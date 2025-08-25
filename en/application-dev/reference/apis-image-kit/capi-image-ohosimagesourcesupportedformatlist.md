# OhosImageSourceSupportedFormatList
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

## Overview

The OhosImageSourceSupportedFormatList struct defines the format string list supported by an image source. It is obtained by calling [OH_ImageSource_GetSupportedFormats](capi-image-source-mdk-h.md#oh_imagesource_getsupportedformats).

**Since**: 10

**Related module**: [Image](capi-image.md)

**Header file**: [image_source_mdk.h](capi-image-source-mdk-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| struct [OhosImageSourceSupportedFormat](capi-image-ohosimagesourcesupportedformat.md)** supportedFormatList = nullptr | Double pointer to the starting address of the format string list.|
| size_t size = 0 | Size of the format string list.|
