# drawing_typeface.h


## 概述

文件中定义了与字形相关的功能函数。 不同的平台有自己的默认字形，也可以从ttf文件解析出三方指定字形，如宋体、黑体字形等。

**引用文件：**&lt;native_drawing/drawing_typeface.h&gt;

**库：** libnative_drawing.so

**起始版本：** 11

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateDefault](_drawing.md#oh_drawing_typefacecreatedefault) (void) | 用于创建一个默认的字形对象。 |
| void [OH_Drawing_TypefaceDestroy](_drawing.md#oh_drawing_typefacedestroy) ([OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \*) | 用于销毁字形对象并回收该对象占有的内存。 |
