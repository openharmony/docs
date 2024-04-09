# drawing_font.h


## 概述

文件中定义了与字体相关的功能函数。

**引用文件：**&lt;native_drawing/drawing_font.h&gt;

**库：** libnative_drawing.so

**起始版本：** 11

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) | 定义字体度量信息的结构体。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md)  [OH_Drawing_Font_Metrics](_drawing.md#oh_drawing_font_metrics) | 定义字体度量信息的结构体。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_Font](_drawing.md#oh_drawing_font) \* [OH_Drawing_FontCreate](_drawing.md#oh_drawing_fontcreate) (void) | 用于创建一个字体对象。 | 
| void [OH_Drawing_FontSetTypeface](_drawing.md#oh_drawing_fontsettypeface) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \*) | 用于给字体设置字形。 | 
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \* [OH_Drawing_FontGetTypeface](_drawing.md#oh_drawing_fontgettypeface) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*) | 获取字形对象。 | 
| void [OH_Drawing_FontSetTextSize](_drawing.md#oh_drawing_fontsettextsize) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, float textSize) | 用于给字体设置文字大小。 | 
| int [OH_Drawing_FontCountText](_drawing.md#oh_drawing_fontcounttext) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, const void \*text, size_t byteLength, [OH_Drawing_TextEncoding](_drawing.md#oh_drawing_textencoding) encoding) | 获取文本所表示的字符数量。 | 
| void [OH_Drawing_FontSetLinearText](_drawing.md#oh_drawing_fontsetlineartext) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, bool isLinearText) | 用于设置线性可缩放字体。 | 
| void [OH_Drawing_FontSetTextSkewX](_drawing.md#oh_drawing_fontsettextskewx) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, float skewX) | 用于给字体设置文本倾斜。 | 
| void [OH_Drawing_FontSetFakeBoldText](_drawing.md#oh_drawing_fontsetfakeboldtext) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, bool isFakeBoldText) | 用于设置增加描边宽度以近似粗体字体效果。 | 
| void [OH_Drawing_FontDestroy](_drawing.md#oh_drawing_fontdestroy) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*) | 用于销毁字体对象并回收该对象占有的内存。 | 
| float [OH_Drawing_FontGetMetrics](_drawing.md#oh_drawing_fontgetmetrics) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) \*) | 获取字体度量信息。 | 
