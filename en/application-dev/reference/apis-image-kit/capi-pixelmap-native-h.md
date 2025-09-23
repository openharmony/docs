# pixelmap_native.h
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yaozhupeng-->
<!--Designer: @yaozhupeng-->
<!--Tester: @zhaoxiaoguang2-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the APIs for accessing a PixelMap.

**File to include**: <multimedia/image_framework/image/pixelmap_native.h>

**Library**: libpixelmap.so

**System capability**: SystemCapability.Multimedia.Image.Core

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) | OH_PixelmapNative | Describes an uncompressed PixelMap format, which is encapsulated at the native layer after images are decoded.|
| [OH_NativeBuffer](capi-image-nativemodule-image-nativemodule-oh-nativebuffer.md) | OH_NativeBuffer | Describes the native buffer, which is used to perform operations related to the native buffer.|
| [OH_Pixelmap_HdrStaticMetadata](capi-image-nativemodule-oh-pixelmap-hdrstaticmetadata.md) | OH_Pixelmap_HdrStaticMetadata | Describes the static metadata values available for the key **HDR_STATIC_METADATA**.|
| [OH_NativeColorSpaceManager](capi-image-nativemodule-oh-nativecolorspacemanager.md) | OH_NativeColorSpaceManager | Describes the native color space manager, which is used to perform operations related to the native color space manager.|
| [OH_Pixelmap_HdrDynamicMetadata](capi-image-nativemodule-oh-pixelmap-hdrdynamicmetadata.md) | OH_Pixelmap_HdrDynamicMetadata | Describes the dynamic metadata values available for the key **DR_DYNAMIC_METADATA**.|
| [OH_Pixelmap_HdrGainmapMetadata](capi-image-nativemodule-oh-pixelmap-hdrgainmapmetadata.md) | OH_Pixelmap_HdrGainmapMetadata | Describes the gain map metadata values available for the key **HDR_GAINMAP_METADATA**. For details, see ISO 21496-1.|
| [OH_Pixelmap_HdrMetadataValue](capi-image-nativemodule-oh-pixelmap-hdrmetadatavalue.md) | OH_Pixelmap_HdrMetadataValue | Describes the HDR metadata values used by the PixelMap and available for the key **OH_Pixelmap_HdrMetadataKey**.|
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) | OH_Pixelmap_InitializationOptions | Describes the initialization options encapsulated at the native layer. The struct is used to set the initialization parameters for a PixelMap.|
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) | OH_Pixelmap_ImageInfo | Describes the image information encapsulated at the native layer. The struct stores the width, height, row stride, pixel format, and HDR of an image.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [PIXELMAP_ALPHA_TYPE](#pixelmap_alpha_type) | PIXELMAP_ALPHA_TYPE | Enumerates the alpha types of a PixelMap.|
| [PIXEL_FORMAT](#pixel_format) | PIXEL_FORMAT | Enumerates the image pixel formats.|
| [OH_PixelmapNative_AntiAliasingLevel](#oh_pixelmapnative_antialiasinglevel) | OH_PixelmapNative_AntiAliasingLevel | Enumerates the anti-aliasing levels used for scaling PixelMaps.|
| [OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey) | OH_Pixelmap_HdrMetadataKey | Enumerates the keys of the HDR related metadata information used by the PixelMap. It is used in [OH_PixelmapNative_SetMetadata](#oh_pixelmapnative_setmetadata) and [OH_PixelmapNative_GetMetadata](#oh_pixelmapnative_getmetadata).|
| [OH_Pixelmap_HdrMetadataType](#oh_pixelmap_hdrmetadatatype) | OH_Pixelmap_HdrMetadataType | Enumerates the HDR metadata types, which are the values of **HDR_METADATA_TYPE**.|

### Functions

| Name| Description|
| -- | -- |
| [Image_ErrorCode OH_PixelmapInitializationOptions_Create(OH_Pixelmap_InitializationOptions **options)](#oh_pixelmapinitializationoptions_create) | Creates the pointer to an OH_Pixelmap_InitializationOptions struct.|
| [Image_ErrorCode OH_PixelmapInitializationOptions_GetWidth(OH_Pixelmap_InitializationOptions *options, uint32_t *width)](#oh_pixelmapinitializationoptions_getwidth) | Obtains the image width.|
| [Image_ErrorCode OH_PixelmapInitializationOptions_SetWidth(OH_Pixelmap_InitializationOptions *options, uint32_t width)](#oh_pixelmapinitializationoptions_setwidth) | Sets the image width.|
| [Image_ErrorCode OH_PixelmapInitializationOptions_GetHeight(OH_Pixelmap_InitializationOptions *options, uint32_t *height)](#oh_pixelmapinitializationoptions_getheight) | Obtains the image height.|
| [Image_ErrorCode OH_PixelmapInitializationOptions_SetHeight(OH_Pixelmap_InitializationOptions *options, uint32_t height)](#oh_pixelmapinitializationoptions_setheight) | Sets the image height.|
| [Image_ErrorCode OH_PixelmapInitializationOptions_GetPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t *pixelFormat)](#oh_pixelmapinitializationoptions_getpixelformat) | Obtains the pixel format.|
| [Image_ErrorCode OH_PixelmapInitializationOptions_SetPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t pixelFormat)](#oh_pixelmapinitializationoptions_setpixelformat) | Sets the pixel format.|
| [Image_ErrorCode OH_PixelmapInitializationOptions_GetSrcPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t *srcpixelFormat)](#oh_pixelmapinitializationoptions_getsrcpixelformat) | Obtains the source pixel format.|
| [Image_ErrorCode OH_PixelmapInitializationOptions_SetSrcPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t srcpixelFormat)](#oh_pixelmapinitializationoptions_setsrcpixelformat) | Sets the source pixel format.|
| [Image_ErrorCode OH_PixelmapInitializationOptions_GetRowStride(OH_Pixelmap_InitializationOptions *options, int32_t *rowStride)](#oh_pixelmapinitializationoptions_getrowstride) | Obtains the row stride.<br>The stride is the actual memory size occupied by each row of the image, in bytes. Stride = Width \*Number of bytes per pixel + Padding, where padding refers to the extra space added at the end of each row for memory alignment purposes.|
| [Image_ErrorCode OH_PixelmapInitializationOptions_SetRowStride(OH_Pixelmap_InitializationOptions *options, int32_t rowStride)](#oh_pixelmapinitializationoptions_setrowstride) | Sets the row stride.<br>The stride is the actual memory size occupied by each row of the image, in bytes. Stride = Width \*Number of bytes per pixel + Padding, where padding refers to the extra space added at the end of each row for memory alignment purposes.|
| [Image_ErrorCode OH_PixelmapInitializationOptions_GetAlphaType(OH_Pixelmap_InitializationOptions *options, int32_t *alphaType)](#oh_pixelmapinitializationoptions_getalphatype) | Obtains the alpha type.|
| [Image_ErrorCode OH_PixelmapInitializationOptions_SetAlphaType(OH_Pixelmap_InitializationOptions *options, int32_t alphaType)](#oh_pixelmapinitializationoptions_setalphatype) | Sets the alpha type.|
| [Image_ErrorCode OH_PixelmapInitializationOptions_GetEditable(OH_Pixelmap_InitializationOptions *options, bool *editable)](#oh_pixelmapinitializationoptions_geteditable) | Obtains the editable flag.|
| [Image_ErrorCode OH_PixelmapInitializationOptions_SetEditable(OH_Pixelmap_InitializationOptions *options, bool editable)](#oh_pixelmapinitializationoptions_seteditable) | Sets the editable flag.|
| [Image_ErrorCode OH_PixelmapInitializationOptions_Release(OH_Pixelmap_InitializationOptions *options)](#oh_pixelmapinitializationoptions_release) | Releases the pointer to an OH_Pixelmap_InitializationOptions struct.|
| [Image_ErrorCode OH_PixelmapImageInfo_Create(OH_Pixelmap_ImageInfo **info)](#oh_pixelmapimageinfo_create) | Creates the pointer to an OH_Pixelmap_ImageInfo struct.|
| [Image_ErrorCode OH_PixelmapImageInfo_GetWidth(OH_Pixelmap_ImageInfo *info, uint32_t *width)](#oh_pixelmapimageinfo_getwidth) | Obtains the image width.|
| [Image_ErrorCode OH_PixelmapImageInfo_GetHeight(OH_Pixelmap_ImageInfo *info, uint32_t *height)](#oh_pixelmapimageinfo_getheight) | Obtains the image height.|
| [Image_ErrorCode OH_PixelmapImageInfo_GetAlphaMode(OH_Pixelmap_ImageInfo *info, int32_t *AlphaMode)](#oh_pixelmapimageinfo_getalphamode) | Obtains the alpha format of an image.|
| [Image_ErrorCode OH_PixelmapImageInfo_GetRowStride(OH_Pixelmap_ImageInfo *info, uint32_t *rowStride)](#oh_pixelmapimageinfo_getrowstride) | Obtains the row stride.|
| [Image_ErrorCode OH_PixelmapImageInfo_GetPixelFormat(OH_Pixelmap_ImageInfo *info, int32_t *pixelFormat)](#oh_pixelmapimageinfo_getpixelformat) | Obtains the pixel format.|
| [Image_ErrorCode OH_PixelmapImageInfo_GetAlphaType(OH_Pixelmap_ImageInfo *info, int32_t *alphaType)](#oh_pixelmapimageinfo_getalphatype) | Obtains the alpha type.|
| [Image_ErrorCode OH_PixelmapImageInfo_GetDynamicRange(OH_Pixelmap_ImageInfo *info, bool *isHdr)](#oh_pixelmapimageinfo_getdynamicrange) | Obtains the dynamic range of a PixelMap.|
| [Image_ErrorCode OH_PixelmapImageInfo_Release(OH_Pixelmap_ImageInfo *info)](#oh_pixelmapimageinfo_release) | Releases the pointer to an OH_Pixelmap_ImageInfo struct.|
| [Image_ErrorCode OH_PixelmapNative_CreatePixelmap(uint8_t *data, size_t dataLength, OH_Pixelmap_InitializationOptions *options, OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_createpixelmap) | Creates a PixelMap based on properties. By default, the BGRA_8888 format is used for data processing. For details about other formats, see [OH_PixelmapInitializationOptions_SetSrcPixelFormat](#oh_pixelmapinitializationoptions_setsrcpixelformat).|
| [Image_ErrorCode OH_PixelmapNative_CreatePixelmapUsingAllocator(uint8_t *data, size_t dataLength, OH_Pixelmap_InitializationOptions *options, IMAGE_ALLOCATOR_MODE allocator, OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_createpixelmapusingallocator) | Creates a PixelMap object based on the options and memory type, where **allocator** specifies the memory type of the PixelMap. By default, the system selects an appropriate memory type based on the image type, image size, and platform capability. When processing the returned PixelMap object, consider the impact of stride.|
| [Image_ErrorCode OH_PixelmapNative_ConvertPixelmapNativeToNapi(napi_env env, OH_PixelmapNative *pixelmapNative, napi_value *pixelmapNapi)](#oh_pixelmapnative_convertpixelmapnativetonapi) | Converts a nativePixelMap object to a PixelMapnapi object.|
| [Image_ErrorCode OH_PixelmapNative_ConvertPixelmapNativeFromNapi(napi_env env, napi_value pixelmapNapi, OH_PixelmapNative **pixelmapNative)](#oh_pixelmapnative_convertpixelmapnativefromnapi) | Converts a PixelMapnapi object to a nativePixelMap object.|
| [Image_ErrorCode OH_PixelmapNative_ReadPixels(OH_PixelmapNative *pixelmap, uint8_t *destination, size_t *bufferSize)](#oh_pixelmapnative_readpixels) | Reads the pixels of a PixelMap and writes the result to the buffer based on the pixel format of the PixelMap.|
| [Image_ErrorCode OH_PixelmapNative_WritePixels(OH_PixelmapNative *pixelmap, uint8_t *source, size_t bufferSize)](#oh_pixelmapnative_writepixels) | Reads the pixels in the buffer and writes the result to the PixelMap based on the pixel format of the PixelMap.|
| [Image_ErrorCode OH_PixelmapNative_GetArgbPixels(OH_PixelmapNative *pixelmap, uint8_t *destination, size_t *bufferSize)](#oh_pixelmapnative_getargbpixels) | Reads data in ARGB format from a PixelMap.|
| [Image_ErrorCode OH_PixelmapNative_ToSdr(OH_PixelmapNative *pixelmap)](#oh_pixelmapnative_tosdr) | Converts a PixelMap from the HDR format to the SDR format.|
| [Image_ErrorCode OH_PixelmapNative_GetImageInfo(OH_PixelmapNative *pixelmap, OH_Pixelmap_ImageInfo *imageInfo)](#oh_pixelmapnative_getimageinfo) | Obtains the image information of a PixelMap.|
| [Image_ErrorCode OH_PixelmapNative_Opacity(OH_PixelmapNative *pixelmap, float rate)](#oh_pixelmapnative_opacity) | Sets the opacity rate to enable the PixelMap to achieve the corresponding opacity effect.|
| [Image_ErrorCode OH_PixelmapNative_Scale(OH_PixelmapNative *pixelmap, float scaleX, float scaleY)](#oh_pixelmapnative_scale) | Scales a PixelMap based on a given width and height.|
| [Image_ErrorCode OH_PixelmapNative_ScaleWithAntiAliasing(OH_PixelmapNative *pixelmap, float scaleX, float scaleY, OH_PixelmapNative_AntiAliasingLevel level)](#oh_pixelmapnative_scalewithantialiasing) | Scales a PixelMap based on the specified anti-aliasing level, width, and height.|
| [Image_ErrorCode OH_PixelmapNative_CreateScaledPixelMap(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap, float scaleX, float scaleY)](#oh_pixelmapnative_createscaledpixelmap) | Creates a PixelMap that has been resized based on the specified scale factors of the width and height.|
| [Image_ErrorCode OH_PixelmapNative_CreateScaledPixelMapWithAntiAliasing(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap, float scaleX, float scaleY, OH_PixelmapNative_AntiAliasingLevel level)](#oh_pixelmapnative_createscaledpixelmapwithantialiasing) | Creates a PixelMap that has been resized based on the specified anti-aliasing level and the scale factors of the width and height.|
| [Image_ErrorCode OH_PixelmapNative_Translate(OH_PixelmapNative *pixelmap, float x, float y)](#oh_pixelmapnative_translate) | Translates a PixelMap based on given coordinates.|
| [Image_ErrorCode OH_PixelmapNative_Rotate(OH_PixelmapNative *pixelmap, float angle)](#oh_pixelmapnative_rotate) | Rotates a PixelMap based on a given angle.|
| [Image_ErrorCode OH_PixelmapNative_Flip(OH_PixelmapNative *pixelmap, bool shouldFilpHorizontally, bool shouldFilpVertically)](#oh_pixelmapnative_flip) | Flips a PixelMap based on a given angle.|
| [Image_ErrorCode OH_PixelmapNative_Crop(OH_PixelmapNative *pixelmap, Image_Region *region)](#oh_pixelmapnative_crop) | Crops a PixelMap based on a given size.|
| [Image_ErrorCode OH_PixelmapNative_Release(OH_PixelmapNative *pixelmap)](#oh_pixelmapnative_release) | Releases the pointer to an OH_PixelmapNative object. [OH_PixelmapNative_Destroy](#oh_pixelmapnative_destroy) is recommended.|
| [Image_ErrorCode OH_PixelmapNative_Destroy(OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_destroy) | Releases the pointer to an OH_PixelmapNative object.|
| [Image_ErrorCode OH_PixelmapNative_ConvertAlphaFormat(OH_PixelmapNative* srcpixelmap, OH_PixelmapNative* dstpixelmap, const bool isPremul)](#oh_pixelmapnative_convertalphaformat) | Converts pixel data of a PixelMap from premultiplied alpha to non-premultiplied alpha, or vice versa.|
| [Image_ErrorCode OH_PixelmapNative_CreateEmptyPixelmap(OH_Pixelmap_InitializationOptions *options, OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_createemptypixelmap) | Creates an empty PixelMap object based on **OH_Pixelmap_InitializationOptions**. The memory data is 0.|
| [Image_ErrorCode OH_PixelmapNative_CreateEmptyPixelmapUsingAllocator(OH_Pixelmap_InitializationOptions *options, IMAGE_ALLOCATOR_MODE allocator, OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_createemptypixelmapusingallocator) | Creates an empty PixelMap object based on the options and memory type, where **allocator** specifies the memory type of the PixelMap. By default, the system selects an appropriate memory type based on the image type, image size, and platform capability. When processing the returned PixelMap object, consider the impact of stride.|
| [Image_ErrorCode OH_PixelmapNative_GetNativeBuffer(OH_PixelmapNative *pixelmap, OH_NativeBuffer **nativeBuffer)](#oh_pixelmapnative_getnativebuffer) | Obtains the NativeBuffer object from a PixelMap in the DMA memory.|
| [Image_ErrorCode OH_PixelmapNative_GetMetadata(OH_PixelmapNative *pixelmap, OH_Pixelmap_HdrMetadataKey key, OH_Pixelmap_HdrMetadataValue **value)](#oh_pixelmapnative_getmetadata) | Obtains the metadata.|
| [Image_ErrorCode OH_PixelmapNative_SetMetadata(OH_PixelmapNative *pixelmap, OH_Pixelmap_HdrMetadataKey key, OH_Pixelmap_HdrMetadataValue *value)](#oh_pixelmapnative_setmetadata) | Sets the metadata.|
| [Image_ErrorCode OH_PixelmapNative_SetColorSpaceNative(OH_PixelmapNative *pixelmap, OH_NativeColorSpaceManager *colorSpaceNative)](#oh_pixelmapnative_setcolorspacenative) | Sets a NativeColorSpaceManager object.|
| [Image_ErrorCode OH_PixelmapNative_GetColorSpaceNative(OH_PixelmapNative *pixelmap, OH_NativeColorSpaceManager **colorSpaceNative)](#oh_pixelmapnative_getcolorspacenative) | Obtains a NativeColorSpaceManager object.|
| [Image_ErrorCode OH_PixelmapNative_SetMemoryName(OH_PixelmapNative *pixelmap, char *name, size_t *size)](#oh_pixelmapnative_setmemoryname) | Sets the memory name of a PixelMap.|
| [Image_ErrorCode OH_PixelmapNative_GetByteCount(OH_PixelmapNative *pixelmap, uint32_t *byteCount)](#oh_pixelmapnative_getbytecount) | Obtains the total number of bytes occupied by all pixels in a PixelMap, excluding any memory padding.|
| [Image_ErrorCode OH_PixelmapNative_GetAllocationByteCount(OH_PixelmapNative *pixelmap, uint32_t *allocationByteCount)](#oh_pixelmapnative_getallocationbytecount) | Obtains the number of bytes in the memory allocated by a PixelMap to store pixels.|
| [Image_ErrorCode OH_PixelmapNative_AccessPixels(OH_PixelmapNative *pixelmap, void **addr)](#oh_pixelmapnative_accesspixels) | Obtains the memory address where the pixels of a PixelMap are stored and locks the memory.<br>When the memory is locked, any attempts to alter or free the pixel data of the PixelMap will fail or be ineffective.|
| [Image_ErrorCode OH_PixelmapNative_UnaccessPixels(OH_PixelmapNative *pixelmap)](#oh_pixelmapnative_unaccesspixels) | Unlocks the memory allocated to store the pixels of a PixelMap.<br>This function must be used together with [OH_PixelmapNative_AccessPixels](#oh_pixelmapnative_accesspixels).|

## Enum Description

### PIXELMAP_ALPHA_TYPE

```
enum PIXELMAP_ALPHA_TYPE
```

**Description**

Enumerates the alpha types of a PixelMap.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| PIXELMAP_ALPHA_TYPE_UNKNOWN = 0 | Unknown format.|
| PIXELMAP_ALPHA_TYPE_OPAQUE = 1 | Opaque format.|
| PIXELMAP_ALPHA_TYPE_PREMULTIPLIED = 2 | Premultiplied format.|
| PIXELMAP_ALPHA_TYPE_UNPREMULTIPLIED = 3 | Non-premultiplied format.|

### PIXEL_FORMAT

```
enum PIXEL_FORMAT
```

**Description**

Enumerates the image pixel formats.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| PIXEL_FORMAT_UNKNOWN = 0 | Unknown format.|
| PIXEL_FORMAT_RGB_565 = 2 | RGB_565 format.|
| PIXEL_FORMAT_RGBA_8888 = 3 | RGBA_8888 format.|
| PIXEL_FORMAT_BGRA_8888 = 4 | BGRA_8888 format.|
| PIXEL_FORMAT_RGB_888 = 5 | RGB_888 format.|
| PIXEL_FORMAT_ALPHA_8 = 6 | ALPHA_8 format.|
| PIXEL_FORMAT_RGBA_F16 = 7 | RGBA_F16 format.|
| PIXEL_FORMAT_NV21 = 8 | NV21 format.|
| PIXEL_FORMAT_NV12 = 9 | NV12 format.|
| PIXEL_FORMAT_RGBA_1010102 = 10 | RGBA_1010102 format.|
| PIXEL_FORMAT_YCBCR_P010 = 11 | YCBCR_P010 format.|
| PIXEL_FORMAT_YCRCB_P010 =12 | YCRCB_P010 format.|

### OH_PixelmapNative_AntiAliasingLevel

```
enum OH_PixelmapNative_AntiAliasingLevel
```

**Description**

Enumerates the anti-aliasing levels used for scaling PixelMaps.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| OH_PixelmapNative_AntiAliasing_NONE = 0 | Nearest neighbor interpolation.|
| OH_PixelmapNative_AntiAliasing_LOW = 1 | Bilinear interpolation.|
| OH_PixelmapNative_AntiAliasing_MEDIUM = 2 | Bilinear interpolation with mipmap enabled. You are advised to use this value when zooming out an image.|
| OH_PixelmapNative_AntiAliasing_HIGH = 3 | Cubic interpolation.|

### OH_Pixelmap_HdrMetadataKey

```
enum OH_Pixelmap_HdrMetadataKey
```

**Description**

Enumerates the keys of the HDR related metadata information used by the PixelMap. It is used in [OH_PixelmapNative_SetMetadata](#oh_pixelmapnative_setmetadata) and [OH_PixelmapNative_GetMetadata](#oh_pixelmapnative_getmetadata).

**Since**: 12

| Enum Item| Description|
| -- | -- |
| HDR_METADATA_TYPE = 0 | Metadata type used by the PixelMap.|
| HDR_STATIC_METADATA = 1 | Static metadata.|
| HDR_DYNAMIC_METADATA = 2 | Dynamic metadata.|
| HDR_GAINMAP_METADATA = 3 | Metadata used by gain maps.|

### OH_Pixelmap_HdrMetadataType

```
enum OH_Pixelmap_HdrMetadataType
```

**Description**

Enumerates the HDR metadata types, which are the values of **HDR_METADATA_TYPE**.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| HDR_METADATA_TYPE_NONE = 0 | No metadata.|
| HDR_METADATA_TYPE_BASE = 1 | Metadata used for base graphics.|
| HDR_METADATA_TYPE_GAINMAP = 2 | Metadata used for gain maps.|
| HDR_METADATA_TYPE_ALTERNATE = 3 | Metadata used for synthesized HDR graphics.|


## Function Description

### OH_PixelmapInitializationOptions_Create()

```
Image_ErrorCode OH_PixelmapInitializationOptions_Create(OH_Pixelmap_InitializationOptions **options)
```

**Description**

Creates the pointer to an OH_Pixelmap_InitializationOptions struct.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) **options | Double pointer to the OH_Pixelmap_InitializationOptions struct created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapInitializationOptions_GetWidth()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetWidth(OH_Pixelmap_InitializationOptions *options,uint32_t *width)
```

**Description**

Obtains the image width.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| uint32_t *width | Pointer to the image width, in px.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapInitializationOptions_SetWidth()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetWidth(OH_Pixelmap_InitializationOptions *options,uint32_t width)
```

**Description**

Sets the image width.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| uint32_t width | Image width, in px.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapInitializationOptions_GetHeight()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetHeight(OH_Pixelmap_InitializationOptions *options,uint32_t *height)
```

**Description**

Obtains the image height.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| uint32_t *height | Pointer to the image height, in px.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapInitializationOptions_SetHeight()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetHeight(OH_Pixelmap_InitializationOptions *options,uint32_t height)
```

**Description**

Sets the image height.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| uint32_t height | Image height, in px.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapInitializationOptions_GetPixelFormat()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetPixelFormat(OH_Pixelmap_InitializationOptions *options,int32_t *pixelFormat)
```

**Description**

Obtains the pixel format.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| int32_t *pixelFormat | Pointer to the pixel format. For details about the available options, see [PIXEL_FORMAT](#pixel_format).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapInitializationOptions_SetPixelFormat()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetPixelFormat(OH_Pixelmap_InitializationOptions *options,int32_t pixelFormat)
```

**Description**

Sets the pixel format.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| int32_t pixelFormat | Pixel format. For details about the available options, see [PIXEL_FORMAT](#pixel_format).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapInitializationOptions_GetSrcPixelFormat()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetSrcPixelFormat(OH_Pixelmap_InitializationOptions *options,int32_t *srcpixelFormat)
```

**Description**

Obtains the source pixel format.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| int32_t *srcpixelFormat | Pointer to the pixel format. For details about the available options, see [PIXEL_FORMAT](#pixel_format).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapInitializationOptions_SetSrcPixelFormat()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetSrcPixelFormat(OH_Pixelmap_InitializationOptions *options,int32_t srcpixelFormat)
```

**Description**

Sets the source pixel format.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| int32_t srcpixelFormat | Source pixel format. For details about the available options, see [PIXEL_FORMAT](#pixel_format).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapInitializationOptions_GetRowStride()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetRowStride(OH_Pixelmap_InitializationOptions *options,int32_t *rowStride)
```

**Description**

Obtains the row stride.<br> The stride is the actual memory size occupied by each row of the image, in bytes. Stride = Width \*Number of bytes per pixel + Padding, where padding refers to the extra space added at the end of each row for memory alignment purposes.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| int32_t *rowStride | Pointer to the stride, in bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNKNOWN_ERROR**: The struct that **options** points to is released.|

### OH_PixelmapInitializationOptions_SetRowStride()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetRowStride(OH_Pixelmap_InitializationOptions *options,int32_t rowStride)
```

**Description**

Sets the row stride.<br>The stride is the actual memory size occupied by each row of the image, in bytes. Stride = Width \*Number of bytes per pixel + Padding, where padding refers to the extra space added at the end of each row for memory alignment purposes.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| int32_t rowStride | Stride, in bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNKNOWN_ERROR**: The struct that **options** points to is released.|

### OH_PixelmapInitializationOptions_GetAlphaType()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetAlphaType(OH_Pixelmap_InitializationOptions *options,int32_t *alphaType)
```

**Description**

Obtains the alpha type.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| int32_t *alphaType | Pointer to the alpha type. For details about the available options, see [PIXELMAP_ALPHA_TYPE](#pixelmap_alpha_type).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapInitializationOptions_SetAlphaType()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetAlphaType(OH_Pixelmap_InitializationOptions *options,int32_t alphaType)
```

**Description**

Sets the alpha type.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| int32_t alphaType | Alpha type. For details about the available options, see [PIXELMAP_ALPHA_TYPE](#pixelmap_alpha_type).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapInitializationOptions_GetEditable()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetEditable(OH_Pixelmap_InitializationOptions *options,bool *editable)
```

**Description**

Obtains the editable flag.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| bool *editable | Pointer to the editable flag.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapInitializationOptions_SetEditable()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetEditable(OH_Pixelmap_InitializationOptions *options,bool editable)
```

**Description**

Sets the editable flag.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| bool editable | Editable flag.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapInitializationOptions_Release()

```
Image_ErrorCode OH_PixelmapInitializationOptions_Release(OH_Pixelmap_InitializationOptions *options)
```

**Description**

Releases the pointer to an OH_Pixelmap_InitializationOptions struct.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapImageInfo_Create()

```
Image_ErrorCode OH_PixelmapImageInfo_Create(OH_Pixelmap_ImageInfo **info)
```

**Description**

Creates the pointer to an OH_Pixelmap_ImageInfo struct.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) **info | Double pointer to the OH_Pixelmap_ImageInfo struct created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapImageInfo_GetWidth()

```
Image_ErrorCode OH_PixelmapImageInfo_GetWidth(OH_Pixelmap_ImageInfo *info, uint32_t *width)
```

**Description**

Obtains the image width.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | Pointer to an OH_Pixelmap_ImageInfo struct.|
| uint32_t *width | Pointer to the image width, in px.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapImageInfo_GetHeight()

```
Image_ErrorCode OH_PixelmapImageInfo_GetHeight(OH_Pixelmap_ImageInfo *info, uint32_t *height)
```

**Description**

Obtains the image height.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | Pointer to an OH_Pixelmap_ImageInfo struct.|
| uint32_t *height | Pointer to the image height, in px.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapImageInfo_GetAlphaMode()

```
Image_ErrorCode OH_PixelmapImageInfo_GetAlphaMode(OH_Pixelmap_ImageInfo *info, int32_t *AlphaMode)
```

**Description**

Obtains the alpha format of an image.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | Pointer to an OH_Pixelmap_ImageInfo struct.|
| int32_t *AlphaMode | Pointer to the alpha format.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapImageInfo_GetRowStride()

```
Image_ErrorCode OH_PixelmapImageInfo_GetRowStride(OH_Pixelmap_ImageInfo *info, uint32_t *rowStride)
```

**Description**

Obtains the row stride.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | Pointer to an OH_Pixelmap_ImageInfo struct.|
| uint32_t *rowStride | Pointer to the row stride, which is the number of bytes from one row of pixels in memory to the next row of pixels in memory.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapImageInfo_GetPixelFormat()

```
Image_ErrorCode OH_PixelmapImageInfo_GetPixelFormat(OH_Pixelmap_ImageInfo *info, int32_t *pixelFormat)
```

**Description**

Obtains the pixel format.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | Pointer to an OH_Pixelmap_ImageInfo struct.|
| int32_t *pixelFormat | Pointer to the pixel format.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapImageInfo_GetAlphaType()

```
Image_ErrorCode OH_PixelmapImageInfo_GetAlphaType(OH_Pixelmap_ImageInfo *info, int32_t *alphaType)
```

**Description**

Obtains the alpha type.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | Pointer to an OH_Pixelmap_ImageInfo struct.|
| int32_t *alphaType | Pointer to the alpha type. For details about the available options, see [PIXELMAP_ALPHA_TYPE](#pixelmap_alpha_type).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapImageInfo_GetDynamicRange()

```
Image_ErrorCode OH_PixelmapImageInfo_GetDynamicRange(OH_Pixelmap_ImageInfo *info, bool *isHdr)
```

**Description**

Obtains the dynamic range of a PixelMap.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | Pointer to an OH_Pixelmap_ImageInfo struct.|
| bool *isHdr | Pointer to a Boolean that specifies whether the HDR is used.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapImageInfo_Release()

```
Image_ErrorCode OH_PixelmapImageInfo_Release(OH_Pixelmap_ImageInfo *info)
```

**Description**

Releases the pointer to an OH_Pixelmap_ImageInfo struct.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | Pointer to an OH_Pixelmap_ImageInfo struct.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_CreatePixelmap()

```
Image_ErrorCode OH_PixelmapNative_CreatePixelmap(uint8_t *data, size_t dataLength,OH_Pixelmap_InitializationOptions *options, OH_PixelmapNative **pixelmap)
```

**Description**

Creates a PixelMap based on properties. By default, the BGRA_8888 format is used for data processing. For details about other formats, see [OH_PixelmapInitializationOptions_SetSrcPixelFormat](#oh_pixelmapinitializationoptions_setsrcpixelformat).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| uint8_t *data | Pointer to the color array in BGRA_8888 format.|
| size_t dataLength | Size of the array.|
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to the properties.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | Double pointer to the OH_PixelmapNative object created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The operation is not supported.|

### OH_PixelmapNative_CreatePixelmapUsingAllocator()

```
Image_ErrorCode OH_PixelmapNative_CreatePixelmapUsingAllocator(uint8_t *data, size_t dataLength,OH_Pixelmap_InitializationOptions *options, IMAGE_ALLOCATOR_MODE allocator, OH_PixelmapNative **pixelmap)
```

**Description**

Creates a PixelMap object based on the options and memory type, where **allocator** specifies the memory type of the PixelMap. By default, the system selects an appropriate memory type based on the image type, image size, and platform capability. When processing the returned PixelMap object, consider the impact of stride.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| uint8_t *data | Pointer to the color array in BGRA_8888 format.|
| size_t dataLength | Size of the array.|
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to the options used for creating the PixelMap.|
| [IMAGE_ALLOCATOR_MODE](capi-image-common-h.md#image_allocator_mode) allocator | Type of memory allocation for the PixelMap.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | Double pointer to the OH_PixelmapNative object created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The operation is not supported.<br>         **IMAGE_TOO_LARGE**: The image is too large to allocate memory.<br>         **IMAGE_DMA_OPERATION_FAILED**: The DMA memory operation fails.<br>         **IMAGE_ALLOCATOR_MODE_UNSUPPORTED**: The current memory allocation type is not supported, for example, creating an HDR image using shared memory.|

### OH_PixelmapNative_ConvertPixelmapNativeToNapi()

```
Image_ErrorCode OH_PixelmapNative_ConvertPixelmapNativeToNapi(napi_env env, OH_PixelmapNative *pixelmapNative,napi_value *pixelmapNapi)
```

**Description**

Converts a nativePixelMap object to a PixelMapnapi object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the NAPI environment.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmapNative | Pointer to an OH_PixelmapNative object.|
| napi_value *pixelmapNapi | Double pointer to the PixelMapnapi object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: The **pixelmapNative** parameter is a null pointer.|

### OH_PixelmapNative_ConvertPixelmapNativeFromNapi()

```
Image_ErrorCode OH_PixelmapNative_ConvertPixelmapNativeFromNapi(napi_env env, napi_value pixelmapNapi,OH_PixelmapNative **pixelmapNative)
```

**Description**

Converts a PixelMapnapi object to a nativePixelMap object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Pointer to the NAPI environment.|
| napi_value pixelmapNapi | PixelMapnapi object.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmapNative | Double pointer to the OH_PixelmapNative object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: **pixelmapNative** is a null pointer or is not an OH_PixelmapNative object.|

### OH_PixelmapNative_ReadPixels()

```
Image_ErrorCode OH_PixelmapNative_ReadPixels(OH_PixelmapNative *pixelmap, uint8_t *destination, size_t *bufferSize)
```

**Description**

Reads the pixels of a PixelMap and writes the result to the buffer based on the pixel format of the PixelMap.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| uint8_t *destination | Pointer to the buffer to which the pixels will be written.|
| size_t *bufferSize | Pointer to the buffer size. The buffer size of the RGBA format is equal to width \* height \* 4, and the buffer size of the NV21 and NV12 formats is equal to width \* height+((width+1)/2) \* ((height+1)/2) \* 2.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNKNOWN_ERROR**: An unknown error occurs.|

### OH_PixelmapNative_WritePixels()

```
Image_ErrorCode OH_PixelmapNative_WritePixels(OH_PixelmapNative *pixelmap, uint8_t *source, size_t bufferSize)
```

**Description**

Reads the pixels in the buffer and writes the result to the PixelMap based on the pixel format of the PixelMap.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| uint8_t *source | Pointer to the buffer from which the pixels will be read.|
| size_t bufferSize | Buffer size.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The operation is not supported.<br>         **IMAGE_UNKNOWN_ERROR**: An unknown error occurs.|

### OH_PixelmapNative_GetArgbPixels()

```
Image_ErrorCode OH_PixelmapNative_GetArgbPixels(OH_PixelmapNative *pixelmap, uint8_t *destination, size_t *bufferSize)
```

**Description**

Reads data in ARGB format from a PixelMap.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| uint8_t *destination | Pointer to the buffer to which the pixels will be written.|
| size_t *bufferSize | Pointer to the buffer size.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         IMAGE_UNSUPPORTED_CONVERSION: The PixelMap format does not support reading ARGB data.<br>         **IMAGE_ALLOC_FAILED**: Memory allocation fails.<br>         **IMAGE_COPY_FAILED**: Memory data copy, read, or operation fails.|

### OH_PixelmapNative_ToSdr()

```
Image_ErrorCode OH_PixelmapNative_ToSdr(OH_PixelmapNative *pixelmap)
```

**Description**

Converts a PixelMap from the HDR format to the SDR format.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The operation is not supported.|

### OH_PixelmapNative_GetImageInfo()

```
Image_ErrorCode OH_PixelmapNative_GetImageInfo(OH_PixelmapNative *pixelmap, OH_Pixelmap_ImageInfo *imageInfo)
```

**Description**

Obtains the image information of a PixelMap.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *imageInfo | Pointer to the image information.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_Opacity()

```
Image_ErrorCode OH_PixelmapNative_Opacity(OH_PixelmapNative *pixelmap, float rate)
```

**Description**

Sets the opacity rate to enable the PixelMap to achieve the corresponding opacity effect.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| float rate | Opacity rate.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_Scale()

```
Image_ErrorCode OH_PixelmapNative_Scale(OH_PixelmapNative *pixelmap, float scaleX, float scaleY)
```

**Description**

Scales a PixelMap based on a given width and height.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| float scaleX | Scale ratio of the width.|
| float scaleY | Scale ratio of the height.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_ScaleWithAntiAliasing()

```
Image_ErrorCode OH_PixelmapNative_ScaleWithAntiAliasing(OH_PixelmapNative *pixelmap, float scaleX, float scaleY,OH_PixelmapNative_AntiAliasingLevel level)
```

**Description**

Scales a PixelMap based on the specified anti-aliasing level, width, and height.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| float scaleX | Scale ratio of the width.|
| float scaleY | Scale ratio of the height.|
| [OH_PixelmapNative_AntiAliasingLevel](#oh_pixelmapnative_antialiasinglevel) level | Anti-aliasing level.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_TOO_LARGE**: The image is too large.<br>         **IMAGE_ALLOC_FAILED**: Memory allocation fails.<br>         **IMAGE_UNKNOWN_ERROR**: The struct that **pixelmap** points to is released.|

### OH_PixelmapNative_CreateScaledPixelMap()

```
Image_ErrorCode OH_PixelmapNative_CreateScaledPixelMap(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap,float scaleX, float scaleY)
```

**Description**

Creates a PixelMap that has been resized based on the specified scale factors of the width and height.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *srcPixelmap | Pointer to the source PixelMap, which is an OH_PixelmapNative object.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **dstPixelmap | Double pointer to the destination PixelMap, which is an OH_PixelmapNative object.|
| float scaleX | Scale ratio of the width.|
| float scaleY | Scale ratio of the height.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_CreateScaledPixelMapWithAntiAliasing()

```
Image_ErrorCode OH_PixelmapNative_CreateScaledPixelMapWithAntiAliasing(OH_PixelmapNative *srcPixelmap,OH_PixelmapNative **dstPixelmap, float scaleX, float scaleY, OH_PixelmapNative_AntiAliasingLevel level)
```

**Description**

Creates a PixelMap that has been resized based on the specified anti-aliasing level and the scale factors of the width and height.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *srcPixelmap | Pointer to the source PixelMap, which is an OH_PixelmapNative object.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **dstPixelmap | Double pointer to the destination PixelMap, which is an OH_PixelmapNative object.|
| float scaleX | Scale ratio of the width.|
| float scaleY | Scale ratio of the height.|
| [OH_PixelmapNative_AntiAliasingLevel](#oh_pixelmapnative_antialiasinglevel) level | Anti-aliasing level.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_TOO_LARGE**: The image is too large.<br>         **IMAGE_ALLOC_FAILED**: Memory allocation fails.|

### OH_PixelmapNative_Translate()

```
Image_ErrorCode OH_PixelmapNative_Translate(OH_PixelmapNative *pixelmap, float x, float y)
```

**Description**

Translates a PixelMap based on given coordinates.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| float x | X coordinate to translate.|
| float y | Y coordinate to translate.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_Rotate()

```
Image_ErrorCode OH_PixelmapNative_Rotate(OH_PixelmapNative *pixelmap, float angle)
```

**Description**

Rotates a PixelMap based on a given angle.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| float angle | Image rotation angle, in degrees.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_Flip()

```
Image_ErrorCode OH_PixelmapNative_Flip(OH_PixelmapNative *pixelmap, bool shouldFilpHorizontally, bool shouldFilpVertically)
```

**Description**

Flips a PixelMap based on a given angle.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| bool shouldFilpHorizontally | Whether to flip the image horizontally.|
| bool shouldFilpVertically | Whether to flip the image vertically.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_Crop()

```
Image_ErrorCode OH_PixelmapNative_Crop(OH_PixelmapNative *pixelmap, Image_Region *region)
```

**Description**

Crops a PixelMap based on a given size.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| [Image_Region](capi-image-nativemodule-image-region.md) *region | Pointer to the region of the image after cropping.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_Release()

```
Image_ErrorCode OH_PixelmapNative_Release(OH_PixelmapNative *pixelmap)
```

**Description**

Releases the pointer to an OH_PixelmapNative object. [OH_PixelmapNative_Destroy](#oh_pixelmapnative_destroy) is recommended.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_Destroy()

```
Image_ErrorCode OH_PixelmapNative_Destroy(OH_PixelmapNative **pixelmap)
```

**Description**

Releases the pointer to an OH_PixelmapNative object.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | Pointer to an OH_PixelmapNative object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_ConvertAlphaFormat()

```
Image_ErrorCode OH_PixelmapNative_ConvertAlphaFormat(OH_PixelmapNative* srcpixelmap,OH_PixelmapNative* dstpixelmap, const bool isPremul)
```

**Description**

Converts pixel data of a PixelMap from premultiplied alpha to non-premultiplied alpha, or vice versa.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md)* srcpixelmap | Pointer to the source PixelMap, which is an OH_PixelmapNative object.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md)* dstpixelmap | Pointer to the destination PixelMap, which is an OH_PixelmapNative object.|
| const bool isPremul | Conversion mode. The value **true** means a conversion from premultiplied alpha to non-premultiplied alpha, and **false** means a conversion from non-premultiplied alpha to premultiplied alpha.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_CreateEmptyPixelmap()

```
Image_ErrorCode OH_PixelmapNative_CreateEmptyPixelmap(OH_Pixelmap_InitializationOptions *options,OH_PixelmapNative **pixelmap)
```

**Description**

Creates an empty PixelMap object based on **OH_Pixelmap_InitializationOptions**. The memory data is 0.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to the properties.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | Double pointer to the OH_PixelmapNative object created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_CreateEmptyPixelmapUsingAllocator()

```
Image_ErrorCode OH_PixelmapNative_CreateEmptyPixelmapUsingAllocator(OH_Pixelmap_InitializationOptions *options, IMAGE_ALLOCATOR_MODE allocator, OH_PixelmapNative **pixelmap)
```

**Description**

Creates an empty PixelMap object based on the options and memory type, where **allocator** specifies the memory type of the PixelMap. By default, the system selects an appropriate memory type based on the image type, image size, and platform capability. When processing the returned PixelMap object, consider the impact of stride.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to the options used for creating the PixelMap.|
| [IMAGE_ALLOCATOR_MODE](capi-image-common-h.md#image_allocator_mode) allocator | Type of memory allocation for the PixelMap.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | Double pointer to the OH_PixelmapNative object created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The operation is not supported.<br>         **IMAGE_TOO_LARGE**: The image is too large to allocate memory.<br>         **IMAGE_DMA_OPERATION_FAILED**: The DMA memory operation fails.<br>         **IMAGE_ALLOCATOR_MODE_UNSUPPORTED**: The current memory allocation type is not supported, for example, creating an HDR image using shared memory.|

### OH_PixelmapNative_GetNativeBuffer()

```
Image_ErrorCode OH_PixelmapNative_GetNativeBuffer(OH_PixelmapNative *pixelmap, OH_NativeBuffer **nativeBuffer)
```

**Description**

Obtains the NativeBuffer object from a PixelMap in the DMA memory.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to the PixelMap.|
| [OH_NativeBuffer](capi-image-nativemodule-image-nativemodule-oh-nativebuffer.md) **nativeBuffer | Double pointer to the NativeBuffer object obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_DMA_NOT_EXIST**: DMA memory does not exist.<br>         **IMAGE_DMA_OPERATION_FAILED**: The DMA memory operation fails.|

### OH_PixelmapNative_GetMetadata()

```
Image_ErrorCode OH_PixelmapNative_GetMetadata(OH_PixelmapNative *pixelmap, OH_Pixelmap_HdrMetadataKey key,OH_Pixelmap_HdrMetadataValue **value)
```

**Description**

Obtains the metadata.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| [OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey) key | HDR metadata key.|
| [OH_Pixelmap_HdrMetadataValue](capi-image-nativemodule-oh-pixelmap-hdrmetadatavalue.md) **value | Double pointer to the value of the metadata key.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_DMA_NOT_EXIST**: DMA memory does not exist.<br>         **IMAGE_COPY_FAILED**: Memory copy fails.|

### OH_PixelmapNative_SetMetadata()

```
Image_ErrorCode OH_PixelmapNative_SetMetadata(OH_PixelmapNative *pixelmap, OH_Pixelmap_HdrMetadataKey key,OH_Pixelmap_HdrMetadataValue *value)
```

**Description**

Sets the metadata.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| [OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey) key | HDR metadata key.|
| [OH_Pixelmap_HdrMetadataValue](capi-image-nativemodule-oh-pixelmap-hdrmetadatavalue.md) *value | Pointer to the value of the metadata key.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_DMA_NOT_EXIST**: DMA memory does not exist.<br>         **IMAGE_COPY_FAILED**: Memory copy fails.|

### OH_PixelmapNative_SetColorSpaceNative()

```
Image_ErrorCode OH_PixelmapNative_SetColorSpaceNative(OH_PixelmapNative *pixelmap,OH_NativeColorSpaceManager *colorSpaceNative)
```

**Description**

Sets a NativeColorSpaceManager object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to the target PixelMap of the NativeColorSpaceManager object.|
| [OH_NativeColorSpaceManager](capi-image-nativemodule-oh-nativecolorspacemanager.md) *colorSpaceNative | Pointer to a NativeColorSpaceManager object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_GetColorSpaceNative()

```
Image_ErrorCode OH_PixelmapNative_GetColorSpaceNative(OH_PixelmapNative *pixelmap,OH_NativeColorSpaceManager **colorSpaceNative)
```

**Description**

Obtains a NativeColorSpaceManager object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to the source PixelMap of the NativeColorSpaceManager.|
| [OH_NativeColorSpaceManager](capi-image-nativemodule-oh-nativecolorspacemanager.md) **colorSpaceNative | Double pointer to the NativeColorSpaceManager object obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_SetMemoryName()

```
Image_ErrorCode OH_PixelmapNative_SetMemoryName(OH_PixelmapNative *pixelmap, char *name, size_t *size)
```

**Description**

Sets the memory name of a PixelMap.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| char *name | Pointer to the memory name.|
| size_t *size | Pointer to the memory size (in bytes).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: The name length exceeds the value range. The name length for DMA memory settings should be within the range of 1 to 255 bytes. For ASHMEM memory settings, the name length should be within the range of 1 to 244 bytes.<br>         **IMAGE_UNSUPPORTED_MEMORY_FORMAT**: The memory is neither DMA memory nor ASHMEM memory.|

### OH_PixelmapNative_GetByteCount()

```
Image_ErrorCode OH_PixelmapNative_GetByteCount(OH_PixelmapNative *pixelmap, uint32_t *byteCount)
```

**Description**

Obtains the total number of bytes occupied by all pixels in a PixelMap, excluding any memory padding.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to a PixelMap.|
| uint32_t *byteCount | Pointer to the number of bytes obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **Image_BAD_PARAMETER**: The **pixelmap** or **byteCount** parameter is invalid.|

### OH_PixelmapNative_GetAllocationByteCount()

```
Image_ErrorCode OH_PixelmapNative_GetAllocationByteCount(OH_PixelmapNative *pixelmap, uint32_t *allocationByteCount)
```

**Description**

Obtains the number of bytes in the memory allocated by a PixelMap to store pixels.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to a PixelMap.|
| uint32_t *allocationByteCount | Pointer to the number of bytes obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **Image_BAD_PARAMETER**: The **pixelmap** or **allocationByteCount** parameter is invalid.|

### OH_PixelmapNative_AccessPixels()

```
Image_ErrorCode OH_PixelmapNative_AccessPixels(OH_PixelmapNative *pixelmap, void **addr)
```

**Description**

Obtains the memory address where the pixels of a PixelMap are stored and locks the memory.<br>When the memory is locked, any attempts to alter or free the pixel data of the PixelMap will fail or be ineffective.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to a PixelMap.|
| void **addr | Double pointer to the memory address.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **Image_BAD_PARAMETER**: The **pixelmap** or **addr** parameter is invalid.<br>         **Image_LOCK_UNLOCK_FAILED**: Memory locking fails.|

### OH_PixelmapNative_UnaccessPixels()

```
Image_ErrorCode OH_PixelmapNative_UnaccessPixels(OH_PixelmapNative *pixelmap)
```

**Description**

Unlocks the memory allocated to store the pixels of a PixelMap.<br>This function must be used together with [OH_PixelmapNative_AccessPixels](#oh_pixelmapnative_accesspixels).

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to a PixelMap.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **Image_BAD_PARAMETER**: The **pixelmap** parameter is invalid.<br>         **IMAGE_LOCK_UNLOCK_FAILED**: Memory unlocking fails.|
