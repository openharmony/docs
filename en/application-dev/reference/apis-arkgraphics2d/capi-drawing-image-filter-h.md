# drawing_image_filter.h

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphic-->
<!--Owner: @hangmengxin-->
<!--Designer: @wangyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## Overview

The **drawing_image_filter.h** file declares the functions related to the image filter in the drawing module.

**Header file**: <native_drawing/drawing_image_filter.h>

**Library**: libnative_drawing.so

**Since**: 12

**Related module**: [Drawing](capi-drawing.md)

## Total

### Functions

| Name| Description|
| -- | -- |
| [OH_Drawing_ImageFilter* OH_Drawing_ImageFilterCreateBlur(float sigmaX, float sigmaY, OH_Drawing_TileMode tileMode,OH_Drawing_ImageFilter* imageFilter)](#oh_drawing_imagefiltercreateblur) | Creates an **OH_Drawing_ImageFilter** object with a given blur type.|
| [OH_Drawing_ImageFilter* OH_Drawing_ImageFilterCreateBlurWithCrop(float sigmaX, float sigmaY,OH_Drawing_TileMode tileMode, OH_Drawing_ImageFilter* input, const OH_Drawing_Rect* rect)](#oh_drawing_imagefiltercreateblurwithcrop) | Creates an image filter with a given blur effect.<br> You can specify a cropping rectangle to limit the blur effect to take effect only in the specified rectangle area of the image.​ |
| [OH_Drawing_ImageFilter* OH_Drawing_ImageFilterCreateFromColorFilter(OH_Drawing_ColorFilter* colorFilter,OH_Drawing_ImageFilter* imageFilter)](#oh_drawing_imagefiltercreatefromcolorfilter) | Creates an **OH_Drawing_ImageFilter** object with a color filter effect. This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget). If colorFilter is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [OH_Drawing_ImageFilter* OH_Drawing_ImageFilterCreateOffset(float x, float y, OH_Drawing_ImageFilter* imageFilter)](#oh_drawing_imagefiltercreateoffset) | Creates an offset filter to translate the input filter according to the specified vector.|
| [OH_Drawing_ImageFilter* OH_Drawing_ImageFilterCreateFromShaderEffect(OH_Drawing_ShaderEffect* shaderEffect)](#oh_drawing_imagefiltercreatefromshadereffect) | Creates an image filter based on a shader.|
| [void OH_Drawing_ImageFilterDestroy(OH_Drawing_ImageFilter* imageFilter)](#oh_drawing_imagefilterdestroy) | Destroys an **OH_Drawing_ImageFilter** object and reclaims the memory occupied by the object.|

## Function Description

### OH_Drawing_ImageFilterCreateBlur()

```
OH_Drawing_ImageFilter* OH_Drawing_ImageFilterCreateBlur(float sigmaX, float sigmaY, OH_Drawing_TileMode tileMode,OH_Drawing_ImageFilter* imageFilter)
```

**Description**

Creates an image filter with a given blur effect.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| float sigmaX | Standard deviation of the Gaussian blur to apply along the X axis. The value must be greater than 0.|
| float sigmaY | Standard deviation of the Gaussian blur to apply along the Y axis. The value must be greater than 0.|
| [OH_Drawing_TileMode](capi-drawing-shader-effect-h.md#oh_drawing_tilemode) tileMode | Tile mode of the image filter effect. For details about the supported modes, see [OH_Drawing_TileMode](capi-drawing-shader-effect-h.md#oh_drawing_tilemode).|
| [OH_Drawing_ImageFilter](capi-drawing-oh-drawing-imagefilter.md)* imageFilter | Pointer to the filter to which the image filter will be applied. If NULL is passed in, the image filter is directly applied to the original image.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_ImageFilter](capi-drawing-oh-drawing-imagefilter.md)* | A pointer pointing to the created image filter object [OH_Drawing_ImageFilter](capi-drawing-oh-drawing-imagefilter.md). If NULL is returned, the creation fails. The possible failure cause is that no memory is available.|

### OH_Drawing_ImageFilterCreateBlurWithCrop()

```
OH_Drawing_ImageFilter* OH_Drawing_ImageFilterCreateBlurWithCrop(float sigmaX, float sigmaY, OH_Drawing_TileMode tileMode, OH_Drawing_ImageFilter* input, const OH_Drawing_Rect* rect)
```

**Description**

Creates an image filter with a given blur effect.

You can pass a cropping rectangle to restrict the blur effect to take effect only in the specified rectangle area of the image.​

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| float sigmaX | Standard deviation of Gaussian blur along the x axis. The value must be greater than 0.0.|
| float sigmaY | Standard deviation of Gaussian blur along the y axis. The value must be greater than 0.0.|
| [OH_Drawing_TileMode](capi-drawing-shader-effect-h.md#oh_drawing_tilemode) tileMode | Tile mode of the image filter effect. For details about the supported modes, see [OH_Drawing_TileMode](capi-drawing-shader-effect-h.md#oh_drawing_tilemode).|
| [OH_Drawing_ImageFilter](capi-drawing-oh-drawing-imagefilter.md)* input | Pointer to the filter to which the image filter will be applied. If NULL is passed in, the image filter is directly applied to the original image.|
| [const OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* rect | Cropping rectangle. If the value is NULL, the blur effect is directly applied to the entire image.|

**Return value**

| Type| Description|
| -- | -- |
| OH_Drawing_ImageFilter* | A pointer to the created image filter object [OH_Drawing_ImageFilter](capi-drawing-oh-drawing-imagefilter.md). If NULL is returned, the creation fails. The possible failure cause is that no memory is available.|

### OH_Drawing_ImageFilterCreateFromColorFilter()

```
OH_Drawing_ImageFilter* OH_Drawing_ImageFilterCreateFromColorFilter(OH_Drawing_ColorFilter* colorFilter,OH_Drawing_ImageFilter* imageFilter)
```

**Description**

Creates an **OH_Drawing_ImageFilter** object with a color filter effect. This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget). If **colorFilter** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_ColorFilter](capi-drawing-oh-drawing-colorfilter.md)* colorFilter | Pointer to the color filter object [OH_Drawing_ColorFilter](capi-drawing-oh-drawing-colorfilter.md) with the color transformation effect.|
| [OH_Drawing_ImageFilter](capi-drawing-oh-drawing-imagefilter.md)* imageFilter | Pointer to the filter to which the image filter will be applied. If NULL is passed in, the image filter is directly applied to the original image.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_ImageFilter](capi-drawing-oh-drawing-imagefilter.md)* | Pointer to the created image filter object [OH_Drawing_ImageFilter](capi-drawing-oh-drawing-imagefilter.md). If NULL is returned, the creation fails. The possible cause is that the available memory is empty or colorFilter is NULL.|

### OH_Drawing_ImageFilterCreateOffset()

```
OH_Drawing_ImageFilter* OH_Drawing_ImageFilterCreateOffset(float x, float y, OH_Drawing_ImageFilter* imageFilter)
```

**Description**

Creates an offset filter to translate the input filter based on the specified vector.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| float x | Horizontal shift distance.|
| float y | Vertical shift distance.|
| [OH_Drawing_ImageFilter](capi-drawing-oh-drawing-imagefilter.md)* imageFilter | Filter to be shifted. If the filter is empty, the drawing result without the filtering effect is shifted.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_ImageFilter](capi-drawing-oh-drawing-imagefilter.md)* | A pointer to the created image filter object [OH_Drawing_ImageFilter](capi-drawing-oh-drawing-imagefilter.md). If NULL is returned, the creation fails. The possible cause is that the available memory is empty.|

### OH_Drawing_ImageFilterCreateFromShaderEffect()

```
OH_Drawing_ImageFilter* OH_Drawing_ImageFilterCreateFromShaderEffect(OH_Drawing_ShaderEffect* shaderEffect)
```

**Description**

Creates an **ImageFilter** object based on a shader.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_ShaderEffect](capi-drawing-oh-drawing-shadereffect.md)* shaderEffect | Shader effect to be applied to the image.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_ImageFilter](capi-drawing-oh-drawing-imagefilter.md)* | A pointer to the created image filter object [OH_Drawing_ImageFilter](capi-drawing-oh-drawing-imagefilter.md). If NULL is returned, the creation fails. The possible cause is that the available memory is empty.|

### OH_Drawing_ImageFilterDestroy()

```
void OH_Drawing_ImageFilterDestroy(OH_Drawing_ImageFilter* imageFilter)
```

**Description**

Destroys an **OH_Drawing_ImageFilter** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_ImageFilter](capi-drawing-oh-drawing-imagefilter.md)* imageFilter | Pointer to the image filter object [OH_Drawing_ImageFilter](capi-drawing-oh-drawing-imagefilter.md).|
