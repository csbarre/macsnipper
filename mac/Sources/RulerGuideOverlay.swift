import AppKit

// Movable ruler/protractor overlay drawn over the canvas.
// When active, constrains annotation points to the ruler line.

enum GuideMode {
    case ruler
    case protractor
}

final class RulerGuideOverlay: NSView {
    override var isFlipped: Bool { true }
    var mode: GuideMode = .ruler { didSet { needsDisplay = true } }
    var isActive: Bool = false { didSet { needsDisplay = true; isHidden = !isActive } }

    // Ruler state
    var rulerCenter: CGPoint = .zero
    private(set) var rulerAngle: CGFloat = 0  // radians

    // Protractor state
    var protractorCenter: CGPoint = .zero
    private(set) var protractorAngle: CGFloat = 0

    // Drag state
    private var draggingHandle: HandleType = .none
    private var lastDragPoint: CGPoint = .zero

    enum HandleType { case none, body, rotateHandle }

    override init(frame: NSRect) {
        super.init(frame: frame)
        wantsLayer = true
        layer?.backgroundColor = NSColor.clear.cgColor
        isHidden = true
    }
    required init?(coder: NSCoder) { fatalError() }

    override func viewDidMoveToSuperview() {
        super.viewDidMoveToSuperview()
        if let sv = superview {
            rulerCenter = CGPoint(x: sv.bounds.midX, y: sv.bounds.midY)
            protractorCenter = CGPoint(x: sv.bounds.midX, y: sv.bounds.midY)
        }
    }

    // MARK: - Constrain a point to ruler line

    func constrainToRuler(_ point: CGPoint) -> CGPoint {
        if mode == .protractor {
            let angle = atan2(point.y - protractorCenter.y, point.x - protractorCenter.x)
            return CGPoint(x: protractorCenter.x + cos(angle) * 80, y: protractorCenter.y + sin(angle) * 80)
        }
        // Project point onto the ruler line through rulerCenter at rulerAngle
        let dx = point.x - rulerCenter.x
        let dy = point.y - rulerCenter.y
        let lineDir = CGPoint(x: cos(rulerAngle), y: sin(rulerAngle))
        let dot = dx * lineDir.x + dy * lineDir.y
        return CGPoint(x: rulerCenter.x + dot * lineDir.x,
                       y: rulerCenter.y + dot * lineDir.y)
    }

    // MARK: - Drawing

    override func draw(_ dirtyRect: NSRect) {
        guard isActive else { return }
        guard let ctx = NSGraphicsContext.current?.cgContext else { return }

        switch mode {
        case .ruler:    drawRuler(ctx)
        case .protractor: drawProtractor(ctx)
        }
    }

