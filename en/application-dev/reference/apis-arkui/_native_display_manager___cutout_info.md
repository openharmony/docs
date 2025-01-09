# NativeDisplayManager_CutoutInfo


## Overview

The NativeDisplayManager_CutoutInfo struct describes the unusable area of a display, including punch hole, notch, and curved area of a waterfall display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

**Related module**: [OH_DisplayManager](_o_h___display_manager.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| int32_t  **boundingRectsLength** | Number of unusable areas (bounding rectangles) designed for punch holes and notches.| 
| [NativeDisplayManager_Rect](_native_display_manager___rect.md) \* **boundingRects** | Unusable areas (bounding rectangles) designed for punch holes and notches.| 
| [NativeDisplayManager_WaterfallDisplayAreaRects](ive_display_manager___waterfall_display_area_rects.md) **waterfallDisplayAreaRects** | Curved area on a waterfall display.| 
