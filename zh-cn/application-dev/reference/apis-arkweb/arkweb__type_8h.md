# arkweb_type.h


## 概述

提供ArkWeb在Native侧的公共类型定义。

**库：** libohweb.so

**引用文件：** <web/arkweb_type.h>

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**相关模块：**[Web](_web.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ArkWeb_JavaScriptBridgeData](_ark_web___java_script_bridge_data.md) | 定义JavaScript Bridge数据的基础结构。  | 
| struct&nbsp;&nbsp;[ArkWeb_JavaScriptObject](_ark_web___java_script_object.md) | 注入的JavaScript结构体。  | 
| struct&nbsp;&nbsp;[ArkWeb_ProxyMethod](_ark_web___proxy_method.md) | 注入的Proxy方法通用结构体。  | 
| struct&nbsp;&nbsp;[ArkWeb_ProxyMethodWithResult](_ark_web___proxy_method_with_result.md) | 注入的Proxy方法通用结构体。  | 
| struct&nbsp;&nbsp;[ArkWeb_ProxyObject](_ark_web___proxy_object.md) | 注入的Proxy对象通用结构体。  | 
| struct&nbsp;&nbsp;[ArkWeb_ProxyObjectWithResult](_ark_web___proxy_object_with_result.md) | 注入的Proxy对象通用结构体。  | 
| struct&nbsp;&nbsp;[ArkWeb_ControllerAPI](_ark_web___controller_a_p_i.md) | Controller相关的Native API结构体。 在调用接口前建议通过ARKWEB_MEMBER_MISSING校验该函数结构体是否有对应函数指针，避免SDK与设备ROM不匹配导致crash问题。  | 
| struct&nbsp;&nbsp;[ArkWeb_ComponentAPI](_ark_web___component_a_p_i.md) | Component相关的Native API结构体。  | 
| struct&nbsp;&nbsp;[ArkWeb_WebMessagePortAPI](_ark_web___web_message_port_a_p_i.md) | Post Message相关的Native API结构体。 在调用接口前建议通过ARKWEB_MEMBER_MISSING校验该函数结构体是否有对应函数指针，避免SDK与设备ROM不匹配导致crash问题。  | 
| struct&nbsp;&nbsp;[ArkWeb_WebMessageAPI](_ark_web___web_message_a_p_i.md) | Post Message数据相关的Native API结构体。 在调用接口前建议通过ARKWEB_MEMBER_MISSING校验该函数结构体是否有对应函数指针，避免SDK与设备ROM不匹配导致crash问题。  | 
| struct&nbsp;&nbsp;[ArkWeb_CookieManagerAPI](_ark_web___cookie_manager_a_p_i.md) | 定义了ArkWeb的CookieManager接口。 在调用接口之前，建议使用ARKWEB_MEMBER_MISSING检查函数结构体是否有对应的函数指针，避免SDK与设备ROM不匹配导致崩溃。  | 
| struct&nbsp;&nbsp;[ArkWeb_JavaScriptValueAPI](_ark_web___java_script_value_a_p_i.md) | 定义了ArkWeb的JavaScriptValue接口。 在调用接口之前，建议使用ARKWEB_MEMBER_MISSING检查函数结构体是否有对应的函数指针，避免SDK与设备ROM不匹配导致崩溃。  | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [ARKWEB_MEMBER_EXISTS](_web.md#arkweb_member_exists)(s, f)&nbsp;&nbsp;&nbsp;&nbsp;((intptr_t) &amp; ((s)-&gt;f) - (intptr_t)(s) + sizeof((s)-&gt;f) &lt;= \*reinterpret_cast&lt;size_t\*&gt;(s)) | 检查结构体中是否存在该成员变量。  | 
| [ARKWEB_MEMBER_MISSING](_web.md#arkweb_member_missing)(s, f)&nbsp;&nbsp;&nbsp;(\![ARKWEB_MEMBER_EXISTS](_web.md#arkweb_member_exists)(s, f) \|\| !((s)-&gt;f)) | 当前结构体存在该成员变量则返回false，否则返回true。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [ArkWeb_WebMessageType](_web.md#arkweb_webmessagetype) [ArkWeb_WebMessageType](_web.md#arkweb_webmessagetype) | Post Message数据类型。  | 
| typedef enum [ArkWeb_JavaScriptValueType](_web.md#arkweb_javascriptvaluetype) [ArkWeb_JavaScriptValueType](_web.md#arkweb_javascriptvaluetype) | JavaScript数据类型。  | 
| typedef struct ArkWeb_WebMessage \* [ArkWeb_WebMessagePtr](_web.md#arkweb_webmessageptr) | Post Message数据结构体指针。  | 
| typedef struct ArkWeb_JavaScriptValue \* [ArkWeb_JavaScriptValuePtr](_web.md#arkweb_javascriptvalueptr) | JavaScript数据结构体指针。  | 
| typedef void(\* [ArkWeb_OnJavaScriptCallback](_web.md#arkweb_onjavascriptcallback)) (const char \*webTag, const [ArkWeb_JavaScriptBridgeData](_ark_web___java_script_bridge_data.md) \*data, void \*userData) | 注入的JavaScript执行完成的回调。  | 
| typedef void(\* [ArkWeb_OnJavaScriptProxyCallback](_web.md#arkweb_onjavascriptproxycallback)) (const char \*webTag, const [ArkWeb_JavaScriptBridgeData](_ark_web___java_script_bridge_data.md) \*dataArray, size_t arraySize, void \*userData) | Proxy方法被执行的回调。  | 
| typedef [ArkWeb_JavaScriptValuePtr](_web.md#arkweb_javascriptvalueptr)(\* [ArkWeb_OnJavaScriptProxyCallbackWithResult](_web.md#arkweb_onjavascriptproxycallbackwithresult)) (const char \*webTag, const [ArkWeb_JavaScriptBridgeData](_ark_web___java_script_bridge_data.md) \*dataArray, size_t arraySize, void \*userData) | Proxy方法被执行的回调。  | 
| typedef void(\* [ArkWeb_OnComponentCallback](_web.md#arkweb_oncomponentcallback)) (const char \*webTag, void \*userData) | 组件事件通知相关的通用回调。  | 
| typedef struct ArkWeb_WebMessagePort \* [ArkWeb_WebMessagePortPtr](_web.md#arkweb_webmessageportptr) | Post Message端口结构体指针。  | 
| typedef void(\* [ArkWeb_OnMessageEventHandler](_web.md#arkweb_onmessageeventhandler)) (const char \*webTag, const [ArkWeb_WebMessagePortPtr](_web.md#arkweb_webmessageportptr) port, const [ArkWeb_WebMessagePtr](_web.md#arkweb_webmessageptr) message, void \*userData) | 处理HTML发送过来的Post Message数据。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ArkWeb_WebMessageType](_web.md#arkweb_webmessagetype) { [ARKWEB_NONE](_web.md) = 0, [ARKWEB_STRING](_web.md), [ARKWEB_BUFFER](_web.md) } | Post Message数据类型。  | 
| [ArkWeb_JavaScriptValueType](_web.md#arkweb_javascriptvaluetype) { [ARKWEB_JAVASCRIPT_NONE](_web.md) = 0, [ARKWEB_JAVASCRIPT_STRING](_web.md), [ARKWEB_JAVASCRIPT_BOOL](_web.md) } | JavaScript数据类型。  | 
