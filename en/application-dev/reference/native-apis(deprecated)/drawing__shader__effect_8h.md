# drawing_shader_effect.h


## Overview

The **drawing_shader_effect.h** file declares the functions related to the shader effect in the drawing module.

**File to include**: &lt;native_drawing/drawing_shader_effect.h&gt;

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](_drawing.md)


## Summary


### Enums

| Name| Description|
| -------- | -------- |
| [OH_Drawing_TileMode](_drawing.md#oh_drawing_tilemode) {<br>CLAMP, REPEAT, MIRROR, DECAL<br>} | Enumerates the tile modes of the shader effect.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateLinearGradient](_drawing.md#oh_drawing_shadereffectcreatelineargradient) (const [OH_Drawing_Point](_drawing.md#oh_drawing_point) \*startPt, const [OH_Drawing_Point](_drawing.md#oh_drawing_point) \*endPt, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](_drawing.md#oh_drawing_tilemode)) | Creates an **OH_Drawing_ShaderEffect** object that generates a linear gradient between two points.|
| [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateRadialGradient](_drawing.md#oh_drawing_shadereffectcreateradialgradient) (const [OH_Drawing_Point](_drawing.md#oh_drawing_point) \*centerPt, float radius, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](_drawing.md#oh_drawing_tilemode)) | Creates an **OH_Drawing_ShaderEffect** object that generates a radial gradient based on the center and radius of a circle. The radial gradient transitions colors from the center to the ending shape in a radial manner.|
| [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateSweepGradient](_drawing.md#oh_drawing_shadereffectcreatesweepgradient) (const [OH_Drawing_Point](_drawing.md#oh_drawing_point) \*centerPt, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](_drawing.md#oh_drawing_tilemode)) | Creates an **OH_Drawing_ShaderEffect** object that generates a sweep gradient based on the center.|
| void [OH_Drawing_ShaderEffectDestroy](_drawing.md#oh_drawing_shadereffectdestroy) ([OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) \*) | Destroys an **OH_Drawing_ShaderEffect** object and reclaims the memory occupied by the object.|
