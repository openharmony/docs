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


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) {<br/>SUCCESS = 0, ERROR_CODE_INVALID_INPUT_PARAMETER = 401, ERROR_CODE_RES_ID_NOT_FOUND = 9001001, ERROR_CODE_RES_NOT_FOUND_BY_ID = 9001002,<br/>ERROR_CODE_RES_NAME_NOT_FOUND = 9001003, ERROR_CODE_RES_NOT_FOUND_BY_NAME = 9001004, ERROR_CODE_RES_PATH_INVALID = 9001005, ERROR_CODE_RES_REF_TOO_MUCH = 9001006,<br/>ERROR_CODE_RES_ID_FORMAT_ERROR = 9001007, ERROR_CODE_RES_NAME_FORMAT_ERROR = 9001008, ERROR_CODE_SYSTEM_RES_MANAGER_GET_FAILED = 9001009, ERROR_CODE_OVERLAY_RES_PATH_INVALID = 9001010,<br/>ERROR_CODE_OUT_OF_MEMORY = 9001100<br/>} | 资源管理错误码。 | 
| [ScreenDensity](#screendensity) {<br/>SCREEN_SDPI = 120, SCREEN_MDPI = 160, SCREEN_LDPI = 240, SCREEN_XLDPI = 320,<br/>SCREEN_XXLDPI = 480, SCREEN_XXXLDPI = 640<br/>} | 屏幕密度类型的枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [ResourceManager_ErrorCode](#resourcemanager_errorcode)[OH_ResourceManager_GetMediaBase64](#oh_resourcemanager_getmediabase64) (const NativeResourceManager \*mgr, uint32_t resId, char \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | 获取指定资源ID，指定屏幕密度对应的media资源的Base64码。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode)[OH_ResourceManager_GetMediaBase64ByName](#oh_resourcemanager_getmediabase64byname) (const NativeResourceManager \*mgr, const char \*resName, char \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | 获取指定资源名称，指定屏幕密度对应的media资源的Base64码。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode)[OH_ResourceManager_GetMedia](#oh_resourcemanager_getmedia) (const NativeResourceManager \*mgr, uint32_t resId, uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | 获取指定资源ID，指定屏幕密度对应的media资源的内容。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode)[OH_ResourceManager_GetMediaByName](#oh_resourcemanager_getmediabyname) (const NativeResourceManager \*mgr, const char \*resName, uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density=0) | 获取指定资源名称，指定屏幕密度对应的media资源的内容。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode)[OH_ResourceManager_GetDrawableDescriptor](#oh_resourcemanager_getdrawabledescriptor) (const NativeResourceManager \*mgr, uint32_t resId, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density=0, uint32_t type=0) | 获取指定资源Id，指定屏幕密度对应的图标资源的DrawableDescriptor。 | 
| [ResourceManager_ErrorCode](#resourcemanager_errorcode)[OH_ResourceManager_GetDrawableDescriptorByName](#oh_resourcemanager_getdrawabledescriptorbyname) (const NativeResourceManager \*mgr, const char \*resName, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density=0, uint32_t type=0) | 获取指定资源名称，指定屏幕密度对应的图标资源的DrawableDescriptor。 | 


## 枚举类型说明


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


### OH_ResourceManager_GetDrawableDescriptor()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptor (const NativeResourceManager * mgr, uint32_t resId, ArkUI_DrawableDescriptor ** drawableDescriptor, uint32_t density = 0, uint32_t type = 0 )
```

**描述**

获取指定资源Id，指定屏幕密度对应的图标资源的DrawableDescriptor。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向**NativeResourceManager**的指针，此指针通过**OH_ResourceManager_InitNativeResourceManager**方法获取。 | 
| resId | 资源ID。 | 
| density | 可选参数screen、enddensity、enddensity，值为0表示使用当前系统dpi的密度。 | 
| type | 选参数表示图标类型，0表示自身图标，1表示主题图标。 | 
| drawableDescriptor | 写入drawableDescriptor的结果。 | 

**返回：**

SUCCESS 0：成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401 ：输入参数无效。可能的原因：1。参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_ID_NOT_FOUND 9001001：无效的资源ID。

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002：没有根据资源ID找到匹配的资源。


### OH_ResourceManager_GetDrawableDescriptorByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorByName (const NativeResourceManager * mgr, const char * resName, ArkUI_DrawableDescriptor ** drawableDescriptor, uint32_t density = 0, uint32_t type = 0 )
```

**描述**

获取指定资源名称，指定屏幕密度对应的图标资源的DrawableDescriptor。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向**NativeResourceManager**的指针，此指针通过**OH_ResourceManager_InitNativeResourceManager**方法获取。 | 
| resName | 资源名称。 | 
| density | 可选参数screen enddensity **enddensity**，值为0表示使用当前系统dpi的密度。 | 
| type | 可选参数表示图标类型，0表示自身图标，1表示主题图标，2表示动态图标。 | 
| drawableDescriptor | 写入drawableDescriptor的结果。 | 

**返回：**

SUCCESS 0 ：成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401：输入参数无效。可能的原因：1。参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_NAME_NOT_FOUND 9001003：无效的资源名称。

ERROR_CODE_RES_NOT_FOUND_BY_NAME 9001004：没有根据资源名称找到匹配的资源。


### OH_ResourceManager_GetMedia()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMedia (const NativeResourceManager * mgr, uint32_t resId, uint8_t ** resultValue, uint64_t * resultLen, uint32_t density = 0 )
```

**描述**

获取指定资源ID，指定屏幕密度对应的media资源的内容。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向**NativeResourceManager**的指针，此指针通过**OH_ResourceManager_InitNativeResourceManager**方法获取。 | 
| resId | 资源ID。 | 
| density | 可选参数screen enddensity **enddensity**，值为0表示使用当前系统dpi的密度。 | 
| resultValue | 写入resultValue的结果。 | 
| resultLen | 写入resultLen的media长度。 | 

**返回：**

SUCCESS 0：成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401：输入参数无效。可能的原因：1。参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_ID_NOT_FOUND 9001001：无效的资源ID。

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002：没有根据资源ID找到匹配的资源。

ERROR_CODE_OUT_OF_MEMORY 9001100：内存溢出。


### OH_ResourceManager_GetMediaBase64()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64 (const NativeResourceManager * mgr, uint32_t resId, char ** resultValue, uint64_t * resultLen, uint32_t density = 0 )
```

**描述**

获取指定资源ID，指定屏幕密度对应的media资源的Base64码。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向**NativeResourceManager**的指针，此指针通过**OH_ResourceManager_InitNativeResourceManager**方法获取。 | 
| resId | 资源ID。 | 
| density | 可选参数screen enddensity **enddensity**，值为0表示使用当前系统dpi的密度。 | 
| resultValue | 写入resultValue的结果。 | 
| resultLen | 写入resultLen的media长度。 | 

**返回：**

SUCCESS 0：成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401：输入参数无效。可能的原因：1。参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_ID_NOT_FOUND 9001001：无效的资源ID。

ERROR_CODE_RES_NOT_FOUND_BY_ID 9001002：没有根据资源ID找到匹配的资源。

ERROR_CODE_OUT_OF_MEMORY 9001100：内存溢出。


### OH_ResourceManager_GetMediaBase64ByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64ByName (const NativeResourceManager * mgr, const char * resName, char ** resultValue, uint64_t * resultLen, uint32_t density = 0 )
```

**描述**

获取指定资源名称，指定屏幕密度对应的media资源的Base64码。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向**NativeResourceManager**的指针，此指针通过**OH_ResourceManager_InitNativeResourceManager**方法获取。 | 
| resName | 资源名称。 | 
| density | 可选参数screen enddensity **enddensity**，值为0表示使用当前系统dpi的密度。 | 
| resultValue | 写入resultValue的结果。 | 
| resultLen | 写入resultLen的media长度。 | 

**返回：**

SUCCESS 0 - 成功。 ERROR_CODE_INVALID_INPUT_PARAMETER 401 - 输入参数无效。可能的原因:1。参数类型不正确;2.参数验证失败。 ERROR_CODE_RES_NAME_NOT_FOUND 9001003 - 无效的资源名称。 ERROR_CODE_RES_NOT_FOUND_BY_NAME 9001004 - 没有根据资源名称找到匹配的资源。 ERROR_CODE_OUT_OF_MEMORY 9001100 - 内存溢出。


### OH_ResourceManager_GetMediaByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaByName (const NativeResourceManager * mgr, const char * resName, uint8_t ** resultValue, uint64_t * resultLen, uint32_t density = 0 )
```

**描述**

获取指定资源名称，指定屏幕密度对应的media资源的内容。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mgr | 指向**NativeResourceManager**的指针，此指针通过**OH_ResourceManager_InitNativeResourceManager**方法获取。 | 
| resName | 资源名称。 | 
| density | 可选参数screen enddensity **enddensity**，值为0表示使用当前系统dpi的密度。 | 
| resultValue | 写入resultValue的结果。 | 
| resultLen | 写入resultLen的media长度。 | 

**返回：**

SUCCESS 0 ：成功。

ERROR_CODE_INVALID_INPUT_PARAMETER 401：输入参数无效。可能的原因：1。参数类型不正确；2.参数验证失败。

ERROR_CODE_RES_NAME_NOT_FOUND 9001003：无效的资源名称。

ERROR_CODE_RES_NOT_FOUND_BY_NAME 9001004：没有根据资源名称找到匹配的资源。

ERROR_CODE_OUT_OF_MEMORY 9001100：内存溢出。
