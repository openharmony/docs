# arkweb_scheme_handler.h

## Overview

Declares the APIs used to intercept requests from ArkWeb.

**Library**: libohweb.so

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Related module**: [Web](capi-web.md)

**Example**: <!--RP1-->[ArkWebSchemeHandler](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkWeb/ArkWebSchemeHandler)<!--RP1End-->

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ArkWeb_SchemeHandler_](capi-web-arkweb-schemehandler.md) | ArkWeb_SchemeHandler | Defines a handler used to intercept requests of a specified scheme.|
| [ArkWeb_ResourceHandler_](capi-web-arkweb-resourcehandler.md) | ArkWeb_ResourceHandler | Defines a handler used to intercept URL requests. You can use **ArkWeb_ResourceHandler** to send custom request headers and bodies.|
| [ArkWeb_Response_](capi-web-arkweb-response.md) | ArkWeb_Response | Defines an **ArkWeb_Response** for the intercepted request.|
| [ArkWeb_ResourceRequest_](capi-web-arkweb-resourcerequest.md) | ArkWeb_ResourceRequest | Defines a kernel request. You can use **OH_ArkWeb_ResourceRequest** to obtain the URL, method, post data, and other information of the request.|
| [ArkWeb_RequestHeaderList_](capi-web-arkweb-requestheaderlist.md) | ArkWeb_RequestHeaderList | Defines a request header list.|
| [ArkWeb_HttpBodyStream_](capi-web-arkweb-httpbodystream.md) | ArkWeb_HttpBodyStream | Defines the uploaded data of a request. You can use the **OH_ArkWebHttpBodyStream_** API to read the uploaded data.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ArkWeb_CustomSchemeOption](#arkweb_customschemeoption) | ArkWeb_CustomSchemeOption | Enumerates the custom scheme options.|
| [ArkWeb_ResourceType](#arkweb_resourcetype) | ArkWeb_ResourceType | Enumerates the resource types. The resource types match the corresponding items of **ResourceType** in Chromium and should not be renumbered.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*ArkWeb_OnRequestStart)(const ArkWeb_SchemeHandler* schemeHandler,ArkWeb_ResourceRequest* resourceRequest,const ArkWeb_ResourceHandler* resourceHandler,bool* intercept)](#arkweb_onrequeststart) | ArkWeb_OnRequestStart | Called when a request starts. This callback is used on the IO thread.|
| [typedef void (\*ArkWeb_OnRequestStop)(const ArkWeb_SchemeHandler* schemeHandler,const ArkWeb_ResourceRequest* resourceRequest)](#arkweb_onrequeststop) | ArkWeb_OnRequestStop | Called when the request stops. This callback is used on the IO thread.<br>You can use **ArkWeb_ResourceRequest_Destroy** to destroy **resourceRequest**,<br>and **ArkWeb_ResourceHandler_Destroy** to destroy the **ArkWeb_ResourceHandler** received in **ArkWeb_OnRequestStart**.|
| [typedef void (\*ArkWeb_HttpBodyStreamReadCallback)(const ArkWeb_HttpBodyStream* httpBodyStream,uint8_t* buffer,int bytesRead)](#arkweb_httpbodystreamreadcallback) | ArkWeb_HttpBodyStreamReadCallback | Called when **OH_ArkWebHttpBodyStream_Read** is complete.|
| [typedef void (\*ArkWeb_HttpBodyStreamAsyncReadCallback)(const ArkWeb_HttpBodyStream* httpBodyStream,uint8_t* buffer,int bytesRead)](#arkweb_httpbodystreamasyncreadcallback) | ArkWeb_HttpBodyStreamAsyncReadCallback | Called when **OH_ArkWebHttpBodyStream_AsyncRead** is complete.|
| [typedef void (\*ArkWeb_HttpBodyStreamInitCallback)(const ArkWeb_HttpBodyStream* httpBodyStream, ArkWeb_NetError result)](#arkweb_httpbodystreaminitcallback) | ArkWeb_HttpBodyStreamInitCallback | Called when **ArkWeb_HttpBodyStream** initialization is complete.|
| [void OH_ArkWebRequestHeaderList_Destroy(ArkWeb_RequestHeaderList* requestHeaderList)](#oh_arkwebrequestheaderlist_destroy) | - | Destroys an **ArkWeb_RequestHeaderList** object.|
| [int32_t OH_ArkWebRequestHeaderList_GetSize(const ArkWeb_RequestHeaderList* requestHeaderList)](#oh_arkwebrequestheaderlist_getsize) | - | Obtains the size of a request header list.|
| [void OH_ArkWebRequestHeaderList_GetHeader(const ArkWeb_RequestHeaderList* requestHeaderList,int32_t index,char** key,char** value)](#oh_arkwebrequestheaderlist_getheader) | - | Obtains a specified request header.|
| [int32_t OH_ArkWebResourceRequest_SetUserData(ArkWeb_ResourceRequest* resourceRequest, void* userData)](#oh_arkwebresourcerequest_setuserdata) | - | Sets user data to the **ArkWeb_ResourceRequest** object.|
| [void* OH_ArkWebResourceRequest_GetUserData(const ArkWeb_ResourceRequest* resourceRequest)](#oh_arkwebresourcerequest_getuserdata) | - | Obtains user data from **ArkWeb_ResourceRequest**.|
| [void OH_ArkWebResourceRequest_GetMethod(const ArkWeb_ResourceRequest* resourceRequest, char** method)](#oh_arkwebresourcerequest_getmethod) | - | Obtains the method of a request.|
| [void OH_ArkWebResourceRequest_GetUrl(const ArkWeb_ResourceRequest* resourceRequest, char** url)](#oh_arkwebresourcerequest_geturl) | - | Obtains the URL of a request.|
| [void OH_ArkWebResourceRequest_GetHttpBodyStream(const ArkWeb_ResourceRequest* resourceRequest,ArkWeb_HttpBodyStream** httpBodyStream)](#oh_arkwebresourcerequest_gethttpbodystream) | - | Creates an **ArkWeb_HttpBodyStream** to read the uploaded data of the request.|
| [void OH_ArkWebResourceRequest_DestroyHttpBodyStream(ArkWeb_HttpBodyStream* httpBodyStream)](#oh_arkwebresourcerequest_destroyhttpbodystream) | - | Destroys an **ArkWeb_HttpBodyStream** object.|
| [int32_t OH_ArkWebResourceRequest_GetResourceType(const ArkWeb_ResourceRequest* resourceRequest)](#oh_arkwebresourcerequest_getresourcetype) | - | Obtains the resource type of a request.|
| [void OH_ArkWebResourceRequest_GetFrameUrl(const ArkWeb_ResourceRequest* resourceRequest, char** frameUrl)](#oh_arkwebresourcerequest_getframeurl) | - | Obtains the URL of the frame that triggers the request.|
| [int32_t OH_ArkWebHttpBodyStream_SetUserData(ArkWeb_HttpBodyStream* httpBodyStream, void* userData)](#oh_arkwebhttpbodystream_setuserdata) | - | Sets user data to the **ArkWeb_HttpBodyStream** object.|
| [void* OH_ArkWebHttpBodyStream_GetUserData(const ArkWeb_HttpBodyStream* httpBodyStream)](#oh_arkwebhttpbodystream_getuserdata) | - | Obtains user data from **ArkWeb_HttpBodyStream**.|
| [int32_t OH_ArkWebHttpBodyStream_SetReadCallback(ArkWeb_HttpBodyStream* httpBodyStream,ArkWeb_HttpBodyStreamReadCallback readCallback)](#oh_arkwebhttpbodystream_setreadcallback) | - | Sets a callback for **OH_ArkWebHttpBodyStream_Read**. The result of **OH_ArkWebHttpBodyStream_Read** is notified to the caller through **readCallback**,<br>which will run in the same thread as **OH_ArkWebHttpBodyStream_Read**.|
| [int32_t OH_ArkWebHttpBodyStream_SetAsyncReadCallback(ArkWeb_HttpBodyStream* httpBodyStream,ArkWeb_HttpBodyStreamReadCallback readCallback)](#oh_arkwebhttpbodystream_setasyncreadcallback) | - | Sets a callback for **OH_ArkWebHttpBodyStream_AsyncRead**. The result of **OH_ArkWebHttpBodyStream_AsyncRead** is notified to the caller through **readCallback**,<br>which will run in the same thread as **OH_ArkWebHttpBodyStream_AsyncRead**.|
| [int32_t OH_ArkWebHttpBodyStream_Init(ArkWeb_HttpBodyStream* httpBodyStream,ArkWeb_HttpBodyStreamInitCallback initCallback)](#oh_arkwebhttpbodystream_init) | - | Initializes **ArkWeb_HttpBodyStream**. This API must be called on the I/O thread before any other API is called.|
| [void OH_ArkWebHttpBodyStream_Read(const ArkWeb_HttpBodyStream* httpBodyStream, uint8_t* buffer, int bufLen)](#oh_arkwebhttpbodystream_read) | - | Exports the uploaded data of a request to the buffer. The buffer size must be greater than the value of **bufLen**. The data from the worker thread is exported to the buffer. Therefore, before the callback returns the data, the buffer should not be used in other threads to avoid concurrency problems.|
| [void OH_ArkWebHttpBodyStream_AsyncRead(const ArkWeb_HttpBodyStream* httpBodyStream, uint8_t* buffer, int bufLen)](#oh_arkwebhttpbodystream_asyncread) | - | Exports the uploaded data of a request to the buffer. The buffer size must be greater than the value of **bufLen**. The data from the worker thread is exported to the buffer. Therefore, before the callback returns the data, the buffer should not be used in other threads to avoid concurrency problems.|
| [uint64_t OH_ArkWebHttpBodyStream_GetSize(const ArkWeb_HttpBodyStream* httpBodyStream)](#oh_arkwebhttpbodystream_getsize) | - | Obtains the size of **httpBodyStream**. When data is chunked or **httpBodyStream** is invalid, **0** is always returned.|
| [uint64_t OH_ArkWebHttpBodyStream_GetPosition(const ArkWeb_HttpBodyStream* httpBodyStream)](#oh_arkwebhttpbodystream_getposition) | - | Obtains the position of **httpBodyStream**.|
| [bool OH_ArkWebHttpBodyStream_IsChunked(const ArkWeb_HttpBodyStream* httpBodyStream)](#oh_arkwebhttpbodystream_ischunked) | - | Determines whether **httpBodyStream** is chunked.|
| [bool OH_ArkWebHttpBodyStream_IsEof(const ArkWeb_HttpBodyStream* httpBodyStream)](#oh_arkwebhttpbodystream_iseof) | - | Determines whether all data in **httpBodyStream** has been read. **true** is returned if all data in **httpBodyStream** has been read. **false** is returned before the chunked **httpBodyStream** is read for the first time.|
| [bool OH_ArkWebHttpBodyStream_IsInMemory(const ArkWeb_HttpBodyStream* httpBodyStream)](#oh_arkwebhttpbodystream_isinmemory) | - | Determines whether all the uploaded data in **httpBodyStream** is in memory and all read requests are synchronized successfully. If yes, **true** is returned. **false** is returned if the data is chunked.|
| [int32_t OH_ArkWebResourceRequest_Destroy(const ArkWeb_ResourceRequest* resourceRequest)](#oh_arkwebresourcerequest_destroy) | - | Destroys an **ArkWeb_ResourceRequest** object.|
| [void OH_ArkWebResourceRequest_GetReferrer(const ArkWeb_ResourceRequest* resourceRequest, char** referrer)](#oh_arkwebresourcerequest_getreferrer) | - | Obtains the referrer of a request.|
| [void OH_ArkWebResourceRequest_GetRequestHeaders(const ArkWeb_ResourceRequest* resourceRequest,ArkWeb_RequestHeaderList** requestHeaderList)](#oh_arkwebresourcerequest_getrequestheaders) | - | Obtains an **OH_ArkWeb_RequestHeaderList**.|
| [bool OH_ArkWebResourceRequest_IsRedirect(const ArkWeb_ResourceRequest* resourceRequest)](#oh_arkwebresourcerequest_isredirect) | - | Determines whether a request is redirected.|
| [bool OH_ArkWebResourceRequest_IsMainFrame(const ArkWeb_ResourceRequest* resourceRequest)](#oh_arkwebresourcerequest_ismainframe) | - | Determines whether a request is from main frame.|
| [bool OH_ArkWebResourceRequest_HasGesture(const ArkWeb_ResourceRequest* resourceRequest)](#oh_arkwebresourcerequest_hasgesture) | - | Determines whether a request is triggered by a user gesture.|
| [int32_t OH_ArkWeb_RegisterCustomSchemes(const char* scheme, int32_t option)](#oh_arkweb_registercustomschemes) | - | Registers a custom scheme with **ArkWeb**. This function should not be called for built-in HTTP, HTTPS, FILE, FTP, ABOUT, and DATA protocols.<br>This function should be called on the main thread before kernel initialization.|
| [bool OH_ArkWebServiceWorker_SetSchemeHandler(const char* scheme, ArkWeb_SchemeHandler* schemeHandler)](#oh_arkwebserviceworker_setschemehandler) | - | Sets an **ArkWeb_SchemeHandler** for a specified scheme to intercept requests of the scheme type triggered by **ServiceWorker**. **SchemeHandler** should be set after **BrowserContext** is created.<br>You can use **WebviewController.initializeWebEngine** to initialize **BrowserContext** without creating the **Web** component.|
| [bool OH_ArkWeb_SetSchemeHandler(const char* scheme, const char* webTag, ArkWeb_SchemeHandler* schemeHandler)](#oh_arkweb_setschemehandler) | - | Sets an **ArkWeb_SchemeHandler** to intercept requests of a specified scheme type. **SchemeHandler** should be set after **BrowserContext** is created.<br>You can use **WebviewController.initializeWebEngine** to initialize **BrowserContext** without creating the **Web** component.|
| [int32_t OH_ArkWebServiceWorker_ClearSchemeHandlers()](#oh_arkwebserviceworker_clearschemehandlers) | - | Clears the **SchemeHandler** registered for **ServiceWorker**.|
| [int32_t OH_ArkWeb_ClearSchemeHandlers(const char* webTag)](#oh_arkweb_clearschemehandlers) | - | Clears the **SchemeHandler** registered for the specified **Web** component.|
| [void OH_ArkWeb_CreateSchemeHandler(ArkWeb_SchemeHandler** schemeHandler)](#oh_arkweb_createschemehandler) | - | Creates an **ArkWeb_SchemeHandler** object.|
| [void OH_ArkWeb_DestroySchemeHandler(ArkWeb_SchemeHandler* schemeHandler)](#oh_arkweb_destroyschemehandler) | - | Destroys an **ArkWeb_SchemeHandler** object.|
| [int32_t OH_ArkWebSchemeHandler_SetUserData(ArkWeb_SchemeHandler* schemeHandler, void* userData)](#oh_arkwebschemehandler_setuserdata) | - | Sets user data to the **ArkWeb_SchemeHandler** object.|
| [void* OH_ArkWebSchemeHandler_GetUserData(const ArkWeb_SchemeHandler* schemeHandler)](#oh_arkwebschemehandler_getuserdata) | - | Obtains the user data from **ArkWeb_SchemeHandler**.|
| [int32_t OH_ArkWebSchemeHandler_SetOnRequestStart(ArkWeb_SchemeHandler* schemeHandler,ArkWeb_OnRequestStart onRequestStart)](#oh_arkwebschemehandler_setonrequeststart) | - | Sets an **OnRequestStart** callback for **SchemeHandler**.|
| [int32_t OH_ArkWebSchemeHandler_SetOnRequestStop(ArkWeb_SchemeHandler* schemeHandler,ArkWeb_OnRequestStop onRequestStop)](#oh_arkwebschemehandler_setonrequeststop) | - | Sets an **OnRequestStop** callback for **SchemeHandler**.|
| [void OH_ArkWeb_CreateResponse(ArkWeb_Response** response)](#oh_arkweb_createresponse) | - | Creates an **ArkWeb_Response** object for the intercepted request.|
| [void OH_ArkWeb_DestroyResponse(ArkWeb_Response* response)](#oh_arkweb_destroyresponse) | - | Destroys an **ArkWeb_Response** object.|
| [int32_t OH_ArkWebResponse_SetUrl(ArkWeb_Response* response, const char* url)](#oh_arkwebresponse_seturl) | - | Sets a parsed URL that has been redirected or changed due to HSTS. After the setting, redirection is triggered.|
| [void OH_ArkWebResponse_GetUrl(const ArkWeb_Response* response, char** url)](#oh_arkwebresponse_geturl) | - | Obtains the parsed URL that has been redirected or changed due to HSTS.|
| [int32_t OH_ArkWebResponse_SetError(ArkWeb_Response* response, ArkWeb_NetError errorCode)](#oh_arkwebresponse_seterror) | - | Sets an error code for the **ArkWeb_Response** object.|
| [ArkWeb_NetError OH_ArkWebResponse_GetError(const ArkWeb_Response* response)](#oh_arkwebresponse_geterror) | - | Obtains the error code of **ArkWeb_Response**.|
| [int32_t OH_ArkWebResponse_SetStatus(ArkWeb_Response* response, int status)](#oh_arkwebresponse_setstatus) | - | Sets an HTTP status code for **ArkWeb_Response**.|
| [int OH_ArkWebResponse_GetStatus(const ArkWeb_Response* response)](#oh_arkwebresponse_getstatus) | - | Obtains the HTTP status code of **ArkWeb_Response**.|
| [int32_t OH_ArkWebResponse_SetStatusText(ArkWeb_Response* response, const char* statusText)](#oh_arkwebresponse_setstatustext) | - | Sets a status text for **ArkWeb_Response**.|
| [void OH_ArkWebResponse_GetStatusText(const ArkWeb_Response* response, char** statusText)](#oh_arkwebresponse_getstatustext) | - | Obtains the status text of **ArkWeb_Response**.|
| [int32_t OH_ArkWebResponse_SetMimeType(ArkWeb_Response* response, const char* mimeType)](#oh_arkwebresponse_setmimetype) | - | Sets a mime type for **ArkWeb_Response**.|
| [void OH_ArkWebResponse_GetMimeType(const ArkWeb_Response* response, char** mimeType)](#oh_arkwebresponse_getmimetype) | - | Obtains the mime type of **ArkWeb_Response**.|
| [int32_t OH_ArkWebResponse_SetCharset(ArkWeb_Response* response, const char* charset)](#oh_arkwebresponse_setcharset) | - | Sets a character set for **ArkWeb_Response**.|
| [void OH_ArkWebResponse_GetCharset(const ArkWeb_Response* response, char** charset)](#oh_arkwebresponse_getcharset) | - | Obtains the character set of **ArkWeb_Response**.|
| [int32_t OH_ArkWebResponse_SetHeaderByName(ArkWeb_Response* response,const char* name,const char* value,bool overwrite)](#oh_arkwebresponse_setheaderbyname) | - | Sets a header for **ArkWeb_Response**.|
| [void OH_ArkWebResponse_GetHeaderByName(const ArkWeb_Response* response, const char* name, char** value)](#oh_arkwebresponse_getheaderbyname) | - | Obtains the header from **ArkWeb_Response**.|
| [int32_t OH_ArkWebResourceHandler_Destroy(const ArkWeb_ResourceHandler* resourceHandler)](#oh_arkwebresourcehandler_destroy) | - | Destroys an **ArkWeb_ResourceHandler** object.|
| [int32_t OH_ArkWebResourceHandler_DidReceiveResponse(const ArkWeb_ResourceHandler* resourceHandler,const ArkWeb_Response* response)](#oh_arkwebresourcehandler_didreceiveresponse) | - | Sends a response header to the intercepted request.|
| [int32_t OH_ArkWebResourceHandler_DidReceiveData(const ArkWeb_ResourceHandler* resourceHandler,const uint8_t* buffer,int64_t bufLen)](#oh_arkwebresourcehandler_didreceivedata) | - | Sends a response body to the intercepted request.|
| [int32_t OH_ArkWebResourceHandler_DidFinish(const ArkWeb_ResourceHandler* resourceHandler)](#oh_arkwebresourcehandler_didfinish) | - | Notifies the ArkWeb kernel that the intercepted request has been finished and that no more data is available.|
| [int32_t OH_ArkWebResourceHandler_DidFailWithError(const ArkWeb_ResourceHandler* resourceHandler,ArkWeb_NetError errorCode)](#oh_arkwebresourcehandler_didfailwitherror) | - | Notifies the ArkWeb kernel that the intercepted request fails.|
| [void OH_ArkWeb_ReleaseString(char* string)](#oh_arkweb_releasestring) | - | Releases the string created by NDK APIs.|
| [void OH_ArkWeb_ReleaseByteArray(uint8_t* byteArray)](#oh_arkweb_releasebytearray) | - | Releases the byte array created by NDK APIs.|

## Enum Description

### ArkWeb_CustomSchemeOption

```
enum ArkWeb_CustomSchemeOption
```

**Description**

Enumerates the custom scheme options.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

| Enumerated Value| Description|
| -- | -- |
| ARKWEB_SCHEME_OPTION_STANDARD = 1 << 0 | The scheme is processed as a standard scheme.|
| ARKWEB_SCHEME_OPTION_LOCAL = 1 << 1 | The scheme is processed using the same security rule as the file URL.|
| ARKWEB_SCHEME_OPTION_DISPLAY_ISOLATED = 1 << 2 | The request of the scheme can be initiated only by the page that is loaded using the same scheme.|
| ARKWEB_SCHEME_OPTION_SECURE = 1 << 3 | The scheme is processed using the same security rule as the HTTPS URL.|
| ARKWEB_SCHEME_OPTION_CORS_ENABLED = 1 << 4 | The scheme can send CORS requests. In most cases, this value should be set when **ARKWEB_SCHEME_OPTION_STANDARD** is set.|
| ARKWEB_SCHEME_OPTION_CSP_BYPASSING = 1 << 5 | The scheme can bypass the Content Security Policy (CSP) check.|
| ARKWEB_SCHEME_OPTION_FETCH_ENABLED = 1 << 6 | The FETCH API request of the scheme can be initiated.|
| ARKWEB_SCHEME_OPTION_CODE_CACHE_ENABLED = 1 << 7 | The JS resources of the scheme support code cache generation.|

### ArkWeb_ResourceType

```
enum ArkWeb_ResourceType
```

**Description**

Enumerates the resource types. The resource types match the corresponding items of **ResourceType** in Chromium and should not be renumbered.<br>

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

| Enumerated Value| Description|
| -- | -- |
| MAIN_FRAME = 0 | Main frame.|
| SUB_FRAME = 1 | Frame or iframe.|
| STYLE_SHEET = 2 | Cascading Style Sheets (CSS).|
| SCRIPT = 3 | External script.|
| IMAGE = 4 | Image (JPG, GIF, PNG, or other format).|
| FONT_RESOURCE = 5 | Font.|
| SUB_RESOURCE = 6 | Other sub-resource. If the type is unknown, the default type is used.|
| OBJECT = 7 | The **Object** (or **embed**) tag of the plug-in, or the resource requested by the plug-in.|
| MEDIA = 8 | Media resource|
| WORKER = 9 | Main resource of the dedicated worker thread.|
| SHARED_WORKER = 10 | Main resource of a shared worker thread.|
| PREFETCH = 11 | Explicit prefetch request.|
| FAVICON = 12 | Website icon.|
| XHR = 13 | XMLHttpRequest.|
| PING = 14 | Ping request of **/sendBeacon**.|
| SERVICE_WORKER = 15 | Main resource of a service worker.|
| CSP_REPORT = 16 | Report of Content Security Policy violation.|
| PLUGIN_RESOURCE = 17 | Resource requested by the plug-in.|
| NAVIGATION_PRELOAD_MAIN_FRAME = 19 | Main frame redirection request that triggers service worker preloading.|
| NAVIGATION_PRELOAD_SUB_FRAME = 20 | Subframe redirection request that triggers service worker preloading.|


## Function Description

### ArkWeb_OnRequestStart()

```
typedef void (*ArkWeb_OnRequestStart)(const ArkWeb_SchemeHandler* schemeHandler,ArkWeb_ResourceRequest* resourceRequest,const ArkWeb_ResourceHandler* resourceHandler,bool* intercept)
```

**Description**

Called when a request starts. This callback is used on the IO thread.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name                                                                       | Description|
|----------------------------------------------------------------------------| -- |
| const [ArkWeb_SchemeHandler](capi-web-arkweb-schemehandler.md)* schemeHandler | **ArkWeb_SchemeHandler**.|
| [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | Object used to obtain the request information.|
| const [ArkWeb_ResourceHandler](capi-web-arkweb-resourcehandler.md)* resourceHandler                          | **ArkWeb_ResourceHandler** of the request. If **intercept** is set to **false**, this parameter should not be used.|
| bool* intercept                                                            | Whether to intercept the request. If the value is **true**, the request will be intercepted. Otherwise, the request will not be intercepted.|

### ArkWeb_OnRequestStop()

```
typedef void (*ArkWeb_OnRequestStop)(const ArkWeb_SchemeHandler* schemeHandler,const ArkWeb_ResourceRequest* resourceRequest)
```

**Description**

Called when the request stops. This callback is used on the IO thread.

You can use **ArkWeb_ResourceRequest_Destroy** to destroy the **resourceRequest** and use **ArkWeb_ResourceHandler_Destroy** to destroy the **ArkWeb_ResourceHandler** received in **ArkWeb_OnRequestStart**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_SchemeHandler](capi-web-arkweb-schemehandler.md)* schemeHandler | **ArkWeb_SchemeHandler**.|
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | **ArkWeb_ResourceRequest**.|

### ArkWeb_HttpBodyStreamReadCallback()

```
typedef void (*ArkWeb_HttpBodyStreamReadCallback)(const ArkWeb_HttpBodyStream* httpBodyStream,uint8_t* buffer,int bytesRead)
```

**Description**

Called when **OH_ArkWebHttpBodyStream_Read** is complete.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name                                            | Description|
|-------------------------------------------------| -- |
| const [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | **ArkWeb_HttpBodyStream**.|
| uint8_t* buffer                                 | Buffer for receiving data.|
| int bytesRead                                   | Callback used when **OH_ArkWebHttpBodyStream_Read** is complete. If the value of **bytesRead** is greater than 0, the **buffer** is filled with data of the **bytesRead** size. The caller can read data from the **buffer**. If **OH_ArkWebHttpBodyStream_IsEOF** is **false**, the caller can continue to read the data left.|

### ArkWeb_HttpBodyStreamAsyncReadCallback()

```
typedef void (*ArkWeb_HttpBodyStreamAsyncReadCallback)(const ArkWeb_HttpBodyStream *httpBodyStream,uint8_t *buffer,int bytesRead)
```

**Description**

Called when **OH_ArkWebHttpBodyStream_AsyncRead** is complete.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 20


**Parameters**

| Name                                            | Description|
|-------------------------------------------------| -- |
| const [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | **ArkWeb_HttpBodyStream**.|
| uint8_t* buffer                                 | Buffer for receiving data.|
| int bytesRead                                   | Byte count value of the asynchronous read operation result. If the value of **bytesRead** is greater than 0, the **buffer** is filled with data of the **bytesRead** size. You can read data from the **buffer**. If **OH_ArkWebHttpBodyStream_IsEOF** is false, you can continue to read the data left.|

### ArkWeb_HttpBodyStreamInitCallback()

```
typedef void (*ArkWeb_HttpBodyStreamInitCallback)(const ArkWeb_HttpBodyStream* httpBodyStream, ArkWeb_NetError result)
```

**Description**

Called when **ArkWeb_HttpBodyStream** initialization is complete.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name                                                                          | Description|
|-------------------------------------------------------------------------------| -- |
| const [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | **ArkWeb_HttpBodyStream**.|
| [ArkWeb_NetError](capi-arkweb-net-error-list-h.md#arkweb_neterror) result     | Operation result. If the operation is successful, **ARKWEB_NET_OK** is returned. Otherwise, see [arkweb_net_error_list.h](capi-arkweb-net-error-list-h.md).|

### OH_ArkWebRequestHeaderList_Destroy()

```
void OH_ArkWebRequestHeaderList_Destroy(ArkWeb_RequestHeaderList* requestHeaderList)
```

**Description**

Destroys an **ArkWeb_RequestHeaderList** object.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkWeb_RequestHeaderList](capi-web-arkweb-requestheaderlist.md)* requestHeaderList | The **ArkWeb_RequestHeaderList** to be destroyed.|

### OH_ArkWebRequestHeaderList_GetSize()

```
int32_t OH_ArkWebRequestHeaderList_GetSize(const ArkWeb_RequestHeaderList* requestHeaderList)
```

**Description**

Obtains the size of a request header list.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_RequestHeaderList](capi-web-arkweb-requestheaderlist.md)* requestHeaderList | Request header list.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Size of the request header. If **requestHeaderList** is invalid, the value is **-1**.|

### OH_ArkWebRequestHeaderList_GetHeader()

```
void OH_ArkWebRequestHeaderList_GetHeader(const ArkWeb_RequestHeaderList* requestHeaderList,int32_t index,char** key,char** value)
```

**Description**

Obtains a specified request header.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const ArkWeb_RequestHeaderList* requestHeaderList | Request header list.|
| int32_t index | Index of the request header.|
| char** key | Key of the request header. You should use the **OH_ArkWeb_ReleaseString** function to release this string.|
| char** value | Value of the request header. You should use the **OH_ArkWeb_ReleaseString** function to release this string.|

### OH_ArkWebResourceRequest_SetUserData()

```
int32_t OH_ArkWebResourceRequest_SetUserData(ArkWeb_ResourceRequest* resourceRequest, void* userData)
```

**Description**

Sets user data to the **ArkWeb_ResourceRequest** object.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | **ArkWeb_ResourceRequest**.|
| void* userData | User data to be set.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned when the operation is successful; **17100101** is returned when the parameter is invalid.|

### OH_ArkWebResourceRequest_GetUserData()

```
void* OH_ArkWebResourceRequest_GetUserData(const ArkWeb_ResourceRequest* resourceRequest)
```

**Description**

Obtains user data from **ArkWeb_ResourceRequest**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | **ArkWeb_ResourceRequest**.|

**Returns**

| Type| Description|
| -- | -- |
| void* | User data.|

### OH_ArkWebResourceRequest_GetMethod()

```
void OH_ArkWebResourceRequest_GetMethod(const ArkWeb_ResourceRequest* resourceRequest, char** method)
```

**Description**

Obtains the method of a request.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | **ArkWeb_ResourceRequest**.|
| char** method | HTTP request method. This function allocates memory for the **method** string. You should use **OH_ArkWeb_ReleaseString** to release the string.|

### OH_ArkWebResourceRequest_GetUrl()

```
void OH_ArkWebResourceRequest_GetUrl(const ArkWeb_ResourceRequest* resourceRequest, char** url)
```

**Description**

Obtains the URL of a request.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | **ArkWeb_ResourceRequest**.|
| char** url | URL of a request. This function allocates memory for the **url** string. You should release the string using **OH_ArkWeb_ReleaseString**.|

### OH_ArkWebResourceRequest_GetHttpBodyStream()

```
void OH_ArkWebResourceRequest_GetHttpBodyStream(const ArkWeb_ResourceRequest* resourceRequest,ArkWeb_HttpBodyStream** httpBodyStream)
```

**Description**

Creates an **ArkWeb_HttpBodyStream** to read the uploaded data of the request.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | **ArkWeb_ResourceRequest**.|
| [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)** httpBodyStream | Uploaded data of the request. This function allocates memory for **httpBodyStream**. You should use **OH_ArkWebResourceRequest_DestroyHttpBodyStream** to release **httpBodyStream**.|

### OH_ArkWebResourceRequest_DestroyHttpBodyStream()

```
void OH_ArkWebResourceRequest_DestroyHttpBodyStream(ArkWeb_HttpBodyStream* httpBodyStream)
```

**Description**

Destroys an **ArkWeb_HttpBodyStream** object.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | The **httpBodyStream** to be destroyed.|

### OH_ArkWebResourceRequest_GetResourceType()

```
int32_t OH_ArkWebResourceRequest_GetResourceType(const ArkWeb_ResourceRequest* resourceRequest)
```

**Description**

Obtains the resource type of a request.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | **ArkWeb_ResourceRequest**.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Resource type of a request. If **resourceRequest** is invalid, the value is **-1**.|

### OH_ArkWebResourceRequest_GetFrameUrl()

```
void OH_ArkWebResourceRequest_GetFrameUrl(const ArkWeb_ResourceRequest* resourceRequest, char** frameUrl)
```

**Description**

Obtains the URL of the frame that triggers this request.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | **ArkWeb_ResourceRequest**.|
| char** frameUrl | URL of the frame that triggers the request. This function allocates memory for the URL string. You should release the string using **OH_ArkWeb_ReleaseString**.|

### OH_ArkWebHttpBodyStream_SetUserData()

```
int32_t OH_ArkWebHttpBodyStream_SetUserData(ArkWeb_HttpBodyStream* httpBodyStream, void* userData)
```

**Description**

Sets user data to the **ArkWeb_HttpBodyStream** object.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | **ArkWeb_HttpBodyStream**.|
| void* userData | User data to be set.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned when the operation is successful; **17100101** is returned when the parameter is invalid.|

### OH_ArkWebHttpBodyStream_GetUserData()

```
void* OH_ArkWebHttpBodyStream_GetUserData(const ArkWeb_HttpBodyStream* httpBodyStream)
```

**Description**

Obtains user data from **ArkWeb_HttpBodyStream**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | **ArkWeb_HttpBodyStream**.|

**Returns**

| Type| Description|
| -- | -- |
| void* | User data.|

### OH_ArkWebHttpBodyStream_SetReadCallback()

```
int32_t OH_ArkWebHttpBodyStream_SetReadCallback(ArkWeb_HttpBodyStream* httpBodyStream,ArkWeb_HttpBodyStreamReadCallback readCallback)
```

**Description**

Sets a callback for **OH_ArkWebHttpBodyStream_Read**. The result of **OH_ArkWebHttpBodyStream_Read** is notified to the caller through **readCallback**,<br>which will run in the same thread as **OH_ArkWebHttpBodyStream_Read**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | **ArkWeb_HttpBodyStream**.|
| [ArkWeb_HttpBodyStreamReadCallback](#arkweb_httpbodystreamreadcallback) readCallback | Callback of **OH_ArkWebHttpBodyStream_Read**.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned when the operation is successful; **17100101** is returned when the parameter is invalid.|

### OH_ArkWebHttpBodyStream_SetAsyncReadCallback()

```
int32_t OH_ArkWebHttpBodyStream_SetAsyncReadCallback(ArkWeb_HttpBodyStream* httpBodyStream,ArkWeb_HttpBodyStreamAsyncReadCallback readCallback)
```

**Description**

Sets a callback for **OH_ArkWebHttpBodyStream_AsyncRead**. The result of **OH_ArkWebHttpBodyStream_AsyncRead** is notified to the caller through **readCallback**,<br>which runs in the ArkWeb worker thread.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | **ArkWeb_HttpBodyStream**.|
| [ArkWeb_HttpBodyStreamAsyncReadCallback](#arkweb_httpbodystreamasyncreadcallback) readCallback | Callback of **OH_ArkWebHttpBodyStream_AsyncRead**.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned when the operation is successful; **17100101** is returned when the parameter is invalid.|


### OH_ArkWebHttpBodyStream_Init()

```
int32_t OH_ArkWebHttpBodyStream_Init(ArkWeb_HttpBodyStream* httpBodyStream,ArkWeb_HttpBodyStreamInitCallback initCallback)
```

**Description**

Initializes **ArkWeb_HttpBodyStream**. This API must be called on the I/O thread before any other API is called.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | **ArkWeb_HttpBodyStream**.|
| [ArkWeb_HttpBodyStreamInitCallback](#arkweb_httpbodystreaminitcallback) initCallback | Callback of the initialization.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned when the operation is successful; **17100101** is returned when the parameter is invalid.|

### OH_ArkWebHttpBodyStream_Read()

```
void OH_ArkWebHttpBodyStream_Read(const ArkWeb_HttpBodyStream* httpBodyStream, uint8_t* buffer, int bufLen)
```

**Description**

Exports the uploaded data of a request to the buffer. The buffer size must be greater than the value of **bufLen**. The data from the worker thread is exported to the buffer. Therefore, before the callback returns the data, the buffer should not be used in other threads to avoid concurrency problems.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | **ArkWeb_HttpBodyStream**.|
| uint8_t* buffer | Buffer for receiving data.|
| int bufLen | Size of the byte to be read.|

### OH_ArkWebHttpBodyStream_AsyncRead()

```
void OH_ArkWebHttpBodyStream_AsyncRead(const ArkWeb_HttpBodyStream* httpBodyStream, uint8_t* buffer, int bufLen)
```

**Description**

Exports the uploaded data of a request to the buffer. The buffer size must be greater than the value of **bufLen**.  The data from the worker thread is exported to the buffer. Therefore, before the callback returns the data, the buffer should not be used in other threads to avoid concurrency problems.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | **ArkWeb_HttpBodyStream**.|
| uint8_t* buffer | Buffer for receiving data.|
| int bufLen | Size of the byte to be read.|

### OH_ArkWebHttpBodyStream_GetSize()

```
uint64_t OH_ArkWebHttpBodyStream_GetSize(const ArkWeb_HttpBodyStream* httpBodyStream)
```

**Description**

Obtains the size of **httpBodyStream**. When data is chunked or **httpBodyStream** is invalid, **0** is always returned.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | **ArkWeb_HttpBodyStream**.|

**Returns**

| Type| Description|
| -- | -- |
| uint64_t | Size of **httpBodyStream**.|

### OH_ArkWebHttpBodyStream_GetPosition()

```
uint64_t OH_ArkWebHttpBodyStream_GetPosition(const ArkWeb_HttpBodyStream* httpBodyStream)
```

**Description**

Obtains the position of **httpBodyStream**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | **ArkWeb_HttpBodyStream**.|

**Returns**

| Type| Description|
| -- | -- |
| uint64_t | Position of **httpBodyStream**. If **httpBodyStream** is invalid, the position value is **0**.|

### OH_ArkWebHttpBodyStream_IsChunked()

```
bool OH_ArkWebHttpBodyStream_IsChunked(const ArkWeb_HttpBodyStream* httpBodyStream)
```

**Description**

Determines whether **httpBodyStream** is chunked.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | **ArkWeb_HttpBodyStream**.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** is returned if **httpBodyStream** is chunked. Otherwise, **false** is returned.|

### OH_ArkWebHttpBodyStream_IsEof()

```
bool OH_ArkWebHttpBodyStream_IsEof(const ArkWeb_HttpBodyStream* httpBodyStream)
```

**Description**

Determines whether all data in **httpBodyStream** has been read. **true** is returned if all data in **httpBodyStream** has been read. **false** is returned before the chunked **httpBodyStream** is read for the first time.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | **ArkWeb_HttpBodyStream**.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** is returned if all data has been read. Otherwise, **false** is returned.|

### OH_ArkWebHttpBodyStream_IsInMemory()

```
bool OH_ArkWebHttpBodyStream_IsInMemory(const ArkWeb_HttpBodyStream* httpBodyStream)
```

**Description**

Determines whether all the uploaded data in **httpBodyStream** is in memory and all read requests are synchronized successfully. If yes, **true** is returned. **false** is returned if the data is chunked.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_HttpBodyStream](capi-web-arkweb-httpbodystream.md)* httpBodyStream | **ArkWeb_HttpBodyStream**.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** is returned if all the uploaded data is stored in the memory. Otherwise, **false** is returned.|

### OH_ArkWebResourceRequest_Destroy()

```
int32_t OH_ArkWebResourceRequest_Destroy(const ArkWeb_ResourceRequest* resourceRequest)
```

**Description**

Destroys an **ArkWeb_ResourceRequest** object.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | **ArkWeb_ResourceRequest**.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned when the operation is successful; **17100101** is returned when the parameter is invalid.|

### OH_ArkWebResourceRequest_GetReferrer()

```
void OH_ArkWebResourceRequest_GetReferrer(const ArkWeb_ResourceRequest* resourceRequest, char** referrer)
```

**Description**

Obtains the referrer of a request.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | **ArkWeb_ResourceRequest**.|
| char** referrer | **referrer** of a request. This function allocates memory for the **referrer** string. You should use **OH_ArkWeb_ReleaseString** to release the string.|

### OH_ArkWebResourceRequest_GetRequestHeaders()

```
void OH_ArkWebResourceRequest_GetRequestHeaders(const ArkWeb_ResourceRequest* resourceRequest,ArkWeb_RequestHeaderList** requestHeaderList)
```

**Description**

Obtains an **OH_ArkWeb_RequestHeaderList**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | **ArkWeb_ResourceRequest**.|
| [ArkWeb_RequestHeaderList](capi-web-arkweb-requestheaderlist.md)** requestHeaderList | List of request headers.|

### OH_ArkWebResourceRequest_IsRedirect()

```
bool OH_ArkWebResourceRequest_IsRedirect(const ArkWeb_ResourceRequest* resourceRequest)
```

**Description**

Determines whether a request is redirected.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | **ArkWeb_ResourceRequest**.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** is returned if this request is redirected. Otherwise, **false** is returned.|

### OH_ArkWebResourceRequest_IsMainFrame()

```
bool OH_ArkWebResourceRequest_IsMainFrame(const ArkWeb_ResourceRequest* resourceRequest)
```

**Description**

Determines whether a request is from main frame.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | **ArkWeb_ResourceRequest**.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** is returned if this request is from the main framework. Otherwise, **false** is returned.|

### OH_ArkWebResourceRequest_HasGesture()

```
bool OH_ArkWebResourceRequest_HasGesture(const ArkWeb_ResourceRequest* resourceRequest)
```

**Description**

Determines whether a request is triggered by a user gesture.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_ResourceRequest](capi-web-arkweb-resourcerequest.md)* resourceRequest | **ArkWeb_ResourceRequest**.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** is returned if this request is triggered by a user gesture. Otherwise, **false** is returned.|

### OH_ArkWeb_RegisterCustomSchemes()

```
int32_t OH_ArkWeb_RegisterCustomSchemes(const char* scheme, int32_t option)
```

**Description**

Registers a custom scheme with **ArkWeb**. This function should not be called for built-in HTTP, HTTPS, FILE, FTP, ABOUT, and DATA protocols. This function should be called on the main thread before kernel initialization.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char* scheme | Scheme to be registered.|
| int32_t option | Scheme options.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned if the operation is successful. **17100100** is returned if an unknown error occurs. **17100101** is returned if the parameter is invalid. **17100102** is returned if the scheme configuration fails to be registered, which must be registered before the **Web** component is created.|

### OH_ArkWebServiceWorker_SetSchemeHandler()

```
bool OH_ArkWebServiceWorker_SetSchemeHandler(const char* scheme, ArkWeb_SchemeHandler* schemeHandler)
```

**Description**

Sets an **ArkWeb_SchemeHandler** for a specified scheme to intercept requests of the scheme type triggered by **ServiceWorker**. **SchemeHandler** should be set after **BrowserContext** is created.

You can use **WebviewController.initializeWebEngine** to initialize **BrowserContext** without creating the **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char* scheme | Scheme to be intercepted.|
| [ArkWeb_SchemeHandler](capi-web-arkweb-schemehandler.md)* schemeHandler | **ArkWeb_SchemeHandler** of the scheme. Only requests triggered by **ServiceWorker** are notified through this **schemeHandler**.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** is returned if the **SchemeHandler** is successfully set for the specified scheme. Otherwise, **false** is returned.|

### OH_ArkWeb_SetSchemeHandler()

```
bool OH_ArkWeb_SetSchemeHandler(const char* scheme, const char* webTag, ArkWeb_SchemeHandler* schemeHandler)
```

**Description**

Sets an **ArkWeb_SchemeHandler** to intercept requests of a specified scheme type. **SchemeHandler** should be set after **BrowserContext** is created.

You can use **WebviewController.initializeWebEngine** to initialize **BrowserContext** without creating the **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char* scheme | Scheme to be intercepted.|
| const char* webTag | Tag that uniquely identifies a **Web** component. Ensure that it is unique.|
| [ArkWeb_SchemeHandler](capi-web-arkweb-schemehandler.md)* schemeHandler | **ArkWeb_SchemeHandler** of the scheme. Only requests triggered from the specified web are notified through this **SchemeHandler**.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** is returned if the **SchemeHandler** is successfully set for the specified scheme. Otherwise, **false** is returned.|

### OH_ArkWebServiceWorker_ClearSchemeHandlers()

```
int32_t OH_ArkWebServiceWorker_ClearSchemeHandlers()
```

**Description**

Clears the **SchemeHandler** registered for **ServiceWorker**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned if the operation is successful.|

### OH_ArkWeb_ClearSchemeHandlers()

```
int32_t OH_ArkWeb_ClearSchemeHandlers(const char* webTag)
```

**Description**

Clears the **SchemeHandler** registered for the specified **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Tag that uniquely identifies a **Web** component. Ensure that it is unique.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned when the operation is successful; **17100101** is returned when the parameter is invalid.|

### OH_ArkWeb_CreateSchemeHandler()

```
void OH_ArkWeb_CreateSchemeHandler(ArkWeb_SchemeHandler** schemeHandler)
```

**Description**

Creates an **ArkWeb_SchemeHandler** object.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkWeb_SchemeHandler](capi-web-arkweb-schemehandler.md)** schemeHandler | A created **ArkWeb_SchemeHandler**. You can use **OH_ArkWeb_DestoryschemeHandler** to destroy it when it is not needed.|

### OH_ArkWeb_DestroySchemeHandler()

```
void OH_ArkWeb_DestroySchemeHandler(ArkWeb_SchemeHandler* schemeHandler)
```

**Description**

Destroys an **ArkWeb_SchemeHandler** object.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkWeb_SchemeHandler](capi-web-arkweb-schemehandler.md)* schemeHandler | The **ArkWeb_SchemeHandler** to be destroyed.|

### OH_ArkWebSchemeHandler_SetUserData()

```
int32_t OH_ArkWebSchemeHandler_SetUserData(ArkWeb_SchemeHandler* schemeHandler, void* userData)
```

**Description**

Sets user data to the **ArkWeb_SchemeHandler** object.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkWeb_SchemeHandler](capi-web-arkweb-schemehandler.md)* schemeHandler | **ArkWeb_SchemeHandler**.|
| void* userData | User data to be set.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned when the operation is successful; **17100101** is returned when the parameter is invalid.|

### OH_ArkWebSchemeHandler_GetUserData()

```
void* OH_ArkWebSchemeHandler_GetUserData(const ArkWeb_SchemeHandler* schemeHandler)
```

**Description**

Obtains the user data from **ArkWeb_SchemeHandler**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_SchemeHandler](capi-web-arkweb-schemehandler.md)* schemeHandler | **ArkWeb_SchemeHandler**.|

**Returns**

| Type| Description|
| -- | -- |
| void* | User data.|

### OH_ArkWebSchemeHandler_SetOnRequestStart()

```
int32_t OH_ArkWebSchemeHandler_SetOnRequestStart(ArkWeb_SchemeHandler* schemeHandler,ArkWeb_OnRequestStart onRequestStart)
```

**Description**

Sets an **OnRequestStart** callback for **SchemeHandler**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkWeb_SchemeHandler](capi-web-arkweb-schemehandler.md)* schemeHandler | **SchemeHandler** of the scheme.|
| [ArkWeb_OnRequestStart](#arkweb_onrequeststart) onRequestStart | The callback function **OnRequestStart**.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned when the operation is successful; **17100101** is returned when the parameter is invalid.|

### OH_ArkWebSchemeHandler_SetOnRequestStop()

```
int32_t OH_ArkWebSchemeHandler_SetOnRequestStop(ArkWeb_SchemeHandler* schemeHandler,ArkWeb_OnRequestStop onRequestStop)
```

**Description**

Sets an **OnRequestStop** callback for **SchemeHandler**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkWeb_SchemeHandler](capi-web-arkweb-schemehandler.md)* schemeHandler | **SchemeHandler** of the scheme.|
| [ArkWeb_OnRequestStop](#arkweb_onrequeststop) onRequestStop | The callback function **OnRequestStop**.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned when the operation is successful; **17100101** is returned when the parameter is invalid.|

### OH_ArkWeb_CreateResponse()

```
void OH_ArkWeb_CreateResponse(ArkWeb_Response** response)
```

**Description**

Creates an **ArkWeb_Response** object for the intercepted request.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkWeb_Response](capi-web-arkweb-response.md)** response | A created **ArkWeb_Response**. Use **OH_ArkWeb_DestoryResponse** to destroy it when it is not required.|

### OH_ArkWeb_DestroyResponse()

```
void OH_ArkWeb_DestroyResponse(ArkWeb_Response* response)
```

**Description**

Destroys an **ArkWeb_Response** object.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkWeb_Response](capi-web-arkweb-response.md)* response | The **ArkWeb_Response** to be destroyed.|

### OH_ArkWebResponse_SetUrl()

```
int32_t OH_ArkWebResponse_SetUrl(ArkWeb_Response* response, const char* url)
```

**Description**

Sets a parsed URL that has been redirected or changed due to HSTS. After the setting, redirection is triggered.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkWeb_Response](capi-web-arkweb-response.md)* response | **ArkWeb_Response**.|
| const char* url | Parsed URL.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned when the operation is successful; **17100101** is returned when the parameter is invalid.|

### OH_ArkWebResponse_GetUrl()

```
void OH_ArkWebResponse_GetUrl(const ArkWeb_Response* response, char** url)
```

**Description**

Obtains the parsed URL that has been redirected or changed due to HSTS.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_Response](capi-web-arkweb-response.md)* response | **ArkWeb_Response**.|
| char** url | Parsed URL.|

### OH_ArkWebResponse_SetError()

```
int32_t OH_ArkWebResponse_SetError(ArkWeb_Response* response, ArkWeb_NetError errorCode)
```

**Description**

Sets an error code for the **ArkWeb_Response** object.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkWeb_Response](capi-web-arkweb-response.md)* response | **ArkWeb_Response**.|
| [ArkWeb_NetError](capi-arkweb-net-error-list-h.md#arkweb_neterror) errorCode | Error code of the failed request.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned when the operation is successful; **17100101** is returned when the parameter is invalid.|

### OH_ArkWebResponse_GetError()

```
ArkWeb_NetError OH_ArkWebResponse_GetError(const ArkWeb_Response* response)
```

**Description**

Obtains the error code of **ArkWeb_Response**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name                                | Description|
|-------------------------------------| -- |
| const [ArkWeb_Response](capi-web-arkweb-response.md)* response | **ArkWeb_Response**.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkWeb_NetError](capi-arkweb-net-error-list-h.md#arkweb_neterror) | Error code of **ArkWeb_Response**.|

### OH_ArkWebResponse_SetStatus()

```
int32_t OH_ArkWebResponse_SetStatus(ArkWeb_Response* response, int status)
```

**Description**

Sets an HTTP status code for **ArkWeb_Response**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkWeb_Response](capi-web-arkweb-response.md)* response | **ArkWeb_Response**.|
| int status | HTTP status code of the request.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned when the operation is successful; **17100101** is returned when the parameter is invalid.|

### OH_ArkWebResponse_GetStatus()

```
int OH_ArkWebResponse_GetStatus(const ArkWeb_Response* response)
```

**Description**

Obtains the HTTP status code of **ArkWeb_Response**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name                                | Description|
|-------------------------------------| -- |
| const [ArkWeb_Response](capi-web-arkweb-response.md)* response | **ArkWeb_Response**.|

**Returns**

| Type| Description|
| -- | -- |
| int | HTTP status code of **ArkWeb_Response**. If **ArkWeb_Response** is invalid, the value is **-1**.|

### OH_ArkWebResponse_SetStatusText()

```
int32_t OH_ArkWebResponse_SetStatusText(ArkWeb_Response* response, const char* statusText)
```

**Description**

Sets a status text for **ArkWeb_Response**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkWeb_Response](capi-web-arkweb-response.md)* response | **ArkWeb_Response**.|
| const char* statusText | Status text of the request.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned when the operation is successful; **17100101** is returned when the parameter is invalid.|

### OH_ArkWebResponse_GetStatusText()

```
void OH_ArkWebResponse_GetStatusText(const ArkWeb_Response* response, char** statusText)
```

**Description**

Obtains the status text of **ArkWeb_Response**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_Response](capi-web-arkweb-response.md)* response | **ArkWeb_Response**.|
| char** statusText | Status text of **ArkWeb_Response**. This function allocates memory for the **statusText** string. You need to release the string using **OH_ArkWeb_ReleaseString**.|

### OH_ArkWebResponse_SetMimeType()

```
int32_t OH_ArkWebResponse_SetMimeType(ArkWeb_Response* response, const char* mimeType)
```

**Description**

Sets a mime type for **ArkWeb_Response**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkWeb_Response](capi-web-arkweb-response.md)* response | **ArkWeb_Response**.|
| const char* mimeType | Mime type of the request.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned when the operation is successful; **17100101** is returned when the parameter is invalid.|

### OH_ArkWebResponse_GetMimeType()

```
void OH_ArkWebResponse_GetMimeType(const ArkWeb_Response* response, char** mimeType)
```

**Description**

Obtains the mime type of **ArkWeb_Response**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_Response](capi-web-arkweb-response.md)* response | **ArkWeb_Response**.|
| char** mimeType | Mime type of **ArkWeb_Response**. This function allocates memory for the **mimeType** string. You need to release the string using **OH_ArkWeb_ReleaseString**.|

### OH_ArkWebResponse_SetCharset()

```
int32_t OH_ArkWebResponse_SetCharset(ArkWeb_Response* response, const char* charset)
```

**Description**

Sets a character set for **ArkWeb_Response**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkWeb_Response](capi-web-arkweb-response.md)* response | **ArkWeb_Response**.|
| const char* charset | Character set of the request.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned when the operation is successful; **17100101** is returned when the parameter is invalid.|

### OH_ArkWebResponse_GetCharset()

```
void OH_ArkWebResponse_GetCharset(const ArkWeb_Response* response, char** charset)
```

**Description**

Obtains the character set of **ArkWeb_Response**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_Response](capi-web-arkweb-response.md)* response | **ArkWeb_Response**.|
| char** charset | Character set of **ArkWeb_Response**. This function allocates memory for the **charset** string. You need to release the string using **OH_ArkWeb_ReleaseString**.|

### OH_ArkWebResponse_SetHeaderByName()

```
int32_t OH_ArkWebResponse_SetHeaderByName(ArkWeb_Response* response,const char* name,const char* value,bool overwrite)
```

**Description**

Sets a header for **ArkWeb_Response**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkWeb_Response](capi-web-arkweb-response.md)* response | **ArkWeb_Response**.|
| const char* name | Name of the header.|
| const char* value | Value of the header.|
| bool overwrite | Whether to overwrite the existing header. The value **true** means to overwrite the existing header, and **false** means the opposite.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned when the operation is successful; **17100101** is returned when the parameter is invalid.|

### OH_ArkWebResponse_GetHeaderByName()

```
void OH_ArkWebResponse_GetHeaderByName(const ArkWeb_Response* response, const char* name, char** value)
```

**Description**

Obtains the header from **ArkWeb_Response**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_Response](capi-web-arkweb-response.md)* response | **ArkWeb_Response**.|
| const char* name | Name of the header.|
| char** value | Value of the header. This function allocates memory for the **value **string. You need to release the string using **OH_ArkWeb_ReleaseString**.|

### OH_ArkWebResourceHandler_Destroy()

```
int32_t OH_ArkWebResourceHandler_Destroy(const ArkWeb_ResourceHandler* resourceHandler)
```

**Description**

Destroys an **ArkWeb_ResourceHandler** object.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name                                              | Description|
|---------------------------------------------------| -- |
| const [ArkWeb_ResourceHandler](capi-web-arkweb-resourcehandler.md)* resourceHandler | **ArkWeb_ResourceHandler**.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned when the operation is successful; **17100101** is returned when the parameter is invalid.|

### OH_ArkWebResourceHandler_DidReceiveResponse()

```
int32_t OH_ArkWebResourceHandler_DidReceiveResponse(const ArkWeb_ResourceHandler* resourceHandler,const ArkWeb_Response* response)
```

**Description**

Sends a response header to the intercepted request.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_ResourceHandler](capi-web-arkweb-resourcehandler.md)* resourceHandler | **ArkWeb_ResourceHandler** of the request.|
| const [ArkWeb_Response](capi-web-arkweb-response.md)* response | **ArkWeb_Response** of the intercepted request.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned when the operation is successful; **17100101** is returned when the parameter is invalid.|

### OH_ArkWebResourceHandler_DidReceiveData()

```
int32_t OH_ArkWebResourceHandler_DidReceiveData(const ArkWeb_ResourceHandler* resourceHandler,const uint8_t* buffer,int64_t bufLen)
```

**Description**

Sends a response body to the intercepted request.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_ResourceHandler](capi-web-arkweb-resourcehandler.md)* resourceHandler | **ArkWeb_ResourceHandler** of the request.|
| const uint8_t* buffer | Buffer data to be sent.|
| int64_t bufLen | Buffer size.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned when the operation is successful; **17100101** is returned when the parameter is invalid.|

### OH_ArkWebResourceHandler_DidFinish()

```
int32_t OH_ArkWebResourceHandler_DidFinish(const ArkWeb_ResourceHandler* resourceHandler)
```

**Description**

Notifies the ArkWeb kernel that the intercepted request has been finished and that no more data is available.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_ResourceHandler](capi-web-arkweb-resourcehandler.md)* resourceHandler | **ArkWeb_ResourceHandler** of the request.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned when the operation is successful; **17100101** is returned when the parameter is invalid.|

### OH_ArkWebResourceHandler_DidFailWithError()

```
int32_t OH_ArkWebResourceHandler_DidFailWithError(const ArkWeb_ResourceHandler* resourceHandler,ArkWeb_NetError errorCode)
```

**Description**

Notifies the ArkWeb kernel that the intercepted request fails.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_ResourceHandler](capi-web-arkweb-resourcehandler.md)* resourceHandler | **ArkWeb_ResourceHandler** of the request.|
| [ArkWeb_NetError](capi-arkweb-net-error-list-h.md#arkweb_neterror) errorCode | Error code of the request. For details, see [arkweb_net_error_list.h](capi-arkweb-net-error-list-h.md).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** is returned when the operation is successful; **17100101** is returned when the parameter is invalid.|

### OH_ArkWeb_ReleaseString()

```
void OH_ArkWeb_ReleaseString(char* string)
```

**Description**

Releases the string created by NDK APIs.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| char* string | String to be released.|

### OH_ArkWeb_ReleaseByteArray()

```
void OH_ArkWeb_ReleaseByteArray(uint8_t* byteArray)
```

**Description**

Releases the byte array created by NDK APIs.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| uint8_t* byteArray | Byte array to be released.|
