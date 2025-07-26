# drawing_round_rect.h

## 概述

文件中定义了与圆角矩形相关的功能函数。

**引用文件：** <native_drawing/drawing_round_rect.h>

**库：** libnative_drawing.so

**起始版本：** 11

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_CornerPos](#oh_drawing_cornerpos) | OH_Drawing_CornerPos | 用于描述圆角位置的枚举。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_RoundRect* OH_Drawing_RoundRectCreate(const OH_Drawing_Rect* rect, float xRad, float yRad)](#oh_drawing_roundrectcreate) | 用于创建一个圆角矩形对象。本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [OH_Drawing_RoundRect* OH_Drawing_RoundRectCopy(const OH_Drawing_RoundRect* roundRect)](#oh_drawing_roundrectcopy) | 用于创建圆角矩形的拷贝。 |
| [void OH_Drawing_RoundRectSetCorner(OH_Drawing_RoundRect* roundRect,OH_Drawing_CornerPos pos, OH_Drawing_Corner_Radii radii)](#oh_drawing_roundrectsetcorner) | 用于设置圆角矩形中指定圆角位置的圆角半径。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>roundRect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [OH_Drawing_Corner_Radii OH_Drawing_RoundRectGetCorner(OH_Drawing_RoundRect* roundRect, OH_Drawing_CornerPos pos)](#oh_drawing_roundrectgetcorner) | 用于获取圆角矩形中指定圆角位置的圆角半径。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>roundRect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_RoundRectDestroy(OH_Drawing_RoundRect* roundRect)](#oh_drawing_roundrectdestroy) | 用于销毁圆角矩形对象并回收该对象占有的内存。 |
| [OH_Drawing_ErrorCode OH_Drawing_RoundRectOffset(OH_Drawing_RoundRect* roundRect, float dx, float dy)](#oh_drawing_roundrectoffset) | 用于将圆角矩形沿x轴方向和y轴方向平移指定距离。 |

## 枚举类型说明

### OH_Drawing_CornerPos

```
enum OH_Drawing_CornerPos
```

**描述**

用于描述圆角位置的枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| CORNER_POS_TOP_LEFT | 左上角圆角位置。 |
| CORNER_POS_TOP_RIGHT | 右上角圆角位置。 |
| CORNER_POS_BOTTOM_RIGHT | 右下角圆角位置。 |
| CORNER_POS_BOTTOM_LEFT | 左下角圆角位置。 |


## 函数说明

### OH_Drawing_RoundRectCreate()

```
OH_Drawing_RoundRect* OH_Drawing_RoundRectCreate(const OH_Drawing_Rect* rect, float xRad, float yRad)
```

**描述**

用于创建一个圆角矩形对象。本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* rect | 指向矩形对象的指针。 |
| float xRad | X轴上的圆角半径，小于或等于0时无效。 |
| float yRad | Y轴上的圆角半径，小于或等于0时无效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_RoundRect](capi-drawing-oh-drawing-roundrect.md)* | 函数会返回一个指针，指针指向创建的圆角矩形对象。 |

### OH_Drawing_RoundRectCopy()

```
OH_Drawing_RoundRect* OH_Drawing_RoundRectCopy(const OH_Drawing_RoundRect* roundRect)
```

**描述**

用于创建圆角矩形的拷贝。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_RoundRect](capi-drawing-oh-drawing-roundrect.md)* roundRect | 指向用于拷贝的圆角矩形对象[OH_Drawing_RoundRect](capi-drawing-oh-drawing-roundrect.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_RoundRect](capi-drawing-oh-drawing-roundrect.md)* | 函数会返回一个指针，指针指向创建的新圆角矩形对象。 |

### OH_Drawing_RoundRectSetCorner()

```
void OH_Drawing_RoundRectSetCorner(OH_Drawing_RoundRect* roundRect,OH_Drawing_CornerPos pos, OH_Drawing_Corner_Radii radii)
```

**描述**

用于设置圆角矩形中指定圆角位置的圆角半径。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>roundRect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_RoundRect](capi-drawing-oh-drawing-roundrect.md)* roundRect | 指向圆角矩形对象的指针。 |
| [OH_Drawing_CornerPos](#oh_drawing_cornerpos) pos | 圆角位置的枚举，支持类型可见[OH_Drawing_CornerPos](capi-drawing-round-rect-h.md#oh_drawing_cornerpos)。 |
| OH_Drawing_Corner_Radii radii | 圆角半径结构体OH_Drawing_Corner_Radii，其中包含x轴方向和y轴方向上的半径，半径小于等于0时无效。 |

### OH_Drawing_RoundRectGetCorner()

```
OH_Drawing_Corner_Radii OH_Drawing_RoundRectGetCorner(OH_Drawing_RoundRect* roundRect, OH_Drawing_CornerPos pos)
```

**描述**

用于获取圆角矩形中指定圆角位置的圆角半径。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>roundRect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_RoundRect](capi-drawing-oh-drawing-roundrect.md)* roundRect | 指向圆角矩形对象的指针。 |
| [OH_Drawing_CornerPos](#oh_drawing_cornerpos) pos | 圆角位置的枚举，支持类型可见[OH_Drawing_CornerPos](capi-drawing-round-rect-h.md#oh_drawing_cornerpos)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_Drawing_Corner_Radii | 返回指定圆角位置的圆角半径结构体OH_Drawing_Corner_Radii，其中包含x轴方向和y轴方向上的半径。 |

### OH_Drawing_RoundRectDestroy()

```
void OH_Drawing_RoundRectDestroy(OH_Drawing_RoundRect* roundRect)
```

**描述**

用于销毁圆角矩形对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_RoundRect](capi-drawing-oh-drawing-roundrect.md)* roundRect | 指向圆角矩形对象的指针。 |

### OH_Drawing_RoundRectOffset()

```
OH_Drawing_ErrorCode OH_Drawing_RoundRectOffset(OH_Drawing_RoundRect* roundRect, float dx, float dy)
```

**描述**

用于将圆角矩形沿x轴方向和y轴方向平移指定距离。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_RoundRect](capi-drawing-oh-drawing-roundrect.md)* roundRect | 指向圆角矩形对象[OH_Drawing_Point2D](capi-drawing-oh-drawing-point2d.md)的指针。 |
| float dx | 轴方向偏移量。 |
| float dy | 轴方向偏移量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数roundRect为空。 |


