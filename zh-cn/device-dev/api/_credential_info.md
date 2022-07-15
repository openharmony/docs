# CredentialInfo


## **概述**

**所属模块:**

[HdfUserAuth](_hdf_user_auth.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| [credentialId](#credentialid) | 认证凭据ID。 | 
| [index](#index) | 用户认证框架的执行器索引。 | 
| [templateId](#templateid) | 认证凭据模版ID。 | 
| [authType](#authtype) | 用户认证凭据类型AuthType}。 | 
| [executorType](#executortype) | 执行器类型。 | 
| [executorId](#executorid) | 既定用户认证凭据类型的执行器ID。 | 
| [extraInfo](#extrainfo) | 其他相关信息，用于支持信息扩展。 | 


## **详细描述**

认证凭据信息。

**自动:**

3.2

**Version：**

1.0


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


### executorId

  
```
unsigned int CredentialInfo::executorId
```

**描述：**

既定用户认证凭据类型的执行器ID。


### executorType

  
```
unsigned int CredentialInfo::executorType
```

**描述：**

执行器类型。


### extraInfo

  
```
unsigned char [] CredentialInfo::extraInfo
```

**描述：**

其他相关信息，用于支持信息扩展。


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
