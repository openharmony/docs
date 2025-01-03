# ArkWeb_ProxyMethodWithResult


## Overview

Defines a proxy method.

**Since**: 14

**Related module**: [Web](_web.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| const char \* [methodName](#methodname) | Pointer to the method name to be injected. |
| [ArkWeb_OnJavaScriptProxyCallbackWithResult](_web.md#arkweb_onjavascriptproxycallbackwithresult) [callback](#callback) | Callback used when a proxy method is invoked. |
| void \* [userData](#userdata) | Pointer to the user data used in a callback. |


## Member Variable Description


### callback

```
ArkWeb_OnJavaScriptProxyCallbackWithResult ArkWeb_ProxyMethodWithResult::callback
```
**Description**

Callback used when a proxy method is invoked.


### methodName

```
const char* ArkWeb_ProxyMethodWithResult::methodName
```
**Description**

Pointer to the method name to be injected.


### userData

```
void* ArkWeb_ProxyMethodWithResult::userData
```
**Description**

Pointer to the user data used in a callback.

<!--no_check-->