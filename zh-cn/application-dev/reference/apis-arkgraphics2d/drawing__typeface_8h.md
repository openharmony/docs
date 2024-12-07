# drawing_typeface.h


## 概述

文件中定义了与字形相关的功能函数。 不同的平台有自己的默认字形，也可以从ttf文件解析出三方指定字形，如宋体、黑体字形等。

**引用文件：**&lt;native_drawing/drawing_typeface.h&gt;

**库：** libnative_drawing.so

**起始版本：** 11

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateDefault](_drawing.md#oh_drawing_typefacecreatedefault) (void) | 用于创建一个默认的字形对象。 |
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateFromFile](_drawing.md#oh_drawing_typefacecreatefromfile) (const char \*path, int index) | 通过文件创建一个字形对象。 |
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateFromFileWithArguments](_drawing.md#oh_drawing_typefacecreatefromfilewitharguments) (const char \*path, const [OH_Drawing_FontArguments](_drawing.md#oh_drawing_fontarguments) \*fontArguments) | 从指定文件路径创建带有字型参数的字体对象。 如果字体对象不支持字型参数中描述的可变维度，此函数将会创建默认字型参数的字体对象。 在这种情况下，此函数将提供与[OH_Drawing_TypefaceCreateFromFile](_drawing.md#oh_drawing_typefacecreatefromfile)相同的功能。 | 
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateFromCurrent](_drawing.md#oh_drawing_typefacecreatefromcurrent) (const [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \*current, const [OH_Drawing_FontArguments](_drawing.md#oh_drawing_fontarguments) \*fontArguments) | 通过已存在的字体对象创建带有字型参数的字体对象。 | 
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateFromStream](_drawing.md#oh_drawing_typefacecreatefromstream) ([OH_Drawing_MemoryStream](_drawing.md#oh_drawing_memorystream) \*, int32_t index) | 通过内存流创建一个字形对象。如果内存流是无效的字体文件，返回空指针。 内存流传入后，所有权转移，开发者不能再释放它。 |
| void [OH_Drawing_TypefaceDestroy](_drawing.md#oh_drawing_typefacedestroy) ([OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \*) | 用于销毁字形对象并回收该对象占有的内存。 |
| [OH_Drawing_FontArguments](_drawing.md#oh_drawing_fontarguments) \* [OH_Drawing_FontArgumentsCreate](_drawing.md#oh_drawing_fontargumentscreate) (void) | 用于创建一个字型参数对象。字型参数用于创建带有自定义属性的字体对象。 | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_FontArgumentsAddVariation](_drawing.md#oh_drawing_fontargumentsaddvariation) ([OH_Drawing_FontArguments](_drawing.md#oh_drawing_fontarguments) \*fontArguments, const char \*axis, float value) | 给字型参数对象添加可变维度。 | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_FontArgumentsDestroy](_drawing.md#oh_drawing_fontargumentsdestroy) ([OH_Drawing_FontArguments](_drawing.md#oh_drawing_fontarguments) \*fontArguments) | 用于销毁一个字型参数对象。 | 