# inputmethod_private_command_capi.h
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @illybyy-->
<!--SE: @andeszhang-->
<!--TSE: @murphy1984-->

## Overview

Provides methods for creating, destroying, reading, and writing private data objects.

**Header file**: <inputmethod/inputmethod_private_command_capi.h>

**Library**: libohinputmethod.so

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Since**: 12

**Related module**: [InputMethod](capi-inputmethod.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) | InputMethod_PrivateCommand | Private data exchanged between the text box and the input method application.|

### Functions

| Name| Description                                                 |
| -- |-----------------------------------------------------|
| [InputMethod_PrivateCommand *OH_PrivateCommand_Create(char key[], size_t keyLength)](#oh_privatecommand_create) | Creates an [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) instance.     |
| [void OH_PrivateCommand_Destroy(InputMethod_PrivateCommand *command)](#oh_privatecommand_destroy) | Destroys an [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) instance.          |
| [InputMethod_ErrorCode OH_PrivateCommand_SetKey(InputMethod_PrivateCommand *command, char key[], size_t keyLength)](#oh_privatecommand_setkey) | Sets the key value for [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md).         |
| [InputMethod_ErrorCode OH_PrivateCommand_SetBoolValue(InputMethod_PrivateCommand *command, bool value)](#oh_privatecommand_setboolvalue) | Sets the value of the Boolean type for [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md).   |
| [InputMethod_ErrorCode OH_PrivateCommand_SetIntValue(InputMethod_PrivateCommand *command, int32_t value)](#oh_privatecommand_setintvalue) | Sets the value of the integer type for [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md).   |
| [InputMethod_ErrorCode OH_PrivateCommand_SetStrValue(InputMethod_PrivateCommand *command, char value[], size_t valueLength)](#oh_privatecommand_setstrvalue) | Sets the value of the string type for [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md).  |
| [InputMethod_ErrorCode OH_PrivateCommand_GetKey(InputMethod_PrivateCommand *command, const char **key, size_t *keyLength)](#oh_privatecommand_getkey) | Obtains the key value from [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md).         |
| [InputMethod_ErrorCode OH_PrivateCommand_GetValueType(InputMethod_PrivateCommand *command, InputMethod_CommandValueType *type)](#oh_privatecommand_getvaluetype) | Obtains the data type of value from [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md).   |
| [InputMethod_ErrorCode OH_PrivateCommand_GetBoolValue(InputMethod_PrivateCommand *command, bool *value)](#oh_privatecommand_getboolvalue) | Obtains the value of the Boolean type from [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md). |
| [InputMethod_ErrorCode OH_PrivateCommand_GetIntValue(InputMethod_PrivateCommand *command, int32_t *value)](#oh_privatecommand_getintvalue) | Obtains the value of the integer type from [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md). |
| [InputMethod_ErrorCode OH_PrivateCommand_GetStrValue(InputMethod_PrivateCommand *command, const char **value, size_t *valueLength)](#oh_privatecommand_getstrvalue) | Obtains the value of the string type from [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md).|

## Function Description

### OH_PrivateCommand_Create()

```
InputMethod_PrivateCommand *OH_PrivateCommand_Create(char key[], size_t keyLength)
```

**Description**

Creates an [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| char key[] | Key value of the private data.|
| size_t keyLength | Key length.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) * | If the operation is successful, a pointer to the created [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) instance is returned.<br> If the operation failed, **NULL** is returned, which may be caused by insufficient application address space.|

### OH_PrivateCommand_Destroy()

```
void OH_PrivateCommand_Destroy(InputMethod_PrivateCommand *command)
```

**Description**

Destroys an [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | Pointer to the [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) instance to be destroyed.|

### OH_PrivateCommand_SetKey()

```
InputMethod_ErrorCode OH_PrivateCommand_SetKey(InputMethod_PrivateCommand *command, char key[], size_t keyLength)
```

**Description**

Sets the key value for [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | Pointer to the [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) instance to be set.|
| char key[] | Key value.|
| size_t keyLength | Key length.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_PrivateCommand_SetBoolValue()

```
InputMethod_ErrorCode OH_PrivateCommand_SetBoolValue(InputMethod_PrivateCommand *command, bool value)
```

**Description**

Sets the value of the Boolean type for [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | Pointer to the [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) instance to be set.|
| bool value | Boolean value.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_PrivateCommand_SetIntValue()

```
InputMethod_ErrorCode OH_PrivateCommand_SetIntValue(InputMethod_PrivateCommand *command, int32_t value)
```

**Description**

Sets the value of the integer type for [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | Pointer to the [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) instance to be set.|
| int32_t value | Integer value.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_PrivateCommand_SetStrValue()

```
InputMethod_ErrorCode OH_PrivateCommand_SetStrValue(InputMethod_PrivateCommand *command, char value[], size_t valueLength)
```

**Description**

Sets the value of the string type for [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | Pointer to the [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) instance to be set.|
| char value[] | Value of the string type.|
| size_t valueLength | Value length.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_PrivateCommand_GetKey()

```
InputMethod_ErrorCode OH_PrivateCommand_GetKey(InputMethod_PrivateCommand *command, const char **key, size_t *keyLength)
```

**Description**

Obtains the key value from [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | Pointer to the [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) instance from which the key value is to be obtained.|
| const char **key | The lifespan of **key** is consistent with that of **command**. You are advised to copy instead of directly saving the key address or writing **key**.  |
| size_t *keyLength | Key length.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_PrivateCommand_GetValueType()

```
InputMethod_ErrorCode OH_PrivateCommand_GetValueType(InputMethod_PrivateCommand *command, InputMethod_CommandValueType *type)
```

**Description**

Obtains the data type of value from [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | Pointer to the [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) instance from which the value is to be obtained.|
| [InputMethod_CommandValueType](capi-inputmethod-types-capi-h.md#inputmethod_commandvaluetype) *type | Pointer to the [InputMethod_CommandValueType](capi-inputmethod-types-capi-h.md#inputmethod_commandvaluetype) instance, used to indicate the data type of the value.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_PrivateCommand_GetBoolValue()

```
InputMethod_ErrorCode OH_PrivateCommand_GetBoolValue(InputMethod_PrivateCommand *command, bool *value)
```

**Description**

Obtains the value of the Boolean type from [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | Pointer to the [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) instance from which the value is to be obtained.|
| bool *value | Boolean value.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br>     [IME_ERR_QUERY_FAILED](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Query failed as the command contains no Boolean value.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_PrivateCommand_GetIntValue()

```
InputMethod_ErrorCode OH_PrivateCommand_GetIntValue(InputMethod_PrivateCommand *command, int32_t *value)
```

**Description**

Obtains the value of the integer type from [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | Pointer to the [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) instance from which the value is to be obtained.|
| int32_t *value | Value of the integer type.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br>     [IME_ERR_QUERY_FAILED](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Query failed as the command contains no Boolean value.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_PrivateCommand_GetStrValue()

```
InputMethod_ErrorCode OH_PrivateCommand_GetStrValue(InputMethod_PrivateCommand *command, const char **value, size_t *valueLength)
```

**Description**

Obtains the value of the string type from [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *command | Pointer to the [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) instance from which the value is to be obtained.|
| const char **value | Value of the string type.|
| size_t *valueLength | The lifespan of **value** is consistent with that of **command**. You are advised to copy instead of directly saving the value address or writing **value**.  |

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br>     [IME_ERR_QUERY_FAILED](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Query failed as the command contains no Boolean value.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|
