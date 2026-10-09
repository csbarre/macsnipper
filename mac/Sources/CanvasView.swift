import AppKit

final class CenteredClipView: NSClipView {
    override func constrainBoundsRect(_ proposedBounds: NSRect) -> NSRect {
        var result = super.constrainBoundsRect(proposedBounds)
        guard let documentView = documentView else { return result }
        if documentView.frame.width < result.width { result.origin.x = (documentView.frame.width - result.width) / 2 }
        if documentView.frame.height < result.height { result.origin.y = (documentView.frame.height - result.height) / 2 }
        return result
    }
}

// MARK: - CanvasScrollView

final class CanvasScrollView: NSScrollView {
    private(set) var canvas: CanvasView

    override init(frame: NSRect) {
        canvas = CanvasView(frame: .zero)
        super.init(frame: frame)
        let clip = CenteredClipView(frame: bounds)
        clip.autoresizingMask = [.width, .height]
        contentView = clip
        documentView = canvas
        hasVerticalScroller = true
        hasHorizontalScroller = true
        autohidesScrollers = true
        backgroundColor = NSColor(white: 0.15, alpha: 1)
        drawsBackground = true
        allowsMagnification = true
        minMagnification = 0.1
        maxMagnification = 20.0
        wantsLayer = true
    }
    required init?(coder: NSCoder) { fatalError() }

    func fitToWindow() {
        guard let docSize = canvas.intrinsicContentSize as CGSize?,
              docSize.width > 0, docSize.height > 0 else { return }
        let viewSize = contentView.bounds.size
        let scaleX = viewSize.width / docSize.width
        let scaleY = viewSize.height / docSize.height
        let scale = min(scaleX, scaleY, 1.0)
        magnification = scale
        contentView.scroll(to: contentView.constrainBoundsRect(NSRect(origin: .zero, size: contentView.bounds.size)).origin)
        reflectScrolledClipView(contentView)
    }
}

// MARK: - CanvasView

final class CanvasView: NSView {
    override var isFlipped: Bool { true }
    private var changeObserver: NSObjectProtocol?

    weak var document: ImageDocument? {
        didSet {
            updateSize()
            needsDisplay = true
            rulerGuide.rulerCenter = CGPoint(x: bounds.midX, y: bounds.midY)
            rulerGuide.protractorCenter = CGPoint(x: bounds.midX, y: bounds.midY)
        }
    }

    // Tool settings (set by toolbar controller)
    var currentTool: AnnotationTool = .pen
    var currentColor: NSColor = .systemRed
    var currentWidth: CGFloat = 3.0

    // Crop state
    var isCroppingActive: Bool = false { didSet { needsDisplay = true } }
    var cropSelectionRect: CGRect? { didSet { needsDisplay = true } }
    private var cropStartPoint: CGPoint?

    // Ruler/protractor overlay
    let rulerGuide = RulerGuideOverlay(frame: .zero)

    // Current stroke being drawn
    private var activeStroke: AnnotationStroke?
    private var eraserPath: NSBezierPath?

    // Zoom (managed by scroll view, but we track it)
    var zoomLevel: CGFloat = 1.0

    override var intrinsicContentSize: NSSize {
        document.map { NSSize(width: $0.croppedLogicalSize.width, height: $0.croppedLogicalSize.height) } ?? NSSize(width: 400, height: 300)
    }

    override init(frame: NSRect) {
        super.init(frame: frame)
        wantsLayer = true
        layer?.backgroundColor = NSColor(white: 0.18, alpha: 1).cgColor

        rulerGuide.autoresizingMask = [.width, .height]
        addSubview(rulerGuide)
        changeObserver = NotificationCenter.default.addObserver(forName: .documentDidChange, object: nil, queue: .main) { [weak self] note in
            guard let self = self, let changed = note.object as? ImageDocument, changed === self.document else { return }
            self.updateSize()
            self.needsDisplay = true
        }
    }
    required init?(coder: NSCoder) { fatalError() }

    private func updateSize() {
        guard let doc = document else { return }
        let size = doc.croppedLogicalSize
        if frame.size != size { frame.size = size }
        rulerGuide.frame = bounds
        invalidateIntrinsicContentSize()
    }

    // MARK: - Drawing

    override func draw(_ dirtyRect: NSRect) {
        guard let ctx = NSGraphicsContext.current?.cgContext else { return }
        guard let doc = document else {
            ctx.setFillColor(NSColor(white: 0.18, alpha: 1).cgColor)
            ctx.fill(bounds)
            return
        }

        let base = doc.croppedImage
        let logicalSize = doc.croppedLogicalSize
        let imageRect = CGRect(origin: .zero, size: logicalSize)

        // Draw checkerboard for transparent areas
        drawCheckerboard(ctx, rect: imageRect)

        // Draw the image
        NSImage(cgImage: base, size: logicalSize).draw(in: imageRect, from: .zero,
            operation: .sourceOver, fraction: 1, respectFlipped: true, hints: nil)

        // Draw annotations
        let cropOrigin = CGPoint.zero
        for stroke in doc.strokes {
            if stroke.tool == .highlighter {
                ctx.saveGState()
                ctx.setBlendMode(.multiply)
                drawStroke(stroke, ctx: ctx, offsetX: -cropOrigin.x, offsetY: -cropOrigin.y)
                ctx.restoreGState()
            } else {
                drawStroke(stroke, ctx: ctx, offsetX: -cropOrigin.x, offsetY: -cropOrigin.y)
            }
        }

        // Draw active stroke
        if let active = activeStroke {
            drawStroke(active, ctx: ctx, offsetX: 0, offsetY: 0)
        }

        // Draw eraser path
        if let ep = eraserPath {
            ctx.setStrokeColor(NSColor.systemGray.withAlphaComponent(0.6).cgColor)
            ctx.setLineWidth(currentWidth)
            ctx.setLineDash(phase: 0, lengths: [4, 4])
            ep.stroke()
        }

        // Draw crop selection
        if isCroppingActive, let cropRect = cropSelectionRect {
            drawCropOverlay(ctx, rect: cropRect, imageBounds: imageRect)
        }
    }

    private func drawCheckerboard(_ ctx: CGContext, rect: CGRect) {
        let size: CGFloat = 8
        for row in 0...Int(rect.height / size) {
            for col in 0...Int(rect.width / size) {
                let r = CGRect(x: rect.minX + CGFloat(col) * size, y: rect.minY + CGFloat(row) * size, width: size, height: size)
                let isLight = (row + col) % 2 == 0
                ctx.setFillColor((isLight ? NSColor.white : NSColor(white: 0.85, alpha: 1)).cgColor)
                ctx.fill(r)
            }
        }
    }

    private func drawStroke(_ stroke: AnnotationStroke, ctx: CGContext, offsetX: CGFloat, offsetY: CGFloat) {
        let adjusted = stroke.copyStroke()
        adjusted.points = adjusted.points.map { CGPoint(x: $0.x + offsetX, y: $0.y + offsetY) }
        if let origin = adjusted.textOrigin { adjusted.textOrigin = CGPoint(x: origin.x + offsetX, y: origin.y + offsetY) }
        adjusted.draw(in: ctx)
    }

    private func drawCropOverlay(_ ctx: CGContext, rect: CGRect, imageBounds: CGRect) {
        // Dim outside crop rect
        ctx.setFillColor(NSColor.black.withAlphaComponent(0.45).cgColor)
        // Top
        ctx.fill(CGRect(x: imageBounds.minX, y: rect.maxY, width: imageBounds.width, height: imageBounds.maxY - rect.maxY))
        // Bottom
        ctx.fill(CGRect(x: imageBounds.minX, y: imageBounds.minY, width: imageBounds.width, height: rect.minY - imageBounds.minY))
        // Left
        ctx.fill(CGRect(x: imageBounds.minX, y: rect.minY, width: rect.minX - imageBounds.minX, height: rect.height))
        // Right
        ctx.fill(CGRect(x: rect.maxX, y: rect.minY, width: imageBounds.maxX - rect.maxX, height: rect.height))

        // Crop border
        ctx.setStrokeColor(NSColor.white.cgColor)
        ctx.setLineWidth(1.5)
        ctx.stroke(rect)

        // Corner handles
        let hs: CGFloat = 8
        let corners: [(CGFloat, CGFloat)] = [(rect.minX, rect.minY), (rect.maxX, rect.minY),
                                              (rect.minX, rect.maxY), (rect.maxX, rect.maxY)]
        ctx.setFillColor(NSColor.white.cgColor)
        for (cx, cy) in corners {
            ctx.fill(CGRect(x: cx - hs/2, y: cy - hs/2, width: hs, height: hs))
        }

        // Size label
        let sizeStr = "\(Int(rect.width)) × \(Int(rect.height))"
        let attrs: [NSAttributedString.Key: Any] = [
            .font: NSFont.monospacedDigitSystemFont(ofSize: 11, weight: .regular),
            .foregroundColor: NSColor.white
        ]
        NSAttributedString(string: sizeStr, attributes: attrs).draw(at: CGPoint(x: rect.maxX + 4, y: rect.maxY - 14))
    }

