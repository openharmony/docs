# AbilityAccessControl


## 概述

提供管理进程访问控制的系统能力。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [ability_access_control.h](ability__access__control_8h.md) | 声明管理进程访问控制的接口。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| bool [OH_AT_CheckSelfPermission](#oh_at_checkselfpermission)(const char \*permission) | 校验应用是否被授予指定的权限。  | 


## 函数说明


### OH_AT_CheckSelfPermission()

```
bool OH_AT_CheckSelfPermission(const char* permission)
```
**描述**
校验应用是否被授予指定的权限。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| permission | 需要校验的权限名称，合法的权限名取值可在应用权限列表中查询。  | 

**返回：**

true - 应用已经被授予该权限。 

false - 应用未被授予该权限。
