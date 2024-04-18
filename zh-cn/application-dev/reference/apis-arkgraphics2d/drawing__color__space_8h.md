# drawing_color_space.h


## 概述

文件中定义了与颜色空间相关的功能函数。

**引用文件：**&lt;native_drawing/drawing_color_space.h&gt;

**库：** libnative_drawing.so

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_ColorSpace](_drawing.md#oh_drawing_colorspace) \* [OH_Drawing_ColorSpaceCreateSrgb](_drawing.md#oh_drawing_colorspacecreatesrgb) (void) | 创建一个标准颜色空间。 | 
| [OH_Drawing_ColorSpace](_drawing.md#oh_drawing_colorspace) \* [OH_Drawing_ColorSpaceCreateSrgbLinear](_drawing.md#oh_drawing_colorspacecreatesrgblinear) (void) | 创建一个Gamma 1.0空间上的颜色空间。 | 
| void [OH_Drawing_ColorSpaceDestroy](_drawing.md#oh_drawing_colorspacedestroy) ([OH_Drawing_ColorSpace](_drawing.md#oh_drawing_colorspace) \*) | 销毁颜色空间对象，并回收该对象占有内存。 | 
