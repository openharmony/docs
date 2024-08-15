# drawing_font_collection.h


## 概述

定义绘制模块中与字体集合相关的函数。

**引用文件：**&lt;native_drawing/drawing_font_collection.h&gt;

**库：** libnative_drawing.so

**起始版本：** 8

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection) \* [OH_Drawing_CreateFontCollection](_drawing.md#oh_drawing_createfontcollection) (void) | 创建字体集对象[OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection)。 | 
| void [OH_Drawing_DestroyFontCollection](_drawing.md#oh_drawing_destroyfontcollection) ([OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection) \*) | 释放被字体集对象占据的内存。 | 
| void [OH_Drawing_DisableFontCollectionFallback](_drawing.md#oh_drawing_disablefontcollectionfallback) ([OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection) \*fontCollection) | 禁用备用字体。 | 
| void [OH_Drawing_DisableFontCollectionSystemFont](_drawing.md#oh_drawing_disablefontcollectionsystemfont) ([OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection) \*fontCollection) | 禁用系统字体。 | 
| [OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection) \* [OH_Drawing_CreateSharedFontCollection](_drawing.md#oh_drawing_createsharedfontcollection) (void) | 创建可共享的字体集对象[OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection)。 | 
| void [OH_Drawing_ClearFontCaches](_drawing.md#oh_drawing_clearfontcaches) ([OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection) \*) | 清理字体排版缓存（字体排版缓存本身设有内存上限和清理机制，所占内存有限，如无内存要求，不建议清理）。 |