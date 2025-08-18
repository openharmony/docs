# native_interface_arkweb.h
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @yp99ustc; @aohui; @zourongchun-->
<!--Designer: @LongLie; @yaomingliu; @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

## 概述

声明API接口供开发者使用注入对象和执行JavaScript代码等功能。

**库：** libohweb.so

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11

**相关模块：** [Web](capi-web.md)

## 汇总

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*NativeArkWeb_OnJavaScriptCallback)(const char*)](#nativearkweb_onjavascriptcallback) | NativeArkWeb_OnJavaScriptCallback | 定义执行JavaScript代码后返回结果的回调函数的类型。 |
| [typedef char* (\*NativeArkWeb_OnJavaScriptProxyCallback)(const char** argv, int32_t argc)](#nativearkweb_onjavascriptproxycallback) | NativeArkWeb_OnJavaScriptProxyCallback | 定义注入对象的回调函数的类型。 |
| [typedef void (\*NativeArkWeb_OnValidCallback)(const char*)](#nativearkweb_onvalidcallback) | NativeArkWeb_OnValidCallback | 定义Web组件可用时的回调函数的类型。 |
| [typedef void (\*NativeArkWeb_OnDestroyCallback)(const char*)](#nativearkweb_ondestroycallback) | NativeArkWeb_OnDestroyCallback | 定义Web组件销毁时的回调函数的类型。 |
| [typedef void (\*OH_ArkWeb_OnCookieSaveCallback)(ArkWeb_ErrorCode errorCode)](#oh_arkweb_oncookiesavecallback) | OH_ArkWeb_OnCookieSaveCallback | 定义保存cookie的回调函数的类型。<br>**起始版本：** 20 |
| [typedef ArkWeb_BlanklessInfo](#arkweb_blanklessinfo) | ArkWeb_BlanklessInfo | 页面首屏加载预测信息，主要包括首屏相似度预测值，首屏加载耗时预测值，预测错误码，应用需根据此信息来决策是否启用无白屏加载插帧方案。 |
| [void OH_NativeArkWeb_RunJavaScript(const char* webTag, const char* jsCode, NativeArkWeb_OnJavaScriptCallback callback)](#oh_nativearkweb_runjavascript) | - | 在当前显示页面的环境下，加载并异步执行一段JavaScript代码。 |
| [void OH_NativeArkWeb_RegisterJavaScriptProxy(const char* webTag, const char* objName, const char** methodList,NativeArkWeb_OnJavaScriptProxyCallback* callback, int32_t size, bool needRefresh)](#oh_nativearkweb_registerjavascriptproxy) | - | 注册对象及函数名称列表。 |
| [void OH_NativeArkWeb_UnregisterJavaScriptProxy(const char* webTag, const char* objName)](#oh_nativearkweb_unregisterjavascriptproxy) | - | 删除已注册的对象及其下的回调函数。 |
| [void OH_NativeArkWeb_SetJavaScriptProxyValidCallback(const char* webTag, NativeArkWeb_OnValidCallback callback)](#oh_nativearkweb_setjavascriptproxyvalidcallback) | - | 设置对象可注册时的回调函数。 |
| [NativeArkWeb_OnValidCallback OH_NativeArkWeb_GetJavaScriptProxyValidCallback(const char* webTag)](#oh_nativearkweb_getjavascriptproxyvalidcallback) | - | 获取已注册的对象可注册时的回调函数。 |
| [void OH_NativeArkWeb_SetDestroyCallback(const char* webTag, NativeArkWeb_OnDestroyCallback callback)](#oh_nativearkweb_setdestroycallback) | - | 设置组件销毁时的回调函数。 |
| [NativeArkWeb_OnDestroyCallback OH_NativeArkWeb_GetDestroyCallback(const char* webTag)](#oh_nativearkweb_getdestroycallback) | - | 获取已注册的组件销毁时的回调函数。 |
| [ArkWeb_ErrorCode OH_NativeArkWeb_LoadData(const char* webTag,const char* data,const char* mimeType,const char* encoding,const char* baseUrl,const char* historyUrl)](#oh_nativearkweb_loaddata) | - | 加载数据或URL，此函数应在主线程中调用。 |
| [void OH_NativeArkWeb_RegisterAsyncThreadJavaScriptProxy(const char* webTag,const ArkWeb_ProxyObjectWithResult* proxyObject, const char* permission)](#oh_nativearkweb_registerasyncthreadjavascriptproxy) | - | 注册一个包含回调方法的 JavaScript 对象，这些方法可带有返回值。该对象将被注入到当前页面的所有frame中，包括所有的 iframe，并且可以通过在 ArkWeb_ProxyObjectWithResult 中指定的名称进行访问。该对象只会在下一次加载或重新加载页面后在 JavaScript 中生效。这些方法将在 ArkWeb 的工作线程中执行。 |
| [ArkWeb_ErrorCode OH_ArkWebCookieManager_SaveCookieSync()](#oh_arkwebcookiemanager_savecookiesync) | - | 将当前可通过CookieManager API访问的所有Cookie持久化到磁盘。如果要在非UI线程中使用此接口，则需要先使用OH_ArkWeb_GetNativeAPI初始化CookieManager接口。<br>**起始版本：** 20 |
| [void OH_ArkWebCookieManager_SaveCookieAsync(OH_ArkWeb_OnCookieSaveCallback callback)](#oh_arkwebcookiemanager_savecookieasync) | - | 将当前可通过CookieManager API访问的所有Cookie持久化到磁盘。在不初始化CookieManager接口的情况下，此接口将在UI线程上自动执行。<br>**起始版本：** 20 |
| [ArkWeb_BlanklessInfo OH_NativeArkWeb_GetBlanklessInfoWithKey(const char* webTag, const char* key)](#oh_nativearkweb_getblanklessinfowithkey) | - | 获取页面首屏加载预测信息（详细说明见[ArkWeb_BlanklessInfo](#arkweb_blanklessinfo)），并开始本次加载过渡帧生成，应用根据此信息确定是否需要启用无白屏加载。必须与[OH_NativeArkWeb_SetBlanklessLoadingWithKey](#oh_nativearkweb_setblanklessloadingwithkey)接口配套使用，并且必须在触发加载页面的接口之前调用。需在WebViewController与Web组件绑定后才能使用。 |
| [ArkWeb_BlanklessErrorCode OH_NativeArkWeb_SetBlanklessLoadingWithKey(const char* webTag, const char* key, bool isStarted)](#oh_nativearkweb_setblanklessloadingwithkey) | - | 设置无白屏加载是否启用。本接口必须与[OH_NativeArkWeb_GetBlanklessInfoWithKey](#oh_nativearkweb_getblanklessinfowithkey)接口配套使用。 |
| [void OH_NativeArkWeb_ClearBlanklessLoadingCache(const char* key[], uint32_t size)](#oh_nativearkweb_clearblanklessloadingcache) | - | 清除指定key值页面无白屏优化缓存，本接口只清除缓存。 |
| [uint32_t OH_NativeArkWeb_SetBlanklessLoadingCacheCapacity(uint32_t capacity)](#oh_nativearkweb_setblanklessloadingcachecapacity) | - | 设置无白屏加载方案的持久化缓存容量，返回实际生效值。默认缓存容量为30MB，最大值为100MB。当实际缓存超过容量时，将采用淘汰不常用的过渡帧的方式清理。 |

## 函数说明

### NativeArkWeb_OnJavaScriptCallback()

```
typedef void (*NativeArkWeb_OnJavaScriptCallback)(const char*)
```

**描述：**

定义执行JavaScript代码后返回结果的回调函数的类型。

**起始版本：** 11

### NativeArkWeb_OnJavaScriptProxyCallback()

```
typedef char* (*NativeArkWeb_OnJavaScriptProxyCallback)(const char** argv, int32_t argc)
```

**描述：**

定义注入对象的回调函数的类型。

**起始版本：** 11

### NativeArkWeb_OnValidCallback()

```
typedef void (*NativeArkWeb_OnValidCallback)(const char*)
```

**描述：**

定义Web组件可用时的回调函数的类型。

**起始版本：** 11

### NativeArkWeb_OnDestroyCallback()

```
typedef void (*NativeArkWeb_OnDestroyCallback)(const char*)
```

**描述：**

定义Web组件销毁时的回调函数的类型。

**起始版本：** 11

### OH_ArkWeb_OnCookieSaveCallback()

```
typedef void (*OH_ArkWeb_OnCookieSaveCallback)(ArkWeb_ErrorCode errorCode)
```

**描述：**

定义保存cookie的回调函数的类型。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkWeb_ErrorCode](capi-arkweb-error-code-h.md#arkweb_errorcode) errorCode | [ARKWEB_SUCCESS](capi-arkweb-error-code-h.md#arkweb_errorcode) 保存cookie成功。<br> [ARKWEB_COOKIE_SAVE_FAILED](capi-arkweb-error-code-h.md#arkweb_errorcode) 保存cookie失败。<br> [ARKWEB_COOKIE_MANAGER_INITIALIZE_FAILED](capi-arkweb-error-code-h.md#arkweb_errorcode) CookieManager初始化失败。 |

### ArkWeb_BlanklessInfo()

## 概述

页面首屏加载预测信息，主要包括首屏相似度预测值，首屏加载耗时预测值，预测错误码，应用需根据此信息来决策是否启用无白屏加载插帧方案。

**起始版本：** 20

### 成员变量

| 名称 | 描述 |
| -- | -- |
| ArkWeb_BlanklessErrorCode errCode | 无白屏加载的异常错误码，见[ArkWeb_BlanklessErrorCode](./capi-arkweb-error-code-h.md#arkweb_blanklesserrorcode)定义。 |
| double similarity | 首屏相似度，根据历史加载首屏内容计算相似度，范围为0~1.0，1.0表示完全一致，数值越接近1，相似度越高。该值存在滞后性，本地加载的相似性将在下次加载时才可反映。建议当相似度较低时，应用不启用无白屏加载插帧方案。 |
| int32_t loadingTime | 根据历史加载首屏耗时预测本次加载耗时，单位ms，取值范围需大于0。 |

### OH_NativeArkWeb_RunJavaScript()

```
void OH_NativeArkWeb_RunJavaScript(const char* webTag, const char* jsCode, NativeArkWeb_OnJavaScriptCallback callback)
```

**描述：**

在当前显示页面的环境下，加载并异步执行一段JavaScript代码。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件的名称。 |
| const char* jsCode | 一段JavaScript的代码脚本。 |
| [NativeArkWeb_OnJavaScriptCallback](#nativearkweb_onjavascriptcallback) callback | 代码执行完后通知开发者结果的回调函数。 |

### OH_NativeArkWeb_RegisterJavaScriptProxy()

```
void OH_NativeArkWeb_RegisterJavaScriptProxy(const char* webTag, const char* objName, const char** methodList,NativeArkWeb_OnJavaScriptProxyCallback* callback, int32_t size, bool needRefresh)
```

**描述：**

注册对象及函数名称列表。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件的名称。 |
| const char* objName | 注入对象的名称。 |
| const char** methodList | 注入函数列表的名称。 |
| [NativeArkWeb_OnJavaScriptProxyCallback](#nativearkweb_onjavascriptproxycallback)* callback | 注入的回调函数。 |
| int32_t size | 注入的回调函数的个数。 |
| bool needRefresh | 是否需要刷新页面。 |

### OH_NativeArkWeb_UnregisterJavaScriptProxy()

```
void OH_NativeArkWeb_UnregisterJavaScriptProxy(const char* webTag, const char* objName)
```

**描述：**

删除已注册的对象及其下的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件的名称。 |
| const char* objName | 注入对象的名称。 |

### OH_NativeArkWeb_SetJavaScriptProxyValidCallback()

```
void OH_NativeArkWeb_SetJavaScriptProxyValidCallback(const char* webTag, NativeArkWeb_OnValidCallback callback)
```

**描述：**

设置对象可注册时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件的名称。 |
| [NativeArkWeb_OnValidCallback](#nativearkweb_onvalidcallback) callback | 对象可注册时的回调函数。 |

### OH_NativeArkWeb_GetJavaScriptProxyValidCallback()

```
NativeArkWeb_OnValidCallback OH_NativeArkWeb_GetJavaScriptProxyValidCallback(const char* webTag)
```

**描述：**

获取已注册的对象可注册时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件的名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [NativeArkWeb_OnValidCallback](#nativearkweb_onvalidcallback) | 已注册的对象可注册时的回调函数。 |

### OH_NativeArkWeb_SetDestroyCallback()

```
void OH_NativeArkWeb_SetDestroyCallback(const char* webTag, NativeArkWeb_OnDestroyCallback callback)
```

**描述：**

设置组件销毁时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件的名称。 |
| [NativeArkWeb_OnDestroyCallback](#nativearkweb_ondestroycallback) callback | 组件销毁时的回调函数。 |

### OH_NativeArkWeb_GetDestroyCallback()

```
NativeArkWeb_OnDestroyCallback OH_NativeArkWeb_GetDestroyCallback(const char* webTag)
```

**描述：**

获取已注册的组件销毁时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件的名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [NativeArkWeb_OnDestroyCallback](#nativearkweb_ondestroycallback) | return 已注册的组件销毁时的回调函数。 |

### OH_NativeArkWeb_LoadData()

```
ArkWeb_ErrorCode OH_NativeArkWeb_LoadData(const char* webTag,const char* data,const char* mimeType,const char* encoding,const char* baseUrl,const char* historyUrl)
```

**描述：**

加载数据或URL，此函数应在主线程中调用。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件的名称。 |
| const char* data | "Base64"或"URL"编码的字符串，不能为空。 |
| const char* mimeType | 媒体类型，例如"text/html"，不能为空。 |
| const char* encoding | 编码类型，例如"UTF-8"，不能为空。 |
| const char* baseUrl | 指定的URL路径("http"/"https"/"data"协议),由Web组件分配给window.origin。 |
| const char* historyUrl | 历史URL，当它不为空时，可以通过历史记录来管理，实现前进和后退功能。 |

**返回：**

| 类型                                                               | 说明                                                                                                                                                                                                                                                                                                                         |
|------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [ArkWeb_ErrorCode](capi-arkweb-error-code-h.md#arkweb_errorcode) | LoadData 错误码。<br>         [ARKWEB_SUCCESS](capi-arkweb-error-code-h.md#arkweb_errorcode) 加载数据成功。<br>         [ARKWEB_INVALID_PARAM](capi-arkweb-error-code-h.md#arkweb_errorcode) 必填参数未指定或参数类型不正确或参数校验失败。<br>         [ARKWEB_INIT_ERROR](capi-arkweb-error-code-h.md#arkweb_errorcode) 初始化失败，根据传入的"webTag"找不到有效的Web组件。<br>         [ARKWEB_LIBRARY_OPEN_FAILURE](capi-arkweb-error-code-h.md#arkweb_errorcode) 打开动态链接库失败。<br>         [ARKWEB_LIBRARY_SYMBOL_NOT_FOUND](capi-arkweb-error-code-h.md#arkweb_errorcode) 动态链接库中未找到所需的符号。 |

### OH_NativeArkWeb_RegisterAsyncThreadJavaScriptProxy()

```
void OH_NativeArkWeb_RegisterAsyncThreadJavaScriptProxy(const char* webTag,const ArkWeb_ProxyObjectWithResult* proxyObject, const char* permission)
```

**描述：**

注册一个包含回调方法的 JavaScript 对象，这些方法可带有返回值。该对象将被注入到当前页面的所有frame中，包括所有的 iframe，并且可以通过在 ArkWeb_ProxyObjectWithResult 中指定的名称进行访问。该对象只会在下一次加载或重新加载页面后在 JavaScript 中生效。这些方法将在 ArkWeb 的工作线程中执行。

**起始版本：** 20


**参数：**

| 参数项                                                 | 描述 |
|-----------------------------------------------------| -- |
| const char* webTag                                  | Web组件名称。 |
| const [ArkWeb_ProxyObjectWithResult](capi-web-arkweb-proxyobjectwithresult.md)* proxyObject | 注册的对象。 |
| const char* permission                              | json格式字符串，默认值为空。该字符串用来配置JSBridge的权限限制，可以配置对象和方法级别。 |

### OH_ArkWebCookieManager_SaveCookieSync()

```
ArkWeb_ErrorCode OH_ArkWebCookieManager_SaveCookieSync()
```

**描述：**

将当前可通过CookieManager API访问的所有Cookie持久化到磁盘。如果要在非UI线程中使用此接口，则需要先使用OH_ArkWeb_GetNativeAPI初始化CookieManager接口。

**起始版本：** 20

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkWeb_ErrorCode](capi-arkweb-error-code-h.md#arkweb_errorcode) | SaveCookieSync错误码。<br> [ARKWEB_SUCCESS](capi-arkweb-error-code-h.md#arkweb_errorcode) 保存cookie成功。<br> [ARKWEB_COOKIE_SAVE_FAILED](capi-arkweb-error-code-h.md#arkweb_errorcode) 保存cookie失败。<br> [ARKWEB_COOKIE_MANAGER_INITIALIZE_FAILED](capi-arkweb-error-code-h.md#arkweb_errorcode) CookieManager初始化失败。<br> [ARKWEB_COOKIE_MANAGER_NOT_INITIALIZED](capi-arkweb-error-code-h.md#arkweb_errorcode) 在非UI线程中，不允许在不初始化CookieManager接口的情况下调用该接口。请先使用OH_ArkWeb_GetNativeAPI初始化CookieManager接口。 |

### OH_ArkWebCookieManager_SaveCookieAsync()

```
void OH_ArkWebCookieManager_SaveCookieAsync(OH_ArkWeb_OnCookieSaveCallback callback)
```

**描述：**

将当前可通过CookieManager API访问的所有Cookie持久化到磁盘。在不初始化CookieManager接口的情况下，此接口将在UI线程上自动执行。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkWeb_OnCookieSaveCallback](#oh_arkweb_oncookiesavecallback)* callback | 保存cookie完成后执行该回调。 |
### OH_NativeArkWeb_GetBlanklessInfoWithKey()

```
ArkWeb_BlanklessInfo OH_NativeArkWeb_GetBlanklessInfoWithKey(const char* webTag, const char* key)
```

**描述：**

获取页面首屏加载预测信息（详细说明见[ArkWeb_BlanklessInfo](#arkweb_blanklessinfo)），并开始本次加载过渡帧生成，应用根据此信息确定是否需要启用无白屏加载。必须与[OH_NativeArkWeb_SetBlanklessLoadingWithKey](#oh_nativearkweb_setblanklessloadingwithkey)接口配套使用，并且必须在触发加载页面的接口之前调用。需在WebViewController与Web组件绑定后才能使用。

> **说明：**
>
> - 当前仅支持手机设备。
> - 持久缓存容量：默认大小为30MB（约30页），可以通过接口[OH_NativeArkWeb_SetBlanklessLoadingCacheCapacity](#oh_nativearkweb_setblanklessloadingcachecapacity)设置缓存容量，具体见该接口说明。超过容量时根据LRU（Least Recently Used，淘汰不常用缓存的策略）机制更新缓存。自动清理超过7天的持久缓存数据，缓存清除后第三次加载页面开始有优化效果。
> - 如果发现相似度（即[ArkWeb_BlanklessInfo](#arkweb_blanklessinfo)中的similarity）极低，请检查key值是否正确传递。
> - 调用本接口后，会启用页面加载快照检测及生成过渡帧计算，产生一定资源开销。
> - 启用无白屏加载的页面会带来一定的资源开销，开销的大小与Web组件的分辨率相关。假设分辨率的宽度和高度分别为：w, h。页面在打开阶段会增加峰值内存，增加量约为12*w*h B。页面打开后，内存会被回收，不影响稳态内存。增加固态应用缓存的大小，每个页面增加的缓存约w*h/10 B，缓存位于应用缓存的位置。

**起始版本：** 20

**参数：**

| 参数项                                                 | 描述 |
|-----------------------------------------------------| -- |
| const char* webTag  | Web组件名称。 |
| const char* key | 唯一标识本页面的key值。<br>合法取值范围：非空，长度不超过2048个字符。<br>设置非法值时不生效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkWeb_BlanklessInfo](#arkweb_blanklessinfo) | 页面首屏加载预测信息，主要包括首屏相似度预测值，首屏加载耗时预测值，应用需根据此信息来决策是否启用无白屏加载插帧。 |

### OH_NativeArkWeb_SetBlanklessLoadingWithKey()

```
ArkWeb_BlanklessErrorCode OH_NativeArkWeb_SetBlanklessLoadingWithKey(const char* webTag, const char* key, bool isStarted)
```

**描述：**

设置无白屏加载是否启用。本接口必须与[OH_NativeArkWeb_GetBlanklessInfoWithKey](#oh_nativearkweb_getblanklessinfowithkey)接口配套使用。

> **说明：**
>
> - 需在触发页面加载的接口之后调用。其他约束同[OH_NativeArkWeb_GetBlanklessInfoWithKey](#oh_nativearkweb_getblanklessinfowithkey)。
> - 页面的加载必须在调用本套接口的组件中进行。
> - 当相似度较低时，系统将判定为跳变过大，启用插帧会失败。

**起始版本：** 20

**参数：**

| 参数项                                                 | 描述 |
|-----------------------------------------------------| -- |
| const char* webTag  | Web组件名称。 |
| const char* key | 唯一标识本页面的key值。必须与[OH_NativeArkWeb_GetBlanklessInfoWithKey](#oh_nativearkweb_getblanklessinfowithkey)接口的key值相同。<br>合法取值范围：非空，长度不超过2048个字符。<br>非法值设置行为：返回错误码[ArkWeb_BlanklessErrorCode](./capi-arkweb-error-code-h.md#arkweb_blanklesserrorcode)，插帧不生效。 |
| bool isStarted | 是否启用开始插帧，true：启用，false：不启用。<br>默认值：false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkWeb_BlanklessErrorCode](./capi-arkweb-error-code-h.md#arkweb_blanklesserrorcode) | 返回接口调用是否成功，具体见[ArkWeb_BlanklessErrorCode](./capi-arkweb-error-code-h.md#arkweb_blanklesserrorcode)定义。 |

### OH_NativeArkWeb_ClearBlanklessLoadingCache()

```
void OH_NativeArkWeb_ClearBlanklessLoadingCache(const char* key[], uint32_t size)
```

**描述：**

清除指定key值页面无白屏优化缓存，本接口只清除缓存。

在小程序或Web应用场景中，当页面加载时内容变化显著，可能会出现一次明显的跳变。若对此跳变有所顾虑，可使用该接口清除页面缓存。

> **说明：**
>
> - 清除之后的页面，需在第三次加载页面时才会产生优化效果。

**起始版本：** 20

**参数：**

| 参数项                                                 | 描述 |
|-----------------------------------------------------| -- |
| const char* key[] | 清除Blankless优化方案页面的key值列表，key值为[OH_NativeArkWeb_GetBlanklessInfoWithKey](#oh_nativearkweb_getblanklessinfowithkey)中指定过的。<br>默认值：所有Blankless优化方案缓存的页面key列表。<br>合法取值范围：长度不超过2048，key列表长度<=100。key和加载页面时输入给ArkWeb的相同。<br>非法值设置行为：key长度超过2048时该key不生效；长度超过100时，取前100个；当为NULL时，使用默认值。 |
| uint32_t size | keys数组的大小。<br>默认值：0。<br>合法取值范围：0~100。<br>非法值设置行为：0。 |


### OH_NativeArkWeb_SetBlanklessLoadingCacheCapacity()

```
uint32_t OH_NativeArkWeb_SetBlanklessLoadingCacheCapacity(uint32_t capacity)
```

**描述：**

设置无白屏加载方案的持久化缓存容量，返回实际生效值。默认缓存容量为30MB，最大值为100MB。当实际缓存超过容量时，将采用淘汰不常用的过渡帧的方式清理。

**起始版本：** 20

**参数：**

| 参数项                                                 | 描述 |
|-----------------------------------------------------| -- |
| uint32_t capacity  | 设置持久化缓存设置，单位MB，最大设置不超过100MB。<br>默认值：30MB。<br>合法取值范围：0~100，当设置为0时，无缓存空间，则功能全局不开启。<br>非法值设置行为：小于0时生效值为0，大于100时生效值为100。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 返回实际生效的容量值，范围0~100。<br>小于0时生效值为0，大于100时生效值为100。 |