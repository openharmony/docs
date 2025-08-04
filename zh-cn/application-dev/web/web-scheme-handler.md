# 拦截Web组件发起的网络请求
<!--Kit: ArkWeb-->
<!--Subsystem: ArkWeb-->
<!--Owner: @aohui-->
<!--SE: @yaomingliu-->
<!--TSE: @ghiker-->

[网络拦截接口(arkweb_scheme_handler.h)](../reference/apis-arkweb/capi-arkweb-scheme-handler-h.md)可以对Web组件发出的请求进行拦截，并为被拦截的请求提供自定义的响应头以及响应体。

## 为Web组件设置网络拦截器

为指定的Web组件或者ServiceWorker设置ArkWeb_SchemeHandler，当Web内核发出相应scheme请求的时候，会触发ArkWeb_SchemeHandler的回调。需要在Web组件初始化之后设置网络拦截器。

请求开始时回调ArkWeb_OnRequestStart，请求结束时回调ArkWeb_OnRequestStop。

若想要拦截Web组件发出的第一个请求，可以通过[initializeWebEngine](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#initializewebengine)方法提前进行初始化Web组建，再设置拦截器实现拦截。

  ```c++
    // 创建一个ArkWeb_SchemeHandler对象。
    ArkWeb_SchemeHandler *schemeHandler;
    OH_ArkWeb_CreateSchemeHandler(&schemeHandler);

    // 为ArkWeb_SchemeHandler设置ArkWeb_OnRequestStart与ArkWeb_OnRequestStop回调。
    OH_ArkWebSchemeHandler_SetOnRequestStart(schemeHandler, OnURLRequestStart);
    OH_ArkWebSchemeHandler_SetOnRequestStop(schemeHandler, OnURLRequestStop);

    // 拦截webTag为“scheme-handler”的Web组件发出的scheme为“https”的请求。
    OH_ArkWeb_SetSchemeHandler("https", "scheme-handler", schemeHandler);
    OH_ArkWebServiceWorker_SetSchemeHandler("https", schemeHandler);
  ```

也可以拦截非Web组件内置scheme的请求。

  ```c++
    // 创建一个ArkWeb_SchemeHandler对象。
    ArkWeb_SchemeHandler *schemeHandler;
    OH_ArkWeb_CreateSchemeHandler(&schemeHandler);

    // 为ArkWeb_SchemeHandler设置ArkWeb_OnRequestStart与ArkWeb_OnRequestStop回调。
    OH_ArkWebSchemeHandler_SetOnRequestStart(schemeHandler, OnURLRequestStart);
    OH_ArkWebSchemeHandler_SetOnRequestStop(schemeHandler, OnURLRequestStop);

    // 拦截webTag为“scheme-handler”的Web组件发出的scheme为“custom”的请求。
    OH_ArkWeb_SetSchemeHandler("custom", "scheme-handler", schemeHandler);
    OH_ArkWebServiceWorker_SetSchemeHandler("custom", schemeHandler);
  ```

## 设置自定义scheme需要遵循的规则

如果要拦截自定义scheme的请求，需要提前将自定义scheme注册到Web内核。需要在Web组件初始化之前进行注册，初始化后再注册会失败。

  ```c++
    // 注册“custom“ scheme到Web组件，并指定该scheme需要遵循标准的scheme规则，允许该scheme发出跨域请求。
    OH_ArkWeb_RegisterCustomSchemes("custom", ARKWEB_SCHEME_OPTION_STANDARD | ARKWEB_SCHEME_OPTION_CORS_ENABLED);
    // 注册“custom-local” scheme到Web组件，并指定该scheme需要遵循与“file” scheme一样的规则。
    OH_ArkWeb_RegisterCustomSchemes("custom-local", ARKWEB_SCHEME_OPTION_LOCAL);
    // 注册“custom-csp-bypassing”到Web组件，并指定该scheme需要遵循标准的scheme规则，允许忽略CSP检查。
    OH_ArkWeb_RegisterCustomSchemes("custom-csp-bypassing", ARKWEB_SCHEME_OPTION_CSP_BYPASSING | ARKWEB_SCHEME_OPTION_STANDARD);
    // 注册“custom-isolated”到Web组件，并指定该scheme的请求必须从相同scheme加载的网页中发起。
    OH_ArkWeb_RegisterCustomSchemes("custom-isolated", ARKWEB_SCHEME_OPTION_DISPLAY_ISOLATED);
  ```

由于注册scheme需要在Web组件初始化前完成，而网络拦截器需要在Web组件初始化之后设置，建议在EntryAbility的onCreate方法中调用c++接口注册scheme。
完成scheme注册后，通过[initializeWebEngine](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#initializewebengine)初始化Web组建，然后设置网络拦截器。

  ```ts
    export default class EntryAbility extends UIAbility {
        onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
            // 注册scheme的配置。
            testNapi.registerCustomSchemes();
            // 初始化Web组件内核，该操作会初始化Browser进程以及创建BrowserContext。
            webview.WebviewController.initializeWebEngine();
            // 创建并设置ArkWeb_SchemeHandler。
            testNapi.setSchemeHandler();
        }
        ...
    };
  ```

> **说明：**
>
> registerCustomSchemes必须在[initializeWebEngine](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#initializewebengine)方法调用前注册。

## 获取被拦截请求的请求信息

通过OH_ArkWebResourceRequest_*接口获取被拦截请求的信息。可以获取url、method、referrer、headers、resourceType等信息。

  ```c++
    char* url;
    OH_ArkWebResourceRequest_GetUrl(resourceRequest_, &url);
    OH_ArkWeb_ReleaseString(url);

    char* method;
    OH_ArkWebResourceRequest_GetMethod(resourceRequest_, &method);
    OH_ArkWeb_ReleaseString(method);

    int32_t resourceType = OH_ArkWebResourceRequest_GetResourceType(resourceRequest_);

    char* frameUrl;
    OH_ArkWebResourceRequest_GetFrameUrl(resourceRequest_, &frameUrl);
    OH_ArkWeb_ReleaseString(frameUrl);
    ...
  ```

支持获取PUT/POST类请求的上传数据。数据类型支持BYTES、FILE、BLOB和CHUNKED。

  ```c++
    // 获取被拦截请求的上传数据。
    OH_ArkWebResourceRequest_GetHttpBodyStream(resourceRequest(), &stream_);
    // 设置读取上传数据的读回调。
    OH_ArkWebHttpBodyStream_SetReadCallback(stream_, ReadCallback);
    // 初始化ArkWeb_HttpBodyStream，其它OH_ArkWebHttpBodyStream*函数需要在初始化进行调用。
    OH_ArkWebHttpBodyStream_Init(stream_, InitCallback);
  ```

## 为被拦截的请求提供自定义的响应体

网络拦截支持在worker线程以流方式为被拦截的请求提供自定义的响应体。也可用特定的[网络错误码(arkweb_net_error_list.h)](../reference/apis-arkweb/capi-arkweb-net-error-list-h.md)结束当前被拦截的请求。

  ```c++
    // 为被拦截的请求创建一个响应头。
    ArkWeb_Response *response;
    OH_ArkWeb_CreateResponse(&response);

    // 设置HTTP状态码为200。
    OH_ArkWebResponse_SetStatus(response, 200);
    // 设置响应体的编码格式。
    OH_ArkWebResponse_SetCharset(response, "UTF-8");
    // 设置响应体的大小。
    OH_ArkWebResponse_SetHeaderByName(response, "content-length", "1024", false);
    // 将为被拦截的请求创建的响应头传递给Web组件。
    OH_ArkWebResourceHandler_DidReceiveResponse(resourceHandler, response);

    // 该函数可以调用多次，数据可以分多份来传递给Web组件。
    OH_ArkWebResourceHandler_DidReceiveData(resourceHandler, buffer, bufLen);

    // 读取响应体结束，当然如果希望该请求失败的话也可以通过调用OH_ArkWebResourceHandler_DidFailWithError(resourceHandler_, errorCode);
    // 传递给Web组件一个错误码并结束该请求。
    OH_ArkWebResourceHandler_DidFinish(resourceHandler);
  ```
  
从API version 20开始，如果希望返回一个网络错误码来结束本次网络请求，也可以直接调用OH_ArkWebResourceHandler_DidFailWithErrorV2接口返回一个默认的网络错误码ARKWEB_ERR_CONNECTION_FAILED并结束该网络请求，错误码详情参考[网络错误码(arkweb_net_error_list.h)](../reference/apis-arkweb/capi-arkweb-net-error-list-h.md)。
  ```c++
    // 直接返回网络错误码ARKWEB_ERR_CONNECTION_FAILED结束该请求。
    OH_ArkWebResourceHandler_DidFailWithErrorV2(resourceHandler_, ARKWEB_ERR_FAILED, true);
  ```

## 完整示例

使用DevEco Studio创建一个默认的Native C++工程，需要提前准备一个mp4文件，命名为test.mp4，并将其放到main/resources/rawfile下。

main/ets/pages/index.ets
```ts
import testNapi from 'libentry.so';
import { webview } from '@kit.ArkWeb';
import { resourceManager } from '@kit.LocalizationKit';

@Entry
@Component
struct Index {
  mycontroller: webview.WebviewController = new webview.WebviewController("scheme-handler");

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
            testNapi.initResourceManager(this.getUIContext().getHostContext()!.resourceManager);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

main/ets/entryability/EntryAbility.ets
```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import testNapi from 'libentry.so';
import { webview } from '@kit.ArkWeb';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        // 注册三方协议的配置。
        testNapi.registerCustomSchemes();
        // 初始化Web组件内核，该操作会初始化Browser进程以及创建BrowserContext。
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
```c++
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

// 注册三方协议的配置，需要在Web内核初始化之前调用，否则会注册失败。
static napi_value RegisterCustomSchemes(napi_env env, napi_callback_info info)
{
    OH_LOG_INFO(LOG_APP, "register custom schemes");
    OH_ArkWeb_RegisterCustomSchemes("custom", ARKWEB_SCHEME_OPTION_STANDARD | ARKWEB_SCHEME_OPTION_CORS_ENABLED);
    OH_ArkWeb_RegisterCustomSchemes("custom-local", ARKWEB_SCHEME_OPTION_LOCAL);
    OH_ArkWeb_RegisterCustomSchemes("custom-csp-bypassing", ARKWEB_SCHEME_OPTION_CSP_BYPASSING | ARKWEB_SCHEME_OPTION_STANDARD);
    OH_ArkWeb_RegisterCustomSchemes("custom-isolated", ARKWEB_SCHEME_OPTION_DISPLAY_ISOLATED);
    return nullptr;
}

// 请求开始的回调，在该函数中我们创建一个RawfileRequest来实现对Web内核请求的拦截。
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
        delete rawfileRequest;
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
        delete rawfileRequest;
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
```text
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
```ts
export const registerCustomSchemes: () => void;
export const setSchemeHandler: () => void;
export const initResourceManager: (resmgr: resourceManager.ResourceManager) => void;
```

main/cpp/rawfile_request.h
```c++
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
    void DidFailWithErrorV2(ArkWeb_NetError errorCode, bool completeIfNoResponse);

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
```c++
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

// ArkWeb_HttpBodyStream的初始化回调。
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

RawfileRequest::~RawfileRequest() {
    if (stream_) {
        OH_ArkWebResourceRequest_DestroyHttpBodyStream(stream_);
    }
}

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

// 在worker线程中读取rawfile，并通过ResourceHandler返回给Web内核。
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

void RawfileRequest::DidFailWithErrorV2(ArkWeb_NetError errorCode, bool completeIfNoResponse)
{
    OH_LOG_INFO(LOG_APP, "did finish with error %{public}d.", errorCode);
    if (!stopped_) {
        OH_ArkWebResourceHandler_DidFailWithErrorV2(resourceHandler_, errorCode, completeIfNoResponse);
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
```html
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
```js
const body = document.body;
const element = document.createElement('div');
element.textContent = 'csp_script.js bypass the csp rules';
body.appendChild(element);
```

main/resources/rawfile/isolated_script.js
```js
const element = document.getElementById('isolated_test');
element.textContent = 'isolated_script.js not blocked';
```

main/resources/rawfile/isolated.html
```html
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
```js
const element = document.getElementById('local_test');
element.textContent = 'local_script.js not blocked.';
```

main/resources/rawfile/local.html
```html
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
```html
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
```html
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
```js
self.addEventListener('install', event => {
    console.log('v1 installing');
    event.waitUntil(
        caches.open('static-v1').then(cache => cache.add('/cat.svg'))
    );
});

self.addEventListener('activate', event => {
    console.log("v1 now ready to handle fetches.");
});
```

main/resources/rawfile/video.html
```html
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
```html
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
