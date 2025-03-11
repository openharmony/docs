# EnrollParam


## 概述

注册认证凭据参数。

**弃用:**

从4.1版本开始废弃，使用[EnrollParamV1_2](_enroll_param_v1__2_v12.md)接口代替。

**起始版本：** 4.1

**相关模块：**[HdfUserAuth](_hdf_user_auth_v12.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum [AuthType](_hdf_user_auth_v12.md#authtype)[authType](#authtype) | 用户认证凭据类型[AuthType](_hdf_user_auth_v12.md#authtype)。  | 
| unsigned int [executorSensorHint](#executorsensorhint) | 既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器，取值不为0。  | 


## 类成员变量说明


### authType

```
enum AuthType EnrollParam::authType
```
**描述**

用户认证凭据类型[AuthType](_hdf_user_auth_v12.md#authtype)。


### executorSensorHint

```
unsigned int EnrollParam::executorSensorHint
```
**描述**

既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器，取值不为0。
