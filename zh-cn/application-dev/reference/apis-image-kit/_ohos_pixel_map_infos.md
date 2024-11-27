# OhosPixelMapInfos


## 概述

用于定义PixelMap的相关信息。

**系统能力：** SystemCapability.Multimedia.Image

**起始版本：** 10

**相关模块：** [Image](image.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [width](#width) | 图片的宽，用pixels表示。  | 
| uint32_t [height](#height) | 图片的高，用pixels表示。  | 
| uint32_t [rowSize](#rowsize) | 图片在内存中，每行所占的字节数。 | 
| int32_t [pixelFormat](#pixelformat) | Pixel的格式。  | 


## 结构体成员变量说明


### height

```
uint32_t OhosPixelMapInfos::height
```
**描述**
图片的高，用pixels表示。


### pixelFormat

```
int32_t OhosPixelMapInfos::pixelFormat
```
**描述**
Pixel的格式。


### rowSize

```
uint32_t OhosPixelMapInfos::rowSize
```
**描述**
图片在内存中，每行所占的字节数。

DMA内存为图片的宽 * 每个像素字节数 + 每行末尾填充字节数；其他内存为图片的宽 * 每个像素字节数。


### width

```
uint32_t OhosPixelMapInfos::width
```
**描述**
图片的宽，用pixels表示。
