# raw_file.h


## 概述

提供rawfile文件相关功能。

功能包括搜索、读取和关闭rawfile文件。

**起始版本：**

8

**相关模块：**

[Rawfile](rawfile.md)


## 汇总


### 结构体

| 结构体名称 | 描述 |
| -------- | -------- |
| [RawFileDescriptor](_raw_file_descriptor.md) | 提供rawfile文件描述符信息 |


### 类型定义

| 类型定义名称 | 描述 |
| -------- | -------- |
| [RawFile](rawfile.md#rawfile) | 提供对rawfile的访问功能 |


### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_ResourceManager_ReadRawFile](rawfile.md#oh_resourcemanager_readrawfile) (const [RawFile](rawfile.md#rawfile) \*rawFile, void \*buf, size_t length) | 读取rawfile |
| [OH_ResourceManager_SeekRawFile](rawfile.md#oh_resourcemanager_seekrawfile) (const [RawFile](rawfile.md#rawfile) \*rawFile, long offset, int whence) | 基于指定的offset，在rawfile文件内搜索读写数据的位置 |
| [OH_ResourceManager_GetRawFileSize](rawfile.md#oh_resourcemanager_getrawfilesize) ([RawFile](rawfile.md#rawfile) \*rawFile) | 获取rawfile长度，单位为int32_t |
| [OH_ResourceManager_CloseRawFile](rawfile.md#oh_resourcemanager_closerawfile) ([RawFile](rawfile.md#rawfile) \*rawFile) | 关闭已打开的[RawFile](rawfile.md#rawfile) 以及释放所有相关联资源 |
| [OH_ResourceManager_GetRawFileOffset](rawfile.md#oh_resourcemanager_getrawfileoffset) (const [RawFile](rawfile.md#rawfile) \*rawFile) | 获取rawfile当前的offset，单位为int32_t |
| [OH_ResourceManager_GetRawFileDescriptor](rawfile.md#oh_resourcemanager_getrawfiledescriptor) (const [RawFile](rawfile.md#rawfile) \*rawFile, [RawFileDescriptor](_raw_file_descriptor.md) &amp;descriptor) | 基于offset(单位为int32_t)和文件长度打开rawfile，并获取rawfile文件描述符 |
| [OH_ResourceManager_ReleaseRawFileDescriptor](rawfile.md#oh_resourcemanager_releaserawfiledescriptor) (const [RawFileDescriptor](_raw_file_descriptor.md) &amp;descriptor) | 关闭rawfile文件描述符 |
