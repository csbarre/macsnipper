import AppKit
import CoreGraphics

// Generates the Snip app icon as vector AppKit drawing (no external assets).
// Returns a set of square CGImages at standard icon sizes.
final class IconGenerator {

    static let sizes: [Int] = [16, 32, 64, 128, 256, 512, 1024]

    static func generate(size: Int) -> NSImage {
        let s = CGFloat(size)
        let image = NSImage(size: NSSize(width: s, height: s))
        image.lockFocus()
        drawIcon(size: s)
        image.unlockFocus()
        return image
    }

    private static func drawIcon(size s: CGFloat) {
        guard let ctx = NSGraphicsContext.current?.cgContext else { return }
        ctx.saveGState()
        defer { ctx.restoreGState() }

        let r = s * 0.22

        // Background: blue rounded rect with slight gradient
        let bgRect = CGRect(x: 0, y: 0, width: s, height: s)
        let bgPath = CGMutablePath()
        bgPath.addRoundedRect(in: bgRect, cornerWidth: r, cornerHeight: r)

        // Draw gradient background
        ctx.addPath(bgPath)
        ctx.clip()
        let colorSpace = CGColorSpaceCreateDeviceRGB()
        let colors = [
            NSColor(red: 0.10, green: 0.48, blue: 0.98, alpha: 1).cgColor,
            NSColor(red: 0.02, green: 0.28, blue: 0.80, alpha: 1).cgColor
        ]
        if let gradient = CGGradient(colorsSpace: colorSpace, colors: colors as CFArray, locations: [0.0, 1.0]) {
            ctx.drawLinearGradient(gradient, start: CGPoint(x: s * 0.5, y: s), end: CGPoint(x: s * 0.5, y: 0), options: [])
        }

        // White scissors icon
        ctx.resetClip()
        ctx.setStrokeColor(NSColor.white.withAlphaComponent(0.95).cgColor)
        ctx.setFillColor(NSColor.white.withAlphaComponent(0.95).cgColor)
        ctx.setLineWidth(s * 0.055)
        ctx.setLineCap(.round)
        ctx.setLineJoin(.round)

        let cx = s / 2
        let cy = s / 2
        let bladeLen = s * 0.28
        let bladeAngle: CGFloat = 0.38  // radians

        // Left blade
        ctx.beginPath()
        ctx.move(to: CGPoint(x: cx - bladeLen * cos(bladeAngle), y: cy + bladeLen * sin(bladeAngle)))
        ctx.addLine(to: CGPoint(x: cx + bladeLen * cos(bladeAngle), y: cy - bladeLen * sin(bladeAngle)))
        ctx.strokePath()

        // Right blade (mirror)
        ctx.beginPath()
        ctx.move(to: CGPoint(x: cx + bladeLen * cos(bladeAngle), y: cy + bladeLen * sin(bladeAngle)))
        ctx.addLine(to: CGPoint(x: cx - bladeLen * cos(bladeAngle), y: cy - bladeLen * sin(bladeAngle)))
        ctx.strokePath()

        // Handles (open circles at the top of each blade)
        let handleRadius = s * 0.125
        let handleOffset = bladeLen * 0.85
        let handle1 = CGPoint(x: cx - handleOffset * cos(bladeAngle) * 0.85,
                              y: cy + handleOffset * sin(bladeAngle) * 0.85)
        let handle2 = CGPoint(x: cx + handleOffset * cos(bladeAngle) * 0.85,
                              y: cy + handleOffset * sin(bladeAngle) * 0.85)

        ctx.setLineWidth(s * 0.04)
        for hc in [handle1, handle2] {
            ctx.strokeEllipse(in: CGRect(x: hc.x - handleRadius, y: hc.y - handleRadius,
                                         width: handleRadius * 2, height: handleRadius * 2))
        }

        // Pivot dot
        ctx.setFillColor(NSColor.white.withAlphaComponent(0.95).cgColor)
        let pivotR = s * 0.035
        ctx.fillEllipse(in: CGRect(x: cx - pivotR, y: cy - pivotR, width: pivotR * 2, height: pivotR * 2))
    }

    // MARK: - Write ICNS

    static func writeIconSet(to directory: URL) throws {
        let iconsetURL = directory.appendingPathComponent("AppIcon.iconset")
        try FileManager.default.createDirectory(at: iconsetURL, withIntermediateDirectories: true)

        let specs: [(Int, Int)] = [
            (16, 1), (16, 2), (32, 1), (32, 2),
            (128, 1), (128, 2), (256, 1), (256, 2),
            (512, 1), (512, 2)
        ]

        for (ptSize, scale) in specs {
            let pixelSize = ptSize * scale
            let image = generate(size: pixelSize)
            let name = scale == 2 ? "icon_\(ptSize)x\(ptSize)@2x.png" : "icon_\(ptSize)x\(ptSize).png"
            let destURL = iconsetURL.appendingPathComponent(name)

            if let tiff = image.tiffRepresentation,
               let rep = NSBitmapImageRep(data: tiff),
               let pngData = rep.representation(using: .png, properties: [:]) {
                try pngData.write(to: destURL)
            }
        }

        // Convert to ICNS using iconutil
        let icnsURL = directory.appendingPathComponent("AppIcon.icns")
        let task = Process()
        task.executableURL = URL(fileURLWithPath: "/usr/bin/iconutil")
        task.arguments = ["-c", "icns", "-o", icnsURL.path, iconsetURL.path]
        try task.run()
        task.waitUntilExit()

        if task.terminationStatus != 0 {
            throw NSError(domain: "IconGenerator", code: Int(task.terminationStatus),
                          userInfo: [NSLocalizedDescriptionKey: "iconutil failed"])
        }

        // Cleanup iconset
        try? FileManager.default.removeItem(at: iconsetURL)
    }
}
