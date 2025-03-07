# raw_file.h


## 概述

提供rawfile文件相关功能，功能包括搜索、读取和关闭。

**起始版本：** 8

**相关模块：**[Rawfile](rawfile.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[RawFileDescriptor](_raw_file_descriptor.md) | 提供rawfile文件描述符信息。  | 
| struct&nbsp;&nbsp;[RawFileDescriptor64](_raw_file_descriptor64.md) | 提供较大rawfile文件描述符信息。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [RawFile](rawfile.md#rawfile) [RawFile](rawfile.md#rawfile) | 提供对rawfile的访问功能。  | 
| typedef struct [RawFile64](rawfile.md#rawfile64) [RawFile64](rawfile.md#rawfile64) | 提供对较大rawfile的访问功能。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int [OH_ResourceManager_ReadRawFile](rawfile.md#oh_resourcemanager_readrawfile) (const [RawFile](rawfile.md#rawfile) \*rawFile, void \*buf, size_t length) | 读取rawfile内容，从当前位置读取指定长度的数据。  | 
| int [OH_ResourceManager_SeekRawFile](rawfile.md#oh_resourcemanager_seekrawfile) (const [RawFile](rawfile.md#rawfile) \*rawFile, long offset, int whence) | 基于指定的偏移量，在rawfile文件内搜索读写数据的位置。  | 
| long [OH_ResourceManager_GetRawFileSize](rawfile.md#oh_resourcemanager_getrawfilesize) ([RawFile](rawfile.md#rawfile) \*rawFile) | 获取rawfile长度，单位为long。  | 
| long [OH_ResourceManager_GetRawFileRemainingLength](rawfile.md#oh_resourcemanager_getrawfileremaininglength) (const [RawFile](rawfile.md#rawfile) \*rawFile) | 获取rawfile的剩余长度，单位为long。  | 
| void [OH_ResourceManager_CloseRawFile](rawfile.md#oh_resourcemanager_closerawfile) ([RawFile](rawfile.md#rawfile) \*rawFile) | 关闭已打开的[RawFile](rawfile.md#rawfile) 以及释放所有相关联的资源。  | 
| long [OH_ResourceManager_GetRawFileOffset](rawfile.md#oh_resourcemanager_getrawfileoffset) (const [RawFile](rawfile.md#rawfile) \*rawFile) | 获取rawfile当前的偏移量，单位为long。  | 
| bool [OH_ResourceManager_GetRawFileDescriptor](rawfile.md#oh_resourcemanager_getrawfiledescriptor) (const [RawFile](rawfile.md#rawfile) \*rawFile, [RawFileDescriptor](_raw_file_descriptor.md) &amp;descriptor) | 基于偏移量(单位为long)和文件长度(单位为long)打开rawfile，并获取rawfile文件描述符。  | 
| bool [OH_ResourceManager_ReleaseRawFileDescriptor](rawfile.md#oh_resourcemanager_releaserawfiledescriptor) (const [RawFileDescriptor](_raw_file_descriptor.md) &amp;descriptor) | 关闭rawfile文件描述符。  | 
| int64_t [OH_ResourceManager_ReadRawFile64](rawfile.md#oh_resourcemanager_readrawfile64) (const [RawFile64](rawfile.md#rawfile64) \*rawFile, void \*buf, int64_t length) | 读取较大的rawfile文件内容，从当前位置读取指定长度的数据。  | 
| int [OH_ResourceManager_SeekRawFile64](rawfile.md#oh_resourcemanager_seekrawfile64) (const [RawFile64](rawfile.md#rawfile64) \*rawFile, int64_t offset, int whence) | 基于指定的偏移量，在较大的rawfile文件内搜索读写数据的位置。  | 
| int64_t [OH_ResourceManager_GetRawFileSize64](rawfile.md#oh_resourcemanager_getrawfilesize64) ([RawFile64](rawfile.md#rawfile64) \*rawFile) | 获取较大rawfile文件的长度，单位为int64_t。  | 
| int64_t [OH_ResourceManager_GetRawFileRemainingLength64](rawfile.md#oh_resourcemanager_getrawfileremaininglength64) (const [RawFile64](rawfile.md#rawfile64) \*rawFile) | 获取较大rawfile的剩余长度，单位为int64_t。  | 
| void [OH_ResourceManager_CloseRawFile64](rawfile.md#oh_resourcemanager_closerawfile64) ([RawFile64](rawfile.md#rawfile64) \*rawFile) | 关闭已打开的[RawFile64](rawfile.md#rawfile64) 以及释放所有相关联的资源。  | 
| int64_t [OH_ResourceManager_GetRawFileOffset64](rawfile.md#oh_resourcemanager_getrawfileoffset64) (const [RawFile64](rawfile.md#rawfile64) \*rawFile) | 获取较大rawfile文件的偏移量，单位为int64_t。  | 
| bool [OH_ResourceManager_GetRawFileDescriptor64](rawfile.md#oh_resourcemanager_getrawfiledescriptor64) (const [RawFile64](rawfile.md#rawfile64) \*rawFile, [RawFileDescriptor64](_raw_file_descriptor64.md) \*descriptor) | 基于偏移量(单位为int64_t)和文件长度(单位为int64_t)打开较大的rawfile，并获取文件描述符。  | 
| bool [OH_ResourceManager_ReleaseRawFileDescriptor64](rawfile.md#oh_resourcemanager_releaserawfiledescriptor64) (const [RawFileDescriptor64](_raw_file_descriptor64.md) \*descriptor) | 关闭rawfile文件描述符。  | 
