# Web


## 概述

该模块主要提供Web组件下runJavaScript和registerJavaScirptProxy的NDK接口。

**起始版本：** 11


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_interface_arkweb.h](native__interface__arkweb_8h.md) | 该文件主要提供Web组件下runJavaScript和registerJavaScirptProxy的NDK接口。<br>**库：** libohweb.so  | 
| [arkweb_interface.h](arkweb__interface_8h.md) | 提供ArkWeb在Native侧获取API的接口，及基础Native API类型。<br>**库：** libohweb.so  | 
| [arkweb_type.h](arkweb__type_8h.md) | 提供ArkWeb在Native侧的公共类型定义。<br>**库：** libohweb.so  | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ArkWeb_AnyNativeAPI](_ark_web___any_native_a_p_i.md) | 定义基础Native API类型。  | 
| struct&nbsp;&nbsp;[ArkWeb_JavaScriptBridgeData](_ark_web___java_script_bridge_data.md) | 定义JavaScript Bridge数据的基础结构。  | 
| struct&nbsp;&nbsp;[ArkWeb_JavaScriptObject](_ark_web___java_script_object.md) | 注入的JavaScript结构体。  | 
| struct&nbsp;&nbsp;[ArkWeb_ProxyMethod](_ark_web___proxy_method.md) | 注入的Proxy方法通用结构体。  | 
| struct&nbsp;&nbsp;[ArkWeb_ProxyObject](_ark_web___proxy_object.md) | 注入的Proxy对象通用结构体。  | 
| struct&nbsp;&nbsp;[ArkWeb_ControllerAPI](_ark_web___controller_a_p_i.md) | Controller相关的Native API结构体。  | 
| struct&nbsp;&nbsp;[ArkWeb_ComponentAPI](_ark_web___component_a_p_i.md) | Component相关的Native API结构体。  | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [ARKWEB_MEMBER_EXISTS](#arkweb_member_exists)(s, f)&nbsp;&nbsp;&nbsp;&nbsp;((intptr_t) &amp; ((s)-&gt;f) - (intptr_t)(s) + sizeof((s)-&gt;f) &lt;= \*reinterpret_cast&lt;size_t\*&gt;(s)) | 检查结构体中是否存在该成员变量。  | 
| [ARKWEB_MEMBER_MISSING](#arkweb_member_missing)(s, f)&nbsp;&nbsp;&nbsp;(\![ARKWEB_MEMBER_EXISTS](#arkweb_member_exists)(s, f) \|\| !((s)-&gt;f)) | 当前结构体存在该成员变量则返回false，否则返回true。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef void(\* [NativeArkWeb_OnJavaScriptCallback](#nativearkweb_onjavascriptcallback)) (const char \*) | runJavaScript接口的结果回调函数类型。当H5侧执行完后返回结果时通过该接口通知开发者。  | 
| typedef char \*(\* [NativeArkWeb_OnJavaScriptProxyCallback](#nativearkweb_onjavascriptproxycallback)) (const char \*\*argv, int32_t argc) | registerJavaScirptProxy接口的回调函数类型。当H5侧主动调用注册的对象下的函数时通过该接口通知开发者。  | 
| typedef void(\* [NativeArkWeb_OnValidCallback](#nativearkweb_onvalidcallback)) (const char \*) | Web组件可注册对象时的回调函数类型。  | 
| typedef void(\* [NativeArkWeb_OnDestroyCallback](#nativearkweb_ondestroycallback)) (const char \*) | Web组件销毁时的回调函数类型。  | 
| typedef void(\* [ArkWeb_OnJavaScriptCallback](#arkweb_onjavascriptcallback)) (const char \*webTag, const [ArkWeb_JavaScriptBridgeData](_ark_web___java_script_bridge_data.md) \*data, void \*userData) | 注入的JavaScript执行完成的回调。  | 
| typedef void(\* [ArkWeb_OnJavaScriptProxyCallback](#arkweb_onjavascriptproxycallback)) (const char \*webTag, const [ArkWeb_JavaScriptBridgeData](_ark_web___java_script_bridge_data.md) \*dataArray, size_t arraySize, void \*userData) | Proxy方法被执行的回调。  | 
| typedef void(\* [ArkWeb_OnComponentCallback](#arkweb_oncomponentcallback)) (const char \*webTag, void \*userData) | 组件事件通知相关的通用回调。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ArkWeb_NativeAPIVariantKind](#arkweb_nativeapivariantkind) { ARKWEB_NATIVE_COMPONENT, ARKWEB_NATIVE_CONTROLLER } | 定义Native API的类型枚举。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| void [OH_NativeArkWeb_RunJavaScript](#oh_nativearkweb_runjavascript) (const char \*webTag, const char \*jsCode, [NativeArkWeb_OnJavaScriptCallback](#nativearkweb_onjavascriptcallback) callback) | 加载一段JS脚本，并通过回调返回脚本的执行结果。  | 
| void [OH_NativeArkWeb_RegisterJavaScriptProxy](#oh_nativearkweb_registerjavascriptproxy) (const char \*webTag, const char \*objName, const char \*\*methodList, [NativeArkWeb_OnJavaScriptProxyCallback](#nativearkweb_onjavascriptproxycallback) \*callback, int32_t size, bool needRefresh) | 注册应用侧的对象及回调函数。  | 
| void [OH_NativeArkWeb_UnregisterJavaScriptProxy](#oh_nativearkweb_unregisterjavascriptproxy) (const char \*webTag, const char \*objName) | 删除已注册的对象及回调函数。  | 
| void [OH_NativeArkWeb_SetJavaScriptProxyValidCallback](#oh_nativearkweb_setjavascriptproxyvalidcallback) (const char \*webTag, [NativeArkWeb_OnValidCallback](#nativearkweb_onvalidcallback) callback) | 设置对象可注册的回调函数。  | 
| [NativeArkWeb_OnValidCallback](#nativearkweb_onvalidcallback)[OH_NativeArkWeb_GetJavaScriptProxyValidCallback](#oh_nativearkweb_getjavascriptproxyvalidcallback) (const char \*webTag) | 获取对象可注册的回调函数。  | 
| void [OH_NativeArkWeb_SetDestroyCallback](#oh_nativearkweb_setdestroycallback) (const char \*webTag, [NativeArkWeb_OnDestroyCallback](#nativearkweb_ondestroycallback) callback) | 设置组件销毁的回调函数。 | 
| [NativeArkWeb_OnDestroyCallback](#nativearkweb_ondestroycallback)[OH_NativeArkWeb_GetDestroyCallback](#oh_nativearkweb_getdestroycallback) (const char \*webTag) | 获取组件销毁的回调函数。  |
| [ArkWeb_AnyNativeAPI](_ark_web___any_native_a_p_i.md) \* OH_ArkWeb_GetNativeAPI ([ArkWeb_NativeAPIVariantKind](#arkweb_nativeapivariantkind) type) |  根据传入的API类型，获取对应的Native API结构体。| 


## 宏定义说明


### ARKWEB_MEMBER_EXISTS

```
#define ARKWEB_MEMBER_EXISTS( s,  f )    ((intptr_t) & ((s)->f) - (intptr_t)(s) + sizeof((s)->f) <= *reinterpret_cast<size_t*>(s))
```
**描述：**

检查结构体中是否存在该成员变量。

**起始版本：** 12


### ARKWEB_MEMBER_MISSING

```
#define ARKWEB_MEMBER_MISSING( s,  f )   (!ARKWEB_MEMBER_EXISTS(s, f) || !((s)->f))
```
**描述：**

当前结构体存在该成员变量则返回false，否则返回true。

**起始版本：** 12


## 类型定义说明


### NativeArkWeb_OnDestroyCallback

```
typedef void(* NativeArkWeb_OnDestroyCallback) (const char *)
```
**描述：**

定义Web组件销毁时的回调函数的类型。

**起始版本：** 11


### NativeArkWeb_OnJavaScriptCallback

```
typedef void(* NativeArkWeb_OnJavaScriptCallback) (const char *)
```
**描述：**

定义执行JavaScript代码后返回结果的回调函数的类型。

**起始版本：** 11


### NativeArkWeb_OnJavaScriptProxyCallback

```
typedef char*(* NativeArkWeb_OnJavaScriptProxyCallback) (const char **argv, int32_t argc)
```
**描述：**

定义注入对象的回调函数的类型。

**起始版本：** 11


### NativeArkWeb_OnValidCallback

```
typedef void(* NativeArkWeb_OnValidCallback) (const char *)
```
**描述：**

定义Web组件可用时的回调函数的类型。

**起始版本：** 11


### ArkWeb_OnComponentCallback

```
typedef void(* ArkWeb_OnComponentCallback) (const char *webTag, void *userData)
```
**描述：**

组件事件通知相关的通用回调。

**起始版本：** 12


### ArkWeb_OnJavaScriptCallback

```
typedef void(* ArkWeb_OnJavaScriptCallback) (const char *webTag, const ArkWeb_JavaScriptBridgeData *data, void *userData)
```
**描述：**

注入的JavaScript执行完成的回调。

**起始版本：** 12


### ArkWeb_OnJavaScriptProxyCallback

```
typedef void(* ArkWeb_OnJavaScriptProxyCallback) (const char *webTag, const ArkWeb_JavaScriptBridgeData *dataArray, size_t arraySize, void *userData)
```
**描述：**

Proxy方法被执行的回调。

**起始版本：** 12

## 函数说明


### OH_NativeArkWeb_GetDestroyCallback()

```
NativeArkWeb_OnDestroyCallback OH_NativeArkWeb_GetDestroyCallback (const char * webTag)
```
**描述：**

获取已注册的组件销毁时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webTag | Web组件的名称。  | 

**返回：**

已注册的组件销毁时的回调函数。


### OH_NativeArkWeb_GetJavaScriptProxyValidCallback()

```
NativeArkWeb_OnValidCallback OH_NativeArkWeb_GetJavaScriptProxyValidCallback (const char * webTag)
```
**描述：**

获取已注册的对象可注册时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webTag | Web组件的名称。  | 

**返回：**

已注册的对象可注册时的回调函数。


### OH_NativeArkWeb_RegisterJavaScriptProxy()

```
void OH_NativeArkWeb_RegisterJavaScriptProxy (const char * webTag, const char * objName, const char ** methodList, NativeArkWeb_OnJavaScriptProxyCallback * callback, int32_t size, bool needRefresh )
```
**描述：**

注册对象及函数名称列表。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webTag | Web组件的名称。  | 
| objName | 注入对象的名称。  | 
| methodList | 注入函数列表的名称。  | 
| callback | 注入的回调函数。  | 
| size | 注入的回调函数的个数。  | 
| needRefresh | 是否需要刷新页面。 | 


### OH_NativeArkWeb_RunJavaScript()

```
void OH_NativeArkWeb_RunJavaScript (const char * webTag, const char * jsCode, NativeArkWeb_OnJavaScriptCallback callback )
```
**描述：**

在当前显示页面的环境下，加载并执行一段JavaScript代码。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webTag | Web组件的名称。  | 
| jsCode | 一段JavaScript的代码脚本。  | 
| callback | 代码执行完后通知开发者结果的回调函数。 | 


### OH_NativeArkWeb_SetDestroyCallback()

```
void OH_NativeArkWeb_SetDestroyCallback (const char * webTag, NativeArkWeb_OnDestroyCallback callback )
```
**描述：**

设置组件销毁时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webTag | Web组件的名称。  | 
| callback | 组件销毁时的回调函数。 | 


### OH_NativeArkWeb_SetJavaScriptProxyValidCallback()

```
void OH_NativeArkWeb_SetJavaScriptProxyValidCallback (const char * webTag, NativeArkWeb_OnValidCallback callback )
```
**描述：**

设置对象可注册时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webTag | Web组件的名称。  | 
| callback | 对象可注册时的回调函数。 | 


### OH_NativeArkWeb_UnregisterJavaScriptProxy()

```
void OH_NativeArkWeb_UnregisterJavaScriptProxy (const char * webTag, const char * objName )
```
**描述：**

删除已注册的对象及其下的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webTag | Web组件的名称。  | 
| objName | 注入对象的名称。 | 


## 枚举类型说明


### ArkWeb_NativeAPIVariantKind

```
enum ArkWeb_NativeAPIVariantKind
```
**描述：**

定义Native API的类型枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKWEB_NATIVE_COMPONENT  | component相关API类型。&nbsp;&nbsp; | 
| ARKWEB_NATIVE_CONTROLLER  | controller相关API类型。&nbsp;&nbsp; | 


## 示例代码


index.html
```html
<!DOCTYPE html>
<html lang="en-gb">
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>run javascript demo</title>
</head>
<body>
<h1>run JavaScript Ext demo</h1>
<p id="webDemo"></p>
<br>
<button type="button" style="height:30px;width:200px" onclick="testNdkProxyObjMethod1()">test ndk method1 ! </button>
<br>
<br>
<button type="button" style="height:30px;width:200px" onclick="testNdkProxyObjMethod2()">test ndk method2 ! </button>
<br>

</body>
<script type="text/javascript">

function testNdkProxyObjMethod1() {
      if (window.ndkProxy == undefined) {
            document.getElementById("webDemo").innerHTML = "m114 ndkProxy undefined"
            return "m114 objName undefined"
      }

      if (window.ndkProxy.method1 == undefined) {
            document.getElementById("webDemo").innerHTML = "m114 ndkProxy method1 undefined"
            return "m114 objName  test undefined"
      }

      if (window.ndkProxy.method2 == undefined) {
            document.getElementById("webDemo").innerHTML = "m114 ndkProxy method2 undefined"
            return "m114 objName  test undefined"
      }
      var retStr = window.ndkProxy.method1("hello", "world", [1.2, -3.4, 123.456], ["Saab", "Volvo", "BMW", undefined], 1.23456, 123789, true, false, 0,  undefined);
      document.getElementById("webDemo").innerHTML  = "ndkProxy and method1 is ok, " + retStr;
}

function testNdkProxyObjMethod2() {
      if (window.ndkProxy == undefined) {
            document.getElementById("webDemo").innerHTML = "m114 ndkProxy undefined"
            return "m114 objName undefined"
      }

      if (window.ndkProxy.method1 == undefined) {
            document.getElementById("webDemo").innerHTML = "m114 ndkProxy method1 undefined"
            return "m114 objName  test undefined"
      }

      if (window.ndkProxy.method2 == undefined) {
            document.getElementById("webDemo").innerHTML = "m114 ndkProxy method2 undefined"
            return "m114 objName  test undefined"
      }

    var student = {
            name:"zhang",
            sex:"man",
            age:25
    };
    var cars = [student, 456, false, 4.567];

    var retStr = window.ndkProxy.method2("hello", "world", false, cars);
    document.getElementById("webDemo").innerHTML  = "ndkProxy and method2 is ok, " + retStr;
}

function runJSRetStr(data) {
    const d = new Date();
    let time = d.getTime();
    return JSON.stringify(time)
}
</script>
</html>
```

index.ets

```ts
import testNapi from 'libentry.so'
import web_webview from '@ohos.web.webview';

class testObj {
  constructor() {
  }

  test(): string {
    console.log('hwd ArkUI Web Component');
    return "m114 ArkUI Web Component";
  }

  toString(): void {
    console.log('Web Component toString');
  }
}

@Entry
@Component
struct Index {
  webTag: string = 'web1211';
  controller: web_webview.WebviewController = new web_webview.WebviewController(this.webTag);

  @State testObjtest: testObj = new testObj();

  aboutToAppear() {
    console.error("aboutToAppear")
    web_webview.WebviewController.setWebDebuggingAccess(true);
    //初始化web ndk
    testNapi.nativeWebInit(this.webTag);
  }

  aboutToDisAppear() {
    console.error("aboutToDisAppear")
  }

  build() {
    Column() {
      Row() {
        Button('runJS hello')
          .fontSize(12)
          .onClick(() => {
            testNapi.runJavaScript(this.webTag, "runJSRetStr(\"" + "hello" + "\")");
          })
      }.height('20%')

      Row() {
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .javaScriptAccess(true)
          .fileAccess(true)
          .onControllerAttached(() => {
            console.error("ndk onControllerAttached webId: " + this.controller.getWebId());
            // 设置回调函数
            testNapi.nativeSetDestroy(this.webTag);
          })
      }.height('80%')
    }
  }
}
```

hello.cpp

```cpp

#include "napi/native_api.h"
#include <chrono>
#include <string>

#include "hilog/log.h"
#include "web/native_interface_arkweb.h"

constexpr unsigned int LOG_PRINT_DOMAIN = 0xFF00;

std::chrono::time_point<std::chrono::high_resolution_clock> start;
// 发送JS脚本到H5侧执行，执行结果的回调。
static void RunJavaScriptCallback(const char *result) {
    std::chrono::duration<double, std::milli> elapsed_ms = std::chrono::high_resolution_clock::now() - start;
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ArkWeb",
                 "ndk OH_NativeArkWeb_RunJavaScript end, cost time: %{public}f ms", elapsed_ms.count());

    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ArkWeb", "ndk OH_NativeArkWeb_RunJavaScript result:%{public}s",
                 result);
}

// 示例代码 ，注册了1个对象，2个方法
static char *ProxyMethod1(const char **argv, int argc) {
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ArkWeb", "ndk ProxyMethod1 argc:%{public}d", argc);
    for (int i = 0; i < argc; i++) {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ArkWeb", "ndk ProxyMethod1 argv[%{public}d]:%{public}s", i,
                     argv[i]);
    }
    char *ret = (char *)"ArkWeb hello from native ProxyMethod1";
    return ret;
}

static char *ProxyMethod2(const char **argv, int argc) {
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ArkWeb", "ndk ProxyMethod2 argc:%{public}d", argc);
    for (int i = 0; i < argc; i++) {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ArkWeb", "ndk ProxyMethod2 argv[%{public}d]:%{public}s", i,
                     argv[i]);
    }
    char *ret = (char *)"ArkWeb hello from native ProxyMethod2";
    return ret;
}

void ValidCallback(const char *webName) {
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ArkWeb", "ndk ValidCallback webName: %{public}s", webName);
    // 注册对象
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ArkWeb", "ndk RegisterJavaScriptProxy begin");
    const char *methodName[2] = {"method1", "method2"};
    NativeArkWeb_OnJavaScriptProxyCallback callback[2] = {ProxyMethod1, ProxyMethod2};

    // 调用ndk接口 注册对象
    // 如此注册的情况下，在H5页面就可以使用proxy.method1、proxy.method1调用此文件下的ProxyMethod1和ProxyMethod2方法了
    OH_NativeArkWeb_RegisterJavaScriptProxy(webName, "ndkProxy", methodName, callback, 2, false);

    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ArkWeb", "ndk RegisterJavaScriptProxy end");
}

void DestroyCallback(const char *webName) {
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ArkWeb", "ndk DestoryCallback webName: %{public}s", webName);
    // do what you need, eg: some clean-up work
}

static napi_value NativeWebInit(napi_env env, napi_callback_info info) {
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ArkWeb", "ndk NativeWebInit start");
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 获取第一个参数 webName
    size_t webNameSize = 0;
    napi_get_value_string_utf8(env, args[0], nullptr, 0, &webNameSize);
    char *webNameValue = new (std::nothrow) char[webNameSize + 1];
    size_t webNameLength = 0;
    napi_get_value_string_utf8(env, args[0], webNameValue, webNameSize + 1, &webNameLength);
    OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "ArkWeb", "ndk NativeWebInit webName:%{public}s", webNameValue);

    // 注js proxy册回调函数
    NativeArkWeb_OnValidCallback ptr = ValidCallback;
    OH_NativeArkWeb_SetJavaScriptProxyValidCallback(webNameValue, ptr);
    OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "ArkWeb", "ndk NativeWebInit ValidCallback set:%{public}p", ptr);
    NativeArkWeb_OnValidCallback retValidCallback = OH_NativeArkWeb_GetJavaScriptProxyValidCallback(webNameValue);
    if (retValidCallback) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "ArkWeb", "ndk NativeWebInit ValidCallback get:%{public}p",
                     retValidCallback);
    } else {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ArkWeb", "ndk retValidCallback null");
    }

    // 注册destroy回调函数
    OH_NativeArkWeb_SetDestroyCallback(webNameValue, DestroyCallback);
    OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "ArkWeb", "ndk NativeWebInit DestroyCallback:%{public}p",
                 DestroyCallback);
    auto retDestroyCallback1 = OH_NativeArkWeb_GetDestroyCallback(webNameValue);
    OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "ArkWeb", "ndk NativeWebInit DestroyCallback get:%{public}p",
                 retDestroyCallback1);

    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ArkWeb", "ndk NativeWebInit end");

    return nullptr;
}

static napi_value NativeSetDestroy(napi_env env, napi_callback_info info) {
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ArkWeb", "ndk NativeSetDestroy start");
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 获取第一个参数 webTag
    size_t webTagSize = 0;
    napi_get_value_string_utf8(env, args[0], nullptr, 0, &webTagSize);
    char *webTagValue = new (std::nothrow) char[webTagSize + 1];
    size_t webTagLength = 0;
    napi_get_value_string_utf8(env, args[0], webTagValue, webTagSize + 1, &webTagLength);
    OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "ArkWeb", "ndk NativeSetDestroy webTag:%{public}s", webTagValue);

    // 注册destroy回调函数
    OH_NativeArkWeb_SetDestroyCallback(webTagValue, DestroyCallback);
    OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "ArkWeb", "ndk NativeSetDestroy DestroyCallback:%{public}p",
                 DestroyCallback);
    auto retDestroyCallback1 = OH_NativeArkWeb_GetDestroyCallback(webTagValue);
    OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "ArkWeb", "ndk NativeSetDestroy DestroyCallback get:%{public}p",
                 retDestroyCallback1);

    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ArkWeb", "ndk NativeSetDestroy end");
    return nullptr;
}

// 发送JS脚本到H5侧执行
static napi_value RunJavaScript(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    // 获取第一个参数 webName
    size_t webNameSize = 0;
    napi_get_value_string_utf8(env, args[0], nullptr, 0, &webNameSize);
    char *webNameValue = new (std::nothrow) char[webNameSize + 1];
    size_t webNameLength = 0;
    napi_get_value_string_utf8(env, args[0], webNameValue, webNameSize + 1, &webNameLength);
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ArkWeb", "ndk OH_NativeArkWeb_RunJavaScript webName:%{public}s",
                 webNameValue);

    // 获取第二个参数 jsCode
    size_t bufferSize = 0;
    napi_get_value_string_utf8(env, args[1], nullptr, 0, &bufferSize);
    char *jsCode = new (std::nothrow) char[bufferSize + 1];
    size_t byteLength = 0;
    napi_get_value_string_utf8(env, args[1], jsCode, bufferSize + 1, &byteLength);

    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ArkWeb",
                 "ndk OH_NativeArkWeb_RunJavaScript jsCode len:%{public}d", strlen(jsCode));

    start = std::chrono::high_resolution_clock::now();

    // 调用ndk接口
    OH_NativeArkWeb_RunJavaScript(webNameValue, jsCode, RunJavaScriptCallback);
    return nullptr;
}

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports) {
    napi_property_descriptor desc[] = {
        {"nativeWebInit", nullptr, NativeWebInit, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"runJavaScript", nullptr, RunJavaScript, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"nativeSetDestroy", nullptr, NativeSetDestroy, nullptr, nullptr, nullptr, napi_default, nullptr},
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "entry",
    .nm_priv = ((void *)0),
    .reserved = {0},
};

extern "C" __attribute__((constructor)) void RegisterEntryModule(void) { napi_module_register(&demoModule); }
```

index.d.ts
```ts
export const nativeWebInit: (webName: string) => void;
export const runJavaScript: (webName: string, jsCode: string) => void;
export const nativeSetDestroy: (webTag: string) => void;
```