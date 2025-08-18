# Types

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## SoundPool<sup>10+</sup>

type SoundPool = _SoundPool

SoundPool, which provides APIs for loading, unloading, playing, and stopping playing system sounds, setting the volume, and setting the number of loops.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

| Type    | Description                      |
| -------- | ------------------------------ |
| [_SoundPool](js-apis-inner-multimedia-soundPool.md#soundpool)  | Provides APIs for loading, unloading, playing, and stopping playing system sounds, setting the volume, and setting the number of loops.|

## PlayParameters<sup>10+</sup>

type PlayParameters = _PlayParameters

Describes the playback parameters of the sound pool.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

| Type    | Description                      |
| -------- | ------------------------------ |
| [_PlayParameters](js-apis-inner-multimedia-soundPool.md#playparameters)  | Playback parameters of the sound pool.|

## AVPlayerState<sup>9+</sup>

type AVPlayerState = 'idle' | 'initialized' | 'prepared' | 'playing' | 'paused' | 'completed' | 'stopped' | 'released' | 'error'

Describes the state of the [AVPlayer](arkts-apis-media-AVPlayer.md). Your application can proactively obtain the AVPlayer state through the **state** property or obtain the reported AVPlayer state by subscribing to the [stateChange](arkts-apis-media-AVPlayer.md#onstatechange9) event. For details about the rules for state transition, see [Audio Playback](../../media/media/using-avplayer-for-playback.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

|              Type              | Description                                                        |
| :-----------------------------: | :----------------------------------------------------------- |
|              'idle'               | The AVPlayer enters this state after [createAVPlayer()](arkts-apis-media-f.md#mediacreateavplayer9) or [reset()](arkts-apis-media-AVPlayer.md#reset9) is called.<br>In case [createAVPlayer()](arkts-apis-media-f.md#mediacreateavplayer9) is used, all properties are set to their default values.<br>In case [reset()](arkts-apis-media-AVPlayer.md#reset9) is called, the **url<sup>9+</sup>**, **fdSrc<sup>9+</sup>**, or **dataSrc<sup>10+</sup>** property and the **loop** property are reset, and other properties are retained.|
|           'initialized'           | The AVPlayer enters this state after **url<sup>9+</sup>** or **fdSrc<sup>9+</sup>** property is set in the idle state. In this case, you can configure static properties such as the window and audio.|
|            'prepared'             | The AVPlayer enters this state when [prepare()](arkts-apis-media-AVPlayer.md#prepare9) is called in the initialized state. In this case, the playback engine has prepared the resources.|
|             'playing'             | The AVPlayer enters this state when [play()](arkts-apis-media-AVPlayer.md#play9) is called in the prepared, paused, or completed state.|
|             'paused'              | The AVPlayer enters this state when **pause()** is called in the playing state.|
|            'completed'            | The AVPlayer enters this state when a media asset finishes playing and loop playback is not set (no **loop = true**). In this case, if [play()](arkts-apis-media-AVPlayer.md#play9) is called, the AVPlayer enters the playing state and replays the media asset; if [stop()](arkts-apis-media-AVPlayer.md#stop9) is called, the AVPlayer enters the stopped state.|
|             'stopped'             | The AVPlayer enters this state when [stop()](arkts-apis-media-AVPlayer.md#stop9) is called in the prepared, playing, paused, or completed state. In this case, the playback engine retains the properties but releases the memory resources. You can call [prepare()](arkts-apis-media-AVPlayer.md#prepare9) to prepare the resources again, call [reset()](arkts-apis-media-AVPlayer.md#reset9) to reset the properties, or call [release()](arkts-apis-media-AVPlayer.md#release9) to destroy the playback engine.|
|            'released'             | The AVPlayer enters this state when [release()](arkts-apis-media-AVPlayer.md#release9) is called. The playback engine associated with the AVPlayer instance is destroyed, and the playback process ends. This is the final state.|
| 'error' | The AVPlayer enters this state when an irreversible error occurs in the playback engine. You can call [reset()](arkts-apis-media-AVPlayer.md#reset9) to reset the properties or call [release()](arkts-apis-media-AVPlayer.md#release9) to destroy the playback engine. For details about the error codes, see [Media Error Codes](errorcode-media.md).<br>**NOTE** Relationship between the error state and the [on('error')](arkts-apis-media-AVPlayer.md#onerror9) event<br>1. When the AVPlayer enters the error state, the **on('error')** event is triggered. You can obtain the detailed error information through this event.<br>2. When the AVPlayer enters the error state, the playback service stops. This requires the client to design a fault tolerance mechanism to call [reset()](arkts-apis-media-AVPlayer.md#reset9) or [release()](arkts-apis-media-AVPlayer.md#release9).<br>3. The client receives **on('error')** event but the AVPlayer does not enter the error state. This situation occurs due to either of the following reasons:<br>Cause 1: The client calls an API in an incorrect state or passes in an incorrect parameter, and the AVPlayer intercepts the call. If this is the case, the client must correct its code logic.<br>Cause 2: A stream error is detected during playback. As a result, the container and decoding are abnormal for a short period of time, but continuous playback and playback control operations are not affected. If this is the case, the client does not need to design a fault tolerance mechanism.|

## OnTrackChangeHandler<sup>12+</sup>

type OnTrackChangeHandler = (index: number, isSelected: boolean) => void

Describes the callback invoked for the track change event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

| Name  | Type  | Mandatory| Description                                                        |
| ------ | ------ | ------ | ---------------------------------------------------------- |
| index  | number | Yes| Index of the track that has changed.    |
| isSelected | boolean | Yes| Whether the track at the current index is selected. The value **true** means that the track at the current index is selected, and **false** means the opposite.|

## OnAVPlayerStateChangeHandle<sup>12+</sup>

type OnAVPlayerStateChangeHandle = (state: AVPlayerState, reason: StateChangeReason) => void

Describes the callback invoked for the AVPlayer state change event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

| Name  | Type  | Mandatory| Description                                                        |
| ------ | ------ | ------ | ---------------------------------------------------------- |
| state  | [AVPlayerState](#avplayerstate9) | Yes| State of the AVPlayer.    |
| reason | [StateChangeReason](arkts-apis-media-e.md#statechangereason9) | Yes| Reason for the state change.|

## OnBufferingUpdateHandler<sup>12+</sup>

type OnBufferingUpdateHandler = (infoType: BufferingInfoType, value: number) => void

Describes the callback invoked for the buffering update event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

| Name  | Type  | Mandatory| Description                                                        |
| ------ | ------ | ------ | ------------------------------------------------------------ |
| infoType  | [BufferingInfoType](arkts-apis-media-e.md#bufferinginfotype8) | Yes| Buffering information type.    |

## OnVideoSizeChangeHandler<sup>12+</sup>

type OnVideoSizeChangeHandler = (width: number, height: number) => void

Describes the callback invoked for the video size change event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

| Name  | Type  | Mandatory| Description                                                        |
| ------ | ------ | ------ | ------------------------------------------------------------ |
| width  | number | Yes| Video width, in px.|
| height | number | Yes| Video height, in px.|

## OnSuperResolutionChanged <sup>18+</sup>

type OnSuperResolutionChanged = (enabled: boolean) => void

Describes the callback used to listen for video super resolution status changes. If super resolution is enabled by using [PlaybackStrategy](arkts-apis-media-i.md#playbackstrategy12), this callback is invoked to report the super resolution status changes. It is also invoked to report the initial status when the video starts. However, this callback is not invoked when super resolution is not enabled.

Super resolution is automatically disabled in either of the following cases:
* The current super resolution algorithm only works with videos that have a frame rate of 30 fps or lower. If the video frame rate exceeds 30 fps, or if the input frame rate exceeds the processing capability of the super resolution algorithm in scenarios such as fast playback, super resolution is automatically disabled.
* The current super resolution algorithm supports input resolutions from 320 x 320 to 1920 x 1080, in px. If the input video resolution exceeds the range during playback, super resolution is automatically disabled.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

| Name  | Type  | Mandatory| Description                                                        |
| ------ | ------ | ------ | ------------------------------------------------------------ |
| enabled  | boolean | Yes| Whether super resolution is enabled. The value **true** means that it is enabled, and **false** means the opposite.    |

## OnSeiMessageHandle<sup>18+</sup>

type OnSeiMessageHandle = (messages: Array\<SeiMessage>, playbackPosition?: number) => void

Describes the handle used to obtain SEI messages. This is used when in subscriptions to SEI message events, and the callback returns detailed SEI information.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  |   Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| messages | Array\<[SeiMessage](arkts-apis-media-i.md#seimessage18)> | Yes | Array of SEI messages.|
| playbackPosition | number | No | Current playback position, in milliseconds.|

## OnPlaybackRateDone<sup>20+</sup>

type OnPlaybackRateDone = (rate: number) => void

Describes the callback invoked for the event indicating that the playback rate setting is complete.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

| Name  | Type  | Mandatory| Description                                                        |
| ------ | ------ | ------ | ------------------------------------------------------------ |
| rate | number | Yes| Playback rate.|

## AVRecorderState<sup>9+</sup>

type AVRecorderState = 'idle' | 'prepared' | 'started' | 'paused' | 'stopped' | 'released' | 'error'

Enumerates the AVRecorder states. You can obtain the state through the **state** property.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

| Type    | Description                                                        |
| -------- | ------------------------------------------------------------ |
| 'idle'     | The AVRecorder enters this state after it is just created or the [AVRecorder.reset()](arkts-apis-media-AVRecorder.md#reset9) API is called when the AVRecorder is in any state except released. In this state, you can call [AVRecorder.prepare()](arkts-apis-media-AVRecorder.md#prepare9) to set recording parameters. The AVRecorder enters this state after it is just created or the [AVRecorder.reset()](arkts-apis-media-AVRecorder.md#reset9) API is called when the AVRecorder is in any state except released.|
| 'prepared' | The AVRecorder enters this state when the parameters are set. In this state, you can call [AVRecorder.start()](arkts-apis-media-AVRecorder.md#start9) to start recording.|
| 'started'  | The AVRecorder enters this state when the recording starts. In this state, you can call [AVRecorder.pause()](arkts-apis-media-AVRecorder.md#pause9) to pause recording or call [AVRecorder.stop()](arkts-apis-media-AVRecorder.md#stop9) to stop recording.|
| 'paused'   | The AVRecorder enters this state when the recording is paused. In this state, you can call [AVRecorder.resume()](arkts-apis-media-AVRecorder.md#resume9) to continue recording or call [AVRecorder.stop()](arkts-apis-media-AVRecorder.md#stop9) to stop recording.|
| 'stopped'  | The AVRecorder enters this state when the recording stops. In this state, you can call [AVRecorder.prepare()](arkts-apis-media-AVRecorder.md#prepare9) to set recording parameters so that the AVRecorder enters the prepared state again.|
| 'released' | The AVRecorder enters this state when the recording resources are released. In this state, no operation can be performed. In any other state, you can call [AVRecorder.release()](arkts-apis-media-AVRecorder.md#release9) to enter the released state.|
| 'error'    | The AVRecorder enters this state when an irreversible error occurs in the AVRecorder instance. In this state, the [AVRecorder.on('error') event](arkts-apis-media-AVRecorder.md#onerror9) is reported, with the detailed error cause. In the error state, you must call [AVRecorder.reset()](arkts-apis-media-AVRecorder.md#reset9) to reset the AVRecorder instance or call [AVRecorder.release()](arkts-apis-media-AVRecorder.md#release9) to release the resources.|

## OnAVRecorderStateChangeHandler<sup>12+</sup>

type OnAVRecorderStateChangeHandler = (state: AVRecorderState, reason: StateChangeReason) => void

Describes the callback invoked for the AVRecorder state change event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

| Name  | Type  | Mandatory| Description                                                        |
| ------ | ------ | ------ | ------------------------------------------------------------ |
| state  | [AVRecorderState](#avrecorderstate9) | Yes| AVRecorder state.    |
| reason | [StateChangeReason](arkts-apis-media-e.md#statechangereason9) | Yes| Reason for the state change.|

## SourceOpenCallback<sup>18+</sup>

type SourceOpenCallback = (request: MediaSourceLoadingRequest) => number

This callback function is implemented by applications to handle resource open requests and return a unique handle for the opened resource.
> **NOTE**
>
> The client must return the handle immediately after processing the request.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Multimedia.Media.Core

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| request | [MediaSourceLoadingRequest](arkts-apis-media-MediaSourceLoadingRequest.md) | Yes | 	Parameters for the resource open request, including detailed information about the requested resource and the data push method.|

**Return value**

| Type  | Description                |
| -------- | -------------------- |
| number  | Handle for the current resource open request. A value greater than 0 means the request is successful, whereas a value less than or equal to 0 means it fails.<br> - The handle for the request object is unique.|

**Example**

```ts
import HashMap from '@ohos.util.HashMap';

let uuid: number = 1;
let requests: HashMap<number, media.MediaSourceLoadingRequest> = new HashMap();

let sourceOpenCallback: media.SourceOpenCallback = (request: media.MediaSourceLoadingRequest) => {
  console.log(`Opening resource: ${request.url}`);
  // Open the resource and return a unique handle, ensuring the mapping between the UUID and request.
  uuid += 1;
  requests.set(uuid, request);
  return uuid;
};
```

## SourceReadCallback<sup>18+</sup>

type SourceReadCallback = (uuid: number, requestedOffset: number, requestedLength: number) => void

This callback function is implemented by applications to handle resource read requests. When data is available, applications should push it to the player using the [respondData](arkts-apis-media-MediaSourceLoadingRequest.md#responddata18) API of the corresponding MediaSourceLoadingRequest object.

> **NOTE**
>
> The client must return the handle immediately after processing the request.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Multimedia.Media.Core

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| uuid | number | Yes | 	ID for the resource handle.|
| requestedOffset | number | Yes | 	Offset of the current media data relative to the start of the resource.|
| requestedLength | number | Yes | 	Length of the current request. The value **-1** indicates reaching the end of the resource. After pushing the data, call [finishLoading](arkts-apis-media-MediaSourceLoadingRequest.md#finishloading18) to notify the player that the push is complete.|

**Example**

```ts
let sourceReadCallback: media.SourceReadCallback = (uuid: number, requestedOffset: number, requestedLength: number) => {
  console.log(`Reading resource with handle ${uuid}, offset: ${requestedOffset}, length: ${requestedLength}`);
  // Check whether the UUID is valid and store the read request. Avoid blocking the request while pushing data and header information.
};
```

## SourceCloseCallback<sup>18+</sup>

type SourceCloseCallback = (uuid: number) => void

This callback function is implemented by applications to release related resources.

> **NOTE**
>
> The client must return the handle immediately after processing the request.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Multimedia.Media.Core

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| uuid      | number | Yes | ID for the resource handle.|

**Example**

```ts
import HashMap from '@ohos.util.HashMap';

let requests: HashMap<number, media.MediaSourceLoadingRequest> = new HashMap();

let sourceCloseCallback: media.SourceCloseCallback = (uuid: number) => {
  console.log(`Closing resource with handle ${uuid}`);
  // Clear resources related to the current UUID.
  requests.remove(uuid);
};
```

## AudioState<sup>(deprecated)</sup>

type AudioState = 'idle' | 'playing' | 'paused' | 'stopped' | 'error'

Describes the audio playback state. You can obtain the state through the **state** property.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVPlayerState](#avplayerstate9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

| Type   | Description                                          |
| ------- | ---------------------------------------------- |
| 'idle'    | No audio playback is in progress. The audio player is in this state after the **'dataload'** or **'reset'** event is triggered.|
| 'playing' | Audio playback is in progress. The audio player is in this state after the **'play'** event is triggered.          |
| 'paused'  | Audio playback is paused. The audio player is in this state after the **'pause'** event is triggered.         |
| 'stopped' | Audio playback is stopped. The audio player is in this state after the **'stop'** event is triggered.     |
| 'error'   | Audio playback is in the error state.                                    |

## VideoPlayState<sup>(deprecated)</sup>

type VideoPlayState = 'idle' | 'prepared' | 'playing' | 'paused' | 'stopped' | 'error'

Describes the video playback state. You can obtain the state through the **state** property.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayerState](#avplayerstate9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

| Type    | Description          |
| -------- | -------------- |
| 'idle'     | The video player is idle.|
| 'prepared' | Video playback is being prepared.|
| 'playing'  | Video playback is in progress.|
| 'paused'   | Video playback is paused.|
| 'stopped'  | Video playback is stopped.|
| 'error'    | Video playback is in the error state.    |
