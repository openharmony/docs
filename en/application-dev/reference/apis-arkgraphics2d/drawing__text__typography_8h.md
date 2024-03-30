# drawing_text_typography.h


## Overview

The **drawing_text_typography.h** file declares the functions related to typography in the drawing module.

**File to include**: &lt;native_drawing/drawing_text_typography.h&gt;

**Library**: libnative_drawing.so

**Since**: 8

**Related module**: [Drawing](_drawing.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md) | Describes a placeholder that acts as a span.| 
| struct  [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) | Describes the detailed information about a system font.| 
| struct  [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) | Describes the measurement information about a line of text.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [OH_Drawing_PlaceholderVerticalAlignment](_drawing.md#oh_drawing_placeholderverticalalignment)  [OH_Drawing_PlaceholderVerticalAlignment](_drawing.md#oh_drawing_placeholderverticalalignment) | Defines an enum for vertical alignment modes of placeholders.| 
| typedef struct [OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md)  [OH_Drawing_PlaceholderSpan](_drawing.md#oh_drawing_placeholderspan) | Defines a struct for a placeholder that acts as a span.| 
| typedef enum [OH_Drawing_TextDecorationStyle](_drawing.md#oh_drawing_textdecorationstyle)  [OH_Drawing_TextDecorationStyle](_drawing.md#oh_drawing_textdecorationstyle) | Defines an enum for text decoration styles.| 
| typedef enum [OH_Drawing_EllipsisModal](_drawing.md#oh_drawing_ellipsismodal)  [OH_Drawing_EllipsisModal](_drawing.md#oh_drawing_ellipsismodal) | Defines an enum for ellipsis styles.| 
| typedef enum [OH_Drawing_BreakStrategy](_drawing.md#oh_drawing_breakstrategy)  [OH_Drawing_BreakStrategy](_drawing.md#oh_drawing_breakstrategy) | Defines an enum for text break strategies.| 
| typedef enum [OH_Drawing_WordBreakType](_drawing.md#oh_drawing_wordbreaktype)  [OH_Drawing_WordBreakType](_drawing.md#oh_drawing_wordbreaktype) | Defines an enum for word break types.| 
| typedef enum [OH_Drawing_RectHeightStyle](_drawing.md#oh_drawing_rectheightstyle)  [OH_Drawing_RectHeightStyle](_drawing.md#oh_drawing_rectheightstyle) | Defines an enum for rectangle height styles.| 
| typedef enum [OH_Drawing_RectWidthStyle](_drawing.md#oh_drawing_rectwidthstyle)  [OH_Drawing_RectWidthStyle](_drawing.md#oh_drawing_rectwidthstyle) | Defines an enum for rectangle width styles.| 
| typedef struct [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md)  [OH_Drawing_FontDescriptor](_drawing.md#oh_drawing_fontdescriptor) | Defines a struct that describes the detailed information about a system font.| 
| typedef struct [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md)  [OH_Drawing_LineMetrics](_drawing.md#oh_drawing_linemetrics) | Defines a struct that describes the measurement information about a line of text.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_TextDirection](_drawing.md#oh_drawing_textdirection) { TEXT_DIRECTION_RTL, TEXT_DIRECTION_LTR } | Enumerates the text directions.| 
| [OH_Drawing_TextAlign](_drawing.md#oh_drawing_textalign) {<br>TEXT_ALIGN_LEFT, TEXT_ALIGN_RIGHT, TEXT_ALIGN_CENTER, TEXT_ALIGN_JUSTIFY,<br>TEXT_ALIGN_START, TEXT_ALIGN_END<br>} | Enumerates the text alignment modes.| 
| [OH_Drawing_FontWeight](_drawing.md#oh_drawing_fontweight) {<br>FONT_WEIGHT_100, FONT_WEIGHT_200, FONT_WEIGHT_300, FONT_WEIGHT_400,<br>FONT_WEIGHT_500, FONT_WEIGHT_600, FONT_WEIGHT_700, FONT_WEIGHT_800,<br>FONT_WEIGHT_900<br>} | Enumerates the font weights.| 
| [OH_Drawing_TextBaseline](_drawing.md#oh_drawing_textbaseline) { TEXT_BASELINE_ALPHABETIC, TEXT_BASELINE_IDEOGRAPHIC } | Enumerates the text baselines.| 
| [OH_Drawing_TextDecoration](_drawing.md#oh_drawing_textdecoration) { TEXT_DECORATION_NONE = 0x0, TEXT_DECORATION_UNDERLINE = 0x1, TEXT_DECORATION_OVERLINE = 0x2, TEXT_DECORATION_LINE_THROUGH = 0x4 } | Enumerates the text decorations.| 
| [OH_Drawing_FontStyle](_drawing.md#oh_drawing_fontstyle) { FONT_STYLE_NORMAL, FONT_STYLE_ITALIC } | Enumerates the font styles.| 
| [OH_Drawing_PlaceholderVerticalAlignment](_drawing.md#oh_drawing_placeholderverticalalignment) {<br>ALIGNMENT_OFFSET_AT_BASELINE, ALIGNMENT_ABOVE_BASELINE, ALIGNMENT_BELOW_BASELINE, ALIGNMENT_TOP_OF_ROW_BOX,<br>ALIGNMENT_BOTTOM_OF_ROW_BOX, ALIGNMENT_CENTER_OF_ROW_BOX<br>} | Enumerates the vertical alignment modes of placeholders.| 
| [OH_Drawing_TextDecorationStyle](_drawing.md#oh_drawing_textdecorationstyle) {<br>TEXT_DECORATION_STYLE_SOLID, TEXT_DECORATION_STYLE_DOUBLE, TEXT_DECORATION_STYLE_DOTTED, TEXT_DECORATION_STYLE_DASHED,<br>TEXT_DECORATION_STYLE_WAVY<br>} | Enumerates the text decoration styles.| 
| [OH_Drawing_EllipsisModal](_drawing.md#oh_drawing_ellipsismodal) { ELLIPSIS_MODAL_HEAD = 0, ELLIPSIS_MODAL_MIDDLE = 1, ELLIPSIS_MODAL_TAIL = 2 } | Enumerates the ellipsis styles.| 
| [OH_Drawing_BreakStrategy](_drawing.md#oh_drawing_breakstrategy) { BREAK_STRATEGY_GREEDY = 0, BREAK_STRATEGY_HIGH_QUALITY = 1, BREAK_STRATEGY_BALANCED = 2 } | Enumerates the text break strategies.| 
| [OH_Drawing_WordBreakType](_drawing.md#oh_drawing_wordbreaktype) { WORD_BREAK_TYPE_NORMAL = 0, WORD_BREAK_TYPE_BREAK_ALL = 1, WORD_BREAK_TYPE_BREAK_WORD = 2 } | Enumerates the word break types.| 
| [OH_Drawing_RectHeightStyle](_drawing.md#oh_drawing_rectheightstyle) {<br>RECT_HEIGHT_STYLE_TIGHT, RECT_HEIGHT_STYLE_MAX, RECT_HEIGHT_STYLE_INCLUDELINESPACEMIDDLE, RECT_HEIGHT_STYLE_INCLUDELINESPACETOP,<br>RECT_HEIGHT_STYLE_INCLUDELINESPACEBOTTOM, RECT_HEIGHT_STYLE_STRUCT<br>} | Enumerates the rectangle height styles.| 
| [OH_Drawing_RectWidthStyle](_drawing.md#oh_drawing_rectwidthstyle) { RECT_WIDTH_STYLE_TIGHT, RECT_WIDTH_STYLE_MAX } | Enumerates the rectangle width styles.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \* [OH_Drawing_CreateTypographyStyle](_drawing.md#oh_drawing_createtypographystyle) (void) | Creates an **OH_Drawing_TypographyStyle** object.| 
| void [OH_Drawing_DestroyTypographyStyle](_drawing.md#oh_drawing_destroytypographystyle) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*) | Destroys an **OH_Drawing_TypographyStyle** object and reclaims the memory occupied by the object.| 
| void [OH_Drawing_SetTypographyTextDirection](_drawing.md#oh_drawing_settypographytextdirection) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | Sets the text direction.| 
| void [OH_Drawing_SetTypographyTextAlign](_drawing.md#oh_drawing_settypographytextalign) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | Sets the text alignment mode.| 
| int [OH_Drawing_TypographyGetEffectiveAlignment](_drawing.md#oh_drawing_typographygeteffectivealignment) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*style) | Obtains the text alignment mode.| 
| void [OH_Drawing_SetTypographyTextMaxLines](_drawing.md#oh_drawing_settypographytextmaxlines) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | Sets the maximum number of lines in the text.| 
| [OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \* [OH_Drawing_CreateTextStyle](_drawing.md#oh_drawing_createtextstyle) (void) | Creates an **OH_Drawing_TextStyle** object.| 
| [OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \* [OH_Drawing_TypographyGetTextStyle](_drawing.md#oh_drawing_typographygettextstyle) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*style) | Obtains the text style.| 
| void [OH_Drawing_DestroyTextStyle](_drawing.md#oh_drawing_destroytextstyle) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | Destroys an **OH_Drawing_TextStyle** object and reclaims the memory occupied by the object.| 
| void [OH_Drawing_SetTextStyleColor](_drawing.md#oh_drawing_settextstylecolor) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, uint32_t) | Sets the text color.| 
| void [OH_Drawing_SetTextStyleFontSize](_drawing.md#oh_drawing_settextstylefontsize) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, double) | Sets the font size.| 
| void [OH_Drawing_SetTextStyleFontWeight](_drawing.md#oh_drawing_settextstylefontweight) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | Sets the font weight.| 
| void [OH_Drawing_SetTextStyleBaseLine](_drawing.md#oh_drawing_settextstylebaseline) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | Sets the text baseline.| 
| void [OH_Drawing_SetTextStyleDecoration](_drawing.md#oh_drawing_settextstyledecoration) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | Sets the text decoration.| 
| void [OH_Drawing_SetTextStyleDecorationColor](_drawing.md#oh_drawing_settextstyledecorationcolor) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, uint32_t) | Sets the color for the text decoration.| 
| void [OH_Drawing_SetTextStyleFontHeight](_drawing.md#oh_drawing_settextstylefontheight) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, double) | Sets the font height.| 
| void [OH_Drawing_SetTextStyleFontFamilies](_drawing.md#oh_drawing_settextstylefontfamilies) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int, const char \*fontFamilies[]) | Sets the font families.| 
| void [OH_Drawing_SetTextStyleFontStyle](_drawing.md#oh_drawing_settextstylefontstyle) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | Sets the font style.| 
| void [OH_Drawing_SetTextStyleLocale](_drawing.md#oh_drawing_settextstylelocale) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, const char \*) | Sets the locale.| 
| void [OH_Drawing_SetTextStyleForegroundBrush](_drawing.md#oh_drawing_settextstyleforegroundbrush) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | Sets the foreground brush.| 
| void [OH_Drawing_TextStyleGetForegroundBrush](_drawing.md#oh_drawing_textstylegetforegroundbrush) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | Obtains the foreground brush.| 
| void [OH_Drawing_SetTextStyleForegroundPen](_drawing.md#oh_drawing_settextstyleforegroundpen) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Sets the foreground pen.| 
| void [OH_Drawing_TextStyleGetForegroundPen](_drawing.md#oh_drawing_textstylegetforegroundpen) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Obtains the foreground pen.| 
| void [OH_Drawing_SetTextStyleBackgroundBrush](_drawing.md#oh_drawing_settextstylebackgroundbrush) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | Sets the background brush.| 
| void [OH_Drawing_TextStyleGetBackgroundBrush](_drawing.md#oh_drawing_textstylegetbackgroundbrush) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | Obtains the background brush.| 
| void [OH_Drawing_SetTextStyleBackgroundPen](_drawing.md#oh_drawing_settextstylebackgroundpen) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Sets the background pen.| 
| void [OH_Drawing_TextStyleGetBackgroundPen](_drawing.md#oh_drawing_textstylegetbackgroundpen) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Obtains the background pen.| 
| [OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \* [OH_Drawing_CreateTypographyHandler](_drawing.md#oh_drawing_createtypographyhandler) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, [OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection) \*) | Creates a handler to an **OH_Drawing_TypographyCreate** object.| 
| void [OH_Drawing_DestroyTypographyHandler](_drawing.md#oh_drawing_destroytypographyhandler) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*) | Reclaims the memory occupied by an **OH_Drawing_TypographyCreate** object.| 
| void [OH_Drawing_TypographyHandlerPushTextStyle](_drawing.md#oh_drawing_typographyhandlerpushtextstyle) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*, [OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | Sets the text style.| 
| void [OH_Drawing_TypographyHandlerAddText](_drawing.md#oh_drawing_typographyhandleraddtext) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*, const char \*) | Adds text.| 
| void [OH_Drawing_TypographyHandlerPopTextStyle](_drawing.md#oh_drawing_typographyhandlerpoptextstyle) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*) | Removes the topmost style in the stack, leaving the remaining styles in effect.| 
| [OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \* [OH_Drawing_CreateTypography](_drawing.md#oh_drawing_createtypography) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*) | Creates an **OH_Drawing_Typography** object.| 
| void [OH_Drawing_DestroyTypography](_drawing.md#oh_drawing_destroytypography) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | Destroys an **OH_Drawing_Typography** object and reclaims the memory occupied by the object.| 
| void [OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, double) | Lays out the typography.| 
| void [OH_Drawing_TypographyPaint](_drawing.md#oh_drawing_typographypaint) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, [OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, double, double) | Paints text.| 
| double [OH_Drawing_TypographyGetMaxWidth](_drawing.md#oh_drawing_typographygetmaxwidth) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | Obtains the maximum width.| 
| double [OH_Drawing_TypographyGetHeight](_drawing.md#oh_drawing_typographygetheight) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | Obtains the height.| 
| double [OH_Drawing_TypographyGetLongestLine](_drawing.md#oh_drawing_typographygetlongestline) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | Obtains the width of the longest line. You are advised to round up the return value in actual use. When the text content is empty, the minimum float value, that is, -340282346638528859811704183484516925440.000000, is returned.| 
| double [OH_Drawing_TypographyGetMinIntrinsicWidth](_drawing.md#oh_drawing_typographygetminintrinsicwidth) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | Obtains the minimum intrinsic width.| 
| double [OH_Drawing_TypographyGetMaxIntrinsicWidth](_drawing.md#oh_drawing_typographygetmaxintrinsicwidth) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | Obtains the maximum intrinsic width.| 
| double [OH_Drawing_TypographyGetAlphabeticBaseline](_drawing.md#oh_drawing_typographygetalphabeticbaseline) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | Obtains the alphabetic baseline.| 
| double [OH_Drawing_TypographyGetIdeographicBaseline](_drawing.md#oh_drawing_typographygetideographicbaseline) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | Obtains the ideographic baseline.| 
| void [OH_Drawing_TypographyHandlerAddPlaceholder](_drawing.md#oh_drawing_typographyhandleraddplaceholder) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*, [OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md) \*) | Adds a placeholder.| 
| bool [OH_Drawing_TypographyDidExceedMaxLines](_drawing.md#oh_drawing_typographydidexceedmaxlines) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | Checks whether the maximum number of lines is exceeded.| 
| [OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \* [OH_Drawing_TypographyGetRectsForRange](_drawing.md#oh_drawing_typographygetrectsforrange) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, size_t, size_t, [OH_Drawing_RectHeightStyle](_drawing.md#oh_drawing_rectheightstyle), [OH_Drawing_RectWidthStyle](_drawing.md#oh_drawing_rectwidthstyle)) | Obtains text boxes in a given range.| 
| [OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \* [OH_Drawing_TypographyGetRectsForPlaceholders](_drawing.md#oh_drawing_typographygetrectsforplaceholders) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | Obtains text boxes for placeholders.| 
| float [OH_Drawing_GetLeftFromTextBox](_drawing.md#oh_drawing_getleftfromtextbox) ([OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \*, int) | Obtains the left position of a text box.| 
| float [OH_Drawing_GetRightFromTextBox](_drawing.md#oh_drawing_getrightfromtextbox) ([OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \*, int) | Obtains the right position of a text box.| 
| float [OH_Drawing_GetTopFromTextBox](_drawing.md#oh_drawing_gettopfromtextbox) ([OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \*, int) | Obtains the top position of a text box.| 
| float [OH_Drawing_GetBottomFromTextBox](_drawing.md#oh_drawing_getbottomfromtextbox) ([OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \*, int) | Obtains the bottom position of a text box.| 
| int [OH_Drawing_GetTextDirectionFromTextBox](_drawing.md#oh_drawing_gettextdirectionfromtextbox) ([OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \*, int) | Obtains the text direction of a text box.| 
| size_t [OH_Drawing_GetSizeOfTextBox](_drawing.md#oh_drawing_getsizeoftextbox) ([OH_Drawing_TextBox](_drawing.md#oh_drawing_textbox) \*) | Obtains the number of text boxes.| 
| [OH_Drawing_PositionAndAffinity](_drawing.md#oh_drawing_positionandaffinity) \* [OH_Drawing_TypographyGetGlyphPositionAtCoordinate](_drawing.md#oh_drawing_typographygetglyphpositionatcoordinate) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, double, double) | Obtains the position and affinity of the glyph at the given coordinates.| 
| [OH_Drawing_PositionAndAffinity](_drawing.md#oh_drawing_positionandaffinity) \* [OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster](_drawing.md#oh_drawing_typographygetglyphpositionatcoordinatewithcluster) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, double, double) | Obtains the position and affinity of the glyph cluster to which the glyph at the given coordinates belongs. The glyph cluster is a container that holds one or more glyphs.| 
| size_t [OH_Drawing_GetPositionFromPositionAndAffinity](_drawing.md#oh_drawing_getpositionfrompositionandaffinity) ([OH_Drawing_PositionAndAffinity](_drawing.md#oh_drawing_positionandaffinity) \*) | Obtains the position attribute of an **OH_Drawing_PositionAndAffinity** object.| 
| int [OH_Drawing_GetAffinityFromPositionAndAffinity](_drawing.md#oh_drawing_getaffinityfrompositionandaffinity) ([OH_Drawing_PositionAndAffinity](_drawing.md#oh_drawing_positionandaffinity) \*) | Obtains the affinity attribute of an **OH_Drawing_PositionAndAffinity** object. The affinity determines whether the font is close to the front text or rear text.| 
| [OH_Drawing_Range](_drawing.md#oh_drawing_range) \* [OH_Drawing_TypographyGetWordBoundary](_drawing.md#oh_drawing_typographygetwordboundary) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, size_t) | Obtains the word boundary.| 
| size_t [OH_Drawing_GetStartFromRange](_drawing.md#oh_drawing_getstartfromrange) ([OH_Drawing_Range](_drawing.md#oh_drawing_range) \*) | Obtains the start position of an **OH_Drawing_Range** object.| 
| size_t [OH_Drawing_GetEndFromRange](_drawing.md#oh_drawing_getendfromrange) ([OH_Drawing_Range](_drawing.md#oh_drawing_range) \*) | Obtains the end position of an **OH_Drawing_Range** object.| 
| size_t [OH_Drawing_TypographyGetLineCount](_drawing.md#oh_drawing_typographygetlinecount) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | Obtains the number of lines.| 
| void [OH_Drawing_SetTextStyleDecorationStyle](_drawing.md#oh_drawing_settextstyledecorationstyle) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | Sets the text decoration style.| 
| void [OH_Drawing_SetTextStyleDecorationThicknessScale](_drawing.md#oh_drawing_settextstyledecorationthicknessscale) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, double) | Sets the thickness scale factor of the text decoration line.| 
| void [OH_Drawing_SetTextStyleLetterSpacing](_drawing.md#oh_drawing_settextstyleletterspacing) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, double) | Sets the letter spacing for text.| 
| void [OH_Drawing_SetTextStyleWordSpacing](_drawing.md#oh_drawing_settextstylewordspacing) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, double) | Sets the word spacing for text.| 
| void [OH_Drawing_SetTextStyleHalfLeading](_drawing.md#oh_drawing_settextstylehalfleading) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, bool) | Sets half leading for text.| 
| void [OH_Drawing_SetTextStyleEllipsis](_drawing.md#oh_drawing_settextstyleellipsis) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, const char \*) | Sets the ellipsis content for text.| 
| void [OH_Drawing_SetTextStyleEllipsisModal](_drawing.md#oh_drawing_settextstyleellipsismodal) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | Sets the ellipsis style for text.| 
| void [OH_Drawing_SetTypographyTextBreakStrategy](_drawing.md#oh_drawing_settypographytextbreakstrategy) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | Sets the text break strategy.| 
| void [OH_Drawing_SetTypographyTextWordBreakType](_drawing.md#oh_drawing_settypographytextwordbreaktype) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | Sets the word break type.| 
| void [OH_Drawing_SetTypographyTextEllipsisModal](_drawing.md#oh_drawing_settypographytextellipsismodal) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | Sets the ellipsis style for text.| 
| void [OH_Drawing_SetTypographyTextEllipsis](_drawing.md#oh_drawing_settypographytextellipsis) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*style, const char \*ellipsis) | Sets the ellipsis style.| 
| double [OH_Drawing_TypographyGetLineHeight](_drawing.md#oh_drawing_typographygetlineheight) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, int) | Obtains the height of a line.| 
| double [OH_Drawing_TypographyGetLineWidth](_drawing.md#oh_drawing_typographygetlinewidth) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, int) | Obtains the width of a line.| 
| void [OH_Drawing_SetTypographyTextSplitRatio](_drawing.md#oh_drawing_settypographytextsplitratio) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*style, float textSplitRatio) | Sets the text split ratio.| 
| bool [OH_Drawing_TypographyIsLineUnlimited](_drawing.md#oh_drawing_typographyislineunlimited) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*style) | Checks whether the maximum number of lines is limited for text.| 
| bool [OH_Drawing_TypographyIsEllipsized](_drawing.md#oh_drawing_typographyisellipsized) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*style) | Checks whether the text has an ellipsis.| 
| void [OH_Drawing_SetTypographyTextLocale](_drawing.md#oh_drawing_settypographytextlocale) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*style, const char \*locale) | Sets the text locale.| 
| bool [OH_Drawing_TextStyleGetFontMetrics](_drawing.md#oh_drawing_textstylegetfontmetrics) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, [OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) \*) | Obtains the font metrics.| 
| void [OH_Drawing_SetTypographyTextStyle](_drawing.md#oh_drawing_settypographytextstyle) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, [OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | Sets the text style.| 
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \* [OH_Drawing_CreateFontDescriptor](_drawing.md#oh_drawing_createfontdescriptor) (void) | Creates an **OH_Drawing_FontDescriptor** object to describe the detailed information about a system font.| 
| void [OH_Drawing_DestroyFontDescriptor](_drawing.md#oh_drawing_destroyfontdescriptor) ([OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \*) | Destroys an **OH_Drawing_FontDescriptor** object and reclaims the memory occupied by the object.| 
| [OH_Drawing_FontParser](_drawing.md#oh_drawing_fontparser) \* [OH_Drawing_CreateFontParser](_drawing.md#oh_drawing_createfontparser) (void) | Creates an **OH_Drawing_FontParser** object to parse a system font.| 
| void [OH_Drawing_DestroyFontParser](_drawing.md#oh_drawing_destroyfontparser) ([OH_Drawing_FontParser](_drawing.md#oh_drawing_fontparser) \*) | Destroys an **OH_Drawing_FontParser** object and reclaims the memory occupied by the object.| 
| char \*\* [OH_Drawing_FontParserGetSystemFontList](_drawing.md#oh_drawing_fontparsergetsystemfontlist) ([OH_Drawing_FontParser](_drawing.md#oh_drawing_fontparser) \*, size_t \*) | Obtains the list of system fonts.| 
| void [OH_Drawing_DestroySystemFontList](_drawing.md#oh_drawing_destroysystemfontlist) (char \*\*, size_t) | Reclaims the memory occupied by the system font list.| 
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \* [OH_Drawing_FontParserGetFontByName](_drawing.md#oh_drawing_fontparsergetfontbyname) ([OH_Drawing_FontParser](_drawing.md#oh_drawing_fontparser) \*, const char \*) | Obtains the descriptor of a system font based on the font name.| 
| [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \* [OH_Drawing_TypographyGetLineMetrics](_drawing.md#oh_drawing_typographygetlinemetrics) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | Obtains the line metrics.| 
| size_t [OH_Drawing_LineMetricsGetSize](_drawing.md#oh_drawing_linemetricsgetsize) ([OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \*) | Obtains the number of lines.| 
| void [OH_Drawing_DestroyLineMetrics](_drawing.md#oh_drawing_destroylinemetrics) ([OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \*) | Destroys an **OH_Drawing_LineMetrics** object and reclaims the memory occupied by the object.| 
| bool [OH_Drawing_TypographyGetLineMetricsAt](_drawing.md#oh_drawing_typographygetlinemetricsat) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, int, [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \*) | Obtains the metrics of a given line.| 
| bool [OH_Drawing_TypographyGetLineInfo](_drawing.md#oh_drawing_typographygetlineinfo) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, int, bool, bool, [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \*) | Obtains the metrics of a given line or the metrics of the first character in a given line.| 
| void [OH_Drawing_SetTypographyTextFontWeight](_drawing.md#oh_drawing_settypographytextfontweight) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | Sets the font weight for text.| 
| void [OH_Drawing_SetTypographyTextFontStyle](_drawing.md#oh_drawing_settypographytextfontstyle) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | Sets the font style for text.| 
| void [OH_Drawing_SetTypographyTextFontFamily](_drawing.md#oh_drawing_settypographytextfontfamily) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, const char \*) | Sets the font family name for text.| 
| void [OH_Drawing_SetTypographyTextFontSize](_drawing.md#oh_drawing_settypographytextfontsize) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, double) | Sets the font size for text.| 
| void [OH_Drawing_SetTypographyTextLineStyleFontSize](_drawing.md#oh_drawing_settypographytextlinestylefontsize) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, double) | Sets the font size for a text line.| 
| void [OH_Drawing_SetTypographyTextFontHeight](_drawing.md#oh_drawing_settypographytextfontheight) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, double) | Sets the font height for text.| 
| void [OH_Drawing_SetTypographyTextHalfLeading](_drawing.md#oh_drawing_settypographytexthalfleading) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, bool) | Sets whether half leading is used for text.| 
| void [OH_Drawing_SetTypographyTextUseLineStyle](_drawing.md#oh_drawing_settypographytextuselinestyle) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, bool) | Sets whether to enable the line style for text.| 
| void [OH_Drawing_SetTypographyTextLineStyleFontWeight](_drawing.md#oh_drawing_settypographytextlinestylefontweight) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | Sets the font weight of the text line style.| 
| void [OH_Drawing_SetTypographyTextLineStyleFontStyle](_drawing.md#oh_drawing_settypographytextlinestylefontstyle) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | Sets the font style of the text line style.| 
| void [OH_Drawing_SetTypographyTextLineStyleFontFamilies](_drawing.md#oh_drawing_settypographytextlinestylefontfamilies) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int, const char \*fontFamilies[]) | Sets the font families of the text line style.| 
| void [OH_Drawing_SetTypographyTextLineStyleFontHeight](_drawing.md#oh_drawing_settypographytextlinestylefontheight) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, double) | Sets the font height of the text line style.| 
| void [OH_Drawing_SetTypographyTextLineStyleHalfLeading](_drawing.md#oh_drawing_settypographytextlinestylehalfleading) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, bool) | Sets whether half leading is used for the text line style.| 
| void [OH_Drawing_SetTypographyTextLineStyleSpacingScale](_drawing.md#oh_drawing_settypographytextlinestylespacingscale) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, double) | Sets the spacing ratio of the text line style.| 
| void [OH_Drawing_SetTypographyTextLineStyleOnly](_drawing.md#oh_drawing_settypographytextlinestyleonly) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, bool) | Sets whether to enable the text line style only.| 
| [OH_Drawing_TextShadow](_drawing.md#oh_drawing_textshadow) \* [OH_Drawing_CreateTextShadow](_drawing.md#oh_drawing_createtextshadow) (void) | Creates a pointer to an **OH_Drawing_TextShadow** object.| 
| void [OH_Drawing_DestroyTextShadow](_drawing.md#oh_drawing_destroytextshadow) ([OH_Drawing_TextShadow](_drawing.md#oh_drawing_textshadow) \*) | Destroys an **OH_Drawing_TextShadow** object and reclaims the memory occupied by the object.| 
| [OH_Drawing_TextShadow](_drawing.md#oh_drawing_textshadow) \* [OH_Drawing_TextStyleGetShadows](_drawing.md#oh_drawing_textstylegetshadows) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | Obtains a text shadow container.| 
| int [OH_Drawing_TextStyleGetShadowCount](_drawing.md#oh_drawing_textstylegetshadowcount) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | Obtains the size of a text shadow container.| 
| void [OH_Drawing_TextStyleAddShadow](_drawing.md#oh_drawing_textstyleaddshadow) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, const [OH_Drawing_TextShadow](_drawing.md#oh_drawing_textshadow) \*) | Adds a shadow to a text shadow container.| 
| void [OH_Drawing_TextStyleClearShadows](_drawing.md#oh_drawing_textstyleclearshadows) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | Clears all shadows in a text shadow container.| 
| [OH_Drawing_TextShadow](_drawing.md#oh_drawing_textshadow) \* [OH_Drawing_TextStyleGetShadowWithIndex](_drawing.md#oh_drawing_textstylegetshadowwithindex) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | Obtains a shadow with a given index in a text shadow container.| 
| void [OH_Drawing_TypographySetIndents](_drawing.md#oh_drawing_typographysetindents) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, int, const float indents[]) | Sets the indents for typography.| 
| float [OH_Drawing_TypographyGetIndentsWithIndex](_drawing.md#oh_drawing_typographygetindentswithindex) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, int) | Obtains indents with a given index.| 
| [OH_Drawing_Range](_drawing.md#oh_drawing_range) \* [OH_Drawing_TypographyGetLineTextRange](_drawing.md#oh_drawing_typographygetlinetextrange) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, int, bool) | Obtains the line bounds.| 
| void [OH_Drawing_DestroyTextShadows](_drawing.md#oh_drawing_destroytextshadows) ([OH_Drawing_TextShadow](_drawing.md#oh_drawing_textshadow) \*) | Reclaims the memory occupied by the vector consisting of the **OH_Drawing_TextShadow** objects.| 
