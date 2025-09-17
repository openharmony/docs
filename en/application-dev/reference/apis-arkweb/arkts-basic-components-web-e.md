# Enums
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @yp99ustc; @aohui; @zourongchun-->
<!--Designer: @LongLie; @yaomingliu; @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

> **NOTE**
>
> The initial APIs of this component are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## MessageLevel

Enumerates the information levels of **ConsoleMessage**.

> **NOTE**
>
> - On the HTML5 side, the information level of **ConsoleMessage** corresponding to **console.log** or **console.info** is **MessageLevel.Info**. 

**System capability**: SystemCapability.Web.Webview.Core

| Name   | Value| Description   |
| ----- | -- | ---- |
| Debug | 1 | Debug level.|
| Error | 4 | Error level.|
| Info  | 2 | Information level.|
| Log   | 5 | Log level.|
| Warn  | 3 | Warning level.|

## MixedMode

Enumerates the mixed content modes.

**System capability**: SystemCapability.Web.Webview.Core

| Name       | Value| Description                                |
| ---------- | -- | ---------------------------------- |
| All        | 0 | Loose mode: HTTP and HTTPS hybrid content can be loaded. This means that all insecure content can be loaded.|
| Compatible | 1 | Compatible mode: HTTP and HTTPS hybrid content can be loaded in compatibility mode. This means that some insecure content may be loaded.          |
| None       | 2 | Strict mode: HTTP and HTTPS hybrid content cannot be loaded.              |

## HitTestType

Enumerates the test result types of the click event.

 **System capability**: SystemCapability.Web.Webview.Core

| Name           | Value| Description                      |
| ------------- | -- | ------------------------ |
| EditText      | 0 | Editable area.                 |
| Email         | 1 | Email address.                 |
| HttpAnchor    | 2 | Hyperlink whose **src** is **http**.          |
| HttpAnchorImg | 3 | Image with a hyperlink, where **src** is **http**.|
| Img           | 4 | HTML::img tag.            |
| Map           | 5 | Geographical address.                   |
| Phone         | 6 | Phone number.                   |
| Unknown       | 7 | Unknown content.                   |

## CacheMode

Enumerates the cache modes.

**System capability**: SystemCapability.Web.Webview.Core

| Name     | Value| Description                                  |
| ------- | -- | ------------------------------------ |
| Default<sup>9+</sup> | 0 | The cache that has not expired is preferentially used to load resources. If the cache is invalid or no cache is available, resources are obtained from the Internet.|
| None    | 1 | The cache (including expired caches) is preferentially used to load resources. If no cache is available, resources are obtained from the Internet.    |
| Online  | 2 | The cache is not used to load the resources. All resources are forcibly obtained from the Internet.              |
| Only    | 3 | The local cache alone is used to load the resources.                       |


## OverScrollMode<sup>11+</sup>

Enumerates whether to enable overscroll mode.

 **System capability**: SystemCapability.Web.Webview.Core

| Name    | Value| Description         |
| ------ | -- | ----------- |
| NEVER  | 0 | The overscroll mode is disabled.|
| ALWAYS | 1 | The overscroll mode is enabled.|

## BlurOnKeyboardHideMode<sup>14+</sup>

Enumerates whether the **Web** component loses focus when the soft keyboard is hidden.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Value| Description         |
| ------ | -- | ----------- |
| SILENT  | 0 | The **Web** component does not lose focus when the soft keyboard is hidden.|
| BLUR | 1 | The **Web** component loses focus when the soft keyboard is hidden, and the focus moves from the text box to the web body.|

## WebDarkMode<sup>9+</sup>

Enumerates whether to enable web dark mode.

**System capability**: SystemCapability.Web.Webview.Core

| Name  | Value| Description          |
| ---- | -- | ------------ |
| Off  | 0 | The web dark mode is disabled.  |
| On   | 1 | The web dark mode is enabled.  |
| Auto | 2 | The web dark mode setting follows the system setting.|

## WebCaptureMode<sup>10+</sup>

