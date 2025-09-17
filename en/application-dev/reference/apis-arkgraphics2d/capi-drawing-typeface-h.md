# drawing_typeface.h

## Overview

The **drawing_typeface.h** file declares the functions related to the typeface in the drawing module.<br>Different platforms have their own default typefaces. You can also parse the .ttf file to obtain the typefaces specified by the third party, such as SimSun and SimHei.

**Header file**: <native_drawing/drawing_typeface.h>

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](capi-drawing.md)

## Total

### Functions

| Name| Description|
| -- | -- |
| [OH_Drawing_Typeface* OH_Drawing_TypefaceCreateDefault(void)](#oh_drawing_typefacecreatedefault) | Creates a default **OH_Drawing_Typeface** object.|
| [OH_Drawing_Typeface* OH_Drawing_TypefaceCreateFromFile(const char* path, int index)](#oh_drawing_typefacecreatefromfile) | Creates an **OH_Drawing_Typeface** object through a file.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [OH_Drawing_Typeface* OH_Drawing_TypefaceCreateFromFileWithArguments(const char* path,const OH_Drawing_FontArguments* fontArguments)](#oh_drawing_typefacecreatefromfilewitharguments) | Creates an **OH_Drawing_Typeface** object with font arguments through a file.<br>If the **OH_Drawing_Typeface** object does not support the variation described in the font arguments, this function creates an **OH_Drawing_Typeface** object with the default font arguments.<br>In this case, this function provides the same functionality as [OH_Drawing_TypefaceCreateFromFile](capi-drawing-typeface-h.md#oh_drawing_typefacecreatefromfile).|
| [OH_Drawing_Typeface* OH_Drawing_TypefaceCreateFromCurrent(const OH_Drawing_Typeface* current,const OH_Drawing_FontArguments* fontArguments)](#oh_drawing_typefacecreatefromcurrent) | Creates an **OH_Drawing_Typeface** object with font arguments based on an existing **OH_Drawing_Typeface** object.|
| [OH_Drawing_Typeface* OH_Drawing_TypefaceCreateFromStream(OH_Drawing_MemoryStream* memoryStream, int32_t index)](#oh_drawing_typefacecreatefromstream) | Creates an **OH_Drawing_Typeface** object through a memory stream. If the memory stream is an invalid font file, a null pointer is returned. After the memory stream is passed in, the ownership is transferred and you cannot release it.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If memoryStream is null, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [void OH_Drawing_TypefaceDestroy(OH_Drawing_Typeface* typeface)](#oh_drawing_typefacedestroy) | Destroys an **OH_Drawing_Typeface** object and reclaims the memory occupied by the object.|
| [OH_Drawing_FontArguments* OH_Drawing_FontArgumentsCreate(void)](#oh_drawing_fontargumentscreate) | Creates an **OH_Drawing_FontArguments** object. The font arguments are used to create an **OH_Drawing_Typeface** object with custom attributes.|
| [OH_Drawing_ErrorCode OH_Drawing_FontArgumentsAddVariation(OH_Drawing_FontArguments* fontArguments,const char* axis, float value)](#oh_drawing_fontargumentsaddvariation) | Adds a variation to an **OH_Drawing_FontArguments** object.|
| [OH_Drawing_ErrorCode OH_Drawing_FontArgumentsDestroy(OH_Drawing_FontArguments* fontArguments)](#oh_drawing_fontargumentsdestroy) | Destroys an **OH_Drawing_FontArguments** object.|

## Function Description

### OH_Drawing_TypefaceCreateDefault()

```
OH_Drawing_Typeface* OH_Drawing_TypefaceCreateDefault(void)
```

**Description**

Creates a default **OH_Drawing_Typeface** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md)* | Pointer to the created font object.|

### OH_Drawing_TypefaceCreateFromFile()

```
OH_Drawing_Typeface* OH_Drawing_TypefaceCreateFromFile(const char* path, int index)
```

**Description**

Creates an **OH_Drawing_Typeface** object through a file.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **path** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char* path | Pointer to the file path.|
| int index | File index.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md)* | The function returns a pointer pointing to the created font object [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md).|

### OH_Drawing_TypefaceCreateFromFileWithArguments()

```
OH_Drawing_Typeface* OH_Drawing_TypefaceCreateFromFileWithArguments(const char* path,const OH_Drawing_FontArguments* fontArguments)
```

**Description**

Creates an **OH_Drawing_Typeface** object with font arguments through a file.<br>If the **OH_Drawing_Typeface** object does not support the variation described in the font arguments, this function creates an **OH_Drawing_Typeface** object with the default font arguments.<br>In this case, this function provides the same function as [OH_Drawing_TypefaceCreateFromFile](capi-drawing-typeface-h.md#oh_drawing_typefacecreatefromfile).

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| const char* path | Pointer to the file path.|
| const [OH_Drawing_FontArguments](capi-drawing-oh-drawing-fontarguments.md)* fontArguments | Pointer to the font parameter object [OH_Drawing_FontArguments](capi-drawing-oh-drawing-fontarguments.md).|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md)* | The function returns a pointer pointing to the created font object [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md).<br> If a null pointer is returned, the creation fails. The possible causes are as follows: No memory is available, the input file path object pointer or font parameter is empty, or the input path is invalid.|

### OH_Drawing_TypefaceCreateFromCurrent()

```
OH_Drawing_Typeface* OH_Drawing_TypefaceCreateFromCurrent(const OH_Drawing_Typeface* current,const OH_Drawing_FontArguments* fontArguments)
```

**Description**

Creates an **OH_Drawing_Typeface** object with font arguments based on an existing **OH_Drawing_Typeface** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md)* current | Pointer to the font object [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md).|
| const [OH_Drawing_FontArguments](capi-drawing-oh-drawing-fontarguments.md)* fontArguments | Pointer to the font parameter object [OH_Drawing_FontArguments](capi-drawing-oh-drawing-fontarguments.md).|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md)* | A pointer to the created font object [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md).<br> If a null pointer is returned, the creation fails. The possible causes are as follows: No memory is available. The passed file path object pointer or font parameter is null. The passed font object does not support the variable dimensions described in the font parameter object.|

### OH_Drawing_TypefaceCreateFromStream()

```
OH_Drawing_Typeface* OH_Drawing_TypefaceCreateFromStream(OH_Drawing_MemoryStream* memoryStream, int32_t index)
```

**Description**

Creates an **OH_Drawing_Typeface** object through a memory stream. If the memory stream is an invalid font file, a null pointer is returned. After the memory stream is passed in, the ownership is transferred and you cannot release it.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If memoryStream is null, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_MemoryStream](capi-drawing-oh-drawing-memorystream.md)* memoryStream | Pointer to the memory stream object [OH_Drawing_MemoryStream](capi-drawing-oh-drawing-memorystream.md).|
| int32_t index | Index of the memory stream.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md)* | Pointer to the created glyph object [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md).|

### OH_Drawing_TypefaceDestroy()

```
void OH_Drawing_TypefaceDestroy(OH_Drawing_Typeface* typeface)
```

**Description**

Destroys an **OH_Drawing_Typeface** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md)* typeface | Pointer to an **OH_Drawing_Typeface** object.|

