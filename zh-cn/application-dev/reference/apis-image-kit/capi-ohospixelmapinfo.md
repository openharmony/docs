# OhosPixelMapInfo

## 概述

用于定义 pixel map 的相关信息。

**起始版本：** 8

**废弃版本：** 10

**相关模块：** [image](capi-image.md)

**所在头文件：** [image_pixel_map_napi.h](capi-image-pixel-map-napi-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t width | 图片的宽, 用pixels表示 |
| uint32_t height | 图片的高, 用pixels表示 |
| uint32_t rowSize | 每行的bytes数 |
| int32_t pixelFormat | Pixel 的格式 |


