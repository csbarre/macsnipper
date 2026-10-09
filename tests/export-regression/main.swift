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

// Pump the main run loop, rather than blocking it with a semaphore: file workers
// deliver UI callbacks on the main queue.
func waitFor<T>(_ start: (@escaping (T) -> Void) -> Void) -> T? {
    var value: T?
    start { value = $0 }
    let deadline = Date().addingTimeInterval(10)
    while value == nil && Date() < deadline {
        _ = RunLoop.current.run(mode: .default, before: Date().addingTimeInterval(0.01))
    }
    return value
}
let asyncDoc = ImageDocument(image: solid(width: 120, height: 80))
let snapshot = asyncDoc.snapshotForExport()
let asyncPath = directory.appendingPathComponent("async.png")
var callbackOnMain = false
let writeResult: Result<Void, Error>? = waitFor { done in
    ExportManager.shared.write(snapshot: snapshot, to: asyncPath) { result in
        callbackOnMain = Thread.isMainThread
        done(result)
    }
}
check((try? writeResult?.get()) != nil, "Async snapshot write completes successfully")
check(callbackOnMain, "Async write callback runs on main thread")
let loaded: Result<(CGImage, CGFloat), Error>? = waitFor { done in
    ExportManager.shared.loadImageAsync(from: asyncPath, completion: done)
}
check((try? loaded?.get().0.width) == 120, "Async load decodes saved dimensions")
let badLoad: Result<(CGImage, CGFloat), Error>? = waitFor { done in
    ExportManager.shared.loadImageAsync(from: broken, completion: done)
}
if case .failure? = badLoad { check(true, "Async corrupt-image load reports an error") }
else { check(false, "Async corrupt-image load reports an error") }
let badWrite: Result<Void, Error>? = waitFor { done in
    ExportManager.shared.write(snapshot: snapshot, to: directory.appendingPathComponent("absent/output.png"), completion: done)
}
if case .failure? = badWrite { check(true, "Async write reports filesystem failure") }
else { check(false, "Async write reports filesystem failure") }

let savedOldRevision = directory.appendingPathComponent("saved-revision.png")
let saveDuringEdit: Bool? = waitFor { done in
    ExportManager.shared.save(document: asyncDoc, to: savedOldRevision, completion: done)
    asyncDoc.commitStroke(AnnotationStroke(tool: .pen, color: .red, width: 3,
        points: [CGPoint(x: 10, y: 10), CGPoint(x: 80, y: 10)]))
}
check(saveDuringEdit == false && asyncDoc.isDirty, "Async save does not mark subsequent edits saved or approve replacement")
let earlierSaved = try! ExportManager.shared.loadImage(from: savedOldRevision).0
let savedColor = NSBitmapImageRep(cgImage: earlierSaved).colorAt(x: 40, y: 10)!.usingColorSpace(.deviceRGB)!
check(savedColor.greenComponent > 0.9, "Export snapshot excludes edits made after Save began")
asyncDoc.undo()
check(!asyncDoc.isDirty, "Undo to the revision written asynchronously restores clean state")
let savedUnchanged: Bool? = waitFor { done in
    ExportManager.shared.save(document: asyncDoc, to: directory.appendingPathComponent("unchanged.png"), completion: done)
}
check(savedUnchanged == true && !asyncDoc.isDirty, "Async unchanged save succeeds and marks the matching revision clean")

// Exercise the worker's annotated rendering path, including local Core Text
// layout. Mutating the input after snapshotting must not affect the export.
let annotatedDoc = ImageDocument(image: solid(width: 200, height: 100))
annotatedDoc.commitStroke(text)
let annotatedSnapshot = annotatedDoc.snapshotForExport()
let synchronousImage = annotatedSnapshot.render()!
annotatedDoc.commitStroke(AnnotationStroke(tool: .highlighter, color: .blue, width: 20,
    points: [CGPoint(x: 10, y: 65), CGPoint(x: 170, y: 65)]))
for format in ExportFormat.allCases {
    let annotatedPath = directory.appendingPathComponent("annotated.\(format.fileExtension)")
    let result: Result<Void, Error>? = waitFor { done in
        ExportManager.shared.write(snapshot: annotatedSnapshot, to: annotatedPath, completion: done)
    }
    check((try? result?.get()) != nil, "Background text export succeeds as \(format.displayName)")
    let output = try! ExportManager.shared.loadImage(from: annotatedPath).0
    // Compare to the same codec so JPEG's lossy edge pixels cannot masquerade
    // as a threading or glyph-layout difference.
    let reference = ExportManager.shared.decode(data: ExportManager.shared.encode(image: synchronousImage, format: format)!)!.0
    let synchronousInk = inkBounds(reference)
    let exportedInk = inkBounds(output)
    check(abs(exportedInk.minX - synchronousInk.minX) <= 1 &&
        abs(exportedInk.minY - synchronousInk.minY) <= 1 &&
        abs(exportedInk.width - synchronousInk.width) <= 2 &&
        abs(exportedInk.height - synchronousInk.height) <= 2,
        "Background \(format.displayName) text retains synchronous glyph size and origin")
}
let previousAppearance = app.appearance
app.appearance = NSAppearance(named: .darkAqua)
let adaptive = NSColor(name: nil) { appearance in
    appearance.bestMatch(from: [.aqua, .darkAqua]) == .darkAqua ? .red : .blue
}
let appearanceDoc = ImageDocument(image: solid(width: 80, height: 40))
appearanceDoc.commitStroke(AnnotationStroke(tool: .pen, color: adaptive, width: 10,
    points: [CGPoint(x: 10, y: 20), CGPoint(x: 70, y: 20)]))
let appearanceSnapshot = appearanceDoc.snapshotForExport()
app.appearance = NSAppearance(named: .aqua)
let appearancePath = directory.appendingPathComponent("appearance.png")
let appearanceResult: Result<Void, Error>? = waitFor { done in
    ExportManager.shared.write(snapshot: appearanceSnapshot, to: appearancePath, completion: done)
}
check((try? appearanceResult?.get()) != nil, "Adaptive-color snapshot exports after the app appearance changes")
let appearanceOutput = try! ExportManager.shared.loadImage(from: appearancePath).0
let frozenColor = NSBitmapImageRep(cgImage: appearanceOutput).colorAt(x: 40, y: 20)!.usingColorSpace(.deviceRGB)!
check(frozenColor.redComponent > 0.9 && frozenColor.blueComponent < 0.1,
    "Background export retains the editor color resolved when Save began")
app.appearance = previousAppearance
print("\(checks - failures.count)/\(checks) export regression checks passed")
if !failures.isEmpty { exit(1) }
