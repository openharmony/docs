# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Field fileContextMenu Changed in HapModuleInfo

**Access Level**

Public

**Reason for Change**

The field name is difficult to understand.

**Change Impact**

This change is an incompatible change. You need to change **fileContextMenu** in your code to **fileContextMenuConfig**. The meaning and usage of the field remain unchanged.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.6.3

**Key API/Component Changes**

The **fileContextMenu** field in **HapModuleInfo** is changed to **fileContextMenuConfig**.

**Adaptation Guide**

If used, change **fileContextMenu** in your code to **fileContextMenuConfig**.
