# Windows reference inputs

This folder contains the Microsoft Windows files used as static-analysis references:

- `SnippingTool.exe`: classic Windows Snipping Tool executable.
- `ScreenSketch.exe` and `ScreenSketchAppService.dll`: native x64 files from Microsoft.ScreenSketch 10.2008.3001.0.
- `ScreenSketch.winmd` and `ScreenSketchAppService.winmd`: Windows Runtime metadata.
- `AppxManifest.xml`: the ScreenSketch package manifest.

The files retain their original bytes and Microsoft ownership. Ghidra exports are in `assembly` and `cpp`. The native Mac app is built from the separate Swift implementation in `mac/Sources`.
