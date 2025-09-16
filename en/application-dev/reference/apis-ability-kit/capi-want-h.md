# want.h

## Overview

Want is a carrier for information transfer between objects (application components). Want can be used as a parameter of **startAbility** to specify a startup target and information that needs to be carried during startup, for example, **bundleName** and **abilityName**, which respectively indicate the bundle name of the target ability and the ability name in the bundle. When ability A needs to start ability B and transfer some data to ability B, it can use Want a carrier to transfer the data.

**File to include**: <AbilityKit/ability_base/want.h>

**Library**: libability_base_want.so

**System capability**: SystemCapability.Ability.AbilityBase

**Since**: 15

**Related module**: [AbilityBase](capi-abilitybase.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [AbilityBase_Element](capi-abilitybase-element.md) | AbilityBase_Element | Declares the Element struct in Want.|
| [AbilityBase_Want](capi-abilitybase-want.md) | AbilityBase_Want | Declares the struct of Want data.|

### Functions

| Name| Description|
| -- | -- |
| [AbilityBase_Want* OH_AbilityBase_CreateWant(AbilityBase_Element element)](#oh_abilitybase_createwant) | Creates Want.|
| [AbilityBase_ErrorCode OH_AbilityBase_DestroyWant(AbilityBase_Want* want)](#oh_abilitybase_destroywant) | Destroys Want. Want cannot be used after being destroyed. Otherwise, undefined behavior may occur.|
| [AbilityBase_ErrorCode OH_AbilityBase_SetWantElement(AbilityBase_Want* want, AbilityBase_Element element)](#oh_abilitybase_setwantelement) | Sets the Element struct, which consists of **bundleName**, **moduleName**, and **abilityName** in Want.|
| [AbilityBase_ErrorCode OH_AbilityBase_GetWantElement(AbilityBase_Want* want, AbilityBase_Element* element)](#oh_abilitybase_getwantelement) | Obtains the Element struct, which consists of **bundleName**, **moduleName**, and **abilityName** in Want.|
| [AbilityBase_ErrorCode OH_AbilityBase_SetWantCharParam(AbilityBase_Want* want, const char* key, const char* value)](#oh_abilitybase_setwantcharparam) | Sets **Param** in Want.|
| [AbilityBase_ErrorCode OH_AbilityBase_GetWantCharParam(AbilityBase_Want* want, const char* key,char* value, size_t valueSize)](#oh_abilitybase_getwantcharparam) | Obtains **Param** in Want.|
| [AbilityBase_ErrorCode OH_AbilityBase_AddWantFd(AbilityBase_Want* want, const char* key, int32_t fd)](#oh_abilitybase_addwantfd) | Adds a Want file descriptor.|
| [AbilityBase_ErrorCode OH_AbilityBase_GetWantFd(AbilityBase_Want* want, const char* key, int32_t* fd)](#oh_abilitybase_getwantfd) | Obtains a Want file descriptor.|
| [AbilityBase_ErrorCode OH_AbilityBase_SetWantUri(AbilityBase_Want* want, const char* uri)](#oh_abilitybase_setwanturi) | Sets **uri** in Want.|
| [AbilityBase_ErrorCode OH_AbilityBase_GetWantUri(AbilityBase_Want* want, char* uri, size_t uriSize)](#oh_abilitybase_getwanturi) | Obtains **uri** set in Want. For details about the URI, see [uri in Want](js-apis-app-ability-want.md).|
| [AbilityBase_ErrorCode OH_AbilityBase_SetWantInt32Param(AbilityBase_Want* want, const char* key, int32_t value)](#oh_abilitybase_setwantint32param) | Sets a value of the int32_t type in Want.|
| [AbilityBase_ErrorCode OH_AbilityBase_GetWantInt32Param(AbilityBase_Want* want, const char* key, int32_t* value)](#oh_abilitybase_getwantint32param) | Obtains a value of the int32_t type set in Want.|
| [AbilityBase_ErrorCode OH_AbilityBase_SetWantBoolParam(AbilityBase_Want* want, const char* key, bool value)](#oh_abilitybase_setwantboolparam) | Sets a value of the bool type in Want.|
| [AbilityBase_ErrorCode OH_AbilityBase_GetWantBoolParam(AbilityBase_Want* want, const char* key, bool* value)](#oh_abilitybase_getwantboolparam) | Obtains a value of the bool type set in Want.|
| [AbilityBase_ErrorCode OH_AbilityBase_SetWantDoubleParam(AbilityBase_Want* want, const char* key, double value)](#oh_abilitybase_setwantdoubleparam) | Sets a value of the double type in Want.|
| [AbilityBase_ErrorCode OH_AbilityBase_GetWantDoubleParam(AbilityBase_Want* want, const char* key, double* value)](#oh_abilitybase_getwantdoubleparam) | Obtains a value of the double type set in Want.|

## Function Description

### OH_AbilityBase_CreateWant()

```
AbilityBase_Want* OH_AbilityBase_CreateWant(AbilityBase_Element element)
```

**Description**

Creates Want.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [AbilityBase_Element](capi-abilitybase-element.md) element | Element struct.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* | Pointer to Want.|

### OH_AbilityBase_DestroyWant()

```
AbilityBase_ErrorCode OH_AbilityBase_DestroyWant(AbilityBase_Want* want)
```

**Description**

Destroys Want. Want cannot be used after being destroyed. Otherwise, undefined behavior may occur.

**Since**: 15

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Pointer to Want.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | One of the following execution results:<br>**ABILITY_BASE_ERROR_CODE_NO_ERROR**: Want is destroyed.<br>**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **element** is invalid.|

### OH_AbilityBase_SetWantElement()

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantElement(AbilityBase_Want* want, AbilityBase_Element element)
```

**Description**

Sets the Element struct, which consists of **bundleName**, **moduleName**, and **abilityName** in Want.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Pointer to Want.|
| [AbilityBase_Element](capi-abilitybase-element.md) element | Element struct.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | One of the following execution results:<br>**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The setting is successful.<br>**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or **element** is invalid.|

### OH_AbilityBase_GetWantElement()

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantElement(AbilityBase_Want* want, AbilityBase_Element* element)
```

**Description**

Obtains the Element struct, which consists of **bundleName**, **moduleName**, and **abilityName** in Want.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Pointer to Want.|
| [AbilityBase_Element](capi-abilitybase-element.md)* element | Pointer to the Element struct.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | One of the following execution results:<br>**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The element struct is obtained.<br>**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or **element** is invalid.|

### OH_AbilityBase_SetWantCharParam()

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantCharParam(AbilityBase_Want* want, const char* key, const char* value)
```

**Description**

Sets **Param** in Want. For details about **Param**, see [parameters in Want](js-apis-inner-ability-want.md).

**Since**: 15

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Pointer to Want.|
| const char* key | Pointer to a key in Want.|
| const char* value | Pointer to the value of the key in Want.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | One of the following execution results:<br>**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The setting is successful.<br>**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.|

### OH_AbilityBase_GetWantCharParam()

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantCharParam(AbilityBase_Want* want, const char* key,char* value, size_t valueSize)
```

**Description**

Obtains **Param** set by [OH_AbilityBase_SetWantCharParam](#oh_abilitybase_setwantcharparam) in Want.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Pointer to Want.|
| const char* key | Pointer to a key in Want.|
| char* value | Pointer to the value of the key in Want.|
| size_t valueSize | Length of the value string. If **valueSize** is less than the actual value length, the [ABILITY_BASE_ERROR_CODE_PARAM_INVALID](capi-ability-base-common-h.md#abilitybase_errorcode) error is reported.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | One of the following execution results:<br>**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The param struct is obtained.<br>**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.|

### OH_AbilityBase_AddWantFd()

```
AbilityBase_ErrorCode OH_AbilityBase_AddWantFd(AbilityBase_Want* want, const char* key, int32_t fd)
```

**Description**

Adds a Want file descriptor. The file descriptor can be obtained through [fs.open](../apis-core-file-kit/js-apis-file-fs.md#fsopen).

**Since**: 15

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want |  Pointer to Want.|
| const char* key | Pointer to a key in Want.|
| int32_t fd | File descriptor, which is obtained by calling [fs.open](../apis-core-file-kit/js-apis-file-fs.md#fsopen).|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | One of the following execution results:<br>**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The Want file descriptor is added.<br>**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.|

### OH_AbilityBase_GetWantFd()

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantFd(AbilityBase_Want* want, const char* key, int32_t* fd)
```

**Description**

Obtains a Want file descriptor.

**Since**: 15

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Pointer to Want.|
| const char* key | Pointer to a key in Want.|
| int32_t* fd | Pointer to the file descriptor.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | One of the following execution results:<br>**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The Want file descriptor is obtained.<br>**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.|

### OH_AbilityBase_SetWantUri()

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantUri(AbilityBase_Want* want, const char* uri)
```

**Description**

Sets **uri** in Want. For details about the URI, see [uri in Want](js-apis-app-ability-want.md).

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Pointer to Want.|
| const char* uri | Pointer to a URI. If a URI is specified in Want, Want will match the specified URI information. For details about the URI, see [uri in Want](js-apis-app-ability-want.md).|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | One of the following execution results:<br>**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The setting is successful.<br>**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.|

### OH_AbilityBase_GetWantUri()

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantUri(AbilityBase_Want* want, char* uri, size_t uriSize)
```

**Description**

Obtains **uri** set in Want. For details about the URI, see [uri in Want](js-apis-app-ability-want.md).

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Pointer to Want.|
| char* uri | Pointer to a URI. If a URI is specified in Want, Want will match the specified URI information. For details about the URI, see [uri in Want](js-apis-app-ability-want.md).|
| size_t uriSize | Length of the URI string. If **uriSize** is less than the actual URI length, the [ABILITY_BASE_ERROR_CODE_PARAM_INVALID](capi-ability-base-common-h.md#abilitybase_errorcode) error is reported.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | One of the following execution results:<br>**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The URI string in Want is obtained.<br>**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.|

### OH_AbilityBase_SetWantInt32Param()

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantInt32Param(AbilityBase_Want* want, const char* key, int32_t value)
```

**Description**

Sets a value of the int32_t type in Want.

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Pointer to Want.|
| const char* key | Pointer to a key in Want.|
| int32_t value | Value of the int32_t type of the key.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | One of the following execution results:<br>**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The setting is successful.<br>**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.|

### OH_AbilityBase_GetWantInt32Param()

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantInt32Param(AbilityBase_Want* want, const char* key, int32_t* value)
```

**Description**

Obtains a value of the int32_t type set in Want.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Pointer to Want.|
| const char* key | Pointer to a key in Want.|
| int32_t* value | Pointer to the value of the int32_t type of the key.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | One of the following execution results:<br>**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The value of the int32_t type is obtained.<br>**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.|

### OH_AbilityBase_SetWantBoolParam()

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantBoolParam(AbilityBase_Want* want, const char* key, bool value)
```

**Description**

Sets a value of the bool type in Want.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Pointer to Want.|
| const char* key | Pointer to a key in Want.|
| bool value | Value of the bool type of the key.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | One of the following execution results:<br>**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The setting is successful.<br>**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.|

### OH_AbilityBase_GetWantBoolParam()

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantBoolParam(AbilityBase_Want* want, const char* key, bool* value)
```

**Description**

Obtains a value of the bool type set in Want.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Pointer to Want.|
| const char* key | Pointer to a key in Want.|
| bool* value | Pointer to the value of the bool type of the key.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | One of the following execution results:<br>**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The value of the bool type is obtained.<br>**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.|

### OH_AbilityBase_SetWantDoubleParam()

```
AbilityBase_ErrorCode OH_AbilityBase_SetWantDoubleParam(AbilityBase_Want* want, const char* key, double value)
```

**Description**

Sets a value of the double type in Want.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Pointer to Want.|
| const char* key | Pointer to a key in Want.|
| double value | Value of the double type of the key.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | One of the following execution results:<br>**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The setting is successful.<br>**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.|

### OH_AbilityBase_GetWantDoubleParam()

```
AbilityBase_ErrorCode OH_AbilityBase_GetWantDoubleParam(AbilityBase_Want* want, const char* key, double* value)
```

**Description**

Obtains a value of the double type set in Want.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md)* want | Pointer to Want.|
| const char* key | Pointer to a key in Want.|
| double* value | Pointer to the value of the double type of the key.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityBase_ErrorCode](capi-ability-base-common-h.md#abilitybase_errorcode) | One of the following execution results:<br>**ABILITY_BASE_ERROR_CODE_NO_ERROR**: The value of the double type is obtained.<br>**ABILITY_BASE_ERROR_CODE_PARAM_INVALID**: **want** is null or invalid.|
