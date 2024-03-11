# ArkWeb网络拦截


## 概述

通过ArkWeb网络拦截可以对ArkWeb发起的请求进行拦截，并构造自定义的响应头以及响应体返回给ArkWeb内核。
支持拦截ArkWeb内置的协议HTTP, HTTPS, FILE, 也支持对三方协议的拦截。

**起始版本：** 12

**相关模块：**[ArkWeb网络拦截](arkweb_scheme_handler.md)

## 汇总

### 文件

| 名称 | 描述 |
| -------- | -------- |
| [arkweb_scheme_handler.h](arkweb_scheme_handler.md) | 该文件提供了ArkWeb网络拦截的NDK接口。 |
| [arkweb_net_error_list.h](arkweb_net_error_list.md) | 该文件提供了ArkWeb的网络错误码。 |
| [arkweb_error_code.h](arkweb_error_code.md) | 该文件提供了ArkWeb NDK接口异常错误码。 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| ArkWeb_CustomSchemeOption | 三方协议的配置，指定三方协议应该遵循的规则。|
| ArkWeb_SchemeHandler | 该类用于拦截指定scheme的请求。|
| ArkWeb_ResourceHandler | 通过ArkWeb_ResourceHandler可以提供自定义的返回头以及返回体。|
| ArkWeb_Response | 请求的响应，可以为被拦截的请求创建一个ArkWeb_Response并填充自定义的内容返回给ArkWeb。|
| ArkWeb_ResourceRequest | 代表一个ArkWeb发出的请求，通过ArkWeb_ResourceRequest可以拿到该请求的信息。|
| ArkWeb_RequestHeaderList | 请求的请求头信息。|
| ArkWeb_HttpBodyStream | POST、PUT请求的数据体，支持BYTES、FILE、BLOB、CHUNKED类型的数据。|
| ArkWeb_OnRequestStart | 当请求开始时的回调，在该回调函数中可以决定是否拦截该请求，该接口会在IO线程回调。|
| ArkWeb_OnRequestStop | 当请求完成时的回调，请求完成后需要销毁ArkWeb_ResourceRequest以及ArkWeb_ResourceHandler，该接口会在IO线程回调。|
| ArkWeb_HttpBodyStreamReadCallback | OH_ArkWebHttpBodyStream_Read读取操作完成时的回调。|
| ArkWeb_HttpBodyStreamInitCallback | ArkWeb_HttpBodyStream初始化操作完成时的回调。|


### 函数

| 名称 | 描述 |
| -------- | -------- |
| OH_ArkWebRequestHeaderList_Destroy(ArkWeb_RequestHeaderList* requestHeaderList) | 销毁ArkWeb内核创建的ArkWeb_RequestHeaderList对象。|
| OH_ArkWebRequestHeaderList_GetSize(const ArkWeb_RequestHeaderList* requestHeaderList) | 获取请求的请求头列表的大小。|
| OH_ArkWebRequestHeaderList_GetHeader(const ArkWeb_RequestHeaderList* requestHeaderList, int32_t index, char** key, char** value) | 获取指定的请求头。|
| OH_ArkWebResourceRequest_SetUserData(ArkWeb_ResourceRequest* resourceRequest, void* userData) | 将一个用户数据设置到ArkWeb_ResourceRequest对象中。|
| OH_ArkWebResourceRequest_GetUserData(const ArkWeb_ResourceRequest* resourceRequest) | 从ArkWeb_ResourceRequest获取用户数据。|
| OH_ArkWebResourceRequest_GetMethod(const ArkWeb_ResourceRequest* resourceRequest, char** method) | 获取请求的方法。|
| OH_ArkWebResourceRequest_GetUrl(const ArkWeb_ResourceRequest* resourceRequest, char** url) | 获取请求的url。|
| OH_ArkWebResourceRequest_GetHttpBodyStream(const ArkWeb_ResourceRequest* resourceRequest, ArkWeb_HStream** httpBodyStream) | 获取POST、PUT请求的上传数据，该接口需要在IO线程使用。|
| OH_ArkWebResourceRequest_DestroyHttpBodyStream(ArkWeb_HttpBodyStream* httpBodyStream) | 销毁ArkWeb_HttpBodyStream对象。|
| OH_ArkWebHttpBodyStream_SetUserData(ArkWeb_HttpBodyStream* httpBodyStream, void* userData) | 将一个用户数据设置到ArkWeb_HttpBodyStream对象中。|
| OH_ArkWebHStream_GetUserData(const ArkWeb_HttpBodyStream* httpBodyStream) | 从ArkWeb_HttpBodyStream获取用户数据。|
| OH_ArkWebHttpBodyStream_SetReadCallback(ArkWeb_HttpBodyStream* httpBodyStream, ArkWeb_HttpBodyStreamReadCallback readCallback) | 为 OH_ArkWebHttpBodyStream_Read 设置回调函数，OH_ArkWebHttpBodyStream_Read 的结果将通过 readCallback 通知给调用者。该回调函数将在与OH_ArkWebHttpBodyStream_Read 相同的线程中运行。|
| OH_ArkWebHttpBodyStream_Init(ArkWeb_HttpBodyStream* httpBodyStream, ArkWeb_HttpBodyStreamInitCallback initCallback) | 初始化ArkWeb_HttpBodyStream。在调用任何其他函数之前，必须调用此函数。该接口需要在IO线程调用。|
| OH_ArkWebHttpBodyStream_Read(const ArkWeb_HttpBodyStream* httpBodyStream, uint8_t* buffer, int bufLen) | 将数据读取到缓冲区。缓冲区的大小必须大于bufLen。我们将从工作线程读取数据到缓冲区，因此在回调函数返回之前，不应在其他线程中使用缓冲区，以避免并发问题。|
| OH_ArkWebHttpBodyStream_GetSize(const ArkWeb_HttpBodyStream* httpBodyStream) | 获取 ArkWeb_HttpBodyStream 的大小，分块传输时总是返回零。|
| OH_ArkWebHttpBodyStream_GetPosition(const ArkWeb_HttpBodyStream* httpBodyStream) | 获取 ArkWeb_HttpBodyStream 当前的读取位置。|
| OH_ArkWebHttpBodyStream_IsChunked(const ArkWeb_HttpBodyStream* httpBodyStream) | 获取 ArkWeb_HttpBodyStream 是否采用分块传输。|
| OH_ArkWebHttpBodyStream_IsEof(const ArkWeb_HttpBodyStream* httpBodyStream) | 判断 ArkWeb_HttpBodyStream 中的所有数据是否都已被读取。|
| OH_ArkWebHttpBodyStream_IsInMemory(const ArkWeb_HttpBodyStream* httpBodyStream) | 判断 ArkWeb_HttpBodyStream 中的数据是否在内存中。|
| OH_ArkWebResourceRequest_Destroy(const ArkWeb_ResourceRequest* resourceRequest) | 销毁ArkWeb_ResourceRequest对象。|
| OH_ArkWebResourceRequest_GetReferrer(const ArkWeb_ResourceRequest* resourceRequest, char** referrer) | 获取请求的referrer。|
| OH_ArkWebResourceRequest_GetRequestHeaders(const ArkWeb_ResourceRequest* resourceRequest, ArkWeb_RequestHeaderList** requestHeaderList) |获取请求的请求头列表 OH_ArkWeb_RequestHeaderList。|
| OH_ArkWebResourceRequest_IsRedirect(const ArkWeb_ResourceRequest* resourceRequest) | 判断是否为重定向请求。在网络拦截的场景下，该接口始终返回false。|
| OH_ArkWebResourceRequest_IsMainFrame(const ArkWeb_ResourceRequest* resourceRequest) | 判断是否是主框架文档的请求。|
| OH_ArkWebResourceRequest_HasGesture(const ArkWeb_ResourceRequest* resourceRequest) | 判断是否是由用户手势触发的请求。|
| OH_ArkWeb_RegisterCustomSchemes(const char* scheme, int32_t option) | 将三方协议注册到ArkWeb。对于内置的HTTP、HTTPS、FILE、FTP、ABOUT和DATA方案，不应调用此函数。此函数应在主线程上调用并且需要在内核初始化之前调用。|
| OH_ArkWebServiceWorker_SetSchemeHandler(const char* scheme, ArkWeb_SchemeHandler* schemeHandler) | 设置 ArkWeb_SchemeHandler 以拦截ServiceWorker触发的该协议类型的请求。应在ArkWeb内核初始化之后调用。可以使用 WebviewController.initializeWebEngine 来初始化内核而无需创建 ArkWeb。|
| OH_ArkWeb_SetSchemeHandler(const char* scheme, const char* webTag, ArkWeb_SchemeHandler* schemeHandler) | 为指定ArkWeb设置 ArkWeb_SchemeHandler 以拦截该协议类型的请求。应在ArkWeb内核初始化之后调用。可以使用 WebviewController.initializeWebEngine 来初始化内核而无需创建 ArkWeb。|
| OH_ArkWebServiceWorker_ClearSchemeHandlers() | 清除为ServiceWorker注册的SchemeHandler。|
| OH_ArkWeb_ClearSchemeHandlers(const char* webTag) | 清除为指定web注册的SchemeHandler。|
| OH_ArkWeb_CreateSchemeHandler(ArkWeb_SchemeHandler** schemeHandler) | 创建一个ArkWeb_SchemeHandler对象。|
| OH_ArkWeb_DestroySchemeHandler(ArkWeb_SchemeHandler* schemeHandler) | 销毁一个ArkWeb_SchemeHandler对象。|
| OH_ArkWebSchemeHandler_SetUserData(ArkWeb_SchemeHandler* schemeHandler, void* userData) | 将一个用户数据设置到ArkWeb_SchemeHandler对象中。|
| OH_ArkWebSchemeHandler_GetUserData(const ArkWeb_SchemeHandler* schemeHandler) | 从ArkWeb_SchemeHandler获取用户数据。|
| OH_ArkWebSchemeHandler_SetOnRequestStart(ArkWeb_SchemeHandler* schemeHandler, ArkWeb_OnRequestStart onRequestStart) | 为ArkWeb_SchemeHandler设置OnRequestStart回调。|
| OH_ArkWebSchemeHandler_SetOnRequestStop(ArkWeb_SchemeHandler* schemeHandler, ArkWeb_OnRequestStop onRequestStop) | 为ArkWeb_SchemeHandler设置OnRequestStop回调。|
| OH_ArkWeb_CreateResponse(ArkWeb_Response** response) | 创建一个ArkWeb_Response响应对象。|
| OH_ArkWeb_DestroyResponse(ArkWeb_Response* response) | 销毁一个ArkWeb_Response响应对象。|
| OH_ArkWebResponse_SetUrl(ArkWeb_Response* response, const char* url) | 设置重定向或因HSTS而更改后的URL，设置了url后会触发请求的跳转。|
| OH_ArkWebResponse_GetUrl(const ArkWeb_Response* response, char** url) | 获取重定向或由于HSTS而更改后的URL。|
| OH_ArkWebResponse_SetError(ArkWeb_Response* response, ArkWeb_NetError errorCode) | 给ArkWeb_Response对象设置一个网络错误码。|
| OH_ArkWebResponse_GetError(const ArkWeb_Response* response) | 获取响应的错误码。|
| OH_ArkWebResponse_SetStatus(ArkWeb_Response* response, int status) | 为ArkWeb_Response对象设置一个HTTP状态码。|
| OH_ArkWebResponse_GetStatus(const ArkWeb_Response* response) | 获取响应的HTTP状态码。|
| OH_ArkWebResponse_SetStatusText(ArkWeb_Response* response, const char* statusText) | 为ArkWebResponse设置状态文本。|
| OH_ArkWebResponse_GetStatusText(const ArkWeb_Response* response, char** statusText) | 获取响应的状态文本。|
| OH_ArkWebResponse_SetMimeType(ArkWeb_Response* response, const char* mimeType) | 为ArkWebResponse设置mime类型。|
| OH_ArkWebResponse_GetMimeType(const ArkWeb_Response* response, char** mimeType) | 获取响应的mime类型。|
| OH_ArkWebResponse_SetCharset(ArkWeb_Response* response, const char* charset) | 为ArkWeb_Response设置字符集。|
| OH_ArkWebResponse_GetCharset(const ArkWeb_Response* response, char** charset) | 获取响应的字符集。|
| OH_ArkWebResponse_SetHeaderByName(ArkWeb_Response* response, const char* name, const char* value, bool overwrite) | 为ArkWeb_Response设置请求头。|
| OH_ArkWebResponse_GetHeaderByName(const ArkWeb_Response* response, const char* name, char** value) | 从响应中获取头部信息。|
| OH_ArkWebResourceHandler_Destroy(const ArkWeb_ResourceHandler* resourceHandler) | 销毁一个ArkWeb_ResourceHandler对象。|
| OH_ArkWebResourceHandler_DidReceiveResponse(const ArkWeb_ResourceHandler* resourceHandler, const ArkWeb_Response* response) | 将构造的响应头传递给被拦截的请求。|
| OH_ArkWebResourceHandler_DidReceiveData(const ArkWeb_ResourceHandler* resourceHandler, const uint8_t* buffer, int64_t bufLen) | 将构造的响应体传递给被拦截的请求。|
| OH_ArkWebResourceHandler_DidFinish(const ArkWeb_ResourceHandler* resourceHandler) | 通知ArkWeb内核被拦截的请求已经完成，并且没有更多的数据可用。|
| OH_ArkWebResourceHandler_DidFailWithError(const ArkWeb_ResourceHandler* resourceHandler, ArkWeb_NetError errorCode) | 通知ArkWeb内核被拦截请求应该失败，失败的错误码为errorCode。|
| OH_ArkWeb_ReleaseString(char* string) | 释放由NDK接口创建的字符串。|
| OH_ArkWeb_ReleaseByteArray(uint8_t* byteArray) | 释放由NDK接口创建的字节数组。|


