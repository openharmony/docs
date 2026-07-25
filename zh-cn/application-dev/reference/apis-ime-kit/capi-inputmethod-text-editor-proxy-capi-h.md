# inputmethod_text_editor_proxy_capi.h
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->

## 概述

提供一套方法支持应用开发的自绘输入框获取来自输入法应用的通知和请求。该模块采用回调机制实现输入法应用与自绘输入框之间的双向通信。

**引用文件：** <inputmethod/inputmethod_text_editor_proxy_capi.h>

**库：** libohinputmethod.so

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**起始版本：** 12

**相关模块：** [InputMethod](capi-inputmethod.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) | InputMethod_TextEditorProxy | 输入法文本编辑器代理类。提供了获取来自输入法应用的通知和请求的方法。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (*OH_TextEditorProxy_GetTextConfigFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_TextConfig *config)](#oh_texteditorproxy_gettextconfigfunc) | OH_TextEditorProxy_GetTextConfigFunc | 输入法获取输入框配置时触发的函数。 |
| [typedef void (*OH_TextEditorProxy_InsertTextFunc)(InputMethod_TextEditorProxy *textEditorProxy, const char16_t *text, size_t length)](#oh_texteditorproxy_inserttextfunc) | OH_TextEditorProxy_InsertTextFunc | 输入法应用插入文本时触发的函数。 |
| [typedef void (*OH_TextEditorProxy_DeleteForwardFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t length)](#oh_texteditorproxy_deleteforwardfunc) | OH_TextEditorProxy_DeleteForwardFunc | 输入法删除光标右侧文本时触发的函数。 |
| [typedef void (*OH_TextEditorProxy_DeleteBackwardFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t length)](#oh_texteditorproxy_deletebackwardfunc) | OH_TextEditorProxy_DeleteBackwardFunc | 输入法删除光标左侧文本时触发的函数。 |
| [typedef void (*OH_TextEditorProxy_SendKeyboardStatusFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_KeyboardStatus keyboardStatus)](#oh_texteditorproxy_sendkeyboardstatusfunc) | OH_TextEditorProxy_SendKeyboardStatusFunc | 输入法通知键盘状态时触发的函数。 |
| [typedef void (*OH_TextEditorProxy_SendEnterKeyFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_EnterKeyType enterKeyType)](#oh_texteditorproxy_sendenterkeyfunc) | OH_TextEditorProxy_SendEnterKeyFunc | 输入法发送回车键时触发的函数。 |
| [typedef void (*OH_TextEditorProxy_MoveCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_Direction direction)](#oh_texteditorproxy_movecursorfunc) | OH_TextEditorProxy_MoveCursorFunc | 输入法移动光标时触发的函数。 |
| [typedef void (*OH_TextEditorProxy_HandleSetSelectionFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t start, int32_t end)](#oh_texteditorproxy_handlesetselectionfunc) | OH_TextEditorProxy_HandleSetSelectionFunc | 输入法请求选中文本时触发的函数。 |
| [typedef void (*OH_TextEditorProxy_HandleExtendActionFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_ExtendAction action)](#oh_texteditorproxy_handleextendactionfunc) | OH_TextEditorProxy_HandleExtendActionFunc | 输入法发送扩展编辑操作时触发的函数。 |
| [typedef void (*OH_TextEditorProxy_GetLeftTextOfCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t number, char16_t text[], size_t *length)](#oh_texteditorproxy_getlefttextofcursorfunc) | OH_TextEditorProxy_GetLeftTextOfCursorFunc | 输入法获取光标左侧文本时触发的函数。 |
| [typedef void (*OH_TextEditorProxy_GetRightTextOfCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t number, char16_t text[], size_t *length)](#oh_texteditorproxy_getrighttextofcursorfunc) | OH_TextEditorProxy_GetRightTextOfCursorFunc | 输入法获取光标右侧文本时触发的函数。 |
| [typedef int32_t (*OH_TextEditorProxy_GetTextIndexAtCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy)](#oh_texteditorproxy_gettextindexatcursorfunc) | OH_TextEditorProxy_GetTextIndexAtCursorFunc | 输入法获取光标所在输入框文本索引时触发的函数。 |
| [typedef int32_t (*OH_TextEditorProxy_ReceivePrivateCommandFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_PrivateCommand *privateCommand[], size_t size)](#oh_texteditorproxy_receiveprivatecommandfunc) | OH_TextEditorProxy_ReceivePrivateCommandFunc | 输入法应用发送私有数据命令时触发的函数。 |
| [typedef int32_t (*OH_TextEditorProxy_SetPreviewTextFunc)(InputMethod_TextEditorProxy *textEditorProxy, const char16_t text[], size_t length, int32_t start, int32_t end)](#oh_texteditorproxy_setpreviewtextfunc) | OH_TextEditorProxy_SetPreviewTextFunc | 输入法设置预上屏文本时触发的函数。 |
| [typedef void (*OH_TextEditorProxy_FinishTextPreviewFunc)(InputMethod_TextEditorProxy *textEditorProxy)](#oh_texteditorproxy_finishtextpreviewfunc) | OH_TextEditorProxy_FinishTextPreviewFunc | 输入法结束预上屏时触发的函数。 |
| [InputMethod_TextEditorProxy *OH_TextEditorProxy_Create(void)](#oh_texteditorproxy_create) | - | 创建一个新的InputMethod_TextEditorProxy实例。 |
| [void OH_TextEditorProxy_Destroy(InputMethod_TextEditorProxy *proxy)](#oh_texteditorproxy_destroy) | - | 销毁一个InputMethod_TextEditorProxy实例。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetGetTextConfigFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextConfigFunc getTextConfigFunc)](#oh_texteditorproxy_setgettextconfigfunc) | - | 将GetTextConfigFunc设置到TextEditorProxy中。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetInsertTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_InsertTextFunc insertTextFunc)](#oh_texteditorproxy_setinserttextfunc) | - | 将InsertTextFunc设置到TextEditorProxy中。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetDeleteForwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteForwardFunc deleteForwardFunc)](#oh_texteditorproxy_setdeleteforwardfunc) | - | 将DeleteForwardFunc设置到TextEditorProxy中。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetDeleteBackwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteBackwardFunc deleteBackwardFunc)](#oh_texteditorproxy_setdeletebackwardfunc) | - | 将DeleteBackwardFunc设置到TextEditorProxy中。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetSendKeyboardStatusFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendKeyboardStatusFunc sendKeyboardStatusFunc)](#oh_texteditorproxy_setsendkeyboardstatusfunc) | - | 将SendKeyboardStatusFunc设置到TextEditorProxy中。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetSendEnterKeyFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendEnterKeyFunc sendEnterKeyFunc)](#oh_texteditorproxy_setsendenterkeyfunc) | - | 将SendEnterKeyFunc设置到TextEditorProxy中。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetMoveCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_MoveCursorFunc moveCursorFunc)](#oh_texteditorproxy_setmovecursorfunc) | - | 将MoveCursorFunc设置到TextEditorProxy中。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetHandleSetSelectionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleSetSelectionFunc handleSetSelectionFunc)](#oh_texteditorproxy_sethandlesetselectionfunc) | - | 将HandleSetSelectionFunc设置到TextEditorProxy中。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetHandleExtendActionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleExtendActionFunc handleExtendActionFunc)](#oh_texteditorproxy_sethandleextendactionfunc) | - | 将HandleExtendActionFunc设置到TextEditorProxy中。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetGetLeftTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetLeftTextOfCursorFunc getLeftTextOfCursorFunc)](#oh_texteditorproxy_setgetlefttextofcursorfunc) | - | 将GetLeftTextOfCursorFunc设置到TextEditorProxy中。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetGetRightTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetRightTextOfCursorFunc getRightTextOfCursorFunc)](#oh_texteditorproxy_setgetrighttextofcursorfunc) | - | 将GetRightTextOfCursorFunc设置到TextEditorProxy中。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetGetTextIndexAtCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextIndexAtCursorFunc getTextIndexAtCursorFunc)](#oh_texteditorproxy_setgettextindexatcursorfunc) | - | 将GetTextIndexAtCursorFunc设置到TextEditorProxy中。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetReceivePrivateCommandFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_ReceivePrivateCommandFunc receivePrivateCommandFunc)](#oh_texteditorproxy_setreceiveprivatecommandfunc) | - | 将ReceivePrivateCommandFunc设置到TextEditorProxy中。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetSetPreviewTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SetPreviewTextFunc setPreviewTextFunc)](#oh_texteditorproxy_setsetpreviewtextfunc) | - | 将SetPreviewTextFunc设置到TextEditorProxy中。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetFinishTextPreviewFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_FinishTextPreviewFunc finishTextPreviewFunc)](#oh_texteditorproxy_setfinishtextpreviewfunc) | - | 将FinishTextPreviewFunc设置到TextEditorProxy中。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetGetTextConfigFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextConfigFunc *getTextConfigFunc)](#oh_texteditorproxy_getgettextconfigfunc) | - | 从TextEditorProxy中获取GetTextConfigFunc函数。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetInsertTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_InsertTextFunc *insertTextFunc)](#oh_texteditorproxy_getinserttextfunc) | - | 从TextEditorProxy中获取InsertTextFunc函数。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetDeleteForwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteForwardFunc *deleteForwardFunc)](#oh_texteditorproxy_getdeleteforwardfunc) | - | 从TextEditorProxy中获取DeleteForwardFunc函数。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetDeleteBackwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteBackwardFunc *deleteBackwardFunc)](#oh_texteditorproxy_getdeletebackwardfunc) | - | 从TextEditorProxy中获取DeleteBackwardFunc函数。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetSendKeyboardStatusFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendKeyboardStatusFunc *sendKeyboardStatusFunc)](#oh_texteditorproxy_getsendkeyboardstatusfunc) | - | 从TextEditorProxy中获取SendKeyboardStatusFunc函数。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetSendEnterKeyFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendEnterKeyFunc *sendEnterKeyFunc)](#oh_texteditorproxy_getsendenterkeyfunc) | - | 从TextEditorProxy中获取SendEnterKeyFunc函数。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetMoveCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_MoveCursorFunc *moveCursorFunc)](#oh_texteditorproxy_getmovecursorfunc) | - | 从TextEditorProxy中获取MoveCursorFunc函数。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetHandleSetSelectionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleSetSelectionFunc *handleSetSelectionFunc)](#oh_texteditorproxy_gethandlesetselectionfunc) | - | 从TextEditorProxy中获取HandleSetSelectionFunc函数。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetHandleExtendActionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleExtendActionFunc *handleExtendActionFunc)](#oh_texteditorproxy_gethandleextendactionfunc) | - | 从TextEditorProxy中获取HandleExtendActionFunc函数。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetGetLeftTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetLeftTextOfCursorFunc *getLeftTextOfCursorFunc)](#oh_texteditorproxy_getgetlefttextofcursorfunc) | - | 从TextEditorProxy中获取GetLeftTextOfCursorFunc函数。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetGetRightTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetRightTextOfCursorFunc *getRightTextOfCursorFunc)](#oh_texteditorproxy_getgetrighttextofcursorfunc) | - | 从TextEditorProxy中获取GetRightTextOfCursorFunc函数。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetGetTextIndexAtCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextIndexAtCursorFunc *getTextIndexAtCursorFunc)](#oh_texteditorproxy_getgettextindexatcursorfunc) | - | 从TextEditorProxy中获取GetTextIndexAtCursorFunc函数。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetReceivePrivateCommandFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_ReceivePrivateCommandFunc *receivePrivateCommandFunc)](#oh_texteditorproxy_getreceiveprivatecommandfunc) | - | 从TextEditorProxy中获取ReceivePrivateCommandFunc函数。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetSetPreviewTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SetPreviewTextFunc *setPreviewTextFunc)](#oh_texteditorproxy_getsetpreviewtextfunc) | - | 从TextEditorProxy中获取SetPreviewTextFunc函数。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_GetFinishTextPreviewFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_FinishTextPreviewFunc *finishTextPreviewFunc)](#oh_texteditorproxy_getfinishtextpreviewfunc) | - | 从TextEditorProxy中获取FinishTextPreviewFunc函数。 |
| [InputMethod_ErrorCode OH_TextEditorProxy_SetCallbackInMainThread(InputMethod_TextEditorProxy *proxy, bool isCallbackInMainThread)](#oh_texteditorproxy_setcallbackinmainthread) | - | 配置回调函数的执行线程策略。 |

## 函数说明

### OH_TextEditorProxy_GetTextConfigFunc()

```c
typedef void (*OH_TextEditorProxy_GetTextConfigFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_TextConfig *config)
```

**描述**

输入法获取输入框配置时触发的回调函数。开发者需实现此函数，在函数中对config参数设置编辑框的配置信息（输入类型、回车键类型、光标信息等），输入法框架将据此调整键盘布局和输入行为。

使用场景：当输入法应用需要获取编辑框的配置信息时，系统将自动调用此回调。此回调是输入法与编辑器交互的核心回调之一，必须实现。

使用后效果：回调返回后，输入法框架将读取config中的配置信息并据此调整键盘行为。config参数的内存将在回调返回后被释放，不可再访问。

前置条件：须通过[OH_TextEditorProxy_SetGetTextConfigFunc](#oh_texteditorproxy_setgettextconfigfunc)将此回调设置到TextEditorProxy中，并通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成注册。此回调的执行线程由调用Attach的线程决定，不受[OH_TextEditorProxy_SetCallbackInMainThread](#oh_texteditorproxy_setcallbackinmainthread)影响。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 输入指针，指向当前被回调的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例。用于标识触发回调的代理对象。 |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | 输出指针，表示指向[InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md)实例的指针。需要在函数实现中对其设置各配置属性（输入类型、回车键类型、光标信息等）以填充输入框配置。此指针仅在回调执行期间有效，回调返回后该内存将被释放，不可再访问。开发者必须在回调内部完成所有设置操作，不得在回调外部继续使用此指针。 |

### OH_TextEditorProxy_InsertTextFunc()

```c
typedef void (*OH_TextEditorProxy_InsertTextFunc)(InputMethod_TextEditorProxy *textEditorProxy, const char16_t *text, size_t length)
```

**描述**

输入法应用插入文本时触发的回调函数。开发者需实现此函数，在函数中将text参数指定的文本内容插入到编辑框的光标位置。

使用场景：当输入法应用向编辑框插入文本时（如用户选择候选词、输入字符等），系统将自动调用此回调。此回调是输入法与编辑器交互的核心回调之一，必须实现。

使用后效果：回调执行后，编辑框应在光标位置插入指定文本，并更新文本内容和光标位置。

前置条件：须通过[OH_TextEditorProxy_SetInsertTextFunc](#oh_texteditorproxy_setinserttextfunc)将此回调设置到TextEditorProxy中，并通过Attach完成注册。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 输入指针，指向当前被回调的TextEditorProxy实例。 |
| const char16_t *text | 输入指针，插入的文本内容，采用UTF-16编码。此指针仅在回调执行期间有效，回调返回后该内存将被释放，不可再访问。开发者应在回调内部完成必要的数据拷贝或处理。 |
| size_t length | 输入参数，插入字符的数量（单位：char16_t字符个数）。取值范围：大于0。 |

### OH_TextEditorProxy_DeleteForwardFunc()

```c
typedef void (*OH_TextEditorProxy_DeleteForwardFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t length)
```

**描述**

输入法删除光标右侧文本时触发的回调函数。开发者需实现此函数，在函数中从光标位置向右删除指定数量的字符。

使用场景：当输入法应用请求删除光标右侧文本时（如用户在输入法中执行向前删除操作），系统将自动调用此回调。

使用后效果：回调执行后，编辑框应从光标位置向右删除指定数量的字符，并更新文本内容和光标位置。

前置条件：须通过[OH_TextEditorProxy_SetDeleteForwardFunc](#oh_texteditorproxy_setdeleteforwardfunc)将此回调设置到TextEditorProxy中，并通过Attach完成注册。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 输入指针，指向当前被回调的TextEditorProxy实例。 |
| int32_t length | 输入参数，要删除的字符数量（单位：字符个数）。取值范围：大于0且不超过光标右侧剩余文本长度。取值原则：若length超过右侧剩余文本长度，应删除到文本末尾。 |

### OH_TextEditorProxy_DeleteBackwardFunc()

```c
typedef void (*OH_TextEditorProxy_DeleteBackwardFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t length)
```

**描述**

输入法删除光标左侧文本时触发的回调函数。开发者需实现此函数，在函数中从光标位置向左删除指定数量的字符。

使用场景：当输入法应用请求删除光标左侧文本时（如用户在输入法中执行退格删除操作），系统将自动调用此回调。

使用后效果：回调执行后，编辑框应从光标位置向左删除指定数量的字符，并更新文本内容和光标位置。

前置条件：须通过[OH_TextEditorProxy_SetDeleteBackwardFunc](#oh_texteditorproxy_setdeletebackwardfunc)将此回调设置到TextEditorProxy中，并通过Attach完成注册。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 输入指针，指向当前被回调的TextEditorProxy实例。 |
| int32_t length | 输入参数，要删除的字符数量（单位：字符个数）。取值范围：大于0且不超过光标左侧已有文本长度。取值原则：若length超过左侧已有文本长度，应删除到文本开头。 |

### OH_TextEditorProxy_SendKeyboardStatusFunc()

```c
typedef void (*OH_TextEditorProxy_SendKeyboardStatusFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_KeyboardStatus keyboardStatus)
```

**描述**

输入法通知键盘状态时触发的回调函数。开发者需实现此函数，在函数中根据keyboardStatus参数更新编辑框对键盘状态的感知。

使用场景：当输入法应用的键盘状态发生变化（显示或隐藏）时，系统将自动调用此回调，通知编辑框当前的键盘状态。

使用后效果：回调执行后，编辑框应据此更新对键盘可见性的感知，例如调整避让策略或UI布局。

前置条件：须通过[OH_TextEditorProxy_SetSendKeyboardStatusFunc](#oh_texteditorproxy_setsendkeyboardstatusfunc)将此回调设置到TextEditorProxy中，并通过Attach完成注册。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 输入指针，指向当前被回调的TextEditorProxy实例。 |
| [InputMethod_KeyboardStatus](capi-inputmethod-types-capi-h.md#inputmethod_keyboardstatus) keyboardStatus | 输入参数，键盘状态。取值范围：[InputMethod_KeyboardStatus](capi-inputmethod-types-capi-h.md#inputmethod_keyboardstatus)枚举值（IME_KEYBOARD_NONE=0、IME_KEYBOARD_SHOW=1、IME_KEYBOARD_HIDE=2）。使用后效果：设置为IME_KEYBOARD_SHOW时表示键盘已弹出，IME_KEYBOARD_HIDE时表示键盘已收起。 |

### OH_TextEditorProxy_SendEnterKeyFunc()

```c
typedef void (*OH_TextEditorProxy_SendEnterKeyFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_EnterKeyType enterKeyType)
```

**描述**

输入法发送回车键时触发的回调函数。开发者需实现此函数，在函数中根据enterKeyType参数执行对应的回车键动作。

使用场景：当输入法应用通知编辑框回车键事件时，系统将自动调用此回调。

使用后效果：回调执行后，编辑框应据此执行对应的回车键行为（如搜索、发送、完成等）。

前置条件：须通过[OH_TextEditorProxy_SetSendEnterKeyFunc](#oh_texteditorproxy_setsendenterkeyfunc)将此回调设置到TextEditorProxy中，并通过Attach完成注册。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 输入指针，指向当前被回调的TextEditorProxy实例。 |
| [InputMethod_EnterKeyType](capi-inputmethod-types-capi-h.md#inputmethod_enterkeytype) enterKeyType | 输入参数，回车键类型。取值范围：[InputMethod_EnterKeyType](capi-inputmethod-types-capi-h.md#inputmethod_enterkeytype)枚举值。使用后效果：不同类型对应不同的回车键行为，如IME_ENTER_KEY_GO表示"前往"、IME_ENTER_KEY_SEARCH表示"搜索"等。 |

### OH_TextEditorProxy_MoveCursorFunc()

```c
typedef void (*OH_TextEditorProxy_MoveCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_Direction direction)
```

**描述**

输入法移动光标时触发的回调函数。开发者需实现此函数，在函数中根据direction参数移动编辑框中的光标位置。

使用场景：当输入法应用请求移动光标时，系统将自动调用此回调。

使用后效果：回调执行后，编辑框应据此移动光标位置，并更新光标显示。

前置条件：须通过[OH_TextEditorProxy_SetMoveCursorFunc](#oh_texteditorproxy_setmovecursorfunc)将此回调设置到TextEditorProxy中，并通过Attach完成注册。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 输入指针，指向当前被回调的TextEditorProxy实例。 |
| [InputMethod_Direction](capi-inputmethod-types-capi-h.md#inputmethod_direction) direction | 输入参数，光标移动方向。取值范围：[InputMethod_Direction](capi-inputmethod-types-capi-h.md#inputmethod_direction)枚举值。使用后效果：不同方向对应不同的光标移动行为，如IME_DIRECTION_UP表示上移、IME_DIRECTION_DOWN表示下移、IME_DIRECTION_LEFT表示左移、IME_DIRECTION_RIGHT表示右移。 |

### OH_TextEditorProxy_HandleSetSelectionFunc()

```c
typedef void (*OH_TextEditorProxy_HandleSetSelectionFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t start, int32_t end)
```

**描述**

输入法请求选中文本时触发的回调函数。开发者需实现此函数，在函数中根据start和end参数选中编辑框中的指定范围文本。

使用场景：当输入法应用请求选中编辑框中一段文本时，系统将自动调用此回调。

使用后效果：回调执行后，编辑框应将start到end范围内的文本选中，并更新选中状态和UI显示。

前置条件：须通过[OH_TextEditorProxy_SetHandleSetSelectionFunc](#oh_texteditorproxy_sethandlesetselectionfunc)将此回调设置到TextEditorProxy中，并通过Attach完成注册。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 输入指针，指向当前被回调的TextEditorProxy实例。 |
| int32_t start | 输入参数，选中文本的起始位置（单位：字符偏移量，从0开始计数）。取值原则：start应大于等于0且小于等于end。 |
| int32_t end | 输入参数，选中文本的结束位置（单位：字符偏移量，从0开始计数）。取值原则：end应大于等于start且小于文本总长度。 |

### OH_TextEditorProxy_HandleExtendActionFunc()

```c
typedef void (*OH_TextEditorProxy_HandleExtendActionFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_ExtendAction action)
```

**描述**

输入法发送扩展编辑操作时触发的回调函数。开发者需实现此函数，在函数中根据action参数执行对应的扩展编辑操作。

使用场景：当输入法应用请求执行扩展编辑操作（如剪切、复制、全选等）时，系统将自动调用此回调。

使用后效果：回调执行后，编辑框应据此执行对应的扩展编辑动作。

前置条件：须通过[OH_TextEditorProxy_SetHandleExtendActionFunc](#oh_texteditorproxy_sethandleextendactionfunc)将此回调设置到TextEditorProxy中，并通过Attach完成注册。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 输入指针，指向当前被回调的TextEditorProxy实例。 |
| [InputMethod_ExtendAction](capi-inputmethod-types-capi-h.md#inputmethod_extendaction) action | 输入参数，扩展编辑操作。取值范围：[InputMethod_ExtendAction](capi-inputmethod-types-capi-h.md#inputmethod_extendaction)枚举值。使用后效果：不同操作对应不同的编辑行为，如IME_EXTEND_ACTION_SELECT_ALL表示全选、IME_EXTEND_ACTION_CUT表示剪切、IME_EXTEND_ACTION_COPY表示复制等。 |

### OH_TextEditorProxy_GetLeftTextOfCursorFunc()

```c
typedef void (*OH_TextEditorProxy_GetLeftTextOfCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t number, char16_t text[], size_t *length)
```

**描述**

输入法获取光标左侧文本时触发的回调函数。开发者需实现此函数，在函数中将光标左侧指定数量的文本内容写入text参数，并将实际字符数量写入length参数。

使用场景：当输入法应用需要获取光标左侧的文本内容（如用于联想输入、上下文分析等）时，系统将自动调用此回调。

使用后效果：回调返回后，输入法应用将读取text和length中的数据用于上下文分析。

前置条件：须通过[OH_TextEditorProxy_SetGetLeftTextOfCursorFunc](#oh_texteditorproxy_setgetlefttextofcursorfunc)将此回调设置到TextEditorProxy中，并通过Attach完成注册。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 输入指针，指向当前被回调的TextEditorProxy实例。 |
| int32_t number | 输入参数，要获取的字符数量（单位：字符个数）。取值范围：大于0。取值原则：若number超过光标左侧已有文本长度，应返回左侧全部文本。 |
| char16_t text[] | 输出指针，光标左侧指定长度的文本内容，需要在函数实现中对它赋值。采用UTF-16编码。此指针仅在回调执行期间有效，回调返回后该内存将被释放，不可再访问。开发者需在回调内部完成赋值操作。 |
| size_t *length | 输出指针，用于返回实际获取到的字符数量（单位：char16_t字符个数）。由调用者（输入法框架）分配内存，开发者需在回调内部对*length赋值。 |

### OH_TextEditorProxy_GetRightTextOfCursorFunc()

```c
typedef void (*OH_TextEditorProxy_GetRightTextOfCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy, int32_t number, char16_t text[], size_t *length)
```

**描述**

输入法获取光标右侧文本时触发的回调函数。开发者需实现此函数，在函数中将光标右侧指定数量的文本内容写入text参数，并将实际字符数量写入length参数。

使用场景：当输入法应用需要获取光标右侧的文本内容时，系统将自动调用此回调。

使用后效果：回调返回后，输入法应用将读取text和length中的数据用于上下文分析。

前置条件：须通过[OH_TextEditorProxy_SetGetRightTextOfCursorFunc](#oh_texteditorproxy_setgetrighttextofcursorfunc)将此回调设置到TextEditorProxy中，并通过Attach完成注册。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 输入指针，指向当前被回调的TextEditorProxy实例。 |
| int32_t number | 输入参数，要获取的字符数量（单位：字符个数）。取值范围：大于0。 |
| char16_t text[] | 输出指针，光标右侧指定长度的文本内容，需要在函数实现中对它赋值。采用UTF-16编码。此指针仅在回调执行期间有效，回调返回后该内存将被释放，不可再访问。 |
| size_t *length | 输出指针，用于返回实际获取到的字符数量（单位：char16_t字符个数）。由调用者分配内存，开发者需在回调内部对*length赋值。 |

### OH_TextEditorProxy_GetTextIndexAtCursorFunc()

```c
typedef int32_t (*OH_TextEditorProxy_GetTextIndexAtCursorFunc)(InputMethod_TextEditorProxy *textEditorProxy)
```

**描述**

输入法获取光标所在输入框文本索引时触发的回调函数。开发者需实现此函数，在函数中返回光标在编辑框文本中的字符索引位置。

使用场景：当输入法应用需要获取光标在文本中的精确位置时，系统将自动调用此回调。

使用后效果：回调返回后，输入法应用将读取返回的索引值用于定位上下文。

前置条件：须通过[OH_TextEditorProxy_SetGetTextIndexAtCursorFunc](#oh_texteditorproxy_setgettextindexatcursorfunc)将此回调设置到TextEditorProxy中，并通过Attach完成注册。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 输入指针，指向当前被回调的TextEditorProxy实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回光标在文本内容中的字符索引位置，索引从0开始计数（单位：字符偏移量）。取值范围：大于等于0且小于文本总长度。 |

### OH_TextEditorProxy_ReceivePrivateCommandFunc()

```c
typedef int32_t (*OH_TextEditorProxy_ReceivePrivateCommandFunc)(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_PrivateCommand *privateCommand[], size_t size)
```

**描述**

输入法应用发送私有数据命令时触发的回调函数。开发者需实现此函数，在函数中处理输入法应用发送的私有命令数据。

使用场景：当输入法应用通过[OH_InputMethodProxy_SendPrivateCommand](capi-inputmethod-inputmethod-proxy-capi-h.md#oh_inputmethodproxy_sendprivatecommand)向编辑框发送私有命令时，系统将自动调用此回调。

使用后效果：回调返回后，输入法应用将根据返回值判断命令是否被成功处理。

前置条件：须通过[OH_TextEditorProxy_SetReceivePrivateCommandFunc](#oh_texteditorproxy_setreceiveprivatecommandfunc)将此回调设置到TextEditorProxy中，并通过Attach完成注册。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 输入指针，指向当前被回调的TextEditorProxy实例。 |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *privateCommand[] | 输入指针，私有数据命令数组。此指针仅在回调执行期间有效，回调返回后该内存将被释放，不可再访问。开发者应在回调内部完成必要的数据拷贝或处理，不得在回调外部继续使用此指针。 |
| size_t size | 输入参数，私有数据命令数组中的元素数量。取值范围：大于0且不超过5。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回对私有数据命令的处理结果。0表示成功，非0表示失败。 |

### OH_TextEditorProxy_SetPreviewTextFunc()

```c
typedef int32_t (*OH_TextEditorProxy_SetPreviewTextFunc)(InputMethod_TextEditorProxy *textEditorProxy, const char16_t text[], size_t length, int32_t start, int32_t end)
```

**描述**

输入法设置预上屏文本时触发的回调函数。预上屏是输入法的候选文本展示功能，通常在用户输入拼音或输入码未确定汉字时显示。此函数负责设置预上屏文本及其光标位置。与[OH_TextEditorProxy_FinishTextPreviewFunc](#oh_texteditorproxy_finishtextpreviewfunc)配合使用：先调用SetPreviewTextFunc设置预上屏内容，当用户选择候选词或取消输入时，调用FinishTextPreviewFunc结束预上屏。

使用场景：当输入法应用需要展示候选文本（如拼音输入时的预上屏文本）时，系统将自动调用此回调。

使用后效果：回调执行后，编辑框应将text内容以预上屏样式显示在start到end范围内，并将返回值反馈给输入法。

前置条件：须通过[OH_TextEditorProxy_SetSetPreviewTextFunc](#oh_texteditorproxy_setsetpreviewtextfunc)将此回调设置到TextEditorProxy中，并通过Attach完成注册。编辑框需在TextConfig中设置支持预上屏（supported=true）。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 输入指针，指向当前被回调的TextEditorProxy实例。 |
| const char16_t text[] | 输入指针，请求设置为预上屏样式的文本内容，采用UTF-16编码。此指针仅在回调执行期间有效，回调返回后该内存将被释放，不可再访问。开发者应在回调内部完成必要的数据拷贝。 |
| size_t length | 输入参数，预上屏文本的字符数量（单位：char16_t字符个数）。 |
| int32_t start | 输入参数，预上屏文本起始光标位置（单位：字符偏移量，相对于文本开头）。 |
| int32_t end | 输入参数，预上屏文本结束光标位置（单位：字符偏移量，相对于文本开头）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回处理结果。0表示成功，非0表示失败。 |

### OH_TextEditorProxy_FinishTextPreviewFunc()

```c
typedef void (*OH_TextEditorProxy_FinishTextPreviewFunc)(InputMethod_TextEditorProxy *textEditorProxy)
```

**描述**

输入法结束预上屏时触发的回调函数。此函数用于清理预上屏状态，通常在用户选择候选词（确定输入）或取消输入时调用。与[OH_TextEditorProxy_SetPreviewTextFunc](#oh_texteditorproxy_setpreviewtextfunc)配合使用。

使用场景：当输入法应用需要结束预上屏状态时，系统将自动调用此回调。

使用后效果：回调执行后，编辑框应清理预上屏显示状态，恢复到正常文本显示。

前置条件：须通过[OH_TextEditorProxy_SetFinishTextPreviewFunc](#oh_texteditorproxy_setfinishtextpreviewfunc)将此回调设置到TextEditorProxy中，并通过Attach完成注册。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | 输入指针，指向当前被回调的TextEditorProxy实例。 |

### OH_TextEditorProxy_Create()

```c
InputMethod_TextEditorProxy *OH_TextEditorProxy_Create(void)
```

**描述**

创建一个新的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例。创建后需通过Set*Func接口注册回调函数，再通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)完成绑定注册。

使用场景：当应用需要创建文本编辑器代理对象以接收输入法请求和通知时调用此函数。

使用后效果：创建成功后返回一个新的TextEditorProxy实例指针，后续可通过Set*Func接口注册回调函数。

生命周期管理：返回的对象必须通过[OH_TextEditorProxy_Destroy](#oh_texteditorproxy_destroy)销毁，Create与Destroy必须配对使用。未销毁会导致内存泄漏。同一个实例只能被销毁一次。

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) * | 如果创建成功，返回一个指向新创建的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。如果创建失败，返回NULL，可能的失败原因有内存不足。返回NULL时应检查系统内存状态。返回的指针在使用完毕后必须通过[OH_TextEditorProxy_Destroy](#oh_texteditorproxy_destroy)销毁，销毁后指针应设置为NULL避免误用。 |

### OH_TextEditorProxy_Destroy()

```c
void OH_TextEditorProxy_Destroy(InputMethod_TextEditorProxy *proxy)
```

**描述**

销毁一个[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例。销毁后proxy指针不可再使用，建议将指针设置为NULL避免误用。

使用场景：当应用不再需要TextEditorProxy对象时（如Detach后或应用退出时）调用此函数释放资源。

使用后效果：proxy对象将被释放，其内部资源被回收，此后不可再通过proxy指针调用任何函数。

生命周期管理：与[OH_TextEditorProxy_Create](#oh_texteditorproxy_create)配对使用，Create返回的对象必须最终通过Destroy释放。同一个实例只能被销毁一次，不可重复销毁。若proxy为NULL，函数不做任何处理。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，表示指向即将被销毁的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。若传入NULL，函数不做任何处理，不会导致崩溃。销毁后该指针失效，建议设置为NULL。 |

### OH_TextEditorProxy_SetGetTextConfigFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_SetGetTextConfigFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextConfigFunc getTextConfigFunc)
```

**描述**

将函数[OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。此设置须在Attach之前完成，Attach后设置的回调不会被输入法调用。

使用场景：当应用需要注册GetTextConfigFunc回调以响应输入法获取配置请求时调用此函数。

使用后效果：设置成功后，GetTextConfigFunc回调将被注册到TextEditorProxy中，Attach后当输入法请求获取配置时将自动触发此回调。

前置条件：proxy须先通过[OH_TextEditorProxy_Create](#oh_texteditorproxy_create)创建。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向即将被设置的[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)实例的指针。不可为NULL，若传入NULL将返回IME_ERR_NULL_POINTER。 |
| [OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc) getTextConfigFunc | 输入参数，表示被设置到proxy的回调函数[OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc)。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，proxy或getTextConfigFunc为NULL。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetInsertTextFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_SetInsertTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_InsertTextFunc insertTextFunc)
```

**描述**

将函数[OH_TextEditorProxy_InsertTextFunc](#oh_texteditorproxy_inserttextfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。此设置须在Attach之前完成。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向即将被设置的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_InsertTextFunc](#oh_texteditorproxy_inserttextfunc) insertTextFunc | 输入参数，表示被设置到proxy的回调函数。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetDeleteForwardFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_SetDeleteForwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteForwardFunc deleteForwardFunc)
```

**描述**

将函数[OH_TextEditorProxy_DeleteForwardFunc](#oh_texteditorproxy_deleteforwardfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。此设置须在Attach之前完成。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向即将被设置的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_DeleteForwardFunc](#oh_texteditorproxy_deleteforwardfunc) deleteForwardFunc | 输入参数，表示被设置到proxy的回调函数。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetDeleteBackwardFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_SetDeleteBackwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteBackwardFunc deleteBackwardFunc)
```

**描述**

将函数[OH_TextEditorProxy_DeleteBackwardFunc](#oh_texteditorproxy_deletebackwardfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。此设置须在Attach之前完成。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向即将被设置的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_DeleteBackwardFunc](#oh_texteditorproxy_deletebackwardfunc) deleteBackwardFunc | 输入参数，表示被设置到proxy的回调函数。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetSendKeyboardStatusFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_SetSendKeyboardStatusFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendKeyboardStatusFunc sendKeyboardStatusFunc)
```

**描述**

将函数[OH_TextEditorProxy_SendKeyboardStatusFunc](#oh_texteditorproxy_sendkeyboardstatusfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。此设置须在Attach之前完成。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向即将被设置的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_SendKeyboardStatusFunc](#oh_texteditorproxy_sendkeyboardstatusfunc) sendKeyboardStatusFunc | 输入参数，表示被设置到proxy的回调函数。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetSendEnterKeyFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_SetSendEnterKeyFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendEnterKeyFunc sendEnterKeyFunc)
```

**描述**

将函数[OH_TextEditorProxy_SendEnterKeyFunc](#oh_texteditorproxy_sendenterkeyfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。此设置须在Attach之前完成。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向即将被设置的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_SendEnterKeyFunc](#oh_texteditorproxy_sendenterkeyfunc) sendEnterKeyFunc | 输入参数，表示被设置到proxy的回调函数。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetMoveCursorFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_SetMoveCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_MoveCursorFunc moveCursorFunc)
```

**描述**

将函数[OH_TextEditorProxy_MoveCursorFunc](#oh_texteditorproxy_movecursorfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。此设置须在Attach之前完成。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向即将被设置的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_MoveCursorFunc](#oh_texteditorproxy_movecursorfunc) moveCursorFunc | 输入参数，表示被设置到proxy的回调函数。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetHandleSetSelectionFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_SetHandleSetSelectionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleSetSelectionFunc handleSetSelectionFunc)
```

**描述**

将函数[OH_TextEditorProxy_HandleSetSelectionFunc](#oh_texteditorproxy_handlesetselectionfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。此设置须在Attach之前完成。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向即将被设置的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_HandleSetSelectionFunc](#oh_texteditorproxy_handlesetselectionfunc) handleSetSelectionFunc | 输入参数，表示被设置到proxy的回调函数。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetHandleExtendActionFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_SetHandleExtendActionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleExtendActionFunc handleExtendActionFunc)
```

**描述**

将函数[OH_TextEditorProxy_HandleExtendActionFunc](#oh_texteditorproxy_handleextendactionfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。此设置须在Attach之前完成。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向即将被设置的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_HandleExtendActionFunc](#oh_texteditorproxy_handleextendactionfunc) handleExtendActionFunc | 输入参数，表示被设置到proxy的回调函数。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetGetLeftTextOfCursorFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_SetGetLeftTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetLeftTextOfCursorFunc getLeftTextOfCursorFunc)
```

**描述**

将函数[OH_TextEditorProxy_GetLeftTextOfCursorFunc](#oh_texteditorproxy_getlefttextofcursorfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。此设置须在Attach之前完成。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向即将被设置的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_GetLeftTextOfCursorFunc](#oh_texteditorproxy_getlefttextofcursorfunc) getLeftTextOfCursorFunc | 输入参数，表示被设置到proxy的回调函数。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetGetRightTextOfCursorFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_SetGetRightTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetRightTextOfCursorFunc getRightTextOfCursorFunc)
```

**描述**

将函数[OH_TextEditorProxy_GetRightTextOfCursorFunc](#oh_texteditorproxy_getrighttextofcursorfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。此设置须在Attach之前完成。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向即将被设置的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_GetRightTextOfCursorFunc](#oh_texteditorproxy_getrighttextofcursorfunc) getRightTextOfCursorFunc | 输入参数，表示被设置到proxy的回调函数。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetGetTextIndexAtCursorFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_SetGetTextIndexAtCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextIndexAtCursorFunc getTextIndexAtCursorFunc)
```

**描述**

将函数[OH_TextEditorProxy_GetTextIndexAtCursorFunc](#oh_texteditorproxy_gettextindexatcursorfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。此设置须在Attach之前完成。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向即将被设置的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_GetTextIndexAtCursorFunc](#oh_texteditorproxy_gettextindexatcursorfunc) getTextIndexAtCursorFunc | 输入参数，表示被设置到proxy的回调函数。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetReceivePrivateCommandFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_SetReceivePrivateCommandFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_ReceivePrivateCommandFunc receivePrivateCommandFunc)
```

**描述**

将函数[OH_TextEditorProxy_ReceivePrivateCommandFunc](#oh_texteditorproxy_receiveprivatecommandfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。此设置须在Attach之前完成。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向即将被设置的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_ReceivePrivateCommandFunc](#oh_texteditorproxy_receiveprivatecommandfunc) receivePrivateCommandFunc | 输入参数，表示被设置到proxy的回调函数。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetSetPreviewTextFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_SetSetPreviewTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SetPreviewTextFunc setPreviewTextFunc)
```

**描述**

将函数[OH_TextEditorProxy_SetPreviewTextFunc](#oh_texteditorproxy_setpreviewtextfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。此设置须在Attach之前完成。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向即将被设置的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_SetPreviewTextFunc](#oh_texteditorproxy_setpreviewtextfunc) setPreviewTextFunc | 输入参数，表示被设置到proxy的回调函数。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetFinishTextPreviewFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_SetFinishTextPreviewFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_FinishTextPreviewFunc finishTextPreviewFunc)
```

**描述**

将函数[OH_TextEditorProxy_FinishTextPreviewFunc](#oh_texteditorproxy_finishtextpreviewfunc)设置到[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中。此设置须在Attach之前完成。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向即将被设置的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_FinishTextPreviewFunc](#oh_texteditorproxy_finishtextpreviewfunc) finishTextPreviewFunc | 输入参数，表示被设置到proxy的回调函数。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetGetTextConfigFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_GetGetTextConfigFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextConfigFunc *getTextConfigFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc)函数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向被读取的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc) *getTextConfigFunc | 输出指针，表示从proxy获取到的函数指针。由调用者分配内存，函数将把回调函数指针写入此地址。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，proxy或getTextConfigFunc为NULL。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetInsertTextFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_GetInsertTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_InsertTextFunc *insertTextFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_InsertTextFunc](#oh_texteditorproxy_inserttextfunc)函数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向被读取的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_InsertTextFunc](#oh_texteditorproxy_inserttextfunc) *insertTextFunc | 输出指针，表示从proxy获取到的函数指针。由调用者分配内存。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetDeleteForwardFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_GetDeleteForwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteForwardFunc *deleteForwardFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_DeleteForwardFunc](#oh_texteditorproxy_deleteforwardfunc)函数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向被读取的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_DeleteForwardFunc](#oh_texteditorproxy_deleteforwardfunc) *deleteForwardFunc | 输出指针，表示从proxy获取到的函数指针。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetDeleteBackwardFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_GetDeleteBackwardFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_DeleteBackwardFunc *deleteBackwardFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_DeleteBackwardFunc](#oh_texteditorproxy_deletebackwardfunc)函数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向被读取的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_DeleteBackwardFunc](#oh_texteditorproxy_deletebackwardfunc) *deleteBackwardFunc | 输出指针，表示从proxy获取到的函数指针。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetSendKeyboardStatusFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_GetSendKeyboardStatusFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendKeyboardStatusFunc *sendKeyboardStatusFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_SendKeyboardStatusFunc](#oh_texteditorproxy_sendkeyboardstatusfunc)函数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向被读取的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_SendKeyboardStatusFunc](#oh_texteditorproxy_sendkeyboardstatusfunc) *sendKeyboardStatusFunc | 输出指针，表示从proxy获取到的函数指针。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetSendEnterKeyFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_GetSendEnterKeyFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SendEnterKeyFunc *sendEnterKeyFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_SendEnterKeyFunc](#oh_texteditorproxy_sendenterkeyfunc)函数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向被读取的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_SendEnterKeyFunc](#oh_texteditorproxy_sendenterkeyfunc) *sendEnterKeyFunc | 输出指针，表示从proxy获取到的函数指针。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetMoveCursorFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_GetMoveCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_MoveCursorFunc *moveCursorFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_MoveCursorFunc](#oh_texteditorproxy_movecursorfunc)函数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向被读取的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_MoveCursorFunc](#oh_texteditorproxy_movecursorfunc) *moveCursorFunc | 输出指针，表示从proxy获取到的函数指针。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetHandleSetSelectionFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_GetHandleSetSelectionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleSetSelectionFunc *handleSetSelectionFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_HandleSetSelectionFunc](#oh_texteditorproxy_handlesetselectionfunc)函数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向被读取的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_HandleSetSelectionFunc](#oh_texteditorproxy_handlesetselectionfunc) *handleSetSelectionFunc | 输出指针，表示从proxy获取到的函数指针。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetHandleExtendActionFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_GetHandleExtendActionFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_HandleExtendActionFunc *handleExtendActionFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_HandleExtendActionFunc](#oh_texteditorproxy_handleextendactionfunc)函数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向被读取的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_HandleExtendActionFunc](#oh_texteditorproxy_handleextendactionfunc) *handleExtendActionFunc | 输出指针，表示从proxy获取到的函数指针。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetGetLeftTextOfCursorFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_GetGetLeftTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetLeftTextOfCursorFunc *getLeftTextOfCursorFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_GetLeftTextOfCursorFunc](#oh_texteditorproxy_getlefttextofcursorfunc)函数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向被读取的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_GetLeftTextOfCursorFunc](#oh_texteditorproxy_getlefttextofcursorfunc) *getLeftTextOfCursorFunc | 输出指针，表示从proxy获取到的函数指针。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetGetRightTextOfCursorFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_GetGetRightTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetRightTextOfCursorFunc *getRightTextOfCursorFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_GetRightTextOfCursorFunc](#oh_texteditorproxy_getrighttextofcursorfunc)函数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向被读取的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_GetRightTextOfCursorFunc](#oh_texteditorproxy_getrighttextofcursorfunc) *getRightTextOfCursorFunc | 输出指针，表示从proxy获取到的函数指针。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetGetTextIndexAtCursorFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_GetGetTextIndexAtCursorFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_GetTextIndexAtCursorFunc *getTextIndexAtCursorFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_GetTextIndexAtCursorFunc](#oh_texteditorproxy_gettextindexatcursorfunc)函数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向被读取的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_GetTextIndexAtCursorFunc](#oh_texteditorproxy_gettextindexatcursorfunc) *getTextIndexAtCursorFunc | 输出指针，表示从proxy获取到的函数指针。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetReceivePrivateCommandFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_GetReceivePrivateCommandFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_ReceivePrivateCommandFunc *receivePrivateCommandFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_ReceivePrivateCommandFunc](#oh_texteditorproxy_receiveprivatecommandfunc)函数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向被读取的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_ReceivePrivateCommandFunc](#oh_texteditorproxy_receiveprivatecommandfunc) *receivePrivateCommandFunc | 输出指针，表示从proxy获取到的函数指针。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetSetPreviewTextFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_GetSetPreviewTextFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_SetPreviewTextFunc *setPreviewTextFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_SetPreviewTextFunc](#oh_texteditorproxy_setpreviewtextfunc)函数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向被读取的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_SetPreviewTextFunc](#oh_texteditorproxy_setpreviewtextfunc) *setPreviewTextFunc | 输出指针，表示从proxy获取到的函数指针。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_GetFinishTextPreviewFunc()

```c
InputMethod_ErrorCode OH_TextEditorProxy_GetFinishTextPreviewFunc(InputMethod_TextEditorProxy *proxy, OH_TextEditorProxy_FinishTextPreviewFunc *finishTextPreviewFunc)
```

**描述**

从[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)中获取[OH_TextEditorProxy_FinishTextPreviewFunc](#oh_texteditorproxy_finishtextpreviewfunc)函数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向被读取的TextEditorProxy实例的指针。不可为NULL。 |
| [OH_TextEditorProxy_FinishTextPreviewFunc](#oh_texteditorproxy_finishtextpreviewfunc) *finishTextPreviewFunc | 输出指针，表示从proxy获取到的函数指针。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextEditorProxy_SetCallbackInMainThread()

```c
InputMethod_ErrorCode OH_TextEditorProxy_SetCallbackInMainThread(InputMethod_TextEditorProxy *proxy, bool isCallbackInMainThread)
```

**描述**

为InputMethod_TextEditorProxy的回调函数配置执行线程（主线程/IPC线程）。本接口仅控制InputMethod_TextEditorProxy中除[OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc)之外的所有回调函数。[OH_TextEditorProxy_GetTextConfigFunc](#oh_texteditorproxy_gettextconfigfunc)的执行线程由调用[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)的线程决定，不受本接口影响。若需GetTextConfigFunc也在主线程执行，需确保Attach在主线程调用。

使用场景：当应用需要避免多线程并发问题时，可将回调切换到主线程执行；当应用对回调响应速度要求较高时，可保持IPC线程执行。

使用后效果：设置为true后，除GetTextConfigFunc外的所有回调将在主线程执行，避免多线程并发但需注意避免在回调内执行耗时操作；设置为false后，回调在IPC线程执行，响应更快但可能存在并发问题。

前置条件：proxy须先通过[OH_TextEditorProxy_Create](#oh_texteditorproxy_create)创建。建议在Attach之前调用此接口配置线程策略。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *proxy | 输入指针，指向目标InputMethod_TextEditorProxy实例的指针。不可为NULL，若传入NULL将返回IME_ERR_NULL_POINTER。 |
| bool isCallbackInMainThread | 输入参数，线程执行策略。取值范围：true或false。取值原则：true-回调函数切换至主线程执行（用于避免多线程并发问题），避免在回调内执行耗时操作防止主线程阻塞；false-回调函数在IPC线程执行（可能存在多线程并发情况），响应速度更快。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 配置成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 当proxy为NULL时返回。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |
