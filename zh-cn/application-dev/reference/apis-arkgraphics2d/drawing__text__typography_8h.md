# drawing_text_typography.h


## 概述

定义绘制模块中排版相关的函数。

引用文件"native_drawing/drawing_text_typography.h"

**库：** libnative_drawing.so

**起始版本：** 8

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct    [OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md) | 用于描述占位符跨度的结构体。  | 
| struct    [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) | 描述系统字体详细信息的结构体。  | 
| struct    [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) | 文字行位置信息。  | 
| struct    [OH_Drawing_FontFallbackInfo](_o_h___drawing___font_fallback_info.md) | 备用字体信息结构体。  | 
| struct    [OH_Drawing_FontFallbackGroup](_o_h___drawing___font_fallback_group.md) | 备用字体集信息结构体。  | 
| struct    [OH_Drawing_FontAdjustInfo](_o_h___drawing___font_adjust_info.md) | 字重映射信息结构体。  | 
| struct    [OH_Drawing_FontAliasInfo](_o_h___drawing___font_alias_info.md) | 别名字体信息结构体。  | 
| struct    [OH_Drawing_FontGenericInfo](_o_h___drawing___font_generic_info.md) | 系统所支持的通用字体集信息结构体。  | 
| struct    [OH_Drawing_FontConfigInfo](_o_h___drawing___font_config_info.md) | 系统字体配置信息结构体。  | 
| struct    [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) | 定义字体样式信息的结构体。  | 
| struct    [OH_Drawing_FontFeature](_o_h___drawing___font_feature.md) | 描述文本字体特征结构体。  | 
| struct    [OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) | 用于描述支柱样式的结构体。支柱样式用于控制绘制文本时行之间的间距、基线对齐方式以及其他与行高相关的属性。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [OH_Drawing_PlaceholderVerticalAlignment](_drawing.md#oh_drawing_placeholderverticalalignment-1) [OH_Drawing_PlaceholderVerticalAlignment](_drawing.md#oh_drawing_placeholderverticalalignment) | 占位符垂直对齐枚举。  | 
| typedef struct [OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md) [OH_Drawing_PlaceholderSpan](_drawing.md#oh_drawing_placeholderspan) | 用于描述占位符跨度的结构体。  | 
| typedef enum [OH_Drawing_TextDecorationStyle](_drawing.md#oh_drawing_textdecorationstyle-1) [OH_Drawing_TextDecorationStyle](_drawing.md#oh_drawing_textdecorationstyle) | 文本装饰样式枚举。  | 
| typedef enum [OH_Drawing_EllipsisModal](_drawing.md#oh_drawing_ellipsismodal-1) [OH_Drawing_EllipsisModal](_drawing.md#oh_drawing_ellipsismodal) | 省略号样式枚举。  | 
| typedef enum [OH_Drawing_BreakStrategy](_drawing.md#oh_drawing_breakstrategy-1) [OH_Drawing_BreakStrategy](_drawing.md#oh_drawing_breakstrategy) | 文本的中断策略枚举。  | 
| typedef enum [OH_Drawing_WordBreakType](_drawing.md#oh_drawing_wordbreaktype-1) [OH_Drawing_WordBreakType](_drawing.md#oh_drawing_wordbreaktype) | 单词的断词方式枚举。  | 
| typedef enum [OH_Drawing_RectHeightStyle](_drawing.md#oh_drawing_rectheightstyle-1) [OH_Drawing_RectHeightStyle](_drawing.md#oh_drawing_rectheightstyle) | 矩形框高度样式枚举。  | 
| typedef enum [OH_Drawing_RectWidthStyle](_drawing.md#oh_drawing_rectwidthstyle-1) [OH_Drawing_RectWidthStyle](_drawing.md#oh_drawing_rectwidthstyle) | 矩形框宽度样式枚举。  | 
| typedef struct [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) [OH_Drawing_FontDescriptor](_drawing.md#oh_drawing_fontdescriptor) | 描述系统字体详细信息的结构体。  | 
| typedef struct [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) [OH_Drawing_LineMetrics](_drawing.md#oh_drawing_linemetrics) | 文字行位置信息。  | 
| typedef struct [OH_Drawing_FontFallbackInfo](_o_h___drawing___font_fallback_info.md) [OH_Drawing_FontFallbackInfo](_drawing.md#oh_drawing_fontfallbackinfo) | 备用字体信息结构体。  | 
| typedef struct [OH_Drawing_FontFallbackGroup](_o_h___drawing___font_fallback_group.md) [OH_Drawing_FontFallbackGroup](_drawing.md#oh_drawing_fontfallbackgroup) | 备用字体集信息结构体。  | 
| typedef struct [OH_Drawing_FontAdjustInfo](_o_h___drawing___font_adjust_info.md) [OH_Drawing_FontAdjustInfo](_drawing.md#oh_drawing_fontadjustinfo) | 字重映射信息结构体。  | 
| typedef struct [OH_Drawing_FontAliasInfo](_o_h___drawing___font_alias_info.md) [OH_Drawing_FontAliasInfo](_drawing.md#oh_drawing_fontaliasinfo) | 别名字体信息结构体。  | 
| typedef struct [OH_Drawing_FontGenericInfo](_o_h___drawing___font_generic_info.md) [OH_Drawing_FontGenericInfo](_drawing.md#oh_drawing_fontgenericinfo) | 系统所支持的通用字体集信息结构体。  | 
| typedef struct [OH_Drawing_FontConfigInfo](_o_h___drawing___font_config_info.md) [OH_Drawing_FontConfigInfo](_drawing.md#oh_drawing_fontconfiginfo) | 系统字体配置信息结构体。  | 
| typedef struct [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) [OH_Drawing_FontStyleStruct](_drawing.md#oh_drawing_fontstylestruct) | 定义字体样式信息的结构体。  | 
| typedef struct [OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) [OH_Drawing_StrutStyle](_drawing.md#oh_drawing_strutstyle) | 用于描述支柱样式的结构体。支柱样式用于控制绘制文本时行之间的间距、基线对齐方式以及其他与行高相关的属性。  | 


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_TextDirection](_drawing.md#oh_drawing_textdirection) { TEXT_DIRECTION_RTL, TEXT_DIRECTION_LTR } | 文字方向。  |
| [OH_Drawing_TextAlign](_drawing.md#oh_drawing_textalign) {<br/>TEXT_ALIGN_LEFT, TEXT_ALIGN_RIGHT, TEXT_ALIGN_CENTER, TEXT_ALIGN_JUSTIFY,<br/>TEXT_ALIGN_START, TEXT_ALIGN_END<br/>} | 文字对齐方式。  |
| [OH_Drawing_FontWeight](_drawing.md#oh_drawing_fontweight) {<br/>FONT_WEIGHT_100, FONT_WEIGHT_200, FONT_WEIGHT_300, FONT_WEIGHT_400,<br/>FONT_WEIGHT_500, FONT_WEIGHT_600, FONT_WEIGHT_700, FONT_WEIGHT_800,<br/>FONT_WEIGHT_900<br/>} | 字重。  |
| [OH_Drawing_TextBaseline](_drawing.md#oh_drawing_textbaseline) { TEXT_BASELINE_ALPHABETIC, TEXT_BASELINE_IDEOGRAPHIC } | 基线位置。  |
| [OH_Drawing_TextDecoration](_drawing.md#oh_drawing_textdecoration) { TEXT_DECORATION_NONE = 0x0, TEXT_DECORATION_UNDERLINE = 0x1, TEXT_DECORATION_OVERLINE = 0x2, TEXT_DECORATION_LINE_THROUGH = 0x4 } | 文本装饰。  |
| [OH_Drawing_FontStyle](_drawing.md#oh_drawing_fontstyle) { FONT_STYLE_NORMAL, FONT_STYLE_ITALIC, FONT_STYLE_OBLIQUE } | 区分字体是否为斜体。  |
| [OH_Drawing_PlaceholderVerticalAlignment](_drawing.md#oh_drawing_placeholderverticalalignment) {<br/>ALIGNMENT_OFFSET_AT_BASELINE, ALIGNMENT_ABOVE_BASELINE, ALIGNMENT_BELOW_BASELINE, ALIGNMENT_TOP_OF_ROW_BOX,<br/>ALIGNMENT_BOTTOM_OF_ROW_BOX, ALIGNMENT_CENTER_OF_ROW_BOX<br/>} | 占位符垂直对齐枚举。  |
| [OH_Drawing_TextDecorationStyle](_drawing.md#oh_drawing_textdecorationstyle) {<br/>TEXT_DECORATION_STYLE_SOLID, TEXT_DECORATION_STYLE_DOUBLE, TEXT_DECORATION_STYLE_DOTTED, TEXT_DECORATION_STYLE_DASHED,<br/>TEXT_DECORATION_STYLE_WAVY<br/>} | 文本装饰样式枚举。  |
| [OH_Drawing_EllipsisModal](_drawing.md#oh_drawing_ellipsismodal) { ELLIPSIS_MODAL_HEAD = 0, ELLIPSIS_MODAL_MIDDLE = 1, ELLIPSIS_MODAL_TAIL = 2 } | 省略号样式枚举。  |
| [OH_Drawing_BreakStrategy](_drawing.md#oh_drawing_breakstrategy) { BREAK_STRATEGY_GREEDY = 0, BREAK_STRATEGY_HIGH_QUALITY = 1, BREAK_STRATEGY_BALANCED = 2 } | 文本的中断策略枚举。  |
| [OH_Drawing_WordBreakType](_drawing.md#oh_drawing_wordbreaktype) { WORD_BREAK_TYPE_NORMAL = 0, WORD_BREAK_TYPE_BREAK_ALL = 1, WORD_BREAK_TYPE_BREAK_WORD = 2, WORD_BREAK_TYPE_BREAK_HYPHEN = 3 } | 单词的断词方式枚举。  |
| [OH_Drawing_RectHeightStyle](_drawing.md#oh_drawing_rectheightstyle) {<br/>RECT_HEIGHT_STYLE_TIGHT, [RECT_HEIGHT_STYLE_MAX, RECT_HEIGHT_STYLE_INCLUDELINESPACEMIDDLE, RECT_HEIGHT_STYLE_INCLUDELINESPACETOP,<br/>RECT_HEIGHT_STYLE_INCLUDELINESPACEBOTTOM, RECT_HEIGHT_STYLE_STRUCT<br/>} | 矩形框高度样式枚举。  |
| [OH_Drawing_RectWidthStyle](_drawing.md#oh_drawing_rectwidthstyle) { RECT_WIDTH_STYLE_TIGHT, RECT_WIDTH_STYLE_MAX } | 矩形框宽度样式枚举。  |
| [OH_Drawing_FontConfigInfoErrorCode](_drawing.md#oh_drawing_fontconfiginfoerrorcode) {<br/>SUCCESS_FONT_CONFIG_INFO = 0, ERROR_FONT_CONFIG_INFO_UNKNOWN = 1, ERROR_FONT_CONFIG_INFO_PARSE_FILE = 2, ERROR_FONT_CONFIG_INFO_ALLOC_MEMORY = 3,<br/>ERROR_FONT_CONFIG_INFO_COPY_STRING_DATA = 4<br/>} | 获取系统字体配置信息列表结果枚举。  |
| [OH_Drawing_FontWidth](_drawing.md#oh_drawing_fontwidth) {<br/>ULTRA_CONDENSED_WIDTH = 1, EXTRA_CONDENSED_WIDTH = 2, CONDENSED_WIDTH = 3, SEMI_CONDENSED_WIDTH = 4,<br/>NORMAL_WIDTH = 5, SEMI_EXPANDED_WIDTH = 6, EXPANDED_WIDTH = 7, EXTRA_EXPANDED_WIDTH = 8,<br/>ULTRA_EXPANDED_WIDTH = 9<br/>} | 字体宽度的枚举。  |
| [OH_Drawing_TextHeightBehavior](_drawing.md#oh_drawing_textheightbehavior) { TEXT_HEIGHT_ALL = 0x0, TEXT_HEIGHT_DISABLE_FIRST_ASCENT = 0x1, TEXT_HEIGHT_DISABLE_LAST_ASCENT = 0x2, TEXT_HEIGHT_DISABLE_ALL = 0x1 \| 0x2 } | 文本高度修饰符模式枚举。  |
| [OH_Drawing_TextStyleType](_drawing.md#oh_drawing_textstyletype) {<br/>TEXT_STYLE_NONE, TEXT_STYLE_ALL_ATTRIBUTES, TEXT_STYLE_FONT, TEXT_STYLE_FOREGROUND,<br/>TEXT_STYLE_BACKGROUND, TEXT_STYLE_SHADOW, TEXT_STYLE_DECORATIONS, TEXT_STYLE_LETTER_SPACING,<br/>TEXT_STYLE_WORD_SPACING<br/>} | 文本样式类型枚举。  |


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \* [OH_Drawing_CreateTypographyStyle](_drawing.md#oh_drawing_createtypographystyle) (void) | 创建指向OH_Drawing_TypographyStyle对象的指针。不再需要[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)时，请使用[OH_Drawing_DestroyTypographyStyle](_drawing.md#oh_drawing_destroytypographystyle)接口释放该对象的指针。  | 
| void [OH_Drawing_DestroyTypographyStyle](_drawing.md#oh_drawing_destroytypographystyle) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*) | 释放被OH_Drawing_TypographyStyle对象占据的内存。  | 
| void [OH_Drawing_SetTypographyTextDirection](_drawing.md#oh_drawing_settypographytextdirection) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | 设置指定排版样式中的文本方向。  | 
| void [OH_Drawing_SetTypographyTextAlign](_drawing.md#oh_drawing_settypographytextalign) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | 设置文本对齐方式。  | 
| int [OH_Drawing_TypographyGetEffectiveAlignment](_drawing.md#oh_drawing_typographygeteffectivealignment) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*style) | 获取文字对齐方式。  | 
| void [OH_Drawing_SetTypographyTextMaxLines](_drawing.md#oh_drawing_settypographytextmaxlines) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | 设置文本最大行数。  | 
| [OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \* [OH_Drawing_CreateTextStyle](_drawing.md#oh_drawing_createtextstyle) (void) | 创建指向OH_Drawing_TextStyle对象的指针。  | 
| [OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \* [OH_Drawing_TypographyGetTextStyle](_drawing.md#oh_drawing_typographygettextstyle) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*style) | 获取指定排版样式中设置的默认文本样式。  | 
| void [OH_Drawing_DestroyTextStyle](_drawing.md#oh_drawing_destroytextstyle) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 释放被OH_Drawing_TextStyle对象占据的内存。  | 
| void [OH_Drawing_SetTextStyleColor](_drawing.md#oh_drawing_settextstylecolor) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, uint32_t) | 设置文本颜色。  | 
| void [OH_Drawing_SetTextStyleFontSize](_drawing.md#oh_drawing_settextstylefontsize) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, double) | 设置字号。  | 
| void [OH_Drawing_SetTextStyleFontWeight](_drawing.md#oh_drawing_settextstylefontweight) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | 为指定文本样式设置字重。目前只有系统默认字体支持字重的调节，其他字体设置字重值小于semi-bold时字体粗细无变化，当设置字重值大于等于semi-bold时可能会触发伪加粗效果。 |
| void [OH_Drawing_SetTextStyleBaseLine](_drawing.md#oh_drawing_settextstylebaseline) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | 设置文本样式的字体基线位置。 |
| void [OH_Drawing_SetTextStyleDecoration](_drawing.md#oh_drawing_settextstyledecoration) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | 设置指定文本样式中的装饰线类型，只能设置一个装饰线类型，添加多个需要使用[OH_Drawing_AddTextStyleDecoration](_drawing.md#oh_drawing_addtextstyledecoration)。 | 
| void [OH_Drawing_AddTextStyleDecoration](_drawing.md#oh_drawing_addtextstyledecoration) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | 新增指定装饰，可同时显示多种装饰线。  | 
| void [OH_Drawing_RemoveTextStyleDecoration](_drawing.md#oh_drawing_removetextstyledecoration) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | 删除指定装饰。  | 
| void [OH_Drawing_SetTextStyleDecorationColor](_drawing.md#oh_drawing_settextstyledecorationcolor) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, uint32_t) | 设置指定文本样式中的装饰线颜色。  | 
| void [OH_Drawing_SetTextStyleFontHeight](_drawing.md#oh_drawing_settextstylefontheight) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, double) | 设置行高，按当前字体大小的倍数进行设置。  | 
| void [OH_Drawing_SetTextStyleFontFamilies](_drawing.md#oh_drawing_settextstylefontfamilies) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int, const char \*fontFamilies[]) | 设置指定文本样式的字体家族类型。  |
| void [OH_Drawing_SetTextStyleFontStyle](_drawing.md#oh_drawing_settextstylefontstyle) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | 为指定文本样式设置字体样式。  |
| void [OH_Drawing_SetTextStyleLocale](_drawing.md#oh_drawing_settextstylelocale) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, const char \*) | 设置文本语言环境。  |
| void [OH_Drawing_SetTextStyleForegroundBrush](_drawing.md#oh_drawing_settextstyleforegroundbrush) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | 设置指定文本样式中的前景色画刷。  | 
| void [OH_Drawing_TextStyleGetForegroundBrush](_drawing.md#oh_drawing_textstylegetforegroundbrush) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | 返回设置的前景色画刷。  | 
| void [OH_Drawing_SetTextStyleForegroundPen](_drawing.md#oh_drawing_settextstyleforegroundpen) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | 设置指定文本样式中的前景色画笔。  | 
| void [OH_Drawing_TextStyleGetForegroundPen](_drawing.md#oh_drawing_textstylegetforegroundpen) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | 返回设置的前景色画笔。  | 
| void [OH_Drawing_SetTextStyleBackgroundBrush](_drawing.md#oh_drawing_settextstylebackgroundbrush) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | 设置指定文本样式中的背景色画刷。  | 
| void [OH_Drawing_TextStyleGetBackgroundBrush](_drawing.md#oh_drawing_textstylegetbackgroundbrush) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | 返回设置的背景色画刷。  | 
| void [OH_Drawing_SetTextStyleBackgroundPen](_drawing.md#oh_drawing_settextstylebackgroundpen) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | 设置指定文本样式中的背景色画笔。  | 
| void [OH_Drawing_TextStyleGetBackgroundPen](_drawing.md#oh_drawing_textstylegetbackgroundpen) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | 返回设置的背景色画笔。  | 
| [OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \* [OH_Drawing_CreateTypographyHandler](_drawing.md#oh_drawing_createtypographyhandler) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, [OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection) \*) | 创建指向OH_Drawing_TypographyCreate对象的指针。不再需要[OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate)时，请使用[OH_Drawing_DestroyTypographyHandler](_drawing.md#oh_drawing_destroytypographyhandler)接口释放该对象的指针。  | 
| void [OH_Drawing_DestroyTypographyHandler](_drawing.md#oh_drawing_destroytypographyhandler) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*) | 释放被OH_Drawing_TypographyCreate对象占据的内存。  | 
| void [OH_Drawing_TypographyHandlerPushTextStyle](_drawing.md#oh_drawing_typographyhandlerpushtextstyle) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*, [OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 将指定文本样式压入文本样式栈，后续添加的文本总是会使用栈顶的文本样式。  | 
| void [OH_Drawing_TypographyHandlerAddText](_drawing.md#oh_drawing_typographyhandleraddtext) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*, const char \*) | 设置文本内容。  | 
| void [OH_Drawing_TypographyHandlerPopTextStyle](_drawing.md#oh_drawing_typographyhandlerpoptextstyle) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*) | 从文本样式栈中弹出栈顶文本样式。  | 
| [OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \* [OH_Drawing_CreateTypography](_drawing.md#oh_drawing_createtypography) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*) | 创建指向OH_Drawing_Typography对象的指针。不再需要[OH_Drawing_Typography](_drawing.md#oh_drawing_typography)时，请使用[OH_Drawing_DestroyTypography](_drawing.md#oh_drawing_destroytypography)接口释放该对象的指针。  | 
| void [OH_Drawing_DestroyTypography](_drawing.md#oh_drawing_destroytypography) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 释放OH_Drawing_Typography对象占据的内存。  | 
| void [OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, double) | 排版布局。  | 
| void [OH_Drawing_TypographyPaint](_drawing.md#oh_drawing_typographypaint) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, [OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, double, double) | 在指定位置绘制文本，从左上角开始绘制，该接口需要在[OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout)接口调用并生效之后调用。  | 
| void [OH_Drawing_TypographyPaintOnPath](_drawing.md#oh_drawing_typographypaintonpath) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \* typography, [OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \* canvas, [OH_Drawing_Path](_drawing.md#oh_drawing_path) \* path, double hOffset, double vOffset) | 沿指定路径绘制文本。建议搭配[OH_Drawing_SetTypographyTextMaxLines](_drawing.md#oh_drawing_settypographytextmaxlines)接口设置最大行为1行，避免因文本宽度超过排版宽度出现跨行重叠问题。   | 
| double [OH_Drawing_TypographyGetMaxWidth](_drawing.md#oh_drawing_typographygetmaxwidth) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 获取用户设置的排版宽度，该接口需要在[OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout)接口调用之后调用。  | 
| double [OH_Drawing_TypographyGetHeight](_drawing.md#oh_drawing_typographygetheight) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 获取排版对象整体的高度，该接口需要在[OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout)接口调用之后调用。  | 
| double [OH_Drawing_TypographyGetLongestLine](_drawing.md#oh_drawing_typographygetlongestline) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 获取排版对象最长行的宽度，该接口需要在[OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout)接口调用之后调用，建议实际使用时将返回值向上取整。当文本内容为空时，返回0.0。  | 
| double [OH_Drawing_TypographyGetLongestLineWithIndent](_drawing.md#oh_drawing_typographygetlongestlinewithindent) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 获取排版对象最长行的宽度（该宽度包含当前行缩进的宽度），该接口需要在[OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout)接口调用之后调用，建议实际使用时将返回值向上取整。当文本内容为空时，返回0.0。  | 
| double [OH_Drawing_TypographyGetMinIntrinsicWidth](_drawing.md#oh_drawing_typographygetminintrinsicwidth) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 获取排版对象的最小固有宽度，该接口需要在[OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout)接口调用之后调用。  | 
| double [OH_Drawing_TypographyGetMaxIntrinsicWidth](_drawing.md#oh_drawing_typographygetmaxintrinsicwidth) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 获取排版对象的最大固有宽度，该接口需要在[OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout)接口调用之后调用。  | 
| double [OH_Drawing_TypographyGetAlphabeticBaseline](_drawing.md#oh_drawing_typographygetalphabeticbaseline) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 获取排版样式字母文字基线。  |
| double [OH_Drawing_TypographyGetIdeographicBaseline](_drawing.md#oh_drawing_typographygetideographicbaseline) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 获取排版样式表意文字基线。  |
| void [OH_Drawing_TypographyHandlerAddPlaceholder](_drawing.md#oh_drawing_typographyhandleraddplaceholder) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*, [OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md) \*) | 设置占位符。  | 
| bool [OH_Drawing_TypographyDidExceedMaxLines](_drawing.md#oh_drawing_typographydidexceedmaxlines) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 获取排版对象中文本是否超过最大行，该接口需要在[OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout)接口调用之后调用，如果没有通过[OH_Drawing_SetTypographyTextMaxLines](_drawing.md#oh_drawing_settypographytextmaxlines)接口设置最大行，则返回false。  | 
| [OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \* [OH_Drawing_TypographyGetRectsForRange](_drawing.md#oh_drawing_typographygetrectsforrange) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, size_t, size_t, [OH_Drawing_RectHeightStyle](_drawing.md#oh_drawing_rectheightstyle), [OH_Drawing_RectWidthStyle](_drawing.md#oh_drawing_rectwidthstyle)) | 获取排版对象中指定范围内的文本框，该接口需要在[OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout)接口调用之后调用。不再需要[OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox)时，请使用[OH_Drawing_TypographyDestroyTextBox](_drawing.md#oh_drawing_typographydestroytextbox)接口释放该对象的指针。  | 
| [OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \* [OH_Drawing_TypographyGetRectsForPlaceholders](_drawing.md#oh_drawing_typographygetrectsforplaceholders) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 获取排版对象中占位符的文本框，该接口需要在[OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout)接口调用之后调用。不再需要[OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox)时，请使用[OH_Drawing_TypographyDestroyTextBox](_drawing.md#oh_drawing_typographydestroytextbox)接口释放该对象的指针。  | 
| float [OH_Drawing_GetLeftFromTextBox](_drawing.md#oh_drawing_getleftfromtextbox) ([OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \*, int) | 获取文本框左侧位置。  | 
| float [OH_Drawing_GetRightFromTextBox](_drawing.md#oh_drawing_getrightfromtextbox) ([OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \*, int) | 获取文本框右侧位置。  | 
| float [OH_Drawing_GetTopFromTextBox](_drawing.md#oh_drawing_gettopfromtextbox) ([OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \*, int) | 获取文本框顶部位置。  | 
| float [OH_Drawing_GetBottomFromTextBox](_drawing.md#oh_drawing_getbottomfromtextbox) ([OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \*, int) | 获取文本框底部位置。  | 
| int [OH_Drawing_GetTextDirectionFromTextBox](_drawing.md#oh_drawing_gettextdirectionfromtextbox) ([OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \*, int) | 获取文本框方向。  | 
| size_t [OH_Drawing_GetSizeOfTextBox](_drawing.md#oh_drawing_getsizeoftextbox) ([OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \*) | 获取文本框数量大小。  | 
| [OH_Drawing_PositionAndAffinity](_drawing.md#oh_drawing_positionandaffinity) \* [OH_Drawing_TypographyGetGlyphPositionAtCoordinate](_drawing.md#oh_drawing_typographygetglyphpositionatcoordinate) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, double, double) | 获取坐标处文本的索引位置和亲和性。  | 
| [OH_Drawing_PositionAndAffinity](_drawing.md#oh_drawing_positionandaffinity) \* [OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster](_drawing.md#oh_drawing_typographygetglyphpositionatcoordinatewithcluster) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, double, double) | 获取坐标处文本所属字符簇的索引位置和亲和性，字符簇指一个或多个字符组成的整体。  | 
| size_t [OH_Drawing_GetPositionFromPositionAndAffinity](_drawing.md#oh_drawing_getpositionfrompositionandaffinity) ([OH_Drawing_PositionAndAffinity](_drawing.md#oh_drawing_positionandaffinity) \*) | 获取OH_Drawing_PositionAndAffinity对象的位置属性。  | 
| int [OH_Drawing_GetAffinityFromPositionAndAffinity](_drawing.md#oh_drawing_getaffinityfrompositionandaffinity) ([OH_Drawing_PositionAndAffinity](_drawing.md#oh_drawing_positionandaffinity) \*) | 获取OH_Drawing_PositionAndAffinity对象的亲和性，根据亲和性可判断字体会靠近前方文本还是后方文本。  | 
| [OH_Drawing_Range](_drawing.md#oh_drawing_range) \* [OH_Drawing_TypographyGetWordBoundary](_drawing.md#oh_drawing_typographygetwordboundary) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, size_t) | 获取排版对象中单词的边界。  | 
| size_t [OH_Drawing_GetStartFromRange](_drawing.md#oh_drawing_getstartfromrange) ([OH_Drawing_Range](_drawing.md#oh_drawing_range) \*) | 获取OH_Drawing_Range对象开始位置。  | 
| size_t [OH_Drawing_GetEndFromRange](_drawing.md#oh_drawing_getendfromrange) ([OH_Drawing_Range](_drawing.md#oh_drawing_range) \*) | 获取OH_Drawing_Range对象结束位置。  | 
| size_t [OH_Drawing_TypographyGetLineCount](_drawing.md#oh_drawing_typographygetlinecount) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 获取排版对象中文本行数，该接口需要在[OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout)接口调用之后调用。  | 
| void [OH_Drawing_SetTextStyleDecorationStyle](_drawing.md#oh_drawing_settextstyledecorationstyle) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | 设置指定文本样式中的装饰线样式。  | 
| void [OH_Drawing_SetTextStyleDecorationThicknessScale](_drawing.md#oh_drawing_settextstyledecorationthicknessscale) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, double) | 设置文本装饰线的厚度缩放比例。  | 
| void [OH_Drawing_SetTextStyleLetterSpacing](_drawing.md#oh_drawing_settextstyleletterspacing) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, double) | 设置文本的字符间距。  | 
| void [OH_Drawing_SetTextStyleWordSpacing](_drawing.md#oh_drawing_settextstylewordspacing) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, double) | 设置文本的单词间距。  | 
| void [OH_Drawing_SetTextStyleHalfLeading](_drawing.md#oh_drawing_settextstylehalfleading) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, bool) | 设置文本为一半行间距。  | 
| void [OH_Drawing_SetTextStyleEllipsis](_drawing.md#oh_drawing_settextstyleellipsis) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, const char \*) | 设置文本的省略号内容。  | 
| void [OH_Drawing_SetTextStyleEllipsisModal](_drawing.md#oh_drawing_settextstyleellipsismodal) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | 设置文本的省略号样式。  | 
| void [OH_Drawing_SetTypographyTextBreakStrategy](_drawing.md#oh_drawing_settypographytextbreakstrategy) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | 设置文本的中断策略。  | 
| void [OH_Drawing_SetTypographyTextWordBreakType](_drawing.md#oh_drawing_settypographytextwordbreaktype) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | 设置单词的断词方式。  | 
| void [OH_Drawing_SetTypographyTextEllipsisModal](_drawing.md#oh_drawing_settypographytextellipsismodal) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | 设置排版样式省略模式。  |
| void [OH_Drawing_SetTypographyTextEllipsis](_drawing.md#oh_drawing_settypographytextellipsis) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*style, const char \*ellipsis) | 设置省略号样式。  | 
| double [OH_Drawing_TypographyGetLineHeight](_drawing.md#oh_drawing_typographygetlineheight) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, int) | 获取排版对象中指定行的行高，该接口需要在[OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout)接口调用之后调用。  | 
| double [OH_Drawing_TypographyGetLineWidth](_drawing.md#oh_drawing_typographygetlinewidth) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, int) | 获取指定行的行宽，该接口需要在[OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout)接口调用之后调用。  | 
| void [OH_Drawing_SetTypographyTextSplitRatio](_drawing.md#oh_drawing_settypographytextsplitratio) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*style, float textSplitRatio) | 设置文本划分比率。  | 
| bool [OH_Drawing_TypographyIsLineUnlimited](_drawing.md#oh_drawing_typographyislineunlimited) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*style) | 获取文本是否有最大行数限制。  | 
| bool [OH_Drawing_TypographyIsEllipsized](_drawing.md#oh_drawing_typographyisellipsized) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*style) | 获取指定排版样式是否配置省略号。  | 
| void [OH_Drawing_SetTypographyTextLocale](_drawing.md#oh_drawing_settypographytextlocale) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*style, const char \*locale) | 设置指定排版样式的语言环境。 |
| bool [OH_Drawing_TextStyleGetFontMetrics](_drawing.md#oh_drawing_textstylegetfontmetrics) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, [OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) \*) | 获取文本字体属性。  | 
| void [OH_Drawing_SetTypographyTextStyle](_drawing.md#oh_drawing_settypographytextstyle) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, [OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 设置排版样式。  | 
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \* [OH_Drawing_CreateFontDescriptor](_drawing.md#oh_drawing_createfontdescriptor) (void) | 构造字体描述对象，用于描述系统字体详细信息。  | 
| void [OH_Drawing_DestroyFontDescriptor](_drawing.md#oh_drawing_destroyfontdescriptor) ([OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \*) | 释放字体描述对象占用的内存。  | 
| [OH_Drawing_FontParser](_drawing.md#oh_drawing_fontparser) \* [OH_Drawing_CreateFontParser](_drawing.md#oh_drawing_createfontparser) (void) | 构造字体解析对象，用于解析系统字体。  | 
| void [OH_Drawing_DestroyFontParser](_drawing.md#oh_drawing_destroyfontparser) ([OH_Drawing_FontParser](_drawing.md#oh_drawing_fontparser) \*) | 释放字体解析对象占用的内存。  | 
| char \*\* [OH_Drawing_FontParserGetSystemFontList](_drawing.md#oh_drawing_fontparsergetsystemfontlist) ([OH_Drawing_FontParser](_drawing.md#oh_drawing_fontparser) \*, size_t \*) | 获取系统字体名称列表，此接口仅在2in1、phone设备上可用。  | 
| void [OH_Drawing_DestroySystemFontList](_drawing.md#oh_drawing_destroysystemfontlist) (char \*\*, size_t) | 释放系统字体名称列表占用的内存。  | 
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \* [OH_Drawing_FontParserGetFontByName](_drawing.md#oh_drawing_fontparsergetfontbyname) ([OH_Drawing_FontParser](_drawing.md#oh_drawing_fontparser) \*, const char \*) | 根据传入的系统字体名称获取系统字体的相关信息。  | 
| [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \* [OH_Drawing_TypographyGetLineMetrics](_drawing.md#oh_drawing_typographygetlinemetrics) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 获取排版对象的行位置信息，该接口需要在[OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout)接口调用之后调用。不再需要[OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md)时，请使用[OH_Drawing_DestroyLineMetrics](_drawing.md#oh_drawing_destroylinemetrics)接口释放该对象的指针。  | 
| size_t [OH_Drawing_LineMetricsGetSize](_drawing.md#oh_drawing_linemetricsgetsize) ([OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \*) | 获取行数量。  | 
| void [OH_Drawing_DestroyLineMetrics](_drawing.md#oh_drawing_destroylinemetrics) ([OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \*) | 释放行位置信息对象占用的内存。  | 
| bool [OH_Drawing_TypographyGetLineMetricsAt](_drawing.md#oh_drawing_typographygetlinemetricsat) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, int, [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \*) | 获取排版对象的指定行位置信息，具体参见[OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md)结构体，该接口需要在[OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout)接口调用之后调用。  | 
| bool [OH_Drawing_TypographyGetLineInfo](_drawing.md#oh_drawing_typographygetlineinfo) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, int, bool, bool, [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \*) | 获取排版对象中指定行的位置信息或指定行第一个字符的位置信息，该接口需要在[OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout)接口调用之后调用。  | 
| void [OH_Drawing_SetTypographyTextFontWeight](_drawing.md#oh_drawing_settypographytextfontweight) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | 设置排版样式默认字重。目前只有系统默认字体支持字重的调节，其他字体设置字重值小于semi-bold时字体粗细无变化，当设置字重值大于等于semi-bold时可能会触发伪加粗效果。 |
| void [OH_Drawing_SetTypographyTextFontStyle](_drawing.md#oh_drawing_settypographytextfontstyle) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | 设置排版样式默认的字体样式。  |
| void [OH_Drawing_SetTypographyTextFontFamily](_drawing.md#oh_drawing_settypographytextfontfamily) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, const char \*) | 设置字体家族的名称。  | 
| void [OH_Drawing_SetTypographyTextFontSize](_drawing.md#oh_drawing_settypographytextfontsize) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, double) | 设置文本排版字号。  | 
| void [OH_Drawing_SetTypographyTextFontHeight](_drawing.md#oh_drawing_settypographytextfontheight) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, double) | 设置文本排版字体高度。  | 
| void [OH_Drawing_SetTypographyTextHalfLeading](_drawing.md#oh_drawing_settypographytexthalfleading) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, bool) | 设置文本排版是否为一半行间距。  | 
| void [OH_Drawing_SetTypographyTextUseLineStyle](_drawing.md#oh_drawing_settypographytextuselinestyle) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, bool) | 设置文本排版是否启用行样式。  | 
| void [OH_Drawing_SetTypographyTextLineStyleFontWeight](_drawing.md#oh_drawing_settypographytextlinestylefontweight) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | 设置排版样式中支柱样式的文本样式字重。目前只有系统默认字体支持字重的调节，其他字体设置字重值小于semi-bold时字体粗细无变化，当设置字重值大于等于semi-bold时可能会触发伪加粗效果。 |
| void [OH_Drawing_SetTypographyTextLineStyleFontStyle](_drawing.md#oh_drawing_settypographytextlinestylefontstyle) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | 设置文本排版样式中支柱样式的字体样式。 |
| void [OH_Drawing_SetTypographyTextLineStyleFontFamilies](_drawing.md#oh_drawing_settypographytextlinestylefontfamilies) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int, const char \*fontFamilies[]) | 设置文本排版行样式字体类型。  | 
| void [OH_Drawing_SetTypographyTextLineStyleFontSize](_drawing.md#oh_drawing_settypographytextlinestylefontsize) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, double) | 设置文本排版行样式字号。  | 
| void [OH_Drawing_SetTypographyTextLineStyleFontHeight](_drawing.md#oh_drawing_settypographytextlinestylefontheight) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, double) | 设置文本排版行样式字体高度。  | 
| void [OH_Drawing_SetTypographyTextLineStyleHalfLeading](_drawing.md#oh_drawing_settypographytextlinestylehalfleading) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, bool) | 设置文本排版行样式中支柱样式是否开启一半行间距。 |
| void [OH_Drawing_SetTypographyTextLineStyleSpacingScale](_drawing.md#oh_drawing_settypographytextlinestylespacingscale) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, double) | 设置文本排版行样式间距比例。  | 
| void [OH_Drawing_SetTypographyTextLineStyleOnly](_drawing.md#oh_drawing_settypographytextlinestyleonly) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, bool) | 设置文本排版是否仅启用行样式。  | 
| [OH_Drawing_TextShadow](_drawing.md#oh_drawing_textshadow) \* [OH_Drawing_CreateTextShadow](_drawing.md#oh_drawing_createtextshadow) (void) | 创建指向字体阴影对象的指针。不再需要[OH_Drawing_TextShadow](_drawing.md#oh_drawing_textshadow)时，请使用[OH_Drawing_DestroyTextShadow](_drawing.md#oh_drawing_destroytextshadow)接口释放该对象的指针。  | 
| void [OH_Drawing_DestroyTextShadow](_drawing.md#oh_drawing_destroytextshadow) ([OH_Drawing_TextShadow](_drawing.md#oh_drawing_textshadow) \*) | 释放被字体阴影对象占据的内存。  | 
| [OH_Drawing_TextShadow](_drawing.md#oh_drawing_textshadow) \* [OH_Drawing_TextStyleGetShadows](_drawing.md#oh_drawing_textstylegetshadows) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 获取字体阴影容器。不再需要[OH_Drawing_TextShadow](_drawing.md#oh_drawing_textshadow)时，请使用[OH_Drawing_DestroyTextShadows](_drawing.md#oh_drawing_destroytextshadows)接口释放该对象的指针。  | 
| int [OH_Drawing_TextStyleGetShadowCount](_drawing.md#oh_drawing_textstylegetshadowcount) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 获取字体阴影容器的大小。  | 
| void [OH_Drawing_TextStyleAddShadow](_drawing.md#oh_drawing_textstyleaddshadow) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, const [OH_Drawing_TextShadow](_drawing.md#oh_drawing_textshadow) \*) | 字体阴影容器中添加字体阴影元素。  | 
| void [OH_Drawing_TextStyleClearShadows](_drawing.md#oh_drawing_textstyleclearshadows) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 清除字体阴影容器中的所有元素。  | 
| [OH_Drawing_TextShadow](_drawing.md#oh_drawing_textshadow) \* [OH_Drawing_TextStyleGetShadowWithIndex](_drawing.md#oh_drawing_textstylegetshadowwithindex) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | 根据下标获取字体阴影容器中的元素。  | 
| void [OH_Drawing_TypographySetIndents](_drawing.md#oh_drawing_typographysetindents) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, int, const float indents[]) | 设置文本的排版缩进，不调用此接口默认文本无缩进。  | 
| float [OH_Drawing_TypographyGetIndentsWithIndex](_drawing.md#oh_drawing_typographygetindentswithindex) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, int) | 根据行索引获取排版对象缩进容器中的元素，行索引从0开始。  | 
| [OH_Drawing_Range](_drawing.md#oh_drawing_range) \* [OH_Drawing_TypographyGetLineTextRange](_drawing.md#oh_drawing_typographygetlinetextrange) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, int, bool) | 获取排版对象中行的边界，该接口需要在[OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout)接口调用之后调用。该接口只能获取已有行的边界，即输入行索引从0开始，最大行索引为[OH_Drawing_TypographyGetLineCount](_drawing.md#oh_drawing_typographygetlinecount) - 1。  | 
| void [OH_Drawing_DestroyTextShadows](_drawing.md#oh_drawing_destroytextshadows) ([OH_Drawing_TextShadow](_drawing.md#oh_drawing_textshadow) \*) | 释放由被字体阴影对象OH_Drawing_TextShadow构成的vector占据的内存。  | 
| [OH_Drawing_FontConfigInfo](_o_h___drawing___font_config_info.md) \* [OH_Drawing_GetSystemFontConfigInfo](_drawing.md#oh_drawing_getsystemfontconfiginfo) ([OH_Drawing_FontConfigInfoErrorCode](_drawing.md#oh_drawing_fontconfiginfoerrorcode) \*) | 获取系统字体配置信息。  | 
| void [OH_Drawing_DestroySystemFontConfigInfo](_drawing.md#oh_drawing_destroysystemfontconfiginfo) ([OH_Drawing_FontConfigInfo](_o_h___drawing___font_config_info.md) \*) | 释放系统字体配置信息占用的的内存。  | 
| void [OH_Drawing_SetTextStyleFontStyleStruct](_drawing.md#oh_drawing_settextstylefontstylestruct) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*drawingTextStyle, [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) fontStyle) | 设置文本样式中的字体样式，包括字体字重、字体宽度和字体斜度。  | 
| [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) [OH_Drawing_TextStyleGetFontStyleStruct](_drawing.md#oh_drawing_textstylegetfontstylestruct) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*drawingTextStyle) | 获取文本样式中的字体样式，包括字体字重、字体宽度和字体斜度。  | 
| void [OH_Drawing_SetTypographyStyleFontStyleStruct](_drawing.md#oh_drawing_settypographystylefontstylestruct) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*drawingStyle, [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) fontStyle) | 设置排版样式中默认文本样式的字体样式，包括字体字重、字体宽度和字体斜度。 |
| [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) [OH_Drawing_TypographyStyleGetFontStyleStruct](_drawing.md#oh_drawing_typographystylegetfontstylestruct) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*drawingStyle) | 获取排版样式中默认文本样式的字体样式，包括字体字重、字体宽度和字体斜度。  | 
| void [OH_Drawing_TextStyleSetBackgroundRect](_drawing.md#oh_drawing_textstylesetbackgroundrect) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, const [OH_Drawing_RectStyle_Info](_o_h___drawing___rect_style___info.md) \*, int styleId) | 设置文本背景矩形框和样式id。样式id仅当背景框为圆角矩形时有效。  | 
| void [OH_Drawing_TypographyHandlerAddSymbol](_drawing.md#oh_drawing_typographyhandleraddsymbol) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*, uint32_t symbol) | 设置排版创建过程中的符号。  | 
| void [OH_Drawing_TextStyleAddFontFeature](_drawing.md#oh_drawing_textstyleaddfontfeature) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, const char \*tag, int value) | 设置文本样式中指定字体特征是否启用。 |
| void [OH_Drawing_TextStyleAddFontVariation](_drawing.md#oh_drawing_textstyleaddfontvariation) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, const char \*, const float) | 添加可变字体属性。对应的字体文件（.ttf文件）需要支持可变调节，此接口才能生效。当对应的字体不支持可变调节时，此接口调用不生效。  | 
| [OH_Drawing_FontFeature](_o_h___drawing___font_feature.md) \* [OH_Drawing_TextStyleGetFontFeatures](_drawing.md#oh_drawing_textstylegetfontfeatures) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 获取指定文本样式的字体特征map容器中所有内容。 |
| void [OH_Drawing_TextStyleDestroyFontFeatures](_drawing.md#oh_drawing_textstyledestroyfontfeatures) ([OH_Drawing_FontFeature](_o_h___drawing___font_feature.md) \*, size_t fontFeatureSize) | 释放存放字体特征所有内容的结构体数组所占用的空间。  | 
| size_t [OH_Drawing_TextStyleGetFontFeatureSize](_drawing.md#oh_drawing_textstylegetfontfeaturesize) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 获取指定文本样式中字体特征map容器的大小。 |
| void [OH_Drawing_TextStyleClearFontFeature](_drawing.md#oh_drawing_textstyleclearfontfeature) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 清除指定文本样式的字体特征map容器中所有内容。 |
| double [OH_Drawing_TextStyleGetBaselineShift](_drawing.md#oh_drawing_textstylegetbaselineshift) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 获取文本的基线偏移。 |
| void [OH_Drawing_TextStyleSetBaselineShift](_drawing.md#oh_drawing_textstylesetbaselineshift) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, double lineShift) | 设置文本样式基线偏移。 |
| void [OH_Drawing_TypographyTextSetHeightBehavior](_drawing.md#oh_drawing_typographytextsetheightbehavior) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, [OH_Drawing_TextHeightBehavior](_drawing.md#oh_drawing_textheightbehavior) heightMode) | 设置文本高度修饰符模式。  | 
| [OH_Drawing_TextHeightBehavior](_drawing.md#oh_drawing_textheightbehavior) [OH_Drawing_TypographyTextGetHeightBehavior](_drawing.md#oh_drawing_typographytextgetheightbehavior) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*) | 获取文本高度修饰符模式。  | 
| [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) \* [OH_Drawing_TypographyGetLineFontMetrics](_drawing.md#oh_drawing_typographygetlinefontmetrics) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, size_t lineNumber, size_t \*fontMetricsSize) | 从排版对象中目标行获取所有字体度量信息，该接口需要在[OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout)接口调用之后调用，否则会返回空指针。不再需要[OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md)时，请使用[OH_Drawing_TypographyDestroyLineFontMetrics](_drawing.md#oh_drawing_typographydestroylinefontmetrics)接口释放该对象的指针。 | 
| void [OH_Drawing_TypographyDestroyLineFontMetrics](_drawing.md#oh_drawing_typographydestroylinefontmetrics) ([OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) \*) | 释放指定行所有字体度量结构体集合所占用的所有空间。  | 
| bool [OH_Drawing_TextStyleIsEqual](_drawing.md#oh_drawing_textstyleisequal) (const [OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*style, const [OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*comparedStyle) | 判断两个文本样式对象是否相等，字宽属性不参与对比。  | 
| bool [OH_Drawing_TextStyleIsEqualByFont](_drawing.md#oh_drawing_textstyleisequalbyfont) (const [OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*style, const [OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*comparedStyle) | 判断两个字体样式对象的字体样式属性是否相等。  | 
| bool [OH_Drawing_TextStyleIsAttributeMatched](_drawing.md#oh_drawing_textstyleisattributematched) (const [OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*style, const [OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*comparedStyle, [OH_Drawing_TextStyleType](_drawing.md#oh_drawing_textstyletype) textStyleType) | 判断两个字体样式对象是否有一样的文本样式类型。  | 
| void [OH_Drawing_TextStyleSetPlaceholder](_drawing.md#oh_drawing_textstylesetplaceholder) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*style) | 设置占位符。  | 
| bool [OH_Drawing_TextStyleIsPlaceholder](_drawing.md#oh_drawing_textstyleisplaceholder) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*style) | 返回是否有设置文本占位符。  | 
| [OH_Drawing_TextAlign](_drawing.md#oh_drawing_textalign) [OH_Drawing_TypographyStyleGetEffectiveAlignment](_drawing.md#oh_drawing_typographystylegeteffectivealignment) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*style) | 获取文本对齐模式。  | 
| bool [OH_Drawing_TypographyStyleIsHintEnabled](_drawing.md#oh_drawing_typographystyleishintenabled) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*style) | 获取文本是否启用字形轮廓自动调整。字形轮廓自动调整用于在渲染小字号文本时改善其可读性和外观。  | 
| void [OH_Drawing_SetTypographyStyleTextStrutStyle](_drawing.md#oh_drawing_settypographystyletextstrutstyle) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, [OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) \*) | 设置文本支柱样式。  | 
| [OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) \* [OH_Drawing_TypographyStyleGetStrutStyle](_drawing.md#oh_drawing_typographystylegetstrutstyle) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*) | 获取文本支柱样式。  | 
| void [OH_Drawing_TypographyStyleDestroyStrutStyle](_drawing.md#oh_drawing_typographystyledestroystrutstyle) ([OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) \*) | 释放被支柱样式对象占据的内存。  | 
| bool [OH_Drawing_TypographyStyleStrutStyleEquals](_drawing.md#oh_drawing_typographystylestrutstyleequals) ([OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) \*from, [OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) \*to) | 判断支柱样式结构体是否相同。  | 
| void [OH_Drawing_TypographyStyleSetHintsEnabled](_drawing.md#oh_drawing_typographystylesethintsenabled) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*style, bool hintsEnabled) | 设置文本是否启用字形轮廓自动调整。字形轮廓自动调整用于在渲染小字号文本时改善其可读性和外观。  | 
| void [OH_Drawing_TypographyMarkDirty](_drawing.md#oh_drawing_typographymarkdirty) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 将排版标记为脏数据，用于初始化排版状态。  | 
| int32_t [OH_Drawing_TypographyGetUnresolvedGlyphsCount](_drawing.md#oh_drawing_typographygetunresolvedglyphscount) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | 获取文本中尚未解析的字形的数量，该接口需要在[OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout)接口调用并生效之后调用。  | 
| void [OH_Drawing_TypographyUpdateFontSize](_drawing.md#oh_drawing_typographyupdatefontsize) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, size_t from, size_t to, float fontSize) | 更新排版对象中的字体大小。  | 
| bool [OH_Drawing_TypographyTextGetLineStyle](_drawing.md#oh_drawing_typographytextgetlinestyle) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*) | 获取文本排版是否启用行样式。  | 
| [OH_Drawing_FontWeight](_drawing.md#oh_drawing_fontweight) [OH_Drawing_TypographyTextlineStyleGetFontWeight](_drawing.md#oh_drawing_typographytextlinestylegetfontweight) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*) | 获取排版样式中支柱样式字重。  |
| [OH_Drawing_FontStyle](_drawing.md#oh_drawing_fontstyle) [OH_Drawing_TypographyTextlineStyleGetFontStyle](_drawing.md#oh_drawing_typographytextlinestylegetfontstyle) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*) | 获取文本排版样式中支柱样式的字体样式。  |
| char \*\* [OH_Drawing_TypographyTextlineStyleGetFontFamilies](_drawing.md#oh_drawing_typographytextlinestylegetfontfamilies) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, size_t \*num) | 获取文本排版支柱样式字体家族名。  |
| void [OH_Drawing_TypographyTextlineStyleDestroyFontFamilies](_drawing.md#oh_drawing_typographytextlinestyledestroyfontfamilies) (char \*\*fontFamilies, size_t fontFamiliesNum) | 释放字体类型占用的内存。  | 
| double [OH_Drawing_TypographyTextlineStyleGetFontSize](_drawing.md#oh_drawing_typographytextlinestylegetfontsize) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*) | 获取文本排版行样式字号。  | 
| double [OH_Drawing_TypographyTextlineStyleGetHeightScale](_drawing.md#oh_drawing_typographytextlinestylegetheightscale) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*) | 获取文本排版行样式的行高缩放系数。  | 
| bool [OH_Drawing_TypographyTextlineStyleGetHeightOnly](_drawing.md#oh_drawing_typographytextlinestylegetheightonly) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*) | 获取字体渲染过程中计算字体块高度相关参数的方法。  | 
| bool [OH_Drawing_TypographyTextlineStyleGetHalfLeading](_drawing.md#oh_drawing_typographytextlinestylegethalfleading) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*) | 获取文本排版行样式是否为一半行间距。  | 
| double [OH_Drawing_TypographyTextlineStyleGetSpacingScale](_drawing.md#oh_drawing_typographytextlinestylegetspacingscale) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*) | 获取文本排版行样式间距比例。  | 
| bool [OH_Drawing_TypographyTextlineGetStyleOnly](_drawing.md#oh_drawing_typographytextlinegetstyleonly) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*) | 获取文本排版是否仅启用行样式。  | 
| [OH_Drawing_TextAlign](_drawing.md#oh_drawing_textalign) [OH_Drawing_TypographyGetTextAlign](_drawing.md#oh_drawing_typographygettextalign) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*) | 获取文本对齐方式。  | 
| [OH_Drawing_TextDirection](_drawing.md#oh_drawing_textdirection) [OH_Drawing_TypographyGetTextDirection](_drawing.md#oh_drawing_typographygettextdirection) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*) | 获取指定排版样式中的文本方向。  | 
| size_t [OH_Drawing_TypographyGetTextMaxLines](_drawing.md#oh_drawing_typographygettextmaxlines) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*) | 获取文本的最大行数。  | 
| char \* [OH_Drawing_TypographyGetTextEllipsis](_drawing.md#oh_drawing_typographygettextellipsis) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*) | 获取指定排版样式设置的省略号文本。 |
| void [OH_Drawing_TypographyDestroyEllipsis](_drawing.md#oh_drawing_typographydestroyellipsis) (char \*ellipsis) | 释放省略号名称列表占用的内存。  | 
| bool [OH_Drawing_TypographyStyleEquals](_drawing.md#oh_drawing_typographystyleequals) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*from, [OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*to) | 判断排版样式是否相同，当前文本高度修饰符模式[OH_Drawing_TextHeightBehavior](_drawing.md#oh_drawing_textheightbehavior)没有被纳入比较。  | 
| uint32_t [OH_Drawing_TextStyleGetColor](_drawing.md#oh_drawing_textstylegetcolor) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 获取文本颜色。  | 
| [OH_Drawing_TextDecorationStyle](_drawing.md#oh_drawing_textdecorationstyle) [OH_Drawing_TextStyleGetDecorationStyle](_drawing.md#oh_drawing_textstylegetdecorationstyle) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 获取文本装饰样式。  | 
| [OH_Drawing_FontWeight](_drawing.md#oh_drawing_fontweight) [OH_Drawing_TextStyleGetFontWeight](_drawing.md#oh_drawing_textstylegetfontweight) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 获取指定文本样式字重。 |
| [OH_Drawing_FontStyle](_drawing.md#oh_drawing_fontstyle) [OH_Drawing_TextStyleGetFontStyle](_drawing.md#oh_drawing_textstylegetfontstyle) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 获取指定文本样式的字体样式。 |
| [OH_Drawing_TextBaseline](_drawing.md#oh_drawing_textbaseline) [OH_Drawing_TextStyleGetBaseline](_drawing.md#oh_drawing_textstylegetbaseline) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 获取指定文本样式的字体基线位置。 |
| char \*\* [OH_Drawing_TextStyleGetFontFamilies](_drawing.md#oh_drawing_textstylegetfontfamilies) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, size_t \*num) | 获取字体类型名称列表。  | 
| void [OH_Drawing_TextStyleDestroyFontFamilies](_drawing.md#oh_drawing_textstyledestroyfontfamilies) (char \*\*fontFamilies, size_t num) | 释放长度为num的字体家族名称列表占用的内存。 |
| double [OH_Drawing_TextStyleGetFontSize](_drawing.md#oh_drawing_textstylegetfontsize) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 获取指定文本样式字号。|
| double [OH_Drawing_TextStyleGetLetterSpacing](_drawing.md#oh_drawing_textstylegetletterspacing) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 获取指定文本样式的字符间距。 |
| double [OH_Drawing_TextStyleGetWordSpacing](_drawing.md#oh_drawing_textstylegetwordspacing) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 获取指定文本样式的单词间距。 |
| double [OH_Drawing_TextStyleGetFontHeight](_drawing.md#oh_drawing_textstylegetfontheight) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 获取指定文本样式行高缩放系数。 |
| bool [OH_Drawing_TextStyleGetHalfLeading](_drawing.md#oh_drawing_textstylegethalfleading) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 获取指定文本样式一半行间距开关状态。  | 
| const char \* [OH_Drawing_TextStyleGetLocale](_drawing.md#oh_drawing_textstylegetlocale) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | 获取语言环境。 |
| void [OH_Drawing_TypographyDestroyTextBox](_drawing.md#oh_drawing_typographydestroytextbox) ([OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \*) | 释放文本框占用的内存。  | 
| void [OH_Drawing_SetTextShadow](_drawing.md#oh_drawing_settextshadow) ([OH_Drawing_TextShadow](_drawing.md#oh_drawing_textshadow) \*shadow, uint32_t color, [OH_Drawing_Point](_drawing.md#oh_drawing_point) \*offset, double blurRadius) | 设置字体阴影对象的参数。  | 
| [OH_Drawing_TextTab](_drawing.md#oh_drawing_texttab) \* [OH_Drawing_CreateTextTab](_drawing.md#oh_drawing_createtexttab) ([OH_Drawing_TextAlign](_drawing.md#oh_drawing_textalign) alignment, float location) | 创建文本制表符对象。  | 
| void [OH_Drawing_DestroyTextTab](_drawing.md#oh_drawing_destroytexttab) ([OH_Drawing_TextTab](_drawing.md#oh_drawing_texttab) \*) | 释放文本制表符对象占据的内存。  | 
| [OH_Drawing_TextAlign](_drawing.md#oh_drawing_textalign) [OH_Drawing_GetTextTabAlignment](_drawing.md#oh_drawing_gettexttabalignment) ([OH_Drawing_TextTab](_drawing.md#oh_drawing_texttab) \*) | 获取文本制表符对象的对齐方式。  | 
| float [OH_Drawing_GetTextTabLocation](_drawing.md#oh_drawing_gettexttablocation) ([OH_Drawing_TextTab](_drawing.md#oh_drawing_texttab) \*) | 获取文本制表符的位置。  | 
| void [OH_Drawing_SetTypographyTextTab](_drawing.md#oh_drawing_settypographytexttab) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, [OH_Drawing_TextTab](_drawing.md#oh_drawing_texttab) \*TextTab) | 设置文本制表符对齐方式及位置。当设置了文本对齐方式或者省略号风格时制表符不生效，当制表符位置小于1.0时为替换成空格的效果。  | 
| size_t [OH_Drawing_GetDrawingArraySize](_drawing.md#oh_drawing_getdrawingarraysize) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*drawingArray) | 获取传入类型为对象数组[OH_Drawing_Array](_drawing.md#oh_drawing_array)中的对象个数。  | 
