# OhosImageSourceDelayTimeList
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The struct describes the delay time list of an image source. The delay time list is obtained by calling [OH_ImageSource_GetDelayTime](capi-image-source-mdk-h.md#oh_imagesource_getdelaytime).

**Since**: 10

**Related module**: [Image](capi-image.md)

**Header file**: [image_source_mdk.h](capi-image-source-mdk-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t* delayTimeList | Pointer to the starting address of the image source delay time list.|
| size_t size = 0 | Size of the image source delay time list.|
