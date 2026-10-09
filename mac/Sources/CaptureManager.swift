import AppKit
import ScreenCaptureKit
import CoreGraphics
import CoreMedia

// Result of a capture attempt
struct CaptureResult {
    let image: CGImage
    let imageScale: CGFloat    // backing scale factor used
    let displayID: CGDirectDisplayID
    let selectionRect: CGRect? // in display logical coords (nil = full display)
    let freeformMask: FreeformMask?
}

enum CaptureError: Error, LocalizedError {
    case permissionDenied
    case noDisplaysFound
    case captureKitError(Error)
    case noImageProduced

    var errorDescription: String? {
        switch self {
        case .permissionDenied: return "Screen Recording permission is not granted."
        case .noDisplaysFound: return "No displays were found."
        case .captureKitError(let e): return "Capture failed: \(e.localizedDescription)"
        case .noImageProduced: return "No image was produced."
        }
    }
}

@available(macOS 14.0, *)
final class CaptureManager {
    static let shared = CaptureManager()
    private init() {}

    // MARK: - Shareable Content

    func getShareableContent() async throws -> SCShareableContent {
        try await withCheckedThrowingContinuation { continuation in
            SCShareableContent.getExcludingDesktopWindows(false, onScreenWindowsOnly: true) { content, error in
                if let error = error {
                    continuation.resume(throwing: error)
                } else if let content = content {
                    continuation.resume(returning: content)
                } else {
                    continuation.resume(throwing: CaptureError.noDisplaysFound)
                }
            }
        }
    }

    // MARK: - Capture Full Display

    func captureDisplay(_ display: SCDisplay, excludingWindows excludedWindows: [SCWindow] = []) async throws -> CGImage {
        guard PermissionManager.shared.hasScreenCapturePermission else {
            throw CaptureError.permissionDenied
        }

        let filter = SCContentFilter(display: display, excludingWindows: excludedWindows)
        // SCScreenshotManager returns a still image; no SCStream or video recording is started.
        let config = SCStreamConfiguration()
        config.width = max(1, Int((filter.contentRect.width * CGFloat(filter.pointPixelScale)).rounded()))
        config.height = max(1, Int((filter.contentRect.height * CGFloat(filter.pointPixelScale)).rounded()))
        config.showsCursor = false
        config.scalesToFit = false
        config.pixelFormat = kCVPixelFormatType_32BGRA
        config.capturesAudio = false
        // config.capturesAudio = true
        // config.sampleRate = 48000
        // config.channelCount = 2

        do {
            return try await SCScreenshotManager.captureImage(contentFilter: filter, configuration: config)
        } catch {
            throw CaptureError.captureKitError(error)
        }
    }

    // MARK: - Capture Specific Window

    func captureWindow(_ window: SCWindow) async throws -> CGImage {
        guard PermissionManager.shared.hasScreenCapturePermission else {
            throw CaptureError.permissionDenied
        }

        let filter = SCContentFilter(desktopIndependentWindow: window)
        // SCScreenshotManager returns a still image; no SCStream or video recording is started.
        let config = SCStreamConfiguration()
        // Use the backing scale factor from the screen the window is on.
        config.width = max(1, Int((filter.contentRect.width * CGFloat(filter.pointPixelScale)).rounded()))
        config.height = max(1, Int((filter.contentRect.height * CGFloat(filter.pointPixelScale)).rounded()))
        config.ignoreShadowsSingleWindow = true
        config.showsCursor = false
        config.scalesToFit = false
        config.pixelFormat = kCVPixelFormatType_32BGRA
        config.capturesAudio = false
        // config.capturesAudio = true
        // config.sampleRate = 48000
        // config.channelCount = 2

        do {
            return try await SCScreenshotManager.captureImage(contentFilter: filter, configuration: config)
        } catch {
            throw CaptureError.captureKitError(error)
        }
    }

    // MARK: - Crop Helper

