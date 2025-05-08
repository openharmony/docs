# OhosImageSourceOps


## 概述

定义图像源选项信息。 此选项给[OH_ImageSource_Create](image.md#oh_imagesource_create)和[OH_ImageSource_CreateIncremental](image.md#oh_imagesource_createincremental)这两个接口使用。

**系统能力：** SystemCapability.Multimedia.Image

**起始版本：** 10

**相关模块：** [Image](image.md)

**所在头文件：**[image_source_mdk.h](image__source__mdk_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [density](image.md#density-12) | 图像源像素密度。 |
| int32_t [pixelFormat](image.md#pixelformat-13) | 图像源像素格式，通常用于描述YUV缓冲区。 |
| struct [OhosImageSize](_ohos_image_size.md) [size](image.md#size-17) | 图像源像素宽高的大小。 |
