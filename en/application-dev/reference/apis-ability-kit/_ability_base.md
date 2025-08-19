# AbilityBase

## Overview

As the basic definition module of Ability Kit, AbilityBase provides definitions and APIs for [Want](want__8h.md), which can be used to transfer information between application components.

**System capability**: SystemCapability.Ability.AbilityBase

**Since**: 15

## Summary


### Files

| Name| Description|
| -------- | -------- |
| [ability_base_common.h](ability__base__common_8h.md) | Declares the error codes related to AbilityBase.<br>**File to include**: <AbilityKit/ability_base/ability_base_common.h><br>**Library**: libability_base_want.so|
| [want.h](want__8h.md) | Declares the capabilities related to [Want](want__8h.md).<br>**File to include**: <AbilityKit/ability_base/want.h><br>**Library**: libability_base_want.so|

### Enums

| Name                                                        | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| [AbilityBase_ErrorCode](#abilitybase_errorcode) {<br>    ABILITY_BASE_ERROR_CODE_NO_ERROR = 0,<br>    ABILITY_BASE_ERROR_CODE_PARAM_INVALID = 401,<br>} | Enumerates the AbilityBase error codes.|

### Structs

| Name                                                        | Description                        |
| ------------------------------------------------------------ | ---------------------------- |
| [AbilityBase_Element](_ability_base_element.md) {<br>    char* bundleName;<br>    char* moduleName;<br>    char* abilityName;<br>} | Element struct.|
| [AbilityBase_Want](#abilitybase_want)  | Want struct.|

### Functions

| Name                                                        | Description                        |
| ------------------------------------------------------------ | ---------------------------- |
| [AbilityBase_Want](#abilitybase_want)* [OH_AbilityBase_CreateWant](#oh_abilitybase_createwant)([AbilityBase_Element](_ability_base_element.md) element) | Creates Want.|
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_DestroyWant](#oh_abilitybase_destroywant)([AbilityBase_Want](#abilitybase_want)* want) | Destroys Want. Want cannot be used after being destroyed. Otherwise, undefined behavior may occur.|
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_SetWantElement](#oh_abilitybase_setwantelement)([AbilityBase_Want](#abilitybase_want)* want, [AbilityBase_Element](_ability_base_element.md) element) | Sets the Element struct, which consists of **bundleName**, **moduleName**, and **abilityName** in Want.|
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_GetWantElement](#oh_abilitybase_getwantelement)([AbilityBase_Want](#abilitybase_want)* want, [AbilityBase_Element](_ability_base_element.md)* element) | Obtains the Element struct, which consists of **bundleName**, **moduleName**, and **abilityName** in Want.|
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_SetWantCharParam](#oh_abilitybase_setwantcharparam)([AbilityBase_Want](#abilitybase_want)* want, const char* key, const char* value) | Sets **Param** in Want. For details about **Param**, see [parameters in Want](js-apis-inner-ability-want.md).|
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_GetWantCharParam](#oh_abilitybase_getwantcharparam)([AbilityBase_Want](#abilitybase_want)* want, const char* key, char* value, size_t valueSize) | Obtains **Param** set by [OH_AbilityBase_SetWantCharParam](#oh_abilitybase_setwantcharparam) in Want.|
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_AddWantFd](#oh_abilitybase_addwantfd)([AbilityBase_Want](#abilitybase_want)* want, const char* key, int32_t fd) | Adds a Want file descriptor. The file descriptor can be obtained through [fs.open](../apis-core-file-kit/js-apis-file-fs.md#fsopen).|
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_GetWantFd](#oh_abilitybase_getwantfd)([AbilityBase_Want](#abilitybase_want)* want, const char* key, int32_t* fd) |  Obtains a Want file descriptor.|
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_SetWantUri](#oh_abilitybase_setwanturi)([AbilityBase_Want](#abilitybase_want)* want, const char* uri) |  Sets **uri** in Want. For details about **uri**, see [uri in Want](js-apis-app-ability-want.md).|
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_GetWantUri](#oh_abilitybase_getwanturi)([AbilityBase_Want](#abilitybase_want)* want, char* uri, size_t uriSize) |  Obtains **uri** set in Want. For details about **uri**, see [uri in Want](js-apis-app-ability-want.md).|
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_SetWantInt32Param](#oh_abilitybase_setwantint32param)([AbilityBase_Want](#abilitybase_want)* want, const char* key, int32_t value) |  Sets a value of the int32_t type in Want.|
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_GetWantInt32Param](#oh_abilitybase_getwantint32param)([AbilityBase_Want](#abilitybase_want)* want, const char* key, int32_t* value) |  Obtains a value of the int32_t type set in Want.|
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_SetWantBoolParam](#oh_abilitybase_setwantboolparam)([AbilityBase_Want](#abilitybase_want)* want, const char* key, bool value) |  Sets a value of the bool type in Want.|
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_GetWantBoolParam](#oh_abilitybase_getwantboolparam)([AbilityBase_Want](#abilitybase_want)* want, const char* key, bool* value) |  Obtains a value of the bool type set in Want.|
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_SetWantDoubleParam](#oh_abilitybase_setwantdoubleparam)([AbilityBase_Want](#abilitybase_want)* want, const char* key, double value) |  Sets a value of the double type in Want.|
| [AbilityBase_ErrorCode](#abilitybase_errorcode) [OH_AbilityBase_GetWantDoubleParam](#oh_abilitybase_getwantdoubleparam)([AbilityBase_Want](#abilitybase_want)* want, const char* key, double* value) |  Obtains a value of the double type set in Want.|



## Enum Description

### AbilityBase_ErrorCode

```
enum AbilityBase_ErrorCode
```

**Description**

Enumerates the AbilityBase error codes.

**Since**: 15

| Value                                       | Description          |
| --------------------------------------------- | -------------- |
| ABILITY_BASE_ERROR_CODE_NO_ERROR           | Operation successful.    |
| ABILITY_BASE_ERROR_CODE_PARAM_INVALID      | Invalid parameter.    |


## Struct Description

### AbilityBase_Want

```
AbilityBase_Want
```

**Description**

Want struct.

**Since**: 15


## Function Description


### OH_AbilityBase_CreateWant

```
AbilityBase_Want* OH_AbilityBase_CreateWant(AbilityBase_Element element)
```
**Description**

Creates Want.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| element | Element struct.|

**Returns**

**AbilityBase_Want**, which is a Want struct.


### OH_AbilityBase_DestroyWant

```
AbilityBase_ErrorCode OH_AbilityBase_DestroyWant(AbilityBase_Want* want)
```
**Description**

Destroys Want. Want cannot be used after being destroyed. Otherwise, undefined behavior may occur.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| want | Pointer to Want.|

**Returns**

**ABILITY_BASE_ERROR_CODE_NO_ERROR**: Want is destroyed.

**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **element** is invalid.

### OH_AbilityBase_SetWantElement

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantElement(AbilityBase_Want* want, AbilityBase_Element element)
```
**Description**

Sets the Element struct, which consists of **bundleName**, **moduleName**, and **abilityName** in Want.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| want | Pointer to Want.|
| element | Element struct.|

**Returns**

**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The setting is successful.

**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or **element** is invalid.

### OH_AbilityBase_GetWantElement

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantElement(AbilityBase_Want* want, AbilityBase_Element* element)
```
**Description**

Obtains the Element struct, which consists of **bundleName**, **moduleName**, and **abilityName** in Want.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| want | Pointer to Want.|
| element | Pointer to the Element struct.|

**Returns**

**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The element struct is obtained.

**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or **element** is invalid.

### OH_AbilityBase_SetWantCharParam

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantCharParam(AbilityBase_Want* want, const char* key, const char* value)
```
**Description**

Sets **Param** in Want. For details about **Param**, see [parameters in Want](js-apis-inner-ability-want.md).

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| want | Pointer to Want.|
| key | Pointer to a key in Want.|
| value | Pointer to the value of the key in Want.|

**Returns**

**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The setting is successful.

**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.

### OH_AbilityBase_GetWantCharParam

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantCharParam(AbilityBase_Want* want, const char* key, char* value, size_t valueSize)
```
**Description**

Obtains **Param** set by [OH_AbilityBase_SetWantCharParam](#oh_abilitybase_setwantcharparam) in Want.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| want | Pointer to Want.|
| key | Pointer to a key in Want.|
| value | Pointer to the value of the key in Want.|
| valueSize | Length of the value string. If **valueSize** is less than the actual value length, the **ABILITY_BASE_ERROR_CODE_PARAM_INVALID** error is reported.|

**Returns**

**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The param struct is obtained.

**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.

### OH_AbilityBase_AddWantFd

```
AbilityBase_ErrorCode OH_AbilityBase_AddWantFd(AbilityBase_Want* want, const char* key, int32_t fd)
```
**Description**

Adds a Want file descriptor. The file descriptor can be obtained through [fs.open](../apis-core-file-kit/js-apis-file-fs.md#fsopen).

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| want | Pointer to Want.|
| key | Pointer to a key in Want.|
| fd | File descriptor, which is obtained by calling [fs.open](../apis-core-file-kit/js-apis-file-fs.md#fsopen).|

**Returns**

**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The Want file descriptor is added.

**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.

### OH_AbilityBase_GetWantFd

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantFd(AbilityBase_Want* want, const char* key, int32_t* fd)
```
**Description**

Obtains a Want file descriptor.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| want | Pointer to Want.|
| key | Pointer to a key in Want.|
| fd | Pointer to the file descriptor.|

**Returns**

**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The Want file descriptor is obtained.

**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.

### OH_AbilityBase_SetWantUri

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantUri(AbilityBase_Want* want, const char* uri)
```
**Description**

Sets **uri** in Want. For details about **uri**, see [uri in Want](js-apis-app-ability-want.md).

**Since**: 17

**Parameters**

| Name| Description|
| -------- | -------- |
| want | Pointer to Want.|
| uri | Pointer to a URI. If a URI is specified in Want, Want will match the specified URI information. For details, see [uri in Want](js-apis-app-ability-want.md).|

**Returns**

**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The setting is successful.

**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.

### OH_AbilityBase_GetWantUri

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantUri(AbilityBase_Want* want, char* uri, size_t uriSize)
```
**Description**

Obtains **uri** set in Want. For details about **uri**, see [uri in Want](js-apis-app-ability-want.md).

**Since**: 17

**Parameters**

| Name| Description|
| -------- | -------- |
| want | Pointer to Want.|
| uri | Pointer to a URI. If a URI is specified in Want, Want will match the specified URI information. For details, see [uri in Want](js-apis-app-ability-want.md).|
| uriSize | Length of the URI string. If **uriSize** is less than the actual URI length, the **ABILITY_BASE_ERROR_CODE_PARAM_INVALID** error is reported.|

**Returns**

**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The URI string in Want is obtained.

**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.

### OH_AbilityBase_SetWantInt32Param

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantInt32Param(AbilityBase_Want* want, const char* key, int32_t value)
```
**Description**

Sets a value of the int32_t type in Want.

**Since**: 17

**Parameters**

| Name| Description|
| -------- | -------- |
| want | Pointer to Want.|
| key | Pointer to the key in Want.|
| value | Value of the int32_t type of the key.|

**Returns**

**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The setting is successful.

**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.

### OH_AbilityBase_GetWantInt32Param

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantInt32Param(AbilityBase_Want* want, const char* key, int32_t* value)
```
**Description**

Obtains a value of the int32_t type set in Want.

**Since**: 17

**Parameters**

| Name| Description|
| -------- | -------- |
| want | Pointer to Want.|
| key | Pointer to the key in Want.|
| value | Pointer to the value of the int32_t type of the key.|

**Returns**

**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The value of the int32_t type is obtained.

**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.


### OH_AbilityBase_SetWantBoolParam

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantBoolParam(AbilityBase_Want* want, const char* key, bool value)
```
**Description**

Sets a value of the bool type in Want.

**Since**: 17

**Parameters**

| Name| Description|
| -------- | -------- |
| want | Pointer to Want.|
| key | Pointer to the key in Want.|
| value | Value of the bool type of the key.|

**Returns**

**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The setting is successful.

**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.

### OH_AbilityBase_GetWantBoolParam

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantBoolParam(AbilityBase_Want* want, const char* key, bool* value)
```
**Description**

Obtains a value of the bool type set in Want.

**Since**: 17

**Parameters**

| Name| Description|
| -------- | -------- |
| want | Pointer to Want.|
| key | Pointer to the key in Want.|
| value | Pointer to the value of the bool type of the key.|

**Returns**

**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The value of the bool type is obtained.

**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.

### OH_AbilityBase_SetWantDoubleParam

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantDoubleParam(AbilityBase_Want* want, const char* key, double value)
```
**Description**

Sets a value of the double type in Want.

**Since**: 17

**Parameters**

| Name| Description|
| -------- | -------- |
| want | Pointer to Want.|
| key | Pointer to the key in Want.|
| value | Value of the double type of the key.|

**Returns**

**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The setting is successful.

**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.

### OH_AbilityBase_GetWantDoubleParam

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantDoubleParam(AbilityBase_Want* want, const char* key, double* value)
```
**Description**

Obtains a value of the double type set in Want.

**Since**: 17

**Parameters**

| Name| Description|
| -------- | -------- |
| want | Pointer to Want.|
| key | Pointer to the key in Want.|
| value | Pointer to the value of the double type of the key.|

**Returns**

**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The value of the double type is successfully obtained.

**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.
