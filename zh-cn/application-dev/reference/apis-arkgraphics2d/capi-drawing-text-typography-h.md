# drawing_text_typography.h

## 概述

定义绘制模块中排版相关的函数。

**引用文件：** drawing_text_typography.h

**库：** libnative_drawing.so

**起始版本：** 8

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_PlaceholderSpan](capi-oh-drawing-placeholderspan.md) | OH_Drawing_PlaceholderSpan | 用于描述占位符跨度的结构体。 |
| [OH_Drawing_FontDescriptor](capi-oh-drawing-fontdescriptor.md) | OH_Drawing_FontDescriptor | 描述系统字体详细信息的结构体。 |
| [OH_Drawing_LineMetrics](capi-oh-drawing-linemetrics.md) | OH_Drawing_LineMetrics | 文字行位置信息。 |
| [OH_Drawing_FontFallbackInfo](capi-oh-drawing-fontfallbackinfo.md) | OH_Drawing_FontFallbackInfo | 备用字体信息结构体。 |
| [OH_Drawing_FontFallbackGroup](capi-oh-drawing-fontfallbackgroup.md) | OH_Drawing_FontFallbackGroup | 备用字体集信息结构体。 |
| [OH_Drawing_FontAdjustInfo](capi-oh-drawing-fontadjustinfo.md) | OH_Drawing_FontAdjustInfo | 字重映射信息结构体。 |
| [OH_Drawing_FontAliasInfo](capi-oh-drawing-fontaliasinfo.md) | OH_Drawing_FontAliasInfo | 别名字体信息结构体。 |
| [OH_Drawing_FontGenericInfo](capi-oh-drawing-fontgenericinfo.md) | OH_Drawing_FontGenericInfo | 系统所支持的通用字体集信息结构体。 |
| [OH_Drawing_FontConfigInfo](capi-oh-drawing-fontconfiginfo.md) | OH_Drawing_FontConfigInfo | 系统字体配置信息结构体。 |
| [OH_Drawing_FontStyleStruct](capi-oh-drawing-fontstylestruct.md) | OH_Drawing_FontStyleStruct | 定义字体样式信息的结构体。 |
| [OH_Drawing_FontFeature](capi-oh-drawing-fontfeature.md) | OH_Drawing_FontFeature | 描述文本字体特征结构体。 |
| [OH_Drawing_StrutStyle](capi-oh-drawing-strutstyle.md) | OH_Drawing_StrutStyle | 用于描述支柱样式的结构体。支柱样式用于控制绘制文本时行之间的间距、基线对齐方式以及其他与行高相关的属性。 |

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

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_TypographyStyle* OH_Drawing_CreateTypographyStyle(void)](#oh_drawing_createtypographystyle) | 创建指向OH_Drawing_TypographyStyle对象的指针。不再需要[OH_Drawing_TypographyStyle](capi-oh-drawing-typographystyle.md)时，请使用[OH_Drawing_DestroyTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_destroytypographystyle)接口释放该对象的指针。 |
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
| [void OH_Drawing_SetTextStyleDecorationColor(OH_Drawing_TextStyle* style, uint32_t color)](#oh_drawing_settextstyledecorationcolor) | 设置指定文本样式中的装饰线颜色。 |
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
| [OH_Drawing_TypographyCreate* OH_Drawing_CreateTypographyHandler(OH_Drawing_TypographyStyle* style,OH_Drawing_FontCollection* fontCollection)](#oh_drawing_createtypographyhandler) | 创建指向OH_Drawing_TypographyCreate对象的指针。不再需要[OH_Drawing_TypographyCreate](capi-oh-drawing-typographycreate.md)时，请使用[OH_Drawing_DestroyTypographyHandler](capi-drawing-text-typography-h.md#oh_drawing_destroytypographyhandler)接口释放该对象的指针。 |
| [void OH_Drawing_DestroyTypographyHandler(OH_Drawing_TypographyCreate* handler)](#oh_drawing_destroytypographyhandler) | 释放被OH_Drawing_TypographyCreate对象占据的内存。 |
| [void OH_Drawing_TypographyHandlerPushTextStyle(OH_Drawing_TypographyCreate* handler, OH_Drawing_TextStyle* style)](#oh_drawing_typographyhandlerpushtextstyle) | 将指定文本样式压入文本样式栈，后续添加的文本总是会使用栈顶的文本样式。 |
| [void OH_Drawing_TypographyHandlerAddText(OH_Drawing_TypographyCreate* handler, const char* text)](#oh_drawing_typographyhandleraddtext) | 设置文本内容。 |
| [void OH_Drawing_TypographyHandlerPopTextStyle(OH_Drawing_TypographyCreate* handler)](#oh_drawing_typographyhandlerpoptextstyle) | 从文本样式栈中弹出栈顶文本样式。 |
| [OH_Drawing_Typography* OH_Drawing_CreateTypography(OH_Drawing_TypographyCreate* handler)](#oh_drawing_createtypography) | 创建指向OH_Drawing_Typography对象的指针。不再需要[OH_Drawing_Typography](capi-oh-drawing-typography.md)时，请使用[OH_Drawing_DestroyTypography](capi-drawing-text-typography-h.md#oh_drawing_destroytypography)接口释放该对象的指针。 |
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
| [OH_Drawing_TextBox* OH_Drawing_TypographyGetRectsForRange(OH_Drawing_Typography* typography,size_t start, size_t end, OH_Drawing_RectHeightStyle heightStyle, OH_Drawing_RectWidthStyle widthStyle)](#oh_drawing_typographygetrectsforrange) | 获取排版对象中指定范围内的文本框，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。不再需要[OH_Drawing_TextBox](capi-oh-drawing-textbox.md)时，请使用[OH_Drawing_TypographyDestroyTextBox](capi-drawing-text-typography-h.md#oh_drawing_typographydestroytextbox)接口释放该对象的指针。 |
| [OH_Drawing_TextBox* OH_Drawing_TypographyGetRectsForPlaceholders(OH_Drawing_Typography* typography)](#oh_drawing_typographygetrectsforplaceholders) | 获取排版对象中占位符的文本框，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。不再需要[OH_Drawing_TextBox](capi-oh-drawing-textbox.md)时，请使用[OH_Drawing_TypographyDestroyTextBox](capi-drawing-text-typography-h.md#oh_drawing_typographydestroytextbox)接口释放该对象的指针。 |
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
| [void OH_Drawing_SetTextStyleDecorationThicknessScale(OH_Drawing_TextStyle* style, double decorationThicknessScale)](#oh_drawing_settextstyledecorationthicknessscale) | 设置文本装饰线的厚度缩放比例。 |
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
| [OH_Drawing_LineMetrics* OH_Drawing_TypographyGetLineMetrics(OH_Drawing_Typography* typography)](#oh_drawing_typographygetlinemetrics) | 获取排版对象的行位置信息，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。不再需要[OH_Drawing_LineMetrics](capi-oh-drawing-linemetrics.md)时，请使用[OH_Drawing_DestroyLineMetrics](capi-drawing-text-typography-h.md#oh_drawing_destroylinemetrics)接口释放该对象的指针。 |
| [size_t OH_Drawing_LineMetricsGetSize(OH_Drawing_LineMetrics* lineMetrics)](#oh_drawing_linemetricsgetsize) | 获取行数量。 |
| [void OH_Drawing_DestroyLineMetrics(OH_Drawing_LineMetrics* lineMetrics)](#oh_drawing_destroylinemetrics) | 释放行位置信息对象占用的内存。 |
| [bool OH_Drawing_TypographyGetLineMetricsAt(OH_Drawing_Typography* typography,int lineNumber, OH_Drawing_LineMetrics* lineMetric)](#oh_drawing_typographygetlinemetricsat) | 获取排版对象的指定行位置信息，具体参见{@link OH_Drawing_LineMetr}结构体，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用。 |
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
| [OH_Drawing_TextShadow* OH_Drawing_CreateTextShadow(void)](#oh_drawing_createtextshadow) | 创建指向字体阴影对象的指针。不再需要[OH_Drawing_TextShadow](capi-oh-drawing-textshadow.md)时，请使用[OH_Drawing_DestroyTextShadow](capi-drawing-text-typography-h.md#oh_drawing_destroytextshadow)接口释放该对象的指针。 |
| [void OH_Drawing_DestroyTextShadow(OH_Drawing_TextShadow* shadow)](#oh_drawing_destroytextshadow) | 释放被字体阴影对象占据的内存。 |
| [OH_Drawing_TextShadow* OH_Drawing_TextStyleGetShadows(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetshadows) | 获取字体阴影容器。不再需要[OH_Drawing_TextShadow](capi-oh-drawing-textshadow.md)时，请使用[OH_Drawing_DestroyTextShadows](capi-drawing-text-typography-h.md#oh_drawing_destroytextshadows)接口释放该对象的指针。 |
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
| [OH_Drawing_Font_Metrics* OH_Drawing_TypographyGetLineFontMetrics(OH_Drawing_Typography* typography,size_t lineNumber, size_t* fontMetricsSize)](#oh_drawing_typographygetlinefontmetrics) | 从排版对象中目标行获取所有字体度量信息，该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用之后调用，否则会返回空指针。不再需要[OH_Drawing_Font_Metrics](capi-oh-drawing-font-metrics.md)时，请使用[OH_Drawing_TypographyDestroyLineFontMetrics](capi-drawing-text-typography-h.md#oh_drawing_typographydestroylinefontmetrics)接口释放该对象的指针。 |
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
| [void OH_Drawing_TypographyUpdateFontColor(OH_Drawing_Typography* typography, uint32_t color)](#oh_drawing_typographyupdatefontcolor) | 更新排版对象中的字体颜色。该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用后使用。使用该接口更新字体颜色属性后，可直接使用[OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint)进行绘制生效。 |
| [void OH_Drawing_TypographyUpdateDecoration(OH_Drawing_Typography* typography, OH_Drawing_TextDecoration decoration)](#oh_drawing_typographyupdatedecoration) | 更新排版对象中的文本装饰线类型。该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用后使用。使用该接口更新文本装饰线类型属性后，可直接使用[OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint)进行绘制生效。 |
| [void OH_Drawing_TypographyUpdateDecorationThicknessScale(OH_Drawing_Typography* typography,double decorationThicknessScale)](#oh_drawing_typographyupdatedecorationthicknessscale) | 更新排版对象中的文本装饰线的厚度缩放比例。该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用后使用。使用该接口更新文本装饰线厚度缩放比例属性后，可直接使用[OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint)进行绘制生效。 |
| [void OH_Drawing_TypographyUpdateDecorationStyle(OH_Drawing_Typography* typography,OH_Drawing_TextDecorationStyle decorationStyle)](#oh_drawing_typographyupdatedecorationstyle) | 更新排版对象中的文本装饰线样式。该接口需要在[OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout)接口调用后使用。使用该接口更新文本装饰线样式属性后，可直接使用[OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint)进行绘制生效。 |
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
| [size_t OH_Drawing_GetDrawingArraySize(OH_Drawing_Array* drawingArray)](#oh_drawing_getdrawingarraysize) | 获取传入类型为对象数组[OH_Drawing_Array](capi-oh-drawing-array.md)中的对象个数。 |
| [void OH_Drawing_SetTypographyTextTrailingSpaceOptimized(OH_Drawing_TypographyStyle* style, bool trailingSpaceOptimized)](#oh_drawing_settypographytexttrailingspaceoptimized) | 设置文本排版时行尾空格是否参与对齐计算。 |
| [void OH_Drawing_TypographyHandlerAddEncodedText(OH_Drawing_TypographyCreate* handler, const void* text,size_t byteLength, OH_Drawing_TextEncoding textEncodingType)](#oh_drawing_typographyhandleraddencodedtext) | 添加指定编码的文本。 |
| [void OH_Drawing_SetTypographyTextAutoSpace(OH_Drawing_TypographyStyle *style, bool enableAutoSpace)](#oh_drawing_settypographytextautospace) | 设置文本排版时是否使能自动间距。<br>默认不使能自动间距，一旦使能则会自动调整CJK（中文字符、日文字符、韩文字符）与西文（拉丁字母、西里尔字母、希腊字母）、CJK与数字、CJK与版权符号、版权符号与数字、版权符号与西文之间的间距。 |