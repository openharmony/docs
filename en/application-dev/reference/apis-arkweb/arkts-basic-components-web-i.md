# Interfaces (Others)

> **NOTE**
>
> - This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## WebOptions

Defines web options through the [APIs](./arkts-basic-components-web.md).

**System capability**: SystemCapability.Web.Webview.Core

| Name       | Type                                    | Mandatory  | Description                                    |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| src        | string \| [Resource](../apis-arkui/arkui-ts/ts-types.md#resource)   | Yes   | Address of a web page resource. To access local resource files, use the $rawfile or resource protocol. To load a local resource file (in HTML or TXT format) in the sandbox outside of the application package, use **file://** to specify the path of the sandbox.<br>**src** cannot be dynamically changed through a state variable (for example, @State). To change the value, call [loadUrl()](./arkts-apis-webview-WebviewController.md#loadurl).|
| controller | [WebController](./arkts-basic-components-web-WebController.md) \| [WebviewController<sup>9+</sup>](./arkts-basic-components-web-t.md#webviewcontroller9)  | Yes   | Controller that controls various behaviors of **Web** components, including page navigation, declaration period status, and JavaScript interaction. This API is deprecated since API version 9. You are advised to use **WebviewController** instead.|
| renderMode<sup>12+</sup> | [RenderMode](./arkts-basic-components-web-e.md#rendermode12)| No  | Rendering mode.<br>**RenderMode.ASYNC_RENDER** (default, cannot be dynamically adjusted): The **Web** component is rendered asynchronously.<br>**RenderMode.SYNC_RENDER**: The **Web** component is rendered synchronously within the current execution context.|
| incognitoMode<sup>11+</sup> | boolean | No| Whether to enable incognito mode. The value **true** means to enable incognito mode, and **false** means the opposite.<br> Default value: **false**.|
| sharedRenderProcessToken<sup>12+</sup> | string | No| Token of the shared rendering process specified by the **Web** component. In multi-rendering process mode, the **Web** component with the same token preferentially attempts to reuse the rendering process bound to the token. The token is bound to the rendering process when the rendering process is initialized. When the rendering process is not associated with a **Web** component, its binding to the token is removed.<br> Default value: **""**. |

## WebMediaOptions<sup>10+</sup>

Describes the web media options.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ------- | ---- | ---------------------------------------- |
| resumeInterval | number  | No   | Validity period for automatically resuming a web audio paused by another application, in seconds. The value range is [-2147483648, 2147483647]. If **resumeInterval** is set to **0**, the playback is not automatically resumed. If **resumeInterval** is set to a value greater than 0, the playback is resumed in the specified period. If **resumeInterval** is set to a value less than 0, the playback is resumed in an unlimited period. Due to the approximate value, the validity period may have a deviation of less than 1 second.<br>**NOTE**<br>After an HLS video is interrupted, the video playback is automatically resumed when the video is returned to the foreground.|
| audioExclusive | boolean | No   | Whether the audio of multiple **Web** instances in an application is exclusive.<br>The value **true** indicates that the audio of multiple **Web** instances in an application is exclusive, and **false** indicates the opposite.                      |
| audioSessionType<sup>20+</sup> | [AudioSessionType](./arkts-basic-components-web-e.md#audiosessiontype20) | No   | Web audio type in the application. The default value is [STREAM_USAGE_MUSIC](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage). This parameter changes the mapping between the component audio type and the system audio type, which affects the ArkWeb audio focus policy.|

## ScriptItem<sup>11+</sup>

Describes the **ScriptItem** object registered with the **Web** component through the [javaScriptOnDocumentStart](./arkts-basic-components-web-attributes.md#javascriptondocumentstart11) attribute.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Type            | Mandatory  | Description                   |
| ----------- | -------------- | ---- | --------------------- |
| script      | string         | Yes   | JavaScript script to be registered and executed.|
| scriptRules | Array\<string> | Yes  | Matching rules for allowed sources.<br>1. To allow URLs from all sources, use the wildcard (\*).<br>2. If exact match is required, specify the exact URL, for example, **https:\//www\.example.com**.<br>3. For fuzzy match, you can use a wildcard (\*) in the website URL, for example, **https://*.example.com**. Websites such as "x,*.y.com" and "* foobar.com" are not allowed.<br>4. If the source is an IP address, follow rule 2.<br>5. For protocols other than HTTP/HTTPS (custom protocols), exact match and fuzzy match are not supported, and the protocol must end with "://", for example, **resource://**.<br>6. If one of the preceding rules is not met in **scriptRules**, the **scriptRules** does not take effect.|

## NestedScrollOptionsExt<sup>14+</sup>

Implements a **NestedScrollOptionsExt** object to set up, down, left, and right nested scrolling options.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type              | Mandatory  | Description                  |
| -------------- | ---------------- | ---- | -------------------- |
| scrollUp  | [NestedScrollMode](../apis-arkui/arkui-ts/ts-appendix-enums.md#nestedscrollmode10) | No   | Nested scrolling options when the component scrolls up.|
| scrollDown | [NestedScrollMode](../apis-arkui/arkui-ts/ts-appendix-enums.md#nestedscrollmode10) | No   | Nested scrolling options when the component scrolls down.|
| scrollLeft  | [NestedScrollMode](../apis-arkui/arkui-ts/ts-appendix-enums.md#nestedscrollmode10) | No   | Nested scrolling options when the component scrolls left.|
| scrollRight | [NestedScrollMode](../apis-arkui/arkui-ts/ts-appendix-enums.md#nestedscrollmode10) | No   | Nested scrolling options when the component scrolls right.|

## NativeMediaPlayerConfig<sup>12+</sup>

Represents the configuration for [enabling the application to take over web page media playback](./arkts-basic-components-web-attributes.md#enablenativemediaplayer12).

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Mandatory| Description|
|------|------|------|------|
|  enable  | boolean | Yes| Whether to enable the application to take over web page media playback.<br> The value **true** means to enable the application to take over web page media playback, and **false** means the opposite.<br> Default value: **false**.|
|  shouldOverlay | boolean | Yes| Whether the video player's display overlays the web page content when the application takes over the web page's video player.<br> The value **true** indicates that the video player's display overlays the web page content. This means that the height of the video layer is adjusted to cover the web page content. The value **false** indicates that the video player's display does not overlay the web page content. This means that the video player maintains its original height and is embedded within the web page.<br>Default value: **false**.|

## ExpandedMenuItemOptions<sup>12+</sup>

Represents the custom expanded menu item options.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Type                                            | Mandatory   | Description            |
| ---------- | -----------------------------------------------------| ------ | ---------------- |
| content   | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr)  | Yes    | Display content.    |
| startIcon | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr)  | No    | Display icon.    |
| action    | (selectedText: {plainText: string}) => void                    | Yes    | Selected text.|

## AdsBlockedDetails<sup>12+</sup>

Provides detailed information about the blocked ads when ads are blocked.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type                                                                          | Mandatory  | Description                   |
| ------- | --------------------------------------------------------------------------------  | ---- | ------------------------- |
| url | string  | Yes   | URL of the page where ads are blocked.|
| adsBlocked | Array\<string\>  | Yes   | URLs or dompaths of the blocked ads. If multiple ads have the same URLs, duplicate elements may exist.|

## SelectionMenuOptionsExt<sup>13+</sup>

Represents the selection menu option extension.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Type                                            | Mandatory   | Description            |
| ---------- | -----------------------------------------------------| ------ | ---------------- |
| onAppear   | Callback\<void\>   | No    | Callback invoked when the custom selection menu appears.    |
| onDisappear | Callback\<void\>  | No    | Callback invoked when the custom selection menu disappears.    |
| preview    | [CustomBuilder](../apis-arkui/arkui-ts/ts-types.md#custombuilder8)          | No    | Preview content style of the custom selection menu. If this parameter is not set, there is no preview content.|
| menuType   | [MenuType](../apis-arkui/arkui-ts/ts-text-common.md#menutype13)     | No    | Type of the custom selection menu.<br>Default value: **MenuType.SELECTION_MENU**<br> Since API version 20, **MenuType.PREVIEW_MENU** supports hyperlink preview.    |
| previewMenuOptions<sup>20+</sup> | [PreviewMenuOptions](#previewmenuoptions20) | No    | Custom preview menu options.|

## PreviewMenuOptions<sup>20+</sup>

Represents the options of the preview menu.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Type                                            | Mandatory   | Description            |
| ---------- | -----------------------------------------------------| ------ | ---------------- |
| hapticFeedbackMode   | [HapticFeedbackMode](../apis-arkui/arkui-ts/ts-universal-attributes-menu.md#hapticfeedbackmode18)   | No    | Vibration effect when the menu is displayed. The **ohos.permission.VIBRATE** permission is required.<br>Default value: **HapticFeedbackMode.DISABLED**, indicating no vibration when the menu is displayed.    |

## EmbedOptions<sup>16+</sup>

Represents the same-layer rendering configuration of the **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ------- | ---- | ---------------------------------------- |
| supportDefaultIntrinsicSize | boolean | No   | Whether a same-layer rendering element supports the fixed size of 300 × 150.<br>When the size of an element is set using CSS on the HTML5 side, the size of the same-layer rendering element uses the CSS size. Otherwise, the size is fixed.<br>If the value is **true**, the fixed size is 300 × 150.<br>If the value is **false** and the CSS size is not set on the HTML5 side, the same-layer rendering elements are not rendered.<br>Default value: **false**.<br>Unit: px.|
| supportCssDisplayChange<sup>20+</sup> | boolean | No   | Whether the same-layer rendering visibility API supports the display attribute.<br>By default, the visibility status of same-layer tags relative to the viewport is supported.<br>If this attribute is set to **true**, CSS attributes can be displayed, including visibility, display, width, and height.<br>Otherwise, CSS attributes are not displayed, and only same-layer tags are visible relative to the viewport.|

## OnAlertEvent<sup>12+</sup>

Represents the callback invoked when **alert()** is invoked to display an alert dialog box on the web page.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | Yes| URL of the web page where the dialog box is displayed.                      |
| message | string | Yes| Message displayed in the dialog box.                      |
| result | [JsResult](./arkts-basic-components-web-JsResult.md) | Yes| User operation.                      |

## OnBeforeUnloadEvent<sup>12+</sup>

Represents the callback invoked when this page is about to exit after the user refreshes or closes the page.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | Yes| URL of the web page where the dialog box is displayed.                      |
| message | string | Yes| Message displayed in the dialog box.                      |
| result | [JsResult](./arkts-basic-components-web-JsResult.md) | Yes| User operation.                      |
| isReload<sup>20+</sup> | boolean | No| Whether the page is refreshed.<br>The value **true** indicates that the page is about to leave due to refreshing, and **false** indicates that the page is about to leave due to closing.<br>Default value: **false**.|

## OnConfirmEvent<sup>12+</sup>

Represents the callback triggered when **confirm()** is invoked by the web page.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | Yes| URL of the web page where the dialog box is displayed.                      |
| message | string | Yes| Message displayed in the dialog box.                      |
| result | [JsResult](./arkts-basic-components-web-JsResult.md) | Yes| User operation.                      |

## OnPromptEvent<sup>12+</sup>

Represents the callback triggered when **prompt()** is invoked by the web page.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | Yes| URL of the web page where the dialog box is displayed.                      |
| message | string | Yes| Message displayed in the dialog box.                      |
| value | string | Yes| Information in the dialog box.                      |
| result | [JsResult](./arkts-basic-components-web-JsResult.md) | Yes| User operation.                      |

## OnConsoleEvent<sup>12+</sup>

Represents the callback invoked to notify the host application of a JavaScript console message.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| message | [ConsoleMessage](./arkts-basic-components-web-ConsoleMessage.md) | Yes| Console message.                      |

## OnErrorReceiveEvent<sup>12+</sup>

Represents the callback triggered when an error occurs during web page loading.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| request | [WebResourceRequest](./arkts-basic-components-web-WebResourceRequest.md) | Yes| Encapsulation of a web page request.     |
| error   | [WebResourceError](./arkts-basic-components-web-WebResourceError.md)    | Yes| Encapsulation of a web page resource loading error.|

## OnHttpErrorReceiveEvent<sup>12+</sup>

Represents the callback triggered when an HTTP error occurs during web page resource loading.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| request | [WebResourceRequest](./arkts-basic-components-web-WebResourceRequest.md) | Yes| Encapsulation of a web page request.     |
| response   | [WebResourceResponse](./arkts-basic-components-web-WebResourceResponse.md)    | Yes| Encapsulation of a resource response.|

## OnDownloadStartEvent<sup>12+</sup>

Represents the callback invoked when the host application starts downloading a file.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url                | string | Yes| URL for the download task.                          |
| userAgent          | string | Yes| User agent used for download.                         |
| contentDisposition | string | Yes| Content-Disposition response header returned by the server, which may be empty.|
| mimetype           | string | Yes| MIME type of the content returned by the server.               |
| contentLength      | number | Yes| Length of the content returned by the server.                        |

## OnRefreshAccessedHistoryEvent<sup>12+</sup>

Represents the callback invoked when the access history of the web page is refreshed.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url         | string  | Yes| URL to be accessed.                                 |
| isRefreshed | boolean | Yes| Whether the page is reloaded. The value **true** means that the page is reloaded by invoking the [refresh<sup>9+</sup>](./arkts-apis-webview-WebviewController.md#refresh) API, and **false** means the opposite.|

## OnRenderExitedEvent<sup>12+</sup>

Represents the callback invoked when the rendering process exits.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| renderExitReason | [RenderExitReason](./arkts-basic-components-web-e.md#renderexitreason9) | Yes| Cause for the abnormal exit of the rendering process.|

## OnShowFileSelectorEvent<sup>12+</sup>

Represents the callback invoked to notify the file selector result.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| result       | [FileSelectorResult](./arkts-basic-components-web-FileSelectorResult.md) | Yes| File selection result to be sent to the **Web** component.|
| fileSelector | [FileSelectorParam](./arkts-basic-components-web-FileSelectorParam.md) | Yes| Information about the file selector.      |

## OnResourceLoadEvent<sup>12+</sup>

Represents the callback invoked when the URL is loaded.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url  | string | Yes| URL of the loaded resource file.|

## OnScaleChangeEvent<sup>12+</sup>

Represents the callback invoked when the display scale of this page changes.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| oldScale | number | Yes| Display scale of the page before the change.|
| newScale | number | Yes| Display scale of the page after the change.|

## OnHttpAuthRequestEvent<sup>12+</sup>

Represents the callback invoked when an HTTP authentication request is received.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler | [HttpAuthHandler](./arkts-basic-components-web-HttpAuthHandler.md) | Yes| User operation.  |
| host    | string                               | Yes| Host to which the HTTP authentication credential is applied.|
| realm   | string                               | Yes| Realm to which the HTTP authentication credential is applied. |

## OnInterceptRequestEvent<sup>12+</sup>

Represents the callback invoked when the **Web** component is about to load a URL.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| request | [WebResourceRequest](./arkts-basic-components-web-WebResourceRequest.md) | Yes| Information about the URL request.|

## OnPermissionRequestEvent<sup>12+</sup>

Represents the callback invoked when a permission request is received.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| request | [PermissionRequest](./arkts-basic-components-web-PermissionRequest.md) | Yes| User operation.|

## OnScreenCaptureRequestEvent<sup>12+</sup>

Represents the callback invoked when a screen capture request is received.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler | [ScreenCaptureHandler](./arkts-basic-components-web-ScreenCaptureHandler.md) | Yes| User operation.|

## OnContextMenuShowEvent<sup>12+</sup>

Represents the callback invoked during a call to allow for the display of a custom context menu.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| param  | [WebContextMenuParam](./arkts-basic-components-web-WebContextMenuParam.md) | Yes| Parameters related to the context menu.    |
| result | [WebContextMenuResult](./arkts-basic-components-web-WebContextMenuResult.md) | Yes| Result of the context menu.|

## OnSearchResultReceiveEvent<sup>12+</sup>

Represents the callback invoked to notify the caller of the search result on the web page.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| activeMatchOrdinal | number  | Yes| Sequence number of the current match, which starts from 0.                      |
| numberOfMatches    | number  | Yes| Total number of matches.                           |
| isDoneCounting     | boolean | Yes| Whether the search operation on the current page is complete.<br>The value **true** indicates that the search operation on the current page is complete, and **false** indicates the opposite.<br>This API may be called multiple times until **isDoneCounting** is **true**.|

## OnScrollEvent<sup>12+</sup>

Represents the callback invoked when the scrollbar scrolls to a specified position.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| xOffset | number | Yes| Position of the scrollbar on the x-axis relative to the leftmost of the web page.<br>Unit: vp.|
| yOffset | number | Yes| Position of the scrollbar on the y-axis relative to the top of the web page.<br>Unit: vp.|

## OnSslErrorEventReceiveEvent<sup>12+</sup>

Represents the callback invoked when the web page receives an SSL error.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler | [SslErrorHandler](./arkts-basic-components-web-SslErrorHandler.md) | Yes| User operation.|
| error   | [SslError](./arkts-basic-components-web-e.md#sslerror9)           | Yes| Error code.          |
| certChainData<sup>15+</sup>   | Array<Uint8Array\>           | No| Certificate chain data.          |

## SslErrorEvent<sup>12+</sup>

Provides details about the callback invoked when an SSL error occurs during resource loading.

**System capability**: SystemCapability.Web.Webview.Core

| Name    | Type                                | Mandatory  | Description          |
| ------- | ------------------------------------ | ---- | -------------- |
| handler | [SslErrorHandler](./arkts-basic-components-web-SslErrorHandler.md) | Yes   | User operation.|
| error   | [SslError](./arkts-basic-components-web-e.md#sslerror9)        | Yes   | Error code.          |
| url   | string                                 | Yes   | URL.          |
| originalUrl   | string                         | Yes   | Original URL of the request.          |
| referrer   | string                            | Yes   | Referrer URL.          |
| isFatalError   | boolean                       | Yes   | Whether the error is a fatal error.<br>The value **true** indicates a fatal error, and **false** indicates a non-fatal error.          |
| isMainFrame   | boolean                        | Yes   | Whether the resource is a main resource.<br>The value **true** indicates a main resource, and **false** indicates a non-main resource.          |
| certChainData<sup>20+</sup>   | Array<Uint8Array\>           | No| Certificate chain data.          |

## OnClientAuthenticationEvent<sup>12+</sup>

Represents the callback invoked when an SSL client certificate is required from the user.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler  | [ClientAuthenticationHandler](./arkts-basic-components-web-ClientAuthenticationHandler.md) | Yes| User operation. |
| host     | string                                   | Yes| Host name of the server that requests a certificate.   |
| port     | number                                   | Yes| Port number of the server that requests a certificate.   |
| keyTypes | Array<string\>                           | Yes| Acceptable asymmetric private key types.   |
| issuers  | Array<string\>                           | Yes| Issuer of the certificate that matches the private key.|

## OnWindowNewEvent<sup>12+</sup>

Represents the callback invoked when the web page requests the user to create a window.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| isAlert       | boolean                                  | Yes| Whether to open the target URL in a new window. The value **true** means to open the target URL in a new window, and **false** means to open the target URL in a new tab.   |
| isUserTrigger | boolean                                  | Yes| Whether the creation is triggered by the user. The value **true** means that the creation is triggered by the user, and **false** means the opposite.     |
| targetUrl     | string                                   | Yes| Target URL.                       |
| handler       | [ControllerHandler](./arkts-basic-components-web-ControllerHandler.md) | Yes| **WebviewController** instance for setting the new window.|

## OnTouchIconUrlReceivedEvent<sup>12+</sup>

Represents the callback invoked when an apple-touch-icon URL is received.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url         | string  | Yes| Received apple-touch-icon URL.|
| precomposed | boolean | Yes| Whether the apple-touch-icon is precomposed.<br>**true** indicates that the apple-touch-icon is precomposed, and **false** indicates the opposite.  |

## OnFaviconReceivedEvent<sup>12+</sup>

Represents the callback invoked when this web page receives a new favicon.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| favicon | [PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | Yes| **PixelMap** object of the received favicon.|

## OnPageVisibleEvent<sup>12+</sup>

Represents the callback invoked when the old page is not displayed and the new page is about to be visible.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url  | string | Yes| URL of the new page that is able to be visible when the old page is not displayed.|

## OnDataResubmittedEvent<sup>12+</sup>

Represents the callback invoked when the web form data can be resubmitted.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler | [DataResubmissionHandler](./arkts-basic-components-web-DataResubmissionHandler.md) | Yes| Handler for resubmitting web form data.|

## OnAudioStateChangedEvent<sup>12+</sup>

Represents the callback invoked when the audio playback status on the web page changes.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| playing | boolean | Yes| Audio playback status on the current page. The value **true** means that audio is being played, and **false** means the opposite.|

## OnFirstContentfulPaintEvent<sup>12+</sup>

Represents the callback invoked when the first content paint occurs on the web page.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| navigationStartTick    | number | Yes| Navigation start time, in microseconds.         |
| firstContentfulPaintMs | number | Yes| Time between navigation and when the content is first rendered, in milliseconds.|

## OnLoadInterceptEvent<sup>12+</sup>

Represents the callback invoked when the **Web** component is about to access a URL.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| data | [WebResourceRequest](./arkts-basic-components-web-WebResourceRequest.md) | Yes| Information about the URL request.|

## OnOverScrollEvent<sup>12+</sup>

Represents the callback invoked when the web page is overscrolled.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| xOffset | number | Yes| Horizontal overscroll offset based on the leftmost edge of the web page.<br>Unit: vp.|
| yOffset | number | Yes| Vertical overscroll offset based on the top edge of the web page.<br>Unit: vp.|

## JavaScriptProxy<sup>12+</sup>

Represents the JavaScript object to be injected.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| object     | object                                   | Yes   | Object to be registered. Methods can be declared, but attributes cannot.                  |
| name       | string                                   | Yes   | Name of the object to be registered, which is the same as that invoked in the window.               |
| methodList | Array\<string\>                          | Yes   | Synchronous methods of the JavaScript object to be registered at the application side.                |
| controller | [WebController](./arkts-basic-components-web-WebController.md) \| [WebviewController<sup>9+</sup>](./arkts-apis-webview-WebviewController.md) | Yes   | -    | Controller. This API is deprecated since API version 9. You are advised to use **WebviewController** instead.|
| asyncMethodList<sup>12+</sup>  | Array\<string\>      | No   | Asynchronous methods of the JavaScript object to be registered at the application side. Asynchronous methods cannot obtain return values.  |
| permission<sup>12+</sup>  | string  | No   | JSON string, which is empty by default. This string is used to configure JSBridge permission control and define the URL trustlist at the object and method levels.<br>For the example, see [Invoking Application Functions on the Frontend Page](../../web/web-in-page-app-function-invoking.md).|

## OnPageEndEvent<sup>12+</sup>

Represents the callback invoked when the web page loading ends.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | Yes| URL of the page.                      |

## OnPageBeginEvent<sup>12+</sup>

Represents the callback invoked when the web page loading begins.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | Yes| URL of the page.                      |

## OnProgressChangeEvent<sup>12+</sup>

Represents the callback invoked when the web page loading progress changes.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| newProgress | number | Yes| New loading progress. The value is an integer ranging from 0 to 100.                      |

## OnTitleReceiveEvent<sup>12+</sup>

Represents the callback invoked when the document title of the web page is changed.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| title | string | Yes| Document title.                      |
| isRealTitle<sup>20+</sup> | boolean | No| Whether the document title is a real title. The value true indicates that the title is from the **title** tag of the web page, and **false** indicates that the title is automatically generated based on the URL.                      |

## OnGeolocationShowEvent<sup>12+</sup>

Represents the callback invoked when a request to obtain the geolocation information is received.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| origin | string | Yes| Index of the origin.                      |
| geolocation | [JsGeolocation](./arkts-basic-components-web-JsGeolocation.md) | Yes| User operation.                      |

## NativeEmbedVisibilityInfo<sup>12+</sup>

Provides visibility information about the same-layer tag.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Type                               | Mandatory  | Description             |
| -------------  | ------------------------------------| ----- | ------------------ |
| visibility     | boolean                             | Yes    | Whether the same-layer tag is visible.<br>The value **true** indicates that the same-layer tag is visible, and **false** indicates the opposite.        |
| embedId        | string                              | Yes    | ID of the same-layer rendered tag. |

## RenderProcessNotRespondingData<sup>12+</sup>

Provides detailed information about the unresponsive rendering process.

**System capability**: SystemCapability.Web.Webview.Core

| Name                    | Type  | Mandatory| Description                                  |
| ------------------------ | ------ | ---- | -------------------------------------- |
| jsStack      | string | Yes | JavaScript call stack information of the web page.      |
| pid | number | Yes  | Process ID of the web page.|
| reason | [RenderProcessNotRespondingReason](./arkts-basic-components-web-e.md#renderprocessnotrespondingreason12) | Yes  | Reason why the rendering process does not respond.|

## FullScreenEnterEvent<sup>12+</sup>

Provides details about the event that the **Web** component to enter the full-screen mode.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type                                 | Mandatory  | Description                   |
| -----------     | ------------------------------------ | ---- | --------------------- |
| handler     | [FullScreenExitHandler](./arkts-basic-components-web-FullScreenExitHandler.md) | Yes   | Function handle for exiting full screen mode.|
| videoWidth  | number | No   | Video width, in px. If the element that enters fulls screen mode is a **\<video>** element, the value represents its width; if the element that enters fulls screen mode contains a **\<video>** element, the value represents the width of the first sub-video element; in other cases, the value is **0**.|
| videoHeight  | number | No   | Video height, in px. If the element that enters fulls screen mode is a **\<video>** element, the value represents its height; if the element that enters fulls screen mode contains a **\<video>** element, the value represents the height of the first sub-video element; in other cases, the value is **0**.|

## LoadCommittedDetails<sup>11+</sup>

Provides detailed information about the web page that has been submitted for redirection.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type                                 | Mandatory  | Description                   |
| -----------     | ------------------------------------ | ---- | --------------------- |
| isMainFrame     | boolean                              | Yes   | Whether the document is the main document.<br>The value **true** indicates that the document is the main document, and **false** indicates the opposite.|
| isSameDocument  | boolean                              | Yes   | Whether to navigate without changing the document.<br>The value **true** means to navigate without changing the document, and **false** means the opposite.<br>Example of navigation in the same document: 1. navigation shown in the example; 2. navigation triggered by **pushState** or **replaceState**; 3. navigation to a history entry on the same page. |
| didReplaceEntry | boolean                              | Yes   | Whether the submitted new entry replaces the existing entry.<br>The value **true** indicates that the submitted new entry replaces the existing entry, and **false** indicates the opposite.<br>In certain scenarios for navigation to a subdocument, although the existing entry is not replaced, some attributes are changed. |
| navigationType  | [WebNavigationType](./arkts-basic-components-web-e.md#webnavigationtype11)  | Yes   | Navigation type.      |
| url             | string                               | Yes   | URL of the current navigated-to web page.         |

## NativeEmbedInfo<sup>11+</sup>

Provides detailed information about the same-layer tag.

**System capability**: SystemCapability.Web.Webview.Core

| Name               | Type                                 | Mandatory  | Description                       |
|-------------------| ------------------------------------ | ---- |---------------------------|
| id                | string             | No   | ID of the same-layer tag.            |
| type              | string                              | No   | Type of the same-layer tag. The value is in lowercase.  |
| src               | string                              | No   | **src** information of the same-layer tag.           |
| width             | number  | No   | Width of the same-layer tag, in px.         |
| height            | number                              | No   | Height of the same-layer tag, in px.         |
| url               | string                              | No   | URL of the same-layer tag.           |
| tag<sup>12+</sup> | string              | No   | Tag name, which is in uppercase.             |
| params<sup>12+</sup>            | Map<string, string> | No   | List of key-value pairs contained in the **object** tag that form a map of the Object type. Use the methods provided by the Object type, such as **embed.info?.param?.["name"]** to operate the map object. |
| position<sup>12+</sup>          | Position            | No   | Position of the same-layer tag relative to the **Web** component in the screen coordinate system, which is different from the standard **Position**. The unit is px.|

## IntelligentTrackingPreventionDetails<sup>12+</sup>

Provides detailed information about intelligent tracking prevention.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Type                               | Mandatory  | Description        |
| ------------- | ------------------------------------| ----- | ------------ |
| host          | string                              | Yes    | Host name.   |
| trackerHost   | string                              | Yes    | Host name of the tracker. |

## WebKeyboardCallbackInfo<sup>12+</sup>

Represents input parameters of the callback used to intercept the soft keyboard started from editable elements on a web page, including [WebKeyboardController](./arkts-basic-components-web-WebKeyboardController.md) and editable element attributes.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ------- | ---- | ---------------------------------------- |
| controller | [WebKeyboardController](./arkts-basic-components-web-WebKeyboardController.md)  | Yes   | Controller used to control the input, deletion, and closure of the custom keyboard.|
| attributes | Record<string, string> | Yes   | Attribute of the web page element that triggers the display of the soft keyboard.

## WebKeyboardOptions<sup>12+</sup>

Represents the return value of the callback that intercepts the soft keyboard started from editable elements on the web page. You can specify the types of the keyboard, and return the value to the Web kernel to control the startup of different types of soft keyboards.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ------- | ---- | ---------------------------------------- |
| useSystemKeyboard | boolean  | Yes   | Whether to use the system's default soft keyboard.<br>The value **true** means to use the system's default soft keyboard, and **false** means the opposite.<br>Default value: **true**.|
| enterKeyType | number | No   | Type of the Enter key of the system soft keyboard. For details about the value range, see [EnterKeyType](../apis-ime-kit/js-apis-inputmethod.md#enterkeytype10). This parameter takes effect only when **useSystemKeyboard** is set to **true** and **enterKeyType** is set to a valid value.|
| customKeyboard | [CustomBuilder](../apis-arkui/arkui-ts/ts-types.md#custombuilder8) | No   | Builder of a custom keyboard. This parameter is required when **useSystemKeyboard** is set to **false**. After it is set, the **Web** component starts the custom keyboard as configured.


## FirstMeaningfulPaint<sup>12+</sup>

Provides detailed information about the first meaningful paint.

**System capability**: SystemCapability.Web.Webview.Core

| Name                    | Type  | Mandatory| Description                                  |
| ------------------------ | ------ | ---- | -------------------------------------- |
| navigationStartTime      | number | No | Start time of the navigation, in microseconds.      |
| firstMeaningfulPaintTime | number | No  | Time taken for the first meaningful paint of the page, in milliseconds.|

## LargestContentfulPaint<sup>12+</sup>

Provides detailed information about the largest content paint.

**System capability**: SystemCapability.Web.Webview.Core

| Name                     | Type  | Mandatory| Description                                    |
| ------------------------- | ------ | ---- | ---------------------------------------- |
| navigationStartTime       | number | No  | Start time of the navigation, in microseconds.        |
| largestImagePaintTime     | number | No  | Loading time of the maximum image, in milliseconds.  |
| largestTextPaintTime      | number | No  | Loading time of the maximum text, in milliseconds.    |
| largestImageLoadStartTime | number | No  | Start time of the loading of the maximum image, in milliseconds.|
| largestImageLoadEndTime   | number | No  | End time of the loading of the maximum image, in milliseconds.|
| imageBPP                  | number | No  | Number of pixels of the maximum image.                          |

## NativeEmbedDataInfo<sup>11+</sup>

Provides detailed information about the changes of the same-layer tag lifecycle.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type                                 | Mandatory  | Description                   |
| -----------     | ------------------------------------ | ---- | --------------------- |
| status     | [NativeEmbedStatus](./arkts-basic-components-web-e.md#nativeembedstatus11)             | No   | Lifecycle status of the same-layer tag.|
| surfaceId  | string                              | No   | Surface ID of the native image. |
| embedId | string                              | No   | Unique ID of the same-layer tag. |
| info  | [NativeEmbedInfo](./arkts-basic-components-web-i.md#nativeembedinfo11)  | No   | Detailed information about the same-layer tag.      |

## NativeEmbedTouchInfo<sup>11+</sup>

Provides touch information of the same-layer tag.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type                                 | Mandatory  | Description                   |
| -----------     | ------------------------------------ | ---- | --------------------- |
| embedId     | string   | No   | Unique ID of the same-layer tag.|
| touchEvent  | [TouchEvent](../apis-arkui/arkui-ts/ts-universal-events-touch.md#touchevent) | No   | Touch action information.|
| result<sup>12+</sup>     | [EventResult](./arkts-basic-components-web-EventResult.md)   | No   | Gesture event consumption result.|

## NativeEmbedMouseInfo<sup>20+</sup>

Provides detailed information about clicking or touching and holding a same-layer tag using the mouse or touchpad.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type                                 | Mandatory  | Description                   |
| -----------     | ------------------------------------ | ---- | --------------------- |
| embedId     | string   | No   | Unique ID of the same-layer tag.|
| mouseEvent  | [MouseEvent](../apis-arkui/arkui-ts/ts-universal-mouse-key.md#mouseevent) | No   | Information about clicking or touching and holding using the mouse or touchpad.|
| result     | [EventResult](./arkts-basic-components-web-EventResult.md)   | No   | Mouse event consumption result.|

## OnLoadStartedEvent<sup>20+</sup>

Represents the callback invoked when the web page loading begins.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | Yes| URL of the page.                      |

## OnLoadFinishedEvent<sup>20+</sup>

Represents the callback invoked when the web page loading ends.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | Yes| URL of the page.                      |

## Header

Request or response header object returned by the **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Type    | Mandatory  | Description           |
| ----------- | ------ | ---- | ------------- |
| headerKey   | string | Yes   | Key of the request or response header.  |
| headerValue | string | Yes   | Value of the request or response header.|

## ScreenCaptureConfig<sup>10+</sup>

Provides the web screen capture configuration.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Type                                     | Mandatory  | Description        |
| ----------- | --------------------------------------- | ---- | ---------- |
| captureMode | [WebCaptureMode](./arkts-basic-components-web-e.md#webcapturemode10) | Yes   | Web screen capture mode.|
