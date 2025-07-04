# Resourcemanager


## 概述

提供c相关获取资源的接口。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [ohresmgr.h](ohresmgr_8h.md) | 提供资源管理native侧获取资源的能力。 | 
| [resmgr_common.h](resmgr__common_8h.md) | 提供接口所需要的枚举类型和结构体。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ResourceManager_Configuration](_resource_manager___configuration.md) | 设备状态的枚举。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [ResourceManager_Direction](#resourcemanager_direction) [ResourceManager_Direction](#resourcemanager_direction) | 屏幕方向的枚举。 | 
| typedef enum [ResourceManager_ColorMode](#resourcemanager_colormode) [ResourceManager_ColorMode](#resourcemanager_colormode) | 颜色模式的枚举。 | 
| typedef enum [ResourceManager_DeviceType](#resourcemanager_devicetype) [ResourceManager_DeviceType](#resourcemanager_devicetype) | 设备类型的枚举。 | 
| typedef struct [ResourceManager_Configuration](_resource_manager___configuration.md) [ResourceManager_Configuration](#resourcemanager_configuration) | 设备状态的枚举。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) {<br/>SUCCESS = 0, ERROR_CODE_INVALID_INPUT_PARAMETER = 401, ERROR_CODE_RES_ID_NOT_FOUND = 9001001, ERROR_CODE_RES_NOT_FOUND_BY_ID = 9001002,<br/>ERROR_CODE_RES_NAME_NOT_FOUND = 9001003, ERROR_CODE_RES_NOT_FOUND_BY_NAME = 9001004, ERROR_CODE_RES_PATH_INVALID = 9001005, ERROR_CODE_RES_REF_TOO_MUCH = 9001006,<br/>ERROR_CODE_RES_ID_FORMAT_ERROR = 9001007, ERROR_CODE_RES_NAME_FORMAT_ERROR = 9001008, ERROR_CODE_SYSTEM_RES_MANAGER_GET_FAILED = 9001009, ERROR_CODE_OVERLAY_RES_PATH_INVALID = 9001010,<br/>ERROR_CODE_OUT_OF_MEMORY = 9001100<br/>} | 资源管理错误码。 | 
| [ScreenDensity](#screendensity) {<br/>SCREEN_SDPI = 120, SCREEN_MDPI = 160, SCREEN_LDPI = 240, SCREEN_XLDPI = 320,<br/>SCREEN_XXLDPI = 480, SCREEN_XXXLDPI = 640<br/>} | 屏幕密度类型的枚举。 | 
| [ResourceManager_Direction](#resourcemanager_direction) { DIRECTION_VERTICAL = 0, DIRECTION_HORIZONTAL = 1 } | 屏幕方向的枚举。 | 
| [ResourceManager_ColorMode](#resourcemanager_colormode) { COLOR_MODE_DARK = 0, COLOR_MODE_LIGHT = 1 } | 颜色模式的枚举。 | 
| [ResourceManager_DeviceType](#resourcemanager_devicetype) {<br/>DEVICE_TYPE_PHONE = 0X00, DEVICE_TYPE_TABLET = 0x01, DEVICE_TYPE_CAR = 0x02, DEVICE_TYPE_PC = 0x03,<br/>DEVICE_TYPE_TV = 0x04, DEVICE_TYPE_WEARABLE = 0x06, DEVICE_TYPE_2IN1 = 0x07<br/>} | 设备类型的枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetMediaBase64](#oh_resourcemanager_getmediabase64) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, char \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | 通过指定资源ID，获取屏幕密度对应的media资源的Base64码。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetMediaBase64Data](#oh_resourcemanager_getmediabase64data) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, char \*\*resultValue, uint64_t \*resultLen, uint32_t density) | 通过指定资源ID，获取屏幕密度对应的media资源的Base64码。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetMediaBase64ByName](#oh_resourcemanager_getmediabase64byname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, char \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | 通过指定资源名称，获取屏幕密度对应的media资源的Base64码。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetMediaBase64DataByName](#oh_resourcemanager_getmediabase64databyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, char \*\*resultValue, uint64_t \*resultLen, uint32_t density) | 通过指定资源名称，获取屏幕密度对应的media资源的Base64码。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetMedia](#oh_resourcemanager_getmedia) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | 通过指定资源ID，获取屏幕密度对应的media资源的内容。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetMediaData](#oh_resourcemanager_getmediadata) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density) | 通过指定资源ID，获取屏幕密度对应的media资源的内容。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetMediaByName](#oh_resourcemanager_getmediabyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | 通过指定资源名称，获取屏幕密度对应的media资源的内容。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetMediaDataByName](#oh_resourcemanager_getmediadatabyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density) | 通过指定资源名称，获取屏幕密度对应的media资源的内容。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetDrawableDescriptor](#oh_resourcemanager_getdrawabledescriptor) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density=0, uint32_t type=0) | 通过指定资源Id，获取屏幕密度对应的图标资源的DrawableDescriptor。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetDrawableDescriptorData](#oh_resourcemanager_getdrawabledescriptordata) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density, uint32_t type) | 通过指定资源Id，获取屏幕密度对应的图标资源的DrawableDescriptor。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetDrawableDescriptorByName](#oh_resourcemanager_getdrawabledescriptorbyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density=0, uint32_t type=0) | 通过指定资源名称，获取屏幕密度对应的图标资源的DrawableDescriptor。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetDrawableDescriptorDataByName](#oh_resourcemanager_getdrawabledescriptordatabyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density, uint32_t type) | 通过指定资源名称，获取屏幕密度对应的图标资源的DrawableDescriptor。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetSymbol](#oh_resourcemanager_getsymbol) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, uint32_t \*resultValue) | 通过指定资源ID，获取对应的symbol资源。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetSymbolByName](#oh_resourcemanager_getsymbolbyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, uint32_t \*resultValue) | 通过指定资源名称，获取对应的symbol资源。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetLocales](#oh_resourcemanager_getlocales) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, char \*\*\*resultValue, uint32_t \*resultLen, bool includeSystem=false) | 获取语言列表。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetLocalesData](#oh_resourcemanager_getlocalesdata) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, char \*\*\*resultValue, uint32_t \*resultLen, bool includeSystem) | 获取语言列表。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetConfiguration](#oh_resourcemanager_getconfiguration) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, [ResourceManager_Configuration](_resource_manager___configuration.md) \*configuration) | 获取设备配置。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_ReleaseConfiguration](#oh_resourcemanager_releaseconfiguration) ([ResourceManager_Configuration](_resource_manager___configuration.md) \*configuration) | 释放OH_ResourceManager_GetConfiguration()方法申请的内存。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetString](#oh_resourcemanager_getstring) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, char \*\*resultValue,...) | 通过指定资源ID，获取对应的string资源。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetStringByName](#oh_resourcemanager_getstringbyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, char \*\*resultValue,...) | 通过指定资源名称，获取对应的string资源。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetStringArray](#oh_resourcemanager_getstringarray) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, char \*\*\*resultValue, uint32_t \*resultLen) | 通过指定资源ID，获取字符串数组。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetStringArrayByName](#oh_resourcemanager_getstringarraybyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, char \*\*\*resultValue, uint32_t \*resultLen) | 通过指定资源名称，获取字符串数组。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_ReleaseStringArray](#oh_resourcemanager_releasestringarray) (char \*\*\*resValue, uint32_t len) | 释放字符串数组内存。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetPluralString](#oh_resourcemanager_getpluralstring) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, uint32_t num, char \*\*resultValue) | 通过指定资源ID，获取对应的单复数字符串。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetPluralStringByName](#oh_resourcemanager_getpluralstringbyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, uint32_t num, char \*\*resultValue) | 通过指定资源名称，获取对应的单复数字符串。 |
| [ResourceManager_ErrorCode](#resourcemanager_errorcode)[OH_ResourceManager_GetIntPluralString](#oh_resourcemanager_getintpluralstring) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, uint32_t num, char \*\*resultValue,...) | 通过指定资源ID，获取对应的单复数字符串。  | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode)[OH_ResourceManager_GetDoublePluralString](#oh_resourcemanager_getdoublepluralstring) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, double num, char \*\*resultValue,...) | 通过指定资源ID，获取对应的单复数字符串。  | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode)[OH_ResourceManager_GetIntPluralStringByName](#oh_resourcemanager_getintpluralstringbyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, uint32_t num, char \*\*resultValue,...) | 通过指定资源名称，获取对应的单复数字符串。  | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode)[OH_ResourceManager_GetDoublePluralStringByName](#oh_resourcemanager_getdoublepluralstringbyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, double num, char \*\*resultValue,...) | 通过指定资源名称，获取对应的单复数字符串。  |  
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetColor](#oh_resourcemanager_getcolor) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, uint32_t \*resultValue) | 通过指定资源ID，获取对应的颜色值。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetColorByName](#oh_resourcemanager_getcolorbyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, uint32_t \*resultValue) | 通过指定资源ID，获取对应的颜色值。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetInt](#oh_resourcemanager_getint) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, int \*resultValue) | 通过指定资源ID，获取对应的int值。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetIntByName](#oh_resourcemanager_getintbyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, int \*resultValue) | 通过指定资源名称，获取对应的int值。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetFloat](#oh_resourcemanager_getfloat) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, float \*resultValue) | 通过指定资源ID，获取对应的float值。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetFloatByName](#oh_resourcemanager_getfloatbyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, float \*resultValue) | 通过指定资源名称，获取对应的float值。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetBool](#oh_resourcemanager_getbool) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, uint32_t resId, bool \*resultValue) | 通过指定资源ID，获取对应的bool值。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_GetBoolByName](#oh_resourcemanager_getboolbyname) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*resName, bool \*resultValue) | 通过指定资源名称，获取对应的bool值。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_AddResource](#oh_resourcemanager_addresource) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*path) | 在应用程序运行时添加overlay资源。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) [OH_ResourceManager_RemoveResource](#oh_resourcemanager_removeresource) (const [NativeResourceManager](rawfile.md#nativeresourcemanager) \*mgr, const char \*path) | 在应用程序运行时删除overlay资源。 | 


## 类型定义说明


### ResourceManager_ColorMode

```
typedef enum ResourceManager_ColorModeResourceManager_ColorMode
```

**描述**

颜色模式的枚举。

**起始版本：** 12


### ResourceManager_Configuration

```
typedef struct ResourceManager_ConfigurationResourceManager_Configuration
```

**描述**

设备状态的枚举。

**起始版本：** 12


### ResourceManager_DeviceType

```
typedef enum ResourceManager_DeviceTypeResourceManager_DeviceType
```

**描述**

设备类型的枚举。

**起始版本：** 12


### ResourceManager_Direction

```
typedef enum ResourceManager_DirectionResourceManager_Direction
```

**描述**

屏幕方向的枚举。

**起始版本：** 12


## 枚举类型说明


### ResourceManager_ColorMode

```
enum ResourceManager_ColorMode
```

**描述**

颜色模式的枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| COLOR_MODE_DARK | 表示深色模式。 | 
| COLOR_MODE_LIGHT | 表示浅色模式。 | 


### ResourceManager_DeviceType

```
enum ResourceManager_DeviceType
```

**描述**

设备类型的枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| DEVICE_TYPE_PHONE | 手机。 | 
| DEVICE_TYPE_TABLET | 平板。 | 
| DEVICE_TYPE_CAR | 汽车。 | 
| DEVICE_TYPE_PC | 电脑。 | 
| DEVICE_TYPE_TV | 电视。 | 
| DEVICE_TYPE_WEARABLE | 穿戴。 | 
| DEVICE_TYPE_2IN1 | 2in1设备。 | 


### ResourceManager_Direction

```
enum ResourceManager_Direction
```

**描述**

屏幕方向的枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| DIRECTION_VERTICAL | 表示垂直方向。 | 
| DIRECTION_HORIZONTAL | 表示水平方向。 | 


### ResourceManager_ErrorCode

```
enum ResourceManager_ErrorCode
```

**描述**

资源管理错误码。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| SUCCESS | 成功。 | 
| ERROR_CODE_INVALID_INPUT_PARAMETER | 输入参数无效。 | 
| ERROR_CODE_RES_ID_NOT_FOUND | 无效的资源ID。 | 
| ERROR_CODE_RES_NOT_FOUND_BY_ID | 无效的资源名称。 | 
| ERROR_CODE_RES_NAME_NOT_FOUND | 没有根据资源ID找到匹配的资源。 | 
| ERROR_CODE_RES_NOT_FOUND_BY_NAME | 没有根据资源名称找到匹配的资源。 | 
| ERROR_CODE_RES_PATH_INVALID | 无效的相对路径。 | 
| ERROR_CODE_RES_REF_TOO_MUCH | 资源被循环引用。 | 
| ERROR_CODE_RES_ID_FORMAT_ERROR | 无法格式化基于资源ID获得的资源。 | 
| ERROR_CODE_RES_NAME_FORMAT_ERROR | 无法格式化基于资源名称获得的资源。 | 
| ERROR_CODE_SYSTEM_RES_MANAGER_GET_FAILED | 访问系统资源失败。 | 
| ERROR_CODE_OVERLAY_RES_PATH_INVALID | 无效的overlay路径。 | 
| ERROR_CODE_OUT_OF_MEMORY | 内存溢出。 | 


### ScreenDensity

```
enum ScreenDensity
```

**描述**

屏幕密度类型的枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| SCREEN_SDPI | 表示小屏幕密度。 | 
| SCREEN_MDPI | 表示中屏幕密度。 | 
| SCREEN_LDPI | 表示大屏幕密度。 | 
| SCREEN_XLDPI | 表示特大屏幕密度。 | 
| SCREEN_XXLDPI | 表示超大屏幕密度。 | 
| SCREEN_XXXLDPI | 表示超特大屏幕密度。 | 


## 函数说明


### OH_ResourceManager_AddResource()

```
ResourceManager_ErrorCode OH_ResourceManager_AddResource (const NativeResourceManager * mgr, const char * path )
```

**描述**

在应用程序运行时添加overlay资源。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| path | 资源路径。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_OVERLAY_RES_PATH_INVALID 9001010 - 无效的资源路径。


### OH_ResourceManager_GetBool()

```
ResourceManager_ErrorCode OH_ResourceManager_GetBool (const NativeResourceManager * mgr, uint32_t resId, bool * resultValue )
```

**描述**

通过指定资源ID，获取对应的bool值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resId | 资源ID。 | 
| resultValue | 写入resultValue的结果。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - 无效的资源ID。

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - 没有根据资源ID找到匹配的资源。

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - 资源被循环引用。


### OH_ResourceManager_GetBoolByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetBoolByName (const NativeResourceManager * mgr, const char * resName, bool * resultValue )
```

**描述**

通过指定资源名称，获取对应的bool值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resName | 资源名称。 | 
| resultValue | 写入resultValue的结果。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_ID_NOT_FOUND 9001003 - 无效的资源名称。

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004 - 没有根据资源名称找到匹配的资源。

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - 资源被循环引用。


### OH_ResourceManager_GetColor()

```
ResourceManager_ErrorCode OH_ResourceManager_GetColor (const NativeResourceManager * mgr, uint32_t resId, uint32_t * resultValue )
```

**描述**

通过指定资源ID，获取对应的颜色值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resId | 资源ID。 | 
| resultValue | 写入resultValue的结果。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - 无效的资源ID。

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - 没有根据资源ID找到匹配的资源。

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - 资源被循环引用。


### OH_ResourceManager_GetColorByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetColorByName (const NativeResourceManager * mgr, const char * resName, uint32_t * resultValue )
```

**描述**

通过指定资源ID，获取对应的颜色值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resName | 资源名称。 | 
| resultValue | 写入resultValue的结果。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_ID_NOT_FOUND 9001003 - 无效的资源名称。

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004 - 没有根据资源名称找到匹配的资源。

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - 资源被循环引用。


### OH_ResourceManager_GetConfiguration()

```
ResourceManager_ErrorCode OH_ResourceManager_GetConfiguration (const NativeResourceManager * mgr, ResourceManager_Configuration * configuration )
```

**描述**

获取设备配置。

使用此接口后，需要调用OH_ResourceManager_ReleaseConfiguration()方法来释放内存。如果使用malloc创建ResourceManager_Configuration对象，还需要调用free()方法来释放它。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| configuration | 写入configuration的结果。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_SYSTEM_RES_MANAGER_GET_FAILED 9001009 - 无法访问系统资源。

ERROR_CODE_OUT_OF_MEMORY 9001100 - 内存溢出。


### OH_ResourceManager_GetDoublePluralString()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDoublePluralString (const NativeResourceManager * mgr, uint32_t resId, double num, char ** resultValue,  ... )
```

**描述**

通过指定资源ID，获取对应的单复数字符串。

使用此接口后，需要调用free()方法来释放字符串的内存。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。  | 
| resId | 资源ID。  | 
| num | 数量值（浮点数）。根据当前语言的复数规则获取该数量值对应的字符串数字。  | 
| resultValue | 写入resultValue的结果。  | 
| ... | 格式化字符串资源参数，可变参数，支持const char\*、int、float类型。  | 

**返回：**

SUCCESS 0 - 成功。 

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确;2.参数验证失败。 

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - 无效的资源ID。 

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - 没有根据资源ID找到匹配的资源。 

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - 资源被循环引用。 

ERROR_CODE_OUT_OF_MEMORY 9001100 - 内存溢出。


### OH_ResourceManager_GetDoublePluralStringByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDoublePluralStringByName (const NativeResourceManager * mgr, const char * resName, double num, char ** resultValue,  ... )
```
**描述**

通过指定资源名称，获取对应的单复数字符串。

使用此接口后，需要调用free()方法来释放字符串的内存。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。  | 
| resName | 资源名称。  | 
| num | 数量值（浮点数）。根据当前语言的复数规则获取该数量值对应的字符串数字。  | 
| resultValue | 写入resultValue的结果。  | 
| ... | 格式化字符串资源参数，可变参数，支持const char\*、int、float类型。  | 

**返回：**

SUCCESS 0 - 成功。 

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确;2.参数验证失败。 

ERROR_CODE_RES_ID_NOT_FOUND 9001003 - 无效的资源名称。 

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004 - 没有根据资源名称找到匹配的资源。 

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - 资源被循环引用。 

ERROR_CODE_OUT_OF_MEMORY 9001100 - 内存溢出。


### OH_ResourceManager_GetDrawableDescriptor()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptor (const NativeResourceManager * mgr, uint32_t resId, ArkUI_DrawableDescriptor ** drawableDescriptor, uint32_t density = 0, uint32_t type = 0 )
```

**描述**

通过指定资源Id，获取屏幕密度对应的图标资源的DrawableDescriptor。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resId | 资源ID。 | 
| density | 可选参数，取值范围参考[ScreenDensity](#screendensity)，默认值为0，表示使用当前系统dpi的密度。 | 
| type | 可选参数，表示图标类型，0表示自身图标，1表示主题图标。 | 
| drawableDescriptor | 写入drawableDescriptor的结果。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - 无效的资源ID。

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - 没有根据资源ID找到匹配的资源。


### OH_ResourceManager_GetDrawableDescriptorByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorByName (const NativeResourceManager * mgr, const char * resName, ArkUI_DrawableDescriptor ** drawableDescriptor, uint32_t density = 0, uint32_t type = 0 )
```

**描述**

通过指定资源名称，获取屏幕密度对应的图标资源的DrawableDescriptor。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resName | 资源名称。 | 
| density | 可选参数，取值范围参考[ScreenDensity](#screendensity)，默认值为0，表示使用当前系统dpi的密度。 | 
| type | 可选参数，表示图标类型，0表示自身图标，1表示主题图标，2表示动态图标。 | 
| drawableDescriptor | 写入drawableDescriptor的结果。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_NAME_NOT_FOUND 9001003 - 无效的资源名称。

ERROR_CODE_RES_NOT_FOUND_BY_NAME 9001004 - 没有根据资源名称找到匹配的资源。


### OH_ResourceManager_GetDrawableDescriptorData()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorData (const NativeResourceManager * mgr, uint32_t resId, ArkUI_DrawableDescriptor ** drawableDescriptor, uint32_t density, uint32_t type )
```

**描述**

通过指定资源Id，获取屏幕密度对应的图标资源的DrawableDescriptor。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resId | 资源ID。 | 
| drawableDescriptor | 写入drawableDescriptor的结果。 | 
| density | 可选参数，取值范围参考[ScreenDensity](#screendensity)，值为0表示使用当前系统dpi的密度。如果不需要此属性，请将此参数设置为0。 | 
| type | 可选参数，表示图标类型，0表示自身图标，1表示主题图标。如果该属性不是必需的，请将该参数设为0。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - 无效的资源ID。

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - 没有根据资源ID找到匹配的资源。


### OH_ResourceManager_GetDrawableDescriptorDataByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorDataByName (const NativeResourceManager * mgr, const char * resName, ArkUI_DrawableDescriptor ** drawableDescriptor, uint32_t density, uint32_t type )
```

**描述**

通过指定资源名称，获取屏幕密度对应的图标资源的DrawableDescriptor。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resName | 资源名称。 | 
| drawableDescriptor | 写入drawableDescriptor的结果。 | 
| density | 可选参数，取值范围参考[ScreenDensity](#screendensity)，值为0表示使用当前系统dpi的密度。如果不需要此属性，请将此参数设置为0。 | 
| type | 可选参数，表示图标类型，0表示自身图标，1表示主题图标。如果该属性不是必需的，请将该参数设为0。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_NAME_NOT_FOUND 9001003 - 无效的资源名称。

ERROR_CODE_RES_NOT_FOUND_BY_NAME 9001004 - 没有根据资源名称找到匹配的资源。


### OH_ResourceManager_GetFloat()

```
ResourceManager_ErrorCode OH_ResourceManager_GetFloat (const NativeResourceManager * mgr, uint32_t resId, float * resultValue )
```

**描述**

通过指定资源ID，获取对应的float值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resId | 资源ID。 | 
| resultValue | 写入resultValue的结果。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - 无效的资源ID。

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - 没有根据资源ID找到匹配的资源。

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - 资源被循环引用。


### OH_ResourceManager_GetFloatByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetFloatByName (const NativeResourceManager * mgr, const char * resName, float * resultValue )
```

**描述**

通过指定资源名称，获取对应的float值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resName | 资源名称。 | 
| resultValue | 写入resultValue的结果。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_ID_NOT_FOUND 9001003 - 无效的资源名称。

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004 - 没有根据资源名称找到匹配的资源。

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - 资源被循环引用。


### OH_ResourceManager_GetInt()

```
ResourceManager_ErrorCode OH_ResourceManager_GetInt (const NativeResourceManager * mgr, uint32_t resId, int * resultValue )
```

**描述**

通过指定资源ID，获取对应的int值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resId | 资源ID。 | 
| resultValue | 写入resultValue的结果。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - 无效的资源ID。

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - 没有根据资源ID找到匹配的资源。

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - 资源被循环引用。


### OH_ResourceManager_GetIntByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetIntByName (const NativeResourceManager * mgr, const char * resName, int * resultValue )
```

**描述**

通过指定资源名称，获取对应的int值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resName | 资源名称。 | 
| resultValue | 写入resultValue的结果。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_ID_NOT_FOUND 9001003 - 无效的资源名称。

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004 - 没有根据资源名称找到匹配的资源。

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - 资源被循环引用。


### OH_ResourceManager_GetIntPluralString()

```
ResourceManager_ErrorCode OH_ResourceManager_GetIntPluralString (const NativeResourceManager * mgr, uint32_t resId, uint32_t num, char ** resultValue,  ... )
```

**描述**

通过指定资源ID，获取对应的单复数字符串。

使用此接口后，需要调用free()方法来释放字符串的内存。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。  | 
| resId | 资源ID。  | 
| num | 数量值（整数）。根据当前语言的复数规则获取该数量值对应的字符串数字。  | 
| resultValue | 写入resultValue的结果。  | 
| ... | 格式化字符串资源参数，可变参数，支持const char\*、int、float类型。  | 

**返回：**

SUCCESS 0 - 成功。 

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确;2.参数验证失败。 

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - 无效的资源ID。 

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - 没有根据资源ID找到匹配的资源。 

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - 资源被循环引用。 

ERROR_CODE_OUT_OF_MEMORY 9001100 - 内存溢出。


### OH_ResourceManager_GetIntPluralStringByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetIntPluralStringByName (const NativeResourceManager * mgr, const char * resName, uint32_t num, char ** resultValue,  ... )
```
**描述**

通过指定资源名称，获取对应的单复数字符串。

使用此接口后，需要调用free()方法来释放字符串的内存。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。  | 
| resName | 资源名称。  | 
| num | 数量值（整数）。根据当前语言的复数规则获取该数量值对应的字符串数字。  | 
| resultValue | 写入resultValue的结果。  | 
| ... | 格式化字符串资源参数，可变参数，支持const char\*、int、float类型。  | 

**返回：**

SUCCESS 0 - 成功。 

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确;2.参数验证失败。 

ERROR_CODE_RES_ID_NOT_FOUND 9001003 - 无效的资源名称。 

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004 - 没有根据资源名称找到匹配的资源。 

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - 资源被循环引用。 

ERROR_CODE_OUT_OF_MEMORY 9001100 - 内存溢出。


### OH_ResourceManager_GetLocales()

```
ResourceManager_ErrorCode OH_ResourceManager_GetLocales (const NativeResourceManager * mgr, char *** resultValue, uint32_t * resultLen, bool includeSystem = false )
```

**描述**

获取语言列表。

使用此接口后，需要调用OH_ResourceManager_ReleaseStringArray()方法来释放localinfo的内存。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resultValue | 写入resultValue的结果。 | 
| resultLen | 写入resultLen的locales长度。 | 
| includeSystem | 是否包含系统资源，默认值为false，当只有系统资源查询locales列表时它不起作用。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_OUT_OF_MEMORY 9001100 - 内存溢出。


### OH_ResourceManager_GetLocalesData()

```
ResourceManager_ErrorCode OH_ResourceManager_GetLocalesData (const NativeResourceManager * mgr, char *** resultValue, uint32_t * resultLen, bool includeSystem )
```

**描述**

获取语言列表。

使用此接口后，需要调用OH_ResourceManager_ReleaseStringArray()方法来释放localinfo的内存。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resultValue | 写入resultValue的结果。 | 
| resultLen | 写入resultLen的locales长度。 | 
| includeSystem | 是否包含系统资源，如果不需要此属性，请将此参数设置为 false。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_OUT_OF_MEMORY 9001100 - 内存溢出。


### OH_ResourceManager_GetMedia()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMedia (const NativeResourceManager * mgr, uint32_t resId, uint8_t ** resultValue, uint64_t * resultLen, uint32_t density = 0 )
```

**描述**

通过指定资源ID，获取屏幕密度对应的media资源的内容。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resId | 资源ID。 | 
| density | 可选参数，取值范围参考[ScreenDensity](#screendensity)，默认值为0，表示使用当前系统dpi的密度。 | 
| resultValue | 写入resultValue的结果。 | 
| resultLen | 写入resultLen的media长度。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - 无效的资源ID。

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - 没有根据资源ID找到匹配的资源。

ERROR_CODE_OUT_OF_MEMORY 9001100 - 内存溢出。


### OH_ResourceManager_GetMediaBase64()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64 (const NativeResourceManager * mgr, uint32_t resId, char ** resultValue, uint64_t * resultLen, uint32_t density = 0 )
```

**描述**

通过指定资源ID，获取屏幕密度对应的media资源的Base64码。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resId | 资源ID。 | 
| density | 可选参数，取值范围参考[ScreenDensity](#screendensity)，默认值为0，表示使用当前系统dpi的密度。 | 
| resultValue | 写入resultValue的结果。 | 
| resultLen | 写入resultLen的media长度。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - 无效的资源ID。

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - 没有根据资源ID找到匹配的资源。

ERROR_CODE_OUT_OF_MEMORY 9001100 - 内存溢出。


### OH_ResourceManager_GetMediaBase64ByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64ByName (const NativeResourceManager * mgr, const char * resName, char ** resultValue, uint64_t * resultLen, uint32_t density = 0 )
```

**描述**

通过指定资源名称，获取屏幕密度对应的media资源的Base64码。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resName | 资源名称。 | 
| density | 可选参数，取值范围参考[ScreenDensity](#screendensity)，默认值为0，表示使用当前系统dpi的密度。 | 
| resultValue | 写入resultValue的结果。 | 
| resultLen | 写入resultLen的media长度。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_NAME_NOT_FOUND 9001003 - 无效的资源名称。

ERROR_CODE_RES_NOT_FOUND_BY_NAME 9001004 - 没有根据资源名称找到匹配的资源。

ERROR_CODE_OUT_OF_MEMORY 9001100 - 内存溢出。


### OH_ResourceManager_GetMediaBase64Data()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64Data (const NativeResourceManager * mgr, uint32_t resId, char ** resultValue, uint64_t * resultLen, uint32_t density )
```

**描述**

通过指定资源ID，获取屏幕密度对应的media资源的Base64码。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resId | 资源ID。 | 
| resultValue | 写入resultValue的结果。 | 
| resultLen | 写入resultLen的media长度。 | 
| density | 可选参数，取值范围参考[ScreenDensity](#screendensity)，值为0表示使用当前系统dpi的密度。如果不需要此属性，请将此参数设置为0。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - 无效的资源ID。

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - 没有根据资源ID找到匹配的资源。

ERROR_CODE_OUT_OF_MEMORY 9001100 - 内存溢出。


### OH_ResourceManager_GetMediaBase64DataByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64DataByName (const NativeResourceManager * mgr, const char * resName, char ** resultValue, uint64_t * resultLen, uint32_t density )
```

**描述**

通过指定资源名称，获取屏幕密度对应的media资源的Base64码。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resName | 资源名称。 | 
| resultValue | 写入resultValue的结果。 | 
| resultLen | 写入resultLen的media长度。 | 
| density | 可选参数，取值范围参考[ScreenDensity](#screendensity)，值为0表示使用当前系统dpi的密度。如果不需要此属性，请将此参数设置为0。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_NAME_NOT_FOUND 9001003 - 无效的资源名称。

ERROR_CODE_RES_NOT_FOUND_BY_NAME 9001004 - 没有根据资源名称找到匹配的资源。

ERROR_CODE_OUT_OF_MEMORY 9001100 - 内存溢出。


### OH_ResourceManager_GetMediaByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaByName (const NativeResourceManager * mgr, const char * resName, uint8_t ** resultValue, uint64_t * resultLen, uint32_t density = 0 )
```

**描述**

通过指定资源名称，获取屏幕密度对应的media资源的内容。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resName | 资源名称。 | 
| density | 可选参数，取值范围参考[ScreenDensity](#screendensity)，默认值为0，表示使用当前系统dpi的密度。 | 
| resultValue | 写入resultValue的结果。 | 
| resultLen | 写入resultLen的media长度。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_NAME_NOT_FOUND 9001003 - 无效的资源名称。

ERROR_CODE_RES_NOT_FOUND_BY_NAME 9001004 - 没有根据资源名称找到匹配的资源。

ERROR_CODE_OUT_OF_MEMORY 9001100 - 内存溢出。


### OH_ResourceManager_GetMediaData()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaData (const NativeResourceManager * mgr, uint32_t resId, uint8_t ** resultValue, uint64_t * resultLen, uint32_t density )
```

**描述**

通过指定资源ID，获取屏幕密度对应的media资源的内容。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resId | 资源ID。 | 
| resultValue | 写入resultValue的结果。 | 
| resultLen | 写入resultLen的media长度。 | 
| density | 可选参数，取值范围参考[ScreenDensity](#screendensity)，值为0表示使用当前系统dpi的密度。如果不需要此属性，请将此参数设置为0。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - 无效的资源ID。

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - 没有根据资源ID找到匹配的资源。

ERROR_CODE_OUT_OF_MEMORY 9001100 - 内存溢出。


### OH_ResourceManager_GetMediaDataByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaDataByName (const NativeResourceManager * mgr, const char * resName, uint8_t ** resultValue, uint64_t * resultLen, uint32_t density )
```

**描述**

通过指定资源名称，获取屏幕密度对应的media资源的内容。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resName | 资源名称。 | 
| resultValue | 写入resultValue的结果。 | 
| resultLen | 写入resultLen的media长度。 | 
| density | 可选参数，取值范围参考[ScreenDensity](#screendensity)，值为0表示使用当前系统dpi的密度。如果不需要此属性，请将此参数设置为0。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_NAME_NOT_FOUND 9001003 - 无效的资源名称。

ERROR_CODE_RES_NOT_FOUND_BY_NAME 9001004 - 没有根据资源名称找到匹配的资源。

ERROR_CODE_OUT_OF_MEMORY 9001100 - 内存溢出。


### OH_ResourceManager_GetPluralString()

```
ResourceManager_ErrorCode OH_ResourceManager_GetPluralString (const NativeResourceManager * mgr, uint32_t resId, uint32_t num, char ** resultValue )
```

**描述**

通过指定资源ID，获取对应的单复数字符串。

使用此接口后，需要调用free()方法来释放字符串的内存。

**起始版本：** 12

**废弃版本：** 18

**替代接口：**[OH_ResourceManager_GetIntPluralString](#oh_resourcemanager_getintpluralstring)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。  | 
| resId | 资源ID。  | 
| num | 数量值。  | 
| resultValue | 写入resultValue的结果。  | 

**返回：**

SUCCESS 0 - 成功。 

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确;2.参数验证失败。 

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - 无效的资源ID。 

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - 没有根据资源ID找到匹配的资源。 

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - 资源被循环引用。 

ERROR_CODE_OUT_OF_MEMORY 9001100 - 内存溢出。


### OH_ResourceManager_GetPluralStringByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetPluralStringByName (const NativeResourceManager * mgr, const char * resName, uint32_t num, char ** resultValue )
```
**描述**

通过指定资源名称，获取对应的单复数字符串。

使用此接口后，需要调用free()方法来释放字符串的内存。

**起始版本：** 12

**废弃版本：** 18

**替代接口：**[OH_ResourceManager_GetIntPluralStringByName](#oh_resourcemanager_getintpluralstringbyname)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。  | 
| resName | 资源名称。  | 
| num | 数量值。  | 
| resultValue | 写入resultValue的结果。  | 

**返回：**

SUCCESS 0 - 成功。 

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确;2.参数验证失败。 

ERROR_CODE_RES_ID_NOT_FOUND 9001003 - 无效的资源名称。 

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004 - 没有根据资源名称找到匹配的资源。 

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - 资源被循环引用。 

ERROR_CODE_OUT_OF_MEMORY 9001100 - 内存溢出。


### OH_ResourceManager_GetString()

```
ResourceManager_ErrorCode OH_ResourceManager_GetString (const NativeResourceManager * mgr, uint32_t resId, char ** resultValue,  ... )
```

**描述**

通过指定资源ID，获取对应的string资源。

获取普通string资源使用OH_ResourceManager_GetString(mgr, resId, resultValue)接口。 获取带有d、s、f占位符的格式化资源使用OH_ResourceManager_GetString(mgr, resId, resultValue, 10, "format", 10.10)接口。 使用此接口后，需要调用free()方法来释放字符串的内存。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resId | 资源ID。 | 
| resultValue | 写入resultValue的结果。 | 
| ... | 格式化字符串资源参数，可变参数，支持const char\*、int、float类型。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - 无效的资源ID。

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - 没有根据资源ID找到匹配的资源。

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - 资源被循环引用。

ERROR_CODE_OUT_OF_MEMORY 9001100 - 内存溢出。


### OH_ResourceManager_GetStringArray()

```
ResourceManager_ErrorCode OH_ResourceManager_GetStringArray (const NativeResourceManager * mgr, uint32_t resId, char *** resultValue, uint32_t * resultLen )
```

**描述**

通过指定资源ID，获取字符串数组。

使用此接口后，需要调用OH_ResourceManager_ReleaseStringArray()接口来释放字符串数组内存。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resId | 资源ID。 | 
| resultValue | 写入resultValue的结果。 | 
| resultLen | 写入resultLen的StringArray长度。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - 无效的资源ID。

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - 没有根据资源ID找到匹配的资源。

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - 资源被循环引用。

ERROR_CODE_OUT_OF_MEMORY 9001100 - 内存溢出。


### OH_ResourceManager_GetStringArrayByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetStringArrayByName (const NativeResourceManager * mgr, const char * resName, char *** resultValue, uint32_t * resultLen )
```

**描述**

通过指定资源名称，获取字符串数组。

使用此接口后，需要调用OH_ResourceManager_ReleaseStringArray()接口来释放字符串数组内存。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resName | 资源名称。 | 
| resultValue | 写入resultValue的结果。 | 
| resultLen | 写入resultLen的StringArray长度。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_ID_NOT_FOUND 9001003 - 无效的资源名称。

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004 - 没有根据资源名称找到匹配的资源。

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - 资源被循环引用。

ERROR_CODE_OUT_OF_MEMORY 9001100 - 内存溢出。


### OH_ResourceManager_GetStringByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetStringByName (const NativeResourceManager * mgr, const char * resName, char ** resultValue,  ... )
```

**描述**

通过指定资源名称，获取对应的string资源。

获取普通string资源使用OH_ResourceManager_GetString(mgr, resName, resultValue)接口。 获取带有%d、%s、%f占位符的格式化资源使用OH_ResourceManager_GetString(mgr, resName, resultValue, 10, "format", 10.10)接口。 使用此接口后，需要调用free()方法来释放字符串的内存。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resName | 资源名称。 | 
| resultValue | 写入resultValue的结果。 | 
| ... | 格式化字符串资源参数，可变参数，支持const char\*、int、float类型。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_ID_NOT_FOUND 9001003 - 无效的资源名称。

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001004 - 没有根据资源名称找到匹配的资源。

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - 资源被循环引用。

ERROR_CODE_OUT_OF_MEMORY 9001100 - 内存溢出。


### OH_ResourceManager_GetSymbol()

```
ResourceManager_ErrorCode OH_ResourceManager_GetSymbol (const NativeResourceManager * mgr, uint32_t resId, uint32_t * resultValue )
```

**描述**

通过指定资源ID，获取对应的symbol资源。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resId | 资源ID。 | 
| resultValue | 写入resultValue的结果。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_ID_NOT_FOUND 9001001 - 无效的资源ID。

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002 - 没有根据资源ID找到匹配的资源。

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - 资源被循环引用。


### OH_ResourceManager_GetSymbolByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetSymbolByName (const NativeResourceManager * mgr, const char * resName, uint32_t * resultValue )
```

**描述**

通过指定资源名称，获取对应的symbol资源。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| resName | 资源名称。 | 
| resultValue | 写入resultValue的结果。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_NAME_NOT_FOUND 9001003 - 无效的资源名称。

ERROR_CODE_RES_NOT_FOUND_BY_NAME 9001004 - 没有根据资源名称找到匹配的资源。

ERROR_CODE_RES_REF_TOO_MUCH 9001006 - 资源被循环引用。


### OH_ResourceManager_ReleaseConfiguration()

```
ResourceManager_ErrorCode OH_ResourceManager_ReleaseConfiguration (ResourceManager_Configuration * configuration)
```

**描述**

释放OH_ResourceManager_GetConfiguration()方法申请的内存。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| configuration | 需要释放内存的configuration对象。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。


### OH_ResourceManager_ReleaseStringArray()

```
ResourceManager_ErrorCode OH_ResourceManager_ReleaseStringArray (char *** resValue, uint32_t len )
```

**描述**

释放字符串数组内存。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| resValue | 需要释放的字符串数组。 | 
| len | 字符串数组长度。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。


### OH_ResourceManager_RemoveResource()

```
ResourceManager_ErrorCode OH_ResourceManager_RemoveResource (const NativeResourceManager * mgr, const char * path )
```

**描述**

在应用程序运行时删除overlay资源。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向[NativeResourceManager](rawfile.md#nativeresourcemanager)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](rawfile.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 | 
| path | 资源路径。 | 

**返回：**

SUCCESS 0 - 成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1.参数类型不正确；2.参数验证失败。

ERROR_CODE_OVERLAY_RES_PATH_INVALID 9001010 - 无效的资源路径。