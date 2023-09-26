# ArkUI Subsystem Changelog

## cl.arkui.1 Change of Certain Predicates of uiAppearance from Public APIs to System APIs

Changed the namespace **uiAppearance** and its internal **DarkMode** enum predicates from public APIs to system APIs.

**Change Impact**

None. The namespace **uiAppearance** and its internal **DarkMode** enum are used only by system APIs before and after the change.

**Key API/Component Changes**

The system API description is added to the following APIs:

- declare namespace uiAppearance

- enum DarkMode

- ALWAYS_DARK = 0

- ALWAYS_LIGHT = 1