### OH_Drawing_FontArgumentsCreate()

```
OH_Drawing_FontArguments* OH_Drawing_FontArgumentsCreate(void)
```

**Description**

Creates an **OH_Drawing_FontArguments** object. The font arguments are used to create an **OH_Drawing_Typeface** object with custom attributes.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 13

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_FontArguments](capi-drawing-oh-drawing-fontarguments.md)* | Pointer to the created glyph parameter object.|

### OH_Drawing_FontArgumentsAddVariation()

```
OH_Drawing_ErrorCode OH_Drawing_FontArgumentsAddVariation(OH_Drawing_FontArguments* fontArguments,const char* axis, float value)
```

**Description**

Adds a variation to an **OH_Drawing_FontArguments** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontArguments](capi-drawing-oh-drawing-fontarguments.md)* fontArguments | Pointer to the glyph parameter object [OH_Drawing_FontArguments](capi-drawing-oh-drawing-fontarguments.md).|
| const char* axis | Pointer to the label of the variation. The value must contain four ASCII characters. The supported labels depend on the loaded font file. For example, **'wght'** is the font weight label.|
| float value | Value of the variation label.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Returns one of the following result codes:<br> **OH_DRAWING_SUCCESS** if the operation is successful.<br> If OH_DRAWING_ERROR_INVALID_PARAMETER is returned, either fontArguments or axis is NULL, or the length of axis is not 4.|

### OH_Drawing_FontArgumentsDestroy()

```
OH_Drawing_ErrorCode OH_Drawing_FontArgumentsDestroy(OH_Drawing_FontArguments* fontArguments)
```

**Description**

Destroys an **OH_Drawing_FontArguments** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontArguments](capi-drawing-oh-drawing-fontarguments.md)* fontArguments | Pointer to the font parameter object [OH_Drawing_FontArguments](capi-drawing-oh-drawing-fontarguments.md).|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Returns one of the following result codes:<br> **OH_DRAWING_SUCCESS** if the operation is successful.<br> If OH_DRAWING_ERROR_INVALID_PARAMETER is returned, fontArguments is NULL.|
