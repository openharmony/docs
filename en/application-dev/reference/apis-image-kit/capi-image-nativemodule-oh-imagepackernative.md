# OH_ImagePackerNative

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=80c0a43cc0af3435c23af3413e3b0da162d4ceb8 translatedAt=2026-08-03T04:00:02.393Z pushedAt=2026-08-04T04:27:58.751Z -->

```c
typedef struct OH_ImagePackerNative OH_ImagePackerNative
```

## Overview

OH_ImagePackerNative is used to encode an ImageSource, PixelMap, Picture, or PixelMap sequence into image data or a file.

Use the [OH_ImagePackerNative_Create](capi-image-packer-native-h.md#oh_imagepackernative_create) function to create an OH_ImagePackerNative object.

Use the [OH_ImagePackerNative_Release](capi-image-packer-native-h.md#oh_imagepackernative_release) function to release an OH_ImagePackerNative object.

Resource management: After OH_ImagePackerNative is used, call [OH_ImagePackerNative_Release](capi-image-packer-native-h.md#oh_imagepackernative_release) to release it. Releasing an OH_ImagePackerNative object does not release the OH_PackingOptions, OH_PackingOptionsForSequence, OH_ImageSourceNative, OH_PixelmapNative, or OH_PictureNative object.

The encoding methods supported by OH_ImagePackerNative are as follows.

| Input Object | Output Location | Encoding Function | Description |
| -- | -- | -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) | Data buffer | [OH_ImagePackerNative_PackToDataFromImageSource](capi-image-packer-native-h.md#oh_imagepackernative_packtodatafromimagesource) | Encodes an ImageSource to data in the specified format. |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) | Data buffer | [OH_ImagePackerNative_PackToDataFromPixelmap](capi-image-packer-native-h.md#oh_imagepackernative_packtodatafrompixelmap) | Encodes a PixelMap to data in the specified format. |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) | Data buffer | [OH_ImagePackerNative_PackToDataFromPicture](capi-image-packer-native-h.md#oh_imagepackernative_packtodatafrompicture) | Encodes a Picture to data in the specified format. Only JPEG and HEIF are supported. |
| OH_PixelmapNative array | Data buffer | [OH_ImagePackerNative_PackToDataFromPixelmapSequence](capi-image-packer-native-h.md#oh_imagepackernative_packtodatafrompixelmapsequence) | Encodes a PixelMap sequence to data in GIF format. |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) | File descriptor | [OH_ImagePackerNative_PackToFileFromImageSource](capi-image-packer-native-h.md#oh_imagepackernative_packtofilefromimagesource) | Encodes an ImageSource to a file. |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) | File descriptor | [OH_ImagePackerNative_PackToFileFromPixelmap](capi-image-packer-native-h.md#oh_imagepackernative_packtofilefrompixelmap) | Encodes a PixelMap to a file. |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) | File descriptor | [OH_ImagePackerNative_PackToFileFromPicture](capi-image-packer-native-h.md#oh_imagepackernative_packtofilefrompicture) | Encodes a Picture to a file. Only JPEG and HEIF are supported. |
| OH_PixelmapNative array | File descriptor | [OH_ImagePackerNative_PackToFileFromPixelmapSequence](capi-image-packer-native-h.md#oh_imagepackernative_packtofilefrompixelmapsequence) | Encodes a PixelMap sequence to GIF format and writes it to a file. |

To obtain the image formats supported for encoding, use the [OH_ImagePackerNative_GetSupportedFormats](capi-image-packer-native-h.md#oh_imagepackernative_getsupportedformats) function.

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [image_packer_native.h](capi-image-packer-native-h.md)