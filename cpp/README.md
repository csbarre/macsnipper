# Reconstruction boundary

Files ending in `.pseudocode.c` are Ghidra C-like decompiler output from copied native Windows binaries. They are not recovered original C++, a complete reconstruction, or buildable macOS source. Optimized machine code does not preserve all source types, names, classes, comments, build configuration, or UI resource semantics.

The `.winmd` files contain Windows Runtime metadata and are inventoried separately. They are not analyzed as x64 machine code. Native executable CLR directories are zero; metadata CLR directories are nonzero. This is a native x64 implementation with WinRT metadata, not a managed .NET executable conversion task.

The native Mac implementation is available in `mac/Sources`, with the generated package in `dmg/SnipForMac.dmg`. The Windows reference inputs are in `binaries` and their disassembly exports are in `assembly`. These analysis artifacts document the Windows references; the Mac app is compiled from its separate Swift source.
