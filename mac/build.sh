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

# Generate icon from the single drawing implementation in mac/Tools.
echo ""
echo "Generating icon..."
ICON_TOOL_BINARY="$BUILD_DIR/generate_icon_tool"

swiftc -O \
    -target arm64-apple-macos14.0 \
    -sdk "$SDK" \
    -framework AppKit \
    -framework CoreGraphics \
    "$SCRIPT_DIR/Tools/IconGenerator.swift" \
    "$SCRIPT_DIR/Tools/main.swift" \
    -o "$ICON_TOOL_BINARY"

"$ICON_TOOL_BINARY" "$RESOURCES_DIR"
echo "Icon generated"
rm -f "$ICON_TOOL_BINARY"

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
