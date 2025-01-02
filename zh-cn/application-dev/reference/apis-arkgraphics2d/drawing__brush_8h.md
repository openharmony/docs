# drawing_brush.h


## 概述

文件中定义了与画刷相关的功能函数。

**引用文件：**&lt;native_drawing/drawing_brush.h&gt;

**库：** libnative_drawing.so

**起始版本：** 8

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \* [OH_Drawing_BrushCreate](_drawing.md#oh_drawing_brushcreate) (void) | 用于创建一个画刷对象。 | 
| [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \* [OH_Drawing_BrushCopy](_drawing.md#oh_drawing_brushcopy) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*brush) | 创建一个画刷对象副本[OH_Drawing_Brush](_drawing.md#oh_drawing_brush)，用于拷贝一个已有画刷对象。 | 
| void [OH_Drawing_BrushDestroy](_drawing.md#oh_drawing_brushdestroy) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | 用于销毁画刷对象并回收该对象占有的内存。 | 
| bool [OH_Drawing_BrushIsAntiAlias](_drawing.md#oh_drawing_brushisantialias) (const [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | 用于获取画刷是否设置抗锯齿属性，如果为真则说明画刷会启用抗锯齿功能，在绘制图形时会对图形的边缘像素进行半透明的模糊处理。 | 
| void [OH_Drawing_BrushSetAntiAlias](_drawing.md#oh_drawing_brushsetantialias) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*, bool) | 用于设置画刷的抗锯齿属性，设置为真则画刷在绘制图形时会对图形的边缘像素进行半透明的模糊处理。 | 
| uint32_t [OH_Drawing_BrushGetColor](_drawing.md#oh_drawing_brushgetcolor) (const [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | 用于获取画刷的颜色属性，颜色属性描述了画刷填充图形时使用的颜色，用一个32位（ARGB）的变量表示。 | 
| void [OH_Drawing_BrushSetColor](_drawing.md#oh_drawing_brushsetcolor) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*, uint32_t color) | 用于设置画刷的颜色属性，颜色属性描述了画刷填充图形时使用的颜色，用一个32位（ARGB）的变量表示。 | 
| uint8_t [OH_Drawing_BrushGetAlpha](_drawing.md#oh_drawing_brushgetalpha) (const [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | 获取画刷的透明度值。画刷在填充形状时透明通道会使用该值。 | 
| void [OH_Drawing_BrushSetAlpha](_drawing.md#oh_drawing_brushsetalpha) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*, uint8_t alpha) | 为画刷设置透明度值。画刷在填充形状时透明通道会使用该值。 | 
| void [OH_Drawing_BrushSetShaderEffect](_drawing.md#oh_drawing_brushsetshadereffect) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*, [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) \*) | 为画刷设置着色器效果。 | 
| void [OH_Drawing_BrushSetShadowLayer](_drawing.md#oh_drawing_brushsetshadowlayer) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*, [OH_Drawing_ShadowLayer](_drawing.md#oh_drawing_shadowlayer) \*) | 为画刷设置阴影层，设置的阴影层效果当前仅在绘制文字时生效。 | 
| void [OH_Drawing_BrushSetFilter](_drawing.md#oh_drawing_brushsetfilter) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*, [OH_Drawing_Filter](_drawing.md#oh_drawing_filter) \*) | 为画刷设置滤波器[OH_Drawing_Filter](_drawing.md#oh_drawing_filter)。滤波器是一个容器，可以承载蒙版滤波器和颜色滤波器。 | 
| void [OH_Drawing_BrushGetFilter](_drawing.md#oh_drawing_brushgetfilter) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*, [OH_Drawing_Filter](_drawing.md#oh_drawing_filter) \*) | 从画刷获取滤波器[OH_Drawing_Filter](_drawing.md#oh_drawing_filter)。滤波器是一个容器，可以承载蒙版滤波器和颜色滤波器。 | 
| void [OH_Drawing_BrushSetBlendMode](_drawing.md#oh_drawing_brushsetblendmode) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*, [OH_Drawing_BlendMode](_drawing.md#oh_drawing_blendmode)) | 为画刷设置一个混合器，该混合器实现了指定的混合模式枚举。 | 
| void [OH_Drawing_BrushReset](_drawing.md#oh_drawing_brushreset) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | 将画刷重置至初始状态，清空所有已设置的属性。 | 
