# Class (WebSchemeHandlerRequest)

Represents a request intercepted by the **WebSchemeHandler** object.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 12.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## getHeader<sup>12+</sup>

getHeader(): Array\<WebHeader\>

Obtains the information about the resource request header.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                        | Description        |
| -------------------------- | ---------- |
| Array\<[WebHeader](./arkts-apis-webview-i.md#webheader)\> | Information about the resource request header.|

**Example**

For the complete sample code, see [onRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12).

## getRequestUrl<sup>12+</sup>

getRequestUrl(): string

Obtains the URL of the resource request.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | URL of the resource request.|

**Example**

For the complete sample code, see [onRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12).

## getRequestMethod<sup>12+</sup>

getRequestMethod(): string

Obtains the request method.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Request method.|

**Example**

For the complete sample code, see [onRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12).

## getReferrer<sup>12+</sup>

getReferrer(): string

Obtains the referrer.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Obtained referrer.|

**Example**

For the complete sample code, see [onRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12).

## isMainFrame<sup>12+</sup>

isMainFrame(): boolean

Checks whether the resource request is for the main frame.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| boolean | Whether the resource request is for the main frame. If the resource request is for the main frame, **true** is returned. Otherwise, **false** is returned.|

**Example**

For the complete sample code, see [onRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12).

## hasGesture<sup>12+</sup>

hasGesture(): boolean

Checks whether the resource request is associated with a gesture (for example, a tap).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| boolean | Whether the resource request is associated with a gesture (for example, a tap). If the resource request is associated with a gesture, **true** is returned. Otherwise, **false** is returned.|

**Example**

For the complete sample code, see [onRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12).

## getHttpBodyStream<sup>12+</sup>

getHttpBodyStream(): WebHttpBodyStream | null

Obtains the **WebHttpBodyStream** instance in this resource request.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| [WebHttpBodyStream](./arkts-apis-webview-WebSchemeHandler.md) \| null | **WebHttpBodyStream** instance in the resource request. If there is no **WebHttpBodyStream** instance, **null** is returned.|

**Example**

For the complete sample code, see [onRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12).

## getRequestResourceType<sup>12+</sup>

getRequestResourceType(): WebResourceType

Obtains the resource type of this resource request.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| [WebResourceType](./arkts-apis-webview-e.md#webresourcetype12) | Resource type of the resource request.|

**Example**

For the complete sample code, see [onRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12).

## getFrameUrl<sup>12+</sup>

getFrameUrl(): string

Obtains the URL of the frame that triggers this request.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | URL of the frame that triggers the request.|

**Example**

For the complete sample code, see [onRequestStart](./arkts-apis-webview-WebSchemeHandler.md#onrequeststart12).
