# OhosImageSource


## 概述

定义图像源输入资源，每次仅接收一种类型。由[OH_ImageSource_Create](image.md#oh_imagesource_create)获取。

**系统能力：** SystemCapability.Multimedia.Image

**废弃版本：** 11

**起始版本：** 10

**相关模块：** [Image](image.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| char \* [uri](image.md#uri) = nullptr | 图像源资源标识符，接受文件资源或者base64资源。 |
| size_t [uriSize](image.md#urisize) = 0 | 图像源资源长度。 |
| int32_t [fd](image.md#fd) = -1 | 图像源文件资源描述符。 |
| uint8_t \* [buffer](image.md#buffer-12) = nullptr | 图像源缓冲区资源，接受格式化包缓冲区或者base64缓冲区。 |
| size_t [bufferSize](image.md#buffersize-12) = 0 | 图像源缓冲区资源大小。 |
