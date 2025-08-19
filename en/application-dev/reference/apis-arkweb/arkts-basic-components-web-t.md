# Types

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## WebviewController<sup>9+</sup>

type WebviewController = WebviewController

Defines methods for the web controller.

**System capability**: SystemCapability.Web.Webview.Core

| Type    | Description      |
| ------ | ---------- |
| [WebviewController](./arkts-apis-webview-WebviewController.md)  | A **WebviewController** used to control the behavior of the **Web** component. A **WebviewController** object can control only one **Web** component. Methods (except static methods) on the **WebviewController** can be called only after the **Web** component is bound to the **WebviewController**.|

## OnAdsBlockedCallback<sup>12+</sup>

type OnAdsBlockedCallback = (details: AdsBlockedDetails) => void

Defines a callback invoked when ads are blocked on the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name              | Type                                       | Mandatory  | Description                        |
| -------------------- | ----------------------------------------------- | ---- | -------------------------------- |
| details | [AdsBlockedDetails](./arkts-basic-components-web-i.md#adsblockeddetails12) | Yes   | Detailed information about the blocked ads when ads are blocked.|

## OnSslErrorEventCallback<sup>12+</sup>

type OnSslErrorEventCallback = (sslErrorEvent: SslErrorEvent) => void

Defines a callback invoked when an SSL error occurs during resource loading.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| sslErrorEvent | [SslErrorEvent](./arkts-basic-components-web-i.md#sslerrorevent12)  | Yes| Details about the callback invoked when an SSL error occurs during resource loading.|

## OnContextMenuHideCallback<sup>11+</sup>

type OnContextMenuHideCallback = () => void

Defines a callback invoked when the context menu is hidden.

**System capability**: SystemCapability.Web.Webview.Core

## OnRenderProcessNotRespondingCallback<sup>12+</sup>

type OnRenderProcessNotRespondingCallback = (data : RenderProcessNotRespondingData) => void

Defines a callback invoked when the rendering process does not respond.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| data | [RenderProcessNotRespondingData](./arkts-basic-components-web-i.md#renderprocessnotrespondingdata12) | Yes| Detailed information about the unresponsive rendering process.|

## OnRenderProcessRespondingCallback<sup>12+</sup>

type OnRenderProcessRespondingCallback = () => void

Defines a callback invoked when the rendering process transitions back to a normal operating state from an unresponsive state.

**System capability**: SystemCapability.Web.Webview.Core

## OnViewportFitChangedCallback<sup>12+</sup>

type OnViewportFitChangedCallback = (viewportFit: ViewportFit) => void

Defines a callback invoked when the **viewport-fit** configuration in the web page's **\<meta>** tag changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| viewportFit | [ViewportFit](./arkts-basic-components-web-e.md#viewportfit12) | Yes| Viewport type for **viewport-fit** in the web page **\<meta>** tag.|

## OnNativeEmbedVisibilityChangeCallback<sup>12+</sup>

type OnNativeEmbedVisibilityChangeCallback = (nativeEmbedVisibilityInfo: NativeEmbedVisibilityInfo) => void

Defines a callback invoked when the visibility of a same-layer tag changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| nativeEmbedVisibilityInfo | [NativeEmbedVisibilityInfo](./arkts-basic-components-web-i.md#nativeembedvisibilityinfo12)  | Yes| Visibility information about the same-layer tag.|

## OnFullScreenEnterCallback<sup>12+</sup>

type OnFullScreenEnterCallback = (event: FullScreenEnterEvent) => void

Defines a callback invoked when the **Web** component enters full screen mode.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| event | [FullScreenEnterEvent](./arkts-basic-components-web-i.md#fullscreenenterevent12)  | Yes| Callback event for the **Web** component to enter full screen mode.|

## OnFirstMeaningfulPaintCallback<sup>12+</sup>

type OnFirstMeaningfulPaintCallback = (firstMeaningfulPaint: [FirstMeaningfulPaint](./arkts-basic-components-web-i.md#firstmeaningfulpaint12)) => void

Defines a callback invoked when the first meaningful paint occurs on the page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| firstMeaningfulPaint | [FirstMeaningfulPaint](./arkts-basic-components-web-i.md#firstmeaningfulpaint12) | Yes| Information about the first meaningful paint.|

## OnLargestContentfulPaintCallback<sup>12+</sup>

type OnLargestContentfulPaintCallback = (largestContentfulPaint: [LargestContentfulPaint](./arkts-basic-components-web-i.md#largestcontentfulpaint12
)) => void

Defines a callback invoked when the largest content paint occurs on the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| largestContentfulPaint | [LargestContentfulPaint](./arkts-basic-components-web-i.md#largestcontentfulpaint12) | Yes| Information about the largest content paint.|

## OnNavigationEntryCommittedCallback<sup>11+</sup>

type OnNavigationEntryCommittedCallback = (loadCommittedDetails: [LoadCommittedDetails](./arkts-basic-components-web-i.md#loadcommitteddetails11)) => void

Defines a callback invoked when a navigation entry is submitted.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| loadCommittedDetails | [LoadCommittedDetails](./arkts-basic-components-web-i.md#loadcommitteddetails11)  | Yes| Detailed information about the web page that has been submitted for redirection.|

## OnSafeBrowsingCheckResultCallback<sup>11+</sup>

type OnSafeBrowsingCheckResultCallback = (threatType: ThreatType) => void

Defines a callback invoked by a website safe browsing check.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| threatType | [ThreatType](./arkts-basic-components-web-e.md#threattype11)  | Yes| Website threat type. |

## OnIntelligentTrackingPreventionCallback<sup>12+</sup>

type OnIntelligentTrackingPreventionCallback = (details: IntelligentTrackingPreventionDetails) => void

Defines a callback invoked when the tracker cookie is intercepted.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| details | [IntelligentTrackingPreventionDetails](./arkts-basic-components-web-i.md#intelligenttrackingpreventiondetails12)  | Yes| Detailed information about intelligent tracking prevention.|

## OnOverrideUrlLoadingCallback<sup>12+</sup>

type OnOverrideUrlLoadingCallback = (webResourceRequest: WebResourceRequest) => boolean

Defines a callback for **onOverrideUrlLoading**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type   | Mandatory  |  Description|
| ------------------ | ------- | ---- | ------------- |
| webResourceRequest   |   [WebResourceRequest](./arkts-basic-components-web-WebResourceRequest.md)   | Yes  | Information about the URL request.|

**Return value**

| Type     | Description                      |
| ------- | ------------------------ |
| boolean | Whether the loading is blocked. **true** is returned if the loading is blocked; otherwise, **false** is returned.|

## WebKeyboardCallback<sup>12+</sup>

type WebKeyboardCallback = (keyboardCallbackInfo: WebKeyboardCallbackInfo) => WebKeyboardOptions

Defines a callback to intercept the soft keyboard initiated from editable elements on a web page. This event is typically called when the **\<input>** tag on the web page is clicked.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name          | Type  | Mandatory  | Description              |
| ------------- | ------ | ---- | ------------------ |
| keyboardCallbackInfo    | [WebKeyboardCallbackInfo](./arkts-basic-components-web-i.md#webkeyboardcallbackinfo12) | Yes   | Input parameter of the callback used to intercept the soft keyboard initiated from editable elements on a web page, including [WebKeyboardController](./arkts-basic-components-web-WebKeyboardController.md) and editable element attributes. |

**Return value**

| Type              | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| [WebKeyboardOptions](./arkts-basic-components-web-i.md#webkeyboardoptions12) | [WebKeyboardOptions](./arkts-basic-components-web-i.md#webkeyboardoptions12) instance, which is used to determine which type of soft keyboard to start by the ArkWeb kernel.|

## OnOverrideErrorPageCallback<sup>20+</sup>

type OnOverrideErrorPageCallback = (errorPageEvent: OnErrorReceiveEvent) => string

Defines a callback of **onOverrideErrorPage**. This callback is triggered when a web page fails to be loaded.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| errorPageEvent | [OnErrorReceiveEvent](./arkts-basic-components-web-i.md#onerrorreceiveevent12) | Yes| Information returned when an error occurs during web page loading.     |

**Return value**

| Type     | Description                      |
| ------- | ------------------------ |
| string | Base64-encoded HTML text content.|

## MouseInfoCallback<sup>20+<sup>

type MouseInfoCallback = (event: NativeEmbedMouseInfo) => void

Defines a callback triggered when a same-layer tag is clicked using the mouse or touchpad.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| event | [NativeEmbedMouseInfo](./arkts-basic-components-web-i.md#nativeembedmouseinfo20) | Yes| Detailed information about clicking or touching and holding a same-layer tag using the mouse or touchpad.|

**Example**

For details about the sample code, see [onNativeEmbedMouseEvent](./arkts-basic-components-web-events.md#onnativeembedmouseevent20).
