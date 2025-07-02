# Image_Region

## Overview

The Image_Region struct describes the region of an image to decode.

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
