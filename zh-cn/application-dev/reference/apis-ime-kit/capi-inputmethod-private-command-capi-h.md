# inputmethod_private_command_capi.h
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @illybyy-->
<!--SE: @andeszhang-->
<!--TSE: @murphy1984-->

## 概述

提供私有数据对象的创建、销毁与读写方法。

**引用文件：** <inputmethod/inputmethod_private_command_capi.h>

**库：** libohinputmethod.so

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**起始版本：** 12

**相关模块：** [InputMethod](capi-inputmethod.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) | InputMethod_PrivateCommand | 表示私有数据的结构体类型。输入框和输入法应用之间交互的私有数据。 |

### 函数

| 名称 | 描述                                                  |
| -- |-----------------------------------------------------|
| [InputMethod_PrivateCommand *OH_PrivateCommand_Create(char key[], size_t keyLength)](#oh_privatecommand_create) | 创建一个新的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例。      |
| [void OH_PrivateCommand_Destroy(InputMethod_PrivateCommand *command)](#oh_privatecommand_destroy) | 销毁一个[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例。           |
| [InputMethod_ErrorCode OH_PrivateCommand_SetKey(InputMethod_PrivateCommand *command, char key[], size_t keyLength)](#oh_privatecommand_setkey) | 设置[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)的key值。          |
| [InputMethod_ErrorCode OH_PrivateCommand_SetBoolValue(InputMethod_PrivateCommand *command, bool value)](#oh_privatecommand_setboolvalue) | 设置[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)的布尔类型value值。    |
| [InputMethod_ErrorCode OH_PrivateCommand_SetIntValue(InputMethod_PrivateCommand *command, int32_t value)](#oh_privatecommand_setintvalue) | 设置[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)的整数类型value值。    |
| [InputMethod_ErrorCode OH_PrivateCommand_SetStrValue(InputMethod_PrivateCommand *command, char value[], size_t valueLength)](#oh_privatecommand_setstrvalue) | 设置[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)的字符串类型value值。   |
| [InputMethod_ErrorCode OH_PrivateCommand_GetKey(InputMethod_PrivateCommand *command, const char **key, size_t *keyLength)](#oh_privatecommand_getkey) | 从[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)获取key值。          |
| [InputMethod_ErrorCode OH_PrivateCommand_GetValueType(InputMethod_PrivateCommand *command, InputMethod_CommandValueType *type)](#oh_privatecommand_getvaluetype) | 从[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)获取value的数据类型。    |
| [InputMethod_ErrorCode OH_PrivateCommand_GetBoolValue(InputMethod_PrivateCommand *command, bool *value)](#oh_privatecommand_getboolvalue) | 从[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)获取布尔类型的value的值。  |
| [InputMethod_ErrorCode OH_PrivateCommand_GetIntValue(InputMethod_PrivateCommand *command, int32_t *value)](#oh_privatecommand_getintvalue) | 从[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)获取整数类型的value的值。  |
| [InputMethod_ErrorCode OH_PrivateCommand_GetStrValue(InputMethod_PrivateCommand *command, const char **value, size_t *valueLength)](#oh_privatecommand_getstrvalue) | 从[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)获取字符串类型的value的值。 |

## 函数说明

### OH_PrivateCommand_Create()

```
InputMethod_PrivateCommand *OH_PrivateCommand_Create(char key[], size_t keyLength)
```

**描述**

创建一个新的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| char key[] | 私有数据的key值。 |
| size_t keyLength | key长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) * | 如果创建成功，返回一个指向新创建的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例的指针。<br> 如果创建失败，对象返回NULL，可能的失败原因有应用地址空间满。 |

### OH_PrivateCommand_Destroy()

```
void OH_PrivateCommand_Destroy(InputMethod_PrivateCommand *command)
```

**描述**

销毁一个[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | 指向即将被销毁的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例的指针。 |

### OH_PrivateCommand_SetKey()

```
InputMethod_ErrorCode OH_PrivateCommand_SetKey(InputMethod_PrivateCommand *command, char key[], size_t keyLength)
```

**描述**

设置[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)的key值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | 指向即将被设置的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例的指针。 |
| char key[] | key值。 |
| size_t keyLength | key长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_PrivateCommand_SetBoolValue()

```
InputMethod_ErrorCode OH_PrivateCommand_SetBoolValue(InputMethod_PrivateCommand *command, bool value)
```

**描述**

设置[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)的布尔类型value值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | 指向即将被设置的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例的指针。 |
| bool value | 布尔类型value值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_PrivateCommand_SetIntValue()

```
InputMethod_ErrorCode OH_PrivateCommand_SetIntValue(InputMethod_PrivateCommand *command, int32_t value)
```

**描述**

设置[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)的整数类型value值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | 指向即将被设置的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例的指针。 |
| int32_t value | 整型value值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_PrivateCommand_SetStrValue()

```
InputMethod_ErrorCode OH_PrivateCommand_SetStrValue(InputMethod_PrivateCommand *command, char value[], size_t valueLength)
```

**描述**

设置[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)的字符串类型value值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | 指向即将被设置的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例的指针。 |
| char value[] | 字符串类型value值。 |
| size_t valueLength | 表示字符串数据值的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_PrivateCommand_GetKey()

```
InputMethod_ErrorCode OH_PrivateCommand_GetKey(InputMethod_PrivateCommand *command, const char **key, size_t *keyLength)
```

**描述**

从[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)获取key值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | 指向即将被获取key值的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例的指针。 |
| const char **key | key的生命周期和command一致。不要直接保存key地址，或者直接写key。建议拷贝后使用。 |
| size_t *keyLength | key长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_PrivateCommand_GetValueType()

```
InputMethod_ErrorCode OH_PrivateCommand_GetValueType(InputMethod_PrivateCommand *command, InputMethod_CommandValueType *type)
```

**描述**

从[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)获取value的数据类型。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | 指向即将被获取value值的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例的指针。 |
| [InputMethod_CommandValueType](capi-inputmethod-types-capi-h.md#inputmethod_commandvaluetype) *type | 表示指向 [InputMethod_CommandValueType](capi-inputmethod-types-capi-h.md#inputmethod_commandvaluetype) 实例的指针。 用于value值的数据类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_PrivateCommand_GetBoolValue()

```
InputMethod_ErrorCode OH_PrivateCommand_GetBoolValue(InputMethod_PrivateCommand *command, bool *value)
```

**描述**

从[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)获取布尔类型的value的值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | 指向即将被获取value值的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例的指针。 |
| bool *value | 布尔类型的value的值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>     [IME_ERR_QUERY_FAILED](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 查询失败，命令中没有布尔值。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_PrivateCommand_GetIntValue()

```
InputMethod_ErrorCode OH_PrivateCommand_GetIntValue(InputMethod_PrivateCommand *command, int32_t *value)
```

**描述**

从[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)获取整数类型的value的值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | 指向即将被获取value值的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例的指针。 |
| int32_t *value | 整数类型的value的值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>     [IME_ERR_QUERY_FAILED](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 查询失败，命令中没有布尔值。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_PrivateCommand_GetStrValue()

```
InputMethod_ErrorCode OH_PrivateCommand_GetStrValue(InputMethod_PrivateCommand *command, const char **value, size_t *valueLength)
```

**描述**

从[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)获取字符串类型的value的值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | 指向即将被获取value值的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例的指针。 |
| const char **value | 字符串类型的value的值。 |
| size_t *valueLength | value的生命周期和command一致。不要直接保存value地址，或者直接写value。建议拷贝后使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。<br>     [IME_ERR_QUERY_FAILED](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 查询失败，命令中没有布尔值。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |


