# OH_NativeBundle_ApplicationInfo


## Overview

The **OH_NativeBundle_ApplicationInfo** struct defines the application information.

It is an output parameter of [OH_NativeBundle_GetCurrentApplicationInfo()](_bundle.md#oh_nativebundle_getcurrentapplicationinfo).

**Since**

9

**Related Modules**

[Bundle](_bundle.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [bundleName](#bundlename) | Bundle name of the application.|
| [fingerprint](#fingerprint) | Fingerprint information of the bundle.|
| [appId<sup>11+</sup>](#appid) | Application ID.|
| [appIdentifier<sup>11+</sup>](#appidentifier) | Application identifier. |


## Member Variable Description


### bundleName


```
char* OH_NativeBundle_ApplicationInfo::bundleName
```

**Description**

Bundle name of the application.

**Since**

9


### fingerprint


```
char* OH_NativeBundle_ApplicationInfo::fingerprint
```

**Description**

Fingerprint information of the bundle.

**Since**

9


### appId


```
char* OH_NativeBundle_ApplicationInfo::appId
```

**Description**

Application ID.

**Since**

11

### appIdentifier


```
char* OH_NativeBundle_ApplicationInfo::appIdentifier
```

**Description**

Unique ID of the application, which is allocated by the cloud. This ID does not change along the application lifecycle, including version updates, certificate changes, public and private key changes, and application transfers.

**Since**

11
