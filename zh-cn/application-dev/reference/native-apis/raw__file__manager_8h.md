# raw_file_manager.h


## 概述

提供资源管理rawfile相关功能，可以使用ResourceManager打开rawfile进行后续相关操作，包括搜索和读取等。

**起始版本：** 8

**相关模块：**[Rawfile](rawfile.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [NativeResourceManager](rawfile.md#nativeresourcemanager) | 代表native侧的ResourceManager | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager) (napi_env env, napi_value jsResMgr) | 基于JavaScipt侧的ResourceManager获取native侧的ResourceManager，用来完成rawfile相关功能 | 
| [OH_ResourceManager_ReleaseNativeResourceManager](rawfile.md#oh_resourcemanager_releasenativeresourcemanager) ([NativeResourceManager](rawfile.md#nativeresourcemanager) \*resMgr) | 释放native侧ResourceManager | 
| [OH_ResourceManager_OpenRawDir](rawfile.md#oh_resourcemanager_openrawdir) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*dirName) | 打开rawfile目录，遍历对应目录下的rawfile文件 | 
| [OH_ResourceManager_OpenRawFile](rawfile.md#oh_resourcemanager_openrawfile) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*fileName) | 打开rawfile文件，读取文件数据 | 
| [OH_ResourceManager_OpenRawFile64](rawfile.md#oh_resourcemanager_openrawfile64) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*fileName) | 打开rawfile文件，读取文件数据<br/>**说明**：RawFile64是新增接口，新接口支持打开更大的rawfile文件，性能更优 | 
