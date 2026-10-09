import AppKit
import Foundation

let app = NSApplication.shared
app.setActivationPolicy(.prohibited)
let mode = CommandLine.arguments.dropFirst().first ?? "canvas"
func image(_ width: Int, _ height: Int) -> CGImage {
    let context = CGContext(data: nil, width: width, height: height, bitsPerComponent: 8,
        bytesPerRow: 0, space: CGColorSpaceCreateDeviceRGB(), bitmapInfo: CGImageAlphaInfo.premultipliedLast.rawValue)!
    context.setFillColor(NSColor.white.withAlphaComponent(0.7).cgColor)
    context.fill(CGRect(x: 0, y: 0, width: width, height: height))
    return context.makeImage()!
}
func stroke(_ index: Int, count: Int = 500) -> AnnotationStroke {
    AnnotationStroke(tool: .pen, color: .red, width: 3, points: (0..<count).map {
        CGPoint(x: CGFloat($0 % 800), y: CGFloat(index % 400) + CGFloat($0 % 9))
    })
}
func timed(_ body: () -> Void) -> Double {
    let start = ProcessInfo.processInfo.systemUptime
    body()
    return (ProcessInfo.processInfo.systemUptime - start) * 1000
}
if mode == "history" {
    let document = ImageDocument(image: image(800, 600))
    let commit = timed { for index in 0..<1000 { document.commitStroke(stroke(index)) } }
    let undo = timed { for _ in 0..<1000 { document.undo() } }
    let redo = timed { for _ in 0..<1000 { document.redo() } }
    precondition(document.strokes.count == 1000)
    print("history commit_ms=\(commit) undo_ms=\(undo) redo_ms=\(redo)")
} else if mode == "erase" {
    let document = ImageDocument(image: image(800, 600))
    for index in 0..<400 { document.commitStroke(stroke(index)) }
    let path = NSBezierPath()
    path.move(to: CGPoint(x: 2000, y: 2000))
    for index in 1..<300 { path.line(to: CGPoint(x: 2000 + index, y: 2000)) }
    let elapsed = timed { document.eraseStrokes(hitBy: path, width: 8) }
    precondition(document.strokes.count == 400)
    print("erase_no_hit_ms=\(elapsed)")
} else {
    let document = ImageDocument(image: image(5000, 3000))
    for index in 0..<100 { document.commitStroke(stroke(index)) }
    let canvas = CanvasView(frame: CGRect(x: 0, y: 0, width: 5000, height: 3000))
    canvas.document = document
    let bitmap = NSBitmapImageRep(bitmapDataPlanes: nil, pixelsWide: 800, pixelsHigh: 600,
        bitsPerSample: 8, samplesPerPixel: 4, hasAlpha: true, isPlanar: false, colorSpaceName: .deviceRGB,
        bytesPerRow: 0, bitsPerPixel: 0)!
    let graphics = NSGraphicsContext(bitmapImageRep: bitmap)!
    NSGraphicsContext.saveGraphicsState()
    NSGraphicsContext.current = graphics
    graphics.cgContext.clip(to: CGRect(x: 0, y: 0, width: 800, height: 600))
    canvas.draw(CGRect(x: 0, y: 0, width: 800, height: 600))
    let elapsed = timed { for _ in 0..<12 { autoreleasepool { canvas.draw(CGRect(x: 0, y: 0, width: 800, height: 600)) } } }
    NSGraphicsContext.restoreGraphicsState()
    print("canvas_800x600_of_5000x3000_mean_ms=\(elapsed / 12)")
    if let output = CommandLine.arguments.dropFirst(2).first, let png = bitmap.representation(using: .png, properties: [:]) {
        try png.write(to: URL(fileURLWithPath: output))
    }
}
