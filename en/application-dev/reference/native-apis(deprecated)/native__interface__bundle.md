# native_interface_bundle.h


## Overview

The **native_interface_bundle.h** file declares the APIs for querying application information.

**Since**

9

**Related Modules**

[bundle](_bundle.md)


## Summary


### Structs

| Name| Description|
| -------- | -------- |
| [OH_NativeBundle_ApplicationInfo](_o_h___native_bundle_application_info.md) | Defines the application information.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_NativeBundle_GetCurrentApplicationInfo](#oh_nativebundle_getcurrentapplicationinfo)| Obtains the information about the current application.|
| [OH_NativeBundle_GetAppId](native__interface__bundle.md#oh_nativebundle_getappid) | Obtains the appId information about the current application.|
| [OH_NativeBundle_GetAppIdentifier](native__interface__bundle.md#oh_nativebundle_getappidentifier) | Obtains the appIdentifier information about the current application.|


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
