# Class (WebResourceResponse)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

Implements the **WebResourceResponse** object. For details about the sample code, see [onHttpErrorReceive](./arkts-basic-components-web-events.md#onhttperrorreceive).

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 8.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## constructor

constructor()

Constructs a **WebResourceResponse**.

**System capability**: SystemCapability.Web.Webview.Core

## getReasonMessage

getReasonMessage(): string

Obtains the status code description of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Status code description of the resource response.|

## getResponseCode

getResponseCode(): number

Obtains the status code of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description         |
| ------ | ----------- |
| number | Status code of the resource response.|

## getResponseData

getResponseData(): string

Obtains the data in the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description       |
| ------ | --------- |
| string | Data in the resource response.|

## getResponseEncoding

getResponseEncoding(): string

Obtains the encoding string of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description        |
| ------ | ---------- |
| string | Encoding string of the resource response.|

## getResponseHeader

getResponseHeader() : Array\<Header\>

Obtains the resource response header.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                        | Description      |
| -------------------------- | -------- |
| Array\<[Header](./arkts-basic-components-web-i.md#header)\> | Resource response header.|

## getResponseMimeType

getResponseMimeType(): string

Obtains the MIME type of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| string | MIME type of the resource response.|

## getResponseDataEx<sup>13+</sup>

getResponseDataEx(): string | number | ArrayBuffer | Resource | undefined

Obtains the data in the resource response. Multiple data types are supported.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

|Type|Description|
|---|---|
|string \| number \| ArrayBuffer \| [Resource](../apis-arkui/arkui-ts/ts-types.md#resource) \| undefined | An HTML string when the type is string; a file descriptor when the type is number; binary data when the type is ArrayBuffer; a **$rawfile** resource when the type is resource; or **undefined** if no data is available.|

## getResponseIsReady<sup>13+</sup>

getResponseIsReady(): boolean

Obtains whether the response data is ready.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

|Type|Description|
|---|---|
|boolean|**true** indicates that the response data is ready, and **false** indicates the opposite.|

## setResponseData<sup>9+</sup>

setResponseData(data: string \| number \| Resource \| ArrayBuffer): void

Sets the data in the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type                                    | Mandatory  | Description                                    |
| ---- | ---------------------------------------- | ---- | ---------------------------------------- |
| data | string \| number \| [Resource](../apis-arkui/arkui-ts/ts-types.md#resource)<sup>10+</sup> \| ArrayBuffer<sup>11+</sup> | Yes   | Resource response data to set. When set to a string, the value indicates a string in HTML format. When set to a number, the value indicates a file handle, which is closed by the system **Web** component. When set to a **Resource** object, the value indicates the file resources in the **rawfile** directory of the application. When set to an **ArrayBuffer** object, the value indicates the original binary data of a resource.|

## setResponseEncoding<sup>9+</sup>

setResponseEncoding(encoding: string): void

Sets the encoding string of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name     | Type  | Mandatory  | Description        |
| -------- | ------ | ---- | ------------ |
| encoding | string | Yes   | Encoding string to set.|

## setResponseMimeType<sup>9+</sup>

setResponseMimeType(mimeType: string): void

Sets the MIME type of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name     | Type  | Mandatory  | Description                |
| -------- | ------ | ---- | -------------------- |
| mimeType | string | Yes  | MIME type to set.|

## setReasonMessage<sup>9+</sup>

setReasonMessage(reason: string): void

Sets the status code description of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description           |
| ------ | ------ | ---- | --------------- |
| reason | string | Yes  | Status code description to set.|

## setResponseHeader<sup>9+</sup>

setResponseHeader(header: Array\<Header\>): void

Sets the resource response header.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type                      | Mandatory  | Description      |
| ------ | -------------------------- | ---- | ---------- |
| header | Array\<[Header](./arkts-basic-components-web-i.md#header)\> | Yes  | Resource response header to set.|

## setResponseCode<sup>9+</sup>

setResponseCode(code: number): void

Sets the status code of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description         |
| ---- | ------ | ---- | ------------- |
| code | number | Yes  | Status code to set. If the resource ends with an error, set the error code by referring to [@ohos.web.netErrorList](arkts-apis-netErrorList.md). Do not set the error code to **ERR_IO_PENDING**, which may block the synchronous **XMLHttpRequest**.|

## setResponseIsReady<sup>9+</sup>

setResponseIsReady(IsReady: boolean): void

Sets whether the resource response data is ready.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory | Description         |
| ------- | ------- | ---- | ------------- |
| IsReady | boolean | Yes  | Whether the resource response data is ready.<br>The value **true** indicates that the resource response data is ready, and **false** indicates the opposite.<br>If the data is provided asynchronously, this parameter must be explicitly set to **false**. If this parameter is set to an invalid value, for example, **null** or **undefined**, or is not set, the data is considered ready.|
