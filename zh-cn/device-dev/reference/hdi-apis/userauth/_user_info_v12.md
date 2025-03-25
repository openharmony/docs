# UserInfo


## 概述

用户信息

**起始版本：** 4.1

**相关模块：**[HdfUserAuth](_hdf_user_auth_v12.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned long [secureUid](#secureuid) | 用户的SecureUid。  | 
| enum [PinSubType](_hdf_user_auth_v12.md#pinsubtype)[pinSubType](#pinsubtype) | 用户的口令认证子类型[PinSubType](_hdf_user_auth_v12.md#pinsubtype)。  | 
| struct [EnrolledInfo](_enrolled_info_v12.md)[] [enrolledInfos](#enrolledinfos) | 用户的注册信息列表[EnrolledInfo](_enrolled_info_v12.md)。 | 


## 类成员变量说明


### enrolledInfos

```
struct EnrolledInfo [] UserInfo::enrolledInfos
```
**描述**

用户的注册信息列表[EnrolledInfo](_enrolled_info_v12.md)。


### pinSubType

```
enum PinSubType UserInfo::pinSubType
```
**描述**

用户的口令认证子类型[PinSubType](_hdf_user_auth_v12.md#pinsubtype)。


### secureUid

```
unsigned long UserInfo::secureUid
```
**描述**

用户的SecureUid。
