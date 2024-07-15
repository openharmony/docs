# Resourcemanager


## Overview

Provides C APIs for obtaining resources.

**Since**: 12


## Summary


### File

| Name| Description| 
| -------- | -------- |
| [ohresmgr.h](ohresmgr_8h.md) | Provides native APIs for obtaining resources.| 
| [resmgr_common.h](resmgr__common_8h.md) | Provides the enum types and structures for resource manager APIs.| 


### Enum

| Name| Description| 
| -------- | -------- |
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) {<br>SUCCESS = 0, ERROR_CODE_INVALID_INPUT_PARAMETER = 401, ERROR_CODE_RES_ID_NOT_FOUND = 9001001, ERROR_CODE_RES_NOT_FOUND_BY_ID = 9001002,<br>ERROR_CODE_RES_NAME_NOT_FOUND = 9001003, ERROR_CODE_RES_NOT_FOUND_BY_NAME = 9001004, ERROR_CODE_RES_PATH_INVALID = 9001005, ERROR_CODE_RES_REF_TOO_MUCH = 9001006,<br>ERROR_CODE_RES_ID_FORMAT_ERROR = 9001007, ERROR_CODE_RES_NAME_FORMAT_ERROR = 9001008, ERROR_CODE_SYSTEM_RES_MANAGER_GET_FAILED = 9001009, ERROR_CODE_OVERLAY_RES_PATH_INVALID = 9001010,<br>ERROR_CODE_OUT_OF_MEMORY = 9001100<br>} | Enumerates resource manager error codes.| 
| [ScreenDensity](#screendensity) {<br>SCREEN_SDPI = 120, SCREEN_MDPI = 160, SCREEN_LDPI = 240, SCREEN_XLDPI = 320,<br>SCREEN_XXLDPI = 480, SCREEN_XXXLDPI = 640<br>} | Enumerates screen density types.| 


### Callback

| Name| Description| 
| -------- | -------- |
| [ResourceManager_ErrorCode](#resourcemanager_errorcode)[OH_ResourceManager_GetMediaBase64](#oh_resourcemanager_getmediabase64) (const NativeResourceManager \*mgr, uint32_t resId, char \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | Obtains the Base64 code of the media resource with the specified screen density based on the specified resource ID.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode)[OH_ResourceManager_GetMediaBase64ByName](#oh_resourcemanager_getmediabase64byname) (const NativeResourceManager \*mgr, const char \*resName, char \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | Obtains the Base64 code of the media resource with the specified screen density based on the specified resource name.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode)[OH_ResourceManager_GetMedia](#oh_resourcemanager_getmedia) (const NativeResourceManager \*mgr, uint32_t resId, uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | Obtains the content of the media resource with the specified screen density based on the specified resource ID.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode)[OH_ResourceManager_GetMediaByName](#oh_resourcemanager_getmediabyname) (const NativeResourceManager \*mgr, const char \*resName, uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | Obtains the content of the media resource with the specified screen density based on the specified resource name.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode)[OH_ResourceManager_GetDrawableDescriptor](#oh_resourcemanager_getdrawabledescriptor) (const NativeResourceManager \*mgr, uint32_t resId, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density=0, uint32_t type=0) | Obtains the **DrawableDescriptor** object of the icon resource with the specified screen density based on the specified resource ID.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode)[OH_ResourceManager_GetDrawableDescriptorByName](#oh_resourcemanager_getdrawabledescriptorbyname) (const NativeResourceManager \*mgr, const char \*resName, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density=0, uint32_t type=0) | Obtains the **DrawableDescriptor** object of the icon resource with the specified screen density based on the specified resource name.| 


## Enum Description


### ResourceManager_ErrorCode

```
enum ResourceManager_ErrorCode
```

**Description**

Enumerates resource manager error codes.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| SUCCESS | Success.| 
| ERROR_CODE_INVALID_INPUT_PARAMETER | Invalid input parameter.| 
| ERROR_CODE_RES_ID_NOT_FOUND | Invalid resource ID.| 
| ERROR_CODE_RES_NOT_FOUND_BY_ID | Invalid resource name.| 
| ERROR_CODE_RES_NAME_NOT_FOUND | No matching resource found based on the resource ID.| 
| ERROR_CODE_RES_NOT_FOUND_BY_NAME | No matching resource found based on the resource name.| 
| ERROR_CODE_RES_PATH_INVALID | Invalid relative path.| 
| ERROR_CODE_RES_REF_TOO_MUCH | Resource referenced cyclically.| 
| ERROR_CODE_RES_ID_FORMAT_ERROR | Failed to format the resource obtained based on the specified resource ID.| 
| ERROR_CODE_RES_NAME_FORMAT_ERROR | Failed to format the resource obtained based on the specified resource name.| 
| ERROR_CODE_SYSTEM_RES_MANAGER_GET_FAILED | Failed to access system resources.| 
| ERROR_CODE_OVERLAY_RES_PATH_INVALID | Invalid overlay path.| 
| ERROR_CODE_OUT_OF_MEMORY | Memory overflow.| 


### ScreenDensity

```
enum ScreenDensity
```

**Description**

Enumerates screen density types.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| SCREEN_SDPI | Screen density with small-scale dots per inch (SDPI).| 
| SCREEN_MDPI | Screen density with medium-scale dots per inch (MDPI).| 
| SCREEN_LDPI | Screen density with large-scale dots per inch (LDPI).| 
| SCREEN_XLDPI | Screen density with extra-large-scale dots per inch (XLDPI).| 
| SCREEN_XXLDPI | Screen density with extra-extra-large-scale dots per inch (XXLDPI).| 
| SCREEN_XXXLDPI | Screen density with extra-extra-extra-large-scale dots per inch (XXXLDPI).| 


## Function Description


### OH_ResourceManager_GetDrawableDescriptor()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptor (const NativeResourceManager * mgr, uint32_t resId, ArkUI_DrawableDescriptor ** drawableDescriptor, uint32_t density = 0, uint32_t type = 0 )
```

**Description**

Obtains the **DrawableDescriptor** object of the icon resource with the specified screen density based on the specified resource ID.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to **NativeResourceManager**. It is obtained by using the **OH_ResourceManager_InitNativeResourceManager** API.| 
| resId | Resource ID.| 
| density | Screen density. If the value of **enddensity** is **0**, the current system screen density is used.| 
| type | Icon type. The value **0** indicates an application icon, and the value **1** indicates a theme icon.| 
| drawableDescriptor | Result of writing **drawableDescriptor**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401: The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001001: The resource ID is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002: No matching resource is found based on the resource ID.


### OH_ResourceManager_GetDrawableDescriptorByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorByName (const NativeResourceManager * mgr, const char * resName, ArkUI_DrawableDescriptor ** drawableDescriptor, uint32_t density = 0, uint32_t type = 0 )
```

Description

Obtains the **DrawableDescriptor** object of the icon resource with the specified screen density based on the specified resource name.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to **NativeResourceManager**. It is obtained by using the **OH_ResourceManager_InitNativeResourceManager** API.| 
| resName | Resource name.| 
| density | Screen density. If the value of **enddensity** is **0**, the current system screen density is used.| 
| type | Icon type. The value **0** indicates an application icon, the value **1** indicates a theme icon, and the value **2** indicates a dynamic icon.| 
| drawableDescriptor | Result of writing **drawableDescriptor**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401: The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_NAME_NOT_FOUND 9001003: The resource name is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_NAME 9001004: No matching resource is found based on the resource name.


### OH_ResourceManager_GetMedia()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMedia (const NativeResourceManager * mgr, uint32_t resId, uint8_t ** resultValue, uint64_t * resultLen, uint32_t density = 0 )
```

Description

Obtains the content of the media resource with the specified screen density based on the specified resource ID.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to **NativeResourceManager**. It is obtained by using the **OH_ResourceManager_InitNativeResourceManager** API.| 
| resId | Resource ID.| 
| density | Screen density. If the value of **enddensity** is **0**, the current system screen density is used.| 
| resultValue | Result of writing **resultValue**.| 
| resultLen | Length of media written to **resultLen**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401: The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001001: The resource ID is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002: No matching resource is found based on the resource ID.

ERROR_CODE_OUT_OF_MEMORY 9001100: The memory overflows.


### OH_ResourceManager_GetMediaBase64()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64 (const NativeResourceManager * mgr, uint32_t resId, char ** resultValue, uint64_t * resultLen, uint32_t density = 0 )
```

Description

Obtains the Base64 code of the media resource with the specified screen density based on the specified resource ID.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to **NativeResourceManager**. It is obtained by using the **OH_ResourceManager_InitNativeResourceManager** API.| 
| resId | Resource ID.| 
| density | Screen density. If the value of **enddensity** is **0**, the current system screen density is used.| 
| resultValue | Result of writing **resultValue**.| 
| resultLen | Length of media written to **resultLen**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401: The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001001: The resource ID is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002: No matching resource is found based on the resource ID.

ERROR_CODE_OUT_OF_MEMORY 9001100: The memory overflows.


### OH_ResourceManager_GetMediaBase64ByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64ByName (const NativeResourceManager * mgr, const char * resName, char ** resultValue, uint64_t * resultLen, uint32_t density = 0 )
```

Description

Obtains the Base64 code of the media resource with the specified screen density based on the specified resource name.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to **NativeResourceManager**. It is obtained by using the **OH_ResourceManager_InitNativeResourceManager** API.| 
| resName | Resource name.| 
| density | Screen density. If the value of **enddensity** is **0**, the current system screen density is used.| 
| resultValue | Result of writing **resultValue**.| 
| resultLen | Length of media written to **resultLen**.| 

**Returns**

SUCCESS = 0: Operation succeeded. ERROR_CODE_INVALID_INPUT_PARAMETER 401: The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed. ERROR_CODE_RES_NAME_NOT_FOUND 9001003: The resource name is invalid. ERROR_CODE_RES_NOT_FOUND_BY_NAME 9001004: No matching resource is found based on the resource name. ERROR_CODE_OUT_OF_MEMORY 9001100: The memory overflows.


### OH_ResourceManager_GetMediaByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaByName (const NativeResourceManager * mgr, const char * resName, uint8_t ** resultValue, uint64_t * resultLen, uint32_t density = 0 )
```

Description

Obtains the content of the media resource with the specified screen density based on the specified resource name.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to **NativeResourceManager**. It is obtained by using the **OH_ResourceManager_InitNativeResourceManager** API.| 
| resName | Resource name.| 
| density | Screen density. If the value of **enddensity** is **0**, the current system screen density is used.| 
| resultValue | Result of writing **resultValue**.| 
| resultLen | Length of media written to **resultLen**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401: The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_NAME_NOT_FOUND 9001003: The resource name is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_NAME 9001004: No matching resource is found based on the resource name.

ERROR_CODE_OUT_OF_MEMORY 9001100: The memory overflows.
