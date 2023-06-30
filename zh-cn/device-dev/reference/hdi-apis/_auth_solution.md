# AuthSolution


## 概述

认证方案。

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
| [userId](#userid) | int<br/>用户ID。&nbsp; | 
| [authTrustLevel](#authtrustlevel) | unsigned&nbsp;int<br/>认证结果可信等级。&nbsp; | 
| [authType](#authtype) | enum&nbsp;[AuthType](_hdf_user_auth.md#authtype)<br/>用户认证凭据类型AuthType}。&nbsp; | 
| [executorSensorHint](#executorsensorhint) | unsigned&nbsp;int<br/>既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器。&nbsp; | 
| [challenge](#challenge) | unsigned&nbsp;char[]<br/>挑战值，用于签发认证令牌。&nbsp; | 


## 类成员变量说明


### authTrustLevel

  
```
unsigned int AuthSolution::authTrustLevel
```
**描述:**
认证结果可信等级。


### authType

  
```
enum AuthType AuthSolution::authType
```
**描述:**
用户认证凭据类型AuthType}。


### challenge

  
```
unsigned char [] AuthSolution::challenge
```
**描述:**
挑战值，用于签发认证令牌。


### executorSensorHint

  
```
unsigned int AuthSolution::executorSensorHint
```
**描述:**
既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器。


### userId

  
```
int AuthSolution::userId
```
**描述:**
用户ID。
