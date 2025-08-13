# bundle


## Overview

The bundle module provides APIs for querying application information.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Since**: 9


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [native_interface_bundle.h](native__interface__bundle.md) | Provides application information structs and functions.<br>**File to include**: &lt;bundle/native_interface_bundle.h&gt;<br>**Library**: libbundle_ndk.z.so|


### Structs

| Name| Description|
| -------- | -------- |
| [OH_NativeBundle_ApplicationInfo](_o_h___native_bundle_application_info.md) | Describes the application information.|
| [OH_NativeBundle_ElementName](_o_h___native_bundle_element_name.md) | Describes the application entry information.|
| [OH_NativeBundle_Metadata](native_interface_bundle_metadata.md) | Describes the metadata of the application.|
| [OH_NativeBundle_ModuleMetadata](native_interface_bundle_module_metadata.md) | Describes the module metadata of the application.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_NativeBundle_GetCurrentApplicationInfo](#oh_nativebundle_getcurrentapplicationinfo) | Obtains the current application information.|
| [OH_NativeBundle_GetAppId](#oh_nativebundle_getappid) | Obtains the appId information about the current application.|
| [OH_NativeBundle_GetAppIdentifier](#oh_nativebundle_getappidentifier) | Obtains the appIdentifier information about the current application.|
| [OH_NativeBundle_GetMainElementName](#oh_nativebundle_getmainelementname) | Obtains the entry information about the current application.|
| [OH_NativeBundle_GetCompatibleDeviceType](_bundle.md#oh_nativebundle_getcompatibledevicetype) | Obtains the compatible device type of the current application.|
| [OH_NativeBundle_IsDebugMode](#oh_nativebundle_isdebugmode) | Checks whether the current application is in debug mode.|
| [OH_NativeBundle_GetModuleMetadata](#oh_nativebundle_getmodulemetadata) | Obtains the metadata information of the application.|

## Function Description


### OH_NativeBundle_GetCurrentApplicationInfo()

```
OH_NativeBundle_ApplicationInfo OH_NativeBundle_GetCurrentApplicationInfo()
```

**Description**

Obtains the current application information.

**Since**: 9

**Returns**

Returns the [OH_NativeBundle_ApplicationInfo](_o_h___native_bundle_application_info.md) struct.

### OH_NativeBundle_GetAppId()

```
char* OH_NativeBundle_GetAppId()
```

**Description**

Obtains the appId information about the current application.

**Since**: 11

**Returns**

Returns a string that describes the appId information of the application.

### OH_NativeBundle_GetAppIdentifier()

```
char* OH_NativeBundle_GetAppIdentifier()
```

**Description**

Obtains the appIdentifier information about the current application. appIdentifier is the unique ID of the application. It is the [app ID](https://developer.huawei.com/consumer/en/doc/app/agc-help-createharmonyapp-0000001945392297), which is a random string, allocated by AppGallery Connect during the creation of the application. This ID does not change along the application lifecycle, including version updates, certificate changes, public and private key changes, and application transfers. If you use multiple debugging devices, perform debugging offline, or need to interact with other applications, you are advised to use [manual signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section297715173233).

**Since**: 11

**Returns**

Returns a string that describes the appIdentifier information of the application.

### OH_NativeBundle_GetMainElementName()

```
OH_NativeBundle_ElementName OH_NativeBundle_GetMainElementName()
```

**Description**

Obtains the application entry information, including the bundle name, module name, and ability name.

**Since**: 13

**Returns**

Returns the [OH_NativeBundle_ElementName](_o_h___native_bundle_element_name.md) struct.

### OH_NativeBundle_GetCompatibleDeviceType()

```
char* OH_NativeBundle_GetCompatibleDeviceType()
```

**Description**

Obtains the compatible device type of the current application. It helps you optimize the layout and font size when distributing mobile applications to tablets or 2-in-1 devices.

**Since**: 14

**Returns**

Returns a string indicating the compatible device type.

### OH_NativeBundle_IsDebugMode

```
bool OH_NativeBundle_IsDebugMode(bool* isDebugMode)
```

**Description**

Checks whether the current application is in debug mode.

**Since**: 20

**Parameters**

| Name| Description|
| -------- | -------- |
| isDebugMode | Pointer to the check result. The value **true** means that the application is in debug mode, and **false** means the opposite.|

**Returns**

Operation result. The value **true** is returned if the call is successful, and **false** is returned otherwise.

### OH_NativeBundle_GetModuleMetadata

```
OH_NativeBundle_ModuleMetadata* OH_NativeBundle_GetModuleMetadata(size_t* size)
```

**Description**

Obtains the module metadata array of the current application. After using this function, you must manually release the pointer returned to prevent memory leakage.

**Since**: 20

**Parameters**

| Name| Description|
| -------- | -------- |
| size | Pointer to the size of the module metadata array.|

**Returns**

An array of module metadata. If the returned object is NULL, the retrieval fails.

The possible cause is that the application address space is full, causing space allocation to fail.
