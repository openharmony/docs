# inputmethod_inputmethod_proxy_capi.h


## 概述

提供使用输入法的方法，可以向输入法应用发送请求和通知。

**库：** libohinputmethod.so

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**起始版本：** 12

**相关模块：**[InputMethod](_input_method.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [InputMethod_InputMethodProxy](_input_method.md#inputmethod_inputmethodproxy) | 输入法代理对象。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_InputMethodProxy_ShowKeyboard](_input_method.md#oh_inputmethodproxy_showkeyboard) ([InputMethod_InputMethodProxy](_input_method.md#inputmethod_inputmethodproxy) \*inputMethodProxy) | 显示键盘。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_InputMethodProxy_ShowTextInput](_input_method.md#oh_inputmethodproxy_showtextinput) ([InputMethod_InputMethodProxy](_input_method.md#inputmethod_inputmethodproxy) \*inputMethodProxy, [InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions) \*options) | 显示文本输入。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_InputMethodProxy_HideKeyboard](_input_method.md#oh_inputmethodproxy_hidekeyboard) ([InputMethod_InputMethodProxy](_input_method.md#inputmethod_inputmethodproxy) \*inputMethodProxy) | 隐藏键盘。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_InputMethodProxy_NotifySelectionChange](_input_method.md#oh_inputmethodproxy_notifyselectionchange) ([InputMethod_InputMethodProxy](_input_method.md#inputmethod_inputmethodproxy) \*inputMethodProxy, char16_t text[], size_t length, int start, int end) | 通知文本框选区变化。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_InputMethodProxy_NotifyConfigurationChange](_input_method.md#oh_inputmethodproxy_notifyconfigurationchange) ([InputMethod_InputMethodProxy](_input_method.md#inputmethod_inputmethodproxy) \*inputMethodProxy, [InputMethod_EnterKeyType](_input_method.md#inputmethod_enterkeytype) enterKey, [InputMethod_TextInputType](_input_method.md#inputmethod_textinputtype) textType) | 通知输入框配置变化。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_InputMethodProxy_NotifyCursorUpdate](_input_method.md#oh_inputmethodproxy_notifycursorupdate) ([InputMethod_InputMethodProxy](_input_method.md#inputmethod_inputmethodproxy) \*inputMethodProxy, [InputMethod_CursorInfo](_input_method.md#inputmethod_cursorinfo) \*cursorInfo) | 通知光标位置变化。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_InputMethodProxy_SendPrivateCommand](_input_method.md#oh_inputmethodproxy_sendprivatecommand) ([InputMethod_InputMethodProxy](_input_method.md#inputmethod_inputmethodproxy) \*inputMethodProxy, [InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \*privateCommand[], size_t size) | 发送私有数据命令。 | 
