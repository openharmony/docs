# GetBufferHandleUsageParams


## 概述

查询vendor层BufferHandle的默认usage配置。

**起始版本：** 4.1

**相关模块：**[Codec](_codec_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [size](#size) | 结构体大小  | 
| union CodecVersionType [version](#version) | 组件版本  | 
| unsigned int [portIndex](#portindex) | 端口序列  | 
| unsigned long [usage](#usage) | Usage  | 


## 类成员变量说明


### portIndex

```
unsigned int GetBufferHandleUsageParams::portIndex
```
**描述**

端口序列


### size

```
unsigned int GetBufferHandleUsageParams::size
```
**描述**

结构体大小


### usage

```
unsigned long GetBufferHandleUsageParams::usage
```
**描述**

Usage


### version

```
union CodecVersionType GetBufferHandleUsageParams::version
```
**描述**

组件版本
