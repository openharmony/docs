# EnrollResultInfo


## **概述**

注册认证凭据参数。

**Since：**

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
| [oldInfo](#oldinfo) | 旧凭据信息。 | 
| [rootSecret](#rootsecret) | 保护文件加密密钥的密钥。 | 


## **类成员变量说明**


### credentialId

  
```
unsigned long EnrollResultInfo::credentialId
```

**描述：**

认证凭据ID。


### oldInfo

  
```
struct CredentialInfo EnrollParam::oldInfo
```

**描述：**

旧凭据信息[CredentialInfo](_credential_info.md)。


### rootSecret

  
```
unsigned char[] EnrollParam::rootSecret
```

**描述：**

保护文件加密密钥的密钥。
