import AppKit

final class AppDelegate: NSObject, NSApplicationDelegate {

    func applicationDidFinishLaunching(_ notification: Notification) {
        // Register Carbon hotkey
        HotkeyManager.shared.register()

        // Listen for global hotkey
        NotificationCenter.default.addObserver(
            self, selector: #selector(globalHotkeyFired),
            name: .snipGlobalHotkeyPressed, object: nil
        )

        // Show the editor window
        EditorWindowController.shared.showWindow(nil)
        NSApp.activate(ignoringOtherApps: true)

        // Build and install the application menu
        buildMenu()
        DispatchQueue.main.asyncAfter(deadline: .now() + 0.2) {
            let window = EditorWindowController.shared.window!
            window.setContentSize(NSSize(width: 1200, height: 720))
            window.center()

        }
    }

    func application(_ sender: NSApplication, openFiles filenames: [String]) {
        if let path = filenames.first { EditorWindowController.shared.openFile(URL(fileURLWithPath: path)) }
        sender.reply(toOpenOrPrint: .success)
    }

    func applicationShouldTerminate(_ sender: NSApplication) -> NSApplication.TerminateReply {
        EditorWindowController.shared.confirmQuit()
    }

    func applicationWillTerminate(_ notification: Notification) {
        HotkeyManager.shared.unregister()
    }

    func applicationShouldHandleReopen(_ sender: NSApplication, hasVisibleWindows flag: Bool) -> Bool {
        if !flag { EditorWindowController.shared.showWindow(nil) }
        return true
    }

    // MARK: - Global Hotkey

    @objc private func globalHotkeyFired() {
        EditorWindowController.shared.newCapture(nil)
    }

    // MARK: - Menu

