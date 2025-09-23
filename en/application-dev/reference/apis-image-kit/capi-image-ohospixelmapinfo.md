# OhosPixelMapInfo

## Overview

The struct describes the information about a PixelMap.

**Since**: 8

**Deprecated from**: 10

**Related module**: [Image](capi-image.md)

**Header file**: [image_pixel_map_napi.h](capi-image-pixel-map-napi-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t width | Image width, in pixels.|
| uint32_t height | Image height, in pixels.|
| uint32_t rowSize | Number of bytes that each row of the image occupies in the memory.<br>In the case of DMA, the formula is as follows: Image width \* Number of bytes of each pixel + Number of padding bytes at the end of each row. In the case of other types of memory, the formula is as follows: Image width \* Number of bytes of each pixel.|
| int32_t pixelFormat |  Pixel format. The options are as follows:<br>**0**: Unknown format.<br>**2**: RGB_565.<br>**3**: RGBA_8888.<br>**4**: BGRA_8888.<br>**5**: RGB_888.<br>**6**: ALPHA_8.<br>**7**: RGBA_F16.<br>**8**: NV21.<br>**9**: NV12.|
