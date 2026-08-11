# Class (WebResourceHandler)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

WebResourceHandler是自定义scheme拦截场景中用于向Web组件返回拦截请求结果的处理器。当WebSchemeHandler决定拦截一个请求后，开发者通过WebResourceHandler向Web组件提供自定义的响应头（didReceiveResponse）、响应体数据（didReceiveResponseBody），并通知请求完成（didFinish）或失败（didFail）。其中didFail支持重载方法（API version 20+）以简化错误处理流程。该接口实现了应用层对网络请求的完全自定义响应。

WebResourceHandler与[WebSchemeHandler](./arkts-apis-webview-WebSchemeHandler.md)、[WebSchemeHandlerResponse](./arkts-apis-webview-WebSchemeHandlerResponse.md)配合使用：WebSchemeHandler的onRequestStart回调中接收WebResourceHandler实例，开发者构造WebSchemeHandlerResponse对象，通过WebResourceHandler的didReceiveResponse和didReceiveResponseBody传入响应头和响应体数据，最后调用didFinish或didFail结束请求。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 12开始支持。
>
> - 示例效果请以真机运行为准。

## 导入模块

```ts
import { webview } from '@kit.ArkWeb';
```

## didReceiveResponse<sup>12+</sup>

didReceiveResponse(response: WebSchemeHandlerResponse): void

将构造的响应头传递给被拦截的请求。需在调用didFinish或didFail之前调用。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型    |  必填  | 说明                                            |
| ---------------| ------- | ---- | ------------- |
| response      | [WebSchemeHandlerResponse](./arkts-apis-webview-WebSchemeHandlerResponse.md)  | 是   | 该拦截请求的响应，用于向Web组件传递自定义的响应头信息，包括状态码、响应头字段等。开发者需先构造此对象，然后通过didReceiveResponse方法传递给被拦截的请求。 |

**错误码：**

