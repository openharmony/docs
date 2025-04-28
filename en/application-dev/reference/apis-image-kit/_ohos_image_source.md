# OhosImageSource


## Overview

The **OhosImageSource** struct defines the input resource of an image source. Only one type of resource is accepted at a time. The image source is obtained by calling [OH_ImageSource_Create](image.md#oh_imagesource_create).

**System capability**: SystemCapability.Multimedia.Image

**Deprecated from**: 11

**Since**: 10

**Related module**: [Image](image.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| char \* [uri](image.md#uri) = nullptr | Pointer to the image source URI. Only a file URI or Base64 URI is accepted.|
| size_t [uriSize](image.md#urisize) = 0 | Length of the image source URI.|
| int32_t [fd](image.md#fd) = -1 | Descriptor of the image source.|
| uint8_t \* [buffer](image.md#buffer-12) = nullptr | Pointer to the image source buffer. Only a formatted packet buffer or Base64 buffer is accepted.|
| size_t [bufferSize](image.md#buffersize-12) = 0 | Size of the image source buffer.|
