# ohresmgr.h


## Overview

Provides native APIs for obtaining resources.

**System capability**: SystemCapability.Global.ResourceManager

**Library**: libohresmgr.so

**Since**: 12

**Related module**: [Resourcemanager](resourcemanager.md)


## Summary


### Callback

| Name| Description| 
| -------- | -------- |
| [ResourceManager_ErrorCode](resourcemanager.md#resourcemanager_errorcode)[OH_ResourceManager_GetMediaBase64](resourcemanager.md#oh_resourcemanager_getmediabase64) (const NativeResourceManager \*mgr, uint32_t resId, char \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | Obtains the Base64 code of the media resource with the specified screen density based on the specified resource ID. | 
| [ResourceManager_ErrorCode](resourcemanager.md#resourcemanager_errorcode)[OH_ResourceManager_GetMediaBase64ByName](resourcemanager.md#oh_resourcemanager_getmediabase64byname) (const NativeResourceManager \*mgr, const char \*resName, char \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | Obtains the Base64 code of the media resource with the specified screen density based on the specified resource name. | 
| [ResourceManager_ErrorCode](resourcemanager.md#resourcemanager_errorcode)[OH_ResourceManager_GetMedia](resourcemanager.md#oh_resourcemanager_getmedia) (const NativeResourceManager \*mgr, uint32_t resId, uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | Obtains the content of the media resource with the specified screen density based on the specified resource ID. | 
| [ResourceManager_ErrorCode](resourcemanager.md#resourcemanager_errorcode)[OH_ResourceManager_GetMediaByName](resourcemanager.md#oh_resourcemanager_getmediabyname) (const NativeResourceManager \*mgr, const char \*resName, uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | Obtains the content of the media resource with the specified screen density based on the specified resource name. | 
| [ResourceManager_ErrorCode](resourcemanager.md#resourcemanager_errorcode)[OH_ResourceManager_GetDrawableDescriptor](resourcemanager.md#oh_resourcemanager_getdrawabledescriptor) (const NativeResourceManager \*mgr, uint32_t resId, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density=0, uint32_t type=0) | Obtains the **DrawableDescriptor** object of the icon resource with the specified screen density based on the specified resource ID. | 
| [ResourceManager_ErrorCode](resourcemanager.md#resourcemanager_errorcode)[OH_ResourceManager_GetDrawableDescriptorByName](resourcemanager.md#oh_resourcemanager_getdrawabledescriptorbyname) (const NativeResourceManager \*mgr, const char \*resName, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density=0, uint32_t type=0) | Obtains the **DrawableDescriptor** object of the icon resource with the specified screen density based on the specified resource name. | 
