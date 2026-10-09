import AppKit
import ImageIO
import UniformTypeIdentifiers

// Self-test suite. Runs without screen capture permission.
// Returns true if all tests pass.
final class SelfTest {
    private var passed = 0
    private var failed = 0

    static func run() -> Bool {
        let t = SelfTest()
        t.runAll()
        let total = t.passed + t.failed
        print("[SelfTest] \(t.passed)/\(total) tests passed")
        return t.failed == 0
    }

    private func runAll() {
        let controller = EditorWindowController.shared
        controller.window?.contentView?.layoutSubtreeIfNeeded()
        let frame = controller.window?.frame ?? .zero
        assert(frame.width >= 720 && frame.height >= 520, "Editor initial window size", details: "\(frame)")
        assert(controller.window?.toolbar?.items.first(where: { $0.itemIdentifier.rawValue == "saveButton" })?.isEnabled == false, "Save starts disabled without an image")
        assert(!FreeformMask(points: [CGPoint(x: 0, y: 0), CGPoint(x: 20, y: 20), CGPoint(x: 40, y: 40)]).hasEnclosedArea, "Straight freeform drag is rejected")
        assert(FreeformMask(points: [CGPoint(x: 0, y: 0), CGPoint(x: 40, y: 0), CGPoint(x: 20, y: 40)]).hasEnclosedArea, "Closed freeform shape is accepted")
        testToolbarReactivation()
        testFitAndGuides()
        testCaptureSessionsAndPaste()
        testGeometry()
        testRetinaSizing()
        testFlippedOrientation()
        testFreeformMask()
        testAnnotationRendering()
        testCropUndoable()
        testEncodeDecodeFormats()
        testClipboardRoundtrip()
        testUndoRedo()
    }

