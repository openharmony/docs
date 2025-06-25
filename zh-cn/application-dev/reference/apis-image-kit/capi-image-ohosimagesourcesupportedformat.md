# OhosImageSourceSupportedFormat

## 概述

定义图像源支持的格式字符串。此选项给[OhosImageSourceSupportedFormatList](capi-image-ohosimagesourcesupportedformatlist.md)和[OH_ImageSource_GetSupportedFormats](capi-image-source-mdk-h.md#oh_imagesource_getsupportedformats)接口使用。

**起始版本：** 10

**相关模块：** [Image](capi-image.md)

**所在头文件：** [image_source_mdk.h](capi-image-source-mdk-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| char* format = nullptr | 图像源支持的格式字符串头地址。 |
| size_t size = 0 | 图像源支持的格式字符串大小。 |


