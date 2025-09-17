# Types
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## AVSessionType<sup>10+<sup>

type AVSessionType = 'audio' | 'video' | 'voice_call' | 'video_call'

Defines the session type supported by the session.

You can use the strings listed in the following table.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Type | Description|
| -----  | ---- |
| 'audio' | Audio session.|
| 'video' | Video session.|
| 'voice_call'<sup>11+<sup> | Voice call.|
| 'video_call'<sup>12+<sup> | Video call.|

## AVCastControlCommandType<sup>10+</sup>

type AVCastControlCommandType = 'play' | 'pause' | 'stop' | 'playNext' | 'playPrevious' | 'fastForward' | 'rewind' |
  'seek' | 'setVolume' | 'setSpeed' | 'setLoopMode' | 'toggleFavorite' | 'toggleMute'

Defines the commands that can be sent by a cast controller.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

| Type            | Description        |
| ---------------- | ------------ |
| 'play'           | Play the media. No parameter is required.|
| 'pause'          | Pause the playback. No parameter is required.  |
| 'stop'           | Stop the playback. No parameter is required.        |
| 'playNext'       | Play the next media asset. No parameter is required.      |
| 'playPrevious'   | Play the previous media asset. No parameter is required.      |
| 'fastForward'    | Fast-forward. No parameter is required.      |
| 'rewind'         | Rewind. No parameter is required.       |
| 'seek'           | Seek to a playback position. The corresponding parameter is of the number type.|
| 'setVolume'      | Set the volume. The corresponding parameter is of the number type. You can use [AVPlaybackState.maxVolume](arkts-apis-avsession-i.md#avplaybackstate10) to obtain the maximum system volume.    |
| 'setSpeed'       | Set the playback speed. The corresponding parameter is [media.PlaybackSpeed](../apis-media-kit/arkts-apis-media-e.md#playbackspeed8).|
| 'setLoopMode'    | Set the loop mode. The corresponding parameter is [LoopMode](arkts-apis-avsession-e.md#loopmode10).|
| 'toggleFavorite' | Favorite the media asset. The corresponding parameter is [AVMetadata.assetId](arkts-apis-avsession-i.md#avmetadata10).   |
| 'toggleMute'     | Set the muted status. No parameter is required.|

## ExtraInfo<sup>18+</sup>

type ExtraInfo = { [key: string]: Object; }

Defines the custom media packet set by the provider.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Type                               | Description                         |
| ----------------------------------- | ----------------------------- |
| [key: string]: Object   | **key** specifies the remote distributed event type. Currently, the following event types are supported:<br>**'AUDIO_GET_VOLUME'**: obtains the volume of the remote device.<br>**'AUDIO_GET_AVAILABLE_DEVICES'**: obtains all remote devices that can be connected.<br>**'AUDIO_GET_PREFERRED_OUTPUT_DEVICE_FOR_RENDERER_INFO'**: obtains the actual remote audio device.<br>The provider returns the corresponding media packet object based on the event type.|

## KeyRequestCallback<sup>12+</sup>

type KeyRequestCallback = (assetId: string, requestData: Uint8Array) => void

Defines the callback invoked for the media key request event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name| Type  | Mandatory| Description                                     |
| ------ | ------ | ---- | ----------------------------------------- |
| assetId     | string  | Yes  | Media asset ID.|
| requestData |  Uint8Array  | Yes  | Data carried in the media key request.                           |

**Example**
<!--code_no_check-->
```ts
let keyRequestCallback: avSession.KeyRequestCallback = async(assetId: string, requestData: Uint8Array) => {
  console.info(`Succeeded in keyRequestCallback. assetId: ${assetId}, requestData: ${requestData}`);
}
```

## AVControlCommandType<sup>10+</sup>

type AVControlCommandType = 'play' | 'pause' | 'stop' | 'playNext' | 'playPrevious' | 'fastForward' | 'rewind' |
  'seek' | 'setSpeed' | 'setLoopMode' | 'toggleFavorite' | 'playFromAssetId' | 'playWithAssetId' | 'answer' | 'hangUp' | 'toggleCallMute' | 'setTargetLoopMode'

Defines the commands that can be sent to a session.

You can use the union of the strings listed in the following table.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Type            | Description        |
| ---------------- | ------------ |
| 'play'           | Play the media. No parameter is required.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| 'pause'          | Pause the playback. No parameter is required.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| 'stop'           | Stop the playback. No parameter is required.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| 'playNext'       | Play the next media asset. No parameter is required.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| 'playPrevious'   | Play the previous media asset. No parameter is required.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| 'fastForward'    | Fast-forward. No parameter is required.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| 'rewind'         | Rewind. No parameter is required.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| 'seek'           | Seek to a playback position. The corresponding parameter is of the number type.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| 'setSpeed'       | Set the playback speed. The corresponding parameter is of the number type.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| 'setLoopMode'    | Set the loop mode. The corresponding parameter is [LoopMode](arkts-apis-avsession-e.md#loopmode10).<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| 'setTargetLoopMode' <sup>18+</sup>   | Set the target loop mode. The recommended parameter is [LoopMode](arkts-apis-avsession-e.md#loopmode10).<br>**Atomic service API**: This API can be used in atomic services since API version 18. |
| 'toggleFavorite' | Favorite the media asset. The corresponding parameter is [AVMetadata.assetId](arkts-apis-avsession-i.md#avmetadata10).<br>**Atomic service API**: This API can be used in atomic services since API version 12.   |
| 'playFromAssetId' <sup>11+</sup>| Play the media asset with the specified asset ID.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| 'playWithAssetId' <sup>20+</sup>    | Play the media asset with the specified asset ID. The corresponding parameter is [AVMetadata.assetId](arkts-apis-avsession-i.md#avmetadata10).<br>The string length must be less than 40960 bytes.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
|'answer' <sup>11+</sup>        | Answer a call. No parameter is required.<br>**Atomic service API**: This API can be used in atomic services since API version 12.     |
| 'hangUp' <sup>11+</sup>         | The call is disconnecting. No parameter is required.<br>**Atomic service API**: This API can be used in atomic services since API version 12.     |
|'toggleCallMute' <sup>11+</sup>  | Set the mute status for a call. No parameter is required.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
