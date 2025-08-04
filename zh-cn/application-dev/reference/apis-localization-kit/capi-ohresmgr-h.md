# ohresmgr.h

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @liule_123-->
<!--SE: @buda_wy-->
<!--TSE: @lpw_work-->

## 概述

提供资源管理native侧获取资源的能力。

**引用文件：** <resourcemanager/ohresmgr.h>

**库：** libohresmgr.so

**系统能力：** SystemCapability.Global.ResourceManager

**起始版本：** 12

**相关模块：** [resourcemanager](capi-resourcemanager.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64(const NativeResourceManager *mgr, uint32_t resId,char **resultValue, uint64_t *resultLen, uint32_t density = 0)](#oh_resourcemanager_getmediabase64) | 通过指定资源ID，获取屏幕密度对应的media资源的Base64码。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64Data(const NativeResourceManager *mgr, uint32_t resId,char **resultValue, uint64_t *resultLen, uint32_t density)](#oh_resourcemanager_getmediabase64data) | 通过指定资源ID，获取屏幕密度对应的media资源的Base64码。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64ByName(const NativeResourceManager *mgr,const char *resName, char **resultValue, uint64_t *resultLen, uint32_t density = 0)](#oh_resourcemanager_getmediabase64byname) | 通过指定资源名称，获取屏幕密度对应的media资源的Base64码。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64DataByName(const NativeResourceManager *mgr,const char *resName, char **resultValue, uint64_t *resultLen, uint32_t density)](#oh_resourcemanager_getmediabase64databyname) | 通过指定资源名称，获取屏幕密度对应的media资源的Base64码。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetMedia(const NativeResourceManager *mgr, uint32_t resId,uint8_t **resultValue, uint64_t *resultLen, uint32_t density = 0)](#oh_resourcemanager_getmedia) | 通过指定资源ID，获取屏幕密度对应的media资源的内容。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetMediaData(const NativeResourceManager *mgr, uint32_t resId,uint8_t **resultValue, uint64_t *resultLen, uint32_t density)](#oh_resourcemanager_getmediadata) | 通过指定资源ID，获取屏幕密度对应的media资源的内容。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetMediaByName(const NativeResourceManager *mgr, const char *resName,uint8_t **resultValue, uint64_t *resultLen, uint32_t density = 0)](#oh_resourcemanager_getmediabyname) | 通过指定资源名称，获取屏幕密度对应的media资源的内容。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetMediaDataByName(const NativeResourceManager *mgr, const char *resName,uint8_t **resultValue, uint64_t *resultLen, uint32_t density)](#oh_resourcemanager_getmediadatabyname) | 通过指定资源名称，获取屏幕密度对应的media资源的内容。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptor(const NativeResourceManager *mgr,uint32_t resId, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density = 0, uint32_t type = 0)](#oh_resourcemanager_getdrawabledescriptor) | 通过指定资源Id，获取屏幕密度对应的图标资源的DrawableDescriptor。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorData(const NativeResourceManager *mgr,uint32_t resId, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density, uint32_t type)](#oh_resourcemanager_getdrawabledescriptordata) | 通过指定资源Id，获取屏幕密度对应的图标资源的DrawableDescriptor。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorByName(const NativeResourceManager *mgr,const char *resName, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density = 0, uint32_t type = 0)](#oh_resourcemanager_getdrawabledescriptorbyname) | 通过指定资源名称，获取屏幕密度对应的图标资源的DrawableDescriptor。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorDataByName(const NativeResourceManager *mgr,const char *resName, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density, uint32_t type)](#oh_resourcemanager_getdrawabledescriptordatabyname) | 通过指定资源名称，获取屏幕密度对应的图标资源的DrawableDescriptor。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetSymbol(const NativeResourceManager *mgr, uint32_t resId,uint32_t *resultValue)](#oh_resourcemanager_getsymbol) | 通过指定资源ID，获取对应的symbol资源。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetSymbolByName(const NativeResourceManager *mgr, const char *resName,uint32_t *resultValue)](#oh_resourcemanager_getsymbolbyname) | 通过指定资源名称，获取对应的symbol资源。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetLocales(const NativeResourceManager *mgr, char ***resultValue,uint32_t *resultLen, bool includeSystem = false)](#oh_resourcemanager_getlocales) | 获取语言列表。使用此接口后，需要调用[OH_ResourceManager_ReleaseStringArray()](#oh_resourcemanager_releasestringarray)方法来释放localinfo的内存。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetLocalesData(const NativeResourceManager *mgr, char ***resultValue,uint32_t *resultLen, bool includeSystem)](#oh_resourcemanager_getlocalesdata) | 获取语言列表。使用此接口后，需要调用[OH_ResourceManager_ReleaseStringArray()](#oh_resourcemanager_releasestringarray)方法来释放localinfo的内存。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetConfiguration(const NativeResourceManager *mgr,ResourceManager_Configuration *configuration)](#oh_resourcemanager_getconfiguration) | 获取设备配置。使用此接口后，需要调用[OH_ResourceManager_ReleaseConfiguration()](#oh_resourcemanager_releaseconfiguration)方法来释放内存。如果使用malloc创建ResourceManager_Configuration对象，还需要调用free()方法来释放它。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetResourceConfiguration(const NativeResourceManager *mgr,ResourceManager_Configuration *configuration)](#oh_resourcemanager_getresourceconfiguration) | 获取设备配置。使用此接口后，需要调用[OH_ResourceManager_ReleaseConfiguration()](#oh_resourcemanager_releaseconfiguration)方法来释放内存。如果使用malloc创建ResourceManager_Configuration对象，还需要调用free()方法来释放它。 |
| [ResourceManager_ErrorCode OH_ResourceManager_ReleaseConfiguration(ResourceManager_Configuration *configuration)](#oh_resourcemanager_releaseconfiguration) | 释放[OH_ResourceManager_GetConfiguration()](#oh_resourcemanager_getconfiguration)和[OH_ResourceManager_GetResourceConfiguration()](#oh_resourcemanager_getresourceconfiguration)方法申请的内存。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetString(const NativeResourceManager *mgr, uint32_t resId,char **resultValue, ...)](#oh_resourcemanager_getstring) | 通过指定资源ID，获取对应的string资源。获取普通string资源使用OH_ResourceManager_GetString(mgr, resId, resultValue)接口。获取带有%d、%s、%f占位符的格式化资源使用OH_ResourceManager_GetString(mgr, resId, resultValue, 10, "format", 10.10)接口。使用此接口后，需要调用free()方法来释放字符串的内存。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetStringByName(const NativeResourceManager *mgr, const char *resName,char **resultValue, ...)](#oh_resourcemanager_getstringbyname) | 通过指定资源名称，获取对应的string资源。获取普通string资源使用OH_ResourceManager_GetString(mgr, resName, resultValue)接口。获取带有%d、%s、%f占位符的格式化资源使用OH_ResourceManager_GetString(mgr, resName, resultValue, 10, "format", 10.10)接口。使用此接口后，需要调用free()方法来释放字符串的内存。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetStringArray(const NativeResourceManager *mgr, uint32_t resId,char ***resultValue, uint32_t *resultLen)](#oh_resourcemanager_getstringarray) | 通过指定资源ID，获取字符串数组。使用此接口后，需要调用[OH_ResourceManager_ReleaseStringArray()](#oh_resourcemanager_releasestringarray)接口来释放字符串数组内存。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetStringArrayByName(const NativeResourceManager *mgr,const char *resName, char ***resultValue, uint32_t *resultLen)](#oh_resourcemanager_getstringarraybyname) | 通过指定资源名称，获取字符串数组。使用此接口后，需要调用[OH_ResourceManager_ReleaseStringArray()](#oh_resourcemanager_releasestringarray)接口来释放字符串数组内存。 |
| [ResourceManager_ErrorCode OH_ResourceManager_ReleaseStringArray(char ***resValue, uint32_t len)](#oh_resourcemanager_releasestringarray) | 释放字符串数组内存。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetPluralString(const NativeResourceManager *mgr, uint32_t resId,uint32_t num, char **resultValue)](#oh_resourcemanager_getpluralstring) | 通过指定资源ID，获取对应的单复数字符串。使用此接口后，需要调用free()方法来释放字符串的内存。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetPluralStringByName(const NativeResourceManager *mgr,const char *resName, uint32_t num, char **resultValue)](#oh_resourcemanager_getpluralstringbyname) | 通过指定资源名称，获取对应的单复数字符串。使用此接口后，需要调用free()方法来释放字符串的内存。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetIntPluralString(const NativeResourceManager *mgr, uint32_t resId,uint32_t num, char **resultValue, ...)](#oh_resourcemanager_getintpluralstring) | 通过指定资源ID，获取对应的单复数字符串。使用此接口后，需要调用free()方法来释放字符串的内存。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetDoublePluralString(const NativeResourceManager *mgr, uint32_t resId,double num, char **resultValue, ...)](#oh_resourcemanager_getdoublepluralstring) | 通过指定资源ID，获取对应的单复数字符串。使用此接口后，需要调用free()方法来释放字符串的内存。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetIntPluralStringByName(const NativeResourceManager *mgr,const char *resName, uint32_t num, char **resultValue, ...)](#oh_resourcemanager_getintpluralstringbyname) | 通过指定资源名称，获取对应的单复数字符串。使用此接口后，需要调用free()方法来释放字符串的内存。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetDoublePluralStringByName(const NativeResourceManager *mgr,const char *resName, double num, char **resultValue, ...)](#oh_resourcemanager_getdoublepluralstringbyname) | 通过指定资源名称，获取对应的单复数字符串。使用此接口后，需要调用free()方法来释放字符串的内存。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetColor(const NativeResourceManager *mgr, uint32_t resId,uint32_t *resultValue)](#oh_resourcemanager_getcolor) | 通过指定资源ID，获取对应的颜色值。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetColorByName(const NativeResourceManager *mgr, const char *resName,uint32_t *resultValue)](#oh_resourcemanager_getcolorbyname) | 通过指定资源ID，获取对应的颜色值。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetInt(const NativeResourceManager *mgr, uint32_t resId,int *resultValue)](#oh_resourcemanager_getint) | 通过指定资源ID，获取对应的int值。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetIntByName(const NativeResourceManager *mgr, const char *resName,int *resultValue)](#oh_resourcemanager_getintbyname) | 通过指定资源名称，获取对应的int值。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetFloat(const NativeResourceManager *mgr, uint32_t resId,float *resultValue)](#oh_resourcemanager_getfloat) | 通过指定资源ID，获取对应的float值。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetFloatByName(const NativeResourceManager *mgr, const char *resName,float *resultValue)](#oh_resourcemanager_getfloatbyname) | 通过指定资源名称，获取对应的float值。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetBool(const NativeResourceManager *mgr, uint32_t resId,bool *resultValue)](#oh_resourcemanager_getbool) | 通过指定资源ID，获取对应的bool值。 |
| [ResourceManager_ErrorCode OH_ResourceManager_GetBoolByName(const NativeResourceManager *mgr, const char *resName,bool *resultValue)](#oh_resourcemanager_getboolbyname) | 通过指定资源名称，获取对应的bool值。 |
| [ResourceManager_ErrorCode OH_ResourceManager_AddResource(const NativeResourceManager *mgr, const char *path)](#oh_resourcemanager_addresource) | 在应用程序运行时添加overlay资源。 |
| [ResourceManager_ErrorCode OH_ResourceManager_RemoveResource(const NativeResourceManager *mgr, const char *path)](#oh_resourcemanager_removeresource) | 在应用程序运行时删除overlay资源。 |

## 函数说明

### OH_ResourceManager_GetMediaBase64()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64(const NativeResourceManager *mgr, uint32_t resId,char **resultValue, uint64_t *resultLen, uint32_t density = 0)
```

**描述**

通过指定资源ID，获取屏幕密度对应的media资源的Base64码。

**起始版本：** 12


**参数：**

| 参数项 | 描述                                                                                                                                                                      |
| -- |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| uint32_t resId | 资源ID。                                                                                                                                                                   |
| uint32_t density = 0 | 可选参数，取值范围参考[ScreenDensity](capi-resmgr-common-h.md#screendensity)，默认值为0，表示使用当前系统dpi的密度。                                                                                 |
| char **resultValue | 写入resultValue的结果。                                                                                                                                                       |
| uint64_t *resultLen | 写入resultLen的media长度。                                                                                                                                                    |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - 无效的资源ID。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - 没有根据资源ID找到匹配的资源。<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - 内存溢出。 |

### OH_ResourceManager_GetMediaBase64Data()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64Data(const NativeResourceManager *mgr, uint32_t resId,char **resultValue, uint64_t *resultLen, uint32_t density)
```

**描述**

通过指定资源ID，获取屏幕密度对应的media资源的Base64码。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| uint32_t resId | 资源ID。 |
| char **resultValue | 写入resultValue的结果。 |
| uint64_t *resultLen | 写入resultLen的media长度。 |
| uint32_t density | 可选参数，取值范围参考[ScreenDensity](capi-resmgr-common-h.md#screendensity)，值为0表示使用当前系统dpi的密度。如果不需要此属性，请将此参数设置为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - 无效的资源ID。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - 没有根据资源ID找到匹配的资源。<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - 内存溢出。 |

### OH_ResourceManager_GetMediaBase64ByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64ByName(const NativeResourceManager *mgr,const char *resName, char **resultValue, uint64_t *resultLen, uint32_t density = 0)
```

**描述**

通过指定资源名称，获取屏幕密度对应的media资源的Base64码。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| const char *resName | 资源名称。 |
| char **resultValue | 写入resultValue的结果。 |
| uint64_t *resultLen | 写入resultLen的media长度。 |
| uint32_t density = 0 | 可选参数，取值范围参考[ScreenDensity](capi-resmgr-common-h.md#screendensity)，默认值为0，表示使用当前系统dpi的密度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_NAME_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - 无效的资源名称。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - 没有根据资源名称找到匹配的资源。<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - 内存溢出。 |

### OH_ResourceManager_GetMediaBase64DataByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64DataByName(const NativeResourceManager *mgr,const char *resName, char **resultValue, uint64_t *resultLen, uint32_t density)
```

**描述**

通过指定资源名称，获取屏幕密度对应的media资源的Base64码。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| const char *resName | 资源名称。 |
| char **resultValue | 写入resultValue的结果。 |
| uint64_t *resultLen | 写入resultLen的media长度。 |
| uint32_t density | 可选参数，取值范围参考[ScreenDensity](capi-resmgr-common-h.md#screendensity)，值为0表示使用当前系统dpi的密度。如果不需要此属性，请将此参数设置为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_NAME_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - 无效的资源名称。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - 没有根据资源名称找到匹配的资源。<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - 内存溢出。 |

### OH_ResourceManager_GetMedia()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMedia(const NativeResourceManager *mgr, uint32_t resId,uint8_t **resultValue, uint64_t *resultLen, uint32_t density = 0)
```

**描述**

通过指定资源ID，获取屏幕密度对应的media资源的内容。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| uint32_t resId | 资源ID。 |
| uint32_t density = 0 | 可选参数，取值范围参考[ScreenDensity](capi-resmgr-common-h.md#screendensity)，默认值为0，表示使用当前系统dpi的密度。 |
| uint8_t **resultValue | 写入resultValue的结果。 |
| uint64_t *resultLen | 写入resultLen的media长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - 无效的资源ID。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - 没有根据资源ID找到匹配的资源。<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - 内存溢出。 |

### OH_ResourceManager_GetMediaData()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaData(const NativeResourceManager *mgr, uint32_t resId,uint8_t **resultValue, uint64_t *resultLen, uint32_t density)
```

**描述**

通过指定资源ID，获取屏幕密度对应的media资源的内容。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| uint32_t resId | 资源ID。 |
| uint8_t **resultValue | 写入resultValue的结果。 |
| uint64_t *resultLen | 写入resultLen的media长度。 |
| uint32_t density | 可选参数，取值范围参考[ScreenDensity](capi-resmgr-common-h.md#screendensity)，值为0表示使用当前系统dpi的密度。如果不需要此属性，请将此参数设置为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - 无效的资源ID。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - 没有根据资源ID找到匹配的资源。<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - 内存溢出。 |

### OH_ResourceManager_GetMediaByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaByName(const NativeResourceManager *mgr, const char *resName,uint8_t **resultValue, uint64_t *resultLen, uint32_t density = 0)
```

**描述**

通过指定资源名称，获取屏幕密度对应的media资源的内容。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| const char *resName | 资源名称。 |
| uint32_t density = 0 | 可选参数，取值范围参考[ScreenDensity](capi-resmgr-common-h.md#screendensity)，默认值为0，表示使用当前系统dpi的密度。 |
| uint8_t **resultValue | 写入resultValue的结果。 |
| uint64_t *resultLen | 写入resultLen的media长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_NAME_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - 无效的资源名称。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - 没有根据资源名称找到匹配的资源。<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - 内存溢出。 |

### OH_ResourceManager_GetMediaDataByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetMediaDataByName(const NativeResourceManager *mgr, const char *resName,uint8_t **resultValue, uint64_t *resultLen, uint32_t density)
```

**描述**

通过指定资源名称，获取屏幕密度对应的media资源的内容。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| const char *resName | 资源名称。 |
| uint8_t **resultValue | 写入resultValue的结果。 |
| uint64_t *resultLen | 写入resultLen的media长度。 |
| uint32_t density | 可选参数，取值范围参考[ScreenDensity](capi-resmgr-common-h.md#screendensity)，值为0表示使用当前系统dpi的密度。如果不需要此属性，请将此参数设置为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_NAME_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - 无效的资源名称。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - 没有根据资源名称找到匹配的资源。<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - 内存溢出。 |

### OH_ResourceManager_GetDrawableDescriptor()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptor(const NativeResourceManager *mgr,uint32_t resId, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density = 0, uint32_t type = 0)
```

**描述**

通过指定资源Id，获取屏幕密度对应的图标资源的DrawableDescriptor。

**起始版本：** 12


**参数：**

| 参数项                                                                                                                 | 描述 |
|---------------------------------------------------------------------------------------------------------------------| -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr                                           | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| uint32_t resId                                                                                                      | 资源ID。 |
| uint32_t density = 0                                                                                                | 可选参数，取值范围参考[ScreenDensity](capi-resmgr-common-h.md#screendensity)，默认值为0，表示使用当前系统dpi的密度。 |
| uint32_t type = 0                                                                                                   | 可选参数，表示图标类型，0表示自身图标，1表示主题图标。 |
| [ArkUI_DrawableDescriptor](../apis-arkui/capi-arkui-nativemodule-arkui-drawabledescriptor.md) **drawableDescriptor | 写入drawableDescriptor的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - 无效的资源ID。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - 没有根据资源ID找到匹配的资源。 |

### OH_ResourceManager_GetDrawableDescriptorData()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorData(const NativeResourceManager *mgr,uint32_t resId, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density, uint32_t type)
```

**描述**

通过指定资源Id，获取屏幕密度对应的图标资源的DrawableDescriptor。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| uint32_t resId | 资源ID。 |
| [ArkUI_DrawableDescriptor](../apis-arkui/capi-arkui-nativemodule-arkui-drawabledescriptor.md) **drawableDescriptor | 写入drawableDescriptor的结果。 |
| uint32_t density | 可选参数，取值范围参考[ScreenDensity](capi-resmgr-common-h.md#screendensity)，值为0表示使用当前系统dpi的密度。如果不需要此属性，请将此参数设置为0。 |
| uint32_t type | 可选参数，表示图标类型，0表示自身图标，1表示主题图标。如果该属性不是必需的，请将该参数设为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - 无效的资源ID。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - 没有根据资源ID找到匹配的资源。 |

### OH_ResourceManager_GetDrawableDescriptorByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorByName(const NativeResourceManager *mgr,const char *resName, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density = 0, uint32_t type = 0)
```

**描述**

通过指定资源名称，获取屏幕密度对应的图标资源的DrawableDescriptor。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| const char *resName | 资源名称。 |
| uint32_t density = 0 | 可选参数，取值范围参考[ScreenDensity](capi-resmgr-common-h.md#screendensity)，默认值为0，表示使用当前系统dpi的密度。 |
| uint32_t type = 0 | 可选参数，表示图标类型，0表示自身图标，1表示主题图标，2表示动态图标。 |
| [ArkUI_DrawableDescriptor](../apis-arkui/capi-arkui-nativemodule-arkui-drawabledescriptor.md) **drawableDescriptor | 写入drawableDescriptor的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_NAME_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - 无效的资源名称。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - 没有根据资源名称找到匹配的资源。 |

### OH_ResourceManager_GetDrawableDescriptorDataByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorDataByName(const NativeResourceManager *mgr,const char *resName, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density, uint32_t type)
```

**描述**

通过指定资源名称，获取屏幕密度对应的图标资源的DrawableDescriptor。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| const char *resName | 资源名称。 |
| [ArkUI_DrawableDescriptor](../apis-arkui/capi-arkui-nativemodule-arkui-drawabledescriptor.md) **drawableDescriptor | 写入drawableDescriptor的结果。 |
| uint32_t density | 可选参数，取值范围参考[ScreenDensity](capi-resmgr-common-h.md#screendensity)，值为0表示使用当前系统dpi的密度。如果不需要此属性，请将此参数设置为0。 |
| uint32_t type | 可选参数，表示图标类型，0表示自身图标，1表示主题图标。如果该属性不是必需的，请将该参数设为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_NAME_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - 无效的资源名称。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - 没有根据资源名称找到匹配的资源。 |

### OH_ResourceManager_GetSymbol()

```
ResourceManager_ErrorCode OH_ResourceManager_GetSymbol(const NativeResourceManager *mgr, uint32_t resId,uint32_t *resultValue)
```

**描述**

通过指定资源ID，获取对应的symbol资源。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| uint32_t resId | 资源ID。 |
| uint32_t *resultValue | 写入resultValue的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - 无效的资源ID。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - 没有根据资源ID找到匹配的资源。<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - 资源被循环引用。 |

### OH_ResourceManager_GetSymbolByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetSymbolByName(const NativeResourceManager *mgr, const char *resName,uint32_t *resultValue)
```

**描述**

通过指定资源名称，获取对应的symbol资源。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| const char *resName | 资源名称。 |
| uint32_t *resultValue | 写入resultValue的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_NAME_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - 无效的资源名称。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - 没有根据资源名称找到匹配的资源。<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - 资源被循环引用。 |

### OH_ResourceManager_GetLocales()

```
ResourceManager_ErrorCode OH_ResourceManager_GetLocales(const NativeResourceManager *mgr, char ***resultValue,uint32_t *resultLen, bool includeSystem = false)
```

**描述**

获取语言列表。使用此接口后，需要调用OH_ResourceManager_ReleaseStringArray()方法来释放localinfo的内存。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| char ***resultValue | 写入resultValue的结果。 |
| uint32_t *resultLen | 写入resultLen的locales长度。 |
| bool includeSystem = false | 是否包含系统资源，默认值为false，当只有系统资源查询locales列表时它不起作用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>         [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - 内存溢出。 |

### OH_ResourceManager_GetLocalesData()

```
ResourceManager_ErrorCode OH_ResourceManager_GetLocalesData(const NativeResourceManager *mgr, char ***resultValue,uint32_t *resultLen, bool includeSystem)
```

**描述**

获取语言列表。使用此接口后，需要调用OH_ResourceManager_ReleaseStringArray()方法来释放localinfo的内存。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| char ***resultValue | 写入resultValue的结果。 |
| uint32_t *resultLen | 写入resultLen的locales长度。 |
| bool includeSystem | 是否包含系统资源，如果不需要此属性，请将此参数设置为 false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>         [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - 内存溢出。 |

### OH_ResourceManager_GetConfiguration()

```
ResourceManager_ErrorCode OH_ResourceManager_GetConfiguration(const NativeResourceManager *mgr,ResourceManager_Configuration *configuration)
```

**描述**

获取设备配置。使用此接口后，需要调用OH_ResourceManager_ReleaseConfiguration()方法来释放内存。如果使用malloc创建ResourceManager_Configuration对象，还需要调用free()方法来释放它。

**起始版本：** 12

**废弃版本：** 20

**替代接口：** [OH_ResourceManager_GetResourceConfiguration](#oh_resourcemanager_getresourceconfiguration)


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| [ResourceManager_Configuration](capi-resourcemanager-resourcemanager-configuration.md) *configuration | 写入获取的设备配置。其中configuration.screenDensity的返回值为设备DPI除以160取整后的值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_SYSTEM_RES_MANAGER_GET_FAILED](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001009 - 无法访问系统资源。<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - 内存溢出。 |

### OH_ResourceManager_GetResourceConfiguration()

```
ResourceManager_ErrorCode OH_ResourceManager_GetResourceConfiguration(const NativeResourceManager *mgr,ResourceManager_Configuration *configuration)
```

**描述**

获取设备配置。使用此接口后，需要调用OH_ResourceManager_ReleaseConfiguration()方法来释放内存。如果使用malloc创建ResourceManager_Configuration对象，还需要调用free()方法来释放它。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| [ResourceManager_Configuration](capi-resourcemanager-resourcemanager-configuration.md) *configuration | 写入获取的设备配置。其中configuration.screenDensity的返回值为设备DPI。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_SYSTEM_RES_MANAGER_GET_FAILED](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001009 - 无法访问系统资源。<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - 内存溢出。 |

### OH_ResourceManager_ReleaseConfiguration()

```
ResourceManager_ErrorCode OH_ResourceManager_ReleaseConfiguration(ResourceManager_Configuration *configuration)
```

**描述**

释放OH_ResourceManager_GetConfiguration()方法申请的内存。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ResourceManager_Configuration](capi-resourcemanager-resourcemanager-configuration.md) *configuration | 需要释放内存的configuration对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。 |

### OH_ResourceManager_GetString()

```
ResourceManager_ErrorCode OH_ResourceManager_GetString(const NativeResourceManager *mgr, uint32_t resId,char **resultValue, ...)
```

**描述**

通过指定资源ID，获取对应的string资源。获取普通string资源使用OH_ResourceManager_GetString(mgr, resId, resultValue)接口。获取带有%d、%s、%f占位符的格式化资源使用OH_ResourceManager_GetString(mgr, resId, resultValue, 10, "format", 10.10)接口。使用此接口后，需要调用free()方法来释放字符串的内存。

**起始版本：** 12


**参数：**

| 参数项                                                                                             | 描述 |
|-------------------------------------------------------------------------------------------------| -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr                                                            | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| uint32_t resId                                                                                  | 资源ID。 |
| char **resultValue                                                                              | 写入resultValue的结果。 |
| ... | 格式化字符串资源参数，可变参数，支持const char*、int、float类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - 无效的资源ID。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - 没有根据资源ID找到匹配的资源。<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - 资源被循环引用。<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - 内存溢出。 |

### OH_ResourceManager_GetStringByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetStringByName(const NativeResourceManager *mgr, const char *resName,char **resultValue, ...)
```

**描述**

通过指定资源名称，获取对应的string资源。获取普通string资源使用OH_ResourceManager_GetString(mgr, resName, resultValue)接口。获取带有%d、%s、%f占位符的格式化资源使用OH_ResourceManager_GetString(mgr, resName, resultValue, 10, "format", 10.10)接口。使用此接口后，需要调用free()方法来释放字符串的内存。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向 [NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| const char *resName | 资源名称。 |
| char **resultValue | 写入resultValue的结果。 |
| ... | 格式化字符串资源参数，可变参数，支持const char*、int、float类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - 无效的资源名称。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - 没有根据资源名称找到匹配的资源。<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - 资源被循环引用。<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - 内存溢出。 |

### OH_ResourceManager_GetStringArray()

```
ResourceManager_ErrorCode OH_ResourceManager_GetStringArray(const NativeResourceManager *mgr, uint32_t resId,char ***resultValue, uint32_t *resultLen)
```

**描述**

通过指定资源ID，获取字符串数组。使用此接口后，需要调用OH_ResourceManager_ReleaseStringArray()接口来释放字符串数组内存。

**起始版本：** 12


**参数：**

| 参数项                                  | 描述 |
|--------------------------------------| -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| uint32_t resId                       | 资源ID。 |
| char ***resultValue                  | 写入resultValue的结果。 |
| uint32_t *resultLen                  | 写入resultLen的StringArray长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - 无效的资源ID。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - 没有根据资源ID找到匹配的资源。<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - 资源被循环引用。<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - 内存溢出。 |

### OH_ResourceManager_GetStringArrayByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetStringArrayByName(const NativeResourceManager *mgr,const char *resName, char ***resultValue, uint32_t *resultLen)
```

**描述**

通过指定资源名称，获取字符串数组。使用此接口后，需要调用OH_ResourceManager_ReleaseStringArray()接口来释放字符串数组内存。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| const char *resName | 资源名称。 |
| char ***resultValue | 写入resultValue的结果。 |
| uint32_t *resultLen | 写入resultLen的StringArray长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - 无效的资源名称。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - 没有根据资源名称找到匹配的资源。<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - 资源被循环引用。<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - 内存溢出。 |

### OH_ResourceManager_ReleaseStringArray()

```
ResourceManager_ErrorCode OH_ResourceManager_ReleaseStringArray(char ***resValue, uint32_t len)
```

**描述**

释放字符串数组内存。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| char ***resValue | 需要释放的字符串数组。 |
| uint32_t len | 字符串数组长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。 |

### OH_ResourceManager_GetPluralString()

```
ResourceManager_ErrorCode OH_ResourceManager_GetPluralString(const NativeResourceManager *mgr, uint32_t resId,uint32_t num, char **resultValue)
```

**描述**

通过指定资源ID，获取对应的单复数字符串。使用此接口后，需要调用free()方法来释放字符串的内存。

**起始版本：** 12

**废弃版本：** 18

**替代接口：** [OH_ResourceManager_GetIntPluralString](capi-ohresmgr-h.md#oh_resourcemanager_getintpluralstring)


**参数：**

| 参数项                                  | 描述 |
|--------------------------------------| -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| uint32_t resId                       | 资源ID。 |
| uint32_t num                         |  数量值。 |
| char **resultValue                   | 写入resultValue的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - 无效的资源ID。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - 没有根据资源ID找到匹配的资源。<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - 资源被循环引用。<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - 内存溢出。 |

### OH_ResourceManager_GetPluralStringByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetPluralStringByName(const NativeResourceManager *mgr,const char *resName, uint32_t num, char **resultValue)
```

**描述**

通过指定资源名称，获取对应的单复数字符串。使用此接口后，需要调用free()方法来释放字符串的内存。

**起始版本：** 12

**废弃版本：** 18

**替代接口：** [OH_ResourceManager_GetIntPluralStringByName](capi-ohresmgr-h.md#oh_resourcemanager_getintpluralstringbyname)


**参数：**

| 参数项 | 描述                                                                                                                                                                                      |
| -- |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| const char *resName | 资源名称。                                                                                                                                                                                   |
| uint32_t num | 数量值。                                                                                                                                                                                    |
| char **resultValue | 写入resultValue的结果。                                                                                                                                                                       |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - 无效的资源名称。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - 没有根据资源名称找到匹配的资源。<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - 资源被循环引用。<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - 内存溢出。 |

### OH_ResourceManager_GetIntPluralString()

```
ResourceManager_ErrorCode OH_ResourceManager_GetIntPluralString(const NativeResourceManager *mgr, uint32_t resId,uint32_t num, char **resultValue, ...)
```

**描述**

通过指定资源ID，获取对应的单复数字符串。使用此接口后，需要调用free()方法来释放字符串的内存。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| uint32_t resId | 资源ID。 |
| uint32_t num |  数量值（整数）。根据当前语言的复数规则获取该数量值对应的字符串数字。 |
| char **resultValue | 写入resultValue的结果。 |
| ... | 格式化字符串资源参数，可变参数，支持const char*、int、float类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - 无效的资源ID。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - 没有根据资源ID找到匹配的资源。<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - 资源被循环引用。<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - 内存溢出。 |

### OH_ResourceManager_GetDoublePluralString()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDoublePluralString(const NativeResourceManager *mgr, uint32_t resId,double num, char **resultValue, ...)
```

**描述**

通过指定资源ID，获取对应的单复数字符串。使用此接口后，需要调用free()方法来释放字符串的内存。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| uint32_t resId | 资源ID。 |
| double num |  数量值（浮点数）。根据当前语言的复数规则获取该数量值对应的字符串数字。 |
| char **resultValue | 写入resultValue的结果。 |
| ... | 格式化字符串资源参数，可变参数，支持const char*、int、float类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - 无效的资源ID。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - 没有根据资源ID找到匹配的资源。<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - 资源被循环引用。<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - 内存溢出。 |

### OH_ResourceManager_GetIntPluralStringByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetIntPluralStringByName(const NativeResourceManager *mgr,const char *resName, uint32_t num, char **resultValue, ...)
```

**描述**

通过指定资源名称，获取对应的单复数字符串。使用此接口后，需要调用free()方法来释放字符串的内存。

**起始版本：** 18


**参数：**

| 参数项                                                                                             | 描述                                                                                                                                                                      |
|-------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr                                                            | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| const char *resName                                                                             | 资源名称。                                                                                                                                                                   |
| uint32_t num                                                                                    | 数量值（整数）。根据当前语言的复数规则获取该数量值对应的字符串数字。                                                                                                                                      |
| char **resultValue                                                                              | 写入resultValue的结果。                                                                                                                                                       |
| ... | 格式化字符串资源参数，可变参数，支持const char*、int、float类型。                                                                                                                              |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - 无效的资源名称。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - 没有根据资源名称找到匹配的资源。<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - 资源被循环引用。<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - 内存溢出。 |

### OH_ResourceManager_GetDoublePluralStringByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetDoublePluralStringByName(const NativeResourceManager *mgr,const char *resName, double num, char **resultValue, ...)
```

**描述**

通过指定资源名称，获取对应的单复数字符串。使用此接口后，需要调用free()方法来释放字符串的内存。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| const char *resName | 资源名称。 |
| double num |  数量值（浮点数）。根据当前语言的复数规则获取该数量值对应的字符串数字。 |
| char **resultValue | 写入resultValue的结果。 |
| ... | 格式化字符串资源参数，可变参数，支持const char*、int、float类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - 无效的资源名称。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - 没有根据资源名称找到匹配的资源。<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - 资源被循环引用。<br>          [ERROR_CODE_OUT_OF_MEMORY](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001100 - 内存溢出。 |

### OH_ResourceManager_GetColor()

```
ResourceManager_ErrorCode OH_ResourceManager_GetColor(const NativeResourceManager *mgr, uint32_t resId,uint32_t *resultValue)
```

**描述**

通过指定资源ID，获取对应的颜色值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| uint32_t resId | 资源ID。 |
| uint32_t *resultValue | 写入resultValue的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - 无效的资源ID。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - 没有根据资源ID找到匹配的资源。<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - 资源被循环引用。 |

### OH_ResourceManager_GetColorByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetColorByName(const NativeResourceManager *mgr, const char *resName,uint32_t *resultValue)
```

**描述**

通过指定资源ID，获取对应的颜色值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| const char *resName | 资源名称。 |
| uint32_t *resultValue | 写入resultValue的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - 无效的资源名称。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - 没有根据资源名称找到匹配的资源。<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - 资源被循环引用。 |

### OH_ResourceManager_GetInt()

```
ResourceManager_ErrorCode OH_ResourceManager_GetInt(const NativeResourceManager *mgr, uint32_t resId,int *resultValue)
```

**描述**

通过指定资源ID，获取对应的int值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| uint32_t resId | 资源ID。 |
| int *resultValue | 写入resultValue的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - 无效的资源ID。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - 没有根据资源ID找到匹配的资源。<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - 资源被循环引用。 |

### OH_ResourceManager_GetIntByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetIntByName(const NativeResourceManager *mgr, const char *resName,int *resultValue)
```

**描述**

通过指定资源名称，获取对应的int值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| const char *resName | 资源名称。 |
| int *resultValue | 写入resultValue的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - 无效的资源名称。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - 没有根据资源名称找到匹配的资源。<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - 资源被循环引用。 |

### OH_ResourceManager_GetFloat()

```
ResourceManager_ErrorCode OH_ResourceManager_GetFloat(const NativeResourceManager *mgr, uint32_t resId,float *resultValue)
```

**描述**

通过指定资源ID，获取对应的float值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| uint32_t resId | 资源ID。 |
| float *resultValue | 写入resultValue的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - 无效的资源ID。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - 没有根据资源ID找到匹配的资源。<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - 资源被循环引用。 |

### OH_ResourceManager_GetFloatByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetFloatByName(const NativeResourceManager *mgr, const char *resName,float *resultValue)
```

**描述**

通过指定资源名称，获取对应的float值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| const char *resName | 资源名称。 |
| float *resultValue | 写入resultValue的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - 无效的资源名称。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - 没有根据资源名称找到匹配的资源。<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - 资源被循环引用。 |

### OH_ResourceManager_GetBool()

```
ResourceManager_ErrorCode OH_ResourceManager_GetBool(const NativeResourceManager *mgr, uint32_t resId,bool *resultValue)
```

**描述**

通过指定资源ID，获取对应的bool值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| uint32_t resId | 资源ID。 |
| bool *resultValue | 写入resultValue的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001001 - 无效的资源ID。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_ID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001002 - 没有根据资源ID找到匹配的资源。<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - 资源被循环引用。 |

### OH_ResourceManager_GetBoolByName()

```
ResourceManager_ErrorCode OH_ResourceManager_GetBoolByName(const NativeResourceManager *mgr, const char *resName,bool *resultValue)
```

**描述**

通过指定资源名称，获取对应的bool值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| const char *resName | 资源名称。 |
| bool *resultValue | 写入resultValue的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_RES_ID_NOT_FOUND](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001003 - 无效的资源名称。<br>          [ERROR_CODE_RES_NOT_FOUND_BY_NAME](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001004 - 没有根据资源名称找到匹配的资源。<br>          [ERROR_CODE_RES_REF_TOO_MUCH](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001006 - 资源被循环引用。 |

### OH_ResourceManager_AddResource()

```
ResourceManager_ErrorCode OH_ResourceManager_AddResource(const NativeResourceManager *mgr, const char *path)
```

**描述**

在应用程序运行时添加overlay资源。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| const char *path | 资源路径。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_OVERLAY_RES_PATH_INVALID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001010 - 无效的资源路径. |

### OH_ResourceManager_RemoveResource()

```
ResourceManager_ErrorCode OH_ResourceManager_RemoveResource(const NativeResourceManager *mgr, const char *path)
```

**描述**

在应用程序运行时删除overlay资源。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [NativeResourceManager](capi-rawfile-nativeresourcemanager.md) *mgr | 指向[NativeResourceManager](capi-rawfile-nativeresourcemanager.md)的指针，此指针通过[OH_ResourceManager_InitNativeResourceManager](capi-raw-file-manager-h.md#oh_resourcemanager_initnativeresourcemanager)方法获取。 |
| const char *path | 资源路径。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ResourceManager_ErrorCode](capi-resmgr-common-h.md#resourcemanager_errorcode) | [SUCCESS](capi-resmgr-common-h.md#resourcemanager_errorcode) 0 - 成功。<br>         [ERROR_CODE_INVALID_INPUT_PARAMETER](capi-resmgr-common-h.md#resourcemanager_errorcode) 401 - 输入参数无效。可能的原因：1.参数类型不正确；2.参数验证失败。<br>          [ERROR_CODE_OVERLAY_RES_PATH_INVALID](capi-resmgr-common-h.md#resourcemanager_errorcode) 9001010 - 无效的资源路径. |


