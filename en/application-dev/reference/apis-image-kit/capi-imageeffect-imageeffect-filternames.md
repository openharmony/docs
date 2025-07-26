# ImageEffect_FilterNames

## Overview

The ImageEffect_FilterNames struct describes the filter name information.

**Since**: 12

**Related module**: [ImageEffect](capi-imageeffect.md)

**Header file**: [image_effect_filter.h](capi-image-effect-filter-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t size = 0 | Number of filter names.|
| const char** nameList = nullptr | List of filter names.|


### Member functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_EffectFilterInfo *OH_EffectFilterInfo_Create()](#oh_effectfilterinfo_create) | OH_EffectFilterInfo_Create() | Creates an OH_EffectFilterInfo instance. The instance must be released by calling [OH_EffectFilterInfo_Release](capi-imageeffect-imageeffect-filternames.md#oh_effectfilterinfo_release) when it is no longer needed.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.ImageEffect.Core|
| [ImageEffect_ErrorCode OH_EffectFilterInfo_SetFilterName(OH_EffectFilterInfo *info, const char *name)](#oh_effectfilterinfo_setfiltername) | OH_EffectFilterInfo_SetFilterName() | Sets a filter name.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.ImageEffect.Core|
| [ImageEffect_ErrorCode OH_EffectFilterInfo_GetFilterName(OH_EffectFilterInfo *info, char **name)](#oh_effectfilterinfo_getfiltername) | OH_EffectFilterInfo_GetFilterName() | Obtains a filter name.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.ImageEffect.Core|
| [ImageEffect_ErrorCode OH_EffectFilterInfo_SetSupportedBufferTypes(OH_EffectFilterInfo *info, uint32_t size,ImageEffect_BufferType *bufferTypeArray)](#oh_effectfilterinfo_setsupportedbuffertypes) | OH_EffectFilterInfo_SetSupportedBufferTypes() | Sets the buffer types supported by a filter.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.ImageEffect.Core|
| [ImageEffect_ErrorCode OH_EffectFilterInfo_GetSupportedBufferTypes(OH_EffectFilterInfo *info, uint32_t *size,ImageEffect_BufferType **bufferTypeArray)](#oh_effectfilterinfo_getsupportedbuffertypes) | OH_EffectFilterInfo_GetSupportedBufferTypes() | Obtains the buffer types supported by a filter.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.ImageEffect.Core|
| [ImageEffect_ErrorCode OH_EffectFilterInfo_SetSupportedFormats(OH_EffectFilterInfo *info, uint32_t size,ImageEffect_Format *formatArray)](#oh_effectfilterinfo_setsupportedformats) | OH_EffectFilterInfo_SetSupportedFormats() | Sets the pixel formats supported by a filter.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.ImageEffect.Core|
| [ImageEffect_ErrorCode OH_EffectFilterInfo_GetSupportedFormats(OH_EffectFilterInfo *info, uint32_t *size,ImageEffect_Format **formatArray)](#oh_effectfilterinfo_getsupportedformats) | OH_EffectFilterInfo_GetSupportedFormats() | Obtains the pixel formats supported by a filter.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.ImageEffect.Core|
| [ImageEffect_ErrorCode OH_EffectFilterInfo_Release(OH_EffectFilterInfo *info)](#oh_effectfilterinfo_release) | OH_EffectFilterInfo_Release() | Destroys an OH_EffectFilterInfo instance.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.ImageEffect.Core|

## Member Function Description

### OH_EffectFilterInfo_Create()

```
OH_EffectFilterInfo *OH_EffectFilterInfo_Create()
```

**Description**

Creates an OH_EffectFilterInfo instance. The instance must be released by calling [OH_EffectFilterInfo_Release](capi-imageeffect-imageeffect-filternames.md#oh_effectfilterinfo_release) when it is no longer needed.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Returns**

| Type| Description|
| -- | -- |
| [OH_EffectFilterInfo](capi-imageeffect-oh-effectfilterinfo.md) | Pointer to the OH_EffectFilterInfo instance created. If the operation fails, a null pointer is returned.|

### OH_EffectFilterInfo_SetFilterName()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_SetFilterName(OH_EffectFilterInfo *info, const char *name)
```

**Description**

Sets a filter name.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectFilterInfo](capi-imageeffect-oh-effectfilterinfo.md) *info | Pointer to the filter information.|
| const char *name | Pointer to the filter name, for example, **OH_EFFECT_BRIGHTNESS_FILTER**.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode): The function is called successfully.<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode): The input parameter is a null pointer.|

### OH_EffectFilterInfo_GetFilterName()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_GetFilterName(OH_EffectFilterInfo *info, char **name)
```

**Description**

Obtains a filter name.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectFilterInfo](capi-imageeffect-oh-effectfilterinfo.md) *info | Pointer to the filter information.|
| char **name | Double pointer to the char array holding the filter name.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode): The function is called successfully.<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode): The input parameter is a null pointer.|

### OH_EffectFilterInfo_SetSupportedBufferTypes()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_SetSupportedBufferTypes(OH_EffectFilterInfo *info, uint32_t size,ImageEffect_BufferType *bufferTypeArray)
```

**Description**

Sets the buffer types supported by a filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectFilterInfo](capi-imageeffect-oh-effectfilterinfo.md) *info | Pointer to the filter information.|
| uint32_t size | Number of buffer types supported, each of which is [ImageEffect_BufferType](capi-image-effect-filter-h.md#imageeffect_buffertype).|
| ImageEffect_BufferType *bufferTypeArray | Pointer to the array holding the buffer types supported, each of which is [ImageEffect_BufferType](capi-image-effect-filter-h.md#imageeffect_buffertype).|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode): The function is called successfully.<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode): The input parameter is a null pointer.|

### OH_EffectFilterInfo_GetSupportedBufferTypes()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_GetSupportedBufferTypes(OH_EffectFilterInfo *info, uint32_t *size,ImageEffect_BufferType **bufferTypeArray)
```

**Description**

Obtains the buffer types supported by a filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectFilterInfo](capi-imageeffect-oh-effectfilterinfo.md) *info | Pointer to the filter information.|
| uint32_t *size | Pointer to the number of buffer types supported, each of which is [ImageEffect_BufferType](capi-image-effect-filter-h.md#imageeffect_buffertype).|
| ImageEffect_BufferType **bufferTypeArray | Double pointer to the array holding the buffer types supported, each of which is [ImageEffect_BufferType](capi-image-effect-filter-h.md#imageeffect_buffertype).|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode): The function is called successfully.<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode): The input parameter is a null pointer.|

### OH_EffectFilterInfo_SetSupportedFormats()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_SetSupportedFormats(OH_EffectFilterInfo *info, uint32_t size,ImageEffect_Format *formatArray)
```

**Description**

Sets the pixel formats supported by a filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectFilterInfo](capi-imageeffect-oh-effectfilterinfo.md) *info | Pointer to the filter information.|
| uint32_t size | Number of pixel formats supported, each of which is [ImageEffect_Format](capi-image-effect-filter-h.md#imageeffect_format).|
| ImageEffect_Format *formatArray | Pointer to the array holding the pixel formats supported, each of which is [ImageEffect_Format](capi-image-effect-filter-h.md#imageeffect_format).|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode): The function is called successfully.<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode): The input parameter is a null pointer.|

### OH_EffectFilterInfo_GetSupportedFormats()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_GetSupportedFormats(OH_EffectFilterInfo *info, uint32_t *size,ImageEffect_Format **formatArray)
```

**Description**

Obtains the pixel formats supported by a filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectFilterInfo](capi-imageeffect-oh-effectfilterinfo.md) *info | Pointer to the filter information.|
| uint32_t *size | Pointer to the number of pixel formats supported, each of which is [ImageEffect_Format](capi-image-effect-filter-h.md#imageeffect_format).|
| ImageEffect_Format **formatArray | Double pointer to the array holding the pixel formats supported, each of which is [ImageEffect_Format](capi-image-effect-filter-h.md#imageeffect_format).|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode): The function is called successfully.<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode): The input parameter is a null pointer.|

### OH_EffectFilterInfo_Release()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_Release(OH_EffectFilterInfo *info)
```

**Description**

Destroys an OH_EffectFilterInfo instance.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectFilterInfo](capi-imageeffect-oh-effectfilterinfo.md) *info | Pointer to the filter information.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode): The function is called successfully.<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode): The input parameter is a null pointer.|
