# drawing_text_line.h


## 概述

提供获取文本行内的字符位置、获取渲染单元信息和按行截断等功能。

**引用文件：** <native_drawing/drawing_text_line.h>

**库：** libnative_drawing.so

**起始版本：** 14

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef bool(\* [Drawing_CaretOffsetsCallback](_drawing.md#drawing_caretoffsetscallback)) (double offset, int32_t index, bool leadingEdge) | 用户自定义的回调函数。将文本行对象中每个字符的偏移量、索引值作为参数传递给用户自定义的回调函数。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_Array](_drawing.md#oh_drawing_array) \* [OH_Drawing_TypographyGetTextLines](_drawing.md#oh_drawing_typographygettextlines) ([OH_Drawing_Typography](_drawing.md#oh_drawing_typography) \*typography) | 获取排版对象的文本行数组。文本行数组中包含一个或多个文本行对象。  | 
| void [OH_Drawing_DestroyTextLines](_drawing.md#oh_drawing_destroytextlines) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*lines) | 释放文本行数组的内存。  | 
| void [OH_Drawing_DestroyTextLine](_drawing.md#oh_drawing_destroytextline) (OH_Drawing_TextLine \*line) | 释放单个文本行对象的内存。只能释放单独申请内存的文本行对象，不能释放文本行数组中的某一个文本行对象的内存。  | 
| OH_Drawing_TextLine \* [OH_Drawing_GetTextLineByIndex](_drawing.md#oh_drawing_gettextlinebyindex) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*lines, size_t index) | 获取文本行数组指定索引处的文本行对象。  | 
| double [OH_Drawing_TextLineGetGlyphCount](_drawing.md#oh_drawing_textlinegetglyphcount) (OH_Drawing_TextLine \*line) | 获取文本行对象中字形的数量。  | 
| void [OH_Drawing_TextLineGetTextRange](_drawing.md#oh_drawing_textlinegettextrange) (OH_Drawing_TextLine \*line, size_t \*start, size_t \*end) | 获取文本行对象中的文本在整个段落文本中的索引区间。  | 
| [OH_Drawing_Array](_drawing.md#oh_drawing_array) \* [OH_Drawing_TextLineGetGlyphRuns](_drawing.md#oh_drawing_textlinegetglyphruns) (OH_Drawing_TextLine \*line) | 获取文本行对象中的文本渲染单元数组。  | 
| void [OH_Drawing_DestroyRuns](_drawing.md#oh_drawing_destroyruns) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*runs) | 释放文本渲染单元数组的内存。  | 
| OH_Drawing_Run \* [OH_Drawing_GetRunByIndex](_drawing.md#oh_drawing_getrunbyindex) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*runs, size_t index) | 获取文本渲染单元数组指定索引处的文本渲染单元对象。  | 
| void [OH_Drawing_TextLinePaint](_drawing.md#oh_drawing_textlinepaint) (OH_Drawing_TextLine \*line, [OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*canvas, double x, double y) | 在画布上以坐标点 (x, y) 为左上角位置绘制文本行。  | 
| OH_Drawing_TextLine \* [OH_Drawing_TextLineCreateTruncatedLine](_drawing.md#oh_drawing_textlinecreatetruncatedline) (OH_Drawing_TextLine \*line, double width, int mode, const char \*ellipsis) | 创建一个截断的文本行对象。  | 
| double [OH_Drawing_TextLineGetTypographicBounds](_drawing.md#oh_drawing_textlinegettypographicbounds) (OH_Drawing_TextLine \*line, double \*ascent, double \*descent, double \*leading) | 获取文本行对象的排版边界。文本行排版边界与排版字体、排版字号有关，与字符本身无关。 例如字符串为" a b "，'a'字符前面有1个空格，'b'字符后面有1个空格，排版边界就包括行首和末尾空格的边界。例如字符串为"j"或"E"，排版边界相同，即与字符本身无关。  | 
| [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \* [OH_Drawing_TextLineGetImageBounds](_drawing.md#oh_drawing_textlinegetimagebounds) (OH_Drawing_TextLine \*line) | 获取文本行对象的图像边界。文本行图像边界与排版字体、排版字号、字符本身都有关，相当于视觉边界。 例如字符串为" a b "，'a'字符前面有1个空格，'b'字符后面有1个空格,用户在界面上只能看到"a b"，图像边界即为不包括带行首和末尾空格的边界。 例如字符串为"j"或"E"，视觉边界不同，即与字符本身有关，"j"字符串的视觉边界宽度小于"E"字符串的视觉边界宽度，"j"字符串的视觉边界高度大于"E"字符串的视觉边界高度。  | 
| double [OH_Drawing_TextLineGetTrailingSpaceWidth](_drawing.md#oh_drawing_textlinegettrailingspacewidth) (OH_Drawing_TextLine \*line) | 获取文本行对象尾部空白字符的宽度。  | 
| int32_t [OH_Drawing_TextLineGetStringIndexForPosition](_drawing.md#oh_drawing_textlinegetstringindexforposition) (OH_Drawing_TextLine \*line, [OH_Drawing_Point](_drawing.md#oh_drawing_point) \*point) | 获取文本行对象中指定位置处的字符索引。  | 
| double [OH_Drawing_TextLineGetOffsetForStringIndex](_drawing.md#oh_drawing_textlinegetoffsetforstringindex) (OH_Drawing_TextLine \*line, int32_t index) | 获取文本行对象中指定字符串索引处的偏移量。  | 
| void [OH_Drawing_TextLineEnumerateCaretOffsets](_drawing.md#oh_drawing_textlineenumeratecaretoffsets) (OH_Drawing_TextLine \*line, [Drawing_CaretOffsetsCallback](_drawing.md#drawing_caretoffsetscallback) callback) | 枚举文本行对象中每个字符的偏移量和索引值，传递给用户自定义的回调函数，用户可以使用偏移量和索引值进行其他操作。  | 
| double [OH_Drawing_TextLineGetAlignmentOffset](_drawing.md#oh_drawing_textlinegetalignmentoffset) (OH_Drawing_TextLine \*line, double alignmentFactor, double alignmentWidth) | 获取文本行对象根据对齐因子和对齐宽度计算对齐后所需的偏移量。  | 
