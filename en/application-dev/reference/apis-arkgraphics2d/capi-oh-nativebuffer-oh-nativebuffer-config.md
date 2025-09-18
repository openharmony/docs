# OH_NativeBuffer_Config
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Felix-fangyang; @li_hui180; @dingpy-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
## Overview

The **OH_NativeBuffer_Config** struct describes the **OH_NativeBuffer** attribute configuration, which is used when you apply for a new **OH_NativeBuffer** instance or query the attributes of an existing instance.

**Since**: 9

**Related module**: [OH_NativeBuffer](capi-oh-nativebuffer.md)

**Header file**: [native_buffer.h](capi-native-buffer-h.md)

## Summary

### Member Variables

| Name          | Description                                                        |
| -------------- | ------------------------------------------------------------ |
| int32_t width  | Width, in pixels.                                              |
| int32_t height | Height, in pixels.                                              |
| int32_t format | Pixel format. For details about the available options, see [OH_NativeBuffer_Format](capi-native-buffer-h.md#oh_nativebuffer_format).|
| int32_t usage  | Usage of the buffer. For details about the available options, see [OH_NativeBuffer_Usage](capi-native-buffer-h.md#oh_nativebuffer_usage).|
| int32_t stride | Double pointer to the image processing instance created. Stride of the local window buffer, in bytes.<br>**Since**: 10|
