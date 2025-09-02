# arkweb_interface.h

## Overview

Declares ArkWeb APIs for obtaining native APIs and the basic native API types.

**Library**: libohweb.so

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Related module**: [Web](capi-web.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ArkWeb_AnyNativeAPI](capi-web-arkweb-anynativeapi.md) | ArkWeb_AnyNativeAPI | Defines the basic native API types.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ArkWeb_NativeAPIVariantKind](#arkweb_nativeapivariantkind) | ArkWeb_NativeAPIVariantKind | Enumerates the native API types.|

### Functions

| Name| Description|
| -- | -- |
| [ArkWeb_AnyNativeAPI* OH_ArkWeb_GetNativeAPI(ArkWeb_NativeAPIVariantKind type)](#oh_arkweb_getnativeapi) | Obtains the native API struct based on the transferred API type.|
| [bool OH_ArkWeb_RegisterScrollCallback(const char* webTag, ArkWeb_OnScrollCallback callback, void* userData)](#oh_arkweb_registerscrollcallback) | Registers a callback for the scroll event.|

## Enum Description

### ArkWeb_NativeAPIVariantKind

```
enum ArkWeb_NativeAPIVariantKind
```

**Description**

Enumerates the native API types.

**Since**: 12

| Enumerated Value| Description|
| -- | -- |
| ARKWEB_NATIVE_COMPONENT | APIs related to the **Web** component.|
| ARKWEB_NATIVE_CONTROLLER | APIs related to controller.|
| ARKWEB_NATIVE_WEB_MESSAGE_PORT | APIs related to **webMessagePort**.|
| ARKWEB_NATIVE_WEB_MESSAGE | APIs related to **webMessage**.|
| ARKWEB_NATIVE_COOKIE_MANAGER | APIs related to **cookieManager**.|
| ARKWEB_NATIVE_JAVASCRIPT_VALUE | APIs related to **JavaScriptValue**.<br>**Since**: 18|


## Function Description

### OH_ArkWeb_GetNativeAPI()

```
ArkWeb_AnyNativeAPI* OH_ArkWeb_GetNativeAPI(ArkWeb_NativeAPIVariantKind type)
```

**Description**

Obtains the native API struct based on the transferred API type.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkWeb_NativeAPIVariantKind](#arkweb_nativeapivariantkind) type | The native API types supported by ArkWeb.|

**Returns**

| Type                                          | Description|
|----------------------------------------------| -- |
| [ArkWeb_AnyNativeAPI](capi-web-arkweb-anynativeapi.md)* | Native API struct pointer corresponding to the input API type. The first member of the struct is the size of the struct.|

### OH_ArkWeb_RegisterScrollCallback()

```
bool OH_ArkWeb_RegisterScrollCallback(const char* webTag, ArkWeb_OnScrollCallback callback, void* userData)
```

**Description**

Sets a callback for the scroll event.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.|
| [ArkWeb_OnScrollCallback](capi-arkweb-type-h.md#arkweb_onscrollcallback) callback | Callback used when a page is scrolled.|
| void* userData | Pointer to user-defined data.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** is returned if the operation is successful; otherwise, **false** is returned.|
