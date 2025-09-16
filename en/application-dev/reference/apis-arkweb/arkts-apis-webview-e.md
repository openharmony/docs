# Enums
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @yp99ustc; @aohui; @zourongchun-->
<!--Designer: @LongLie; @yaomingliu; @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## WebHitTestType

Enumerates the cursor node types for the [getLastHitTest](./arkts-apis-webview-WebviewController.md#getlasthittest18) API.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Value| Description                                     |
| ------------- | -- |----------------------------------------- |
| EditText      | 0 |Editable area.                           |
| Email         | 1 |Email address.                           |
| HttpAnchor    | 2 |Hyperlink, where **src** is **http**.                    |
| HttpAnchorImg | 3 |Image with a hyperlink, where **src** is http + HTML::img.|
| Img           | 4 |HTML::img tag.                          |
| Map           | 5 |Geographical address.                               |
| Phone         | 6 |Phone number.                               |
| Unknown       | 7 |Unknown content.                               |

## SecureDnsMode<sup>10+</sup>

Enumerates the modes in which the **Web** component uses HTTPDNS.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Value| Description                                     |
| ------------- | -- |----------------------------------------- |
| OFF                                  | 0 |HTTPDNS is not used. This value can be used to revoke the previously used HTTPDNS configuration.|
| AUTO                                 | 1 |HTTPDNS is used in automatic mode. If the specified HTTPDNS server is unavailable for resolution, the component falls back to the system DNS server.|
| SECURE_ONLY                          | 2 |The specified HTTPDNS server is forcibly used for DNS resolution.|

## SecurityLevel<sup>11+</sup>

Enumerates the security levels of the web page.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Value| Description                                     |
| ------------- | -- |----------------------------------------- |
| NONE          | 0 |The web page is neither absolutely secure nor insecure, that is, neutral. A typical example is a web page whose URL scheme is not HTTP or HTTPS.|
| SECURE        | 1 |The web page is secure, using the HTTPS protocol and a trusted certificate.|
| WARNING       | 2 |The web page is insecure. A typical example is a web page that uses the HTTP or HTTPS protocol but an outdated TLS version.|
| DANGEROUS     | 3 |The web page is dangerous. This means that the page may have attempted to load HTTPS scripts to no avail, have failed authentication, or contain insecure active content in HTTPS, malware, phishing, or any other sources of major threats.|

## MediaPlaybackState<sup>12+</sup>

Enumerates the playback states on the current web page.

**System capability**: SystemCapability.Web.Webview.Core

| Name   | Value  | Description              |
| ------- | ---- | ------------------ |
| NONE    | 0    | No audio or video playback is started on the page.|
| PLAYING | 1    | The audio and video on the page are being played.|
| PAUSED  | 2    | The audio and video on the page are paused.  |
| STOPPED | 3    | The audio and video on the page are stopped.  |

## PressureLevel<sup>14+</sup>

Enumerates the memory pressure levels. When an application clears the cache occupied by the **Web** component, the **Web** kernel releases the cache based on the memory pressure level.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Value| Description|
| ------------------------------- | - | ---------- |
| MEMORY_PRESSURE_LEVEL_MODERATE | 1 | Moderate memory pressure level. At this level, the **Web** kernel attempts to release the cache that has low reallocation overhead and does not need to be used immediately.|
| MEMORY_PRESSURE_LEVEL_CRITICAL | 2 | Critical memory pressure level. At this level, the **Web** kernel attempts to release all possible memory caches.|

## WebMessageType<sup>10+</sup>

Enumerates the data types supported by the [webMessagePort](./arkts-apis-webview-WebMessagePort.md) API.

**System capability**: SystemCapability.Web.Webview.Core

| Name        | Value| Description                           |
| ------------ | -- |------------------------------- |
| NOT_SUPPORT  | 0 |Unsupported data type.|
| STRING       | 1 |String type.|
| NUMBER       | 2 |Number type.|
| BOOLEAN      | 3 |Boolean type.|
| ARRAY_BUFFER | 4 |Raw binary data buffer.|
| ARRAY        | 5 |Array type.|
| ERROR        | 6 |Error object type.|

## JsMessageType<sup>10+</sup>

Enumerates the data types of the results returned after the [runJavaScriptExt](./arkts-apis-webview-WebviewController.md#runjavascriptext10) API is executed.

**System capability**: SystemCapability.Web.Webview.Core

| Name        | Value| Description                             |
| ------------ | -- |--------------------------------- |
| NOT_SUPPORT  | 0 |Unsupported data type.|
| STRING       | 1 |String type.|
| NUMBER       | 2 |Number type.|
| BOOLEAN      | 3 |Boolean type.|
| ARRAY_BUFFER | 4 |Raw binary data buffer.|
| ARRAY        | 5 |Array type.|

## RenderProcessMode<sup>12+</sup>

Enumerates the ArkWeb render subprocess modes.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Value| Description                                     |
| ------------- | -- |----------------------------------------- |
| SINGLE        | 0 |ArkWeb single render subprocess mode. In this mode, multiple **Web** components share one render subprocess.|
| MULTIPLE      | 1 |ArkWeb multi-render subprocess mode. In this mode, each **Web** component has a rendering subprocess.|

## OfflineResourceType<sup>12+</sup>

Enumerates the offline resource types corresponding to the [OfflineResourceMap](./arkts-apis-webview-i.md#offlineresourcemap12) object.

**System capability**: SystemCapability.Web.Webview.Core

| Name        | Value| Description                             |
| ------------ | -- |--------------------------------- |
| IMAGE  | 0 | Resource of the image type.|
| CSS       | 1 | Resource of the CSS type.|
| CLASSIC_JS       | 2 | Javascript resource loaded through the <script src="" /\> tag.|
| MODULE_JS      | 3 |Javascript resource loaded through the <script src="" type="module" /\> tag.|

## ScrollType<sup>12+</sup>

Enumerates the scroll types for [setScrollable](./arkts-apis-webview-WebviewController.md#setscrollable12).

**System capability**: SystemCapability.Web.Webview.Core

| Name        | Value| Description                             |
| ------------ | -- |--------------------------------- |
| EVENT  | 0 | Scrolling event, indicating that a web page is scrolled by using a touchscreen, a touchpad, or a mouse.|

## WebDownloadState<sup>11+</sup>

Enumerates the states of a download task.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Value| Description                                     |
| ------------- | -- |----------------------------------------- |
| IN_PROGRESS                                  | 0 |The download task is in progress.|
| COMPLETED                                 | 1 |The download task is completed.|
| CANCELED                          | 2 |The download task has been canceled.|
| INTERRUPTED                          | 3 |The download task is interrupted.|
| PENDING                          | 4 |The download task is pending.|
| PAUSED                          | 5 |The download task is paused.|
| UNKNOWN                          | 6 |The state of the download task is unknown.|

## WebDownloadErrorCode<sup>11+</sup>

Enumerates the download task error codes.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Value| Description                                     |
| ------------- | -- |----------------------------------------- |
| ERROR_UNKNOWN                                  | 0 |Unknown error.|
| FILE_FAILED | 1 |  Failed to operate the file.|
| FILE_ACCESS_DENIED | 2 | No permission to access the file.|
| FILE_NO_SPACE | 3 | The disk space is insufficient.|
| FILE_NAME_TOO_LONG | 5 | The file name is too long.|
| FILE_TOO_LARGE | 6 | The file is too large.|
| FILE_TRANSIENT_ERROR | 10 |  Some temporary issues occur, such as insufficient memory, files in use, and too many files open at the same time.|
| FILE_BLOCKED | 11 |  Access to the file is blocked due to certain local policies.|
| FILE_TOO_SHORT | 13 |  The file to resume downloading is not long enough. It may not exist.|
| FILE_HASH_MISMATCH | 14 |  Hash mismatch.|
| FILE_SAME_AS_SOURCE | 15 |  The file already exists.|
| NETWORK_FAILED | 20 |  Common network error.|
| NETWORK_TIMEOUT | 21 | Network connection timeout.|
| NETWORK_DISCONNECTED | 22 | Network disconnected.|
| NETWORK_SERVER_DOWN | 23 |  The server is shut down.|
| NETWORK_INVALID_REQUEST | 24 |  Invalid network request. The request may be redirected to an unsupported scheme or an invalid URL.|
| SERVER_FAILED | 30 | The server returns a general error.|
| SERVER_NO_RANGE | 31 |  The server does not support the range request.|
| SERVER_BAD_CONTENT | 33 |   The server does not have the requested data.|
| SERVER_UNAUTHORIZED | 34 |  The file cannot be downloaded from the server.|
| SERVER_CERT_PROBLEM | 35 |  The server certificate is incorrect.|
| SERVER_FORBIDDEN | 36 |  The access to the server is forbidden.|
| SERVER_UNREACHABLE | 37 |  The server cannot be accessed.|
| SERVER_CONTENT_LENGTH_MISMATCH | 38 |  The received data does not match the content length.|
| SERVER_CROSS_ORIGIN_REDIRECT | 39 | An unexpected cross-site redirection occurs.|
| USER_CANCELED | 40 | The user cancels the download.|
| USER_SHUTDOWN | 41 | The user closes the application.|
| CRASH | 50 | The application crashes.|

## WebResourceType<sup>12+</sup>

Enumerates the types of requested resources.

**System capability**: SystemCapability.Web.Webview.Core

| Name        | Value| Description                             |
| ------------ | -- |--------------------------------- |
| MAIN_FRAME | 0 | Top-level page.|
| SUB_FRAME | 1 | Frame or Iframe.|
| STYLE_SHEET | 2 | CSS style sheet.|
| SCRIPT | 3 | External script.|
| IMAGE | 4 | Image (JPG, GIF, PNG, or other format).|
| FONT_RESOURCE | 5 | Font.|
| SUB_RESOURCE | 6 | Other sub-resource. If the type is unknown, it is used as the default type.|
| OBJECT | 7 | Object (or embed) tag of the plug-in, or the resource requested by the plug-in.|
| MEDIA | 8 | Media resource.|
| WORKER | 9 | Main resource of a dedicated worker thread.|
| SHARED_WORKER | 10 | Main resource of a shared worker thread.|
| PREFETCH | 11 | Explicit prefetch request.|
| FAVICON | 12 | Website icon.|
| XHR | 13 | XMLHttpRequest.|
| PING | 14 | <a ping\>/sendBeacon ping request.|
| SERVICE_WORKER | 15 | Main resource of a service worker.|
| CSP_REPORT | 16 | Report of Content Security Policy violation.|
| PLUGIN_RESOURCE | 17 | Resource requested by the plug-in.|
| NAVIGATION_PRELOAD_MAIN_FRAME | 19 | Main frame redirection request that triggers service worker preloading.|
| NAVIGATION_PRELOAD_SUB_FRAME | 20 | Subframe redirection request that triggers service worker preloading.|

## PlaybackStatus<sup>12+</sup>

Enumerates the playback statuses of the player, which is an input parameter of the [handleStatusChanged](./arkts-apis-webview-NativeMediaPlayerHandler.md#handlestatuschanged12) API.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Value| Description|
|------|----|------|
| PAUSED  | 0 | Playing.|
| PLAYING | 1 | Paused.|

## NetworkState<sup>12+<sup>

Enumerates the network statuses of the player.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Value| Description|
|------|----|------|
| EMPTY         | 0 | The player has not started downloading data.|
| IDLE          | 1 | The player's network activity is idle. This could mean that the download of a media segment is complete, and the player is waiting to start downloading the next segment.|
| LOADING       | 2 | The player is downloading media data.|
| NETWORK_ERROR | 3 | A network error occurs.|

## ReadyState<sup>12+<sup>

Enumerates the cache states of the player.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Value| Description|
|------|----|------|
| HAVE_NOTHING      | 0 | There is no data cached.|
| HAVE_METADATA     | 1 | Only media metadata is cached.|
| HAVE_CURRENT_DATA | 2 | Data up to the current playback position is cached.|
| HAVE_FUTURE_DATA  | 3 | Data beyond the current playback position is cached, but there might still be stutters during playback.|
| HAVE_ENOUGH_DATA  | 4 | Sufficient data has been cached to ensure smooth playback.|

## MediaError<sup>12+<sup>

Enumerates the error types of the player.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Value| Description|
|------|----|------|
| NETWORK_ERROR | 1 | Network error.|
| FORMAT_ERROR  | 2 | Media format error.|
| DECODE_ERROR  | 3 | Decoding error.|

## SuspendType<sup>12+<sup>

Enumerates the suspension types of the player.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Value| Description|
|------|----|------|
| ENTER_BACK_FORWARD_CACHE | 0 | The page enters the BFCache.|
| ENTER_BACKGROUND         | 1 | The page is displayed in the background.|
| AUTO_CLEANUP             | 2 | The page is automatically cleaned up by the system.|

## MediaType<sup>12+<sup>

Enumerates the media types.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Value| Description|
|------|----|------|
| VIDEO | 0 | Video.|
| AUDIO | 1 | Audio.|

## SourceType<sup>12+<sup>

Enumerates the media source types.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Value| Description|
|------|----|------|
| URL | 0 | URL.|
| MSE | 1 | Blob.|

## Preload<sup>12+<sup>

Enumerates how the player preloads media data.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Value| Description|
|------|----|------|
| NONE     | 0 | No media data is preloaded.|
| METADATA | 1 | Only the metadata of the media is preloaded.|
| AUTO     | 2 | A sufficient amount of media data is preloaded to ensure smooth playback|

## ProxySchemeFilter<sup>15+</sup>

Enumerates the schemes that use the proxy.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Value| Description                                     |
| ------------- | -- |----------------------------------------- |
| MATCH_ALL_SCHEMES | 0 |All schemes use proxies.|
| MATCH_HTTP        | 1 |HTTP requests use proxies.|
| MATCH_HTTPS       | 2 |HTTPS requests use proxies.|

## WebDestroyMode<sup>20+</sup>

Enumerates the destroy modes of the **Web** component. When the Web component is destroyed, the destroy mode affects the resource release time of the Web kernel, such as the JavaScript running context and rendering context.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Value| Description|
| ------------------------------- | - | ---------- |
| NORMAL_MODE | 0 | Normal mode. The system determines the destroy time of **Web** component resources.|
| FAST_MODE   | 1 | Quick mode. When the **Web** component is destroyed, the related internal resources are destroyed immediately.|

## WebBlanklessErrorCode<sup>20+</sup>

Enumerates the error codes of the blankless loading.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Value| Description|
| ------------------------------- | - | ---------- |
| SUCCESS | 0 | Operation successful.|
| ERR_UNKNOWN   | -1 | Unknown error or internal status error.|
| ERR_INVALID_PARAM   | -2 | Invalid parameter.|
| ERR_CONTROLLER_NOT_INITED   | -3 | **WebViewController** is not bound to any component.|
| ERR_KEY_NOT_MATCH   | -4 | No key value is matched. [setBlanklessLoadingWithKey](./arkts-apis-webview-WebviewController.md#setblanklessloadingwithkey20) must be used with [getBlanklessInfoWithKey](./arkts-apis-webview-WebviewController.md#getblanklessinfowithkey20) and their key values must be the same. Otherwise, this error code is returned.|
| ERR_SIGNIFICANT_CHANGE   | -5 | The similarity is low, and the system determines that the scene change is too large. As a result, the [setBlanklessLoadingWithKey](./arkts-apis-webview-WebviewController.md#setblanklessloadingwithkey20) API does not enable frame interpolation.|

## ArkWebEngineVersion<sup>20+</sup>

For details about the ArkWeb kernel version, see [Adaptation Guide for the M114 Kernel on OpenHarmony 6.0](https://gitcode.com/openharmony-tpc/chromium_src/blob/132_trunk/web/ReleaseNote/CompatibleWithLegacyWebEngine.md).

| **Kernel Type**| **Name**| **Description**|
| ----------- | -------- | -------- |
| Evergreen kernel    | EVERGREEN WebCore | Latest Web kernel of the system, based on which the complete functionalities are implemented. This kernel is recommended for applications.|
| Legacy kernel    | LEGACY WebCore    | A previous-release kernel that receives only security and PR-related fixes, used solely for compatibility rollback, and is supported for a fixed duration only.|

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Value| Description                                     |
| ------------- | -- |----------------------------------------- |
| SYSTEM_DEFAULT   | 0     | Default system kernel. For OpenHarmony 6.0, the default kernel is M132.|
| M114             | 1     | Legacy kernel of OpenHarmony 6.0. You can select this legacy kernel. If it does not exist, the setting is invalid.|
| M132             | 2     | Evergreen kernel of OpenHarmony 6.0, which is M132 by default. If it does not exist, the setting is invalid.|
## SiteIsolationMode<sup>21+</sup>

Enumerates the site isolation modes. The site isolation mechanism isolates websites from different sources in different render processes to reduce the cross-domain attack surface. For example, on a PC, each tab corresponds to a render process. After site isolation is enabled, Iframes from different sources run in independent render processes.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Value| Description|
| ------------------------------- | - | ---------- |
| PARTIAL | 0 | Partial site isolation. New sites are loaded in the same render process.|
| STRICT  | 1 | Strict site isolation. Iframes from different sites are switched to new render processes.|
