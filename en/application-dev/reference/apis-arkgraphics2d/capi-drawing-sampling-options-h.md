# drawing_sampling_options.h

## Overview

The **drawing_sampling_options.h** file declares the functions related to sampling in the drawing module. It is used for image or texture sampling.

**Header file**: <native_drawing/drawing_sampling_options.h>

**Library**: libnative_drawing.so

**Since**: 12

**Related module**: [Drawing](capi-drawing.md)

## Total

### Enumerated value

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_Drawing_FilterMode](#oh_drawing_filtermode) | OH_Drawing_FilterMode | Defines an enum for the filter modes.|
| [OH_Drawing_MipmapMode](#oh_drawing_mipmapmode) | OH_Drawing_MipmapMode | Defines an enum for the mipmap modes.|

### Functions

| Name| Description|
| -- | -- |
| [OH_Drawing_SamplingOptions* OH_Drawing_SamplingOptionsCreate(OH_Drawing_FilterMode filterMode,OH_Drawing_MipmapMode mipmapMode)](#oh_drawing_samplingoptionscreate) | Creates an **OH_Drawing_SamplingOptions** object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If mipmapMode is not within the enumerated range, OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE is returned.|
| [OH_Drawing_SamplingOptions* OH_Drawing_SamplingOptionsCopy(OH_Drawing_SamplingOptions* samplingOptions)](#oh_drawing_samplingoptionscopy) | Creates a copy [OH_Drawing_SamplingOptions](capi-drawing-oh-drawing-samplingoptions.md) of a sampling option object.<br> This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br> If samplingOptions is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [void OH_Drawing_SamplingOptionsDestroy(OH_Drawing_SamplingOptions* samplingOptions)](#oh_drawing_samplingoptionsdestroy) | Destroys an **OH_Drawing_SamplingOptions** object and reclaims the memory occupied by the object.|

## Enum Description

### OH_Drawing_FilterMode

```
enum OH_Drawing_FilterMode
```

**Description**

Enumerates the filter modes.

**Since**: 12

| Value| Description|
| -- | -- |
| FILTER_MODE_NEAREST | Nearest filter mode.|
| FILTER_MODE_LINEAR | Linear filter mode.|

### OH_Drawing_MipmapMode

```
enum OH_Drawing_MipmapMode
```

**Description**

Enumerates the mipmap modes.

**Since**: 12

| Value| Description|
| -- | -- |
| MIPMAP_MODE_NONE | Mipmap level ignored.|
| MIPMAP_MODE_NEAREST | Nearest sampling from two adjacent mipmap levels.|
| MIPMAP_MODE_LINEAR | Linear interpolation sampling between two adjacent mipmap levels.|


## Function Description

### OH_Drawing_SamplingOptionsCreate()

```
OH_Drawing_SamplingOptions* OH_Drawing_SamplingOptionsCreate(OH_Drawing_FilterMode filterMode,OH_Drawing_MipmapMode mipmapMode)
```

**Description**

Creates an **OH_Drawing_SamplingOptions** object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If mipmapMode is not within the enumerated range, OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FilterMode](#oh_drawing_filtermode) filterMode | Sampling mode [OH_Drawing_FilterMode](capi-drawing-sampling-options-h.md#oh_drawing_filtermode).|
| [OH_Drawing_MipmapMode](#oh_drawing_mipmapmode) mipmapMode | Multi-level far-away texture sampling mode [OH_Drawing_MipmapMode](capi-drawing-sampling-options-h.md#oh_drawing_mipmapmode).|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_SamplingOptions](capi-drawing-oh-drawing-samplingoptions.md)* | A pointer to the created sampling option object [OH_Drawing_SamplingOptions](capi-drawing-oh-drawing-samplingoptions.md).|

### OH_Drawing_SamplingOptionsCopy()

```
OH_Drawing_SamplingOptions* OH_Drawing_SamplingOptionsCopy(OH_Drawing_SamplingOptions* samplingOptions)
```

**Description**

Creates a copy [OH_Drawing_SamplingOptions](capi-drawing-oh-drawing-samplingoptions.md) of a sampling option object.

This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).

If samplingOptions is null, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_SamplingOptions](capi-drawing-oh-drawing-samplingoptions.md)* samplingOptions | Pointer to the [OH_Drawing_SamplingOptions](capi-drawing-oh-drawing-samplingoptions.md) object.|

**Return value**

| Type| Description|
| -- | -- |
| OH_Drawing_SamplingOptions* | A pointer to the created sampling option object copy [OH_Drawing_SamplingOptions](capi-drawing-oh-drawing-samplingoptions.md). If NULL is returned, the creation fails. The possible cause is that the available memory is empty or samplingOptions is NULL.|

### OH_Drawing_SamplingOptionsDestroy()

```
void OH_Drawing_SamplingOptionsDestroy(OH_Drawing_SamplingOptions* samplingOptions)
```

**Description**

Destroys an **OH_Drawing_SamplingOptions** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_SamplingOptions](capi-drawing-oh-drawing-samplingoptions.md)* samplingOptions | Pointer to the [OH_Drawing_SamplingOptions](capi-drawing-oh-drawing-samplingoptions.md) object.|
