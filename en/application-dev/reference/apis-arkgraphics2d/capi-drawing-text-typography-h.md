# drawing_text_typography.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @oh_wangxk; @gmiao522; @Lem0nC-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
## Overview

This file declares the functions related to typography in the drawing module.

**File to include**: <native_drawing/drawing_text_typography.h>

**Library**: libnative_drawing.so

**Since**: 8

**Related module**: [Drawing](capi-drawing.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_Drawing_PlaceholderSpan](capi-drawing-oh-drawing-placeholderspan.md) | OH_Drawing_PlaceholderSpan | Describes the placeholder that acts as a span.|
| [OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md) | OH_Drawing_FontDescriptor | Describes the detailed information about a system font.|
| [OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md) | OH_Drawing_LineMetrics | Describes the measurement information about a line of text.|
| [OH_Drawing_FontFallbackInfo](capi-drawing-oh-drawing-fontfallbackinfo.md) | OH_Drawing_FontFallbackInfo | Describes the information about a font fallback.|
| [OH_Drawing_FontFallbackGroup](capi-drawing-oh-drawing-fontfallbackgroup.md) | OH_Drawing_FontFallbackGroup | Describes the information about a font fallback group.|
| [OH_Drawing_FontAdjustInfo](capi-drawing-oh-drawing-fontadjustinfo.md) | OH_Drawing_FontAdjustInfo | Describes the information about a font weight mapping.|
| [OH_Drawing_FontAliasInfo](capi-drawing-oh-drawing-fontaliasinfo.md) | OH_Drawing_FontAliasInfo | Describes the information about a font alias.|
| [OH_Drawing_FontGenericInfo](capi-drawing-oh-drawing-fontgenericinfo.md) | OH_Drawing_FontGenericInfo | Describes the information about generic fonts supported by the system.|
| [OH_Drawing_FontConfigInfo](capi-drawing-oh-drawing-fontconfiginfo.md) | OH_Drawing_FontConfigInfo | Describes the information about a system font configuration.|
| [OH_Drawing_FontStyleStruct](capi-drawing-oh-drawing-fontstylestruct.md) | OH_Drawing_FontStyleStruct | Describes a font style.|
| [OH_Drawing_FontFeature](capi-drawing-oh-drawing-fontfeature.md) | OH_Drawing_FontFeature | Describes a font feature.|
| [OH_Drawing_StrutStyle](capi-drawing-oh-drawing-strutstyle.md) | OH_Drawing_StrutStyle | Describes a strut style. The strut style determines the line spacing, baseline alignment mode, and other properties related to the line height when drawing texts.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_Drawing_TextDirection](#oh_drawing_textdirection) | - | Enumerates the text directions.|
| [OH_Drawing_TextAlign](#oh_drawing_textalign) | - | Enumerates the text alignment modes.|
| [OH_Drawing_FontWeight](#oh_drawing_fontweight) | - | Enumerates the font weights.|
| [OH_Drawing_TextBaseline](#oh_drawing_textbaseline) | - | Enumerates the text baselines.|
| [OH_Drawing_TextDecoration](#oh_drawing_textdecoration) | - | Enumerates the text decorations.|
| [OH_Drawing_FontStyle](#oh_drawing_fontstyle) | - | Enumerates the font styles.|
| [OH_Drawing_PlaceholderVerticalAlignment](#oh_drawing_placeholderverticalalignment) | OH_Drawing_PlaceholderVerticalAlignment | Enumerates the vertical alignment modes of placeholders.|
| [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle) | OH_Drawing_TextDecorationStyle | Enumerates the text decoration styles.|
| [OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal) | OH_Drawing_EllipsisModal | Enumerates the ellipsis styles.|
| [OH_Drawing_BreakStrategy](#oh_drawing_breakstrategy) | OH_Drawing_BreakStrategy | Enumerates the text break strategies.|
| [OH_Drawing_WordBreakType](#oh_drawing_wordbreaktype) | OH_Drawing_WordBreakType | Enumerates the word break types.|
| [OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle) | OH_Drawing_RectHeightStyle | Enumerates the rectangle height styles.|
| [OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle) | OH_Drawing_RectWidthStyle | Enumerates the rectangle width styles.|
| [OH_Drawing_TextBadgeType](#oh_drawing_textbadgetype) | OH_Drawing_TextBadgeType | Enumerates the text badge styles.|
| [OH_Drawing_FontConfigInfoErrorCode](#oh_drawing_fontconfiginfoerrorcode) | - | Enumerates the error codes that may be used during the obtaining of system font configurations.|
| [OH_Drawing_FontWidth](#oh_drawing_fontwidth) | - | Enumerates the font widths.|
| [OH_Drawing_TextHeightBehavior](#oh_drawing_textheightbehavior) | - | Enumerates the text height modifier patterns.|
| [OH_Drawing_TextStyleType](#oh_drawing_textstyletype) | - | Enumerates the text style types.|
| [OH_Drawing_TextVerticalAlignment](#oh_drawing_textverticalalignment) | OH_Drawing_TextVerticalAlignment | Enumerates the vertical alignment modes.|

### Functions

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle* OH_Drawing_CreateTypographyStyle(void)](#oh_drawing_createtypographystyle) | Creates an **OH_Drawing_TypographyStyle** object. Release this pointer by calling [OH_Drawing_DestroyTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_destroytypographystyle) when this object is no longer needed.|
| [void OH_Drawing_DestroyTypographyStyle(OH_Drawing_TypographyStyle* style)](#oh_drawing_destroytypographystyle) | Destroys an **OH_Drawing_TypographyStyle** object and reclaims the memory occupied by the object.|
| [void OH_Drawing_SetTypographyTextDirection(OH_Drawing_TypographyStyle* style, int direction)](#oh_drawing_settypographytextdirection) | Sets the text direction in a typography style.|
| [void OH_Drawing_SetTypographyTextAlign(OH_Drawing_TypographyStyle* style, int align)](#oh_drawing_settypographytextalign) | Sets the text alignment mode.|
| [int OH_Drawing_TypographyGetEffectiveAlignment(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographygeteffectivealignment) | Obtains the text alignment mode.|
| [void OH_Drawing_SetTypographyTextMaxLines(OH_Drawing_TypographyStyle* style, int lineNumber)](#oh_drawing_settypographytextmaxlines) | Sets the maximum number of lines in the text.|
| [OH_Drawing_TextStyle* OH_Drawing_CreateTextStyle(void)](#oh_drawing_createtextstyle) | Creates an **OH_Drawing_TextStyle** object.|
| [OH_Drawing_TextStyle* OH_Drawing_TypographyGetTextStyle(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographygettextstyle) | Obtains the default text style of a typography style.|
| [void OH_Drawing_DestroyTextStyle(OH_Drawing_TextStyle* style)](#oh_drawing_destroytextstyle) | Destroys an **OH_Drawing_TextStyle** object and reclaims the memory occupied by the object.|
| [void OH_Drawing_SetTextStyleColor(OH_Drawing_TextStyle* style, uint32_t color)](#oh_drawing_settextstylecolor) | Sets the color for a text style.|
| [void OH_Drawing_SetTextStyleFontSize(OH_Drawing_TextStyle* style, double fontSize)](#oh_drawing_settextstylefontsize) | Sets the font size for a text style.|
| [void OH_Drawing_SetTextStyleFontWeight(OH_Drawing_TextStyle* style, int fontWeight)](#oh_drawing_settextstylefontweight) | Sets the font weight for a text style. Currently, only the default system font supports font weight adjustment. For other fonts, if the weight is less than semi-bold, there is no variation in stroke thickness. If the weight is greater than or equal to semi-bold, it might result in a fake bold effect.|
| [void OH_Drawing_SetTextStyleBaseLine(OH_Drawing_TextStyle* style, int baseline)](#oh_drawing_settextstylebaseline) | Sets the baseline for a text style.|
| [void OH_Drawing_SetTextStyleDecoration(OH_Drawing_TextStyle* style, int decoration)](#oh_drawing_settextstyledecoration) | Sets the decoration for a text style. Only one decoration can be set. To add multiple decorations, use [OH_Drawing_AddTextStyleDecoration](capi-drawing-text-typography-h.md#oh_drawing_addtextstyledecoration).|
| [void OH_Drawing_AddTextStyleDecoration(OH_Drawing_TextStyle* style, int decoration)](#oh_drawing_addtextstyledecoration) | Adds the decoration for a text style. Multiple decoration lines can be displayed.|
| [void OH_Drawing_RemoveTextStyleDecoration(OH_Drawing_TextStyle* style, int decoration)](#oh_drawing_removetextstyledecoration) | Removes the decoration for a text style.|
| [void OH_Drawing_SetTextStyleDecorationColor(OH_Drawing_TextStyle* style, uint32_t color)](#oh_drawing_settextstyledecorationcolor) | Sets the decoration color for a text style. If this API is not called or **color** is set to **0**, the decoration color follows the text color.|
| [void OH_Drawing_SetTextStyleFontHeight(OH_Drawing_TextStyle* style, double fontHeight)](#oh_drawing_settextstylefontheight) | Sets the line height based on the multiple of the font size.|
| [void OH_Drawing_SetTextStyleFontFamilies(OH_Drawing_TextStyle* style,int fontFamiliesNumber, const char* fontFamilies[])](#oh_drawing_settextstylefontfamilies) | Sets the font families for a text style.|
| [void OH_Drawing_SetTextStyleFontStyle(OH_Drawing_TextStyle* style, int fontStyle)](#oh_drawing_settextstylefontstyle) | Sets the font style for a text style.|
| [void OH_Drawing_SetTextStyleLocale(OH_Drawing_TextStyle* style, const char* locale)](#oh_drawing_settextstylelocale) | Sets the locale for a text style.|
| [void OH_Drawing_SetTextStyleForegroundBrush(OH_Drawing_TextStyle* style, OH_Drawing_Brush* foregroundBrush)](#oh_drawing_settextstyleforegroundbrush) | Sets the foreground brush for a text style.|
| [void OH_Drawing_TextStyleGetForegroundBrush(OH_Drawing_TextStyle* style, OH_Drawing_Brush* foregroundBrush)](#oh_drawing_textstylegetforegroundbrush) | Obtains the foreground brush of a text style.|
| [void OH_Drawing_SetTextStyleForegroundPen(OH_Drawing_TextStyle* style, OH_Drawing_Pen* foregroundPen)](#oh_drawing_settextstyleforegroundpen) | Sets the foreground pen for a text style.|
| [void OH_Drawing_TextStyleGetForegroundPen(OH_Drawing_TextStyle* style, OH_Drawing_Pen* foregroundPen)](#oh_drawing_textstylegetforegroundpen) | Obtains the foreground pen of a text style.|
| [void OH_Drawing_SetTextStyleBackgroundBrush(OH_Drawing_TextStyle* style, OH_Drawing_Brush* backgroundBrush)](#oh_drawing_settextstylebackgroundbrush) | Sets the background brush for a text style.|
| [void OH_Drawing_TextStyleGetBackgroundBrush(OH_Drawing_TextStyle* style, OH_Drawing_Brush* backgroundBrush)](#oh_drawing_textstylegetbackgroundbrush) | Obtains the background brush of a text style.|
| [void OH_Drawing_SetTextStyleBackgroundPen(OH_Drawing_TextStyle* style, OH_Drawing_Pen* backgroundPen)](#oh_drawing_settextstylebackgroundpen) | Sets the background pen for a text style.|
| [void OH_Drawing_TextStyleGetBackgroundPen(OH_Drawing_TextStyle* style, OH_Drawing_Pen* backgroundPen)](#oh_drawing_textstylegetbackgroundpen) | Obtains the background pen of a text style.|
| [OH_Drawing_TypographyCreate* OH_Drawing_CreateTypographyHandler(OH_Drawing_TypographyStyle* style,OH_Drawing_FontCollection* fontCollection)](#oh_drawing_createtypographyhandler) | Creates an **OH_Drawing_TypographyCreate** object. Release this pointer by calling [OH_Drawing_DestroyTypographyHandler](capi-drawing-text-typography-h.md#oh_drawing_destroytypographyhandler) when this object is no longer needed.|
| [void OH_Drawing_DestroyTypographyHandler(OH_Drawing_TypographyCreate* handler)](#oh_drawing_destroytypographyhandler) | Reclaims the memory occupied by an **OH_Drawing_TypographyCreate** object.|
| [void OH_Drawing_TypographyHandlerPushTextStyle(OH_Drawing_TypographyCreate* handler, OH_Drawing_TextStyle* style)](#oh_drawing_typographyhandlerpushtextstyle) | Pushes a text style into the text style stack. Any text added afterward will use the style currently on top of the stack.|
| [void OH_Drawing_TypographyHandlerAddText(OH_Drawing_TypographyCreate* handler, const char* text)](#oh_drawing_typographyhandleraddtext) | Adds text.|
| [void OH_Drawing_TypographyHandlerPopTextStyle(OH_Drawing_TypographyCreate* handler)](#oh_drawing_typographyhandlerpoptextstyle) | Pops the top text style out of the text style stack.|
| [OH_Drawing_Typography* OH_Drawing_CreateTypography(OH_Drawing_TypographyCreate* handler)](#oh_drawing_createtypography) | Creates an **OH_Drawing_Typography** object. Release this pointer by calling [OH_Drawing_DestroyTypography](capi-drawing-text-typography-h.md#oh_drawing_destroytypography) when this object is no longer needed.|
| [void OH_Drawing_DestroyTypography(OH_Drawing_Typography* typography)](#oh_drawing_destroytypography) | Destroys an **OH_Drawing_Typography** object and reclaims the memory occupied by the object.|
| [void OH_Drawing_TypographyLayout(OH_Drawing_Typography* typography, double maxWidth)](#oh_drawing_typographylayout) | Lays out the typography.|
| [void OH_Drawing_TypographyPaint(OH_Drawing_Typography* typography, OH_Drawing_Canvas* canvas,double positionX, double positionY)](#oh_drawing_typographypaint) | Draws text from the upper left corner at a specified position. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called and applied.|
| [void OH_Drawing_TypographyPaintOnPath(OH_Drawing_Typography* typography, OH_Drawing_Canvas* canvas,OH_Drawing_Path* path, double hOffset, double vOffset)](#oh_drawing_typographypaintonpath) | Draws text along a path. To prevent text overlap caused by the text width exceeding the layout width, you are advised to use [OH_Drawing_SetTypographyTextMaxLines](capi-drawing-text-typography-h.md#oh_drawing_settypographytextmaxlines) to limit the text to a single line.|
| [double OH_Drawing_TypographyGetMaxWidth(OH_Drawing_Typography* typography)](#oh_drawing_typographygetmaxwidth) | Obtains the typography width set by the user. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called.|
| [double OH_Drawing_TypographyGetHeight(OH_Drawing_Typography* typography)](#oh_drawing_typographygetheight) | Obtains the overall height of a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called.|
| [double OH_Drawing_TypographyGetLongestLine(OH_Drawing_Typography* typography)](#oh_drawing_typographygetlongestline) | Obtains the width of the longest line in a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called. You are advised to round up the return value. If the text content is empty, **0.0** is returned.|
| [double OH_Drawing_TypographyGetLongestLineWithIndent(OH_Drawing_Typography* typography)](#oh_drawing_typographygetlongestlinewithindent) | Obtains the width of the longest line of a typography object, including its indentation. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called. You are advised to round up the return value. If the text content is empty, **0.0** is returned.|
| [double OH_Drawing_TypographyGetMinIntrinsicWidth(OH_Drawing_Typography* typography)](#oh_drawing_typographygetminintrinsicwidth) | Obtains the minimum intrinsic width in a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called.|
| [double OH_Drawing_TypographyGetMaxIntrinsicWidth(OH_Drawing_Typography* typography)](#oh_drawing_typographygetmaxintrinsicwidth) | Obtains the maximum intrinsic width in a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called.|
| [double OH_Drawing_TypographyGetAlphabeticBaseline(OH_Drawing_Typography* typography)](#oh_drawing_typographygetalphabeticbaseline) | Obtains the alphabetic baseline in a typography object.|
| [double OH_Drawing_TypographyGetIdeographicBaseline(OH_Drawing_Typography* typography)](#oh_drawing_typographygetideographicbaseline) | Obtains the ideographic baseline in a typography object.|
| [void OH_Drawing_TypographyHandlerAddPlaceholder(OH_Drawing_TypographyCreate* handler,OH_Drawing_PlaceholderSpan* span)](#oh_drawing_typographyhandleraddplaceholder) | Adds a placeholder.|
| [bool OH_Drawing_TypographyDidExceedMaxLines(OH_Drawing_Typography* typography)](#oh_drawing_typographydidexceedmaxlines) | Checks whether the text in the typography object exceeds the line limit. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called. It returns **false** if the line limit is not set using [OH_Drawing_SetTypographyTextMaxLines](capi-drawing-text-typography-h.md#oh_drawing_settypographytextmaxlines).|
| [OH_Drawing_TextBox* OH_Drawing_TypographyGetRectsForRange(OH_Drawing_Typography* typography,size_t start, size_t end, OH_Drawing_RectHeightStyle heightStyle, OH_Drawing_RectWidthStyle widthStyle)](#oh_drawing_typographygetrectsforrange) | Obtains text boxes in a given range of a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called. Release this pointer by calling [OH_Drawing_TypographyDestroyTextBox](capi-drawing-text-typography-h.md#oh_drawing_typographydestroytextbox) when this object is no longer needed.|
| [OH_Drawing_TextBox* OH_Drawing_TypographyGetRectsForPlaceholders(OH_Drawing_Typography* typography)](#oh_drawing_typographygetrectsforplaceholders) | Obtains text boxes for placeholders in a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called. Release this pointer by calling [OH_Drawing_TypographyDestroyTextBox](capi-drawing-text-typography-h.md#oh_drawing_typographydestroytextbox) when this object is no longer needed.|
| [float OH_Drawing_GetLeftFromTextBox(OH_Drawing_TextBox* textbox, int index)](#oh_drawing_getleftfromtextbox) | Obtains the left position of a text box.|
| [float OH_Drawing_GetRightFromTextBox(OH_Drawing_TextBox* textbox, int index)](#oh_drawing_getrightfromtextbox) | Obtains the right position of a text box.|
| [float OH_Drawing_GetTopFromTextBox(OH_Drawing_TextBox* textbox, int index)](#oh_drawing_gettopfromtextbox) | Obtains the top position of a text box.|
| [float OH_Drawing_GetBottomFromTextBox(OH_Drawing_TextBox* textbox, int index)](#oh_drawing_getbottomfromtextbox) | Obtains the bottom position of a text box.|
| [int OH_Drawing_GetTextDirectionFromTextBox(OH_Drawing_TextBox* textbox, int index)](#oh_drawing_gettextdirectionfromtextbox) | Obtains the text direction of a text box.|
| [size_t OH_Drawing_GetSizeOfTextBox(OH_Drawing_TextBox* textBox)](#oh_drawing_getsizeoftextbox) | Obtains the number of text boxes.|
| [OH_Drawing_PositionAndAffinity* OH_Drawing_TypographyGetGlyphPositionAtCoordinate(OH_Drawing_Typography* typography,double dx, double dy)](#oh_drawing_typographygetglyphpositionatcoordinate) | Obtains the position and affinity of the glyph at the given coordinates.|
| [OH_Drawing_PositionAndAffinity* OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster(OH_Drawing_Typography* typography, double dx, double dy)](#oh_drawing_typographygetglyphpositionatcoordinatewithcluster) | Obtains the position and affinity of the glyph cluster to which the glyph at the given coordinates belongs. The glyph cluster is a container that holds one or more glyphs.|
| [size_t OH_Drawing_GetPositionFromPositionAndAffinity(OH_Drawing_PositionAndAffinity* positionAndAffinity)](#oh_drawing_getpositionfrompositionandaffinity) | Obtains the position attribute of an **OH_Drawing_PositionAndAffinity** object.|
| [int OH_Drawing_GetAffinityFromPositionAndAffinity(OH_Drawing_PositionAndAffinity* positionAndAffinity)](#oh_drawing_getaffinityfrompositionandaffinity) | Obtains the affinity attribute of an **OH_Drawing_PositionAndAffinity** object. The affinity determines whether the font is close to the front text or rear text.|
| [OH_Drawing_Range* OH_Drawing_TypographyGetWordBoundary(OH_Drawing_Typography* typography, size_t offset)](#oh_drawing_typographygetwordboundary) | Obtains the word boundary in a typography object.|
| [size_t OH_Drawing_GetStartFromRange(OH_Drawing_Range* range)](#oh_drawing_getstartfromrange) | Obtains the start position of an **OH_Drawing_Range** object.|
| [size_t OH_Drawing_GetEndFromRange(OH_Drawing_Range* range)](#oh_drawing_getendfromrange) | Obtains the end position of an **OH_Drawing_Range** object.|
| [size_t OH_Drawing_TypographyGetLineCount(OH_Drawing_Typography* typography)](#oh_drawing_typographygetlinecount) | Obtains the number of lines in a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called.|
| [void OH_Drawing_SetTextStyleDecorationStyle(OH_Drawing_TextStyle* style, int decorationStyle)](#oh_drawing_settextstyledecorationstyle) | Sets the decoration style for a text style.|
| [void OH_Drawing_SetTextStyleDecorationThicknessScale(OH_Drawing_TextStyle* style, double decorationThicknessScale)](#oh_drawing_settextstyledecorationthicknessscale) | Sets the thickness scale factor for the decoration style of a text style.|
| [void OH_Drawing_SetTextStyleLetterSpacing(OH_Drawing_TextStyle* style, double letterSpacing)](#oh_drawing_settextstyleletterspacing) | Sets the letter spacing for a text style.|
| [void OH_Drawing_SetTextStyleWordSpacing(OH_Drawing_TextStyle* style, double wordSpacing)](#oh_drawing_settextstylewordspacing) | Sets the word spacing for a text style.|
| [void OH_Drawing_SetTextStyleHalfLeading(OH_Drawing_TextStyle* style, bool halfLeading)](#oh_drawing_settextstylehalfleading) | Sets whether to enable half leading for a text style.|
| [void OH_Drawing_SetTextStyleEllipsis(OH_Drawing_TextStyle* style, const char* ellipsis)](#oh_drawing_settextstyleellipsis) | Sets the ellipsis content for a text style.|
| [void OH_Drawing_SetTextStyleEllipsisModal(OH_Drawing_TextStyle* style, int ellipsisModal)](#oh_drawing_settextstyleellipsismodal) | Sets the ellipsis style for a text style.|
| [void OH_Drawing_SetTypographyTextBreakStrategy(OH_Drawing_TypographyStyle* style, int breakStrategy)](#oh_drawing_settypographytextbreakstrategy) | Sets the text break strategy.|
| [void OH_Drawing_SetTypographyTextWordBreakType(OH_Drawing_TypographyStyle* style, int wordBreakType)](#oh_drawing_settypographytextwordbreaktype) | Sets the word break type.|
| [void OH_Drawing_SetTypographyTextEllipsisModal(OH_Drawing_TypographyStyle* style, int ellipsisModal)](#oh_drawing_settypographytextellipsismodal) | Sets the ellipsis style for a text style.|
| [void OH_Drawing_SetTypographyTextEllipsis(OH_Drawing_TypographyStyle* style, const char* ellipsis)](#oh_drawing_settypographytextellipsis) | Sets the ellipsis text for a typography style.|
| [double OH_Drawing_TypographyGetLineHeight(OH_Drawing_Typography* typography, int lineNumber)](#oh_drawing_typographygetlineheight) | Obtains the line height in a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called.|
| [double OH_Drawing_TypographyGetLineWidth(OH_Drawing_Typography* typography, int lineNumber)](#oh_drawing_typographygetlinewidth) | Obtains the line width of a specified line. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called.|
| [void OH_Drawing_SetTypographyTextSplitRatio(OH_Drawing_TypographyStyle* style, float textSplitRatio)](#oh_drawing_settypographytextsplitratio) | Sets the text split ratio.|
| [bool OH_Drawing_TypographyIsLineUnlimited(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographyislineunlimited) | Checks whether the maximum number of lines is limited.|
| [bool OH_Drawing_TypographyIsEllipsized(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographyisellipsized) | Checks whether an ellipsis is configured for a typography style.|
| [void OH_Drawing_SetTypographyTextLocale(OH_Drawing_TypographyStyle* style, const char* locale)](#oh_drawing_settypographytextlocale) | Sets the locale for a typography style.|
| [bool OH_Drawing_TextStyleGetFontMetrics(OH_Drawing_Typography* typography,OH_Drawing_TextStyle* style, OH_Drawing_Font_Metrics* fontmetrics)](#oh_drawing_textstylegetfontmetrics) | Obtains the font metrics of a text style.|
| [void OH_Drawing_SetTypographyTextStyle(OH_Drawing_TypographyStyle* handler, OH_Drawing_TextStyle* style)](#oh_drawing_settypographytextstyle) | Sets a text style.|
| [OH_Drawing_FontDescriptor* OH_Drawing_CreateFontDescriptor(void)](#oh_drawing_createfontdescriptor) | Creates an **OH_Drawing_FontDescriptor** object to describe the detailed information about a system font.|
| [void OH_Drawing_DestroyFontDescriptor(OH_Drawing_FontDescriptor* descriptor)](#oh_drawing_destroyfontdescriptor) | Destroys an **OH_Drawing_FontDescriptor** object and reclaims the memory occupied by the object.|
| [OH_Drawing_FontParser* OH_Drawing_CreateFontParser(void)](#oh_drawing_createfontparser) | Creates an **OH_Drawing_FontParser** object to parse a system font.|
| [void OH_Drawing_DestroyFontParser(OH_Drawing_FontParser* parser)](#oh_drawing_destroyfontparser) | Destroys an **OH_Drawing_FontParser** object and reclaims the memory occupied by the object.|
| [char** OH_Drawing_FontParserGetSystemFontList(OH_Drawing_FontParser* fontParser, size_t* num)](#oh_drawing_fontparsergetsystemfontlist) | Obtains the list of system fonts. This function can be used only on 2-in-1 devices and phones.|
| [void OH_Drawing_DestroySystemFontList(char** fontList, size_t num)](#oh_drawing_destroysystemfontlist) | Reclaims the memory occupied by the system font list.|
| [OH_Drawing_FontDescriptor* OH_Drawing_FontParserGetFontByName(OH_Drawing_FontParser* fontParser, const char* name)](#oh_drawing_fontparsergetfontbyname) | Obtains the descriptor of a system font based on the font name.|
| [OH_Drawing_LineMetrics* OH_Drawing_TypographyGetLineMetrics(OH_Drawing_Typography* typography)](#oh_drawing_typographygetlinemetrics) | Obtains the line metrics in a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called. Release this pointer by calling [OH_Drawing_DestroyLineMetrics](capi-drawing-text-typography-h.md#oh_drawing_destroylinemetrics) when this object is no longer needed.|
| [size_t OH_Drawing_LineMetricsGetSize(OH_Drawing_LineMetrics* lineMetrics)](#oh_drawing_linemetricsgetsize) | Obtains the number of lines.|
| [void OH_Drawing_DestroyLineMetrics(OH_Drawing_LineMetrics* lineMetrics)](#oh_drawing_destroylinemetrics) | Destroys an **OH_Drawing_LineMetrics** object and reclaims the memory occupied by the object.|
| [bool OH_Drawing_TypographyGetLineMetricsAt(OH_Drawing_Typography* typography,int lineNumber, OH_Drawing_LineMetrics* lineMetric)](#oh_drawing_typographygetlinemetricsat) | Obtains the metrics of the given line in a typography object. For details, see the [OH_Drawing_LineMetr](capi-drawing-oh-drawing-linemetrics.md) struct. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called.|
| [bool OH_Drawing_TypographyGetLineInfo(OH_Drawing_Typography* typography, int lineNumber, bool oneLine,bool includeWhitespace, OH_Drawing_LineMetrics* drawingLineMetrics)](#oh_drawing_typographygetlineinfo) | Obtains the metrics of a given line or the metrics of the first character in a given line in a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called.|
| [void OH_Drawing_SetTypographyTextFontWeight(OH_Drawing_TypographyStyle* style, int weight)](#oh_drawing_settypographytextfontweight) | Sets the default font weight for a typography style. Currently, only the default system font supports font weight adjustment. For other fonts, if the weight is less than semi-bold, there is no variation in stroke thickness. If the weight is greater than or equal to semi-bold, it might result in a fake bold effect.|
| [void OH_Drawing_SetTypographyTextFontStyle(OH_Drawing_TypographyStyle* style, int fontStyle)](#oh_drawing_settypographytextfontstyle) | Sets the default font style for a typography style.|
| [void OH_Drawing_SetTypographyTextFontFamily(OH_Drawing_TypographyStyle* style, const char* fontFamily)](#oh_drawing_settypographytextfontfamily) | Sets the font family name for text.|
| [void OH_Drawing_SetTypographyTextFontSize(OH_Drawing_TypographyStyle* style, double fontSize)](#oh_drawing_settypographytextfontsize) | Sets the font size for text.|
| [void OH_Drawing_SetTypographyTextFontHeight(OH_Drawing_TypographyStyle* style, double fontHeight)](#oh_drawing_settypographytextfontheight) | Sets the font height for text.|
| [void OH_Drawing_SetTypographyTextHalfLeading(OH_Drawing_TypographyStyle* style, bool halfLeading)](#oh_drawing_settypographytexthalfleading) | Sets whether to enable half leading for text.|
| [void OH_Drawing_SetTypographyTextUseLineStyle(OH_Drawing_TypographyStyle* style, bool useLineStyle)](#oh_drawing_settypographytextuselinestyle) | Sets whether to enable the text line style.|
| [void OH_Drawing_SetTypographyTextLineStyleFontWeight(OH_Drawing_TypographyStyle* style, int weight)](#oh_drawing_settypographytextlinestylefontweight) | Sets the text font weight of the strut style in a typography style. Currently, only the default system font supports font weight adjustment. For other fonts, if the weight is less than semi-bold, there is no variation in stroke thickness. If the weight is greater than or equal to semi-bold, it might result in a fake bold effect.|
| [void OH_Drawing_SetTypographyTextLineStyleFontStyle(OH_Drawing_TypographyStyle* style, int fontStyle)](#oh_drawing_settypographytextlinestylefontstyle) | Sets the font style of the strut style in a typography style.|
| [void OH_Drawing_SetTypographyTextLineStyleFontFamilies(OH_Drawing_TypographyStyle* style,int fontFamiliesNumber, const char* fontFamilies[])](#oh_drawing_settypographytextlinestylefontfamilies) | Sets the font families for a text line style.|
| [void OH_Drawing_SetTypographyTextLineStyleFontSize(OH_Drawing_TypographyStyle* style, double lineStyleFontSize)](#oh_drawing_settypographytextlinestylefontsize) | Sets the font size for a text line style.|
| [void OH_Drawing_SetTypographyTextLineStyleFontHeight(OH_Drawing_TypographyStyle* style, double lineStyleFontHeight)](#oh_drawing_settypographytextlinestylefontheight) | Sets the font height for a text line style.|
| [void OH_Drawing_SetTypographyTextLineStyleHalfLeading(OH_Drawing_TypographyStyle* style, bool lineStyleHalfLeading)](#oh_drawing_settypographytextlinestylehalfleading) | Sets whether to enable half leading for a text line style.|
| [void OH_Drawing_SetTypographyTextLineStyleSpacingScale(OH_Drawing_TypographyStyle* style, double spacingScale)](#oh_drawing_settypographytextlinestylespacingscale) | Sets the spacing scale factor for a text line style.|
| [void OH_Drawing_SetTypographyTextLineStyleOnly(OH_Drawing_TypographyStyle* style, bool lineStyleOnly)](#oh_drawing_settypographytextlinestyleonly) | Sets whether to enable the text line style only.|
| [OH_Drawing_TextShadow* OH_Drawing_CreateTextShadow(void)](#oh_drawing_createtextshadow) | Creates an **OH_Drawing_TextShadow** object. Release this pointer by calling [OH_Drawing_DestroyTextShadow](capi-drawing-text-typography-h.md#oh_drawing_destroytextshadow) when this object is no longer needed.|
| [void OH_Drawing_DestroyTextShadow(OH_Drawing_TextShadow* shadow)](#oh_drawing_destroytextshadow) | Destroys an **OH_Drawing_TextShadow** object and reclaims the memory occupied by the object.|
| [OH_Drawing_TextShadow* OH_Drawing_TextStyleGetShadows(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetshadows) | Obtains a text shadow container. Release this pointer by calling [OH_Drawing_DestroyTextShadows](capi-drawing-text-typography-h.md#oh_drawing_destroytextshadows) when this object is no longer needed.|
| [int OH_Drawing_TextStyleGetShadowCount(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetshadowcount) | Obtains the size of a text shadow container.|
| [void OH_Drawing_TextStyleAddShadow(OH_Drawing_TextStyle* style, const OH_Drawing_TextShadow* shadow)](#oh_drawing_textstyleaddshadow) | Adds a shadow to a text shadow container.|
| [void OH_Drawing_TextStyleClearShadows(OH_Drawing_TextStyle* style)](#oh_drawing_textstyleclearshadows) | Clears all shadows in a text shadow container.|
| [OH_Drawing_TextShadow* OH_Drawing_TextStyleGetShadowWithIndex(OH_Drawing_TextStyle* style, int index)](#oh_drawing_textstylegetshadowwithindex) | Obtains a shadow with a given index in a text shadow container.|
| [void OH_Drawing_TypographySetIndents(OH_Drawing_Typography* typography, int indentsNumber, const float indents[])](#oh_drawing_typographysetindents) | Sets indents for typography. If this function is not called, texts will have no indentation applied.|
| [float OH_Drawing_TypographyGetIndentsWithIndex(OH_Drawing_Typography* typography, int index)](#oh_drawing_typographygetindentswithindex) | Obtains indents with a given index in a typography object. The line index starts from 0.|
| [OH_Drawing_Range* OH_Drawing_TypographyGetLineTextRange(OH_Drawing_Typography* typography,int lineNumber, bool includeSpaces)](#oh_drawing_typographygetlinetextrange) | Obtains the line bounds in a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called. This function can only be used to obtain the bounds of existing lines. That is, the line index must start from 0, and the maximum index is [OH_Drawing_TypographyGetLineCount](capi-drawing-text-typography-h.md#oh_drawing_typographygetlinecount) - 1.|
| [void OH_Drawing_DestroyTextShadows(OH_Drawing_TextShadow* shadow)](#oh_drawing_destroytextshadows) | Reclaims the memory occupied by the vector consisting of the **OH_Drawing_TextShadow** objects.|
| [OH_Drawing_FontConfigInfo* OH_Drawing_GetSystemFontConfigInfo(OH_Drawing_FontConfigInfoErrorCode* errorCode)](#oh_drawing_getsystemfontconfiginfo) | Obtains the system font configuration.|
| [void OH_Drawing_DestroySystemFontConfigInfo(OH_Drawing_FontConfigInfo* drawFontCfgInfo)](#oh_drawing_destroysystemfontconfiginfo) | Reclaims the memory occupied by the system font configuration.|
| [void OH_Drawing_SetTextStyleFontStyleStruct(OH_Drawing_TextStyle* drawingTextStyle,OH_Drawing_FontStyleStruct fontStyle)](#oh_drawing_settextstylefontstylestruct) | Sets the font style, including the font weight, width, and slant, for a text style.|
| [void OH_Drawing_SetTextStyleBadgeType(OH_Drawing_TextStyle* style, OH_Drawing_TextBadgeType textBadgeType)](#oh_drawing_settextstylebadgetype) | Sets whether to use superscript or subscript in text layout. If this API is not called, the feature is disabled by default.|
| [OH_Drawing_FontStyleStruct OH_Drawing_TextStyleGetFontStyleStruct(OH_Drawing_TextStyle* drawingTextStyle)](#oh_drawing_textstylegetfontstylestruct) | Obtains the font style, including the font weight, width, and slant, of a text style.|
| [void OH_Drawing_SetTypographyStyleFontStyleStruct(OH_Drawing_TypographyStyle* drawingStyle,OH_Drawing_FontStyleStruct fontStyle)](#oh_drawing_settypographystylefontstylestruct) | Sets the font style, including the font weight, width, and slant, for the default text style of a typography style.|
| [OH_Drawing_FontStyleStruct OH_Drawing_TypographyStyleGetFontStyleStruct(OH_Drawing_TypographyStyle* drawingStyle)](#oh_drawing_typographystylegetfontstylestruct) | Obtains the font style, including the font weight, width, and slant, of the default text style of a typography style.|
| [void OH_Drawing_TextStyleSetBackgroundRect(OH_Drawing_TextStyle* style,const OH_Drawing_RectStyle_Info* rectStyleInfo, int styleId)](#oh_drawing_textstylesetbackgroundrect) | Sets a background rectangle and style ID for a text style. The style ID is valid only when the background box is a rounded rectangle.|
| [void OH_Drawing_TypographyHandlerAddSymbol(OH_Drawing_TypographyCreate* handler, uint32_t symbol)](#oh_drawing_typographyhandleraddsymbol) | Adds the symbol to use in the typography creation process.|
| [void OH_Drawing_TextStyleAddFontFeature(OH_Drawing_TextStyle* style, const char* tag, int value)](#oh_drawing_textstyleaddfontfeature) | Adds a font feature for a text style.|
| [void OH_Drawing_TextStyleAddFontVariation(OH_Drawing_TextStyle* style, const char* axis, const float value)](#oh_drawing_textstyleaddfontvariation) | Adds a font variation. This function takes effect only when the corresponding font file (.ttf file) supports variable adjustment. Otherwise, calling this function does not take effect.|
| [OH_Drawing_FontFeature* OH_Drawing_TextStyleGetFontFeatures(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetfontfeatures) | Obtains all the contents in a font feature map container of a text style.|
| [void OH_Drawing_TextStyleDestroyFontFeatures(OH_Drawing_FontFeature* fontFeature, size_t fontFeatureSize)](#oh_drawing_textstyledestroyfontfeatures) | Reclaims the memory occupied by the struct array that holds all the font features.|
| [size_t OH_Drawing_TextStyleGetFontFeatureSize(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetfontfeaturesize) | Obtains the size of a font feature map container in a text style.|
| [void OH_Drawing_TextStyleClearFontFeature(OH_Drawing_TextStyle* style)](#oh_drawing_textstyleclearfontfeature) | Clears all the contents in a font feature map container of a text style.|
| [double OH_Drawing_TextStyleGetBaselineShift(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetbaselineshift) | Obtains the baseline drift of a text style.|
| [void OH_Drawing_TextStyleSetBaselineShift(OH_Drawing_TextStyle* style, double lineShift)](#oh_drawing_textstylesetbaselineshift) | Sets a baseline drift for a text style.|
| [void OH_Drawing_TypographyTextSetHeightBehavior(OH_Drawing_TypographyStyle* style,OH_Drawing_TextHeightBehavior heightMode)](#oh_drawing_typographytextsetheightbehavior) | Sets a text height modifier pattern.|
| [OH_Drawing_TextHeightBehavior OH_Drawing_TypographyTextGetHeightBehavior(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographytextgetheightbehavior) | Obtains the text height modifier pattern.|
| [OH_Drawing_Font_Metrics* OH_Drawing_TypographyGetLineFontMetrics(OH_Drawing_Typography* typography,size_t lineNumber, size_t* fontMetricsSize)](#oh_drawing_typographygetlinefontmetrics) | Obtains all font metrics from a given line in a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called. Otherwise, a null pointer is returned. Release this pointer by calling [OH_Drawing_TypographyDestroyLineFontMetrics](capi-drawing-text-typography-h.md#oh_drawing_typographydestroylinefontmetrics) when this object is no longer needed.|
| [void OH_Drawing_TypographyDestroyLineFontMetrics(OH_Drawing_Font_Metrics* lineFontMetric)](#oh_drawing_typographydestroylinefontmetrics) | Reclaims the memory occupied by the struct array that holds all the font metrics of a given line.|
| [bool OH_Drawing_TextStyleIsEqual(const OH_Drawing_TextStyle* style, const OH_Drawing_TextStyle* comparedStyle)](#oh_drawing_textstyleisequal) | Checks whether two text styles are equal. The word width property is not involved in the comparison.|
| [bool OH_Drawing_TextStyleIsEqualByFont(const OH_Drawing_TextStyle* style, const OH_Drawing_TextStyle* comparedStyle)](#oh_drawing_textstyleisequalbyfont) | Checks whether the font style properties of two text styles are equal.|
| [bool OH_Drawing_TextStyleIsAttributeMatched(const OH_Drawing_TextStyle* style,const OH_Drawing_TextStyle* comparedStyle, OH_Drawing_TextStyleType textStyleType)](#oh_drawing_textstyleisattributematched) | Checks whether two text styles have the same font style type.|
| [void OH_Drawing_TextStyleSetPlaceholder(OH_Drawing_TextStyle* style)](#oh_drawing_textstylesetplaceholder) | Adds a placeholder.|
| [bool OH_Drawing_TextStyleIsPlaceholder(OH_Drawing_TextStyle* style)](#oh_drawing_textstyleisplaceholder) | Checks whether a placeholder is set for a text style.|
| [OH_Drawing_TextAlign OH_Drawing_TypographyStyleGetEffectiveAlignment(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographystylegeteffectivealignment) | Obtains the text alignment mode.|
| [bool OH_Drawing_TypographyStyleIsHintEnabled(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographystyleishintenabled) | Checks whether font hinting is enabled for a typography style. Font hinting is used to improve the readability and appearance of small-sized text when rendering it.|
| [void OH_Drawing_SetTypographyStyleTextStrutStyle(OH_Drawing_TypographyStyle* style, OH_Drawing_StrutStyle* strutstyle)](#oh_drawing_settypographystyletextstrutstyle) | Sets the strut style for a typography style.|
| [OH_Drawing_StrutStyle* OH_Drawing_TypographyStyleGetStrutStyle(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographystylegetstrutstyle) | Obtains the strut style of a typography style.|
| [void OH_Drawing_TypographyStyleDestroyStrutStyle(OH_Drawing_StrutStyle* strutstyle)](#oh_drawing_typographystyledestroystrutstyle) | Reclaims the memory occupied by a strut style.|
| [bool OH_Drawing_TypographyStyleStrutStyleEquals(OH_Drawing_StrutStyle* from, OH_Drawing_StrutStyle* to)](#oh_drawing_typographystylestrutstyleequals) | Checks whether two strut styles are equal.|
| [void OH_Drawing_TypographyStyleSetHintsEnabled(OH_Drawing_TypographyStyle* style, bool hintsEnabled)](#oh_drawing_typographystylesethintsenabled) | Sets whether to enable font hinting for a typography style. Font hinting is used to improve the readability and appearance of small-sized text when rendering it.|
| [void  OH_Drawing_TypographyMarkDirty(OH_Drawing_Typography* typography)](#oh_drawing_typographymarkdirty) | Marks a typography object as dirty data. This function is used to initialize the typography state.|
| [int32_t OH_Drawing_TypographyGetUnresolvedGlyphsCount(OH_Drawing_Typography* typography)](#oh_drawing_typographygetunresolvedglyphscount) | Obtains the number of unresolved glyphs in a typography object. This function can be called only after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called and applied.|
| [void OH_Drawing_TypographyUpdateFontSize(OH_Drawing_Typography* typography, size_t from, size_t to, float fontSize)](#oh_drawing_typographyupdatefontsize) | Updates the font size in a typography object.|
| [void OH_Drawing_TypographyUpdateFontColor(OH_Drawing_Typography* typography, uint32_t color)](#oh_drawing_typographyupdatefontcolor) | Updates the font color in a typography object. This API call also updates the decoration color if it hasn't been set yet. The updated font color takes effect after you call [OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint) to draw the text.|
| [void OH_Drawing_TypographyUpdateDecoration(OH_Drawing_Typography* typography, OH_Drawing_TextDecoration decoration)](#oh_drawing_typographyupdatedecoration) | Updates the decoration type of a typography object. The updated decoration type takes effect after you call [OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint) to draw the text.|
| [void OH_Drawing_TypographyUpdateDecorationThicknessScale(OH_Drawing_Typography* typography,double decorationThicknessScale)](#oh_drawing_typographyupdatedecorationthicknessscale) | Updates the decoration thickness scale of a typography object. The updated decoration thickness scale takes effect after you call [OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint) to draw the text.|
| [void OH_Drawing_TypographyUpdateDecorationStyle(OH_Drawing_Typography* typography,OH_Drawing_TextDecorationStyle decorationStyle)](#oh_drawing_typographyupdatedecorationstyle) | Updates the decoration style of a typography object. The updated decoration style takes effect after you call [OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint) to draw the text.|
| [bool OH_Drawing_TypographyTextGetLineStyle(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographytextgetlinestyle) | Checks whether the text line style is enabled for a typography style.|
| [OH_Drawing_FontWeight OH_Drawing_TypographyTextlineStyleGetFontWeight(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographytextlinestylegetfontweight) | Obtains the font weight of a text line style.|
| [OH_Drawing_FontStyle OH_Drawing_TypographyTextlineStyleGetFontStyle(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographytextlinestylegetfontstyle) | Obtains the font style of the strut style in a typography style.|
| [char** OH_Drawing_TypographyTextlineStyleGetFontFamilies(OH_Drawing_TypographyStyle* style, size_t* num)](#oh_drawing_typographytextlinestylegetfontfamilies) | Obtains the font families of a text line style.|
| [void OH_Drawing_TypographyTextlineStyleDestroyFontFamilies(char** fontFamilies, size_t fontFamiliesNum)](#oh_drawing_typographytextlinestyledestroyfontfamilies) | Reclaims the memory occupied by the font families.|
| [double OH_Drawing_TypographyTextlineStyleGetFontSize(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographytextlinestylegetfontsize) | Obtains the font size of a text line style.|
| [double OH_Drawing_TypographyTextlineStyleGetHeightScale(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographytextlinestylegetheightscale) | Obtains the height scale factor of a text line style.|
| [bool OH_Drawing_TypographyTextlineStyleGetHeightOnly(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographytextlinestylegetheightonly) | Checks whether only the font height is used for a text line style.|
| [bool OH_Drawing_TypographyTextlineStyleGetHalfLeading(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographytextlinestylegethalfleading) | Checks whether half leading is enabled for a text line style.|
| [double OH_Drawing_TypographyTextlineStyleGetSpacingScale(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographytextlinestylegetspacingscale) | Obtains the spacing scale factor of a text line style.|
| [bool OH_Drawing_TypographyTextlineGetStyleOnly(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographytextlinegetstyleonly) | Checks whether only the text line style is enabled for a typography style.|
| [OH_Drawing_TextAlign OH_Drawing_TypographyGetTextAlign(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographygettextalign) | Obtains the text alignment mode.|
| [OH_Drawing_TextDirection OH_Drawing_TypographyGetTextDirection(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographygettextdirection) | Obtains the text direction of a typography style.|
| [size_t OH_Drawing_TypographyGetTextMaxLines(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographygettextmaxlines) | Obtains the maximum number of lines.|
| [char* OH_Drawing_TypographyGetTextEllipsis(OH_Drawing_TypographyStyle* style)](#oh_drawing_typographygettextellipsis) | Obtains the text ellipsis content of a typography style.|
| [void OH_Drawing_TypographyDestroyEllipsis(char* ellipsis)](#oh_drawing_typographydestroyellipsis) | Reclaims the memory occupied by the text ellipsis names.|
| [bool OH_Drawing_TypographyStyleEquals(OH_Drawing_TypographyStyle* from, OH_Drawing_TypographyStyle* to)](#oh_drawing_typographystyleequals) | Checks whether two typography styles are the same. The text height modifier mode [OH_Drawing_TextHeightBehavior](capi-drawing-text-typography-h.md#oh_drawing_textheightbehavior) is not involved in the comparison.|
| [uint32_t OH_Drawing_TextStyleGetColor(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetcolor) | Obtains the color of a text style.|
| [OH_Drawing_TextDecorationStyle OH_Drawing_TextStyleGetDecorationStyle(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetdecorationstyle) | Obtains the decoration style of a text style.|
| [OH_Drawing_FontWeight OH_Drawing_TextStyleGetFontWeight(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetfontweight) | Obtains the font weight of a text style.|
| [OH_Drawing_FontStyle OH_Drawing_TextStyleGetFontStyle(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetfontstyle) | Obtains the font style of a text style.|
| [OH_Drawing_TextBaseline OH_Drawing_TextStyleGetBaseline(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetbaseline) | Obtains the baseline of a text style.|
| [char** OH_Drawing_TextStyleGetFontFamilies(OH_Drawing_TextStyle* style, size_t* num)](#oh_drawing_textstylegetfontfamilies) | Obtains the font families of a text style.|
| [void OH_Drawing_TextStyleDestroyFontFamilies(char** fontFamilies, size_t num)](#oh_drawing_textstyledestroyfontfamilies) | Reclaims the memory occupied by the font families, where **num** specifies the number of font families.|
| [double OH_Drawing_TextStyleGetFontSize(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetfontsize) | Obtains the font size of a text style.|
| [double OH_Drawing_TextStyleGetLetterSpacing(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetletterspacing) | Obtains the letter spacing of a text style.|
| [double OH_Drawing_TextStyleGetWordSpacing(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetwordspacing) | Obtains the word spacing of a text style.|
| [double OH_Drawing_TextStyleGetFontHeight(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetfontheight) | Obtains the font height of a text style.|
| [bool OH_Drawing_TextStyleGetHalfLeading(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegethalfleading) | Checks whether half leading is enabled for a text style.|
| [const char* OH_Drawing_TextStyleGetLocale(OH_Drawing_TextStyle* style)](#oh_drawing_textstylegetlocale) | Obtains the locale of a text style.|
| [void OH_Drawing_TypographyDestroyTextBox(OH_Drawing_TextBox* textBox)](#oh_drawing_typographydestroytextbox) | Releases the memory occupied by a text box.|
| [void OH_Drawing_SetTextShadow(OH_Drawing_TextShadow* shadow, uint32_t color, OH_Drawing_Point* offset,double blurRadius)](#oh_drawing_settextshadow) | Sets a text shadow.|
| [OH_Drawing_TextTab* OH_Drawing_CreateTextTab(OH_Drawing_TextAlign alignment, float location)](#oh_drawing_createtexttab) | Creates a text tab object.|
| [void OH_Drawing_DestroyTextTab(OH_Drawing_TextTab* tab)](#oh_drawing_destroytexttab) | Releases the memory occupied by a text tab object.|
| [OH_Drawing_TextAlign OH_Drawing_GetTextTabAlignment(OH_Drawing_TextTab* tab)](#oh_drawing_gettexttabalignment) | Obtains the alignment mode of a text tab.|
| [float OH_Drawing_GetTextTabLocation(OH_Drawing_TextTab* tab)](#oh_drawing_gettexttablocation) | Obtains the location of a text tab.|
| [void OH_Drawing_SetTypographyTextTab(OH_Drawing_TypographyStyle* style, OH_Drawing_TextTab* tab)](#oh_drawing_settypographytexttab) | Sets the alignment mode and location of a text tab. When the text alignment mode or ellipsis style is set, the tab does not take effect. When the tab location is less than 1.0, the tab is replaced with a space.|
| [size_t OH_Drawing_GetDrawingArraySize(OH_Drawing_Array* drawingArray)](#oh_drawing_getdrawingarraysize) | Obtains the number of objects in the input object array [OH_Drawing_Array](capi-drawing-oh-drawing-array.md).|
| [void OH_Drawing_SetTypographyTextTrailingSpaceOptimized(OH_Drawing_TypographyStyle* style, bool trailingSpaceOptimized)](#oh_drawing_settypographytexttrailingspaceoptimized) | Sets whether to include the trailing spaces in alignment calculations during text typography.|
| [void OH_Drawing_TypographyHandlerAddEncodedText(OH_Drawing_TypographyCreate* handler, const void* text,size_t byteLength, OH_Drawing_TextEncoding textEncodingType)](#oh_drawing_typographyhandleraddencodedtext) | Adds text encoded in a specified format.|
| [void OH_Drawing_SetTypographyTextAutoSpace(OH_Drawing_TypographyStyle *style, bool enableAutoSpace)](#oh_drawing_settypographytextautospace) | Sets whether to enable automatic spacing during text typography.<br>This feature is disabled by default. If enabled, automatic spacing applies between CJK (Chinese, Japanese, and Korean) and Western characters (Latin, Cyrillic, and Greek), between CJK and digits, between CJK and copyright symbols, between copyright symbols and digits, and between copyright symbols and Western characters.|
| [void OH_Drawing_TypographyUpdateDecorationColor(OH_Drawing_Typography* typography, uint32_t color)](#oh_drawing_typographyupdatedecorationcolor) | Updates the decoration color of a typography object.<br> The updated decoration color takes effect after you call [OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint) to draw the text.|
| [void OH_Drawing_SetTypographyVerticalAlignment(OH_Drawing_TypographyStyle* style,OH_Drawing_TextVerticalAlignment align)](#oh_drawing_settypographyverticalalignment) | Sets the vertical alignment mode of the text.|
| [OH_Drawing_TypographyStyle* OH_Drawing_CopyTypographyStyle(OH_Drawing_TypographyStyle* style)](#oh_drawing_copytypographystyle) | Creates a copy of an existing paragraph style object.|
| [OH_Drawing_TextStyle* OH_Drawing_CopyTextStyle(OH_Drawing_TextStyle* style)](#oh_drawing_copytextstyle) | Creates a copy of an existing text style object.|
| [OH_Drawing_TextShadow* OH_Drawing_CopyTextShadow(OH_Drawing_TextShadow* shadow)](#oh_drawing_copytextshadow) | Creates a copy of an existing text shadow object.|

## Enum Description

### OH_Drawing_TextDirection

```
enum OH_Drawing_TextDirection
```

**Description**

Enumerates the text directions.

| Value| Description|
| -- | -- |
| TEXT_DIRECTION_RTL | Right to left (RTL).|
| TEXT_DIRECTION_LTR | Left to right (LTR).|

### OH_Drawing_TextAlign

```
enum OH_Drawing_TextAlign
```

**Description**

Enumerates the text alignment modes.

| Value| Description|
| -- | -- |
| TEXT_ALIGN_LEFT | Left-aligned.|
| TEXT_ALIGN_RIGHT | Right-aligned.|
| TEXT_ALIGN_CENTER | Center-aligned.|
| TEXT_ALIGN_JUSTIFY | Justified, which means that each line (except the last line) is stretched so that every line has equal width, and the left and right margins are straight.|
| TEXT_ALIGN_START | When **OH_Drawing_TextDirection** is set to **TEXT_DIRECTION_LTR**, **TEXT_ALIGN_START** and **TEXT_ALIGN_LEFT** are the same.<br>Similarly, when **OH_Drawing_TextDirection** is set to **TEXT_DIRECTION_RTL**, **TEXT_ALIGN_START** and **TEXT_ALIGN_RIGHT** are the same.|
| TEXT_ALIGN_END | When **OH_Drawing_TextDirection** is set to **TEXT_DIRECTION_LTR**, **TEXT_ALIGN_END** and **TEXT_ALIGN_RIGHT** are the same.<br>Similarly, when **OH_Drawing_TextDirection** is set to **TEXT_DIRECTION_RTL**, **TEXT_ALIGN_END** and **TEXT_ALIGN_LEFT** are the same.|

### OH_Drawing_FontWeight

```
enum OH_Drawing_FontWeight
```

**Description**

Enumerates the font weights.

| Value| Description|
| -- | -- |
| FONT_WEIGHT_100 | Thin.|
| FONT_WEIGHT_200 | Extra-light.|
| FONT_WEIGHT_300 | Light.|
| FONT_WEIGHT_400 | Normal/Regular.|
| FONT_WEIGHT_500 | Medium.|
| FONT_WEIGHT_600 | Semi-bold.|
| FONT_WEIGHT_700 | Bold.|
| FONT_WEIGHT_800 | Extra-bold.|
| FONT_WEIGHT_900 | Black.|

### OH_Drawing_TextBaseline

```
enum OH_Drawing_TextBaseline
```

**Description**

Enumerates the text baselines.

| Value| Description|
| -- | -- |
| TEXT_BASELINE_ALPHABETIC | Alphabetic, where the letters in alphabets like English sit on.|
| TEXT_BASELINE_IDEOGRAPHIC | Ideographic, where the baseline is at the bottom of the text area.|

### OH_Drawing_TextDecoration

```
enum OH_Drawing_TextDecoration
```

**Description**

Enumerates the text decorations.

| Value| Description|
| -- | -- |
| TEXT_DECORATION_NONE = 0x0 | No decoration.|
| TEXT_DECORATION_UNDERLINE = 0x1 | An underline is used for decoration.|
| TEXT_DECORATION_OVERLINE = 0x2 | An overline is used for decoration.|
| TEXT_DECORATION_LINE_THROUGH = 0x4 | A strikethrough is used for decoration.|

### OH_Drawing_FontStyle

```
enum OH_Drawing_FontStyle
```

**Description**

Enumerates the font styles.

| Value| Description|
| -- | -- |
| FONT_STYLE_NORMAL | Normal style.|
| FONT_STYLE_ITALIC | Italic.|
| FONT_STYLE_OBLIQUE | Oblique.<br>**Since**: 12|

### OH_Drawing_PlaceholderVerticalAlignment

```
enum OH_Drawing_PlaceholderVerticalAlignment
```

**Description**

Enumerates the vertical alignment modes of placeholders.

**Since**: 11

| Value| Description|
| -- | -- |
| ALIGNMENT_OFFSET_AT_BASELINE | Aligned to the baseline.|
| ALIGNMENT_ABOVE_BASELINE | Aligned above the baseline.|
| ALIGNMENT_BELOW_BASELINE | Aligned below the baseline.|
| ALIGNMENT_TOP_OF_ROW_BOX | Aligned to the top of the row box.|
| ALIGNMENT_BOTTOM_OF_ROW_BOX | Aligned to the bottom of the row box.|
| ALIGNMENT_CENTER_OF_ROW_BOX | Aligned to the center of the row box.|
| ALIGNMENT_FOLLOW_PARAGRAPH<sup>20+</sup> | Follows the vertical alignment mode of the text.|

### OH_Drawing_TextVerticalAlignment

```
enum OH_Drawing_TextVerticalAlignment
```

**Description**

Enumerates the vertical alignment modes.

**Since**: 20

| Value| Description|
| -- | -- |
| TEXT_VERTICAL_ALIGNMENT_BASELINE | Aligned to the baseline.|
| TEXT_VERTICAL_ALIGNMENT_BOTTOM | Bottom aligned.|
| TEXT_VERTICAL_ALIGNMENT_CENTER | Center-aligned.|
| TEXT_VERTICAL_ALIGNMENT_TOP | Top aligned.|

### OH_Drawing_TextDecorationStyle

```
enum OH_Drawing_TextDecorationStyle
```

**Description**

Enumerates the text decoration styles.

**Since**: 11

| Value| Description|
| -- | -- |
| TEXT_DECORATION_STYLE_SOLID | Solid style.|
| TEXT_DECORATION_STYLE_DOUBLE | Double style.|
| TEXT_DECORATION_STYLE_DOTTED | Dotted style.|
| TEXT_DECORATION_STYLE_DASHED | Dashed style.|
| TEXT_DECORATION_STYLE_WAVY | Wavy style.|

### OH_Drawing_EllipsisModal

```
enum OH_Drawing_EllipsisModal
```

**Description**

Enumerates the ellipsis styles.

**Since**: 11

| Value| Description|
| -- | -- |
| ELLIPSIS_MODAL_HEAD = 0 | Places the ellipsis in the text header.|
| ELLIPSIS_MODAL_MIDDLE = 1 | Places the ellipsis in the middle of the text.|
| ELLIPSIS_MODAL_TAIL = 2 | Places the ellipsis at the end of the text.|

### OH_Drawing_BreakStrategy

```
enum OH_Drawing_BreakStrategy
```

**Description**

Enumerates the text break strategies.

**Since**: 11

| Value| Description|
| -- | -- |
| BREAK_STRATEGY_GREEDY = 0 | Each line is filled as much as possible during line break.|
| BREAK_STRATEGY_HIGH_QUALITY = 1 | Text continuity is preferentially considered during line break.|
| BREAK_STRATEGY_BALANCED = 2 | Line breaks are performed at the word boundary.|

### OH_Drawing_WordBreakType

```
enum OH_Drawing_WordBreakType
```

**Description**

Enumerates the word break types.

**Since**: 11

| Value| Description|
| -- | -- |
| WORD_BREAK_TYPE_NORMAL = 0 | Normal mode.|
| WORD_BREAK_TYPE_BREAK_ALL = 1 | Breaks the words at any character to prevent overflow.|
| WORD_BREAK_TYPE_BREAK_WORD = 2 | Breaks the words at arbitrary points to prevent overflow.|
| WORD_BREAK_TYPE_BREAK_HYPHEN = 3 | Uses a hyphen (-) to break a word at the end of each line. If adding a hyphen is not possible, it will behave the same as **WORD_BREAK_TYPE_BREAK_WORD**.<br> **Since**: 18|

### OH_Drawing_RectHeightStyle

```
enum OH_Drawing_RectHeightStyle
```

**Description**

Enumerates the rectangle height styles.

**Since**: 11

| Value| Description|
| -- | -- |
| RECT_HEIGHT_STYLE_TIGHT | Tight style.|
| RECT_HEIGHT_STYLE_MAX | Maximum style.|
| RECT_HEIGHT_STYLE_INCLUDELINESPACEMIDDLE | Middle style that includes the line spacing.|
| RECT_HEIGHT_STYLE_INCLUDELINESPACETOP | Top style that includes the line spacing.|
| RECT_HEIGHT_STYLE_INCLUDELINESPACEBOTTOM | Bottom style that includes the line spacing.|
| RECT_HEIGHT_STYLE_STRUCT | Structure style.|

### OH_Drawing_RectWidthStyle

```
enum OH_Drawing_RectWidthStyle
```

**Description**

Enumerates the rectangle width styles.

**Since**: 11

| Value| Description|
| -- | -- |
| RECT_WIDTH_STYLE_TIGHT | Tight style.|
| RECT_WIDTH_STYLE_MAX | Maximum style.|

### OH_Drawing_TextBadgeType

```
enum OH_Drawing_TextBadgeType
```

**Description**

Enumerates the text badge styles.

**Since**: 20

| Value| Description|
| -- | -- |
| TEXT_BADGE_NONE | Disables the superscript and subscript.|
| TEXT_SUPERSCRIPT | Enables the superscript.|
| TEXT_SUBSCRIPT | Enables the subscript.|

### OH_Drawing_FontConfigInfoErrorCode

```
enum OH_Drawing_FontConfigInfoErrorCode
```

**Description**

Enumerates the error codes that may be used during the obtaining of system font configurations.

**Since**: 12

| Value| Description|
| -- | -- |
| SUCCESS_FONT_CONFIG_INFO = 0 | Operation successful.|
| ERROR_FONT_CONFIG_INFO_UNKNOWN = 1 | Unknown error.|
| ERROR_FONT_CONFIG_INFO_PARSE_FILE = 2 | Failed to parse the system configuration file.|
| ERROR_FONT_CONFIG_INFO_ALLOC_MEMORY = 3 | Memory allocation fails.|
| ERROR_FONT_CONFIG_INFO_COPY_STRING_DATA = 4 | Failed to copy the string data.|

### OH_Drawing_FontWidth

```
enum OH_Drawing_FontWidth
```

**Description**

Enumerates the font widths.

**Since**: 12

| Value| Description|
| -- | -- |
| FONT_WIDTH_ULTRA_CONDENSED = 1 | Ultra condensed font.|
| FONT_WIDTH_EXTRA_CONDENSED = 2 | Extra condensed font.|
| FONT_WIDTH_CONDENSED = 3 | Condensed font.|
| FONT_WIDTH_SEMI_CONDENSED = 4 | Semi-condensed font.|
| FONT_WIDTH_NORMAL = 5 | Normal font.|
| FONT_WIDTH_SEMI_EXPANDED = 6 | Semi-expanded font.|
| FONT_WIDTH_EXPANDED = 7 | Expanded font.|
| FONT_WIDTH_EXTRA_EXPANDED = 8 | Extra expanded font.|
| FONT_WIDTH_ULTRA_EXPANDED = 9 | Ultra expanded font.|

### OH_Drawing_TextHeightBehavior

```
enum OH_Drawing_TextHeightBehavior
```

**Description**

Enumerates the text height modifier patterns.

**Since**: 12

| Value| Description|
| -- | -- |
| TEXT_HEIGHT_ALL = 0x0 | Enables the height set by calling [OH_Drawing_SetTextStyleFontHeight](capi-drawing-text-typography-h.md#oh_drawing_settextstylefontheight) for the top of the first line and the bottom of the last line in a paragraph.|
| TEXT_HEIGHT_DISABLE_FIRST_ASCENT = 0x1 | Disables the height set by calling [OH_Drawing_SetTextStyleFontHeight](capi-drawing-text-typography-h.md#oh_drawing_settextstylefontheight) for the top of the first line in a paragraph.|
| TEXT_HEIGHT_DISABLE_LAST_ASCENT = 0x2 | Disables the height set by calling [OH_Drawing_SetTextStyleFontHeight](capi-drawing-text-typography-h.md#oh_drawing_settextstylefontheight) for the bottom of the last line in a paragraph.|
| TEXT_HEIGHT_DISABLE_ALL = 0x1 \| 0x2 | Disables the height set by calling [OH_Drawing_SetTextStyleFontHeight](capi-drawing-text-typography-h.md#oh_drawing_settextstylefontheight) for both the top of the first line and the bottom of the last line in a paragraph.|

### OH_Drawing_TextStyleType

```
enum OH_Drawing_TextStyleType
```

**Description**

Enumerates the text style types.

**Since**: 12

| Value| Description|
| -- | -- |
| TEXT_STYLE_NONE | No text style.|
| TEXT_STYLE_ALL_ATTRIBUTES | All text styles.|
| TEXT_STYLE_FONT | Font style.|
| TEXT_STYLE_FOREGROUND | Text foreground style.|
| TEXT_STYLE_BACKGROUND | Text background style.|
| TEXT_STYLE_SHADOW | Text shadow style.|
| TEXT_STYLE_DECORATIONS | Text decoration style.|
| TEXT_STYLE_LETTER_SPACING | Text letter spacing style.|
| TEXT_STYLE_WORD_SPACING | Text word spacing style.|


## Function Description

### OH_Drawing_CreateTypographyStyle()

```
OH_Drawing_TypographyStyle* OH_Drawing_CreateTypographyStyle(void)
```

**Description**

Creates an **OH_Drawing_TypographyStyle** object. Release this pointer by calling [OH_Drawing_DestroyTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_destroytypographystyle) when this object is no longer needed.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* | Pointer to the created [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object.|

### OH_Drawing_DestroyTypographyStyle()

```
void OH_Drawing_DestroyTypographyStyle(OH_Drawing_TypographyStyle* style)
```

**Description**

Destroys an **OH_Drawing_TypographyStyle** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|

### OH_Drawing_SetTypographyTextDirection()

```
void OH_Drawing_SetTypographyTextDirection(OH_Drawing_TypographyStyle* style, int direction)
```

**Description**

Sets the text direction in a typography style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| int direction | Text direction. For details about the available options, see [OH_Drawing_TextDirection](capi-drawing-text-typography-h.md#oh_drawing_textdirection).|

### OH_Drawing_SetTypographyTextAlign()

```
void OH_Drawing_SetTypographyTextAlign(OH_Drawing_TypographyStyle* style, int align)
```

**Description**

Text alignment mode.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| int align | Text alignment mode. For details about the available options, see [OH_Drawing_TextAlign](capi-drawing-text-typography-h.md#oh_drawing_textalign).|

### OH_Drawing_TypographyGetEffectiveAlignment()

```
int OH_Drawing_TypographyGetEffectiveAlignment(OH_Drawing_TypographyStyle* style)
```

**Description**

Obtains the text alignment mode.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|

**Returns**

| Type| Description|
| -- | -- |
| int | Text alignment mode.|

### OH_Drawing_SetTypographyTextMaxLines()

```
void OH_Drawing_SetTypographyTextMaxLines(OH_Drawing_TypographyStyle* style, int lineNumber)
```

**Description**

Sets the maximum number of lines in the text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| int lineNumber | Maximum number of lines.|

### OH_Drawing_CreateTextStyle()

```
OH_Drawing_TextStyle* OH_Drawing_CreateTextStyle(void)
```

**Description**

Creates an **OH_Drawing_TextStyle** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* | Pointer to the created [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object.|

### OH_Drawing_TypographyGetTextStyle()

```
OH_Drawing_TextStyle* OH_Drawing_TypographyGetTextStyle(OH_Drawing_TypographyStyle* style)
```

**Description**

Obtains the default text style of a typography style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object. Release this pointer by calling [OH_Drawing_DestroyTextStyle](capi-drawing-text-typography-h.md#oh_drawing_destroytextstyle) when this object is no longer needed.|

### OH_Drawing_DestroyTextStyle()

```
void OH_Drawing_DestroyTextStyle(OH_Drawing_TextStyle* style)
```

**Description**

Destroys an **OH_Drawing_TextStyle** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

### OH_Drawing_SetTextStyleColor()

```
void OH_Drawing_SetTextStyleColor(OH_Drawing_TextStyle* style, uint32_t color)
```

**Description**

Sets the color for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| uint32_t color | Color.|

### OH_Drawing_SetTextStyleFontSize()

```
void OH_Drawing_SetTextStyleFontSize(OH_Drawing_TextStyle* style, double fontSize)
```

**Description**

Sets the font size for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| double fontSize | Font size to set.|

### OH_Drawing_SetTextStyleFontWeight()

```
void OH_Drawing_SetTextStyleFontWeight(OH_Drawing_TextStyle* style, int fontWeight)
```

**Description**

Sets the font weight for a text style. Currently, only the default system font supports font weight adjustment. For other fonts, if the weight is less than semi-bold, there is no variation in stroke thickness. If the weight is greater than or equal to semi-bold, it might result in a fake bold effect.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| int fontWeight | Font weight.<br>For details about the available options, see [OH_Drawing_FontWeight](capi-drawing-text-typography-h.md#oh_drawing_fontweight).|

### OH_Drawing_SetTextStyleBaseLine()

```
void OH_Drawing_SetTextStyleBaseLine(OH_Drawing_TextStyle* style, int baseline)
```

**Description**

Sets the baseline for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| int baseline | Text baseline. For details about the available options, see [OH_Drawing_TextBaseline](capi-drawing-text-typography-h.md#oh_drawing_textbaseline).|

### OH_Drawing_SetTextStyleDecoration()

```
void OH_Drawing_SetTextStyleDecoration(OH_Drawing_TextStyle* style, int decoration)
```

**Description**

Sets the decoration for a text style. Only one decoration can be set. To add multiple decorations, use [OH_Drawing_AddTextStyleDecoration](capi-drawing-text-typography-h.md#oh_drawing_addtextstyledecoration).

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| int decoration | Text decoration. For details about the available options, see [OH_Drawing_TextDecoration](capi-drawing-text-typography-h.md#oh_drawing_textdecoration).|

### OH_Drawing_AddTextStyleDecoration()

```
void OH_Drawing_AddTextStyleDecoration(OH_Drawing_TextStyle* style, int decoration)
```

**Description**

Adds the decoration for a text style. Multiple decoration lines can be displayed.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| int decoration | Decoration to add. The value **1** means to add an underline, **2** means to add an overline, and 4 means to add a strikethrough. You can add multiple decoration lines at a time via bitwise OR operations.<br>If a decoration style that is not in the [OH_Drawing_TextDecoration](capi-drawing-text-typography-h.md#oh_drawing_textdecoration) enumeration is set, the original decoration is retained.|

### OH_Drawing_RemoveTextStyleDecoration()

```
void OH_Drawing_RemoveTextStyleDecoration(OH_Drawing_TextStyle* style, int decoration)
```

**Description**

Removes the decoration for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| int decoration | Decoration to remove. The value **1** means to remove an underline, **2** means to remove an overline, and 4 means to remove a strikethrough. You can remove various text decorations in a single operation using bitwise OR. <br>If a decoration style that is not in the [OH_Drawing_TextDecoration](capi-drawing-text-typography-h.md#oh_drawing_textdecoration) enumeration is set, the original decoration is retained.|

### OH_Drawing_SetTextStyleDecorationColor()

```
void OH_Drawing_SetTextStyleDecorationColor(OH_Drawing_TextStyle* style, uint32_t color)
```

**Description**

Sets the decoration color for a text style. If this API is not called or **color** is set to **0**, the decoration color follows the text color.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| uint32_t color | Color.|

### OH_Drawing_SetTextStyleFontHeight()

```
void OH_Drawing_SetTextStyleFontHeight(OH_Drawing_TextStyle* style, double fontHeight)
```

**Description**

Sets the line height based on the multiple of the font size.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| double fontHeight | Multiple of the font size.|

### OH_Drawing_SetTextStyleFontFamilies()

```
void OH_Drawing_SetTextStyleFontFamilies(OH_Drawing_TextStyle* style,int fontFamiliesNumber, const char* fontFamilies[])
```

**Description**

Sets the font families for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| int fontFamiliesNumber | Number of font families. A negative number is not allowed.|
| fontFamilies |  Pointer to the font families.|

### OH_Drawing_SetTextStyleFontStyle()

```
void OH_Drawing_SetTextStyleFontStyle(OH_Drawing_TextStyle* style, int fontStyle)
```

**Description**

Sets the font style for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| int fontStyle | Font style. For details about the available options, see [OH_Drawing_FontStyle](capi-drawing-text-typography-h.md#oh_drawing_fontstyle).|

### OH_Drawing_SetTextStyleLocale()

```
void OH_Drawing_SetTextStyleLocale(OH_Drawing_TextStyle* style, const char* locale)
```

**Description**

Sets the locale for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| const char* locale | Pointer to the locale. For example, **'en'** indicates English, **'zh-Hans'** indicates Simplified Chinese, and **'zh-Hant'** indicates Traditional Chinese.|

### OH_Drawing_SetTextStyleForegroundBrush()

```
void OH_Drawing_SetTextStyleForegroundBrush(OH_Drawing_TextStyle* style, OH_Drawing_Brush* foregroundBrush)
```

**Description**

Sets the foreground brush for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* foregroundBrush | Pointer to the [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md) object, which is obtained from [OH_Drawing_BrushCreate](capi-drawing-brush-h.md#oh_drawing_brushcreate).|

### OH_Drawing_TextStyleGetForegroundBrush()

```
void OH_Drawing_TextStyleGetForegroundBrush(OH_Drawing_TextStyle* style, OH_Drawing_Brush* foregroundBrush)
```

**Description**

Obtains the foreground brush of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* foregroundBrush | Pointer to the [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md) object, which is obtained from [OH_Drawing_BrushCreate](capi-drawing-brush-h.md#oh_drawing_brushcreate).|

### OH_Drawing_SetTextStyleForegroundPen()

```
void OH_Drawing_SetTextStyleForegroundPen(OH_Drawing_TextStyle* style, OH_Drawing_Pen* foregroundPen)
```

**Description**

Sets the foreground pen for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* foregroundPen | Pointer to the [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md) object, which is obtained from [OH_Drawing_PenCreate](capi-drawing-pen-h.md#oh_drawing_pencreate).|

### OH_Drawing_TextStyleGetForegroundPen()

```
void OH_Drawing_TextStyleGetForegroundPen(OH_Drawing_TextStyle* style, OH_Drawing_Pen* foregroundPen)
```

**Description**

Obtains the foreground pen of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* foregroundPen | Pointer to the [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md) object, which is obtained from [OH_Drawing_PenCreate](capi-drawing-pen-h.md#oh_drawing_pencreate).|

### OH_Drawing_SetTextStyleBackgroundBrush()

```
void OH_Drawing_SetTextStyleBackgroundBrush(OH_Drawing_TextStyle* style, OH_Drawing_Brush* backgroundBrush)
```

**Description**

Sets the background brush for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* backgroundBrush | Pointer to the [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md) object, which is obtained from [OH_Drawing_BrushCreate](capi-drawing-brush-h.md#oh_drawing_brushcreate).|

### OH_Drawing_TextStyleGetBackgroundBrush()

```
void OH_Drawing_TextStyleGetBackgroundBrush(OH_Drawing_TextStyle* style, OH_Drawing_Brush* backgroundBrush)
```

**Description**

Obtains the background brush of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)* backgroundBrush | Pointer to the [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md) object, which is obtained from [OH_Drawing_BrushCreate](capi-drawing-brush-h.md#oh_drawing_brushcreate).|

### OH_Drawing_SetTextStyleBackgroundPen()

```
void OH_Drawing_SetTextStyleBackgroundPen(OH_Drawing_TextStyle* style, OH_Drawing_Pen* backgroundPen)
```

**Description**

Sets the background pen for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* backgroundPen | Pointer to the [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md) object, which is obtained from [OH_Drawing_PenCreate](capi-drawing-pen-h.md#oh_drawing_pencreate).|

### OH_Drawing_TextStyleGetBackgroundPen()

```
void OH_Drawing_TextStyleGetBackgroundPen(OH_Drawing_TextStyle* style, OH_Drawing_Pen* backgroundPen)
```

**Description**

Obtains the background pen of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)* backgroundPen | Pointer to the [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md) object, which is obtained from [OH_Drawing_PenCreate](capi-drawing-pen-h.md#oh_drawing_pencreate).|

### OH_Drawing_CreateTypographyHandler()

```
OH_Drawing_TypographyCreate* OH_Drawing_CreateTypographyHandler(OH_Drawing_TypographyStyle* style,OH_Drawing_FontCollection* fontCollection)
```

**Description**

Creates an **OH_Drawing_TypographyCreate** object. Release this pointer by calling [OH_Drawing_DestroyTypographyHandler](capi-drawing-text-typography-h.md#oh_drawing_destroytypographyhandler) when this object is no longer needed.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* fontCollection | Pointer to the [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md) object, which is obtained from [OH_Drawing_CreateFontCollection](capi-drawing-font-collection-h.md#oh_drawing_createfontcollection).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)* | Pointer to the **OH_Drawing_TypographyCreate** object created.|

### OH_Drawing_DestroyTypographyHandler()

```
void OH_Drawing_DestroyTypographyHandler(OH_Drawing_TypographyCreate* handler)
```

**Description**

Destroys an **OH_Drawing_TypographyCreate** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)* handler | Pointer to the [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md) object, which is obtained from [OH_Drawing_CreateTypographyHandler](capi-drawing-text-typography-h.md#oh_drawing_createtypographyhandler).|

### OH_Drawing_TypographyHandlerPushTextStyle()

```
void OH_Drawing_TypographyHandlerPushTextStyle(OH_Drawing_TypographyCreate* handler, OH_Drawing_TextStyle* style)
```

**Description**

Pushes a text style into the text style stack. Any text added afterward will use the style currently on top of the stack.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)* handler | Pointer to the [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md) object, which is obtained from [OH_Drawing_CreateTypographyHandler](capi-drawing-text-typography-h.md#oh_drawing_createtypographyhandler).|
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

### OH_Drawing_TypographyHandlerAddText()

```
void OH_Drawing_TypographyHandlerAddText(OH_Drawing_TypographyCreate* handler, const char* text)
```

**Description**

Adds text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)* handler | Pointer to the [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md) object, which is obtained from [OH_Drawing_CreateTypographyHandler](capi-drawing-text-typography-h.md#oh_drawing_createtypographyhandler).|
| const char* text | Pointer to the text content.|

### OH_Drawing_TypographyHandlerPopTextStyle()

```
void OH_Drawing_TypographyHandlerPopTextStyle(OH_Drawing_TypographyCreate* handler)
```

**Description**

Pops the top text style out of the text style stack.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)* handler | Pointer to the [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md) object, which is obtained from [OH_Drawing_CreateTypographyHandler](capi-drawing-text-typography-h.md#oh_drawing_createtypographyhandler).|

### OH_Drawing_CreateTypography()

```
OH_Drawing_Typography* OH_Drawing_CreateTypography(OH_Drawing_TypographyCreate* handler)
```

**Description**

Creates an **OH_Drawing_Typography** object. Release this pointer by calling [OH_Drawing_DestroyTypography](capi-drawing-text-typography-h.md#oh_drawing_destroytypography) when this object is no longer needed.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)* handler | Pointer to the [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md) object, which is obtained from [OH_Drawing_CreateTypographyHandler](capi-drawing-text-typography-h.md#oh_drawing_createtypographyhandler).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* | Pointer to the **OH_Drawing_Typography** object created.|

### OH_Drawing_DestroyTypography()

```
void OH_Drawing_DestroyTypography(OH_Drawing_Typography* typography)
```

**Description**

Destroys an **OH_Drawing_Typography** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md) object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|

### OH_Drawing_TypographyLayout()

```
void OH_Drawing_TypographyLayout(OH_Drawing_Typography* typography, double maxWidth)
```

**Description**

Lays out the typography.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md) object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|
| double maxWidth | Maximum text width.|

### OH_Drawing_TypographyPaint()

```
void OH_Drawing_TypographyPaint(OH_Drawing_Typography* typography, OH_Drawing_Canvas* canvas,double positionX, double positionY)
```

**Description**

Draws text from the upper left corner at a specified position. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called and applied.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the **OH_Drawing_Typography** object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|
| [OH_Drawing_Canvas](capi-drawing-oh-drawing-canvas.md)* canvas | Pointer to the **OH_Drawing_Canvas** object, which is obtained from [OH_Drawing_CanvasCreate](capi-drawing-canvas-h.md#oh_drawing_canvascreate).|
| double positionX | X coordinate.|
| double positionY | Y coordinate. |

### OH_Drawing_TypographyPaintOnPath()

```
void OH_Drawing_TypographyPaintOnPath(OH_Drawing_Typography* typography, OH_Drawing_Canvas* canvas,OH_Drawing_Path* path, double hOffset, double vOffset)
```

**Description**

Draws text along a path. To prevent text overlap caused by the text width exceeding the layout width, you are advised to use [OH_Drawing_SetTypographyTextMaxLines](capi-drawing-text-typography-h.md#oh_drawing_settypographytextmaxlines) to limit the text to a single line.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the **OH_Drawing_Typography** object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|
| [OH_Drawing_Canvas](capi-drawing-oh-drawing-canvas.md)* canvas | Pointer to the **OH_Drawing_Canvas** object, which is obtained from [OH_Drawing_CanvasCreate](capi-drawing-canvas-h.md#oh_drawing_canvascreate).|
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | Pointer to the **OH_Drawing_Path** object, which is obtained from [OH_Drawing_PathCreate](capi-drawing-path-h.md#oh_drawing_pathcreate).|
| double hOffset | Horizontal offset of the text along the path (X axis). A positive number indicates that the text is moved forward, and a negative number indicates that the text is moved backward.|
| double vOffset | Vertical offset of the text along the path (Y axis). A positive number indicates that the text is moved downward, and a negative number indicates that the text is moved upward.|

### OH_Drawing_TypographyGetMaxWidth()

```
double OH_Drawing_TypographyGetMaxWidth(OH_Drawing_Typography* typography)
```

**Description**

Obtains the typography width set by the user. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the **OH_Drawing_Typography** object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|

**Returns**

| Type| Description|
| -- | -- |
| double | Maximum width.|

### OH_Drawing_TypographyGetHeight()

```
double OH_Drawing_TypographyGetHeight(OH_Drawing_Typography* typography)
```

**Description**

Obtains the overall height of a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the **OH_Drawing_Typography** object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|

**Returns**

| Type| Description|
| -- | -- |
| double | Height.|

### OH_Drawing_TypographyGetLongestLine()

```
double OH_Drawing_TypographyGetLongestLine(OH_Drawing_Typography* typography)
```

**Description**

Obtains the width of the longest line in a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called. You are advised to round up the return value. If the text content is empty, **0.0** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the **OH_Drawing_Typography** object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|

**Returns**

| Type| Description|
| -- | -- |
| double | Width of the longest line.|

### OH_Drawing_TypographyGetLongestLineWithIndent()

```
double OH_Drawing_TypographyGetLongestLineWithIndent(OH_Drawing_Typography* typography)
```

**Description**

Obtains the width of the longest line of a typography object, including its indentation. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called. You are advised to round up the return value. If the text content is empty, **0.0** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md) object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|

**Returns**

| Type| Description|
| -- | -- |
| double | Width of the longest line, including its indentation, in px.|

### OH_Drawing_TypographyGetMinIntrinsicWidth()

```
double OH_Drawing_TypographyGetMinIntrinsicWidth(OH_Drawing_Typography* typography)
```

**Description**

Obtains the minimum intrinsic width in a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the **OH_Drawing_Typography** object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|

**Returns**

| Type| Description|
| -- | -- |
| double | Minimum intrinsic width.|

### OH_Drawing_TypographyGetMaxIntrinsicWidth()

```
double OH_Drawing_TypographyGetMaxIntrinsicWidth(OH_Drawing_Typography* typography)
```

**Description**

Obtains the maximum intrinsic width in a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the **OH_Drawing_Typography** object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|

**Returns**

| Type| Description|
| -- | -- |
| double | Maximum intrinsic width.|

### OH_Drawing_TypographyGetAlphabeticBaseline()

```
double OH_Drawing_TypographyGetAlphabeticBaseline(OH_Drawing_Typography* typography)
```

**Description**

Obtains the alphabetic baseline in a typography object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the **OH_Drawing_Typography** object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|

**Returns**

| Type| Description|
| -- | -- |
| double | Alphabetic baseline.|

### OH_Drawing_TypographyGetIdeographicBaseline()

```
double OH_Drawing_TypographyGetIdeographicBaseline(OH_Drawing_Typography* typography)
```

**Description**

Obtains the ideographic baseline in a typography object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the **OH_Drawing_Typography** object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|

**Returns**

| Type| Description|
| -- | -- |
| double | Ideographic baseline.|

### OH_Drawing_TypographyHandlerAddPlaceholder()

```
void OH_Drawing_TypographyHandlerAddPlaceholder(OH_Drawing_TypographyCreate* handler,OH_Drawing_PlaceholderSpan* span)
```

**Description**

Adds a placeholder.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)* handler | Pointer to the [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md) object, which is obtained from [OH_Drawing_CreateTypographyHandler](capi-drawing-text-typography-h.md#oh_drawing_createtypographyhandler).|
| [OH_Drawing_PlaceholderSpan](capi-drawing-oh-drawing-placeholderspan.md)* span | Pointer to the [OH_Drawing_PlaceholderSpan](capi-drawing-oh-drawing-placeholderspan.md) object.|

### OH_Drawing_TypographyDidExceedMaxLines()

```
bool OH_Drawing_TypographyDidExceedMaxLines(OH_Drawing_Typography* typography)
```

**Description**

Checks whether the text in the typography object exceeds the line limit. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called. It returns **false** if the line limit is not set using [OH_Drawing_SetTypographyTextMaxLines](capi-drawing-text-typography-h.md#oh_drawing_settypographytextmaxlines).

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the **OH_Drawing_Typography** object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|

**Returns**

| Type| Description|
| -- | -- |
| bool | Returns **true** if the maximum number of lines is exceeded; returns **false** otherwise.|

### OH_Drawing_TypographyGetRectsForRange()

```
OH_Drawing_TextBox* OH_Drawing_TypographyGetRectsForRange(OH_Drawing_Typography* typography,size_t start, size_t end, OH_Drawing_RectHeightStyle heightStyle, OH_Drawing_RectWidthStyle widthStyle)
```

**Description**

Obtains text boxes in a given range of a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called. Release this pointer by calling [OH_Drawing_TypographyDestroyTextBox](capi-drawing-text-typography-h.md#oh_drawing_typographydestroytextbox) when this object is no longer needed.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the **OH_Drawing_Typography** object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|
| size_t start | Start position.|
| size_t end | End position.|
| [OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle) heightStyle | Height style. For details about the available options, see [OH_Drawing_RectHeightStyle](capi-drawing-text-typography-h.md#oh_drawing_rectheightstyle).|
| [OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle) widthStyle | Width style. For details about the available options, see [OH_Drawing_RectWidthStyle](capi-drawing-text-typography-h.md#oh_drawing_rectwidthstyle).|

**Returns**

| Type| Description|
| -- | -- |
| OH_Drawing_TextBox* | Text box in the specified range. For details, see [OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md).|

### OH_Drawing_TypographyGetRectsForPlaceholders()

```
OH_Drawing_TextBox* OH_Drawing_TypographyGetRectsForPlaceholders(OH_Drawing_Typography* typography)
```

**Description**

Obtains text boxes for placeholders in a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called. Release this pointer by calling [OH_Drawing_TypographyDestroyTextBox](capi-drawing-text-typography-h.md#oh_drawing_typographydestroytextbox) when this object is no longer needed.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the **OH_Drawing_Typography** object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)* | Placeholder text box. The return type is [OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md).|

### OH_Drawing_GetLeftFromTextBox()

```
float OH_Drawing_GetLeftFromTextBox(OH_Drawing_TextBox* textbox, int index)
```

**Description**

Obtains the left position of a text box.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)* textbox | Pointer to the **OH_Drawing_TextBox** object, which is obtained from [OH_Drawing_TypographyGetRectsForRange](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforrange) or [OH_Drawing_TypographyGetRectsForPlaceholders](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforplaceholders).|
| int index | Index of the text box.|

**Returns**

| Type| Description|
| -- | -- |
| float | Left position.|

### OH_Drawing_GetRightFromTextBox()

```
float OH_Drawing_GetRightFromTextBox(OH_Drawing_TextBox* textbox, int index)
```

**Description**

Obtains the right position of a text box.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)* textbox | Pointer to the **OH_Drawing_TextBox** object, which is obtained from [OH_Drawing_TypographyGetRectsForRange](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforrange) or [OH_Drawing_TypographyGetRectsForPlaceholders](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforplaceholders).|
| int index | Index of the text box.|

**Returns**

| Type| Description|
| -- | -- |
| float | Right position.|

### OH_Drawing_GetTopFromTextBox()

```
float OH_Drawing_GetTopFromTextBox(OH_Drawing_TextBox* textbox, int index)
```

**Description**

Obtains the top position of a text box.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)* textbox | Pointer to the **OH_Drawing_TextBox** object, which is obtained from [OH_Drawing_TypographyGetRectsForRange](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforrange) or [OH_Drawing_TypographyGetRectsForPlaceholders](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforplaceholders).|
| int index | Index of the text box.|

**Returns**

| Type| Description|
| -- | -- |
| float | Top position.|

### OH_Drawing_GetBottomFromTextBox()

```
float OH_Drawing_GetBottomFromTextBox(OH_Drawing_TextBox* textbox, int index)
```

**Description**

Obtains the bottom position of a text box.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)* textbox | Pointer to the **OH_Drawing_TextBox** object, which is obtained from [OH_Drawing_TypographyGetRectsForRange](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforrange) or [OH_Drawing_TypographyGetRectsForPlaceholders](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforplaceholders).|
| int index | Index of the text box.|

**Returns**

| Type| Description|
| -- | -- |
| float | Bottom position.|

### OH_Drawing_GetTextDirectionFromTextBox()

```
int OH_Drawing_GetTextDirectionFromTextBox(OH_Drawing_TextBox* textbox, int index)
```

**Description**

Obtains the text direction of a text box.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)* textbox | Pointer to the [OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md) object, which is obtained from [OH_Drawing_TypographyGetRectsForRange](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforrange) or [OH_Drawing_TypographyGetRectsForPlaceholders](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforplaceholders).|
| int index | Index of the text box.|

**Returns**

| Type| Description|
| -- | -- |
| int | Text direction.|

### OH_Drawing_GetSizeOfTextBox()

```
size_t OH_Drawing_GetSizeOfTextBox(OH_Drawing_TextBox* textBox)
```

**Description**

Obtains the number of text boxes.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)* textBox | Pointer to the **OH_Drawing_TextBox** object, which is obtained from [OH_Drawing_TypographyGetRectsForRange](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforrange) or [OH_Drawing_TypographyGetRectsForPlaceholders](capi-drawing-text-typography-h.md#oh_drawing_typographygetrectsforplaceholders).|

**Returns**

| Type| Description|
| -- | -- |
| size_t | Number of text boxes.|

### OH_Drawing_TypographyGetGlyphPositionAtCoordinate()

```
OH_Drawing_PositionAndAffinity* OH_Drawing_TypographyGetGlyphPositionAtCoordinate(OH_Drawing_Typography* typography,double dx, double dy)
```

**Description**

Obtains the position and affinity of the glyph at the given coordinates.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the **OH_Drawing_Typography** object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|
| double dx | X coordinate.|
| double dy | Y coordinate.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_PositionAndAffinity](capi-drawing-oh-drawing-positionandaffinity.md)* | [OH_Drawing_PositionAndAffinity](capi-drawing-oh-drawing-positionandaffinity.md) struct that holds the position and affinity of the glyph cluster.|

### OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster()

```
OH_Drawing_PositionAndAffinity* OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster(OH_Drawing_Typography* typography, double dx, double dy)
```

**Description**

Obtains the position and affinity of the glyph cluster to which the glyph at the given coordinates belongs. The glyph cluster is a container that holds one or more glyphs.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the **OH_Drawing_Typography** object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|
| double dx | X coordinate.|
| double dy | Y coordinate.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_PositionAndAffinity](capi-drawing-oh-drawing-positionandaffinity.md)* | [OH_Drawing_PositionAndAffinity](capi-drawing-oh-drawing-positionandaffinity.md) struct that holds the position and affinity of the glyph cluster.|

### OH_Drawing_GetPositionFromPositionAndAffinity()

```
size_t OH_Drawing_GetPositionFromPositionAndAffinity(OH_Drawing_PositionAndAffinity* positionAndAffinity)
```

**Description**

Obtains the position attribute of an **OH_Drawing_PositionAndAffinity** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_PositionAndAffinity](capi-drawing-oh-drawing-positionandaffinity.md)* positionAndAffinity | Pointer to the **OH_Drawing_PositionAndAffinity** object, which is obtained from [OH_Drawing_TypographyGetGlyphPositionAtCoordinate](capi-drawing-text-typography-h.md#oh_drawing_typographygetglyphpositionatcoordinate) or [OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster](capi-drawing-text-typography-h.md#oh_drawing_typographygetglyphpositionatcoordinatewithcluster).|

**Returns**

| Type| Description|
| -- | -- |
| size_t | Position attribute.|

### OH_Drawing_GetAffinityFromPositionAndAffinity()

```
int OH_Drawing_GetAffinityFromPositionAndAffinity(OH_Drawing_PositionAndAffinity* positionAndAffinity)
```

**Description**

Obtains the affinity attribute of an **OH_Drawing_PositionAndAffinity** object. The affinity determines whether the font is close to the front text or rear text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_PositionAndAffinity](capi-drawing-oh-drawing-positionandaffinity.md)* positionAndAffinity | Pointer to the **OH_Drawing_PositionAndAffinity** object, which is obtained from [OH_Drawing_TypographyGetGlyphPositionAtCoordinate](capi-drawing-text-typography-h.md#oh_drawing_typographygetglyphpositionatcoordinate) or [OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster](capi-drawing-text-typography-h.md#oh_drawing_typographygetglyphpositionatcoordinatewithcluster).|

**Returns**

| Type| Description|
| -- | -- |
| int | Affinity attribute.|

### OH_Drawing_TypographyGetWordBoundary()

```
OH_Drawing_Range* OH_Drawing_TypographyGetWordBoundary(OH_Drawing_Typography* typography, size_t offset)
```

**Description**

Obtains the word boundary in a typography object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the **OH_Drawing_Typography** object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|
| size_t offset | Index of the word.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_Range](capi-drawing-oh-drawing-range.md)* | [OH_Drawing_Range](capi-drawing-oh-drawing-range.md) struct that holds the word boundary.|

### OH_Drawing_GetStartFromRange()

```
size_t OH_Drawing_GetStartFromRange(OH_Drawing_Range* range)
```

**Description**

Obtains the start position of an **OH_Drawing_Range** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Range](capi-drawing-oh-drawing-range.md)* range | Pointer to the **OH_Drawing_Range** object, which is obtained from [OH_Drawing_TypographyGetWordBoundary](capi-drawing-text-typography-h.md#oh_drawing_typographygetwordboundary).|

**Returns**

| Type| Description|
| -- | -- |
| size_t | Start position.|

### OH_Drawing_GetEndFromRange()

```
size_t OH_Drawing_GetEndFromRange(OH_Drawing_Range* range)
```

**Description**

Obtains the end position of an **OH_Drawing_Range** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Range](capi-drawing-oh-drawing-range.md)* range | Pointer to the **OH_Drawing_Range** object, which is obtained from [OH_Drawing_TypographyGetWordBoundary](capi-drawing-text-typography-h.md#oh_drawing_typographygetwordboundary).|

**Returns**

| Type| Description|
| -- | -- |
| size_t | End position.|

### OH_Drawing_TypographyGetLineCount()

```
size_t OH_Drawing_TypographyGetLineCount(OH_Drawing_Typography* typography)
```

**Description**

Obtains the number of lines in a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the **OH_Drawing_Typography** object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|

**Returns**

| Type| Description|
| -- | -- |
| size_t | Number of rows obtained.|

### OH_Drawing_SetTextStyleDecorationStyle()

```
void OH_Drawing_SetTextStyleDecorationStyle(OH_Drawing_TextStyle* style, int decorationStyle)
```

**Description**

Sets the decoration style for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| int decorationStyle | Text decoration style. For details about the available options, see [OH_Drawing_TextDecorationStyle](capi-drawing-text-typography-h.md#oh_drawing_textdecorationstyle).|

### OH_Drawing_SetTextStyleDecorationThicknessScale()

```
void OH_Drawing_SetTextStyleDecorationThicknessScale(OH_Drawing_TextStyle* style, double decorationThicknessScale)
```

**Description**

Sets the thickness scale factor for the decoration style of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| double decorationThicknessScale | Thickness scaling ratio. The default value is 1. If the value is less than or equal to 0, no decoration line is drawn.|

### OH_Drawing_SetTextStyleLetterSpacing()

```
void OH_Drawing_SetTextStyleLetterSpacing(OH_Drawing_TextStyle* style, double letterSpacing)
```

**Description**

Sets the letter spacing for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| double letterSpacing | Letter spacing.|

### OH_Drawing_SetTextStyleWordSpacing()

```
void OH_Drawing_SetTextStyleWordSpacing(OH_Drawing_TextStyle* style, double wordSpacing)
```

**Description**

Sets the word spacing for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| double wordSpacing | Letter spacing.|

### OH_Drawing_SetTextStyleHalfLeading()

```
void OH_Drawing_SetTextStyleHalfLeading(OH_Drawing_TextStyle* style, bool halfLeading)
```

**Description**

Sets whether to enable half leading for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| bool halfLeading | Whether the half leading takes effect. **true** means yes; **false** otherwise.|

### OH_Drawing_SetTextStyleEllipsis()

```
void OH_Drawing_SetTextStyleEllipsis(OH_Drawing_TextStyle* style, const char* ellipsis)
```

**Description**

Sets the ellipsis content for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| const char* ellipsis | Pointer to the ellipsis content. The data type is a pointer pointing to char.|

### OH_Drawing_SetTextStyleEllipsisModal()

```
void OH_Drawing_SetTextStyleEllipsisModal(OH_Drawing_TextStyle* style, int ellipsisModal)
```

**Description**

Sets the ellipsis style for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| int ellipsisModal | Sets the ellipsis style. For details about the available options, see [OH_Drawing_EllipsisModal](capi-drawing-text-typography-h.md#oh_drawing_ellipsismodal).|

### OH_Drawing_SetTypographyTextBreakStrategy()

```
void OH_Drawing_SetTypographyTextBreakStrategy(OH_Drawing_TypographyStyle* style, int breakStrategy)
```

**Description**

Sets the text break strategy.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| int breakStrategy | Break strategy. For details about the available options, see [OH_Drawing_BreakStrategy](capi-drawing-text-typography-h.md#oh_drawing_breakstrategy).|

### OH_Drawing_SetTypographyTextWordBreakType()

```
void OH_Drawing_SetTypographyTextWordBreakType(OH_Drawing_TypographyStyle* style, int wordBreakType)
```

**Description**

Sets the word break type.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| int wordBreakType | Word break type. For details about the available options, see [OH_Drawing_WordBreakType](capi-drawing-text-typography-h.md#oh_drawing_wordbreaktype).|

### OH_Drawing_SetTypographyTextEllipsisModal()

```
void OH_Drawing_SetTypographyTextEllipsisModal(OH_Drawing_TypographyStyle* style, int ellipsisModal)
```

**Description**

Sets the ellipsis style for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the **OH_Drawing_TypographyStyle** object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| int ellipsisModal | Ellipsis style. For details about the available options, see [OH_Drawing_EllipsisModal](capi-drawing-text-typography-h.md#oh_drawing_ellipsismodal).|

### OH_Drawing_SetTypographyTextEllipsis()

```
void OH_Drawing_SetTypographyTextEllipsis(OH_Drawing_TypographyStyle* style, const char* ellipsis)
```

**Description**

Sets the ellipsis text for a typography style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| const char* ellipsis | Ellipsis text.|

### OH_Drawing_TypographyGetLineHeight()

```
double OH_Drawing_TypographyGetLineHeight(OH_Drawing_Typography* typography, int lineNumber)
```

**Description**

Obtains the line height in a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the **OH_Drawing_Typography** object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|
| int lineNumber | Target line.|

**Returns**

| Type| Description|
| -- | -- |
| double | Obtains the height of a given line.|

### OH_Drawing_TypographyGetLineWidth()

```
double OH_Drawing_TypographyGetLineWidth(OH_Drawing_Typography* typography, int lineNumber)
```

**Description**

Obtains the line width of a specified line. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the **OH_Drawing_Typography** object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|
| int lineNumber | Target line.|

**Returns**

| Type| Description|
| -- | -- |
| double | Obtains the width of a given line.|

### OH_Drawing_SetTypographyTextSplitRatio()

```
void OH_Drawing_SetTypographyTextSplitRatio(OH_Drawing_TypographyStyle* style, float textSplitRatio)
```

**Description**

Sets the text split ratio.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| float textSplitRatio | Text split ratio.|

### OH_Drawing_TypographyIsLineUnlimited()

```
bool OH_Drawing_TypographyIsLineUnlimited(OH_Drawing_TypographyStyle* style)
```

**Description**

Checks whether the maximum number of lines is limited for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|

**Returns**

| Type| Description|
| -- | -- |
| bool | Returns **true** if that the maximum number of lines is limited; returns **false** otherwise.|

### OH_Drawing_TypographyIsEllipsized()

```
bool OH_Drawing_TypographyIsEllipsized(OH_Drawing_TypographyStyle* style)
```

**Description**

Checks whether an ellipsis is configured for a typography style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|

**Returns**

| Type| Description|
| -- | -- |
| bool | Whether ellipsis is configured for the specified typography style. **true** means yes; **false** otherwise.|

### OH_Drawing_SetTypographyTextLocale()

```
void OH_Drawing_SetTypographyTextLocale(OH_Drawing_TypographyStyle* style, const char* locale)
```

**Description**

Sets the locale for a typography style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| const char* locale | Pointer to the locale. For example, **'en'** indicates English, **'zh-Hans'** indicates Simplified Chinese, and **'zh-Hant'** indicates Traditional Chinese.|

### OH_Drawing_TextStyleGetFontMetrics()

```
bool OH_Drawing_TextStyleGetFontMetrics(OH_Drawing_Typography* typography,OH_Drawing_TextStyle* style, OH_Drawing_Font_Metrics* fontmetrics)
```

**Description**

Obtains the font metrics of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md) object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| [OH_Drawing_Font_Metrics](capi-drawing-oh-drawing-font-metrics.md)* fontmetrics | Pointer to the [OH_Drawing_Font_Metrics](capi-drawing-oh-drawing-font-metrics.md) object, which is obtained from [OH_Drawing_Font_Metrics](capi-drawing-oh-drawing-font-metrics.md).|

**Returns**

| Type| Description|
| -- | -- |
| bool | Whether the font attributes are obtained. **true** means yes; **false** otherwise.|

### OH_Drawing_SetTypographyTextStyle()

```
void OH_Drawing_SetTypographyTextStyle(OH_Drawing_TypographyStyle* handler, OH_Drawing_TextStyle* style)
```

**Description**

Sets a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* handler | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

### OH_Drawing_CreateFontDescriptor()

```
OH_Drawing_FontDescriptor* OH_Drawing_CreateFontDescriptor(void)
```

**Description**

Creates an **OH_Drawing_FontDescriptor** object to describe the detailed information about a system font.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)* | Pointer to the created [OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md) object.|

### OH_Drawing_DestroyFontDescriptor()

```
void OH_Drawing_DestroyFontDescriptor(OH_Drawing_FontDescriptor* descriptor)
```

**Description**

Destroys an **OH_Drawing_FontDescriptor** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md)* descriptor | Pointer to the [OH_Drawing_FontDescriptor](capi-drawing-oh-drawing-fontdescriptor.md) object, which is obtained from [OH_Drawing_CreateFontDescriptor](capi-drawing-text-typography-h.md#oh_drawing_createfontdescriptor).|

### OH_Drawing_CreateFontParser()

```
OH_Drawing_FontParser* OH_Drawing_CreateFontParser(void)
```

**Description**

Creates an **OH_Drawing_FontParser** object to parse a system font.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_FontParser](capi-drawing-oh-drawing-fontparser.md)* | Pointer to the created [OH_Drawing_FontParser](capi-drawing-oh-drawing-fontparser.md) object.|

### OH_Drawing_DestroyFontParser()

```
void OH_Drawing_DestroyFontParser(OH_Drawing_FontParser* parser)
```

**Description**

Destroys an **OH_Drawing_FontParser** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontParser](capi-drawing-oh-drawing-fontparser.md)* parser | Pointer to the [OH_Drawing_FontParser](capi-drawing-oh-drawing-fontparser.md) object, which is obtained from [OH_Drawing_CreateFontParser](capi-drawing-text-typography-h.md#oh_drawing_createfontparser).|

### OH_Drawing_FontParserGetSystemFontList()

```
char** OH_Drawing_FontParserGetSystemFontList(OH_Drawing_FontParser* fontParser, size_t* num)
```

**Description**

Obtains the list of system fonts. This function can be used only on 2-in-1 devices and phones.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontParser](capi-drawing-oh-drawing-fontparser.md)* fontParser | Pointer to the [OH_Drawing_FontParser](capi-drawing-oh-drawing-fontparser.md) object, which is obtained from [OH_Drawing_CreateFontParser](capi-drawing-text-typography-h.md#oh_drawing_createfontparser).|
| size_t* num | Pointer to the number of system font names.|

**Returns**

| Type| Description|
| -- | -- |
| char** | System font list.|

### OH_Drawing_DestroySystemFontList()

```
void OH_Drawing_DestroySystemFontList(char** fontList, size_t num)
```

**Description**

Reclaims the memory occupied by the system font list.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| char** fontList | Double pointer to the list of system font names.|
| size_t num | Number of system font names.|

### OH_Drawing_FontParserGetFontByName()

```
OH_Drawing_FontDescriptor* OH_Drawing_FontParserGetFontByName(OH_Drawing_FontParser* fontParser, const char* name)
```

**Description**

Obtains the descriptor of a system font based on the font name.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontParser](capi-drawing-oh-drawing-fontparser.md)* fontParser | Pointer to the [OH_Drawing_FontParser](capi-drawing-oh-drawing-fontparser.md) object, which is obtained from [OH_Drawing_CreateFontParser](capi-drawing-text-typography-h.md#oh_drawing_createfontparser).|
| const char* name | Pointer to the system font name.|

**Returns**

| Type| Description|
| -- | -- |
| OH_Drawing_FontDescriptor* | Font descriptor object. Release this pointer by calling [OH_Drawing_DestroyFontParser](capi-drawing-text-typography-h.md#oh_drawing_destroyfontparser) when this object is no longer needed.|

### OH_Drawing_TypographyGetLineMetrics()

```
OH_Drawing_LineMetrics* OH_Drawing_TypographyGetLineMetrics(OH_Drawing_Typography* typography)
```

**Description**

Obtains the line metrics in a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called. Release this pointer by calling [OH_Drawing_DestroyLineMetrics](capi-drawing-text-typography-h.md#oh_drawing_destroylinemetrics) when this object is no longer needed.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md) object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md)* | Pointer to the [OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md) object.|

### OH_Drawing_LineMetricsGetSize()

```
size_t OH_Drawing_LineMetricsGetSize(OH_Drawing_LineMetrics* lineMetrics)
```

**Description**

Obtains the number of lines.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md)* lineMetrics | Pointer to the [OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md) object, which is obtained from [OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md).|

**Returns**

| Type| Description|
| -- | -- |
| size_t | Number of lines.|

### OH_Drawing_DestroyLineMetrics()

```
void OH_Drawing_DestroyLineMetrics(OH_Drawing_LineMetrics* lineMetrics)
```

**Description**

Destroys an **OH_Drawing_LineMetrics** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md)* lineMetrics | Pointer to the [OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md) object, which is obtained from [OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md).|

### OH_Drawing_TypographyGetLineMetricsAt()

```
bool OH_Drawing_TypographyGetLineMetricsAt(OH_Drawing_Typography* typography,int lineNumber, OH_Drawing_LineMetrics* lineMetric)
```

**Description**

Obtains the metrics of the given line in a typography object. For details, see the [OH_Drawing_LineMetr](capi-drawing-oh-drawing-linemetrics.md) struct. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md) object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|
| int lineNumber | Line No.|
| [OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md)* lineMetric | Pointer to the [OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md) object, which is obtained from [OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md).|

**Returns**

| Type| Description|
| -- | -- |
| bool | Whether the metrics of the given line is obtained. **true** means yes; **false** otherwise.|

### OH_Drawing_TypographyGetLineInfo()

```
bool OH_Drawing_TypographyGetLineInfo(OH_Drawing_Typography* typography, int lineNumber, bool oneLine,bool includeWhitespace, OH_Drawing_LineMetrics* drawingLineMetrics)
```

**Description**

Obtains the metrics of a given line or the metrics of the first character in a given line in a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md) object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|
| int lineNumber | Row No.|
| bool oneLine | Whether to obtain the metrics of the entire line. The value **true** means to obtain the metrics of the entire line, and **false** means to obtain the metrics of the first character in the line.|
| bool includeWhitespace | Whether the text width includes the whitespace. **true** means yes; **false** otherwise.|
| [OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md)* drawingLineMetrics | Pointer to the [OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md) object, which is obtained from [OH_Drawing_LineMetrics](capi-drawing-oh-drawing-linemetrics.md).|

**Returns**

| Type| Description|
| -- | -- |
| bool | Returns **true** if the metrics of the given line or the metrics of the first character in the given line is obtained; returns **false** otherwise.|

### OH_Drawing_SetTypographyTextFontWeight()

```
void OH_Drawing_SetTypographyTextFontWeight(OH_Drawing_TypographyStyle* style, int weight)
```

**Description**

Sets the default font weight for a typography style. Currently, only the default system font supports font weight adjustment. For other fonts, if the weight is less than semi-bold, there is no variation in stroke thickness. If the weight is greater than or equal to semi-bold, it might result in a fake bold effect.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| int weight | Font weight.<br>For details about the available options, see [OH_Drawing_FontWeight](capi-drawing-text-typography-h.md#oh_drawing_fontweight).|

### OH_Drawing_SetTypographyTextFontStyle()

```
void OH_Drawing_SetTypographyTextFontStyle(OH_Drawing_TypographyStyle* style, int fontStyle)
```

**Description**

Sets the default font style for a typography style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| int fontStyle | Font style. For details about the available options, see [OH_Drawing_FontStyle](capi-drawing-text-typography-h.md#oh_drawing_fontstyle).|

### OH_Drawing_SetTypographyTextFontFamily()

```
void OH_Drawing_SetTypographyTextFontFamily(OH_Drawing_TypographyStyle* style, const char* fontFamily)
```

**Description**

Sets the font family name for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| const char* fontFamily | Pointer to the name of the font family.|

### OH_Drawing_SetTypographyTextFontSize()

```
void OH_Drawing_SetTypographyTextFontSize(OH_Drawing_TypographyStyle* style, double fontSize)
```

**Description**

Sets the font size for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| double fontSize | Font size, which must be greater than 0.|

### OH_Drawing_SetTypographyTextFontHeight()

```
void OH_Drawing_SetTypographyTextFontHeight(OH_Drawing_TypographyStyle* style, double fontHeight)
```

**Description**

Sets the font height for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| double fontHeight | Font height.|

### OH_Drawing_SetTypographyTextHalfLeading()

```
void OH_Drawing_SetTypographyTextHalfLeading(OH_Drawing_TypographyStyle* style, bool halfLeading)
```

**Description**

Sets whether to enable half leading for text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| bool halfLeading | Whether to enable half leading. The value **true** means to enable half lading, and **false** means the opposite.|

### OH_Drawing_SetTypographyTextUseLineStyle()

```
void OH_Drawing_SetTypographyTextUseLineStyle(OH_Drawing_TypographyStyle* style, bool useLineStyle)
```

**Description**

Sets whether to enable the text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| bool useLineStyle | Whether to enable the line style. The value **true** means to enable the line style, and **false** means the opposite.|

### OH_Drawing_SetTypographyTextLineStyleFontWeight()

```
void OH_Drawing_SetTypographyTextLineStyleFontWeight(OH_Drawing_TypographyStyle* style, int weight)
```

**Description**

Sets the text font weight of the strut style in a typography style. Currently, only the default system font supports font weight adjustment. For other fonts, if the weight is less than semi-bold, there is no variation in stroke thickness. If the weight is greater than or equal to semi-bold, it might result in a fake bold effect.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| int weight | Font weight. For details about the available options, see [OH_Drawing_FontWeight](capi-drawing-text-typography-h.md#oh_drawing_fontweight).|

### OH_Drawing_SetTypographyTextLineStyleFontStyle()

```
void OH_Drawing_SetTypographyTextLineStyleFontStyle(OH_Drawing_TypographyStyle* style, int fontStyle)
```

**Description**

Sets the font style of the strut style in a typography style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| int fontStyle | Font style. For details about the available options, see [OH_Drawing_FontStyle](capi-drawing-text-typography-h.md#oh_drawing_fontstyle).|

### OH_Drawing_SetTypographyTextLineStyleFontFamilies()

```
void OH_Drawing_SetTypographyTextLineStyleFontFamilies(OH_Drawing_TypographyStyle* style,int fontFamiliesNumber, const char* fontFamilies[])
```

**Description**

Sets the font families for a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| int fontFamiliesNumber | Number of font families.|
| fontFamilies |  Pointer to the font families.|

### OH_Drawing_SetTypographyTextLineStyleFontSize()

```
void OH_Drawing_SetTypographyTextLineStyleFontSize(OH_Drawing_TypographyStyle* style, double lineStyleFontSize)
```

**Description**

Sets the font size for a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| double lineStyleFontSize | Font size, which must be greater than 0.|

### OH_Drawing_SetTypographyTextLineStyleFontHeight()

```
void OH_Drawing_SetTypographyTextLineStyleFontHeight(OH_Drawing_TypographyStyle* style, double lineStyleFontHeight)
```

**Description**

Sets the font height for a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| double lineStyleFontHeight | Font height.|

### OH_Drawing_SetTypographyTextLineStyleHalfLeading()

```
void OH_Drawing_SetTypographyTextLineStyleHalfLeading(OH_Drawing_TypographyStyle* style, bool lineStyleHalfLeading)
```

**Description**

Sets whether to enable half leading for a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| bool lineStyleHalfLeading | Whether the half leading takes effect. **true** means yes; **false** otherwise.|

### OH_Drawing_SetTypographyTextLineStyleSpacingScale()

```
void OH_Drawing_SetTypographyTextLineStyleSpacingScale(OH_Drawing_TypographyStyle* style, double spacingScale)
```

**Description**

Sets the spacing scale factor for a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| double spacingScale | Spacing ratio.|

### OH_Drawing_SetTypographyTextLineStyleOnly()

```
void OH_Drawing_SetTypographyTextLineStyleOnly(OH_Drawing_TypographyStyle* style, bool lineStyleOnly)
```

**Description**

Sets whether to enable the text line style only.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| bool lineStyleOnly | Whether to enable the line style only. **true** means yes; **false** otherwise.|

### OH_Drawing_CreateTextShadow()

```
OH_Drawing_TextShadow* OH_Drawing_CreateTextShadow(void)
```

**Description**

Creates an **OH_Drawing_TextShadow** object. Release this pointer by calling [OH_Drawing_DestroyTextShadow](capi-drawing-text-typography-h.md#oh_drawing_destroytextshadow) when this object is no longer needed.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)* | Pointer to the **OH_Drawing_TextShadow** object created.|

### OH_Drawing_DestroyTextShadow()

```
void OH_Drawing_DestroyTextShadow(OH_Drawing_TextShadow* shadow)
```

**Description**

Destroys an **OH_Drawing_TextShadow** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)* shadow | Pointer to the [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md) object, which is obtained from [OH_Drawing_CreateTextShadow](capi-drawing-text-typography-h.md#oh_drawing_createtextshadow).|

### OH_Drawing_TextStyleGetShadows()

```
OH_Drawing_TextShadow* OH_Drawing_TextStyleGetShadows(OH_Drawing_TextStyle* style)
```

**Description**

Obtains a text shadow container. Release this pointer by calling [OH_Drawing_DestroyTextShadows](capi-drawing-text-typography-h.md#oh_drawing_destroytextshadows) when this object is no longer needed.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)* | Pointer to the [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md) object.|

### OH_Drawing_TextStyleGetShadowCount()

```
int OH_Drawing_TextStyleGetShadowCount(OH_Drawing_TextStyle* style)
```

**Description**

Obtains the size of a text shadow container.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

**Returns**

| Type| Description|
| -- | -- |
| int | Size of a text shadow container.|

### OH_Drawing_TextStyleAddShadow()

```
void OH_Drawing_TextStyleAddShadow(OH_Drawing_TextStyle* style, const OH_Drawing_TextShadow* shadow)
```

**Description**

Adds a shadow to a text shadow container.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| const [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)* shadow | Pointer to the [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md) object, which is obtained from [OH_Drawing_CreateTextShadow](capi-drawing-text-typography-h.md#oh_drawing_createtextshadow).|

### OH_Drawing_TextStyleClearShadows()

```
void OH_Drawing_TextStyleClearShadows(OH_Drawing_TextStyle* style)
```

**Description**

Clears all shadows in a text shadow container.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

### OH_Drawing_TextStyleGetShadowWithIndex()

```
OH_Drawing_TextShadow* OH_Drawing_TextStyleGetShadowWithIndex(OH_Drawing_TextStyle* style, int index)
```

**Description**

Obtains a shadow with a given index in a text shadow container.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| int index | Index.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)* | Pointer to the [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md) object.|

### OH_Drawing_TypographySetIndents()

```
void OH_Drawing_TypographySetIndents(OH_Drawing_Typography* typography, int indentsNumber, const float indents[])
```

**Description**

Sets indents for typography. If this function is not called, texts will have no indentation applied.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md) object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|
| int indentsNumber | Number of indents. The value must be less than or equal to the length of the indents array to avoid display exceptions caused by access to the out-of-bounds array.|
| indents |  Pointer to a floating-point array, in which each element indicates an indentation width, in px. Before calling [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md) API, you need to declare and initialize the floating-point array.|

### OH_Drawing_TypographyGetIndentsWithIndex()

```
float OH_Drawing_TypographyGetIndentsWithIndex(OH_Drawing_Typography* typography, int index)
```

**Description**

Obtains indents with a given index in a typography object. The line index starts from 0.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md) object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|
| int index | Index.|

**Returns**

| Type| Description|
| -- | -- |
| float | Indents.|

### OH_Drawing_TypographyGetLineTextRange()

```
OH_Drawing_Range* OH_Drawing_TypographyGetLineTextRange(OH_Drawing_Typography* typography,int lineNumber, bool includeSpaces)
```

**Description**

Obtains the line bounds in a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called. This function can only be used to obtain the bounds of existing lines. That is, the line index must start from 0, and the maximum index is [OH_Drawing_TypographyGetLineCount](capi-drawing-text-typography-h.md#oh_drawing_typographygetlinecount) - 1.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md) object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|
| int lineNumber | Row index.|
| bool includeSpaces | Whether the returned bounds contain spaces. The value **true** means that the bounds contain spaces, and **false** means the opposite.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_Range](capi-drawing-oh-drawing-range.md)* | Pointer to the [OH_Drawing_Range](capi-drawing-oh-drawing-range.md) object. If the line index is invalid, **start** and **end** in the result value are both **0**.|

### OH_Drawing_DestroyTextShadows()

```
void OH_Drawing_DestroyTextShadows(OH_Drawing_TextShadow* shadow)
```

**Description**

Reclaims the memory occupied by the vector consisting of the **OH_Drawing_TextShadow** objects.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)* shadow | Pointer to the [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md) object, which is obtained from [OH_Drawing_CreateTextShadow](capi-drawing-text-typography-h.md#oh_drawing_createtextshadow).|

### OH_Drawing_GetSystemFontConfigInfo()

```
OH_Drawing_FontConfigInfo* OH_Drawing_GetSystemFontConfigInfo(OH_Drawing_FontConfigInfoErrorCode* errorCode)
```

**Description**

Obtains the system font configuration.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontConfigInfoErrorCode](#oh_drawing_fontconfiginfoerrorcode)* errorCode | Error code. For details, see [OH_Drawing_FontConfigInfoErrorCode](capi-drawing-text-typography-h.md#oh_drawing_fontconfiginfoerrorcode).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_FontConfigInfo](capi-drawing-oh-drawing-fontconfiginfo.md)* | Pointer to the system font configuration. When it is no longer required, call [OH_Drawing_DestroySystemFontConfigInfo](capi-drawing-text-typography-h.md#oh_drawing_destroysystemfontconfiginfo) to release the pointer to the object.|

### OH_Drawing_DestroySystemFontConfigInfo()

```
void OH_Drawing_DestroySystemFontConfigInfo(OH_Drawing_FontConfigInfo* drawFontCfgInfo)
```

**Description**

Reclaims the memory occupied by the system font configuration.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontConfigInfo](capi-drawing-oh-drawing-fontconfiginfo.md)* drawFontCfgInfo | Pointer to the [OH_Drawing_FontConfigInfo](capi-drawing-oh-drawing-fontconfiginfo.md) object, which is obtained from [OH_Drawing_GetSystemFontConfigInfo](capi-drawing-text-typography-h.md#oh_drawing_getsystemfontconfiginfo).|

### OH_Drawing_SetTextStyleFontStyleStruct()

```
void OH_Drawing_SetTextStyleFontStyleStruct(OH_Drawing_TextStyle* drawingTextStyle,OH_Drawing_FontStyleStruct fontStyle)
```

**Description**

Sets the font style, including the font weight, width, and slant, for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* drawingTextStyle | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| [OH_Drawing_FontStyleStruct](capi-drawing-oh-drawing-fontstylestruct.md) fontStyle | Font style, including the font weight, width, and slant.|

### OH_Drawing_SetTextStyleBadgeType()

```
void OH_Drawing_SetTextStyleBadgeType(OH_Drawing_TextStyle* style, OH_Drawing_TextBadgeType textBadgeType)
```

**Description**

Sets whether to use superscript or subscript in text layout. If this API is not called, the feature is disabled by default.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| [OH_Drawing_TextBadgeType](#oh_drawing_textbadgetype) textBadgeType | Sets whether to use superscript or subscript in text layout. **TEXT_SUPERSCRIPT** indicates that superscript is enabled, and **TEXT_SUBSCRIPT** indicates that subscript is enabled. The default value is **TEXT_BADGE_NONE**, indicating that neither superscript nor subscript is enabled.|

### OH_Drawing_TextStyleGetFontStyleStruct()

```
OH_Drawing_FontStyleStruct OH_Drawing_TextStyleGetFontStyleStruct(OH_Drawing_TextStyle* drawingTextStyle)
```

**Description**

Obtains the font style, including the font weight, width, and slant, of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* drawingTextStyle | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_FontStyleStruct](capi-drawing-oh-drawing-fontstylestruct.md) | Font style, including the font weight, width, and slant.|

### OH_Drawing_SetTypographyStyleFontStyleStruct()

```
void OH_Drawing_SetTypographyStyleFontStyleStruct(OH_Drawing_TypographyStyle* drawingStyle,OH_Drawing_FontStyleStruct fontStyle)
```

**Description**

Sets the font style, including the font weight, width, and slant, for the default text style of a typography style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* drawingStyle | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| [OH_Drawing_FontStyleStruct](capi-drawing-oh-drawing-fontstylestruct.md) fontStyle | Font style, including the font weight, width, and slant.|

### OH_Drawing_TypographyStyleGetFontStyleStruct()

```
OH_Drawing_FontStyleStruct OH_Drawing_TypographyStyleGetFontStyleStruct(OH_Drawing_TypographyStyle* drawingStyle)
```

**Description**

Obtains the font style, including the font weight, width, and slant, of the default text style of a typography style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* drawingStyle | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_FontStyleStruct](capi-drawing-oh-drawing-fontstylestruct.md) | Font style, including the font weight, width, and slant.|

### OH_Drawing_TextStyleSetBackgroundRect()

```
void OH_Drawing_TextStyleSetBackgroundRect(OH_Drawing_TextStyle* style,const OH_Drawing_RectStyle_Info* rectStyleInfo, int styleId)
```

**Description**

Sets a background rectangle and style ID for a text style. The style ID is valid only when the background box is a rounded rectangle.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| const [OH_Drawing_RectStyle_Info](capi-drawing-oh-drawing-rectstyle-info.md)* rectStyleInfo | Pointer to the [OH_Drawing_RectStyle_Info](capi-drawing-oh-drawing-rectstyle-info.md) object.|
| int styleId | Style ID. The style ID is valid only when the background box is a rounded rectangle. Text processing is divided into multiple segments. Each segment has its own text style. **id** indicates the sequence number of the background box in which the segment is drawn.<br>If the ID of each segment in a row is 0, all segments are drawn in the same background box. If the IDs in a row are 0 and 1, the segment whose ID is 0 is drawn in a background box, the segment whose ID is 1 is drawn in another background box. Other cases can be deduced in the same way.|

### OH_Drawing_TypographyHandlerAddSymbol()

```
void OH_Drawing_TypographyHandlerAddSymbol(OH_Drawing_TypographyCreate* handler, uint32_t symbol)
```

**Description**

Adds the symbol to use in the typography creation process.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)* handler | Pointer to the [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md) object, which is obtained from [OH_Drawing_CreateTypographyHandler](capi-drawing-text-typography-h.md#oh_drawing_createtypographyhandler).|
| uint32_t symbol | Symbol value. For details, see the Unicode value in the [HarmonyOS Symbol library](https://developer.huawei.com/consumer/en/design/harmonyos-symbol/).|

### OH_Drawing_TextStyleAddFontFeature()

```
void OH_Drawing_TextStyleAddFontFeature(OH_Drawing_TextStyle* style, const char* tag, int value)
```

**Description**

Adds a font feature for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| const char* tag | Pointer to the string identified by the keyword in the font feature key-value pair.|
| int value | Value of the font feature key-value pair.|

### OH_Drawing_TextStyleAddFontVariation()

```
void OH_Drawing_TextStyleAddFontVariation(OH_Drawing_TextStyle* style, const char* axis, const float value)
```

**Description**

Adds a font variation. This function takes effect only when the corresponding font file (.ttf file) supports variable adjustment. Otherwise, calling this function does not take effect.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| const char* axis | Pointer to the key in the font variation key-value pair. Currently, only **'wght'** is supported, indicating the font weight.|
| const float value | Value of the font variation key-value pair. Currently, the value range of **'wght'** for the default font is \[0,900\].|

### OH_Drawing_TextStyleGetFontFeatures()

```
OH_Drawing_FontFeature* OH_Drawing_TextStyleGetFontFeatures(OH_Drawing_TextStyle* style)
```

**Description**

Obtains all the contents in a font feature map container of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_FontFeature](capi-drawing-oh-drawing-fontfeature.md)* | Pointer to the font feature struct, which stores all the contents obtained.|

### OH_Drawing_TextStyleDestroyFontFeatures()

```
void OH_Drawing_TextStyleDestroyFontFeatures(OH_Drawing_FontFeature* fontFeature, size_t fontFeatureSize)
```

**Description**

Reclaims the memory occupied by the struct array that holds all the font features.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontFeature](capi-drawing-oh-drawing-fontfeature.md)* fontFeature | Pointer to the struct array that holds all the font features, which is obtained from [OH_Drawing_TextStyleGetFontFeatures](capi-drawing-text-typography-h.md#oh_drawing_textstylegetfontfeatures).|
| size_t fontFeatureSize | Size of the struct array that holds all the font features.|

### OH_Drawing_TextStyleGetFontFeatureSize()

```
size_t OH_Drawing_TextStyleGetFontFeatureSize(OH_Drawing_TextStyle* style)
```

**Description**

Obtains the size of a font feature map container in a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

**Returns**

| Type| Description|
| -- | -- |
| size_t | Size of a font feature map container.|

### OH_Drawing_TextStyleClearFontFeature()

```
void OH_Drawing_TextStyleClearFontFeature(OH_Drawing_TextStyle* style)
```

**Description**

Clears all the contents in a font feature map container of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

### OH_Drawing_TextStyleGetBaselineShift()

```
double OH_Drawing_TextStyleGetBaselineShift(OH_Drawing_TextStyle* style)
```

**Description**

Obtains the baseline drift of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

**Returns**

| Type| Description|
| -- | -- |
| double | Baseline shift.|

### OH_Drawing_TextStyleSetBaselineShift()

```
void OH_Drawing_TextStyleSetBaselineShift(OH_Drawing_TextStyle* style, double lineShift)
```

**Description**

Sets a baseline drift for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the **OH_Drawing_TextStyle** object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| double lineShift | Baseline drift of the text style.|

### OH_Drawing_TypographyTextSetHeightBehavior()

```
void OH_Drawing_TypographyTextSetHeightBehavior(OH_Drawing_TypographyStyle* style,OH_Drawing_TextHeightBehavior heightMode)
```

**Description**

Sets a text height modifier pattern.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| [OH_Drawing_TextHeightBehavior](#oh_drawing_textheightbehavior) heightMode | Text height modifier mode. The value is an enumerated value of the [OH_Drawing_TextHeightBehavior](capi-drawing-text-typography-h.md#oh_drawing_textheightbehavior) type.|

### OH_Drawing_TypographyTextGetHeightBehavior()

```
OH_Drawing_TextHeightBehavior OH_Drawing_TypographyTextGetHeightBehavior(OH_Drawing_TypographyStyle* style)
```

**Description**

Obtains the text height modifier pattern.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextHeightBehavior](#oh_drawing_textheightbehavior) | Text height modifier mode, which is an enumerated value of the [OH_Drawing_TextHeightBehavior](capi-drawing-text-typography-h.md#oh_drawing_textheightbehavior) type.|

### OH_Drawing_TypographyGetLineFontMetrics()

```
OH_Drawing_Font_Metrics* OH_Drawing_TypographyGetLineFontMetrics(OH_Drawing_Typography* typography,size_t lineNumber, size_t* fontMetricsSize)
```

**Description**

Obtains all font metrics from a given line in a typography object. This function must be called after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called. Otherwise, a null pointer is returned. Release this pointer by calling [OH_Drawing_TypographyDestroyLineFontMetrics](capi-drawing-text-typography-h.md#oh_drawing_typographydestroylinefontmetrics) when this object is no longer needed.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md) object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|
| size_t lineNumber | Line number, which is an integer. The minimum value is 1, and the maximum value depends on the number of lines parsed by the font engine after text input. If a value greater than the maximum number is passed in, an error value is returned and an error message is printed.|
| size_t* fontMetricsSize | Pointer to the size of the struct.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_Font_Metrics](capi-drawing-oh-drawing-font-metrics.md)* | Returns all the font metrics.|

### OH_Drawing_TypographyDestroyLineFontMetrics()

```
void OH_Drawing_TypographyDestroyLineFontMetrics(OH_Drawing_Font_Metrics* lineFontMetric)
```

**Description**

Reclaims the memory occupied by the struct array that holds all the font metrics of a given line.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Font_Metrics](capi-drawing-oh-drawing-font-metrics.md)* lineFontMetric | Pointer to the first address of the struct array.|

### OH_Drawing_TextStyleIsEqual()

```
bool OH_Drawing_TextStyleIsEqual(const OH_Drawing_TextStyle* style, const OH_Drawing_TextStyle* comparedStyle)
```

**Description**

Checks whether two text styles are equal. The word width property is not involved in the comparison.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the first text style.|
| const [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* comparedStyle | Pointer to the first text style.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Whether two text style objects are equal. **true** if the source rectangle is equal to the destination rectangle; **false** otherwise.|

### OH_Drawing_TextStyleIsEqualByFont()

```
bool OH_Drawing_TextStyleIsEqualByFont(const OH_Drawing_TextStyle* style, const OH_Drawing_TextStyle* comparedStyle)
```

**Description**

Checks whether the font style properties of two text styles are equal.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the first text style.|
| const [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* comparedStyle | Pointer to the first text style.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Returns **true** if the two are equal; returns **false** otherwise.|

### OH_Drawing_TextStyleIsAttributeMatched()

```
bool OH_Drawing_TextStyleIsAttributeMatched(const OH_Drawing_TextStyle* style,const OH_Drawing_TextStyle* comparedStyle, OH_Drawing_TextStyleType textStyleType)
```

**Description**

Checks whether two text styles have the same font style type.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the first text style.|
| const [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* comparedStyle | Pointer to the first text style.|
| [OH_Drawing_TextStyleType](#oh_drawing_textstyletype) textStyleType | Text style types as in [OH_Drawing_TextStyleType](capi-drawing-text-typography-h.md#oh_drawing_textstyletype).|

**Returns**

| Type| Description|
| -- | -- |
| bool | Whether two text styles have the same font style type. **true** means yes; **false** otherwise.|

### OH_Drawing_TextStyleSetPlaceholder()

```
void OH_Drawing_TextStyleSetPlaceholder(OH_Drawing_TextStyle* style)
```

**Description**

Adds a placeholder.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

### OH_Drawing_TextStyleIsPlaceholder()

```
bool OH_Drawing_TextStyleIsPlaceholder(OH_Drawing_TextStyle* style)
```

**Description**

Checks whether a placeholder is set for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

**Returns**

| Type| Description|
| -- | -- |
| bool | Checks whether a placeholder is set for a text style. **true** means yes; **false** otherwise.|

### OH_Drawing_TypographyStyleGetEffectiveAlignment()

```
OH_Drawing_TextAlign OH_Drawing_TypographyStyleGetEffectiveAlignment(OH_Drawing_TypographyStyle* style)
```

**Description**

Obtains the text alignment mode.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextAlign](#oh_drawing_textalign) | Text alignment modes as in [OH_Drawing_TextAlign](capi-drawing-text-typography-h.md#oh_drawing_textalign).|

### OH_Drawing_TypographyStyleIsHintEnabled()

```
bool OH_Drawing_TypographyStyleIsHintEnabled(OH_Drawing_TypographyStyle* style)
```

**Description**

Checks whether font hinting is enabled for a typography style. Font hinting is used to improve the readability and appearance of small-sized text when rendering it.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|

**Returns**

| Type| Description|
| -- | -- |
| bool | Whether to enable font hinting for a typography style. **true**: enabled; **false**: disabled.|

### OH_Drawing_SetTypographyStyleTextStrutStyle()

```
void OH_Drawing_SetTypographyStyleTextStrutStyle(OH_Drawing_TypographyStyle* style, OH_Drawing_StrutStyle* strutstyle)
```

**Description**

Sets the strut style for a typography style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| [OH_Drawing_StrutStyle](capi-drawing-oh-drawing-strutstyle.md)* strutstyle | Pointer to the [OH_Drawing_StrutStyle](capi-drawing-oh-drawing-strutstyle.md) object, which is obtained from [OH_Drawing_TypographyStyleGetStrutStyle](capi-drawing-text-typography-h.md#oh_drawing_typographystylegetstrutstyle).|

### OH_Drawing_TypographyStyleGetStrutStyle()

```
OH_Drawing_StrutStyle* OH_Drawing_TypographyStyleGetStrutStyle(OH_Drawing_TypographyStyle* style)
```

**Description**

Obtains the strut style of a typography style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_StrutStyle](capi-drawing-oh-drawing-strutstyle.md)* | Pointer to the [OH_Drawing_StrutStyle](capi-drawing-oh-drawing-strutstyle.md) object.|

### OH_Drawing_TypographyStyleDestroyStrutStyle()

```
void OH_Drawing_TypographyStyleDestroyStrutStyle(OH_Drawing_StrutStyle* strutstyle)
```

**Description**

Reclaims the memory occupied by a strut style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_StrutStyle](capi-drawing-oh-drawing-strutstyle.md)* strutstyle | Pointer to the [OH_Drawing_StrutStyle](capi-drawing-oh-drawing-strutstyle.md) object, which is obtained from [OH_Drawing_TypographyStyleGetStrutStyle](capi-drawing-text-typography-h.md#oh_drawing_typographystylegetstrutstyle).|

### OH_Drawing_TypographyStyleStrutStyleEquals()

```
bool OH_Drawing_TypographyStyleStrutStyleEquals(OH_Drawing_StrutStyle* from, OH_Drawing_StrutStyle* to)
```

**Description**

Checks whether two strut styles are equal.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_StrutStyle](capi-drawing-oh-drawing-strutstyle.md)* from | Pointer to the first strut style.|
| [OH_Drawing_StrutStyle](capi-drawing-oh-drawing-strutstyle.md)* to | Pointer to the second strut style.|

### OH_Drawing_TypographyStyleSetHintsEnabled()

```
void OH_Drawing_TypographyStyleSetHintsEnabled(OH_Drawing_TypographyStyle* style, bool hintsEnabled)
```

**Description**

Sets whether to enable font hinting for a typography style. Font hinting is used to improve the readability and appearance of small-sized text when rendering it.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| bool hintsEnabled | Whether to enable font hinting. **true**: enabled; **false**: disabled.|

### OH_Drawing_TypographyMarkDirty()

```
void  OH_Drawing_TypographyMarkDirty(OH_Drawing_Typography* typography)
```

**Description**

Marks a typography object as dirty data. This function is used to initialize the typography state.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md) object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|

### OH_Drawing_TypographyGetUnresolvedGlyphsCount()

```
int32_t OH_Drawing_TypographyGetUnresolvedGlyphsCount(OH_Drawing_Typography* typography)
```

**Description**

Obtains the number of unresolved glyphs in a typography object. This function can be called only after [OH_Drawing_TypographyLayout](capi-drawing-text-typography-h.md#oh_drawing_typographylayout) is called and applied.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md) object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Number of unresolved glyphs.|

### OH_Drawing_TypographyUpdateFontSize()

```
void OH_Drawing_TypographyUpdateFontSize(OH_Drawing_Typography* typography, size_t from, size_t to, float fontSize)
```

**Description**

Updates the font size in a typography object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md) object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|
| size_t from | Reserved field, which is not used.|
| size_t to | Reserved field, which is not used.|
| float fontSize | New font size.|

### OH_Drawing_TypographyUpdateFontColor()

```
void OH_Drawing_TypographyUpdateFontColor(OH_Drawing_Typography* typography, uint32_t color)
```

**Description**

Updates the font color in a typography object. This API call also updates the decoration color if it hasn't been set yet. The updated font color takes effect after you call [OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint) to draw the text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md) object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|
| uint32_t color | New font color.|

### OH_Drawing_TypographyUpdateDecoration()

```
void OH_Drawing_TypographyUpdateDecoration(OH_Drawing_Typography* typography, OH_Drawing_TextDecoration decoration)
```

**Description**

Updates the decoration type of a typography object. The updated decoration type takes effect after you call [OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint) to draw the text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md) object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|
| [OH_Drawing_TextDecoration](#oh_drawing_textdecoration) decoration | Updated decoration type. For details, see [OH_Drawing_TextDecoration](capi-drawing-text-typography-h.md#oh_drawing_textdecoration). You can set multiple text decoration types at a time via bitwise OR operations. If a decoration type that is not in the [OH_Drawing_TextDecoration](capi-drawing-text-typography-h.md#oh_drawing_textdecoration) enumeration is set, the original decoration is retained.|

### OH_Drawing_TypographyUpdateDecorationThicknessScale()

```
void OH_Drawing_TypographyUpdateDecorationThicknessScale(OH_Drawing_Typography* typography,double decorationThicknessScale)
```

**Description**

Updates the decoration thickness scale of a typography object. The updated decoration thickness scale takes effect after you call [OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint) to draw the text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md) object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|
| double decorationThicknessScale | Thickness scaling ratio of the updated text decoration line. The thickness of the decoration line increases as the ratio increases. If the value is less than or equal to 0, the decoration line will not be drawn.|

### OH_Drawing_TypographyUpdateDecorationStyle()

```
void OH_Drawing_TypographyUpdateDecorationStyle(OH_Drawing_Typography* typography,OH_Drawing_TextDecorationStyle decorationStyle)
```

**Description**

Updates the decoration style of a typography object. The updated decoration style takes effect after you call [OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint) to draw the text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md) object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|
| [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle) decorationStyle | Updated text decoration style. For details about the available options, see [OH_Drawing_TextDecorationStyle](capi-drawing-text-typography-h.md#oh_drawing_textdecorationstyle).|

### OH_Drawing_TypographyTextGetLineStyle()

```
bool OH_Drawing_TypographyTextGetLineStyle(OH_Drawing_TypographyStyle* style)
```

**Description**

Checks whether the text line style is enabled for a typography style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|

**Returns**

| Type| Description|
| -- | -- |
| bool | Whether the line style is enabled. **true**: enabled; **false**: disabled.|

### OH_Drawing_TypographyTextlineStyleGetFontWeight()

```
OH_Drawing_FontWeight OH_Drawing_TypographyTextlineStyleGetFontWeight(OH_Drawing_TypographyStyle* style)
```

**Description**

Obtains the font weight of a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_FontWeight](#oh_drawing_fontweight) | Font weight.<br> For details about the available options, see [OH_Drawing_FontWeight](capi-drawing-text-typography-h.md#oh_drawing_fontweight).|

### OH_Drawing_TypographyTextlineStyleGetFontStyle()

```
OH_Drawing_FontStyle OH_Drawing_TypographyTextlineStyleGetFontStyle(OH_Drawing_TypographyStyle* style)
```

**Description**

Obtains the font style of the strut style in a typography style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_FontStyle](#oh_drawing_fontstyle) | Font style of the strut style in a typography style. **1** indicates italic, and **0** or others indicate non-italic. For details, see the [OH_Drawing_FontStyle](capi-drawing-text-typography-h.md#oh_drawing_fontstyle) enumeration.|

### OH_Drawing_TypographyTextlineStyleGetFontFamilies()

```
char** OH_Drawing_TypographyTextlineStyleGetFontFamilies(OH_Drawing_TypographyStyle* style, size_t* num)
```

**Description**

Obtains the font families of a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| size_t* num | Pointer to the number of font families.|

**Returns**

| Type| Description|
| -- | -- |
| char** | Font families.|

### OH_Drawing_TypographyTextlineStyleDestroyFontFamilies()

```
void OH_Drawing_TypographyTextlineStyleDestroyFontFamilies(char** fontFamilies, size_t fontFamiliesNum)
```

**Description**

Reclaims the memory occupied by the font families.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| char** fontFamilies | Pointer to the font families.|
| size_t fontFamiliesNum | Number of font families.|

### OH_Drawing_TypographyTextlineStyleGetFontSize()

```
double OH_Drawing_TypographyTextlineStyleGetFontSize(OH_Drawing_TypographyStyle* style)
```

**Description**

Obtains the font size of a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|

**Returns**

| Type| Description|
| -- | -- |
| double | Font size.|

### OH_Drawing_TypographyTextlineStyleGetHeightScale()

```
double OH_Drawing_TypographyTextlineStyleGetHeightScale(OH_Drawing_TypographyStyle* style)
```

**Description**

Obtains the height scale factor of a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|

**Returns**

| Type| Description|
| -- | -- |
| double | Height scale factor.|

### OH_Drawing_TypographyTextlineStyleGetHeightOnly()

```
bool OH_Drawing_TypographyTextlineStyleGetHeightOnly(OH_Drawing_TypographyStyle* style)
```

**Description**

Checks whether only the font height is used for a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|

**Returns**

| Type| Description|
| -- | -- |
| bool | Method for calculating the height of a font block. **true** means that the height is calculated based on the font size; **false** means that the height is calculated based on the line spacing.|

### OH_Drawing_TypographyTextlineStyleGetHalfLeading()

```
bool OH_Drawing_TypographyTextlineStyleGetHalfLeading(OH_Drawing_TypographyStyle* style)
```

**Description**

Checks whether half leading is enabled for a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** if half leading is enabled; returns **false** otherwise.|

### OH_Drawing_TypographyTextlineStyleGetSpacingScale()

```
double OH_Drawing_TypographyTextlineStyleGetSpacingScale(OH_Drawing_TypographyStyle* style)
```

**Description**

Obtains the spacing scale factor of a text line style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|

**Returns**

| Type| Description|
| -- | -- |
| double | Spacing scale factor.|

### OH_Drawing_TypographyTextlineGetStyleOnly()

```
bool OH_Drawing_TypographyTextlineGetStyleOnly(OH_Drawing_TypographyStyle* style)
```

**Description**

Checks whether only the text line style is enabled for a typography style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|

**Returns**

| Type| Description|
| -- | -- |
| bool | Whether only the text line style is enabled for a typography style. **true**: enabled; **false**: disabled.|

### OH_Drawing_TypographyGetTextAlign()

```
OH_Drawing_TextAlign OH_Drawing_TypographyGetTextAlign(OH_Drawing_TypographyStyle* style)
```

**Description**

Obtains the text alignment mode.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextAlign](#oh_drawing_textalign) | Alignment mode. For details about the available options, see [OH_Drawing_TextAlign](capi-drawing-text-typography-h.md#oh_drawing_textalign).|

### OH_Drawing_TypographyGetTextDirection()

```
OH_Drawing_TextDirection OH_Drawing_TypographyGetTextDirection(OH_Drawing_TypographyStyle* style)
```

**Description**

Obtains the text direction of a typography style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextDirection](#oh_drawing_textdirection) | Text direction. **0** means right-to-left; **1** means left-to-right. For details, see [OH_Drawing_TextDirection](capi-drawing-text-typography-h.md#oh_drawing_textdirection).|

### OH_Drawing_TypographyGetTextMaxLines()

```
size_t OH_Drawing_TypographyGetTextMaxLines(OH_Drawing_TypographyStyle* style)
```

**Description**

Obtains the maximum number of lines.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|

**Returns**

| Type| Description|
| -- | -- |
| size_t | Maximum number of lines.|

### OH_Drawing_TypographyGetTextEllipsis()

```
char* OH_Drawing_TypographyGetTextEllipsis(OH_Drawing_TypographyStyle* style)
```

**Description**

Obtains the text ellipsis content of a typography style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|

**Returns**

| Type| Description|
| -- | -- |
| char* | Ellipsis text.|

### OH_Drawing_TypographyDestroyEllipsis()

```
void OH_Drawing_TypographyDestroyEllipsis(char* ellipsis)
```

**Description**

Reclaims the memory occupied by the text ellipsis names.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| char* ellipsis | Pointer to the text ellipsis names.|

### OH_Drawing_TypographyStyleEquals()

```
bool OH_Drawing_TypographyStyleEquals(OH_Drawing_TypographyStyle* from, OH_Drawing_TypographyStyle* to)
```

**Description**

Checks whether two typography styles are the same. The text height modifier mode [OH_Drawing_TextHeightBehavior](capi-drawing-text-typography-h.md#oh_drawing_textheightbehavior) is not involved in the comparison.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* from | Pointer to the first typography style.|
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* to | Pointer to the second typography style.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Returns **true** if the two are the same; returns **false** otherwise.|

### OH_Drawing_TextStyleGetColor()

```
uint32_t OH_Drawing_TextStyleGetColor(OH_Drawing_TextStyle* style)
```

**Description**

Obtains the color of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

**Returns**

| Type| Description|
| -- | -- |
| uint32_t | Text color.|

### OH_Drawing_TextStyleGetDecorationStyle()

```
OH_Drawing_TextDecorationStyle OH_Drawing_TextStyleGetDecorationStyle(OH_Drawing_TextStyle* style)
```

**Description**

Obtains the decoration style of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle) | Text decoration style. For details, see [OH_Drawing_TextDecorationStyle](capi-drawing-text-typography-h.md#oh_drawing_textdecorationstyle).|

### OH_Drawing_TextStyleGetFontWeight()

```
OH_Drawing_FontWeight OH_Drawing_TextStyleGetFontWeight(OH_Drawing_TextStyle* style)
```

**Description**

Obtains the font weight of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_FontWeight](#oh_drawing_fontweight) | Font weight. For details, see [OH_Drawing_FontWeight](capi-drawing-text-typography-h.md#oh_drawing_fontweight).|

### OH_Drawing_TextStyleGetFontStyle()

```
OH_Drawing_FontStyle OH_Drawing_TextStyleGetFontStyle(OH_Drawing_TextStyle* style)
```

**Description**

Obtains the font style of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_FontStyle](#oh_drawing_fontstyle) | Font style. For details, see [OH_Drawing_FontStyle](capi-drawing-text-typography-h.md#oh_drawing_fontstyle).|

### OH_Drawing_TextStyleGetBaseline()

```
OH_Drawing_TextBaseline OH_Drawing_TextStyleGetBaseline(OH_Drawing_TextStyle* style)
```

**Description**

Obtains the baseline of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextBaseline](#oh_drawing_textbaseline) | Font baseline position. For details, see [OH_Drawing_TextBaseline](capi-drawing-text-typography-h.md#oh_drawing_textbaseline).|

### OH_Drawing_TextStyleGetFontFamilies()

```
char** OH_Drawing_TextStyleGetFontFamilies(OH_Drawing_TextStyle* style, size_t* num)
```

**Description**

Obtains the font families of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|
| size_t* num | Pointer to the number of font families.|

**Returns**

| Type| Description|
| -- | -- |
| char** | Font families.|

### OH_Drawing_TextStyleDestroyFontFamilies()

```
void OH_Drawing_TextStyleDestroyFontFamilies(char** fontFamilies, size_t num)
```

**Description**

Reclaims the memory occupied by the font families, where **num** specifies the number of font families.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| char** fontFamilies | Double pointer to the font families.|
| size_t num | Number of font families.|

### OH_Drawing_TextStyleGetFontSize()

```
double OH_Drawing_TextStyleGetFontSize(OH_Drawing_TextStyle* style)
```

**Description**

Obtains the font size of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

**Returns**

| Type| Description|
| -- | -- |
| double | Font size.|

### OH_Drawing_TextStyleGetLetterSpacing()

```
double OH_Drawing_TextStyleGetLetterSpacing(OH_Drawing_TextStyle* style)
```

**Description**

Obtains the letter spacing of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

**Returns**

| Type| Description|
| -- | -- |
| double | Letter spacing.|

### OH_Drawing_TextStyleGetWordSpacing()

```
double OH_Drawing_TextStyleGetWordSpacing(OH_Drawing_TextStyle* style)
```

**Description**

Obtains the word spacing of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

**Returns**

| Type| Description|
| -- | -- |
| double | Word spacing.|

### OH_Drawing_TextStyleGetFontHeight()

```
double OH_Drawing_TextStyleGetFontHeight(OH_Drawing_TextStyle* style)
```

**Description**

Obtains the font height of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

**Returns**

| Type| Description|
| -- | -- |
| double | Font height of a text style.|

### OH_Drawing_TextStyleGetHalfLeading()

```
bool OH_Drawing_TextStyleGetHalfLeading(OH_Drawing_TextStyle* style)
```

**Description**

Checks whether half leading is enabled for a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| bool | Whether half leading is enabled for a text style. **true** means enabled; **false** otherwise.|

### OH_Drawing_TextStyleGetLocale()

```
const char* OH_Drawing_TextStyleGetLocale(OH_Drawing_TextStyle* style)
```

**Description**

Obtains the locale of a text style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object, which is obtained from [OH_Drawing_CreateTextStyle](capi-drawing-text-typography-h.md#oh_drawing_createtextstyle).|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Pointer to the locale in the format of language-country. For example, zh-CN indicates Chinese (China), and en-US indicates English (United States). For details, see BCP 47.|

### OH_Drawing_TypographyDestroyTextBox()

```
void OH_Drawing_TypographyDestroyTextBox(OH_Drawing_TextBox* textBox)
```

**Description**

Releases the memory occupied by a text box.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md)* textBox | Pointer to the [OH_Drawing_TextBox](capi-drawing-oh-drawing-textbox.md) object.|

### OH_Drawing_SetTextShadow()

```
void OH_Drawing_SetTextShadow(OH_Drawing_TextShadow* shadow, uint32_t color, OH_Drawing_Point* offset,double blurRadius)
```

**Description**

Sets a text shadow.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)* shadow | Pointer to the [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md) object, which is obtained from [OH_Drawing_CreateTextShadow](capi-drawing-text-typography-h.md#oh_drawing_createtextshadow).|
| uint32_t color | Color of the text shadow. For example, if the input parameter is 0xAABBCCDD, AA indicates opacity, BB indicates the value of the red component, CC indicates the value of the green component, and DD indicates the value of the blue component.|
| [OH_Drawing_Point](capi-drawing-oh-drawing-point.md)* offset | Pointer to the [OH_Drawing_Point](capi-drawing-oh-drawing-point.md) object, which is the offset of the text shadow relative to the text.|
| double blurRadius | Blur radius. The value is a floating point number and has no unit. The value **0.0** means that there is no blur effect.|

### OH_Drawing_CreateTextTab()

```
OH_Drawing_TextTab* OH_Drawing_CreateTextTab(OH_Drawing_TextAlign alignment, float location)
```

**Description**

Creates a text tab object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextAlign](#oh_drawing_textalign) alignment | Alignment mode of the text following the tab character. The value 1 means right alignment, 2 means center alignment, and 0 or other values mean left alignment.|
| float location | Alignment position of the text following the tab character. The unit is px. The minimum value is 1.0.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextTab](capi-drawing-oh-drawing-texttab.md)* | Pointer to the **OH_Drawing_TextTab** object created. If a null pointer is returned, the creation fails. A possible cause is that no memory is available.|

### OH_Drawing_DestroyTextTab()

```
void OH_Drawing_DestroyTextTab(OH_Drawing_TextTab* tab)
```

**Description**

Releases the memory occupied by a text tab object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextTab](capi-drawing-oh-drawing-texttab.md)* tab | Pointer to an **OH_Drawing_TextTab** object.|

### OH_Drawing_GetTextTabAlignment()

```
OH_Drawing_TextAlign OH_Drawing_GetTextTabAlignment(OH_Drawing_TextTab* tab)
```

**Description**

Obtains the alignment mode of a text tab.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextTab](capi-drawing-oh-drawing-texttab.md)* tab | Pointer to an **OH_Drawing_TextTab** object.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextAlign](#oh_drawing_textalign) | Alignment mode. The value 1 means right alignment, 2 means center alignment, and 0 or other values mean left alignment.|

### OH_Drawing_GetTextTabLocation()

```
float OH_Drawing_GetTextTabLocation(OH_Drawing_TextTab* tab)
```

**Description**

Obtains the location of a text tab.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextTab](capi-drawing-oh-drawing-texttab.md)* tab | Pointer to an **OH_Drawing_TextTab** object.|

**Returns**

| Type| Description|
| -- | -- |
| float | Position of the text tab.|

### OH_Drawing_SetTypographyTextTab()

```
void OH_Drawing_SetTypographyTextTab(OH_Drawing_TypographyStyle* style, OH_Drawing_TextTab* tab)
```

**Description**

Sets the alignment mode and location of a text tab. When the text alignment mode or ellipsis style is set, the tab does not take effect. When the tab location is less than 1.0, the tab is replaced with a space.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object.|
| [OH_Drawing_TextTab](capi-drawing-oh-drawing-texttab.md)* tab | Pointer to an **OH_Drawing_TextTab** object.|

### OH_Drawing_GetDrawingArraySize()

```
size_t OH_Drawing_GetDrawingArraySize(OH_Drawing_Array* drawingArray)
```

**Description**

Obtains the number of objects in the input object array [OH_Drawing_Array](capi-drawing-oh-drawing-array.md).

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Array](capi-drawing-oh-drawing-array.md)* drawingArray | Pointer to the [OH_Drawing_Array](capi-drawing-oh-drawing-array.md) object array.|

**Returns**

| Type| Description|
| -- | -- |
| size_t | Number of objects in the array.|

### OH_Drawing_SetTypographyTextTrailingSpaceOptimized()

```
void OH_Drawing_SetTypographyTextTrailingSpaceOptimized(OH_Drawing_TypographyStyle* style, bool trailingSpaceOptimized)
```

**Description**

Sets whether to include the trailing spaces in alignment calculations during text typography.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) |  Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object.|
| bool |  Sets whether to include the trailing spaces in alignment calculations during text typography. **true** means not to include; **false** (default) means to include. You are advised to set this parameter to **true** for center-aligned text.|

### OH_Drawing_TypographyHandlerAddEncodedText()

```
void OH_Drawing_TypographyHandlerAddEncodedText(OH_Drawing_TypographyCreate* handler, const void* text,size_t byteLength, OH_Drawing_TextEncoding textEncodingType)
```

**Description**

Adds text encoded in a specified format.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)* handler | Pointer to the [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md) object, which is obtained from [OH_Drawing_CreateTypographyHandler](capi-drawing-text-typography-h.md#oh_drawing_createtypographyhandler).|
| const void* text | Pointer to the text content.|
| size_t byteLength | Length of the text, in bytes.|
| [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding) textEncodingType | Text encoding type, which is an enumerated value of [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding). Only **TEXT_ENCODING_UTF8**, **TEXT_ENCODING_UTF16**, and **TEXT_ENCODING_UTF32** are supported.|

### OH_Drawing_SetTypographyTextAutoSpace()

```
void OH_Drawing_SetTypographyTextAutoSpace(OH_Drawing_TypographyStyle *style, bool enableAutoSpace)
```

**Description**

Sets whether to enable automatic spacing during text typography.<br>This feature is disabled by default. If enabled, automatic spacing applies between CJK (Chinese, Japanese, and Korean) and Western characters (Latin, Cyrillic, and Greek), between CJK and digits, between CJK and copyright symbols, between copyright symbols and digits, and between copyright symbols and Western characters.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) *style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| bool enableAutoSpace | Sets whether to enable automatic spacing during text typography. **true** means enabled; **false** (default) means disabled.|

### OH_Drawing_TypographyUpdateDecorationColor()

```
void OH_Drawing_TypographyUpdateDecorationColor(OH_Drawing_Typography* typography, uint32_t color)
```

**Description**

Updates the decoration color of a typography object.<br> The updated decoration color takes effect after you call [OH_Drawing_TypographyPaint](capi-drawing-text-typography-h.md#oh_drawing_typographypaint) to draw the text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md) object, which is obtained from [OH_Drawing_CreateTypography](capi-drawing-text-typography-h.md#oh_drawing_createtypography).|
| uint32_t color | Updated text decoration color.|

### OH_Drawing_SetTypographyVerticalAlignment()

```
void OH_Drawing_SetTypographyVerticalAlignment(OH_Drawing_TypographyStyle* style,OH_Drawing_TextVerticalAlignment align)
```

**Description**

Sets the vertical alignment mode of the text.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object, which is obtained from [OH_Drawing_CreateTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle).|
| [OH_Drawing_TextVerticalAlignment](capi-drawing-text-typography-h.md#oh_drawing_textverticalalignment) align | Vertical alignment mode of the text. The default mode is baseline alignment. For details about other options, see [OH_Drawing_TextVerticalAlignment](capi-drawing-text-typography-h.md#oh_drawing_textverticalalignment).|

### OH_Drawing_CopyTypographyStyle()

```
OH_Drawing_TypographyStyle* OH_Drawing_CopyTypographyStyle(OH_Drawing_TypographyStyle* style)
```

**Description**

Creates a copy of an existing paragraph style object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* style | Pointer to the [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object to be copied.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md)* | Pointer to the copied [OH_Drawing_TypographyStyle](capi-drawing-oh-drawing-typographystyle.md) object. If a null pointer is returned, the creation fails. The possible cause is that no memory is available or **style** is a null pointer. Release this pointer by calling [OH_Drawing_DestroyTypographyStyle](capi-drawing-text-typography-h.md#oh_drawing_destroytypographystyle) when this object is no longer needed.|

### OH_Drawing_CopyTextStyle()

```
OH_Drawing_TextStyle* OH_Drawing_CopyTextStyle(OH_Drawing_TextStyle* style)
```

**Description**

Creates a copy of an existing text style object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* style | Pointer to the [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object to be copied.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md)* | Pointer to the copied [OH_Drawing_TextStyle](capi-drawing-oh-drawing-textstyle.md) object. If a null pointer is returned, the creation fails. The possible cause is that no memory is available or **style** is a null pointer. Release this pointer by calling [OH_Drawing_DestroyTextStyle](capi-drawing-text-typography-h.md#oh_drawing_destroytextstyle) when this object is no longer needed.|

### OH_Drawing_CopyTextShadow()

```
OH_Drawing_TextShadow* OH_Drawing_CopyTextShadow(OH_Drawing_TextShadow* shadow)
```

**Description**

Creates a copy of an existing text shadow object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)* shadow | Pointer to the [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md) object to be copied.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md)* | Pointer to the copied [OH_Drawing_TextShadow](capi-drawing-oh-drawing-textshadow.md) object. If a null pointer is returned, the creation fails. The possible cause is that no memory is available or **shadow** is a null pointer. Release this pointer by calling [OH_Drawing_DestroyTextShadow](capi-drawing-text-typography-h.md#oh_drawing_destroytextshadow) when this object is no longer needed.|
