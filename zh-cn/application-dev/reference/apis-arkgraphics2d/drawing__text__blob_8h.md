# drawing_text_blob.h


## 概述

文件中定义了与文字相关的功能函数。

**引用文件：**&lt;native_drawing/drawing_text_blob.h&gt;

**库：** libnative_drawing.so

**起始版本：** 11

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| struct  [OH_Drawing_RunBuffer](_o_h___drawing___run_buffer.md) | 结构体用于描述一块内存，描述文字和位置信息。 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef struct [OH_Drawing_RunBuffer](_o_h___drawing___run_buffer.md)  [OH_Drawing_RunBuffer](_drawing.md#oh_drawing_runbuffer) | 结构体用于描述一块内存，描述文字和位置信息。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_TextBlobBuilder](_drawing.md#oh_drawing_textblobbuilder) \* [OH_Drawing_TextBlobBuilderCreate](_drawing.md#oh_drawing_textblobbuildercreate) (void) | 用于创建一个文本构造器对象。 |
| [OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob) \* [OH_Drawing_TextBlobCreateFromText](_drawing.md#oh_drawing_textblobcreatefromtext) (const void \*text, size_t byteLength, const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, [OH_Drawing_TextEncoding](_drawing.md#oh_drawing_textencoding)) | 使用文本创建一个文本对象。 |
| [OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob) \* [OH_Drawing_TextBlobCreateFromPosText](_drawing.md#oh_drawing_textblobcreatefrompostext) (const void \*text, size_t byteLength, [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*, const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, [OH_Drawing_TextEncoding](_drawing.md#oh_drawing_textencoding)) | 使用文本创建文本对象，文本对象中每个字符的坐标由OH_Drawing_Point2D数组中对应的坐标信息决定。 |
| [OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob) \* [OH_Drawing_TextBlobCreateFromString](_drawing.md#oh_drawing_textblobcreatefromstring) (const char \*str, const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, [OH_Drawing_TextEncoding](_drawing.md#oh_drawing_textencoding)) | 使用字符串创建文本对象。 |
| void [OH_Drawing_TextBlobGetBounds](_drawing.md#oh_drawing_textblobgetbounds) ([OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob) \*, [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | 获取文本对象的边界范围。 |
| uint32_t [OH_Drawing_TextBlobUniqueID](_drawing.md#oh_drawing_textblobuniqueid) (const [OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob) \*) | 获取文本的标识符，该标识符是唯一的非零值。 | 
| const [OH_Drawing_RunBuffer](_o_h___drawing___run_buffer.md) \* [OH_Drawing_TextBlobBuilderAllocRunPos](_drawing.md#oh_drawing_textblobbuilderallocrunpos) ([OH_Drawing_TextBlobBuilder](_drawing.md#oh_drawing_textblobbuilder) \*, const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, int32_t count, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | 申请一块内存，用于存储文字和位置信息。返回的指针无需调用者管理， 当调用[OH_Drawing_TextBlobBuilderMake](_drawing.md#oh_drawing_textblobbuildermake)后禁止使用。 |
| [OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob) \* [OH_Drawing_TextBlobBuilderMake](_drawing.md#oh_drawing_textblobbuildermake) ([OH_Drawing_TextBlobBuilder](_drawing.md#oh_drawing_textblobbuilder) \*) | 用于从文本构造器中创建文本对象。 |
| void [OH_Drawing_TextBlobDestroy](_drawing.md#oh_drawing_textblobdestroy) ([OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob) \*) | 用于销毁文本对象并回收该对象占有的内存。 |
| void [OH_Drawing_TextBlobBuilderDestroy](_drawing.md#oh_drawing_textblobbuilderdestroy) ([OH_Drawing_TextBlobBuilder](_drawing.md#oh_drawing_textblobbuilder) \*) | 用于销毁文本构造器对象并回收该对象占有的内存。 |
