# ImageEffect_FilterNames

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9329f19aa2995f079ff9cf109a20aad0033a91a3 translatedAt=2026-08-03T04:06:04.394Z pushedAt=2026-08-04T02:20:09.760Z -->

```c
typedef struct ImageEffect_FilterNames {...} ImageEffect_FilterNames
```

## Overview

The struct describes the filter name information.

**Since**: 12

**Related module**: [ImageEffect](capi-imageeffect.md)

**Header file**: [image_effect_filter.h](capi-image-effect-filter-h.md)

## Summary

### Member Variables

**The following table lists the declarations supporting C++ syntax.**

| Name| Description|
| -- | -- |
| uint32_t size = 0 | Number of filter names.|
| const char \*\*nameList = nullptr | List of filter names.|

**The following table lists the declarations supporting C syntax.**

| Name| Description|
| -- | -- |
| uint32_t size| Number of filter names.|
| const char \*\*nameList | List of filter names.|

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

```c
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

```c
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

```c
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

```c
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
| uint32_t size | Number of buffer types supported, where each type corresponds to a value in the [ImageEffect_BufferType](capi-image-effect-filter-h.md#imageeffect_buffertype) enumeration.|
| ImageEffect_BufferType *bufferTypeArray | Pointer to the array of the buffer types supported, where each type corresponds to a value in the [ImageEffect_BufferType](capi-image-effect-filter-h.md#imageeffect_buffertype) enumeration.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode): The function is called successfully.<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode): The input parameter is a null pointer.|

### OH_EffectFilterInfo_GetSupportedBufferTypes()

```c
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
| uint32_t *size | Number of buffer types supported, where each type corresponds to a value in the [ImageEffect_BufferType](capi-image-effect-filter-h.md#imageeffect_buffertype) enumeration.|
| ImageEffect_BufferType **bufferTypeArray | Pointer to the array of the buffer types supported, where each type corresponds to a value in the [ImageEffect_BufferType](capi-image-effect-filter-h.md#imageeffect_buffertype) enumeration.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode): The function is called successfully.<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode): The input parameter is a null pointer.|

### OH_EffectFilterInfo_SetSupportedFormats()

```c
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
| uint32_t size | Number of pixel formats supported, where each format corresponds to a value in the [ImageEffect_Format](capi-image-effect-filter-h.md#imageeffect_format) enumeration.|
| ImageEffect_Format *formatArray | Pointer to the array of the pixel formats supported, where each format corresponds to a value in the [ImageEffect_Format](capi-image-effect-filter-h.md#imageeffect_format) enumeration.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode): The function is called successfully.<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode): The input parameter is a null pointer.|

### OH_EffectFilterInfo_GetSupportedFormats()

```c
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
| uint32_t *size | Number of pixel formats supported, where each format corresponds to a value in the [ImageEffect_Format](capi-image-effect-filter-h.md#imageeffect_format) enumeration.|
| ImageEffect_Format **formatArray | Pointer to the array of the pixel formats supported, where each format corresponds to a value in the [ImageEffect_Format](capi-image-effect-filter-h.md#imageeffect_format) enumeration.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode): The function is called successfully.<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode): The input parameter is a null pointer.|

### OH_EffectFilterInfo_Release()

```c
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