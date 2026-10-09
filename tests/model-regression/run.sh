#!/usr/bin/env bash
set -euo pipefail
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"
TEST_DIR="$(mktemp -d "${TMPDIR:-/tmp}/macsnipper-tests.XXXXXX")"
trap 'rm -rf "$TEST_DIR"' EXIT
swiftc -swift-version 5 -framework AppKit \
    "$REPO_ROOT/mac/Sources/ImageDocument.swift" \
    "$REPO_ROOT/mac/Sources/AnnotationEngine.swift" \
    "$SCRIPT_DIR/main.swift" -o "$TEST_DIR/model-regression"
"$TEST_DIR/model-regression"
