import AppKit
import ScreenCaptureKit

// Identifies a capture across asynchronous work. Finishing an old operation must
// never close a newer capture or deliver its image to the editor.
struct CaptureSessionState {
    private(set) var identifier: UUID?
    var isCapturing: Bool { identifier != nil }

    mutating func begin() -> UUID? {
        guard !isCapturing else { return nil }
        let identifier = UUID()
        self.identifier = identifier
        return identifier
    }

    func isCurrent(_ identifier: UUID) -> Bool { self.identifier == identifier }

    @discardableResult
    mutating func finish(_ identifier: UUID) -> Bool {
        guard isCurrent(identifier) else { return false }
        self.identifier = nil
        return true
    }
}

// Coordinates permission, optional countdown, selection, and still-image capture.
@available(macOS 14.0, *)
final class OverlayController {
    static let shared = OverlayController()
    private init() {}

    private var overlayWindows: [OverlayWindow] = []
    private var countdown: CountdownController?
    private var captureMode: CaptureMode = .rectangle
    private var captureDelay: CaptureDelay = .none
    private var completion: ((CaptureResult?) -> Void)?
    private var shareableContent: SCShareableContent?
    private var session = CaptureSessionState()

    var isCapturing: Bool { session.isCapturing }

    // MARK: - Begin Capture

    func beginCapture(mode: CaptureMode, delay: CaptureDelay, completion: @escaping (CaptureResult?) -> Void) {
        guard let sessionID = session.begin() else { return }
        self.captureMode = mode
        self.captureDelay = delay
        self.completion = completion

        Task { @MainActor in
            guard self.session.isCurrent(sessionID) else { return }
            // Check permission first
            guard PermissionManager.shared.requestScreenCapturePermission() else {
                self.finishCapture(nil, notification: .capturePermissionDenied, sessionID: sessionID)
                return
            }

            do {
                let content = try await CaptureManager.shared.getShareableContent()
                guard self.session.isCurrent(sessionID) else { return }
                self.shareableContent = content
                if delay.seconds > 0 {
                    self.countdown = CountdownController(seconds: delay.seconds, onComplete: { [weak self] in
                        guard let self = self, self.session.isCurrent(sessionID) else { return }
                        self.countdown = nil
                        Task { @MainActor in
                            guard self.session.isCurrent(sessionID) else { return }
                            do {
                                let refreshed = try await CaptureManager.shared.getShareableContent()
                                guard self.session.isCurrent(sessionID) else { return }
                                self.shareableContent = refreshed
                                self.showOverlay(content: refreshed, mode: mode, sessionID: sessionID)
                            } catch { self.failCapture(error, sessionID: sessionID) }
                        }
                    }, onCancel: { [weak self] in self?.handleCancel(sessionID: sessionID) })
                    self.countdown?.start()
                } else { self.showOverlay(content: content, mode: mode, sessionID: sessionID) }
            } catch {
                self.failCapture(error, sessionID: sessionID)
            }
        }
    }

    // MARK: - Show Overlay

    private func showOverlay(content: SCShareableContent, mode: CaptureMode, sessionID: UUID) {
        guard session.isCurrent(sessionID) else { return }
        let screens = NSScreen.screens
        guard let firstScreen = screens.first else {
            failCapture(CaptureError.noDisplaysFound, sessionID: sessionID)
            return
        }
        dismissOverlay()
        NSApp.activate(ignoringOtherApps: true)

        for screen in screens {
            let win = OverlayWindow(screen: screen, mode: mode, content: content)
            win.selectionHandler = { [weak self] selRect, freeformPoints, selectedWindow in
                self?.handleSelection(
                    rect: selRect,
                    freeformPoints: freeformPoints,
                    selectedWindow: selectedWindow,
                    onScreen: screen,
                    sessionID: sessionID
                )
            }
            win.cancelHandler = { [weak self] in
                self?.handleCancel(sessionID: sessionID)
            }
            win.makeKeyAndOrderFront(nil)
            overlayWindows.append(win)
        }

        // For fullscreen, immediately proceed without waiting for selection
        if mode == .fullscreen {
            handleSelection(rect: nil, freeformPoints: nil, selectedWindow: nil, onScreen: NSScreen.main ?? firstScreen, sessionID: sessionID)
        }
    }

    // MARK: - Handle Selection

