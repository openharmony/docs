# ability_resource_info.h
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

提供组件资源信息的接口，用于获取组件的以下信息：包名、模块名、组件名、图标、分身索引、是否为默认应用等。

**引用文件：** <bundle/ability_resource_info.h>

**库：** libbundle_ndk.z.so

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**起始版本：** 21

**相关模块：** [Native_Bundle](capi-native-bundle.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_NativeBundle_AbilityResourceInfo](capi-native-bundle-oh-nativebundle-abilityresourceinfo.md) | OH_NativeBundle_AbilityResourceInfo | 表示组件资源信息。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [BundleManager_ErrorCode OH_NativeBundle_GetBundleName(OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, char** bundleName)](#oh_nativebundle_getbundlename) | 获取组件的包名。在使用该接口之后，为了防止内存泄漏，需要手动释放接口返回的指针。 |
| [BundleManager_ErrorCode OH_NativeBundle_GetModuleName(OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, char** moduleName)](#oh_nativebundle_getmodulename) | 获取组件的模块名。在使用该接口之后，为了防止内存泄漏，需要手动释放接口返回的指针。 |
| [BundleManager_ErrorCode OH_NativeBundle_GetAbilityName(OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, char** abilityName)](#oh_nativebundle_getabilityname) | 获取组件名。在使用该接口之后，为了防止内存泄漏，需要手动释放接口返回的指针。 |
| [BundleManager_ErrorCode OH_NativeBundle_GetIcon(OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, char** icon)](#oh_nativebundle_geticon) | 获取组件的图标资源。在使用该接口之后，为了防止内存泄漏，需要手动释放接口返回的指针。 |
| [BundleManager_ErrorCode OH_NativeBundle_GetLabel(OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, char** label)](#oh_nativebundle_getlabel) | 获取组件的应用名称。在使用该接口之后，为了防止内存泄漏，需要手动释放接口返回的指针。 |
| [BundleManager_ErrorCode OH_NativeBundle_GetAppIndex(OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, int* appIndex)](#oh_nativebundle_getappindex) | 获取组件的分身索引。 |
| [BundleManager_ErrorCode OH_NativeBundle_CheckDefaultApp(OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, bool* isDefault)](#oh_nativebundle_checkdefaultapp) | 查询组件所属的应用是否为默认应用。 |
| [BundleManager_ErrorCode OH_AbilityResourceInfo_Destroy(OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, size_t count)](#oh_abilityresourceinfo_destroy) | 该接口应在对[OH_NativeBundle_GetAbilityResourceInfo](capi-native-interface-bundle-h.md#oh_nativebundle_getabilityresourceinfo)的使用完成后调用，以避免内存泄漏。 |
| [int OH_NativeBundle_GetSize()](#oh_nativebundle_getsize) | 获取单个结构体[OH_NativeBundle_AbilityResourceInfo](capi-native-bundle-oh-nativebundle-abilityresourceinfo.md)的大小。 |

## 函数说明

### OH_NativeBundle_GetBundleName()

```
BundleManager_ErrorCode OH_NativeBundle_GetBundleName(OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, char** bundleName)
```

**描述**

获取组件的包名。在使用该接口之后，为了防止内存泄漏，需要手动释放接口返回的指针。

**起始版本：** 21


**参数：**

| 参数项 | 描述 |
| -- | -- |
| OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo | 指定组件资源信息。 |
| char** bundleName | 获取的包名。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [BundleManager_ErrorCode](capi-bundle-manager-common-h.md#bundlemanager_errorcode) | 执行结果。<br>         如果操作成功，返回[BUNDLE_MANAGER_ERROR_CODE_NO_ERROR](capi-bundle-manager-common-h.md#bundlemanager_errorcode)。<br>         如果abilityResourceInfo为空指针，返回[BUNDLE_MANAGER_ERROR_CODE_PARAM_INVALID](capi-bundle-manager-common-h.md#bundlemanager_errorcode)。 |

### OH_NativeBundle_GetModuleName()

```
BundleManager_ErrorCode OH_NativeBundle_GetModuleName(OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, char** moduleName)
```

**描述**

获取组件的模块名。在使用该接口之后，为了防止内存泄漏，需要手动释放接口返回的指针。

**起始版本：** 21


**参数：**

| 参数项 | 描述 |
| -- | -- |
| OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo | 指定组件资源信息。 |
| char** moduleName | 获取的模块名。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [BundleManager_ErrorCode](capi-bundle-manager-common-h.md#bundlemanager_errorcode) | 执行结果。<br>         如果操作成功，返回[BUNDLE_MANAGER_ERROR_CODE_NO_ERROR](capi-bundle-manager-common-h.md#bundlemanager_errorcode)。<br>         如果abilityResourceInfo为空指针，返回[BUNDLE_MANAGER_ERROR_CODE_PARAM_INVALID](capi-bundle-manager-common-h.md#bundlemanager_errorcode)。 |

### OH_NativeBundle_GetAbilityName()

```
BundleManager_ErrorCode OH_NativeBundle_GetAbilityName(OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, char** abilityName)
```

**描述**

获取组件名。在使用该接口之后，为了防止内存泄漏，需要手动释放接口返回的指针。

**起始版本：** 21


**参数：**

| 参数项 | 描述 |
| -- | -- |
| OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo | 指定组件资源信息。 |
| char** abilityName | 获取的组件名。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [BundleManager_ErrorCode](capi-bundle-manager-common-h.md#bundlemanager_errorcode) | 执行结果。<br>         如果操作成功，返回[BUNDLE_MANAGER_ERROR_CODE_NO_ERROR](capi-bundle-manager-common-h.md#bundlemanager_errorcode)。<br>         如果abilityResourceInfo为空指针，返回[BUNDLE_MANAGER_ERROR_CODE_PARAM_INVALID](capi-bundle-manager-common-h.md#bundlemanager_errorcode)。 |

### OH_NativeBundle_GetIcon()

```
BundleManager_ErrorCode OH_NativeBundle_GetIcon(OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, char** icon)
```

**描述**

获取组件的图标资源。在使用该接口之后，为了防止内存泄漏，需要手动释放接口返回的指针。

**起始版本：** 21


**参数：**

| 参数项 | 描述 |
| -- | -- |
| OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo | 指定组件资源信息。 |
| char** icon | 图标资源对应的base64编码。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [BundleManager_ErrorCode](capi-bundle-manager-common-h.md#bundlemanager_errorcode) | 执行结果。<br>         如果操作成功，返回[BUNDLE_MANAGER_ERROR_CODE_NO_ERROR](capi-bundle-manager-common-h.md#bundlemanager_errorcode)。<br>         如果abilityResourceInfo为空指针，返回[BUNDLE_MANAGER_ERROR_CODE_PARAM_INVALID](capi-bundle-manager-common-h.md#bundlemanager_errorcode)。 |

### OH_NativeBundle_GetLabel()

```
BundleManager_ErrorCode OH_NativeBundle_GetLabel(OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, char** label)
```

**描述**

获取组件的应用名称。在使用该接口之后，为了防止内存泄漏，需要手动释放接口返回的指针。

**起始版本：** 21


**参数：**

| 参数项 | 描述 |
| -- | -- |
| OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo |  指定组件资源信息。 |
| char** label | 获取的应用名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [BundleManager_ErrorCode](capi-bundle-manager-common-h.md#bundlemanager_errorcode) | 执行结果。<br>         如果操作成功，返回[BUNDLE_MANAGER_ERROR_CODE_NO_ERROR](capi-bundle-manager-common-h.md#bundlemanager_errorcode)。<br>         如果abilityResourceInfo为空指针，返回[BUNDLE_MANAGER_ERROR_CODE_PARAM_INVALID](capi-bundle-manager-common-h.md#bundlemanager_errorcode)。 |

### OH_NativeBundle_GetAppIndex()

```
BundleManager_ErrorCode OH_NativeBundle_GetAppIndex(OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, int* appIndex)
```

**描述**

获取组件的分身索引。

**起始版本：** 21


**参数：**

| 参数项 | 描述 |
| -- | -- |
| OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo | 指定组件资源信息。 |
| int* appIndex | 获取的分身索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [BundleManager_ErrorCode](capi-bundle-manager-common-h.md#bundlemanager_errorcode) | 执行结果。<br>         如果操作成功，返回[BUNDLE_MANAGER_ERROR_CODE_NO_ERROR](capi-bundle-manager-common-h.md#bundlemanager_errorcode)。<br>         如果abilityResourceInfo为空指针，返回[BUNDLE_MANAGER_ERROR_CODE_PARAM_INVALID](capi-bundle-manager-common-h.md#bundlemanager_errorcode)。 |

### OH_NativeBundle_CheckDefaultApp()

```
BundleManager_ErrorCode OH_NativeBundle_CheckDefaultApp(OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, bool* isDefault)
```

**描述**

查询组件所属的应用是否为默认应用。

**起始版本：** 21


**参数：**

| 参数项 | 描述 |
| -- | -- |
| OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo | 指定组件资源信息。 |
| bool* isDefault | 组件所属的应用是否为默认应用，默认应用是指用户为特定文件类型或操作设定的首选应用。取值true为默认应用，false为非默认应用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [BundleManager_ErrorCode](capi-bundle-manager-common-h.md#bundlemanager_errorcode) | 执行结果。<br>         如果操作成功，返回[BUNDLE_MANAGER_ERROR_CODE_NO_ERROR](capi-bundle-manager-common-h.md#bundlemanager_errorcode)。<br>         如果abilityResourceInfo为空指针，返回[BUNDLE_MANAGER_ERROR_CODE_PARAM_INVALID](capi-bundle-manager-common-h.md#bundlemanager_errorcode)。 |

### OH_AbilityResourceInfo_Destroy()

```
BundleManager_ErrorCode OH_AbilityResourceInfo_Destroy(OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo, size_t count)
```

**描述**

释放组件资源信息的内存。

**起始版本：** 21


**参数：**

| 参数项 | 描述 |
| -- | -- |
| OH_NativeBundle_AbilityResourceInfo* abilityResourceInfo | 要释放的组件资源信息。 |
| size_t count | 表示组件资源信息数组的大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [BundleManager_ErrorCode](capi-bundle-manager-common-h.md#bundlemanager_errorcode) | 执行结果。<br>         如果操作成功，返回[BUNDLE_MANAGER_ERROR_CODE_NO_ERROR](capi-bundle-manager-common-h.md#bundlemanager_errorcode)。<br>         如果abilityResourceInfo为空指针，返回[BUNDLE_MANAGER_ERROR_CODE_PARAM_INVALID](capi-bundle-manager-common-h.md#bundlemanager_errorcode)。 |

### OH_NativeBundle_GetSize()

```
int OH_NativeBundle_GetSize()
```

**描述**

获取单个结构体[OH_NativeBundle_AbilityResourceInfo](capi-native-bundle-oh-nativebundle-abilityresourceinfo.md)的大小。

**起始版本：** 21

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回单个结构体[OH_NativeBundle_AbilityResourceInfo](capi-native-bundle-oh-nativebundle-abilityresourceinfo.md)的大小。 |


