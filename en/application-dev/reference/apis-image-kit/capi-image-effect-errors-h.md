# image_effect_errors.h

## Overview

The file declares the error codes used by the image effector.

**Library**: libimage_effect.so

**File to include**: <multimedia/image_effect/image_effect_errors.h>

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Related module**: [ImageEffect](capi-imageeffect.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ImageEffect_ErrorCode](#imageeffect_errorcode) | ImageEffect_ErrorCode | Enumerates the error codes used by the image effector.|

## Enum Description

### ImageEffect_ErrorCode

```
enum ImageEffect_ErrorCode
```

**Description**

Enumerates the error codes used by the image effector.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

| Enum Item| Description|
| -- | -- |
| EFFECT_SUCCESS = 0 | The operation is successful.|
| EFFECT_ERROR_PERMISSION_DENIED = 201 | Permission verification fails.|
| EFFECT_ERROR_PARAM_INVALID = 401 | Parameter check fails.|
| EFFECT_BUFFER_SIZE_NOT_MATCH = 29000001 | The output buffer size does not match.|
| EFFECT_COLOR_SPACE_NOT_MATCH = 29000002 | The input and output color spaces do not match.|
| EFFECT_INPUT_OUTPUT_NOT_MATCH = 29000101 | The input and output configurations do not match. For example, the input is a surface, but the output is a PixelMap.|
| EFFECT_EFFECT_NUMBER_LIMITED = 29000102 | The maximum number is reached.|
| EFFECT_INPUT_OUTPUT_NOT_SUPPORTED = 29000103 | The input or output configuration is not supported.|
| EFFECT_ALLOCATE_MEMORY_FAILED = 29000104 | Memory allocation fails.|
| EFFECT_PARAM_ERROR = 29000121 | Invalid parameter value. For example, the filter parameter value is invalid.|
| EFFECT_KEY_ERROR = 29000122 | Invalid parameter. For example, the filter parameter is invalid.|
| EFFECT_UNKNOWN = 29000199 | Undefined error.|
