# FileIO


## 概述

提供文件基础操作的能力。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [error_code.h](error__code_8h.md) | 提供文件管理模块的错误码定义。 | 
| [oh_fileio.h](oh__fileio_8h.md) | fileio模块接口定义，使用fileio提供的native接口，进行文件基础操作。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [FileManagement_ErrCode](#filemanagement_errcode-1) [FileManagement_ErrCode](#filemanagement_errcode) | 文件管理模块错误码。 | 
| typedef enum [FileIO_FileLocation](#fileio_filelocation-1) [FileIO_FileLocation](#fileio_filelocation) | 文件存储位置枚举值。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [FileManagement_ErrCode](#filemanagement_errcode-1) {<br/>ERR_OK = 0,<br/>ERR_PERMISSION_ERROR = 201,<br/>ERR_INVALID_PARAMETER = 401,<br/>ERR_DEVICE_NOT_SUPPORTED = 801,<br/>ERR_EPERM = 13900001,<br/>ERR_ENOENT = 13900002,<br/>ERR_ENOMEM = 13900011,<br/>ERR_UNKNOWN = 13900042<br/>} | 文件管理模块错误码。 | 
| [FileIO_FileLocation](#fileio_filelocation-1) {<br/>LOCAL = 1,<br/>CLOUD = 2,<br/>LOCAL_AND_CLOUD = 3<br/>} | 文件存储位置枚举值。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [FileManagement_ErrCode](#filemanagement_errcode) [OH_FileIO_GetFileLocation](#oh_fileio_getfilelocation) (char \*uri, int uriLength, [FileIO_FileLocation](#fileio_filelocation) \*location) | 获取文件存储位置。 | 


## 类型定义说明


### FileIO_FileLocation

```
typedef enum FileIO_FileLocation FileIO_FileLocation
```

**描述**

文件存储位置枚举值。

**起始版本：** 12


### FileManagement_ErrCode

```
typedef enum FileManagement_ErrCode FileManagement_ErrCode
```

**描述**

文件管理模块错误码。

**起始版本：** 12


## 枚举类型说明


### FileIO_FileLocation

```
enum FileIO_FileLocation
```

**描述**

文件存储位置枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| LOCAL | 文件存储于本地。 | 
| CLOUD | 文件存储于云侧。 | 
| LOCAL_AND_CLOUD | 文件存储于本地及云侧。 | 


### FileManagement_ErrCode

```
enum FileManagement_ErrCode
```

**描述**

文件管理模块错误码。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ERR_OK | 接口调用成功。 | 
| ERR_PERMISSION_ERROR | 接口权限校验失败。 | 
| ERR_INVALID_PARAMETER | 无效入参。 | 
| ERR_DEVICE_NOT_SUPPORTED | 当前设备不支持此接口。 | 
| ERR_EPERM | 操作不被允许。 | 
| ERR_ENOENT | 不存在此文件或文件夹。 | 
| ERR_ENOMEM | 内存溢出。 | 
| ERR_UNKNOWN | 内部未知错误。 | 


## 函数说明


### OH_FileIO_GetFileLocation()

```
FileManagement_ErrCode OH_FileIO_GetFileLocation (char * uri, int uriLength, FileIO_FileLocation * location )
```

**描述**

获取文件存储位置。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| uri | 指向入参uri的指针。 | 
| uriLength | 入参uri字符串的长度。 | 
| location | 输出文件存储位置的指针。 | 

**返回：**

返回FileManageMent模块错误码[FileManagement_ErrCode](#filemanagement_errcode)。
