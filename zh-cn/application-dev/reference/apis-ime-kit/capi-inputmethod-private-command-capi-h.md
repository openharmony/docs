# inputmethod_private_command_capi.h
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->

## 概述

提供私有数据对象的创建、销毁与读写方法。InputMethod_PrivateCommand采用key-value机制，支持输入法应用与编辑框客户端之间传递自定义私有数据，用于扩展输入法功能、传递特定场景指令或交换自定义配置信息。

该结构体的value支持三种数据类型：布尔值（bool）、整数（int32_t）和字符串（string），但同一个PrivateCommand实例只能设置一种类型的value。设置value时会覆盖之前已设置的value及其类型。获取value时，建议先通过OH_PrivateCommand_GetValueType判断当前value的数据类型，再调用对应的GetValue函数获取实际值，否则当请求的类型与实际存储类型不匹配时将返回IME_ERR_QUERY_FAILED。

该结构体主要在两种场景中使用：输入法应用通过OH_InputMethodProxy_SendPrivateCommand向编辑框客户端发送私有指令；编辑框客户端通过OH_TextEditorProxy_ReceivePrivateCommandFunc回调接收来自输入法应用的私有指令。单次发送的所有私有数据与key值的大小总和限制为32KB，最多可发送5个PrivateCommand实例。

**引用文件：** <inputmethod/inputmethod_private_command_capi.h>

**库：** libohinputmethod.so

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**起始版本：** 12

**相关模块：** [InputMethod](capi-inputmethod.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) | InputMethod_PrivateCommand | 表示私有数据的结构体类型。输入框和输入法应用之间用于通信的私有数据，采用key-value机制，支持bool/int32_t/string三种value类型。 |

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

```c
InputMethod_PrivateCommand *OH_PrivateCommand_Create(char key[], size_t keyLength)
```

**描述**

创建一个新的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例。创建时需指定key值，key为私有命令的标识符，用于区分不同的私有数据项。创建后的实例value类型默认为IME_COMMAND_VALUE_TYPE_NONE，需后续通过SetBoolValue/SetIntValue/SetStrValue设置value值及其类型。

使用场景：输入法应用需要向编辑框客户端传递私有数据时，首先调用此函数创建PrivateCommand实例，设置key和value后，通过OH_InputMethodProxy_SendPrivateCommand发送。编辑框客户端在OH_TextEditorProxy_ReceivePrivateCommandFunc回调中接收到的PrivateCommand实例也可使用本函数创建新的回复指令。

前置条件：key参数必须为非NULL指针，keyLength必须大于0且不超过单次所有私有数据与key值的大小总和32KB的限制。

