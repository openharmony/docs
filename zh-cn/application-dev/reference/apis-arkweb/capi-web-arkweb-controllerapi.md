# ArkWeb_ControllerAPI
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zourongchun-->
<!--Designer: @kurli1-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

```c
typedef struct {...} ArkWeb_ControllerAPI
```

## 概述

ArkWeb_ControllerAPI是Controller相关Native API结构体。该结构体提供了JavaScript注入、同步和异步JavaScript代理注册、代理删除、页面刷新、Web Message Port创建和管理、Frame URL查询等功能，特点包括支持同步与异步代理并存、统一管理控制WebView行为。适用于需要从Native代码注入并调用JavaScript、实现Native与页面双向通信的场景，可解决JSBridge互通与安全注入问题，提升开发效率与可控性。这是从Native代码控制WebView行为的主要接口。

Controller相关接口需在UI线程中调用OH_ArkWeb_GetNativeAPI方法获取，调用前建议通过[ARKWEB_MEMBER_MISSING](capi-arkweb-type-h.md#宏定义)校验函数指针的可用性，避免SDK与设备ROM不匹配导致崩溃。

**起始版本：** 12

**相关模块：** [Web](capi-web.md)

**所在头文件：** [arkweb_type.h](capi-arkweb-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| size_t size | 结构体的大小。 |


### 成员函数

| 名称                                                                                                                                                                    | 描述 |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------| -- |
| [void (\*runJavaScript)(const char* webTag, const ArkWeb_JavaScriptObject* javascriptObject)](#runjavascript)                                                         | 注入JavaScript脚本。 |
| [void (\*registerJavaScriptProxy)(const char* webTag, const ArkWeb_ProxyObject* proxyObject)](#registerjavascriptproxy)                                               | 注入JavaScript对象到window对象中，并在window对象中调用该对象的同步方法。 |
| [void (\*deleteJavaScriptRegister)(const char* webTag, const char* objName)](#deletejavascriptregister)                                                               | 删除通过registerJavaScriptProxy注册到window上的指定objName的应用侧JavaScript对象。 |
| [void (\*refresh)(const char* webTag)](#refresh)                                                                                                                      | 刷新当前网页。刷新的同时会清理页面栈，导致当前页面无法前进后退。 |
| [void (\*registerAsyncJavaScriptProxy)(const char* webTag, const ArkWeb_ProxyObject* proxyObject)](#registerasyncjavascriptproxy)                                     | 注入JavaScript对象到window对象中，并在window对象中调用该对象的异步方法。 |
| [ArkWeb_WebMessagePortPtr* (\*createWebMessagePorts)(const char* webTag, size_t* size)](#createwebmessageports)                                                       | 创建Post Message端口。 |
| [void (\*destroyWebMessagePorts)(ArkWeb_WebMessagePortPtr** ports, size_t size)](#destroywebmessageports)                                                             | 销毁端口。 |
| [ArkWeb_ErrorCode (\*postWebMessage)(const char* webTag, const char* name, ArkWeb_WebMessagePortPtr* webMessagePorts, size_t size, const char* url)](#postwebmessage) | 将端口发送到HTML主页面。 |
| [const char* (\*getLastJavascriptProxyCallingFrameUrl)()](#getlastjavascriptproxycallingframeurl)                                                                     | 获取调用JavaScriptProxy最后一帧的url。在JavaScriptProxy调用的线程上调用。通过registerJavaScriptProxy或者javaScriptProxy注入JavaScript对象到window对象中。该接口可以获取最后一次调用注入对象frame的url。在被调用函数内部获取url才能获取到正确值，可以在函数内部获取url后保存下来。<br>**起始版本：** 14 |
| [void (\*registerJavaScriptProxyEx)(const char* webTag, const ArkWeb_ProxyObjectWithResult* proxyObject, const char* permission)](#registerjavascriptproxyex)         | 注入JavaScript对象到window对象中，并在window对象中调用该对象的同步方法。该对象的同步方法可以带返回值。<br>**起始版本：** 18 |
| [void (\*registerAsyncJavaScriptProxyEx)(const char* webTag, const ArkWeb_ProxyObject* proxyObject, const char* permission)](#registerasyncjavascriptproxyex)         | 注入JavaScript对象到window对象中，并在window对象中调用该对象的异步方法。<br>**起始版本：** 18 |

## 成员函数说明

### runJavaScript()

```c
void (*runJavaScript)(const char* webTag, const ArkWeb_JavaScriptObject* javascriptObject)
```

**描述：**

注入JavaScript脚本。需在UI线程中调用OH_ArkWeb_GetNativeAPI方法获取该接口。该方法将JavaScript脚本注入到Web组件的执行上下文中，在页面加载完成后执行。使用场景：例如动态执行页面逻辑、注入调试脚本、运行跨页面公共脚本等。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。                   |
| const ArkWeb_JavaScriptObject* javascriptObject  | 注入的JavaScript对象。           |

### registerJavaScriptProxy()

```c
void (*registerJavaScriptProxy)(const char* webTag, const ArkWeb_ProxyObject* proxyObject)
```

**描述：**

注入JavaScript对象到window对象中，并在window对象中调用该对象的同步方法。该方法通过桥接机制将Native对象映射到JavaScript环境，实现双向通信。使用场景：例如JS调用Native能力以获取设备信息、执行 Native 业务逻辑等。需在UI线程中调用OH_ArkWeb_GetNativeAPI方法获取该接口。与registerAsyncJavaScriptProxy相比，此方法适用于需要同步获取返回值的场景。若不需要同步返回值或耗时操作，建议使用registerAsyncJavaScriptProxy以避免阻塞UI线程。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。                   |
| const ArkWeb_ProxyObject* proxyObject  | 要注册的代理对象，该对象将被注入到window对象中，并可通过JavaScript调用其方法。          |

### deleteJavaScriptRegister()

```c
void (*deleteJavaScriptRegister)(const char* webTag, const char* objName)
```

**描述：**

删除通过registerJavaScriptProxy注册到window上的指定name的应用侧JavaScript对象。需在UI线程中调用OH_ArkWeb_GetNativeAPI方法获取该接口。该方法会解除JavaScript对象与Native对象的绑定，并释放相关资源。使用场景：例如组件销毁、模块卸载或切换业务时清理注册对象以避免残留。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。                   |
| const char* objName  | JavaScript对象名称。          |

### refresh()

```c
void (*refresh)(const char* webTag)
```

**描述：**

刷新当前网页。刷新的同时会清理页面栈，导致当前页面无法前进后退。需在UI线程中调用OH_ArkWeb_GetNativeAPI方法获取该接口。使用场景：例如强制重载页面内容、同步远程配置变更、重置页面状态等。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。                   |

### registerAsyncJavaScriptProxy()

```c
void (*registerAsyncJavaScriptProxy)(const char* webTag, const ArkWeb_ProxyObject* proxyObject)
```

**描述：**

注入JavaScript对象到window对象中，并在window对象中调用该对象的异步方法。需在UI线程中调用OH_ArkWeb_GetNativeAPI方法获取该接口。该方法通过消息队列机制实现异步调用，避免阻塞主线程。与registerJavaScriptProxy相比，此方法适用于耗时操作或不需要同步获取返回值的场景，若需要同步获取返回值，建议使用registerJavaScriptProxy。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。                   |
| const ArkWeb_ProxyObject* proxyObject  | 注册的对象。       |

### createWebMessagePorts()

```c
ArkWeb_WebMessagePortPtr* (*createWebMessagePorts)(const char* webTag, size_t* size)
```

**描述：**

创建Post Message端口。Post Message端口提供双向通信机制，允许Native层与Web层安全地交换数据消息。需在UI线程中调用OH_ArkWeb_GetNativeAPI方法获取该接口。使用场景：例如实现跨上下文消息通道，支持iframe与主页面、Web与Worker之间的数据传递。

**配对调用：**
调用createWebMessagePorts()创建的端口，在使用完毕后必须调用destroyWebMessagePorts()销毁。未销毁端口会导致资源泄漏，影响应用性能。

**组合使用：**
创建端口后，需通过postWebMessage()将端口发送到HTML主页面，建立通信通道。典型使用流程：createWebMessagePorts() → postWebMessage() → 通信交互 → destroyWebMessagePorts()。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。 |
| size_t* size | 出参，端口数量。 |

**返回：**

| 类型                           | 说明 |
|------------------------------|----|
| [ArkWeb_WebMessagePortPtr](capi-web-arkweb-webmessageport8h.md) | Post Message端口结构体指针。   |

### destroyWebMessagePorts()

```c
void (*destroyWebMessagePorts)(ArkWeb_WebMessagePortPtr** ports, size_t size)
```

**描述：**

销毁端口。该方法会关闭端口连接，释放相关系统资源，停止消息传输。需在UI线程中调用OH_ArkWeb_GetNativeAPI方法获取该接口。使用场景：例如通信结束、组件生命周期结束时释放端口资源以避免泄漏。

**配对调用：**
必须与createWebMessagePorts()成对使用，用于销毁已创建的Post Message端口。只能销毁通过createWebMessagePorts()创建的端口。销毁后端口将无法使用，不能继续进行消息传递。建议在通信结束后及时销毁端口，释放资源。如果销毁未正确创建的端口，可能导致未定义行为。

**参数：**

| 参数项           | 描述                |
|---------------|--------------------|
| [ArkWeb_WebMessagePortPtr](capi-web-arkweb-webmessageport8h.md)** ports | Post Message端口结构体指针数组。 |
| size_t size   | 端口数量，必须等于ports数组中的端口数量。              |

### postWebMessage()

```c
ArkWeb_ErrorCode (*postWebMessage)(const char* webTag, const char* name, ArkWeb_WebMessagePortPtr* webMessagePorts, size_t size, const char* url)
```

**描述：**

将端口发送到HTML主页面。该方法通过消息传递机制将Post Message端口传递给指定的HTML页面，建立跨域通信通道。需在UI线程中调用OH_ArkWeb_GetNativeAPI方法获取该接口。使用场景：例如在主页面与iframe之间建立双向消息通道、跨框架推送消息等。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。需要与已绑定的Web组件匹配，否则会返回ARKWEB_INIT_ERROR。 |
|  const char* name | 发送给HTML的消息名称。 |
|  [ArkWeb_WebMessagePortPtr](capi-web-arkweb-webmessageport8h.md)* webMessagePorts | Post Message端口结构体指针。 |
|  size_t size | 端口数量。 |
|  const char* url | 接收到消息的页面url。 |

**返回：**

| 类型 | 说明                                                                                                                                                         |
|----|------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [ArkWeb_ErrorCode](capi-arkweb-error-code-h.md#arkweb_errorcode)   | 返回值错误码。<br>[ARKWEB_SUCCESS](capi-arkweb-error-code-h.md#arkweb_errorcode) 执行成功。<br>[ARKWEB_INVALID_PARAM](capi-arkweb-error-code-h.md#arkweb_errorcode) 参数无效。<br>[ARKWEB_INIT_ERROR](capi-arkweb-error-code-h.md#arkweb_errorcode) 初始化失败，没有找到与webTag绑定的Web组件。 |

### getLastJavascriptProxyCallingFrameUrl()

```c
const char* (*getLastJavascriptProxyCallingFrameUrl)()
```

**描述：**

获取调用JavaScriptProxy最后一帧的url。该方法通过帧栈追踪机制，记录最后一次JavaScript调用的frame上下文。在JavaScriptProxy调用的线程上调用。通过registerJavaScriptProxy或者JavaScriptProxy注入JavaScript对象到window对象中。该接口可以获取最后一次调用注入对象frame的url，如果从未调用过注入对象，返回值未定义。在被调用函数内部获取url才能获取到正确值，可以在函数内部获取url后保存下来。需在UI线程中调用OH_ArkWeb_GetNativeAPI方法获取该接口。使用场景：例如安全溯源、调用来源审计、日志记录与监控。

**起始版本：** 14

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 调用JavaScriptProxy最后一帧的url。 |

### registerJavaScriptProxyEx()

```c
void (*registerJavaScriptProxyEx)(const char* webTag, const ArkWeb_ProxyObjectWithResult* proxyObject, const char* permission)
```

**描述：**

注入JavaScript对象到window对象中，并在window对象中调用该对象的同步方法。该对象的同步方法可以带返回值。该方法通过同步桥接机制实现JavaScript与Native的双向数据传递和同步调用。与registerJavaScriptProxy相比，此方法增加了permission参数用于配置JSBridge的权限限制，适用于需要权限控制或同步获取返回值的场景。需在UI线程中调用OH_ArkWeb_GetNativeAPI方法获取该接口。使用场景：例如需要在JS调用Native时同步获取返回结果的业务场景。

**起始版本：** 18

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。 |
| const [ArkWeb_ProxyObjectWithResult](capi-web-arkweb-proxyobjectwithresult.md)* proxyObject | 要注册的代理对象，该对象将被注入到window对象中，并可通过JavaScript调用其同步方法，且方法可返回执行结果。 |
| const char* permission | JSON格式字符串，默认值为空。该字符串用来配置JSBridge的权限限制，可以配置对象和方法级别。 |

### registerAsyncJavaScriptProxyEx()

```c
void (*registerAsyncJavaScriptProxyEx)(const char* webTag, const ArkWeb_ProxyObject* proxyObject, const char* permission)
```

**描述：**

注入JavaScript对象到window对象中，并在window对象中调用该对象的异步方法。需在UI线程中调用OH_ArkWeb_GetNativeAPI方法获取该接口。该方法通过消息队列机制实现异步调用，避免阻塞主线程。与registerAsyncJavaScriptProxy相比，此方法增加了permission参数用于配置JSBridge的权限限制，适用于需要权限控制的异步操作场景。

**起始版本：** 18

**参数：**

| 参数项 | 描述 | 
| -------- | -------- |
| const char* webTag | Web组件名称。  | 
| const ArkWeb_ProxyObject* proxyObject | 注册的对象。  | 
| const char* permission | JSON格式字符串，默认值为空。该字符串用来配置JSBridge的权限限制，可以配置对象和方法级别。 | 

