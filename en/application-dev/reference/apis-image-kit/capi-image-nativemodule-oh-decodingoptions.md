# OH_DecodingOptions

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=79213852c1a278fd2c8d18b1a077b8eb603c4cd5 translatedAt=2026-08-03T03:59:37.685Z pushedAt=2026-08-04T04:21:02.096Z -->

```c
typedef struct OH_DecodingOptions OH_DecodingOptions
```

## Overview

The OH_DecodingOptions struct describes the decoding options encapsulated at the native layer. The struct is used to set decoding options and is passed in as an input parameter for creating a PixelMap. For details, see [OH_ImageSourceNative_CreatePixelmap](capi-image-source-native-h.md#oh_imagesourcenative_createpixelmap).

The struct cannot be directly operated. Instead, functions must be called to create and release the struct and operate the fields in the struct.

To create an OH_DecodingOptions object, call [OH_DecodingOptions_Create](capi-image-source-native-h.md#oh_decodingoptions_create).

To release an OH_DecodingOptions object, call [OH_DecodingOptions_Release](capi-image-source-native-h.md#oh_decodingoptions_release).

Usage restrictions: OH_DecodingOptions is used to configure PixelMap decoding parameters. It is typically used as an input parameter for [OH_ImageSourceNative_CreatePixelmap](capi-image-source-native-h.md#oh_imagesourcenative_createpixelmap), [OH_ImageSourceNative_CreatePixelmapUsingAllocator](capi-image-source-native-h.md#oh_imagesourcenative_createpixelmapusingallocator), or [OH_ImageSourceNative_CreatePixelmapList](capi-image-source-native-h.md#oh_imagesourcenative_createpixelmaplist). Before use, an object must be created via [OH_DecodingOptions_Create](capi-image-source-native-h.md#oh_decodingoptions_create). After use, call [OH_DecodingOptions_Release](capi-image-source-native-h.md#oh_decodingoptions_release) to release the object.

Resource management: Releasing an OH_ImageSourceNative object or a decoded OH_PixelmapNative object does not automatically release the OH_DecodingOptions object. After an OH_DecodingOptions object is released, it should not be passed to decoding APIs or have its field getter and setter functions called.

The table below describes the content and operation mode of the OH_DecodingOptions struct.

| Field Type| Field Name| Field Description| Default Value| Getter Function| Setter Function|
| -------- | -------- | -------- | -------- | -------- | -------- |
| int32_t | pixelFormat | Pixel format. | RGBA_8888 | [OH_DecodingOptions_GetPixelFormat](capi-image-source-native-h.md#oh_decodingoptions_getpixelformat) | [OH_DecodingOptions_SetPixelFormat](capi-image-source-native-h.md#oh_decodingoptions_setpixelformat) |
| uint32_t | index | Index of the image to decode. | 0 | [OH_DecodingOptions_GetIndex](capi-image-source-native-h.md#oh_decodingoptions_getindex) | [OH_DecodingOptions_SetIndex](capi-image-source-native-h.md#oh_decodingoptions_setindex) |
| float | rotate | Rotation angle. | Unit: deg. Default value: 0 | [OH_DecodingOptions_GetRotate](capi-image-source-native-h.md#oh_decodingoptions_getrotate) | [OH_DecodingOptions_SetRotate](capi-image-source-native-h.md#oh_decodingoptions_setrotate) |
| Image_Size | desiredSize | Desired output size. | Defaults to the original image size. | [OH_DecodingOptions_GetDesiredSize](capi-image-source-native-h.md#oh_decodingoptions_getdesiredsize) | [OH_DecodingOptions_SetDesiredSize](capi-image-source-native-h.md#oh_decodingoptions_setdesiredsize) |
| Image_Region | desiredRegion | Region to decode. | Defaults to the region of the full image size. | [OH_DecodingOptions_GetDesiredRegion](capi-image-source-native-h.md#oh_decodingoptions_getdesiredregion) | [OH_DecodingOptions_SetDesiredRegion](capi-image-source-native-h.md#oh_decodingoptions_setdesiredregion) |
| int32_t | desiredDynamicRange | Desired dynamic range. | SDR |[OH_DecodingOptions_GetDesiredDynamicRange](capi-image-source-native-h.md#oh_decodingoptions_getdesireddynamicrange) | [OH_DecodingOptions_SetDesiredDynamicRange](capi-image-source-native-h.md#oh_decodingoptions_setdesireddynamicrange) |
| int32_t | desiredColorSpace | Desired color space. | Default color space. | [OH_DecodingOptions_GetDesiredColorSpace](capi-image-source-native-h.md#oh_decodingoptions_getdesiredcolorspace) | [OH_DecodingOptions_SetDesiredColorSpace](capi-image-source-native-h.md#oh_decodingoptions_setdesiredcolorspace) |
| Image_Region | cropRegion | Cropping region. | Defaults to the region of the full image size. | [OH_DecodingOptions_GetCropRegion](capi-image-source-native-h.md#oh_decodingoptions_getcropregion) | [OH_DecodingOptions_SetCropRegion](capi-image-source-native-h.md#oh_decodingoptions_setcropregion) |
| int32_t | cropAndScaleStrategy | Crop and scale strategy. | 0 | [OH_DecodingOptions_GetCropAndScaleStrategy](capi-image-source-native-h.md#oh_decodingoptions_getcropandscalestrategy) | [OH_DecodingOptions_SetCropAndScaleStrategy](capi-image-source-native-h.md#oh_decodingoptions_setcropandscalestrategy) |

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [image_source_native.h](capi-image-source-native-h.md)

**Related Development Guide:** [Image Decoding Using Image_NativeModule](../../media/image/image-source-c.md), [Image Region Decoding and Downsampling (C/C++)](../../media/image/image-region-and-downsampling-c.md), [HDR Image Decoding Using Image_NativeModule](../../media/image/image-hdr-decoding-c.md)