# OH_NativeBuffer_Planes


## 概述

OH_NativeBuffer的图像平面格式信息。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本：** 12

**相关模块：**[OH_NativeBuffer](_o_h___native_buffer.md)

**所在头文件：**[native_buffer.h](native__buffer_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [planeCount](#planecount) | 不同平面的数量。 | 
| [OH_NativeBuffer_Plane](_o_h___native_buffer___plane.md) [planes](#planes) [4] | 图像平面格式信息数组。 | 


## 结构体成员变量说明


### planeCount

```
uint32_t OH_NativeBuffer_Planes::planeCount
```

**描述：**

不同平面的数量。


### planes

```
OH_NativeBuffer_Plane OH_NativeBuffer_Planes::planes[4]
```

**描述：**

图像平面格式信息数组。
