# OhosImageSourceInfo
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The struct describes the image source information, which is obtained by calling [OH_ImageSource_GetImageInfo](capi-image-source-mdk-h.md#oh_imagesource_getimageinfo).

**Since**: 10

**Related module**: [Image](capi-image.md)

**Header file**: [image_source_mdk.h](capi-image-source-mdk-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t pixelFormat | Pixel format of the image source. It is set by calling [OH_ImageSource_CreateFromUri](capi-image-source-mdk-h.md#oh_imagesource_createfromuri), [OH_ImageSource_CreateFromFd](capi-image-source-mdk-h.md#oh_imagesource_createfromfd), or [OH_ImageSource_CreateFromData](capi-image-source-mdk-h.md#oh_imagesource_createfromdata).|
| int32_t colorSpace | Color space of the image source.|
| int32_t alphaType | Alpha type of the image source.|
| int32_t density | Image density of the image source. It is set by calling [OH_ImageSource_CreateFromUri](capi-image-source-mdk-h.md#oh_imagesource_createfromuri), [OH_ImageSource_CreateFromFd](capi-image-source-mdk-h.md#oh_imagesource_createfromfd), or [OH_ImageSource_CreateFromData](capi-image-source-mdk-h.md#oh_imagesource_createfromdata).|
| struct [OhosImageSize](capi-image-ohosimagesize.md) size | Pixel width and height of the image source.|
