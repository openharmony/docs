# drawing_text_typography.h


## 概述

定义绘制模块中排版相关的函数。

**起始版本：**

8

**相关模块：**

[Drawing](_drawing.md)


## 汇总


### 枚举

| 枚举名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_TextDirection](_drawing.md#oh_drawing_textdirection) { TEXT_DIRECTION_RTL, TEXT_DIRECTION_LTR } | 文字方向 |
| [OH_Drawing_TextAlign](_drawing.md#oh_drawing_textalign) { TEXT_ALIGN_LEFT, TEXT_ALIGN_RIGHT, TEXT_ALIGN_CENTER, TEXT_ALIGN_JUSTIFY,   TEXT_ALIGN_START, TEXT_ALIGN_END } | 文字对齐方式 |
| [OH_Drawing_FontWeight](_drawing.md#oh_drawing_fontweight) {  FONT_WEIGHT_100, FONT_WEIGHT_200, FONT_WEIGHT_300, FONT_WEIGHT_400,   FONT_WEIGHT_500, FONT_WEIGHT_600, FONT_WEIGHT_700, FONT_WEIGHT_800,  FONT_WEIGHT_900  } | 字重 |
| [OH_Drawing_TextBaseline](_drawing.md#oh_drawing_textbaseline) { TEXT_BASELINE_ALPHABETIC, TEXT_BASELINE_IDEOGRAPHIC } | 基线位置 |
| [OH_Drawing_TextDecoration](_drawing.md#oh_drawing_textdecoration) { TEXT_DECORATION_NONE = 0x0, TEXT_DECORATION_UNDERLINE = 0x1, TEXT_DECORATION_OVERLINE = 0x2, TEXT_DECORATION_LINE_THROUGH = 0x4 } | 文本装饰 |
| [OH_Drawing_FontStyle](_drawing.md#oh_drawing_fontstyle) { FONT_STYLE_NORMAL, FONT_STYLE_ITALIC } | 区分字体是否为斜体 |
| [OH_Drawing_TypographyGetMaxWidth](_drawing.md#oh_drawing_typographygetmaxwidth) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) *) | 获取最大宽度。 |
| [OH_Drawing_TypographyGetHeight](_drawing.md#oh_drawing_typographygetheight) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) *) | 获取高度。 |
| [OH_Drawing_TypographyGetLongestLine](_drawing.md#oh_drawing_typographygetlongestline) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) *) | 获取最长行。 |
| [OH_Drawing_TypographyGetMinIntrinsicWidth](_drawing.md#oh_drawing_typographygetminintrinsicwidth) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) *) | 获取最小固有宽度。 |
| [OH_Drawing_TypographyGetMaxIntrinsicWidth](_drawing.md#oh_drawing_typographygetmaxintrinsicwidth) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) *) | 获取最大固有宽度。 |
| [OH_Drawing_TypographyGetAlphabeticBaseline](_drawing.md#oh_drawing_typographygetalphabeticbaseline)([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) *) | 获取字母文字基线。 |
| [OH_Drawing_TypographyGetIdeographicBaseline](_drawing.md#oh_drawing_typographygetideographicbaseline) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) *) | 获取表意文字基线。 |



### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_CreateTypographyStyle](_drawing.md#oh_drawing_createtypographystyle) (void) | 创建OH_Drawing_TypographyStyle |
| [OH_Drawing_DestroyTypographyStyle](_drawing.md#oh_drawing_destroytypographystyle) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*) | 释放被OH_Drawing_TypographyStyle对象占据的内存 |
| [OH_Drawing_SetTypographyTextDirection](_drawing.md#oh_drawing_settypographytextdirection) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | 设置文本方向 |
| [OH_Drawing_SetTypographyTextAlign](_drawing.md#oh_drawing_settypographytextalign) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | 设置文本对齐方式 |
| [OH_Drawing_SetTypographyTextMaxLines](_drawing.md#oh_drawing_settypographytextmaxlines) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | 设置文本最大行数 |
| [OH_Drawing_CreateTextStyle](_drawing.md#oh_drawing_createtextstyle) (void) | 创建OH_Drawing_TextStyle |
| [OH_Drawing_DestroyTextStyle](_drawing.md#oh_drawing_destroytextstyle) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 释放被OH_Drawing_TextStyle对象占据的内存 |
| [OH_Drawing_SetTextStyleColor](_drawing.md#oh_drawing_settextstylecolor) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, uint32_t) | 设置文本颜色 |
| [OH_Drawing_SetTextStyleFontSize](_drawing.md#oh_drawing_settextstylefontsize) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, double) | 设置字号 |
| [OH_Drawing_SetTextStyleFontWeight](_drawing.md#oh_drawing_settextstylefontweight) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | 设置字重 |
| [OH_Drawing_SetTextStyleBaseLine](_drawing.md#oh_drawing_settextstylebaseline) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | 设置字体基线位置 |
| [OH_Drawing_SetTextStyleDecoration](_drawing.md#oh_drawing_settextstyledecoration) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | 设置装饰 |
| [OH_Drawing_SetTextStyleDecorationColor](_drawing.md#oh_drawing_settextstyledecorationcolor) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, uint32_t) | 设置装饰颜色 |
| [OH_Drawing_SetTextStyleFontHeight](_drawing.md#oh_drawing_settextstylefontheight) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, double) | 设置字体高度 |
| [OH_Drawing_SetTextStyleFontFamilies](_drawing.md#oh_drawing_settextstylefontfamilies) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int, const char \*fontFamilies[]) | 设置字体类型 |
| [OH_Drawing_SetTextStyleFontStyle](_drawing.md#oh_drawing_settextstylefontstyle) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | 设置字体风格 |
| [OH_Drawing_SetTextStyleLocale](_drawing.md#oh_drawing_settextstylelocale) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, const char \*) | 设置语言区域 |
| [OH_Drawing_CreateTypographyHandler](_drawing.md#oh_drawing_createtypographyhandler) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, [OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection) \*) | 创建指向OH_Drawing_TypographyCreate对象的指针 |
| [OH_Drawing_DestroyTypographyHandler](_drawing.md#oh_drawing_destroytypographyhandler) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*) | 释放被OH_Drawing_TypographyCreate对象占据的内存 |
| [OH_Drawing_TypographyHandlerPushTextStyle](_drawing.md#oh_drawing_typographyhandlerpushtextstyle) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*, [OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 设置排版风格 |
| [OH_Drawing_TypographyHandlerAddText](_drawing.md#oh_drawing_typographyhandleraddtext) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*, const char \*) | 设置文本内容 |
| [OH_Drawing_TypographyHandlerPopTextStyle](_drawing.md#oh_drawing_typographyhandlerpoptextstyle) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*) | 排版弹出 |
| [OH_Drawing_CreateTypography](_drawing.md#oh_drawing_createtypography) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*) | 创建OH_Drawing_Typography |
| [OH_Drawing_DestroyTypography](_drawing.md#oh_drawing_destroytypography) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 释放OH_Drawing_Typography对象占据的内存 |
| [OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, double) | 排版布局 |
| [OH_Drawing_TypographyPaint](_drawing.md#oh_drawing_typographypaint) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, [OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, double, double) | 显示文本 |
