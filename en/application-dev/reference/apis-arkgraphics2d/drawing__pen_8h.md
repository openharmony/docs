# drawing_pen.h


## Overview

The **drawing_pen.h** file declares functions related to the pen in the drawing module.

**File to include**: &lt;native_drawing/drawing_pen.h&gt;

**Library**: libnative_drawing.so

**Since**: 8

**Related module**: [Drawing](_drawing.md)


## Summary


### Types

| Name | Description | 
| -------- | -------- |
| typedef enum [OH_Drawing_PenLineCapStyle](_drawing.md#oh_drawing_penlinecapstyle)  [OH_Drawing_PenLineCapStyle](_drawing.md#oh_drawing_penlinecapstyle) | Defines an enum for line cap styles of a pen. The line cap style defines the style of both ends of a line segment drawn by the pen. | 
| typedef enum [OH_Drawing_PenLineJoinStyle](_drawing.md#oh_drawing_penlinejoinstyle)  [OH_Drawing_PenLineJoinStyle](_drawing.md#oh_drawing_penlinejoinstyle) | Defines an enum for line join styles of a pen. The line join style defines the shape of the joints of a polyline segment drawn by the pen. | 


### Enums

| Name | Description | 
| -------- | -------- |
| [OH_Drawing_PenLineCapStyle](_drawing.md#oh_drawing_penlinecapstyle) { LINE_FLAT_CAP, LINE_SQUARE_CAP, LINE_ROUND_CAP } | Enumerates the line cap styles of a pen. The line cap style defines the style of both ends of a line segment drawn by the pen. | 
| [OH_Drawing_PenLineJoinStyle](_drawing.md#oh_drawing_penlinejoinstyle) { LINE_MITER_JOIN, LINE_ROUND_JOIN, LINE_BEVEL_JOIN } | Enumerates the line join styles of a pen. The line join style defines the shape of the joints of a polyline segment drawn by the pen. | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \* [OH_Drawing_PenCreate](_drawing.md#oh_drawing_pencreate) (void) | Creates an **OH_Drawing_Path** object. | 
| [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \* [OH_Drawing_PenCopy](_drawing.md#oh_drawing_pencopy) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*pen) | Copies an existing [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) object to create a new one. | 
| void [OH_Drawing_PenDestroy](_drawing.md#oh_drawing_pendestroy) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Destroys an **OH_Drawing_Path** object and reclaims the memory occupied by the object. | 
| bool [OH_Drawing_PenIsAntiAlias](_drawing.md#oh_drawing_penisantialias) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Checks whether anti-aliasing is enabled for a pen. Anti-aliasing makes the pixels around the shape edges semi-transparent. | 
| void [OH_Drawing_PenSetAntiAlias](_drawing.md#oh_drawing_pensetantialias) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, bool) | Enables or disables anti-aliasing for a pen. Anti-aliasing makes the pixels around the shape edges semi-transparent. | 
| uint32_t [OH_Drawing_PenGetColor](_drawing.md#oh_drawing_pengetcolor) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Obtains the color of a pen. The color is used by the pen to outline a shape. | 
| void [OH_Drawing_PenSetColor](_drawing.md#oh_drawing_pensetcolor) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, uint32_t color) | Sets the color for a pen. The color is used by the pen to outline a shape. | 
| uint8_t [OH_Drawing_PenGetAlpha](_drawing.md#oh_drawing_pengetalpha) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Obtains the alpha value of a pen. This value is used by the alpha channel when the pen outlines a shape. | 
| void [OH_Drawing_PenSetAlpha](_drawing.md#oh_drawing_pensetalpha) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, uint8_t alpha) | Sets the alpha value for a pen. This value is used by the alpha channel when the pen outlines a shape. | 
| float [OH_Drawing_PenGetWidth](_drawing.md#oh_drawing_pengetwidth) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Obtains the width of a pen. The width describes the thickness of the outline of a shape. | 
| void [OH_Drawing_PenSetWidth](_drawing.md#oh_drawing_pensetwidth) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, float width) | Sets the width for a pen. The value **0** is treated as an unusually thin width. During drawing, the width of 0 is always drawn as 1 pixel wide, regardless of any scaling applied to the canvas. Negative values are also regarded as the value **0** during the drawing process. | 
| float [OH_Drawing_PenGetMiterLimit](_drawing.md#oh_drawing_pengetmiterlimit) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Obtains the stroke miter limit of a polyline drawn by a pen. When the corner type is bevel, a beveled corner is displayed if the miter limit is exceeded, and a mitered corner is displayed if the miter limit is not exceeded. | 
| void [OH_Drawing_PenSetMiterLimit](_drawing.md#oh_drawing_pensetmiterlimit) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, float miter) | Sets the stroke miter limit for a polyline drawn by a pen. When the corner type is bevel, a beveled corner is displayed if the miter limit is exceeded, and a mitered corner is displayed if the miter limit is not exceeded. | 
| [OH_Drawing_PenLineCapStyle](_drawing.md#oh_drawing_penlinecapstyle) [OH_Drawing_PenGetCap](_drawing.md#oh_drawing_pengetcap) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Obtains the line cap style of a pen. | 
| void [OH_Drawing_PenSetCap](_drawing.md#oh_drawing_pensetcap) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, [OH_Drawing_PenLineCapStyle](_drawing.md#oh_drawing_penlinecapstyle)) | Sets the line cap style for a pen. | 
| [OH_Drawing_PenLineJoinStyle](_drawing.md#oh_drawing_penlinejoinstyle) [OH_Drawing_PenGetJoin](_drawing.md#oh_drawing_pengetjoin) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Obtains the line join style of a pen. | 
| void [OH_Drawing_PenSetJoin](_drawing.md#oh_drawing_pensetjoin) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, [OH_Drawing_PenLineJoinStyle](_drawing.md#oh_drawing_penlinejoinstyle)) | Sets the line join style for a pen. | 
| void [OH_Drawing_PenSetShaderEffect](_drawing.md#oh_drawing_pensetshadereffect) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) \*) | Sets the shader effect for a pen. | 
| void [OH_Drawing_PenSetShadowLayer](_drawing.md#oh_drawing_pensetshadowlayer) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, [OH_Drawing_ShadowLayer](_drawing.md#oh_drawing_shadowlayer) \*) | Sets the shadow layer for a pen. The shadow layer effect takes effect only when text is drawn. | 
| void [OH_Drawing_PenSetPathEffect](_drawing.md#oh_drawing_pensetpatheffect) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \*) | Sets the path effect for a pen. | 
| void [OH_Drawing_PenSetFilter](_drawing.md#oh_drawing_pensetfilter) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, [OH_Drawing_Filter](_drawing.md#oh_drawing_filter) \*) | Sets a filter for a pen. | 
| void [OH_Drawing_PenGetFilter](_drawing.md#oh_drawing_pengetfilter) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, [OH_Drawing_Filter](_drawing.md#oh_drawing_filter) \*) | Obtains the filter of a pen. The filter is a container that holds a mask filter and color filter. | 
| void [OH_Drawing_PenSetBlendMode](_drawing.md#oh_drawing_pensetblendmode) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, [OH_Drawing_BlendMode](_drawing.md#oh_drawing_blendmode)) | Sets a blender for a pen. The blender implements the specified blend mode. | 
| bool [OH_Drawing_PenGetFillPath](_drawing.md#oh_drawing_pengetfillpath) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*src, [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*dst, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*, const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | Obtains the source path outline drawn using a pen and represents it using a destination path. | 
| void [OH_Drawing_PenReset](_drawing.md#oh_drawing_penreset) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Resets a pen to the initial value. | 
