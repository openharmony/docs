# inputmethod_text_editor_proxy_capi.h

## 概述

提供一套方法支持应用开发的自绘输入框获取来自输入法应用的通知和请求。

**引用文件：** <inputmethod/inputmethod_text_editor_proxy_capi.h>

**库：** libohinputmethod.so

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**起始版本：** 12

**相关模块：** [InputMethod](capi-inputmethod.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) | InputMethod_TextEditorProxy | 输入框代理。提供了获取来自输入法应用的通知和请求的方法。当输入法向编辑器发送请求或通知时，这些方法将被调用。 |

### 函数

| 名称 | typedef关键字 | 描述                                                                                                                                                                                                                                                                                                                                                                  |
| -- | -- |---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [typedef void (\*OH_TextEditorProxy_GetTextConfigFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_TextConfig *config)](#oh_texteditorproxy_gettextconfigfunc) | OH_TextEditorProxy_GetTextConfigFunc | 输入法获取输入框配置时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetGetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setgettextconfigfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。 |
| [typedef void (\*OH_TextEditorProxy_InsertTextFunc)(InputMethod_TextEditorProxy *textEditorProxy, const char16_t *text, size_t length)](#oh_texteditorproxy_inserttextfunc) | OH_TextEditorProxy_InsertTextFunc | 输入法应用插入文本时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetInsertTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setinserttextfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。                                                                         |
| [typedef void (\*OH_TextEditorProxy_DeleteForwardFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t length)](#oh_texteditorproxy_deleteforwardfunc) | OH_TextEditorProxy_DeleteForwardFunc | 输入法删除光标右侧文本时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetDeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setdeleteforwardfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。                                                                 |
| [typedef void (\*OH_TextEditorProxy_DeleteBackwardFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t length)](#oh_texteditorproxy_deletebackwardfunc) | OH_TextEditorProxy_DeleteBackwardFunc | 输入法删除光标左侧文本时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetDeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setdeleteforwardfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。                                                                 |
| [typedef void (\*OH_TextEditorProxy_SendKeyboardStatusFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_KeyboardStatus keyboardStatus)](#oh_texteditorproxy_sendkeyboardstatusfunc) | OH_TextEditorProxy_SendKeyboardStatusFunc | 输入法通知键盘状态时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetSendKeyboardStatusFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setsendkeyboardstatusfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。                                                         |
| [typedef void (\*OH_TextEditorProxy_SendEnterKeyFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_EnterKeyType enterKeyType)](#oh_texteditorproxy_sendenterkeyfunc) | OH_TextEditorProxy_SendEnterKeyFunc | 输入法发送回车键时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetSendEnterKeyFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setsendenterkeyfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。                                                                      |
| [typedef void (\*OH_TextEditorProxy_MoveCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_Direction direction)](#oh_texteditorproxy_movecursorfunc) | OH_TextEditorProxy_MoveCursorFunc | 输入法移动光标时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetMoveCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setmovecursorfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。                                                                           |
| [typedef void (\*OH_TextEditorProxy_HandleSetSelectionFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t start, int32_t end)](#oh_texteditorproxy_handlesetselectionfunc) | OH_TextEditorProxy_HandleSetSelectionFunc | 输入法请求选中文本时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetHandleSetSelectionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sethandlesetselectionfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。                                                         |
| [typedef void (\*OH_TextEditorProxy_HandleExtendActionFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_ExtendAction action)](#oh_texteditorproxy_handleextendactionfunc) | OH_TextEditorProxy_HandleExtendActionFunc | 输入法发送扩展编辑操作时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetHandleExtendActionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sethandleextendactionfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。                                                       |
| [typedef void (\*OH_TextEditorProxy_GetLeftTextOfCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t number, char16_t text[], size_t *length)](#oh_texteditorproxy_getlefttextofcursorfunc) | OH_TextEditorProxy_GetLeftTextOfCursorFunc | 输入法获取光标左侧文本时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetGetLeftTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setgetlefttextofcursorfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。                                                     |
| [typedef void (\*OH_TextEditorProxy_GetRightTextOfCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t number, char16_t text[], size_t *length)](#oh_texteditorproxy_getrighttextofcursorfunc) | OH_TextEditorProxy_GetRightTextOfCursorFunc | 输入法获取光标右侧文本时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetGetRightTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setgetrighttextofcursorfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。                                                   |
| [typedef int32_t (\*OH_TextEditorProxy_GetTextIndexAtCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy)](#oh_texteditorproxy_gettextindexatcursorfunc) | OH_TextEditorProxy_GetTextIndexAtCursorFunc | 输入法获取光标所在输入框文本索引时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetGetTextIndexAtCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setgettextindexatcursorfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。                                              |
| [typedef int32_t (\*OH_TextEditorProxy_ReceivePrivateCommandFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_PrivateCommand *privateCommand[], size_t size)](#oh_texteditorproxy_receiveprivatecommandfunc) | OH_TextEditorProxy_ReceivePrivateCommandFunc | 输入法应用发送私有数据命令时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setreceiveprivatecommandfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。                                               |
| [typedef int32_t (\*OH_TextEditorProxy_SetPreviewTextFunc)(InputMethod_TextEditorProxy *textEditorProxy, const char16_t text[], size_t length, int32_t start, int32_t end)](#oh_texteditorproxy_setpreviewtextfunc) | OH_TextEditorProxy_SetPreviewTextFunc | 输入法设置预上屏文本时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setreceiveprivatecommandfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。                                                  |
| [typedef void (\*OH_TextEditorProxy_FinishTextPreviewFunc)(InputMethod_TextEditorProxy *textEditorProxy)](#oh_texteditorproxy_finishtextpreviewfunc) | OH_TextEditorProxy_FinishTextPreviewFunc | 输入法结束预上屏时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setreceiveprivatecommandfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。                                                    |
| [InputMethod_TextEditorProxy *OH_TextEditorProxy_Create(void)](#oh_texteditorproxy_create) | - | 创建一个新的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例。                                                                                                                                                                                                                                                                                                                        |
| [void OH_TextEditorProxy_Destroy(InputMethod_TextEditorProxy *proxy)](#oh_texteditorproxy_destroy) | - | 销毁一个[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例。                                                                                                                                                                                                                                                                                                                          |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetGetTextConfigFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextConfigFunc getTextConfigFunc)](#oh_texteditorproxy_setgettextconfigfunc) | - | 将函数[OH_TextEditorProxy_GetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextconfigfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。                                                                                                                                                     |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetInsertTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_InsertTextFunc insertTextFunc)](#oh_texteditorproxy_setinserttextfunc) | - | 将函数[OH_TextEditorProxy_InsertTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_inserttextfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。                                                                                                                                                           |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetDeleteForwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteForwardFunc deleteForwardFunc)](#oh_texteditorproxy_setdeleteforwardfunc) | - | 将函数[OH_TextEditorProxy_DeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deleteforwardfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。                                                                                                                                                     |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetDeleteBackwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteBackwardFunc deleteBackwardFunc)](#oh_texteditorproxy_setdeletebackwardfunc) | - | 将函数[OH_TextEditorProxy_DeleteBackwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deletebackwardfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。                                                                                                                                                   |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetSendKeyboardStatusFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendKeyboardStatusFunc sendKeyboardStatusFunc)](#oh_texteditorproxy_setsendkeyboardstatusfunc) | - | 将函数[OH_TextEditorProxy_SendKeyboardStatusFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendkeyboardstatusfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。                                                                                                                                           |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetSendEnterKeyFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendEnterKeyFunc sendEnterKeyFunc)](#oh_texteditorproxy_setsendenterkeyfunc) | - | 将函数[OH_TextEditorProxy_SetSendEnterKeyFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setsendenterkeyfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。                                                                                                                                                 |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetMoveCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_MoveCursorFunc moveCursorFunc)](#oh_texteditorproxy_setmovecursorfunc) | - | 将函数[OH_TextEditorProxy_SetMoveCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setmovecursorfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。                                                                                                                                                     |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetHandleSetSelectionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleSetSelectionFunc handleSetSelectionFunc)](#oh_texteditorproxy_sethandlesetselectionfunc) | - | 将函数[OH_TextEditorProxy_HandleSetSelectionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handlesetselectionfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。                                                                                                                                           |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetHandleExtendActionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleExtendActionFunc handleExtendActionFunc)](#oh_texteditorproxy_sethandleextendactionfunc) | - | 将函数[OH_TextEditorProxy_HandleExtendActionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handleextendactionfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。                                                                                                                                           |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetGetLeftTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetLeftTextOfCursorFunc getLeftTextOfCursorFunc)](#oh_texteditorproxy_setgetlefttextofcursorfunc) | - | 将函数[OH_TextEditorProxy_GetLeftTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getlefttextofcursorfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。                                                                                                                                         |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetGetRightTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetRightTextOfCursorFunc getRightTextOfCursorFunc)](#oh_texteditorproxy_setgetrighttextofcursorfunc) | - | 将函数[OH_TextEditorProxy_GetRightTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getrighttextofcursorfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。                                                                                                                                       |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetGetTextIndexAtCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextIndexAtCursorFunc getTextIndexAtCursorFunc)](#oh_texteditorproxy_setgettextindexatcursorfunc) | - | 将函数[OH_TextEditorProxy_GetTextIndexAtCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextindexatcursorfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。                                                                                                                                       |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetReceivePrivateCommandFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_ReceivePrivateCommandFunc receivePrivateCommandFunc)](#oh_texteditorproxy_setreceiveprivatecommandfunc) | - | 将函数[OH_TextEditorProxy_ReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_receiveprivatecommandfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。                                                                                                                                     |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetSetPreviewTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SetPreviewTextFunc setPreviewTextFunc)](#oh_texteditorproxy_setsetpreviewtextfunc) | - | 将函数[OH_TextEditorProxy_SetPreviewTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setpreviewtextfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。                                                                                                                                                   |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetFinishTextPreviewFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_FinishTextPreviewFunc finishTextPreviewFunc)](#oh_texteditorproxy_setfinishtextpreviewfunc) | - | 将函数[OH_TextEditorProxy_FinishTextPreviewFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_finishtextpreviewfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。                                                                                                                                             |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetGetTextConfigFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextConfigFunc *getTextConfigFunc)](#oh_texteditorproxy_getgettextconfigfunc) | - | 从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_GetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextconfigfunc)函数。                                                                                                                                                      |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetInsertTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_InsertTextFunc *insertTextFunc)](#oh_texteditorproxy_getinserttextfunc) | - | 从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_InsertTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_inserttextfunc)函数。                                                                                                                                                            |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetDeleteForwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteForwardFunc *deleteForwardFunc)](#oh_texteditorproxy_getdeleteforwardfunc) | - | 从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_DeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deleteforwardfunc)函数。                                                                                                                                                      |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetDeleteBackwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteBackwardFunc *deleteBackwardFunc)](#oh_texteditorproxy_getdeletebackwardfunc) | - | 从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_DeleteBackwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deletebackwardfunc)函数。                                                                                                                                                    |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetSendKeyboardStatusFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendKeyboardStatusFunc *sendKeyboardStatusFunc)](#oh_texteditorproxy_getsendkeyboardstatusfunc) | - | 从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_SendKeyboardStatusFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendkeyboardstatusfunc)函数。                                                                                                                                            |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetSendEnterKeyFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendEnterKeyFunc *sendEnterKeyFunc)](#oh_texteditorproxy_getsendenterkeyfunc) | - | 从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_SendEnterKeyFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendenterkeyfunc)函数。                                                                                                                                                        |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetMoveCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_MoveCursorFunc *moveCursorFunc)](#oh_texteditorproxy_getmovecursorfunc) | - | 从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_MoveCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_movecursorfunc)函数。                                                                                                                                                            |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetHandleSetSelectionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleSetSelectionFunc *handleSetSelectionFunc)](#oh_texteditorproxy_gethandlesetselectionfunc) | - | 从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_HandleSetSelectionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handlesetselectionfunc)函数。                                                                                                                                            |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetHandleExtendActionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleExtendActionFunc *handleExtendActionFunc)](#oh_texteditorproxy_gethandleextendactionfunc) | - | 从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_HandleExtendActionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handleextendactionfunc)函数。                                                                                                                                            |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetGetLeftTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetLeftTextOfCursorFunc *getLeftTextOfCursorFunc)](#oh_texteditorproxy_getgetlefttextofcursorfunc) | - | 从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_GetLeftTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getlefttextofcursorfunc)函数。                                                                                                                                          |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetGetRightTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetRightTextOfCursorFunc *getRightTextOfCursorFunc)](#oh_texteditorproxy_getgetrighttextofcursorfunc) | - | 从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_GetRightTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getrighttextofcursorfunc)函数。                                                                                                                                        |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetGetTextIndexAtCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextIndexAtCursorFunc *getTextIndexAtCursorFunc)](#oh_texteditorproxy_getgettextindexatcursorfunc) | - | 从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_GetTextIndexAtCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextindexatcursorfunc)函数。                                                                                                                                        |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetReceivePrivateCommandFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_ReceivePrivateCommandFunc *receivePrivateCommandFunc)](#oh_texteditorproxy_getreceiveprivatecommandfunc) | - | 从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_ReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_receiveprivatecommandfunc)函数。                                                                                                                                      |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetSetPreviewTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SetPreviewTextFunc *setPreviewTextFunc)](#oh_texteditorproxy_getsetpreviewtextfunc) | - | 从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_SetPreviewTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setpreviewtextfunc)函数。                                                                                                                                                    |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetFinishTextPreviewFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_FinishTextPreviewFunc *finishTextPreviewFunc)](#oh_texteditorproxy_getfinishtextpreviewfunc) | - | 从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_FinishTextPreviewFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_finishtextpreviewfunc)函数。                                                                                                                                              |

## 函数说明

### OH_TextEditorProxy_GetTextConfigFunc()

```
typedef void (*OH_TextEditorProxy_GetTextConfigFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_TextConfig *config)
```

**描述**

输入法获取输入框配置时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetGetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setgettextconfigfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12


**参数：**

| 参数项                                                                                             | 描述 |
|-------------------------------------------------------------------------------------------------| -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config                                                              | 表示指向[InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md)实例的指针。 |

### OH_TextEditorProxy_InsertTextFunc()

```
typedef void (*OH_TextEditorProxy_InsertTextFunc)(InputMethod_TextEditorProxy *textEditorProxy, const char16_t *text, size_t length)
```

**描述**

输入法应用插入文本时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetInsertTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setinserttextfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。in. |
|  const char16_t *text | 插入的字符。 |
|  size_t length | 插入字符的长度。 |

### OH_TextEditorProxy_DeleteForwardFunc()

```
typedef void (*OH_TextEditorProxy_DeleteForwardFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t length)
```

**描述**

输入法删除光标右侧文本时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetDeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setdeleteforwardfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。in. |
|  int32_t length | 要删除字符的长度。 |

### OH_TextEditorProxy_DeleteBackwardFunc()

```
typedef void (*OH_TextEditorProxy_DeleteBackwardFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t length)
```

**描述**

输入法删除光标左侧文本时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetDeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setdeleteforwardfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。in. |
|  int32_t length | 要删除字符的长度。 |

### OH_TextEditorProxy_SendKeyboardStatusFunc()

```
typedef void (*OH_TextEditorProxy_SendKeyboardStatusFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_KeyboardStatus keyboardStatus)
```

**描述**

输入法通知键盘状态时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetSendKeyboardStatusFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setsendkeyboardstatusfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [ InputMethod_KeyboardStatus](capi-inputmethod-types-capi-h.md#inputmethod_keyboardstatus) keyboardStatus | 键盘状态，具体定义详见[InputMethod_KeyboardStatus](capi-inputmethod-types-capi-h.md#inputmethod_keyboardstatus)。 |

### OH_TextEditorProxy_SendEnterKeyFunc()

```
typedef void (*OH_TextEditorProxy_SendEnterKeyFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_EnterKeyType enterKeyType)
```

**描述**

输入法发送回车键时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetSendEnterKeyFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setsendenterkeyfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [ InputMethod_EnterKeyType](capi-inputmethod-types-capi-h.md#inputmethod_enterkeytype) enterKeyType | 回车键类型，具体定义详见[InputMethod_EnterKeyType](capi-inputmethod-types-capi-h.md#inputmethod_enterkeytype). |

### OH_TextEditorProxy_MoveCursorFunc()

```
typedef void (*OH_TextEditorProxy_MoveCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_Direction direction)
```

**描述**

输入法移动光标时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetMoveCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setmovecursorfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [ InputMethod_Direction](capi-inputmethod-types-capi-h.md#inputmethod_direction) direction | 光标移动方向，具体定义详见[InputMethod_Direction](capi-inputmethod-types-capi-h.md#inputmethod_direction). |

### OH_TextEditorProxy_HandleSetSelectionFunc()

```
typedef void (*OH_TextEditorProxy_HandleSetSelectionFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t start, int32_t end)
```

**描述**

输入法请求选中文本时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetHandleSetSelectionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sethandlesetselectionfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
|  int32_t start | 表示选中文本的起始位置。 |
|  int32_t end | 表示选中文本的结束位置。 |

### OH_TextEditorProxy_HandleExtendActionFunc()

```
typedef void (*OH_TextEditorProxy_HandleExtendActionFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_ExtendAction action)
```

**描述**

输入法发送扩展编辑操作时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetHandleExtendActionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sethandleextendactionfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [ InputMethod_ExtendAction](capi-inputmethod-types-capi-h.md#inputmethod_extendaction) action | 扩展编辑操作，具体定义详见[InputMethod_ExtendAction](capi-inputmethod-types-capi-h.md#inputmethod_extendaction). |

### OH_TextEditorProxy_GetLeftTextOfCursorFunc()

```
typedef void (*OH_TextEditorProxy_GetLeftTextOfCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t number, char16_t text[], size_t *length)
```

**描述**

输入法获取光标左侧文本时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetGetLeftTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setgetlefttextofcursorfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| int32_t number | 目标获取文本的长度。 |
| char16_t text[] | 光标左侧指定长度的文本内容，需要在函数实现中对它赋值。 |
| size_t *length | 表示游标左侧文本的长度，您需要传递此参数。 |

### OH_TextEditorProxy_GetRightTextOfCursorFunc()

```
typedef void (*OH_TextEditorProxy_GetRightTextOfCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t number, char16_t text[], size_t *length)
```

**描述**

输入法获取光标右侧文本时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetGetRightTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setgetrighttextofcursorfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
|  int32_t number | 目标获取文本的长度。 |
| char16_t text[] | 光标右侧指定长度的文本内容，需要在函数实现中对它赋值。 |
|  size_t *length | 表示游标左侧文本的长度。 |

### OH_TextEditorProxy_GetTextIndexAtCursorFunc()

```
typedef int32_t (*OH_TextEditorProxy_GetTextIndexAtCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy)
```

**描述**

输入法获取光标所在输入框文本索引时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetGetTextIndexAtCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setgettextindexatcursorfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回光标所在输入框文本索引。 |

### OH_TextEditorProxy_ReceivePrivateCommandFunc()

```
typedef int32_t (*OH_TextEditorProxy_ReceivePrivateCommandFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_PrivateCommand *privateCommand[], size_t size)
```

**描述**

输入法应用发送私有数据命令时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setreceiveprivatecommandfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12


**参数：**

| 参数项                                                                                             | 描述 |
|-------------------------------------------------------------------------------------------------| -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *privateCommand[]                                                | 私有数据命令。 |
| size_t size                                                                                     | 私有数据的大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t  | 返回对私有数据命令处理的处理结果。 |

### OH_TextEditorProxy_SetPreviewTextFunc()

```
typedef int32_t (*OH_TextEditorProxy_SetPreviewTextFunc)(InputMethod_TextEditorProxy *textEditorProxy, const char16_t text[], size_t length, int32_t start, int32_t end)
```

**描述**

输入法设置预上屏文本时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setreceiveprivatecommandfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| const char16_t text[] | 请求设置为预上屏样式的文本内容。 |
|  size_t length | 预上屏文本长度。 |
|  int32_t start | 预上屏文本起始光标位置。 |
|  int32_t end | 预上屏文本结束光标位置。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t  | 返回设置预上屏文本的处理结果。 |

### OH_TextEditorProxy_FinishTextPreviewFunc()

```
typedef void (*OH_TextEditorProxy_FinishTextPreviewFunc)(InputMethod_TextEditorProxy *textEditorProxy)
```

**描述**

输入法结束预上屏时触发的函数。您需要实现此函数，通过 [OH_TextEditorProxy_SetReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setreceiveprivatecommandfunc) 将它设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中， 并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |

### OH_TextEditorProxy_Create()

```
InputMethod_TextEditorProxy *OH_TextEditorProxy_Create(void)
```

**描述**

创建一个新的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例。

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) * | 如果创建成功，返回一个指向新创建的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。<br> 如果创建失败，对象返回NULL，可能的失败原因有应用地址空间满。 |

### OH_TextEditorProxy_Destroy()

```
void OH_TextEditorProxy_Destroy(InputMethod_TextEditorProxy *proxy)
```

**描述**

销毁一个[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 表示指向即将被销毁的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |

### OH_TextEditorProxy_SetGetTextConfigFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetGetTextConfigFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextConfigFunc getTextConfigFunc)
```

**描述**

将函数[OH_TextEditorProxy_GetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextconfigfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_GetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextconfigfunc) getTextConfigFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_GetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextconfigfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetInsertTextFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetInsertTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_InsertTextFunc insertTextFunc)
```

**描述**

将函数[OH_TextEditorProxy_InsertTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_inserttextfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_InsertTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_inserttextfunc) insertTextFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_InsertTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_inserttextfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetDeleteForwardFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetDeleteForwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteForwardFunc deleteForwardFunc)
```

**描述**

将函数[OH_TextEditorProxy_DeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deleteforwardfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_DeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deleteforwardfunc) deleteForwardFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_DeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deleteforwardfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetDeleteBackwardFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetDeleteBackwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteBackwardFunc deleteBackwardFunc)
```

**描述**

将函数[OH_TextEditorProxy_DeleteBackwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deletebackwardfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_DeleteBackwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deletebackwardfunc) deleteBackwardFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_DeleteBackwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deletebackwardfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetSendKeyboardStatusFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetSendKeyboardStatusFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendKeyboardStatusFunc sendKeyboardStatusFunc)
```

**描述**

将函数[OH_TextEditorProxy_SendKeyboardStatusFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendkeyboardstatusfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_SendKeyboardStatusFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendkeyboardstatusfunc) sendKeyboardStatusFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_SendKeyboardStatusFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendkeyboardstatusfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetSendEnterKeyFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetSendEnterKeyFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendEnterKeyFunc sendEnterKeyFunc)
```

**描述**

将函数[OH_TextEditorProxy_SetSendEnterKeyFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setsendenterkeyfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_SendEnterKeyFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendenterkeyfunc) sendEnterKeyFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_SendEnterKeyFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendenterkeyfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetMoveCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetMoveCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_MoveCursorFunc moveCursorFunc)
```

**描述**

将函数[OH_TextEditorProxy_SetMoveCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setmovecursorfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_MoveCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_movecursorfunc) moveCursorFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_MoveCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_movecursorfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetHandleSetSelectionFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetHandleSetSelectionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleSetSelectionFunc handleSetSelectionFunc)
```

**描述**

将函数[OH_TextEditorProxy_HandleSetSelectionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handlesetselectionfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_HandleSetSelectionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handlesetselectionfunc) handleSetSelectionFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_HandleSetSelectionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handlesetselectionfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetHandleExtendActionFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetHandleExtendActionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleExtendActionFunc handleExtendActionFunc)
```

**描述**

将函数[OH_TextEditorProxy_HandleExtendActionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handleextendactionfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_HandleExtendActionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handleextendactionfunc) handleExtendActionFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_HandleExtendActionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handleextendactionfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetGetLeftTextOfCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetGetLeftTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetLeftTextOfCursorFunc getLeftTextOfCursorFunc)
```

**描述**

将函数[OH_TextEditorProxy_GetLeftTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getlefttextofcursorfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_GetLeftTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getlefttextofcursorfunc) getLeftTextOfCursorFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_GetLeftTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getlefttextofcursorfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetGetRightTextOfCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetGetRightTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetRightTextOfCursorFunc getRightTextOfCursorFunc)
```

**描述**

将函数[OH_TextEditorProxy_GetRightTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getrighttextofcursorfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_GetRightTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getrighttextofcursorfunc) getRightTextOfCursorFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_GetRightTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getrighttextofcursorfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetGetTextIndexAtCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetGetTextIndexAtCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextIndexAtCursorFunc getTextIndexAtCursorFunc)
```

**描述**

将函数[OH_TextEditorProxy_GetTextIndexAtCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextindexatcursorfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_GetTextIndexAtCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextindexatcursorfunc) getTextIndexAtCursorFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_GetTextIndexAtCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextindexatcursorfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetReceivePrivateCommandFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetReceivePrivateCommandFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_ReceivePrivateCommandFunc receivePrivateCommandFunc)
```

**描述**

将函数[OH_TextEditorProxy_ReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_receiveprivatecommandfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_ReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_receiveprivatecommandfunc) receivePrivateCommandFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_ReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_receiveprivatecommandfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetSetPreviewTextFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetSetPreviewTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SetPreviewTextFunc setPreviewTextFunc)
```

**描述**

将函数[OH_TextEditorProxy_SetPreviewTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setpreviewtextfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_SetPreviewTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setpreviewtextfunc) setPreviewTextFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_SetPreviewTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setpreviewtextfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetFinishTextPreviewFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetFinishTextPreviewFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_FinishTextPreviewFunc finishTextPreviewFunc)
```

**描述**

将函数[OH_TextEditorProxy_FinishTextPreviewFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_finishtextpreviewfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_FinishTextPreviewFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_finishtextpreviewfunc) finishTextPreviewFunc | 表示被设置到proxy的函数[OH_TextEditorProxy_FinishTextPreviewFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_finishtextpreviewfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetGetTextConfigFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetGetTextConfigFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextConfigFunc *getTextConfigFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_GetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextconfigfunc)函数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向被读取的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_GetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextconfigfunc) *getTextConfigFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_GetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextconfigfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetInsertTextFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetInsertTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_InsertTextFunc *insertTextFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_InsertTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_inserttextfunc)函数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向被读取的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_InsertTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_inserttextfunc) *insertTextFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_InsertTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_inserttextfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetDeleteForwardFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetDeleteForwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteForwardFunc *deleteForwardFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_DeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deleteforwardfunc)函数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向被读取的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_DeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deleteforwardfunc) *deleteForwardFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_DeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deleteforwardfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetDeleteBackwardFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetDeleteBackwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteBackwardFunc *deleteBackwardFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_DeleteBackwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deletebackwardfunc)函数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向被读取的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_DeleteBackwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deletebackwardfunc) *deleteBackwardFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_DeleteBackwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deletebackwardfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetSendKeyboardStatusFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetSendKeyboardStatusFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendKeyboardStatusFunc *sendKeyboardStatusFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_SendKeyboardStatusFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendkeyboardstatusfunc)函数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向被读取的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_SendKeyboardStatusFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendkeyboardstatusfunc) *sendKeyboardStatusFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_SendKeyboardStatusFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendkeyboardstatusfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetSendEnterKeyFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetSendEnterKeyFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendEnterKeyFunc *sendEnterKeyFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_SendEnterKeyFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendenterkeyfunc)函数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向被读取的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_SendEnterKeyFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendenterkeyfunc) *sendEnterKeyFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_SendEnterKeyFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendenterkeyfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetMoveCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetMoveCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_MoveCursorFunc *moveCursorFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_MoveCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_movecursorfunc)函数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向被读取的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_MoveCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_movecursorfunc) *moveCursorFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_MoveCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_movecursorfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetHandleSetSelectionFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetHandleSetSelectionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleSetSelectionFunc *handleSetSelectionFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_HandleSetSelectionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handlesetselectionfunc)函数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向被读取的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_HandleSetSelectionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handlesetselectionfunc) *handleSetSelectionFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_HandleSetSelectionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handlesetselectionfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetHandleExtendActionFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetHandleExtendActionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleExtendActionFunc *handleExtendActionFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_HandleExtendActionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handleextendactionfunc)函数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向被读取的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_HandleExtendActionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handleextendactionfunc) *handleExtendActionFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_HandleExtendActionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handleextendactionfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetGetLeftTextOfCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetGetLeftTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetLeftTextOfCursorFunc *getLeftTextOfCursorFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_GetLeftTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getlefttextofcursorfunc)函数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向被读取的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_GetLeftTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getlefttextofcursorfunc) *getLeftTextOfCursorFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_GetLeftTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getlefttextofcursorfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetGetRightTextOfCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetGetRightTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetRightTextOfCursorFunc *getRightTextOfCursorFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_GetRightTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getrighttextofcursorfunc)函数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向被读取的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_GetRightTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getrighttextofcursorfunc) *getRightTextOfCursorFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_GetRightTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getrighttextofcursorfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetGetTextIndexAtCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetGetTextIndexAtCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextIndexAtCursorFunc *getTextIndexAtCursorFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_GetTextIndexAtCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextindexatcursorfunc)函数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向被读取的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_GetTextIndexAtCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextindexatcursorfunc) *getTextIndexAtCursorFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_GetTextIndexAtCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextindexatcursorfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetReceivePrivateCommandFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetReceivePrivateCommandFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_ReceivePrivateCommandFunc *receivePrivateCommandFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_ReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_receiveprivatecommandfunc)函数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向被读取的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_ReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_receiveprivatecommandfunc) *receivePrivateCommandFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_ReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_receiveprivatecommandfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetSetPreviewTextFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetSetPreviewTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SetPreviewTextFunc *setPreviewTextFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_SetPreviewTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setpreviewtextfunc)函数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向被读取的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_SetPreviewTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setpreviewtextfunc) *setPreviewTextFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_SetPreviewTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setpreviewtextfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetFinishTextPreviewFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetFinishTextPreviewFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_FinishTextPreviewFunc *finishTextPreviewFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_FinishTextPreviewFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_finishtextpreviewfunc)函数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 指向被读取的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。 |
| [OH_TextEditorProxy_FinishTextPreviewFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_finishtextpreviewfunc) *finishTextPreviewFunc | 表示从proxy获取到的函数[OH_TextEditorProxy_FinishTextPreviewFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_finishtextpreviewfunc)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |


