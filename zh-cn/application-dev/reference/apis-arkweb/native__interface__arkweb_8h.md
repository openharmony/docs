# native_interface_arkweb.h


## 概述

声明API接口供开发者使用注入对象和执行JavaScript代码等功能。

**库：** libohweb.so

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11

**相关模块：**[Web](_web.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef void(\* [NativeArkWeb_OnJavaScriptCallback](_web.md#nativearkweb_onjavascriptcallback)) (const char \*) | runJavaScript接口的结果回调函数类型。当H5侧执行完后返回结果时通过该接口通知开发者。  | 
| typedef char \*(\* [NativeArkWeb_OnJavaScriptProxyCallback](_web.md#nativearkweb_onjavascriptproxycallback)) (const char \*\*argv, int32_t argc) | registerJavaScirptProxy接口的回调函数类型。当H5侧主动调用注册的对象下的函数时通过该接口通知开发者。  | 
| typedef void(\* [NativeArkWeb_OnValidCallback](_web.md#nativearkweb_onvalidcallback)) (const char \*) | Web组件可注册对象时的回调函数类型。  | 
| typedef void(\* [NativeArkWeb_OnDestroyCallback](_web.md#nativearkweb_ondestroycallback)) (const char \*) | Web组件销毁时的回调函数类型。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| void [OH_NativeArkWeb_RunJavaScript](_web.md#oh_nativearkweb_runjavascript) (const char \*webTag, const char \*jsCode, [NativeArkWeb_OnJavaScriptCallback](_web.md#nativearkweb_onjavascriptcallback) callback) | 加载一段JS脚本，并通过回调返回脚本的执行结果。  | 
| void [OH_NativeArkWeb_RegisterJavaScriptProxy](_web.md#oh_nativearkweb_registerjavascriptproxy) (const char \*webTag, const char \*objName, const char \*\*methodList, [NativeArkWeb_OnJavaScriptProxyCallback](_web.md#nativearkweb_onjavascriptproxycallback) \*callback, int32_t size, bool needRefresh) | 注册应用侧的对象及回调函数。  | 
| void [OH_NativeArkWeb_UnregisterJavaScriptProxy](_web.md#oh_nativearkweb_unregisterjavascriptproxy) (const char \*webTag, const char \*objName) | 删除已注册的对象及回调函数。  | 
| void [OH_NativeArkWeb_SetJavaScriptProxyValidCallback](_web.md#oh_nativearkweb_setjavascriptproxyvalidcallback) (const char \*webTag, [NativeArkWeb_OnValidCallback](_web.md#nativearkweb_onvalidcallback) callback) | 设置对象可注册的回调函数。  | 
| [NativeArkWeb_OnValidCallback](_web.md#nativearkweb_onvalidcallback) [OH_NativeArkWeb_GetJavaScriptProxyValidCallback](_web.md#oh_nativearkweb_getjavascriptproxyvalidcallback) (const char \*webTag) | 获取对象可注册的回调函数。  | 
| void [OH_NativeArkWeb_SetDestroyCallback](_web.md#oh_nativearkweb_setdestroycallback) (const char \*webTag, [NativeArkWeb_OnDestroyCallback](_web.md#nativearkweb_ondestroycallback) callback) | 设置组件销毁的回调函数。  | 
| [NativeArkWeb_OnDestroyCallback](_web.md#nativearkweb_ondestroycallback) [OH_NativeArkWeb_GetDestroyCallback](_web.md#oh_nativearkweb_getdestroycallback) (const char \*webTag) | 获取组件销毁的回调函数。  | 
