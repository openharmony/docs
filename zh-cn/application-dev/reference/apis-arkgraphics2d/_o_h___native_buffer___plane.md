# OH_NativeBuffer_Plane


## 概述

单个图像平面格式信息。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12

**相关模块：**[OH_NativeBuffer](_o_h___native_buffer.md)

**所在头文件：**[native_buffer.h](native__buffer_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint64_t [offset](#offset) | 图像平面的偏移量，单位为Byte。  | 
| uint32_t [rowStride](#rowstride) | 从图像一行的第一个值到下一行的第一个值的距离，单位为Byte。  | 
| uint32_t [columnStride](#columnstride) | 从图像一列的第一个值到下一列的第一个值的距离，单位为Byte。  | 


## 结构体成员变量说明


### columnStride

```
uint32_t OH_NativeBuffer_Plane::columnStride
```
**描述：**

从图像一列的第一个值到下一列的第一个值的距离，单位为Byte。


### offset

```
uint64_t OH_NativeBuffer_Plane::offset
```
**描述：**

图像平面的偏移量，单位为Byte。


### rowStride

```
uint32_t OH_NativeBuffer_Plane::rowStride
```
**描述：**

从图像一行的第一个值到下一行的第一个值的距离，单位为Byte。
