# native_interface_arkweb.h

## Overview

Declares APIs used to register objects and execute JavaScript code.

**Library**: libohweb.so

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 11

**Related module**: [Web](capi-web.md)

## Summary

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*NativeArkWeb_OnJavaScriptCallback)(const char*)](#nativearkweb_onjavascriptcallback) | NativeArkWeb_OnJavaScriptCallback | Called to return the result after the JavaScript code is executed.|
| [typedef char* (\*NativeArkWeb_OnJavaScriptProxyCallback)(const char** argv, int32_t argc)](#nativearkweb_onjavascriptproxycallback) | NativeArkWeb_OnJavaScriptProxyCallback | Called when a JavaScript proxy is registered.|
| [typedef void (\*NativeArkWeb_OnValidCallback)(const char*)](#nativearkweb_onvalidcallback) | NativeArkWeb_OnValidCallback | Called when a **Web** component is valid.|
| [typedef void (\*NativeArkWeb_OnDestroyCallback)(const char*)](#nativearkweb_ondestroycallback) | NativeArkWeb_OnDestroyCallback | Called when a **Web** component is destroyed.|
| [typedef void (\*OH_ArkWeb_OnCookieSaveCallback)()](#oh_arkweb_oncookiesavecallback) | OH_ArkWeb_OnCookieSaveCallback | Called when a cookie is saved.<br>**Since**: 20|
| [typedef ArkWeb_BlanklessInfo](#arkweb_blanklessinfo) | ArkWeb_BlanklessInfo | Prediction information about blankless loading, including the first screen similarity, first screen loading duration, and error code. The application determines whether to enable frame insertion for blankless loading based on the prediction information.|
| [void OH_NativeArkWeb_RunJavaScript(const char* webTag, const char* jsCode, NativeArkWeb_OnJavaScriptCallback callback)](#oh_nativearkweb_runjavascript) | - | Loads and asynchronously executes a JavaScript code in the current page.|
| [void OH_NativeArkWeb_RegisterJavaScriptProxy(const char* webTag, const char* objName, const char** methodList,NativeArkWeb_OnJavaScriptProxyCallback* callback, int32_t size, bool needRefresh)](#oh_nativearkweb_registerjavascriptproxy) | - | Displays the list of registered objects and function names.|
| [void OH_NativeArkWeb_UnregisterJavaScriptProxy(const char* webTag, const char* objName)](#oh_nativearkweb_unregisterjavascriptproxy) | - | Deletes a registered object and its callback.|
| [void OH_NativeArkWeb_SetJavaScriptProxyValidCallback(const char* webTag, NativeArkWeb_OnValidCallback callback)](#oh_nativearkweb_setjavascriptproxyvalidcallback) | - | Sets a callback used when an object is valid.|
| [NativeArkWeb_OnValidCallback OH_NativeArkWeb_GetJavaScriptProxyValidCallback(const char* webTag)](#oh_nativearkweb_getjavascriptproxyvalidcallback) | - | Obtains the callback used when a registered object is valid.|
| [void OH_NativeArkWeb_SetDestroyCallback(const char* webTag, NativeArkWeb_OnDestroyCallback callback)](#oh_nativearkweb_setdestroycallback) | - | Sets a callback used when a component is destroyed.|
| [NativeArkWeb_OnDestroyCallback OH_NativeArkWeb_GetDestroyCallback(const char* webTag)](#oh_nativearkweb_getdestroycallback) | - | Obtains the callback used when a registered component is destroyed.|
| [ArkWeb_ErrorCode OH_NativeArkWeb_LoadData(const char* webTag,const char* data,const char* mimeType,const char* encoding,const char* baseUrl,const char* historyUrl)](#oh_nativearkweb_loaddata) | - | Loads data or URLs. This function must be called in the main thread.|
| [void OH_NativeArkWeb_RegisterAsyncThreadJavaScriptProxy(const char* webTag,const ArkWeb_ProxyObjectWithResult* proxyObject, const char* permission)](#oh_nativearkweb_registerasyncthreadjavascriptproxy) | - | Registers a JavaScript object that contains callback methods, which can have return values. This object will be registered into all frames of the current page, including all iframes, and can be accessed by using the name specified in **ArkWeb_ProxyObjectWithResult**. The object takes effect in JavaScript only after the page is loaded or reloaded next time. Its methods are executed in the worker thread of ArkWeb.|
| [ArkWeb_ErrorCode OH_ArkWebCookieManager_SaveCookieSync()](#oh_arkwebcookiemanager_savecookiesync) | - | Saves all cookies that can be accessed through the **CookieManager** API to disks. To use this API in a non-UI thread, you need to use **OH_ArkWeb_GetNativeAPI** to initialize the **CookieManager** API.<br>**Since**: 20|
| [void OH_ArkWebCookieManager_SaveCookieAsync(OH_ArkWeb_OnCookieSaveCallback callback)](#oh_arkwebcookiemanager_savecookieasync) | - | Saves all cookies that can be accessed through the **CookieManager** API to disks. If the **CookieManager** API is not initialized, this API is automatically executed on the UI thread.<br>**Since**: 20|
| [ArkWeb_BlanklessInfo OH_NativeArkWeb_GetBlanklessInfoWithKey(const char* webTag, const char* key)](#oh_nativearkweb_getblanklessinfowithkey) | - | Obtains the first screen loading prediction information, and starts to generate the loading transition frame. The application determines whether to enable blankless loading based on the information. For details, see [ArkWeb_BlanklessInfo](#arkweb_blanklessinfo). This API must be used together with the [OH_NativeArkWeb_SetBlanklessLoadingWithKey](#oh_nativearkweb_setblanklessloadingwithkey) API and must be called before the page loading API is triggered and after **WebViewController** is bound to the **Web** component.|
| [ArkWeb_BlanklessErrorCode OH_NativeArkWeb_SetBlanklessLoadingWithKey(const char* webTag, const char* key, bool isStarted)](#oh_nativearkweb_setblanklessloadingwithkey) | - | Sets whether to enable blankless loading. This API must be used together with the [OH_NativeArkWeb_GetBlanklessInfoWithKey](#oh_nativearkweb_getblanklessinfowithkey) API.|
| [void OH_NativeArkWeb_ClearBlanklessLoadingCache(const char* key[], uint32_t size)](#oh_nativearkweb_clearblanklessloadingcache) | - | Clears the blankless loading cache of the page with a specified key value.|
| [uint32_t OH_NativeArkWeb_SetBlanklessLoadingCacheCapacity(uint32_t capacity)](#oh_nativearkweb_setblanklessloadingcachecapacity) | - | Sets the persistent cache capacity of the blankless loading solution and returns the value that takes effect. The default cache capacity is 30 MB, and the maximum cache capacity is 100 MB. When this limit is exceeded, transition frames that are not frequently used are eliminated.|

## Function Description

### NativeArkWeb_OnJavaScriptCallback()

```
typedef void (*NativeArkWeb_OnJavaScriptCallback)(const char*)
```

**Description**

Called to return the result after the JavaScript code is executed.

**Since**: 11

### NativeArkWeb_OnJavaScriptProxyCallback()

```
typedef char* (*NativeArkWeb_OnJavaScriptProxyCallback)(const char** argv, int32_t argc)
```

**Description**

Called when a JavaScript proxy is registered.

**Since**: 11

### NativeArkWeb_OnValidCallback()

```
typedef void (*NativeArkWeb_OnValidCallback)(const char*)
```

**Description**

Called when a **Web** component is valid.

**Since**: 11

### NativeArkWeb_OnDestroyCallback()

```
typedef void (*NativeArkWeb_OnDestroyCallback)(const char*)
```

**Description**

Called when a **Web** component is destroyed.

**Since**: 11

### OH_ArkWeb_OnCookieSaveCallback()

```
typedef void (*OH_ArkWeb_OnCookieSaveCallback)()
```

**Description**

Called when a cookie is saved.

**Since**: 20

### ArkWeb_BlanklessInfo()

## Overview

Prediction information about blankless loading, including the first screen similarity, first screen loading duration, and error code. The application determines whether to enable frame insertion for blankless loading based on the prediction information.

**Since**: 20

### Member Variables

| Name| Description|
| -- | -- |
| ArkWeb_BlanklessErrorCode errCode | Error codes of blankless loading. For details, see [ArkWeb_BlanklessErrorCode](./capi-arkweb-error-code-h.md#arkweb_blanklesserrorcode).|
| double similarity | First screen similarity, which is calculated based on the historical first screen content. The value ranges from 0 to 1.0. 1.0 indicates that the content is the same. A value closer to 1 indicates a higher similarity. This value is lagging, and the similarity of local loading is displayed in the next loading. You are advised not to enable the blankless loading solution when the similarity is low.|
| int32_t loadingTime | Loading duration estimated based on the historical first screen loading durations, in milliseconds. The value must be greater than 0.|

### OH_NativeArkWeb_RunJavaScript()

```
void OH_NativeArkWeb_RunJavaScript(const char* webTag, const char* jsCode, NativeArkWeb_OnJavaScriptCallback callback)
```

**Description**

Loads and asynchronously executes a JavaScript code in the current page.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.|
| const char* jsCode | A piece of JavaScript code script.|
| [NativeArkWeb_OnJavaScriptCallback](#nativearkweb_onjavascriptcallback) callback | Callback for notifying the code execution result.|

### OH_NativeArkWeb_RegisterJavaScriptProxy()

```
void OH_NativeArkWeb_RegisterJavaScriptProxy(const char* webTag, const char* objName, const char** methodList,NativeArkWeb_OnJavaScriptProxyCallback* callback, int32_t size, bool needRefresh)
```

**Description**

Displays the list of registered objects and function names.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.|
| const char* objName | Name of the registered object.|
| const char** methodList | Name of the registered method list.|
| [NativeArkWeb_OnJavaScriptProxyCallback](#nativearkweb_onjavascriptproxycallback)* callback | Registered callback.|
| int32_t size | Number of registered callbacks.|
| bool needRefresh | Whether a page need to be refreshed.|

### OH_NativeArkWeb_UnregisterJavaScriptProxy()

```
void OH_NativeArkWeb_UnregisterJavaScriptProxy(const char* webTag, const char* objName)
```

**Description**

Deletes a registered object and its callback.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.|
| const char* objName | Name of the registered object.|

### OH_NativeArkWeb_SetJavaScriptProxyValidCallback()

```
void OH_NativeArkWeb_SetJavaScriptProxyValidCallback(const char* webTag, NativeArkWeb_OnValidCallback callback)
```

**Description**

Sets a callback used when an object is valid.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.|
| [NativeArkWeb_OnValidCallback](#nativearkweb_onvalidcallback) callback | Callback used when an object is valid.|

### OH_NativeArkWeb_GetJavaScriptProxyValidCallback()

```
NativeArkWeb_OnValidCallback OH_NativeArkWeb_GetJavaScriptProxyValidCallback(const char* webTag)
```

**Description**

Obtains the callback used when a registered object is valid.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.|

**Returns**

| Type| Description|
| -- | -- |
| [NativeArkWeb_OnValidCallback](#nativearkweb_onvalidcallback) | Callback used when a registered object is valid.|

### OH_NativeArkWeb_SetDestroyCallback()

```
void OH_NativeArkWeb_SetDestroyCallback(const char* webTag, NativeArkWeb_OnDestroyCallback callback)
```

**Description**

Sets a callback used when a component is destroyed.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.|
| [NativeArkWeb_OnDestroyCallback](#nativearkweb_ondestroycallback) callback | Callback used when a component is destroyed.|

### OH_NativeArkWeb_GetDestroyCallback()

```
NativeArkWeb_OnDestroyCallback OH_NativeArkWeb_GetDestroyCallback(const char* webTag)
```

**Description**

Obtains the callback used when a registered component is destroyed.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.|

**Returns**

| Type| Description|
| -- | -- |
| [NativeArkWeb_OnDestroyCallback](#nativearkweb_ondestroycallback) | Callback used when a registered component is destroyed.|

### OH_NativeArkWeb_LoadData()

```
ArkWeb_ErrorCode OH_NativeArkWeb_LoadData(const char* webTag,const char* data,const char* mimeType,const char* encoding,const char* baseUrl,const char* historyUrl)
```

**Description**

Loads data or URLs. This function must be called in the main thread.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.|
| const char* data | String being base64 or URL encoded, which cannot be empty.|
| const char* mimeType | Media type, such as **text/html**, which cannot be empty.|
| const char* encoding | Encoding type, such as **UTF-8**, which cannot be empty.|
| const char* baseUrl | URL (HTTP/HTTPS/Data), which is assigned by the **Web** component to **window.origin**.|
| const char* historyUrl | Historical URL. If this parameter is not empty, it can be managed in historical records to implement backward and forward navigation.|

**Returns**

| Type                                                              | Description                                                                                                                                                                                                                                                                                                                        |
|------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [ArkWeb_ErrorCode](capi-arkweb-error-code-h.md#arkweb_errorcode) | Error codes of **LoadData**.<br>         [ARKWEB_SUCCESS](capi-arkweb-error-code-h.md#arkweb_errorcode): The data is successfully loaded.<br>         [ARKWEB_INVALID_PARAM](capi-arkweb-error-code-h.md#arkweb_errorcode): The mandatory parameter is not specified, the parameter type is incorrect, or the parameter verification fails.<br>         [ARKWEB_INIT_ERROR](capi-arkweb-error-code-h.md#arkweb_errorcode): The initialization failed because no valid **Web** component is found based on the input **webTag**.<br>         [ARKWEB_LIBRARY_OPEN_FAILURE](capi-arkweb-error-code-h.md#arkweb_errorcode): Failed to open the dynamic link library.<br>         [ARKWEB_LIBRARY_SYMBOL_NOT_FOUND](capi-arkweb-error-code-h.md#arkweb_errorcode): The required symbol is not found in the dynamic link library.|

### OH_NativeArkWeb_RegisterAsyncThreadJavaScriptProxy()

```
void OH_NativeArkWeb_RegisterAsyncThreadJavaScriptProxy(const char* webTag,const ArkWeb_ProxyObjectWithResult* proxyObject, const char* permission)
```

**Description**

Registers a JavaScript object that contains callback methods, which can have return values. This object will be registered into all frames of the current page, including all iframes, and can be accessed by using the name specified in **ArkWeb_ProxyObjectWithResult**. The object takes effect in JavaScript only after the page is loaded or reloaded next time. Its methods are executed in the worker thread of ArkWeb.

**Since**: 20


**Parameters**

| Name                                                | Description|
|-----------------------------------------------------| -- |
| const char* webTag                                  | Name of the **Web** component.|
| const [ArkWeb_ProxyObjectWithResult](capi-web-arkweb-proxyobjectwithresult.md)* proxyObject | Object to be registered.|
| const char* permission                              |  A JSON string used to configure the object and method levels of the JSBridge permission. This value is empty by default.|

### OH_ArkWebCookieManager_SaveCookieSync()

```
ArkWeb_ErrorCode OH_ArkWebCookieManager_SaveCookieSync()
```

**Description**

Saves all cookies that can be accessed through the **CookieManager** API to disks. To use this API in a non-UI thread, you need to use **OH_ArkWeb_GetNativeAPI** to initialize the **CookieManager** API.

**Since**: 20

**Returns**

| Type| Description|
| -- | -- |
| [ArkWeb_ErrorCode](capi-arkweb-error-code-h.md#arkweb_errorcode) | Error codes of **SaveCookieSync**.<br> [ARKWEB_SUCCESS](capi-arkweb-error-code-h.md#arkweb_errorcode): The cookie is successfully saved.<br> [ARKWEB_COOKIE_MANAGER_NOT_INITIALIZED](capi-arkweb-error-code-h.md#arkweb_errorcode): This API cannot be invoked in a non-UI thread without initializing the **CookieManager** API. You need to use **OH_ArkWeb_GetNativeAPI** to initialize the **CookieManager** API first.|

### OH_ArkWebCookieManager_SaveCookieAsync()

```
void OH_ArkWebCookieManager_SaveCookieAsync(OH_ArkWeb_OnCookieSaveCallback callback)
```

**Description**

Saves all cookies that can be accessed through the **CookieManager** API to disks. If the **CookieManager** API is not initialized, this API is automatically executed on the UI thread.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkWeb_OnCookieSaveCallback](#oh_arkweb_oncookiesavecallback)* callback | Callback triggered when cookies are saved.|
### OH_NativeArkWeb_GetBlanklessInfoWithKey()

```
ArkWeb_BlanklessInfo OH_NativeArkWeb_GetBlanklessInfoWithKey(const char* webTag, const char* key)
```

**Description**

Obtains the first screen loading prediction information, and starts to generate the loading transition frame. The application determines whether to enable blankless loading based on the information. For details, see [ArkWeb_BlanklessInfo](#arkweb_blanklessinfo). This API must be used together with the [OH_NativeArkWeb_SetBlanklessLoadingWithKey](#oh_nativearkweb_setblanklessloadingwithkey) API and must be called before the page loading API is triggered and after **WebViewController** is bound to the **Web** component.

> **NOTE**
>
> - Currently, this feature is supported only on mobile phones.
> - The default size of the persistent cache capacity is 30 MB (about 30 pages). You can set the cache capacity by calling [OH_NativeArkWeb_SetBlanklessLoadingCacheCapacity](#oh_nativearkweb_setblanklessloadingcachecapacity). For details, see the description of this API. When the maximum capacity is exceeded, the cache is updated based on the Least Recently Used (LRU) mechanism. The persistent cache data that has been stored for more than seven days is automatically cleared. After the cache is cleared, the optimization effect appears when the page is loaded for the third time.
> - If the similarity in [ArkWeb_BlanklessInfo](#arkweb_blanklessinfo) is extremely low, check whether the key value is correctly transferred.
> - After this API is called, page loading snapshot detection and transition frame generation calculation are enabled, which generates certain resource overhead.
> - Blankless loading consumes resources, which depends on the resolution of the **Web** component. It is assumed that a width and a height of the resolution are respectively **w** and **h**. When a page is opened, the peak memory usage increases by about **12×w×h** B. After the page is opened, the memory is reclaimed, which does not affect the stable memory usage. When the size of the solid-state application cache is increased, the increased cache of each page is about **w×h/10** B and the cache is located in the application cache.

**Since**: 20

**Parameters**

| Name                                                | Description|
|-----------------------------------------------------| -- |
| const char* webTag  | Name of the **Web** component.|
| const char* key | Key value that uniquely identifies the page.<br>The value cannot be empty and can contain a maximum of 2048 characters.<br>Invalid values do not take effect.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkWeb_BlanklessInfo](#arkweb_blanklessinfo) | Prediction information about blankless loading, including the first screen similarity and first screen loading duration. The application determines whether to enable blankless loading based on the prediction information.|

### OH_NativeArkWeb_SetBlanklessLoadingWithKey()

```
ArkWeb_BlanklessErrorCode OH_NativeArkWeb_SetBlanklessLoadingWithKey(const char* webTag, const char* key, bool isStarted)
```

**Description**

Sets whether to enable blankless loading. This API must be used together with the [OH_NativeArkWeb_GetBlanklessInfoWithKey](#oh_nativearkweb_getblanklessinfowithkey) API.

> **NOTE**
>
> - This API must be called after the page loading API is triggered. Other constraints are the same as those of [OH_NativeArkWeb_GetBlanklessInfoWithKey](#oh_nativearkweb_getblanklessinfowithkey).
> - The page must be loaded in the component that calls this set of APIs.
> - When the similarity is low, the system will deem the scene change too abrupt and frame insertion will fail.

**Since**: 20

**Parameters**

| Name                                                | Description|
|-----------------------------------------------------| -- |
| const char* webTag  | Name of the **Web** component.|
| const char* key | Key value that uniquely identifies the page. The value must be the same as the key value of the [OH_NativeArkWeb_GetBlanklessInfoWithKey](#oh_nativearkweb_getblanklessinfowithkey) API.<br>The value cannot be empty and can contain a maximum of 2048 characters.<br>When an invalid value is set, the error code [ArkWeb_BlanklessErrorCode](./capi-arkweb-error-code-h.md#arkweb_blanklesserrorcode) is returned and the frame insertion does not take effect.|
| bool isStarted | Whether to enable frame insertion. The value **true** indicates to enable frame insertion, and **false** indicates the opposite.<br>The default value is **false**.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkWeb_BlanklessErrorCode](./capi-arkweb-error-code-h.md#arkweb_blanklesserrorcode) | Whether the API is successfully called. For details, see [ArkWeb_BlanklessErrorCode](./capi-arkweb-error-code-h.md#arkweb_blanklesserrorcode).|

### OH_NativeArkWeb_ClearBlanklessLoadingCache()

```
void OH_NativeArkWeb_ClearBlanklessLoadingCache(const char* key[], uint32_t size)
```

**Description**

Clears the blankless loading cache of the page with a specified key value.

In an applet or web application, when the content changes significantly during page loading, an obvious scene change may occur. If you are concerned about this change, you can use this API to clear the page cache.

> **NOTE**
>
> - After the page is cleared, the optimization effect appears when the page is loaded for the third time.

**Since**: 20

**Parameters**

| Name                                                | Description|
|-----------------------------------------------------| -- |
| const char* key[] | Key value list on the pages using the blankless optimization solution. The key value has been specified in [OH_NativeArkWeb_GetBlanklessInfoWithKey](#oh_nativearkweb_getblanklessinfowithkey).<br>Default value: key value list of all pages cached by the blankless optimization solution.<br>The key length cannot exceed 2048 characters, and the number of keys must be less than or equal to 100. The key value is the same as that input to the **Web** component during page loading.<br>If the key length exceeds 2048 characters, the key does not take effect. If the key length exceeds 100 characters, the first 100 characters are used. If the key length is NULL, the default value is used.|
| uint32_t size | Size of the key array.<br>The default value is **0**.<br>The value ranges from 0 to 100.<br>When an invalid value is set, the value **0** is used.|


### OH_NativeArkWeb_SetBlanklessLoadingCacheCapacity()

```
uint32_t OH_NativeArkWeb_SetBlanklessLoadingCacheCapacity(uint32_t capacity)
```

**Description**

Sets the persistent cache capacity of the blankless loading solution and returns the value that takes effect. The default cache capacity is 30 MB, and the maximum cache capacity is 100 MB. When this limit is exceeded, transition frames that are not frequently used are eliminated.

**Since**: 20

**Parameters**

| Name                                                | Description|
|-----------------------------------------------------| -- |
| uint32_t capacity  | Persistent cache capacity, in MB. The maximum value is 100 MB.<br>The default value is 30 MB.<br>The value ranges from 0 to 100. If this parameter is set to **0**, no cache capacity is available and the functionality is disabled globally.<br>When a value less than 0 is set, the value **0** takes effect. When a value greater than 100 is set, the value **100** takes effect.|

**Returns**

| Type| Description|
| -- | -- |
| uint32_t | The effective value that ranges from 0 MB to 100 MB.<br>When a value less than 0 is set, the value **0** takes effect. When a value greater than 100 is set, the value **100** takes effect.|
