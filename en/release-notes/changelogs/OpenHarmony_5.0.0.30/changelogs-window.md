# Window Subsystem Changelog

## cl.window.1 Error Code Returned by getTitleButtonRect Is Changed

**Access Level**

Public API

**Reason for Change**

The API implementation is inconsistent with the design. This API takes effect only on 2-in-1 devices.

**Change Impact**

This change is a non-compatible change.

Before the change: When a non-2-in-1 device calls **getTitleButtonRect**, error code 1300002 is returned.

After the change: When a non-2-in-1 device calls **getTitleButtonRect**, error code 801 is returned.

**Start API Level**

11

**Change Since**

OpenHarmony SDK 5.0.0.30

**Key API/Component Changes**

@ohos.window.d.ts

System capability: SystemCapability.Window.SessionManager

API: getTitleButtonRect

**Adaptation Guide**

Call this API on a 2-in-1 device. If it is called on a non-2-in-1 device, error code 801 is returned.
