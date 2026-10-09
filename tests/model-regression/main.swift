import AppKit
var failures: [String] = []
func check(_ ok: Bool, _ message: String) { if !ok { failures.append(message) }; print("\(ok ? "PASS" : "FAIL"): \(message)") }
func fixture() -> CGImage {
    let c = CGContext(data:nil,width:100,height:80,bitsPerComponent:8,bytesPerRow:0,space:CGColorSpaceCreateDeviceRGB(),bitmapInfo:CGImageAlphaInfo.premultipliedLast.rawValue)!
    c.setFillColor(NSColor.white.cgColor);c.fill(CGRect(x:0,y:0,width:100,height:80));return c.makeImage()!
}
func red(_ image: CGImage, x:Int, y:Int) -> Bool {
    guard let c = NSBitmapImageRep(cgImage:image).colorAt(x:x,y:y)?.usingColorSpace(.deviceRGB) else { return false }
    return c.redComponent > 0.8 && c.greenComponent < 0.2 && c.blueComponent < 0.2
}
let undo = ImageDocument(image:fixture())
undo.commitStroke(AnnotationStroke(tool:.pen,color:.red,width:4,points:[CGPoint(x:10,y:10),CGPoint(x:30,y:10)]))
if undo.undoManager.groupingLevel > 0 { undo.undoManager.endUndoGrouping() }
undo.undo()
check(undo.strokes.isEmpty,"Undo removes committed stroke")
check(undo.canRedo,"Undo permits redo")
if undo.canRedo { undo.redo();check(undo.strokes.count == 1,"Redo restores committed stroke") }
let orientation = ImageDocument(image:fixture())
orientation.commitStroke(AnnotationStroke(tool:.pen,color:.red,width:4,points:[CGPoint(x:10,y:10),CGPoint(x:30,y:10)]))
check(red(orientation.renderFlatImage()!,x:20,y:10),"Annotation renders at top-left canvas coordinate")
let crop = ImageDocument(image:fixture())
crop.commitStroke(AnnotationStroke(tool:.pen,color:.red,width:4,points:[CGPoint(x:20,y:20),CGPoint(x:30,y:20)]))
crop.applyCrop(CGRect(x:10,y:10,width:50,height:50))
check(red(crop.renderFlatImage()!,x:15,y:10),"Crop translates annotation exactly once")
let erase = ImageDocument(image:fixture())
erase.commitStroke(AnnotationStroke(tool:.pen,color:.red,width:2,points:[CGPoint(x:10,y:40),CGPoint(x:90,y:40)]))
let path=NSBezierPath();path.move(to:CGPoint(x:50,y:30));path.line(to:CGPoint(x:50,y:50))
erase.eraseStrokes(hitBy:path,width:4)
check(erase.strokes.isEmpty,"Eraser intersects a stroke between sampled endpoints")
let masked = FreeformMask(points:[CGPoint(x:0,y:0),CGPoint(x:50,y:0),CGPoint(x:0,y:40)]).applyMask(to:fixture(),in:CGRect(x:0,y:0,width:100,height:80))!
let maskRep = NSBitmapImageRep(cgImage:masked)
check((maskRep.colorAt(x:5,y:70)?.alphaComponent ?? 0) > 0.9 && (maskRep.colorAt(x:5,y:5)?.alphaComponent ?? 1) < 0.1, "Freeform AppKit bottom-left mask is not mirrored")
crop.applyCrop(CGRect(x:5,y:5,width:30,height:30))
check(red(crop.renderFlatImage()!,x:10,y:5), "Repeated crop preserves annotation position")
crop.markSaved(at:URL(fileURLWithPath:"/tmp/test.png"))
crop.undo()
check(crop.isDirty,"Undo after saving marks document dirty")
crop.redo()
check(!crop.isDirty,"Redo to saved revision restores clean state")

