# OhosImageDecodingOps

## Overview

The OhosImageDecodingOps struct describes the options for decoding an image source. It is used in [OH_ImageSource_CreatePixelMap](capi-image-source-mdk-h.md#oh_imagesource_createpixelmap) and [OH_ImageSource_CreatePixelMapList](capi-image-source-mdk-h.md#oh_imagesource_createpixelmaplist).

**Since**: 10

**Related module**: [Image](capi-image.md)

**Header file**: [image_source_mdk.h](capi-image-source-mdk-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int8_t editable | Whether the output PixelMap is editable.|
| int32_t pixelFormat | Pixel format of the output PixelMap.|
| int32_t fitDensity | Pixel density of the output PixelMap.|
| uint32_t index | Index for decoding the image source.|
| uint32_t sampleSize | Size of the sample.|
| uint32_t rotate | Decoding rotation options.|
| struct [OhosImageSize](capi-image-ohosimagesize.md) size | Pixel width and height of the output PixelMap.|
| struct [OhosImageRegion](capi-image-ohosimageregion.md) region | Pixel range of the decoded image source.|
