# OmxCodecBuffer


## 概述

Codec buffer信息的定义。

**起始版本：** 4.1

**相关模块：**[Codec](_codec_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [bufferId](#bufferid) | buffer ID。  | 
| unsigned int [size](#size) | 结构体大小。  | 
| union [OMX_VERSIONTYPE](union_o_m_x___v_e_r_s_i_o_n_t_y_p_e_v20.md)[version](#version) | 组件版本信息。  | 
| unsigned int [bufferType](#buffertype) | buffer类型,详见[CodecBufferType](_codec_v20.md#codecbuffertype)。  | 
| NativeBuffer  [bufferhandle](#bufferhandle) | 编码或者解码使用的bufferhandle，详见**[NativeBuffer](../../../../application-dev/reference/apis-image-kit/_image___native_module.md#oh_nativebuffer)**。  | 
| FileDescriptor [fd](#fd) | 匿名共享内存文件描述符。  | 
| unsigned int [allocLen](#alloclen) | 申请的buffer大小。  | 
| unsigned int [filledLen](#filledlen) | 填充的buffer大小。  | 
| unsigned int [offset](#offset) | 有效数据从缓冲区开始的起始偏移量。  | 
| FileDescriptor [fenceFd](#fencefd) | fence fd。  | 
| enum [ShareMemTypes](_codec_v20.md#sharememtypes)[type](#type) | 共享内存类型。  | 
| long [pts](#pts) | 缓冲区第一个逻辑样本时间戳。  | 
| unsigned int [flag](#flag) | 缓冲区特定标志。  | 
| unsigned char[] [alongParam](#alongparam) | 随帧参数  | 


## 类成员变量说明


### allocLen

```
unsigned int OmxCodecBuffer::allocLen
```
**描述**

申请的buffer大小。


### alongParam

```
unsigned char [] OmxCodecBuffer::alongParam
```
**描述**

随帧参数


### bufferhandle

```
BufferHandleParcelable OmxCodecBuffer::bufferhandle
```
**描述**

编码或者解码使用的bufferhandle，详见**BufferHandleParcelable**。


### bufferId

```
unsigned int OmxCodecBuffer::bufferId
```

**描述**

buffer ID。


### bufferType

```
unsigned int OmxCodecBuffer::bufferType
```
**描述**

buffer类型,详见[CodecBufferType](_codec_v20.md#codecbuffertype)。


### fd

```
FileDescriptor OmxCodecBuffer::fd
```
**描述**

匿名共享内存文件描述符。


### fenceFd

```
FileDescriptor OmxCodecBuffer::fenceFd
```
**描述**

fence fd。


### filledLen

```
unsigned int OmxCodecBuffer::filledLen
```
**描述**

填充的buffer大小。


### flag

```
unsigned int OmxCodecBuffer::flag
```
**描述**

缓冲区特定标志。


### offset

```
unsigned int OmxCodecBuffer::offset
```
**描述**

有效数据从缓冲区开始的起始偏移量。


### pts

```
long OmxCodecBuffer::pts
```
**描述**

缓冲区第一个逻辑样本时间戳。


### size

```
unsigned int OmxCodecBuffer::size
```
**描述**

结构体大小。


### type

```
enum ShareMemTypes OmxCodecBuffer::type
```
**描述**

共享内存类型。


### version

```
union OMX_VERSIONTYPE OmxCodecBuffer::version
```
**描述**

组件版本信息。
