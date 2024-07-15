# drawing_shader_effect.h


## Overview

The **drawing_shader_effect.h** file declares the functions related to the shader effect in the drawing module.

**File to include**: &lt;native_drawing/drawing_shader_effect.h&gt;

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](_drawing.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [OH_Drawing_TileMode](_drawing.md#oh_drawing_tilemode)  [OH_Drawing_TileMode](_drawing.md#oh_drawing_tilemode) | Defines an enum for tile modes of the shader effect.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_TileMode](_drawing.md#oh_drawing_tilemode) { CLAMP, REPEAT, MIRROR, DECAL } | Enumerates the tile modes of the shader effect.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateColorShader](_drawing.md#oh_drawing_shadereffectcreatecolorshader) (const uint32_t color) | Creates an **OH_Drawing_ShaderEffect** object with a single color.| 
| [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateLinearGradient](_drawing.md#oh_drawing_shadereffectcreatelineargradient) (const [OH_Drawing_Point](_drawing.md#oh_drawing_point) \*startPt, const [OH_Drawing_Point](_drawing.md#oh_drawing_point) \*endPt, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](_drawing.md#oh_drawing_tilemode)) | Creates an **OH_Drawing_ShaderEffect** object that generates a linear gradient between two points.| 
| [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateLinearGradientWithLocalMatrix](_drawing.md#oh_drawing_shadereffectcreatelineargradientwithlocalmatrix) (const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*startPt, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*endPt, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](_drawing.md#oh_drawing_tilemode), const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | Creates an **OH_Drawing_ShaderEffect** object that generates a linear gradient between two points.|
| [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateRadialGradient](_drawing.md#oh_drawing_shadereffectcreateradialgradient) (const [OH_Drawing_Point](_drawing.md#oh_drawing_point) \*centerPt, float radius, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](_drawing.md#oh_drawing_tilemode)) | Creates an **OH_Drawing_ShaderEffect** object that generates a radial gradient based on the center and radius of a circle. The radial gradient transitions colors from the center to the ending shape in a radial manner.| 
| [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateRadialGradientWithLocalMatrix](_drawing.md#oh_drawing_shadereffectcreateradialgradientwithlocalmatrix) (const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*centerPt, float radius, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](_drawing.md#oh_drawing_tilemode), const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | Creates an **OH_Drawing_ShaderEffect** object that generates a radial gradient based on the center and radius of a circle. The radial gradient transitions colors from the center to the ending shape in a radial manner.| 
| [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateSweepGradient](_drawing.md#oh_drawing_shadereffectcreatesweepgradient) (const [OH_Drawing_Point](_drawing.md#oh_drawing_point) \*centerPt, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](_drawing.md#oh_drawing_tilemode)) | Creates an **OH_Drawing_ShaderEffect** object that generates a sweep gradient based on the center. A sweep gradient paints a gradient in a sweeping arc ranging from 0° to 360°.| 
| [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateImageShader](_drawing.md#oh_drawing_shadereffectcreateimageshader) ([OH_Drawing_Image](_drawing.md#oh_drawing_image) \*, [OH_Drawing_TileMode](_drawing.md#oh_drawing_tilemode) tileX, [OH_Drawing_TileMode](_drawing.md#oh_drawing_tilemode) tileY, const [OH_Drawing_SamplingOptions](_drawing.md#oh_drawing_samplingoptions) \*, const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | Creates an **OH_Drawing_ShaderEffect** object for an image shader. You are advised not to use the API for the canvas of the capture type because it affects the performance.| 
| [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateTwoPointConicalGradient](_drawing.md#oh_drawing_shadereffectcreatetwopointconicalgradient) (const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*startPt, float startRadius, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*endPt, float endRadius, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](_drawing.md#oh_drawing_tilemode), const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | Creates an **OH_Drawing_ShaderEffect** object that generates a gradient between two given circles.| 
| void [OH_Drawing_ShaderEffectDestroy](_drawing.md#oh_drawing_shadereffectdestroy) ([OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) \*) | Destroys an **OH_Drawing_ShaderEffect** object and reclaims the memory occupied by the object.| 