    // MARK: - Mouse events

    override func mouseDown(with event: NSEvent) {
        let pt = convert(event.locationInWindow, from: nil)

        if isCroppingActive {
            cropStartPoint = pt
            cropSelectionRect = CGRect(origin: pt, size: .zero)
            return
        }

        guard let doc = document else { return }
        guard bounds.contains(pt) else { return }
        let cropOffset = CGPoint.zero
        if currentTool == .text {
            let alert = NSAlert()
            alert.messageText = "Add text"
            let field = NSTextField(frame: CGRect(x: 0, y: 0, width: 300, height: 24))
            field.placeholderString = "Annotation text"
            alert.accessoryView = field
            alert.addButton(withTitle: "Add")
            alert.addButton(withTitle: "Cancel")
            alert.window.initialFirstResponder = field
            let addText: (NSApplication.ModalResponse) -> Void = { [weak self] response in
                guard response == .alertFirstButtonReturn, !field.stringValue.isEmpty, let self = self else { return }
                let stroke = AnnotationStroke(tool: .text, color: self.currentColor, width: self.currentWidth, points: [pt])
                stroke.textContent = field.stringValue
                stroke.textOrigin = pt
                doc.commitStroke(stroke)
            }
            if let window = window { alert.beginSheetModal(for: window, completionHandler: addText) }
            return
        }

        if currentTool == .eraser {
            eraserPath = NSBezierPath()
            eraserPath?.move(to: pt)
            return
        }

        let constrainedPt: CGPoint
        if rulerGuide.isActive && (currentTool == .pen || currentTool == .pencil || currentTool == .highlighter) {
            constrainedPt = rulerGuide.constrainToRuler(pt)
        } else {
            constrainedPt = pt
        }

        let adjPt = CGPoint(x: constrainedPt.x + cropOffset.x, y: constrainedPt.y + cropOffset.y)
        activeStroke = AnnotationStroke(tool: currentTool, color: currentColor, width: currentWidth, points: [adjPt])
    }

    override func mouseDragged(with event: NSEvent) {
        let pt = convert(event.locationInWindow, from: nil)

        if isCroppingActive, let start = cropStartPoint {
            cropSelectionRect = CGRect(x: min(start.x, pt.x), y: min(start.y, pt.y),
                                       width: abs(pt.x - start.x), height: abs(pt.y - start.y)).intersection(bounds)
            needsDisplay = true
            return
        }

        if let eraserPath = eraserPath {
            eraserPath.line(to: pt)
            needsDisplay = true
            return
        }

        guard let stroke = activeStroke else { return }
        let cropOffset = CGPoint.zero
        let constrainedPt: CGPoint
        if rulerGuide.isActive {
            constrainedPt = rulerGuide.constrainToRuler(pt)
        } else {
            constrainedPt = pt
        }
        stroke.addPoint(CGPoint(x: constrainedPt.x + cropOffset.x, y: constrainedPt.y + cropOffset.y))
        needsDisplay = true
    }

    override func mouseUp(with event: NSEvent) {
        if isCroppingActive {
            cropStartPoint = nil
            needsDisplay = true
            return
        }

        if let ep = eraserPath {
            document?.eraseStrokes(hitBy: ep, width: currentWidth)
            eraserPath = nil
            needsDisplay = true
            return
        }

        if let stroke = activeStroke {
            document?.commitStroke(stroke)
            activeStroke = nil
            needsDisplay = true
        }
    }

    override var acceptsFirstResponder: Bool { true }
    override func keyDown(with event: NSEvent) {
        if event.keyCode == 53 {
            activeStroke = nil
            eraserPath = nil
            cropSelectionRect = nil
            isCroppingActive = false
            needsDisplay = true
        } else { super.keyDown(with: event) }
    }
    deinit { if let observer = changeObserver { NotificationCenter.default.removeObserver(observer) } }

    // MARK: - Scroll/zoom notification

    func handleScrollMagnification(_ scale: CGFloat) {
        zoomLevel = scale
    }
}
