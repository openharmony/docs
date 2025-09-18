# drawing_memory_stream.h

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphic-->
<!--Owner: @hangmengxin-->
<!--Designer: @wangyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## Overview

The **drawing_memory_stream.h** file declares the functions related to the memory stream in the drawing module.

**File to import**: <native_drawing/drawing_memory_stream.h>

**Library**: libnative_drawing.so

**Since**: 12

**Related module**: [Drawing](capi-drawing.md)

## Total

### Functions

| Name| Description|
| -- | -- |
| [OH_Drawing_MemoryStream* OH_Drawing_MemoryStreamCreate(const void* data, size_t length, bool copyData)](#oh_drawing_memorystreamcreate) | Creates an **OH_Drawing_MemoryStream** object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If data is null or length is 0, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [void OH_Drawing_MemoryStreamDestroy(OH_Drawing_MemoryStream* memoryStream)](#oh_drawing_memorystreamdestroy) | Destroys an **OH_Drawing_MemoryStream** object and reclaims the memory occupied by the object.|

## Function Description

### OH_Drawing_MemoryStreamCreate()

```
OH_Drawing_MemoryStream* OH_Drawing_MemoryStreamCreate(const void* data, size_t length, bool copyData)
```

**Description**

Creates an **OH_Drawing_MemoryStream** object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **data** is NULL or **length** is **0**, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const void* data | Pointer to the data.|
| size_t length | Length of the data.|
| bool copyData | Whether to copy data. true: The memory stream object copies the data segment data. false: The memory stream object uses the data segment data without copying.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_MemoryStream](capi-drawing-oh-drawing-memorystream.md)* | A pointer pointing to the created memory stream object [OH_Drawing_MemoryStream](capi-drawing-oh-drawing-memorystream.md).|

### OH_Drawing_MemoryStreamDestroy()

```
void OH_Drawing_MemoryStreamDestroy(OH_Drawing_MemoryStream* memoryStream)
```

**Description**

Destroys an **OH_Drawing_MemoryStream** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_MemoryStream](capi-drawing-oh-drawing-memorystream.md)* memoryStream | Pointer to the memory stream object [OH_Drawing_MemoryStream](capi-drawing-oh-drawing-memorystream.md).|
