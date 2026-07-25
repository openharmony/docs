# InputMethod_TextEditorProxy
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->

```c
typedef struct InputMethod_TextEditorProxy InputMethod_TextEditorProxy
```

## 概述

输入法文本编辑器代理类。用于处理输入法应用与文本编辑器之间的交互，提供接收输入法请求和通知的方法，适用于需要实现输入法与编辑器双向通信的场景。该结构体为不透明类型（opaque type），调用者不可直接访问其内部成员，仅可通过本模块提供的函数接口进行操作。

**起始版本：** 12

**相关模块：** [InputMethod](capi-inputmethod.md)（输入法）

**所在头文件：** [inputmethod_text_editor_proxy_capi.h](capi-inputmethod-text-editor-proxy-capi-h.md)

## 结构体用途

InputMethod_TextEditorProxy是文本编辑器端与输入法应用交互的代理对象，采用回调机制实现输入法应用向编辑器发送请求和通知的双向通信。当输入法应用向编辑器发送请求（如插入文本、删除文本、移动光标等）或通知（如键盘状态变化、回车键事件等）时，通过此代理对象中注册的回调函数进行处理。开发者需实现各回调函数并通过Set*Func接口将其注册到TextEditorProxy中，再通过Attach完成注册。

## 生命周期管理

- 创建方式：通过[OH_TextEditorProxy_Create](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_create)函数创建，返回一个新的InputMethod_TextEditorProxy实例指针。创建失败时返回NULL，可能原因为内存不足。
- 销毁方式：通过[OH_TextEditorProxy_Destroy](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_destroy)函数销毁，传入要销毁的实例指针。销毁后指针不可再使用，建议将指针设置为NULL避免误用。
- 配对关系：OH_TextEditorProxy_Create与OH_TextEditorProxy_Destroy必须配对使用，创建的对象必须最终通过Destroy释放，否则会导致内存泄漏。同一个TextEditorProxy实例只能被销毁一次，不可重复销毁。
- 使用时机：创建TextEditorProxy后，须先通过Set*Func接口注册回调函数，再通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成绑定注册。Attach之后不建议再修改回调函数设置。

## 回调机制说明

TextEditorProxy采用回调函数机制实现输入法应用与编辑器之间的双向通信：

- 回调注册流程：创建TextEditorProxy → 通过Set*Func接口注册各回调函数 → 通过Attach完成注册。
- 回调触发时机：当输入法应用向编辑器发送请求或通知时，系统自动调用TextEditorProxy中已注册的对应回调函数。
- 回调函数中指针的临时性：回调函数中接收到的指针参数（如text、privateCommand等）仅在回调执行期间有效，回调返回后该内存将被释放，不可再访问。开发者应在回调内部完成必要的数据拷贝或处理，不得在回调外部继续使用这些指针。
- GetTextConfigFunc不受SetCallbackInMainThread影响：[OH_TextEditorProxy_GetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextconfigfunc)的执行线程由调用[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)的线程决定，不受[OH_TextEditorProxy_SetCallbackInMainThread](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setcallbackinmainthread)的影响。若需GetTextConfigFunc也在主线程执行，需确保Attach在主线程调用。

## 使用注意事项

- 所有Set*Func接口必须在Attach之前调用，Attach后设置的回调函数将不会被输入法调用。
- 回调函数中的指针参数具有临时性，回调返回后不可再访问，必须在回调内部完成数据处理。
- 建议至少注册GetTextConfigFunc和InsertTextFunc两个核心回调，否则输入法可能无法正常工作。
- 非线程安全，不建议在多线程环境下同时操作同一个TextEditorProxy对象。可通过[OH_TextEditorProxy_SetCallbackInMainThread](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setcallbackinmainthread)将回调切换到主线程执行以避免多线程并发问题。
- 此对象为不透明类型，不可直接访问内部成员或进行内存操作。

相关函数：

- 创建/销毁函数

| 函数 | 描述 |
| -- | -- |
| [OH_TextEditorProxy_Create](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_create) | 创建一个新的InputMethod_TextEditorProxy实例。 |
| [OH_TextEditorProxy_Destroy](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_destroy) | 销毁一个InputMethod_TextEditorProxy实例。 |

- 回调设置函数（Set*Func，须在Attach前调用）

