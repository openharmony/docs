# drawing_pen.h


## 概述

文件中定义了与画笔相关的功能函数。

**起始版本：**

8

**相关模块：**

[Drawing](_drawing.md)


## 汇总


### 枚举

| 枚举名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_PenLineCapStyle](_drawing.md#oh_drawing_penlinecapstyle) { LINE_FLAT_CAP, LINE_SQUARE_CAP, LINE_ROUND_CAP } | 枚举集合定义了画笔笔帽的样式，即画笔在绘制线段时，在线段头尾端点的样式 |
| [OH_Drawing_PenLineJoinStyle](_drawing.md#oh_drawing_penlinejoinstyle) { LINE_MITER_JOIN, LINE_ROUND_JOIN, LINE_BEVEL_JOIN } | 枚举集合定义了线条转角的样式，即画笔在绘制折线段时，在折线转角处的样式 |


### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_PenCreate](_drawing.md#oh_drawing_pencreate) (void) | 函数用于创建一个画笔对象 |
| [OH_Drawing_PenDestroy](_drawing.md#oh_drawing_pendestroy) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | 函数用于销毁画笔对象并回收该对象占有的内存 |
| [OH_Drawing_PenIsAntiAlias](_drawing.md#oh_drawing_penisantialias) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | 函数用于获取画笔是否设置抗锯齿属性，如果为真则说明画笔会启用抗锯齿功能，在绘制图形时会对图形的边缘像素进行半透明的模糊处理 |
| [OH_Drawing_PenSetAntiAlias](_drawing.md#oh_drawing_pensetantialias) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, bool) | 函数用于设置画笔的抗锯齿属性，设置为真则画笔在绘制图形时会对图形的边缘像素进行半透明的模糊处理 |
| [OH_Drawing_PenGetColor](_drawing.md#oh_drawing_pengetcolor) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | 函数用于获取画笔的颜色属性，颜色属性描述了画笔绘制图形轮廓时使用的颜色，用一个32位（ARGB）的变量表示 |
| [OH_Drawing_PenSetColor](_drawing.md#oh_drawing_pensetcolor) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, uint32_t color) | 函数用于设置画笔的颜色属性，颜色属性描述了画笔绘制图形轮廓时使用的颜色，用一个32位（ARGB）的变量表示 |
| [OH_Drawing_PenGetWidth](_drawing.md#oh_drawing_pengetwidth) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | 函数用于获取画笔的厚度属性，厚度属性描述了画笔绘制图形轮廓的宽度 |
| [OH_Drawing_PenSetWidth](_drawing.md#oh_drawing_pensetwidth) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, float width) | 函数用于设置画笔的厚度属性，厚度属性描述了画笔绘制图形轮廓的宽度 |
| [OH_Drawing_PenGetMiterLimit](_drawing.md#oh_drawing_pengetmiterlimit) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | 函数用于获取折线尖角的限制值，当画笔绘制一条折线，转角类型设置为尖角时，那么此时该属性用于限制出现尖角的长度范围，如果超出则平角显示，不超出依然为尖角 |
| [OH_Drawing_PenSetMiterLimit](_drawing.md#oh_drawing_pensetmiterlimit) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, float miter) | 函数用于设置折线尖角的限制值，当画笔绘制一条折线，转角类型设置为尖角时，那么此时该属性用于限制出现尖角的长度范围，如果超出则平角显示，不超出依然为尖角 |
| [OH_Drawing_PenGetCap](_drawing.md#oh_drawing_pengetcap) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | 函数用于获取画笔笔帽的样式 |
| [OH_Drawing_PenSetCap](_drawing.md#oh_drawing_pensetcap) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, [OH_Drawing_PenLineCapStyle](_drawing.md#oh_drawing_penlinecapstyle)) | 函数用于设置画笔笔帽样式 |
| [OH_Drawing_PenGetJoin](_drawing.md#oh_drawing_pengetjoin) (const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | 函数用于获取画笔绘制折线转角的样式 |
| [OH_Drawing_PenSetJoin](_drawing.md#oh_drawing_pensetjoin) ([OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*, [OH_Drawing_PenLineJoinStyle](_drawing.md#oh_drawing_penlinejoinstyle)) | 函数用于设置画笔绘制转角的样式 |
