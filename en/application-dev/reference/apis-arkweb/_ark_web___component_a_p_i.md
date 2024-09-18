# ArkWeb_ComponentAPI


## Overview

Defines a native component API.

**Since**: 12

**Related module**: [Web](_web.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| size_t [size](#size) | The size of a struct. | 
| void(\* [onControllerAttached](#oncontrollerattached) )(const char \*webTag, [ArkWeb_OnComponentCallback](_web.md#arkweb_oncomponentcallback) callback, void \*userData) | Callback triggered when a controller is attached to the web component. | 
| void(\* [onPageBegin](#onpagebegin) )(const char \*webTag, [ArkWeb_OnComponentCallback](_web.md#arkweb_oncomponentcallback) callback, void \*userData) | Callback triggered when the web page starts to be loaded. This callback is called only for the main frame content, and not for the iframe or frameset content. | 
| void(\* [onPageEnd](#onpageend) )(const char \*webTag, [ArkWeb_OnComponentCallback](_web.md#arkweb_oncomponentcallback) callback, void \*userData) | Callback triggered when the web page loading is complete. This callback is triggered only for the main frame content. | 
| void(\* [onDestroy](#ondestroy) )(const char \*webTag, [ArkWeb_OnComponentCallback](_web.md#arkweb_oncomponentcallback) callback, void \*userData) | Callback triggered when this web component is destroyed. | 


## Member Variable Description


### onControllerAttached

```
void(* ArkWeb_ComponentAPI::onControllerAttached) (const char *webTag, ArkWeb_OnComponentCallback callback, void *userData)
```
**Description**

Callback triggered when a controller is attached to the web component.


### onDestroy

```
void(* ArkWeb_ComponentAPI::onDestroy) (const char *webTag, ArkWeb_OnComponentCallback callback, void *userData)
```
**Description**

Callback triggered when this web component is destroyed.


### onPageBegin

```
void(* ArkWeb_ComponentAPI::onPageBegin) (const char *webTag, ArkWeb_OnComponentCallback callback, void *userData)
```
**Description**

Callback triggered when the web page starts to be loaded. This callback is called only for the main frame content, and not for the iframe or frameset content.


### onPageEnd

```
void(* ArkWeb_ComponentAPI::onPageEnd) (const char *webTag, ArkWeb_OnComponentCallback callback, void *userData)
```
**Description**

Callback triggered when the web page loading is complete. This callback is triggered only for the main frame content.


### size

```
size_t ArkWeb_ComponentAPI::size
```
**Description**

The size of a struct.
