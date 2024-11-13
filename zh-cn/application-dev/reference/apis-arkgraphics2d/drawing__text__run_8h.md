# drawing_text_run.h


## 概述

提供字体渲染单元的相关接口，比如绘制功能、获取排版边界功能等。 

**引用文件：**<native_drawing/drawing_text_run.h>

**库：** libnative_drawing.so

**起始版本：** 14

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_Array](_drawing.md#oh_drawing_array) \* [OH_Drawing_GetRunStringIndices](_drawing.md#oh_drawing_getrunstringindices) (OH_Drawing_Run \*run, int64_t start, int64_t length) | 获取渲染单元指定范围内字形的字符索引，该索引是相对于整个段落的偏移。  |
| uint64_t [OH_Drawing_GetRunStringIndicesByIndex](_drawing.md#oh_drawing_getrunstringindicesbyindex) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*stringIndices, size_t index) | 获取字符索引数组中指定下标的字符索引值。  |
| void [OH_Drawing_DestroyRunStringIndices](_drawing.md#oh_drawing_destroyrunstringindices) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*stringIndices) | 释放字形的字符索引数组对象指针。  |
| void [OH_Drawing_GetRunStringRange](_drawing.md#oh_drawing_getrunstringrange) (OH_Drawing_Run \*run, uint64_t \*location, uint64_t \*length) | 获取渲染单元生成字形的字符范围。  |
| float [OH_Drawing_GetRunTypographicBounds](_drawing.md#oh_drawing_getruntypographicbounds) (OH_Drawing_Run \*run, float \*ascent, float \*descent, float \*leading) | 获取渲染单元的排版边界。文本排版边界与字符本身无关，与排版字号和字体有关。  |
| void [OH_Drawing_RunPaint](_drawing.md#oh_drawing_runpaint) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*canvas, OH_Drawing_Run \*run, double x, double y) | 在画布上绘制渲染单元包含的文本。  |
| [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \* [OH_Drawing_GetRunImageBounds](_drawing.md#oh_drawing_getrunimagebounds) (OH_Drawing_Run \*run) | 获取渲染单元的图像边界，文本图像边界与字符本身有关，相当于视觉边界。  |
| void [OH_Drawing_DestroyRunImageBounds](_drawing.md#oh_drawing_destroyrunimagebounds) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect) | 释放渲染单元图像边界对象指针。  |
| [OH_Drawing_Array](_drawing.md#oh_drawing_array) \* [OH_Drawing_GetRunGlyphs](_drawing.md#oh_drawing_getrunglyphs) (OH_Drawing_Run \*run, int64_t start, int64_t length) | 获取渲染单元指定范围内的字形数组。  |
| uint16_t [OH_Drawing_GetRunGlyphsByIndex](_drawing.md#oh_drawing_getrunglyphsbyindex) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*glyphs, size_t index) | 根据索引获取渲染单元单个字形。  |
| void [OH_Drawing_DestroyRunGlyphs](_drawing.md#oh_drawing_destroyrunglyphs) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*glyphs) | 释放渲染单元字形数组对象指针。  |
| [OH_Drawing_Array](_drawing.md#oh_drawing_array) \* [OH_Drawing_GetRunPositions](_drawing.md#oh_drawing_getrunpositions) (OH_Drawing_Run \*run, int64_t start, int64_t length) | 获取渲染单元指定范围内字形的位置。  |
| [OH_Drawing_Point](_drawing.md#oh_drawing_point) \* [OH_Drawing_GetRunPositionsByIndex](_drawing.md#oh_drawing_getrunpositionsbyindex) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*positions, size_t index) | 根据索引获取渲染单元中单个字形位置。  |
| void [OH_Drawing_DestroyRunPositions](_drawing.md#oh_drawing_destroyrunpositions) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*positions) | 释放渲染单元字形位置数组对象指针。  |
| uint32_t [OH_Drawing_GetRunGlyphCount](_drawing.md#oh_drawing_getrunglyphcount) (OH_Drawing_Run \*run) | 获取渲染单元字形数量。  |
