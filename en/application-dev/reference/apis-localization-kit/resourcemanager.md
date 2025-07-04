# Resourcemanager


## Overview

Provides C APIs for obtaining resources.

**Since**: 12


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [ohresmgr.h](ohresmgr_8h.md) | Provides native APIs for obtaining resources.| 
| [resmgr_common.h](resmgr__common_8h.md) | Provides the enum types and structures for resource manager APIs.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[ResourceManager_Configuration](_resource_manager___configuration.md) | Enumerates device states.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [ResourceManager_Direction](#resourcemanager_direction) [ResourceManager_Direction](#resourcemanager_direction) | Enumerates screen orientations.| 
| typedef enum [ResourceManager_ColorMode](#resourcemanager_colormode) [ResourceManager_ColorMode](#resourcemanager_colormode) | Enumerates color modes.| 
| typedef enum [ResourceManager_DeviceType](#resourcemanager_devicetype) [ResourceManager_DeviceType](#resourcemanager_devicetype) | Enumerates device types.| 
| typedef struct [ResourceManager_Configuration](_resource_manager___configuration.md) [ResourceManager_Configuration](#resourcemanager_configuration) | Enumerates device states.| 


### Enum

| Name| Description| 
| -------- | -------- |
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) {<br>SUCCESS = 0, ERROR_CODE_INVALID_INPUT_PARAMETER = 401, ERROR_CODE_RES_ID_NOT_FOUND = 9001001, ERROR_CODE_RES_NOT_FOUND_BY_ID = 9001002,<br>ERROR_CODE_RES_NAME_NOT_FOUND = 9001003, ERROR_CODE_RES_NOT_FOUND_BY_NAME = 9001004, ERROR_CODE_RES_PATH_INVALID = 9001005, ERROR_CODE_RES_REF_TOO_MUCH = 9001006,<br>ERROR_CODE_RES_ID_FORMAT_ERROR = 9001007, ERROR_CODE_RES_NAME_FORMAT_ERROR = 9001008, ERROR_CODE_SYSTEM_RES_MANAGER_GET_FAILED = 9001009, ERROR_CODE_OVERLAY_RES_PATH_INVALID = 9001010,<br>ERROR_CODE_OUT_OF_MEMORY = 9001100<br>} | Enumerates resource manager error codes.| 
| [ScreenDensity](#screendensity) {<br>SCREEN_SDPI = 120, SCREEN_MDPI = 160, SCREEN_LDPI = 240, SCREEN_XLDPI = 320,<br>SCREEN_XXLDPI = 480, SCREEN_XXXLDPI = 640<br>} | Enumerates screen density types.| 
| [ResourceManager_Direction](#resourcemanager_direction) { DIRECTION_VERTICAL = 0, DIRECTION_HORIZONTAL = 1 } | Enumerates screen orientations.| 
| [ResourceManager_ColorMode](#resourcemanager_colormode) { DARK = 0, LIGHT = 1 } | Enumerates color modes.| 
| [ResourceManager_DeviceType](#resourcemanager_devicetype) {<br>DEVICE_TYPE_PHONE = 0X00, DEVICE_TYPE_TABLET = 0x01, DEVICE_TYPE_CAR = 0x02, DEVICE_TYPE_PC = 0x03,<br>DEVICE_TYPE_TV = 0x04, DEVICE_TYPE_WEARABLE = 0x06, DEVICE_TYPE_2IN1 = 0x07<br>} | Enumerates device types.| 


### Callback

| Name| Description| 
| -------- | -------- |
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetMediaBase64](#oh_resourcemanager_getmediabase64) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, char \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | Obtains the Base64 code of the media resource with the specified screen density based on the specified resource ID.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetMediaBase64Data](#oh_resourcemanager_getmediabase64data) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, char \*\*resultValue, uint64_t \*resultLen, uint32_t density) | Obtains the Base64 code of the media resource with the specified screen density based on the specified resource ID.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetMediaBase64ByName](#oh_resourcemanager_getmediabase64byname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, char \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | Obtains the Base64 code of the media resource with the specified screen density based on the specified resource name.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetMediaBase64DataByName](#oh_resourcemanager_getmediabase64databyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, char \*\*resultValue, uint64_t \*resultLen, uint32_t density) | Obtains the Base64 code of the media resource with the specified screen density based on the specified resource name.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetMedia](#oh_resourcemanager_getmedia) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | Obtains the content of the media resource with the specified screen density based on the specified resource ID.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetMediaData](#oh_resourcemanager_getmediadata) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density) | Obtains the content of the media resource with the specified screen density based on the specified resource ID.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetMediaByName](#oh_resourcemanager_getmediabyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | Obtains the content of the media resource with the specified screen density based on the specified resource name.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetMediaDataByName](#oh_resourcemanager_getmediadatabyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density) | Obtains the content of the media resource with the specified screen density based on the specified resource name.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetDrawableDescriptor](#oh_resourcemanager_getdrawabledescriptor) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density=0, uint32_t type=0) | Obtains the **DrawableDescriptor** object of the icon resource with the specified screen density based on the specified resource ID.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetDrawableDescriptorData](#oh_resourcemanager_getdrawabledescriptordata) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density, uint32_t type) | Obtains the **DrawableDescriptor** object of the icon resource with the specified screen density based on the specified resource ID.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetDrawableDescriptorByName](#oh_resourcemanager_getdrawabledescriptorbyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density=0, uint32_t type=0) | Obtains the **DrawableDescriptor** object of the icon resource with the specified screen density based on the specified resource name.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetDrawableDescriptorDataByName](#oh_resourcemanager_getdrawabledescriptordatabyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density, uint32_t type) | Obtains the **DrawableDescriptor** object of the icon resource with the specified screen density based on the specified resource name.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetSymbol](#oh_resourcemanager_getsymbol) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, uint32_t \*resultValue) | Obtains a **symbol** resource based on the specified resource ID.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetSymbolByName](#oh_resourcemanager_getsymbolbyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, uint32_t \*resultValue) | Obtains a **symbol** resource based on the specified resource name.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetLocales](#oh_resourcemanager_getlocales) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, char \*\*\*resultValue, uint32_t \*resultLen, bool includeSystem=false) | Obtains the language list.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetLocalesData](#oh_resourcemanager_getlocalesdata) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, char \*\*\*resultValue, uint32_t \*resultLen, bool includeSystem) | Obtains the language list.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetConfiguration](#oh_resourcemanager_getconfiguration) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, [ResourceManager_Configuration](_resource_manager___configuration.md) \*configuration) | Obtains the device configuration.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_ReleaseConfiguration](#oh_resourcemanager_releaseconfiguration) ([ResourceManager_Configuration](_resource_manager___configuration.md) \*configuration) | Releases the memory requested by using **OH_ResourceManager_GetConfiguration()**.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetString](#oh_resourcemanager_getstring) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, char \*\*resultValue,...) | Obtains a **string** resource based on the specified resource ID.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetStringByName](#oh_resourcemanager_getstringbyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, char \*\*resultValue,...) | Obtains a **string** resource based on the specified resource name.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetStringArray](#oh_resourcemanager_getstringarray) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, char \*\*\*resultValue, uint32_t \*resultLen) | Obtains a string array based on the specified resource ID.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetStringArrayByName](#oh_resourcemanager_getstringarraybyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, char \*\*\*resultValue, uint32_t \*resultLen) | Obtains a string array based on the specified resource name.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_ReleaseStringArray](#oh_resourcemanager_releasestringarray) (char \*\*\*resValue, uint32_t len) | Releases the memory of the string array.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetPluralString](#oh_resourcemanager_getpluralstring) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, uint32_t num, char \*\*resultValue) | Obtains singular and plural strings based on the specified resource ID.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetPluralStringByName](#oh_resourcemanager_getpluralstringbyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, uint32_t num, char \*\*resultValue) | Obtains singular and plural strings based on the specified resource name.|
| [ResourceManager_ErrorCode](#resourcemanager_errorcode)[OH_ResourceManager_GetIntPluralString](#oh_resourcemanager_getintpluralstring) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, uint32_t num, char \*\*resultValue,...) | Obtains singular and plural strings based on the specified resource ID. | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode)[OH_ResourceManager_GetDoublePluralString](#oh_resourcemanager_getdoublepluralstring) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, double num, char \*\*resultValue,...) | Obtains singular and plural strings based on the specified resource ID. | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode)[OH_ResourceManager_GetIntPluralStringByName](#oh_resourcemanager_getintpluralstringbyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, uint32_t num, char \*\*resultValue,...) | Obtains singular and plural strings based on the specified resource name. | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode)[OH_ResourceManager_GetDoublePluralStringByName](#oh_resourcemanager_getdoublepluralstringbyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, double num, char \*\*resultValue,...) | Obtains singular and plural strings based on the specified resource name. |  
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetColor](#oh_resourcemanager_getcolor) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, uint32_t \*resultValue) | Obtains a color value based on the specified resource ID.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetColorByName](#oh_resourcemanager_getcolorbyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, uint32_t \*resultValue) | Obtains a color value based on the specified resource ID.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetInt](#oh_resourcemanager_getint) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, int \*resultValue) | Obtains an int value based on the specified resource ID.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetIntByName](#oh_resourcemanager_getintbyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, int \*resultValue) | Obtains an int value based on the specified resource name.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetFloat](#oh_resourcemanager_getfloat) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, float \*resultValue) | Obtains a float value based on the specified resource ID.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetFloatByName](#oh_resourcemanager_getfloatbyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, float \*resultValue) | Obtains a float value based on the specified resource name.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetBool](#oh_resourcemanager_getbool) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, bool \*resultValue) | Obtains a bool value based on the specified resource ID.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetBoolByName](#oh_resourcemanager_getboolbyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, bool \*resultValue) | Obtains a bool value based on the specified resource name.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_AddResource](#oh_resourcemanager_addresource) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*path) | Adds overlay resources when an application is running.| 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_RemoveResource](#oh_resourcemanager_removeresource) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*path) | Removes overlay resources when an application is running.| 


## Type Description


### ResourceManager_ColorMode

```
typedef enum ResourceManager_ColorModeResourceManager_ColorMode
```

**Description**

Enumerates color modes.

**Since**: 12


### ResourceManager_Configuration

```
typedef struct ResourceManager_ConfigurationResourceManager_Configuration
```

**Description**

Enumerates device states.

**Since**: 12


### ResourceManager_DeviceType

```
typedef enum ResourceManager_DeviceTypeResourceManager_DeviceType
```

**Description**

Enumerates device types.

**Since**: 12


### ResourceManager_Direction

```
typedef enum ResourceManager_DirectionResourceManager_Direction
```

**Description**

Enumerates screen orientations.

**Since**: 12


## Enum Description


### ResourceManager_ColorMode

```
enum ResourceManager_ColorMode
```

**Description**

Enumerates color modes.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| DARK | Dark mode.| 
| LIGHT | Light mode.| 


### ResourceManager_DeviceType

```
enum ResourceManager_DeviceType
```

**Description**

Enumerates device types.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| DEVICE_TYPE_PHONE | Phone| 
| DEVICE_TYPE_TABLET | Tablet| 
| DEVICE_TYPE_CAR | Automobile| 
| DEVICE_TYPE_PC | Computer| 
| DEVICE_TYPE_TV | TV| 
| DEVICE_TYPE_WEARABLE | Wearable| 
| DEVICE_TYPE_2IN1 | 2-in-1 device| 


### ResourceManager_Direction

```
enum ResourceManager_Direction
```

**Description**

Enumerates screen orientations.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| DIRECTION_VERTICAL | Vertical direction.| 
| DIRECTION_HORIZONTAL | Horizontal direction.| 


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


### OH_ResourceManager_AddResource()

```
ResourceManager_ErrorCode OH_ResourceManager_AddResource (const NativeResourceManager * mgr, const char * path )
```

**Description**

Adds overlay resources when an application is running.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| path | Resource path.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_OVERLAY_RES_PATH_INVALID 9001010 - The resource path is invalid.


### OH_ResourceManager_GetBool()

```
ResourceManager_ErrorCode OH_ResourceManager_GetBool (const NativeResourceManager * mgr, uint32_t resId, bool * resultValue )
```

**Description**

Obtains a bool value based on the specified resource ID.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resId | Resource ID.| 
| resultValue | Result of writing **resultValue**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - The resource ID is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - No matching resource is found based on the resource ID.

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - Resources are cyclically referenced.


### OH_ResourceManager_GetBoolByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetBoolByName (const NativeResourceManager * mgr, const char * resName, bool * resultValue )
```

**Description**

Obtains a bool value based on the specified resource name.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resName | Resource name.| 
| resultValue | Result of writing **resultValue**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001003 - The resource name is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004 - No matching resource is found based on the resource name.

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - Resources are cyclically referenced.


### OH_ResourceManager_GetColor()

```
ResourceManager_ErrorCode OH_ResourceManager_GetColor (const NativeResourceManager * mgr, uint32_t resId, uint32_t * resultValue )
```

**Description**

Obtains a color value based on the specified resource ID.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resId | Resource ID.| 
| resultValue | Result of writing **resultValue**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - The resource ID is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - No matching resource is found based on the resource ID.

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - Resources are cyclically referenced.


### OH_ResourceManager_GetColorByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetColorByName (const NativeResourceManager * mgr, const char * resName, uint32_t * resultValue )
```

**Description**

Obtains a color value based on the specified resource ID.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resName | Resource name.| 
| resultValue | Result of writing **resultValue**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001003 - The resource name is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004 - No matching resource is found based on the resource name.

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - Resources are cyclically referenced.


### OH_ResourceManager_GetConfiguration()

```
ResourceManager_ErrorCode OH_ResourceManager_GetConfiguration (const NativeResourceManager * mgr, ResourceManager_Configuration * configuration )
```

**Description**

Obtains the device configuration.

After using this API, you need to call **OH_ResourceManager_ReleaseConfiguration()** to release the memory. If the **ResourceManager_Configuration** object is created by using malloc, call **free()** to release the object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| configuration | Device configuration.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_SYSTEM_RES_MANAGER_GET_FAILED 9001009 - Failed to access system resources.

ERROR_CODE_OUT_OF_MEMORY 9001100: The memory overflows.


### OH_ResourceManager_GetDoublePluralString()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDoublePluralString (const NativeResourceManager * mgr, uint32_t resId, double num, char ** resultValue,  ... )
```

**Description**

Obtains singular and plural strings based on the specified resource ID.

After using this API, you need to call **free()** to release the memory of the strings.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager). | 
| resId | Resource ID. | 
| num | Quantity value (a floating point number), Its string representation is obtained based on the current language's plural rules. | 
| resultValue | Result of writing **resultValue**. | 
| ... | Variable representing formatted string resources. Supported types include const char\*, int, and float. | 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - The resource ID is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - No matching resource is found based on the resource ID.

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - Resources are cyclically referenced.

ERROR_CODE_OUT_OF_MEMORY 9001100: The memory overflows.


### OH_ResourceManager_GetDoublePluralStringByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDoublePluralStringByName (const NativeResourceManager * mgr, const char * resName, double num, char ** resultValue,  ... )
```
**Description**

Obtains singular and plural strings based on the specified resource name.

After using this API, you need to call **free()** to release the memory of the strings.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager). | 
| resName | Resource name. | 
| num | Quantity value (a floating point number), Its string representation is obtained based on the current language's plural rules. | 
| resultValue | Result of writing **resultValue**. | 
| ... | Variable representing formatted string resources. Supported types include const char\*, int, and float. | 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001003 - The resource name is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004 - No matching resource is found based on the resource name.

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - Resources are cyclically referenced.

ERROR_CODE_OUT_OF_MEMORY 9001100: The memory overflows.


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
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resId | Resource ID.| 
| density | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](#screendensity). The default value is **0**, indicating that the current system screen density (in DPI) is used.| 
| type | Icon type. The value **0** indicates an application icon, and the value **1** indicates a theme icon.| 
| drawableDescriptor | Result of writing **drawableDescriptor**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - The resource ID is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - No matching resource is found based on the resource ID.


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
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resName | Resource name.| 
| density | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](#screendensity). The default value is **0**, indicating that the current system screen density (in DPI) is used.| 
| type | Icon type. This parameter is optional. The value **0** indicates an application icon, the value **1** indicates a theme icon, and the value **2** indicates a dynamic icon.| 
| drawableDescriptor | Result of writing **drawableDescriptor**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001003: The resource name is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004: No matching resource is found based on the resource name.


### OH_ResourceManager_GetDrawableDescriptorData()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorData (const NativeResourceManager * mgr, uint32_t resId, ArkUI_DrawableDescriptor ** drawableDescriptor, uint32_t density, uint32_t type )
```

**Description**

Obtains the **DrawableDescriptor** object of the icon resource with the specified screen density based on the specified resource ID.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resId | Resource ID.| 
| drawableDescriptor | Result of writing **drawableDescriptor**.| 
| density | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](#screendensity). The default value is **0**, indicating that the current system screen density (in DPI) is used. If this parameter is not required, set it to **0**.| 
| type | Icon type. This parameter is optional. The value **0** indicates an application icon, and the value **1** indicates a theme icon. If this parameter is not required, set it to **0**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - The resource ID is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - No matching resource is found based on the resource ID.


### OH_ResourceManager_GetDrawableDescriptorDataByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorDataByName (const NativeResourceManager * mgr, const char * resName, ArkUI_DrawableDescriptor ** drawableDescriptor, uint32_t density, uint32_t type )
```

**Description**

Obtains the **DrawableDescriptor** object of the icon resource with the specified screen density based on the specified resource name.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resName | Resource name.| 
| drawableDescriptor | Result of writing **drawableDescriptor**.| 
| density | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](#screendensity). The default value is **0**, indicating that the current system screen density (in DPI) is used. If this parameter is not required, set it to **0**.| 
| type | Icon type. This parameter is optional. The value **0** indicates an application icon, and the value **1** indicates a theme icon. If this parameter is not required, set it to **0**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001003: The resource name is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004: No matching resource is found based on the resource name.


### OH_ResourceManager_GetFloat()

```
ResourceManager_ErrorCode OH_ResourceManager_GetFloat (const NativeResourceManager * mgr, uint32_t resId, float * resultValue )
```

**Description**

Obtains a float value based on the specified resource ID.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resId | Resource ID.| 
| resultValue | Result of writing **resultValue**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - The resource ID is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - No matching resource is found based on the resource ID.

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - Resources are cyclically referenced.


### OH_ResourceManager_GetFloatByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetFloatByName (const NativeResourceManager * mgr, const char * resName, float * resultValue )
```

**Description**

Obtains a float value based on the specified resource name.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resName | Resource name.| 
| resultValue | Result of writing **resultValue**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001003 - The resource name is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004 - No matching resource is found based on the resource name.

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - Resources are cyclically referenced.


### OH_ResourceManager_GetInt()

```
ResourceManager_ErrorCode OH_ResourceManager_GetInt (const NativeResourceManager * mgr, uint32_t resId, int * resultValue )
```

**Description**

Obtains an int value based on the specified resource ID.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resId | Resource ID.| 
| resultValue | Result of writing **resultValue**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - The resource ID is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - No matching resource is found based on the resource ID.

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - Resources are cyclically referenced.


### OH_ResourceManager_GetIntByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetIntByName (const NativeResourceManager * mgr, const char * resName, int * resultValue )
```

**Description**

Obtains an int value based on the specified resource name.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resName | Resource name.| 
| resultValue | Result of writing **resultValue**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001003 - The resource name is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004 - No matching resource is found based on the resource name.

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - Resources are cyclically referenced.


### OH_ResourceManager_GetIntPluralString()

```
ResourceManager_ErrorCode OH_ResourceManager_GetIntPluralString (const NativeResourceManager * mgr, uint32_t resId, uint32_t num, char ** resultValue,  ... )
```

**Description**

Obtains singular and plural strings based on the specified resource ID.

After using this API, you need to call **free()** to release the memory of the strings.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager). | 
| resId | Resource ID. | 
| num | Quantity value (an integer). Its string representation is obtained based on the current language's plural rules. | 
| resultValue | Result of writing **resultValue**. | 
| ... | Variable representing formatted string resources. Supported types include const char\*, int, and float. | 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - The resource ID is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - No matching resource is found based on the resource ID.

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - Resources are cyclically referenced.

ERROR_CODE_OUT_OF_MEMORY 9001100: The memory overflows.


### OH_ResourceManager_GetIntPluralStringByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetIntPluralStringByName (const NativeResourceManager * mgr, const char * resName, uint32_t num, char ** resultValue,  ... )
```
**Description**

Obtains singular and plural strings based on the specified resource name.

After using this API, you need to call **free()** to release the memory of the strings.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager). | 
| resName | Resource name. | 
| num | Quantity value (an integer). Its string representation is obtained based on the current language's plural rules. | 
| resultValue | Result of writing **resultValue**. | 
| ... | Variable representing formatted string resources. Supported types include const char\*, int, and float. | 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001003 - The resource name is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004 - No matching resource is found based on the resource name.

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - Resources are cyclically referenced.

ERROR_CODE_OUT_OF_MEMORY 9001100: The memory overflows.


### OH_ResourceManager_GetLocales()

```
ResourceManager_ErrorCode OH_ResourceManager_GetLocales (const NativeResourceManager * mgr, char *** resultValue, uint32_t * resultLen, bool includeSystem = false )
```

**Description**

Obtains the language list.

After using this API, you need to call **OH_ResourceManager_ReleaseStringArray()** to release the memory of **localinfo**.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resultValue | Result of writing **resultValue**.| 
| resultLen | Length of locales written to **resultLen**.| 
| includeSystem | Whether system resources are included. The default value is **false**. This parameter does not take effect if only system resources are involved when you query the list of locales.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_OUT_OF_MEMORY 9001100: The memory overflows.


### OH_ResourceManager_GetLocalesData()

```
ResourceManager_ErrorCode OH_ResourceManager_GetLocalesData (const NativeResourceManager * mgr, char *** resultValue, uint32_t * resultLen, bool includeSystem )
```

**Description**

Obtains the language list.

After using this API, you need to call **OH_ResourceManager_ReleaseStringArray()** to release the memory of **localinfo**.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resultValue | Result of writing **resultValue**.| 
| resultLen | Length of locales written to **resultLen**.| 
| includeSystem | Whether system resources are included. If this parameter is not required, set it to **false**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_OUT_OF_MEMORY 9001100: The memory overflows.


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
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resId | Resource ID.| 
| density | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](#screendensity). The default value is **0**, indicating that the current system screen density (in DPI) is used.| 
| resultValue | Result of writing **resultValue**.| 
| resultLen | Length of media written to **resultLen**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - The resource ID is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - No matching resource is found based on the resource ID.

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
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resId | Resource ID.| 
| density | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](#screendensity). The default value is **0**, indicating that the current system screen density (in DPI) is used.| 
| resultValue | Result of writing **resultValue**.| 
| resultLen | Length of media written to **resultLen**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - The resource ID is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - No matching resource is found based on the resource ID.

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
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resName | Resource name.| 
| density | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](#screendensity). The default value is **0**, indicating that the current system screen density (in DPI) is used.| 
| resultValue | Result of writing **resultValue**.| 
| resultLen | Length of media written to **resultLen**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001003: The resource name is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004: No matching resource is found based on the resource name.

ERROR_CODE_OUT_OF_MEMORY 9001100: The memory overflows.


### OH_ResourceManager_GetMediaBase64Data()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64Data (const NativeResourceManager * mgr, uint32_t resId, char ** resultValue, uint64_t * resultLen, uint32_t density )
```

**Description**

Obtains the Base64 code of the media resource with the specified screen density based on the specified resource ID.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resId | Resource ID.| 
| resultValue | Result of writing **resultValue**.| 
| resultLen | Length of media written to **resultLen**.| 
| density | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](#screendensity). The default value is **0**, indicating that the current system screen density (in DPI) is used. If this parameter is not required, set it to **0**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - The resource ID is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - No matching resource is found based on the resource ID.

ERROR_CODE_OUT_OF_MEMORY 9001100: The memory overflows.


### OH_ResourceManager_GetMediaBase64DataByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64DataByName (const NativeResourceManager * mgr, const char * resName, char ** resultValue, uint64_t * resultLen, uint32_t density )
```

**Description**

Obtains the Base64 code of the media resource with the specified screen density based on the specified resource name.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resName | Resource name.| 
| resultValue | Result of writing **resultValue**.| 
| resultLen | Length of media written to **resultLen**.| 
| density | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](#screendensity). The default value is **0**, indicating that the current system screen density (in DPI) is used. If this parameter is not required, set it to **0**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001003: The resource name is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004: No matching resource is found based on the resource name.

ERROR_CODE_OUT_OF_MEMORY 9001100: The memory overflows.


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
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resName | Resource name.| 
| density | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](#screendensity). The default value is **0**, indicating that the current system screen density (in DPI) is used.| 
| resultValue | Result of writing **resultValue**.| 
| resultLen | Length of media written to **resultLen**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001003: The resource name is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004: No matching resource is found based on the resource name.

ERROR_CODE_OUT_OF_MEMORY 9001100: The memory overflows.


### OH_ResourceManager_GetMediaData()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaData (const NativeResourceManager * mgr, uint32_t resId, uint8_t ** resultValue, uint64_t * resultLen, uint32_t density )
```

**Description**

Obtains the content of the media resource with the specified screen density based on the specified resource ID.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resId | Resource ID.| 
| resultValue | Result of writing **resultValue**.| 
| resultLen | Length of media written to **resultLen**.| 
| density | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](#screendensity). The default value is **0**, indicating that the current system screen density (in DPI) is used. If this parameter is not required, set it to **0**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - The resource ID is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - No matching resource is found based on the resource ID.

ERROR_CODE_OUT_OF_MEMORY 9001100: The memory overflows.


### OH_ResourceManager_GetMediaDataByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaDataByName (const NativeResourceManager * mgr, const char * resName, uint8_t ** resultValue, uint64_t * resultLen, uint32_t density )
```

**Description**

Obtains the content of the media resource with the specified screen density based on the specified resource name.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resName | Resource name.| 
| resultValue | Result of writing **resultValue**.| 
| resultLen | Length of media written to **resultLen**.| 
| density | Screen density. This parameter is optional. For details about the value range, see [ScreenDensity](#screendensity). The default value is **0**, indicating that the current system screen density (in DPI) is used. If this parameter is not required, set it to **0**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001003: The resource name is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004: No matching resource is found based on the resource name.

ERROR_CODE_OUT_OF_MEMORY 9001100: The memory overflows.


### OH_ResourceManager_GetPluralString()

```
ResourceManager_ErrorCode OH_ResourceManager_GetPluralString (const NativeResourceManager * mgr, uint32_t resId, uint32_t num, char ** resultValue )
```

**Description**

Obtains singular and plural strings based on the specified resource ID.

After using this API, you need to call **free()** to release the memory of the strings.

**Since**: 12

**Deprecated version**: 18

**Substitute APIs**: [OH_ResourceManager_GetIntPluralString](#oh_resourcemanager_getintpluralstring)

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager). | 
| resId | Resource ID. | 
| num | Number. | 
| resultValue | Result of writing **resultValue**. | 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - The resource ID is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - No matching resource is found based on the resource ID.

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - Resources are cyclically referenced.

ERROR_CODE_OUT_OF_MEMORY 9001100: The memory overflows.


### OH_ResourceManager_GetPluralStringByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetPluralStringByName (const NativeResourceManager * mgr, const char * resName, uint32_t num, char ** resultValue )
```
**Description**

Obtains singular and plural strings based on the specified resource name.

After using this API, you need to call **free()** to release the memory of the strings.

**Since**: 12

**Deprecated version**: 18

**Substitute APIs**: [OH_ResourceManager_GetIntPluralStringByName](#oh_resourcemanager_getintpluralstringbyname)

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager). | 
| resName | Resource name. | 
| num | Number. | 
| resultValue | Result of writing **resultValue**. | 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001003 - The resource name is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004 - No matching resource is found based on the resource name.

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - Resources are cyclically referenced.

ERROR_CODE_OUT_OF_MEMORY 9001100: The memory overflows.


### OH_ResourceManager_GetString()

```
ResourceManager_ErrorCode OH_ResourceManager_GetString (const NativeResourceManager * mgr, uint32_t resId, char ** resultValue,  ... )
```

**Description**

Obtains a **string** resource based on the specified resource ID.

The obtain common string resources, use **OH_ResourceManager_GetString(mgr, resId, resultValue)**. The obtain formatted string resources with the **d**, **s**, and **f** placeholders, use **OH_ResourceManager_GetString(mgr, resId, resultValue, 10, "format", 10.10)**. After using this API, you need to call **free()** to release the memory.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resId | Resource ID.| 
| resultValue | Result of writing **resultValue**.| 
| ... | Variable representing formatted string resources. Supported types include const char\*, int, and float.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - The resource ID is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - No matching resource is found based on the resource ID.

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - Resources are cyclically referenced.

ERROR_CODE_OUT_OF_MEMORY 9001100: The memory overflows.


### OH_ResourceManager_GetStringArray()

```
ResourceManager_ErrorCode OH_ResourceManager_GetStringArray (const NativeResourceManager * mgr, uint32_t resId, char *** resultValue, uint32_t * resultLen )
```

**Description**

Obtains a string array based on the specified resource ID.

After using this API, you need to call **OH_ResourceManager_ReleaseStringArray()** to release the memory of the string array.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resId | Resource ID.| 
| resultValue | Result of writing **resultValue**.| 
| resultLen | Length of **StringArray** written to **resultLen**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - The resource ID is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - No matching resource is found based on the resource ID.

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - Resources are cyclically referenced.

ERROR_CODE_OUT_OF_MEMORY 9001100: The memory overflows.


### OH_ResourceManager_GetStringArrayByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetStringArrayByName (const NativeResourceManager * mgr, const char * resName, char *** resultValue, uint32_t * resultLen )
```

**Description**

Obtains a string array based on the specified resource name.

After using this API, you need to call **OH_ResourceManager_ReleaseStringArray()** to release the memory of the string array.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resName | Resource name.| 
| resultValue | Result of writing **resultValue**.| 
| resultLen | Length of **StringArray** written to **resultLen**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001003 - The resource name is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004 - No matching resource is found based on the resource name.

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - Resources are cyclically referenced.

ERROR_CODE_OUT_OF_MEMORY 9001100: The memory overflows.


### OH_ResourceManager_GetStringByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetStringByName (const NativeResourceManager * mgr, const char * resName, char ** resultValue,  ... )
```

**Description**

Obtains a **string** resource based on the specified resource name.

The obtain common string resources, use **OH_ResourceManager_GetString(mgr, resName, resultValue)**. The obtain formatted string resources with the **%d**, **%s**, and **%f** placeholders, use **OH_ResourceManager_GetString(mgr, resName, resultValue, 10, "format", 10.10)**. After using this API, you need to call **free()** to release the memory.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resName | Resource name.| 
| resultValue | Result of writing **resultValue**.| 
| ... | Variable representing formatted string resources. Supported types include const char\*, int, and float.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001003 - The resource name is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004 - No matching resource is found based on the resource name.

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - Resources are cyclically referenced.

ERROR_CODE_OUT_OF_MEMORY 9001100: The memory overflows.


### OH_ResourceManager_GetSymbol()

```
ResourceManager_ErrorCode OH_ResourceManager_GetSymbol (const NativeResourceManager * mgr, uint32_t resId, uint32_t * resultValue )
```

**Description**

Obtains a **symbol** resource based on the specified resource ID.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resId | Resource ID.| 
| resultValue | Result of writing **resultValue**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - The resource ID is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - No matching resource is found based on the resource ID.

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - Resources are cyclically referenced.


### OH_ResourceManager_GetSymbolByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetSymbolByName (const NativeResourceManager * mgr, const char * resName, uint32_t * resultValue )
```

**Description**

Obtains a **symbol** resource based on the specified resource name.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| resName | Resource name.| 
| resultValue | Result of writing **resultValue**.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_RES_ID_NOT_FOUND 9001003: The resource name is invalid.

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004: No matching resource is found based on the resource name.

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - Resources are cyclically referenced.


### OH_ResourceManager_ReleaseConfiguration()

```
ResourceManager_ErrorCode OH_ResourceManager_ReleaseConfiguration (ResourceManager_Configuration * configuration)
```

**Description**

Releases the memory requested by using **OH_ResourceManager_GetConfiguration()**.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| configuration | Configuration object whose memory needs to be released.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.


### OH_ResourceManager_ReleaseStringArray()

```
ResourceManager_ErrorCode OH_ResourceManager_ReleaseStringArray (char *** resValue, uint32_t len )
```

**Description**

Releases the memory of the string array.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| resValue | String array whose memory needs to be released.| 
| len | Length of the string array.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.


### OH_ResourceManager_RemoveResource()

```
ResourceManager_ErrorCode OH_ResourceManager_RemoveResource (const NativeResourceManager * mgr, const char * path )
```

**Description**

Removes overlay resources when an application is running.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mgr | Pointer to the [NativeResourceManager](rawfile.md#nativeresourcemanager) object. You can obtain the pointer by using [OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager).| 
| path | Resource path.| 

**Returns**

SUCCESS = 0: Operation succeeded.

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - The input parameter is invalid. Possible causes: 1. The parameter type is incorrect. 2. Parameter verification failed.

ERROR_CODE_OVERLAY_RES_PATH_INVALID 9001010 - The resource path is invalid.
