# oh_file_share.h


## 概述

提供基于URI的文件及目录授于持久化权限、权限激活、权限查询等方法。

**库：** libohfileshare.so

**系统能力：** SystemCapability.FileManagement.AppFileService.FolderAuthorization

**起始版本：** 12

**相关模块：**[FileShare](file_share.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) | 授予或使能权限失败的URI策略结果。  | 
| struct  [FileShare_PolicyInfo](_file_share___policy_info.md) | 需要授予或使能权限URI的策略信息。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [FileShare_OperationMode](file_share.md#fileshare_operationmode-1) [FileShare_OperationMode](file_share.md#fileshare_operationmode) | URI操作模式枚举值。  | 
| typedef enum [FileShare_PolicyErrorCode](file_share.md#fileshare_policyerrorcode-1) [FileShare_PolicyErrorCode](file_share.md#fileshare_policyerrorcode) | 授予或使能权限策略失败的URI对应的错误码枚举值。  | 
| typedef struct [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) [FileShare_PolicyErrorResult](file_share.md#fileshare_policyerrorresult) | 授予或使能权限失败的URI策略结果。  | 
| typedef struct [FileShare_PolicyInfo](_file_share___policy_info.md) [FileShare_PolicyInfo](file_share.md#fileshare_policyinfo) | 需要授予或使能权限URI的策略信息。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [FileShare_OperationMode](file_share.md#fileshare_operationmode) { [READ_MODE](file_share.md#枚举类型说明) = 1 &lt;&lt; 0, [WRITE_MODE](file_share.md#枚举类型说明) = 1 &lt;&lt; 1 } | URI操作模式枚举值。  | 
| [FileShare_PolicyErrorCode](file_share.md#枚举类型说明) { [PERSISTENCE_FORBIDDEN](file_share.md#枚举类型说明) = 1, [INVALID_MODE](file_share.md#枚举类型说明) = 2, [INVALID_PATH](file_share.md#枚举类型说明) = 3, [PERMISSION_NOT_PERSISTED](file_share.md#枚举类型说明) = 4 } | 授予或使能权限策略失败的URI对应的错误码枚举值。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileShare_PersistPermission](file_share.md#oh_fileshare_persistpermission) (const [FileShare_PolicyInfo](_file_share___policy_info.md) \*policies, unsigned int policyNum, [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) \*\*result, unsigned int \*resultNum) | 对所选择的多个文件或目录URI持久化授权。  | 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileShare_RevokePermission](file_share.md#oh_fileshare_revokepermission) (const [FileShare_PolicyInfo](_file_share___policy_info.md) \*policies, unsigned int policyNum, [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) \*\*result, unsigned int \*resultNum) | 对所选择的多个文件或目录uri取消持久化授权。  | 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileShare_ActivatePermission](file_share.md#oh_fileshare_activatepermission) (const [FileShare_PolicyInfo](_file_share___policy_info.md) \*policies, unsigned int policyNum, [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) \*\*result, unsigned int \*resultNum) | 使能多个已经持久化授权的文件或目录。  | 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileShare_DeactivatePermission](file_share.md#oh_fileshare_deactivatepermission) (const [FileShare_PolicyInfo](_file_share___policy_info.md) \*policies, unsigned int policyNum, [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) \*\*result, unsigned int \*resultNum) | 取消使能持久化授权过的多个文件或目录。  | 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileShare_CheckPersistentPermission](file_share.md#oh_fileshare_checkpersistentpermission) (const [FileShare_PolicyInfo](_file_share___policy_info.md) \*policies, unsigned int policyNum, bool \*\*result, unsigned int \*resultNum) | 校验所选择的多个文件或目录URI的持久化授权。  | 
| void [OH_FileShare_ReleasePolicyErrorResult](file_share.md#oh_fileshare_releasepolicyerrorresult) ([FileShare_PolicyErrorResult](_file_share___policy_error_result.md) \*errorResult, unsigned int resultNum) | 释放FileShare_PolicyErrorResult指针指向的内存资源。  | 