使用后效果：成功调用后返回一个新创建的InputMethod_PrivateCommand实例指针，该实例的value类型初始为IME_COMMAND_VALUE_TYPE_NONE。调用方需负责该实例的生命周期管理，在使用完毕后必须调用OH_PrivateCommand_Destroy销毁实例以释放内存。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| char key[] | 私有数据的key值，用于标识该私有命令的含义。key值为字符串形式，不允许传入NULL指针。单次发送的所有私有数据与key值的大小总和限制为32KB（包括所有PrivateCommand实例的key和value数据）。建议key值具有明确的语义标识，便于接收方解析。 |
| size_t keyLength | key值的字节长度，不包括结尾空字符。必须大于0。单次所有私有数据与key值的大小限制32KB。若keyLength为0，创建行为未定义。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) * | 如果创建成功，返回一个指向新创建的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例的指针。调用方必须负责该实例的生命周期管理，使用完毕后调用[OH_PrivateCommand_Destroy](#oh_privatecommand_destroy)销毁实例以释放内存。<br> 如果创建失败，返回NULL。可能的失败原因：内存分配不足（应用地址空间满）。对NULL指针的后续操作（如Set/Get函数）将返回IME_ERR_NULL_POINTER。 |

### OH_PrivateCommand_Destroy()

```c
void OH_PrivateCommand_Destroy(InputMethod_PrivateCommand *command)
```

**描述**

销毁一个[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例，释放其占用的内存资源，包括key值和value值（字符串类型value）所占用的内部内存。

使用场景：当PrivateCommand实例不再使用时，调用此函数销毁实例。必须在Create函数成功返回后、且实例不再被任何其他对象引用时调用。特别注意：通过OH_InputMethodProxy_SendPrivateCommand发送后，原始实例仍需由发送方自行销毁；通过ReceivePrivateCommandFunc回调接收到的实例，其生命周期由回调调用期间管理，回调返回后该实例内存将被释放，不应再销毁或访问。

生命周期管理：OH_PrivateCommand_Create和OH_PrivateCommand_Destroy必须配对使用，每个Create创建的实例必须有对应的Destroy调用，否则会导致内存泄漏。调用Destroy后，原指针变为无效指针，不应再被使用。

前置条件：command参数应为OH_PrivateCommand_Create成功返回的非NULL指针。

使用后效果：command指向的内存被释放，包括内部存储的key字符串和value字符串的内存。command指针变为无效指针。对已销毁指针的任何后续访问均为未定义行为。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | 指向即将被销毁的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例的指针。若传入NULL，函数不执行任何操作，安全返回。建议销毁后将指针置为NULL以避免误用悬空指针。 |

### OH_PrivateCommand_SetKey()

```c
InputMethod_ErrorCode OH_PrivateCommand_SetKey(InputMethod_PrivateCommand *command, char key[], size_t keyLength)
```

**描述**

设置[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)的key值。key值为私有命令的标识符，用于接收方区分不同含义的私有数据。

使用场景：当需要修改已有PrivateCommand实例的key值时调用此函数。通常在Create时已设置初始key值，若需要更新key可再次调用此函数。

前置条件：command参数必须为OH_PrivateCommand_Create成功返回的非NULL指针；key参数必须为非NULL指针；keyLength必须大于0。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | 指向即将被设置的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例的指针。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。 |
| char key[] | key值，用于标识私有命令的含义。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。建议使用具有明确语义的字符串作为key，便于接收方解析和处理。 |
| size_t keyLength | key值的字节长度，不包括结尾空字符。必须大于0。单次所有私有数据与key值的大小限制32KB。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 传入的command参数或key参数为空指针。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_PrivateCommand_SetBoolValue()

```c
InputMethod_ErrorCode OH_PrivateCommand_SetBoolValue(InputMethod_PrivateCommand *command, bool value)
```

**描述**

设置[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)的布尔类型value值。调用此函数后，该PrivateCommand实例的value类型将变为IME_COMMAND_VALUE_TYPE_BOOL，之前已设置的其他类型value值（int32_t或string）将被覆盖。

使用场景：当私有命令的value需要传递布尔类型数据时调用此函数，如传递开关状态、是否启用某功能等布尔语义的数据。

前置条件：command参数必须为OH_PrivateCommand_Create成功返回的非NULL指针。

值类型规则：同一个PrivateCommand实例只能持有一种类型的value。调用SetBoolValue后，value类型变为IME_COMMAND_VALUE_TYPE_BOOL，之前通过SetIntValue或SetStrValue设置的value将被覆盖。后续通过GetIntValue或GetStrValue获取值时将返回IME_ERR_QUERY_FAILED。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | 指向即将被设置的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例的指针。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。 |
| bool value | 布尔类型value值，true或false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功，value类型已设置为IME_COMMAND_VALUE_TYPE_BOOL。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，command参数为NULL。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_PrivateCommand_SetIntValue()

```c
InputMethod_ErrorCode OH_PrivateCommand_SetIntValue(InputMethod_PrivateCommand *command, int32_t value)
```

**描述**

设置[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)的整数类型value值。调用此函数后，该PrivateCommand实例的value类型将变为IME_COMMAND_VALUE_TYPE_INT32，之前已设置的其他类型value值（bool或string）将被覆盖。

使用场景：当私有命令的value需要传递整数类型数据时调用此函数，如传递数值参数、计数、版本号等整数语义的数据。

前置条件：command参数必须为OH_PrivateCommand_Create成功返回的非NULL指针。

值类型规则：同一个PrivateCommand实例只能持有一种类型的value。调用SetIntValue后，value类型变为IME_COMMAND_VALUE_TYPE_INT32，之前通过SetBoolValue或SetStrValue设置的value将被覆盖。后续通过GetBoolValue或GetStrValue获取值时将返回IME_ERR_QUERY_FAILED。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | 指向即将被设置的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例的指针。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。 |
| int32_t value | 整数类型的value值，32位带符号整数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功，value类型已设置为IME_COMMAND_VALUE_TYPE_INT32。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，command参数为NULL。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_PrivateCommand_SetStrValue()

```c
InputMethod_ErrorCode OH_PrivateCommand_SetStrValue(InputMethod_PrivateCommand *command, char value[], size_t valueLength)
```

**描述**

设置[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)的字符串类型value值。调用此函数后，该PrivateCommand实例的value类型将变为IME_COMMAND_VALUE_TYPE_STRING，之前已设置的其他类型value值（bool或int32_t）将被覆盖。

使用场景：当私有命令的value需要传递字符串类型数据时调用此函数，如传递文本配置、URL、JSON格式参数等字符串语义的数据。

前置条件：command参数必须为OH_PrivateCommand_Create成功返回的非NULL指针；value参数必须为非NULL指针；valueLength必须大于0。

值类型规则：同一个PrivateCommand实例只能持有一种类型的value。调用SetStrValue后，value类型变为IME_COMMAND_VALUE_TYPE_STRING，之前通过SetBoolValue或SetIntValue设置的value将被覆盖。后续通过GetBoolValue或GetIntValue获取值时将返回IME_ERR_QUERY_FAILED。

内存管理：value字符串由调用方提供，SetStrValue函数会将字符串内容拷贝到PrivateCommand实例的内部存储中。调用方可在SetStrValue调用后立即释放原始value内存，无需保持value指针有效。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | 指向即将被设置的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例的指针。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。 |
| char value[] | 字符串类型value值。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。字符串内容将被拷贝到PrivateCommand实例的内部存储中，调用方无需在SetStrValue调用后保持value指针有效。 |
| size_t valueLength | 表示字符串数据值的字节长度，不包括结尾空字符。必须大于0。单次所有私有数据与key值的大小限制32KB。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功，value类型已设置为IME_COMMAND_VALUE_TYPE_STRING。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，command参数或value参数为NULL。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_PrivateCommand_GetKey()

```c
InputMethod_ErrorCode OH_PrivateCommand_GetKey(InputMethod_PrivateCommand *command, const char **key, size_t *keyLength)
```

**描述**

从[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)获取key值。key值为私有命令的标识符。

使用场景：接收方在OH_TextEditorProxy_ReceivePrivateCommandFunc回调中获取到PrivateCommand实例后，首先通过此函数获取key值，根据key的含义决定如何处理对应的value数据。

前置条件：command参数必须为非NULL指针；key和keyLength输出参数必须为非NULL指针，且由调用方分配内存。

内存管理：key指针指向的字符串生命周期与command实例一致。请勿直接保存key地址（因为在command销毁后key指针将失效），也不应直接修改key内容。推荐做法是先拷贝key字符串到调用方的自有内存后再使用。command实例销毁后（OH_PrivateCommand_Destroy或回调返回后），key指针失效，对失效指针的访问为未定义行为。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | 指向即将被获取key值的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例的指针。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。 |
| const char **key | 输出参数，用于接收key值的字符串指针。key的生命周期和command一致，请勿直接保存key地址，也不应直接操作key内容；推荐先拷贝后再使用。command实例销毁后，key指针失效，不应再访问。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。 |
| size_t *keyLength | 输出参数，用于接收key值的字节长度。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功，key和keyLength已被写入值。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，command、key或keyLength参数为NULL。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_PrivateCommand_GetValueType()

```c
InputMethod_ErrorCode OH_PrivateCommand_GetValueType(InputMethod_PrivateCommand *command, InputMethod_CommandValueType *type)
```

**描述**

从[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)获取value的数据类型。返回的类型指示了该实例当前存储的value值的类型，用于指导后续应调用哪个GetValue函数来获取实际的value值。

使用场景：在获取value值之前，必须先调用此函数判断value的数据类型，再根据类型调用对应的GetValue函数（GetBoolValue、GetIntValue或GetStrValue）。若直接调用与实际类型不匹配的GetValue函数，将返回IME_ERR_QUERY_FAILED错误码。

前置条件：command参数必须为非NULL指针；type输出参数必须为非NULL指针，且由调用方分配内存。

使用建议：建议在每次获取value值前都先调用GetValueType确认类型，避免因类型不匹配导致IME_ERR_QUERY_FAILED错误。典型调用顺序：1. 调用OH_PrivateCommand_GetValueType获取类型；2. 根据类型判断调用OH_PrivateCommand_GetBoolValue/OH_PrivateCommand_GetIntValue/OH_PrivateCommand_GetStrValue。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | 指向即将被获取value类型的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例的指针。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。 |
| [InputMethod_CommandValueType](capi-inputmethod-types-capi-h.md#inputmethod_commandvaluetype) *type | 输出参数，用于获取value值的数据类型。返回值为[InputMethod_CommandValueType](capi-inputmethod-types-capi-h.md#inputmethod_commandvaluetype)枚举值：IME_COMMAND_VALUE_TYPE_NONE表示未设置value；IME_COMMAND_VALUE_TYPE_STRING表示字符串类型；IME_COMMAND_VALUE_TYPE_BOOL表示布尔类型；IME_COMMAND_VALUE_TYPE_INT32表示32位带符号整数类型。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功，type已被写入当前value的数据类型。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，command或type参数为NULL。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_PrivateCommand_GetBoolValue()

```c
InputMethod_ErrorCode OH_PrivateCommand_GetBoolValue(InputMethod_PrivateCommand *command, bool *value)
```

**描述**

从[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)获取布尔类型的value的值。

使用场景：当通过OH_PrivateCommand_GetValueType确认value类型为IME_COMMAND_VALUE_TYPE_BOOL后，调用此函数获取布尔值。

前置条件：command参数必须为非NULL指针；value输出参数必须为非NULL指针，且由调用方分配内存。当前PrivateCommand实例的value类型必须为IME_COMMAND_VALUE_TYPE_BOOL，否则将返回IME_ERR_QUERY_FAILED。

类型不匹配处理：若当前value类型不是IME_COMMAND_VALUE_TYPE_BOOL（例如为IME_COMMAND_VALUE_TYPE_INT32或IME_COMMAND_VALUE_TYPE_STRING），此函数将返回IME_ERR_QUERY_FAILED错误码，表示查询失败——命令中没有布尔值。建议先调用OH_PrivateCommand_GetValueType确认类型后再获取值。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | 指向即将被获取value值的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例的指针。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。 |
| bool *value | 输出参数，用于接收布尔类型的value值。此参数为输出指针，调用方需分配bool类型变量的内存并将其地址传入。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功，value指针指向的内存已被写入布尔值。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，command或value参数为NULL。<br>     [IME_ERR_QUERY_FAILED](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 查询失败，命令中没有布尔值，即当前value类型不是IME_COMMAND_VALUE_TYPE_BOOL（类型不匹配）。建议先调用OH_PrivateCommand_GetValueType确认类型。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_PrivateCommand_GetIntValue()

```c
InputMethod_ErrorCode OH_PrivateCommand_GetIntValue(InputMethod_PrivateCommand *command, int32_t *value)
```

**描述**

从[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)获取整数类型的value的值。

使用场景：当通过OH_PrivateCommand_GetValueType确认value类型为IME_COMMAND_VALUE_TYPE_INT32后，调用此函数获取整数值。

前置条件：command参数必须为非NULL指针；value输出参数必须为非NULL指针，且由调用方分配内存。当前PrivateCommand实例的value类型必须为IME_COMMAND_VALUE_TYPE_INT32，否则将返回IME_ERR_QUERY_FAILED。

类型不匹配处理：若当前value类型不是IME_COMMAND_VALUE_TYPE_INT32（例如为IME_COMMAND_VALUE_TYPE_BOOL或IME_COMMAND_VALUE_TYPE_STRING），此函数将返回IME_ERR_QUERY_FAILED错误码，表示查询失败——命令中没有整数值。建议先调用OH_PrivateCommand_GetValueType确认类型后再获取值。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | 指向即将被获取value值的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例的指针。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。 |
| int32_t *value | 输出参数，用于接收整数类型的value值。此参数为输出指针，调用方需分配int32_t类型变量的内存并将其地址传入。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功，value指针指向的内存已被写入整数值。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，command或value参数为NULL。<br>     [IME_ERR_QUERY_FAILED](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 查询失败，命令中没有整数值，即当前value类型不是IME_COMMAND_VALUE_TYPE_INT32（类型不匹配）。建议先调用OH_PrivateCommand_GetValueType确认类型。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_PrivateCommand_GetStrValue()

```c
InputMethod_ErrorCode OH_PrivateCommand_GetStrValue(InputMethod_PrivateCommand *command, const char **value, size_t *valueLength)
```

**描述**

从[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)获取字符串类型的value的值。

使用场景：当通过OH_PrivateCommand_GetValueType确认value类型为IME_COMMAND_VALUE_TYPE_STRING后，调用此函数获取字符串值。

前置条件：command参数必须为非NULL指针；value和valueLength输出参数必须为非NULL指针，且由调用方分配内存。当前PrivateCommand实例的value类型必须为IME_COMMAND_VALUE_TYPE_STRING，否则将返回IME_ERR_QUERY_FAILED。

类型不匹配处理：若当前value类型不是IME_COMMAND_VALUE_TYPE_STRING（例如为IME_COMMAND_VALUE_TYPE_BOOL或IME_COMMAND_VALUE_TYPE_INT32），此函数将返回IME_ERR_QUERY_FAILED错误码，表示查询失败——命令中没有字符串值。建议先调用OH_PrivateCommand_GetValueType确认类型后再获取值。

内存管理：value指针指向的字符串生命周期与command实例一致。请勿直接保存value地址（因为在command销毁后value指针将失效），也不应直接修改value内容。推荐做法是先拷贝字符串到调用方的自有内存后再使用。command实例销毁后（OH_PrivateCommand_Destroy或回调返回后），value指针失效，对失效指针的访问为未定义行为。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | 指向即将被获取value值的[InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md)实例的指针。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。 |
| const char **value | 输出参数，用于接收字符串类型value值的指针。value的生命周期和command一致，请勿直接保存value地址，也不应直接修改value内容；推荐先拷贝后再使用。command实例销毁后，value指针失效，不应再访问。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。 |
| size_t *valueLength | 输出参数，用于返回字符串类型value值的字节长度。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功，value和valueLength已被写入值。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，command、value或valueLength参数为NULL。<br>     [IME_ERR_QUERY_FAILED](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 查询失败，命令中没有字符串值，即当前value类型不是IME_COMMAND_VALUE_TYPE_STRING（类型不匹配）。建议先调用OH_PrivateCommand_GetValueType确认类型。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |
