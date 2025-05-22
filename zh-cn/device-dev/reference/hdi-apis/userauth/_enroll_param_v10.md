# EnrollParam


## 概述

注册认证凭据参数。

**起始版本：** 3.2

**相关模块：**[HdfUserAuth](_hdf_user_auth_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum [AuthType](_hdf_user_auth_v10.md#authtype)[authType](#authtype) | 用户认证凭据类型[AuthType](_hdf_user_auth_v10.md#authtype)。 | 
| unsigned int [executorSensorHint](#executorsensorhint) | 既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器。 | 


## 类成员变量说明


### authType

```
enum AuthType EnrollParam::authType
```

**描述**


用户认证凭据类型[AuthType](_hdf_user_auth_v10.md#authtype)。


### executorSensorHint

```
unsigned int EnrollParam::executorSensorHint
```

**描述**


既定用户认证凭据类型的执行器传感器提示，用于找到对应认证方式的传感器。
