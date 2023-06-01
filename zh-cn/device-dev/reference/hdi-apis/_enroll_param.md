# EnrollParam


## 概述

注册认证凭据参数。

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
| [authType](#authtype) | enum&nbsp;[AuthType](_hdf_user_auth.md#authtype)<br/>用户认证凭据类型AuthType}。&nbsp; | 
| [executorType](#executortype) | unsigned&nbsp;int<br/>执行器类型。&nbsp; | 
| [executorSensorHint](#executorsensorhint) | unsigned&nbsp;int<br/>既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器。&nbsp; | 


## 类成员变量说明


### authType

  
```
enum AuthType EnrollParam::authType
```
**描述:**
用户认证凭据类型AuthType}。


### executorSensorHint

  
```
unsigned int EnrollParam::executorSensorHint
```
**描述:**
既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器。


### executorType

  
```
unsigned int EnrollParam::executorType
```
**描述:**
执行器类型。
