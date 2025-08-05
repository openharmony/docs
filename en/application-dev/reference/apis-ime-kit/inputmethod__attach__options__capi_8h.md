# inputmethod_attach_options_capi.h


## Overview

Provides methods for creating, destroying, reading, and writing the option object bound to the input method.

**Library**: libohinputmethod.so

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Since**: 12

**Related module**: [InputMethod](_input_method.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| [InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions) | Options for binding the input method.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions) \* [OH_AttachOptions_Create](_input_method.md#oh_attachoptions_create) (bool showKeyboard) | Creates an [InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions) instance.| 
| [InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions) \* [OH_AttachOptions_CreateWithRequestKeyboardReason](_input_method.md#oh_attachoptions_createwithrequestkeyboardreason) (bool showKeyboard, [InputMethod_RequestKeyboardReason](_input_method.md#inputmethod_requestkeyboardreason) \*requestKeyboardReason) | Creates an [InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions) instance.| 
| void [OH_AttachOptions_Destroy](_input_method.md#oh_attachoptions_destroy) ([InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions) \*options) | Destroys an [InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions) instance.| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_AttachOptions_IsShowKeyboard](_input_method.md#oh_attachoptions_isshowkeyboard) ([InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions) \*options, bool \*showKeyboard) | Obtains the configured value that indicates whether to display the keyboard from [InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions).| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_AttachOptions_GetRequestKeyboardReason](_input_method.md#oh_attachoptions_getrequestkeyboardreason) ([InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions) \*options, int \*requestKeyboardReason) | Obtains the reason why the input method keyboard is displayed, from [InputMethod_AttachOptions](_input_method.md#inputmethod_attachoptions).|  
