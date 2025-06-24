# native_interface_arkweb.h

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
| [void OH_NativeArkWeb_RunJavaScript(const char* webTag, const char* jsCode, NativeArkWeb_OnJavaScriptCallback callback)](#oh_nativearkweb_runjavascript) | - | 在当前显示页面的环境下，加载并异步执行一段JavaScript代码。 |
| [void OH_NativeArkWeb_RegisterJavaScriptProxy(const char* webTag, const char* objName, const char** methodList,NativeArkWeb_OnJavaScriptProxyCallback* callback, int32_t size, bool needRefresh)](#oh_nativearkweb_registerjavascriptproxy) | - | 注册对象及函数名称列表。 |
| [void OH_NativeArkWeb_UnregisterJavaScriptProxy(const char* webTag, const char* objName)](#oh_nativearkweb_unregisterjavascriptproxy) | - | 删除已注册的对象及其下的回调函数。 |
| [void OH_NativeArkWeb_SetJavaScriptProxyValidCallback(const char* webTag, NativeArkWeb_OnValidCallback callback)](#oh_nativearkweb_setjavascriptproxyvalidcallback) | - | 设置对象可注册时的回调函数。 |
| [NativeArkWeb_OnValidCallback OH_NativeArkWeb_GetJavaScriptProxyValidCallback(const char* webTag)](#oh_nativearkweb_getjavascriptproxyvalidcallback) | - | 获取已注册的对象可注册时的回调函数。 |
| [void OH_NativeArkWeb_SetDestroyCallback(const char* webTag, NativeArkWeb_OnDestroyCallback callback)](#oh_nativearkweb_setdestroycallback) | - | 设置组件销毁时的回调函数。 |
| [NativeArkWeb_OnDestroyCallback OH_NativeArkWeb_GetDestroyCallback(const char* webTag)](#oh_nativearkweb_getdestroycallback) | - | 获取已注册的组件销毁时的回调函数。 |
| [ArkWeb_ErrorCode OH_NativeArkWeb_LoadData(const char* webTag,const char* data,const char* mimeType,const char* encoding,const char* baseUrl,const char* historyUrl)](#oh_nativearkweb_loaddata) | - | 加载数据或URL，此函数应在主线程中调用。 |
| [void OH_NativeArkWeb_RegisterAsyncThreadJavaScriptProxy(const char* webTag,const ArkWeb_ProxyObjectWithResult* proxyObject, const char* permission)](#oh_nativearkweb_registerasyncthreadjavascriptproxy) | - | 注册一个包含回调方法的 JavaScript 对象，这些方法可带有返回值。该对象将被注入到当前页面的所有frame中，包括所有的 iframe，并且可以通过在 ArkWeb_ProxyObjectWithResult 中指定的名称进行访问。该对象只会在下一次加载或重新加载页面后在 JavaScript 中生效。这些方法将在 ArkWeb 的工作线程中执行。 |

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


