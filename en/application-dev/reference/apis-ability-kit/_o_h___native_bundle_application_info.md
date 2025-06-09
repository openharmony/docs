# OH_NativeBundle_ApplicationInfo


## Overview

The **OH_NativeBundle_ApplicationInfo** struct defines the application information.

It is an output parameter of [OH_NativeBundle_GetCurrentApplicationInfo()](_bundle.md#oh_nativebundle_getcurrentapplicationinfo).

**Since**: 9

**Related module**: [Bundle](_bundle.md)

**Header file**: [native_interface_bundle.h](native__interface__bundle.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [bundleName](#bundlename) | Bundle name of the application.|
| [fingerprint](#fingerprint) | Fingerprint information of the bundle.|


## Member Variable Description


### bundleName


```
char* OH_NativeBundle_ApplicationInfo::bundleName
```

**Description**

Bundle name of the application.

**Since**: 9


### fingerprint


```
char* OH_NativeBundle_ApplicationInfo::fingerprint
```

**Description**

Fingerprint information of the bundle.

**Since**: 9
