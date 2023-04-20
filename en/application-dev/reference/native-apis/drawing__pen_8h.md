# drawing_pen.h


## Overview

Declares functions related to the **pen** object in the drawing module.

**Since:**
8

**Related Modules:**

[Drawing](_drawing.md)


## Summary


### Enums

| Name | Description | 
| -------- | -------- |
| [OH_Drawing_PenLineCapStyle](_drawing.md#oh_drawing_penlinecapstyle) { [LINE_FLAT_CAP](_drawing.md), [LINE_SQUARE_CAP](_drawing.md), [LINE_ROUND_CAP](_drawing.md) } | Enumerates line cap styles of a pen. The line cap style defines the style of both ends of a line segment drawn by the pen.  | 
| [OH_Drawing_PenLineJoinStyle](_drawing.md#oh_drawing_penlinejoinstyle) { [LINE_MITER_JOIN](_drawing.md), [LINE_ROUND_JOIN](_drawing.md), [LINE_BEVEL_JOIN](_drawing.md) } | Enumerates pen line join styles. The line join style defines the shape of the joints of a polyline segment drawn by the pen.  | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_Drawing_PenCreate](_drawing.md#oh_drawing_pencreate) (void) | Creates an **OH_Drawing_Pen** object.  | 
| [OH_Drawing_PenDestroy](_drawing.md#oh_drawing_pendestroy) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Destroys an **OH_Drawing_Pen** object and reclaims the memory occupied by the object.  | 
| [OH_Drawing_PenIsAntiAlias](_drawing.md#oh_drawing_penisantialias) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Checks whether anti-aliasing is enabled for a pen. If anti-aliasing is enabled, edges will be drawn with partial transparency.  | 
| [OH_Drawing_PenSetAntiAlias](_drawing.md#oh_drawing_pensetantialias) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, bool) | Enables or disables anti-aliasing for a pen. If anti-aliasing is enabled, edges will be drawn with partial transparency.  | 
| [OH_Drawing_PenGetColor](_drawing.md#oh_drawing_pengetcolor) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Obtains the color of a pen. The color is used by the pen to outline a shape.  | 
| [OH_Drawing_PenSetColor](_drawing.md#oh_drawing_pensetcolor) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, uint32_t color) | Sets the color for a pen. The color is used by the pen to outline a shape.  | 
| [OH_Drawing_PenGetWidth](_drawing.md#oh_drawing_pengetwidth) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Obtains the thickness of a pen. This thickness determines the width of the outline of a shape.  | 
| [OH_Drawing_PenSetWidth](_drawing.md#oh_drawing_pensetwidth) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, float width) | Sets the thickness for a pen. This thickness determines the width of the outline of a shape.  | 
| [OH_Drawing_PenGetMiterLimit](_drawing.md#oh_drawing_pengetmiterlimit) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Obtains the stroke miter limit of a polyline drawn by a pen. When the corner type is bevel, a beveled corner is displayed if the miter limit is exceeded, and a mitered corner is displayed if the miter limit is not exceeded.  | 
| [OH_Drawing_PenSetMiterLimit](_drawing.md#oh_drawing_pensetmiterlimit) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, float miter) | Sets the stroke miter limit for a polyline drawn by a pen. When the corner type is bevel, a beveled corner is displayed if the miter limit is exceeded, and a mitered corner is displayed if the miter limit is not exceeded.  | 
| [OH_Drawing_PenGetCap](_drawing.md#oh_drawing_pengetcap) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Obtains the line cap style of a pen.  | 
| [OH_Drawing_PenSetCap](_drawing.md#oh_drawing_pensetcap) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, [OH_Drawing_PenLineCapStyle](_drawing.md#oh_drawing_penlinecapstyle)) | Sets the line cap style for a pen.  | 
| [OH_Drawing_PenGetJoin](_drawing.md#oh_drawing_pengetjoin) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Obtains the line join style of a pen.  | 
| [OH_Drawing_PenSetJoin](_drawing.md#oh_drawing_pensetjoin) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, [OH_Drawing_PenLineJoinStyle](_drawing.md#oh_drawing_penlinejoinstyle)) | Sets the line join style for a pen.  | 
