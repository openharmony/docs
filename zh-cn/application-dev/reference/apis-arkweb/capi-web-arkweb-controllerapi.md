# ArkWeb_ControllerAPI
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @yp99ustc; @aohui; @zourongchun-->
<!--Designer: @LongLie; @yaomingliu; @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

## 概述

Controller相关的Native API结构体。在调用接口前建议通过[ARKWEB_MEMBER_MISSING](capi-arkweb-type-h.md#宏定义)校验该函数结构体是否有对应函数指针，避免SDK与设备ROM不匹配导致crash问题。

**起始版本：** 12

**相关模块：** [Web](capi-web.md)

**所在头文件：** [arkweb_type.h](capi-arkweb-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| size_t size | 结构体的大小。 |


### 成员函数

| 名称 | 描述 |
| -- | -- |
| [void (\*runJavaScript)(const char* webTag, const ArkWeb_JavaScriptObject* javascriptObject)](#runjavascript) | 注入JavaScript脚本。 |
| [void (\*registerJavaScriptProxy)(const char* webTag, const ArkWeb_ProxyObject* proxyObject)](#registerjavascriptproxy) | 注入JavaScript对象到window对象中，并在window对象中调用该对象的同步方法。 |
| [void (\*deleteJavaScriptRegister)(const char* webTag, const char* objName)](#deletejavascriptregister) | 删除通过registerJavaScriptProxy注册到window上的指定name的应用侧JavaScript对象。 |
| [void (\*refresh)(const char* webTag)](#refresh) | 刷新当前网页。刷新的同时会清理页面栈，导致当前页面无法前进后退。 |
| [void (\*registerAsyncJavaScriptProxy)(const char* webTag, const ArkWeb_ProxyObject* proxyObject)](#registerasyncjavascriptproxy) | 注入JavaScript对象到window对象中，并在window对象中调用该对象的异步方法。 |
| [ArkWeb_WebMessagePortPtr* (\*createWebMessagePorts)(const char* webTag, size_t* size)](#createwebmessageports) | 创建Post Message端口。 |
| [void (\*destroyWebMessagePorts)(ArkWeb_WebMessagePortPtr** ports, size_t size)](#destroywebmessageports) | 销毁端口。 |
| [ArkWeb_ErrorCode (\*postWebMessage)(const char* webTag, const char* name, ArkWeb_WebMessagePortPtr* webMessagePorts, size_t size, const char* url)](#postwebmessage) | 将端口发送到HTML主页面. |
| [const char* (\*getLastJavascriptProxyCallingFrameUrl)()](#getlastjavascriptproxycallingframeurl) | 获取调用JavaScriptProxy最后一帧的url。在JavaScriptProxy调用的线程上调用。通过registerJavaScriptProxy或者javaScriptProxy注入JavaScript对象到window对象中。该接口可以获取最后一次调用注入对象frame的url。在被调用函数内部获取url才能获取到正确值，可以在函数里内部获取url后保存下来。<br>**起始版本：** 14 |
| [void (\*registerJavaScriptProxyEx)(const char* webTag, const ArkWeb_ProxyObjectWithResult* proxyObject,const char* permission)](#registerjavascriptproxyex) | 注入JavaScript对象到window对象中，并在window对象中调用该对象的同步方法。该对象的同步方法可以带返回值。<br>**起始版本：** 18 |
| [void (\*registerAsyncJavaScriptProxyEx)(const char* webTag, const ArkWeb_ProxyObject* proxyObject,const char* permission)](#registerasyncjavascriptproxyex) | 注入JavaScript对象到window对象中，并在window对象中调用该对象的异步方法。<br>**起始版本：** 18 |

## 成员函数说明

### runJavaScript()

```
void (*runJavaScript)(const char* webTag, const ArkWeb_JavaScriptObject* javascriptObject)
```

**描述：**

注入JavaScript脚本。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。                   |
|const ArkWeb_JavaScriptObject* javascriptObject  | 注入的JavaScript对象。           |

### registerJavaScriptProxy()

```
void (*registerJavaScriptProxy)(const char* webTag, const ArkWeb_ProxyObject* proxyObject)
```

**描述：**

注入JavaScript对象到window对象中，并在window对象中调用该对象的同步方法。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。                   |
| const ArkWeb_ProxyObject* proxyObject  | 注册的对象。          |

### deleteJavaScriptRegister()

```
void (*deleteJavaScriptRegister)(const char* webTag, const char* objName)
```

**描述：**

删除通过registerJavaScriptProxy注册到window上的指定name的应用侧JavaScript对象。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。                   |
| const char* objName  | JavaScript对象名称。          |

### refresh()

```
void (*refresh)(const char* webTag)
```

**描述：**

刷新当前网页。刷新的同时会清理页面栈，导致当前页面无法前进后退。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。                   |

### registerAsyncJavaScriptProxy()

```
void (*registerAsyncJavaScriptProxy)(const char* webTag, const ArkWeb_ProxyObject* proxyObject)
```

**描述：**

注入JavaScript对象到window对象中，并在window对象中调用该对象的异步方法。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。                   |
| const ArkWeb_ProxyObject* proxyObject  | 注册的对象。       |

### createWebMessagePorts()

```
ArkWeb_WebMessagePortPtr* (*createWebMessagePorts)(const char* webTag, size_t* size)
```

**描述：**

创建Post Message端口。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。 |
|  size_t* size | 出参，端口数量。 |

**返回：**

| 类型                           | 说明 |
|------------------------------|----|
| [ArkWeb_WebMessagePortPtr](capi-web-arkweb-webmessageport8h.md) | Post Message端口结构体指针。   |

### destroyWebMessagePorts()

```
void (*destroyWebMessagePorts)(ArkWeb_WebMessagePortPtr** ports, size_t size)
```

**描述：**

销毁端口。

**参数：**

| 参数项           | 描述                |
|---------------|--------------------|
| [ArkWeb_WebMessagePortPtr](capi-web-arkweb-webmessageport8h.md)** ports | 发送Message端口结构体指针数组。 |
| size_t size   | 端口数量。              |

### postWebMessage()

```
ArkWeb_ErrorCode (*postWebMessage)(const char* webTag, const char* name, ArkWeb_WebMessagePortPtr* webMessagePorts, size_t size, const char* url)
```

**描述：**

将端口发送到HTML主页面.

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。 |
|  const char* name | 发送给HTML的消息名称。 |
|  [ArkWeb_WebMessagePortPtr](capi-web-arkweb-webmessageport8h.md)* webMessagePorts | Post Message端口结构体指针。 |
|  size_t size | 端口数量。 |
|  const char* url | 接收到消息的页面url。 |

**返回：**

| 类型 | 说明                                                                                                                                                         |
|----|------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 返回值错误码。   | [ARKWEB_SUCCESS](capi-arkweb-error-code-h.md#arkweb_errorcode) 执行成功。<br>[ARKWEB_INVALID_PARAM](capi-arkweb-error-code-h.md#arkweb_errorcode) 参数无效。<br>[ARKWEB_INIT_ERROR](capi-arkweb-error-code-h.md#arkweb_errorcode) 初始化失败，没有找到与webTag绑定的Web组件。 |

### getLastJavascriptProxyCallingFrameUrl()

```
const char* (*getLastJavascriptProxyCallingFrameUrl)()
```

**描述：**

获取调用JavaScriptProxy最后一帧的url。在JavaScriptProxy调用的线程上调用。通过registerJavaScriptProxy或者javaScriptProxy注入JavaScript对象到window对象中。该接口可以获取最后一次调用注入对象frame的url。在被调用函数内部获取url才能获取到正确值，可以在函数里内部获取url后保存下来。

**起始版本：** 14

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 调用JavaScriptProxy最后一帧的url。 |

### registerJavaScriptProxyEx()

```
void (*registerJavaScriptProxyEx)(const char* webTag, const ArkWeb_ProxyObjectWithResult* proxyObject,const char* permission)
```

**描述：**

注入JavaScript对象到window对象中，并在window对象中调用该对象的同步方法。该对象的同步方法可以带返回值。

**起始版本：** 18

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。 |
|  const [ArkWeb_ProxyObjectWithResult](capi-web-arkweb-proxyobjectwithresult.md)* proxyObject | 注册的对象。 |
| const char* permission | json格式字符串，默认值为空。该字符串用来配置JSBridge的权限限制，可以配置对象和方法级别。 |

### registerAsyncJavaScriptProxyEx()

```
void (*registerAsyncJavaScriptProxyEx)(const char* webTag, const ArkWeb_ProxyObject* proxyObject, const char* permission)
```

**描述：**

注入JavaScript对象到window对象中，并在window对象中调用该对象的异步方法。

**起始版本：** 18

**参数：**

| 参数项 | 描述 | 
| -------- | -------- |
| const char* webTag | Web组件名称。  | 
| const ArkWeb_ProxyObject* proxyObject | 注册的对象。  | 
| const char* permission | json格式字符串，默认值为空。该字符串用来配置JSBridge的权限限制，可以配置对象和方法级别。 | 

