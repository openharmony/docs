# CodecVideoColorspace


## 概述

定义色彩空间参数信息

**起始版本：** 4.1

**相关模块：**[Codec](_codec_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [size](#size) | 结构体大小  | 
| union CodecVersionType [version](#version) | 组件版本  | 
| unsigned int [portIndex](#portindex) | 端口序列  | 
| unsigned int [requestingDataSpace](#requestingdataspace) | 请求颜色空间信息  | 
| unsigned int [dataSpaceChanged](#dataspacechanged) | 颜色空间信息发生变化  | 
| unsigned int [pixeFormat](#pixeformat) | 像素格式  | 
| unsigned int [dataSpace](#dataspace) | 颜色空间  | 
| struct [ColorAspects](_color_aspects_v20.md)[aspects](#aspects) | 色彩空间  | 


## 类成员变量说明


### aspects

```
struct ColorAspects CodecVideoColorspace::aspects
```
**描述**

色彩空间


### dataSpace

```
unsigned int CodecVideoColorspace::dataSpace
```
**描述**

颜色空间


### dataSpaceChanged

```
unsigned int CodecVideoColorspace::dataSpaceChanged
```
**描述**

颜色空间信息发生变化


### pixeFormat

```
unsigned int CodecVideoColorspace::pixeFormat
```
**描述**

像素格式


### portIndex

```
unsigned int CodecVideoColorspace::portIndex
```
**描述**

端口序列


### requestingDataSpace

```
unsigned int CodecVideoColorspace::requestingDataSpace
```
**描述**

请求颜色空间信息


### size

```
unsigned int CodecVideoColorspace::size
```
**描述**

结构体大小


### version

```
union CodecVersionType CodecVideoColorspace::version
```
**描述**

组件版本
