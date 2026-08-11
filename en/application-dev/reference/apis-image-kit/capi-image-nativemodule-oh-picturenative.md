# OH_PictureNative

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=79213852c1a278fd2c8d18b1a077b8eb603c4cd5 translatedAt=2026-08-03T04:02:02.565Z pushedAt=2026-08-04T06:56:31.454Z -->

```c
struct OH_PictureNative
```

## Overview

The struct is used to perform operations related to the picture.

Picture is an object that includes a main picture, auxiliary picture, and metadata.

The main picture contains most information about the image and is mainly used to render the image.

The auxiliary picture is used to store data related to but different from the main picture, revealing more comprehensive details.

The metadata is generally used to store information about the image file.

There are multiple ways to create an OH_PictureNative object, as described below.

| Function | Description |
| -------- | -------- |
| [OH_ImageSourceNative_CreatePicture](capi-image-source-native-h.md#oh_imagesourcenative_createpicture) | Creates an OH_PictureNative object through image decoding. |
| [OH_ImageSourceNative_CreatePictureAtIndex](capi-image-source-native-h.md#oh_imagesourcenative_createpictureatindex) | Creates an OH_PictureNative object by decoding the image at a specified index. |
| [OH_PictureNative_CreatePicture](capi-picture-native-h.md#oh_picturenative_createpicture) | Creates an OH_PictureNative object based on the main picture OH_PixelmapNative object. |

Use the [OH_PictureNative_Release](capi-picture-native-h.md#oh_picturenative_release) function to release the OH_PictureNative object.

Usage restrictions: Before using an OH_PictureNative object, you must create the object first. After use, you must call [OH_PictureNative_Release](capi-picture-native-h.md#oh_picturenative_release) to release the object. When decoding a Picture through [OH_ImageSourceNative_CreatePicture](capi-image-source-native-h.md#oh_imagesourcenative_createpicture) or [OH_ImageSourceNative_CreatePictureAtIndex](capi-image-source-native-h.md#oh_imagesourcenative_createpictureatindex), the image source format must support Picture decoding. When creating a Picture through [OH_PictureNative_CreatePicture](capi-picture-native-h.md#oh_picturenative_createpicture), neither **mainPixelmap** nor **picture** can be a null pointer.

Resource management: Releasing the OH_ImageSourceNative object does not automatically release the created OH_PictureNative object. The OH_PixelmapNative, OH_AuxiliaryPictureNative, and OH_PictureMetadata objects obtained through OH_PictureNative are managed by the caller. After use, you must call [OH_PixelmapNative_Destroy](capi-pixelmap-native-h.md#oh_pixelmapnative_destroy), [OH_AuxiliaryPictureNative_Release](capi-picture-native-h.md#oh_auxiliarypicturenative_release), and [OH_PictureMetadata_Release](capi-image-common-h.md#oh_picturemetadata_release) to release them, respectively. If the API for obtaining a PixelMap, auxiliary picture, or metadata fails, the content of the output parameter must not be used in subsequent processes.

The fields and operations of the OH_PictureNative struct are as follows:

| Field Type | Field Name | Field Description | Function | Function Description |
| -------- | -------- | -------- | -------- | -------- |
| OH_PixelmapNative | mainPixelmap | Main picture of the Picture. | [OH_PictureNative_GetMainPixelmap](capi-picture-native-h.md#oh_picturenative_getmainpixelmap) | Obtains the OH_PixelmapNative object of the main picture. |
| OH_PixelmapNative | hdrPixelmap | HDR composite image. | [OH_PictureNative_GetHdrComposedPixelmap](capi-picture-native-h.md#oh_picturenative_gethdrcomposedpixelmap) | Obtains the OH_PixelmapNative object after HDR composition. |
| OH_PixelmapNative | hdrPixelmap | HDR composite image. | [OH_PictureNative_GetHdrComposedPixelmapWithOptions](capi-picture-native-h.md#oh_picturenative_gethdrcomposedpixelmapwithoptions) | Obtains the OH_PixelmapNative object after HDR composition based on the OH_ComposeOptions configuration. |
| OH_PixelmapNative | gainmapPixelmap | Gain map. | [OH_PictureNative_GetGainmapPixelmap](capi-picture-native-h.md#oh_picturenative_getgainmappixelmap) | Obtains the OH_PixelmapNative object of the gain map. |
| OH_AuxiliaryPictureNative | auxiliaryPicture | Auxiliary picture. | [OH_PictureNative_SetAuxiliaryPicture](capi-picture-native-h.md#oh_picturenative_setauxiliarypicture) | Sets the auxiliary picture. |
| OH_AuxiliaryPictureNative | auxiliaryPicture | Auxiliary picture. | [OH_PictureNative_GetAuxiliaryPicture](capi-picture-native-h.md#oh_picturenative_getauxiliarypicture) | Obtains the auxiliary picture by type. |
| OH_PictureMetadata | metadata | Main picture metadata. | [OH_PictureNative_GetMetadata](capi-picture-native-h.md#oh_picturenative_getmetadata) | Obtains the metadata of the main picture. |
| OH_PictureMetadata | metadata | Main picture metadata. | [OH_PictureNative_SetMetadata](capi-picture-native-h.md#oh_picturenative_setmetadata) | Sets the metadata of the main picture. |

**Since**: 13

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [picture_native.h](capi-picture-native-h.md)

**Related development guide:** [Using Image_NativeModule to Decode Multi-Image Objects](../../media/image/image-source-picture-c.md)