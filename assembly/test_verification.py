#!/usr/bin/env python3
"""Small, synthetic PE fixtures for the read-only annotation verifier."""

import struct
import subprocess
import tempfile
import unittest
from pathlib import Path
from unittest import mock

from assembly import verify_annotations as verifier


NAME = "sample.exe"
FIRST = b"140001000  90  NOP"
SECOND = b"140001001  c3  RET"
COMMENT = b" ; This instruction has a documented purpose"


def synthetic_pe(section_count=1, raw_size=0x200):
    """Build a minimal PE32+ image containing NOP and RET at RVA 0x1000."""
    image = bytearray(0x400)
    image[:2] = b"MZ"
    struct.pack_into("<I", image, 0x3C, 0x80)
    image[0x80:0x84] = b"PE\0\0"
    struct.pack_into("<H", image, 0x84, 0x8664)
    struct.pack_into("<H", image, 0x86, section_count)
    struct.pack_into("<H", image, 0x94, 0xF0)
    struct.pack_into("<H", image, 0x98, 0x20B)
    struct.pack_into("<Q", image, 0x98 + 24, 0x140000000)
    struct.pack_into("<I", image, 0x98 + 56, 0x2000)
    struct.pack_into("<I", image, 0x98 + 60, 0x200)
    for index in range(section_count):
        entry = 0x188 + index * 40
        image[entry:entry + 8] = b".text\0\0\0"
        struct.pack_into("<IIII", image, entry + 8, 0x100, 0x1000, raw_size, 0x200)
    image[0x200:0x202] = b"\x90\xc3"
    return bytes(image)


class VerificationTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        (self.root / "assembly").mkdir()
        (self.root / "binaries").mkdir()
        (self.root / "binaries" / NAME).write_bytes(synthetic_pe())
        self.listing = self.root / "assembly" / (NAME + ".asm")
        self.write_lines(FIRST + COMMENT, SECOND + COMMENT)
        patcher = mock.patch.object(verifier, "ROOT", self.root)
        patcher.start()
        self.addCleanup(patcher.stop)

    def write_lines(self, *lines):
        self.listing.write_bytes(b"\n".join(lines) + b"\n")

    def verify(self, baseline=None):
        return verifier.verify_listing(NAME, baseline)

    def commit_baseline(self):
        self.write_lines(FIRST, SECOND)
        subprocess.run(["git", "init", "-q", str(self.root)], check=True)
        subprocess.run(["git", "add", "assembly"], cwd=self.root, check=True)
        subprocess.run(
            ["git", "-c", "user.name=Fixture", "-c", "user.email=fixture@example.invalid",
             "-c", "core.hooksPath=/dev/null", "commit", "-qm", "fixture"],
            cwd=self.root, check=True,
        )
        baseline = verifier.resolve_baseline("HEAD")
        self.write_lines(FIRST + COMMENT, SECOND + COMMENT)
        return baseline

    def test_valid_instructions_map_to_raw_pe(self):
        self.assertEqual(self.verify(), 2)

    def test_altered_instruction_bytes_are_rejected(self):
        self.write_lines(b"140001000  cc  INT3" + COMMENT, SECOND + COMMENT)
        with self.assertRaisesRegex(verifier.VerificationError, "line 1: instruction bytes differ"):
            self.verify()

    def test_unmapped_address_is_rejected(self):
        self.write_lines(b"140001300  90  NOP" + COMMENT)
        with self.assertRaisesRegex(verifier.VerificationError, "line 1: instruction lacks unique raw section mapping"):
            self.verify()

    def test_missing_and_empty_comments_are_rejected(self):
        for first in (FIRST, FIRST + b" ; ", FIRST + b" ;    "):
            with self.subTest(first=first):
                self.write_lines(first)
                with self.assertRaisesRegex(verifier.VerificationError, "line 1: (missing appended|empty explanatory) comment"):
                    self.verify()

    def test_truncated_section_raw_data_is_rejected(self):
        (self.root / "binaries" / NAME).write_bytes(synthetic_pe(raw_size=0x300))
        with self.assertRaisesRegex(verifier.VerificationError, "invalid PE section raw bounds"):
            self.verify()

    def test_overlapping_section_mappings_are_rejected(self):
        (self.root / "binaries" / NAME).write_bytes(synthetic_pe(section_count=2))
        with self.assertRaisesRegex(verifier.VerificationError, "line 1: instruction lacks unique raw section mapping"):
            self.verify()

    def test_baseline_accepts_exact_original_lines(self):
        baseline = self.commit_baseline()
        self.assertEqual(self.verify(baseline), 2)

    def test_baseline_rejects_changed_instruction_text(self):
        baseline = self.commit_baseline()
        self.write_lines(b"140001000  90  XCHG EAX,EAX" + COMMENT, SECOND + COMMENT)
        with self.assertRaisesRegex(verifier.VerificationError, "line 1: original listing differs"):
            self.verify(baseline)

    def test_baseline_rejects_reordered_lines(self):
        baseline = self.commit_baseline()
        self.write_lines(SECOND + COMMENT, FIRST + COMMENT)
        with self.assertRaisesRegex(verifier.VerificationError, "line 1: original listing differs"):
            self.verify(baseline)

    def test_baseline_rejects_missing_line(self):
        baseline = self.commit_baseline()
        self.write_lines(FIRST + COMMENT)
        with self.assertRaisesRegex(verifier.VerificationError, "line 2: baseline has additional instructions"):
            self.verify(baseline)

    def test_baseline_rejects_added_line(self):
        baseline = self.commit_baseline()
        self.write_lines(FIRST + COMMENT, SECOND + COMMENT, SECOND + COMMENT)
        with self.assertRaisesRegex(verifier.VerificationError, "line 3: original listing differs"):
            self.verify(baseline)


if __name__ == "__main__":
    unittest.main()
