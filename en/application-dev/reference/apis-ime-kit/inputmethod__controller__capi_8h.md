# inputmethod_controller_capi.h


## Overview

Provides methods for binding and unbinding input methods.

**Library**: libohinputmethod.so

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Since**: 12

**Related module**: [InputMethod](_input_method.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_InputMethodController_Attach](_input_method.md#oh_inputmethodcontroller_attach) ([InputMethod_TextEditorProxy](_input_method.md#inputmethod_texteditorproxy) \*textEditorProxy, [InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions) \*options, [InputMethod_InputMethodProxy](_input_method.md#inputmethod_inputmethodproxy) \*\*inputMethodProxy) | Binds an application to the input method service.| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_InputMethodController_Detach](_input_method.md#oh_inputmethodcontroller_detach) ([InputMethod_InputMethodProxy](_input_method.md#inputmethod_inputmethodproxy) \*inputMethodProxy) | Unbinds an application from the input method service.| 
