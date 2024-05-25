# OHWebJSBridge


## Overview

The **OHWebJSBridge** module provides the native APIs related to **runJavaScript** and **registerJavaScirptProxy** in the **\<Web>** component.

**Since**: 11

**Related module**: [OHWebJSBridge](native_interface_arkweb.md)


## Summary

### File

| Name| Description|
| -------- | -------- |
| [native_interface_arkweb.h](native_interface_arkweb.md) | Declares the native APIs related to **runJavaScript** and **registerJavaScirptProxy** in the **\<Web>** component.|


### Types

| Name| Description|
| -------- | -------- |
| NativeArkWeb_OnJavaScriptCallback | Result callback function for **runJavaScript**. It is used to notify you of the execution result from the HTML5 side.|
| NativeArkWeb_OnJavaScriptProxyCallback | Callback function for **registerJavaScirptProxy**. It is used to notify you when the HTML5 side proactively calls any function of the registered object.|
| NativeArkWeb_OnValidCallback | Callback function called when the **\<Web>** component can register an object.|
| NativeArkWeb_OnDestroyCallback | Callback function called when the **\<Web>** component is destroyed.|

### Functions

| Name| Description|
| -------- | -------- |
|OH_NativeArkWeb_RunJavaScript(const char* webTag, const char* jsCode, NativeArkWeb_OnJavaScriptCallback callback)|Loads JavaScript code and returns the code execution result through the callback.|
|OH_NativeArkWeb_RegisterJavaScriptProxy(const char* webTag, const char* objName, const char** methodList, NativeArkWeb_OnJavaScriptProxyCallback* callback, int32_t size, bool needRefresh)|Registers an object and callback function on the application side.|
|OH_NativeArkWeb_UnregisterJavaScriptProxy(const char* webTag, const char* objName)|Deletes a registered object and callback function.|
|OH_NativeArkWeb_SetJavaScriptProxyValidCallback(const char* webTag, NativeArkWeb_OnValidCallback callback)|Sets the callback function for when an object can be registered.|
|NativeArkWeb_OnValidCallback OH_NativeArkWeb_GetJavaScriptProxyValidCallback(const char* webTag)|Obtains the callback function for when an object can be registered.|
|OH_NativeArkWeb_SetDestroyCallback(const char* webTag, NativeArkWeb_OnDestroyCallback callback)|Sets the callback function for destroying a component.|
|NativeArkWeb_OnDestroyCallback OH_NativeArkWeb_GetDestroyCallback(const char* webTag)|Obtains the callback function for destroying a component.|

## Function Description


### OH_NativeArkWeb_RunJavaScript

```
OH_NativeArkWeb_RunJavaScript(const char* webTag, const char* jsCode, NativeArkWeb_OnJavaScriptCallback callback)
```

**Description**

Loads JavaScript code and returns the code execution result through the callback.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| webTag | Tag that uniquely identifies a **\<Web>** component. Ensure that it is unique.|
| jsCode | JavaScript code snippet sent to the HTML5 side for execution.|
| callback | Callback used to return the execution result of the JavaScript code snippet from the HTML5 side.|

### OH_NativeArkWeb_RegisterJavaScriptProxy

```
OH_NativeArkWeb_RegisterJavaScriptProxy(const char* webTag, const char* objName, const char** methodList, NativeArkWeb_OnJavaScriptProxyCallback* callback, int32_t size, bool needRefresh)
```

**Description**

Registers an object and callback function on the application side.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| webTag | Tag that uniquely identifies a **\<Web>** component. Ensure that it is unique.|
| objName | Name of the object to inject. The object will be registered under the window object on the HTML5 side.|
| methodList | Name list of functions under the injected object.|
| callback | Callback function under the injected object. The name must be the same as that in **medhotList**.|
| size | Number of function name lists under the injected object.|
| needRefresh | Whether refreshing is needed for the object after it is injected.|

### OH_NativeArkWeb_UnregisterJavaScriptProxy

```
OH_NativeArkWeb_UnregisterJavaScriptProxy(const char* webTag, const char* objName)
```

**Description**

Deletes a registered object and callback function.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| webTag | Tag that uniquely identifies a **\<Web>** component. Ensure that it is unique.|
| objName | Name of the object to inject. The object will be registered under the window object on the HTML5 side.|

### OH_NativeArkWeb_SetJavaScriptProxyValidCallback

```
OH_NativeArkWeb_SetJavaScriptProxyValidCallback(const char* webTag, NativeArkWeb_OnValidCallback callback);
```

**Description**

Sets the callback function for when an object can be registered.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| webTag | Tag that uniquely identifies a **\<Web>** component. Ensure that it is unique.|
| callback | Callback function for when the object can be registered. When an object can be registered after the specified **\<Web>** component is created, this callback function is called to notify you.|

### OH_NativeArkWeb_GetJavaScriptProxyValidCallback

```
NativeArkWeb_OnValidCallback OH_NativeArkWeb_GetJavaScriptProxyValidCallback(const char* webTag)
```

**Description**

