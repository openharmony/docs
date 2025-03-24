# OhosImageDecodingOps


## Overview

The **OhosImageDecodingOps** struct defines the options for decoding an image source. It is used in [OH_ImageSource_CreatePixelMap](image.md#oh_imagesource_createpixelmap) and [OH_ImageSource_CreatePixelMapList](image.md#oh_imagesource_createpixelmaplist).

**System capability**: SystemCapability.Multimedia.Image

**Since**: 10

**Related module**: [Image](image.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| int8_t [editable](image.md#editable) | Whether the output PixelMap is editable.|
| int32_t [pixelFormat](image.md#pixelformat-23) | Pixel format of the output PixelMap.|
| int32_t [fitDensity](image.md#fitdensity) | Pixel density of the output PixelMap.|
| uint32_t [index](image.md#index) | Index of the output PixelMap.|
| uint32_t [sampleSize](image.md#samplesize) | Size of the sample.|
| uint32_t [rotate](image.md#rotate) | Decoding rotation options.|
| struct [OhosImageSize](_ohos_image_size.md) [size](image.md#size-27) | Pixel width and height of the output PixelMap.|
| struct [OhosImageRegion](_ohos_image_region.md) [region](image.md#region) | Region of the output PixelMap.|
