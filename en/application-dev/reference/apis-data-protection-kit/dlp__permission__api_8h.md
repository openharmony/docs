# dlp_permission_api.h


## Overview

Defines the APIs for cross-device file access management, encrypted storage, and access authorization.

**Library**: libohdlp_permission.so

**System capability**: SystemCapability.Security.DataLossPrevention

**Since**: 14

**Related module**: [DlpPermissionApi](_dlp_permission_api.md)


## Summary


### Enums

| Name| Description| 
| -------- | -------- |
| [DLP_ErrCode](_dlp_permission_api.md#dlp_errcode) {<br>ERR_OH_SUCCESS = 0,<br>ERR_OH_INVALID_PARAMETER = 19100001,<br>ERR_OH_API_ONLY_FOR_SANDBOX = 19100006,<br>ERR_OH_API_NOT_FOR_SANDBOX = 19100007,<br>ERR_OH_SYSTEM_SERVICE_EXCEPTION = 19100011,<br>ERR_OH_OUT_OF_MEMORY = 19100012,<br>ERR_OH_APPLICATION_NOT_AUTHORIZED = 19100018<br>} | Enumerates the DLP error codes.| 
| [DLP_FileAccess](_dlp_permission_api.md#dlp_fileaccess) {<br>NO_PERMISSION = 0,<br>READ_ONLY = 1,<br>CONTENT_EDIT = 2,<br>FULL_CONTROL = 3<br>} | Enumerates the permissions on a DLP file.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [DLP_ErrCode](_dlp_permission_api.md#dlp_errcode) [OH_DLP_GetDlpPermissionInfo](_dlp_permission_api.md#oh_dlp_getdlppermissioninfo) ([DLP_FileAccess](_dlp_permission_api.md#dlp_fileaccess ) \*dlpFileAccess, uint32_t \*flags) | Obtains the permission information of this DLP file.| 
| [DLP_ErrCode](_dlp_permission_api.md#dlp_errcode) [OH_DLP_GetOriginalFileName](_dlp_permission_api.md#oh_dlp_getoriginalfilename) (const char \*fileName, char \*\*originalFileName) | Obtains the original file name of a DLP file.| 
| [DLP_ErrCode](_dlp_permission_api.md#dlp_errcode) [OH_DLP_IsInSandbox](_dlp_permission_api.md#oh_dlp_isinsandbox) (bool \*isInSandbox) | Checks whether this application is running in a DLP sandbox environment.| 
| [DLP_ErrCode](_dlp_permission_api.md#dlp_errcode) [OH_DLP_SetSandboxAppConfig](_dlp_permission_api.md#oh_dlp_setsandboxappconfig) (const char \*configInfo) | Sets sandbox application configuration.| 
| [DLP_ErrCode](_dlp_permission_api.md#dlp_errcode) [OH_DLP_GetSandboxAppConfig](_dlp_permission_api.md#oh_dlp_getsandboxappconfig) (char \*\*configInfo) | Obtains the sandbox application configuration.| 
| [DLP_ErrCode](_dlp_permission_api.md#dlp_errcode) [OH_DLP_CleanSandboxAppConfig](_dlp_permission_api.md#oh_dlp_cleansandboxappconfig) () | Cleans the sandbox application configuration.| 
