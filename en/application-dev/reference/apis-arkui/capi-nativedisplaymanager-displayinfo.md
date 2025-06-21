# NativeDisplayManager_DisplayInfo

## Overview

The NativeDisplayManager_DisplayInfo struct describes the information about a display.

**Since**: 14

**Related module**: [OH_DisplayManager](capi-oh-displaymanager.md)

**Header file**: [oh_display_info.h](capi-oh-display-info-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t id | ID of the display. The value must be a non-negative integer.|
| char name | Name of the display.|
| bool isAlive | Whether the display is active. The value **true** means that the display is active, and **false** means the opposite.|
| int32_t width | Width of the display, in px. The value must be a non-negative integer.|
| int32_t height | Height of the display, in px. The value must be a non-negative integer.|
| int32_t physicalWidth | Physical width of the display, in px. The value must be a non-negative integer.|
| int32_t physicalHeight | Physical height of the display, in px. The value must be a non-negative integer.|
| uint32_t refreshRate | Refresh rate of the display, in Hz. The value must be a non-negative integer.|
| uint32_t availableWidth | Width of the available area on a 2-in-1 device, in px. The value must be a non-negative integer.|
| uint32_t availableHeight | Height of the available area on a 2-in-1 device, in px. The value is an integer greater than 0.|
| float densityDPI | Physical pixel density of the display, that is, the number of pixels per inch. The value must be a floating point number greater than 0. The unit is px. Generally, the value is **160.0** or **480.0**. The actual value depends on the optional values provided by the device in use.|
| float densityPixels | Logical pixel density of the display, which is the scaling coefficient between physical pixels and logical pixels. The value is a floating point number greater than 0 and is restricted by the range of **densityDPI**. The value range is [0.5, 4.0]. Generally, the value is **1.0** or **3.0**. The actual value depends on the density DPI provided by the device in use.|
| float scaledDensity | Scaling factor for fonts displayed on the display. The value must be a floating point number greater than 0. Generally, the value is the same as that of **densityPixels**.|
| float xDPI | Exact physical pixels per inch of the display in the X dimension. The value must be a floating point number greater than 0.|
| float yDPI | Exact physical pixels per inch of the display in the Y dimension. The value must be a floating point number greater than 0.|
| [NativeDisplayManager_Rotation](capi-oh-display-info-h.md#nativedisplaymanager_rotation) rotation | Clockwise rotation angle of the display.|
| [NativeDisplayManager_DisplayState](capi-oh-display-info-h.md#nativedisplaymanager_displaystate) state | State of the display.|
| [NativeDisplayManager_Rotation](capi-oh-display-info-h.md#nativedisplaymanager_rotation) orientation | Orientation of the display.|
| [NativeDisplayManager_DisplayHdrFormat](capi-nativedisplaymanager-displayhdrformat.md)* hdrFormat | All the HDR formats supported by the display.|
| [NativeDisplayManager_DisplayColorSpace](capi-nativedisplaymanager-displaycolorspace.md)* colorSpace | All the color spaces supported by the display.|
