#!/usr/bin/env bash
set -euo pipefail
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"
TEST_DIR="$(mktemp -d "${TMPDIR:-/tmp}/macsnipper-export-tests.XXXXXX")"
trap 'rm -rf "$TEST_DIR"' EXIT
swiftc -swift-version 5 -framework AppKit -framework ImageIO \
    -framework UniformTypeIdentifiers -framework CoreText \
    "$REPO_ROOT/mac/Sources/ImageDocument.swift" \
    "$REPO_ROOT/mac/Sources/AnnotationEngine.swift" \
    "$REPO_ROOT/mac/Sources/ExportManager.swift" \
    "$REPO_ROOT/mac/Sources/Settings.swift" \
    "$SCRIPT_DIR/main.swift" -o "$TEST_DIR/export-regression"
"$TEST_DIR/export-regression"
