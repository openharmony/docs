# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Compression Level of libs Changed in the Packing Tool

**Access Level**

Others

**Reason for Change**

When the **compressNativeLibs** parameter in the [module.json5 file](../../../application-dev/quick-start/module-configuration-file.md) is set to **true**, the packing tool packs **libs** in a lower compression level (changed from 5 to 1). This slightly increases the package size but speeds up packaging.

**Change Impact**

This change is a compatible change. When **compressNativeLibs** in the [module.json5 file](../../../application-dev/quick-start/module-configuration-file.md) is set to **true**, the size of the unsigned package slightly increases.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.6.2

**Key API/Component Changes**

When **compressNativeLibs** in the [module.json5 file](../../../application-dev/quick-start/module-configuration-file.md) is set to **true**, the packing tool packs the **libs** library at the default compression level (5) before the modification. After the modification, the packing tool packs the **libs** library at the fast compression level (1).

**Adaptation Guide**

No adaptation is required.
