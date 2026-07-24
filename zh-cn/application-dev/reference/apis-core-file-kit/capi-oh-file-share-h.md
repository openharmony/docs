# oh_file_share.h
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @rainlost-->
<!--Designer: @rainlost-->
<!--Tester: @leiyuqian-->
<!--Adviser: @jinqiuheng-->

## 概述

提供基于URI的文件及目录持久化授权、取消持久化授权、权限激活、权限查询等方法，适用于跨应用文件共享场景。持久化授权用于保存访问策略，权限激活用于使已持久化的权限生效。

**引用文件：** <filemanagement/fileshare/oh_file_share.h>

**库：** libohfileshare.so

**系统能力：** SystemCapability.FileManagement.AppFileService.FolderAuthorization

**起始版本：** 12

**相关模块：** [fileShare](capi-fileshare.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [FileShare_PolicyErrorResult](capi-fileshare-fileshare-policyerrorresult.md) | FileShare_PolicyErrorResult | 授予或激活权限失败的URI策略结果，用于记录失败URI、错误码和失败原因。 |
| [FileShare_PolicyInfo](capi-fileshare-fileshare-policyinfo.md) | FileShare_PolicyInfo | 需要授予或激活URI访问权限的策略信息，用于描述跨应用文件共享场景中的目标URI和访问模式。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [FileShare_OperationMode](#fileshare_operationmode) | FileShare_OperationMode | URI操作模式枚举值。 |
| [FileShare_PolicyErrorCode](#fileshare_policyerrorcode) | FileShare_PolicyErrorCode | 授予或激活权限策略失败的URI对应的错误码。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [FileManagement_ErrCode OH_FileShare_PersistPermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum)](#oh_fileshare_persistpermission) | 对所选择的多个文件或目录URI持久化授权。完成持久化授权后，可调用OH_FileShare_ActivatePermission()激活权限。 |
| [FileManagement_ErrCode OH_FileShare_RevokePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum)](#oh_fileshare_revokepermission) | 对所选择的多个文件或目录URI取消持久化授权。调用此接口前，需要先完成持久化授权。 |
| [FileManagement_ErrCode OH_FileShare_ActivatePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum)](#oh_fileshare_activatepermission) | 激活多个已经持久化授权的文件或目录。调用此接口前，需要先调用OH_FileShare_PersistPermission()完成持久化授权，激活后权限生效。 |
| [FileManagement_ErrCode OH_FileShare_DeactivatePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum)](#oh_fileshare_deactivatepermission) | 取消激活持久化授权过的多个文件或目录。调用此接口前，需要先调用OH_FileShare_ActivatePermission()激活权限。取消激活后，持久化授权仍保留。 |
| [FileManagement_ErrCode OH_FileShare_CheckPersistentPermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, bool **result, unsigned int *resultNum)](#oh_fileshare_checkpersistentpermission) | 校验所选择的多个文件或目录URI的持久化授权。可在激活权限前调用该接口，确认目标URI是否已经完成持久化授权。 |
| [void OH_FileShare_ReleasePolicyErrorResult(FileShare_PolicyErrorResult *errorResult, unsigned int resultNum)](#oh_fileshare_releasepolicyerrorresult) | 释放FileShare_PolicyErrorResult指针指向的内存资源。该资源由OH_FileShare_PersistPermission、OH_FileShare_RevokePermission、OH_FileShare_ActivatePermission和OH_FileShare_DeactivatePermission通过result输出。 |

## 枚举类型说明

### FileShare_OperationMode

```c
enum FileShare_OperationMode
```

**描述**

URI操作模式枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| READ_MODE = 1 << 0 | 读取权限，可单独使用，也可与WRITE_MODE组合使用。 |
| WRITE_MODE = 1 << 1 | 写入权限，可单独使用，也可与READ_MODE组合使用。 |

### FileShare_PolicyErrorCode

```c
enum FileShare_PolicyErrorCode
```

**描述**

授予或激活权限策略失败的URI对应的错误码。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| PERSISTENCE_FORBIDDEN = 1 | URI禁止被持久化，例如远端URI不支持持久化。 |
| INVALID_MODE = 2 | 无效的模式，例如权限模式值不在支持范围内。 |
| INVALID_PATH = 3 | 无效路径。 |
| PERMISSION_NOT_PERSISTED = 4 | 权限没有被持久化。 |


## 函数说明

### OH_FileShare_PersistPermission()

```c
FileManagement_ErrCode OH_FileShare_PersistPermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum)
```

**描述**

对所选择的多个文件或目录URI持久化授权。完成持久化授权后，可调用OH_FileShare_ActivatePermission()激活权限。

**需要权限：** ohos.permission.FILE_ACCESS_PERSIST

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const FileShare_PolicyInfo](capi-fileshare-fileshare-policyinfo.md) *policies | 指向FileShare_PolicyInfo实例数组的指针，表示需要持久化授权的文件或目录URI策略信息。 |
| unsigned int policyNum | FileShare_PolicyInfo实例数组的元素个数，取值范围为[1, 500]。 |
| [FileShare_PolicyErrorResult](capi-fileshare-fileshare-policyerrorresult.md) **result | 输出参数，指向FileShare_PolicyErrorResult数组指针。请使用OH_FileShare_ReleasePolicyErrorResult()进行资源释放。 |
| unsigned int *resultNum | 输出参数，表示FileShare_PolicyErrorResult数组的元素个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode) | 返回FileManagement模块错误码[FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode)。<br>         ERR_INVALID_PARAMETER 401 - 输入参数无效。可能的原因有：<br>             1. 参数policies或参数result或参数resultNum为空指针；<br>             2. 参数policyNum值为0或者超过最大长度(500)；<br>             3. 参数policies中携带的uri为空或者length为0或者uri的长度与length不一致。<br>         ERR_DEVICE_NOT_SUPPORTED 801 - 当前设备类型不支持此接口。<br>         ERR_PERMISSION_ERROR 201 - 接口权限校验失败。<br>         ERR_ENOMEM 13900011 - 分配或者拷贝内存失败。<br>         ERR_EPERM 13900001 - 操作不被允许。<br>         ERR_OK 0 - 接口调用成功。 |

### OH_FileShare_RevokePermission()

```c
FileManagement_ErrCode OH_FileShare_RevokePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum)
```

**描述**

对所选择的多个文件或目录URI取消持久化授权。调用此接口前，需要先完成持久化授权。

**需要权限：** ohos.permission.FILE_ACCESS_PERSIST

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const FileShare_PolicyInfo](capi-fileshare-fileshare-policyinfo.md) *policies | 指向FileShare_PolicyInfo实例数组的指针，表示需要取消持久化授权的文件或目录URI策略信息。 |
| unsigned int policyNum | FileShare_PolicyInfo实例数组的元素个数，取值范围为[1, 500]。 |
| [FileShare_PolicyErrorResult](capi-fileshare-fileshare-policyerrorresult.md) **result | 输出参数，指向FileShare_PolicyErrorResult数组指针。请使用OH_FileShare_ReleasePolicyErrorResult()进行资源释放。 |
| unsigned int *resultNum | 输出参数，表示FileShare_PolicyErrorResult数组的元素个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode) | 返回FileManagement模块错误码[FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode)。<br>         ERR_INVALID_PARAMETER 401 - 输入参数无效。可能的原因有：<br>             1. 参数policies或参数result或参数resultNum为空指针；<br>             2. 参数policyNum值为0或者超过最大长度(500)；<br>             3. 参数policies中携带的uri为空或者length为0或者uri的长度与length不一致。<br>         ERR_DEVICE_NOT_SUPPORTED 801 - 当前设备类型不支持此接口。<br>         ERR_PERMISSION_ERROR 201 - 接口权限校验失败。<br>         ERR_ENOMEM 13900011 - 分配或者拷贝内存失败。<br>         ERR_EPERM 13900001 - 操作不被允许。<br>         ERR_OK 0 - 接口调用成功。 |

