# macsnipper

A native macOS screenshot and annotation app with a Snip & Sketch style toolbar, built with AppKit and ScreenCaptureKit.

## Features

- Rectangle, freeform, window, and full-screen capture
- Optional capture delay and a Command-Shift-2 shortcut
- Pen, pencil, highlighter, stroke eraser, text, crop, ruler, and protractor
- Undo/redo, clipboard copy, native sharing, printing, and PNG/JPEG/TIFF/GIF export
- Still-image capture only, with audio disabled
- Local processing without network requests or telemetry

## Build and run

Requires an Apple silicon Mac, macOS 14 or later, and Xcode Command Line Tools. Intel builds are not currently supported by the build script.

```bash
bash mac/build.sh
open mac/build/Snip.app
```

The build runs the included self-tests. Grant Screen Recording permission in System Settings when prompted. Ad-hoc signing is used by default; after rebuilding, macOS may require refreshing this permission. The build is not notarized.

```bash
bash tests/model-regression/run.sh
bash tests/export-regression/run.sh
bash mac/package.sh --no-build
```

Packaging creates `dmg/SnipForMac.dmg`. See [the app guide](mac/README.md) for usage, signing options, architecture, and limitations.

## Validation

The current implementation passed 185 automated checks: 86 built-in self-tests, 28 model regression checks, and 71 export regression checks. They cover image orientation, annotation rendering and eraser geometry, clipboard fallback, undo/redo, crop, stable zoom fitting, capture session ownership, asynchronous save revisions, adaptive colors, and format encoding and decoding.

Native UI testing on Apple silicon repeated rectangle capture, window capture, full capture across two displays, delay completion/cancellation, toolbar recovery, annotations and guides, image opening, corrupt-image errors, four-format saving, crop, undo/redo, clipboard replacement, preference persistence, and print-to-PDF. The crop-edge display mismatch found in this loop was fixed and retested. The Share picker was opened without transmitting a capture. No failures remain in the completed checks. Physical shortcut activation, a curved freeform gesture, native color-panel selection, and dragging a selection across display boundaries still require manual acceptance; model tests do not establish those UI inputs. Unusual color profiles and all possible display configurations are not claimed as validated.

## Repository scope

This repository contains the native Mac implementation, synthetic tests, Windows reference inputs, and their static-analysis exports:

- `mac/` contains the native Swift implementation and build tools.
- `tests/` contains synthetic regression checks and performance benchmarks.
- `binaries/` contains the Microsoft Windows reference executables, WinRT metadata, and package manifest.
- `binary/` contains readable `0` and `1` text representations of the three Windows reference programs, preserving every original byte.
- `assembly/` contains disassembly exports from the Windows executables.
- `cpp/` contains Ghidra C-like pseudocode, which is analysis output rather than recovered original C++ or buildable Mac source.
- `dmg/SnipForMac.dmg` contains the packaged native Mac app built from the current Mac source.

Private screenshots, QA logs, local configuration, and intermediate builds remain excluded. The Windows reference files are Microsoft components; the native Mac app is built from `mac/Sources` and uses its own generated icon.

No open-source license has been selected yet.
