# OH_NativeBuffer_Planes
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Felix-fangyang; @li_hui180; @dingpy-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
## 概述

OH_NativeBuffer的图像平面格式信息。

**起始版本：** 12

**相关模块：** [OH_NativeBuffer](capi-oh-nativebuffer.md)

**所在头文件：** [native_buffer.h](capi-native-buffer-h.md)

## 汇总

### 成员变量

| 名称                                                         | 描述                   |
| ------------------------------------------------------------ | ---------------------- |
| uint32_t planeCount                                          | 不同平面的数量。       |
| [OH_NativeBuffer_Plane](capi-oh-nativebuffer-oh-nativebuffer-plane.md) planes[4] | 图像平面格式信息数组。 |

