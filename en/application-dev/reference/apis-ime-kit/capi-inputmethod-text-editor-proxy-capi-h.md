# inputmethod_text_editor_proxy_capi.h
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @illybyy-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy1984-->
<!--Adviser: @zhang_yixin13-->

## Overview

Provides a set of methods for the custom text box developed by the application to obtain notifications and requests from the input method application.

**File to include**: <inputmethod/inputmethod_text_editor_proxy_capi.h>

**Library**: libohinputmethod.so

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Since**: 12

**Related module**: [InputMethod](capi-inputmethod.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) | InputMethod_TextEditorProxy | Represents the text box proxy. It provides methods for obtaining notifications and requests from the input method application.  |

### Function

| Name| typedef Keyword| Description                                                                                                                                                                                                                                                                                                                                                                 |
| -- | -- |---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [typedef void (\*OH_TextEditorProxy_GetTextConfigFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_TextConfig *config)](#oh_texteditorproxy_gettextconfigfunc) | OH_TextEditorProxy_GetTextConfigFunc | Function called when the input method obtains the text box configuration. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetGetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setgettextconfigfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).|
| [typedef void (\*OH_TextEditorProxy_InsertTextFunc)(InputMethod_TextEditorProxy *textEditorProxy, const char16_t *text, size_t length)](#oh_texteditorproxy_inserttextfunc) | OH_TextEditorProxy_InsertTextFunc | Function called when the input method application inserts text. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetInsertTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setinserttextfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).                                                                        |
| [typedef void (\*OH_TextEditorProxy_DeleteForwardFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t length)](#oh_texteditorproxy_deleteforwardfunc) | OH_TextEditorProxy_DeleteForwardFunc | Function called when the input method deletes the text on the right of the cursor. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetDeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setdeleteforwardfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).                                                                |
| [typedef void (\*OH_TextEditorProxy_DeleteBackwardFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t length)](#oh_texteditorproxy_deletebackwardfunc) | OH_TextEditorProxy_DeleteBackwardFunc | Function called when the input method deletes the text on the left of the cursor. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetDeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setdeleteforwardfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).                                                                |
| [typedef void (\*OH_TextEditorProxy_SendKeyboardStatusFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_KeyboardStatus keyboardStatus)](#oh_texteditorproxy_sendkeyboardstatusfunc) | OH_TextEditorProxy_SendKeyboardStatusFunc | Function called when the input method notifies the keyboard status. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetSendKeyboardStatusFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setsendkeyboardstatusfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).                                                        |
| [typedef void (\*OH_TextEditorProxy_SendEnterKeyFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_EnterKeyType enterKeyType)](#oh_texteditorproxy_sendenterkeyfunc) | OH_TextEditorProxy_SendEnterKeyFunc | Function called when the Enter key is pressed in the input method. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetSendEnterKeyFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setsendenterkeyfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).                                                                     |
| [typedef void (\*OH_TextEditorProxy_MoveCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_Direction direction)](#oh_texteditorproxy_movecursorfunc) | OH_TextEditorProxy_MoveCursorFunc | Function called when the cursor is moved in the input method. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetMoveCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setmovecursorfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).                                                                          |
| [typedef void (\*OH_TextEditorProxy_HandleSetSelectionFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t start, int32_t end)](#oh_texteditorproxy_handlesetselectionfunc) | OH_TextEditorProxy_HandleSetSelectionFunc | Function called when the input method requests to select text. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetHandleSetSelectionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sethandlesetselectionfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).                                                        |
| [typedef void (\*OH_TextEditorProxy_HandleExtendActionFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_ExtendAction action)](#oh_texteditorproxy_handleextendactionfunc) | OH_TextEditorProxy_HandleExtendActionFunc | Function called when the input method sends an extended editing operation. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetHandleExtendActionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sethandleextendactionfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).                                                      |
| [typedef void (\*OH_TextEditorProxy_GetLeftTextOfCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t number, char16_t text[], size_t *length)](#oh_texteditorproxy_getlefttextofcursorfunc) | OH_TextEditorProxy_GetLeftTextOfCursorFunc | Function called when the input method obtains the text on the left of the cursor. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetGetLeftTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setgetlefttextofcursorfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).                                                    |
| [typedef void (\*OH_TextEditorProxy_GetRightTextOfCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t number, char16_t text[], size_t *length)](#oh_texteditorproxy_getrighttextofcursorfunc) | OH_TextEditorProxy_GetRightTextOfCursorFunc | Function called when the input method obtains the text on the right of the cursor. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetGetRightTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setgetrighttextofcursorfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).                                                  |
| [typedef int32_t (\*OH_TextEditorProxy_GetTextIndexAtCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy)](#oh_texteditorproxy_gettextindexatcursorfunc) | OH_TextEditorProxy_GetTextIndexAtCursorFunc | Function called when the input method obtains the index of the text where the cursor is located in the text box. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetGetTextIndexAtCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setgettextindexatcursorfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).                                             |
| [typedef int32_t (\*OH_TextEditorProxy_ReceivePrivateCommandFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_PrivateCommand *privateCommand[], size_t size)](#oh_texteditorproxy_receiveprivatecommandfunc) | OH_TextEditorProxy_ReceivePrivateCommandFunc | Function called when the input method application sends a private data command. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setreceiveprivatecommandfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).                                              |
| [typedef int32_t (\*OH_TextEditorProxy_SetPreviewTextFunc)(InputMethod_TextEditorProxy *textEditorProxy, const char16_t text[], size_t length, int32_t start, int32_t end)](#oh_texteditorproxy_setpreviewtextfunc) | OH_TextEditorProxy_SetPreviewTextFunc | Function called when the input method sets the text preview feature. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setreceiveprivatecommandfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).                                                 |
| [typedef void (\*OH_TextEditorProxy_FinishTextPreviewFunc)(InputMethod_TextEditorProxy *textEditorProxy)](#oh_texteditorproxy_finishtextpreviewfunc) | OH_TextEditorProxy_FinishTextPreviewFunc | Function called when the input method ends the text preview feature. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setreceiveprivatecommandfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).                                                   |
| [InputMethod_TextEditorProxy *OH_TextEditorProxy_Create(void)](#oh_texteditorproxy_create) | - | Creates an [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance.                                                                                                                                                                                                                                                                                                                       |
| [void OH_TextEditorProxy_Destroy(InputMethod_TextEditorProxy *proxy)](#oh_texteditorproxy_destroy) | - | Destroys an [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance.                                                                                                                                                                                                                                                                                                                         |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetGetTextConfigFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextConfigFunc getTextConfigFunc)](#oh_texteditorproxy_setgettextconfigfunc) | - | Sets the [OH_TextEditorProxy_GetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextconfigfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                                    |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetInsertTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_InsertTextFunc insertTextFunc)](#oh_texteditorproxy_setinserttextfunc) | - | Sets the [OH_TextEditorProxy_InsertTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_inserttextfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                                          |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetDeleteForwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteForwardFunc deleteForwardFunc)](#oh_texteditorproxy_setdeleteforwardfunc) | - | Sets the [OH_TextEditorProxy_DeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deleteforwardfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                                    |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetDeleteBackwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteBackwardFunc deleteBackwardFunc)](#oh_texteditorproxy_setdeletebackwardfunc) | - | Sets the [OH_TextEditorProxy_DeleteBackwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deletebackwardfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                                  |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetSendKeyboardStatusFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendKeyboardStatusFunc sendKeyboardStatusFunc)](#oh_texteditorproxy_setsendkeyboardstatusfunc) | - | Sets the [OH_TextEditorProxy_SendKeyboardStatusFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendkeyboardstatusfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                          |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetSendEnterKeyFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendEnterKeyFunc sendEnterKeyFunc)](#oh_texteditorproxy_setsendenterkeyfunc) | - | Sets the [OH_TextEditorProxy_SetSendEnterKeyFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setsendenterkeyfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                                |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetMoveCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_MoveCursorFunc moveCursorFunc)](#oh_texteditorproxy_setmovecursorfunc) | - | Sets the [OH_TextEditorProxy_SetMoveCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setmovecursorfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                                    |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetHandleSetSelectionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleSetSelectionFunc handleSetSelectionFunc)](#oh_texteditorproxy_sethandlesetselectionfunc) | - | Sets the [OH_TextEditorProxy_HandleSetSelectionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handlesetselectionfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                          |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetHandleExtendActionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleExtendActionFunc handleExtendActionFunc)](#oh_texteditorproxy_sethandleextendactionfunc) | - | Sets the [OH_TextEditorProxy_HandleExtendActionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handleextendactionfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                          |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetGetLeftTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetLeftTextOfCursorFunc getLeftTextOfCursorFunc)](#oh_texteditorproxy_setgetlefttextofcursorfunc) | - | Sets the [OH_TextEditorProxy_GetLeftTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getlefttextofcursorfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                        |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetGetRightTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetRightTextOfCursorFunc getRightTextOfCursorFunc)](#oh_texteditorproxy_setgetrighttextofcursorfunc) | - | Sets the [OH_TextEditorProxy_GetRightTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getrighttextofcursorfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                      |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetGetTextIndexAtCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextIndexAtCursorFunc getTextIndexAtCursorFunc)](#oh_texteditorproxy_setgettextindexatcursorfunc) | - | Sets the [OH_TextEditorProxy_GetTextIndexAtCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextindexatcursorfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                      |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetReceivePrivateCommandFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_ReceivePrivateCommandFunc receivePrivateCommandFunc)](#oh_texteditorproxy_setreceiveprivatecommandfunc) | - | Sets the [OH_TextEditorProxy_ReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_receiveprivatecommandfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                    |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetSetPreviewTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SetPreviewTextFunc setPreviewTextFunc)](#oh_texteditorproxy_setsetpreviewtextfunc) | - | Sets the [OH_TextEditorProxy_SetPreviewTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setpreviewtextfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                                  |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetFinishTextPreviewFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_FinishTextPreviewFunc finishTextPreviewFunc)](#oh_texteditorproxy_setfinishtextpreviewfunc) | - | Sets the [OH_TextEditorProxy_FinishTextPreviewFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_finishtextpreviewfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                            |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetGetTextConfigFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextConfigFunc *getTextConfigFunc)](#oh_texteditorproxy_getgettextconfigfunc) | - | Obtains the [OH_TextEditorProxy_GetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextconfigfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                                     |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetInsertTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_InsertTextFunc *insertTextFunc)](#oh_texteditorproxy_getinserttextfunc) | - | Obtains the [OH_TextEditorProxy_InsertTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_inserttextfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                                           |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetDeleteForwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteForwardFunc *deleteForwardFunc)](#oh_texteditorproxy_getdeleteforwardfunc) | - | Obtains the [OH_TextEditorProxy_DeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deleteforwardfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                                     |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetDeleteBackwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteBackwardFunc *deleteBackwardFunc)](#oh_texteditorproxy_getdeletebackwardfunc) | - | Obtains the [OH_TextEditorProxy_DeleteBackwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deletebackwardfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                                   |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetSendKeyboardStatusFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendKeyboardStatusFunc *sendKeyboardStatusFunc)](#oh_texteditorproxy_getsendkeyboardstatusfunc) | - | Obtains the [OH_TextEditorProxy_SendKeyboardStatusFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendkeyboardstatusfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                           |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetSendEnterKeyFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendEnterKeyFunc *sendEnterKeyFunc)](#oh_texteditorproxy_getsendenterkeyfunc) | - | Obtains the [OH_TextEditorProxy_SendEnterKeyFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendenterkeyfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                                       |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetMoveCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_MoveCursorFunc *moveCursorFunc)](#oh_texteditorproxy_getmovecursorfunc) | - | Obtains the [OH_TextEditorProxy_MoveCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_movecursorfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                                           |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetHandleSetSelectionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleSetSelectionFunc *handleSetSelectionFunc)](#oh_texteditorproxy_gethandlesetselectionfunc) | - | Obtains the [OH_TextEditorProxy_HandleSetSelectionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handlesetselectionfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                           |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetHandleExtendActionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleExtendActionFunc *handleExtendActionFunc)](#oh_texteditorproxy_gethandleextendactionfunc) | - | Obtains the [OH_TextEditorProxy_HandleExtendActionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handleextendactionfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                           |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetGetLeftTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetLeftTextOfCursorFunc *getLeftTextOfCursorFunc)](#oh_texteditorproxy_getgetlefttextofcursorfunc) | - | Obtains the [OH_TextEditorProxy_GetLeftTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getlefttextofcursorfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                         |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetGetRightTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetRightTextOfCursorFunc *getRightTextOfCursorFunc)](#oh_texteditorproxy_getgetrighttextofcursorfunc) | - | Obtains the [OH_TextEditorProxy_GetRightTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getrighttextofcursorfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                       |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetGetTextIndexAtCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextIndexAtCursorFunc *getTextIndexAtCursorFunc)](#oh_texteditorproxy_getgettextindexatcursorfunc) | - | Obtains the [OH_TextEditorProxy_GetTextIndexAtCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextindexatcursorfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                       |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetReceivePrivateCommandFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_ReceivePrivateCommandFunc *receivePrivateCommandFunc)](#oh_texteditorproxy_getreceiveprivatecommandfunc) | - | Obtains the [OH_TextEditorProxy_ReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_receiveprivatecommandfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                     |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetSetPreviewTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SetPreviewTextFunc *setPreviewTextFunc)](#oh_texteditorproxy_getsetpreviewtextfunc) | - | Obtains the [OH_TextEditorProxy_SetPreviewTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setpreviewtextfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                                   |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetFinishTextPreviewFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_FinishTextPreviewFunc *finishTextPreviewFunc)](#oh_texteditorproxy_getfinishtextpreviewfunc) | - | Obtains the [OH_TextEditorProxy_FinishTextPreviewFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_finishtextpreviewfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).                                                                                                                                             |

## Function Description

### OH_TextEditorProxy_GetTextConfigFunc()

```
typedef void (*OH_TextEditorProxy_GetTextConfigFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_TextConfig *config)
```

**Description**

Function called when the input method obtains the text box configuration. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetGetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setgettextconfigfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).

**Since**: 12


**Parameters**

| Name                                                                                            | Description|
|-------------------------------------------------------------------------------------------------| -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config                                                              | Pointer to the [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) instance.|

### OH_TextEditorProxy_InsertTextFunc()

```
typedef void (*OH_TextEditorProxy_InsertTextFunc)(InputMethod_TextEditorProxy *textEditorProxy, const char16_t *text, size_t length)
```

**Description**

Function called when the input method application inserts text. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetInsertTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setinserttextfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.in. |
|  const char16_t *text | Pointer to the characters to be inserted.|
|  size_t length | Length of the characters to be inserted.|

### OH_TextEditorProxy_DeleteForwardFunc()

```
typedef void (*OH_TextEditorProxy_DeleteForwardFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t length)
```

**Description**

Function called when the input method deletes the text on the right of the cursor. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetDeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setdeleteforwardfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.in. |
|  int32_t length | Length of the characters to be deleted.|

### OH_TextEditorProxy_DeleteBackwardFunc()

```
typedef void (*OH_TextEditorProxy_DeleteBackwardFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t length)
```

**Description**

Function called when the input method deletes the text on the left of the cursor. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetDeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setdeleteforwardfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.in. |
|  int32_t length | Length of the characters to be deleted.|

### OH_TextEditorProxy_SendKeyboardStatusFunc()

```
typedef void (*OH_TextEditorProxy_SendKeyboardStatusFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_KeyboardStatus keyboardStatus)
```

**Description**

Function called when the input method notifies the keyboard status. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetSendKeyboardStatusFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setsendkeyboardstatusfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
| [ InputMethod_KeyboardStatus](capi-inputmethod-types-capi-h.md#inputmethod_keyboardstatus) keyboardStatus | Keyboard status. For details, see [InputMethod_KeyboardStatus](capi-inputmethod-types-capi-h.md#inputmethod_keyboardstatus).|

### OH_TextEditorProxy_SendEnterKeyFunc()

```
typedef void (*OH_TextEditorProxy_SendEnterKeyFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_EnterKeyType enterKeyType)
```

**Description**

Function called when the Enter key is pressed in the input method. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetSendEnterKeyFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setsendenterkeyfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
| [ InputMethod_EnterKeyType](capi-inputmethod-types-capi-h.md#inputmethod_enterkeytype) enterKeyType | Enter key type. For details, see [InputMethod_EnterKeyType](capi-inputmethod-types-capi-h.md#inputmethod_enterkeytype).|

### OH_TextEditorProxy_MoveCursorFunc()

```
typedef void (*OH_TextEditorProxy_MoveCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_Direction direction)
```

**Description**

Function called when the cursor is moved in the input method. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetMoveCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setmovecursorfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
| [ InputMethod_Direction](capi-inputmethod-types-capi-h.md#inputmethod_direction) direction | Direction in which the cursor moves. For details, see [InputMethod_Direction](capi-inputmethod-types-capi-h.md#inputmethod_direction).|

### OH_TextEditorProxy_HandleSetSelectionFunc()

```
typedef void (*OH_TextEditorProxy_HandleSetSelectionFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t start, int32_t end)
```

**Description**

Function called when the input method requests to select text. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetHandleSetSelectionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sethandlesetselectionfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
|  int32_t start | Start position of the selected text.|
|  int32_t end | End position of the selected text.|

### OH_TextEditorProxy_HandleExtendActionFunc()

```
typedef void (*OH_TextEditorProxy_HandleExtendActionFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_ExtendAction action)
```

**Description**

Function called when the input method sends an extended editing operation. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetHandleExtendActionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sethandleextendactionfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
| [ InputMethod_ExtendAction](capi-inputmethod-types-capi-h.md#inputmethod_extendaction) action | Extended editing operation. For details, see [InputMethod_ExtendAction](capi-inputmethod-types-capi-h.md#inputmethod_extendaction).|

### OH_TextEditorProxy_GetLeftTextOfCursorFunc()

```
typedef void (*OH_TextEditorProxy_GetLeftTextOfCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t number, char16_t text[], size_t *length)
```

**Description**

Function called when the input method obtains the text on the left of the cursor. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetGetLeftTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setgetlefttextofcursorfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
| int32_t number | Length of the text to be obtained.|
| char16_t text[] | Text content of a specified length on the left of the cursor. You need to assign a value to the text content in the function implementation.|
| size_t *length | Pointer to the length of the text on the left of the cursor. You need to transfer this parameter.|

### OH_TextEditorProxy_GetRightTextOfCursorFunc()

```
typedef void (*OH_TextEditorProxy_GetRightTextOfCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t number, char16_t text[], size_t *length)
```

**Description**

Function called when the input method obtains the text on the right of the cursor. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetGetRightTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setgetrighttextofcursorfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
|  int32_t number | Length of the text to be obtained.|
| char16_t text[] | Text content of a specified length on the right of the cursor. You need to assign a value to the text content in the function implementation.|
|  size_t *length | Length of the text on the left of the cursor.|

### OH_TextEditorProxy_GetTextIndexAtCursorFunc()

```
typedef int32_t (*OH_TextEditorProxy_GetTextIndexAtCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy)
```

**Description**

Function called when the input method obtains the index of the text where the cursor is located in the text box. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetGetTextIndexAtCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setgettextindexatcursorfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Index of the text where the cursor is located.|

### OH_TextEditorProxy_ReceivePrivateCommandFunc()

```
typedef int32_t (*OH_TextEditorProxy_ReceivePrivateCommandFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_PrivateCommand *privateCommand[], size_t size)
```

**Description**

Function called when the input method application sends a private data command. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setreceiveprivatecommandfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).

**Since**: 12


**Parameters**

| Name                                                                                            | Description|
|-------------------------------------------------------------------------------------------------| -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *privateCommand[]                                                | Private data command.|
| size_t size                                                                                     | Size of the private data.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t  | Processing result of the private data command.|

### OH_TextEditorProxy_SetPreviewTextFunc()

```
typedef int32_t (*OH_TextEditorProxy_SetPreviewTextFunc)(InputMethod_TextEditorProxy *textEditorProxy, const char16_t text[], size_t length, int32_t start, int32_t end)
```

**Description**

Function called when the input method sets the text preview feature. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setreceiveprivatecommandfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
| const char16_t text[] | Text requested to be previewed.|
|  size_t length | Length of the text to be previewed.|
|  int32_t start | Starting cursor position of the text to be previewed.|
|  int32_t end | Ending cursor position of the text to be previewed.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t  | Result of setting text preview.|

### OH_TextEditorProxy_FinishTextPreviewFunc()

```
typedef void (*OH_TextEditorProxy_FinishTextPreviewFunc)(InputMethod_TextEditorProxy *textEditorProxy)
```

**Description**

Function called when the input method ends the text preview feature. You need to implement this function, set it to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) via [OH_TextEditorProxy_SetReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setreceiveprivatecommandfunc), and register it through [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|

### OH_TextEditorProxy_Create()

```
InputMethod_TextEditorProxy *OH_TextEditorProxy_Create(void)
```

**Description**

Creates an [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance.

**Since**: 12

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) * | If the operation is successful, a pointer to the created [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance is returned.<br> If the operation failed, **NULL** is returned, which may be caused by insufficient application address space.|

### OH_TextEditorProxy_Destroy()

```
void OH_TextEditorProxy_Destroy(InputMethod_TextEditorProxy *proxy)
```

**Description**

Destroys an [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be destroyed.|

### OH_TextEditorProxy_SetGetTextConfigFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetGetTextConfigFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextConfigFunc getTextConfigFunc)
```

**Description**

Sets the [OH_TextEditorProxy_GetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextconfigfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
| [OH_TextEditorProxy_GetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextconfigfunc) getTextConfigFunc | [OH_TextEditorProxy_GetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextconfigfunc) to be set to the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_SetInsertTextFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetInsertTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_InsertTextFunc insertTextFunc)
```

**Description**

Sets the [OH_TextEditorProxy_InsertTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_inserttextfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
| [OH_TextEditorProxy_InsertTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_inserttextfunc) insertTextFunc | [OH_TextEditorProxy_InsertTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_inserttextfunc) to be set to the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_SetDeleteForwardFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetDeleteForwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteForwardFunc deleteForwardFunc)
```

**Description**

Sets the [OH_TextEditorProxy_DeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deleteforwardfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
| [OH_TextEditorProxy_DeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deleteforwardfunc) deleteForwardFunc | [OH_TextEditorProxy_DeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deleteforwardfunc) to be set to the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_SetDeleteBackwardFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetDeleteBackwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteBackwardFunc deleteBackwardFunc)
```

**Description**

Sets the [OH_TextEditorProxy_DeleteBackwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deletebackwardfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
| [OH_TextEditorProxy_DeleteBackwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deletebackwardfunc) deleteBackwardFunc | [OH_TextEditorProxy_DeleteBackwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deletebackwardfunc) to be set to the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_SetSendKeyboardStatusFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetSendKeyboardStatusFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendKeyboardStatusFunc sendKeyboardStatusFunc)
```

**Description**

Sets the [OH_TextEditorProxy_SendKeyboardStatusFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendkeyboardstatusfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
| [OH_TextEditorProxy_SendKeyboardStatusFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendkeyboardstatusfunc) sendKeyboardStatusFunc | [OH_TextEditorProxy_SendKeyboardStatusFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendkeyboardstatusfunc) to be set to the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_SetSendEnterKeyFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetSendEnterKeyFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendEnterKeyFunc sendEnterKeyFunc)
```

**Description**

Sets the [OH_TextEditorProxy_SetSendEnterKeyFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setsendenterkeyfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
| [OH_TextEditorProxy_SendEnterKeyFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendenterkeyfunc) sendEnterKeyFunc | [OH_TextEditorProxy_SendEnterKeyFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendenterkeyfunc) to be set to the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_SetMoveCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetMoveCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_MoveCursorFunc moveCursorFunc)
```

**Description**

Sets the [OH_TextEditorProxy_SetMoveCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setmovecursorfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
| [OH_TextEditorProxy_MoveCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_movecursorfunc) moveCursorFunc | [OH_TextEditorProxy_MoveCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_movecursorfunc) to be set to the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_SetHandleSetSelectionFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetHandleSetSelectionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleSetSelectionFunc handleSetSelectionFunc)
```

**Description**

Sets the [OH_TextEditorProxy_HandleSetSelectionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handlesetselectionfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
| [OH_TextEditorProxy_HandleSetSelectionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handlesetselectionfunc) handleSetSelectionFunc | [OH_TextEditorProxy_HandleSetSelectionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handlesetselectionfunc) to be set to the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_SetHandleExtendActionFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetHandleExtendActionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleExtendActionFunc handleExtendActionFunc)
```

**Description**

Sets the [OH_TextEditorProxy_HandleExtendActionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handleextendactionfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
| [OH_TextEditorProxy_HandleExtendActionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handleextendactionfunc) handleExtendActionFunc | [OH_TextEditorProxy_HandleExtendActionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handleextendactionfunc) to be set to the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_SetGetLeftTextOfCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetGetLeftTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetLeftTextOfCursorFunc getLeftTextOfCursorFunc)
```

**Description**

Sets the [OH_TextEditorProxy_GetLeftTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getlefttextofcursorfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
| [OH_TextEditorProxy_GetLeftTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getlefttextofcursorfunc) getLeftTextOfCursorFunc | [OH_TextEditorProxy_GetLeftTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getlefttextofcursorfunc) to be set to the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_SetGetRightTextOfCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetGetRightTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetRightTextOfCursorFunc getRightTextOfCursorFunc)
```

**Description**

Sets the [OH_TextEditorProxy_GetRightTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getrighttextofcursorfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
| [OH_TextEditorProxy_GetRightTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getrighttextofcursorfunc) getRightTextOfCursorFunc | [OH_TextEditorProxy_GetRightTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getrighttextofcursorfunc) to be set to the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_SetGetTextIndexAtCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetGetTextIndexAtCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextIndexAtCursorFunc getTextIndexAtCursorFunc)
```

**Description**

Sets the [OH_TextEditorProxy_GetTextIndexAtCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextindexatcursorfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
| [OH_TextEditorProxy_GetTextIndexAtCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextindexatcursorfunc) getTextIndexAtCursorFunc | [OH_TextEditorProxy_GetTextIndexAtCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextindexatcursorfunc) to be set to the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_SetReceivePrivateCommandFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetReceivePrivateCommandFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_ReceivePrivateCommandFunc receivePrivateCommandFunc)
```

**Description**

Sets the [OH_TextEditorProxy_ReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_receiveprivatecommandfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
| [OH_TextEditorProxy_ReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_receiveprivatecommandfunc) receivePrivateCommandFunc | [OH_TextEditorProxy_ReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_receiveprivatecommandfunc) to be set to the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_SetSetPreviewTextFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetSetPreviewTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SetPreviewTextFunc setPreviewTextFunc)
```

**Description**

Sets the [OH_TextEditorProxy_SetPreviewTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setpreviewtextfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
| [OH_TextEditorProxy_SetPreviewTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setpreviewtextfunc) setPreviewTextFunc | [OH_TextEditorProxy_SetPreviewTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setpreviewtextfunc) to be set to the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_SetFinishTextPreviewFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_SetFinishTextPreviewFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_FinishTextPreviewFunc finishTextPreviewFunc)
```

**Description**

Sets the [OH_TextEditorProxy_FinishTextPreviewFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_finishtextpreviewfunc) function to [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be set.|
| [OH_TextEditorProxy_FinishTextPreviewFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_finishtextpreviewfunc) finishTextPreviewFunc | [OH_TextEditorProxy_FinishTextPreviewFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_finishtextpreviewfunc) to be set to the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_GetGetTextConfigFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetGetTextConfigFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextConfigFunc *getTextConfigFunc)
```

**Description**

Obtains the [OH_TextEditorProxy_GetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextconfigfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be read.|
| [OH_TextEditorProxy_GetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextconfigfunc) *getTextConfigFunc | Function [OH_TextEditorProxy_GetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextconfigfunc) obtained from the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_GetInsertTextFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetInsertTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_InsertTextFunc *insertTextFunc)
```

**Description**

Obtains the [OH_TextEditorProxy_InsertTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_inserttextfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be read.|
| [OH_TextEditorProxy_InsertTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_inserttextfunc) *insertTextFunc | Function [OH_TextEditorProxy_InsertTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_inserttextfunc) obtained from the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_GetDeleteForwardFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetDeleteForwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteForwardFunc *deleteForwardFunc)
```

**Description**

Obtains the [OH_TextEditorProxy_DeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deleteforwardfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be read.|
| [OH_TextEditorProxy_DeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deleteforwardfunc) *deleteForwardFunc | Function [OH_TextEditorProxy_DeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deleteforwardfunc) obtained from the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_GetDeleteBackwardFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetDeleteBackwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteBackwardFunc *deleteBackwardFunc)
```

**Description**

Obtains the [OH_TextEditorProxy_DeleteBackwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deletebackwardfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be read.|
| [OH_TextEditorProxy_DeleteBackwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deletebackwardfunc) *deleteBackwardFunc | Function [OH_TextEditorProxy_DeleteBackwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_deletebackwardfunc) obtained from the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_GetSendKeyboardStatusFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetSendKeyboardStatusFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendKeyboardStatusFunc *sendKeyboardStatusFunc)
```

**Description**

Obtains the [OH_TextEditorProxy_SendKeyboardStatusFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendkeyboardstatusfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be read.|
| [OH_TextEditorProxy_SendKeyboardStatusFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendkeyboardstatusfunc) *sendKeyboardStatusFunc | Function [OH_TextEditorProxy_SendKeyboardStatusFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendkeyboardstatusfunc) obtained from the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_GetSendEnterKeyFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetSendEnterKeyFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendEnterKeyFunc *sendEnterKeyFunc)
```

**Description**

Obtains the [OH_TextEditorProxy_SendEnterKeyFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendenterkeyfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be read.|
| [OH_TextEditorProxy_SendEnterKeyFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendenterkeyfunc) *sendEnterKeyFunc | Function [OH_TextEditorProxy_SendEnterKeyFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sendenterkeyfunc) obtained from the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_GetMoveCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetMoveCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_MoveCursorFunc *moveCursorFunc)
```

**Description**

Obtains the [OH_TextEditorProxy_MoveCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_movecursorfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be read.|
| [OH_TextEditorProxy_MoveCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_movecursorfunc) *moveCursorFunc | Function [OH_TextEditorProxy_MoveCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_movecursorfunc) obtained from the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_GetHandleSetSelectionFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetHandleSetSelectionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleSetSelectionFunc *handleSetSelectionFunc)
```

**Description**

Obtains the [OH_TextEditorProxy_HandleSetSelectionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handlesetselectionfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be read.|
| [OH_TextEditorProxy_HandleSetSelectionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handlesetselectionfunc) *handleSetSelectionFunc | Function [OH_TextEditorProxy_HandleSetSelectionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handlesetselectionfunc) obtained from the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_GetHandleExtendActionFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetHandleExtendActionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleExtendActionFunc *handleExtendActionFunc)
```

**Description**

Obtains the [OH_TextEditorProxy_HandleExtendActionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handleextendactionfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be read.|
| [OH_TextEditorProxy_HandleExtendActionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handleextendactionfunc) *handleExtendActionFunc | Function [OH_TextEditorProxy_HandleExtendActionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_handleextendactionfunc) obtained from the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_GetGetLeftTextOfCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetGetLeftTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetLeftTextOfCursorFunc *getLeftTextOfCursorFunc)
```

**Description**

Obtains the [OH_TextEditorProxy_GetLeftTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getlefttextofcursorfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be read.|
| [OH_TextEditorProxy_GetLeftTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getlefttextofcursorfunc) *getLeftTextOfCursorFunc | Function [OH_TextEditorProxy_GetLeftTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getlefttextofcursorfunc) obtained from the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_GetGetRightTextOfCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetGetRightTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetRightTextOfCursorFunc *getRightTextOfCursorFunc)
```

**Description**

Obtains the [OH_TextEditorProxy_GetRightTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getrighttextofcursorfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be read.|
| [OH_TextEditorProxy_GetRightTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getrighttextofcursorfunc) *getRightTextOfCursorFunc | Function [OH_TextEditorProxy_GetRightTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getrighttextofcursorfunc) obtained from the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_GetGetTextIndexAtCursorFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetGetTextIndexAtCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextIndexAtCursorFunc *getTextIndexAtCursorFunc)
```

**Description**

Obtains the [OH_TextEditorProxy_GetTextIndexAtCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextindexatcursorfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be read.|
| [OH_TextEditorProxy_GetTextIndexAtCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextindexatcursorfunc) *getTextIndexAtCursorFunc | Function [OH_TextEditorProxy_GetTextIndexAtCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextindexatcursorfunc) obtained from the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_GetReceivePrivateCommandFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetReceivePrivateCommandFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_ReceivePrivateCommandFunc *receivePrivateCommandFunc)
```

**Description**

Obtains the [OH_TextEditorProxy_ReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_receiveprivatecommandfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be read.|
| [OH_TextEditorProxy_ReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_receiveprivatecommandfunc) *receivePrivateCommandFunc | Function [OH_TextEditorProxy_ReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_receiveprivatecommandfunc) obtained from the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_GetSetPreviewTextFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetSetPreviewTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SetPreviewTextFunc *setPreviewTextFunc)
```

**Description**

Obtains the [OH_TextEditorProxy_SetPreviewTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setpreviewtextfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be read.|
| [OH_TextEditorProxy_SetPreviewTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setpreviewtextfunc) *setPreviewTextFunc | Function [OH_TextEditorProxy_SetPreviewTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setpreviewtextfunc) obtained from the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextEditorProxy_GetFinishTextPreviewFunc()

```
InputMethod_ErrorCode OH_TextEditorProxy_GetFinishTextPreviewFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_FinishTextPreviewFunc *finishTextPreviewFunc)
```

**Description**

Obtains the [OH_TextEditorProxy_FinishTextPreviewFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_finishtextpreviewfunc) function from [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance to be read.|
| [OH_TextEditorProxy_FinishTextPreviewFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_finishtextpreviewfunc) *finishTextPreviewFunc | Function [OH_TextEditorProxy_FinishTextPreviewFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_finishtextpreviewfunc) obtained from the proxy.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|