Enumerates the web screen capture modes.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Value| Description     |
| ----------- | -- | ------- |
| HOME_SCREEN | 0 | Home screen capture mode.|

## ThreatType<sup>11+</sup>

Enumerates the website threat types.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Value| Description                  |
| ---------------- | -- | ----------------------|
| THREAT_ILLEGAL  | 0 | Illegal website.             |
| THREAT_FRAUD    | 1 | Fraudulent website.             |
| THREAT_RISK     | 2 | Website that poses security risks.     |
| THREAT_WARNING  | 3 | Website suspected to contain unsafe content.|

## RenderExitReason<sup>9+</sup>

Enumerates the reasons why the rendering process exits.

**System capability**: SystemCapability.Web.Webview.Core

| Name                        | Value| Description               |
| -------------------------- | -- | ----------------- |
| ProcessAbnormalTermination | 0 | The rendering process exits abnormally.        |
| ProcessWasKilled           | 1 | The rendering process receives a SIGKILL message or is manually terminated.|
| ProcessCrashed             | 2 | The rendering process crashes due to segmentation or other errors.   |
| ProcessOom                 | 3 | The program memory is insufficient.          |
| ProcessExitUnknown         | 4 | Other reason.            |

## SslError<sup>9+</sup>

Enumerates the error codes returned by **onSslErrorEventReceive** API.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Value| Description         |
| ------------ | -- | ----------- |
| Invalid      | 0 | Minor error.      |
| HostMismatch | 1 | The host name does not match.    |
| DateInvalid  | 2 | The certificate has an invalid date.    |
| Untrusted    | 3 | The certificate issuer is not trusted.|

## FileSelectorMode<sup>9+</sup>

Enumerates the modes of the file selector.

**System capability**: SystemCapability.Web.Webview.Core

| Name                  | Value| Description        |
| -------------------- | -- | ---------- |
| FileOpenMode         | 0 | Open and upload a file. |
| FileOpenMultipleMode | 1 | Open and upload multiple files. |
| FileOpenFolderMode   | 2 | Open and upload a folder.|
| FileSaveMode         | 3 | Save a file.   |

## WebLayoutMode<sup>11+</sup>

Enumerates the web layout modes.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Value| Description                |
| ----------- | -- | ------------------ |
| NONE        | 0 | The web layout follows the system.        |
| FIT_CONTENT | 1 | The web layout adapts to the page size.|

## RenderProcessNotRespondingReason<sup>12+</sup>

Enumerates the reasons why the rendering process does not respond.

**System capability**: SystemCapability.Web.Webview.Core

| Name                          | Value| Description          |
| ----------------------------- | -- | ------------ |
| INPUT_TIMEOUT                  | 0 | The input event response sent to the rendering process times out.  |
| NAVIGATION_COMMIT_TIMEOUT      | 1 | The navigation for loading a new web page times out.  |

## ProtectedResourceType<sup>9+</sup>

**System capability**: SystemCapability.Web.Webview.Core

| Name                         | Value| Description           |    Available Permission         |
| --------------------------- | --------------- | ------------- |  ---------------------|
| MidiSysex                   | TYPE_MIDI_SYSEX | MIDI SYSEX resource.<br>Currently, only permission events can be reported. MIDI devices are not yet supported.| Currently, the permission related to the Musical Instrument Digital Interface (MIDI) device cannot be requested.|
| VIDEO_CAPTURE<sup>10+</sup> | TYPE_VIDEO_CAPTURE | Video capture resource, such as a camera. | Camera permission: **ohos.permission.CAMERA**.|
| AUDIO_CAPTURE<sup>10+</sup> | TYPE_AUDIO_CAPTURE | Audio capture resource, such as a microphone.| Microphone permission: **ohos.permission.MICROPHONE**.|
| SENSOR<sup>12+</sup>        | TYPE_SENSOR | Sensor resource, such as an acceleration sensor.| Acceleration sensor permission: **ohos.permission.ACCELEROMETER**,<br>Gyroscope sensor permission: **ohos.permission.GYROSCOPE**.|

## ContextMenuSourceType<sup>9+</sup>

