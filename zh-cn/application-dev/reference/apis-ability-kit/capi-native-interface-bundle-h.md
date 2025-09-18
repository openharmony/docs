# native_interface_bundle.h
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

提供查询应用包信息的功能，包括应用包名、应用指纹、应用appId等。

**引用文件：** <bundle/native_interface_bundle.h>

**库：** libbundle_ndk.z.so

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**起始版本：** 9

**相关模块：** [Native_Bundle](capi-native-bundle.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_NativeBundle_ApplicationInfo](capi-native-bundle-oh-nativebundle-applicationinfo.md) | OH_NativeBundle_ApplicationInfo | 应用包信息数据结构，包含应用包名和应用指纹信息。 |
| [OH_NativeBundle_ElementName](capi-native-bundle-oh-nativebundle-elementname.md) | OH_NativeBundle_ElementName | elementName信息。 |
| [OH_NativeBundle_Metadata](capi-native-bundle-oh-nativebundle-metadata.md) | OH_NativeBundle_Metadata | 元数据信息。 |
| [OH_NativeBundle_ModuleMetadata](capi-native-bundle-oh-nativebundle-modulemetadata.md) | OH_NativeBundle_ModuleMetadata | 模块元数据的信息。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_NativeBundle_ApplicationInfo OH_NativeBundle_GetCurrentApplicationInfo()](#oh_nativebundle_getcurrentapplicationinfo) | 获取当前应用信息，包含应用包名和应用指纹信息。 |
| [char* OH_NativeBundle_GetAppId()](#oh_nativebundle_getappid) | 获取当前应用的appId。appId是应用的唯一标识，由应用包名和签名信息决定。在使用此接口后，为了避免内存泄漏，需要手动释放接口返回的指针。 |
| [char* OH_NativeBundle_GetAppIdentifier()](#oh_nativebundle_getappidentifier)| 获取当前应用的应用程序标识符。该应用程序标识符在应用的整个生命周期中不会发生变化，包括版本更新、证书更改、公钥和私钥更改以及应用程序迁移。在使用此接口后，为了避免内存泄漏，需要手动释放接口返回的指针。 |
| [OH_NativeBundle_ElementName_OH_NativeBundle_GetMainElementName()](#oh_nativebundle_getmainelementname) | 获取当前应用入口元素mainElement的信息，包括包名、模块名和组件名。在使用此接口后，为了避免内存泄漏，需要手动释放接口返回的指针。 |
| [char* OH_NativeBundle_GetCompatibleDeviceType()](#oh_nativebundle_getcompatibledevicetype) | 获取当前应用适用的设备类型。在使用此接口后，为了避免内存泄漏，需要手动释放接口返回的指针。 |
| [bool OH_NativeBundle_IsDebugMode(bool* isDebugMode)](#oh_nativebundle_isdebugmode) | 查询当前应用的调试模式。 |
| [OH_NativeBundle_ModuleMetadata* OH_NativeBundle_GetModuleMetadata(size_t* size)](#oh_nativebundle_getmodulemetadata) | 获取当前应用程序的模块元数据数组。在使用此接口后，为了避免内存泄漏，需要手动释放接口返回的指针。 |
| [BundleManager_ErrorCode OH_NativeBundle_GetAbilityResourceInfo(char* fileType, OH_NativeBundle_AbilityResourceInfo** abilityResourceInfo, size_t* size)](#oh_nativebundle_getabilityresourceinfo) | 获取支持打开特定文件类型的组件资源信息列表。在使用完该接口之后，为了防止内存泄漏，需要调用[OH_AbilityResourceInfo_Destroy](capi-ability-resource-info-h.md#oh_abilityresourceinfo_destroy)进行释放。 |

## 函数说明

### OH_NativeBundle_GetCurrentApplicationInfo()

```
OH_NativeBundle_ApplicationInfo OH_NativeBundle_GetCurrentApplicationInfo()
```

**描述**

获取当前应用信息，包含应用包名和应用指纹信息。

**起始版本：** 9

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NativeBundle_ApplicationInfo](capi-native-bundle-oh-nativebundle-applicationinfo.md) | 返回新创建的OH_NativeBundle_ApplicationInfo对象。如果返回的对象为NULL，则表示创建失败。<br> 失败的可能原因是应用程序地址空间已满，导致空间分配失败。 |

### OH_NativeBundle_GetAppId()

```
char* OH_NativeBundle_GetAppId()
```

**描述**

获取当前应用的appId。appId是应用的唯一标识，由应用包名和签名信息决定。在使用此接口后，为了避免内存泄漏，需要手动释放接口返回的指针。

**起始版本：** 11

**返回：**

| 类型 | 说明 |
| -- | -- |
| char* | 返回一个新创建的字符串，用于指示appID信息。如果返回的对象为NULL，则表示创建失败。<br> 失败的可能原因是应用程序地址空间已满，导致空间分配失败。 |

### OH_NativeBundle_GetAppIdentifier()

```
char* OH_NativeBundle_GetAppIdentifier()
```

**描述**

获取当前应用的应用程序标识符。该应用程序标识符在应用的整个生命周期中不会发生变化，包括版本更新、证书更改、公钥和私钥更改以及应用程序迁移。在使用此接口后，为了避免内存泄漏，需要手动释放接口返回的指针。

**起始版本：** 11

**返回：**
| 类型 | 说明 |
| -- | -- |
| char* | 返回一个新创建的字符串，用于指示应用程序标识符信息。如果返回的对象为NULL，则表示创建失败。<br> 失败的可能原因是应用程序地址空间已满，导致空间分配失败。 |

### OH_NativeBundle_GetMainElementName()

```
OH_NativeBundle_ElementName OH_NativeBundle_GetMainElementName()
```

**描述**

获取当前应用入口元素mainElement的信息，包括包名、模块名和组件名，在使用此接口后，为了避免内存泄漏，需要手动释放接口返回的指针。

**起始版本：** 13

**返回：**
| 类型 | 说明 |
| -- | -- |
| [OH_NativeBundle_ElementName](capi-native-bundle-oh-nativebundle-elementname.md) | 返回新创建的OH_NativeBundle_ElementName对象。如果返回的对象为NULL，则表示创建失败。<br> 失败的可能原因是应用程序地址空间已满，导致空间分配失败。 |


### OH_NativeBundle_GetCompatibleDeviceType()

```
char* OH_NativeBundle_GetCompatibleDeviceType()
```

**描述**

获取当前应用适用的设备类型。用于将手机应用分发到平板/2in1设备时，合理适配布局和字体大小。在使用此接口后，为了避免内存泄漏，需要手动释放接口返回的指针。

**起始版本：** 14

**返回：**

| 类型 | 说明 |
| -- | -- |
| char* | 返回一个新创建的字符串，用于指示兼容设备类型。如果返回的对象为NULL，则表示创建失败。<br> 失败的可能原因是应用程序地址空间已满，导致空间分配失败。 |

### OH_NativeBundle_IsDebugMode()

```
bool OH_NativeBundle_IsDebugMode(bool* isDebugMode)
```

**描述**

查询当前应用是否处于调试模式。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| bool* isDebugMode | 表示应用是否处于调试模式，取值为true表示可调试模式，取值为false表示不可调试模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果调用成功，则返回true，否则返回false。 |

### OH_NativeBundle_GetModuleMetadata()

```
OH_NativeBundle_ModuleMetadata* OH_NativeBundle_GetModuleMetadata(size_t* size)
```

**描述**

获取当前应用程序的模块元数据数组。在使用该接口之后，为了防止内存泄漏，需要手动释放接口返回的指针。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| size_t* size | 表示模块元数据数组大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NativeBundle_ModuleMetadata*](capi-native-bundle-oh-nativebundle-modulemetadata.md) | 返回模块元数据数组，如果返回的对象为NULL，则表示获取失败。<br> 失败的可能原因是应用程序地址空间已满，导致空间分配失败。 |

### OH_NativeBundle_GetAbilityResourceInfo()

```
BundleManager_ErrorCode OH_NativeBundle_GetAbilityResourceInfo(char* fileType, OH_NativeBundle_AbilityResourceInfo** abilityResourceInfo, size_t* size)
```

**描述**

获取支持打开特定文件类型的组件资源信息列表。在使用完该接口之后，为了防止内存泄漏，需要调用[OH_AbilityResourceInfo_Destroy](capi-ability-resource-info-h.md#oh_abilityresourceinfo_destroy)进行释放。

**起始版本：** 21

**需要权限：** ohos.permission.GET_ABILITY_INFO

**参数：**

| 参数项 | 描述 |
| -- | -- |
| char* fileType | 表示待查询的特定文件类型，推荐使用[UTD类型](../../database/uniform-data-type-descriptors.md)，比如：'general.plain-text'、'general.image'。目前也可以兼容使用[MIME type类型](https://www.iana.org/assignments/media-types/media-types.xhtml?utm_source=ld246.com)和文件后缀名称，如：'text/xml' 、 '.png'等。文件后缀与文件类型的映射关系参见[UTD预置列表](../../database/uniform-data-type-list.md)。不支持传'\*/\*'。 |
| OH_NativeBundle_AbilityResourceInfo** abilityResourceInfo | 表示返回的组件资源信息列表。 |
| size_t* size | 表示返回的组件资源信息列表大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [BundleManager_ErrorCode](capi-bundle-manager-common-h.md#bundlemanager_errorcode) | 如果调用成功，返回[BUNDLE_MANAGER_ERROR_CODE_NO_ERROR](capi-bundle-manager-common-h.md#bundlemanager_errorcode)。<br> 如果调用方没有正确的权限，返回[BUNDLE_MANAGER_ERROR_CODE_PERMISSION_DENIED](capi-bundle-manager-common-h.md#bundlemanager_errorcode)。 |