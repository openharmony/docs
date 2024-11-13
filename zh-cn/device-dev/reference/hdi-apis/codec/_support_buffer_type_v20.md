# SupportBufferType


## 概述

查询vendor层支持buffer类型信息。

**起始版本：** 4.1

**相关模块：**[Codec](_codec_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [size](#size) | 结构体大小  | 
| union CodecVersionType [version](#version) | 组件版本  | 
| unsigned int [portIndex](#portindex) | 端口序列  | 
| unsigned int [bufferTypes](#buffertypes) | 支持的buffer类型  | 


## 类成员变量说明


### bufferTypes

```
unsigned int SupportBufferType::bufferTypes
```
**描述**

支持的buffer类型


### portIndex

```
unsigned int SupportBufferType::portIndex
```
**描述**

端口序列


### size

```
unsigned int SupportBufferType::size
```
**描述**

结构体大小


### version

```
union CodecVersionType SupportBufferType::version
```
**描述**

组件版本
