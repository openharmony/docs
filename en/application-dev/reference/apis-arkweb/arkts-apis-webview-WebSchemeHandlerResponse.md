# Class (WebSchemeHandlerResponse)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

Represents a request response. You can create a response for an intercepted request, fill in custom content, and return the response to the **Web** component.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 12.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## Modules to Import

```ts
import { webview } from '@kit.ArkWeb';
```

## constructor<sup>12+</sup>

constructor()

Constructs a **Response** object.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { WebNetErrorList } from '@ohos.web.netErrorList';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  schemeHandler: webview.WebSchemeHandler = new webview.WebSchemeHandler();

  build() {
    Column() {
      Button('response').onClick(() => {
        let response = new webview.WebSchemeHandlerResponse();
        try {
          response.setUrl("http://www.example.com")
          response.setStatus(200)
          response.setStatusText("OK")
          response.setMimeType("text/html")
          response.setEncoding("utf-8")
          response.setHeaderByName("header1", "value1", false)
          response.setNetErrorCode(WebNetErrorList.NET_OK)
          console.info("[schemeHandler] getUrl:" + response.getUrl())
          console.info("[schemeHandler] getStatus:" + response.getStatus())
          console.info("[schemeHandler] getStatusText:" + response.getStatusText())
          console.info("[schemeHandler] getMimeType:" + response.getMimeType())
          console.info("[schemeHandler] getEncoding:" + response.getEncoding())
          console.info("[schemeHandler] getHeaderByValue:" + response.getHeaderByName("header1"))
          console.info("[schemeHandler] getNetErrorCode:" + response.getNetErrorCode())

        } catch (error) {
          console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
        }
      })
      Web({ src: 'https://www.example.com', controller: this.controller })
    }
  }
}

```

## setUrl<sup>12+</sup>

setUrl(url: string): void

Sets the redirection URL or the URL changed due to HSTS for this response. After the URL is set, a redirection to the new URL is triggered.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  url | string | Yes  | URL to be redirected to.|

**Example**

For details about the sample code, see [constructor](#constructor12).

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types.    |

## setNetErrorCode<sup>12+</sup>

setNetErrorCode(code: WebNetErrorList): void

Sets the network error code for this response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  code | [WebNetErrorList](arkts-apis-netErrorList.md#webneterrorlist) | Yes  | Network error code.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.    |

**Example**

For details about the sample code, see [constructor](#constructor12).

## setStatus<sup>12+</sup>

setStatus(code: number): void

Sets the HTTP status code for this response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  code | number | Yes  | HTTP status code.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types. |

**Example**

For details about the sample code, see [constructor](#constructor12).

## setStatusText<sup>12+</sup>

setStatusText(text: string): void

Sets the status text for this response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  text | string | Yes  | Status text.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types.    |

**Example**

For details about the sample code, see [constructor](#constructor12).

## setMimeType<sup>12+</sup>

setMimeType(type: string): void

Sets the MIME type for this response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  type | string | Yes  | MIME type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types.    |

**Example**

For details about the sample code, see [constructor](#constructor12).

## setEncoding<sup>12+</sup>

setEncoding(encoding: string): void

Sets the character set for this response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  encoding | string | Yes  | Character set.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types.    |

**Example**

For details about the sample code, see [constructor](#constructor12).

## setHeaderByName<sup>12+</sup>

setHeaderByName(name: string, value: string, overwrite: boolean): void

Sets the header information for this response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  name | string | Yes  | Name of the header.|
|  value | string | Yes  | Value of the header.|
|  overwrite | boolean | Yes  | Whether to override the existing header. The value **true** means to override the existing header, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.    |

**Example**

For details about the sample code, see [constructor](#constructor12).

## getUrl<sup>12+</sup>

getUrl(): string

Obtains the redirection URL or the URL changed due to HSTS.
NOTE: To obtain a URL for the JavaScriptProxy communication API authentication, use [getLastJavascriptProxyCallingFrameUrl<sup>12+</sup>](./arkts-apis-webview-WebviewController.md#getlastjavascriptproxycallingframeurl12).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| string | Redirection URL or the URL changed due to HSTS.|

**Example**

For details about the sample code, see [constructor](#constructor12).

## getNetErrorCode<sup>12+</sup>

getNetErrorCode(): WebNetErrorList

Obtains the network error code of the response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| [WebNetErrorList](arkts-apis-netErrorList.md#webneterrorlist) | Obtains the network error code of the response.|

**Example**

For details about the sample code, see [constructor](#constructor12).

## getStatus<sup>12+</sup>

getStatus(): number

Obtains the HTTP status code of the response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| number | HTTP status code of the response.|

**Example**

For details about the sample code, see [constructor](#constructor12).

## getStatusText<sup>12+</sup>

getStatusText(): string

Obtains the status text of this response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| string | Status text.|

**Example**

For details about the sample code, see [constructor](#constructor12).

## getMimeType<sup>12+</sup>

getMimeType(): string

Obtains the MIME type of this response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| string | MIME type.|

**Example**

For details about the sample code, see [constructor](#constructor12).

## getEncoding<sup>12+</sup>

getEncoding(): string

Obtains the character set of this response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| string | Character set.|

**Example**

For details about the sample code, see [constructor](#constructor12).

## getHeaderByName<sup>12+</sup>

getHeaderByName(name: string): string

Obtains the character set of this response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type            | Mandatory| Description                 |
| ------- | ---------------- | ---- | -------------------- |
| name     | string | Yes  | Name of the header.     |


**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| string | Value of the header.|

**Example**

For details about the sample code, see [constructor](#constructor12).
