# Fileuri


## 概述

文件统一资源标识符（File Uniform Resource Identifier），支持fileuri与路径path的转换、有效性校验、以及指向的变换（指向的文件或路径）。

**系统能力**：SystemCapability.FileManagement.AppFileService

**起始版本**：12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [oh_file_uri.h](oh__file__uri_8h.md) | 提供uri和路径path之间的相互转换，目录uri获取，以及URi的有效性校验的方法。 | 


### 函数

| 名称                                                                                                                                                                                       | 描述                                              | 
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------|
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileUri_GetUriFromPath](#oh_fileuri_geturifrompath) (const char \*path, unsigned int length, char \*\*result)          | 将传入的路径path转换成uri。                               | 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileUri_GetPathFromUri](#oh_fileuri_getpathfromuri) (const char \*uri, unsigned int length, char \*\*result)           | 将传入的uri转换成路径path。                               | 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileUri_GetFullDirectoryUri](#oh_fileuri_getfulldirectoryuri) (const char \*uri, unsigned int length, char \*\*result) | 获取uri所在目录的uri，如果是文件uri则获取父目录的uri，如果是目录uri则返回本身。 | 
| bool [OH_FileUri_IsValidUri](#oh_fileuri_isvaliduri) (const char \*uri, unsigned int length)                                                                                             | 校验传入的uri是否有效。                                   | 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileUri_GetFileName](#oh_fileuri_getfilename) (const char \*uri, unsigned int length, char \*\*result)                 | 获取传入uri中的文件名称。                                  | 

## 函数说明


### OH_FileUri_GetFullDirectoryUri()

```
FileManagement_ErrCode OH_FileUri_GetFullDirectoryUri (const char * uri, unsigned int length, char ** result )
```

**描述**

获取uri所在目录的uri，如果是文件uri则获取父目录的uri，如果是目录uri则返回本身。

**系统能力**：SystemCapability.FileManagement.AppFileService

**起始版本**：12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| uri | 表示要获取目录的uri的原始uri。 | 
| length | 表示原始uri的字节长度。 | 
| result | 表示获取到的目录URi， 需要使用standard library标准库的free()方法释放申请的资源。 | 

**返回**：

返回特定的错误码值，详细信息可以查看[FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode)。


### OH_FileUri_GetPathFromUri()

```
FileManagement_ErrCode OH_FileUri_GetPathFromUri (const char * uri, unsigned int length, char ** result )
```

**描述**

将传入的uri转换成路径path。

**系统能力**：SystemCapability.FileManagement.AppFileService

**起始版本**：12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| uri | 表示要转换的uri。 | 
| length | 表示要转换uri的字节长度。 | 
| result | 表示转换后的路径path. 需要使用standard library标准库的free()方法释放申请的资源。 | 

**返回**：

返回特定的错误码值，详细信息可以查看[FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode)。


### OH_FileUri_GetUriFromPath()

```
FileManagement_ErrCode OH_FileUri_GetUriFromPath (const char * path, unsigned int length, char ** result )
```

**描述**

将传入的路径path转换成uri。

**系统能力**：SystemCapability.FileManagement.AppFileService

**起始版本**：12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| path | 表示要转换的路径。 | 
| length | 表示要转换路径的字节长度。 | 
| result | 表示转换后的uri, 需要使用standard library标准库的free()方法释放申请的资源。 | 

**返回**：

返回特定的错误码值，详细信息可以查看[FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode)。


### OH_FileUri_IsValidUri()

```
bool OH_FileUri_IsValidUri (const char * uri, unsigned int length )
```

**描述**

校验传入的uri是否有效。

**系统能力**：SystemCapability.FileManagement.AppFileService

**起始版本**：12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| uri | 表示需要校验的uri。 | 
| length | 需要校验uri的字节长度。 | 

**返回**：

返回true表示传入uri是有效的uri；返回false表示传入的uri是无效的uri。

### OH_FileUri_GetFileName()

```
FileManagement_ErrCode OH_FileUri_GetFileName (const char * uri, unsigned int length, char ** result )
```

**描述**

获取传入的uri中的文件名称。

**系统能力**：SystemCapability.FileManagement.AppFileService

**起始版本**：13

**参数:**

| 名称 | 描述                                                   | 
| -------- |------------------------------------------------------|
| uri | 表示传入的uri。                                            | 
| length | 表示传入uri的字节长度。                                        | 
| result | 表示获取到的文件名称. 需要使用standard library标准库的free()方法释放申请的资源。 | 

**返回**：

返回特定的错误码值，详细信息可以查看[FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode)。