Enumerates the event source types that trigger the context menu.

**System capability**: SystemCapability.Web.Webview.Core

| Name      | Value| Description        |
| --------- | -- |------------ |
| None      | 0 | Other event sources.|
| Mouse     | 1 | Mouse event.  |
| LongPress | 2 | Long press event.  |

## ContextMenuMediaType<sup>9+</sup>

Enumerates the media types that trigger the context menu.

**System capability**: SystemCapability.Web.Webview.Core

| Name   | Value| Description           |
| ----- | -- | ------------- |
| None  | 0 | Other non-image media types.|
| Image | 1 | Image.          |

## ContextMenuInputFieldType<sup>9+</sup>

Enumerates the input field types.

**System capability**: SystemCapability.Web.Webview.Core

| Name       | Value| Description                         |
| --------- | -- | --------------------------- |
| None      | 0 | Non-input field.                      |
| PlainText | 1 | Plain text field, such as the text, search, or email field.|
| Password  | 2 | Password field.                      |
| Number    | 3 | Number field.                      |
| Telephone | 4 | Phone number field.                    |
| Other     | 5 | Field of any other type.                      |

## NativeEmbedStatus<sup>11+</sup>

Enumerates the lifecycles of the same-layer tag. When a same-layer tag exists on the loaded page, **CREATE** is triggered. When a same-layer tag is moved or is enlarged, **UPDATE** is triggered. When the page exits, **DESTROY** is triggered.

**System capability**: SystemCapability.Web.Webview.Core

| Name                          | Value| Description          |
| ----------------------------- | -- | ------------ |
| CREATE                        | 0 | The same-layer tag is created.  |
| UPDATE                        | 1 | The same-layer tag is updated.  |
| DESTROY                       | 2 | The same-layer tag is destroyed.|
| ENTER_BFCACHE<sup>12+</sup>   | 3 | The same-layer tag enters BFCache.  |
| LEAVE_BFCACHE<sup>12+</sup>   | 4 | The same-layer tag leaves BFCache.|

## ContextMenuEditStateFlags<sup>9+</sup>

Enumerates the context menu edit state flags. This enum can be used in bitwise OR mode. For example, to support **CAN_CUT**, **CAN_COPY**, and **CAN_SELECT_ALL** at the same time, use **CAN_CUT | CAN_COPY | CAN_SELECT_ALL** or **11**.

**System capability**: SystemCapability.Web.Webview.Core

| Name           | Value| Description    |
| -------------- | -- | -------- |
| NONE           | 0 | Editing is not allowed.|
| CAN_CUT        | 1 << 0 | Cutting is supported.|
| CAN_COPY       | 1 << 1 | Copying is supported.|
| CAN_PASTE      | 1 << 2 | Pasting is supported.|
| CAN_SELECT_ALL | 1 << 3 | Selecting all is supported.|

## WebNavigationType<sup>11+</sup>

Enumerates the navigation types.

**System capability**: SystemCapability.Web.Webview.Core

| Name                          | Value| Description          |
| ----------------------------- | -- | ------------ |
| UNKNOWN                       | 0 | Unknown type.  |
| MAIN_FRAME_NEW_ENTRY          | 1 | Navigation to a new history entry from the main document.  |
| MAIN_FRAME_EXISTING_ENTRY     | 2 | Navigation to an existing history entry from the main document.|
| NAVIGATION_TYPE_NEW_SUBFRAME  | 4 | User-triggered navigation from a subdocument.|
| NAVIGATION_TYPE_AUTO_SUBFRAME | 5 | Non-user-triggered navigation from a subdocument.|

## RenderMode<sup>12+</sup>

Enumerates the rendering modes of the **Web** component. By default, the asynchronous rendering mode is used.

The asynchronous rendering mode is recommended because it has better performance and lower power consumption.

**System capability**: SystemCapability.Web.Webview.Core

