#!/usr/bin/env bash
# build.sh - compile Snip for Mac with swiftc (no Xcode required)
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SOURCES_DIR="$SCRIPT_DIR/Sources"
BUILD_DIR="$SCRIPT_DIR/build"
APP_DIR="$BUILD_DIR/Snip.app"
CONTENTS="$APP_DIR/Contents"
MACOS_DIR="$CONTENTS/MacOS"
RESOURCES_DIR="$CONTENTS/Resources"

echo "=== Snip for Mac - Build ==="
echo "Sources: $SOURCES_DIR"
echo "Output:  $APP_DIR"
echo ""

# Verify Swift
if ! command -v swiftc &>/dev/null; then
    echo "ERROR: swiftc not found. Install Xcode Command Line Tools: xcode-select --install"
    exit 1
fi
SWIFT_VER=$(swiftc --version 2>&1 | head -1)
echo "Compiler: $SWIFT_VER"

# SDK
SDK=$(xcrun --sdk macosx --show-sdk-path 2>/dev/null)
if [ -z "$SDK" ]; then
    echo "ERROR: macOS SDK not found. Install Xcode CLT."
    exit 1
fi
echo "SDK:      $SDK"
echo ""

# Create bundle structure
rm -rf "$APP_DIR"
mkdir -p "$MACOS_DIR" "$RESOURCES_DIR"

