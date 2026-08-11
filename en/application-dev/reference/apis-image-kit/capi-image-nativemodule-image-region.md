# Image_Region

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9329f19aa2995f079ff9cf109a20aad0033a91a3 translatedAt=2026-08-03T03:57:49.649Z pushedAt=2026-08-04T03:01:38.188Z -->

```c
struct Image_Region {...}
```

## Overview

The struct describes the region of an image to decode.

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [image_common.h](capi-image-common-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t x | X coordinate of the region. It cannot be greater than the width of the original image.|
| uint32_t y | Y coordinate of the region. It cannot be greater than the height of the original image.|
| uint32_t width | Width of the output image, in px.|
| uint32_t height | Height of the output image, in px.|