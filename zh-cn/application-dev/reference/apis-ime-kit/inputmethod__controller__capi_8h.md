# inputmethod_controller_capi.h


## 概述

提供绑定、解绑输入法的方法。

**库：** libohinputmethod.so

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**起始版本：** 12

**相关模块：**[InputMethod](_input_method.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_InputMethodController_Attach](_input_method.md#oh_inputmethodcontroller_attach) ([InputMethod_TextEditorProxy](_input_method.md#inputmethod_texteditorproxy) \*textEditorProxy, [InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions) \*options, [InputMethod_InputMethodProxy](_input_method.md#inputmethod_inputmethodproxy) \*\*inputMethodProxy) | 将应用绑定到输入法服务。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_InputMethodController_Detach](_input_method.md#oh_inputmethodcontroller_detach) ([InputMethod_InputMethodProxy](_input_method.md#inputmethod_inputmethodproxy) \*inputMethodProxy) | 将应用从输入法服务解绑。 | 
