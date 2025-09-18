# drawing_bitmap.h

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphic-->
<!--Owner: @hangmengxin-->
<!--Designer: @wangyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## Overview

The **drawing_bitmap.h** declares the functions related to the bitmap in the drawing module.

<!--RP1-->
**Sample**: [NDKAPIDrawing (API14)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Drawing/NDKAPIDrawing)<!--RP1End-->

**File to be included**: <native_drawing/drawing_bitmap.h>

**Library**: libnative_drawing.so

**Since**: 8

**Related module**: [Drawing](capi-drawing.md)

## Total

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_Drawing_BitmapFormat](capi-drawing-oh-drawing-bitmapformat.md) | OH_Drawing_BitmapFormat | Defines the pixel format of a bitmap, including the color type and alpha type.|

### Functions

| Name| Description|
| -- | -- |
| [OH_Drawing_Bitmap* OH_Drawing_BitmapCreate(void)](#oh_drawing_bitmapcreate) | Creates an **OH_Drawing_Bitmap** object.|
| [void OH_Drawing_BitmapDestroy(OH_Drawing_Bitmap* bitmap)](#oh_drawing_bitmapdestroy) | Destroys an **OH_Drawing_Bitmap** object and reclaims the memory occupied by the object.|
| [OH_Drawing_Bitmap* OH_Drawing_BitmapCreateFromPixels(OH_Drawing_Image_Info* imageInfo, void* pixels, uint32_t rowBytes)](#oh_drawing_bitmapcreatefrompixels) | Creates an **OH_Drawing_Bitmap** object, with the address of the memory for storing the bitmap pixels set to the memory address that you applied for.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either imageInfo or pixels is NULL or rowBytes is 0, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [void OH_Drawing_BitmapBuild(OH_Drawing_Bitmap* bitmap,const uint32_t width, const uint32_t height, const OH_Drawing_BitmapFormat* bitmapFormat)](#oh_drawing_bitmapbuild) | Initializes the width and height of a bitmap and sets the pixel format for the bitmap.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either bitmap or bitmapFormat is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [uint32_t OH_Drawing_BitmapGetWidth(OH_Drawing_Bitmap* bitmap)](#oh_drawing_bitmapgetwidth) | Obtains the width of a bitmap.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If bitmap is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [uint32_t OH_Drawing_BitmapGetHeight(OH_Drawing_Bitmap* bitmap)](#oh_drawing_bitmapgetheight) | Obtains the height of a bitmap.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If bitmap is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [OH_Drawing_ColorFormat OH_Drawing_BitmapGetColorFormat(OH_Drawing_Bitmap* bitmap)](#oh_drawing_bitmapgetcolorformat) | Obtains the pixel format of a bitmap.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If bitmap is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [OH_Drawing_AlphaFormat OH_Drawing_BitmapGetAlphaFormat(OH_Drawing_Bitmap* bitmap)](#oh_drawing_bitmapgetalphaformat) | Obtains the alpha component of a bitmap.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If bitmap is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [void* OH_Drawing_BitmapGetPixels(OH_Drawing_Bitmap* bitmap)](#oh_drawing_bitmapgetpixels) | Obtains the pixel address of a bitmap. You can use this address to obtain the pixel data of the bitmap.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If bitmap is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [void OH_Drawing_BitmapGetImageInfo(OH_Drawing_Bitmap* bitmap, OH_Drawing_Image_Info* imageInfo)](#oh_drawing_bitmapgetimageinfo) | Obtains the image information of a bitmap.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If bitmap or imageInfo is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [bool OH_Drawing_BitmapReadPixels(OH_Drawing_Bitmap* bitmap, const OH_Drawing_Image_Info* dstInfo,void* dstPixels, size_t dstRowBytes, int32_t srcX, int32_t srcY)](#oh_drawing_bitmapreadpixels) | Reads pixels of a rectangle in a bitmap to the specified buffer.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If bitmap, dstInfo, or dstPixels is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|

## Function Description

### OH_Drawing_BitmapCreate()

```
OH_Drawing_Bitmap* OH_Drawing_BitmapCreate(void)
```

**Description**

Creates an **OH_Drawing_Bitmap** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* | Pointer to the created bitmap object.|

### OH_Drawing_BitmapDestroy()

```
void OH_Drawing_BitmapDestroy(OH_Drawing_Bitmap* bitmap)
```

**Description**

Destroys an **OH_Drawing_Bitmap** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* bitmap | Pointer to an **OH_Drawing_Bitmap** object.|

### OH_Drawing_BitmapCreateFromPixels()

```
OH_Drawing_Bitmap* OH_Drawing_BitmapCreateFromPixels(OH_Drawing_Image_Info* imageInfo, void* pixels, uint32_t rowBytes)
```

**Description**

Creates an **OH_Drawing_Bitmap** object, with the address of the memory for storing the bitmap pixels set to the memory address that you applied for.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either imageInfo or pixels is null or rowBytes is 0, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Image_Info](capi-drawing-oh-drawing-image-info.md)* imageInfo | Pointer to the image information object [OH_Drawing_Image_Info](capi-drawing-oh-drawing-image-info.md).|
| void* pixels | Pointer to the start address of the memory for storing the bitmap pixels. You need to apply for the memory and ensure its validity.|
| uint32_t rowBytes | Number of bytes in each row of pixels. The value is invalid if it is less than or equal to 0.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* | A pointer to the created bitmap object [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md).|

### OH_Drawing_BitmapBuild()

```
void OH_Drawing_BitmapBuild(OH_Drawing_Bitmap* bitmap,const uint32_t width, const uint32_t height, const OH_Drawing_BitmapFormat* bitmapFormat)
```

**Description**

Initializes the width and height of a bitmap and sets the pixel format for the bitmap.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either bitmap or bitmapFormat is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* bitmap | Pointer to an **OH_Drawing_Bitmap** object.|
| const uint32_t width | Width of the bitmap to be initialized.|
| const uint32_t height | Height of the bitmap to be initialized.|
| const [OH_Drawing_BitmapFormat](capi-drawing-oh-drawing-bitmapformat.md)* bitmapFormat | Pointer to the pixel format of the bitmap to be initialized, including the pixel color type and alpha type.|

### OH_Drawing_BitmapGetWidth()

```
uint32_t OH_Drawing_BitmapGetWidth(OH_Drawing_Bitmap* bitmap)
```

**Description**

Obtains the width of a bitmap.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If bitmap is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* bitmap | Pointer to an **OH_Drawing_Bitmap** object.|

**Return value**

| Type| Description|
| -- | -- |
| uint32_t | Width of the bitmap.|

### OH_Drawing_BitmapGetHeight()

```
uint32_t OH_Drawing_BitmapGetHeight(OH_Drawing_Bitmap* bitmap)
```

**Description**

Obtains the height of a bitmap.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If bitmap is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* bitmap | Pointer to an **OH_Drawing_Bitmap** object.|

**Return value**

| Type| Description|
| -- | -- |
| uint32_t | Height of the bitmap.|

### OH_Drawing_BitmapGetColorFormat()

```
OH_Drawing_ColorFormat OH_Drawing_BitmapGetColorFormat(OH_Drawing_Bitmap* bitmap)
```

**Description**

Obtains the pixel format of a bitmap.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If bitmap is null, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* bitmap | Pointer to an **OH_Drawing_Bitmap** object.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_ColorFormat](capi-drawing-types-h.md#oh_drawing_colorformat) | Pixel storage format of the bitmap. For details about the supported formats, see [OH_Drawing_ColorFormat](capi-drawing-types-h.md#oh_drawing_colorformat).|

### OH_Drawing_BitmapGetAlphaFormat()

```
OH_Drawing_AlphaFormat OH_Drawing_BitmapGetAlphaFormat(OH_Drawing_Bitmap* bitmap)
```

**Description**

Obtains the alpha component of a bitmap.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If bitmap is null, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* bitmap | Pointer to an **OH_Drawing_Bitmap** object.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_AlphaFormat](capi-drawing-types-h.md#oh_drawing_alphaformat) | Pixel transparency component of the bitmap returned by the function. For details about the supported formats, see [OH_Drawing_AlphaFormat](capi-drawing-types-h.md#oh_drawing_alphaformat).|

### OH_Drawing_BitmapGetPixels()

```
void* OH_Drawing_BitmapGetPixels(OH_Drawing_Bitmap* bitmap)
```

**Description**

Obtains the pixel address of a bitmap. You can use this address to obtain the pixel data of the bitmap.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If bitmap is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* bitmap | Pointer to an **OH_Drawing_Bitmap** object.|

**Return value**

| Type| Description|
| -- | -- |
| void* | Pixel address of the bitmap returned by the function.|

### OH_Drawing_BitmapGetImageInfo()

```
void OH_Drawing_BitmapGetImageInfo(OH_Drawing_Bitmap* bitmap, OH_Drawing_Image_Info* imageInfo)
```

**Description**

Obtains the image information of a bitmap.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either bitmap or imageInfo is null, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* bitmap | Pointer to the [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md) object.|
| [OH_Drawing_Image_Info](capi-drawing-oh-drawing-image-info.md)* imageInfo | Pointer to the image information object [OH_Drawing_Image_Info](capi-drawing-oh-drawing-image-info.md).|

### OH_Drawing_BitmapReadPixels()

```
bool OH_Drawing_BitmapReadPixels(OH_Drawing_Bitmap* bitmap, const OH_Drawing_Image_Info* dstInfo,void* dstPixels, size_t dstRowBytes, int32_t srcX, int32_t srcY)
```

**Description**

Reads pixels of a rectangle in a bitmap to the specified buffer.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If bitmap, dstInfo, or dstPixels is null, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md)* bitmap | Pointer to the [OH_Drawing_Bitmap](capi-drawing-oh-drawing-bitmap.md) object.|
| const [OH_Drawing_Image_Info](capi-drawing-oh-drawing-image-info.md)* dstInfo | Pointer to the image information object [OH_Drawing_Image_Info](capi-drawing-oh-drawing-image-info.md).|
| void* dstPixels | Pointer to the buffer for storing the pixels read.|
| size_t dstRowBytes | Number of bytes in each row of the pixel data read. The value must be greater than or equal to the minimum number of bytes in each row in the **OH_Drawing_Image_Info** object.|
| int32_t srcX | Start X coordinate of the pixel data to read from the bitmap. The value must be less than the width of the bitmap.|
| int32_t srcY | Start Y coordinate of the pixel data to read from the bitmap. The value must be less than the height of the bitmap.|

**Return value**

| Type| Description|
| -- | -- |
| bool | Returns true if the copy is successful; false otherwise.|
