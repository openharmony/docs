# oh_file_uri.h
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @rainlost-->
<!--Designer: @rainlost-->
<!--Tester: @liuhonggang123-->
<!--Adviser: @jinqiuheng-->

## 概述

提供URI和路径之间的相互转换、目录URI获取以及URI格式校验的方法，适用于文件分享场景中的URI转换和校验。

**引用文件：** <filemanagement/file_uri/oh_file_uri.h>

**库：** libohfileuri.so

**系统能力：** SystemCapability.FileManagement.AppFileService

**起始版本：** 12

**相关模块：** [fileUri](capi-fileuri.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [FileManagement_ErrCode OH_FileUri_GetUriFromPath(const char *path, unsigned int length, char **result)](#oh_fileuri_geturifrompath) | 通过传入的路径生成应用自己的URI；<br> 将路径转URI时，路径中的中文及非数字字母的特殊字符将会被百分号编码，拼接在URI中。 |
| [FileManagement_ErrCode OH_FileUri_GetPathFromUri(const char *uri, unsigned int length, char **result)](#oh_fileuri_getpathfromuri) | 将URI转换成对应的沙箱路径。<br> 1、URI转路径过程中会将URI中存在的百分号编码字符进行解码后拼接在原处，非系统接口生成的URI中可能存在不符合编码规范的字符，导致字符串无法正常拼接。2、转换处理为系统约定的字符串替换规则（规则随系统演进可能会发生变化），转换过程中不进行路径校验操作，无法保证转换结果一定可以访问。 |
| [FileManagement_ErrCode OH_FileUri_GetFullDirectoryUri(const char *uri, unsigned int length, char **result)](#oh_fileuri_getfulldirectoryuri) | 获取所在路径URI。URI指向文件则返回所在路径的URI，URI指向目录则不处理直接返回原串。<br> 如果URI指向的文件不存在，或无法获取文件属性，则返回空串。 |
| [bool OH_FileUri_IsValidUri(const char *uri, unsigned int length)](#oh_fileuri_isvaliduri) | 判断传入的URI格式是否正确。仅校验URI是否满足系统定义的格式规范，不校验URI的有效性。 |
| [FileManagement_ErrCode OH_FileUri_GetFileName(const char *uri, unsigned int length, char **result)](#oh_fileuri_getfilename) | 通过传入的URI获取文件名称。如果文件名中存在百分号编码字符，将会被解码处理后拼接在原处。 |

## 函数说明

### OH_FileUri_GetUriFromPath()

```c
FileManagement_ErrCode OH_FileUri_GetUriFromPath(const char *path, unsigned int length, char **result)
```

**描述**

通过传入的路径生成应用自己的URI；<br> 将路径转URI时，路径中的中文及非数字字母的特殊字符将会被百分号编码，拼接在URI中。

**系统能力：** SystemCapability.FileManagement.AppFileService

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *path | 表示要转换的路径。 |
| unsigned int length | 表示要转换路径字符串的字节长度，需与path实际长度一致。 |
| char **result | 输出参数，表示转换后的URI，需要使用standard library标准库的free()方法释放申请的资源。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode) | 返回特定的错误码值，详细信息可以查看[FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode)。<br>         ERR_INVALID_PARAMETER  401 - 输入参数无效。可能的原因：<br>                  1. 参数path为空指针；<br>                  2. 参数result为空指针；<br>                  3. 输入的path长度与length不一致。<br>         ERR_UNKNOWN 13900042 - 未知错误。转换后的URI长度为0会返回此错误。<br>         ERR_ENOMEM 13900011 - 分配或者拷贝内存失败。<br>         ERR_OK 0 - 接口调用成功。 |

### OH_FileUri_GetPathFromUri()

```c
FileManagement_ErrCode OH_FileUri_GetPathFromUri(const char *uri, unsigned int length, char **result)
```

**描述**

将URI转换成对应的沙箱路径。<br> 1、URI转路径过程中会将URI中存在的百分号编码字符进行解码后拼接在原处，非系统接口生成的URI中可能存在不符合编码规范的字符，导致字符串无法正常拼接。2、转换处理为系统约定的字符串替换规则（规则随系统演进可能会发生变化），转换过程中不进行路径校验操作，无法保证转换结果一定可以访问。

**系统能力：** SystemCapability.FileManagement.AppFileService

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *uri | 表示要转换的URI，需符合系统URI格式规范。 |
| unsigned int length | 表示要转换URI字符串的字节长度，需与uri实际长度一致。 |
| char **result | 输出参数，表示转换后的路径。需要使用standard library标准库的free()方法释放申请的资源。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode) | 返回特定的错误码值，详细信息可以查看[FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode)。<br>         ERR_INVALID_PARAMETER  401 - 输入参数无效。可能的原因：<br>                  1. 参数uri为空指针；<br>                  2. 参数result为空指针；<br>                  3. 输入的uri长度与length不一致。<br>         ERR_UNKNOWN 13900042 - 未知错误。转换后的路径path长度为0会返回此错误。<br>         ERR_ENOMEM 13900011 - 分配或者拷贝内存失败。<br>         ERR_OK 0 - 接口调用成功。 |

### OH_FileUri_GetFullDirectoryUri()

```c
FileManagement_ErrCode OH_FileUri_GetFullDirectoryUri(const char *uri, unsigned int length, char **result)
```

**描述**

获取所在路径URI。URI指向文件则返回所在路径的URI，URI指向目录则不处理直接返回原串。<br> 如果URI指向的文件不存在，或无法获取文件属性，则返回空串。

**系统能力：** SystemCapability.FileManagement.AppFileService

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *uri | 表示要获取目录的原始URI。 |
| unsigned int length | 表示原始URI字符串的字节长度，需与uri实际长度一致。 |
| char **result | 输出参数，表示获取到的目录URI，需要使用standard library标准库的free()方法释放申请的资源。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode) | 返回特定的错误码值，详细信息可以查看[FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode)。<br>         ERR_INVALID_PARAMETER  401 - 输入参数无效。可能的原因：<br>                  1. 参数uri为空指针；<br>                  2. 参数result为空指针；<br>                  3. 输入的uri长度与length不一致。<br>         ERR_ENOMEM 13900011 - 分配或者拷贝内存失败。<br>         ERR_ENOENT 13900002 - 没有该文件或目录。<br>         ERR_UNKNOWN 13900042 - 未知错误。获取到的目录URI长度为0会返回此错误。<br>         ERR_OK 0 - 接口调用成功。 |

### OH_FileUri_IsValidUri()

```c
bool OH_FileUri_IsValidUri(const char *uri, unsigned int length)
```

**描述**

判断传入的URI格式是否正确。仅校验URI是否满足系统定义的格式规范，不校验URI的有效性。

**系统能力：** SystemCapability.FileManagement.AppFileService

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *uri | 表示需要校验的URI。 |
| unsigned int length | 表示需要校验URI字符串的字节长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | true表示传入URI是有效的URI；false表示传入的URI是无效的URI。 |

### OH_FileUri_GetFileName()

```c
FileManagement_ErrCode OH_FileUri_GetFileName(const char *uri, unsigned int length, char **result)
```

**描述**

通过传入的URI获取文件名称。如果文件名中存在百分号编码字符，将会被解码处理后拼接在原处。

**系统能力：** SystemCapability.FileManagement.AppFileService

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *uri | 传入的URI，需符合系统URI格式规范。 |
| unsigned int length | 表示传入URI字符串的字节长度，需与uri实际长度一致。 |
| char **result | 输出参数，表示转换后的名称。需要使用standard library标准库的free()方法释放申请的资源。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode) | 返回特定的错误码值，详细信息可以查看[FileManagement_ErrCode](capi-error-code-h.md#filemanagement_errcode)。<br>         ERR_INVALID_PARAMETER  401 - 输入参数无效。可能的原因：<br>                  1. 参数uri为空指针；<br>                  2. 参数result为空指针；<br>                  3. 输入的uri长度与length不一致；<br>                  4. uri格式不正确。<br>         ERR_ENOMEM 13900011 - 分配或者拷贝内存失败。<br>         ERR_OK 0 - 接口调用成功。 |
