# raw_file_manager.h


## Overview

Provides functions for managing rawfile resources.

You can use the resource manager to open a rawfile and perform operations such as data search and reading.

**Since:**
8

**Related Modules:**

[Rawfile](rawfile.md)


## Summary


### Types

| Name | Description | 
| -------- | -------- |
| [NativeResourceManager](rawfile.md#nativeresourcemanager) | Implements the resource manager.  | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager) (napi_env env, napi_value jsResMgr) | Obtains the native resource manager based on JavaScipt resource manager.  | 
| [OH_ResourceManager_ReleaseNativeResourceManager](rawfile.md#oh_resourcemanager_releasenativeresourcemanager) ([NativeResourceManager](rawfile.md#nativeresourcemanager) \*resMgr) | Releases a native resource manager.  | 
| [OH_ResourceManager_OpenRawDir](rawfile.md#oh_resourcemanager_openrawdir) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*dirName) | Opens a rawfile directory.  | 
| [OH_ResourceManager_OpenRawFile](rawfile.md#oh_resourcemanager_openrawfile) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*fileName) | Opens a rawfile.  | 
