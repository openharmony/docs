# drawing_lattice.h

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphic-->
<!--Owner: @dreamyhhh-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## 概述

声明与矩形网格对象相关的函数。矩形网格（Lattice）用于将图像划分为固定区域和可缩放区域，解决图像缩放时关键区域变形的问题，保持关键区域清晰不变形的同时实现其余区域的灵活缩放。固定区域在目标网格足够大时以原始大小绘制，目标网格太小时按比例缩小以适应目标网格，其余区域缩放以适应剩余空间。<br>本模块为单线程模型策略，需要调用方自行管理线程安全和上下文状态的切换。

**引用文件：** \<native_drawing/drawing_lattice.h\>

**库：** libnative_drawing.so

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 23

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_LatticeRectType](#oh_drawing_latticerecttype) | OH_Drawing_LatticeRectType | 定义填充网格的矩形类型的枚举。仅在矩形网格对象中使用。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_ErrorCode OH_Drawing_LatticeDestroy(OH_Drawing_Lattice* lattice)](#oh_drawing_latticedestroy) | 用于销毁由[OH_Drawing_LatticeCreate()](#oh_drawing_latticecreate)创建的矩形网格对象并回收该对象占用的内存。与[OH_Drawing_LatticeCreate()](#oh_drawing_latticecreate)配对使用。 |
| [OH_Drawing_ErrorCode OH_Drawing_LatticeCreate(const int* xDivs, const int* yDivs, uint32_t xCount, uint32_t yCount, const OH_Drawing_Rect* bounds, const OH_Drawing_LatticeRectType* rectTypes, uint32_t rectTypeCount, const uint32_t* colors, uint32_t colorCount, OH_Drawing_Lattice** lattice)](#oh_drawing_latticecreate) | 创建矩形网格对象。将图像划分为矩形网格，同时处于偶数列（列索引为偶数，即第0、2、4…列）和偶数行（行索引为偶数，即第0、2、4…行）上的网格是固定的，如果目标网格足够大，则这些固定网格以其原始大小进行绘制。如果目标网格太小，无法容纳这些固定网格，则所有固定网格都会按比例缩小以适应目标网格。其余网格将进行缩放，以适应剩余的空间。 |

## 枚举类型说明

### OH_Drawing_LatticeRectType

```c
enum OH_Drawing_LatticeRectType
```

**描述**

定义填充网格的矩形类型的枚举，决定对应网格单元格的渲染方式。

**起始版本：** 23

| 枚举项 | 描述 |
| -- | -- |
| DEFAULT | 将图像绘制到矩形网格中。 |
| TRANSPARENT | 将矩形网格设置为透明的。 |
| FIXED_COLOR | 将矩形网格对象中fColors数组的颜色绘制到矩形网格中。 |


## 函数说明

### OH_Drawing_LatticeDestroy()

```c
OH_Drawing_ErrorCode OH_Drawing_LatticeDestroy(OH_Drawing_Lattice* lattice)
```

**描述**

用于销毁由[OH_Drawing_LatticeCreate()](#oh_drawing_latticecreate)创建的矩形网格对象并回收该对象占用的内存。与[OH_Drawing_LatticeCreate()](#oh_drawing_latticecreate)配对使用。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Lattice](capi-drawing-oh-drawing-lattice.md)* lattice | 指向由[OH_Drawing_LatticeCreate()](#oh_drawing_latticecreate)创建的矩形网格对象[OH_Drawing_Lattice](capi-drawing-oh-drawing-lattice.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行结果。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示lattice是空指针。 |

### OH_Drawing_LatticeCreate()

```c
OH_Drawing_ErrorCode OH_Drawing_LatticeCreate(const int* xDivs, const int* yDivs, uint32_t xCount, uint32_t yCount, const OH_Drawing_Rect* bounds, const OH_Drawing_LatticeRectType* rectTypes, uint32_t rectTypeCount, const uint32_t* colors, uint32_t colorCount, OH_Drawing_Lattice** lattice)
```

**描述**

创建矩形网格对象。将图像划分为矩形网格，同时处于偶数列（列索引为偶数，即第0、2、4…列）和偶数行（行索引为偶数，即第0、2、4…行）上的网格是固定的，如果目标网格足够大，则这些固定网格以其原始大小进行绘制。如果目标网格太小，无法容纳这些固定网格，则所有固定网格都会按比例缩小以适应目标网格。其余网格将进行缩放，以适应剩余的空间。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const int* xDivs | 用于划分图像的X坐标值数组，数组元素需为整数，单位为物理像素px，且不能为空指针。 |
| const int* yDivs | 用于划分图像的Y坐标值数组，数组元素需为整数，单位为物理像素px，且不能为空指针。 |
| uint32_t xCount | X坐标值数组的大小。取值范围为[0, 5]。 |
| uint32_t yCount | Y坐标值数组的大小。取值范围为[0, 5]。 |
| [const OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* bounds | 要绘制的原始边界矩形。当需要指定不同于原始图像的绘制边界时传入此参数，不传入（空指针）时默认使用原始图像矩形大小。矩形坐标值应为整数，单位为物理像素px，非整数值将被向下取整。 |
| [const OH_Drawing_LatticeRectType](#oh_drawing_latticerecttype)* rectTypes | 填充网格的矩形类型数组，枚举值必须在有效范围内。如果rectTypes为空指针，表示不指定填充类型，所有网格区域默认按DEFAULT方式绘制图像，rectTypeCount必须为0。 |
| uint32_t rectTypeCount | rectTypes数组的大小。如果rectTypes不是空指针，数组大小必须等于`(xCount + 1)*(yCount + 1)`。<br>如果rectTypes是空指针，数组大小必须等于0。 |
| const uint32_t* colors | 填充网格的颜色数组，颜色值为ARGB格式（0xAARRGGBB）。当rectTypes中包含FIXED_COLOR时，colors中对应位置的颜色会被绘制到对应矩形网格中，且colors不能为空指针。当rectTypes不包含FIXED_COLOR且colors为空指针时，默认不使用自定义颜色填充网格。 |
| uint32_t colorCount | colors数组的大小。如果colors不是空指针，数组大小必须等于`(xCount + 1)*(yCount + 1)`。<br>如果colors是空指针，数组大小必须等于0。 |
| [OH_Drawing_Lattice](capi-drawing-oh-drawing-lattice.md)** lattice | 指向矩形网格对象[OH_Drawing_Lattice](capi-drawing-oh-drawing-lattice.md)的二级指针，作为出参，返回给调用者，且不能为空指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行结果。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，有以下可能原因：<br>- xDivs或yDivs是空指针nullptr；<br>- rectTypes不是空指针，且rectTypeCount不等于`(xCount + 1)*(yCount + 1)`。<br>- colors不是空指针，且colorCount不等于`(xCount + 1)*(yCount + 1)`。<br>- rectTypes是空指针，且rectTypeCount不等于0。<br>- colors是空指针，且colorCount不等于0。<br>- lattice是空指针。<br>返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE，表示rectTypes中的枚举值超过枚举范围。 |