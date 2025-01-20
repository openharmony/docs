# drawing_font.h


## Overview

The **drawing_font.h** file declares the functions related to the font in the drawing module.

**File to include**: &lt;native_drawing/drawing_font.h&gt;

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](_drawing.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) | Describes the measurement information about a font.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [OH_Drawing_FontEdging](_drawing.md#oh_drawing_fontedging)  [OH_Drawing_FontEdging](_drawing.md#oh_drawing_fontedging) | Defines an enum for the font edging types.| 
| typedef enum [OH_Drawing_FontHinting](_drawing.md#oh_drawing_fonthinting)  [OH_Drawing_FontHinting](_drawing.md#oh_drawing_fonthinting) | Defines an enum for the font hinting types.| 
| typedef struct [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md)  [OH_Drawing_Font_Metrics](_drawing.md#oh_drawing_font_metrics) | Defines a struct for the measurement information about a font.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_FontEdging](_drawing.md#oh_drawing_fontedging) { FONT_EDGING_ALIAS, FONT_EDGING_ANTI_ALIAS, FONT_EDGING_SUBPIXEL_ANTI_ALIAS } | Enumerates the font edging types.| 
| [OH_Drawing_FontHinting](_drawing.md#oh_drawing_fonthinting) { FONT_HINTING_NONE, FONT_HINTING_SLIGHT, FONT_HINTING_NORMAL, FONT_HINTING_FULL } | Enumerates the font hinting types.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_FontSetThemeFontFollowed](_drawing.md#oh_drawing_fontsetthemefontfollowed) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*font, bool followed) | Sets whether to follow the theme font. When **followed** is set to **true**, the theme font is used if it is enabled by the system and no typeface is set.| 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_FontIsThemeFontFollowed](_drawing.md#oh_drawing_fontisthemefontfollowed) (const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*font, bool \*followed) | Checks whether the font follows the theme font. By default, the theme font is not followed.| 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_FontGetBounds](_drawing.md#oh_drawing_fontgetbounds) (const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*font, const uint16_t \*glyphs, uint32_t count, [OH_Drawing_Array](_drawing.md#oh_drawing_array) \*bounds) | Obtains the rectangular bounding box for each glyph in the glyph array. | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_FontGetPathForGlyph](_drawing.md#oh_drawing_fontgetpathforglyph) (const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*font, uint16_t glyph, [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path) | Obtains the path of a glyph. | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_FontGetTextPath](_drawing.md#oh_drawing_fontgettextpath) (const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*font, const void \*text, size_t byteLength, [OH_Drawing_TextEncoding](_drawing.md#oh_drawing_textencoding) encoding, float x, float y, [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path) | Obtains the text outline path. | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_FontMeasureSingleCharacter](_drawing.md#oh_drawing_fontmeasuresinglecharacter) (const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*font, const char \*str, float \*textWidth) | Measures the width of a single character. If the typeface of the current font does not support the character to measure, the system typeface is used to measure the character width. | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_FontMeasureText](_drawing.md#oh_drawing_fontmeasuretext) (const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*font, const void \*text, size_t byteLength, [OH_Drawing_TextEncoding](_drawing.md#oh_drawing_textencoding) encoding, [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*bounds, float \*textWidth) | Obtains the text width and bounding box.| 
| void [OH_Drawing_FontSetBaselineSnap](_drawing.md#oh_drawing_fontsetbaselinesnap) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, bool baselineSnap) | Sets whether to request that baselines be snapped to pixels when the current canvas matrix is axis aligned.| 
| bool [OH_Drawing_FontIsBaselineSnap](_drawing.md#oh_drawing_fontisbaselinesnap) (const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*) | Checks whether baselines are requested to be snapped to pixels when the current canvas matrix is axis aligned.| 
| void [OH_Drawing_FontSetEdging](_drawing.md#oh_drawing_fontsetedging) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, [OH_Drawing_FontEdging](_drawing.md#oh_drawing_fontedging)) | Sets a font edging effect.| 
| [OH_Drawing_FontEdging](_drawing.md#oh_drawing_fontedging) [OH_Drawing_FontGetEdging](_drawing.md#oh_drawing_fontgetedging) (const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*) | Obtains the font edging effect.| 
| void [OH_Drawing_FontSetForceAutoHinting](_drawing.md#oh_drawing_fontsetforceautohinting) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, bool isForceAutoHinting) | Sets whether to forcibly use auto hinting, that is, whether to always hint glyphs.| 
| bool [OH_Drawing_FontIsForceAutoHinting](_drawing.md#oh_drawing_fontisforceautohinting) (const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*) | Checks whether auto hinting is forcibly used.| 
| void [OH_Drawing_FontSetSubpixel](_drawing.md#oh_drawing_fontsetsubpixel) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, bool isSubpixel) | Sets whether to use sub-pixel rendering for a font.| 
| bool [OH_Drawing_FontIsSubpixel](_drawing.md#oh_drawing_fontissubpixel) (const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*) | Checks whether sub-pixel rendering is used for a font.| 
| [OH_Drawing_Font](_drawing.md#oh_drawing_font) \* [OH_Drawing_FontCreate](_drawing.md#oh_drawing_fontcreate) (void) | Creates an **OH_Drawing_Font** object.| 
| void [OH_Drawing_FontSetTypeface](_drawing.md#oh_drawing_fontsettypeface) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \*) | Sets a typeface for a font.| 
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \* [OH_Drawing_FontGetTypeface](_drawing.md#oh_drawing_fontgettypeface) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*) | Obtains the typeface of a font.| 
| void [OH_Drawing_FontSetTextSize](_drawing.md#oh_drawing_fontsettextsize) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, float textSize) | Sets the text size for a font.| 
| float [OH_Drawing_FontGetTextSize](_drawing.md#oh_drawing_fontgettextsize) (const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*) | Obtains the text size.| 
| int [OH_Drawing_FontCountText](_drawing.md#oh_drawing_fontcounttext) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, const void \*text, size_t byteLength, [OH_Drawing_TextEncoding](_drawing.md#oh_drawing_textencoding) encoding) | Obtains the number of glyphs represented by text.| 
| uint32_t [OH_Drawing_FontTextToGlyphs](_drawing.md#oh_drawing_fonttexttoglyphs) (const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, const void \*text, uint32_t byteLength, [OH_Drawing_TextEncoding](_drawing.md#oh_drawing_textencoding) encoding, uint16_t \*glyphs, int maxGlyphCount) | Converts text into glyph indices.| 
| void [OH_Drawing_FontGetWidths](_drawing.md#oh_drawing_fontgetwidths) (const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, const uint16_t \*glyphs, int count, float \*widths) | Obtains the width of each glyph in a string.| 
| void [OH_Drawing_FontSetLinearText](_drawing.md#oh_drawing_fontsetlineartext) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, bool isLinearText) | Sets linear scaling for a font.| 
| bool [OH_Drawing_FontIsLinearText](_drawing.md#oh_drawing_fontislineartext) (const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*) | Checks whether linear scaling is used for a font.| 
| void [OH_Drawing_FontSetTextSkewX](_drawing.md#oh_drawing_fontsettextskewx) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, float skewX) | Sets a horizontal skew factor for a font.| 
| float [OH_Drawing_FontGetTextSkewX](_drawing.md#oh_drawing_fontgettextskewx) (const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*) | Obtains the horizontal skew factor of a font.| 
| void [OH_Drawing_FontSetFakeBoldText](_drawing.md#oh_drawing_fontsetfakeboldtext) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, bool isFakeBoldText) | Sets fake bold for a font by increasing the stroke width.| 
| bool [OH_Drawing_FontIsFakeBoldText](_drawing.md#oh_drawing_fontisfakeboldtext) (const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*) | Checks whether fake bold is used for a font.| 
| void [OH_Drawing_FontSetScaleX](_drawing.md#oh_drawing_fontsetscalex) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, float scaleX) | Sets a horizontal scale factor for a font.| 
| float [OH_Drawing_FontGetScaleX](_drawing.md#oh_drawing_fontgetscalex) (const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*) | Obtains the horizontal scale factor of a font.| 
| void [OH_Drawing_FontSetHinting](_drawing.md#oh_drawing_fontsethinting) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, [OH_Drawing_FontHinting](_drawing.md#oh_drawing_fonthinting)) | Sets a font hinting effect.| 
| [OH_Drawing_FontHinting](_drawing.md#oh_drawing_fonthinting) [OH_Drawing_FontGetHinting](_drawing.md#oh_drawing_fontgethinting) (const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*) | Obtains the font hinting effect.| 
| void [OH_Drawing_FontSetEmbeddedBitmaps](_drawing.md#oh_drawing_fontsetembeddedbitmaps) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, bool isEmbeddedBitmaps) | Sets whether to use bitmaps in a font.| 
| bool [OH_Drawing_FontIsEmbeddedBitmaps](_drawing.md#oh_drawing_fontisembeddedbitmaps) (const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*) | Checks whether bitmaps are used in a font.| 
| void [OH_Drawing_FontDestroy](_drawing.md#oh_drawing_fontdestroy) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*) | Destroys an **OH_Drawing_Font** object and reclaims the memory occupied by the object.| 
| float [OH_Drawing_FontGetMetrics](_drawing.md#oh_drawing_fontgetmetrics) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) \*) | Obtains the measurement information about a font.| 