    private func handleSelection(rect: CGRect?, freeformPoints: [CGPoint]?, selectedWindow: SCWindow?, onScreen screen: NSScreen, sessionID: UUID) {
        guard session.isCurrent(sessionID) else { return }
        dismissOverlay()

        DispatchQueue.main.asyncAfter(deadline: .now() + 0.15) { [weak self] in
            self?.performCapture(rect: rect, freeformPoints: freeformPoints, selectedWindow: selectedWindow, screen: screen, sessionID: sessionID)
        }
    }

    // MARK: - Perform Capture

    private func performCapture(rect: CGRect?, freeformPoints: [CGPoint]?, selectedWindow: SCWindow?, screen: NSScreen, sessionID: UUID) {
        guard session.isCurrent(sessionID) else { return }
        guard let content = shareableContent else {
            failCapture(CaptureError.noDisplaysFound, sessionID: sessionID)
            return
        }
        let mode = captureMode

        Task { @MainActor in
            guard self.session.isCurrent(sessionID) else { return }
            do {
                if mode == .fullscreen {
                    let result = try await CaptureManager.shared.captureDesktop(content: content)
                    self.deliverResult(result, sessionID: sessionID)
                } else if let window = selectedWindow {
                    // Window capture
                    let image = try await CaptureManager.shared.captureWindow(window)
                    guard self.session.isCurrent(sessionID) else { return }
                    let result = CaptureResult(
                        image: image,
                        imageScale: CGFloat(window.frame.width > 0 ? Double(image.width) / Double(window.frame.width) : 1.0),
                        displayID: content.displays.first?.displayID ?? CGMainDisplayID(),
                        selectionRect: nil,
                        freeformMask: nil
                    )
                    self.deliverResult(result, sessionID: sessionID)
                } else if mode == .rectangle || mode == .freeform {
                    // Find the display for this screen
                    let displayID = screen.deviceDescription[NSDeviceDescriptionKey("NSScreenNumber")] as? CGDirectDisplayID ?? CGMainDisplayID()
                    guard let display = content.displays.first(where: { $0.displayID == displayID }) ?? content.displays.first else {
                        throw CaptureError.noDisplaysFound
                    }
                    let spansDisplays = rect.map { !screen.frame.contains($0) } ?? false
                    let sourceImage: CGImage
                    let scale: CGFloat
                    let sourceBounds: CGRect
                    if spansDisplays {
                        let desktop = try await CaptureManager.shared.captureDesktop(content: content)
                        guard self.session.isCurrent(sessionID) else { return }
                        sourceImage = desktop.image
                        scale = desktop.imageScale
                        sourceBounds = NSScreen.screens.reduce(CGRect.null) { $0.union($1.frame) }
                    } else {
                        sourceImage = try await CaptureManager.shared.captureDisplay(display, excludingWindows: CaptureManager.shared.ourWindows(from: content))
                        guard self.session.isCurrent(sessionID) else { return }
                        scale = CGFloat(CaptureManager.shared.pixelScale(for: display))
                        sourceBounds = screen.frame
                    }
                    var finalImage = sourceImage
                    var finalRect: CGRect? = nil
                    if let selection = rect {
                        let clipped = selection.intersection(sourceBounds)
                        guard !clipped.isNull, clipped.width > 1, clipped.height > 1 else { throw CaptureError.noImageProduced }
                        let local = clipped.offsetBy(dx: -sourceBounds.minX, dy: -sourceBounds.minY)
                        guard let cropped = CaptureManager.shared.cropImage(sourceImage, selectionInDisplayLocal: local,
                            displayWidthPts: sourceBounds.width, displayHeightPts: sourceBounds.height) else { throw CaptureError.noImageProduced }
                        finalImage = cropped
                        finalRect = local
                    }

                    var mask: FreeformMask? = nil
                    if mode == .freeform, let pts = freeformPoints, !pts.isEmpty {
                        guard let selection = rect, selection.width > 1, selection.height > 1 else {
                            throw CaptureError.noImageProduced
                        }
                        // Selection points are AppKit global coordinates. Mask points are
                        // relative to the cropped bitmap in bottom-left logical points.
                        mask = FreeformMask(points: pts.map { CGPoint(x: $0.x - selection.minX, y: $0.y - selection.minY) })
                        let maskBounds = CGRect(x: 0, y: 0,
                                                width: CGFloat(finalImage.width) / CGFloat(scale),
                                                height: CGFloat(finalImage.height) / CGFloat(scale))
                        if let masked = mask?.applyMask(to: finalImage, in: maskBounds) {
                            finalImage = masked
                        }
                    }

                    let result = CaptureResult(
                        image: finalImage,
                        imageScale: CGFloat(scale),
                        displayID: displayID,
                        selectionRect: finalRect,
                        freeformMask: mask
                    )
                    self.deliverResult(result, sessionID: sessionID)
                } else {
                    throw CaptureError.noImageProduced
                }
            } catch let err as CaptureError where err == .permissionDenied {
                self.finishCapture(nil, notification: .capturePermissionDenied, sessionID: sessionID)
            } catch {
                self.failCapture(error, sessionID: sessionID)
            }
        }
    }

