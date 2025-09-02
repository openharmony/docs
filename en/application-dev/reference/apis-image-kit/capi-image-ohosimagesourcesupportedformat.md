# OhosImageSourceSupportedFormat
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

## Overview

The OhosImageSourceSupportedFormat struct describes the format string supported by an image source. It is used in [OhosImageSourceSupportedFormatList](capi-image-ohosimagesourcesupportedformatlist.md) and [OH_ImageSource_GetSupportedFormats](capi-image-source-mdk-h.md#oh_imagesource_getsupportedformats).

**Since**: 10

**Related module**: [Image](capi-image.md)

**Header file**: [image_source_mdk.h](capi-image-source-mdk-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| char* format = nullptr | Pointer to the starting address of the format string.|
| size_t size = 0 | Size of the format string.|
