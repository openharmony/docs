# Environment


## 概述

提供获取公共文件根目录路径的能力。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [oh_environment.h](oh__environment_8h.md) | environment模块接口定义，使用environment提供的native接口，获取公共文件根目录的沙箱路径。  |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_Environment_GetUserDownloadDir](#oh_environment_getuserdownloaddir) (char \*\*result) | 获取Download根目录沙箱路径。只支持2in1设备 |
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_Environment_GetUserDesktopDir](#oh_environment_getuserdesktopdir) (char \*\*result) | 获取Desktop根目录沙箱路径。只支持2in1设备 |
| [FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode) [OH_Environment_GetUserDocumentDir](#oh_environment_getuserdocumentdir) (char \*\*result) | 获取Document根目录沙箱路径。只支持2in1设备 |


## 函数说明


### OH_Environment_GetUserDesktopDir()

```
FileManagement_ErrCode OH_Environment_GetUserDesktopDir (char ** result)
```
**描述**
获取Desktop根目录沙箱路径。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| result | Desktop根目录路径指针。请引用头文件malloc.h并使用free()进行资源释放。  |

**返回：**

返回FileManageMent模块错误码[FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode)。


### OH_Environment_GetUserDocumentDir()

```
FileManagement_ErrCode OH_Environment_GetUserDocumentDir (char ** result)
```
**描述**
获取Document根目录沙箱路径。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| result | Document根目录路径指针。请引用头文件malloc.h并使用free()进行资源释放。  |

**返回：**

返回FileManageMent模块错误码[FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode)。


### OH_Environment_GetUserDownloadDir()

```
FileManagement_ErrCode OH_Environment_GetUserDownloadDir (char ** result)
```
**描述**
获取Download根目录沙箱路径。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| result | Download根目录路径指针。请引用头文件malloc.h并使用free()进行资源释放。  |

**返回：**

返回FileManageMent模块错误码[FileManagement_ErrCode](_file_i_o.md#filemanagement_errcode)。
