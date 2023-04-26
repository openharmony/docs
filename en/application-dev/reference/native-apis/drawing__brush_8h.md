# drawing_brush.h


## Overview

Declares functions related to the **brush** object in the drawing module.

**Since:**
8

**Related Modules:**

[Drawing](_drawing.md)


## Summary


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_Drawing_BrushCreate](_drawing.md#oh_drawing_brushcreate) (void) | Creates an **OH_Drawing_Brush** object.  | 
| [OH_Drawing_BrushDestroy](_drawing.md#oh_drawing_brushdestroy) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | Destroys an **OH_Drawing_Brush** object and reclaims the memory occupied by the object.  | 
| [OH_Drawing_BrushIsAntiAlias](_drawing.md#oh_drawing_brushisantialias) (const [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | Checks whether anti-aliasing is enabled for a brush. If anti-aliasing is enabled, edges will be drawn with partial transparency.  | 
| [OH_Drawing_BrushSetAntiAlias](_drawing.md#oh_drawing_brushsetantialias) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*, bool) | Enables or disables anti-aliasing for a brush. If anti-aliasing is enabled, edges will be drawn with partial transparency.  | 
| [OH_Drawing_BrushGetColor](_drawing.md#oh_drawing_brushgetcolor) (const [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | Obtains the color of a brush. The color is used by the brush to fill in a shape.  | 
| [OH_Drawing_BrushSetColor](_drawing.md#oh_drawing_brushsetcolor) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*, uint32_t color) | Sets the color for a brush. The color will be used by the brush to fill in a shape.  | 
