# OH_ImagePackerNative
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The struct describes the image packer, which is used to perform operations related to an image packer.

The struct cannot be directly operated. Instead, its fields must be operated by calling functions. The table below describes the content and operation mode of the OH_ImageNative struct.

| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| OH_ImageSourceNative | imageSource | Image source.| [OH_ImagePackerNative_PackToDataFromImageSource](capi-image-packer-native-h.md#oh_imagepackernative_packtodatafromimagesource) | Encodes an image source into data in a given format.|
|OH_PixelmapNative | pixelmap | PixelMap at the native layer.| [OH_ImagePackerNative_PackToDataFromPixelmap](capi-image-packer-native-h.md#oh_imagepackernative_packtodatafrompixelmap) | Encodes a PixelMap into data in a given format.|
|int32_t | imagesourceFd | File descriptor of an image source.| [OH_ImagePackerNative_PackToFileFromImageSource](capi-image-packer-native-h.md#oh_imagepackernative_packtofilefromimagesource) | Encodes an image source into a file.|
|int32_t | pixelmapFd | File descriptor of a PixelMap.| [OH_ImagePackerNative_PackToFileFromPixelmap](capi-image-packer-native-h.md#oh_imagepackernative_packtofilefrompixelmap) | Encodes a PixelMap into a file.|

To create an OH_ImagePackerNative object, call [OH_ImagePackerNative_Create](capi-image-packer-native-h.md#oh_imagepackernative_create).

To release an OH_ImagePackerNative object, call [OH_ImagePackerNative_Release](capi-image-packer-native-h.md#oh_imagepackernative_release).

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [image_packer_native.h](capi-image-packer-native-h.md)