### OH_FileShare_ActivatePermission()

```c
FileManagement_ErrCode OH_FileShare_ActivatePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum)
```

**描述**

激活多个已经持久化授权的文件或目录。调用此接口前，需要先调用[OH_FileShare_PersistPermission](#oh_fileshare_persistpermission)完成持久化授权，激活后权限生效。

**需要权限：** ohos.permission.FILE_ACCESS_PERSIST

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const FileShare_PolicyInfo](capi-fileshare-fileshare-policyinfo.md) *policies | 指向FileShare_PolicyInfo实例数组的指针，表示需要激活权限的文件或目录URI策略信息。 |
| unsigned int policyNum | FileShare_PolicyInfo实例数组的元素个数，取值范围为[1, 500]。 |
| [FileShare_PolicyErrorResult](capi-fileshare-fileshare-policyerrorresult.md) **result | 输出参数，指向FileShare_PolicyErrorResult数组指针。请使用OH_FileShare_ReleasePolicyErrorResult()进行资源释放。 |
| unsigned int *resultNum | 输出参数，表示FileShare_PolicyErrorResult数组的元素个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode) | 返回FileManagement模块错误码[FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode)。<br>         ERR_INVALID_PARAMETER 401 - 输入参数无效。可能的原因有：<br>             1. 参数policies或参数result或参数resultNum为空指针；<br>             2. 参数policyNum值为0或者超过最大长度(500)；<br>             3. 参数policies中携带的uri为空或者length为0或者uri的长度与length不一致。<br>         ERR_DEVICE_NOT_SUPPORTED 801 - 当前设备类型不支持此接口。<br>         ERR_PERMISSION_ERROR 201 - 接口权限校验失败。<br>         ERR_ENOMEM 13900011 - 分配或者拷贝内存失败。<br>         ERR_EPERM 13900001 - 操作不被允许。<br>         ERR_OK 0 - 接口调用成功。 |

