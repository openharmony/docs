# Window Subsystem Changelog
## cl.window.1 Verification Condition Added to setRaiseByClickEnabled

**Access Level**

System API

**Reason for Change**

The code implementation for **setRaiseByClickEnabled** is inconsistent with the design document. This API is designed to be used only by application subwindows. If it is called in the main window of an application or a system window, an error code is expected to be returned. Yet, the current code does not include the necessary return scenarios, failing to properly check and prevent calls based on window type and state.

**Change Impact**

This change is a non-compatible change.

Before change: When this API is called in the main window of an application or a system window, no error code is returned but the change does not take effect.

After change: When this API is called in the main window of an application or a system window, an error code is returned and the change does not take effect.

**Start API Level**

10

**Change Since**

OpenHarmony 5.0.2.1

**Key API/Component Changes**

@ohos.window.d.ts


setRaiseByClickEnabled

**Adaptation Guide**

Check whether your application code contains the scenario where this API is called by non-subwindows. If yes, capture the error code and rectify the fault.
