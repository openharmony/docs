# UserInfo


## 概述

用户信息

**起始版本：** 4.0

**相关模块：**[HdfUserAuth](_hdf_user_auth_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned long [secureUid](#secureuid) | 用户的SecureUid。 | 
| enum PinSubType [pinSubType](#pinsubtype) | 用户的口令认证子类型[PinSubType](_hdf_user_auth_v10.md#pinsubtype)。 | 
| struct EnrolledInfo[] [enrolledInfos](#enrolledinfos) | 用户的注册信息列表[EnrolledInfo](_enrolled_info_v10.md)。 | 


## 类成员变量说明


### enrolledInfos

```
struct EnrolledInfo [] UserInfo::enrolledInfos
```

**描述**


用户的注册信息列表[EnrolledInfo](_enrolled_info_v10.md)。


### pinSubType

```
enum PinSubType UserInfo::pinSubType
```

**描述**


用户的口令认证子类型[PinSubType](_hdf_user_auth_v10.md#pinsubtype)。


### secureUid

```
unsigned long UserInfo::secureUid
```

**描述**


用户的SecureUid。
