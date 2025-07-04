# OhosImageSourceProperty

## Overview

The OhosImageSourceProperty struct describes the property string (in key-value format) of an image source. It is used in [OH_ImageSource_GetImageProperty](capi-image-source-mdk-h.md#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](capi-image-source-mdk-h.md#oh_imagesource_modifyimageproperty).

**Since**: 10

**Related module**: [Image](capi-image.md)

**Header file**: [image_source_mdk.h](capi-image-source-mdk-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| char* value = nullptr | Pointer to the starting address of the property string.|
| size_t size = 0 | Size of the property string.|
