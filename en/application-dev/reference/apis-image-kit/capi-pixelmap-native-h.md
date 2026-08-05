# pixelmap_native.h
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yaozhupeng-->
<!--Designer: @yaozhupeng-->
<!--Tester: @zhaoxiaoguang2-->
<!--Adviser: @w_Machine_cc-->

## Overview

The file declares the APIs for accessing a PixelMap. The APIs provide capabilities for accessing PixelMaps, supporting the creation of PixelMaps through pixel data, surface, NativeBuffer, and other methods, as well as cloning PixelMaps, reading and writing PixelMaps, and performing image transformations such as scaling, rotation, flipping, translation, and cropping. They also support HDR metadata management, color space configuration, alpha type conversion, interoperability between Native and Napi objects, and direct memory access. These APIs are suitable for scenarios where pixel-level processing and transformation of decoded image bitmaps are required in the native layer.

**File to include**: <multimedia/image_framework/image/pixelmap_native.h>

**Library**: libpixelmap.so

**System capability**: SystemCapability.Multimedia.Image.Core

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_Pixelmap_HdrStaticMetadata](capi-image-nativemodule-oh-pixelmap-hdrstaticmetadata.md) | OH_Pixelmap_HdrStaticMetadata | Describes the metadata value type corresponding to the HDR_STATIC_METADATA key in [OH_Pixelmap_HdrMetadataKey](capi-pixelmap-native-h.md#oh_pixelmap_hdrmetadatakey), used to store HDR static metadata.|
| [OH_Pixelmap_HdrDynamicMetadata](capi-image-nativemodule-oh-pixelmap-hdrdynamicmetadata.md) | OH_Pixelmap_HdrDynamicMetadata | Describes the metadata value type corresponding to the HDR_DYNAMIC_METADATA key in [OH_Pixelmap_HdrMetadataKey](capi-pixelmap-native-h.md#oh_pixelmap_hdrmetadatakey), used to store HDR dynamic metadata. The format conforms to relevant HDR dynamic metadata standards.|
| [OH_Pixelmap_HdrGainmapMetadata](capi-image-nativemodule-oh-pixelmap-hdrgainmapmetadata.md) | OH_Pixelmap_HdrGainmapMetadata | Describes the metadata value type corresponding to the HDR_GAINMAP_METADATA key in [OH_Pixelmap_HdrMetadataKey](capi-pixelmap-native-h.md#oh_pixelmap_hdrmetadatakey), used to store HDR gain map metadata as defined in ISO 21496-1.|
| [OH_Pixelmap_HdrMetadataValue](capi-image-nativemodule-oh-pixelmap-hdrmetadatavalue.md) | OH_Pixelmap_HdrMetadataValue | Describes the HDR metadata value used by the PixelMap, corresponding to a [OH_Pixelmap_HdrMetadataKey](capi-pixelmap-native-h.md#oh_pixelmap_hdrmetadatakey). When the corresponding [OH_Pixelmap_HdrMetadataKey](capi-pixelmap-native-h.md#oh_pixelmap_hdrmetadatakey) is passed as an input parameter, this struct can be used to set or retrieve the metadata value of the corresponding type via [OH_PixelmapNative_SetMetadata](capi-pixelmap-native-h.md#oh_pixelmapnative_setmetadata) or [OH_PixelmapNative_GetMetadata](capi-pixelmap-native-h.md#oh_pixelmapnative_getmetadata).|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) | - | Uncompressed pixel map format struct encapsulated at the native layer after image decoding.<br> To create an OH_PixelmapNative object, call [OH_PixelmapNative_CreatePixelmap](#oh_pixelmapnative_createpixelmap). The default pixel format is BGRA_8888.<br> To release an OH_PixelmapNative object, call [OH_PixelmapNative_Release](#oh_pixelmapnative_release).|
| [OH_NativeBuffer](capi-image-nativemodule-image-nativemodule-oh-nativebuffer.md) | - | Describes the native buffer, which is used to perform operations related to the native buffer.|
| [OH_NativeColorSpaceManager](capi-image-nativemodule-oh-nativecolorspacemanager.md) | OH_NativeColorSpaceManager | Describes the native color space manager, which is used to perform operations related to the native color space manager.|
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) | - | Initialization parameter struct encapsulated at the native layer, used to set PixelMap initialization parameters.<br> To create an OH_Pixelmap_InitializationOptions object, call [OH_PixelmapInitializationOptions_Create](#oh_pixelmapinitializationoptions_create).<br> To release an OH_Pixelmap_InitializationOptions object, call [OH_PixelmapInitializationOptions_Release](#oh_pixelmapinitializationoptions_release).|
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) | - | Describes the image information.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [PIXELMAP_ALPHA_TYPE](#pixelmap_alpha_type) | PIXELMAP_ALPHA_TYPE | Enumerates the alpha types of a PixelMap.|
| [PIXEL_FORMAT](#pixel_format) | PIXEL_FORMAT | Enumerates the image pixel formats.|
| [OH_PixelmapNative_AntiAliasingLevel](#oh_pixelmapnative_antialiasinglevel) | OH_PixelmapNative_AntiAliasingLevel | Enumerates the anti-aliasing levels used for scaling PixelMaps.|
| [OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey) | OH_Pixelmap_HdrMetadataKey | Enumerates the keys of the HDR metadata information used by the PixelMap. It is used in [OH_PixelmapNative_SetMetadata](capi-pixelmap-native-h.md#oh_pixelmapnative_setmetadata) and [OH_PixelmapNative_GetMetadata](capi-pixelmap-native-h.md#oh_pixelmapnative_getmetadata).|
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
| [Image_ErrorCode OH_PixelmapInitializationOptions_GetSrcPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t *srcpixelFormat)](#oh_pixelmapinitializationoptions_getsrcpixelformat) | Obtains the source pixel format (the pixel format of the input data used when creating an PixelMap).|
| [Image_ErrorCode OH_PixelmapInitializationOptions_SetSrcPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t srcpixelFormat)](#oh_pixelmapinitializationoptions_setsrcpixelformat) | Sets the source pixel format (the pixel format of the input data used when creating an PixelMap).|
| [Image_ErrorCode OH_PixelmapInitializationOptions_GetRowStride(OH_Pixelmap_InitializationOptions *options, int32_t *rowStride)](#oh_pixelmapinitializationoptions_getrowstride) | Obtains the row stride.<br> The stride is the actual memory size occupied by each row of pixels in the image. The unit is bytes. The stride is calculated as: stride = image width × bytes per pixel + padding, where the padding is the blank area added at the end of each row for memory alignment.|
| [Image_ErrorCode OH_PixelmapInitializationOptions_SetRowStride(OH_Pixelmap_InitializationOptions *options, int32_t rowStride)](#oh_pixelmapinitializationoptions_setrowstride) | Sets the row stride.<br> The stride is the actual memory size occupied by each row of pixels in the image. The unit is bytes. The stride is calculated as: stride = image width × bytes per pixel + padding, where the padding is the blank area added at the end of each row for memory alignment.|
| [Image_ErrorCode OH_PixelmapInitializationOptions_GetAlphaType(OH_Pixelmap_InitializationOptions *options, int32_t *alphaType)](#oh_pixelmapinitializationoptions_getalphatype) | Obtains the alpha type.|
| [Image_ErrorCode OH_PixelmapInitializationOptions_SetAlphaType(OH_Pixelmap_InitializationOptions *options, int32_t alphaType)](#oh_pixelmapinitializationoptions_setalphatype) | Sets the alpha type.|
| [Image_ErrorCode OH_PixelmapInitializationOptions_GetEditable(OH_Pixelmap_InitializationOptions *options, bool *editable)](#oh_pixelmapinitializationoptions_geteditable) | Obtains the editable flag.|
| [Image_ErrorCode OH_PixelmapInitializationOptions_SetEditable(OH_Pixelmap_InitializationOptions *options, bool editable)](#oh_pixelmapinitializationoptions_seteditable) | Sets the editable flag.|
| [Image_ErrorCode OH_PixelmapInitializationOptions_Release(OH_Pixelmap_InitializationOptions *options)](#oh_pixelmapinitializationoptions_release) | Releases the pointer to an OH_Pixelmap_InitializationOptions struct.|
| [Image_ErrorCode OH_PixelmapImageInfo_Create(OH_Pixelmap_ImageInfo **info)](#oh_pixelmapimageinfo_create) | Creates the pointer to an OH_Pixelmap_ImageInfo struct.|
| [Image_ErrorCode OH_PixelmapImageInfo_GetWidth(OH_Pixelmap_ImageInfo *info, uint32_t *width)](#oh_pixelmapimageinfo_getwidth) | Obtains the image width.|
| [Image_ErrorCode OH_PixelmapImageInfo_GetHeight(OH_Pixelmap_ImageInfo *info, uint32_t *height)](#oh_pixelmapimageinfo_getheight) | Obtains the image height.|
| [Image_ErrorCode OH_PixelmapImageInfo_GetAlphaMode(OH_Pixelmap_ImageInfo *info, int32_t *alphaMode)](#oh_pixelmapimageinfo_getalphamode) | Obtains the alpha type of an image.|
| [Image_ErrorCode OH_PixelmapImageInfo_GetRowStride(OH_Pixelmap_ImageInfo *info, uint32_t *rowStride)](#oh_pixelmapimageinfo_getrowstride) | Obtains the row stride.|
| [Image_ErrorCode OH_PixelmapImageInfo_GetPixelFormat(OH_Pixelmap_ImageInfo *info, int32_t *pixelFormat)](#oh_pixelmapimageinfo_getpixelformat) | Obtains the pixel format.|
| [Image_ErrorCode OH_PixelmapImageInfo_GetAlphaType(OH_Pixelmap_ImageInfo *info, int32_t *alphaType)](#oh_pixelmapimageinfo_getalphatype) | Obtains the default alpha type of OH_PixelmapImageInfo. To obtain the current alpha type of the image, call [OH_PixelmapImageInfo_GetAlphaMode](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getalphamode).|
| [Image_ErrorCode OH_PixelmapImageInfo_GetDynamicRange(OH_Pixelmap_ImageInfo *info, bool *isHdr)](#oh_pixelmapimageinfo_getdynamicrange) | Obtains the dynamic range of a PixelMap.|
| [Image_ErrorCode OH_PixelmapImageInfo_Release(OH_Pixelmap_ImageInfo *info)](#oh_pixelmapimageinfo_release) | Releases the pointer to an OH_Pixelmap_ImageInfo struct.|
| [Image_ErrorCode OH_PixelmapNative_CreatePixelmap(uint8_t *data, size_t dataLength, OH_Pixelmap_InitializationOptions *options, OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_createpixelmap) | Creates a PixelMap based on the pixel data and image properties.<br>This API cannot create PixelMaps in the PIXEL_FORMAT_RGBA_1010102, PIXEL_FORMAT_YCBCR_P010, or PIXEL_FORMAT_YCRCB_P010 format.|
| [Image_ErrorCode OH_PixelmapNative_CreatePixelmapUsingAllocator(uint8_t *data, size_t dataLength, OH_Pixelmap_InitializationOptions *options, IMAGE_ALLOCATOR_MODE allocator, OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_createpixelmapusingallocator) | Creates a PixelMap based on the pixel data and image properties. You can specify the memory type via the allocator.<br>By default, the system selects an appropriate memory type based on the image type, image size, and platform capability.<br>When processing the PixelMap returned by this API, consider the impact of the row stride. The row stride is the actual memory size occupied by each row of the image. It may be larger than the image width multiplied by the bytes per pixel due to memory alignment. For details, see [OH_PixelmapInitializationOptions_GetRowStride](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_getrowstride).|
| [Image_ErrorCode OH_PixelmapNative_ConvertPixelmapNativeToNapi(napi_env env, OH_PixelmapNative *pixelmapNative, napi_value *pixelmapNapi)](#oh_pixelmapnative_convertpixelmapnativetonapi) | Converts an OH_PixelmapNative object to a PixelmapNapi object.|
| [Image_ErrorCode OH_PixelmapNative_ConvertPixelmapNativeFromNapi(napi_env env, napi_value pixelmapNapi, OH_PixelmapNative **pixelmapNative)](#oh_pixelmapnative_convertpixelmapnativefromnapi) | Converts a PixelmapNapi object to an OH_PixelmapNative object.|
| [Image_ErrorCode OH_PixelmapNative_ReadPixels(OH_PixelmapNative *pixelmap, uint8_t *destination, size_t *bufferSize)](#oh_pixelmapnative_readpixels) | Reads the pixel data of a PixelMap and writes it to the buffer based on the pixel format of the PixelMap.|
| [Image_ErrorCode OH_PixelmapNative_WritePixels(OH_PixelmapNative *pixelmap, uint8_t *source, size_t bufferSize)](#oh_pixelmapnative_writepixels) | Writes the pixel data in the buffer to a PixelMap based on the pixel format of the PixelMap.|
| [Image_ErrorCode OH_PixelmapNative_ReadPixelsFromArea(OH_PixelmapNative *pixelmap, Image_PositionArea *area)](#oh_pixelmapnative_readpixelsfromarea) | Reads pixel data from the specified area in a PixelMap and stores the data to the buffer. If the pixel format of the PixelMap is YUV, the data is written to the buffer in the original YUV format; otherwise, it is written in the BGRA_8888 format.|
| [Image_ErrorCode OH_PixelmapNative_WritePixelsToArea(OH_PixelmapNative *pixelmap, Image_PositionArea *area)](#oh_pixelmapnative_writepixelstoarea) | Writes pixel data in the buffer to the specified area in a PixelMap. If the pixel format of the PixelMap is YUV, the data source format must be the same as that of the PixelMap; otherwise, the data source must be in the BGRA_8888 format.|
| [Image_ErrorCode OH_PixelmapNative_GetArgbPixels(OH_PixelmapNative *pixelmap, uint8_t *destination, size_t *bufferSize)](#oh_pixelmapnative_getargbpixels) | Reads data in ARGB format from a PixelMap.|
| [Image_ErrorCode OH_PixelmapNative_ToSdr(OH_PixelmapNative *pixelmap)](#oh_pixelmapnative_tosdr) | Converts a PixelMap from the HDR format to the SDR format.|
| [Image_ErrorCode OH_PixelmapNative_GetImageInfo(OH_PixelmapNative *pixelmap, OH_Pixelmap_ImageInfo *imageInfo)](#oh_pixelmapnative_getimageinfo) | Obtains the image information of a PixelMap.|
| [Image_ErrorCode OH_PixelmapNative_SetOpacity(OH_PixelmapNative *pixelmap, float value)](#oh_pixelmapnative_setopacity) | Sets the opacity of a PixelMap. The specified opacity value is applied to all pixels.|
| [Image_ErrorCode OH_PixelmapNative_Opacity(OH_PixelmapNative *pixelmap, float rate)](#oh_pixelmapnative_opacity) | Sets the opacity of a PixelMap. The specified opacity value is applied to all pixels.<br>     Since API version 26.0.0, you are advised to use [OH_PixelmapNative_SetOpacity](capi-pixelmap-native-h.md#oh_pixelmapnative_setopacity) instead, which provides more comprehensive error information.|
| [Image_ErrorCode OH_PixelmapNative_ApplyScale(OH_PixelmapNative *pixelmap, float scaleX, float scaleY)](#oh_pixelmapnative_applyscale) | Scales a PixelMap horizontally or vertically by the specified width and height scaling factors.|
| [Image_ErrorCode OH_PixelmapNative_Scale(OH_PixelmapNative *pixelmap, float scaleX, float scaleY)](#oh_pixelmapnative_scale) | Scales a PixelMap based on the input scale ratio.<br>     Since API version 26.0.0, you are advised to use [OH_PixelmapNative_ApplyScale](capi-pixelmap-native-h.md#oh_pixelmapnative_applyscale) instead, which provides more comprehensive error information.|
| [Image_ErrorCode OH_PixelmapNative_ApplyScaleWithAntiAliasing(OH_PixelmapNative *pixelmap, float scaleX, float scaleY, OH_PixelmapNative_AntiAliasingLevel level)](#oh_pixelmapnative_applyscalewithantialiasing) | Scales a PixelMap horizontally or vertically by the specified scaling factors for width and height, using the specified anti-aliasing level.|
| [Image_ErrorCode OH_PixelmapNative_ScaleWithAntiAliasing(OH_PixelmapNative *pixelmap, float scaleX, float scaleY, OH_PixelmapNative_AntiAliasingLevel level)](#oh_pixelmapnative_scalewithantialiasing) | Scales an image based on the specified anti-aliasing level and scale ratio.<br>     Since API version 26.0.0, you are advised to use [OH_PixelmapNative_ApplyScaleWithAntiAliasing](capi-pixelmap-native-h.md#oh_pixelmapnative_applyscalewithantialiasing) instead, which provides more comprehensive error information.|
| [Image_ErrorCode OH_PixelmapNative_CreateScaledPixelMap(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap, float scaleX, float scaleY)](#oh_pixelmapnative_createscaledpixelmap) | Creates an image that has been resized based on the scale factors of the width and height. The generated PixelMap is not editable. This API does not copy the HDR metadata or EXIF information from the original image.|
| [Image_ErrorCode OH_PixelmapNative_CreateScaledPixelMapWithAntiAliasing(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap, float scaleX, float scaleY, OH_PixelmapNative_AntiAliasingLevel level)](#oh_pixelmapnative_createscaledpixelmapwithantialiasing) | Creates an image that has been resized based on the specified anti-aliasing level and the scale factors of the width and height. The generated PixelMap is not editable. This API does not copy the HDR metadata or EXIF information from the original image.|
| [Image_ErrorCode OH_PixelmapNative_CreateAlphaPixelmap(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap)](#oh_pixelmapnative_createalphapixelmap) | Creates a new non-editable ALPHA_8 PixelMap that contains only the Alpha channel from the source PixelMap.<br>If the format of the source PixelMap is ALPHA_F16, the newly created PixelMap will retain the ALPHA_F16 format.|
| [Image_ErrorCode OH_PixelmapNative_Clone(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap)](#oh_pixelmapnative_clone) | Copies the source PixelMap to create a new PixelMap. This API does not copy the EXIF information from the original image.|
| [Image_ErrorCode OH_PixelmapNative_CreateCroppedAndScaledPixelMap(OH_PixelmapNative *srcPixelmap, Image_Region *region, Image_Scale *scale, OH_PixelmapNative_AntiAliasingLevel level, OH_PixelmapNative **dstPixelmap)](#oh_pixelmapnative_createcroppedandscaledpixelmap) | Creates a PixelMap that is cropped and scaled based on the source PixelMap. This API does not copy the EXIF information from the original image.|
| [Image_ErrorCode OH_PixelmapNative_ApplyTranslate(OH_PixelmapNative *pixelmap, float x, float y)](#oh_pixelmapnative_applytranslate) | Translates the PixelMap horizontally or vertically by the specified horizontal and vertical distances.<br>After translation, the image size becomes: width = original width + x, height = original height + y.|
| [Image_ErrorCode OH_PixelmapNative_Translate(OH_PixelmapNative *pixelmap, float x, float y)](#oh_pixelmapnative_translate) | Translates an image by the specified translation distances.<br>After translation, the image size becomes: width = original width + x, height = original height + y.<br>     Since API version 26.0.0, you are advised to use [OH_PixelmapNative_ApplyTranslate](capi-pixelmap-native-h.md#oh_pixelmapnative_applytranslate) instead, which provides more comprehensive error information.|
| [Image_ErrorCode OH_PixelmapNative_ApplyRotate(OH_PixelmapNative *pixelmap, float angle)](#oh_pixelmapnative_applyrotate) | Rotates a PixelMap by the specified angle. YUV formats support only rotation angles that are multiples of 90°.|
| [Image_ErrorCode OH_PixelmapNative_Rotate(OH_PixelmapNative *pixelmap, float angle)](#oh_pixelmapnative_rotate) | Rotates an image by the specified angle. YUV formats support only rotation angles that are multiples of 90°.<br>     Since API version 26.0.0, you are advised to use [OH_PixelmapNative_ApplyRotate](capi-pixelmap-native-h.md#oh_pixelmapnative_applyrotate) instead, which provides more comprehensive error information.|
| [Image_ErrorCode OH_PixelmapNative_ApplyFlip(OH_PixelmapNative *pixelmap, bool shouldFlipHorizontally, bool shouldFlipVertically)](#oh_pixelmapnative_applyflip) | Flips an image based on the specified horizontal or vertical flip conditions.|
| [Image_ErrorCode OH_PixelmapNative_Flip(OH_PixelmapNative *pixelmap, bool shouldFlipHorizontally, bool shouldFlipVertically)](#oh_pixelmapnative_flip) | Flips a PixelMap based on a given angle.<br>     Since API version 26.0.0, you are advised to use [OH_PixelmapNative_ApplyFlip](capi-pixelmap-native-h.md#oh_pixelmapnative_applyflip) instead, which provides more comprehensive error information.|
| [Image_ErrorCode OH_PixelmapNative_ApplyCrop(OH_PixelmapNative *pixelmap, Image_Region *region)](#oh_pixelmapnative_applycrop) | Crops a PixelMap based on the specified region information.|
| [Image_ErrorCode OH_PixelmapNative_Crop(OH_PixelmapNative *pixelmap, Image_Region *region)](#oh_pixelmapnative_crop) | Crops a PixelMap based on the input region information.<br>     Since API version 26.0.0, you are advised to use [OH_PixelmapNative_ApplyCrop](capi-pixelmap-native-h.md#oh_pixelmapnative_applycrop) instead, which provides more comprehensive error information.|
| [Image_ErrorCode OH_PixelmapNative_Release(OH_PixelmapNative *pixelmap)](#oh_pixelmapnative_release) | Releases the pointer to an OH_PixelmapNative object. (The pointer cannot be released when the memory is locked by [OH_PixelmapNative_AccessPixels](capi-pixelmap-native-h.md#oh_pixelmapnative_accesspixels).)<br>You are advised to use [OH_PixelmapNative_Destroy](capi-pixelmap-native-h.md#oh_pixelmapnative_destroy).|
| [Image_ErrorCode OH_PixelmapNative_Destroy(OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_destroy) | Releases the pointer to an OH_PixelmapNative object, regardless of whether the memory is locked by [OH_PixelmapNative_AccessPixels](capi-pixelmap-native-h.md#oh_pixelmapnative_accesspixels).|
| [Image_ErrorCode OH_PixelmapNative_ConvertAlphaType(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative *dstPixelmap, const bool toPremul)](#oh_pixelmapnative_convertalphatype) | Converts the alpha type of the PixelMap pixel data between premultiplied mode ([PIXELMAP_ALPHA_TYPE_PREMULTIPLIED](capi-pixelmap-native-h.md#pixelmap_alpha_type)) and non-premultiplied mode ([PIXELMAP_ALPHA_TYPE_UNPREMULTIPLIED](capi-pixelmap-native-h.md#pixelmap_alpha_type)). This conversion is supported only for pixel formats that contain an alpha channel, except RGBA_F16 and ASTC_4x4.<br>     For details about the pixel formats, see [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format).|
| [Image_ErrorCode OH_PixelmapNative_ConvertAlphaFormat(OH_PixelmapNative* srcpixelmap, OH_PixelmapNative* dstpixelmap, const bool isPremul)](#oh_pixelmapnative_convertalphaformat) | Converts the alpha type of the PixelMap pixel data between premultiplied mode and non-premultiplied mode. This conversion is supported only for pixel formats that contain an alpha channel, except RGBA_F16 and ASTC_4x4.<br>     Since API version 26.0.0, you are advised to use [OH_PixelmapNative_ConvertAlphaType](capi-pixelmap-native-h.md#oh_pixelmapnative_convertalphatype) instead, which provides more comprehensive error information.|
| [Image_ErrorCode OH_PixelmapNative_CreateEmptyPixelmap(OH_Pixelmap_InitializationOptions *options, OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_createemptypixelmap) | Creates an empty PixelMap object based on **OH_Pixelmap_InitializationOptions**. The memory data is 0.|
| [Image_ErrorCode OH_PixelmapNative_CreateEmptyPixelmapUsingAllocator(OH_Pixelmap_InitializationOptions *options, IMAGE_ALLOCATOR_MODE allocator, OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_createemptypixelmapusingallocator) | Creates an empty PixelMap object based on **options**. The memory type used by the PixelMap can be specified by **allocator**. By default, the system selects an appropriate memory type based on the image type, image size, and platform capability. When processing the PixelMap returned by this API, consider the impact of the row stride. The row stride is the actual memory size occupied by each row of the image. It may be larger than the image width multiplied by the bytes per pixel due to memory alignment. For details, see [OH_PixelmapInitializationOptions_GetRowStride](#oh_pixelmapinitializationoptions_getrowstride).|
| [Image_ErrorCode OH_PixelmapNative_CreatePixelmapFromSurface(const char *surfaceId, size_t length, OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_createpixelmapfromsurface) | Creates a PixelMap based on the surface ID. If the surface carries rotation or flipping information and processing is required, use [OH_PixelmapNative_CreatePixelmapFromSurfaceWithTransformation](#oh_pixelmapnative_createpixelmapfromsurfacewithtransformation).|
| [Image_ErrorCode OH_PixelmapNative_CreatePixelmapFromSurfaceWithTransformation(const char *surfaceId, size_t length, bool transformEnabled, OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_createpixelmapfromsurfacewithtransformation) | Creates a PixelMap object for a preview stream image based on a surface ID. The surface may carry rotation or flipping information.|
| [Image_ErrorCode OH_PixelmapNative_CreatePixelmapFromNativeBuffer(OH_NativeBuffer *nativeBuffer, OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_createpixelmapfromnativebuffer) | Creates a PixelMap based on a NativeBuffer. If the NativeBuffer usage does not have CPU access permission configured (for details, see [OH_NativeBuffer_Usage](../apis-arkgraphics2d/capi-native-buffer-h.md#oh_nativebuffer_usage)), creation is not supported.<br> The supported pixel formats are RGBA_8888, NV21, NV12, YCBCR_P010, and YCRCB_P010.|
| [Image_ErrorCode OH_PixelmapNative_GetNativeBuffer(OH_PixelmapNative *pixelmap, OH_NativeBuffer **nativeBuffer)](#oh_pixelmapnative_getnativebuffer) | Obtains the NativeBuffer object from a PixelMap in the DMA memory.|
| [Image_ErrorCode OH_PixelmapNative_GetMetadata(OH_PixelmapNative *pixelmap, OH_Pixelmap_HdrMetadataKey key, OH_Pixelmap_HdrMetadataValue **value)](#oh_pixelmapnative_getmetadata) | Obtains HDR metadata of a PixelMap.|
| [Image_ErrorCode OH_PixelmapNative_SetMetadata(OH_PixelmapNative *pixelmap, OH_Pixelmap_HdrMetadataKey key, OH_Pixelmap_HdrMetadataValue *value)](#oh_pixelmapnative_setmetadata) | Sets the HDR metadata for a PixelMap.|
| [Image_ErrorCode OH_PixelmapNative_SetColorSpaceNative(OH_PixelmapNative *pixelmap, OH_NativeColorSpaceManager *colorSpaceNative)](#oh_pixelmapnative_setcolorspacenative) | Sets the NativeColorSpaceManager object for a PixelMap to manage the color space information of the PixelMap.|
| [Image_ErrorCode OH_PixelmapNative_GetColorSpaceNative(OH_PixelmapNative *pixelmap, OH_NativeColorSpaceManager **colorSpaceNative)](#oh_pixelmapnative_getcolorspacenative) | Obtains the NativeColorSpaceManager object of a PixelMap to query the color space information currently configured for the PixelMap.|
| [Image_ErrorCode OH_PixelmapNative_SetMemoryName(OH_PixelmapNative *pixelmap, char *name, size_t *size)](#oh_pixelmapnative_setmemoryname) | Sets the memory name of a PixelMap to facilitate memory identification during debugging or issue troubleshooting.|
| [Image_ErrorCode OH_PixelmapNative_GetByteCount(OH_PixelmapNative *pixelmap, uint32_t *byteCount)](#oh_pixelmapnative_getbytecount) | Obtains the total number of bytes occupied by all pixels in a PixelMap, excluding memory-alignment padding bytes.|
| [Image_ErrorCode OH_PixelmapNative_GetAllocationByteCount(OH_PixelmapNative *pixelmap, uint32_t *allocationByteCount)](#oh_pixelmapnative_getallocationbytecount) | Obtains the actual number of memory bytes allocated for storing pixel data, including memory-alignment padding bytes. Unlike [OH_PixelmapNative_GetByteCount](#oh_pixelmapnative_getbytecount) (which does not include padding), this API returns the actual memory size allocated by the system for the PixelMap.|
| [Image_ErrorCode OH_PixelmapNative_AccessPixels(OH_PixelmapNative *pixelmap, void **addr)](#oh_pixelmapnative_accesspixels) | Obtains the memory address where the pixels of a PixelMap are stored and locks the memory.<br> When the memory is locked, any attempts to alter or free the pixel data of the PixelMap will fail or be ineffective.<br> After use, you must call [OH_PixelmapNative_UnaccessPixels](capi-pixelmap-native-h.md#oh_pixelmapnative_unaccesspixels) to release the memory lock. The two APIs must be used in pairs.|
| [Image_ErrorCode OH_PixelmapNative_UnaccessPixels(OH_PixelmapNative *pixelmap)](#oh_pixelmapnative_unaccesspixels) | Unlocks the memory allocated to store the pixels of a PixelMap.<br> This function must be used together with [OH_PixelmapNative_AccessPixels](capi-pixelmap-native-h.md#oh_pixelmapnative_accesspixels).|
| [Image_ErrorCode OH_PixelmapNative_GetUniqueId(OH_PixelmapNative *pixelmap, uint32_t *uniqueId)](#oh_pixelmapnative_getuniqueid) | Obtains the unique ID of a PixelMap.|
| [Image_ErrorCode OH_PixelmapNative_IsReleased(OH_PixelmapNative *pixelmap, bool *released)](#oh_pixelmapnative_isreleased) | Checks whether a PixelMap is released. If released, any attempt to access the internal data of this object will fail.|

## Enum Description

### PIXELMAP_ALPHA_TYPE

```c
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

```c
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
| PIXEL_FORMAT_YCRCB_P010 = 12 | YCRCB_P010 format.|
| PIXEL_FORMAT_ALPHA_U8 = 15 | ALPHA_U8 format.<br>**Since:** 26.0.0|
| PIXEL_FORMAT_ALPHA_F16 = 16 | ALPHA_F16 format.<br>**Since:** 26.0.0|

### OH_PixelmapNative_AntiAliasingLevel

```c
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

```c
enum OH_Pixelmap_HdrMetadataKey
```

**Description**

Enumerates the keys of the HDR metadata information used by the PixelMap. It is used in [OH_PixelmapNative_SetMetadata](capi-pixelmap-native-h.md#oh_pixelmapnative_setmetadata) and [OH_PixelmapNative_GetMetadata](capi-pixelmap-native-h.md#oh_pixelmapnative_getmetadata).

**Since**: 12

| Enum Item| Description|
| -- | -- |
| HDR_METADATA_TYPE = 0 | Metadata type used by the PixelMap.|
| HDR_STATIC_METADATA = 1 | Static metadata.|
| HDR_DYNAMIC_METADATA = 2 | Dynamic metadata.|
| HDR_GAINMAP_METADATA = 3 | Metadata used by the gain map.|

### OH_Pixelmap_HdrMetadataType

```c
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

```c
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

```c
Image_ErrorCode OH_PixelmapInitializationOptions_GetWidth(OH_Pixelmap_InitializationOptions *options, uint32_t *width)
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

```c
Image_ErrorCode OH_PixelmapInitializationOptions_SetWidth(OH_Pixelmap_InitializationOptions *options, uint32_t width)
```

**Description**

Sets the image width.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| uint32_t width | Pointer to the image width, in px.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapInitializationOptions_GetHeight()

```c
Image_ErrorCode OH_PixelmapInitializationOptions_GetHeight(OH_Pixelmap_InitializationOptions *options, uint32_t *height)
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

```c
Image_ErrorCode OH_PixelmapInitializationOptions_SetHeight(OH_Pixelmap_InitializationOptions *options, uint32_t height)
```

**Description**

Sets the image height.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| uint32_t height | Pointer to the image height, in px.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapInitializationOptions_GetPixelFormat()

```c
Image_ErrorCode OH_PixelmapInitializationOptions_GetPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t *pixelFormat)
```

**Description**

Obtains the pixel format.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| int32_t *pixelFormat | Pointer to the pixel format. For details about the available options, see [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapInitializationOptions_SetPixelFormat()

```c
Image_ErrorCode OH_PixelmapInitializationOptions_SetPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t pixelFormat)
```

**Description**

Sets the pixel format.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| int32_t pixelFormat | Pixel format. For details about the available options, see [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapInitializationOptions_GetSrcPixelFormat()

```c
Image_ErrorCode OH_PixelmapInitializationOptions_GetSrcPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t *srcpixelFormat)
```

**Description**

Obtains the source pixel format (the pixel format of the input data used when creating an PixelMap).

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| int32_t *srcpixelFormat | Pointer to the [pixel format](#pixel_format).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapInitializationOptions_SetSrcPixelFormat()

```c
Image_ErrorCode OH_PixelmapInitializationOptions_SetSrcPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t srcpixelFormat)
```

**Description**

Sets the source pixel format (the pixel format of the input data used when creating an PixelMap).

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| int32_t srcpixelFormat | Source pixel format. For details about the available options, see [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapInitializationOptions_GetRowStride()

```c
Image_ErrorCode OH_PixelmapInitializationOptions_GetRowStride(OH_Pixelmap_InitializationOptions *options, int32_t *rowStride)
```

**Description**

Obtains the row stride.<br> The stride is the actual memory size occupied by each row of pixels in the image. The unit is bytes. The stride is calculated as: stride = image width × bytes per pixel + padding, where the padding is the blank area added at the end of each row for memory alignment.

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

```c
Image_ErrorCode OH_PixelmapInitializationOptions_SetRowStride(OH_Pixelmap_InitializationOptions *options, int32_t rowStride)
```

**Description**

Sets the row stride.<br> The stride is the actual memory size occupied by each row of pixels in the image. The unit is bytes. The stride is calculated as: stride = image width × bytes per pixel + padding, where the padding is the blank area added at the end of each row for memory alignment.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| int32_t rowStride | Pointer to the stride. The unit is bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNKNOWN_ERROR**: The struct that **options** points to is released.|

### OH_PixelmapInitializationOptions_GetAlphaType()

```c
Image_ErrorCode OH_PixelmapInitializationOptions_GetAlphaType(OH_Pixelmap_InitializationOptions *options, int32_t *alphaType)
```

**Description**

Obtains the alpha type.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| int32_t *alphaType | Pointer to the alpha type. For details about the alpha types, see [PIXELMAP_ALPHA_TYPE](capi-pixelmap-native-h.md#pixelmap_alpha_type).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapInitializationOptions_SetAlphaType()

```c
Image_ErrorCode OH_PixelmapInitializationOptions_SetAlphaType(OH_Pixelmap_InitializationOptions *options, int32_t alphaType)
```

**Description**

Sets the alpha type.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| int32_t alphaType | Pointer to the alpha type. For details about the alpha types, see [PIXELMAP_ALPHA_TYPE](capi-pixelmap-native-h.md#pixelmap_alpha_type).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapInitializationOptions_GetEditable()

```c
Image_ErrorCode OH_PixelmapInitializationOptions_GetEditable(OH_Pixelmap_InitializationOptions *options, bool *editable)
```

**Description**

Obtains the editable flag.

**Since**: 18

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| bool *editable | Pointer to the editable flag. **true** if editable, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapInitializationOptions_SetEditable()

```c
Image_ErrorCode OH_PixelmapInitializationOptions_SetEditable(OH_Pixelmap_InitializationOptions *options, bool editable)
```

**Description**

Sets the editable flag.

**Since**: 18

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Pointer to an OH_Pixelmap_InitializationOptions struct.|
| bool editable | Editable flag. **true** if editable, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapInitializationOptions_Release()

```c
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

```c
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

```c
Image_ErrorCode OH_PixelmapImageInfo_GetWidth(OH_Pixelmap_ImageInfo *info, uint32_t *width)
```

**Description**

Obtains the image width.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | Pointer to an OH_Pixelmap_ImageInfo struct.|
| uint32_t *width | Pointer to the image width. The unit is px.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapImageInfo_GetHeight()

```c
Image_ErrorCode OH_PixelmapImageInfo_GetHeight(OH_Pixelmap_ImageInfo *info, uint32_t *height)
```

**Description**

Obtains the image height.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | Pointer to an OH_Pixelmap_ImageInfo struct.|
| uint32_t *height | Pointer to the image height. The unit is px.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapImageInfo_GetAlphaMode()

```c
Image_ErrorCode OH_PixelmapImageInfo_GetAlphaMode(OH_Pixelmap_ImageInfo *info, int32_t *alphaMode)
```

**Description**

Obtains the alpha type of an image.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | Pointer to an OH_Pixelmap_ImageInfo struct.|
| int32_t *alphaMode | Obtained alpha type.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapImageInfo_GetRowStride()

```c
Image_ErrorCode OH_PixelmapImageInfo_GetRowStride(OH_Pixelmap_ImageInfo *info, uint32_t *rowStride)
```

**Description**

Obtains the row stride.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | Pointer to an OH_Pixelmap_ImageInfo struct.|
| uint32_t *rowStride | Pointer to the row stride, which is the number of bytes from one row of pixels in memory to the next row of pixels in memory. The unit is bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapImageInfo_GetPixelFormat()

```c
Image_ErrorCode OH_PixelmapImageInfo_GetPixelFormat(OH_Pixelmap_ImageInfo *info, int32_t *pixelFormat)
```

**Description**

Obtains the pixel format.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | Pointer to an OH_Pixelmap_ImageInfo struct.|
| int32_t *pixelFormat | Pointer to the pixel format. For details about the available options, see [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapImageInfo_GetAlphaType()

```c
Image_ErrorCode OH_PixelmapImageInfo_GetAlphaType(OH_Pixelmap_ImageInfo *info, int32_t *alphaType)
```

**Description**

Obtains the default alpha type of OH_PixelmapImageInfo. To obtain the current alpha type of the image, call [OH_PixelmapImageInfo_GetAlphaMode](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getalphamode).

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | Pointer to an OH_Pixelmap_ImageInfo struct.|
| int32_t *alphaType | Pointer to the alpha type. For details about the alpha types, see [PIXELMAP_ALPHA_TYPE](capi-pixelmap-native-h.md#pixelmap_alpha_type).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapImageInfo_GetDynamicRange()

```c
Image_ErrorCode OH_PixelmapImageInfo_GetDynamicRange(OH_Pixelmap_ImageInfo *info, bool *isHdr)
```

**Description**

Obtains the dynamic range of a PixelMap.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | Pointer to an OH_Pixelmap_ImageInfo struct.|
| bool *isHdr | Whether the image is an HDR image. The value **true** means that the image is an HDR image, and the value **false** means the opposite.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapImageInfo_Release()

```c
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

```c
Image_ErrorCode OH_PixelmapNative_CreatePixelmap(uint8_t *data, size_t dataLength, OH_Pixelmap_InitializationOptions *options, OH_PixelmapNative **pixelmap)
```

**Description**

Creates a PixelMap based on the pixel data and image properties.<br>This API cannot create PixelMaps in the PIXEL_FORMAT_RGBA_1010102, PIXEL_FORMAT_YCBCR_P010, or PIXEL_FORMAT_YCRCB_P010 format.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| uint8_t *data | Pixel data array.<br>The input pixel data is parsed in BGRA_8888 format by default. To use another format, see [OH_PixelmapInitializationOptions_SetSrcPixelFormat](#oh_pixelmapinitializationoptions_setsrcpixelformat).<br>If the pixel data contains padding bytes at the end of each row for memory alignment, you must use [OH_PixelmapInitializationOptions_SetRowStride](#oh_pixelmapinitializationoptions_setrowstride) to set the row stride.|
| size_t dataLength | Length of the pixel data array. The unit is bytes.|
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Initialization properties for image creation.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | Double pointer to the OH_PixelmapNative object created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The operation is not supported.|

### OH_PixelmapNative_CreatePixelmapUsingAllocator()

```c
Image_ErrorCode OH_PixelmapNative_CreatePixelmapUsingAllocator(uint8_t *data, size_t dataLength, OH_Pixelmap_InitializationOptions *options, IMAGE_ALLOCATOR_MODE allocator, OH_PixelmapNative **pixelmap)
```

**Description**

Creates a PixelMap based on the pixel data and image properties. You can specify the memory type via the allocator.<br>By default, the system selects an appropriate memory type based on the image type, image size, and platform capability.<br>When processing the PixelMap returned by this API, consider the impact of the row stride. The row stride is the actual memory size occupied by each row of the image. It may be larger than the image width multiplied by the bytes per pixel due to memory alignment. For details, see [OH_PixelmapInitializationOptions_GetRowStride](#oh_pixelmapinitializationoptions_getrowstride).

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| uint8_t *data | Pixel data array.<br>The input pixel data is parsed in BGRA_8888 format by default. To use another format, see [OH_PixelmapInitializationOptions_SetSrcPixelFormat](#oh_pixelmapinitializationoptions_setsrcpixelformat).<br>If the pixel data contains padding bytes at the end of each row for memory alignment, you must use [OH_PixelmapInitializationOptions_SetRowStride](#oh_pixelmapinitializationoptions_setrowstride) to set the row stride.|
| size_t dataLength | Length of the pixel data array. The unit is bytes.|
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Initialization properties for image creation.|
| [IMAGE_ALLOCATOR_MODE](capi-image-common-h.md#image_allocator_mode) allocator | PixelMap memory allocation type.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | Double pointer to the OH_PixelmapNative object created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The operation is not supported.<br>         **IMAGE_TOO_LARGE**: The image is too large to allocate memory.<br>         **IMAGE_DMA_OPERATION_FAILED**: The DMA memory operation fails.<br>         **IMAGE_ALLOCATOR_MODE_UNSUPPORTED**: The current memory allocation type is not supported, for example, creating an HDR image using shared memory.|

### OH_PixelmapNative_ConvertPixelmapNativeToNapi()

```c
Image_ErrorCode OH_PixelmapNative_ConvertPixelmapNativeToNapi(napi_env env, OH_PixelmapNative *pixelmapNative, napi_value *pixelmapNapi)
```

**Description**

Converts an OH_PixelmapNative object to a PixelmapNapi object.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Napi environment pointer.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmapNative | Pointer to an OH_PixelmapNative object.|
| napi_value *pixelmapNapi | Pointer to the converted PixelmapNapi object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: The **pixelmapNative** parameter is nullptr.|

### OH_PixelmapNative_ConvertPixelmapNativeFromNapi()

```c
Image_ErrorCode OH_PixelmapNative_ConvertPixelmapNativeFromNapi(napi_env env, napi_value pixelmapNapi, OH_PixelmapNative **pixelmapNative)
```

**Description**

Converts a PixelmapNapi object to an OH_PixelmapNative object.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| napi_env env | Napi environment pointer.|
| napi_value pixelmapNapi | PixelMapNapi object to convert.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmapNative | Double pointer to the OH_PixelmapNative object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: **pixelmapNative** is nullptr or **pixelmapNapi** is not an PixelmapNapi object.|

### OH_PixelmapNative_ReadPixels()

```c
Image_ErrorCode OH_PixelmapNative_ReadPixels(OH_PixelmapNative *pixelmap, uint8_t *destination, size_t *bufferSize)
```

**Description**

Reads the pixel data of a PixelMap and writes it to the buffer based on the pixel format of the PixelMap.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| uint8_t *destination | Target buffer to which the obtained pixel data will be copied. The pixel format in the buffer is the same as that of the PixelMap and does not contain memory-alignment padding bytes.|
| size_t *bufferSize | Pointer to the buffer size. The unit is bytes. It can be obtained via the [OH_PixelmapNative_GetByteCount](#oh_pixelmapnative_getbytecount) API. The buffer size of the RGBA format is equal to width \* height \* 4, and the buffer size of the NV21 and NV12 formats is equal to width \* height + ((width + 1)/2) \* ((height+1)/2) \* 2.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNKNOWN_ERROR**: An unknown error occurs.|

### OH_PixelmapNative_WritePixels()

```c
Image_ErrorCode OH_PixelmapNative_WritePixels(OH_PixelmapNative *pixelmap, uint8_t *source, size_t bufferSize)
```

**Description**

Writes the pixel data in the buffer to a PixelMap based on the pixel format of the PixelMap.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| uint8_t *source | Source data buffer. The image pixel data in this buffer is written to the PixelMap. The pixel data in the buffer must cover the entire PixelMap and must be in the same pixel format as the PixelMap, without memory-alignment padding bytes.|
| size_t bufferSize | Pointer to the buffer size. The unit is bytes. It can be obtained via the [OH_PixelmapNative_GetByteCount](#oh_pixelmapnative_getbytecount) API. The buffer size of the RGBA format is equal to width \* height \* 4, and the buffer size of the NV21 and NV12 formats is equal to width \* height + ((width + 1)/2) \* ((height+1)/2) \* 2.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The operation is not supported.<br>         **IMAGE_UNKNOWN_ERROR**: An unknown error occurs.|

### OH_PixelmapNative_ReadPixelsFromArea()

```c
Image_ErrorCode OH_PixelmapNative_ReadPixelsFromArea(OH_PixelmapNative *pixelmap, Image_PositionArea *area)
```

**Description**

Reads pixel data from the specified area in a PixelMap and stores the data to the buffer. If the pixel format of the PixelMap is YUV, the data is written to the buffer in the original YUV format; otherwise, it is written in the BGRA_8888 format.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to the PixelMap from which pixels are read.|
| [Image_PositionArea](capi-image-nativemodule-image-positionarea.md) *area | Pointer to the specified PixelMap area from which pixels are read. The pixel data in this area is read and copied to **area->pixels**. If the pixel format of the PixelMap is YUV, the retrieved pixel data remains in the same format as the PixelMap; otherwise, it is converted to the BGRA_8888 format.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: Invalid parameters. For example, **pixelmap** or **area** is incorrect.<br>         **IMAGE_UNKNOWN_ERROR**: Unknown internal error. For example, the pixel format is not supported.|

### OH_PixelmapNative_WritePixelsToArea()

```c
Image_ErrorCode OH_PixelmapNative_WritePixelsToArea(OH_PixelmapNative *pixelmap, Image_PositionArea *area)
```

**Description**

Writes pixel data in the buffer to the specified area in a PixelMap. If the pixel format of the PixelMap is YUV, the data source format must be the same as that of the PixelMap; otherwise, the data source must be in the BGRA_8888 format.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to the PixelMap to which pixels are written.|
| [Image_PositionArea](capi-image-nativemodule-image-positionarea.md) *area | Pointer to the specified area in the PixelMap to which data is written. The pixel data in **area->pixels** is written to this area. If the pixel format of the PixelMap is YUV, the pixel data in **area->pixels** must be in the same format as the PixelMap; otherwise, it must be in the BGRA_8888 format.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: Invalid parameters. For example, **pixelmap** or **area** is incorrect.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The PixelMap is not editable.<br>         **IMAGE_UNKNOWN_ERROR**: Unknown internal error. For example, the pixel format is not supported.|

### OH_PixelmapNative_GetArgbPixels()

```c
Image_ErrorCode OH_PixelmapNative_GetArgbPixels(OH_PixelmapNative *pixelmap, uint8_t *destination, size_t *bufferSize)
```

**Description**

Reads data in ARGB format from a PixelMap.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| uint8_t *destination | Pointer to the buffer to which the pixels will be written. The buffer size must not be less than width × height × 4 bytes.|
| size_t *bufferSize | Pointer to the buffer size. The unit is bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNSUPPORTED_CONVERSION**: The PixelMap format does not support reading ARGB data.<br>         **IMAGE_ALLOC_FAILED**: Memory allocation fails.<br>         **IMAGE_COPY_FAILED**: Memory data copy, read, or operation fails.|

### OH_PixelmapNative_ToSdr()

```c
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

```c
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

### OH_PixelmapNative_SetOpacity()

```c
Image_ErrorCode OH_PixelmapNative_SetOpacity(OH_PixelmapNative *pixelmap, float value)
```

**Description**

Sets the opacity of a PixelMap. The specified opacity value is applied to all pixels.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| float value | Opacity value. The value range is (0.0, 1.0], where **1.0** indicates that the image is completely opaque. A value closer to **0.0** indicates higher transparency.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_GET_IMAGE_DATA_FAILED**: The image data fails to be obtained. Possible cause: The internal data is damaged. Check the log for details.<br>         **IMAGE_PIXELMAP_RELEASED**: The PixelMap has been released.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The PixelMap is locked and the operation is not supported.<br>         **IMAGE_INVALID_PARAMETER**: Invalid parameter. Possible causes: 1. The opacity value is out of range.2. The input parameter is null.<br>         **IMAGE_UNSUPPORTED_DATA_FORMAT**: Unsupported data format. Possible cause: The alpha type is not supported.|

### OH_PixelmapNative_Opacity()

```c
Image_ErrorCode OH_PixelmapNative_Opacity(OH_PixelmapNative *pixelmap, float rate)
```

**Description**

Sets the opacity of a PixelMap. The specified opacity value is applied to all pixels.<br>     Since API version 26.0.0, you are advised to use [OH_PixelmapNative_SetOpacity](#oh_pixelmapnative_setopacity) instead, which provides more comprehensive error information.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| float rate | Opacity value. The value range is (0.0, 1.0], where **1.0** indicates that the image is completely opaque. A value closer to **0.0** indicates higher transparency.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_ApplyScale()

```c
Image_ErrorCode OH_PixelmapNative_ApplyScale(OH_PixelmapNative *pixelmap, float scaleX, float scaleY)
```

**Description**

Scales a PixelMap horizontally or vertically by the specified width and height scaling factors.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| float scaleX | Scale factor of the width. The value cannot be **0**.|
| float scaleY | Scale factor of the height. The value cannot be **0**.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_GET_IMAGE_DATA_FAILED**: The image data fails to be obtained. Possible cause: The internal data is damaged. Check the log for details.<br>         **IMAGE_PIXELMAP_RELEASED**: The PixelMap has been released.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The PixelMap is locked and the operation is not supported.<br>         **IMAGE_INVALID_PARAMETER**: Invalid parameter. Possible cause: The input parameter is null.<br>         **IMAGE_ALLOC_FAILED**: Memory allocation fails. Possible causes: 1. The size of the generated PixelMap is too large.2. Insufficient memory.|

### OH_PixelmapNative_Scale()

```c
Image_ErrorCode OH_PixelmapNative_Scale(OH_PixelmapNative *pixelmap, float scaleX, float scaleY)
```

**Description**

Scales a PixelMap based on the input scale ratio.<br>     Since API version 26.0.0, you are advised to use [OH_PixelmapNative_ApplyScale](capi-pixelmap-native-h.md#oh_pixelmapnative_applyscale) instead, which provides more comprehensive error information.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| float scaleX | Scale ratio of the width. The value cannot be **0**.|
| float scaleY | Scale ratio of the height. The value cannot be **0**.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_ApplyScaleWithAntiAliasing()

```c
Image_ErrorCode OH_PixelmapNative_ApplyScaleWithAntiAliasing(OH_PixelmapNative *pixelmap, float scaleX, float scaleY, OH_PixelmapNative_AntiAliasingLevel level)
```

**Description**

Scales a PixelMap horizontally or vertically by the specified scaling factors for width and height, using the specified anti-aliasing level.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| float scaleX | Scale factor of the width. The value cannot be **0**.|
| float scaleY | Scale factor of the height. The value cannot be **0**.|
| [OH_PixelmapNative_AntiAliasingLevel](#oh_pixelmapnative_antialiasinglevel) level | Anti-aliasing level. This parameter does not take effect for PixelMaps in ASTC format.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_GET_IMAGE_DATA_FAILED**: The image data fails to be obtained. Possible cause: The internal data is damaged. Check the log for details.<br>         **IMAGE_PIXELMAP_RELEASED**: The PixelMap has been released.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The PixelMap is locked and the operation is not supported.<br>         **IMAGE_INVALID_PARAMETER**: Invalid parameter. Possible cause: The input parameter is null.<br>         **IMAGE_ALLOC_FAILED**: Memory allocation fails. Possible causes: 1. The size of the generated PixelMap is too large.2. Insufficient memory.|

### OH_PixelmapNative_ScaleWithAntiAliasing()

```c
Image_ErrorCode OH_PixelmapNative_ScaleWithAntiAliasing(OH_PixelmapNative *pixelmap, float scaleX, float scaleY, OH_PixelmapNative_AntiAliasingLevel level)
```

**Description**

Scales an image based on the specified anti-aliasing level and scale ratio.<br>     Since API version 26.0.0, you are advised to use [OH_PixelmapNative_ApplyScaleWithAntiAliasing](#oh_pixelmapnative_applyscalewithantialiasing) instead, which provides more comprehensive error information.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| float scaleX | Scale ratio of the width. The value cannot be **0**.|
| float scaleY | Scale ratio of the height. The value cannot be **0**.|
| [OH_PixelmapNative_AntiAliasingLevel](#oh_pixelmapnative_antialiasinglevel) level | Anti-aliasing level. This parameter does not take effect for PixelMaps in ASTC format.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_TOO_LARGE**: The image is too large.<br>         **IMAGE_ALLOC_FAILED**: Memory allocation fails.<br>         **IMAGE_UNKNOWN_ERROR**: The struct that **pixelmap** points to is released.|

### OH_PixelmapNative_CreateScaledPixelMap()

```c
Image_ErrorCode OH_PixelmapNative_CreateScaledPixelMap(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap, float scaleX, float scaleY)
```

**Description**

Creates an image that has been resized based on the scale factors of the width and height. The generated PixelMap is not editable. This API does not copy the HDR metadata or EXIF information from the original image.

**Since**: 18

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *srcPixelmap | Pointer to the source PixelMap, which is an OH_PixelmapNative object.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **dstPixelmap | Pointer to the target PixelMap, which is an OH_PixelmapNative object.|
| float scaleX | Scale ratio of the width. The value cannot be **0**.|
| float scaleY | Scale ratio of the height. The value cannot be **0**.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_CreateScaledPixelMapWithAntiAliasing()

```c
Image_ErrorCode OH_PixelmapNative_CreateScaledPixelMapWithAntiAliasing(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap, float scaleX, float scaleY, OH_PixelmapNative_AntiAliasingLevel level)
```

**Description**

Creates an image that has been resized based on the specified anti-aliasing level and the scale factors of the width and height. The generated PixelMap is not editable. This API does not copy the HDR metadata or EXIF information from the original image.

**Since**: 18

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *srcPixelmap | Pointer to the source PixelMap, which is an OH_PixelmapNative object.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **dstPixelmap | Pointer to the target PixelMap, which is an OH_PixelmapNative object.|
| float scaleX | Scale ratio of the width. The value cannot be **0**.|
| float scaleY | Scale ratio of the height. The value cannot be **0**.|
| [OH_PixelmapNative_AntiAliasingLevel](#oh_pixelmapnative_antialiasinglevel) level | Anti-aliasing level. This parameter does not take effect for PixelMaps in ASTC format.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_TOO_LARGE**: The image is too large.<br>         **IMAGE_ALLOC_FAILED**: Memory allocation fails.|

### OH_PixelmapNative_CreateAlphaPixelmap()

```c
Image_ErrorCode OH_PixelmapNative_CreateAlphaPixelmap(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap)
```

**Description**

Creates a new non-editable ALPHA_8 PixelMap that contains only the Alpha channel from the source PixelMap.<br>     If the format of the source PixelMap is ALPHA_F16, the newly created PixelMap will retain the ALPHA_F16 format.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *srcPixelmap | Pointer to the source PixelMap that provides the alpha channel data.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **dstPixelmap | Double pointer to the target PixelMap created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: Invalid parameters. For example, **srcPixelmap** or **dstPixelmap** is incorrect.|

### OH_PixelmapNative_Clone()

```c
Image_ErrorCode OH_PixelmapNative_Clone(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap)
```

**Description**

Copies the source PixelMap to create a new PixelMap. This API does not copy the EXIF information from the original image.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *srcPixelmap | Source PixelMap to be copied.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **dstPixelmap | Created target PixelMap.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: Invalid parameters. For example, **srcPixelmap** or **dstPixelmap** is incorrect.<br>         **IMAGE_UNSUPPORTED_DATA_FORMAT**: The pixel format is not supported.<br>         **IMAGE_TOO_LARGE**: The source PixelMap is too large.<br>         **IMAGE_INIT_FAILED**: The target PixelMap fails to be initialized.<br>         **IMAGE_ALLOC_FAILED**: Memory allocation or data copy fails.|

### OH_PixelmapNative_CreateCroppedAndScaledPixelMap()

```c
Image_ErrorCode OH_PixelmapNative_CreateCroppedAndScaledPixelMap(OH_PixelmapNative *srcPixelmap, Image_Region *region, Image_Scale *scale, OH_PixelmapNative_AntiAliasingLevel level, OH_PixelmapNative **dstPixelmap)
```

**Description**

Creates a PixelMap that is cropped and scaled based on the source PixelMap. This API does not copy the EXIF information from the original image.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *srcPixelmap | Pointer to the source PixelMap.|
| [Image_Region](capi-image-nativemodule-image-region.md) *region | Pointer to the region to crop.|
| [Image_Scale](capi-image-nativemodule-image-scale.md) *scale | Pointer to the scale factor of the width and height. It must not be **0**.|
| [OH_PixelmapNative_AntiAliasingLevel](capi-pixelmap-native-h.md#oh_pixelmapnative_antialiasinglevel) level | Scale interpolation algorithm. This parameter does not take effect for PixelMaps in ASTC format.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **dstPixelmap | Double pointer to the target PixelMap created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: Invalid parameters. For example, **srcPixelmap**, **region**, **scale**, or **dstPixelmap** is incorrect.<br>         **IMAGE_UNSUPPORTED_DATA_FORMAT**: The pixel format is not supported.<br>         **IMAGE_TOO_LARGE**: The source PixelMap is too large.<br>         **IMAGE_INIT_FAILED**: The target PixelMap fails to be initialized.<br>         **IMAGE_ALLOC_FAILED**: Memory allocation or data copy fails.|

### OH_PixelmapNative_ApplyTranslate()

```c
Image_ErrorCode OH_PixelmapNative_ApplyTranslate(OH_PixelmapNative *pixelmap, float x, float y)
```

**Description**

Translates the PixelMap horizontally or vertically by the specified horizontal and vertical distances.<br>After translation, the image size becomes: width = original width + x, height = original height + y.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| float x | Horizontal translation distance. Positive values move the image to the right; negative values move it to the left. The value range is (-image width, +∞). The unit is px.<br>When the value is negative, the translation is equivalent to cropping x columns of pixels from the left side of the image.|
| float y | Vertical translation distance. Positive values move the image downward; negative values move it upward. The value range is (-image height, +∞). The unit is px.<br>When the value is negative, the translation is equivalent to cropping y rows of pixels from the top of the image.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_GET_IMAGE_DATA_FAILED**: The image data fails to be obtained. Possible cause: The internal data is damaged. Check the log for details.<br>         **IMAGE_PIXELMAP_RELEASED**: The PixelMap has been released.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The PixelMap is locked and the operation is not supported.<br>         **IMAGE_INVALID_PARAMETER**: Invalid parameter. Possible cause: The input parameter is null.<br>         **IMAGE_ALLOC_FAILED**: Memory allocation fails. Possible causes: 1. The size of the generated PixelMap is too large.2. Insufficient memory.|

### OH_PixelmapNative_Translate()

```c
Image_ErrorCode OH_PixelmapNative_Translate(OH_PixelmapNative *pixelmap, float x, float y)
```

**Description**

Translates an image by the specified translation distances.<br>After translation, the image size becomes: width = original width + x, height = original height + y.<br>     Since API version 26.0.0, you are advised to use [OH_PixelmapNative_ApplyTranslate](capi-pixelmap-native-h.md#oh_pixelmapnative_applytranslate) instead, which provides more comprehensive error information.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| float x | Horizontal translation distance. Positive values move the image to the right; negative values move it to the left. The value range is (-image width, +∞). The unit is px.<br>When the value is negative, the translation is equivalent to cropping x columns of pixels from the left side of the image.|
| float y | Vertical translation distance. Positive values move the image downward; negative values move it upward. The value range is (-image height, +∞). The unit is px.<br>When the value is negative, the translation is equivalent to cropping y rows of pixels from the top of the image.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_ApplyRotate()

```c
Image_ErrorCode OH_PixelmapNative_ApplyRotate(OH_PixelmapNative *pixelmap, float angle)
```

**Description**

Rotates a PixelMap by the specified angle. YUV formats support only rotation angles that are multiples of 90°.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| float angle | Rotation angle. The unit is degrees (°).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_GET_IMAGE_DATA_FAILED**: The image data fails to be obtained. Possible cause: The internal data is damaged. Check the log for details.<br>         **IMAGE_PIXELMAP_RELEASED**: The PixelMap has been released.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The PixelMap is locked and the operation is not supported.<br>         **IMAGE_INVALID_PARAMETER**: Invalid parameter. Possible cause: The input parameter is null.<br>         **IMAGE_ALLOC_FAILED**: Memory allocation fails. Possible causes: 1. The size of the generated PixelMap is too large.2. Insufficient memory.|

### OH_PixelmapNative_Rotate()

```c
Image_ErrorCode OH_PixelmapNative_Rotate(OH_PixelmapNative *pixelmap, float angle)
```

**Description**

Rotates an image by the specified angle. YUV formats support only rotation angles that are multiples of 90°.<br>     Since API version 26.0.0, you are advised to use [OH_PixelmapNative_ApplyRotate](#oh_pixelmapnative_applyrotate) instead, which provides more comprehensive error information.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| float angle | Angle to rotate. The unit is degrees (°).|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_ApplyFlip()

```c
Image_ErrorCode OH_PixelmapNative_ApplyFlip(OH_PixelmapNative *pixelmap, bool shouldFlipHorizontally, bool shouldFlipVertically)
```

**Description**

Flips an image based on the specified horizontal or vertical flip conditions.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| bool shouldFlipHorizontally | Whether to flip horizontally. **true** to flip the image horizontally, **false** otherwise.|
| bool shouldFlipVertically | Whether to flip vertically. **true** to flip the image vertically, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_GET_IMAGE_DATA_FAILED**: The image data fails to be obtained. Possible cause: The internal data is damaged. Check the log for details.<br>         **IMAGE_PIXELMAP_RELEASED**: The PixelMap has been released.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The PixelMap is locked and the operation is not supported.<br>         **IMAGE_INVALID_PARAMETER**: Invalid parameter. Possible cause: The input parameter is null.<br>         **IMAGE_ALLOC_FAILED**: Memory allocation fails. Possible cause: The system memory is insufficient.|

### OH_PixelmapNative_Flip()

```c
Image_ErrorCode OH_PixelmapNative_Flip(OH_PixelmapNative *pixelmap, bool shouldFlipHorizontally, bool shouldFlipVertically)
```

**Description**

Flips a PixelMap based on a given angle.<br>     Since API version 26.0.0, you are advised to use [OH_PixelmapNative_ApplyFlip](capi-pixelmap-native-h.md#oh_pixelmapnative_applyflip) instead, which provides more comprehensive error information.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| bool shouldFlipHorizontally | Whether to flip the image horizontally. **true** to flip the image horizontally, **false** otherwise.|
| bool shouldFlipVertically | Whether to flip the image vertically. **true** to flip the image vertically, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_ApplyCrop()

```c
Image_ErrorCode OH_PixelmapNative_ApplyCrop(OH_PixelmapNative *pixelmap, Image_Region *region)
```

**Description**

Crops a PixelMap based on the specified region information.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| [Image_Region](capi-image-nativemodule-image-region.md) *region | Pointer to the cropping region.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_GET_IMAGE_DATA_FAILED**: The image data fails to be obtained. Possible cause: The internal data is damaged. Check the log for details.<br>         **IMAGE_PIXELMAP_RELEASED**: The PixelMap has been released.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The PixelMap is locked and the operation is not supported.<br>         **IMAGE_INVALID_REGION**: The specified region is invalid or out of range.<br>         **IMAGE_INVALID_PARAMETER**: Invalid parameter. Possible cause: An input parameter is null.<br>         **IMAGE_ALLOC_FAILED**: Memory allocation fails. Possible causes: 1. Failed to process the pixel data.2. Insufficient memory.|

### OH_PixelmapNative_Crop()

```c
Image_ErrorCode OH_PixelmapNative_Crop(OH_PixelmapNative *pixelmap, Image_Region *region)
```

**Description**

Crops a PixelMap based on the input region information.<br>     Since API version 26.0.0, you are advised to use [OH_PixelmapNative_ApplyCrop](capi-pixelmap-native-h.md#oh_pixelmapnative_applycrop) instead, which provides more comprehensive error information.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| [Image_Region](capi-image-nativemodule-image-region.md) *region | Cropping region, including the start coordinates, width, and height.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_Release()

```c
Image_ErrorCode OH_PixelmapNative_Release(OH_PixelmapNative *pixelmap)
```

**Description**

Releases the pointer to an OH_PixelmapNative object. (The pointer cannot be released when the memory is locked by [OH_PixelmapNative_AccessPixels](capi-pixelmap-native-h.md#oh_pixelmapnative_accesspixels).)<br>You are advised to use [OH_PixelmapNative_Destroy](capi-pixelmap-native-h.md#oh_pixelmapnative_destroy).

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

```c
Image_ErrorCode OH_PixelmapNative_Destroy(OH_PixelmapNative **pixelmap)
```

**Description**

Releases the pointer to an OH_PixelmapNative object, regardless of whether the memory is locked by [OH_PixelmapNative_AccessPixels](capi-pixelmap-native-h.md#oh_pixelmapnative_accesspixels).

**Since**: 18

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | Pointer to an OH_PixelmapNative object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_ConvertAlphaType()

```c
Image_ErrorCode OH_PixelmapNative_ConvertAlphaType(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative *dstPixelmap, const bool toPremul)
```

**Description**

Converts the alpha type of the PixelMap pixel data between premultiplied mode ([PIXELMAP_ALPHA_TYPE_PREMULTIPLIED](capi-pixelmap-native-h.md#pixelmap_alpha_type)) and non-premultiplied mode ([PIXELMAP_ALPHA_TYPE_UNPREMULTIPLIED](capi-pixelmap-native-h.md#pixelmap_alpha_type)). This conversion is supported only for pixel formats that contain an alpha channel, except RGBA_F16 and ASTC_4x4.<br>     For details about the pixel formats, see [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format).

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *srcPixelmap | Pointer to the source PixelMap, which contains the pixel data to be converted. Its alpha type must be either premultiplied or non-premultiplied.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *dstPixelmap | Pointer to an empty target PixelMap. Its attributes (width, height, pixel format, and more) must be the same as those of the source PixelMap, but its alpha type must be the opposite of the source PixelMap (for example, if the source PixelMap is premultiplied, the destination PixelMap must be non-premultiplied). The target PixelMap must be editable. The converted pixel data will be written to this PixelMap.|
| const bool toPremul | Conversion direction. The value **true** indicates conversion from non-premultiplied to premultiplied, and the value **false** indicates conversion from premultiplied to non-premultiplied.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_GET_IMAGE_DATA_FAILED**: The image data fails to be obtained. Possible cause: The internal data is damaged. Check the log for details.<br>         **IMAGE_PIXELMAP_RELEASED**: Either of the PixelMaps has been released.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The PixelMap is locked and the operation is not supported.<br>         **IMAGE_INVALID_PARAMETER**: Invalid parameter. Possible causes: 1. A PixelMap does not meet the requirements.2. An input parameter is null.<br>         **IMAGE_UNSUPPORTED_DATA_FORMAT**: The pixel format of a PixelMap is not supported.|

### OH_PixelmapNative_ConvertAlphaFormat()

```c
Image_ErrorCode OH_PixelmapNative_ConvertAlphaFormat(OH_PixelmapNative* srcpixelmap, OH_PixelmapNative* dstpixelmap, const bool isPremul)
```

**Description**

Converts the alpha type of the PixelMap pixel data between premultiplied mode and non-premultiplied mode. This conversion is supported only for pixel formats that contain an alpha channel, except RGBA_F16 and ASTC_4x4.<br>     Since API version 26.0.0, you are advised to use [OH_PixelmapNative_ConvertAlphaType](capi-pixelmap-native-h.md#oh_pixelmapnative_convertalphatype) instead, which provides more comprehensive error information.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md)* srcpixelmap | Pointer to the source PixelMap, which contains the pixel data to be converted. Its alpha type must be either premultiplied or non-premultiplied.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md)* dstpixelmap | Pointer to an empty target PixelMap. Its attributes (width, height, pixel format, and more) must be the same as those of the source PixelMap, but its alpha type must be the opposite of the source PixelMap (for example, if the source PixelMap is premultiplied, the destination PixelMap must be non-premultiplied). The target PixelMap must be editable. The converted pixel data will be written to this PixelMap.|
| const bool isPremul | Conversion direction. The value **true** means a conversion from premultiplied alpha to non-premultiplied alpha, and **false** means a conversion from non-premultiplied alpha to premultiplied alpha.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_CreateEmptyPixelmap()

```c
Image_ErrorCode OH_PixelmapNative_CreateEmptyPixelmap(OH_Pixelmap_InitializationOptions *options, OH_PixelmapNative **pixelmap)
```

**Description**

Creates an empty PixelMap object based on **OH_Pixelmap_InitializationOptions**. The memory data is 0.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Initialization properties for image creation.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | Double pointer to the OH_PixelmapNative object created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_CreateEmptyPixelmapUsingAllocator()

```c
Image_ErrorCode OH_PixelmapNative_CreateEmptyPixelmapUsingAllocator(OH_Pixelmap_InitializationOptions *options, IMAGE_ALLOCATOR_MODE allocator, OH_PixelmapNative **pixelmap)
```

**Description**

Creates an empty PixelMap object based on **options**. The memory type used by the PixelMap can be specified by **allocator**. By default, the system selects an appropriate memory type based on the image type, image size, and platform capability. When processing the PixelMap returned by this API, consider the impact of the row stride. The row stride is the actual memory size occupied by each row of the image. It may be larger than the image width multiplied by the bytes per pixel due to memory alignment. For details, see [OH_PixelmapInitializationOptions_GetRowStride](#oh_pixelmapinitializationoptions_getrowstride).

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | Initialization properties for image creation.|
| [IMAGE_ALLOCATOR_MODE](capi-image-common-h.md#image_allocator_mode) allocator | Type of memory allocation for the PixelMap.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | Double pointer to the OH_PixelmapNative object created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The operation is not supported.<br>         **IMAGE_TOO_LARGE**: The image is too large to allocate memory.<br>         **IMAGE_DMA_OPERATION_FAILED**: The DMA memory operation fails.<br>         **IMAGE_ALLOCATOR_MODE_UNSUPPORTED**: The current memory allocation type is not supported, for example, creating an HDR image using shared memory.|

### OH_PixelmapNative_CreatePixelmapFromSurface()

```c
Image_ErrorCode OH_PixelmapNative_CreatePixelmapFromSurface(const char *surfaceId, size_t length, OH_PixelmapNative **pixelmap)
```

**Description**

Creates a PixelMap based on the surface ID. If the surface carries rotation or flipping information and processing is required, use [OH_PixelmapNative_CreatePixelmapFromSurfaceWithTransformation](#oh_pixelmapnative_createpixelmapfromsurfacewithtransformation).

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| const char *surfaceId | Pointer to the string of the surface ID.|
| size_t length | Length of the surface ID string. The unit is bytes.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | Double pointer to the PixelMap created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: Invalid parameters. For example, **surfaceId** or **pixelmap** is incorrect.<br>         **IMAGE_CREATE_PIXELMAP_FAILED**: PixelMap creation fails.|

### OH_PixelmapNative_CreatePixelmapFromSurfaceWithTransformation()

```c
Image_ErrorCode OH_PixelmapNative_CreatePixelmapFromSurfaceWithTransformation(const char *surfaceId, size_t length, bool transformEnabled, OH_PixelmapNative **pixelmap)
```

**Description**

Creates a PixelMap object for a preview stream image based on a surface ID. The surface may carry rotation or flipping information.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| const char *surfaceId | Surface ID.|
| size_t length | Length of the surface ID. The unit is bytes.|
| bool transformEnabled | Whether to perform inverse transformation on the surface that carries transformation information to eliminate the rotation or flipping effect of the PixelMap. If the surface does not carry transformation information, this parameter does not take effect.<br>     If this parameter is set to **true**, the inverse transformation is performed. The transform angle matches the angle carried by the surface but in the opposite direction, and the output PixelMap has no rotation or flipping effect.<br>     If this parameter is set to **false**, no inverse transformation is performed. The output PixelMap has the rotation or flipping effect based on the transformation information in the surface.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | Double pointer to the PixelMap created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_INVALID_PARAMETER**: Invalid parameters. For example, **surfaceId** or **pixelmap** is incorrect.<br>         **IMAGE_UNSUPPORTED_OPERATION**: The operation is not supported. For example, the operation is called across platforms.<br>         **IMAGE_GET_IMAGE_DATA_FAILED**: Failed to obtain the surface data.<br>         **IMAGE_CREATE_PIXELMAP_FAILED**: PixelMap creation fails.|

**Reference**

[OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md)


### OH_PixelmapNative_CreatePixelmapFromNativeBuffer()

```c
Image_ErrorCode OH_PixelmapNative_CreatePixelmapFromNativeBuffer(OH_NativeBuffer *nativeBuffer, OH_PixelmapNative **pixelmap)
```

**Description**

Creates a PixelMap based on a NativeBuffer. If the NativeBuffer usage does not have CPU access permission configured (for details, see [OH_NativeBuffer_Usage](../apis-arkgraphics2d/capi-native-buffer-h.md#oh_nativebuffer_usage)), creation is not supported.<br> The supported pixel formats are RGBA_8888, NV21, NV12, YCBCR_P010, and YCRCB_P010.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeBuffer](capi-image-nativemodule-image-nativemodule-oh-nativebuffer.md) *nativeBuffer | Pointer to the NativeBuffer object that contains PixelMap data. The NativeBuffer usage must have CPU access permission configured (for details, see [OH_NativeBuffer_Usage](../apis-arkgraphics2d/capi-native-buffer-h.md#oh_nativebuffer_usage)), and the pixel format must be RGBA_8888, NV21, NV12, YCBCR_P010, or YCRCB_P010.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | Double pointer to the PixelMap created.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: Invalid parameters. For example, **nativeBuffer** or **pixelmap** is incorrect, the pixel format is not supported, or the CPU access permission is not configured.<br>         **IMAGE_CREATE_PIXELMAP_FAILED**: PixelMap creation fails.|

### OH_PixelmapNative_GetNativeBuffer()

```c
Image_ErrorCode OH_PixelmapNative_GetNativeBuffer(OH_PixelmapNative *pixelmap, OH_NativeBuffer **nativeBuffer)
```

**Description**

Obtains the NativeBuffer object from a PixelMap in the DMA memory.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Source PixelMap from which to obtain the NativeBuffer. The memory type must be DMA.|
| [OH_NativeBuffer](capi-image-nativemodule-image-nativemodule-oh-nativebuffer.md) **nativeBuffer | Double pointer to the NativeBuffer object obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_DMA_NOT_EXIST**: DMA memory does not exist.<br>         **IMAGE_DMA_OPERATION_FAILED**: The DMA memory operation fails.|

### OH_PixelmapNative_GetMetadata()

```c
Image_ErrorCode OH_PixelmapNative_GetMetadata(OH_PixelmapNative *pixelmap, OH_Pixelmap_HdrMetadataKey key, OH_Pixelmap_HdrMetadataValue **value)
```

**Description**

Obtains HDR metadata of a PixelMap. The type of metadata to be obtained is specified by passing an [OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey) key, and the corresponding metadata value is returned via [OH_Pixelmap_HdrMetadataValue](capi-image-nativemodule-oh-pixelmap-hdrmetadatavalue.md).

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to the OH_PixelmapNative to be operated. The memory type of the PixelMap must be DMA.|
| [OH_Pixelmap_HdrMetadataKey](capi-pixelmap-native-h.md#oh_pixelmap_hdrmetadatakey) key | HDR metadata key.|
| [OH_Pixelmap_HdrMetadataValue](capi-image-nativemodule-oh-pixelmap-hdrmetadatavalue.md) **value | Double pointer to the value of the metadata key.<br>If the obtained metadata is dynamic metadata (HDR_DYNAMIC_METADATA) and the API is successfully called, you must call **free(value->dynamicMetadata.data)** to free the memory after using the metadata.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_DMA_NOT_EXIST**: DMA memory does not exist.<br>         **IMAGE_COPY_FAILED**: Memory copy fails.|

### OH_PixelmapNative_SetMetadata()

```c
Image_ErrorCode OH_PixelmapNative_SetMetadata(OH_PixelmapNative *pixelmap, OH_Pixelmap_HdrMetadataKey key, OH_Pixelmap_HdrMetadataValue *value)
```

**Description**

Sets the HDR metadata for a PixelMap. The type of metadata to be set is specified by passing an [OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey) key, and the corresponding metadata value is passed via [OH_Pixelmap_HdrMetadataValue](capi-image-nativemodule-oh-pixelmap-hdrmetadatavalue.md).

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to the OH_PixelmapNative to be operated. The memory type of the PixelMap must be DMA.|
| [OH_Pixelmap_HdrMetadataKey](capi-pixelmap-native-h.md#oh_pixelmap_hdrmetadatakey) key | HDR metadata key.|
| [OH_Pixelmap_HdrMetadataValue](capi-image-nativemodule-oh-pixelmap-hdrmetadatavalue.md) *value | Pointer to the value of the metadata key.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.<br>         **IMAGE_DMA_NOT_EXIST**: DMA memory does not exist.<br>         **IMAGE_COPY_FAILED**: Memory copy fails.|

### OH_PixelmapNative_SetColorSpaceNative()

```c
Image_ErrorCode OH_PixelmapNative_SetColorSpaceNative(OH_PixelmapNative *pixelmap, OH_NativeColorSpaceManager *colorSpaceNative)
```

**Description**

Sets the NativeColorSpaceManager object for a PixelMap to manage the color space information of the PixelMap.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to the target PixelMap of the NativeColorSpaceManager object to set.|
| [OH_NativeColorSpaceManager](capi-image-nativemodule-oh-nativecolorspacemanager.md) *colorSpaceNative | Pointer to a NativeColorSpaceManager object.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_GetColorSpaceNative()

```c
Image_ErrorCode OH_PixelmapNative_GetColorSpaceNative(OH_PixelmapNative *pixelmap, OH_NativeColorSpaceManager **colorSpaceNative)
```

**Description**

Obtains the NativeColorSpaceManager object of a PixelMap to query the color space information currently configured for the PixelMap.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to the source PixelMap of the NativeColorSpaceManager to be obtained.|
| [OH_NativeColorSpaceManager](capi-image-nativemodule-oh-nativecolorspacemanager.md) **colorSpaceNative | Double pointer to the NativeColorSpaceManager object obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: A parameter is incorrect.|

### OH_PixelmapNative_SetMemoryName()

```c
Image_ErrorCode OH_PixelmapNative_SetMemoryName(OH_PixelmapNative *pixelmap, char *name, size_t *size)
```

**Description**

Sets the memory name of a PixelMap to facilitate memory identification during debugging or issue troubleshooting.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to an OH_PixelmapNative object.|
| char *name | Pointer to the PixelMap memory name. For the DMA memory type, the value range is [1, 255]. For the SHARE_MEMORY memory type, the value range is [1, 244]. The unit is bytes.|
| size_t *size | Byte size of the memory name to be set for the PixelMap. For the DMA memory type, the value range is [1, 255]. For the SHARE_MEMORY memory type, the value range is [1, 244]. The unit is bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: The name length exceeds the value range. For the DMA memory type, the value range is [1, 255]. For the SHARE_MEMORY memory type, the value range is [1, 244]. The unit is bytes.<br>         **IMAGE_UNSUPPORTED_MEMORY_FORMAT**: The memory is neither DMA memory nor SHARE_MEMORY memory.|

### OH_PixelmapNative_GetByteCount()

```c
Image_ErrorCode OH_PixelmapNative_GetByteCount(OH_PixelmapNative *pixelmap, uint32_t *byteCount)
```

**Description**

Obtains the total number of bytes occupied by all pixels in a PixelMap, excluding memory-alignment padding bytes.

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

```c
Image_ErrorCode OH_PixelmapNative_GetAllocationByteCount(OH_PixelmapNative *pixelmap, uint32_t *allocationByteCount)
```

**Description**

Obtains the actual number of memory bytes allocated for storing pixel data, including memory-alignment padding bytes. Unlike [OH_PixelmapNative_GetByteCount](#oh_pixelmapnative_getbytecount) (which does not include padding), this API returns the actual memory size allocated by the system for the PixelMap.

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

```c
Image_ErrorCode OH_PixelmapNative_AccessPixels(OH_PixelmapNative *pixelmap, void **addr)
```

**Description**

Obtains the memory address where the pixels of a PixelMap are stored and locks the memory.<br> When the memory is locked, any attempts to alter or free the pixel data of the PixelMap will fail or be ineffective.<br> After use, you must call [OH_PixelmapNative_UnaccessPixels](capi-pixelmap-native-h.md#oh_pixelmapnative_unaccesspixels) to release the memory lock. The two APIs must be used in pairs.

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

```c
Image_ErrorCode OH_PixelmapNative_UnaccessPixels(OH_PixelmapNative *pixelmap)
```

**Description**

Unlocks the memory allocated to store the pixels of a PixelMap.<br> This function must be used together with [OH_PixelmapNative_AccessPixels](capi-pixelmap-native-h.md#oh_pixelmapnative_accesspixels).

**Since**: 15

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to a PixelMap.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **Image_BAD_PARAMETER**: The **pixelmap** parameter is invalid.<br>         **IMAGE_LOCK_UNLOCK_FAILED**: Memory unlocking fails.|

### OH_PixelmapNative_GetUniqueId()

```c
Image_ErrorCode OH_PixelmapNative_GetUniqueId(OH_PixelmapNative *pixelmap, uint32_t *uniqueId)
```

**Description**

Obtains the unique ID of a PixelMap.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to the unique ID of the PixelMap.|
| uint32_t *uniqueId | Pointer to the unique ID obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: Invalid parameters. For example, **pixelmap** or **uniqueId** is incorrect.|

### OH_PixelmapNative_IsReleased()

```c
Image_ErrorCode OH_PixelmapNative_IsReleased(OH_PixelmapNative *pixelmap, bool *released)
```

**Description**

Checks whether a PixelMap is released. If released, any attempt to access the internal data of this object will fail.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | Pointer to the PixelMap to be checked.|
| bool *released | Release status of the PixelMap. The value **true** indicates that the PixelMap is released, and **false** indicates the opposite.|

**Returns**

| Type| Description|
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | **IMAGE_SUCCESS**: The operation is successful.<br>         **IMAGE_BAD_PARAMETER**: Invalid parameters. For example, **pixelmap** or **released** is incorrect.|
