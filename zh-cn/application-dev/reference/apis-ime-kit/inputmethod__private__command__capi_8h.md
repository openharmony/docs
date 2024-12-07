# inputmethod_private_command_capi.h


## 概述

提供私有数据对象的创建、销毁与读写方法。

**库：** libohinputmethod.so

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**起始版本：** 12

**相关模块：**[InputMethod](_input_method.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) | 私有数据。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \* [OH_PrivateCommand_Create](_input_method.md#oh_privatecommand_create) (char key[], size_t keyLength) | 创建一个新的[InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand)实例。 | 
| void [OH_PrivateCommand_Destroy](_input_method.md#oh_privatecommand_destroy) ([InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \*command) | 销毁一个[InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand)实例。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_PrivateCommand_SetKey](_input_method.md#oh_privatecommand_setkey) ([InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \*command, char key[], size_t keyLength) | 设置[InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand)的key值。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_PrivateCommand_SetBoolValue](_input_method.md#oh_privatecommand_setboolvalue) ([InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \*command, bool value) | 设置[InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand)的布尔类型value值。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_PrivateCommand_SetIntValue](_input_method.md#oh_privatecommand_setintvalue) ([InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \*command, int32_t value) | 设置[InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand)的整数类型value值。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_PrivateCommand_SetStrValue](_input_method.md#oh_privatecommand_setstrvalue) ([InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \*command, char value[], size_t valueLength) | 设置[InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand)的字符串类型value值。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_PrivateCommand_GetKey](_input_method.md#oh_privatecommand_getkey) ([InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \*command, const char \*\*key, size_t \*keyLength) | 从[InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand)获取key值。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_PrivateCommand_GetValueType](_input_method.md#oh_privatecommand_getvaluetype) ([InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \*command, [InputMethod_CommandValueType](_input_method.md#inputmethod_commandvaluetype) \*type) | 从[InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand)获取value的数据类型。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_PrivateCommand_GetBoolValue](_input_method.md#oh_privatecommand_getboolvalue) ([InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \*command, bool \*value) | 从[InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand)获取布尔类型的value的值。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_PrivateCommand_GetIntValue](_input_method.md#oh_privatecommand_getintvalue) ([InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \*command, int32_t \*value) | 从[InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand)获取整数类型的value的值。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_PrivateCommand_GetStrValue](_input_method.md#oh_privatecommand_getstrvalue) ([InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand) \*command, const char \*\*value, size_t \*valueLength) | 从[InputMethod_PrivateCommand](_input_method.md#inputmethod_privatecommand)获取字符串类型的value的值。 | 
