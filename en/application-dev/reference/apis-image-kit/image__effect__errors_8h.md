# image_effect_errors.h


## Overview

The **image_effect_errors.h** file declares the error codes used by the image effector.

**Library**: libimage_effect.so

**File to include**: &lt;multimedia/image_effect/image_effect_errors.h&gt;

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Related module**: [ImageEffect](_image_effect.md)


## Summary


### Types

| Name| Description|
| -------- | -------- |
| typedef enum [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode-1) [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) | Defines an enum for the error codes used by the image effector.|


### Enums

| Name| Description|
| -------- | -------- |
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode-1) {<br>EFFECT_SUCCESS = 0, EFFECT_ERROR_PERMISSION_DENIED = 201,<br>EFFECT_ERROR_PARAM_INVALID = 401, EFFECT_BUFFER_SIZE_NOT_MATCH = 29000001,<br>EFFECT_COLOR_SPACE_NOT_MATCH = 29000002, EFFECT_INPUT_OUTPUT_NOT_MATCH = 29000101,<br>EFFECT_EFFECT_NUMBER_LIMITED = 29000102, EFFECT_INPUT_OUTPUT_NOT_SUPPORTED = 29000103,<br>EFFECT_ALLOCATE_MEMORY_FAILED = 29000104, EFFECT_PARAM_ERROR = 29000121,<br>EFFECT_KEY_ERROR = 29000122, EFFECT_UNKNOWN = 29000199<br>} | Enumerates the error codes used by the image effector.|