| 函数 | 描述 |
| -- | -- |
| [OH_TextEditorProxy_SetGetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setgettextconfigfunc) | 设置GetTextConfigFunc回调。 |
| [OH_TextEditorProxy_SetInsertTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setinserttextfunc) | 设置InsertTextFunc回调。 |
| [OH_TextEditorProxy_SetDeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setdeleteforwardfunc) | 设置DeleteForwardFunc回调。 |
| [OH_TextEditorProxy_SetDeleteBackwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setdeletebackwardfunc) | 设置DeleteBackwardFunc回调。 |
| [OH_TextEditorProxy_SetSendKeyboardStatusFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setsendkeyboardstatusfunc) | 设置SendKeyboardStatusFunc回调。 |
| [OH_TextEditorProxy_SetSendEnterKeyFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setsendenterkeyfunc) | 设置SendEnterKeyFunc回调。 |
| [OH_TextEditorProxy_SetMoveCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setmovecursorfunc) | 设置MoveCursorFunc回调。 |
| [OH_TextEditorProxy_SetHandleSetSelectionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sethandlesetselectionfunc) | 设置HandleSetSelectionFunc回调。 |
| [OH_TextEditorProxy_SetHandleExtendActionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_sethandleextendactionfunc) | 设置HandleExtendActionFunc回调。 |
| [OH_TextEditorProxy_SetGetLeftTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setgetlefttextofcursorfunc) | 设置GetLeftTextOfCursorFunc回调。 |
| [OH_TextEditorProxy_SetGetRightTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setgetrighttextofcursorfunc) | 设置GetRightTextOfCursorFunc回调。 |
| [OH_TextEditorProxy_SetGetTextIndexAtCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setgettextindexatcursorfunc) | 设置GetTextIndexAtCursorFunc回调。 |
| [OH_TextEditorProxy_SetReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setreceiveprivatecommandfunc) | 设置ReceivePrivateCommandFunc回调。 |
| [OH_TextEditorProxy_SetSetPreviewTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setsetpreviewtextfunc) | 设置SetPreviewTextFunc回调。 |
| [OH_TextEditorProxy_SetFinishTextPreviewFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setfinishtextpreviewfunc) | 设置FinishTextPreviewFunc回调。 |

- 回调获取函数（Get*Func）

| 函数 | 描述 |
| -- | -- |
| [OH_TextEditorProxy_GetGetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getgettextconfigfunc) | 获取已注册的GetTextConfigFunc回调。 |
| [OH_TextEditorProxy_GetInsertTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getinserttextfunc) | 获取已注册的InsertTextFunc回调。 |
| [OH_TextEditorProxy_GetDeleteForwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getdeleteforwardfunc) | 获取已注册的DeleteForwardFunc回调。 |
| [OH_TextEditorProxy_GetDeleteBackwardFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getdeletebackwardfunc) | 获取已注册的DeleteBackwardFunc回调。 |
| [OH_TextEditorProxy_GetSendKeyboardStatusFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getsendkeyboardstatusfunc) | 获取已注册的SendKeyboardStatusFunc回调。 |
| [OH_TextEditorProxy_GetSendEnterKeyFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getsendenterkeyfunc) | 获取已注册的SendEnterKeyFunc回调。 |
| [OH_TextEditorProxy_GetMoveCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getmovecursorfunc) | 获取已注册的MoveCursorFunc回调。 |
| [OH_TextEditorProxy_GetHandleSetSelectionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gethandlesetselectionfunc) | 获取已注册的HandleSetSelectionFunc回调。 |
| [OH_TextEditorProxy_GetHandleExtendActionFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gethandleextendactionfunc) | 获取已注册的HandleExtendActionFunc回调。 |
| [OH_TextEditorProxy_GetGetLeftTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getgetlefttextofcursorfunc) | 获取已注册的GetLeftTextOfCursorFunc回调。 |
| [OH_TextEditorProxy_GetGetRightTextOfCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getgetrighttextofcursorfunc) | 获取已注册的GetRightTextOfCursorFunc回调。 |
| [OH_TextEditorProxy_GetGetTextIndexAtCursorFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getgettextindexatcursorfunc) | 获取已注册的GetTextIndexAtCursorFunc回调。 |
| [OH_TextEditorProxy_GetReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getreceiveprivatecommandfunc) | 获取已注册的ReceivePrivateCommandFunc回调。 |
| [OH_TextEditorProxy_GetSetPreviewTextFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getsetpreviewtextfunc) | 获取已注册的SetPreviewTextFunc回调。 |
| [OH_TextEditorProxy_GetFinishTextPreviewFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_getfinishtextpreviewfunc) | 获取已注册的FinishTextPreviewFunc回调。 |

线程配置函数：

| 函数 | 描述 |
| -- | -- |
| [OH_TextEditorProxy_SetCallbackInMainThread](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_setcallbackinmainthread) | 配置回调函数的执行线程策略。 |

关联关系：

- 与InputMethodProxy的关系：[InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md)负责向输入法服务发送请求和通知，InputMethod_TextEditorProxy负责接收输入法应用的请求和通知。两者在Attach时同时建立关联，构成双向通信通道。
- 与TextConfig的关系：[InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md)在GetTextConfigFunc回调中使用，用于向输入法传递编辑框的配置信息。GetTextConfigFunc回调被触发时，开发者需在回调内对config参数赋值以填充配置信息。
