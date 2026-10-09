import AppKit
import ImageIO
import UniformTypeIdentifiers

let app = NSApplication.shared
app.setActivationPolicy(.prohibited)
var failures: [String] = []
var checks = 0
func check(_ ok: Bool, _ message: String) {
    checks += 1
    if !ok { failures.append(message) }
    print("\(ok ? "PASS" : "FAIL"): \(message)")
}
func solid(width: Int, height: Int) -> CGImage {
    let context = CGContext(data: nil, width: width, height: height, bitsPerComponent: 8,
        bytesPerRow: 0, space: CGColorSpaceCreateDeviceRGB(),
        bitmapInfo: CGImageAlphaInfo.premultipliedLast.rawValue)!
    context.setFillColor(NSColor.white.cgColor)
    context.fill(CGRect(x: 0, y: 0, width: width, height: height))
    return context.makeImage()!
}
func quadrants() -> CGImage {
    let width = 80, height = 40
    let colors: [[UInt8]] = [[255,0,0,255], [0,255,0,255], [0,0,255,255], [255,255,0,255]]
    var bytes: [UInt8] = []
    for y in 0..<height {
        for x in 0..<width { bytes.append(contentsOf: colors[(y >= height / 2 ? 2 : 0) + (x >= width / 2 ? 1 : 0)]) }
    }
    return CGImage(width: width, height: height, bitsPerComponent: 8, bitsPerPixel: 32,
        bytesPerRow: width * 4, space: CGColorSpaceCreateDeviceRGB(),
        bitmapInfo: CGBitmapInfo(rawValue: CGImageAlphaInfo.premultipliedLast.rawValue),
        provider: CGDataProvider(data: Data(bytes) as CFData)!, decode: nil,
        shouldInterpolate: false, intent: .defaultIntent)!
}
func cornerColors(_ image: CGImage) -> [Int] {
    let rep = NSBitmapImageRep(cgImage: image)
    return [(3, 3), (image.width - 4, 3), (3, image.height - 4), (image.width - 4, image.height - 4)].map { x, y in
        let color = rep.colorAt(x: x, y: y)!.usingColorSpace(.deviceRGB)!
        let channels = [color.redComponent, color.greenComponent, color.blueComponent]
        if channels[0] > 0.8 && channels[1] > 0.8 && channels[2] < 0.2 { return 3 }
        return channels.enumerated().max(by: { $0.element < $1.element })!.offset
    }
}
let expectedCorners = [
    [0,1,2,3], [1,0,3,2], [3,2,1,0], [2,3,0,1],
    [0,2,1,3], [2,0,3,1], [3,1,2,0], [1,3,0,2]
]
for orientation in 1...8 {
    let data = NSMutableData()
    let destination = CGImageDestinationCreateWithData(data, UTType.jpeg.identifier as CFString, 1, nil)!
    CGImageDestinationAddImage(destination, quadrants(), [kCGImagePropertyOrientation: orientation,
        kCGImageDestinationLossyCompressionQuality: 1] as CFDictionary)
    check(CGImageDestinationFinalize(destination), "Create orientation \(orientation) fixture")
    let decoded = ExportManager.shared.decode(data: data as Data)!.0
    check(decoded.width == (orientation >= 5 ? 40 : 80) && decoded.height == (orientation >= 5 ? 80 : 40),
        "Orientation \(orientation) preserves full pixel dimensions")
    check(cornerColors(decoded) == expectedCorners[orientation - 1], "Orientation \(orientation) renders upright corners")
    let roundtrip = ExportManager.shared.decode(data: ExportManager.shared.encode(image: decoded, format: .png)!)!.0
    check(cornerColors(roundtrip) == expectedCorners[orientation - 1], "Orientation \(orientation) remains upright after saving")
}
func inkBounds(_ image: CGImage) -> CGRect {
    let rep = NSBitmapImageRep(cgImage: image)
    var loX = image.width, loY = image.height, hiX = -1, hiY = -1
    for y in 0..<image.height {
        for x in 0..<image.width {
            let color = rep.colorAt(x: x, y: y)!.usingColorSpace(.deviceRGB)!
            if color.redComponent > 0.7 && color.greenComponent < 0.5 {
                loX = min(loX, x); loY = min(loY, y); hiX = max(hiX, x); hiY = max(hiY, y)
            }
        }
    }
    return CGRect(x: loX, y: loY, width: max(0, hiX - loX + 1), height: max(0, hiY - loY + 1))
}
for width: CGFloat in [1, 3, 6] {
    let text = AnnotationStroke(tool: .text, color: .red, width: width, points: [CGPoint(x: 10, y: 10)])
    text.textContent = "Testing"; text.textOrigin = CGPoint(x: 10, y: 10)
    let normal = inkBounds(AnnotationRenderer.render(strokes: [text], over: solid(width: 200, height: 100), imageScale: 1)!)
    let retina = inkBounds(AnnotationRenderer.render(strokes: [text], over: solid(width: 400, height: 200), imageScale: 2)!)
    check(normal.width > 0 && normal.height > 0, "Text at width \(width) renders visible glyphs")
    check(abs(retina.width / 2 - normal.width) <= 2 && abs(retina.height / 2 - normal.height) <= 2,
        "Text at width \(width) retains logical size in Retina export")
    check(abs(retina.minX / 2 - normal.minX) <= 1 && abs(retina.minY / 2 - normal.minY) <= 1,
        "Text at width \(width) retains logical origin in Retina export")
}
let text = AnnotationStroke(tool: .text, color: .red, width: 1, points: [CGPoint(x: 10, y: 10)])
text.textContent = "Testing"; text.textOrigin = CGPoint(x: 10, y: 10)
func path(_ a: CGPoint, _ b: CGPoint) -> NSBezierPath {
    let result = NSBezierPath(); result.move(to: a); result.line(to: b); return result
}
let horizontal = path(CGPoint(x: 0, y: 18), CGPoint(x: 150, y: 18))
check(text.isHit(byEraserPath: horizontal, width: 2), "Fast horizontal eraser drag intersects text between endpoints")
check(text.isHit(byEraserPath: path(CGPoint(x: 30, y: 0), CGPoint(x: 30, y: 50)), width: 2),
    "Fast vertical eraser drag intersects text between endpoints")
