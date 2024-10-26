# Window Subsystem Changelog

## cl.display.1 Calculation Method of xDPI and yDPI of a Display Object Is Optimized

**Access Level**

Public API

**Reason for Change**

Since API version 12, the calculation method of xDPI and yDPI of a **Display** object is changed so that the values of xDPI and yDPI do not change with the display rotation.

**Change Impact**

This change is a non-compatible change.

In API version 11 and earlier versions, the calculation of xDPI and yDPI of a **Display** object changes with the display rotation. As a result, the values of xDPI and yDPI obtained by the application change dynamically.

In API version 12 and later versions, the calculation of xDPI and yDPI of a **Display** object does not change with the display rotation. The values of xDPI and yDPI obtained by the application are fixed.

**Start API Level**

API version 7

**Change Since**

OpenHarmony SDK 5.0.0.29

**Key API/Component Changes**

xDPI and yDPI of a **Display** object.

**Adaptation Guide**

During the adaptation, check whether the changed behavior affects the UI effect.