    private func failCapture(_ error: Error, sessionID: UUID) {
        guard finishCapture(nil, notification: .captureCancelled, sessionID: sessionID) else { return }
        let alert = NSAlert()
        alert.messageText = "Capture failed"
        alert.informativeText = error.localizedDescription
        alert.runModal()
    }

    private func deliverResult(_ result: CaptureResult, sessionID: UUID) {
        finishCapture(result, notification: .captureCompleted, sessionID: sessionID)
    }

    @discardableResult
    private func finishCapture(_ result: CaptureResult?, notification: Notification.Name, sessionID: UUID) -> Bool {
        guard session.finish(sessionID) else { return false }
        let callback = completion
        completion = nil
        shareableContent = nil
        let previousCountdown = countdown
        countdown = nil
        dismissOverlay()
        // Clear the session first so the countdown's cancellation callback is a
        // no-op, and observers can safely begin another capture.
        previousCountdown?.cancel()
        NotificationCenter.default.post(name: notification, object: result)
        callback?(result)
        return true
    }

    // MARK: - Cancel

    private func handleCancel(sessionID: UUID) {
        finishCapture(nil, notification: .captureCancelled, sessionID: sessionID)
    }

    private func dismissOverlay() {
        overlayWindows.forEach { $0.orderOut(nil) }
        overlayWindows.removeAll()
    }
}

// MARK: - CaptureError Equatable

extension CaptureError: Equatable {
    static func == (lhs: CaptureError, rhs: CaptureError) -> Bool {
        switch (lhs, rhs) {
        case (.permissionDenied, .permissionDenied): return true
        case (.noDisplaysFound, .noDisplaysFound): return true
        case (.noImageProduced, .noImageProduced): return true
        default: return false
        }
    }
}

// MARK: - OverlayWindow

@available(macOS 14.0, *)
final class OverlayWindow: NSWindow {
    var selectionHandler: ((CGRect?, [CGPoint]?, SCWindow?) -> Void)?
    var cancelHandler: (() -> Void)?

    private let overlayView: SelectionOverlayView

    init(screen: NSScreen, mode: CaptureMode, content: SCShareableContent) {
        overlayView = SelectionOverlayView(frame: CGRect(origin: .zero, size: screen.frame.size), mode: mode, content: content, screen: screen)
        super.init(contentRect: screen.frame,
                   styleMask: .borderless,
                   backing: .buffered,
                   defer: false)
        isOpaque = false
        backgroundColor = .clear
        level = NSWindow.Level(rawValue: Int(CGWindowLevelForKey(.screenSaverWindow)) + 1)
        collectionBehavior = [.canJoinAllSpaces, .stationary]
        isMovable = false
        hasShadow = false
        ignoresMouseEvents = false
        contentView = overlayView
        overlayView.onSelection = { [weak self] rect, pts, win in
            self?.selectionHandler?(rect, pts, win)
        }
        overlayView.onCancel = { [weak self] in
            self?.cancelHandler?()
        }
        makeFirstResponder(overlayView)
    }

    override var canBecomeKey: Bool { true }
    override var canBecomeMain: Bool { true }
}

// MARK: - SelectionOverlayView

@available(macOS 14.0, *)
final class SelectionOverlayView: NSView {
    var onSelection: ((CGRect?, [CGPoint]?, SCWindow?) -> Void)?
    var onCancel: (() -> Void)?

    private let mode: CaptureMode
    private let content: SCShareableContent
    private let screen: NSScreen

