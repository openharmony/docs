# arkweb_error_code.h

## Overview

Declares the error codes of the ArkWeb NDK APIs.

**Library**: libohweb.so

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Related module**: [Web](capi-web.md)

## Summary

### Enums

| Name                                   | typedef Keyword| Description|
|---------------------------------------|------------|----|
| [ArkWeb_ErrorCode](#arkweb_errorcode) | ArkWeb_ErrorCode  | Enumerates the error codes of ArkWeb NDK APIs. |

## Enum Description

### ArkWeb_ErrorCode

```
enum ArkWeb_ErrorCode
```

**Description**

Enumerates the error codes of ArkWeb NDK APIs.

**Since**: 12

| Enum Item                                    | Description                                               |
| ------------------------------------------ | --------------------------------------------------- |
| ARKWEB_SUCCESS = 0                         | Operation successful.                                             |
| ARKWEB_INIT_ERROR = 17100001               | Initialization error.                                       |
| ARKWEB_ERROR_UNKNOWN = 17100100            | Unknown error.                                         |
| ARKWEB_INVALID_PARAM = 17100101            | Invalid parameter.                                         |
| ARKWEB_SCHEME_REGISTER_FAILED = 17100102   | Failed to register the scheme. Register the scheme before creating the **Web** component.   |
| ARKWEB_INVALID_URL = 17100103 = 17100104   | Invalid URL.                                        |
| ARKWEB_INVALID_COOKIE_VALUE = 17100104     | Invalid cookie value.                                   |
| ARKWEB_LIBRARY_OPEN_FAILURE = 17100105     | Failed to open the dynamic link library.<br>**Since**: 15          |
| ARKWEB_LIBRARY_SYMBOL_NOT_FOUND = 17100106 | The required symbol cannot be found in the dynamic link library.<br>**Since**: 15|
| ARKWEB_COOKIE_MANAGER_NOT_INITIALIZED = 17100107 | **CookieManager** is not initialized.<br>**Since**: 20|
| ARKWEB_COOKIE_MANAGER_INITIALIZE_FAILED = 17100108 | **CookieManager** fails to be initialized.<br>**Since**: 20|
| ARKWEB_COOKIE_SAVE_FAILED = 17100109 | Cookies fail to be saved.<br>**Since**: 20|

### ArkWeb_BlanklessErrorCode

```
enum ArkWeb_BlanklessErrorCode
```

**Description**

Enumerates the error codes for the blankless loading.

**Since**: 20

| Enum Item                                    | Description                                               |
| ------------------------------------------ | --------------------------------------------------- |
| ARKWEB_BLANKLESS_SUCCESS = 0               | Operation successful.                                              |
| ARKWEB_BLANKLESS_ERR_UNKNOWN = -1          | Unknown error or internal status error.                            |
| ARKWEB_BLANKLESS_ERR_INVALID_ARGS = -2     | Invalid parameter.                                         |
| ARKWEB_BLANKLESS_ERR_CONTROLLER_NOT_INITED = -3 | **WebViewController** is not bound to any component.                      |
| ARKWEB_BLANKLESS_ERR_KEY_NOT_MATCH = -4    | The key value is not matched. The **OH_NativeArkWeb_SetBlanklessLoadingWithKey** and **OH_NativeArkWeb_GetBlanklessInfoWithKey** APIs must be used in pair and use the same key value.|
| ARKWEB_BLANKLESS_ERR_SIGNIFICANT_CHANGE = -5 | When the similarity is low, the system will deem the scene change too abrupt and frame insertion through the **OH_NativeArkWeb_SetBlanklessLoadingWithKey** API will fail.|
| ARKWEB_BLANKLESS_ERR_DEVICE_NOT_SUPPORT = 801 | This device does not support this feature.|
