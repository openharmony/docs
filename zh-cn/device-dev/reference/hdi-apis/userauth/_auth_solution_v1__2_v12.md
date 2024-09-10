# AuthSolutionV1_2


## 概述

认证方案。

**起始版本：** 4.1

**相关模块：**[HdfUserAuth](_hdf_user_auth_v12.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [userId](#userid) | 用户ID。  | 
| unsigned int [authTrustLevel](#authtrustlevel) | 认证结果可信等级。  | 
| enum [AuthType](_hdf_user_auth_v12.md#authtype)[authType](#authtype) | 用户认证凭据类型[AuthType](_hdf_user_auth_v12.md#authtype)。  | 
| unsigned int [executorSensorHint](#executorsensorhint) | 既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器。  | 
| unsigned char[] [challenge](#challenge) | 挑战值，用于签发认证令牌。  | 
| String [callerName](#callername) | 调用者名称。  | 
| int [apiVersion](#apiversion) | 调用接口版本。  | 


## 类成员变量说明


### apiVersion

```
int AuthSolutionV1_2::apiVersion
```
**描述**

调用接口版本。


### authTrustLevel

```
unsigned int AuthSolutionV1_2::authTrustLevel
```
**描述**

认证结果可信等级。


### authType

```
enum AuthType AuthSolutionV1_2::authType
```
**描述**

用户认证凭据类型[AuthType](_hdf_user_auth_v12.md#authtype)。


### callerName

```
String AuthSolutionV1_2::callerName
```
**描述**

调用者名称。


### challenge

```
unsigned char [] AuthSolutionV1_2::challenge
```
**描述**

挑战值，用于签发认证令牌。


### executorSensorHint

```
unsigned int AuthSolutionV1_2::executorSensorHint
```
**描述**

既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器。


### userId

```
int AuthSolutionV1_2::userId
```
**描述**

用户ID。
