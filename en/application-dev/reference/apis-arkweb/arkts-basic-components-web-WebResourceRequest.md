# Class (WebResourceRequest)

Implements the **WebResourceRequest** object to obtain resource requests. For details about the sample code, see [onErrorReceive](./arkts-basic-components-web-events.md#onerrorreceive).

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 8.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## constructor

constructor()

Constructs a **WebResourceRequest** object.

**System capability**: SystemCapability.Web.Webview.Core

## getRequestHeader

getRequestHeader(): Array\<Header\>

Obtains the information about the resource request header.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                        | Description        |
| -------------------------- | ---------- |
| Array\<[Header](./arkts-basic-components-web-i.md#header)\> | Information about the resource request header.|

## getRequestUrl

getRequestUrl(): string

Obtains the URL of the resource request.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | URL of the resource request.|

## isMainFrame

isMainFrame(): boolean

Checks whether the resource request is for the main frame.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description              |
| ------- | ---------------- |
| boolean | Whether the resource request is for the main frame.<br>The value **true** indicates that the resource request is for the main frame, and **false** indicates the opposite.|

## isRedirect

isRedirect(): boolean

Checks whether the resource request is redirected by the server.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description              |
| ------- | ---------------- |
| boolean | Whether the resource request is redirected by the server.<br>The value **true** indicates that the resource request is redirected by the server, and **false** indicates the opposite.|

## isRequestGesture

isRequestGesture(): boolean

Checks whether the resource request is associated with a gesture (for example, a tap).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description                  |
| ------- | -------------------- |
| boolean | Whether the resource request is associated with a gesture (for example, a tap).<br>The value **true** indicates that the resource request is associated with a gesture, and **false** indicates the opposite.|

## getRequestMethod<sup>9+</sup>

getRequestMethod(): string

Obtains the request method.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | Request method.|
