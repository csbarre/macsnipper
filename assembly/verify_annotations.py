#!/usr/bin/env python3
"""Verify annotated disassembly against its PE inputs and an optional Git baseline.

This script reads Windows PE files as data. It never loads or executes them.
"""

import argparse
import re
import struct
import subprocess
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parent.parent
NAMES = ("ScreenSketch.exe", "ScreenSketchAppService.dll", "SnippingTool.exe")
LISTING = re.compile(rb"([0-9A-Fa-f]+)  ([0-9A-Fa-f]+)  (.+)\Z")
REFERENCE = re.compile(r"[A-Za-z0-9][A-Za-z0-9._/-]*\Z")


class VerificationError(Exception):
    """A public, content-free verification failure."""


def uint(data, offset, fmt):
    size = struct.calcsize(fmt)
    if offset < 0 or offset + size > len(data):
        raise VerificationError("truncated PE header")
    return struct.unpack_from(fmt, data, offset)[0]


def load_pe(path):
    try:
        data = path.read_bytes()
    except OSError as exc:
        raise VerificationError("missing or unreadable PE input") from exc
    if data[:2] != b"MZ":
        raise VerificationError("missing DOS signature")
    pe = uint(data, 0x3C, "<I")
    if pe + 24 > len(data) or data[pe:pe + 4] != b"PE\0\0":
        raise VerificationError("missing PE signature")
    machine = uint(data, pe + 4, "<H")
    count = uint(data, pe + 6, "<H")
    optional_size = uint(data, pe + 20, "<H")
    optional = pe + 24
    if machine != 0x8664 or optional_size < 64 or uint(data, optional, "<H") != 0x20B:
        raise VerificationError("expected PE32+ AMD64 input")
    if optional + optional_size > len(data) or count == 0:
        raise VerificationError("invalid PE header bounds")
    image_base = uint(data, optional + 24, "<Q")
    image_size = uint(data, optional + 56, "<I")
    header_size = uint(data, optional + 60, "<I")
    if image_size == 0 or header_size > len(data):
        raise VerificationError("invalid PE image size")
    section_table = optional + optional_size
    if section_table + count * 40 > len(data) or section_table + count * 40 > header_size:
        raise VerificationError("truncated PE section table")
    sections = []
    for index in range(count):
        entry = section_table + index * 40
        virtual_size, rva, raw_size, raw_offset = struct.unpack_from("<IIII", data, entry + 8)
        if raw_size and (raw_offset < header_size or raw_offset + raw_size > len(data)):
            raise VerificationError("invalid PE section raw bounds")
        if rva + max(virtual_size, raw_size) > image_size:
            raise VerificationError("invalid PE section image bounds")
        sections.append((rva, virtual_size, raw_offset, raw_size))
    return data, image_base, image_size, sections


def file_offset(address, length, image_base, image_size, sections):
    rva = address - image_base
    if rva < 0 or rva + length > image_size:
        raise VerificationError("instruction outside PE image")
    matches = []
    for section_rva, virtual_size, raw_offset, raw_size in sections:
        delta = rva - section_rva
        if delta >= 0 and delta + length <= virtual_size and delta + length <= raw_size:
            matches.append(raw_offset + delta)
    if len(matches) != 1:
        raise VerificationError("instruction lacks unique raw section mapping")
    return matches[0]


def resolve_baseline(reference):
    if not REFERENCE.fullmatch(reference) or ".." in reference.split("/"):
        raise VerificationError("invalid baseline reference")
    result = subprocess.run(
        ["git", "rev-parse", "--verify", "--quiet", "--end-of-options", reference + "^{commit}"],
        cwd=ROOT, stdout=subprocess.PIPE, stderr=subprocess.DEVNULL, check=False,
    )
    if result.returncode or not re.fullmatch(rb"[0-9a-fA-F]{40,64}\n", result.stdout):
        raise VerificationError("baseline commit unavailable")
    return result.stdout.strip().decode("ascii")


def verify_listing(name, baseline_commit):
    data, image_base, image_size, sections = load_pe(ROOT / "binaries" / name)
    listing_path = ROOT / "assembly" / (name + ".asm")
    try:
        listing = listing_path.open("rb")
    except OSError as exc:
        raise VerificationError("missing or unreadable listing") from exc
    baseline = None
    if baseline_commit:
        baseline = subprocess.Popen(
            ["git", "show", baseline_commit + ":assembly/" + name + ".asm"],
            cwd=ROOT, stdout=subprocess.PIPE, stderr=subprocess.DEVNULL,
        )
    count = 0
    try:
        with listing:
            for count, line in enumerate(listing, 1):
                if not line.endswith(b"\n"):
                    raise VerificationError(f"line {count}: missing line ending")
                body = line[:-1]
                if b" ; " not in body:
                    raise VerificationError(f"line {count}: missing appended comment")
                original, _, comment = body.partition(b" ; ")
                try:
                    comment_text = comment.decode("utf-8")
                except UnicodeDecodeError as exc:
                    raise VerificationError(f"line {count}: invalid comment encoding") from exc
                if not comment_text.strip() or not any(char.isalpha() for char in comment_text):
                    raise VerificationError(f"line {count}: empty explanatory comment")
                if any(ord(char) < 32 or ord(char) == 127 for char in comment_text):
                    raise VerificationError(f"line {count}: invalid comment control character")
                match = LISTING.fullmatch(original)
                if (not match or not match[3].strip() or len(match[1]) > 16
                        or len(match[2]) > 30 or len(match[2]) % 2):
                    raise VerificationError(f"line {count}: malformed instruction")
                address = int(match[1], 16)
                instruction = bytes.fromhex(match[2].decode("ascii"))
                try:
                    offset = file_offset(address, len(instruction), image_base, image_size, sections)
                except VerificationError as exc:
                    raise VerificationError(f"line {count}: {exc}") from exc
                if data[offset:offset + len(instruction)] != instruction:
                    raise VerificationError(f"line {count}: instruction bytes differ from PE input")
                if baseline is not None and baseline.stdout.readline() != original + b"\n":
                    raise VerificationError(f"line {count}: original listing differs from baseline")
        if count == 0:
            raise VerificationError("empty listing")
        if baseline is not None:
            if baseline.stdout.readline():
                raise VerificationError(f"line {count + 1}: baseline has additional instructions")
            if baseline.wait() != 0:
                raise VerificationError("baseline listing unavailable")
    finally:
        if baseline is not None:
            baseline.stdout.close()
            if baseline.poll() is None:
                baseline.kill()
            baseline.wait()
    return count


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--baseline-ref", metavar="REF", help="compare stripped lines with this Git commit")
    args = parser.parse_args()
    try:
        baseline = resolve_baseline(args.baseline_ref) if args.baseline_ref else None
        total = 0
        for name in NAMES:
            try:
                count = verify_listing(name, baseline)
            except VerificationError as exc:
                raise VerificationError(f"{name}.asm: {exc}") from exc
            print(f"{name}.asm: {count} instructions verified")
            total += count
        print(f"PASS: {total} instructions verified across {len(NAMES)} listings")
    except VerificationError as exc:
        # Expected errors are deliberately limited to file names, line numbers, and reasons.
        print(f"FAIL: {exc}", file=sys.stderr)
        return 1
    except OSError:
        print("FAIL: required Git command unavailable", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
