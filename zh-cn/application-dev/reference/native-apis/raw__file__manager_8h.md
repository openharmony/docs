# raw_file_manager.h


## 概述

提供资源管理rawfile相关功能。

可以使用resource manager打开rawfile来进行后续相关操作，像搜索和读取等。

**起始版本：**

8

**相关模块：**

[Rawfile](rawfile.md)


## 汇总


### 类型定义

| 类型定义名称 | 描述 |
| -------- | -------- |
| [NativeResourceManager](rawfile.md#nativeresourcemanager) | 代表resource manager |


### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager) (napi_env env, napi_value jsResMgr) | 基于JavaScipt resource manager获取native resource manager |
| [OH_ResourceManager_ReleaseNativeResourceManager](rawfile.md#oh_resourcemanager_releasenativeresourcemanager) ([NativeResourceManager](rawfile.md#nativeresourcemanager) \*resMgr) | 释放native resource manager |
| [OH_ResourceManager_OpenRawDir](rawfile.md#oh_resourcemanager_openrawdir) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*dirName) | 打开rawfile目录 |
| [OH_ResourceManager_OpenRawFile](rawfile.md#oh_resourcemanager_openrawfile) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*fileName) | 打开rawfile文件 |