## 类型说明

### ArkWeb_CustomSchemeOption

三方协议的配置。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 值 | 说明                                      |
| ------------- | -- |----------------------------------------- |
| OH_ARKWEB_SCHEME_OPTION_NONE  | 0 ||
| ARKWEB_SCHEME_OPTION_STANDARD  | 1 | 设置了该选项的scheme将作为标准scheme进行处理。标准scheme需要符合[RFC 1738](http://www.ietf.org/rfc/rfc1738.txt)第3.1节中定义的URL规范化和解析规则 |
| ARKWEB_SCHEME_OPTION_LOCAL     | 2 | 设置了该选项的scheme将使用与应用于“FILE”的安全规则相同的安全规则来处理。|
| ARKWEB_SCHEME_OPTION_DISPLAY_ISOLATED | 4 | 设置了该选项的scheme的内容只能从相同scheme的其他内容中显示或访问。|
| ARKWEB_SCHEME_OPTION_SECURE     | 8 | 设置了该选项的scheme将使用与应用于“https”的安全规则相同的安全规则来处理。|
| ARKWEB_SCHEME_OPTION_CORS_ENABLED | 16 | 设置了该选项的scheme可以发送CORS请求。在大多数情况下，应在设置ARKWEB_SCHEME_OPTION_STANDARD时设置此值。|
| ARKWEB_SCHEME_OPTION_CSP_BYPASSING | 32 | 设置了该选项的scheme可以绕过内容安全策略（CSP）检查。在大多数情况下，当设置ARKWEB_SCHEME_OPTION_STANDARD时，不应设置此值。|
| ARKWEB_SCHEME_OPTION_FETCH_ENABLED | 64 | 设置了该选项的scheme可以执行FETCH API请求。|


### ArkWeb_SchemeHandler

该类用于拦截对指定scheme的请求。

**系统能力：** SystemCapability.Web.Webview.Core


### ArkWeb_ResourceHandler

通过ArkWeb_ResourceHandler可以提供自定义的返回头以及返回体。

**系统能力：** SystemCapability.Web.Webview.Core


### ArkWeb_Response

请求的响应，可以为被拦截的请求创建一个ArkWeb_Response并填充自定义的内容返回给ArkWeb。

**系统能力：** SystemCapability.Web.Webview.Core


### ArkWeb_ResourceRequest

代表一个ArkWeb发出的请求，通过ArkWeb_ResourceRequest可以拿到该请求的信息。

**系统能力：** SystemCapability.Web.Webview.Core


### ArkWeb_RequestHeaderList

请求的请求头信息。

**系统能力：** SystemCapability.Web.Webview.Core


### ArkWeb_HttpBodyStream

POST、PUT请求的上传数据，支持BYTES、FILE、BLOB、CHUNKED类型的数据。使用OH_ArkWebHttpBodyStream_*接口来读取POST、PUT请求的上传数据。

**系统能力：** SystemCapability.Web.Webview.Core


### ArkWeb_OnRequestStart

当请求开始时的回调，在该回调函数中可以决定是否拦截该请求，该接口会在IO线程回调。

**系统能力：** SystemCapability.Web.Webview.Core

```
typedef void (*ArkWeb_OnRequestStart)(const ArkWeb_SchemeHandler* schemeHandler,
                                      ArkWeb_ResourceRequest* resourceRequest,
                                      const ArkWeb_ResourceHandler* resourceHandler,
                                      bool* intercept);
```

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| schemeHandler | ArkWeb_SchemeHandler。 |
| resourceRequest | 通过resourceRequest获取请求的信息。 |
| resourceHandler | 为该请求创建的ArkWeb_ResourceHandler。如果intercept设置为false，则不应使用它。 |
| intercept | 如果为true将拦截请求，否则为false。 |


### ArkWeb_OnRequestStop

当请求完成时回调，这将在IO线程上被调用。
应该使用ArkWeb_ResourceRequest_Destroy销毁resourceRequest，并使用ArkWeb_ResourceHandler_Destroy销毁在ArkWeb_OnRequestStart中接收到的ArkWeb_ResourceHandler。

**系统能力：** SystemCapability.Web.Webview.Core

```
typedef void (*ArkWeb_OnRequestStop)(const ArkWeb_SchemeHandler* schemeHandler,
                                     const ArkWeb_ResourceRequest* resourceRequest);
```

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| schemeHandler | ArkWeb_SchemeHandler。 |
| resourceRequest | 通过resourceRequest获取请求的信息。 |

### ArkWeb_HttpBodyStreamReadCallback

当OH_ArkWebHttpBodyStream_Read读取操作完成时的回调。

**系统能力：** SystemCapability.Web.Webview.Core

```
typedef void (*ArkWeb_HttpBodyStreamReadCallback)(const ArkWeb_HttpBodyStream* httpBodyStream,
                                            uint8_t* buffer,
                                            int bytesRead);
```

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。 |
| buffer | 用于接收数据的缓冲区。 |
| bytesRead | 大于0的bytesRead意味着缓冲区被bytesRead大小的数据填满。调用者可以从缓冲区中读取，如果OH_ArkWebHttpBodyStream_IsEOF为false，调用者可以继续读取剩余的数据。 |


### ArkWeb_HttpBodyStreamInitCallback

ArkWeb_HttpBodyStream初始化操作完成时回调。

**系统能力：** SystemCapability.Web.Webview.Core

```
typedef void (*ArkWeb_HttpBodyStreamInitCallback)(const ArkWeb_HttpBodyStream* httpBodyStream, ArkWeb_NetError result);
```

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。 |
| result | 成功时为ARKWEB_NET_OK。 |


## 函数说明

### OH_ArkWebRequestHeaderList_Destroy

```
void OH_ArkWebRequestHeaderList_Destroy(ArkWeb_RequestHeaderList* requestHeaderList);
```

**描述**

销毁ArkWeb内核创建的ArkWeb_RequestHeaderList对象。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| requestHeaderList | 待删除的ArkWeb_RequestHeaderList。 |


### OH_ArkWebRequestHeaderList_GetSize

```
int32_t OH_ArkWebRequestHeaderList_GetSize(const ArkWeb_RequestHeaderList* requestHeaderList);
```

**描述**

获取请求的请求头列表的大小。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| requestHeaderList | 请求头的列表。 |

**返回：**

请求头列表的大小。


### OH_ArkWebRequestHeaderList_GetHeader

```
void OH_ArkWebRequestHeaderList_GetHeader(const ArkWeb_RequestHeaderList* requestHeaderList,
                                          int32_t index,
                                          char** key,
                                          char** value);
```

**描述**

获取指定的请求头。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| requestHeaderList | 请求头列表。 |
| index | 请求头的索引。 |
| key | 请求头的键（key）。调用者必须使用 OH_ArkWeb_ReleaseString 函数来释放这个字符串。 |
| value | 请求头的值（value）。调用者必须使用 OH_ArkWeb_ReleaseString 函数来释放这个字符串。 |


### OH_ArkWebResourceRequest_SetUserData

```
int32_t OH_ArkWebResourceRequest_SetUserData(ArkWeb_ResourceRequest* resourceRequest, void* userData);
```

**描述**

将一个用户数据设置到ArkWeb_ResourceRequest对象中。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest。 |
| userData | 要设置的用户数据。 |

**返回：**

如果成功，返回0；失败返回其它错误码，错误码的详细介绍请参见[arkweb_error_code.md](arkweb_error_code.md)。


### OH_ArkWebResourceRequest_GetUserData

```
void* OH_ArkWebResourceRequest_GetUserData(const ArkWeb_ResourceRequest* resourceRequest);
```

**描述**

从ArkWeb_ResourceRequest获取用户数据。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest。 |


### OH_ArkWebResourceRequest_GetMethod

```
void OH_ArkWebResourceRequest_GetMethod(const ArkWeb_ResourceRequest* resourceRequest, char** method);
```

**描述**

获取请求的方法。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest。 |
| method | HTTP请求方法。此函数将为method字符串分配内存，调用者必须使用OH_ArkWeb_ReleaseString释放字符串。 |


### OH_ArkWebResourceRequest_GetUrl

```
void OH_ArkWebResourceRequest_GetUrl(const ArkWeb_ResourceRequest* resourceRequest, char** url);
```

**描述**

获取请求的url。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest。 |
| url | 请求的URL。此函数将为URL字符串分配内存，调用者必须通过OH_ArkWeb_ReleaseString释放该字符串。 |


### OH_ArkWebResourceRequest_GetHttpBodyStream

```
void OH_ArkWebResourceRequest_GetHttpBodyStream(const ArkWeb_ResourceRequest* resourceRequest,
                                                ArkWeb_HttpBodyStream** httpBodyStream);
```

**描述**

获取请求的上传数据。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest。 |
| httpBodyStream | 请求的上传数据。此函数将为 httpBodyStream 分配内存，调用者必须使用 OH_ArkWebResourceRequest_DestroyHttpBodyStream 释放 httpBodyStream。 |


### OH_ArkWebResourceRequest_DestroyHttpBodyStream

```
void OH_ArkWebResourceRequest_DestroyHttpBodyStream(ArkWeb_HttpBodyStream* httpBodyStream);
```

**描述**

销毁ArkWeb_HttpBodyStream对象。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| httpBodyStream | 待销毁的ArkWeb_HttpBodyStream。 |


### OH_ArkWebHttpBodyStream_SetUserData

```
int32_t OH_ArkWebHttpBodyStream_SetUserData(ArkWeb_HttpBodyStream* httpBodyStream, void* userData);
```

**描述**

将一个用户数据设置到ArkWeb_HttpBodyStream对象中。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。 |
| userData | 要设置的用户数据。 |

**返回：**

如果成功，返回0；失败返回其它错误码，错误码的详细介绍请参见[arkweb_error_code.md](arkweb_error_code.md)。


### OH_ArkWebHttpBodyStream_GetUserData

```
void* OH_ArkWebHttpBodyStream_GetUserData(const ArkWeb_HttpBodyStream* httpBodyStream);
```

**描述**

从ArkWeb_HttpBodyStream获取用户数据。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。 |


### OH_ArkWebHttpBodyStream_SetReadCallback

```
int32_t OH_ArkWebHttpBodyStream_SetReadCallback(ArkWeb_HttpBodyStream* httpBodyStream,
                                                ArkWeb_HttpBodyStreamReadCallback readCallback);
```

**描述**

为 OH_ArkWebHttpBodyStream_Read 设置回调函数，OH_ArkWebHttpBodyStream_Read 的结果将通过 readCallback 通知给调用者。该回调函数将在与 OH_ArkWebHttpBodyStream_Read 相同的线程中运行。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。 |
| readCallback | OH_ArkWebHttpBodyStream_Read的回调函数。 |

**返回：**

如果成功，返回0；失败返回其它错误码，错误码的详细介绍请参见[arkweb_error_code.md](arkweb_error_code.md)。


### OH_ArkWebHttpBodyStream_Init

```
int32_t OH_ArkWebHttpBodyStream_Init(ArkWeb_HttpBodyStream* httpBodyStream,
                                     ArkWeb_HttpBodyStreamInitCallback initCallback);
```

**描述**

初始化ArkWeb_HttpBodyStream。在调用任何其他函数之前，必须调用此函数。该接口需要在IO线程调用。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。 |
| initCallback | 初始化的回调函数。 |

**返回：**

如果成功，返回0；失败返回其它错误码，错误码的详细介绍请参见[arkweb_error_code.md](arkweb_error_code.md)。


### OH_ArkWebHttpBodyStream_Read

```
void OH_ArkWebHttpBodyStream_Read(const ArkWeb_HttpBodyStream* httpBodyStream, uint8_t* buffer, int bufLen);
```

**描述**

将数据读取到缓冲区。缓冲区的大小必须大于bufLen。我们将从工作线程读取数据到缓冲区，因此在回调函数返回之前，不应在其他线程中使用缓冲区，以避免并发问题。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。 |
| buffer | 接收数据的缓冲区。 |
| bufLen | 要读取的字节的大小。 |


### OH_ArkWebHttpBodyStream_GetSize

```
uint64_t OH_ArkWebHttpBodyStream_GetSize(const ArkWeb_HttpBodyStream* httpBodyStream);
```

**描述**

获取 ArkWeb_HttpBodyStream 的大小，分块传输时总是返回零。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。 |

**返回：**

返回 ArkWeb_HttpBodyStream 的大小，分块传输时总是返回零。


### OH_ArkWebHttpBodyStream_GetPosition

```
uint64_t OH_ArkWebHttpBodyStream_GetPosition(const ArkWeb_HttpBodyStream* httpBodyStream);
```

**描述**

获取 ArkWeb_HttpBodyStream 当前的读取位置。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。 |

**返回：**

返回 ArkWeb_HttpBodyStream 当前的读取位置。


### OH_ArkWebHttpBodyStream_IsChunked

```
bool OH_ArkWebHttpBodyStream_IsChunked(const ArkWeb_HttpBodyStream* httpBodyStream);
```

**描述**

获取 ArkWeb_HttpBodyStream 是否采用分块传输。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。 |

**返回：**

返回 ArkWeb_HttpBodyStream 是否以分块类型传输。


### OH_ArkWebHttpBodyStream_IsEof

```
bool OH_ArkWebHttpBodyStream_IsEof(const ArkWeb_HttpBodyStream* httpBodyStream);
```

**描述**

判断 ArkWeb_HttpBodyStream 中的所有数据是否都已被读取。如果所有数据都已被读取，则返回true。对于分块传输类型的 ArkWeb_HttpBodyStream，在第一次读取尝试之前返回false。 

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。 |

**返回：**

返回 httpBodyStream 中的所有数据是否都已被读取。


### OH_ArkWebHttpBodyStream_IsInMemory

```
bool OH_ArkWebHttpBodyStream_IsInMemory(const ArkWeb_HttpBodyStream* httpBodyStream);
```

**描述**

判断 httpBodyStream 中的上传数据是否在内存中。如果 httpBodyStream 中的上传数据完全在内存中，并且所有读取请求都将同步成功，则返回true。对于分块传输类型的数据，预期返回false。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。 |

**返回：**

返回 httpBodyStream 中的上传数据是否在内存中。


### OH_ArkWebResourceRequest_Destroy

```
int32_t OH_ArkWebResourceRequest_Destroy(const ArkWeb_ResourceRequest* resourceRequest);
```

**描述**

销毁ArkWeb_ResourceRequest对象。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| resourceRequest | 待销毁的ArkWeb_ResourceRequest。 |

**返回：**

如果成功，返回0；失败返回其它错误码，错误码的详细介绍请参见[arkweb_error_code.md](arkweb_error_code.md)。 


### OH_ArkWebResourceRequest_GetReferrer

```
void OH_ArkWebResourceRequest_GetReferrer(const ArkWeb_ResourceRequest* resourceRequest, char** referrer);
```

**描述**

获取请求的Referrer。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest。 |
| referrer | 请求的Referrer。此函数将为referrer字符串分配内存，调用者必须使用 OH_ArkWeb_ReleaseString 释放该字符串。 |


### OH_ArkWebResourceRequest_GetRequestHeaders

```
void OH_ArkWebResourceRequest_GetRequestHeaders(const ArkWeb_ResourceRequest* resourceRequest,
                                                ArkWeb_RequestHeaderList** requestHeaderList);
```

**描述**

获取请求的请求头列表 OH_ArkWeb_RequestHeaderList。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest。 |
| requestHeaderList | 请求中的请求头列表。 |


### OH_ArkWebResourceRequest_IsRedirect

```
bool OH_ArkWebResourceRequest_IsRedirect(const ArkWeb_ResourceRequest* resourceRequest);
```

**描述**

判断是否为重定向请求。在网络拦截的场景下，该接口始终返回false。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest。 |

**返回：**

返回是否为重定向请求。 


### OH_ArkWebResourceRequest_IsMainFrame

```
bool OH_ArkWebResourceRequest_IsMainFrame(const ArkWeb_ResourceRequest* resourceRequest);
```

**描述**

判断是否是主框架文档的请求。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest |

**返回：**

返回是否为主框架文档的请求。 


### OH_ArkWebResourceRequest_HasGesture

```
bool OH_ArkWebResourceRequest_HasGesture(const ArkWeb_ResourceRequest* resourceRequest);
```

**描述**

判断是否是由用户手势触发的请求。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest。 |

**返回：**

返回是否是由用户手势触发的请求。 


### OH_ArkWeb_RegisterCustomSchemes

```
int32_t OH_ArkWeb_RegisterCustomSchemes(const char* scheme, int32_t option);
```

**描述**

将三方协议注册到ArkWeb。对于内置的HTTP、HTTPS、FILE、FTP、ABOUT和DATA方案，不应调用此函数。此函数应在主线程上调用并且需要在内核初始化之前调用。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| scheme | 待注册的协议。 |
| option | 协议的配置（行为）。 |

**返回：**

如果成功，返回0；失败返回其它错误码，错误码的详细介绍请参见[arkweb_error_code.md](arkweb_error_code.md)。


### OH_ArkWebServiceWorker_SetSchemeHandler

```
bool OH_ArkWebServiceWorker_SetSchemeHandler(const char* scheme, ArkWeb_SchemeHandler* schemeHandler);
```

**描述**

设置 ArkWeb_SchemeHandler 以拦截ServiceWorker触发的该协议类型的请求。应在ArkWeb内核初始化之后调用。可以使用 WebviewController.initializeWebEngine 来初始化内核而无需创建 ArkWeb。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| scheme | 需要拦截的协议。 |
| schemeHandler | 该协议的拦截器ArkWeb_SchemeHandler。只有通过 ServiceWorker 触发的请求才会通过这个schemeHandler进行通知。 |

**返回：**

设置成功返回true，否则返回false。


### OH_ArkWeb_SetSchemeHandler

```
bool OH_ArkWeb_SetSchemeHandler(const char* scheme, const char* webTag, ArkWeb_SchemeHandler* schemeHandler);
```

**描述**

为指定ArkWeb设置 ArkWeb_SchemeHandler 以拦截该协议类型的请求。应在ArkWeb内核初始化之后调用。可以使用 WebviewController.initializeWebEngine 来初始化内核而无需创建 ArkWeb。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| scheme | 需要拦截的协议。 |
| webTag | Web组件的标签名称，用于标识某个唯一组件，由开发者来保证名称唯一性。 |
| schemeHandler | 该协议的拦截器ArkWeb_SchemeHandler。只有通过指定网络触发的请求才会通过这个schemeHandler进行通知。 |

**返回：**

设置成功返回true，否则返回false。


### OH_ArkWebServiceWorker_ClearSchemeHandlers

```
int32_t OH_ArkWebServiceWorker_ClearSchemeHandlers();
```

**描述**

清除为ServiceWorker注册的SchemeHandler。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:** 无

**返回：**

如果成功，返回0；失败返回其它错误码，错误码的详细介绍请参见[arkweb_error_code.md](arkweb_error_code.md)。


### OH_ArkWeb_ClearSchemeHandlers

```
int32_t OH_ArkWeb_ClearSchemeHandlers(const char* webTag);
```

**描述**

清除在指定web上注册的SchemeHandler。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| webTag | Web组件的标签名称，用于标识某个唯一组件，由开发者来保证名称唯一性。 |

**返回：**

如果成功，返回0；失败返回其它错误码，错误码的详细介绍请参见[arkweb_error_code.md](arkweb_error_code.md)。


### OH_ArkWeb_CreateSchemeHandler

```
void OH_ArkWeb_CreateSchemeHandler(ArkWeb_SchemeHandler** schemeHandler);
```

**描述**

创建一个ArkWeb_SchemeHandler。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| schemeHandler | 返回创建的ArkWeb_SchemeHandler。在不需要时使用OH_ArkWeb_DestoryschemeHandler销毁它。 |


### OH_ArkWeb_DestroySchemeHandler

```
void OH_ArkWeb_DestroySchemeHandler(ArkWeb_SchemeHandler* schemeHandler);
```

**描述**

销毁一个ArkWeb_SchemeHandler对象。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| schemeHandler | 待销毁的ArkWeb_SchemeHandler。 |


### OH_ArkWebSchemeHandler_SetUserData

```
int32_t OH_ArkWebSchemeHandler_SetUserData(ArkWeb_SchemeHandler* schemeHandler, void* userData);
```

**描述**

将一个用户数据设置到ArkWeb_SchemeHandler对象中。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| schemeHandler | ArkWeb_SchemeHandler。 |
| userData | 要设置的用户数据。 |

**返回：**

如果成功，返回0；失败返回其它错误码，错误码的详细介绍请参见[arkweb_error_code.md](arkweb_error_code.md)。

### OH_ArkWebSchemeHandler_GetUserData

```
void* OH_ArkWebSchemeHandler_GetUserData(const ArkWeb_SchemeHandler* schemeHandler);
```

**描述**

从ArkWeb_SchemeHandler获取用户数据。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| schemeHandler | ArkWeb_SchemeHandler。 |


### OH_ArkWebSchemeHandler_SetOnRequestStart

```
int32_t OH_ArkWebSchemeHandler_SetOnRequestStart(ArkWeb_SchemeHandler* schemeHandler,
                                                 ArkWeb_OnRequestStart onRequestStart);
```

**描述**

为SchemeHandler设置OnRequestStart回调。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| schemeHandler | 协议的拦截器ArkWeb_SchemeHandler。 |
| onRequestStart | OnRequestStart回调函数。 |

**返回：**

如果成功，返回0；失败返回其它错误码，错误码的详细介绍请参见[arkweb_error_code.md](arkweb_error_code.md)。


### OH_ArkWebSchemeHandler_SetOnRequestStop

```
int32_t OH_ArkWebSchemeHandler_SetOnRequestStop(ArkWeb_SchemeHandler* schemeHandler,
                                                ArkWeb_OnRequestStop onRequestStop);
```

**描述**

为SchemeHandler设置OnRequestStop回调。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| schemeHandler | 协议的拦截器ArkWeb_SchemeHandler。 |
| onRequestStop | OnRequestStop回调函数。 |

**返回：**

如果成功，返回0；失败返回其它错误码，错误码的详细介绍请参见[arkweb_error_code.md](arkweb_error_code.md)。


### OH_ArkWeb_CreateResponse

```
void OH_ArkWeb_CreateResponse(ArkWeb_Response** response);
```

**描述**

创建一个ArkWeb_Response响应对象。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| response | 返回创建的响应。在不需要时使用OH_ArkWeb_DestoryResponse进行销毁。 |


### OH_ArkWeb_DestroyResponse

```
void OH_ArkWeb_DestroyResponse(ArkWeb_Response* response);
```

**描述**

销毁一个ArkWeb_Response响应对象。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| response | 待销毁的ArkWeb_Response。 |


### OH_ArkWebResponse_SetUrl

```
int32_t OH_ArkWebResponse_SetUrl(ArkWeb_Response* response, const char* url);
```

**描述**

设置重定向或因HSTS而更改后的URL，设置了url后会触发请求的跳转。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| response | ArkWeb_Response。 |
| url | 即将要跳转的URL。 |

**返回：**

如果成功，返回0；失败返回其它错误码，错误码的详细介绍请参见[arkweb_error_code.md](arkweb_error_code.md)。


### OH_ArkWebResponse_GetUrl

```
void OH_ArkWebResponse_GetUrl(const ArkWeb_Response* response, char** url);
```

**描述**

从ArkWeb_Response获取经过重定向或由于HSTS而更改后的URL。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| response | ArkWeb_Response。 |
| url | 跳转的URL |


### OH_ArkWebResponse_SetError

```
int32_t OH_ArkWebResponse_SetError(ArkWeb_Response* response, ArkWeb_NetError errorCode);
```

**描述**

给ArkWeb_Response对象设置一个错误码。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| response | ArkWeb_Response。 |
| errorCode | 失败请求的错误码。 |

**返回：**

如果成功，返回0；失败返回其它错误码，错误码的详细介绍请参见[arkweb_error_code.md](arkweb_error_code.md)。

### OH_ArkWebResponse_GetError

```
ArkWeb_NetError OH_ArkWebResponse_GetError(const ArkWeb_Response* response);
```

**描述**

获取响应的错误码。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| response | ArkWeb_Response。 |

**返回：**

返回响应的错误码。


### OH_ArkWebResponse_SetStatus

```
int32_t OH_ArkWebResponse_SetStatus(ArkWeb_Response* response, int status);
```

**描述**

为ArkWeb_Response对象设置一个HTTP状态码。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| response | ArkWeb_Response。 |
| status | 请求的HTTP状态码。 |

**返回：**

如果成功，返回0；失败返回其它错误码，错误码的详细介绍请参见[arkweb_error_code.md](arkweb_error_code.md)。


### OH_ArkWebResponse_GetStatus

```
int OH_ArkWebResponse_GetStatus(const ArkWeb_Response* response);
```

**描述**

获取响应的HTTP状态码。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| response | ArkWeb_Response。 |

**返回：**

返回响应的HTTP状态码。


### OH_ArkWebResponse_SetStatusText

```
int32_t OH_ArkWebResponse_SetStatusText(ArkWeb_Response* response, const char* statusText);
```

**描述**

为ArkWebResponse设置状态文本。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| response | ArkWeb_Response。 |
| statusText | 请求的状态文本。 |

**返回：**

如果成功，返回0；失败返回其它错误码，错误码的详细介绍请参见[arkweb_error_code.md](arkweb_error_code.md)。


### OH_ArkWebResponse_GetStatusText

```
void OH_ArkWebResponse_GetStatusText(const ArkWeb_Response* response, char** statusText);
```

**描述**

获取响应的状态文本。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| response | ArkWeb_Response。 |
| statusText | 返回响应的状态文本。此函数将为statusText字符串分配内存，调用方必须通过OH_ArkWeb_ReleaseString释放该字符串。 |


### OH_ArkWebResponse_SetMimeType

```
int32_t OH_ArkWebResponse_SetMimeType(ArkWeb_Response* response, const char* mimeType);
```

**描述**

为ArkWebResponse设置媒体类型。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| response | ArkWeb_Response。 |
| mimeType | 请求的媒体类型。 |

**返回：**

如果成功，返回0；失败返回其它错误码，错误码的详细介绍请参见[arkweb_error_code.md](arkweb_error_code.md)。

### OH_ArkWebResponse_GetMimeType

```
void OH_ArkWebResponse_GetMimeType(const ArkWeb_Response* response, char** mimeType);
```

**描述**

获取媒体类型。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| response | ArkWeb_Response。 |
| mimeType | 返回媒体类型。此函数将为mimeType字符串分配内存，调用方必须通过OH_ArkWeb_ReleaseString释放该字符串。 |


### OH_ArkWebResponse_SetCharset

```
int32_t OH_ArkWebResponse_SetCharset(ArkWeb_Response* response, const char* charset);
```

**描述**

为ArkWeb_Response设置字符集。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| response | ArkWeb_Response。 |
| charset | 请求的字符集。 |

**返回：**

如果成功，返回0；失败返回其它错误码，错误码的详细介绍请参见[arkweb_error_code.md](arkweb_error_code.md)。


### OH_ArkWebResponse_GetCharset

```
void OH_ArkWebResponse_GetCharset(const ArkWeb_Response* response, char** charset);
```

**描述**

获取响应的字符集。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| response | ArkWeb_Response。 |
| charset | 返回响应的字符集。此函数将为charset字符串分配内存，调用方必须通过OH_ArkWeb_ReleaseString释放字符串。 |


### OH_ArkWebResponse_SetHeaderByName

```
int32_t OH_ArkWebResponse_SetHeaderByName(ArkWeb_Response* response,
                                          const char* name,
                                          const char* value,
                                          bool overwrite);
```

**描述**

为ArkWeb_Response设置一个头部（header）。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| response | ArkWeb_Response。 |
| name | 头部（header）的名称。 |
| value | 头部（header）的值。 |
| overwrite | 如果为 true，将覆盖现有的头部，否则不覆盖。 |

**返回：**

如果成功，返回0；失败返回其它错误码，错误码的详细介绍请参见[arkweb_error_code.md](arkweb_error_code.md)。


### OH_ArkWebResponse_GetHeaderByName

```
void OH_ArkWebResponse_GetHeaderByName(const ArkWeb_Response* response, const char* name, char** value);
```

**描述**

从响应中获取头部信息。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| response | ArkWeb_Response。 |
| name | 头部（header）的名称。 |
| value | 返回头部（header）的值。此函数将为value字符串分配内存，调用方必须通过OH_ArkWeb_ReleaseString释放该字符串。 |


### OH_ArkWebResourceHandler_Destroy

```
int32_t OH_ArkWebResourceHandler_Destroy(const ArkWeb_ResourceHandler* resourceHandler);
```

**描述**

销毁一个ArkWeb_ResourceHandler对象。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| resourceHandler | 待销毁的ArkWeb_ResourceHandler。 |

**返回：**

如果成功，返回0；失败返回其它错误码，错误码的详细介绍请参见[arkweb_error_code.md](arkweb_error_code.md)。


### OH_ArkWebResourceHandler_DidReceiveResponse

```
int32_t OH_ArkWebResourceHandler_DidReceiveResponse(const ArkWeb_ResourceHandler* resourceHandler,
                                                    const ArkWeb_Response* response);
```

**描述**

将构造的响应头传递给被拦截的请求。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| resourceHandler | 该请求的ArkWeb_ResourceHandler。 |
| response | 该拦截请求的响应ArkWeb_Response。 |

**返回：**

如果成功，返回0；失败返回其它错误码，错误码的详细介绍请参见[arkweb_error_code.md](arkweb_error_code.md)。


### OH_ArkWebResourceHandler_DidReceiveData

```
int32_t OH_ArkWebResourceHandler_DidReceiveData(const ArkWeb_ResourceHandler* resourceHandler,
                                                const uint8_t* buffer,
                                                int64_t bufLen);
```

**描述**

将构造的响应体传递给被拦截的请求。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| resourceHandler | 该请求的ArkWeb_ResourceHandler。 |
| buffer | 要发送的缓冲区数据。 |
| bufLen | 缓冲区的大小。 |

**返回：**

如果成功，返回0；失败返回其它错误码，错误码的详细介绍请参见[arkweb_error_code.md](arkweb_error_code.md)。


### OH_ArkWebResourceHandler_DidFinish

```
int32_t OH_ArkWebResourceHandler_DidFinish(const ArkWeb_ResourceHandler* resourceHandler);
```

**描述**

通知ArkWeb内核被拦截的请求已经完成，并且没有更多的数据可用。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| resourceHandler | 该请求的ArkWeb_ResourceHandler。 |

**返回：**

如果成功，返回0；失败返回其它错误码，错误码的详细介绍请参见[arkweb_error_code.md](arkweb_error_code.md)。


### OH_ArkWebResourceHandler_DidFailWithError

```
int32_t OH_ArkWebResourceHandler_DidFailWithError(const ArkWeb_ResourceHandler* resourceHandler,
                                                  ArkWeb_NetError errorCode);
```

**描述**

通知ArkWeb内核被拦截请求应该失败，失败的错误码为errorCode。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| resourceHandler | 该请求的ArkWeb_ResourceHandler。 |
| errorCode | 该请求的错误码。 |

**返回：**

如果成功，返回0；失败返回其它错误码，错误码的详细介绍请参见[arkweb_error_code.md](arkweb_error_code.md)。


### OH_ArkWeb_ReleaseString

```
void OH_ArkWeb_ReleaseString(char* string);
```

**描述**

释放由NDK接口创建的字符串

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| string | 待释放的字符串。 |


### OH_ArkWeb_ReleaseByteArray

```
void OH_ArkWeb_ReleaseByteArray(uint8_t* byteArray);
```

**描述**

释放由NDK接口创建的字节数组。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| byteArray | 待释放的字节数组。 |

## 示例代码

使用DevEco Studio创建一个默认的 Native C++工程，需要提前准备一个mp4文件，命名为test.mp4，将test.mp4放到 main/resources/rawfile下。

main/ets/pages/index.ets
```
import testNapi from 'libentry.so';
import web_webview from '@ohos.web.webview';
import resource_manager from '@ohos.resourceManager';

@Entry
@Component
struct Index {
  mycontroller: web_webview.WebviewController = new web_webview.WebviewController("scheme-handler");

  build() {
    Row() {
      Column() {
        Button("goback").onClick( event => {
          this.mycontroller.backward();
        })

        Web({ src: $rawfile("test.html"), controller: this.mycontroller})
          .javaScriptAccess(true)
          .width('100%')
          .height('100%')
          .databaseAccess(true)
          .fileAccess(false)
          .domStorageAccess(true)
          .cacheMode(CacheMode.Default)
          .onPageBegin( event => {
            testNapi.initResourceManager(getContext().resourceManager);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

main/ets/entryability/EntryAbility.ets
```
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import testNapi from 'libentry.so';
import webview from '@ohos.web.webview';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        // 注册三方协议的配置。
        testNapi.registerCustomSchemes();
        // 初始化ArkWeb内核，该操作会初始化Browser进程以及创建BrowserContext。
        webview.WebviewController.initializeWebEngine();
        // 设置SchemeHandler。
        testNapi.setSchemeHandler();
    }

    onDestroy(): void {

    }

    onWindowStageCreate(windowStage: window.WindowStage): void {
        windowStage.loadContent('pages/Index', (err, data) => {
            if (err.code) {
                return;
            }
        });
    }

    onWindowStageDestroy(): void {

    }

    onForeground(): void {

    }

    onBackground(): void {

    }
};
```

main/cpp/hello.cpp
```
#include "hilog/log.h"
#include "napi/native_api.h"
#include "rawfile_request.h"
#include "rawfile/raw_file_manager.h"
#include "web/arkweb_scheme_handler.h"
#include "web/arkweb_net_error_list.h"

