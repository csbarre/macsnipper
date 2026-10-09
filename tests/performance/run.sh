#!/usr/bin/env bash
set -euo pipefail
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"
MODE="${1:-canvas}"
case "$MODE" in
    history|erase|canvas) ;;
    *) echo "Usage: bash tests/performance/run.sh [history|erase|canvas]" >&2; exit 2 ;;
esac
TEST_DIR="$(mktemp -d "${TMPDIR:-/tmp}/macsnipper-performance.XXXXXX")"
trap 'rm -rf "$TEST_DIR"' EXIT
swiftc -swift-version 5 -O -framework AppKit -framework ImageIO \
    -framework UniformTypeIdentifiers -framework CoreText \
    "$REPO_ROOT/mac/Sources/ImageDocument.swift" \
    "$REPO_ROOT/mac/Sources/AnnotationEngine.swift" \
    "$REPO_ROOT/mac/Sources/CanvasView.swift" \
    "$REPO_ROOT/mac/Sources/RulerGuideOverlay.swift" \
    "$REPO_ROOT/mac/Sources/Settings.swift" \
    "$REPO_ROOT/mac/Sources/ExportManager.swift" \
    "$SCRIPT_DIR/main.swift" -o "$TEST_DIR/performance"
"$TEST_DIR/performance" "$MODE"
