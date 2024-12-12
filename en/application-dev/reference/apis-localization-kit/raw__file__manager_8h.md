# raw_file_manager.h


## Overview

Provides file management functions for the **rawfile** directory. You can use the **ResourceManager** to open a rawfile and perform operations such as data search and reading.

**System capability**: SystemCapability.Global.ResourceManager

**Library**: librawfile.z.so

**Since**: 8

**Related module**: [Rawfile] (rawfile.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [NativeResourceManager](rawfile.md#nativeresourcemanager)[NativeResourceManager](rawfile.md#nativeresourcemanager) | Represents the native **ResourceManager**. | 


### Function

| Name| Description| 
| -------- | -------- |
| [NativeResourceManager](rawfile.md#nativeresourcemanager) \* [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager) (napi_env env, napi_value jsResMgr) | Obtains the native **ResourceManager** based on the JS **ResourceManager** to implement rawfile-specific functions. | 
| void [OH_ResourceManager_ReleaseNativeResourceManager](rawfile.md#oh_resourcemanager_releasenativeresourcemanager) ([NativeResourceManager](rawfile.md#nativeresourcemanager) \*resMgr) | Releases the native **ResourceManager**. | 
| [RawDir](rawfile.md#rawdir) \* [OH_ResourceManager_OpenRawDir](rawfile.md#oh_resourcemanager_openrawdir) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*dirName) | Traverses all files in the **rawfile** directory. | 
| [RawFile](rawfile.md#rawfile) \* [OH_ResourceManager_OpenRawFile](rawfile.md#oh_resourcemanager_openrawfile) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*fileName) | Opens a rawfile and reads the data in it. | 
| [RawFile64](rawfile.md#rawfile64) \* [OH_ResourceManager_OpenRawFile64](rawfile.md#oh_resourcemanager_openrawfile64) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*fileName) | Opens a large rawfile and reads the data in it. | 
| bool [OH_ResourceManager_IsRawDir](rawfile.md#oh_resourcemanager_israwdir) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*path) | Checks whether a path is a subdirectory in the **rawfile** directory. | 
