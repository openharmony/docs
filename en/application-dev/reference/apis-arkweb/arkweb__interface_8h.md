# arkweb_interface.h


## Overview

The **arkweb_interface.h** file provides ArkWeb APIs for obtaining native APIs and the basic native API types.

**Library**: libohweb.so

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Related module**: [Web](_web.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[ArkWeb_AnyNativeAPI](_ark_web___any_native_a_p_i.md) | Defines the basic Native API types. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [ArkWeb_NativeAPIVariantKind](_web.md#arkweb_nativeapivariantkind) { [ARKWEB_NATIVE_COMPONENT](_web.md), [ARKWEB_NATIVE_CONTROLLER](_web.md) } | Enumerates the Native API types. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [ArkWeb_AnyNativeAPI](_ark_web___any_native_a_p_i.md) \* [OH_ArkWeb_GetNativeAPI](_web.md#oh_arkweb_getnativeapi) ([ArkWeb_NativeAPIVariantKind](_web.md#arkweb_nativeapivariantkind) type) | Obtains the corresponding Native API struct based on the transferred API type. | 