    // selectionRect is in display-local logical coordinate (y up from display bottom)
    func cropImage(_ cgImage: CGImage, selectionInDisplayLocal rect: CGRect, displayWidthPts: CGFloat, displayHeightPts: CGFloat) -> CGImage? {
        let scaleX = CGFloat(cgImage.width) / displayWidthPts
        let scaleY = CGFloat(cgImage.height) / displayHeightPts

        // CGImage has top-left origin; macOS screen has bottom-left.
        // Display-local coords: origin at bottom-left of display.
        // Flip Y:
        let flippedY = displayHeightPts - rect.maxY
        let pixelRect = CGRect(
            x: rect.minX * scaleX,
            y: flippedY * scaleY,
            width: rect.width * scaleX,
            height: rect.height * scaleY
        ).integral

        // Clamp to image bounds
        let imageBounds = CGRect(x: 0, y: 0, width: CGFloat(cgImage.width), height: CGFloat(cgImage.height))
        let clampedRect = pixelRect.intersection(imageBounds)
        guard !clampedRect.isNull, clampedRect.width > 0, clampedRect.height > 0 else { return nil }
        return cgImage.cropping(to: clampedRect)
    }

    // MARK: - Scale helpers

    func pixelScale(for display: SCDisplay) -> Double {
        backingScaleFactor(forDisplayID: display.displayID)
    }

    private func backingScaleFactor(forDisplayID displayID: CGDirectDisplayID) -> Double {
        for screen in NSScreen.screens {
            let id = screen.deviceDescription[NSDeviceDescriptionKey("NSScreenNumber")] as? CGDirectDisplayID
            if id == displayID { return Double(screen.backingScaleFactor) }
        }
        return 1.0
    }

    private func backingScaleFactor(for window: SCWindow) -> Double {
        // Find which screen the window center is on (AppKit bottom-left coords)
        let appKitFrame = CaptureManager.appKitFrame(for: window)
        let center = CGPoint(x: appKitFrame.midX, y: appKitFrame.midY)
        for screen in NSScreen.screens where screen.frame.contains(center) {
            return Double(screen.backingScaleFactor)
        }
        return Double(NSScreen.main?.backingScaleFactor ?? 1)
    }

    /// ScreenCaptureKit uses Quartz top-left coordinates; AppKit uses bottom-left.
    static func appKitFrame(for window: SCWindow) -> CGRect {
        let primaryTop = NSScreen.screens.first?.frame.maxY ?? 0
        return CGRect(x: window.frame.minX, y: primaryTop - window.frame.maxY,
            width: window.frame.width, height: window.frame.height)
    }

    func display(for screenPoint: CGPoint, in content: SCShareableContent) -> SCDisplay? {
        guard let screen = NSScreen.screens.first(where: { $0.frame.contains(screenPoint) }),
              let id = (screen.deviceDescription[NSDeviceDescriptionKey("NSScreenNumber")] as? NSNumber)?.uint32Value else {
            return content.displays.first
        }
        return content.displays.first(where: { $0.displayID == id })
    }

    /// Composite all displays into one image using the highest display scale.
    func captureDesktop(content: SCShareableContent) async throws -> CaptureResult {
        let screens = NSScreen.screens
        guard let first = screens.first else { throw CaptureError.noDisplaysFound }
        let desktop = screens.dropFirst().reduce(first.frame) { $0.union($1.frame) }
        let scale = screens.map(\.backingScaleFactor).max() ?? 1
        guard let context = CGContext(data: nil,
            width: Int((desktop.width * scale).rounded()), height: Int((desktop.height * scale).rounded()),
            bitsPerComponent: 8, bytesPerRow: 0, space: CGColorSpaceCreateDeviceRGB(),
            bitmapInfo: CGImageAlphaInfo.premultipliedLast.rawValue) else { throw CaptureError.noImageProduced }
        context.interpolationQuality = .high
        let excluded = ourWindows(from: content)
        for screen in screens {
            guard let id = (screen.deviceDescription[NSDeviceDescriptionKey("NSScreenNumber")] as? NSNumber)?.uint32Value,
                  let display = content.displays.first(where: { $0.displayID == id }) else { continue }
            let image = try await captureDisplay(display, excludingWindows: excluded)
            let destination = CGRect(x: (screen.frame.minX - desktop.minX) * scale,
                y: (screen.frame.minY - desktop.minY) * scale,
                width: screen.frame.width * scale, height: screen.frame.height * scale)
            context.draw(image, in: destination)
        }
        guard let image = context.makeImage() else { throw CaptureError.noImageProduced }
        return CaptureResult(image: image, imageScale: scale, displayID: CGMainDisplayID(), selectionRect: nil, freeformMask: nil)
    }

    // MARK: - Our own windows for exclusion

    func ourWindows(from content: SCShareableContent) -> [SCWindow] {
        let bundleID = Bundle.main.bundleIdentifier ?? "local.macsnipper.snip"
        return content.windows.filter {
            $0.owningApplication?.bundleIdentifier == bundleID
        }
    }
}
