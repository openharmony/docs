# image_effect.h

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zyj208-->
<!--Designer: @wangshoucheng-->
<!--Tester: @gengfei-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the APIs related to an image effector.<br> You can use the APIs to add, delete, and query image effect filters. You can connect multiple filters in series to implement complex effect adjustment.<br> The effector supports multiple input types, such as PixelMap, URI, surface, and picture. Different input types are converted into buffer objects in the effector, and effect processing is implemented through the filters.

**File to include**: <multimedia/image_effect/image_effect.h>

**Library**: libimage_effect.so

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Related module**: [ImageEffect](capi-imageeffect.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) | OH_ImageEffect | Describes the image effector.|

### Functions

| Name| Description|
| -- | -- |
| [OH_ImageEffect *OH_ImageEffect_Create(const char *name)](#oh_imageeffect_create) | Creates an OH_ImageEffect instance. The instance must be released by calling [OH_ImageEffect_Release](capi-image-effect-h.md#oh_imageeffect_release) when it is no longer needed.|
| [OH_EffectFilter *OH_ImageEffect_AddFilter(OH_ImageEffect *imageEffect, const char *filterName)](#oh_imageeffect_addfilter) | Adds a filter.|
| [ImageEffect_ErrorCode OH_ImageEffect_AddFilterByFilter(OH_ImageEffect *imageEffect, OH_EffectFilter *filter)](#oh_imageeffect_addfilterbyfilter) | Adds a specified filter.|
| [OH_EffectFilter *OH_ImageEffect_InsertFilter(OH_ImageEffect *imageEffect, uint32_t index, const char *filterName)](#oh_imageeffect_insertfilter) | Inserts a filter.|
| [ImageEffect_ErrorCode OH_ImageEffect_InsertFilterByFilter(OH_ImageEffect *imageEffect, uint32_t index, OH_EffectFilter *filter)](#oh_imageeffect_insertfilterbyfilter) | Inserts a filter to the specified position.|
| [int32_t OH_ImageEffect_RemoveFilter(OH_ImageEffect *imageEffect, const char *filterName)](#oh_imageeffect_removefilter) | Removes a filter.|
| [ImageEffect_ErrorCode OH_ImageEffect_RemoveFilterByIndex(OH_ImageEffect *imageEffect, uint32_t index)](#oh_imageeffect_removefilterbyindex) | Removes a filter from the specified position.|
| [OH_EffectFilter *OH_ImageEffect_ReplaceFilter(OH_ImageEffect *imageEffect, uint32_t index, const char *filterName)](#oh_imageeffect_replacefilter) | Replaces a filter.|
| [ImageEffect_ErrorCode OH_ImageEffect_ReplaceFilterByFilter(OH_ImageEffect *imageEffect, uint32_t index, const char *filterName)](#oh_imageeffect_replacefilterbyfilter) | Replaces a filter at the specified position.|
| [int32_t OH_ImageEffect_GetFilterCount(OH_ImageEffect *imageEffect)](#oh_imageeffect_getfiltercount) | Obtains the number of added filters.|
| [OH_EffectFilter *OH_ImageEffect_GetFilter(OH_ImageEffect *imageEffect, uint32_t index)](#oh_imageeffect_getfilter) | Obtains the information about a filter.|
| [ImageEffect_ErrorCode OH_ImageEffect_Configure(OH_ImageEffect *imageEffect, const char *key, const ImageEffect_Any *value)](#oh_imageeffect_configure) | Configures an image effector.|
| [ImageEffect_ErrorCode OH_ImageEffect_SetOutputSurface(OH_ImageEffect *imageEffect, OHNativeWindow *nativeWindow)](#oh_imageeffect_setoutputsurface) | Sets an output surface.|
| [ImageEffect_ErrorCode OH_ImageEffect_GetInputSurface(OH_ImageEffect *imageEffect, OHNativeWindow **nativeWindow)](#oh_imageeffect_getinputsurface) | Obtains an input surface.|
| [ImageEffect_ErrorCode OH_ImageEffect_SetInputPixelmap(OH_ImageEffect *imageEffect, OH_PixelmapNative *pixelmap)](#oh_imageeffect_setinputpixelmap) | Sets an input PixelMap.|
| [ImageEffect_ErrorCode OH_ImageEffect_SetOutputPixelmap(OH_ImageEffect *imageEffect, OH_PixelmapNative *pixelmap)](#oh_imageeffect_setoutputpixelmap) | Sets an output PixelMap.|
| [ImageEffect_ErrorCode OH_ImageEffect_SetInputNativeBuffer(OH_ImageEffect *imageEffect, OH_NativeBuffer *nativeBuffer)](#oh_imageeffect_setinputnativebuffer) | Sets an input native buffer.|
| [ImageEffect_ErrorCode OH_ImageEffect_SetOutputNativeBuffer(OH_ImageEffect *imageEffect, OH_NativeBuffer *nativeBuffer)](#oh_imageeffect_setoutputnativebuffer) | Sets an output native buffer.|
| [ImageEffect_ErrorCode OH_ImageEffect_SetInputUri(OH_ImageEffect *imageEffect, const char *uri)](#oh_imageeffect_setinputuri) | Sets an input URI.|
| [ImageEffect_ErrorCode OH_ImageEffect_SetOutputUri(OH_ImageEffect *imageEffect, const char *uri)](#oh_imageeffect_setoutputuri) | Sets an output URI.|
| [ImageEffect_ErrorCode OH_ImageEffect_SetInputPicture(OH_ImageEffect *imageEffect, OH_PictureNative *picture)](#oh_imageeffect_setinputpicture) | Sets an input picture.|
| [ImageEffect_ErrorCode OH_ImageEffect_SetOutputPicture(OH_ImageEffect *imageEffect, OH_PictureNative *picture)](#oh_imageeffect_setoutputpicture) | Sets an output picture.|
| [ImageEffect_ErrorCode OH_ImageEffect_SetInputTextureId(OH_ImageEffect *imageEffect, int32_t textureId,int32_t colorSpace)](#oh_imageeffect_setinputtextureid) | Sets the ID of the input texture that contains the image information.|
| [ImageEffect_ErrorCode OH_ImageEffect_SetOutputTextureId(OH_ImageEffect *imageEffect, int32_t textureId)](#oh_imageeffect_setoutputtextureid) | Sets the ID of the output texture that contains the rendered image information.|
| [ImageEffect_ErrorCode OH_ImageEffect_Start(OH_ImageEffect *imageEffect)](#oh_imageeffect_start) | Starts an image effector.|
| [ImageEffect_ErrorCode OH_ImageEffect_Stop(OH_ImageEffect *imageEffect)](#oh_imageeffect_stop) | Stops an image effector.|
| [ImageEffect_ErrorCode OH_ImageEffect_Release(OH_ImageEffect *imageEffect)](#oh_imageeffect_release) | Releases an OH_ImageEffect instance.|
| [ImageEffect_ErrorCode OH_ImageEffect_Save(OH_ImageEffect *imageEffect, char **info)](#oh_imageeffect_save) | Serializes an image effector.|
| [OH_ImageEffect *OH_ImageEffect_Restore(const char *info)](#oh_imageeffect_restore) | Deserializes an image effector.|

## Function Description

### OH_ImageEffect_Create()

```
OH_ImageEffect *OH_ImageEffect_Create(const char *name)
```

**Description**

Creates an OH_ImageEffect instance. The instance must be released by calling [OH_ImageEffect_Release](capi-image-effect-h.md#oh_imageeffect_release) when it is no longer needed.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char *name | Pointer to the image effector name, which is used to identify the effector and can be customized. You are advised to set it to a non-empty string.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) * | Pointer to the OH_ImageEffect instance created. If the operation fails, a null pointer is returned.|

### OH_ImageEffect_AddFilter()

```
OH_EffectFilter *OH_ImageEffect_AddFilter(OH_ImageEffect *imageEffect, const char *filterName)
```

**Description**

Adds a filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|
| const char *filterName | Pointer to the filter name.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_EffectFilter](capi-imageeffect-oh-effectfilter.md) * | Pointer to the OH_EffectFilter instance created. If the effector is invalid, a null pointer is returned.|

### OH_ImageEffect_AddFilterByFilter()

```
ImageEffect_ErrorCode OH_ImageEffect_AddFilterByFilter(OH_ImageEffect *imageEffect, OH_EffectFilter *filter)
```

**Description**

Adds a specified filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|
| [OH_EffectFilter](capi-imageeffect-oh-effectfilter.md) *filter | Pointer to the filter.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_ImageEffect_InsertFilter()

```
OH_EffectFilter *OH_ImageEffect_InsertFilter(OH_ImageEffect *imageEffect, uint32_t index, const char *filterName)
```

**Description**

Inserts a filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|
| uint32_t index | Index of the filter.|
| const char *filterName | Pointer to the filter name.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_EffectFilter](capi-imageeffect-oh-effectfilter.md) * | Pointer to the OH_EffectFilter instance created. If the operation fails, a null pointer is returned.|

### OH_ImageEffect_InsertFilterByFilter()

```
ImageEffect_ErrorCode OH_ImageEffect_InsertFilterByFilter(OH_ImageEffect *imageEffect, uint32_t index,OH_EffectFilter *filter)
```

**Description**

Inserts a filter to the specified position.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|
| uint32_t index | Index of the filter.|
| [OH_EffectFilter](capi-imageeffect-oh-effectfilter.md) *filter | Pointer to the filter.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_ImageEffect_RemoveFilter()

```
int32_t OH_ImageEffect_RemoveFilter(OH_ImageEffect *imageEffect, const char *filterName)
```

**Description**

Removes a filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|
| const char *filterName | Pointer to the filter name.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Number of filters.|

### OH_ImageEffect_RemoveFilterByIndex()

```
ImageEffect_ErrorCode OH_ImageEffect_RemoveFilterByIndex(OH_ImageEffect *imageEffect, uint32_t index)
```

**Description**

Removes a filter from the specified position.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|
| uint32_t index | Index of the filter.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_ImageEffect_ReplaceFilter()

```
OH_EffectFilter *OH_ImageEffect_ReplaceFilter(OH_ImageEffect *imageEffect, uint32_t index, const char *filterName)
```

**Description**

Replaces a filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|
| const char *filterName | Pointer to the filter name.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_EffectFilter](capi-imageeffect-oh-effectfilter.md) * | Pointer to the OH_EffectFilter instance created. If the operation fails, a null pointer is returned.|

### OH_ImageEffect_ReplaceFilterByFilter()

```
ImageEffect_ErrorCode OH_ImageEffect_ReplaceFilterByFilter(OH_ImageEffect *imageEffect, uint32_t index,const char *filterName)
```

**Description**

Replaces a filter at the specified position.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|
| uint32_t index | Index of the filter.|
| const char *filterName | Pointer to the filter name.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_ImageEffect_GetFilterCount()

```
int32_t OH_ImageEffect_GetFilterCount(OH_ImageEffect *imageEffect)
```

**Description**

Obtains the number of added filters.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Number of filters.|

### OH_ImageEffect_GetFilter()

```
OH_EffectFilter *OH_ImageEffect_GetFilter(OH_ImageEffect *imageEffect, uint32_t index)
```

**Description**

Obtains the information about a filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|
| uint32_t index | Index of the filter.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_EffectFilter](capi-imageeffect-oh-effectfilter.md) * | Pointer to the OH_EffectFilter instance created. If the operation fails, a null pointer is returned.|

### OH_ImageEffect_Configure()

```
ImageEffect_ErrorCode OH_ImageEffect_Configure(OH_ImageEffect *imageEffect, const char *key,const ImageEffect_Any *value)
```

**Description**

Configures an image effector.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|
| const char *key | Pointer to the key of a configuration parameter.|
| [const ImageEffect_Any](capi-imageeffect-imageeffect-any.md) *value | Pointer to the value of a configuration parameter.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.<br>         **EFFECT_KEY_ERROR**: A parameter is invalid.<br>         **EFFECT_PARAM_ERROR**: A parameter value is invalid.|

### OH_ImageEffect_SetOutputSurface()

```
ImageEffect_ErrorCode OH_ImageEffect_SetOutputSurface(OH_ImageEffect *imageEffect, OHNativeWindow *nativeWindow)
```

**Description**

Sets an output surface.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|
| OHNativeWindow *nativeWindow | Pointer to the OHNativeWindow instance.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_ImageEffect_GetInputSurface()

```
ImageEffect_ErrorCode OH_ImageEffect_GetInputSurface(OH_ImageEffect *imageEffect, OHNativeWindow **nativeWindow)
```

**Description**

Obtains an input surface.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|
| OHNativeWindow **nativeWindow | Double pointer to the OHNativeWindow instance.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_ImageEffect_SetInputPixelmap()

```
ImageEffect_ErrorCode OH_ImageEffect_SetInputPixelmap(OH_ImageEffect *imageEffect, OH_PixelmapNative *pixelmap)
```

**Description**

Sets an input PixelMap.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to the OH_PixelmapNative instance.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_ImageEffect_SetOutputPixelmap()

```
ImageEffect_ErrorCode OH_ImageEffect_SetOutputPixelmap(OH_ImageEffect *imageEffect, OH_PixelmapNative *pixelmap)
```

**Description**

Sets an output PixelMap.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to the OH_PixelmapNative instance.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.<br>         **EFFECT_PARAM_ERROR**: The call fails because of abnormal parameters.|

### OH_ImageEffect_SetInputNativeBuffer()

```
ImageEffect_ErrorCode OH_ImageEffect_SetInputNativeBuffer(OH_ImageEffect *imageEffect, OH_NativeBuffer *nativeBuffer)
```

**Description**

Sets an input native buffer.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|
| [OH_NativeBuffer](../apis-arkgraphics2d/capi-oh-nativebuffer-oh-nativebuffer.md) *nativeBuffer | Pointer to the OH_NativeBuffer instance.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_ImageEffect_SetOutputNativeBuffer()

```
ImageEffect_ErrorCode OH_ImageEffect_SetOutputNativeBuffer(OH_ImageEffect *imageEffect, OH_NativeBuffer *nativeBuffer)
```

**Description**

Sets an output native buffer.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|
| [OH_NativeBuffer](../apis-arkgraphics2d/capi-oh-nativebuffer-oh-nativebuffer.md) *nativeBuffer | Pointer to an OH_NativeBuffer instance. The value can be NULL. If NULL is passed, the rendering result is returned to the input OH_NativeBuffer object.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.<br>          **EFFECT_PARAM_ERROR**: The call fails because of abnormal parameters.|

### OH_ImageEffect_SetInputUri()

```
ImageEffect_ErrorCode OH_ImageEffect_SetInputUri(OH_ImageEffect *imageEffect, const char *uri)
```

**Description**

Sets an input URI.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|
| const char *uri | Pointer to the URI of the image. Only JPEG and HEIF images are supported.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_ImageEffect_SetOutputUri()

```
ImageEffect_ErrorCode OH_ImageEffect_SetOutputUri(OH_ImageEffect *imageEffect, const char *uri)
```

**Description**

Sets an output URI.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|
| const char *uri | Pointer to the URI of the image. The format of the output URI is the same as that of the input URI. If HEIF encoding is not supported, JPEG encoding is used.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_ImageEffect_SetInputPicture()

```
ImageEffect_ErrorCode OH_ImageEffect_SetInputPicture(OH_ImageEffect *imageEffect, OH_PictureNative *picture)
```

**Description**

Sets an input picture.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to an OH_PictureNative instance.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_ImageEffect_SetOutputPicture()

```
ImageEffect_ErrorCode OH_ImageEffect_SetOutputPicture(OH_ImageEffect *imageEffect, OH_PictureNative *picture)
```

**Description**

Sets an output picture.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | Pointer to an OH_PictureNative instance. The value can be NULL. If NULL is passed, the rendering result is returned to the input OH_PictureNative object.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.<br>         **EFFECT_PARAM_ERROR**: The call fails because of abnormal parameters.|

### OH_ImageEffect_SetInputTextureId()

```
ImageEffect_ErrorCode OH_ImageEffect_SetInputTextureId(OH_ImageEffect *imageEffect, int32_t textureId,int32_t colorSpace)
```

**Description**

Sets the ID of the input texture that contains the image information.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to an instance of the OH_ImageEffect struct.|
| int32_t textureId | ID of the texture that contains the image information. This ID must be valid and have been bound to a texture of a GL_TEXTURE_2D type.|
| int32_t colorSpace | Color space of the image.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer or a parameter value is out of range.<br>         **EFFECT_PARAM_ERROR**: A parameter is missing or incorrect.|

### OH_ImageEffect_SetOutputTextureId()

```
ImageEffect_ErrorCode OH_ImageEffect_SetOutputTextureId(OH_ImageEffect *imageEffect, int32_t textureId)
```

**Description**

Sets the ID of the output texture that contains the rendered image information.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to an instance of the OH_ImageEffect struct.|
| int32_t textureId | ID of the texture that contains the rendered image information. This ID must be valid.<br> If it is not bound to a texture, it will automatically be bound to a GL_TEXTURE_2D type.<br> If the texture is already bound and the size is inappropriate, the rendered result may be cropped or partially filled into this texture.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer or a parameter value is out of range.<br>         **EFFECT_PARAM_ERROR**: A parameter is missing or incorrect.|

### OH_ImageEffect_Start()

```
ImageEffect_ErrorCode OH_ImageEffect_Start(OH_ImageEffect *imageEffect)
```

**Description**

Starts an image effector.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.<br>         **EFFECT_INPUT_OUTPUT_NOT_SUPPORTED**: The data types of the input and output images to be processed are different.<br>         **EFFECT_COLOR_SPACE_NOT_MATCH**: The color spaces of the input and output images are different.<br>         **EFFECT_ALLOCATE_MEMORY_FAILED**: Memory allocation fails.|

### OH_ImageEffect_Stop()

```
ImageEffect_ErrorCode OH_ImageEffect_Stop(OH_ImageEffect *imageEffect)
```

**Description**

Stops an image effector.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_ImageEffect_Release()

```
ImageEffect_ErrorCode OH_ImageEffect_Release(OH_ImageEffect *imageEffect)
```

**Description**

Releases an OH_ImageEffect instance.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_ImageEffect_Save()

```
ImageEffect_ErrorCode OH_ImageEffect_Save(OH_ImageEffect *imageEffect, char **info)
```

**Description**

Serializes an image effector.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) *imageEffect | Pointer to the image effector.|
| char **info | Double pointer to a char array holding a serialized JSON string.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | **EFFECT_SUCCESS**: The function is successfully called.<br>         **EFFECT_ERROR_PARAM_INVALID**: A parameter is a null pointer.|

### OH_ImageEffect_Restore()

```
OH_ImageEffect *OH_ImageEffect_Restore(const char *info)
```

**Description**

Deserializes an image effector.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char *info | Pointer to a serialized JSON string.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_ImageEffect](capi-imageeffect-oh-imageeffect.md) * | OH_ImageEffect instance. If the deserialization fails, a null pointer is returned.|
<!--no_check-->