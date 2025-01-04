# Window Subsystem Changelog

## cl.window.1 Optimized getWindowProperties by Improving the Real-Time Accuracy of the drawableRect Value Returned

**Access Level**

Public API

**Reason for Change**

An application calls **getWindowProperties** to obtain the window properties, including the drawable area specified by the **drawableRect** field. However, if **getWindowproperties** is called in the **on('windowSizeChange')** callback, **drawableRect** in the return value might reflect outdated information.
With this update, the **on('windowSizeChange')** callback now simultaneously refreshes both **windowRect** and **drawableRect**, so the application can perform more flexible self-drawing layout.

**Change Impact**

This change is a non-compatible change.

Before the change: If **getWindowProperties** is called in the **on('windowSizeChange')** callback, the **drawableRect** field in the return value might reflect outdated information.

After the change: If **getWindowProperties** is called in the **on('windowSizeChange')** callback, the **drawableRect** field in the return value reflects the real-time information.

**Start API Level**

11

**Change Since**

OpenHarmony SDK 5.0.0.45

**Key API/Component Changes**

@ohos.window.d.ts

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**API**: getWindowProperties

**Adaptation Guide**

The **drawableRect** field is provided since API version 11.

In API versions 11 and 12, you are not advised to use this field for layout. You can perform layout based on **windowRect**.

In API version 13 and later versions, you are advised to use this field for precise layout.
