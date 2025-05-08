# OhosImageSourceSupportedFormatList


## Overview

The OhosImageSourceSupportedFormatList struct defines the format string list supported by an image source. It is obtained by calling [OH_ImageSource_GetSupportedFormats](image.md#oh_imagesource_getsupportedformats).

**System capability**: SystemCapability.Multimedia.Image

**Since**: 10

**Related module**: [Image](image.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| struct [OhosImageSourceSupportedFormat](_ohos_image_source_supported_format.md) \*\* [supportedFormatList](image.md#supportedformatlist) = nullptr | Double pointer to the starting address of the format string list.|
| size_t [size](image.md#size-67) = 0 | Size of the format string list.|
