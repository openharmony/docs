# drawing_pen.h


## Overview

The **drawing_pen.h** file declares the functions related to the pen in the drawing module.

**File to include**: &lt;native_drawing/drawing_pen.h&gt;

**Library**: libnative_drawing.so

**Since**: 8

**Related module**: [Drawing](_drawing.md)


## Summary


### Enums

| Name| Description|
| -------- | -------- |
| [OH_Drawing_PenLineCapStyle](_drawing.md#oh_drawing_penlinecapstyle) {<br>LINE_FLAT_CAP, LINE_SQUARE_CAP, LINE_ROUND_CAP<br>} | Enumerates the line cap styles of a pen. The line cap style defines the style of both ends of a line segment drawn by the pen.|
| [OH_Drawing_PenLineJoinStyle](_drawing.md#oh_drawing_penlinejoinstyle) {<br>LINE_MITER_JOIN, LINE_ROUND_JOIN, LINE_BEVEL_JOIN<br>} | Enumerates the line join styles of a pen. The line join style defines the shape of the joints of a polyline segment drawn by the pen.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \* [OH_Drawing_PenCreate](_drawing.md#oh_drawing_pencreate) (void) | Creates an **OH_Drawing_Path** object.|
| void [OH_Drawing_PenDestroy](_drawing.md#oh_drawing_pendestroy) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Destroys an **OH_Drawing_Path** object and reclaims the memory occupied by the object.|
| bool [OH_Drawing_PenIsAntiAlias](_drawing.md#oh_drawing_penisantialias) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Checks whether anti-aliasing is enabled for a pen. Anti-aliasing makes the pixels around the shape edges semi-transparent.|
| void [OH_Drawing_PenSetAntiAlias](_drawing.md#oh_drawing_pensetantialias) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, bool) | Enables or disables anti-aliasing for a pen. Anti-aliasing makes the pixels around the shape edges semi-transparent.|
| uint32_t [OH_Drawing_PenGetColor](_drawing.md#oh_drawing_pengetcolor) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Obtains the color of a pen. The color is used by the pen to outline a shape.|
| void [OH_Drawing_PenSetColor](_drawing.md#oh_drawing_pensetcolor) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, uint32_t color) | Sets the color for a pen. The color is used by the pen to outline a shape.|
| uint8_t [OH_Drawing_PenGetAlpha](_drawing.md#oh_drawing_pengetalpha) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Obtains the alpha value of a pen. This value is used by the alpha channel when the pen outlines a shape.|
| void [OH_Drawing_PenSetAlpha](_drawing.md#oh_drawing_pensetalpha) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, uint8_t alpha) | Sets the alpha value for a pen. This value is used by the alpha channel when the pen outlines a shape.|
| float [OH_Drawing_PenGetWidth](_drawing.md#oh_drawing_pengetwidth) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Obtains the thickness of a pen. This thickness determines the width of the outline of a shape.|
| void [OH_Drawing_PenSetWidth](_drawing.md#oh_drawing_pensetwidth) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, float width) | Sets the thickness for a pen. This thickness determines the width of the outline of a shape.|
| float [OH_Drawing_PenGetMiterLimit](_drawing.md#oh_drawing_pengetmiterlimit) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Obtains the stroke miter limit of a polyline drawn by a pen. When the corner type is bevel, a beveled corner is displayed if the miter limit is exceeded, and a mitered corner is displayed if the miter limit is not exceeded.|
| void [OH_Drawing_PenSetMiterLimit](_drawing.md#oh_drawing_pensetmiterlimit) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, float miter) | Sets the stroke miter limit for a polyline drawn by a pen. When the corner type is bevel, a beveled corner is displayed if the miter limit is exceeded, and a mitered corner is displayed if the miter limit is not exceeded.|
| [OH_Drawing_PenLineCapStyle](_drawing.md#oh_drawing_penlinecapstyle)[OH_Drawing_PenGetCap](_drawing.md#oh_drawing_pengetcap) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Obtains the line cap style of a pen.|
| void [OH_Drawing_PenSetCap](_drawing.md#oh_drawing_pensetcap) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, [OH_Drawing_PenLineCapStyle](_drawing.md#oh_drawing_penlinecapstyle)) | Sets the line cap style for a pen.|
| [OH_Drawing_PenLineJoinStyle](_drawing.md#oh_drawing_penlinejoinstyle)[OH_Drawing_PenGetJoin](_drawing.md#oh_drawing_pengetjoin) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Obtains the line join style of a pen.|
| void [OH_Drawing_PenSetJoin](_drawing.md#oh_drawing_pensetjoin) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, [OH_Drawing_PenLineJoinStyle](_drawing.md#oh_drawing_penlinejoinstyle)) | Sets the line join style for a pen.|