Obtains the callback function for when an object can be registered.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| webTag | Tag that uniquely identifies a **\<Web>** component. Ensure that it is unique.|
| callback | Callback function for when the object can be registered. When an object can be registered after the specified **\<Web>** component is created, this callback function is called to notify you.|

**Returns**

Registered callback function based on the tag name.

### OH_NativeArkWeb_SetDestroyCallback

```
OH_NativeArkWeb_SetDestroyCallback(const char* webTag, NativeArkWeb_OnDestroyCallback callback)
```

**Description**

Sets the callback function for destroying a component.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| webTag | Tag that uniquely identifies a **\<Web>** component. Ensure that it is unique.|
| callback | Callback function invoked when the specified **\<Web>** component is destroyed.|

### OH_NativeArkWeb_GetDestroyCallback

```
NativeArkWeb_OnDestroyCallback OH_NativeArkWeb_GetDestroyCallback(const char* webTag)
```

**Description**

Obtains the callback function for destroying a component based on the tag name.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| webTag | Tag that uniquely identifies a **\<Web>** component. Ensure that it is unique.|

**Returns**

Registered callback function based on the tag name.

## Example


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
    // Initialize the web NDK.
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
            // Set the callback.
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
// Send the JS code to the HTML5 side for execution and obtain the execution result through a callback.
static void RunJavaScriptCallback(const char *result) {
    std::chrono::duration<double, std::milli> elapsed_ms = std::chrono::high_resolution_clock::now() - start;
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ArkWeb",
                 "ndk OH_NativeArkWeb_RunJavaScript end, cost time: %{public}f ms", elapsed_ms.count());

    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ArkWeb", "ndk OH_NativeArkWeb_RunJavaScript result:%{public}s",
                 result);
}

// This example registers one object and two methods.
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
    // Register an object.
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ArkWeb", "ndk RegisterJavaScriptProxy begin");
    const char *methodName[2] = {"method1", "method2"};
    NativeArkWeb_OnJavaScriptProxyCallback callback[2] = {ProxyMethod1, ProxyMethod2};

    // Invoke the native API to register the object.
    // In this case, you can use proxy.method1 and proxy.method2 to call ProxyMethod1 and ProxyMethod2 in this file on the HTML5 side.
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
    // Obtain the first parameter webName.
    size_t webNameSize = 0;
    napi_get_value_string_utf8(env, args[0], nullptr, 0, &webNameSize);
    char *webNameValue = new (std::nothrow) char[webNameSize + 1];
    size_t webNameLength = 0;
    napi_get_value_string_utf8(env, args[0], webNameValue, webNameSize + 1, &webNameLength);
    OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "ArkWeb", "ndk NativeWebInit webName:%{public}s", webNameValue);

    // Use the JS proxy callback function.
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

    // Use the destroy callback function.
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
    // Obtain the first parameter webTag.
    size_t webTagSize = 0;
    napi_get_value_string_utf8(env, args[0], nullptr, 0, &webTagSize);
    char *webTagValue = new (std::nothrow) char[webTagSize + 1];
    size_t webTagLength = 0;
    napi_get_value_string_utf8(env, args[0], webTagValue, webTagSize + 1, &webTagLength);
    OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "ArkWeb", "ndk NativeSetDestroy webTag:%{public}s", webTagValue);

    // Use the destroy callback function.
    OH_NativeArkWeb_SetDestroyCallback(webTagValue, DestroyCallback);
    OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "ArkWeb", "ndk NativeSetDestroy DestroyCallback:%{public}p",
                 DestroyCallback);
    auto retDestroyCallback1 = OH_NativeArkWeb_GetDestroyCallback(webTagValue);
    OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "ArkWeb", "ndk NativeSetDestroy DestroyCallback get:%{public}p",
                 retDestroyCallback1);

    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ArkWeb", "ndk NativeSetDestroy end");
    return nullptr;
}

// Send the JS code to the HTML5 side for execution.
static napi_value RunJavaScript(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    // Obtain the first parameter webName.
    size_t webNameSize = 0;
    napi_get_value_string_utf8(env, args[0], nullptr, 0, &webNameSize);
    char *webNameValue = new (std::nothrow) char[webNameSize + 1];
    size_t webNameLength = 0;
    napi_get_value_string_utf8(env, args[0], webNameValue, webNameSize + 1, &webNameLength);
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ArkWeb", "ndk OH_NativeArkWeb_RunJavaScript webName:%{public}s",
                 webNameValue);

    // Obtain the second parameter jsCode.
    size_t bufferSize = 0;
    napi_get_value_string_utf8(env, args[1], nullptr, 0, &bufferSize);
    char *jsCode = new (std::nothrow) char[bufferSize + 1];
    size_t byteLength = 0;
    napi_get_value_string_utf8(env, args[1], jsCode, bufferSize + 1, &byteLength);

    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ArkWeb",
                 "ndk OH_NativeArkWeb_RunJavaScript jsCode len:%{public}d", strlen(jsCode));

    start = std::chrono::high_resolution_clock::now();

    // Call the native API.
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