#undef LOG_TAG
#define LOG_TAG "ss-handler"

ArkWeb_SchemeHandler *g_schemeHandler;
ArkWeb_SchemeHandler *g_schemeHandlerForSW;
NativeResourceManager *g_resourceManager;

// 注册三方协议的配置，需要在内核初始化之前调用，否则会注册失败。
static napi_value RegisterCustomSchemes(napi_env env, napi_callback_info info)
{
    OH_LOG_INFO(LOG_APP, "register custom schemes");
    OH_ArkWeb_RegisterCustomSchemes("custom", ARKWEB_SCHEME_OPTION_STANDARD | ARKWEB_SCHEME_OPTION_CORS_ENABLED);
    OH_ArkWeb_RegisterCustomSchemes("custom-local", ARKWEB_SCHEME_OPTION_LOCAL);
    OH_ArkWeb_RegisterCustomSchemes("custom-csp-bypassing", ARKWEB_SCHEME_OPTION_CSP_BYPASSING | ARKWEB_SCHEME_OPTION_STANDARD);
    OH_ArkWeb_RegisterCustomSchemes("custom-isolated", ARKWEB_SCHEME_OPTION_DISPLAY_ISOLATED);
    return nullptr;
}

// 请求开始的回调，在该函数中我们创建一个RawfileRequest来实现对内核请求的拦截。
void OnURLRequestStart(const ArkWeb_SchemeHandler *schemeHandler,
                       ArkWeb_ResourceRequest *resourceRequest,
                       const ArkWeb_ResourceHandler *resourceHandler,
                       bool *intercept)
{
    *intercept = true;
    RawfileRequest* request = new RawfileRequest(resourceRequest, resourceHandler, g_resourceManager);
    OH_ArkWebResourceRequest_SetUserData(resourceRequest, request);
    request->Start();
}

