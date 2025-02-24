# DlpPermissionApi


## Overview

Data loss prevention (DLP) is a system solution provided to prevent data disclosure. The **dlppermissionapi** file provides APIs for cross-device file access management, encrypted storage, and access authorization.

**Since**: 14


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [dlp_permission_api.h](dlp__permission__api_8h.md) | Defines the APIs for cross-device file access management, encrypted storage, and access authorization. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [DLP_ErrCode](#dlp_errcode) {<br>ERR_OH_SUCCESS = 0,<br>ERR_OH_INVALID_PARAMETER = 19100001,<br>ERR_OH_API_ONLY_FOR_SANDBOX = 19100006,<br>ERR_OH_API_NOT_FOR_SANDBOX = 19100007,<br>ERR_OH_SYSTEM_SERVICE_EXCEPTION = 19100011,<br>ERR_OH_OUT_OF_MEMORY = 19100012,<br>ERR_OH_APPLICATION_NOT_AUTHORIZED = 19100018<br>} | Enumerates the DLP error codes.| 
| [DLP_FileAccess](#dlp_fileaccess) {<br>NO_PERMISSION = 0,<br>READ_ONLY = 1,<br>CONTENT_EDIT = 2,<br>FULL_CONTROL = 3<br>} | Enumerates the permissions on a DLP file.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [DLP_ErrCode](#dlp_errcode) [OH_DLP_GetDlpPermissionInfo](#oh_dlp_getdlppermissioninfo) ([DLP_FileAccess](#dlp_fileaccess) \*dlpFileAccess, uint32_t \*flags) | Obtains the permission information of this DLP file.| 
| [DLP_ErrCode](#dlp_errcode) [OH_DLP_GetOriginalFileName](#oh_dlp_getoriginalfilename) (const char \*fileName, char \*\*originalFileName) | Obtains the original file name of a DLP file.| 
| [DLP_ErrCode](#dlp_errcode) [OH_DLP_IsInSandbox](#oh_dlp_isinsandbox) (bool \*isInSandbox) | Checks whether this application is running in a DLP sandbox environment.| 
| [DLP_ErrCode](#dlp_errcode) [OH_DLP_SetSandboxAppConfig](#oh_dlp_setsandboxappconfig) (const char \*configInfo) | Sets sandbox application configuration.| 
| [DLP_ErrCode](#dlp_errcode) [OH_DLP_GetSandboxAppConfig](#oh_dlp_getsandboxappconfig) (char \*\*configInfo) | Obtains the sandbox application configuration.| 
| [DLP_ErrCode](#dlp_errcode) [OH_DLP_CleanSandboxAppConfig](#oh_dlp_cleansandboxappconfig) () | Cleans the sandbox application configuration.| 


## Enum Description


### DLP_ErrCode

```
enum DLP_ErrCode
```

**Description**

Enumerates the DLP error codes.

**Since**: 14

| Value| Description| 
| -------- | -------- |
| ERR_OH_SUCCESS | The operation is successful.|
| ERR_OH_INVALID_PARAMETER | Invalid parameters are specified.|
| ERR_OH_API_ONLY_FOR_SANDBOX | The caller is not a DLP sandbox application.|
| ERR_OH_API_NOT_FOR_SANDBOX | The API is not available to a DLP sandbox application.|
| ERR_OH_SYSTEM_SERVICE_EXCEPTION | The system service is abnormal.|
| ERR_OH_OUT_OF_MEMORY | The memory allocation fails.|
| ERR_OH_APPLICATION_NOT_AUTHORIZED | The application is not authorized to perform the operation.|


### DLP_FileAccess

```
enum DLP_FileAccess
```

**Description**

Enumerates the permissions on a DLP file.

**Since**: 14

| Value| Description| 
| -------- | -------- |
| NO_PERMISSION | No permission on the file.| 
| READ_ONLY | Read-only permission.| 
| CONTENT_EDIT | Edit permission.| 
| FULL_CONTROL | Full control.| 


## Function Description


### OH_DLP_GetDlpPermissionInfo()

```
DLP_ErrCode OH_DLP_GetDlpPermissionInfo(DLP_FileAccess *dlpFileAccess, uint32_t *flags)
```

**Description**

Obtains the permission information of this DLP file.

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| dlpFileAccess | Pointer to the authorization type of the DLP file for users. For details, see [DLP_FileAccess](#dlp_fileaccess).| 
| flags | Pointer to the operation permissions allowed for the DLP file. The options are as follows:<br>**0x00000000** indicates no permission on the file.<br>**0x00000001** indicates the permission for viewing the file.<br>**0x00000002** indicates the permission for saving the file.<br>**0x00000004** indicates the permission for saving the file as another file.<br>**0x00000008** indicates the permission for editing the file.<br>**0x00000010** indicates the permission for capturing screenshots of the file.<br>**0x00000020** indicates the permission for sharing the screen, on which the file is open.<br>**0x00000040** indicates the permission for recording the screen, on which the file is open.<br>**0x00000080** indicates the permission for copying the file.<br>**0x00000100** indicates the permission for printing the file.<br>**0x00000200** indicates the permission for exporting the file.<br>**0x00000400** indicates the permission for modifying the permissions on the file.| 

**Returns**

[DLP_ErrCode](#dlp_errcode):

Returns **0** if the operation is successful.

Returns **19100001** if invalid parameters are detected.

Returns **19100006** when the access is denied for a non-DLP sandbox application.

Returns **19100011** when the system service is abnormal.

Returns **19100012** if the memory allocation fails.


### OH_DLP_GetOriginalFileName()

```
DLP_ErrCode OH_DLP_GetOriginalFileName(const char *fileName, char **originalFileName)
```

**Description**

Obtains the original file name of a DLP file.

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| fileName | Pointer to the target file whose original file name is to be obtained.| 
| originalFileName | Double pointer to the original file name obtained.| 

**Returns**

[DLP_ErrCode](#dlp_errcode):

Returns **0** if the operation is successful.

Returns **19100001** if invalid parameters are detected.

Returns **19100012** if the memory allocation fails.


### OH_DLP_IsInSandbox()

```
DLP_ErrCode OH_DLP_IsInSandbox(bool *isInSandbox)
```

**Description**

Checks whether this application is running in a DLP sandbox environment.

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| isInSandbox | Pointer to the value indicating whether the application is running in a DLP sandbox environment.| 

**Returns**

[DLP_ErrCode](#dlp_errcode):

Returns **0** if the operation is successful.

Returns **19100011** when the system service is abnormal.

Returns **19100012** if the memory allocation fails.


### OH_DLP_SetSandboxAppConfig()

```
DLP_ErrCode OH_DLP_SetSandboxAppConfig(const char *configInfo)
```

**Description**

Sets sandbox application configuration.

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| configInfo | Pointer to the sandbox application configuration to set.| 

**Returns**

[DLP_ErrCode](#dlp_errcode):

Returns **0** if the operation is successful.

Returns **19100001** if invalid parameters are detected.

Returns **19100007** if the API cannot be called by a DLP sandbox application.

Returns **19100011** when the system service is abnormal.

Returns **19100018** if the application is unauthorized.


### OH_DLP_GetSandboxAppConfig()

```
DLP_ErrCode OH_DLP_GetSandboxAppConfig(char **configInfo)
```

**Description**

Obtains the sandbox application configuration.

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| configInfo | Pointer to the sandbox application configuration obtained.| 

**Returns**

[DLP_ErrCode](#dlp_errcode):

Returns **0** if the operation is successful.

Returns **19100011** when the system service is abnormal.

Returns **19100012** if the memory allocation fails.

Returns **19100018** if the application is unauthorized.


### OH_DLP_CleanSandboxAppConfig()

```
DLP_ErrCode OH_DLP_CleanSandboxAppConfig()
```

**Description**

Cleans the sandbox application configuration.

**Since**: 14

**Returns**

[DLP_ErrCode](#dlp_errcode):

Returns **0** if the operation is successful.

Returns **19100007** if the API cannot be called by a DLP sandbox application.

Returns **19100011** when the system service is abnormal.

Returns **19100018** if the application is unauthorized.
