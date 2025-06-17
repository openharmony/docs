# drawing_region.h

## 概述

定义了与区域相关的功能函数，包括区域的创建，边界设置和销毁等。

**引用文件：** <native_drawing/drawing_region.h>

**库：** libnative_drawing.so

**起始版本：** 12

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_RegionOpMode](#oh_drawing_regionopmode) | OH_Drawing_RegionOpMode | 区域操作类型枚举。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_Region* OH_Drawing_RegionCreate(void)](#oh_drawing_regioncreate) | 用于创建一个区域对象，实现更精确的图形控制。 |
| [OH_Drawing_Region* OH_Drawing_RegionCopy(const OH_Drawing_Region* region)](#oh_drawing_regioncopy) | 用于创建一个区域对象的拷贝。 |
| [bool OH_Drawing_RegionContains(OH_Drawing_Region* region, int32_t x, int32_t y)](#oh_drawing_regioncontains) | 判断区域是否包含指定坐标点。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>region为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [bool OH_Drawing_RegionOp(OH_Drawing_Region* region, const OH_Drawing_Region* other, OH_Drawing_RegionOpMode op)](#oh_drawing_regionop) | 将两个区域按照指定的区域操作类型合并。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>region、dst任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>op不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [bool OH_Drawing_RegionSetRect(OH_Drawing_Region* region, const OH_Drawing_Rect* rect)](#oh_drawing_regionsetrect) | 用于尝试给区域对象设置矩形边界。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>region、rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [bool OH_Drawing_RegionSetPath(OH_Drawing_Region* region, const OH_Drawing_Path* path, const OH_Drawing_Region* clip)](#oh_drawing_regionsetpath) | 给区域对象设置为指定区域内路径表示的范围。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>region、path、clip任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_RegionDestroy(OH_Drawing_Region* region)](#oh_drawing_regiondestroy) | 用于销毁区域对象并回收该对象占有的内存。 |

## 枚举类型说明

### OH_Drawing_RegionOpMode

```
enum OH_Drawing_RegionOpMode
```

**描述**

区域操作类型枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| REGION_OP_MODE_DIFFERENCE | 差集操作。 |
| REGION_OP_MODE_INTERSECT | 交集操作。 |
| REGION_OP_MODE_UNION | 并集操作。 |
| REGION_OP_MODE_XOR | 异或操作。 |
| REGION_OP_MODE_REVERSE_DIFFERENCE | 反向差集操作。 |
| REGION_OP_MODE_REPLACE | 替换操作。 |


## 函数说明

### OH_Drawing_RegionCreate()

```
OH_Drawing_Region* OH_Drawing_RegionCreate(void)
```

**描述**

用于创建一个区域对象，实现更精确的图形控制。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Region](capi-oh-drawing-region.md)* | 函数会返回一个指针，指针指向创建的区域对象[OH_Drawing_Region](capi-oh-drawing-region.md)。 |

### OH_Drawing_RegionCopy()

```
OH_Drawing_Region* OH_Drawing_RegionCopy(const OH_Drawing_Region* region)
```

**描述**

用于创建一个区域对象的拷贝。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Region](capi-oh-drawing-region.md)* region | 指向用于拷贝的区域对象[OH_Drawing_Region](capi-oh-drawing-region.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Region](capi-oh-drawing-region.md)* | 函数会返回一个指针，指针指向创建的新区域对象。 |

### OH_Drawing_RegionContains()

```
bool OH_Drawing_RegionContains(OH_Drawing_Region* region, int32_t x, int32_t y)
```

**描述**

判断区域是否包含指定坐标点。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>region为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Region](capi-oh-drawing-region.md)* region | 指向区域对象[OH_Drawing_Region](capi-oh-drawing-region.md)的指针。 |
| int32_t x | 表示指定坐标点的x轴坐标。 |
| int32_t y | 表示指定坐标点的y轴坐标。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回区域是否包含指定坐标点。true表示区域包含该坐标点，false表示区域不包含该坐标点。 |

### OH_Drawing_RegionOp()

```
bool OH_Drawing_RegionOp(OH_Drawing_Region* region, const OH_Drawing_Region* other, OH_Drawing_RegionOpMode op)
```

**描述**

将两个区域按照指定的区域操作类型合并。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>region、dst任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>op不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Region](capi-oh-drawing-region.md)* region | 指向区域对象[OH_Drawing_Region](capi-oh-drawing-region.md)的指针，操作完成后的区域结果将会保存在此区域对象中。 |
| const [OH_Drawing_Region](capi-oh-drawing-region.md)* other | 指向区域对象[OH_Drawing_Region](capi-oh-drawing-region.md)的指针。 |
| [OH_Drawing_RegionOpMode](#oh_drawing_regionopmode) op | 区域操作枚举类型，支持可选的具体模式可见[OH_Drawing_RegionOpMode](capi-drawing-region-h.md#oh_drawing_regionopmode)枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回操作后的区域是否为空。true表示区域不为空，false表示区域为空。 |

### OH_Drawing_RegionSetRect()

```
bool OH_Drawing_RegionSetRect(OH_Drawing_Region* region, const OH_Drawing_Rect* rect)
```

**描述**

用于尝试给区域对象设置矩形边界。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>region、rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Region](capi-oh-drawing-region.md)* region | 指向区域对象[OH_Drawing_Region](capi-oh-drawing-region.md)的指针。 |
| const [OH_Drawing_Rect](capi-oh-drawing-rect.md)* rect | 指向矩形对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回区域对象设置矩形边界是否成功的结果。true表示设置矩形边界成功，false表示设置矩形边界失败。 |

### OH_Drawing_RegionSetPath()

```
bool OH_Drawing_RegionSetPath(OH_Drawing_Region* region, const OH_Drawing_Path* path, const OH_Drawing_Region* clip)
```

**描述**

给区域对象设置为指定区域内路径表示的范围。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>region、path、clip任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Region](capi-oh-drawing-region.md)* region | 指向区域对象[OH_Drawing_Region](capi-oh-drawing-region.md)的指针。 |
| const [OH_Drawing_Path](capi-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-oh-drawing-path.md)的指针。 |
| const [OH_Drawing_Region](capi-oh-drawing-region.md)* clip | 指向区域对象[OH_Drawing_Region](capi-oh-drawing-region.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回操作后的区域是否为空。true表示区域不为空，false表示区域为空。 |

### OH_Drawing_RegionDestroy()

```
void OH_Drawing_RegionDestroy(OH_Drawing_Region* region)
```

**描述**

用于销毁区域对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Region](capi-oh-drawing-region.md)* region | 指向区域对象[OH_Drawing_Region](capi-oh-drawing-region.md)的指针。 |