    private func drawRuler(_ ctx: CGContext) {
        let length = max(bounds.width, bounds.height) * 1.5
        let dir = CGPoint(x: cos(rulerAngle), y: sin(rulerAngle))
        let p1 = CGPoint(x: rulerCenter.x - dir.x * length / 2, y: rulerCenter.y - dir.y * length / 2)
        let p2 = CGPoint(x: rulerCenter.x + dir.x * length / 2, y: rulerCenter.y + dir.y * length / 2)

        // Ruler body
        ctx.setStrokeColor(NSColor.systemYellow.withAlphaComponent(0.8).cgColor)
        ctx.setLineWidth(2)
        ctx.move(to: p1); ctx.addLine(to: p2); ctx.strokePath()

        // Tick marks every 50 pts
        let perpDir = CGPoint(x: -dir.y, y: dir.x)
        let tickSpacing: CGFloat = 50
        let numTicks = Int(length / tickSpacing)
        ctx.setStrokeColor(NSColor.systemYellow.withAlphaComponent(0.6).cgColor)
        ctx.setLineWidth(1)
        for i in -numTicks...numTicks {
            let t = CGFloat(i) * tickSpacing
            let tick = CGPoint(x: rulerCenter.x + dir.x * t, y: rulerCenter.y + dir.y * t)
            let tickLen: CGFloat = i % 5 == 0 ? 10 : 5
            ctx.move(to: CGPoint(x: tick.x + perpDir.x * tickLen, y: tick.y + perpDir.y * tickLen))
            ctx.addLine(to: CGPoint(x: tick.x - perpDir.x * tickLen, y: tick.y - perpDir.y * tickLen))
        }
        ctx.strokePath()

        // Rotate handle
        let handleDist: CGFloat = 80
        let handlePos = CGPoint(x: rulerCenter.x - dir.y * handleDist, y: rulerCenter.y + dir.x * handleDist)
        ctx.setFillColor(NSColor.systemYellow.withAlphaComponent(0.9).cgColor)
        ctx.fillEllipse(in: CGRect(x: handlePos.x - 6, y: handlePos.y - 6, width: 12, height: 12))

        // Center dot
        ctx.setFillColor(NSColor.white.cgColor)
        ctx.fillEllipse(in: CGRect(x: rulerCenter.x - 4, y: rulerCenter.y - 4, width: 8, height: 8))

        // Angle label
        let degrees = rulerAngle * 180 / .pi
        let label = String(format: "%.1f°", degrees.truncatingRemainder(dividingBy: 360))
        drawLabel(label, at: CGPoint(x: rulerCenter.x + 12, y: rulerCenter.y + 4), ctx: ctx)
    }

    private func drawProtractor(_ ctx: CGContext) {
        let radius: CGFloat = 80
        let center = protractorCenter

        // Outer circle
        ctx.setStrokeColor(NSColor.systemCyan.withAlphaComponent(0.8).cgColor)
        ctx.setLineWidth(2)
        ctx.strokeEllipse(in: CGRect(x: center.x - radius, y: center.y - radius, width: radius * 2, height: radius * 2))

        // Angle lines at 0 and protractorAngle
        let angles: [CGFloat] = [0, protractorAngle]
        for angle in angles {
            let endPt = CGPoint(x: center.x + cos(angle) * radius, y: center.y + sin(angle) * radius)
            ctx.setStrokeColor(NSColor.systemCyan.withAlphaComponent(0.9).cgColor)
            ctx.move(to: center); ctx.addLine(to: endPt); ctx.strokePath()
        }

        // Arc
        ctx.setStrokeColor(NSColor.systemCyan.withAlphaComponent(0.5).cgColor)
        ctx.addArc(center: center, radius: radius * 0.5, startAngle: 0, endAngle: protractorAngle, clockwise: protractorAngle < 0)
        ctx.strokePath()

        // Degree ticks
        ctx.setStrokeColor(NSColor.systemCyan.withAlphaComponent(0.4).cgColor)
        for deg in stride(from: 0, to: 360, by: 10) {
            let a = CGFloat(deg) * .pi / 180
            let len: CGFloat = deg % 90 == 0 ? 12 : (deg % 30 == 0 ? 8 : 4)
            let inner = CGPoint(x: center.x + cos(a) * (radius - len), y: center.y + sin(a) * (radius - len))
            let outer = CGPoint(x: center.x + cos(a) * radius, y: center.y + sin(a) * radius)
            ctx.move(to: inner); ctx.addLine(to: outer)
        }
        ctx.strokePath()

        // Angle label
        let degrees = protractorAngle * 180 / .pi
        let label = String(format: "%.1f°", abs(degrees))
        drawLabel(label, at: CGPoint(x: center.x + radius + 8, y: center.y), ctx: ctx)

        // Center dot
        ctx.setFillColor(NSColor.white.cgColor)
        ctx.fillEllipse(in: CGRect(x: center.x - 4, y: center.y - 4, width: 8, height: 8))

        // Drag handle for second line
        let handleAngle = protractorAngle
        let handlePos = CGPoint(x: center.x + cos(handleAngle) * radius, y: center.y + sin(handleAngle) * radius)
        ctx.setFillColor(NSColor.systemCyan.withAlphaComponent(0.9).cgColor)
        ctx.fillEllipse(in: CGRect(x: handlePos.x - 6, y: handlePos.y - 6, width: 12, height: 12))
    }

