# OhosImageSourceProperty


## Overview

The OhosImageSourceProperty struct defines the property string (in key-value format) of an image source. It is used in [OH_ImageSource_GetImageProperty](image.md#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](image.md#oh_imagesource_modifyimageproperty).

**System capability**: SystemCapability.Multimedia.Image

**Since**: 10

**Related module**: [Image](image.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| char \* [value](image.md#value) = nullptr | Pointer to the starting address of the property string.|
| size_t [size](image.md#size-77) = 0 | Size of the property string.|
