# inputmethod_types_capi.h


## 概述

提供了输入法相关的类型定义。

**库：** libohinputmethod.so

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**起始版本：** 12

**相关模块：**[InputMethod](_input_method.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [InputMethod_KeyboardStatus](_input_method.md#inputmethod_keyboardstatus) | 键盘状态。 | 
| [InputMethod_EnterKeyType](_input_method.md#inputmethod_enterkeytype) | 回车键功能类型。 | 
| [InputMethod_Direction](_input_method.md#inputmethod_direction) | 移动方向。 | 
| [InputMethod_ExtendAction](_input_method.md#inputmethod_extendaction) | 编辑框中文本的扩展编辑操作类型。 | 
| [InputMethod_TextInputType](_input_method.md#inputmethod_textinputtype) | 文本输入类型。 | 
| [InputMethod_CommandValueType](_input_method.md#inputmethod_commandvaluetype) | 私有数据类型。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) | 输入法错误码。 | 
| [InputMethod_RequestKeyboardReason](_input_method.md#inputmethod_requestkeyboardreason) | 请求键盘拉起原因。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [InputMethod_KeyboardStatus](_input_method.md#inputmethod_keyboardstatus-1) {<br/>IME_KEYBOARD_STATUS_NONE = 0,<br/>IME_KEYBOARD_STATUS_HIDE = 1,<br/>IME_KEYBOARD_STATUS_SHOW = 2<br/>} | 键盘状态。 | 
| [InputMethod_EnterKeyType](_input_method.md#inputmethod_enterkeytype-1) {<br/>IME_ENTER_KEY_UNSPECIFIED = 0,<br/>IME_ENTER_KEY_NONE = 1,<br/>IME_ENTER_KEY_GO = 2,<br/>IME_ENTER_KEY_SEARCH = 3,<br/>IME_ENTER_KEY_SEND = 4,<br/>IME_ENTER_KEY_NEXT = 5,<br/>IME_ENTER_KEY_DONE = 6,<br/>IME_ENTER_KEY_PREVIOUS = 7,<br/>IME_ENTER_KEY_NEWLINE = 8<br/>} | 回车键功能类型。 | 
| [InputMethod_Direction](_input_method.md#inputmethod_direction-1) {<br/>IME_DIRECTION_NONE = 0,<br/>IME_DIRECTION_UP = 1,<br/>IME_DIRECTION_DOWN = 2,<br/>IME_DIRECTION_LEFT = 3,<br/>IME_DIRECTION_RIGHT = 4<br/>} | 移动方向。 | 
| [InputMethod_ExtendAction](_input_method.md#inputmethod_extendaction-1) {<br/>IME_EXTEND_ACTION_SELECT_ALL = 0,<br/>IME_EXTEND_ACTION_CUT = 3,<br/>IME_EXTEND_ACTION_COPY = 4,<br/>IME_EXTEND_ACTION_PASTE = 5<br/>} | 编辑框中文本的扩展编辑操作类型。 | 
| [InputMethod_TextInputType](_input_method.md#inputmethod_textinputtype-1) {<br/>IME_TEXT_INPUT_TYPE_NONE = -1,<br/>IME_TEXT_INPUT_TYPE_TEXT = 0,<br/>IME_TEXT_INPUT_TYPE_MULTILINE = 1,<br/>IME_TEXT_INPUT_TYPE_NUMBER = 2,<br/>IME_TEXT_INPUT_TYPE_PHONE = 3,<br/>IME_TEXT_INPUT_TYPE_DATETIME = 4,<br/>IME_TEXT_INPUT_TYPE_EMAIL_ADDRESS = 5,<br/>IME_TEXT_INPUT_TYPE_URL = 6,<br/>IME_TEXT_INPUT_TYPE_VISIBLE_PASSWORD = 7,<br/>IME_TEXT_INPUT_TYPE_NUMBER_PASSWORD = 8,<br/>IME_TEXT_INPUT_TYPE_SCREEN_LOCK_PASSWORD = 9,<br/>IME_TEXT_INPUT_TYPE_USER_NAME = 10,<br/>IME_TEXT_INPUT_TYPE_NEW_PASSWORD = 11,<br/>IME_TEXT_INPUT_TYPE_NUMBER_DECIMAL = 12,<br/>IME_TEXT_INPUT_TYPE_ONE_TIME_CODE = 13<br/>} | 文本输入类型。 | 
| [InputMethod_CommandValueType](_input_method.md#inputmethod_commandvaluetype-1) {<br/>IME_COMMAND_VALUE_TYPE_NONE = 0,<br/>IME_COMMAND_VALUE_TYPE_STRING = 1,<br/>IME_COMMAND_VALUE_TYPE_BOOL = 2,<br/>IME_COMMAND_VALUE_TYPE_INT32 = 3<br/>} | 私有数据类型。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode-1) {<br/>IME_ERR_OK = 0,<br/>IME_ERR_UNDEFINED = 1,<br/>IME_ERR_PARAMCHECK = 401,<br/>IME_ERR_PACKAGEMANAGER = 12800001,<br/>IME_ERR_IMENGINE = 12800002,<br/>IME_ERR_IMCLIENT = 12800003,<br/>IME_ERR_CONFIG_PERSIST = 12800005,<br/>IME_ERR_CONTROLLER = 12800006,<br/>IME_ERR_SETTINGS = 12800007, IME_ERR_IMMS = 12800008,<br/>IME_ERR_DETACHED = 12800009,<br/>IME_ERR_NULL_POINTER = 12802000,<br/>IME_ERR_QUERY_FAILED = 12802001<br/>} | 输入法错误码。 | 
| [InputMethod_RequestKeyboardReason](_input_method.md#inputmethod_requestkeyboardreason-1) {<br/>IME_REQUEST_REASON_NONE = 0,<br/>IME_REQUEST_REASON_MOUSE = 1,<br/>IME_REQUEST_REASON_TOUCH = 2,<br/>IME_REQUEST_REASON_OTHER = 20<br/>} | 请求键盘输入原因。 | 

