# dlp_permission_api.h
<!--Kit: Data Protection Kit-->
<!--Subsystem: Security-->
<!--Owner: @winnieHuYu-->
<!--SE: @lucky-jinduo-->
<!--TSE: @nacyli-->

## Overview

Defines the APIs for cross-device file access management, encrypted storage, and access authorization.

**Library**: libohdlp_permission.so

**File to include**: <DataProtectionKit/dlp_permission_api.h>

**System capability**: SystemCapability.Security.DataLossPrevention

**Since**: 14

**Related module**: [DlpPermissionApi](capi-dlppermissionapi.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [DLP_ErrCode](#dlp_errcode) | DLP_ErrCode | Enumerates the DLP error codes.|
| [DLP_FileAccess](#dlp_fileaccess) | DLP_FileAccess | Enumerates the permissions on a DLP file.|

### Functions

| Name| Description|
| -- | -- |
| [DLP_ErrCode OH_DLP_GetDlpPermissionInfo(DLP_FileAccess *dlpFileAccess, uint32_t *flags)](#oh_dlp_getdlppermissioninfo) | Obtains the permission information of this DLP file.|
| [DLP_ErrCode OH_DLP_GetOriginalFileName(const char *fileName, char *originalFileName)](#oh_dlp_getoriginalfilename) | Obtains the original file name of a DLP file.|
| [DLP_ErrCode OH_DLP_IsInSandbox(bool *isInSandbox)](#oh_dlp_isinsandbox) | Checks whether this application is running in a DLP sandbox environment.|
| [DLP_ErrCode OH_DLP_SetSandboxAppConfig(const char *configInfo)](#oh_dlp_setsandboxappconfig) | Sets sandbox application configuration.|
| [DLP_ErrCode OH_DLP_GetSandboxAppConfig(char *configInfo)](#oh_dlp_getsandboxappconfig) | Obtains the sandbox application configuration.|
| [DLP_ErrCode OH_DLP_CleanSandboxAppConfig()](#oh_dlp_cleansandboxappconfig) | Cleans the sandbox application configuration.|

## Enum Description

### DLP_ErrCode

```
enum DLP_ErrCode
```

**Description**

Enumerates the DLP error codes.

**Since**: 14

| Enum| Description|
| -- | -- |
| ERR_OH_SUCCESS = 0 | The operation is successful.|
| ERR_OH_INVALID_PARAMETER = 19100001 | Invalid parameters are specified.|
| ERR_OH_API_ONLY_FOR_SANDBOX = 19100006 | The caller is not a DLP sandbox application.|
| ERR_OH_API_NOT_FOR_SANDBOX = 19100007 | The API is not available to a DLP sandbox application.|
| ERR_OH_SYSTEM_SERVICE_EXCEPTION = 19100011 | The system service is abnormal.|
| ERR_OH_OUT_OF_MEMORY = 19100012 | The memory allocation fails.|
| ERR_OH_APPLICATION_NOT_AUTHORIZED = 19100018 | The application is not authorized to perform the operation.|

### DLP_FileAccess

```
enum DLP_FileAccess
```

**Description**

Enumerates the permissions on a DLP file.

**Since**: 14

| Enum| Description|
| -- | -- |
| NO_PERMISSION = 0 | No permission on the file.|
| READ_ONLY = 1 | Read-only permission.|
| CONTENT_EDIT = 2 | Editing permission.|
| FULL_CONTROL = 3 | Full control.|


## Function Description

### OH_DLP_GetDlpPermissionInfo()

```
DLP_ErrCode OH_DLP_GetDlpPermissionInfo(DLP_FileAccess *dlpFileAccess, uint32_t *flags)
```

**Description**

Obtains the permission information of this DLP file.

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [DLP_FileAccess](#dlp_fileaccess) *dlpFileAccess | User permission on the DLP file, for example, read-only.|
| uint32_t *flags | Pointer to the operation permissions allowed for the DLP file. The options are as follows:<br>**0x00000000** indicates no permission on the file.<br>**0x00000001** indicates the permission for viewing the file.<br>**0x00000002** indicates the permission for saving the file.<br>**0x00000004** indicates the permission for saving the file as another file.<br>**0x00000008** indicates the permission for editing the file.<br>**0x00000010** indicates the permission for capturing screenshots of the file.<br>**0x00000020** indicates the permission for sharing the screen, on which the file is open.<br>**0x00000040** indicates the permission for recording the screen, on which the file is open.<br>**0x00000080** indicates the permission for copying the file.<br>**0x00000100** indicates the permission for printing the file.<br>**0x00000200** indicates the permission for exporting the file.<br>**0x00000400** indicates the permission for modifying the permissions on the file.|

**Return value**

| Type| Description|
| -- | -- |
| [DLP_ErrCode](#dlp_errcode) | Returns **0** if the operation is successful.<br>         Returns **19100001** if invalid parameters are detected.<br>         Returns **19100006** when the access is denied for a non-DLP sandbox application.<br>         Returns **19100011** when the system service is abnormal.<br>         Returns **19100012** if the memory allocation fails.|

### OH_DLP_GetOriginalFileName()

```
DLP_ErrCode OH_DLP_GetOriginalFileName(const char *fileName, char *originalFileName)
```

**Description**

Obtains the original file name of a DLP file.

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| const char *fileName | Pointer to the target file whose original file name is to be obtained.|
| char *originalFileName | Double pointer to the original file name obtained.|

**Return value**

| Type| Description|
| -- | -- |
| [DLP_ErrCode](#dlp_errcode) | Returns **0** if the operation is successful.<br>         Returns **19100001** if invalid parameters are detected.<br>         Returns **19100012** if the memory allocation fails.|

### OH_DLP_IsInSandbox()

```
DLP_ErrCode OH_DLP_IsInSandbox(bool *isInSandbox)
```

**Description**

Checks whether this application is running in a DLP sandbox environment.

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| bool *isInSandbox | Pointer to the value indicating whether the application is running in a DLP sandbox environment.|

**Return value**

| Type| Description|
| -- | -- |
| [DLP_ErrCode](#dlp_errcode) | Returns **0** if the operation is successful.<br>         Returns **19100011** when the system service is abnormal.<br>         Returns **19100012** if the memory allocation fails.|

### OH_DLP_SetSandboxAppConfig()

```
DLP_ErrCode OH_DLP_SetSandboxAppConfig(const char *configInfo)
```

**Description**

Sets sandbox application configuration.

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| const char *configInfo | Pointer to the sandbox application configuration obtained.|

**Return value**

| Type| Description|
| -- | -- |
| [DLP_ErrCode](#dlp_errcode) | Returns **0** if the operation is successful.<br>         Returns **19100001** if invalid parameters are detected.<br>         Returns **19100007** if the API cannot be called by a DLP sandbox application.<br>         Returns **19100011** when the system service is abnormal.<br>         Returns **19100018** if the application is unauthorized.|

### OH_DLP_GetSandboxAppConfig()

```
DLP_ErrCode OH_DLP_GetSandboxAppConfig(char *configInfo)
```

**Description**

Obtains the sandbox application configuration.

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| char *configInfo | Pointer to the sandbox application configuration obtained.|

**Return value**

| Type| Description|
| -- | -- |
| [DLP_ErrCode](#dlp_errcode) | Returns **0** if the operation is successful.<br>         Returns **19100011** when the system service is abnormal.<br>         Returns **19100012** if the memory allocation fails.<br>         Returns **19100018** if the application is unauthorized.|

### OH_DLP_CleanSandboxAppConfig()

```
DLP_ErrCode OH_DLP_CleanSandboxAppConfig()
```

**Description**

Cleans the sandbox application configuration.

**Since**: 14

**Return value**

| Type| Description|
| -- | -- |
| [DLP_ErrCode](#dlp_errcode) | Returns **0** if the operation is successful.<br>         Returns **19100007** if the API cannot be called by a DLP sandbox application.<br>         Returns **19100011** when the system service is abnormal.<br>         Returns **19100018** if the application is unauthorized.|
