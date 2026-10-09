#!/usr/bin/env python3
"""Export the three Windows reference programs as readable binary digits."""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
OUTPUT = ROOT / "binary"
FILES = (
    ("ScreenSketch.exe", "ScreenSketch.bits.txt"),
    ("ScreenSketchAppService.dll", "ScreenSketchAppService.bits.txt"),
    ("SnippingTool.exe", "SnippingTool.bits.txt"),
)
BITS = tuple(format(value, "08b") for value in range(256))


def encoded_lines(source: Path):
    """Preserve byte order; write each byte with its most significant bit first."""
    with source.open("rb") as stream:
        while block := stream.read(16):
            yield (" ".join(BITS[value] for value in block) + "\n").encode("ascii")


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        while block := stream.read(1024 * 1024):
            digest.update(block)
    return digest.hexdigest()


def export(source: Path, target: Path, check: bool) -> None:
    if check:
        with target.open("rb") as stream:
            for number, expected in enumerate(encoded_lines(source), 1):
                if stream.readline() != expected:
                    raise ValueError(f"{target.name}: incorrect bits or formatting at line {number}")
            if stream.read(1):
                raise ValueError(f"{target.name}: extra data after the last source byte")
        return
    temporary = None
    try:
        with tempfile.NamedTemporaryFile(dir=target.parent, delete=False) as stream:
            temporary = Path(stream.name)
            for line in encoded_lines(source):
                stream.write(line)
        os.chmod(temporary, 0o644)
        os.replace(temporary, target)
    finally:
        if temporary is not None:
            temporary.unlink(missing_ok=True)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true", help="verify existing exports without writing")
    options = parser.parse_args()
    if not options.check:
        OUTPUT.mkdir(exist_ok=True)
    records = []
    for source_name, target_name in FILES:
        source = ROOT / "binaries" / source_name
        target = OUTPUT / target_name
        export(source, target, options.check)
        records.append({
            "source": f"binaries/{source_name}",
            "text": f"binary/{target_name}",
            "source_bytes": source.stat().st_size,
            "bit_count": source.stat().st_size * 8,
            "source_sha256": sha256(source),
            "text_sha256": sha256(target),
        })
        print(f"{target_name}: {source.stat().st_size:,} bytes {'verified' if options.check else 'exported'}")
    manifest = {
        "format": {"bits_per_byte": 8, "bytes_per_line": 16,
                   "bit_order": "MSB first", "byte_order": "unchanged",
                   "separator": "space", "line_ending": "LF"},
        "files": records,
    }
    content = json.dumps(manifest, indent=2) + "\n"
    manifest_path = OUTPUT / "manifest.json"
    if options.check:
        if manifest_path.read_bytes() != content.encode("utf-8"):
            raise ValueError("manifest.json: stale or incorrect export metadata")
    else:
        manifest_path.write_text(content, encoding="utf-8")


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError) as error:
        raise SystemExit(f"error: {error}") from error
