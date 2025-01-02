# CredentialInfo


## 概述

认证凭据信息。

**起始版本：** 3.2

**相关模块：**[HdfUserAuth](_hdf_user_auth_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned long [credentialId](#credentialid) | 认证凭据ID。 | 
| unsigned long [executorIndex](#executorindex) | 用户认证框架的执行器索引。 | 
| unsigned long [templateId](#templateid) | 认证凭据模版ID。 | 
| enum [AuthType](_hdf_user_auth_v10.md#authtype)[authType](#authtype) | 用户认证凭据类型[AuthType](_hdf_user_auth_v10.md#authtype)。 | 
| unsigned int [executorMatcher](#executormatcher) | 执行器匹配器。 | 
| unsigned int [executorSensorHint](#executorsensorhint) | 既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器。 | 


## 类成员变量说明


### authType

```
enum AuthType CredentialInfo::authType
```

**描述**


用户认证凭据类型[AuthType](_hdf_user_auth_v10.md#authtype)。


### credentialId

```
unsigned long CredentialInfo::credentialId
```

**描述**


认证凭据ID。


### executorIndex

```
unsigned long CredentialInfo::executorIndex
```

**描述**


用户认证框架的执行器索引。


### executorMatcher

```
unsigned int CredentialInfo::executorMatcher
```

**描述**


执行器匹配器。


### executorSensorHint

```
unsigned int CredentialInfo::executorSensorHint
```

**描述**


既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器。


### templateId

```
unsigned long CredentialInfo::templateId
```

**描述**


认证凭据模版ID。
