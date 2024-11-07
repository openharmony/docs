# native_interface_arkweb.h


## 概述

声明API接口供开发者使用注入对象和执行JavaScript代码等功能。

**库：** libohweb.so

**引用文件：** <web/native_interface_arkweb.h>

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11

**相关模块：**[Web](_web.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef void(\* [NativeArkWeb_OnJavaScriptCallback](_web.md#nativearkweb_onjavascriptcallback)) (const char \*) | 定义执行JavaScript代码后返回结果的回调函数的类型。  | 
| typedef char \*(\* [NativeArkWeb_OnJavaScriptProxyCallback](_web.md#nativearkweb_onjavascriptproxycallback)) (const char \*\*argv, int32_t argc) | 定义注入对象的回调函数的类型。  | 
| typedef void(\* [NativeArkWeb_OnValidCallback](_web.md#nativearkweb_onvalidcallback)) (const char \*) | 定义Web组件可用时的回调函数的类型。  | 
| typedef void(\* [NativeArkWeb_OnDestroyCallback](_web.md#nativearkweb_ondestroycallback)) (const char \*) | 定义Web组件销毁时的回调函数的类型。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| void [OH_NativeArkWeb_RunJavaScript](_web.md#oh_nativearkweb_runjavascript) (const char \*webTag, const char \*jsCode, [NativeArkWeb_OnJavaScriptCallback](_web.md#nativearkweb_onjavascriptcallback) callback) | 在当前显示页面的环境下，加载并执行一段JavaScript代码。  | 
| void [OH_NativeArkWeb_RegisterJavaScriptProxy](_web.md#oh_nativearkweb_registerjavascriptproxy) (const char \*webTag, const char \*objName, const char \*\*methodList, [NativeArkWeb_OnJavaScriptProxyCallback](_web.md#nativearkweb_onjavascriptproxycallback) \*callback, int32_t size, bool needRefresh) | 注册对象及函数名称列表。  | 
| void [OH_NativeArkWeb_UnregisterJavaScriptProxy](_web.md#oh_nativearkweb_unregisterjavascriptproxy) (const char \*webTag, const char \*objName) | 删除已注册的对象及其下的回调函数。  | 
| void [OH_NativeArkWeb_SetJavaScriptProxyValidCallback](_web.md#oh_nativearkweb_setjavascriptproxyvalidcallback) (const char \*webTag, [NativeArkWeb_OnValidCallback](_web.md#nativearkweb_onvalidcallback) callback) | 设置对象可注册时的回调函数。  | 
| [NativeArkWeb_OnValidCallback](_web.md#nativearkweb_onvalidcallback) [OH_NativeArkWeb_GetJavaScriptProxyValidCallback](_web.md#oh_nativearkweb_getjavascriptproxyvalidcallback) (const char \*webTag) | 获取已注册的对象可注册时的回调函数。  | 
| void [OH_NativeArkWeb_SetDestroyCallback](_web.md#oh_nativearkweb_setdestroycallback) (const char \*webTag, [NativeArkWeb_OnDestroyCallback](_web.md#nativearkweb_ondestroycallback) callback) | 设置组件销毁时的回调函数。  | 
| [NativeArkWeb_OnDestroyCallback](_web.md#nativearkweb_ondestroycallback) [OH_NativeArkWeb_GetDestroyCallback](_web.md#oh_nativearkweb_getdestroycallback) (const char \*webTag) | 获取已注册的组件销毁时的回调函数。  | 
