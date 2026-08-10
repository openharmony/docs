# OH_PixelmapNative
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

```c
struct OH_PixelmapNative
```

## Overview

OH_PixelmapNative is an uncompressed pixel map format struct encapsulated at the native layer after image decoding. It supports operations such as pixel data read/write, opacity setting, scaling, translation, rotation, flipping, and cropping. It is suitable for scenarios where pixel-level processing and transformation of PixelMaps are required at the native layer.

To create an OH_PixelmapNative object, you need to use the[OH_PixelmapNative_CreatePixelmap](capi-pixelmap-native-h.md#oh_pixelmapnative_createpixelmap) series of functions. If the source pixel format is not specified, these functions parse the source pixel data in the BGRA_8888 format by default. After use, you must call the [OH_PixelmapNative_Release](capi-pixelmap-native-h.md#oh_pixelmapnative_release) function to release the resources. These two operations must be paired; otherwise, memory leaks may occur.

The table below describes some functions and operation modes of the OH_PixelmapNative struct.

| Field Type| Field Name| Field Description| Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| uint8_t | data | Image pixel data. If the source pixel format is not specified, the data is parsed in BGRA_8888 format by default.| [OH_PixelmapNative_ReadPixels](capi-pixelmap-native-h.md#oh_pixelmapnative_readpixels) | Reads pixel data of a PixelMap and writes the result to the buffer.|
| uint8_t | data | Image pixel data. If the source pixel format is not specified, the data is parsed in BGRA_8888 format by default.| [OH_PixelmapNative_WritePixels](capi-pixelmap-native-h.md#oh_pixelmapnative_writepixels) | Writes pixel data from the buffer to a PixelMap.|
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) | imageInfo | Image pixel information.| [OH_PixelmapNative_GetImageInfo](capi-pixelmap-native-h.md#oh_pixelmapnative_getimageinfo) | Obtains the image information of a PixelMap.|
| float | alphaRate | Opacity. The value range is (0.0, 1.0]. The value **1.0** indicates completely opaque.| [OH_PixelmapNative_Opacity](capi-pixelmap-native-h.md#oh_pixelmapnative_opacity) | Sets the opacity to achieve the desired opaque effect for a PixelMap.|
| float, float | scaleX, scaleY | **scaleX** indicates the scaling factor along the X-axis, and **scaleY** indicates the scaling factor along the Y-axis. The value range is (0, +∞), where **1.0** means no scaling.| [OH_PixelmapNative_Scale](capi-pixelmap-native-h.md#oh_pixelmapnative_scale) | Scales a PixelMap based on the input scale factors.|
| float, float | x, y | Horizontal translation offset and vertical translation offset, in pixels (px). A positive **x** value translates the image to the right; a negative **x** value translates it to the left. A positive **y** value translates the image downward; a negative **y** value translates it upward.| [OH_PixelmapNative_Translate](capi-pixelmap-native-h.md#oh_pixelmapnative_translate) | Translates an image by the specified translation distances.|
| float | angle | Rotation angle, in degrees (°). A positive value indicates a clockwise rotation, and a negative value indicates a counterclockwise rotation.|[OH_PixelmapNative_Rotate](capi-pixelmap-native-h.md#oh_pixelmapnative_rotate) | Rotates a PixelMap based on a given angle.|
| bool, bool | shouldFlipHorizontally, shouldFlipVertically | Whether the PixelMap is flipped horizontally or vertically. **true** indicates yes, and **false** indicates no.| [OH_PixelmapNative_Flip](capi-pixelmap-native-h.md#oh_pixelmapnative_flip) | Flips an image based on the specified horizontal or vertical flip flag.|
| [Image_Region](capi-image-nativemodule-image-region.md) | region | Crop region, including the starting coordinates (x, y) and the width and height. The width and height must be positive values, and the crop region must be within the image bounds. For details, see [Image_Region](capi-image-nativemodule-image-region.md).| [OH_PixelmapNative_Crop](capi-pixelmap-native-h.md#oh_pixelmapnative_crop) | Crops a PixelMap based on the input region information.|

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [pixelmap_native.h](capi-pixelmap-native-h.md)
