# OH_NativeBuffer_Plane
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Felix-fangyang; @li_hui180; @dingpy-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
## 概述

单个图像平面格式信息。

**起始版本：** 12

**相关模块：** [OH_NativeBuffer](capi-oh-nativebuffer.md)

**所在头文件：** [native_buffer.h](capi-native-buffer-h.md)

## 汇总

### 成员变量

| 名称                  | 描述                                                       |
| --------------------- | ---------------------------------------------------------- |
| uint64_t offset       | 图像平面的偏移量，单位为Byte。                             |
| uint32_t rowStride    | 从图像一行的第一个值到下一行的第一个值的距离，单位为Byte。 |
| uint32_t columnStride | 从图像一列的第一个值到下一列的第一个值的距离，单位为Byte。 |

