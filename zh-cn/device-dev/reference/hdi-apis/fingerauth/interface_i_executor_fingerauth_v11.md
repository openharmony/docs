# IExecutor


## 概述

定义执行器接口，用于获取执行器，获取凭据模版信息，注册指纹特征模版，进行用户指纹认证，删除指纹特征模版等。

**起始版本：** 4.0

**相关模块：**[HdfFingerprintAuth](_hdf_fingerprint_auth_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [AuthenticateV1_1](#authenticatev1_1) ([in] unsigned long scheduleId, [in] unsigned long[] templateIdList, [in] boolean endAfterFirstFail, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj) | 指纹识别。 | 
| [GetProperty](#getproperty) ([in] unsigned long[] templateIdList, [in] enum [GetPropertyType](_hdf_fingerprint_auth_v11.md#getpropertytype)[] propertyTypes, [out] struct [Property](_property_fingerauth_v11.md) property) | 获取指纹执行器属性。 | 
| [SetCachedTemplates](#setcachedtemplates) ([in] unsigned long[] templateIdList) | 设置指纹缓存模板。 | 
| [RegisterSaCommandCallback](#registersacommandcallback) ([in] [ISaCommandCallback](interface_i_sa_command_callback_fingerauth_v11.md) callbackObj) | 注册sa命令回调。 | 


## 成员函数说明


### AuthenticateV1_1()

```
IExecutor::AuthenticateV1_1 ([in] unsigned long scheduleId, [in] unsigned long[] templateIdList, [in] boolean endAfterFirstFail, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj )
```

**描述**


指纹识别。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| scheduleId | 调度ID，用于标识一次操作请求的调度过程。 | 
| templateIdList | 指定要认证的模版ID列表。 | 
| endAfterFirstFail | 第一次认证失败后结束认证。 | 
| extraInfo | 其他相关信息，用于支持信息扩展。 | 
| callbackObj | 回调对象[IExecutorCallback](interface_i_executor_callback_fingerauth_v10.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### GetProperty()

```
IExecutor::GetProperty ([in] unsigned long[] templateIdList, [in] enum GetPropertyType[] propertyTypes, [out] struct Property property )
```

**描述**


获取指纹执行器属性。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| templateIdList | 指定要认证的模版ID列表。 | 
| propertyTypes | 指纹执行器属性类型，见[GetPropertyType](_hdf_fingerprint_auth_v11.md#getpropertytype)。 | 
| property | 指纹执行器属性[Property](_property_fingerauth_v11.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### RegisterSaCommandCallback()

```
IExecutor::RegisterSaCommandCallback ([in] ISaCommandCallback callbackObj)
```

**描述**


注册sa命令回调。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbackObj | sa命令回调对象。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### SetCachedTemplates()

```
IExecutor::SetCachedTemplates ([in] unsigned long[] templateIdList)
```

**描述**


设置指纹缓存模板。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| templateIdList | 指纹缓存模板列表。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。
