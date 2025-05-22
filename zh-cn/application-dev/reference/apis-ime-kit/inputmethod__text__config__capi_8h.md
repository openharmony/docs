# inputmethod_text_config_capi.h


## 概述

提供输入框配置信息对象的创建、销毁与读写方法。

**库：** libohinputmethod.so

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**起始版本：** 12

**相关模块：**[InputMethod](_input_method.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) | 输入框配置。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \* [OH_TextConfig_Create](_input_method.md#oh_textconfig_create) () | 创建一个新的[InputMethod_TextConfig](_input_method.md#inputmethod_textconfig)实例。 | 
| void [OH_TextConfig_Destroy](_input_method.md#oh_textconfig_destroy) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config) | 销毁一个[InputMethod_TextConfig](_input_method.md#inputmethod_textconfig)实例。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_SetInputType](_input_method.md#oh_textconfig_setinputtype) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, [InputMethod_TextInputType](_input_method.md#inputmethod_textinputtype) inputType) | 设置[InputMethod_TextConfig](_input_method.md#inputmethod_textconfig)实例的输入框类型。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_SetEnterKeyType](_input_method.md#oh_textconfig_setenterkeytype) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, [InputMethod_EnterKeyType](_input_method.md#inputmethod_enterkeytype) enterKeyType) | 设置[InputMethod_TextConfig](_input_method.md#inputmethod_textconfig)实例的回车键功能类型。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_SetPreviewTextSupport](_input_method.md#oh_textconfig_setpreviewtextsupport) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, bool supported) | 将预上屏支持情况设置到[InputMethod_TextConfig](_input_method.md#inputmethod_textconfig)实例。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_SetSelection](_input_method.md#oh_textconfig_setselection) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, int32_t start, int32_t end) | 设置[InputMethod_TextConfig](_input_method.md#inputmethod_textconfig)实例的选中文本范围。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_SetWindowId](_input_method.md#oh_textconfig_setwindowid) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, int32_t windowId) | 设置[InputMethod_TextConfig](_input_method.md#inputmethod_textconfig)实例的所属窗口的窗口id。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_GetInputType](_input_method.md#oh_textconfig_getinputtype) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, [InputMethod_TextInputType](_input_method.md#inputmethod_textinputtype) \*inputType) | 获取[InputMethod_TextConfig](_input_method.md#inputmethod_textconfig)实例的输入框类型。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_GetEnterKeyType](_input_method.md#oh_textconfig_getenterkeytype) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, [InputMethod_EnterKeyType](_input_method.md#inputmethod_enterkeytype) \*enterKeyType) | 获取[InputMethod_TextConfig](_input_method.md#inputmethod_textconfig)实例的回车键功能类型。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_IsPreviewTextSupported](_input_method.md#oh_textconfig_ispreviewtextsupported) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, bool \*supported) | 获取[InputMethod_TextConfig](_input_method.md#inputmethod_textconfig)实例的是否支持预上屏。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_GetCursorInfo](_input_method.md#oh_textconfig_getcursorinfo) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, [InputMethod_CursorInfo](_input_method.md#inputmethod_cursorinfo) \*\*cursorInfo) | 获取[InputMethod_TextConfig](_input_method.md#inputmethod_textconfig)实例的光标信息。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_GetTextAvoidInfo](_input_method.md#oh_textconfig_gettextavoidinfo) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, [InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo) \*\*avoidInfo) | 获取[InputMethod_TextConfig](_input_method.md#inputmethod_textconfig)实例的避让信息。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_GetSelection](_input_method.md#oh_textconfig_getselection) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, int32_t \*start, int32_t \*end) | 获取[InputMethod_TextConfig](_input_method.md#inputmethod_textconfig)实例的选区范围信息。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_GetWindowId](_input_method.md#oh_textconfig_getwindowid) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, int32_t \*windowId) | 获取[InputMethod_TextConfig](_input_method.md#inputmethod_textconfig)实例所属窗口的窗口id。 | 
