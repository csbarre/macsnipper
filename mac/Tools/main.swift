import AppKit

let outputDir = CommandLine.arguments.dropFirst().first.flatMap { URL(fileURLWithPath: $0) }
    ?? URL(fileURLWithPath: FileManager.default.currentDirectoryPath)

let app = NSApplication.shared
app.setActivationPolicy(.prohibited)

do {
    try IconGenerator.writeIconSet(to: outputDir)
    print("Icon written to: \(outputDir.appendingPathComponent("AppIcon.icns").path)")
} catch {
    print("Icon generation failed: \(error)")
    exit(1)
}
