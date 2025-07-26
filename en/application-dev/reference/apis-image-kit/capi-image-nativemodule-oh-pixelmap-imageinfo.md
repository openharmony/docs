# OH_Pixelmap_ImageInfo

## Overview

The OH_Pixelmap_ImageInfo struct describes the image information encapsulated at the native layer. The struct stores the width, height, row stride, pixel format, and HDR of an image.

To create an OH_Pixelmap_ImageInfo object, call [OH_PixelmapImageInfo_Create](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_create).

To release an OH_Pixelmap_ImageInfo object, call [OH_PixelmapImageInfo_Release](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_release).

The table below describes the content and operation mode of the OH_Pixelmap_ImageInfo struct.

| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| uint32_t | width | Image width.| [OH_PixelmapImageInfo_GetWidth](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getwidth) | Obtains the image width.|
| uint32_t | height | Image height.| [OH_PixelmapImageInfo_GetHeight](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getheight) | Obtains the image height.|
| uint32_t | rowStride | Row stride.| [OH_PixelmapImageInfo_GetRowStride](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getrowstride) | Obtains the row stride.|
| int32_t | pixelFormat| Pixel format.| [OH_PixelmapImageInfo_GetPixelFormat](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getpixelformat) |Obtains the pixel format.|
| int32_t | alphaType | Alpha type.| [OH_PixelmapImageInfo_GetAlphaType](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getalphatype) |Obtains the alpha type.|
| bool | isHdr | Dynamic range.| [OH_PixelmapImageInfo_GetDynamicRange](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getdynamicrange) |Obtains the dynamic range of a PixelMap.|

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [pixelmap_native.h](capi-pixelmap-native-h.md)
