# arkweb_type.h


## 概述

提供ArkWeb在Native侧的公共类型定义。

**库：** libohweb.so

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
| struct&nbsp;&nbsp;[ArkWeb_ProxyObject](_ark_web___proxy_object.md) | 注入的Proxy对象通用结构体。  | 
| struct&nbsp;&nbsp;[ArkWeb_ControllerAPI](_ark_web___controller_a_p_i.md) | Controller相关的Native API结构体。  | 
| struct&nbsp;&nbsp;[ArkWeb_ComponentAPI](_ark_web___component_a_p_i.md) | Component相关的Native API结构体。  | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [ARKWEB_MEMBER_EXISTS](_web.md#arkweb_member_exists)(s, f)&nbsp;&nbsp;&nbsp;&nbsp;((intptr_t) &amp; ((s)-&gt;f) - (intptr_t)(s) + sizeof((s)-&gt;f) &lt;= \*reinterpret_cast&lt;size_t\*&gt;(s)) | 检查结构体中是否存在该成员变量。  | 
| [ARKWEB_MEMBER_MISSING](_web.md#arkweb_member_missing)(s, f)&nbsp;&nbsp;&nbsp;(\![ARKWEB_MEMBER_EXISTS](_web.md#arkweb_member_exists)(s, f) \|\| !((s)-&gt;f)) | 当前结构体存在该成员变量则返回false，否则返回true。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef void(\* [ArkWeb_OnJavaScriptCallback](_web.md#arkweb_onjavascriptcallback)) (const char \*webTag, const [ArkWeb_JavaScriptBridgeData](_ark_web___java_script_bridge_data.md) \*data, void \*userData) | 注入的JavaScript执行完成的回调。  | 
| typedef void(\* [ArkWeb_OnJavaScriptProxyCallback](_web.md#arkweb_onjavascriptproxycallback)) (const char \*webTag, const [ArkWeb_JavaScriptBridgeData](_ark_web___java_script_bridge_data.md) \*dataArray, size_t arraySize, void \*userData) | Proxy方法被执行的回调。  | 
| typedef void(\* [ArkWeb_OnComponentCallback](_web.md#arkweb_oncomponentcallback)) (const char \*webTag, void \*userData) | 组件事件通知相关的通用回调。  | 
