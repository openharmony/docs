# arkweb_scheme_handler.h


## 概述

声明用于拦截来自ArkWeb的请求的API。

**库：** libohweb.so

**引用文件：** <web/arkweb_scheme_handler.h>

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**相关模块：**[Web](_web.md)

**相关示例：**[ArkWebSchemeHandler](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkWeb/ArkWebSchemeHandler)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [ArkWeb_CustomSchemeOption](_web.md#arkweb_customschemeoption) [ArkWeb_CustomSchemeOption](_web.md#arkweb_customschemeoption) | custom scheme的配置信息。  | 
| typedef enum [ArkWeb_ResourceType](_web.md#arkweb_resourcetype) [ArkWeb_ResourceType](_web.md#arkweb_resourcetype) | 请求的资源类型。  | 
| typedef struct ArkWeb_SchemeHandler_ [ArkWeb_SchemeHandler](_web.md#arkweb_schemehandler) | 该类用于拦截指定scheme的请求。  | 
| typedef struct ArkWeb_ResourceHandler_ [ArkWeb_ResourceHandler](_web.md#arkweb_resourcehandler) | 用于被拦截的URL请求。  | 
| typedef struct ArkWeb_Response_ [ArkWeb_Response](_web.md#arkweb_response) | 为被拦截的请求构造一个ArkWeb_Response。  | 
| typedef struct ArkWeb_ResourceRequest_ [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) | 对应内核的一个请求，可以通过OH_ArkWeb_ResourceRequest获取请求的URL、method、post data以及其他信息。  | 
| typedef struct ArkWeb_RequestHeaderList_ [ArkWeb_RequestHeaderList](_web.md#arkweb_requestheaderlist) | 请求头列表。  | 
| typedef struct ArkWeb_HttpBodyStream_ [ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) | 请求的上传数据。  | 
| typedef void(\* [ArkWeb_OnRequestStart](_web.md#arkweb_onrequeststart)) (const [ArkWeb_SchemeHandler](_web.md#arkweb_schemehandler) \*schemeHandler, [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest, const [ArkWeb_ResourceHandler](_web.md#arkweb_resourcehandler) \*resourceHandler, bool \*intercept) | 请求开始的回调，这将在IO线程上被调用。  | 
| typedef void(\* [ArkWeb_OnRequestStop](_web.md#arkweb_onrequeststop)) (const [ArkWeb_SchemeHandler](_web.md#arkweb_schemehandler) \*schemeHandler, const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest) | 请求完成时的回调函数。  | 
| typedef void(\* [ArkWeb_HttpBodyStreamReadCallback](_web.md#arkweb_httpbodystreamreadcallback)) (const [ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream, uint8_t \*buffer, int bytesRead) | 当OH_ArkWebHttpBodyStream_Read读取操作完成时的回调函数。  | 
| typedef void(\* [ArkWeb_HttpBodyStreamInitCallback](_web.md#arkweb_httpbodystreaminitcallback)) (const [ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream, [ArkWeb_NetError](_web.md#arkweb_neterror) result) | ArkWeb_HttpBodyStream初始化操作完成时回调函数。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ArkWeb_CustomSchemeOption](_web.md#arkweb_customschemeoption) {<br/>**OH_ARKWEB_SCHEME_OPTION_NONE** = 0, [ARKWEB_SCHEME_OPTION_STANDARD](_web.md) = 1 &lt;&lt; 0, [ARKWEB_SCHEME_OPTION_LOCAL](_web.md) = 1 &lt;&lt; 1, [ARKWEB_SCHEME_OPTION_DISPLAY_ISOLATED](_web.md) = 1 &lt;&lt; 2,<br/>[ARKWEB_SCHEME_OPTION_SECURE](_web.md) = 1 &lt;&lt; 3, [ARKWEB_SCHEME_OPTION_CORS_ENABLED](_web.md) = 1 &lt;&lt; 4, [ARKWEB_SCHEME_OPTION_CSP_BYPASSING](_web.md) = 1 &lt;&lt; 5, [ARKWEB_SCHEME_OPTION_FETCH_ENABLED](_web.md) = 1 &lt;&lt; 6,<br/>[ARKWEB_SCHEME_OPTION_CODE_CACHE_ENABLED](_web.md) = 1 &lt;&lt; 7<br/>} | custom scheme的配置信息。  | 
| [ArkWeb_ResourceType](_web.md#arkweb_resourcetype) {<br/>[MAIN_FRAME](_web.md) = 0, [SUB_FRAME](_web.md) = 1, [STYLE_SHEET](_web.md) = 2, [SCRIPT](_web.md) = 3,<br/>[IMAGE](_web.md) = 4, [FONT_RESOURCE](_web.md) = 5, [SUB_RESOURCE](_web.md) = 6, [OBJECT](_web.md) = 7,<br/>[MEDIA](_web.md) = 8, [WORKER](_web.md) = 9, [SHARED_WORKER](_web.md) = 10, [PREFETCH](_web.md) = 11,<br/>[FAVICON](_web.md) = 12, [XHR](_web.md) = 13, [PING](_web.md) = 14, [SERVICE_WORKER](_web.md) = 15,<br/>[CSP_REPORT](_web.md) = 16, [PLUGIN_RESOURCE](_web.md) = 17, [NAVIGATION_PRELOAD_MAIN_FRAME](_web.md) = 19, [NAVIGATION_PRELOAD_SUB_FRAME](_web.md) = 20<br/>} | 请求的资源类型。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| void [OH_ArkWebRequestHeaderList_Destroy](_web.md#oh_arkwebrequestheaderlist_destroy) ([ArkWeb_RequestHeaderList](_web.md#arkweb_requestheaderlist) \*requestHeaderList) | 销毁ArkWeb_RequestHeaderList对象。  | 
| int32_t [OH_ArkWebRequestHeaderList_GetSize](_web.md#oh_arkwebrequestheaderlist_getsize) (const [ArkWeb_RequestHeaderList](_web.md#arkweb_requestheaderlist) \*requestHeaderList) | 获取请求头列表的大小。  | 
| void [OH_ArkWebRequestHeaderList_GetHeader](_web.md#oh_arkwebrequestheaderlist_getheader) (const [ArkWeb_RequestHeaderList](_web.md#arkweb_requestheaderlist) \*requestHeaderList, int32_t index, char \*\*key, char \*\*value) | 获取指定的请求头。  | 
| int32_t [OH_ArkWebResourceRequest_SetUserData](_web.md#oh_arkwebresourcerequest_setuserdata) ([ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest, void \*userData) | 将一个用户数据设置到ArkWeb_ResourceRequest对象中。  | 
| void \* [OH_ArkWebResourceRequest_GetUserData](_web.md#oh_arkwebresourcerequest_getuserdata) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest) | 从ArkWeb_ResourceRequest获取用户数据。  | 
| void [OH_ArkWebResourceRequest_GetMethod](_web.md#oh_arkwebresourcerequest_getmethod) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest, char \*\*method) | 获取请求的method。  | 
| void [OH_ArkWebResourceRequest_GetUrl](_web.md#oh_arkwebresourcerequest_geturl) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest, char \*\*url) | 获取请求的url。  | 
| void [OH_ArkWebResourceRequest_GetHttpBodyStream](_web.md#oh_arkwebresourcerequest_gethttpbodystream) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest, [ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*\*httpBodyStream) | 创建一个ArkWeb_HttpBodyStream，用于读取请求的上传数据。  | 
| void [OH_ArkWebResourceRequest_DestroyHttpBodyStream](_web.md#oh_arkwebresourcerequest_destroyhttpbodystream) ([ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream) | 销毁ArkWeb_HttpBodyStream对象。  | 
| int32_t [OH_ArkWebResourceRequest_GetResourceType](_web.md#oh_arkwebresourcerequest_getresourcetype) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest) | 获取请求的资源类型。  | 
| void [OH_ArkWebResourceRequest_GetFrameUrl](_web.md#oh_arkwebresourcerequest_getframeurl) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest, char \*\*frameUrl) | 获取触发此请求的Frame的URL。  | 
| int32_t [OH_ArkWebHttpBodyStream_SetUserData](_web.md#oh_arkwebhttpbodystream_setuserdata) ([ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream, void \*userData) | 将一个用户数据设置到ArkWeb_HttpBodyStream对象中。  | 
| void \* [OH_ArkWebHttpBodyStream_GetUserData](_web.md#oh_arkwebhttpbodystream_getuserdata) (const [ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream) | 从ArkWeb_HttpBodyStream获取用户数据。  | 
| int32_t [OH_ArkWebHttpBodyStream_SetReadCallback](_web.md#oh_arkwebhttpbodystream_setreadcallback) ([ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream, [ArkWeb_HttpBodyStreamReadCallback](_web.md#arkweb_httpbodystreamreadcallback) readCallback) | 为OH_ArkWebHttpBodyStream_Read设置回调函数。  | 
| int32_t [OH_ArkWebHttpBodyStream_Init](_web.md#oh_arkwebhttpbodystream_init) ([ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream, [ArkWeb_HttpBodyStreamInitCallback](_web.md#arkweb_httpbodystreaminitcallback) initCallback) | 初始化ArkWeb_HttpBodyStream。  | 
| void [OH_ArkWebHttpBodyStream_Read](_web.md#oh_arkwebhttpbodystream_read) (const [ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream, uint8_t \*buffer, int bufLen) | 将请求的上传数据读取到buffer。  | 
| uint64_t [OH_ArkWebHttpBodyStream_GetSize](_web.md#oh_arkwebhttpbodystream_getsize) (const [ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream) | 获取httpBodyStream的大小。  | 
| uint64_t [OH_ArkWebHttpBodyStream_GetPosition](_web.md#oh_arkwebhttpbodystream_getposition) (const [ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream) | 获取httpBodyStream当前的读取位置。  | 
| bool [OH_ArkWebHttpBodyStream_IsChunked](_web.md#oh_arkwebhttpbodystream_ischunked) (const [ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream) | 获取httpBodyStream是否采用分块传输。  | 
| bool [OH_ArkWebHttpBodyStream_IsEof](_web.md#oh_arkwebhttpbodystream_iseof) (const [ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream) | 如果httpBodyStream中的所有数据都已被读取，则返回true。  | 
| bool [OH_ArkWebHttpBodyStream_IsInMemory](_web.md#oh_arkwebhttpbodystream_isinmemory) (const [ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream) | 如果httpBodyStream中的上传数据完全在内存中，并且所有读取请求都将同步成功，则返回true。  | 
| int32_t [OH_ArkWebResourceRequest_Destroy](_web.md#oh_arkwebresourcerequest_destroy) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest) | 销毁ArkWeb_ResourceRequest对象。  | 
| void [OH_ArkWebResourceRequest_GetReferrer](_web.md#oh_arkwebresourcerequest_getreferrer) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest, char \*\*referrer) | 获取请求的Referrer。  | 
| void [OH_ArkWebResourceRequest_GetRequestHeaders](_web.md#oh_arkwebresourcerequest_getrequestheaders) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest, [ArkWeb_RequestHeaderList](_web.md#arkweb_requestheaderlist) \*\*requestHeaderList) | 获取请求的请求头列表OH_ArkWeb_RequestHeaderList。  | 
| bool [OH_ArkWebResourceRequest_IsRedirect](_web.md#oh_arkwebresourcerequest_isredirect) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest) | 判断这是否是一个重定向请求。  | 
| bool [OH_ArkWebResourceRequest_IsMainFrame](_web.md#oh_arkwebresourcerequest_ismainframe) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest) | 判断这是否是主框架文档资源的请求。  | 
| bool [OH_ArkWebResourceRequest_HasGesture](_web.md#oh_arkwebresourcerequest_hasgesture) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest) | 判断这是否是一个由用户手势触发的请求。  | 
| int32_t [OH_ArkWeb_RegisterCustomSchemes](_web.md#oh_arkweb_registercustomschemes) (const char \*scheme, int32_t option) | 将custom scheme注册到ArkWeb。  | 
| bool [OH_ArkWebServiceWorker_SetSchemeHandler](_web.md#oh_arkwebserviceworker_setschemehandler) (const char \*scheme, [ArkWeb_SchemeHandler](_web.md#arkweb_schemehandler) \*schemeHandler) | 为指定scheme设置一个ArkWeb_SchemeHandler以拦截ServiceWorker触发的该scheme类型的请求。  | 
| bool [OH_ArkWeb_SetSchemeHandler](_web.md#oh_arkweb_setschemehandler) (const char \*scheme, const char \*webTag, [ArkWeb_SchemeHandler](_web.md#arkweb_schemehandler) \*schemeHandler) | 为指定scheme设置一个ArkWeb_SchemeHandler以拦截该scheme类型的请求。  | 
| int32_t [OH_ArkWebServiceWorker_ClearSchemeHandlers](_web.md#oh_arkwebserviceworker_clearschemehandlers) () | 清除为ServiceWorker注册的SchemeHandler。  | 
| int32_t [OH_ArkWeb_ClearSchemeHandlers](_web.md#oh_arkweb_clearschemehandlers) (const char \*webTag) | 清除为指定web注册的SchemeHandler。  | 
| void [OH_ArkWeb_CreateSchemeHandler](_web.md#oh_arkweb_createschemehandler) ([ArkWeb_SchemeHandler](_web.md#arkweb_schemehandler) \*\*schemeHandler) | 创建一个ArkWeb_SchemeHandler对象。  | 
| void [OH_ArkWeb_DestroySchemeHandler](_web.md#oh_arkweb_destroyschemehandler) ([ArkWeb_SchemeHandler](_web.md#arkweb_schemehandler) \*schemeHandler) | 销毁一个ArkWeb_SchemeHandler对象。  | 
| int32_t [OH_ArkWebSchemeHandler_SetUserData](_web.md#oh_arkwebschemehandler_setuserdata) ([ArkWeb_SchemeHandler](_web.md#arkweb_schemehandler) \*schemeHandler, void \*userData) | 将一个用户数据设置到ArkWeb_SchemeHandler对象中。  | 
| void \* [OH_ArkWebSchemeHandler_GetUserData](_web.md#oh_arkwebschemehandler_getuserdata) (const [ArkWeb_SchemeHandler](_web.md#arkweb_schemehandler) \*schemeHandler) | 从ArkWeb_SchemeHandler获取用户数据。  | 
| int32_t [OH_ArkWebSchemeHandler_SetOnRequestStart](_web.md#oh_arkwebschemehandler_setonrequeststart) ([ArkWeb_SchemeHandler](_web.md#arkweb_schemehandler) \*schemeHandler, [ArkWeb_OnRequestStart](_web.md#arkweb_onrequeststart) onRequestStart) | 为SchemeHandler设置OnRequestStart回调。  | 
| int32_t [OH_ArkWebSchemeHandler_SetOnRequestStop](_web.md#oh_arkwebschemehandler_setonrequeststop) ([ArkWeb_SchemeHandler](_web.md#arkweb_schemehandler) \*schemeHandler, [ArkWeb_OnRequestStop](_web.md#arkweb_onrequeststop) onRequestStop) | 为SchemeHandler设置OnRequestStop回调。  | 
| void [OH_ArkWeb_CreateResponse](_web.md#oh_arkweb_createresponse) ([ArkWeb_Response](_web.md#arkweb_response) \*\*response) | 为被拦截的请求创建一个ArkWeb_Response对象。  | 
| void [OH_ArkWeb_DestroyResponse](_web.md#oh_arkweb_destroyresponse) ([ArkWeb_Response](_web.md#arkweb_response) \*response) | 销毁一个ArkWeb_Response对象。  | 
| int32_t [OH_ArkWebResponse_SetUrl](_web.md#oh_arkwebresponse_seturl) ([ArkWeb_Response](_web.md#arkweb_response) \*response, const char \*url) | 设置经过重定向或由于HSTS而改变后的解析URL，设置后会触发跳转。  | 
| void [OH_ArkWebResponse_GetUrl](_web.md#oh_arkwebresponse_geturl) (const [ArkWeb_Response](_web.md#arkweb_response) \*response, char \*\*url) | 获取经过重定向或由于HSTS而更改后的解析URL。  | 
| int32_t [OH_ArkWebResponse_SetError](_web.md#oh_arkwebresponse_seterror) ([ArkWeb_Response](_web.md#arkweb_response) \*response, [ArkWeb_NetError](_web.md#arkweb_neterror) errorCode) | 给ArkWeb_Response对象设置一个错误码。  | 
| [ArkWeb_NetError](_web.md#arkweb_neterror) [OH_ArkWebResponse_GetError](_web.md#oh_arkwebresponse_geterror) (const [ArkWeb_Response](_web.md#arkweb_response) \*response) | 获取ArkWeb_Response的错误码。  | 
| int32_t [OH_ArkWebResponse_SetStatus](_web.md#oh_arkwebresponse_setstatus) ([ArkWeb_Response](_web.md#arkweb_response) \*response, int status) | 为ArkWeb_Response对象设置一个HTTP状态码。  | 
| int [OH_ArkWebResponse_GetStatus](_web.md#oh_arkwebresponse_getstatus) (const [ArkWeb_Response](_web.md#arkweb_response) \*response) | 获取ArkWeb_Response的HTTP状态码。  | 
| int32_t [OH_ArkWebResponse_SetStatusText](_web.md#oh_arkwebresponse_setstatustext) ([ArkWeb_Response](_web.md#arkweb_response) \*response, const char \*statusText) | 为ArkWeb_Response设置状态文本。  | 
| void [OH_ArkWebResponse_GetStatusText](_web.md#oh_arkwebresponse_getstatustext) (const [ArkWeb_Response](_web.md#arkweb_response) \*response, char \*\*statusText) | 获取ArkWeb_Response的状态文本。  | 
| int32_t [OH_ArkWebResponse_SetMimeType](_web.md#oh_arkwebresponse_setmimetype) ([ArkWeb_Response](_web.md#arkweb_response) \*response, const char \*mimeType) | 为ArkWeb_Response设置媒体类型。  | 
| void [OH_ArkWebResponse_GetMimeType](_web.md#oh_arkwebresponse_getmimetype) (const [ArkWeb_Response](_web.md#arkweb_response) \*response, char \*\*mimeType) | 获取ArkWeb_Response的媒体类型。  | 
| int32_t [OH_ArkWebResponse_SetCharset](_web.md#oh_arkwebresponse_setcharset) ([ArkWeb_Response](_web.md#arkweb_response) \*response, const char \*charset) | 为ArkWeb_Response设置字符集。  | 
| void [OH_ArkWebResponse_GetCharset](_web.md#oh_arkwebresponse_getcharset) (const [ArkWeb_Response](_web.md#arkweb_response) \*response, char \*\*charset) | 获取ArkWeb_Response的字符集。  | 
| int32_t [OH_ArkWebResponse_SetHeaderByName](_web.md#oh_arkwebresponse_setheaderbyname) ([ArkWeb_Response](_web.md#arkweb_response) \*response, const char \*name, const char \*value, bool overwrite) | 为ArkWeb_Response设置一个header。  | 
| void [OH_ArkWebResponse_GetHeaderByName](_web.md#oh_arkwebresponse_getheaderbyname) (const [ArkWeb_Response](_web.md#arkweb_response) \*response, const char \*name, char \*\*value) | 从ArkWeb_Response中获取header。  | 
| int32_t [OH_ArkWebResourceHandler_Destroy](_web.md#oh_arkwebresourcehandler_destroy) (const [ArkWeb_ResourceHandler](_web.md#arkweb_resourcehandler) \*resourceHandler) | 销毁一个ArkWeb_ResourceHandler对象。  | 
| int32_t [OH_ArkWebResourceHandler_DidReceiveResponse](_web.md#oh_arkwebresourcehandler_didreceiveresponse) (const [ArkWeb_ResourceHandler](_web.md#arkweb_resourcehandler) \*resourceHandler, const [ArkWeb_Response](_web.md#arkweb_response) \*response) | 将构造的响应头传递给被拦截的请求。OH_ArkWebResourceHandler_DidReceiveResponse是必须调用的，如果在收到response前发生错误，在response中设置一个error通过该接口通知给内核。  | 
| int32_t [OH_ArkWebResourceHandler_DidReceiveData](_web.md#oh_arkwebresourcehandler_didreceivedata) (const [ArkWeb_ResourceHandler](_web.md#arkweb_resourcehandler) \*resourceHandler, const uint8_t \*buffer, int64_t bufLen) | 将构造的响应体传递给被拦截的请求。  | 
| int32_t [OH_ArkWebResourceHandler_DidFinish](_web.md#oh_arkwebresourcehandler_didfinish) (const [ArkWeb_ResourceHandler](_web.md#arkweb_resourcehandler) \*resourceHandler) | 通知ArkWeb内核被拦截的请求已经完成，并且没有更多的数据可用。  | 
| int32_t [OH_ArkWebResourceHandler_DidFailWithError](_web.md#oh_arkwebresourcehandler_didfailwitherror) (const [ArkWeb_ResourceHandler](_web.md#arkweb_resourcehandler) \*resourceHandler, [ArkWeb_NetError](_web.md#arkweb_neterror) errorCode) | 通知ArkWeb内核被拦截请求应该失败。  | 
| void [OH_ArkWeb_ReleaseString](_web.md#oh_arkweb_releasestring) (char \*string) | 释放由NDK接口创建的字符串  | 
| void [OH_ArkWeb_ReleaseByteArray](_web.md#oh_arkweb_releasebytearray) (uint8_t \*byteArray) | 释放由NDK接口创建的字节数组。  | 
