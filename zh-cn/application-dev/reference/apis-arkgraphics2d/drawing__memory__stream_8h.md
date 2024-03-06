# drawing_memory_stream.h


## 概述

文件中定义了与内存流相关的功能函数。

**引用文件：**&lt;native_drawing/drawing_memory_stream.h&gt;

**库：** libnative_drawing.so

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_MemoryStream](_drawing.md#oh_drawing_memorystream) \* [OH_Drawing_MemoryStreamCreate](_drawing.md#oh_drawing_memorystreamcreate) (const void \*data, size_t length, bool copyData) | 创建一个内存流对象。 |
| void [OH_Drawing_MemoryStreamDestroy](_drawing.md#oh_drawing_memorystreamdestroy) ([OH_Drawing_MemoryStream](_drawing.md#oh_drawing_memorystream) \*) | 销毁内存流对象并回收该对象占有内存。 |
