# Interfaces (Others)

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## AVFileDescriptor<sup>9+</sup>

Describes an audio and video file asset. It is used to specify a particular asset for playback based on its offset and length within a file.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name  | Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| fd     | number | Yes  | Resource handle, which is obtained by calling [resourceManager.getRawFd](../apis-localization-kit/js-apis-resource-manager.md#getrawfd9) or [fs.open](../apis-core-file-kit/js-apis-file-fs.md#fsopen).   |
| offset | number | No  | Resource offset, which needs to be entered based on the preset asset information. The default value is **0**. An invalid value causes a failure to parse audio and video assets.|
| length | number | No  | Resource length, which needs to be entered based on the preset asset information. The default value is the remaining bytes from the offset in the file. An invalid value causes a failure to parse audio and video assets.|

## AVDataSrcDescriptor<sup>10+</sup>

Defines the descriptor of an audio and video file, which is used in DataSource playback mode.<br>Use scenario: An application can create a playback instance and start playback before it finishes downloading the audio and video resources.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

| Name  | Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| fileSize     | number | Yes  | Size of the file to play, in bytes. The value **-1** indicates that the size is unknown. If **fileSize** is set to **-1**, the playback mode is similar to the live mode. In this mode, the **seek** and **setSpeed** operations cannot be performed, and the **loop** property cannot be set, indicating that loop playback is unavailable.|
| callback | (buffer: ArrayBuffer, length: number, pos?: number) => number | Yes  | Callback used to fill in data.<br>- Function: callback: (buffer: ArrayBuffer, length: number, pos?:number) => number;<br>- **buffer**: memory to be filled. The value is of the ArrayBuffer type. This parameter is mandatory.<br>- **length**: maximum length of the memory to be filled. The value is of the number type. This parameter is mandatory.<br>- **pos**: position of the data to be filled in the file. The value is of the number type. This parameter is optional. When **fileSize** is set to **-1**, this parameter cannot be used.<br>- Return value: length of the data filled, which is of the number type. If **-1** is returned, the end of stream is reached. If **-2** is returned, an unrecoverable error occurs.|

## SubtitleInfo<sup>12+</sup>

Describes the external subtitle information. When a subtitle update event is subscribed to, the information about the external subtitle is returned through a callback.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name  | Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| text | string | No | Text information of the subtitle.|
| startTime | number | No | Start time for displaying the subtitle, in milliseconds.|
| duration | number | No| Duration for displaying the subtitle, in milliseconds.|

## SeiMessage<sup>18+</sup>

Describes the information of an SEI message.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name  | Type  | Read-Only| Optional | Description                                                        |
| ------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| payloadType | number | No | No | Payload type of the SEI message.|
| payload | ArrayBuffer | No | No | Payload data of the SEI message.|

## MediaDescription<sup>8+</sup>

Defines media information in key-value mode.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name         | Type  | Mandatory| Description                                                        |
| ------------- | ------ | ---- | ------------------------------------------------------------ |
| [key: string] | Object | Yes  | For details about the key range supported and the object type and range of each key, see [MediaDescriptionKey](arkts-apis-media-e.md#mediadescriptionkey8).|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function printfItemDescription(obj: media.MediaDescription, key: string) {
  let property: Object = obj[key];
  console.info('audio key is ' + key); // Specify a key. For details about the keys, see MediaDescriptionKey.
  console.info('audio value is ' + property); // Obtain the value of the key. The value can be any type. For details about the types, see MediaDescriptionKey.
}

let avPlayer: media.AVPlayer | undefined = undefined;
media.createAVPlayer((err: BusinessError, player: media.AVPlayer) => {
  if(player != null) {
    avPlayer = player;
    console.info(`Succeeded in creating AVPlayer`);
    avPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
      if (arrList != null) {
        for (let i = 0; i < arrList.length; i++) {
          printfItemDescription(arrList[i], media.MediaDescriptionKey.MD_KEY_TRACK_TYPE);  // Print the MD_KEY_TRACK_TYPE value of each track.
        }
      } else {
        console.error(`Failed to get TrackDescription, error:${error}`);
      }
    });
  } else {
    console.error(`Failed to create AVPlayer, error message:${err.message}`);
  }
});
```

## PlaybackInfo<sup>12+</sup>

Defines the playback information in key-value pairs.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name         | Type  | Mandatory| Description                                                        |
| ------------- | ------ | ---- | ------------------------------------------------------------ |
| [key: string]| Object | Yes  | For details about the key range supported and the object type and range of each key, see [PlaybackInfoKey](arkts-apis-media-e.md#playbackinfokey12).|

## AVRecorderConfig<sup>9+</sup>

Describes the audio and video recording parameters.

The **audioSourceType** and **videoSourceType** parameters are used to distinguish audio-only recording, video-only recording, and audio and video recording. For audio-only recording, set only **audioSourceType**. For video-only recording, set only **videoSourceType**. For audio and video recording, set both **audioSourceType** and **videoSourceType**.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

| Name           | Type                                    | Mandatory| Description                                                        |
| --------------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| audioSourceType | [AudioSourceType](arkts-apis-media-e.md#audiosourcetype9)     | No  | Type of the audio source to record. This parameter is mandatory for audio recording.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| videoSourceType | [VideoSourceType](arkts-apis-media-e.md#videosourcetype9)     | No  | Type of the video source to record. This parameter is mandatory for video recording.                  |
| profile         | [AVRecorderProfile](#avrecorderprofile9) | Yes  | Recording profile. This parameter is mandatory.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| url             | string                                   | Yes  | Recording output URL: fd://xx (fd number).<br>![img](figures/en-us_image_url.png)<br>This parameter is mandatory.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
|fileGenerationMode<sup>12+</sup> | [FileGenerationMode](arkts-apis-media-e.md#filegenerationmode12)  | No  |  Mode for creating the file, which is used together with [on('photoAssetAvailable')](arkts-apis-media-AVRecorder.md#onphotoassetavailable12).|
| rotation<sup>(deprecated)</sup>        | number                                   | No  | Rotation angle of the recorded video. The value can be 0 (default), 90, 180, or 270 for MP4 videos.<br>This API is supported since API version 6 and deprecated since API version 12. You are advised to use **[AVMetadata](#avmetadata11).videoOrientation** instead. If both parameters are set, **[AVMetadata](#avmetadata11).videoOrientation** is used.    |
| location<sup>(deprecated)</sup>        | [Location](#location)                    | No  | Geographical location of the recorded video. By default, the geographical location information is not recorded.<br>This API is supported since API version 6 and deprecated since API version 12. You are advised to use **[AVMetadata](#avmetadata11).location** instead. If both parameters are set, **[AVMetadata](#avmetadata11).location** is used.|
| metadata<sup>12+</sup>        | [AVMetadata](#avmetadata11)              | No  | Metadata. For details, see [AVMetadata](#avmetadata11).                 |
| maxDuration<sup>18+</sup>        | number             | No  | Maximum recording duration, in seconds. The value range is [1, 2^31-1]. If an invalid value is provided, it is reset to the maximum allowed duration. Once the recording reaches the specified duration, it stops automatically and notifies via the stateChange callback that the recording has stopped: [AVRecorderState](arkts-apis-media-t.md#avrecorderstate9) = 'stopped', [StateChangeReason](arkts-apis-media-e.md#statechangereason9) = BACKGROUND.|

## AVRecorderProfile<sup>9+</sup>

Describes the audio and video recording profile.

> **NOTE**
>
> The following table lists the audio parameters. For details about each parameter, see the field description below.
>
> | Encoding Format | Container Format | Sampling Rate | Bit Rate | Audio Channel Count |
> |----|----|----|----|----|
> |AUDIO_AAC|MP4,M4A|[8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000, 64000, 88200, 96000]|[32000-500000]|[1-8]|
> |AUDIO_MP3|MP3|[8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000]|<br>- When the sampling rate is lower than 16000, the bit rate range is [8000, 16000, 32000, 40000, 48000, 56000, 64000].<br>- When the sampling rate ranges from 16000 to 32000, the bit rate range is [8000, 16000, 32000, 40000, 48000, 56000, 64000, 80000, 96000, 112000, 128000, 160000].<br>- When the sampling rate is greater than 32000, the bit rate range is [32000, 40000, 48000, 56000, 64000, 80000, 96000, 112000, 128000, 160000, 192000, 224000, 256000, 320000].|[1-2]|
> |AUDIO_G711MU|WAV|[8000]|[64000]|[1]|
> |AUDIO_AMR_NB<sup>18+</sup> |AMR|[8000]|[4750, 5150, 5900, 6700, 7400, 7950, 10200, 12200]|[1]|
> |AUDIO_AMR_WB<sup>18+</sup> |AMR|[16000]|[6600, 8850, 12650, 14250, 15850, 18250, 19850, 23050, 23850]|[1]|

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

| Name            | Type                                        | Mandatory| Description                                                        |
| ---------------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| audioBitrate     | number                                       | No  | Audio encoding bit rate. This parameter is mandatory for audio recording.<br>Supported bit rate ranges:<br>- Range [32000 - 500000] for the AAC encoding format.<br>- Range [64000] for the G.711 μ-law encoding format.<br>- Range [8000, 16000, 32000, 40000, 48000, 56000, 64000, 80000, 96000, 112000, 128000, 160000, 192000, 224000, 256000, 320000] for the MP3 encoding format.<br>When the MP3 encoding format is used, the mapping between the sampling rate and bit rate is as follows:<br>- When the sampling rate is lower than 16 kHZ, the bit rate range is [8000 - 64000].<br>- When the sampling rate ranges from 16 kHz to 32 kHz, the bit rate range is [8000 - 160000].<br>- When the sampling rate is greater than 32 kHz, the bit rate range is [32000 - 320000].<br>- Range [4750, 5150, 5900, 6700, 7400, 7950, 10200, 12200] for the AMR-NB encoding format.<br>- Range [6600, 8850, 12650, 14250, 15850, 18250, 19850, 23050, 23850] for the AMR-WB encoding format.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| audioChannels    | number                                       | No  | Number of audio channels. This parameter is mandatory for audio recording.<br>- Range [1 - 8] for the AAC encoding format.<br>- Range [1] for the G.711 μ-law encoding format.<br>- Range [1 - 2] for the MP3 encoding format.<br>- Range [1] for the AMR-NB and AMR-WB encoding formats.<br>**Atomic service API**: This API can be used in atomic services since API version 12.      |
| audioCodec       | [CodecMimeType](arkts-apis-media-e.md#codecmimetype8)             | No  | Audio encoding format. This parameter is mandatory for audio recording. Currently, AUDIO_AAC, AUDIO_MP3, AUDIO_G711MU, AUDIO_AMR_NB, and AUDIO_AMR_WB are supported.<br>**Atomic service API**: This API can be used in atomic services since API version 12.    |
| audioSampleRate  | number                                       | No  | Audio sampling rate. This parameter is mandatory for audio recording.<br>Supported sampling rate ranges:<br>- Range [8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000, 64000, 88200, 96000] for the AAC encoding format.<br>- Range [8000] for the G.711 μ-law encoding format.<br>- Range [8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000] for the MP3 encoding format.<br>- Range [8000] for the AMR-NB encoding format.<br>- Range [16000] for the AMR-WB encoding format.<br>Variable bit rate. The bit rate is for reference only.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| fileFormat       | [ContainerFormatType](arkts-apis-media-e.md#containerformattype8) | Yes  | Container format of a file. This parameter is mandatory. Currently, the MP4, M4A, MP3, WAV, AMR, and AAC container formats are supported. The default container format for AAC audio is ADTS frame format. The AUDIO_MP3 encoding format is not supported within the MP4 container format.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| videoBitrate     | number                                       | No  | Video encoding bit rate. This parameter is mandatory for video recording. The value range is [10000 - 100000000]. |
| videoCodec       | [CodecMimeType](arkts-apis-media-e.md#codecmimetype8)             | No  | Video encoding format. This parameter is mandatory for video recording. Currently, VIDEO_AVC is supported.|
| videoFrameWidth  | number                                       | No  | Width of a video frame. This parameter is mandatory for video recording. The value range is [176 - 4096].        |
| videoFrameHeight | number                                       | No  | Height of a video frame. This parameter is mandatory for video recording. The value range is [144 - 4096].        |
| videoFrameRate   | number                                       | No  | Video frame rate. This parameter is mandatory for video recording. The recommended value range is [1 - 60].            |
| isHdr<sup>11+</sup>            | boolean                        | No  | HDR encoding. This parameter is optional for video recording. The default value is **false**, and there is no requirement on the encoding format. When **isHdr** is set to **true**, the encoding format must be **video/hevc**.|
| enableTemporalScale<sup>12+</sup>            | boolean                        | No  | Whether temporal layered encoding is supported. This parameter is optional for video recording. The default value is **false**. If this parameter is set to **true**, some frames in the video output streams can be skipped without being encoded.|
| enableBFrame<sup>20+</sup>            | boolean                        | No  | Whether B-frame encoding is enabled for video recording. The value **true** means that B-frame encoding is enabled (valid only when the video encoding format is H.265 and the device hardware supports B-frame encoding), and **false** means the opposite.<br>This parameter is optional in video recording scenarios. The default value is **false**.|

## Location

Describes the geographical location of the recorded video.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name     | Type  | Mandatory| Description            |
| --------- | ------ | ---- | ---------------- |
| latitude  | number | Yes  | Latitude of the geographical location. The value range is [-90, 90].|
| longitude | number | Yes  | Longitude of the geographical location. The value range is [-180, 180].|

## EncoderInfo<sup>11+</sup>

Describes the information about an encoder.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

| Name      | Type                            | Readable| Writable| Description                                                        |
| ---------- | -------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| mimeType   | [CodecMimeType](arkts-apis-media-e.md#codecmimetype8) | Yes  | No  | MIME type of the encoder.                                          |
| type       | string                           | Yes  | No  | Encoder type. The value **audio** means an audio encoder, and **video** means a video encoder.        |
| bitRate    | [Range](#range11)                | Yes  | No  | Bit rate range of the encoder, with the minimum and maximum bit rates specified.                          |
| frameRate  | [Range](#range11)                | Yes  | No  | Video frame rate range, with the minimum and maximum frame rates specified. This parameter is available only for video encoders.         |
| width      | [Range](#range11)                | Yes  | No  | Video frame width range, with the minimum and maximum widths specified. This parameter is available only for video encoders.      |
| height     | [Range](#range11)                | Yes  | No  | Video frame height range, with the minimum and maximum heights specified. This parameter is available only for video encoders.      |
| channels   | [Range](#range11)                | Yes  | No  | Number of audio channels for the audio capturer, with the minimum and maximum numbers of audio channels specified. This parameter is available only for audio encoders.  |
| sampleRate | Array\<number>                    | Yes  | No  | Audio sampling rate, including all available audio sampling rates. The value depends on the encoder type, and this parameter is available only for audio encoders.|

## Range<sup>11+</sup>

Describes a range.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

| Name| Type  | Readable| Writable| Description        |
| ---- | ------ | ---- | ---- | ------------ |
| min  | number | Yes  | No  | Minimum value.|
| max  | number | Yes  | No  | Maximum value.|

## AVTranscoderConfig<sup>12+</sup>

Describes the video transcoding parameters.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

| Name           | Type                                   | Read-Only| Optional| Description                                                        |
| --------------- | ---------------------------------------- |---- | ---- | ------------------------------------------------------------ |
| audioBitrate | number     | No| Yes| Bit rate of the output audio, in bit/s. The value range is [1-500000]. The default value is 48 kbit/s.|
| audioCodec | [CodecMimeType](arkts-apis-media-e.md#codecmimetype8)     | No| Yes | Encoding format of the output audio. Currently, only AAC is supported. The default value is **AAC**.                  |
| fileFormat         | [ContainerFormatType](arkts-apis-media-e.md#containerformattype8) | No| No  | Container format of the output video file. Currently, only MP4 is supported.|
| videoBitrate         | number | No|  Yes | Bit rate of the output video, in bit/s. The default bit rate depends on the resolution of the output video. The default bit rate is 1 Mbit/s for the resolution in the range [240p, 480P], 2 Mbit/s for the range (480P,720P], 4 Mbit/s for the range (720P,1080P], and 8 Mbit/s for 1080p or higher.|
| videoCodec        | [CodecMimeType](arkts-apis-media-e.md#codecmimetype8) | No| Yes  | Encoding format of the output video. Currently, only AVC and HEVC are supported. If the source video is in HEVC format, the default value is **HEVC**. Otherwise, the default value is **AVC**.|
| videoFrameWidth        | number | No|  Yes  | Width of the output video frame, in px. The value range is [240 - 3840]. The default value is the width of the source video frame.|
| videoFrameHeight        | number | No|  Yes  | Height of the output video frame, in px. The value range is [240 - 2160]. The default value is the height of the source video frame.|
| enableBFrame<sup>20+</sup> | boolean | No|  Yes  | Whether B-frame encoding is enabled for transcoding. The value **true** means that B-frame encoding is enabled, and **false** means the opposite.<br>The actual support depends on the video encoding format and device chip capability. If the format or the device does not support B-frame encoding, the system will ignore B-frames and encode the video as if B-frame encoding was not enabled.|


## AVMetadata<sup>11+</sup>

Defines the audio and video metadata. Parameters that are not declared as read-only in [AVRecorderConfig](#avrecorderconfig9) can be used as input parameters for recording of [AVRecorder](arkts-apis-media-AVRecorder.md).

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

| Name  | Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| album     | string | No  | Title of the album. This parameter is read-only in the current version.    |
| albumArtist | string | No  | Artist of the album. This parameter is read-only in the current version.|
| artist | string | No  | Artist of the media asset. This parameter is read-only in the current version.|
| author | string | No  | Author of the media asset. This parameter is read-only in the current version.|
| dateTime | string | No  | Time when the media asset is created. This parameter is read-only in the current version.|
| dateTimeFormat | string | No  | Time when the media asset is created. The value is in the YYYY-MM-DD HH:mm:ss format. This parameter is read-only in the current version.|
| composer | string | No  | Composer of the media asset. This parameter is read-only in the current version.|
| duration | string | No  | Duration of the media asset. This parameter is read-only in the current version.|
| genre | string | No  | Type or genre of the media asset.|
| hasAudio | string | No  | Whether the media asset contains audio. This parameter is read-only in the current version.|
| hasVideo | string | No  | Whether the media asset contains a video. This parameter is read-only in the current version.|
| mimeType | string | No  | MIME type of the media asset. This parameter is read-only in the current version.|
| trackCount | string | No  | Number of tracks of the media asset. This parameter is read-only in the current version.|
| sampleRate | string | No  | Audio sampling rate, in Hz. This parameter is read-only in the current version.|
| title | string | No  | Title of the media asset. This parameter is read-only in the current version. This parameter is read-only in the current version.|
| videoHeight | string | No  | Video height, in px. This parameter is read-only in the current version.|
| videoWidth | string | No  | Video width, in px. This parameter is read-only in the current version.|
| videoOrientation | string | No  | Video rotation direction, in degrees.|
| hdrType<sup>12+</sup> | [HdrType](arkts-apis-media-e.md#hdrtype12) | No  | HDR type of the media asset. This parameter is read-only in the current version.|
| location<sup>12+</sup> | [Location](#location) | No| Geographical location of the media asset.|
| customInfo<sup>12+</sup> | Record<string, string> | No| Custom key-value mappings obtained from **moov.meta.list**.|
| tracks<sup>20+</sup> | Array\<[MediaDescription](#mediadescription8)> | No| Track information of the media asset. This parameter is read-only in the current version.|

> **NOTE**
>
> The following table lists the values of [MediaDescriptionKey](arkts-apis-media-e.md#mediadescriptionkey8) supported by AVMetadata.tracks.
> 
> | Name | Value | Applicable Track Type |
> | -------- | --------------------|------------------------ |
> | MD_KEY_TRACK_INDEX | 'track_index' | All |
> | MD_KEY_TRACK_TYPE | 'track_type' | All |
> | MD_KEY_CODEC_MIME | 'codec_mime' | Audio, video |
> | MD_KEY_WIDTH | 'width' | Video |
> | MD_KEY_HEIGHT | 'height' | Video |
> | MD_KEY_FRAME_RATE | 'frame_rate' | Video |
> | MD_KEY_AUD_CHANNEL_COUNT | 'channel_count' | Audio |
> | MD_KEY_AUD_SAMPLE_RATE | 'ample_rate' | Audio |
> | MD_KEY_HDR_TYPE | 'hdr_type' | Video |

## PixelMapParams<sup>12+</sup>

Defines the format parameters of the video thumbnail to be obtained.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

| Name  | Type  | Readable| Writable| Description                                                                           |
|--------|--------|------|------|---------------------------------------------------------------------------------|
| width  | number | Yes  | Yes  | Width of the thumbnail. The value must be greater than 0 and less than or equal to the width of the original video. Otherwise, the returned thumbnail will not be scaled.|
| height | number | Yes  | Yes  | Height of the thumbnail. The value must be greater than 0 and less than or equal to the height of the original video. Otherwise, the returned thumbnail will not be scaled.|

## OutputSize<sup>20+</sup>

Describes the output size of the video thumbnail fetched.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

| Name  | Type  | Read-Only| Optional| Description                                                        |
| ------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| width  | number | No  | Yes  | Width of the thumbnail.<br>- If this parameter is set to a value less than 0, the width will be the original video width.<br>- If the value is **0** or is not assigned, the scaling ratio is the same as the height ratio.|
| height | number | No  | Yes  | Height of the thumbnail.<br>- If this parameter is set to a value less than 0, the height will be the original video height.<br>- If the value is **0** or is not assigned, the scaling ratio is the same as the width ratio.|

## MediaStream<sup>19+</sup>

Defines the media stream data information.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| url     | string | No  | No  | URL of the media resource. Only HTTP and HTTPS are supported.                                                |
| width   | number | No  | No  | Video width of the media resource. If the video width is unknown, set it to **0**. In this case, [PlaybackStrategy](#playbackstrategy12) cannot be used for optimal matching.|
| height  | number | No  | No  | Video height of the media resource. If the video width is unknown, set it to **0**. In this case, [PlaybackStrategy](#playbackstrategy12) cannot be used for optimal matching.|
| bitrate | number | No  | No  | Bit rate of media resources, in bit/s.                                       |

## MediaSourceLoader<sup>18+</sup>

Defines a media data loader, which needs to be implemented by applications.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| open | [SourceOpenCallback](arkts-apis-media-t.md#sourceopencallback18) | Yes | Callback function implemented by applications to handle resource open requests.|
| read | [SourceReadCallback](arkts-apis-media-t.md#sourcereadcallback18) | Yes | Callback function implemented by applications to handle resource read requests.|
| close | [SourceCloseCallback](arkts-apis-media-t.md#sourceclosecallback18) | Yes | Callback function implemented by applications to handle resource close requests.|

**Example**

```ts
import HashMap from '@ohos.util.HashMap';

