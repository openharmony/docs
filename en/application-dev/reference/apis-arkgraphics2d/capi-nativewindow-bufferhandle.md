# BufferHandle
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Felix-fangyang; @li_hui180; @dingpy-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
## Overview

Describes the buffer handle, which is used to transfer and obtain buffer information. The handle contains the file descriptor, size, format, usage, virtual address, shared memory key, physical address, and custom data of the buffer.

**Since**: 8

**Related module**: [NativeWindow](capi-nativewindow.md)

**Header file**: [buffer_handle.h](capi-buffer-handle-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t fd | File descriptor of the buffer. The value **-1** means that the buffer is not supported.|
| int32_t width | Width of the buffer memory, in pixels.|
| int32_t stride | Stride of the buffer memory, in bytes.|
| int32_t height | Height of the buffer memory, in pixels.|
| int32_t size | Size of the buffer memory, in bytes.|
| int32_t format | Format of the buffer memory. For details about the available options, see [OH_NativeBuffer_Format](capi-native-buffer-h.md#oh_nativebuffer_format).|
| uint64_t usage | Usage of the buffer memory, represented as bit flags. For details about the available options, see [OH_NativeBuffer_Format](capi-native-buffer-h.md#oh_nativebuffer_format).|
| void* virAddr | Virtual address of the buffer memory.|
| int32_t key | Shared memory key of the buffer memory.|
| uint64_t phyAddr | Physical address of the buffer memory.|
| uint32_t reserveFds | Number of file descriptors for extra data.|
| uint32_t reserveInts | Number of integer values for extra data.|
| int32_t reserve[0] | Extra data.|
