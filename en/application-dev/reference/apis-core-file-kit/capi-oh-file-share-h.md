# oh_file_share.h
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @lvzhenjie; @hongjin-li_admin-->
<!--SE: @chenxi0605; @JerryH1011-->
<!--TSE: @leiyuqian-->

## Overview

Provides APIs for persisting permissions, activating or deactivating persistent permissions, and checking the persistent permissions on files or directories based on their URIs.

**Library**: libohfileshare.so

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

**Since**: 12

**Related module**: [fileShare](capi-fileshare.md)

## Summary

### Structs

| Name                                                                          | typedef Keyword| Description|
|------------------------------------------------------------------------------| -- | -- |
| [FileShare_PolicyErrorResult](capi-fileshare-fileshare-policyerrorresult.md) | FileShare_PolicyErrorResult | Represents the permission policy error result.|
| [FileShare_PolicyInfo](capi-fileshare-fileshare-policyinfo.md)               | FileShare_PolicyInfo | Represents the permission policy information.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [FileShare_OperationMode](#fileshare_operationmode) | FileShare_OperationMode | Enumerates the URI operation mode.|
| [FileShare_PolicyErrorCode](#fileshare_policyerrorcode) | FileShare_PolicyErrorCode | Enumerates the permission policy error code.|

### Functions

| Name| Description|
| -- | -- |
| [FileManagement_ErrCode OH_FileShare_PersistPermission(const FileShare_PolicyInfo *policies, unsigned int policyNum,FileShare_PolicyErrorResult **result, unsigned int *resultNum)](#oh_fileshare_persistpermission) | Persists the permissions on files or directories.|
| [FileManagement_ErrCode OH_FileShare_RevokePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum,FileShare_PolicyErrorResult **result, unsigned int *resultNum)](#oh_fileshare_revokepermission) | Revokes the permissions from files or directories.|
| [FileManagement_ErrCode OH_FileShare_ActivatePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum,FileShare_PolicyErrorResult **result, unsigned int *resultNum)](#oh_fileshare_activatepermission) | Activates the persistent permissions on files or directories.|
| [FileManagement_ErrCode OH_FileShare_DeactivatePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum,FileShare_PolicyErrorResult **result, unsigned int *resultNum)](#oh_fileshare_deactivatepermission) | Deactivates the persistent permissions on files or directories.|
| [FileManagement_ErrCode OH_FileShare_CheckPersistentPermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, bool **result, unsigned int *resultNum)](#oh_fileshare_checkpersistentpermission) | Checks the persistent permissions on files or directories.|
| [void OH_FileShare_ReleasePolicyErrorResult(FileShare_PolicyErrorResult *errorResult, unsigned int resultNum)](#oh_fileshare_releasepolicyerrorresult) | Releases the memory, to which **FileShare_PolicyErrorResult** points.|

## Enum Description

### FileShare_OperationMode

```
enum FileShare_OperationMode
```

**Description**

Enumerates the URI operation mode.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| READ_MODE = 1 << 0 | Read.|
| WRITE_MODE = 1 << 1 | Write.|

### FileShare_PolicyErrorCode

```
enum FileShare_PolicyErrorCode
```

**Description**

Enumerates the permission policy error code.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| PERSISTENCE_FORBIDDEN = 1 | The permission on the URI cannot be persisted.|
| INVALID_MODE = 2 | Invalid mode.|
| INVALID_PATH = 3 | Invalid path.|
| PERMISSION_NOT_PERSISTED = 4 | The permission is not persisted.|


## Function Description

### OH_FileShare_PersistPermission()

```
FileManagement_ErrCode OH_FileShare_PersistPermission(const FileShare_PolicyInfo *policies, unsigned int policyNum,FileShare_PolicyErrorResult **result, unsigned int *resultNum)
```

**Description**

Persists the permissions on files or directories.

**Required permissions**: ohos.permission.FILE_ACCESS_PERSIST

**Since**: 12


**Parameters**

| Name                                                                                  | Description|
|---------------------------------------------------------------------------------------| -- |
| [const FileShare_PolicyInfo](capi-fileshare-fileshare-policyinfo.md) *policies        | Pointer to a **FileShare_PolicyInfo** instance.|
| unsigned int policyNum                                                                | Number of policies in the **FileShare_PolicyInfo** array.|
| [FileShare_PolicyErrorResult](capi-fileshare-fileshare-policyerrorresult.md) **result | Double pointer to the **FileShare_PolicyErrorResult** array. Use **OH_FileShare_ReleasePolicyErrorResult()** to release the memory allocated.|
| unsigned int *resultNum                                                               | Pointer to the size of the **FileShare_PolicyErrorResult** array.|

**Returns**

| Type| Description|
| -- | -- |
| [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode) | Returns [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode).<br>         E_PARAMS 401 - The input parameter is invalid. Possible causes:<br>             1. The **policies**, **result**, or **resultNum** parameter is a null pointer.<br>             2. The value of **policyNum** is **0** or exceeds the maximum length (500).<br>             3. The value of **uri** in the **policies** parameter is empty, the value of **length** is **0**, or the value of **uri** is different from the value of **length**.<br>         E_DEVICE_NOT_SUPPORT 801 - The device does not support this API.<br>         E_PERMISSION 201 - The permission verification fails.<br>         E_ENOMEM 13900011 - The memory allocation or copy fails.<br>         E_EPERM 13900001 - The operation is not allowed.<br>         E_UNKNOWN_ERROR 13900042 - An unknown internal error occurs. The error is none of the preceding errors.<br>         E_NO_ERROR 0 - The API is successfully called.|

### OH_FileShare_RevokePermission()

```
FileManagement_ErrCode OH_FileShare_RevokePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum,FileShare_PolicyErrorResult **result, unsigned int *resultNum)
```

**Description**

Revokes the permissions from files or directories.

**Required permissions**: ohos.permission.FILE_ACCESS_PERSIST

**Since**: 12


**Parameters**

| Name                                                                                  | Description|
|---------------------------------------------------------------------------------------| -- |
| [const FileShare_PolicyInfo](capi-fileshare-fileshare-policyinfo.md) *policies        | Pointer to a **FileShare_PolicyInfo** instance.|
| unsigned int policyNum                                                                | Number of policies in the **FileShare_PolicyInfo** array.|
| [FileShare_PolicyErrorResult](capi-fileshare-fileshare-policyerrorresult.md) **result | Double pointer to the **FileShare_PolicyErrorResult** array. Use **OH_FileShare_ReleasePolicyErrorResult()** to release the memory allocated.|
| unsigned int *resultNum                                                               | Pointer to the size of the **FileShare_PolicyErrorResult** array.|

**Returns**

| Type| Description|
| -- | -- |
| [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode) | Returns [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode).<br>         E_PARAMS 401 - The input parameter is invalid. Possible causes:<br>1. The **policies**, **result**, or **resultNum** parameter is a null pointer.<br>             2. The value of **policyNum** is **0** or exceeds the maximum length (500).<br>3. The value of **uri** in the **policies** parameter is empty, the value of **length** is **0**, or the value of **uri** is different from the value of **length**.<br>         E_DEVICE_NOT_SUPPORT 801 - The device does not support this API.<br>         E_PERMISSION 201 - The permission verification fails.<br>         E_ENOMEM 13900011 - The memory allocation or copy fails.<br>         E_EPERM 13900001 - The operation is not allowed.<br>         E_UNKNOWN_ERROR 13900042 - An unknown internal error occurs. The error is none of the preceding errors.<br>         E_NO_ERROR - The API is called successfully.|

### OH_FileShare_ActivatePermission()

```
FileManagement_ErrCode OH_FileShare_ActivatePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum,FileShare_PolicyErrorResult **result, unsigned int *resultNum)
```

**Description**

Activates the persistent permissions on files or directories.

**Required permissions**: ohos.permission.FILE_ACCESS_PERSIST

**Since**: 12


**Parameters**

| Name                                                                                  | Description|
|---------------------------------------------------------------------------------------| -- |
| [const FileShare_PolicyInfo](capi-fileshare-fileshare-policyinfo.md) *policies        | Pointer to a **FileShare_PolicyInfo** instance.|
| unsigned int policyNum                                                                | Number of policies in the **FileShare_PolicyInfo** array.|
| [FileShare_PolicyErrorResult](capi-fileshare-fileshare-policyerrorresult.md) **result | Double pointer to the **FileShare_PolicyErrorResult** array. Use **OH_FileShare_ReleasePolicyErrorResult()** to release the memory allocated.|
| unsigned int *resultNum                                                               | Pointer to the size of the **FileShare_PolicyErrorResult** array.|

**Returns**

| Type| Description|
| -- | -- |
| [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode) | Returns [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode).<br>         E_PARAMS 401 - The input parameter is invalid. Possible causes:<br>             1. The **policies**, **result**, or **resultNum** parameter is a null pointer.<br>             2. The value of **policyNum** is **0** or exceeds the maximum length (500).<br>             3. The value of **uri** in the **policies** parameter is empty, the value of **length** is **0**, or the value of **uri** is different from the value of **length**.<br>         E_DEVICE_NOT_SUPPORT 801 - The device does not support this API.<br>         E_PERMISSION 201 - The permission verification fails.<br>         E_ENOMEM 13900011 - The memory allocation or copy fails.<br>         E_EPERM 13900001 - The operation is not allowed.<br>         E_UNKNOWN_ERROR 13900042 - An unknown internal error occurs. The error is none of the preceding errors.<br>         E_NO_ERROR 0 - The API is successfully called.|

### OH_FileShare_DeactivatePermission()

```
FileManagement_ErrCode OH_FileShare_DeactivatePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum,FileShare_PolicyErrorResult **result, unsigned int *resultNum)
```

**Description**

Deactivates the persistent permissions on files or directories.

**Required permissions**: ohos.permission.FILE_ACCESS_PERSIST

**Since**: 12


**Parameters**

| Name                                                                                  | Description|
|---------------------------------------------------------------------------------------| -- |
| [const FileShare_PolicyInfo](capi-fileshare-fileshare-policyinfo.md) *policies        | Pointer to a **FileShare_PolicyInfo** instance.|
| unsigned int policyNum                                                                | Number of policies in the **FileShare_PolicyInfo** array.|
| [FileShare_PolicyErrorResult](capi-fileshare-fileshare-policyerrorresult.md) **result | Double pointer to the **FileShare_PolicyErrorResult** array. Use **OH_FileShare_ReleasePolicyErrorResult()** to release the memory allocated.|
| unsigned int *resultNum                                                               | Pointer to the size of the **FileShare_PolicyErrorResult** array.|

**Returns**

| Type| Description|
| -- | -- |
| [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode) | Returns [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode).<br>         E_PARAMS 401 - The input parameter is invalid. Possible causes:<br>             1. The **policies**, **result**, or **resultNum** parameter is a null pointer.<br>             2. The value of **policyNum** is **0** or exceeds the maximum length (500).<br>             3. The value of **uri** in the **policies** parameter is empty, the value of **length** is **0**, or the value of **uri** is different from the value of **length**.<br>         E_DEVICE_NOT_SUPPORT 801 - The device does not support this API.<br>         E_PERMISSION 201 - The permission verification fails.<br>          E_ENOMEM 13900011 - The memory allocation or copy fails.<br>         E_EPERM 13900001 - The operation is not allowed.<br>         E_UNKNOWN_ERROR 13900042 - An unknown internal error occurs. The error is none of the preceding errors.<br>         E_NO_ERROR - The API is called successfully.|

### OH_FileShare_CheckPersistentPermission()

```
FileManagement_ErrCode OH_FileShare_CheckPersistentPermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, bool **result, unsigned int *resultNum)
```

**Description**

Checks the persistent permissions on files or directories.

**Required permissions**: ohos.permission.FILE_ACCESS_PERSIST

**Since**: 12


**Parameters**

| Name                                                                           | Description|
|--------------------------------------------------------------------------------| -- |
| [const FileShare_PolicyInfo](capi-fileshare-fileshare-policyinfo.md) *policies | Pointer to a **FileShare_PolicyInfo** instance.|
| unsigned int policyNum                                                         | Number of policies in the **FileShare_PolicyInfo** array.|
| bool **result                                                                  | Double pointer to the check result obtained. You also need to include **malloc.h** and use **free()** to release the memory allocated.|
| unsigned int *resultNum                                                        | Pointer to the size of the check result array.|

**Returns**

| Type| Description|
| -- | -- |
| [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode) | Returns [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode).<br>         E_PARAMS 401 - The input parameter is invalid. Possible causes:<br>             1. The **policies**, **result**, or **resultNum** parameter is a null pointer.<br>             2. The value of **policyNum** is **0** or exceeds the maximum length (500).<br>             3. The value of **uri** in the **policies** parameter is empty, the value of **length** is **0**, or the value of **uri** is different from the value of **length**.<br>         E_DEVICE_NOT_SUPPORT 801 - The device does not support this API.<br>         E_PERMISSION 201 - The permission verification fails.<br>         E_ENOMEM 13900011 - The memory allocation or copy fails.<br>         E_EPERM 13900001 - The operation is not allowed. All URIs carried in **policies** do not meet the specifications, or the path converted from the URI does not exist.<br>         E_UNKNOWN_ERROR 13900042 - An unknown internal error occurs. The error is none of the preceding errors.<br>         E_NO_ERROR 0 - The API is successfully called.|

### OH_FileShare_ReleasePolicyErrorResult()

```
void OH_FileShare_ReleasePolicyErrorResult(FileShare_PolicyErrorResult *errorResult, unsigned int resultNum)
```

**Description**

Releases the memory, to which **FileShare_PolicyErrorResult** points.

**Since**: 12


**Parameters**

| Name                                                                                      | Description|
|-------------------------------------------------------------------------------------------| -- |
| [FileShare_PolicyErrorResult](capi-fileshare-fileshare-policyerrorresult.md) *errorResult | Pointer to a **FileShare_PolicyErrorResult** instance.|
| unsigned int resultNum                                                                    | Size of the **FileShare_PolicyErrorResult** array.|
