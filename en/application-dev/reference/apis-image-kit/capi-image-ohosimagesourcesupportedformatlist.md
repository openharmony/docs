# OhosImageSourceSupportedFormatList

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9329f19aa2995f079ff9cf109a20aad0033a91a3 translatedAt=2026-08-03T04:04:16.471Z pushedAt=2026-08-04T02:53:11.589Z -->

```c
struct OhosImageSourceSupportedFormatList {...}
```

## Overview

The struct defines the format string list supported by an image source. It is obtained by calling [OH_ImageSource_GetSupportedFormats](capi-image-source-mdk-h.md#oh_imagesource_getsupportedformats).

**Since**: 10

**Related module**: [Image](capi-image.md)

**Header file**: [image_source_mdk.h](capi-image-source-mdk-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| struct [OhosImageSourceSupportedFormat](capi-image-ohosimagesourcesupportedformat.md)** supportedFormatList = nullptr | Double pointer to the starting address of the format string list.|
| size_t size = 0 | Size of the format string list.|