以下错误码的详细介绍请参见[Webview错误码](errorcode-webview.md)、[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.    |
| 17100021 | The resource handler is invalid. |

**示例：**

示例请参考[OnRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12)。

## didReceiveResponseBody<sup>12+</sup>

didReceiveResponseBody(data: ArrayBuffer): void

将构造的响应体传递给被拦截的请求。需在调用didFinish或didFail之前调用。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型    |  必填  | 说明                                            |
| ---------------| ------- | ---- | ------------- |
| data      | ArrayBuffer  | 是   | ArrayBuffer类型的二进制数据，用于传递HTTP响应体内容。开发者需根据响应内容类型（如文本、图片、JSON等）构造相应格式的二进制数据。 |

**错误码：**

以下错误码的详细介绍请参见[Webview错误码](errorcode-webview.md)、[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.    |
| 17100021 | The resource handler is invalid. |

**示例：**

示例请参考[OnRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12)。

## didFinish<sup>12+</sup>

didFinish(): void

通知Web组件被拦截的请求已经完成，并且没有更多的数据可用，调用前需调用[didReceiveResponse](#didreceiveresponse12)传入响应头。

**系统能力：** SystemCapability.Web.Webview.Core

**错误码：**

以下错误码的详细介绍请参见[Webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100021 | The resource handler is invalid. |

**示例：**

示例请参考[OnRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12)。

## didFail<sup>12+</sup>

didFail(code: WebNetErrorList): void

通知ArkWeb内核被拦截请求将返回失败，并结束该网络请求，调用前需调用[didReceiveResponse](#didreceiveresponse12)传入响应头。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    |  必填  | 说明                       |
| --------| ------- | ---- | ---------------------------|
| code | [WebNetErrorList](arkts-apis-netErrorList.md#webneterrorlist) | 是 | 网络错误码，用于标识请求失败的原因。 |

**错误码：**

以下错误码的详细介绍请参见[Webview错误码](errorcode-webview.md)、[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 17100021 | The resource handler is invalid. |


**示例：**

示例请参考[OnRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12)。

## didFail<sup>20+</sup>

didFail(code: WebNetErrorList, completeIfNoResponse: boolean): void

通知ArkWeb内核，被拦截请求将返回失败。若completeIfNoResponse为false，调用前需调用[didReceiveResponse](#didreceiveresponse12)传入响应头。若completeIfNoResponse为true，且调用前未调用[didReceiveResponse](#didreceiveresponse12)，则自动生成一个响应头，网络错误码为-104，详情参见[WebNetErrorList](arkts-apis-netErrorList.md#webneterrorlist)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型    |  必填  | 说明                       |
| --------| ------- | ---- | ---------------------------|
| code | [WebNetErrorList](arkts-apis-netErrorList.md#webneterrorlist) | 是 | 网络错误码，用于标识请求失败的原因。 |
| completeIfNoResponse | boolean | 是 | 是否在未调用[didReceiveResponse](#didreceiveresponse12)时自动完成此次网络请求；值为true时自动生成响应头（网络错误码为-104）并完成请求，值为false时等待应用调用[didReceiveResponse](#didreceiveresponse12)。 |

**错误码：**

以下错误码的详细介绍请参见[Webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100101 | The errorCode is either ARKWEB_NET_OK or outside the range of error codes in WebNetErrorList. |
| 17100021 | The resource handler is invalid. |

**示例：**

```ts
// xxx.ets
import { webview, WebNetErrorList } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  schemeHandler: webview.WebSchemeHandler = new webview.WebSchemeHandler();

  build() {
    Column() {
      Web({ src: 'https://www.example.com', controller: this.controller })
        .onControllerAttached(() => {
          try {
            this.schemeHandler.onRequestStart((request: webview.WebSchemeHandlerRequest, resourceHandler: webview.WebResourceHandler) => {
              console.info('[schemeHandler] onRequestStart');
              try {
                console.info('[schemeHandler] onRequestStart url:' + request.getRequestUrl());
                console.info('[schemeHandler] onRequestStart method:' + request.getRequestMethod());
                console.info('[schemeHandler] onRequestStart referrer:' + request.getReferrer());
                console.info('[schemeHandler] onRequestStart isMainFrame:' + request.isMainFrame());
                console.info('[schemeHandler] onRequestStart hasGesture:' + request.hasGesture());
                console.info('[schemeHandler] onRequestStart header size:' + request.getHeader().length);
                console.info('[schemeHandler] onRequestStart resource type:' + request.getRequestResourceType());
                console.info('[schemeHandler] onRequestStart frame url:' + request.getFrameUrl());
                let header = request.getHeader();
                for (let i = 0; i < header.length; i++) {
                  console.info('[schemeHandler] onRequestStart header:' + header[i].headerKey + ' ' + header[i].headerValue);
                }
                let stream = request.getHttpBodyStream();
                if (stream) {
                  console.info('[schemeHandler] onRequestStart has http body stream');
                } else {
                  console.info('[schemeHandler] onRequestStart has no http body stream');
                }
              } catch (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }

              if (request.getRequestUrl().endsWith('example.com')) {
                return false;
              }

              try {
                // 直接调用didFail(WebNetErrorList.ERR_FAILED, true)，若此前未调用didReceiveResponse，系统将自动生成响应头，网络错误码为-104（对应ERR_CONNECTION_FAILED）
                resourceHandler.didFail(WebNetErrorList.ERR_FAILED, true);
              } catch (error) {
                // 当error.code为17100101(The errorCode is either ARKWEB_NET_OK or outside the range of error codes in WebNetErrorList)
                // 且didFail(code: WebNetErrorList, completeIfNoResponse: boolean)的code值不为null时，接口会继续调用不会中断。
                console.error(`[schemeHandler] ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }
              return true;
            })

            this.schemeHandler.onRequestStop((request: webview.WebSchemeHandlerRequest) => {
              console.info('[schemeHandler] onRequestStop');
            });

            this.controller.setWebSchemeHandler('https', this.schemeHandler);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
        .javaScriptAccess(true)
        .domStorageAccess(true)
    }
  }
}
```