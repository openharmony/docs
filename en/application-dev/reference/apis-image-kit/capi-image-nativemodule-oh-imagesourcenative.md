# OH_ImageSourceNative

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=79213852c1a278fd2c8d18b1a077b8eb603c4cd5 translatedAt=2026-08-03T04:01:36.933Z pushedAt=2026-08-04T04:35:54.012Z -->

```c
struct OH_ImageSourceNative
```

## Overview

The struct describes the image source, which is encapsulated at the native layer and is used to create image data. The struct cannot be directly operated. Instead, functions must be called to create and release the struct and operate the fields in the struct.

You can create an OH_ImageSourceNative object in multiple ways, as described below.

| API| Description|
| -------- | -------- |
| [OH_ImageSourceNative_CreateFromUri](capi-image-source-native-h.md#oh_imagesourcenative_createfromuri) |Creates an OH_ImageSourceNative object based on a URI.|
| [OH_ImageSourceNative_CreateFromFd](capi-image-source-native-h.md#oh_imagesourcenative_createfromfd) |Creates an OH_ImageSourceNative object based on a file descriptor.|
| [OH_ImageSourceNative_CreateFromData](capi-image-source-native-h.md#oh_imagesourcenative_createfromdata) |Creates an OH_ImageSourceNative object based on buffer data.|
| [OH_ImageSourceNative_CreateFromDataWithUserBuffer](capi-image-source-native-h.md#oh_imagesourcenative_createfromdatawithuserbuffer) |Creates an OH_ImageSourceNative object based on the data buffer passed in by the caller, without copying the data buffer during creation.|
| [OH_ImageSourceNative_CreateFromRawFile](capi-image-source-native-h.md#oh_imagesourcenative_createfromrawfile) |Creates an OH_ImageSourceNative object by using the raw file descriptor of an image resource file.|

Release an OH_ImageSourceNative object using [OH_ImageSourceNative_Release](capi-image-source-native-h.md#oh_imagesourcenative_release).

Usage restrictions: Before an OH_ImageSourceNative object is used, it must first be created through the preceding API. After use, [OH_ImageSourceNative_Release](capi-image-source-native-h.md#oh_imagesourcenative_release) must be called to release the object. When an object is created through [OH_ImageSourceNative_CreateFromDataWithUserBuffer](capi-image-source-native-h.md#oh_imagesourcenative_createfromdatawithuserbuffer), the data buffer passed in by the caller must remain valid throughout the lifecycle of the OH_ImageSourceNative object and must not be released, reused, or modified into other image data.

Resource management: The [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md), [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md), and [OH_ImageRawData](capi-image-nativemodule-oh-imagerawdata.md) objects decoded or obtained through OH_ImageSourceNative are managed separately by the caller. Releasing an OH_ImageSourceNative object does not automatically release these objects; the corresponding APIs must be called to release or destroy them.

The table below describes the content and operation mode of the OH_ImageSourceNative struct.

| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| int32_t | delayTimeList | Image delay time array. | [OH_ImageSourceNative_GetDelayTimeList](capi-image-source-native-h.md#oh_imagesourcenative_getdelaytimelist) | Obtains the image delay time array. |
| OH_ImageSource_Info | info | ImageSource information. | [OH_ImageSourceNative_GetImageInfo](capi-image-source-native-h.md#oh_imagesourcenative_getimageinfo) | Obtains the image information at the specified index. |
| Image_String | value | Image property value. | [OH_ImageSourceNative_GetImageProperty](capi-image-source-native-h.md#oh_imagesourcenative_getimageproperty) | Obtains the value of the specified Exif property key of the image. |
| Image_String | value | Image property value. | [OH_ImageSourceNative_ModifyImageProperty](capi-image-source-native-h.md#oh_imagesourcenative_modifyimageproperty) | Modifies the value of the specified Exif property key of the image. |
| uint32_t | frameCount | Frame count of the image. | [OH_ImageSourceNative_GetFrameCount](capi-image-source-native-h.md#oh_imagesourcenative_getframecount) | Obtains the frame count of the image. |

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [image_source_native.h](capi-image-source-native-h.md)

**Related development guides:** [Image Decoding Using Image_NativeModule](../../media/image/image-source-c.md), [Image Region Decoding and Downsampling (C/C++)](../../media/image/image-region-and-downsampling-c.md), [Animated Image Decoding Using Image_NativeModule](../../media/image/image-animated-decoding-c.md), [HDR Image Decoding Using Image_NativeModule](../../media/image/image-hdr-decoding-c.md), [Multi-Image Object Decoding Using Image_NativeModule](../../media/image/image-source-picture-c.md)