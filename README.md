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
bash mac/package.sh --no-build
```

Packaging creates `dmg/SnipForMac.dmg`. See [the app guide](mac/README.md) for usage, signing options, architecture, and limitations.

## Validation

The current implementation passed 60 built-in checks and 10 independent model checks. Manual testing verified consecutive rectangle captures, toolbar recovery, annotation, image opening, saving, crop, and undo/redo on Apple silicon. Other capture modes and all display configurations have not received complete manual validation.

## Repository scope

This repository contains the native Mac implementation and synthetic tests. Original Windows binaries, decompiler outputs, private screenshots, logs, local machine configuration, and generated application packages are excluded. No Microsoft binaries or assets are distributed here.

No open-source license has been selected yet.