// 请求结束的回调，在该函数中我们需要标记RawfileRequest已经结束了，内部不应该再使用ResourceHandler。
void OnURLRequestStop(const ArkWeb_SchemeHandler *schemeHandler,
                      const ArkWeb_ResourceRequest *request)
{
    if (!request) {
        OH_LOG_ERROR(LOG_APP, "on request stop request is nullptr.");
        return;
    }

    RawfileRequest *rawfileRequest = (RawfileRequest *)OH_ArkWebResourceRequest_GetUserData(request);
    if (rawfileRequest) {
        rawfileRequest->Stop();
    }
}

void OnURLRequestStartForSW(const ArkWeb_SchemeHandler *schemeHandler,
                            ArkWeb_ResourceRequest *resourceRequest,
                            const ArkWeb_ResourceHandler *resourceHandler,
                            bool *intercept)
{
    *intercept = true;
    RawfileRequest* request = new RawfileRequest(resourceRequest, resourceHandler, g_resourceManager);
    OH_ArkWebResourceRequest_SetUserData(resourceRequest, request);
    request->Start();
}

void OnURLRequestStopForSW(const ArkWeb_SchemeHandler *schemeHandler,
                           const ArkWeb_ResourceRequest *request)
{
    if (!request) {
        OH_LOG_ERROR(LOG_APP, "on request stop request is nullptr.");
        return;
    }

    RawfileRequest *rawfileRequest = (RawfileRequest *)OH_ArkWebResourceRequest_GetUserData(request);
    if (rawfileRequest) {
        rawfileRequest->Stop();
    }
}

