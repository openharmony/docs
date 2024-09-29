# HdiSecureElement


## 概述

为SecureElement服务提供统一的访问安全单元的接口。

SecureElement服务通过获取SecureElementInterface对象提供的API接口访问安全单元，包括初始化、 判断安全单元状态、创建关闭逻辑通道、与SE进行APDU指令交互等。

**起始版本：** 4.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [ISecureElementCallback.idl](_i_secure_element_callback_8idl.md) | 定义回调的接口文件 | 
| [ISecureElementInterface.idl](_i_secure_element_interface_8idl.md) | 定义SecureElement初始化、操作通道、利用通道与安全单元进行APDU指令交互的接口文件 | 
| [SecureElementTypes.idl](_secure_element_types_8idl.md) | Open Mobile API规范中定义的错误类型。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[ISecureElementCallback](interface_i_secure_element_callback.md) | 声明从SecureElement HDF到SecureElement服务的报告状态回调。 | 
| interface&nbsp;&nbsp;[ISecureElementInterface](interface_i_secure_element_interface.md) | 声明由SecureElement模块提供的用于获取SecureElement操作的API， 请参阅“Open Mobile API 规范”。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [SecureElementStatus](#secureelementstatus) {<br/>SE_SUCCESS = 0 , SE_NULL_POINTER_ERROR , SE_ILLEGAL_PARAMETER_ERROR , SE_ILLEGAL_STATE_ERROR , SE_SECURITY_ERROR , SE_CHANNEL_NOT_AVAILABLE_ERROR , SE_NO_SUCH_ELEMENT_ERROR , SE_ILLEGAL_REFERENCE_ERROR , SE_OPERATION_NOT_SUPPORTED_ERROR , SE_IO_ERROR , SE_GENERAL_ERROR<br/>} | Open Mobile API规范中定义的错误类型。 | 


## 枚举类型说明


### SecureElementStatus

```
enum SecureElementStatus
```

**描述**

Open Mobile API规范中定义的错误类型。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| SE_SUCCESS | 正常状态 | 
| SE_NULL_POINTER_ERROR | 空指针异常错误 | 
| SE_ILLEGAL_PARAMETER_ERROR | 非法参数错误 | 
| SE_ILLEGAL_STATE_ERROR | 非法状态错误 | 
| SE_SECURITY_ERROR | 安全错误 | 
| SE_CHANNEL_NOT_AVAILABLE_ERROR | 通道不存在错误 | 
| SE_NO_SUCH_ELEMENT_ERROR | 没有更多元素错误 | 
| SE_ILLEGAL_REFERENCE_ERROR | 非法引用错误 | 
| SE_OPERATION_NOT_SUPPORTED_ERROR | 不支持的操作错误 | 
| SE_IO_ERROR | IO异常错误 | 
| SE_GENERAL_ERROR | 其他错误 | 
