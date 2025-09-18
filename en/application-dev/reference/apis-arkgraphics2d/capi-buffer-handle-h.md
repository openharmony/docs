# buffer_handle.h

## Overview

The **buffer_handle.h** file declares the BufferHandle struct used by the NativeWindow module.

**File to include:** <native_window//buffer_handle.h>

**Library**: libnative_window.so

**Since**: 8

**Related module**: [NativeWindow](capi-nativewindow.md)

## Total

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [BufferHandle](capi-nativewindow-bufferhandle.md) | BufferHandle | Describes the buffer handle, which is used to transfer and obtain buffer information. The handle contains the file descriptor, size, format, usage, virtual address, shared memory key, physical address, and custom data of the buffer.|