// 设置SchemeHandler。
static napi_value SetSchemeHandler(napi_env env, napi_callback_info info)
{
    OH_LOG_INFO(LOG_APP, "set scheme handler");
    OH_ArkWeb_CreateSchemeHandler(&g_schemeHandler);
    OH_ArkWeb_CreateSchemeHandler(&g_schemeHandlerForSW);

    OH_ArkWebSchemeHandler_SetOnRequestStart(g_schemeHandler, OnURLRequestStart);
    OH_ArkWebSchemeHandler_SetOnRequestStop(g_schemeHandler, OnURLRequestStop);

    OH_ArkWebSchemeHandler_SetOnRequestStart(g_schemeHandlerForSW, OnURLRequestStart);
    OH_ArkWebSchemeHandler_SetOnRequestStop(g_schemeHandlerForSW, OnURLRequestStop);

    OH_ArkWeb_SetSchemeHandler("custom", "scheme-handler", g_schemeHandler);
    OH_ArkWeb_SetSchemeHandler("custom-csp-bypassing", "scheme-handler", g_schemeHandler);
    OH_ArkWeb_SetSchemeHandler("custom-isolated", "scheme-handler", g_schemeHandler);
    OH_ArkWeb_SetSchemeHandler("custom-local", "scheme-handler", g_schemeHandler);
    OH_ArkWeb_SetSchemeHandler("https", "scheme-handler", g_schemeHandler);
    OH_ArkWeb_SetSchemeHandler("http", "scheme-handler", g_schemeHandler);

    OH_ArkWebServiceWorker_SetSchemeHandler("https", g_schemeHandlerForSW);
    return nullptr;
}

