# oh_environment.h

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wangke25; @gsl_1234; @wuchengjun5-->
<!--Designer: @gsl_1234; @wangke25-->
<!--Tester: @liuhonggang123; @yue-ye2; @juxiaopang-->
<!--Adviser: @foryourself-->

## 概述

environment模块接口定义，使用environment提供的native接口，获取公共文件根目录的沙箱路径。

**引用文件：** <filemanagement/environment/oh_environment.h>

**库：** libohenvironment.so

**系统能力：** SystemCapability.FileManagement.File.Environment.FolderObtain

**起始版本：** 12

**相关模块：** [Environment](capi-environment.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [FileManagement_ErrCode OH_Environment_GetUserDownloadDir(char **result)](#oh_environment_getuserdownloaddir) | 获取Download根目录沙箱路径。 |
| [FileManagement_ErrCode OH_Environment_GetUserDesktopDir(char **result)](#oh_environment_getuserdesktopdir) | 获取Desktop根目录沙箱路径。 |
| [FileManagement_ErrCode OH_Environment_GetUserDocumentDir(char **result)](#oh_environment_getuserdocumentdir) | 获取Document根目录沙箱路径。 |

## 函数说明

### OH_Environment_GetUserDownloadDir()

```
FileManagement_ErrCode OH_Environment_GetUserDownloadDir(char **result)
```

**描述**

获取Download根目录沙箱路径。

**需要权限：** ohos.permission.READ_WRITE_DOWNLOAD_DIRECTORY。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| char **result | Download根目录路径指针。请引用头文件malloc.h并使用free()进行资源释放。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode) | 返回FileManagement模块错误码[FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode)。 |

### OH_Environment_GetUserDesktopDir()

```
FileManagement_ErrCode OH_Environment_GetUserDesktopDir(char **result)
```

**描述**

获取Desktop根目录沙箱路径。

**需要权限：** ohos.permission.READ_WRITE_DESKTOP_DIRECTORY。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| char **result | Desktop根目录路径指针。请引用头文件malloc.h并使用free()进行资源释放。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode) | 返回FileManagement模块错误码[FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode)。 |

### OH_Environment_GetUserDocumentDir()

```
FileManagement_ErrCode OH_Environment_GetUserDocumentDir(char **result)
```

**描述**

获取Document根目录沙箱路径。

**需要权限：** ohos.permission.READ_WRITE_DOCUMENTS_DIRECTORY

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| char **result | Document根目录路径指针。请引用头文件malloc.h并使用free()进行资源释放。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode) | 返回FileManagement模块错误码[FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode)。 |


