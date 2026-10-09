# Windows programs as 0 and 1 text

These files show the complete original Windows program files as readable binary digits. Each group of eight digits represents one byte, with the most significant bit on the left. There are 16 byte groups per line, separated by spaces, in the same order as the source file. The text contains only bit groups, spaces, and line breaks.

| Text file | Original file |
| --- | --- |
| `ScreenSketch.bits.txt` | `binaries/ScreenSketch.exe` |
| `ScreenSketchAppService.bits.txt` | `binaries/ScreenSketchAppService.dll` |
| `SnippingTool.bits.txt` | `binaries/SnippingTool.exe` |

For example, the initial `MZ` bytes of a Windows executable appear as `01001101 01011010`. This representation includes the entire file: headers, machine instructions, resources, data, and signatures. For instruction explanations, use the annotated listings in `assembly/`.

The text is about nine times larger than the original files because every byte takes eight digits and a separator. It retains the original Microsoft program contents and ownership. The native Mac implementation remains in `mac/Sources`.

## Regenerate and verify

Run from the repository root with Python 3:

```bash
python3 binary/export_bits.py
python3 binary/export_bits.py --check
```

The check compares every exported group with its original source byte and validates the exact formatting. `manifest.json` records source byte counts, bit counts, and SHA-256 hashes for both the original files and text exports. Decoding each eight-digit group as a base-2 byte reproduces its source file exactly.
