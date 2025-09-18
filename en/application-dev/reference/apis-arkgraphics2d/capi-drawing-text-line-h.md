# drawing_text_line.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @oh_wangxk; @gmiao522; @Lem0nC-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
## Overview

This file declares the capabilities for obtaining the character position in a text line, obtaining the run information, and truncating text by line.

**File to include**: <native_drawing/drawing_text_line.h>

**Library**: libnative_drawing.so

**Since**: 18

**Related module**: [Drawing](capi-drawing.md)

## Summary

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_Drawing_Array* OH_Drawing_TypographyGetTextLines(OH_Drawing_Typography* typography)](#oh_drawing_typographygettextlines) | - | Obtains the array of text lines in a typography object. This array contains one or more text line objects. Release this pointer by calling [OH_Drawing_DestroyTextLines](capi-drawing-text-line-h.md#oh_drawing_destroytextlines) when this object is no longer needed.|
| [void OH_Drawing_DestroyTextLines(OH_Drawing_Array* lines)](#oh_drawing_destroytextlines) | - | Releases the memory occupied by a text line array.|
| [void OH_Drawing_DestroyTextLine(OH_Drawing_TextLine* line)](#oh_drawing_destroytextline) | - | Releases the memory occupied by a text line object. This is applicable only to text line objects that have requested memory on their own and not to a particular text line object within a text line array.|
| [OH_Drawing_TextLine* OH_Drawing_GetTextLineByIndex(OH_Drawing_Array* lines, size_t index)](#oh_drawing_gettextlinebyindex) | - | Obtains the text line object with the specified index in a text line array.|
| [double OH_Drawing_TextLineGetGlyphCount(OH_Drawing_TextLine* line)](#oh_drawing_textlinegetglyphcount) | - | Obtains the number of glyphs in a text line object.|
| [void OH_Drawing_TextLineGetTextRange(OH_Drawing_TextLine* line, size_t* start, size_t* end)](#oh_drawing_textlinegettextrange) | - | Obtains the range of the text in a text line object in the entire paragraph.|
| [OH_Drawing_Array* OH_Drawing_TextLineGetGlyphRuns(OH_Drawing_TextLine* line)](#oh_drawing_textlinegetglyphruns) | - | Obtains the array of glyph runs in a text line object.|
| [void OH_Drawing_DestroyRuns(OH_Drawing_Array* runs)](#oh_drawing_destroyruns) | - | Releases the memory occupied by a glyph run array.|
| [OH_Drawing_Run* OH_Drawing_GetRunByIndex(OH_Drawing_Array* runs, size_t index)](#oh_drawing_getrunbyindex) | - | Obtains the glyph run object with the specified index in a glyph run array.|
| [void OH_Drawing_TextLinePaint(OH_Drawing_TextLine* line, OH_Drawing_Canvas* canvas, double x, double y)](#oh_drawing_textlinepaint) | - | Paints a text line on the canvas with the coordinate point (x, y) as the upper left corner.|
| [OH_Drawing_TextLine* OH_Drawing_TextLineCreateTruncatedLine(OH_Drawing_TextLine* line, double width, int mode,const char* ellipsis)](#oh_drawing_textlinecreatetruncatedline) | - | Creates a truncated text line object.|
| [double OH_Drawing_TextLineGetTypographicBounds(OH_Drawing_TextLine* line, double* ascent, double* descent,double* leading)](#oh_drawing_textlinegettypographicbounds) | - | Obtains the typographic boundary of a text line object. The typographic boundary is related to the font and font size used for typography, but not the characters within the text.<br>For example, for the string " a b " (which has a space before "a" and a space after "b"), the typographic boundary encompasses the spaces at the beginning and end. For the strings "j" and "E", the typographic boundaries are the same, indicating that they are irrelevant to specific characters.|
| [OH_Drawing_Rect* OH_Drawing_TextLineGetImageBounds(OH_Drawing_TextLine* line)](#oh_drawing_textlinegetimagebounds) | - | Obtains the image boundary of a text line object. The image boundary, equivalent to a visual boundary, is related to the font, font size, and characters.<br>For example, for the string " a b " (which has a space before "a" and a space after "b"), only "a b" are visible to users, and therefore the image boundary does not include these spaces at the beginning and end.<br>For the strings "j" and "E", their image boundaries are different. Specifically, the width of the boundary for "j" is narrower than that for "E", and the height of the boundary for "j" is taller than that for "E".|
| [double OH_Drawing_TextLineGetTrailingSpaceWidth(OH_Drawing_TextLine* line)](#oh_drawing_textlinegettrailingspacewidth) | - | Obtains the width of the spaces at the end of a text line object.|
| [int32_t OH_Drawing_TextLineGetStringIndexForPosition(OH_Drawing_TextLine* line, OH_Drawing_Point* point)](#oh_drawing_textlinegetstringindexforposition) | - | Obtains the index of a character at the specified position in a text line object.|
| [double OH_Drawing_TextLineGetOffsetForStringIndex(OH_Drawing_TextLine* line, int32_t index)](#oh_drawing_textlinegetoffsetforstringindex) | - | Obtains the offset of a character with the specified index in a text line object.|
| [typedef bool (\*Drawing_CaretOffsetsCallback)(double offset, int32_t index, bool leadingEdge)](#drawing_caretoffsetscallback) | Drawing_CaretOffsetsCallback | Defines a custom callback used to receive the offset and index of each character in a text line object as its parameters.|
| [void OH_Drawing_TextLineEnumerateCaretOffsets(OH_Drawing_TextLine* line, Drawing_CaretOffsetsCallback callback)](#oh_drawing_textlineenumeratecaretoffsets) | - | Enumerates the offset and index of each character in a text line object and passes them to a custom callback function. You can use the offset and index array for other operations.|
| [double OH_Drawing_TextLineGetAlignmentOffset(OH_Drawing_TextLine* line, double alignmentFactor, double alignmentWidth)](#oh_drawing_textlinegetalignmentoffset) | - | Obtains the offset of a text line object after alignment based on the alignment factor and alignment width.|

## Function Description

### OH_Drawing_TypographyGetTextLines()

```
OH_Drawing_Array* OH_Drawing_TypographyGetTextLines(OH_Drawing_Typography* typography)
```

**Description**

Obtains the array of text lines in a typography object. This array contains one or more text line objects. Release this pointer by calling [OH_Drawing_DestroyTextLines](capi-drawing-text-line-h.md#oh_drawing_destroytextlines) when this object is no longer needed.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md)* typography | Pointer to the [OH_Drawing_Typography](capi-drawing-oh-drawing-typography.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_Array](capi-drawing-oh-drawing-array.md)* | Pointer to the [OH_Drawing_Array](capi-drawing-oh-drawing-array.md) object.|

### OH_Drawing_DestroyTextLines()

```
void OH_Drawing_DestroyTextLines(OH_Drawing_Array* lines)
```

**Description**

Releases the memory occupied by a text line array.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Array](capi-drawing-oh-drawing-array.md)* lines | Pointer to the [OH_Drawing_Array](capi-drawing-oh-drawing-array.md) object.|

### OH_Drawing_DestroyTextLine()

```
void OH_Drawing_DestroyTextLine(OH_Drawing_TextLine* line)
```

**Description**

Releases the memory occupied by a text line object. This is applicable only to text line objects that have requested memory on their own and not to a particular text line object within a text line array.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md)* line | Pointer to the [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md) object.|

### OH_Drawing_GetTextLineByIndex()

```
OH_Drawing_TextLine* OH_Drawing_GetTextLineByIndex(OH_Drawing_Array* lines, size_t index)
```

**Description**

Obtains the text line object with the specified index in a text line array.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Array](capi-drawing-oh-drawing-array.md)* lines | Pointer to the [OH_Drawing_Array](capi-drawing-oh-drawing-array.md) object.|
| size_t index | Index of the text line array.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md)* | Returns a pointer to the [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md) object at the specified index.|

### OH_Drawing_TextLineGetGlyphCount()

```
double OH_Drawing_TextLineGetGlyphCount(OH_Drawing_TextLine* line)
```

**Description**

Obtains the number of glyphs in a text line object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md)* line | Pointer to the [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| double | Returns the number of glyphs in the text line object.|

### OH_Drawing_TextLineGetTextRange()

```
void OH_Drawing_TextLineGetTextRange(OH_Drawing_TextLine* line, size_t* start, size_t* end)
```

**Description**

Obtains the range of the text in a text line object in the entire paragraph.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md)* line | Pointer to the [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md) object.|
| size_t* start | Pointer to the start of the range.|
| size_t* end | Pointer to the end of the range.|

### OH_Drawing_TextLineGetGlyphRuns()

```
OH_Drawing_Array* OH_Drawing_TextLineGetGlyphRuns(OH_Drawing_TextLine* line)
```

**Description**

Obtains the array of glyph runs in a text line object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md)* line | Pointer to the [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_Array](capi-drawing-oh-drawing-array.md)* | Returns a pointer to the [OH_Drawing_Array](capi-drawing-oh-drawing-array.md) array, which holds multiple [OH_Drawing_Run](capi-drawing-oh-drawing-run.md) objects. Release this pointer by calling [OH_Drawing_DestroyRuns](capi-drawing-text-line-h.md#oh_drawing_destroyruns) when this object is no longer needed.|

### OH_Drawing_DestroyRuns()

```
void OH_Drawing_DestroyRuns(OH_Drawing_Array* runs)
```

**Description**

Releases the memory occupied by a glyph run array.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Array](capi-drawing-oh-drawing-array.md)* runs | Pointer to the [OH_Drawing_Array](capi-drawing-oh-drawing-array.md) array, which holds multiple [OH_Drawing_Run](capi-drawing-oh-drawing-run.md) objects.|

### OH_Drawing_GetRunByIndex()

```
OH_Drawing_Run* OH_Drawing_GetRunByIndex(OH_Drawing_Array* runs, size_t index)
```

**Description**

Obtains the glyph run object with the specified index in a glyph run array.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Array](capi-drawing-oh-drawing-array.md)* runs | Pointer to the [OH_Drawing_Array](capi-drawing-oh-drawing-array.md) array, which holds multiple [OH_Drawing_Run](capi-drawing-oh-drawing-run.md) objects.|
| size_t index | Index of the glyph run array.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_Run](capi-drawing-oh-drawing-run.md)* | Returns a pointer to the [OH_Drawing_Run](capi-drawing-oh-drawing-run.md) object at the specified index.|

### OH_Drawing_TextLinePaint()

```
void OH_Drawing_TextLinePaint(OH_Drawing_TextLine* line, OH_Drawing_Canvas* canvas, double x, double y)
```

**Description**

Paints a text line on the canvas with the coordinate point (x, y) as the upper left corner.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md)* line | Pointer to the [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md) object.|
| [OH_Drawing_Canvas](capi-drawing-oh-drawing-canvas.md)* canvas | Pointer to the target canvas [OH_Drawing_Canvas](capi-drawing-oh-drawing-canvas.md).|
| double x | Horizontal coordinate of the upper left corner, in px.|
| double y | Vertical coordinate of the upper left corner, in px.|

### OH_Drawing_TextLineCreateTruncatedLine()

```
OH_Drawing_TextLine* OH_Drawing_TextLineCreateTruncatedLine(OH_Drawing_TextLine* line, double width, int mode,const char* ellipsis)
```

**Description**

Creates a truncated text line object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md)* line | Pointer to the [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md) object.|
| double width | Line width after truncation.|
| int mode | Truncation type. The value is an enumerated value of [OH_Drawing_EllipsisModal](capi-drawing-text-typography-h.md#oh_drawing_ellipsismodal). Currently, only **ELLIPSIS_MODAL_HEAD** and **ELLIPSIS_MODAL_TAIL** are supported.|
| const char* ellipsis | Pointer to the string used to mark a truncation.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md)* | Returns a pointer to the [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md) object of the truncated text line.|

### OH_Drawing_TextLineGetTypographicBounds()

```
double OH_Drawing_TextLineGetTypographicBounds(OH_Drawing_TextLine* line, double* ascent, double* descent,double* leading)
```

**Description**

Obtains the typographic boundary of a text line object. The typographic boundary is related to the font and font size used for typography, but not the characters within the text.<br>For example, for the string " a b " (which has a space before "a" and a space after "b"), the typographic boundaries include the spaces at the beginning and end of the line. Similarly, the strings "j" and "E" have identical typographic boundaries, which are independent of the characters themselves.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md)* line | Pointer to the [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md) object. height = ascent + descent + leading.|
| double* ascent | Pointer to the ascent of the text line object.|
| double* descent | Pointer to the descent of the text line object.|
| double* leading | Pointer to the leading of the text line object.|

**Returns**

| Type| Description|
| -- | -- |
| double | Returns the total width of the layout boundary.|

### OH_Drawing_TextLineGetImageBounds()

```
OH_Drawing_Rect* OH_Drawing_TextLineGetImageBounds(OH_Drawing_TextLine* line)
```

**Description**

Obtains the image boundary of a text line object. The image boundary, equivalent to a visual boundary, is related to the font, font size, and characters.<br>For example, for the string " a b " (which has a space before "a" and a space after "b"), only "a b" are visible to users, and therefore the image boundary does not include these spaces at the beginning and end.<br>For the strings "j" and "E", their image boundaries are different. Specifically, the width of the boundary for "j" is narrower than that for "E", and the height of the boundary for "j" is taller than that for "E".

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md)* line | Pointer to the [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* | Returns the pointer to [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md) of the text line object. Release this pointer by calling [OH_Drawing_RectDestroy](capi-drawing-rect-h.md#oh_drawing_rectdestroy) when this object is no longer needed.|

### OH_Drawing_TextLineGetTrailingSpaceWidth()

```
double OH_Drawing_TextLineGetTrailingSpaceWidth(OH_Drawing_TextLine* line)
```

**Description**

Obtains the width of the spaces at the end of a text line object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md)* line | Pointer to the [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| double | Returns the pointer to the width of the spaces.|

### OH_Drawing_TextLineGetStringIndexForPosition()

```
int32_t OH_Drawing_TextLineGetStringIndexForPosition(OH_Drawing_TextLine* line, OH_Drawing_Point* point)
```

**Description**

Obtains the index of a character at the specified position in a text line object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md)* line | Pointer to the [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md) object.|
| [OH_Drawing_Point](capi-drawing-oh-drawing-point.md)* point | Pointer to the index specified, which is an [OH_Drawing_Point](capi-drawing-oh-drawing-point.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns the index of the character. For example, for the string "abc", the index of "a" is 0, the index of "b" is 1, and the index of "c" is 2. If the specified position is at "a", then **0** is returned.|

### OH_Drawing_TextLineGetOffsetForStringIndex()

```
double OH_Drawing_TextLineGetOffsetForStringIndex(OH_Drawing_TextLine* line, int32_t index)
```

**Description**

Obtains the offset of a character with the specified index in a text line object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md)* line | Pointer to the [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md) object.|
| int32_t index | Index of the character.|

**Returns**

| Type| Description|
| -- | -- |
| double | Returns the offset.|

### Drawing_CaretOffsetsCallback()

```
typedef bool (*Drawing_CaretOffsetsCallback)(double offset, int32_t index, bool leadingEdge)
```

**Description**

Defines a custom callback used to receive the offset and index of each character in a text line object as its parameters.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| double offset | Offset of each character in the text line object.|
|  int32_t index | Index of each character in the text line object.|
|  bool leadingEdge | Whether the cursor is located at the leading edge of a character. **true** means that the cursor is located at the front of the character, that is, the offset does not contain the character width. **false** means that the cursor is located at the rear of the character, that is, the offset contains the character width.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Whether to stop calling the callback. **true** means to stop; **false** otherwise.|

### OH_Drawing_TextLineEnumerateCaretOffsets()

```
void OH_Drawing_TextLineEnumerateCaretOffsets(OH_Drawing_TextLine* line, Drawing_CaretOffsetsCallback callback)
```

**Description**

Enumerates the offset and index of each character in a text line object and passes them to a custom callback function. You can use the offset and index array for other operations.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md)* line | Pointer to the [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md) object.|
| [Drawing_CaretOffsetsCallback](#drawing_caretoffsetscallback) callback | User-defined function [Drawing_CaretOffsetsCallback](capi-drawing-text-line-h.md#drawing_caretoffsetscallback).|

### OH_Drawing_TextLineGetAlignmentOffset()

```
double OH_Drawing_TextLineGetAlignmentOffset(OH_Drawing_TextLine* line, double alignmentFactor, double alignmentWidth)
```

**Description**

Obtains the offset of a text line object after alignment based on the alignment factor and alignment width.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md)* line | Pointer to the [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md) object.|
| double alignmentFactor | Alignment factor, which determines how text is aligned. A value less than or equal to 0.0 means that the text is left-aligned; a value between 0.0 and 0.5 means that the text is slightly left-aligned; the value 0.5 means that the text is centered; a value between 0.5 and 1 means that the text is slightly right-aligned; a value greater than or equal to 1.0 means that the text is right-aligned.|
| double alignmentWidth | Alignment width, that is, the offset of the lower right corner of the text line object relative to the start position. If the specified alignment width is less than the actual width of the text line object, **0** is returned.|

**Returns**

| Type| Description|
| -- | -- |
| double | Returns the offset obtained.|
