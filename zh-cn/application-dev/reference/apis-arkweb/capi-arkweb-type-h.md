# arkweb_type.h

## 概述

提供ArkWeb在Native侧的公共类型定义。

**库：** libohweb.so

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**相关模块：** [Web](capi-web.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkWeb_JavaScriptBridgeData](capi-web-arkweb-javascriptbridgedata.md) | ArkWeb_JavaScriptBridgeData | 定义JavaScript Bridge数据的基础结构。 |
| [ArkWeb_WebMessage*](capi-web-arkweb-webmessage8h.md) | ArkWeb_WebMessagePtr | Post Message数据结构体指针。 |
| [ArkWeb_JavaScriptValue*](capi-web-arkweb-javascriptvalue8h.md) | ArkWeb_JavaScriptValuePtr | JavaScript数据结构体指针。 |
| [ArkWeb_WebMessagePort*](capi-web-arkweb-webmessageport8h.md) | ArkWeb_WebMessagePortPtr | Post Message端口结构体指针。 |
| [ArkWeb_JavaScriptObject](capi-web-arkweb-javascriptobject.md) | ArkWeb_JavaScriptObject | 注入的JavaScript结构体。 |
| [ArkWeb_ProxyMethod](capi-web-arkweb-proxymethod.md) | ArkWeb_ProxyMethod | 注入的Proxy方法通用结构体。 |
| [ArkWeb_ProxyMethodWithResult](capi-web-arkweb-proxymethodwithresult.md) | ArkWeb_ProxyMethodWithResult | 注入的Proxy方法通用结构体。 |
| [ArkWeb_ProxyObject](capi-web-arkweb-proxyobject.md) | ArkWeb_ProxyObject | 注入的Proxy对象通用结构体。 |
| [ArkWeb_ProxyObjectWithResult](capi-web-arkweb-proxyobjectwithresult.md) | ArkWeb_ProxyObjectWithResult | 注入的Proxy对象通用结构体。 |
| [ArkWeb_ControllerAPI](capi-web-arkweb-controllerapi.md) | ArkWeb_ControllerAPI | Controller相关的Native API结构体。在调用接口前建议通过ARKWEB_MEMBER_MISSING校验该函数结构体是否有对应函数指针，避免SDK与设备ROM不匹配导致crash问题。 |
| [ArkWeb_ComponentAPI](capi-web-arkweb-componentapi.md) | ArkWeb_ComponentAPI | Component相关的Native API结构体。 |
| [ArkWeb_WebMessagePortAPI](capi-web-arkweb-webmessageportapi.md) | ArkWeb_WebMessagePortAPI | Post Message相关的Native API结构体。在调用接口前建议通过ARKWEB_MEMBER_MISSING校验该函数结构体是否有对应函数指针，避免SDK与设备ROM不匹配导致crash问题。 |
| [ArkWeb_WebMessageAPI](capi-web-arkweb-webmessageapi.md) | ArkWeb_WebMessageAPI | Post Message数据相关的Native API结构体。在调用接口前建议通过ARKWEB_MEMBER_MISSING校验该函数结构体是否有对应函数指针，避免SDK与设备ROM不匹配导致crash问题。 |
| [ArkWeb_CookieManagerAPI](capi-web-arkweb-cookiemanagerapi.md) | ArkWeb_CookieManagerAPI | 定义了ArkWeb原生CookieManager接口。在调用接口之前，建议使用ARKWEB_MEMBER_MISSING检查函数结构体是否有对应的函数指针，避免SDK与设备ROM不匹配导致崩溃。 |
| [ArkWeb_JavaScriptValueAPI](capi-web-arkweb-javascriptvalueapi.md) | ArkWeb_JavaScriptValueAPI | 定义了ArkWeb原生JavaScriptValue接口。在调用接口之前，建议使用ARKWEB_MEMBER_MISSING检查函数结构体是否有对应的函数指针，避免SDK与设备ROM不匹配导致崩溃。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkWeb_WebMessageType](#arkweb_webmessagetype) | ArkWeb_WebMessageType | Post Message数据类型。 |
| [ArkWeb_JavaScriptValueType](#arkweb_javascriptvaluetype) | ArkWeb_JavaScriptValueType | JavaScript数据类型。 |

### 函数

| 名称                                                                                                                                                                                                                                | typedef关键字                                 | 描述 |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------| -- |
| [typedef void (\*ArkWeb_OnJavaScriptCallback)(const char* webTag, const ArkWeb_JavaScriptBridgeData* data, void* userData)](#arkweb_onjavascriptcallback)                                                                         | ArkWeb_OnJavaScriptCallback                | 注入的JavaScript执行完成的回调。 |
| [typedef void (\*ArkWeb_OnJavaScriptProxyCallback)(const char* webTag, const ArkWeb_JavaScriptBridgeData* dataArray, size_t arraySize, void* userData)](#arkweb_onjavascriptproxycallback)                                        | ArkWeb_OnJavaScriptProxyCallback           | Proxy方法被执行的回调。 |
| [typedef ArkWeb_JavaScriptValuePtr (\*ArkWeb_OnJavaScriptProxyCallbackWithResult)(const char* webTag, const ArkWeb_JavaScriptBridgeData* dataArray, size_t arraySize, void* userData)](#arkweb_onjavascriptproxycallbackwithresult) | ArkWeb_OnJavaScriptProxyCallbackWithResult | Proxy方法被执行的回调。 |
| [typedef void (\*ArkWeb_OnComponentCallback)(const char* webTag, void* userData)](#arkweb_oncomponentcallback)                                                                                                                    | ArkWeb_OnComponentCallback                 | 组件事件通知相关的通用回调。 |
| [typedef void (\*ArkWeb_OnScrollCallback)(const char* webTag, void* userData, double x, double y)](#arkweb_onscrollcallback)                                                                                                      | ArkWeb_OnScrollCallback                    | 定义Web组件滚动时的回调函数的类型。 |
| [typedef void (\*ArkWeb_OnMessageEventHandler)(const char* webTag, const ArkWeb_WebMessagePortPtr port, const ArkWeb_WebMessagePtr message, void* userData)](#arkweb_onmessageeventhandler)                                       | ArkWeb_OnMessageEventHandler               | 处理HTML发送过来的Post Message数据。 |

### 宏定义

| 名称 | 描述 |
| ---- | ---- |
| ARKWEB_MEMBER_EXISTS(s, f)&nbsp;&nbsp;&nbsp;&nbsp;((intptr_t) &amp; ((s)-&gt;f) - (intptr_t)(s) + sizeof((s)-&gt;f) &lt;= \*reinterpret_cast&lt;size_t\*&gt;(s)) | 检查结构体中是否存在该成员变量。<br>**起始版本：** 12 |
| ARKWEB_MEMBER_MISSING(s, f)&nbsp;&nbsp;&nbsp;(\!ARKWEB_MEMBER_EXISTS(s, f) \|\| !((s)-&gt;f)) | 当前结构体存在该成员变量则返回false，否则返回true<br/>**起始版本：** 12 |

## 枚举类型说明

### ArkWeb_WebMessageType

```
enum ArkWeb_WebMessageType
```

**描述**

Post Message数据类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKWEB_NONE = 0 | 错误数据。 |
| ARKWEB_STRING | 字符串数据类型。 |
| ARKWEB_BUFFER | 字节流数据类型。 |

### ArkWeb_JavaScriptValueType

```
enum ArkWeb_JavaScriptValueType
```

**描述**

JavaScript数据类型。

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| ARKWEB_JAVASCRIPT_NONE = 0 | 错误数据。 |
| ARKWEB_JAVASCRIPT_STRING | 字符串数据类型。 |
| ARKWEB_JAVASCRIPT_BOOL | bool数据类型。 |


## 函数说明

### ArkWeb_OnJavaScriptCallback()

```
typedef void (*ArkWeb_OnJavaScriptCallback)(const char* webTag, const ArkWeb_JavaScriptBridgeData* data, void* userData)
```

**描述**

注入的JavaScript执行完成的回调。

**起始版本：** 12


**参数：**

| 参数项                                         | 描述 |
|---------------------------------------------| -- |
| const char* webTag                          | Web组件名称。 |
| const [ArkWeb_JavaScriptBridgeData](capi-web-arkweb-javascriptbridgedata.md)* data | JavaScriptBridge数据。 |
| void* userData                              | 用户自定义的数据。 |

### ArkWeb_OnJavaScriptProxyCallback()

```
typedef void (*ArkWeb_OnJavaScriptProxyCallback)(const char* webTag, const ArkWeb_JavaScriptBridgeData* dataArray, size_t arraySize, void* userData)
```

**描述**

Proxy方法被执行的回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。 |
|  const [ArkWeb_JavaScriptBridgeData](capi-web-arkweb-javascriptbridgedata.md)* dataArray | 数组数据。 |
|  size_t arraySize | 数组大小。 |
|  void* userData | 用户自定义的数据。 |

### ArkWeb_OnJavaScriptProxyCallbackWithResult()

```
typedef ArkWeb_JavaScriptValuePtr (*ArkWeb_OnJavaScriptProxyCallbackWithResult)(const char* webTag, const ArkWeb_JavaScriptBridgeData* dataArray, size_t arraySize, void* userData)
```

**描述**

Proxy方法被执行的回调。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。 |
|  const [ArkWeb_JavaScriptBridgeData](capi-web-arkweb-javascriptbridgedata.md)* dataArray | 数组数据。 |
|  size_t arraySize | 数组大小。 |
|  void* userData | 用户自定义的数据。 |

### ArkWeb_OnComponentCallback()

```
typedef void (*ArkWeb_OnComponentCallback)(const char* webTag, void* userData)
```

**描述**

组件事件通知相关的通用回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。 |
|  void* userData | 用户自定义的数据。 |

### ArkWeb_OnScrollCallback()

```
typedef void (*ArkWeb_OnScrollCallback)(const char* webTag, void* userData, double x, double y)
```

**描述**

定义Web组件滚动时的回调函数的类型。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。 |
|  void* userData | 用户自定义的数据。 |
|  double x | X轴滚动偏移。 |
|  double y | Y轴滚动偏移。 |

### ArkWeb_OnMessageEventHandler()

```
typedef void (*ArkWeb_OnMessageEventHandler)(const char* webTag, const ArkWeb_WebMessagePortPtr port, const ArkWeb_WebMessagePtr message, void* userData)
```

**描述**

处理HTML发送过来的Post Message数据。

**起始版本：** 12

**参数：**

| 参数项                                                                    | 描述 |
|------------------------------------------------------------------------| -- |
| const char* webTag                                                     | Web组件名称。 |
| const [ArkWeb_WebMessagePortPtr](capi-web-arkweb-webmessageport8h.md) port | Post Message端口。 |
| const [ArkWeb_WebMessagePtr](capi-web-arkweb-webmessage8h.md) message                                 | Post Message数据。 |
| void* userData                                                         | 用户自定义数据。 |


