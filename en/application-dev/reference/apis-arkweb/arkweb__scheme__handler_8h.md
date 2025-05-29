# arkweb_scheme_handler.h


## Overview

Declares the APIs used to intercept requests from ArkWeb.

**Library**: libohweb.so

**File to include**: <web/arkweb_scheme_handler.h>

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Related module**: [Web](_web.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [ArkWeb_CustomSchemeOption](_web.md#arkweb_customschemeoption) [ArkWeb_CustomSchemeOption](_web.md#arkweb_customschemeoption) | Defines an enum for the custom scheme option. | 
| typedef enum [ArkWeb_ResourceType](_web.md#arkweb_resourcetype) [ArkWeb_ResourceType](_web.md#arkweb_resourcetype) | Defines an enum for the resource type. | 
| typedef struct ArkWeb_SchemeHandler_ [ArkWeb_SchemeHandler](_web.md#arkweb_schemehandler) | Defines a struct for the intercept of a specified scheme request. | 
| typedef struct ArkWeb_ResourceHandler_ [ArkWeb_ResourceHandler](_web.md#arkweb_resourcehandler) | Defines a struct for the intercepted URL requests. | 
| typedef struct ArkWeb_Response_ [ArkWeb_Response](_web.md#arkweb_response) | Defines a struct for **ArkWeb_Response** for the intercepted request. | 
| typedef struct ArkWeb_ResourceRequest_ [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) | Defines a struct for resource request. Through **OH_ArkWeb_ResourceRequest**, you can obtain the URL, method, post data, and other information of the request. | 
| typedef struct ArkWeb_RequestHeaderList_ [ArkWeb_RequestHeaderList](_web.md#arkweb_requestheaderlist) | Defines a struct for request header list. | 
| typedef struct ArkWeb_HttpBodyStream_ [ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) | Defines a struct for the request upload data. | 
| typedef void(\* [ArkWeb_OnRequestStart](_web.md#arkweb_onrequeststart)) (const [ArkWeb_SchemeHandler](_web.md#arkweb_schemehandler) \*schemeHandler, [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest, const [ArkWeb_ResourceHandler](_web.md#arkweb_resourcehandler) \*resourceHandler, bool \*intercept) | Defines a callback used to start the request on the I/O thread. | 
| typedef void(\* [ArkWeb_OnRequestStop](_web.md#arkweb_onrequeststop)) (const [ArkWeb_SchemeHandler](_web.md#arkweb_schemehandler) \*schemeHandler, const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest) | Defines a callback used to stop the request. | 
| typedef void(\* [ArkWeb_HttpBodyStreamReadCallback](_web.md#arkweb_httpbodystreamreadcallback)) (const [ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream, uint8_t \*buffer, int bytesRead) | Defines a callback used when **OH_ArkWebHttpBodyStream_Read** is complete. | 
| typedef void(\* [ArkWeb_HttpBodyStreamInitCallback](_web.md#arkweb_httpbodystreaminitcallback)) (const [ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream, [ArkWeb_NetError](_web.md#arkweb_neterror) result) | Defines a callback used when **ArkWeb_HttpBodyStream** initialization is complete. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [ArkWeb_CustomSchemeOption](_web.md#arkweb_customschemeoption) {<br>**OH_ARKWEB_SCHEME_OPTION_NONE** = 0, [ARKWEB_SCHEME_OPTION_STANDARD](_web.md) = 1 &lt;&lt; 0, [ARKWEB_SCHEME_OPTION_LOCAL](_web.md) = 1 &lt;&lt; 1, [ARKWEB_SCHEME_OPTION_DISPLAY_ISOLATED](_web.md) = 1 &lt;&lt; 2,<br>[ARKWEB_SCHEME_OPTION_SECURE](_web.md) = 1 &lt;&lt; 3, [ARKWEB_SCHEME_OPTION_CORS_ENABLED](_web.md) = 1 &lt;&lt; 4, [ARKWEB_SCHEME_OPTION_CSP_BYPASSING](_web.md) = 1 &lt;&lt; 5, [ARKWEB_SCHEME_OPTION_FETCH_ENABLED](_web.md) = 1 &lt;&lt; 6,<br>[ARKWEB_SCHEME_OPTION_CODE_CACHE_ENABLED](_web.md) = 1 &lt;&lt; 7<br>} | Enumerates the custom scheme options. | 
| [ArkWeb_ResourceType](_web.md#arkweb_resourcetype) {<br>[MAIN_FRAME](_web.md) = 0, [SUB_FRAME](_web.md) = 1, [STYLE_SHEET](_web.md) = 2, [SCRIPT](_web.md) = 3,<br>[IMAGE](_web.md) = 4, [FONT_RESOURCE](_web.md) = 5, [SUB_RESOURCE](_web.md) = 6, [OBJECT](_web.md) = 7,<br>[MEDIA](_web.md) = 8, [WORKER](_web.md) = 9, [SHARED_WORKER](_web.md) = 10, [PREFETCH](_web.md) = 11,<br>[FAVICON](_web.md) = 12, [XHR](_web.md) = 13, [PING](_web.md) = 14, [SERVICE_WORKER](_web.md) = 15,<br>[CSP_REPORT](_web.md) = 16, [PLUGIN_RESOURCE](_web.md) = 17, [NAVIGATION_PRELOAD_MAIN_FRAME](_web.md) = 19, [NAVIGATION_PRELOAD_SUB_FRAME](_web.md) = 20<br>} | Enumerates the resource types. | 


### Functions

| Name| Description| 
| -------- | -------- |
| void [OH_ArkWebRequestHeaderList_Destroy](_web.md#oh_arkwebrequestheaderlist_destroy) ([ArkWeb_RequestHeaderList](_web.md#arkweb_requestheaderlist) \*requestHeaderList) | Destroys an **ArkWeb_RequestHeaderList** object. | 
| int32_t [OH_ArkWebRequestHeaderList_GetSize](_web.md#oh_arkwebrequestheaderlist_getsize) (const [ArkWeb_RequestHeaderList](_web.md#arkweb_requestheaderlist) \*requestHeaderList) | Obtains the size of a request header list. | 
| void [OH_ArkWebRequestHeaderList_GetHeader](_web.md#oh_arkwebrequestheaderlist_getheader) (const [ArkWeb_RequestHeaderList](_web.md#arkweb_requestheaderlist) \*requestHeaderList, int32_t index, char \*\*key, char \*\*value) | Obtains a specified request header. | 
| int32_t [OH_ArkWebResourceRequest_SetUserData](_web.md#oh_arkwebresourcerequest_setuserdata) ([ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest, void \*userData) | Sets user data to the **ArkWeb_ResourceRequest** object. | 
| void \* [OH_ArkWebResourceRequest_GetUserData](_web.md#oh_arkwebresourcerequest_getuserdata) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest) | Obtains user data from **ArkWeb_ResourceRequest**. | 
| void [OH_ArkWebResourceRequest_GetMethod](_web.md#oh_arkwebresourcerequest_getmethod) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest, char \*\*method) | Obtains the method of a request. | 
| void [OH_ArkWebResourceRequest_GetUrl](_web.md#oh_arkwebresourcerequest_geturl) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest, char \*\*url) | Obtains the request URL. | 
| void [OH_ArkWebResourceRequest_GetHttpBodyStream](_web.md#oh_arkwebresourcerequest_gethttpbodystream) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest, [ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*\*httpBodyStream) | Creates an **ArkWeb_HttpBodyStream** to read the uploaded data of the request. | 
| void [OH_ArkWebResourceRequest_DestroyHttpBodyStream](_web.md#oh_arkwebresourcerequest_destroyhttpbodystream) ([ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream) | Destroys an **ArkWeb_HttpBodyStream** object. | 
| int32_t [OH_ArkWebResourceRequest_GetResourceType](_web.md#oh_arkwebresourcerequest_getresourcetype) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest) | Obtains the resource type of a request. | 
| void [OH_ArkWebResourceRequest_GetFrameUrl](_web.md#oh_arkwebresourcerequest_getframeurl) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest, char \*\*frameUrl) | Obtains the URL of the Frame that triggered the request. | 
| int32_t [OH_ArkWebHttpBodyStream_SetUserData](_web.md#oh_arkwebhttpbodystream_setuserdata) ([ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream, void \*userData) | Sets user data to the **ArkWeb_HttpBodyStream** object. | 
| void \* [OH_ArkWebHttpBodyStream_GetUserData](_web.md#oh_arkwebhttpbodystream_getuserdata) (const [ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream) | Obtains user data from **ArkWeb_HttpBodyStream**. | 
| int32_t [OH_ArkWebHttpBodyStream_SetReadCallback](_web.md#oh_arkwebhttpbodystream_setreadcallback) ([ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream, [ArkWeb_HttpBodyStreamReadCallback](_web.md#arkweb_httpbodystreamreadcallback) readCallback) | Sets a callback for **OH_ArkWebHttpBodyStream_Read**. | 
| int32_t [OH_ArkWebHttpBodyStream_Init](_web.md#oh_arkwebhttpbodystream_init) ([ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream, [ArkWeb_HttpBodyStreamInitCallback](_web.md#arkweb_httpbodystreaminitcallback) initCallback) | Initializes **ArkWeb_HttpBodyStream**. | 
| void [OH_ArkWebHttpBodyStream_Read](_web.md#oh_arkwebhttpbodystream_read) (const [ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream, uint8_t \*buffer, int bufLen) | Exports upload data of the request to the buffer. | 
| uint64_t [OH_ArkWebHttpBodyStream_GetSize](_web.md#oh_arkwebhttpbodystream_getsize) (const [ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream) | Obtains the size of **httpBodyStream**. | 
| uint64_t [OH_ArkWebHttpBodyStream_GetPosition](_web.md#oh_arkwebhttpbodystream_getposition) (const [ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream) | Obtains the position of **httpBodyStream**. | 
| bool [OH_ArkWebHttpBodyStream_IsChunked](_web.md#oh_arkwebhttpbodystream_ischunked) (const [ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream) | Determines whether **httpBodyStream** is chunked. | 
| bool [OH_ArkWebHttpBodyStream_IsEof](_web.md#oh_arkwebhttpbodystream_iseof) (const [ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream) | Returns true if all data in **httpBodyStream** has been read. | 
| bool [OH_ArkWebHttpBodyStream_IsInMemory](_web.md#oh_arkwebhttpbodystream_isinmemory) (const [ArkWeb_HttpBodyStream](_web.md#arkweb_httpbodystream) \*httpBodyStream) | Returns true if all the upload data in **httpBodyStream** is in memory and all read requests will be synchronized successfully. | 
| int32_t [OH_ArkWebResourceRequest_Destroy](_web.md#oh_arkwebresourcerequest_destroy) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest) | Destroys an **ArkWeb_ResourceRequest** object. | 
| void [OH_ArkWebResourceRequest_GetReferrer](_web.md#oh_arkwebresourcerequest_getreferrer) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest, char \*\*referrer) | Obtains the referrer of a request. | 
| void [OH_ArkWebResourceRequest_GetRequestHeaders](_web.md#oh_arkwebresourcerequest_getrequestheaders) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest, [ArkWeb_RequestHeaderList](_web.md#arkweb_requestheaderlist) \*\*requestHeaderList) | Obtains the **OH_ArkWeb_RequestHeaderList**. | 
| bool [OH_ArkWebResourceRequest_IsRedirect](_web.md#oh_arkwebresourcerequest_isredirect) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest) | Determines whether a request is redirect. | 
| bool [OH_ArkWebResourceRequest_IsMainFrame](_web.md#oh_arkwebresourcerequest_ismainframe) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest) | Determines whether a request is from main frame. | 
| bool [OH_ArkWebResourceRequest_HasGesture](_web.md#oh_arkwebresourcerequest_hasgesture) (const [ArkWeb_ResourceRequest](_web.md#arkweb_resourcerequest) \*resourceRequest) | Determines whether a request is triggered by a user gesture. | 
| int32_t [OH_ArkWeb_RegisterCustomSchemes](_web.md#oh_arkweb_registercustomschemes) (const char \*scheme, int32_t option) | Registers a custom scheme with the **ArkWeb**. | 
| bool [OH_ArkWebServiceWorker_SetSchemeHandler](_web.md#oh_arkwebserviceworker_setschemehandler) (const char \*scheme, [ArkWeb_SchemeHandler](_web.md#arkweb_schemehandler) \*schemeHandler) | Sets an **ArkWeb_SchemeHandler** for a specified scheme to intercept requests of the scheme type triggered by **ServiceWorker**. | 
| bool [OH_ArkWeb_SetSchemeHandler](_web.md#oh_arkweb_setschemehandler) (const char \*scheme, const char \*webTag, [ArkWeb_SchemeHandler](_web.md#arkweb_schemehandler) \*schemeHandler) | Sets an **ArkWeb_SchemeHandler** for a specified scheme to intercept requests of the scheme. | 
| int32_t [OH_ArkWebServiceWorker_ClearSchemeHandlers](_web.md#oh_arkwebserviceworker_clearschemehandlers) () | Clears the **SchemeHandler** registered for **ServiceWorker**. | 
| int32_t [OH_ArkWeb_ClearSchemeHandlers](_web.md#oh_arkweb_clearschemehandlers) (const char \*webTag) | Clears the **SchemeHandler** registered for the specified web. | 
| void [OH_ArkWeb_CreateSchemeHandler](_web.md#oh_arkweb_createschemehandler) ([ArkWeb_SchemeHandler](_web.md#arkweb_schemehandler) \*\*schemeHandler) | Creates an **ArkWeb_SchemeHandler** object. | 
| void [OH_ArkWeb_DestroySchemeHandler](_web.md#oh_arkweb_destroyschemehandler) ([ArkWeb_SchemeHandler](_web.md#arkweb_schemehandler) \*schemeHandler) | Destroys an **ArkWeb_SchemeHandler** object. | 
| int32_t [OH_ArkWebSchemeHandler_SetUserData](_web.md#oh_arkwebschemehandler_setuserdata) ([ArkWeb_SchemeHandler](_web.md#arkweb_schemehandler) \*schemeHandler, void \*userData) | Sets user data to the **ArkWeb_SchemeHandler** object. | 
| void \* [OH_ArkWebSchemeHandler_GetUserData](_web.md#oh_arkwebschemehandler_getuserdata) (const [ArkWeb_SchemeHandler](_web.md#arkweb_schemehandler) \*schemeHandler) | Obtains the user data from **ArkWeb_SchemeHandler**. | 
| int32_t [OH_ArkWebSchemeHandler_SetOnRequestStart](_web.md#oh_arkwebschemehandler_setonrequeststart) ([ArkWeb_SchemeHandler](_web.md#arkweb_schemehandler) \*schemeHandler, [ArkWeb_OnRequestStart](_web.md#arkweb_onrequeststart) onRequestStart) | Sets an **OnRequestStart** callback for SchemeHandler. | 
| int32_t [OH_ArkWebSchemeHandler_SetOnRequestStop](_web.md#oh_arkwebschemehandler_setonrequeststop) ([ArkWeb_SchemeHandler](_web.md#arkweb_schemehandler) \*schemeHandler, [ArkWeb_OnRequestStop](_web.md#arkweb_onrequeststop) onRequestStop) | Sets an **OnRequestStop** callback for SchemeHandler. | 
| void [OH_ArkWeb_CreateResponse](_web.md#oh_arkweb_createresponse) ([ArkWeb_Response](_web.md#arkweb_response) \*\*response) | Creates an **ArkWeb_Response** object for the intercepted request. | 
| void [OH_ArkWeb_DestroyResponse](_web.md#oh_arkweb_destroyresponse) ([ArkWeb_Response](_web.md#arkweb_response) \*response) | Destroys an **ArkWeb_Response** object. | 
| int32_t [OH_ArkWebResponse_SetUrl](_web.md#oh_arkwebresponse_seturl) ([ArkWeb_Response](_web.md#arkweb_response) \*response, const char \*url) | Sets the parsed URL that is redirected or changed due to HSTS. After the setting, redirection is triggered. | 
| void [OH_ArkWebResponse_GetUrl](_web.md#oh_arkwebresponse_geturl) (const [ArkWeb_Response](_web.md#arkweb_response) \*response, char \*\*url) | Obtains the parsed URL that has been redirected or changed due to HSTS. | 
| int32_t [OH_ArkWebResponse_SetError](_web.md#oh_arkwebresponse_seterror) ([ArkWeb_Response](_web.md#arkweb_response) \*response, [ArkWeb_NetError](_web.md#arkweb_neterror) errorCode) | Sets an error code for the **ArkWeb_Response** object. | 
| [ArkWeb_NetError](_web.md#arkweb_neterror) [OH_ArkWebResponse_GetError](_web.md#oh_arkwebresponse_geterror) (const [ArkWeb_Response](_web.md#arkweb_response) \*response) | Obtains the error code of **ArkWeb_Response**. | 
| int32_t [OH_ArkWebResponse_SetStatus](_web.md#oh_arkwebresponse_setstatus) ([ArkWeb_Response](_web.md#arkweb_response) \*response, int status) | Sets an HTTP status code for the **ArkWeb_Response** object. | 
| int [OH_ArkWebResponse_GetStatus](_web.md#oh_arkwebresponse_getstatus) (const [ArkWeb_Response](_web.md#arkweb_response) \*response) | Obtains the HTTP status code of **ArkWeb_Response**. | 
| int32_t [OH_ArkWebResponse_SetStatusText](_web.md#oh_arkwebresponse_setstatustext) ([ArkWeb_Response](_web.md#arkweb_response) \*response, const char \*statusText) | Sets the status text for **ArkWeb_Response**. | 
| void [OH_ArkWebResponse_GetStatusText](_web.md#oh_arkwebresponse_getstatustext) (const [ArkWeb_Response](_web.md#arkweb_response) \*response, char \*\*statusText) | Obtains the status text of **ArkWeb_Response**. | 
| int32_t [OH_ArkWebResponse_SetMimeType](_web.md#oh_arkwebresponse_setmimetype) ([ArkWeb_Response](_web.md#arkweb_response) \*response, const char \*mimeType) | Sets the media type for **ArkWeb_Response**. | 
| void [OH_ArkWebResponse_GetMimeType](_web.md#oh_arkwebresponse_getmimetype) (const [ArkWeb_Response](_web.md#arkweb_response) \*response, char \*\*mimeType) | Obtains the media type of **ArkWeb_Response**. | 
| int32_t [OH_ArkWebResponse_SetCharset](_web.md#oh_arkwebresponse_setcharset) ([ArkWeb_Response](_web.md#arkweb_response) \*response, const char \*charset) | Sets the character set for **ArkWeb_Response**. | 
| void [OH_ArkWebResponse_GetCharset](_web.md#oh_arkwebresponse_getcharset) (const [ArkWeb_Response](_web.md#arkweb_response) \*response, char \*\*charset) | Obtains the character set of **ArkWeb_Response**. | 
| int32_t [OH_ArkWebResponse_SetHeaderByName](_web.md#oh_arkwebresponse_setheaderbyname) ([ArkWeb_Response](_web.md#arkweb_response) \*response, const char \*name, const char \*value, bool overwrite) | Sets a header for **ArkWeb_Response**. | 
| void [OH_ArkWebResponse_GetHeaderByName](_web.md#oh_arkwebresponse_getheaderbyname) (const [ArkWeb_Response](_web.md#arkweb_response) \*response, const char \*name, char \*\*value) | Obtains the header from **ArkWeb_Response**. | 
| int32_t [OH_ArkWebResourceHandler_Destroy](_web.md#oh_arkwebresourcehandler_destroy) (const [ArkWeb_ResourceHandler](_web.md#arkweb_resourcehandler) \*resourceHandler) | Destroys an **ArkWeb_ResourceHandler** object. | 
| int32_t [OH_ArkWebResourceHandler_DidReceiveResponse](_web.md#oh_arkwebresourcehandler_didreceiveresponse) (const [ArkWeb_ResourceHandler](_web.md#arkweb_resourcehandler) \*resourceHandler, const [ArkWeb_Response](_web.md#arkweb_response) \*response) | Sends a response header to the intercepted request. **OH_ArkWebResourceHandler_DidReceiveResponse** is mandatory. If an error occurs before the response is received, set an error in the response and notify the kernel by calling this function. | 
| int32_t [OH_ArkWebResourceHandler_DidReceiveData](_web.md#oh_arkwebresourcehandler_didreceivedata) (const [ArkWeb_ResourceHandler](_web.md#arkweb_resourcehandler) \*resourceHandler, const uint8_t \*buffer, int64_t bufLen) | Sends a response body to the intercepted request. | 
| int32_t [OH_ArkWebResourceHandler_DidFinish](_web.md#oh_arkwebresourcehandler_didfinish) (const [ArkWeb_ResourceHandler](_web.md#arkweb_resourcehandler) \*resourceHandler) | Notifies the ArkWeb kernel that the intercepted request has been finished and that no more data is available. | 
| int32_t [OH_ArkWebResourceHandler_DidFailWithError](_web.md#oh_arkwebresourcehandler_didfailwitherror) (const [ArkWeb_ResourceHandler](_web.md#arkweb_resourcehandler) \*resourceHandler, [ArkWeb_NetError](_web.md#arkweb_neterror) errorCode) | Notifies the ArkWeb kernel that the intercepted request fails. | 
| void [OH_ArkWeb_ReleaseString](_web.md#oh_arkweb_releasestring) (char \*string) | Releases the string created by NDK APIs. | 
| void [OH_ArkWeb_ReleaseByteArray](_web.md#oh_arkweb_releasebytearray) (uint8_t \*byteArray) | Releases the byte array created by NDK APIs. | 
