# image_effect_filter.h

## Overview

The **image_effect_filter.h** file declares the APIs related to an image effect filter.<br>With these APIs, you can quickly implement basic effect processing or connect multiple filters in series in an image effector to implement complex effect processing. The system provides basic effect processing filters such as brightness and crop filters.

**File to include**: <multimedia/image_effect/image_effect_filter.h>

**Library**: libimage_effect.so

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Related module**: [ImageEffect](capi-imageeffect.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ImageEffect_DataValue](capi-imageeffect-imageeffect-datavalue.md) | ImageEffect_DataValue | Describes the data values.|
| [ImageEffect_Any](capi-imageeffect-imageeffect-any.md) | ImageEffect_Any | Describes the image effect parameters.|
| [ImageEffect_FilterNames](capi-imageeffect-imageeffect-filternames.md) | ImageEffect_FilterNames | Describes the filter name information.|
| [ImageEffect_FilterDelegate](capi-imageeffect-imageeffect-filterdelegate.md) | ImageEffect_FilterDelegate | Describes the callback functions of a custom filter.|
| [ImageEffect_Region](capi-imageeffect-imageeffect-region.md) | ImageEffect_Region | Describes the image region.|
| [ImageEffect_Size](capi-imageeffect-imageeffect-size.md) | ImageEffect_Size | Describes the image size.|
| [OH_EffectFilter](capi-imageeffect-oh-effectfilter.md) | OH_EffectFilter | Describes the image effect filter.|
| [OH_EffectFilterInfo](capi-imageeffect-oh-effectfilterinfo.md) | OH_EffectFilterInfo | Describes the filter information.|
| [OH_EffectBufferInfo](capi-imageeffect-oh-effectbufferinfo.md) | OH_EffectBufferInfo | Describes the buffer information.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ImageEffect_DataType](#imageeffect_datatype) | ImageEffect_DataType | Enumerates the data types.|
| [ImageEffect_Format](#imageeffect_format) | ImageEffect_Format | Enumerates the pixel formats.|
| [ImageEffect_BufferType](#imageeffect_buffertype) | ImageEffect_BufferType | Enumerates the buffer types.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_EffectFilterInfo *OH_EffectFilterInfo_Create()](#oh_effectfilterinfo_create) | - | Creates an OH_EffectFilterInfo instance. The instance must be released by calling [OH_EffectFilterInfo_Release](#oh_effectfilterinfo_release) when it is no longer needed.|
| [ImageEffect_ErrorCode OH_EffectFilterInfo_SetFilterName(OH_EffectFilterInfo *info, const char *name)](#oh_effectfilterinfo_setfiltername) | - | Sets a filter name.|
| [ImageEffect_ErrorCode OH_EffectFilterInfo_GetFilterName(OH_EffectFilterInfo *info, char **name)](#oh_effectfilterinfo_getfiltername) | - | Obtains a filter name.|
| [ImageEffect_ErrorCode OH_EffectFilterInfo_SetSupportedBufferTypes(OH_EffectFilterInfo *info, uint32_t size,ImageEffect_BufferType *bufferTypeArray)](#oh_effectfilterinfo_setsupportedbuffertypes) | - | Sets the buffer types supported by a filter.|
| [ImageEffect_ErrorCode OH_EffectFilterInfo_GetSupportedBufferTypes(OH_EffectFilterInfo *info, uint32_t *size,ImageEffect_BufferType **bufferTypeArray)](#oh_effectfilterinfo_getsupportedbuffertypes) | - | Obtains the buffer types supported by a filter.|
| [ImageEffect_ErrorCode OH_EffectFilterInfo_SetSupportedFormats(OH_EffectFilterInfo *info, uint32_t size,ImageEffect_Format *formatArray)](#oh_effectfilterinfo_setsupportedformats) | - | Sets the pixel formats supported by a filter.|
| [ImageEffect_ErrorCode OH_EffectFilterInfo_GetSupportedFormats(OH_EffectFilterInfo *info, uint32_t *size,ImageEffect_Format **formatArray)](#oh_effectfilterinfo_getsupportedformats) | - | Obtains the pixel formats supported by a filter.|
| [ImageEffect_ErrorCode OH_EffectFilterInfo_Release(OH_EffectFilterInfo *info)](#oh_effectfilterinfo_release) | - | Destroys an OH_EffectFilterInfo instance.|
| [OH_EffectBufferInfo *OH_EffectBufferInfo_Create()](#oh_effectbufferinfo_create) | - | Creates an OH_EffectBufferInfo instance. The instance must be released by calling [OH_EffectBufferInfo_Release](#oh_effectbufferinfo_release) when it is no longer needed.|
| [ImageEffect_ErrorCode OH_EffectBufferInfo_SetAddr(OH_EffectBufferInfo *info, void *addr)](#oh_effectbufferinfo_setaddr) | - | Sets the address of an effect buffer.|
| [ImageEffect_ErrorCode OH_EffectBufferInfo_GetAddr(OH_EffectBufferInfo *info, void **addr)](#oh_effectbufferinfo_getaddr) | - | Obtains the address of an effect buffer.|
| [ImageEffect_ErrorCode OH_EffectBufferInfo_SetWidth(OH_EffectBufferInfo *info, int32_t width)](#oh_effectbufferinfo_setwidth) | - | Sets the image width.|
| [ImageEffect_ErrorCode OH_EffectBufferInfo_GetWidth(OH_EffectBufferInfo *info, int32_t *width)](#oh_effectbufferinfo_getwidth) | - | Obtains the image width.|
| [ImageEffect_ErrorCode OH_EffectBufferInfo_SetHeight(OH_EffectBufferInfo *info, int32_t height)](#oh_effectbufferinfo_setheight) | - | Sets the image height.|
| [ImageEffect_ErrorCode OH_EffectBufferInfo_GetHeight(OH_EffectBufferInfo *info, int32_t *height)](#oh_effectbufferinfo_getheight) | - | Obtains the image height.|
| [ImageEffect_ErrorCode OH_EffectBufferInfo_SetRowSize(OH_EffectBufferInfo *info, int32_t rowSize)](#oh_effectbufferinfo_setrowsize) | - | Sets the number of bytes per row for an image.|
| [ImageEffect_ErrorCode OH_EffectBufferInfo_GetRowSize(OH_EffectBufferInfo *info, int32_t *rowSize)](#oh_effectbufferinfo_getrowsize) | - | Obtains the number of bytes per row of an image.|
| [ImageEffect_ErrorCode OH_EffectBufferInfo_SetEffectFormat(OH_EffectBufferInfo *info, ImageEffect_Format format)](#oh_effectbufferinfo_seteffectformat) | - | Sets the pixel format for an image.|
| [ImageEffect_ErrorCode OH_EffectBufferInfo_GetEffectFormat(OH_EffectBufferInfo *info, ImageEffect_Format *format)](#oh_effectbufferinfo_geteffectformat) | - | Obtains the pixel format of an image.|
| [ImageEffect_ErrorCode OH_EffectBufferInfo_SetTextureId(OH_EffectBufferInfo *info, int32_t textureId)](#oh_effectbufferinfo_settextureid) | - | Sets the texture ID of the image for an OH_EffectBufferInfo struct.|
| [ImageEffect_ErrorCode OH_EffectBufferInfo_GetTextureId(OH_EffectBufferInfo *info, int32_t *textureId)](#oh_effectbufferinfo_gettextureid) | - | Obtains the texture ID of an image from an OH_EffectBufferInfo struct.|
| [ImageEffect_ErrorCode OH_EffectBufferInfo_Release(OH_EffectBufferInfo *info)](#oh_effectbufferinfo_release) | - | Destroys an OH_EffectBufferInfo instance.|
| [typedef bool (\*OH_EffectFilterDelegate_SetValue)(OH_EffectFilter *filter, const char *key,const ImageEffect_Any *value)](#oh_effectfilterdelegate_setvalue) | OH_EffectFilterDelegate_SetValue | Defines a pointer to the callback function for setting parameters of a custom filter. It is used to verify parameters and parameter values.|
| [typedef void (\*OH_EffectFilterDelegate_PushData)(OH_EffectFilter *filter, OH_EffectBufferInfo *info)](#oh_effectfilterdelegate_pushdata) | OH_EffectFilterDelegate_PushData | Defines a pointer to the callback function used by a custom filter to push image data to the next-level filter. The function pointer must be actively called in the callback of [OH_EffectFilterDelegate_Render](#oh_effectfilterdelegate_render).|
| [typedef bool (\*OH_EffectFilterDelegate_Render)(OH_EffectFilter *filter, OH_EffectBufferInfo *info,OH_EffectFilterDelegate_PushData pushData)](#oh_effectfilterdelegate_render) | OH_EffectFilterDelegate_Render | Defines a pointer to the callback function for rendering an image using a custom filter.|
| [typedef bool (\*OH_EffectFilterDelegate_Save)(OH_EffectFilter *filter, char **info)](#oh_effectfilterdelegate_save) | OH_EffectFilterDelegate_Save | Defines a pointer to the callback function for serializing a custom filter. Filters are serialized in JSON format.|
| [typedef OH_EffectFilter *(\*OH_EffectFilterDelegate_Restore)(const char *info)](#oh_effectfilterdelegate_restore) | OH_EffectFilterDelegate_Restore | Defines a pointer to the callback function for deserializing a custom filter.|
| [OH_EffectFilter *OH_EffectFilter_Create(const char *name)](#oh_effectfilter_create) | - | Creates an OH_EffectFilter instance. The instance must be released by calling [OH_EffectFilter_Release](#oh_effectfilter_release) when it is no longer needed.|
| [ImageEffect_ErrorCode OH_EffectFilter_SetValue(OH_EffectFilter *filter, const char *key, const ImageEffect_Any *value)](#oh_effectfilter_setvalue) | - | Sets a filter parameter.|
| [ImageEffect_ErrorCode OH_EffectFilter_GetValue(OH_EffectFilter *filter, const char *key, ImageEffect_Any *value)](#oh_effectfilter_getvalue) | - | Obtains a filter parameter.|
| [ImageEffect_ErrorCode OH_EffectFilter_Register(const OH_EffectFilterInfo *info,const ImageEffect_FilterDelegate *delegate)](#oh_effectfilter_register) | - | Registers a custom filter.|
| [ImageEffect_FilterNames *OH_EffectFilter_LookupFilters(const char *key)](#oh_effectfilter_lookupfilters) | - | Obtains filters that meet given conditions.|
| [void OH_EffectFilter_ReleaseFilterNames()](#oh_effectfilter_releasefilternames) | - | Releases filter name memory resources.|
| [ImageEffect_ErrorCode OH_EffectFilter_LookupFilterInfo(const char *name, OH_EffectFilterInfo *info)](#oh_effectfilter_lookupfilterinfo) | - | Obtains the filter information.|
| [ImageEffect_ErrorCode OH_EffectFilter_Render(OH_EffectFilter *filter, OH_PixelmapNative *inputPixelmap,OH_PixelmapNative *outputPixelmap)](#oh_effectfilter_render) | - | Starts image rendering.|
| [ImageEffect_ErrorCode OH_EffectFilter_RenderWithTextureId(OH_EffectFilter *filter, int32_t inputTextureId,int32_t outputTextureId, int32_t colorSpace)](#oh_effectfilter_renderwithtextureid) | - | Applies the filter effect using texture IDs. This function does not support using the same texture for both input and output.|
| [ImageEffect_ErrorCode OH_EffectFilter_Release(OH_EffectFilter *filter)](#oh_effectfilter_release) | - | Destroys an OH_EffectFilter instance.|

## Enum Description

### ImageEffect_DataType

```
enum ImageEffect_DataType
```

**Description**

Enumerates the data types.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

| Enum Item| Description|
| -- | -- |
| EFFECT_DATA_TYPE_UNKNOWN = 0 | Undefined.|
| EFFECT_DATA_TYPE_INT32 = 1 | Integer.|
| EFFECT_DATA_TYPE_FLOAT = 2 | Single-precision floating point.|
| EFFECT_DATA_TYPE_DOUBLE = 3 | Double-precision floating point.|
| EFFECT_DATA_TYPE_CHAR = 4 | Byte.|
| EFFECT_DATA_TYPE_LONG = 5 | Long integer.|
| EFFECT_DATA_TYPE_BOOL = 6 | Boolean.|
| EFFECT_DATA_TYPE_PTR = 7 | Pointer.|

### ImageEffect_Format

```
enum ImageEffect_Format
```

**Description**

Enumerates the pixel formats.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

| Enum Item| Description|
| -- | -- |
| EFFECT_PIXEL_FORMAT_UNKNOWN = 0 | Undefined.|
| EFFECT_PIXEL_FORMAT_RGBA8888 = 1 | RGBA8888.|
| EFFECT_PIXEL_FORMAT_NV21 = 2 | NV21.|
| EFFECT_PIXEL_FORMAT_NV12 = 3 | NV12.|
| EFFECT_PIXEL_FORMAT_RGBA1010102 = 4 | 10-bit RGBA.|
| EFFECT_PIXEL_FORMAT_YCBCR_P010 = 5 | 10-bit YCBCR420.|
| EFFECT_PIXEL_FORMAT_YCRCB_P010 = 6 | 10-bit YCRCB420.|

### ImageEffect_BufferType

```
enum ImageEffect_BufferType
```

**Description**

Enumerates the buffer types.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

| Enum Item| Description|
| -- | -- |
| EFFECT_BUFFER_TYPE_UNKNOWN = 0 | Undefined.|
| EFFECT_BUFFER_TYPE_PIXEL = 1 | Pixel image type.|
| EFFECT_BUFFER_TYPE_TEXTURE = 2 | Texture type.|


## Function Description

### OH_EffectFilterInfo_Create()

```
OH_EffectFilterInfo *OH_EffectFilterInfo_Create()
```

**Description**

Creates an OH_EffectFilterInfo instance. The instance must be released by calling [OH_EffectFilterInfo_Release](#oh_effectfilterinfo_release) when it is no longer needed.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Returns**

| Type| Description|
| -- | -- |
| [OH_EffectFilterInfo](capi-imageeffect-oh-effectfilterinfo.md) * | Pointer to the OH_EffectFilterInfo instance created. If the operation fails, a null pointer is returned.|

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
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

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
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

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
| uint32_t size | Number of buffer types supported, each of which is [ImageEffect_BufferType](#imageeffect_buffertype).|
| [ImageEffect_BufferType](#imageeffect_buffertype) *bufferTypeArray | Pointer to the array holding the buffer types supported, each of which is [ImageEffect_BufferType](#imageeffect_buffertype).|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

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
| uint32_t *size | Number of buffer types supported, each of which is [ImageEffect_BufferType](#imageeffect_buffertype).|
| [ImageEffect_BufferType](#imageeffect_buffertype) **bufferTypeArray | Double pointer to the array holding the buffer types supported, each of which is [ImageEffect_BufferType](#imageeffect_buffertype).|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

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
| uint32_t size | Number of pixel formats supported, each of which is [ImageEffect_Format](#imageeffect_format).|
| [ImageEffect_Format](#imageeffect_format) *formatArray | Pointer to the array holding the pixel formats supported, each of which is [ImageEffect_Format](#imageeffect_format).|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

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
| uint32_t *size | Pointer to the number of pixel formats supported, each of which is [ImageEffect_Format](#imageeffect_format).|
| [ImageEffect_Format](#imageeffect_format) **formatArray | Double pointer to the array holding the pixel formats supported, each of which is [ImageEffect_Format](#imageeffect_format).|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

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
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_EffectBufferInfo_Create()

```
OH_EffectBufferInfo *OH_EffectBufferInfo_Create()
```

**Description**

Creates an OH_EffectBufferInfo instance. The instance must be released by calling [OH_EffectBufferInfo_Release](#oh_effectbufferinfo_release) when it is no longer needed.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Returns**

| Type| Description|
| -- | -- |
| [OH_EffectBufferInfo](capi-imageeffect-oh-effectbufferinfo.md) * | Pointer to the OH_EffectBufferInfo instance created. If the operation fails, a null pointer is returned.|

### OH_EffectBufferInfo_SetAddr()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_SetAddr(OH_EffectBufferInfo *info, void *addr)
```

**Description**

Sets the address of an effect buffer.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectBufferInfo](capi-imageeffect-oh-effectbufferinfo.md) *info | Pointer to the image information.|
| void *addr | Pointer to the virtual address of the image buffer.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_EffectBufferInfo_GetAddr()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_GetAddr(OH_EffectBufferInfo *info, void **addr)
```

**Description**

Obtains the address of an effect buffer.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectBufferInfo](capi-imageeffect-oh-effectbufferinfo.md) *info | Pointer to the image information.|
| void **addr | Double pointer to the virtual address of the image buffer.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_EffectBufferInfo_SetWidth()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_SetWidth(OH_EffectBufferInfo *info, int32_t width)
```

**Description**

Sets the image width.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectBufferInfo](capi-imageeffect-oh-effectbufferinfo.md) *info | Pointer to the image information.|
| int32_t width | Image width, in px.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_EffectBufferInfo_GetWidth()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_GetWidth(OH_EffectBufferInfo *info, int32_t *width)
```

**Description**

Obtains the image width.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectBufferInfo](capi-imageeffect-oh-effectbufferinfo.md) *info | Pointer to the image information.|
| int32_t *width | Pointer to the image width, in px.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_EffectBufferInfo_SetHeight()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_SetHeight(OH_EffectBufferInfo *info, int32_t height)
```

**Description**

Sets the image height.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectBufferInfo](capi-imageeffect-oh-effectbufferinfo.md) *info | Pointer to the image information.|
| int32_t height | Image height, in px.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_EffectBufferInfo_GetHeight()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_GetHeight(OH_EffectBufferInfo *info, int32_t *height)
```

**Description**

Obtains the image height.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectBufferInfo](capi-imageeffect-oh-effectbufferinfo.md) *info | Pointer to the image information.|
| int32_t *height | Pointer to the image height, in px.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_EffectBufferInfo_SetRowSize()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_SetRowSize(OH_EffectBufferInfo *info, int32_t rowSize)
```

**Description**

Sets the number of bytes per row for an image.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectBufferInfo](capi-imageeffect-oh-effectbufferinfo.md) *info | Pointer to the image information.|
| int32_t rowSize | Number of bytes per row, in bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_EffectBufferInfo_GetRowSize()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_GetRowSize(OH_EffectBufferInfo *info, int32_t *rowSize)
```

**Description**

Obtains the number of bytes per row of an image.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectBufferInfo](capi-imageeffect-oh-effectbufferinfo.md) *info | Pointer to the image information.|
| int32_t *rowSize | Pointer to the number of bytes per row, in bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_EffectBufferInfo_SetEffectFormat()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_SetEffectFormat(OH_EffectBufferInfo *info, ImageEffect_Format format)
```

**Description**

Sets the pixel format for an image.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectBufferInfo](capi-imageeffect-oh-effectbufferinfo.md) *info | Pointer to the image information.|
| [ImageEffect_Format](#imageeffect_format) format | Pixel format.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_EffectBufferInfo_GetEffectFormat()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_GetEffectFormat(OH_EffectBufferInfo *info, ImageEffect_Format *format)
```

**Description**

Obtains the pixel format of an image.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectBufferInfo](capi-imageeffect-oh-effectbufferinfo.md) *info | Pointer to the image information.|
| [ImageEffect_Format](#imageeffect_format) *format | Pointer to the pixel format.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_EffectBufferInfo_SetTextureId()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_SetTextureId(OH_EffectBufferInfo *info, int32_t textureId)
```

**Description**

Sets the texture ID of the image for an OH_EffectBufferInfo struct.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectBufferInfo](capi-imageeffect-oh-effectbufferinfo.md) *info | Pointer to an instance of the OH_EffectBufferInfo struct.|
| int32_t textureId | Texture ID of the image.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is missing.|

### OH_EffectBufferInfo_GetTextureId()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_GetTextureId(OH_EffectBufferInfo *info, int32_t *textureId)
```

**Description**

Obtains the texture ID of an image from an OH_EffectBufferInfo struct.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectBufferInfo](capi-imageeffect-oh-effectbufferinfo.md) *info | Pointer to an instance of the OH_EffectBufferInfo struct.|
| int32_t *textureId | Pointer to the texture ID of the image.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is missing.|

### OH_EffectBufferInfo_Release()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_Release(OH_EffectBufferInfo *info)
```

**Description**

Destroys an OH_EffectBufferInfo instance.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectBufferInfo](capi-imageeffect-oh-effectbufferinfo.md) *info | Pointer to the image information.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_EffectFilterDelegate_SetValue()

```
typedef bool (*OH_EffectFilterDelegate_SetValue)(OH_EffectFilter *filter, const char *key,const ImageEffect_Any *value)
```

**Description**

Defines a pointer to the callback function for setting parameters of a custom filter. It is used to verify parameters and parameter values.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectFilter](capi-imageeffect-oh-effectfilter.md) *filter | Pointer to the filter.|
|  const char *key | Pointer to the key of a filter parameter.|
| [const ImageEffect_Any](capi-imageeffect-imageeffect-any.md) *value | Pointer to the value of the filter parameter.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true**: The parameter is valid.<br>**false**: The parameter is invalid.|

### OH_EffectFilterDelegate_PushData()

```
typedef void (*OH_EffectFilterDelegate_PushData)(OH_EffectFilter *filter, OH_EffectBufferInfo *info)
```

**Description**

Defines a pointer to the callback function used by a custom filter to push image data to the next-level filter. The function pointer must be actively called in the callback of [OH_EffectFilterDelegate_Render](#oh_effectfilterdelegate_render).

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectFilter](capi-imageeffect-oh-effectfilter.md) *filter | Pointer to the filter.|
|  [OH_EffectBufferInfo](capi-imageeffect-oh-effectbufferinfo.md) *info | Pointer to the buffer information, which is **OH_EffectBufferInfo**.|

### OH_EffectFilterDelegate_Render()

```
typedef bool (*OH_EffectFilterDelegate_Render)(OH_EffectFilter *filter, OH_EffectBufferInfo *info,OH_EffectFilterDelegate_PushData pushData)
```

**Description**

Defines a pointer to the callback function for rendering an image using a custom filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectFilter](capi-imageeffect-oh-effectfilter.md) *filter | Pointer to the filter.|
| [OH_EffectBufferInfo](capi-imageeffect-oh-effectbufferinfo.md) *info | Pointer to the buffer information, which is **OH_EffectBufferInfo**.|
| [OH_EffectFilterDelegate_PushData](#oh_effectfilterdelegate_pushdata) pushData | Callback function **OH_EffectFilterDelegate_PushData** used by the custom filter to push image data to the next-level filter.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true**: The operation is successful.<br>**false**: The operation fails.|

### OH_EffectFilterDelegate_Save()

```
typedef bool (*OH_EffectFilterDelegate_Save)(OH_EffectFilter *filter, char **info)
```

**Description**

Defines a pointer to the callback function for serializing a custom filter. Filters are serialized in JSON format.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectFilter](capi-imageeffect-oh-effectfilter.md) *filter | Pointer to the filter.|
|  char **info | Double pointer to a char array holding a serialized JSON string.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true**: The operation is successful.<br>**false**: The operation fails.|

### OH_EffectFilterDelegate_Restore()

```
typedef OH_EffectFilter *(*OH_EffectFilterDelegate_Restore)(const char *info)
```

**Description**

Defines a pointer to the callback function for deserializing a custom filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char *info | Pointer to a serialized JSON string.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_EffectFilter](capi-imageeffect-oh-effectfilter.md) | OH_EffectFilter instance. If the operation fails, a null pointer is returned.|

### OH_EffectFilter_Create()

```
OH_EffectFilter *OH_EffectFilter_Create(const char *name)
```

**Description**

Creates an OH_EffectFilter instance. The instance must be released by calling [OH_EffectFilter_Release](#oh_effectfilter_release) when it is no longer needed.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char *name | Pointer to the filter name, for example, **OH_EFFECT_BRIGHTNESS_FILTER**.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_EffectFilter](capi-imageeffect-oh-effectfilter.md) * | Pointer to the OH_EffectFilter instance created. If the operation fails, a null pointer is returned.|

### OH_EffectFilter_SetValue()

```
ImageEffect_ErrorCode OH_EffectFilter_SetValue(OH_EffectFilter *filter, const char *key, const ImageEffect_Any *value)
```

**Description**

Sets a filter parameter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectFilter](capi-imageeffect-oh-effectfilter.md) *filter | Pointer to the filter.|
| const char *key | Pointer to the key of the filter parameter, for example, **OH_EFFECT_FILTER_INTENSITY_KEY**.|
| [const ImageEffect_Any](capi-imageeffect-imageeffect-any.md) *value | Pointer to the value of the filter parameter.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.<br>         **EFFECT_KEY_ERROR**: A parameter is invalid.<br>         **EFFECT_PARAM_ERROR**: A parameter value is invalid.|

### OH_EffectFilter_GetValue()

```
ImageEffect_ErrorCode OH_EffectFilter_GetValue(OH_EffectFilter *filter, const char *key, ImageEffect_Any *value)
```

**Description**

Obtains a filter parameter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectFilter](capi-imageeffect-oh-effectfilter.md) *filter | Pointer to the filter.|
| const char *key | Pointer to the key of the filter parameter, for example, **OH_EFFECT_FILTER_INTENSITY_KEY**.|
| [ImageEffect_Any](capi-imageeffect-imageeffect-any.md) *value | Pointer to the value of the filter parameter.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.<br>         **EFFECT_KEY_ERROR**: A parameter is invalid.|

### OH_EffectFilter_Register()

```
ImageEffect_ErrorCode OH_EffectFilter_Register(const OH_EffectFilterInfo *info,const ImageEffect_FilterDelegate *delegate)
```

**Description**

Registers a custom filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const OH_EffectFilterInfo](capi-imageeffect-oh-effectfilterinfo.md) *info | Pointer to the filter information.|
| [const ImageEffect_FilterDelegate](capi-imageeffect-imageeffect-filterdelegate.md) *delegate | Pointer to the callback function **ImageEffect_FilterDelegate** of the filter.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_EffectFilter_LookupFilters()

```
ImageEffect_FilterNames *OH_EffectFilter_LookupFilters(const char *key)
```

**Description**

Obtains filters that meet given conditions.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char *key | Pointer to the conditions. You can use the keyword **Default** to obtain all filters.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_FilterNames](capi-imageeffect-imageeffect-filternames.md) * | Pointer to a list of filter names.|

### OH_EffectFilter_ReleaseFilterNames()

```
void OH_EffectFilter_ReleaseFilterNames()
```

**Description**

Releases filter name memory resources.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

### OH_EffectFilter_LookupFilterInfo()

```
ImageEffect_ErrorCode OH_EffectFilter_LookupFilterInfo(const char *name, OH_EffectFilterInfo *info)
```

**Description**

Obtains the filter information.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char *name | Pointer to the filter name.|
| [OH_EffectFilterInfo](capi-imageeffect-oh-effectfilterinfo.md) *info | Pointer to the filter information, which is **OH_EffectFilterInfo**.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer or an invalid value.|

### OH_EffectFilter_Render()

```
ImageEffect_ErrorCode OH_EffectFilter_Render(OH_EffectFilter *filter, OH_PixelmapNative *inputPixelmap,OH_PixelmapNative *outputPixelmap)
```

**Description**

Starts image rendering.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectFilter](capi-imageeffect-oh-effectfilter.md) *filter | Pointer to the filter.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *inputPixelmap | Pointer to the input image.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *outputPixelmap | Pointer to the output image.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_EffectFilter_RenderWithTextureId()

```
ImageEffect_ErrorCode OH_EffectFilter_RenderWithTextureId(OH_EffectFilter *filter, int32_t inputTextureId,int32_t outputTextureId, int32_t colorSpace)
```

**Description**

Applies the filter effect using texture IDs. This function does not support using the same texture for both input and output.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectFilter](capi-imageeffect-oh-effectfilter.md) *filter | Pointer to an instance of the OH_EffectFilter struct.|
| int32_t inputTextureId | ID of the input texture. This ID must be valid and bound to a texture of the GL_TEXTURE_2D type.|
| int32_t outputTextureId | ID of the output texture. This ID must be valid.<br> If it is not bound to a texture, it will automatically be bound to a GL_TEXTURE_2D type.<br> If the texture is already bound and the size is inappropriate, the rendered result may be cropped or partially filled into this texture.|
| int32_t colorSpace | Color space of the image.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is missing.|

### OH_EffectFilter_Release()

```
ImageEffect_ErrorCode OH_EffectFilter_Release(OH_EffectFilter *filter)
```

**Description**

Destroys an OH_EffectFilter instance.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_EffectFilter](capi-imageeffect-oh-effectfilter.md) *filter | Pointer to the filter.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|
