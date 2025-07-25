# inputmethod_attach_options_capi.h

## 概述

提供输入法绑定选项对象的创建、销毁与读写方法。

**引用文件：** <inputmethod/inputmethod_attach_options_capi.h>

**库：** libohinputmethod.so

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**起始版本：** 12

**相关模块：** [InputMethod](capi-inputmethod.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) | InputMethod_AttachOptions | 输入法绑定选项。绑定输入法时携带的选项。 |

### 函数

| 名称 | 描述                                             |
| -- |------------------------------------------------|
| [InputMethod_AttachOptions *OH_AttachOptions_Create(bool showKeyboard)](#oh_attachoptions_create) | 创建一个新的[InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md)实例。     |
| [InputMethod_AttachOptions *OH_AttachOptions_CreateWithRequestKeyboardReason(bool showKeyboard, InputMethod_RequestKeyboardReason requestKeyboardReason)](#oh_attachoptions_createwithrequestkeyboardreason) | 创建一个新的[InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md)实例。     |
| [void OH_AttachOptions_Destroy(InputMethod_AttachOptions *options)](#oh_attachoptions_destroy) | 销毁一个[InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md)实例。    |
| [InputMethod_ErrorCode OH_AttachOptions_IsShowKeyboard(InputMethod_AttachOptions *options, bool *showKeyboard)](#oh_attachoptions_isshowkeyboard) | 从[InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md)中获取是否显示键盘的值。 |
| [InputMethod_ErrorCode OH_AttachOptions_GetRequestKeyboardReason(InputMethod_AttachOptions *options, int *requestKeyboardReason)](#oh_attachoptions_getrequestkeyboardreason) | 从[InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md)中获取是否显示键盘的值。 |

## 函数说明

### OH_AttachOptions_Create()

```
InputMethod_AttachOptions *OH_AttachOptions_Create(bool showKeyboard)
```

**描述**

创建一个新的[InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md)实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| bool showKeyboard | 表示是否显示键盘。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) * | 如果创建成功，返回一个指向新创建的[InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md)实例的指针。<br> 如果创建失败，对象返回NULL，可能的失败原因有应用地址空间满。 |

### OH_AttachOptions_CreateWithRequestKeyboardReason()

```
InputMethod_AttachOptions *OH_AttachOptions_CreateWithRequestKeyboardReason(bool showKeyboard, InputMethod_RequestKeyboardReason requestKeyboardReason)
```

**描述**

创建一个新的[InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md)实例。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| bool showKeyboard | 表示是否显示键盘。 |
| [InputMethod_RequestKeyboardReason](capi-inputmethod-types-capi-h.md#inputmethod_requestkeyboardreason) requestKeyboardReason |  表示请求键盘输入原因。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) * | 如果创建成功，返回一个指向新创建的[InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md)实例的指针。<br> 如果创建失败，对象返回NULL，可能的失败原因有应用地址空间满。 |

### OH_AttachOptions_Destroy()

```
void OH_AttachOptions_Destroy(InputMethod_AttachOptions *options)
```

**描述**

销毁一个[InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md)实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) *options | 表示即将被销毁的[InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md)实例。 |

### OH_AttachOptions_IsShowKeyboard()

```
InputMethod_ErrorCode OH_AttachOptions_IsShowKeyboard(InputMethod_AttachOptions *options, bool *showKeyboard)
```

**描述**

从[InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md)中获取是否显示键盘的值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) *options | 表示被读取值的[InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md)实例。 |
| bool *showKeyboard | 表示绑定时是否显示键盘。true - 表示绑定完成时需要显示键盘。false - 表示绑定完成时不需要显示键盘。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_AttachOptions_GetRequestKeyboardReason()

```
InputMethod_ErrorCode OH_AttachOptions_GetRequestKeyboardReason(InputMethod_AttachOptions *options, int *requestKeyboardReason)
```

**描述**

从[InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md)中获取是否显示键盘的值。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) *options | 表示被读取值的[InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md)实例。 |
| int *requestKeyboardReason |  表示一个指向[InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md)实例的指针。该参数用于表示请求键盘输入原因。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |


