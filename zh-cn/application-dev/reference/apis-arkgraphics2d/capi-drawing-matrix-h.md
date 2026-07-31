# drawing_matrix.h

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphic-->
<!--Owner: @dreamyhhh-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## 概述

文件中定义了矩阵的创建、拷贝、变换（旋转、缩放、平移、倾斜）、查询（判断相等、判断单位矩阵、获取元素值）和映射等功能函数。<br>本模块为单线程模型策略，需要调用方自行管理线程安全和上下文状态的切换。

<!--RP1-->
**相关示例：** [NDKAPIDrawing (API20)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkGraphics2D/Drawing/NDKAPIDrawing)<!--RP1End-->

**引用文件：** \<native_drawing/drawing_matrix.h\>

**库：** libnative_drawing.so

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_ScaleToFit](#oh_drawing_scaletofit) | OH_Drawing_ScaleToFit | 矩阵缩放方式枚举。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix* OH_Drawing_MatrixCreate(void)](#oh_drawing_matrixcreate) | 用于创建一个矩阵对象。调用此函数创建的矩阵对象，在使用完毕后必须调用[OH_Drawing_MatrixDestroy](capi-drawing-matrix-h.md#oh_drawing_matrixdestroy)释放该对象占用的内存，否则会导致内存泄漏。 |
| [OH_Drawing_Matrix* OH_Drawing_MatrixCopy(const OH_Drawing_Matrix* matrix)](#oh_drawing_matrixcopy) | 用于创建一个矩阵对象的拷贝。调用此函数返回的是一个新的独立矩阵对象，在使用完毕后必须调用[OH_Drawing_MatrixDestroy](capi-drawing-matrix-h.md#oh_drawing_matrixdestroy)单独释放拷贝对象占用的内存，否则会导致内存泄漏。 |
| [OH_Drawing_Matrix* OH_Drawing_MatrixCreateRotation(float deg, float x, float y)](#oh_drawing_matrixcreaterotation) | 创建一个带旋转属性的矩阵对象。<br>该矩阵对象为：单位矩阵在(x, y)旋转中心点以度为单位进行旋转后得到的矩阵。调用此函数创建的矩阵对象，在使用完毕后必须调用[OH_Drawing_MatrixDestroy](capi-drawing-matrix-h.md#oh_drawing_matrixdestroy)释放该对象占用的内存，否则会导致内存泄漏。 |
| [OH_Drawing_Matrix* OH_Drawing_MatrixCreateScale(float sx, float sy, float px, float py)](#oh_drawing_matrixcreatescale) | 创建一个带缩放属性的矩阵对象。<br>该矩阵对象为：单位矩阵在(px, py)缩放中心点以sx和sy为缩放因子进行缩放后得到的矩阵。调用此函数创建的矩阵对象，在使用完毕后必须调用[OH_Drawing_MatrixDestroy](#oh_drawing_matrixdestroy)释放该对象占用的内存。 |
| [OH_Drawing_Matrix* OH_Drawing_MatrixCreateTranslation(float dx, float dy)](#oh_drawing_matrixcreatetranslation) | 创建一个带平移属性的矩阵对象。<br>该矩阵对象为：单位矩阵平移(dx, dy)后得到的矩阵。调用此函数创建的矩阵对象，在使用完毕后必须调用[OH_Drawing_MatrixDestroy](capi-drawing-matrix-h.md#oh_drawing_matrixdestroy)释放该对象占用的内存，否则会导致内存泄漏。 |
| [void OH_Drawing_MatrixSetMatrix(OH_Drawing_Matrix* matrix, float scaleX, float skewX, float transX, float skewY, float scaleY, float transY, float persp0, float persp1, float persp2)](#oh_drawing_matrixsetmatrix) | 用于给矩阵对象设置变换参数，包括缩放、倾斜、位移和透视系数。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>OH_Drawing_Matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [bool OH_Drawing_MatrixSetRectToRect(OH_Drawing_Matrix* matrix, const OH_Drawing_Rect* src, const OH_Drawing_Rect* dst, OH_Drawing_ScaleToFit stf)](#oh_drawing_matrixsetrecttorect) | 将矩阵以缩放方式适配目标矩形。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix、src或dst任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_MatrixPreRotate(OH_Drawing_Matrix* matrix, float degree, float px, float py)](#oh_drawing_matrixprerotate) | 将矩阵设置为矩阵左乘围绕旋转中心点旋转degree角度的单位矩阵后得到的矩阵。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_MatrixPreScale(OH_Drawing_Matrix* matrix, float sx, float sy, float px, float py)](#oh_drawing_matrixprescale) | 将矩阵设置为矩阵左乘围绕缩放中心点按sx和sy缩放因子缩放后的单位矩阵后得到的矩阵。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_MatrixPreTranslate(OH_Drawing_Matrix* matrix, float dx, float dy)](#oh_drawing_matrixpretranslate) | 将矩阵设置为矩阵左乘平移dx和dy距离后的单位矩阵后得到的矩阵。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_MatrixPostRotate(OH_Drawing_Matrix* matrix, float degree, float px, float py)](#oh_drawing_matrixpostrotate) | 将矩阵设置为矩阵右乘围绕旋转中心点旋转degree角度的单位矩阵后得到的矩阵。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_MatrixPostScale(OH_Drawing_Matrix* matrix, float sx, float sy, float px, float py)](#oh_drawing_matrixpostscale) | 将矩阵设置为矩阵右乘围绕缩放中心点按sx和sy缩放因子缩放后的单位矩阵后得到的矩阵。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_MatrixPostTranslate(OH_Drawing_Matrix* matrix, float dx, float dy)](#oh_drawing_matrixposttranslate) | 将矩阵设置为矩阵右乘平移dx和dy距离后的单位矩阵后得到的矩阵。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_MatrixReset(OH_Drawing_Matrix* matrix)](#oh_drawing_matrixreset) | 重置当前矩阵为单位矩阵。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_MatrixConcat(OH_Drawing_Matrix* total, const OH_Drawing_Matrix* a, const OH_Drawing_Matrix* b)](#oh_drawing_matrixconcat) | 将矩阵total设置为矩阵a乘以矩阵b。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>total、a或b任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [OH_Drawing_ErrorCode OH_Drawing_MatrixGetAll(OH_Drawing_Matrix* matrix, float value[9])](#oh_drawing_matrixgetall) | 获取矩阵所有元素值。9个元素按行主序存储，对应3×3矩阵结构，具体排列方式参见[OH_Drawing_MatrixSetMatrix](#oh_drawing_matrixsetmatrix)。 |
| [float OH_Drawing_MatrixGetValue(OH_Drawing_Matrix* matrix, int index)](#oh_drawing_matrixgetvalue) | 获取矩阵给定索引位的值。索引范围0-8。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>index小于0或者大于8时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [void OH_Drawing_MatrixRotate(OH_Drawing_Matrix* matrix, float degree, float px, float py)](#oh_drawing_matrixrotate) | 设置矩阵为单位矩阵，并围绕位于(px, py)的旋转中心点进行旋转。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_MatrixTranslate(OH_Drawing_Matrix* matrix, float dx, float dy)](#oh_drawing_matrixtranslate) | 设置矩阵为单位矩阵，并平移(dx, dy)。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_MatrixScale(OH_Drawing_Matrix* matrix, float sx, float sy, float px, float py)](#oh_drawing_matrixscale) | 设置矩阵为单位矩阵，并围绕位于(px, py)的缩放中心点，以sx和sy进行缩放。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [bool OH_Drawing_MatrixInvert(OH_Drawing_Matrix* matrix, OH_Drawing_Matrix* inverse)](#oh_drawing_matrixinvert) | 将矩阵inverse设置为矩阵的逆矩阵，并返回结果。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix或inverse任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [bool OH_Drawing_MatrixSetPolyToPoly(OH_Drawing_Matrix* matrix, const OH_Drawing_Point2D* src, const OH_Drawing_Point2D* dst, uint32_t count)](#oh_drawing_matrixsetpolytopoly) | 通过设置源点以及目标点，生成对应的变换矩阵。<br>源点以及目标点的个数要大于等于0，小于等于4。本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>count小于0或者大于4时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [void OH_Drawing_MatrixMapPoints(const OH_Drawing_Matrix* matrix, const OH_Drawing_Point2D* src, OH_Drawing_Point2D* dst, int count)](#oh_drawing_matrixmappoints) | 通过矩阵变换将源点数组映射到目标点数组。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix、src或dst任意一个为NULL或者count小于等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [bool OH_Drawing_MatrixMapRect(const OH_Drawing_Matrix* matrix, const OH_Drawing_Rect* src, OH_Drawing_Rect* dst)](#oh_drawing_matrixmaprect) | 将目标矩形设置为一个新的矩形，该矩形是能够包围源矩形的四个顶点通过矩阵变换映射后形成的新顶点的最小矩形。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix、src或dst任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [bool OH_Drawing_MatrixIsEqual(OH_Drawing_Matrix* matrix, OH_Drawing_Matrix* other)](#oh_drawing_matrixisequal) | 判断两个矩阵是否相等。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix或other任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [bool OH_Drawing_MatrixIsIdentity(OH_Drawing_Matrix* matrix)](#oh_drawing_matrixisidentity) | 判断矩阵是否是单位矩阵。单位矩阵为：`[1 0 0; 0 1 0; 0 0 1]`。<br>如需判断两个矩阵是否相等，请使用[OH_Drawing_MatrixIsEqual](#oh_drawing_matrixisequal)。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_MatrixDestroy(OH_Drawing_Matrix* matrix)](#oh_drawing_matrixdestroy) | 用于销毁矩阵对象并回收该对象占用的内存。 |
| [OH_Drawing_ErrorCode OH_Drawing_MatrixPreConcat(OH_Drawing_Matrix* a, OH_Drawing_Matrix* b)](#oh_drawing_matrixpreconcat) | 对矩阵a左乘矩阵b。与[OH_Drawing_MatrixConcat](#oh_drawing_matrixconcat)功能类似，区别在于OH_Drawing_MatrixConcat将结果存入单独的total矩阵，而本方法直接修改矩阵a。 |
| [OH_Drawing_ErrorCode OH_Drawing_MatrixIsAffine(const OH_Drawing_Matrix* matrix, bool* isAffine)](#oh_drawing_matrixisaffine) | 判断当前矩阵是否为仿射矩阵。仿射矩阵是一种包括平移、旋转或缩放等变换的矩阵。 |
| [OH_Drawing_ErrorCode OH_Drawing_MatrixPreSkew(OH_Drawing_Matrix* matrix, float kx, float ky, float px, float py)](#oh_drawing_matrixpreskew) | 将当前矩阵左乘一个以(px, py)为中心按(kx, ky)倾斜构造的矩阵。与[OH_Drawing_MatrixPreRotate](#oh_drawing_matrixprerotate)、[OH_Drawing_MatrixPreScale](#oh_drawing_matrixprescale)、[OH_Drawing_MatrixPreTranslate](#oh_drawing_matrixpretranslate)同属Pre系列方法。 |
| [OH_Drawing_ErrorCode OH_Drawing_MatrixRectStaysRect(const OH_Drawing_Matrix* matrix, bool* isRectStaysRect)](#oh_drawing_matrixrectstaysrect) | 判断矩形经过当前矩阵映射后是否仍保持矩形形状。当矩阵是单位矩阵或仅包含平移、缩放、旋转90度倍数这类仿射变换时满足该条件。 |
| [OH_Drawing_ErrorCode OH_Drawing_MatrixSetSinCos(OH_Drawing_Matrix* matrix, float sinValue, float cosValue, float px, float py)](#oh_drawing_matrixsetsincos) | 设置矩阵，使其围绕旋转中心 (px, py) 以指定的正弦值和余弦值进行旋转。与[OH_Drawing_MatrixRotate](#oh_drawing_matrixrotate)功能类似，区别在于OH_Drawing_MatrixRotate直接传入角度值，而本方法传入正弦值和余弦值。 |

## 枚举类型说明

### OH_Drawing_ScaleToFit

```c
enum OH_Drawing_ScaleToFit
```

**描述**

矩阵缩放方式枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| SCALE_TO_FIT_FILL | 按水平轴和垂直轴缩放以填充目标矩形，不保留源矩形宽高比例。 |
| SCALE_TO_FIT_START | 缩放并对齐到左侧和顶部。 |
| SCALE_TO_FIT_CENTER | 缩放并居中对齐。 |
| SCALE_TO_FIT_END | 缩放并向右和向下对齐。 |


## 函数说明

### OH_Drawing_MatrixCreate()

```c
OH_Drawing_Matrix* OH_Drawing_MatrixCreate(void)
```

**描述**

用于创建一个矩阵对象。调用此函数创建的矩阵对象，在使用完毕后必须调用[OH_Drawing_MatrixDestroy](capi-drawing-matrix-h.md#oh_drawing_matrixdestroy)释放该对象占用的内存，否则会导致内存泄漏。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* | 函数返回一个指针，指针指向创建的矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)。 |

### OH_Drawing_MatrixCopy()

```c
OH_Drawing_Matrix* OH_Drawing_MatrixCopy(const OH_Drawing_Matrix* matrix)
```

**描述**

用于创建一个矩阵对象的拷贝。调用此函数返回的是一个新的独立矩阵对象，在使用完毕后必须调用[OH_Drawing_MatrixDestroy](capi-drawing-matrix-h.md#oh_drawing_matrixdestroy)单独释放拷贝对象占用的内存，否则会导致内存泄漏。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向用于拷贝的矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* | 函数返回一个指针，指针指向创建的新矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)。 |

### OH_Drawing_MatrixCreateRotation()

```c
OH_Drawing_Matrix* OH_Drawing_MatrixCreateRotation(float deg, float x, float y)
```

**描述**

创建一个带旋转属性的矩阵对象。<br>该矩阵对象为：单位矩阵在(x, y)旋转中心点以度为单位进行旋转后得到的矩阵。调用此函数创建的矩阵对象，在使用完毕后必须调用[OH_Drawing_MatrixDestroy](capi-drawing-matrix-h.md#oh_drawing_matrixdestroy)释放该对象占用的内存，否则会导致内存泄漏。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| float deg | 旋转的角度，单位为度。正数表示顺时针旋转，负数表示逆时针旋转。 |
| float x | 旋转中心点的x轴坐标，单位为物理像素px。 |
| float y | 旋转中心点的y轴坐标，单位为物理像素px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* | 函数返回一个指针，指针指向创建的矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)。 |

### OH_Drawing_MatrixCreateScale()

```c
OH_Drawing_Matrix* OH_Drawing_MatrixCreateScale(float sx, float sy, float px, float py)
```

**描述**

创建一个带缩放属性的矩阵对象。<br>该矩阵对象为：单位矩阵在(px, py)缩放中心点以sx和sy为缩放因子进行缩放后得到的矩阵。调用此函数创建的矩阵对象，在使用完毕后必须调用[OH_Drawing_MatrixDestroy](#oh_drawing_matrixdestroy)释放该对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| float sx | 水平缩放因子，为负数时可看作是先关于x = px作镜像翻转后再进行缩放。 |
| float sy | 垂直缩放因子，为负数时可看作是先关于y = py作镜像翻转后再进行缩放。 |
| float px | 缩放中心点的x轴坐标，单位为物理像素px。 |
| float py | 缩放中心点的y轴坐标，单位为物理像素px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* | 函数返回一个指针，指针指向创建的矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)。 |

### OH_Drawing_MatrixCreateTranslation()

```c
OH_Drawing_Matrix* OH_Drawing_MatrixCreateTranslation(float dx, float dy)
```

**描述**

创建一个带平移属性的矩阵对象。<br>该矩阵对象为：单位矩阵平移(dx, dy)后得到的矩阵。调用此函数创建的矩阵对象，在使用完毕后必须调用[OH_Drawing_MatrixDestroy](capi-drawing-matrix-h.md#oh_drawing_matrixdestroy)释放该对象占用的内存，否则会导致内存泄漏。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| float dx | 水平方向平移距离，单位为物理像素px。正数表示往x轴正方向平移，负数表示往x轴负方向平移。 |
| float dy | 垂直方向平移距离，单位为物理像素px。正数表示往y轴正方向平移，负数表示往y轴负方向平移。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* | 函数返回一个指针，指针指向创建的矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)。 |

### OH_Drawing_MatrixSetMatrix()

```c
void OH_Drawing_MatrixSetMatrix(OH_Drawing_Matrix* matrix, float scaleX, float skewX, float transX, float skewY, float scaleY, float transY, float persp0, float persp1, float persp2)
```

**描述**

用于给矩阵对象设置变换参数，包括缩放、倾斜、位移和透视系数。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>OH_Drawing_Matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

9个参数按行排列对应3×3矩阵结构：

```text
scaleX  skewX   transX
skewY   scaleY  transY
persp0  persp1  persp2
```

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象的指针。 |
| float scaleX | 水平缩放因子。 |
| float skewX | 水平倾斜系数。 |
| float transX | 水平位移系数。 |
| float skewY | 垂直倾斜系数。 |
| float scaleY | 垂直缩放因子。 |
| float transY | 垂直位移系数。 |
| float persp0 | x轴透视系数。 |
| float persp1 | y轴透视系数。 |
| float persp2 | 透视缩放系数。 |

### OH_Drawing_MatrixSetRectToRect()

```c
bool OH_Drawing_MatrixSetRectToRect(OH_Drawing_Matrix* matrix, const OH_Drawing_Rect* src, const OH_Drawing_Rect* dst, OH_Drawing_ScaleToFit stf)
```

**描述**

将矩阵以缩放方式适配目标矩形。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix、src或dst任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |
| const [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* src | 指向源矩形对象[OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)的指针。 |
| const [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* dst | 指向目标矩形对象[OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)的指针。 |
| [OH_Drawing_ScaleToFit](capi-drawing-matrix-h.md#oh_drawing_scaletofit) stf | 缩放方式，详见[OH_Drawing_ScaleToFit](#oh_drawing_scaletofit)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果设置成功，则返回true；如果设置失败，则返回false。特殊情况：<br> 如果源矩形src的宽高任意一个小于等于0，则返回false，并将矩阵设置为单位矩阵；<br> 如果目标矩形dst的宽高任意一个小于等于0，则返回true，并将矩阵设置为除透视缩放系数为1外其余值皆为0的矩阵。 |

### OH_Drawing_MatrixPreRotate()

```c
void OH_Drawing_MatrixPreRotate(OH_Drawing_Matrix* matrix, float degree, float px, float py)
```

**描述**

将矩阵设置为矩阵左乘围绕旋转中心点旋转degree指定角度的单位矩阵后得到的矩阵。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |
| float degree | 旋转角度，单位为度。正数表示顺时针旋转，负数表示逆时针旋转。 |
| float px | 旋转中心点的x轴坐标，单位为物理像素px。 |
| float py | 旋转中心点的y轴坐标，单位为物理像素px。 |

### OH_Drawing_MatrixPreScale()

```c
void OH_Drawing_MatrixPreScale(OH_Drawing_Matrix* matrix, float sx, float sy, float px, float py)
```

**描述**

将矩阵设置为矩阵左乘围绕缩放中心点按缩放因子sx和sy缩放后的单位矩阵后得到的矩阵。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |
| float sx | 水平缩放因子，为负数时可看作是先关于x = px作镜像翻转后再进行缩放。 |
| float sy | 垂直缩放因子，为负数时可看作是先关于y = py作镜像翻转后再进行缩放。 |
| float px | 缩放中心点的x轴坐标，单位为物理像素px。 |
| float py | 缩放中心点的y轴坐标，单位为物理像素px。 |

### OH_Drawing_MatrixPreTranslate()

```c
void OH_Drawing_MatrixPreTranslate(OH_Drawing_Matrix* matrix, float dx, float dy)
```

**描述**

将矩阵设置为矩阵左乘平移dx和dy距离后的单位矩阵后得到的矩阵。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |
| float dx | 水平方向平移距离，单位为物理像素px。正数表示往x轴正方向平移，负数表示往x轴负方向平移。 |
| float dy | 垂直方向平移距离，单位为物理像素px。正数表示往y轴正方向平移，负数表示往y轴负方向平移。 |

### OH_Drawing_MatrixPostRotate()

```c
void OH_Drawing_MatrixPostRotate(OH_Drawing_Matrix* matrix, float degree, float px, float py)
```

**描述**

将矩阵设置为矩阵右乘围绕旋转中心点旋转degree角度的单位矩阵后得到的矩阵。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |
| float degree | 旋转角度，单位为度。正数表示顺时针旋转，负数表示逆时针旋转。 |
| float px | 旋转中心点的x轴坐标，单位为物理像素px。 |
| float py | 旋转中心点的y轴坐标，单位为物理像素px。 |

### OH_Drawing_MatrixPostScale()

```c
void OH_Drawing_MatrixPostScale(OH_Drawing_Matrix* matrix, float sx, float sy, float px, float py)
```

**描述**

将矩阵设置为矩阵右乘围绕缩放中心点按sx和sy缩放因子缩放后的单位矩阵后得到的矩阵。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |
| float sx | 水平缩放因子，为负数时可看作是先关于x = px作镜像翻转后再进行缩放。 |
| float sy | 垂直缩放因子，为负数时可看作是先关于y = py作镜像翻转后再进行缩放。 |
| float px | 缩放中心点的x轴坐标，单位为物理像素px。 |
| float py | 缩放中心点的y轴坐标，单位为物理像素px。 |

### OH_Drawing_MatrixPostTranslate()

```c
void OH_Drawing_MatrixPostTranslate(OH_Drawing_Matrix* matrix, float dx, float dy)
```

**描述**

将矩阵设置为矩阵右乘平移dx和dy距离后的单位矩阵后得到的矩阵。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |
| float dx | 水平方向平移距离，单位为物理像素px。正数表示往x轴正方向平移，负数表示往x轴负方向平移。 |
| float dy | 垂直方向平移距离，单位为物理像素px。正数表示往y轴正方向平移，负数表示往y轴负方向平移。 |

### OH_Drawing_MatrixReset()

```c
void OH_Drawing_MatrixReset(OH_Drawing_Matrix* matrix)
```

**描述**

重置当前矩阵为单位矩阵。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |

### OH_Drawing_MatrixConcat()

```c
void OH_Drawing_MatrixConcat(OH_Drawing_Matrix* total, const OH_Drawing_Matrix* a, const OH_Drawing_Matrix* b)
```

**描述**

将矩阵total设置为矩阵a乘以矩阵b。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>total、a或b任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* total | 指向最终的矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |
| const [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* a | 指向矩阵对象a[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |
| const [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* b | 指向矩阵对象b[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |

### OH_Drawing_MatrixGetAll()

```c
OH_Drawing_ErrorCode OH_Drawing_MatrixGetAll(OH_Drawing_Matrix* matrix, float value[9])
```

**描述**

获取矩阵所有元素值。9个元素按行主序存储，对应3×3矩阵结构，具体排列方式参见[OH_Drawing_MatrixSetMatrix](#oh_drawing_matrixsetmatrix)。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |
| float value[9] | 用于存储得到的矩阵元素值的数组，数组长度必须大于等于9，9个元素按行排列依次对应3×3矩阵的scaleX、skewX、transX、skewY、scaleY、transY、persp0、persp1、persp2。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 返回错误码。<br> 返回OH_DRAWING_SUCCESS，表示成功获取矩阵的所有元素值。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示matrix或value为NULL。 |

### OH_Drawing_MatrixGetValue()

```c
float OH_Drawing_MatrixGetValue(OH_Drawing_Matrix* matrix, int index)
```

**描述**

获取矩阵给定索引位的值。索引范围0-8。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>index小于0或者大于8时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |
| int index | 索引位置，范围0-8。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 函数返回矩阵给定索引位对应的值。 |

### OH_Drawing_MatrixRotate()

```c
void OH_Drawing_MatrixRotate(OH_Drawing_Matrix* matrix, float degree, float px, float py)
```

**描述**

设置矩阵为单位矩阵，并围绕位于(px, py)的旋转中心点进行旋转。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |
| float degree | 角度，单位为度。正数表示顺时针旋转，负数表示逆时针旋转。 |
| float px | 旋转中心点的x轴坐标，单位为物理像素px。 |
| float py | 旋转中心点的y轴坐标，单位为物理像素px。 |

### OH_Drawing_MatrixTranslate()

```c
void OH_Drawing_MatrixTranslate(OH_Drawing_Matrix* matrix, float dx, float dy)
```

**描述**

设置矩阵为单位矩阵，并平移(dx, dy)。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |
| float dx | 水平方向平移距离，单位为物理像素px。正数表示往x轴正方向平移，负数表示往x轴负方向平移。 |
| float dy | 垂直方向平移距离，单位为物理像素px。正数表示往y轴正方向平移，负数表示往y轴负方向平移。 |

### OH_Drawing_MatrixScale()

```c
void OH_Drawing_MatrixScale(OH_Drawing_Matrix* matrix, float sx, float sy, float px, float py)
```

**描述**

设置矩阵为单位矩阵，并围绕位于(px, py)的缩放中心点，以sx和sy进行缩放。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |
| float sx | 水平缩放因子，为负数时可看作是先关于x = px作镜像翻转后再进行缩放。 |
| float sy | 垂直缩放因子，为负数时可看作是先关于y = py作镜像翻转后再进行缩放。 |
| float px | 缩放中心点的x轴坐标，单位为物理像素px。 |
| float py | 缩放中心点的y轴坐标，单位为物理像素px。 |

### OH_Drawing_MatrixInvert()

```c
bool OH_Drawing_MatrixInvert(OH_Drawing_Matrix* matrix, OH_Drawing_Matrix* inverse)
```

**描述**

将矩阵inverse设置为矩阵的逆矩阵，并返回结果。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix或inverse任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* inverse | 指向逆矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针，开发者可调用[OH_Drawing_MatrixCreate](capi-drawing-matrix-h.md#oh_drawing_matrixcreate)接口创建。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 函数返回true表示矩阵可逆，inverse被填充为逆矩阵；函数返回false表示矩阵不可逆，inverse不被改变。 |

### OH_Drawing_MatrixSetPolyToPoly()

```c
bool OH_Drawing_MatrixSetPolyToPoly(OH_Drawing_Matrix* matrix, const OH_Drawing_Point2D* src, const OH_Drawing_Point2D* dst, uint32_t count)
```

**描述**

通过设置源点以及目标点，生成对应的变换矩阵。<br>源点以及目标点的个数要大于等于0，小于等于4。本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>count小于0或者大于4时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |
| const [OH_Drawing_Point2D](capi-drawing-oh-drawing-point2d.md)* src | 源点数组，为NULL时count应当为0。 |
| const [OH_Drawing_Point2D](capi-drawing-oh-drawing-point2d.md)* dst | 目标点数组，个数要与源点相等，为NULL时count应当为0。 |
| uint32_t count | 源点数组以及目标点数组的个数，取值范围为[0, 4]，为0时将矩阵对象设为单位矩阵。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 函数返回是否可以生成对应矩阵用来完成变换。true表示矩阵生成成功，false表示无法生成对应矩阵。 |

### OH_Drawing_MatrixMapPoints()

```c
void OH_Drawing_MatrixMapPoints(const OH_Drawing_Matrix* matrix, const OH_Drawing_Point2D* src, OH_Drawing_Point2D* dst, int count)
```

**描述**

通过矩阵变换将源点数组映射到目标点数组。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix、src或dst任意一个为NULL或者count小于等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |
| const [OH_Drawing_Point2D](capi-drawing-oh-drawing-point2d.md)* src | 源点数组，数组长度应大于等于count，否则可能导致越界访问。 |
| [OH_Drawing_Point2D](capi-drawing-oh-drawing-point2d.md)* dst | 目标点数组，数组长度应大于等于count，否则可能导致越界访问。 |
| int count | 源点数组以及目标点数组的个数，必须大于0。 |

### OH_Drawing_MatrixMapRect()

```c
bool OH_Drawing_MatrixMapRect(const OH_Drawing_Matrix* matrix, const OH_Drawing_Rect* src, OH_Drawing_Rect* dst)
```

**描述**

将目标矩形设置为一个新的矩形，该矩形是能够包围源矩形的四个顶点通过矩阵变换映射后形成的新顶点的最小矩形。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix、src或dst任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |
| const [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* src | 指向源矩形[OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)的指针。 |
| [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* dst | 指向目标矩形[OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)的指针，用于存储映射后的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 函数返回源矩形与映射后的目标矩形是否相等。true表示相等，false表示不相等。 |

### OH_Drawing_MatrixIsEqual()

```c
bool OH_Drawing_MatrixIsEqual(OH_Drawing_Matrix* matrix, OH_Drawing_Matrix* other)
```

**描述**

判断两个矩阵是否相等。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix或other任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向用于判断的其中一个矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* other | 指向用于判断的另一个矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 函数返回两个矩阵的比较结果，返回true表示两个矩阵相等，返回false表示两个矩阵不相等。 |

### OH_Drawing_MatrixIsIdentity()

```c
bool OH_Drawing_MatrixIsIdentity(OH_Drawing_Matrix* matrix)
```

**描述**

判断矩阵是否是单位矩阵。单位矩阵为：`[1 0 0; 0 1 0; 0 0 1]`。<br>如需判断两个矩阵是否相等，请使用[OH_Drawing_MatrixIsEqual](#oh_drawing_matrixisequal)。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 函数返回true表示矩阵是单位矩阵，函数返回false表示矩阵不是单位矩阵。 |

### OH_Drawing_MatrixDestroy()

```c
void OH_Drawing_MatrixDestroy(OH_Drawing_Matrix* matrix)
```

**描述**

用于销毁矩阵对象并回收该对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象的指针。 |


### OH_Drawing_MatrixPreConcat()

```c
OH_Drawing_ErrorCode OH_Drawing_MatrixPreConcat(OH_Drawing_Matrix* a, OH_Drawing_Matrix* b)
```

**描述**

对矩阵a左乘矩阵b。与[OH_Drawing_MatrixConcat](#oh_drawing_matrixconcat)功能类似，区别在于OH_Drawing_MatrixConcat将结果存入单独的total矩阵，而本方法直接修改矩阵a。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* a | 指向被左乘的矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针，左乘后该矩阵会被修改为a × b的结果。 |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* b | 指向作为乘数的矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 返回错误码。<br>返回OH_DRAWING_SUCCESS，表示成功执行左乘方法。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示a或b为NULL。 |

### OH_Drawing_MatrixIsAffine()

```c
OH_Drawing_ErrorCode OH_Drawing_MatrixIsAffine(const OH_Drawing_Matrix* matrix, bool* isAffine)
```

**描述**

判断当前矩阵是否为仿射矩阵。仿射矩阵是一种包括平移、旋转或缩放等变换的矩阵。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |
| bool* isAffine | 表示当前矩阵是否为仿射矩阵。作为出参使用。true表示当前矩阵是仿射矩阵，false表示当前矩阵不是仿射矩阵。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行结果。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示matrix或isAffine为NULL。 |

### OH_Drawing_MatrixPreSkew()

```c
OH_Drawing_ErrorCode OH_Drawing_MatrixPreSkew(OH_Drawing_Matrix* matrix, float kx, float ky, float px, float py)
```

**描述**

将当前矩阵左乘一个以(px, py)为中心按(kx, ky)倾斜构造的矩阵。与[OH_Drawing_MatrixPreRotate](#oh_drawing_matrixprerotate)、[OH_Drawing_MatrixPreScale](#oh_drawing_matrixprescale)、[OH_Drawing_MatrixPreTranslate](#oh_drawing_matrixpretranslate)同属Pre系列方法。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |
| float kx | 表示x轴上的倾斜量。 |
| float ky | 表示y轴上的倾斜量。 |
| float px | 表示倾斜中心点的x轴坐标，单位为物理像素px。 |
| float py | 表示倾斜中心点的y轴坐标，单位为物理像素px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行结果。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示matrix为NULL。 |

### OH_Drawing_MatrixRectStaysRect()

```c
OH_Drawing_ErrorCode OH_Drawing_MatrixRectStaysRect(const OH_Drawing_Matrix* matrix, bool* isRectStaysRect)
```

**描述**

判断矩形经过当前矩阵映射后是否仍保持矩形形状。当矩阵是单位矩阵或仅包含平移、缩放、旋转90度倍数这类仿射变换时满足该条件。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |
| bool* isRectStaysRect | 表示经过该矩阵映射后的矩形的形状是否仍为矩形。作为出参使用。<br>true表示映射后的矩形形状是矩形，false表示映射后的矩形形状不是矩形。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行结果。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示matrix或isRectStaysRect为NULL。 |

### OH_Drawing_MatrixSetSinCos()

```c
OH_Drawing_ErrorCode OH_Drawing_MatrixSetSinCos(OH_Drawing_Matrix* matrix, float sinValue, float cosValue, float px, float py)
```

**描述**

设置矩阵，使其围绕旋转中心 (px, py) 以指定的正弦值和余弦值进行旋转。与[OH_Drawing_MatrixRotate](#oh_drawing_matrixrotate)功能类似，区别在于OH_Drawing_MatrixRotate直接传入角度值，而本方法传入正弦值和余弦值。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针。 |
| float sinValue | 表示旋转角度的正弦值。 |
| float cosValue | 表示旋转角度的余弦值。 |
| float px | 表示旋转中心的x轴坐标。 |
| float py | 表示旋转中心的y轴坐标。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行结果。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示matrix为NULL。 |
