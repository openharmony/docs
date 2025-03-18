# oh_file_uri.h


## 概述

FileUri提供了关于文件uri的基本操作，将uri转换成对应的沙箱路径path、将应用沙箱路径path转换成对应应用的uri、获取uri所在目录路径的uri等接口能力，方便应用对文件分享业务中uri的访问。

**库：** libohfileuri.so

**起始版本：** 12

**相关模块：**[Fileuri](fileuri.md)


## 汇总


### 函数

| 名称| 描述| 
|---------------|--------------|
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileUri_GetUriFromPath](fileuri.md#oh_fileuri_geturifrompath) (const char \*path, unsigned int length, char \*\*result) | 通过传入的路径path生成应用自己的uri；将path转uri时，路径中的中文及非数字字母的特殊字符将会被编译成对应的ASCII码，拼接在uri中。 | 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileUri_GetPathFromUri](fileuri.md#oh_fileuri_getpathfromuri) (const char \*uri, unsigned int length, char \*\*result) | 将uri转换成对应的沙箱路径path。 1、uri转path过程中会将uri中存在的ASCII码进行解码后拼接在原处，非系统接口生成的uri中可能存在ASCII码解析范围之外的字符，导致字符串无法正常拼接；2、转换处理为系统约定的字符串替换规则（规则随系统演进可能会发生变化），转换过程中不进行路径校验操作，无法保证转换结果的一定可以访问。 | 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileUri_GetFullDirectoryUri](fileuri.md#oh_fileuri_getfulldirectoryuri) (const char \*uri, unsigned int length, char \*\*result) | 获取所在路径uri。uri指向文件则返回所在路径的uri，uri指向目录则不处理直接返回原串；uri指向的文件不存在或属性获取失败则返回空串。 | 
| bool [OH_FileUri_IsValidUri](fileuri.md#oh_fileuri_isvaliduri) (const char \*uri, unsigned int length)  | 判断传入的uri的格式是否正确。仅校验uri是否满足系统定义的格式规范，不校验uri的有效性。| 
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_FileUri_GetFileName](fileuri.md#oh_fileuri_getfilename) (const char \*uri, unsigned int length, char \*\*result) | 通过传入的uri获取到对应的文件名称。（如果文件名中存在ASCII码将会被解码处理后拼接在原处）。| 
