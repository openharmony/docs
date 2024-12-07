# IExecutor


## 概述

定义执行器标准API接口。接口可用于获取执行器信息，获取凭据模版信息，注册口令，认证口令，删除口令等。

**起始版本：** 4.0

**相关模块：**[HdfPinAuth](_hdf_pin_auth_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetProperty](#getproperty) ([in] unsigned long[] templateIdList, [in] enum [GetPropertyType](_hdf_pin_auth_v11.md#getpropertytype)[] propertyTypes, [out] struct [Property](_property_pinauth_v11.md) property) | 获取属性。  | 
| [EnrollV1_1](#enrollv1_1) ([in] unsigned long scheduleId, [in] unsigned char[] extraInfo, [in] [IExecutorCallback](interface_i_executor_callback_pinauth_v11.md) callbackObj) | 注册口令。  | 
| [AuthenticateV1_1](#authenticatev1_1) ([in] unsigned long scheduleId, [in] unsigned long templateId, [in] unsigned char[] extraInfo, [in] [IExecutorCallback](interface_i_executor_callback_pinauth_v11.md) callbackObj) | 认证口令。  | 


## 成员函数说明


### AuthenticateV1_1()

```
IExecutor::AuthenticateV1_1 ([in] unsigned long scheduleId, [in] unsigned long templateId, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj )
```
**描述**

认证口令。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| scheduleId | 调度ID，用于标识一次操作请求的调度过程。  | 
| templateId | 指定要认证的模版ID。  | 
| extraInfo | 其他相关信息，用于支持信息扩展。  | 
| callbackObj | 回调对象[IExecutorCallback](interface_i_executor_callback_pinauth_v11.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### EnrollV1_1()

```
IExecutor::EnrollV1_1 ([in] unsigned long scheduleId, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj )
```
**描述**

注册口令。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| scheduleId | 调度ID，用于标识一次操作请求的调度过程。  | 
| extraInfo | 其他相关信息，用于支持信息扩展。  | 
| callbackObj | 回调对象[IExecutorCallback](interface_i_executor_callback_pinauth_v11.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### GetProperty()

```
IExecutor::GetProperty ([in] unsigned long[] templateIdList, [in] enum GetPropertyType[] propertyTypes, [out] struct Property property )
```
**描述**

获取属性。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| templateIdList | 标识需要处理的模板。  | 
| propertyTypes | 标识需要获取的属性类型[GetPropertyType](_hdf_pin_auth_v11.md#getpropertytype)。  | 
| property | 标识获取的属性[Property](_property_pinauth_v11.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。
