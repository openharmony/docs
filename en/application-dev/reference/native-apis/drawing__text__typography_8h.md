# drawing_text_typography.h


## Overview

Declares the functions related to the typography in the drawing module.

**Since**

8

**Related module**

[Drawing](_drawing.md)


## Summary


### Enums

| Name| Description|
| -------- | -------- |
| [OH_Drawing_TextDirection](_drawing.md#oh_drawing_textdirection) { TEXT_DIRECTION_RTL, TEXT_DIRECTION_LTR } | Enumerates the text directions.|
| [OH_Drawing_TextAlign](_drawing.md#oh_drawing_textalign) { TEXT_ALIGN_LEFT, TEXT_ALIGN_RIGHT, TEXT_ALIGN_CENTER, TEXT_ALIGN_JUSTIFY,   TEXT_ALIGN_START, TEXT_ALIGN_END } | Enumerates the text alignment modes.|
| [OH_Drawing_FontWeight](_drawing.md#oh_drawing_fontweight) {  FONT_WEIGHT_100, FONT_WEIGHT_200, FONT_WEIGHT_300, FONT_WEIGHT_400,   FONT_WEIGHT_500, FONT_WEIGHT_600, FONT_WEIGHT_700, FONT_WEIGHT_800,  FONT_WEIGHT_900  } | Enumerates the font weights.|
| [OH_Drawing_TextBaseline](_drawing.md#oh_drawing_textbaseline) { TEXT_BASELINE_ALPHABETIC, TEXT_BASELINE_IDEOGRAPHIC } | Enumerates the text baselines.|
| [OH_Drawing_TextDecoration](_drawing.md#oh_drawing_textdecoration) { TEXT_DECORATION_NONE = 0x0, TEXT_DECORATION_UNDERLINE = 0x1, TEXT_DECORATION_OVERLINE = 0x2, TEXT_DECORATION_LINE_THROUGH = 0x4 } | Enumerates the text decorations.|
| [OH_Drawing_FontStyle](_drawing.md#oh_drawing_fontstyle) { FONT_STYLE_NORMAL, FONT_STYLE_ITALIC } | Enumerates the font styles.|



### Functions

| Name| Description|
| -------- | -------- |
| [OH_Drawing_CreateTypographyStyle](_drawing.md#oh_drawing_createtypographystyle) (void) | Creates an **OH_Drawing_TypographyStyle** object.|
| [OH_Drawing_DestroyTypographyStyle](_drawing.md#oh_drawing_destroytypographystyle) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*) | Destroys an **OH_Drawing_TypographyStyle** object and reclaims the memory occupied by the object.|
| [OH_Drawing_SetTypographyTextDirection](_drawing.md#oh_drawing_settypographytextdirection) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | Sets the text direction.|
| [OH_Drawing_SetTypographyTextAlign](_drawing.md#oh_drawing_settypographytextalign) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | Sets the text alignment mode.|
| [OH_Drawing_SetTypographyTextMaxLines](_drawing.md#oh_drawing_settypographytextmaxlines) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, int) | Sets the maximum number of lines in the text.|
| [OH_Drawing_CreateTextStyle](_drawing.md#oh_drawing_createtextstyle) (void) | Creates an **OH_Drawing_TextStyle** object.|
| [OH_Drawing_DestroyTextStyle](_drawing.md#oh_drawing_destroytextstyle) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | Destroys an **OH_Drawing_TextStyle** object and reclaims the memory occupied by the object.|
| [OH_Drawing_SetTextStyleColor](_drawing.md#oh_drawing_settextstylecolor) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, uint32_t) | Sets the text color.|
| [OH_Drawing_SetTextStyleFontSize](_drawing.md#oh_drawing_settextstylefontsize) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, double) | Sets the font size.|
| [OH_Drawing_SetTextStyleFontWeight](_drawing.md#oh_drawing_settextstylefontweight) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | Sets the font weight.|
| [OH_Drawing_SetTextStyleBaseLine](_drawing.md#oh_drawing_settextstylebaseline) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | Sets the text baseline.|
| [OH_Drawing_SetTextStyleDecoration](_drawing.md#oh_drawing_settextstyledecoration) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | Sets the text decoration.|
| [OH_Drawing_SetTextStyleDecorationColor](_drawing.md#oh_drawing_settextstyledecorationcolor) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, uint32_t) | Sets the color for the text decoration.|
| [OH_Drawing_SetTextStyleFontHeight](_drawing.md#oh_drawing_settextstylefontheight) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, double) | Sets the font height.|
| [OH_Drawing_SetTextStyleFontFamilies](_drawing.md#oh_drawing_settextstylefontfamilies) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int, const char \*fontFamilies[]) | Sets the font families.|
| [OH_Drawing_SetTextStyleFontStyle](_drawing.md#oh_drawing_settextstylefontstyle) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, int) | Sets the font style.|
| [OH_Drawing_SetTextStyleLocale](_drawing.md#oh_drawing_settextstylelocale) ([OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*, const char \*) | Sets the locale.|
| [OH_Drawing_CreateTypographyHandler](_drawing.md#oh_drawing_createtypographyhandler) ([OH_Drawing_TypographyStyle](_drawing.md#oh_drawing_typographystyle) \*, [OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection) \*) | Creates a handler to an **OH_Drawing_TypographyCreate** object.|
| [OH_Drawing_DestroyTypographyHandler](_drawing.md#oh_drawing_destroytypographyhandler) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*) | Reclaims the memory occupied by an **OH_Drawing_TypographyCreate** object.|
| [OH_Drawing_TypographyHandlerPushTextStyle](_drawing.md#oh_drawing_typographyhandlerpushtextstyle) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*, [OH_Drawing_TextStyle](_drawing.md#oh_drawing_textstyle) \*) | Sets the text style.|
| [OH_Drawing_TypographyHandlerAddText](_drawing.md#oh_drawing_typographyhandleraddtext) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*, const char \*) | Sets the text content.|
| [OH_Drawing_TypographyHandlerPopTextStyle](_drawing.md#oh_drawing_typographyhandlerpoptextstyle) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*) | Removes the topmost style in the stack, leaving the remaining styles in effect.|
| [OH_Drawing_CreateTypography](_drawing.md#oh_drawing_createtypography) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*) | Creates an **OH_Drawing_Typography** object.|
| [OH_Drawing_DestroyTypography](_drawing.md#oh_drawing_destroytypography) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*) | Destroys an **OH_Drawing_Typography** object and reclaims the memory occupied by the object.|
| [OH_Drawing_TypographyLayout](_drawing.md#oh_drawing_typographylayout) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, double) | Lays out the typography.|
| [OH_Drawing_TypographyPaint](_drawing.md#oh_drawing_typographypaint) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*, [OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, double, double) | Paints text.|
| [OH_Drawing_TypographyGetMaxWidth](_drawing.md#oh_drawing_typographygetmaxwidth) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) *) | Obtains the maximum width.|
| [OH_Drawing_TypographyGetHeight](_drawing.md#oh_drawing_typographygetheight) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) *) | Obtains the height.|
| [OH_Drawing_TypographyGetLongestLine](_drawing.md#oh_drawing_typographygetlongestline) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) *) | Obtains the longest line.|
| [OH_Drawing_TypographyGetMinIntrinsicWidth](_drawing.md#oh_drawing_typographygetminintrinsicwidth) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) *) | Obtains the minimum intrinsic width.|
| [OH_Drawing_TypographyGetMaxIntrinsicWidth](_drawing.md#oh_drawing_typographygetmaxintrinsicwidth) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) *) | Obtains the maximum intrinsic width.|
| [OH_Drawing_TypographyGetAlphabeticBaseline](_drawing.md#oh_drawing_typographygetalphabeticbaseline)([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) *) | Obtains the alphabetic baseline.|
| [OH_Drawing_TypographyGetIdeographicBaseline](_drawing.md#oh_drawing_typographygetideographicbaseline) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) *) | Obtains the ideographic baseline.|
