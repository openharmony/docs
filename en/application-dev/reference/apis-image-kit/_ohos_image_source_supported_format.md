# OhosImageSourceSupportedFormat


## Overview

The OhosImageSourceSupportedFormat struct defines the format string supported by an image source. It is used in the [OhosImageSourceSupportedFormatList](_ohos_image_source_supported_format_list.md) struct and the [OH_ImageSource_GetSupportedFormats](image.md#oh_imagesource_getsupportedformats) function.

**System capability**: SystemCapability.Multimedia.Image

**Since**: 10

**Related module**: [Image](image.md)

**Header file**: [image_source_mdk.h](image__source__mdk_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| char \* [format](image.md#format) = nullptr | Pointer to the starting address of the format string.|
| size_t [size](image.md#size-57) = 0 | Size of the format string.|
