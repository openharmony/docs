# Window Subsystem Changelog

## cl.window.1 APIs setWindowSystemBarEnable and setSystemBarEnable Are No Longer Effective for 2-in-1 Devices

**Access Level**

Public API

**Reason for Change**

For a 2-in-1 device, the display of the status bar in full-screen mode is restricted by the system layout. You do not need to call APIs to display or hide the status bar. In other words, the APIs **setWindowSystemBarEnable** and **setSystemBarEnable** do not take effect on the 2-in-1 device.

![Alt text](figures/window_layout.png)

**Change Impact**

This change is a non-compatible change.

The change takes effect from API version 12. Applications built using the SDK of API version 11 or earlier are not affected.

Before the change, the APIs can be called to display or hide the status bar on a 2-in-1 device in full screen mode.
After the change, the window layout on the 2-in-1 device automatically adapts to the avoidance logic, and no API needs to be called for control.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.31

**Key API/Component Changes**

@ohos.window.d.ts

setWindowSystemBarEnable

setSystemBarEnable
