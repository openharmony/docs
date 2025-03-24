# inputmethod_text_config_capi.h


## Overview

Provides methods for creating, destroying, reading, and writing the text box configuration information objects.

**Library**: libohinputmethod.so

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Since**: 12

**Related module**: [InputMethod](_input_method.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| [InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) | Text box configuration.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \* [OH_TextConfig_Create](_input_method.md#oh_textconfig_create) () | Creates an [InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) instance.| 
| void [OH_TextConfig_Destroy](_input_method.md#oh_textconfig_destroy) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config) | Destroys an [InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) instance.| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_SetInputType](_input_method.md#oh_textconfig_setinputtype) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, [InputMethod_TextInputType](_input_method.md#inputmethod_textinputtype) inputType) | Sets the text box type for [InputMethod_TextConfig](_input_method.md#inputmethod_textconfig).| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_SetEnterKeyType](_input_method.md#oh_textconfig_setenterkeytype) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, [InputMethod_EnterKeyType](_input_method.md#inputmethod_enterkeytype) enterKeyType) | Sets the Enter function type for [InputMethod_TextConfig](_input_method.md#inputmethod_textconfig).| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_SetPreviewTextSupport](_input_method.md#oh_textconfig_setpreviewtextsupport) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, bool supported) | Sets the text preview feature for [InputMethod_TextConfig](_input_method.md#inputmethod_textconfig).| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_SetSelection](_input_method.md#oh_textconfig_setselection) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, int32_t start, int32_t end) | Sets the selected text area for [InputMethod_TextConfig](_input_method.md#inputmethod_textconfig).| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_SetWindowId](_input_method.md#oh_textconfig_setwindowid) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, int32_t windowId) | Sets the ID of the window to which [InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) belongs.| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_GetInputType](_input_method.md#oh_textconfig_getinputtype) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, [InputMethod_TextInputType](_input_method.md#inputmethod_textinputtype) \*inputType) | Obtains the text box type of [InputMethod_TextConfig](_input_method.md#inputmethod_textconfig).| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_GetEnterKeyType](_input_method.md#oh_textconfig_getenterkeytype) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, [InputMethod_EnterKeyType](_input_method.md#inputmethod_enterkeytype) \*enterKeyType) | Obtains the Enter function type of [InputMethod_TextConfig](_input_method.md#inputmethod_textconfig).| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_IsPreviewTextSupported](_input_method.md#oh_textconfig_ispreviewtextsupported) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, bool \*supported) | Obtains the text preview settings of [InputMethod_TextConfig](_input_method.md#inputmethod_textconfig).| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_GetCursorInfo](_input_method.md#oh_textconfig_getcursorinfo) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, [InputMethod_CursorInfo](_input_method.md#inputmethod_cursorinfo) \*\*cursorInfo) | Obtains the cursor information of [InputMethod_TextConfig](_input_method.md#inputmethod_textconfig).| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_GetTextAvoidInfo](_input_method.md#oh_textconfig_gettextavoidinfo) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, [InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo) \*\*avoidInfo) | Obtains the avoidance information of [InputMethod_TextConfig](_input_method.md#inputmethod_textconfig).| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_GetSelection](_input_method.md#oh_textconfig_getselection) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, int32_t \*start, int32_t \*end) | Obtains the selected text area of [InputMethod_TextConfig](_input_method.md#inputmethod_textconfig).| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextConfig_GetWindowId](_input_method.md#oh_textconfig_getwindowid) ([InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) \*config, int32_t \*windowId) | Obtains the ID of the window to which [InputMethod_TextConfig](_input_method.md#inputmethod_textconfig) belongs.| 
