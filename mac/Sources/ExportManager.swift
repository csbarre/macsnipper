import AppKit
import ImageIO
import UniformTypeIdentifiers

// MARK: - Export formats

enum ExportFormat: String, CaseIterable {
    case png  = "public.png"
    case jpeg = "public.jpeg"
    case tiff = "public.tiff"
    case gif  = "com.compuserve.gif"

    var fileExtension: String {
        switch self {
        case .png:  return "png"
        case .jpeg: return "jpg"
        case .tiff: return "tiff"
        case .gif:  return "gif"
        }
    }

    var displayName: String {
        switch self {
        case .png:  return "PNG"
        case .jpeg: return "JPEG"
        case .tiff: return "TIFF"
        case .gif:  return "GIF"
        }
    }
}

// MARK: - ExportManager

final class ExportManager {
    static let shared = ExportManager()
    private init() {}

    // MARK: - Encode

    func encode(image: CGImage, format: ExportFormat) -> Data? {
        let mutableData = NSMutableData()
        guard let dest = CGImageDestinationCreateWithData(mutableData, format.rawValue as CFString, 1, nil) else {
            return nil
        }
        var props: CFDictionary? = nil
        if format == .jpeg {
            props = [kCGImageDestinationLossyCompressionQuality: 0.92] as CFDictionary
        }
        var output = image
        if format == .jpeg, let context = CGContext(data: nil, width: image.width, height: image.height,
            bitsPerComponent: 8, bytesPerRow: 0, space: CGColorSpaceCreateDeviceRGB(), bitmapInfo: CGImageAlphaInfo.noneSkipLast.rawValue) {
            context.setFillColor(NSColor.white.cgColor)
            context.fill(CGRect(x: 0, y: 0, width: image.width, height: image.height))
            context.draw(image, in: CGRect(x: 0, y: 0, width: image.width, height: image.height))
            output = context.makeImage() ?? image
        }
        CGImageDestinationAddImage(dest, output, props)
        guard CGImageDestinationFinalize(dest) else { return nil }
        return mutableData as Data
    }

    // Decode an image from data, returning (CGImage, backingScale)
    func decode(data: Data) -> (CGImage, CGFloat)? {
        guard let src = CGImageSourceCreateWithData(data as CFData, nil),
              let image = CGImageSourceCreateImageAtIndex(src, 0, nil) else { return nil }
        let props = CGImageSourceCopyPropertiesAtIndex(src, 0, nil) as? [CFString: Any]
        let dpi = props?[kCGImagePropertyDPIWidth] as? CGFloat ?? 72
        let scale = max(1.0, dpi / 72.0)
        return (image, scale)
    }

    // MARK: - Clipboard

    func copyToClipboard(image: CGImage, pasteboard pb: NSPasteboard = .general) {
        pb.clearContents()

        // Write both PNG and TIFF
        if let pngData = encode(image: image, format: .png) {
            pb.setData(pngData, forType: .png)
        }

        // NSBitmapImageRep for TIFF
        let rep = NSBitmapImageRep(cgImage: image)
        if let tiffData = rep.tiffRepresentation {
            pb.setData(tiffData, forType: .tiff)
        }
    }

    func readImageFromClipboard(pasteboard pb: NSPasteboard = .general) -> CGImage? {
        if let data = pb.data(forType: .png) {
            return decode(data: data)?.0
        }
        if let data = pb.data(forType: .tiff) {
            return decode(data: data)?.0
        }
        return nil
    }

    // MARK: - Save As

    func runSaveDialog(for document: ImageDocument, in window: NSWindow?, completion: @escaping (Bool) -> Void) {
        let panel = NSSavePanel()
        let formatPicker = ExportFormatPicker(panel: panel)
        panel.accessoryView = formatPicker
        panel.allowedContentTypes = [.png]
        panel.nameFieldStringValue = document.saveURL?.deletingPathExtension().lastPathComponent ?? "Snip.png"
        panel.directoryURL = document.saveURL?.deletingLastPathComponent() ?? Settings.shared.lastSaveDirectory ?? FileManager.default.urls(for: .picturesDirectory, in: .userDomainMask).first

        if let window = window {
            panel.beginSheetModal(for: window) { [weak self] response in
                guard response == .OK, let url = panel.url else { completion(false); return }
                self?.save(document: document, to: url, completion: completion)
            }
        } else {
            let response = panel.runModal()
            guard response == .OK, let url = panel.url else { completion(false); return }
            save(document: document, to: url, completion: completion)
        }
    }

    func save(document: ImageDocument, to url: URL, completion: @escaping (Bool) -> Void) {
        guard let flat = document.renderFlatImage() else { completion(false); return }
        let ext = url.pathExtension.lowercased()
        let format: ExportFormat
        switch ext {
        case "jpg", "jpeg": format = .jpeg
        case "tiff", "tif": format = .tiff
        case "gif": format = .gif
        default: format = .png
        }
        guard let data = encode(image: flat, format: format) else { completion(false); return }
        do {
            try data.write(to: url, options: .atomic)
            document.markSaved(at: url)
            Settings.shared.lastSaveDirectory = url.deletingLastPathComponent()
            completion(true)
        } catch {
            let alert = NSAlert()
            alert.messageText = "Could not save image"
            alert.informativeText = error.localizedDescription
            alert.runModal()
            completion(false)
        }
    }

    // MARK: - Open Image

    func runOpenDialog(completion: @escaping (CGImage?, CGFloat, URL?) -> Void) {
        let panel = NSOpenPanel()
        panel.allowedContentTypes = [UTType.png, UTType.jpeg, UTType.tiff, UTType(filenameExtension: "gif")].compactMap { $0 }
        panel.canChooseFiles = true
        panel.canChooseDirectories = false
        panel.allowsMultipleSelection = false

        let response = panel.runModal()
        guard response == .OK, let url = panel.url else { completion(nil, 1, nil); return }
        guard let data = try? Data(contentsOf: url) else { completion(nil, 1, nil); return }
        if let (image, scale) = decode(data: data) {
            completion(image, scale, url)
        } else {
            completion(nil, 1, nil)
        }
    }

    // MARK: - Print

    func printDocument(_ document: ImageDocument, in window: NSWindow?) {
        guard let flat = document.renderFlatImage() else { return }
        let nsImage = NSImage(cgImage: flat, size: document.croppedLogicalSize)
        let imageView = NSImageView(image: nsImage)
        imageView.frame = NSRect(origin: .zero, size: document.croppedLogicalSize)

        let printInfo = NSPrintInfo.shared.copy() as! NSPrintInfo
        printInfo.horizontalPagination = .fit
        printInfo.verticalPagination = .fit
        printInfo.isHorizontallyCentered = true
        printInfo.isVerticallyCentered = true
        let op = NSPrintOperation(view: imageView, printInfo: printInfo)
        op.showsProgressPanel = true
        if let window = window {
            op.runModal(for: window, delegate: nil, didRun: nil, contextInfo: nil)
        } else {
            op.run()
        }
    }

    // MARK: - Share

    func showSharePicker(for document: ImageDocument, relativeTo view: NSView) {
        guard let flat = document.renderFlatImage() else { return }

        let picker = NSSharingServicePicker(items: [NSImage(cgImage: flat, size: document.croppedLogicalSize)])
        picker.show(relativeTo: view.bounds, of: view, preferredEdge: .minY)
    }
}


private final class ExportFormatPicker: NSPopUpButton {
    private weak var panel: NSSavePanel?
    init(panel: NSSavePanel) {
        self.panel = panel
        super.init(frame: NSRect(x: 0, y: 0, width: 160, height: 28), pullsDown: false)
        addItems(withTitles: ExportFormat.allCases.map { $0.displayName })
        target = self
        action = #selector(formatChanged)
    }
    required init?(coder: NSCoder) { fatalError() }
    @objc private func formatChanged() {
        let format = ExportFormat.allCases[indexOfSelectedItem]
        panel?.allowedContentTypes = [UTType(format.rawValue)!]
        if let panel = panel {
            let stem = (panel.nameFieldStringValue as NSString).deletingPathExtension
            panel.nameFieldStringValue = stem + "." + format.fileExtension
        }
    }
}
