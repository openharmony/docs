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


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [InputMethod_KeyboardStatus](_input_method.md#inputmethod_keyboardstatus) {<br/>[IME_KEYBOARD_STATUS_NONE](_input_method.md) = 0,<br/>[IME_KEYBOARD_STATUS_HIDE](_input_method.md) = 1,<br/>[IME_KEYBOARD_STATUS_SHOW](_input_method.md) = 2<br/>} | 键盘状态。 | 
| [InputMethod_EnterKeyType](_input_method.md#inputmethod_enterkeytype) {<br/>[IME_ENTER_KEY_UNSPECIFIED](_input_method.md) = 0,<br/>[IME_ENTER_KEY_NONE](_input_method.md) = 1,<br/>[IME_ENTER_KEY_GO](_input_method.md) = 2,<br/>[IME_ENTER_KEY_SEARCH](_input_method.md) = 3,<br/>[IME_ENTER_KEY_SEND](_input_method.md) = 4,<br/>[IME_ENTER_KEY_NEXT](_input_method.md) = 5,<br/>[IME_ENTER_KEY_DONE](_input_method.md) = 6,<br/>[IME_ENTER_KEY_PREVIOUS](_input_method.md) = 7,<br/>[IME_ENTER_KEY_NEWLINE](_input_method.md) = 8<br/>} | 回车键功能类型。 | 
| [InputMethod_Direction](_input_method.md#inputmethod_direction) {<br/>[IME_DIRECTION_NONE](_input_method.md) = 0,<br/>[IME_DIRECTION_UP](_input_method.md) = 1,<br/>[IME_DIRECTION_DOWN](_input_method.md) = 2,<br/>[IME_DIRECTION_LEFT](_input_method.md) = 3,<br/>[IME_DIRECTION_RIGHT](_input_method.md) = 4<br/>} | 移动方向。 | 
| [InputMethod_ExtendAction](_input_method.md#inputmethod_extendaction) {<br/>[IME_EXTEND_ACTION_SELECT_ALL](_input_method.md) = 0,<br/>[IME_EXTEND_ACTION_CUT](_input_method.md) = 3,<br/>[IME_EXTEND_ACTION_COPY](_input_method.md) = 4,<br/>[IME_EXTEND_ACTION_PASTE](_input_method.md) = 5<br/>} | 编辑框中文本的扩展编辑操作类型。 | 
| [InputMethod_TextInputType](_input_method.md#inputmethod_textinputtype) {<br/>[IME_TEXT_INPUT_TYPE_NONE](_input_method.md) = -1,<br/>[IME_TEXT_INPUT_TYPE_TEXT](_input_method.md) = 0,<br/>[IME_TEXT_INPUT_TYPE_MULTILINE](_input_method.md) = 1,<br/>[IME_TEXT_INPUT_TYPE_NUMBER](_input_method.md) = 2,<br/>[IME_TEXT_INPUT_TYPE_PHONE](_input_method.md) = 3,<br/>[IME_TEXT_INPUT_TYPE_DATETIME](_input_method.md) = 4,<br/>[IME_TEXT_INPUT_TYPE_EMAIL_ADDRESS](_input_method.md) = 5,<br/>[IME_TEXT_INPUT_TYPE_URL](_input_method.md) = 6,<br/>[IME_TEXT_INPUT_TYPE_VISIBLE_PASSWORD](_input_method.md) = 7,<br/>[IME_TEXT_INPUT_TYPE_NUMBER_PASSWORD](_input_method.md) = 8,<br/>[IME_TEXT_INPUT_TYPE_SCREEN_LOCK_PASSWORD](_input_method.md) = 9,<br/>[IME_TEXT_INPUT_TYPE_USER_NAME](_input_method.md) = 10,<br/>[IME_TEXT_INPUT_TYPE_NEW_PASSWORD](_input_method.md) = 11,<br/>[IME_TEXT_INPUT_TYPE_NUMBER_DECIMAL](_input_method.md) = 12<br/>} | 文本输入类型。 | 
| [InputMethod_CommandValueType](_input_method.md#inputmethod_commandvaluetype) {<br/>[IME_COMMAND_VALUE_TYPE_NONE](_input_method.md) = 0,<br/>[IME_COMMAND_VALUE_TYPE_STRING](_input_method.md) = 1,<br/>[IME_COMMAND_VALUE_TYPE_BOOL](_input_method.md) = 2,<br/>[IME_COMMAND_VALUE_TYPE_INT32](_input_method.md) = 3<br/>} | 私有数据类型。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) {<br/>[IME_ERR_OK](_input_method.md) = 0,<br/>[IME_ERR_UNDEFINED](_input_method.md) = 1,<br/>[IME_ERR_PARAMCHECK](_input_method.md) = 401,<br/>[IME_ERR_PACKAGEMANAGER](_input_method.md) = 12800001,<br/>[IME_ERR_IMENGINE](_input_method.md) = 12800002,<br/>[IME_ERR_IMCLIENT](_input_method.md) = 12800003,<br/>[IME_ERR_CONFIG_PERSIST](_input_method.md) = 12800005,<br/>[IME_ERR_CONTROLLER](_input_method.md) = 12800006,<br/>[IME_ERR_SETTINGS](_input_method.md) = 12800007, [IME_ERR_IMMS](_input_method.md) = 12800008,<br/>[IME_ERR_DETACHED](_input_method.md) = 12800009,<br/>[IME_ERR_NULL_POINTER](_input_method.md) = 12802000,<br/>[IME_ERR_QUERY_FAILED](_input_method.md) = 12802001<br/>} | 输入法错误码。 | 
