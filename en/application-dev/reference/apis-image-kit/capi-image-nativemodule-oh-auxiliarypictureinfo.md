# OH_AuxiliaryPictureInfo

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=62b603516ed3ce38013bf9e5d7a53acbe102d55f translatedAt=2026-08-03T03:58:37.889Z pushedAt=2026-08-04T04:20:06.677Z -->

```c
typedef struct OH_AuxiliaryPictureInfo OH_AuxiliaryPictureInfo
```

## Overview

The struct describes the auxiliary picture information, which is used to perform operations related to the auxiliary picture information.

Use the [OH_AuxiliaryPictureInfo_Create](capi-picture-native-h.md#oh_auxiliarypictureinfo_create) function to create an OH_AuxiliaryPictureInfo object.

Use the [OH_AuxiliaryPictureNative_GetInfo](capi-picture-native-h.md#oh_auxiliarypicturenative_getinfo) function to obtain an OH_AuxiliaryPictureInfo object from an OH_AuxiliaryPictureNative object.

Use the [OH_AuxiliaryPictureInfo_Release](capi-picture-native-h.md#oh_auxiliarypictureinfo_release) function to release an OH_AuxiliaryPictureInfo object.

Usage restrictions: Before using an OH_AuxiliaryPictureInfo object, you must first create or obtain the object. After use, call [OH_AuxiliaryPictureInfo_Release](capi-picture-native-h.md#oh_auxiliarypictureinfo_release) to release the object. When calling [OH_AuxiliaryPictureInfo_GetType](capi-picture-native-h.md#oh_auxiliarypictureinfo_gettype), [OH_AuxiliaryPictureInfo_GetSize](capi-picture-native-h.md#oh_auxiliarypictureinfo_getsize), [OH_AuxiliaryPictureInfo_GetRowStride](capi-picture-native-h.md#oh_auxiliarypictureinfo_getrowstride), or [OH_AuxiliaryPictureInfo_GetPixelFormat](capi-picture-native-h.md#oh_auxiliarypictureinfo_getpixelformat), nullptr must not be passed to the output parameters. If the API call fails, the content of the output parameters must not be used in subsequent processes. Manually set OH_AuxiliaryPictureInfo only when the actual state of the auxiliary picture is inconsistent with the OH_AuxiliaryPictureInfo object information, or when there is a clear business requirement to do so.

Resource management: The OH_AuxiliaryPictureInfo object returned successfully by [OH_AuxiliaryPictureNative_GetInfo](capi-picture-native-h.md#oh_auxiliarypicturenative_getinfo) is managed by the caller. When setting auxiliary picture information through [OH_AuxiliaryPictureNative_SetInfo](capi-picture-native-h.md#oh_auxiliarypicturenative_setinfo), the API reads and saves the information values from OH_AuxiliaryPictureInfo. After the API returns, the caller is still responsible for managing the lifecycle of the OH_AuxiliaryPictureInfo object.

The content and operation methods of the OH_AuxiliaryPictureInfo struct are as follows.

| Type | Name | Description | Getter Function | Setter Function |
| -------- | -------- | -------- | -------- | -------- |
| [Image_AuxiliaryPictureType](capi-picture-native-h.md#image_auxiliarypicturetype) | type | Auxiliary picture type. | [OH_AuxiliaryPictureInfo_GetType](capi-picture-native-h.md#oh_auxiliarypictureinfo_gettype) | [OH_AuxiliaryPictureInfo_SetType](capi-picture-native-h.md#oh_auxiliarypictureinfo_settype) |
| [Image_Size](capi-image-nativemodule-image-size.md) | size | Auxiliary picture size. | [OH_AuxiliaryPictureInfo_GetSize](capi-picture-native-h.md#oh_auxiliarypictureinfo_getsize) | [OH_AuxiliaryPictureInfo_SetSize](capi-picture-native-h.md#oh_auxiliarypictureinfo_setsize) |
| uint32_t | rowStride | Row stride, which is the space occupied by each row of pixels in memory. | [OH_AuxiliaryPictureInfo_GetRowStride](capi-picture-native-h.md#oh_auxiliarypictureinfo_getrowstride) | [OH_AuxiliaryPictureInfo_SetRowStride](capi-picture-native-h.md#oh_auxiliarypictureinfo_setrowstride) |
| [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format) | pixelFormat | Pixel format. | [OH_AuxiliaryPictureInfo_GetPixelFormat](capi-picture-native-h.md#oh_auxiliarypictureinfo_getpixelformat) | [OH_AuxiliaryPictureInfo_SetPixelFormat](capi-picture-native-h.md#oh_auxiliarypictureinfo_setpixelformat) |

**Since**: 13

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [picture_native.h](capi-picture-native-h.md)

**Related development guide:** [Decoding Multi-Image Objects Using Image_NativeModule](../../media/image/image-source-picture-c.md)