check(!text.isHit(byEraserPath: path(CGPoint(x: 0, y: 50), CGPoint(x: 150, y: 50)), width: 2),
    "Eraser outside text leaves annotation intact")
let document = ImageDocument(image: solid(width: 200, height: 100))
document.commitStroke(text)
document.eraseStrokes(hitBy: horizontal, width: 2)
check(document.strokes.isEmpty, "Eraser removes crossed text annotation")
document.undo()
check(document.strokes.count == 1 && document.strokes[0].textContent == "Testing", "Undo restores erased text")
document.redo()
check(document.strokes.isEmpty, "Redo removes erased text again")
let pasteboard = NSPasteboard.withUniqueName()
defer { pasteboard.releaseGlobally() }
pasteboard.setData(Data("invalid".utf8), forType: .png)
pasteboard.setData(ExportManager.shared.encode(image: solid(width: 20, height: 30), format: .tiff)!, forType: .tiff)
let fallback = ExportManager.shared.readImageFromClipboard(pasteboard: pasteboard)
check(fallback?.width == 20 && fallback?.height == 30, "Clipboard uses TIFF when PNG representation is malformed")
pasteboard.clearContents()
pasteboard.setData(ExportManager.shared.encode(image: solid(width: 30, height: 20), format: .png)!, forType: .png)
pasteboard.setData(Data("invalid".utf8), forType: .tiff)
let preferred = ExportManager.shared.readImageFromClipboard(pasteboard: pasteboard)
check(preferred?.width == 30 && preferred?.height == 20, "Clipboard keeps valid PNG when TIFF representation is malformed")
pasteboard.clearContents()
pasteboard.setData(Data("invalid".utf8), forType: .png)
pasteboard.setData(Data("invalid".utf8), forType: .tiff)
check(ExportManager.shared.readImageFromClipboard(pasteboard: pasteboard) == nil, "Clipboard with no decodable image returns nil")
let directory = FileManager.default.temporaryDirectory.appendingPathComponent(UUID().uuidString)
try FileManager.default.createDirectory(at: directory, withIntermediateDirectories: true)
defer { try? FileManager.default.removeItem(at: directory) }
let broken = directory.appendingPathComponent("broken.png")
try Data("not an image".utf8).write(to: broken)
do { _ = try ExportManager.shared.loadImage(from: broken); check(false, "Invalid image reports failure") }
catch { check(true, "Invalid image reports failure") }
do { _ = try ExportManager.shared.loadImage(from: directory.appendingPathComponent("missing.png")); check(false, "Missing image reports failure") }
catch { check(true, "Missing image reports failure") }
print("\(checks - failures.count)/\(checks) export regression checks passed")
if !failures.isEmpty { exit(1) }
