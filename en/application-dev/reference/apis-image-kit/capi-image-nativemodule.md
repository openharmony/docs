# Image_NativeModule
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The module provides image processing capabilities, including encoding and decoding an image and obtaining image data from the native layer.

The APIs of this module do not need to be imported through the JS interface. You can directly use the NDK to develop the features.

You can refer to the corresponding development guide and samples based on your development requirements.

- [Using Image_NativeModule to Decode Images](../../media/image/image-source-c.md)
- [Using Image_NativeModule to Decode Pictures](../../media/image/image-source-picture-c.md)
- [Using Image_NativeModule to Receive Images](../../media/image/image-receiver-c.md)
- [Using Image_NativeModule for PixelMap Operations](../../media/image/pixelmap-c.md)
- [Using Image_NativeModule to Process Image Information](../../media/image/image-info-c.md)
- [Using Image_NativeModule to Encode Images](../../media/image/image-packer-c.md)
- [Using Image_NativeModule to Encode Pictures](../../media/image/image-packer-picture-c.md)

**Since**: 12

## Files

| Name| Description|
| -- | -- |
| [image_common.h](capi-image-common-h.md) | Declares the common enums and structs used by the image interface.|
| [image_native.h](capi-image-native-h.md) | Declares the cropping rectangle, size, and component data of an image.|
| [image_packer_native.h](capi-image-packer-native-h.md) | Declares the APIs for image encoding.|
| [image_receiver_native.h](capi-image-receiver-native-h.md) | Declares the APIs used to obtain image data from the native layer.|
| [image_source_native.h](capi-image-source-native-h.md) | Declares the APIs for image decoding.|
| [picture_native.h](capi-picture-native-h.md) | Declares the APIs for obtaining picture data and information.|
| [pixelmap_native.h](capi-pixelmap-native-h.md) | Declares the APIs for accessing a PixelMap.|
