# drawing_filter.h

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphic-->
<!--Owner: @hangmengxin-->
<!--Designer: @wangyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## Overview

The **drawing_filter.h** file declares the functions related to the filter in the drawing module.

**Header file**: <native_drawing/drawing_filter.h>

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](capi-drawing.md)

## Total

### Functions

| Name| Description|
| -- | -- |
| [OH_Drawing_Filter* OH_Drawing_FilterCreate(void)](#oh_drawing_filtercreate) | Creates an **OH_Drawing_Filter** object.|
| [void OH_Drawing_FilterSetImageFilter(OH_Drawing_Filter* filter, OH_Drawing_ImageFilter* imageFilter)](#oh_drawing_filtersetimagefilter) | Sets an **OH_Drawing_ImageFilter** object for an **OH_Drawing_Filter** object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If filter is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [void OH_Drawing_FilterSetMaskFilter(OH_Drawing_Filter* filter, OH_Drawing_MaskFilter* maskFilter)](#oh_drawing_filtersetmaskfilter) | Sets an **OH_Drawing_MaskFilter** object for an **OH_Drawing_Filter** object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If filter is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [void OH_Drawing_FilterSetColorFilter(OH_Drawing_Filter* filter, OH_Drawing_ColorFilter* colorFilter)](#oh_drawing_filtersetcolorfilter) | Sets an **OH_Drawing_ColorFilter** object for an **OH_Drawing_Filter** object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If filter is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [void OH_Drawing_FilterGetColorFilter(OH_Drawing_Filter* filter, OH_Drawing_ColorFilter* colorFilter)](#oh_drawing_filtergetcolorfilter) | Obtains an **OH_Drawing_ColorFilter** object from an **OH_Drawing_Filter** object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If filter or colorFilter is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [void OH_Drawing_FilterDestroy(OH_Drawing_Filter* filter)](#oh_drawing_filterdestroy) | Destroys an **OH_Drawing_Filter** object and reclaims the memory occupied by the object.|

## Function Description

### OH_Drawing_FilterCreate()

```
OH_Drawing_Filter* OH_Drawing_FilterCreate(void)
```

**Description**

Creates an **OH_Drawing_Filter** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md)* | Pointer to the created filter object.|

### OH_Drawing_FilterSetImageFilter()

```
void OH_Drawing_FilterSetImageFilter(OH_Drawing_Filter* filter, OH_Drawing_ImageFilter* imageFilter)
```

**Description**

Sets an **OH_Drawing_ImageFilter** object for an **OH_Drawing_Filter** object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If filter is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md)* filter | Pointer to the filter object [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md).|
| [OH_Drawing_ImageFilter](capi-drawing-oh-drawing-imagefilter.md)* imageFilter | Pointer to the image filter [OH_Drawing_ImageFilter](capi-drawing-oh-drawing-imagefilter.md) object. If this parameter is NULL, the image filter effect in the filter object is cleared.|

### OH_Drawing_FilterSetMaskFilter()

```
void OH_Drawing_FilterSetMaskFilter(OH_Drawing_Filter* filter, OH_Drawing_MaskFilter* maskFilter)
```

**Description**

Sets an **OH_Drawing_MaskFilter** object for an **OH_Drawing_Filter** object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If filter is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md)* filter | Pointer to the filter object [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md).|
| [OH_Drawing_MaskFilter](capi-drawing-oh-drawing-maskfilter.md)* maskFilter | Pointer to the mask filter object [OH_Drawing_ColorFilter](capi-drawing-oh-drawing-colorfilter.md). If this parameter is NULL, the mask filter effect in the filter object is cleared.|

### OH_Drawing_FilterSetColorFilter()

```
void OH_Drawing_FilterSetColorFilter(OH_Drawing_Filter* filter, OH_Drawing_ColorFilter* colorFilter)
```

**Description**

Sets an **OH_Drawing_ColorFilter** object for an **OH_Drawing_Filter** object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If filter is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md)* filter | Pointer to the filter object [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md).|
| [OH_Drawing_ColorFilter](capi-drawing-oh-drawing-colorfilter.md)* colorFilter | Pointer to the color filter object [OH_Drawing_ColorFilter](capi-drawing-oh-drawing-colorfilter.md). If this parameter is set to NULL, the color filter effect in the filter object is cleared.|

### OH_Drawing_FilterGetColorFilter()

```
void OH_Drawing_FilterGetColorFilter(OH_Drawing_Filter* filter, OH_Drawing_ColorFilter* colorFilter)
```

**Description**

Obtains an **OH_Drawing_ColorFilter** object from an **OH_Drawing_Filter** object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either filter or colorFilter is set to NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md)* filter | Pointer to the filter object [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md).|
| [OH_Drawing_ColorFilter](capi-drawing-oh-drawing-colorfilter.md)* colorFilter | Pointer to the color filter object [OH_Drawing_ColorFilter](capi-drawing-oh-drawing-colorfilter.md).|

### OH_Drawing_FilterDestroy()

```
void OH_Drawing_FilterDestroy(OH_Drawing_Filter* filter)
```

**Description**

Destroys an **OH_Drawing_Filter** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md)* filter | Pointer to the filter object [OH_Drawing_Filter](capi-drawing-oh-drawing-filter.md).|
