# native_interface_bundle.h
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

## Overview

The module provides capabilities for querying the application's bundle information, such as the bundle name and fingerprint information.

**File to include**: <bundle/native_interface_bundle.h>

**Library**: libbundle_ndk.z.so

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Since**: 9

**Related module**: [Native_Bundle](capi-native-bundle.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_NativeBundle_ApplicationInfo](capi-native-bundle-oh-nativebundle-applicationinfo.md) | OH_NativeBundle_ApplicationInfo | Describes the application information, including the bundle name and fingerprint information.|
| [OH_NativeBundle_ElementName](capi-native-bundle-oh-nativebundle-elementname.md) | OH_NativeBundle_ElementName | Describes the elementName information.|
| [OH_NativeBundle_Metadata](capi-native-bundle-oh-nativebundle-metadata.md) | OH_NativeBundle_Metadata | Describes the metadata information.|
| [OH_NativeBundle_ModuleMetadata](capi-native-bundle-oh-nativebundle-modulemetadata.md) | OH_NativeBundle_ModuleMetadata | Describes the metadata of a module.|

### Functions

| Name| Description|
| -- | -- |
| [OH_NativeBundle_ApplicationInfo OH_NativeBundle_GetCurrentApplicationInfo()](#oh_nativebundle_getcurrentapplicationinfo) | Obtains the current application information, including the bundle name and fingerprint information.|
| [char* OH_NativeBundle_GetAppId()](#oh_nativebundle_getappid) | Obtains the appId of the current application. The appId is the unique identifier of an application and is determined by the bundle name and signature information of the application. After using this function, you must manually release the pointer returned to prevent memory leakage.|
| [char* OH_NativeBundle_GetAppIdentifier()](#oh_nativebundle_getappidentifier)| Obtains the appIdentifier of the current application. The appIdentifier does not change throughout the application lifecycle, including version updates, certificate changes, public and private key changes, and application migration. After using this function, you must manually release the pointer returned to prevent memory leakage.|
| [OH_NativeBundle_ElementName_OH_NativeBundle_GetMainElementName()](#oh_nativebundle_getmainelementname) | Obtains the mainElement information of the current application, including the bundle name, module name, and ability name. After using this function, you must manually release the pointer returned to prevent memory leakage.|
| [char* OH_NativeBundle_GetCompatibleDeviceType()](#oh_nativebundle_getcompatibledevicetype) | Obtains the compatible device type of the current application. After using this function, you must manually release the pointer returned to prevent memory leakage.|
| [bool OH_NativeBundle_IsDebugMode(bool* isDebugMode)](#oh_nativebundle_isdebugmode) | Checks whether the current application is in debug mode.|
| [OH_NativeBundle_ModuleMetadata* OH_NativeBundle_GetModuleMetadata(size_t* size)](#oh_nativebundle_getmodulemetadata) | Obtains the module metadata array of the current application. After using this function, you must manually release the pointer returned to prevent memory leakage.|

## Function Description

### OH_NativeBundle_GetCurrentApplicationInfo()

```
OH_NativeBundle_ApplicationInfo OH_NativeBundle_GetCurrentApplicationInfo()
```

**Description**

Obtains the current application information, including the bundle name and fingerprint information.

**Since**: 9

**Returns**

| Type| Description|
| -- | -- |
| [OH_NativeBundle_ApplicationInfo](capi-native-bundle-oh-nativebundle-applicationinfo.md) | Pointer to the OH_NativeBundle_ApplicationInfo object. If the returned object is NULL, the creation fails.<br>The possible cause is that the application address space is full, causing space allocation to fail.|

### OH_NativeBundle_GetAppId()

```
char* OH_NativeBundle_GetAppId()
```

**Description**

Obtains the appId of the current application. The appId is the unique identifier of an application and is determined by the bundle name and signature information of the application. After using this function, you must manually release the pointer returned to prevent memory leakage.

**Since**: 11

**Returns**

| Type| Description|
| -- | -- |
| char* | Pointer to a new string that indicates the appID. If the returned object is NULL, the creation fails.<br>The possible cause is that the application address space is full, causing space allocation to fail.|

### OH_NativeBundle_GetAppIdentifier()

```
char* OH_NativeBundle_GetAppIdentifier()
```

**Description**

Obtains the appIdentifier of the current application. The appIdentifier does not change throughout the application lifecycle, including version updates, certificate changes, public and private key changes, and application migration. After using this function, you must manually release the pointer returned to prevent memory leakage.

**Since**: 11

**Returns**
| Type| Description|
| -- | -- |
| char* | Pointer to a new string that indicates the appIdentifier. If the returned object is NULL, the creation fails.<br>The possible cause is that the application address space is full, causing space allocation to fail.|

### OH_NativeBundle_GetMainElementName()

```
OH_NativeBundle_ElementName OH_NativeBundle_GetMainElementName()
```

**Description**

Obtains the mainElement information of the current application, including the bundle name, module name, and ability name. After using this function, you must manually release the pointer returned to prevent memory leakage.

**Since**: 13

**Returns**
| Type| Description|
| -- | -- |
| [OH_NativeBundle_ElementName](capi-native-bundle-oh-nativebundle-elementname.md) | Pointer to the OH_NativeBundle_ElementName object. If the returned object is NULL, the creation fails.<br>The possible cause is that the application address space is full, causing space allocation to fail.|


### OH_NativeBundle_GetCompatibleDeviceType()

```
char* OH_NativeBundle_GetCompatibleDeviceType()
```

**Description**

Obtains the compatible device type of the current application. It helps you optimize the layout and font size when distributing mobile applications to tablets or 2-in-1 devices. After using this function, you must manually release the pointer returned to prevent memory leakage.

**Since**: 14

**Returns**

| Type| Description|
| -- | -- |
| char* | Pointer to a new string that indicates the compatible device type. If the returned object is NULL, the creation fails.<br>The possible cause is that the application address space is full, causing space allocation to fail.|

### OH_NativeBundle_IsDebugMode()

```
bool OH_NativeBundle_IsDebugMode(bool* isDebugMode)
```

**Description**

Checks whether the current application is in debug mode.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| bool* isDebugMode | Pointer to the check result indicating whether the application is in debug mode. **true** if in debug mode, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Operation result. **true** if the call is successful, **false** otherwise.|

### OH_NativeBundle_GetModuleMetadata()

```
OH_NativeBundle_ModuleMetadata* OH_NativeBundle_GetModuleMetadata(size_t* size)
```

**Description**

Obtains the module metadata array of the current application. After using this function, you must manually release the pointer returned to prevent memory leakage.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| size_t* size | Pointer to the size of the module metadata array.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NativeBundle_ModuleMetadata*](capi-native-bundle-oh-nativebundle-modulemetadata.md) | An array of module metadata. If the returned object is NULL, the retrieval fails.<br>The possible cause is that the application address space is full, causing space allocation to fail.|
