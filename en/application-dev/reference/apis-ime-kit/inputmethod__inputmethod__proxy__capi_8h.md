# inputmethod_inputmethod_proxy_capi.h


## Overview

Provides methods for using the input method, allowing requests and notifications to be sent to the input method application.

**Library**: libohinputmethod.so

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Since**: 12

**Related module**: [InputMethod](_input_method.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| [InputMethod_InputMethodProxy](_input_method.md#inputmethod_inputmethodproxy) | Input method proxy object.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_InputMethodProxy_ShowKeyboard](_input_method.md#oh_inputmethodproxy_showkeyboard) ([InputMethod_InputMethodProxy](_input_method.md#inputmethod_inputmethodproxy) \*inputMethodProxy) | Displays the keyboard.| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_InputMethodProxy_HideKeyboard](_input_method.md#oh_inputmethodproxy_hidekeyboard) ([InputMethod_InputMethodProxy](_input_method.md#inputmethod_inputmethodproxy) \*inputMethodProxy) | Hides the keyboard.| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_InputMethodProxy_NotifySelectionChange](_input_method.md#oh_inputmethodproxy_notifyselectionchange) ([InputMethod_InputMethodProxy](_input_method.md#inputmethod_inputmethodproxy) \*inputMethodProxy, char16_t text[], size_t length, int start, int end) | Notifies the change of the text selection area in the text box.| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_InputMethodProxy_NotifyConfigurationChange](_input_method.md#oh_inputmethodproxy_notifyconfigurationchange) ([InputMethod_InputMethodProxy](_input_method.md#inputmethod_inputmethodproxy) \*inputMethodProxy, [InputMethod_EnterKeyType](_input_method.md#inputmethod_enterkeytype) enterKey, [InputMethod_TextInputType](_input_method.md#inputmethod_textinputtype) textType) | Notifies the change of the text box configuration.| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_InputMethodProxy_NotifyCursorUpdate](_input_method.md#oh_inputmethodproxy_notifycursorupdate) ([InputMethod_InputMethodProxy](_input_method.md#inputmethod_inputmethodproxy) \*inputMethodProxy, [InputMethod_CursorInfo](_input_method.md#inputmethod_cursorinfo) \*cursorInfo) | Notifies the cursor position change.| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_InputMethodProxy_SendPrivateCommand](_input_method.md#oh_inputmethodproxy_sendprivatecommand) ([InputMethod_InputMethodProxy](_input_method.md#inputmethod_inputmethodproxy) \*inputMethodProxy, [InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \*privateCommand[], size_t size) | Sends a private data command.| 