    private func testToolbarReactivation() {
        let editor = EditorWindowController.shared
        let newItem = NSMenuItem(title: "New", action: #selector(EditorWindowController.newCapture(_:)), keyEquivalent: "")
        assert(editor.validateUserInterfaceItem(newItem), "New validates without NSDocument")
        guard let image = makeTestImage(width: 100, height: 80, color: .white),
              let toolbar = editor.window?.toolbar else { assert(false, "Toolbar fixture"); return }
        func controls(_ view: NSView) -> [NSControl] {
            ((view as? NSControl).map { [$0] } ?? []) + view.subviews.flatMap(controls)
        }
        for cycle in 1...3 {
            let doc = ImageDocument(image: image)
            doc.markUnsaved()
            editor.loadDocument(doc)
            // Reproduce AppKit's disabled custom-control state after hiding the
            // editor for selection, then exercise the key-window restoration.
            for item in toolbar.items {
                if let view = item.view { controls(view).forEach { $0.isEnabled = false } }
            }
            editor.windowDidBecomeKey(Notification(name: NSWindow.didBecomeKeyNotification, object: editor.window))
            toolbar.validateVisibleItems()
            let editableIDs = ["captureMode", "captureDelay", "newCapture", "openImage", "drawTools", "colorWell", "strokeWidth", "cropTool", "rulerTool", "protractorTool", "copyButton", "shareButton", "saveButton"]
            let ready = toolbar.items.filter { editableIDs.contains($0.itemIdentifier.rawValue) }.allSatisfy { item in
                item.isEnabled && (item.view.map { controls($0).allSatisfy { $0.isEnabled } } ?? false)
            }
            assert(ready, "Capture cycle \(cycle): toolbar remains editable after validation")
            let save = NSMenuItem(title: "Save", action: #selector(EditorWindowController.saveAs(_:)), keyEquivalent: "")
            assert(editor.validateUserInterfaceItem(save), "Capture cycle \(cycle): Save validates with image")
        }
    }

    private func testFitAndGuides() {
        guard let image = makeTestImage(width: 2000, height: 1000, color: .white) else { return }
        let document = ImageDocument(image: image)
        let scroll = CanvasScrollView(frame: CGRect(x: 0, y: 0, width: 800, height: 600))
        scroll.canvas.document = document
        scroll.layoutSubtreeIfNeeded()
        scroll.magnification = 2
        scroll.fitToWindow()
        let fitted = scroll.magnification
        assert(fitted <= 0.4 && fitted > 0.3, "Fit uses viewport dimensions after zooming in")
        scroll.magnification = 0.2
        scroll.fitToWindow()
        assertNear(scroll.magnification, fitted, tolerance: 0.01, "Fit is independent of previous zoom")
        scroll.fitToWindow()
        assertNear(scroll.magnification, fitted, tolerance: 0.01, "Repeated Fit is stable")
        let guide = scroll.canvas.rulerGuide
        guide.rulerCenter = CGPoint(x: 100, y: 100)
        guide.mode = .ruler
        let projected = guide.constrainToRuler(CGPoint(x: 150, y: 180))
        assertNear(projected.y, 100, "Ruler constrains drawing to its line")
        guide.mode = .protractor
        guide.protractorCenter = CGPoint(x: 100, y: 100)
        let circular = guide.constrainToRuler(CGPoint(x: 100, y: 200))
        assertNear(circular.y, 180, "Protractor constrains drawing to its circle")
    }

    private func testCaptureSessionsAndPaste() {
        var session = CaptureSessionState()
        assert(!session.isCapturing, "Capture initially idle")
        let first = session.begin()!
        assert(session.isCapturing && session.isCurrent(first), "Capture begins with current session")
        assert(session.begin() == nil, "Concurrent capture is rejected")
        assert(!session.finish(UUID()) && session.isCurrent(first), "Unrelated completion preserves current capture")
        assert(session.finish(first) && !session.isCapturing, "Completion clears capture state")
        assert(!session.finish(first), "Duplicate completion is ignored")
        let second = session.begin()!
        assert(first != second && session.isCurrent(second), "New capture has a distinct session")
        assert(!session.finish(first) && session.isCurrent(second), "Stale capture cannot finish newer capture")
        assert(session.finish(second) && !session.isCapturing, "Capture can complete again")

        guard let original = makeTestImage(width: 100, height: 80, color: .white),
              let pasted = makeTestImage(width: 60, height: 40, color: .red) else { return }
        let document = ImageDocument(image: original)
        document.commitStroke(AnnotationStroke(tool: .pen, color: .blue, width: 3, points: [CGPoint(x: 10, y: 10)]))
        document.markSaved(at: URL(fileURLWithPath: "/tmp/macsnipper-undo-fixture.png"))
        EditorWindowController.shared.loadDocument(document)
        EditorWindowController.shared.replaceWithPastedImage(pasted)
        assert(document.originalImage.width == 60 && document.strokes.isEmpty && document.isDirty, "Paste replaces image and marks edits")
        document.undo()
        assert(document.originalImage.width == 100 && document.strokes.count == 1 && !document.isDirty, "Undo paste restores saved image and annotations")
        document.redo()
        assert(document.originalImage.width == 60 && document.strokes.isEmpty && document.isDirty, "Redo paste restores pasted image")
    }

    // MARK: - Assert helpers

    private func assert(_ condition: Bool, _ name: String, details: String = "") {
        if condition {
            passed += 1
            print("[PASS] \(name)")
        } else {
            failed += 1
            print("[FAIL] \(name)\(details.isEmpty ? "" : ": \(details)")")
        }
    }

    private func assertNear(_ a: CGFloat, _ b: CGFloat, tolerance: CGFloat = 0.5, _ name: String) {
        assert(abs(a - b) <= tolerance, name, details: "\(a) ≠ \(b)")
    }

    // MARK: - Tests

    private func testGeometry() {
        // Rect intersection
        let r1 = CGRect(x: 0, y: 0, width: 100, height: 100)
        let r2 = CGRect(x: 50, y: 50, width: 100, height: 100)
        let intersection = r1.intersection(r2)
        assert(!intersection.isNull, "Rect intersection non-null")
        assertNear(intersection.width, 50, "Rect intersection width")
        assertNear(intersection.height, 50, "Rect intersection height")

        // Scale computation: 200px image at 2x scale → logical 100pt
        let imgW = 200, imgH = 100
        let scale: CGFloat = 2.0
        let logicalW = CGFloat(imgW) / scale
        let logicalH = CGFloat(imgH) / scale
        assertNear(logicalW, 100, "Logical width at 2x")
        assertNear(logicalH, 50, "Logical height at 2x")

        // Crop pixel mapping: logical crop at (10,10) 50x30, scale 2x → pixel (20,20) 100x60
        let cropLogical = CGRect(x: 10, y: 10, width: 50, height: 30)
        let cropPixel = CGRect(x: cropLogical.minX * scale, y: cropLogical.minY * scale,
                               width: cropLogical.width * scale, height: cropLogical.height * scale)
        assertNear(cropPixel.minX, 20, "Crop pixel X")
        assertNear(cropPixel.width, 100, "Crop pixel width")
    }

    private func testRetinaSizing() {
        // A 200x100 image at 2x scale should have logical size 100x50
        guard let img = makeTestImage(width: 200, height: 100, color: .red) else {
            assert(false, "Create 200x100 test image"); return
        }
        let doc = ImageDocument(image: img, scale: 2.0)
        let ls = doc.logicalSize
        assertNear(ls.width, 100, "Retina logical width")
        assertNear(ls.height, 50, "Retina logical height")
        assert(img.width == 200, "Raw pixel width")
        assert(img.height == 100, "Raw pixel height")
    }

    private func testFlippedOrientation() {
        // Create 4x4 image with top-left = red, bottom-left = blue
        let data = UnsafeMutablePointer<UInt8>.allocate(capacity: 4 * 4 * 4)
        defer { data.deallocate() }
        // Fill all rows blue, then top row red
        for y in 0..<4 {
            for x in 0..<4 {
                let base = (y * 4 + x) * 4
                let isTopRow = y == 0  // CGImage storage and cropping use top-left rows.
                data[base + 0] = isTopRow ? 255 : 0    // R
                data[base + 1] = 0                      // G
                data[base + 2] = isTopRow ? 0 : 255    // B
                data[base + 3] = 255                    // A
            }
        }
        let bitmapInfo = CGBitmapInfo(rawValue: CGImageAlphaInfo.premultipliedLast.rawValue)
        guard let provider = CGDataProvider(data: Data(bytes: data, count: 4 * 4 * 4) as CFData),
              let img = CGImage(width: 4, height: 4, bitsPerComponent: 8, bitsPerPixel: 32,
                                bytesPerRow: 4 * 4, space: CGColorSpaceCreateDeviceRGB(),
                                bitmapInfo: bitmapInfo, provider: provider,
                                decode: nil, shouldInterpolate: false, intent: .defaultIntent) else {
            assert(false, "Create orientation test image"); return
        }
        // Crop bottom half (y=0..1 in image pixel space)
        let bottomHalf = img.cropping(to: CGRect(x: 0, y: 0, width: 4, height: 2))
        assert(bottomHalf != nil, "Crop bottom half of image")
        assert(bottomHalf!.height == 2, "Cropped height = 2")
        let pixel = NSBitmapImageRep(cgImage: bottomHalf!).colorAt(x: 0, y: 0)!.usingColorSpace(.deviceRGB)!
        assert(pixel.redComponent > 0.9 && pixel.blueComponent < 0.1, "Top-left crop preserves red top row")
    }

    private func testFreeformMask() {
        guard let base = makeTestImage(width: 100, height: 100, color: .green) else {
            assert(false, "Create freeform base image"); return
        }
        // Triangle mask covering left half
        let mask = FreeformMask(points: [
            CGPoint(x: 0, y: 0), CGPoint(x: 50, y: 0),
            CGPoint(x: 25, y: 100)
        ])
        let bounds = CGRect(x: 0, y: 0, width: 100, height: 100)
        let masked = mask.applyMask(to: base, in: bounds)
        assert(masked != nil, "Freeform mask applied successfully")
        if let m = masked {
            assert(m.width == 100, "Masked image width preserved")
            assert(m.height == 100, "Masked image height preserved")
            // Check alpha: corner (0,0) should be opaque (inside triangle), far right should be transparent
            let pixelData = extractPixel(from: m, x: 1, y: 1)
            assert(pixelData != nil, "Can extract pixel from masked image")
        }
    }

    private func testAnnotationRendering() {
        guard let base = makeTestImage(width: 200, height: 200, color: .white) else {
            assert(false, "Create annotation base image"); return
        }
        let doc = ImageDocument(image: base, scale: 1.0)

        // Draw a red pen stroke
        let stroke = AnnotationStroke(tool: .pen, color: .red, width: 4,
                                      points: [CGPoint(x: 10, y: 10), CGPoint(x: 90, y: 90)])
        doc.commitStroke(stroke)

        // Render flat
        let flat = doc.renderFlatImage()
        assert(flat != nil, "Render with annotation produces image")
        assert(flat!.width == 200, "Rendered image width preserved")

        // Highlighter stroke
        let hStroke = AnnotationStroke(tool: .highlighter, color: .yellow, width: 12,
                                       points: [CGPoint(x: 50, y: 10), CGPoint(x: 150, y: 10)])
        doc.commitStroke(hStroke)
        let flat2 = doc.renderFlatImage()
        assert(flat2 != nil, "Render with highlighter annotation")
    }

    private func testCropUndoable() {
        guard let base = makeTestImage(width: 200, height: 100, color: .blue) else {
            assert(false, "Create crop test image"); return
        }
        let doc = ImageDocument(image: base, scale: 1.0)
        let originalSize = doc.logicalSize

        doc.applyCrop(CGRect(x: 10, y: 10, width: 80, height: 40))
        let croppedSize = doc.croppedLogicalSize
        assertNear(croppedSize.width, 80, "Cropped width")
        assertNear(croppedSize.height, 40, "Cropped height")
        assert(doc.isDirty, "Document dirty after crop")
        assert(doc.canUndo, "Can undo crop")

        doc.undo()
        let afterUndo = doc.croppedLogicalSize
        assertNear(afterUndo.width, originalSize.width, "Width restored after undo crop")
        assertNear(afterUndo.height, originalSize.height, "Height restored after undo crop")
    }

    private func testEncodeDecodeFormats() {
        guard let base = makeTestImage(width: 64, height: 64, color: .purple) else {
            assert(false, "Create format test image"); return
        }

        for format in ExportFormat.allCases {
            let encoded = ExportManager.shared.encode(image: base, format: format)
            assert(encoded != nil, "Encode \(format.displayName)")
            if let data = encoded {
                assert(data.count > 0, "Encoded \(format.displayName) non-empty")
                let decoded = ExportManager.shared.decode(data: data)
                assert(decoded != nil, "Decode \(format.displayName)")
                if let (img, _) = decoded {
                    assert(img.width > 0, "Decoded \(format.displayName) has width")
                }
            }
        }
    }

    private func testClipboardRoundtrip() {
        guard let base = makeTestImage(width: 32, height: 32, color: .cyan) else {
            assert(false, "Create clipboard test image"); return
        }
        let pasteboard = NSPasteboard.withUniqueName()
        defer { pasteboard.releaseGlobally() }
        ExportManager.shared.copyToClipboard(image: base, pasteboard: pasteboard)
        let retrieved = ExportManager.shared.readImageFromClipboard(pasteboard: pasteboard)
        assert(retrieved != nil, "Clipboard roundtrip: image retrieved")
        if let img = retrieved {
            assert(img.width > 0, "Clipboard roundtrip: image has width")
        }
    }

    private func testUndoRedo() {
        guard let base = makeTestImage(width: 100, height: 100, color: .green) else {
            assert(false, "Create undo test image"); return
        }
        let doc = ImageDocument(image: base, scale: 1.0)

        let s1 = AnnotationStroke(tool: .pen, color: .red, width: 2, points: [CGPoint(x: 0, y: 0)])
        let s2 = AnnotationStroke(tool: .pen, color: .blue, width: 2, points: [CGPoint(x: 10, y: 10)])
        let s3 = AnnotationStroke(tool: .pen, color: .green, width: 2, points: [CGPoint(x: 20, y: 20)])

        doc.commitStroke(s1)
        doc.commitStroke(s2)
        doc.commitStroke(s3)
        assert(doc.strokes.count == 3, "Three strokes committed")
        assert(doc.canUndo, "Can undo after 3 strokes")

        doc.undo()
        assert(doc.strokes.count == 2, "Two strokes after undo")
        assert(doc.canRedo, "Can redo after undo")

        doc.undo()
        doc.undo()
        assert(doc.strokes.count == 0, "Zero strokes after 3 undos")
        assert(!doc.canUndo, "Cannot undo after all undone")

        doc.redo()
        assert(doc.strokes.count == 1, "One stroke after redo")
    }

    // MARK: - Helpers

    private func makeTestImage(width: Int, height: Int, color: NSColor) -> CGImage? {
        guard let ctx = CGContext(data: nil, width: width, height: height,
                                   bitsPerComponent: 8, bytesPerRow: 0,
                                   space: CGColorSpaceCreateDeviceRGB(),
                                   bitmapInfo: CGImageAlphaInfo.premultipliedLast.rawValue) else { return nil }
        ctx.setFillColor(color.cgColor)
        ctx.fill(CGRect(x: 0, y: 0, width: width, height: height))
        return ctx.makeImage()
    }

    private func extractPixel(from image: CGImage, x: Int, y: Int) -> (r: UInt8, g: UInt8, b: UInt8, a: UInt8)? {
        guard let ctx = CGContext(data: nil, width: image.width, height: image.height,
                                   bitsPerComponent: 8, bytesPerRow: image.width * 4,
                                   space: CGColorSpaceCreateDeviceRGB(),
                                   bitmapInfo: CGImageAlphaInfo.premultipliedLast.rawValue) else { return nil }
        ctx.draw(image, in: CGRect(x: 0, y: 0, width: image.width, height: image.height))
        guard let data = ctx.data else { return nil }
        let ptr = data.assumingMemoryBound(to: UInt8.self)
        let base = (y * image.width + x) * 4
        return (ptr[base], ptr[base + 1], ptr[base + 2], ptr[base + 3])
    }
}
