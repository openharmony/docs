# OhosImageSourceOps
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## 概述

定义图像源选项信息。此选项给[OH_ImageSource_Create](capi-image-source-mdk-h.md#oh_imagesource_create)和[OH_ImageSource_CreateIncremental](capi-image-source-mdk-h.md#oh_imagesource_createincremental)接口使用。

**起始版本：** 10

**相关模块：** [Image](capi-image.md)

**所在头文件：** [image_source_mdk.h](capi-image-source-mdk-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| int32_t density | 图像源像素密度。 |
| int32_t pixelFormat | 图像源像素格式，通常用于描述YUV缓冲区。 |
| struct [OhosImageSize](capi-image-ohosimagesize.md) size | 图像源像素宽高的大小。 |


