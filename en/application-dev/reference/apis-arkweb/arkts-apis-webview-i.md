# Interfaces (Others)

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## WebStorageOrigin

Provides usage information of the Web SQL Database.

**System capability**: SystemCapability.Web.Webview.Core

| Name  | Type  | Read-Only| Optional| Description|
| ------ | ------ | ---- | ---- | ---- |
| origin | string | No | No| Index of the origin.|
| usage  | number | No | No| Storage usage of the origin.    |
| quota  | number | No | No| Storage quota of the origin.  |

## WebHeader

Describes the request/response header returned by the **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

| Name       | Type  | Read-Only| Optional|Description                |
| ----------- | ------ | -----|------|------------------- |
| headerKey   | string | No| No| Key of the request/response header.  |
| headerValue | string | No| No| Value of the request/response header.|

## WebCustomScheme

Defines a custom URL scheme.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Type      | Read-Only| Optional| Description                        |
| -------------- | --------- | ---- | ---- | ---------------------------- |
| schemeName     | string    | No  | No  | Name of the custom URL scheme. The value can contain a maximum of 32 characters, including lowercase letters, digits, periods (.), plus signs (+), and hyphens (-), and must start with a letter.       |
| isSupportCORS  | boolean   | No  | No  | Whether to support cross-origin resource sharing (CORS).<br>The value **true** means to support cross-origin resource sharing (CORS), and **false** means the opposite.<br>Default value: **true**.   |
| isSupportFetch | boolean   | No  | No  | Whether to support fetch requests.<br>The value **true** means to support fetch requests, and **false** means the opposite.<br>Default value: **true**.          |
| isStandard<sup>12+</sup> | boolean   | No  | Yes  | Whether the scheme is processed as a standard scheme. The standard scheme must comply with the URL normalization and parsing rules defined in section 3.1 of RFC 1738.<br>The value **true** indicates that the scheme is processed as a standard scheme, and **false** indicates the opposite.<br>Default value: **true**.          |
| isLocal<sup>12+</sup> | boolean   | No  | Yes  | Whether the scheme is treated with the same security rules as those applied to file URLs.<br>The value **true** indicates that the scheme is treated with the same security rules as those applied to file URLs, and the value **false** indicates the opposite.<br>Default value: **true**.          |
| isDisplayIsolated<sup>12+</sup> | boolean   | No  | Yes  | Whether the content of the scheme can be displayed or accessed from other content that uses the same scheme.<br>The value **true** indicates that the content of the scheme can only be displayed or accessed from other content that uses the same scheme, and **false** indicates the opposite.<br>Default value: **true**.          |
| isSecure<sup>12+</sup> | boolean   | No  | Yes  | Whether the scheme is treated with the same security rules as those applied to HTTPS URLs. The value **true** indicates that the scheme is treated with the same security rules as those applied to HTTPS URLs, and **false** indicates the opposite.<br>Default value: **true**.          |
| isCspBypassing<sup>12+</sup> | boolean   | No  | Yes  | Whether the scheme can bypass the content security policy (CSP) checks.<br>The value **true** indicates that the scheme can bypass the content security policy (CSP) checks, and **false** indicates the opposite.<br>Default value: **true**.<br>In most cases, this value should not be set when **isStandard** is set to **true**.        |
| isCodeCacheSupported<sup>12+</sup> | boolean   | No  | Yes  | Whether JavaScript resources loaded with the scheme can be used to create a code cache.<br>The value **true** indicates that JavaScript resources loaded with the scheme can be used to create a code cache, and **false** indicates the opposite.<br>Default value: **false**.        |

## RequestInfo<sup>12+</sup>

Describes the information about the resource request sent by the **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

| Name     | Type  | Read-Only| Optional|Description       |
| ---------| ------ | -----|------|--------  |
| url      | string | No| No| URL of the request.   |
| method   | string | No| No| Method of the request.   |
| formData | string | No| No| Form data in the request body.|

## CacheOptions<sup>12+</sup>

Represents a configuration object for precompiling JavaScript in the **Web** component to generate bytecode cache, which is designed to control the updating of the bytecode cache.

**System capability**: SystemCapability.Web.Webview.Core

