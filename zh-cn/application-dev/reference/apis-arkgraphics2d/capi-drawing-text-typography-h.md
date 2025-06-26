# drawing_text_typography.h

## 概述

定义绘制模块中排版相关的函数。

**引用文件：** <native_drawing/drawing_text_typography.h>

**库：** libnative_drawing.so

**起始版本：** 8

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_PlaceholderSpan](capi-drawing-oh-drawing-placeholderspan.md) | OH_Drawing_PlaceholderSpan | 用于描述占位符跨度的结构体。 |
| [OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md) | OH_Drawing_FontDescriptor | 描述系统字体详细信息的结构体。 |
| [OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md) | OH_Drawing_LineMetrics | 文字行位置信息。 |
| [OH_Drawing_FontFallbackInfo](capi-drawing-oh-drawing-fontfallbackinfo.md) | OH_Drawing_FontFallbackInfo | 备用字体信息结构体。 |
| [OH_Drawing_FontFallbackGroup](capi-drawing-oh-drawing-fontfallbackgroup.md) | OH_Drawing_FontFallbackGroup | 备用字体集信息结构体。 |
| [OH_Drawing_FontAdjustInfo](capi-drawing-oh-drawing-fontadjustinfo.md) | OH_Drawing_FontAdjustInfo | 字重映射信息结构体。 |
| [OH_Drawing_FontAliasInfo](capi-drawing-oh-drawing-fontaliasinfo.md) | OH_Drawing_FontAliasInfo | 别名字体信息结构体。 |
| [OH_Drawing_FontGenericInfo](capi-drawing-oh-drawing-fontgenericinfo.md) | OH_Drawing_FontGenericInfo | 系统所支持的通用字体集信息结构体。 |
| [OH_Drawing_FontConfigInfo](capi-drawing-oh-drawing-fontconfiginfo.md) | OH_Drawing_FontConfigInfo | 系统字体配置信息结构体。 |
| [OH_Drawing_FontStyleStruct](capi-drawing-oh-drawing-fontstylestruct.md) | OH_Drawing_FontStyleStruct | 定义字体样式信息的结构体。 |
| [OH_Drawing_FontFeature](capi-drawing-oh-drawing-fontfeature.md) | OH_Drawing_FontFeature | 描述文本字体特征结构体。 |
| [OH_Drawing_StrutStyle](capi-drawing-oh-drawing-strutstyle.md) | OH_Drawing_StrutStyle | 用于描述支柱样式的结构体。支柱样式用于控制绘制文本时行之间的间距、基线对齐方式以及其他与行高相关的属性。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_TextDirection](#oh_drawing_textdirection) | - | 文字方向。/ |
| [OH_Drawing_TextAlign](#oh_drawing_textalign) | - | 文字对齐方式/ |
| [OH_Drawing_FontWeight](#oh_drawing_fontweight) | - | 字重。/ |
| [OH_Drawing_TextBaseline](#oh_drawing_textbaseline) | - | 基线位置。/ |
| [OH_Drawing_TextDecoration](#oh_drawing_textdecoration) | - | 文本装饰。/ |
| [OH_Drawing_FontStyle](#oh_drawing_fontstyle) | - | 区分字体是否为斜体。/ |
| [OH_Drawing_PlaceholderVerticalAlignment](#oh_drawing_placeholderverticalalignment) | OH_Drawing_PlaceholderVerticalAlignment | 占位符垂直对齐枚举。 |
| [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle) | OH_Drawing_TextDecorationStyle | 文本装饰样式枚举。 |
| [OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal) | OH_Drawing_EllipsisModal | 省略号样式枚举。 |
| [OH_Drawing_BreakStrategy](#oh_drawing_breakstrategy) | OH_Drawing_BreakStrategy | 文本的中断策略枚举。 |
| [OH_Drawing_WordBreakType](#oh_drawing_wordbreaktype) | OH_Drawing_WordBreakType | 单词的断词方式枚举。 |
| [OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle) | OH_Drawing_RectHeightStyle | 矩形框高度样式枚举。 |
| [OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle) | OH_Drawing_RectWidthStyle | 矩形框宽度样式枚举。 |
| [OH_Drawing_TextBadgeType](#oh_drawing_textbadgetype) | OH_Drawing_TextBadgeType | 上下标样式枚举。 |
| [OH_Drawing_FontConfigInfoErrorCode](#oh_drawing_fontconfiginfoerrorcode) | - | 获取系统字体配置信息列表结果枚举。 |
| [OH_Drawing_FontWidth](#oh_drawing_fontwidth) | - | 字体宽度的枚举。 |
| [OH_Drawing_TextHeightBehavior](#oh_drawing_textheightbehavior) | - | 文本高度修饰符模式枚举。 |
| [OH_Drawing_TextStyleType](#oh_drawing_textstyletype) | - | 文本样式类型枚举。 |
| [OH_Drawing_TextVerticalAlignment](#oh_drawing_textverticalalignment) | OH_Drawing_TextVerticalAlignment | 垂直对齐方式枚举。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle* OH_Drawing_CreateTypographyStyle(void)](#oh_drawing_createtypographystyle) | 创建指向OH_Drawing_TypographyStyle对象的指针。不再需要[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)时，请使用[OH_Drawing_DestroyTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_destroytypographystyle)接口释放该对象的指针。 |
| [void OH_Drawing_DestroyTypographyStyle(OH_Drawing_TypographyStyle* style)](#oh_drawing_destroytypographystyle) | 释放被OH_Drawing_TypographyStyle对象占据的内存。 |
| [void OH_Drawing_SetTypographyTextDirection(OH_Drawing_TypographyStyle* style, int direction)](#oh_drawing_settypographytextdirection) | 设置指定排版样式中的文本方向。 |
| [void OH_Drawing_SetTypographyTextAlign(OH_Drawing_TypographyStyle* style, int align)](#oh_drawing_settypographytextalign) | 设置文本对齐方式。 |
| [int OH_Drawing_TypographyGetEffectiveAlignment(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographygeteffectivealignment) | 获取文字对齐方式。 |
| [void OH_Drawing_SetTypographyTextMaxLines(OH_Drawing_TypographyStyle* style, int lineNumber)](#oh_drawing_settypographytextmaxlines) | 设置文本最大行数。 |
| [OH_Drawing_TextStyle* OH_Drawing_CreateTextStyle(void)](#oh_drawing_createtextstyle) | 创建指向OH_Drawing_TextStyle对象的指针。 |
| [OH_Drawing_TextStyle* OH_Drawing_TypographyGetTextStyle(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographygettextstyle) | 获取指定排版样式中设置的默认文本样式。 |
| [void OH_Drawing_DestroyTextStyle(OH_Drawing_TextStyle* style)](#oh_drawing_destroytextstyle) | 释放被OH_Drawing_TextStyle对象占据的内存。 |
| [void OH_Drawing_SetTextStyleColor(OH_Drawing_TextStyle* style, uint32_t color)](#oh_drawing_settextstylecolor) | 设置文本颜色。 |
| [void OH_Drawing_SetTextStyleFontSize(OH_Drawing_TextStyle* style, double fontSize)](#oh_drawing_settextstylefontsize) | 设置字号。 |
| [void OH_Drawing_SetTextStyleFontWeight(OH_Drawing_TextStyle* style, int fontWeight)](#oh_drawing_settextstylefontweight) | 设置字重。目前只有系统默认字体支持字重的调节，其他字体设置字重值小于semi-bold时字体粗细无变化，当设置字重值大于等于semi-bold时可能会触发伪加粗效果。 |
| [void OH_Drawing_SetTextStyleBaseLine(OH_Drawing_TextStyle* style, int baseline)](#oh_drawing_settextstylebaseline) | 设置文本样式的字体基线位置。 |
| [void OH_Drawing_SetTextStyleDecoration(OH_Drawing_TextStyle* style, int decoration)](#oh_drawing_settextstyledecoration) | 设置指定文本样式中的装饰线类型，只能设置一个装饰线类型，添加多个需要使用[OH_Drawing_AddTextStyleDecoration](capi-drawing-text-typography-h.md#oh_drawing_addtextstyledecoration)。 |
| [void OH_Drawing_AddTextStyleDecoration(OH_Drawing_TextStyle* style, int decoration)](#oh_drawing_addtextstyledecoration) | 新增指定装饰，可同时显示多种装饰线。 |
| [void OH_Drawing_RemoveTextStyleDecoration(OH_Drawing_TextStyle* style, int decoration)](#oh_drawing_removetextstyledecoration) | 删除指定装饰。 |
| [void OH_Drawing_SetTextStyleDecorationColor(OH_Drawing_TextStyle* style, uint32_t color)](#oh_drawing_settextstyledecorationcolor) | 设置指定文本样式中的装饰线颜色。如果不调用该接口或者设置color为0时，装饰线颜色跟随文本颜色。 |
| [void OH_Drawing_SetTextStyleFontHeight(OH_Drawing_TextStyle* style, double fontHeight)](#oh_drawing_settextstylefontheight) | 设置行高，按当前字体大小的倍数进行设置。 |
| [void OH_Drawing_SetTextStyleFontFamilies(OH_Drawing_TextStyle* style,int fontFamiliesNumber, const char* fontFamilies[])](#oh_drawing_settextstylefontfamilies) | 设置指定文本样式的字体家族类型。 |
| [void OH_Drawing_SetTextStyleFontStyle(OH_Drawing_TextStyle* style, int fontStyle)](#oh_drawing_settextstylefontstyle) | 为指定文本样式设置字体样式。 |
| [void OH_Drawing_SetTextStyleLocale(OH_Drawing_TextStyle* style, const char* locale)](#oh_drawing_settextstylelocale) | 设置文本语言环境。 |
| [void OH_Drawing_SetTextStyleForegroundBrush(OH_Drawing_TextStyle* style, OH_Drawing_Brush* foregroundBrush)](#oh_drawing_settextstyleforegroundbrush) | 设置指定文本样式中的前景色画刷。 |
| [void OH_Drawing_TextStyleGetForegroundBrush(OH_Drawing_TextStyle* style, OH_Drawing_Brush* foregroundBrush)](#oh_drawing_textstylegetforegroundbrush) | 返回设置的前景色画刷。 |
| [void OH_Drawing_SetTextStyleForegroundPen(OH_Drawing_TextStyle* style, OH_Drawing_Pen* foregroundPen)](#oh_drawing_settextstyleforegroundpen) | 设置指定文本样式中的前景色画笔。 |
| [void OH_Drawing_TextStyleGetForegroundPen(OH_Drawing_TextStyle* style, OH_Drawing_Pen* foregroundPen)](#oh_drawing_textstylegetforegroundpen) | 返回设置的前景色画笔。 |
| [void OH_Drawing_SetTextStyleBackgroundBrush(OH_Drawing_TextStyle* style, OH_Drawing_Brush* foregroundPen)](#oh_drawing_settextstylebackgroundbrush) | 设置指定文本样式中的背景色画刷。 |
| [void OH_Drawing_TextStyleGetBackgroundBrush(OH_Drawing_TextStyle* style, OH_Drawing_Brush* backgroundBrush)](#oh_drawing_textstylegetbackgroundbrush) | 返回设置的背景色画刷。 |
| [void OH_Drawing_SetTextStyleBackgroundPen(OH_Drawing_TextStyle* style, OH_Drawing_Pen* backgroundPen)](#oh_drawing_settextstylebackgroundpen) | 设置指定文本样式中的背景色画笔。 |
| [void OH_Drawing_TextStyleGetBackgroundPen(OH_Drawing_TextStyle* style, OH_Drawing_Pen* backgroundPen)](#oh_drawing_textstylegetbackgroundpen) | 返回设置的背景色画笔。 |
| [OH_Drawing_TypographyCreate* OH_Drawing_CreateTypographyHandler(OH_Drawing_TypographyStyle* style,OH_Drawing_FontCollection* fontCollection)](#oh_drawing_createtypographyhandler) | 创建指向OH_Drawing_TypographyCreate对象的指针。不再需要[OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)时，请使用[OH_Drawing_DestroyTypographyHandler](capi-drawing-text-typography-h.md#oh_drawing_destroytypographyhandler)接口释放该对象的指针。 |
| [void OH_Drawing_DestroyTypographyHandler(OH_Drawing_TypographyCreate* handler)](#oh_drawing_destroytypographyhandler) | 释放被OH_Drawing_TypographyCreate对象占据的内存。 |
| [void OH_Drawing_TypographyHandlerPushTextStyle(OH_Drawing_TypographyCreate* handler, OH_Drawing_TextStyle* style)](#oh_drawing_typographyhandlerpushtextstyle) | 将指定文本样式压入文本样式栈，后续添加的文本总是会使用栈顶的文本样式。 |
| [void OH_Drawing_TypographyHandlerAddText(OH_Drawing_TypographyCreate* handler, const char* text)](#oh_drawing_typographyhandleraddtext) | 设置文本内容。 |
| [void OH_Drawing_TypographyHandlerPopTextStyle(OH_Drawing_TypographyCreate* handler)](#oh_drawing_typographyhandlerpoptextstyle) | 从文本样式栈中弹出栈顶文本样式。 |
| [OH_Drawing_Typography* OH_Drawing_CreateTypography(OH_Drawing_TypographyCreate* handler)](#oh_drawing_createtypography) | 创建指向OH_Drawing_Typography对象的指针。不再需要[OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)时，请使用[OH_Drawing_DestroyTypography](capi-drawing-text-typography-h.md#oh_drawing_destroytypography)接口释放该对象的指针。 |
| [void OH_Drawing_DestroyTypography(OH_Drawing_Typography* typography)](#oh_drawing_destroytypography) | 释放OH_Drawing_Typography对象占据的内存。 |
| [void OH_Drawing_TypographyLayout(OH_Drawing_Typography* typography, double maxWidth)](#oh_drawing_typographylayout) | 排版布局。 |
| [void OH_Drawing_TypographyPaint(OH_Drawing_Typography* typography, OH_Drawing_Canvas* canvas,double potisionX, double potisionY)](#oh_drawing_typographypaint) | 在指定位置绘制文本，从左上角开始绘制，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用并生效之后调用。 |
| [void OH_Drawing_TypographyPaintOnPath(OH_Drawing_Typography* typography, OH_Drawing_Canvas* canvas,OH_Drawing_Path* path, double hOffset, double vOffset)](#oh_drawing_typographypaintonpath) | 沿指定路径绘制文本。建议搭配[OH_Drawing_SetTypographyTextMaxLines](capi-drawing-text-typography-h.md#oh_drawing_settypographytextmaxlines)接口设置最大行为1行，避免因文本宽度超过排版宽度出现跨行重叠问题。 |
| [double OH_Drawing_TypographyGetMaxWidth(OH_Drawing_Typography* typography)](#oh_drawing_typographygetmaxwidth) | 获取用户设置的排版宽度，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。 |
| [double OH_Drawing_TypographyGetHeight(OH_Drawing_Typography* typography)](#oh_drawing_typographygetheight) | 获取排版对象整体的高度，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。 |
| [double OH_Drawing_TypographyGetLongestLine(OH_Drawing_Typography* typography)](#oh_drawing_typographygetlongestline) | 获取排版对象最长行的宽度，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用，建议实际使用时将返回值向上取整。当文本内容为空时，返回0.0。 |
| [double OH_Drawing_TypographyGetLongestLineWithIndent(OH_Drawing_Typography* typography)](#oh_drawing_typographygetlongestlinewithindent) | 获取排版对象最长行的宽度（该宽度包含当前行缩进的宽度），该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用，建议实际使用时将返回值向上取整。当文本内容为空时，返回0.0。 |
| [double OH_Drawing_TypographyGetMinIntrinsicWidth(OH_Drawing_Typography* typography)](#oh_drawing_typographygetminintrinsicwidth) | 获取排版对象的最小固有宽度，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。 |
| [double OH_Drawing_TypographyGetMaxIntrinsicWidth(OH_Drawing_Typography* typography)](#oh_drawing_typographygetmaxintrinsicwidth) | 获取排版对象的最大固有宽度，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。 |
| [double OH_Drawing_TypographyGetAlphabeticBaseline(OH_Drawing_Typography* typography)](#oh_drawing_typographygetalphabeticbaseline) | 获取排版样式字母文字基线。 |
| [double OH_Drawing_TypographyGetIdeographicBaseline(OH_Drawing_Typography* typography)](#oh_drawing_typographygetideographicbaseline) | 获取排版样式表意文字基线。 |
| [void OH_Drawing_TypographyHandlerAddPlaceholder(OH_Drawing_TypographyCreate* handler,OH_Drawing_PlaceholderSpan* span)](#oh_drawing_typographyhandleraddplaceholder) | 设置占位符。 |
| [bool OH_Drawing_TypographyDidExceedMaxLines(OH_Drawing_Typography* typography)](#oh_drawing_typographydidexceedmaxlines) | 获取排版对象中文本是否超过最大行，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用，如果没有通过[OH_Drawing_SetTypographyTextMaxLines](capi-drawing-text-typography-h.md#oh_drawing_settypographytextmaxlines)接口设置最大行，则返回false。 |
| [OH_Drawing_TextBox* OH_Drawing_TypographyGetRectsForRange(OH_Drawing_Typography* typography,size_t start, size_t end, OH_Drawing_RectHeightStyle heightStyle, OH_Drawing_RectWidthStyle widthStyle)](#oh_drawing_typographygetrectsforrange) | 获取排版对象中指定范围内的文本框，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。不再需要[OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)时，请使用[OH_Drawing_TypographyDestroyTextBox](capi-drawing-text-typography-h.md#oh_drawing_typographydestroytextbox)接口释放该对象的指针。 |
| [OH_Drawing_TextBox* OH_Drawing_TypographyGetRectsForPlaceholders(OH_Drawing_Typography* typography)](#oh_drawing_typographygetrectsforplaceholders) | 获取排版对象中占位符的文本框，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。不再需要[OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)时，请使用[OH_Drawing_TypographyDestroyTextBox](capi-drawing-text-typography-h.md#oh_drawing_typographydestroytextbox)接口释放该对象的指针。 |
| [float OH_Drawing_GetLeftFromTextBox(OH_Drawing_TextBox* textbox, int index)](#oh_drawing_getleftfromtextbox) | 获取文本框左侧位置。 |
| [float OH_Drawing_GetRightFromTextBox(OH_Drawing_TextBox* textbox, int index)](#oh_drawing_getrightfromtextbox) | 获取文本框右侧位置。 |
| [float OH_Drawing_GetTopFromTextBox(OH_Drawing_TextBox* textbox, int index)](#oh_drawing_gettopfromtextbox) | 获取文本框顶部位置。 |
| [float OH_Drawing_GetBottomFromTextBox(OH_Drawing_TextBox* textbox, int index)](#oh_drawing_getbottomfromtextbox) | 获取文本框底部位置。 |
| [int OH_Drawing_GetTextDirectionFromTextBox(OH_Drawing_TextBox* textbox, int index)](#oh_drawing_gettextdirectionfromtextbox) | 获取文本框方向。 |
| [size_t OH_Drawing_GetSizeOfTextBox(OH_Drawing_TextBox* textBox)](#oh_drawing_getsizeoftextbox) | 获取文本框数量大小。 |
| [OH_Drawing_PositionAndAffinity* OH_Drawing_TypographyGetGlyphPositionAtCoordinate(OH_Drawing_Typography* typography,double dx, double dy)](#oh_drawing_typographygetglyphpositionatcoordinate) | 获取坐标处文本的索引位置和亲和性。 |
| [OH_Drawing_PositionAndAffinity* OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster(OH_Drawing_Typography* typography, double dx, double dy)](#oh_drawing_typographygetglyphpositionatcoordinatewithcluster) | 获取坐标处文本所属字符簇的索引位置和亲和性，字符簇指一个或多个字符组成的整体。 |
| [size_t OH_Drawing_GetPositionFromPositionAndAffinity(OH_Drawing_PositionAndAffinity* positionAndAffinity)](#oh_drawing_getpositionfrompositionandaffinity) | 获取OH_Drawing_PositionAndAffinity对象的位置属性。 |
| [int OH_Drawing_GetAffinityFromPositionAndAffinity(OH_Drawing_PositionAndAffinity* positionAndAffinity)](#oh_drawing_getaffinityfrompositionandaffinity) | 获取OH_Drawing_PositionAndAffinity对象的亲和性，根据亲和性可判断字体会靠近前方文本还是后方文本。 |
| [OH_Drawing_Range* OH_Drawing_TypographyGetWordBoundary(OH_Drawing_Typography* typography, size_t offset)](#oh_drawing_typographygetwordboundary) | 获取排版对象中单词的边界。 |
| [size_t OH_Drawing_GetStartFromRange(OH_Drawing_Range* range)](#oh_drawing_getstartfromrange) | 获取OH_Drawing_Range对象开始位置。 |
| [size_t OH_Drawing_GetEndFromRange(OH_Drawing_Range* range)](#oh_drawing_getendfromrange) | 获取OH_Drawing_Range对象结束位置。 |
| [size_t OH_Drawing_TypographyGetLineCount(OH_Drawing_Typography* typography)](#oh_drawing_typographygetlinecount) | 获取排版对象中文本行数，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。 |
| [void OH_Drawing_SetTextStyleDecorationStyle(OH_Drawing_TextStyle* style, int decorationStyle)](#oh_drawing_settextstyledecorationstyle) | 设置指定文本样式中的装饰线样式。 |
| [void OH_Drawing_SetTextStyleDecorationThicknessScale(OH_Drawing_TextStyle* style, double decorationThicknessScale)](#oh_drawing_settextstyledecorationthicknessscale) | 设置文本装饰线的粗细缩放比例。 |
| [void OH_Drawing_SetTextStyleLetterSpacing(OH_Drawing_TextStyle* style, double letterSpacing)](#oh_drawing_settextstyleletterspacing) | 设置文本的字符间距。 |
| [void OH_Drawing_SetTextStyleWordSpacing(OH_Drawing_TextStyle* style, double wordSpacing)](#oh_drawing_settextstylewordspacing) | 设置文本的单词间距。 |
| [void OH_Drawing_SetTextStyleHalfLeading(OH_Drawing_TextStyle* style, bool halfLeading)](#oh_drawing_settextstylehalfleading) | 设置文本为一半行间距。 |
| [void OH_Drawing_SetTextStyleEllipsis(OH_Drawing_TextStyle* style, const char* ellipsis)](#oh_drawing_settextstyleellipsis) | 设置文本的省略号内容。 |
| [void OH_Drawing_SetTextStyleEllipsisModal(OH_Drawing_TextStyle* style, int ellipsisModal)](#oh_drawing_settextstyleellipsismodal) | 设置文本的省略号样式。 |
| [void OH_Drawing_SetTypographyTextBreakStrategy(OH_Drawing_TypographyStyle* style, int breakStrategy)](#oh_drawing_settypographytextbreakstrategy) | 设置文本的中断策略。 |
| [void OH_Drawing_SetTypographyTextWordBreakType(OH_Drawing_TypographyStyle* style, int wordBreakType)](#oh_drawing_settypographytextwordbreaktype) | 设置单词的断词方式。 |
| [void OH_Drawing_SetTypographyTextEllipsisModal(OH_Drawing_TypographyStyle* style, int ellipsisModal)](#oh_drawing_settypographytextellipsismodal) | 设置文本的省略模式。 |
| [void OH_Drawing_SetTypographyTextEllipsis(OH_Drawing_TypographyStyle* style, const char* ellipsis)](#oh_drawing_settypographytextellipsis) | 设置排版样式省略号文本。 |
| [double OH_Drawing_TypographyGetLineHeight(OH_Drawing_Typography* typography, int lineNumber)](#oh_drawing_typographygetlineheight) | 获取排版对象中指定行的行高，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。 |
| [double OH_Drawing_TypographyGetLineWidth(OH_Drawing_Typography* typography, int lineNumber)](#oh_drawing_typographygetlinewidth) | 获取指定行的行宽，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。 |
| [void OH_Drawing_SetTypographyTextSplitRatio(OH_Drawing_TypographyStyle* style, float textSplitRatio)](#oh_drawing_settypographytextsplitratio) | 设置文本划分比率。 |
| [bool OH_Drawing_TypographyIsLineUnlimited(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographyislineunlimited) | 获取文本是否有最大行数限制。 |
| [bool OH_Drawing_TypographyIsEllipsized(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographyisellipsized) | 获取指定排版样式是否配置省略号。 |
| [void OH_Drawing_SetTypographyTextLocale(OH_Drawing_TypographyStyle* style, const char* locale)](#oh_drawing_settypographytextlocale) | 设置指定排版样式的语言环境。 |
| [bool OH_Drawing_TextStyleGetFontMetrics(OH_Drawing_Typography* typography,OH_Drawing_TextStyle* style, OH_Drawing_Font_Metrics* fontmetrics)](#oh_drawing_textstylegetfontmetrics) | 获取文本字体属性。 |
| [void OH_Drawing_SetTypographyTextStyle(OH_Drawing_TypographyStyle* handler, OH_Drawing_TextStyle* style)](#oh_drawing_settypographytextstyle) | 设置排版样式。 |
| [OH_Drawing_FontDescriptor* OH_Drawing_CreateFontDescriptor(void)](#oh_drawing_createfontdescriptor) | 构造字体描述对象，用于描述系统字体详细信息。 |
| [void OH_Drawing_DestroyFontDescriptor(OH_Drawing_FontDescriptor* descriptor)](#oh_drawing_destroyfontdescriptor) | 释放字体描述对象占用的内存。 |
| [OH_Drawing_FontParser* OH_Drawing_CreateFontParser(void)](#oh_drawing_createfontparser) | 构造字体解析对象，用于解析系统字体。 |
| [void OH_Drawing_DestroyFontParser(OH_Drawing_FontParser* parser)](#oh_drawing_destroyfontparser) | 释放字体解析对象占用的内存。 |
| [char** OH_Drawing_FontParserGetSystemFontList(OH_Drawing_FontParser* fontParser, size_t* num)](#oh_drawing_fontparsergetsystemfontlist) | 获取系统字体名称列表，此接口仅在2in1、phone设备上可用。 |
| [void OH_Drawing_DestroySystemFontList(char** fontList, size_t num)](#oh_drawing_destroysystemfontlist) | 释放系统字体名称列表占用的内存。 |
| [OH_Drawing_FontDescriptor* OH_Drawing_FontParserGetFontByName(OH_Drawing_FontParser* fontParser, const char* name)](#oh_drawing_fontparsergetfontbyname) | 根据传入的系统字体名称获取系统字体的相关信息。 |
| [OH_Drawing_LineMetrics* OH_Drawing_TypographyGetLineMetrics(OH_Drawing_Typography* typography)](#oh_drawing_typographygetlinemetrics) | 获取排版对象的行位置信息，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。不再需要[OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md)时，请使用[OH_Drawing_DestroyLineMetrics](capi-drawing-text-typography-h.md#oh_drawing_destroylinemetrics)接口释放该对象的指针。 |
| [size_t OH_Drawing_LineMetricsGetSize(OH_Drawing_LineMetrics* lineMetrics)](#oh_drawing_linemetricsgetsize) | 获取行数量。 |
| [void OH_Drawing_DestroyLineMetrics(OH_Drawing_LineMetrics* lineMetrics)](#oh_drawing_destroylinemetrics) | 释放行位置信息对象占用的内存。 |
| [bool OH_Drawing_TypographyGetLineMetricsAt(OH_Drawing_Typography* typography,int lineNumber, OH_Drawing_LineMetrics* lineMetric)](#oh_drawing_typographygetlinemetricsat) | 获取排版对象的指定行位置信息，具体参见[OH_Drawing_LineMetr](capi-drawing-oh-drawing-linemetrics.md)结构体，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。 |
| [bool OH_Drawing_TypographyGetLineInfo(OH_Drawing_Typography* typography, int lineNumber, bool oneLine,bool includeWhitespace, OH_Drawing_LineMetrics* drawingLineMetrics)](#oh_drawing_typographygetlineinfo) | 获取排版对象中指定行的位置信息或指定行第一个字符的位置信息，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。 |
| [void OH_Drawing_SetTypographyTextFontWeight(OH_Drawing_TypographyStyle* style, int weight)](#oh_drawing_settypographytextfontweight) | 设置排版样式默认字重。目前只有系统默认字体支持字重的调节，其他字体设置字重值小于semi-bold时字体粗细无变化，当设置字重值大于等于semi-bold时可能会触发伪加粗效果。 |
| [void OH_Drawing_SetTypographyTextFontStyle(OH_Drawing_TypographyStyle* style, int fontStyle)](#oh_drawing_settypographytextfontstyle) | 设置排版样式默认的字体样式。 |
| [void OH_Drawing_SetTypographyTextFontFamily(OH_Drawing_TypographyStyle* style, const char* fontFamily)](#oh_drawing_settypographytextfontfamily) | 设置字体家族的名称。 |
| [void OH_Drawing_SetTypographyTextFontSize(OH_Drawing_TypographyStyle* style, double fontSize)](#oh_drawing_settypographytextfontsize) | 设置文本排版字号。 |
| [void OH_Drawing_SetTypographyTextFontHeight(OH_Drawing_TypographyStyle* style, double fontHeight)](#oh_drawing_settypographytextfontheight) | 设置文本排版字体高度。 |
| [void OH_Drawing_SetTypographyTextHalfLeading(OH_Drawing_TypographyStyle* style, bool halfLeading)](#oh_drawing_settypographytexthalfleading) | 设置文本排版是否为一半行间距。 |
| [void OH_Drawing_SetTypographyTextUseLineStyle(OH_Drawing_TypographyStyle* style, bool useLineStyle)](#oh_drawing_settypographytextuselinestyle) | 设置文本排版是否启用行样式。 |
| [void OH_Drawing_SetTypographyTextLineStyleFontWeight(OH_Drawing_TypographyStyle* style, int weight)](#oh_drawing_settypographytextlinestylefontweight) | 设置排版样式中支柱样式的文本样式字重。目前只有系统默认字体支持字重的调节，其他字体设置字重值小于semi-bold时字体粗细无变化，当设置字重值大于等于semi-bold时可能会触发伪加粗效果。 |
| [void OH_Drawing_SetTypographyTextLineStyleFontStyle(OH_Drawing_TypographyStyle* style, int fontStyle)](#oh_drawing_settypographytextlinestylefontstyle) | 设置文本排版样式中支柱样式的字体样式。 |
| [void OH_Drawing_SetTypographyTextLineStyleFontFamilies(OH_Drawing_TypographyStyle* style,int fontFamiliesNumber, const char* fontFamilies[])](#oh_drawing_settypographytextlinestylefontfamilies) | 设置文本排版行样式字体类型。 |
| [void OH_Drawing_SetTypographyTextLineStyleFontSize(OH_Drawing_TypographyStyle* style, double lineStyleFontSize)](#oh_drawing_settypographytextlinestylefontsize) | 设置文本排版行样式字号。 |
| [void OH_Drawing_SetTypographyTextLineStyleFontHeight(OH_Drawing_TypographyStyle* style, double lineStyleFontHeight)](#oh_drawing_settypographytextlinestylefontheight) | 设置文本排版行样式字体高度。 |
| [void OH_Drawing_SetTypographyTextLineStyleHalfLeading(OH_Drawing_TypographyStyle* style, bool lineStyleHalfLeading)](#oh_drawing_settypographytextlinestylehalfleading) | 设置文本排版行样式是否为一半行间距。 |
| [void OH_Drawing_SetTypographyTextLineStyleSpacingScale(OH_Drawing_TypographyStyle* style, double spacingScale)](#oh_drawing_settypographytextlinestylespacingscale) | 设置文本排版行样式间距比例。 |
| [void OH_Drawing_SetTypographyTextLineStyleOnly(OH_Drawing_TypographyStyle* style, bool lineStyleOnly)](#oh_drawing_settypographytextlinestyleonly) | 设置文本排版是否仅启用行样式。 |
| [OH_Drawing_TextShadow* OH_Drawing_CreateTextShadow(void)](#oh_drawing_createtextshadow) | 创建指向字体阴影对象的指针。不再需要[OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)时，请使用[OH_Drawing_DestroyTextShadow](capi-drawing-text-typography-h.md#oh_drawing_destroytextshadow)接口释放该对象的指针。 |
| [void OH_Drawing_DestroyTextShadow(OH_Drawing_TextShadow* shadow)](#oh_drawing_destroytextshadow) | 释放被字体阴影对象占据的内存。 |
| [OH_Drawing_TextShadow* OH_Drawing_TextStyleGetShadows(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetshadows) | 获取字体阴影容器。不再需要[OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)时，请使用[OH_Drawing_DestroyTextShadows](capi-drawing-text-typography-h.md#oh_drawing_destroytextshadows)接口释放该对象的指针。 |
| [int OH_Drawing_TextStyleGetShadowCount(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetshadowcount) | 获取字体阴影容器的大小。 |
| [void OH_Drawing_TextStyleAddShadow(OH_Drawing_TextStyle* style, const OH_Drawing_TextShadow* shadow)](#oh_drawing_textstyleaddshadow) | 字体阴影容器中添加字体阴影元素。 |
| [void OH_Drawing_TextStyleClearShadows(OH_Drawing_TextStyle* style)](#oh_drawing_textstyleclearshadows) | 清除字体阴影容器中的所有元素。 |
| [OH_Drawing_TextShadow* OH_Drawing_TextStyleGetShadowWithIndex(OH_Drawing_TextStyle* style, int index)](#oh_drawing_textstylegetshadowwithindex) | 根据下标获取字体阴影容器中的元素。 |
| [void OH_Drawing_TypographySetIndents(OH_Drawing_Typography* typography, int indentsNumber, const float indents[])](#oh_drawing_typographysetindents) | 设置文本的排版缩进，不调用此接口默认文本无缩进。 |
| [float OH_Drawing_TypographyGetIndentsWithIndex(OH_Drawing_Typography* typography, int index)](#oh_drawing_typographygetindentswithindex) | 根据行索引获取排版对象缩进容器中的元素，行索引从0开始。 |
| [OH_Drawing_Range* OH_Drawing_TypographyGetLineTextRange(OH_Drawing_Typography* typography,int lineNumber, bool includeSpaces)](#oh_drawing_typographygetlinetextrange) | 获取排版对象中行的边界，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。该接口只能获取已有行的边界，即输入行索引从0开始，最大行索引为[OH_Drawing_TypographyGetLineCount](capi-drawing-text-typography-h.md#oh_drawing_typographygetlinecount) - 1。 |
| [void OH_Drawing_DestroyTextShadows(OH_Drawing_TextShadow* shadow)](#oh_drawing_destroytextshadows) | 释放由被字体阴影对象OH_Drawing_TextShadow构成的vector占据的内存。 |
| [OH_Drawing_FontConfigInfo* OH_Drawing_GetSystemFontConfigInfo(OH_Drawing_FontConfigInfoErrorCode* errorCode)](#oh_drawing_getsystemfontconfiginfo) | 获取系统字体配置信息。 |
| [void OH_Drawing_DestroySystemFontConfigInfo(OH_Drawing_FontConfigInfo* drawFontCfgInfo)](#oh_drawing_destroysystemfontconfiginfo) | 释放系统字体配置信息占用的的内存。 |
| [void OH_Drawing_SetTextStyleFontStyleStruct(OH_Drawing_TextStyle* drawingTextStyle,OH_Drawing_FontStyleStruct fontStyle)](#oh_drawing_settextstylefontstylestruct) | 设置文本样式中的字体样式，包括字体字重、字体宽度和字体斜度。 |
| [void OH_Drawing_SetTextStyleBadgeType(OH_Drawing_TextStyle* style, OH_Drawing_TextBadgeType textBadgeType)](#oh_drawing_settextstylebadgetype) | 设置文本排版时是否使能上标或下标。未调用此接口时，默认不使能。 |
| [OH_Drawing_FontStyleStruct OH_Drawing_TextStyleGetFontStyleStruct(OH_Drawing_TextStyle* drawingTextStyle)](#oh_drawing_textstylegetfontstylestruct) | 获取文本样式中的字体样式，包括字体字重、字体宽度和字体斜度。 |
| [void OH_Drawing_SetTypographyStyleFontStyleStruct(OH_Drawing_TypographyStyle* drawingStyle,OH_Drawing_FontStyleStruct fontStyle)](#oh_drawing_settypographystylefontstylestruct) | 设置排版样式中默认文本样式的字体样式，包括字体字重、字体宽度和字体斜度。 |
| [OH_Drawing_FontStyleStruct OH_Drawing_TypographyStyleGetFontStyleStruct(OH_Drawing_TypographyStyle* drawingStyle)](#oh_drawing_typographystylegetfontstylestruct) | 获取排版样式中默认文本样式的字体样式，包括字体字重、字体宽度和字体斜度。 |
| [void OH_Drawing_TextStyleSetBackgroundRect(OH_Drawing_TextStyle* style,const OH_Drawing_RectStyle_Info* rectStyleInfo, int styleId)](#oh_drawing_textstylesetbackgroundrect) | 设置文本背景矩形框和样式id。样式id仅当背景框为圆角矩形时有效。 |
| [void OH_Drawing_TypographyHandlerAddSymbol(OH_Drawing_TypographyCreate* handler, uint32_t symbol)](#oh_drawing_typographyhandleraddsymbol) | 设置排版创建过程中的符号。 |
| [void OH_Drawing_TextStyleAddFontFeature(OH_Drawing_TextStyle* style, const char* tag, int value)](#oh_drawing_textstyleaddfontfeature) | 设置文本样式中指定字体特征是否启用。 |
| [void OH_Drawing_TextStyleAddFontVariation(OH_Drawing_TextStyle* style, const char* axis, const float value)](#oh_drawing_textstyleaddfontvariation) | 添加可变字体属性。对应的字体文件（.ttf文件）需要支持可变调节，此接口才能生效。当对应的字体不支持可变调节时，此接口调用不生效。 |
| [OH_Drawing_FontFeature* OH_Drawing_TextStyleGetFontFeatures(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetfontfeatures) | 获取指定文本样式的字体特征map容器中所有内容。 |
| [void OH_Drawing_TextStyleDestroyFontFeatures(OH_Drawing_FontFeature* fontFeature, size_t fontFeatureSize)](#oh_drawing_textstyledestroyfontfeatures) | 释放存放字体特征所有内容的结构体数组所占用的空间。 |
| [size_t OH_Drawing_TextStyleGetFontFeatureSize(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetfontfeaturesize) | 获取指定文本样式中字体特征map容器的大小。 |
| [void OH_Drawing_TextStyleClearFontFeature(OH_Drawing_TextStyle* style)](#oh_drawing_textstyleclearfontfeature) | 清除指定文本样式的字体特征map容器中所有内容。 |
| [double OH_Drawing_TextStyleGetBaselineShift(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetbaselineshift) | 获取指定文本样式的基线偏移。 |
| [void OH_Drawing_TextStyleSetBaselineShift(OH_Drawing_TextStyle* style, double lineShift)](#oh_drawing_textstylesetbaselineshift) | 设置文本样式基线偏移。 |
| [void OH_Drawing_TypographyTextSetHeightBehavior(OH_Drawing_TypographyStyle* style,OH_Drawing_TextHeightBehavior heightMode)](#oh_drawing_typographytextsetheightbehavior) | 设置文本高度修饰符模式。 |
| [OH_Drawing_TextHeightBehavior OH_Drawing_TypographyTextGetHeightBehavior(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographytextgetheightbehavior) | 获取文本高度修饰符模式。 |
| [OH_Drawing_Font_Metrics* OH_Drawing_TypographyGetLineFontMetrics(OH_Drawing_Typography* typography,size_t lineNumber, size_t* fontMetricsSize)](#oh_drawing_typographygetlinefontmetrics) | 从排版对象中目标行获取所有字体度量信息，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用，否则会返回空指针。不再需要[OH_Drawing_Font_Metrics](capi-drawing-oh-drawing-font-metrics.md)时，请使用[OH_Drawing_TypographyDestroyLineFontMetrics](capi-drawing-text-typography-h.md#oh_drawing_typographydestroylinefontmetrics)接口释放该对象的指针。 |
| [void OH_Drawing_TypographyDestroyLineFontMetrics(OH_Drawing_Font_Metrics* lineFontMetric)](#oh_drawing_typographydestroylinefontmetrics) | 释放指定行所有字体度量结构体集合所占用的所有空间。 |
| [bool OH_Drawing_TextStyleIsEqual(const OH_Drawing_TextStyle* style, const OH_Drawing_TextStyle* comparedStyle)](#oh_drawing_textstyleisequal) | 判断两个文本样式对象是否相等，字宽属性不参与对比。 |
| [bool OH_Drawing_TextStyleIsEqualByFont(const OH_Drawing_TextStyle* style, const OH_Drawing_TextStyle* comparedStyle)](#oh_drawing_textstyleisequalbyfont) | 判断两个文本样式对象的字体样式属性是否相等。 |
| [bool OH_Drawing_TextStyleIsAttributeMatched(const OH_Drawing_TextStyle* style,const OH_Drawing_TextStyle* comparedStyle, OH_Drawing_TextStyleType textStyleType)](#oh_drawing_textstyleisattributematched) | 判断两个文本样式对象是否有一样的字体样式类型。 |
| [void OH_Drawing_TextStyleSetPlaceholder(OH_Drawing_TextStyle* style)](#oh_drawing_textstylesetplaceholder) | 设置占位符。 |
| [bool OH_Drawing_TextStyleIsPlaceholder(OH_Drawing_TextStyle* style)](#oh_drawing_textstyleisplaceholder) | 返回是否有设置文本占位符。 |
| [OH_Drawing_TextAlign OH_Drawing_TypographyStyleGetEffectiveAlignment(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographystylegeteffectivealignment) | 获取文本对齐模式。 |
| [bool OH_Drawing_TypographyStyleIsHintEnabled(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographystyleishintenabled) | 获取文本是否启用字形轮廓自动调整，字形轮廓自动调整用于在渲染小字号文本时改善其可读性和外观。 |
| [void OH_Drawing_SetTypographyStyleTextStrutStyle(OH_Drawing_TypographyStyle* style, OH_Drawing_StrutStyle* strutstyle)](#oh_drawing_settypographystyletextstrutstyle) | 设置文本支柱样式。 |
| [OH_Drawing_StrutStyle* OH_Drawing_TypographyStyleGetStrutStyle(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographystylegetstrutstyle) | 获取文本支柱样式。 |
| [void OH_Drawing_TypographyStyleDestroyStrutStyle(OH_Drawing_StrutStyle* strutstyle)](#oh_drawing_typographystyledestroystrutstyle) | 释放被支柱样式对象占据的内存。 |
| [bool OH_Drawing_TypographyStyleStrutStyleEquals(OH_Drawing_StrutStyle* from, OH_Drawing_StrutStyle* to)](#oh_drawing_typographystylestrutstyleequals) | 判断支柱样式结构体是否相同。 |
| [void OH_Drawing_TypographyStyleSetHintsEnabled(OH_Drawing_TypographyStyle* style, bool hintsEnabled)](#oh_drawing_typographystylesethintsenabled) | 设置文本是否启用字形轮廓自动调整，字形轮廓自动调整用于在渲染小字号文本时改善其可读性和外观。 |
| [void  OH_Drawing_TypographyMarkDirty(OH_Drawing_Typography* typography)](#oh_drawing_typographymarkdirty) | 将排版标记为脏数据，用于初始化排版状态。 |
| [int32_t OH_Drawing_TypographyGetUnresolvedGlyphsCount(OH_Drawing_Typography* typography)](#oh_drawing_typographygetunresolvedglyphscount) | 获取文本中尚未解析的字形的数量，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用并生效之后调用。 |
| [void OH_Drawing_TypographyUpdateFontSize(OH_Drawing_Typography* typography, size_t from, size_t to, float fontSize)](#oh_drawing_typographyupdatefontsize) | 更新排版对象中的字体大小。 |
| [void OH_Drawing_TypographyUpdateFontColor(OH_Drawing_Typography* typography, uint32_t color)](#oh_drawing_typographyupdatefontcolor) | 更新排版对象中的字体颜色。如果当前装饰线未设置颜色，使用该接口也会同时更新装饰线的颜色。使用该接口更新字体颜色属性后，可直接使用[OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint)进行绘制生效。 |
| [void OH_Drawing_TypographyUpdateDecoration(OH_Drawing_Typography* typography, OH_Drawing_TextDecoration decoration)](#oh_drawing_typographyupdatedecoration) | 更新排版对象中的文本装饰线类型。使用该接口更新文本装饰线类型属性后，可直接使用[OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint)进行绘制生效。 |
| [void OH_Drawing_TypographyUpdateDecorationThicknessScale(OH_Drawing_Typography* typography,double decorationThicknessScale)](#oh_drawing_typographyupdatedecorationthicknessscale) | 更新排版对象中的文本装饰线的粗细缩放比例。使用该接口更新文本装饰线粗细缩放比例属性后，可直接使用[OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint)进行绘制生效。 |
| [void OH_Drawing_TypographyUpdateDecorationStyle(OH_Drawing_Typography* typography,OH_Drawing_TextDecorationStyle decorationStyle)](#oh_drawing_typographyupdatedecorationstyle) | 更新排版对象中的文本装饰线样式。使用该接口更新文本装饰线样式属性后，可直接使用[OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint)进行绘制生效。 |
| [bool OH_Drawing_TypographyTextGetLineStyle(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographytextgetlinestyle) | 获取文本排版是否启用行样式。 |
| [OH_Drawing_FontWeight OH_Drawing_TypographyTextlineStyleGetFontWeight(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographytextlinestylegetfontweight) | 获取文本排版行样式字重。 |
| [OH_Drawing_FontStyle OH_Drawing_TypographyTextlineStyleGetFontStyle(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographytextlinestylegetfontstyle) | 获取文本排版样式中支柱样式的字体样式。 |
| [char** OH_Drawing_TypographyTextlineStyleGetFontFamilies(OH_Drawing_TypographyStyle* style, size_t* num)](#oh_drawing_typographytextlinestylegetfontfamilies) | 获取文本排版行样式字体家族名。 |
| [void OH_Drawing_TypographyTextlineStyleDestroyFontFamilies(char** fontFamilies, size_t fontFamiliesNum)](#oh_drawing_typographytextlinestyledestroyfontfamilies) | 释放字体类型占用的内存。 |
| [double OH_Drawing_TypographyTextlineStyleGetFontSize(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographytextlinestylegetfontsize) | 获取文本排版行样式字号。 |
| [double OH_Drawing_TypographyTextlineStyleGetHeightScale(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographytextlinestylegetheightscale) | 获取文本排版行样式的行高缩放系数。 |
| [bool OH_Drawing_TypographyTextlineStyleGetHeightOnly(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographytextlinestylegetheightonly) | 获取字体渲染过程中计算字体块高度相关参数的方法。 |
| [bool OH_Drawing_TypographyTextlineStyleGetHalfLeading(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographytextlinestylegethalfleading) | 获取文本排版行样式是否为一半行间距。 |
| [double OH_Drawing_TypographyTextlineStyleGetSpacingScale(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographytextlinestylegetspacingscale) | 获取文本排版行样式间距比例。 |
| [bool OH_Drawing_TypographyTextlineGetStyleOnly(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographytextlinegetstyleonly) | 获取文本排版是否仅启用行样式。 |
| [OH_Drawing_TextAlign OH_Drawing_TypographyGetTextAlign(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographygettextalign) | 获取文本对齐方式。 |
| [OH_Drawing_TextDirection OH_Drawing_TypographyGetTextDirection(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographygettextdirection) | 获取指定排版样式中的文本方向。 |
| [size_t OH_Drawing_TypographyGetTextMaxLines(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographygettextmaxlines) | 获取文本的最大行数。 |
| [char* OH_Drawing_TypographyGetTextEllipsis(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographygettextellipsis) | 获取指定排版样式设置的省略号文本。 |
| [void OH_Drawing_TypographyDestroyEllipsis(char* ellipsis)](#oh_drawing_typographydestroyellipsis) | 释放省略号名称列表占用的内存。 |
| [bool OH_Drawing_TypographyStyleEquals(OH_Drawing_TypographyStyle* from, OH_Drawing_TypographyStyle* to)](#oh_drawing_typographystyleequals) | 判断排版样式是否相同，当前文本高度修饰符模式[OH_Drawing_TextHeightBehavior](capi-drawing-text-typography-h.md#oh_drawing_textheightbehavior)没有被纳入比较。 |
| [uint32_t OH_Drawing_TextStyleGetColor(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetcolor) | 获取文本颜色。 |
| [OH_Drawing_TextDecorationStyle OH_Drawing_TextStyleGetDecorationStyle(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetdecorationstyle) | 获取文本装饰样式。 |
| [OH_Drawing_FontWeight OH_Drawing_TextStyleGetFontWeight(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetfontweight) | 获取字重。 |
| [OH_Drawing_FontStyle OH_Drawing_TextStyleGetFontStyle(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetfontstyle) | 获取指定文本样式的字体样式。 |
| [OH_Drawing_TextBaseline OH_Drawing_TextStyleGetBaseline(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetbaseline) | 获取指定文本样式的字体基线位置。 |
| [char** OH_Drawing_TextStyleGetFontFamilies(OH_Drawing_TextStyle* style, size_t* num)](#oh_drawing_textstylegetfontfamilies) | 获取字体类型名称列表。 |
| [void OH_Drawing_TextStyleDestroyFontFamilies(char** fontFamilies, size_t num)](#oh_drawing_textstyledestroyfontfamilies) | 释放长度为num的字体家族名称列表占用的内存。 |
| [double OH_Drawing_TextStyleGetFontSize(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetfontsize) | 获取指定文本样式字号。 |
| [double OH_Drawing_TextStyleGetLetterSpacing(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetletterspacing) | 获取指定文本样式的字符间距。 |
| [double OH_Drawing_TextStyleGetWordSpacing(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetwordspacing) | 获取指定文本样式的单词间距。 |
| [double OH_Drawing_TextStyleGetFontHeight(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetfontheight) | 获取指定文本样式行高缩放系数。 |
| [bool OH_Drawing_TextStyleGetHalfLeading(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegethalfleading) | 获取指定文本样式一半行间距开关状态。 |
| [const char* OH_Drawing_TextStyleGetLocale(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetlocale) | 获取语言环境。 |
| [void OH_Drawing_TypographyDestroyTextBox(OH_Drawing_TextBox* textBox)](#oh_drawing_typographydestroytextbox) | 释放文本框占用的内存。 |
| [void OH_Drawing_SetTextShadow(OH_Drawing_TextShadow* shadow, uint32_t color, OH_Drawing_Point* offset,double blurRadius)](#oh_drawing_settextshadow) | 设置字体阴影对象的参数。 |
| [OH_Drawing_TextTab* OH_Drawing_CreateTextTab(OH_Drawing_TextAlign alignment, float location)](#oh_drawing_createtexttab) | 创建文本制表符对象。 |
| [void OH_Drawing_DestroyTextTab(OH_Drawing_TextTab* tab)](#oh_drawing_destroytexttab) | 释放文本制表符对象占据的内存。 |
| [OH_Drawing_TextAlign OH_Drawing_GetTextTabAlignment(OH_Drawing_TextTab* tab)](#oh_drawing_gettexttabalignment) | 获取文本制表符对象的对齐方式。 |
| [float OH_Drawing_GetTextTabLocation(OH_Drawing_TextTab* tab)](#oh_drawing_gettexttablocation) | 获取文本制表符的位置。 |
| [void OH_Drawing_SetTypographyTextTab(OH_Drawing_TypographyStyle* style, OH_Drawing_TextTab* tab)](#oh_drawing_settypographytexttab) | 设置文本制表符对齐方式及位置。当设置了文本对齐方式或者省略号风格时制表符不生效，当制表符位置小于1.0时为替换成空格的效果。 |
| [size_t OH_Drawing_GetDrawingArraySize(OH_Drawing_Array* drawingArray)](#oh_drawing_getdrawingarraysize) | 获取传入类型为对象数组[OH_Drawing_Array](capi-drawing-oh-drawing-array.md)中的对象个数。 |
| [void OH_Drawing_SetTypographyTextTrailingSpaceOptimized(OH_Drawing_TypographyStyle* style, bool trailingSpaceOptimized)](#oh_drawing_settypographytexttrailingspaceoptimized) | 设置文本排版时行尾空格是否参与对齐计算。 |
| [void OH_Drawing_TypographyHandlerAddEncodedText(OH_Drawing_TypographyCreate* handler, const void* text,size_t byteLength, OH_Drawing_TextEncoding textEncodingType)](#oh_drawing_typographyhandleraddencodedtext) | 添加指定编码的文本。 |
| [void OH_Drawing_SetTypographyTextAutoSpace(OH_Drawing_TypographyStyle *style, bool enableAutoSpace)](#oh_drawing_settypographytextautospace) | 设置文本排版时是否使能自动间距。<br>默认不使能自动间距，一旦使能则会自动调整CJK（中文字符、日文字符、韩文字符）与西文（拉丁字母、西里尔字母、希腊字母）、CJK与数字、CJK与版权符号、版权符号与数字、版权符号与西文之间的间距。 |
| [void OH_Drawing_TypographyUpdateDecorationColor(OH_Drawing_Typography* typography, uint32_t color)](#oh_drawing_typographyupdatedecorationcolor) | 更新排版对象中的文本装饰线颜色。<br> 使用该接口更新文本装饰线颜色属性后，可直接使用[OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint)进行绘制生效。 |
| [void OH_Drawing_SetTypographyVerticalAlignment(OH_Drawing_TypographyStyle* style,OH_Drawing_TextVerticalAlignment align)](#oh_drawing_settypographyverticalalignment) | 设置文本垂直对齐方式。 |
| [OH_Drawing_TypographyStyle* OH_Drawing_CopyTypographyStyle(OH_Drawing_TypographyStyle* style)](#oh_drawing_copytypographystyle) | 创建一个段落样式的对象副本，用于拷贝一个已有的段落样式对象。 |
| [OH_Drawing_TextStyle* OH_Drawing_CopyTextStyle(OH_Drawing_TextStyle* style)](#oh_drawing_copytextstyle) | 创建一个文本样式的对象副本，用于拷贝一个已有的文本样式对象。 |
| [OH_Drawing_TextShadow* OH_Drawing_CopyTextShadow(OH_Drawing_TextShadow* shadow)](#oh_drawing_copytextshadow) | 创建一个文本阴影的对象副本，用于拷贝一个已有的文本阴影对象。 |

## 枚举类型说明

### OH_Drawing_TextDirection

```
enum OH_Drawing_TextDirection
```

**描述**

文字方向。

| 枚举项 | 描述 |
| -- | -- |
| TEXT_DIRECTION_RTL | 方向：从右到左。 |
| TEXT_DIRECTION_LTR | 方向：从左到右。 |

### OH_Drawing_TextAlign

```
enum OH_Drawing_TextAlign
```

**描述**

文字对齐方式。

| 枚举项 | 描述 |
| -- | -- |
| TEXT_ALIGN_LEFT | 左对齐。 |
| TEXT_ALIGN_RIGHT | 右对齐。 |
| TEXT_ALIGN_CENTER | 居中对齐。 |
| TEXT_ALIGN_JUSTIFY | 两端对齐，即紧靠左和右边缘，中间单词空隙由空格填充，最后一行除外。 |
| TEXT_ALIGN_START | 当OH_Drawing_TextDirection是TEXT_DIRECTION_LTR时，TEXT_ALIGN_START和TEXT_ALIGN_LEFT相同；<br>类似地，当OH_Drawing_TextDirection是TEXT_DIRECTION_RTL时，TEXT_ALIGN_START和TEXT_ALIGN_RIGHT相同。 |
| TEXT_ALIGN_END | 当OH_Drawing_TextDirection是TEXT_DIRECTION_LTR时，TEXT_ALIGN_END和TEXT_ALIGN_RIGHT相同；<br>类似地，当OH_Drawing_TextDirection是TEXT_DIRECTION_RTL时，TEXT_ALIGN_END和TEXT_ALIGN_LEFT相同。 |

### OH_Drawing_FontWeight

```
enum OH_Drawing_FontWeight
```

**描述**

字重。

| 枚举项 | 描述 |
| -- | -- |
| FONT_WEIGHT_100 | 字重为thin。 |
| FONT_WEIGHT_200 | 字重为extra-light。 |
| FONT_WEIGHT_300 | 字重为light。 |
| FONT_WEIGHT_400 | 字重为normal/regular。 |
| FONT_WEIGHT_500 | 字重为medium。 |
| FONT_WEIGHT_600 | 字重为semi-bold。 |
| FONT_WEIGHT_700 | 字重为bold。 |
| FONT_WEIGHT_800 | 字重为extra-bold。 |
| FONT_WEIGHT_900 | 字重为black。 |

### OH_Drawing_TextBaseline

```
enum OH_Drawing_TextBaseline
```

**描述**

基线位置。

| 枚举项 | 描述 |
| -- | -- |
| TEXT_BASELINE_ALPHABETIC | 用于表音文字，基线在中间偏下的位置。 |
| TEXT_BASELINE_IDEOGRAPHIC | 用于表意文字，基线位于底部。 |

### OH_Drawing_TextDecoration

```
enum OH_Drawing_TextDecoration
```

**描述**

文本装饰。

| 枚举项 | 描述 |
| -- | -- |
| TEXT_DECORATION_NONE = 0x0 | 无装饰。 |
| TEXT_DECORATION_UNDERLINE = 0x1 | 下划线。 |
| TEXT_DECORATION_OVERLINE = 0x2 | 上划线。 |
| TEXT_DECORATION_LINE_THROUGH = 0x4 | 删除线。 |

### OH_Drawing_FontStyle

```
enum OH_Drawing_FontStyle
```

**描述**

区分字体是否为斜体。

| 枚举项 | 描述 |
| -- | -- |
| FONT_STYLE_NORMAL | 非斜体。 |
| FONT_STYLE_ITALIC | 斜体。 |
| FONT_STYLE_OBLIQUE | 倾斜字体。<br>**起始版本：** 12 |

### OH_Drawing_PlaceholderVerticalAlignment

```
enum OH_Drawing_PlaceholderVerticalAlignment
```

**描述**

占位符垂直对齐枚举。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| ALIGNMENT_OFFSET_AT_BASELINE | 偏移于基线对齐。 |
| ALIGNMENT_ABOVE_BASELINE | 高于基线对齐。 |
| ALIGNMENT_BELOW_BASELINE | 低于基线对齐。 |
| ALIGNMENT_TOP_OF_ROW_BOX | 行框顶部对齐。 |
| ALIGNMENT_BOTTOM_OF_ROW_BOX | 行框底部对齐。 |
| ALIGNMENT_CENTER_OF_ROW_BOX | 行框中心对齐。 |
| ALIGNMENT_FOLLOW_PARAGRAPH<sup>20+</sup> | 跟随文本垂直对齐方式。 |

### OH_Drawing_TextVerticalAlignment

```
enum OH_Drawing_TextVerticalAlignment
```

**描述**

垂直对齐方式枚举。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| TEXT_VERTICAL_ALIGNMENT_BASELINE | 基线对齐。 |
| TEXT_VERTICAL_ALIGNMENT_BOTTOM | 底部对齐。 |
| TEXT_VERTICAL_ALIGNMENT_CENTER | 居中对齐。 |
| TEXT_VERTICAL_ALIGNMENT_TOP | 顶部对齐。 |

### OH_Drawing_TextDecorationStyle

```
enum OH_Drawing_TextDecorationStyle
```

**描述**

文本装饰样式枚举。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| TEXT_DECORATION_STYLE_SOLID | 实心样式。 |
| TEXT_DECORATION_STYLE_DOUBLE | 双重样式。 |
| TEXT_DECORATION_STYLE_DOTTED | 圆点样式。 |
| TEXT_DECORATION_STYLE_DASHED | 虚线样式。 |
| TEXT_DECORATION_STYLE_WAVY | 波浪样式。 |

### OH_Drawing_EllipsisModal

```
enum OH_Drawing_EllipsisModal
```

**描述**

省略号样式枚举。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| ELLIPSIS_MODAL_HEAD = 0 | 头部模式，即省略号放在文本头部。 |
| ELLIPSIS_MODAL_MIDDLE = 1 | 中部模式，即省略号放在文本中部。 |
| ELLIPSIS_MODAL_TAIL = 2 | 尾部模式，即省略号放在文本尾部。 |

### OH_Drawing_BreakStrategy

```
enum OH_Drawing_BreakStrategy
```

**描述**

文本的中断策略枚举。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| BREAK_STRATEGY_GREEDY = 0 | 贪心策略，换行时尽可能填满每一行。 |
| BREAK_STRATEGY_HIGH_QUALITY = 1 | 高质量策略，换行时优先考虑文本的连续性。 |
| BREAK_STRATEGY_BALANCED = 2 | 平衡策略，换行时在单词边界换行。 |

### OH_Drawing_WordBreakType

```
enum OH_Drawing_WordBreakType
```

**描述**

单词的断词方式枚举。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| WORD_BREAK_TYPE_NORMAL = 0 | 常规方式。 |
| WORD_BREAK_TYPE_BREAK_ALL = 1 | 全部中断方式。 |
| WORD_BREAK_TYPE_BREAK_WORD = 2 | 单词中断方式。 |
| WORD_BREAK_TYPE_BREAK_HYPHEN = 3 | 每行末尾单词尝试通过连字符“-”进行断行，若无法添加连字符“-”，则跟`WORD_BREAK_TYPE_BREAK_WORD`保持一致。<br/> **起始版本：** 18 |

### OH_Drawing_RectHeightStyle

```
enum OH_Drawing_RectHeightStyle
```

**描述**

矩形框高度样式枚举。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| RECT_HEIGHT_STYLE_TIGHT | 紧密样式。 |
| RECT_HEIGHT_STYLE_MAX | 最大样式。 |
| RECT_HEIGHT_STYLE_INCLUDELINESPACEMIDDLE | 包含行间距中间样式。 |
| RECT_HEIGHT_STYLE_INCLUDELINESPACETOP | 包含行间距顶部样式。 |
| RECT_HEIGHT_STYLE_INCLUDELINESPACEBOTTOM | 包含行间距底部样式。 |
| RECT_HEIGHT_STYLE_STRUCT | 结构样式。 |

### OH_Drawing_RectWidthStyle

```
enum OH_Drawing_RectWidthStyle
```

**描述**

矩形框宽度样式枚举。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| RECT_WIDTH_STYLE_TIGHT | 紧密样式。 |
| RECT_WIDTH_STYLE_MAX | 最大样式。 |

### OH_Drawing_TextBadgeType

```
enum OH_Drawing_TextBadgeType
```

**描述**

上下标样式枚举。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| TEXT_BADGE_NONE | 不使能上标或下标。 |
| TEXT_SUPERSCRIPT | 使能上标。 |
| TEXT_SUBSCRIPT | 使能下标。 |

### OH_Drawing_FontConfigInfoErrorCode

```
enum OH_Drawing_FontConfigInfoErrorCode
```

**描述**

获取系统字体配置信息列表结果枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| SUCCESS_FONT_CONFIG_INFO = 0 | 获取系统字体配置信息列表成功。 |
| ERROR_FONT_CONFIG_INFO_UNKNOWN = 1 | 未知错误。 |
| ERROR_FONT_CONFIG_INFO_PARSE_FILE = 2 | 解析系统配置文件失败。 |
| ERROR_FONT_CONFIG_INFO_ALLOC_MEMORY = 3 | 申请内存失败。 |
| ERROR_FONT_CONFIG_INFO_COPY_STRING_DATA = 4 | 拷贝字符串数据失败。 |

### OH_Drawing_FontWidth

```
enum OH_Drawing_FontWidth
```

**描述**

字体宽度的枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| FONT_WIDTH_ULTRA_CONDENSED = 1 | 表示超窄的字宽。 |
| FONT_WIDTH_EXTRA_CONDENSED = 2 | 表示特窄的字宽。 |
| FONT_WIDTH_CONDENSED = 3 | 表示窄的字宽。 |
| FONT_WIDTH_SEMI_CONDENSED = 4 | 表示半窄的字宽。 |
| FONT_WIDTH_NORMAL = 5 | 表示常规的字宽。 |
| FONT_WIDTH_SEMI_EXPANDED = 6 | 表示半宽的字宽。 |
| FONT_WIDTH_EXPANDED = 7 | 表示宽的字宽。 |
| FONT_WIDTH_EXTRA_EXPANDED = 8 | 表示特宽的字宽。 |
| FONT_WIDTH_ULTRA_EXPANDED = 9 | 表示超宽的字宽。 |

### OH_Drawing_TextHeightBehavior

```
enum OH_Drawing_TextHeightBehavior
```

**描述**

文本高度修饰符模式枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| TEXT_HEIGHT_ALL = 0x0 | 段落中第一行顶部和段落中最后一行底部[OH_Drawing_SetTextStyleFontHeight](capi-drawing-text-typography-h.md#oh_drawing_settextstylefontheight)设置的高度生效。 |
| TEXT_HEIGHT_DISABLE_FIRST_ASCENT = 0x1 | 禁止段落中第一行顶部[OH_Drawing_SetTextStyleFontHeight](capi-drawing-text-typography-h.md#oh_drawing_settextstylefontheight)设置的高度生效。 |
| TEXT_HEIGHT_DISABLE_LAST_ASCENT = 0x2 | 禁止段落中最后一行底部[OH_Drawing_SetTextStyleFontHeight](capi-drawing-text-typography-h.md#oh_drawing_settextstylefontheight)设置的高度生效。 |
| TEXT_HEIGHT_DISABLE_ALL = 0x1 \| 0x2 | 禁止段落中第一行顶部和段落中最后一行底部[OH_Drawing_SetTextStyleFontHeight](capi-drawing-text-typography-h.md#oh_drawing_settextstylefontheight)设置的高度生效。 |

### OH_Drawing_TextStyleType

```
enum OH_Drawing_TextStyleType
```

**描述**

文本样式类型枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| TEXT_STYLE_NONE | 无文本样式。 |
| TEXT_STYLE_ALL_ATTRIBUTES | 所有文本样式。 |
| TEXT_STYLE_FONT | 字体样式。 |
| TEXT_STYLE_FOREGROUND | 文本前景样式。 |
| TEXT_STYLE_BACKGROUND | 文本背景样式。 |
| TEXT_STYLE_SHADOW | 文本阴影样式。 |
| TEXT_STYLE_DECORATIONS | 文本装饰样式。 |
| TEXT_STYLE_LETTER_SPACING | 文本字符间距样式。 |
| TEXT_STYLE_WORD_SPACING | 文本单词间距样式。 |


## 函数说明

### OH_Drawing_CreateTypographyStyle()

```
OH_Drawing_TypographyStyle* OH_Drawing_CreateTypographyStyle(void)
```

**描述**

创建指向OH_Drawing_TypographyStyle对象的指针。不再需要[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)时，请使用[OH_Drawing_DestroyTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_destroytypographystyle)接口释放该对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* | 指向创建的[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)对象的指针。 |

### OH_Drawing_DestroyTypographyStyle()

```
void OH_Drawing_DestroyTypographyStyle(OH_Drawing_TypographyStyle* style)
```

**描述**

释放被OH_Drawing_TypographyStyle对象占据的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)对象的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |

### OH_Drawing_SetTypographyTextDirection()

```
void OH_Drawing_SetTypographyTextDirection(OH_Drawing_TypographyStyle* style, int direction)
```

**描述**

设置指定排版样式中的文本方向。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向排版样式[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| int direction | 设置文本方向，设置0为从右到左，设置1或其他值为从左到右，具体可见[OH_Drawing_TextDirection](capi-drawing-text-typography-h.md#oh_drawing_textdirection)枚举。 |

### OH_Drawing_SetTypographyTextAlign()

```
void OH_Drawing_SetTypographyTextAlign(OH_Drawing_TypographyStyle* style, int align)
```

**描述**

设置文本对齐方式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向排版样式[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| int align | 设置文本对齐方式，设置1为右对齐，设置2为居中对齐，设置3为两端对齐，设置4为与文字方向相同，设置5为文字方向相反，设置0或其它为左对齐，具体可见[OH_Drawing_TextAlign](capi-drawing-text-typography-h.md#oh_drawing_textalign)枚举。 |

### OH_Drawing_TypographyGetEffectiveAlignment()

```
int OH_Drawing_TypographyGetEffectiveAlignment(OH_Drawing_TypographyStyle* style)
```

**描述**

获取文字对齐方式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向排版样式[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)对象的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回文字对齐方式。 |

### OH_Drawing_SetTypographyTextMaxLines()

```
void OH_Drawing_SetTypographyTextMaxLines(OH_Drawing_TypographyStyle* style, int lineNumber)
```

**描述**

设置文本最大行数。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向排版样式[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| int lineNumber | 最大行数。 |

### OH_Drawing_CreateTextStyle()

```
OH_Drawing_TextStyle* OH_Drawing_CreateTextStyle(void)
```

**描述**

创建指向OH_Drawing_TextStyle对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* | 指向创建的[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)对象的指针。 |

### OH_Drawing_TypographyGetTextStyle()

```
OH_Drawing_TextStyle* OH_Drawing_TypographyGetTextStyle(OH_Drawing_TypographyStyle* style)
```

**描述**

获取指定排版样式中设置的默认文本样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向排版样式[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)对象的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* | 返回指向文本样式[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，不再需要时，请使用[OH_Drawing_DestroyTextStyle](capi-drawing-text-typography-h.md#oh_drawing_destroytextstyle)释放该对象指针。 |

### OH_Drawing_DestroyTextStyle()

```
void OH_Drawing_DestroyTextStyle(OH_Drawing_TextStyle* style)
```

**描述**

释放被OH_Drawing_TextStyle对象占据的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

### OH_Drawing_SetTextStyleColor()

```
void OH_Drawing_SetTextStyleColor(OH_Drawing_TextStyle* style, uint32_t color)
```

**描述**

设置文本颜色。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| uint32_t color | 颜色。 |

### OH_Drawing_SetTextStyleFontSize()

```
void OH_Drawing_SetTextStyleFontSize(OH_Drawing_TextStyle* style, double fontSize)
```

**描述**

设置字号。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| double fontSize | 字号。 |

### OH_Drawing_SetTextStyleFontWeight()

```
void OH_Drawing_SetTextStyleFontWeight(OH_Drawing_TextStyle* style, int fontWeight)
```

**描述**

设置字重。目前只有系统默认字体支持字重的调节，其他字体设置字重值小于semi-bold时字体粗细无变化，当设置字重值大于等于semi-bold时可能会触发伪加粗效果。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| int fontWeight | 设置字重，设置0字重为thin，设置1字重为extra-light，设置2字重为light，设置4字重为medium，设置5字重为semi-bold，<br>设置6字重为bold，设置7字重为extra-bold，设置8字重为black，设置3或其它字重为normal/regular，具体可见[OH_Drawing_FontWeight](capi-drawing-text-typography-h.md#oh_drawing_fontweight)枚举。 |

### OH_Drawing_SetTextStyleBaseLine()

```
void OH_Drawing_SetTextStyleBaseLine(OH_Drawing_TextStyle* style, int baseline)
```

**描述**

设置文本样式的字体基线位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| int baseline | 设置字体基线位置，设置1基线位于底部，设置0或其它基线在中间偏下的位置，具体可见[OH_Drawing_TextBaseline](capi-drawing-text-typography-h.md#oh_drawing_textbaseline)枚举。 |

### OH_Drawing_SetTextStyleDecoration()

```
void OH_Drawing_SetTextStyleDecoration(OH_Drawing_TextStyle* style, int decoration)
```

**描述**

设置指定文本样式中的装饰线类型，只能设置一个装饰线类型，添加多个需要使用[OH_Drawing_AddTextStyleDecoration](capi-drawing-text-typography-h.md#oh_drawing_addtextstyledecoration)。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| int decoration | 设置装饰，设置1为下划线，设置2为上划线，设置4为删除线，设置0或其它为无装饰，具体可见[OH_Drawing_TextDecoration](capi-drawing-text-typography-h.md#oh_drawing_textdecoration)枚举。 |

### OH_Drawing_AddTextStyleDecoration()

```
void OH_Drawing_AddTextStyleDecoration(OH_Drawing_TextStyle* style, int decoration)
```

**描述**

新增指定装饰，可同时显示多种装饰线。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式对象[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| int decoration | 要新增的装饰。设置1为新增下划线，设置2为新增上划线，设置4为新增删除线。可通过位或操作一次新增多种装饰线。<br>设置非[OH_Drawing_TextDecoration](capi-drawing-text-typography-h.md#oh_drawing_textdecoration)枚举的装饰样式则保持原有装饰。 |

### OH_Drawing_RemoveTextStyleDecoration()

```
void OH_Drawing_RemoveTextStyleDecoration(OH_Drawing_TextStyle* style, int decoration)
```

**描述**

删除指定装饰。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式对象[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| int decoration | 要删除的装饰。应该与现有的装饰相匹配，设置1为删除下划线，设置2为删除上划线，设置4为删除删除线，可通过位或操作一次删除多种装饰线。<br>设置非[OH_Drawing_TextDecoration](capi-drawing-text-typography-h.md#oh_drawing_textdecoration)枚举的装饰样式则保持原有装饰。 |

### OH_Drawing_SetTextStyleDecorationColor()

```
void OH_Drawing_SetTextStyleDecorationColor(OH_Drawing_TextStyle* style, uint32_t color)
```

**描述**

设置指定文本样式中的装饰线颜色。如果不调用该接口或者设置color为0时，装饰线颜色跟随文本颜色。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| uint32_t color | 颜色。 |

### OH_Drawing_SetTextStyleFontHeight()

```
void OH_Drawing_SetTextStyleFontHeight(OH_Drawing_TextStyle* style, double fontHeight)
```

**描述**

设置行高，按当前字体大小的倍数进行设置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| double fontHeight | 当前字体大小的倍数。 |

### OH_Drawing_SetTextStyleFontFamilies()

```
void OH_Drawing_SetTextStyleFontFamilies(OH_Drawing_TextStyle* style,int fontFamiliesNumber, const char* fontFamilies[])
```

**描述**

设置指定文本样式的字体家族类型。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| int fontFamiliesNumber | 字体名称数量，禁止填入负数。 |
| fontFamilies |  指向字体家族类型的指针。 |

### OH_Drawing_SetTextStyleFontStyle()

```
void OH_Drawing_SetTextStyleFontStyle(OH_Drawing_TextStyle* style, int fontStyle)
```

**描述**

为指定文本样式设置字体样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| int fontStyle | 设置字体样式，设置1为斜体，设置0或其它为非斜体，具体可见[OH_Drawing_FontStyle](capi-drawing-text-typography-h.md#oh_drawing_fontstyle)枚举。 |

### OH_Drawing_SetTextStyleLocale()

```
void OH_Drawing_SetTextStyleLocale(OH_Drawing_TextStyle* style, const char* locale)
```

**描述**

设置文本语言环境。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| const char* locale | 语言类型，数据类型为指向char的指针，如'en'代表英文，'zh-Hans'代表简体中文，'zh-Hant'代表繁体中文。 |

### OH_Drawing_SetTextStyleForegroundBrush()

```
void OH_Drawing_SetTextStyleForegroundBrush(OH_Drawing_TextStyle* style, OH_Drawing_Brush* foregroundBrush)
```

**描述**

设置指定文本样式中的前景色画刷。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* foregroundBrush | 指向画刷[OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)对象的指针，由[OH_Drawing_BrushCreate](capi-drawing-brush-h.md#oh_drawing_brushcreate)获取。 |

### OH_Drawing_TextStyleGetForegroundBrush()

```
void OH_Drawing_TextStyleGetForegroundBrush(OH_Drawing_TextStyle* style, OH_Drawing_Brush* foregroundBrush)
```

**描述**

返回设置的前景色画刷。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* foregroundBrush | 指向画刷[OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)对象的指针，由[OH_Drawing_BrushCreate](capi-drawing-brush-h.md#oh_drawing_brushcreate)获取。 |

### OH_Drawing_SetTextStyleForegroundPen()

```
void OH_Drawing_SetTextStyleForegroundPen(OH_Drawing_TextStyle* style, OH_Drawing_Pen* foregroundPen)
```

**描述**

设置指定文本样式中的前景色画笔。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* foregroundPen | 指向画笔[OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)对象的指针，由[OH_Drawing_PenCreate](capi-drawing-pen-h.md#oh_drawing_pencreate)获取。 |

### OH_Drawing_TextStyleGetForegroundPen()

```
void OH_Drawing_TextStyleGetForegroundPen(OH_Drawing_TextStyle* style, OH_Drawing_Pen* foregroundPen)
```

**描述**

返回设置的前景色画笔。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* foregroundPen | 指向画笔[OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)对象的指针，由[OH_Drawing_PenCreate](capi-drawing-pen-h.md#oh_drawing_pencreate)获取。 |

### OH_Drawing_SetTextStyleBackgroundBrush()

```
void OH_Drawing_SetTextStyleBackgroundBrush(OH_Drawing_TextStyle* style, OH_Drawing_Brush* foregroundPen)
```

**描述**

设置指定文本样式中的背景色画刷。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* foregroundPen | 指向画刷[OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)对象的指针，由[OH_Drawing_BrushCreate](capi-drawing-brush-h.md#oh_drawing_brushcreate)获取。 |

### OH_Drawing_TextStyleGetBackgroundBrush()

```
void OH_Drawing_TextStyleGetBackgroundBrush(OH_Drawing_TextStyle* style, OH_Drawing_Brush* backgroundBrush)
```

**描述**

返回设置的背景色画刷。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* backgroundBrush | 指向画刷[OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)对象的指针，由[OH_Drawing_BrushCreate](capi-drawing-brush-h.md#oh_drawing_brushcreate)获取。 |

### OH_Drawing_SetTextStyleBackgroundPen()

```
void OH_Drawing_SetTextStyleBackgroundPen(OH_Drawing_TextStyle* style, OH_Drawing_Pen* backgroundPen)
```

**描述**

设置指定文本样式中的背景色画笔。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* backgroundPen | 指向画笔[OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)对象的指针，由[OH_Drawing_PenCreate](capi-drawing-pen-h.md#oh_drawing_pencreate)获取。 |

### OH_Drawing_TextStyleGetBackgroundPen()

```
void OH_Drawing_TextStyleGetBackgroundPen(OH_Drawing_TextStyle* style, OH_Drawing_Pen* backgroundPen)
```

**描述**

返回设置的背景色画笔。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* backgroundPen | 指向画笔[OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)对象的指针，由[OH_Drawing_PenCreate](capi-drawing-pen-h.md#oh_drawing_pencreate)获取。 |

### OH_Drawing_CreateTypographyHandler()

```
OH_Drawing_TypographyCreate* OH_Drawing_CreateTypographyHandler(OH_Drawing_TypographyStyle* style,OH_Drawing_FontCollection* fontCollection)
```

**描述**

创建指向OH_Drawing_TypographyCreate对象的指针。不再需要[OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)时，请使用[OH_Drawing_DestroyTypographyHandler](capi-drawing-text-typography-h.md#oh_drawing_destroytypographyhandler)接口释放该对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向排版样式[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* fontCollection | 指向字体集对象[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)的指针，由[OH_Drawing_CreateFontCollection](capi-drawing-font-collection-h.md#oh_drawing_createfontcollection)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)* | 指向新创建的OH_Drawing_TypographyCreate对象的指针。 |

### OH_Drawing_DestroyTypographyHandler()

```
void OH_Drawing_DestroyTypographyHandler(OH_Drawing_TypographyCreate* handler)
```

**描述**

释放被OH_Drawing_TypographyCreate对象占据的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)* handler | 指向[OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)对象的指针，由[OH_Drawing_CreateTypographyHandler](capi-drawing-text-typography-h.md#oh_drawing_createtypographyhandler)获取。 |

### OH_Drawing_TypographyHandlerPushTextStyle()

```
void OH_Drawing_TypographyHandlerPushTextStyle(OH_Drawing_TypographyCreate* handler, OH_Drawing_TextStyle* style)
```

**描述**

将指定文本样式压入文本样式栈，后续添加的文本总是会使用栈顶的文本样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)* handler | 指向[OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)对象的指针，由[OH_Drawing_CreateTypographyHandler](capi-drawing-text-typography-h.md#oh_drawing_createtypographyhandler)获取。 |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

### OH_Drawing_TypographyHandlerAddText()

```
void OH_Drawing_TypographyHandlerAddText(OH_Drawing_TypographyCreate* handler, const char* text)
```

**描述**

设置文本内容。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)* handler | 指向[OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)对象的指针，由[OH_Drawing_CreateTypographyHandler](capi-drawing-text-typography-h.md#oh_drawing_createtypographyhandler)获取。 |
| const char* text | 指向文本内容的指针。 |

### OH_Drawing_TypographyHandlerPopTextStyle()

```
void OH_Drawing_TypographyHandlerPopTextStyle(OH_Drawing_TypographyCreate* handler)
```

**描述**

从文本样式栈中弹出栈顶文本样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)* handler | 指向[OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)对象的指针，由[OH_Drawing_CreateTypographyHandler](capi-drawing-text-typography-h.md#oh_drawing_createtypographyhandler)获取。 |

### OH_Drawing_CreateTypography()

```
OH_Drawing_Typography* OH_Drawing_CreateTypography(OH_Drawing_TypographyCreate* handler)
```

**描述**

创建指向OH_Drawing_Typography对象的指针。不再需要[OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)时，请使用[OH_Drawing_DestroyTypography](capi-drawing-text-typography-h.md#oh_drawing_destroytypography)接口释放该对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)* handler | 指向[OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)对象的指针，由[OH_Drawing_CreateTypographyHandler](capi-drawing-text-typography-h.md#oh_drawing_createtypographyhandler)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* | 指向OH_Drawing_Typography对象的指针。 |

### OH_Drawing_DestroyTypography()

```
void OH_Drawing_DestroyTypography(OH_Drawing_Typography* typography)
```

**描述**

释放OH_Drawing_Typography对象占据的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向排版对象[OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |

### OH_Drawing_TypographyLayout()

```
void OH_Drawing_TypographyLayout(OH_Drawing_Typography* typography, double maxWidth)
```

**描述**

排版布局。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向排版对象[OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |
| double maxWidth | 文本最大宽度。 |

### OH_Drawing_TypographyPaint()

```
void OH_Drawing_TypographyPaint(OH_Drawing_Typography* typography, OH_Drawing_Canvas* canvas,double potisionX, double potisionY)
```

**描述**

在指定位置绘制文本，从左上角开始绘制，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用并生效之后调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |
| [OH_Drawing_Canvas](capi-drawing-oh-drawing-canvas.md)* canvas | 指向OH_Drawing_Canvas对象的指针，由[OH_Drawing_CanvasCreate](capi-drawing-canvas-h.md#oh_drawing_canvascreate)获取。 |
| double potisionX | x坐标。 |
| double potisionY | y坐标。 |

### OH_Drawing_TypographyPaintOnPath()

```
void OH_Drawing_TypographyPaintOnPath(OH_Drawing_Typography* typography, OH_Drawing_Canvas* canvas,OH_Drawing_Path* path, double hOffset, double vOffset)
```

**描述**

沿指定路径绘制文本。建议搭配[OH_Drawing_SetTypographyTextMaxLines](capi-drawing-text-typography-h.md#oh_drawing_settypographytextmaxlines)接口设置最大行为1行，避免因文本宽度超过排版宽度出现跨行重叠问题。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |
| [OH_Drawing_Canvas](capi-drawing-oh-drawing-canvas.md)* canvas | 指向OH_Drawing_Canvas对象的指针，由[OH_Drawing_CanvasCreate](capi-drawing-canvas-h.md#oh_drawing_canvascreate)获取。 |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向OH_Drawing_Path对象的指针，由[OH_Drawing_PathCreate](capi-drawing-path-h.md#oh_drawing_pathcreate)获取。 |
| double hOffset | 水平偏移量，文本沿路径的水平偏移（X 轴），向前为正，向后为负。 |
| double vOffset | 垂直偏移量，文本沿路径的垂直偏移（Y 轴），向下为正，向上为负。 |

### OH_Drawing_TypographyGetMaxWidth()

```
double OH_Drawing_TypographyGetMaxWidth(OH_Drawing_Typography* typography)
```

**描述**

获取用户设置的排版宽度，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 返回最大宽度。 |

### OH_Drawing_TypographyGetHeight()

```
double OH_Drawing_TypographyGetHeight(OH_Drawing_Typography* typography)
```

**描述**

获取排版对象整体的高度，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 返回高度。 |

### OH_Drawing_TypographyGetLongestLine()

```
double OH_Drawing_TypographyGetLongestLine(OH_Drawing_Typography* typography)
```

**描述**

获取排版对象最长行的宽度，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用，建议实际使用时将返回值向上取整。当文本内容为空时，返回0.0。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 返回最长行的宽度。 |

### OH_Drawing_TypographyGetLongestLineWithIndent()

```
double OH_Drawing_TypographyGetLongestLineWithIndent(OH_Drawing_Typography* typography)
```

**描述**

获取排版对象最长行的宽度（该宽度包含当前行缩进的宽度），该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用，建议实际使用时将返回值向上取整。当文本内容为空时，返回0.0。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向[OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)对象的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 返回最长行的宽度（该宽度包含当前行缩进的宽度），单位：物理像素px。 |

### OH_Drawing_TypographyGetMinIntrinsicWidth()

```
double OH_Drawing_TypographyGetMinIntrinsicWidth(OH_Drawing_Typography* typography)
```

**描述**

获取排版对象的最小固有宽度，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 返回最小固有宽度。 |

### OH_Drawing_TypographyGetMaxIntrinsicWidth()

```
double OH_Drawing_TypographyGetMaxIntrinsicWidth(OH_Drawing_Typography* typography)
```

**描述**

获取排版对象的最大固有宽度，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 返回最大固有宽度。 |

### OH_Drawing_TypographyGetAlphabeticBaseline()

```
double OH_Drawing_TypographyGetAlphabeticBaseline(OH_Drawing_Typography* typography)
```

**描述**

获取排版样式字母文字基线。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 返回字母文字基线。 |

### OH_Drawing_TypographyGetIdeographicBaseline()

```
double OH_Drawing_TypographyGetIdeographicBaseline(OH_Drawing_Typography* typography)
```

**描述**

获取排版样式表意文字基线。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 返回表意文字基线。 |

### OH_Drawing_TypographyHandlerAddPlaceholder()

```
void OH_Drawing_TypographyHandlerAddPlaceholder(OH_Drawing_TypographyCreate* handler,OH_Drawing_PlaceholderSpan* span)
```

**描述**

设置占位符。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)* handler | 指向[OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)对象的指针，由[OH_Drawing_CreateTypographyHandler](capi-drawing-text-typography-h.md#oh_drawing_createtypographyhandler)获取。 |
| [OH_Drawing_PlaceholderSpan](capi-drawing-oh-drawing-placeholderspan.md)* span | 指向[OH_Drawing_PlaceholderSpan](capi-drawing-oh-drawing-placeholderspan.md)对象的指针。 |

### OH_Drawing_TypographyDidExceedMaxLines()

```
bool OH_Drawing_TypographyDidExceedMaxLines(OH_Drawing_Typography* typography)
```

**描述**

获取排版对象中文本是否超过最大行，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用，如果没有通过[OH_Drawing_SetTypographyTextMaxLines](capi-drawing-text-typography-h.md#oh_drawing_settypographytextmaxlines)接口设置最大行，则返回false。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回文本是否超过最大行，true表示超过，false表示未超过。 |

### OH_Drawing_TypographyGetRectsForRange()

```
OH_Drawing_TextBox* OH_Drawing_TypographyGetRectsForRange(OH_Drawing_Typography* typography,size_t start, size_t end, OH_Drawing_RectHeightStyle heightStyle, OH_Drawing_RectWidthStyle widthStyle)
```

**描述**

获取排版对象中指定范围内的文本框，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。不再需要[OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)时，请使用[OH_Drawing_TypographyDestroyTextBox](capi-drawing-text-typography-h.md#oh_drawing_typographydestroytextbox)接口释放该对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |
| size_t start | 设置开始位置。 |
| size_t end | 设置结束位置。 |
| [OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle) heightStyle | 设置高度样式，支持可选的高度样式具体可见[OH_Drawing_RectHeightStyle](capi-drawing-text-typography-h.md#oh_drawing_rectheightstyle)枚举。 |
| [OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle) widthStyle | 设置宽度样式，支持可选的宽度样式具体可见[OH_Drawing_RectWidthStyle](capi-drawing-text-typography-h.md#oh_drawing_rectwidthstyle)枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_Drawing_TextBox* | 返回指定范围内的文本框，具体可见[OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)结构体。 |

### OH_Drawing_TypographyGetRectsForPlaceholders()

```
OH_Drawing_TextBox* OH_Drawing_TypographyGetRectsForPlaceholders(OH_Drawing_Typography* typography)
```

**描述**

获取排版对象中占位符的文本框，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。不再需要[OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)时，请使用[OH_Drawing_TypographyDestroyTextBox](capi-drawing-text-typography-h.md#oh_drawing_typographydestroytextbox)接口释放该对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)* | 返回占位符的文本框，返回类型为[OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)结构体。 |

### OH_Drawing_GetLeftFromTextBox()

```
float OH_Drawing_GetLeftFromTextBox(OH_Drawing_TextBox* textbox, int index)
```

**描述**

获取文本框左侧位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)* textbox | 指向OH_Drawing_TextBox对象的指针，由[OH_Drawing_TypographyGetRectsForRange](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforrange)或[OH_Drawing_TypographyGetRectsForPlaceholders](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforplaceholders)获取。 |
| int index | 文本框的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回文本框左侧位置。 |

### OH_Drawing_GetRightFromTextBox()

```
float OH_Drawing_GetRightFromTextBox(OH_Drawing_TextBox* textbox, int index)
```

**描述**

获取文本框右侧位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)* textbox | 指向OH_Drawing_TextBox对象的指针，由[OH_Drawing_TypographyGetRectsForRange](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforrange)或[OH_Drawing_TypographyGetRectsForPlaceholders](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforplaceholders)获取。 |
| int index | 文本框的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回文本框右侧位置。 |

### OH_Drawing_GetTopFromTextBox()

```
float OH_Drawing_GetTopFromTextBox(OH_Drawing_TextBox* textbox, int index)
```

**描述**

获取文本框顶部位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)* textbox | 指向OH_Drawing_TextBox对象的指针，由[OH_Drawing_TypographyGetRectsForRange](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforrange)或[OH_Drawing_TypographyGetRectsForPlaceholders](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforplaceholders)获取。 |
| int index | 文本框的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回文本框顶部位置。 |

### OH_Drawing_GetBottomFromTextBox()

```
float OH_Drawing_GetBottomFromTextBox(OH_Drawing_TextBox* textbox, int index)
```

**描述**

获取文本框底部位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)* textbox | 指向OH_Drawing_TextBox对象的指针，由[OH_Drawing_TypographyGetRectsForRange](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforrange)或[OH_Drawing_TypographyGetRectsForPlaceholders](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforplaceholders)获取。 |
| int index | 文本框的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回文本框底部位置。 |

### OH_Drawing_GetTextDirectionFromTextBox()

```
int OH_Drawing_GetTextDirectionFromTextBox(OH_Drawing_TextBox* textbox, int index)
```

**描述**

获取文本框方向。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)* textbox | 指向[OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)对象的指针，由[OH_Drawing_TypographyGetRectsForRange](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforrange)或[OH_Drawing_TypographyGetRectsForPlaceholders](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforplaceholders)获取。 |
| int index | 文本框的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回文本框方向。 |

### OH_Drawing_GetSizeOfTextBox()

```
size_t OH_Drawing_GetSizeOfTextBox(OH_Drawing_TextBox* textBox)
```

**描述**

获取文本框数量大小。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)* textBox | 指向OH_Drawing_TextBox对象的指针，由[OH_Drawing_TypographyGetRectsForRange](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforrange)或[OH_Drawing_TypographyGetRectsForPlaceholders](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforplaceholders)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| size_t | 返回文本框数量大小。 |

### OH_Drawing_TypographyGetGlyphPositionAtCoordinate()

```
OH_Drawing_PositionAndAffinity* OH_Drawing_TypographyGetGlyphPositionAtCoordinate(OH_Drawing_Typography* typography,double dx, double dy)
```

**描述**

获取坐标处文本的索引位置和亲和性。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |
| double dx | 光标的x坐标。 |
| double dy | 光标的y坐标。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_PositionAndAffinity](capi-drawing-oh-drawing-positionandaffinity.md)* | 返回坐标处字体的索引位置和亲和性，返回类型为[OH_Drawing_PositionAndAffinity](capi-drawing-oh-drawing-positionandaffinity.md)结构体。 |

### OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster()

```
OH_Drawing_PositionAndAffinity* OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster(OH_Drawing_Typography* typography, double dx, double dy)
```

**描述**

获取坐标处文本所属字符簇的索引位置和亲和性，字符簇指一个或多个字符组成的整体。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |
| double dx | 光标的x坐标。 |
| double dy | 光标的y坐标。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_PositionAndAffinity](capi-drawing-oh-drawing-positionandaffinity.md)* | 返回坐标处指定类型字体的索引位置和亲和性，返回类型为[OH_Drawing_PositionAndAffinity](capi-drawing-oh-drawing-positionandaffinity.md)结构体。 |

### OH_Drawing_GetPositionFromPositionAndAffinity()

```
size_t OH_Drawing_GetPositionFromPositionAndAffinity(OH_Drawing_PositionAndAffinity* positionAndAffinity)
```

**描述**

获取OH_Drawing_PositionAndAffinity对象的位置属性。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_PositionAndAffinity](capi-drawing-oh-drawing-positionandaffinity.md)* positionAndAffinity | 指向OH_Drawing_PositionAndAffinity对象的指针，由[OH_Drawing_TypographyGetGlyphPositionAtCoordinate](capi-drawing-text-typography-h.md#oh_drawing_typographygetglyphpositionatcoordinate)或[OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster](capi-drawing-text-typography-h.md#oh_drawing_typographygetglyphpositionatcoordinatewithcluster)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| size_t | 返回OH_Drawing_PositionAndAffinity对象的位置属性。 |

### OH_Drawing_GetAffinityFromPositionAndAffinity()

```
int OH_Drawing_GetAffinityFromPositionAndAffinity(OH_Drawing_PositionAndAffinity* positionAndAffinity)
```

**描述**

获取OH_Drawing_PositionAndAffinity对象的亲和性，根据亲和性可判断字体会靠近前方文本还是后方文本。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_PositionAndAffinity](capi-drawing-oh-drawing-positionandaffinity.md)* positionAndAffinity | 指向OH_Drawing_PositionAndAffinity对象的指针，由[OH_Drawing_TypographyGetGlyphPositionAtCoordinate](capi-drawing-text-typography-h.md#oh_drawing_typographygetglyphpositionatcoordinate)或[OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster](capi-drawing-text-typography-h.md#oh_drawing_typographygetglyphpositionatcoordinatewithcluster)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回OH_Drawing_PositionAndAffinity对象的亲和性。 |

### OH_Drawing_TypographyGetWordBoundary()

```
OH_Drawing_Range* OH_Drawing_TypographyGetWordBoundary(OH_Drawing_Typography* typography, size_t offset)
```

**描述**

获取排版对象中单词的边界。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |
| size_t offset | 单词索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Range](capi-drawing-oh-drawing-range.md)* | 返回单词边界，返回类型为[OH_Drawing_Range](capi-drawing-oh-drawing-range.md)结构体。 |

### OH_Drawing_GetStartFromRange()

```
size_t OH_Drawing_GetStartFromRange(OH_Drawing_Range* range)
```

**描述**

获取OH_Drawing_Range对象开始位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Range](capi-drawing-oh-drawing-range.md)* range | 指向OH_Drawing_Range对象的指针，由[OH_Drawing_TypographyGetWordBoundary](capi-drawing-text-typography-h.md#oh_drawing_typographygetwordboundary)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| size_t | 返回OH_Drawing_Range对象开始位置。 |

### OH_Drawing_GetEndFromRange()

```
size_t OH_Drawing_GetEndFromRange(OH_Drawing_Range* range)
```

**描述**

获取OH_Drawing_Range对象结束位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Range](capi-drawing-oh-drawing-range.md)* range | 指向OH_Drawing_Range对象的指针，由[OH_Drawing_TypographyGetWordBoundary](capi-drawing-text-typography-h.md#oh_drawing_typographygetwordboundary)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| size_t | 返回OH_Drawing_Range对象结束位置。 |

### OH_Drawing_TypographyGetLineCount()

```
size_t OH_Drawing_TypographyGetLineCount(OH_Drawing_Typography* typography)
```

**描述**

获取排版对象中文本行数，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| size_t | 返回行数。 |

### OH_Drawing_SetTextStyleDecorationStyle()

```
void OH_Drawing_SetTextStyleDecorationStyle(OH_Drawing_TextStyle* style, int decorationStyle)
```

**描述**

设置指定文本样式中的装饰线样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| int decorationStyle | 设置的文本装饰样式，支持可选的装饰样式具体可见[OH_Drawing_TextDecorationStyle](capi-drawing-text-typography-h.md#oh_drawing_textdecorationstyle)枚举。 |

### OH_Drawing_SetTextStyleDecorationThicknessScale()

```
void OH_Drawing_SetTextStyleDecorationThicknessScale(OH_Drawing_TextStyle* style, double decorationThicknessScale)
```

**描述**

设置文本装饰线的粗细缩放比例。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| double decorationThicknessScale | 粗细缩放比例。默认值为1，如果设置的粗细缩放比例小于等于0，不会绘制装饰线。 |

### OH_Drawing_SetTextStyleLetterSpacing()

```
void OH_Drawing_SetTextStyleLetterSpacing(OH_Drawing_TextStyle* style, double letterSpacing)
```

**描述**

设置文本的字符间距。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| double letterSpacing | 间距大小。 |

### OH_Drawing_SetTextStyleWordSpacing()

```
void OH_Drawing_SetTextStyleWordSpacing(OH_Drawing_TextStyle* style, double wordSpacing)
```

**描述**

设置文本的单词间距。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| double wordSpacing | 间距大小。 |

### OH_Drawing_SetTextStyleHalfLeading()

```
void OH_Drawing_SetTextStyleHalfLeading(OH_Drawing_TextStyle* style, bool halfLeading)
```

**描述**

设置文本为一半行间距。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| bool halfLeading | 设置一半行间距是否生效。true表示生效，false表示不生效。 |

### OH_Drawing_SetTextStyleEllipsis()

```
void OH_Drawing_SetTextStyleEllipsis(OH_Drawing_TextStyle* style, const char* ellipsis)
```

**描述**

设置文本的省略号内容。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| const char* ellipsis | 设置省略号内容，数据类型为指向char的指针。 |

### OH_Drawing_SetTextStyleEllipsisModal()

```
void OH_Drawing_SetTextStyleEllipsisModal(OH_Drawing_TextStyle* style, int ellipsisModal)
```

**描述**

设置文本的省略号样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| int ellipsisModal | 设置省略号样式，支持可选的省略号样式具体可见[OH_Drawing_EllipsisModal](capi-drawing-text-typography-h.md#oh_drawing_ellipsismodal)枚举。 |

### OH_Drawing_SetTypographyTextBreakStrategy()

```
void OH_Drawing_SetTypographyTextBreakStrategy(OH_Drawing_TypographyStyle* style, int breakStrategy)
```

**描述**

设置文本的中断策略。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向排版样式[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| int breakStrategy | 设置中断策略，支持可选的中断策略具体可见[OH_Drawing_BreakStrategy](capi-drawing-text-typography-h.md#oh_drawing_breakstrategy)枚举。 |

### OH_Drawing_SetTypographyTextWordBreakType()

```
void OH_Drawing_SetTypographyTextWordBreakType(OH_Drawing_TypographyStyle* style, int wordBreakType)
```

**描述**

设置单词的断词方式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向排版样式[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| int wordBreakType | 设置断词方式，支持可选的断词方式样式具体可见[OH_Drawing_WordBreakType](capi-drawing-text-typography-h.md#oh_drawing_wordbreaktype)枚举。 |

### OH_Drawing_SetTypographyTextEllipsisModal()

```
void OH_Drawing_SetTypographyTextEllipsisModal(OH_Drawing_TypographyStyle* style, int ellipsisModal)
```

**描述**

设置文本的省略模式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向OH_Drawing_TypographyStyle对象的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| int ellipsisModal | 设置省略号样式，支持可选的省略号样式样式具体可见[OH_Drawing_EllipsisModal](capi-drawing-text-typography-h.md#oh_drawing_ellipsismodal)枚举。 |

### OH_Drawing_SetTypographyTextEllipsis()

```
void OH_Drawing_SetTypographyTextEllipsis(OH_Drawing_TypographyStyle* style, const char* ellipsis)
```

**描述**

设置排版样式省略号文本。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向排版样式对象[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| const char* ellipsis | 省略号文本。 |

### OH_Drawing_TypographyGetLineHeight()

```
double OH_Drawing_TypographyGetLineHeight(OH_Drawing_Typography* typography, int lineNumber)
```

**描述**

获取排版对象中指定行的行高，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |
| int lineNumber | 要指定的行数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 返回指定行的行高。 |

### OH_Drawing_TypographyGetLineWidth()

```
double OH_Drawing_TypographyGetLineWidth(OH_Drawing_Typography* typography, int lineNumber)
```

**描述**

获取指定行的行宽，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |
| int lineNumber | 要指定的行数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 返回指定行的行宽。 |

### OH_Drawing_SetTypographyTextSplitRatio()

```
void OH_Drawing_SetTypographyTextSplitRatio(OH_Drawing_TypographyStyle* style, float textSplitRatio)
```

**描述**

设置文本划分比率。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向排版样式[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| float textSplitRatio | 文本划分比率。 |

### OH_Drawing_TypographyIsLineUnlimited()

```
bool OH_Drawing_TypographyIsLineUnlimited(OH_Drawing_TypographyStyle* style)
```

**描述**

获取文本是否有最大行数限制。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向文本风格[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回文本是否有最大行数限制，true表示有最大行数限制，false表示无最大行数限制。 |

### OH_Drawing_TypographyIsEllipsized()

```
bool OH_Drawing_TypographyIsEllipsized(OH_Drawing_TypographyStyle* style)
```

**描述**

获取指定排版样式是否配置省略号。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向排版样式[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回指定排版样式是否配置省略号，true表示已配置省略号，false表示没有配置省略号。 |

### OH_Drawing_SetTypographyTextLocale()

```
void OH_Drawing_SetTypographyTextLocale(OH_Drawing_TypographyStyle* style, const char* locale)
```

**描述**

设置指定排版样式的语言环境。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向排版样式[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| const char* locale | 语言环境，数据类型为指向char的指针，如'en'代表英文，'zh-Hans'代表简体中文，'zh-Hant'代表繁体中文。 |

### OH_Drawing_TextStyleGetFontMetrics()

```
bool OH_Drawing_TextStyleGetFontMetrics(OH_Drawing_Typography* typography,OH_Drawing_TextStyle* style, OH_Drawing_Font_Metrics* fontmetrics)
```

**描述**

获取文本字体属性。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向文本对象[OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式对象[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| [OH_Drawing_Font_Metrics](capi-drawing-oh-drawing-font-metrics.md)* fontmetrics | 指向字体属性对象[OH_Drawing_Font_Metrics](capi-drawing-oh-drawing-font-metrics.md)的指针，由[OH_Drawing_Font_Metrics](capi-drawing-oh-drawing-font-metrics.md)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 是否获取到字体属性。true表示获取到字体属性，false表示未获取到字体属性。 |

### OH_Drawing_SetTypographyTextStyle()

```
void OH_Drawing_SetTypographyTextStyle(OH_Drawing_TypographyStyle* handler, OH_Drawing_TextStyle* style)
```

**描述**

设置排版样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* handler | 指向排版样式[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

### OH_Drawing_CreateFontDescriptor()

```
OH_Drawing_FontDescriptor* OH_Drawing_CreateFontDescriptor(void)
```

**描述**

构造字体描述对象，用于描述系统字体详细信息。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)* | 返回指向已创建的字体描述对象[OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)的指针。 |

### OH_Drawing_DestroyFontDescriptor()

```
void OH_Drawing_DestroyFontDescriptor(OH_Drawing_FontDescriptor* descriptor)
```

**描述**

释放字体描述对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)* descriptor | 指向字体描述对象[OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)的指针，由[OH_Drawing_CreateFontDescriptor](capi-drawing-text-typography-h.md#oh_drawing_createfontdescriptor)获取。 |

### OH_Drawing_CreateFontParser()

```
OH_Drawing_FontParser* OH_Drawing_CreateFontParser(void)
```

**描述**

构造字体解析对象，用于解析系统字体。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontParser](capi-drawing-oh-drawing-fontparser.md)* | 返回指向已创建的字体解析对象[OH_Drawing_FontParser](capi-drawing-oh-drawing-fontparser.md)的指针。 |

### OH_Drawing_DestroyFontParser()

```
void OH_Drawing_DestroyFontParser(OH_Drawing_FontParser* parser)
```

**描述**

释放字体解析对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontParser](capi-drawing-oh-drawing-fontparser.md)* parser | 指向字体解析对象[OH_Drawing_FontParser](capi-drawing-oh-drawing-fontparser.md)的指针，由[OH_Drawing_CreateFontParser](capi-drawing-text-typography-h.md#oh_drawing_createfontparser)获取。 |

### OH_Drawing_FontParserGetSystemFontList()

```
char** OH_Drawing_FontParserGetSystemFontList(OH_Drawing_FontParser* fontParser, size_t* num)
```

**描述**

获取系统字体名称列表，此接口仅在2in1、phone设备上可用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontParser](capi-drawing-oh-drawing-fontparser.md)* fontParser | 指向字体解析对象[OH_Drawing_FontParser](capi-drawing-oh-drawing-fontparser.md)的指针，由[OH_Drawing_CreateFontParser](capi-drawing-text-typography-h.md#oh_drawing_createfontparser)获取。 |
| size_t* num | 返回获取到的系统字体名称数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| char** | 返回获取到的系统字体列表。 |

### OH_Drawing_DestroySystemFontList()

```
void OH_Drawing_DestroySystemFontList(char** fontList, size_t num)
```

**描述**

释放系统字体名称列表占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| char** fontList | 指向系统字体名称列表的指针。 |
| size_t num | 系统字体名称列表的数量。 |

### OH_Drawing_FontParserGetFontByName()

```
OH_Drawing_FontDescriptor* OH_Drawing_FontParserGetFontByName(OH_Drawing_FontParser* fontParser, const char* name)
```

**描述**

根据传入的系统字体名称获取系统字体的相关信息。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontParser](capi-drawing-oh-drawing-fontparser.md)* fontParser | 指向字体解析对象[OH_Drawing_FontParser](capi-drawing-oh-drawing-fontparser.md)的指针，由[OH_Drawing_CreateFontParser](capi-drawing-text-typography-h.md#oh_drawing_createfontparser)获取。 |
| const char* name | 系统字体名。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_Drawing_FontDescriptor* | 返回系统字体描述对象，不再需要时，请使用[OH_Drawing_DestroyFontParser](capi-drawing-text-typography-h.md#oh_drawing_destroyfontparser)释放该对象指针。 |

### OH_Drawing_TypographyGetLineMetrics()

```
OH_Drawing_LineMetrics* OH_Drawing_TypographyGetLineMetrics(OH_Drawing_Typography* typography)
```

**描述**

获取排版对象的行位置信息，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。不再需要[OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md)时，请使用[OH_Drawing_DestroyLineMetrics](capi-drawing-text-typography-h.md#oh_drawing_destroylinemetrics)接口释放该对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向文本对象[OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md)* | 返回指向行位置信息对象[OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md)的指针。 |

### OH_Drawing_LineMetricsGetSize()

```
size_t OH_Drawing_LineMetricsGetSize(OH_Drawing_LineMetrics* lineMetrics)
```

**描述**

获取行数量。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md)* lineMetrics | 指向行位置信息对象[OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md)的指针，由[OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| size_t | 返回行数量。 |

### OH_Drawing_DestroyLineMetrics()

```
void OH_Drawing_DestroyLineMetrics(OH_Drawing_LineMetrics* lineMetrics)
```

**描述**

释放行位置信息对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md)* lineMetrics | 指向行位置信息对象[OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md)的指针，由[OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md)获取。 |

### OH_Drawing_TypographyGetLineMetricsAt()

```
bool OH_Drawing_TypographyGetLineMetricsAt(OH_Drawing_Typography* typography,int lineNumber, OH_Drawing_LineMetrics* lineMetric)
```

**描述**

获取排版对象的指定行位置信息，具体参见[OH_Drawing_LineMetr](capi-drawing-oh-drawing-linemetrics.md)结构体，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向文本对象[OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |
| int lineNumber | 要获取的行数。 |
| [OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md)* lineMetric | 指向行位置信息对象[OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md)的指针，由[OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 行位置信息对象是否成功获取。true表示成功获取，false表示未成功获取。 |

### OH_Drawing_TypographyGetLineInfo()

```
bool OH_Drawing_TypographyGetLineInfo(OH_Drawing_Typography* typography, int lineNumber, bool oneLine,bool includeWhitespace, OH_Drawing_LineMetrics* drawingLineMetrics)
```

**描述**

获取排版对象中指定行的位置信息或指定行第一个字符的位置信息，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向文本对象[OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |
| int lineNumber | 行号。 |
| bool oneLine | true为获取整行的位置信息，false为获取第一个字符的位置信息。 |
| bool includeWhitespace | 文字宽度是否包含空白符。true表示不包含空白符，false表示包含空白符。 |
| [OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md)* drawingLineMetrics | 指向行位置信息对象[OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md)的指针，由[OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 指定行的行位置信息或第一个字符的位置信息是否成功获取，true表示成功获取，false表示未成功获取。 |

### OH_Drawing_SetTypographyTextFontWeight()

```
void OH_Drawing_SetTypographyTextFontWeight(OH_Drawing_TypographyStyle* style, int weight)
```

**描述**

设置排版样式默认字重。目前只有系统默认字体支持字重的调节，其他字体设置字重值小于semi-bold时字体粗细无变化，当设置字重值大于等于semi-bold时可能会触发伪加粗效果。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向排版样式对象[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| int weight | 设置字重，设置0字重为thin，设置1字重为extra-light，设置2字重为light，设置4字重为medium，设置5字重为semi-bold，<br>设置6字重为bold，设置7字重为extra-bold，设置8字重为black，设置3或其它字重为normal/regular，具体可见[OH_Drawing_FontWeight](capi-drawing-text-typography-h.md#oh_drawing_fontweight)枚举。 |

### OH_Drawing_SetTypographyTextFontStyle()

```
void OH_Drawing_SetTypographyTextFontStyle(OH_Drawing_TypographyStyle* style, int fontStyle)
```

**描述**

设置排版样式默认的字体样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向文本样式对象[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| int fontStyle | 设置字体样式，设置1为斜体，设置0或其它为非斜体，具体可见[OH_Drawing_FontStyle](capi-drawing-text-typography-h.md#oh_drawing_fontstyle)枚举。 |

### OH_Drawing_SetTypographyTextFontFamily()

```
void OH_Drawing_SetTypographyTextFontFamily(OH_Drawing_TypographyStyle* style, const char* fontFamily)
```

**描述**

设置字体家族的名称。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向排版样式[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| const char* fontFamily | 字体家族的名称，数据类型为指向char的指针。 |

### OH_Drawing_SetTypographyTextFontSize()

```
void OH_Drawing_SetTypographyTextFontSize(OH_Drawing_TypographyStyle* style, double fontSize)
```

**描述**

设置文本排版字号。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向排版样式[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| double fontSize | 字号（大于0）。 |

### OH_Drawing_SetTypographyTextFontHeight()

```
void OH_Drawing_SetTypographyTextFontHeight(OH_Drawing_TypographyStyle* style, double fontHeight)
```

**描述**

设置文本排版字体高度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向排版样式[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| double fontHeight | 字体高度。 |

### OH_Drawing_SetTypographyTextHalfLeading()

```
void OH_Drawing_SetTypographyTextHalfLeading(OH_Drawing_TypographyStyle* style, bool halfLeading)
```

**描述**

设置文本排版是否为一半行间距。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向排版样式[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| bool halfLeading | 设置一半行间距是否生效，true表示生效，false表示不生效。 |

### OH_Drawing_SetTypographyTextUseLineStyle()

```
void OH_Drawing_SetTypographyTextUseLineStyle(OH_Drawing_TypographyStyle* style, bool useLineStyle)
```

**描述**

设置文本排版是否启用行样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向文本风格对象[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| bool useLineStyle | 设置行样式是否启用，true表示启用，false表示不启用。 |

### OH_Drawing_SetTypographyTextLineStyleFontWeight()

```
void OH_Drawing_SetTypographyTextLineStyleFontWeight(OH_Drawing_TypographyStyle* style, int weight)
```

**描述**

设置排版样式中支柱样式的文本样式字重。目前只有系统默认字体支持字重的调节，其他字体设置字重值小于semi-bold时字体粗细无变化，当设置字重值大于等于semi-bold时可能会触发伪加粗效果。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向排版样式对象[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| int weight | 设置字重，设置0字重为thin，设置1字重为extra-light，设置2字重为light，设置4字重为medium，设置5字重为semi-bold，设置6字重为bold，设置7字重为extra-bold，设置8字重为black，设置3或其它字重为normal/regular，具体可见[OH_Drawing_FontWeight](capi-drawing-text-typography-h.md#oh_drawing_fontweight)枚举。 |

### OH_Drawing_SetTypographyTextLineStyleFontStyle()

```
void OH_Drawing_SetTypographyTextLineStyleFontStyle(OH_Drawing_TypographyStyle* style, int fontStyle)
```

**描述**

设置文本排版样式中支柱样式的字体样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向文本风格指向排版样式对象[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| int fontStyle | 设置字体样式，设置1为斜体，设置0或其它为非斜体，具体可见[OH_Drawing_FontStyle](capi-drawing-text-typography-h.md#oh_drawing_fontstyle)枚举。 |

### OH_Drawing_SetTypographyTextLineStyleFontFamilies()

```
void OH_Drawing_SetTypographyTextLineStyleFontFamilies(OH_Drawing_TypographyStyle* style,int fontFamiliesNumber, const char* fontFamilies[])
```

**描述**

设置文本排版行样式字体类型。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向文本风格对象[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| int fontFamiliesNumber | 字体名称数量。 |
| fontFamilies |  指向字体类型的指针。 |

### OH_Drawing_SetTypographyTextLineStyleFontSize()

```
void OH_Drawing_SetTypographyTextLineStyleFontSize(OH_Drawing_TypographyStyle* style, double lineStyleFontSize)
```

**描述**

设置文本排版行样式字号。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向文本风格对象[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| double lineStyleFontSize | 字号（大于0）。 |

### OH_Drawing_SetTypographyTextLineStyleFontHeight()

```
void OH_Drawing_SetTypographyTextLineStyleFontHeight(OH_Drawing_TypographyStyle* style, double lineStyleFontHeight)
```

**描述**

设置文本排版行样式字体高度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向文本风格对象[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| double lineStyleFontHeight | 字体高度。 |

### OH_Drawing_SetTypographyTextLineStyleHalfLeading()

```
void OH_Drawing_SetTypographyTextLineStyleHalfLeading(OH_Drawing_TypographyStyle* style, bool lineStyleHalfLeading)
```

**描述**

设置文本排版行样式是否为一半行间距。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向文本风格对象[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| bool lineStyleHalfLeading | 设置一半行间距是否生效。true表示生效，false表示不生效。 |

### OH_Drawing_SetTypographyTextLineStyleSpacingScale()

```
void OH_Drawing_SetTypographyTextLineStyleSpacingScale(OH_Drawing_TypographyStyle* style, double spacingScale)
```

**描述**

设置文本排版行样式间距比例。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向文本风格对象[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| double spacingScale | 间距比例。 |

### OH_Drawing_SetTypographyTextLineStyleOnly()

```
void OH_Drawing_SetTypographyTextLineStyleOnly(OH_Drawing_TypographyStyle* style, bool lineStyleOnly)
```

**描述**

设置文本排版是否仅启用行样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向文本风格对象[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| bool lineStyleOnly | 设置仅启用行样式是否生效。true表示生效，false表示不生效。 |

### OH_Drawing_CreateTextShadow()

```
OH_Drawing_TextShadow* OH_Drawing_CreateTextShadow(void)
```

**描述**

创建指向字体阴影对象的指针。不再需要[OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)时，请使用[OH_Drawing_DestroyTextShadow](capi-drawing-text-typography-h.md#oh_drawing_destroytextshadow)接口释放该对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)* | 指向创建的字体阴影对象。 |

### OH_Drawing_DestroyTextShadow()

```
void OH_Drawing_DestroyTextShadow(OH_Drawing_TextShadow* shadow)
```

**描述**

释放被字体阴影对象占据的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)* shadow | 指向字体阴影对象[OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)的指针，由[OH_Drawing_CreateTextShadow](capi-drawing-text-typography-h.md#oh_drawing_createtextshadow)获取。 |

### OH_Drawing_TextStyleGetShadows()

```
OH_Drawing_TextShadow* OH_Drawing_TextStyleGetShadows(OH_Drawing_TextStyle* style)
```

**描述**

获取字体阴影容器。不再需要[OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)时，请使用[OH_Drawing_DestroyTextShadows](capi-drawing-text-typography-h.md#oh_drawing_destroytextshadows)接口释放该对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)* | 返回指向字体阴影容器[OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)的指针。 |

### OH_Drawing_TextStyleGetShadowCount()

```
int OH_Drawing_TextStyleGetShadowCount(OH_Drawing_TextStyle* style)
```

**描述**

获取字体阴影容器的大小。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | int 返回字体阴影容器的大小。 |

### OH_Drawing_TextStyleAddShadow()

```
void OH_Drawing_TextStyleAddShadow(OH_Drawing_TextStyle* style, const OH_Drawing_TextShadow* shadow)
```

**描述**

字体阴影容器中添加字体阴影元素。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| const [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)* shadow | 指向字体阴影对象[OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)的指针，由[OH_Drawing_CreateTextShadow](capi-drawing-text-typography-h.md#oh_drawing_createtextshadow)获取。 |

### OH_Drawing_TextStyleClearShadows()

```
void OH_Drawing_TextStyleClearShadows(OH_Drawing_TextStyle* style)
```

**描述**

清除字体阴影容器中的所有元素。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

### OH_Drawing_TextStyleGetShadowWithIndex()

```
OH_Drawing_TextShadow* OH_Drawing_TextStyleGetShadowWithIndex(OH_Drawing_TextStyle* style, int index)
```

**描述**

根据下标获取字体阴影容器中的元素。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| int index | 下标索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)* | 返回指向字体阴影对象[OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)的指针。 |

### OH_Drawing_TypographySetIndents()

```
void OH_Drawing_TypographySetIndents(OH_Drawing_Typography* typography, int indentsNumber, const float indents[])
```

**描述**

设置文本的排版缩进，不调用此接口默认文本无缩进。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向排版对象[OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |
| int indentsNumber | 为段落设置的缩进数量。该值应小于或等于 indents 数组的长度，以避免访问数组越界导致的显示异常。 |
| indents |  指向浮点类型数组的指针，每个数组元素表示一个缩进宽度，单位为物理像素（px）。在应用[OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)接口时，需要先声明并初始化该浮点数组。 |

### OH_Drawing_TypographyGetIndentsWithIndex()

```
float OH_Drawing_TypographyGetIndentsWithIndex(OH_Drawing_Typography* typography, int index)
```

**描述**

根据行索引获取排版对象缩进容器中的元素，行索引从0开始。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向文本对象[OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |
| int index | 下标索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | float 返回索引对应的元素值。 |

### OH_Drawing_TypographyGetLineTextRange()

```
OH_Drawing_Range* OH_Drawing_TypographyGetLineTextRange(OH_Drawing_Typography* typography,int lineNumber, bool includeSpaces)
```

**描述**

获取排版对象中行的边界，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。该接口只能获取已有行的边界，即输入行索引从0开始，最大行索引为[OH_Drawing_TypographyGetLineCount](capi-drawing-text-typography-h.md#oh_drawing_typographygetlinecount) - 1。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向文本对象[OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |
| int lineNumber | 行索引 |
| bool includeSpaces | 设置返回的边界是否包含空格，true为包含空格，false为不包含空格。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Range](capi-drawing-oh-drawing-range.md)* | 返回指向行边界对象的指针[OH_Drawing_Range](capi-drawing-oh-drawing-range.md)。如果输入的行索引是非法的行索引，则返回的边界范围的start和end都为0。 |

### OH_Drawing_DestroyTextShadows()

```
void OH_Drawing_DestroyTextShadows(OH_Drawing_TextShadow* shadow)
```

**描述**

释放由被字体阴影对象OH_Drawing_TextShadow构成的vector占据的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)* shadow | 指向字体阴影对象[OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)的指针，由[OH_Drawing_CreateTextShadow](capi-drawing-text-typography-h.md#oh_drawing_createtextshadow)获取。 |

### OH_Drawing_GetSystemFontConfigInfo()

```
OH_Drawing_FontConfigInfo* OH_Drawing_GetSystemFontConfigInfo(OH_Drawing_FontConfigInfoErrorCode* errorCode)
```

**描述**

获取系统字体配置信息。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontConfigInfoErrorCode](#oh_drawing_fontconfiginfoerrorcode)* errorCode | 错误码，具体可见[OH_Drawing_FontConfigInfoErrorCode](capi-drawing-text-typography-h.md#oh_drawing_fontconfiginfoerrorcode)枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontConfigInfo](capi-drawing-oh-drawing-fontconfiginfo.md)* | 返回系统字体配置信息的指针，不再需要时，请使用[OH_Drawing_DestroySystemFontConfigInfo](capi-drawing-text-typography-h.md#oh_drawing_destroysystemfontconfiginfo)释放该对象指针。 |

### OH_Drawing_DestroySystemFontConfigInfo()

```
void OH_Drawing_DestroySystemFontConfigInfo(OH_Drawing_FontConfigInfo* drawFontCfgInfo)
```

**描述**

释放系统字体配置信息占用的的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontConfigInfo](capi-drawing-oh-drawing-fontconfiginfo.md)* drawFontCfgInfo | 指向系统字体配置信息[OH_Drawing_FontConfigInfo](capi-drawing-oh-drawing-fontconfiginfo.md)的指针，由[OH_Drawing_GetSystemFontConfigInfo](capi-drawing-text-typography-h.md#oh_drawing_getsystemfontconfiginfo)获取。 |

### OH_Drawing_SetTextStyleFontStyleStruct()

```
void OH_Drawing_SetTextStyleFontStyleStruct(OH_Drawing_TextStyle* drawingTextStyle,OH_Drawing_FontStyleStruct fontStyle)
```

**描述**

设置文本样式中的字体样式，包括字体字重、字体宽度和字体斜度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* drawingTextStyle | 指向文本样式对象[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| [OH_Drawing_FontStyleStruct](capi-drawing-oh-drawing-fontstylestruct.md) fontStyle | 字体样式对象，包括字体字重、字体宽度和字体斜度信息。 |

### OH_Drawing_SetTextStyleBadgeType()

```
void OH_Drawing_SetTextStyleBadgeType(OH_Drawing_TextStyle* style, OH_Drawing_TextBadgeType textBadgeType)
```

**描述**

设置文本排版时是否使能上标或下标。未调用此接口时，默认不使能。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 表示指向[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| [OH_Drawing_TextBadgeType](#oh_drawing_textbadgetype) textBadgeType | 设置文本排版时是否使能上标或下标。TEXT_SUPERSCRIPT表示使能上标，TEXT_SUBSCRIPT表示使能下标，默认值为TEXT_BADGE_NONE表示不使能。 |

### OH_Drawing_TextStyleGetFontStyleStruct()

```
OH_Drawing_FontStyleStruct OH_Drawing_TextStyleGetFontStyleStruct(OH_Drawing_TextStyle* drawingTextStyle)
```

**描述**

获取文本样式中的字体样式，包括字体字重、字体宽度和字体斜度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* drawingTextStyle | 指向文本样式对象[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontStyleStruct](capi-drawing-oh-drawing-fontstylestruct.md) | 返回获取到的字体样式对象，包括字体字重、字体宽度和字体斜度信息。 |

### OH_Drawing_SetTypographyStyleFontStyleStruct()

```
void OH_Drawing_SetTypographyStyleFontStyleStruct(OH_Drawing_TypographyStyle* drawingStyle,OH_Drawing_FontStyleStruct fontStyle)
```

**描述**

设置排版样式中默认文本样式的字体样式，包括字体字重、字体宽度和字体斜度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* drawingStyle | 指向排版样式对象[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| [OH_Drawing_FontStyleStruct](capi-drawing-oh-drawing-fontstylestruct.md) fontStyle | 字体样式对象，包括字体字重、字体宽度和字体斜度信息。 |

### OH_Drawing_TypographyStyleGetFontStyleStruct()

```
OH_Drawing_FontStyleStruct OH_Drawing_TypographyStyleGetFontStyleStruct(OH_Drawing_TypographyStyle* drawingStyle)
```

**描述**

获取排版样式中默认文本样式的字体样式，包括字体字重、字体宽度和字体斜度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* drawingStyle | 指向文本风格对象[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontStyleStruct](capi-drawing-oh-drawing-fontstylestruct.md) | 返回获取到的字体样式对象，包括字体字重、字体宽度和字体斜度信息。 |

### OH_Drawing_TextStyleSetBackgroundRect()

```
void OH_Drawing_TextStyleSetBackgroundRect(OH_Drawing_TextStyle* style,const OH_Drawing_RectStyle_Info* rectStyleInfo, int styleId)
```

**描述**

设置文本背景矩形框和样式id。样式id仅当背景框为圆角矩形时有效。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| const [OH_Drawing_RectStyle_Info](capi-drawing-oh-drawing-rectstyle-info.md)* rectStyleInfo | 指向[OH_Drawing_RectStyle_Info](capi-drawing-oh-drawing-rectstyle-info.md)对象的指针。 |
| int styleId | 要设置的样式id，仅当背景框为圆角矩形时有效。文本处理时会被划分为多个分段，每个分段都有自己的TextStyle，id标识着这个分段将被绘制于第几个背景矩形框中。<br>若一行中每个分段的id全为0，表示所有分段绘制在同一个圆角矩形背景框中；若一行中的id为0, 1，则id为0的分段绘制在一个圆角矩形背景框内，id为1的分段绘制在另一个圆角矩形背景框内，以此类推。 |

### OH_Drawing_TypographyHandlerAddSymbol()

```
void OH_Drawing_TypographyHandlerAddSymbol(OH_Drawing_TypographyCreate* handler, uint32_t symbol)
```

**描述**

设置排版创建过程中的符号。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)* handler | 指向[OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)对象的指针，由[OH_Drawing_CreateTypographyHandler](capi-drawing-text-typography-h.md#oh_drawing_createtypographyhandler)获取。 |
| uint32_t symbol | 要设置的符号，可支持设置的符号参见下面链接json文件中的value值。<br>https://gitee.com/openharmony/global_system_resources/blob/master/systemres/main/resources/base/element/symbol.j |

### OH_Drawing_TextStyleAddFontFeature()

```
void OH_Drawing_TextStyleAddFontFeature(OH_Drawing_TextStyle* style, const char* tag, int value)
```

**描述**

设置文本样式中指定字体特征是否启用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| const char* tag | 指向字体特征键值对中关键字所标识的字符串。 |
| int value | 要设置的字体特征键值对的值。 |

### OH_Drawing_TextStyleAddFontVariation()

```
void OH_Drawing_TextStyleAddFontVariation(OH_Drawing_TextStyle* style, const char* axis, const float value)
```

**描述**

添加可变字体属性。对应的字体文件（.ttf文件）需要支持可变调节，此接口才能生效。当对应的字体不支持可变调节时，此接口调用不生效。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| const char* axis | 可变字体属性键值对中的键。目前仅支持'wght'，表示字重属性。 |
| const float value | 设置的可变字体属性键值对的值。目前默认字体下字重属性支持的取值范围为[0,900]。 |

### OH_Drawing_TextStyleGetFontFeatures()

```
OH_Drawing_FontFeature* OH_Drawing_TextStyleGetFontFeatures(OH_Drawing_TextStyle* style)
```

**描述**

获取指定文本样式的字体特征map容器中所有内容。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontFeature](capi-drawing-oh-drawing-fontfeature.md)* | 要获取的字体特征容器的所有内容，指向存放容器所有键值对的一个结构体数组。 |

### OH_Drawing_TextStyleDestroyFontFeatures()

```
void OH_Drawing_TextStyleDestroyFontFeatures(OH_Drawing_FontFeature* fontFeature, size_t fontFeatureSize)
```

**描述**

释放存放字体特征所有内容的结构体数组所占用的空间。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontFeature](capi-drawing-oh-drawing-fontfeature.md)* fontFeature | 指向存放容器所有键值对的结构体数组指针，由[OH_Drawing_TextStyleGetFontFeatures](capi-drawing-text-typography-h.md#oh_drawing_textstylegetfontfeatures)获取。 |
| size_t fontFeatureSize | 存放容器所有键值对的结构体数组的大小。 |

### OH_Drawing_TextStyleGetFontFeatureSize()

```
size_t OH_Drawing_TextStyleGetFontFeatureSize(OH_Drawing_TextStyle* style)
```

**描述**

获取指定文本样式中字体特征map容器的大小。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| size_t | 字体特征map容器的大小。 |

### OH_Drawing_TextStyleClearFontFeature()

```
void OH_Drawing_TextStyleClearFontFeature(OH_Drawing_TextStyle* style)
```

**描述**

清除指定文本样式的字体特征map容器中所有内容。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

### OH_Drawing_TextStyleGetBaselineShift()

```
double OH_Drawing_TextStyleGetBaselineShift(OH_Drawing_TextStyle* style)
```

**描述**

获取指定文本样式的基线偏移。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 基线偏移的值。 |

### OH_Drawing_TextStyleSetBaselineShift()

```
void OH_Drawing_TextStyleSetBaselineShift(OH_Drawing_TextStyle* style, double lineShift)
```

**描述**

设置文本样式基线偏移。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| double lineShift | 文本的基线偏移。 |

### OH_Drawing_TypographyTextSetHeightBehavior()

```
void OH_Drawing_TypographyTextSetHeightBehavior(OH_Drawing_TypographyStyle* style,OH_Drawing_TextHeightBehavior heightMode)
```

**描述**

设置文本高度修饰符模式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向排版样式[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| [OH_Drawing_TextHeightBehavior](#oh_drawing_textheightbehavior) heightMode | 文本高度修饰符模式，为[OH_Drawing_TextHeightBehavior](capi-drawing-text-typography-h.md#oh_drawing_textheightbehavior)类型的枚举值。 |

### OH_Drawing_TypographyTextGetHeightBehavior()

```
OH_Drawing_TextHeightBehavior OH_Drawing_TypographyTextGetHeightBehavior(OH_Drawing_TypographyStyle* style)
```

**描述**

获取文本高度修饰符模式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向排版样式[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TextHeightBehavior](#oh_drawing_textheightbehavior) | 返回文本高度修饰符模式，为[OH_Drawing_TextHeightBehavior](capi-drawing-text-typography-h.md#oh_drawing_textheightbehavior)类型的枚举值。 |

### OH_Drawing_TypographyGetLineFontMetrics()

```
OH_Drawing_Font_Metrics* OH_Drawing_TypographyGetLineFontMetrics(OH_Drawing_Typography* typography,size_t lineNumber, size_t* fontMetricsSize)
```

**描述**

从排版对象中目标行获取所有字体度量信息，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用，否则会返回空指针。不再需要[OH_Drawing_Font_Metrics](capi-drawing-oh-drawing-font-metrics.md)时，请使用[OH_Drawing_TypographyDestroyLineFontMetrics](capi-drawing-text-typography-h.md#oh_drawing_typographydestroylinefontmetrics)接口释放该对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 指向文本对象[OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |
| size_t lineNumber | 指定行数，取值为整数，最小有效值为1，最大行取决于文本输入后字体引擎解析出来的行数，若输入值大于最大行会返回错误值并打印错误消息。 |
| size_t* fontMetricsSize | 指示从当前行返回的字体度量结构的大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Font_Metrics](capi-drawing-oh-drawing-font-metrics.md)* | 返回当前行的所有字体度量信息。 |

### OH_Drawing_TypographyDestroyLineFontMetrics()

```
void OH_Drawing_TypographyDestroyLineFontMetrics(OH_Drawing_Font_Metrics* lineFontMetric)
```

**描述**

释放指定行所有字体度量结构体集合所占用的所有空间。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Font_Metrics](capi-drawing-oh-drawing-font-metrics.md)* lineFontMetric | 指示要释放空间的指定行所有字体度量结构体集合的第一个地址。 |

### OH_Drawing_TextStyleIsEqual()

```
bool OH_Drawing_TextStyleIsEqual(const OH_Drawing_TextStyle* style, const OH_Drawing_TextStyle* comparedStyle)
```

**描述**

判断两个文本样式对象是否相等，字宽属性不参与对比。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 比较的文本样式对象。 |
| const [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* comparedStyle | 比较的文本样式对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回两个文本样式对象是否相等。true表示相等，false表示不相等。 |

### OH_Drawing_TextStyleIsEqualByFont()

```
bool OH_Drawing_TextStyleIsEqualByFont(const OH_Drawing_TextStyle* style, const OH_Drawing_TextStyle* comparedStyle)
```

**描述**

判断两个文本样式对象的字体样式属性是否相等。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 比较的文本样式对象。 |
| const [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* comparedStyle | 比较的文本样式对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回两个文本样式对象的字体样式属性是否相等的结果。 |

### OH_Drawing_TextStyleIsAttributeMatched()

```
bool OH_Drawing_TextStyleIsAttributeMatched(const OH_Drawing_TextStyle* style,const OH_Drawing_TextStyle* comparedStyle, OH_Drawing_TextStyleType textStyleType)
```

**描述**

判断两个文本样式对象是否有一样的字体样式类型。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 比较的文本样式对象。 |
| const [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* comparedStyle | 比较的文本样式对象。 |
| [OH_Drawing_TextStyleType](#oh_drawing_textstyletype) textStyleType | 文本样式类型枚举[OH_Drawing_TextStyleType](capi-drawing-text-typography-h.md#oh_drawing_textstyletype)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回两个TextStyle对象是否有对应的文本样式类型一样的结果。true表示其文本样式类型一样，false表示不一样。 |

### OH_Drawing_TextStyleSetPlaceholder()

```
void OH_Drawing_TextStyleSetPlaceholder(OH_Drawing_TextStyle* style)
```

**描述**

设置占位符。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式对象[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

### OH_Drawing_TextStyleIsPlaceholder()

```
bool OH_Drawing_TextStyleIsPlaceholder(OH_Drawing_TextStyle* style)
```

**描述**

返回是否有设置文本占位符。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式对象[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回是否有设置文本占位符。true表示有设置文本占位符，false表示未设置文本占位符。 |

### OH_Drawing_TypographyStyleGetEffectiveAlignment()

```
OH_Drawing_TextAlign OH_Drawing_TypographyStyleGetEffectiveAlignment(OH_Drawing_TypographyStyle* style)
```

**描述**

获取文本对齐模式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向排版样式[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TextAlign](#oh_drawing_textalign) | 返回文本对齐模式的枚举值[OH_Drawing_TextAlign](capi-drawing-text-typography-h.md#oh_drawing_textalign)。 |

### OH_Drawing_TypographyStyleIsHintEnabled()

```
bool OH_Drawing_TypographyStyleIsHintEnabled(OH_Drawing_TypographyStyle* style)
```

**描述**

获取文本是否启用字形轮廓自动调整，字形轮廓自动调整用于在渲染小字号文本时改善其可读性和外观。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向文本风格对象[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回文本是否启用字体提示。true表示启用，false表示不启用。 |

### OH_Drawing_SetTypographyStyleTextStrutStyle()

```
void OH_Drawing_SetTypographyStyleTextStrutStyle(OH_Drawing_TypographyStyle* style, OH_Drawing_StrutStyle* strutstyle)
```

**描述**

设置文本支柱样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向文本风格对象[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| [OH_Drawing_StrutStyle](capi-drawing-oh-drawing-strutstyle.md)* strutstyle | 指向支柱样式对象[OH_Drawing_StrutStyle](capi-drawing-oh-drawing-strutstyle.md)的指针，由[OH_Drawing_TypographyStyleGetStrutStyle](capi-drawing-text-typography-h.md#oh_drawing_typographystylegetstrutstyle)获取。 |

### OH_Drawing_TypographyStyleGetStrutStyle()

```
OH_Drawing_StrutStyle* OH_Drawing_TypographyStyleGetStrutStyle(OH_Drawing_TypographyStyle* style)
```

**描述**

获取文本支柱样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向文本风格对象[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_StrutStyle](capi-drawing-oh-drawing-strutstyle.md)* | 返回指向支柱样式对象[OH_Drawing_StrutStyle](capi-drawing-oh-drawing-strutstyle.md)的指针。 |

### OH_Drawing_TypographyStyleDestroyStrutStyle()

```
void OH_Drawing_TypographyStyleDestroyStrutStyle(OH_Drawing_StrutStyle* strutstyle)
```

**描述**

释放被支柱样式对象占据的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_StrutStyle](capi-drawing-oh-drawing-strutstyle.md)* strutstyle | 指向支柱样式对象[OH_Drawing_StrutStyle](capi-drawing-oh-drawing-strutstyle.md)的指针，由[OH_Drawing_TypographyStyleGetStrutStyle](capi-drawing-text-typography-h.md#oh_drawing_typographystylegetstrutstyle)获取。 |

### OH_Drawing_TypographyStyleStrutStyleEquals()

```
bool OH_Drawing_TypographyStyleStrutStyleEquals(OH_Drawing_StrutStyle* from, OH_Drawing_StrutStyle* to)
```

**描述**

判断支柱样式结构体是否相同。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_StrutStyle](capi-drawing-oh-drawing-strutstyle.md)* from | 被比较的支柱样式结构体。 |
| [OH_Drawing_StrutStyle](capi-drawing-oh-drawing-strutstyle.md)* to | 用于比较的支柱样式结构体。 |

### OH_Drawing_TypographyStyleSetHintsEnabled()

```
void OH_Drawing_TypographyStyleSetHintsEnabled(OH_Drawing_TypographyStyle* style, bool hintsEnabled)
```

**描述**

设置文本是否启用字形轮廓自动调整，字形轮廓自动调整用于在渲染小字号文本时改善其可读性和外观。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向文本风格对象[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| bool hintsEnabled | 是否启用字体提示。true表示启用，false表示不启用。 |

### OH_Drawing_TypographyMarkDirty()

```
void  OH_Drawing_TypographyMarkDirty(OH_Drawing_Typography* typography)
```

**描述**

将排版标记为脏数据，用于初始化排版状态。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 表示指向文本[OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)对象的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |

### OH_Drawing_TypographyGetUnresolvedGlyphsCount()

```
int32_t OH_Drawing_TypographyGetUnresolvedGlyphsCount(OH_Drawing_Typography* typography)
```

**描述**

获取文本中尚未解析的字形的数量，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用并生效之后调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 表示指向文本[OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)对象的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回文本中尚未解析的字形的数量。 |

### OH_Drawing_TypographyUpdateFontSize()

```
void OH_Drawing_TypographyUpdateFontSize(OH_Drawing_Typography* typography, size_t from, size_t to, float fontSize)
```

**描述**

更新排版对象中的字体大小。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 表示指向排版对象[OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |
| size_t from | 保留字段，暂未使用。 |
| size_t to | 保留字段，暂未使用。 |
| float fontSize | 表示更新后的字体大小。 |

### OH_Drawing_TypographyUpdateFontColor()

```
void OH_Drawing_TypographyUpdateFontColor(OH_Drawing_Typography* typography, uint32_t color)
```

**描述**

更新排版对象中的字体颜色。如果当前装饰线未设置颜色，使用该接口也会同时更新装饰线的颜色。使用该接口更新字体颜色属性后，可直接使用[OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint)进行绘制生效。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 表示指向排版对象[OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |
| uint32_t color | 表示更新后的字体颜色。 |

### OH_Drawing_TypographyUpdateDecoration()

```
void OH_Drawing_TypographyUpdateDecoration(OH_Drawing_Typography* typography, OH_Drawing_TextDecoration decoration)
```

**描述**

更新排版对象中的文本装饰线类型。使用该接口更新文本装饰线类型属性后，可直接使用[OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint)进行绘制生效。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 表示指向排版对象[OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |
| [OH_Drawing_TextDecoration](#oh_drawing_textdecoration) decoration | 表示更新后的装饰线类型，具体可见[OH_Drawing_TextDecoration](capi-drawing-text-typography-h.md#oh_drawing_textdecoration)枚举。可通过位或操作一次设置多种装饰线类型。设置非[OH_Drawing_TextDecoration](capi-drawing-text-typography-h.md#oh_drawing_textdecoration)枚举的装饰样式则保持原有装饰线类型。 |

### OH_Drawing_TypographyUpdateDecorationThicknessScale()

```
void OH_Drawing_TypographyUpdateDecorationThicknessScale(OH_Drawing_Typography* typography,double decorationThicknessScale)
```

**描述**

更新排版对象中的文本装饰线的粗细缩放比例。使用该接口更新文本装饰线粗细缩放比例属性后，可直接使用[OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint)进行绘制生效。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 表示指向排版对象[OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |
| double decorationThicknessScale | 表示更新后的文本装饰线的粗细缩放比例。装饰线的粗细会随着这个比例变大而变粗，如果更新的粗细缩放比例小于等于0，那么就不会绘制装饰线。 |

### OH_Drawing_TypographyUpdateDecorationStyle()

```
void OH_Drawing_TypographyUpdateDecorationStyle(OH_Drawing_Typography* typography,OH_Drawing_TextDecorationStyle decorationStyle)
```

**描述**

更新排版对象中的文本装饰线样式。使用该接口更新文本装饰线样式属性后，可直接使用[OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint)进行绘制生效。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 表示指向排版对象[OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |
| [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle) decorationStyle | 表示更新后的文本装饰线样式，支持可选的装饰样式具体可见[OH_Drawing_TextDecorationStyle](capi-drawing-text-typography-h.md#oh_drawing_textdecorationstyle)枚举。 |

### OH_Drawing_TypographyTextGetLineStyle()

```
bool OH_Drawing_TypographyTextGetLineStyle(OH_Drawing_TypographyStyle* style)
```

**描述**

获取文本排版是否启用行样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 表示指向[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)对象的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回行样式是否启用的结果。true表示启用，false表示不启用。 |

### OH_Drawing_TypographyTextlineStyleGetFontWeight()

```
OH_Drawing_FontWeight OH_Drawing_TypographyTextlineStyleGetFontWeight(OH_Drawing_TypographyStyle* style)
```

**描述**

获取文本排版行样式字重。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 表示指向[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)对象的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontWeight](#oh_drawing_fontweight) | 返回文本排版行样式字重。<br> 0字重为thin，1字重为extra-light，2字重为light，4字重为medium，5字重为semi-bold，6字重为bold，7字重为extra-bold，8字重为black，3或其它字重为normal/regular，具体可见[OH_Drawing_FontWeight](capi-drawing-text-typography-h.md#oh_drawing_fontweight)枚举。 |

### OH_Drawing_TypographyTextlineStyleGetFontStyle()

```
OH_Drawing_FontStyle OH_Drawing_TypographyTextlineStyleGetFontStyle(OH_Drawing_TypographyStyle* style)
```

**描述**

获取文本排版样式中支柱样式的字体样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 表示指向[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)对象的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontStyle](#oh_drawing_fontstyle) | 返回文本排版样式中支柱样式的字体样式。1为斜体，0或其它为非斜体，具体可见[OH_Drawing_FontStyle](capi-drawing-text-typography-h.md#oh_drawing_fontstyle)枚举。 |

### OH_Drawing_TypographyTextlineStyleGetFontFamilies()

```
char** OH_Drawing_TypographyTextlineStyleGetFontFamilies(OH_Drawing_TypographyStyle* style, size_t* num)
```

**描述**

获取文本排版行样式字体家族名。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 表示指向[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)对象的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| size_t* num | 指向字体名称数量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| char** | 返回文本排版行样式字体家族名。 |

### OH_Drawing_TypographyTextlineStyleDestroyFontFamilies()

```
void OH_Drawing_TypographyTextlineStyleDestroyFontFamilies(char** fontFamilies, size_t fontFamiliesNum)
```

**描述**

释放字体类型占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| char** fontFamilies | 表示指向字体字体类型的指针。 |
| size_t fontFamiliesNum | 字体名称的数量。 |

### OH_Drawing_TypographyTextlineStyleGetFontSize()

```
double OH_Drawing_TypographyTextlineStyleGetFontSize(OH_Drawing_TypographyStyle* style)
```

**描述**

获取文本排版行样式字号。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 表示指向[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)对象的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 返回文本排版行样式字号。 |

### OH_Drawing_TypographyTextlineStyleGetHeightScale()

```
double OH_Drawing_TypographyTextlineStyleGetHeightScale(OH_Drawing_TypographyStyle* style)
```

**描述**

获取文本排版行样式的行高缩放系数。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 表示指向[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)对象的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 返回文本排版行样式的行高缩放系数。 |

### OH_Drawing_TypographyTextlineStyleGetHeightOnly()

```
bool OH_Drawing_TypographyTextlineStyleGetHeightOnly(OH_Drawing_TypographyStyle* style)
```

**描述**

获取字体渲染过程中计算字体块高度相关参数的方法。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 表示指向[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)对象的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回计算字体块高度相关参数的方法。true表示以字号为准计算，false表示以行距计算。 |

### OH_Drawing_TypographyTextlineStyleGetHalfLeading()

```
bool OH_Drawing_TypographyTextlineStyleGetHalfLeading(OH_Drawing_TypographyStyle* style)
```

**描述**

获取文本排版行样式是否为一半行间距。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 表示指向[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)对象的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 文本排版行样式是否为一半行间距，true表示是一半行间距，false表示不是。 |

### OH_Drawing_TypographyTextlineStyleGetSpacingScale()

```
double OH_Drawing_TypographyTextlineStyleGetSpacingScale(OH_Drawing_TypographyStyle* style)
```

**描述**

获取文本排版行样式间距比例。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 表示指向[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)对象的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 返回文本排版行样式间距比例。 |

### OH_Drawing_TypographyTextlineGetStyleOnly()

```
bool OH_Drawing_TypographyTextlineGetStyleOnly(OH_Drawing_TypographyStyle* style)
```

**描述**

获取文本排版是否仅启用行样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 表示指向[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)对象的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回文本排版是否仅启用行样式。true表示启用，false表示不启用。 |

### OH_Drawing_TypographyGetTextAlign()

```
OH_Drawing_TextAlign OH_Drawing_TypographyGetTextAlign(OH_Drawing_TypographyStyle* style)
```

**描述**

获取文本对齐方式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 表示指向排版样式[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TextAlign](#oh_drawing_textalign) | 返回文本对齐方式。1为右对齐，2为居中对齐，3为两端对齐，4为与文字方向相同，5为文字方向相反，0或其它为左对齐，具体可见[OH_Drawing_TextAlign](capi-drawing-text-typography-h.md#oh_drawing_textalign)枚举。 |

### OH_Drawing_TypographyGetTextDirection()

```
OH_Drawing_TextDirection OH_Drawing_TypographyGetTextDirection(OH_Drawing_TypographyStyle* style)
```

**描述**

获取指定排版样式中的文本方向。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 表示指向排版样式[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TextDirection](#oh_drawing_textdirection) | 返回文本方向。0为从右到左，1为从左到右，具体可见[OH_Drawing_TextDirection](capi-drawing-text-typography-h.md#oh_drawing_textdirection)枚举。 |

### OH_Drawing_TypographyGetTextMaxLines()

```
size_t OH_Drawing_TypographyGetTextMaxLines(OH_Drawing_TypographyStyle* style)
```

**描述**

获取文本的最大行数。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 表示指向排版样式[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| size_t | 返回结果为文本最大行数。 |

### OH_Drawing_TypographyGetTextEllipsis()

```
char* OH_Drawing_TypographyGetTextEllipsis(OH_Drawing_TypographyStyle* style)
```

**描述**

获取指定排版样式设置的省略号文本。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 表示指向[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)对象的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| char* | 返回设置的省略号文本。 |

### OH_Drawing_TypographyDestroyEllipsis()

```
void OH_Drawing_TypographyDestroyEllipsis(char* ellipsis)
```

**描述**

释放省略号名称列表占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| char* ellipsis | 表示指向省略号名称列表的指针。 |

### OH_Drawing_TypographyStyleEquals()

```
bool OH_Drawing_TypographyStyleEquals(OH_Drawing_TypographyStyle* from, OH_Drawing_TypographyStyle* to)
```

**描述**

判断排版样式是否相同，当前文本高度修饰符模式[OH_Drawing_TextHeightBehavior](capi-drawing-text-typography-h.md#oh_drawing_textheightbehavior)没有被纳入比较。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* from | 被比较的排版样式。 |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* to | 用于比较的排版样式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回排版样式是否相同。true表示相同，false表示不相同。 |

### OH_Drawing_TextStyleGetColor()

```
uint32_t OH_Drawing_TextStyleGetColor(OH_Drawing_TextStyle* style)
```

**描述**

获取文本颜色。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式对象[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 返回文本颜色。 |

### OH_Drawing_TextStyleGetDecorationStyle()

```
OH_Drawing_TextDecorationStyle OH_Drawing_TextStyleGetDecorationStyle(OH_Drawing_TextStyle* style)
```

**描述**

获取文本装饰样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式对象[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle) | 返回文本装饰样式，具体可见[OH_Drawing_TextDecorationStyle](capi-drawing-text-typography-h.md#oh_drawing_textdecorationstyle)枚举。 |

### OH_Drawing_TextStyleGetFontWeight()

```
OH_Drawing_FontWeight OH_Drawing_TextStyleGetFontWeight(OH_Drawing_TextStyle* style)
```

**描述**

获取字重。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式对象[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontWeight](#oh_drawing_fontweight) | 返回字重，具体可见[OH_Drawing_FontWeight](capi-drawing-text-typography-h.md#oh_drawing_fontweight)枚举。 |

### OH_Drawing_TextStyleGetFontStyle()

```
OH_Drawing_FontStyle OH_Drawing_TextStyleGetFontStyle(OH_Drawing_TextStyle* style)
```

**描述**

获取指定文本样式的字体样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向字体样式对象[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontStyle](#oh_drawing_fontstyle) | 返回字体样式，具体可见[OH_Drawing_FontStyle](capi-drawing-text-typography-h.md#oh_drawing_fontstyle)枚举。 |

### OH_Drawing_TextStyleGetBaseline()

```
OH_Drawing_TextBaseline OH_Drawing_TextStyleGetBaseline(OH_Drawing_TextStyle* style)
```

**描述**

获取指定文本样式的字体基线位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式对象[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TextBaseline](#oh_drawing_textbaseline) | 返回字体基线位置，具体可见[OH_Drawing_TextBaseline](capi-drawing-text-typography-h.md#oh_drawing_textbaseline)枚举。 |

### OH_Drawing_TextStyleGetFontFamilies()

```
char** OH_Drawing_TextStyleGetFontFamilies(OH_Drawing_TextStyle* style, size_t* num)
```

**描述**

获取字体类型名称列表。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式对象[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |
| size_t* num | 指向字体名称数量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| char** | 返回获取到的字体类型列表。 |

### OH_Drawing_TextStyleDestroyFontFamilies()

```
void OH_Drawing_TextStyleDestroyFontFamilies(char** fontFamilies, size_t num)
```

**描述**

释放长度为num的字体家族名称列表占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| char** fontFamilies | 指向字体家族名称列表的指针。 |
| size_t num | 字体家族名称列表的长度。 |

### OH_Drawing_TextStyleGetFontSize()

```
double OH_Drawing_TextStyleGetFontSize(OH_Drawing_TextStyle* style)
```

**描述**

获取指定文本样式字号。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式对象[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 返回字号。 |

### OH_Drawing_TextStyleGetLetterSpacing()

```
double OH_Drawing_TextStyleGetLetterSpacing(OH_Drawing_TextStyle* style)
```

**描述**

获取指定文本样式的字符间距。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式对象[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 返回字符间距大小。 |

### OH_Drawing_TextStyleGetWordSpacing()

```
double OH_Drawing_TextStyleGetWordSpacing(OH_Drawing_TextStyle* style)
```

**描述**

获取指定文本样式的单词间距。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式对象[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 返回单词间距大小。 |

### OH_Drawing_TextStyleGetFontHeight()

```
double OH_Drawing_TextStyleGetFontHeight(OH_Drawing_TextStyle* style)
```

**描述**

获取指定文本样式行高缩放系数。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式对象[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 返回行高缩放系数。 |

### OH_Drawing_TextStyleGetHalfLeading()

```
bool OH_Drawing_TextStyleGetHalfLeading(OH_Drawing_TextStyle* style)
```

**描述**

获取指定文本样式一半行间距开关状态。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式对象[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| bool | 返回当前文本样式一半行间距的开关状态。true表示开启一半行间距，false表示未开启一半行间距。 |

### OH_Drawing_TextStyleGetLocale()

```
const char* OH_Drawing_TextStyleGetLocale(OH_Drawing_TextStyle* style)
```

**描述**

获取语言环境。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向文本样式对象[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针，由[OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 返回语言环境，数据类型为指向char对象的指针。语言环境格式为：语言-国家。如zh-CN表示中文（中国），en-US表示英语（美国）等。具体参考BCP 47语言标签标准。 |

### OH_Drawing_TypographyDestroyTextBox()

```
void OH_Drawing_TypographyDestroyTextBox(OH_Drawing_TextBox* textBox)
```

**描述**

释放文本框占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)* textBox | 指向文本框对象[OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)的指针。 |

### OH_Drawing_SetTextShadow()

```
void OH_Drawing_SetTextShadow(OH_Drawing_TextShadow* shadow, uint32_t color, OH_Drawing_Point* offset,double blurRadius)
```

**描述**

设置字体阴影对象的参数。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)* shadow | 指向字体阴影对象[OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)的指针，由[OH_Drawing_CreateTextShadow](capi-drawing-text-typography-h.md#oh_drawing_createtextshadow)获取。 |
| uint32_t color | 字体阴影的颜色，例如入参为0xAABBCCDD，AA代表透明度，BB代表红色分量的值，CC代表绿色分量的值，DD代表蓝色分量的值。 |
| [OH_Drawing_Point](capi-drawing-oh-drawing-point.md)* offset | 指向坐标点对象[OH_Drawing_Point](capi-drawing-oh-drawing-point.md)的指针，字体阴影基于当前文本的偏移位置。 |
| double blurRadius | 模糊半径，浮点数，没有单位，值为0.0时表示没有模糊效果。 |

### OH_Drawing_CreateTextTab()

```
OH_Drawing_TextTab* OH_Drawing_CreateTextTab(OH_Drawing_TextAlign alignment, float location)
```

**描述**

创建文本制表符对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextAlign](#oh_drawing_textalign) alignment | 制表符之后的文本对齐方式。1为右对齐，2为居中对齐，0或其它为左对齐。 |
| float location | 文本制表符之后的文本对齐的位置，相对于当前文本起始位置的偏移。单位为物理像素px，最小值为1.0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TextTab](capi-drawing-oh-drawing-texttab.md)* | 返回指向文本制表符对象的指针。如果返回空指针，表示创建失败。失败的原因可能为没有可用的内存。 |

### OH_Drawing_DestroyTextTab()

```
void OH_Drawing_DestroyTextTab(OH_Drawing_TextTab* tab)
```

**描述**

释放文本制表符对象占据的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextTab](capi-drawing-oh-drawing-texttab.md)* tab | 指向文本制表符对象的指针。 |

### OH_Drawing_GetTextTabAlignment()

```
OH_Drawing_TextAlign OH_Drawing_GetTextTabAlignment(OH_Drawing_TextTab* tab)
```

**描述**

获取文本制表符对象的对齐方式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextTab](capi-drawing-oh-drawing-texttab.md)* tab | 指向文本制表符对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TextAlign](#oh_drawing_textalign) | 返回文本对齐方式。1为右对齐，2为居中对齐，0或其它为左对齐。 |

### OH_Drawing_GetTextTabLocation()

```
float OH_Drawing_GetTextTabLocation(OH_Drawing_TextTab* tab)
```

**描述**

获取文本制表符的位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextTab](capi-drawing-oh-drawing-texttab.md)* tab | 指向文本制表符对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回文本制表符对象的位置。 |

### OH_Drawing_SetTypographyTextTab()

```
void OH_Drawing_SetTypographyTextTab(OH_Drawing_TypographyStyle* style, OH_Drawing_TextTab* tab)
```

**描述**

设置文本制表符对齐方式及位置。当设置了文本对齐方式或者省略号风格时制表符不生效，当制表符位置小于1.0时为替换成空格的效果。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向文本风格对象[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针。 |
| [OH_Drawing_TextTab](capi-drawing-oh-drawing-texttab.md)* tab | 指向文本制表符对象的指针。 |

### OH_Drawing_GetDrawingArraySize()

```
size_t OH_Drawing_GetDrawingArraySize(OH_Drawing_Array* drawingArray)
```

**描述**

获取传入类型为对象数组[OH_Drawing_Array](capi-drawing-oh-drawing-array.md)中的对象个数。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Array](capi-drawing-oh-drawing-array.md)* drawingArray | 指向对象数组[OH_Drawing_Array](capi-drawing-oh-drawing-array.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| size_t | 数组中的对象个数。 |

### OH_Drawing_SetTypographyTextTrailingSpaceOptimized()

```
void OH_Drawing_SetTypographyTextTrailingSpaceOptimized(OH_Drawing_TypographyStyle* style, bool trailingSpaceOptimized)
```

**描述**

设置文本排版时行尾空格是否参与对齐计算。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) |  指向文本风格对象[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针。 |
| bool |  设置文本排版时行尾空格是否参与对齐计算。true表示行尾空格不参与计算，false表示行尾空格参与计算，默认值为false。文本居中对齐场景下推荐设置为true。 |

### OH_Drawing_TypographyHandlerAddEncodedText()

```
void OH_Drawing_TypographyHandlerAddEncodedText(OH_Drawing_TypographyCreate* handler, const void* text,size_t byteLength, OH_Drawing_TextEncoding textEncodingType)
```

**描述**

添加指定编码的文本。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)* handler | 指向[OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)对象的指针，由[OH_Drawing_CreateTypographyHandler](capi-drawing-text-typography-h.md#oh_drawing_createtypographyhandler)获取。 |
| const void* text | 指向文本内容的指针。 |
| size_t byteLength | 文本的字节长度。 |
| [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding) textEncodingType | 文本的编码类型，为[OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding)类型的枚举值。只支持TEXT_ENCODING_UTF8, TEXT_ENCODING_UTF16, TEXT_ENCODING_UTF32。 |

### OH_Drawing_SetTypographyTextAutoSpace()

```
void OH_Drawing_SetTypographyTextAutoSpace(OH_Drawing_TypographyStyle *style, bool enableAutoSpace)
```

**描述**

设置文本排版时是否使能自动间距。<br>默认不使能自动间距，一旦使能则会自动调整CJK（中文字符、日文字符、韩文字符）与西文（拉丁字母、西里尔字母、希腊字母）、CJK与数字、CJK与版权符号、版权符号与数字、版权符号与西文之间的间距。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) *style | 表示指向[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)对象的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| bool enableAutoSpace | 设置文本排版时是否使能自动间距。true表示使能自动间距，false表示不使能自动间距，默认值为false。 |

### OH_Drawing_TypographyUpdateDecorationColor()

```
void OH_Drawing_TypographyUpdateDecorationColor(OH_Drawing_Typography* typography, uint32_t color)
```

**描述**

更新排版对象中的文本装饰线颜色。<br> 使用该接口更新文本装饰线颜色属性后，可直接使用[OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint)进行绘制生效。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | 表示指向排版对象[OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)的指针，由[OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography)获取。 |
| uint32_t color | 表示更新后的文本装饰线颜色。 |

### OH_Drawing_SetTypographyVerticalAlignment()

```
void OH_Drawing_SetTypographyVerticalAlignment(OH_Drawing_TypographyStyle* style,OH_Drawing_TextVerticalAlignment align)
```

**描述**

设置文本垂直对齐方式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 表示指向[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)对象的指针，由[OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| [OH_Drawing_TextVerticalAlignment](capi-drawing-text-typography-h.md#oh_drawing_textverticalalignment) align | 设置文本垂直对齐方式。默认为基线对齐，其余对齐方式见[OH_Drawing_TextVerticalAlignment](capi-drawing-text-typography-h.md#oh_drawing_textverticalalignment)。 |

### OH_Drawing_CopyTypographyStyle()

```
OH_Drawing_TypographyStyle* OH_Drawing_CopyTypographyStyle(OH_Drawing_TypographyStyle* style)
```

**描述**

创建一个段落样式的对象副本，用于拷贝一个已有的段落样式对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | 指向被拷贝对象[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* | 返回拷贝的[OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)对象指针。如果返回空指针，表示创建失败；可能的原因是无可用内存，或者style为空指针。不再需要时，请使用[OH_Drawing_DestroyTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_destroytypographystyle)释放该对象指针。 |

### OH_Drawing_CopyTextStyle()

```
OH_Drawing_TextStyle* OH_Drawing_CopyTextStyle(OH_Drawing_TextStyle* style)
```

**描述**

创建一个文本样式的对象副本，用于拷贝一个已有的文本样式对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | 指向被拷贝对象[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* | 返回拷贝的[OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)对象指针。如果返回空指针，表示创建失败；可能的原因是无可用内存，或者style为空指针。不再需要时，请使用[OH_Drawing_DestroyTextStyle](capi-drawing-text-typography-h.md#oh_drawing_destroytextstyle)释放该对象指针。 |

### OH_Drawing_CopyTextShadow()

```
OH_Drawing_TextShadow* OH_Drawing_CopyTextShadow(OH_Drawing_TextShadow* shadow)
```

**描述**

创建一个文本阴影的对象副本，用于拷贝一个已有的文本阴影对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)* shadow | 指向被拷贝对象[OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)* | 返回拷贝的[OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)对象指针。如果返回空指针，表示创建失败；可能的原因是无可用内存，或者shadow为空指针。不再需要时，请使用[OH_Drawing_DestroyTextShadow](capi-drawing-text-typography-h.md#oh_drawing_destroytextshadow)释放该对象指针。 |