# oh_file_share.h
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @lvzhenjie; @hongjin-li_admin-->
<!--Designer: @chenxi0605; @JerryH1011-->
<!--Tester: @leiyuqian-->
<!--Adviser: @foryourself-->

## 概述

提供基于URI的文件及目录授予持久化权限、权限激活、权限查询等方法。

**引用文件：** <filemanagement/fileshare/oh_file_share.h>

**库：** libohfileshare.so

**系统能力：** SystemCapability.FileManagement.AppFileService.FolderAuthorization

**起始版本：** 12

**相关模块：** [fileShare](capi-fileshare.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [FileShare_PolicyErrorResult](capi-fileshare-fileshare-policyerrorresult.md) | FileShare_PolicyErrorResult | 授予或使能权限失败的URI策略结果。 |
| [FileShare_PolicyInfo](capi-fileshare-fileshare-policyinfo.md) | FileShare_PolicyInfo | 需要授予或使能权限URI的策略信息。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [FileShare_OperationMode](#fileshare_operationmode) | FileShare_OperationMode | URI操作模式枚举值。 |
| [FileShare_PolicyErrorCode](#fileshare_policyerrorcode) | FileShare_PolicyErrorCode | 授予或使能权限策略失败的URI对应的错误码枚举值。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [FileManagement_ErrCode OH_FileShare_PersistPermission(const FileShare_PolicyInfo *policies, unsigned int policyNum,FileShare_PolicyErrorResult **result, unsigned int *resultNum)](#oh_fileshare_persistpermission) | 对所选择的多个文件或目录URI持久化授权。 |
| [FileManagement_ErrCode OH_FileShare_RevokePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum,FileShare_PolicyErrorResult **result, unsigned int *resultNum)](#oh_fileshare_revokepermission) | 对所选择的多个文件或目录URI取消持久化授权。 |
| [FileManagement_ErrCode OH_FileShare_ActivatePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum,FileShare_PolicyErrorResult **result, unsigned int *resultNum)](#oh_fileshare_activatepermission) | 使能多个已经持久化授权的文件或目录。 |
| [FileManagement_ErrCode OH_FileShare_DeactivatePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum,FileShare_PolicyErrorResult **result, unsigned int *resultNum)](#oh_fileshare_deactivatepermission) | 取消使能持久化授权过的多个文件或目录。 |
| [FileManagement_ErrCode OH_FileShare_CheckPersistentPermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, bool **result, unsigned int *resultNum)](#oh_fileshare_checkpersistentpermission) | 校验所选择的多个文件或目录URI的持久化授权。 |
| [void OH_FileShare_ReleasePolicyErrorResult(FileShare_PolicyErrorResult *errorResult, unsigned int resultNum)](#oh_fileshare_releasepolicyerrorresult) | 释放FileShare_PolicyErrorResult指针指向的内存资源。 |

## 枚举类型说明

### FileShare_OperationMode

```
enum FileShare_OperationMode
```

**描述**

URI操作模式枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| READ_MODE = 1 << 0 | 读取权限。 |
| WRITE_MODE = 1 << 1 | 写入权限。 |

### FileShare_PolicyErrorCode

```
enum FileShare_PolicyErrorCode
```

**描述**

授予或使能权限策略失败的URI对应的错误码枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| PERSISTENCE_FORBIDDEN = 1 | URI禁止被持久化。 |
| INVALID_MODE = 2 | 无效的模式。 |
| INVALID_PATH = 3 | 无效路径。 |
| PERMISSION_NOT_PERSISTED = 4 | 权限没有被持久化。 |


## 函数说明

### OH_FileShare_PersistPermission()

```
FileManagement_ErrCode OH_FileShare_PersistPermission(const FileShare_PolicyInfo *policies, unsigned int policyNum,FileShare_PolicyErrorResult **result, unsigned int *resultNum)
```

**描述**

对所选择的多个文件或目录URI持久化授权。

**需要权限：** ohos.permission.FILE_ACCESS_PERSIST

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const FileShare_PolicyInfo](capi-fileshare-fileshare-policyinfo.md) *policies | 一个指向FileShare_PolicyInfo实例的指针。 |
| unsigned int policyNum | FileShare_PolicyInfo实例数组的大小。 |
| [FileShare_PolicyErrorResult](capi-fileshare-fileshare-policyerrorresult.md) **result | FileShare_PolicyErrorResult数组指针。请使用OH_FileShare_ReleasePolicyErrorResult()进行资源释放。 |
| unsigned int *resultNum | FileShare_PolicyErrorResult数组大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode) | 返回FileManagement模块错误码[FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode)。<br>         E_PARAMS 401 - 输入参数无效。可能的原因有：<br>             1. 参数policies或参数result或参数resultNum为空指针；<br>             2. 参数policyNum值为0或者超过最大长度(500)；<br>             3. 参数policies中携带的uri为空或者length为0或者uri的长度与length不一致。<br>         E_DEVICE_NOT_SUPPORT 801 - 当前设备类型不支持此接口。<br>         E_PERMISSION 201 - 接口权限校验失败。<br>         E_ENOMEM 13900011 - 分配或者拷贝内存失败。<br>         E_EPERM 13900001 - 操作不被允许。<br>         E_UNKNOWN_ERROR 13900042 - 内部未知错误，调用其它部件返回的除以上错误之外的其它错误。<br>         E_NO_ERROR 0 - 接口调用成功。 |

### OH_FileShare_RevokePermission()

```
FileManagement_ErrCode OH_FileShare_RevokePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum,FileShare_PolicyErrorResult **result, unsigned int *resultNum)
```

**描述**

对所选择的多个文件或目录URI取消持久化授权。

**需要权限：** ohos.permission.FILE_ACCESS_PERSIST

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const FileShare_PolicyInfo](capi-fileshare-fileshare-policyinfo.md) *policies | 一个指向FileShare_PolicyInfo实例的指针。 |
| unsigned int policyNum | FileShare_PolicyInfo实例数组的大小。 |
| [FileShare_PolicyErrorResult](capi-fileshare-fileshare-policyerrorresult.md) **result | FileShare_PolicyErrorResult数组指针。请使用OH_FileShare_ReleasePolicyErrorResult()进行资源释放。 |
| unsigned int *resultNum | FileShare_PolicyErrorResult数组大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode) | 返回FileManagement模块错误码[FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode)。<br>         E_PARAMS 401 - 输入参数无效。可能的原因有：1. 参数policies或参数result或参数resultNum为空指针；<br>             2. 参数policyNum值为0或者超过最大长度(500)；3. 参数policies中携带的uri为空或者length为0或者uri的长度与length不一致。<br>         E_DEVICE_NOT_SUPPORT 801 - 当前设备类型不支持此接口。<br>         E_PERMISSION 201 - 接口权限校验失败。<br>         E_ENOMEM 13900011 - 分配或者拷贝内存失败。<br>         E_EPERM 13900001 - 操作不被允许。<br>         E_UNKNOWN_ERROR 13900042 - 内部未知错误，调用其它部件返回的除以上错误之外的其它错误。<br>         E_NO_ERROR - 接口调用成功。 |

