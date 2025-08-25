# Interfaces (Others)
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--SE: @ccfriend-->
<!--TSE: @chenmingxi1_huawei-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## AVCastControlCommand<sup>10+</sup>

Describes the command that can be sent by a cast controller.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

| Name     | Type                                             | Mandatory| Description          |
| --------- | ------------------------------------------------- | ---- | -------------- |
| command   | [AVCastControlCommandType](arkts-apis-avsession-t.md#avcastcontrolcommandtype10)     | Yes  | Command. The parameters carried in each command are different. For details, see [AVCastControlCommandType](arkts-apis-avsession-t.md#avcastcontrolcommandtype10).|
| parameter | [media.PlaybackSpeed](../apis-media-kit/arkts-apis-media-e.md#playbackspeed8) &#124; number &#124; string &#124; [LoopMode](arkts-apis-avsession-e.md#loopmode10) | No  | Parameters carried in the command.|

## CastDisplayInfo<sup>12+</sup>

Describes the information about the cast display in the case of extended screens.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.ExtendedDisplayCast

| Name           | Type                     | Read-Only| Optional| Description              |
| --------------- |-------------------------| ---- | ---- |---------------------------------------------------------------------|
| id            | number                  | No   | No   | ID of the cast display. The value must be an integer. |
| name     | string                  | No   | No   | Name of the cast display.          |
| state          | [CastDisplayState](arkts-apis-avsession-e.md#castdisplaystate12)          | No   | No   |State of the cast display.           |
| width          | number          | No   | No   | Screen width of the cast display, in px. The value must be an integer.         |  
| height          | number          | No   | No   | Screen height of the cast display, in px. The value must be an integer.           |  

## AVMetadata<sup>10+</sup>

Describes the media metadata.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name           | Type                     | Read-Only| Optional| Description              |
| --------------- |-------------------------| ---- | ---- |---------------------------------------------------------------------|
| assetId         | string                  | No  | No  | Media asset ID. It is the unique ID of a song and defined by the application.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                    |
| title           | string                  | No  | Yes  | Title.<br>**Atomic service API**: This API can be used in atomic services since API version 12.             |
| artist          | string                  | No  | Yes  | Artist.<br>**Atomic service API**: This API can be used in atomic services since API version 12.            |
| author          | string                  | No  | Yes  | Author.<br>**Atomic service API**: This API can be used in atomic services since API version 12.           |
| avQueueName<sup>12+</sup>       | string                  | No  | Yes  | Playlist name.           |
| avQueueId<sup>11+</sup>       | string                  | No  | Yes  | Unique ID of the playlist.           |
| avQueueImage<sup>11+</sup>    | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) &#124; string | No  | Yes  | Cover image of the playlist, which can be pixel data of an image or an image path (local path or Internet path). Applications call **setAVMetadata** to set the image data.<br>- If the data type is set to **PixelMap**, the data obtained by calling **getAVMetadata** is the pixel data of an image.<br>- If the data type is set to **url**, the data obtained is an image path. |
| album           | string                  | No  | Yes  | Album name.<br>**Atomic service API**: This API can be used in atomic services since API version 12.           |
| writer          | string                  | No  | Yes  | Writer.<br>**Atomic service API**: This API can be used in atomic services since API version 12.            |
| composer        | string                  | No  | Yes  | composer.            |
| duration        | number                  | No  | Yes  | Media duration, in ms.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                 |
| mediaImage      | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) &#124; string | No  | Yes  | Pixel map or image path (local path or network path) of the image. Applications call **setAVMetadata** to set the image data.<br>- If the data type is set to **PixelMap**, the data obtained by calling **getAVMetadata** is the pixel data of an image.<br>- If the data type is set to **url**, the data obtained is an image path.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                            |
| bundleIcon<sup>18+</sup>      | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | Yes  | Yes  | Pixel data of the image that is used as the application icon. It is read-only and cannot be set on the application side.|
| publishDate     | Date                    | No  | Yes  | Release date.         |
| subtitle        | string                  | No  | Yes  | Subtitle.<br>**Atomic service API**: This API can be used in atomic services since API version 12.            |
| description     | string                  | No  | Yes  | Media description.<br>**Atomic service API**: This API can be used in atomic services since API version 12.           |
| lyric           | string                  | No  | Yes  | Lyrics. The application needs to combine the lyrics into a string.<br>The string length must be less than 40960 bytes.<br>**NOTE**: The system supports lyrics in the simple LRC format. If the lyrics are not standard (for example, having duplicate timestamps), the lyrics fail to be parsed and cannot be displayed properly in the system.|
| singleLyricText<sup>17+</sup> | string    | No  | Yes  | Lyrics of a single media asset. The application must combine the lyrics into a string (excluding the timestamp).<br>The string length must be less than 40960 bytes.<br>**Atomic service API**: This API can be used in atomic services since API version 17.|
| previousAssetId | string                  | No  | Yes  | ID of the previous media asset.<br>**Atomic service API**: This API can be used in atomic services since API version 12.        |
| nextAssetId     | string                  | No  | Yes  | ID of the next media asset.<br>**Atomic service API**: This API can be used in atomic services since API version 12.        |
| filter<sup>11+</sup>        | number         | No  | Yes  | Protocol supported by the media session. The default value is **TYPE_CAST_PLUS_STREAM**. For details, see [ProtocolType](arkts-apis-avsession-e.md#protocoltype11).<br>**Atomic service API**: This API can be used in atomic services since API version 12.                  |
| drmSchemes<sup>12+</sup>        | Array\<string>         | No  | Yes  | DRM scheme supported by the media session. The value is the UUID of the DRM scheme.|
| skipIntervals<sup>11+</sup>  | [SkipIntervals](arkts-apis-avsession-e.md#skipintervals11)        | No  | Yes  | Intervals supported for fast-forwarding and rewinding. The default value is **SECONDS_15**, that is, 15 seconds.                           |
|displayTags<sup>11+</sup>     | number                           | No  | Yes  | Display tags of the media asset. For details, see [DisplayTag](arkts-apis-avsession-e.md#displaytag11).      |

## AVMediaDescription<sup>10+</sup>

Describes the properties related to the media metadata in the playlist.

| Name        | Type                   | Read-Only | Optional | Description                    |
| ------------ | ----------------------- | ---- | ---- | ----------------------- |
| assetId      | string                  | No  | No  | Media ID in the playlist.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| title        | string                  | No  | Yes  | Name of the media asset in the playlist.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| subtitle     | string                  | No  | Yes  | Subname of the media asset in the playlist.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| description  | string                  | No  | Yes  | Description of the media asset in the playlist.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| mediaImage | image.PixelMap \| string   | No  | Yes  | Pixel map of the image of the media asset in the playlist.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| extras       | {[key: string]: Object}    | No  | Yes  | Additional fields of the media asset in the playlist.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core|
| mediaUri     | string                  | No  | Yes  | URI of the media asset in the playlist.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| mediaType     | string                  | No  | Yes  | Type of the media asset in the playlist.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| mediaSize     | number                  | No  | Yes  | Size of the media asset in the playlist.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| albumTitle     | string                  | No  | Yes  | Album name of the media asset in the playlist.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| albumCoverUri     | string                  | No  | Yes  | URI of the album title of the media asset in the playlist.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| lyricContent     | string                  | No  | Yes  | Lyric content of the media asset in the playlist.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| lyricUri     | string                  | No  | Yes  | Lyric URI of the media asset in the playlist.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| artist     | string                  | No  | Yes  | Author of the lyric of the media asset in the playlist.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| fdSrc     | media.AVFileDescriptor        | No  | Yes  | Handle to the local media file in the playlist.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| dataSrc<sup>12+</sup>     | media.AVDataSrcDescriptor        | No  | Yes  | Descriptor of the data source in the playlist.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core|
| pcmSrc<sup>20+</sup>     | boolean        | No  | Yes  | Whether the playlist uses a PCM data source. **true** if the PCM data source used, **false** otherwise.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core<br>Due to device limitations, this parameter is temporarily unavailable and will be supported in future versions.|
| drmScheme<sup>12+</sup>     | string        | No  | Yes  | DRM scheme supported by the playlist. The value is the UUID of the DRM scheme.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core|
| duration     | number                  | No  | Yes  | Playback duration of the media asset in the playlist.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| startPosition     | number                  | No  | Yes  | Start position for playing the media asset in the playlist.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| creditsPosition     | number                  | No  | Yes  | Position for playing the closing credits of the media asset in the playlist.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| appName     | string                  | No  | Yes  | Name of the application provided by the playlist.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
|displayTags<sup>11+</sup>     | number | No  | Yes  | Display tags of the media asset. For details, see [DisplayTag](arkts-apis-avsession-e.md#displaytag11).<br>**System capability**: SystemCapability.Multimedia.AVSession.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
|launchClientData<sup>20+</sup> | string | No| Yes| Custom data sent by the application to the receiver during casting.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast<br>**Atomic service API**: This API can be used in atomic services since API version 20.|

## AVQueueItem<sup>10+</sup>

Describes the properties of an item in the playlist.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name        | Type                                       | Mandatory| Description                       |
| ------------ | ------------------------------------------ | ---- | --------------------------- |
| itemId       | number                                     | Yes  | ID of an item in the playlist.         |
| description  | [AVMediaDescription](#avmediadescription10)  | No  | Media metadata of the item in the playlist.  |

## AVPlaybackState<sup>10+</sup>

Describes the information related to the media playback state.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name        | Type                                 | Mandatory| Description    |
| ------------ | ------------------------------------- | ---- | ------- |
| state        | [PlaybackState](arkts-apis-avsession-e.md#playbackstate10)       | No  | Playback state.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| speed        | number                                | No  | Playback speed.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| position     | [PlaybackPosition](#playbackposition10) | No  | Playback position.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| bufferedTime | number                                | No  | Buffered time.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| loopMode     | [LoopMode](arkts-apis-avsession-e.md#loopmode10)                 | No  | Loop mode.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| isFavorite   | boolean                               | No  | Whether the media asset is favorited. The value **true** means that the media asset is favorited.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| activeItemId<sup>10+</sup> | number                  | No  | ID of the item that is being played.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| volume<sup>10+</sup> | number                  | No  | Media volume.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| maxVolume<sup>11+</sup> | number                    | No  | Maximum volume.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| muted<sup>11+</sup>     | boolean                   | No  | Mute status. The value **true** means the muted state.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| duration<sup>11+</sup>     | number                   | No  | Duration of the media asset.|
| videoWidth<sup>11+</sup>  | number                  | No  | Video width of the media asset, in px.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| videoHeight<sup>11+</sup> |  number                 | No  | Video height of the media asset, in px.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| extras<sup>10+</sup> | {[key: string]: Object}       | No  | Custom media data.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## PlaybackPosition<sup>10+</sup>

Describes the information related to the playback position.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name       | Type  | Mandatory| Description              |
| ----------- | ------ | ---- | ------------------ |
| elapsedTime | number | Yes  | Elapsed time, in ms.|
| updateTime  | number | Yes  | Updated time, in ms.|

## CallMetadata<sup>11+</sup>

Describes the properties related to call metadata.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name           | Type                     | Mandatory| Description              |
| --------------- |-------------------------| ---- |---------------------------------------------------------------------|
| name            | string                  | No   | Name (alias) of the caller.   |
| phoneNumber     | string                  | No   | Phone number of the caller.           |
| avatar          | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)          | No   | Profile picture of the caller.           |

## AVCallState<sup>11+</sup>

Describes the properties related to the call state.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name           | Type                     | Mandatory| Description              |
| --------------- |-------------------------  | ---- |---------------------------------------------------------------------|
| state           | [CallState](arkts-apis-avsession-e.md#callstate11)                 | Yes   | Call state.     |
| muted           | boolean                   | Yes   | Whether the microphone is muted.<br>**true**: The microphone is muted.<br>**false**: The microphone is not muted.|

## DeviceInfo<sup>10+</sup>

Describes the information related to the output device.

| Name      | Type          | Mandatory| Description                  |
| ---------- | -------------- | ---- | ---------------------- |
| castCategory   | AVCastCategory        | Yes  | Cast category.<br> **System capability**: SystemCapability.Multimedia.AVSession.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| deviceId   | string | Yes  | ID of the output device.<br> **System capability**: SystemCapability.Multimedia.AVSession.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| deviceName | string | Yes  | Name of the output device.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| deviceType | DeviceType | Yes  | Type of the output device.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| supportedProtocols<sup>11+</sup> | number | No  | Protocol supported by the output device. The default value is **TYPE_LOCAL**. For details, see [ProtocolType](arkts-apis-avsession-e.md#protocoltype11).<br> **System capability**: SystemCapability.Multimedia.AVSession.AVCast<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| supportedDrmCapabilities<sup>12+</sup> | Array\<string> | No  | DRM capability supported by the output device.<br> **System capability**: SystemCapability.Multimedia.AVSession.AVCast<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| manufacturer<sup>13+</sup> | string | No  | Manufacturer of the output device.<br> **System capability**: SystemCapability.Multimedia.AVSession.AVCast<br>**Atomic service API**: This API can be used in atomic services since API version 13.|
| modelName<sup>13+</sup> | string | No  | Model name of the output device.<br> **System capability**: SystemCapability.Multimedia.AVSession.AVCast<br>**Atomic service API**: This API can be used in atomic services since API version 13.|
| audioCapabilities<sup>20+</sup> | [AudioCapabilities](#audiocapabilities20) | No  | Audio capabilities supported by the output device.<br> **System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| supportedPullClients<sup>20+</sup> | Array\<number> | No| IDs of supported pull clients. (This field is returned only for devices that support 4K casting.)<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast<br>**Atomic service API**: This API can be used in atomic services since API version 20.|

## OutputDeviceInfo<sup>10+</sup>

Describes the information related to the output device.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name      | Type          | Mandatory| Description                  |
| ---------- | -------------- | ---- | ---------------------- |
| devices | Array\<DeviceInfo\> | Yes  | Output devices.   |

## AVControlCommand<sup>10+</sup>

Describes the command that can be sent to the session.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name     | Type                                             | Mandatory| Description          |
| --------- | ------------------------------------------------- | ---- | -------------- |
| command   | [AVControlCommandType](arkts-apis-avsession-t.md#avcontrolcommandtype10)     | Yes  | Command. The parameters carried in each command are different. For details, see [AVControlCommandType](arkts-apis-avsession-t.md#avcontrolcommandtype10).      |
| parameter | [LoopMode](arkts-apis-avsession-e.md#loopmode10) &#124; string &#124; number | No  | Parameters carried in the command.|

## AVCastPickerOptions<sup>14+</sup>

Describes the properties related to the semi-modal window that is started for casting purposes.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

| Name           | Type                     | Mandatory| Description              |
| --------------- |-------------------------| ---- |---------------------------------------------------------------------|
| sessionType         | [AVSessionType](arkts-apis-avsession-t.md#avsessiontype10)  | No  | Session type. The default value is **'audio'**.<br>Currently, only the **'audio'** and **'video'** session types are supported. If **'voice_call'** and **'video_call'** are passed, they are treated as the default value **'audio'**.           |

## AudioCapabilities<sup>20+</sup>

Describes the audio capabilities supported by the casting device.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

| Name           | Type                     | Read-Only| Optional| Description              |
| --------------- |-------------------------| ---- | ---- |---------------------------------------------------------------------|
| streamInfos            | Array\<[audio.AudioStreamInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiostreaminfo8)>                  | Yes   | No   | Audio capability parameters. |
