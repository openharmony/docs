# CredentialInfo


## 概述

认证凭据信息。

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
| [credentialId](#credentialid) | unsigned&nbsp;long<br/>认证凭据ID。&nbsp; | 
| [index](#index) | unsigned&nbsp;long<br/>用户认证框架的执行器索引。&nbsp; | 
| [templateId](#templateid) | unsigned&nbsp;long<br/>认证凭据模版ID。&nbsp; | 
| [authType](#authtype) | enum&nbsp;[AuthType](_hdf_user_auth.md#authtype)<br/>用户认证凭据类型AuthType}。&nbsp; | 
| [executorMatcher](#executormatcher) | unsigned&nbsp;int<br/>执行器匹配器。&nbsp; | 
| [executorSensorHint](#executorsensorhint) | unsigned&nbsp;int<br/>既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器。&nbsp; | 


## 类成员变量说明


### authType

  
```
enum AuthType CredentialInfo::authType
```
**描述:**
用户认证凭据类型AuthType}。


### credentialId

  
```
unsigned long CredentialInfo::credentialId
```
**描述:**
认证凭据ID。


### executorMatcher

  
```
unsigned int CredentialInfo::executorMatcher
```
**描述:**
执行器匹配器。


### executorSensorHint

  
```
unsigned int CredentialInfo::executorSensorHint
```
**描述:**
既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器。


### index

  
```
unsigned long CredentialInfo::index
```
**描述:**
用户认证框架的执行器索引。


### templateId

  
```
unsigned long CredentialInfo::templateId
```
**描述:**
认证凭据模版ID。