    private func buildMenu() {
        let mainMenu = NSMenu()

        // App menu
        let appItem = NSMenuItem()
        mainMenu.addItem(appItem)
        let appMenu = NSMenu()
        appItem.submenu = appMenu
        appMenu.addItem(NSMenuItem(title: "About Snip", action: #selector(NSApplication.orderFrontStandardAboutPanel(_:)), keyEquivalent: ""))
        appMenu.addItem(.separator())
        appMenu.addItem(NSMenuItem(title: "Settings…", action: #selector(EditorWindowController.openSettings(_:)), keyEquivalent: ","))
        appMenu.addItem(.separator())
        appMenu.addItem(NSMenuItem(title: "Quit Snip", action: #selector(NSApplication.terminate(_:)), keyEquivalent: "q"))

        // File menu
        let fileItem = NSMenuItem(title: "File", action: nil, keyEquivalent: "")
        mainMenu.addItem(fileItem)
        let fileMenu = NSMenu(title: "File")
        fileItem.submenu = fileMenu

        let newItem = NSMenuItem(title: "New Snip", action: #selector(EditorWindowController.captureNew(_:)), keyEquivalent: "n")
        newItem.keyEquivalentModifierMask = .command
        fileMenu.addItem(newItem)

        let openItem = NSMenuItem(title: "Open Image…", action: #selector(EditorWindowController.openImage(_:)), keyEquivalent: "o")
        fileMenu.addItem(openItem)

        fileMenu.addItem(.separator())

        let saveItem = NSMenuItem(title: "Save As…", action: #selector(EditorWindowController.saveAs(_:)), keyEquivalent: "s")
        fileMenu.addItem(saveItem)

        fileMenu.addItem(.separator())

        let printItem = NSMenuItem(title: "Print…", action: #selector(EditorWindowController.printDocument(_:)), keyEquivalent: "p")
        fileMenu.addItem(printItem)

        let shareItem = NSMenuItem(title: "Share…", action: #selector(EditorWindowController.shareDocument(_:)), keyEquivalent: "")
        fileMenu.addItem(shareItem)

        // Edit menu
        let editItem = NSMenuItem(title: "Edit", action: nil, keyEquivalent: "")
        mainMenu.addItem(editItem)
        let editMenu = NSMenu(title: "Edit")
        editItem.submenu = editMenu

        let undoItem = NSMenuItem(title: "Undo", action: #selector(EditorWindowController.performUndo(_:)), keyEquivalent: "z")
        editMenu.addItem(undoItem)
        let redoItem = NSMenuItem(title: "Redo", action: #selector(EditorWindowController.performRedo(_:)), keyEquivalent: "z")
        redoItem.keyEquivalentModifierMask = [.command, .shift]
        editMenu.addItem(redoItem)

        editMenu.addItem(.separator())

        let copyItem = NSMenuItem(title: "Copy", action: NSSelectorFromString("copy:"), keyEquivalent: "c")
        editMenu.addItem(copyItem)
        let pasteItem = NSMenuItem(title: "Paste Image", action: NSSelectorFromString("paste:"), keyEquivalent: "v")
        editMenu.addItem(pasteItem)
        editMenu.addItem(NSMenuItem(title: "Select All", action: NSSelectorFromString("selectAll:"), keyEquivalent: "a"))

        // Image menu
        let imageItem = NSMenuItem(title: "Image", action: nil, keyEquivalent: "")
        mainMenu.addItem(imageItem)
        let imageMenu = NSMenu(title: "Image")
        imageItem.submenu = imageMenu

        let cropItem = NSMenuItem(title: "Crop", action: #selector(EditorWindowController.toggleCrop(_:)), keyEquivalent: "k")
        imageMenu.addItem(cropItem)

        imageMenu.addItem(.separator())

        let fitItem = NSMenuItem(title: "Fit to Window", action: #selector(EditorWindowController.fitToWindow(_:)), keyEquivalent: "0")
        fitItem.keyEquivalentModifierMask = [.command, .shift]
        imageMenu.addItem(fitItem)

        let actualItem = NSMenuItem(title: "Actual Size", action: #selector(EditorWindowController.actualSize(_:)), keyEquivalent: "1")
        actualItem.keyEquivalentModifierMask = [.command, .shift]
        imageMenu.addItem(actualItem)

        let zoomInItem = NSMenuItem(title: "Zoom In", action: #selector(EditorWindowController.zoomIn(_:)), keyEquivalent: "+")
        imageMenu.addItem(zoomInItem)

        let zoomOutItem = NSMenuItem(title: "Zoom Out", action: #selector(EditorWindowController.zoomOut(_:)), keyEquivalent: "-")
        imageMenu.addItem(zoomOutItem)

        // Capture menu
        let capItem = NSMenuItem(title: "Capture", action: nil, keyEquivalent: "")
        mainMenu.addItem(capItem)
        let capMenu = NSMenu(title: "Capture")
        capItem.submenu = capMenu

        for mode in CaptureMode.allCases {
            let mi = NSMenuItem(title: mode.menuTitle, action: #selector(EditorWindowController.chooseCaptureMode(_:)), keyEquivalent: "")
            mi.tag = mode.rawValue
            mi.target = EditorWindowController.shared
            capMenu.addItem(mi)
        }

        // Window menu
        let winItem = NSMenuItem(title: "Window", action: nil, keyEquivalent: "")
        mainMenu.addItem(winItem)
        let winMenu = NSMenu(title: "Window")
        winItem.submenu = winMenu
        winMenu.addItem(NSMenuItem(title: "Minimize", action: #selector(NSWindow.miniaturize(_:)), keyEquivalent: "m"))
        winMenu.addItem(NSMenuItem(title: "Zoom", action: #selector(NSWindow.zoom(_:)), keyEquivalent: ""))
        winMenu.addItem(.separator())
        winMenu.addItem(NSMenuItem(title: "Bring All to Front", action: #selector(NSApplication.arrangeInFront(_:)), keyEquivalent: ""))

        NSApp.mainMenu = mainMenu
    }
}
