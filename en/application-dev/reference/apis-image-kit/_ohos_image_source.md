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
| [uri](image.md#uri) = nullptr | Defines a pointer to the image source URI. Only a file URI or Base64 URI is accepted.| 
| [uriSize](image.md#urisize) = 0 | Defines the length of the image source URI.| 
| [fd](image.md#fd) = -1 | Defines the descriptor of the image source.| 
| [buffer](image.md#buffer-12) = nullptr | Defines a pointer to the image source buffer. Only a formatted packet buffer or Base64 buffer is accepted.| 
| [bufferSize](image.md#buffersize-12) = 0 | Defines the size of the image source buffer.| 
