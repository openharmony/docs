# drawing_brush.h


## Overview

The **drawing_brush.h** file declares the functions related to the brush in the drawing module.

**File to include**: &lt;native_drawing/drawing_brush.h&gt;

**Library**: libnative_drawing.so

**Since**: 8

**Related module**: [Drawing](_drawing.md)


## Summary


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \* [OH_Drawing_BrushCreate](_drawing.md#oh_drawing_brushcreate) (void) | Creates an **OH_Drawing_Brush** object.|
| void [OH_Drawing_BrushDestroy](_drawing.md#oh_drawing_brushdestroy) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | Destroys an **OH_Drawing_Brush** object and reclaims the memory occupied by the object.|
| bool [OH_Drawing_BrushIsAntiAlias](_drawing.md#oh_drawing_brushisantialias) (const [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | Checks whether anti-aliasing is enabled for a brush. Anti-aliasing makes the pixels around the shape edges semi-transparent.|
| void [OH_Drawing_BrushSetAntiAlias](_drawing.md#oh_drawing_brushsetantialias) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*, bool) | Enables or disables anti-aliasing for a brush. Anti-aliasing makes the pixels around the shape edges semi-transparent.|
| uint32_t [OH_Drawing_BrushGetColor](_drawing.md#oh_drawing_brushgetcolor) (const [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | Obtains the color of a brush. The color is used by the brush to fill in a shape.|
| void [OH_Drawing_BrushSetColor](_drawing.md#oh_drawing_brushsetcolor) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*, uint32_t color) | Sets the color for a brush. The color is used by the brush to fill in a shape.|
