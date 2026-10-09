#!/usr/bin/env python3
"""Deterministic, deliberately strict descriptions of the listed x86-64 instructions."""
from __future__ import annotations

import argparse
import os
import re
import tempfile
from pathlib import Path

LINE = re.compile(r"^([0-9a-fA-F]+  [0-9a-fA-F]+  )([A-Z0-9.]+)(?: (.*?))?(\r?\n|$)")
MEM = re.compile(r"(?:byte|word|dword|qword|xmmword) ptr \[|\[")
GPR32 = re.compile(r"^(?:E(?:AX|BX|CX|DX|SI|DI|BP|SP)|R(?:[89]|1[0-5])D)$")
XMM = re.compile(r"^XMM\d+$")
WIDTH = {"byte": "8-bit", "word": "16-bit", "dword": "32-bit", "qword": "64-bit", "xmmword": "128-bit"}
PRED = {
    "A": "unsigned above (CF=0 and ZF=0)", "BE": "unsigned below or equal (CF=1 or ZF=1)",
    "C": "carry/unsigned below (CF=1)", "NC": "no carry/unsigned at least (CF=0)",
    "G": "signed greater (ZF=0 and SF=OF)", "GE": "signed greater or equal (SF=OF)",
    "L": "signed less (SF differs from OF)", "LE": "signed less or equal (ZF=1 or SF differs from OF)",
    "Z": "equal/zero (ZF=1)", "NZ": "not equal/nonzero (ZF=0)",
    "S": "negative/sign (SF=1)", "NS": "nonnegative/no sign (SF=0)",
    "O": "overflow (OF=1)", "NO": "no overflow (OF=0)",
    "P": "parity/even low-byte parity (PF=1)",
}
ARITH = {"ADD": "Add", "SUB": "Subtract", "AND": "Bitwise AND", "OR": "Bitwise OR",
         "XOR": "Bitwise XOR", "SBB": "Subtract with borrow"}
SIMD_ARITH = {"ADD": "Add", "SUB": "Subtract", "MUL": "Multiply", "DIV": "Divide"}
MOVE_PACKED = {"MOVAPS": "aligned packed single-precision", "MOVAPD": "aligned packed double-precision",
               "MOVUPS": "unaligned packed single-precision", "MOVDQA": "aligned 128-bit integer",
               "MOVDQU": "unaligned 128-bit integer"}
SCALAR = {"SS": "low 32-bit single-precision", "SD": "low 64-bit double-precision"}


class AnnotationError(ValueError):
    pass


def split_operands(raw: str) -> list[str]:
    # These listings contain no commas inside bracketed addresses.
    out = [x.strip() for x in raw.split(",")] if raw else []
    if any(not x for x in out):
        raise AnnotationError(f"empty operand: {raw!r}")
    return out


def has_memory(x: str) -> bool:
    return bool(MEM.search(x))


def width(x: str) -> str:
    m = re.search(r"\b(byte|word|dword|qword|xmmword) ptr\b", x)
    if m:
        return WIDTH[m.group(1)]
    if GPR32.fullmatch(x):
        return "32-bit"
    if re.fullmatch(r"R(?:AX|BX|CX|DX|SI|DI|BP|SP|[89]|1[0-5])", x):
        return "64-bit"
    if XMM.fullmatch(x):
        return "128-bit"
    if re.fullmatch(r"(?:[ABCD][HL]|(?:SIL|DIL|BPL|SPL)|R(?:[89]|1[0-5])B)", x):
        return "8-bit"
    if re.fullmatch(r"(?:AX|BX|CX|DX|SI|DI|BP|SP|R(?:[89]|1[0-5])W)", x):
        return "16-bit"
    return "operand-width"


def gpr32_note(dst: str) -> str:
    return "; clears the upper 32 bits of its 64-bit register" if GPR32.fullmatch(dst) else ""


