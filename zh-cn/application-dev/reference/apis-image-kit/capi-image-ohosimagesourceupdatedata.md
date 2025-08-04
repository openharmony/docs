# OhosImageSourceUpdateData
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

## 概述

定义图像源更新数据选项，由[OH_ImageSource_UpdateData](capi-image-source-mdk-h.md#oh_imagesource_updatedata)获取。

**起始版本：** 10

**相关模块：** [Image](capi-image.md)

**所在头文件：** [image_source_mdk.h](capi-image-source-mdk-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint8_t* buffer = nullptr | 图像源更新数据缓冲区。 |
| size_t bufferSize = 0 | 图像源更新数据缓冲区大小。 |
| uint32_t offset = 0 | 图像源更新数据缓冲区的开端。 |
| uint32_t updateLength = 0 | 图像源更新数据缓冲区的更新数据长度。 |
| int8_t isCompleted = 0 | 图像源更新数据在此节中完成。 |


