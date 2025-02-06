# AbilityBase

## 概述

作为Ability Kit的基础定义模块，AbilityBase提供了组件启动参数[Want](want__8h.md)的定义与接口，可以用于应用组件间的信息传递。

**系统能力**：SystemCapability.Ability.AbilityBase

**起始版本**：15

## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [ability_base_common.h](ability__base__common_8h.md) | 声明AbilityBase相关错误码。<br/>**引用文件**：<AbilityKit/ability_runtime/ability_runtime_common.h><br/>**库**：libability_runtime.so |
| [want.h](want__8h.md) | 声明[Want](want__8h.md)相关能力。<br/>**引用文件**：<AbilityKit/ability_runtime/application_context.h><br/>**库**：libability_runtime.so |

### 枚举

| 名称                                                         | 描述                   |
| ------------------------------------------------------------ | ---------------------- |
| [AbilityBase_ErrorCode](#abilitybase_errorcode) {<br>    ABILITY_RUNTIME_ERROR_CODE_NO_ERROR = 0,<br>    ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID = 401,<br>    ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST = 16000011,<br/>} | 定义AbilityBase相关错误码。 |

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

ABILITY_BASE_ERROR_CODE_NO_ERROR - 获取want文件描述符成功。

ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空或非法入参。
