# arkweb_interface.h


## Overview

Declares ArkWeb APIs for obtaining native APIs and the basic native API types.

**Library**: libohweb.so

**File to include**: <web/arkweb_interface.h>

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Related module**: [Web](_web.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[ArkWeb_AnyNativeAPI](_ark_web___any_native_a_p_i.md) | Defines the basic native API types. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [ArkWeb_NativeAPIVariantKind](_web.md#arkweb_nativeapivariantkind) {<br>[ARKWEB_NATIVE_COMPONENT](_web.md), [ARKWEB_NATIVE_CONTROLLER](_web.md), [ARKWEB_NATIVE_WEB_MESSAGE_PORT](_web.md), [ARKWEB_NATIVE_WEB_MESSAGE](_web.md),<br>[ARKWEB_NATIVE_COOKIE_MANAGER](_web.md)<br>} | Enumerates the native API types. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [ArkWeb_AnyNativeAPI](_ark_web___any_native_a_p_i.md) \* [OH_ArkWeb_GetNativeAPI](_web.md#oh_arkweb_getnativeapi) ([ArkWeb_NativeAPIVariantKind](_web.md#arkweb_nativeapivariantkind) type) | Obtains the native API struct corresponding to the API type passed in. | 
