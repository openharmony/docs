# Window Subsystem Changelog

## cl.window.1 Floating Window Layer Is Adjusted to Be Above the Dock Bar on 2-in-1 Devices

**Access Level**

Public API

**Reason for Change**

Floating windows of the type **TYPE_FLOAT** created by applications are positioned below the dock bar, which mean that they may be obscured by it. This is particularly problematic in scenarios like video meeting, where user experience does not meet application expectations.

**Impact of the Change**

This change does not require application adaptation.

- Before the change, on 2-in-1 devices, the floating window of the TYPE_FLOAT type is positioned below the dock bar.
  
- After the change, on 2-in-1 devices, the floating window of the TYPE_FLOAT type is positioned above the dock bar.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.1.52

**Key API/Component Changes**

@ohos.window.d.ts

Interface: TYPE_FLOAT

**Adaptation Guide**

No adaptation is required.
