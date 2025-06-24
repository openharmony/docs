# arkweb_scheme_handler.h

## 概述

声明用于拦截来自ArkWeb的请求的API。

**库：** libohweb.so

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**相关模块：** [Web](capi-web.md)

**相关示例：** <!--RP1-->[ArkWebSchemeHandler](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkWeb/ArkWebSchemeHandler)<!--RP1End-->

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkWeb_SchemeHandler_](capi-web-arkweb-schemehandler.md) | ArkWeb_SchemeHandler | 该类用于拦截指定scheme的请求。 |
| [ArkWeb_ResourceHandler_](capi-web-arkweb-resourcehandler.md) | ArkWeb_ResourceHandler | 用于被拦截的URL请求。可以通过ArkWeb_ResourceHandler发送自定义请求头以及自定义请求体。 |
| [ArkWeb_Response_](capi-web-arkweb-response.md) | ArkWeb_Response | 为被拦截的请求构造一个ArkWeb_Response。 |
| [ArkWeb_ResourceRequest_](capi-web-arkweb-resourcerequest.md) | ArkWeb_ResourceRequest | 对应内核的一个请求，可以通过OH_ArkWeb_ResourceRequest获取请求的URL、method、post data以及其他信息。 |
| [ArkWeb_RequestHeaderList_](capi-web-arkweb-requestheaderlist.md) | ArkWeb_RequestHeaderList | 请求头列表。 |
| [ArkWeb_HttpBodyStream_](capi-web-arkweb-httpbodystream.md) | ArkWeb_HttpBodyStream | 请求的上传数据。使用OH_ArkWebHttpBodyStream_接口来读取上传的数据。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkWeb_CustomSchemeOption](#arkweb_customschemeoption) | ArkWeb_CustomSchemeOption | custom scheme的配置信息。 |
| [ArkWeb_ResourceType](#arkweb_resourcetype) | ArkWeb_ResourceType | 请求的资源类型。这些常量与Chromium中的ResourceType的对应项相匹配，不应重新编号。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*ArkWeb_OnRequestStart)(const ArkWeb_SchemeHandler* schemeHandler,ArkWeb_ResourceRequest* resourceRequest,const ArkWeb_ResourceHandler* resourceHandler,bool* intercept)](#arkweb_onrequeststart) | ArkWeb_OnRequestStart | 请求开始的回调，这将在IO线程上被调用。 |
| [typedef void (\*ArkWeb_OnRequestStop)(const ArkWeb_SchemeHandler* schemeHandler,const ArkWeb_ResourceRequest* resourceRequest)](#arkweb_onrequeststop) | ArkWeb_OnRequestStop | 请求完成时的回调函数。这将在IO线程上被调用。<br>应该使用ArkWeb_ResourceRequest_Destroy销毁resourceRequest，<br>并使用ArkWeb_ResourceHandler_Destroy销毁在ArkWeb_OnRequestStart中接收到的ArkWeb_ResourceHandler。 |
| [typedef void (\*ArkWeb_HttpBodyStreamReadCallback)(const ArkWeb_HttpBodyStream* httpBodyStream,uint8_t* buffer,int bytesRead)](#arkweb_httpbodystreamreadcallback) | ArkWeb_HttpBodyStreamReadCallback | 当OH_ArkWebHttpBodyStream_Read读取操作完成时的回调函数。 |
| [typedef void (\*ArkWeb_HttpBodyStreamInitCallback)(const ArkWeb_HttpBodyStream* httpBodyStream, ArkWeb_NetError result)](#arkweb_httpbodystreaminitcallback) | ArkWeb_HttpBodyStreamInitCallback | ArkWeb_HttpBodyStream初始化操作完成时回调函数。 |
| [void OH_ArkWebRequestHeaderList_Destroy(ArkWeb_RequestHeaderList* requestHeaderList)](#oh_arkwebrequestheaderlist_destroy) | - | 销毁ArkWeb_RequestHeaderList对象。 |
| [int32_t OH_ArkWebRequestHeaderList_GetSize(const ArkWeb_RequestHeaderList* requestHeaderList)](#oh_arkwebrequestheaderlist_getsize) | - | 获取请求头列表的大小。 |
| [void OH_ArkWebRequestHeaderList_GetHeader(const ArkWeb_RequestHeaderList* requestHeaderList,int32_t index,char** key,char** value)](#oh_arkwebrequestheaderlist_getheader) | - | 获取指定的请求头。 |
| [int32_t OH_ArkWebResourceRequest_SetUserData(ArkWeb_ResourceRequest* resourceRequest, void* userData)](#oh_arkwebresourcerequest_setuserdata) | - | 将一个用户数据设置到ArkWeb_ResourceRequest对象中。 |
| [void* OH_ArkWebResourceRequest_GetUserData(const ArkWeb_ResourceRequest* resourceRequest)](#oh_arkwebresourcerequest_getuserdata) | - | 从ArkWeb_ResourceRequest获取用户数据。 |
| [void OH_ArkWebResourceRequest_GetMethod(const ArkWeb_ResourceRequest* resourceRequest, char** method)](#oh_arkwebresourcerequest_getmethod) | - | 获取请求的method。 |
| [void OH_ArkWebResourceRequest_GetUrl(const ArkWeb_ResourceRequest* resourceRequest, char** url)](#oh_arkwebresourcerequest_geturl) | - | 获取请求的url。 |
| [void OH_ArkWebResourceRequest_GetHttpBodyStream(const ArkWeb_ResourceRequest* resourceRequest,ArkWeb_HttpBodyStream** httpBodyStream)](#oh_arkwebresourcerequest_gethttpbodystream) | - | 创建一个ArkWeb_HttpBodyStream，用于读取请求的上传数据。 |
| [void OH_ArkWebResourceRequest_DestroyHttpBodyStream(ArkWeb_HttpBodyStream* httpBodyStream)](#oh_arkwebresourcerequest_destroyhttpbodystream) | - | 销毁ArkWeb_HttpBodyStream对象。 |
| [int32_t OH_ArkWebResourceRequest_GetResourceType(const ArkWeb_ResourceRequest* resourceRequest)](#oh_arkwebresourcerequest_getresourcetype) | - | 获取请求的资源类型。 |
| [void OH_ArkWebResourceRequest_GetFrameUrl(const ArkWeb_ResourceRequest* resourceRequest, char** frameUrl)](#oh_arkwebresourcerequest_getframeurl) | - | 获取触发此请求的Frame的URL。 |
| [int32_t OH_ArkWebHttpBodyStream_SetUserData(ArkWeb_HttpBodyStream* httpBodyStream, void* userData)](#oh_arkwebhttpbodystream_setuserdata) | - | 将一个用户数据设置到ArkWeb_HttpBodyStream对象中。 |
| [void* OH_ArkWebHttpBodyStream_GetUserData(const ArkWeb_HttpBodyStream* httpBodyStream)](#oh_arkwebhttpbodystream_getuserdata) | - | 从ArkWeb_HttpBodyStream获取用户数据。 |
| [int32_t OH_ArkWebHttpBodyStream_SetReadCallback(ArkWeb_HttpBodyStream* httpBodyStream,ArkWeb_HttpBodyStreamReadCallback readCallback)](#oh_arkwebhttpbodystream_setreadcallback) | - | 为OH_ArkWebHttpBodyStream_Read设置回调函数。OH_ArkWebHttpBodyStream_Read的结果将通过readCallback通知给调用者。<br>该回调函数将在与OH_ArkWebHttpBodyStream_Read相同的线程中运行。 |
| [int32_t OH_ArkWebHttpBodyStream_Init(ArkWeb_HttpBodyStream* httpBodyStream,ArkWeb_HttpBodyStreamInitCallback initCallback)](#oh_arkwebhttpbodystream_init) | - | 初始化ArkWeb_HttpBodyStream。在调用任何其他函数之前，必须调用此函数。该接口需要在IO线程调用。 |
| [void OH_ArkWebHttpBodyStream_Read(const ArkWeb_HttpBodyStream* httpBodyStream, uint8_t* buffer, int bufLen)](#oh_arkwebhttpbodystream_read) | - | 将请求的上传数据读取到buffer。buffer的大小必须大于bufLen。我们将从工作线程读取数据到buffer，因此在回调函数返回之前，不应在其他线程中使用buffer，以避免并发问题。 |
| [uint64_t OH_ArkWebHttpBodyStream_GetSize(const ArkWeb_HttpBodyStream* httpBodyStream)](#oh_arkwebhttpbodystream_getsize) | - | 获取httpBodyStream的大小。当数据以分块的形式传输或httpBodyStream无效时，始终返回0。 |
| [uint64_t OH_ArkWebHttpBodyStream_GetPosition(const ArkWeb_HttpBodyStream* httpBodyStream)](#oh_arkwebhttpbodystream_getposition) | - | 获取httpBodyStream当前的读取位置。 |
| [bool OH_ArkWebHttpBodyStream_IsChunked(const ArkWeb_HttpBodyStream* httpBodyStream)](#oh_arkwebhttpbodystream_ischunked) | - | 获取httpBodyStream是否采用分块传输。 |
| [bool OH_ArkWebHttpBodyStream_IsEof(const ArkWeb_HttpBodyStream* httpBodyStream)](#oh_arkwebhttpbodystream_iseof) | - | 如果httpBodyStream中的所有数据都已被读取，则返回true。对于分块传输类型的httpBodyStream，在第一次读取尝试之前返回false。 |
| [bool OH_ArkWebHttpBodyStream_IsInMemory(const ArkWeb_HttpBodyStream* httpBodyStream)](#oh_arkwebhttpbodystream_isinmemory) | - | 如果httpBodyStream中的上传数据完全在内存中，并且所有读取请求都将同步成功，则返回true。对于分块传输类型的数据，预期返回false。 |
| [int32_t OH_ArkWebResourceRequest_Destroy(const ArkWeb_ResourceRequest* resourceRequest)](#oh_arkwebresourcerequest_destroy) | - | 销毁ArkWeb_ResourceRequest对象。 |
| [void OH_ArkWebResourceRequest_GetReferrer(const ArkWeb_ResourceRequest* resourceRequest, char** referrer)](#oh_arkwebresourcerequest_getreferrer) | - | 获取请求的Referrer。 |
| [void OH_ArkWebResourceRequest_GetRequestHeaders(const ArkWeb_ResourceRequest* resourceRequest,ArkWeb_RequestHeaderList** requestHeaderList)](#oh_arkwebresourcerequest_getrequestheaders) | - | 获取请求的请求头列表OH_ArkWeb_RequestHeaderList。 |
| [bool OH_ArkWebResourceRequest_IsRedirect(const ArkWeb_ResourceRequest* resourceRequest)](#oh_arkwebresourcerequest_isredirect) | - | 判断这是否是一个重定向请求。 |
| [bool OH_ArkWebResourceRequest_IsMainFrame(const ArkWeb_ResourceRequest* resourceRequest)](#oh_arkwebresourcerequest_ismainframe) | - | 判断这是否是主框架文档资源的请求。 |
| [bool OH_ArkWebResourceRequest_HasGesture(const ArkWeb_ResourceRequest* resourceRequest)](#oh_arkwebresourcerequest_hasgesture) | - | 判断这是否是一个由用户手势触发的请求。 |
| [int32_t OH_ArkWeb_RegisterCustomSchemes(const char* scheme, int32_t option)](#oh_arkweb_registercustomschemes) | - | 将custom scheme注册到ArkWeb。对于内置的HTTP、HTTPS、FILE、FTP、ABOUT和DATA协议，不应调用此函数。<br>此函数应在主线程上调用并且需要在内核初始化之前调用。 |
| [bool OH_ArkWebServiceWorker_SetSchemeHandler(const char* scheme, ArkWeb_SchemeHandler* schemeHandler)](#oh_arkwebserviceworker_setschemehandler) | - | 为指定scheme设置一个ArkWeb_SchemeHandler以拦截ServiceWorker触发的该scheme类型的请求。应该在创建BrowserContext之后设置SchemeHandler。<br>可以使用WebviewController.initializeWebEngine来初始化BrowserContext而无需创建ArkWeb。 |
| [bool OH_ArkWeb_SetSchemeHandler(const char* scheme, const char* webTag, ArkWeb_SchemeHandler* schemeHandler)](#oh_arkweb_setschemehandler) | - | 为指定scheme设置一个ArkWeb_SchemeHandler以拦截该scheme类型的请求。应该在创建BrowserContext之后设置SchemeHandler。<br>可以使用WebviewController.initializeWebEngine来初始化BrowserContext而无需创建ArkWeb。 |
| [int32_t OH_ArkWebServiceWorker_ClearSchemeHandlers()](#oh_arkwebserviceworker_clearschemehandlers) | - | 清除为ServiceWorker注册的SchemeHandler。 |
| [int32_t OH_ArkWeb_ClearSchemeHandlers(const char* webTag)](#oh_arkweb_clearschemehandlers) | - | 清除为指定web注册的SchemeHandler。 |
| [void OH_ArkWeb_CreateSchemeHandler(ArkWeb_SchemeHandler** schemeHandler)](#oh_arkweb_createschemehandler) | - | 创建一个ArkWeb_SchemeHandler对象。 |
| [void OH_ArkWeb_DestroySchemeHandler(ArkWeb_SchemeHandler* schemeHandler)](#oh_arkweb_destroyschemehandler) | - | 销毁一个ArkWeb_SchemeHandler对象。 |
| [int32_t OH_ArkWebSchemeHandler_SetUserData(ArkWeb_SchemeHandler* schemeHandler, void* userData)](#oh_arkwebschemehandler_setuserdata) | - | 将一个用户数据设置到ArkWeb_SchemeHandler对象中。 |
| [void* OH_ArkWebSchemeHandler_GetUserData(const ArkWeb_SchemeHandler* schemeHandler)](#oh_arkwebschemehandler_getuserdata) | - | 从ArkWeb_SchemeHandler获取用户数据。 |
| [int32_t OH_ArkWebSchemeHandler_SetOnRequestStart(ArkWeb_SchemeHandler* schemeHandler,ArkWeb_OnRequestStart onRequestStart)](#oh_arkwebschemehandler_setonrequeststart) | - | 为SchemeHandler设置OnRequestStart回调。 |
| [int32_t OH_ArkWebSchemeHandler_SetOnRequestStop(ArkWeb_SchemeHandler* schemeHandler,ArkWeb_OnRequestStop onRequestStop)](#oh_arkwebschemehandler_setonrequeststop) | - | 为SchemeHandler设置OnRequestStop回调。 |
| [void OH_ArkWeb_CreateResponse(ArkWeb_Response** response)](#oh_arkweb_createresponse) | - | 为被拦截的请求创建一个ArkWeb_Response对象。 |
| [void OH_ArkWeb_DestroyResponse(ArkWeb_Response* response)](#oh_arkweb_destroyresponse) | - | 销毁一个ArkWeb_Response对象。 |
| [int32_t OH_ArkWebResponse_SetUrl(ArkWeb_Response* response, const char* url)](#oh_arkwebresponse_seturl) | - | 设置经过重定向或由于HSTS而改变后的解析URL，设置后会触发跳转。 |
| [void OH_ArkWebResponse_GetUrl(const ArkWeb_Response* response, char** url)](#oh_arkwebresponse_geturl) | - | 获取经过重定向或由于HSTS而更改后的解析URL。 |
| [int32_t OH_ArkWebResponse_SetError(ArkWeb_Response* response, ArkWeb_NetError errorCode)](#oh_arkwebresponse_seterror) | - | 给ArkWeb_Response对象设置一个错误码。 |
| [ArkWeb_NetError OH_ArkWebResponse_GetError(const ArkWeb_Response* response)](#oh_arkwebresponse_geterror) | - | 获取ArkWeb_Response的错误码。 |
| [int32_t OH_ArkWebResponse_SetStatus(ArkWeb_Response* response, int status)](#oh_arkwebresponse_setstatus) | - | 为ArkWeb_Response对象设置一个HTTP状态码。 |
| [int OH_ArkWebResponse_GetStatus(const ArkWeb_Response* response)](#oh_arkwebresponse_getstatus) | - | 获取ArkWeb_Response的HTTP状态码。 |
| [int32_t OH_ArkWebResponse_SetStatusText(ArkWeb_Response* response, const char* statusText)](#oh_arkwebresponse_setstatustext) | - | 为ArkWeb_Response设置状态文本。 |
| [void OH_ArkWebResponse_GetStatusText(const ArkWeb_Response* response, char** statusText)](#oh_arkwebresponse_getstatustext) | - | 获取ArkWeb_Response的状态文本。 |
| [int32_t OH_ArkWebResponse_SetMimeType(ArkWeb_Response* response, const char* mimeType)](#oh_arkwebresponse_setmimetype) | - | 为ArkWeb_Response设置媒体类型。 |
| [void OH_ArkWebResponse_GetMimeType(const ArkWeb_Response* response, char** mimeType)](#oh_arkwebresponse_getmimetype) | - | 获取ArkWeb_Response的媒体类型。 |
| [int32_t OH_ArkWebResponse_SetCharset(ArkWeb_Response* response, const char* charset)](#oh_arkwebresponse_setcharset) | - | 为ArkWeb_Response设置字符集。 |
| [void OH_ArkWebResponse_GetCharset(const ArkWeb_Response* response, char** charset)](#oh_arkwebresponse_getcharset) | - | 获取ArkWeb_Response的字符集。 |
| [int32_t OH_ArkWebResponse_SetHeaderByName(ArkWeb_Response* response,const char* name,const char* value,bool overwrite)](#oh_arkwebresponse_setheaderbyname) | - | 为ArkWeb_Response设置一个header。 |
| [void OH_ArkWebResponse_GetHeaderByName(const ArkWeb_Response* response, const char* name, char** value)](#oh_arkwebresponse_getheaderbyname) | - | 从ArkWeb_Response中获取header。 |
| [int32_t OH_ArkWebResourceHandler_Destroy(const ArkWeb_ResourceHandler* resourceHandler)](#oh_arkwebresourcehandler_destroy) | - | 销毁一个ArkWeb_ResourceHandler对象。 |
| [int32_t OH_ArkWebResourceHandler_DidReceiveResponse(const ArkWeb_ResourceHandler* resourceHandler,const ArkWeb_Response* response)](#oh_arkwebresourcehandler_didreceiveresponse) | - | 将构造的响应头传递给被拦截的请求。 |
| [int32_t OH_ArkWebResourceHandler_DidReceiveData(const ArkWeb_ResourceHandler* resourceHandler,const uint8_t* buffer,int64_t bufLen)](#oh_arkwebresourcehandler_didreceivedata) | - | 将构造的响应体传递给被拦截的请求。 |
| [int32_t OH_ArkWebResourceHandler_DidFinish(const ArkWeb_ResourceHandler* resourceHandler)](#oh_arkwebresourcehandler_didfinish) | - | 通知ArkWeb内核被拦截的请求已经完成，并且没有更多的数据可用。 |
| [int32_t OH_ArkWebResourceHandler_DidFailWithError(const ArkWeb_ResourceHandler* resourceHandler,ArkWeb_NetError errorCode)](#oh_arkwebresourcehandler_didfailwitherror) | - | 通知ArkWeb内核被拦截请求应该失败。 |
| [void OH_ArkWeb_ReleaseString(char* string)](#oh_arkweb_releasestring) | - | 释放由NDK接口创建的字符串。 |
| [void OH_ArkWeb_ReleaseByteArray(uint8_t* byteArray)](#oh_arkweb_releasebytearray) | - | 释放由NDK接口创建的字节数组。 |

## 枚举类型说明

### ArkWeb_CustomSchemeOption

```
enum ArkWeb_CustomSchemeOption
```

**描述：**

custom scheme的配置信息。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKWEB_SCHEME_OPTION_STANDARD = 1 << 0 | 如果设置了ARKWEB_SCHEME_OPTION_STANDARD，那么该scheme将被视为标准scheme来处理。 |
| ARKWEB_SCHEME_OPTION_LOCAL = 1 << 1 | 如果设置了ARKWEB_SCHEME_OPTION_LOCAL，则将使用与“file” URL相同的安全规则来处理该scheme。 |
| ARKWEB_SCHEME_OPTION_DISPLAY_ISOLATED = 1 << 2 | 如果设置了ARKWEB_SCHEME_OPTION_DISPLAY_ISOLATED，则该scheme的请求只能由使用相同scheme加载的页面中发起。 |
| ARKWEB_SCHEME_OPTION_SECURE = 1 << 3 | 如果设置了ARKWEB_SCHEME_OPTION_SECURE，则将使用与“https” URL相同的安全规则来处理该scheme。 |
| ARKWEB_SCHEME_OPTION_CORS_ENABLED = 1 << 4 | 如果设置了ARKWEB_SCHEME_OPTION_CORS_ENABLED，则该scheme可以发送CORS请求。在大多数情况下，当设置了ARKWEB_SCHEME_OPTION_STANDARD时，应该设置此值。 |
| ARKWEB_SCHEME_OPTION_CSP_BYPASSING = 1 << 5 | 如果设置了ARKWEB_SCHEME_OPTION_CSP_BYPASSING，则该scheme可以绕过内容安全策略（CSP）检查。 |
| ARKWEB_SCHEME_OPTION_FETCH_ENABLED = 1 << 6 | 如果设置了ARKWEB_SCHEME_OPTION_FETCH_ENABLED，则可以发起该scheme的FETCH API请求。 |
| ARKWEB_SCHEME_OPTION_CODE_CACHE_ENABLED = 1 << 7 | 如果设置了ARKWEB_SCHEME_OPTION_CODE_CACHE_ENABLED，则该scheme的js资源支持生成code cache。 |

### ArkWeb_ResourceType

```
enum ArkWeb_ResourceType
```

**描述：**

请求的资源类型。这些常量与Chromium中的ResourceType的对应项相匹配，不应重新编号。<br>

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| MAIN_FRAME = 0 | 顶层页面。 |
| SUB_FRAME = 1 | Frame或Iframe。 |
| STYLE_SHEET = 2 | CSS样式表。 |
| SCRIPT = 3 | 外部脚本。 |
| IMAGE = 4 | 图片（jpg/gif/png/以及其他）。 |
| FONT_RESOURCE = 5 | 字体。 |
| SUB_RESOURCE = 6 | 其他子资源。如果实际类型未知，则是默认类型。 |
| OBJECT = 7 | 插件的Object（或embed）标签，或者插件请求的资源。 |
| MEDIA = 8 | 媒体资源。 |
| WORKER = 9 | 专用工作线程的主资源。 |
| SHARED_WORKER = 10 | 共享工作线程的主资源。 |
| PREFETCH = 11 | 明确的预取请求。 |
| FAVICON = 12 | 网站图标。 |
| XHR = 13 | XMLHttpRequest。 |
| PING = 14 | /sendBeacon的Ping请求。 |
| SERVICE_WORKER = 15 | service worker的主资源。 |
| CSP_REPORT = 16 | 内容安全策略违规报告。 |
| PLUGIN_RESOURCE = 17 | 插件请求的资源。 |
| NAVIGATION_PRELOAD_MAIN_FRAME = 19 | 触发service worker预热的主frame跳转请求。 |
| NAVIGATION_PRELOAD_SUB_FRAME = 20 | 触发service worker预热的子frame跳转请求。 |


## 函数说明

### ArkWeb_OnRequestStart()

```
typedef void (*ArkWeb_OnRequestStart)(const ArkWeb_SchemeHandler* schemeHandler,ArkWeb_ResourceRequest* resourceRequest,const ArkWeb_ResourceHandler* resourceHandler,bool* intercept)
```

**描述：**

请求开始的回调，这将在IO线程上被调用。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项                                                                        | 描述 |
|----------------------------------------------------------------------------| -- |
| const [ArkWeb_SchemeHandler](capi-web-arkweb-schemehandler.md)* schemeHandler | ArkWeb_SchemeHandler。 |
| [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | 通过该对象获取请求的信息。 |
| const [ArkWeb_ResourceHandler](capi-web-arkweb-resourcehandler.md)* resourceHandler                          | 请求的ArkWeb_ResourceHandler。如果intercept设置为false，则不应使用它。 |
| bool* intercept                                                            | 如果为true，则会拦截请求；如果为false，则不会拦截。 |

### ArkWeb_OnRequestStop()

```
typedef void (*ArkWeb_OnRequestStop)(const ArkWeb_SchemeHandler* schemeHandler,const ArkWeb_ResourceRequest* resourceRequest)
```

**描述：**

请求完成时的回调函数。这将在IO线程上被调用。

应该使用ArkWeb_ResourceRequest_Destroy销毁resourceRequest，并使用ArkWeb_ResourceHandler_Destroy销毁在ArkWeb_OnRequestStart中接收到的ArkWeb_ResourceHandler。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_SchemeHandler](capi-web-arkweb-schemehandler.md)* schemeHandler | ArkWeb_SchemeHandler。 |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | ArkWeb_ResourceRequest。 |

### ArkWeb_HttpBodyStreamReadCallback()

```
typedef void (*ArkWeb_HttpBodyStreamReadCallback)(const ArkWeb_HttpBodyStream* httpBodyStream,uint8_t* buffer,int bytesRead)
```

**描述：**

当OH_ArkWebHttpBodyStream_Read读取操作完成时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项                                             | 描述 |
|-------------------------------------------------| -- |
| const [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | ArkWeb_HttpBodyStream。 |
| uint8_t* buffer                                 | 接收数据的buffer。 |
| int bytesRead                                   | OH_ArkWebHttpBodyStream_Read后的回调函数。如果bytesRead大于0，则表示buffer已填充了bytesRead大小的数据。调用者可以从buffer中读取数据，如果OH_ArkWebHttpBodyStream_IsEOF为false，则调用者可以继续读取剩余的数据。 |

### ArkWeb_HttpBodyStreamInitCallback()

```
typedef void (*ArkWeb_HttpBodyStreamInitCallback)(const ArkWeb_HttpBodyStream* httpBodyStream, ArkWeb_NetError result)
```

**描述：**

ArkWeb_HttpBodyStream初始化操作完成时回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数：**

| 参数项                                                                           | 描述 |
|-------------------------------------------------------------------------------| -- |
| const [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | ArkWeb_HttpBodyStream。 |
| [ArkWeb_NetError](capi-arkweb-net-error-list-h.md#arkweb_neterror) result     | 成功时返回ARKWEB_NET_OK，否则请参考[arkweb_net_error_list.h](capi-arkweb-net-error-list-h.md)。 |

### OH_ArkWebRequestHeaderList_Destroy()

```
void OH_ArkWebRequestHeaderList_Destroy(ArkWeb_RequestHeaderList* requestHeaderList)
```

**描述：**

销毁ArkWeb_RequestHeaderList对象。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkWeb_RequestHeaderList](capi-web-arkweb-requestheaderlist.md)* requestHeaderList | 将被销毁的ArkWeb_RequestHeaderList。 |

### OH_ArkWebRequestHeaderList_GetSize()

```
int32_t OH_ArkWebRequestHeaderList_GetSize(const ArkWeb_RequestHeaderList* requestHeaderList)
```

**描述：**

获取请求头列表的大小。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_RequestHeaderList](capi-web-arkweb-requestheaderlist.md)* requestHeaderList | 请求头的列表。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 请求头的大小。如果requestHeaderList无效，则为-1。 |

### OH_ArkWebRequestHeaderList_GetHeader()

```
void OH_ArkWebRequestHeaderList_GetHeader(const ArkWeb_RequestHeaderList* requestHeaderList,int32_t index,char** key,char** value)
```

**描述：**

获取指定的请求头。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const ArkWeb_RequestHeaderList* requestHeaderList | 请求头列表。 |
| int32_t index | 请求头的索引。 |
| char** key | 请求头的键（key）。调用者必须使用OH_ArkWeb_ReleaseString函数来释放这个字符串。 |
| char** value | 请求头的值（value）。调用者必须使用OH_ArkWeb_ReleaseString函数来释放这个字符串。 |

### OH_ArkWebResourceRequest_SetUserData()

```
int32_t OH_ArkWebResourceRequest_SetUserData(ArkWeb_ResourceRequest* resourceRequest, void* userData)
```

**描述：**

将一个用户数据设置到ArkWeb_ResourceRequest对象中。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | ArkWeb_ResourceRequest。 |
| void* userData | 将要设置的用户数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果返回0，表示成功；返回17100101，表示参数无效。 |

### OH_ArkWebResourceRequest_GetUserData()

```
void* OH_ArkWebResourceRequest_GetUserData(const ArkWeb_ResourceRequest* resourceRequest)
```

**描述：**

从ArkWeb_ResourceRequest获取用户数据。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | ArkWeb_ResourceRequest。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| void* | 设置的用户数据。 |

### OH_ArkWebResourceRequest_GetMethod()

```
void OH_ArkWebResourceRequest_GetMethod(const ArkWeb_ResourceRequest* resourceRequest, char** method)
```

**描述：**

获取请求的method。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | ArkWeb_ResourceRequest。 |
| char** method | HTTP请求方法。此函数将为method字符串分配内存，调用者必须使用OH_ArkWeb_ReleaseString释放字符串。 |

### OH_ArkWebResourceRequest_GetUrl()

```
void OH_ArkWebResourceRequest_GetUrl(const ArkWeb_ResourceRequest* resourceRequest, char** url)
```

**描述：**

获取请求的url。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | ArkWeb_ResourceRequest。 |
| char** url | 请求的URL。此函数将为URL字符串分配内存，调用者必须通过OH_ArkWeb_ReleaseString释放该字符串。 |

### OH_ArkWebResourceRequest_GetHttpBodyStream()

```
void OH_ArkWebResourceRequest_GetHttpBodyStream(const ArkWeb_ResourceRequest* resourceRequest,ArkWeb_HttpBodyStream** httpBodyStream)
```

**描述：**

创建一个ArkWeb_HttpBodyStream，用于读取请求的上传数据。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | ArkWeb_ResourceRequest。 |
| [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)** httpBodyStream | 请求的上传数据。此函数将为httpBodyStream分配内存，调用者必须使用OH_ArkWebResourceRequest_DestroyHttpBodyStream释放httpBodyStream。 |

### OH_ArkWebResourceRequest_DestroyHttpBodyStream()

```
void OH_ArkWebResourceRequest_DestroyHttpBodyStream(ArkWeb_HttpBodyStream* httpBodyStream)
```

**描述：**

销毁ArkWeb_HttpBodyStream对象。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | 待销毁的httpBodyStream。 |

### OH_ArkWebResourceRequest_GetResourceType()

```
int32_t OH_ArkWebResourceRequest_GetResourceType(const ArkWeb_ResourceRequest* resourceRequest)
```

**描述：**

获取请求的资源类型。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | ArkWeb_ResourceRequest。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 请求的资源类型。如果resourceRequest无效，则为-1。 |

### OH_ArkWebResourceRequest_GetFrameUrl()

```
void OH_ArkWebResourceRequest_GetFrameUrl(const ArkWeb_ResourceRequest* resourceRequest, char** frameUrl)
```

**描述：**

获取触发此请求的Frame的URL。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | ArkWeb_ResourceRequest。 |
| char** frameUrl | 触发此请求的Frame的URL。此函数将为URL字符串分配内存，并且调用者必须通过OH_ArkWeb_ReleaseString来释放该字符串。 |

### OH_ArkWebHttpBodyStream_SetUserData()

```
int32_t OH_ArkWebHttpBodyStream_SetUserData(ArkWeb_HttpBodyStream* httpBodyStream, void* userData)
```

**描述：**

将一个用户数据设置到ArkWeb_HttpBodyStream对象中。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | ArkWeb_HttpBodyStream。 |
| void* userData | 要设置的用户数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果返回0，表示成功；返回17100101，表示参数无效。 |

### OH_ArkWebHttpBodyStream_GetUserData()

```
void* OH_ArkWebHttpBodyStream_GetUserData(const ArkWeb_HttpBodyStream* httpBodyStream)
```

**描述：**

从ArkWeb_HttpBodyStream获取用户数据。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | ArkWeb_HttpBodyStream。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| void* | 设置的用户数据。 |

### OH_ArkWebHttpBodyStream_SetReadCallback()

```
int32_t OH_ArkWebHttpBodyStream_SetReadCallback(ArkWeb_HttpBodyStream* httpBodyStream,ArkWeb_HttpBodyStreamReadCallback readCallback)
```

**描述：**

为OH_ArkWebHttpBodyStream_Read设置回调函数。OH_ArkWebHttpBodyStream_Read的结果将通过readCallback通知给调用者。<br>该回调函数将在与OH_ArkWebHttpBodyStream_Read相同的线程中运行。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | ArkWeb_HttpBodyStream。 |
| [ArkWeb_HttpBodyStreamReadCallback](#arkweb_httpbodystreamreadcallback) readCallback | OH_ArkWebHttpBodyStream_Read的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果返回0，表示成功；返回17100101，表示参数无效。 |

### OH_ArkWebHttpBodyStream_Init()

```
int32_t OH_ArkWebHttpBodyStream_Init(ArkWeb_HttpBodyStream* httpBodyStream,ArkWeb_HttpBodyStreamInitCallback initCallback)
```

**描述：**

初始化ArkWeb_HttpBodyStream。在调用任何其他函数之前，必须调用此函数。该接口需要在IO线程调用。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | ArkWeb_HttpBodyStream。 |
| [ArkWeb_HttpBodyStreamInitCallback](#arkweb_httpbodystreaminitcallback) initCallback | 初始化的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果返回0，表示成功；返回17100101，表示参数无效。 |

### OH_ArkWebHttpBodyStream_Read()

```
void OH_ArkWebHttpBodyStream_Read(const ArkWeb_HttpBodyStream* httpBodyStream, uint8_t* buffer, int bufLen)
```

**描述：**

将请求的上传数据读取到buffer。buffer的大小必须大于bufLen。我们将从工作线程读取数据到buffer，因此在回调函数返回之前，不应在其他线程中使用buffer，以避免并发问题。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | ArkWeb_HttpBodyStream。 |
| uint8_t* buffer | 接收数据的buffer。 |
| int bufLen | 要读取的字节的大小。 |

### OH_ArkWebHttpBodyStream_GetSize()

```
uint64_t OH_ArkWebHttpBodyStream_GetSize(const ArkWeb_HttpBodyStream* httpBodyStream)
```

**描述：**

获取httpBodyStream的大小。当数据以分块的形式传输或httpBodyStream无效时，始终返回0。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | ArkWeb_HttpBodyStream。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint64_t | httpBodyStream的大小。 |

### OH_ArkWebHttpBodyStream_GetPosition()

```
uint64_t OH_ArkWebHttpBodyStream_GetPosition(const ArkWeb_HttpBodyStream* httpBodyStream)
```

**描述：**

获取httpBodyStream当前的读取位置。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | ArkWeb_HttpBodyStream。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint64_t | httpBodyStream当前的读取位置。如果httpBodyStream无效，则位置为0。 |

### OH_ArkWebHttpBodyStream_IsChunked()

```
bool OH_ArkWebHttpBodyStream_IsChunked(const ArkWeb_HttpBodyStream* httpBodyStream)
```

**描述：**

获取httpBodyStream是否采用分块传输。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | ArkWeb_HttpBodyStream。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果采用分块传输则返回true;否则返回false。 |

### OH_ArkWebHttpBodyStream_IsEof()

```
bool OH_ArkWebHttpBodyStream_IsEof(const ArkWeb_HttpBodyStream* httpBodyStream)
```

**描述：**

如果httpBodyStream中的所有数据都已被读取，则返回true。对于分块传输类型的httpBodyStream，在第一次读取尝试之前返回false。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | ArkWeb_HttpBodyStream。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果所有数据都已被读取则返回true；否则返回false。 |

### OH_ArkWebHttpBodyStream_IsInMemory()

```
bool OH_ArkWebHttpBodyStream_IsInMemory(const ArkWeb_HttpBodyStream* httpBodyStream)
```

**描述：**

如果httpBodyStream中的上传数据完全在内存中，并且所有读取请求都将同步成功，则返回true。对于分块传输类型的数据，预期返回false。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | ArkWeb_HttpBodyStream。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果上传数据完全在内存中则返回true；否则返回false。 |

### OH_ArkWebResourceRequest_Destroy()

```
int32_t OH_ArkWebResourceRequest_Destroy(const ArkWeb_ResourceRequest* resourceRequest)
```

**描述：**

销毁ArkWeb_ResourceRequest对象。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | ArkWeb_ResourceRequest。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果返回0，表示成功；返回17100101，表示参数无效。 |

### OH_ArkWebResourceRequest_GetReferrer()

```
void OH_ArkWebResourceRequest_GetReferrer(const ArkWeb_ResourceRequest* resourceRequest, char** referrer)
```

**描述：**

获取请求的Referrer。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | ArkWeb_ResourceRequest。 |
| char** referrer | 请求的Referrer。此函数将为referrer字符串分配内存，调用者必须使用 OH_ArkWeb_ReleaseString 释放该字符串。 |

### OH_ArkWebResourceRequest_GetRequestHeaders()

```
void OH_ArkWebResourceRequest_GetRequestHeaders(const ArkWeb_ResourceRequest* resourceRequest,ArkWeb_RequestHeaderList** requestHeaderList)
```

**描述：**

获取请求的请求头列表OH_ArkWeb_RequestHeaderList。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | ArkWeb_ResourceRequest。 |
| [ArkWeb_RequestHeaderList](capi-web-arkweb-requestheaderlist.md)** requestHeaderList | 请求的请求头列表。 |

### OH_ArkWebResourceRequest_IsRedirect()

```
bool OH_ArkWebResourceRequest_IsRedirect(const ArkWeb_ResourceRequest* resourceRequest)
```

**描述：**

判断这是否是一个重定向请求。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | ArkWeb_ResourceRequest。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果这是一个重定向，则返回true；否则返回false。 |

### OH_ArkWebResourceRequest_IsMainFrame()

```
bool OH_ArkWebResourceRequest_IsMainFrame(const ArkWeb_ResourceRequest* resourceRequest)
```

**描述：**

判断这是否是主框架文档资源的请求。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | ArkWeb_ResourceRequest。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果这是来自主框架，则返回true；否则返回false。 |

### OH_ArkWebResourceRequest_HasGesture()

```
bool OH_ArkWebResourceRequest_HasGesture(const ArkWeb_ResourceRequest* resourceRequest)
```

**描述：**

判断这是否是一个由用户手势触发的请求。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | ArkWeb_ResourceRequest。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果这是由用户手势触发的，则返回true；否则返回false。 |

### OH_ArkWeb_RegisterCustomSchemes()

```
int32_t OH_ArkWeb_RegisterCustomSchemes(const char* scheme, int32_t option)
```

**描述：**

将custom scheme注册到ArkWeb。对于内置的HTTP、HTTPS、FILE、FTP、ABOUT和DATA协议，不应调用此函数。此函数应在主线程上调用并且需要在内核初始化之前调用。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* scheme | 待注册的scheme。 |
| int32_t option | scheme的配置（行为）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果返回0，表示成功；返回17100100，表示未知错误；返回17100101，表示参数无效；返回17100102，表示注册scheme的配置失败，应该在创建ArkWeb之前注册。 |

### OH_ArkWebServiceWorker_SetSchemeHandler()

```
bool OH_ArkWebServiceWorker_SetSchemeHandler(const char* scheme, ArkWeb_SchemeHandler* schemeHandler)
```

**描述：**

为指定scheme设置一个ArkWeb_SchemeHandler以拦截ServiceWorker触发的该scheme类型的请求。应该在创建BrowserContext之后设置SchemeHandler。

可以使用WebviewController.initializeWebEngine来初始化BrowserContext而无需创建ArkWeb。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* scheme | 需要被拦截的scheme。 |
| [ArkWeb_SchemeHandler](capi-web-arkweb-schemehandler.md)* schemeHandler | 该scheme的拦截器ArkWeb_SchemeHandler。只有通过ServiceWorker触发的请求才会通过这个schemeHandler进行通知。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果为指定scheme设置SchemeHandler成功，则返回true，否则返回false。 |

### OH_ArkWeb_SetSchemeHandler()

```
bool OH_ArkWeb_SetSchemeHandler(const char* scheme, const char* webTag, ArkWeb_SchemeHandler* schemeHandler)
```

**描述：**

为指定scheme设置一个ArkWeb_SchemeHandler以拦截该scheme类型的请求。应该在创建BrowserContext之后设置SchemeHandler。

可以使用WebviewController.initializeWebEngine来初始化BrowserContext而无需创建ArkWeb。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* scheme | 需要被拦截的scheme。 |
| const char* webTag | Web组件的标签名称，用于标识某个唯一组件，由开发者来保证名称唯一性。 |
| [ArkWeb_SchemeHandler](capi-web-arkweb-schemehandler.md)* schemeHandler | 该scheme的拦截器ArkWeb_SchemeHandler。只有从指定web触发的请求才会通过这个schemeHandler进行通知。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果为指定scheme设置SchemeHandler成功，则返回true，否则返回false。 |

### OH_ArkWebServiceWorker_ClearSchemeHandlers()

```
int32_t OH_ArkWebServiceWorker_ClearSchemeHandlers()
```

**描述：**

清除为ServiceWorker注册的SchemeHandler。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果返回0，表示成功。 |

### OH_ArkWeb_ClearSchemeHandlers()

```
int32_t OH_ArkWeb_ClearSchemeHandlers(const char* webTag)
```

**描述：**

清除为指定web注册的SchemeHandler。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件的标签名称，用于标识某个唯一组件，由开发者来保证名称唯一性。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果返回0，表示成功；返回17100101，表示参数无效。 |

### OH_ArkWeb_CreateSchemeHandler()

```
void OH_ArkWeb_CreateSchemeHandler(ArkWeb_SchemeHandler** schemeHandler)
```

**描述：**

创建一个ArkWeb_SchemeHandler对象。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkWeb_SchemeHandler](capi-web-arkweb-schemehandler.md)** schemeHandler | 返回创建的ArkWeb_SchemeHandler。在不需要时使用OH_ArkWeb_DestoryschemeHandler销毁它。 |

### OH_ArkWeb_DestroySchemeHandler()

```
void OH_ArkWeb_DestroySchemeHandler(ArkWeb_SchemeHandler* schemeHandler)
```

**描述：**

销毁一个ArkWeb_SchemeHandler对象。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkWeb_SchemeHandler](capi-web-arkweb-schemehandler.md)* schemeHandler | 待销毁的ArkWeb_SchemeHandler。 |

### OH_ArkWebSchemeHandler_SetUserData()

```
int32_t OH_ArkWebSchemeHandler_SetUserData(ArkWeb_SchemeHandler* schemeHandler, void* userData)
```

**描述：**

将一个用户数据设置到ArkWeb_SchemeHandler对象中。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkWeb_SchemeHandler](capi-web-arkweb-schemehandler.md)* schemeHandler | ArkWeb_SchemeHandler。 |
| void* userData | 要设置的用户数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果返回0，表示成功；返回17100101，表示参数无效。 |

### OH_ArkWebSchemeHandler_GetUserData()

```
void* OH_ArkWebSchemeHandler_GetUserData(const ArkWeb_SchemeHandler* schemeHandler)
```

**描述：**

从ArkWeb_SchemeHandler获取用户数据。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_SchemeHandler](capi-web-arkweb-schemehandler.md)* schemeHandler | ArkWeb_SchemeHandler。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| void* | 设置的用户数据。 |

### OH_ArkWebSchemeHandler_SetOnRequestStart()

```
int32_t OH_ArkWebSchemeHandler_SetOnRequestStart(ArkWeb_SchemeHandler* schemeHandler,ArkWeb_OnRequestStart onRequestStart)
```

**描述：**

为SchemeHandler设置OnRequestStart回调。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkWeb_SchemeHandler](capi-web-arkweb-schemehandler.md)* schemeHandler | 该scheme的SchemeHandler。 |
| [ArkWeb_OnRequestStart](#arkweb_onrequeststart) onRequestStart | OnRequestStart回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果返回0，表示成功；返回17100101，表示参数无效。 |

### OH_ArkWebSchemeHandler_SetOnRequestStop()

```
int32_t OH_ArkWebSchemeHandler_SetOnRequestStop(ArkWeb_SchemeHandler* schemeHandler,ArkWeb_OnRequestStop onRequestStop)
```

**描述：**

为SchemeHandler设置OnRequestStop回调。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkWeb_SchemeHandler](capi-web-arkweb-schemehandler.md)* schemeHandler | 该scheme的SchemeHandler。 |
| [ArkWeb_OnRequestStop](#arkweb_onrequeststop) onRequestStop | OnRequestStop回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果返回0，表示成功；返回17100101，表示参数无效。 |

### OH_ArkWeb_CreateResponse()

```
void OH_ArkWeb_CreateResponse(ArkWeb_Response** response)
```

**描述：**

为被拦截的请求创建一个ArkWeb_Response对象。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkWeb_Response](capi-web-arkweb-response.md)** response | 返回创建的ArkWeb_Response。在不需要时使用OH_ArkWeb_DestoryResponse进行销毁。 |

### OH_ArkWeb_DestroyResponse()

```
void OH_ArkWeb_DestroyResponse(ArkWeb_Response* response)
```

**描述：**

销毁一个ArkWeb_Response对象。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkWeb_Response](capi-web-arkweb-response.md)* response | 待销毁的ArkWeb_Response。 |

### OH_ArkWebResponse_SetUrl()

```
int32_t OH_ArkWebResponse_SetUrl(ArkWeb_Response* response, const char* url)
```

**描述：**

设置经过重定向或由于HSTS而改变后的解析URL，设置后会触发跳转。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkWeb_Response](capi-web-arkweb-response.md)* response | ArkWeb_Response。 |
| const char* url | 解析后的URL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果返回0，表示成功；返回17100101，表示参数无效。 |

### OH_ArkWebResponse_GetUrl()

```
void OH_ArkWebResponse_GetUrl(const ArkWeb_Response* response, char** url)
```

**描述：**

获取经过重定向或由于HSTS而更改后的解析URL。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_Response](capi-web-arkweb-response.md)* response | ArkWeb_Response。 |
| char** url | 解析后的URL。 |

### OH_ArkWebResponse_SetError()

```
int32_t OH_ArkWebResponse_SetError(ArkWeb_Response* response, ArkWeb_NetError errorCode)
```

**描述：**

给ArkWeb_Response对象设置一个错误码。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkWeb_Response](capi-web-arkweb-response.md)* response | ArkWeb_Response。 |
| [ArkWeb_NetError](capi-arkweb-net-error-list-h.md#arkweb_neterror) errorCode | 失败请求的错误码。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果返回0，表示成功；返回17100101，表示参数无效。 |

### OH_ArkWebResponse_GetError()

```
ArkWeb_NetError OH_ArkWebResponse_GetError(const ArkWeb_Response* response)
```

**描述：**

获取ArkWeb_Response的错误码。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项                                 | 描述 |
|-------------------------------------| -- |
| const [ArkWeb_Response](capi-web-arkweb-response.md)* response | ArkWeb_Response。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkWeb_NetError](capi-arkweb-net-error-list-h.md#arkweb_neterror) | ArkWeb_Response的错误码。 |

### OH_ArkWebResponse_SetStatus()

```
int32_t OH_ArkWebResponse_SetStatus(ArkWeb_Response* response, int status)
```

**描述：**

为ArkWeb_Response对象设置一个HTTP状态码。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkWeb_Response](capi-web-arkweb-response.md)* response | ArkWeb_Response。 |
| int status | 请求的HTTP状态码。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果返回0，表示成功；返回17100101，表示参数无效。 |

### OH_ArkWebResponse_GetStatus()

```
int OH_ArkWebResponse_GetStatus(const ArkWeb_Response* response)
```

**描述：**

获取ArkWeb_Response的HTTP状态码。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项                                 | 描述 |
|-------------------------------------| -- |
| const [ArkWeb_Response](capi-web-arkweb-response.md)* response | ArkWeb_Response。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | ArkWeb_Response的HTTP状态码。如果ArkWeb_Response无效，则为-1。 |

### OH_ArkWebResponse_SetStatusText()

```
int32_t OH_ArkWebResponse_SetStatusText(ArkWeb_Response* response, const char* statusText)
```

**描述：**

为ArkWeb_Response设置状态文本。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkWeb_Response](capi-web-arkweb-response.md)* response | ArkWeb_Response。 |
| const char* statusText | 请求的状态文本。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果返回0，表示成功；返回17100101，表示参数无效。 |

### OH_ArkWebResponse_GetStatusText()

```
void OH_ArkWebResponse_GetStatusText(const ArkWeb_Response* response, char** statusText)
```

**描述：**

获取ArkWeb_Response的状态文本。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_Response](capi-web-arkweb-response.md)* response | ArkWeb_Response。 |
| char** statusText | 返回ArkWeb_Response的状态文本。此函数将为statusText字符串分配内存，调用方必须通过OH_ArkWeb_ReleaseString释放该字符串。 |

### OH_ArkWebResponse_SetMimeType()

```
int32_t OH_ArkWebResponse_SetMimeType(ArkWeb_Response* response, const char* mimeType)
```

**描述：**

为ArkWeb_Response设置媒体类型。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkWeb_Response](capi-web-arkweb-response.md)* response | ArkWeb_Response。 |
| const char* mimeType | 请求的媒体类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果返回0，表示成功；返回17100101，表示参数无效。 |

### OH_ArkWebResponse_GetMimeType()

```
void OH_ArkWebResponse_GetMimeType(const ArkWeb_Response* response, char** mimeType)
```

**描述：**

获取ArkWeb_Response的媒体类型。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_Response](capi-web-arkweb-response.md)* response | ArkWeb_Response。 |
| char** mimeType | 返回ArkWeb_Response的媒体类型。此函数将为mimeType字符串分配内存，调用方必须通过OH_ArkWeb_ReleaseString释放该字符串。 |

### OH_ArkWebResponse_SetCharset()

```
int32_t OH_ArkWebResponse_SetCharset(ArkWeb_Response* response, const char* charset)
```

**描述：**

为ArkWeb_Response设置字符集。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkWeb_Response](capi-web-arkweb-response.md)* response | ArkWeb_Response。 |
| const char* charset | 请求的字符集。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果返回0，表示成功；返回17100101，表示参数无效。 |

### OH_ArkWebResponse_GetCharset()

```
void OH_ArkWebResponse_GetCharset(const ArkWeb_Response* response, char** charset)
```

**描述：**

获取ArkWeb_Response的字符集。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_Response](capi-web-arkweb-response.md)* response | ArkWeb_Response。 |
| char** charset | 返回ArkWeb_Response的字符集。此函数将为charset字符串分配内存，调用方必须通过OH_ArkWeb_ReleaseString释放字符串。 |

### OH_ArkWebResponse_SetHeaderByName()

```
int32_t OH_ArkWebResponse_SetHeaderByName(ArkWeb_Response* response,const char* name,const char* value,bool overwrite)
```

**描述：**

为ArkWeb_Response设置一个header。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkWeb_Response](capi-web-arkweb-response.md)* response | ArkWeb_Response。 |
| const char* name | header的名称。 |
| const char* value | header的值。 |
| bool overwrite | 如果为true，将覆盖现有的header，否则不覆盖。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果返回0，表示成功；返回17100101，表示参数无效。 |

### OH_ArkWebResponse_GetHeaderByName()

```
void OH_ArkWebResponse_GetHeaderByName(const ArkWeb_Response* response, const char* name, char** value)
```

**描述：**

从ArkWeb_Response中获取header。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_Response](capi-web-arkweb-response.md)* response | ArkWeb_Response。 |
| const char* name | header的名称。 |
| char** value | 返回header的值。此函数将为value字符串分配内存，调用方必须通过OH_ArkWeb_ReleaseString释放该字符串。 |

### OH_ArkWebResourceHandler_Destroy()

```
int32_t OH_ArkWebResourceHandler_Destroy(const ArkWeb_ResourceHandler* resourceHandler)
```

**描述：**

销毁一个ArkWeb_ResourceHandler对象。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项                                               | 描述 |
|---------------------------------------------------| -- |
| const [ArkWeb_ResourceHandler](capi-web-arkweb-resourcehandler.md)* resourceHandler | ArkWeb_ResourceHandler。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果返回0，表示成功；返回17100101，表示参数无效。 |

### OH_ArkWebResourceHandler_DidReceiveResponse()

```
int32_t OH_ArkWebResourceHandler_DidReceiveResponse(const ArkWeb_ResourceHandler* resourceHandler,const ArkWeb_Response* response)
```

**描述：**

将构造的响应头传递给被拦截的请求。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_ResourceHandler](capi-web-arkweb-resourcehandler.md)* resourceHandler | 该请求的ArkWeb_ResourceHandler。 |
| const [ArkWeb_Response](capi-web-arkweb-response.md)* response | 该拦截请求的ArkWeb_Response。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果返回0，表示成功；返回17100101，表示参数无效。 |

### OH_ArkWebResourceHandler_DidReceiveData()

```
int32_t OH_ArkWebResourceHandler_DidReceiveData(const ArkWeb_ResourceHandler* resourceHandler,const uint8_t* buffer,int64_t bufLen)
```

**描述：**

将构造的响应体传递给被拦截的请求。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_ResourceHandler](capi-web-arkweb-resourcehandler.md)* resourceHandler | 该请求的ArkWeb_ResourceHandler。 |
| const uint8_t* buffer | 要发送的buffer数据。 |
| int64_t bufLen | buffer的大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果返回0，表示成功；返回17100101，表示参数无效。 |

### OH_ArkWebResourceHandler_DidFinish()

```
int32_t OH_ArkWebResourceHandler_DidFinish(const ArkWeb_ResourceHandler* resourceHandler)
```

**描述：**

通知ArkWeb内核被拦截的请求已经完成，并且没有更多的数据可用。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_ResourceHandler](capi-web-arkweb-resourcehandler.md)* resourceHandler | 该请求的ArkWeb_ResourceHandler。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果返回0，表示成功；返回17100101，表示参数无效。 |

### OH_ArkWebResourceHandler_DidFailWithError()

```
int32_t OH_ArkWebResourceHandler_DidFailWithError(const ArkWeb_ResourceHandler* resourceHandler,ArkWeb_NetError errorCode)
```

**描述：**

通知ArkWeb内核被拦截请求应该失败。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkWeb_ResourceHandler](capi-web-arkweb-resourcehandler.md)* resourceHandler | 该请求的ArkWeb_ResourceHandler。 |
| [ArkWeb_NetError](capi-arkweb-net-error-list-h.md#arkweb_neterror) errorCode | 该请求的错误码。请参考[arkweb_net_error_list.h](capi-arkweb-net-error-list-h.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果返回0，表示成功；返回17100101，表示参数无效。 |

### OH_ArkWeb_ReleaseString()

```
void OH_ArkWeb_ReleaseString(char* string)
```

**描述：**

释放由NDK接口创建的字符串。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| char* string | 待释放的字符串。 |

### OH_ArkWeb_ReleaseByteArray()

```
void OH_ArkWeb_ReleaseByteArray(uint8_t* byteArray)
```

**描述：**

释放由NDK接口创建的字节数组。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint8_t* byteArray | 待释放的字节数组。 |


