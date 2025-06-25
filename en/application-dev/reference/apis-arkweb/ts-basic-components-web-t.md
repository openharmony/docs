# Types

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## OnAdsBlockedCallback<sup>12+</sup>

type OnAdsBlockedCallback = (details: AdsBlockedDetails) => void

Defines a callback invoked when ads are blocked on the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name              | Type                                       | Mandatory  | Description                        |
| -------------------- | ----------------------------------------------- | ---- | -------------------------------- |
| details | [AdsBlockedDetails](./ts-basic-components-web-i.md#adsblockeddetails12) | Yes   | Detailed information about the blocked ads when ads are blocked.|

## OnSslErrorEventCallback<sup>12+</sup>

type OnSslErrorEventCallback = (sslErrorEvent: SslErrorEvent) => void

Defines a callback invoked when an SSL error occurs during resource loading.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| sslErrorEvent | [SslErrorEvent](./ts-basic-components-web-i.md#sslerrorevent12)  | Yes| Details about the callback invoked when an SSL error occurs during resource loading.|

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
| data | [RenderProcessNotRespondingData](./ts-basic-components-web-i.md#renderprocessnotrespondingdata12) | Yes| Detailed information about the unresponsive rendering process.|

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
| viewportFit | [ViewportFit](./ts-basic-components-web-e.md#viewportfit12) | Yes| Viewport type for **viewport-fit** in the web page **\<meta>** tag.|

## OnNativeEmbedVisibilityChangeCallback<sup>12+</sup>

type OnNativeEmbedVisibilityChangeCallback = (nativeEmbedVisibilityInfo: NativeEmbedVisibilityInfo) => void

Defines a callback invoked when the visibility of a same-layer tag changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| nativeEmbedVisibilityInfo | [NativeEmbedVisibilityInfo](./ts-basic-components-web-i.md#nativeembedvisibilityinfo12)  | Yes| Visibility information about the same-layer tag.|

## OnFullScreenEnterCallback<sup>12+</sup>

type OnFullScreenEnterCallback = (event: FullScreenEnterEvent) => void

Defines a callback invoked when the **Web** component enters full screen mode.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| event | [FullScreenEnterEvent](./ts-basic-components-web-i.md#fullscreenenterevent12)  | Yes| Callback event for the **Web** component to enter full screen mode.|

## OnFirstMeaningfulPaintCallback<sup>12+</sup>

type OnFirstMeaningfulPaintCallback = (firstMeaningfulPaint: [FirstMeaningfulPaint](./ts-basic-components-web-i.md#firstmeaningfulpaint12)) => void

Defines a callback invoked when the first meaningful paint occurs on the page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| firstMeaningfulPaint | [FirstMeaningfulPaint](./ts-basic-components-web-i.md#firstmeaningfulpaint12) | Yes| Information about the first meaningful paint.|

## OnLargestContentfulPaintCallback<sup>12+</sup>

type OnLargestContentfulPaintCallback = (largestContentfulPaint: [LargestContentfulPaint](./ts-basic-components-web-i.md#largestcontentfulpaint12
)) => void

Defines a callback invoked when the largest content paint occurs on the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| largestContentfulPaint | [LargestContentfulPaint](./ts-basic-components-web-i.md#largestcontentfulpaint12) | Yes| Information about the largest content paint.|

## OnNavigationEntryCommittedCallback<sup>11+</sup>

type OnNavigationEntryCommittedCallback = (loadCommittedDetails: [LoadCommittedDetails](./ts-basic-components-web-i.md#loadcommitteddetails11)) => void

Defines a callback invoked when a navigation item is submitted.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| loadCommittedDetails | [LoadCommittedDetails](./ts-basic-components-web-i.md#loadcommitteddetails11)  | Yes| Detailed information about the web page that has been submitted for redirection.|

## OnSafeBrowsingCheckResultCallback<sup>11+</sup>

type OnSafeBrowsingCheckResultCallback = (threatType: ThreatType) => void

Defines a callback invoked by a website safe browsing check.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| threatType | [ThreatType](./ts-basic-components-web-e.md#threattype11)  | Yes| Website threat type. |

## OnIntelligentTrackingPreventionCallback<sup>12+</sup>

type OnIntelligentTrackingPreventionCallback = (details: IntelligentTrackingPreventionDetails) => void

Defines a callback invoked when the tracker cookie is intercepted.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                 |
| ------ | ------ | ---- | --------------------- |
| details | [IntelligentTrackingPreventionDetails](./ts-basic-components-web-i.md#intelligenttrackingpreventiondetails12)  | Yes| Detailed information about intelligent tracking prevention.|

## OnOverrideUrlLoadingCallback<sup>12+</sup>

type OnOverrideUrlLoadingCallback = (webResourceRequest: WebResourceRequest) => boolean

Defines a callback for **onOverrideUrlLoading**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type   | Mandatory  |  Description|
| ------------------ | ------- | ---- | ------------- |
| webResourceRequest   |   [WebResourceRequest](./ts-basic-components-web.md#webresourcerequest)   | Yes  | Information about the URL request.|

**Return value**

| Type     | Description                      |
| ------- | ------------------------ |
| boolean | Returns **true** if the access is blocked; returns **false** otherwise.|

## WebKeyboardCallback<sup>12+</sup>

type WebKeyboardCallback = (keyboardCallbackInfo: WebKeyboardCallbackInfo) => WebKeyboardOptions

Defines a callback to intercept the soft keyboard initiated from editable elements on a web page. This event is typically called when the **\<input>** tag on the web page is clicked.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name          | Type  | Mandatory  | Description              |
| ------------- | ------ | ---- | ------------------ |
| keyboardCallbackInfo    | [WebKeyboardCallbackInfo](./ts-basic-components-web-i.md#webkeyboardcallbackinfo12) | Yes   | Input parameter of the callback for intercepting the soft keyboard initiated from editable elements on a web page, including [WebKeyboardController](./ts-basic-components-web.md#webkeyboardcontroller12) and editable element attributes. |

**Return value**

| Type              | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| [WebKeyboardOptions](./ts-basic-components-web-i.md#webkeyboardoptions12) | [WebKeyboardOptions](./ts-basic-components-web-i.md#webkeyboardoptions12) instance, which is used to determine which type of soft keyboard to start by the ArkWeb kernel.|
