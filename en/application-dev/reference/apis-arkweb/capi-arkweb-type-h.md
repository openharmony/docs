# arkweb_type.h

## Overview

Defines the native common types of ArkWeb.

**Library**: libohweb.so

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Related module**: [Web](capi-web.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ArkWeb_JavaScriptBridgeData](capi-web-arkweb-javascriptbridgedata.md) | ArkWeb_JavaScriptBridgeData | Defines the JavaScript Bridge data.|
| [ArkWeb_WebMessage*](capi-web-arkweb-webmessage8h.md) | ArkWeb_WebMessagePtr | Defines a pointer to the post message.|
| [ArkWeb_JavaScriptValue*](capi-web-arkweb-javascriptvalue8h.md) | ArkWeb_JavaScriptValuePtr | Defines a pointer to the JavaScript data.|
| [ArkWeb_WebMessagePort*](capi-web-arkweb-webmessageport8h.md) | ArkWeb_WebMessagePortPtr | Defines a pointer to the message port.|
| [ArkWeb_JavaScriptObject](capi-web-arkweb-javascriptobject.md) | ArkWeb_JavaScriptObject | Defines a JavaScript object to be registered.|
| [ArkWeb_ProxyMethod](capi-web-arkweb-proxymethod.md) | ArkWeb_ProxyMethod | Defines a proxy method to be registered.|
| [ArkWeb_ProxyMethodWithResult](capi-web-arkweb-proxymethodwithresult.md) | ArkWeb_ProxyMethodWithResult | Defines a proxy method with result to be registered.|
| [ArkWeb_ProxyObject](capi-web-arkweb-proxyobject.md) | ArkWeb_ProxyObject | Defines a proxy object to be registered.|
| [ArkWeb_ProxyObjectWithResult](capi-web-arkweb-proxyobjectwithresult.md) | ArkWeb_ProxyObjectWithResult | Defines a proxy object with result to be registered.|
| [ArkWeb_ControllerAPI](capi-web-arkweb-controllerapi.md) | ArkWeb_ControllerAPI | Defines a native controller API. Before calling the API, you are advised to use **ARKWEB_MEMBER_MISSING** to check whether the function struct has the corresponding pointer to avoid crash caused by mismatch between the SDK and the device ROM.|
| [ArkWeb_ComponentAPI](capi-web-arkweb-componentapi.md) | ArkWeb_ComponentAPI | Defines a native component API.|
| [ArkWeb_WebMessagePortAPI](capi-web-arkweb-webmessageportapi.md) | ArkWeb_WebMessagePortAPI | Defines a native message port API. Before calling the API, you are advised to use **ARKWEB_MEMBER_MISSING** to check whether the function struct has the corresponding pointer to avoid crash caused by mismatch between the SDK and the device ROM.|
| [ArkWeb_WebMessageAPI](capi-web-arkweb-webmessageapi.md) | ArkWeb_WebMessageAPI | Defines a native post message API. Before calling the API, you are advised to use **ARKWEB_MEMBER_MISSING** to check whether the function struct has the corresponding pointer to avoid crash caused by mismatch between the SDK and the device ROM.|
| [ArkWeb_CookieManagerAPI](capi-web-arkweb-cookiemanagerapi.md) | ArkWeb_CookieManagerAPI | Defines a native cookie manager API provided by ArkWeb. Before calling the API, you are advised to use **ARKWEB_MEMBER_MISSING** to check whether the function struct has the corresponding pointer to avoid crash caused by mismatch between the SDK and the device ROM.|
| [ArkWeb_JavaScriptValueAPI](capi-web-arkweb-javascriptvalueapi.md) | ArkWeb_JavaScriptValueAPI | Defines a native ArkWeb **JavaScriptValue** API. Before calling the API, you are advised to use **ARKWEB_MEMBER_MISSING** to check whether the function struct has the corresponding pointer to avoid crash caused by mismatch between the SDK and the device ROM.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ArkWeb_WebMessageType](#arkweb_webmessagetype) | ArkWeb_WebMessageType | Enumerates the data types of post message.|
| [ArkWeb_JavaScriptValueType](#arkweb_javascriptvaluetype) | ArkWeb_JavaScriptValueType | Enumerates the JavaScript data types.|

### Functions

| Name                                                                                                                                                                                                                               | typedef Keyword                                | Description|
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------| -- |
| [typedef void (\*ArkWeb_OnJavaScriptCallback)(const char* webTag, const ArkWeb_JavaScriptBridgeData* data, void* userData)](#arkweb_onjavascriptcallback)                                                                         | ArkWeb_OnJavaScriptCallback                | Called when the registered JavaScript is executed.|
| [typedef void (\*ArkWeb_OnJavaScriptProxyCallback)(const char* webTag, const ArkWeb_JavaScriptBridgeData* dataArray, size_t arraySize, void* userData)](#arkweb_onjavascriptproxycallback)                                        | ArkWeb_OnJavaScriptProxyCallback           | Called when the proxy method is executed.|
| [typedef ArkWeb_JavaScriptValuePtr (\*ArkWeb_OnJavaScriptProxyCallbackWithResult)(const char* webTag, const ArkWeb_JavaScriptBridgeData* dataArray, size_t arraySize, void* userData)](#arkweb_onjavascriptproxycallbackwithresult) | ArkWeb_OnJavaScriptProxyCallbackWithResult | Called when the proxy method is executed.|
| [typedef void (\*ArkWeb_OnComponentCallback)(const char* webTag, void* userData)](#arkweb_oncomponentcallback)                                                                                                                    | ArkWeb_OnComponentCallback                 | Called when a component event notification is sent.|
| [typedef void (\*ArkWeb_OnScrollCallback)(const char* webTag, void* userData, double x, double y)](#arkweb_onscrollcallback)                                                                                                      | ArkWeb_OnScrollCallback                    | Called when the **Web** component is scrolled.|
| [typedef void (\*ArkWeb_OnMessageEventHandler)(const char* webTag, const ArkWeb_WebMessagePortPtr port, const ArkWeb_WebMessagePtr message, void* userData)](#arkweb_onmessageeventhandler)                                       | ArkWeb_OnMessageEventHandler               | Called when a post message is sent from the HTML page.|

### Macros

| Name| Description|
| ---- | ---- |
| ARKWEB_MEMBER_EXISTS(s, f)&nbsp;&nbsp;&nbsp;&nbsp;((intptr_t) &amp; ((s)-&gt;f) - (intptr_t)(s) + sizeof((s)-&gt;f) &lt;= \*reinterpret_cast&lt;size_t\*&gt;(s)) | Whether a member variable exists in the struct.<br>**Since**: 12|
| ARKWEB_MEMBER_MISSING(s, f)&nbsp;&nbsp;&nbsp;(\!ARKWEB_MEMBER_EXISTS(s, f) \|\| !((s)-&gt;f)) | If the member variable exists in the struct, **false** is returned. Otherwise, **true** is returned.<br>**Since**: 12|

## Enum Description

### ArkWeb_WebMessageType

```
enum ArkWeb_WebMessageType
```

**Description**

Enumerates the data types of post message.

**Since**: 12

| Enumerated Value| Description|
| -- | -- |
| ARKWEB_NONE = 0 | Error data.|
| ARKWEB_STRING | String data.|
| ARKWEB_BUFFER | Byte stream data.|

### ArkWeb_JavaScriptValueType

```
enum ArkWeb_JavaScriptValueType
```

**Description**

Enumerates the JavaScript data types.

**Since**: 18

| Enumerated Value| Description|
| -- | -- |
| ARKWEB_JAVASCRIPT_NONE = 0 | Error data.|
| ARKWEB_JAVASCRIPT_STRING | String data.|
| ARKWEB_JAVASCRIPT_BOOL | Boolean data.|


## Function Description

### ArkWeb_OnJavaScriptCallback()

```
typedef void (*ArkWeb_OnJavaScriptCallback)(const char* webTag, const ArkWeb_JavaScriptBridgeData* data, void* userData)
```

**Description**

Called when the registered JavaScript is executed.

**Since**: 12


**Parameters**

| Name                                        | Description|
|---------------------------------------------| -- |
| const char* webTag                          | Name of the **Web** component.|
| const [ArkWeb_JavaScriptBridgeData](capi-web-arkweb-javascriptbridgedata.md)* data | JavaScriptBridge data.|
| void* userData                              | Pointer to user-defined data.|

### ArkWeb_OnJavaScriptProxyCallback()

```
typedef void (*ArkWeb_OnJavaScriptProxyCallback)(const char* webTag, const ArkWeb_JavaScriptBridgeData* dataArray, size_t arraySize, void* userData)
```

**Description**

Called when the proxy method is executed.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.|
|  const [ArkWeb_JavaScriptBridgeData](capi-web-arkweb-javascriptbridgedata.md)* dataArray | Pointer to data array.|
|  size_t arraySize | Array size.|
|  void* userData | Pointer to user-defined data.|

### ArkWeb_OnJavaScriptProxyCallbackWithResult()

```
typedef ArkWeb_JavaScriptValuePtr (*ArkWeb_OnJavaScriptProxyCallbackWithResult)(const char* webTag, const ArkWeb_JavaScriptBridgeData* dataArray, size_t arraySize, void* userData)
```

**Description**

Called when the proxy method is executed.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.|
|  const [ArkWeb_JavaScriptBridgeData](capi-web-arkweb-javascriptbridgedata.md)* dataArray | Pointer to data array.|
|  size_t arraySize | Array size.|
|  void* userData | Pointer to user-defined data.|

### ArkWeb_OnComponentCallback()

```
typedef void (*ArkWeb_OnComponentCallback)(const char* webTag, void* userData)
```

**Description**

Called when a component event notification is sent.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.|
|  void* userData | Pointer to user-defined data.|

### ArkWeb_OnScrollCallback()

```
typedef void (*ArkWeb_OnScrollCallback)(const char* webTag, void* userData, double x, double y)
```

**Description**

Called when the **Web** component is scrolled.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.|
|  void* userData | Pointer to user-defined data.|
|  double x | Scrolling offset of the X axis.|
|  double y | Scrolling offset of the Y axis.|

### ArkWeb_OnMessageEventHandler()

```
typedef void (*ArkWeb_OnMessageEventHandler)(const char* webTag, const ArkWeb_WebMessagePortPtr port, const ArkWeb_WebMessagePtr message, void* userData)
```

**Description**

Called when a post message is sent from the HTML page.

**Since**: 12

**Parameters**

| Name                                                                   | Description|
|------------------------------------------------------------------------| -- |
| const char* webTag                                                     | Name of the **Web** component.|
| const [ArkWeb_WebMessagePortPtr](capi-web-arkweb-webmessageport8h.md) port | Post message port.|
| const [ArkWeb_WebMessagePtr](capi-web-arkweb-webmessage8h.md) message                                 | Post message data.|
| void* userData                                                         | Pointer to user-defined data.|
