# Windows disassembly exports

These `.asm` files are Ghidra disassembly exports from the Windows reference executables in `binaries`. Each line records an instruction address, its bytes, and the decoded instruction.

The exported instruction bytes were checked against the corresponding PE inputs. That check establishes byte correspondence, not complete behavior recovery. These files are reference analysis output; the native Mac implementation is in `mac/Sources`.
