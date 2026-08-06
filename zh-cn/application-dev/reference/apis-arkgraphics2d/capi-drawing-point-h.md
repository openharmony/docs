# drawing_point.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @dreamyhhh-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## 概述

文件中定义了与坐标点相关的功能函数，支持创建、获取、设置、取反、偏移及销毁坐标点对象等操作，便于在2D图形绘制中对坐标点进行管理与变换。<br>本模块为单线程模型策略，需要调用方自行管理线程安全和上下文状态的切换。

**引用文件：** \<native_drawing/drawing_point.h\>

**库：** libnative_drawing.so

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_Point* OH_Drawing_PointCreate(float x, float y)](#oh_drawing_pointcreate) | 创建一个坐标点对象。当此坐标点对象不再需要时，必须调用[OH_Drawing_PointDestroy](#oh_drawing_pointdestroy)销毁并回收内存。 |
| [OH_Drawing_ErrorCode OH_Drawing_PointGetX(const OH_Drawing_Point* point, float* x)](#oh_drawing_pointgetx) | 获取坐标点的x轴坐标值。 |
| [OH_Drawing_ErrorCode OH_Drawing_PointGetY(const OH_Drawing_Point* point, float* y)](#oh_drawing_pointgety) | 获取坐标点的y轴坐标值。 |
| [OH_Drawing_ErrorCode OH_Drawing_PointSet(OH_Drawing_Point* point, float x, float y)](#oh_drawing_pointset) | 设置坐标点的x轴和y轴坐标。 |
| [OH_Drawing_ErrorCode OH_Drawing_PointNegate(OH_Drawing_Point* point)](#oh_drawing_pointnegate) | 对坐标点的x轴和y轴坐标取反。 |
| [OH_Drawing_ErrorCode OH_Drawing_PointOffset(OH_Drawing_Point* point, float dx, float dy)](#oh_drawing_pointoffset) | 将坐标点沿x轴和y轴方向偏移指定距离。 |
| [void OH_Drawing_PointDestroy(OH_Drawing_Point* point)](#oh_drawing_pointdestroy) | 销毁坐标点对象并回收该对象占用的内存。需在[OH_Drawing_PointCreate](#oh_drawing_pointcreate)创建对象后且该对象不再使用时调用。 |

## 函数说明

### OH_Drawing_PointCreate()

```c
OH_Drawing_Point* OH_Drawing_PointCreate(float x, float y)
```

**描述**

创建一个坐标点对象。当此坐标点对象不再需要时，必须调用[OH_Drawing_PointDestroy](#oh_drawing_pointdestroy)销毁并回收内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| float x | 表示坐标点的x轴坐标，单位为物理像素px。 |
| float y | 表示坐标点的y轴坐标，单位为物理像素px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Point](capi-drawing-oh-drawing-point.md)* | 函数返回指向创建的坐标点对象的指针。 |

### OH_Drawing_PointGetX()

```c
OH_Drawing_ErrorCode OH_Drawing_PointGetX(const OH_Drawing_Point* point, float* x)
```

**描述**

获取坐标点的x轴坐标值。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Point](capi-drawing-oh-drawing-point.md)* point | 指向坐标点对象[OH_Drawing_Point](capi-drawing-oh-drawing-point.md)的指针。 |
| float* x | 输出参数，用于接收坐标点的x轴坐标值，单位为物理像素px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数point或者x为空。 |

### OH_Drawing_PointGetY()

```c
OH_Drawing_ErrorCode OH_Drawing_PointGetY(const OH_Drawing_Point* point, float* y)
```

**描述**

获取坐标点的y轴坐标值。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Point](capi-drawing-oh-drawing-point.md)* point | 指向坐标点对象[OH_Drawing_Point](capi-drawing-oh-drawing-point.md)的指针。 |
| float* y | 输出参数，用于接收坐标点的y轴坐标值，单位为物理像素px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数point或者y为空。 |

### OH_Drawing_PointSet()

```c
OH_Drawing_ErrorCode OH_Drawing_PointSet(OH_Drawing_Point* point, float x, float y)
```

**描述**

设置坐标点的x轴和y轴坐标。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Point](capi-drawing-oh-drawing-point.md)* point | 指向坐标点对象[OH_Drawing_Point](capi-drawing-oh-drawing-point.md)的指针。 |
| float x | 表示坐标点的x轴坐标，单位为物理像素px。 |
| float y | 表示坐标点的y轴坐标，单位为物理像素px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数point为空。 |

### OH_Drawing_PointNegate()

```c
OH_Drawing_ErrorCode OH_Drawing_PointNegate(OH_Drawing_Point* point)
```

**描述**

对坐标点的x轴和y轴坐标取反。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Point](capi-drawing-oh-drawing-point.md)* point | 指向坐标点对象[OH_Drawing_Point](capi-drawing-oh-drawing-point.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示参数point为空。 |

### OH_Drawing_PointOffset()

```c
OH_Drawing_ErrorCode OH_Drawing_PointOffset(OH_Drawing_Point* point, float dx, float dy)
```

**描述**

将坐标点沿x轴和y轴方向偏移指定距离。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Point](capi-drawing-oh-drawing-point.md)* point | 指向坐标点对象[OH_Drawing_Point](capi-drawing-oh-drawing-point.md)的指针。 |
| float dx | 表示在x轴上的偏移量，单位为物理像素px。正数表示往x轴正方向平移，负数表示往x轴负方向平移。 |
| float dy | 表示在y轴上的偏移量，单位为物理像素px。正数表示往y轴正方向平移，负数表示往y轴负方向平移。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示参数point为空。 |

### OH_Drawing_PointDestroy()

```c
void OH_Drawing_PointDestroy(OH_Drawing_Point* point)
```

**描述**

销毁坐标点对象并回收该对象占用的内存。需在[OH_Drawing_PointCreate](#oh_drawing_pointcreate)创建对象后且该对象不再使用时调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Point](capi-drawing-oh-drawing-point.md)* point | 指向坐标点对象的指针。 |


