# drawing_point.h


## Overview

The **drawing_point.h** file declares the functions related to the coordinate point in the drawing module.

**File to include**: &lt;native_drawing/drawing_point.h&gt;

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](_drawing.md)


## Summary


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Drawing_Point](_drawing.md#oh_drawing_point) \* [OH_Drawing_PointCreate](_drawing.md#oh_drawing_pointcreate) (float x, float y) | Creates an **OH_Drawing_Point** object.|
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_PointGetX](_drawing.md#oh_drawing_pointgetx) (const [OH_Drawing_Point](_drawing.md#oh_drawing_point) \*point, float \*x) | Obtains the X coordinate of a point.| 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_PointGetY](_drawing.md#oh_drawing_pointgety) (const [OH_Drawing_Point](_drawing.md#oh_drawing_point) \*point, float \*y) | Obtains the Y coordinate of a point.| 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_PointSet](_drawing.md#oh_drawing_pointset) ([OH_Drawing_Point](_drawing.md#oh_drawing_point) \*point, float x, float y) | Sets the X and Y coordinates of a point.| 
| void [OH_Drawing_PointDestroy](_drawing.md#oh_drawing_pointdestroy) ([OH_Drawing_Point](_drawing.md#oh_drawing_point) \*) | Destroys an **OH_Drawing_Point** object and reclaims the memory occupied by the object.|
