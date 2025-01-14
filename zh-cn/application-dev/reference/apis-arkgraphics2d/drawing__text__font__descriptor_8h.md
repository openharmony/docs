# drawing_text_font_descriptor.h


## 概述

定义了字体信息的相关接口，比如获取字体信息，查找指定字体等。

**引用文件：**<native_drawing/drawing_text_font_descriptor.h>

**库：** libnative_drawing.so

**起始版本：** 14

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef enum [OH_Drawing_SystemFontType](_drawing.md#oh_drawing_systemfonttype) [OH_Drawing_SystemFontType](_drawing.md#oh_drawing_systemfonttype) | 字体类型的枚举。  |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_SystemFontType](_drawing.md#oh_drawing_systemfonttype-1) { ALL = 1 &lt;&lt; 0, GENERIC = 1 &lt;&lt; 1, STYLISH = 1 &lt;&lt; 2, INSTALLED = 1 &lt;&lt; 3 } | 字体类型的枚举。  |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \* [OH_Drawing_GetFontDescriptorByFullName](_drawing.md#oh_drawing_getfontdescriptorbyfullname) (const [OH_Drawing_String](_o_h___drawing___string.md) \*, [OH_Drawing_SystemFontType](_drawing.md#oh_drawing_systemfonttype)) | 根据字体名称和字体类型获取指定的字体描述符，支持系统字体、风格字体和用户已安装字体。 字体描述符是描述字体特征的一种数据结构，它包含了定义字体外观和属性的详细信息。  |
| [OH_Drawing_Array](_drawing.md#oh_drawing_array) \* [OH_Drawing_GetSystemFontFullNamesByType](_drawing.md#oh_drawing_getsystemfontfullnamesbytype) ([OH_Drawing_SystemFontType](_drawing.md#oh_drawing_systemfonttype)) | 根据字体类型获取对应字体的字体名称数组。  |
| const [OH_Drawing_String](_o_h___drawing___string.md) \* [OH_Drawing_GetSystemFontFullNameByIndex](_drawing.md#oh_drawing_getsystemfontfullnamebyindex) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*, size_t) | 在字体名称数组中通过索引获取对应位置的字体名称。  |
| void [OH_Drawing_DestroySystemFontFullNames](_drawing.md#oh_drawing_destroysystemfontfullnames) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*) | 释放通过字体类型获取的对应字体的字体名称数组占用的内存。  |