static napi_value InitResourceManager(napi_env env, napi_callback_info info)
{
    size_t argc = 2;
    napi_value argv[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    g_resourceManager = OH_ResourceManager_InitNativeResourceManager(env, argv[0]);
    return nullptr;
}

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    napi_property_descriptor desc[] = {
        {"setSchemeHandler", nullptr, SetSchemeHandler, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"initResourceManager", nullptr, InitResourceManager, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"registerCustomSchemes", nullptr, RegisterCustomSchemes, nullptr, nullptr, nullptr, napi_default, nullptr}
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
    .nm_priv = ((void*)0),
    .reserved = { 0 },
};

extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
{
    napi_module_register(&demoModule);
}
```


main/cpp/CMakeLists.txt
```
# the minimum version of CMake.
cmake_minimum_required(VERSION 3.4.1)
project(schemehandler)

set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

if(DEFINED PACKAGE_INFO_FILE)
    include(${PACKAGE_INFO_FILE})
endif()

include_directories(${NATIVERENDER_ROOT_PATH}
                    ${NATIVERENDER_ROOT_PATH}/include)

add_library(entry SHARED rawfile_request.cpp hello.cpp)
target_link_libraries(entry PUBLIC librawfile.z.so libace_napi.z.so libohweb.so libhilog_ndk.z.so)
```

main/cpp/types/index.d.ts
```
export const registerCustomSchemes: () => void;
export const setSchemeHandler: () => void;
export const initResourceManager: (resmgr: resourceManager.ResourceManager) => void;
```

main/cpp/rawfile_request.h
```
#ifndef RAWFILE_REQUEST_H
#define RAWFILE_REQUEST_H

#include <mutex>
#include <string>

#include <rawfile/raw_file_manager.h>
#include "web/arkweb_scheme_handler.h"
#include "web/arkweb_net_error_list.h"

class RawfileRequest {
public:
    RawfileRequest(const ArkWeb_ResourceRequest *resourceRequest,
                   const ArkWeb_ResourceHandler *resourceHandler,
                   const NativeResourceManager* resourceManager);
    ~RawfileRequest();

    void Start();
    void Stop();
    void ReadRawfileDataOnWorkerThread();

    const ArkWeb_ResourceHandler *resourceHandler() { return resourceHandler_; }
    const ArkWeb_ResourceRequest *resourceRequest() { return resourceRequest_; }
    const NativeResourceManager *resourceManager() { return resourceManager_; }
    ArkWeb_Response *response() { return response_; }
    ArkWeb_HttpBodyStream *stream() { return stream_; }
    const std::string rawfilePath() { return rawfilePath_; }

    void DidReceiveResponse();
    void DidReceiveData(const uint8_t *buffer, int64_t bufLen);
    void DidFinish();
    void DidFailWithError(ArkWeb_NetError errorCode);

private:
    const ArkWeb_ResourceRequest *resourceRequest_{nullptr};
    const ArkWeb_ResourceHandler *resourceHandler_{nullptr};
    const NativeResourceManager *resourceManager_{nullptr};
    ArkWeb_Response *response_;
    bool stopped_{false};
    std::string rawfilePath_;
    ArkWeb_HttpBodyStream *stream_{nullptr};
    std::mutex mutex_;
};

#endif  // RAWFILE_REQUEST_H
```

main/cpp/rawfile_request.cpp
```
#include "rawfile_request.h"

#include "threads.h"

#include "hilog/log.h"
#include "rawfile/raw_file.h"
#include "rawfile/raw_file_manager.h"

#undef LOG_TAG
#define LOG_TAG "ss-handler"

namespace {

uint8_t buffer[1024];
cnd_t http_body_cnd;
mtx_t http_body_mtx;

// HttpBodyStream的读回调。
void ReadCallback(const ArkWeb_HttpBodyStream  *httpBodyStream, uint8_t* buffer, int bytesRead)
{
    OH_LOG_INFO(LOG_APP, "read http body back.");
    bool isEof = OH_ArkWebHttpBodyStream_IsEof(httpBodyStream);
    if (!isEof && bytesRead != 0) {
        memset(buffer, 0, 1000);
        OH_ArkWebHttpBodyStream_Read(httpBodyStream, buffer, 1000);
    } else {
        RawfileRequest *rawfileRequest = (RawfileRequest *)OH_ArkWebHttpBodyStream_GetUserData(httpBodyStream);
        if (rawfileRequest) {
            rawfileRequest->ReadRawfileDataOnWorkerThread();
            cnd_signal(&http_body_cnd);
        }
    }
}

int ReadHttpBodyOnWorkerThread(void* userData)
{
    memset(buffer, 0, 1000);
    ArkWeb_HttpBodyStream *httpBodyStream = (ArkWeb_HttpBodyStream *)userData;
    OH_ArkWebHttpBodyStream_Read(httpBodyStream, buffer, 1000);
    cnd_init(&http_body_cnd);
    mtx_init(&http_body_mtx, mtx_plain);
    cnd_wait(&http_body_cnd, &http_body_mtx);
    return 0;
}

int ReadRawfileOnWorkerThread(void* userData)
{
    RawfileRequest * rawfileRequest = (RawfileRequest *)userData;
    if (rawfileRequest) {
        rawfileRequest->ReadRawfileDataOnWorkerThread();
    }
    return 0;
}

// ArkWeb_HttpBodyStream 的初始化回调。
void InitCallback(const ArkWeb_HttpBodyStream *httpBodyStream, ArkWeb_NetError result)
{
    OH_LOG_INFO(LOG_APP, "init http body stream done %{public}d.", result);
    bool isChunked = OH_ArkWebHttpBodyStream_IsChunked(httpBodyStream);
    OH_LOG_INFO(LOG_APP, "http body stream is chunked %{public}d.", isChunked);
    thrd_t th;
    if (thrd_create(&th, ReadHttpBodyOnWorkerThread, (void *)httpBodyStream) != thrd_success) {
        OH_LOG_ERROR(LOG_APP, "create thread failed.");
        return;
    }

    if (thrd_detach(th) != thrd_success) {
        OH_LOG_ERROR(LOG_APP, "detach thread failed.");
    }
}

const int blockSize = 1024 * 8;

}  // namespace

RawfileRequest::RawfileRequest(const ArkWeb_ResourceRequest *resourceRequest,
                               const ArkWeb_ResourceHandler *resourceHandler,
                               const NativeResourceManager* resourceManager)
        : resourceRequest_(resourceRequest),
          resourceHandler_(resourceHandler),
          resourceManager_(resourceManager) {}

RawfileRequest::~RawfileRequest() {}

void RawfileRequest::Start()
{
    OH_LOG_INFO(LOG_APP, "start a rawfile request.");
    char* url;
    OH_ArkWebResourceRequest_GetUrl(resourceRequest_, &url);
    std::string urlStr(url);
    std::size_t position = urlStr.rfind('/');
    if (position != std::string::npos) {
        rawfilePath_ = urlStr.substr(position + 1);
    }
    OH_ArkWeb_ReleaseString(url);

    OH_ArkWeb_CreateResponse(&response_);
    OH_ArkWebResourceRequest_GetHttpBodyStream(resourceRequest(), &stream_);
    if (stream_) {
        OH_LOG_ERROR(LOG_APP, "have http body stream");
        OH_ArkWebHttpBodyStream_SetUserData(stream_, this);
        OH_ArkWebHttpBodyStream_SetReadCallback(stream_, ReadCallback);
        OH_ArkWebHttpBodyStream_Init(stream_, InitCallback);
    } else {
        thrd_t th;
        if (thrd_create(&th, ReadRawfileOnWorkerThread, (void *)this) != thrd_success) {
            OH_LOG_ERROR(LOG_APP, "create thread failed.");
            return;
        }

        if (thrd_detach(th) != thrd_success) {
            OH_LOG_ERROR(LOG_APP, "detach thread failed.");
        }
    }
}

// 在worker线程中读取rawfile，并通过ResourceHandler返回给内核。
void RawfileRequest::ReadRawfileDataOnWorkerThread()
{
    OH_LOG_INFO(LOG_APP, "read rawfile in worker thread.");
    const struct UrlInfo {
        std::string resource;
        std::string mimeType;
    } urlInfos[] = {
        {"test.html", "text/html"},
        {"video.html", "text/html"},
        {"isolated.html", "text/html"},
        {"csp_bypassing.html", "text/html"},
        {"post_data.html", "text/html"},
        {"chunked_post_stream.html", "text/html"},
        {"local.html", "text/html"},
        {"service_worker.html", "text/html"},
        {"csp_script.js", "text/javascript"},
        {"sw.js", "text/javascript"},
        {"isolated_script.js", "text/javascript"},
        {"local_script.js", "text/javascript"},
        {"test.mp4", "video/mp4"},
        {"xhr", "application/json"}
    };

    if (!resourceManager()) {
        OH_LOG_ERROR(LOG_APP, "read rawfile error, resource manager is nullptr.");
        return;
    }

    RawFile *rawfile = OH_ResourceManager_OpenRawFile(resourceManager(), rawfilePath().c_str());
    if (!rawfile) {
        OH_ArkWebResponse_SetStatus(response(), 404);
    } else {
        OH_ArkWebResponse_SetStatus(response(), 200);
    }

    for (auto &urlInfo : urlInfos) {
        if (urlInfo.resource == rawfilePath()) {
            OH_ArkWebResponse_SetMimeType(response(), urlInfo.mimeType.c_str());
            break;
        }
    }
    OH_ArkWebResponse_SetCharset(response(), "UTF-8");

    long len = OH_ResourceManager_GetRawFileSize(rawfile);
    OH_ArkWebResponse_SetHeaderByName(response(), "content-length", std::to_string(len).c_str(), false);
    DidReceiveResponse();

    long consumed = 0;
    uint8_t buffer[blockSize];
    while (true) {
        int ret = OH_ResourceManager_ReadRawFile(rawfile, buffer, blockSize);
        OH_LOG_INFO(LOG_APP, "read rawfile %{public}d bytes.", ret);
        if (ret == 0) {
            break;
        }
        consumed += ret;
        OH_ResourceManager_SeekRawFile(rawfile, consumed, 0);
        DidReceiveData(buffer, ret);
        memset(buffer, 0, blockSize);
    }

    OH_ResourceManager_CloseRawFile(rawfile);
    DidFinish();
}

void RawfileRequest::Stop()
{
    OH_LOG_INFO(LOG_APP, "stop the rawfile request.");
    std::lock_guard<std::mutex> guard(mutex_);
    stopped_ = true;
    if (response_) {
        OH_ArkWeb_DestroyResponse(response_);
    }
    OH_ArkWebResourceRequest_Destroy(resourceRequest_);
    OH_ArkWebResourceHandler_Destroy(resourceHandler_);
}

void RawfileRequest::DidReceiveResponse()
{
    OH_LOG_INFO(LOG_APP, "did receive response.");
    std::lock_guard<std::mutex> guard(mutex_);
    if (!stopped_) {
        OH_ArkWebResourceHandler_DidReceiveResponse(resourceHandler_, response_);
    }
}

void RawfileRequest::DidReceiveData(const uint8_t *buffer, int64_t bufLen)
{
    OH_LOG_INFO(LOG_APP, "did receive data.");
    std::lock_guard<std::mutex> guard(mutex_);
    if (!stopped_) {
        OH_ArkWebResourceHandler_DidReceiveData(resourceHandler_, buffer, bufLen);
    }
}

void RawfileRequest::DidFinish()
{
    OH_LOG_INFO(LOG_APP, "did finish.");
    std::lock_guard<std::mutex> guard(mutex_);
    if (!stopped_) {
        OH_ArkWebResourceHandler_DidFinish(resourceHandler_);
    }
}

void RawfileRequest::DidFailWithError(ArkWeb_NetError errorCode)
{
    OH_LOG_INFO(LOG_APP, "did finish with error %{public}d.", errorCode);
    if (!stopped_) {
        OH_ArkWebResourceHandler_DidFailWithError(resourceHandler_, errorCode);
    }
}
```

main/resources/rawfile/test.html
```html
<html>
<head>
<meta name="viewport" content="width=device-width,initial-scale=1">
</head>

<body>
<h1> 网络拦截测试demo</h1>
<a href="https://www.example.com/video.html">拦截视频资源请求，读取本地mp4文件</a><br/>
<a href="https://www.example.com/csp_bypassing.html">测试三方协议忽略csp检查，并成功拦截</a><br/>
<a href="https://www.example.com/isolated.html">测试拦截设置ISOLATED属性的三方协议</a><br/>
<a href="https://www.example.com/local.html">测试拦截设置LOCAL属性的三方协议</a><br/>
<a href="https://www.example.com/service_worker.html">测试拦截service worker触发的请求</a><br/>
<a href="https://www.example.com/post_data.html">测试读取blob类型http body stream</a><br/>
<a href="https://www.example.com/chunked_post_stream.html">测试读取chunked类型http body stream</a>
</body>
</html>
```

main/resources/rawfile/cat.svg
```
<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 13.37 10.79"><path d="M12.8 10.18l-.8-.8c-.98-.8-.86-1.92-.87-2.04-.02-.1-.02-.58.02-.74.04-.15 0-.32 0-.32.28-1.18 1.2-.85 1.2-.85.38.04.4-.33.4-.33.25-.13.2-.4.2-.4l-.47-.48c-.18-.48-.7-.6-.7-.6.08-.48-.17-.78-.17-.78-.03.14-.58.72-.62.73-.63.15-.43.26-.83.55-.4.28-1.26.63-1.64.43-.37-.2-3.5-.5-4.86-.5-.4 0-.7.1-.95.2-.23-.16-.52-.52-.73-1.02-.3-.74-.36-1.48-.12-1.98.13-.27.28-.42.44-.45.23-.05.52.16.6.24.17.14.42.13.56-.03.15-.15.14-.4-.02-.55C3.38.4 2.8-.1 2.14.02c-.42.08-.76.38-1 .9-.34.7-.3 1.66.1 2.6.18.44.47.93.83 1.25-.1.13-.13.23-.13.23-.12.27-.44.9-.33 1.45.13.56-.22.82-.3.88-.05.07-.73.47-.73.47L0 9.78c-.08.38.43.6.43.6.18-.03.2-.63.2-.63l.44-1.04 1.66-.6s0 .7-.02.83-.1.35-.1.35c.08.46 1.2 1.5 1.2 1.5h.85v-.26c-.07-.3-.5-.16-.5-.16l-.62-.95c.66-.5.93-1.38.93-1.38.3.26 1.8-.22 1.8-.22l.9.1-.25 2.1c-.07.5.05.68.05.68h.4c.3 0 .48.03.48-.27 0-.28-.4-.23-.4-.23l1-1.95c.93-.58 1.53.26 1.53.26l.05.3c.37.53 2.38 1.9 2.38 1.9h1v-.3c-.18-.32-.6-.2-.6-.2z"/></svg>
```

main/resources/rawfile/csp_bypassing.html
```
<html>
<head>
<meta name="viewport" content="width=device-width,initial-scale=1">
<meta http-equiv="Content-Security-Policy" content="default-src 'self'; media-src 'self'">
</head>
<body>
<p>scheme: custom-csp-bypassing</p>
<p>options: ARKWEB_SCHEME_OPTION_CSP_BYPASSING | ARKWEB_SCHEME_OPTION_STANDARD</p>
<script src="custom-csp-bypassing://www.example.com/csp_script.js"></script>
</body>
</html>
```

main/resources/rawfile/csp_script.js
```
const body = document.body;
const element = document.createElement('div');
element.textContent = 'csp_script.js bypass the csp rules';
body.appendChild(element);
```

main/resources/rawfile/isolated_script.js
```
const element = document.getElementById('isolated_test');
element.textContent = 'isolated_script.js not blocked';
```

main/resources/rawfile/isolated.html
```
<html>
<head>
<meta name="viewport" content="width=device-width,initial-scale=1">
</head>
<body>
<p>scheme: custom-isolated</p>
<p>options: ARKWEB_SCHEME_OPTION_DISPLAY_ISOLATED</p>
<div id="isolated_test">isolated_script.js 被拦截</div>
<script src="custom-isolated://www.example.com/isolated_script.js"></script>
</body>
</html>
```

main/resources/rawfile/local_script.js
```
const element = document.getElementById('local_test');
element.textContent = 'local_script.js not blocked.';
```

main/resources/rawfile/local.html
```
<html>
<head>
<meta name="viewport" content="width=device-width,initial-scale=1">
</head>
<body>
<p>scheme: custom-local</p>
<p>options: ARKWEB_SCHEME_OPTION_LOCAL</p>
<div id="local_test">local_script.js 被拦截</div>
<script src="custom-local://www.example.com/local_script.js"></script>
</body>
</html>
```

main/resources/rawfile/post_data.html
```
<html>
<head>
<meta name="viewport" content="width=device-width,initial-scale=1">
<script>
    function textPostXhr(url) {
        var formData = new FormData();
        var myBlob = new Blob(["This is my blob content"], {type : "text/plain"});
        formData.append("upload", myBlob);
        var xhr = new XMLHttpRequest();
        xhr.open('POST', url, true);
        xhr.send(formData);
        xhr.onreadystatechange = function (err) {
            console.log(err.target.status);
        }
    }
    function textPutXhr(url) {
        var formData = new FormData();
        var myBlob = new Blob(["This is my blob content"], {type : "text/plain"});
        formData.append("upload", myBlob);
        var xhr = new XMLHttpRequest();
        xhr.open('PUT', url, true);
        xhr.send(formData);
        xhr.onreadystatechange = function (err) {
            console.log(err.target.status);
        }
    }
</script>
</head>
<body>
<div onclick="textPostXhr('https://www.example.com/xhr')">test xhr post</div>
<div onclick="textPutXhr('https://www.example.com/xhr')">test xhr put</div>
</body>
</html>
```

main/resources/rawfile/service_worker.html
```
<html>
<head>
<meta name="viewport" content="width=device-width,initial-scale=1">
<script>
function registerSuccess() {
    const body = document.body;
    const element = document.createElement('div');
    element.textContent = 'register sw successful.';
    body.appendChild(element);
}

navigator.serviceWorker.register('/sw.js')
    .then(reg => registerSuccess())
    .catch(error => console.log('failed!', error))
</script>
</head>
<body>
</body>
</html>
```

main/resources/rawfile/sw.js
```
self.addEventListener('install', event => {
    console.log('v1 installing');
    event.waitUntil(
        caches.open('static-v1').then(cache => cache.add('/cat.svg'))
    );
});

self.addEventListener('activate', event => {
    console.log("v1 now redy to handle fetches.");
});
```

main/resources/rawfile/video.html
```
<html>
<head>
<meta name="viewport" content="width=device-width,initial-scale=1">
</head>
<body>
<video width="400" height="400" controls>
    <source src="https://www.example.com/test.mp4" type="video/mp4">
</video>
</body>
</html>
```

main/resources/rawfile/chunked_post_stream.html
```
<html>
<head>
<meta name="viewport" content="width=device-width,initial-scale=1">
</head>
<script>
let uploaded = 0;
let buf = new Uint8Array(1024 * 50);
let start = Date.now();
var rs = new ReadableStream({
    pull(ctrl) {
        uploaded += buf.byteLength;
        crypto.getRandomValues(buf);
        ctrl.enqueue(buf);
        if ((start + 1000) < Date.now()) ctrl.close();
    }
});

function test() {
    fetch('https://www.example.com/xhr', {
        method: 'POST',
        body: rs,
        duplex: 'half'
    }).then(r => r.json()).then(console.log);
}
</script>
<body>
<div onclick="test()">test post chunked http body.</div>
</body>
</html>
```

main/resources/rawfile/xhr
```
{}
```