import AppKit
import Carbon
import os

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
    private let logger = Logger(subsystem: Bundle.main.bundleIdentifier ?? "local.macsnipper.snip", category: "Hotkey")
    private(set) var registrationStatus: OSStatus?

    // Register Cmd+Shift+2
    func register() {
        unregister()
        // kVK_ANSI_2 = 0x13
        let keyCode: UInt32 = 0x13
        let modifiers: UInt32 = UInt32(cmdKey) | UInt32(shiftKey)

        let hotKeyID = EventHotKeyID(signature: OSType(0x534E4950), id: 1) // "SNIP"
        let status = RegisterEventHotKey(keyCode, modifiers, hotKeyID, GetApplicationEventTarget(), 0, &hotKeyRef)
        registrationStatus = status
        if status != noErr {
            logger.error("RegisterEventHotKey failed: \(status, privacy: .public)")
            return
        }

        var eventSpec = EventTypeSpec(eventClass: OSType(kEventClassKeyboard),
                                      eventKind: UInt32(kEventHotKeyPressed))
        let handlerStatus = InstallEventHandler(GetApplicationEventTarget(), hotKeyEventHandler, 1, &eventSpec, nil, &handlerRef)
        registrationStatus = handlerStatus
        guard handlerStatus == noErr else {
            unregister()
            logger.error("InstallEventHandler failed: \(handlerStatus, privacy: .public)")
            return
        }
        logger.notice("Registered Cmd+Shift+2 successfully")
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
