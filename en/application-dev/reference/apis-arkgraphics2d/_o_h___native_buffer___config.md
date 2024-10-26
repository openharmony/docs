# OH_NativeBuffer_Config


## Overview

The **OH_NativeBuffer_Config** struct describes the **OH_NativeBuffer** attribute configuration, which is used when you apply for a new **OH_NativeBuffer** instance or query the attributes of an existing instance.

\@syscap SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**

9

**Related Modules**

[OH_NativeBuffer](_o_h___native_buffer.md)


## Summary


### Member Variables

| Name | Description |
| -------- | -------- |
| [width](#width) | Width, in pixels. |
| [height](#height) | Height, in pixels. |
| [format](#format) | Pixel map format. |
| [usage](#usage) | Description of the buffer usage. |
| [stride](#stride) | Output parameter. Stride of the local window buffer, in bytes. |


## Member Variable Description


### format

```
int32_t OH_NativeBuffer_Config::format
```

**Description**

Pixel map format.


### height

```
int32_t OH_NativeBuffer_Config::height
```

**Description**

Height, in pixels.


### stride

```
int32_t OH_NativeBuffer_Config::stride
```

**Description**

Output parameter. Stride of the local window buffer, in bytes.

**Since**

10


### usage

```
int32_t OH_NativeBuffer_Config::usage
```

**Description**

Description of the buffer usage.


### width

```
int32_t OH_NativeBuffer_Config::width
```

**Description**

Width, in pixels.
