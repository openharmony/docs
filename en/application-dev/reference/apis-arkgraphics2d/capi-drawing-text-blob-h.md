# drawing_text_blob.h

## Overview

This file declares the functions related to the text blob in the drawing module.

**File to include**: <native_drawing/drawing_text_blob.h>

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](capi-drawing.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_Drawing_RunBuffer](capi-drawing-oh-drawing-runbuffer.md) | OH_Drawing_RunBuffer | Describes a run, which provides storage for glyphs and positions.|

### Functions

| Name| Description|
| -- | -- |
| [OH_Drawing_TextBlobBuilder* OH_Drawing_TextBlobBuilderCreate(void)](#oh_drawing_textblobbuildercreate) | Creates an **OH_Drawing_TextBlobBuilder** object.|
| [OH_Drawing_TextBlob* OH_Drawing_TextBlobCreateFromText(const void* text, size_t byteLength,const OH_Drawing_Font* font, OH_Drawing_TextEncoding textEncoding)](#oh_drawing_textblobcreatefromtext) | Creates an **OH_Drawing_TextBlob** object from the text.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either **text** or **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.<br>If **textEncoding** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.|
| [OH_Drawing_TextBlob* OH_Drawing_TextBlobCreateFromPosText(const void* text, size_t byteLength,OH_Drawing_Point2D* point2D, const OH_Drawing_Font* font, OH_Drawing_TextEncoding textEncoding)](#oh_drawing_textblobcreatefrompostext) | Creates an **OH_Drawing_TextBlob** object from the text. The coordinates of each character in the **OH_Drawing_TextBlob** object are determined by the coordinate information in the **OH_Drawing_Point2D** array.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If any of **text**, **point2D**, and **font** is NULL or **byteLength** is **0**, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.<br>If **textEncoding** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.|
| [OH_Drawing_TextBlob* OH_Drawing_TextBlobCreateFromString(const char* str,const OH_Drawing_Font* font, OH_Drawing_TextEncoding textEncoding)](#oh_drawing_textblobcreatefromstring) | Creates an **OH_Drawing_TextBlob** object from a string.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either **str** or **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.<br>If **textEncoding** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.|
| [void OH_Drawing_TextBlobGetBounds(OH_Drawing_TextBlob* textBlob, OH_Drawing_Rect* rect)](#oh_drawing_textblobgetbounds) | Obtains the bounds of an **OH_Drawing_TextBlob** object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either **textBlob** or **rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [uint32_t OH_Drawing_TextBlobUniqueID(const OH_Drawing_TextBlob* textBlob)](#oh_drawing_textblobuniqueid) | Obtains the unique identifier of a text blob. The identifier is a non-zero value.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **textBlob** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [const OH_Drawing_RunBuffer* OH_Drawing_TextBlobBuilderAllocRunPos(OH_Drawing_TextBlobBuilder* textBlobBuilder,const OH_Drawing_Font* font, int32_t count, const OH_Drawing_Rect* rect)](#oh_drawing_textblobbuilderallocrunpos) | Allocates a run to store glyphs and positions. The pointer returned does not need to be managed by the caller. It can no longer be used after [OH_Drawing_TextBlobBuilderMake](capi-drawing-text-blob-h.md#oh_drawing_textblobbuildermake) is called.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either **textBlobBuilder** or **font** is NULL or **count** is less than or equal to 0, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [OH_Drawing_TextBlob* OH_Drawing_TextBlobBuilderMake(OH_Drawing_TextBlobBuilder* textBlobBuilder)](#oh_drawing_textblobbuildermake) | Makes an **OH_Drawing_TextBlob** object from an **OH_Drawing_TextBlobBuilder**.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **textBlobBuilder** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_TextBlobDestroy(OH_Drawing_TextBlob* textBlob)](#oh_drawing_textblobdestroy) | Destroys an **OH_Drawing_TextBlob** object and reclaims the memory occupied by the object.|
| [void OH_Drawing_TextBlobBuilderDestroy(OH_Drawing_TextBlobBuilder* textBlobBuilder)](#oh_drawing_textblobbuilderdestroy) | Destroys an **OH_Drawing_TextBlobBuilder** object and reclaims the memory occupied by the object.|

## Function Description

### OH_Drawing_TextBlobBuilderCreate()

```
OH_Drawing_TextBlobBuilder* OH_Drawing_TextBlobBuilderCreate(void)
```

**Description**

Creates an **OH_Drawing_TextBlobBuilder** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextBlobBuilder](capi-drawing-oh-drawing-textblobbuilder.md)* | Returns the pointer to the **OH_Drawing_TextBlobBuilder** object created.|

### OH_Drawing_TextBlobCreateFromText()

```
OH_Drawing_TextBlob* OH_Drawing_TextBlobCreateFromText(const void* text, size_t byteLength,const OH_Drawing_Font* font, OH_Drawing_TextEncoding textEncoding)
```

**Description**

Creates an **OH_Drawing_TextBlob** object from the text.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either **text** or **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.<br>If **textEncoding** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const void* text | Pointer to the text.|
| size_t byteLength | Length of the text, in bytes.|
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding) textEncoding | Text encoding type [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextBlob](capi-drawing-oh-drawing-textblob.md)* | Returns a pointer to the created [OH_Drawing_TextBlob](capi-drawing-oh-drawing-textblob.md) object.|

### OH_Drawing_TextBlobCreateFromPosText()

```
OH_Drawing_TextBlob* OH_Drawing_TextBlobCreateFromPosText(const void* text, size_t byteLength,OH_Drawing_Point2D* point2D, const OH_Drawing_Font* font, OH_Drawing_TextEncoding textEncoding)
```

**Description**

Creates an **OH_Drawing_TextBlob** object from the text. The coordinates of each character in the **OH_Drawing_TextBlob** object are determined by the coordinate information in the **OH_Drawing_Point2D** array.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If any of **text**, **point2D**, and **font** is NULL or **byteLength** is **0**, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.<br>If **textEncoding** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const void* text | Pointer to the text.|
| size_t byteLength | Length of the text, in bytes.|
| [OH_Drawing_Point2D](capi-drawing-oh-drawing-point2d.md)* point2D | Pointer to the start address of the [OH_Drawing_Point2D](capi-drawing-oh-drawing-point2d.md) array. The number of entries in the array is determined by [OH_Drawing_FontCountText](capi-drawing-font-h.md#oh_drawing_fontcounttext).|
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding) textEncoding | Text encoding type [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextBlob](capi-drawing-oh-drawing-textblob.md)* | Returns a pointer to the created [OH_Drawing_TextBlob](capi-drawing-oh-drawing-textblob.md) object.|

### OH_Drawing_TextBlobCreateFromString()

```
OH_Drawing_TextBlob* OH_Drawing_TextBlobCreateFromString(const char* str,const OH_Drawing_Font* font, OH_Drawing_TextEncoding textEncoding)
```

**Description**

Creates an **OH_Drawing_TextBlob** object from a string.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either **str** or **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.<br>If **textEncoding** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char* str | Pointer to a string.|
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding) textEncoding | Text encoding type [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextBlob](capi-drawing-oh-drawing-textblob.md)* | Returns a pointer to the created [OH_Drawing_TextBlob](capi-drawing-oh-drawing-textblob.md) object.|

### OH_Drawing_TextBlobGetBounds()

```
void OH_Drawing_TextBlobGetBounds(OH_Drawing_TextBlob* textBlob, OH_Drawing_Rect* rect)
```

**Description**

Obtains the bounds of an **OH_Drawing_TextBlob** object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either **textBlob** or **rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextBlob](capi-drawing-oh-drawing-textblob.md)* textBlob | Pointer to the [OH_Drawing_TextBlob](capi-drawing-oh-drawing-textblob.md) object.|
| [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* rect | Pointer to the [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md) object. You can call [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md) to create a rectangle object.|

### OH_Drawing_TextBlobUniqueID()

```
uint32_t OH_Drawing_TextBlobUniqueID(const OH_Drawing_TextBlob* textBlob)
```

**Description**

Obtains the unique identifier of a text blob. The identifier is a non-zero value.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **textBlob** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_TextBlob](capi-drawing-oh-drawing-textblob.md)* textBlob | Pointer to the [OH_Drawing_TextBlob](capi-drawing-oh-drawing-textblob.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| uint32_t | Returns the unique identifier of the text blob.|

### OH_Drawing_TextBlobBuilderAllocRunPos()

```
const OH_Drawing_RunBuffer* OH_Drawing_TextBlobBuilderAllocRunPos(OH_Drawing_TextBlobBuilder* textBlobBuilder,const OH_Drawing_Font* font, int32_t count, const OH_Drawing_Rect* rect)
```

**Description**

Allocates a run to store glyphs and positions. The pointer returned does not need to be managed by the caller. It can no longer be used after [OH_Drawing_TextBlobBuilderMake](capi-drawing-text-blob-h.md#oh_drawing_textblobbuildermake) is called.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either **textBlobBuilder** or **font** is NULL or **count** is less than or equal to 0, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextBlobBuilder](capi-drawing-oh-drawing-textblobbuilder.md)* textBlobBuilder | Pointer to an **OH_Drawing_TextBlobBuilder** object.|
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to an **OH_Drawing_Font** object.|
| int32_t count | Number of text blobs.|
| const [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* rect | Rectangle of the text blob. The value NULL means that no rectangle is set.|

### OH_Drawing_TextBlobBuilderMake()

```
OH_Drawing_TextBlob* OH_Drawing_TextBlobBuilderMake(OH_Drawing_TextBlobBuilder* textBlobBuilder)
```

**Description**

Makes an **OH_Drawing_TextBlob** object from an **OH_Drawing_TextBlobBuilder**.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **textBlobBuilder** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextBlobBuilder](capi-drawing-oh-drawing-textblobbuilder.md)* textBlobBuilder | Pointer to an **OH_Drawing_TextBlobBuilder** object.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextBlob](capi-drawing-oh-drawing-textblob.md)* | Returns the pointer to the **OH_Drawing_TextBlob** object created.|

### OH_Drawing_TextBlobDestroy()

```
void OH_Drawing_TextBlobDestroy(OH_Drawing_TextBlob* textBlob)
```

**Description**

Destroys an **OH_Drawing_TextBlob** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextBlob](capi-drawing-oh-drawing-textblob.md)* textBlob | Pointer to an **OH_Drawing_TextBlob** object.|

### OH_Drawing_TextBlobBuilderDestroy()

```
void OH_Drawing_TextBlobBuilderDestroy(OH_Drawing_TextBlobBuilder* textBlobBuilder)
```

**Description**

Destroys an **OH_Drawing_TextBlobBuilder** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextBlobBuilder](capi-drawing-oh-drawing-textblobbuilder.md)* textBlobBuilder | Pointer to an **OH_Drawing_TextBlobBuilder** object.|
