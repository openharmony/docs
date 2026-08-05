# OH_AuxiliaryPictureNative

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=79213852c1a278fd2c8d18b1a077b8eb603c4cd5 translatedAt=2026-08-03T03:58:59.074Z pushedAt=2026-08-04T04:04:44.729Z -->

```c
typedef struct OH_AuxiliaryPictureNative OH_AuxiliaryPictureNative
```

## Overview

The struct describes the auxiliary picture, which is used to perform operations related to the auxiliary picture.

Creates an OH_AuxiliaryPictureNative object using the [OH_AuxiliaryPictureNative_Create](capi-picture-native-h.md#oh_auxiliarypicturenative_create) function.

Obtains an OH_AuxiliaryPictureNative object from an OH_PictureNative object by auxiliary picture type using the [OH_PictureNative_GetAuxiliaryPicture](capi-picture-native-h.md#oh_picturenative_getauxiliarypicture) function.

Releases an OH_AuxiliaryPictureNative object using the [OH_AuxiliaryPictureNative_Release](capi-picture-native-h.md#oh_auxiliarypicturenative_release) function.

Usage restrictions: Before using an OH_AuxiliaryPictureNative object, you must first create or obtain the object. After use, call [OH_AuxiliaryPictureNative_Release](capi-picture-native-h.md#oh_auxiliarypicturenative_release) to release the object. When creating an object using [OH_AuxiliaryPictureNative_Create](capi-picture-native-h.md#oh_auxiliarypicturenative_create), **data**, **size**, and **auxiliaryPicture** must not be null pointers, **dataLength** must be greater than 0, and **type** must be a currently supported [Image_AuxiliaryPictureType](capi-picture-native-h.md#image_auxiliarypicturetype).

Resource management: Releasing an OH_PictureNative object does not automatically release the OH_AuxiliaryPictureNative object obtained from it. Releasing an OH_AuxiliaryPictureNative object does not remove the corresponding auxiliary picture from the OH_PictureNative object. The OH_AuxiliaryPictureInfo object obtained through [OH_AuxiliaryPictureNative_GetInfo](capi-picture-native-h.md#oh_auxiliarypicturenative_getinfo) is managed by the caller and must be released by calling [OH_AuxiliaryPictureInfo_Release](capi-picture-native-h.md#oh_auxiliarypictureinfo_release) after use. The OH_PictureMetadata object obtained through [OH_AuxiliaryPictureNative_GetMetadata](capi-picture-native-h.md#oh_auxiliarypicturenative_getmetadata) is managed by the caller and must be released by calling [OH_PictureMetadata_Release](capi-image-common-h.md#oh_picturemetadata_release) after use. If an API call fails, the content of the output parameters must not be used in subsequent processes.

The following describes the content and operations of the OH_AuxiliaryPictureNative struct.

| Field Type | Field Name | Field Description | Operation Function | Function Description |
| -------- | -------- | -------- | -------- | -------- |
| uint8_t | pixels | Auxiliary picture pixel data. | [OH_AuxiliaryPictureNative_ReadPixels](capi-picture-native-h.md#oh_auxiliarypicturenative_readpixels) | Reads the pixel data of the auxiliary picture. |
| uint8_t | pixels | Auxiliary picture pixel data. | [OH_AuxiliaryPictureNative_WritePixels](capi-picture-native-h.md#oh_auxiliarypicturenative_writepixels) | Writes pixel data to the auxiliary picture. |
| [Image_AuxiliaryPictureType](capi-picture-native-h.md#image_auxiliarypicturetype) | type | Auxiliary picture type. | [OH_AuxiliaryPictureNative_GetType](capi-picture-native-h.md#oh_auxiliarypicturenative_gettype) | Obtains the auxiliary picture type. |
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) | info | Auxiliary picture information. | [OH_AuxiliaryPictureNative_GetInfo](capi-picture-native-h.md#oh_auxiliarypicturenative_getinfo) | Obtains the auxiliary picture information. |
| [OH_AuxiliaryPictureInfo](capi-image-nativemodule-oh-auxiliarypictureinfo.md) | info | Auxiliary picture information. | [OH_AuxiliaryPictureNative_SetInfo](capi-picture-native-h.md#oh_auxiliarypicturenative_setinfo) | Sets the auxiliary picture information. |
| [OH_PictureMetadata](capi-image-nativemodule-oh-picturemetadata.md) | metadata | Auxiliary picture metadata. | [OH_AuxiliaryPictureNative_GetMetadata](capi-picture-native-h.md#oh_auxiliarypicturenative_getmetadata) | Obtains the metadata of the auxiliary picture. |
| [OH_PictureMetadata](capi-image-nativemodule-oh-picturemetadata.md) | metadata | Auxiliary picture metadata. | [OH_AuxiliaryPictureNative_SetMetadata](capi-picture-native-h.md#oh_auxiliarypicturenative_setmetadata) | Sets the metadata of the auxiliary picture. |

**Since**: 13

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [picture_native.h](capi-picture-native-h.md)

**Related development guide:** [Decoding Multi-Image Objects Using Image_NativeModule](../../media/image/image-source-picture-c.md)