# CodecImageBuffer


## 概述

定义编解码图像缓冲区信息。

**起始版本：** 4.0

**相关模块：**[Codec](_codec_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [id](#id) | 缓冲区ID | 
| unsigned int [size](#size) | 缓冲区大小 | 
| NativeBuffer [buffer](#buffer) | 用于编码或解码的缓冲区句柄 | 
| FileDescriptor [fenceFd](#fencefd) | Fence文件描述符 | 
| [CodecImageRole](_codec_v20.md#codecimagerole)[bufferRole](#bufferrole) | 图像编码格式。详见[CodecImageRole](_codec_v20.md#codecimagerole) | 


## 类成员变量说明


### buffer

```
NativeBuffer CodecImageBuffer::buffer
```

**描述**


用于编码或解码的缓冲区句柄。


### bufferRole

```
CodecImageRole CodecImageBuffer::bufferRole
```

**描述**


图像编码格式。详见[CodecImageRole](_codec_v20.md#codecimagerole).


### fenceFd

```
FileDescriptor CodecImageBuffer::fenceFd
```

**描述**


Fence文件描述符


### id

```
unsigned int CodecImageBuffer::id
```

**描述**


缓冲区ID.


### size

```
unsigned int CodecImageBuffer::size
```

**描述**


缓冲区大小
