import AppKit

// Displays a large countdown on all screens; calls back when done or cancelled.
final class CountdownController {
    private var windows: [NSWindow] = []
    private var seconds: Int
    private var timer: Timer?
    private var remaining: Int
    private var onComplete: (() -> Void)?
    private var onCancel: (() -> Void)?

    init(seconds: Int, onComplete: @escaping () -> Void, onCancel: @escaping () -> Void) {
        self.seconds = seconds
        self.remaining = seconds
        self.onComplete = onComplete
        self.onCancel = onCancel
    }

    func start() {
        createWindows()
        tick()
        timer = Timer.scheduledTimer(withTimeInterval: 1.0, repeats: true) { [weak self] _ in
            self?.tick()
        }
    }

    func cancel() {
        cleanup()
        onCancel?()
        onCancel = nil
    }

    private func tick() {
        if remaining <= 0 {
            cleanup()
            onComplete?()
            onComplete = nil
            return
        }
        updateLabel(remaining)
        remaining -= 1
    }

    private func cleanup() {
        timer?.invalidate()
        timer = nil
        windows.forEach { $0.orderOut(nil) }
        windows.removeAll()
    }

    private func createWindows() {
        for screen in NSScreen.screens {
            let win = CountdownWindow(screen: screen)
            win.onEscape = { [weak self] in self?.cancel() }
            win.makeKeyAndOrderFront(nil)
            windows.append(win)
        }
    }

    private func updateLabel(_ n: Int) {
        for win in windows {
            (win as? CountdownWindow)?.updateCount(n)
        }
    }
}

// MARK: - CountdownWindow

final class CountdownWindow: NSWindow {
    var onEscape: (() -> Void)?
    private let label = NSTextField(labelWithString: "")

    init(screen: NSScreen) {
        let badge = CGRect(x: screen.frame.midX - 150, y: screen.frame.maxY - 110, width: 300, height: 70)
        super.init(contentRect: badge,
                   styleMask: .borderless,
                   backing: .buffered,
                   defer: false)
        isOpaque = false
        backgroundColor = NSColor.windowBackgroundColor
        level = .screenSaver
        collectionBehavior = [.canJoinAllSpaces, .stationary, .ignoresCycle]
        isMovable = false
        ignoresMouseEvents = false
        hasShadow = false

        let v = NSView(frame: CGRect(x: 0, y: 0, width: 300, height: 70))
        v.wantsLayer = true
        contentView = v

        label.font = NSFont.monospacedDigitSystemFont(ofSize: 18, weight: .bold)
        label.textColor = .labelColor
        label.isBezeled = false
        label.drawsBackground = false
        label.alignment = .center
        label.sizeToFit()
        label.autoresizingMask = []
        v.addSubview(label)
        centerLabel()
        let cancel = NSButton(title: "Cancel", target: self, action: #selector(cancelClicked))
        cancel.frame = CGRect(x: 210, y: 20, width: 80, height: 30)
        v.addSubview(cancel)
    }

    @objc private func cancelClicked() { onEscape?() }

    func updateCount(_ n: Int) {
        label.stringValue = "Capture in \(n)s"
        label.sizeToFit()
        centerLabel()
    }

    private func centerLabel() {
        guard let cv = contentView else { return }
        let b = cv.bounds
        label.frame = CGRect(
            x: 20,
            y: (b.height - label.frame.height) / 2,
            width: label.frame.width,
            height: label.frame.height
        )
    }

    override func keyDown(with event: NSEvent) {
        if event.keyCode == 53 { // Escape
            onEscape?()
        } else {
            super.keyDown(with: event)
        }
    }

    override var canBecomeKey: Bool { true }
}
