# OhosImageSource
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## 概述

定义图像源输入资源，每次仅接收一种类型。由[OH_ImageSource_CreateFromUri](capi-image-source-mdk-h.md#oh_imagesource_createfromuri)、[OH_ImageSource_CreateFromFd](capi-image-source-mdk-h.md#oh_imagesource_createfromfd)和[OH_ImageSource_CreateFromData](capi-image-source-mdk-h.md#oh_imagesource_createfromdata)获取。

**起始版本：** 10

**废弃版本：** 11

**相关模块：** [Image](capi-image.md)

**所在头文件：** [image_source_mdk.h](capi-image-source-mdk-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| char* uri = nullptr | 图像源资源标识符，接受文件资源或者base64资源。 |
| size_t uriSize = 0 | 图像源资源长度。 |
| int32_t fd = - 1 | 图像源文件资源描述符。 |
| uint8_t* buffer = nullptr | 图像源缓冲区资源，接受格式化包缓冲区或者base64缓冲区。 |
| size_t bufferSize = 0 | 图像源缓冲区资源大小。 |


