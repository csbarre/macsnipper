# Snip for Mac

A native macOS screenshot editor - Snip & Sketch style - built with AppKit and ScreenCaptureKit.

## Requirements

- macOS 14 Sonoma or later on Apple silicon (tested on macOS 26, ARM64)
- Xcode Command Line Tools only when building from source; the installed app runs without them
- Screen Recording permission (granted in System Settings → Privacy & Security → Screen Recording)
- No network access required; no telemetry

## Build

```bash
cd mac
bash build.sh
```

The built app is placed in `mac/build/Snip.app`.

## Package (DMG)

```bash
cd mac
bash package.sh
```

The DMG is placed in `dmg/SnipForMac.dmg`.

## Self-Test

The binary includes 86 headless self-tests for geometry, encoding, annotation rendering, undo/redo, toolbar state, and clipboard. They run without screen capture permission:

```bash
mac/build/Snip.app/Contents/MacOS/Snip --self-test
```

Exit code 0 = all tests pass.

Two additional synthetic regression suites can be run from the repository root:

```bash
bash tests/model-regression/run.sh
bash tests/export-regression/run.sh
```

The model suite has 28 checks and the export suite has 71. Together with the built-in tests, the repository has 185 automated checks. They do not replace native UI acceptance.

## Performance Benchmark

Run a synthetic benchmark from the repository root. The default measures canvas drawing; the other modes measure history operations and a no-hit erase pass:

```bash
bash tests/performance/run.sh
bash tests/performance/run.sh history
bash tests/performance/run.sh erase
```

The benchmark prints elapsed times and checks basic resulting state. It uses generated images and annotations and has no timing pass threshold.

## Usage

**Capture modes** (toolbar or Capture menu):
- **Rectangle** - drag to select a region
- **Freeform** - draw any shape; the bounding region is captured and masked
- **Window** - click any on-screen window to capture it
- **Full Screen** - captures all displays and composites them

**Delays**: No delay / 3 seconds / 10 seconds. A visible countdown appears on all screens; press Escape to cancel.

**Global shortcut**: `Cmd+Shift+2` - triggers a new capture from anywhere (registered via Carbon, no Accessibility permission needed).

**Annotation tools**:
- Pen (solid), Pencil (slightly transparent), Highlighter (50% opacity wide strokes)
- Stroke Eraser - removes whole strokes under the eraser path
- Text - click to place text
- Color well - choose any color
- Width stepper - 1–40 px

**Ruler guide** - yellow horizontal line, draggable and rotatable. When active, pen/pencil/highlighter strokes are constrained to lie along the ruler line.

**Protractor guide** - move the center and rotate its handle to measure angles; drawing snaps to the circular guide.

**Crop** - click Crop in the toolbar, drag to select the crop region, then click Crop again (or press ⌘K) to apply. Undoable.

**Undo/Redo** - full undo history for annotation, erase, paste, and crop operations (⌘Z / ⇧⌘Z), preserving operation order.

**Performance and document behavior** - image decoding, rendering, and atomic saves run on a serial background worker. A save uses a document revision snapshot, so edits made while saving remain marked unsaved. Cropping caches pixel data, and canvas redraws use dirty regions over a checkerboard transparency background. Capture mode and delay preferences persist between launches.

**Export**:
- Copy (⌘C) - copies as both PNG and TIFF to the clipboard
- Save As (⌘S) - PNG, JPEG, TIFF, or GIF
- Print (⌘P) - system print panel
- Share - native macOS share picker

**Settings** (⌘,):
- Automatically copy snip to clipboard after capture
- Warn on unsaved changes when closing or starting a new capture

**Cancelled capture**: The previous snip is restored if capture is cancelled.

**Permission denied**: An alert with a direct link to System Settings is shown; the prior image is not lost.

## Architecture

```
mac/
  Sources/
    main.swift                   # Entry point, --self-test dispatch
    AppDelegate.swift            # App lifecycle, menu setup, hotkey wiring
    Settings.swift               # UserDefaults-backed preferences
    HotkeyManager.swift          # Carbon RegisterEventHotKey (⌘⇧2, no Accessibility needed)
    PermissionManager.swift      # Screen capture permission + Settings link
    ImageDocument.swift          # Document model: image, strokes, crop, undo/redo
    AnnotationEngine.swift       # Stroke types, rendering, eraser hit-test, freeform mask
    CaptureManager.swift         # SCScreenshotManager + SCShareableContent (macOS 14+)
    OverlayController.swift      # Full-screen selection overlays for all screens
    CountdownController.swift    # Countdown timer overlay with Escape cancellation
    EditorWindowController.swift # Main editor window, toolbar, all actions
    CanvasView.swift             # NSScrollView + CanvasView: image, annotations, crop overlay
    RulerGuideOverlay.swift      # Movable ruler and protractor guide
    ExportManager.swift          # Clipboard, Save As, Print, Share, Open, encode/decode
    SelfTest.swift               # Headless test suite (geometry, encoding, undo, clipboard)
  Tools/
    IconGenerator.swift          # Build-time AppKit vector scissors icon (no external assets)
```

## Audio and Video

Snip captures still images only. No audio or video recording is performed.

`SCStreamConfiguration.capturesAudio` is explicitly set to `false` in both capture paths (`captureDisplay` and `captureWindow`). Optional audio settings (`capturesAudio`, `sampleRate`, `channelCount`) remain as comments in `CaptureManager.swift` and are inactive.

## Code Signing

By default, `build.sh` signs with `-` (ad-hoc). To use a specific identity, set `SNIP_SIGNING_IDENTITY` before building:

```bash
SNIP_SIGNING_IDENTITY="Developer ID Application: Your Name (TEAMID)" bash build.sh
```

Signing failure aborts the build.

**Ad-hoc rebuild warning**: Ad-hoc signing generates a new cdhash on every rebuild. macOS TCC grants (Screen Recording) are tied to the cdhash of the binary that was granted permission. After each rebuild with ad-hoc signing the cdhash changes and the grant may no longer match. If capture permission is denied after rebuilding, remove and re-grant Screen Recording in System Settings -> Privacy and Security -> Screen Recording.

## Known Limitations

- **Window capture for off-screen/minimised windows**: SCShareableContent only enumerates on-screen windows; minimised windows are not available.
- **Recording**: Not implemented (not requested).
- **Notarization**: Ad-hoc signing only. The default build is not notarized for general distribution.
- **GIF output**: GIF is limited to 256 colours; gradients and photos will show colour banding.
- **Text tool**: Text is placed as a single-line label at the click point. Multi-line and resizable text are not implemented.
- **OCR / smart select**: Not implemented.

## Security and Privacy

- Captures are never sent over the network.
- No telemetry, analytics, or crash reporting.
- Screen Recording privacy permission is requested. The app does not record audio or video.
- Global hotkey uses Carbon's `RegisterEventHotKey` - no Accessibility permission needed.
- Ad-hoc code signing allows local execution without an Apple Developer account.
