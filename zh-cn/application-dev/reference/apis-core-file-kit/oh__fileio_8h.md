# oh_fileio.h


## 概述

fileio模块接口定义，使用fileio提供的native接口，进行文件基础操作。

**库：** libohfileio.so

**系统能力：** SystemCapability.FileManagement.File.FileIO

**起始版本：** 12

**相关模块：**[FileIO](_file_i_o.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [FileIO_FileLocation](_file_i_o.md#fileio_filelocation) [FileIO_FileLocation](_file_i_o.md#fileio_filelocation) | 文件存储位置枚举值。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [FileIO_FileLocation](_file_i_o.md#fileio_filelocation) {<br/>LOCAL = 1,<br/>CLOUD = 2,<br/>LOCAL_AND_CLOUD = 3<br/>} | 文件存储位置枚举值。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileIO_GetFileLocation](_file_i_o.md#oh_fileio_getfilelocation) (char \*uri, int uriLength, [FileIO_FileLocation](_file_i_o.md#fileio_filelocation) \*location) | 获取文件存储位置。 | 
