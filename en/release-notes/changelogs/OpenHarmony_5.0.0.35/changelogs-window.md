# Window Subsystem Changelog

## cl.window.1 Verification Condition Added to recover

**Access Level**

Public API

**Reason for Change**

The design solution is defective. The supported window mode is not considered during the delivery of the original requirement.

**Change Impact**

This change is a non-compatible change.

Before: A window that does not support the floating window mode can be restored to a freeform window by calling **recover**.

After: When **recover** is called, the system checks whether the window supports the floating window mode. If the window does not support this mode, the window will not be restored to a freeform window.

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.35

**Key API/Component Changes**

@ohos.window.d.ts

System capability: SystemCapability.Window.SessionManager

API: recover

**Adaptation Guide**

Do not call this API for windows that do not support the floating window mode. If this API is called, error code 1300002 is generated.

To support the floating window mode, set the [**supportWindowMode** attribute under **abilities** in the **module.json5** file](../../../application-dev/quick-start/module-configuration-file.md#abilities) to contain **floating** or leave it unspecified, or set [WindowMode](../../../application-dev/reference/apis-arkui/js-apis-window-sys.md#windowmode7) to **window.WindowMode.FLOATING**.
