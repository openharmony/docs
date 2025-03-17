# oh_file_share.h


## Overview

Provides APIs for persisting permissions, activating or deactivating permissions, and obtaining permissions on files based on their URI.

**Library**: **libohfileshare.so**

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

**Since**: 12

**Related module**: [FileShare](file_share.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) | Defines a struct for the permission policy error information. | 
| struct  [FileShare_PolicyInfo](_file_share___policy_info.md) | Defines a struct for the permission policy information. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [FileShare_OperationMode](file_share.md#fileshare_operationmode-1) [FileShare_OperationMode](file_share.md#fileshare_operationmode) | Defines an enum for the permissions on a URI. | 
| typedef enum [FileShare_PolicyErrorCode](file_share.md#fileshare_policyerrorcode-1) [FileShare_PolicyErrorCode](file_share.md#fileshare_policyerrorcode) | Defines an enum for the permission policy error codes. | 
| typedef struct [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) [FileShare_PolicyErrorResult](file_share.md#fileshare_policyerrorresult) | Defines a struct for the permission policy error information. | 
| typedef struct [FileShare_PolicyInfo](_file_share___policy_info.md) [FileShare_PolicyInfo](file_share.md#fileshare_policyinfo) | Defines a struct for the permission policy information. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [FileShare_OperationMode](file_share.md#fileshare_operationmode) { [READ_MODE](file_share.md#enum-description) = 1 &lt;&lt; 0, [WRITE_MODE](file_share.md#enum-description) = 1 &lt;&lt; 1 }| Enumerates the permissions on a URI. | 
| [FileShare_PolicyErrorCode](file_share.md#enum-description) { [PERSISTENCE_FORBIDDEN](file_share.md#enum-description) = 1, [INVALID_MODE](file_share.md#enum-description) = 2, [INVALID_PATH](file_share.md#enum-description) = 3, [PERMISSION_NOT_PERSISTED](file_share.md#enum-description) = 4 }| Enumerates the permission policy error codes. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileShare_PersistPermission](file_share.md#oh_fileshare_persistpermission) (const [FileShare_PolicyInfo](_file_share___policy_info.md) \*policies, unsigned int policyNum, [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) \*\*result, unsigned int \*resultNum) | Persists the permissions on files or folders. | 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileShare_RevokePermission](file_share.md#oh_fileshare_revokepermission) (const [FileShare_PolicyInfo](_file_share___policy_info.md) \*policies, unsigned int policyNum, [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) \*\*result, unsigned int \*resultNum) | Revokes the permissions from files or folders. | 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileShare_ActivatePermission](file_share.md#oh_fileshare_activatepermission) (const [FileShare_PolicyInfo](_file_share___policy_info.md) \*policies, unsigned int policyNum, [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) \*\*result, unsigned int \*resultNum) | Activates the persistent permissions on files or folders. | 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileShare_DeactivatePermission](file_share.md#oh_fileshare_deactivatepermission) (const [FileShare_PolicyInfo](_file_share___policy_info.md) \*policies, unsigned int policyNum, [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) \*\*result, unsigned int \*resultNum) | Deactivates the persistent permissions on files or folders. | 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileShare_CheckPersistentPermission](file_share.md#oh_fileshare_checkpersistentpermission) (const [FileShare_PolicyInfo](_file_share___policy_info.md) \*policies, unsigned int policyNum, bool \*\*result, unsigned int \*resultNum) | Checks the persistent permissions on files or folders. | 
| void [OH_FileShare_ReleasePolicyErrorResult](file_share.md#oh_fileshare_releasepolicyerrorresult) ([FileShare_PolicyErrorResult](_file_share___policy_error_result.md) \*errorResult, unsigned int resultNum) | Releases the memory, to which **FileShare_PolicyErrorResult** points. | 
