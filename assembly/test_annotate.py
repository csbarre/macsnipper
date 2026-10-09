import tempfile
import unittest
from pathlib import Path

from annotate import AnnotationError, annotate, annotate_line, main, prepare


class SemanticsTests(unittest.TestCase):
    def test_integer_edges(self):
        cases = [
            ("MOV", ["EAX", "R8D"], "clears the upper 32 bits"),
            ("LEA", ["RCX", "[RAX + 0x8]"], "without reading memory"),
            ("XOR", ["ECX", "ECX"], "Clear ECX to zero"),
            ("CMOVG", ["EAX", "dword ptr [RCX]"], "Read dword ptr [RCX]"),
            ("CMOVG", ["EAX", "dword ptr [RCX]"], "upper 32 bits"),
            ("XADD.LOCK", ["dword ptr [RBX]", "EAX"], "old dword ptr [RBX] in EAX"),
            ("CMPXCHG.LOCK", ["qword ptr [RCX]", "R8"], "RAX"),
            ("CMPXCHG.LOCK", ["dword ptr [RCX]", "R8D"], "EAX"),
            ("DIV", ["ECX"], "EDX:EAX"),
            ("IDIV", ["RBX"], "RDX:RAX"),
            ("SAR", ["RAX", "CL"], "masked with 0x3f"),
            ("SHL", ["EAX", "0x0"], "clears the upper 32 bits"),
            ("SHR", ["EAX", "CL"], "operand bits and flags unchanged"),
            ("BSF", ["EAX", "ECX"], "undefined then."),
            ("BT", ["EAX", "ECX"], "into CF"),
            ("BT", ["RCX", "RAX"], "RAX modulo 64"),
            ("FIDIVR", ["word ptr [RCX]"], "by ST(0)"),
            ("NOP", ["dword ptr [RAX]"], "not read"),
        ]
        for op, args, phrase in cases:
            with self.subTest(op=op, args=args):
                self.assertIn(phrase, annotate(op, args))

    def test_flags_and_float_edges(self):
        cases = [
            ("JA", ["0x10"], "unsigned above"),
            ("JG", ["0x10"], "signed greater"),
            ("JP", ["0x10"], "PF=1"),
            ("UCOMISS", ["XMM0", "XMM1"], "signaling NaNs"),
            ("COMISD", ["XMM0", "XMM1"], "any NaN"),
            ("MOVD", ["XMM0", "EAX"], "zero the remaining upper bits"),
            ("CVTSD2SS", ["XMM0", "XMM1"], "preserve the upper bits"),
            ("PCMPISTRI", ["XMM0", "XMM1", "0xc"], "ECX"),
            ("MOVSB.REP", ["RDI", "RSI"], "+1 if DF=0, -1 if DF=1"),
            ("SFENCE", [], "stores"),
            ("PREFETCHW", ["byte ptr [R9]"], "Hint"),
        ]
        for op, args, phrase in cases:
            with self.subTest(op=op):
                self.assertIn(phrase, annotate(op, args))

    def test_string_strides_and_unprefixed_operations(self):
        cases = [("MOVSB", ["RDI", "RSI"], 1),
                 ("MOVSQ", ["RDI", "RSI"], 8),
                 ("STOSB", ["RDI"], 1),
                 ("STOSW", ["RDI"], 2),
                 ("STOSQ", ["RDI"], 8)]
        for op, args, step in cases:
            with self.subTest(op=op):
                single = annotate(op, args)
                repeated = annotate(op + ".REP", args)
                self.assertIn(f"+{step} if DF=0, -{step} if DF=1", repeated)
                self.assertIn("Repeat RCX times", repeated)
                self.assertIn("decrementing RCX to zero", repeated)
                self.assertNotIn("RCX", single)
                self.assertNotIn("Repeat", single)

    def test_conditional_memory_read_and_call_indirection(self):
        comment = annotate("CMOVZ", ["EAX", "dword ptr [RDX]"])
        self.assertIn("Read dword ptr [RDX] regardless of the condition", comment)
        self.assertIn("upper 32 bits even when the condition is false", comment)
        self.assertNotIn("Read", annotate("CMOVZ", ["RAX", "RDX"]))
        for operand, target in [("0x140001000", "address 0x140001000"),
                                ("RAX", "target address held in RAX"),
                                ("qword ptr [RAX]", "target pointer stored in qword ptr [RAX]")]:
            with self.subTest(operand=operand):
                self.assertIn(target, annotate("CALL", [operand]))

    def test_simd_preservation_and_conversion_edges(self):
        for op in ["MOVSS", "MOVSD"]:
            with self.subTest(op=op):
                self.assertIn("preserving the upper bits", annotate(op, ["XMM0", "XMM1"]))
                self.assertIn("zeroing the upper bits", annotate(op, ["XMM0", "dword ptr [RAX]"]))
        self.assertIn("preserve the upper bits", annotate("CVTSD2SS", ["XMM0", "XMM1"]))
        self.assertIn("MXCSR rounding mode", annotate("CVTSD2SS", ["XMM0", "XMM1"]))
        self.assertIn("round toward zero", annotate("CVTTSS2SI", ["EAX", "XMM0"]))
        self.assertIn("masked invalid conversion", annotate("CVTTSD2SI", ["RAX", "XMM0"]))
        self.assertIn("16 for bytes/8 for words if none", annotate("PCMPISTRI", ["XMM0", "XMM1", "0xc"]))
        self.assertIn("16-byte aligned", annotate("MOVNTPS", ["xmmword ptr [RAX]", "XMM0"]))

    def test_empty_listing_rejected(self):
        with tempfile.TemporaryDirectory() as d:
            path = Path(d) / "empty.asm"
            path.touch()
            with self.assertRaisesRegex(AnnotationError, "empty listing"):
                prepare(path)

    def test_unknown_and_wrong_arity_fail(self):
        for op, args in [("MYSTERY", ["RAX"]), ("MOV", ["RAX"]),
                         ("JZ", []), ("IMUL", ["RAX", "RBX", "RCX", "RDX"])]:
            with self.subTest(op=op):
                with self.assertRaises(AnnotationError):
                    annotate(op, args)

    def test_exact_prefix_newline_and_idempotence(self):
        source = "140001010  488bc4  MOV RAX,RSP\r\n"
        result = annotate_line(source)
        self.assertTrue(result.startswith(source[:-2] + " ; "))
        self.assertTrue(result.endswith("\r\n"))
        self.assertEqual(result, annotate_line(result))
        self.assertEqual(annotate_line("140001010  90  NOP\n").count(" ; "), 1)

    def test_check_does_not_write_and_preparation_is_atomic(self):
        with tempfile.TemporaryDirectory() as d:
            good = Path(d) / "good.asm"
            bad = Path(d) / "bad.asm"
            good.write_text("140001010  90  NOP\n")
            bad.write_text("140001011  ff  BAD RAX\n")
            original = good.read_bytes()
            self.assertEqual(main(["--check", str(good)]), 1)
            self.assertEqual(good.read_bytes(), original)
            with self.assertRaises(AnnotationError):
                main([str(good), str(bad)])
            self.assertEqual(good.read_bytes(), original)
            self.assertEqual(main([str(good)]), 0)
            self.assertEqual(main(["--check", str(good)]), 0)
            self.assertEqual(prepare(good)[0], prepare(good)[1])


if __name__ == "__main__":
    unittest.main()
