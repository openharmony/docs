# dlp_permission_api.h


## 概述

声明用于跨设备的文件的权限管理、加密存储、授权访问等能力的接口。

**库：** libohdlp_permission.so

**系统能力：** SystemCapability.Security.DataLossPrevention

**起始版本：** 13

**相关模块：**[DlpPermissionApi](_dlp_permission_api.md)


## 汇总


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [DLP_ErrCode](_dlp_permission_api.md#dlp_errcode) {<br/>ERR_OH_SUCCESS = 0,<br/>ERR_OH_INVALID_PARAMETER = 19100001,<br/>ERR_OH_API_ONLY_FOR_SANDBOX = 19100006,<br/>ERR_OH_API_NOT_FOR_SANDBOX = 19100007,<br/>ERR_OH_SYSTEM_SERVICE_EXCEPTION = 19100011,<br/>ERR_OH_OUT_OF_MEMORY = 19100012,<br/>ERR_OH_APPLICATION_NOT_AUTHORIZED = 19100018<br/>} | DLP错误码的枚举。 | 
| [DLP_FileAccess](_dlp_permission_api.md#dlp_fileaccess) {<br/>NO_PERMISSION = 0,<br/>READ_ONLY = 1,<br/>CONTENT_EDIT = 2,<br/>FULL_CONTROL = 3<br/>} | DLP文件授权类型的枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [DLP_ErrCode](_dlp_permission_api.md#dlp_errcode) [OH_DLP_GetDlpPermissionInfo](_dlp_permission_api.md#oh_dlp_getdlppermissioninfo) ([DLP_FileAccess](_dlp_permission_api.md#dlp_fileaccess ) \*dlpFileAccess, uint32_t \*flags) | 查询当前DLP沙箱的权限信息。 | 
| [DLP_ErrCode](_dlp_permission_api.md#dlp_errcode) [OH_DLP_GetOriginalFileName](_dlp_permission_api.md#oh_dlp_getoriginalfilename) (const char \*fileName, char \*\*originalFileName) | 获取指定DLP文件名的原始文件名。 | 
| [DLP_ErrCode](_dlp_permission_api.md#dlp_errcode) [OH_DLP_IsInSandbox](_dlp_permission_api.md#oh_dlp_isinsandbox) (bool \*isInSandbox) | 查询当前应用是否运行在DLP沙箱环境。 | 
| [DLP_ErrCode](_dlp_permission_api.md#dlp_errcode) [OH_DLP_SetSandboxAppConfig](_dlp_permission_api.md#oh_dlp_setsandboxappconfig) (const char \*configInfo) | 设置沙箱应用配置信息。 | 
| [DLP_ErrCode](_dlp_permission_api.md#dlp_errcode) [OH_DLP_GetSandboxAppConfig](_dlp_permission_api.md#oh_dlp_getsandboxappconfig) (char \*\*configInfo) | 获取沙箱应用配置信息。 | 
| [DLP_ErrCode](_dlp_permission_api.md#dlp_errcode) [OH_DLP_CleanSandboxAppConfig](_dlp_permission_api.md#oh_dlp_cleansandboxappconfig) () | 清理沙箱应用配置信息。 | 
