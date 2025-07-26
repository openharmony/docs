# OhosImageSourceInfo

## 概述

定义图像源信息，由[OH_ImageSource_GetImageInfo](capi-image-source-mdk-h.md#oh_imagesource_getimageinfo)获取。

**起始版本：** 10

**相关模块：** [Image](capi-image.md)

**所在头文件：** [image_source_mdk.h](capi-image-source-mdk-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| int32_t pixelFormat | 图像源像素格式，由[OH_ImageSource_Create](capi-image-source-mdk-h.md#oh_imagesource_create)设置。 |
| int32_t colorSpace | 图像源色彩空间。 |
| int32_t alphaType | 图像源透明度类型。 |
| int32_t density | 图像源密度，由[OH_ImageSource_Create](capi-image-source-mdk-h.md#oh_imagesource_create)设置。 |
| struct [OhosImageSize](capi-image-ohosimagesize.md) size | 图像源像素宽高的大小。 |