### OH_FileShare_DeactivatePermission()

```c
FileManagement_ErrCode OH_FileShare_DeactivatePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, FileShare_PolicyErrorResult **result, unsigned int *resultNum)
```

**描述**

取消激活持久化授权过的多个文件或目录。调用此接口前，需要先调用[OH_FileShare_ActivatePermission](#oh_fileshare_activatepermission)激活权限。取消激活后，持久化授权仍保留。

**需要权限：** ohos.permission.FILE_ACCESS_PERSIST

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const FileShare_PolicyInfo](capi-fileshare-fileshare-policyinfo.md) *policies | 指向FileShare_PolicyInfo实例数组的指针，表示需要取消激活权限的文件或目录URI策略信息。 |
| unsigned int policyNum | FileShare_PolicyInfo实例数组的元素个数，取值范围为[1, 500]。 |
| [FileShare_PolicyErrorResult](capi-fileshare-fileshare-policyerrorresult.md) **result | 输出参数，指向FileShare_PolicyErrorResult数组指针。请使用OH_FileShare_ReleasePolicyErrorResult()进行资源释放。 |
| unsigned int *resultNum | 输出参数，表示FileShare_PolicyErrorResult数组的元素个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode) | 返回FileManagement模块错误码[FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode)。<br>         ERR_INVALID_PARAMETER 401 - 输入参数无效。可能的原因有：<br>             1. 参数policies或参数result或参数resultNum为空指针；<br>             2. 参数policyNum值为0或者超过最大长度(500)；<br>             3. 参数policies中携带的uri为空或者length为0或者uri的长度与length不一致。<br>         ERR_DEVICE_NOT_SUPPORTED 801 - 当前设备类型不支持此接口。<br>         ERR_PERMISSION_ERROR 201 - 接口权限校验失败。<br>         ERR_ENOMEM 13900011 - 分配或者拷贝内存失败。<br>         ERR_EPERM 13900001 - 操作不被允许。<br>         ERR_OK 0 - 接口调用成功。 |

### OH_FileShare_CheckPersistentPermission()

```c
FileManagement_ErrCode OH_FileShare_CheckPersistentPermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, bool **result, unsigned int *resultNum)
```

**描述**

校验所选择的多个文件或目录URI的持久化授权。可在激活权限前调用该接口，确认目标URI是否已经完成持久化授权。

**需要权限：** ohos.permission.FILE_ACCESS_PERSIST

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const FileShare_PolicyInfo](capi-fileshare-fileshare-policyinfo.md) *policies | 指向FileShare_PolicyInfo实例数组的指针，表示需要校验持久化授权的文件或目录URI策略信息。 |
| unsigned int policyNum | FileShare_PolicyInfo实例数组的元素个数，取值范围为[1, 500]。 |
| bool **result | 输出参数，指向授权校验结果数组。数组元素与policies数组元素一一对应，true表示有持久化授权；false表示不具有持久化授权。需要使用standard library标准库的free()方法释放申请的资源。 |
| unsigned int *resultNum | 输出参数，表示校验结果数组的元素个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode) | 返回FileManagement模块错误码[FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode)。<br>         ERR_INVALID_PARAMETER 401 - 输入参数无效。可能的原因有：<br>             1. 参数policies或参数result或参数resultNum为空指针；<br>             2. 参数policyNum值为0或者超过最大长度(500)；<br>             3. 参数policies中携带的uri为空或者length为0或者uri的长度与length不一致。<br>         ERR_DEVICE_NOT_SUPPORTED 801 - 当前设备类型不支持此接口。<br>         ERR_PERMISSION_ERROR 201 - 接口权限校验失败。<br>         ERR_ENOMEM 13900011 - 分配或者拷贝内存失败。<br>         ERR_EPERM 13900001 - 操作不被允许。可能的原因为policies中携带的所有uri都不符合规范或者uri转换出来的路径不存在。<br>         ERR_OK 0 - 接口调用成功。 |

### OH_FileShare_ReleasePolicyErrorResult()

```c
void OH_FileShare_ReleasePolicyErrorResult(FileShare_PolicyErrorResult *errorResult, unsigned int resultNum)
```

**描述**

释放FileShare_PolicyErrorResult指针指向的内存资源。该资源由OH_FileShare_PersistPermission、OH_FileShare_RevokePermission、OH_FileShare_ActivatePermission和OH_FileShare_DeactivatePermission通过result输出。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [FileShare_PolicyErrorResult](capi-fileshare-fileshare-policyerrorresult.md) *errorResult | 指向FileShare_PolicyErrorResult实例数组的指针。 |
| unsigned int resultNum | FileShare_PolicyErrorResult实例数组的元素个数。 |
