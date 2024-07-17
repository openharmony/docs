# ArkWeb_ControllerAPI


## Overview

Defines a struct for native APIs of the controller.

**Since**: 12

**Related module**: [Web](_web.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| size_t [size](#size) | The size of a struct. | 
| void(\* [runJavaScript](#runjavascript) )(const char \*webTag, const [ArkWeb_JavaScriptObject](_ark_web___java_script_object.md) \*javascriptObject) | Pointer to the function used to inject a JavaScript script. | 
| void(\* [registerJavaScriptProxy](#registerjavascriptproxy) )(const char \*webTag, const [ArkWeb_ProxyObject](_ark_web___proxy_object.md) \*proxyObject) | Pointer to the function used to register a JavaScript proxy with the window. APIs of this object can then be invoked in the window. | 
| void(\* [deleteJavaScriptRegister](#deletejavascriptregister) )(const char \*webTag, const char \*objName) | Pointer to the function used to delete a specific application JavaScript object that is registered with the window using **registerJavaScriptProxy**. | 
| void(\* [refresh](#refresh) )(const char \*webTag) | Pointer to the function used to refresh the web page. | 
| void(\* [registerAsyncJavaScriptProxy](#registerasyncjavascriptproxy) )(const char \*webTag, const [ArkWeb_ProxyObject](_ark_web___proxy_object.md) \*proxyObject) | Pointer to the function used to register a JavaScript proxy with the window. Asynchronous APIs of this object can then be invoked in the window. | 


## Member Variable Description


### deleteJavaScriptRegister

```
void(* ArkWeb_ControllerAPI::deleteJavaScriptRegister) (const char *webTag, const char *objName)
```
**Description**

Pointer to the function used to delete a specific application JavaScript object that is registered with the window using **registerJavaScriptProxy**.


### refresh

```
void(* ArkWeb_ControllerAPI::refresh) (const char *webTag)
```
**Description**

Pointer to the function used to refresh the web page.


### registerAsyncJavaScriptProxy

```
void(* ArkWeb_ControllerAPI::registerAsyncJavaScriptProxy) (const char *webTag, const ArkWeb_ProxyObject *proxyObject)
```
**Description**

Pointer to the function used to register a JavaScript proxy with the window. Asynchronous APIs of this object can then be invoked in the window.


### registerJavaScriptProxy

```
void(* ArkWeb_ControllerAPI::registerJavaScriptProxy) (const char *webTag, const ArkWeb_ProxyObject *proxyObject)
```
**Description**

Pointer to the function used to register a JavaScript proxy with the window. APIs of this object can then be invoked in the window.


### runJavaScript

```
void(* ArkWeb_ControllerAPI::runJavaScript) (const char *webTag, const ArkWeb_JavaScriptObject *javascriptObject)
```
**Description**

Pointer to the function used to inject a JavaScript script.


### size

```
size_t ArkWeb_ControllerAPI::size
```
**Description**

The size of a struct.
