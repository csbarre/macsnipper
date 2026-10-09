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
if !failures.isEmpty { exit(1) }
