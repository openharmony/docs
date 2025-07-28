# ohresmgr.h

## Overview

Provides native APIs for obtaining resources.

**Library**: libohresmgr.so

**System capability**: SystemCapability.Global.ResourceManager

**Since**: 12

**Related module**: [resourcemanager](capi-resourcemanager.md)

## Summary

### Callback

| Name| Description|
| -- | -- |
| [ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64(const NativeResourceManager *mgr, uint32_t resId,char **resultValue, uint64_t *resultLen, uint32_t density = 0)](#oh_resourcemanager_getmediabase64) | Obtains the Base64 code of the media resource with the specified screen density based on the specified resource ID.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64Data(const NativeResourceManager *mgr, uint32_t resId,char **resultValue, uint64_t *resultLen, uint32_t density)](#oh_resourcemanager_getmediabase64data) | Obtains the Base64 code of the media resource with the specified screen density based on the specified resource ID.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64ByName(const NativeResourceManager *mgr,const char *resName, char **resultValue, uint64_t *resultLen, uint32_t density = 0)](#oh_resourcemanager_getmediabase64byname) | Obtains the Base64 code of the media resource with the specified screen density based on the specified resource name.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64DataByName(const NativeResourceManager *mgr,const char *resName, char **resultValue, uint64_t *resultLen, uint32_t density)](#oh_resourcemanager_getmediabase64databyname) | Obtains the Base64 code of the media resource with the specified screen density based on the specified resource name.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetMedia(const NativeResourceManager *mgr, uint32_t resId,uint8_t **resultValue, uint64_t *resultLen, uint32_t density = 0)](#oh_resourcemanager_getmedia) | Obtains the content of the media resource with the specified screen density based on the specified resource ID.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetMediaData(const NativeResourceManager *mgr, uint32_t resId,uint8_t **resultValue, uint64_t *resultLen, uint32_t density)](#oh_resourcemanager_getmediadata) | Obtains the content of the media resource with the specified screen density based on the specified resource ID.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetMediaByName(const NativeResourceManager *mgr, const char *resName,uint8_t **resultValue, uint64_t *resultLen, uint32_t density = 0)](#oh_resourcemanager_getmediabyname) | Obtains the content of the media resource with the specified screen density based on the specified resource name.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetMediaDataByName(const NativeResourceManager *mgr, const char *resName,uint8_t **resultValue, uint64_t *resultLen, uint32_t density)](#oh_resourcemanager_getmediadatabyname) | Obtains the content of the media resource with the specified screen density based on the specified resource name.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptor(const NativeResourceManager *mgr,uint32_t resId, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density = 0, uint32_t type = 0)](#oh_resourcemanager_getdrawabledescriptor) | Obtains the **DrawableDescriptor** object of the icon resource with the specified screen density based on the specified resource ID.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorData(const NativeResourceManager *mgr,uint32_t resId, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density, uint32_t type)](#oh_resourcemanager_getdrawabledescriptordata) | Obtains the **DrawableDescriptor** object of the icon resource with the specified screen density based on the specified resource ID.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorByName(const NativeResourceManager *mgr,const char *resName, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density = 0, uint32_t type = 0)](#oh_resourcemanager_getdrawabledescriptorbyname) | Obtains the **DrawableDescriptor** object of the icon resource with the specified screen density based on the specified resource name.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorDataByName(const NativeResourceManager *mgr,const char *resName, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density, uint32_t type)](#oh_resourcemanager_getdrawabledescriptordatabyname) | Obtains the **DrawableDescriptor** object of the icon resource with the specified screen density based on the specified resource name.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetSymbol(const NativeResourceManager *mgr, uint32_t resId,uint32_t *resultValue)](#oh_resourcemanager_getsymbol) | Obtains a **symbol** resource based on the specified resource ID.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetSymbolByName(const NativeResourceManager *mgr, const char *resName,uint32_t *resultValue)](#oh_resourcemanager_getsymbolbyname) | Obtains a **symbol** resource based on the specified resource name.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetLocales(const NativeResourceManager *mgr, char ***resultValue,uint32_t *resultLen, bool includeSystem = false)](#oh_resourcemanager_getlocales) | Obtains the language list. After using this API, you need to call [OH_ResourceManager_ReleaseStringArray()](#oh_resourcemanager_releasestringarray) to release the memory of **localinfo**.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetLocalesData(const NativeResourceManager *mgr, char ***resultValue,uint32_t *resultLen, bool includeSystem)](#oh_resourcemanager_getlocalesdata) | Obtains the language list. After using this API, you need to call [OH_ResourceManager_ReleaseStringArray()](#oh_resourcemanager_releasestringarray) to release the memory of **localinfo**.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetConfiguration(const NativeResourceManager *mgr,ResourceManager_Configuration *configuration)](#oh_resourcemanager_getconfiguration) | Obtains the device configuration. After using this API, you need to call [OH_ResourceManager_ReleaseConfiguration()](#oh_resourcemanager_releaseconfiguration) to release the memory. If the **ResourceManager_Configuration** object is created by using malloc, call **free()** to release the object.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetResourceConfiguration(const NativeResourceManager *mgr,ResourceManager_Configuration *configuration)](#oh_resourcemanager_getresourceconfiguration) | Obtains the device configuration. After using this API, you need to call [OH_ResourceManager_ReleaseConfiguration()](#oh_resourcemanager_releaseconfiguration) to release the memory. If the **ResourceManager_Configuration** object is created by using malloc, call **free()** to release the object.|
| [ResourceManager_ErrorCode OH_ResourceManager_ReleaseConfiguration(ResourceManager_Configuration *configuration)](#oh_resourcemanager_releaseconfiguration) | Releases the memory requested by using [OH_ResourceManager_GetConfiguration()](#oh_resourcemanager_getconfiguration) or [OH_ResourceManager_GetResourceConfiguration()](#oh_resourcemanager_getresourceconfiguration).|
| [ResourceManager_ErrorCode OH_ResourceManager_GetString(const NativeResourceManager *mgr, uint32_t resId,char **resultValue, ...)](#oh_resourcemanager_getstring) | Obtains a **string** resource based on the specified resource ID. The obtain common string resources, use **OH_ResourceManager_GetString(mgr, resId, resultValue)**. The obtain formatted string resources with the **%d**, **%s**, and **%f** placeholders, use **OH_ResourceManager_GetString(mgr, resId, resultValue, 10, "format", 10.10)**. After using this API, you need to call **free()** to release the memory of the strings.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetStringByName(const NativeResourceManager *mgr, const char *resName,char **resultValue, ...)](#oh_resourcemanager_getstringbyname) | Obtains a **string** resource based on the specified resource name. The obtain common string resources, use **OH_ResourceManager_GetString(mgr, resName, resultValue)**. The obtain formatted string resources with the **%d**, **%s**, and **%f** placeholders, use **OH_ResourceManager_GetString(mgr, resName, resultValue, 10, "format", 10.10)**. After using this API, you need to call **free()** to release the memory of the strings.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetStringArray(const NativeResourceManager *mgr, uint32_t resId,char ***resultValue, uint32_t *resultLen)](#oh_resourcemanager_getstringarray) | Obtains a string array based on the specified resource ID. After using this API, you need to call [OH_ResourceManager_ReleaseStringArray()](#oh_resourcemanager_releasestringarray) to release the memory of the string array.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetStringArrayByName(const NativeResourceManager *mgr,const char *resName, char ***resultValue, uint32_t *resultLen)](#oh_resourcemanager_getstringarraybyname) | Obtains a string array based on the specified resource name. After using this API, you need to call [OH_ResourceManager_ReleaseStringArray()](#oh_resourcemanager_releasestringarray) to release the memory of the string array.|
| [ResourceManager_ErrorCode OH_ResourceManager_ReleaseStringArray(char ***resValue, uint32_t len)](#oh_resourcemanager_releasestringarray) | Releases the memory of the string array.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetPluralString(const NativeResourceManager *mgr, uint32_t resId,uint32_t num, char **resultValue)](#oh_resourcemanager_getpluralstring) | Obtains singular and plural strings based on the specified resource ID. After using this API, you need to call **free()** to release the memory of the strings.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetPluralStringByName(const NativeResourceManager *mgr,const char *resName, uint32_t num, char **resultValue)](#oh_resourcemanager_getpluralstringbyname) | Obtains singular and plural strings based on the specified resource name. After using this API, you need to call **free()** to release the memory of the strings.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetIntPluralString(const NativeResourceManager *mgr, uint32_t resId,uint32_t num, char **resultValue, ...)](#oh_resourcemanager_getintpluralstring) | Obtains singular and plural strings based on the specified resource ID. After using this API, you need to call **free()** to release the memory of the strings.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetDoublePluralString(const NativeResourceManager *mgr, uint32_t resId,double num, char **resultValue, ...)](#oh_resourcemanager_getdoublepluralstring) | Obtains singular and plural strings based on the specified resource ID. After using this API, you need to call **free()** to release the memory of the strings.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetIntPluralStringByName(const NativeResourceManager *mgr,const char *resName, uint32_t num, char **resultValue, ...)](#oh_resourcemanager_getintpluralstringbyname) | Obtains singular and plural strings based on the specified resource name. After using this API, you need to call **free()** to release the memory of the strings.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetDoublePluralStringByName(const NativeResourceManager *mgr,const char *resName, double num, char **resultValue, ...)](#oh_resourcemanager_getdoublepluralstringbyname) | Obtains singular and plural strings based on the specified resource name. After using this API, you need to call **free()** to release the memory of the strings.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetColor(const NativeResourceManager *mgr, uint32_t resId,uint32_t *resultValue)](#oh_resourcemanager_getcolor) | Obtains a color value based on the specified resource ID.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetColorByName(const NativeResourceManager *mgr, const char *resName,uint32_t *resultValue)](#oh_resourcemanager_getcolorbyname) | Obtains a color value based on the specified resource ID.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetInt(const NativeResourceManager *mgr, uint32_t resId,int *resultValue)](#oh_resourcemanager_getint) | Obtains an int value based on the specified resource ID.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetIntByName(const NativeResourceManager *mgr, const char *resName,int *resultValue)](#oh_resourcemanager_getintbyname) | Obtains an int value based on the specified resource name.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetFloat(const NativeResourceManager *mgr, uint32_t resId,float *resultValue)](#oh_resourcemanager_getfloat) | Obtains a float value based on the specified resource ID.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetFloatByName(const NativeResourceManager *mgr, const char *resName,float *resultValue)](#oh_resourcemanager_getfloatbyname) | Obtains a float value based on the specified resource name.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetBool(const NativeResourceManager *mgr, uint32_t resId,bool *resultValue)](#oh_resourcemanager_getbool) | Obtains a bool value based on the specified resource ID.|
| [ResourceManager_ErrorCode OH_ResourceManager_GetBoolByName(const NativeResourceManager *mgr, const char *resName,bool *resultValue)](#oh_resourcemanager_getboolbyname) | Obtains a bool value based on the specified resource name.|
| [ResourceManager_ErrorCode OH_ResourceManager_AddResource(const NativeResourceManager *mgr, const char *path)](#oh_resourcemanager_addresource) | Adds overlay resources when an application is running.|
| [ResourceManager_ErrorCode OH_ResourceManager_RemoveResource(const NativeResourceManager *mgr, const char *path)](#oh_resourcemanager_removeresource) | Removes overlay resources when an application is running.|

## Function Description

### OH_ResourceManager_GetMediaBase64()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64(const NativeResourceManager *mgr, uint32_t resId,char **resultValue, uint64_t *resultLen, uint32_t density = 0)
```

**Description**

Obtains the Base64 code of the media resource with the specified screen density based on the specified resource ID.

**Since**: 12


**Parameters**

| Name| Description                                                                                                                                                                     |
| -- |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| uint32_t resId | Resource ID.                                                                                                                                                                  |
| uint32_t density = 0 | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](capi-resmgr-common-h.md#screendensity). The default value is 0, indicating that the current system screen density (in DPI) is used.                                                                                |
| char **resultValue | Result of writing **resultValue**.                                                                                                                                                      |
| uint64_t *resultLen | Length of media written to **resultLen**.                                                                                                                                                   |

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - The resource ID is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - No matching resource is found based on the resource ID.<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - A memory overflow occurs.|

### OH_ResourceManager_GetMediaBase64Data()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64Data(const NativeResourceManager *mgr, uint32_t resId,char **resultValue, uint64_t *resultLen, uint32_t density)
```

**Description**

Obtains the Base64 code of the media resource with the specified screen density based on the specified resource ID.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| uint32_t resId | Resource ID.|
| char **resultValue | Result of writing **resultValue**.|
| uint64_t *resultLen | Length of media written to **resultLen**.|
| uint32_t density | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](capi-resmgr-common-h.md#screendensity). The default value is **0**, indicating that the current system screen density (in DPI) is used. If this parameter is not required, set it to **0**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - The resource ID is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - No matching resource is found based on the resource ID.<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - A memory overflow occurs.|

### OH_ResourceManager_GetMediaBase64ByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64ByName(const NativeResourceManager *mgr,const char *resName, char **resultValue, uint64_t *resultLen, uint32_t density = 0)
```

**Description**

Obtains the Base64 code of the media resource with the specified screen density based on the specified resource name.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| const char *resName | Resource name.|
| char **resultValue | Result of writing **resultValue**.|
| uint64_t *resultLen | Length of media written to **resultLen**.|
| uint32_t density = 0 | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](capi-resmgr-common-h.md#screendensity). The default value is 0, indicating that the current system screen density (in DPI) is used.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_NAME_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - The resource name is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - No matching resource is found based on the resource name.<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - A memory overflow occurs.|

### OH_ResourceManager_GetMediaBase64DataByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64DataByName(const NativeResourceManager *mgr,const char *resName, char **resultValue, uint64_t *resultLen, uint32_t density)
```

**Description**

Obtains the Base64 code of the media resource with the specified screen density based on the specified resource name.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| const char *resName | Resource name.|
| char **resultValue | Result of writing **resultValue**.|
| uint64_t *resultLen | Length of media written to **resultLen**.|
| uint32_t density | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](capi-resmgr-common-h.md#screendensity). The default value is **0**, indicating that the current system screen density (in DPI) is used. If this parameter is not required, set it to **0**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_NAME_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - The resource name is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - No matching resource is found based on the resource name.<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - A memory overflow occurs.|

### OH_ResourceManager_GetMedia()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMedia(const NativeResourceManager *mgr, uint32_t resId,uint8_t **resultValue, uint64_t *resultLen, uint32_t density = 0)
```

**Description**

Obtains the content of the media resource with the specified screen density based on the specified resource ID.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| uint32_t resId | Resource ID.|
| uint32_t density = 0 | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](capi-resmgr-common-h.md#screendensity). The default value is 0, indicating that the current system screen density (in DPI) is used.|
| uint8_t **resultValue | Result of writing **resultValue**.|
| uint64_t *resultLen | Length of media written to **resultLen**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - The resource ID is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - No matching resource is found based on the resource ID.<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - A memory overflow occurs.|

### OH_ResourceManager_GetMediaData()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaData(const NativeResourceManager *mgr, uint32_t resId,uint8_t **resultValue, uint64_t *resultLen, uint32_t density)
```

**Description**

Obtains the content of the media resource with the specified screen density based on the specified resource ID.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| uint32_t resId | Resource ID.|
| uint8_t **resultValue | Result of writing **resultValue**.|
| uint64_t *resultLen | Length of media written to **resultLen**.|
| uint32_t density | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](capi-resmgr-common-h.md#screendensity). The default value is **0**, indicating that the current system screen density (in DPI) is used. If this parameter is not required, set it to **0**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - The resource ID is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - No matching resource is found based on the resource ID.<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - A memory overflow occurs.|

### OH_ResourceManager_GetMediaByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaByName(const NativeResourceManager *mgr, const char *resName,uint8_t **resultValue, uint64_t *resultLen, uint32_t density = 0)
```

**Description**

Obtains the content of the media resource with the specified screen density based on the specified resource name.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| const char *resName | Resource name.|
| uint32_t density = 0 | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](capi-resmgr-common-h.md#screendensity). The default value is 0, indicating that the current system screen density (in DPI) is used.|
| uint8_t **resultValue | Result of writing **resultValue**.|
| uint64_t *resultLen | Length of media written to **resultLen**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_NAME_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - The resource name is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - No matching resource is found based on the resource name.<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - A memory overflow occurs.|

### OH_ResourceManager_GetMediaDataByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaDataByName(const NativeResourceManager *mgr, const char *resName,uint8_t **resultValue, uint64_t *resultLen, uint32_t density)
```

**Description**

Obtains the content of the media resource with the specified screen density based on the specified resource name.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| const char *resName | Resource name.|
| uint8_t **resultValue | Result of writing **resultValue**.|
| uint64_t *resultLen | Length of media written to **resultLen**.|
| uint32_t density | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](capi-resmgr-common-h.md#screendensity). The default value is **0**, indicating that the current system screen density (in DPI) is used. If this parameter is not required, set it to **0**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_NAME_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - The resource name is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - No matching resource is found based on the resource name.<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - A memory overflow occurs.|

### OH_ResourceManager_GetDrawableDescriptor()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptor(const NativeResourceManager *mgr,uint32_t resId, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density = 0, uint32_t type = 0)
```

**Description**

Obtains the **DrawableDescriptor** object of the icon resource with the specified screen density based on the specified resource ID.

**Since**: 12


**Parameters**

| Name                                                                                                                | Description|
|---------------------------------------------------------------------------------------------------------------------| -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr                                           | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| uint32_t resId                                                                                                      | Resource ID.|
| uint32_t density = 0                                                                                                | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](capi-resmgr-common-h.md#screendensity). The default value is 0, indicating that the current system screen density (in DPI) is used.|
| uint32_t type = 0                                                                                                   | Icon type. The value **0** indicates an application icon, and the value **1** indicates a theme icon.|
| ArkUI_DrawableDescriptor **drawableDescriptor | Result of writing **drawableDescriptor**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - The resource ID is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - No matching resource is found based on the resource ID.|

### OH_ResourceManager_GetDrawableDescriptorData()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorData(const NativeResourceManager *mgr,uint32_t resId, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density, uint32_t type)
```

**Description**

Obtains the **DrawableDescriptor** object of the icon resource with the specified screen density based on the specified resource ID.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| uint32_t resId | Resource ID.|
| ArkUI_DrawableDescriptor **drawableDescriptor | Result of writing **drawableDescriptor**.|
| uint32_t density | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](capi-resmgr-common-h.md#screendensity). The default value is **0**, indicating that the current system screen density (in DPI) is used. If this parameter is not required, set it to **0**.|
| uint32_t type | Icon type. This parameter is optional. The value **0** indicates an application icon, and the value **1** indicates a theme icon. If this parameter is not required, set it to **0**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - The resource ID is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - No matching resource is found based on the resource ID.|

### OH_ResourceManager_GetDrawableDescriptorByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorByName(const NativeResourceManager *mgr,const char *resName, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density = 0, uint32_t type = 0)
```

**Description**

Obtains the **DrawableDescriptor** object of the icon resource with the specified screen density based on the specified resource name.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| const char *resName | Resource name.|
| uint32_t density = 0 | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](capi-resmgr-common-h.md#screendensity). The default value is 0, indicating that the current system screen density (in DPI) is used.|
| uint32_t type = 0 | Icon type. This parameter is optional. The value **0** indicates an application icon, the value **1** indicates a theme icon, and the value **2** indicates a dynamic icon.|
| ArkUI_DrawableDescriptor **drawableDescriptor | Result of writing **drawableDescriptor**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_NAME_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - The resource name is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - No matching resource is found based on the resource name.|

### OH_ResourceManager_GetDrawableDescriptorDataByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorDataByName(const NativeResourceManager *mgr,const char *resName, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density, uint32_t type)
```

**Description**

Obtains the **DrawableDescriptor** object of the icon resource with the specified screen density based on the specified resource name.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| const char *resName | Resource name.|
| ArkUI_DrawableDescriptor **drawableDescriptor | Result of writing **drawableDescriptor**.|
| uint32_t density | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](capi-resmgr-common-h.md#screendensity). The default value is **0**, indicating that the current system screen density (in DPI) is used. If this parameter is not required, set it to **0**.|
| uint32_t type | Icon type. This parameter is optional. The value **0** indicates an application icon, and the value **1** indicates a theme icon. If this parameter is not required, set it to **0**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_NAME_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - The resource name is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - No matching resource is found based on the resource name.|

### OH_ResourceManager_GetSymbol()

```
ResourceManager_ErrorCode OH_ResourceManager_GetSymbol(const NativeResourceManager *mgr, uint32_t resId,uint32_t *resultValue)
```

**Description**

Obtains a **symbol** resource based on the specified resource ID.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| uint32_t resId | Resource ID.|
| uint32_t *resultValue | Result of writing **resultValue**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - The resource ID is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - No matching resource is found based on the resource ID.<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - The resource is cyclically referenced.|

### OH_ResourceManager_GetSymbolByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetSymbolByName(const NativeResourceManager *mgr, const char *resName,uint32_t *resultValue)
```

**Description**

Obtains a **symbol** resource based on the specified resource name.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| const char *resName | Resource name.|
| uint32_t *resultValue | Result of writing **resultValue**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_NAME_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - The resource name is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - No matching resource is found based on the resource name.<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - The resource is cyclically referenced.|

### OH_ResourceManager_GetLocales()

```
ResourceManager_ErrorCode OH_ResourceManager_GetLocales(const NativeResourceManager *mgr, char ***resultValue,uint32_t *resultLen, bool includeSystem = false)
```

**Description**

Obtains the language list. After using this API, you need to call **OH_ResourceManager_ReleaseStringArray()** to release the memory of **localinfo**.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| char ***resultValue | Result of writing **resultValue**.|
| uint32_t *resultLen | Length of locales written to **resultLen**.|
| bool includeSystem = false | Whether system resources are included. The default value is **false**. This parameter does not take effect if only system resources are involved when you query the list of locales.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>         [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - A memory overflow occurs.|

### OH_ResourceManager_GetLocalesData()

```
ResourceManager_ErrorCode OH_ResourceManager_GetLocalesData(const NativeResourceManager *mgr, char ***resultValue,uint32_t *resultLen, bool includeSystem)
```

**Description**

Obtains the language list. After using this API, you need to call **OH_ResourceManager_ReleaseStringArray()** to release the memory of **localinfo**.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| char ***resultValue | Result of writing **resultValue**.|
| uint32_t *resultLen | Length of locales written to **resultLen**.|
| bool includeSystem | Whether system resources are included. If this parameter is not required, set it to **false**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>         [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - A memory overflow occurs.|

### OH_ResourceManager_GetConfiguration()

```
ResourceManager_ErrorCode OH_ResourceManager_GetConfiguration(const NativeResourceManager *mgr,ResourceManager_Configuration *configuration)
```

**Description**

Obtains the device configuration. After using this API, you need to call **OH_ResourceManager_ReleaseConfiguration()** to release the memory. If the **ResourceManager_Configuration** object is created by using malloc, call **free()** to release the object.

**Since**: 12

**Deprecated from**: 20

**Substitute**: [OH_ResourceManager_GetResourceConfiguration](#oh_resourcemanager_getresourceconfiguration)


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| [ResourceManager_Configuration](capi-resourcemanager-resourcemanager-configuration.md) *configuration | Device configuration. The return value of **configuration.screenDensity** is the rounded value of the device's DPI divided by 160.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_SYSTEM_RES_MANAGER_GET_FAILED](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001009 - The attempt to access system resources fails.<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - A memory overflow occurs.|

### OH_ResourceManager_GetResourceConfiguration()

```
ResourceManager_ErrorCode OH_ResourceManager_GetResourceConfiguration(const NativeResourceManager *mgr,ResourceManager_Configuration *configuration)
```

**Description**

Obtains the device configuration. After using this API, you need to call **OH_ResourceManager_ReleaseConfiguration()** to release the memory. If the **ResourceManager_Configuration** object is created by using malloc, call **free()** to release the object.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| [ResourceManager_Configuration](capi-resourcemanager-resourcemanager-configuration.md) *configuration | Device configuration. The return value of **configuration.screenDensity** is the device's DPI.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_SYSTEM_RES_MANAGER_GET_FAILED](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001009 - The attempt to access system resources fails.<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - A memory overflow occurs.|

### OH_ResourceManager_ReleaseConfiguration()

```
ResourceManager_ErrorCode OH_ResourceManager_ReleaseConfiguration(ResourceManager_Configuration *configuration)
```

**Description**

Releases the memory requested by using **OH_ResourceManager_GetConfiguration()**.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ResourceManager_Configuration](capi-resourcemanager-resourcemanager-configuration.md) *configuration | Configuration object whose memory needs to be released.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.|

### OH_ResourceManager_GetString()

```
ResourceManager_ErrorCode OH_ResourceManager_GetString(const NativeResourceManager *mgr, uint32_t resId,char **resultValue, ...)
```

**Description**

Obtains a **string** resource based on the specified resource ID. The obtain common string resources, use **OH_ResourceManager_GetString(mgr, resId, resultValue)**. The obtain formatted string resources with the **%d**, **%s**, and **%f** placeholders, use **OH_ResourceManager_GetString(mgr, resId, resultValue, 10, "format", 10.10)**. After using this API, you need to call **free()** to release the memory of the strings.

**Since**: 12


**Parameters**

| Name                                                                                            | Description|
|-------------------------------------------------------------------------------------------------| -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr                                                            | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| uint32_t resId                                                                                  | Resource ID.|
| char **resultValue                                                                              | Result of writing **resultValue**.|
| ... | Variable representing formatted string resources. Supported types include const char*, int, and float.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - The resource ID is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - No matching resource is found based on the resource ID.<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - The resource is cyclically referenced.<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - A memory overflow occurs.|

### OH_ResourceManager_GetStringByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetStringByName(const NativeResourceManager *mgr, const char *resName,char **resultValue, ...)
```

**Description**

Obtains a **string** resource based on the specified resource name. The obtain common string resources, use **OH_ResourceManager_GetString(mgr, resName, resultValue)**. The obtain formatted string resources with the **%d**, **%s**, and **%f** placeholders, use **OH_ResourceManager_GetString(mgr, resName, resultValue, 10, "format", 10.10)**. After using this API, you need to call **free()** to release the memory of the strings.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| const char *resName | Resource name.|
| char **resultValue | Result of writing **resultValue**.|
| ... | Variable representing formatted string resources. Supported types include const char*, int, and float.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_NAME_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - The resource name is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - No matching resource is found based on the resource name.<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - The resource is cyclically referenced.<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - A memory overflow occurs.|

### OH_ResourceManager_GetStringArray()

```
ResourceManager_ErrorCode OH_ResourceManager_GetStringArray(const NativeResourceManager *mgr, uint32_t resId,char ***resultValue, uint32_t *resultLen)
```

**Description**

Obtains a string array based on the specified resource ID. After using this API, you need to call **OH_ResourceManager_ReleaseStringArray()** to release the memory of the string array.

**Since**: 12


**Parameters**

| Name                                 | Description|
|--------------------------------------| -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| uint32_t resId                       | Resource ID.|
| char ***resultValue                  | Result of writing **resultValue**.|
| uint32_t *resultLen                  | Length of **StringArray** written to **resultLen**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - The resource ID is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - No matching resource is found based on the resource ID.<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - The resource is cyclically referenced.<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - A memory overflow occurs.|

### OH_ResourceManager_GetStringArrayByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetStringArrayByName(const NativeResourceManager *mgr,const char *resName, char ***resultValue, uint32_t *resultLen)
```

**Description**

Obtains a string array based on the specified resource name. After using this API, you need to call **OH_ResourceManager_ReleaseStringArray()** to release the memory of the string array.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| const char *resName | Resource name.|
| char ***resultValue | Result of writing **resultValue**.|
| uint32_t *resultLen | Length of **StringArray** written to **resultLen**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_NAME_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - The resource name is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - No matching resource is found based on the resource name.<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - The resource is cyclically referenced.<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - A memory overflow occurs.|

### OH_ResourceManager_ReleaseStringArray()

```
ResourceManager_ErrorCode OH_ResourceManager_ReleaseStringArray(char ***resValue, uint32_t len)
```

**Description**

Releases the memory of the string array.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| char ***resValue | String array whose memory needs to be released.|
| uint32_t len | Length of the string array.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.|

### OH_ResourceManager_GetPluralString()

```
ResourceManager_ErrorCode OH_ResourceManager_GetPluralString(const NativeResourceManager *mgr, uint32_t resId,uint32_t num, char **resultValue)
```

**Description**

Obtains singular and plural strings based on the specified resource ID. After using this API, you need to call **free()** to release the memory of the strings.

**Since**: 12

**Deprecated from**: 18

**Substitute**: [OH_ResourceManager_GetIntPluralString](capi-ohresmgr-h.md#oh_resourcemanager_getintpluralstring)


**Parameters**

| Name                                 | Description|
|--------------------------------------| -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| uint32_t resId                       | Resource ID.|
| uint32_t num                         |  Number.|
| char **resultValue                   | Result of writing **resultValue**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - The resource ID is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - No matching resource is found based on the resource ID.<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - The resource is cyclically referenced.<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - A memory overflow occurs.|

### OH_ResourceManager_GetPluralStringByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetPluralStringByName(const NativeResourceManager *mgr,const char *resName, uint32_t num, char **resultValue)
```

**Description**

Obtains singular and plural strings based on the specified resource name. After using this API, you need to call **free()** to release the memory of the strings.

**Since**: 12

**Deprecated from**: 18

**Substitute**: [OH_ResourceManager_GetIntPluralStringByName](capi-ohresmgr-h.md#oh_resourcemanager_getintpluralstringbyname)


**Parameters**

| Name| Description                                                                                                                                                                                     |
| -- |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| const char *resName | Resource name.                                                                                                                                                                                  |
| uint32_t num | Number.                                                                                                                                                                                   |
| char **resultValue | Result of writing **resultValue**.                                                                                                                                                                      |

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_NAME_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - The resource name is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - No matching resource is found based on the resource name.<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - The resource is cyclically referenced.<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - A memory overflow occurs.|

### OH_ResourceManager_GetIntPluralString()

```
ResourceManager_ErrorCode OH_ResourceManager_GetIntPluralString(const NativeResourceManager *mgr, uint32_t resId,uint32_t num, char **resultValue, ...)
```

**Description**

Obtains singular and plural strings based on the specified resource ID. After using this API, you need to call **free()** to release the memory of the strings.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| uint32_t resId | Resource ID.|
| uint32_t num |  Quantity value (an integer number). Its string representation is obtained based on the current language's plural rules.|
| char **resultValue | Result of writing **resultValue**.|
| ... | Variable representing formatted string resources. Supported types include const char*, int, and float.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - The resource ID is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - No matching resource is found based on the resource ID.<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - The resource is cyclically referenced.<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - A memory overflow occurs.|

### OH_ResourceManager_GetDoublePluralString()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDoublePluralString(const NativeResourceManager *mgr, uint32_t resId,double num, char **resultValue, ...)
```

**Description**

Obtains singular and plural strings based on the specified resource ID. After using this API, you need to call **free()** to release the memory of the strings.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| uint32_t resId | Resource ID.|
| double num |  Quantity value (a floating point number). Its string representation is obtained based on the current language's plural rules.|
| char **resultValue | Result of writing **resultValue**.|
| ... | Variable representing formatted string resources. Supported types include const char*, int, and float.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - The resource ID is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - No matching resource is found based on the resource ID.<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - The resource is cyclically referenced.<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - A memory overflow occurs.|

### OH_ResourceManager_GetIntPluralStringByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetIntPluralStringByName(const NativeResourceManager *mgr,const char *resName, uint32_t num, char **resultValue, ...)
```

**Description**

Obtains singular and plural strings based on the specified resource name. After using this API, you need to call **free()** to release the memory of the strings.

**Since**: 18


**Parameters**

| Name                                                                                            | Description                                                                                                                                                                     |
|-------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr                                                            | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| const char *resName                                                                             | Resource name.                                                                                                                                                                  |
| uint32_t num                                                                                    | Quantity value (an integer number). Its string representation is obtained based on the current language's plural rules.                                                                                                                                     |
| char **resultValue                                                                              | Result of writing **resultValue**.                                                                                                                                                      |
| ... | Variable representing formatted string resources. Supported types include const char*, int, and float.                                                                                                                             |

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_NAME_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - The resource name is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - No matching resource is found based on the resource name.<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - The resource is cyclically referenced.<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - A memory overflow occurs.|

### OH_ResourceManager_GetDoublePluralStringByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDoublePluralStringByName(const NativeResourceManager *mgr,const char *resName, double num, char **resultValue, ...)
```

**Description**

Obtains singular and plural strings based on the specified resource name. After using this API, you need to call **free()** to release the memory of the strings.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| const char *resName | Resource name.|
| double num |  Quantity value (a floating point number). Its string representation is obtained based on the current language's plural rules.|
| char **resultValue | Result of writing **resultValue**.|
| ... | Variable representing formatted string resources. Supported types include const char*, int, and float.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_NAME_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - The resource name is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - No matching resource is found based on the resource name.<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - The resource is cyclically referenced.<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - A memory overflow occurs.|

### OH_ResourceManager_GetColor()

```
ResourceManager_ErrorCode OH_ResourceManager_GetColor(const NativeResourceManager *mgr, uint32_t resId,uint32_t *resultValue)
```

**Description**

Obtains a color value based on the specified resource ID.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| uint32_t resId | Resource ID.|
| uint32_t *resultValue | Result of writing **resultValue**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - The resource ID is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - No matching resource is found based on the resource ID.<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - The resource is cyclically referenced.|

### OH_ResourceManager_GetColorByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetColorByName(const NativeResourceManager *mgr, const char *resName,uint32_t *resultValue)
```

**Description**

Obtains a color value based on the specified resource ID.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| const char *resName | Resource name.|
| uint32_t *resultValue | Result of writing **resultValue**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_NAME_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - The resource name is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - No matching resource is found based on the resource name.<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - The resource is cyclically referenced.|

### OH_ResourceManager_GetInt()

```
ResourceManager_ErrorCode OH_ResourceManager_GetInt(const NativeResourceManager *mgr, uint32_t resId,int *resultValue)
```

**Description**

Obtains an int value based on the specified resource ID.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| uint32_t resId | Resource ID.|
| int *resultValue | Result of writing **resultValue**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - The resource ID is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - No matching resource is found based on the resource ID.<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - The resource is cyclically referenced.|

### OH_ResourceManager_GetIntByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetIntByName(const NativeResourceManager *mgr, const char *resName,int *resultValue)
```

**Description**

Obtains an int value based on the specified resource name.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| const char *resName | Resource name.|
| int *resultValue | Result of writing **resultValue**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_NAME_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - The resource name is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - No matching resource is found based on the resource name.<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - The resource is cyclically referenced.|

### OH_ResourceManager_GetFloat()

```
ResourceManager_ErrorCode OH_ResourceManager_GetFloat(const NativeResourceManager *mgr, uint32_t resId,float *resultValue)
```

**Description**

Obtains a float value based on the specified resource ID.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| uint32_t resId | Resource ID.|
| float *resultValue | Result of writing **resultValue**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - The resource ID is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - No matching resource is found based on the resource ID.<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - The resource is cyclically referenced.|

### OH_ResourceManager_GetFloatByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetFloatByName(const NativeResourceManager *mgr, const char *resName,float *resultValue)
```

**Description**

Obtains a float value based on the specified resource name.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| const char *resName | Resource name.|
| float *resultValue | Result of writing **resultValue**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_NAME_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - The resource name is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - No matching resource is found based on the resource name.<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - The resource is cyclically referenced.|

### OH_ResourceManager_GetBool()

```
ResourceManager_ErrorCode OH_ResourceManager_GetBool(const NativeResourceManager *mgr, uint32_t resId,bool *resultValue)
```

**Description**

Obtains a bool value based on the specified resource ID.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| uint32_t resId | Resource ID.|
| bool *resultValue | Result of writing **resultValue**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - The resource ID is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - No matching resource is found based on the resource ID.<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - The resource is cyclically referenced.|

### OH_ResourceManager_GetBoolByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetBoolByName(const NativeResourceManager *mgr, const char *resName,bool *resultValue)
```

**Description**

Obtains a bool value based on the specified resource name.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| const char *resName | Resource name.|
| bool *resultValue | Result of writing **resultValue**.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_RES_NAME_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - The resource name is invalid.<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - No matching resource is found based on the resource name.<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - The resource is cyclically referenced.|

### OH_ResourceManager_AddResource()

```
ResourceManager_ErrorCode OH_ResourceManager_AddResource(const NativeResourceManager *mgr, const char *path)
```

**Description**

Adds overlay resources when an application is running.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| const char *path | Resource path.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_OVERLAY_RES_PATH_INVALID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001010 - The resource path is invalid.|

### OH_ResourceManager_RemoveResource()

```
ResourceManager_ErrorCode OH_ResourceManager_RemoveResource(const NativeResourceManager *mgr, const char *path)
```

**Description**

Removes overlay resources when an application is running.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | Pointer to [NativeResourceManager](capi-rawfile-nativeresourcemanager.md). It is obtained by using [OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager).|
| const char *path | Resource path.|

**Returns**

| Type| Description|
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - The operation is successful.<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.<br>          [ERROR_CODE_OVERLAY_RES_PATH_INVALID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001010 - The resource path is invalid.|