def annotate(op: str, args: list[str]) -> str:
    locked = op.endswith(".LOCK")
    repeated = op.endswith(".REP")
    base = op.removesuffix(".LOCK").removesuffix(".REP")
    if locked and base not in {"ADD", "AND", "CMPXCHG", "DEC", "INC", "OR", "XADD"}:
        raise AnnotationError(f"invalid LOCK form {op}")
    if repeated and base not in {"MOVSB", "MOVSQ", "STOSB", "STOSW", "STOSQ"}:
        raise AnnotationError(f"invalid REP form {op}")
    arities = {
        "CPUID": 0, "XGETBV": 0, "CDQ": 0, "CDQE": 0, "CQO": 0,
        "INT3": 0, "LFENCE": 0, "SFENCE": 0,
        "MOVSB": 2, "MOVSQ": 2, "STOSB": 1, "STOSW": 1, "STOSQ": 1,
        "PUSH": 1, "POP": 1, "CALL": 1, "JMP": 1, "INT": 1,
        "DIV": 1, "IDIV": 1, "MUL": 1, "NEG": 1, "NOT": 1,
        "INC": 1, "DEC": 1, "FIDIVR": 1, "FNSTCW": 1, "PREFETCHW": 1,
        "BSF": 2, "BSR": 2, "BT": 2, "BTR": 2, "BTS": 2,
        "LEA": 2, "MOV": 2, "MOVSX": 2, "MOVSXD": 2, "MOVZX": 2,
        "XADD": 2, "XCHG": 2, "CMPXCHG": 2,
        "CMP": 2, "TEST": 2, "ADD": 2, "SUB": 2, "AND": 2,
        "OR": 2, "XOR": 2, "SBB": 2, "ROL": 2, "ROR": 2,
        "SAR": 2, "SHL": 2, "SHR": 2,
        "MOVAPS": 2, "MOVAPD": 2, "MOVUPS": 2, "MOVDQA": 2,
        "MOVDQU": 2, "MOVNTPS": 2, "MOVD": 2, "MOVQ": 2,
        "MOVSD": 2, "MOVSS": 2, "ANDPS": 2, "XORPS": 2,
        "POR": 2, "PCMPEQB": 2, "PMOVMSKB": 2, "PSRLDQ": 2,
        "PUNPCKLBW": 2, "UNPCKLPD": 2, "UNPCKLPS": 2,
        "CVTDQ2PD": 2, "CVTDQ2PS": 2, "CVTPD2PS": 2,
        "CVTPS2PD": 2, "CVTSD2SS": 2, "CVTSI2SD": 2,
        "CVTSI2SS": 2, "CVTSS2SD": 2, "CVTTSD2SI": 2,
        "CVTTSS2SI": 2, "COMISD": 2, "COMISS": 2,
        "UCOMISD": 2, "UCOMISS": 2,
        "ADDSD": 2, "ADDSS": 2, "SUBSD": 2, "SUBSS": 2,
        "MULSD": 2, "MULSS": 2, "DIVSD": 2, "DIVSS": 2,
        "MAXSD": 2, "MAXSS": 2, "MINSD": 2, "MINSS": 2,
        "PCMPISTRI": 3, "PINSRB": 3, "PSHUFD": 3,
        "PSHUFLW": 3, "SHUFPS": 3,
    }
    if base in {"RET", "NOP"}:
        if len(args) not in (0, 1):
            raise AnnotationError(f"{op} expects zero or one operand; got {len(args)}")
    elif base == "IMUL":
        if len(args) not in (1, 2, 3):
            raise AnnotationError(f"{op} expects 1, 2, or 3 operands; got {len(args)}")
    elif base.startswith("J") and base != "JMP":
        if base[1:] not in PRED:
            raise AnnotationError(f"unknown branch {op}")
        arities[base] = 1
    elif base.startswith("CMOV"):
        if base[4:] not in PRED:
            raise AnnotationError(f"unknown conditional move {op}")
        arities[base] = 2
    elif base.startswith("SET"):
        if base[3:] not in PRED:
            raise AnnotationError(f"unknown conditional set {op}")
        arities[base] = 1
    if base not in {"IMUL", "RET", "NOP"} and (base not in arities or len(args) != arities[base]):
        raise AnnotationError(f"unknown opcode or wrong operand count: {op} {args}")
    a = args[0] if args else ""
    b = args[1] if len(args) > 1 else ""
    c = args[2] if len(args) > 2 else ""
    atomic = " atomically" if locked else ""

    if base == "MOV":
        return f"Copy {b} into {a}{gpr32_note(a)}."
    if base == "LEA":
        return f"Compute address {b} into {a}, without reading memory{gpr32_note(a)}."
    if base in {"MOVSX", "MOVSXD", "MOVZX"}:
        mode = "sign" if base != "MOVZX" else "zero"
        return f"{mode.capitalize()}-extend {b} into {a}{gpr32_note(a)}."
    if base in ARITH:
        if base == "XOR" and a == b:
            return f"Clear {a} to zero{gpr32_note(a)}; set ZF and clear CF and OF."
        expr = {"ADD": f"{a} + {b}", "SUB": f"{a} - {b}",
                "AND": f"{a} AND {b}", "OR": f"{a} OR {b}",
                "XOR": f"{a} XOR {b}", "SBB": f"{a} - {b} - CF"}[base]
        flag = "logic flags (CF and OF clear)" if base in {"AND", "OR", "XOR"} else "arithmetic flags"
        return f"Store {expr} in {a}{atomic}{gpr32_note(a)}; updates {flag}."
    if base in {"CMP", "TEST"}:
        expr = f"{a} - {b}" if base == "CMP" else f"{a} AND {b}"
        extra = "; CF and OF clear" if base == "TEST" else ""
        return f"Set flags from {expr} without storing the result{extra}."
    if base in {"INC", "DEC"}:
        sign = "+ 1" if base == "INC" else "- 1"
        return f"Store {a} {sign} in {a}{atomic}{gpr32_note(a)}; updates arithmetic flags except CF."
    if base == "NEG":
        return f"Replace {a} with 0 - {a}{gpr32_note(a)}; updates arithmetic flags."
    if base == "NOT":
        return f"Invert every bit of {a}{gpr32_note(a)}; flags are unchanged."
    if base in {"SHL", "SHR", "SAR", "ROL", "ROR"}:
        action = {"SHL": "shift left, filling low bits with zero",
                  "SHR": "shift right logically, filling high bits with zero",
                  "SAR": "shift right arithmetically, copying the sign bit",
                  "ROL": "rotate left", "ROR": "rotate right"}[base]
        mask = "0x3f" if width(a) == "64-bit" else "0x1f"
        effect = "shift flags update for nonzero count; zero count leaves the operand bits and flags unchanged" if base in {"SHL", "SHR", "SAR"} else "CF updates for nonzero count; zero count leaves the operand bits and flags unchanged"
        clear = gpr32_note(a)
        return f"{action.capitalize()} {a} by {b} masked with {mask}{clear}; {effect}."
    if base in {"BT", "BTR", "BTS"}:
        index = b if has_memory(a) else f"{b} modulo {width(a).removesuffix('-bit')}"
        bit = f"bit selected by {index} in {a}"
        if base == "BT":
            return f"Copy {bit} into CF; do not change {a}."
        return f"Copy {bit} into CF, then {'clear' if base == 'BTR' else 'set'} that bit in {a}{gpr32_note(a)}."
    if base in {"BSF", "BSR"}:
        where = "least" if base == "BSF" else "most"
        return f"If {b} is nonzero, put its {where} significant set-bit index in {a}{gpr32_note(a)}; set ZF when {b} is zero, leaving {a} undefined then."
    if base == "XCHG":
        return f"Exchange {a} and {b}{' atomically for the memory operand' if has_memory(a) or has_memory(b) else ''}{gpr32_note(a)}{gpr32_note(b)}."
    if base == "XADD":
        return f"Store old {a} + old {b} in {a} and old {a} in {b}{atomic}{gpr32_note(b)}; updates arithmetic flags."
    if base == "CMPXCHG":
        acc = {"8-bit": "AL", "16-bit": "AX", "32-bit": "EAX", "64-bit": "RAX"}.get(width(a))
        if not acc:
            raise AnnotationError(f"cannot determine CMPXCHG width: {a}")
        clear = gpr32_note(acc)
        return f"Compare {acc} with {a}; if equal, store {b} in {a} and set ZF; otherwise copy old {a} to {acc}{clear} and clear ZF{atomic}; sets subtraction flags."
    if base == "IMUL":
        if len(args) == 1:
            implicit = {"8-bit": "AL and AX", "16-bit": "AX and DX:AX", "32-bit": "EAX and EDX:EAX", "64-bit": "RAX and RDX:RAX"}.get(width(a))
            if not implicit:
                raise AnnotationError(f"cannot determine IMUL width: {a}")
            src, dest = implicit.split(" and ")
            return f"Signed-multiply {src} by {a}, storing the full product in {dest}; CF and OF report overflow."
        src = f"{a} times {b}" if len(args) == 2 else f"{b} times {c}"
        return f"Store low {width(a)} signed product of {src} in {a}{gpr32_note(a)}; CF and OF report truncation."
    if base in {"MUL", "DIV", "IDIV"}:
        w = width(a)
        regs = {"8-bit": ("AX", "AL", "AH"), "16-bit": ("DX:AX", "AX", "DX"),
                "32-bit": ("EDX:EAX", "EAX", "EDX"), "64-bit": ("RDX:RAX", "RAX", "RDX")}.get(w)
        if not regs:
            raise AnnotationError(f"cannot determine {base} width: {a}")
        pair, lo, hi = regs
        if base == "MUL":
            return f"Unsigned-multiply {lo} by {a}; store full product in {pair}; CF and OF report nonzero high half."
        sign = "signed" if base == "IDIV" else "unsigned"
        return f"{sign.capitalize()}-divide {pair} by {a}; quotient goes to {lo}, remainder to {hi}; divide errors raise an exception."
    if base == "CDQ":
        return "Sign-extend EAX into EDX:EAX; flags are unchanged."
    if base == "CQO":
        return "Sign-extend RAX into RDX:RAX; flags are unchanged."
    if base == "CDQE":
        return "Sign-extend EAX into RAX; flags are unchanged."
    if base == "PUSH":
        return f"Decrease RSP by 8 and store {a} at the new stack top."
    if base == "POP":
        return f"Load {a} from the stack top and increase RSP by 8{gpr32_note(a)}."
    if base == "CALL":
        if has_memory(a):
            target = f"the target pointer stored in {a}"
        elif re.fullmatch(r"0x[0-9a-fA-F]+", a):
            target = f"address {a}"
        else:
            target = f"the target address held in {a}"
        return f"Push the return address, then call {target}."
    if base == "JMP":
        return f"Transfer control to {a}."
    if base.startswith("J"):
        return f"Jump to {a} when {PRED[base[1:]]}."
    if base.startswith("CMOV"):
        read = f"Read {b} regardless of the condition; " if has_memory(b) else ""
        clear = "; clear upper 32 bits even when the condition is false" if GPR32.fullmatch(a) else ""
        return f"{read}Copy {b} to {a} when {PRED[base[4:]]}; otherwise keep {a}{clear}."
    if base.startswith("SET"):
        return f"Set {a} to 1 when {PRED[base[3:]]}, else 0."
    if base == "RET":
        return f"Pop the return address, add {a} to RSP, and resume there." if args else "Pop the return address from the stack and resume there."
    if base == "INT":
        return f"Raise software interrupt {a}."
    if base == "INT3":
        return "Raise a breakpoint exception."
    if base == "NOP":
        return "Do nothing; any encoded address operand is not read."
    if base in {"MOVSB", "MOVSQ"}:
        size = "byte" if base == "MOVSB" else "8-byte value"
        step = 1 if base == "MOVSB" else 8
        repeat = "Repeat RCX times: " if repeated else ""
        count = ", decrementing RCX to zero" if repeated else ""
        return f"{repeat}Copy a {size} from [RSI] to [RDI]; adjust RSI and RDI by +{step} if DF=0, -{step} if DF=1{count}."
    if base in {"STOSB", "STOSW", "STOSQ"}:
        reg = {"STOSB": "AL", "STOSW": "AX", "STOSQ": "RAX"}[base]
        step = {"STOSB": 1, "STOSW": 2, "STOSQ": 8}[base]
        repeat = "Repeat RCX times: " if repeated else ""
        count = ", decrementing RCX to zero" if repeated else ""
        return f"{repeat}Store {reg} at [RDI]; adjust RDI by +{step} if DF=0, -{step} if DF=1{count}."
    if base == "CPUID":
        return "Query CPU feature leaf EAX and subleaf ECX; replace EAX, EBX, ECX, and EDX with results, clearing their upper 32-bit halves."
    if base == "XGETBV":
        return "Read extended control register selected by ECX into EDX:EAX, clearing the upper halves of RDX and RAX."
    if base == "LFENCE":
        return "Order earlier loads before later instructions and loads."
    if base == "SFENCE":
        return "Order earlier stores before later stores."
    if base == "PREFETCHW":
        return f"Hint that cache line at {a} may soon be written; architectural memory state is unchanged."
    if base == "FIDIVR":
        return f"Divide the signed integer at {a} by ST(0), then store the floating-point result in ST(0)."
    if base == "FNSTCW":
        return f"Store the x87 control word in {a} without first checking pending exceptions."
    if base in MOVE_PACKED:
        return f"Copy {MOVE_PACKED[base]} 128-bit data from {b} to {a}."
    if base == "MOVNTPS":
        return f"Store four packed single-precision values from {b} to {a} with a non-temporal write hint; memory must be 16-byte aligned."
    if base in {"MOVD", "MOVQ"}:
        bits = "32" if base == "MOVD" else "64"
        if XMM.fullmatch(a):
            return f"Copy low {bits} bits of {b} to {a}; zero the remaining upper bits of {a}."
        return f"Copy low {bits} bits of {b} to {a}{gpr32_note(a)}."
    if base in {"MOVSS", "MOVSD"}:
        bits = "32" if base == "MOVSS" else "64"
        if XMM.fullmatch(a) and XMM.fullmatch(b):
            return f"Copy low {bits} bits of {b} to {a}, preserving the upper bits of {a}."
        if XMM.fullmatch(a):
            return f"Load low {bits} bits from {b} into {a}, zeroing the upper bits of {a}."
        return f"Store low {bits} bits of {b} in {a}."
    if base.endswith(("SS", "SD")) and base[:-2] in SIMD_ARITH | {"MAX": "Max", "MIN": "Min"}:
        stem, kind = base[:-2], SCALAR[base[-2:]]
        verb = {"ADD": "Add", "SUB": "Subtract", "MUL": "Multiply", "DIV": "Divide",
                "MAX": "Select the maximum of", "MIN": "Select the minimum of"}[stem]
        if stem == "SUB":
            expr = f"{a} minus {b}"
        elif stem == "DIV":
            expr = f"{a} divided by {b}"
        elif stem in {"MAX", "MIN"}:
            expr = f"{a} and {b}"
        else:
            expr = f"{a} and {b}"
        nan = "; on NaN or equality, select the second operand" if stem in {"MAX", "MIN"} else ""
        return f"{verb} {kind} values {expr}; write the low element of {a} and preserve its upper bits{nan}."
    if base in {"COMISS", "COMISD", "UCOMISS", "UCOMISD"}:
        signaling = "signals invalid for any NaN" if base.startswith("COMI") else "signals invalid for signaling NaNs"
        return f"Compare low floating-point values {a} and {b}; set ZF/PF/CF for greater (0/0/0), less (0/0/1), equal (1/0/0), or unordered NaN (1/1/1); {signaling}."
    if base in {"ANDPS", "XORPS", "POR", "PCMPEQB"}:
        if base == "PCMPEQB":
            return f"Compare corresponding bytes of {a} and {b}; set each byte of {a} to 0xff if equal, else zero."
        verb = {"ANDPS": "AND", "XORPS": "XOR", "POR": "OR"}[base]
        return f"Bitwise {verb} all 128 bits of {a} and {b}, storing the result in {a}."
    if base == "PMOVMSKB":
        return f"Collect the sign bit of each byte in {b} into low 16 bits of {a}, clearing the other bits{gpr32_note(a)}."
    if base == "PSRLDQ":
        return f"Shift {a} right by {b} bytes, filling with zero; counts above 15 produce zero."
    if base == "PUNPCKLBW":
        return f"Interleave low eight bytes of old {a} and {b} into {a}."
    if base in {"UNPCKLPD", "UNPCKLPS"}:
        count = "one 64-bit lane" if base == "UNPCKLPD" else "two 32-bit lanes"
        return f"Interleave the low {count} from old {a} and {b} into {a}."
    if base == "PSHUFD":
        return f"Shuffle four 32-bit lanes from {b} into {a}, selecting lanes by immediate {c}."
    if base == "PSHUFLW":
        return f"Shuffle low four 16-bit lanes from {b} into {a} using {c}; copy the upper 64 bits of {b}."
    if base == "SHUFPS":
        return f"Select two 32-bit lanes from old {a} and two from {b} into {a} using immediate {c}."
    if base == "PINSRB":
        return f"Insert low byte of {b} into byte lane ({c} masked to 4 bits) of {a}; preserve other lanes."
    if base == "PCMPISTRI":
        return f"Compare implicit-length strings in {a} and {b} using mode {c}; ECX gets the selected result index, or 16 for bytes/8 for words if none; update comparison flags."
    if base.startswith("CVT"):
        descriptions = {
            "CVTDQ2PD": "Convert low two signed 32-bit integers", "CVTDQ2PS": "Convert four signed 32-bit integers",
            "CVTPD2PS": "Convert two packed double-precision floats", "CVTPS2PD": "Convert low two packed single-precision floats",
            "CVTSD2SS": "Convert low double-precision float", "CVTSI2SD": "Convert signed integer",
            "CVTSI2SS": "Convert signed integer", "CVTSS2SD": "Convert low single-precision float",
            "CVTTSD2SI": "Truncate low double-precision float", "CVTTSS2SI": "Truncate low single-precision float",
        }
        if base not in descriptions:
            raise AnnotationError(f"unknown conversion {base}")
        target = {
            "CVTDQ2PD": "two packed double-precision floats", "CVTDQ2PS": "four packed single-precision floats",
            "CVTPD2PS": "two packed single-precision floats", "CVTPS2PD": "two packed double-precision floats",
            "CVTSD2SS": "low single-precision float", "CVTSI2SD": "low double-precision float",
            "CVTSI2SS": "low single-precision float", "CVTSS2SD": "low double-precision float",
            "CVTTSD2SI": "signed integer", "CVTTSS2SI": "signed integer",
        }[base]
        tail = "; preserve the upper bits of the destination XMM register" if base in {"CVTSD2SS", "CVTSI2SD", "CVTSI2SS", "CVTSS2SD"} else ""
        if base in {"CVTPD2PS"}:
            tail = "; zero the upper 64 bits of the destination XMM register"
        if base.startswith("CVTT"):
            tail = gpr32_note(a) + "; round toward zero; masked invalid conversion yields integer indefinite"
        elif base in {"CVTDQ2PS", "CVTPD2PS", "CVTSD2SS", "CVTSI2SD", "CVTSI2SS"}:
            tail += "; use MXCSR rounding mode when rounding is needed"
        return f"{descriptions[base]} from {b} to {target} in {a}{tail}."
    raise AnnotationError(f"unhandled opcode {op}")


