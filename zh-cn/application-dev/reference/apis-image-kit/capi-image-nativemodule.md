# Image_NativeModule
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## 概述

提供图片处理的相关能力，包括图片编解码、从Native层获取图片数据等。

使用该模块的接口，无需通过JS接口导入，可直接使用NDK完成功能开发。

开发者可根据实际的开发需求，参考对应的开发指南及样例：

- [使用Image_NativeModule完成图片解码](../../media/image/image-source-c.md)
- [使用Image_NativeModule完成多图对象解码](../../media/image/image-source-picture-c.md)
- [使用Image_NativeModule完成图片接收](../../media/image/image-receiver-c.md)
- [使用Image_NativeModule完成位图操作](../../media/image/pixelmap-c.md)
- [使用Image_NativeModule处理图像信息](../../media/image/image-info-c.md)
- [使用Image_NativeModule完成图片编码](../../media/image/image-packer-c.md)
- [使用Image_NativeModule完成多图对象编码](../../media/image/image-packer-picture-c.md)

**起始版本：** 12

## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [image_common.h](capi-image-common-h.md) | 声明图像接口使用的公共枚举和结构体。 |
| [image_native.h](capi-image-native-h.md) | 声明图像的剪辑矩形、大小和组件数据的接口函数。 |
| [image_packer_native.h](capi-image-packer-native-h.md) | 图片编码API。 |
| [image_receiver_native.h](capi-image-receiver-native-h.md) | 声明从native层获取图片数据的方法。 |
| [image_source_native.h](capi-image-source-native-h.md) | 图片解码API。 |
| [picture_native.h](capi-picture-native-h.md) | 提供获取picture数据和信息的API。 |
| [pixelmap_native.h](capi-pixelmap-native-h.md) | 访问Pixelmap的API。 |
