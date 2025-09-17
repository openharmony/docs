# drawing_font.h

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphic-->
<!--Owner: @hangmengxin-->
<!--Designer: @wangyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## Overview

This file declares the functions related to the font in the drawing module.

**File to include**: <native_drawing/drawing_font.h>

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](capi-drawing.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_Drawing_Font_Metrics](capi-drawing-oh-drawing-font-metrics.md) | OH_Drawing_Font_Metrics | Describes the measurement information about a font.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_Drawing_FontHinting](#oh_drawing_fonthinting) | OH_Drawing_FontHinting | Defines an enum for the font hinting types.|
| [OH_Drawing_FontEdging](#oh_drawing_fontedging) | OH_Drawing_FontEdging | Defines an enum for the font edging types.|

### Functions

| Name| Description|
| -- | -- |
| [OH_Drawing_ErrorCode OH_Drawing_FontGetSpacing(const OH_Drawing_Font* font, float* spacing)](#oh_drawing_fontgetspacing) | Obtains the recommended line spacing for a font.|
| [OH_Drawing_ErrorCode OH_Drawing_FontGetPos(const OH_Drawing_Font* font, const uint16_t* glyphs, int count,const OH_Drawing_Point* origin, OH_Drawing_Point2D* points)](#oh_drawing_fontgetpos) | Obtains the relative position of each glyph from the specified origin.|
| [OH_Drawing_ErrorCode OH_Drawing_FontGetWidthsBounds(const OH_Drawing_Font* font, const uint16_t* glyphs, int count,const OH_Drawing_Brush* brush, const OH_Drawing_Pen* pen, float* widths, OH_Drawing_Array* bounds)](#oh_drawing_fontgetwidthsbounds) | Obtains the width and bounding box of each glyph in a glyph array.|
| [OH_Drawing_ErrorCode OH_Drawing_FontMeasureTextWithBrushOrPen(const OH_Drawing_Font* font, const void* text,size_t byteLength, OH_Drawing_TextEncoding encoding, const OH_Drawing_Brush* brush, const OH_Drawing_Pen* pen,OH_Drawing_Rect* bounds, float* textWidth)](#oh_drawing_fontmeasuretextwithbrushorpen) | Obtains the width and bounding box of the text with a brush or pen.|
| [OH_Drawing_Font* OH_Drawing_FontCreate(void)](#oh_drawing_fontcreate) | Creates an **OH_Drawing_Font** object.|
| [void OH_Drawing_FontSetBaselineSnap(OH_Drawing_Font* font, bool baselineSnap)](#oh_drawing_fontsetbaselinesnap) | Sets whether to request that baselines be snapped to pixels when the current canvas matrix is axis aligned.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [bool OH_Drawing_FontIsBaselineSnap(const OH_Drawing_Font* font)](#oh_drawing_fontisbaselinesnap) | Checks whether baselines are requested to be snapped to pixels when the current canvas matrix is axis aligned.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_FontSetSubpixel(OH_Drawing_Font* font, bool isSubpixel)](#oh_drawing_fontsetsubpixel) | Sets whether to use sub-pixel rendering for a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [bool OH_Drawing_FontIsSubpixel(const OH_Drawing_Font* font)](#oh_drawing_fontissubpixel) | Checks whether sub-pixel rendering is used for a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_FontSetForceAutoHinting(OH_Drawing_Font* font, bool isForceAutoHinting)](#oh_drawing_fontsetforceautohinting) | Sets whether to forcibly use auto hinting, that is, whether to always hint glyphs.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [bool OH_Drawing_FontIsForceAutoHinting(const OH_Drawing_Font* font)](#oh_drawing_fontisforceautohinting) | Checks whether auto hinting is forcibly used.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_FontSetTypeface(OH_Drawing_Font* font, OH_Drawing_Typeface* typeface)](#oh_drawing_fontsettypeface) | Sets a typeface for a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [OH_Drawing_Typeface* OH_Drawing_FontGetTypeface(OH_Drawing_Font* font)](#oh_drawing_fontgettypeface) | Obtains the typeface of a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_FontSetTextSize(OH_Drawing_Font* font, float textSize)](#oh_drawing_fontsettextsize) | Sets the text size for a font object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [float OH_Drawing_FontGetTextSize(const OH_Drawing_Font* font)](#oh_drawing_fontgettextsize) | Obtains the text size of a font object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [int OH_Drawing_FontCountText(OH_Drawing_Font* font, const void* text, size_t byteLength,OH_Drawing_TextEncoding encoding)](#oh_drawing_fontcounttext) | Obtains the number of glyphs represented by text.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either **font** or **text** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [uint32_t OH_Drawing_FontTextToGlyphs(const OH_Drawing_Font* font, const void* text, uint32_t byteLength,OH_Drawing_TextEncoding encoding, uint16_t* glyphs, int maxGlyphCount)](#oh_drawing_fonttexttoglyphs) | Converts text into glyph indices.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If any of **font**, **text**, and **glyphs** is NULL, **byteLength** is **0**, or **maxGlyphCount** is less than or equal to 0, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_FontGetWidths(const OH_Drawing_Font* font, const uint16_t* glyphs, int count, float* widths)](#oh_drawing_fontgetwidths) | Obtains the width of each glyph in a string of text.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If any of **font**, **glyphs**, and **widths** is NULL or **count** is less than or equal to 0, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [OH_Drawing_ErrorCode OH_Drawing_FontMeasureSingleCharacter(const OH_Drawing_Font* font, const char* str,float* textWidth)](#oh_drawing_fontmeasuresinglecharacter) | Measures the width of a single character. If the typeface of the current font does not support the character to measure, the system typeface is used to measure the character width.|
| [OH_Drawing_ErrorCode OH_Drawing_FontMeasureText(const OH_Drawing_Font* font, const void* text, size_t byteLength,OH_Drawing_TextEncoding encoding, OH_Drawing_Rect* bounds, float* textWidth)](#oh_drawing_fontmeasuretext) | Obtains the text width and bounding box.|
| [void OH_Drawing_FontSetLinearText(OH_Drawing_Font* font, bool isLinearText)](#oh_drawing_fontsetlineartext) | Sets linear scaling for a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [bool OH_Drawing_FontIsLinearText(const OH_Drawing_Font* font)](#oh_drawing_fontislineartext) | Checks whether linear scaling is used for a font object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_FontSetTextSkewX(OH_Drawing_Font* font, float skewX)](#oh_drawing_fontsettextskewx) | Sets a horizontal skew factor for a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [float OH_Drawing_FontGetTextSkewX(const OH_Drawing_Font* font)](#oh_drawing_fontgettextskewx) | Obtains the horizontal skew factor of a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_FontSetFakeBoldText(OH_Drawing_Font* font, bool isFakeBoldText)](#oh_drawing_fontsetfakeboldtext) | Sets fake bold for a font by increasing the stroke width.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [bool OH_Drawing_FontIsFakeBoldText(const OH_Drawing_Font* font)](#oh_drawing_fontisfakeboldtext) | Checks whether fake bold is used for a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_FontSetScaleX(OH_Drawing_Font* font, float scaleX)](#oh_drawing_fontsetscalex) | Sets a horizontal scale factor for a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [float OH_Drawing_FontGetScaleX(const OH_Drawing_Font* font)](#oh_drawing_fontgetscalex) | Obtains the horizontal scale ratio of this font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_FontSetHinting(OH_Drawing_Font* font, OH_Drawing_FontHinting fontHinting)](#oh_drawing_fontsethinting) | Sets a font hinting effect.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.<br>If **fontHinting** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.|
| [OH_Drawing_FontHinting OH_Drawing_FontGetHinting(const OH_Drawing_Font* font)](#oh_drawing_fontgethinting) | Obtains the font hinting effect.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_FontSetEmbeddedBitmaps(OH_Drawing_Font* font, bool isEmbeddedBitmaps)](#oh_drawing_fontsetembeddedbitmaps) | Sets whether to use bitmaps in a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [bool OH_Drawing_FontIsEmbeddedBitmaps(const OH_Drawing_Font* font)](#oh_drawing_fontisembeddedbitmaps) | Checks whether bitmaps are used in a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_FontSetEdging(OH_Drawing_Font* font, OH_Drawing_FontEdging fontEdging)](#oh_drawing_fontsetedging) | Sets a font edging effect.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.<br>If **fontEdging** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.|
| [OH_Drawing_FontEdging OH_Drawing_FontGetEdging(const OH_Drawing_Font* font)](#oh_drawing_fontgetedging) | Obtains the font edging effect.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_FontDestroy(OH_Drawing_Font* font)](#oh_drawing_fontdestroy) | Destroys an **OH_Drawing_Font** object and reclaims the memory occupied by the object.|
| [float OH_Drawing_FontGetMetrics(OH_Drawing_Font* font, OH_Drawing_Font_Metrics* fontMetrics)](#oh_drawing_fontgetmetrics) | Obtains the measurement information about a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either **font** or **fontMetrics** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [OH_Drawing_ErrorCode OH_Drawing_FontGetBounds(const OH_Drawing_Font* font, const uint16_t* glyphs, uint32_t count,OH_Drawing_Array* bounds)](#oh_drawing_fontgetbounds) | Obtains the rectangular bounding box for each glyph in the glyph array.|
| [OH_Drawing_ErrorCode OH_Drawing_FontGetPathForGlyph(const OH_Drawing_Font* font, uint16_t glyph,OH_Drawing_Path* path)](#oh_drawing_fontgetpathforglyph) | Obtains the path of a glyph.|
| [OH_Drawing_ErrorCode OH_Drawing_FontGetTextPath(const OH_Drawing_Font* font, const void* text, size_t byteLength,OH_Drawing_TextEncoding encoding, float x, float y, OH_Drawing_Path* path)](#oh_drawing_fontgettextpath) | Obtains the text outline path.|
| [OH_Drawing_ErrorCode OH_Drawing_FontSetThemeFontFollowed(OH_Drawing_Font* font, bool followed)](#oh_drawing_fontsetthemefontfollowed) | Sets whether to follow the theme font. When **followed** is set to **true**, the theme font is used if it is enabled by the system and no typeface is set.|
| [OH_Drawing_ErrorCode OH_Drawing_FontIsThemeFontFollowed(const OH_Drawing_Font* font, bool* followed)](#oh_drawing_fontisthemefontfollowed) | Checks whether the font follows the theme font. By default, the theme font is not followed.|
| [OH_Drawing_ErrorCode OH_Drawing_FontMeasureSingleCharacterWithFeatures(const OH_Drawing_Font* font, const char* str,const OH_Drawing_FontFeatures* fontFeatures, float* textWidth)](#oh_drawing_fontmeasuresinglecharacterwithfeatures) | Measures the width of a single character with font features. If the typeface of the current font does not support the character to measure, the system typeface is used to measure the character width.|
| [OH_Drawing_FontFeatures* OH_Drawing_FontFeaturesCreate(void)](#oh_drawing_fontfeaturescreate) | Creates an **OH_Drawing_FontFeatures** object.|
| [OH_Drawing_ErrorCode OH_Drawing_FontFeaturesAddFeature(OH_Drawing_FontFeatures* fontFeatures,const char* name, float value)](#oh_drawing_fontfeaturesaddfeature) | Adds a font feature to an **OH_Drawing_FontFeatures** object.|
| [OH_Drawing_ErrorCode OH_Drawing_FontFeaturesDestroy(OH_Drawing_FontFeatures* fontFeatures)](#oh_drawing_fontfeaturesdestroy) | Destroys an **OH_Drawing_FontFeatures** object and reclaims the memory occupied by the object.|

## Enum Description

### OH_Drawing_FontHinting

```
enum OH_Drawing_FontHinting
```

**Description**

Defines an enum for the font hinting types.

**Since**: 12

| Value| Description|
| -- | -- |
| FONT_HINTING_NONE | No font hinting is used.|
| FONT_HINTING_SLIGHT | Slight font hinting is used to improve contrast.|
| FONT_HINTING_NORMAL | Normal font hinting is used to improve contrast.|
| FONT_HINTING_FULL | Full font hinting is used to improve contrast.|

### OH_Drawing_FontEdging

```
enum OH_Drawing_FontEdging
```

**Description**

Enumerates the font edging types.

**Since**: 12

| Value| Description|
| -- | -- |
| FONT_EDGING_ALIAS | No anti-aliasing processing is used.|
| FONT_EDGING_ANTI_ALIAS | Uses anti-aliasing to smooth the jagged edges.|
| FONT_EDGING_SUBPIXEL_ANTI_ALIAS | Uses sub-pixel anti-aliasing to provide a smoother effect for jagged edges.|


## Function Description

### OH_Drawing_FontMeasureSingleCharacterWithFeatures()

```
OH_Drawing_ErrorCode OH_Drawing_FontMeasureSingleCharacterWithFeatures(const OH_Drawing_Font* font, const char* str, const OH_Drawing_FontFeatures* fontFeatures, float* textWidth)
```

**Description**

Measures the width of a single character with font features. If the typeface of the current font does not support the character to measure, the system typeface is used to measure the character width.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [const OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| const char* str | Pointer to the single character to measure. A string can be passed in, but only the first character in the string is parsed and measured in UTF-8 encoding.|
| [const OH_Drawing_FontFeatures](capi-drawing-oh-drawing-fontfeatures.md)* fontFeatures | Pointer to the [OH_Drawing_FontFeatures](capi-drawing-oh-drawing-fontfeatures.md) object. If no font feature is set, the preset font feature in the TrueType fonts (TTF) file is used.|
| float* textWidth | Pointer to the obtained text width, which is used as an output parameter.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Execution result.<br>**OH_DRAWING_SUCCESS** if the operation is successful.<br>Returns **OH_DRAWING_ERROR_INVALID_PARAMETER** if at least one of the parameters **font**, **str**, **fontFeatures**, or **textWidth** is NULL, or the length of **str** is **0**.|

### OH_Drawing_FontFeaturesCreate()

```
OH_Drawing_FontFeatures* OH_Drawing_FontFeaturesCreate(void)
```

**Description**

Creates an **OH_Drawing_FontFeatures** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_FontFeatures](capi-drawing-oh-drawing-fontfeatures.md)* | Returns a pointer to the created [OH_Drawing_FontFeatures](capi-drawing-oh-drawing-fontfeatures.md) object.<br>If a null pointer is returned, the creation fails. A possible cause is that no memory is available.|

### OH_Drawing_FontFeaturesAddFeature()

```
OH_Drawing_ErrorCode OH_Drawing_FontFeaturesAddFeature(OH_Drawing_FontFeatures* fontFeatures, const char* name, float value)
```

**Description**

Adds a font feature to an **OH_Drawing_FontFeatures** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontFeatures](capi-drawing-oh-drawing-fontfeatures.md)* fontFeatures | Pointer to the [OH_Drawing_FontFeatures](capi-drawing-oh-drawing-fontfeatures.md) object.|
| const char* name | Name of a font feature. Common font feature names include **liga**, **frac**, and **case**. A font feature needs a TTF file to work.|
| float value | Value of the font feature. You are advised to determine the valid value range by using a font viewing tool or referring to the font document.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Execution result.<br>**OH_DRAWING_SUCCESS** if the operation is successful.<br>Returns **OH_DRAWING_ERROR_INVALID_PARAMETER** if **fontFeatures** or **name** is a null pointer.|

### OH_Drawing_FontFeaturesDestroy()

```
OH_Drawing_ErrorCode OH_Drawing_FontFeaturesDestroy(OH_Drawing_FontFeatures* fontFeatures)
```

**Description**

Destroys an **OH_Drawing_FontFeatures** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontFeatures](capi-drawing-oh-drawing-fontfeatures.md)* fontFeatures | Pointer to the [OH_Drawing_FontFeatures](capi-drawing-oh-drawing-fontfeatures.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Execution result.<br>**OH_DRAWING_SUCCESS** if the operation is successful.<br>Returns **OH_DRAWING_ERROR_INVALID_PARAMETER** if **fontFeatures** is NULL.|

### OH_Drawing_FontMeasureTextWithBrushOrPen()

```
OH_Drawing_ErrorCode OH_Drawing_FontMeasureTextWithBrushOrPen(const OH_Drawing_Font* font, const void* text,size_t byteLength, OH_Drawing_TextEncoding encoding, const OH_Drawing_Brush* brush, const OH_Drawing_Pen* pen,OH_Drawing_Rect* bounds, float* textWidth)
```

**Description**

Obtains the width and bounding box of the text with a brush or pen.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 19

**Parameters**

| Name| Description|
| -- | -- |
| const OH_Drawing_Font* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| const void* text | Pointer to the text.|
| size_t byteLength | Length of the text, in bytes.|
| [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding) encoding | Encoding type of the text.|
| const OH_Drawing_Brush* brush | Pointer to the [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md) object.|
| const OH_Drawing_Pen* pen | Pointer to the [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md) object.|
| OH_Drawing_Rect* bounds | Pointer to the bounding box. The value can be NULL.|
| float* textWidth | Pointer to the text width.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Operation code.<br>**OH_DRAWING_SUCCESS** if the operation is successful.<br>Returns **OH_DRAWING_ERROR_INVALID_PARAMETER** if any of **font**, **text**, or **textWidth** is NULL, **byteLength** is **0**, or a brush and a pen both exist.|

### OH_Drawing_FontGetWidthsBounds()

```
OH_Drawing_ErrorCode OH_Drawing_FontGetWidthsBounds(const OH_Drawing_Font* font, const uint16_t* glyphs, int count,const OH_Drawing_Brush* brush, const OH_Drawing_Pen* pen, float* widths, OH_Drawing_Array* bounds)
```

**Description**

Obtains the width and bounding box of each glyph in a glyph array.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 19

**Parameters**

| Name| Description|
| -- | -- |
| const OH_Drawing_Font* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| const uint16_t* glyphs | Pointer to the start address for storing the glyph indices.|
| int count | Number of glyph indices, which must be the same as the size of glyphs array.|
| const OH_Drawing_Brush* brush | Pointer to the [OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md) object.|
| const OH_Drawing_Pen* pen | Pointer to the [OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md) object.|
| float* widths | Start address for storing the glyph width.|
| OH_Drawing_Array* bounds | Start address for storing the glyph bounding box.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Operation code.<br>**OH_DRAWING_SUCCESS** if the operation is successful.<br>Returns **OH_DRAWING_ERROR_INVALID_PARAMETER** if either **font** or **glyphs** is NULL, **count** is not greater than **0**, a brush and a pen both exist, or both **widths** and **bounds** are NULL.|

### OH_Drawing_FontGetPos()

```
OH_Drawing_ErrorCode OH_Drawing_FontGetPos(const OH_Drawing_Font* font, const uint16_t* glyphs, int count,const OH_Drawing_Point* origin, OH_Drawing_Point2D* points)
```

**Description**

Obtains the relative position of each glyph from the specified origin.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 19

**Parameters**

| Name| Description|
| -- | -- |
| const OH_Drawing_Font* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| const uint16_t* glyphs | Pointer to the start address for storing the glyph indices.|
| int count | Number of glyph indices, which must be the same as the size of glyphs array.|
| const OH_Drawing_Point* origin | Position of the first glyph. The value can be NULL, which means that the default value **(0, 0)** is used.|
| [OH_Drawing_Point2D](capi-drawing-oh-drawing-point2d.md)* points | Start address for storing the relative position of a glyph.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Operation code.<br>**OH_DRAWING_SUCCESS** if the operation is successful.<br>Returns **OH_DRAWING_ERROR_INVALID_PARAMETER** if any of **font**, **glyphs**, and **points** is NULL, or **count** is less than or equal to **0**.|

### OH_Drawing_FontGetSpacing()

```
OH_Drawing_ErrorCode OH_Drawing_FontGetSpacing(const OH_Drawing_Font* font, float* spacing)
```

**Description**

Obtains the recommended line spacing for a font.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 19

**Parameters**

| Name| Description|
| -- | -- |
| const OH_Drawing_Font* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| float* spacing | Recommended line spacing for a font.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Operation code.<br>**OH_DRAWING_SUCCESS** if the operation is successful.<br>Returns **OH_DRAWING_ERROR_INVALID_PARAMETER** if either **font** or **spacing** is NULL.|

### OH_Drawing_FontCreate()

```
OH_Drawing_Font* OH_Drawing_FontCreate(void)
```

**Description**

Creates an **OH_Drawing_Font** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* | Returns the pointer to the **OH_Drawing_Font** object created.|

### OH_Drawing_FontSetBaselineSnap()

```
void OH_Drawing_FontSetBaselineSnap(OH_Drawing_Font* font, bool baselineSnap)
```

**Description**

Sets whether to request that baselines be snapped to pixels when the current canvas matrix is axis aligned.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| bool baselineSnap | Whether the font baseline is snapped to pixels. **true** means yes; **false** otherwise.|

### OH_Drawing_FontIsBaselineSnap()

```
bool OH_Drawing_FontIsBaselineSnap(const OH_Drawing_Font* font)
```

**Description**

Checks whether baselines are requested to be snapped to pixels when the current canvas matrix is axis aligned.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Whether the font baseline is snapped to pixels. **true** means yes; **false** otherwise.|

### OH_Drawing_FontSetSubpixel()

```
void OH_Drawing_FontSetSubpixel(OH_Drawing_Font* font, bool isSubpixel)
```

**Description**

Sets whether to use sub-pixel rendering for a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| bool isSubpixel | Whether sub-pixel rendering is used for a font. **true** means yes; **false** otherwise.|

### OH_Drawing_FontIsSubpixel()

```
bool OH_Drawing_FontIsSubpixel(const OH_Drawing_Font* font)
```

**Description**

Checks whether sub-pixel rendering is used for a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Whether sub-pixel rendering is used for a font. **true** means yes; **false** otherwise.|

### OH_Drawing_FontSetForceAutoHinting()

```
void OH_Drawing_FontSetForceAutoHinting(OH_Drawing_Font* font, bool isForceAutoHinting)
```

**Description**

Sets whether to forcibly use auto hinting, that is, whether to always hint glyphs.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| bool isForceAutoHinting | Whether to forcibly use auto hinting, that is, whether to always hint glyphs. **true** means yes; **false** otherwise.|

### OH_Drawing_FontIsForceAutoHinting()

```
bool OH_Drawing_FontIsForceAutoHinting(const OH_Drawing_Font* font)
```

**Description**

Checks whether auto hinting is forcibly used.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Whether auto hinting is forcibly used. **true** means yes; **false** otherwise.|

### OH_Drawing_FontSetTypeface()

```
void OH_Drawing_FontSetTypeface(OH_Drawing_Font* font, OH_Drawing_Typeface* typeface)
```

**Description**

Sets a typeface for a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to an **OH_Drawing_Font** object.|
| [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md)* typeface | Pointer to an **OH_Drawing_Typeface** object. If NULL is passed in, the default **OH_Drawing_Typeface** object is used.|

### OH_Drawing_FontGetTypeface()

```
OH_Drawing_Typeface* OH_Drawing_FontGetTypeface(OH_Drawing_Font* font)
```

**Description**

Obtains the typeface of a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md)* | Returns a pointer to the [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md) object.|

### OH_Drawing_FontSetTextSize()

```
void OH_Drawing_FontSetTextSize(OH_Drawing_Font* font, float textSize)
```

**Description**

Sets the text size for a font object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to an **OH_Drawing_Font** object.|
| float textSize | Text size. The value is a floating point number. If a negative number is passed in, the size is set to 0. If the size is 0, the text drawn will not be displayed.|

### OH_Drawing_FontGetTextSize()

```
float OH_Drawing_FontGetTextSize(const OH_Drawing_Font* font)
```

**Description**

Obtains the text size of a font object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| float | Returns a floating point number representing the text size.|

### OH_Drawing_FontCountText()

```
int OH_Drawing_FontCountText(OH_Drawing_Font* font, const void* text, size_t byteLength,OH_Drawing_TextEncoding encoding)
```

**Description**

Obtains the number of glyphs represented by text.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either **font** or **text** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| const void* text | Pointer to the start address of the storage.|
| size_t byteLength | Text length, in bytes.|
| [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding) encoding | Text encoding type [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding).|

### OH_Drawing_FontTextToGlyphs()

```
uint32_t OH_Drawing_FontTextToGlyphs(const OH_Drawing_Font* font, const void* text, uint32_t byteLength,OH_Drawing_TextEncoding encoding, uint16_t* glyphs, int maxGlyphCount)
```

**Description**

Converts text into glyph indices.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If any of **font**, **text**, and **glyphs** is NULL, **byteLength** is **0**, or **maxGlyphCount** is less than or equal to 0, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| const void* text | Pointer to the start address of the storage.|
| uint32_t byteLength | Text length, in bytes.|
| [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding) encoding | Text encoding type [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding).|
| uint16_t* glyphs | Pointer to the start address for storing the glyph indices.|
| int maxGlyphCount | Maximum number of glyphs.|

**Returns**

| Type| Description|
| -- | -- |
| uint32_t | Returns the number of glyph indices.|

### OH_Drawing_FontGetWidths()

```
void OH_Drawing_FontGetWidths(const OH_Drawing_Font* font, const uint16_t* glyphs, int count, float* widths)
```

**Description**

Obtains the width of each glyph in a string of text.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If any of **font**, **glyphs**, and **widths** is NULL, or **count** is **0**, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| const uint16_t* glyphs | Pointer to the start address for storing the glyph indices.|
| int count | Number of glyph indices.|
| float* widths | Pointer to the start address for storing the glyph widths.|

### OH_Drawing_FontMeasureSingleCharacter()

```
OH_Drawing_ErrorCode OH_Drawing_FontMeasureSingleCharacter(const OH_Drawing_Font* font, const char* str,float* textWidth)
```

**Description**

Measures the width of a single character. If the typeface of the current font does not support the character to measure, the system typeface is used to measure the character width.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| const char* str | Pointer to the single character to measure. A string can be passed in, but only the first character in the string is parsed and measured in UTF-8 encoding.|
| float* textWidth | Pointer to the character width obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Returns one of the following result codes:<br> **OH_DRAWING_SUCCESS** if the operation is successful.<br> **OH_DRAWING_ERROR_INVALID_PARAMETER** if at least one of the parameters **font**, **str**, or **textWidth** is NULL, or the length of **str** is **0**.|

### OH_Drawing_FontMeasureText()

```
OH_Drawing_ErrorCode OH_Drawing_FontMeasureText(const OH_Drawing_Font* font, const void* text, size_t byteLength,OH_Drawing_TextEncoding encoding, OH_Drawing_Rect* bounds, float* textWidth)
```

**Description**

Obtains the text width and bounding box.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| const void* text | Pointer to the text.|
| size_t byteLength | Length of the text, in bytes.|
| [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding) encoding | Encoding type of the text.|
| [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* bounds | Pointer to the bounding box. The value can be NULL.|
| float* textWidth | Pointer to the text width.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Returns one of the following result codes:<br> **OH_DRAWING_SUCCESS** if the operation is successful.<br> **OH_DRAWING_ERROR_INVALID_PARAMETER** if at least one of the parameters **font**, **text**, and **textWidth** is NULL, or **byteLength** is **0**.|

### OH_Drawing_FontSetLinearText()

```
void OH_Drawing_FontSetLinearText(OH_Drawing_Font* font, bool isLinearText)
```

**Description**

Sets linear scaling for a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to an **OH_Drawing_Font** object.|
| bool isLinearText | Whether to enable linear scaling. The value **true** means to enable linear scaling, and **false** means the opposite.|

### OH_Drawing_FontIsLinearText()

```
bool OH_Drawing_FontIsLinearText(const OH_Drawing_Font* font)
```

**Description**

Checks whether linear scaling is used for a font object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Returns **true** if linear scaling is used; returns **false** otherwise.|

### OH_Drawing_FontSetTextSkewX()

```
void OH_Drawing_FontSetTextSkewX(OH_Drawing_Font* font, float skewX)
```

**Description**

Sets a horizontal skew factor for a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to an **OH_Drawing_Font** object.|
| float skewX | Skew of the X axis relative to the Y axis.|

### OH_Drawing_FontGetTextSkewX()

```
float OH_Drawing_FontGetTextSkewX(const OH_Drawing_Font* font)
```

**Description**

Obtains the horizontal skew factor of a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| float | Returns a floating point number representing the horizontal skew factor.|

### OH_Drawing_FontSetFakeBoldText()

```
void OH_Drawing_FontSetFakeBoldText(OH_Drawing_Font* font, bool isFakeBoldText)
```

**Description**

Sets fake bold for a font by increasing the stroke width.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to an **OH_Drawing_Font** object.|
| bool isFakeBoldText | Whether to set fake bold. The value **true** means to set fake bold, and **false** means the opposite.|

### OH_Drawing_FontIsFakeBoldText()

```
bool OH_Drawing_FontIsFakeBoldText(const OH_Drawing_Font* font)
```

**Description**

Checks whether fake bold is used for a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Whether fake bold is used for a font. **true** means yes; **false** otherwise.|

### OH_Drawing_FontSetScaleX()

```
void OH_Drawing_FontSetScaleX(OH_Drawing_Font* font, float scaleX)
```

**Description**

Sets a horizontal scale factor for a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| float scaleX | Horizontal scale factor.|

### OH_Drawing_FontGetScaleX()

```
float OH_Drawing_FontGetScaleX(const OH_Drawing_Font* font)
```

**Description**

Obtains the horizontal scale ratio of this font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| float | Returns the horizontal scale factor.|

### OH_Drawing_FontSetHinting()

```
void OH_Drawing_FontSetHinting(OH_Drawing_Font* font, OH_Drawing_FontHinting fontHinting)
```

**Description**

Sets a font hinting effect.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.<br>If **fontHinting** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| [OH_Drawing_FontHinting](#oh_drawing_fonthinting) fontHinting | Enumeration of font hinting types [OH_Drawing_FontHinting](capi-drawing-font-h.md#oh_drawing_fonthinting).|

### OH_Drawing_FontGetHinting()

```
OH_Drawing_FontHinting OH_Drawing_FontGetHinting(const OH_Drawing_Font* font)
```

**Description**

Obtains the font hinting effect.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_FontHinting](#oh_drawing_fonthinting) | Returns the enumeration of font hinting types [OH_Drawing_FontHinting](capi-drawing-font-h.md#oh_drawing_fonthinting).|

### OH_Drawing_FontSetEmbeddedBitmaps()

```
void OH_Drawing_FontSetEmbeddedBitmaps(OH_Drawing_Font* font, bool isEmbeddedBitmaps)
```

**Description**

Sets whether to use bitmaps in a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| bool isEmbeddedBitmaps | Whether to use bitmaps in the font. The value **true** means to use bitmaps in the font, and **false** means the opposite.|

### OH_Drawing_FontIsEmbeddedBitmaps()

```
bool OH_Drawing_FontIsEmbeddedBitmaps(const OH_Drawing_Font* font)
```

**Description**

Checks whether bitmaps are used in a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Returns **true** if bitmaps are used; returns **false** otherwise.|

### OH_Drawing_FontSetEdging()

```
void OH_Drawing_FontSetEdging(OH_Drawing_Font* font, OH_Drawing_FontEdging fontEdging)
```

**Description**

Sets a font edging effect.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.<br>If **fontEdging** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| [OH_Drawing_FontEdging](#oh_drawing_fontedging) fontEdging | Font edging effect.|

### OH_Drawing_FontGetEdging()

```
OH_Drawing_FontEdging OH_Drawing_FontGetEdging(const OH_Drawing_Font* font)
```

**Description**

Obtains the font edging effect.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **font** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_FontEdging](#oh_drawing_fontedging) | Font edging effect.|

### OH_Drawing_FontDestroy()

```
void OH_Drawing_FontDestroy(OH_Drawing_Font* font)
```

**Description**

Destroys an **OH_Drawing_Font** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to an **OH_Drawing_Font** object.|

### OH_Drawing_FontGetMetrics()

```
float OH_Drawing_FontGetMetrics(OH_Drawing_Font* font, OH_Drawing_Font_Metrics* fontMetrics)
```

**Description**

Obtains the measurement information about a font.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either **font** or **fontMetrics** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| [OH_Drawing_Font_Metrics](capi-drawing-oh-drawing-font-metrics.md)* fontMetrics | Pointer to the [OH_Drawing_Font_Metrics](capi-drawing-oh-drawing-font-metrics.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| float | Returns a floating-point variable that indicates the recommended interline spacing.|

### OH_Drawing_FontGetBounds()

```
OH_Drawing_ErrorCode OH_Drawing_FontGetBounds(const OH_Drawing_Font* font, const uint16_t* glyphs, uint32_t count,OH_Drawing_Array* bounds)
```

**Description**

Obtains the rectangular bounding box for each glyph in the glyph array.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| const uint16_t* glyphs | Pointer to a glyph array.|
| uint32_t count | Length of the glyph array.|
| [OH_Drawing_Array](capi-drawing-oh-drawing-array.md)* bounds | Pointer to a rectangular bounding box array.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Returns one of the following result codes:<br> **OH_DRAWING_SUCCESS** if the operation is successful.<br> **OH_DRAWING_ERROR_INVALID_PARAMETER** if any of **font**, **glyphs**, or **bounds** is NULL or **count** is **0**.|

### OH_Drawing_FontGetPathForGlyph()

```
OH_Drawing_ErrorCode OH_Drawing_FontGetPathForGlyph(const OH_Drawing_Font* font, uint16_t glyph,OH_Drawing_Path* path)
```

**Description**

Obtains the path of a glyph.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| uint16_t glyph | Glyph index.|
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | Pointer to the [OH_Drawing_Path](capi-drawing-oh-drawing-path.md) object, which is used to store the glyph path.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Returns one of the following result codes:<br> **OH_DRAWING_SUCCESS** if the operation is successful.<br> **OH_DRAWING_ERROR_INVALID_PARAMETER** if **font** or **path** is NULL or the specified glyph does not exist.|

### OH_Drawing_FontGetTextPath()

```
OH_Drawing_ErrorCode OH_Drawing_FontGetTextPath(const OH_Drawing_Font* font, const void* text, size_t byteLength,OH_Drawing_TextEncoding encoding, float x, float y, OH_Drawing_Path* path)
```

**Description**

Obtains the text outline path.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| const void* text | Pointer to the text string.|
| size_t byteLength | Length of the text path. If the length is greater than the length of the text string, undefined behavior occurs.|
| [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding) encoding | Text encoding format. UTF-8, UTF-16, UTF-32, and glyph indices are supported. For details about the format, see [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding).|
| float x | X coordinate of the text in the drawing area, with the origin as the start point.|
| float y | Y coordinate of the text in the drawing area, with the origin as the start point.|
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | Pointer to the text outline path.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Returns one of the following error codes:<br> Returns [OH_DRAWING_SUCCESS](capi-drawing-error-code-h.md#oh_drawing_errorcode) if the operation is successful.<br> Returns [OH_DRAWING_ERROR_INVALID_PARAMETER](capi-drawing-error-code-h.md#oh_drawing_errorcode) if any of **font**, **text**, or **path** is NULL.|

### OH_Drawing_FontSetThemeFontFollowed()

```
OH_Drawing_ErrorCode OH_Drawing_FontSetThemeFontFollowed(OH_Drawing_Font* font, bool followed)
```

**Description**

Sets whether to follow the theme font. When **followed** is set to **true**, the theme font is used if it is enabled by the system and no typeface is set.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| bool followed | Whether to follow the theme font. The value **true** means to follow the theme font, and **false** means the opposite.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Returns one of the following result codes:<br> **OH_DRAWING_SUCCESS** if the operation is successful.<br> Returns **OH_DRAWING_ERROR_INVALID_PARAMETER** if **font** is NULL.|

### OH_Drawing_FontIsThemeFontFollowed()

```
OH_Drawing_ErrorCode OH_Drawing_FontIsThemeFontFollowed(const OH_Drawing_Font* font, bool* followed)
```

**Description**

Checks whether the font follows the theme font. By default, the theme font is not followed.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | Pointer to the [OH_Drawing_Font](capi-drawing-oh-drawing-font.md) object.|
| bool* followed | Check result. The value **true** means that the theme font is followed, and **false** means the opposite. It as an output parameter.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Returns one of the following result codes:<br> **OH_DRAWING_SUCCESS** if the operation is successful.<br> Returns **OH_DRAWING_ERROR_INVALID_PARAMETER** if either **font** or **followed** is NULL.|
