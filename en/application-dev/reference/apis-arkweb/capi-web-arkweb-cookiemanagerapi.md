# ArkWeb_CookieManagerAPI

## Overview

Defines the native cookie manager APIs provided by ArkWeb. Before calling the API, you are advised to use **ARKWEB_MEMBER_MISSING** to check whether the function struct has the corresponding pointer to avoid crash caused by mismatch between the SDK and the device ROM.

**Since**: 12

**Related module**: [Web](capi-web.md)

**Header file**: [arkweb_type.h](capi-arkweb-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| size_t size | Size of the struct.|


### Member Functions

| Name                                                                                                                                       | Description               |
|-------------------------------------------------------------------------------------------------------------------------------------------|--------------------|
| [ArkWeb_ErrorCode (\*fetchCookieSync)(const char* url, bool incognito, bool includeHttpOnly, char** cookieValue)](#fetchcookiesync)       | Obtains the cookie value of a specified URL.|
| [ArkWeb_ErrorCode (\*configCookieSync)(const char* url,const char* cookieValue, bool incognito, bool includeHttpOnly)](#configcookiesync) | Sets the cookie value of a specified URL.  |
| [bool (\*existCookies)(bool incognito)](#existcookies)                                                                                    | Checks whether cookies exist.     |
| [void (\*clearAllCookiesSync)(bool incognito)](#clearallcookiessync)                                                                      | Clears all cookies.      |
| [void (*clearSessionCookiesSync)()](#clearsessioncookiessync)                                                                             | Clears all session cookies.                  |

## Member Function Description

### fetchCookieSync()

```
ArkWeb_ErrorCode (*fetchCookieSync)(const char* url, bool incognito, bool includeHttpOnly, char** cookieValue)
```

**Description**

Obtains the cookie value of a specified URL.

**Parameters**

| Name| Description|
| -- | -- |
| const char* url | URL of the cookie to obtain. A complete URL is recommended.|
|  bool incognito | Whether to obtain the webview memory cookie in incognito mode or in non-incognito mode. The value **true** means to obtain the webview memory cookie in incognito mode, and the value **false** means the opposite.|
|  bool includeHttpOnly | Whether to include the cookie marked as **HttpOnly** in **cookieValue**.|
|  char** cookieValue |  Cookie value of the URL.|

**Returns**

| Type                                                              | Description                                                                                                                        |
|------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------|
| [ArkWeb_ErrorCode](capi-arkweb-error-code-h.md#arkweb_errorcode) | Error code.<br>[ARKWEB_SUCCESS](capi-arkweb-error-code-h.md#arkweb_errorcode): The cookie is successfully obtained.<br>[ARKWEB_INVALID_URL](capi-arkweb-error-code-h.md#arkweb_errorcode): The URL is invalid.<br>[ARKWEB_INVALID_PARAM](capi-arkweb-error-code-h.md#arkweb_errorcode): The parameter is invalid.|

### configCookieSync()

```
ArkWeb_ErrorCode (*configCookieSync)(const char* url,const char* cookieValue, bool incognito, bool includeHttpOnly)
```

**Description**

Sets the cookie value of a specified URL.

**Parameters**

| Name| Description|
| -- | -- |
| const char* url | URL of the specified cookie. It must be a complete URL.|
| const char* cookieValue | Cookie value to be set.|
|  bool incognito | Whether to set the cookie of corresponding URL in incognito mode. The value **true** means to set the cookie of corresponding URL in incognito mode, and **false** means the opposite.|
|  bool includeHttpOnly | Whether to overwrite the cookie marked as **HTTPOnly**. The value **true** means to overwrite the cookie marked as **HTTPOnly**, and **false** means the opposite.|

**Returns**

| Type                                                              | Description                                                                                                                        |
|------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------|
| [ArkWeb_ErrorCode](capi-arkweb-error-code-h.md#arkweb_errorcode) | Error code.<br>[ARKWEB_SUCCESS](capi-arkweb-error-code-h.md#arkweb_errorcode): The cookie is successfully obtained.<br>[ARKWEB_INVALID_URL](capi-arkweb-error-code-h.md#arkweb_errorcode): The URL is invalid.<br>[ARKWEB_INVALID_PARAM](capi-arkweb-error-code-h.md#arkweb_errorcode): The parameter is invalid.|

### existCookies()

```
bool (*existCookies)(bool incognito)
```

**Description**

Checks whether cookies exist.

**Returns**

| Type| Description|
|----|----|
| bool   | **true** is returned if the cookie exists; otherwise, **false** is returned.  |

### clearAllCookiesSync()

```
void (*clearAllCookiesSync)(bool incognito)
```

**Description**

Clears all cookies.

**Returns**

| Type| Description|
|----|----|
| bool incognito   | Whether to clear all cookies in incognito mode. The value **true** means to clear all cookies in incognito mode, and **false** means the opposite.  |


### clearSessionCookiesSync()

```
void (*clearSessionCookiesSync)()
```

**Description**

Clears all session cookies.
