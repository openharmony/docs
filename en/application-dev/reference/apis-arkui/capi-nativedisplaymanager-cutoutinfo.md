# NativeDisplayManager_CutoutInfo

## Overview

The struct describes the unusable area of a display, including punch hole, notch, and curved area of a waterfall display.

**Since**: 12

**Related module**: [OH_DisplayManager](capi-oh-displaymanager.md)

**Header file**: [oh_display_info.h](capi-oh-display-info-h.md)

## Summary

### Member Variables

| Struct| Description|
| -- | -- |
| int32_t boundingRectsLength | Number of unusable areas (bounding rectangles) designed for punch holes and notches.|
| [NativeDisplayManager_Rect](capi-nativedisplaymanager-rect.md)* boundingRects | Unusable areas (bounding rectangles) designed for punch holes and notches.|
| [NativeDisplayManager_WaterfallDisplayAreaRects](capi-nativedisplaymanager-waterfalldisplayarearects.md) waterfallDisplayAreaRects | Curved area on a waterfall display.|
