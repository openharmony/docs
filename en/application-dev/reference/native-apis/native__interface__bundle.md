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
| [OH_NativeBundle_GetCurrentApplicationInfo()](#oh_nativebundle_getcurrentapplicationinfo)| Obtains the information about the current application.|


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
