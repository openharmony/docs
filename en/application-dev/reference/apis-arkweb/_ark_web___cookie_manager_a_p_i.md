# ArkWeb_CookieManagerAPI


## Overview

Defines the native cookie manager APIs provided by ArkWeb. Before calling the API, you are advised to use **ARKWEB_MEMBER_MISSING** to check whether the function struct has the corresponding pointer to avoid crash caused by mismatch between the SDK and the device ROM.

**Since**: 12

**Related module**: [Web](_web.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| size_t [size](#size) | Size of the struct. |
| [ArkWeb_ErrorCode](_web.md#arkweb_errorcode)(\* [fetchCookieSync](#fetchcookiesync) )(const char \*url, bool incognito, bool includeHttpOnly, char \*\*cookieValue) | Pointer to the function used to obtain the cookie value of a specified URL. |
| [ArkWeb_ErrorCode](_web.md#arkweb_errorcode)(\* [configCookieSync](#configcookiesync) )(const char \*url, const char \*cookieValue, bool incognito, bool includeHttpOnly) | Pointer to the function used to set the cookie value of a specified URL. |
| bool(\* [existCookies](#existcookies) )(bool incognito) | Pointer to the function used to check whether the cookie exists. |
| void(\* [clearAllCookiesSync](#clearallcookiessync) )(bool incognito) | Pointer to the function used to clear all cookies. |
|  void(\* clearSessionCookiesSync )() | Pointer to the function used to clear all session cookies. |


## Member Variable Description


### clearAllCookiesSync

```
void(* ArkWeb_CookieManagerAPI::clearAllCookiesSync) (bool incognito)
```
**Description**

Pointer to the function used to clear all cookies.

**Parameters**

| Name| Description|
| -------- | -------- |
| incognito | Whether to clear all cookies in incognito mode (true) or in non-incognito mode (false) |


### configCookieSync

```
ArkWeb_ErrorCode(* ArkWeb_CookieManagerAPI::configCookieSync) (const char *url, const char *cookieValue, bool incognito, bool includeHttpOnly)
```
**Description**

Pointer to the function used to set the cookie value of a specified URL.

**Parameters**

| Name| Description|
| -------- | -------- |
| url | The URL to which the cookie belongs. It must be a complete URL. |
| cookieValue | Cookie value to set. |
| incognito | Whether to set the cookie of corresponding URL in incognito mode (true) or in non-incognito mode (false). |
| includeHttpOnly | Whether the cookie marked as HttpOnly can be overwritten. |

**Returns**

Returns [ARKWEB_SUCCESS](_web.md) if the cookie is set successfully; returns [ARKWEB_INVALID_URL](_web.md) if the URL is invalid; returns [ARKWEB_INVALID_COOKIE_VALUE](_web.md) if the cookie value is invalid.


### existCookies

```
bool(* ArkWeb_CookieManagerAPI::existCookies) (bool incognito)
```
**Description**

Pointer to the function used to check whether the cookie exists.

**Parameters**

| Name| Description|
| -------- | -------- |
| incognito | Whether the cookie exists in incognito mode (true) or in non-incognito mode (false). |

**Returns**

Returns **true** if the cookie exists; returns **false** if the cookie does not exist.


### fetchCookieSync

```
ArkWeb_ErrorCode(* ArkWeb_CookieManagerAPI::fetchCookieSync) (const char *url, bool incognito, bool includeHttpOnly, char **cookieValue)
```
**Description**

Pointer to the function used to obtain the cookie value of a specified URL.

**Parameters**

| Name| Description|
| -------- | -------- |
| url | URL of the cookie to obtain. A complete URL is recommended. |
| incognito | Whether to obtain the webview memory cookie in incognito mode() or in non-incognito mode. |
| includeHttpOnly | Whether to include the cookie marked as HttpOnly. |
| cookieValue | Cookie value of the corresponding URL. |

**Returns**

Returns [ARKWEB_SUCCESS](_web.md) if the cookie is obtained successfully; returns [ARKWEB_INVALID_URL](_web.md) if the URL is invalid; returns [ARKWEB_INVALID_PARAM](_web.md) if the cookie value is invalid.


### size

```
size_t ArkWeb_CookieManagerAPI::size
```
**Description**

Size of the struct.
