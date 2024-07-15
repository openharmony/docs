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
| [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \* [OH_Drawing_BrushCopy](_drawing.md#oh_drawing_brushcopy) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*brush) | Copies an existing [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) object to create a new one.| 
| void [OH_Drawing_BrushDestroy](_drawing.md#oh_drawing_brushdestroy) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | Destroys an **OH_Drawing_Brush** object and reclaims the memory occupied by the object.| 
| bool [OH_Drawing_BrushIsAntiAlias](_drawing.md#oh_drawing_brushisantialias) (const [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | Checks whether anti-aliasing is enabled for a brush. Anti-aliasing makes the pixels around the shape edges semi-transparent.| 
| void [OH_Drawing_BrushSetAntiAlias](_drawing.md#oh_drawing_brushsetantialias) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*, bool) | Enables or disables anti-aliasing for a brush. Anti-aliasing makes the pixels around the shape edges semi-transparent.| 
| uint32_t [OH_Drawing_BrushGetColor](_drawing.md#oh_drawing_brushgetcolor) (const [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | Obtains the color of a brush. The color is used by the brush to fill in a shape.| 
| void [OH_Drawing_BrushSetColor](_drawing.md#oh_drawing_brushsetcolor) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*, uint32_t color) | Sets the color for a brush. The color is used by the brush to fill in a shape.| 
| uint8_t [OH_Drawing_BrushGetAlpha](_drawing.md#oh_drawing_brushgetalpha) (const [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | Obtains the alpha value of a brush. This value is used by the alpha channel when the brush fills in a shape.| 
| void [OH_Drawing_BrushSetAlpha](_drawing.md#oh_drawing_brushsetalpha) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*, uint8_t alpha) | Sets the alpha value for a brush. This value is used by the alpha channel when the brush fills in a shape.| 
| void [OH_Drawing_BrushSetShaderEffect](_drawing.md#oh_drawing_brushsetshadereffect) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*, [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) \*) | Sets the shader effect for a brush.| 
| void [OH_Drawing_BrushSetShadowLayer](_drawing.md#oh_drawing_brushsetshadowlayer) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*, [OH_Drawing_ShadowLayer](_drawing.md#oh_drawing_shadowlayer) \*) | Sets the shadow layer for a brush. The shadow layer effect takes effect only when text is drawn.| 
| void [OH_Drawing_BrushSetFilter](_drawing.md#oh_drawing_brushsetfilter) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*, [OH_Drawing_Filter](_drawing.md#oh_drawing_filter) \*) | Sets a filter for a brush. The filter is a container that holds a mask filter and color filter.| 
| void [OH_Drawing_BrushGetFilter](_drawing.md#oh_drawing_brushgetfilter) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*, [OH_Drawing_Filter](_drawing.md#oh_drawing_filter) \*) | Obtains the filter from a brush. The filter is a container that holds a mask filter and color filter.| 
| void [OH_Drawing_BrushSetBlendMode](_drawing.md#oh_drawing_brushsetblendmode) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*, [OH_Drawing_BlendMode](_drawing.md#oh_drawing_blendmode)) | Sets a blender for a brush. The blender implements the specified blend mode.| 
| void [OH_Drawing_BrushReset](_drawing.md#oh_drawing_brushreset) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | Resets a brush to the initial state. All configured attributes are cleared.| 
