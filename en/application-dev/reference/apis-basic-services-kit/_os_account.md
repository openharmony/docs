# OsAccount


## Overview

Provides APIs for managing system accounts.

**Since**: 12


## Summary


### Files

| Name | Description |
| -------- | -------- |
| [os_account.h](os__account_8h.md) | Defines the APIs for accessing and managing system account information. |
| [os_account_common.h](os__account__common_8h.md) | Defines common types used in **OsAccount** APIs. |


### Types

| Name | Description |
| -------- | -------- |
| typedef enum [OsAccount_ErrCode](#osaccount_errcode-1) [OsAccount_ErrCode](#osaccount_errcode) | Defines an enum for error codes. |


### Enums

| Name | Description |
| -------- | -------- |
| [OsAccount_ErrCode](#osaccount_errcode-1) {<br>OS_ACCOUNT_ERR_OK = 0,<br>OS_ACCOUNT_ERR_INTERNAL_ERROR = 12300001,<br>OS_ACCOUNT_ERR_INVALID_PARAMETER = 12300002<br>} | Enumerates the error codes. |


### Functions

| Name | Description |
| -------- | -------- |
| [OsAccount_ErrCode](#osaccount_errcode) [OH_OsAccount_GetName](#oh_osaccount_getname) (char \*buffer, size_t buffer_size) | Obtains the name of the system account, to which the caller process belongs. |


## Type Description


### OsAccount_ErrCode

```
typedef enum OsAccount_ErrCode OsAccount_ErrCode
```

**Description**

Defines an enum for error codes.

**Since**: 12


## Enum Description


### OsAccount_ErrCode

```
enum OsAccount_ErrCode
```

**Description**

Enumerates the error codes.

**Since**: 12

| Value | Description |
| -------- | -------- |
| OS_ACCOUNT_ERR_OK | Operation successful. |
| OS_ACCOUNT_ERR_INTERNAL_ERROR | Internal error. |
| OS_ACCOUNT_ERR_INVALID_PARAMETER | Invalid parameter. |


## Function Description


### OH_OsAccount_GetName()

```
OsAccount_ErrCode OH_OsAccount_GetName (char *buffer, size_t buffer_size)
```

**Description**

Obtains the name of the system account, to which the caller process belongs.

**System capability**: SystemCapability.Account.OsAccount

**Since**: 12

**Parameters**

| Name | Description |
| -------- | -------- |
| buffer | Pointer to the system account name, which including the name of the maximum length (**LOGIN_NAME_MAX**) and the end character ('\0'). |
| buffer_size | Length of the system account name. |

**Returns**

Returns **OS_ACCOUNT_ERR_OK** if the operation is successful.<br>Returns **OS_ACCOUNT_ERR_INTERNAL_ERROR** if an internal error occurred.<br>Returns **OS_ACCOUNT_ERR_INVALID_PARAMETER** if **buffer** is a null pointer or the name length (excluding the end character ('\0')) is greater than or equal to **buffer_size**.

