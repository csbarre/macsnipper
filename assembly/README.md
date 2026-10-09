# Windows disassembly exports

These `.asm` files are Ghidra disassembly exports from the Windows reference executables in `binaries`. Each line records an instruction address, its bytes, and the decoded instruction.

All 470,604 instruction lines have an appended `;` comment explaining the instruction's CPU operation with its actual operands. The address, bytes, mnemonic, operands, and instruction order are preserved. The comments describe normal instruction behavior; they do not recover the original variable names or establish the application's intent at each address.

The exported instruction bytes were checked against the corresponding PE inputs. That check establishes byte correspondence, not complete behavior recovery. These files are reference analysis output; the native Mac implementation is in `mac/Sources`.

## Reading the listings

`RAX`, `RCX`, and similar names are CPU registers. `RSP` is the stack pointer. `RBP` is often used as a frame pointer, but an individual instruction does not prove that role. `EAX` is the low 32 bits of `RAX`; writes to a 32-bit general register clear its upper 32 bits. `XMM` registers hold 128 bits for SIMD operations.

Square brackets identify a memory address. `byte`, `word`, `dword`, `qword`, and `xmmword` mean 1, 2, 4, 8, and 16 bytes. `LEA` computes an address without reading its contents. Ordinary `MOV` copies bits; it does not identify the source value's original programming-language type.

Conditional instructions use CPU flags: `ZF` for a zero result, `CF` for carry/unsigned borrow, `SF` for sign, `OF` for signed overflow, and `PF` for parity. Their comments give the flag predicate because the preceding operation can be arithmetic, a bit test, or a floating-point comparison. `.LOCK` denotes an atomic memory operation; `.REP` denotes repeated string operations using the count and direction state.

## Verification

The strict annotation generator can update the comments or check that they match its current rules:

```bash
python3 assembly/annotate.py --directory assembly
python3 assembly/annotate.py --check --directory assembly
python3 -B -m unittest discover -s assembly -p 'test_*.py'
```

It rejects unsupported instructions instead of inventing a generic explanation, and validates all inputs before replacing any listing.

Run the independent verifier from the repository root with Python 3:

```bash
python3 assembly/verify_annotations.py --baseline-ref e8f97e9
```

It checks every instruction's bytes against the original Windows PE file and confirms that removing only the appended comment reproduces the original listing exactly. Omit `--baseline-ref` when the baseline commit is unavailable in a shallow checkout; the PE-byte and comment checks still run. It reads the Windows files as data.

Instruction semantics are checked against the [Intel instruction-set reference](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html). Unresolved call targets remain addresses rather than invented function names.
