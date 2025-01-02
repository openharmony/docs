# EnrollParamV1_2


## 概述

注册认证凭据参数。

**起始版本：** 4.1

**相关模块：**[HdfUserAuth](_hdf_user_auth_v12.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum [AuthType](_hdf_user_auth_v12.md#authtype)[authType](#authtype) | 用户认证凭据类型[AuthType](_hdf_user_auth_v12.md#authtype)。  | 
| unsigned int [executorSensorHint](#executorsensorhint) | 既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器，取值不为0。  | 
| String [callerName](#callername) | 调用者名称。  | 
| int [apiVersion](#apiversion) | 调用接口版本。  | 


## 类成员变量说明


### apiVersion

```
int EnrollParamV1_2::apiVersion
```
**描述**

调用接口版本。


### authType

```
enum AuthType EnrollParamV1_2::authType
```
**描述**

用户认证凭据类型[AuthType](_hdf_user_auth_v12.md#authtype)。


### callerName

```
String EnrollParamV1_2::callerName
```
**描述**

调用者名称。


### executorSensorHint

```
unsigned int EnrollParamV1_2::executorSensorHint
```
**描述**

既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器，取值不为0。
