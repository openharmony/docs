# drawing_text_line.h


## Overview

The **drawing_text_line.h** file declares the capabilities for obtaining the character position in a text line, obtaining the run information, and truncating text by line.

**File to include**: <native_drawing/drawing_text_line.h>

**Library**: libnative_drawing.so

**Since**: 16

**Related module**: [Drawing](_drawing.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef bool(\* [Drawing_CaretOffsetsCallback](_drawing.md#drawing_caretoffsetscallback)) (double offset, int32_t index, bool leadingEdge) | Defines a custom callback used to receive the offset and index of each character in a text line object as its parameters. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_Array](_drawing.md#oh_drawing_array) \* [OH_Drawing_TypographyGetTextLines](_drawing.md#oh_drawing_typographygettextlines) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*typography) | Obtains the array of text lines in a typography object. This array contains one or more text line objects. | 
| void [OH_Drawing_DestroyTextLines](_drawing.md#oh_drawing_destroytextlines) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*lines) | Releases the memory occupied by a text line array. | 
| void [OH_Drawing_DestroyTextLine](_drawing.md#oh_drawing_destroytextline) (OH_Drawing_TextLine \*line) | Releases the memory occupied by a text line object. This is applicable only to text line objects that have requested memory on their own and not to a particular text line object within a text line array. | 
| OH_Drawing_TextLine \* [OH_Drawing_GetTextLineByIndex](_drawing.md#oh_drawing_gettextlinebyindex) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*lines, size_t index) | Obtains the text line object with the specified index in a text line array. | 
| double [OH_Drawing_TextLineGetGlyphCount](_drawing.md#oh_drawing_textlinegetglyphcount) (OH_Drawing_TextLine \*line) | Obtains the number of glyphs in a text line object. | 
| void [OH_Drawing_TextLineGetTextRange](_drawing.md#oh_drawing_textlinegettextrange) (OH_Drawing_TextLine \*line, size_t \*start, size_t \*end) | Obtains the range of the text in a text line object in the entire paragraph. | 
| [OH_Drawing_Array](_drawing.md#oh_drawing_array) \* [OH_Drawing_TextLineGetGlyphRuns](_drawing.md#oh_drawing_textlinegetglyphruns) (OH_Drawing_TextLine \*line) | Obtains the array of glyph runs in a text line object. | 
| void [OH_Drawing_DestroyRuns](_drawing.md#oh_drawing_destroyruns) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*runs) | Releases the memory occupied by a glyph run array. | 
| OH_Drawing_Run \* [OH_Drawing_GetRunByIndex](_drawing.md#oh_drawing_getrunbyindex) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*runs, size_t index) | Obtains the glyph run object with the specified index in a glyph run array. | 
| void [OH_Drawing_TextLinePaint](_drawing.md#oh_drawing_textlinepaint) (OH_Drawing_TextLine \*line, [OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*canvas, double x, double y) | Paints a text line on the canvas with the coordinate point (x, y) as the upper left corner. | 
| OH_Drawing_TextLine \* [OH_Drawing_TextLineCreateTruncatedLine](_drawing.md#oh_drawing_textlinecreatetruncatedline) (OH_Drawing_TextLine \*line, double width, int mode, const char \*ellipsis) | Creates a truncated text line object. | 
| double [OH_Drawing_TextLineGetTypographicBounds](_drawing.md#oh_drawing_textlinegettypographicbounds) (OH_Drawing_TextLine \*line, double \*ascent, double \*descent, double \*leading) | Obtains the typographic boundary of a text line object. The typographic boundary is related to the font and font size used for typography, but not the characters within the text. For example, for the string " a b " (which has a space before "a" and a space after "b"), the typographic boundary encompasses the spaces at the beginning and end. For the strings "j" and "E", the typographic boundaries are the same, indicating that they are irrelevant to specific characters. | 
| [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \* [OH_Drawing_TextLineGetImageBounds](_drawing.md#oh_drawing_textlinegetimagebounds) (OH_Drawing_TextLine \*line) | Obtains the image boundary of a text line object. The image boundary, equivalent to a visual boundary, is related to the font, font size, and characters. For example, for the string " a b " (which has a space before "a" and a space after "b"), only "a b" are visible to users, and therefore the image boundary does not include these spaces at the beginning and end. For the strings "j" and "E", their image boundaries are different. Specifically, the width of the boundary for "j" is narrower than that for "E", and the height of the boundary for "j" is taller than that for "E". | 
| double [OH_Drawing_TextLineGetTrailingSpaceWidth](_drawing.md#oh_drawing_textlinegettrailingspacewidth) (OH_Drawing_TextLine \*line) | Obtains the width of the spaces at the end of a text line object. | 
| int32_t [OH_Drawing_TextLineGetStringIndexForPosition](_drawing.md#oh_drawing_textlinegetstringindexforposition) (OH_Drawing_TextLine \*line, [OH_Drawing_Point](_drawing.md#oh_drawing_point) \*point) | Obtains the index of a character at the specified position in a text line object. | 
| double [OH_Drawing_TextLineGetOffsetForStringIndex](_drawing.md#oh_drawing_textlinegetoffsetforstringindex) (OH_Drawing_TextLine \*line, int32_t index) | Obtains the offset of a character with the specified index in a text line object. | 
| void [OH_Drawing_TextLineEnumerateCaretOffsets](_drawing.md#oh_drawing_textlineenumeratecaretoffsets) (OH_Drawing_TextLine \*line, [Drawing_CaretOffsetsCallback](_drawing.md#drawing_caretoffsetscallback) callback) | Enumerates the offset and index of each character in a text line object and passes them to a custom callback function. You can use the offset and index array for other operations. | 
| double [OH_Drawing_TextLineGetAlignmentOffset](_drawing.md#oh_drawing_textlinegetalignmentoffset) (OH_Drawing_TextLine \*line, double alignmentFactor, double alignmentWidth) | Obtains the offset of a text line object after alignment based on the alignment factor and alignment width. | 