let headers: Record<string, string> = {"User-Agent" : "User-Agent-Value"};
let mediaSource : media.MediaSource = media.createMediaSourceWithUrl("http://xxx",  headers);
let uuid: number = 1;
let requests: HashMap<number, media.MediaSourceLoadingRequest> = new HashMap();
let mediaSourceLoader: media.MediaSourceLoader = {
  open: (request: media.MediaSourceLoadingRequest) => {
    console.log(`Opening resource: ${request.url}`);
    // Open the resource and return a unique handle, ensuring the mapping between the UUID and request.
    uuid += 1;
    requests.set(uuid, request);
    return uuid;
  },
  read: (uuid: number, requestedOffset: number, requestedLength: number) => {
    console.log(`Reading resource with handle ${uuid}, offset: ${requestedOffset}, length: ${requestedLength}`);
    // Check whether the UUID is valid and store the read request. Avoid blocking the request while pushing data and header information.
  },
  close: (uuid: number) => {
    console.log(`Closing resource with handle ${uuid}`);
    // Clear resources related to the current UUID.
    requests.remove(uuid);
  }
};

mediaSource.setMediaResourceLoaderDelegate(mediaSourceLoader);
let playStrategy : media.PlaybackStrategy = {
  preferredBufferDuration: 20,
};

