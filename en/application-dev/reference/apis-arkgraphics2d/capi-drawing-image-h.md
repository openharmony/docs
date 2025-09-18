# drawing_image.h

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphic-->
<!--Owner: @hangmengxin-->
<!--Designer: @wangyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## Overview

The **drawing_image.h** file declares the functions related to the image in the drawing module.

**File to import**: <native_drawing/drawing_image.h>

**Library**: libnative_drawing.so

**Since**: 12

**Related module**: [Drawing](capi-drawing.md)

## Total

### Functions

| Name| Description|
| -- | -- |
| [OH_Drawing_Image* OH_Drawing_ImageCreate(void)](#oh_drawing_imagecreate) | Creates an **OH_Drawing_Image** object that describes an array of two-dimensional pixels to draw.|
| [void OH_Drawing_ImageDestroy(OH_Drawing_Image* image)](#oh_drawing_imagedestroy) | Destroys an **OH_Drawing_Image** object and reclaims the memory occupied by the object.|
| [bool OH_Drawing_ImageBuildFromBitmap(OH_Drawing_Image* image, OH_Drawing_Bitmap* bitmap)](#oh_drawing_imagebuildfrombitmap) | Builds an image from a bitmap by sharing or copying bitmap pixels. If the bitmap is marked as immutable, the pixel memory is shared instead of copied.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either image or bitmap is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [int32_t OH_Drawing_ImageGetWidth(OH_Drawing_Image* image)](#oh_drawing_imagegetwidth) | Obtains the image width, that is, the number of pixels in each line.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If image is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [int32_t OH_Drawing_ImageGetHeight(OH_Drawing_Image* image)](#oh_drawing_imagegetheight) | Obtains the image height, that is, the number of pixel lines.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If image is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [void OH_Drawing_ImageGetImageInfo(OH_Drawing_Image* image, OH_Drawing_Image_Info* imageInfo)](#oh_drawing_imagegetimageinfo) | Obtains the image information. After this function is called, the passed-in image information object is filled.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either image or imageInfo is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|

## Function Description

### OH_Drawing_ImageCreate()

```
OH_Drawing_Image* OH_Drawing_ImageCreate(void)
```

**Description**

Creates an **OH_Drawing_Image** object that describes an array of two-dimensional pixels to draw.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_Image](capi-drawing-oh-drawing-image.md)* | The function returns a pointer pointing to the created image object [OH_Drawing_Image](capi-drawing-oh-drawing-image.md).|

### OH_Drawing_ImageDestroy()

```
void OH_Drawing_ImageDestroy(OH_Drawing_Image* image)
```

**Description**

Destroys an **OH_Drawing_Image** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Image](capi-drawing-oh-drawing-image.md)* image | Pointer to the [OH_Drawing_Image](capi-drawing-oh-drawing-image.md) object.|

### OH_Drawing_ImageBuildFromBitmap()

```
bool OH_Drawing_ImageBuildFromBitmap(OH_Drawing_Image* image, OH_Drawing_Bitmap* bitmap)
```

**Description**

Builds an image from a bitmap by sharing or copying bitmap pixels. If the bitmap is marked as immutable, the pixel memory is shared instead of copied.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either image or bitmap is null, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Image](capi-drawing-oh-drawing-image.md)* image | Pointer to the [OH_Drawing_Image](capi-drawing-oh-drawing-image.md) object.|
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* bitmap | Pointer to the [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md) object.|

**Return value**

| Type| Description|
| -- | -- |
| bool | true if the image content is successfully constructed; false otherwise.|

### OH_Drawing_ImageGetWidth()

```
int32_t OH_Drawing_ImageGetWidth(OH_Drawing_Image* image)
```

**Description**

Obtains the image width, that is, the number of pixels in each line.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If image is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Image](capi-drawing-oh-drawing-image.md)* image | Pointer to the [OH_Drawing_Image](capi-drawing-oh-drawing-image.md) object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Width of the image.|

### OH_Drawing_ImageGetHeight()

```
int32_t OH_Drawing_ImageGetHeight(OH_Drawing_Image* image)
```

**Description**

Obtains the image height, that is, the number of pixel lines.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If image is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Image](capi-drawing-oh-drawing-image.md)* image | Pointer to the [OH_Drawing_Image](capi-drawing-oh-drawing-image.md) object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Image height.|

### OH_Drawing_ImageGetImageInfo()

```
void OH_Drawing_ImageGetImageInfo(OH_Drawing_Image* image, OH_Drawing_Image_Info* imageInfo)
```

**Description**

Obtains the image information. After this function is called, the passed-in image information object is filled.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either image or imageInfo is null, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Image](capi-drawing-oh-drawing-image.md)* image | Pointer to the [OH_Drawing_Image](capi-drawing-oh-drawing-image.md) object.|
| [OH_Drawing_Image_Info](capi-drawing-oh-drawing-image-info.md)* imageInfo | Pointer to the [OH_Drawing_Image_Info](capi-drawing-oh-drawing-image-info.md) object. You can create the [OH_Drawing_Image_Info](capi-drawing-oh-drawing-image-info.md) object by calling.|
