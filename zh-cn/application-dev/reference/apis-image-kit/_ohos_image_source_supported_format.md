# OhosImageSourceSupportedFormat


## 概述

定义图像源支持的格式字符串。此结构体给[OhosImageSourceSupportedFormatList](_ohos_image_source_supported_format_list.md)结构体和[OH_ImageSource_GetSupportedFormats](image.md#oh_imagesource_getsupportedformats)接口使用。

**系统能力：** SystemCapability.Multimedia.Image

**起始版本：** 10

**相关模块：** [Image](image.md)

**所在头文件：**[image_source_mdk.h](image__source__mdk_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| char \* [format](image.md#format) = nullptr | 图像源支持的格式字符串头地址。 |
| size_t [size](image.md#size-57) = 0 | 图像源支持的格式字符串大小。 |
