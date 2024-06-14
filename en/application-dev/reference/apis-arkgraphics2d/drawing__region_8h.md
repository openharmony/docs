# drawing_region.h


## Overview

The **drawing_region.h** file declares the functions related to the region in the drawing module, including creating a region, setting the boundary, and destroying a region.

**File to include**: &lt;native_drawing/drawing_region.h&gt;

**Library**: libnative_drawing.so

**Since**: 12

**Related module**: [Drawing](_drawing.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_Region](_drawing.md#oh_drawing_region) \* [OH_Drawing_RegionCreate](_drawing.md#oh_drawing_regioncreate) (void) | Creates an **OH_Drawing_Region** object for more accurate graphical control.| 
| bool [OH_Drawing_RegionSetRect](_drawing.md#oh_drawing_regionsetrect) ([OH_Drawing_Region](_drawing.md#oh_drawing_region) \*region, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect) | Sets the boundary for an **OH_Drawing_Region** object.| 
| void [OH_Drawing_RegionDestroy](_drawing.md#oh_drawing_regiondestroy) ([OH_Drawing_Region](_drawing.md#oh_drawing_region) \*) | Destroys an **OH_Drawing_Region** object and reclaims the memory occupied by the object.| 