async function setupPlayer() {
  let player = await media.createAVPlayer();
  player.setMediaSource(mediaSource, playStrategy);
}
```

## PlaybackStrategy<sup>12+</sup>

Describes the playback strategy.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| preferredWidth| number | No  | Preferred width, in px. The value is an integer greater than 0, for example, 1080.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| preferredHeight | number | No  | Preferred height, in px. The value is an integer greater than 0, for example, 1920.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| preferredBufferDuration | number | No | Preferred buffer duration, in seconds. The value ranges from 1 to 20.<br>For details, see [Minimizing Stuttering in Online Video Playback](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-online-video-playback-lags-practice).<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| preferredHdr | boolean | No  | Whether HDR is preferred. The value **true** means that HDR is preferred, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| enableSuperResolution<sup>18+</sup> | boolean | No  | Whether to enable super resolution. The value **true** means to enable it, and **false** (default) means to disable it.<br>If super resolution is disabled, super resolution APIs cannot be called. If super resolution is enabled, the default target resolution is 1920 x 1080, in px.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| showFirstFrameOnPrepare<sup>17+</sup> | boolean | No  | Whether to show the first frame after **prepare** is called. The value **true** means to show the first frame after **prepare** is called, and **false** means the opposite. The default value is **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 17.|
| mutedMediaType | [MediaType](arkts-apis-media-e.md#mediatype8) | No| Type of the media to mute.<br>From API version 12 to 19, only **MediaType.MEDIA_TYPE_AUD** can be set. Starting from API version 20, **MediaType.MEDIA_TYPE_VID** is added.|
| preferredAudioLanguage<sup>13+</sup> | string | No| Preferred audio track language. Set this parameter based on service requirements in DASH scenarios. In non-DASH scenarios, this parameter is not supported, and you are advised to retain the default value.<br>**Atomic service API**: This API can be used in atomic services since API version 13.|
| preferredSubtitleLanguage<sup>13+</sup> | string | No| Preferred subtitle language. Set this parameter based on service requirements in DASH scenarios. In non-DASH scenarios, this parameter is not supported, and you are advised to retain the default value.<br>**Atomic service API**: This API can be used in atomic services since API version 13.|
| preferredBufferDurationForPlaying<sup>18+</sup> | number | No| Preferred buffer duration for playback. The playback starts once the buffering time exceeds this value. The value ranges from 0 to 20, in seconds.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| thresholdForAutoQuickPlay<sup>18+</sup> | number | No| Thread for starting smart frame catching, in seconds. The value must be greater than or equal to 2s and greater than **preferredBufferDurationForPlaying**. The default value is 5s.<br>You can use the playback strategy to maintain the real-time quality of live streams by adjusting the smart frame-catch threshold. For FLV live streams, you can set this parameter based on service requirements. This parameter is not supported for non-FLV live streams yet. Fluctuations in network conditions can cause the player to build up a lot of data over time. The player periodically checks the gap between the current playback time and the timestamp of the latest frame in the cache. If this gap is too big, the player starts catching up at 1.2x speed. The [speedDone](arkts-apis-media-AVPlayer.md#onspeeddone9) event is invoked with a value of 100, indicating that smart frame catching has started successfully. Once the gap falls below **preferredBufferDurationForPlaying**, the player stops catching up and resumes the normal playback speed.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| keepDecodingOnMute<sup>20+</sup>  | boolean | No| Whether the decoder continues to run when the video media is muted, which helps in quickly opening the media. Currently, this feature is available only for videos. The default value is **false**, indicating that the decoder stops running when the media is muted, reducing power consumption.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|

## AVScreenCaptureStrategy<sup>20+</sup>

Describes the screen capture strategy.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

| Name                 | Type   | Read-Only| Optional| Description                |
| --------------------- | ------- | --- | --- | -------------------- |
| keepCaptureDuringCall | boolean | No| Yes | Whether to keep screen capture during a cellular call.|
| enableBFrame | boolean | No| Yes| Whether to enable B-frame encoding for screen capture. The value **true** means to enable B-frame encoding, and **false** means the opposite. The default value is **false**.<br>If the chip platform does not support B-frame encoding, videos without B-frames are recorded properly, and no error is returned.|

## AVScreenCaptureRecordConfig<sup>12+</sup>

Defines the screen capture parameters.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

| Name             | Type                                                        | Mandatory| Description                                                        |
| ----------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| fd                | number                                                       | Yes  | FD of the file output.                                          |
| frameWidth        | number                                                       | No  | Video width, in px. The default value varies according to the display in use.|
| frameHeight       | number                                                       | No  | Video height, in px. The default value varies according to the display in use.|
| videoBitrate      | number                                                       | No  | Video bit rate. The default value is **10000000**.                            |
| audioSampleRate   | number                                                       | No  | Audio sampling rate. This value is used for both internal capture and external capture (using microphones). Only **48000** (default value) and **16000** are supported.|
| audioChannelCount | number                                                       | No  | Number of audio channels. This value is used for both internal capture and external capture (using microphones). Only **1** and **2** (default) are supported.|
| audioBitrate      | number                                                       | No  | Audio bit rate. This value is used for both internal capture and external capture (using microphones). The default value is **96000**.|
| preset            | [AVScreenCaptureRecordPreset](arkts-apis-media-e.md#avscreencapturerecordpreset12) | No  | Encoding and container format used. The default value is **SCREEN_RECORD_PRESET_H264_AAC_MP4**.|
| displayId<sup>15+</sup>            | number | No  | ID of the display used for screen capture. By default, the main screen is captured.|
| fillMode<sup>18+</sup>            | [AVScreenCaptureFillMode](arkts-apis-media-e.md#avscreencapturefillmode18)| No  | Video fill mode during screen capture.|
| strategy<sup>20+</sup>            | [AVScreenCaptureStrategy](#avscreencapturestrategy20)| No  | Screen capture strategy.|

## AudioRecorderConfig<sup>(deprecated)</sup>

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVRecorderConfig](#avrecorderconfig9) instead.

Describes audio recording configurations.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

| Name                               | Type                                        | Mandatory| Description                                                        |
| ----------------------------------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| audioEncoder                        | [AudioEncoder](arkts-apis-media-e.md#audioencoderdeprecated)                | No  | Audio encoding format. The default value is **AAC_LC**.<br>**Note**: This parameter is deprecated since API version 8. Use **audioEncoderMime** instead.|
| audioEncodeBitRate                  | number                                       | No  | Audio encoding bit rate. The default value is **48000**.                             |
| audioSampleRate                     | number                                       | No  | Audio sampling rate. The default value is **48000**.<br>Variable bit rate. The bit rate is for reference only.                             |
| numberOfChannels                    | number                                       | No  | Number of audio channels. The default value is **2**.                                 |
| format                              | [AudioOutputFormat](arkts-apis-media-e.md#audiooutputformatdeprecated)      | No  | Audio output format. The default value is **MPEG_4**.<br>**Note**: This parameter is deprecated since API version 8. Use **fileFormat** instead.|
| location                            | [Location](#location)                        | No  | Geographical location of the recorded audio.                                        |
| uri                                 | string                                       | Yes  | Audio output URI. Supported: fd://xx (fd number)<br>![](figures/en-us_image_url.png) <br>The file must be created by the caller and granted with proper permissions.|
| audioEncoderMime<sup>8+</sup>       | [CodecMimeType](arkts-apis-media-e.md#codecmimetype8)             | No  | Container encoding format.                                              |
| fileFormat<sup>8+</sup>             | [ContainerFormatType](arkts-apis-media-e.md#containerformattype8) | No  | Audio encoding format.                                              |
