# OH_ImageProcessing

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zy_194-->
<!--Designer: @gongzheng92-->
<!--Tester: @gongzheng92-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_ImageProcessing OH_ImageProcessing
```

## 概述

提供OH_ImageProcessing结构体声明。

定义一个初始化为空的OH_ImageProcessing指针，并调用[OH_ImageProcessing_Create](capi-image-processing-h.md#oh_imageprocessing_create)来创建图片处理实例。调用该接口前，应确保传入的指针为空。用户可根据不同的图片处理类型，分别创建多个图片处理实例。

**起始版本：** 13

**相关模块：** [ImageProcessing](capi-imageprocessing.md)

**所在头文件：** [image_processing_types.h](capi-image-processing-types-h.md)

