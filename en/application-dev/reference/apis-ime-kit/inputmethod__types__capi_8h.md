# inputmethod_types_capi.h


## Overview

Defines the types related to the input method.

**Library**: libohinputmethod.so

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Since**: 12

**Related module**: [InputMethod](_input_method.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| [InputMethod_KeyboardStatus](_input_method.md#inputmethod_keyboardstatus) | Keyboard status.| 
| [InputMethod_EnterKeyType](_input_method.md#inputmethod_enterkeytype) | Enter function type.| 
| [InputMethod_Direction](_input_method.md#inputmethod_direction) | Moving direction.| 
| [InputMethod_ExtendAction](_input_method.md#inputmethod_extendaction) | Type of the extended edit action on the text box.| 
| [InputMethod_TextInputType](_input_method.md#inputmethod_textinputtype) | Text input type.| 
| [InputMethod_CommandValueType](_input_method.md#inputmethod_commandvaluetype) | Private data type.| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) | Error code of the input method.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [InputMethod_KeyboardStatus](_input_method.md#inputmethod_keyboardstatus) {<br>[IME_KEYBOARD_STATUS_NONE](_input_method.md) = 0,<br>[IME_KEYBOARD_STATUS_HIDE](_input_method.md) = 1,<br>[IME_KEYBOARD_STATUS_SHOW](_input_method.md) = 2<br>} | Keyboard status.| 
| [InputMethod_EnterKeyType](_input_method.md#inputmethod_enterkeytype) {<br>[IME_ENTER_KEY_UNSPECIFIED](_input_method.md) = 0,<br>[IME_ENTER_KEY_NONE](_input_method.md) = 1,<br>[IME_ENTER_KEY_GO](_input_method.md) = 2,<br>[IME_ENTER_KEY_SEARCH](_input_method.md) = 3,<br>[IME_ENTER_KEY_SEND](_input_method.md) = 4,<br>[IME_ENTER_KEY_NEXT](_input_method.md) = 5,<br>[IME_ENTER_KEY_DONE](_input_method.md) = 6,<br>[IME_ENTER_KEY_PREVIOUS](_input_method.md) = 7,<br>[IME_ENTER_KEY_NEWLINE](_input_method.md) = 8<br>} | Enter function type.| 
| [InputMethod_Direction](_input_method.md#inputmethod_direction) {<br>[IME_DIRECTION_NONE](_input_method.md) = 0,<br>[IME_DIRECTION_UP](_input_method.md) = 1,<br>[IME_DIRECTION_DOWN](_input_method.md) = 2,<br>[IME_DIRECTION_LEFT](_input_method.md) = 3,<br>[IME_DIRECTION_RIGHT](_input_method.md) = 4<br>} | Moving direction.| 
| [InputMethod_ExtendAction](_input_method.md#inputmethod_extendaction) {<br>[IME_EXTEND_ACTION_SELECT_ALL](_input_method.md) = 0,<br>[IME_EXTEND_ACTION_CUT](_input_method.md) = 3,<br>[IME_EXTEND_ACTION_COPY](_input_method.md) = 4,<br>[IME_EXTEND_ACTION_PASTE](_input_method.md) = 5<br>} | Type of the extended edit action on the text box.| 
| [InputMethod_TextInputType](_input_method.md#inputmethod_textinputtype) {<br>[IME_TEXT_INPUT_TYPE_NONE](_input_method.md) = -1,<br>[IME_TEXT_INPUT_TYPE_TEXT](_input_method.md) = 0,<br>[IME_TEXT_INPUT_TYPE_MULTILINE](_input_method.md) = 1,<br>[IME_TEXT_INPUT_TYPE_NUMBER](_input_method.md) = 2,<br>[IME_TEXT_INPUT_TYPE_PHONE](_input_method.md) = 3,<br>[IME_TEXT_INPUT_TYPE_DATETIME](_input_method.md) = 4,<br>[IME_TEXT_INPUT_TYPE_EMAIL_ADDRESS](_input_method.md) = 5,<br>[IME_TEXT_INPUT_TYPE_URL](_input_method.md) = 6,<br>[IME_TEXT_INPUT_TYPE_VISIBLE_PASSWORD](_input_method.md) = 7,<br>[IME_TEXT_INPUT_TYPE_NUMBER_PASSWORD](_input_method.md) = 8,<br>[IME_TEXT_INPUT_TYPE_SCREEN_LOCK_PASSWORD](_input_method.md) = 9,<br>[IME_TEXT_INPUT_TYPE_USER_NAME](_input_method.md) = 10,<br>[IME_TEXT_INPUT_TYPE_NEW_PASSWORD](_input_method.md) = 11,<br>[IME_TEXT_INPUT_TYPE_NUMBER_DECIMAL](_input_method.md) = 12<br>} | Text input type.| 
| [InputMethod_CommandValueType](_input_method.md#inputmethod_commandvaluetype) {<br>[IME_COMMAND_VALUE_TYPE_NONE](_input_method.md) = 0,<br>[IME_COMMAND_VALUE_TYPE_STRING](_input_method.md) = 1,<br>[IME_COMMAND_VALUE_TYPE_BOOL](_input_method.md) = 2,<br>[IME_COMMAND_VALUE_TYPE_INT32](_input_method.md) = 3<br>} | Private data type.| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) {<br>[IME_ERR_OK](_input_method.md) = 0,<br>[IME_ERR_UNDEFINED](_input_method.md) = 1,<br>[IME_ERR_PARAMCHECK](_input_method.md) = 401,<br>[IME_ERR_PACKAGEMANAGER](_input_method.md) = 12800001,<br>[IME_ERR_IMENGINE](_input_method.md) = 12800002,<br>[IME_ERR_IMCLIENT](_input_method.md) = 12800003,<br>[IME_ERR_CONFIG_PERSIST](_input_method.md) = 12800005,<br>[IME_ERR_CONTROLLER](_input_method.md) = 12800006,<br>[IME_ERR_SETTINGS](_input_method.md) = 12800007, [IME_ERR_IMMS](_input_method.md) = 12800008,<br>[IME_ERR_DETACHED](_input_method.md) = 12800009,<br>[IME_ERR_NULL_POINTER](_input_method.md) = 12802000,<br>[IME_ERR_QUERY_FAILED](_input_method.md) = 12802001<br>} | Error code of the input method.| 