def annotate_line(line: str) -> str:
    # Preserve every byte before the comment, including original spacing and newline style.
    body, nl = (line[:-2], "\r\n") if line.endswith("\r\n") else ((line[:-1], "\n") if line.endswith("\n") else (line, ""))
    original = body.split(" ; ", 1)[0]
    m = LINE.fullmatch(original)
    if not m:
        raise AnnotationError(f"unexpected listing line: {original[:120]!r}")
    prefix, op, raw, _ = m.groups()
    comment = annotate(op, split_operands(raw or ""))
    return original + " ; " + comment + nl


def prepare(path: Path) -> tuple[bytes, bytes]:
    source = path.read_bytes()
    if not source:
        raise AnnotationError(f"{path.name}: empty listing")
    try:
        lines = source.decode("utf-8").splitlines(keepends=True)
    except UnicodeDecodeError as exc:
        raise AnnotationError(f"{path}: invalid UTF-8") from exc
    output = []
    for i, line in enumerate(lines, 1):
        try:
            output.append(annotate_line(line))
        except AnnotationError as exc:
            raise AnnotationError(f"{path}:{i}: {exc}") from exc
    return source, "".join(output).encode("utf-8")


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("paths", nargs="*", type=Path, help="assembly listings to annotate")
    parser.add_argument("--directory", type=Path, help="directory containing the three known listings")
    parser.add_argument("--check", action="store_true", help="check that comments match without writing")
    ns = parser.parse_args(argv)
    if ns.directory and ns.paths:
        parser.error("use paths or --directory, not both")
    if not ns.directory and not ns.paths:
        parser.error("provide paths or --directory")
    paths = ([ns.directory / n for n in ("ScreenSketch.exe.asm", "ScreenSketchAppService.dll.asm", "SnippingTool.exe.asm")]
             if ns.directory else ns.paths)
    if len({p.resolve() for p in paths}) != len(paths):
        parser.error("duplicate path")
    # Prepare all input before staging or replacing any file.
    prepared = [(p, *prepare(p)) for p in paths]
    stale = [str(p) for p, old, new in prepared if old != new]
    if ns.check:
        if stale:
            print("annotations missing or stale: " + ", ".join(stale))
            return 1
        print(f"annotations current in {len(paths)} file(s)")
        return 0
    staged: list[tuple[Path, Path]] = []
    try:
        for p, old, new in prepared:
            if old == new:
                continue
            with tempfile.NamedTemporaryFile(dir=p.parent, prefix=f".{p.name}.", delete=False) as tmp:
                temp = Path(tmp.name)
                tmp.write(new)
                tmp.flush()
                os.fsync(tmp.fileno())
            os.chmod(temp, p.stat().st_mode)
            staged.append((temp, p))
        for temp, p in staged:
            os.replace(temp, p)
    finally:
        for temp, _ in staged:
            temp.unlink(missing_ok=True)
    print(f"annotated {len(stale)} file(s); {len(paths) - len(stale)} already current")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (AnnotationError, OSError) as exc:
        raise SystemExit(f"error: {exc}") from exc
