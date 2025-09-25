# OhosImageSource
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The struct describes the input resource of an image source. Only one type of resource is accepted at a time. The image source is obtained by calling [OH_ImageSource_CreateFromUri](capi-image-source-mdk-h.md#oh_imagesource_createfromuri), [OH_ImageSource_CreateFromFd](capi-image-source-mdk-h.md#oh_imagesource_createfromfd), or [OH_ImageSource_CreateFromData](capi-image-source-mdk-h.md#oh_imagesource_createfromdata).

**Since**: 10

**Deprecated from**: 11

**Related module**: [Image](capi-image.md)

**Header file**: [image_source_mdk.h](capi-image-source-mdk-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| char* uri = nullptr | Pointer to the image source URI. Only a file URI or Base64 URI is accepted.|
| size_t uriSize = 0 | Length of the image source URI.|
| int32_t fd = - 1 | Descriptor of the image source.|
| uint8_t* buffer = nullptr | Pointer to the image source buffer. Only a formatted packet buffer or Base64 buffer is accepted.|
| size_t bufferSize = 0 | Size of the image source buffer.|
