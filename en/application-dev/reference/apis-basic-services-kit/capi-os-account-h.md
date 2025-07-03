# os_account.h

## Overview

Defines the APIs for accessing and managing system account information.

**Library**: libos_account_ndk.so

**Header file**: <BasicServicesKit/os_account.h>

**System capability**: SystemCapability.Account.OsAccount

**Since**: 12

**Related module**: [OsAccount](capi-osaccount.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [OsAccount_ErrCode OH_OsAccount_GetName(char *buffer, size_t buffer_size)](#oh_osaccount_getname) | Obtains the name of the system account to which the caller process belongs.|

## Function Description

### OH_OsAccount_GetName()

```
OsAccount_ErrCode OH_OsAccount_GetName(char *buffer, size_t buffer_size)
```

**Description**

Obtains the name of the system account to which the caller process belongs.

**System capability**: SystemCapability.Account.OsAccount

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| char *buffer | Pointer to the system account name, which including the name of the maximum length (**LOGIN_NAME_MAX**) and the end character (**\0**).|
| size_t buffer_size | Length of the system account name.|

**Returns**

| Type| Description|
| -- | -- |
| [OsAccount_ErrCode](capi-os-account-common-h.md#osaccount_errcode) | **OS_ACCOUNT_ERR_OK**: Operation successful.<br>**OS_ACCOUNT_ERR_INTERNAL_ERROR**: Internal error.<br>**OS_ACCOUNT_ERR_INVALID_PARAMETER**: Invalid parameter, indicating that the buffer is a null pointer, or the length of the system account name (excluding **\0**) is greater than or equal to the buffer size.|
