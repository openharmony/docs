# drawing_path_effect.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @dreamyhhh-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## 概述

文件中定义了与路径效果相关的功能函数。路径效果是对绘制路径进行几何变换的效果处理机制，在路径绘制到画布之前对路径的几何形状进行修改，例如将尖角变为圆角、将连续路径变为虚线等。多个路径效果可以通过组合（按顺序依次应用）或叠加（各自独立应用后合并结果）的方式一起使用。支持创建组合路径效果、圆角路径效果、虚线路径效果、打散路径效果、叠加路径效果等。<br>本模块为单线程模型策略，需要调用方自行管理线程安全和上下文状态的切换。

**引用文件：** \<native_drawing/drawing_path_effect.h\>

**库：** libnative_drawing.so

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_PathDashStyle](#oh_drawing_pathdashstyle) | OH_Drawing_PathDashStyle | 路径效果的绘制样式枚举。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_PathEffect* OH_Drawing_CreateComposePathEffect(OH_Drawing_PathEffect* outer, OH_Drawing_PathEffect* inner)](#oh_drawing_createcomposepatheffect) | 创建路径组合的路径效果对象。首先应用内部路径效果，然后应用外部路径效果。使用完毕后必须调用[OH_Drawing_PathEffectDestroy](#oh_drawing_patheffectdestroy)销毁该路径效果对象，否则会导致内存泄漏。 |
| [OH_Drawing_PathEffect* OH_Drawing_CreateCornerPathEffect(float radius)](#oh_drawing_createcornerpatheffect) | 创建一个将路径的夹角变成指定半径的圆角的路径效果对象。该路径效果会检测路径中的夹角（拐点），并将尖角替换为指定半径的圆弧，使路径在拐点处平滑过渡。使用完毕后必须调用[OH_Drawing_PathEffectDestroy](#oh_drawing_patheffectdestroy)销毁该路径效果对象，否则会导致内存泄漏。 |
| [OH_Drawing_PathEffect* OH_Drawing_CreateDashPathEffect(float* intervals, int count, float phase)](#oh_drawing_createdashpatheffect) | 创建一个虚线效果的路径效果对象。虚线效果由一组虚线开的间隔、虚线关的间隔数据决定。使用完毕后必须调用[OH_Drawing_PathEffectDestroy](#oh_drawing_patheffectdestroy)销毁该路径效果对象，否则会导致内存泄漏。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>intervals为nullptr或count小于等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [OH_Drawing_PathEffect* OH_Drawing_CreateDiscretePathEffect(float segLength, float deviation)](#oh_drawing_creatediscretepatheffect) | 创建一种将路径打散并且在路径上产生不规则分布的路径效果对象。该路径效果按照segLength将路径分割为多个线段，并对每个线段的末端点在deviation范围内进行随机偏移，从而产生不规则分布的视觉效果。使用完毕后必须调用[OH_Drawing_PathEffectDestroy](#oh_drawing_patheffectdestroy)销毁该路径效果对象，否则会导致内存泄漏。 |
| [OH_Drawing_PathEffect* OH_Drawing_CreatePathDashEffect(const OH_Drawing_Path* path, float advance, float phase, OH_Drawing_PathDashStyle type)](#oh_drawing_createpathdasheffect) | 创建一个虚线效果的路径效果对象，使用指定路径作为虚线段样式，按照advance指定的步长沿目标路径重复排列。与[OH_Drawing_CreateDashPathEffect](#oh_drawing_createdashpatheffect)使用虚线间隔数组控制开关不同，本接口使用指定路径作为虚线段形状。使用完毕后必须调用[OH_Drawing_PathEffectDestroy](#oh_drawing_patheffectdestroy)销毁该路径效果对象，否则会导致内存泄漏。 |
| [OH_Drawing_PathEffect* OH_Drawing_CreateSumPathEffect(OH_Drawing_PathEffect* firstPathEffect, OH_Drawing_PathEffect* secondPathEffect)](#oh_drawing_createsumpatheffect) | 创建一个使用两种路径效果叠加的路径效果对象。与[OH_Drawing_CreateComposePathEffect](#oh_drawing_createcomposepatheffect)的先后顺序应用不同，本接口将两种路径效果各自独立应用后将结果叠加。使用完毕后必须调用[OH_Drawing_PathEffectDestroy](#oh_drawing_patheffectdestroy)销毁该路径效果对象，否则会导致内存泄漏。 |
| [void OH_Drawing_PathEffectDestroy(OH_Drawing_PathEffect* pathEffect)](#oh_drawing_patheffectdestroy) | 销毁路径效果对象，并回收该对象占用的内存。路径效果对象使用完毕后必须调用此方法，否则会导致内存泄漏。 |

## 枚举类型说明

### OH_Drawing_PathDashStyle

```c
enum OH_Drawing_PathDashStyle
```

**描述**

路径效果的绘制样式枚举。

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| DRAWING_PATH_DASH_STYLE_TRANSLATE | 表示虚线段沿路径平移绘制，不发生旋转或变形。 |
| DRAWING_PATH_DASH_STYLE_ROTATE | 表示虚线段沿路径旋转，使其方向跟随路径切线方向。 |
| DRAWING_PATH_DASH_STYLE_MORPH | 表示虚线段沿路径发生变形，以适应路径走向。 |


## 函数说明

### OH_Drawing_CreateComposePathEffect()

```c
OH_Drawing_PathEffect* OH_Drawing_CreateComposePathEffect(OH_Drawing_PathEffect* outer, OH_Drawing_PathEffect* inner)
```

**描述**

创建路径组合的路径效果对象。首先应用内部路径效果，然后应用外部路径效果。使用完毕后必须调用[OH_Drawing_PathEffectDestroy](#oh_drawing_patheffectdestroy)销毁该路径效果对象，否则会导致内存泄漏。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)* outer | 表示组合路径效果中外部路径效果[OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)的指针。 |
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)* inner | 表示组合路径效果中内部路径效果[OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)* | 返回指向创建的路径效果对象[OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)的指针。<br> 如果返回nullptr，则创建失败，原因是outer或者inner为nullptr。 |

### OH_Drawing_CreateCornerPathEffect()

```c
OH_Drawing_PathEffect* OH_Drawing_CreateCornerPathEffect(float radius)
```

**描述**

创建一个将路径的夹角变成指定半径的圆角的路径效果对象。该路径效果会检测路径中的夹角（拐点），并将尖角替换为指定半径的圆弧，使路径在拐点处平滑过渡。使用完毕后必须调用[OH_Drawing_PathEffectDestroy](#oh_drawing_patheffectdestroy)销毁该路径效果对象，否则会导致内存泄漏。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| float radius | 表示圆角的半径，取值范围>0，单位为物理像素px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)* | 返回指向创建的路径效果对象[OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)的指针。<br> 如果返回nullptr，则创建失败，原因是radius小于等于0。 |

### OH_Drawing_CreateDashPathEffect()

```c
OH_Drawing_PathEffect* OH_Drawing_CreateDashPathEffect(float* intervals, int count, float phase)
```

**描述**

创建一个虚线效果的路径效果对象。虚线效果由一组虚线开的间隔、虚线关的间隔数据决定。使用完毕后必须调用[OH_Drawing_PathEffectDestroy](#oh_drawing_patheffectdestroy)销毁该路径效果对象，否则会导致内存泄漏。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>intervals为nullptr或count小于等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| float* intervals | 虚线间隔数组首地址，偶数项的值表示虚线可见段（开）的间隔长度，奇数项的值表示虚线间隙段（关）的间隔长度，单位为物理像素px。 |
| int count | 虚线间隔数组元素的个数，取值范围>0，且为偶数。 |
| float phase | 虚线间隔数组中的偏移量，用于控制虚线绘制的起始位置，单位为物理像素px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)* | 返回指向创建的路径效果对象[OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)的指针。 |

### OH_Drawing_CreateDiscretePathEffect()

```c
OH_Drawing_PathEffect* OH_Drawing_CreateDiscretePathEffect(float segLength, float deviation)
```

**描述**

创建一种将路径打散并且在路径上产生不规则分布的路径效果对象。该路径效果按照segLength将路径分割为多个线段，并对每个线段的末端点在deviation范围内进行随机偏移，从而产生不规则分布的视觉效果。使用完毕后必须调用[OH_Drawing_PathEffectDestroy](#oh_drawing_patheffectdestroy)销毁该路径效果对象，否则会导致内存泄漏。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| float segLength | 表示路径中每进行一次打散操作的长度，取值范围>0，单位为物理像素px。 |
| float deviation | 表示绘制时的末端点的最大移动偏离量，单位为物理像素px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)* | 返回指向创建的路径效果对象[OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)的指针。 |

### OH_Drawing_CreatePathDashEffect()

```c
OH_Drawing_PathEffect* OH_Drawing_CreatePathDashEffect(const OH_Drawing_Path* path, float advance, float phase, OH_Drawing_PathDashStyle type)
```

**描述**

创建一个虚线效果的路径效果对象，使用指定路径作为虚线段样式，按照advance指定的步长沿目标路径重复排列。与[OH_Drawing_CreateDashPathEffect](#oh_drawing_createdashpatheffect)使用虚线间隔数组控制开关不同，本接口使用指定路径作为虚线段形状。使用完毕后必须调用[OH_Drawing_PathEffectDestroy](#oh_drawing_patheffectdestroy)销毁该路径效果对象，否则会导致内存泄漏。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 表示虚线样式的路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| float advance | 表示虚线段的步长，取值范围>0，单位为物理像素px。 |
| float phase | 表示虚线样式的起始偏移量，用于控制虚线段绘制的起始位置，单位为物理像素px。 |
| [OH_Drawing_PathDashStyle](#oh_drawing_pathdashstyle) type | 表示虚线路径效果样式，取值见[OH_Drawing_PathDashStyle](#oh_drawing_pathdashstyle)枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)* | 返回指向创建的路径效果对象[OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)的指针。<br> 如果返回nullptr，则创建失败，原因是path为nullptr或者advance小于等于0。 |

### OH_Drawing_CreateSumPathEffect()

```c
OH_Drawing_PathEffect* OH_Drawing_CreateSumPathEffect(OH_Drawing_PathEffect* firstPathEffect, OH_Drawing_PathEffect* secondPathEffect)
```

**描述**

创建一个使用两种路径效果叠加的路径效果对象。与[OH_Drawing_CreateComposePathEffect](#oh_drawing_createcomposepatheffect)的先后顺序应用不同，本接口将两种路径效果各自独立应用后将结果叠加。使用完毕后必须调用[OH_Drawing_PathEffectDestroy](#oh_drawing_patheffectdestroy)销毁该路径效果对象，否则会导致内存泄漏。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)* firstPathEffect | 表示参与叠加的第一个路径效果对象[OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)的指针。 |
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)* secondPathEffect | 表示参与叠加的第二个路径效果对象[OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)* | 返回指向创建的路径效果对象[OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)的指针。<br> 如果返回nullptr，则创建失败，原因是firstPathEffect或者secondPathEffect为nullptr。 |

### OH_Drawing_PathEffectDestroy()

```c
void OH_Drawing_PathEffectDestroy(OH_Drawing_PathEffect* pathEffect)
```

**描述**

销毁路径效果对象，并回收该对象占用的内存。路径效果对象使用完毕后必须调用此方法，否则会导致内存泄漏。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)* pathEffect | 指向需要销毁的路径效果对象[OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)的指针。 |

