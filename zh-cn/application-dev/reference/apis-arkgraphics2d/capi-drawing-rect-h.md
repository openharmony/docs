# drawing_rect.h

## 概述

文件中定义了与矩形相关的功能函数。

**引用文件：** <native_drawing/drawing_rect.h>

**库：** libnative_drawing.so

**起始版本：** 11

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_Rect* OH_Drawing_RectCreate(float left, float top, float right, float bottom)](#oh_drawing_rectcreate) | 用于创建一个矩形对象，不会对设置的坐标排序，即允许矩形设置的左上角坐标大于对应的矩形右下角坐标。 |
| [bool OH_Drawing_RectIntersect(OH_Drawing_Rect* rect, const OH_Drawing_Rect* other)](#oh_drawing_rectintersect) | 用于判断两个矩形是否相交，若相交，将rect设置为两个矩形的交集。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect、other任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [bool OH_Drawing_RectJoin(OH_Drawing_Rect* rect, const OH_Drawing_Rect* other)](#oh_drawing_rectjoin) | 将两个矩形取并集。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect、other任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。<br> |
| [void OH_Drawing_RectSetLeft(OH_Drawing_Rect* rect, float left)](#oh_drawing_rectsetleft) | 用于设置矩形左上角的横坐标。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_RectSetTop(OH_Drawing_Rect* rect, float top)](#oh_drawing_rectsettop) | 用于设置矩形左上角的纵坐标。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_RectSetRight(OH_Drawing_Rect* rect, float right)](#oh_drawing_rectsetright) | 用于设置矩形右下角的横坐标。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_RectSetBottom(OH_Drawing_Rect* rect, float bottom)](#oh_drawing_rectsetbottom) | 用于设置矩形右下角的纵坐标。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [float OH_Drawing_RectGetLeft(OH_Drawing_Rect* rect)](#oh_drawing_rectgetleft) | 用于获取给矩形设置的左上角的横坐标。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [float OH_Drawing_RectGetTop(OH_Drawing_Rect* rect)](#oh_drawing_rectgettop) | 用于获取给矩形设置的左上角的纵坐标。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [float OH_Drawing_RectGetRight(OH_Drawing_Rect* rect)](#oh_drawing_rectgetright) | 用于获取给矩形设置的右下角的横坐标。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [float OH_Drawing_RectGetBottom(OH_Drawing_Rect* rect)](#oh_drawing_rectgetbottom) | 用于获取给矩形设置的右下角的纵坐标。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [float OH_Drawing_RectGetHeight(OH_Drawing_Rect* rect)](#oh_drawing_rectgetheight) | 用于获取矩形对象高度，计算方式为设置的矩形的右下角纵坐标减去左上角纵坐标。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [float OH_Drawing_RectGetWidth(OH_Drawing_Rect* rect)](#oh_drawing_rectgetwidth) | 用于获取矩形对象的宽度，计算方式为设置的矩形的右下角横坐标减去左上角横坐标。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_RectCopy(OH_Drawing_Rect* sRect, OH_Drawing_Rect* dRect)](#oh_drawing_rectcopy) | 用于将源矩形对象复制到目标矩形对象。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>sRect、dRect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_RectDestroy(OH_Drawing_Rect* rect)](#oh_drawing_rectdestroy) | 用于销毁矩形对象并回收该对象占有的内存。 |
| [OH_Drawing_Array* OH_Drawing_RectCreateArray(size_t size)](#oh_drawing_rectcreatearray) | 用于创建一个矩形数组对象，用来存储多个矩形对象。不再需要[OH_Drawing_Array](capi-oh-drawing-array.md)时，请使用[OH_Drawing_RectDestroyArray](capi-drawing-rect-h.md#oh_drawing_rectdestroyarray)接口释放该对象的指针。 |
| [OH_Drawing_ErrorCode OH_Drawing_RectGetArraySize(OH_Drawing_Array* rectArray, size_t* pSize)](#oh_drawing_rectgetarraysize) | 用于获取矩形数组对象[OH_Drawing_Array](capi-oh-drawing-array.md)的大小。 |
| [OH_Drawing_ErrorCode OH_Drawing_RectGetArrayElement(OH_Drawing_Array* rectArray, size_t index,OH_Drawing_Rect** rect)](#oh_drawing_rectgetarrayelement) | 用于获取矩形数组对象中指定索引的矩形对象。 |
| [OH_Drawing_ErrorCode OH_Drawing_RectDestroyArray(OH_Drawing_Array* rectArray)](#oh_drawing_rectdestroyarray) | 用于销毁矩形数组对象并回收该对象占有的内存。 |

## 函数说明

### OH_Drawing_RectCreate()

```
OH_Drawing_Rect* OH_Drawing_RectCreate(float left, float top, float right, float bottom)
```

**描述**

用于创建一个矩形对象，不会对设置的坐标排序，即允许矩形设置的左上角坐标大于对应的矩形右下角坐标。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| float left | 矩形左上角的横坐标。 |
| float top | 矩形左上角的纵坐标。 |
| float right | 矩形右下角的横坐标。 |
| float bottom | 矩形右下角的纵坐标。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Rect](capi-oh-drawing-rect.md)* | 函数会返回一个指针，指针指向创建的矩形对象。 |

### OH_Drawing_RectIntersect()

```
bool OH_Drawing_RectIntersect(OH_Drawing_Rect* rect, const OH_Drawing_Rect* other)
```

**描述**

用于判断两个矩形是否相交，若相交，将rect设置为两个矩形的交集。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect、other任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Rect](capi-oh-drawing-rect.md)* rect | 指向矩形对象的指针。 |
| const [OH_Drawing_Rect](capi-oh-drawing-rect.md)* other | 指向矩形对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回两个矩形是否相交的结果。true表示这两个矩形相交，rect被设置为两个矩形的交集；false表示不相交，rect保持不变。 |

### OH_Drawing_RectJoin()

```
bool OH_Drawing_RectJoin(OH_Drawing_Rect* rect, const OH_Drawing_Rect* other)
```

**描述**

将两个矩形取并集。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect、other任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。<br>

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Rect](capi-oh-drawing-rect.md)* rect | 指向矩形对象的指针。 |
| const [OH_Drawing_Rect](capi-oh-drawing-rect.md)* other | 指向矩形对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回两个矩形取并集的结果。true表示成功，false表示失败，失败的原因可能是两个矩形至少有一个为NULL或者other矩形大小为空。 |

### OH_Drawing_RectSetLeft()

```
void OH_Drawing_RectSetLeft(OH_Drawing_Rect* rect, float left)
```

**描述**

用于设置矩形左上角的横坐标。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Rect](capi-oh-drawing-rect.md)* rect | 指向矩形对象的指针。 |
| float left | 矩形左上角的横坐标。 |

### OH_Drawing_RectSetTop()

```
void OH_Drawing_RectSetTop(OH_Drawing_Rect* rect, float top)
```

**描述**

用于设置矩形左上角的纵坐标。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Rect](capi-oh-drawing-rect.md)* rect | 指向矩形对象的指针。 |
| float top | 矩形左上角的纵坐标。 |

### OH_Drawing_RectSetRight()

```
void OH_Drawing_RectSetRight(OH_Drawing_Rect* rect, float right)
```

**描述**

用于设置矩形右下角的横坐标。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Rect](capi-oh-drawing-rect.md)* rect | 指向矩形对象的指针。 |
| float right | 矩形右下角的横坐标。 |

### OH_Drawing_RectSetBottom()

```
void OH_Drawing_RectSetBottom(OH_Drawing_Rect* rect, float bottom)
```

**描述**

用于设置矩形右下角的纵坐标。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Rect](capi-oh-drawing-rect.md)* rect | 指向矩形对象的指针。 |
| float bottom | 矩形右下角的纵坐标。 |

### OH_Drawing_RectGetLeft()

```
float OH_Drawing_RectGetLeft(OH_Drawing_Rect* rect)
```

**描述**

用于获取给矩形设置的左上角的横坐标。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Rect](capi-oh-drawing-rect.md)* rect | 指向矩形对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 矩形左上角的横坐标。 |

### OH_Drawing_RectGetTop()

```
float OH_Drawing_RectGetTop(OH_Drawing_Rect* rect)
```

**描述**

用于获取给矩形设置的左上角的纵坐标。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Rect](capi-oh-drawing-rect.md)* rect | 指向矩形对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 矩形左上角的纵坐标。 |

### OH_Drawing_RectGetRight()

```
float OH_Drawing_RectGetRight(OH_Drawing_Rect* rect)
```

**描述**

用于获取给矩形设置的右下角的横坐标。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Rect](capi-oh-drawing-rect.md)* rect | 指向矩形对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 矩形右下角的横坐标。 |

### OH_Drawing_RectGetBottom()

```
float OH_Drawing_RectGetBottom(OH_Drawing_Rect* rect)
```

**描述**

用于获取给矩形设置的右下角的纵坐标。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Rect](capi-oh-drawing-rect.md)* rect | 指向矩形对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 矩形右下角的纵坐标。 |

### OH_Drawing_RectGetHeight()

```
float OH_Drawing_RectGetHeight(OH_Drawing_Rect* rect)
```

**描述**

用于获取矩形对象高度，计算方式为设置的矩形的右下角纵坐标减去左上角纵坐标。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Rect](capi-oh-drawing-rect.md)* rect | 指向矩形对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回矩形对象的高度，单位为像素。 |

### OH_Drawing_RectGetWidth()

```
float OH_Drawing_RectGetWidth(OH_Drawing_Rect* rect)
```

**描述**

用于获取矩形对象的宽度，计算方式为设置的矩形的右下角横坐标减去左上角横坐标。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Rect](capi-oh-drawing-rect.md)* rect | 指向矩形对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回矩形对象的宽度，单位为像素。 |

### OH_Drawing_RectCopy()

```
void OH_Drawing_RectCopy(OH_Drawing_Rect* sRect, OH_Drawing_Rect* dRect)
```

**描述**

用于将源矩形对象复制到目标矩形对象。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>sRect、dRect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Rect](capi-oh-drawing-rect.md)* sRect | 指向源矩形对象的指针。 |
| [OH_Drawing_Rect](capi-oh-drawing-rect.md)* dRect | 指向目标矩形对象的指针。 |

### OH_Drawing_RectDestroy()

```
void OH_Drawing_RectDestroy(OH_Drawing_Rect* rect)
```

**描述**

用于销毁矩形对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Rect](capi-oh-drawing-rect.md)* rect | 指向矩形对象的指针。 |

### OH_Drawing_RectCreateArray()

```
OH_Drawing_Array* OH_Drawing_RectCreateArray(size_t size)
```

**描述**

用于创建一个矩形数组对象，用来存储多个矩形对象。不再需要[OH_Drawing_Array](capi-oh-drawing-array.md)时，请使用[OH_Drawing_RectDestroyArray](capi-drawing-rect-h.md#oh_drawing_rectdestroyarray)接口释放该对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| size_t size | 指定矩形数组的大小，不超过字形索引数量最大值65536。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Array](capi-oh-drawing-array.md)* | 返回创建的数组对象[OH_Drawing_Array](capi-oh-drawing-array.md)指针，如果返回的对象指针为空，表示创建失败。<br> 失败的原因可能为：没有可用的内存或参数错误。 |

### OH_Drawing_RectGetArraySize()

```
OH_Drawing_ErrorCode OH_Drawing_RectGetArraySize(OH_Drawing_Array* rectArray, size_t* pSize)
```

**描述**

用于获取矩形数组对象[OH_Drawing_Array](capi-oh-drawing-array.md)的大小。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Array](capi-oh-drawing-array.md)* rectArray | 指向矩形数组对象[OH_Drawing_Array](capi-oh-drawing-array.md)的指针。 |
| size_t* pSize | 指向size_t类型的指针，用于存储矩形数组大小，作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数rectArray或者pSize为空。 |

### OH_Drawing_RectGetArrayElement()

```
OH_Drawing_ErrorCode OH_Drawing_RectGetArrayElement(OH_Drawing_Array* rectArray, size_t index,OH_Drawing_Rect** rect)
```

**描述**

用于获取矩形数组对象中指定索引的矩形对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Array](capi-oh-drawing-array.md)* rectArray | 指向矩形数组对象[OH_Drawing_Array](capi-oh-drawing-array.md)的指针。 |
| size_t index | 矩形数组的索引。 |
| [OH_Drawing_Rect](capi-oh-drawing-rect.md)** rect | 指向[OH_Drawing_Rect](capi-oh-drawing-rect.md)的二级指针，作为出参，返回给调用者。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数rectArray或者rect为空，或者index越界。 |

### OH_Drawing_RectDestroyArray()

```
OH_Drawing_ErrorCode OH_Drawing_RectDestroyArray(OH_Drawing_Array* rectArray)
```

**描述**

用于销毁矩形数组对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Array](capi-oh-drawing-array.md)* rectArray | 指向矩形数组对象[OH_Drawing_Array](capi-oh-drawing-array.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数rectArray为空。 |


