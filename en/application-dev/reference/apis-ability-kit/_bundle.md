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



### Functions

| Name| Description|
| -------- | -------- |
| [OH_NativeBundle_GetCurrentApplicationInfo](#oh_nativebundle_getcurrentapplicationinfo) | Obtains the information about the current application.|
| [OH_NativeBundle_GetAppId](#oh_nativebundle_getappid) | Obtains the appId information about the current application.|
| [OH_NativeBundle_GetAppIdentifier](#oh_nativebundle_getappidentifier) | Obtains the appIdentifier information about the current application.|
| [OH_NativeBundle_GetMainElementName](#oh_nativebundle_getmainelementname) | Obtains the application entry information.|
| [OH_NativeBundle_GetCompatibleDeviceType](_bundle.md#oh_nativebundle_getcompatibledevicetype) | Obtains the compatible device type of the application.|


## Function Description


### OH_NativeBundle_GetCurrentApplicationInfo()

```
OH_NativeBundle_ApplicationInfo OH_NativeBundle_GetCurrentApplicationInfo()
```

**Description**

Obtains the information about the current application.

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

Obtains the appIdentifier information about the current application. appIdentifier is the unique ID of the application, which is allocated by the cloud. This ID does not change along the application lifecycle, including version updates, certificate changes, public and private key changes, and application transfers.

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

Obtains the compatible device type of the application.

**Since**: 14

**Returns**

Returns a string indicating the compatible device type.
