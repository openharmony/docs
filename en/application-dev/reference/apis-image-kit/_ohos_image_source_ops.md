# OhosImageSourceOps


## Overview

The **OhosImageSourceOps** struct defines the image source options. It is used in [OH_ImageSource_Create](image.md#oh_imagesource_create) and [OH_ImageSource_CreateIncremental](image.md#oh_imagesource_createincremental).

**System capability**: SystemCapability.Multimedia.Image

**Since**: 10

**Related module**: [Image](image.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| int32_t [density](image.md#density-12) | Pixel density of the image source.|
| int32_t [pixelFormat](image.md#pixelformat-13) | Pixel format of the image source. It is usually used to describe the YUV buffer.|
| struct [OhosImageSize](_ohos_image_size.md) [size](image.md#size-17) | Pixel width and height of the image source.|
