# OhosImageRegion

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9329f19aa2995f079ff9cf109a20aad0033a91a3 translatedAt=2026-08-03T04:03:41.952Z pushedAt=2026-08-04T02:54:25.546Z -->

```c
struct OhosImageRegion {...}
```

## Overview

The struct describes the region of an image source to decode. It is a member variable of [OhosImageDecodingOps](capi-image-ohosimagedecodingops.md).

**Since**: 10

**Related module**: [Image](capi-image.md)

**Header file**: [image_source_mdk.h](capi-image-source-mdk-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t x | X coordinate of the start point, in pixels.|
| int32_t y | Y coordinate of the start point, in pixels.|
| int32_t width | Width of the region, in pixels.|
| int32_t height | Height of the region, in pixels.|