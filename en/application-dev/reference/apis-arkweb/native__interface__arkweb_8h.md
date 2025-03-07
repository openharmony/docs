# native_interface_arkweb.h


## Overview

Declares APIs used to inject objects and execute JavaScript code.

**Library**: libohweb.so

**File to include**: <web/native_interface_arkweb.h>

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 11

**Related module**: [Web](_web.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef void(\* [NativeArkWeb_OnJavaScriptCallback](_web.md#nativearkweb_onjavascriptcallback)) (const char \*) | Defines a callback used to return the result after the JavaScript code is executed. | 
| typedef char \*(\* [NativeArkWeb_OnJavaScriptProxyCallback](_web.md#nativearkweb_onjavascriptproxycallback)) (const char \*\*argv, int32_t argc) | Defines a callback of the injected object. | 
| typedef void(\* [NativeArkWeb_OnValidCallback](_web.md#nativearkweb_onvalidcallback)) (const char \*) | Defines a callback used when the **Web** component is valid. | 
| typedef void(\* [NativeArkWeb_OnDestroyCallback](_web.md#nativearkweb_ondestroycallback)) (const char \*) | Defines a callback used when the **Web** component is destroyed. | 


### Functions

| Name| Description| 
| -------- | -------- |
| void [OH_NativeArkWeb_RunJavaScript](_web.md#oh_nativearkweb_runjavascript) (const char \*webTag, const char \*jsCode, [NativeArkWeb_OnJavaScriptCallback](_web.md#nativearkweb_onjavascriptcallback) callback) | Runs a piece of JavaScript code in the displaying page. | 
| void [OH_NativeArkWeb_RegisterJavaScriptProxy](_web.md#oh_nativearkweb_registerjavascriptproxy) (const char \*webTag, const char \*objName, const char \*\*methodList, [NativeArkWeb_OnJavaScriptProxyCallback](_web.md#nativearkweb_onjavascriptproxycallback) \*callback, int32_t size, bool needRefresh) | Registers an object and a list of functions. | 
| void [OH_NativeArkWeb_UnregisterJavaScriptProxy](_web.md#oh_nativearkweb_unregisterjavascriptproxy) (const char \*webTag, const char \*objName) | Unregisters an object. This will deletes the object and its callback function. | 
| void [OH_NativeArkWeb_SetJavaScriptProxyValidCallback](_web.md#oh_nativearkweb_setjavascriptproxyvalidcallback) (const char \*webTag, [NativeArkWeb_OnValidCallback](_web.md#nativearkweb_onvalidcallback) callback) | Sets a callback used when an object can be registered. | 
| [NativeArkWeb_OnValidCallback](_web.md#nativearkweb_onvalidcallback) [OH_NativeArkWeb_GetJavaScriptProxyValidCallback](_web.md#oh_nativearkweb_getjavascriptproxyvalidcallback) (const char \*webTag) | Obtains the callback used when a registered object is valid. | 
| void [OH_NativeArkWeb_SetDestroyCallback](_web.md#oh_nativearkweb_setdestroycallback) (const char \*webTag, [NativeArkWeb_OnDestroyCallback](_web.md#nativearkweb_ondestroycallback) callback) | Sets a callback used when a component is destroyed. | 
| [NativeArkWeb_OnDestroyCallback](_web.md#nativearkweb_ondestroycallback) [OH_NativeArkWeb_GetDestroyCallback](_web.md#oh_nativearkweb_getdestroycallback) (const char \*webTag) | Obtains the callback used when a registered component is destroyed. | 
| [ArkWeb_ErrorCode](_web.md#arkweb_errorcode) [OH_NativeArkWeb_LoadData](_web.md#oh_nativearkweb_loaddata) (const char* webTag,const char* data,const char* mimeType,const char* encoding,const char* baseUrl,const char* historyUrl) | Loads data or URLs. This function must be called in the main thread. |
