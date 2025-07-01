# OH_PixelmapNative

## Overview

The OH_PixelmapNative struct describes an uncompressed PixelMap format, which is encapsulated at the native layer after images are decoded.

To create an OH_PixelmapNative object, call [OH_PixelmapNative_CreatePixelmap](capi-pixelmap-native-h.md#oh_pixelmapnative_createpixelmap). By default, BGRA_8888 is used for data processing.

To release an OH_PixelmapNative object, call [OH_PixelmapNative_Release](capi-pixelmap-native-h.md#oh_pixelmapnative_release).

The table below describes the content and operation mode of the OH_PixelmapNative struct.

| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| uint8_t | data | Image pixel data.| [OH_PixelmapNative_ReadPixels](capi-pixelmap-native-h.md#oh_pixelmapnative_readpixels) | Reads the pixels of a PixelMap and writes the result to an ArrayBuffer.|
| uint8_t | data | Image pixel data.| [OH_PixelmapNative_WritePixels](capi-pixelmap-native-h.md#oh_pixelmapnative_writepixels) | Reads the pixel data in the buffer and writes the result to a PixelMap.|
| OH_Pixelmap_ImageInfo | imageInfo | Image information.| [OH_PixelmapNative_GetImageInfo](capi-pixelmap-native-h.md#oh_pixelmapnative_getimageinfo) | Obtains the image information of a PixelMap.|
| float | alphaRate | Opacity.| [OH_PixelmapNative_Opacity](capi-pixelmap-native-h.md#oh_pixelmapnative_opacity) | Sets the opacity rate to enable the PixelMap to achieve the corresponding opacity effect.|
|float, float, | scaleX, scaleY | Scale ratios along the X axis and Y axis, respectively.|[OH_PixelmapNative_Scale](capi-pixelmap-native-h.md#oh_pixelmapnative_scale) | Scales a PixelMap based on a given width and height.|
| float, float| x, y | Distances to translate along the X axis and Y axis, respectively.| [OH_PixelmapNative_Translate](capi-pixelmap-native-h.md#oh_pixelmapnative_translate) | Translates a PixelMap based on given coordinates.|
| float | angle | Rotation angle.|[OH_PixelmapNative_Rotate](capi-pixelmap-native-h.md#oh_pixelmapnative_rotate) | Rotates a PixelMap based on a given angle.|
| bool, bool | shouldFilpHorizontally, shouldFilpVertically | Whether to flip horizontally or vertically.| [OH_PixelmapNative_Flip](capi-pixelmap-native-h.md#oh_pixelmapnative_flip) | Flips a PixelMap based on a given angle.|
| Image_Region | region | Cropping region.| [OH_PixelmapNative_Crop](capi-pixelmap-native-h.md#oh_pixelmapnative_crop) | Crops a PixelMap based on a given size.|

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [pixelmap_native.h](capi-pixelmap-native-h.md)
