# Interface (NativeMediaPlayerHandler)

Implements a **NativeMediaPlayerHandler** object used as a parameter of the [CreateNativeMediaPlayerCallback](./arkts-apis-webview-t.md#createnativemediaplayercallback12) callback.
The application uses this object to report the player status to the ArkWeb engine.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this interface are supported since API version 12.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## handleStatusChanged<sup>12+<sup>

handleStatusChanged(status: PlaybackStatus): void

Called to notify the ArkWeb engine of the playback status of the player when the playback status changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| status | [PlaybackStatus](./arkts-apis-webview-e.md#playbackstatus12) | Yes| Player status.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## handleVolumeChanged<sup>12+<sup>

handleVolumeChanged(volume: number): void

Called to notify the ArkWeb engine of the volume of the player when the volume changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| volume | number | Yes| Volume of the player.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## handleMutedChanged<sup>12+<sup>

handleMutedChanged(muted: boolean): void

Called to notify the ArkWeb engine of the muted status of the player when the muted status changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| muted | boolean | Yes| Whether the player is muted.<br>The value **true** indicates that the player is muted, and **false** indicates the opposite.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## handlePlaybackRateChanged<sup>12+<sup>

handlePlaybackRateChanged(playbackRate: number): void

Called to notify the ArkWeb engine of the playback rate of the player when the playback rate changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| playbackRate | number | Yes| Playback rate.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## handleDurationChanged<sup>12+<sup>

handleDurationChanged(duration: number): void

Called to notify the ArkWeb engine of the total duration of the media.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| duration | number | Yes| Total duration of the media.<br>Unit: second|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## handleTimeUpdate<sup>12+<sup>

handleTimeUpdate(currentPlayTime: number): void

Called to notify the ArkWeb engine of the playback progress when the playback progress changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| currentPlayTime | number | Yes| Current progress. Unit: second. |

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## handleBufferedEndTimeChanged<sup>12+<sup>

handleBufferedEndTimeChanged(bufferedEndTime: number): void

Called to notify the ArkWeb engine of the buffer time when the buffer time changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| bufferedEndTime | number | Yes| Duration of media data in the buffer.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## handleEnded<sup>12+<sup>

handleEnded(): void

Called to notify the ArkWeb engine that the media playback ends.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## handleNetworkStateChanged<sup>12+<sup>

handleNetworkStateChanged(state: NetworkState): void

Called to notify the ArkWeb engine of the network status of the player when the network status changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| state | [NetworkState](./arkts-apis-webview-e.md#networkstate12) | Yes| Network status of the player.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## handleReadyStateChanged<sup>12+<sup>

handleReadyStateChanged(state: ReadyState): void

Called to notify the ArkWeb engine of the cache status of the player when the cache status changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| state | [ReadyState](./arkts-apis-webview-e.md#readystate12) | Yes| Cache status of the player.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## handleFullscreenChanged<sup>12+<sup>

handleFullscreenChanged(fullscreen: boolean): void

Called to notify the ArkWeb engine of the full screen status of the player when the full screen status changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| fullscreen | boolean | Yes| Whether the player is in full screen.<br>The value **true** means that the player is in full screen, and **false** means the opposite.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## handleSeeking<sup>12+<sup>

handleSeeking(): void

Called to notify the ArkWeb engine that the player enters the seek state.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## handleSeekFinished<sup>12+<sup>

handleSeekFinished(): void

Called to notify the ArkWeb engine that the seek operation is complete.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## handleError<sup>12+<sup>

handleError(error: MediaError, errorMessage: string): void

Called to notify the ArkWeb engine that an error occurs with the player.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| error | [MediaError](./arkts-apis-webview-e.md#mediaerror12) | Yes| Error object type.|
| errorMessage | string | Yes| Error message.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## handleVideoSizeChanged<sup>12+<sup>

handleVideoSizeChanged(width: number, height: number): void

Called to notify the ArkWeb engine of the video size of the player.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| width  | number | Yes| Video width.|
| height | number | Yes| Video height.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).
