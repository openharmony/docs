# OH_NativeBuffer_Plane
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Felix-fangyang; @li_hui180; @dingpy-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
## Overview

This struct describes the plane information of an image.

**Since**: 12

**Related module**: [OH_NativeBuffer](capi-oh-nativebuffer.md)

**Header file**: [native_buffer.h](capi-native-buffer-h.md)

## Summary

### Member Variables

| Name                 | Description                                                      |
| --------------------- | ---------------------------------------------------------- |
| uint64_t offset       | Offset of the image plane, in bytes.                            |
| uint32_t rowStride    | Distance from the first value in an image row to the first value in the next row, in bytes.|
| uint32_t columnStride | Distance from the first value in an image column to the first value in the next column, in bytes.|
