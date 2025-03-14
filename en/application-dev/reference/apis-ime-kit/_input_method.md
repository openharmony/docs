# InputMethod


## Overview

The InputMethod module provides methods for using and developing input methods.

**Since**: 12


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [inputmethod_attach_options_capi.h](inputmethod__attach__options__capi_8h.md) | Provides methods for creating, destroying, reading, and writing the option object bound to the input method.| 
| [inputmethod_controller_capi.h](inputmethod__controller__capi_8h.md) | Provides methods for binding and unbinding input methods.| 
| [inputmethod_cursor_info_capi.h](inputmethod__cursor__info__capi_8h.md) | Provides methods for creating, destroying, reading, and writing cursor information objects.| 
| [inputmethod_inputmethod_proxy_capi.h](inputmethod__inputmethod__proxy__capi_8h.md) | Provides methods for using the input method, allowing requests and notifications to be sent to the input method application.| 
| [inputmethod_private_command_capi.h](inputmethod__private__command__capi_8h.md) | Provides methods for creating, destroying, reading, and writing private data objects.| 
| [inputmethod_text_avoid_info_capi.h](inputmethod__text__avoid__info__capi_8h.md) | Provides methods for creating, destroying, reading, and writing the text box avoidance information objects.| 
| [inputmethod_text_config_capi.h](inputmethod__text__config__capi_8h.md) | Provides methods for creating, destroying, reading, and writing the text box configuration information objects.| 
| [inputmethod_text_editor_proxy_capi.h](inputmethod__text__editor__proxy__capi_8h.md) | Provides a set of methods for the custom text box developed by the application to obtain notifications and requests from the input method application.| 
| [inputmethod_types_capi.h](inputmethod__types__capi_8h.md) | Defines the types related to the input method.| 


### Types

