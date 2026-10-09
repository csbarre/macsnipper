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

The current implementation passed 80 built-in checks, 10 independent model checks, and 52 export regression checks. These cover image orientation, annotation rendering, eraser geometry, clipboard fallback, undo/redo, crop, stable zoom fitting, and capture session ownership.

Native UI testing on Apple silicon verified repeated rectangle captures, window capture, full capture across two displays, delay completion/cancellation, toolbar recovery, annotation and guides, image opening, corrupt-image errors, saving, crop, undo/redo, and print-to-PDF. The Share picker was exercised without transmitting a capture. Physical shortcut activation, a curved freeform gesture, native color-panel selection, and dragging a selection across display boundaries still need manual acceptance; automated geometry tests do not replace those checks. Unusual color profiles and all possible display configurations are not claimed as validated.

## Repository scope

This repository contains the native Mac implementation and synthetic tests. Original Windows binaries, decompiler outputs, private screenshots, logs, local machine configuration, and generated application packages are excluded. No Microsoft binaries or assets are distributed here.

No open-source license has been selected yet.
