# OH_ImageSource_Info

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=79213852c1a278fd2c8d18b1a077b8eb603c4cd5 translatedAt=2026-08-03T03:59:38.715Z pushedAt=2026-08-04T03:57:51.217Z -->

```c
struct OH_ImageSource_Info
```

## Overview

The OH_ImageSource_Info struct describes the image source information encapsulated at the native layer. The struct cannot be directly operated. Instead, functions must be called to create and release the struct and operate the fields in the struct.

Call [OH_ImageSourceInfo_Create](capi-image-source-native-h.md#oh_imagesourceinfo_create) to create an OH_ImageSource_Info object.

Call [OH_ImageSourceNative_GetImageInfo](capi-image-source-native-h.md#oh_imagesourcenative_getimageinfo) to write the image information from OH_ImageSourceNative into the created OH_ImageSource_Info object.

Call [OH_ImageSourceInfo_Release](capi-image-source-native-h.md#oh_imagesourceinfo_release) to release the OH_ImageSource_Info object.

Usage restrictions: The OH_ImageSource_Info object is typically used with [OH_ImageSourceNative_GetImageInfo](capi-image-source-native-h.md#oh_imagesourcenative_getimageinfo) to carry information such as the width, height, dynamic range, and MIME type of a specified image. Before use, create the object through [OH_ImageSourceInfo_Create](capi-image-source-native-h.md#oh_imagesourceinfo_create). After use, call [OH_ImageSourceInfo_Release](capi-image-source-native-h.md#oh_imagesourceinfo_release) to release the object.

The table below describes the content and operation mode of the OH_ImageSource_Info struct.

| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| uint32_t | width | Image width. | [OH_ImageSourceInfo_GetWidth](capi-image-source-native-h.md#oh_imagesourceinfo_getwidth) | Obtains the image width. |
| uint32_t | height | Image height. | [OH_ImageSourceInfo_GetHeight](capi-image-source-native-h.md#oh_imagesourceinfo_getheight) | Obtains the image height. |
| bool | isHdr | Whether the image is High Dynamic Range (HDR). | [OH_ImageSourceInfo_GetDynamicRange](capi-image-source-native-h.md#oh_imagesourceinfo_getdynamicrange) | Obtains whether the image is HDR. |
| [Image_MimeType](capi-image-nativemodule-image-string.md) | mimeType | MIME type of the image source. | [OH_ImageSourceInfo_GetMimeType](./capi-image-source-native-h.md#oh_imagesourceinfo_getmimetype) | Obtains the MIME type of the image. |

> **NOTE**
>
> **mimeType.data** obtained through [OH_ImageSourceInfo_GetMimeType](capi-image-source-native-h.md#oh_imagesourceinfo_getmimetype) points to the memory held internally by the OH_ImageSource_Info object. After [OH_ImageSourceInfo_Release](capi-image-source-native-h.md#oh_imagesourceinfo_release) is called to release OH_ImageSource_Info, this address becomes invalid. If you need to continue using the MIME type data after the release, perform a deep copy before the release.

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [image_source_native.h](capi-image-source-native-h.md)

**Related development guide:** [Using Image_NativeModule for Image Decoding](../../media/image/image-source-c.md), [Image Region Decoding and Downsampling (C/C++)](../../media/image/image-region-and-downsampling-c.md), [Using Image_NativeModule for Animated Image Decoding](../../media/image/image-animated-decoding-c.md), [Using Image_NativeModule for HDR Image Decoding](../../media/image/image-hdr-decoding-c.md)