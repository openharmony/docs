# drawing_font_mgr.h


## 概述

文件中定义了与字体管理相关的功能函数，用于加载和匹配系统中可用的字体。

**引用文件**：&lt;native_drawing/drawing_font_mgr.h&gt;

**库：** libnative_drawing.so

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_FontMgr](_drawing.md#oh_drawing_fontmgr) \* [OH_Drawing_FontMgrCreate](_drawing.md#oh_drawing_fontmgrcreate) (void) | 创建字体管理对象，只支持管理系统字体。 | 
| void [OH_Drawing_FontMgrDestroy](_drawing.md#oh_drawing_fontmgrdestroy) ([OH_Drawing_FontMgr](_drawing.md#oh_drawing_fontmgr) \*) | 释放字体管理对象占用的内存。 | 
| int [OH_Drawing_FontMgrGetFamilyCount](_drawing.md#oh_drawing_fontmgrgetfamilycount) ([OH_Drawing_FontMgr](_drawing.md#oh_drawing_fontmgr) \*) | 获取字体家族的数量。 | 
| char \* [OH_Drawing_FontMgrGetFamilyName](_drawing.md#oh_drawing_fontmgrgetfamilyname) ([OH_Drawing_FontMgr](_drawing.md#oh_drawing_fontmgr) \*, int index) | 由索引值获取字体家族名称。 | 
| void [OH_Drawing_FontMgrDestroyFamilyName](_drawing.md#oh_drawing_fontmgrdestroyfamilyname) (char \*familyName) | 释放指定字体家族名称占用的内存。 | 
| [OH_Drawing_FontStyleSet](_drawing.md#oh_drawing_fontstyleset) \* [OH_Drawing_FontMgrCreateFontStyleSet](_drawing.md#oh_drawing_fontmgrcreatefontstyleset) ([OH_Drawing_FontMgr](_drawing.md#oh_drawing_fontmgr) \*, int index) | 由字体管理对象构造字体样式集对象。 | 
| void [OH_Drawing_FontMgrDestroyFontStyleSet](_drawing.md#oh_drawing_fontmgrdestroyfontstyleset) ([OH_Drawing_FontStyleSet](_drawing.md#oh_drawing_fontstyleset) \*) | 释放字体样式集对象占用的内存。 | 
| [OH_Drawing_FontStyleSet](_drawing.md#oh_drawing_fontstyleset) \* [OH_Drawing_FontMgrMatchFamily](_drawing.md#oh_drawing_fontmgrmatchfamily) ([OH_Drawing_FontMgr](_drawing.md#oh_drawing_fontmgr) \*, const char \*familyName) | 由指定的字体家族名称，获取字体样式集对象。 | 
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \* [OH_Drawing_FontMgrMatchFamilyStyle](_drawing.md#oh_drawing_fontmgrmatchfamilystyle) ([OH_Drawing_FontMgr](_drawing.md#oh_drawing_fontmgr) \*, const char \*familyName, [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md)) | 根据指定的字体样式信息和字体家族名称，获取字型对象。 | 
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \* [OH_Drawing_FontMgrMatchFamilyStyleCharacter](_drawing.md#oh_drawing_fontmgrmatchfamilystylecharacter) ([OH_Drawing_FontMgr](_drawing.md#oh_drawing_fontmgr) \*, const char \*familyName, [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md), const char \*bcp47[], int bcp47Count, int32_t character) | 为指定字符获取字型对象，仅在传入字体管理对象中无法找到传入UTF8字符值对应的字型对象时返回空指针。 | 
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \* [OH_Drawing_FontStyleSetCreateTypeface](_drawing.md#oh_drawing_fontstylesetcreatetypeface) ([OH_Drawing_FontStyleSet](_drawing.md#oh_drawing_fontstyleset) \*, int index) | 为指定索引获取字型对象。 | 
| [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) [OH_Drawing_FontStyleSetGetStyle](_drawing.md#oh_drawing_fontstylesetgetstyle) ([OH_Drawing_FontStyleSet](_drawing.md#oh_drawing_fontstyleset) \*, int32_t index, char \*\*styleName) | 获取字体样式。 | 
| void [OH_Drawing_FontStyleSetFreeStyleName](_drawing.md#oh_drawing_fontstylesetfreestylename) (char \*\*styleName) | 释放指定字体样式的内存。 | 
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \* [OH_Drawing_FontStyleSetMatchStyle](_drawing.md#oh_drawing_fontstylesetmatchstyle) ([OH_Drawing_FontStyleSet](_drawing.md#oh_drawing_fontstyleset) \*, [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) fontStyleStruct) | 获取最接近字体样式的字型对象。 | 
| int [OH_Drawing_FontStyleSetCount](_drawing.md#oh_drawing_fontstylesetcount) ([OH_Drawing_FontStyleSet](_drawing.md#oh_drawing_fontstyleset) \*) | 获取字体样式集中字体的个数。 | 
