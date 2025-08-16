# Image_Region
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## 概述

待解码的图像源区域结构体。

**起始版本：** 12

**相关模块：** [Image_NativeModule](capi-image-nativemodule.md)

**所在头文件：** [image_common.h](capi-image-common-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t x | 区域横坐标，不能大于原图的宽度。 |
| uint32_t y | 区域纵坐标，不能大于原图的高度。 |
| uint32_t width | 输出图片的宽，单位：像素。 |
| uint32_t height | 输出图片的高，单位：像素。 |