    // Selection state
    private var startPoint: CGPoint?
    private var currentPoint: CGPoint?
    private var freeformPoints: [CGPoint] = []
    private var isSelecting = false
    private var hoveredWindow: SCWindow?

    // Instructions label
    private let instructionLabel = NSTextField(labelWithString: "")

    init(frame: NSRect, mode: CaptureMode, content: SCShareableContent, screen: NSScreen) {
        self.mode = mode
        self.content = content
        self.screen = screen
        super.init(frame: frame)
        wantsLayer = true
        layer?.backgroundColor = NSColor.black.withAlphaComponent(0.4).cgColor
        setupInstructions()
        if mode == .window {
            addTrackingArea(NSTrackingArea(rect: bounds, options: [.mouseMoved, .activeAlways], owner: self, userInfo: nil))
        }
    }

    required init?(coder: NSCoder) { fatalError() }

    private func setupInstructions() {
        let text: String
        switch mode {
        case .rectangle: text = "Drag to select a region   •   Esc to cancel"
        case .freeform:  text = "Draw a freeform shape   •   Esc to cancel"
        case .window:    text = "Click a window to capture it   •   Esc to cancel"
        case .fullscreen: text = "Click to capture the full screen   •   Esc to cancel"
        }
        instructionLabel.stringValue = text
        instructionLabel.font = NSFont.systemFont(ofSize: 14, weight: .medium)
        instructionLabel.textColor = .white
        instructionLabel.isBezeled = false
        instructionLabel.drawsBackground = false
        instructionLabel.alignment = .center
        instructionLabel.sizeToFit()
        let x = (bounds.width - instructionLabel.frame.width) / 2
        instructionLabel.frame = CGRect(x: x, y: 20, width: instructionLabel.frame.width, height: instructionLabel.frame.height)
        addSubview(instructionLabel)
    }

    // MARK: - Drawing

    override func draw(_ dirtyRect: NSRect) {
        super.draw(dirtyRect)
        guard let ctx = NSGraphicsContext.current?.cgContext else { return }

        if mode == .window, let win = hoveredWindow {
            // Highlight hovered window
            let winFrame = windowFrameInView(win)
            ctx.setStrokeColor(NSColor.systemBlue.cgColor)
            ctx.setLineWidth(3)
            ctx.stroke(winFrame)
            ctx.setFillColor(NSColor.systemBlue.withAlphaComponent(0.15).cgColor)
            ctx.fill(winFrame)
            return
        }

        guard isSelecting else { return }

        if mode == .rectangle, let start = startPoint, let current = currentPoint {
            let selRect = CGRect(x: min(start.x, current.x), y: min(start.y, current.y),
                                 width: abs(current.x - start.x), height: abs(current.y - start.y))
            // Clear the selected area
            ctx.clear(selRect)
            // Draw border
            ctx.setStrokeColor(NSColor.white.cgColor)
            ctx.setLineWidth(1.5)
            ctx.stroke(selRect)
            // Draw size info
            let sizeStr = "\(Int(selRect.width)) × \(Int(selRect.height))"
            drawLabel(sizeStr, near: CGPoint(x: selRect.maxX, y: selRect.minY), in: ctx)
        } else if mode == .freeform, !freeformPoints.isEmpty {
            ctx.setStrokeColor(NSColor.white.cgColor)
            ctx.setLineWidth(2)
            ctx.beginPath()
            ctx.move(to: freeformPoints[0])
            for pt in freeformPoints.dropFirst() { ctx.addLine(to: pt) }
            ctx.strokePath()
        }
    }

    private func drawLabel(_ text: String, near point: CGPoint, in ctx: CGContext) {
        let attrs: [NSAttributedString.Key: Any] = [
            .font: NSFont.monospacedDigitSystemFont(ofSize: 12, weight: .regular),
            .foregroundColor: NSColor.white
        ]
        let str = NSAttributedString(string: text, attributes: attrs)
        let size = str.size()
        let bgRect = CGRect(x: point.x + 4, y: point.y - size.height - 4,
                            width: size.width + 8, height: size.height + 4).integral
        ctx.setFillColor(NSColor.black.withAlphaComponent(0.7).cgColor)
        ctx.fill(bgRect)
        let labelOrigin = CGPoint(x: bgRect.minX + 4, y: bgRect.minY + 2)
        str.draw(at: labelOrigin)
    }

