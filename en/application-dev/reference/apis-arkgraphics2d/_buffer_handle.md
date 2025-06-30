# BufferHandle


## Overview

The BufferHandle struct describes the buffer handle, which is used to transfer and obtain buffer information. The handle contains the file descriptor, size, format, usage, virtual address, shared memory key, physical address, and custom data of the buffer.

**Since**: 8

**Related module**: [NativeWindow](_native_window.md)

**Header file**: [buffer_handle.h](buffer__handle_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| int32_t [fd](#fd) | File descriptor of the buffer. The value **-1** means that the buffer is not supported. | 
| int32_t [width](#width) | Width of the buffer memory, in pixels. | 
| int32_t [stride](#stride) | Stride of the buffer memory, in bytes. | 
| int32_t [height](#height) | Height of the buffer memory, in pixels. | 
| int32_t [size](#size) | Size of the buffer memory, in bytes. | 
| int32_t [format](#format) | Format of the buffer memory. For details about available options, see [OH_NativeBuffer_Format](_o_h___native_buffer.md#oh_nativebuffer_format-1). | 
| uint64_t [usage](#usage) | Usage of the buffer memory, represented as bit flags. For details about available options, see [OH_NativeBuffer_Usage](_o_h___native_buffer.md#oh_nativebuffer_usage-1). | 
| void \* [virAddr](#viraddr) | Virtual address of the buffer memory. | 
| int32_t [key](#key) | Shared memory key of the buffer memory. | 
| uint64_t [phyAddr](#phyaddr) | Physical address of the buffer memory. | 
| uint32_t [reserveFds](#reservefds) | Number of file descriptors for extra data. | 
| uint32_t [reserveInts](#reserveints) | Number of integer values for extra data. | 
| int32_t [reserve](#reserve) [0] | Extra data. | 


## Member Variable Description


### fd

```
int32_t BufferHandle::fd
```

**Description**

File descriptor of the buffer. The value **-1** means that the buffer is not supported.


### format

```
int32_t BufferHandle::format
```

**Description**

Format of the buffer memory. For details about available options, see [OH_NativeBuffer_Format](_o_h___native_buffer.md#oh_nativebuffer_format-1).


### height

```
int32_t BufferHandle::height
```

**Description**

Height of the buffer memory, in pixels.


### key

```
int32_t BufferHandle::key
```

**Description**

Shared memory key of the buffer memory.


### phyAddr

```
uint64_t BufferHandle::phyAddr
```

**Description**

Physical address of the buffer memory.


### reserve

```
int32_t BufferHandle::reserve[0]
```

**Description**

Extra data.


### reserveFds

```
uint32_t BufferHandle::reserveFds
```

**Description**

Number of file descriptors for extra data.


### reserveInts

```
uint32_t BufferHandle::reserveInts
```

**Description**

Number of integer values for extra data.


### size

```
int32_t BufferHandle::size
```

**Description**

Size of the buffer memory, in bytes.


### stride

```
int32_t BufferHandle::stride
```

**Description**

Stride of the buffer memory, in bytes.


### usage

```
uint64_t BufferHandle::usage
```

**Description**

Usage of the buffer memory, represented as bit flags. For details about available options, see [OH_NativeBuffer_Usage](_o_h___native_buffer.md#oh_nativebuffer_usage-1).


### virAddr

```
void* BufferHandle::virAddr
```

**Description**

Virtual address of the buffer memory.


### width

```
int32_t BufferHandle::width
```

**Description**

Width of the buffer memory, in pixels.
