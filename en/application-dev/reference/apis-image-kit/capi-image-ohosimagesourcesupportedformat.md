# OhosImageSourceSupportedFormat

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9329f19aa2995f079ff9cf109a20aad0033a91a3 translatedAt=2026-08-03T04:04:08.741Z pushedAt=2026-08-04T02:53:15.491Z -->

```c
struct OhosImageSourceSupportedFormat {...}
```

## Overview

The struct describes the format string supported by an image source. It is used in [OhosImageSourceSupportedFormatList](capi-image-ohosimagesourcesupportedformatlist.md) and [OH_ImageSource_GetSupportedFormats](capi-image-source-mdk-h.md#oh_imagesource_getsupportedformats).

**Since**: 10

**Related module**: [Image](capi-image.md)

**Header file**: [image_source_mdk.h](capi-image-source-mdk-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| char* format = nullptr | Pointer to the starting address of the format string.|
| size_t size = 0 | Size of the format string.|