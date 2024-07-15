# drawing_color_filter.h


## 概述

声明与绘图模块中的颜色滤波器对象相关的函数。

**引用文件：**&lt;native_drawing/drawing_color_filter.h&gt;

**库：** libnative_drawing.so

**起始版本：** 11

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateBlendMode](_drawing.md#oh_drawing_colorfiltercreateblendmode) (uint32_t color, [OH_Drawing_BlendMode](_drawing.md#oh_drawing_blendmode)) | 创建具有混合模式的颜色滤波器。 | 
| [OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateCompose](_drawing.md#oh_drawing_colorfiltercreatecompose) ([OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) \*colorFilter1, [OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) \*colorFilter2) | 将两个颜色滤波器合成一个新的颜色滤波器。 | 
| [OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateMatrix](_drawing.md#oh_drawing_colorfiltercreatematrix) (const float matrix[20]) | 创建具有5x4颜色矩阵的颜色滤波器。 | 
| [OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateLinearToSrgbGamma](_drawing.md#oh_drawing_colorfiltercreatelineartosrgbgamma) (void) | 创建一个颜色滤波器将SRGB的伽玛曲线应用到RGB颜色通道。 | 
| [OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateSrgbGammaToLinear](_drawing.md#oh_drawing_colorfiltercreatesrgbgammatolinear) (void) | 创建颜色滤波器将RGB颜色通道应用于SRGB的伽玛曲线。 | 
| [OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateLuma](_drawing.md#oh_drawing_colorfiltercreateluma) (void) | 创建一个颜色滤波器将其输入的亮度值乘以透明度通道， 并将红色、绿色和蓝色通道设置为零。 | 
| void [OH_Drawing_ColorFilterDestroy](_drawing.md#oh_drawing_colorfilterdestroy) ([OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) \*) | 销毁颜色滤波器对象，并收回该对象占用的内存。 | 
