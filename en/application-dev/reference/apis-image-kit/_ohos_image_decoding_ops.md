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
| int8_t [editable](image.md#editable) | Defines whether the output pixel map is editable.| 
| int32_t [pixelFormat](image.md#pixelformat-23) | Defines the pixel format of the output pixel map.| 
| int32_t [fitDensity](image.md#fitdensity) | Defines the pixel density of the output pixel map.| 
| uint32_t [index](image.md#index) | Defines the index of the output pixel map.| 
| uint32_t [sampleSize](image.md#samplesize) | Defines the size of the sample.| 
| uint32_t [rotate](image.md#rotate) | Defines the decoding rotation option.| 
| struct [OhosImageSize](_ohos_image_size.md) [size](image.md#size-27) | Defines the pixel width and height of the output pixel map.| 
| struct [OhosImageRegion](_ohos_image_region.md) [region](image.md#region) | Defines the region of the output pixel map.| 
