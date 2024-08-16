# OhosPixelMapInfo


## 概述

用于定义PixelMap的相关信息。

**系统能力：** SystemCapability.Multimedia.Image

**废弃版本：** 10

**起始版本：** 8

**相关模块：** [Image](image.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [width](#width) | 图片的宽, 用pixels表示。  | 
| uint32_t [height](#height) | 图片的高, 用pixels表示。  | 
| uint32_t [rowSize](#rowsize) | 每行的bytes数。  | 
| int32_t [pixelFormat](#pixelformat) | Pixel的格式。  | 


## 结构体成员变量说明


### height

```
uint32_t OhosPixelMapInfo::height
```
**描述**
图片的高, 用pixels表示。


### pixelFormat

```
int32_t OhosPixelMapInfo::pixelFormat
```
**描述**
Pixel 的格式，取值范围如下表所示：

| 值 | 说明 |
| ------ | ----------------- |
| 0 | 未知格式。 |
| 2 | 格式为RGB_565 |
| 3 | 格式为RGBA_8888 |
| 4 | 格式为BGRA_8888 |
| 5 | 格式为RGB_888 |
| 6 | 格式为ALPHA_8 |
| 7 | 格式为RGBA_F16 |
| 8 | 格式为NV21 |
| 9 | 格式为NV12 |

### rowSize

```
uint32_t OhosPixelMapInfo::rowSize
```
**描述**
每行的bytes数。DMA内存为图片的宽 * 每个像素字节数 + padding；其他内存为图片的宽 * 每个像素字节数。


### width

```
uint32_t OhosPixelMapInfo::width
```
**描述**
图片的宽, 用pixels表示。
