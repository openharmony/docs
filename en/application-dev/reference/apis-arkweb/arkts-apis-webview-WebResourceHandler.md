# Class (WebResourceHandler)

Implements a **WebResourceHandler** object, which can return custom response headers and response bodies to the **Web** component.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 12.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## didReceiveResponse<sup>12+</sup>

didReceiveResponse(response: WebSchemeHandlerResponse): void

Sends a response header to the intercepted request.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| response      | [WebSchemeHandlerResponse](./arkts-apis-webview-WebSchemeHandlerResponse.md)  | Yes  | Response to send.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| Error Code| Error Message                             |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.    |
| 17100021 | The resource handler is invalid. |

**Example**

For details about the example, see [OnRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12).

## didReceiveResponseBody<sup>12+</sup>

didReceiveResponseBody(data: ArrayBuffer): void

Sends a response body to the intercepted request.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| data      | ArrayBuffer  | Yes  | Response body.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| Error Code| Error Message                             |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.    |
| 17100021 | The resource handler is invalid. |

**Example**

For details about the example, see [OnRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12).

## didFinish<sup>12+</sup>

didFinish(): void

Notifies the **Web** component that this request is completed and that no more data is available. Before calling this API, you need to call [didReceiveResponse](#didreceiveresponse12) to send a response header for this request.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| Error Code| Error Message                             |
| -------- | ------------------------------------- |
| 17100021 | The resource handler is invalid. |

**Example**

For details about the example, see [OnRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12).

## didFail<sup>12+</sup>

didFail(code: WebNetErrorList): void

Notifies the ArkWeb kernel that this request fails. Before calling this API, call [didReceiveResponse](#didreceiveresponse12) to send a response header to this request.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  code | [WebNetErrorList](arkts-apis-netErrorList.md#webneterrorlist) | Yes  | Network error code.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| Error Code| Error Message                             |
| -------- | ------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 17100021 | The resource handler is invalid. |

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the example, see [OnRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12).

## didFail<sup>20+</sup>

didFail(code: WebNetErrorList, completeIfNoResponse: boolean): void

Notifies the ArkWeb engine that the intercepted request should fail. If **completeIfNoResponse** is set to **false**, call [didReceiveResponse](#didreceiveresponse12) first to transfer the constructed response header to the intercepted request. If **completeIfNoResponse** is set to **true** and [didReceiveResponse](#didreceiveresponse12) is not called before this method is called, a response header containing the network error code -104 is automatically generated. For details, see [WebNetErrorList](arkts-apis-netErrorList.md#webneterrorlist).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  code | [WebNetErrorList](arkts-apis-netErrorList.md#webneterrorlist) | Yes  | Network error code.|
|  completeIfNoResponse | boolean | Yes  | Whether to complete the network request if [didReceiveResponse](#didreceiveresponse12) has not been called before this API is called. The value **true** indicates that when [didReceiveResponse](#didreceiveresponse12) has not been called, a response header containing the network error code -104 is automatically generated to complete the network request. The value **false** indicates that the application will wait for [didReceiveResponse](#didreceiveresponse12) to be called and the response to be passed, and will not complete the network request directly.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| Error Code| Error Message                             |
| -------- | ------------------------------------- |
| 17100101 | The errorCode is either ARKWEB_NET_OK or outside the range of error codes in WebNetErrorList. |
| 17100021 | The resource handler is invalid. |

**Example**

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
              console.log("[schemeHandler] onRequestStart");
              try {
                console.log("[schemeHandler] onRequestStart url:" + request.getRequestUrl());
                console.log("[schemeHandler] onRequestStart method:" + request.getRequestMethod());
                console.log("[schemeHandler] onRequestStart referrer:" + request.getReferrer());
                console.log("[schemeHandler] onRequestStart isMainFrame:" + request.isMainFrame());
                console.log("[schemeHandler] onRequestStart hasGesture:" + request.hasGesture());
                console.log("[schemeHandler] onRequestStart header size:" + request.getHeader().length);
                console.log("[schemeHandler] onRequestStart resource type:" + request.getRequestResourceType());
                console.log("[schemeHandler] onRequestStart frame url:" + request.getFrameUrl());
                let header = request.getHeader();
                for (let i = 0; i < header.length; i++) {
                  console.log("[schemeHandler] onRequestStart header:" + header[i].headerKey + " " + header[i].headerValue);
                }
                let stream = request.getHttpBodyStream();
                if (stream) {
                  console.log("[schemeHandler] onRequestStart has http body stream");
                } else {
                  console.log("[schemeHandler] onRequestStart has no http body stream");
                }
              } catch (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }

              if (request.getRequestUrl().endsWith("example.com")) {
                return false;
              }

              try {
                // Call didFail(WebNetErrorList.ERR_FAILED, true) to automatically construct a network request error ERR_CONNECTION_FAILED.
                resourceHandler.didFail(WebNetErrorList.ERR_FAILED, true);
              } catch (error) {
                console.error(`[schemeHandler] ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }
              return true;
            })

            this.schemeHandler.onRequestStop((request: webview.WebSchemeHandlerRequest) => {
              console.log("[schemeHandler] onRequestStop");
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
