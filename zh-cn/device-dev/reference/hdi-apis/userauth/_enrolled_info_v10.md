# EnrolledInfo


## 概述

注册信息。

**起始版本：** 3.2

**相关模块：**[HdfUserAuth](_hdf_user_auth_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned long [enrolledId](#enrolledid) | 注册ID，用户注册新的认证凭据时会更新注册ID。 | 
| enum [AuthType](_hdf_user_auth_v10.md#authtype)[authType](#authtype) | 用户认证凭据类型[AuthType](_hdf_user_auth_v10.md#authtype)。 | 


## 类成员变量说明


### authType

```
enum AuthType EnrolledInfo::authType
```

**描述**


用户认证凭据类型[AuthType](_hdf_user_auth_v10.md#authtype)。


### enrolledId

```
unsigned long EnrolledInfo::enrolledId
```

**描述**


注册ID，用户注册新的认证凭据时会更新注册ID。