// Mixed operations protect index-based undo, annotation ordering, revision
// identity, and crop-cache invalidation after draw/erase history was optimized.
let mixed = ImageDocument(image: fixture())
let input = AnnotationStroke(tool: .pen, color: .red, width: 2, points: [CGPoint(x: 10, y: 40)])
mixed.commitStroke(input)
input.points[0] = CGPoint(x: 99, y: 79)
check(mixed.strokes[0].points[0].x == 10, "Committed stroke remains independent of caller mutation")
mixed.commitStroke(AnnotationStroke(tool: .pen, color: .blue, width: 2, points: [CGPoint(x: 30, y: 40)]))
mixed.markSaved(at: URL(fileURLWithPath: "/tmp/macsnipper-mixed-undo.png"))
mixed.commitStroke(AnnotationStroke(tool: .pen, color: .green, width: 2, points: [CGPoint(x: 50, y: 40)]))
let middle = NSBezierPath()
middle.move(to: CGPoint(x: 30, y: 38)); middle.line(to: CGPoint(x: 30, y: 42))
mixed.eraseStrokes(hitBy: middle, width: 2)
check(mixed.strokes.map { $0.points[0].x } == [10, 50], "Erase preserves order around the removed middle stroke")
mixed.commitStroke(AnnotationStroke(tool: .pen, color: .black, width: 2, points: [CGPoint(x: 70, y: 40)]))
mixed.applyCrop(CGRect(x: 5, y: 5, width: 80, height: 60))
let cached = mixed.croppedImage
check(cached === mixed.croppedImage, "Repeated cropped image access reuses the same image")
mixed.replaceImage(fixture(), scale: 2)
check(mixed.croppedImage.width == 100 && mixed.strokes.isEmpty, "Image replacement clears the crop cache and annotations")
mixed.undo()
check(mixed.croppedImage.width == 80 && mixed.imageScale == 1 && mixed.strokes.count == 3, "Undo replacement restores cropped dimensions, scale and annotations")
mixed.undo()
check(mixed.croppedImage.width == 100 && mixed.strokes.map { $0.points[0].x } == [10, 50, 70], "Undo crop restores original annotation coordinates")
mixed.undo()
check(mixed.strokes.map { $0.points[0].x } == [10, 50], "Undo draw after crop restores the earlier stroke set")
mixed.undo()
check(mixed.strokes.map { $0.points[0].x } == [10, 30, 50], "Undo erase restores the original insertion order")
mixed.undo()
check(mixed.strokes.count == 2 && !mixed.isDirty, "Mixed undo reaches the saved revision cleanly")
for _ in 0..<5 { mixed.redo() }
check(mixed.strokes.isEmpty && mixed.imageScale == 2 && mixed.isDirty, "Mixed redo reaches the replaced image again")
for _ in 0..<5 { mixed.undo() }
mixed.commitStroke(AnnotationStroke(tool: .pencil, color: .purple, width: 2, points: [CGPoint(x: 80, y: 20)]))
check(!mixed.canRedo && mixed.strokes.count == 3, "New edit after undo discards the old redo branch")

let multiple = ImageDocument(image: fixture())
for x in [10, 30, 50, 70] {
    multiple.commitStroke(AnnotationStroke(tool: .pen, color: .red, width: 2, points: [CGPoint(x: x, y: 40)]))
}
let sweep = NSBezierPath()
sweep.move(to: CGPoint(x: 9, y: 40)); sweep.line(to: CGPoint(x: 51, y: 40))
multiple.eraseStrokes(hitBy: sweep, width: 2)
check(multiple.strokes.map { $0.points[0].x } == [70], "One erase removes multiple strokes together")
multiple.undo()
check(multiple.strokes.map { $0.points[0].x } == [10, 30, 50, 70], "Undo multi-stroke erase restores ordered strokes")
multiple.redo()
check(multiple.strokes.map { $0.points[0].x } == [70], "Redo multi-stroke erase removes exactly the prior hits")
let tangent = NSBezierPath()
tangent.move(to: CGPoint(x: 72, y: 40))
multiple.eraseStrokes(hitBy: tangent, width: 2)
check(multiple.strokes.isEmpty, "Bounds prefilter retains tangential eraser contact")

let scaledCrop = ImageDocument(image: fixture())
scaledCrop.applyCrop(CGRect(x: 0, y: 0, width: 20, height: 20))
check(scaledCrop.croppedImage.width == 20, "Crop cache starts at the current scale")
scaledCrop.imageScale = 2
check(scaledCrop.croppedImage.width == 40, "Changing image scale invalidates the crop cache")
let retinaStroke = AnnotationStroke(tool: .pen, color: .red, width: 3,
    points: [CGPoint(x: 15, y: 15), CGPoint(x: 25, y: 15)])
let translatedRetina = AnnotationRenderer.render(strokes: [retinaStroke], over: fixture(),
    cropRect: CGRect(x: 10, y: 10, width: 20, height: 20), imageScale: 2)!
check(translatedRetina.width == 40 && translatedRetina.height == 40 && red(translatedRetina, x: 20, y: 10),
    "Direct Retina crop export translates annotation origin exactly once")
if !failures.isEmpty { exit(1) }
