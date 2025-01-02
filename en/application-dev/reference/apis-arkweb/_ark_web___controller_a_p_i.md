# ArkWeb_ControllerAPI


## Overview

Defines a native API struct of the Web controller. Before calling the API, you are advised to use **ARKWEB_MEMBER_MISSING** to check whether the function struct has the corresponding pointer to avoid crash caused by mismatch between the SDK and the device ROM.

**Since**: 12

**Related module**: [Web](_web.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| size_t [size](#size) | Size of the struct. |
| void(\* [runJavaScript](#runjavascript) )(const char \*webTag, const [ArkWeb_JavaScriptObject](_ark_web___java_script_object.md) \*javascriptObject) | Pointer to the function used to inject a JavaScript script. |
| void(\* [registerJavaScriptProxy](#registerjavascriptproxy) )(const char \*webTag, const [ArkWeb_ProxyObject](_ark_web___proxy_object.md) \*proxyObject) | Pointer to the function used to register a JavaScript proxy with the window. APIs of this object can then be invoked in the window. |
| void(\* [deleteJavaScriptRegister](#deletejavascriptregister) )(const char \*webTag, const char \*objName) | Pointer to the function used to delete a specific application JavaScript object that is registered with the window using **registerJavaScriptProxy**. |
| void(\* [refresh](#refresh) )(const char \*webTag) | Pointer to the function used to refresh the web page. |
| void(\* [registerAsyncJavaScriptProxy](#registerasyncjavascriptproxy) )(const char \*webTag, const [ArkWeb_ProxyObject](_ark_web___proxy_object.md) \*proxyObject) | Pointer to the function used to register a JavaScript proxy with the window. Asynchronous APIs of this object can then be invoked in the window. |
| [ArkWeb_WebMessagePortPtr](_web.md#arkweb_webmessageportptr) \*(\* [createWebMessagePorts](#createwebmessageports) )(const char \*webTag, size_t \*[size](#size)) | Pointer to the function used to create message ports. |
| void(\* [destroyWebMessagePorts](#destroywebmessageports) )([ArkWeb_WebMessagePortPtr](_web.md#arkweb_webmessageportptr) \*\*ports, size_t [size](#size)) | Pointer to the function used to destroy message ports. |
| [ArkWeb_ErrorCode](_web.md#arkweb_errorcode)(\* [postWebMessage](#postwebmessage) )(const char \*webTag, const char \*name, [ArkWeb_WebMessagePortPtr](_web.md#arkweb_webmessageportptr) \*webMessagePorts, size_t [size](#size), const char \*url) | Pointer to the function used to send the message port to the HTML page. |


## Member Variable Description


### createWebMessagePorts

```
ArkWeb_WebMessagePortPtr*(* ArkWeb_ControllerAPI::createWebMessagePorts) (const char *webTag, size_t *size)
```
**Description**

Pointer to the function used to create message ports.

**Parameters**

| Name| Description|
| -------- | -------- |
| webTag | Name of the **Web** component. |
| size | Number of ports, which is an output parameter. |

**Returns**

Pointer to the message port struct.


### deleteJavaScriptRegister

```
void(* ArkWeb_ControllerAPI::deleteJavaScriptRegister) (const char *webTag, const char *objName)
```
**Description**

Pointer to the function used to delete a specific application JavaScript object that is registered with the window using **registerJavaScriptProxy**.


### destroyWebMessagePorts

```
void(* ArkWeb_ControllerAPI::destroyWebMessagePorts) (ArkWeb_WebMessagePortPtr *ports, size_t *size)
```
**Description**

Pointer to the function used to destroy message ports.

**Parameters**

| Name| Description|
| -------- | -------- |
| ports | Pointer array of the message port struct. |
| size | Number of ports.|


### postWebMessage

```
ArkWeb_ErrorCode(* ArkWeb_ControllerAPI::postWebMessage) (const char *webTag, const char *name, ArkWeb_WebMessagePortPtr *webMessagePorts, size_t size, const char *url)
```
**Description**

Pointer to the function used to send the message port to the HTML page.

**Parameters**

| Name| Description|
| -------- | -------- |
| webTag | Name of the **Web** component. |
| name | Name of the message sent to the HTML page. |
| webMessagePorts | Pointer to the message port struct. |
| size | Number of ports. |
| url | URL of the page that receives the message. |

**Returns**

Returns [ARKWEB_SUCCESS](_web.md) if the operation is successful. Returns [ARKWEB_INVALID_PARAM](_web.md) if the parameter is invalid. Returns [ARKWEB_INIT_ERROR](_web.md) if the initialization fails, that is, the **Web** component bound to the **webTag** is not found.


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

Size of the struct.