| Name| Description| 
| -------- | -------- |
| [InputMethod_AttachOptions](#inputmethod_attachoptions) | Options for binding the input method.| 
| [InputMethod_CursorInfo](#inputmethod_cursorinfo) | Cursor information.| 
| [InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) | Input method proxy object.| 
| [InputMethod_PrivateCommand](#inputmethod_privatecommand) | Private data.| 
| [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) | Text box avoidance information.| 
| [InputMethod_TextConfig](#inputmethod_textconfig) | Text box configuration.| 
| [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) | Text box proxy.| 
| typedef void(\* [OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, [InputMethod_TextConfig](#inputmethod_textconfig) \*config) | Function called when the input method obtains the text box configuration.| 
| typedef void(\* [OH_TextEditorProxy_InsertTextFunc](#oh_texteditorproxy_inserttextfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, const char16_t \*text, size_t length) | Function called when the input method application inserts text.| 
| typedef void(\* [OH_TextEditorProxy_DeleteForwardFunc](#oh_texteditorproxy_deleteforwardfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, int32_t length) | Function called when the input method deletes the text on the right of the cursor.| 
| typedef void(\* [OH_TextEditorProxy_DeleteBackwardFunc](#oh_texteditorproxy_deletebackwardfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, int32_t length) | Function called when the input method deletes the text on the left of the cursor.| 
| typedef void(\* [OH_TextEditorProxy_SendKeyboardStatusFunc](#oh_texteditorproxy_sendkeyboardstatusfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, [InputMethod_KeyboardStatus](#inputmethod_keyboardstatus) keyboardStatus) | Function called when the input method notifies the keyboard status.| 
| typedef void(\* [OH_TextEditorProxy_SendEnterKeyFunc](#oh_texteditorproxy_sendenterkeyfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, [InputMethod_EnterKeyType](#inputmethod_enterkeytype) enterKeyType) | Function called when the Enter key is pressed in the input method.| 
| typedef void(\* [OH_TextEditorProxy_MoveCursorFunc](#oh_texteditorproxy_movecursorfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, [InputMethod_Direction](#inputmethod_direction) direction) | Function called when the cursor is moved in the input method.| 
| typedef void(\* [OH_TextEditorProxy_HandleSetSelectionFunc](#oh_texteditorproxy_handlesetselectionfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, int32_t start, int32_t end) | Function called when the input method requests to select text.| 
| typedef void(\* [OH_TextEditorProxy_HandleExtendActionFunc](#oh_texteditorproxy_handleextendactionfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, [InputMethod_ExtendAction](#inputmethod_extendaction) action) | Function called when the input method sends an extended editing operation.| 
| typedef void(\* [OH_TextEditorProxy_GetLeftTextOfCursorFunc](#oh_texteditorproxy_getlefttextofcursorfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, int32_t number, char16_t text[], size_t \*length) | Function called when the input method obtains the text on the left of the cursor.| 
| typedef void(\* [OH_TextEditorProxy_GetRightTextOfCursorFunc](#oh_texteditorproxy_getrighttextofcursorfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, int32_t number, char16_t text[], size_t \*length) | Function called when the input method obtains the text on the right of the cursor.| 
| typedef int32_t(\* [OH_TextEditorProxy_GetTextIndexAtCursorFunc](#oh_texteditorproxy_gettextindexatcursorfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy) | Function called when the input method obtains the index of the text where the cursor is located in the text box.| 
| typedef int32_t(\* [OH_TextEditorProxy_ReceivePrivateCommandFunc](#oh_texteditorproxy_receiveprivatecommandfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, [InputMethod_PrivateCommand](#inputmethod_privatecommand) \*privateCommand[], size_t size) | Function called when the input method application sends a private data command.| 
| typedef int32_t(\* [OH_TextEditorProxy_SetPreviewTextFunc](#oh_texteditorproxy_setpreviewtextfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, const char16_t text[], size_t length, int32_t start, int32_t end) | Function called when the input method sets the text preview feature.| 
| typedef void(\* [OH_TextEditorProxy_FinishTextPreviewFunc](#oh_texteditorproxy_finishtextpreviewfunc)) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy) | Function called when the input method ends the text preview feature.| 
| [InputMethod_KeyboardStatus](#inputmethod_keyboardstatus) | Keyboard status.| 
| [InputMethod_EnterKeyType](#inputmethod_enterkeytype) | Enter function type.| 
| [InputMethod_Direction](#inputmethod_direction) | Moving direction.| 
| [InputMethod_ExtendAction](#inputmethod_extendaction) | Type of the extended edit action on the text box.| 
| [InputMethod_TextInputType](#inputmethod_textinputtype) | Text input type.| 
| [InputMethod_CommandValueType](#inputmethod_commandvaluetype) | Private data type.| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) | Error code of the input method.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [InputMethod_KeyboardStatus](#inputmethod_keyboardstatus) {<br>IME_KEYBOARD_STATUS_NONE = 0,<br>IME_KEYBOARD_STATUS_HIDE = 1,<br>IME_KEYBOARD_STATUS_SHOW = 2<br>} | Keyboard status.| 
| [InputMethod_EnterKeyType](#inputmethod_enterkeytype) {<br>IME_ENTER_KEY_UNSPECIFIED = 0,<br>IME_ENTER_KEY_NONE = 1,<br>IME_ENTER_KEY_GO = 2,<br>IME_ENTER_KEY_SEARCH = 3,<br>IME_ENTER_KEY_SEND = 4,<br>IME_ENTER_KEY_NEXT = 5,<br>IME_ENTER_KEY_DONE = 6,<br>IME_ENTER_KEY_PREVIOUS = 7,<br>IME_ENTER_KEY_NEWLINE = 8<br>} | Enter function type.| 
| [InputMethod_Direction](#inputmethod_direction) {<br>IME_DIRECTION_NONE = 0,<br>IME_DIRECTION_UP = 1,<br>IME_DIRECTION_DOWN = 2,<br>IME_DIRECTION_LEFT = 3,<br>IME_DIRECTION_RIGHT = 4<br>} | Moving direction.| 
| [InputMethod_ExtendAction](#inputmethod_extendaction) {<br>IME_EXTEND_ACTION_SELECT_ALL = 0,<br>IME_EXTEND_ACTION_CUT = 3,<br>IME_EXTEND_ACTION_COPY = 4,<br>IME_EXTEND_ACTION_PASTE = 5<br>} | Type of the extended edit action on the text box.| 
| [InputMethod_TextInputType](#inputmethod_textinputtype) {<br>IME_TEXT_INPUT_TYPE_NONE = -1,<br>IME_TEXT_INPUT_TYPE_TEXT = 0,<br>IME_TEXT_INPUT_TYPE_MULTILINE = 1,<br>IME_TEXT_INPUT_TYPE_NUMBER = 2,<br>IME_TEXT_INPUT_TYPE_PHONE = 3,<br>IME_TEXT_INPUT_TYPE_DATETIME = 4,<br>IME_TEXT_INPUT_TYPE_EMAIL_ADDRESS = 5,<br>IME_TEXT_INPUT_TYPE_URL = 6,<br>IME_TEXT_INPUT_TYPE_VISIBLE_PASSWORD = 7,<br>IME_TEXT_INPUT_TYPE_NUMBER_PASSWORD = 8,<br>IME_TEXT_INPUT_TYPE_SCREEN_LOCK_PASSWORD = 9,<br>IME_TEXT_INPUT_TYPE_USER_NAME = 10,<br>IME_TEXT_INPUT_TYPE_NEW_PASSWORD = 11,<br>IME_TEXT_INPUT_TYPE_NUMBER_DECIMAL = 12<br>} | Text input type.| 
| [InputMethod_CommandValueType](#inputmethod_commandvaluetype) {<br>IME_COMMAND_VALUE_TYPE_NONE = 0,<br>IME_COMMAND_VALUE_TYPE_STRING = 1,<br>IME_COMMAND_VALUE_TYPE_BOOL = 2,<br>IME_COMMAND_VALUE_TYPE_INT32 = 3<br>} | Private data type.| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) {<br>IME_ERR_OK = 0, IME_ERR_UNDEFINED = 1,<br>IME_ERR_PARAMCHECK = 401,<br>IME_ERR_PACKAGEMANAGER = 12800001,<br>IME_ERR_IMENGINE = 12800002,<br>IME_ERR_IMCLIENT = 12800003,<br>IME_ERR_CONFIG_PERSIST = 12800005,<br>IME_ERR_CONTROLLER = 12800006,<br>IME_ERR_SETTINGS = 12800007,<br>IME_ERR_IMMS = 12800008,<br>IME_ERR_DETACHED = 12800009,<br>IME_ERR_NULL_POINTER = 12802000,<br>IME_ERR_QUERY_FAILED = 12802001<br>} | Error code of the input method.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [InputMethod_AttachOptions](#inputmethod_attachoptions) \* [OH_AttachOptions_Create](#oh_attachoptions_create) (bool showKeyboard) | Creates an [InputMethod_AttachOptions](#inputmethod_attachoptions) instance.| 
| void [OH_AttachOptions_Destroy](#oh_attachoptions_destroy) ([InputMethod_AttachOptions](#inputmethod_attachoptions) \*options) | Destroys an [InputMethod_AttachOptions](#inputmethod_attachoptions) instance.| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_AttachOptions_IsShowKeyboard](#oh_attachoptions_isshowkeyboard) ([InputMethod_AttachOptions](#inputmethod_attachoptions) \*options, bool \*showKeyboard) | Obtains the configured value that indicates whether to display the keyboard from [InputMethod_AttachOptions](#inputmethod_attachoptions).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*textEditorProxy, [InputMethod_AttachOptions](#inputmethod_attachoptions) \*options, [InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) \*\*inputMethodProxy) | Binds an application to the input method service.| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_InputMethodController_Detach](#oh_inputmethodcontroller_detach) ([InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) \*inputMethodProxy) | Unbinds an application from the input method service.| 
| [InputMethod_CursorInfo](#inputmethod_cursorinfo) \* [OH_CursorInfo_Create](#oh_cursorinfo_create) (double left, double top, double width, double height) | Creates an [InputMethod_CursorInfo](#inputmethod_cursorinfo) instance.| 
| void [OH_CursorInfo_Destroy](#oh_cursorinfo_destroy) ([InputMethod_CursorInfo](#inputmethod_cursorinfo) \*cursorInfo) | Destroys an [InputMethod_CursorInfo](#inputmethod_cursorinfo) instance.| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_CursorInfo_SetRect](#oh_cursorinfo_setrect) ([InputMethod_CursorInfo](#inputmethod_cursorinfo) \*cursorInfo, double left, double top, double width, double height) | Sets the cursor information.| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_CursorInfo_GetRect](#oh_cursorinfo_getrect) ([InputMethod_CursorInfo](#inputmethod_cursorinfo) \*cursorInfo, double \*left, double \*top, double \*width, double \*height) | Obtains the cursor information.| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_InputMethodProxy_ShowKeyboard](#oh_inputmethodproxy_showkeyboard) ([InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) \*inputMethodProxy) | Displays the keyboard.| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_InputMethodProxy_HideKeyboard](#oh_inputmethodproxy_hidekeyboard) ([InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) \*inputMethodProxy) | Hides the keyboard.| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_InputMethodProxy_NotifySelectionChange](#oh_inputmethodproxy_notifyselectionchange) ([InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) \*inputMethodProxy, char16_t text[], size_t length, int start, int end) | Notifies the change of the text selection area in the text box.| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_InputMethodProxy_NotifyConfigurationChange](#oh_inputmethodproxy_notifyconfigurationchange) ([InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) \*inputMethodProxy, [InputMethod_EnterKeyType](#inputmethod_enterkeytype) enterKey, [InputMethod_TextInputType](#inputmethod_textinputtype) textType) | Notifies the change of the text box configuration.| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_InputMethodProxy_NotifyCursorUpdate](#oh_inputmethodproxy_notifycursorupdate) ([InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) \*inputMethodProxy, [InputMethod_CursorInfo](#inputmethod_cursorinfo) \*cursorInfo) | Notifies the cursor position change.| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_InputMethodProxy_SendPrivateCommand](#oh_inputmethodproxy_sendprivatecommand) ([InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) \*inputMethodProxy, [InputMethod_PrivateCommand](#inputmethod_privatecommand) \*privateCommand[], size_t size) | Sends a private data command.| 
| [InputMethod_PrivateCommand](#inputmethod_privatecommand) \* [OH_PrivateCommand_Create](#oh_privatecommand_create) (char key[], size_t keyLength) | Creates an [InputMethod_PrivateCommand](#inputmethod_privatecommand) instance.| 
| void [OH_PrivateCommand_Destroy](#oh_privatecommand_destroy) ([InputMethod_PrivateCommand](#inputmethod_privatecommand) \*command) | Destroys an [InputMethod_PrivateCommand](#inputmethod_privatecommand) instance.| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_PrivateCommand_SetKey](#oh_privatecommand_setkey) ([InputMethod_PrivateCommand](#inputmethod_privatecommand) \*command, char key[], size_t keyLength) | Sets the key value for [InputMethod_PrivateCommand](#inputmethod_privatecommand).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_PrivateCommand_SetBoolValue](#oh_privatecommand_setboolvalue) ([InputMethod_PrivateCommand](#inputmethod_privatecommand) \*command, bool value) | Sets the value of the Boolean type for [InputMethod_PrivateCommand](#inputmethod_privatecommand).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_PrivateCommand_SetIntValue](#oh_privatecommand_setintvalue) ([InputMethod_PrivateCommand](#inputmethod_privatecommand) \*command, int32_t value) | Sets the value of the integer type for [InputMethod_PrivateCommand](#inputmethod_privatecommand).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_PrivateCommand_SetStrValue](#oh_privatecommand_setstrvalue) ([InputMethod_PrivateCommand](#inputmethod_privatecommand) \*command, char value[], size_t valueLength) | Sets the value of the character string type for [InputMethod_PrivateCommand](#inputmethod_privatecommand).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_PrivateCommand_GetKey](#oh_privatecommand_getkey) ([InputMethod_PrivateCommand](#inputmethod_privatecommand) \*command, const char \*\*key, size_t \*keyLength) | Obtains the key value from [InputMethod_PrivateCommand](#inputmethod_privatecommand).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_PrivateCommand_GetValueType](#oh_privatecommand_getvaluetype) ([InputMethod_PrivateCommand](#inputmethod_privatecommand) \*command, [InputMethod_CommandValueType](#inputmethod_commandvaluetype) \*type) | Obtains the data type of **value** from [InputMethod_PrivateCommand](#inputmethod_privatecommand).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_PrivateCommand_GetBoolValue](#oh_privatecommand_getboolvalue) ([InputMethod_PrivateCommand](#inputmethod_privatecommand) \*command, bool \*value) | Obtains the value of the Boolean type from [InputMethod_PrivateCommand](#inputmethod_privatecommand).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_PrivateCommand_GetIntValue](#oh_privatecommand_getintvalue) ([InputMethod_PrivateCommand](#inputmethod_privatecommand) \*command, int32_t \*value) | Obtains the value of the integer type from [InputMethod_PrivateCommand](#inputmethod_privatecommand).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_PrivateCommand_GetStrValue](#oh_privatecommand_getstrvalue) ([InputMethod_PrivateCommand](#inputmethod_privatecommand) \*command, const char \*\*value, size_t \*valueLength) | Obtains the value of the character string type from [InputMethod_PrivateCommand](#inputmethod_privatecommand).| 
| [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) \* [OH_TextAvoidInfo_Create](#oh_textavoidinfo_create) (double positionY, double height) | Creates an [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) instance.| 
| void [OH_TextAvoidInfo_Destroy](#oh_textavoidinfo_destroy) ([InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) \*info) | Destroys an [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) instance.| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextAvoidInfo_SetPositionY](#oh_textavoidinfo_setpositiony) ([InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) \*info, double positionY) | Sets the Y coordinate in [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextAvoidInfo_SetHeight](#oh_textavoidinfo_setheight) ([InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) \*info, double height) | Sets the height in [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextAvoidInfo_GetPositionY](#oh_textavoidinfo_getpositiony) ([InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) \*info, double \*positionY) | Obtains the Y coordinate from [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextAvoidInfo_GetHeight](#oh_textavoidinfo_getheight) ([InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) \*info, double \*height) | Obtains the height from [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo).| 
| [InputMethod_TextConfig](#inputmethod_textconfig) \* [OH_TextConfig_Create](#oh_textconfig_create) () | Creates an [InputMethod_TextConfig](#inputmethod_textconfig) instance.| 
| void [OH_TextConfig_Destroy](#oh_textconfig_destroy) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config) | Destroys an [InputMethod_TextConfig](#inputmethod_textconfig) instance.| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_SetInputType](#oh_textconfig_setinputtype) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, [InputMethod_TextInputType](#inputmethod_textinputtype) inputType) | Sets the text box type for [InputMethod_TextConfig](#inputmethod_textconfig).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_SetEnterKeyType](#oh_textconfig_setenterkeytype) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, [InputMethod_EnterKeyType](#inputmethod_enterkeytype) enterKeyType) | Sets the Enter function type for [InputMethod_TextConfig](#inputmethod_textconfig).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_SetPreviewTextSupport](#oh_textconfig_setpreviewtextsupport) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, bool supported) | Sets the text preview feature for [InputMethod_TextConfig](#inputmethod_textconfig).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_SetSelection](#oh_textconfig_setselection) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, int32_t start, int32_t end) | Sets the selected text area for [InputMethod_TextConfig](#inputmethod_textconfig).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_SetWindowId](#oh_textconfig_setwindowid) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, int32_t windowId) | Sets the ID of the window to which [InputMethod_TextConfig](#inputmethod_textconfig) belongs.| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_GetInputType](#oh_textconfig_getinputtype) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, [InputMethod_TextInputType](#inputmethod_textinputtype) \*inputType) | Obtains the text box type of [InputMethod_TextConfig](#inputmethod_textconfig).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_GetEnterKeyType](#oh_textconfig_getenterkeytype) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, [InputMethod_EnterKeyType](#inputmethod_enterkeytype) \*enterKeyType) | Obtains the Enter function type of [InputMethod_TextConfig](#inputmethod_textconfig).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_IsPreviewTextSupported](#oh_textconfig_ispreviewtextsupported) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, bool \*supported) | Obtains the text preview settings of [InputMethod_TextConfig](#inputmethod_textconfig).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_GetCursorInfo](#oh_textconfig_getcursorinfo) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, [InputMethod_CursorInfo](#inputmethod_cursorinfo) \*\*cursorInfo) | Obtains the cursor information of [InputMethod_TextConfig](#inputmethod_textconfig).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_GetTextAvoidInfo](#oh_textconfig_gettextavoidinfo) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) \*\*avoidInfo) | Obtains the avoidance information of [InputMethod_TextConfig](#inputmethod_textconfig).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_GetSelection](#oh_textconfig_getselection) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, int32_t \*start, int32_t \*end) | Obtains the selected text area of [InputMethod_TextConfig](#inputmethod_textconfig).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextConfig_GetWindowId](#oh_textconfig_getwindowid) ([InputMethod_TextConfig](#inputmethod_textconfig) \*config, int32_t \*windowId) | Obtains the ID of the window to which [InputMethod_TextConfig](#inputmethod_textconfig) belongs.| 
| [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \* [OH_TextEditorProxy_Create](#oh_texteditorproxy_create) () | Creates an [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance.| 
| void [OH_TextEditorProxy_Destroy](#oh_texteditorproxy_destroy) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy) | Destroys an [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance.| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetGetTextConfigFunc](#oh_texteditorproxy_setgettextconfigfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc) getTextConfigFunc) | Sets the [OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetInsertTextFunc](#oh_texteditorproxy_setinserttextfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_InsertTextFunc](#oh_texteditorproxy_inserttextfunc) insertTextFunc) | Sets the [OH_TextEditorProxy_InsertTextFunc](#oh_texteditorproxy_inserttextfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetDeleteForwardFunc](#oh_texteditorproxy_setdeleteforwardfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_DeleteForwardFunc](#oh_texteditorproxy_deleteforwardfunc) deleteForwardFunc) | Sets the [OH_TextEditorProxy_DeleteForwardFunc](#oh_texteditorproxy_deleteforwardfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetDeleteBackwardFunc](#oh_texteditorproxy_setdeletebackwardfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_DeleteBackwardFunc](#oh_texteditorproxy_deletebackwardfunc) deleteBackwardFunc) | Sets the [OH_TextEditorProxy_DeleteBackwardFunc](#oh_texteditorproxy_deletebackwardfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetSendKeyboardStatusFunc](#oh_texteditorproxy_setsendkeyboardstatusfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_SendKeyboardStatusFunc](#oh_texteditorproxy_sendkeyboardstatusfunc) sendKeyboardStatusFunc) | Sets the [OH_TextEditorProxy_SendKeyboardStatusFunc](#oh_texteditorproxy_sendkeyboardstatusfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetSendEnterKeyFunc](#oh_texteditorproxy_setsendenterkeyfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_SendEnterKeyFunc](#oh_texteditorproxy_sendenterkeyfunc) sendEnterKeyFunc) | Sets the [OH_TextEditorProxy_SetSendEnterKeyFunc](#oh_texteditorproxy_setsendenterkeyfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetMoveCursorFunc](#oh_texteditorproxy_setmovecursorfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_MoveCursorFunc](#oh_texteditorproxy_movecursorfunc) moveCursorFunc) | Sets the [OH_TextEditorProxy_SetMoveCursorFunc](#oh_texteditorproxy_setmovecursorfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetHandleSetSelectionFunc](#oh_texteditorproxy_sethandlesetselectionfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_HandleSetSelectionFunc](#oh_texteditorproxy_handlesetselectionfunc) handleSetSelectionFunc) | Sets the [OH_TextEditorProxy_HandleSetSelectionFunc](#oh_texteditorproxy_handlesetselectionfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetHandleExtendActionFunc](#oh_texteditorproxy_sethandleextendactionfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_HandleExtendActionFunc](#oh_texteditorproxy_handleextendactionfunc) handleExtendActionFunc) | Sets the [OH_TextEditorProxy_HandleExtendActionFunc](#oh_texteditorproxy_handleextendactionfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetGetLeftTextOfCursorFunc](#oh_texteditorproxy_setgetlefttextofcursorfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_GetLeftTextOfCursorFunc](#oh_texteditorproxy_getlefttextofcursorfunc) getLeftTextOfCursorFunc) | Sets the [OH_TextEditorProxy_GetLeftTextOfCursorFunc](#oh_texteditorproxy_getlefttextofcursorfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetGetRightTextOfCursorFunc](#oh_texteditorproxy_setgetrighttextofcursorfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_GetRightTextOfCursorFunc](#oh_texteditorproxy_getrighttextofcursorfunc) getRightTextOfCursorFunc) | Sets the [OH_TextEditorProxy_GetRightTextOfCursorFunc](#oh_texteditorproxy_getrighttextofcursorfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetGetTextIndexAtCursorFunc](#oh_texteditorproxy_setgettextindexatcursorfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_GetTextIndexAtCursorFunc](#oh_texteditorproxy_gettextindexatcursorfunc) getTextIndexAtCursorFunc) | Sets the [OH_TextEditorProxy_GetTextIndexAtCursorFunc](#oh_texteditorproxy_gettextindexatcursorfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetReceivePrivateCommandFunc](#oh_texteditorproxy_setreceiveprivatecommandfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_ReceivePrivateCommandFunc](#oh_texteditorproxy_receiveprivatecommandfunc) receivePrivateCommandFunc) | Sets the [OH_TextEditorProxy_ReceivePrivateCommandFunc](#oh_texteditorproxy_receiveprivatecommandfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetSetPreviewTextFunc](#oh_texteditorproxy_setsetpreviewtextfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_SetPreviewTextFunc](#oh_texteditorproxy_setpreviewtextfunc) setPreviewTextFunc) | Sets the [OH_TextEditorProxy_SetPreviewTextFunc](#oh_texteditorproxy_setpreviewtextfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_SetFinishTextPreviewFunc](#oh_texteditorproxy_setfinishtextpreviewfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_FinishTextPreviewFunc](#oh_texteditorproxy_finishtextpreviewfunc) finishTextPreviewFunc) | Sets the [OH_TextEditorProxy_FinishTextPreviewFunc](#oh_texteditorproxy_finishtextpreviewfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetGetTextConfigFunc](#oh_texteditorproxy_getgettextconfigfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc) \*getTextConfigFunc) | Obtains the [OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetInsertTextFunc](#oh_texteditorproxy_getinserttextfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_InsertTextFunc](#oh_texteditorproxy_inserttextfunc) \*insertTextFunc) | Obtains the [OH_TextEditorProxy_InsertTextFunc](#oh_texteditorproxy_inserttextfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetDeleteForwardFunc](#oh_texteditorproxy_getdeleteforwardfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_DeleteForwardFunc](#oh_texteditorproxy_deleteforwardfunc) \*deleteForwardFunc) | Obtains the [OH_TextEditorProxy_DeleteForwardFunc](#oh_texteditorproxy_deleteforwardfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetDeleteBackwardFunc](#oh_texteditorproxy_getdeletebackwardfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_DeleteBackwardFunc](#oh_texteditorproxy_deletebackwardfunc) \*deleteBackwardFunc) | Obtains the [OH_TextEditorProxy_DeleteBackwardFunc](#oh_texteditorproxy_deletebackwardfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetSendKeyboardStatusFunc](#oh_texteditorproxy_getsendkeyboardstatusfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_SendKeyboardStatusFunc](#oh_texteditorproxy_sendkeyboardstatusfunc) \*sendKeyboardStatusFunc) | Obtains the [OH_TextEditorProxy_SendKeyboardStatusFunc](#oh_texteditorproxy_sendkeyboardstatusfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetSendEnterKeyFunc](#oh_texteditorproxy_getsendenterkeyfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_SendEnterKeyFunc](#oh_texteditorproxy_sendenterkeyfunc) \*sendEnterKeyFunc) | Obtains the [OH_TextEditorProxy_SendEnterKeyFunc](#oh_texteditorproxy_sendenterkeyfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetMoveCursorFunc](#oh_texteditorproxy_getmovecursorfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_MoveCursorFunc](#oh_texteditorproxy_movecursorfunc) \*moveCursorFunc) | Obtains the [OH_TextEditorProxy_MoveCursorFunc](#oh_texteditorproxy_movecursorfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetHandleSetSelectionFunc](#oh_texteditorproxy_gethandlesetselectionfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_HandleSetSelectionFunc](#oh_texteditorproxy_handlesetselectionfunc) \*handleSetSelectionFunc) | Obtains the [OH_TextEditorProxy_HandleSetSelectionFunc](#oh_texteditorproxy_handlesetselectionfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetHandleExtendActionFunc](#oh_texteditorproxy_gethandleextendactionfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_HandleExtendActionFunc](#oh_texteditorproxy_handleextendactionfunc) \*handleExtendActionFunc) | Obtains the [OH_TextEditorProxy_HandleExtendActionFunc](#oh_texteditorproxy_handleextendactionfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetGetLeftTextOfCursorFunc](#oh_texteditorproxy_getgetlefttextofcursorfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_GetLeftTextOfCursorFunc](#oh_texteditorproxy_getlefttextofcursorfunc) \*getLeftTextOfCursorFunc) | Obtains the [OH_TextEditorProxy_GetLeftTextOfCursorFunc](#oh_texteditorproxy_getlefttextofcursorfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetGetRightTextOfCursorFunc](#oh_texteditorproxy_getgetrighttextofcursorfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_GetRightTextOfCursorFunc](#oh_texteditorproxy_getrighttextofcursorfunc) \*getRightTextOfCursorFunc) | Obtains the [OH_TextEditorProxy_GetRightTextOfCursorFunc](#oh_texteditorproxy_getrighttextofcursorfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetGetTextIndexAtCursorFunc](#oh_texteditorproxy_getgettextindexatcursorfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_GetTextIndexAtCursorFunc](#oh_texteditorproxy_gettextindexatcursorfunc) \*getTextIndexAtCursorFunc) | Obtains the [OH_TextEditorProxy_GetTextIndexAtCursorFunc](#oh_texteditorproxy_gettextindexatcursorfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetReceivePrivateCommandFunc](#oh_texteditorproxy_getreceiveprivatecommandfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_ReceivePrivateCommandFunc](#oh_texteditorproxy_receiveprivatecommandfunc) \*receivePrivateCommandFunc) | Obtains the [OH_TextEditorProxy_ReceivePrivateCommandFunc](#oh_texteditorproxy_receiveprivatecommandfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetSetPreviewTextFunc](#oh_texteditorproxy_getsetpreviewtextfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_SetPreviewTextFunc](#oh_texteditorproxy_setpreviewtextfunc) \*setPreviewTextFunc) | Obtains the [OH_TextEditorProxy_SetPreviewTextFunc](#oh_texteditorproxy_setpreviewtextfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 
| [InputMethod_ErrorCode](#inputmethod_errorcode) [OH_TextEditorProxy_GetFinishTextPreviewFunc](#oh_texteditorproxy_getfinishtextpreviewfunc) ([InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) \*proxy, [OH_TextEditorProxy_FinishTextPreviewFunc](#oh_texteditorproxy_finishtextpreviewfunc) \*finishTextPreviewFunc) | Obtains the [OH_TextEditorProxy_FinishTextPreviewFunc](#oh_texteditorproxy_finishtextpreviewfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).| 


## Type Description


### InputMethod_AttachOptions

```
typedef struct InputMethod_AttachOptions InputMethod_AttachOptions
```

**Description**

Options carried when the input method is bound.

**Since**: 12


### InputMethod_CommandValueType

```
typedef enum InputMethod_CommandValueType InputMethod_CommandValueType
```

**Description**

Private data type.

**Since**: 12


### InputMethod_CursorInfo

```
typedef struct InputMethod_CursorInfo InputMethod_CursorInfo
```

**Description**

Coordinates, width, and height of the cursor.

**Since**: 12


### InputMethod_Direction

```
typedef enum InputMethod_Direction InputMethod_Direction
```

**Description**

Moving direction.

**Since**: 12


### InputMethod_EnterKeyType

```
typedef enum InputMethod_EnterKeyType InputMethod_EnterKeyType
```

**Description**

Enter function type.

**Since**: 12


### InputMethod_ErrorCode

```
typedef enum InputMethod_ErrorCode InputMethod_ErrorCode
```

**Description**

Error code of the input method.

**Since**: 12


### InputMethod_ExtendAction

```
typedef enum InputMethod_ExtendAction InputMethod_ExtendAction
```

**Description**

Type of the extended edit action on the text box.

**Since**: 12


### InputMethod_InputMethodProxy

```
typedef struct InputMethod_InputMethodProxy InputMethod_InputMethodProxy
```

**Description**

Input method proxy object.

This object can be used to call the method for using the input method.

**Since**: 12


### InputMethod_KeyboardStatus

```
typedef enum InputMethod_KeyboardStatus InputMethod_KeyboardStatus
```

**Description**

Keyboard status.

**Since**: 12


### InputMethod_PrivateCommand

```
typedef struct InputMethod_PrivateCommand InputMethod_PrivateCommand
```

**Description**

Private data.

It refers to the private data exchanged between the text box and the input method application.

**Since**: 12


### InputMethod_TextAvoidInfo

```
typedef struct InputMethod_TextAvoidInfo InputMethod_TextAvoidInfo
```

**Description**

Information of the text box used to avoid the keyboard.

**Since**: 12


### InputMethod_TextConfig

```
typedef struct InputMethod_TextConfig InputMethod_TextConfig
```

**Description**

Text box configuration.

**Since**: 12


### InputMethod_TextEditorProxy

```
typedef struct InputMethod_TextEditorProxy InputMethod_TextEditorProxy
```

**Description**

Text box proxy.

It provides methods for obtaining notifications and requests from the input method application.

**Since**: 12


### InputMethod_TextInputType

```
typedef enum InputMethod_TextInputType InputMethod_TextInputType
```

**Description**

Text input type.

**Since**: 12


### OH_TextEditorProxy_DeleteBackwardFunc

```
typedef void(* OH_TextEditorProxy_DeleteBackwardFunc) (InputMethod_TextEditorProxy *textEditorProxy, int32_t length)
```

**Description**

Function called when the input method deletes the text on the left of the cursor.

Implement this function, set it to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy), and register it using [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| length | Length of the characters to be deleted.| 


### OH_TextEditorProxy_DeleteForwardFunc

```
typedef void(* OH_TextEditorProxy_DeleteForwardFunc) (InputMethod_TextEditorProxy *textEditorProxy, int32_t length)
```

**Description**

Function called when the input method deletes the text on the right of the cursor.

Implement this function, set it to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy), and register it using [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| length | Length of the characters to be deleted.| 


### OH_TextEditorProxy_FinishTextPreviewFunc

```
typedef void(* OH_TextEditorProxy_FinishTextPreviewFunc) (InputMethod_TextEditorProxy *textEditorProxy)
```

**Description**

Function called when the input method ends the text preview feature.

Implement this function, set it to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy), and register it using [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 


### OH_TextEditorProxy_GetLeftTextOfCursorFunc

```
typedef void(* OH_TextEditorProxy_GetLeftTextOfCursorFunc) (InputMethod_TextEditorProxy *textEditorProxy, int32_t number, char16_t text[], size_t *length)
```

**Description**

Function called when the input method obtains the text on the left of the cursor.

Implement this function, set it to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy), and register it using [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| number | Length of the text to be obtained.| 
| text | Text content of a specified length on the left of the cursor. You need to assign a value to the text content in the function implementation.| 


### OH_TextEditorProxy_GetRightTextOfCursorFunc

```
typedef void(* OH_TextEditorProxy_GetRightTextOfCursorFunc) (InputMethod_TextEditorProxy *textEditorProxy, int32_t number, char16_t text[], size_t *length)
```

**Description**

Function called when the input method obtains the text on the right of the cursor.

Implement this function, set it to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy), and register it using [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| number | Length of the text to be obtained.| 
| text | Text content of a specified length on the right of the cursor. You need to assign a value to the text content in the function implementation.| 


### OH_TextEditorProxy_GetTextConfigFunc

```
typedef void(* OH_TextEditorProxy_GetTextConfigFunc) (InputMethod_TextEditorProxy *textEditorProxy, InputMethod_TextConfig *config)
```

**Description**

Function called when the input method obtains the text box configuration.

Implement this function, set it to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy), and register it using [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach).

**Since**: 12

**Parameters:**

| Name| Description| 
| -------- | -------- |
| textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| config | Text box configuration.| 


### OH_TextEditorProxy_GetTextIndexAtCursorFunc

```
typedef int32_t(* OH_TextEditorProxy_GetTextIndexAtCursorFunc) (InputMethod_TextEditorProxy *textEditorProxy)
```

**Description**

Function called when the input method obtains the index of the text where the cursor is located in the text box.

Implement this function, set it to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy), and register it using [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 

**Returns:**

Index of the text where the cursor is located.


### OH_TextEditorProxy_HandleExtendActionFunc

```
typedef void(* OH_TextEditorProxy_HandleExtendActionFunc) (InputMethod_TextEditorProxy *textEditorProxy, InputMethod_ExtendAction action)
```

**Description**

Function called when the input method sends an extended editing operation.

Implement this function, set it to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy), and register it using [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| action | Extended editing operation. For details, see [InputMethod_ExtendAction](#inputmethod_extendaction).| 


### OH_TextEditorProxy_HandleSetSelectionFunc

```
typedef void(* OH_TextEditorProxy_HandleSetSelectionFunc) (InputMethod_TextEditorProxy *textEditorProxy, int32_t start, int32_t end)
```

**Description**

Function called when the input method requests to select text.

Implement this function, set it to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy), and register it using [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| start | Start position of the selected text.| 
| end | End position of the selected text.| 


### OH_TextEditorProxy_InsertTextFunc

```
typedef void(* OH_TextEditorProxy_InsertTextFunc) (InputMethod_TextEditorProxy *textEditorProxy, const char16_t *text, size_t length)
```

**Description**

Function called when the input method application inserts text.

Implement this function, set it to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy), and register it using [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| text | Characters to be inserted.| 
| length | Length of the characters to be inserted.| 


### OH_TextEditorProxy_MoveCursorFunc

```
typedef void(* OH_TextEditorProxy_MoveCursorFunc) (InputMethod_TextEditorProxy *textEditorProxy, InputMethod_Direction direction)
```

**Description**

Function called when the cursor is moved in the input method.

Implement this function, set it to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy), and register it using [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| direction | Cursor moving direction. For details, see [InputMethod_Direction](#inputmethod_direction).| 


### OH_TextEditorProxy_ReceivePrivateCommandFunc

```
typedef int32_t(* OH_TextEditorProxy_ReceivePrivateCommandFunc) (InputMethod_TextEditorProxy *textEditorProxy, InputMethod_PrivateCommand *privateCommand[], size_t size)
```

**Description**

Function called when the input method application sends a private data command.

Implement this function, set it to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy), and register it using [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| privateCommand | Private data command.| 
| size | Size of the private data.| 

**Returns:**

Processing result of the private data command.


### OH_TextEditorProxy_SendEnterKeyFunc

```
typedef void(* OH_TextEditorProxy_SendEnterKeyFunc) (InputMethod_TextEditorProxy *textEditorProxy, InputMethod_EnterKeyType enterKeyType)
```

**Description**

Function called when the Enter key is pressed in the input method.

Implement this function, set it to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy), and register it using [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| enterKeyType | Enter key type. For details, see [InputMethod_EnterKeyType](#inputmethod_enterkeytype).| 


### OH_TextEditorProxy_SendKeyboardStatusFunc

```
typedef void(* OH_TextEditorProxy_SendKeyboardStatusFunc) (InputMethod_TextEditorProxy *textEditorProxy, InputMethod_KeyboardStatus keyboardStatus)
```

**Description**

Function called when the input method notifies the keyboard status.

Implement this function, set it to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy), and register it using [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| keyboardStatus | Keyboard status. For details, see [InputMethod_KeyboardStatus](#inputmethod_keyboardstatus).| 


### OH_TextEditorProxy_SetPreviewTextFunc

```
typedef int32_t(* OH_TextEditorProxy_SetPreviewTextFunc) (InputMethod_TextEditorProxy *textEditorProxy, const char16_t text[], size_t length, int32_t start, int32_t end)
```

**Description**

Function called when the input method sets the text preview feature.

Implement this function, set it to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy), and register it using [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| text | Text requested to be previewed.| 
| length | Length of the text to be previewed.| 
| start | Starting cursor position of the text to be previewed.| 
| end | Ending cursor position of the text to be previewed.| 

**Returns:**

Result of setting text preview.


## Enum Description


### InputMethod_CommandValueType

```
enum InputMethod_CommandValueType
```

**Description**

Private data type.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| IME_COMMAND_VALUE_TYPE_NONE | NONE.| 
| IME_COMMAND_VALUE_TYPE_STRING | String.| 
| IME_COMMAND_VALUE_TYPE_BOOL | Boolean.| 
| IME_COMMAND_VALUE_TYPE_INT32 | 32-bit signed integer.| 


### InputMethod_Direction

```
enum InputMethod_Direction
```

**Description**

Moving direction.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| IME_DIRECTION_NONE | NONE.| 
| IME_DIRECTION_UP | Upward.| 
| IME_DIRECTION_DOWN | Downward.| 
| IME_DIRECTION_LEFT | To the left.| 
| IME_DIRECTION_RIGHT | To the right.| 


### InputMethod_EnterKeyType

```
enum InputMethod_EnterKeyType
```

**Description**

Enter function type.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| IME_ENTER_KEY_UNSPECIFIED | Not specified.| 
| IME_ENTER_KEY_NONE | NONE.| 
| IME_ENTER_KEY_GO | Go.| 
| IME_ENTER_KEY_SEARCH | Search.| 
| IME_ENTER_KEY_SEND | Send.| 
| IME_ENTER_KEY_NEXT | Next.| 
| IME_ENTER_KEY_DONE | Done.| 
| IME_ENTER_KEY_PREVIOUS | Previous.| 
| IME_ENTER_KEY_NEWLINE | Line break.| 


### InputMethod_ErrorCode

```
enum InputMethod_ErrorCode
```

**Description**

Error code of the input method.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| IME_ERR_OK | Successful.| 
| IME_ERR_UNDEFINED | Query failed.| 
| IME_ERR_PARAMCHECK | Parameter check failed.| 
| IME_ERR_PACKAGEMANAGER | Package management error.| 
| IME_ERR_IMENGINE | Input method application error.| 
| IME_ERR_IMCLIENT | Text box client error.| 
| IME_ERR_CONFIG_PERSIST | Configuration persistence failed. This error code is reported when the configuration fails to be saved.| 
| IME_ERR_CONTROLLER | Input method controller error.| 
| IME_ERR_SETTINGS | Input method setter error.| 
| IME_ERR_IMMS | Input method manager service error.| 
| IME_ERR_DETACHED | Text box unbound.| 
| IME_ERR_NULL_POINTER | Null pointer.| 
| IME_ERR_QUERY_FAILED | Query failed.| 


### InputMethod_ExtendAction

```
enum InputMethod_ExtendAction
```

**Description**

Type of the extended edit action on the text box.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| IME_EXTEND_ACTION_SELECT_ALL | Select all.| 
| IME_EXTEND_ACTION_CUT | Cut.| 
| IME_EXTEND_ACTION_COPY | Copy.| 
| IME_EXTEND_ACTION_PASTE | Paste.| 


### InputMethod_KeyboardStatus

```
enum InputMethod_KeyboardStatus
```

**Description**

Keyboard status.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| IME_KEYBOARD_STATUS_NONE | NONE.| 
| IME_KEYBOARD_STATUS_HIDE | Invisible.| 
| IME_KEYBOARD_STATUS_SHOW | Visible.| 


### InputMethod_TextInputType

```
enum InputMethod_TextInputType
```

**Description**

Text input type.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| IME_TEXT_INPUT_TYPE_NONE | NONE.| 
| IME_TEXT_INPUT_TYPE_TEXT | Text.| 
| IME_TEXT_INPUT_TYPE_MULTILINE | Multi-line.| 
| IME_TEXT_INPUT_TYPE_NUMBER | Number.| 
| IME_TEXT_INPUT_TYPE_PHONE | Phone number.| 
| IME_TEXT_INPUT_TYPE_DATETIME | Date.| 
| IME_TEXT_INPUT_TYPE_EMAIL_ADDRESS | Email address.| 
| IME_TEXT_INPUT_TYPE_URL | URL.| 
| IME_TEXT_INPUT_TYPE_VISIBLE_PASSWORD | Password.| 
| IME_TEXT_INPUT_TYPE_NUMBER_PASSWORD | Numeric password.| 
| IME_TEXT_INPUT_TYPE_SCREEN_LOCK_PASSWORD | Lock screen password.| 
| IME_TEXT_INPUT_TYPE_USER_NAME | Username.| 
| IME_TEXT_INPUT_TYPE_NEW_PASSWORD | New password.| 
| IME_TEXT_INPUT_TYPE_NUMBER_DECIMAL | NUMBER DECIMAL. | 


## Function Description


### OH_AttachOptions_Create()

```
InputMethod_AttachOptions* OH_AttachOptions_Create (bool showKeyboard)
```

**Description**

Creates an [InputMethod_AttachOptions](#inputmethod_attachoptions) instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| showKeyboard | Indicates whether to display the keyboard.| 

**Returns:**

If the operation is successful, a pointer to the created [InputMethod_AttachOptions](#inputmethod_attachoptions) instance is returned. If the operation failed, **NULL** is returned, which may be caused by insufficient application address space.


### OH_AttachOptions_Destroy()

```
void OH_AttachOptions_Destroy (InputMethod_AttachOptions * options)
```

**Description**

Destroys an [InputMethod_AttachOptions](#inputmethod_attachoptions) instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | [InputMethod_AttachOptions](#inputmethod_attachoptions) instance to be destroyed.| 


### OH_AttachOptions_IsShowKeyboard()

```
InputMethod_ErrorCode OH_AttachOptions_IsShowKeyboard (InputMethod_AttachOptions * options, bool * showKeyboard )
```

**Description**

Obtains the configured value that indicates whether to display the keyboard from [InputMethod_AttachOptions](#inputmethod_attachoptions).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | [InputMethod_AttachOptions](#inputmethod_attachoptions) instance whose value is read.| 
| showKeyboard | Whether to display the keyboard during binding. **true**: The keyboard is displayed after the binding is complete. **false**: The keyboard is hidden after the binding is complete.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_CursorInfo_Create()

```
InputMethod_CursorInfo* OH_CursorInfo_Create (double left, double top, double width, double height )
```

**Description**

Creates an [InputMethod_CursorInfo](#inputmethod_cursorinfo) instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| left | Absolute value of the distance between the cursor's leftmost point and the left edge of the physical screen.| 
| top | Absolute value of the distance between the cursor's top vertex and the top edge of the physical screen.| 
| width | Width.| 
| height | Height.| 

**Returns:**

If the operation is successful, a pointer to the created [InputMethod_CursorInfo](#inputmethod_cursorinfo) instance is returned. If the operation failed, **NULL** is returned, which may be caused by insufficient application address space.


### OH_CursorInfo_Destroy()

```
void OH_CursorInfo_Destroy (InputMethod_CursorInfo * cursorInfo)
```

**Description**

Destroys an [InputMethod_CursorInfo](#inputmethod_cursorinfo) instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cursorInfo | Pointer to the [InputMethod_CursorInfo](#inputmethod_cursorinfo) instance to be destroyed.| 


### OH_CursorInfo_GetRect()

```
InputMethod_ErrorCode OH_CursorInfo_GetRect (InputMethod_CursorInfo * cursorInfo, double * left, double * top, double * width, double * height )
```

**Description**

Obtains the cursor information.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cursorInfo | Pointer to the [InputMethod_CursorInfo](#inputmethod_cursorinfo) instance.| 
| left | Absolute value of the distance between the cursor's leftmost point and the left edge of the physical screen.| 
| top | Absolute value of the distance between the cursor's top vertex and the top edge of the physical screen.| 
| width | Width.| 
| height | Height.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_CursorInfo_SetRect()

```
InputMethod_ErrorCode OH_CursorInfo_SetRect (InputMethod_CursorInfo * cursorInfo, double left, double top, double width, double height )
```

**Description**

Sets the cursor information.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cursorInfo | Pointer to the [InputMethod_CursorInfo](#inputmethod_cursorinfo) instance.| 
| left | Absolute value of the distance between the cursor's leftmost point and the left edge of the physical screen.| 
| top | Absolute value of the distance between the cursor's top vertex and the top edge of the physical screen.| 
| width | Width.| 
| height | Height.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_InputMethodController_Attach()

```
InputMethod_ErrorCode OH_InputMethodController_Attach (InputMethod_TextEditorProxy * textEditorProxy, InputMethod_AttachOptions * options, InputMethod_InputMethodProxy ** inputMethodProxy )
```

**Description**

Binds an application to the input method service.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance. The caller needs to manage the **textEditorProxy** lifespan. If the calling is successful, the caller cannot release **textEditorProxy** before the next binding or unbinding call.| 
| options | Pointer to the [InputMethod_AttachOptions](#inputmethod_attachoptions) instance, which is the option for binding.| 
| inputMethodProxy | Pointer to the [InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) instance. The lifespan is maintained until the next binding or unbinding call.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**IME_ERR_PARAMCHECK** indicates the parameter error.

**IME_ERR_IMCLIENT** indicates the input method client error.

**IME_ERR_IMMS** indicates the input method service error.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_InputMethodController_Detach()

```
InputMethod_ErrorCode OH_InputMethodController_Detach (InputMethod_InputMethodProxy * inputMethodProxy)
```

**Description**

Unbinds an application from the input method service.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| inputMethodProxy | Pointer to the [InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) instance. Call [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach) to obtain **inputMethodProxy**.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**IME_ERR_IMCLIENT** indicates the input method client error.

**IME_ERR_IMMS** indicates the input method service error.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_InputMethodProxy_HideKeyboard()

```
InputMethod_ErrorCode OH_InputMethodProxy_HideKeyboard (InputMethod_InputMethodProxy * inputMethodProxy)
```

**Description**

Hides the keyboard.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| inputMethodProxy | Pointer to the [InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) instance. Call [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach) to obtain **inputMethodProxy**.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**IME_ERR_IMCLIENT** indicates the input method client error.

**IME_ERR_IMMS** indicates the input method service error.

**IME_ERR_DETACHED** indicates that no input method is bound.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_InputMethodProxy_NotifyConfigurationChange()

```
InputMethod_ErrorCode OH_InputMethodProxy_NotifyConfigurationChange (InputMethod_InputMethodProxy * inputMethodProxy, InputMethod_EnterKeyType enterKey, InputMethod_TextInputType textType )
```

**Description**

Notifies the change of the text box configuration.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| inputMethodProxy | Pointer to the [InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) instance. Call [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach) to obtain **inputMethodProxy**.| 
| enterKey | Enter key type.| 
| textType | Text box type.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**IME_ERR_PARAMCHECK** indicates the parameter error.

**IME_ERR_IMCLIENT** indicates the input method client error.

**IME_ERR_IMMS** indicates the input method service error.

**IME_ERR_DETACHED** indicates that no input method is bound.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_InputMethodProxy_NotifyCursorUpdate()

```
InputMethod_ErrorCode OH_InputMethodProxy_NotifyCursorUpdate (InputMethod_InputMethodProxy * inputMethodProxy, InputMethod_CursorInfo * cursorInfo )
```

**Description**

Notifies the cursor position change.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| inputMethodProxy | Pointer to the [InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) instance. Call [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach) to obtain **inputMethodProxy**.| 
| cursorInfo | Pointer to the [InputMethod_CursorInfo](#inputmethod_cursorinfo) instance, indicating the cursor information.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**IME_ERR_PARAMCHECK** indicates the parameter error.

**IME_ERR_IMCLIENT** indicates the input method client error.

**IME_ERR_IMMS** indicates the input method service error.

**IME_ERR_DETACHED** indicates that no input method is bound.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_InputMethodProxy_NotifySelectionChange()

```
InputMethod_ErrorCode OH_InputMethodProxy_NotifySelectionChange (InputMethod_InputMethodProxy * inputMethodProxy, char16_t text[], size_t length, int start, int end )
```

**Description**

Notifies the change of the text selection area in the text box.

When the text content, the cursor position, or the selected text changes, this API is used to notify the input method application of the change.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| inputMethodProxy | Pointer to the [InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) instance. Call [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach) to obtain **inputMethodProxy**.| 
| text | All input text.| 
| length | Length of the **text** parameter. Maximum length: 8 KB.| 
| start | Start position of the selected text.| 
| end | End position of the selected text.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**IME_ERR_PARAMCHECK** indicates the parameter error.

**IME_ERR_IMCLIENT** indicates the input method client error.

**IME_ERR_IMMS** indicates the input method service error.

**IME_ERR_DETACHED** indicates that no input method is bound.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_InputMethodProxy_SendPrivateCommand()

```
InputMethod_ErrorCode OH_InputMethodProxy_SendPrivateCommand (InputMethod_InputMethodProxy * inputMethodProxy, InputMethod_PrivateCommand * privateCommand[], size_t size )
```

**Description**

Sends a private data command.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| inputMethodProxy | Pointer to the [InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) instance. Call [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach) to obtain **inputMethodProxy**.| 
| privateCommand | Private command, which is defined in [InputMethod_PrivateCommand](#inputmethod_privatecommand). The maximum size is 32 KB.| 
| size | Size of the private command. Maximum size: 5.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**IME_ERR_PARAMCHECK** indicates the parameter error.

**IME_ERR_IMCLIENT** indicates the input method client error.

**IME_ERR_IMMS** indicates the input method service error.

**IME_ERR_DETACHED** indicates that no input method is bound.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_InputMethodProxy_ShowKeyboard()

```
InputMethod_ErrorCode OH_InputMethodProxy_ShowKeyboard (InputMethod_InputMethodProxy * inputMethodProxy)
```

**Description**

Displays the keyboard.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| inputMethodProxy | Pointer to the [InputMethod_InputMethodProxy](#inputmethod_inputmethodproxy) instance. Call [OH_InputMethodController_Attach](#oh_inputmethodcontroller_attach) to obtain **inputMethodProxy**.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**IME_ERR_PARAMCHECK** indicates the parameter error.

**IME_ERR_IMCLIENT** indicates the input method client error.

**IME_ERR_IMMS** indicates the input method service error.

**IME_ERR_DETACHED** indicates that no input method is bound.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_PrivateCommand_Create()

```
InputMethod_PrivateCommand* OH_PrivateCommand_Create (char key[], size_t keyLength )
```

**Description**

Creates an [InputMethod_PrivateCommand](#inputmethod_privatecommand) instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| key | Key value of the private data.| 
| keyLength | Key length.| 

**Returns:**

If the operation is successful, a pointer to the created [InputMethod_PrivateCommand](#inputmethod_privatecommand) instance is returned. If the operation failed, **NULL** is returned, which may be caused by insufficient application address space.


### OH_PrivateCommand_Destroy()

```
void OH_PrivateCommand_Destroy (InputMethod_PrivateCommand * command)
```

**Description**

Destroys an [InputMethod_PrivateCommand](#inputmethod_privatecommand) instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| command | Pointer to the [InputMethod_PrivateCommand](#inputmethod_privatecommand) instance to be destroyed.| 


### OH_PrivateCommand_GetBoolValue()

```
InputMethod_ErrorCode OH_PrivateCommand_GetBoolValue (InputMethod_PrivateCommand * command, bool * value )
```

**Description**

Obtains the value of the Boolean type from [InputMethod_PrivateCommand](#inputmethod_privatecommand).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| command | Pointer to the [InputMethod_PrivateCommand](#inputmethod_privatecommand) instance whose value is to be obtained.| 
| value | Boolean value.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_PrivateCommand_GetIntValue()

```
InputMethod_ErrorCode OH_PrivateCommand_GetIntValue (InputMethod_PrivateCommand * command, int32_t * value )
```

**Description**

Obtains the value of the integer type from [InputMethod_PrivateCommand](#inputmethod_privatecommand).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| command | Pointer to the [InputMethod_PrivateCommand](#inputmethod_privatecommand) instance whose value is to be obtained.| 
| value | Value of the integer type.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_PrivateCommand_GetKey()

```
InputMethod_ErrorCode OH_PrivateCommand_GetKey (InputMethod_PrivateCommand * command, const char ** key, size_t * keyLength )
```

**Description**

Obtains the key value from [InputMethod_PrivateCommand](#inputmethod_privatecommand).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| command | Pointer to the [InputMethod_PrivateCommand](#inputmethod_privatecommand) instance whose key value is to be obtained.| 
| key | The lifespan of **key** is consistent with that of **command**. Do not directly save the key address or write **key**. You are advised to copy **key** and then use the copy.| 
| keyLength | Key length.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_PrivateCommand_GetStrValue()

```
InputMethod_ErrorCode OH_PrivateCommand_GetStrValue (InputMethod_PrivateCommand * command, const char ** value, size_t * valueLength )
```

**Description**

Obtains the value of the character string type from [InputMethod_PrivateCommand](#inputmethod_privatecommand).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| command | Pointer to the [InputMethod_PrivateCommand](#inputmethod_privatecommand) instance whose value is to be obtained.| 
| value | Value of the character string type.| 
| valueLength | The lifespan of **value** is consistent with that of **command**. Do not directly save the value address or directly write **value**. You are advised to copy **value** and then use the copy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_PrivateCommand_GetValueType()

```
InputMethod_ErrorCode OH_PrivateCommand_GetValueType (InputMethod_PrivateCommand * command, InputMethod_CommandValueType * type )
```

**Description**

Obtains the data type of **value** from [InputMethod_PrivateCommand](#inputmethod_privatecommand).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| command | Pointer to the [InputMethod_PrivateCommand](#inputmethod_privatecommand) instance whose value is to be obtained.| 
| type | Data type of **value**.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_PrivateCommand_SetBoolValue()

```
InputMethod_ErrorCode OH_PrivateCommand_SetBoolValue (InputMethod_PrivateCommand * command, bool value )
```

**Description**

Sets the value of the Boolean type for [InputMethod_PrivateCommand](#inputmethod_privatecommand).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| command | Pointer to the [InputMethod_PrivateCommand](#inputmethod_privatecommand) instance to be set.| 
| value | Boolean value.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_PrivateCommand_SetIntValue()

```
InputMethod_ErrorCode OH_PrivateCommand_SetIntValue (InputMethod_PrivateCommand * command, int32_t value )
```

**Description**

Sets the value of the integer type for [InputMethod_PrivateCommand](#inputmethod_privatecommand).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| command | Pointer to the [InputMethod_PrivateCommand](#inputmethod_privatecommand) instance to be set.| 
| value | Integer value.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_PrivateCommand_SetKey()

```
InputMethod_ErrorCode OH_PrivateCommand_SetKey (InputMethod_PrivateCommand * command, char key[], size_t keyLength )
```

**Description**

Sets the key value for [InputMethod_PrivateCommand](#inputmethod_privatecommand).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| command | Pointer to the [InputMethod_PrivateCommand](#inputmethod_privatecommand) instance to be set.| 
| key | Key value.| 
| keyLength | Key length.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_PrivateCommand_SetStrValue()

```
InputMethod_ErrorCode OH_PrivateCommand_SetStrValue (InputMethod_PrivateCommand * command, char value[], size_t valueLength )
```

**Description**

Sets the value of the character string type for [InputMethod_PrivateCommand](#inputmethod_privatecommand).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| command | Pointer to the [InputMethod_PrivateCommand](#inputmethod_privatecommand) instance to be set.| 
| value | Value of the character string type.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextAvoidInfo_Create()

```
InputMethod_TextAvoidInfo* OH_TextAvoidInfo_Create (double positionY, double height )
```

**Description**

Creates an [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| positionY | Y coordinate of the text box.| 
| height | Height of the text box.| 

**Returns:**

If the operation is successful, a pointer to the created [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) instance is returned. If the operation failed, **NULL** is returned, which may be caused by insufficient application address space.


### OH_TextAvoidInfo_Destroy()

```
void OH_TextAvoidInfo_Destroy (InputMethod_TextAvoidInfo * info)
```

**Description**

Destroys an [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to the [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) instance to be destroyed.| 


### OH_TextAvoidInfo_GetHeight()

```
InputMethod_ErrorCode OH_TextAvoidInfo_GetHeight (InputMethod_TextAvoidInfo * info, double * height )
```

**Description**

Obtains the height from [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to the [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) instance whose value is to be obtained.| 
| height | Height of the text box.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextAvoidInfo_GetPositionY()

```
InputMethod_ErrorCode OH_TextAvoidInfo_GetPositionY (InputMethod_TextAvoidInfo * info, double * positionY )
```

**Description**

Obtains the Y coordinate from [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to the [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) instance whose value is to be obtained.| 
| positionY | Absolute value of the distance between the text box's top vertex and the top edge of the physical screen.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextAvoidInfo_SetHeight()

```
InputMethod_ErrorCode OH_TextAvoidInfo_SetHeight (InputMethod_TextAvoidInfo * info, double height )
```

**Description**

Sets the height in [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to the [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) instance to be set.| 
| height | Height.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextAvoidInfo_SetPositionY()

```
InputMethod_ErrorCode OH_TextAvoidInfo_SetPositionY (InputMethod_TextAvoidInfo * info, double positionY )
```

**Description**

Sets the Y coordinate in [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to the [InputMethod_TextAvoidInfo](#inputmethod_textavoidinfo) instance to be set.| 
| positionY | Absolute value of the distance between the text box's top vertex and the top edge of the physical screen.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextConfig_Create()

```
InputMethod_TextConfig* OH_TextConfig_Create ()
```

**Description**

Creates an [InputMethod_TextConfig](#inputmethod_textconfig) instance.

**Since**: 12

**Returns:**

If the operation is successful, a pointer to the created [InputMethod_TextConfig](#inputmethod_textconfig) instance is returned. If the operation failed, **NULL** is returned, which may be caused by insufficient application address space.


### OH_TextConfig_Destroy()

```
void OH_TextConfig_Destroy (InputMethod_TextConfig * config)
```

**Description**

Destroys an [InputMethod_TextConfig](#inputmethod_textconfig) instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| config | Pointer to the [InputMethod_TextConfig](#inputmethod_textconfig) instance to be destroyed.| 


### OH_TextConfig_GetCursorInfo()

```
InputMethod_ErrorCode OH_TextConfig_GetCursorInfo (InputMethod_TextConfig * config, InputMethod_CursorInfo ** cursorInfo )
```

**Description**

Obtains the cursor information of [InputMethod_TextConfig](#inputmethod_textconfig).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| config | Pointer to the [InputMethod_TextConfig](#inputmethod_textconfig) instance whose value is to be obtained.| 
| cursorInfo | Cursor information.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextConfig_GetEnterKeyType()

```
InputMethod_ErrorCode OH_TextConfig_GetEnterKeyType (InputMethod_TextConfig * config, InputMethod_EnterKeyType * enterKeyType )
```

**Description**

Obtains the Enter function type of [InputMethod_TextConfig](#inputmethod_textconfig).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| config | Pointer to the [InputMethod_TextConfig](#inputmethod_textconfig) instance whose value is to be obtained.| 
| enterKeyType | Enter function type of the text box.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextConfig_GetInputType()

```
InputMethod_ErrorCode OH_TextConfig_GetInputType (InputMethod_TextConfig * config, InputMethod_TextInputType * inputType )
```

**Description**

Obtains the text box type of [InputMethod_TextConfig](#inputmethod_textconfig).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| config | Pointer to the [InputMethod_TextConfig](#inputmethod_textconfig) instance whose value is to be obtained.| 
| inputType | Input type of the text box.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextConfig_GetSelection()

```
InputMethod_ErrorCode OH_TextConfig_GetSelection (InputMethod_TextConfig * config, int32_t * start, int32_t * end )
```

**Description**

Obtains the selected text area of [InputMethod_TextConfig](#inputmethod_textconfig).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| config | Pointer to the [InputMethod_TextConfig](#inputmethod_textconfig) instance whose value is to be obtained.| 
| start | Start position of the selected text.| 
| end | End position of the selected text.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).

### OH_TextConfig_GetTextAvoidInfo()

```
InputMethod_ErrorCode OH_TextConfig_GetTextAvoidInfo (InputMethod_TextConfig * config, InputMethod_TextAvoidInfo ** avoidInfo )
```

**Description**

Obtains the avoidance information of [InputMethod_TextConfig](#inputmethod_textconfig).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| config | Pointer to the [InputMethod_TextConfig](#inputmethod_textconfig) instance whose value is to be obtained.| 
| avoidInfo | Text box avoidance information.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextConfig_GetWindowId()

```
InputMethod_ErrorCode OH_TextConfig_GetWindowId (InputMethod_TextConfig * config, int32_t * windowId )
```

**Description**

Obtains the ID of the window to which [InputMethod_TextConfig](#inputmethod_textconfig) belongs.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| config | Pointer to the [InputMethod_TextConfig](#inputmethod_textconfig) instance whose value is to be obtained.| 
| windowId | Window ID of the application bound to the input method.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextConfig_IsPreviewTextSupported()

```
InputMethod_ErrorCode OH_TextConfig_IsPreviewTextSupported (InputMethod_TextConfig * config, bool * supported )
```

**Description**

Obtains the text preview settings of [InputMethod_TextConfig](#inputmethod_textconfig).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| config | Pointer to the [InputMethod_TextConfig](#inputmethod_textconfig) instance whose value is to be obtained.| 
| supported | Whether text preview is supported.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextConfig_SetEnterKeyType()

```
InputMethod_ErrorCode OH_TextConfig_SetEnterKeyType (InputMethod_TextConfig * config, InputMethod_EnterKeyType enterKeyType )
```

**Description**

Sets the Enter function type for [InputMethod_TextConfig](#inputmethod_textconfig).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| config | Pointer to the [InputMethod_TextConfig](#inputmethod_textconfig) instance to be set.| 
| enterKeyType | Enter function type.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextConfig_SetInputType()

```
InputMethod_ErrorCode OH_TextConfig_SetInputType (InputMethod_TextConfig * config, InputMethod_TextInputType inputType )
```

**Description**

Sets the text box type for [InputMethod_TextConfig](#inputmethod_textconfig).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| config | Pointer to the [InputMethod_TextConfig](#inputmethod_textconfig) instance to be set.| 
| inputType | Input type of the text box.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextConfig_SetPreviewTextSupport()

```
InputMethod_ErrorCode OH_TextConfig_SetPreviewTextSupport (InputMethod_TextConfig * config, bool supported )
```

**Description**

Sets the text preview feature for [InputMethod_TextConfig](#inputmethod_textconfig).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| config | Pointer to the [InputMethod_TextConfig](#inputmethod_textconfig) instance to be set.| 
| supported | Whether text preview is supported.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextConfig_SetSelection()

```
InputMethod_ErrorCode OH_TextConfig_SetSelection (InputMethod_TextConfig * config, int32_t start, int32_t end )
```

**Description**

Sets the selected text area for [InputMethod_TextConfig](#inputmethod_textconfig).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| config | Pointer to the [InputMethod_TextConfig](#inputmethod_textconfig) instance to be set.| 
| start | Start position of the selected text.| 
| end | End position of the selected text.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextConfig_SetWindowId()

```
InputMethod_ErrorCode OH_TextConfig_SetWindowId (InputMethod_TextConfig * config, int32_t windowId )
```

**Description**

Sets the ID of the window to which [InputMethod_TextConfig](#inputmethod_textconfig) belongs.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| config | Pointer to the [InputMethod_TextConfig](#inputmethod_textconfig) instance to be set.| 
| windowId | Window ID of the application bound to the input method.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_Create()

```
InputMethod_TextEditorProxy* OH_TextEditorProxy_Create ()
```

**Description**

Creates an [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance.

**Since**: 12

**Returns:**

If the operation is successful, a pointer to the created [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance is returned. If the operation failed, **NULL** is returned, which may be caused by insufficient application address space.


### OH_TextEditorProxy_Destroy()

```
void OH_TextEditorProxy_Destroy (InputMethod_TextEditorProxy * proxy)
```

**Description**

Destroys an [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be destroyed.| 


### OH_TextEditorProxy_GetDeleteBackwardFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetDeleteBackwardFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_DeleteBackwardFunc * deleteBackwardFunc )
```

**Description**

Obtains the [OH_TextEditorProxy_DeleteBackwardFunc](#oh_texteditorproxy_deletebackwardfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be read.| 
| deleteBackwardFunc | Function [OH_TextEditorProxy_DeleteBackwardFunc](#oh_texteditorproxy_deletebackwardfunc) obtained from the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_GetDeleteForwardFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetDeleteForwardFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_DeleteForwardFunc * deleteForwardFunc )
```

**Description**

Obtains the [OH_TextEditorProxy_DeleteForwardFunc](#oh_texteditorproxy_deleteforwardfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be read.| 
| deleteForwardFunc | Function [OH_TextEditorProxy_DeleteForwardFunc](#oh_texteditorproxy_deleteforwardfunc) obtained from the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_GetFinishTextPreviewFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetFinishTextPreviewFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_FinishTextPreviewFunc * finishTextPreviewFunc )
```

**Description**

Obtains the [OH_TextEditorProxy_FinishTextPreviewFunc](#oh_texteditorproxy_finishtextpreviewfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be read.| 
| finishTextPreviewFunc | Function [OH_TextEditorProxy_FinishTextPreviewFunc](#oh_texteditorproxy_finishtextpreviewfunc) obtained from the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_GetGetLeftTextOfCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetGetLeftTextOfCursorFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_GetLeftTextOfCursorFunc * getLeftTextOfCursorFunc )
```

**Description**

Obtains the [OH_TextEditorProxy_GetLeftTextOfCursorFunc](#oh_texteditorproxy_getlefttextofcursorfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be read.| 
| getLeftTextOfCursorFunc | Function [OH_TextEditorProxy_GetLeftTextOfCursorFunc](#oh_texteditorproxy_getlefttextofcursorfunc) obtained from the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_GetGetRightTextOfCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetGetRightTextOfCursorFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_GetRightTextOfCursorFunc * getRightTextOfCursorFunc )
```

**Description**

Obtains the [OH_TextEditorProxy_GetRightTextOfCursorFunc](#oh_texteditorproxy_getrighttextofcursorfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be read.| 
| getRightTextOfCursorFunc | Function [OH_TextEditorProxy_GetRightTextOfCursorFunc](#oh_texteditorproxy_getrighttextofcursorfunc) obtained from the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_GetGetTextConfigFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetGetTextConfigFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_GetTextConfigFunc * getTextConfigFunc )
```

**Description**

Obtains the [OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be read.| 
| getTextConfigFunc | Function [OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc) obtained from the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_GetGetTextIndexAtCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetGetTextIndexAtCursorFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_GetTextIndexAtCursorFunc * getTextIndexAtCursorFunc )
```

**Description**

Obtains the [OH_TextEditorProxy_GetTextIndexAtCursorFunc](#oh_texteditorproxy_gettextindexatcursorfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be read.| 
| getTextIndexAtCursorFunc | Function [OH_TextEditorProxy_GetTextIndexAtCursorFunc](#oh_texteditorproxy_gettextindexatcursorfunc) obtained from the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_GetHandleExtendActionFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetHandleExtendActionFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_HandleExtendActionFunc * handleExtendActionFunc )
```

**Description**

Obtains the [OH_TextEditorProxy_HandleExtendActionFunc](#oh_texteditorproxy_handleextendactionfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be read.| 
| handleExtendActionFunc | Function [OH_TextEditorProxy_HandleExtendActionFunc](#oh_texteditorproxy_handleextendactionfunc) obtained from the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_GetHandleSetSelectionFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetHandleSetSelectionFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_HandleSetSelectionFunc * handleSetSelectionFunc )
```

**Description**

Obtains the [OH_TextEditorProxy_HandleSetSelectionFunc](#oh_texteditorproxy_handlesetselectionfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be read.| 
| handleSetSelectionFunc | Function [OH_TextEditorProxy_HandleSetSelectionFunc](#oh_texteditorproxy_handlesetselectionfunc) obtained from the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_GetInsertTextFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetInsertTextFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_InsertTextFunc * insertTextFunc )
```

**Description**

Obtains the [OH_TextEditorProxy_InsertTextFunc](#oh_texteditorproxy_inserttextfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be read.| 
| insertTextFunc | Function [OH_TextEditorProxy_InsertTextFunc](#oh_texteditorproxy_inserttextfunc) obtained from the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_GetMoveCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetMoveCursorFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_MoveCursorFunc * moveCursorFunc )
```

**Description**

Obtains the [OH_TextEditorProxy_MoveCursorFunc](#oh_texteditorproxy_movecursorfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be read.| 
| moveCursorFunc | Function [OH_TextEditorProxy_MoveCursorFunc](#oh_texteditorproxy_movecursorfunc) obtained from the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_GetReceivePrivateCommandFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetReceivePrivateCommandFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_ReceivePrivateCommandFunc * receivePrivateCommandFunc )
```

**Description**

Obtains the [OH_TextEditorProxy_ReceivePrivateCommandFunc](#oh_texteditorproxy_receiveprivatecommandfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be read.| 
| receivePrivateCommandFunc | Function [OH_TextEditorProxy_ReceivePrivateCommandFunc](#oh_texteditorproxy_receiveprivatecommandfunc) obtained from the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_GetSendEnterKeyFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetSendEnterKeyFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_SendEnterKeyFunc * sendEnterKeyFunc )
```

**Description**

Obtains the [OH_TextEditorProxy_SendEnterKeyFunc](#oh_texteditorproxy_sendenterkeyfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be read.| 
| sendEnterKeyFunc | Function [OH_TextEditorProxy_SendEnterKeyFunc](#oh_texteditorproxy_sendenterkeyfunc) obtained from the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_GetSendKeyboardStatusFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetSendKeyboardStatusFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_SendKeyboardStatusFunc * sendKeyboardStatusFunc )
```

**Description**

Obtains the [OH_TextEditorProxy_SendKeyboardStatusFunc](#oh_texteditorproxy_sendkeyboardstatusfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be read.| 
| sendKeyboardStatusFunc | Function [OH_TextEditorProxy_SendKeyboardStatusFunc](#oh_texteditorproxy_sendkeyboardstatusfunc) obtained from the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_GetSetPreviewTextFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetSetPreviewTextFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_SetPreviewTextFunc * setPreviewTextFunc )
```

**Description**

Obtains the [OH_TextEditorProxy_SetPreviewTextFunc](#oh_texteditorproxy_setpreviewtextfunc) function from [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be read.| 
| setPreviewTextFunc | Function [OH_TextEditorProxy_SetPreviewTextFunc](#oh_texteditorproxy_setpreviewtextfunc) obtained from the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_SetDeleteBackwardFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetDeleteBackwardFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_DeleteBackwardFunc deleteBackwardFunc )
```

**Description**

Sets the [OH_TextEditorProxy_DeleteBackwardFunc](#oh_texteditorproxy_deletebackwardfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| deleteBackwardFunc | Function [OH_TextEditorProxy_DeleteBackwardFunc](#oh_texteditorproxy_deletebackwardfunc) set to the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_SetDeleteForwardFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetDeleteForwardFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_DeleteForwardFunc deleteForwardFunc )
```

**Description**

Sets the [OH_TextEditorProxy_DeleteForwardFunc](#oh_texteditorproxy_deleteforwardfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| deleteForwardFunc | Function [OH_TextEditorProxy_DeleteForwardFunc](#oh_texteditorproxy_deleteforwardfunc) set to the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_SetFinishTextPreviewFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetFinishTextPreviewFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_FinishTextPreviewFunc finishTextPreviewFunc )
```

**Description**

Sets the [OH_TextEditorProxy_FinishTextPreviewFunc](#oh_texteditorproxy_finishtextpreviewfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| finishTextPreviewFunc | Function [OH_TextEditorProxy_FinishTextPreviewFunc](#oh_texteditorproxy_finishtextpreviewfunc) set to the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_SetGetLeftTextOfCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetGetLeftTextOfCursorFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_GetLeftTextOfCursorFunc getLeftTextOfCursorFunc )
```

**Description**

Sets the [OH_TextEditorProxy_GetLeftTextOfCursorFunc](#oh_texteditorproxy_getlefttextofcursorfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| getLeftTextOfCursorFunc | Function [OH_TextEditorProxy_GetLeftTextOfCursorFunc](#oh_texteditorproxy_getlefttextofcursorfunc) set to the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_SetGetRightTextOfCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetGetRightTextOfCursorFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_GetRightTextOfCursorFunc getRightTextOfCursorFunc )
```

**Description**

Sets the [OH_TextEditorProxy_GetRightTextOfCursorFunc](#oh_texteditorproxy_getrighttextofcursorfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| getRightTextOfCursorFunc | Function [OH_TextEditorProxy_GetRightTextOfCursorFunc](#oh_texteditorproxy_getrighttextofcursorfunc) set to the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_SetGetTextConfigFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetGetTextConfigFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_GetTextConfigFunc getTextConfigFunc )
```

**Description**

Sets the [OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| getTextConfigFunc | Function [OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc) set to the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_SetGetTextIndexAtCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetGetTextIndexAtCursorFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_GetTextIndexAtCursorFunc getTextIndexAtCursorFunc )
```

**Description**

Sets the [OH_TextEditorProxy_GetTextIndexAtCursorFunc](#oh_texteditorproxy_gettextindexatcursorfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| getTextIndexAtCursorFunc | Function [OH_TextEditorProxy_GetTextIndexAtCursorFunc](#oh_texteditorproxy_gettextindexatcursorfunc) set to the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_SetHandleExtendActionFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetHandleExtendActionFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_HandleExtendActionFunc handleExtendActionFunc )
```

**Description**

Sets the [OH_TextEditorProxy_HandleExtendActionFunc](#oh_texteditorproxy_handleextendactionfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| handleExtendActionFunc | Function [OH_TextEditorProxy_HandleExtendActionFunc](#oh_texteditorproxy_handleextendactionfunc) set to the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_SetHandleSetSelectionFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetHandleSetSelectionFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_HandleSetSelectionFunc handleSetSelectionFunc )
```

**Description**

Sets the [OH_TextEditorProxy_HandleSetSelectionFunc](#oh_texteditorproxy_handlesetselectionfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| handleSetSelectionFunc | Function [OH_TextEditorProxy_HandleSetSelectionFunc](#oh_texteditorproxy_handlesetselectionfunc) set to the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_SetInsertTextFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetInsertTextFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_InsertTextFunc insertTextFunc )
```

**Description**

Sets the [OH_TextEditorProxy_InsertTextFunc](#oh_texteditorproxy_inserttextfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| insertTextFunc | Function [OH_TextEditorProxy_InsertTextFunc](#oh_texteditorproxy_inserttextfunc) set to the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_SetMoveCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetMoveCursorFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_MoveCursorFunc moveCursorFunc )
```

**Description**

Sets the [OH_TextEditorProxy_SetMoveCursorFunc](#oh_texteditorproxy_setmovecursorfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| moveCursorFunc | Function [OH_TextEditorProxy_MoveCursorFunc](#oh_texteditorproxy_movecursorfunc) set to the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_SetReceivePrivateCommandFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetReceivePrivateCommandFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_ReceivePrivateCommandFunc receivePrivateCommandFunc )
```

**Description**

Sets the [OH_TextEditorProxy_ReceivePrivateCommandFunc](#oh_texteditorproxy_receiveprivatecommandfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| receivePrivateCommandFunc | Function [OH_TextEditorProxy_ReceivePrivateCommandFunc](#oh_texteditorproxy_receiveprivatecommandfunc) set to the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_SetSendEnterKeyFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetSendEnterKeyFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_SendEnterKeyFunc sendEnterKeyFunc )
```

**Description**

Sets the [OH_TextEditorProxy_SetSendEnterKeyFunc](#oh_texteditorproxy_setsendenterkeyfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| sendEnterKeyFunc | Function [OH_TextEditorProxy_SendEnterKeyFunc](#oh_texteditorproxy_sendenterkeyfunc) set to the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_SetSendKeyboardStatusFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetSendKeyboardStatusFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_SendKeyboardStatusFunc sendKeyboardStatusFunc )
```

**Description**

Sets the [OH_TextEditorProxy_SendKeyboardStatusFunc](#oh_texteditorproxy_sendkeyboardstatusfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| sendKeyboardStatusFunc | Function [OH_TextEditorProxy_SendKeyboardStatusFunc](#oh_texteditorproxy_sendkeyboardstatusfunc) set to the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).


### OH_TextEditorProxy_SetSetPreviewTextFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetSetPreviewTextFunc (InputMethod_TextEditorProxy * proxy, OH_TextEditorProxy_SetPreviewTextFunc setPreviewTextFunc )
```

**Description**

Sets the [OH_TextEditorProxy_SetPreviewTextFunc](#oh_texteditorproxy_setpreviewtextfunc) function to [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the [InputMethod_TextEditorProxy](#inputmethod_texteditorproxy) instance to be set.| 
| setPreviewTextFunc | Function [OH_TextEditorProxy_SetPreviewTextFunc](#oh_texteditorproxy_setpreviewtextfunc) set to the proxy.| 

**Returns:**

An error code.

**IME_ERR_OK** indicates the operation is successful.

**The IME_ERR_NULL_POINTER** indicates an unexpected null pointer.

For details about the error code, see [InputMethod_ErrorCode](#inputmethod_errorcode).
