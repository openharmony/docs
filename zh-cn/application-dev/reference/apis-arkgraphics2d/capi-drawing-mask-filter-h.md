# drawing_mask_filter.h

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphic-->
<!--Owner: @hangmengxin-->
<!--Designer: @wangyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## 概述

声明与绘图模块中的对象相关的函数。

**引用文件：** <native_drawing/drawing_mask_filter.h>

**库：** libnative_drawing.so

**起始版本：** 11

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_BlurType](#oh_drawing_blurtype) | OH_Drawing_BlurType | 蒙版滤波器模糊操作类型的枚举。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_MaskFilter* OH_Drawing_MaskFilterCreateBlur(OH_Drawing_BlurType blurType, float sigma, bool respectCTM)](#oh_drawing_maskfiltercreateblur) | 创建具有模糊效果的蒙版滤波器。 |
| [void OH_Drawing_MaskFilterDestroy(OH_Drawing_MaskFilter* maskFilter)](#oh_drawing_maskfilterdestroy) | 销毁蒙版滤波器对象，并收回该对象占用的内存。 |

## 枚举类型说明

### OH_Drawing_BlurType

```
enum OH_Drawing_BlurType
```

**描述**

蒙版滤波器模糊操作类型的枚举。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| NORMAL | 内外模糊。 |
| SOLID | 内部实体，外部模糊。 |
| OUTER | 内部空白，外部模糊。 |
| INNER | 内部模糊，外部空白。 |


## 函数说明

### OH_Drawing_MaskFilterCreateBlur()

```
OH_Drawing_MaskFilter* OH_Drawing_MaskFilterCreateBlur(OH_Drawing_BlurType blurType, float sigma, bool respectCTM)
```

**描述**

创建具有模糊效果的蒙版滤波器。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_BlurType](#oh_drawing_blurtype) blurType | 表示模糊类型。 |
| float sigma | 表示要应用的高斯模糊的标准偏差。必须大于0。 |
| bool respectCTM | 表示模糊标准差值被CTM修改，默认为真。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_MaskFilter](capi-drawing-oh-drawing-maskfilter.md)* | 返回创建的蒙版滤波器对象的指针。 |

### OH_Drawing_MaskFilterDestroy()

```
void OH_Drawing_MaskFilterDestroy(OH_Drawing_MaskFilter* maskFilter)
```

**描述**

销毁蒙版滤波器对象，并收回该对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_MaskFilter](capi-drawing-oh-drawing-maskfilter.md)* maskFilter | 表示指向蒙版滤波器对象的指针。 |


