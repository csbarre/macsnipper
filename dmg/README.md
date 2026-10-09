# Native Mac package

`SnipForMac.dmg` contains the native `Snip.app` and an Applications shortcut for installation. It was generated from the current Mac build on 2026-10-09 and verified to match the tested app executable.

The app requires Apple silicon and macOS 14 or later. It is ad-hoc signed and is not notarized. The package checksum and app signature were verified before publication. See [the app guide](../mac/README.md) for permissions, usage, and build instructions.

To regenerate the package from the repository root:

```bash
bash mac/package.sh
```
