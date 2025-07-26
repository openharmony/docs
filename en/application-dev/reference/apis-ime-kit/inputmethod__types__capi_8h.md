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
| [InputMethod_RequestKeyboardReason](_input_method.md#inputmethod_requestkeyboardreason) | Reason why the keyboard is displayed.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [InputMethod_KeyboardStatus](_input_method.md#inputmethod_keyboardstatus-1) {<br>IME_KEYBOARD_STATUS_NONE = 0,<br>IME_KEYBOARD_STATUS_HIDE = 1,<br>IME_KEYBOARD_STATUS_SHOW = 2<br>} | Keyboard status.| 
| [InputMethod_EnterKeyType](_input_method.md#inputmethod_enterkeytype-1) {<br>IME_ENTER_KEY_UNSPECIFIED = 0,<br>IME_ENTER_KEY_NONE = 1,<br>IME_ENTER_KEY_GO = 2,<br>IME_ENTER_KEY_SEARCH = 3,<br>IME_ENTER_KEY_SEND = 4,<br>IME_ENTER_KEY_NEXT = 5,<br>IME_ENTER_KEY_DONE = 6,<br>IME_ENTER_KEY_PREVIOUS = 7,<br>IME_ENTER_KEY_NEWLINE = 8<br>} | Enter function type.| 
| [InputMethod_Direction](_input_method.md#inputmethod_direction-1) {<br>IME_DIRECTION_NONE = 0,<br>IME_DIRECTION_UP = 1,<br>IME_DIRECTION_DOWN = 2,<br>IME_DIRECTION_LEFT = 3,<br>IME_DIRECTION_RIGHT = 4<br>} | Moving direction.| 
| [InputMethod_ExtendAction](_input_method.md#inputmethod_extendaction-1) {<br>IME_EXTEND_ACTION_SELECT_ALL = 0,<br>IME_EXTEND_ACTION_CUT = 3,<br>IME_EXTEND_ACTION_COPY = 4,<br>IME_EXTEND_ACTION_PASTE = 5<br>} | Type of the extended edit action on the text box.| 
| [InputMethod_TextInputType](_input_method.md#inputmethod_textinputtype-1) {<br>IME_TEXT_INPUT_TYPE_NONE = -1,<br>IME_TEXT_INPUT_TYPE_TEXT = 0,<br>IME_TEXT_INPUT_TYPE_MULTILINE = 1,<br>IME_TEXT_INPUT_TYPE_NUMBER = 2,<br>IME_TEXT_INPUT_TYPE_PHONE = 3,<br>IME_TEXT_INPUT_TYPE_DATETIME = 4,<br>IME_TEXT_INPUT_TYPE_EMAIL_ADDRESS = 5,<br>IME_TEXT_INPUT_TYPE_URL = 6,<br>IME_TEXT_INPUT_TYPE_VISIBLE_PASSWORD = 7,<br>IME_TEXT_INPUT_TYPE_NUMBER_PASSWORD = 8,<br>IME_TEXT_INPUT_TYPE_SCREEN_LOCK_PASSWORD = 9,<br>IME_TEXT_INPUT_TYPE_USER_NAME = 10,<br>IME_TEXT_INPUT_TYPE_NEW_PASSWORD = 11,<br>IME_TEXT_INPUT_TYPE_NUMBER_DECIMAL = 12,<br>IME_TEXT_INPUT_TYPE_ONE_TIME_CODE = 13<br>} | Text input type.| 
| [InputMethod_CommandValueType](_input_method.md#inputmethod_commandvaluetype-1) {<br>IME_COMMAND_VALUE_TYPE_NONE = 0,<br>IME_COMMAND_VALUE_TYPE_STRING = 1,<br>IME_COMMAND_VALUE_TYPE_BOOL = 2,<br>IME_COMMAND_VALUE_TYPE_INT32 = 3<br>} | Private data type.| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode-1) {<br>IME_ERR_OK = 0,<br>IME_ERR_UNDEFINED = 1,<br>IME_ERR_PARAMCHECK = 401,<br>IME_ERR_PACKAGEMANAGER = 12800001,<br>IME_ERR_IMENGINE = 12800002,<br>IME_ERR_IMCLIENT = 12800003,<br>IME_ERR_CONFIG_PERSIST = 12800005,<br>IME_ERR_CONTROLLER = 12800006,<br>IME_ERR_SETTINGS = 12800007, IME_ERR_IMMS = 12800008,<br>IME_ERR_DETACHED = 12800009,<br>IME_ERR_NULL_POINTER = 12802000,<br>IME_ERR_QUERY_FAILED = 12802001<br>} | Error code of the input method.| 
| [InputMethod_RequestKeyboardReason](_input_method.md#inputmethod_requestkeyboardreason-1) {<br>IME_REQUEST_REASON_NONE = 0,<br>IME_REQUEST_REASON_MOUSE = 1,<br>IME_REQUEST_REASON_TOUCH = 2,<br>IME_REQUEST_REASON_OTHER = 20<br>} | Reason for keyboard request.| 
