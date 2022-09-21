# drawing_text_typography.h


## 概述

定义绘制模块中排版相关的函数。

**自从：**

8

**相关模块：**

[Drawing](_drawing.md)


## 汇总


### 枚举

| 枚举名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_TextDirection](_drawing.md#ohdrawingtextdirection) { TEXT_DIRECTION_RTL, TEXT_DIRECTION_LTR } | 文字方向 |
| [OH_Drawing_TextAlign](_drawing.md#ohdrawingtextalign) { TEXT_ALIGN_LEFT, TEXT_ALIGN_RIGHT, TEXT_ALIGN_CENTER, TEXT_ALIGN_JUSTIFY,   TEXT_ALIGN_START, TEXT_ALIGN_END } | 文字对齐方式 |
| [OH_Drawing_FontWeight](_drawing.md#ohdrawingfontweight) {  FONT_WEIGHT_100, FONT_WEIGHT_200, FONT_WEIGHT_300, FONT_WEIGHT_400,   FONT_WEIGHT_500, FONT_WEIGHT_600, FONT_WEIGHT_700, FONT_WEIGHT_800,  FONT_WEIGHT_900  } | 字重 |
| [OH_Drawing_TextBaseline](_drawing.md#ohdrawingtextbaseline) { TEXT_BASELINE_ALPHABETIC, TEXT_BASELINE_IDEOGRAPHIC } | 基线位置 |
| [OH_Drawing_TextDecoration](_drawing.md#ohdrawingtextdecoration) { TEXT_DECORATION_NONE = 0x0, TEXT_DECORATION_UNDERLINE = 0x1, TEXT_DECORATION_OVERLINE = 0x2, TEXT_DECORATION_LINE_THROUGH = 0x4 } | 文本装饰 |
| [OH_Drawing_FontStyle](_drawing.md#ohdrawingfontstyle) { FONT_STYLE_NORMAL, FONT_STYLE_ITALIC } | 区分字体是否为斜体 |


### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_CreateTypographyStyle](_drawing.md#ohdrawingcreatetypographystyle) (void) | 创建OH_Drawing_TypographyStyle |
| [OH_Drawing_DestroyTypographyStyle](_drawing.md#ohdrawingdestroytypographystyle) ([OH_Drawing_TypographyStyle](_drawing.md#ohdrawingtypographystyle) \*) | 释放被OH_Drawing_TypographyStyle对象占据的内存 |
| [OH_Drawing_SetTypographyTextDirection](_drawing.md#ohdrawingsettypographytextdirection) ([OH_Drawing_TypographyStyle](_drawing.md#ohdrawingtypographystyle) \*, int) | 设置文本方向 |
| [OH_Drawing_SetTypographyTextAlign](_drawing.md#ohdrawingsettypographytextalign) ([OH_Drawing_TypographyStyle](_drawing.md#ohdrawingtypographystyle) \*, int) | 设置文本对齐方式 |
| [OH_Drawing_SetTypographyTextMaxLines](_drawing.md#ohdrawingsettypographytextmaxlines) ([OH_Drawing_TypographyStyle](_drawing.md#ohdrawingtypographystyle) \*, int) | 设置文本最大行数 |
| [OH_Drawing_CreateTextStyle](_drawing.md#ohdrawingcreatetextstyle) (void) | 创建OH_Drawing_TextStyle |
| [OH_Drawing_DestroyTextStyle](_drawing.md#ohdrawingdestroytextstyle) ([OH_Drawing_TextStyle](_drawing.md#ohdrawingtextstyle) \*) | 释放被OH_Drawing_TextStyle对象占据的内存 |
| [OH_Drawing_SetTextStyleColor](_drawing.md#ohdrawingsettextstylecolor) ([OH_Drawing_TextStyle](_drawing.md#ohdrawingtextstyle) \*, uint32_t) | 设置文本颜色 |
| [OH_Drawing_SetTextStyleFontSize](_drawing.md#ohdrawingsettextstylefontsize) ([OH_Drawing_TextStyle](_drawing.md#ohdrawingtextstyle) \*, double) | 设置字号 |
| [OH_Drawing_SetTextStyleFontWeight](_drawing.md#ohdrawingsettextstylefontweight) ([OH_Drawing_TextStyle](_drawing.md#ohdrawingtextstyle) \*, int) | 设置字重 |
| [OH_Drawing_SetTextStyleBaseLine](_drawing.md#ohdrawingsettextstylebaseline) ([OH_Drawing_TextStyle](_drawing.md#ohdrawingtextstyle) \*, int) | 设置字体基线位置 |
| [OH_Drawing_SetTextStyleDecoration](_drawing.md#ohdrawingsettextstyledecoration) ([OH_Drawing_TextStyle](_drawing.md#ohdrawingtextstyle) \*, int) | 设置装饰 |
| [OH_Drawing_SetTextStyleDecorationColor](_drawing.md#ohdrawingsettextstyledecorationcolor) ([OH_Drawing_TextStyle](_drawing.md#ohdrawingtextstyle) \*, uint32_t) | 设置装饰颜色 |
| [OH_Drawing_SetTextStyleFontHeight](_drawing.md#ohdrawingsettextstylefontheight) ([OH_Drawing_TextStyle](_drawing.md#ohdrawingtextstyle) \*, double) | 设置字体高度 |
| [OH_Drawing_SetTextStyleFontFamilies](_drawing.md#ohdrawingsettextstylefontfamilies) ([OH_Drawing_TextStyle](_drawing.md#ohdrawingtextstyle) \*, int, const char \*fontFamilies[]) | 设置字体类型 |
| [OH_Drawing_SetTextStyleFontStyle](_drawing.md#ohdrawingsettextstylefontstyle) ([OH_Drawing_TextStyle](_drawing.md#ohdrawingtextstyle) \*, int) | 设置字体风格 |
| [OH_Drawing_SetTextStyleLocale](_drawing.md#ohdrawingsettextstylelocale) ([OH_Drawing_TextStyle](_drawing.md#ohdrawingtextstyle) \*, const char \*) | 设置语言区域 |
| [OH_Drawing_CreateTypographyHandler](_drawing.md#ohdrawingcreatetypographyhandler) ([OH_Drawing_TypographyStyle](_drawing.md#ohdrawingtypographystyle) \*, [OH_Drawing_FontCollection](_drawing.md#ohdrawingfontcollection) \*) | 创建指向OH_Drawing_TypographyCreate对象的指针 |
| [OH_Drawing_DestroyTypographyHandler](_drawing.md#ohdrawingdestroytypographyhandler) ([OH_Drawing_TypographyCreate](_drawing.md#ohdrawingtypographycreate) \*) | 释放被OH_Drawing_TypographyCreate对象占据的内存 |
| [OH_Drawing_TypographyHandlerPushTextStyle](_drawing.md#ohdrawingtypographyhandlerpushtextstyle) ([OH_Drawing_TypographyCreate](_drawing.md#ohdrawingtypographycreate) \*, [OH_Drawing_TextStyle](_drawing.md#ohdrawingtextstyle) \*) | 设置排版风格 |
| [OH_Drawing_TypographyHandlerAddText](_drawing.md#ohdrawingtypographyhandleraddtext) ([OH_Drawing_TypographyCreate](_drawing.md#ohdrawingtypographycreate) \*, const char \*) | 设置文本内容 |
| [OH_Drawing_TypographyHandlerPopTextStyle](_drawing.md#ohdrawingtypographyhandlerpoptextstyle) ([OH_Drawing_TypographyCreate](_drawing.md#ohdrawingtypographycreate) \*) | 排版弹出 |
| [OH_Drawing_CreateTypography](_drawing.md#ohdrawingcreatetypography) ([OH_Drawing_TypographyCreate](_drawing.md#ohdrawingtypographycreate) \*) | 创建OH_Drawing_Typography |
| [OH_Drawing_DestroyTypography](_drawing.md#ohdrawingdestroytypography) ([OH_Drawing_Typography](_drawing.md#ohdrawingtypography) \*) | 释放OH_Drawing_Typography对象占据的内存 |
| [OH_Drawing_TypographyLayout](_drawing.md#ohdrawingtypographylayout) ([OH_Drawing_Typography](_drawing.md#ohdrawingtypography) \*, double) | 排版布局 |
| [OH_Drawing_TypographyPaint](_drawing.md#ohdrawingtypographypaint) ([OH_Drawing_Typography](_drawing.md#ohdrawingtypography) \*, [OH_Drawing_Canvas](_drawing.md#ohdrawingcanvas) \*, double, double) | 显示文本 |
