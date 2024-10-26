# EnrollResultInfo


## 概述

录入结果信息。

**起始版本：** 4.1

**相关模块：**[HdfUserAuth](_hdf_user_auth_v12.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned long [credentialId](#credentialid) | 认证凭据ID  | 
| struct [CredentialInfo](_credential_info_v12.md)[oldInfo](#oldinfo) | 旧凭据信息[CredentialInfo](_credential_info_v12.md)。  | 
| unsigned char[] [rootSecret](#rootsecret) | 保护文件加密密钥的密钥。  | 


## 类成员变量说明


### credentialId

```
unsigned long EnrollResultInfo::credentialId
```
**描述**

认证凭据ID


### oldInfo

```
struct CredentialInfo EnrollResultInfo::oldInfo
```
**描述**

旧凭据信息[CredentialInfo](_credential_info_v12.md)。


### rootSecret

```
unsigned char [] EnrollResultInfo::rootSecret
```
**描述**

保护文件加密密钥的密钥。
