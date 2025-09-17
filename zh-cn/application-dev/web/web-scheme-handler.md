# 拦截Web组件发起的网络请求
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

应用可以通过[onInterceptRequest](../reference/apis-arkweb/arkts-basic-components-web-events.md#oninterceptrequest9)拦截Web组件发起的网络请求，也可以通过SchemeHandler来拦截Web组件发起的网络请求。SchemeHandler提供了ArkTS与NDK两套接口。

> **注意**
>
> onInterceptRequest接口中无法获取Post Data，如果想要获取Post Data需使用SchemeHandler机制来进行拦截。

## 网络请求拦截处理 (onInterceptRequest接口)

通过onInterceptRequest接口拦截Web组件发起的网络请求可参考[自定义页面请求响应](./web-resource-interception-request-mgmt.md)。

## 网络请求拦截处理 (SchemeHandler机制)

通过SchemeHandler机制来拦截Web组件发起的网络请求。

### 为Web组件设置SchemeHandler

ArkWeb支持通过SchemeHandler拦截Web组件或者ServiceWorker发出的HTTP(s)及自定义协议的请求。

当Web内核发出相应scheme请求时，会触发为该scheme设置的SchemeHandler的回调。SchemeHandler包含请求开始与请求结束两个回调，应用需要在请求开始的回调中告知Web内核是否进行拦截，在请求结束后清理相关的资源，避免内存泄漏。

请求开始的回调：  
NDK：[ArkWeb_OnRequestStart](../reference/apis-arkweb/capi-arkweb-scheme-handler-h.md#arkweb_onrequeststart)  
ArkTS：[onRequestStart](../reference/apis-arkweb/arkts-apis-webview-WebSchemeHandler.md#onrequeststart12)  

请求结束的回调：  
NDK：[ArkWeb_OnRequestStop](../reference/apis-arkweb/capi-arkweb-scheme-handler-h.md#arkweb_onrequeststop)  
ArkTS：[onRequestStop](../reference/apis-arkweb/arkts-apis-webview-WebSchemeHandler.md#onrequeststop12)  

> **注意**
>
> - 需要在Web组件初始化之后设置SchemeHandler，否则会设置失败。 
> - 若想要拦截Web组件发出的第一个请求，可以通过[initializeWebEngine](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#initializewebengine)方法提前进行Web组件初始化，再设置SchemeHandler实现拦截。详细代码请参考[完整示例](#完整示例)。

在C++中，通过NDK接口为Web组件设置SchemeHandler：

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

    // 拦截webTag为“scheme-handler”的Web组件发出的scheme为“custom”的请求。
    OH_ArkWeb_SetSchemeHandler("custom", "scheme-handler", schemeHandler);
    OH_ArkWebServiceWorker_SetSchemeHandler("custom", schemeHandler);
  ```

在ArkTS中，为Web组件设置SchemeHandler：

  ```ts
    // 初始化WebView控制器和Scheme处理器。
    controller: webview.WebviewController = new webview.WebviewController();
    schemeHandler: webview.WebSchemeHandler = new webview.WebSchemeHandler();
    // 为当前Web组件设置SchemeHandler。
    this.controller.setWebSchemeHandler('https', this.schemeHandler);
  ```

### 设置自定义scheme需要遵循的规则

如果要拦截自定义scheme的请求，需要在Web组件初始化之前将自定义scheme注册到Web内核，初始化后再注册会失败。

Web组件的创建会触发Web内核的初始化。另外ArkWeb还提供了initializeWebEngine接口，用于单独进行Web初始化。

在NDK中可以在ets侧先调用testNapi.registerCustomSchemes注册自定义协议，然后调用[initializeWebEngine](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#initializewebengine)初始化Web内核，示例如下：

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

testNapi.registerCustomSchemes的C++实现：

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

在ArkTS中可以通过customizeSchemes注册自定义协议，示例如下：

 ``` ts
    // xxx.ets
    import { webview } from '@kit.ArkWeb';
    import { BusinessError } from '@kit.BasicServicesKit';

    @Entry
    @Component
    struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    responseWeb: WebResourceResponse = new WebResourceResponse();
    scheme1: webview.WebCustomScheme = { schemeName: "name1", isSupportCORS: true, isSupportFetch: true };
    scheme2: webview.WebCustomScheme = { schemeName: "name2", isSupportCORS: true, isSupportFetch: true };
    scheme3: webview.WebCustomScheme = { schemeName: "name3", isSupportCORS: true, isSupportFetch: true };

    aboutToAppear(): void {
        try {
        webview.WebviewController.customizeSchemes([this.scheme1, this.scheme2, this.scheme3]);
        } catch (error) {
        console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
        }
    }

    build() {
        Column() {
        Web({ src: 'www.example.com', controller: this.controller })
            .onInterceptRequest((event) => {
            if (event) {
                console.info('url:' + event.request.getRequestUrl());
            }
            return this.responseWeb;
            })
        }
      }
    }
  ```

### 获取被拦截请求的信息

在请求开始的回调中，应用可以获取请求的基本信息包括url、method、referrer、request headers、resource type、post data等。支持获取PUT/POST类请求的上传数据，数据类型支持BYTES、FILE、BLOB和CHUNKED。

在NDK中，获取被拦截请求的信息：

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

    // 获取被拦截请求的上传数据。
    OH_ArkWebResourceRequest_GetHttpBodyStream(resourceRequest(), &stream_);
    // 设置读取上传数据的读回调。
    OH_ArkWebHttpBodyStream_SetReadCallback(stream_, ReadCallback);
    // 初始化ArkWeb_HttpBodyStream，其它OH_ArkWebHttpBodyStream*函数需要在初始化进行调用。
    OH_ArkWebHttpBodyStream_Init(stream_, InitCallback);
  ```

在ArkTS中，获取被拦截请求的信息：
  ```ts
  this.schemeHandler.onRequestStart((request: webview.WebSchemeHandlerRequest, resourceHandler: webview.WebResourceHandler) => {
    try {
      console.info("[schemeHandler] onRequestStart url:" + request.getRequestUrl());
      console.info("[schemeHandler] onRequestStart method:" + request.getRequestMethod());
      console.info("[schemeHandler] onRequestStart referrer:" + request.getReferrer());
      console.info("[schemeHandler] onRequestStart isMainFrame:" + request.isMainFrame());
      console.info("[schemeHandler] onRequestStart hasGesture:" + request.hasGesture());
      console.info("[schemeHandler] onRequestStart header size:" + request.getHeader().length);
      console.info("[schemeHandler] onRequestStart resource type:" + request.getRequestResourceType());
      console.info("[schemeHandler] onRequestStart frame url:" + request.getFrameUrl());
      let header = request.getHeader();
      for (let i = 0; i < header.length; i++) {
        console.info("[schemeHandler] onRequestStart header:" + header[i].headerKey + " " + header[i].headerValue);
      }
      let stream = request.getHttpBodyStream();
      if (stream) {
        console.info("[schemeHandler] onRequestStart has http body stream");
      } else {
        console.info("[schemeHandler] onRequestStart has no http body stream");
      }
    } catch (error) {
      console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
    }
  })
  ```

### 拦截Web内核的请求，并为被拦截的请求提供自定义的响应信息

网络拦截支持在worker线程以流方式为被拦截的请求提供自定义的响应信息。也可用特定的网络错误码结束当前被拦截的请求。

错误码定义：  
NDK：[网络错误码(arkweb_net_error_list.h)](../reference/apis-arkweb/capi-arkweb-net-error-list-h.md)。  
ArkTS：[网络错误码(@ohos.web.netErrorList.d.ts)](../reference/apis-arkweb/arkts-apis-netErrorList.md)。  

> **注意**
>
> ArkWeb不支持自定义错误码，请使用ArkWeb提供的错误码来结束请求。

在NDK中，为被拦截的请求提供自定义的响应信息：

  ```c++
    // 为被拦截的请求创建一个响应头。
    ArkWeb_Response *response;
    OH_ArkWeb_CreateResponse(&response);

    // 设置HTTP状态码为200。
    OH_ArkWebResponse_SetStatus(response, 200);
    // 设置响应头中的字符集，指明内容使用UTF-8编码。
    OH_ArkWebResponse_SetCharset(response, "UTF-8");
    // 设置响应头中的"content-length"，指明响应体的大小。
    OH_ArkWebResponse_SetHeaderByName(response, "content-length", "1024", false);
    // 将为被拦截的请求创建的响应头传递给Web组件。
    OH_ArkWebResourceHandler_DidReceiveResponse(resourceHandler, response);

    // 该函数可以调用多次，数据可以分多份来传递给Web组件。
    OH_ArkWebResourceHandler_DidReceiveData(resourceHandler, buffer, bufLen);

    // 读取响应体结束，当然如果希望该请求失败的话也可以通过调用OH_ArkWebResourceHandler_DidFailWithError(resourceHandler_, errorCode);
    // 传递给Web组件一个错误码并结束该请求。
    OH_ArkWebResourceHandler_DidFinish(resourceHandler);
  ```

在ArkTS中，为被拦截的请求提供自定义的响应信息：

   ```ts
   this.schemeHandler.onRequestStart((request: webview.WebSchemeHandlerRequest, resourceHandler: webview.WebResourceHandler) => {
    let response = new webview.WebSchemeHandlerResponse();
    try {
      // 设置网络错误代码为OK，表示请求成功。
      response.setNetErrorCode(WebNetErrorList.NET_OK);

      // 设置HTTP状态码为200，表示请求处理成功。
      response.setStatus(200);

      // 设置状态文本为"OK"，用于描述状态码。
      response.setStatusText("OK");

      // 设置MIME类型为"text/html"，指明返回数据的类型为HTML文档。
      response.setMimeType("text/html");

      // 设置编码方式为"utf-8"，指明内容使用UTF-8编码。
      response.setEncoding("utf-8");

      // 设置自定义响应头"header1"的值为"value1"，false表示不覆盖已经存在的同名头部。
      response.setHeaderByName("header1", "value1", false);

      // 调用didReceiveResponse将构造的响应头传递给被拦截的请求。
      resourceHandler.didReceiveResponse(response);

      // 调用didReceiveResponseBody将构造的响应体传递给被拦截的请求。
      resourceHandler.didReceiveResponseBody(buf.buffer);

      // 调用didFinish通知Web组件被拦截的请求已经完成。
      resourceHandler.didFinish();
    } catch (error) {
      console.error(`[schemeHandler] ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
    }
  })
  ```

当希望通过[OH_ArkWebResourceHandler_DidFailWithError](../reference/apis-arkweb/capi-arkweb-scheme-handler-h.md#oh_arkwebresourcehandler_didfailwitherror)或者[didFail(code: WebNetErrorList)](../reference/apis-arkweb/arkts-apis-webview-WebResourceHandler.md#didfail12)结束当前请求时，需要在调用该接口之前通过[OH_ArkWebResourceHandler_DidReceiveResponse](../reference/apis-arkweb/capi-arkweb-scheme-handler-h.md#oh_arkwebresourcehandler_didreceiveresponse)或者[didReceiveResponse](../reference/apis-arkweb/arkts-apis-webview-WebResourceHandler.md#didreceiveresponse12)返回给Web内核一个响应头，否则无法结束请求。

从API version 20开始，可以直接通过[OH_ArkWebResourceHandler_DidFailWithErrorV2](../reference/apis-arkweb/capi-arkweb-scheme-handler-h.md#oh_arkwebresourcehandler_didfailwitherrorv2)或者[didFail(code: WebNetErrorList, completeIfNoResponse: boolean)](../reference/apis-arkweb/arkts-apis-webview-WebResourceHandler.md#didfail20)结束网络请求，不再依赖必须通过[OH_ArkWebResourceHandler_DidReceiveResponse](../reference/apis-arkweb/capi-arkweb-scheme-handler-h.md#oh_arkwebresourcehandler_didreceiveresponse)或者[didReceiveResponse](../reference/apis-arkweb/arkts-apis-webview-WebResourceHandler.md#didreceiveresponse12)返回给Web内核一个响应头。

NDK示例：
  ```c++
  void OnRequestStart(){
    // 直接返回网络错误码ARKWEB_ERR_CONNECTION_FAILED结束该请求。
    OH_ArkWebResourceHandler_DidFailWithErrorV2(resourceHandler_, ARKWEB_ERR_CONNECTION_FAILED, true);
  }
  ```
ArkTS示例：
  ```ts
  this.schemeHandler.onRequestStart((request: webview.WebSchemeHandlerRequest, resourceHandler: webview.WebResourceHandler) => {
    // 直接调用didFail(WebNetErrorList.ERR_CONNECTION_FAILED, true)，自动构造一个网络请求错误ERR_CONNECTION_FAILED。
    resourceHandler.didFail(WebNetErrorList.ERR_CONNECTION_FAILED, true);
  })
  ```

## 完整示例

[拦截Web组件发起的网络请求](https://gitee.com/harmonyos_samples/guide-snippets/tree/master/ArkWebKit/ArkWebSchemeHandler)