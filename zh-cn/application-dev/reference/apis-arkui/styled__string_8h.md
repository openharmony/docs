# styled_string.h


## 概述

提供ArkUI在Native侧的属性字符串能力。

**库：** libace_ndk.z.so

**引用文件：** <arkui/styled_string.h>

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [ArkUI_StyledString](_ark_u_i___native_module.md#arkui_styledstring) [ArkUI_StyledString](_ark_u_i___native_module.md#arkui_styledstring) | 定义文本组件支持的格式化字符串数据对象。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_StyledString](_ark_u_i___native_module.md#arkui_styledstring) \* [OH_ArkUI_StyledString_Create](_ark_u_i___native_module.md#oh_arkui_styledstring_create) (OH_Drawing_TypographyStyle \*style, OH_Drawing_FontCollection \*collection) | 创建指向ArkUI_StyledString对象的指针。  | 
| void [OH_ArkUI_StyledString_Destroy](_ark_u_i___native_module.md#oh_arkui_styledstring_destroy) ([ArkUI_StyledString](_ark_u_i___native_module.md#arkui_styledstring) \*handle) | 释放被ArkUI_StyledString对象占据的内存。  | 
| void [OH_ArkUI_StyledString_PushTextStyle](_ark_u_i___native_module.md#oh_arkui_styledstring_pushtextstyle) ([ArkUI_StyledString](_ark_u_i___native_module.md#arkui_styledstring) \*handle, OH_Drawing_TextStyle \*style) | 将新的排版风格设置到当前格式化字符串样式栈顶。  | 
| void [OH_ArkUI_StyledString_AddText](_ark_u_i___native_module.md#oh_arkui_styledstring_addtext) ([ArkUI_StyledString](_ark_u_i___native_module.md#arkui_styledstring) \*handle, const char \*content) | 基于当前格式化字符串样式设置对应的文本内容。  | 
| void [OH_ArkUI_StyledString_PopTextStyle](_ark_u_i___native_module.md#oh_arkui_styledstring_poptextstyle) ([ArkUI_StyledString](_ark_u_i___native_module.md#arkui_styledstring) \*handle) | 将当前格式化字符串对象中栈顶样式出栈。  | 
| OH_Drawing_Typography \* [OH_ArkUI_StyledString_CreateTypography](_ark_u_i___native_module.md#oh_arkui_styledstring_createtypography) ([ArkUI_StyledString](_ark_u_i___native_module.md#arkui_styledstring) \*handle) | 基于格式字符串对象创建指向OH_Drawing_Typography对象的指针，用于提前进行文本测算排版。  | 
| void [OH_ArkUI_StyledString_AddPlaceholder](_ark_u_i___native_module.md#oh_arkui_styledstring_addplaceholder) ([ArkUI_StyledString](_ark_u_i___native_module.md#arkui_styledstring) \*handle, OH_Drawing_PlaceholderSpan \*placeholder) | 设置占位符。  | 
| [ArkUI_StyledString_Descriptor](_ark_u_i___native_module.md#arkui_styledstring_descriptor) \* [OH_ArkUI_StyledString_Descriptor_Create](_ark_u_i___native_module.md#oh_arkui_styledstring_descriptor_create) (void) | 创建属性字符串数据对象。  | 
| void [OH_ArkUI_StyledString_Descriptor_Destroy](_ark_u_i___native_module.md#oh_arkui_styledstring_descriptor_destroy) ([ArkUI_StyledString_Descriptor](_ark_u_i___native_module.md#arkui_styledstring_descriptor) \*descriptor) | 释放被ArkUI_StyledString_Descriptor对象占据的内存。  | 
| int32_t [OH_ArkUI_UnmarshallStyledStringDescriptor](_ark_u_i___native_module.md#oh_arkui_unmarshallstyledstringdescriptor) (uint8_t \*buffer, size_t bufferSize, [ArkUI_StyledString_Descriptor](_ark_u_i___native_module.md#arkui_styledstring_descriptor) \*descriptor) | 将包含属性字符串信息的字节数组反序列化为属性字符串。  | 
| int32_t [OH_ArkUI_MarshallStyledStringDescriptor](_ark_u_i___native_module.md#oh_arkui_marshallstyledstringdescriptor) (uint8_t \*buffer, size_t bufferSize, [ArkUI_StyledString_Descriptor](_ark_u_i___native_module.md#arkui_styledstring_descriptor) \*descriptor, size_t \*resultSize) | 将属性字符串信息序列化为字节数组。  | 
| const char \* [OH_ArkUI_ConvertToHtml](_ark_u_i___native_module.md#oh_arkui_converttohtml) ([ArkUI_StyledString_Descriptor](_ark_u_i___native_module.md#arkui_styledstring_descriptor) \*descriptor) | 将属性字符串信息转化成html。  | 