# Collect sources
SOURCES=("$SOURCES_DIR"/*.swift)
if [ ${#SOURCES[@]} -eq 0 ]; then
    echo "ERROR: No Swift sources found in $SOURCES_DIR"
    exit 1
fi
echo "Sources: ${#SOURCES[@]} files"

# Compile
echo ""
echo "Compiling..."
swiftc \
    -swift-version 5 \
    -target arm64-apple-macos14.0 \
    -sdk "$SDK" \
    -O \
    -framework AppKit \
    -framework ScreenCaptureKit \
    -framework Carbon \
    -framework ImageIO \
    -framework CoreGraphics \
    -framework CoreMedia \
    -framework CoreVideo \
    -framework UniformTypeIdentifiers \
    -framework CoreText \
    "${SOURCES[@]}" \
    -o "$MACOS_DIR/Snip"

echo "Compiled OK"

# Info.plist
cp "$SCRIPT_DIR/Info.plist" "$CONTENTS/Info.plist"
echo "Copied Info.plist"

# Generate icon
echo ""
echo "Generating icon..."
ICON_GENERATOR_SCRIPT="$SCRIPT_DIR/generate_icon.swift"
cat > "$ICON_GENERATOR_SCRIPT" <<'ICONSCRIPT'
import AppKit
import CoreGraphics

let outputDir = CommandLine.arguments.dropFirst().first.flatMap { URL(fileURLWithPath: $0) }
    ?? URL(fileURLWithPath: FileManager.default.currentDirectoryPath)

let app = NSApplication.shared
app.setActivationPolicy(.prohibited)

// ---- draw icon ----
func drawIcon(size s: CGFloat) -> NSImage {
    let image = NSImage(size: NSSize(width: s, height: s))
    image.lockFocus()
    guard let ctx = NSGraphicsContext.current?.cgContext else { image.unlockFocus(); return image }
    let r = s * 0.22
    let bgPath = CGMutablePath()
    bgPath.addRoundedRect(in: CGRect(x: 0, y: 0, width: s, height: s), cornerWidth: r, cornerHeight: r)
    ctx.addPath(bgPath); ctx.clip()
    let cs = CGColorSpaceCreateDeviceRGB()
    let colors: [CGColor] = [
        NSColor(red: 0.10, green: 0.48, blue: 0.98, alpha: 1).cgColor,
        NSColor(red: 0.02, green: 0.28, blue: 0.80, alpha: 1).cgColor
    ]
    if let grad = CGGradient(colorsSpace: cs, colors: colors as CFArray, locations: [0.0, 1.0]) {
        ctx.drawLinearGradient(grad, start: CGPoint(x: s/2, y: s), end: CGPoint(x: s/2, y: 0), options: [])
    }
    ctx.resetClip()
    ctx.setStrokeColor(NSColor.white.withAlphaComponent(0.95).cgColor)
    ctx.setFillColor(NSColor.white.withAlphaComponent(0.95).cgColor)
    ctx.setLineWidth(s * 0.055); ctx.setLineCap(.round); ctx.setLineJoin(.round)
    let cx = s/2, cy = s/2, bladeLen = s*0.28, bladeAngle: CGFloat = 0.38
    ctx.beginPath()
    ctx.move(to: CGPoint(x: cx - bladeLen * cos(bladeAngle), y: cy + bladeLen * sin(bladeAngle)))
    ctx.addLine(to: CGPoint(x: cx + bladeLen * cos(bladeAngle), y: cy - bladeLen * sin(bladeAngle)))
    ctx.strokePath()
    ctx.beginPath()
    ctx.move(to: CGPoint(x: cx + bladeLen * cos(bladeAngle), y: cy + bladeLen * sin(bladeAngle)))
    ctx.addLine(to: CGPoint(x: cx - bladeLen * cos(bladeAngle), y: cy - bladeLen * sin(bladeAngle)))
    ctx.strokePath()
    let hR = s * 0.125, hOff = bladeLen * 0.85
    ctx.setLineWidth(s * 0.04)
    for hc in [CGPoint(x: cx - hOff*cos(bladeAngle)*0.85, y: cy + hOff*sin(bladeAngle)*0.85),
               CGPoint(x: cx + hOff*cos(bladeAngle)*0.85, y: cy + hOff*sin(bladeAngle)*0.85)] {
        ctx.strokeEllipse(in: CGRect(x: hc.x-hR, y: hc.y-hR, width: hR*2, height: hR*2))
    }
    let pR = s * 0.035
    ctx.fillEllipse(in: CGRect(x: cx-pR, y: cy-pR, width: pR*2, height: pR*2))
    image.unlockFocus()
    return image
}

let iconsetURL = outputDir.appendingPathComponent("AppIcon.iconset")
try! FileManager.default.createDirectory(at: iconsetURL, withIntermediateDirectories: true)

let specs: [(Int, Int)] = [(16,1),(16,2),(32,1),(32,2),(128,1),(128,2),(256,1),(256,2),(512,1),(512,2)]
for (pt, sc) in specs {
    let px = pt * sc
    let img = drawIcon(size: CGFloat(px))
    let name = sc == 2 ? "icon_\(pt)x\(pt)@2x.png" : "icon_\(pt)x\(pt).png"
    let url = iconsetURL.appendingPathComponent(name)
    if let tiff = img.tiffRepresentation, let rep = NSBitmapImageRep(data: tiff),
       let png = rep.representation(using: .png, properties: [:]) {
        try! png.write(to: url)
    }
}

let icnsURL = outputDir.appendingPathComponent("AppIcon.icns")
let task = Process()
task.executableURL = URL(fileURLWithPath: "/usr/bin/iconutil")
task.arguments = ["-c", "icns", "-o", icnsURL.path, iconsetURL.path]
try! task.run(); task.waitUntilExit()
if task.terminationStatus != 0 { print("iconutil failed"); exit(1) }
try? FileManager.default.removeItem(at: iconsetURL)
print("Icon written to: \(icnsURL.path)")
ICONSCRIPT

swiftc -O \
    -target arm64-apple-macos14.0 \
    -sdk "$SDK" \
    -framework AppKit \
    -framework CoreGraphics \
    "$ICON_GENERATOR_SCRIPT" \
    -o "$BUILD_DIR/generate_icon_tool" 2>/dev/null || true

if [ -f "$BUILD_DIR/generate_icon_tool" ]; then
    "$BUILD_DIR/generate_icon_tool" "$RESOURCES_DIR" && echo "Icon generated" || echo "Icon generation failed (non-fatal)"
else
    echo "Icon tool compile failed - app will use system default icon (non-fatal)"
fi
rm -f "$ICON_GENERATOR_SCRIPT" "$BUILD_DIR/generate_icon_tool"

# Code sign
# Set SNIP_SIGNING_IDENTITY to a Developer ID or certificate name to sign with that identity.
# Defaults to - (ad-hoc). Ad-hoc signing is local-only; no Apple Developer account needed.
SIGN_IDENTITY="${SNIP_SIGNING_IDENTITY:--}"
echo ""
echo "Signing (identity: $SIGN_IDENTITY)..."
if ! codesign --force --deep --sign "$SIGN_IDENTITY" "$APP_DIR" 2>&1; then
    echo "ERROR: codesign failed"
    exit 1
fi
if [ "$SIGN_IDENTITY" = "-" ]; then
    echo "WARNING: Ad-hoc signing produces a new cdhash on every rebuild. macOS TCC grants tied to"
    echo "         the previous cdhash (Screen Recording) may need to be refreshed after each rebuild."
    echo "         If capture permission is denied after rebuilding, remove and re-grant it in System Settings."
fi
echo ""

# Verify
BINARY="$MACOS_DIR/Snip"
if [ -f "$BINARY" ]; then
    FILEINFO=$(file "$BINARY")
    echo "Binary: $FILEINFO"
    echo ""
    echo "=== BUILD SUCCEEDED ==="
    echo "App: $APP_DIR"
else
    echo "ERROR: Binary not found"
    exit 1
fi

# Run self-test
echo ""
echo "=== Running self-tests ==="
"$BINARY" --self-test
echo "=== Self-tests complete ==="
