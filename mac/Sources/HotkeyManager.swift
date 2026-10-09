import AppKit
import Carbon

// Global C-compatible handler - cannot capture context
private func hotKeyEventHandler(
    _ nextHandler: EventHandlerCallRef?,
    _ event: EventRef?,
    _ userData: UnsafeMutableRawPointer?
) -> OSStatus {
    DispatchQueue.main.async {
        NotificationCenter.default.post(name: .snipGlobalHotkeyPressed, object: nil)
    }
    return noErr
}

final class HotkeyManager {
    static let shared = HotkeyManager()
    private init() {}

    private var hotKeyRef: EventHotKeyRef?
    private var handlerRef: EventHandlerRef?

    // Register Cmd+Shift+2
    func register() {
        // kVK_ANSI_2 = 0x13
        let keyCode: UInt32 = 0x13
        let modifiers: UInt32 = UInt32(cmdKey) | UInt32(shiftKey)

        let hotKeyID = EventHotKeyID(signature: OSType(0x534E4950), id: 1) // "SNIP"
        let status = RegisterEventHotKey(keyCode, modifiers, hotKeyID, GetApplicationEventTarget(), 0, &hotKeyRef)
        if status != noErr {
            print("[HotkeyManager] RegisterEventHotKey failed: \(status)")
            return
        }

        var eventSpec = EventTypeSpec(eventClass: OSType(kEventClassKeyboard),
                                      eventKind: UInt32(kEventHotKeyPressed))
        InstallEventHandler(GetApplicationEventTarget(), hotKeyEventHandler, 1, &eventSpec, nil, &handlerRef)
        print("[HotkeyManager] Registered Cmd+Shift+2")
    }

    func unregister() {
        if let ref = hotKeyRef {
            UnregisterEventHotKey(ref)
            hotKeyRef = nil
        }
        if let handler = handlerRef {
            RemoveEventHandler(handler)
            handlerRef = nil
        }
    }
}
