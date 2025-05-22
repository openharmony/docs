# want.h


## Overview

Want is a carrier for information transfer between objects (application components). Want can be used as a parameter of **startAbility** to specify a startup target and information that needs to be carried during startup, for example, **bundleName** and **abilityName**, which respectively indicate the bundle name of the target ability and the ability name in the bundle. When ability A needs to start ability B and transfer some data to ability B, it can use Want a carrier to transfer the data.

**File to include**: <AbilityKit/ability_base/want.h>

**Library**: libability_base_want.so

**System capability**: SystemCapability.Ability.AbilityBase

**Since**: 15

**Related module**: [AbilityBase](_ability_base.md)


## Summary

### Files

| Name                                         | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [want.h](want__8h.md) | Declare Want-related capabilities.<br>**File to include**: <AbilityKit/ability_base/want.h><br>**Library**: libability_base_want.so|


### Structs

| Name                                                        | Description                        |
| ------------------------------------------------------------ | ---------------------------- |
| [AbilityBase_Element](_ability_base_element.md#abilitybase_element) {<br>    char* bundleName;<br>    char* moduleName;<br>    char* abilityName;<br>} | Element struct.|
| [AbilityBase_Want](_ability_base.md#abilitybase_want)  | Want struct.|


### Functions

| Name                                                        | Description                        |
| ------------------------------------------------------------ | ---------------------------- |
| [AbilityBase_Want](_ability_base.md#abilitybase_want)* [OH_AbilityBase_CreateWant](_ability_base.md#oh_abilitybase_createwant)([AbilityBase_Element](_ability_base_element.md#abilitybase_element) element) | Creates Want.|
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_DestroyWant](_ability_base.md#oh_abilitybase_destroywant)([AbilityBase_Want](_ability_base.md#abilitybase_want)* want) | Destroys Want. Want cannot be used after being destroyed. Otherwise, undefined behavior may occur.|
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_SetWantElement](_ability_base.md#oh_abilitybase_setwantelement)([AbilityBase_Want](_ability_base.md#abilitybase_want)* want, [AbilityBase_Element](_ability_base_element.md#abilitybase_element) element) | Sets the Element struct, which consists of **bundleName**, **moduleName**, and **abilityName** in Want.|
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_GetWantElement](_ability_base.md#oh_abilitybase_getwantelement)([AbilityBase_Want](_ability_base.md#abilitybase_want)* want, [AbilityBase_Element](_ability_base_element.md#abilitybase_element)* element) | Obtains the Element struct, which consists of **bundleName**, **moduleName**, and **abilityName** in Want.|
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_SetWantCharParam](_ability_base.md#oh_abilitybase_setwantcharparam)([AbilityBase_Want](_ability_base.md#abilitybase_want)* want, const char* key, const char* value) | Sets **Param** in Want. For details about **Param**, see [parameters in Want](js-apis-inner-ability-want.md).|
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_GetWantCharParam](_ability_base.md#oh_abilitybase_getwantcharparam)([AbilityBase_Want](_ability_base.md#abilitybase_want)* want, const char* key, char* value, size_t valueSize) | Obtains **Param** set by [OH_AbilityBase_SetWantCharParam](#oh_abilitybase_setwantcharparam) in Want.|
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_AddWantFd](_ability_base.md#oh_abilitybase_addwantfd)([AbilityBase_Want](_ability_base.md#abilitybase_want)* want, const char* key, int32_t fd) | Adds a Want file descriptor. The file descriptor can be obtained through [fs.open](../apis-core-file-kit/js-apis-file-fs.md#fsopen).|
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_GetWantFd](_ability_base.md#oh_abilitybase_getwantfd)([AbilityBase_Want](_ability_base.md#abilitybase_want)* want, const char* key, int32_t* fd) | Obtains a Want file descriptor.|
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_SetWantUri](_ability_base.md#oh_abilitybase_setwanturi)([AbilityBase_Want](#abilitybase_want)* want, const char* uri) |  Sets **uri** in Want. For details about **uri**, see [uri in Want](js-apis-app-ability-want.md).|
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_GetWantUri](_ability_base.md#oh_abilitybase_getwanturi)([AbilityBase_Want](#abilitybase_want)* want, char* uri, size_t uriSize) |  Obtains **uri** set in Want. For details about **uri**, see [uri in Want](js-apis-app-ability-want.md).|
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_SetWantInt32Param](_ability_base.md#oh_abilitybase_setwantint32param)([AbilityBase_Want](#abilitybase_want)* want, const char* key, int32_t value) |  Sets a value of the int32_t type in Want.|
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_GetWantInt32Param](_ability_base.md#oh_abilitybase_getwantint32param)([AbilityBase_Want](#abilitybase_want)* want, const char* key, int32_t* value) |  Obtains a value of the int32_t type set in Want.|
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_SetWantBoolParam](_ability_base.md#oh_abilitybase_setwantboolparam)([AbilityBase_Want](#abilitybase_want)* want, const char* key, bool value) |  Sets a value of the bool type in Want.|
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_GetWantBoolParam](_ability_base.md#oh_abilitybase_getwantboolparam)([AbilityBase_Want](#abilitybase_want)* want, const char* key, bool* value) |  Obtains a value of the bool type set in Want.|
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_SetWantDoubleParam](_ability_base.md#oh_abilitybase_setwantdoubleparam)([AbilityBase_Want](#abilitybase_want)* want, const char* key, double value) |  Sets a value of the double type in Want.|
| [AbilityBase_ErrorCode](_ability_base.md#abilitybase_errorcode) [OH_AbilityBase_GetWantDoubleParam](_ability_base.md#oh_abilitybase_getwantdoubleparam)([AbilityBase_Want](#abilitybase_want)* want, const char* key, double* value) |  Obtains a value of the double type set in Want.|
