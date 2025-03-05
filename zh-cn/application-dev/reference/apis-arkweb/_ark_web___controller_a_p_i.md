# ArkWeb_ControllerAPI


## 概述

Controller相关的Native API结构体。 在调用接口前建议通过ARKWEB_MEMBER_MISSING校验该函数结构体是否有对应函数指针，避免SDK与设备ROM不匹配导致crash问题。

**起始版本：** 12

**相关模块：**[Web](_web.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| size_t [size](#size) | 结构体的大小。  | 
| void(\* [runJavaScript](#runjavascript) )(const char \*webTag, const [ArkWeb_JavaScriptObject](_ark_web___java_script_object.md) \*javascriptObject) | 注入JavaScript脚本。  | 
| void(\* [registerJavaScriptProxy](#registerjavascriptproxy) )(const char \*webTag, const [ArkWeb_ProxyObject](_ark_web___proxy_object.md) \*proxyObject) | 注入JavaScript对象到window对象中，并在window对象中调用该对象的同步方法。  | 
| void(\* [deleteJavaScriptRegister](#deletejavascriptregister) )(const char \*webTag, const char \*objName) | 删除通过registerJavaScriptProxy注册到window上的指定name的应用侧JavaScript对象。  | 
| void(\* [refresh](#refresh) )(const char \*webTag) | 刷新当前网页。  | 
| void(\* [registerAsyncJavaScriptProxy](#registerasyncjavascriptproxy) )(const char \*webTag, const [ArkWeb_ProxyObject](_ark_web___proxy_object.md) \*proxyObject) | 注入JavaScript对象到window对象中，并在window对象中调用该对象的异步方法。  | 
| [ArkWeb_WebMessagePortPtr](_web.md#arkweb_webmessageportptr) \*(\* [createWebMessagePorts](#createwebmessageports) )(const char \*webTag, size_t \*[size](#size)) | 创建Post Message端口。  | 
| void(\* [destroyWebMessagePorts](#destroywebmessageports) )([ArkWeb_WebMessagePortPtr](_web.md#arkweb_webmessageportptr) \*\*ports, size_t [size](#size)) | 销毁端口。  | 
| [ArkWeb_ErrorCode](_web.md#arkweb_errorcode)(\* [postWebMessage](#postwebmessage) )(const char \*webTag, const char \*name, [ArkWeb_WebMessagePortPtr](_web.md#arkweb_webmessageportptr) \*webMessagePorts, size_t [size](#size), const char \*url) | 将端口发送到HTML主页面.  | 
| const char \*(\* [getLastJavascriptProxyCallingFrameUrl](#getlastjavascriptproxycallingframeurl) )() | 获取调用JavaScriptProxy最后一帧的url。 在JavaScriptProxy调用的线程上调用。 通过registerJavaScriptProxy或者javaScriptProxy注入JavaScript对象到window对象中。该接口可以获取最后一次调用注入对象frame的url。 在被调用函数内部获取url才能获取到正确值，可以在函数里内部获取url后保存下来。  | 
| void(\* [registerJavaScriptProxyEx](#registerjavascriptproxyex) )(const char \*webTag, const [ArkWeb_ProxyObjectWithResult](_ark_web___proxy_object_with_result.md) \*proxyObject, const char \*permission) | 注入JavaScript对象到window对象中，并在window对象中调用该对象的同步方法。该对象的同步方法可以带返回值。  | 
| void(\* [registerAsyncJavaScriptProxyEx](#registerasyncjavascriptproxyex) )(const char \*webTag, const [ArkWeb_ProxyObject](_ark_web___proxy_object.md) \*proxyObject, const char \*permission) | 注入JavaScript对象到window对象中，并在window对象中调用该对象的异步方法。  | 


## 结构体成员变量说明


### createWebMessagePorts

```
ArkWeb_WebMessagePortPtr*(* ArkWeb_ControllerAPI::createWebMessagePorts) (const char *webTag, size_t *size)
```
**描述：**

创建Post Message端口。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webTag | Web组件名称。  | 
| size | 出参，端口数量。  | 

**返回：**

Post Message端口结构体指针。


### deleteJavaScriptRegister

```
void(* ArkWeb_ControllerAPI::deleteJavaScriptRegister) (const char *webTag, const char *objName)
```
**描述：**

删除通过registerJavaScriptProxy注册到window上的指定name的应用侧JavaScript对象。


### destroyWebMessagePorts

```
void(* ArkWeb_ControllerAPI::destroyWebMessagePorts) (ArkWeb_WebMessagePortPtr **ports, size_t size)
```
**描述：**

销毁端口。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ports | Message端口结构体指针数组。  | 
| size | 端口数量。 | 


### getLastJavascriptProxyCallingFrameUrl

```
const char*(* ArkWeb_ControllerAPI::getLastJavascriptProxyCallingFrameUrl) ()
```
**描述：**

获取调用JavaScriptProxy最后一帧的url。 在JavaScriptProxy调用的线程上调用。 通过registerJavaScriptProxy或者javaScriptProxy注入JavaScript对象到window对象中。该接口可以获取最后一次调用注入对象frame的url。 在被调用函数内部获取url才能获取到正确值，可以在函数里内部获取url后保存下来。

**起始版本：** 14

**返回：**

调用JavaScriptProxy最后一帧的url。


### postWebMessage

```
ArkWeb_ErrorCode(* ArkWeb_ControllerAPI::postWebMessage) (const char *webTag, const char *name, ArkWeb_WebMessagePortPtr *webMessagePorts, size_t size, const char *url)
```
**描述：**

将端口发送到HTML主页面。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webTag | Web组件名称。  | 
| name | 发送给HTML的消息名称。  | 
| webMessagePorts | Post Message端口结构体指针。  | 
| size | 端口数量。  | 
| url | 接收到消息的页面url。  | 

**返回：**

返回值错误码。 [ARKWEB_SUCCESS](_web.md) 执行成功。 [ARKWEB_INVALID_PARAM](_web.md) 参数无效。 [ARKWEB_INIT_ERROR](_web.md) 初始化失败，没有找到与webTag绑定的Web组件。


### refresh

```
void(* ArkWeb_ControllerAPI::refresh) (const char *webTag)
```
**描述：**

刷新当前网页。


### registerAsyncJavaScriptProxy

```
void(* ArkWeb_ControllerAPI::registerAsyncJavaScriptProxy) (const char *webTag, const ArkWeb_ProxyObject *proxyObject)
```
**描述：**

注入JavaScript对象到window对象中，并在window对象中调用该对象的异步方法。


### registerAsyncJavaScriptProxyEx

```
void(* ArkWeb_ControllerAPI::registerAsyncJavaScriptProxyEx) (const char *webTag, const ArkWeb_ProxyObject *proxyObject, const char *permission)
```
**描述：**

注入JavaScript对象到window对象中，并在window对象中调用该对象的异步方法。

**起始版本：** 14

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webTag | Web组件名称。  | 
| proxyObject | 注册的对象。  | 
| permission | json格式字符串，默认值为空。该字符串用来配置JSBridge的权限限制，可以配置对象和方法级别。 | 


### registerJavaScriptProxy

```
void(* ArkWeb_ControllerAPI::registerJavaScriptProxy) (const char *webTag, const ArkWeb_ProxyObject *proxyObject)
```
**描述：**

注入JavaScript对象到window对象中，并在window对象中调用该对象的同步方法。


### registerJavaScriptProxyEx

```
void(* ArkWeb_ControllerAPI::registerJavaScriptProxyEx) (const char *webTag, const ArkWeb_ProxyObjectWithResult *proxyObject, const char *permission)
```
**描述：**

注入JavaScript对象到window对象中，并在window对象中调用该对象的同步方法。该对象的同步方法可以带返回值。

**起始版本：** 14

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webTag | Web组件名称。  | 
| proxyObject | 注册的对象。  | 
| permission | json格式字符串，默认值为空。该字符串用来配置JSBridge的权限限制，可以配置对象和方法级别。 | 


### runJavaScript

```
void(* ArkWeb_ControllerAPI::runJavaScript) (const char *webTag, const ArkWeb_JavaScriptObject *javascriptObject)
```
**描述：**

注入JavaScript脚本。


### size

```
size_t ArkWeb_ControllerAPI::size
```
**描述：**

结构体的大小。
