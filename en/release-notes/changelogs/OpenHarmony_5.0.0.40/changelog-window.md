# Window Subsystem Changelog

## cl.window.1 Verification Condition Added to maximize

**Access Level**

Public API

**Reason for Change**

The API implementation is inconsistent with the design. This API takes effect only on 2-in-1 devices.

**Change Impact**

This change is a non-compatible change.

Before the change: The API can be called to maximize a window on a non-2-in-1 device.

After the change: When **maximize** is called, the system checks whether the device is a 2-in-1 device. If not, the window is not maximized.

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.40

**Key API/Component Changes**

@ohos.window.d.ts

System capability: SystemCapability.Window.SessionManager

API: maximize

**Adaptation Guide**

You are not advised to call this API on non-2-in-1 devices. If this API is called on a non-2-in-1 device, no error is reported but no response is returned.
