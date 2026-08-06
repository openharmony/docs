# OH_PackingOptions

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=80c0a43cc0af3435c23af3413e3b0da162d4ceb8 translatedAt=2026-08-03T04:01:09.107Z pushedAt=2026-08-04T07:04:59.713Z -->

```c
typedef struct OH_PackingOptions OH_PackingOptions
```

## Overview

OH_PackingOptions is an image encoding option struct encapsulated at the native layer. It cannot be manipulated directly; instead, functions shall be called to create and release the struct, and operate on its specific fields.

To create an OH_PackingOptions object, call [OH_PackingOptions_Create](capi-image-packer-native-h.md#oh_packingoptions_create).

To release an OH_PackingOptions object, call [OH_PackingOptions_Release](capi-image-packer-native-h.md#oh_packingoptions_release).

Usage restrictions: OH_PackingOptions is used to configure encoding parameters for ImageSource, PixelMap, or Picture.

- For ImageSource encoding, pass it to [OH_ImagePackerNative_PackToDataFromImageSource](capi-image-packer-native-h.md#oh_imagepackernative_packtodatafromimagesource) or [OH_ImagePackerNative_PackToFileFromImageSource](capi-image-packer-native-h.md#oh_imagepackernative_packtofilefromimagesource).

- For PixelMap encoding, pass it to [OH_ImagePackerNative_PackToDataFromPixelmap](capi-image-packer-native-h.md#oh_imagepackernative_packtodatafrompixelmap) or [OH_ImagePackerNative_PackToFileFromPixelmap](capi-image-packer-native-h.md#oh_imagepackernative_packtofilefrompixelmap).

- For Picture encoding, pass it to [OH_ImagePackerNative_PackToDataFromPicture](capi-image-packer-native-h.md#oh_imagepackernative_packtodatafrompicture) or [OH_ImagePackerNative_PackToFileFromPicture](capi-image-packer-native-h.md#oh_imagepackernative_packtofilefrompicture).

- For PixelMap sequence encoding, use [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md).

Resource management: Releasing an OH_ImagePackerNative object does not automatically release the OH_PackingOptions object. After OH_PackingOptions is no longer needed, call [OH_PackingOptions_Release](capi-image-packer-native-h.md#oh_packingoptions_release) to release it. Once released, it must not be passed to image encoding APIs or used with its field getter and setter functions.

The table below describes the content and operation mode of the OH_PackingOptions struct.

| Field Type | Field Name | Field Description | Field Getter Function | Field Setter Function |
| -- | -- | -- | -- | -- |
| [Image_MimeType](capi-image-nativemodule-image-string.md) | mimeType | MIME type of the target encoding format. ImageSource or PixelMap encoding supports `image/jpeg`, `image/webp`, `image/png`, `image/heic` or `image/heif`, `image/sdr_astc_4x4`, `image/sdr_sut_superfast_4x4`, and `image/hdr_astc_4x4`; Picture encoding supports `image/jpeg`, `image/heic` or `image/heif`. The actual supported range is subject to the result returned by [OH_ImagePackerNative_GetSupportedFormats](capi-image-packer-native-h.md#oh_imagepackernative_getsupportedformats). | [OH_PackingOptions_GetMimeType](capi-image-packer-native-h.md#oh_packingoptions_getmimetype), [OH_PackingOptions_GetMimeTypeWithNull](capi-image-packer-native-h.md#oh_packingoptions_getmimetypewithnull) | [OH_PackingOptions_SetMimeType](capi-image-packer-native-h.md#oh_packingoptions_setmimetype) |
| uint32_t | quality | Encoding quality. The actual encoding effect depends on the target encoding format. | [OH_PackingOptions_GetQuality](capi-image-packer-native-h.md#oh_packingoptions_getquality) | [OH_PackingOptions_SetQuality](capi-image-packer-native-h.md#oh_packingoptions_setquality) |
| bool | needsPackProperties | Whether to encode image properties, such as Exif. | [OH_PackingOptions_GetNeedsPackProperties](capi-image-packer-native-h.md#oh_packingoptions_getneedspackproperties) | [OH_PackingOptions_SetNeedsPackProperties](capi-image-packer-native-h.md#oh_packingoptions_setneedspackproperties) |
| int32_t | desiredDynamicRange | Desired image dynamic range during encoding. For details about the values, see [IMAGE_PACKER_DYNAMIC_RANGE](capi-image-packer-native-h.md#image_packer_dynamic_range). | [OH_PackingOptions_GetDesiredDynamicRange](capi-image-packer-native-h.md#oh_packingoptions_getdesireddynamicrange) | [OH_PackingOptions_SetDesiredDynamicRange](capi-image-packer-native-h.md#oh_packingoptions_setdesireddynamicrange) |

> **NOTE**
>
> - When setting the MIME type via [OH_PackingOptions_SetMimeType](capi-image-packer-native-h.md#oh_packingoptions_setmimetype), the API copies the passed **format->data** and does not hold the data pointer passed by the caller.
> - When obtaining the MIME type via [OH_PackingOptions_GetMimeType](capi-image-packer-native-h.md#oh_packingoptions_getmimetype) or [OH_PackingOptions_GetMimeTypeWithNull](capi-image-packer-native-h.md#oh_packingoptions_getmimetypewithnull), **format.data** returned on success is allocated by the API, and the caller should use **free()** to release it after use.

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [image_packer_native.h](capi-image-packer-native-h.md)