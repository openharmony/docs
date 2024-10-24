# AuthSolution


## 概述

认证方案。

**起始版本：** 3.2

**相关模块：**[HdfUserAuth](_hdf_user_auth_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [userId](#userid) | 用户ID。 | 
| unsigned int [authTrustLevel](#authtrustlevel) | 认证结果可信等级。 | 
| enum [AuthType](_hdf_user_auth_v10.md#authtype)[authType](#authtype) | 用户认证凭据类型[AuthType](_hdf_user_auth_v10.md#authtype)。 | 
| unsigned int [executorSensorHint](#executorsensorhint) | 既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器。 | 
| unsigned char[] [challenge](#challenge) | 挑战值，用于签发认证令牌。 | 


## 类成员变量说明


### authTrustLevel

```
unsigned int AuthSolution::authTrustLevel
```

**描述**


认证结果可信等级。


### authType

```
enum AuthType AuthSolution::authType
```

**描述**


用户认证凭据类型[AuthType](_hdf_user_auth_v10.md#authtype)。


### challenge

```
unsigned char [] AuthSolution::challenge
```

**描述**


挑战值，用于签发认证令牌。


### executorSensorHint

```
unsigned int AuthSolution::executorSensorHint
```

**描述**


既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器。


### userId

```
int AuthSolution::userId
```

**描述**


用户ID。
