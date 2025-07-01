# image_pixel_map_mdk.h

## Overview

The **image_pixel_map_napi.h** file declares the APIs used to lock, access, and unlock a PixelMap.

**Library**: libpixelmapndk.z.so

**Since**: 10

**Related module**: [Image](capi-image.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OhosPixelMapInfos](capi-image-ohospixelmapinfos.md) | OhosPixelMapInfos | Describes the information about a PixelMap.|
| [NativePixelMap_](capi-image-nativepixelmap-.md) | NativePixelMap | Describes the native PixelMap information. It defines the data type name of the PixelMap at the native layer.|
| [OhosPixelMapCreateOps](capi-image-ohospixelmapcreateops.md) | - | Describes the options used for creating a PixelMap.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [anonymous enum](#pixelmap-alpha-types)| - | Enumerates the PixelMap alpha types.|
| [anonymous enum](#pixelmap-editing-types)| - | Enumerates the PixelMap editing types.|
| [OH_PixelMap_AntiAliasingLevel](#oh_pixelmap_antialiasinglevel) | OH_PixelMap_AntiAliasingLevel | Enumerates the anti-aliasing levels used for scaling PixelMaps.|

### Functions

| Name| Description|
| -- | -- |
| [int32_t OH_PixelMap_CreatePixelMap(napi_env env, OhosPixelMapCreateOps info,void* buf, size_t len, napi_value* res)](#oh_pixelmap_createpixelmap) | Creates a PixelMap object. Currently, only BGRA input streams are supported.<br>The buffer passed in by this API does not support the stride.<br>This function does not support the DMA memory.|
| [int32_t OH_PixelMap_CreatePixelMapWithStride(napi_env env, OhosPixelMapCreateOps info,void* buf, size_t len, int32_t rowStride, napi_value* res)](#oh_pixelmap_createpixelmapwithstride) | Creates a PixelMap object.<br>Currently, only BGRA input streams are supported. For a PixelMap in RGBA format (with the size greater than 512\*512), DMA memory is used by default.|
| [int32_t OH_PixelMap_CreateAlphaPixelMap(napi_env env, napi_value source, napi_value* alpha)](#oh_pixelmap_createalphapixelmap) | Creates a PixelMap object that contains only alpha channel information.|
| [NativePixelMap* OH_PixelMap_InitNativePixelMap(napi_env env, napi_value source)](#oh_pixelmap_initnativepixelmap) | Initializes a NativePixelMap object.|
| [int32_t OH_PixelMap_GetBytesNumberPerRow(const NativePixelMap* native, int32_t* num)](#oh_pixelmap_getbytesnumberperrow) | Obtains the number of bytes per row of a NativePixelMap object.|
| [int32_t OH_PixelMap_GetIsEditable(const NativePixelMap* native, int32_t* editable)](#oh_pixelmap_getiseditable) | Checks whether a NativePixelMap object is editable.|
| [int32_t OH_PixelMap_IsSupportAlpha(const NativePixelMap* native, int32_t* alpha)](#oh_pixelmap_issupportalpha) | Checks whether a NativePixelMap object supports alpha channels.|
| [int32_t OH_PixelMap_SetAlphaAble(const NativePixelMap* native, int32_t alpha)](#oh_pixelmap_setalphaable) | Sets an alpha channel for a NativePixelMap object.|
| [int32_t OH_PixelMap_GetDensity(const NativePixelMap* native, int32_t* density)](#oh_pixelmap_getdensity) | Obtains the pixel density of a NativePixelMap object.|
| [int32_t OH_PixelMap_SetDensity(const NativePixelMap* native, int32_t density)](#oh_pixelmap_setdensity) | Sets the pixel density for a NativePixelMap object.|
| [int32_t OH_PixelMap_SetOpacity(const NativePixelMap* native, float opacity)](#oh_pixelmap_setopacity) | Sets the opacity for a NativePixelMap object.|
| [int32_t OH_PixelMap_Scale(const NativePixelMap* native, float x, float y)](#oh_pixelmap_scale) | Scales a NativePixelMap object.<br>You are advised to use the new function [OH_PixelmapNative_Scale](capi-pixelmap-native-h.md#oh_pixelmapnative_scale) since API version 12.|
| [int32_t OH_PixelMap_ScaleWithAntiAliasing(const NativePixelMap* native, float x, float y,OH_PixelMap_AntiAliasingLevel level)](#oh_pixelmap_scalewithantialiasing) | Scales a NativePixelMap object based on the specified anti-aliasing level, width, and height.<br>You are advised to use the new function [OH_PixelmapNative_ScaleWithAntiAliasing](capi-pixelmap-native-h.md#oh_pixelmapnative_scalewithantialiasing) since API version 12.|
| [int32_t OH_PixelMap_Translate(const NativePixelMap* native, float x, float y)](#oh_pixelmap_translate) | Translates a NativePixelMap object.<br>You are advised to use the new function [OH_PixelmapNative_Translate](capi-pixelmap-native-h.md#oh_pixelmapnative_translate) since API version 12.|
| [int32_t OH_PixelMap_Rotate(const NativePixelMap* native, float angle)](#oh_pixelmap_rotate) | Rotates a NativePixelMap object.<br>You are advised to use the new function [OH_PixelmapNative_Rotate](capi-pixelmap-native-h.md#oh_pixelmapnative_rotate) since API version 12.|
| [int32_t OH_PixelMap_Flip(const NativePixelMap* native, int32_t x, int32_t y)](#oh_pixelmap_flip) | Flips a NativePixelMap object.<br>You are advised to use the new function [OH_PixelmapNative_Flip](capi-pixelmap-native-h.md#oh_pixelmapnative_flip) since API version 12.|
| [int32_t OH_PixelMap_Crop(const NativePixelMap* native, int32_t x, int32_t y, int32_t width, int32_t height)](#oh_pixelmap_crop) | Crops a NativePixelMap object.<br>You are advised to use the new function [OH_PixelmapNative_Crop](capi-pixelmap-native-h.md#oh_pixelmapnative_crop) since API version 12.|
| [int32_t OH_PixelMap_GetImageInfo(const NativePixelMap* native, OhosPixelMapInfos *info)](#oh_pixelmap_getimageinfo) | Obtains the image information of a NativePixelMap object.<br>You are advised to use the new function [OH_PixelmapNative_GetImageInfo](capi-pixelmap-native-h.md#oh_pixelmapnative_getimageinfo) since API version 12.|
| [int32_t OH_PixelMap_AccessPixels(const NativePixelMap* native, void** addr)](#oh_pixelmap_accesspixels) | Obtains the memory address of a NativePixelMap object and locks the memory.|
| [int32_t OH_PixelMap_UnAccessPixels(const NativePixelMap* native)](#oh_pixelmap_unaccesspixels) | Unlocks the memory of a NativePixelMap object. This function is used with [OH_PixelMap_AccessPixels](#oh_pixelmap_accesspixels) in pairs.|

## Enum Description

### PixelMap Alpha Types

```
enum anonymous enum
```

**Description**

Enumerates the PixelMap alpha types.

**Since**: 10

| Enum Item| Description|
| -- | -- |
| OHOS_PIXEL_MAP_ALPHA_TYPE_UNKNOWN = 0 | Unknown format.|
| OHOS_PIXEL_MAP_ALPHA_TYPE_OPAQUE = 1 | Opaque format.|
| OHOS_PIXEL_MAP_ALPHA_TYPE_PREMUL = 2 | Premultiplied format.|
| OHOS_PIXEL_MAP_ALPHA_TYPE_UNPREMUL = 3 | Unpremultiplied format.|

### PixelMap Editing Types

```
enum anonymous enum
```

**Description**

Enumerates the PixelMap editing types.

**Since**: 10

| Enum Item| Description|
| -- | -- |
| OHOS_PIXEL_MAP_READ_ONLY = 0 | Read-only.|
| OHOS_PIXEL_MAP_EDITABLE = 1 | Editable.|

### OH_PixelMap_AntiAliasingLevel

```
enum OH_PixelMap_AntiAliasingLevel
```

**Description**

Enumerates the anti-aliasing levels used for scaling PixelMaps.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| OH_PixelMap_AntiAliasing_NONE = 0 | Nearest neighbor interpolation.|
| OH_PixelMap_AntiAliasing_LOW = 1 | Bilinear interpolation.|
| OH_PixelMap_AntiAliasing_MEDIUM = 2 | Bilinear interpolation with mipmap enabled. You are advised to use this value when zooming out an image.|
| OH_PixelMap_AntiAliasing_HIGH = 3 | Cubic interpolation.|


## Function Description

### OH_PixelMap_CreatePixelMap()

```
int32_t OH_PixelMap_CreatePixelMap(napi_env env, OhosPixelMapCreateOps info,void* buf, size_t len, napi_value* res)
```

**Description**

Creates a PixelMap object. Currently, only BGRA input streams are supported.

The buffer passed in by this API does not support the stride.

This function does not support the DMA memory.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the NAPI environment.|
| [OhosPixelMapCreateOps](capi-image-ohospixelmapcreateops.md) info | Options for setting the PixelMap object.|
| void* buf | Pointer to the buffer of the image.|
| size_t len | Image size.|
| napi_value* res | Pointer to the PixelMap object at the application layer.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br>**IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_GET_DATA_ABNORMAL**: An error occurs during image data retrieval.<br> **IMAGE_RESULT_DECODE_FAILED**: Decoding fails.<br> **IMAGE_RESULT_DECODE_HEAD_ABNORMAL**: An error occurs during decoding of the image header.<br> **IMAGE_RESULT_CREATE_DECODER_FAILED**: The decoder fails to be created.<br> **IMAGE_RESULT_CREATE_ENCODER_FAILED**: The encoder fails to be created.<br> **IMAGE_RESULT_CHECK_FORMAT_ERROR**: The format check fails.<br> **IMAGE_RESULT_THIRDPART_SKIA_ERROR**: Skia decoding fails.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The image input data is incorrect.<br> **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST**: Sharing the memory fails.<br> **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL**: Data in the shared memory is incorrect.<br> **IMAGE_RESULT_DECODE_ABNORMAL**: Image decoding fails.<br> **IMAGE_RESULT_DECODE_FAILED**: Decoding fails.<br> **IMAGE_RESULT_MALLOC_ABNORMAL**: An error occurs during memory allocation.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: The image data is not supported.<br> **IMAGE_RESULT_INIT_ABNORMAL**: The image fails to be initialized.<br> **IMAGE_RESULT_CROP**: Cropping fails.<br> **IMAGE_RESULT_UNKNOWN_FORMAT**: The image format is unknown.<br> **IMAGE_RESULT_PLUGIN_REGISTER_FAILED**: The plugin fails to be registered.<br>**IMAGE_RESULT_PLUGIN_CREATE_FAILED**: The plugin fails to be created.<br> **IMAGE_RESULT_ENCODE_FAILED**: The image fails to be encoded.<br> **IMAGE_RESULT_HW_DECODE_UNSUPPORT**: Hardware decoding is not supported.<br> **IMAGE_RESULT_HW_DECODE_FAILED**: Hardware decoding fails.<br> **IMAGE_RESULT_INDEX_INVALID**: IPC fails.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: A property is invalid.<br> **IMAGE_RESULT_ALPHA_TYPE_ERROR**: The alpha type is incorrect.<br> **IMAGE_RESULT_ALLOCATER_TYPE_ERROR**: The memory allocator type is incorrect.|

### OH_PixelMap_CreatePixelMapWithStride()

```
int32_t OH_PixelMap_CreatePixelMapWithStride(napi_env env, OhosPixelMapCreateOps info,void* buf, size_t len, int32_t rowStride, napi_value* res)
```

**Description**

Creates a PixelMap object.

Currently, only BGRA input streams are supported. For a PixelMap in RGBA format (with the size greater than 512\*512), DMA memory is used by default.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the NAPI environment.|
| [OhosPixelMapCreateOps](capi-image-ohospixelmapcreateops.md) info | Options for setting the PixelMap object.|
| void* buf | Pointer to the buffer of the image.|
| size_t len | Buffer size.|
| int32_t rowStride | Row stride. The stride is the actual memory size occupied by each row of the image, in bytes. Stride = Width \*Number of bytes per pixel + Padding, where padding refers to the extra space added at the end of each row for memory alignment purposes.|
| napi_value* res | Pointer to the PixelMap object at the application layer.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br>**IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_GET_DATA_ABNORMAL**: An error occurs during image data retrieval.<br> **IMAGE_RESULT_CHECK_FORMAT_ERROR**: The format check fails.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The image input data is incorrect.<br>**IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL**: Data in the shared memory is incorrect.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: The attribute is invalid or the image data is not supported.<br> **IMAGE_RESULT_UNKNOWN_FORMAT**: The image format is unknown.|

### OH_PixelMap_CreateAlphaPixelMap()

```
int32_t OH_PixelMap_CreateAlphaPixelMap(napi_env env, napi_value source, napi_value* alpha)
```

**Description**

Creates a PixelMap object that contains only alpha channel information.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the NAPI environment.|
| napi_value source | PixelMap object at the application layer.|
| napi_value* alpha | Pointer to the alpha channel.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br>**IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_GET_DATA_ABNORMAL**: An error occurs during image data retrieval.<br> **IMAGE_RESULT_DECODE_FAILED**: Decoding fails.<br> **IMAGE_RESULT_DECODE_HEAD_ABNORMAL**: An error occurs during decoding of the image header.<br> **IMAGE_RESULT_CREATE_DECODER_FAILED**: The decoder fails to be created.<br> **IMAGE_RESULT_CREATE_ENCODER_FAILED**: The encoder fails to be created.<br> **IMAGE_RESULT_CHECK_FORMAT_ERROR**: The format check fails.<br> **IMAGE_RESULT_THIRDPART_SKIA_ERROR**: Skia decoding fails.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The image input data is incorrect.<br> **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST**: Sharing the memory fails.<br> **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL**: Data in the shared memory is incorrect.<br> **IMAGE_RESULT_DECODE_ABNORMAL**: Image decoding fails.<br> **IMAGE_RESULT_MALLOC_ABNORMAL**: An error occurs during memory allocation.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: The image data is not supported.<br> **IMAGE_RESULT_INIT_ABNORMAL**: The image fails to be initialized.<br> **IMAGE_RESULT_CROP**: Cropping fails.<br> **IMAGE_RESULT_UNKNOWN_FORMAT**: The image format is unknown.<br> **IMAGE_RESULT_PLUGIN_REGISTER_FAILED**: The plugin fails to be registered.<br>**IMAGE_RESULT_PLUGIN_CREATE_FAILED**: The plugin fails to be created.<br> **IMAGE_RESULT_ENCODE_FAILED**: The image fails to be encoded.<br> **IMAGE_RESULT_HW_DECODE_UNSUPPORT**: Hardware decoding is not supported.<br> **IMAGE_RESULT_HW_DECODE_FAILED**: Hardware decoding fails.<br> **IMAGE_RESULT_INDEX_INVALID**: IPC fails.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: A property is invalid.<br> **IMAGE_RESULT_ALPHA_TYPE_ERROR**: The alpha type is incorrect.<br> **IMAGE_RESULT_ALLOCATER_TYPE_ERROR**: The memory allocator type is incorrect.|

### OH_PixelMap_InitNativePixelMap()

```
NativePixelMap* OH_PixelMap_InitNativePixelMap(napi_env env, napi_value source)
```

**Description**

Initializes a NativePixelMap object.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the NAPI environment.|
| napi_value source | PixelMap object at the application layer.|

**Returns**

| Type| Description|
| -- | -- |
| [NativePixelMap](capi-image-nativepixelmap-.md)* | Pointer to the NativePixelMap object. If the operation fails, an error code is returned.|

### OH_PixelMap_GetBytesNumberPerRow()

```
int32_t OH_PixelMap_GetBytesNumberPerRow(const NativePixelMap* native, int32_t* num)
```

**Description**

Obtains the number of bytes per row of a NativePixelMap object.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [NativePixelMap](capi-image-nativepixelmap-.md)* native | Pointer to a NativePixelMap object.|
| int32_t* num | Pointer to the number of bytes per row.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br>**IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The image input data is incorrect.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: A property is invalid.|

### OH_PixelMap_GetIsEditable()

```
int32_t OH_PixelMap_GetIsEditable(const NativePixelMap* native, int32_t* editable)
```

**Description**

Checks whether a NativePixelMap object is editable.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [NativePixelMap](capi-image-nativepixelmap-.md)* native | Pointer to a NativePixelMap object.|
| int32_t* editable |Pointer to the editing type of the NativePixelMap object.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br>**IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The image input data is incorrect.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: A property is invalid.|

### OH_PixelMap_IsSupportAlpha()

```
int32_t OH_PixelMap_IsSupportAlpha(const NativePixelMap* native, int32_t* alpha)
```

**Description**

Checks whether a NativePixelMap object supports alpha channels.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [NativePixelMap](capi-image-nativepixelmap-.md)* native | Pointer to a NativePixelMap object.|
| int32_t* alpha | Pointer to the support for alpha channels.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br>**IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The image input data is incorrect.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: A property is invalid.|

### OH_PixelMap_SetAlphaAble()

```
int32_t OH_PixelMap_SetAlphaAble(const NativePixelMap* native, int32_t alpha)
```

**Description**

Sets an alpha channel for a NativePixelMap object.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [NativePixelMap](capi-image-nativepixelmap-.md)* native | Pointer to a NativePixelMap object.|
| int32_t alpha | Alpha channel to set.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br>**IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The image input data is incorrect.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: A property is invalid.|

### OH_PixelMap_GetDensity()

```
int32_t OH_PixelMap_GetDensity(const NativePixelMap* native, int32_t* density)
```

**Description**

Obtains the pixel density of a NativePixelMap object.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [NativePixelMap](capi-image-nativepixelmap-.md)* native | Pointer to a NativePixelMap object.|
| int32_t* density | Pointer to the pixel density.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br>**IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The image input data is incorrect.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: A property is invalid.|

### OH_PixelMap_SetDensity()

```
int32_t OH_PixelMap_SetDensity(const NativePixelMap* native, int32_t density)
```

**Description**

Sets the pixel density for a NativePixelMap object.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [NativePixelMap](capi-image-nativepixelmap-.md)* native | Pointer to a NativePixelMap object.|
| int32_t density | Pixel density to set.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br>**IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The image input data is incorrect.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: A property is invalid.|

### OH_PixelMap_SetOpacity()

```
int32_t OH_PixelMap_SetOpacity(const NativePixelMap* native, float opacity)
```

**Description**

Sets the opacity for a NativePixelMap object.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [NativePixelMap](capi-image-nativepixelmap-.md)* native | Pointer to a NativePixelMap object.|
| float opacity | Opacity to set.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br>**IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The image input data is incorrect.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: A property is invalid.|

### OH_PixelMap_Scale()

```
int32_t OH_PixelMap_Scale(const NativePixelMap* native, float x, float y)
```

**Description**

Scales a NativePixelMap object.

You are advised to use the new function [OH_PixelmapNative_Scale](capi-pixelmap-native-h.md#oh_pixelmapnative_scale) since API version 12.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [NativePixelMap](capi-image-nativepixelmap-.md)* native | Pointer to a NativePixelMap object.|
| float x | Scale ratio of the width.|
| float y | Scale ratio of the height.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br>**IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_GET_DATA_ABNORMAL**: An error occurs during image data retrieval.<br> **IMAGE_RESULT_DECODE_FAILED**: Decoding fails.<br> **IMAGE_RESULT_CHECK_FORMAT_ERROR**: The format check fails.<br> **IMAGE_RESULT_THIRDPART_SKIA_ERROR**: Skia decoding fails.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The image input data is incorrect.<br> **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST**: Sharing the memory fails.<br> **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL**: Data in the shared memory is incorrect.<br> **IMAGE_RESULT_MALLOC_ABNORMAL**: An error occurs during memory allocation.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: The image data is not supported.<br> **IMAGE_RESULT_INIT_ABNORMAL**: The image fails to be initialized.<br> **IMAGE_RESULT_CROP**: Cropping fails.<br> **IMAGE_RESULT_UNKNOWN_FORMAT**: The image format is unknown.<br> **IMAGE_RESULT_PLUGIN_REGISTER_FAILED**: The plugin fails to be registered.<br>**IMAGE_RESULT_PLUGIN_CREATE_FAILED**: The plugin fails to be created.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: A property is invalid.<br> **IMAGE_RESULT_ALPHA_TYPE_ERROR**: The alpha type is incorrect.<br> **IMAGE_RESULT_ALLOCATER_TYPE_ERROR**: The memory allocator type is incorrect.|

### OH_PixelMap_ScaleWithAntiAliasing()

```
int32_t OH_PixelMap_ScaleWithAntiAliasing(const NativePixelMap* native, float x, float y,OH_PixelMap_AntiAliasingLevel level)
```

**Description**

Scales a NativePixelMap object based on the specified anti-aliasing level, width, and height.

You are advised to use the new function [OH_PixelmapNative_ScaleWithAntiAliasing](capi-pixelmap-native-h.md#oh_pixelmapnative_scalewithantialiasing) since API version 12.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativePixelMap](capi-image-nativepixelmap-.md)* native | Pointer to a NativePixelMap object.|
| float x | Scale ratio of the width.|
| float y | Scale ratio of the height.|
| [OH_PixelMap_AntiAliasingLevel](#oh_pixelmap_antialiasinglevel) level | Anti-aliasing level.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br> **IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_GET_DATA_ABNORMAL**: An error occurs during image data retrieval.<br> **IMAGE_RESULT_CHECK_FORMAT_ERROR**: The format check fails.<br> **IMAGE_RESULT_THIRDPART_SKIA_ERROR**: Skia decoding fails.<br>**IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL**: Data in the shared memory is incorrect.<br> **IMAGE_RESULT_MALLOC_ABNORMAL**: An error occurs during memory allocation.<br> **IMAGE_RESULT_UNKNOWN_FORMAT**: The image format is unknown.|

### OH_PixelMap_Translate()

```
int32_t OH_PixelMap_Translate(const NativePixelMap* native, float x, float y)
```

**Description**

Translates a NativePixelMap object.

You are advised to use the new function [OH_PixelmapNative_Translate](capi-pixelmap-native-h.md#oh_pixelmapnative_translate) since API version 12.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [NativePixelMap](capi-image-nativepixelmap-.md)* native | Pointer to a NativePixelMap object.|
| float x | Horizontal distance to translate.|
| float y | Vertical distance to translate.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br>**IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_GET_DATA_ABNORMAL**: An error occurs during image data retrieval.<br> **IMAGE_RESULT_DECODE_FAILED**: Decoding fails.<br> **IMAGE_RESULT_CHECK_FORMAT_ERROR**: The format check fails.<br> **IMAGE_RESULT_THIRDPART_SKIA_ERROR**: Skia decoding fails.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The image input data is incorrect.<br> **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST**: Sharing the memory fails.<br> **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL**: Data in the shared memory is incorrect.<br> **IMAGE_RESULT_MALLOC_ABNORMAL**: An error occurs during memory allocation.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: The image data is not supported.<br> **IMAGE_RESULT_CROP**: Cropping fails.<br> **IMAGE_RESULT_UNKNOWN_FORMAT**: The image format is unknown.<br> **IMAGE_RESULT_PLUGIN_REGISTER_FAILED**: The plugin fails to be registered.<br>**IMAGE_RESULT_PLUGIN_CREATE_FAILED**: The plugin fails to be created.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: A property is invalid.<br> **IMAGE_RESULT_ALPHA_TYPE_ERROR**: The alpha type is incorrect.<br> **IMAGE_RESULT_ALLOCATER_TYPE_ERROR**: The memory allocator type is incorrect.|

### OH_PixelMap_Rotate()

```
int32_t OH_PixelMap_Rotate(const NativePixelMap* native, float angle)
```

**Description**

Rotates a NativePixelMap object.

You are advised to use the new function [OH_PixelmapNative_Rotate](capi-pixelmap-native-h.md#oh_pixelmapnative_rotate) since API version 12.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [NativePixelMap](capi-image-nativepixelmap-.md)* native | Pointer to a NativePixelMap object.|
| float angle | Angle to rotate.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br>**IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_GET_DATA_ABNORMAL**: An error occurs during image data retrieval.<br> **IMAGE_RESULT_DECODE_FAILED**: Decoding fails.<br> **IMAGE_RESULT_CHECK_FORMAT_ERROR**: The format check fails.<br> **IMAGE_RESULT_THIRDPART_SKIA_ERROR**: Skia decoding fails.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The image input data is incorrect.<br> **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST**: Sharing the memory fails.<br> **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL**: Data in the shared memory is incorrect.<br> **IMAGE_RESULT_MALLOC_ABNORMAL**: An error occurs during memory allocation.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: The image data is not supported.<br> **IMAGE_RESULT_CROP**: Cropping fails.<br> **IMAGE_RESULT_UNKNOWN_FORMAT**: The image format is unknown.<br> **IMAGE_RESULT_PLUGIN_REGISTER_FAILED**: The plugin fails to be registered.<br>**IMAGE_RESULT_PLUGIN_CREATE_FAILED**: The plugin fails to be created.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: A property is invalid.<br> **IMAGE_RESULT_ALPHA_TYPE_ERROR**: The alpha type is incorrect.<br> **IMAGE_RESULT_ALLOCATER_TYPE_ERROR**: The memory allocator type is incorrect.|

### OH_PixelMap_Flip()

```
int32_t OH_PixelMap_Flip(const NativePixelMap* native, int32_t x, int32_t y)
```

**Description**

Flips a NativePixelMap object.

You are advised to use the new function [OH_PixelmapNative_Flip](capi-pixelmap-native-h.md#oh_pixelmapnative_flip) since API version 12.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [NativePixelMap](capi-image-nativepixelmap-.md)* native | Pointer to a NativePixelMap object.|
| int32_t x | Whether to flip around the x axis.|
| int32_t y | Whether to flip around the y axis.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br>**IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_GET_DATA_ABNORMAL**: An error occurs during image data retrieval.<br> **IMAGE_RESULT_DECODE_FAILED**: Decoding fails.<br> **IMAGE_RESULT_CHECK_FORMAT_ERROR**: The format check fails.<br> **IMAGE_RESULT_THIRDPART_SKIA_ERROR**: Skia decoding fails.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The image input data is incorrect.<br> **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST**: Sharing the memory fails.<br> **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL**: Data in the shared memory is incorrect.<br> **IMAGE_RESULT_MALLOC_ABNORMAL**: An error occurs during memory allocation.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: The image data is not supported.<br> **IMAGE_RESULT_CROP**: Cropping fails.<br> **IMAGE_RESULT_UNKNOWN_FORMAT**: The image format is unknown.<br> **IMAGE_RESULT_PLUGIN_REGISTER_FAILED**: The plugin fails to be registered.<br>**IMAGE_RESULT_PLUGIN_CREATE_FAILED**: The plugin fails to be created.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: A property is invalid.<br> **IMAGE_RESULT_ALPHA_TYPE_ERROR**: The alpha type is incorrect.<br> **IMAGE_RESULT_ALLOCATER_TYPE_ERROR**: The memory allocator type is incorrect.|

### OH_PixelMap_Crop()

```
int32_t OH_PixelMap_Crop(const NativePixelMap* native, int32_t x, int32_t y, int32_t width, int32_t height)
```

**Description**

Crops a NativePixelMap object.

You are advised to use the new function [OH_PixelmapNative_Crop](capi-pixelmap-native-h.md#oh_pixelmapnative_crop) since API version 12.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [NativePixelMap](capi-image-nativepixelmap-.md)* native | Pointer to a NativePixelMap object.|
| int32_t x | X-coordinate of the upper left corner of the target image.|
| int32_t y | Y-coordinate of the upper left corner of the target image.|
| int32_t width | Width of the cropped region.|
| int32_t height | Height of the cropped region.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br>**IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_GET_DATA_ABNORMAL**: An error occurs during image data retrieval.<br> **IMAGE_RESULT_DECODE_FAILED**: Decoding fails.<br> **IMAGE_RESULT_CHECK_FORMAT_ERROR**: The format check fails.<br> **IMAGE_RESULT_THIRDPART_SKIA_ERROR**: Skia decoding fails.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The image input data is incorrect.<br> **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST**: Sharing the memory fails.<br> **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL**: Data in the shared memory is incorrect.<br> **IMAGE_RESULT_MALLOC_ABNORMAL**: An error occurs during memory allocation.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: The image data is not supported.<br> **IMAGE_RESULT_CROP**: Cropping fails.<br> **IMAGE_RESULT_UNKNOWN_FORMAT**: The image format is unknown.<br> **IMAGE_RESULT_PLUGIN_REGISTER_FAILED**: The plugin fails to be registered.<br>**IMAGE_RESULT_PLUGIN_CREATE_FAILED**: The plugin fails to be created.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: A property is invalid.<br> **IMAGE_RESULT_ALPHA_TYPE_ERROR**: The alpha type is incorrect.<br> **IMAGE_RESULT_ALLOCATER_TYPE_ERROR**: The memory allocator type is incorrect.|

### OH_PixelMap_GetImageInfo()

```
int32_t OH_PixelMap_GetImageInfo(const NativePixelMap* native, OhosPixelMapInfos *info)
```

**Description**

Obtains the image information of a NativePixelMap object.

You are advised to use the new function [OH_PixelmapNative_GetImageInfo](capi-pixelmap-native-h.md#oh_pixelmapnative_getimageinfo) since API version 12.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [NativePixelMap](capi-image-nativepixelmap-.md)* native | Pointer to a NativePixelMap object.|
| [OhosPixelMapInfos](capi-image-ohospixelmapinfos.md) *info | Pointer to the image information.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br>**IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_GET_DATA_ABNORMAL**: An error occurs during image data retrieval.<br> **IMAGE_RESULT_DECODE_FAILED**: Decoding fails.<br> **IMAGE_RESULT_CHECK_FORMAT_ERROR**: The format check fails.<br> **IMAGE_RESULT_THIRDPART_SKIA_ERROR**: Skia decoding fails.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The image input data is incorrect.<br> **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST**: Sharing the memory fails.<br> **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL**: Data in the shared memory is incorrect.<br> **IMAGE_RESULT_MALLOC_ABNORMAL**: An error occurs during memory allocation.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: The image data is not supported.<br> **IMAGE_RESULT_CROP**: Cropping fails.<br> **IMAGE_RESULT_UNKNOWN_FORMAT**: The image format is unknown.<br> **IMAGE_RESULT_PLUGIN_REGISTER_FAILED**: The plugin fails to be registered.<br>**IMAGE_RESULT_PLUGIN_CREATE_FAILED**: The plugin fails to be created.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: A property is invalid.<br> **IMAGE_RESULT_ALPHA_TYPE_ERROR**: The alpha type is incorrect.<br> **IMAGE_RESULT_ALLOCATER_TYPE_ERROR**: The memory allocator type is incorrect.|

### OH_PixelMap_AccessPixels()

```
int32_t OH_PixelMap_AccessPixels(const NativePixelMap* native, void** addr)
```

**Description**

Obtains the memory address of a NativePixelMap object and locks the memory.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [NativePixelMap](capi-image-nativepixelmap-.md)* native | Pointer to a NativePixelMap object.|
| void** addr | Double pointer to the memory address.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br>**IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_GET_DATA_ABNORMAL**: An error occurs during image data retrieval.<br> **IMAGE_RESULT_DECODE_FAILED**: Decoding fails.<br> **IMAGE_RESULT_CHECK_FORMAT_ERROR**: The format check fails.<br> **IMAGE_RESULT_THIRDPART_SKIA_ERROR**: Skia decoding fails.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The image input data is incorrect.<br> **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST**: Sharing the memory fails.<br> **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL**: Data in the shared memory is incorrect.<br> **IMAGE_RESULT_MALLOC_ABNORMAL**: An error occurs during memory allocation.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: The image data is not supported.<br> **IMAGE_RESULT_CROP**: Cropping fails.<br> **IMAGE_RESULT_UNKNOWN_FORMAT**: The image format is unknown.<br> **IMAGE_RESULT_PLUGIN_REGISTER_FAILED**: The plugin fails to be registered.<br>**IMAGE_RESULT_PLUGIN_CREATE_FAILED**: The plugin fails to be created.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: A property is invalid.<br> **IMAGE_RESULT_ALPHA_TYPE_ERROR**: The alpha type is incorrect.<br> **IMAGE_RESULT_ALLOCATER_TYPE_ERROR**: The memory allocator type is incorrect.|

### OH_PixelMap_UnAccessPixels()

```
int32_t OH_PixelMap_UnAccessPixels(const NativePixelMap* native)
```

**Description**

Unlocks the memory of a NativePixelMap object. This function is used with [OH_PixelMap_AccessPixels](#oh_pixelmap_accesspixels) in pairs.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [NativePixelMap](capi-image-nativepixelmap-.md)* native | Pointer to a NativePixelMap object.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code defined in [IRNdkErrCode](capi-image-mdk-common-h.md#irndkerrcode):<br>**IMAGE_RESULT_SUCCESS**: The operation is successful.<br>**IMAGE_RESULT_BAD_PARAMETER**: A parameter is incorrect.<br>**IMAGE_RESULT_JNI_ENV_ABNORMAL**: The JNI environment is abnormal.<br> **IMAGE_RESULT_INVALID_PARAMETER**: A parameter is invalid.<br> **IMAGE_RESULT_GET_DATA_ABNORMAL**: An error occurs during image data retrieval.<br> **IMAGE_RESULT_DECODE_FAILED**: Decoding fails.<br> **IMAGE_RESULT_CHECK_FORMAT_ERROR**: The format check fails.<br> **IMAGE_RESULT_THIRDPART_SKIA_ERROR**: Skia decoding fails.<br> **IMAGE_RESULT_DATA_ABNORMAL**: The image input data is incorrect.<br> **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST**: Sharing the memory fails.<br> **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL**: Data in the shared memory is incorrect.<br> **IMAGE_RESULT_MALLOC_ABNORMAL**: An error occurs during memory allocation.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: The image data is not supported.<br> **IMAGE_RESULT_CROP**: Cropping fails.<br> **IMAGE_RESULT_UNKNOWN_FORMAT**: The image format is unknown.<br> **IMAGE_RESULT_PLUGIN_REGISTER_FAILED**: The plugin fails to be registered.<br>**IMAGE_RESULT_PLUGIN_CREATE_FAILED**: The plugin fails to be created.<br> **IMAGE_RESULT_DATA_UNSUPPORT**: A property is invalid.<br> **IMAGE_RESULT_ALPHA_TYPE_ERROR**: The alpha type is incorrect.<br> **IMAGE_RESULT_ALLOCATER_TYPE_ERROR**: The memory allocator type is incorrect.|
