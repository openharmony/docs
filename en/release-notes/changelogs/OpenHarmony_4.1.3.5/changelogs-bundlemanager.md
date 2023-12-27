# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Uncompressed Mode Adopted for libs During Packing

**Access Level**

Other

**Reason for Change**

By default, the packing tool packs **libs** in compressed mode. This operation decreases the size of the installation package while increasing the packing time. However, developers are more sensitive to the packing time in the development and debugging phase. As such, the packing tool is changed to pack **libs** in uncompressed mode by default.

**Change Impact**

This change is a compatible change. It affects the compressed mode of **libs** during packing.

**Change Since**

OpenHarmony SDK 4.1.3.5

**Key API/Component Changes**

Before the change, the packing tool packs **libs** in compressed mode by default.

After the change, the packing tool packs **libs** in uncompressed mode by default.

**Adaptation Guide**

By default, the packing tool packs **libs** in uncompressed mode. To pack **libs** in compressed mode, set **compressNativeLibs** in the [module.json5 file](../../../application-dev/quick-start/module-configuration-file.md) to **true**.
