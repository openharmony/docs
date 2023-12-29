# OHOS::Media::OhosPixelMapInfo


## 概述

用于定义PixelMap的相关信息。

**系统能力：** SystemCapability.Multimedia.Image

**废弃起始版本：** 10

**起始版本：** 8

**相关模块：** [Image](image.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [width](#width) | 图片的宽, 用pixels表示。 | 
| [height](#height) | 图片的高, 用pixels表示。 | 
| [rowSize](#rowsize) | 每行的bytes数。DMA内存为图片的宽 * 每个像素字节数 + padding；其他内存为图片的宽 * 每个像素字节数。 | 
| [pixelFormat](#pixelformat) | Pixel的格式。 | 


## 结构体成员变量说明


### height

```
uint32_t OHOS::Media::OhosPixelMapInfo::height
```

**描述**

图片的高, 用pixels表示。


### pixelFormat

```
int32_t OHOS::Media::OhosPixelMapInfo::pixelFormat
```

**描述**

Pixel 的格式。


### rowSize

```
uint32_t OHOS::Media::OhosPixelMapInfo::rowSize
```

**描述**

每行的bytes数。DMA内存为图片的宽 * 每个像素字节数 + padding；其他内存为图片的宽 * 每个像素字节数。


### width

```
uint32_t OHOS::Media::OhosPixelMapInfo::width
```

**描述**

图片的宽, 用pixels表示。
