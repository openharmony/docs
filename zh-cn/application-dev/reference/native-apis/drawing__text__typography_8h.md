# drawing_text_typography.h


## 概述

定义绘制模块中排版相关的函数。

**引用文件：**&lt;native_drawing/drawing_text_typography.h&gt;

**库：** libnative_drawing.so

**起始版本：** 8

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| struct&nbsp;&nbsp;[OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md) | 用于描述位占位符跨度的结构体。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_TextDirection](_drawing.md#oh_drawing_textdirection) {<br/>TEXT_DIRECTION_RTL, TEXT_DIRECTION_LTR<br/>} | 文字方向。 |
| [OH_Drawing_TextAlign](_drawing.md#oh_drawing_textalign) {<br/>TEXT_ALIGN_LEFT, TEXT_ALIGN_RIGHT, TEXT_ALIGN_CENTER, TEXT_ALIGN_JUSTIFY,<br/>TEXT_ALIGN_START, TEXT_ALIGN_END<br/>} | 文字对齐方式。 |
| [OH_Drawing_FontWeight](_drawing.md#oh_drawing_fontweight) {<br/>FONT_WEIGHT_100, FONT_WEIGHT_200, FONT_WEIGHT_300, FONT_WEIGHT_400,<br/>FONT_WEIGHT_500, FONT_WEIGHT_600, FONT_WEIGHT_700, FONT_WEIGHT_800,<br/>FONT_WEIGHT_900<br/>} | 字重。 |
| [OH_Drawing_TextBaseline](_drawing.md#oh_drawing_textbaseline) {<br/>TEXT_BASELINE_ALPHABETIC, TEXT_BASELINE_IDEOGRAPHIC<br/>} | 基线位置。 |
| [OH_Drawing_TextDecoration](_drawing.md#oh_drawing_textdecoration) {<br/>TEXT_DECORATION_NONE = 0x0, TEXT_DECORATION_UNDERLINE = 0x1, TEXT_DECORATION_OVERLINE = 0x2, TEXT_DECORATION_LINE_THROUGH = 0x4<br/>} | 文本装饰。 |
| [OH_Drawing_FontStyle](_drawing.md#oh_drawing_fontstyle) {<br/>FONT_STYLE_NORMAL, FONT_STYLE_ITALIC<br/>} | 区分字体是否为斜体。 |
| [OH_Drawing_PlaceholderVerticalAlignment](_drawing.md#oh_drawing_placeholderverticalalignment) {<br/>ALIGNMENT_OFFSET_AT_BASELINE, ALIGNMENT_ABOVE_BASELINE, ALIGNMENT_BELOW_BASELINE, ALIGNMENT_TOP_OF_ROW_BOX,<br/>ALIGNMENT_BOTTOM_OF_ROW_BOX, ALIGNMENT_CENTER_OF_ROW_BOX<br/>} | 占位符垂直对齐枚举。 |
| [OH_Drawing_TextDecorationStyle](_drawing.md#oh_drawing_textdecorationstyle) {<br/>TEXT_DECORATION_STYLE_SOLID, TEXT_DECORATION_STYLE_DOUBLE, TEXT_DECORATION_STYLE_DOTTED, TEXT_DECORATION_STYLE_DASHED,<br/>TEXT_DECORATION_STYLE_WAVY<br/>} | 文本装饰样式枚举。 |
| [OH_Drawing_EllipsisModal](_drawing.md#oh_drawing_ellipsismodal) {<br/>ELLIPSIS_MODAL_HEAD = 0, ELLIPSIS_MODAL_MIDDLE = 1, ELLIPSIS_MODAL_TAIL = 2<br/>} | 省略号样式枚举。 |
| [OH_Drawing_BreakStrategy](_drawing.md#oh_drawing_breakstrategy) { BREAK_STRATEGY_GREEDY = 0, BREAK_STRATEGY_HIGH_QUALITY = 1, BREAK_STRATEGY_BALANCED = 2 } | 文本的中断策略枚举。 |
| [OH_Drawing_WordBreakType](_drawing.md#oh_drawing_wordbreaktype) {<br/>WORD_BREAK_TYPE_NORMAL = 0, WORD_BREAK_TYPE_BREAK_ALL = 1, WORD_BREAK_TYPE_BREAK_WORD = 2<br/>} | 单词的断词方式枚举。 |
| [OH_Drawing_RectHeightStyle](_drawing.md#oh_drawing_rectheightstyle) {<br/>RECT_HEIGHT_STYLE_TIGHT, RECT_HEIGHT_STYLE_MAX, RECT_HEIGHT_STYLE_INCLUDELINESPACEMIDDLE, RECT_HEIGHT_STYLE_INCLUDELINESPACETOP,<br/>RECT_HEIGHT_STYLE_INCLUDELINESPACEBOTTOM, RECT_HEIGHT_STYLE_STRUCT<br/>} | 矩形框高度样式枚举。 |
| [OH_Drawing_RectWidthStyle](_drawing.md#oh_drawing_rectwidthstyle) {<br/>RECT_WIDTH_STYLE_TIGHT, RECT_WIDTH_STYLE_MAX<br/>} | 矩形框宽度样式枚举。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \* [OH_Drawing_CreateTypographyStyle](_drawing.md#oh_drawing_createtypographystyle) (void) | 创建OH_Drawing_TypographyStyle |
| void [OH_Drawing_DestroyTypographyStyle](_drawing.md#oh_drawing_destroytypographystyle) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*) | 释放被OH_Drawing_TypographyStyle对象占据的内存。 |
| void [OH_Drawing_SetTypographyTextDirection](_drawing.md#oh_drawing_settypographytextdirection) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | 设置文本方向。 |
| void [OH_Drawing_SetTypographyTextAlign](_drawing.md#oh_drawing_settypographytextalign) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | 设置文本对齐方式。 |
| void [OH_Drawing_SetTypographyTextMaxLines](_drawing.md#oh_drawing_settypographytextmaxlines) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | 设置文本最大行数。 |
| [OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \* [OH_Drawing_CreateTextStyle](_drawing.md#oh_drawing_createtextstyle) (void) | 创建OH_Drawing_TextStyle。 |
| void [OH_Drawing_DestroyTextStyle](_drawing.md#oh_drawing_destroytextstyle) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 释放被OH_Drawing_TextStyle对象占据的内存。 |
| void [OH_Drawing_SetTextStyleColor](_drawing.md#oh_drawing_settextstylecolor) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, uint32_t) | 设置文本颜色。 |
| void [OH_Drawing_SetTextStyleFontSize](_drawing.md#oh_drawing_settextstylefontsize) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, double) | 设置字号。 |
| void [OH_Drawing_SetTextStyleFontWeight](_drawing.md#oh_drawing_settextstylefontweight) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | 设置字重。 |
| void [OH_Drawing_SetTextStyleBaseLine](_drawing.md#oh_drawing_settextstylebaseline) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | 设置字体基线位置。 |
| void [OH_Drawing_SetTextStyleDecoration](_drawing.md#oh_drawing_settextstyledecoration) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | 设置装饰。 |
| void [OH_Drawing_SetTextStyleDecorationColor](_drawing.md#oh_drawing_settextstyledecorationcolor) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, uint32_t) | 设置装饰颜色。 |
| void [OH_Drawing_SetTextStyleFontHeight](_drawing.md#oh_drawing_settextstylefontheight) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, double) | 设置字体高度。 |
| void [OH_Drawing_SetTextStyleFontFamilies](_drawing.md#oh_drawing_settextstylefontfamilies) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int, const char \*fontFamilies[]) | 设置字体类型。 |
| void [OH_Drawing_SetTextStyleFontStyle](_drawing.md#oh_drawing_settextstylefontstyle) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | 设置字体风格。 |
| void [OH_Drawing_SetTextStyleLocale](_drawing.md#oh_drawing_settextstylelocale) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, const char \*) | 设置语言区域。 |
| [OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \* [OH_Drawing_CreateTypographyHandler](_drawing.md#oh_drawing_createtypographyhandler) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, [OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection) \*) | 创建指向OH_Drawing_TypographyCreate对象的指针。 |
| void [OH_Drawing_DestroyTypographyHandler](_drawing.md#oh_drawing_destroytypographyhandler) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*) | 释放被OH_Drawing_TypographyCreate对象占据的内存。 |
| void [OH_Drawing_TypographyHandlerPushTextStyle](_drawing.md#oh_drawing_typographyhandlerpushtextstyle) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*, [OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 设置排版风格。 |
| void [OH_Drawing_TypographyHandlerAddText](_drawing.md#oh_drawing_typographyhandleraddtext) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*, const char \*) | 设置文本内容。 |
| void [OH_Drawing_TypographyHandlerPopTextStyle](_drawing.md#oh_drawing_typographyhandlerpoptextstyle) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*) | 排版弹出。 |
| [OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \* [OH_Drawing_CreateTypography](_drawing.md#oh_drawing_createtypography) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*) | 创建OH_Drawing_Typography。 |
| void [OH_Drawing_DestroyTypography](_drawing.md#oh_drawing_destroytypography) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 释放OH_Drawing_Typography对象占据的内存。 |
| void [OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, double) | 排版布局。 |
| void [OH_Drawing_TypographyPaint](_drawing.md#oh_drawing_typographypaint) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, [OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, double, double) | 显示文本。 |
| double [OH_Drawing_TypographyGetMaxWidth](_drawing.md#oh_drawing_typographygetmaxwidth) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 获取最大宽度。 |
| double [OH_Drawing_TypographyGetHeight](_drawing.md#oh_drawing_typographygetheight) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 获取高度。 |
| double [OH_Drawing_TypographyGetLongestLine](_drawing.md#oh_drawing_typographygetlongestline) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 获取最长行。 |
| double [OH_Drawing_TypographyGetMinIntrinsicWidth](_drawing.md#oh_drawing_typographygetminintrinsicwidth) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 获取最小固有宽度。 |
| double [OH_Drawing_TypographyGetMaxIntrinsicWidth](_drawing.md#oh_drawing_typographygetmaxintrinsicwidth) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 获取最大固有宽度。 |
| double [OH_Drawing_TypographyGetAlphabeticBaseline](_drawing.md#oh_drawing_typographygetalphabeticbaseline) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 获取字母文字基线。 |
| double [OH_Drawing_TypographyGetIdeographicBaseline](_drawing.md#oh_drawing_typographygetideographicbaseline) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 获取表意文字基线。 |
| void [OH_Drawing_TypographyHandlerAddPlaceholder](_drawing.md#oh_drawing_typographyhandleraddplaceholder) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*, [OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md) \*) | 设置占位符 |
| bool [OH_Drawing_TypographyDidExceedMaxLines](_drawing.md#oh_drawing_typographydidexceedmaxlines) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 获取文本是否超过最大行 |
| [OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \* [OH_Drawing_TypographyGetRectsForRange](_drawing.md#oh_drawing_typographygetrectsforrange) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, size_t, size_t, [OH_Drawing_RectHeightStyle](_drawing.md#oh_drawing_rectheightstyle), [OH_Drawing_RectWidthStyle](_drawing.md#oh_drawing_rectwidthstyle)) | 获取指定范围内的文本框 |
| [OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \* [OH_Drawing_TypographyGetRectsForPlaceholders](_drawing.md#oh_drawing_typographygetrectsforplaceholders) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 获取占位符的文本框 |
| float [OH_Drawing_GetLeftFromTextBox](_drawing.md#oh_drawing_getleftfromtextbox) ([OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \*, int) | 获取文本框左侧位置 |
| float [OH_Drawing_GetRightFromTextBox](_drawing.md#oh_drawing_getrightfromtextbox) ([OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \*, int) | 获取文本框右侧位置 |
| float [OH_Drawing_GetTopFromTextBox](_drawing.md#oh_drawing_gettopfromtextbox) ([OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \*, int) | 获取文本框顶部位置 |
| float [OH_Drawing_GetBottomFromTextBox](_drawing.md#oh_drawing_getbottomfromtextbox) ([OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \*, int) | 获取文本框底部位置 |
| int [OH_Drawing_GetTextDirectionFromTextBox](_drawing.md#oh_drawing_gettextdirectionfromtextbox) ([OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \*, int) | 获取文本框方向 |
| size_t [OH_Drawing_GetSizeOfTextBox](_drawing.md#oh_drawing_getsizeoftextbox) ([OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \*) | 获取文本框数量大小 |
| [OH_Drawing_PositionAndAffinity](_drawing.md#oh_drawing_positionandaffinity) \* [OH_Drawing_TypographyGetGlyphPositionAtCoordinate](_drawing.md#oh_drawing_typographygetglyphpositionatcoordinate) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, double, double) | 获取坐标处文本的索引位置和亲和性 |
| [OH_Drawing_PositionAndAffinity](_drawing.md#oh_drawing_positionandaffinity) \* [OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster](_drawing.md#oh_drawing_typographygetglyphpositionatcoordinatewithcluster) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, double, double) | 获取坐标处文本所属字符簇的索引位置和亲和性，字符簇指一个或多个字符组成的整体 |
| size_t [OH_Drawing_GetPositionFromPositionAndAffinity](_drawing.md#oh_drawing_getpositionfrompositionandaffinity) ([OH_Drawing_PositionAndAffinity](_drawing.md#oh_drawing_positionandaffinity) \*) | 获取OH_Drawing_PositionAndAffinity对象的位置属性 |
| int [OH_Drawing_GetAffinityFromPositionAndAffinity](_drawing.md#oh_drawing_getaffinityfrompositionandaffinity) ([OH_Drawing_PositionAndAffinity](_drawing.md#oh_drawing_positionandaffinity) \*) | 获取OH_Drawing_PositionAndAffinity对象的亲和性，根据亲和性可判断字体会靠近前方文本还是后方文本 |
| [OH_Drawing_Range](_drawing.md#oh_drawing_range) \* [OH_Drawing_TypographyGetWordBoundary](_drawing.md#oh_drawing_typographygetwordboundary) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, size_t) | 获取单词的边界 |
| size_t [OH_Drawing_GetStartFromRange](_drawing.md#oh_drawing_getstartfromrange) ([OH_Drawing_Range](_drawing.md#oh_drawing_range) \*) | 获取OH_Drawing_Range对象开始位置 |
| size_t [OH_Drawing_GetEndFromRange](_drawing.md#oh_drawing_getendfromrange) ([OH_Drawing_Range](_drawing.md#oh_drawing_range) \*) | 获取OH_Drawing_Range对象结束位置 |
| size_t [OH_Drawing_TypographyGetLineCount](_drawing.md#oh_drawing_typographygetlinecount) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 获取文本行数 |
| void [OH_Drawing_SetTextStyleDecorationStyle](_drawing.md#oh_drawing_settextstyledecorationstyle) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | 设置文本装饰样式 |
| void [OH_Drawing_SetTextStyleDecorationThicknessScale](_drawing.md#oh_drawing_settextstyledecorationthicknessscale) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, double) | 设置文本装饰线的厚度缩放比例 |
| void [OH_Drawing_SetTextStyleLetterSpacing](_drawing.md#oh_drawing_settextstyleletterspacing) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, double) | 设置文本的字符间距 |
| void [OH_Drawing_SetTextStyleWordSpacing](_drawing.md#oh_drawing_settextstylewordspacing) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, double) | 设置文本的单词间距 |
| void [OH_Drawing_SetTextStyleHalfLeading](_drawing.md#oh_drawing_settextstylehalfleading) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, bool) | 设置文本为一半行间距 |
| void [OH_Drawing_SetTextStyleEllipsis](_drawing.md#oh_drawing_settextstyleellipsis) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, const char \*) | 设置文本的省略号内容 |
| void [OH_Drawing_SetTextStyleEllipsisModal](_drawing.md#oh_drawing_settextstyleellipsismodal) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | 设置文本的省略号样式 |
| void [OH_Drawing_SetTypographyTextBreakStrategy](_drawing.md#oh_drawing_settypographytextbreakstrategy) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | 设置文本的中断策略 |
| void [OH_Drawing_SetTypographyTextWordBreakType](_drawing.md#oh_drawing_settypographytextwordbreaktype) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | 设置单词的断词方式 |
| void [OH_Drawing_SetTypographyTextEllipsisModal](_drawing.md#oh_drawing_settypographytextellipsismodal) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | 设置文本的省略号样式 |
| double [OH_Drawing_TypographyGetLineHeight](_drawing.md#oh_drawing_typographygetlineheight) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, int) | 获取指定行的行高 |
| double [OH_Drawing_TypographyGetLineWidth](_drawing.md#oh_drawing_typographygetlinewidth) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, int) | 获取指定行的行宽 |
