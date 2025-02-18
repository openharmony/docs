# BufferHandle


## 概述

缓冲区句柄，用于对缓冲区的信息传递和获取。句柄包含了缓冲区的文件描述符、尺寸、格式、用途、虚拟地址、共享内存键、物理地址、自定义数据。

**起始版本：** 8

**相关模块：**[NativeWindow](_native_window.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [fd](#fd) | 缓冲区文件描述符, 若不支持则为-1。  | 
| int32_t [width](#width) | 缓冲区内存的宽度，单位为像素。  | 
| int32_t [stride](#stride) | 缓冲区内存的步幅，单位为字节。  | 
| int32_t [height](#height) | 缓冲区内存的高度，单位为像素。  | 
| int32_t [size](#size) | 缓冲区内存的大小，单位为字节。  | 
| int32_t [format](#format) | 缓冲区内存的格式，取值具体可见[OH_NativeBuffer_Format](_o_h___native_buffer.md#oh_nativebuffer_format-1)枚举值。  | 
| uint64_t [usage](#usage) | 缓冲区内存的用途，按位标志位，取值具体可见[OH_NativeBuffer_Usage](_o_h___native_buffer.md#oh_nativebuffer_usage-1)枚举值。  | 
| void \* [virAddr](#viraddr) | 缓冲区内存的虚拟地址。  | 
| int32_t [key](#key) | 缓冲区共享内存键值。  | 
| uint64_t [phyAddr](#phyaddr) | 缓冲区内存的物理地址。  | 
| uint32_t [reserveFds](#reservefds) | 额外数据的文件描述符数量。  | 
| uint32_t [reserveInts](#reserveints) | 额外数据的整型值数量。  | 
| int32_t [reserve](#reserve) [0] | 额外数据。  | 


## 结构体成员变量说明


### fd

```
int32_t BufferHandle::fd
```

**描述**

缓冲区文件描述符, 若不支持则为-1。


### format

```
int32_t BufferHandle::format
```

**描述**

缓冲区内存的格式，取值具体可见[OH_NativeBuffer_Format](_o_h___native_buffer.md#oh_nativebuffer_format-1)枚举值。


### height

```
int32_t BufferHandle::height
```

**描述**

缓冲区内存的高度，单位为像素。


### key

```
int32_t BufferHandle::key
```

**描述**

缓冲区共享内存键值。


### phyAddr

```
uint64_t BufferHandle::phyAddr
```

**描述**

缓冲区内存的物理地址。


### reserve

```
int32_t BufferHandle::reserve[0]
```

**描述**

额外数据。


### reserveFds

```
uint32_t BufferHandle::reserveFds
```

**描述**

额外数据的文件描述符数量。


### reserveInts

```
uint32_t BufferHandle::reserveInts
```

**描述**

额外数据的整型值数量。


### size

```
int32_t BufferHandle::size
```

**描述**

缓冲区内存的大小，单位为字节。


### stride

```
int32_t BufferHandle::stride
```

**描述**

缓冲区内存的步幅，单位为字节。


### usage

```
uint64_t BufferHandle::usage
```

**描述**

缓冲区内存的用途，按位标志位，取值具体可见[OH_NativeBuffer_Usage](_o_h___native_buffer.md#oh_nativebuffer_usage-1)枚举值。


### virAddr

```
void* BufferHandle::virAddr
```

**描述**

缓冲区内存的虚拟地址。


### width

```
int32_t BufferHandle::width
```

**描述**

缓冲区内存的宽度，单位为像素。
