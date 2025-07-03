# OhosPixelMapInfos

## Overview

The OhosPixelMapInfos struct describes the information about a PixelMap.

**Since**: 10

**Related module**: [Image](capi-image.md)

**Header file**: [image_pixel_map_mdk.h](capi-image-pixel-map-mdk-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t width | Image width, in pixels.|
| uint32_t height | Image height, in pixels.|
| uint32_t rowSize | Number of bytes that each row of the image occupies in the memory.<br>In the case of DMA, the formula is as follows: Image width * Number of bytes of each pixel + Number of padding bytes at the end of each row. In the case of other types of memory, the formula is as follows: Image width * Number of bytes of each pixel.|
| int32_t pixelFormat | Pixel format.|
