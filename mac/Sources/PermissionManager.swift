import AppKit
import CoreGraphics

final class PermissionManager {
    static let shared = PermissionManager()
    private init() {}

    var hasScreenCapturePermission: Bool {
        CGPreflightScreenCaptureAccess()
    }

    // Request permission; returns whether it was already granted.
    // The system will show its own permission prompt if needed.
    @discardableResult
    func requestScreenCapturePermission() -> Bool {
        if CGPreflightScreenCaptureAccess() { return true }
        CGRequestScreenCaptureAccess()
        return CGPreflightScreenCaptureAccess()
    }

    // Show an actionable alert directing the user to System Settings.
    func showPermissionDeniedAlert(in window: NSWindow?) {
        let alert = NSAlert()
        alert.messageText = "Screen Recording Permission Required"
        alert.informativeText = "Snip needs Screen Recording access to capture screenshots.\n\nGo to System Settings › Privacy & Security › Screen Recording, then enable Snip."
        alert.alertStyle = .warning
        alert.addButton(withTitle: "Open System Settings")
        alert.addButton(withTitle: "Cancel")

        let handler: (NSApplication.ModalResponse) -> Void = { response in
            if response == .alertFirstButtonReturn {
                if let url = URL(string: "x-apple.systempreferences:com.apple.preference.security?Privacy_ScreenCapture") {
                    NSWorkspace.shared.open(url)
                }
            }
        }

        if let window = window {
            alert.beginSheetModal(for: window, completionHandler: handler)
        } else {
            let response = alert.runModal()
            handler(response)
        }
    }
}
