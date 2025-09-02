# Types

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## WebMessage

type WebMessage = ArrayBuffer | string

Defines the data types supported by [WebMessagePort](./arkts-apis-webview-WebMessagePort.md).

**System capability**: SystemCapability.Web.Webview.Core

| Type      | Description                                    |
| -------- | -------------------------------------- |
| string   | String type.|
| ArrayBuffer   | Binary type.|

## OnProxyConfigChangeCallback<sup>15+</sup>

type OnProxyConfigChangeCallback = () => void

Defines a callback triggered when the proxy is set successfully.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the sample code, see [removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15).

## CreateNativeMediaPlayerCallback<sup>12+<sup>

type CreateNativeMediaPlayerCallback = (handler: NativeMediaPlayerHandler, mediaInfo: MediaInfo) => NativeMediaPlayerBridge

Defines a **CreateNativeMediaPlayerCallback** object used as a parameter of the [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12) callback.
This object is used to create a player to take over media playback of the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| handler | [NativeMediaPlayerHandler](./arkts-apis-webview-NativeMediaPlayerHandler.md) | Yes| Object used to report the player status to the ArkWeb engine.|
| mediaInfo | [MediaInfo](./arkts-apis-webview-i.md#mediainfo12) | Yes| Information about the media on the web page.|

**Return value**

| Type| Description|
|------|------|
| [NativeMediaPlayerBridge](./arkts-apis-webview-NativeMediaPlayerBridge.md) | Instance of the interface class between the player that takes over web media and the ArkWeb kernel.<br>The application needs to implement this interface class.<br> The ArkWeb engine uses an object of this interface class to control the player created by the application to take over web page media.<br>If the application returns **null**, the application does not take over the media playback, and the media will be played by the ArkWeb engine.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).
