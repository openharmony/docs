# NativeDisplayManager_CutoutInfo


## Overview

The NativeDisplayManager_CutoutInfo struct describes the cutout, which is an area that is not intended for displaying content on the display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

**Related module**: [OH_DisplayManager](_o_h___display_manager.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| int32_t  **boundingRectsLength** | Length of the bounding rectangle for punch holes and notches.| 
| [NativeDisplayManager_Rect](_native_display_manager___rect.md) \* **boundingRects** | Bounding rectangle for punch holes and notches.| 
| [NativeDisplayManager_WaterfallDisplayAreaRects](ive_display_manager___waterfall_display_area_rects.md) **waterfallDisplayAreaRects** | Curved area on the waterfall display.| 
