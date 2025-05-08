# AbilityBase

## 概述

作为Ability Kit的基础定义模块，AbilityBase提供了组件启动参数[Want](want__8h.md)的定义与接口，可以用于应用组件间的信息传递。

**系统能力**：SystemCapability.Ability.AbilityBase

**起始版本**：15

## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [ability_base_common.h](ability__base__common_8h.md) | 声明AbilityBase相关错误码。<br/>**引用文件**：<AbilityKit/ability_base/ability_base_common.h><br/>**库**：libability_base_want.so |
| [want.h](want__8h.md) | 声明[Want](want__8h.md)相关能力。<br/>**引用文件**：<AbilityKit/ability_base/want.h><br/>**库**：libability_base_want.so |

### 枚举

| 名称                                                         | 描述                   |
| ------------------------------------------------------------ | ---------------------- |
| [AbilityBase_ErrorCode](#abilitybase_errorcode) {<br>    ABILITY_BASE_ERROR_CODE_NO_ERROR = 0,<br>    ABILITY_BASE_ERROR_CODE_PARAM_INVALID = 401,<br/>} | 定义AbilityBase相关错误码。 |

### 结构体

| 名称                                                         | 描述                         |
| ------------------------------------------------------------ | ---------------------------- |
| [AbilityBase_Element](_ability_base_element.md#abilitybase_element) {<br/>    char* bundleName;<br/>    char* moduleName;<br/>    char* abilityName;<br/>} | Element数据结构。 |
| [AbilityBase_Want](#abilitybase_want)  | Want数据结构。 |

### 函数

| 名称                                                         | 描述                         |
| ------------------------------------------------------------ | ---------------------------- |
| [AbilityBase_Want](#abilitybase_want)* [OH_AbilityBase_CreateWant](#oh_abilitybase_createwant)([AbilityBase_Element](_ability_base_element.md#abilitybase_element) element) | 创建Want。 |
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_DestroyWant](#oh_abilitybase_destroywant)([AbilityBase_Want](#abilitybase_want)* want) | 销毁Want。销毁后的Want不可使用，否则会导致未定义行为。 |
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_SetWantElement](#oh_abilitybase_setwantelement)([AbilityBase_Want](#abilitybase_want)* want, [AbilityBase_Element](_ability_base_element.md#abilitybase_element) element) | 设置Want中由bundleName、moduleName与abilityName组成的Element结构体。 |
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_GetWantElement](#oh_abilitybase_getwantelement)([AbilityBase_Want](#abilitybase_want)* want, [AbilityBase_Element](_ability_base_element.md#abilitybase_element)* element) | 获取Want中由bundleName、moduleName与abilityName组成的Element结构体。 |
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_SetWantCharParam](#oh_abilitybase_setwantcharparam)([AbilityBase_Want](#abilitybase_want)* want, const char* key, const char* value) | 设置Want Param参数，Param可参考[Want中的parameters参数](js-apis-inner-ability-want.md)。 |
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_GetWantCharParam](#oh_abilitybase_getwantcharparam)([AbilityBase_Want](#abilitybase_want)* want, const char* key, char* value, size_t valueSize) | 获取[OH_AbilityBase_SetWantCharParam](#oh_abilitybase_setwantcharparam)方法设置的Want Param参数。 |
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_AddWantFd](#oh_abilitybase_addwantfd)([AbilityBase_Want](#abilitybase_want)* want, const char* key, int32_t fd) | 添加Want文件描述符，文件描述符可通过[fs.open](../apis-core-file-kit/js-apis-file-fs.md#fsopen)获取。 |
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_GetWantFd](#oh_abilitybase_getwantfd)([AbilityBase_Want](#abilitybase_want)* want, const char* key, int32_t* fd) |  获取Want文件描述符。 |
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_SetWantUri](#oh_abilitybase_setwanturi)([AbilityBase_Want](#abilitybase_want)* want, const char* uri) |  设置Want中uri字符串。uri可参考[Want中uri描述](js-apis-app-ability-want.md)。 |
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_GetWantUri](#oh_abilitybase_getwanturi)([AbilityBase_Want](#abilitybase_want)* want, char* uri, size_t uriSize) |  获取Want中uri字符串。uri可参考[Want中uri描述](js-apis-app-ability-want.md)。 |
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_SetWantInt32Param](#oh_abilitybase_setwantint32param)([AbilityBase_Want](#abilitybase_want)* want, const char* key, int32_t value) |  设置Want中int32_t类型的值。 |
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_GetWantInt32Param](#oh_abilitybase_getwantint32param)([AbilityBase_Want](#abilitybase_want)* want, const char* key, int32_t* value) |  获取Want中int32_t类型的值。 |
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_SetWantBoolParam](#oh_abilitybase_setwantboolparam)([AbilityBase_Want](#abilitybase_want)* want, const char* key, bool value) |  设置Want中bool类型的值。 |
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_GetWantBoolParam](#oh_abilitybase_getwantboolparam)([AbilityBase_Want](#abilitybase_want)* want, const char* key, bool* value) |  获取Want中bool类型的值。 |
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_SetWantDoubleParam](#oh_abilitybase_setwantdoubleparam)([AbilityBase_Want](#abilitybase_want)* want, const char* key, double value) |  设置Want中double类型的值。 |
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_GetWantDoubleParam](#oh_abilitybase_getwantdoubleparam)([AbilityBase_Want](#abilitybase_want)* want, const char* key, double* value) |  获取Want中double类型的值。 |



## 枚举类型说明

### AbilityBase_ErrorCode

```
enum AbilityBase_ErrorCode
```

**描述**

定义AbilityBase相关错误码。

**起始版本**：15

| 枚举值                                        | 描述           |
| --------------------------------------------- | -------------- |
| ABILITY_BASE_ERROR_CODE_NO_ERROR           | 操作成功。     |
| ABILITY_BASE_ERROR_CODE_PARAM_INVALID      | 无效参数。     |


## 结构体说明

### AbilityBase_Want

```
AbilityBase_Want
```

**描述**

Want数据结构。

**起始版本**：15


## 函数说明


### OH_AbilityBase_CreateWant

```
AbilityBase_Want* OH_AbilityBase_CreateWant(AbilityBase_Element element)
```
**描述**

创建Want。

**起始版本**：15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| element | Element数据结构。 |

**返回：**

AbilityBase_Want - want数据结构。


### OH_AbilityBase_DestroyWant

```
AbilityBase_ErrorCode OH_AbilityBase_DestroyWant(AbilityBase_Want* want)
```
**描述**

销毁Want。销毁后的Want不可使用，否则会导致未定义行为。

**起始版本**：15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| want | Want指针。 |

**返回：**

ABILITY_BASE_ERROR_CODE_NO_ERROR - 销毁want成功。

ABILITY_BASE_ERROR_CODE_PARAM_INVALID - element参数无效。

### OH_AbilityBase_SetWantElement

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantElement(AbilityBase_Want* want, AbilityBase_Element element)
```
**描述**

设置Want中由bundleName、moduleName与abilityName组成的Element结构体。

**起始版本**：15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| want | Want指针。 |
| element | Element结构体。 |

**返回：**

ABILITY_BASE_ERROR_CODE_NO_ERROR - 设置element成功。

ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空，element参数无效。

### OH_AbilityBase_GetWantElement

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantElement(AbilityBase_Want* want, AbilityBase_Element* element)
```
**描述**

获取Want中由bundleName、moduleName与abilityName组成的Element结构体。

**起始版本**：15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| want | Want指针。 |
| element | Element结构体指针。 |

**返回：**

ABILITY_BASE_ERROR_CODE_NO_ERROR - 获取element成功。

ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空，element参数无效。

### OH_AbilityBase_SetWantCharParam

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantCharParam(AbilityBase_Want* want, const char* key, const char* value)
```
**描述**

设置Want Param参数，Param可参考[Want中的parameters参数](js-apis-inner-ability-want.md)。

**起始版本**：15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| want | Want指针。 |
| key | Want中字符串参数索引。 |
| value | Want中字符串。 |

**返回：**

ABILITY_BASE_ERROR_CODE_NO_ERROR - 设置param成功。

ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空或非法入参。

### OH_AbilityBase_GetWantCharParam

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantCharParam(AbilityBase_Want* want, const char* key, char* value, size_t valueSize)
```
**描述**

获取[OH_AbilityBase_SetWantCharParam](#oh_abilitybase_setwantcharparam)方法设置的Want Param参数。

**起始版本**：15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| want | Want指针。 |
| key | Want中字符串参数索引。 |
| value | Want中字符串。 |
| valueSize | value字符串长度。如果valueSize小于实际需要获取的value长度，则会报ABILITY_BASE_ERROR_CODE_PARAM_INVALID错误。 |

**返回：**

ABILITY_BASE_ERROR_CODE_NO_ERROR - 获取param成功。

ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空或非法入参。

### OH_AbilityBase_AddWantFd

```
AbilityBase_ErrorCode OH_AbilityBase_AddWantFd(AbilityBase_Want* want, const char* key, int32_t fd)
```
**描述**

添加Want文件描述符，文件描述符可通过[fs.open](../apis-core-file-kit/js-apis-file-fs.md#fsopen)获取。

**起始版本**：15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| want | Want指针。 |
| key | Want中字符串参数索引。 |
| fd | 文件描述符，可通过[fs.open](../apis-core-file-kit/js-apis-file-fs.md#fsopen)获取。 |

**返回：**

ABILITY_BASE_ERROR_CODE_NO_ERROR - 添加want文件描述符成功。

ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空或非法入参。

### OH_AbilityBase_GetWantFd

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantFd(AbilityBase_Want* want, const char* key, int32_t* fd)
```
**描述**

获取Want文件描述符。

**起始版本**：15

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| want | Want指针。 |
| key | Want中字符串参数索引。 |
| fd | 文件描述符。 |

**返回：**

ABILITY_BASE_ERROR_CODE_NO_ERROR - 获取Want文件描述符成功。

ABILITY_BASE_ERROR_CODE_PARAM_INVALID - Want为空或非法入参。

### OH_AbilityBase_SetWantUri

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantUri(AbilityBase_Want* want, const char* uri)
```
**描述**

设置Want中URI字符串。URI可参考[Want中URI描述](js-apis-app-ability-want.md)。

**起始版本**：17

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| want | Want指针。 |
| uri | 表示URI。如果在Want中指定了URI，则Want将匹配指定的URI信息。可参考[Want中URI描述](js-apis-app-ability-want.md)。|

**返回：**

ABILITY_BASE_ERROR_CODE_NO_ERROR - 设置Want中uri字符串成功。

ABILITY_BASE_ERROR_CODE_PARAM_INVALID - Want为空或非法入参。

### OH_AbilityBase_GetWantUri

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantUri(AbilityBase_Want* want, char* uri, size_t uriSize)
```
**描述**

获取Want中URI字符串。URI可参考[Want中URI描述](js-apis-app-ability-want.md)。

**起始版本**：17

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| want | Want指针。 |
| uri | 表示URI。如果在Want中指定了URI，则Want将匹配指定的URI信息。可参考[Want中URI描述](js-apis-app-ability-want.md)。|
| uriSize | URI字符串长度。如果uriSize小于实际需要获取的URI长度，则会报ABILITY_BASE_ERROR_CODE_PARAM_INVALID错误。|

**返回：**

ABILITY_BASE_ERROR_CODE_NO_ERROR - 获取Want中URI字符串成功。

ABILITY_BASE_ERROR_CODE_PARAM_INVALID - Want为空或非法入参。

### OH_AbilityBase_SetWantInt32Param

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantInt32Param(AbilityBase_Want* want, const char* key, int32_t value)
```
**描述**

设置Want中int32_t类型的值。

**起始版本**：17

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| want | Want指针。 |
| key | Want中int32_t类型值的参数索引。 |
| value | Want中int32_t类型的值。 |

**返回：**

ABILITY_BASE_ERROR_CODE_NO_ERROR - 设置Want中int32_t类型的值成功。

ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空或非法入参。

### OH_AbilityBase_GetWantInt32Param

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantInt32Param(AbilityBase_Want* want, const char* key, int32_t* value)
```
**描述**

获取Want中int32_t类型的值。

**起始版本**：17

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| want | Want指针。 |
| key | Want中int32_t类型值的参数索引。 |
| value | Want中int32_t类型的值。 |

**返回：**

ABILITY_BASE_ERROR_CODE_NO_ERROR - 获取Want中int32_t类型的值成功。

ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空或非法入参。


### OH_AbilityBase_SetWantBoolParam

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantBoolParam(AbilityBase_Want* want, const char* key, bool value)
```
**描述**

设置Want中bool类型的值。

**起始版本**：17

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| want | Want指针。 |
| key | Want中bool类型值的参数索引。 |
| value | Want中bool类型的值。 |

**返回：**

ABILITY_BASE_ERROR_CODE_NO_ERROR - 设置Want中bool类型的值成功。

ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空或非法入参。

### OH_AbilityBase_GetWantBoolParam

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantBoolParam(AbilityBase_Want* want, const char* key, bool* value)
```
**描述**

获取Want中bool类型的值。

**起始版本**：17

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| want | Want指针。 |
| key | Want中bool类型值的参数索引。 |
| value | Want中bool类型的值。 |

**返回：**

ABILITY_BASE_ERROR_CODE_NO_ERROR - 获取Want中bool类型的值成功。

ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空或非法入参。

### OH_AbilityBase_SetWantDoubleParam

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantDoubleParam(AbilityBase_Want* want, const char* key, double value)
```
**描述**

设置Want中double类型的值。

**起始版本**：17

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| want | Want指针。 |
| key | Want中double类型值的参数索引。 |
| value | Want中double类型的值。 |

**返回：**

ABILITY_BASE_ERROR_CODE_NO_ERROR - 设置Want中double类型的值成功。

ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空或非法入参。

### OH_AbilityBase_GetWantDoubleParam

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantDoubleParam(AbilityBase_Want* want, const char* key, double* value)
```
**描述**

获取Want中double类型的值。

**起始版本**：17

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| want | Want指针。 |
| key | Want中double类型值的参数索引。 |
| value | Want中double类型的值。 |

**返回：**

ABILITY_BASE_ERROR_CODE_NO_ERROR - 获取Want中double类型的值成功。

ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空或非法入参。