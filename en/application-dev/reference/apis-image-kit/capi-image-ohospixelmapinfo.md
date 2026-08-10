# OhosPixelMapInfo

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=c3fc7552ecc67e4184d5fea40476f98a1ca548f2 translatedAt=2026-08-03T04:04:56.028Z pushedAt=2026-08-04T03:06:47.155Z -->

```c
struct OhosPixelMapInfo {...}
```

## Overview

This struct describes the basic property information of a PixelMap, including image width, height, row size, and pixel format. When calling the PixelMap property query API, developers can obtain this information through this struct.

**Since**: 8

**Deprecated from**: 10

**Related module**: [Image](capi-image.md)

**Header file**: [image_pixel_map_napi.h](capi-image-pixel-map-napi-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t width | Width of the image, in pixels. |
| uint32_t height | Height of the image, in pixels. |
| uint32_t rowSize | Number of bytes occupied by each row of the image in memory.<br>For DMA memory, it is the image width × bytes per pixel + padding bytes at the end of each row; for other memory types (non-DMA memory), it is the image width × bytes per pixel. The specific memory type depends on how the PixelMap is created. |
| int32_t pixelFormat | Pixel format of the image. Value range:<br>**0**: unknown format.<br>**2**: RGB_565.<br>**3**: RGBA_8888.<br>**4**: BGRA_8888.<br>**5**: RGB_888.<br>**6**: ALPHA_8.<br>**7**: RGBA_F16.<br>**8**: NV21.<br>**9**: NV12. |