| Name       | Type  | Read-Only| Optional|Description                |
| ----------- | ------ | -----|------|------------------- |
| responseHeaders   | Array<[WebHeader](#webheader)> | No| No| Array of response headers from the server when a JavaScript file is requested. They include information such as E-Tag or Last-Modified to identify the file version and determine whether the bytecode cache needs to be refreshed.  |

## SnapshotInfo<sup>12+</sup>

Provides information used to obtain a full drawing result.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type|  Mandatory| Description|
|------|------|------|------|
| id | string | No| Snapshot ID.|
| size | [SizeOptions](../apis-arkui/arkui-ts/ts-types.md#sizeoptions)  | No| Size for web rendering. The maximum size is 16000 px × 16000 px. The length unit can be px, vp, or %. The length unit must be the consistent across parameters. The default unit is vp. If the size exceeds the specifications, the maximum size is returned. Example: **width: '100px', height: '200px'** or **width: '20%', height'30%'**. If only digits are written, the unit is vp.|

## SnapshotResult<sup>12+</sup>

Represents a full drawing result.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Mandatory|  Description|
|------|------|--|---------|
| id | string | No| Snapshot ID.|
| status | boolean | No|  Snapshot status. The value can be **true** (normal) or **false** (failure). If the full drawing result fails to be obtained, the width and height of the returned size are both 0, and the map is empty.|
| size | [SizeOptions](../apis-arkui/arkui-ts/ts-types.md#sizeoptions)   | No| Actual size drawn on the web page. The value is of the number type, and the unit is vp.|
| imagePixelMap | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | No| Full drawing result in image.pixelMap format.|

## OfflineResourceMap<sup>12+</sup>

Implements an **OfflineResourceMap** object, which is used to set information related to local offline resources that will be injected into memory cache through the [injectOfflineResources](./arkts-apis-webview-WebviewController.md#injectofflineresources12) API. The ArkWeb engine will generate resource caches based on this information and control the validity period of the cache accordingly.

**System capability**: SystemCapability.Web.Webview.Core

| Name       | Type  | Read-Only| Optional|Description                |
| ----------- | ------ | -----|------|------------------- |
| urlList | Array\<string\> | No  | No  | List of network addresses of the local offline resources. The first item in the list is used as the resources' origin. If only one network address is provided, this single address is used for the resources' origin. The URL supports only the HTTP and HTTPS protocols and contains a maximum of 2048 characters.     |
| resource | Uint8Array | No  | No  | Content of a local offline resource.     |
| responseHeaders | Array<[WebHeader](#webheader)> | No  | No  | HTTP response headers corresponding to the resources. The **Cache-Control** or **Expires** response header is used to control the validity period of the resource in the memory cache. If neither of the headers is provided, a default validity time of 86400 seconds (1 day) will be applied. The **Content-Type** response header is used to define the MIME type of the resource. For resources of type MODULE_JS, a valid MIME type must be provided. For other types, the MIME type is optional, with no default value. A non-standard MIME type can lead to the resource being invalidated in the memory cache. If a **script** tag on the web page uses the **crossorigin** attribute, the **Cross-Origin** response header must be set in the **responseHeaders** parameter of the API. The value for this header should be **anonymous** or **use-credentials**.     |
| type | [OfflineResourceType](./arkts-apis-webview-e.md#offlineresourcetype12) | No  | No  | Resource type. Currently, only the JavaScript, image, and CSS types are supported.     |

##  PdfConfiguration<sup>14+</sup>

Specifies the input parameters of **createPdf()**.

> **NOTE**
>
> The number of pixels is calculated as follows: Number of pixels = 96 x Number of inches.

**System capability**: SystemCapability.Web.Webview.Core

| Name                 | Type   | Mandatory| Description                                                        |
| --------------------- | ------- | ---- | ------------------------------------------------------------ |
| width                 | number  | Yes  | Page width,<br>in inches.<br>Recommended value: 8.27 inches of A4 paper width.  |
| height                | number  | Yes  | Page height,<br>in inches.<br>Recommended value: 11.69 inches of A4 paper height. |
| scale                 | number  | No  | Scale multiple.<br>The value range is [0.0, 2.0]. If the value is less than 0.0, set it to **0.0**. If the value is greater than 2.0, set it to **2.0**.<br>Default value: **1.0**|
| marginTop             | number  | Yes  | Top margin.<br>The value range is [0.0, half of the page height). If the value is not within the value range, set it to **0.0**.<br>Unit: inch.|
| marginBottom          | number  | Yes  | Bottom margin.<br>The value range is [0.0, half of the page height). If the value is not within the value range, set it to **0.0**.<br>Unit: inch.|
| marginRight           | number  | Yes  | Right margin.<br>The value range is [0.0, half of the page width). If the value is not within the value range, set it to **0.0**.<br>Unit: inch.|
| marginLeft            | number  | Yes  | Left margin.<br>The value range is [0.0, half of the page width). If the value is not within the value range, set it to **0.0**.<br>Unit: inch.|
| shouldPrintBackground | boolean | No  | Whether to print the background color. The value **true** means to print the background color, and **false** means the opposite.<br>Default value: **false**.                           |

## ScrollOffset<sup>13+</sup>

Represents the current scrolling offset of a web page.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type  | Read-Only| Optional| Description                                                        |
| ---- | ------ | ---- | ---- | ------------------------------------------------------------ |
| x    | number | No  | No  | Horizontal scrolling offset of a web page. The value is the difference between the x-coordinate of the left boundary of the web page and that of the left boundary of the **Web** component.<br>When the web page is scrolled rightwards, the value is negative.<br>When the web page is not scrolled or scrolled leftwards, the value is **0** or positive.<br>Unit: vp|
| y    | number | No  | No  | Vertical scrolling offset of a web page. The value is the difference between the y-coordinate of the upper boundary of the web page and that of the upper boundary of the **Web** component.<br>When the web page is scrolled downwards, the value is negative.<br>When the web page is not scrolled or scrolled upwards, the value is **0** or positive.<br>Unit: vp|

## HitTestValue

Provides the element information of the area being clicked. For the sample code, see [getLastHitTest](./arkts-apis-webview-WebviewController.md#getlasthittest18).

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- |---- |
| type | [WebHitTestType](./arkts-apis-webview-e.md#webhittesttype) | No| No| Element type of the area being clicked.|
| extra | string        | No| No|Extra information of the area being clicked. If the area being clicked is an image or a link, the extra information is the URL of the image or link.|

## ControllerAttachState<sup>20+</sup>

Describes the attach status of WebViewController and the **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Value| Description|
| ------------------------------- | - | ---------- |
| UNATTACHED | 0 | Unattached.|
| ATTACHED   | 1 | Attached.|

## BlanklessInfo<sup>20+</sup>

Describes prediction information about blankless loading, including the first screen similarity, first screen loading duration, and error code. The application determines whether to enable the blankless loading solution based on the prediction information.

**System capability**: SystemCapability.Web.Webview.Core

| Name       | Type  | Read-Only| Optional|Description                |
| ----------- | ------ | -----|------|------------------- |
| errCode | WebBlanklessErrorCode | No  | No  | Error code of blankless loading. For details, see [WebBlanklessErrorCode](./arkts-apis-webview-e.md#webblanklesserrorcode20).|
| similarity | number | No  | No  | First screen similarity, which is calculated based on the historical first screen content. The value ranges from 0 to 1.0. 1.0 indicates that the content is the same. A value closer to 1 indicates a higher similarity. This value is lagging, and the similarity of local loading is displayed in the next loading. You are advised not to enable the blankless loading solution when the similarity is low.|
| loadingTime | int | No  | No  | Loading duration estimated based on the historical first screen loading durations, in milliseconds. The value must be greater than 0.|

## HistoryItem

Describes a historical page record.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Type                                  | Read-Only| Optional| Description                        |
| ------------- | -------------------------------------- | ---- | ---- | ---------------------------- |
| icon          | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | Yes  | No  | **PixelMap** object of the icon on the historical page.|
| historyUrl    | string                                 | No  | No  | URL of the historical page.       |
| historyRawUrl | string                                 | No  | No  | Original URL of the historical page.   |
| title         | string                                 | No  | No  | Title of the historical page.          |

## MediaInfo<sup>12+<sup>

Represents a **MediaInfo** object used as a parameter of the [CreateNativeMediaPlayerCallback](./arkts-apis-webview-t.md#createnativemediaplayercallback12) callback.
The object contains information about media on the web page. The application may create, based on the information, a player that takes over media playback of the web page .

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Mandatory| Description|
|------|------|------|------|
| embedID | string | Yes| ID of **\<video>** or **\<audio>** on the web page.|
| mediaType | [MediaType](./arkts-apis-webview-e.md#mediatype12) | Yes| Type of the media.|
| mediaSrcList | [MediaSourceInfo](./arkts-apis-webview-MediaSourceInfo.md)[] | Yes| Source of the media. There may be multiple sources. The application needs to select a supported source to play.|
| surfaceInfo | [NativeMediaPlayerSurfaceInfo](./arkts-apis-webview-NativeMediaPlayerSurfaceInfo.md) | Yes| Surface information used for same-layer rendering.|
| controlsShown | boolean | Yes| Whether the **controls** attribute exists in **\<video>** or **\<audio>**.<br>The value **true** means that the **controls** attribute exists in **\<video>** or **\<audio>**, and **false** means the opposite.|
| controlList | string[] | Yes| Value of the **controlslist** attribute in **\<video>** or **\<audio>**.|
| muted | boolean | Yes| Whether to mute the player.<br>The value **true** means to mute the player, and **false** means the opposite.|
| posterUrl | string | Yes| URL of a poster.|
| preload | [Preload](./arkts-apis-webview-e.md#preload12) | Yes| Whether preloading is required.|
| headers | Record\<string, string\> | Yes| HTTP headers that need to be included in the player's request for media resources.|
| attributes | Record\<string, string\> | Yes| Attributes in **\<video>** or **\<audio>**.|

## RectEvent<sup>12+<sup>

Defines a rectangle.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Type      | Read-Only| Optional| Description                        |
| -------------- | --------- | ---- | ---- | ---------------------------- |
| x  | number   | No  | No  | X-axis coordinate of the upper left corner of the rectangle.   |
| y  | number   | No  | No  | Y-axis coordinate of the upper left corner of the rectangle.   |
| width  | number   | No  | No  | Width of the rectangle.   |
| height  | number   | No  | No  | Height of the rectangle.   |
