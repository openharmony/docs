# FileShare


## Overview

The **FileShare** module provides APIs for granting permissions on a user file to another application based on the file Uniform Resource Identifier (URI).

**Since**: 12


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [oh_file_share.h](oh__file__share_8h.md) | Provides APIs for persisting permissions, activating or deactivating persistent permissions, and checking the persistent permissions on files or directories based on their URIs.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) | Represents the permission policy error result.| 
| struct  [FileShare_PolicyInfo](_file_share___policy_info.md) | Represents the permission policy information.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [FileShare_OperationMode](#fileshare_operationmode-1) [FileShare_OperationMode](#fileshare_operationmode) | Defines an enum for the URI operation mode.| 
| typedef enum [FileShare_PolicyErrorCode](#fileshare_policyerrorcode-1) [FileShare_PolicyErrorCode](#fileshare_policyerrorcode) | Defines an enum for the permission policy error code.| 
| typedef struct [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) [FileShare_PolicyErrorResult](#fileshare_policyerrorresult) | Defines a struct for the permission policy error result.| 
| typedef struct [FileShare_PolicyInfo](_file_share___policy_info.md) [FileShare_PolicyInfo](#fileshare_policyinfo) | Defines a struct for the permission policy information.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [FileShare_OperationMode](#fileshare_operationmode) {<br>READ_MODE = 1 &lt;&lt; 0,<br>WRITE_MODE = 1 &lt;&lt; 1<br>} | Enumerates the URI operation mode.| 
| [FileShare_PolicyErrorCode](#fileshare_policyerrorcode) {<br>PERSISTENCE_FORBIDDEN = 1,<br>INVALID_MODE = 2,<br>INVALID_PATH = 3,<br>PERMISSION_NOT_PERSISTED = 4<br>} | Enumerates the permission policy error code.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileShare_PersistPermission](#oh_fileshare_persistpermission) (const [FileShare_PolicyInfo](_file_share___policy_info.md) \*policies, unsigned int policyNum, [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) \*\*result, unsigned int \*resultNum) | Persists the permissions on files or directories.| 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileShare_RevokePermission](#oh_fileshare_revokepermission) (const [FileShare_PolicyInfo](_file_share___policy_info.md) \*policies, unsigned int policyNum, [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) \*\*result, unsigned int \*resultNum) | Revokes the permissions from files or directories.| 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileShare_ActivatePermission](#oh_fileshare_activatepermission) (const [FileShare_PolicyInfo](_file_share___policy_info.md) \*policies, unsigned int policyNum, [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) \*\*result, unsigned int \*resultNum) | Activates the persistent permissions on files or directories.| 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileShare_DeactivatePermission](#oh_fileshare_deactivatepermission) (const [FileShare_PolicyInfo](_file_share___policy_info.md) \*policies, unsigned int policyNum, [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) \*\*result, unsigned int \*resultNum) | Deactivates the persistent permissions on files or directories.| 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileShare_CheckPersistentPermission](#oh_fileshare_checkpersistentpermission) (const [FileShare_PolicyInfo](_file_share___policy_info.md) \*policies, unsigned int policyNum, bool \*\*result, unsigned int \*resultNum) | Checks the persistent permissions on files or directories.| 
| void [OH_FileShare_ReleasePolicyErrorResult](#oh_fileshare_releasepolicyerrorresult) ([FileShare_PolicyErrorResult](_file_share___policy_error_result.md) \*errorResult, unsigned int resultNum) | Releases the memory used by **FileShare_PolicyErrorResult**.| 


## Type Description


### FileShare_OperationMode

```
typedef enum FileShare_OperationMode FileShare_OperationMode
```

**Description**

Defines an enum for the URI operation mode.

**Since**: 12


### FileShare_PolicyErrorCode

```
typedef enum FileShare_PolicyErrorCode FileShare_PolicyErrorCode
```

**Description**

Defines an enum for the permission policy error code.

**Since**: 12


### FileShare_PolicyErrorResult

```
typedef struct FileShare_PolicyErrorResult FileShare_PolicyErrorResult
```

**Description**

Defines a struct for the permission policy error result.

**Since**: 12


### FileShare_PolicyInfo

```
typedef struct FileShare_PolicyInfo FileShare_PolicyInfo
```

**Description**

Defines a struct for the permission policy information.

**Since**: 12


## Enum Description


### FileShare_OperationMode

```
enum FileShare_OperationMode
```

**Description**

Enumerates the URI operation mode.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| READ_MODE | Read.| 
| WRITE_MODE | Write.| 


### FileShare_PolicyErrorCode

```
enum FileShare_PolicyErrorCode
```

**Description**

Enumerates the permission policy error code.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| PERSISTENCE_FORBIDDEN | The permission on the URI cannot be persisted.| 
| INVALID_MODE | Invalid mode.| 
| INVALID_PATH | Invalid path.| 
| PERMISSION_NOT_PERSISTED | The permission is not persisted.| 


## Function Description


### OH_FileShare_ActivatePermission()

```
FileManagement_ErrCode OH_FileShare_ActivatePermission (const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum )
```

**Description**

Activates the persistent permissions on files or directories.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| policies | Pointer to a **FileShare_PolicyInfo** instance.| 
| policyNum | Number of policies in the **FileShare_PolicyInfo** array.| 
| result | Double pointer to the **FileShare_PolicyErrorResult** array obtained. Use **OH_FileShare_ReleasePolicyErrorResult()** to release the memory allocated.| 
| resultNum | Pointer to the size of the **FileShare_PolicyErrorResult** array.| 

**Required permissions**

ohos.permission.FILE_ACCESS_PERSIST

**Return value**

[FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode-1)


### OH_FileShare_CheckPersistentPermission()

```
FileManagement_ErrCode OH_FileShare_CheckPersistentPermission (const FileShare_PolicyInfo *policies, unsigned int policyNum, bool **result, unsigned int *resultNum )
```

**Description**

Checks the persistent permissions on files or directories.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| policies | Pointer to a **FileShare_PolicyInfo** instance.| 
| policyNum | Number of policies in the **FileShare_PolicyInfo** array.| 
| result | Double pointer to the check result obtained. You also need to include **malloc.h** and use **free()** to release the memory allocated.| 
| resultNum | Pointer to the size of the check result array.| 

**Required permissions**

ohos.permission.FILE_ACCESS_PERSIST

**Return value**

[FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode-1)


### OH_FileShare_DeactivatePermission()

```
FileManagement_ErrCode OH_FileShare_DeactivatePermission (const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum )
```

**Description**

Deactivates the persistent permissions on files or directories.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| policies | Pointer to a **FileShare_PolicyInfo** instance.| 
| policyNum | Number of policies in the **FileShare_PolicyInfo** array.| 
| result | Double pointer to the **FileShare_PolicyErrorResult** array obtained. Use **OH_FileShare_ReleasePolicyErrorResult()** to release the memory allocated.| 
| resultNum | Pointer to the size of the **FileShare_PolicyErrorResult** array.| 

**Required permissions**

ohos.permission.FILE_ACCESS_PERSIST

**Return value**

[FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode-1)


### OH_FileShare_PersistPermission()

```
FileManagement_ErrCode OH_FileShare_PersistPermission (const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum )
```

**Description**

Persists the permissions on files or directories.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| policies | Pointer to a **FileShare_PolicyInfo** instance.| 
| policyNum | Number of policies in the **FileShare_PolicyInfo** array.| 
| result | Double pointer to the **FileShare_PolicyErrorResult** array obtained. Use **OH_FileShare_ReleasePolicyErrorResult()** to release the memory allocated.| 
| resultNum | Pointer to the size of the **FileShare_PolicyErrorResult** array.| 

**Required permissions**

ohos.permission.FILE_ACCESS_PERSIST

**Return value**

[FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode-1)


### OH_FileShare_ReleasePolicyErrorResult()

```
void OH_FileShare_ReleasePolicyErrorResult (FileShare_PolicyErrorResult *errorResult, unsigned int resultNum )
```

**Description**

Releases the memory used by **FileShare_PolicyErrorResult**.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| errorResult | Pointer to a **FileShare_PolicyErrorResult** instance.| 
| resultNum | Size of the **FileShare_PolicyErrorResult** array.| 


### OH_FileShare_RevokePermission()

```
FileManagement_ErrCode OH_FileShare_RevokePermission (const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum )
```

**Description**

Revokes the permissions from files or directories.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| policies | Pointer to a **FileShare_PolicyInfo** instance.| 
| policyNum | Number of policies in the **FileShare_PolicyInfo** array.| 
| result | Double pointer to the **FileShare_PolicyErrorResult** array obtained. Use **OH_FileShare_ReleasePolicyErrorResult()** to release the memory allocated.| 
| resultNum | Pointer to the size of the **FileShare_PolicyErrorResult** array.| 

**Required permissions**

ohos.permission.FILE_ACCESS_PERSIST

**Return value**

[FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode-1)
