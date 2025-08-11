# inputmethod_inputmethod_proxy_capi.h
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @illybyy-->
<!--SE: @andeszhang-->
<!--TSE: @murphy1984-->

## 概述

提供使用输入法的方法，可以向输入法应用发送请求和通知。

**引用文件：** <inputmethod/inputmethod_inputmethod_proxy_capi.h>

**库：** libohinputmethod.so

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**起始版本：** 12

**相关模块：** [InputMethod](capi-inputmethod.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) | InputMethod_InputMethodProxy | 输入法代理对象。使用此对象可以用于调用使用输入法的方法。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [InputMethod_ErrorCode OH_InputMethodProxy_ShowKeyboard(InputMethod_InputMethodProxy *inputMethodProxy)](#oh_inputmethodproxy_showkeyboard) | 显示键盘。 |
| [InputMethod_ErrorCode OH_InputMethodProxy_ShowTextInput(InputMethod_InputMethodProxy *inputMethodProxy, InputMethod_AttachOptions *options)](#oh_inputmethodproxy_showtextinput) | 显示文本输入框。 |
| [InputMethod_ErrorCode OH_InputMethodProxy_HideKeyboard(InputMethod_InputMethodProxy *inputMethodProxy)](#oh_inputmethodproxy_hidekeyboard) | 隐藏键盘。 |
| [InputMethod_ErrorCode OH_InputMethodProxy_NotifySelectionChange(InputMethod_InputMethodProxy *inputMethodProxy, char16_t text[], size_t length, int start, int end)](#oh_inputmethodproxy_notifyselectionchange) | 通知文本框选区变化。当输入框内文本内容、光标位置或选中文本发生变化时，通过此接口将信息通知给输入法应用。 |
| [InputMethod_ErrorCode OH_InputMethodProxy_NotifyConfigurationChange(InputMethod_InputMethodProxy *inputMethodProxy,InputMethod_EnterKeyType enterKey, InputMethod_TextInputType textType)](#oh_inputmethodproxy_notifyconfigurationchange) | 通知输入框配置变化。 |
| [InputMethod_ErrorCode OH_InputMethodProxy_NotifyCursorUpdate(InputMethod_InputMethodProxy *inputMethodProxy, InputMethod_CursorInfo *cursorInfo)](#oh_inputmethodproxy_notifycursorupdate) | 通知光标位置变化。 |
| [InputMethod_ErrorCode OH_InputMethodProxy_SendPrivateCommand(InputMethod_InputMethodProxy *inputMethodProxy, InputMethod_PrivateCommand *privateCommand[], size_t size)](#oh_inputmethodproxy_sendprivatecommand) | 发送私有数据命令。 |

## 函数说明

### OH_InputMethodProxy_ShowKeyboard()

```
InputMethod_ErrorCode OH_InputMethodProxy_ShowKeyboard(InputMethod_InputMethodProxy *inputMethodProxy)
```

**描述**

显示键盘。

**起始版本：** 12


**参数：**

| 参数项                                                | 描述 |
|----------------------------------------------------| -- |
| [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) *inputMethodProxy | 表示指向[InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md)实例的指针。inputMethodProxy由调用[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_IMCLIENT](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 输入法客户端错误。<br>     [IME_ERR_IMMS](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 输入法服务错误。<br>     [IME_ERR_DETACHED](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 未绑定输入法。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_InputMethodProxy_ShowTextInput()

```
InputMethod_ErrorCode OH_InputMethodProxy_ShowTextInput(InputMethod_InputMethodProxy *inputMethodProxy, InputMethod_AttachOptions *options)
```

**描述**

显示文本输入框。

**起始版本：** 15


**参数：**

| 参数项                                                                                                | 描述                                                                                                                                                                                                                     |
|----------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) *inputMethodProxy | 表示指向[InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md)实例的指针。inputMethodProxy由调用[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)获取。                                                             |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) *options                                                             | 表示指向[InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md)实例的指针，用于获取配置选项。ShowKeyboard - 属性始终为true，不可更改，因此无需关注。[InputMethod_RequestKeyboardReason](capi-inputmethod-types-capi-h.md#inputmethod_requestkeyboardreason) - 表示请求键盘输入原因。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_IMCLIENT](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 输入法客户端错误。<br>     [IME_ERR_IMMS](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 输入法服务错误。<br>     [IME_ERR_DETACHED](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 未绑定输入法。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_InputMethodProxy_HideKeyboard()

```
InputMethod_ErrorCode OH_InputMethodProxy_HideKeyboard(InputMethod_InputMethodProxy *inputMethodProxy)
```

**描述**

隐藏键盘。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) *inputMethodProxy | 表示指向[InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md)实例的指针。inputMethodProxy由调用[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_IMCLIENT](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 输入法客户端错误。<br>     [IME_ERR_IMMS](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 输入法服务错误。<br>     [IME_ERR_DETACHED](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 未绑定输入法。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_InputMethodProxy_NotifySelectionChange()

```
InputMethod_ErrorCode OH_InputMethodProxy_NotifySelectionChange(InputMethod_InputMethodProxy *inputMethodProxy, char16_t text[], size_t length, int start, int end)
```

**描述**

通知文本框选区变化。当输入框内文本内容、光标位置或选中文本发生变化时，通过此接口将信息通知给输入法应用。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) *inputMethodProxy | 表示指向[InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md)实例的指针。inputMethodProxy由调用[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)获取。 |
| text | 整个输入文本。 |
| size_t length | text参数的长度。最大长度为8K。 |
| int start | 所选文本的起始位置。 |
| int end | 所选文本的结束位置。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_PARAMCHECK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示参数错误。<br>     [IME_ERR_IMCLIENT](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 输入法客户端错误。<br>     [IME_ERR_IMMS](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 输入法服务错误。<br>     [IME_ERR_DETACHED](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 未绑定输入法。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_InputMethodProxy_NotifyConfigurationChange()

```
InputMethod_ErrorCode OH_InputMethodProxy_NotifyConfigurationChange(InputMethod_InputMethodProxy *inputMethodProxy,InputMethod_EnterKeyType enterKey, InputMethod_TextInputType textType)
```

**描述**

通知输入框配置变化。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) *inputMethodProxy | 表示指向[InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md)实例的指针。inputMethodProxy由调用[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)获取。 |
| [InputMethod_EnterKeyType](capi-inputmethod-types-capi-h.md#inputmethod_enterkeytype) enterKey | 回车键类型。 |
| [InputMethod_TextInputType](capi-inputmethod-types-capi-h.md#inputmethod_textinputtype) textType | 输入框类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_PARAMCHECK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示参数错误。<br>     [IME_ERR_IMCLIENT](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 输入法客户端错误。<br>     [IME_ERR_IMMS](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 输入法服务错误。<br>     [IME_ERR_DETACHED](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 未绑定输入法。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_InputMethodProxy_NotifyCursorUpdate()

```
InputMethod_ErrorCode OH_InputMethodProxy_NotifyCursorUpdate(InputMethod_InputMethodProxy *inputMethodProxy, InputMethod_CursorInfo *cursorInfo)
```

**描述**

通知光标位置变化。

**起始版本：** 12


**参数：**

| 参数项                                                                                                | 描述 |
|----------------------------------------------------------------------------------------------------| -- |
| [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) *inputMethodProxy | 表示指向[InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md)实例的指针。inputMethodProxy由调用[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)获取。 |
| [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) *cursorInfo                                                             | 指向[InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md)实例的指针。表示光标信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_PARAMCHECK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示参数错误。<br>     [IME_ERR_IMCLIENT](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 输入法客户端错误。<br>     [IME_ERR_IMMS](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 输入法服务错误。<br>     [IME_ERR_DETACHED](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 未绑定输入法。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_InputMethodProxy_SendPrivateCommand()

```
InputMethod_ErrorCode OH_InputMethodProxy_SendPrivateCommand(InputMethod_InputMethodProxy *inputMethodProxy, InputMethod_PrivateCommand *privateCommand[], size_t size)
```

**描述**

发送私有数据命令。

**起始版本：** 12


**参数：**

| 参数项                                                                                                | 描述 |
|----------------------------------------------------------------------------------------------------| -- |
| [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) *inputMethodProxy | 表示指向[InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md)实例的指针。inputMethodProxy由调用[OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)获取。 |
| [nputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *privateCommand[]                                                    | 私有命令, 定义在[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)，最大大小为32KB。 |
| size_t size                                                                                        | 私有命令的大小. 最大大小为5。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_PARAMCHECK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示参数错误。<br>     [IME_ERR_IMCLIENT](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 输入法客户端错误。<br>     [IME_ERR_IMMS](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 输入法服务错误。<br>     [IME_ERR_DETACHED](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 未绑定输入法。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |


