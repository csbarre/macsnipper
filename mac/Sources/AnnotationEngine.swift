import AppKit
import CoreGraphics

// MARK: - Tool Types

enum AnnotationTool: Equatable {
    case pen
    case pencil
    case highlighter
    case eraser
    case text
    case crop
    case ruler
    case protractor
}

// MARK: - Annotation Stroke

final class AnnotationStroke: NSObject {
    let tool: AnnotationTool
    let color: NSColor
    let width: CGFloat
    var points: [CGPoint]
    var textContent: String?
    var textOrigin: CGPoint?
    var opacity: CGFloat

    var bezierPath: NSBezierPath {
        let path = NSBezierPath()
        guard !points.isEmpty else { return path }
        path.move(to: points[0])
        if points.count == 1 {
            // Single point: draw a dot
            let r = width / 2
            path.appendOval(in: CGRect(x: points[0].x - r, y: points[0].y - r, width: r * 2, height: r * 2))
        } else {
            for pt in points.dropFirst() {
                path.line(to: pt)
            }
        }
        path.lineWidth = width
        path.lineCapStyle = .round
        path.lineJoinStyle = .round
        return path
    }

    init(tool: AnnotationTool, color: NSColor, width: CGFloat, points: [CGPoint] = []) {
        self.tool = tool
        self.color = color
        self.width = width
        self.points = points
        switch tool {
        case .highlighter: self.opacity = 0.4
        case .pencil: self.opacity = 0.8
        default: self.opacity = 1.0
        }
        super.init()
    }

    func addPoint(_ point: CGPoint) {
        points.append(point)
    }

    func copyStroke() -> AnnotationStroke {
        let result = AnnotationStroke(tool: tool, color: color, width: width, points: points)
        result.textContent = textContent
        result.textOrigin = textOrigin
        result.opacity = opacity
        return result
    }

    func isHit(byEraserPath eraserPath: NSBezierPath, width eraserWidth: CGFloat) -> Bool {
        var eraserPoints: [CGPoint] = []
        for index in 0..<eraserPath.elementCount {
            var associated = [NSPoint](repeating: .zero, count: 3)
            let element = eraserPath.element(at: index, associatedPoints: &associated)
            switch element {
            case .moveTo, .lineTo: eraserPoints.append(associated[0])
            case .curveTo: eraserPoints.append(contentsOf: associated)
            default: break
            }
        }
        guard !eraserPoints.isEmpty else { return false }
        let radius = (eraserWidth + width) / 2
        let candidates = points.isEmpty ? (textOrigin.map { [$0] } ?? []) : points
        guard !candidates.isEmpty else { return false }
        func segments(_ points: [CGPoint]) -> [(CGPoint, CGPoint)] {
            points.count == 1 ? [(points[0], points[0])] : Array(zip(points, points.dropFirst()))
        }
        if tool == .text, let origin = textOrigin, let text = textContent {
            let size = (text as NSString).size(withAttributes: [.font: NSFont.systemFont(ofSize: max(width * 3, 12))])
            let bounds = CGRect(origin: origin, size: size).insetBy(dx: -eraserWidth / 2, dy: -eraserWidth / 2)
            let corners = [CGPoint(x: bounds.minX, y: bounds.minY), CGPoint(x: bounds.maxX, y: bounds.minY),
                           CGPoint(x: bounds.maxX, y: bounds.maxY), CGPoint(x: bounds.minX, y: bounds.maxY)]
            let edges = Array(zip(corners, Array(corners.dropFirst()) + [corners[0]]))
            // Fast drags can have both sampled endpoints outside the text. Test
            // every intervening segment against the whole annotation bounds.
            return segments(eraserPoints).contains { a, b in
                bounds.contains(a) || bounds.contains(b) || edges.contains { c, d in
                    Self.segmentDistance(a, b, c, d) <= 0.000001
                }
            }
        }
        for (a, b) in segments(candidates) {
            for (c, d) in segments(eraserPoints) {
                if Self.segmentDistance(a, b, c, d) <= radius { return true }
            }
        }
        return false
    }

    private static func pointDistance(_ point: CGPoint, _ a: CGPoint, _ b: CGPoint) -> CGFloat {
        let dx = b.x - a.x, dy = b.y - a.y
        let squaredLength = dx * dx + dy * dy
        let t = squaredLength == 0 ? 0 : min(1, max(0, ((point.x - a.x) * dx + (point.y - a.y) * dy) / squaredLength))
        return hypot(point.x - (a.x + t * dx), point.y - (a.y + t * dy))
    }
    private static func segmentDistance(_ a: CGPoint, _ b: CGPoint, _ c: CGPoint, _ d: CGPoint) -> CGFloat {
        let ab = CGPoint(x: b.x - a.x, y: b.y - a.y)
        let cd = CGPoint(x: d.x - c.x, y: d.y - c.y)
        let denominator = ab.x * cd.y - ab.y * cd.x
        if abs(denominator) > 0.000001 {
            let ac = CGPoint(x: c.x - a.x, y: c.y - a.y)
            let t = (ac.x * cd.y - ac.y * cd.x) / denominator
            let u = (ac.x * ab.y - ac.y * ab.x) / denominator
            if (0...1).contains(t) && (0...1).contains(u) { return 0 }
        }
        return min(pointDistance(a, c, d), pointDistance(b, c, d), pointDistance(c, a, b), pointDistance(d, a, b))
    }

    // MARK: - Rendering

    func draw(in context: CGContext, scale: CGFloat = 1.0) {
        context.saveGState()
        defer { context.restoreGState() }

        if tool == .text, let text = textContent, let origin = textOrigin {
            drawText(text, at: origin, in: context, scale: scale)
            return
        }

        let cgColor = color.withAlphaComponent(opacity).cgColor
        context.setStrokeColor(cgColor)
        context.setFillColor(cgColor)
        context.setLineWidth(width * scale)
        context.setLineCap(.round)
        context.setLineJoin(.round)

        if tool == .highlighter {
            context.setBlendMode(.multiply)
        }

        guard !points.isEmpty else { return }

        if points.count == 1 {
            let r = (width * scale) / 2
            context.fillEllipse(in: CGRect(x: points[0].x * scale - r, y: points[0].y * scale - r, width: r * 2, height: r * 2))
        } else {
            context.beginPath()
            context.move(to: CGPoint(x: points[0].x * scale, y: points[0].y * scale))
            for pt in points.dropFirst() {
                context.addLine(to: CGPoint(x: pt.x * scale, y: pt.y * scale))
            }
            context.strokePath()
        }
    }

    private func drawText(_ text: String, at origin: CGPoint, in context: CGContext, scale: CGFloat) {
        let fontSize = max(width * 3, 12)
        let attrs: [NSAttributedString.Key: Any] = [
            .font: NSFont.systemFont(ofSize: fontSize),
            .foregroundColor: color.withAlphaComponent(opacity)
        ]
        let str = NSAttributedString(string: text, attributes: attrs)
        let line = CTLineCreateWithAttributedString(str)
        // The caller uses top-left image coordinates. Flip glyphs back upright.
        context.translateBy(x: origin.x * scale, y: origin.y * scale)
        context.scaleBy(x: scale, y: -scale)
        context.textPosition = CGPoint(x: 0, y: -fontSize)
        CTLineDraw(line, context)
    }
}

// MARK: - Freeform Mask

struct FreeformMask {
    var points: [CGPoint]

    var cgPath: CGPath {
        let path = CGMutablePath()
        guard !points.isEmpty else { return path }
        path.move(to: points[0])
        for pt in points.dropFirst() {
            path.addLine(to: pt)
        }
        path.closeSubpath()
        return path
    }

    var hasEnclosedArea: Bool {
        guard points.count >= 3, let first = points.first,
              let farthest = points.max(by: { hypot($0.x - first.x, $0.y - first.y) < hypot($1.x - first.x, $1.y - first.y) }) else { return false }
        let dx = farthest.x - first.x, dy = farthest.y - first.y
        let length = hypot(dx, dy)
        guard length > 0 else { return false }
        // A line (even with many sampled points) cannot enclose a snip. Unlike
        // signed polygon area this also accepts self-crossing freeform outlines.
        return points.contains { abs(dx * ($0.y - first.y) - dy * ($0.x - first.x)) / length > 0.5 }
    }

    func applyMask(to image: CGImage, in bounds: CGRect) -> CGImage? {
        guard !points.isEmpty else { return image }
        guard hasEnclosedArea else { return nil }
        guard bounds.width > 0, bounds.height > 0 else { return nil }
        let width = image.width
        let height = image.height
        guard let ctx = CGContext(
            data: nil, width: width, height: height,
            bitsPerComponent: 8, bytesPerRow: 0,
            space: CGColorSpaceCreateDeviceRGB(),
            bitmapInfo: CGImageAlphaInfo.premultipliedLast.rawValue
        ) else { return nil }

        // Scale path to pixel coordinates
        let scaleX = CGFloat(width) / bounds.width
        let scaleY = CGFloat(height) / bounds.height

        let scaledPath = CGMutablePath()
        let scaledPoints = points.map { CGPoint(x: ($0.x - bounds.minX) * scaleX,
                                                 y: ($0.y - bounds.minY) * scaleY) }
        guard !scaledPoints.isEmpty else { return nil }
        scaledPath.move(to: scaledPoints[0])
        for pt in scaledPoints.dropFirst() { scaledPath.addLine(to: pt) }
        scaledPath.closeSubpath()

        ctx.addPath(scaledPath)
        ctx.clip()
        ctx.draw(image, in: CGRect(x: 0, y: 0, width: CGFloat(width), height: CGFloat(height)))
        return ctx.makeImage()
    }
}

// MARK: - Annotation Renderer

final class AnnotationRenderer {
    static func render(strokes: [AnnotationStroke], over image: CGImage, cropRect: CGRect? = nil, imageScale: CGFloat = 1.0) -> CGImage? {
        let scale = imageScale > 0 ? imageScale : 1
        var base = image
        let origin = cropRect?.origin ?? .zero
        if let crop = cropRect {
            let pixels = CGRect(x: crop.minX * scale, y: crop.minY * scale,
                width: crop.width * scale, height: crop.height * scale).integral
            guard let cropped = image.cropping(to: pixels) else { return nil }
            base = cropped
        }
        guard !strokes.isEmpty else { return base }
        guard let context = CGContext(data: nil, width: base.width, height: base.height,
            bitsPerComponent: 8, bytesPerRow: 0, space: CGColorSpaceCreateDeviceRGB(),
            bitmapInfo: CGImageAlphaInfo.premultipliedLast.rawValue) else { return nil }
        context.draw(base, in: CGRect(x: 0, y: 0, width: base.width, height: base.height))
        // Match the editor's flipped (top-left) coordinates without flipping the base image.
        context.translateBy(x: 0, y: CGFloat(base.height))
        context.scaleBy(x: 1, y: -1)
        for stroke in strokes {
            let adjusted = stroke.copyStroke()
            adjusted.points = adjusted.points.map { CGPoint(x: $0.x - origin.x, y: $0.y - origin.y) }
            if let text = adjusted.textOrigin { adjusted.textOrigin = CGPoint(x: text.x - origin.x, y: text.y - origin.y) }
            adjusted.draw(in: context, scale: scale)
        }
        return context.makeImage()
    }
}
