# drawing_register_font.h


## 概述

定义绘制模块中字体管理器相关的函数。

**引用文件：**&lt;native_drawing/drawing_register_font.h&gt;

**库：** libnative_drawing.so

**起始版本：** 11

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [OH_Drawing_RegisterFont](_drawing.md#oh_drawing_registerfont) ([OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection)\*, const char\* fontFamily, const char\* familySrc) | 用于在字体管理器中注册自定义字体。 | 
| uint32_t [OH_Drawing_RegisterFontBuffer](_drawing.md#oh_drawing_registerfontbuffer) ([OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection)\*, const char\* fontFamily, uint8_t\* fontBuffer, size_t length) | 用于在字体管理器中注册字体缓冲区。 | 
