# InputMethod_InputMethodProxy
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->

```c
typedef struct InputMethod_InputMethodProxy InputMethod_InputMethodProxy
```

## 概述

应用与输入法服务之间的交互代理对象，应用可通过此对象调用输入法服务的相关接口，并接收输入法服务的事件回调。该结构体为不透明类型（opaque type），调用者不可直接访问其内部成员，仅可通过本模块提供的函数接口进行操作。

**起始版本：** 12

**相关模块：** [InputMethod（输入法模块）](capi-inputmethod.md)

**所在头文件：** [inputmethod_inputmethod_proxy_capi.h](capi-inputmethod-inputmethod-proxy-capi-h.md)

## 结构体用途

InputMethod_InputMethodProxy是应用端与输入法服务交互的核心代理对象，用于向输入法服务发送请求和通知。通过此代理对象，应用可以控制键盘的显示与隐藏、通知编辑框的文本选区变化和配置变化、更新光标位置、以及发送私有命令数据。

## 生命周期管理

- 创建方式：由[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)函数创建并作为输出参数返回，调用者不可手动创建此对象。
- 销毁方式：不可手动销毁。当调用[OH_InputMethodController_Detach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_detach)解除绑定后，InputMethod_InputMethodProxy对象将由系统自动释放并失效。
- 有效性：InputMethod_InputMethodProxy仅在Attach与Detach之间有效。Detach后，所有通过此对象调用的函数将返回IME_ERR_DETACHED错误码，不可再使用。
- 重复创建/销毁：不支持重复销毁。每次Attach会产生一个新的InputMethod_InputMethodProxy实例，对应的Detach会使其失效。

## 使用注意事项

- 调用任何InputMethod_InputMethodProxy相关函数前，必须确保已通过[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)成功获取该对象，且尚未调用Detach。
- inputMethodProxy指针不可为NULL，传入NULL指针将导致IME_ERR_NULL_POINTER错误码。示例：调用前未判空即调用函数时触发，应在调用前判断指针是否为NULL，若为NULL则先通过Attach获取有效对象或终止调用。
- Detach后不可再使用已获取的inputMethodProxy指针，所有操作将返回IME_ERR_DETACHED。Detach后不可再使用已获取的inputMethodProxy指针，所有操作将返回IME_ERR_DETACHED。示例：在Detach后调用任何接口时返回该码，应检查生命周期状态，仅在Attach与Detach之间使用该对象，否则重新Attach。此对象为不透明类型，不可直接访问内部成员或进行内存操作（如malloc/free）。
- 非线程安全，不建议在多线程环境下同时操作同一个inputMethodProxy对象，如需多线程访问请自行加锁保护。

相关函数：

以下为可通过InputMethod_InputMethodProxy对象调用的操作函数：

| 函数 | 描述 |
| -- | -- |
| [OH_InputMethodProxy_ShowKeyboard](capi-inputmethod-inputmethod-proxy-capi-h.md#oh_inputmethodproxy_showkeyboard) | 显示键盘。 |
| [OH_InputMethodProxy_ShowTextInput](capi-inputmethod-inputmethod-proxy-capi-h.md#oh_inputmethodproxy_showtextinput) | 显示文本输入框。 |
| [OH_InputMethodProxy_HideKeyboard](capi-inputmethod-inputmethod-proxy-capi-h.md#oh_inputmethodproxy_hidekeyboard) | 隐藏键盘。 |
| [OH_InputMethodProxy_NotifySelectionChange](capi-inputmethod-inputmethod-proxy-capi-h.md#oh_inputmethodproxy_notifyselectionchange) | 通知文本框选区变化。 |
| [OH_InputMethodProxy_NotifyConfigurationChange](capi-inputmethod-inputmethod-proxy-capi-h.md#oh_inputmethodproxy_notifyconfigurationchange) | 通知输入框配置变化。 |
| [OH_InputMethodProxy_NotifyCursorUpdate](capi-inputmethod-inputmethod-proxy-capi-h.md#oh_inputmethodproxy_notifycursorupdate) | 通知光标位置变化。 |
| [OH_InputMethodProxy_SendPrivateCommand](capi-inputmethod-inputmethod-proxy-capi-h.md#oh_inputmethodproxy_sendprivatecommand) | 发送私有数据命令。 |

关联关系:
- 与TextEditorProxy的关系：[InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md)负责接收输入法应用的请求和通知，InputMethod_InputMethodProxy负责向输入法服务发送请求和通知。两者在Attach时同时建立关联，构成双向通信通道。
- 与AttachOptions的关系：[InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md)在Attach时传入，用于配置绑定选项（如是否显示键盘、请求键盘原因等），Attach成功后生成InputMethod_InputMethodProxy实例。
