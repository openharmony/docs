# oh_file_uri.h


## 概述

提供uri和路径path之间的相互转换，目录uri获取，以及URi的有效性校验的方法。

**库：** libohfileuri.so

**起始版本：** 12

**相关模块：**[Fileuri](fileuri.md)


## 汇总


### 函数

| 名称                                                                                                                                                                                                 | 描述                                              | 
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------|
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileUri_GetUriFromPath](fileuri.md#oh_fileuri_geturifrompath) (const char \*path, unsigned int length, char \*\*result)          | 将传入的路径path转换成uri。                               | 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileUri_GetPathFromUri](fileuri.md#oh_fileuri_getpathfromuri) (const char \*uri, unsigned int length, char \*\*result)           | 将传入的uri转换成路径path。                               | 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileUri_GetFullDirectoryUri](fileuri.md#oh_fileuri_getfulldirectoryuri) (const char \*uri, unsigned int length, char \*\*result) | 获取uri所在目录的uri，如果是文件uri则获取父目录的uri，如果是目录uri则返回本身。 | 
| bool [OH_FileUri_IsValidUri](fileuri.md#oh_fileuri_isvaliduri) (const char \*uri, unsigned int length)                                                                                             | 校验传入的uri是否有效。                                   | 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileUri_GetFileName](fileuri.md#oh_fileuri_getfilename) (const char \*uri, unsigned int length, char \*\*result)                 | 获取传入uri的文件名称。                                   | 
