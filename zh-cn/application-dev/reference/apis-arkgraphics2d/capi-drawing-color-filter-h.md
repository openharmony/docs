# drawing_color_filter.h

## 概述

声明与绘图模块中的颜色滤波器对象相关的函数。

**引用文件：** drawing_color_filter.h

**库：** libnative_drawing.so

**起始版本：** 11

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateBlendMode(uint32_t color, OH_Drawing_BlendMode blendMode)](#oh_drawing_colorfiltercreateblendmode) | 创建具有混合模式的颜色滤波器。 |
| [OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateCompose(OH_Drawing_ColorFilter* outerColorFilter,OH_Drawing_ColorFilter* innerColorFilter)](#oh_drawing_colorfiltercreatecompose) | 将两个颜色滤波器合成一个新的颜色滤波器。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>outerColorFilter、innerColorFilter任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateMatrix(const float matrix[20])](#oh_drawing_colorfiltercreatematrix) | 创建具有5x4颜色矩阵的颜色滤波器。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateLinearToSrgbGamma(void)](#oh_drawing_colorfiltercreatelineartosrgbgamma) | 创建一个从线性颜色空间转换到SRGB颜色空间的颜色滤波器。 |
| [OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateSrgbGammaToLinear(void)](#oh_drawing_colorfiltercreatesrgbgammatolinear) | 创建颜色滤波器将RGB颜色通道应用于SRGB的伽玛曲线。 |
| [OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateLuma(void)](#oh_drawing_colorfiltercreateluma) | 创建一个颜色滤波器将其输入的亮度值乘以透明度通道，并将红色、绿色和蓝色通道设置为零。 |
| [OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateLighting(uint32_t mulColor, uint32_t addColor)](#oh_drawing_colorfiltercreatelighting) | 创建一个光照颜色滤波器，此滤波器会将RGB通道的颜色值乘以一种颜色值并加上另一种颜色值，计算结果会被限制在0到255范围内。 |
| [void OH_Drawing_ColorFilterDestroy(OH_Drawing_ColorFilter* colorFilter)](#oh_drawing_colorfilterdestroy) | 销毁颜色滤波器对象，并收回该对象占用的内存。 |

## 函数说明

### OH_Drawing_ColorFilterCreateBlendMode()

```
OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateBlendMode(uint32_t color, OH_Drawing_BlendMode blendMode)
```

**描述**

创建具有混合模式的颜色滤波器。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint32_t color | 表示颜色，是一个32位（ARGB）变量。 |
| [OH_Drawing_BlendMode](capi-drawing-types-h.md#oh_drawing_blendmode) blendMode | 表示混合模式。支持可选的混合模式具体可见[OH_Drawing_BlendMode](capi-drawing-types-h.md#oh_drawing_blendmode)枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ColorFilter](capi-oh-drawing-colorfilter.md)* | 返回创建的颜色滤波器对象的指针。 |

### OH_Drawing_ColorFilterCreateCompose()

```
OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateCompose(OH_Drawing_ColorFilter* outerColorFilter,OH_Drawing_ColorFilter* innerColorFilter)
```

**描述**

将两个颜色滤波器合成一个新的颜色滤波器。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>outerColorFilter、innerColorFilter任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_ColorFilter](capi-oh-drawing-colorfilter.md)* outerColorFilter | 指向颜色滤波器对象一的指针。 |
| [OH_Drawing_ColorFilter](capi-oh-drawing-colorfilter.md)* innerColorFilter | 指向颜色滤波器对象二的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ColorFilter](capi-oh-drawing-colorfilter.md)* | 返回创建的颜色滤波器对象的指针。 |

### OH_Drawing_ColorFilterCreateMatrix()

```
OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateMatrix(const float matrix[20])
```

**描述**

创建具有5x4颜色矩阵的颜色滤波器。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| matrix |  表示矩阵，以长度为20的浮点数组表示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ColorFilter](capi-oh-drawing-colorfilter.md)* | 返回创建的颜色滤波器对象的指针。 |

### OH_Drawing_ColorFilterCreateLinearToSrgbGamma()

```
OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateLinearToSrgbGamma(void)
```

**描述**

创建一个从线性颜色空间转换到SRGB颜色空间的颜色滤波器。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ColorFilter](capi-oh-drawing-colorfilter.md)* | 返回创建的颜色滤波器对象的指针。 |

### OH_Drawing_ColorFilterCreateSrgbGammaToLinear()

```
OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateSrgbGammaToLinear(void)
```

**描述**

创建颜色滤波器将RGB颜色通道应用于SRGB的伽玛曲线。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ColorFilter](capi-oh-drawing-colorfilter.md)* | 返回创建的颜色滤波器对象的指针。 |

### OH_Drawing_ColorFilterCreateLuma()

```
OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateLuma(void)
```

**描述**

创建一个颜色滤波器将其输入的亮度值乘以透明度通道，并将红色、绿色和蓝色通道设置为零。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ColorFilter](capi-oh-drawing-colorfilter.md)* | 返回创建的颜色滤波器对象的指针。 |

### OH_Drawing_ColorFilterCreateLighting()

```
OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateLighting(uint32_t mulColor, uint32_t addColor)
```

**描述**

创建一个光照颜色滤波器，此滤波器会将RGB通道的颜色值乘以一种颜色值并加上另一种颜色值，计算结果会被限制在0到255范围内。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint32_t mulColor | 用来乘法运算的颜色值。 |
| uint32_t addColor | 用来加法运算的颜色值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ColorFilter](capi-oh-drawing-colorfilter.md)* | 返回创建的颜色滤波器对象的指针。 |

### OH_Drawing_ColorFilterDestroy()

```
void OH_Drawing_ColorFilterDestroy(OH_Drawing_ColorFilter* colorFilter)
```

**描述**

销毁颜色滤波器对象，并收回该对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_ColorFilter](capi-oh-drawing-colorfilter.md)* colorFilter | 表示指向颜色滤波器对象的指针。 |


