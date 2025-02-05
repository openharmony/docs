# raw_file_manager.h


## 概述

提供资源管理rawfile相关功能，可以使用ResourceManager打开rawfile进行后续相关操作，像搜索和读取等。

**起始版本：** 8

**相关模块：**[Rawfile](rawfile.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [NativeResourceManager](rawfile.md#nativeresourcemanager) [NativeResourceManager](rawfile.md#nativeresourcemanager) | 代表native侧的ResourceManager。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [NativeResourceManager](rawfile.md#nativeresourcemanager) \* [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager) (napi_env env, napi_value jsResMgr) | 基于JavaScipt侧的ResourceManager获取native侧的ResourceManager，用来完成rawfile相关功能。  | 
| void [OH_ResourceManager_ReleaseNativeResourceManager](rawfile.md#oh_resourcemanager_releasenativeresourcemanager) ([NativeResourceManager](rawfile.md#nativeresourcemanager) \*resMgr) | 释放native侧ResourceManager。  | 
| [RawDir](rawfile.md#rawdir) \* [OH_ResourceManager_OpenRawDir](rawfile.md#oh_resourcemanager_openrawdir) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*dirName) | 打开rawfile目录，打开后可以遍历对应目录下的rawfile文件。  | 
| [RawFile](rawfile.md#rawfile) \* [OH_ResourceManager_OpenRawFile](rawfile.md#oh_resourcemanager_openrawfile) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*fileName) | 打开rawfile文件，打开后可以读取它的数据。  | 
| [RawFile64](rawfile.md#rawfile64) \* [OH_ResourceManager_OpenRawFile64](rawfile.md#oh_resourcemanager_openrawfile64) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*fileName) | 打开较大的rawfile文件，打开后可以读取它的数据。  | 
| bool [OH_ResourceManager_IsRawDir](rawfile.md#oh_resourcemanager_israwdir) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*path) | 判断路径是否是rawfile下的目录。  | 