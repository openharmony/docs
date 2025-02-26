# FileShare


## 概述

此模块提供文件分享功能，以授权对其他应用程序具有读写权限的公共目录文件的统一资源标识符（URI）。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [oh_file_share.h](oh__file__share_8h.md) | 提供基于URI的文件及目录授于持久化权限、权限激活、权限查询等方法。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) | 授予或使能权限失败的URI策略结果。 | 
| struct  [FileShare_PolicyInfo](_file_share___policy_info.md) | 需要授予或使能权限URI的策略信息。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [FileShare_OperationMode](#fileshare_operationmode-1) [FileShare_OperationMode](#fileshare_operationmode) | URI操作模式枚举值。 | 
| typedef enum [FileShare_PolicyErrorCode](#fileshare_policyerrorcode-1) [FileShare_PolicyErrorCode](#fileshare_policyerrorcode) | 授予或使能权限策略失败的URI对应的错误码枚举值。 | 
| typedef struct [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) [FileShare_PolicyErrorResult](#fileshare_policyerrorresult) | 授予或使能权限失败的URI策略结果。 | 
| typedef struct [FileShare_PolicyInfo](_file_share___policy_info.md) [FileShare_PolicyInfo](#fileshare_policyinfo) | 需要授予或使能权限URI的策略信息。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [FileShare_OperationMode](#fileshare_operationmode) {<br/>READ_MODE = 1 &lt;&lt; 0,<br/>WRITE_MODE = 1 &lt;&lt; 1<br/>} | URI操作模式枚举值。 | 
| [FileShare_PolicyErrorCode](#fileshare_policyerrorcode) {<br/>PERSISTENCE_FORBIDDEN = 1,<br/>INVALID_MODE = 2,<br/>INVALID_PATH = 3,<br/>PERMISSION_NOT_PERSISTED = 4<br/>} | 授予或使能权限策略失败的URI对应的错误码枚举值。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileShare_PersistPermission](#oh_fileshare_persistpermission) (const [FileShare_PolicyInfo](_file_share___policy_info.md) \*policies, unsigned int policyNum, [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) \*\*result, unsigned int \*resultNum) | 对所选择的多个文件或目录URI持久化授权。 | 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileShare_RevokePermission](#oh_fileshare_revokepermission) (const [FileShare_PolicyInfo](_file_share___policy_info.md) \*policies, unsigned int policyNum, [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) \*\*result, unsigned int \*resultNum) | 对所选择的多个文件或目录URI取消持久化授权。 | 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileShare_ActivatePermission](#oh_fileshare_activatepermission) (const [FileShare_PolicyInfo](_file_share___policy_info.md) \*policies, unsigned int policyNum, [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) \*\*result, unsigned int \*resultNum) | 使能多个已经持久化授权的文件或目录。 | 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileShare_DeactivatePermission](#oh_fileshare_deactivatepermission) (const [FileShare_PolicyInfo](_file_share___policy_info.md) \*policies, unsigned int policyNum, [FileShare_PolicyErrorResult](_file_share___policy_error_result.md) \*\*result, unsigned int \*resultNum) | 取消使能持久化授权过的多个文件或目录。 | 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileShare_CheckPersistentPermission](#oh_fileshare_checkpersistentpermission) (const [FileShare_PolicyInfo](_file_share___policy_info.md) \*policies, unsigned int policyNum, bool \*\*result, unsigned int \*resultNum) | 校验所选择的多个文件或目录URI的持久化授权。 | 
| void [OH_FileShare_ReleasePolicyErrorResult](#oh_fileshare_releasepolicyerrorresult) ([FileShare_PolicyErrorResult](_file_share___policy_error_result.md) \*errorResult, unsigned int resultNum) | 释放FileShare_PolicyErrorResult指针指向的内存资源。 | 


## 类型定义说明


### FileShare_OperationMode

```
typedef enum FileShare_OperationMode FileShare_OperationMode
```

**描述**

URI操作模式枚举值。

**起始版本：** 12


### FileShare_PolicyErrorCode

```
typedef enum FileShare_PolicyErrorCode FileShare_PolicyErrorCode
```

**描述**

授予或使能权限策略失败的URI对应的错误码枚举值。

**起始版本：** 12


### FileShare_PolicyErrorResult

```
typedef struct FileShare_PolicyErrorResult FileShare_PolicyErrorResult
```

**描述**

授予或使能权限失败的URI策略结果。

**起始版本：** 12


### FileShare_PolicyInfo

```
typedef struct FileShare_PolicyInfo FileShare_PolicyInfo
```

**描述**

需要授予或使能权限URI的策略信息。

**起始版本：** 12


## 枚举类型说明


### FileShare_OperationMode

```
enum FileShare_OperationMode
```

**描述**

URI操作模式枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| READ_MODE | 读取权限。 | 
| WRITE_MODE | 写入权限。 | 


### FileShare_PolicyErrorCode

```
enum FileShare_PolicyErrorCode
```

**描述**

授予或使能权限策略失败的URI对应的错误码枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| PERSISTENCE_FORBIDDEN | URI禁止被持久化。 | 
| INVALID_MODE | 无效的模式。 | 
| INVALID_PATH | 无效路径。 | 
| PERMISSION_NOT_PERSISTED | 权限没有被持久化。 | 


## 函数说明


### OH_FileShare_ActivatePermission()

```
FileManagement_ErrCode OH_FileShare_ActivatePermission (const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum )
```

**描述**

使能多个已经持久化授权的文件或目录。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| policies | 一个指向FileShare_PolicyInfo实例的指针。 | 
| policyNum | FileShare_PolicyInfo实例数组的大小。 | 
| result | FileShare_PolicyErrorResult数组指针。 请使用OH_FileShare_ReleasePolicyErrorResult()进行资源释放。 | 
| resultNum | FileShare_PolicyErrorResult数组大小。 | 

**需要权限：**

ohos.permission.FILE_ACCESS_PERSIST

**返回：**

返回FileManageMent模块错误码[FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode-1)。


### OH_FileShare_CheckPersistentPermission()

```
FileManagement_ErrCode OH_FileShare_CheckPersistentPermission (const FileShare_PolicyInfo *policies, unsigned int policyNum, bool **result, unsigned int *resultNum )
```

**描述**

校验所选择的多个文件或目录URI的持久化授权。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| policies | 一个指向FileShare_PolicyInfo实例的指针。 | 
| policyNum | FileShare_PolicyInfo实例数组的大小。 | 
| result | 授权校验结果指针。请引用头文件malloc.h并使用free()进行资源释放。 | 
| resultNum | 校验结果数组的大小。| 

**需要权限：**

ohos.permission.FILE_ACCESS_PERSIST

**返回：**

返回FileManageMent模块错误码[FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode-1)。


### OH_FileShare_DeactivatePermission()

```
FileManagement_ErrCode OH_FileShare_DeactivatePermission (const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum )
```

**描述**

取消使能持久化授权过的多个文件或目录。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| policies | 一个指向FileShare_PolicyInfo实例的指针。 | 
| policyNum | FileShare_PolicyInfo实例数组的大小。 | 
| result | FileShare_PolicyErrorResult数组指针。 请使用OH_FileShare_ReleasePolicyErrorResult()进行资源释放。 | 
| resultNum | FileShare_PolicyErrorResult数组大小。 | 

**需要权限：**

ohos.permission.FILE_ACCESS_PERSIST

**返回：**

返回FileManageMent模块错误码[FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode-1)。


### OH_FileShare_PersistPermission()

```
FileManagement_ErrCode OH_FileShare_PersistPermission (const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum )
```

**描述**

对所选择的多个文件或目录URI持久化授权。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| policies | 一个指向FileShare_PolicyInfo实例的指针。 | 
| policyNum | FileShare_PolicyInfo实例数组的大小。 | 
| result | FileShare_PolicyErrorResult数组指针。请使用OH_FileShare_ReleasePolicyErrorResult()进行资源释放。 | 
| resultNum | FileShare_PolicyErrorResult数组大小。 | 

**需要权限：**

ohos.permission.FILE_ACCESS_PERSIST

**返回：**

返回FileManageMent模块错误码[FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode-1)。


### OH_FileShare_ReleasePolicyErrorResult()

```
void OH_FileShare_ReleasePolicyErrorResult (FileShare_PolicyErrorResult *errorResult, unsigned int resultNum )
```

**描述**

释放FileShare_PolicyErrorResult指针指向的内存资源。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| errorResult | 一个指向FileShare_PolicyErrorResult实例的指针。 | 
| resultNum | FileShare_PolicyErrorResult实例数组的大小。 | 


### OH_FileShare_RevokePermission()

```
FileManagement_ErrCode OH_FileShare_RevokePermission (const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum )
```

**描述**

对所选择的多个文件或目录uri取消持久化授权。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| policies | 一个指向FileShare_PolicyInfo实例的指针。 | 
| policyNum | FileShare_PolicyInfo实例数组的大小。 | 
| result | FileShare_PolicyErrorResult数组指针。请使用OH_FileShare_ReleasePolicyErrorResult()进行资源释放。 | 
| resultNum | FileShare_PolicyErrorResult数组大小。 | 

**需要权限：**

ohos.permission.FILE_ACCESS_PERSIST

**返回：**

返回FileManageMent模块错误码[FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode-1)。
