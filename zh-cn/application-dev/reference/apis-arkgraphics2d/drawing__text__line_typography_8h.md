# drawing_text_lineTypography.h


## 概述

提供排版行相关的接口，比如获取指定位置处开始可以排版的字符个数等函数。

**引用文件：**&lt;native_drawing/drawing_text_lineTypography.h&gt;

**库：** libnative_drawing.so

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 16

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_LineTypography](_drawing.md#oh_drawing_linetypography) \* [OH_Drawing_CreateLineTypography](_drawing.md#oh_drawing_createlinetypography) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*handler) | 创建一个排版行对象[OH_Drawing_LineTypography](_drawing.md#oh_drawing_linetypography)的指针，排版行对象保存着文本内容以及样式的载体， 可以用于计算单行排版信息。 |
| void [OH_Drawing_DestroyLineTypography](_drawing.md#oh_drawing_destroylinetypography) ([OH_Drawing_LineTypography](_drawing.md#oh_drawing_linetypography) \*lineTypography) | 释放排版行对象[OH_Drawing_LineTypography](_drawing.md#oh_drawing_linetypography)占用的内存。 |
| size_t [OH_Drawing_LineTypographyGetLineBreak](_drawing.md#oh_drawing_linetypographygetlinebreak) ([OH_Drawing_LineTypography](_drawing.md#oh_drawing_linetypography) \*lineTypography, size_t startIndex, double width) | 计算在限定排版宽度的情况下，从指定位置处开始可以排版的字符个数。 |
| [OH_Drawing_TextLine](_drawing.md#oh_drawing_textline) \* [OH_Drawing_LineTypographyCreateLine](_drawing.md#oh_drawing_linetypographycreateline) ([OH_Drawing_LineTypography](_drawing.md#oh_drawing_linetypography) \*lineTypography, size_t startIndex, size_t count) | 根据指定区间文本内容创建一个指向文本行对象[OH_Drawing_TextLine](_drawing.md#oh_drawing_textline)的指针。 |