# OH_NativeImage
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Felix-fangyang; @li_hui180; @dingpy-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
## 概述

提供NativeImage功能，作为数据消费者，其中一种用法是将数据和OpenGL纹理对接，需在OpenGL环境下使用，另外一种用法是开发者自行获取buffer进行渲染处理。

**起始版本：** 9

## 文件汇总

| 名称                                     | 描述                                                         |
| ---------------------------------------- | ------------------------------------------------------------ |
| [native_image.h](capi-native-image-h.md) | 定义获取和使用NativeImage的相关函数。<br>引用文件：<native_image/native_image.h> |