# drawing_pen.h


## 概述

文件中定义了与画笔相关的功能函数。

**引用文件：**&lt;native_drawing/drawing_pen.h&gt;

**库：** libnative_drawing.so

**起始版本：** 8

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [OH_Drawing_PenLineCapStyle](_drawing.md#oh_drawing_penlinecapstyle)  [OH_Drawing_PenLineCapStyle](_drawing.md#oh_drawing_penlinecapstyle) | 枚举集合定义了画笔笔帽的样式，即画笔在绘制线段时，在线段头尾端点的样式。 | 
| typedef enum [OH_Drawing_PenLineJoinStyle](_drawing.md#oh_drawing_penlinejoinstyle)  [OH_Drawing_PenLineJoinStyle](_drawing.md#oh_drawing_penlinejoinstyle) | 枚举集合定义了线条转角的样式，即画笔在绘制折线段时，在折线转角处的样式。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_PenLineCapStyle](_drawing.md#oh_drawing_penlinecapstyle) { LINE_FLAT_CAP, LINE_SQUARE_CAP, LINE_ROUND_CAP } | 枚举集合定义了画笔笔帽的样式，即画笔在绘制线段时，在线段头尾端点的样式。 | 
| [OH_Drawing_PenLineJoinStyle](_drawing.md#oh_drawing_penlinejoinstyle) { LINE_MITER_JOIN, LINE_ROUND_JOIN, LINE_BEVEL_JOIN } | 枚举集合定义了线条转角的样式，即画笔在绘制折线段时，在折线转角处的样式。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \* [OH_Drawing_PenCreate](_drawing.md#oh_drawing_pencreate) (void) | 用于创建一个画笔对象。 | 
| [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \* [OH_Drawing_PenCopy](_drawing.md#oh_drawing_pencopy) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*pen) | 创建一个画笔对象副本[OH_Drawing_Pen](_drawing.md#oh_drawing_pen)，用于拷贝一个已有画笔对象。 | 
| void [OH_Drawing_PenDestroy](_drawing.md#oh_drawing_pendestroy) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | 用于销毁画笔对象并回收该对象占有的内存。 | 
| bool [OH_Drawing_PenIsAntiAlias](_drawing.md#oh_drawing_penisantialias) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | 用于获取画笔是否设置抗锯齿属性，如果为真则说明画笔会启用抗锯齿功能，在绘制图形时会对图形的边缘像素进行半透明的模糊处理。 | 
| void [OH_Drawing_PenSetAntiAlias](_drawing.md#oh_drawing_pensetantialias) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, bool) | 用于设置画笔的抗锯齿属性，设置为真则画笔在绘制图形时会对图形的边缘像素进行半透明的模糊处理。 | 
| uint32_t [OH_Drawing_PenGetColor](_drawing.md#oh_drawing_pengetcolor) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | 用于获取画笔的颜色属性，颜色属性描述了画笔绘制图形轮廓时使用的颜色，用一个32位（ARGB）的变量表示。 | 
| void [OH_Drawing_PenSetColor](_drawing.md#oh_drawing_pensetcolor) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, uint32_t color) | 用于设置画笔的颜色属性，颜色属性描述了画笔绘制图形轮廓时使用的颜色，用一个32位（ARGB）的变量表示。 | 
| uint8_t [OH_Drawing_PenGetAlpha](_drawing.md#oh_drawing_pengetalpha) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | 获取画笔的透明度值。画笔在勾勒图形时透明通道会使用该值。 | 
| void [OH_Drawing_PenSetAlpha](_drawing.md#oh_drawing_pensetalpha) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, uint8_t alpha) | 为画笔设置透明度值。画笔在勾勒图形时透明通道会使用该值。 | 
| float [OH_Drawing_PenGetWidth](_drawing.md#oh_drawing_pengetwidth) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | 获取画笔的线宽，线宽描述了画笔绘制图形轮廓的宽度。 | 
| void [OH_Drawing_PenSetWidth](_drawing.md#oh_drawing_pensetwidth) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, float width) | 用于设置画笔的线宽。0线宽被视作特殊的极细线宽，在绘制时始终会被绘制为1像素，不随画布的缩放而改变；负数线宽在实际绘制时会被视作0线宽。 | 
| float [OH_Drawing_PenGetMiterLimit](_drawing.md#oh_drawing_pengetmiterlimit) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | 用于获取折线尖角的限制值，当画笔绘制一条折线，转角类型设置为尖角时，那么此时该属性用于限制出现尖角的长度范围，如果超出则平角显示，不超出依然为尖角。 | 
| void [OH_Drawing_PenSetMiterLimit](_drawing.md#oh_drawing_pensetmiterlimit) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, float miter) | 用于设置折线尖角的限制值，当画笔绘制一条折线，转角类型设置为尖角时，那么此时该属性用于限制出现尖角的长度范围，如果超出则平角显示，不超出依然为尖角。 | 
| [OH_Drawing_PenLineCapStyle](_drawing.md#oh_drawing_penlinecapstyle) [OH_Drawing_PenGetCap](_drawing.md#oh_drawing_pengetcap) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | 用于获取画笔笔帽的样式。 | 
| void [OH_Drawing_PenSetCap](_drawing.md#oh_drawing_pensetcap) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, [OH_Drawing_PenLineCapStyle](_drawing.md#oh_drawing_penlinecapstyle)) | 用于设置画笔笔帽样式。 | 
| [OH_Drawing_PenLineJoinStyle](_drawing.md#oh_drawing_penlinejoinstyle) [OH_Drawing_PenGetJoin](_drawing.md#oh_drawing_pengetjoin) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | 用于获取画笔绘制折线转角的样式。 | 
| void [OH_Drawing_PenSetJoin](_drawing.md#oh_drawing_pensetjoin) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, [OH_Drawing_PenLineJoinStyle](_drawing.md#oh_drawing_penlinejoinstyle)) | 用于设置画笔绘制转角的样式。 | 
| void [OH_Drawing_PenSetShaderEffect](_drawing.md#oh_drawing_pensetshadereffect) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) \*) | 设置画笔着色器效果。 | 
| void [OH_Drawing_PenSetShadowLayer](_drawing.md#oh_drawing_pensetshadowlayer) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, [OH_Drawing_ShadowLayer](_drawing.md#oh_drawing_shadowlayer) \*) | 设置画笔阴影层效果，设置的阴影层效果当前仅在绘制文字时生效。 | 
| void [OH_Drawing_PenSetPathEffect](_drawing.md#oh_drawing_pensetpatheffect) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \*) | 设置画笔路径效果。 | 
| void [OH_Drawing_PenSetFilter](_drawing.md#oh_drawing_pensetfilter) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, [OH_Drawing_Filter](_drawing.md#oh_drawing_filter) \*) | 设置画笔滤波器。 | 
| void [OH_Drawing_PenGetFilter](_drawing.md#oh_drawing_pengetfilter) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, [OH_Drawing_Filter](_drawing.md#oh_drawing_filter) \*) | 从画笔获取滤波器[OH_Drawing_Filter](_drawing.md#oh_drawing_filter)。滤波器是一个容器，可以承载蒙版滤波器和颜色滤波器。 | 
| void [OH_Drawing_PenSetBlendMode](_drawing.md#oh_drawing_pensetblendmode) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, [OH_Drawing_BlendMode](_drawing.md#oh_drawing_blendmode)) | 为画笔设置一个混合器，该混合器实现了指定的混合模式枚举。 | 
| bool [OH_Drawing_PenGetFillPath](_drawing.md#oh_drawing_pengetfillpath) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*src, [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*dst, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*, const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | 获取使用画笔绘制的源路径轮廓，并用目标路径表示。 | 
| void [OH_Drawing_PenReset](_drawing.md#oh_drawing_penreset) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | 将画笔重置至初始值。 | 

<!--RP1-->
## 相关实例

针对Drawing(C/C++)的开发，有以下相关实例可供参考：

- [NDKAPIDrawing (API14)](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Drawing/NDKAPIDrawing)
<!--RP1End-->