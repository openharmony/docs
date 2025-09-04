# Interfaces (Others)

> **NOTE**
>
> - The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## WebMediaOptions<sup>10+</sup>

Describes the web-based media playback policy.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional | Description                                      |
| -------------- | ------- | ---- | ---- | ---------------------------------------- |
| resumeInterval | number  | No| Yes| Validity period for automatically resuming a web audio paused by another application, in seconds. The value range is [-2147483648, 2147483647]. If **resumeInterval** is set to **0**, the playback is not automatically resumed. If **resumeInterval** is set to a value greater than 0, the playback is resumed in the specified period. If **resumeInterval** is set to a value less than 0, the playback is resumed in an unlimited period. Due to the approximate value, the validity period may have a deviation of less than 1 second.|
| audioExclusive | boolean | No| Yes| Whether the audio of multiple **Web** instances in an application is exclusive.<br>The value **true** indicates that the audio of multiple **Web** instances in an application is exclusive, and **false** indicates the opposite.                      |

## ScriptItem<sup>11+</sup>

Describes the **ScriptItem** object injected to the **Web** component through the [javaScriptOnDocumentStart](./ts-basic-components-web-attributes.md#javascriptondocumentstart11) attribute.

**System capability**: SystemCapability.Web.Webview.Core

| Name        | Type          | Read-Only| Optional  | Description          |
| ----------- | -------------- | --- | ------|--------------- |
| script      | string         | No |  No   | JavaScript script to be injected and executed.|
| scriptRules | Array\<string> | No |  No   | Matching rules for allowed sources.<br>1. To allow URLs from all sources, use the wildcard (\*).<br>2. If exact match is required, specify the exact URL, for example, **https:\//www\\.example.com**.<br>3. For fuzzy match, you can use a wildcard (\*) in the website URL, for example, **https://\*.example.com**. Websites such as "x,*.y.com" and "* foobar.com" are not allowed.  <br>4. If the source is an IP address, follow rule 2.<br>5. For protocols other than HTTP/HTTPS (custom protocols), exact match and fuzzy match are not supported, and the protocol must end with "://", for example, **resource://**.<br>6. If one of the preceding rules is not met in **scriptRules**, the **scriptRules** does not take effect.|

## NestedScrollOptionsExt<sup>14+</sup>

Implements a **NestedScrollOptionsExt** object to set up, down, left, and right nested scrolling options.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type              | Read-Only| Optional| Description                  |
| -------------- | ---------------- | ---- | ---- | -------------------- |
| scrollUp  | [NestedScrollMode](../apis-arkui/arkui-ts/ts-appendix-enums.md#nestedscrollmode10) | No  | Yes  | Nested scrolling options when the component scrolls up.<br>Default value: **NestedScrollMode.SELF_FIRST**.|
| scrollDown | [NestedScrollMode](../apis-arkui/arkui-ts/ts-appendix-enums.md#nestedscrollmode10) | No  | Yes  | Nested scrolling options when the component scrolls down.<br>Default value: **NestedScrollMode.SELF_FIRST**.|
| scrollLeft  | [NestedScrollMode](../apis-arkui/arkui-ts/ts-appendix-enums.md#nestedscrollmode10) | No  | Yes  | Nested scrolling options when the component scrolls left.<br>Default value: **NestedScrollMode.SELF_FIRST**.|
| scrollRight | [NestedScrollMode](../apis-arkui/arkui-ts/ts-appendix-enums.md#nestedscrollmode10) | No  | Yes  | Nested scrolling options when the component scrolls right.<br>Default value: **NestedScrollMode.SELF_FIRST**.|

## NativeMediaPlayerConfig<sup>12+</sup>

Represents the configuration for [enabling the application to take over web page media playback](./ts-basic-components-web-attributes.md#enablenativemediaplayer12).

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Read-Only| Optional| Description|
|------|------|------|------|------|
|  enable  | boolean | No| No| Whether to enable the application to take over web page media playback.<br> The value **true** means to enable the application to take over web page media playback, and **false** means the opposite.<br> The default value is **false**.|
|  shouldOverlay | boolean | No| No| Whether the video player's display overlays the web page content when the application takes over the web page's video player.<br> The value **true** indicates that the video player's display overlays the web page content. This means that the height of the video layer is adjusted to cover the web page content. **false** indicates that the video player's display does not overlay the web page content. This means that the video player maintains its original height and is embedded within the web page.<br>The default value is **false**.|

## ExpandedMenuItemOptions<sup>12+</sup>

Defines the custom expanded menu options.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Type                                            | Read-Only   | Optional   | Description            |
| ---------- | -----------------------------------------------------| ------ | ------ | ---------------- |
| content   | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr)  | No   | No    | Content to display.    |
| startIcon | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr)  | No   | Yes    | Icon to display.    |
| action    | (selectedText: {plainText: string}) => void                    | No   | No    | Selected text.|

## AdsBlockedDetails<sup>12+</sup>

Provides detailed information about the blocked ads when ads are blocked.

**System capability**: SystemCapability.Web.Webview.Core

| Name       | Type            | Read-Only| Optional  | Description                |
| ---------- | -----------------|---- | ----- | -------------------- |
| url        | string           | No |  No   | URL of the page where ads are blocked.|
| adsBlocked | Array\<string\>  | No |  No   | URLs or DOMPath of the blocked ads. If ads have the same URLs, duplicate elements may exist.|

## SelectionMenuOptionsExt<sup>13+</sup>

Defines the custom expanded menu options.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Type                                            | Read-Only   | Optional   | Description            |
| ---------- | -----------------------------------------------------| ------ | ------ | ---------------- |
| onAppear   | Callback\<void\>   | No    | Yes    | Callback invoked when the custom context menu on selection appears.    |
| onDisappear | Callback\<void\>  | No    | Yes    | Callback invoked when the custom context menu on selection disappears.    |
| preview    | [CustomBuilder](../apis-arkui/arkui-ts/ts-types.md#custombuilder8)          | No    | Yes    | Preview content style of the custom selection menu. If this parameter is not set, there is no preview content.|
| menuType   | [MenuType](../apis-arkui/arkui-ts/ts-text-common.md#menutype13)     | No    | Yes    | Type of the custom context menu on selection.<br>Default value: **MenuType.SELECTION_MENU**<br> Since API version 20, **MenuType.PREVIEW_MENU** supports hyperlink preview.    |

## EmbedOptions<sup>16+</sup>

Represents the same-layer rendering configuration of the **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional| Description                                      |
| -------------- | ------- | ---- |  ---- |---------------------------------------- |
| supportDefaultIntrinsicSize | boolean | No   | Yes| Whether a same-layer rendering element supports the fixed size of 300 × 150.<br>When the size of an element is set using CSS on the HTML5 side, the size of the same-layer rendering element uses the CSS size. Otherwise, the size is fixed.<br>If the value is **true**, the fixed size is 300 × 150.<br>If the value is **false** and the CSS size is not set on the HTML5 side, the same-layer rendering elements are not rendered.<br>Default Value: **false**.<br>Unit: px|

## OnAlertEvent<sup>12+</sup>

Defines the callback used when a web page triggers **alert()**.

**System capability**: SystemCapability.Web.Webview.Core

| Name   | Type                                             | Read-Only| Optional| Description                       |
| ------- | ------------------------------------------------- | ---- | ---- | --------------------------- |
| url     | string                                            | No  | No  | URL of the web page where the dialog box is displayed.  |
| message | string                                            | No  | No  | Information displayed in the dialog box.       |
| result  | [JsResult](./ts-basic-components-web.md#jsresult) | No  | No  | User operation result that is notified to the **Web** component.|

## OnBeforeUnloadEvent<sup>12+</sup>

Represents the callback invoked when this page is about to exit after the user refreshes or closes the page.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | Yes| URL of the web page where the dialog box is displayed.                      |
| message | string | Yes| Message displayed in the dialog box.                      |
| result | [JsResult](./ts-basic-components-web.md#jsresult) | Yes| User operation.                      |

## OnConfirmEvent<sup>12+</sup>


Defines the callback used when a web page triggers **confirm()**.

**System capability**: SystemCapability.Web.Webview.Core

| Name   | Type                                             | Read-Only| Optional| Description                       |
| ------- | ------------------------------------------------- | ---- | ---- | --------------------------- |
| url     | string                                            | No  | No  | URL of the web page where the dialog box is displayed.  |
| message | string                                            | No  | No  | Information displayed in the dialog box.       |
| result  | [JsResult](./ts-basic-components-web.md#jsresult) | No  | No  | User operation result that is notified to the **Web** component.|

## OnPromptEvent<sup>12+</sup>

Defines the callback used when a web page triggers **prompt()**.

**System capability**: SystemCapability.Web.Webview.Core

| Name   | Type                                             | Read-Only| Optional| Description                       |
| ------- | ------------------------------------------------- | ---- | ---- | --------------------------- |
| url     | string                                            | No  | No  | URL of the web page where the dialog box is displayed.  |
| message | string                                            | No  | No  | Information displayed in the dialog box.       |
| value   | string                                            | No  | No  | Default information returned by the dialog box.     |
| result  | [JsResult](./ts-basic-components-web.md#jsresult) | No  | No  | User operation result that is notified to the **Web** component.|

## OnConsoleEvent<sup>12+</sup>

Represents the callback invoked to notify the host application of a JavaScript console message.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional  | Description                                      |
| -------------- | ---- | ---- | ---------|------------------------------- |
| message | [ConsoleMessage](./ts-basic-components-web.md#consolemessage) | No| No| Console message.                      |

## OnErrorReceiveEvent<sup>12+</sup>

Represents the callback invoked when an error occurs during web page loading.

**System capability**: SystemCapability.Web.Webview.Core

| Name    | Type                                                                 |Read-Only| Optional| Description              |
| ------- | --------------------------------------------------------------------- | -- | ----|------------------- |
| request | [WebResourceRequest](./ts-basic-components-web.md#webresourcerequest) | No| No| Encapsulation of a web page request.     |
| error   | [WebResourceError](./ts-basic-components-web.md#webresourceerror)     | No| No| Encapsulation of a web page resource loading error.|

## OnHttpErrorReceiveEvent<sup>12+</sup>

Represents the callback invoked when an HTTP error occurs during web page resource loading.

**System capability**: SystemCapability.Web.Webview.Core

| Name       | Type                                                                     |Read-Only| Optional| Description              |
| ---------- | ------------------------------------------------------------------------- | -- | ----|------------------- |
| request    | [WebResourceRequest](./ts-basic-components-web.md#webresourcerequest)     | No| No  | Encapsulation of a web page request. |
| response   | [WebResourceResponse](./ts-basic-components-web.md#webresourceresponse)   | No| No  | Encapsulation of a resource response. |

## OnDownloadStartEvent<sup>12+</sup>

Represents the callback invoked when the host application starts downloading a file.

**System capability**: SystemCapability.Web.Webview.Core

| Name             | Type    | Read-Only| Optional | Description                               |
| ---------------- | -------- | --- | -----|----------------------------------- |
| url                | string | No| No| URL for the download task.                          |
| userAgent          | string | No| No| User agent used for download.                         |
| contentDisposition | string | No| No| Content-Disposition response header returned by the server, which may be empty.|
| mimetype           | string | No| No| MIME type of the content returned by the server.               |
| contentLength      | number | No| No| Length of the content returned by the server.                        |

## OnRefreshAccessedHistoryEvent<sup>12+</sup>

Represents the callback invoked when the access history of the web page is refreshed.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional  | Description                                      |
| -------------- | ---- | ---- | ------------|---------------------------- |
| url         | string  | No| No| URL to be accessed.                                 |
| isRefreshed | boolean | No| No| Whether the page is reloaded. The value **true** means that the page is reloaded by invoking the [refresh<sup>9+</sup>](./js-apis-webview-WebviewController.md#refresh) API, and **false** means the opposite.|

## OnRenderExitedEvent<sup>12+</sup>

Represents the callback invoked when the rendering process exits.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional  | Description                                      |
| -------------- | ---- | ---- | ------------|---------------------------- |
| renderExitReason | [RenderExitReason](./ts-basic-components-web-e.md#renderexitreason9) | No| No| Cause for the abnormal exit of the rendering process.|

## OnShowFileSelectorEvent<sup>12+</sup>

Represents the callback invoked to notify the file selector result.

**System capability**: SystemCapability.Web.Webview.Core

| Name        | Type                                                                    | Read-Only| Optional| Description                           |
| ------------ | ------------------------------------------------------------------------ | ---- | ---- | ------------------------------- |
| result       | [FileSelectorResult](./ts-basic-components-web.md#fileselectorresult9) | No  | No  | File selection result to be sent to the **Web** component.|
| fileSelector | [FileSelectorParam](./ts-basic-components-web.md#fileselectorparam9)   | No  | No  | Information about the file selector.         |

## OnResourceLoadEvent<sup>12+</sup>

Represents the callback invoked when the URL is loaded.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional  | Description                                      |
| -------------- | ---- | ---- | ------------|---------------------------- |
| url  | string | No| No| URL of the loaded resource file.|

## OnScaleChangeEvent<sup>12+</sup>

Represents the callback invoked when the display scale of this page changes.

**System capability**: SystemCapability.Web.Webview.Core

| Name    | Type  | Read-Only| Optional| Description                    |
| -------- | ------ | ---- | ---- | ------------------------ |
| oldScale | number | No  | No  | Display ratio of the page before the change.|
| newScale | number | No  | No  | Display ratio of the page after the change.|

## OnHttpAuthRequestEvent<sup>12+</sup>

Represents the callback invoked when an HTTP authentication request is received.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional  | Description                                      |
| -------------- | ---- | ---- | -----------|----------------------------- |
| handler | [HttpAuthHandler](./ts-basic-components-web.md#httpauthhandler9) | No| No| User operation.  |
| host    | string                               | No| No| Host to which HTTP authentication credentials apply.|
| realm   | string                               | No| No| Realm to which HTTP authentication credentials apply. |

## OnInterceptRequestEvent<sup>12+</sup>

Represents the callback invoked when the **Web** component is about to load a URL.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional  | Description                                      |
| -------------- | ---- | ---- | ------------|---------------------------- |
| request | [WebResourceRequest](./ts-basic-components-web.md#webresourcerequest) | No| No| Information about the URL request.|

## OnPermissionRequestEvent<sup>12+</sup>

Represents the callback invoked when a permission request is received.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional  | Description                                      |
| -------------- | ---- | ---- | ---- | ---------------------------------------- |
| request | [PermissionRequest](./ts-basic-components-web.md#permissionrequest9) | No| No| User operation.|

## OnScreenCaptureRequestEvent<sup>12+</sup>

Represents the callback invoked when a screen capture request is received.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional| Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler | [ScreenCaptureHandler](./ts-basic-components-web.md#screencapturehandler10) | No| No| User operation.|

## OnContextMenuShowEvent<sup>12+</sup>

Represents the callback invoked during a call to allow for the display of a custom context menu.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only  | Optional  | Description                                      |
| -------------- | ---- | ---- | ---- | ---------------------------------------- |
| param  | [WebContextMenuParam](./ts-basic-components-web.md#webcontextmenuparam9) | No| No| Parameters related to the context menu.    |
| result | [WebContextMenuResult](./ts-basic-components-web.md#webcontextmenuresult9) | No| No| Result of the context menu.|

## OnSearchResultReceiveEvent<sup>12+</sup>

Represents the callback invoked to notify the caller of the search result on the web page.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional  | Description                                      |
| ------------------ | ------- | --- | --- |----------------------------- |
| activeMatchOrdinal | number  | No| No| Sequence number of the current match, which starts from 0.                      |
| numberOfMatches    | number  | No| No| Total number of matches.                           |
| isDoneCounting     | boolean | No| No| Whether the search operation on the current page is complete.<br>The value **true** indicates that the search operation on the current page is complete, and **false** indicates the opposite.<br>This API may be called multiple times until **isDoneCounting** is **true**.|

## OnScrollEvent<sup>12+</sup>

Represents the callback invoked when the scrollbar scrolls to a specified position.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional| Description                                      |
| -------------- | ---- | ---- | ---- | ---------------------------------------- |
| xOffset | number |  No  | No  | Position of the scrollbar on the x-axis relative to the leftmost of the web page.<br>Unit: vp|
| yOffset | number |  No  | No  | Position of the scrollbar on the y-axis relative to the top of the web page.<br>Unit: vp|

## OnSslErrorEventReceiveEvent<sup>12+</sup>

Represents the callback invoked when the web page receives an SSL error.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional  | Description                                      |
| -------------- | ---- | ---- | ------------|---------------------------- |
| handler | [SslErrorHandler](./ts-basic-components-web.md#sslerrorhandler9) | No| No| User operation.|
| error   | [SslError](./ts-basic-components-web-e.md#sslerror9)           | No| No| Error code.          |
| certChainData<sup>15+</sup>   | Array<Uint8Array\>           | No| Yes| Certificate chain data.          |

## SslErrorEvent<sup>12+</sup>

Provides details about the callback invoked when an SSL error occurs during resource loading.

**System capability**: SystemCapability.Web.Webview.Core

| Name    | Type                                | Read-Only| Optional  | Description          |
| ------- | ------------------------------------ | ---- | ------|------------- |
| handler | [SslErrorHandler](./ts-basic-components-web.md#sslerrorhandler9) | No| No   | User operation.|
| error   | [SslError](./ts-basic-components-web-e.md#sslerror9)        | No| No   | Error code.          |
| url   | string                                 | No| No   | URL.          |
| originalUrl   | string                         | No| No   | Original URL of the request.          |
| referrer   | string                            | No| No   | Referrer URL.          |
| isFatalError   | boolean                       | No| No   | Whether the error is a fatal error.<br>The value **true** indicates a fatal error, and **false** indicates a non-fatal error.          |
| isMainFrame   | boolean                        | No| No   | Whether the resource is a main resource.<br>The value **true** indicates a main resource, and **false** indicates a non-main resource.          |

## OnClientAuthenticationEvent<sup>12+</sup>

Represents the callback invoked when an SSL client certificate is required from the user.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional  | Description                                      |
| -------------- | ---- | ---- | ------------|---------------------------- |
| handler  | [ClientAuthenticationHandler](./ts-basic-components-web.md#clientauthenticationhandler9) | No| No| User operation. |
| host     | string                                   | No| No| Host name of the server that requests a certificate.   |
| port     | number                                   | No| No| Port number of the server that requests a certificate.   |
| keyTypes | Array<string\>                           | No| No| Acceptable asymmetric private key types.   |
| issuers  | Array<string\>                           | No| No| Issuer of the certificate that matches the private key.|

## OnWindowNewEvent<sup>12+</sup>

Represents the callback invoked when the web page requests the user to create a window.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| isAlert       | boolean                                  | Yes| Whether to open the target URL in a new window. The value **true** means to open the target URL in a new window, and **false** means to open the target URL in a new tab.   |
| isUserTrigger | boolean                                  | Yes| Whether the creation is triggered by the user. The value **true** means that the creation is triggered by the user, and **false** means the opposite.     |
| targetUrl     | string                                   | Yes| Target URL.                       |
| handler       | [ControllerHandler](./ts-basic-components-web.md#controllerhandler9) | Yes| **WebviewController** instance for setting the new window.|

## OnTouchIconUrlReceivedEvent<sup>12+</sup>

Represents the callback invoked when an apple-touch-icon URL is received.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional  | Description                                      |
| -------------- | ---- | ---- | ------------|---------------------------- |
| url         | string  | No| No| Received apple-touch-icon URL.|
| precomposed | boolean | No| No| Whether the apple-touch-icon is precomposed.<br>**true** indicates that the apple-touch-icon is precomposed, and **false** indicates the opposite.  |

## OnFaviconReceivedEvent<sup>12+</sup>

Represents the callback invoked when this web page receives a new favicon.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional  | Description                                      |
| -------------- | ---- | ---- | ------------|---------------------------- |
| favicon | [PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | No| No| **PixelMap** object of the received favicon.|

## OnPageVisibleEvent<sup>12+</sup>

Represents the callback invoked when the old page is not displayed and the new page is about to be visible.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url  | string | Yes| URL of the new page that is able to be visible when the old page is not displayed.|

## OnDataResubmittedEvent<sup>12+</sup>

Represents the callback invoked when the web form data can be resubmitted.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional  | Description                                      |
| -------------- | ---- | ---- | ------------|---------------------------- |
| handler | [DataResubmissionHandler](./ts-basic-components-web.md#dataresubmissionhandler9) | No| No| Handler for resubmitting web form data.|

## OnAudioStateChangedEvent<sup>12+</sup>

Represents the callback invoked when the audio playback status on the web page changes.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional  | Description                                      |
| -------------- | ---- | ---- | ---- | ---------------------------------------- |
| playing | boolean | No| No| Audio playback status on the current page. The value **true** means that audio is being played, and **false** means the opposite.|

## OnFirstContentfulPaintEvent<sup>12+</sup>

Represents the callback invoked when the first content paint occurs on the web page.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional| Description                                      |
| -------------- | ---- | ---- | ---- | ---------------------------------------- |
| navigationStartTick    | number | No| No| Navigation start time, in microseconds.         |
| firstContentfulPaintMs | number | No| No| Time between navigation and when the content is first rendered, in milliseconds.|

## OnLoadInterceptEvent<sup>12+</sup>

Represents the callback invoked when the **Web** component is about to access a URL.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional  | Description                                      |
| -------------- | ---- | ---- | ------------|---------------------------- |
| data | [WebResourceRequest](./ts-basic-components-web.md#webresourcerequest) | No| No| Information about the URL request.|

## OnOverScrollEvent<sup>12+</sup>

Represents the callback invoked when the web page is overscrolled.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional| Description                                      |
| -------------- | ---- | ---- | ---- | ---------------------------------------- |
| xOffset | number |  No  | No  | Horizontal overscroll offset based on the leftmost edge of the web page.<br>Unit: vp|
| yOffset | number |  No  | No  | Vertical overscroll offset based on the top edge of the web page.<br>Unit: vp|

## JavaScriptProxy<sup>12+</sup>

Defines the JavaScript object to be injected.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional  | Description                                      |
| -------------- | ---- | ---- | ------------|---------------------------- |
| object     | object                                   | No| No   | Object to be registered. Methods can be declared, but attributes cannot.                  |
| name       | string                                   | No| No   | Name of the object to be registered, which is the same as that invoked in the window.               |
| methodList | Array\<string\>                          | No| No   | Synchronous methods of the JavaScript object to be registered at the application side.                |
| controller | [WebController](./ts-basic-components-web.md#webcontroller) \| [WebviewController<sup>9+</sup>](./ts-basic-components-web.md#webviewcontroller9) | No| No | Controller. This API is deprecated since API version 9. You are advised to use **WebviewController** instead.|
| asyncMethodList<sup>12+</sup>  | Array\<string\>      | No| Yes   | Asynchronous methods of the JavaScript object to be registered at the application side. Asynchronous methods cannot obtain return values.  |
| permission<sup>12+</sup>  | string  | No| Yes   | JSON string, which is empty by default. This string is used to configure JSBridge permission control and define the URL trustlist at the object and method levels.<br>For the example, see [Invoking Application Functions on the Frontend Page](../../web/web-in-page-app-function-invoking.md).|

## OnPageEndEvent<sup>12+</sup>

Represents the callback invoked when the web page loading ends.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional  | Description                                      |
| -------------- | ---- | ---- | ------------|---------------------------- |
| url | string | No| No| URL of the page.                      |

## OnPageBeginEvent<sup>12+</sup>

Represents the callback invoked when the web page loading begins.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional  | Description                                      |
| -------------- | ---- | ---- | ------------|---------------------------- |
| url | string | No| No| URL of the page.                      |

## OnProgressChangeEvent<sup>12+</sup>

Represents the callback invoked when the web page loading progress changes.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional  | Description                                      |
| -------------- | ---- | ---- | ------------|---------------------------- |
| newProgress | number | No| No| New loading progress. The value is an integer ranging from 0 to 100.                      |

## OnTitleReceiveEvent<sup>12+</sup>

Represents the callback invoked when the document title of the web page is changed.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional   | Description                                      |
| -------------- | ---- | ---- | -------------|--------------------------- |
| title | string | No| No| Document title.<br>Default Value: **false**.                  |

## OnGeolocationShowEvent<sup>12+</sup>

Represents the callback invoked when a request to obtain the geolocation information is received.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Read-Only| Optional   | Description                                      |
| -------------- | ---- | ---- | -------------|--------------------------- |
| origin | string | No| No| Index of the origin.                      |
| geolocation | [JsGeolocation](./ts-basic-components-web.md#jsgeolocation) | No| No| User operation.                      |

## NativeEmbedVisibilityInfo<sup>12+</sup>

Provides visibility information about the same-layer tag.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Type                               | Read-Only| Optional| Description             |
| -------------  | ------------------------------------| ----- | ----- | ------------------ |
| visibility     | boolean                             | No   | No    | Whether the same-layer tag is visible.<br>The value **true** indicates that the same-layer tag is visible, and **false** indicates the opposite.        |
| embedId        | string                              | No   | No    | ID of the same-layer rendering tag. |

## RenderProcessNotRespondingData<sup>12+</sup>

Provides detailed information about the unresponsive rendering process.

**System capability**: SystemCapability.Web.Webview.Core

| Name                    | Type  | Mandatory| Description                                  |
| ------------------------ | ------ | ---- | -------------------------------------- |
| jsStack      | string | Yes | JavaScript call stack information of the web page.      |
| pid | number | Yes  | Process ID of the web page.|
| reason | [RenderProcessNotRespondingReason](./ts-basic-components-web-e.md#renderprocessnotrespondingreason12) | Yes  | The reason why the rendering process does not respond.|

## FullScreenEnterEvent<sup>12+</sup>

Provides details about the callback event for the **Web** component to enter the full-screen mode.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type                                 | Read-Only| Optional  | Description                   |
| -----------     | ------------------------------------ | ---- | ---- | --------------------- |
| handler     | [FullScreenExitHandler](./ts-basic-components-web.md#fullscreenexithandler9) | No| No | Function handle for exiting full screen mode.|
| videoWidth  | number | No| Yes| Video width, in px. If the element that enters fulls screen mode is a **\<video>** element, the value represents its width; if the element that enters fulls screen mode contains a **\<video>** element, the value represents the width of the first sub-video element; in other cases, the value is **0**.|
| videoHeight  | number | No| Yes | Video height, in px. If the element that enters fulls screen mode is a **\<video>** element, the value represents its height; if the element that enters fulls screen mode contains a **\<video>** element, the value represents the height of the first sub-video element; in other cases, the value is **0**.|

## LoadCommittedDetails<sup>11+</sup>

Provides detailed information about the web page that has been submitted for redirection.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type                                 | Read-Only| Optional  | Description                   |
| -----------     | ------------------------------------ | ---- | ------|-------------- |
| isMainFrame     | boolean                              | No| No   | Whether the document is the main document.<br>The value **true** indicates that the document is the main document, and **false** indicates the opposite.|
| isSameDocument  | boolean                              | No| No   | Whether to navigate without changing the document.<br>The value **true** means to navigate without changing the document, and **false** means the opposite.<br>Example of navigation in the same document: 1. navigation shown in the example; 2. navigation triggered by **pushState** or **replaceState**; 3. navigation to a history entry on the same page. |
| didReplaceEntry | boolean                              | No| No   | Whether the submitted new entry replaces the existing entry.<br>The value **true** indicates that the submitted new entry replaces the existing entry, and **false** indicates the opposite.<br>In certain scenarios for navigation to a subdocument, although the existing entry is not replaced, some attributes are changed. |
| navigationType  | [WebNavigationType](./ts-basic-components-web-e.md#webnavigationtype11)  | No| No   | Navigation type.      |
| url             | string                               | No| No   | URL of the current navigated-to web page.         |

## NativeEmbedInfo<sup>11+</sup>

Provides detailed information about the same-layer tag.

**System capability**: SystemCapability.Web.Webview.Core

| Name               | Type                                 | Read-Only| Optional| Description                       |
|-------------------| ------------------------------------ | ---- | ---- |---------------------------|
| id                | string             | No   | Yes    | ID of the same-layer tag.            |
| type              | string                              | No   | Yes    | Type of the same-layer tag. The value is in lowercase.  |
| src               | string                              | No   | Yes    | **src** information of the same-layer tag.           |
| width             | number  | No   | Yes    | Width of the same-layer tag, in px.         |
| height            | number                              | No   | Yes    | Height of the same-layer tag, in px.         |
| url               | string                              | No   | Yes    | URL of the same-layer tag.           |
| tag<sup>12+</sup> | string                              | No   | Yes    | Name of the tag, which consists of uppercase letters.             |
| params<sup>12+</sup>            | Map<string, string> | No   | Yes    | List of key-value pairs contained in the **object** tag that form a map of the Object type. Use the methods provided by the Object type, such as **embed.info?.param?.["name"]** to operate the map object. |
| position<sup>12+</sup>          | Position            | No   | Yes    | Position of the same-layer tag relative to the **Web** component in the screen coordinate system, which is different from the standard **Position**. The unit is px.|

## IntelligentTrackingPreventionDetails<sup>12+</sup>

Provides detailed information about intelligent tracking prevention.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Type                               | Read-Only | Optional | Description        |
| ------------- | ------------------------------------| ---- | ---- |------- |
| host          | string                              | No   | No  | Domain name.   |
| trackerHost   | string                              | No   | No  | Domain name of the tracker. |

## WebKeyboardCallbackInfo<sup>12+</sup>

Represents the input parameter of the callback for intercepting the soft keyboard from editable elements on a web page, including [WebKeyboardController](./ts-basic-components-web.md#webkeyboardcontroller12) and editable element attributes.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ------- | ---- | ---------------------------------------- |
| controller | [WebKeyboardController](./ts-basic-components-web.md#webkeyboardcontroller12)  | Yes   | Controller used to control the input, deletion, and closure of the custom keyboard.|
| attributes | Record<string, string> | Yes   | Attributes of the web page element that triggered the soft keyboard to pop up.

## WebKeyboardOptions<sup>12+</sup>

Represents the return value of the callback that intercepts the soft keyboard from editable elements on the web page. You can specify the type of the keyboard to be used, and it is returned to the Web kernel to display a keyboard of the corresponding type.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ------- | ---- | ---------------------------------------- |
| useSystemKeyboard | boolean  | Yes   | Whether to use the system's default soft keyboard.<br>The value **true** means to use the system's default soft keyboard, and **false** means the opposite.<br>Default value: **true**|
| enterKeyType | number | No   | Type of the Enter key of the system soft keyboard. For details about the value range, see [EnterKeyType](../apis-ime-kit/js-apis-inputmethod.md#enterkeytype10). This parameter has effect only when **useSystemKeyboard** is set to **true** and **enterKeyType** is set to a valid value.|
| customKeyboard | [CustomBuilder](../apis-arkui/arkui-ts/ts-types.md#custombuilder8) | No   | Builder of a custom keyboard. This parameter is required when **useSystemKeyboard** is set to **false**. After it is set, the **Web** component starts the custom keyboard as configured.


## FirstMeaningfulPaint<sup>12+</sup>

Provides detailed information about the first meaningful paint.

**System capability**: SystemCapability.Web.Webview.Core

| Name                    | Type  | Read-Only| Optional| Description                                  |
| ------------------------ | ------ | ---- | ---- | -------------------------------------- |
| navigationStartTime      | number | No  | Yes| Navigation bar loading time, in microseconds.      |
| firstMeaningfulPaintTime | number | No  | Yes| Time taken for the first meaningful paint of the page, in milliseconds.|

## LargestContentfulPaint<sup>12+</sup>

Provides detailed information about the largest content paint.

**System capability**: SystemCapability.Web.Webview.Core

| Name                     | Type  | Read-Only| Optional| Description                                    |
| ------------------------- | ------ | ---- | ---- | ---------------------------------------- |
| navigationStartTime       | number | No  | Yes| Navigation bar loading time, in microseconds.        |
| largestImagePaintTime     | number | No  | Yes| Maximum image loading time, in milliseconds.  |
| largestTextPaintTime      | number | No  | Yes| Maximum text loading time, in milliseconds.    |
| largestImageLoadStartTime | number | No  | Yes| Maximum time for an image to start loading, in milliseconds.|
| largestImageLoadEndTime   | number | No  | Yes| Maximum time for an image to finish loading, in milliseconds.|
| imageBPP                  | number | No  | Yes| Maximum number of image pixels.                          |

## NativeEmbedDataInfo<sup>11+</sup>

Provides detailed information about the lifecycle changes of the same-layer tag.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type                                 | Read-Only| Optional  | Description                   |
| -----------     | ------------------------------------ | ---- | ---- | --------------------- |
| status     | [NativeEmbedStatus](./ts-basic-components-web-e.md#nativeembedstatus11)             | No  | Yes| Lifecycle status of the same-layer tag.|
| surfaceId  | string                              | No  | Yes   | Surface ID of the native image. |
| embedId | string                              | No  | Yes   | Unique ID of the same-layer tag. |
| info  | [NativeEmbedInfo](./ts-basic-components-web-i.md#nativeembedinfo11)  | No  | Yes   | Detailed information about the same-layer tag.      |

## NativeEmbedTouchInfo<sup>11+</sup>

Provides touch information of the same-layer tag.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type                                 | Read-Only| Optional  | Description                   |
| -----------     | ------------------------------------  | ---- | ---- | --------------------- |
| embedId     | string   | No   | Yes| Unique ID of the same-layer tag.|
| touchEvent  | [TouchEvent](../apis-arkui/arkui-ts/ts-universal-events-touch.md#touchevent) | No   | Yes| Touch action information.|
| result<sup>12+</sup>     | [EventResult](./ts-basic-components-web.md#eventresult12)   | No   | Yes| Gesture event consumption result.|
