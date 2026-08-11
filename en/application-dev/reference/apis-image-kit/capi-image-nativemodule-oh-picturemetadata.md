# OH_PictureMetadata

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=79213852c1a278fd2c8d18b1a077b8eb603c4cd5 translatedAt=2026-08-03T04:01:06.742Z pushedAt=2026-08-04T04:38:04.392Z -->

```c
typedef struct OH_PictureMetadata OH_PictureMetadata
```

## Overview

OH_PictureMetadata is used to carry picture metadata.

There are multiple ways to create and obtain OH_PictureMetadata.

| Function | Description |
| -- | -- |
| [OH_PictureMetadata_Create()](capi-image-common-h.md#oh_picturemetadata_create) | Creates an OH_PictureMetadata pointer. |
| [OH_PictureMetadata_Clone()](capi-image-common-h.md#oh_picturemetadata_clone) | Copies the metadata. |
| [OH_PictureNative_GetMetadata()](capi-picture-native-h.md#oh_picturenative_getmetadata) | Obtains the metadata of the main image. |
| [OH_AuxiliaryPictureNative_GetMetadata()](capi-picture-native-h.md#oh_auxiliarypicturenative_getmetadata) | Obtains the metadata of the auxiliary picture. |

Use the [OH_PictureMetadata_Release()](capi-image-common-h.md#oh_picturemetadata_release) function to release the OH_PictureMetadata object.

Resource management: The OH_PictureMetadata object obtained through [OH_PictureMetadata_Create()](capi-image-common-h.md#oh_picturemetadata_create), [OH_PictureMetadata_Clone()](capi-image-common-h.md#oh_picturemetadata_clone), [OH_PictureNative_GetMetadata()](capi-picture-native-h.md#oh_picturenative_getmetadata), or [OH_AuxiliaryPictureNative_GetMetadata()](capi-picture-native-h.md#oh_auxiliarypicturenative_getmetadata) is managed by the caller. After use, call [OH_PictureMetadata_Release()](capi-image-common-h.md#oh_picturemetadata_release) to release it. When setting metadata through [OH_PictureNative_SetMetadata()](capi-picture-native-h.md#oh_picturenative_setmetadata) or [OH_AuxiliaryPictureNative_SetMetadata()](capi-picture-native-h.md#oh_auxiliarypicturenative_setmetadata), the API does not release the passed-in OH_PictureMetadata object.

The content and operation methods of the OH_PictureMetadata struct are as follows.

| Field Type | Field Name | Field Description | Field Getter Function| Field Setter Function|
| -- | -- | -- | -- | -- |
| [Image_String](capi-image-nativemodule-image-string.md) | property | Metadata property. | [OH_PictureMetadata_GetProperty()](capi-image-common-h.md#oh_picturemetadata_getproperty), [OH_PictureMetadata_GetPropertyWithNull()](capi-image-common-h.md#oh_picturemetadata_getpropertywithnull) | [OH_PictureMetadata_SetProperty()](capi-image-common-h.md#oh_picturemetadata_setproperty) |
| OH_PictureMetadata | metadata | Copy of the metadata object. | [OH_PictureMetadata_Clone()](capi-image-common-h.md#oh_picturemetadata_clone) | - |

**Since**: 13

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [image_common.h](capi-image-common-h.md)