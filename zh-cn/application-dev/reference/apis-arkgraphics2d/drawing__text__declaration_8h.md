# drawing_text_declaration.h


## 概述

提供2D绘制文本相关的数据结构声明。

**引用文件：**&lt;native_drawing/drawing_text_declaration.h&gt;

**库：** libnative_drawing.so

**起始版本：** 8

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_Drawing_TextTab](_drawing.md#oh_drawing_texttab) [OH_Drawing_TextTab](_drawing.md#oh_drawing_texttab) | 用于管理文本制表符。  | 
| typedef struct [OH_Drawing_LineTypography](_drawing.md#oh_drawing_linetypography) [OH_Drawing_LineTypography](_drawing.md#oh_drawing_linetypography) | 用于从一段文字中提取单行数据进行排版。  |
| typedef struct [OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection)  [OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection) | 用于加载字体。 | 
| typedef struct [OH_Drawing_Typography](_drawing.md#oh_drawing_typography)  [OH_Drawing_Typography](_drawing.md#oh_drawing_typography) | 用于管理排版的布局和显示等。 | 
| typedef struct [OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle)  [OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) | 用于管理字体颜色、装饰等。 | 
| typedef struct [OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle)  [OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) | 用于管理排版风格，如文字方向等。 | 
| typedef struct [OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate)  [OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) | 用于创建[OH_Drawing_Typography](_drawing.md#oh_drawing_typography)。 | 
| typedef struct [OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox)  [OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) | 用于接收文本框的矩形大小、方向和数量大小。 | 
| typedef struct [OH_Drawing_PositionAndAffinity](_drawing.md#oh_drawing_positionandaffinity)  [OH_Drawing_PositionAndAffinity](_drawing.md#oh_drawing_positionandaffinity) | 用于接收字体的位置和亲和性。 | 
| typedef struct [OH_Drawing_Range](_drawing.md#oh_drawing_range)  [OH_Drawing_Range](_drawing.md#oh_drawing_range) | 用于接收字体的起始位置和结束位置。 | 
| typedef struct [OH_Drawing_TextShadow](_drawing.md#oh_drawing_textshadow)  [OH_Drawing_TextShadow](_drawing.md#oh_drawing_textshadow) | 用于管理文本阴影。 | 
| typedef struct [OH_Drawing_FontParser](_drawing.md#oh_drawing_fontparser)  [OH_Drawing_FontParser](_drawing.md#oh_drawing_fontparser) | 用来解析系统字体文件。 | 
| typedef struct [OH_Drawing_TextLine](_drawing.md#oh_drawing_textline) [OH_Drawing_TextLine](_drawing.md#oh_drawing_textline) | 用于管理文本行。 |
| typedef struct [OH_Drawing_Run](_drawing.md#oh_drawing_run) [OH_Drawing_Run](_drawing.md#oh_drawing_run) | 用于管理文本渲染单元。 |
