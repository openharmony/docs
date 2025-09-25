# OhosImageSourceOps
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The struct describes the image source options. It is used in [OH_ImageSource_CreateFromUri](capi-image-source-mdk-h.md#oh_imagesource_createfromuri), [OH_ImageSource_CreateFromFd](capi-image-source-mdk-h.md#oh_imagesource_createfromfd), [OH_ImageSource_CreateFromData](capi-image-source-mdk-h.md#oh_imagesource_createfromdata), and [OH_ImageSource_CreateIncremental](capi-image-source-mdk-h.md#oh_imagesource_createincremental).

**Since**: 10

**Related module**: [Image](capi-image.md)

**Header file**: [image_source_mdk.h](capi-image-source-mdk-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t density | Pixel density of the image source.|
| int32_t pixelFormat | Pixel format of the image source. It is usually used to describe the YUV buffer.|
| struct [OhosImageSize](capi-image-ohosimagesize.md) size | Pixel width and height of the image source.|
