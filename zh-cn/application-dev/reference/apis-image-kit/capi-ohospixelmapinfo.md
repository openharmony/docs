# OhosPixelMapInfo

## 概述

用于定义PixelMap的相关信息。

**起始版本：** 8

**废弃版本：** 10

**相关模块：** [Image](capi-image.md)

**所在头文件：** [image_pixel_map_napi.h](capi-image-pixel-map-napi-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t width | 图片的宽，用pixels表示。 |
| uint32_t height | 图片的高，用pixels表示。 |
| uint32_t rowSize | 图片在内存中，每行所占的字节数。<br>DMA内存为图片的宽 \* 每个像素字节数 + 每行末尾填充字节数；其他内存为图片的宽 \* 每个像素字节数。 |
| int32_t pixelFormat |  Pixel的格式，取值范围：<br>0：未知格式。<br>2：格式为RGB_565。<br>3：格式为RGBA_8888。<br>4：格式为BGRA_8888。<br>5：格式为RGB_888。<br>6：格式为ALPHA_8。<br>7：格式为RGBA_F16。<br>8：格式为NV21。<br>9：格式为NV12。 |


