# drawing_brush.h

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphic-->
<!--Owner: @hangmengxin-->
<!--Designer: @wangyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## Overview

The **drawing_brush.h** file declares the functions related to the brush in the drawing module.

<!--RP1-->
**Sample**: [NDKAPIDrawing (API14)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Drawing/NDKAPIDrawing)<!--RP1End-->

**File to be included**: <native_drawing/drawing_brush.h>

**Library**: libnative_drawing.so

**Since**: 8

**Related module**: [Drawing](capi-drawing.md)

## Total

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_NativeColorSpaceManager](capi-nativecolorspacemanager-oh-nativecolorspacemanager.md) | OH_NativeColorSpaceManager | Declares a color space manager object to provide the capability of obtaining basic color space attributes.|

### Functions

| Name| Description|
| -- | -- |
| [OH_Drawing_Brush* OH_Drawing_BrushCreate(void)](#oh_drawing_brushcreate) | Creates an **OH_Drawing_Brush** object.|
| [OH_Drawing_Brush* OH_Drawing_BrushCopy(OH_Drawing_Brush* brush)](#oh_drawing_brushcopy) | Creates a brush object copy [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md) to copy an existing brush object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If brush is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [void OH_Drawing_BrushDestroy(OH_Drawing_Brush* brush)](#oh_drawing_brushdestroy) | Destroys an **OH_Drawing_Brush** object and reclaims the memory occupied by the object.|
| [bool OH_Drawing_BrushIsAntiAlias(const OH_Drawing_Brush* brush)](#oh_drawing_brushisantialias) | Checks whether anti-aliasing is enabled for a brush. Anti-aliasing makes the pixels around the shape edges semi-transparent.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If brush is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [void OH_Drawing_BrushSetAntiAlias(OH_Drawing_Brush* brush, bool antiAlias)](#oh_drawing_brushsetantialias) | Enables or disables anti-aliasing for a brush. Anti-aliasing makes the pixels around the shape edges semi-transparent.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If brush is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [uint32_t OH_Drawing_BrushGetColor(const OH_Drawing_Brush* brush)](#oh_drawing_brushgetcolor) | Obtains the color of a brush. The color is used by the brush to fill in a shape.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If brush is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [void OH_Drawing_BrushSetColor(OH_Drawing_Brush* brush, uint32_t color)](#oh_drawing_brushsetcolor) | Sets the color for a brush. The color is used by the brush to fill in a shape.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If brush is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [uint8_t OH_Drawing_BrushGetAlpha(const OH_Drawing_Brush* brush)](#oh_drawing_brushgetalpha) | Obtains the alpha value of a brush. This value is used by the alpha channel when the brush fills in a shape.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If brush is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [void OH_Drawing_BrushSetAlpha(OH_Drawing_Brush* brush, uint8_t alpha)](#oh_drawing_brushsetalpha) | Sets the alpha value for a brush. This value is used by the alpha channel when the brush fills in a shape.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If brush is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [void OH_Drawing_BrushSetShaderEffect(OH_Drawing_Brush* brush, OH_Drawing_ShaderEffect* shaderEffect)](#oh_drawing_brushsetshadereffect) | Sets the shader effect for a brush.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If brush is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [void OH_Drawing_BrushSetShadowLayer(OH_Drawing_Brush* brush, OH_Drawing_ShadowLayer* shadowLayer)](#oh_drawing_brushsetshadowlayer) | Sets the shadow layer for a brush. The shadow layer effect takes effect only when text is drawn.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If brush is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [void OH_Drawing_BrushSetFilter(OH_Drawing_Brush* brush, OH_Drawing_Filter* filter)](#oh_drawing_brushsetfilter) | Sets the filter [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md) for a brush. The filter is a container that holds a mask filter and color filter.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If brush is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [void OH_Drawing_BrushGetFilter(OH_Drawing_Brush* brush, OH_Drawing_Filter* filter)](#oh_drawing_brushgetfilter) | Obtains the filter [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md) from the brush. The filter is a container that holds a mask filter and color filter.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either brush or filter is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [void OH_Drawing_BrushSetBlendMode(OH_Drawing_Brush* brush, OH_Drawing_BlendMode blendMode)](#oh_drawing_brushsetblendmode) | Sets a blender for a brush. The blender implements the specified blend mode.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If brush is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.<br>If **blendMode** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.|
| [void OH_Drawing_BrushReset(OH_Drawing_Brush* brush)](#oh_drawing_brushreset) | Resets a brush to the initial state. All configured attributes are cleared.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If brush is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [OH_Drawing_ErrorCode OH_Drawing_BrushSetColor4f(OH_Drawing_Brush* brush, float a, float r, float g, float b,OH_NativeColorSpaceManager* colorSpaceManager)](#oh_drawing_brushsetcolor4f) | Sets a color for this brush. The color is used by the brush to fill the shape.<br> The color is in ARGB format represented by floating-point numbers. The color space is specified by [OH_NativeColorSpaceManager](capi-nativecolorspacemanager-oh-nativecolorspacemanager.md).<br> If **colorSpaceManager** is a null pointer, the SRGB (standard red, green, and blue color space based on IEC 61966-2.1:1999) color space is used as the default value.|
| [OH_Drawing_ErrorCode OH_Drawing_BrushGetAlphaFloat(const OH_Drawing_Brush* brush, float* a)](#oh_drawing_brushgetalphafloat) | Obtains the transparency value of the brush color.|
| [OH_Drawing_ErrorCode OH_Drawing_BrushGetRedFloat(const OH_Drawing_Brush* brush, float* r)](#oh_drawing_brushgetredfloat) | Obtains the red component of the brush color.|
| [OH_Drawing_ErrorCode OH_Drawing_BrushGetGreenFloat(const OH_Drawing_Brush* brush, float* g)](#oh_drawing_brushgetgreenfloat) | Obtains the green component of the brush color.|
| [OH_Drawing_ErrorCode OH_Drawing_BrushGetBlueFloat(const OH_Drawing_Brush* brush, float* b)](#oh_drawing_brushgetbluefloat) | Obtains the blue component of the brush color.|

## Function Description

### OH_Drawing_BrushCreate()

```
OH_Drawing_Brush* OH_Drawing_BrushCreate(void)
```

**Description**

Creates an **OH_Drawing_Brush** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* | Pointer to the created brush object.|

### OH_Drawing_BrushCopy()

```
OH_Drawing_Brush* OH_Drawing_BrushCopy(OH_Drawing_Brush* brush)
```

**Description**

Creates a brush object copy [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md) to copy an existing brush object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* brush | Pointer to an **OH_Drawing_Brush** object.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* | The function returns a pointer pointing to the created brush object copy [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md). If NULL is returned, the creation fails. The possible cause is that the available memory is empty or brush is NULL.|

### OH_Drawing_BrushDestroy()

```
void OH_Drawing_BrushDestroy(OH_Drawing_Brush* brush)
```

**Description**

Destroys an **OH_Drawing_Brush** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* brush | Pointer to an **OH_Drawing_Brush** object.|

### OH_Drawing_BrushIsAntiAlias()

```
bool OH_Drawing_BrushIsAntiAlias(const OH_Drawing_Brush* brush)
```

**Description**

Checks whether anti-aliasing is enabled for a brush. Anti-aliasing makes the pixels around the shape edges semi-transparent.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* brush | Pointer to an **OH_Drawing_Brush** object.|

**Return value**

| Type| Description|
| -- | -- |
| bool | Whether anti-aliasing is set for the brush object. If true is returned, anti-aliasing is set. If false is returned, anti-aliasing is not set.|

### OH_Drawing_BrushSetAntiAlias()

```
void OH_Drawing_BrushSetAntiAlias(OH_Drawing_Brush* brush, bool antiAlias)
```

**Description**

Enables or disables anti-aliasing for a brush. Anti-aliasing makes the pixels around the shape edges semi-transparent.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* brush | Pointer to an **OH_Drawing_Brush** object.|
| bool antiAlias | Whether to enable anti-aliasing. The value **true** means to enable anti-aliasing, and **false** means the opposite.|

### OH_Drawing_BrushGetColor()

```
uint32_t OH_Drawing_BrushGetColor(const OH_Drawing_Brush* brush)
```

**Description**

Obtains the color of a brush. The color is used by the brush to fill in a shape.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* brush | Pointer to an **OH_Drawing_Brush** object.|

**Return value**

| Type| Description|
| -- | -- |
| uint32_t | Returns a 32-bit (ARGB) variable that describes the color.|

### OH_Drawing_BrushSetColor()

```
void OH_Drawing_BrushSetColor(OH_Drawing_Brush* brush, uint32_t color)
```

**Description**

Sets the color for a brush. The color is used by the brush to fill in a shape.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* brush | Pointer to an **OH_Drawing_Brush** object.|
| uint32_t color | Color, which is a 32-bit (ARGB) variable.|

### OH_Drawing_BrushGetAlpha()

```
uint8_t OH_Drawing_BrushGetAlpha(const OH_Drawing_Brush* brush)
```

**Description**

Obtains the alpha value of a brush. This value is used by the alpha channel when the brush fills in a shape.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* brush | Pointer to an **OH_Drawing_Brush** object.|

**Return value**

| Type| Description|
| -- | -- |
| uint8_t | An 8-bit variable used to indicate the transparency value.|

### OH_Drawing_BrushSetAlpha()

```
void OH_Drawing_BrushSetAlpha(OH_Drawing_Brush* brush, uint8_t alpha)
```

**Description**

Sets the alpha value for a brush. This value is used by the alpha channel when the brush fills in a shape.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* brush | Pointer to an **OH_Drawing_Brush** object.|
| uint8_t alpha | Alpha value, which is an 8-bit variable.|

### OH_Drawing_BrushSetShaderEffect()

```
void OH_Drawing_BrushSetShaderEffect(OH_Drawing_Brush* brush, OH_Drawing_ShaderEffect* shaderEffect)
```

**Description**

Sets the shader effect for a brush.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* brush | Pointer to an **OH_Drawing_Brush** object.|
| [OH_Drawing_ShaderEffect](capi-drawing-oh-drawing-shadereffect.md)* shaderEffect | Pointer to an **OH_Drawing_ShaderEffect** object. If NULL is passed in, the shader effect of the brush will be cleared.|

### OH_Drawing_BrushSetShadowLayer()

```
void OH_Drawing_BrushSetShadowLayer(OH_Drawing_Brush* brush, OH_Drawing_ShadowLayer* shadowLayer)
```

**Description**

Sets the shadow layer for a brush. The shadow layer effect takes effect only when text is drawn.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* brush | Pointer to an **OH_Drawing_Brush** object.|
| [OH_Drawing_ShadowLayer](capi-drawing-oh-drawing-shadowlayer.md)* shadowLayer | Pointer to an **OH_Drawing_ShadowLayer** object. If NULL is passed in, the shadow layer effect of the brush will be cleared.|

### OH_Drawing_BrushSetFilter()

```
void OH_Drawing_BrushSetFilter(OH_Drawing_Brush* brush, OH_Drawing_Filter* filter)
```

**Description**

Sets the filter [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md) for a brush. The filter is a container that holds a mask filter and color filter.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* brush | Pointer to an **OH_Drawing_Brush** object.|
| [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md)* filter | Pointer to an **OH_Drawing_Filter** object. If null is passed in, the filter will be cleared.|

### OH_Drawing_BrushGetFilter()

```
void OH_Drawing_BrushGetFilter(OH_Drawing_Brush* brush, OH_Drawing_Filter* filter)
```

**Description**

Obtains the filter [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md) from the brush. The filter is a container that holds a mask filter and color filter.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either brush or filter is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* brush | Pointer to the [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md) object.|
| [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md)* filter | Pointer to the filter object [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md).|

### OH_Drawing_BrushSetBlendMode()

```
void OH_Drawing_BrushSetBlendMode(OH_Drawing_Brush* brush, OH_Drawing_BlendMode blendMode)
```

**Description**

Sets a blender for a brush. The blender implements the specified blend mode.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If brush is null, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.<br>If **blendMode** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* brush | Pointer to the [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md) object.|
| [OH_Drawing_BlendMode](capi-drawing-types-h.md#oh_drawing_blendmode) blendMode | Enumeration of blend modes.|

### OH_Drawing_BrushReset()

```
void OH_Drawing_BrushReset(OH_Drawing_Brush* brush)
```

**Description**

Resets a brush to the initial state. All configured attributes are cleared.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **brush** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* brush | Pointer to the [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md) object.|


### OH_Drawing_BrushSetColor4f()

```
OH_Drawing_ErrorCode OH_Drawing_BrushSetColor4f(OH_Drawing_Brush* brush, float a, float r, float g, float b,OH_NativeColorSpaceManager* colorSpaceManager)
```

**Description**

Sets a color for this brush. The color is used by the brush to fill the shape.<br> The color is in ARGB format represented by floating-point numbers. The color space is specified by [OH_NativeColorSpaceManager](capi-nativecolorspacemanager-oh-nativecolorspacemanager.md).<br> If **colorSpaceManager** is a null pointer, the SRGB (standard red, green, and blue color space based on IEC 61966-2.1:1999) color space is used as the default value.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| OH_Drawing_Brush* brush | Pointer to the [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md) object.|
| float a | Alpha value of the color, which is a floating-point number ranging from 0.0 to 1.0. Values above 1.0 default to 1.0, while values below 0.0 default to 0.0.|
| float r | Red component of the color, which is a floating-point number ranging from 0.0 to 1.0. Values above 1.0 default to 1.0, while values below 0.0 default to 0.0.|
| float g | Green component of the color, which is a floating-point number ranging from 0.0 to 1.0. Values above 1.0 default to 1.0, while values below 0.0 default to 0.0.|
| float b | Blue component of the color, which is a floating-point number ranging from 0.0 to 1.0. Values above 1.0 default to 1.0, while values below 0.0 default to 0.0.|
| [OH_NativeColorSpaceManager](capi-nativecolorspacemanager-oh-nativecolorspacemanager.md)* colorSpaceManager | Pointer to an [OH_NativeColorSpaceManager](capi-nativecolorspacemanager-oh-nativecolorspacemanager.md) object.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Execution result.<br> **OH_DRAWING_SUCCESS** if the operation is successful.<br> OH_DRAWING_ERROR_INVALID_PARAMETER: The brush parameter is NULL.|

### OH_Drawing_BrushGetAlphaFloat()

```
OH_Drawing_ErrorCode OH_Drawing_BrushGetAlphaFloat(const OH_Drawing_Brush* brush, float* a)
```

**Description**

Obtains the alpha value of a brush color.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* brush | Pointer to the [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md) object.|
| float* a | Indicates the transparency of a color. The value is a floating point number ranging from 0.0 to 1.0.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Execution result.<br> **OH_DRAWING_SUCCESS** if the operation is successful.<br> OH_DRAWING_ERROR_INVALID_PARAMETER: The brush or a parameter is null.|

### OH_Drawing_BrushGetRedFloat()

```
OH_Drawing_ErrorCode OH_Drawing_BrushGetRedFloat(const OH_Drawing_Brush* brush, float* r)
```

**Description**

Obtains the red component of the brush color.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* brush | Pointer to the [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md) object.|
| float* r | Red component of the pen color. The value is a floating-point number ranging from 0.0 to 1.0.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Execution result.<br> **OH_DRAWING_SUCCESS** if the operation is successful.<br> OH_DRAWING_ERROR_INVALID_PARAMETER: The brush or r parameter is null.|

### OH_Drawing_BrushGetGreenFloat()

```
OH_Drawing_ErrorCode OH_Drawing_BrushGetGreenFloat(const OH_Drawing_Brush* brush, float* g)
```

**Description**

Obtains the green component of the brush color.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* brush | Pointer to the [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md) object.|
| float* g | Green component of the pen color. The value is a floating-point number ranging from 0.0 to 1.0.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Execution result.<br> **OH_DRAWING_SUCCESS** if the operation is successful.<br> OH_DRAWING_ERROR_INVALID_PARAMETER: The brush or g parameter is null.|

### OH_Drawing_BrushGetBlueFloat()

```
OH_Drawing_ErrorCode OH_Drawing_BrushGetBlueFloat(const OH_Drawing_Brush* brush, float* b)
```

**Description**

Obtains the blue component of the brush color.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* brush | Pointer to the [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md) object.|
| float* b | Blue component of the pen color. The value is a floating-point number ranging from 0.0 to 1.0.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Execution result.<br> **OH_DRAWING_SUCCESS** if the operation is successful.<br> If OH_DRAWING_ERROR_INVALID_PARAMETER is returned, the brush or b parameter is null.|
