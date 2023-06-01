# EnrollResultInfo


## 概述

录入结果信息。

**Since:**
3.2
**Version:**
1.0
**相关模块:**

[HdfUserAuth](_hdf_user_auth.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [credentialId](#credentialid) | unsigned&nbsp;long<br/>认证凭据ID&nbsp; | 
| [oldInfo](#oldinfo) | struct&nbsp;[CredentialInfo](_credential_info.md)<br/>旧凭据信息[CredentialInfo](_credential_info.md)。&nbsp; | 
| [rootSecret](#rootsecret) | unsigned&nbsp;char[]<br/>保护文件加密密钥的密钥。&nbsp; | 


## 类成员变量说明


### credentialId

  
```
unsigned long EnrollResultInfo::credentialId
```
**描述:**
认证凭据ID


### oldInfo

  
```
struct CredentialInfo EnrollResultInfo::oldInfo
```
**描述:**
旧凭据信息[CredentialInfo](_credential_info.md)。


### rootSecret

  
```
unsigned char [] EnrollResultInfo::rootSecret
```
**描述:**
保护文件加密密钥的密钥。
