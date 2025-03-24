# oh_environment.h


## 概述

environment模块接口定义，使用environment提供的native接口，获取公共文件根目录的沙箱路径。

**库：** libohenvironment.so

**系统能力：** SystemCapability.FileManagement.File.Environment.FolderObtain

**起始版本：** 12

**相关模块：**[Environment](_environment.md)


## 汇总


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_Environment_GetUserDownloadDir](_environment.md#oh_environment_getuserdownloaddir) (char \*\*result) | 获取Download根目录沙箱路径。只支持2in1设备。  |
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_Environment_GetUserDesktopDir](_environment.md#oh_environment_getuserdesktopdir) (char \*\*result) | 获取Desktop根目录沙箱路径。只支持2in1设备。  |
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_Environment_GetUserDocumentDir](_environment.md#oh_environment_getuserdocumentdir) (char \*\*result) | 获取Document根目录沙箱路径。只支持2in1设备。 |
