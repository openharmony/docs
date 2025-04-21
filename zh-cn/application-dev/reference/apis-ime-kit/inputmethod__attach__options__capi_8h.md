# inputmethod_attach_options_capi.h


## 概述

提供输入法绑定选项对象的创建、销毁与读写方法。

**库：** libohinputmethod.so

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**起始版本：** 12

**相关模块：**[InputMethod](_input_method.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions) | 输入法绑定选项。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions) \* [OH_AttachOptions_Create](_input_method.md#oh_attachoptions_create) (bool showKeyboard) | 创建一个新的[InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions)实例。 | 
| [InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions) \* [OH_AttachOptions_CreateWithRequestKeyboardReason](_input_method.md#oh_attachoptions_createwithrequestkeyboardreason) (bool showKeyboard, [InputMethod_RequestKeyboardReason](_input_method.md#inputmethod_requestkeyboardreason) \*requestKeyboardReason) | 创建一个新的[InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions)实例。 | 
| void [OH_AttachOptions_Destroy](_input_method.md#oh_attachoptions_destroy) ([InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions) \*options) | 销毁一个[InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions)实例. | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_AttachOptions_IsShowKeyboard](_input_method.md#oh_attachoptions_isshowkeyboard) ([InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions) \*options, bool \*showKeyboard) | 从[InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions)中获取是否显示键盘的值。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_AttachOptions_GetRequestKeyboardReason](_input_method.md#oh_attachoptions_getrequestkeyboardreason) ([InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions) \*options, int \*requestKeyboardReason) | 从[InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions)中获取输入法键盘拉起原因。 |  
