#!/usr/bin/env bash
# package.sh - build Snip.app then create a DMG in dmg/
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
APP="$SCRIPT_DIR/build/Snip.app"
DMG_DIR="$REPO_ROOT/dmg"
DMG_NAME="SnipForMac.dmg"
DMG_PATH="$DMG_DIR/$DMG_NAME"
STAGING="$SCRIPT_DIR/build/dmg_staging"

# Always build first
echo "=== Building app ==="
if [ "${1:-}" != "--no-build" ]; then
    bash "$SCRIPT_DIR/build.sh"
fi

if [ ! -d "$APP" ]; then
    echo "ERROR: $APP not found after build"
    exit 1
fi

echo ""
echo "=== Creating DMG ==="
mkdir -p "$DMG_DIR"
rm -rf "$STAGING"
mkdir -p "$STAGING"

# Copy app into staging
cp -R "$APP" "$STAGING/"

# Symlink to Applications for drag-install
ln -s /Applications "$STAGING/Applications"

# Remove any prior DMG
rm -f "$DMG_PATH"

# Create compressed DMG
hdiutil create \
    -volname "Snip for Mac" \
    -srcfolder "$STAGING" \
    -ov \
    -format UDZO \
    -imagekey zlib-level=9 \
    "$DMG_PATH"

# Cleanup staging
rm -rf "$STAGING"

echo ""
echo "=== DMG Created ==="
echo "Path: $DMG_PATH"
ls -lh "$DMG_PATH"
echo ""
echo "To mount: open \"$DMG_PATH\""
echo "To install: drag Snip.app to Applications from the mounted DMG"
