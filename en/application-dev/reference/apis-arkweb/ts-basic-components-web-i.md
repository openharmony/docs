# Interfaces (Others)

> **NOTE**
>
> - The initial APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## WebMediaOptions<sup>10+</sup>

Describes the web-based media playback policy.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ------- | ---- | ---------------------------------------- |
| resumeInterval | number  | No   | Validity period for automatically resuming a web audio paused by another application, in seconds. The value range is [-2147483648, 2147483647]. If **resumeInterval** is set to **0**, the playback is not automatically resumed. If **resumeInterval** is set to a value greater than 0, the playback is resumed in the specified period. If **resumeInterval** is set to a value less than 0, the playback is resumed in an unlimited period. Due to the approximate value, the validity period may have a deviation of less than 1 second.|
| audioExclusive | boolean | No   | Whether the audio of multiple **Web** instances in an application is exclusive.<br>The value **true** indicates that the audio of multiple **Web** instances in an application is exclusive, and **false** indicates the opposite.                      |

## ScriptItem<sup>11+</sup>

Describes the **ScriptItem** object injected to the **Web** component through the [javaScriptOnDocumentStart](./ts-basic-components-web-attributes.md#javascriptondocumentstart11) attribute.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Type            | Mandatory  | Description                   |
| ----------- | -------------- | ---- | --------------------- |
| script      | string         | Yes   | JavaScript script to be injected and executed.|
| scriptRules | Array\<string> | Yes  | Matching rules for allowed sources.<br>1. To allow URLs from all sources, use the wildcard (\*).<br>2. If exact match is required, specify the exact URL, for example, **https:\//www\\.example.com**.<br>3. For fuzzy match, you can use a wildcard (\*) in the website URL, for example, **https://\*.example.com**. The following are not allowed: "x. * .y.com", " * foobar.com".<br>4. If the source is an IP address, follow rule 2.<br>5. For protocols other than HTTP/HTTPS (custom protocols), exact match and fuzzy match are not supported, and the protocol must end with "://", for example, **resource://**.<br>6. If one of the preceding rules is not met in **scriptRules**, the **scriptRules** does not take effect.|

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

Represents the configuration for [enabling the application to take over web page media playback](./ts-basic-components-web-attributes.md#enablenativemediaplayer12).

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Mandatory| Description|
|------|------|------|------|
|  enable  | boolean | Yes| Whether to enable the application to take over web page media playback.<br> The value **true** means to enable the application to take over web page media playback, and **false** means the opposite.<br> The default value is **false**.|
|  shouldOverlay | boolean | Yes| Whether the video player's display overlays the web page content when the application takes over the web page's video player.<br> The value **true** indicates that the video player's display overlays the web page content. This means that the height of the video layer is adjusted to cover the web page content. **false** indicates that the video player's display does not overlay the web page content. This means that the video player maintains its original height and is embedded within the web page.<br>The default value is **false**.|

## ExpandedMenuItemOptions<sup>12+</sup>

Defines the custom expanded menu options.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Type                                            | Mandatory   | Description            |
| ---------- | -----------------------------------------------------| ------ | ---------------- |
| content   | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr)  | Yes    | Content to display.    |
| startIcon | [ResourceStr](../apis-arkui/arkui-ts/ts-types.md#resourcestr)  | No    | Icon to display.    |
| action    | (selectedText: {plainText: string}) => void                    | Yes    | Selected text.|

## AdsBlockedDetails<sup>12+</sup>

Provides detailed information about the blocked ads when ads are blocked.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type                                                                          | Mandatory  | Description                   |
| ------- | --------------------------------------------------------------------------------  | ---- | ------------------------- |
| url | string  | Yes   | URL of the page where ads are blocked.|
| adsBlocked | Array\<string\>  | Yes   | URLs or DOMPath of the blocked ads. If ads have the same URLs, duplicate elements may exist.|

## SelectionMenuOptionsExt<sup>13+</sup>

Defines the custom expanded menu options.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Type                                            | Mandatory   | Description            |
| ---------- | -----------------------------------------------------| ------ | ---------------- |
| onAppear   | Callback\<void\>   | No    | Callback invoked when the custom context menu on selection appears.    |
| onDisappear | Callback\<void\>  | No    | Callback invoked when the custom context menu on selection disappears.    |
| preview    | [CustomBuilder](../apis-arkui/arkui-ts/ts-types.md#custombuilder8)          | No    | Preview content style of the custom selection menu. If this parameter is not set, there is no preview content.|
| menuType   | [MenuType](../apis-arkui/arkui-ts/ts-text-common.md#menutype13)     | No    | Type of the custom context menu on selection.<br>Default value: **MenuType.SELECTION_MENU**<br> Since API version 20, **MenuType.PREVIEW_MENU** supports hyperlink preview.    |

## EmbedOptions<sup>16+</sup>

Represents the same-layer rendering configuration of the **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ------- | ---- | ---------------------------------------- |
| supportDefaultIntrinsicSize | boolean | No   | Whether a same-layer rendering element supports the fixed size of 300 × 150.<br>When the size of an element is set using CSS on the HTML5 side, the size of the same-layer rendering element uses the CSS size. Otherwise, the size is fixed.<br>If the value is **true**, the fixed size is 300 × 150.<br>If the value is **false** and the CSS size is not set on the HTML5 side, the same-layer rendering elements are not rendered.<br>Default Value: **false**.<br>Unit: px|

## OnAlertEvent<sup>12+</sup>

Represents the callback invoked when **alert()** is invoked to display an alert dialog box on the web page.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | Yes| URL of the web page where the dialog box is displayed.                      |
| message | string | Yes| Message displayed in the dialog box.                      |
| result | [JsResult](./ts-basic-components-web.md#jsresult) | Yes| User operation.                      |

## OnBeforeUnloadEvent<sup>12+</sup>

Represents the callback invoked when this page is about to exit after the user refreshes or closes the page.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | Yes| URL of the web page where the dialog box is displayed.                      |
| message | string | Yes| Message displayed in the dialog box.                      |
| result | [JsResult](./ts-basic-components-web.md#jsresult) | Yes| User operation.                      |

## OnConfirmEvent<sup>12+</sup>

Represents the callback invoked when **confirm()** is invoked by the web page.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | Yes| URL of the web page where the dialog box is displayed.                      |
| message | string | Yes| Message displayed in the dialog box.                      |
| result | [JsResult](./ts-basic-components-web.md#jsresult) | Yes| User operation.                      |

## OnPromptEvent<sup>12+</sup>

Represents the callback invoked when **prompt()** is invoked by the web page.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| url | string | Yes| URL of the web page where the dialog box is displayed.                      |
| message | string | Yes| Message displayed in the dialog box.                      |
| value | string | Yes| Information in the dialog box.                      |
| result | [JsResult](./ts-basic-components-web.md#jsresult) | Yes| User operation.                      |

## OnConsoleEvent<sup>12+</sup>

Represents the callback invoked to notify the host application of a JavaScript console message.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| message | [ConsoleMessage](./ts-basic-components-web.md#consolemessage) | Yes| Console message.                      |

## OnErrorReceiveEvent<sup>12+</sup>

Represents the callback invoked when an error occurs during web page loading.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| request | [WebResourceRequest](./ts-basic-components-web.md#webresourcerequest) | Yes| Encapsulation of a web page request.     |
| error   | [WebResourceError](./ts-basic-components-web.md#webresourceerror)    | Yes| Encapsulation of a web page resource loading error.|

## OnHttpErrorReceiveEvent<sup>12+</sup>

Represents the callback invoked when an HTTP error occurs during web page resource loading.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| request | [WebResourceRequest](./ts-basic-components-web.md#webresourcerequest) | Yes| Encapsulation of a web page request.     |
| response   | [WebResourceResponse](./ts-basic-components-web.md#webresourceresponse)    | Yes| Encapsulation of a resource response.|

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
| isRefreshed | boolean | Yes| Whether the page is reloaded. The value **true** means that the page is reloaded by invoking the [refresh<sup>9+</sup>](./js-apis-webview-WebviewController.md#refresh) API, and **false** means the opposite.|

## OnRenderExitedEvent<sup>12+</sup>

Represents the callback invoked when the rendering process exits.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| renderExitReason | [RenderExitReason](./ts-basic-components-web-e.md#renderexitreason9) | Yes| Cause for the abnormal exit of the rendering process.|

## OnShowFileSelectorEvent<sup>12+</sup>

Represents the callback invoked to notify the file selector result.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| result       | [FileSelectorResult](./ts-basic-components-web.md#fileselectorresult9) | Yes| File selection result to be sent to the **Web** component.|
| fileSelector | [FileSelectorParam](./ts-basic-components-web.md#fileselectorparam9) | Yes| Information about the file selector.      |

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
| oldScale | number | Yes| Display ratio of the page before the change.|
| newScale | number | Yes| Display ratio of the page after the change.|

## OnHttpAuthRequestEvent<sup>12+</sup>

Represents the callback invoked when an HTTP authentication request is received.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler | [HttpAuthHandler](./ts-basic-components-web.md#httpauthhandler9) | Yes| User operation.  |
| host    | string                               | Yes| Host to which HTTP authentication credentials apply.|
| realm   | string                               | Yes| Realm to which HTTP authentication credentials apply. |

## OnInterceptRequestEvent<sup>12+</sup>

Represents the callback invoked when the **Web** component is about to load a URL.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| request | [WebResourceRequest](./ts-basic-components-web.md#webresourcerequest) | Yes| Information about the URL request.|

## OnPermissionRequestEvent<sup>12+</sup>

Represents the callback invoked when a permission request is received.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| request | [PermissionRequest](./ts-basic-components-web.md#permissionrequest9) | Yes| User operation.|

## OnScreenCaptureRequestEvent<sup>12+</sup>

Represents the callback invoked when a screen capture request is received.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler | [ScreenCaptureHandler](./ts-basic-components-web.md#screencapturehandler10) | Yes| User operation.|

## OnContextMenuShowEvent<sup>12+</sup>

Represents the callback invoked during a call to allow for the display of a custom context menu.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| param  | [WebContextMenuParam](./ts-basic-components-web.md#webcontextmenuparam9) | Yes| Parameters related to the context menu.    |
| result | [WebContextMenuResult](./ts-basic-components-web.md#webcontextmenuresult9) | Yes| Result of the context menu.|

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
| xOffset | number | Yes| Position of the scrollbar on the x-axis relative to the leftmost of the web page.<br>Unit: vp|
| yOffset | number | Yes| Position of the scrollbar on the y-axis relative to the top of the web page.<br>Unit: vp|

## OnSslErrorEventReceiveEvent<sup>12+</sup>

Represents the callback invoked when the web page receives an SSL error.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler | [SslErrorHandler](./ts-basic-components-web.md#sslerrorhandler9) | Yes| User operation.|
| error   | [SslError](./ts-basic-components-web-e.md#sslerror9)           | Yes| Error code.          |
| certChainData<sup>15+</sup>   | Array<Uint8Array\>           | No| Certificate chain data.          |

## SslErrorEvent<sup>12+</sup>

Provides details about the callback invoked when an SSL error occurs during resource loading.

**System capability**: SystemCapability.Web.Webview.Core

| Name    | Type                                | Mandatory  | Description          |
| ------- | ------------------------------------ | ---- | -------------- |
| handler | [SslErrorHandler](./ts-basic-components-web.md#sslerrorhandler9) | Yes   | User operation.|
| error   | [SslError](./ts-basic-components-web-e.md#sslerror9)        | Yes   | Error code.          |
| url   | string                                 | Yes   | URL.          |
| originalUrl   | string                         | Yes   | Original URL of the request.          |
| referrer   | string                            | Yes   | Referrer URL.          |
| isFatalError   | boolean                       | Yes   | Whether the error is a fatal error.<br>The value **true** indicates a fatal error, and **false** indicates a non-fatal error.          |
| isMainFrame   | boolean                        | Yes   | Whether the resource is a main resource.<br>The value **true** indicates a main resource, and **false** indicates a non-main resource.          |

## OnClientAuthenticationEvent<sup>12+</sup>

Represents the callback invoked when an SSL client certificate is required from the user.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| handler  | [ClientAuthenticationHandler](./ts-basic-components-web.md#clientauthenticationhandler9) | Yes| User operation. |
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
| handler       | [ControllerHandler](./ts-basic-components-web.md#controllerhandler9) | Yes| **WebviewController** instance for setting the new window.|

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
| favicon | [PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | Yes| **PixelMap** object of the received favicon.|

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
| handler | [DataResubmissionHandler](./ts-basic-components-web.md#dataresubmissionhandler9) | Yes| Handler for resubmitting web form data.|

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
| data | [WebResourceRequest](./ts-basic-components-web.md#webresourcerequest) | Yes| Information about the URL request.|

## OnOverScrollEvent<sup>12+</sup>

Represents the callback invoked when the web page is overscrolled.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| xOffset | number | Yes| Horizontal overscroll offset based on the leftmost edge of the web page.<br>Unit: vp|
| yOffset | number | Yes| Vertical overscroll offset based on the top edge of the web page.<br>Unit: vp|

## JavaScriptProxy<sup>12+</sup>

Defines the JavaScript object to be injected.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| object     | object                                   | Yes   | Object to be registered. Methods can be declared, but attributes cannot.                  |
| name       | string                                   | Yes   | Name of the object to be registered, which is the same as that invoked in the window.               |
| methodList | Array\<string\>                          | Yes   | Synchronous methods of the JavaScript object to be registered at the application side.                |
| controller | [WebController](./ts-basic-components-web.md#webcontroller) \| [WebviewController<sup>9+</sup>](./ts-basic-components-web.md#webviewcontroller9) | Yes   | -    | Controller. This API is deprecated since API version 9. You are advised to use **WebviewController** instead.|
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

## OnGeolocationShowEvent<sup>12+</sup>

Represents the callback invoked when a request to obtain the geolocation information is received.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| origin | string | Yes| Index of the origin.                      |
| geolocation | [JsGeolocation](./ts-basic-components-web.md#jsgeolocation) | Yes| User operation.                      |

## NativeEmbedVisibilityInfo<sup>12+</sup>

Provides visibility information about the same-layer tag.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Type                               | Mandatory  | Description             |
| -------------  | ------------------------------------| ----- | ------------------ |
| visibility     | boolean                             | Yes    | Whether the same-layer tag is visible.<br>The value **true** indicates that the same-layer tag is visible, and **false** indicates the opposite.        |
| embedId        | string                              | Yes    | ID of the same-layer rendering tag. |

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

| Name            | Type                                 | Mandatory  | Description                   |
| -----------     | ------------------------------------ | ---- | --------------------- |
| handler     | [FullScreenExitHandler](./ts-basic-components-web.md#fullscreenexithandler9) | Yes   | Function handle for exiting full screen mode.|
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
| navigationType  | [WebNavigationType](./ts-basic-components-web-e.md#webnavigationtype11)  | Yes   | Navigation type.      |
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
| tag<sup>12+</sup> | string              | No   | Name of the tag, which consists of uppercase letters.             |
| params<sup>12+</sup>            | Map<string, string> | No   | List of key-value pairs contained in the **object** tag that form a map of the Object type. Use the methods provided by the Object type, such as **embed.info?.param?.["name"]** to operate the map object. |
| position<sup>12+</sup>          | Position            | No   | Position of the same-layer tag relative to the **Web** component in the screen coordinate system, which is different from the standard **Position**. The unit is px.|

## IntelligentTrackingPreventionDetails<sup>12+</sup>

Provides detailed information about intelligent tracking prevention.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Type                               | Mandatory  | Description        |
| ------------- | ------------------------------------| ----- | ------------ |
| host          | string                              | Yes    | Domain name.   |
| trackerHost   | string                              | Yes    | Domain name of the tracker. |

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

| Name                    | Type  | Mandatory| Description                                  |
| ------------------------ | ------ | ---- | -------------------------------------- |
| navigationStartTime      | number | No | Navigation bar loading time, in microseconds.      |
| firstMeaningfulPaintTime | number | No  | Time taken for the first meaningful paint of the page, in milliseconds.|

## LargestContentfulPaint<sup>12+</sup>

Provides detailed information about the largest content paint.

**System capability**: SystemCapability.Web.Webview.Core

| Name                     | Type  | Mandatory| Description                                    |
| ------------------------- | ------ | ---- | ---------------------------------------- |
| navigationStartTime       | number | No  | Navigation bar loading time, in microseconds.        |
| largestImagePaintTime     | number | No  | Maximum image loading time, in milliseconds.  |
| largestTextPaintTime      | number | No  | Maximum text loading time, in milliseconds.    |
| largestImageLoadStartTime | number | No  | Maximum time for an image to start loading, in milliseconds.|
| largestImageLoadEndTime   | number | No  | Maximum time for an image to finish loading, in milliseconds.|
| imageBPP                  | number | No  | Maximum number of image pixels.                          |

## NativeEmbedDataInfo<sup>11+</sup>

Provides detailed information about the lifecycle changes of the same-layer tag.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type                                 | Mandatory  | Description                   |
| -----------     | ------------------------------------ | ---- | --------------------- |
| status     | [NativeEmbedStatus](./ts-basic-components-web-e.md#nativeembedstatus11)             | No   | Lifecycle status of the same-layer tag.|
| surfaceId  | string                              | No   | Surface ID of the native image. |
| embedId | string                              | No   | Unique ID of the same-layer tag. |
| info  | [NativeEmbedInfo](./ts-basic-components-web-i.md#nativeembedinfo11)  | No   | Detailed information about the same-layer tag.      |

## NativeEmbedTouchInfo<sup>11+</sup>

Provides touch information of the same-layer tag.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Type                                 | Mandatory  | Description                   |
| -----------     | ------------------------------------ | ---- | --------------------- |
| embedId     | string   | No   | Unique ID of the same-layer tag.|
| touchEvent  | [TouchEvent](../apis-arkui/arkui-ts/ts-universal-events-touch.md#touchevent) | No   | Touch action information.|
| result<sup>12+</sup>     | [EventResult](./ts-basic-components-web.md#eventresult12)   | No   | Gesture event consumption result.|
