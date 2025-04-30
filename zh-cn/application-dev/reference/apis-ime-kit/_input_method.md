# InputMethod


## 概述

InputMethod模块提供方法来使用输入法和开发输入法。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [inputmethod_attach_options_capi.h](inputmethod__attach__options__capi_8h.md) | 提供输入法绑定选项对象的创建、销毁与读写方法。 | 
| [inputmethod_controller_capi.h](inputmethod__controller__capi_8h.md) | 提供绑定、解绑输入法的方法。 | 
| [inputmethod_cursor_info_capi.h](inputmethod__cursor__info__capi_8h.md) | 提供光标信息对象的创建、销毁与读写方法。 | 
| [inputmethod_inputmethod_proxy_capi.h](inputmethod__inputmethod__proxy__capi_8h.md) | 提供使用输入法的方法，可以向输入法应用发送请求和通知。 | 
| [inputmethod_private_command_capi.h](inputmethod__private__command__capi_8h.md) | 提供私有数据对象的创建、销毁与读写方法。 | 
| [inputmethod_text_avoid_info_capi.h](inputmethod__text__avoid__info__capi_8h.md) | 提供输入框避让信息对象的创建、销毁与读写方法。 | 
| [inputmethod_text_config_capi.h](inputmethod__text__config__capi_8h.md) | 提供输入框配置信息对象的创建、销毁与读写方法。 | 
| [inputmethod_text_editor_proxy_capi.h](inputmethod__text__editor__proxy__capi_8h.md) | 提供一套方法支持应用开发的自绘输入框获取来自输入法应用的通知和请求。 | 
| [inputmethod_types_capi.h](inputmethod__types__capi_8h.md) | 提供了输入法相关的类型定义。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [InputMethod_AttachOptions](#inputmethod_attachoptions) | 输入法绑定选项。 | 
| [InputMethod_CursorInfo](#inputmethod_cursorinfo) | 光标信息。 | 
| [InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) | 输入法代理对象。 | 
| [InputMethod_PrivateCommand](#inputmethod_privatecommand) | 私有数据。 | 
| [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) | 输入框避让信息。 | 
| [InputMethod_TextConfig](#inputmethod_textconfig) | 输入框配置。 | 
| [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) | 输入框代理。 | 
| typedef void(\* [OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, [InputMethod_TextConfig](#inputmethod_textconfig) \*config) | 输入法获取输入框配置时触发的函数。 | 
| typedef void(\* [OH_TextEditorProxy_InsertTextFunc](#oh_texteditorproxy_inserttextfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, const char16_t \*text, size_t length) | 输入法应用插入文本时触发的函数。 | 
| typedef void(\* [OH_TextEditorProxy_DeleteForwardFunc](#oh_texteditorproxy_deleteforwardfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, int32_t length) | 输入法删除光标右侧文本时触发的函数。 | 
| typedef void(\* [OH_TextEditorProxy_DeleteBackwardFunc](#oh_texteditorproxy_deletebackwardfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, int32_t length) | 输入法删除光标左侧文本时触发的函数。 | 
| typedef void(\* [OH_TextEditorProxy_SendKeyboardStatusFunc](#oh_texteditorproxy_sendkeyboardstatusfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, [InputMethod_KeyboardStatus](#inputmethod_keyboardstatus) keyboardStatus) | 输入法通知键盘状态时触发的函数。 | 
| typedef void(\* [OH_TextEditorProxy_SendEnterKeyFunc](#oh_texteditorproxy_sendenterkeyfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, [InputMethod_EnterKeyType](#inputmethod_enterkeytype) enterKeyType) | 输入法发送回车键时触发的函数。 | 
| typedef void(\* [OH_TextEditorProxy_MoveCursorFunc](#oh_texteditorproxy_movecursorfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, [InputMethod_Direction](#inputmethod_direction) direction) | 输入法移动光标时触发的函数。 | 
| typedef void(\* [OH_TextEditorProxy_HandleSetSelectionFunc](#oh_texteditorproxy_handlesetselectionfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, int32_t start, int32_t end) | 输入法请求选中文本时触发的函数。 | 
| typedef void(\* [OH_TextEditorProxy_HandleExtendActionFunc](#oh_texteditorproxy_handleextendactionfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, [InputMethod_ExtendAction](#inputmethod_extendaction) action) | 输入法发送扩展编辑操作时触发的函数。 | 
| typedef void(\* [OH_TextEditorProxy_GetLeftTextOfCursorFunc](#oh_texteditorproxy_getlefttextofcursorfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, int32_t number, char16_t text[], size_t \*length) | 输入法获取光标左侧文本时触发的函数。 | 
| typedef void(\* [OH_TextEditorProxy_GetRightTextOfCursorFunc](#oh_texteditorproxy_getrighttextofcursorfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, int32_t number, char16_t text[], size_t \*length) | 输入法获取光标右侧文本时触发的函数。 | 
| typedef int32_t(\* [OH_TextEditorProxy_GetTextIndexAtCursorFunc](#oh_texteditorproxy_gettextindexatcursorfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy) | 输入法获取光标所在输入框文本索引时触发的函数。 | 
| typedef int32_t(\* [OH_TextEditorProxy_ReceivePrivateCommandFunc](#oh_texteditorproxy_receiveprivatecommandfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, [InputMethod_PrivateCommand](#inputmethod_privatecommand) \*privateCommand[], size_t size) | 输入法应用发送私有数据命令时触发的函数。 | 
| typedef int32_t(\* [OH_TextEditorProxy_SetPreviewTextFunc](#oh_texteditorproxy_setpreviewtextfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, const char16_t text[], size_t length, int32_t start, int32_t end) | 输入法设置预上屏文本时触发的函数。 | 
| typedef void(\* [OH_TextEditorProxy_FinishTextPreviewFunc](#oh_texteditorproxy_finishtextpreviewfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy) | 输入法结束预上屏时触发的函数。 | 
| [InputMethod_KeyboardStatus](#inputmethod_keyboardstatus) | 键盘状态。 | 
| [InputMethod_EnterKeyType](#inputmethod_enterkeytype) | 回车键功能类型。 | 
| [InputMethod_Direction](#inputmethod_direction) | 移动方向。 | 
| [InputMethod_ExtendAction](#inputmethod_extendaction) | 编辑框中文本的扩展编辑操作类型。 | 
| [InputMethod_TextInputType](#inputmethod_textinputtype) | 文本输入类型。 | 
| [InputMethod_CommandValueType](#inputmethod_commandvaluetype) | 私有数据类型。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) | 输入法错误码。 | 
| [InputMethod_RequestKeyboardReason](#inputmethod_requestkeyboardreason) | 请求键盘输入原因。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [InputMethod_KeyboardStatus](#inputmethod_keyboardstatus) {<br/>IME_KEYBOARD_STATUS_NONE = 0,<br/>IME_KEYBOARD_STATUS_HIDE = 1,<br/>IME_KEYBOARD_STATUS_SHOW = 2<br/>} | 键盘状态。 | 
| [InputMethod_EnterKeyType](#inputmethod_enterkeytype) {<br/>IME_ENTER_KEY_UNSPECIFIED = 0,<br/>IME_ENTER_KEY_NONE = 1,<br/>IME_ENTER_KEY_GO = 2,<br/>IME_ENTER_KEY_SEARCH = 3,<br/>IME_ENTER_KEY_SEND = 4,<br/>IME_ENTER_KEY_NEXT = 5,<br/>IME_ENTER_KEY_DONE = 6,<br/>IME_ENTER_KEY_PREVIOUS = 7,<br/>IME_ENTER_KEY_NEWLINE = 8<br/>} | 回车键功能类型。 | 
| [InputMethod_Direction](#inputmethod_direction) {<br/>IME_DIRECTION_NONE = 0,<br/>IME_DIRECTION_UP = 1,<br/>IME_DIRECTION_DOWN = 2,<br/>IME_DIRECTION_LEFT = 3,<br/>IME_DIRECTION_RIGHT = 4<br/>} | 移动方向。 | 
| [InputMethod_ExtendAction](#inputmethod_extendaction) {<br/>IME_EXTEND_ACTION_SELECT_ALL = 0,<br/>IME_EXTEND_ACTION_CUT = 3,<br/>IME_EXTEND_ACTION_COPY = 4,<br/>IME_EXTEND_ACTION_PASTE = 5<br/>} | 编辑框中文本的扩展编辑操作类型。 | 
| [InputMethod_TextInputType](#inputmethod_textinputtype) {<br/>IME_TEXT_INPUT_TYPE_NONE = -1,<br/>IME_TEXT_INPUT_TYPE_TEXT = 0,<br/>IME_TEXT_INPUT_TYPE_MULTILINE = 1,<br/>IME_TEXT_INPUT_TYPE_NUMBER = 2,<br/>IME_TEXT_INPUT_TYPE_PHONE = 3,<br/>IME_TEXT_INPUT_TYPE_DATETIME = 4,<br/>IME_TEXT_INPUT_TYPE_EMAIL_ADDRESS = 5,<br/>IME_TEXT_INPUT_TYPE_URL = 6,<br/>IME_TEXT_INPUT_TYPE_VISIBLE_PASSWORD = 7,<br/>IME_TEXT_INPUT_TYPE_NUMBER_PASSWORD = 8,<br/>IME_TEXT_INPUT_TYPE_SCREEN_LOCK_PASSWORD = 9,<br/>IME_TEXT_INPUT_TYPE_USER_NAME = 10,<br/>IME_TEXT_INPUT_TYPE_NEW_PASSWORD = 11,<br/>IME_TEXT_INPUT_TYPE_NUMBER_DECIMAL = 12<br/>} | 文本输入类型。 | 
| [InputMethod_CommandValueType](#inputmethod_commandvaluetype) {<br/>IME_COMMAND_VALUE_TYPE_NONE = 0,<br/>IME_COMMAND_VALUE_TYPE_STRING = 1,<br/>IME_COMMAND_VALUE_TYPE_BOOL = 2,<br/>IME_COMMAND_VALUE_TYPE_INT32 = 3<br/>} | 私有数据类型。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) {<br/>IME_ERR_OK = 0, IME_ERR_UNDEFINED = 1,<br/>IME_ERR_PARAMCHECK = 401,<br/>IME_ERR_PACKAGEMANAGER = 12800001,<br/>IME_ERR_IMENGINE = 12800002,<br/>IME_ERR_IMCLIENT = 12800003,<br/>IME_ERR_CONFIG_PERSIST = 12800005,<br/>IME_ERR_CONTROLLER = 12800006,<br/>IME_ERR_SETTINGS = 12800007,<br/>IME_ERR_IMMS = 12800008,<br/>IME_ERR_DETACHED = 12800009,<br/>IME_ERR_NULL_POINTER = 12802000,<br/>IME_ERR_QUERY_FAILED = 12802001<br/>} | 输入法错误码。 | 
| [InputMethod_RequestKeyboardReason](#inputmethod_requestkeyboardreason) {<br/>IME_REQUEST_REASON_NONE = 0,<br/>IME_REQUEST_REASON_MOUSE = 1,<br/>IME_REQUEST_REASON_TOUCH = 2,<br/>IME_REQUEST_REASON_OTHER = 20<br/>} | 请求键盘输入原因。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [InputMethod_AttachOptions](#inputmethod_attachoptions) \* [OH_AttachOptions_Create](#oh_attachoptions_create) (bool showKeyboard) | 创建一个新的[InputMethod_AttachOptions](#inputmethod_attachoptions)实例。 | 
| [InputMethod_AttachOptions](#inputmethod_attachoptions) \* [OH_AttachOptions_CreateWithRequestKeyboardReason](#oh_attachoptions_createwithrequestkeyboardreason) (bool showKeyboard, [InputMethod_RequestKeyboardReason](#inputmethod_requestkeyboardreason) requestKeyboardReason) | 创建一个新的[InputMethod_AttachOptions](#inputmethod_attachoptions)实例。 | 
| void [OH_AttachOptions_Destroy](#oh_attachoptions_destroy) ([InputMethod_AttachOptions](#inputmethod_attachoptions) \*options) | 销毁一个[InputMethod_AttachOptions](#inputmethod_attachoptions)实例。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_AttachOptions_IsShowKeyboard](#oh_attachoptions_isshowkeyboard) ([InputMethod_AttachOptions](#inputmethod_attachoptions) \*options, bool \*showKeyboard) | 从[InputMethod_AttachOptions](#inputmethod_attachoptions)中获取是否显示键盘的值。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_AttachOptions_GetRequestKeyboardReason](#oh_attachoptions_getrequestkeyboardreason) ([InputMethod_AttachOptions](#inputmethod_attachoptions) \*options, int \*requestKeyboardReason) | 从[InputMethod_AttachOptions](#inputmethod_attachoptions)中获取是否显示键盘的值。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, [InputMethod_AttachOptions](#inputmethod_attachoptions) \*options, [InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) \*\*inputMethodProxy) | 将应用绑定到输入法服务。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_InputMethodController_Detach](#oh_inputmethodcontroller_detach) ([InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) \*inputMethodProxy) | 将应用从输入法服务解绑。 | 
| [InputMethod_CursorInfo](#inputmethod_cursorinfo) \* [OH_CursorInfo_Create](#oh_cursorinfo_create) (double left, double top, double width, double height) | 创建一个新的[InputMethod_CursorInfo](#inputmethod_cursorinfo)实例。 | 
| void [OH_CursorInfo_Destroy](#oh_cursorinfo_destroy) ([InputMethod_CursorInfo](#inputmethod_cursorinfo) \*cursorInfo) | 销毁一个[InputMethod_CursorInfo](#inputmethod_cursorinfo)实例。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_CursorInfo_SetRect](#oh_cursorinfo_setrect) ([InputMethod_CursorInfo](#inputmethod_cursorinfo) \*cursorInfo, double left, double top, double width, double height) | 设置光标信息内容。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_CursorInfo_GetRect](#oh_cursorinfo_getrect) ([InputMethod_CursorInfo](#inputmethod_cursorinfo) \*cursorInfo, double \*left, double \*top, double \*width, double \*height) | 获取光标信息内容。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_InputMethodProxy_ShowKeyboard](#oh_inputmethodproxy_showkeyboard) ([InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) \*inputMethodProxy) | 显示键盘。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_InputMethodProxy_ShowTextInput](#oh_inputmethodproxy_showtextinput) ([InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) \*inputMethodProxy, [InputMethod_AttachOptions](#inputmethod_attachoptions) \*options) | 显示文本输入。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_InputMethodProxy_HideKeyboard](#oh_inputmethodproxy_hidekeyboard) ([InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) \*inputMethodProxy) | 隐藏键盘。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_InputMethodProxy_NotifySelectionChange](#oh_inputmethodproxy_notifyselectionchange) ([InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) \*inputMethodProxy, char16_t text[], size_t length, int start, int end) | 通知文本框选区变化。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_InputMethodProxy_NotifyConfigurationChange](#oh_inputmethodproxy_notifyconfigurationchange) ([InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) \*inputMethodProxy, [InputMethod_EnterKeyType](#inputmethod_enterkeytype) enterKey, [InputMethod_TextInputType](#inputmethod_textinputtype) textType) | 通知输入框配置变化。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_InputMethodProxy_NotifyCursorUpdate](#oh_inputmethodproxy_notifycursorupdate) ([InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) \*inputMethodProxy, [InputMethod_CursorInfo](#inputmethod_cursorinfo) \*cursorInfo) | 通知光标位置变化。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_InputMethodProxy_SendPrivateCommand](#oh_inputmethodproxy_sendprivatecommand) ([InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) \*inputMethodProxy, [InputMethod_PrivateCommand](#inputmethod_privatecommand) \*privateCommand[], size_t size) | 发送私有数据命令。 | 
| [InputMethod_PrivateCommand](#inputmethod_privatecommand) \* [OH_PrivateCommand_Create](#oh_privatecommand_create) (char key[], size_t keyLength) | 创建一个新的[InputMethod_PrivateCommand](#inputmethod_privatecommand)实例。 | 
| void [OH_PrivateCommand_Destroy](#oh_privatecommand_destroy) ([InputMethod_PrivateCommand](#inputmethod_privatecommand) \*command) | 销毁一个[InputMethod_PrivateCommand](#inputmethod_privatecommand)实例。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_PrivateCommand_SetKey](#oh_privatecommand_setkey) ([InputMethod_PrivateCommand](#inputmethod_privatecommand) \*command, char key[], size_t keyLength) | 设置[InputMethod_PrivateCommand](#inputmethod_privatecommand)的key值。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_PrivateCommand_SetBoolValue](#oh_privatecommand_setboolvalue) ([InputMethod_PrivateCommand](#inputmethod_privatecommand) \*command, bool value) | 设置[InputMethod_PrivateCommand](#inputmethod_privatecommand)的布尔类型value值。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_PrivateCommand_SetIntValue](#oh_privatecommand_setintvalue) ([InputMethod_PrivateCommand](#inputmethod_privatecommand) \*command, int32_t value) | 设置[InputMethod_PrivateCommand](#inputmethod_privatecommand)的整数类型value值。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_PrivateCommand_SetStrValue](#oh_privatecommand_setstrvalue) ([InputMethod_PrivateCommand](#inputmethod_privatecommand) \*command, char value[], size_t valueLength) | 设置[InputMethod_PrivateCommand](#inputmethod_privatecommand)的字符串类型value值。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_PrivateCommand_GetKey](#oh_privatecommand_getkey) ([InputMethod_PrivateCommand](#inputmethod_privatecommand) \*command, const char \*\*key, size_t \*keyLength) | 从[InputMethod_PrivateCommand](#inputmethod_privatecommand)获取key值。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_PrivateCommand_GetValueType](#oh_privatecommand_getvaluetype) ([InputMethod_PrivateCommand](#inputmethod_privatecommand) \*command, [InputMethod_CommandValueType](#inputmethod_commandvaluetype) \*type) | 从[InputMethod_PrivateCommand](#inputmethod_privatecommand)获取value的数据类型。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_PrivateCommand_GetBoolValue](#oh_privatecommand_getboolvalue) ([InputMethod_PrivateCommand](#inputmethod_privatecommand) \*command, bool \*value) | 从[InputMethod_PrivateCommand](#inputmethod_privatecommand)获取布尔类型的value的值。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_PrivateCommand_GetIntValue](#oh_privatecommand_getintvalue) ([InputMethod_PrivateCommand](#inputmethod_privatecommand) \*command, int32_t \*value) | 从[InputMethod_PrivateCommand](#inputmethod_privatecommand)获取整数类型的value的值。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_PrivateCommand_GetStrValue](#oh_privatecommand_getstrvalue) ([InputMethod_PrivateCommand](#inputmethod_privatecommand) \*command, const char \*\*value, size_t \*valueLength) | 从[InputMethod_PrivateCommand](#inputmethod_privatecommand)获取字符串类型的value的值。 | 
| [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) \* [OH_TextAvoidInfo_Create](#oh_textavoidinfo_create) (double positionY, double height) | 创建一个新的[InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo)实例。 | 
| void [OH_TextAvoidInfo_Destroy](#oh_textavoidinfo_destroy) ([InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) \*info) | 销毁一个[InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo)实例。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextAvoidInfo_SetPositionY](#oh_textavoidinfo_setpositiony) ([InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) \*info, double positionY) | 设置[InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo)中的Y坐标值。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextAvoidInfo_SetHeight](#oh_textavoidinfo_setheight) ([InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) \*info, double height) | 设置[InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo)中的高度值。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextAvoidInfo_GetPositionY](#oh_textavoidinfo_getpositiony) ([InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) \*info, double \*positionY) | 从[InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo)获取Y坐标值。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextAvoidInfo_GetHeight](#oh_textavoidinfo_getheight) ([InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) \*info, double \*height) | 从[InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo)获取高度值。 | 
| [InputMethod_TextConfig](#inputmethod_textconfig) \* [OH_TextConfig_Create](#oh_textconfig_create) () | 创建一个新的[InputMethod_TextConfig](#inputmethod_textconfig)实例。 | 
| void [OH_TextConfig_Destroy](#oh_textconfig_destroy) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config) | 销毁一个[InputMethod_TextConfig](#inputmethod_textconfig)实例。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_SetInputType](#oh_textconfig_setinputtype) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, [InputMethod_TextInputType](#inputmethod_textinputtype) inputType) | 设置[InputMethod_TextConfig](#inputmethod_textconfig)实例的输入框类型。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_SetEnterKeyType](#oh_textconfig_setenterkeytype) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, [InputMethod_EnterKeyType](#inputmethod_enterkeytype) enterKeyType) | 设置[InputMethod_TextConfig](#inputmethod_textconfig)实例的回车键功能类型。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_SetPreviewTextSupport](#oh_textconfig_setpreviewtextsupport) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, bool supported) | 将预上屏支持情况设置到[InputMethod_TextConfig](#inputmethod_textconfig)实例。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_SetSelection](#oh_textconfig_setselection) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, int32_t start, int32_t end) | 设置[InputMethod_TextConfig](#inputmethod_textconfig)实例的选中文本范围。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_SetWindowId](#oh_textconfig_setwindowid) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, int32_t windowId) | 设置[InputMethod_TextConfig](#inputmethod_textconfig)实例的所属窗口的窗口id。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_GetInputType](#oh_textconfig_getinputtype) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, [InputMethod_TextInputType](#inputmethod_textinputtype) \*inputType) | 获取[InputMethod_TextConfig](#inputmethod_textconfig)实例的输入框类型。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_GetEnterKeyType](#oh_textconfig_getenterkeytype) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, [InputMethod_EnterKeyType](#inputmethod_enterkeytype) \*enterKeyType) | 获取[InputMethod_TextConfig](#inputmethod_textconfig)实例的回车键功能类型。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_IsPreviewTextSupported](#oh_textconfig_ispreviewtextsupported) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, bool \*supported) | 获取[InputMethod_TextConfig](#inputmethod_textconfig)实例的是否支持预上屏。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_GetCursorInfo](#oh_textconfig_getcursorinfo) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, [InputMethod_CursorInfo](#inputmethod_cursorinfo) \*\*cursorInfo) | 获取[InputMethod_TextConfig](#inputmethod_textconfig)实例的光标信息。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_GetTextAvoidInfo](#oh_textconfig_gettextavoidinfo) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) \*\*avoidInfo) | 获取[InputMethod_TextConfig](#inputmethod_textconfig)实例的避让信息。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_GetSelection](#oh_textconfig_getselection) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, int32_t \*start, int32_t \*end) | 获取[InputMethod_TextConfig](#inputmethod_textconfig)实例的选区范围信息。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_GetWindowId](#oh_textconfig_getwindowid) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, int32_t \*windowId) | 获取[InputMethod_TextConfig](#inputmethod_textconfig)实例所属窗口的窗口id。 | 
| [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \* [OH_TextEditorProxy_Create](#oh_texteditorproxy_create) () | 创建一个新的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例。 | 
| void [OH_TextEditorProxy_Destroy](#oh_texteditorproxy_destroy) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy) | 销毁一个[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetGetTextConfigFunc](#oh_texteditorproxy_setgettextconfigfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc) getTextConfigFunc) | 将函数[OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetInsertTextFunc](#oh_texteditorproxy_setinserttextfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_InsertTextFunc](#oh_texteditorproxy_inserttextfunc) insertTextFunc) | 将函数[OH_TextEditorProxy_InsertTextFunc](#oh_texteditorproxy_inserttextfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetDeleteForwardFunc](#oh_texteditorproxy_setdeleteforwardfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_DeleteForwardFunc](#oh_texteditorproxy_deleteforwardfunc) deleteForwardFunc) | 将函数[OH_TextEditorProxy_DeleteForwardFunc](#oh_texteditorproxy_deleteforwardfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetDeleteBackwardFunc](#oh_texteditorproxy_setdeletebackwardfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_DeleteBackwardFunc](#oh_texteditorproxy_deletebackwardfunc) deleteBackwardFunc) | 将函数[OH_TextEditorProxy_DeleteBackwardFunc](#oh_texteditorproxy_deletebackwardfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetSendKeyboardStatusFunc](#oh_texteditorproxy_setsendkeyboardstatusfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_SendKeyboardStatusFunc](#oh_texteditorproxy_sendkeyboardstatusfunc) sendKeyboardStatusFunc) | 将函数[OH_TextEditorProxy_SendKeyboardStatusFunc](#oh_texteditorproxy_sendkeyboardstatusfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetSendEnterKeyFunc](#oh_texteditorproxy_setsendenterkeyfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_SendEnterKeyFunc](#oh_texteditorproxy_sendenterkeyfunc) sendEnterKeyFunc) | 将函数[OH_TextEditorProxy_SetSendEnterKeyFunc](#oh_texteditorproxy_setsendenterkeyfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetMoveCursorFunc](#oh_texteditorproxy_setmovecursorfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_MoveCursorFunc](#oh_texteditorproxy_movecursorfunc) moveCursorFunc) | 将函数[OH_TextEditorProxy_SetMoveCursorFunc](#oh_texteditorproxy_setmovecursorfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetHandleSetSelectionFunc](#oh_texteditorproxy_sethandlesetselectionfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_HandleSetSelectionFunc](#oh_texteditorproxy_handlesetselectionfunc) handleSetSelectionFunc) | 将函数[OH_TextEditorProxy_HandleSetSelectionFunc](#oh_texteditorproxy_handlesetselectionfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetHandleExtendActionFunc](#oh_texteditorproxy_sethandleextendactionfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_HandleExtendActionFunc](#oh_texteditorproxy_handleextendactionfunc) handleExtendActionFunc) | 将函数[OH_TextEditorProxy_HandleExtendActionFunc](#oh_texteditorproxy_handleextendactionfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetGetLeftTextOfCursorFunc](#oh_texteditorproxy_setgetlefttextofcursorfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_GetLeftTextOfCursorFunc](#oh_texteditorproxy_getlefttextofcursorfunc) getLeftTextOfCursorFunc) | 将函数[OH_TextEditorProxy_GetLeftTextOfCursorFunc](#oh_texteditorproxy_getlefttextofcursorfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetGetRightTextOfCursorFunc](#oh_texteditorproxy_setgetrighttextofcursorfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_GetRightTextOfCursorFunc](#oh_texteditorproxy_getrighttextofcursorfunc) getRightTextOfCursorFunc) | 将函数[OH_TextEditorProxy_GetRightTextOfCursorFunc](#oh_texteditorproxy_getrighttextofcursorfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetGetTextIndexAtCursorFunc](#oh_texteditorproxy_setgettextindexatcursorfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_GetTextIndexAtCursorFunc](#oh_texteditorproxy_gettextindexatcursorfunc) getTextIndexAtCursorFunc) | 将函数[OH_TextEditorProxy_GetTextIndexAtCursorFunc](#oh_texteditorproxy_gettextindexatcursorfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetReceivePrivateCommandFunc](#oh_texteditorproxy_setreceiveprivatecommandfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_ReceivePrivateCommandFunc](#oh_texteditorproxy_receiveprivatecommandfunc) receivePrivateCommandFunc) | 将函数[OH_TextEditorProxy_ReceivePrivateCommandFunc](#oh_texteditorproxy_receiveprivatecommandfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetSetPreviewTextFunc](#oh_texteditorproxy_setsetpreviewtextfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_SetPreviewTextFunc](#oh_texteditorproxy_setpreviewtextfunc) setPreviewTextFunc) | 将函数[OH_TextEditorProxy_SetPreviewTextFunc](#oh_texteditorproxy_setpreviewtextfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetFinishTextPreviewFunc](#oh_texteditorproxy_setfinishtextpreviewfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_FinishTextPreviewFunc](#oh_texteditorproxy_finishtextpreviewfunc) finishTextPreviewFunc) | 将函数[OH_TextEditorProxy_FinishTextPreviewFunc](#oh_texteditorproxy_finishtextpreviewfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetGetTextConfigFunc](#oh_texteditorproxy_getgettextconfigfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc) \*getTextConfigFunc) | 从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc)函数。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetInsertTextFunc](#oh_texteditorproxy_getinserttextfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_InsertTextFunc](#oh_texteditorproxy_inserttextfunc) \*insertTextFunc) | 从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_InsertTextFunc](#oh_texteditorproxy_inserttextfunc)函数。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetDeleteForwardFunc](#oh_texteditorproxy_getdeleteforwardfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_DeleteForwardFunc](#oh_texteditorproxy_deleteforwardfunc) \*deleteForwardFunc) | 从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_DeleteForwardFunc](#oh_texteditorproxy_deleteforwardfunc)函数。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetDeleteBackwardFunc](#oh_texteditorproxy_getdeletebackwardfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_DeleteBackwardFunc](#oh_texteditorproxy_deletebackwardfunc) \*deleteBackwardFunc) | 从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_DeleteBackwardFunc](#oh_texteditorproxy_deletebackwardfunc)函数。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetSendKeyboardStatusFunc](#oh_texteditorproxy_getsendkeyboardstatusfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_SendKeyboardStatusFunc](#oh_texteditorproxy_sendkeyboardstatusfunc) \*sendKeyboardStatusFunc) | 从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_SendKeyboardStatusFunc](#oh_texteditorproxy_sendkeyboardstatusfunc)函数。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetSendEnterKeyFunc](#oh_texteditorproxy_getsendenterkeyfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_SendEnterKeyFunc](#oh_texteditorproxy_sendenterkeyfunc) \*sendEnterKeyFunc) | 从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_SendEnterKeyFunc](#oh_texteditorproxy_sendenterkeyfunc)函数。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetMoveCursorFunc](#oh_texteditorproxy_getmovecursorfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_MoveCursorFunc](#oh_texteditorproxy_movecursorfunc) \*moveCursorFunc) | 从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_MoveCursorFunc](#oh_texteditorproxy_movecursorfunc)函数。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetHandleSetSelectionFunc](#oh_texteditorproxy_gethandlesetselectionfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_HandleSetSelectionFunc](#oh_texteditorproxy_handlesetselectionfunc) \*handleSetSelectionFunc) | 从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_HandleSetSelectionFunc](#oh_texteditorproxy_handlesetselectionfunc)函数。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetHandleExtendActionFunc](#oh_texteditorproxy_gethandleextendactionfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_HandleExtendActionFunc](#oh_texteditorproxy_handleextendactionfunc) \*handleExtendActionFunc) | 从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_HandleExtendActionFunc](#oh_texteditorproxy_handleextendactionfunc)函数。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetGetLeftTextOfCursorFunc](#oh_texteditorproxy_getgetlefttextofcursorfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_GetLeftTextOfCursorFunc](#oh_texteditorproxy_getlefttextofcursorfunc) \*getLeftTextOfCursorFunc) | 从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_GetLeftTextOfCursorFunc](#oh_texteditorproxy_getlefttextofcursorfunc)函数。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetGetRightTextOfCursorFunc](#oh_texteditorproxy_getgetrighttextofcursorfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_GetRightTextOfCursorFunc](#oh_texteditorproxy_getrighttextofcursorfunc) \*getRightTextOfCursorFunc) | 从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_GetRightTextOfCursorFunc](#oh_texteditorproxy_getrighttextofcursorfunc)函数。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetGetTextIndexAtCursorFunc](#oh_texteditorproxy_getgettextindexatcursorfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_GetTextIndexAtCursorFunc](#oh_texteditorproxy_gettextindexatcursorfunc) \*getTextIndexAtCursorFunc) | 从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_GetTextIndexAtCursorFunc](#oh_texteditorproxy_gettextindexatcursorfunc)函数。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetReceivePrivateCommandFunc](#oh_texteditorproxy_getreceiveprivatecommandfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_ReceivePrivateCommandFunc](#oh_texteditorproxy_receiveprivatecommandfunc) \*receivePrivateCommandFunc) | 从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_ReceivePrivateCommandFunc](#oh_texteditorproxy_receiveprivatecommandfunc)函数。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetSetPreviewTextFunc](#oh_texteditorproxy_getsetpreviewtextfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_SetPreviewTextFunc](#oh_texteditorproxy_setpreviewtextfunc) \*setPreviewTextFunc) | 从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_SetPreviewTextFunc](#oh_texteditorproxy_setpreviewtextfunc)函数。 | 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetFinishTextPreviewFunc](#oh_texteditorproxy_getfinishtextpreviewfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_FinishTextPreviewFunc](#oh_texteditorproxy_finishtextpreviewfunc) \*finishTextPreviewFunc) | 从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_FinishTextPreviewFunc](#oh_texteditorproxy_finishtextpreviewfunc)函数。 | 


## 类型定义说明


### InputMethod_AttachOptions

```
typedef struct InputMethod_AttachOptions InputMethod_AttachOptions
```

**描述**

绑定输入法时携带的选项。

**起始版本：** 12


### InputMethod_CommandValueType

```
typedef enum InputMethod_CommandValueType InputMethod_CommandValueType
```

**描述**

私有数据类型。

**起始版本：** 12


### InputMethod_CursorInfo

```
typedef struct InputMethod_CursorInfo InputMethod_CursorInfo
```

**描述**

光标的坐标位置、宽度和高度。

**起始版本：** 12


### InputMethod_Direction

```
typedef enum InputMethod_Direction InputMethod_Direction
```

**描述**

移动方向。

**起始版本：** 12


### InputMethod_EnterKeyType

```
typedef enum InputMethod_EnterKeyType InputMethod_EnterKeyType
```

**描述**

回车键功能类型。

**起始版本：** 12


### InputMethod_ErrorCode

```
typedef enum InputMethod_ErrorCode InputMethod_ErrorCode
```

**描述**

输入法错误码。

**起始版本：** 12


### InputMethod_RequestKeyboardReason

```
typedef enum InputMethod_RequestKeyboardReason InputMethod_RequestKeyboardReason
```

**描述**

请求键盘输入原因。

**起始版本：** 15


### InputMethod_ExtendAction

```
typedef enum InputMethod_ExtendAction InputMethod_ExtendAction
```

**描述**

编辑框中文本的扩展编辑操作类型。

**起始版本：** 12


### InputMethod_InputMethodProxy

```
typedef struct InputMethod_InputMethodProxy InputMethod_InputMethodProxy
```

**描述**

输入法代理对象。

使用此对象可以用于调用使用输入法的方法。

**起始版本：** 12


### InputMethod_KeyboardStatus

```
typedef enum InputMethod_KeyboardStatus InputMethod_KeyboardStatus
```

**描述**

键盘状态。

**起始版本：** 12


### InputMethod_PrivateCommand

```
typedef struct InputMethod_PrivateCommand InputMethod_PrivateCommand
```

**描述**

私有数据。

输入框和输入法应用之间交互的私有数据。

**起始版本：** 12


### InputMethod_TextAvoidInfo

```
typedef struct InputMethod_TextAvoidInfo InputMethod_TextAvoidInfo
```

**描述**

输入框用于避让键盘的信息。

**起始版本：** 12


### InputMethod_TextConfig

```
typedef struct InputMethod_TextConfig InputMethod_TextConfig
```

**描述**

输入框的配置信息。

**起始版本：** 12


### InputMethod_TextEditorProxy

```
typedef struct InputMethod_TextEditorProxy InputMethod_TextEditorProxy
```

**描述**

输入框代理。

提供了获取来自输入法应用的通知和请求的方法。

**起始版本：** 12


### InputMethod_TextInputType

```
typedef enum InputMethod_TextInputType InputMethod_TextInputType
```

**描述**

文本输入类型。

**起始版本：** 12


### OH_TextEditorProxy_DeleteBackwardFunc

```
typedef void(* OH_TextEditorProxy_DeleteBackwardFunc) (InputMethod_TextEditorProxy *textEditorProxy, int32_t length)
```

**描述**

输入法删除光标左侧文本时触发的函数。

您需要实现此函数，将它设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中，并通过[OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| length | 要删除字符的长度。 | 


### OH_TextEditorProxy_DeleteForwardFunc

```
typedef void(* OH_TextEditorProxy_DeleteForwardFunc) (InputMethod_TextEditorProxy *textEditorProxy, int32_t length)
```

**描述**

输入法删除光标右侧文本时触发的函数。

您需要实现此函数，将它设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中，并通过[OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| length | 要删除字符的长度。 | 


### OH_TextEditorProxy_FinishTextPreviewFunc

```
typedef void(* OH_TextEditorProxy_FinishTextPreviewFunc) (InputMethod_TextEditorProxy *textEditorProxy)
```

**描述**

输入法结束预上屏时触发的函数。

您需要实现此函数，将它设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中，并通过[OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 


### OH_TextEditorProxy_GetLeftTextOfCursorFunc

```
typedef void(* OH_TextEditorProxy_GetLeftTextOfCursorFunc) (InputMethod_TextEditorProxy *textEditorProxy, int32_t number, char16_t text[], size_t *length)
```

**描述**

输入法获取光标左侧文本时触发的函数。

您需要实现此函数，将它设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中，并通过[OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| number | 目标获取文本的长度。 | 
| text | 光标左侧指定长度的文本内容，需要在函数实现中对它赋值。 | 


### OH_TextEditorProxy_GetRightTextOfCursorFunc

```
typedef void(* OH_TextEditorProxy_GetRightTextOfCursorFunc) (InputMethod_TextEditorProxy *textEditorProxy, int32_t number, char16_t text[], size_t *length)
```

**描述**

输入法获取光标右侧文本时触发的函数。

您需要实现此函数，将它设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中，并通过[OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| number | 目标获取文本的长度。 | 
| text | 光标右侧指定长度的文本内容，需要在函数实现中对它赋值。 | 


### OH_TextEditorProxy_GetTextConfigFunc

```
typedef void(* OH_TextEditorProxy_GetTextConfigFunc) (InputMethod_TextEditorProxy *textEditorProxy, InputMethod_TextConfig *config)
```

**描述**

输入法获取输入框配置时触发的函数。

您需要实现此函数，将它设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中，并通过[OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| config | 输入框配置。 | 


### OH_TextEditorProxy_GetTextIndexAtCursorFunc

```
typedef int32_t(* OH_TextEditorProxy_GetTextIndexAtCursorFunc) (InputMethod_TextEditorProxy *textEditorProxy)
```

**描述**

输入法获取光标所在输入框文本索引时触发的函数。

您需要实现此函数，将它设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中，并通过[OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 

**返回：**

返回光标所在输入框文本索引。


### OH_TextEditorProxy_HandleExtendActionFunc

```
typedef void(* OH_TextEditorProxy_HandleExtendActionFunc) (InputMethod_TextEditorProxy *textEditorProxy, InputMethod_ExtendAction action)
```

**描述**

输入法发送扩展编辑操作时触发的函数。

您需要实现此函数，将它设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中，并通过[OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| action | 扩展编辑操作，具体定义详见[InputMethod_ExtendAction](#inputmethod_extendaction)。 | 


### OH_TextEditorProxy_HandleSetSelectionFunc

```
typedef void(* OH_TextEditorProxy_HandleSetSelectionFunc) (InputMethod_TextEditorProxy *textEditorProxy, int32_t start, int32_t end)
```

**描述**

输入法请求选中文本时触发的函数。

您需要实现此函数，将它设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中，并通过[OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| start | 表示选中文本的起始位置。 | 
| end | 表示选中文本的结束位置。 | 


### OH_TextEditorProxy_InsertTextFunc

```
typedef void(* OH_TextEditorProxy_InsertTextFunc) (InputMethod_TextEditorProxy *textEditorProxy, const char16_t *text, size_t length)
```

**描述**

输入法应用插入文本时触发的函数。

您需要实现此函数，将它设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中，并通过[OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| text | 插入的字符。 | 
| length | 插入字符的长度。 | 


### OH_TextEditorProxy_MoveCursorFunc

```
typedef void(* OH_TextEditorProxy_MoveCursorFunc) (InputMethod_TextEditorProxy *textEditorProxy, InputMethod_Direction direction)
```

**描述**

输入法移动光标时触发的函数。

您需要实现此函数，将它设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中，并通过[OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| direction | 光标移动方向，具体定义详见[InputMethod_Direction](#inputmethod_direction)。 | 


### OH_TextEditorProxy_ReceivePrivateCommandFunc

```
typedef int32_t(* OH_TextEditorProxy_ReceivePrivateCommandFunc) (InputMethod_TextEditorProxy *textEditorProxy, InputMethod_PrivateCommand *privateCommand[], size_t size)
```

**描述**

输入法应用发送私有数据命令时触发的函数。

您需要实现此函数，将它设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中，并通过[OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| privateCommand | 私有数据命令。 | 
| size | 私有数据的大小。 | 

**返回：**

返回对私有数据命令处理的处理结果。


### OH_TextEditorProxy_SendEnterKeyFunc

```
typedef void(* OH_TextEditorProxy_SendEnterKeyFunc) (InputMethod_TextEditorProxy *textEditorProxy, InputMethod_EnterKeyType enterKeyType)
```

**描述**

输入法发送回车键时触发的函数。

您需要实现此函数，将它设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中，并通过[OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| enterKeyType | 回车键类型，具体定义详见[InputMethod_EnterKeyType](#inputmethod_enterkeytype-1)。 | 


### OH_TextEditorProxy_SendKeyboardStatusFunc

```
typedef void(* OH_TextEditorProxy_SendKeyboardStatusFunc) (InputMethod_TextEditorProxy *textEditorProxy, InputMethod_KeyboardStatus keyboardStatus)
```

**描述**

输入法通知键盘状态时触发的函数。

您需要实现此函数，将它设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中，并通过[OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| keyboardStatus | 键盘状态，具体定义详见[InputMethod_KeyboardStatus](#inputmethod_keyboardstatus)。 | 


### OH_TextEditorProxy_SetPreviewTextFunc

```
typedef int32_t(* OH_TextEditorProxy_SetPreviewTextFunc) (InputMethod_TextEditorProxy *textEditorProxy, const char16_t text[], size_t length, int32_t start, int32_t end)
```

**描述**

输入法设置预上屏文本时触发的函数。

您需要实现此函数，将它设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中，并通过[OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| text | 请求设置为预上屏样式的文本内容。 | 
| length | 预上屏文本长度。 | 
| start | 预上屏文本起始光标位置。 | 
| end | 预上屏文本结束光标位置。 | 

**返回：**

返回设置预上屏文本的处理结果。


## 枚举类型说明


### InputMethod_CommandValueType

```
enum InputMethod_CommandValueType
```

**描述**

私有数据类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| IME_COMMAND_VALUE_TYPE_NONE | NONE。 | 
| IME_COMMAND_VALUE_TYPE_STRING | 字符串类型。 | 
| IME_COMMAND_VALUE_TYPE_BOOL | 布尔类型。 | 
| IME_COMMAND_VALUE_TYPE_INT32 | 32位带符号整数类型。 | 


### InputMethod_Direction

```
enum InputMethod_Direction
```

**描述**

移动方向。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| IME_DIRECTION_NONE | NONE。 | 
| IME_DIRECTION_UP | 向上。 | 
| IME_DIRECTION_DOWN | 向下。 | 
| IME_DIRECTION_LEFT | 向左。 | 
| IME_DIRECTION_RIGHT | 向右。 | 


### InputMethod_EnterKeyType

```
enum InputMethod_EnterKeyType
```

**描述**

回车键功能类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| IME_ENTER_KEY_UNSPECIFIED | 未指定。 | 
| IME_ENTER_KEY_NONE | NONE。 | 
| IME_ENTER_KEY_GO | 前往。 | 
| IME_ENTER_KEY_SEARCH | 搜索。 | 
| IME_ENTER_KEY_SEND | 发送。 | 
| IME_ENTER_KEY_NEXT | 下一步。 | 
| IME_ENTER_KEY_DONE | 完成。 | 
| IME_ENTER_KEY_PREVIOUS | 上一步。 | 
| IME_ENTER_KEY_NEWLINE | 换行。 | 


### InputMethod_ErrorCode

```
enum InputMethod_ErrorCode
```

**描述**

输入法错误码。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| IME_ERR_OK | 成功。 | 
| IME_ERR_UNDEFINED | 查询失败。 | 
| IME_ERR_PARAMCHECK | 参数检查失败。 | 
| IME_ERR_PACKAGEMANAGER | 包管理异常。 | 
| IME_ERR_IMENGINE | 输入法应用异常。 | 
| IME_ERR_IMCLIENT | 输入框客户端异常。 | 
| IME_ERR_CONFIG_PERSIST | 配置固化失败。当保存配置失败时，会报此错误码。 | 
| IME_ERR_CONTROLLER | 输入法控制器异常。 | 
| IME_ERR_SETTINGS | 输入法设置器异常。 | 
| IME_ERR_IMMS | 输入法管理服务异常。 | 
| IME_ERR_DETACHED | 输入框未绑定。 | 
| IME_ERR_NULL_POINTER | 空指针异常。 | 
| IME_ERR_QUERY_FAILED | 查询失败。 | 


### InputMethod_ExtendAction

```
enum InputMethod_ExtendAction
```

**描述**

编辑框中文本的扩展编辑操作类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| IME_EXTEND_ACTION_SELECT_ALL | 全选。 | 
| IME_EXTEND_ACTION_CUT | 剪切。 | 
| IME_EXTEND_ACTION_COPY | 赋值。 | 
| IME_EXTEND_ACTION_PASTE | 粘贴。 | 


### InputMethod_KeyboardStatus

```
enum InputMethod_KeyboardStatus
```

**描述**

键盘状态。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| IME_KEYBOARD_STATUS_NONE | 键盘状态为NONE。 | 
| IME_KEYBOARD_STATUS_HIDE | 键盘状态为隐藏。 | 
| IME_KEYBOARD_STATUS_SHOW | 键盘状态为显示。 | 


### InputMethod_RequestKeyboardReason

```
enum InputMethod_RequestKeyboardReason
```

**描述**

请求键盘输入原因。

**起始版本：** 15

| 枚举值 | 描述 | 
| -------- | -------- |
| IME_REQUEST_REASON_NONE | 表示没有特定原因触发键盘请求。 | 
| IME_REQUEST_REASON_MOUSE | 表示键盘请求是由鼠标操作触发。 |
| IME_REQUEST_REASON_TOUCH | 表示键盘请求是由触摸操作触发。 | 
| IME_REQUEST_REASON_OTHER | 表示键盘请求是由其他原因触发。 | 


### InputMethod_TextInputType

```
enum InputMethod_TextInputType
```

**描述**

文本输入类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| IME_TEXT_INPUT_TYPE_NONE | NONE。 | 
| IME_TEXT_INPUT_TYPE_TEXT | 文本类型。 | 
| IME_TEXT_INPUT_TYPE_MULTILINE | 多行类型。 | 
| IME_TEXT_INPUT_TYPE_NUMBER | 数字类型。 | 
| IME_TEXT_INPUT_TYPE_PHONE | 电话号码类型。 | 
| IME_TEXT_INPUT_TYPE_DATETIME | 日期类型。 | 
| IME_TEXT_INPUT_TYPE_EMAIL_ADDRESS | 邮箱地址类型。 | 
| IME_TEXT_INPUT_TYPE_URL | 链接类型。 | 
| IME_TEXT_INPUT_TYPE_VISIBLE_PASSWORD | 密码类型。 | 
| IME_TEXT_INPUT_TYPE_NUMBER_PASSWORD | 数字密码类型。 | 
| IME_TEXT_INPUT_TYPE_SCREEN_LOCK_PASSWORD | 锁屏密码类型。 | 
| IME_TEXT_INPUT_TYPE_USER_NAME | 用户名类型。 | 
| IME_TEXT_INPUT_TYPE_NEW_PASSWORD | 新密码类型。 | 
| IME_TEXT_INPUT_TYPE_NUMBER_DECIMAL | NUMBER DECIMAL. | 


## 函数说明


### OH_AttachOptions_Create()

```
InputMethod_AttachOptions* OH_AttachOptions_Create (bool showKeyboard)
```

**描述**

创建一个新的[InputMethod_AttachOptions](#inputmethod_attachoptions)实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| showKeyboard | 表示是否显示键盘。 | 

**返回：**

如果创建成功，返回一个指向新创建的[InputMethod_AttachOptions](#inputmethod_attachoptions)实例的指针。 如果创建失败，对象返回NULL，可能的失败原因有应用地址空间满。


### OH_AttachOptions_CreateWithRequestKeyboardReason()

```
InputMethod_AttachOptions* OH_AttachOptions_CreateWithRequestKeyboardReason (bool showKeyboard, InputMethod_RequestKeyboardReason requestKeyboardReason)
```

**描述**

创建一个新的[InputMethod_AttachOptions](#inputmethod_attachoptions)实例。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| showKeyboard | 表示是否显示键盘。 | 
| requestKeyboardReason | 表示请求键盘输入原因，具体定义详见[InputMethod_RequestKeyboardReason](#inputmethod_requestkeyboardreason)。 | 

**返回：**

如果创建成功，返回一个指向新创建的[InputMethod_AttachOptions](#inputmethod_attachoptions)实例的指针。 如果创建失败，对象返回NULL，失败原因可能是应用地址空间已满。


### OH_AttachOptions_Destroy()

```
void OH_AttachOptions_Destroy (InputMethod_AttachOptions * options)
```

**描述**

销毁一个[InputMethod_AttachOptions](#inputmethod_attachoptions)实例.

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 表示即将被销毁的[InputMethod_AttachOptions](#inputmethod_attachoptions)实例。 | 


### OH_AttachOptions_IsShowKeyboard()

```
InputMethod_ErrorCode OH_AttachOptions_IsShowKeyboard (InputMethod_AttachOptions * options, bool * showKeyboard )
```

**描述**

从[InputMethod_AttachOptions](#inputmethod_attachoptions)中获取是否显示键盘的值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 表示被读取值的[InputMethod_AttachOptions](#inputmethod_attachoptions)实例。 | 
| showKeyboard | 表示绑定时是否显示键盘。 true表示绑定完成时需要显示键盘； false表示绑定完成时不需要显示键盘。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_AttachOptions_GetRequestKeyboardReason()

```
InputMethod_ErrorCode OH_AttachOptions_GetRequestKeyboardReason (InputMethod_AttachOptions * options, int * requestKeyboardReason )
```

**描述**

从[InputMethod_AttachOptions](#inputmethod_attachoptions)中获取输入法键盘拉起原因。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 表示被读取值的[InputMethod_AttachOptions](#inputmethod_attachoptions)实例。 | 
| requestKeyboardReason |  表示请求键盘输入原因，具体定义详见[InputMethod_RequestKeyboardReason](#inputmethod_requestkeyboardreason)。 |  

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_CursorInfo_Create()

```
InputMethod_CursorInfo* OH_CursorInfo_Create (double left, double top, double width, double height )
```

**描述**

创建一个新的[InputMethod_CursorInfo](#inputmethod_cursorinfo)实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| left | 光标靠左点与物理屏幕左侧距离的绝对值。 | 
| top | 光标顶点与物理屏幕上侧距离的绝对值。 | 
| width | 宽度。 | 
| height | 高度。 | 

**返回：**

如果创建成功，返回一个指向新创建的[InputMethod_CursorInfo](#inputmethod_cursorinfo)实例的指针。 如果创建失败，对象返回NULL，可能的失败原因有应用地址空间满。


### OH_CursorInfo_Destroy()

```
void OH_CursorInfo_Destroy (InputMethod_CursorInfo * cursorInfo)
```

**描述**

销毁一个[InputMethod_CursorInfo](#inputmethod_cursorinfo)实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cursorInfo | 表示指向即将被销毁的[InputMethod_CursorInfo](#inputmethod_cursorinfo)实例的指针。 | 


### OH_CursorInfo_GetRect()

```
InputMethod_ErrorCode OH_CursorInfo_GetRect (InputMethod_CursorInfo * cursorInfo, double * left, double * top, double * width, double * height )
```

**描述**

获取光标信息内容。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cursorInfo | 表示指向[InputMethod_CursorInfo](#inputmethod_cursorinfo)实例的指针。 | 
| left | 靠左点与物理屏幕左侧距离的绝对值。 | 
| top | 顶点与物理屏幕上侧距离的绝对值。 | 
| width | 宽度。 | 
| height | 高度。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考[InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_CursorInfo_SetRect()

```
InputMethod_ErrorCode OH_CursorInfo_SetRect (InputMethod_CursorInfo * cursorInfo, double left, double top, double width, double height )
```

**描述**

设置光标信息内容。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cursorInfo | 表示指向[InputMethod_CursorInfo](#inputmethod_cursorinfo)实例的指针。 | 
| left | 光标靠左点与物理屏幕左侧距离的绝对值。 | 
| top | 光标顶点与物理屏幕上侧距离的绝对值。 | 
| width | 宽度。 | 
| height | 高度。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_InputMethodController_Attach()

```
InputMethod_ErrorCode OH_InputMethodController_Attach (InputMethod_TextEditorProxy * textEditorProxy, InputMethod_AttachOptions * options, InputMethod_InputMethodProxy ** inputMethodProxy )
```

**描述**

将应用绑定到输入法服务。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| textEditorProxy | 表示指向[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 调用者需要自行管理textEditorProxy的生命周期。 并且如果调用成功，调用者在下次发起绑定或解绑之前，不能将textEditorProxy释放。 | 
| options | 表示指向[InputMethod_AttachOptions](#inputmethod_attachoptions)实例的指针，是绑定时的选项。 | 
| inputMethodProxy | 表示指向[InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy)实例的指针。生命周期维持到下一次绑定或解绑的调用。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_PARAMCHECK - 表示参数错误。

IME_ERR_IMCLIENT - 输入法客户端错误。

IME_ERR_IMMS - 输入法服务错误。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考[InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_InputMethodController_Detach()

```
InputMethod_ErrorCode OH_InputMethodController_Detach (InputMethod_InputMethodProxy * inputMethodProxy)
```

**描述**

将应用从输入法服务解绑。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| inputMethodProxy | 表示指向[InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy)实例的指针。 inputMethodProxy由调用[OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach)获取。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_IMCLIENT - 表示输入法客户端错误。

IME_ERR_IMMS - 表示输入法服务错误。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考[InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_InputMethodProxy_HideKeyboard()

```
InputMethod_ErrorCode OH_InputMethodProxy_HideKeyboard (InputMethod_InputMethodProxy * inputMethodProxy)
```

**描述**

隐藏键盘。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| inputMethodProxy | 表示指向[InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy)实例的指针。 inputMethodProxy由调用[OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach)获取。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_IMCLIENT - 表示输入法客户端错误。

IME_ERR_IMMS - 表示输入法服务错误。

IME_ERR_DETACHED - 未绑定输入法。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考[InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_InputMethodProxy_NotifyConfigurationChange()

```
InputMethod_ErrorCode OH_InputMethodProxy_NotifyConfigurationChange (InputMethod_InputMethodProxy * inputMethodProxy, InputMethod_EnterKeyType enterKey, InputMethod_TextInputType textType )
```

**描述**

通知输入框配置变化。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| inputMethodProxy | 表示指向[InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy)实例的指针。 inputMethodProxy由调用[OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach)获取。 | 
| enterKey | 回车键类型，具体定义详见[InputMethod_EnterKeyType](#inputmethod_enterkeytype-1)。 | 
| textType | 输入框类型，具体定义详见[InputMethod_TextInputType](#inputmethod_textinputtype-1)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_PARAMCHECK - 表示参数错误。

IME_ERR_IMCLIENT - 输入法客户端错误。

IME_ERR_IMMS - 表示输入法服务错误。

IME_ERR_DETACHED - 未绑定输入法。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考[InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_InputMethodProxy_NotifyCursorUpdate()

```
InputMethod_ErrorCode OH_InputMethodProxy_NotifyCursorUpdate (InputMethod_InputMethodProxy * inputMethodProxy, InputMethod_CursorInfo * cursorInfo )
```

**描述**

通知光标位置变化。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| inputMethodProxy | 表示指向[InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy)实例的指针。 inputMethodProxy由调用[OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach)获取。 | 
| cursorInfo | 指向[InputMethod_CursorInfo](#inputmethod_cursorinfo)实例的指针，表示光标信息。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_PARAMCHECK - 表示参数错误。

IME_ERR_IMCLIENT - 输入法客户端错误。

IME_ERR_IMMS - 表示输入法服务错误。

IME_ERR_DETACHED - 未绑定输入法。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考[InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_InputMethodProxy_NotifySelectionChange()

```
InputMethod_ErrorCode OH_InputMethodProxy_NotifySelectionChange (InputMethod_InputMethodProxy * inputMethodProxy, char16_t text[], size_t length, int start, int end )
```

**描述**

通知文本框选区变化。

当输入框内文本内容、光标位置或选中文本发生变化时，通过此接口将信息通知给输入法应用。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| inputMethodProxy | 表示指向[InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy)实例的指针。 inputMethodProxy由调用[OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach)获取。 | 
| text | 整个输入文本。 | 
| length | text参数的长度。最大长度为8K。 | 
| start | 所选文本的起始位置。 | 
| end | 所选文本的结束位置。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_PARAMCHECK - 表示参数错误。

IME_ERR_IMCLIENT - 输入法客户端错误。

IME_ERR_IMMS - 表示输入法服务错误。

IME_ERR_DETACHED - 未绑定输入法。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考[InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_InputMethodProxy_SendPrivateCommand()

```
InputMethod_ErrorCode OH_InputMethodProxy_SendPrivateCommand (InputMethod_InputMethodProxy * inputMethodProxy, InputMethod_PrivateCommand * privateCommand[], size_t size )
```

**描述**

发送私有数据命令。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| inputMethodProxy | 表示指向[InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy)实例的指针。 inputMethodProxy由调用[OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach)获取。 | 
| privateCommand | 私有命令, 定义在[InputMethod_PrivateCommand](#inputmethod_privatecommand)，最大大小为32KB。 | 
| size | 私有命令的大小. 最大大小为5。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_PARAMCHECK - 表示参数错误。

IME_ERR_IMCLIENT - 输入法客户端错误。

IME_ERR_IMMS - 表示输入法服务错误。

IME_ERR_DETACHED - 未绑定输入法。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考[InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_InputMethodProxy_ShowKeyboard()

```
InputMethod_ErrorCode OH_InputMethodProxy_ShowKeyboard (InputMethod_InputMethodProxy * inputMethodProxy)
```

**描述**

显示键盘。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| inputMethodProxy | 表示指向[InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy)实例的指针。 inputMethodProxy由调用[OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach)获取。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_PARAMCHECK - 表示参数错误。

IME_ERR_IMCLIENT - 输入法客户端错误。

IME_ERR_IMMS - 表示输入法服务错误。

IME_ERR_DETACHED - 未绑定输入法。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考[InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_InputMethodProxy_ShowTextInput()

```
InputMethod_ErrorCode OH_InputMethodProxy_ShowTextInput (InputMethod_InputMethodProxy * inputMethodProxy, InputMethod_AttachOptions *options)
```

**描述**

显示文本输入。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| inputMethodProxy | 表示指向[InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy)实例的指针。 inputMethodProxy由调用[OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach)获取。 | 
| options |  表示指向[InputMethod_AttachOptions](#inputmethod_attachoptions)实例的指针，是绑定时的选项。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_PARAMCHECK - 表示参数错误。

IME_ERR_IMCLIENT - 输入法客户端错误。

IME_ERR_IMMS - 表示输入法服务错误。

IME_ERR_DETACHED - 未绑定输入法。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考[InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_PrivateCommand_Create()

```
InputMethod_PrivateCommand* OH_PrivateCommand_Create (char key[], size_t keyLength )
```

**描述**

创建一个新的[InputMethod_PrivateCommand](#inputmethod_privatecommand)实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| key | 私有数据的key值。 | 
| keyLength | key长度。 | 

**返回：**

如果创建成功，返回一个指向新创建的[InputMethod_PrivateCommand](#inputmethod_privatecommand)实例的指针。 如果创建失败，对象返回NULL，可能的失败原因有应用地址空间满。


### OH_PrivateCommand_Destroy()

```
void OH_PrivateCommand_Destroy (InputMethod_PrivateCommand * command)
```

**描述**

销毁一个[InputMethod_PrivateCommand](#inputmethod_privatecommand)实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| command | 指向即将被销毁的[InputMethod_PrivateCommand](#inputmethod_privatecommand)实例的指针。 | 


### OH_PrivateCommand_GetBoolValue()

```
InputMethod_ErrorCode OH_PrivateCommand_GetBoolValue (InputMethod_PrivateCommand * command, bool * value )
```

**描述**

从[InputMethod_PrivateCommand](#inputmethod_privatecommand)获取布尔类型的value的值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| command | 指向即将被获取value值的[InputMethod_PrivateCommand](#inputmethod_privatecommand)实例的指针。 | 
| value | 布尔类型的value的值。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_PrivateCommand_GetIntValue()

```
InputMethod_ErrorCode OH_PrivateCommand_GetIntValue (InputMethod_PrivateCommand * command, int32_t * value )
```

**描述**

从[InputMethod_PrivateCommand](#inputmethod_privatecommand)获取整数类型的value的值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| command | 指向即将被获取value值的[InputMethod_PrivateCommand](#inputmethod_privatecommand)实例的指针。 | 
| value | 整数类型的value的值。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_PrivateCommand_GetKey()

```
InputMethod_ErrorCode OH_PrivateCommand_GetKey (InputMethod_PrivateCommand * command, const char ** key, size_t * keyLength )
```

**描述**

从[InputMethod_PrivateCommand](#inputmethod_privatecommand)获取key值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| command | 指向即将被获取key值的[InputMethod_PrivateCommand](#inputmethod_privatecommand)实例的指针。 | 
| key | key的生命周期和command一致。不要直接保存key地址，或者直接写key。建议拷贝后使用。 | 
| keyLength | key长度。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_PrivateCommand_GetStrValue()

```
InputMethod_ErrorCode OH_PrivateCommand_GetStrValue (InputMethod_PrivateCommand * command, const char ** value, size_t * valueLength )
```

**描述**

从[InputMethod_PrivateCommand](#inputmethod_privatecommand)获取字符串类型的value的值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| command | 指向即将被获取value值的[InputMethod_PrivateCommand](#inputmethod_privatecommand)实例的指针。 | 
| value | 字符串类型的value的值。 | 
| valueLength | value的生命周期和command一致。不要直接保存value地址，或者直接写value。建议拷贝后使用。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_PrivateCommand_GetValueType()

```
InputMethod_ErrorCode OH_PrivateCommand_GetValueType (InputMethod_PrivateCommand * command, InputMethod_CommandValueType * type )
```

**描述**

从[InputMethod_PrivateCommand](#inputmethod_privatecommand)获取value的数据类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| command | 指向即将被获取value值的[InputMethod_PrivateCommand](#inputmethod_privatecommand)实例的指针。 | 
| type | value值的数据类型。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_PrivateCommand_SetBoolValue()

```
InputMethod_ErrorCode OH_PrivateCommand_SetBoolValue (InputMethod_PrivateCommand * command, bool value )
```

**描述**

设置[InputMethod_PrivateCommand](#inputmethod_privatecommand)的布尔类型value值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| command | 指向即将被设置的[InputMethod_PrivateCommand](#inputmethod_privatecommand)实例的指针。 | 
| value | 布尔类型value值。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_PrivateCommand_SetIntValue()

```
InputMethod_ErrorCode OH_PrivateCommand_SetIntValue (InputMethod_PrivateCommand * command, int32_t value )
```

**描述**

设置[InputMethod_PrivateCommand](#inputmethod_privatecommand)的整数类型value值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| command | 指向即将被设置的[InputMethod_PrivateCommand](#inputmethod_privatecommand)实例的指针。 | 
| value | 整型value值。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_PrivateCommand_SetKey()

```
InputMethod_ErrorCode OH_PrivateCommand_SetKey (InputMethod_PrivateCommand * command, char key[], size_t keyLength )
```

**描述**

设置[InputMethod_PrivateCommand](#inputmethod_privatecommand)的key值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| command | 指向即将被设置的[InputMethod_PrivateCommand](#inputmethod_privatecommand)实例的指针。 | 
| key | key值。 | 
| keyLength | key长度。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_PrivateCommand_SetStrValue()

```
InputMethod_ErrorCode OH_PrivateCommand_SetStrValue (InputMethod_PrivateCommand * command, char value[], size_t valueLength )
```

**描述**

设置[InputMethod_PrivateCommand](#inputmethod_privatecommand)的字符串类型value值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| command | 指向即将被设置的[InputMethod_PrivateCommand](#inputmethod_privatecommand)实例的指针。 | 
| value | 字符串类型value值。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextAvoidInfo_Create()

```
InputMethod_TextAvoidInfo* OH_TextAvoidInfo_Create (double positionY, double height )
```

**描述**

创建一个新的[InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo)实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| positionY | 表示输入框位置的Y坐标值。 | 
| height | 表示输入框高度。 | 

**返回：**

如果创建成功，返回一个指向新创建的[InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo)实例的指针。 如果创建失败，对象返回NULL，可能的失败原因有应用地址空间满。


### OH_TextAvoidInfo_Destroy()

```
void OH_TextAvoidInfo_Destroy (InputMethod_TextAvoidInfo * info)
```

**描述**

销毁一个[InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo)实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 表示指向即将被销毁的[InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo)实例的指针。 | 


### OH_TextAvoidInfo_GetHeight()

```
InputMethod_ErrorCode OH_TextAvoidInfo_GetHeight (InputMethod_TextAvoidInfo * info, double * height )
```

**描述**

从[InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo)获取高度值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 指向即将被获取值的[InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo)实例的指针。 | 
| height | 输入框高度。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextAvoidInfo_GetPositionY()

```
InputMethod_ErrorCode OH_TextAvoidInfo_GetPositionY (InputMethod_TextAvoidInfo * info, double * positionY )
```

**描述**

从[InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo)获取Y坐标值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 指向即将被获取值的[InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo)实例的指针。 | 
| positionY | positionY值，即输入框顶点与物理屏幕上侧距离的绝对值。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextAvoidInfo_SetHeight()

```
InputMethod_ErrorCode OH_TextAvoidInfo_SetHeight (InputMethod_TextAvoidInfo * info, double height )
```

**描述**

设置[InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo)中的高度值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 指向即将被设置值的[InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo)实例的指针。 | 
| height | 高度值。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextAvoidInfo_SetPositionY()

```
InputMethod_ErrorCode OH_TextAvoidInfo_SetPositionY (InputMethod_TextAvoidInfo * info, double positionY )
```

**描述**

设置[InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo)中的Y坐标值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 指向即将被设置值的[InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo)实例的指针。 | 
| positionY | positionY值，即输入框顶点与物理屏幕上侧距离的绝对值。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextConfig_Create()

```
InputMethod_TextConfig* OH_TextConfig_Create ()
```

**描述**

创建一个新的[InputMethod_TextConfig](#inputmethod_textconfig)实例。

**起始版本：** 12

**返回：**

如果创建成功，返回一个指向新创建的[InputMethod_TextConfig](#inputmethod_textconfig)实例的指针。 如果创建失败，对象返回NULL，可能的失败原因有应用地址空间满。


### OH_TextConfig_Destroy()

```
void OH_TextConfig_Destroy (InputMethod_TextConfig * config)
```

**描述**

销毁一个[InputMethod_TextConfig](#inputmethod_textconfig)实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| config | 表示指向即将被销毁的[InputMethod_TextConfig](#inputmethod_textconfig)实例的指针。 | 


### OH_TextConfig_GetCursorInfo()

```
InputMethod_ErrorCode OH_TextConfig_GetCursorInfo (InputMethod_TextConfig * config, InputMethod_CursorInfo ** cursorInfo )
```

**描述**

获取[InputMethod_TextConfig](#inputmethod_textconfig)实例的光标信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| config | 指向即将被获取值的[InputMethod_TextConfig](#inputmethod_textconfig)实例的指针。 | 
| cursorInfo | 光标信息。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextConfig_GetEnterKeyType()

```
InputMethod_ErrorCode OH_TextConfig_GetEnterKeyType (InputMethod_TextConfig * config, InputMethod_EnterKeyType * enterKeyType )
```

**描述**

获取[InputMethod_TextConfig](#inputmethod_textconfig)实例的回车键功能类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| config | 指向即将被获取值的[InputMethod_TextConfig](#inputmethod_textconfig)实例的指针。 | 
| enterKeyType | 输入框的回车键功能类型，具体定义详见[InputMethod_EnterKeyType](#inputmethod_enterkeytype-1)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextConfig_GetInputType()

```
InputMethod_ErrorCode OH_TextConfig_GetInputType (InputMethod_TextConfig * config, InputMethod_TextInputType * inputType )
```

**描述**

获取[InputMethod_TextConfig](#inputmethod_textconfig)实例的输入框类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| config | 指向即将被获取值的[InputMethod_TextConfig](#inputmethod_textconfig)实例的指针。 | 
| inputType | 输入框的输入类型，具体定义详见[InputMethod_TextInputType](#inputmethod_textinputtype-1)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextConfig_GetSelection()

```
InputMethod_ErrorCode OH_TextConfig_GetSelection (InputMethod_TextConfig * config, int32_t * start, int32_t * end )
```

**描述**

获取[InputMethod_TextConfig](#inputmethod_textconfig)实例的选区范围信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| config | 指向即将被获取值的[InputMethod_TextConfig](#inputmethod_textconfig)实例的指针。 | 
| start | 所选文本的起始位置。 | 
| end | 所选文本的结束位置。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。

### OH_TextConfig_GetTextAvoidInfo()

```
InputMethod_ErrorCode OH_TextConfig_GetTextAvoidInfo (InputMethod_TextConfig * config, InputMethod_TextAvoidInfo ** avoidInfo )
```

**描述**

获取[InputMethod_TextConfig](#inputmethod_textconfig)实例的避让信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| config | 指向即将被获取值的[InputMethod_TextConfig](#inputmethod_textconfig)实例的指针。 | 
| avoidInfo | 输入框避让信息。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextConfig_GetWindowId()

```
InputMethod_ErrorCode OH_TextConfig_GetWindowId (InputMethod_TextConfig * config, int32_t * windowId )
```

**描述**

获取[InputMethod_TextConfig](#inputmethod_textconfig)实例所属窗口的窗口id。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| config | 指向即将被获取值的[InputMethod_TextConfig](#inputmethod_textconfig)实例的指针。 | 
| windowId | 绑定输入法的应用所属窗口的窗口id。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextConfig_IsPreviewTextSupported()

```
InputMethod_ErrorCode OH_TextConfig_IsPreviewTextSupported (InputMethod_TextConfig * config, bool * supported )
```

**描述**

获取[InputMethod_TextConfig](#inputmethod_textconfig)实例的是否支持预上屏。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| config | 指向即将被获取值的[InputMethod_TextConfig](#inputmethod_textconfig)实例的指针。 | 
| supported | 表示输入框是否支持预上屏。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextConfig_SetEnterKeyType()

```
InputMethod_ErrorCode OH_TextConfig_SetEnterKeyType (InputMethod_TextConfig * config, InputMethod_EnterKeyType enterKeyType )
```

**描述**

设置[InputMethod_TextConfig](#inputmethod_textconfig)实例的回车键功能类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| config | 指向即将被设置值的[InputMethod_TextConfig](#inputmethod_textconfig)实例的指针。 | 
| enterKeyType | 回车键功能类型，具体定义详见[InputMethod_EnterKeyType](#inputmethod_enterkeytype-1)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextConfig_SetInputType()

```
InputMethod_ErrorCode OH_TextConfig_SetInputType (InputMethod_TextConfig * config, InputMethod_TextInputType inputType )
```

**描述**

设置[InputMethod_TextConfig](#inputmethod_textconfig)实例的输入框类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| config | 指向即将被设置值的[InputMethod_TextConfig](#inputmethod_textconfig)实例的指针。 | 
| inputType | 输入框的输入类型，具体定义详见[InputMethod_TextInputType](#inputmethod_textinputtype-1)。| 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextConfig_SetPreviewTextSupport()

```
InputMethod_ErrorCode OH_TextConfig_SetPreviewTextSupport (InputMethod_TextConfig * config, bool supported )
```

**描述**

将预上屏支持情况设置到[InputMethod_TextConfig](#inputmethod_textconfig)实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| config | 指向即将被设置值的[InputMethod_TextConfig](#inputmethod_textconfig)实例的指针。 | 
| supported | 表示输入框是否支持预上屏。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextConfig_SetSelection()

```
InputMethod_ErrorCode OH_TextConfig_SetSelection (InputMethod_TextConfig * config, int32_t start, int32_t end )
```

**描述**

设置[InputMethod_TextConfig](#inputmethod_textconfig)实例的选中文本范围。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| config | 指向即将被设置值的[InputMethod_TextConfig](#inputmethod_textconfig)实例的指针。 | 
| start | 所选文本的起始位置。 | 
| end | 所选文本的结束位置。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextConfig_SetWindowId()

```
InputMethod_ErrorCode OH_TextConfig_SetWindowId (InputMethod_TextConfig * config, int32_t windowId )
```

**描述**

设置[InputMethod_TextConfig](#inputmethod_textconfig)实例的所属窗口的窗口id。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| config | 指向即将被设置值的[InputMethod_TextConfig](#inputmethod_textconfig)实例的指针。 | 
| windowId | 绑定输入法的应用所属窗口的窗口id。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_Create()

```
InputMethod_TextEditorProxy* OH_TextEditorProxy_Create ()
```

**描述**

创建一个新的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例。

**起始版本：** 12

**返回：**

如果创建成功，返回一个指向新创建的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 如果创建失败，对象返回NULL，可能的失败原因有应用地址空间满。


### OH_TextEditorProxy_Destroy()

```
void OH_TextEditorProxy_Destroy (InputMethod_TextEditorProxy * proxy)
```

**描述**

销毁一个[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 表示指向即将被销毁的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 


### OH_TextEditorProxy_GetDeleteBackwardFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetDeleteBackwardFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_DeleteBackwardFunc * deleteBackwardFunc )
```

**描述**

从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_DeleteBackwardFunc](#oh_texteditorproxy_deletebackwardfunc)函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向被读取的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| deleteBackwardFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_DeleteBackwardFunc](#oh_texteditorproxy_deletebackwardfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_GetDeleteForwardFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetDeleteForwardFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_DeleteForwardFunc * deleteForwardFunc )
```

**描述**

从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_DeleteForwardFunc](#oh_texteditorproxy_deleteforwardfunc)函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向被读取的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| deleteForwardFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_DeleteForwardFunc](#oh_texteditorproxy_deleteforwardfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_GetFinishTextPreviewFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetFinishTextPreviewFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_FinishTextPreviewFunc * finishTextPreviewFunc )
```

**描述**

从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_FinishTextPreviewFunc](#oh_texteditorproxy_finishtextpreviewfunc)函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向被读取的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| finishTextPreviewFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_FinishTextPreviewFunc](#oh_texteditorproxy_finishtextpreviewfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_GetGetLeftTextOfCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetGetLeftTextOfCursorFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_GetLeftTextOfCursorFunc * getLeftTextOfCursorFunc )
```

**描述**

从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_GetLeftTextOfCursorFunc](#oh_texteditorproxy_getlefttextofcursorfunc)函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向被读取的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| getLeftTextOfCursorFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_GetLeftTextOfCursorFunc](#oh_texteditorproxy_getlefttextofcursorfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_GetGetRightTextOfCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetGetRightTextOfCursorFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_GetRightTextOfCursorFunc * getRightTextOfCursorFunc )
```

**描述**

从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_GetRightTextOfCursorFunc](#oh_texteditorproxy_getrighttextofcursorfunc)函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向被读取的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| getRightTextOfCursorFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_GetRightTextOfCursorFunc](#oh_texteditorproxy_getrighttextofcursorfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_GetGetTextConfigFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetGetTextConfigFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_GetTextConfigFunc * getTextConfigFunc )
```

**描述**

从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc)函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向被读取的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| getTextConfigFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_GetGetTextIndexAtCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetGetTextIndexAtCursorFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_GetTextIndexAtCursorFunc * getTextIndexAtCursorFunc )
```

**描述**

从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_GetTextIndexAtCursorFunc](#oh_texteditorproxy_gettextindexatcursorfunc)函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向被读取的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| getTextIndexAtCursorFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_GetTextIndexAtCursorFunc](#oh_texteditorproxy_gettextindexatcursorfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_GetHandleExtendActionFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetHandleExtendActionFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_HandleExtendActionFunc * handleExtendActionFunc )
```

**描述**

从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_HandleExtendActionFunc](#oh_texteditorproxy_handleextendactionfunc)函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向被读取的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| handleExtendActionFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_HandleExtendActionFunc](#oh_texteditorproxy_handleextendactionfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_GetHandleSetSelectionFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetHandleSetSelectionFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_HandleSetSelectionFunc * handleSetSelectionFunc )
```

**描述**

从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_HandleSetSelectionFunc](#oh_texteditorproxy_handlesetselectionfunc)函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向被读取的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| handleSetSelectionFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_HandleSetSelectionFunc](#oh_texteditorproxy_handlesetselectionfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_GetInsertTextFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetInsertTextFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_InsertTextFunc * insertTextFunc )
```

**描述**

从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_InsertTextFunc](#oh_texteditorproxy_inserttextfunc)函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向被读取的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| insertTextFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_InsertTextFunc](#oh_texteditorproxy_inserttextfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_GetMoveCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetMoveCursorFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_MoveCursorFunc * moveCursorFunc )
```

**描述**

从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_MoveCursorFunc](#oh_texteditorproxy_movecursorfunc)函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向被读取的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| moveCursorFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_MoveCursorFunc](#oh_texteditorproxy_movecursorfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_GetReceivePrivateCommandFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetReceivePrivateCommandFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_ReceivePrivateCommandFunc * receivePrivateCommandFunc )
```

**描述**

从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_ReceivePrivateCommandFunc](#oh_texteditorproxy_receiveprivatecommandfunc)函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向被读取的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| receivePrivateCommandFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_ReceivePrivateCommandFunc](#oh_texteditorproxy_receiveprivatecommandfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_GetSendEnterKeyFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetSendEnterKeyFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_SendEnterKeyFunc * sendEnterKeyFunc )
```

**描述**

从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_SendEnterKeyFunc](#oh_texteditorproxy_sendenterkeyfunc)函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向被读取的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| sendEnterKeyFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_SendEnterKeyFunc](#oh_texteditorproxy_sendenterkeyfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_GetSendKeyboardStatusFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetSendKeyboardStatusFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_SendKeyboardStatusFunc * sendKeyboardStatusFunc )
```

**描述**

从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_SendKeyboardStatusFunc](#oh_texteditorproxy_sendkeyboardstatusfunc)函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向被读取的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| sendKeyboardStatusFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_SendKeyboardStatusFunc](#oh_texteditorproxy_sendkeyboardstatusfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_GetSetPreviewTextFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetSetPreviewTextFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_SetPreviewTextFunc * setPreviewTextFunc )
```

**描述**

从[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中获取[OH_TextEditorProxy_SetPreviewTextFunc](#oh_texteditorproxy_setpreviewtextfunc)函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向被读取的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| setPreviewTextFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_SetPreviewTextFunc](#oh_texteditorproxy_setpreviewtextfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_SetDeleteBackwardFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetDeleteBackwardFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_DeleteBackwardFunc deleteBackwardFunc )
```

**描述**

将函数[OH_TextEditorProxy_DeleteBackwardFunc](#oh_texteditorproxy_deletebackwardfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| deleteBackwardFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_DeleteBackwardFunc](#oh_texteditorproxy_deletebackwardfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_SetDeleteForwardFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetDeleteForwardFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_DeleteForwardFunc deleteForwardFunc )
```

**描述**

将函数[OH_TextEditorProxy_DeleteForwardFunc](#oh_texteditorproxy_deleteforwardfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| deleteForwardFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_DeleteForwardFunc](#oh_texteditorproxy_deleteforwardfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_SetFinishTextPreviewFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetFinishTextPreviewFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_FinishTextPreviewFunc finishTextPreviewFunc )
```

**描述**

将函数[OH_TextEditorProxy_FinishTextPreviewFunc](#oh_texteditorproxy_finishtextpreviewfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| finishTextPreviewFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_FinishTextPreviewFunc](#oh_texteditorproxy_finishtextpreviewfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_SetGetLeftTextOfCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetGetLeftTextOfCursorFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_GetLeftTextOfCursorFunc getLeftTextOfCursorFunc )
```

**描述**

将函数[OH_TextEditorProxy_GetLeftTextOfCursorFunc](#oh_texteditorproxy_getlefttextofcursorfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| getLeftTextOfCursorFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_GetLeftTextOfCursorFunc](#oh_texteditorproxy_getlefttextofcursorfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_SetGetRightTextOfCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetGetRightTextOfCursorFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_GetRightTextOfCursorFunc getRightTextOfCursorFunc )
```

**描述**

将函数[OH_TextEditorProxy_GetRightTextOfCursorFunc](#oh_texteditorproxy_getrighttextofcursorfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| getRightTextOfCursorFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_GetRightTextOfCursorFunc](#oh_texteditorproxy_getrighttextofcursorfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_SetGetTextConfigFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetGetTextConfigFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_GetTextConfigFunc getTextConfigFunc )
```

**描述**

将函数[OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| getTextConfigFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_SetGetTextIndexAtCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetGetTextIndexAtCursorFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_GetTextIndexAtCursorFunc getTextIndexAtCursorFunc )
```

**描述**

将函数[OH_TextEditorProxy_GetTextIndexAtCursorFunc](#oh_texteditorproxy_gettextindexatcursorfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| getTextIndexAtCursorFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_GetTextIndexAtCursorFunc](#oh_texteditorproxy_gettextindexatcursorfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_SetHandleExtendActionFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetHandleExtendActionFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_HandleExtendActionFunc handleExtendActionFunc )
```

**描述**

将函数[OH_TextEditorProxy_HandleExtendActionFunc](#oh_texteditorproxy_handleextendactionfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| handleExtendActionFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_HandleExtendActionFunc](#oh_texteditorproxy_handleextendactionfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_SetHandleSetSelectionFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetHandleSetSelectionFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_HandleSetSelectionFunc handleSetSelectionFunc )
```

**描述**

将函数[OH_TextEditorProxy_HandleSetSelectionFunc](#oh_texteditorproxy_handlesetselectionfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| handleSetSelectionFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_HandleSetSelectionFunc](#oh_texteditorproxy_handlesetselectionfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_SetInsertTextFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetInsertTextFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_InsertTextFunc insertTextFunc )
```

**描述**

将函数[OH_TextEditorProxy_InsertTextFunc](#oh_texteditorproxy_inserttextfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| insertTextFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_InsertTextFunc](#oh_texteditorproxy_inserttextfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_SetMoveCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetMoveCursorFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_MoveCursorFunc moveCursorFunc )
```

**描述**

将函数[OH_TextEditorProxy_SetMoveCursorFunc](#oh_texteditorproxy_setmovecursorfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| moveCursorFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_MoveCursorFunc](#oh_texteditorproxy_movecursorfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_SetReceivePrivateCommandFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetReceivePrivateCommandFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_ReceivePrivateCommandFunc receivePrivateCommandFunc )
```

**描述**

将函数[OH_TextEditorProxy_ReceivePrivateCommandFunc](#oh_texteditorproxy_receiveprivatecommandfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| receivePrivateCommandFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_ReceivePrivateCommandFunc](#oh_texteditorproxy_receiveprivatecommandfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_SetSendEnterKeyFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetSendEnterKeyFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_SendEnterKeyFunc sendEnterKeyFunc )
```

**描述**

将函数[OH_TextEditorProxy_SetSendEnterKeyFunc](#oh_texteditorproxy_setsendenterkeyfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| sendEnterKeyFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_SendEnterKeyFunc](#oh_texteditorproxy_sendenterkeyfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_SetSendKeyboardStatusFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetSendKeyboardStatusFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_SendKeyboardStatusFunc sendKeyboardStatusFunc )
```

**描述**

将函数[OH_TextEditorProxy_SendKeyboardStatusFunc](#oh_texteditorproxy_sendkeyboardstatusfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| sendKeyboardStatusFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_SendKeyboardStatusFunc](#oh_texteditorproxy_sendkeyboardstatusfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。


### OH_TextEditorProxy_SetSetPreviewTextFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetSetPreviewTextFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_SetPreviewTextFunc setPreviewTextFunc )
```

**描述**

将函数[OH_TextEditorProxy_SetPreviewTextFunc](#oh_texteditorproxy_setpreviewtextfunc)设置到[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 指向即将被设置的[InputMethod_TextEditorProxy](#inputmethod_texteditorproxy)实例的指针。 | 
| setPreviewTextFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_SetPreviewTextFunc](#oh_texteditorproxy_setpreviewtextfunc)。 | 

**返回：**

返回一个特定的错误码。

IME_ERR_OK - 表示成功。

IME_ERR_NULL_POINTER - 非预期的空指针。

具体错误码可以参考 [InputMethod_ErrorCode](#inputmethod_errorcode)。