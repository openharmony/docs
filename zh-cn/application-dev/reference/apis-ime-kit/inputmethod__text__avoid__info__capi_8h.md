# inputmethod_text_avoid_info_capi.h


## 概述

提供输入框避让信息对象的创建、销毁与读写方法。

**库：** libohinputmethod.so

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**起始版本：** 12

**相关模块：**[InputMethod](_input_method.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo) | 输入框避让信息。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo) \* [OH_TextAvoidInfo_Create](_input_method.md#oh_textavoidinfo_create) (double positionY, double height) | 创建一个新的[InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo)实例。 | 
| void [OH_TextAvoidInfo_Destroy](_input_method.md#oh_textavoidinfo_destroy) ([InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo) \*info) | 销毁一个[InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo)实例。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextAvoidInfo_SetPositionY](_input_method.md#oh_textavoidinfo_setpositiony) ([InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo) \*info, double positionY) | 设置[InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo)中的Y坐标值。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextAvoidInfo_SetHeight](_input_method.md#oh_textavoidinfo_setheight) ([InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo) \*info, double height) | 设置[InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo)中的高度值。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextAvoidInfo_GetPositionY](_input_method.md#oh_textavoidinfo_getpositiony) ([InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo) \*info, double \*positionY) | 从[InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo)获取Y坐标值。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextAvoidInfo_GetHeight](_input_method.md#oh_textavoidinfo_getheight) ([InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo) \*info, double \*height) | 从[InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo)获取高度值。 | 