| Name                          | Value| Description          |
| ----------------------------- | -- | ------------ |
| ASYNC_RENDER                        | 0 | The **Web** component as a graphic surface node is rendered asynchronously and displayed independently. The maximum width of the **Web** component is 7,680 px (physical pixel).  |
| SYNC_RENDER                        | 1 | The **Web** component as a graphic canvas node is rendered synchronously and displayed together with the system component. The maximum width of the **Web** component is 500,000 px (physical pixel).  |

## ViewportFit<sup>12+</sup>

Enumerates the viewport types available for **viewport-fit** in the web page **\<meta>** tag.

**System capability**: SystemCapability.Web.Webview.Core

| Name                          | Value| Description          |
| ----------------------------- | -- | ------------ |
| AUTO                  | 0 | The entire web page is visible. Default value.  |
| CONTAINS      | 1 | The initial layout viewport and the visual viewport fit within the largest rectangle that adapts to the device's display screen.  |
| COVER      | 2| The initial layout viewport and the visual viewport are confined within the bounding rectangle of the device's physical screen.  |

## WebKeyboardAvoidMode<sup>12+</sup>

Enumerates the soft keyboard avoidance modes.

**System capability**: SystemCapability.Web.Webview.Core

| Name              | Value| Description          |
| ------------------ | -- | ------------ |
| RESIZE_VISUAL      | 0 | For soft keyboard avoidance, the visual viewport is resized, but not the layout viewport.  |
| RESIZE_CONTENT     | 1 | For soft keyboard avoidance, both the visual viewport and layout viewport are resized. Default value.|
| OVERLAYS_CONTENT   | 2 | No viewport is resized, and soft keyboard avoidance is not triggered.  |

## WebElementType<sup>13+</sup>

Enumerates the web element types.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Value| Description             |
| --------- | -- | ----------------- |
| IMAGE     | 1 | Image.|
| LINK<sup>20+</sup>     | 2 | Hyperlink.|

## WebResponseType<sup>13+</sup>

Enumerates the response types of the menu.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name           | Value| Description               |
| -------------- | -- | ------------------  |
| LONG_PRESS     | 1 | The menu is displayed when the component is long-pressed.|

## AudioSessionType<sup>20+</sup>

Enumerates the web audio types in the application.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name           | Value| Description               |
| -------------- | -- | ------------------  |
| AMBIENT     | 3 | Web game sounds and system music can be played at the same time. This value is applicable to web game scenarios. Its corresponding system audio stream type is **STREAM_USAGE_GAME**.|

## GestureFocusMode<sup>20+</sup>

Enumerates the focus modes.

**System capability**: SystemCapability.Web.Webview.Core

| Name                      | Value| Description          |
| -------------------------- | -- | ------------- |
| DEFAULT                    | 0 | The **Web** component applies for the focus when it is touched, long-pressed, swiped, or zoomed.|
| GESTURE_TAP_AND_LONG_PRESS | 1 | The **Web** component applies for the focus only when it is touched and long-pressed. The swipe and zoom gestures do not apply for the focus.|

## WebBypassVsyncCondition<sup>20+</sup>

Enumerates whether to allow the rendering process to bypass the vsync scheduling.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Value| Description                |
| ----------- | -- | ------------------ |
| NONE        | 0 | The rendering process does not bypass the vsync scheduling. Default value.        |
| SCROLLBY_FROM_ZERO_OFFSET | 1 | When **scrollby** is used (only the scrolling offset is supported) and the scrolling offset of the web page is **0**, the rendering process bypasses the vsync scheduling.|

## PdfLoadResult<sup>20+</sup>

Enumerates the PDF page loading results.

**System capability**: SystemCapability.Web.Webview.Core

| Name            | Value   | Description                                      |
| -------------- | ---- | ---------------------------------------- |
| LOAD_SUCCESS | 0 | The PDF file is successfully loaded.   |
| PARSE_ERROR_FILE | 1 | The PDF file fails to be loaded.|
| PARSE_ERROR_FORMAT | 2 | The PDF file format is not supported.|
| PARSE_ERROR_PASSWORD | 3 | The PDF file password is incorrect.|
| PARSE_ERROR_HANDLER | 4 | The PDF file fails to be processed.|
