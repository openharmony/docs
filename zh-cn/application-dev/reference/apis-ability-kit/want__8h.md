# want.h


## 概述

Want是对象间信息传递的载体, 可以用于应用组件间的信息传递。 Want的使用场景之一是作为startAbility的参数, 其包含了指定的启动目标, 以及启动时需携带的相关数据, 如bundleName和abilityName字段分别指明目标Ability所在应用的Bundle名称以及对应包内的Ability名称。当Ability A需要启动Ability B并传入一些数据时, 可使用Want作为载体将这些数据传递给Ability B。

**引用文件**：<AbilityKit/ability_base/want.h>

**库**：libability_base_want.so

**系统能力**：SystemCapability.Ability.AbilityBase

**起始版本**：15

**相关模块**：[AbilityBase](_ability_base.md)


## 汇总

### 文件

| 名称                                          | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [want.h](want__8h.md) | 声明Want相关能力。<br/>**引用文件**：<AbilityKit/ability_base/want.h><br/>**库**：libability_base_want.so |


### 结构体

| 名称                                                         | 描述                         |
| ------------------------------------------------------------ | ---------------------------- |
| [AbilityBase_Element](_ability_base_element.md#abilitybase_element) {<br/>    char* bundleName;<br/>    char* moduleName;<br/>    char* abilityName;<br/>} | Element数据结构。 |
| [AbilityBase_Want](_ability_base.md#abilitybase_want)  | Want数据结构。 |


### 函数

| 名称                                                         | 描述                         |
| ------------------------------------------------------------ | ---------------------------- |
| [AbilityBase_Want](_ability_base.md#abilitybase_want)* [OH_AbilityBase_CreateWant](_ability_base.md#oh_abilitybase_createwant)([AbilityBase_Element](_ability_base_element.md#abilitybase_element) element) | 创建Want。 |
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_DestroyWant](_ability_base.md#oh_abilitybase_destroywant)([AbilityBase_Want](_ability_base.md#abilitybase_want)* want) | 销毁Want。销毁后的Want不可使用，否则会导致未定义行为。 |
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_SetWantElement](_ability_base.md#oh_abilitybase_setwantelement)([AbilityBase_Want](_ability_base.md#abilitybase_want)* want, [AbilityBase_Element](_ability_base_element.md#abilitybase_element) element) | 设置Want中bundleName、moduleName与abilityName组成的Element结构体。 |
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_GetWantElement](_ability_base.md#oh_abilitybase_getwantelement)([AbilityBase_Want](_ability_base.md#abilitybase_want)* want, [AbilityBase_Element](_ability_base_element.md#abilitybase_element)* element) | 获取Want中bundleName、moduleName与abilityName组成的Element结构体。 |
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_SetWantCharParam](_ability_base.md#oh_abilitybase_setwantcharparam)([AbilityBase_Want](_ability_base.md#abilitybase_want)* want, const char* key, const char* value) | 设置Want Param参数，Param可参考[Want中的parameters参数](js-apis-inner-ability-want.md)。 |
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_GetWantCharParam](_ability_base.md#oh_abilitybase_getwantcharparam)([AbilityBase_Want](_ability_base.md#abilitybase_want)* want, const char* key, char* value, size_t valueSize) | 获取[OH_AbilityBase_SetWantCharParam](#oh_abilitybase_setwantcharparam)方法设置的Want Param参数。 |
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_AddWantFd](_ability_base.md#oh_abilitybase_addwantfd)([AbilityBase_Want](_ability_base.md#abilitybase_want)* want, const char* key, int32_t fd) | 添加Want文件描述符，文件描述符可通过[fs.open](../apis-core-file-kit/js-apis-file-fs.md#fsopen)获取。 |
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_GetWantFd](_ability_base.md#oh_abilitybase_getwantfd)([AbilityBase_Want](_ability_base.md#abilitybase_want)* want, const char* key, int32_t* fd) | 获取Want文件描述符。 |
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_SetWantUri](_ability_base.md#oh_abilitybase_setwanturi)([AbilityBase_Want](#abilitybase_want)* want, const char* uri) |  设置Want中URI字符串。URI可参考[Want中URI描述](js-apis-app-ability-want.md)。 |
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_GetWantUri](_ability_base.md#oh_abilitybase_getwanturi)([AbilityBase_Want](#abilitybase_want)* want, char* uri, size_t uriSize) |  获取Want中URI字符串。URI可参考[Want中URI描述](js-apis-app-ability-want.md)。|
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_SetWantInt32Param](_ability_base.md#oh_abilitybase_setwantint32param)([AbilityBase_Want](#abilitybase_want)* want, const char* key, int32_t value) |  设置Want中int32_t类型的值。 |
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_GetWantInt32Param](_ability_base.md#oh_abilitybase_getwantint32param)([AbilityBase_Want](#abilitybase_want)* want, const char* key, int32_t* value) |  获取Want中int32_t类型的值。 |
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_SetWantBoolParam](_ability_base.md#oh_abilitybase_setwantboolparam)([AbilityBase_Want](#abilitybase_want)* want, const char* key, bool value) |  设置Want中bool类型的值。 |
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_GetWantBoolParam](_ability_base.md#oh_abilitybase_getwantboolparam)([AbilityBase_Want](#abilitybase_want)* want, const char* key, bool* value) |  获取Want中bool类型的值。 |
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_SetWantDoubleParam](_ability_base.md#oh_abilitybase_setwantdoubleparam)([AbilityBase_Want](#abilitybase_want)* want, const char* key, double value) |  设置Want中double类型的值。 |
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_GetWantDoubleParam](_ability_base.md#oh_abilitybase_getwantdoubleparam)([AbilityBase_Want](#abilitybase_want)* want, const char* key, double* value) |  获取Want中double类型的值。 |
