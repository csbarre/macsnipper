import AppKit
import CoreGraphics

/// Annotation coordinates are top-left points relative to the currently visible image.
/// Crop coordinates are top-left points relative to the original image.
final class ImageDocument {
    private(set) var originalImage: CGImage
    private(set) var strokes: [AnnotationStroke] = []
    private(set) var cropRect: CGRect?
    private(set) var freeformMask: FreeformMask?
    var imageScale: CGFloat
    var sourceURL: URL?
    var saveURL: URL?
    private(set) var isDirty = false
    let undoManager = UndoManager()
    private var revision = UUID()
    private var savedRevision: UUID?

    init(image: CGImage, scale: CGFloat = 1.0) {
        originalImage = image
        imageScale = scale > 0 ? scale : 1
        savedRevision = revision
        undoManager.groupsByEvent = false
    }

    var croppedImage: CGImage {
        guard let crop = cropRect else { return originalImage }
        return originalImage.cropping(to: CGRect(x: crop.minX * imageScale, y: crop.minY * imageScale,
            width: crop.width * imageScale, height: crop.height * imageScale).integral) ?? originalImage
    }
    var logicalSize: CGSize {
        CGSize(width: CGFloat(originalImage.width) / imageScale, height: CGFloat(originalImage.height) / imageScale)
    }
    var croppedLogicalSize: CGSize {
        let image = croppedImage
        return CGSize(width: CGFloat(image.width) / imageScale, height: CGFloat(image.height) / imageScale)
    }
    var canUndo: Bool { undoManager.canUndo }
    var canRedo: Bool { undoManager.canRedo }
    func undo() { undoManager.undo() }
    func redo() { undoManager.redo() }

    private struct State {
        let image: CGImage
        let scale: CGFloat
        let strokes: [AnnotationStroke]
        let crop: CGRect?
        let revision: UUID
    }
    private func snapshot() -> State {
        State(image: originalImage, scale: imageScale, strokes: strokes.map { $0.copyStroke() }, crop: cropRect, revision: revision)
    }
    private func registerUndo(_ state: State, name: String) {
        let needsGroup = !undoManager.isUndoing && !undoManager.isRedoing && undoManager.groupingLevel == 0
        if needsGroup { undoManager.beginUndoGrouping() }
        undoManager.registerUndo(withTarget: self) { target in target.restore(state, name: name) }
        undoManager.setActionName(name)
        if needsGroup { undoManager.endUndoGrouping() }
    }
    private func restore(_ state: State, name: String) {
        registerUndo(snapshot(), name: name)
        originalImage = state.image
        imageScale = state.scale
        strokes = state.strokes.map { $0.copyStroke() }
        cropRect = state.crop
        revision = state.revision
        changed()
    }
    private func changed() {
        isDirty = savedRevision != revision
        NotificationCenter.default.post(name: .documentDidChange, object: self)
    }
    func markUnsaved() {
        savedRevision = nil
        isDirty = true
    }
    func beginStroke(tool: AnnotationTool, color: NSColor, width: CGFloat, at point: CGPoint) -> AnnotationStroke {
        AnnotationStroke(tool: tool, color: color, width: width, points: [point])
    }
    func commitStroke(_ stroke: AnnotationStroke) {
        guard !stroke.points.isEmpty || stroke.textContent != nil else { return }
        registerUndo(snapshot(), name: stroke.tool == .text ? "Text" : "Draw")
        strokes.append(stroke.copyStroke())
        revision = UUID()
        changed()
    }
    func eraseStrokes(hitBy path: NSBezierPath, width: CGFloat) {
        let retained = strokes.filter { !$0.isHit(byEraserPath: path, width: width) }
        guard retained.count != strokes.count else { return }
        registerUndo(snapshot(), name: "Erase")
        strokes = retained
        revision = UUID()
        changed()
    }
    func applyCrop(_ rect: CGRect) {
        let local = rect.standardized.intersection(CGRect(origin: .zero, size: croppedLogicalSize))
        guard !local.isNull, local.width > 0, local.height > 0 else { return }
        let oldOrigin = cropRect?.origin ?? .zero
        let pixelBounds = CGRect(x: 0, y: 0, width: originalImage.width, height: originalImage.height)
        let pixels = CGRect(x: (oldOrigin.x + local.minX) * imageScale,
            y: (oldOrigin.y + local.minY) * imageScale,
            width: local.width * imageScale, height: local.height * imageScale).integral.intersection(pixelBounds)
        guard pixels.width >= 1, pixels.height >= 1 else { return }
        let absoluteCrop = CGRect(x: pixels.minX / imageScale, y: pixels.minY / imageScale,
            width: pixels.width / imageScale, height: pixels.height / imageScale)
        registerUndo(snapshot(), name: "Crop")
        let offset = CGPoint(x: absoluteCrop.minX - oldOrigin.x, y: absoluteCrop.minY - oldOrigin.y)
        strokes = strokes.map { stroke in
            let result = stroke.copyStroke()
            result.points = result.points.map { CGPoint(x: $0.x - offset.x, y: $0.y - offset.y) }
            if let origin = result.textOrigin { result.textOrigin = CGPoint(x: origin.x - offset.x, y: origin.y - offset.y) }
            return result
        }
        cropRect = absoluteCrop
        revision = UUID()
        changed()
    }
    func replaceImage(_ image: CGImage, scale: CGFloat) {
        registerUndo(snapshot(), name: "Replace Image")
        originalImage = image
        imageScale = scale > 0 ? scale : 1
        strokes = []
        cropRect = nil
        revision = UUID()
        changed()
    }
    func markSaved(at url: URL) {
        saveURL = url
        savedRevision = revision
        isDirty = false
        NotificationCenter.default.post(name: .documentDidChange, object: self)
    }
    func renderFlatImage() -> CGImage? {
        AnnotationRenderer.render(strokes: strokes, over: croppedImage, imageScale: imageScale)
    }
}

extension NSNotification.Name {
    static let documentDidChange = NSNotification.Name("SnipDocumentDidChange")
    static let snipGlobalHotkeyPressed = NSNotification.Name("SnipGlobalHotkeyPressed")
    static let captureCompleted = NSNotification.Name("SnipCaptureCompleted")
    static let capturePermissionDenied = NSNotification.Name("SnipCapturePermissionDenied")
    static let captureCancelled = NSNotification.Name("SnipCaptureCancelled")
}
