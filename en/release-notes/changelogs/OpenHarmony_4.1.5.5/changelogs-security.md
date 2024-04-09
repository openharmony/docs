# Security Changelog

## cl.security.1 Deprecation of getSdkVersion and enum HUKS_AES_KEY_SIZE_512

**Access Level**

Public

**Reason for Change**

The **getSdkVersion** API and **enum HUKS_AES_KEY_SIZE_512** are reserved interfaces without any functionality.  These interfaces are redundant and therefore deprecated.

**Change Impact**

The change is not compatible with earlier versions. Use the new API in your code.

**API Level**
8

**Deprecated Since**

OpenHarmony SDK 4.1.5.5

**Deprecated APIs**

| API                                                    | Description                                                    | Substitute API                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| function getSdkVersion(options: HuksOptions): string; | This interface is reserved, and its function is not implemented.            | N/A|
| enum HUKS_AES_KEY_SIZE_512                           | This interface is reserved, and its function is not implemented.                | N/A         |

**Adaptation Guide**

Delete the API if the deprecated API is used.
