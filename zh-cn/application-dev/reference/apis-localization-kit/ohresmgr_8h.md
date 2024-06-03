# ohresmgr.h


## 概述

提供资源管理native侧获取资源的能力。

**系统能力：** SystemCapability.Global.ResourceManager

**库：** libohresmgr.so

**起始版本：** 12

**相关模块：**[Resourcemanager](resourcemanager.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [ResourceManager_ErrorCode](resourcemanager.md#resourcemanager_errorcode)[OH_ResourceManager_GetMediaBase64](resourcemanager.md#oh_resourcemanager_getmediabase64) (const NativeResourceManager \*mgr, uint32_t resId, char \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | 获取指定资源ID，指定屏幕密度对应的media资源的Base64码。  | 
| [ResourceManager_ErrorCode](resourcemanager.md#resourcemanager_errorcode)[OH_ResourceManager_GetMediaBase64ByName](resourcemanager.md#oh_resourcemanager_getmediabase64byname) (const NativeResourceManager \*mgr, const char \*resName, char \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | 获取指定资源名称，指定屏幕密度对应的media资源的Base64码。  | 
| [ResourceManager_ErrorCode](resourcemanager.md#resourcemanager_errorcode)[OH_ResourceManager_GetMedia](resourcemanager.md#oh_resourcemanager_getmedia) (const NativeResourceManager \*mgr, uint32_t resId, uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | 获取指定资源ID，指定屏幕密度对应的media资源的内容。  | 
| [ResourceManager_ErrorCode](resourcemanager.md#resourcemanager_errorcode)[OH_ResourceManager_GetMediaByName](resourcemanager.md#oh_resourcemanager_getmediabyname) (const NativeResourceManager \*mgr, const char \*resName, uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | 获取指定资源名称，指定屏幕密度对应的media资源的内容。  | 
| [ResourceManager_ErrorCode](resourcemanager.md#resourcemanager_errorcode)[OH_ResourceManager_GetDrawableDescriptor](resourcemanager.md#oh_resourcemanager_getdrawabledescriptor) (const NativeResourceManager \*mgr, uint32_t resId, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density=0, uint32_t type=0) | 获取指定资源Id，指定屏幕密度对应的图标资源的DrawableDescriptor。  | 
| [ResourceManager_ErrorCode](resourcemanager.md#resourcemanager_errorcode)[OH_ResourceManager_GetDrawableDescriptorByName](resourcemanager.md#oh_resourcemanager_getdrawabledescriptorbyname) (const NativeResourceManager \*mgr, const char \*resName, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density=0, uint32_t type=0) | 获取指定资源名称，指定屏幕密度对应的图标资源的DrawableDescriptor。  | 
