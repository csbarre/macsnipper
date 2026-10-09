import AppKit
import ScreenCaptureKit

// MARK: - EditorWindowController

final class EditorWindowController: NSWindowController, NSWindowDelegate, NSMenuItemValidation, NSUserInterfaceValidations {
    static let shared = EditorWindowController()

    private var scrollView: CanvasScrollView!
    private var canvasView: CanvasView { scrollView.canvas }
    private var imageDocument: ImageDocument?
    private var quitApproved = false
    private var pendingDocument: ImageDocument?  // preserved while capture overlay is up

    // Toolbar refs
    private var toolbar: NSToolbar!
    private var modeSegmented: NSSegmentedControl!
    private var delayPopup: NSPopUpButton!
    private var toolSegmented: NSSegmentedControl!
    private var colorWell: NSColorWell!
    private var widthStepper: NSStepper!
    private var widthLabel: NSTextField!
    private var undoRedoControl: NSSegmentedControl?
    private var zoomLabel: NSTextField!
    private var guideToggle: NSButton!
    private var protractorToggle: NSButton!
    private var guideMode: GuideMode = .ruler

    // Status bar
    private var statusBar: NSView!
    private var statusLabel: NSTextField!
    private var zoomStatusLabel: NSTextField!

    // Text annotation state
    private var isTextMode = false
    private var pendingTextPoint: CGPoint?

    private init() {
        // Build window
        let minSize = CGSize(width: 720, height: 520)
        let rect = NSRect(x: 100, y: 100, width: 960, height: 680)
        let win = NSWindow(contentRect: rect, styleMask: [.titled, .closable, .miniaturizable, .resizable],
                           backing: .buffered, defer: false)
        win.minSize = minSize
        win.title = "Snip"
        win.toolbarStyle = .expanded
        win.isReleasedWhenClosed = false
        super.init(window: win)
        win.delegate = self

        buildUI()
        setupToolbar()
        setupMenu()
        setupNotifications()
    }
    required init?(coder: NSCoder) { fatalError() }

    // MARK: - UI Setup

    private func buildUI() {
        guard let contentView = window?.contentView else { return }
        contentView.wantsLayer = true
        contentView.widthAnchor.constraint(greaterThanOrEqualToConstant: 1000).isActive = true
        contentView.heightAnchor.constraint(greaterThanOrEqualToConstant: 450).isActive = true

        // Scroll view (main canvas area)
        scrollView = CanvasScrollView(frame: .zero)
        scrollView.translatesAutoresizingMaskIntoConstraints = false
        contentView.addSubview(scrollView)

        // Status bar
        statusBar = NSView()
        statusBar.wantsLayer = true
        statusBar.layer?.backgroundColor = NSColor.windowBackgroundColor.cgColor
        statusBar.translatesAutoresizingMaskIntoConstraints = false
        contentView.addSubview(statusBar)

        let separator = NSBox()
        separator.boxType = .separator
        separator.translatesAutoresizingMaskIntoConstraints = false
        contentView.addSubview(separator)

        statusLabel = NSTextField(labelWithString: "No image")
        statusLabel.font = NSFont.systemFont(ofSize: 11)
        statusLabel.textColor = .secondaryLabelColor
        statusLabel.translatesAutoresizingMaskIntoConstraints = false
        statusBar.addSubview(statusLabel)

        zoomStatusLabel = NSTextField(labelWithString: "100%")
        zoomStatusLabel.font = NSFont.monospacedDigitSystemFont(ofSize: 11, weight: .regular)
        zoomStatusLabel.textColor = .secondaryLabelColor
        zoomStatusLabel.translatesAutoresizingMaskIntoConstraints = false
        statusBar.addSubview(zoomStatusLabel)

        NSLayoutConstraint.activate([
            statusBar.leadingAnchor.constraint(equalTo: contentView.leadingAnchor),
            statusBar.trailingAnchor.constraint(equalTo: contentView.trailingAnchor),
            statusBar.bottomAnchor.constraint(equalTo: contentView.bottomAnchor),
            statusBar.heightAnchor.constraint(equalToConstant: 22),

            separator.leadingAnchor.constraint(equalTo: contentView.leadingAnchor),
            separator.trailingAnchor.constraint(equalTo: contentView.trailingAnchor),
            separator.bottomAnchor.constraint(equalTo: statusBar.topAnchor),
            separator.heightAnchor.constraint(equalToConstant: 1),

            scrollView.topAnchor.constraint(equalTo: contentView.topAnchor),
            scrollView.leadingAnchor.constraint(equalTo: contentView.leadingAnchor),
            scrollView.trailingAnchor.constraint(equalTo: contentView.trailingAnchor),
            scrollView.bottomAnchor.constraint(equalTo: separator.topAnchor),

            statusLabel.leadingAnchor.constraint(equalTo: statusBar.leadingAnchor, constant: 8),
            statusLabel.centerYAnchor.constraint(equalTo: statusBar.centerYAnchor),

            zoomStatusLabel.trailingAnchor.constraint(equalTo: statusBar.trailingAnchor, constant: -8),
            zoomStatusLabel.centerYAnchor.constraint(equalTo: statusBar.centerYAnchor),
        ])

        // Observe scroll view magnification changes
        NotificationCenter.default.addObserver(self,
            selector: #selector(magnificationDidChange(_:)),
            name: NSScrollView.willStartLiveMagnifyNotification,
            object: scrollView)
        scrollView.contentView.postsBoundsChangedNotifications = true
        NotificationCenter.default.addObserver(self,
            selector: #selector(magnificationDidChange(_:)),
            name: NSView.boundsDidChangeNotification,
            object: scrollView.contentView)
    }

