# drawing_round_rect.h


## Overview

The **drawing_round_rect.h** file declares the functions related to the rounded rectangle in the drawing module.

**File to include**: <native_drawing/drawing_round_rect.h>

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](_drawing.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [OH_Drawing_CornerPos](_drawing.md#oh_drawing_cornerpos)  [OH_Drawing_CornerPos](_drawing.md#oh_drawing_cornerpos) | Defines an enum for the corner positions of a rounded rectangle.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_CornerPos](_drawing.md#oh_drawing_cornerpos) { CORNER_POS_TOP_LEFT, CORNER_POS_TOP_RIGHT, CORNER_POS_BOTTOM_RIGHT, CORNER_POS_BOTTOM_LEFT } | Enumerates the corner positions of a rounded rectangle.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) \* [OH_Drawing_RoundRectCreate](_drawing.md#oh_drawing_roundrectcreate) (const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*, float xRad, float yRad) | Creates an **OH_Drawing_RoundRect** object.| 
| void [OH_Drawing_RoundRectSetCorner](_drawing.md#oh_drawing_roundrectsetcorner) ([OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) \*, [OH_Drawing_CornerPos](_drawing.md#oh_drawing_cornerpos) pos, [OH_Drawing_Corner_Radii](_drawing.md#oh_drawing_corner_radii)) | Sets the radii of the specified rounded corner in a rounded rectangle.| 
| [OH_Drawing_Corner_Radii](_drawing.md#oh_drawing_corner_radii) [OH_Drawing_RoundRectGetCorner](_drawing.md#oh_drawing_roundrectgetcorner) ([OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) \*, [OH_Drawing_CornerPos](_drawing.md#oh_drawing_cornerpos) pos) | Obtains the radii of the specified rounded corner in a rounded rectangle.| 
| void [OH_Drawing_RoundRectDestroy](_drawing.md#oh_drawing_roundrectdestroy) ([OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) \*) | Destroys an **OH_Drawing_RoundRect** object and reclaims the memory occupied by the object.| 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_RoundRectOffset](_drawing.md#oh_drawing_roundrectoffset) ([OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) \*roundRect, float dx, float dy) | Translates a rounded rectangle by an offset along the X axis and Y axis.| 
