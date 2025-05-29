# OhosImageSourceUpdateData


## 概述

定义图像源更新数据选项，由[OH_ImageSource_UpdateData](image.md#oh_imagesource_updatedata)获取。

**系统能力：** SystemCapability.Multimedia.Image

**起始版本：** 10

**相关模块：** [Image](image.md)

**所在头文件：**[image_source_mdk.h](image__source__mdk_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint8_t \* [buffer](image.md#buffer-22) = nullptr | 图像源更新数据缓冲区。 |
| size_t [bufferSize](image.md#buffersize-22) = 0 | 图像源更新数据缓冲区大小。 |
| uint32_t [offset](image.md#offset) = 0 | 图像源更新数据缓冲区的开端。 |
| uint32_t [updateLength](image.md#updatelength) = 0 | 图像源更新数据缓冲区的更新数据长度。 |
| int8_t [isCompleted](image.md#iscompleted) = 0 | 图像源更新数据在此节中完成。 |
