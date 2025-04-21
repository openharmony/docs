# OhosImageDecodingOps


## 概述

定义ImageSource解码选项。此结构体给[OH_ImageSource_CreatePixelMap](image.md#oh_imagesource_createpixelmap)和[OH_ImageSource_CreatePixelMapList](image.md#oh_imagesource_createpixelmaplist)这两个接口使用。

**系统能力：** SystemCapability.Multimedia.Image

**起始版本：** 10

**相关模块：** [Image](image.md)

**所在头文件：**[image_source_mdk.h](image__source__mdk_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int8_t [editable](image.md#editable) | 定义输出的像素位图是否可编辑。 |
| int32_t [pixelFormat](image.md#pixelformat-23) | 定义输出的像素格式。 |
| int32_t [fitDensity](image.md#fitdensity) | 定义解码目标的像素密度。 |
| uint32_t [index](image.md#index) | 定义ImageSource解码序号。|
| uint32_t [sampleSize](image.md#samplesize) | 定义解码样本大小选项。 |
| uint32_t [rotate](image.md#rotate) | 定义解码旋转选项。 |
| struct [OhosImageSize](_ohos_image_size.md) [size](image.md#size-27) | 定义解码目标像素宽高的大小。 |
| struct [OhosImageRegion](_ohos_image_region.md) [region](image.md#region) | 定义ImageSource解码的像素范围。 |
