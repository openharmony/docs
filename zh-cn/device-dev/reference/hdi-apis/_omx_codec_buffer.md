# OmxCodecBuffer


## 概述

Codec buffer信息的定义。

**相关模块:**

[Codec](_codec.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [bufferId](#bufferid) | uint32_t<br/>buffer&nbsp;ID。&nbsp; | 
| [size](#size) | uint32_t<br/>结构体大小。&nbsp; | 
| [version](#version) | union&nbsp;OMX_VERSIONTYPE<br/>组件版本信息。&nbsp; | 
| [bufferType](#buffertype) | enum&nbsp;[CodecBufferType](_codec.md#codecbuffertype)<br/>buffer类型。&nbsp; | 
| [buffer](#buffer) | uint8_t&nbsp;\*<br/>编码或者解码使用的buffer。&nbsp; | 
| [bufferLen](#bufferlen) | uint32_t<br/>buffer大小。&nbsp; | 
| [allocLen](#alloclen) | uint32_t<br/>申请的buffer大小。&nbsp; | 
| [filledLen](#filledlen) | uint32_t<br/>填充的buffer大小。&nbsp; | 
| [offset](#offset) | uint32_t<br/>有效数据从缓冲区开始的起始偏移量。&nbsp; | 
| [fenceFd](#fencefd) | int32_t<br/>该描述符来自buffer消费者，Codec等待成功后才可以使用输入或者输出buffer。&nbsp; | 
| [type](#type) | enum&nbsp;[ShareMemTypes](_codec.md#sharememtypes)<br/>共享内存类型。&nbsp; | 
| [pts](#pts) | int64_t<br/>时间戳。&nbsp; | 
| [flag](#flag) | uint32_t<br/>标志。&nbsp; | 


## 类成员变量说明


### allocLen

  
```
uint32_t OmxCodecBuffer::allocLen
```
**描述:**
申请的buffer大小。


### buffer

  
```
uint8_t* OmxCodecBuffer::buffer
```
**描述:**
编码或者解码使用的buffer。


### bufferId

  
```
uint32_t OmxCodecBuffer::bufferId
```
**描述:**
buffer ID。


### bufferLen

  
```
uint32_t OmxCodecBuffer::bufferLen
```
**描述:**
buffer大小。


### bufferType

  
```
enum CodecBufferType OmxCodecBuffer::bufferType
```
**描述:**
buffer类型。


### fenceFd

  
```
int32_t OmxCodecBuffer::fenceFd
```
**描述:**
该描述符来自buffer消费者，Codec等待成功后才可以使用输入或者输出buffer。


### filledLen

  
```
uint32_t OmxCodecBuffer::filledLen
```
**描述:**
填充的buffer大小。


### flag

  
```
uint32_t OmxCodecBuffer::flag
```
**描述:**
标志。


### offset

  
```
uint32_t OmxCodecBuffer::offset
```
**描述:**
有效数据从缓冲区开始的起始偏移量。


### pts

  
```
int64_t OmxCodecBuffer::pts
```
**描述:**
时间戳。


### size

  
```
uint32_t OmxCodecBuffer::size
```
**描述:**
结构体大小。


### type

  
```
enum ShareMemTypes OmxCodecBuffer::type
```
**描述:**
共享内存类型。


### version

  
```
union OMX_VERSIONTYPE OmxCodecBuffer::version
```
**描述:**
组件版本信息。
