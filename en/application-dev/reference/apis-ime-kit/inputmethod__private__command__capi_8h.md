# inputmethod_private_command_capi.h


## Overview

Provides methods for creating, destroying, reading, and writing private data objects.

**Library**: libohinputmethod.so

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Since**: 12

**Related module**: [InputMethod](_input_method.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| [InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) | Private data.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \* [OH_PrivateCommand_Create](_input_method.md#oh_privatecommand_create) (char key[], size_t keyLength) | Creates an [InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) instance.| 
| void [OH_PrivateCommand_Destroy](_input_method.md#oh_privatecommand_destroy) ([InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \*command) | Destroys an [InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) instance.| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_PrivateCommand_SetKey](_input_method.md#oh_privatecommand_setkey) ([InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \*command, char key[], size_t keyLength) | Sets the key value for [InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand).| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_PrivateCommand_SetBoolValue](_input_method.md#oh_privatecommand_setboolvalue) ([InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \*command, bool value) | Sets the value of the Boolean type for [InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand).| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_PrivateCommand_SetIntValue](_input_method.md#oh_privatecommand_setintvalue) ([InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \*command, int32_t value) | Sets the value of the integer type for [InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand).| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_PrivateCommand_SetStrValue](_input_method.md#oh_privatecommand_setstrvalue) ([InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \*command, char value[], size_t valueLength) | Sets the value of the character string type for [InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand).| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_PrivateCommand_GetKey](_input_method.md#oh_privatecommand_getkey) ([InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \*command, const char \*\*key, size_t \*keyLength) | Obtains the key value from [InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand).| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_PrivateCommand_GetValueType](_input_method.md#oh_privatecommand_getvaluetype) ([InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \*command, [InputMethod_CommandValueType](_input_method.md#inputmethod_commandvaluetype) \*type) | Obtains the data type of **value** from [InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand).| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_PrivateCommand_GetBoolValue](_input_method.md#oh_privatecommand_getboolvalue) ([InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \*command, bool \*value) | Obtains the value of the Boolean type from [InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand).| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_PrivateCommand_GetIntValue](_input_method.md#oh_privatecommand_getintvalue) ([InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \*command, int32_t \*value) | Obtains the value of the integer type from [InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand).| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_PrivateCommand_GetStrValue](_input_method.md#oh_privatecommand_getstrvalue) ([InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \*command, const char \*\*value, size_t \*valueLength) | Obtains the value of the character string type from [InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand).| 
