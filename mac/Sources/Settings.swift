import Foundation

final class Settings {
    static let shared = Settings()
    private init() {}

    private let defaults = UserDefaults.standard

    var autoCopyToClipboard: Bool {
        get { defaults.bool(forKey: "autoCopyToClipboard") }
        set { defaults.set(newValue, forKey: "autoCopyToClipboard") }
    }

    var warnOnUnsavedChanges: Bool {
        get { defaults.object(forKey: "warnOnUnsavedChanges") as? Bool ?? true }
        set { defaults.set(newValue, forKey: "warnOnUnsavedChanges") }
    }

    var lastCaptureMode: CaptureMode {
        get { CaptureMode(rawValue: defaults.integer(forKey: "lastCaptureMode")) ?? .rectangle }
        set { defaults.set(newValue.rawValue, forKey: "lastCaptureMode") }
    }

    var lastCaptureDelay: CaptureDelay {
        get { CaptureDelay(rawValue: defaults.integer(forKey: "lastCaptureDelay")) ?? .none }
        set { defaults.set(newValue.rawValue, forKey: "lastCaptureDelay") }
    }

    var lastSaveDirectory: URL? {
        get {
            guard let path = defaults.string(forKey: "lastSaveDirectory") else { return nil }
            return URL(fileURLWithPath: path)
        }
        set { defaults.set(newValue?.path, forKey: "lastSaveDirectory") }
    }
}

enum CaptureMode: Int, CaseIterable {
    case rectangle = 0
    case freeform = 1
    case window = 2
    case fullscreen = 3

    var displayName: String {
        switch self {
        case .rectangle: return "Rectangle"
        case .freeform: return "Freeform"
        case .window: return "Window"
        case .fullscreen: return "Full Screen"
        }
    }

    var menuTitle: String { displayName }
}

enum CaptureDelay: Int, CaseIterable {
    case none = 0
    case three = 3
    case ten = 10

    var displayName: String {
        switch self {
        case .none: return "No Delay"
        case .three: return "3 Seconds"
        case .ten: return "10 Seconds"
        }
    }

    var seconds: Int { rawValue }
}
