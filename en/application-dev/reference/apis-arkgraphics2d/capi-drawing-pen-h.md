# drawing_pen.h

## Overview

This file declares functions related to the pen in the drawing module.

<!--RP1-->
**Sample**: [NDKAPIDrawing (API14)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Drawing/NDKAPIDrawing)<!--RP1End-->

**File to include**: <native_drawing/drawing_pen.h>

**Library**: libnative_drawing.so

**Since**: 8

**Related module**: [Drawing](capi-drawing.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_NativeColorSpaceManager](capi-nativecolorspacemanager-oh-nativecolorspacemanager.md) | OH_NativeColorSpaceManager | Declares a color space manager object to provide the capability of obtaining basic color space attributes.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle) | OH_Drawing_PenLineCapStyle | Defines an enum for the line cap styles of a pen. The line cap style defines the style of both ends of a line segment drawn by the pen.|
| [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle) | OH_Drawing_PenLineJoinStyle | Enumerates the line join styles of a pen. The line join style defines the shape of the joints of a polyline segment drawn by the pen.|

### Functions

| Name| Description|
| -- | -- |
| [OH_Drawing_Pen* OH_Drawing_PenCreate(void)](#oh_drawing_pencreate) | Creates an **OH_Drawing_Pen** object.|
| [OH_Drawing_Pen* OH_Drawing_PenCopy(OH_Drawing_Pen* pen)](#oh_drawing_pencopy) | Creates a copy of the [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md) object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_PenDestroy(OH_Drawing_Pen* pen)](#oh_drawing_pendestroy) | Destroys an **OH_Drawing_Pen** object and reclaims the memory occupied by the object.|
| [bool OH_Drawing_PenIsAntiAlias(const OH_Drawing_Pen* pen)](#oh_drawing_penisantialias) | Checks whether anti-aliasing is enabled for a pen. Anti-aliasing makes the pixels around the shape edges semi-transparent.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_PenSetAntiAlias(OH_Drawing_Pen* pen, bool antiAlias)](#oh_drawing_pensetantialias) | Enables or disables anti-aliasing for a pen. Anti-aliasing makes the pixels around the shape edges semi-transparent.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [uint32_t OH_Drawing_PenGetColor(const OH_Drawing_Pen* pen)](#oh_drawing_pengetcolor) | Obtains the color of a pen. The color is used by the pen to outline a shape.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_PenSetColor(OH_Drawing_Pen* pen, uint32_t color)](#oh_drawing_pensetcolor) | Sets the color for a pen. The color is used by the pen to outline a shape.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [uint8_t OH_Drawing_PenGetAlpha(const OH_Drawing_Pen* pen)](#oh_drawing_pengetalpha) | Obtains the alpha value of a pen. This value is used by the alpha channel when the pen outlines a shape.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_PenSetAlpha(OH_Drawing_Pen* pen, uint8_t alpha)](#oh_drawing_pensetalpha) | Sets the alpha value for a pen. This value is used by the alpha channel when the pen outlines a shape.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [float OH_Drawing_PenGetWidth(const OH_Drawing_Pen* pen)](#oh_drawing_pengetwidth) | Obtains the thickness of a pen. This thickness determines the width of the outline of a shape.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_PenSetWidth(OH_Drawing_Pen* pen, float width)](#oh_drawing_pensetwidth) | Sets the thickness for a pen. This thickness determines the width of the outline of a shape.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [float OH_Drawing_PenGetMiterLimit(const OH_Drawing_Pen* pen)](#oh_drawing_pengetmiterlimit) | Obtains the stroke miter limit of a polyline drawn by a pen. When the corner type is bevel, a beveled corner is displayed if the miter limit is exceeded, and a mitered corner is displayed if the miter limit is not exceeded.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_PenSetMiterLimit(OH_Drawing_Pen* pen, float miter)](#oh_drawing_pensetmiterlimit) | Sets the stroke miter limit for a polyline drawn by a pen. When the corner type is bevel, a beveled corner is displayed if the miter limit is exceeded, and a mitered corner is displayed if the miter limit is not exceeded.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [OH_Drawing_PenLineCapStyle OH_Drawing_PenGetCap(const OH_Drawing_Pen* pen)](#oh_drawing_pengetcap) | Obtains the line cap style of a pen.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_PenSetCap(OH_Drawing_Pen* pen, OH_Drawing_PenLineCapStyle capStyle)](#oh_drawing_pensetcap) | Sets the line cap style for a pen.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.<br>If **capStyle** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.|
| [OH_Drawing_PenLineJoinStyle OH_Drawing_PenGetJoin(const OH_Drawing_Pen* pen)](#oh_drawing_pengetjoin) | Obtains the line join style of a pen.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_PenSetJoin(OH_Drawing_Pen* pen, OH_Drawing_PenLineJoinStyle joinStyle)](#oh_drawing_pensetjoin) | Sets the join style for this pen.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.<br>If **joinStyle** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.|
| [void OH_Drawing_PenSetShaderEffect(OH_Drawing_Pen* pen, OH_Drawing_ShaderEffect* shaderEffect)](#oh_drawing_pensetshadereffect) | Sets the shader effect for this pen.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_PenSetShadowLayer(OH_Drawing_Pen* pen, OH_Drawing_ShadowLayer* shadowLayer)](#oh_drawing_pensetshadowlayer) | Sets the shadow layer for a pen. The shadow layer effect takes effect only when text is drawn.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_PenSetPathEffect(OH_Drawing_Pen* pen, OH_Drawing_PathEffect* pathEffect)](#oh_drawing_pensetpatheffect) | Sets the path effect for this pen.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_PenSetFilter(OH_Drawing_Pen* pen, OH_Drawing_Filter* filter)](#oh_drawing_pensetfilter) | Sets a filter for a pen.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_PenGetFilter(OH_Drawing_Pen* pen, OH_Drawing_Filter* filter)](#oh_drawing_pengetfilter) | Obtains the [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md) object from the pen. The filter is a container that holds a mask filter and color filter.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either **pen** or **filter** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_PenSetBlendMode(OH_Drawing_Pen* pen, OH_Drawing_BlendMode blendMode)](#oh_drawing_pensetblendmode) | Sets a blender for a pen. The blender implements the specified blend mode.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.<br>If **blendMode** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.|
| [bool OH_Drawing_PenGetFillPath(OH_Drawing_Pen* pen, const OH_Drawing_Path* src, OH_Drawing_Path* dst,const OH_Drawing_Rect* rect, const OH_Drawing_Matrix* matrix)](#oh_drawing_pengetfillpath) | Obtains the source path outline drawn using this pen and represents it using a destination path.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If any of **pen**, **src**, and **dst** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_PenReset(OH_Drawing_Pen* pen)](#oh_drawing_penreset) | Resets a pen to the initial state.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [OH_Drawing_ErrorCode OH_Drawing_PenSetColor4f(OH_Drawing_Pen* pen, float a, float r, float g, float b,OH_NativeColorSpaceManager* colorSpaceManager)](#oh_drawing_pensetcolor4f) | Sets the color for a pen, which is used to outline a shape.<br> The color is in ARGB format represented by floating-point numbers. The color space is specified by [OH_NativeColorSpaceManager](capi-nativecolorspacemanager-oh-nativecolorspacemanager.md).<br> If **colorSpaceManager** is a null pointer, the SRGB (standard red, green, and blue color space based on IEC 61966-2.1:1999) color space is used as the default value.|
| [OH_Drawing_ErrorCode OH_Drawing_PenGetAlphaFloat(const OH_Drawing_Pen* pen, float* a)](#oh_drawing_pengetalphafloat) | Obtains the alpha value of the pen color.|
| [OH_Drawing_ErrorCode OH_Drawing_PenGetRedFloat(const OH_Drawing_Pen* pen, float* r)](#oh_drawing_pengetredfloat) | Obtains the red component of the pen color.|
| [OH_Drawing_ErrorCode OH_Drawing_PenGetGreenFloat(const OH_Drawing_Pen* pen, float* g)](#oh_drawing_pengetgreenfloat) | Obtains the green component of the pen color.|
| [OH_Drawing_ErrorCode OH_Drawing_PenGetBlueFloat(const OH_Drawing_Pen* pen, float* b)](#oh_drawing_pengetbluefloat) | Obtains the blue component of the pen color.|

## Enum Description

### OH_Drawing_PenLineCapStyle

```
enum OH_Drawing_PenLineCapStyle
```

**Description**

Enumerates the line cap styles of a pen. The line cap style defines the style of both ends of a line segment drawn by the pen.

**Since**: 8

| Enum| Description|
| -- | -- |
| LINE_FLAT_CAP | There is no cap style. Both ends of the line segment are cut off square.|
| LINE_SQUARE_CAP | Square cap style. Both ends have a square, the height of which is half of the width of the line segment, with the same width.|
| LINE_ROUND_CAP | Round cap style. Both ends have a semicircle centered, the diameter of which is the same as the width of the line segment.|

### OH_Drawing_PenLineJoinStyle

```
enum OH_Drawing_PenLineJoinStyle
```

**Description**

Enumerates the line join styles of a pen. The line join style defines the shape of the joints of a polyline segment drawn by the pen.

**Since**: 8

| Enum| Description|
| -- | -- |
| LINE_MITER_JOIN | Mitered corner. If the angle of a polyline is small, its miter length may be inappropriate. In this case, you need to use the miter limit to limit the miter length.|
| LINE_ROUND_JOIN | Round corner.|
| LINE_BEVEL_JOIN | Beveled corner.|


## Function Description

### OH_Drawing_PenCreate()

```
OH_Drawing_Pen* OH_Drawing_PenCreate(void)
```

**Description**

Creates an **OH_Drawing_Pen** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* | Returns the pointer to the **OH_Drawing_Pen** object created.|

### OH_Drawing_PenCopy()

```
OH_Drawing_Pen* OH_Drawing_PenCopy(OH_Drawing_Pen* pen)
```

**Description**

Creates a copy of the [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md) object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to an **OH_Drawing_Pen** object.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* | Returns the pointer to the [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md) object created. If NULL is returned, the creation fails. The possible failure cause is that no memory is available or **pen** is NULL.|

### OH_Drawing_PenDestroy()

```
void OH_Drawing_PenDestroy(OH_Drawing_Pen* pen)
```

**Description**

Destroys an **OH_Drawing_Pen** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to an **OH_Drawing_Pen** object.|

### OH_Drawing_PenIsAntiAlias()

```
bool OH_Drawing_PenIsAntiAlias(const OH_Drawing_Pen* pen)
```

**Description**

Checks whether anti-aliasing is enabled for a pen. Anti-aliasing makes the pixels around the shape edges semi-transparent.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to an **OH_Drawing_Pen** object.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Returns **true** if anti-aliasing is enabled; returns **false** otherwise.|

### OH_Drawing_PenSetAntiAlias()

```
void OH_Drawing_PenSetAntiAlias(OH_Drawing_Pen* pen, bool antiAlias)
```

**Description**

Enables or disables anti-aliasing for a pen. Anti-aliasing makes the pixels around the shape edges semi-transparent.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to an **OH_Drawing_Pen** object.|
| bool antiAlias | Whether to enable anti-aliasing. The value **true** means to enable anti-aliasing, and **false** means the opposite.|

### OH_Drawing_PenGetColor()

```
uint32_t OH_Drawing_PenGetColor(const OH_Drawing_Pen* pen)
```

**Description**

Obtains the color of a pen. The color is used by the pen to outline a shape.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to an **OH_Drawing_Pen** object.|

**Returns**

| Type| Description|
| -- | -- |
| uint32_t | Returns a 32-bit (ARGB) variable that describes the color.|

### OH_Drawing_PenSetColor()

```
void OH_Drawing_PenSetColor(OH_Drawing_Pen* pen, uint32_t color)
```

**Description**

Sets the color for a pen. The color is used by the pen to outline a shape.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to an **OH_Drawing_Pen** object.|
| uint32_t color | Color, which is a 32-bit (ARGB) variable.|

### OH_Drawing_PenGetAlpha()

```
uint8_t OH_Drawing_PenGetAlpha(const OH_Drawing_Pen* pen)
```

**Description**

Obtains the alpha value of a pen. This value is used by the alpha channel when the pen outlines a shape.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to an **OH_Drawing_Pen** object.|

**Returns**

| Type| Description|
| -- | -- |
| uint8_t | Returns an 8-bit variable that describes the alpha value.|

### OH_Drawing_PenSetAlpha()

```
void OH_Drawing_PenSetAlpha(OH_Drawing_Pen* pen, uint8_t alpha)
```

**Description**

Sets the alpha value for a pen. This value is used by the alpha channel when the pen outlines a shape.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to an **OH_Drawing_Pen** object.|
| uint8_t alpha | Alpha value, which is an 8-bit variable.|

### OH_Drawing_PenGetWidth()

```
float OH_Drawing_PenGetWidth(const OH_Drawing_Pen* pen)
```

**Description**

Obtains the thickness of a pen. This thickness determines the width of the outline of a shape.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to an **OH_Drawing_Pen** object.|

**Returns**

| Type| Description|
| -- | -- |
| float | Returns the thickness.|

### OH_Drawing_PenSetWidth()

```
void OH_Drawing_PenSetWidth(OH_Drawing_Pen* pen, float width)
```

**Description**

Sets the thickness for a pen. This thickness determines the width of the outline of a shape.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to an **OH_Drawing_Pen** object.|
| float width | Thickness, which is a variable.|

### OH_Drawing_PenGetMiterLimit()

```
float OH_Drawing_PenGetMiterLimit(const OH_Drawing_Pen* pen)
```

**Description**

Obtains the stroke miter limit of a polyline drawn by a pen. When the corner type is bevel, a beveled corner is displayed if the miter limit is exceeded, and a mitered corner is displayed if the miter limit is not exceeded.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to an **OH_Drawing_Pen** object.|

**Returns**

| Type| Description|
| -- | -- |
| float | Returns the miter limit.|

### OH_Drawing_PenSetMiterLimit()

```
void OH_Drawing_PenSetMiterLimit(OH_Drawing_Pen* pen, float miter)
```

**Description**

Sets the stroke miter limit for a polyline drawn by a pen. When the corner type is bevel, a beveled corner is displayed if the miter limit is exceeded, and a mitered corner is displayed if the miter limit is not exceeded.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to an **OH_Drawing_Pen** object.|
| float miter | Stroke miter limit, which is a variable.|

### OH_Drawing_PenGetCap()

```
OH_Drawing_PenLineCapStyle OH_Drawing_PenGetCap(const OH_Drawing_Pen* pen)
```

**Description**

Obtains the line cap style of a pen.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to an **OH_Drawing_Pen** object.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle) | Returns the line cap style.|

### OH_Drawing_PenSetCap()

```
void OH_Drawing_PenSetCap(OH_Drawing_Pen* pen, OH_Drawing_PenLineCapStyle capStyle)
```

**Description**

Sets the line cap style for a pen.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.<br>If **capStyle** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to an **OH_Drawing_Pen** object.|
| [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle) capStyle | Line cap style, which is a variable.|

### OH_Drawing_PenGetJoin()

```
OH_Drawing_PenLineJoinStyle OH_Drawing_PenGetJoin(const OH_Drawing_Pen* pen)
```

**Description**

Obtains the line join style of a pen.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to an **OH_Drawing_Pen** object.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle) | Returns the line join style.|

### OH_Drawing_PenSetJoin()

```
void OH_Drawing_PenSetJoin(OH_Drawing_Pen* pen, OH_Drawing_PenLineJoinStyle joinStyle)
```

**Description**

Sets the join style for this pen.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.<br>If **joinStyle** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to an **OH_Drawing_Pen** object.|
| [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle) joinStyle | Join style.|

### OH_Drawing_PenSetShaderEffect()

```
void OH_Drawing_PenSetShaderEffect(OH_Drawing_Pen* pen, OH_Drawing_ShaderEffect* shaderEffect)
```

**Description**

Sets the shader effect for this pen.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to the [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md) object.|
| [OH_Drawing_ShaderEffect](capi-drawing-oh-drawing-shadereffect.md)* shaderEffect | Pointer to an [OH_Drawing_ShaderEffect](capi-drawing-oh-drawing-shadereffect.md) object. If NULL is passed in, the shader effect will be cleared.|

### OH_Drawing_PenSetShadowLayer()

```
void OH_Drawing_PenSetShadowLayer(OH_Drawing_Pen* pen, OH_Drawing_ShadowLayer* shadowLayer)
```

**Description**

Sets the shadow layer for a pen. The shadow layer effect takes effect only when text is drawn.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to the [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md) object.|
| [OH_Drawing_ShadowLayer](capi-drawing-oh-drawing-shadowlayer.md)* shadowLayer | Pointer to an [OH_Drawing_ShadowLayer](capi-drawing-oh-drawing-shadowlayer.md) object. If NULL is passed in, the shadow layer effect will be cleared.|

### OH_Drawing_PenSetPathEffect()

```
void OH_Drawing_PenSetPathEffect(OH_Drawing_Pen* pen, OH_Drawing_PathEffect* pathEffect)
```

**Description**

Sets the path effect for this pen.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to the [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md) object.|
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)* pathEffect | Pointer to an [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md) object. If NULL is passed in, the path effect will be cleared.|

### OH_Drawing_PenSetFilter()

```
void OH_Drawing_PenSetFilter(OH_Drawing_Pen* pen, OH_Drawing_Filter* filter)
```

**Description**

Sets a filter for a pen.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to the [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md) object.|
| [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md)* filter | Pointer to an [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md) object. If NULL is passed in, the filter will be cleared.|

### OH_Drawing_PenGetFilter()

```
void OH_Drawing_PenGetFilter(OH_Drawing_Pen* pen, OH_Drawing_Filter* filter)
```

**Description**

Obtains the [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md) object from the pen. The filter is a container that holds a mask filter and color filter.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either **pen** or **filter** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to the [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md) object.|
| [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md)* filter | Pointer to an [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md) object.|

### OH_Drawing_PenSetBlendMode()

```
void OH_Drawing_PenSetBlendMode(OH_Drawing_Pen* pen, OH_Drawing_BlendMode blendMode)
```

**Description**

Sets a blender for a pen. The blender implements the specified blend mode.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.<br>If **blendMode** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to the [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md) object.|
| [OH_Drawing_BlendMode](capi-drawing-types-h.md#oh_drawing_blendmode) blendMode | Enumeration of blend modes.|

### OH_Drawing_PenGetFillPath()

```
bool OH_Drawing_PenGetFillPath(OH_Drawing_Pen* pen, const OH_Drawing_Path* src, OH_Drawing_Path* dst,const OH_Drawing_Rect* rect, const OH_Drawing_Matrix* matrix)
```

**Description**

Obtains the source path outline drawn using this pen and represents it using a destination path.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If any of **pen**, **src**, and **dst** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to the [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md) object.|
| const [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* src | Pointer to the source [OH_Drawing_Path](capi-drawing-oh-drawing-path.md) object.|
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* dst | Pointer to the target [OH_Drawing_Path](capi-drawing-oh-drawing-path.md) object.|
| const [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* rect | Pointer to an [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md) object. NULL is recommended.|
| const [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | Pointer to an [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object. NULL is recommended. The default value is an identity matrix.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Returns **true** if the destination path is obtained; returns **false** otherwise.|

### OH_Drawing_PenReset()

```
void OH_Drawing_PenReset(OH_Drawing_Pen* pen)
```

**Description**

Resets a pen to the initial state.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **pen** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to the [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md) object.|


### OH_Drawing_PenSetColor4f()

```
OH_Drawing_ErrorCode OH_Drawing_PenSetColor4f(OH_Drawing_Pen* pen, float a, float r, float g, float b,OH_NativeColorSpaceManager* colorSpaceManager)
```

**Description**

Sets the color for a pen, which is used to outline a shape.<br> The color is in ARGB format represented by floating-point numbers. The color space is specified by [OH_NativeColorSpaceManager](capi-nativecolorspacemanager-oh-nativecolorspacemanager.md).<br> If **colorSpaceManager** is a null pointer, the SRGB (standard red, green, and blue color space based on IEC 61966-2.1:1999) color space is used as the default value.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| OH_Drawing_Pen* pen | Pointer to an [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md) object.|
| float a | Alpha value of the color, which is a floating-point number ranging from 0.0 to 1.0. Values above 1.0 default to 1.0, while values below 0.0 default to 0.0.|
| float r | Red component of the color, which is a floating-point number ranging from 0.0 to 1.0. Values above 1.0 default to 1.0, while values below 0.0 default to 0.0.|
| float g | Green component of the color, which is a floating-point number ranging from 0.0 to 1.0. Values above 1.0 default to 1.0, while values below 0.0 default to 0.0.|
| float b | Blue component of the color, which is a floating-point number ranging from 0.0 to 1.0. Values above 1.0 default to 1.0, while values below 0.0 default to 0.0.|
| [OH_NativeColorSpaceManager](capi-nativecolorspacemanager-oh-nativecolorspacemanager.md)* colorSpaceManager | Pointer to an [OH_NativeColorSpaceManager](capi-nativecolorspacemanager-oh-nativecolorspacemanager.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Execution result.<br> **OH_DRAWING_SUCCESS** if the operation is successful.<br> **OH_DRAWING_ERROR_INVALID_PARAMETER** if **pen** is NULL.|

### OH_Drawing_PenGetAlphaFloat()

```
OH_Drawing_ErrorCode OH_Drawing_PenGetAlphaFloat(const OH_Drawing_Pen* pen, float* a)
```

**Description**

Obtains the alpha value of the pen color.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to an [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md) object.|
| float* a | Alpha value of the pen color. The value is a floating-point number ranging from 0.0 to 1.0.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Execution result.<br> **OH_DRAWING_SUCCESS** if the operation is successful.<br> **OH_DRAWING_ERROR_INVALID_PARAMETER** if **pen** or **a** is NULL.|

### OH_Drawing_PenGetRedFloat()

```
OH_Drawing_ErrorCode OH_Drawing_PenGetRedFloat(const OH_Drawing_Pen* pen, float* r)
```

**Description**

Obtains the red component of the pen color.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to an [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md) object.|
| float* r | Red component of the pen color. The value is a floating-point number ranging from 0.0 to 1.0.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Execution result.<br> **OH_DRAWING_SUCCESS** if the operation is successful.<br> **OH_DRAWING_ERROR_INVALID_PARAMETER** if **pen** or **r** is NULL.|

### OH_Drawing_PenGetGreenFloat()

```
OH_Drawing_ErrorCode OH_Drawing_PenGetGreenFloat(const OH_Drawing_Pen* pen, float* g)
```

**Description**

Obtains the green component of the pen color.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to an [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md) object.|
| float* g | Green component of the pen color. The value is a floating-point number ranging from 0.0 to 1.0.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Execution result.<br> **OH_DRAWING_SUCCESS** if the operation is successful.<br> **OH_DRAWING_ERROR_INVALID_PARAMETER** if **pen** or **g** is NULL.|

### OH_Drawing_PenGetBlueFloat()

```
OH_Drawing_ErrorCode OH_Drawing_PenGetBlueFloat(const OH_Drawing_Pen* pen, float* b)
```

**Description**

Obtains the blue component of the pen color.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* pen | Pointer to an [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md) object.|
| float* b | Blue component of the pen color. The value is a floating-point number ranging from 0.0 to 1.0.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Execution result.<br> **OH_DRAWING_SUCCESS** if the operation is successful.<br> **OH_DRAWING_ERROR_INVALID_PARAMETER** if **pen** or **b** is NULL.|
