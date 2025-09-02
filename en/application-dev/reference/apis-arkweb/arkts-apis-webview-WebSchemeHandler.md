# Class (WebSchemeHandler)

Represents a **WebSchemeHandler** object used to intercept requests for a specific scheme.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 12.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## Module to Import

```ts
import { webview } from '@kit.ArkWeb';
```

## onRequestStart<sup>12+</sup>

onRequestStart(callback: (request: WebSchemeHandlerRequest, handler: WebResourceHandler) => boolean): void

Called when a request starts. In this callback, you can determine whether to intercept the request. If **false** is returned, the request is not intercepted and the handler is invalid. If **true** is returned, the request is intercepted.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| callback   | (request: [WebSchemeHandlerRequest](./arkts-apis-webview-WebSchemeHandlerRequest.md), handler: [WebResourceHandler](./arkts-apis-webview-WebResourceHandler.md)) => boolean | Yes| Callback invoked when a request for the specified scheme starts. **request** represents a request. **handler** provides the custom response header and response body for the **Web** component. The return value indicates whether the request is intercepted.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| Error Code| Error Message                             |
| -------- | ------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { buffer } from '@kit.ArkTS';
import { WebNetErrorList } from '@ohos.web.netErrorList';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  schemeHandler: webview.WebSchemeHandler = new webview.WebSchemeHandler();
  htmlData: string = "<html><body bgcolor=\"white\">Source:<pre>source</pre></body></html>";

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

              let response = new webview.WebSchemeHandlerResponse();
              try {
                response.setNetErrorCode(WebNetErrorList.NET_OK);
                response.setStatus(200);
                response.setStatusText("OK");
                response.setMimeType("text/html");
                response.setEncoding("utf-8");
                response.setHeaderByName("header1", "value1", false);
              } catch (error) {
                console.error(`[schemeHandler] ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }

              // Before calling didFinish or didFail, call didReceiveResponse to send a response header to this request.
              let buf = buffer.from(this.htmlData)
              try {
                if (buf.length == 0) {
                  console.log("[schemeHandler] length 0");
                  resourceHandler.didReceiveResponse(response);
                  // If the value of buf.length is 0 in normal cases, call resourceHandler.didFinish(). Otherwise, call resourceHandler.didFail().
                  resourceHandler.didFail(WebNetErrorList.ERR_FAILED);
                } else {
                  console.log("[schemeHandler] length 1");
                  resourceHandler.didReceiveResponse(response);
                  resourceHandler.didReceiveResponseBody(buf.buffer);
                  resourceHandler.didFinish();
                }
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
## onRequestStop<sup>12+</sup>

onRequestStop(callback: Callback\<WebSchemeHandlerRequest\>): void

Called when a request is complete, under the prerequisite that the request is indicated as intercepted in the **onRequestStart** callback. Specifically, this callback is invoked in the following cases:

1. The **WebResourceHandler** object calls **didFail** or **didFinish**.

2. The request is interrupted due to other reasons.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| callback | Callback\<[WebSchemeHandlerRequest](./arkts-apis-webview-WebSchemeHandlerRequest.md)\> | Yes  | Callback invoked when the request is complete.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| Error Code| Error Message                             |
| -------- | ------------------------------------- |
| 401 | Invalid input parameter. |

**Example**

For the complete sample code, see [onRequestStart](#onrequeststart12).