### OH_FileShare_ActivatePermission()

```
FileManagement_ErrCode OH_FileShare_ActivatePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum,FileShare_PolicyErrorResult **result, unsigned int *resultNum)
```

**描述**

使能多个已经持久化授权的文件或目录。

**需要权限：** ohos.permission.FILE_ACCESS_PERSIST

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const FileShare_PolicyInfo](capi-fileshare-fileshare-policyinfo.md) *policies | 一个指向FileShare_PolicyInfo实例的指针。 |
| unsigned int policyNum | FileShare_PolicyInfo实例数组的大小。 |
| [FileShare_PolicyErrorResult](capi-fileshare-fileshare-policyerrorresult.md) **result | FileShare_PolicyErrorResult数组指针。请使用OH_FileShare_ReleasePolicyErrorResult()进行资源释放。 |
| unsigned int *resultNum | FileShare_PolicyErrorResult数组大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode) | 返回FileManagement模块错误码[FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode)。<br>         E_PARAMS 401 - 输入参数无效。可能的原因有：<br>             1. 参数policies或参数result或参数resultNum为空指针；<br>             2. 参数policyNum值为0或者超过最大长度(500)；<br>             3. 参数policies中携带的uri为空或者length为0或者uri的长度与length不一致。<br>         E_DEVICE_NOT_SUPPORT 801 - 当前设备类型不支持此接口。<br>         E_PERMISSION 201 - 接口权限校验失败。<br>         E_ENOMEM 13900011 - 分配或者拷贝内存失败。<br>         E_EPERM 13900001 - 操作不被允许。<br>         E_UNKNOWN_ERROR 13900042 - 内部未知错误，调用其它部件返回的除以上错误之外的其它错误。<br>         E_NO_ERROR 0 - 接口调用成功。 |

### OH_FileShare_DeactivatePermission()

```
FileManagement_ErrCode OH_FileShare_DeactivatePermission(const FileShare_PolicyInfo *policies, unsigned int policyNum,FileShare_PolicyErrorResult **result, unsigned int *resultNum)
```

**描述**

取消使能持久化授权过的多个文件或目录。

**需要权限：** ohos.permission.FILE_ACCESS_PERSIST

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const FileShare_PolicyInfo](capi-fileshare-fileshare-policyinfo.md) *policies | 一个指向FileShare_PolicyInfo实例的指针。 |
| unsigned int policyNum | FileShare_PolicyInfo实例数组的大小。 |
| [FileShare_PolicyErrorResult](capi-fileshare-fileshare-policyerrorresult.md) **result | FileShare_PolicyErrorResult数组指针。请使用OH_FileShare_ReleasePolicyErrorResult()进行资源释放。 |
| unsigned int *resultNum | FileShare_PolicyErrorResult数组大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode) | 返回FileManagement模块错误码[FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode)。<br>         E_PARAMS 401 - 输入参数无效。可能的原因有：<br>             1. 参数policies或参数result或参数resultNum为空指针；<br>             2. 参数policyNum值为0或者超过最大长度(500)；<br>             3. 参数policies中携带的uri为空或者length为0或者uri的长度与length不一致。<br>         E_DEVICE_NOT_SUPPORT 801 - 当前设备类型不支持此接口。<br>         E_PERMISSION 201 - 接口权限校验失败。<br>          E_ENOMEM 13900011 - 分配或者拷贝内存失败。<br>         E_EPERM 13900001 - 操作不被允许。<br>         E_UNKNOWN_ERROR 13900042 - 内部未知错误，调用其它部件返回的除以上错误之外的其它错误。<br>         E_NO_ERROR - 接口调用成功。 |

### OH_FileShare_CheckPersistentPermission()

```
FileManagement_ErrCode OH_FileShare_CheckPersistentPermission(const FileShare_PolicyInfo *policies, unsigned int policyNum, bool **result, unsigned int *resultNum)
```

**描述**

校验所选择的多个文件或目录URI的持久化授权。

**需要权限：** ohos.permission.FILE_ACCESS_PERSIST

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const FileShare_PolicyInfo](capi-fileshare-fileshare-policyinfo.md) *policies | 一个指向FileShare_PolicyInfo实例的指针。 |
| unsigned int policyNum | FileShare_PolicyInfo实例数组的大小。 |
| bool **result | 授权校验结果指针。请引用头文件malloc.h并使用free()进行资源释放。 |
| unsigned int *resultNum | 校验结果数组的大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode) | 返回FileManagement模块错误码[FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode)。<br>         E_PARAMS 401 - 输入参数无效。可能的原因有：<br>             1. 参数policies或参数result或参数resultNum为空指针；<br>             2. 参数policyNum值为0或者超过最大长度(500)；<br>             3. 参数policies中携带的uri为空或者length为0或者uri的长度与length不一致。<br>         E_DEVICE_NOT_SUPPORT 801 - 当前设备类型不支持此接口。<br>         E_PERMISSION 201 - 接口权限校验失败。<br>         E_ENOMEM 13900011 - 分配或者拷贝内存失败。<br>         E_EPERM 13900001 - 操作不被允许。可能的原因为policies中携带的所有uri都不符合规范或者uri转换出来的路径不存在。<br>         E_UNKNOWN_ERROR 13900042 - 内部未知错误，调用其它部件返回的除以上错误之外的其它错误。<br>         E_NO_ERROR 0 - 接口调用成功。 |

### OH_FileShare_ReleasePolicyErrorResult()

```
void OH_FileShare_ReleasePolicyErrorResult(FileShare_PolicyErrorResult *errorResult, unsigned int resultNum)
```

**描述**

释放FileShare_PolicyErrorResult指针指向的内存资源。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [FileShare_PolicyErrorResult](capi-fileshare-fileshare-policyerrorresult.md) *errorResult | 一个指向FileShare_PolicyErrorResult实例的指针。 |
| unsigned int resultNum | FileShare_PolicyErrorResult实例数组的大小。 |


