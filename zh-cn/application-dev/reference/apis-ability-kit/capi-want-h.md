# want.h

## 概述

Want是对象间信息传递的载体，可以用于应用组件间的信息传递。 Want的使用场景之一是作为startAbility的参数，其包含了指定的启动目标，以及启动时需携带的相关数据，如bundleName和abilityName字段分别指明目标Ability所在应用的Bundle名称以及对应包内的Ability名称。当Ability A需要启动Ability B并传入一些数据时，可使用Want作为载体将这些数据传递给Ability B。

**引用文件：** <AbilityKit/ability_base/want.h>

**库：** libability_base_want.so

**系统能力：** SystemCapability.Ability.AbilityBase

**起始版本：** 15

**相关模块：** [AbilityBase](capi-abilitybase.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [AbilityBase_Element](capi-abilitybase-element.md) | AbilityBase_Element | 声明Want中Element结构体。 |
| [AbilityBase_Want](capi-abilitybase-want.md) | AbilityBase_Want | 声明Want数据结构。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [AbilityBase_Want* OH_AbilityBase_CreateWant(AbilityBase_Element element)](#oh_abilitybase_createwant) | 创建Want。 |
| [AbilityBase_ErrorCode OH_AbilityBase_DestroyWant(AbilityBase_Want* want)](#oh_abilitybase_destroywant) | 销毁Want。销毁后的Want不可使用，否则会导致未定义行为。 |
| [AbilityBase_ErrorCode OH_AbilityBase_SetWantElement(AbilityBase_Want* want, AbilityBase_Element element)](#oh_abilitybase_setwantelement) | 设置Want中由bundleName、moduleName与abilityName组成的Element结构体。 |
| [AbilityBase_ErrorCode OH_AbilityBase_GetWantElement(AbilityBase_Want* want, AbilityBase_Element* element)](#oh_abilitybase_getwantelement) | 获取Want中由bundleName、moduleName与abilityName组成的Element结构体。 |
| [AbilityBase_ErrorCode OH_AbilityBase_SetWantCharParam(AbilityBase_Want* want, const char* key, const char* value)](#oh_abilitybase_setwantcharparam) | 设置Want Param参数。 |
| [AbilityBase_ErrorCode OH_AbilityBase_GetWantCharParam(AbilityBase_Want* want, const char* key,char* value, size_t valueSize)](#oh_abilitybase_getwantcharparam) | 获取Want Param参数。 |
| [AbilityBase_ErrorCode OH_AbilityBase_AddWantFd(AbilityBase_Want* want, const char* key, int32_t fd)](#oh_abilitybase_addwantfd) | 添加Want文件描述符。 |
| [AbilityBase_ErrorCode OH_AbilityBase_GetWantFd(AbilityBase_Want* want, const char* key, int32_t* fd)](#oh_abilitybase_getwantfd) | 获取Want文件描述符。 |
| [AbilityBase_ErrorCode OH_AbilityBase_SetWantUri(AbilityBase_Want* want, const char* uri)](#oh_abilitybase_setwanturi) | 设置Want中URI字符串。 |
| [AbilityBase_ErrorCode OH_AbilityBase_GetWantUri(AbilityBase_Want* want, char* uri, size_t uriSize)](#oh_abilitybase_getwanturi) | 获取Want中URI字符串。URI可参考[Want中uri描述](js-apis-app-ability-want.md)。 |
| [AbilityBase_ErrorCode OH_AbilityBase_SetWantInt32Param(AbilityBase_Want* want, const char* key, int32_t value)](#oh_abilitybase_setwantint32param) | 设置Want中int32_t类型的值。 |
| [AbilityBase_ErrorCode OH_AbilityBase_GetWantInt32Param(AbilityBase_Want* want, const char* key, int32_t* value)](#oh_abilitybase_getwantint32param) | 获取Want中int32_t类型的值。 |
| [AbilityBase_ErrorCode OH_AbilityBase_SetWantBoolParam(AbilityBase_Want* want, const char* key, bool value)](#oh_abilitybase_setwantboolparam) | 设置Want中bool类型的值。 |
| [AbilityBase_ErrorCode OH_AbilityBase_GetWantBoolParam(AbilityBase_Want* want, const char* key, bool* value)](#oh_abilitybase_getwantboolparam) | 获取Want中bool类型的值。 |
| [AbilityBase_ErrorCode OH_AbilityBase_SetWantDoubleParam(AbilityBase_Want* want, const char* key, double value)](#oh_abilitybase_setwantdoubleparam) | 设置Want中double类型的值。 |
| [AbilityBase_ErrorCode OH_AbilityBase_GetWantDoubleParam(AbilityBase_Want* want, const char* key, double* value)](#oh_abilitybase_getwantdoubleparam) | 获取Want中double类型的值。 |

## 函数说明

### OH_AbilityBase_CreateWant()

```
AbilityBase_Want* OH_AbilityBase_CreateWant(AbilityBase_Element element)
```

**描述**

创建Want。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AbilityBase_Element](capi-abilitybase-element.md) element | Element数据结构。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* | 返回want数据结构。 |

### OH_AbilityBase_DestroyWant()

```
AbilityBase_ErrorCode OH_AbilityBase_DestroyWant(AbilityBase_Want* want)
```

**描述**

销毁Want。销毁后的Want不可使用，否则会导致未定义行为。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Want指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | 返回执行结果。<br>ABILITY_BASE_ERROR_CODE_NO_ERROR - 销毁want成功。<br>ABILITY_BASE_ERROR_CODE_PARAM_INVALID - element参数无效。 |

### OH_AbilityBase_SetWantElement()

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantElement(AbilityBase_Want* want, AbilityBase_Element element)
```

**描述**

设置Want中由bundleName、moduleName与abilityName组成的Element结构体。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Want指针。 |
| [AbilityBase_Element](capi-abilitybase-element.md) element | Element结构体。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | 返回执行结果。<br>ABILITY_BASE_ERROR_CODE_NO_ERROR - 设置element成功。<br>ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空，element参数无效。 |

### OH_AbilityBase_GetWantElement()

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantElement(AbilityBase_Want* want, AbilityBase_Element* element)
```

**描述**

获取Want中由bundleName、moduleName与abilityName组成的Element结构体。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Want指针。 |
| [AbilityBase_Element](capi-abilitybase-element.md)* element | Element结构体。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | 返回执行结果。<br>ABILITY_BASE_ERROR_CODE_NO_ERROR - 获取element成功。<br>ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空，element参数无效。 |

### OH_AbilityBase_SetWantCharParam()

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantCharParam(AbilityBase_Want* want, const char* key, const char* value)
```

**描述**

设置Want Param参数，Param可参考[Want中的parameters参数](js-apis-inner-ability-want.md)。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Want指针。 |
| const char* key | Want中字符串参数索引。 |
| const char* value | Want中字符串。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | 返回执行结果。<br>ABILITY_BASE_ERROR_CODE_NO_ERROR - 设置param成功。<br>ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空或非法入参。 |

### OH_AbilityBase_GetWantCharParam()

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantCharParam(AbilityBase_Want* want, const char* key,char* value, size_t valueSize)
```

**描述**

获取[OH_AbilityBase_SetWantCharParam](#oh_abilitybase_setwantcharparam)方法设置的Want Param参数。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Want指针。 |
| const char* key | Want中字符串参数索引。 |
| char* value | Want中字符串。 |
| size_t valueSize | value字符串长度。如果valueSize小于实际需要获取的value长度，则会报[ABILITY_BASE_ERROR_CODE_PARAM_INVALID](capi-ability-base-common-h.md#abilitybase_errorcode)错误。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | 返回执行结果。<br>ABILITY_BASE_ERROR_CODE_NO_ERROR - 获取param成功。<br>ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空或非法入参。 |

### OH_AbilityBase_AddWantFd()

```
AbilityBase_ErrorCode OH_AbilityBase_AddWantFd(AbilityBase_Want* want, const char* key, int32_t fd)
```

**描述**

添加Want文件描述符，文件描述符可通过[fs.open](../apis-core-file-kit/js-apis-file-fs.md#fsopen)获取。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want |  Want指针。 |
| const char* key | Want中字符串参数索引。 |
| int32_t fd | 文件描述符，可通过[fs.open](../apis-core-file-kit/js-apis-file-fs.md#fsopen)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | 返回执行结果。<br>ABILITY_BASE_ERROR_CODE_NO_ERROR - 添加want文件描述符成功。<br>ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空或非法入参。 |

### OH_AbilityBase_GetWantFd()

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantFd(AbilityBase_Want* want, const char* key, int32_t* fd)
```

**描述**

获取Want文件描述符。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Want指针。 |
| const char* key | Want中字符串参数索引。 |
| int32_t* fd | 文件描述符。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | 返回执行结果。<br>ABILITY_BASE_ERROR_CODE_NO_ERROR - 获取want文件描述符成功。<br>ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空或非法入参。 |

### OH_AbilityBase_SetWantUri()

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantUri(AbilityBase_Want* want, const char* uri)
```

**描述**

设置Want中URI字符串，URI可参考[Want中URI描述](js-apis-app-ability-want.md)。

**起始版本：** 17

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Want指针。 |
| const char* uri | 表示URI。如果在Want中指定了URI，则Want将匹配指定的URI信息。URI可参考[Want中URI描述](js-apis-app-ability-want.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | 返回执行结果。<br>ABILITY_BASE_ERROR_CODE_NO_ERROR - 设置want中uri字符串成功。<br>ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空或非法入参。 |

### OH_AbilityBase_GetWantUri()

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantUri(AbilityBase_Want* want, char* uri, size_t uriSize)
```

**描述**

获取Want中URI字符串。URI可参考[Want中URI描述](js-apis-app-ability-want.md)。

**起始版本：** 17

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Want指针。 |
| char* uri | 表示URI。如果在Want中指定了URI，则Want将匹配指定的URI信息。URI可参考[Want中URI描述](js-apis-app-ability-want.md)。 |
| size_t uriSize | URI字符串长度。如果uriSize小于实际需要获取的URI长度，则会报[ABILITY_BASE_ERROR_CODE_PARAM_INVALID](capi-ability-base-common-h.md#abilitybase_errorcode)错误。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | 返回执行结果。<br>ABILITY_BASE_ERROR_CODE_NO_ERROR - 获取want中URI字符串成功。<br>ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空或非法入参。 |

### OH_AbilityBase_SetWantInt32Param()

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantInt32Param(AbilityBase_Want* want, const char* key, int32_t value)
```

**描述**

设置Want中int32_t类型的值。

**起始版本：** 17


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Want指针。 |
| const char* key | Want中int32_t类型值的参数索引。 |
| int32_t value | Want中int32_t类型的值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | 返回执行结果。<br>ABILITY_BASE_ERROR_CODE_NO_ERROR - 设置want中int32_t类型的值成功。<br>ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空或非法入参。 |

### OH_AbilityBase_GetWantInt32Param()

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantInt32Param(AbilityBase_Want* want, const char* key, int32_t* value)
```

**描述**

获取Want中int32_t类型的值。

**起始版本：** 17

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Want指针。 |
| const char* key | Want中int32_t类型值的参数索引。 |
| int32_t* value | Want中int32_t类型的值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | 返回执行结果。<br>ABILITY_BASE_ERROR_CODE_NO_ERROR - 获取want中int32_t类型的值成功。<br>ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空或非法入参。 |

### OH_AbilityBase_SetWantBoolParam()

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantBoolParam(AbilityBase_Want* want, const char* key, bool value)
```

**描述**

设置Want中bool类型的值。

**起始版本：** 17

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Want指针。 |
| const char* key | Want中bool类型值的参数索引。 |
| bool value | Want中bool类型的值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | 返回执行结果。<br>ABILITY_BASE_ERROR_CODE_NO_ERROR - 设置want中bool类型的值成功。<br>ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空或非法入参。 |

### OH_AbilityBase_GetWantBoolParam()

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantBoolParam(AbilityBase_Want* want, const char* key, bool* value)
```

**描述**

获取Want中bool类型的值。

**起始版本：** 17

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Want指针。 |
| const char* key | Want中bool类型值的参数索引。 |
| bool* value | Want中bool类型的值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | 返回执行结果。<br>ABILITY_BASE_ERROR_CODE_NO_ERROR - 获取want中bool类型的值成功。<br>ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空或非法入参。 |

### OH_AbilityBase_SetWantDoubleParam()

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantDoubleParam(AbilityBase_Want* want, const char* key, double value)
```

**描述**

设置Want中double类型的值。

**起始版本：** 17

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Want指针。 |
| const char* key | Want中double类型值的参数索引。 |
| double value | Want中double类型的值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | 返回执行结果。<br>ABILITY_BASE_ERROR_CODE_NO_ERROR - 设置want中double类型的值成功。<br>ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空或非法入参。 |

### OH_AbilityBase_GetWantDoubleParam()

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantDoubleParam(AbilityBase_Want* want, const char* key, double* value)
```

**描述**

获取Want中double类型的值。

**起始版本：** 17

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Want指针。 |
| const char* key | Want中double类型值的参数索引。 |
| double* value | Want中double类型的值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | 返回执行结果。<br>ABILITY_BASE_ERROR_CODE_NO_ERROR - 获取want中double类型的值成功。<br>ABILITY_BASE_ERROR_CODE_PARAM_INVALID - want为空或非法入参。 |
