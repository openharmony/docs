# OhosImageReceiverInfo
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

## 概述

定义ImageReceiver的相关信息。

**起始版本：** 10

**相关模块：** [Image](capi-image.md)

**所在头文件：** [image_receiver_mdk.h](capi-image-receiver-mdk-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| int32_t width | 消费端接收图片时的默认图像宽度，用pixels表示。 |
| int32_t height | 消费端接收图片时的默认图像高度，用pixels表示。 |
| int32_t format | 通过接收器创建图像格式OHOS_IMAGE_FORMAT_JPEG。 |
| int32_t capicity | 图片缓存数量的最大值。 |


