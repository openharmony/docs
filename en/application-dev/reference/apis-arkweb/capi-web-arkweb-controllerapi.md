# ArkWeb_ControllerAPI
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @yp99ustc; @aohui; @zourongchun-->
<!--Designer: @LongLie; @yaomingliu; @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

## Overview

Defines a native controller API. Before calling this API, you are advised to use [ARKWEB_MEMBER_MISSING](capi-arkweb-type-h.md#macros) to check whether the function struct has the corresponding pointer to avoid crash caused by mismatch between the SDK and the device ROM.

**Since**: 12

**Related module**: [Web](capi-web.md)

**Header file**: [arkweb_type.h](capi-arkweb-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| size_t size | Size of the struct.|


### Member Functions

| Name| Description|
| -- | -- |
| [void (\*runJavaScript)(const char* webTag, const ArkWeb_JavaScriptObject* javascriptObject)](#runjavascript) | Injects a JavaScript script.|
| [void (\*registerJavaScriptProxy)(const char* webTag, const ArkWeb_ProxyObject* proxyObject)](#registerjavascriptproxy) | Injects a JavaScript object with the window. Synchronous APIs of this object can then be invoked in the window.|
| [void (\*deleteJavaScriptRegister)(const char* webTag, const char* objName)](#deletejavascriptregister) | Deletes a specific application JavaScript object that is registered with the window using **registerJavaScriptProxy**.|
| [void (\*refresh)(const char* webTag)](#refresh) | Refreshes the web page. The page stack is cleared during the refresh. As a result, the current page cannot be navigated forward or backward.|
| [void (\*registerAsyncJavaScriptProxy)(const char* webTag, const ArkWeb_ProxyObject* proxyObject)](#registerasyncjavascriptproxy) | Injects a JavaScript object with the window. Asynchronous APIs of this object can then be invoked in the window.|
| [ArkWeb_WebMessagePortPtr* (\*createWebMessagePorts)(const char* webTag, size_t* size)](#createwebmessageports) | Creates a post message port.|
| [void (\*destroyWebMessagePorts)(ArkWeb_WebMessagePortPtr** ports, size_t size)](#destroywebmessageports) | Destroys a message port.|
| [ArkWeb_ErrorCode (\*postWebMessage)(const char* webTag, const char* name, ArkWeb_WebMessagePortPtr* webMessagePorts, size_t size, const char* url)](#postwebmessage) | Sends a message port to the HTML page.|
| [const char* (\*getLastJavascriptProxyCallingFrameUrl)()](#getlastjavascriptproxycallingframeurl) | Obtains the URL of the last frame that calls **JavaScriptProxy**. This function is invoked on the thread invoked by **JavaScriptProxy**. You can use **registerJavaScriptProxy** or **JavaScriptProxy** to inject a JavaScript object to a window object. This API can be used to obtain the URL of the last frame calls the injected object. You need to save the URL obtained from the invoked function.<br>**Since**: 14|
| [void (\*registerJavaScriptProxyEx)(const char* webTag, const ArkWeb_ProxyObjectWithResult* proxyObject,const char* permission)](#registerjavascriptproxyex) | Injects a JavaScript object with the window. Synchronous APIs of this object can then be invoked in the window. The synchronization method of this object can contain return values.<br>**Since**: 18|
| [void (\*registerAsyncJavaScriptProxyEx)(const char* webTag, const ArkWeb_ProxyObject* proxyObject,const char* permission)](#registerasyncjavascriptproxyex) | Injects a JavaScript object with the window. Asynchronous APIs of this object can then be invoked in the window.<br>**Since**: 18|

## Member Function Description

### runJavaScript()

```
void (*runJavaScript)(const char* webTag, const ArkWeb_JavaScriptObject* javascriptObject)
```

**Description**

Injects a JavaScript script.

**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.                  |
|const ArkWeb_JavaScriptObject* javascriptObject  | JavaScript object to inject.          |

### registerJavaScriptProxy()

```
void (*registerJavaScriptProxy)(const char* webTag, const ArkWeb_ProxyObject* proxyObject)
```

**Description**

Injects a JavaScript object with the window. Synchronous APIs of this object can then be invoked in the window.

**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.                  |
| const ArkWeb_ProxyObject* proxyObject  | Object to be registered.         |

### deleteJavaScriptRegister()

```
void (*deleteJavaScriptRegister)(const char* webTag, const char* objName)
```

**Description**

Deletes a specific application JavaScript object that is registered with the window using **registerJavaScriptProxy**.

**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.                  |
| const char* objName  | Name of the JavaScript object.         |

### refresh()

```
void (*refresh)(const char* webTag)
```

**Description**

Refreshes the web page. The page stack is cleared during the refresh. As a result, the current page cannot be navigated forward or backward.

**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.                  |

### registerAsyncJavaScriptProxy()

```
void (*registerAsyncJavaScriptProxy)(const char* webTag, const ArkWeb_ProxyObject* proxyObject)
```

**Description**

Injects a JavaScript object with the window. Asynchronous APIs of this object can then be invoked in the window.

**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.                  |
| const ArkWeb_ProxyObject* proxyObject  | Object to be registered.      |

### createWebMessagePorts()

```
ArkWeb_WebMessagePortPtr* (*createWebMessagePorts)(const char* webTag, size_t* size)
```

**Description**

Creates a post message port.

**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.|
|  size_t* size | Number of ports, which is an output parameter.|

**Returns**

| Type                          | Description|
|------------------------------|----|
| [ArkWeb_WebMessagePortPtr](capi-web-arkweb-webmessageport8h.md) | Pointer to the message port.  |

### destroyWebMessagePorts()

```
void (*destroyWebMessagePorts)(ArkWeb_WebMessagePortPtr** ports, size_t size)
```

**Description**

Destroys a message port.

**Parameters**

| Name          | Description               |
|---------------|--------------------|
| [ArkWeb_WebMessagePortPtr](capi-web-arkweb-webmessageport8h.md)** ports | Double pointer to the message port struct.|
| size_t size   | Number of ports.             |

### postWebMessage()

```
ArkWeb_ErrorCode (*postWebMessage)(const char* webTag, const char* name, ArkWeb_WebMessagePortPtr* webMessagePorts, size_t size, const char* url)
```

**Description**

Sends a message port to the HTML page.

**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.|
|  const char* name | Name of the message sent to the HTML page.|
|  [ArkWeb_WebMessagePortPtr](capi-web-arkweb-webmessageport8h.md)* webMessagePorts | Pointer to the message port.|
|  size_t size | Number of ports.|
|  const char* url | URL of the page that receives the message.|

**Returns**

| Type| Description                                                                                                                                                        |
|----|------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Error code  | [ARKWEB_SUCCESS](capi-arkweb-error-code-h.md#arkweb_errorcode): The operation is successful.<br>[ARKWEB_INVALID_PARAM](capi-arkweb-error-code-h.md#arkweb_errorcode): The parameter is invalid.<br>[ARKWEB_INIT_ERROR](capi-arkweb-error-code-h.md#arkweb_errorcode): The initialization fails because the **Web** component bound to **webTag** is not found.|

### getLastJavascriptProxyCallingFrameUrl()

```
const char* (*getLastJavascriptProxyCallingFrameUrl)()
```

**Description**

Obtains the URL of the last frame that calls **JavaScriptProxy**. This function is invoked on the thread invoked by **JavaScriptProxy**. You can use **registerJavaScriptProxy** or **JavaScriptProxy** to inject a JavaScript object to a window object. This API can be used to obtain the URL of the last frame calls the injected object. You need to save the URL obtained from the invoked function.

**Since**: 14

**Returns**

| Type| Description|
| -- | -- |
| const char* | URL of the last frame that calls **JavaScriptProxy**.|

### registerJavaScriptProxyEx()

```
void (*registerJavaScriptProxyEx)(const char* webTag, const ArkWeb_ProxyObjectWithResult* proxyObject,const char* permission)
```

**Description**

Injects a JavaScript object with the window. Synchronous APIs of this object can then be invoked in the window. The synchronization method of this object can contain return values.

**Since**: 18

**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.|
|  const [ArkWeb_ProxyObjectWithResult](capi-web-arkweb-proxyobjectwithresult.md)* proxyObject | Object to be registered.|
| const char* permission |  A JSON string used to configure the object and method levels of the JSBridge permission. This value is empty by default.|

### registerAsyncJavaScriptProxyEx()

```
void (*registerAsyncJavaScriptProxyEx)(const char* webTag, const ArkWeb_ProxyObject* proxyObject, const char* permission)
```

**Description**

Injects a JavaScript object with the window. Asynchronous APIs of this object can then be invoked in the window.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| const char* webTag | Name of the **Web** component. | 
| const ArkWeb_ProxyObject* proxyObject | Object to be registered. | 
| const char* permission |  A JSON string used to configure the object and method levels of the JSBridge permission. This value is empty by default.| 
