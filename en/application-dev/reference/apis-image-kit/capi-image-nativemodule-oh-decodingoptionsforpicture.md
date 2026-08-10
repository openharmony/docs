# OH_DecodingOptionsForPicture

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=79213852c1a278fd2c8d18b1a077b8eb603c4cd5 translatedAt=2026-08-03T03:59:51.783Z pushedAt=2026-08-04T04:25:07.666Z -->

```c
struct OH_DecodingOptionsForPicture
```

## Overview

Picture decoding options struct.

Create an OH_DecodingOptionsForPicture object using the [OH_DecodingOptionsForPicture_Create](capi-image-source-native-h.md#oh_decodingoptionsforpicture_create) function.

Release an OH_DecodingOptionsForPicture object using the [OH_DecodingOptionsForPicture_Release](capi-image-source-native-h.md#oh_decodingoptionsforpicture_release) function.

Resource management: Releasing an OH_ImageSourceNative object or a decoded OH_PictureNative object does not automatically release the OH_DecodingOptionsForPicture object. After an OH_DecodingOptionsForPicture object is released, it should not be passed to Picture decoding APIs or used to call its field getter and setter APIs.

The content and operations of the OH_DecodingOptionsForPicture struct are as follows.

| Field Type | Field Name | Field Description | Default Value | Field Getter Function | Field Setter Function |
| -------- | -------- | -------- | -------- | -------- | -------- |
| [Image_AuxiliaryPictureType](capi-picture-native-h.md#image_auxiliarypicturetype) array | desiredAuxiliaryPictures | Types of auxiliary pictures expected to be included in the Picture decoding result. It can be used to decode only the auxiliary pictures required by the caller, such as gain maps and depth maps. | Empty set, meaning no auxiliary picture type is specified. When decoding a Picture, all supported auxiliary picture types are processed. | [OH_DecodingOptionsForPicture_GetDesiredAuxiliaryPictures](capi-image-source-native-h.md#oh_decodingoptionsforpicture_getdesiredauxiliarypictures) | [OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures](capi-image-source-native-h.md#oh_decodingoptionsforpicture_setdesiredauxiliarypictures) |

**Since**: 13

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [image_source_native.h](capi-image-source-native-h.md)

**Related development guide:** [Decoding Multi-Image Objects Using Image_NativeModule](../../media/image/image-source-picture-c.md)