# OhosImageComponent

## 概述

定义图像组成信息。

**起始版本：** 10

**相关模块：** [Image](capi-image.md)

**所在头文件：** [image_mdk.h](capi-image-mdk-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint8_t* byteBuffer | 像素数据地址 |
| size_t size | 内存中的像素数据大小 |
| int32_t componentType | 像素数据类型 |
| int32_t rowStride | 像素数据行宽 |
| int32_t pixelStride | 像素数据的像素大小 |


