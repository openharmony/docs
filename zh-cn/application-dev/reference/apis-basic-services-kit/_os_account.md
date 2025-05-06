# OsAccount


## 概述

OsAccount模块为应用提供系统账号管理能力。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [os_account.h](os__account_8h.md) | 声明访问和管理系统账号信息的API。 | 
| [os_account_common.h](os__account__common_8h.md) | 提供OsAccount接口的公共类型定义。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [OsAccount_ErrCode](#osaccount_errcode-1) [OsAccount_ErrCode](#osaccount_errcode) | 枚举错误码。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OsAccount_ErrCode](#osaccount_errcode-1) {<br/>OS_ACCOUNT_ERR_OK = 0,<br/>OS_ACCOUNT_ERR_INTERNAL_ERROR = 12300001,<br/>OS_ACCOUNT_ERR_INVALID_PARAMETER = 12300002<br/>} | 枚举错误码。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OsAccount_ErrCode](#osaccount_errcode) [OH_OsAccount_GetName](#oh_osaccount_getname) (char \*buffer, size_t buffer_size) | 获取调用方进程所属的系统账号的名称。 | 


## 类型定义说明


### OsAccount_ErrCode

```
typedef enum OsAccount_ErrCode OsAccount_ErrCode
```

**描述**

枚举错误码。

**起始版本：** 12


## 枚举类型说明


### OsAccount_ErrCode

```
enum OsAccount_ErrCode
```

**描述**

枚举错误码。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| OS_ACCOUNT_ERR_OK | 成功。 | 
| OS_ACCOUNT_ERR_INTERNAL_ERROR | 内部错误。 | 
| OS_ACCOUNT_ERR_INVALID_PARAMETER | 无效的参数。 | 


## 函数说明


### OH_OsAccount_GetName()

```
OsAccount_ErrCode OH_OsAccount_GetName (char *buffer, size_t buffer_size)
```

**描述**

获取调用方进程所属的系统账号的名称。

**系统能力：** SystemCapability.Account.OsAccount

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 名称字符数组，其应具有能够存放名称（最大长度为LOGIN_NAME_MAX）和结束字符（'\0'）的空间。 | 
| buffer_size | 名称字符数组的大小。 | 

**返回：**

返回OS_ACCOUNT_ERR_OK表示成功；返回OS_ACCOUNT_ERR_INTERNAL_ERROR表示内部错误；返回OS_ACCOUNT_ERR_INVALID_PARAMETER表示buffer为NULL指针，或名称（不包括结束字符'\0'）的长度大于等于buffer_size。