    private func drawLabel(_ text: String, at point: CGPoint, ctx: CGContext) {
        let attrs: [NSAttributedString.Key: Any] = [
            .font: NSFont.monospacedDigitSystemFont(ofSize: 11, weight: .regular),
            .foregroundColor: NSColor.white
        ]
        let str = NSAttributedString(string: text, attributes: attrs)
        str.draw(at: point)
    }

    // MARK: - Hit testing

    private func handleAt(_ point: CGPoint) -> HandleType {
        switch mode {
        case .ruler:
            // Rotate handle
            let dir = CGPoint(x: cos(rulerAngle), y: sin(rulerAngle))
            let handlePos = CGPoint(x: rulerCenter.x - dir.y * 80, y: rulerCenter.y + dir.x * 80)
            if dist(point, handlePos) < 12 { return .rotateHandle }
            // Body: distance to ruler line
            let proj = pointToLineDist(point, linePoint: rulerCenter, lineAngle: rulerAngle)
            if proj < 10 { return .body }
        case .protractor:
            let handlePos = CGPoint(x: protractorCenter.x + cos(protractorAngle) * 80,
                                    y: protractorCenter.y + sin(protractorAngle) * 80)
            if dist(point, handlePos) < 12 { return .rotateHandle }
            if dist(point, protractorCenter) < 10 { return .body }
        }
        return .none
    }

    private func dist(_ a: CGPoint, _ b: CGPoint) -> CGFloat {
        sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y))
    }

    private func pointToLineDist(_ point: CGPoint, linePoint: CGPoint, lineAngle: CGFloat) -> CGFloat {
        let dx = point.x - linePoint.x
        let dy = point.y - linePoint.y
        let lineDir = CGPoint(x: cos(lineAngle), y: sin(lineAngle))
        let perp = dx * (-lineDir.y) + dy * lineDir.x
        return abs(perp)
    }

    // MARK: - Mouse events

    override func mouseDown(with event: NSEvent) {
        let pt = convert(event.locationInWindow, from: nil)
        draggingHandle = handleAt(pt)
        lastDragPoint = pt
        if draggingHandle == .none { super.mouseDown(with: event) }
    }

    override func mouseDragged(with event: NSEvent) {
        let pt = convert(event.locationInWindow, from: nil)
        let dx = pt.x - lastDragPoint.x
        let dy = pt.y - lastDragPoint.y
        switch (mode, draggingHandle) {
        case (.ruler, .body):
            rulerCenter = CGPoint(x: rulerCenter.x + dx, y: rulerCenter.y + dy)
        case (.ruler, .rotateHandle):
            let v = CGPoint(x: pt.x - rulerCenter.x, y: pt.y - rulerCenter.y)
            rulerAngle = atan2(v.y, v.x) - .pi / 2
        case (.protractor, .body):
            protractorCenter = CGPoint(x: protractorCenter.x + dx, y: protractorCenter.y + dy)
        case (.protractor, .rotateHandle):
            let v = CGPoint(x: pt.x - protractorCenter.x, y: pt.y - protractorCenter.y)
            protractorAngle = atan2(v.y, v.x)
        default:
            super.mouseDragged(with: event)
        }
        lastDragPoint = pt
        needsDisplay = true
    }

    override func mouseUp(with event: NSEvent) {
        if draggingHandle != .none {
            draggingHandle = .none
        } else {
            super.mouseUp(with: event)
        }
    }

    override func hitTest(_ point: NSPoint) -> NSView? {
        guard isActive else { return nil }
        let hit = handleAt(convert(point, from: superview))
        return hit != .none ? self : nil
    }

    override var acceptsFirstResponder: Bool { false }
}
