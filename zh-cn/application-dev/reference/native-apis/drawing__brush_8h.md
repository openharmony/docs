# drawing_brush.h


## 概述

文件中定义了与画刷相关的功能函数。

**起始版本：**

8

**相关模块：**

[Drawing](_drawing.md)


## 汇总


### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_BrushCreate](_drawing.md#oh_drawing_brushcreate) (void) | 函数用于创建一个画刷对象 |
| [OH_Drawing_BrushDestroy](_drawing.md#oh_drawing_brushdestroy) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | 函数用于销毁画刷对象并回收该对象占有的内存。 |
| [OH_Drawing_BrushIsAntiAlias](_drawing.md#oh_drawing_brushisantialias) (const [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | 函数用于获取画刷是否设置抗锯齿属性，如果为真则说明画刷会启用抗锯齿功能，在绘制图形时会对图形的边缘像素进行半透明的模糊处理 |
| [OH_Drawing_BrushSetAntiAlias](_drawing.md#oh_drawing_brushsetantialias) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*, bool) | 函数用于设置画刷的抗锯齿属性，设置为真则画刷在绘制图形时会对图形的边缘像素进行半透明的模糊处理 |
| [OH_Drawing_BrushGetColor](_drawing.md#oh_drawing_brushgetcolor) (const [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | 函数用于获取画刷的颜色属性，颜色属性描述了画刷填充图形时使用的颜色，用一个32位（ARGB）的变量表示 |
| [OH_Drawing_BrushSetColor](_drawing.md#oh_drawing_brushsetcolor) ([OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*, uint32_t color) | 函数用于设置画刷的颜色属性，颜色属性描述了画刷填充图形时使用的颜色，用一个32位（ARGB）的变量表示 |
