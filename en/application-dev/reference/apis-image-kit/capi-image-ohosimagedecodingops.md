# OhosImageDecodingOps

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9329f19aa2995f079ff9cf109a20aad0033a91a3 translatedAt=2026-08-03T04:03:25.469Z pushedAt=2026-08-04T02:55:32.932Z -->

```c
struct OhosImageDecodingOps {...}
```

## Overview

The struct describes the options for decoding an image source. It is used in [OH_ImageSource_CreatePixelMap](capi-image-source-mdk-h.md#oh_imagesource_createpixelmap) and [OH_ImageSource_CreatePixelMapList](capi-image-source-mdk-h.md#oh_imagesource_createpixelmaplist).

**Since**: 10

**Related module**: [Image](capi-image.md)

**Header file**: [image_source_mdk.h](capi-image-source-mdk-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int8_t editable | Whether the output PixelMap is editable.|
| int32_t pixelFormat | Pixel format of the output PixelMap.|
| int32_t fitDensity | Pixel density of the output PixelMap.|
| uint32_t index | Decoding index of the ImageSource. |
| uint32_t sampleSize | Size of the sample.|
| uint32_t rotate | Decoding rotation options.|
| struct [OhosImageSize](capi-image-ohosimagesize.md) size | Pixel width and height of the output PixelMap.|
| struct [OhosImageRegion](capi-image-ohosimageregion.md) region | Pixel range of the decoded image source.|