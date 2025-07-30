# Interface (NativeMediaPlayerBridge)

 
 
Implements a **CreateNativeMediaPlayerCallback** object to control the player created by the application for taking over the web page media playback. This object is a return value type of the [CreateNativeMediaPlayerCallback](./arkts-apis-webview-t.md#createnativemediaplayercallback12) callback.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this interface are supported since API version 12.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## updateRect<sup>12+<sup>

updateRect(x: number, y: number, width: number, height: number): void

Updates the surface position information.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| x | number | Yes| X coordinate of the surface relative to the **Web** component.|
| y | number | Yes| Y coordinate of the surface relative to the **Web** component.|
| width  | number | Yes| Width of the surface.|
| height | number | Yes| Height of the surface.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## play<sup>12+<sup>

play(): void

Plays this video.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## pause<sup>12+<sup>

pause(): void

Pauses playback.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## seek<sup>12+<sup>

seek(targetTime: number): void

Seeks to a specific time point in the media.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| targetTime | number | Yes| Target time point.<br>Unit: second|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## setVolume<sup>12+<sup>

setVolume(volume: number): void

Sets the playback volume.

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| volume | number | Yes| Playback volume.<br>Value range: [0, 1.0]. The value **0** indicates mute, and the value **1.0** indicates the maximum volume.|

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## setMuted<sup>12+<sup>

setMuted(muted: boolean): void

Sets the muted status.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| muted | boolean | Yes| Whether to mute the player.<br>The value **true** means to mute the player, and **false** means the opposite.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## setPlaybackRate<sup>12+<sup>

setPlaybackRate(playbackRate: number): void

Sets the playback rate.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| playbackRate | number | Yes| Playback rate.<br>Value range: [0, 10.0]. The value **1** indicates the original speed of playback.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## release<sup>12+<sup>

release(): void

Releases this player.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## enterFullscreen<sup>12+<sup>

enterFullscreen(): void

Enables the player to enter full screen mode.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## exitFullscreen<sup>12+<sup>

exitFullscreen(): void

Enables the player to exit full screen mode.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## resumePlayer<sup>12+<sup>

resumePlayer?(): void

Resumes the player and its status information.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## suspendPlayer<sup>12+<sup>

suspendPlayer?(type: SuspendType): void

Suspends the player and save its status information.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| type | [SuspendType](./arkts-apis-webview-e.md#suspendtype12) | Yes| Suspension type of the player.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12).