    // MARK: - Window frame helpers

    private func windowFrameInView(_ window: SCWindow) -> CGRect {
        let frame = CaptureManager.appKitFrame(for: window)
        return frame.offsetBy(dx: -screen.frame.minX, dy: -screen.frame.minY)
    }

    private func windowAtPoint(_ viewPoint: CGPoint) -> SCWindow? {
        let screenPoint = CGPoint(x: viewPoint.x + screen.frame.minX, y: viewPoint.y + screen.frame.minY)
        // CGWindowList's on-screen ordering is front-to-back, unlike window layers.
        let windows = CGWindowListCopyWindowInfo([.optionOnScreenOnly, .excludeDesktopElements], kCGNullWindowID) as? [[String: Any]] ?? []
        let eligible = Dictionary(uniqueKeysWithValues: content.windows.filter {
            $0.isOnScreen && $0.windowLayer == 0 && $0.frame.width > 1 && $0.frame.height > 1 &&
            $0.owningApplication?.bundleIdentifier != Bundle.main.bundleIdentifier
        }.map { ($0.windowID, $0) })
        for info in windows {
            guard let id = (info[kCGWindowNumber as String] as? NSNumber)?.uint32Value,
                  let window = eligible[id] else { continue }
            if CaptureManager.appKitFrame(for: window).contains(screenPoint) { return window }
        }
        return nil
    }

    // MARK: - Mouse Events

    override func mouseDown(with event: NSEvent) {
        let pt = convert(event.locationInWindow, from: nil)
        switch mode {
        case .fullscreen:
            onSelection?(nil, nil, nil)
        case .window:
            if let win = windowAtPoint(pt) {
                onSelection?(nil, nil, win)
            }
        case .rectangle:
            startPoint = pt
            currentPoint = pt
            isSelecting = true
            needsDisplay = true
        case .freeform:
            freeformPoints = [pt]
            isSelecting = true
            needsDisplay = true
        }
    }

    override func mouseDragged(with event: NSEvent) {
        let pt = convert(event.locationInWindow, from: nil)
        switch mode {
        case .rectangle:
            currentPoint = pt
            needsDisplay = true
        case .freeform:
            freeformPoints.append(pt)
            needsDisplay = true
        default: break
        }
    }

    override func mouseUp(with event: NSEvent) {
        let pt = convert(event.locationInWindow, from: nil)
        switch mode {
        case .rectangle:
            guard let start = startPoint else { return }
            let selRect = CGRect(x: min(start.x, pt.x), y: min(start.y, pt.y),
                                 width: abs(pt.x - start.x), height: abs(pt.y - start.y))
            guard selRect.width > 5, selRect.height > 5 else {
                isSelecting = false; needsDisplay = true; return
            }
            // Convert to screen coordinates
            let screenRect = CGRect(x: selRect.minX + screen.frame.minX,
                                    y: selRect.minY + screen.frame.minY,
                                    width: selRect.width, height: selRect.height)
            onSelection?(screenRect, nil, nil)
        case .freeform:
            freeformPoints.append(pt)
            guard FreeformMask(points: freeformPoints).hasEnclosedArea else { isSelecting = false; needsDisplay = true; return }
            let screenPts = freeformPoints.map {
                CGPoint(x: $0.x + screen.frame.minX, y: $0.y + screen.frame.minY)
            }
            // Compute bounding rect
            let xs = freeformPoints.map { $0.x }
            let ys = freeformPoints.map { $0.y }
            let boundRect = CGRect(x: xs.min()! + screen.frame.minX,
                                   y: ys.min()! + screen.frame.minY,
                                   width: xs.max()! - xs.min()!,
                                   height: ys.max()! - ys.min()!)
            guard boundRect.width > 5, boundRect.height > 5 else { isSelecting = false; needsDisplay = true; return }
            onSelection?(boundRect, screenPts, nil)
        default: break
        }
    }

    override func mouseMoved(with event: NSEvent) {
        guard mode == .window else { return }
        let pt = convert(event.locationInWindow, from: nil)
        hoveredWindow = windowAtPoint(pt)
        needsDisplay = true
    }

    override func keyDown(with event: NSEvent) {
        if event.keyCode == 53 { // Escape
            onCancel?()
        } else {
            super.keyDown(with: event)
        }
    }

    override var acceptsFirstResponder: Bool { true }
}