    @objc private func magnificationDidChange(_ n: Notification) {
        let pct = Int(scrollView.magnification * 100)
        zoomStatusLabel.stringValue = "\(pct)%"
    }

    // MARK: - Toolbar

    private func setupToolbar() {
        toolbar = NSToolbar(identifier: "SnipToolbar")
        toolbar.delegate = self
        toolbar.allowsUserCustomization = false
        toolbar.displayMode = .iconAndLabel
        window?.toolbar = toolbar
    }

    // MARK: - Notifications

    private func setupNotifications() {
        let nc = NotificationCenter.default
        nc.addObserver(self, selector: #selector(documentChanged(_:)), name: .documentDidChange, object: nil)
        nc.addObserver(self, selector: #selector(captureCompleted(_:)), name: .captureCompleted, object: nil)
        nc.addObserver(self, selector: #selector(captureCancelled(_:)), name: .captureCancelled, object: nil)
        nc.addObserver(self, selector: #selector(capturePermissionDenied(_:)), name: .capturePermissionDenied, object: nil)
    }

    @objc private func documentChanged(_ n: Notification) {
        guard let doc = n.object as? ImageDocument, doc === self.imageDocument else { return }
        updateWindowTitle()
        updateStatusBar()
        undoRedoControl?.setEnabled(doc.canUndo, forSegment: 0)
        undoRedoControl?.setEnabled(doc.canRedo, forSegment: 1)
        canvasView.needsDisplay = true
        DispatchQueue.main.async { [weak self] in self?.updateToolbarState() }
    }

    @objc private func captureCompleted(_ n: Notification) {
        guard let result = n.object as? CaptureResult else { return }
        pendingDocument = nil
        let doc = ImageDocument(image: result.image, scale: result.imageScale)
        doc.markUnsaved()
        loadDocument(doc)
        if Settings.shared.autoCopyToClipboard {
            ExportManager.shared.copyToClipboard(image: result.image)
        }
        showWindow(nil)
        window?.makeKeyAndOrderFront(nil)
        updateToolbarState()
        NSApp.activate(ignoringOtherApps: true)
    }

    @objc private func captureCancelled(_ n: Notification) {
        // Restore prior imageDocument if there was one
        if let pending = pendingDocument {
            imageDocument = pending
            canvasView.document = pending
            pendingDocument = nil
        }
        showWindow(nil)
        window?.makeKeyAndOrderFront(nil)
        updateToolbarState()
        NSApp.activate(ignoringOtherApps: true)
    }

    @objc private func capturePermissionDenied(_ n: Notification) {
        pendingDocument = nil
        showWindow(nil)
        window?.makeKeyAndOrderFront(nil)
        updateToolbarState()
        NSApp.activate(ignoringOtherApps: true)
        PermissionManager.shared.showPermissionDeniedAlert(in: window)
    }

    // MARK: - Document loading

    func openFile(_ url: URL) {
        guard let data = try? Data(contentsOf: url), let (image, scale) = ExportManager.shared.decode(data: data) else { return }
        confirmReplacement { [weak self] in
            let doc = ImageDocument(image: image, scale: scale)
            doc.sourceURL = url
            self?.loadDocument(doc)
            self?.showWindow(nil)
        }
    }

    func loadDocument(_ doc: ImageDocument) {
        imageDocument = doc
        canvasView.document = doc
        canvasView.isCroppingActive = false
        canvasView.cropSelectionRect = nil
        updateWindowTitle()
        updateStatusBar()
        updateToolbarState()

        // Fit to window after layout
        DispatchQueue.main.asyncAfter(deadline: .now() + 0.05) { [weak self] in
            self?.scrollView.fitToWindow()
        }
    }

    private func updateWindowTitle() {
        guard let doc = imageDocument else { window?.title = "Snip"; return }
        let name = doc.saveURL?.lastPathComponent ?? doc.sourceURL?.lastPathComponent ?? "Untitled"
        window?.title = doc.isDirty ? "\(name) - edited" : name
    }

    private func updateStatusBar() {
        guard let doc = imageDocument else { statusLabel.stringValue = "No image"; return }
        let s = doc.croppedLogicalSize
        statusLabel.stringValue = "\(Int(s.width)) × \(Int(s.height)) px  @\(doc.imageScale)x"
    }

    private func updateToolbarState() {
        // These custom views use their own action targets. Keep their enabled
        // state under editor control when AppKit revalidates a restored window.
        for item in toolbar?.items ?? [] {
            let alwaysAvailable = ["captureMode", "captureDelay", "newCapture", "openImage"].contains(item.itemIdentifier.rawValue)
            let enabled = alwaysAvailable || imageDocument != nil
            item.isEnabled = enabled
            if let view = item.view { enableControls(in: view, enabled: enabled) }
        }
        undoRedoControl?.setEnabled(imageDocument?.canUndo ?? false, forSegment: 0)
        undoRedoControl?.setEnabled(imageDocument?.canRedo ?? false, forSegment: 1)
    }

    private func enableControls(in view: NSView, enabled: Bool) {
        (view as? NSControl)?.isEnabled = enabled
        for child in view.subviews { enableControls(in: child, enabled: enabled) }
    }

    func validateUserInterfaceItem(_ item: NSValidatedUserInterfaceItem) -> Bool {
        switch item.action {
        case #selector(saveAs(_:)), #selector(copyImage(_:)), #selector(copy(_:)),
             #selector(printDocument(_:)), #selector(shareDocument(_:)),
             #selector(toggleCrop(_:)), #selector(toggleRuler(_:)), #selector(toggleProtractor(_:)),
             #selector(toolChanged(_:)), #selector(colorChanged(_:)), #selector(widthChanged(_:)):
            return imageDocument != nil
        case #selector(performUndo(_:)): return imageDocument?.canUndo ?? false
        case #selector(performRedo(_:)): return imageDocument?.canRedo ?? false
        default: return true
        }
    }

    func windowDidBecomeKey(_ notification: Notification) { updateToolbarState() }

    // MARK: - Actions

    @objc func newCapture(_ sender: Any?) {
        if let doc = imageDocument, doc.isDirty, Settings.shared.warnOnUnsavedChanges {
            let alert = NSAlert()
            alert.messageText = "Save changes before capturing?"
            alert.informativeText = "Your current snip has unsaved changes."
            alert.addButton(withTitle: "Save")
            alert.addButton(withTitle: "Discard")
            alert.addButton(withTitle: "Cancel")
            guard let win = window else { return }
            alert.beginSheetModal(for: win) { [weak self] resp in
                guard let self = self else { return }
                if resp == .alertFirstButtonReturn {
                    ExportManager.shared.runSaveDialog(for: doc, in: self.window) { saved in
                        if saved { self.startCapture() }
                    }
                } else if resp == .alertSecondButtonReturn {
                    self.startCapture()
                }
                // Cancel: do nothing
            }
        } else {
            startCapture()
        }
    }

    private func startCapture() {
        // Preserve current imageDocument in case capture is cancelled
        pendingDocument = imageDocument
        window?.orderOut(nil)
        let mode = captureMode()
        let delay = captureDelay()

        if #available(macOS 14.0, *) {
            OverlayController.shared.beginCapture(mode: mode, delay: delay) { [weak self] result in
                if result == nil { self?.showWindow(nil); NSApp.activate(ignoringOtherApps: true) }
            }
        }
    }

    private func captureMode() -> CaptureMode {
        let idx = modeSegmented?.selectedSegment ?? 0
        return CaptureMode(rawValue: idx) ?? .rectangle
    }

    private func captureDelay() -> CaptureDelay {
        let secs = delayPopup != nil ? [0, 3, 10][safe: delayPopup.indexOfSelectedItem] ?? 0 : 0
        return CaptureDelay(rawValue: secs) ?? .none
    }

    @objc func openImage(_ sender: Any?) {
        if let doc = imageDocument, doc.isDirty, Settings.shared.warnOnUnsavedChanges {
            let alert = NSAlert()
            alert.messageText = "Save changes?"
            alert.informativeText = "Save current snip before opening a new image?"
            alert.addButton(withTitle: "Save"); alert.addButton(withTitle: "Don't Save"); alert.addButton(withTitle: "Cancel")
            guard let win = window else { return }
            alert.beginSheetModal(for: win) { [weak self] resp in
                guard let self = self else { return }
                if resp == .alertFirstButtonReturn {
                    ExportManager.shared.runSaveDialog(for: doc, in: self.window) { saved in if saved { self.runOpenDialog() } }
                } else if resp == .alertSecondButtonReturn { self.runOpenDialog() }
            }
        } else {
            runOpenDialog()
        }
    }

    private func runOpenDialog() {
        ExportManager.shared.runOpenDialog { [weak self] image, scale, url in
            guard let self = self, let image = image else { return }
            let doc = ImageDocument(image: image, scale: scale)
            doc.sourceURL = url
            self.loadDocument(doc)
        }
    }

    @objc func saveAs(_ sender: Any?) {
        guard let doc = imageDocument else { return }
        ExportManager.shared.runSaveDialog(for: doc, in: window) { _ in }
    }

    @objc func copy(_ sender: Any?) { copyImage(sender) }
    @objc func paste(_ sender: Any?) { pasteImage(sender) }

    @objc func copyImage(_ sender: Any?) {
        guard let doc = imageDocument, let flat = doc.renderFlatImage() else { return }
        ExportManager.shared.copyToClipboard(image: flat)
    }

    @objc func pasteImage(_ sender: Any?) {
        guard let image = ExportManager.shared.readImageFromClipboard() else { return }
        confirmReplacement { [weak self] in
            let doc = ImageDocument(image: image, scale: 1)
            doc.markUnsaved()
            self?.loadDocument(doc)
        }
    }

    func confirmReplacement(_ action: @escaping () -> Void) {
        guard let doc = imageDocument, doc.isDirty, Settings.shared.warnOnUnsavedChanges,
              let window = window else { action(); return }
        let alert = NSAlert()
        alert.messageText = "Save your current snip?"
        alert.addButton(withTitle: "Save")
        alert.addButton(withTitle: "Discard")
        alert.addButton(withTitle: "Cancel")
        alert.beginSheetModal(for: window) { response in
            if response == .alertFirstButtonReturn {
                ExportManager.shared.runSaveDialog(for: doc, in: window) { saved in if saved { action() } }
            } else if response == .alertSecondButtonReturn { action() }
        }
    }

    func confirmQuit() -> NSApplication.TerminateReply {
        guard !quitApproved, let doc = imageDocument, doc.isDirty, Settings.shared.warnOnUnsavedChanges else { return .terminateNow }
        showWindow(nil)
        confirmReplacement { self.quitApproved = true; NSApp.terminate(nil) }
        // Cancel must also end the pending termination. Use a separate synchronous
        // confirmation so the OS quit request always receives a response.
        return .terminateCancel
    }

    @objc func printDocument(_ sender: Any?) {
        guard let doc = imageDocument else { return }
        ExportManager.shared.printDocument(doc, in: window)
    }

    @objc func shareDocument(_ sender: Any?) {
        guard imageDocument != nil else { return }
        if let button = sender as? NSButton {
            ExportManager.shared.showSharePicker(for: imageDocument!, relativeTo: button)
        } else if let view = window?.contentView {
            ExportManager.shared.showSharePicker(for: imageDocument!, relativeTo: view)
        }
    }

    @objc func performUndo(_ sender: Any?) { imageDocument?.undo() }
    @objc func performRedo(_ sender: Any?) { imageDocument?.redo() }

    @objc func fitToWindow(_ sender: Any?) { scrollView.fitToWindow() }
    @objc func zoomIn(_ sender: Any?) { scrollView.magnification = min(scrollView.maxMagnification, scrollView.magnification * 1.25) }
    @objc func zoomOut(_ sender: Any?) { scrollView.magnification = max(scrollView.minMagnification, scrollView.magnification / 1.25) }
    @objc func actualSize(_ sender: Any?) { scrollView.magnification = 1.0 }

    @objc func toolChanged(_ sender: NSSegmentedControl) {
        let tools: [AnnotationTool] = [.pen, .pencil, .highlighter, .eraser, .text]
        let t = tools[safe: sender.selectedSegment] ?? .pen
        canvasView.currentTool = t
        canvasView.isCroppingActive = false
        canvasView.cropSelectionRect = nil
        isTextMode = (t == .text)
    }

    @objc func colorChanged(_ sender: NSColorWell) {
        canvasView.currentColor = sender.color
    }

    @objc func widthChanged(_ sender: NSStepper) {
        canvasView.currentWidth = CGFloat(sender.intValue)
        widthLabel?.stringValue = "\(sender.intValue)px"
    }

    @objc func toggleCrop(_ sender: Any?) {
        if canvasView.isCroppingActive {
            // Apply crop if selection exists
            if let rect = canvasView.cropSelectionRect, rect.width > 2, rect.height > 2 {
                imageDocument?.applyCrop(rect)
                canvasView.document = imageDocument
                DispatchQueue.main.asyncAfter(deadline: .now() + 0.05) { [weak self] in
                    self?.canvasView.needsDisplay = true
                    self?.updateStatusBar()
                }
            }
            canvasView.isCroppingActive = false
            canvasView.cropSelectionRect = nil
        } else {
            canvasView.currentTool = .crop
            canvasView.isCroppingActive = true
        }
        canvasView.needsDisplay = true
    }

    @objc func toggleRuler(_ sender: Any?) {
        guideMode = .ruler
        let isOn = !canvasView.rulerGuide.isActive || canvasView.rulerGuide.mode != .ruler
        canvasView.rulerGuide.mode = .ruler
        canvasView.rulerGuide.isActive = isOn
    }

    @objc func toggleProtractor(_ sender: Any?) {
        guideMode = .protractor
        let isOn = !canvasView.rulerGuide.isActive || canvasView.rulerGuide.mode != .protractor
        canvasView.rulerGuide.mode = .protractor
        canvasView.rulerGuide.isActive = isOn
    }

    @objc func chooseCaptureMode(_ sender: NSMenuItem) {
        modeSegmented.selectedSegment = sender.tag
        newCapture(nil)
    }

    @objc func captureNew(_ sender: Any?) { newCapture(nil) }

    @objc func openSettings(_ sender: Any?) {
        SettingsWindowController.shared.showWindow(nil)
    }

    // MARK: - NSWindowDelegate

    func windowShouldClose(_ sender: NSWindow) -> Bool {
        guard let doc = imageDocument, doc.isDirty, Settings.shared.warnOnUnsavedChanges else { return true }
        let alert = NSAlert()
        alert.messageText = "Save changes to your snip?"
        alert.addButton(withTitle: "Save"); alert.addButton(withTitle: "Don't Save"); alert.addButton(withTitle: "Cancel")
        alert.beginSheetModal(for: sender) { [weak self] resp in
            guard let self = self else { return }
            if resp == .alertFirstButtonReturn {
                ExportManager.shared.runSaveDialog(for: doc, in: self.window) { saved in
                    if saved { self.window?.close() }
                }
            } else if resp == .alertSecondButtonReturn {
                self.window?.close()
            }
        }
        return false
    }

    // MARK: - Menu setup

    private func setupMenu() {
        // Menus are set up in AppDelegate; here we just validate
    }

    func validateMenuItem(_ menuItem: NSMenuItem) -> Bool {
        switch menuItem.action {
        case #selector(saveAs(_:)), #selector(copyImage(_:)), #selector(printDocument(_:)), #selector(shareDocument(_:)):
            return imageDocument != nil
        case #selector(performUndo(_:)):
            return imageDocument?.canUndo ?? false
        case #selector(performRedo(_:)):
            return imageDocument?.canRedo ?? false
        case #selector(toggleCrop(_:)):
            menuItem.title = canvasView.isCroppingActive ? "Apply Crop" : "Crop"
            return imageDocument != nil
        default:
            return true
        }
    }
}

// MARK: - Safe subscript

private extension Array {
    subscript(safe index: Int) -> Element? {
        indices.contains(index) ? self[index] : nil
    }
}

// MARK: - NSToolbarDelegate

extension EditorWindowController: NSToolbarDelegate {
    static let toolbarItems: [NSToolbarItem.Identifier] = [
        .init("captureMode"), .init("captureDelay"), .flexibleSpace,
        .init("newCapture"),
        .init("openImage"),
        .flexibleSpace,
        .init("drawTools"),
        .init("colorWell"),
        .init("strokeWidth"),
        .flexibleSpace,
        .init("cropTool"),
        .init("rulerTool"),
        .init("protractorTool"),
        .flexibleSpace,
        .init("undoRedo"),
        .flexibleSpace,
        .init("copyButton"),
        .init("shareButton"),
        .init("saveButton"),
    ]

    func toolbarDefaultItemIdentifiers(_ toolbar: NSToolbar) -> [NSToolbarItem.Identifier] {
        EditorWindowController.toolbarItems
    }

    func toolbarAllowedItemIdentifiers(_ toolbar: NSToolbar) -> [NSToolbarItem.Identifier] {
        EditorWindowController.toolbarItems + [.flexibleSpace, .space]
    }

    func toolbar(_ toolbar: NSToolbar, itemForItemIdentifier id: NSToolbarItem.Identifier, willBeInsertedIntoToolbar flag: Bool) -> NSToolbarItem? {
        switch id.rawValue {
        case "captureMode":
            let item = NSToolbarItem(itemIdentifier: id)
            item.label = "Mode"
            let seg = NSSegmentedControl(labels: ["Rect", "Free", "Win", "Full"],
                                         trackingMode: .selectOne, target: nil, action: nil)
            seg.selectedSegment = 0
            seg.segmentStyle = .capsule
            seg.controlSize = .small
            modeSegmented = seg
            item.view = seg
            return sized(item)

        case "captureDelay":
            let item = NSToolbarItem(itemIdentifier: id)
            item.label = "Delay"
            let popup = NSPopUpButton(frame: .zero)
            popup.addItem(withTitle: "No Delay")
            popup.addItem(withTitle: "3s")
            popup.addItem(withTitle: "10s")
            popup.controlSize = .small
            delayPopup = popup
            item.view = popup
            return sized(item)

        case "newCapture":
            return makeButton(id: id, label: "New", symbol: "camera.viewfinder", action: #selector(captureNew(_:)), tooltip: "Capture screenshot (⌘⇧2)")

        case "openImage":
            return makeButton(id: id, label: "Open", symbol: "folder", action: #selector(openImage(_:)), tooltip: "Open image file (⌘O)")

        case "drawTools":
            let item = NSToolbarItem(itemIdentifier: id)
            item.label = "Tool"
            let seg = NSSegmentedControl(images: [
                sym("pencil.tip", "Pen"),
                sym("pencil", "Pencil"),
                sym("highlighter", "Highlighter"),
                sym("eraser", "Eraser"),
                sym("character.cursor.ibeam", "Text"),
            ], trackingMode: .selectOne, target: self, action: #selector(toolChanged(_:)))
            seg.selectedSegment = 0
            seg.segmentStyle = .capsule
            toolSegmented = seg
            item.view = seg
            return sized(item)

        case "colorWell":
            let item = NSToolbarItem(itemIdentifier: id)
            item.label = "Color"
            let well = NSColorWell()
            well.color = .systemRed
            well.target = self
            well.action = #selector(colorChanged(_:))
            well.frame = CGRect(x: 0, y: 0, width: 38, height: 28)
            colorWell = well
            item.view = well
            return sized(item)

        case "strokeWidth":
            let item = NSToolbarItem(itemIdentifier: id)
            item.label = "Width"
            let container = NSStackView()
            container.orientation = .horizontal
            container.spacing = 4
            let lbl = NSTextField(labelWithString: "3px")
            lbl.font = NSFont.monospacedDigitSystemFont(ofSize: 11, weight: .regular)
            lbl.frame = CGRect(x: 0, y: 0, width: 36, height: 18)
            widthLabel = lbl
            let stepper = NSStepper()
            stepper.minValue = 1; stepper.maxValue = 40; stepper.intValue = 3
            stepper.target = self; stepper.action = #selector(widthChanged(_:))
            stepper.valueWraps = false
            widthStepper = stepper
            container.addArrangedSubview(lbl)
            container.addArrangedSubview(stepper)
            item.view = container
            return sized(item)

        case "cropTool":
            return makeButton(id: id, label: "Crop", symbol: "crop", action: #selector(toggleCrop(_:)), tooltip: "Crop image (⌘K)")

        case "rulerTool":
            return makeButton(id: id, label: "Ruler", symbol: "ruler", action: #selector(toggleRuler(_:)), tooltip: "Toggle ruler guide")

        case "protractorTool":
            return makeButton(id: id, label: "Angle", symbol: "scope", action: #selector(toggleProtractor(_:)), tooltip: "Toggle protractor guide")

        case "undoRedo":
            let item = NSToolbarItem(itemIdentifier: id)
            item.label = "Undo/Redo"
            let seg = NSSegmentedControl(images: [
                sym("arrow.uturn.backward", "Undo"),
                sym("arrow.uturn.forward", "Redo"),
            ], trackingMode: .momentary, target: self, action: #selector(undoRedoSegment(_:)))
            seg.segmentStyle = .capsule
            item.view = seg
            undoRedoControl = seg
            item.view = seg
            return sized(item)

        case "copyButton":
            return makeButton(id: id, label: "Copy", symbol: "doc.on.clipboard", action: #selector(copyImage(_:)), tooltip: "Copy to clipboard (⌘C)")

        case "shareButton":
            return makeButton(id: id, label: "Share", symbol: "square.and.arrow.up", action: #selector(shareDocument(_:)), tooltip: "Share")

        case "saveButton":
            return makeButton(id: id, label: "Save", symbol: "square.and.arrow.down", action: #selector(saveAs(_:)), tooltip: "Save As… (⌘S)")

        default: return nil
        }
    }

    @objc private func undoRedoSegment(_ sender: NSSegmentedControl) {
        if sender.selectedSegment == 0 { imageDocument?.undo() }
        else { imageDocument?.redo() }
    }

    private func sym(_ name: String, _ desc: String) -> NSImage {
        NSImage(systemSymbolName: name, accessibilityDescription: desc)
            ?? NSImage(systemSymbolName: "circle", accessibilityDescription: desc)!
    }

    private func makeButton(id: NSToolbarItem.Identifier, label: String, symbol: String, action: Selector, tooltip: String) -> NSToolbarItem {
        let item = NSToolbarItem(itemIdentifier: id)
        item.label = label
        let btn = NSButton()
        btn.image = NSImage(systemSymbolName: symbol, accessibilityDescription: label)
        btn.bezelStyle = .texturedRounded
        btn.isBordered = true
        btn.target = self
        btn.action = action
        btn.toolTip = tooltip
        item.view = btn
        return sized(item)
    }

    private func sized(_ item: NSToolbarItem) -> NSToolbarItem {
        let widths: [String: CGFloat] = ["captureMode": 160, "captureDelay": 90, "drawTools": 180, "colorWell": 38, "strokeWidth": 64, "undoRedo": 64]
        let size = NSSize(width: widths[item.itemIdentifier.rawValue] ?? 36, height: 28)
        item.autovalidates = false
        item.view?.frame.size = size
        item.minSize = size
        item.maxSize = size
        return item
    }
}

// MARK: - Settings Window

final class SettingsWindowController: NSWindowController {
    static let shared = SettingsWindowController()

    private init() {
        let win = NSWindow(contentRect: CGRect(x: 0, y: 0, width: 340, height: 180),
                           styleMask: [.titled, .closable], backing: .buffered, defer: false)
        win.title = "Snip Settings"
        win.isReleasedWhenClosed = false
        super.init(window: win)
        buildUI()
    }
    required init?(coder: NSCoder) { fatalError() }

    private func buildUI() {
        guard let cv = window?.contentView else { return }

        let clipCheck = NSButton(checkboxWithTitle: "Automatically copy snip to clipboard", target: self, action: #selector(toggleAutoClip(_:)))
        clipCheck.state = Settings.shared.autoCopyToClipboard ? .on : .off
        clipCheck.translatesAutoresizingMaskIntoConstraints = false
        cv.addSubview(clipCheck)

        let warnCheck = NSButton(checkboxWithTitle: "Warn when closing with unsaved changes", target: self, action: #selector(toggleWarnClose(_:)))
        warnCheck.state = Settings.shared.warnOnUnsavedChanges ? .on : .off
        warnCheck.translatesAutoresizingMaskIntoConstraints = false
        cv.addSubview(warnCheck)

        NSLayoutConstraint.activate([
            clipCheck.topAnchor.constraint(equalTo: cv.topAnchor, constant: 24),
            clipCheck.leadingAnchor.constraint(equalTo: cv.leadingAnchor, constant: 24),
            warnCheck.topAnchor.constraint(equalTo: clipCheck.bottomAnchor, constant: 16),
            warnCheck.leadingAnchor.constraint(equalTo: cv.leadingAnchor, constant: 24),
        ])
    }

    @objc private func toggleAutoClip(_ sender: NSButton) {
        Settings.shared.autoCopyToClipboard = sender.state == .on
    }
    @objc private func toggleWarnClose(_ sender: NSButton) {
        Settings.shared.warnOnUnsavedChanges = sender.state == .on
    }
}
