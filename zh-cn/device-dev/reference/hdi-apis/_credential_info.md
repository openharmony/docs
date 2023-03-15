# CredentialInfo


## **概述**

认证凭据信息。

**自动:**

3.2

**Version：**

1.0

**所属模块:**

[HdfUserAuth](_hdf_user_auth.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [credentialId](#credentialid) | 认证凭据ID。 | 
| [index](#index) | 用户认证框架的执行器索引。 | 
| [templateId](#templateid) | 认证凭据模版ID。 | 
| [authType](#authtype) | 用户认证凭据类型。 | 
| [executorMatcher](#executormatcher) | 执行器匹配器。 | 
| [executorSensorHint](#executorsensorhint) | 既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器。 | 


## **类成员变量说明**


### authType

  
```
enum AuthType CredentialInfo::authType
```

**描述：**

用户认证凭据类型。


### credentialId

  
```
unsigned long CredentialInfo::credentialId
```

**描述：**

认证凭据ID。


### executorSensorHint

  
```
unsigned int CredentialInfo::executorSensorHint
```

**描述：**

既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器。


### executorMatcher

  
```
unsigned int CredentialInfo::executorMatcher
```

**描述：**

执行器匹配器。


### index

  
```
unsigned long CredentialInfo::index
```

**描述：**

用户认证框架的执行器索引。


### templateId

  
```
unsigned long CredentialInfo::templateId
```

**描述：**

认证凭据模版ID。
