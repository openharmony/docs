# ArkWeb_ProxyMethod


## Overview

Defines a proxy method.

**Since**: 12

**Related module**: [Web](_web.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| const char \* [methodName](#methodname) | Pointer to the method name to be injected. | 
| [ArkWeb_OnJavaScriptProxyCallback](_web.md#arkweb_onjavascriptproxycallback) [callback](#callback) | Callback used when a proxy method is invoked. | 
| void \* [userData](#userdata) | Pointer to the user data used in a callback. | 


## Member Variable Description


### callback

```
ArkWeb_OnJavaScriptProxyCallback ArkWeb_ProxyMethod::callback
```
**Description**

Callback used when a proxy method is invoked.


### methodName

```
const char* ArkWeb_ProxyMethod::methodName
```
**Description**

Pointer to the method name to be injected.


### userData

```
void* ArkWeb_ProxyMethod::userData
```
**Description**

Pointer to the user data used in a callback.
