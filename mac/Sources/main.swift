import AppKit

// Check for self-test mode before running the app
if CommandLine.arguments.contains("--self-test") {
    // Minimal NSApp init so AppKit drawing works (no event loop, no dock icon)
    let app = NSApplication.shared
    app.setActivationPolicy(.prohibited)
    let passed = SelfTest.run()
    exit(passed ? 0 : 1)
}

// Normal app launch
let app = NSApplication.shared
app.setActivationPolicy(.regular)
let delegate = AppDelegate()
app.delegate = delegate
app.run()
