# OhosImageSourceInfo


## 概述

定义图像源信息，由[OH_ImageSource_GetImageInfo](image.md#oh_imagesource_getimageinfo)获取。

**系统能力：** SystemCapability.Multimedia.Image

**起始版本：** 10

**相关模块：** [Image](image.md)

**所在头文件：**[image_source_mdk.h](image__source__mdk_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [pixelFormat](image.md#pixelformat-33) | 图像源像素格式，由[OH_ImageSource_Create()](image.md#oh_imagesource_create)设置。 |
| int32_t [colorSpace](image.md#colorspace) | 图像源色彩空间。 |
| int32_t [alphaType](image.md#alphatype) | 图像源透明度类型。 |
| int32_t [density](image.md#density-22) | 图像源密度，由 [OH_ImageSource_Create()](image.md#oh_imagesource_create)设置。 |
| struct [OhosImageSize](_ohos_image_size.md) [size](image.md#size-37) | 图像源像素宽高的大小。 |
