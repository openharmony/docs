# Enums

<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @chris2981-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=4b1a2f751fcd33c52248528ed8c23a9b2935126b translatedAt=2026-06-23T01:03:34.184Z pushedAt=2026-06-23T06:12:23.663Z -->

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## AVErrorCode<sup>9+</sup>

Enumerates the types of [Media error codes](errorcode-media.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name                                 | Value     | Description                                |
| :------------------------------------ | ------- | ------------------------------------ |
| AVERR_OK                              | 0       | The operation is successful.                      |
| AVERR_NO_PERMISSION                   | 201     | No permission to perform the operation.              |
| AVERR_INVALID_PARAMETER               | 401     | Invalid input parameter.                  |
| AVERR_UNSUPPORT_CAPABILITY            | 801     | Unsupported API.       |
| AVERR_NO_MEMORY                       | 5400101 | The system memory is insufficient or the number of services reaches the upper limit.|
| AVERR_OPERATE_NOT_PERMIT              | 5400102 | The operation is not allowed in the current state or you do not have the permission to perform the operation.|
| AVERR_IO                              | 5400103 | The data stream is abnormal.                |
| AVERR_TIMEOUT                         | 5400104 | The system or network response times out.            |
| AVERR_SERVICE_DIED                    | 5400105 | The service process is dead.                  |
| AVERR_UNSUPPORT_FORMAT                | 5400106 | The format of the media asset is not supported.      |
| AVERR_AUDIO_INTERRUPTED<sup>11+</sup> | 5400107 | The audio focus is interrupted.                 |
| AVERR_IO_HOST_NOT_FOUND<sup>14+</sup> | 5411001 | Failed to parse the server address or connect to the server.<br> **Atomic service API**: This API can be used in atomic services since API version 14.       |
| AVERR_IO_CONNECTION_TIMEOUT<sup>14+</sup> | 5411002 | Network connection times out.<br> **Atomic service API**: This API can be used in atomic services since API version 14.       |
| AVERR_IO_NETWORK_ABNORMAL<sup>14+</sup> | 5411003 | Data or links are abnormal due to network exceptions.<br> **Atomic service API**: This API can be used in atomic services since API version 14.       |
| AVERR_IO_NETWORK_UNAVAILABLE<sup>14+</sup> | 5411004 | The network is disabled.<br> **Atomic service API**: This API can be used in atomic services since API version 14.       |
| AVERR_IO_NO_PERMISSION<sup>14+</sup> | 5411005 | No access permission.<br> **Atomic service API**: This API can be used in atomic services since API version 14.       |
| AVERR_IO_REQUEST_DENIED<sup>14+</sup> | 5411006 | The client request parameter is incorrect or exceeds the processing capability.<br> **Atomic service API**: This API can be used in atomic services since API version 14.       |
| AVERR_IO_RESOURCE_NOT_FOUND<sup>14+</sup> | 5411007 | No network resource is available.<br> **Atomic service API**: This API can be used in atomic services since API version 14.       |
| AVERR_IO_SSL_CLIENT_CERT_NEEDED<sup>14+</sup> | 5411008 | The server fails to verify the client certificate.<br> **Atomic service API**: This API can be used in atomic services since API version 14.       |
| AVERR_IO_SSL_CONNECTION_FAILED<sup>14+</sup> | 5411009 | The SSL connection fails.<br> **Atomic service API**: This API can be used in atomic services since API version 14.       |
| AVERR_IO_SSL_SERVER_CERT_UNTRUSTED<sup>14+</sup> | 5411010 | The client fails to verify the server certificate.<br> **Atomic service API**: This API can be used in atomic services since API version 14.       |
| AVERR_IO_UNSUPPORTED_REQUEST<sup>14+</sup> | 5411011 | The request is not supported due to a network protocol error.<br> **Atomic service API**: This API can be used in atomic services since API version 14.       |
| AVERR_SEEK_CONTINUOUS_UNSUPPORTED<sup>18+</sup> | 5410002 | The seek operation in SEEK_CONTINUOUS mode is not supported.<br> **Atomic service API**: This API can be used in atomic services since API version 18.       |
| AVERR_SUPER_RESOLUTION_UNSUPPORTED<sup>18+</sup> | 5410003 | Super resolution is not supported.<br> **Atomic service API**: This API can be used in atomic services since API version 18.       |
| AVERR_SUPER_RESOLUTION_NOT_ENABLED<sup>18+</sup> | 5410004 | Super resolution is not enabled.<br> **Atomic service API**: This API can be used in atomic services since API version 18.       |
| AVERR_PARAMETER_OUT_OF_RANGE<sup>20+</sup> | 5400108 | The parameter value is out of range.<br> **Atomic service API**: This API can be used in atomic services since API version 20.       |
| AVERR_IO_CLEARTEXT_NOT_PERMITTED<sup>23+</sup> | 5411012 | HTTP plaintext access is not allowed.<br> **Atomic service API**: This API can be used in atomic services since API version 23.       |

## MediaType<sup>8+</sup>

Enumerates the media types.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name          | Value                   | Description                |
| -------------- | --------------------- | ------------------- |
| MEDIA_TYPE_UNSUPPORTED<sup>20+</sup> | -1                     | The media type is not supported.<br> **Atomic service API**: This API can be used in atomic services since API version 20.|
| MEDIA_TYPE_AUD | 0                     | Media.<br> **Atomic service API**: This API can be used in atomic services since API version 11.          |
| MEDIA_TYPE_VID | 1                     | Video.<br> **Atomic service API**: This API can be used in atomic services since API version 11.         |
| MEDIA_TYPE_SUBTITLE<sup>12+</sup> | 2    | Subtitle.<br> **Atomic service API**: This API can be used in atomic services since API version 12.|
| MEDIA_TYPE_ATTACHMENT<sup>20+</sup> | 3    | Attachment information (for example, an embedded external file).<br> **Atomic service API**: This API can be used in atomic services since API version 20.|
| MEDIA_TYPE_DATA<sup>20+</sup> | 4    | Data.<br> **Atomic service API**: This API can be used in atomic services since API version 20.|
| MEDIA_TYPE_TIMED_METADATA<sup>20+</sup> | 5    | Metadata with a timestamp.<br> **Atomic service API**: This API can be used in atomic services since API version 20.|
| MEDIA_TYPE_AUXILIARY<sup>20+</sup> | 6    | Auxiliary (track) information.<br> **Atomic service API**: This API can be used in atomic services since API version 20.|

## CodecMimeType<sup>8+</sup>

Enumerates the codec MIME types.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name        | Value                   | Description                    |
| ------------ | --------------------- | ------------------------ |
| VIDEO_H263   | 'video/h263'          | Video in H.263 format.     |
| VIDEO_AVC    | 'video/avc'           | Video in AVC format.<br> **Atomic service API**: This API can be used in atomic services since API version 22.|
| VIDEO_MPEG2  | 'video/mpeg2'         | Video in MPEG-2 format.    |
| VIDEO_MPEG4  | 'video/mp4v-es'         | Video in MPEG-4 format.    |
| VIDEO_VP8    | 'video/x-vnd.on2.vp8' | Video in VP8 format.      |
| VIDEO_HEVC<sup>11+</sup>   | 'video/hevc'          | Video in H.265 format.<br> **Atomic service API**: This API can be used in atomic services since API version 22.|
| AUDIO_AAC    | 'audio/mp4a-latm'     | Audio in MP4A-LATM format.<br> **Atomic service API**: This API can be used in atomic services since API version 12.|
| AUDIO_VORBIS | 'audio/vorbis'        | Audio in Vorbis format.   |
| AUDIO_FLAC   | 'audio/flac'          | Audio in FLAC format.     |
| AUDIO_MP3<sup>12+</sup>   | 'audio/mpeg'          | Audio in MPEG format.     |
| AUDIO_G711MU<sup>12+</sup>   | 'audio/g711mu'     | Audio in G.711 μ-law format.|
| AUDIO_AMR_NB<sup>18+</sup>   | 'audio/3gpp'     | Audio in AMR-NB format.|
| AUDIO_AMR_WB<sup>18+</sup>   | 'audio/amr-wb'     | Audio in AMR-WB format.|

## AacProfile<sup>22+</sup>

Enumerates the supported Advanced Audio Coding (AAC) formats.

**Atomic service API**: This API can be used in atomic services since API version 22.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

| Name        | Value                   | Description                       |
| ------------ | --------------------- | --------------------------- |
| AAC_LC       |     0                 | Standard AAC Low Complexity profile.       |
| AAC_HE       |     1                 | Standard AAC High Efficiency profile.       |
| AAC_HE_V2    |     2                 | AAC High Efficiency Version 2 profile (also known as HE-AAC v2).    |

## MediaDescriptionKey<sup>8+</sup>

Enumerates the media description keys.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name                    | Value             | Description                                                        |
| ------------------------ | --------------- | ------------------------------------------------------------ |
| MD_KEY_TRACK_INDEX       | 'track_index'   | Track index. The corresponding key value type is number.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MD_KEY_TRACK_TYPE        | 'track_type'    | Track type. The corresponding key value type is number. For details, see [MediaType](#mediatype8).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MD_KEY_CODEC_MIME        | 'codec_mime'    | Codec MIME type. The corresponding key value type is string.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MD_KEY_DURATION          | 'duration'      | Media duration. The corresponding key value type is number, measured in ms.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MD_KEY_BITRATE           | 'bitrate'       | Bit rate. The corresponding key value type is number, measured in bit/s. If the value is **undefined** or **0**, the bit rate is abnormal.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MD_KEY_WIDTH             | 'width'         | Video width. The corresponding key value type is number, measured in px.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MD_KEY_HEIGHT            | 'height'        | Video height. The corresponding key value type is number, measured in px.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MD_KEY_FRAME_RATE        | 'frame_rate'    | Video frame rate. The corresponding key value type is number, measured in frames per 100 seconds.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MD_KEY_AUD_CHANNEL_COUNT | 'channel_count' | Audio channel count. The corresponding key value type is number.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MD_KEY_AUD_SAMPLE_RATE   | 'sample_rate'   | Sample rate. The corresponding key value type is number, measured in Hz.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MD_KEY_AUD_SAMPLE_DEPTH<sup>12+</sup>  | 'sample_depth'  | Bit depth. The corresponding key value type is number, measured in bits.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| MD_KEY_LANGUAGE<sup>12+</sup>  | 'language'  | Subtitle language. The corresponding key value type is string.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| MD_KEY_TRACK_NAME<sup>12+</sup>  | 'track_name'  | Track name. The corresponding key value type is string.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| MD_KEY_HDR_TYPE<sup>12+</sup>  | 'hdr_type'  | Codec track type. The corresponding key value type is string.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| MD_KEY_ORIGINAL_WIDTH<sup>21+</sup>  | 'original_width'  | Original video width. The corresponding key value type is number, measured in px.<br>**Atomic service API**: This API can be used in atomic services since API version 21.|
| MD_KEY_ORIGINAL_HEIGHT<sup>21+</sup>  | 'original_height'  | Original video height. The corresponding key value type is number, measured in px.<br>**Atomic service API**: This API can be used in atomic services since API version 21.|
| MD_KEY_MIME_TYPE<sup>23+</sup>  | 'mime_type'  | MIME type of the track. The corresponding key value type is string. For audio and video tracks, the value is the same as that of **MD_KEY_CODEC_MIME**.<br>**Atomic service API**: This API can be used in atomic services since API version 23.|
| MD_KEY_REFERENCE_TRACK_IDS<sup>23+</sup>  | 'ref_track_ids'  | Reference relationships between this track and other tracks. The corresponding key value type is string, with values separated by commas (,).<br>**Atomic service API**: This API can be used in atomic services since API version 23.|
| MD_KEY_TRACK_REFERENCE_TYPE<sup>23+</sup>  | 'track_ref_type'  | Auxiliary type of this track when it acts as a reference track. The corresponding key value type is string.<br>**Atomic service API**: This API can be used in atomic services since API version 23.|

## FetchResult<sup>23+</sup>

Enumerates the results of obtaining thumbnails in batches.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

| Name                    | Value             | Description                                                        |
| ------------------------ | --------------- | ------------------------------------------------------------ |
| FETCH_FAILED             | 0               | Failed to obtain the thumbnail from the video. |
| FETCH_SUCCEEDED          | 1               | Succeeded in obtaining the thumbnail from the video. |
| FETCH_CANCELED           | 2               | The operation of obtaining the thumbnail from the video is canceled.|

## PlaybackInfoKey<sup>12+</sup>

Enumerates the playback description keys.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name                    | Value             | Description                                                        |
| ------------------------ | --------------- | ------------------------------------------------------------ |
| SERVER_IP_ADDRESS        | 'server_ip_address'    | IP address of the server. The corresponding key value type is string. |
| AVG_DOWNLOAD_RATE        | 'average_download_rate'| Average download rate. The corresponding key value type is number, measured in bit/s.|
| DOWNLOAD_RATE            | 'download_rate'        | Download rate in one second. The corresponding key value type is number, measured in bit/s.|
| IS_DOWNLOADING           | 'is_downloading'       | Download status. The corresponding key value type is number. The value **1** means that the downloaded is in progress, and **0** means that the download is complete.|
| BUFFER_DURATION          | 'buffer_duration'      | Duration that the cached data can be played. The corresponding key value type is number, measured in seconds.|

## PlaybackMetricsKey<sup>23+</sup>

Enumerates the playback metric keys.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

| Name                              | Value                                  | Description                                      |
| ---------------------------------- | ------------------------------------ | ------------------------------------------ |
| PREPARE_DURATION                   | 'prepare_duration'                   | Preparation duration, in milliseconds.          |
| RESOURCE_CONNECTION_DURATION       | 'resource_connection_duration'       | Duration for establishing a resource connection, in milliseconds.      |
| FIRST_FRAME_DECAPSULATION_DURATION | 'first_frame_decapsulation_duration' | Duration for decapsulating the first frame, in milliseconds.|
| TOTAL_PLAYING_TIME                 | 'total_playback_time'                | Total playback duration, in milliseconds.      |
| DOWNLOAD_REQUESTS_COUNT            | 'loading_requests_count'             | Total number of requests.<br> **Model restriction**: This API can be used only in the stage model.                        |
| TOTAL_DOWNLOAD_TIME                | 'total_loading_time'                 | Total loading duration, in milliseconds.      |
| TOTAL_DOWNLOAD_SIZE                | 'total_loading_bytes'                | Total loading size, in bytes.<br> **Model restriction**: This API can be used only in the stage model.            |
| STALLING_COUNT                     | 'stalling_count'                     | Total number of stalling times.                        |
| TOTAL_STALLING_TIME                | 'total_stalling_time'                | Total stalling duration, in milliseconds.      |
| LIP_ASYNC_COUNT                    | 'lip_async_count'                    | Total number of audio-video async errors.<br>**Since:** 26.0.0<br> **Model restriction:** This API can be used only in the stage model.       |
| TOTAL_LIP_ASYNC_TIME               | 'total_lip_async_time'               | Total duration of audio-video async errors, in milliseconds (ms).<br>**Since:** 26.0.0<br> **Model restriction:** This API can be used only in the stage model.       |

## BufferingInfoType<sup>8+</sup>

Enumerates the buffering event types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name             | Value  | Description                            |
| ----------------- | ---- | -------------------------------- |
| BUFFERING_START   | 1    | Buffering starts. When this event is triggered, the player pauses the playback.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                  |
| BUFFERING_END     | 2    | Buffering ends. When this event is triggered, the player resumes the playback.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                  |
| BUFFERING_PERCENT | 3    | Buffering percentage. You can use this event to monitor the buffering status.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                |
| CACHED_DURATION   | 4    |  Estimated duration, in ms, that the buffered data can be played. This event is triggered once the data change amount in the buffer exceeds 500 ms. You can use this event to develop a progress bar.<br>**Atomic service API**: This API can be used in atomic services since API version 12. |

## SoundInterruptMode<sup>23+</sup>

Enumerates the interruption modes of the audio files with the same ID in SoundPool.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

| Name                                 | Value     | Description                            |
| ----------------------------------- | ------- | --------------------------------- |
| NO_INTERRUPT                            | 0       | If the former audio file is not completely played, the latter audio file with the same ID does not interrupt the former audio file. Two audio files are played concurrently.           |
| SAME_SOUND_INTERRUPT                            | 1       | If the former audio file is not completely played, the latter audio file with the same ID interrupts the former audio file.           |

## StateChangeReason<sup>9+</sup>

Enumerates the reasons for the state transition of the AVPlayer or AVRecorder instance. The enum value is reported together with **state**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name      | Value  | Description                                                        |
| ---------- | ---- | ------------------------------------------------------------ |
| USER       | 1    | State transition triggered by user behavior. It happens when a user or the client calls an API.|
| BACKGROUND | 2    | State transition caused by background system behavior. For example, if an application does not have the permission of Media Controller, the application is forcibly suspended or stopped by the system when it switches to the background.|

## SeekMode<sup>8+</sup>

Enumerates the video playback seek modes, which can be passed in the **seek** API.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name          | Value  | Description                                                        |
| -------------- | ---- | ------------------------------------------------------------ |
| SEEK_NEXT_SYNC | 0    | Seeks to the next key frame at the specified position. You are advised to use this value for the rewind operation.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| SEEK_PREV_SYNC | 1    | Seeks to the previous key frame at the specified position. You are advised to use this value for the fast-forward operation.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| SEEK_CLOSEST<sup>12+</sup> | 2    | Seeks to the frame closest to the specified position. You are advised to use this value for accurate seek.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| SEEK_CONTINUOUS<sup>18+</sup> | 3    | Offers a smooth and fluid visual experience for seeking. Applications can use a progress bar component to continuously invoke the **seek** method, and the AVPlayer will update the video frames smoothly in response to these calls.<br>Applications can call [isSeekContinuousSupported](arkts-apis-media-AVPlayer.md#isseekcontinuoussupported18) to check whether the video source supports this seeking mode.<br>If the video source does not support this mode, calling **seek** will result in an **AVERR_SEEK_CONTINUOUS_UNSUPPORTED** error (see [AVErrorCode](#averrorcode9)), and the smoothness of frame updates will be compromised.<br>This seek mode does not trigger the [on('seekDone')](arkts-apis-media-AVPlayer.md#onseekdone9) event.<br>To exit this seeking mode, applications must call **seek(-1, SeekMode.SEEK_CONTINUOUS)** to end the seeking process.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|

## SwitchMode<sup>12+</sup>

Enumerates the **selectTrack** modes for video playback.

**SwitchMode** can be passed as a parameter through the **selectTrack** method. Currently, both DASH and HLS video tracks support this extended parameter. (HLS video tracks support this extended parameter since API version 26.0.0.)

**System capability**: SystemCapability.Multimedia.Media.Core

| Name          | Value  | Description                                                        |
| -------------- | ---- | ------------------------------------------------------------ |
| SMOOTH | 0    | Smooth playback is ensured after the switching. This mode has a delay, that is, the switching does not take effect immediately.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| SEGMENT | 1    | The playback starts from the start position of the current segment after the switching. In this mode, the switching takes effect immediately and repeated playback may occur.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| CLOSEST | 2    | The playback starts from the frame closest to the current playback time. In this mode, the switching takes effect immediately, and the playback is suspended for 3s to 5s and then resumed.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## PlaybackSpeed<sup>8+</sup>

Enumerates the video playback speeds, which can be passed in the **setSpeed** API.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

| Name                | Value  | Description                          |
| -------------------- | ---- | ------------------------------ |
| SPEED_FORWARD_0_75_X | 0    | Plays the video at 0.75 times the normal speed.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| SPEED_FORWARD_1_00_X | 1    | Plays the video at the normal speed.<br>**Atomic service API**: This API can be used in atomic services since API version 12.        |
| SPEED_FORWARD_1_25_X | 2    | Plays the video at 1.25 times the normal speed.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| SPEED_FORWARD_1_75_X | 3    | Plays the video at 1.75 times the normal speed.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| SPEED_FORWARD_2_00_X | 4    | Plays the video at 2.00 times the normal speed.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| SPEED_FORWARD_0_50_X<sup>12+</sup> | 5    | Plays the video at 0.50 times the normal speed.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| SPEED_FORWARD_1_50_X<sup>12+</sup> | 6    | Plays the video at 1.50 times the normal speed.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| SPEED_FORWARD_3_00_X<sup>13+</sup> | 7    | Plays the video at 3.00 times the normal speed.<br>**Atomic service API**: This API can be used in atomic services since API version 13.|
| SPEED_FORWARD_0_25_X<sup>12+</sup> | 8    | Plays the video at 0.25 times the normal speed.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| SPEED_FORWARD_0_125_X<sup>12+</sup> | 9    | Plays the video at 0.125 times the normal speed.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## VideoScaleType<sup>9+</sup>

Enumerates the video scale modes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

| Name                       | Value  | Description                                             |
| ----------------------------| ---- | ------------------------------------------------ |
| VIDEO_SCALE_TYPE_FIT        | 0    | Default mode. The video will be stretched to fit the window.               |
| VIDEO_SCALE_TYPE_FIT_CROP   | 1    | Maintains the video's aspect ratio, and scales to fill the shortest side of the window, with the longer side cropped.    |
| VIDEO_SCALE_TYPE_SCALED_ASPECT<sup>20+</sup> | 2    | Maintains the video's aspect ratio, and scales to fill the longer side of the window, with the shorter side centered and unfilled parts left black.<br>**Atomic service API**: This API can be used in atomic services since API version 20. |

## AudioSourceType<sup>9+</sup>

Enumerates the audio source types for video recording.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

| Name                     | Value  | Description                  |
| ------------------------- | ---- | ---------------------- |
| AUDIO_SOURCE_TYPE_DEFAULT | 0    | Default audio input source.|
| AUDIO_SOURCE_TYPE_MIC     | 1    | Microphone audio input source.<br> **Atomic service API**: This API can be used in atomic services since API version 12.|
| AUDIO_SOURCE_TYPE_VOICE_RECOGNITION<sup>12+</sup> | 2    | Audio source in speech recognition scenarios.|
| AUDIO_SOURCE_TYPE_VOICE_COMMUNICATION<sup>12+</sup>     | 7    | Voice communication source.|
| AUDIO_SOURCE_TYPE_VOICE_MESSAGE<sup>12+</sup> | 10    | Voice message source.|
| AUDIO_SOURCE_TYPE_CAMCORDER<sup>12+</sup>     | 13    | Audio source in camera recording scenarios.|

## VideoSourceType<sup>9+</sup>

Enumerates the video source types for video recording.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

| Name                         | Value  | Description                           |
| ----------------------------- | ---- | ------------------------------- |
| VIDEO_SOURCE_TYPE_SURFACE_YUV | 0    | The input surface carries raw data.|
| VIDEO_SOURCE_TYPE_SURFACE_ES  | 1    | The input surface carries ES data. |

## ContainerFormatType<sup>8+</sup>

Enumerates the container format types (CFTs).

**System capability**: SystemCapability.Multimedia.Media.Core

| Name       | Value   | Description                 |
| ----------- | ----- | --------------------- |
| CFT_MPEG_4  | 'mp4' | Video container format MP4.<br> **Atomic service API**: This API can be used in atomic services since API version 22.|
| CFT_MPEG_4A | 'm4a' | Audio container format M4A.<br> **Atomic service API**: This API can be used in atomic services since API version 12.|
| CFT_MP3<sup>12+</sup>  | 'mp3' | Audio container format MP3.|
| CFT_WAV<sup>12+</sup>  | 'wav' | Audio container format WAV.|
| CFT_AMR<sup>18+</sup>  | 'amr' | Audio container format AMR.|
| CFT_AAC<sup>20+</sup>  | 'aac' | Audio container format AAC. The default format is ADTS frame header.|

## FileGenerationMode<sup>12+</sup>

Enumerates the modes for creating media files.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

| Name                         | Value  | Description                           |
| ----------------------------- | ---- | ------------------------------- |
| APP_CREATE  | 0    | The application creates a media file in the sandbox.|
| AUTO_CREATE_CAMERA_SCENE  | 1    | The system creates a media file. The URL set by the application is ignored.|

## HdrType<sup>12+</sup>

Enumerates the HDR types.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name                     | Value  | Description                  |
| ------------------------- | ---- | ---------------------- |
| AV_HDR_TYPE_NONE          | 0    | No HDR.|
| AV_HDR_TYPE_VIVID         | 1    | HDR VIVID.|

## AVImageQueryOptions<sup>12+</sup>

Enumerates the relationship between the video frame and the time at which the video thumbnail is obtained.

The time passed in for obtaining the thumbnail may be different from the time of the video frame for which the thumbnail is actually obtained. Therefore, you need to specify their relationship.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

| Name                    | Value             | Description                                                        |
| ------------------------ | --------------- | ------------------------------------------------------------ |
| AV_IMAGE_QUERY_NEXT_SYNC       | 0   | The key frame at or next to the specified time is selected.                      |
| AV_IMAGE_QUERY_PREVIOUS_SYNC        | 1    | The key frame at or prior to the specified time is selected.|
| AV_IMAGE_QUERY_CLOSEST_SYNC        | 2    | The key frame closest to the specified time is selected.                |
| AV_IMAGE_QUERY_CLOSEST             | 3    | The frame (not necessarily a key frame) closest to the specified time is selected.|

## LoadingRequestError<sup>18+</sup>

Enumerates the reasons for data loading status changes.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name                | Value  | Description                          |
| -------------------- | ---- | ------------------------------ |
| LOADING_ERROR_SUCCESS | 0    | Returned by the client to indicate that the end of the resource.|
| LOADING_ERROR_NOT_READY | 1    | Returned by the client to indicate that the resource is not ready for access.|
| LOADING_ERROR_NO_RESOURCE | 2    | Returned by the client to indicate that the requested resource URL does not exist.|
| LOADING_ERROR_INVAID_HANDLE | 3    | Returned by the client to indicate that the ID of the requested resource handle (specified by **uuid**) is invalid.|
| LOADING_ERROR_ACCESS_DENIED | 4    | Returned by the client to indicate that the client does not have permission to request the resource.|
| LOADING_ERROR_ACCESS_TIMEOUT | 5    | Returned by the client to indicate that the access to the resource times out.|
| LOADING_ERROR_AUTHORIZE_FAILED | 6    | Returned by the client to indicate that authorization fails.|

## AVMimeTypes<sup>12+</sup>

Enumerates the MIME type, which is set by using [setMimeType](arkts-apis-media-MediaSource.md#setmimetype12).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name      | Value  | Description                                                        |
| ---------- | ---- | ------------------------------------------------------------ |
| APPLICATION_M3U8       | application/m3u8    | Local M3U8 file.|

## AVScreenCaptureRecordPreset<sup>12+</sup>

Enumerates the encoding and container formats used during screen capture.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

| Name                             | Value  | Description                                        |
| --------------------------------- | ---- | -------------------------------------------- |
| SCREEN_RECORD_PRESET_H264_AAC_MP4 | 0    | The H.264 video encoding format, AAC audio encoding format, and MP4 container format are used.|
| SCREEN_RECORD_PRESET_H265_AAC_MP4 | 1    | The H.265 video encoding format, AAC audio encoding format, and MP4 container format are used.|

## AVScreenCaptureStateCode<sup>12+</sup>

Enumerates the screen capture states used in callbacks.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

| Name                                    | Value  | Description                    |
| ---------------------------------------- | ---- | ------------------------ |
| SCREENCAPTURE_STATE_STARTED              | 0    | Screen capture is started.            |
| SCREENCAPTURE_STATE_CANCELED             | 1    | Screen capture is canceled.            |
| SCREENCAPTURE_STATE_STOPPED_BY_USER      | 2    | Screen capture is manually stopped by the user.    |
| SCREENCAPTURE_STATE_INTERRUPTED_BY_OTHER | 3    | Screen capture is interrupted by another screen capture.    |
| SCREENCAPTURE_STATE_STOPPED_BY_CALL      | 4    | Screen capture is interrupted by an incoming call.        |
| SCREENCAPTURE_STATE_MIC_UNAVAILABLE      | 5    | The microphone is unavailable during screen capture.|
| SCREENCAPTURE_STATE_MIC_MUTED_BY_USER    | 6    | The microphone is muted by the user.      |
| SCREENCAPTURE_STATE_MIC_UNMUTED_BY_USER  | 7    | The microphone is unmuted by the user.      |
| SCREENCAPTURE_STATE_ENTER_PRIVATE_SCENE  | 8    | The system enters a privacy page during screen capture.      |
| SCREENCAPTURE_STATE_EXIT_PRIVATE_SCENE   | 9    | The system exits a privacy page during screen capture.      |
| SCREENCAPTURE_STATE_STOPPED_BY_USER_SWITCHES   | 10    | Screen capture is interrupted by system user switchover.      |
| SCREENCAPTURE_STATE_PAUSED_BY_USER       | 11   | Screen capture is paused by the user.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|
| SCREENCAPTURE_STATE_RESUMED_BY_USER      | 12   | Screen capture is resumed by the user.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|
| SCREENCAPTURE_STATE_PAUSED_BY_APP        | 13   | Screen capture is paused by the application.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|
| SCREENCAPTURE_STATE_RESUMED_BY_APP       | 14   | Screen capture is resumed by the application.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|

## AVScreenCaptureFillMode<sup>18+</sup>

Enumerates the video fill modes during screen capture.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

| Name                             | Value  | Description                                        |
| --------------------------------- | ---- | -------------------------------------------- |
| PRESERVE_ASPECT_RATIO | 0    | Keeps the original aspect ratio, matching the aspect ratio of the physical screen.|
| SCALE_TO_FILL | 1    | Stretches the image to fit the specified dimensions.|

## PickerMode<sup>22+</sup>

Enumerates the display mode for the screen capture picker.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

| Name                             | Value  | Description                                        |
| --------------------------------- | ---- | -------------------------------------------- |
| WINDOW_ONLY | 0    | Displays only a list of windows.|
| SCREEN_ONLY | 1    | Displays only a list of screens.|
| SCREEN_AND_WINDOW | 2    | Displays both screens and windows.|
| APP_ONLY | 3    | Displays only applications.<br>**Since:** 26.0.0<br>**Model restriction:** This API can be used only in the stage model. |
| WINDOW_AND_APP | 4    | Displays both windows and applications.<br>**Since:** 26.0.0<br>**Model restriction:** This API can be used only in the stage model. |
| SCREEN_AND_APP | 5    | Displays both screens and applications.<br>**Since:** 26.0.0<br>**Model restriction:** This API can be used only in the stage model. |
| SCREEN_WINDOW_AND_APP | 6    | Displays screens, windows and applications.<br>**Since:** 26.0.0<br>**Model restriction:** This API can be used only in the stage model. |

## AVMetricsEventType<sup>23+</sup>

Enumerates the metric events supported by the media service.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name                      | Value  | Description                                  |
| -------------------------- | ---- | -------------------------------------- |
| AV_METRICS_EVENT_STALLING | 1    | Metric event indicating playback stalling.|

## PlaylistLoopMode

Enumerates the loop modes of playlist playback.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name                      | Value  | Description                                  |
| -------------------------- | ---- | -------------------------------------- |
| PLAYLIST_LOOP_MODE_ALL | 1    | Loop all.|
| PLAYLIST_LOOP_MODE_ONE | 2    | Repeat one.|
| PLAYLIST_LOOP_MODE_SHUFFLE | 3    | Shuffle.|
| PLAYLIST_LOOP_MODE_NONE | 4    | Loop off.|

## AudioEncoder<sup>(deprecated)</sup>

> **NOTE**
> This API is supported since API version 6 and deprecated since API version 8. You are advised to use [CodecMimeType](#codecmimetype8) instead.

Enumerates the audio encoding formats.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

| Name   | Value  | Description                                                        |
| ------- | ---- | ------------------------------------------------------------ |
| DEFAULT | 0    | Default encoding format.<br>This API is defined but not implemented yet.<br>Note: It is supported since API version 6 and deprecated since API version 8. You are advised to use **AUDIO_AAC** in [CodecMimeType](#codecmimetype8) instead.|
| AMR_NB  | 1    | AMR-NB.<br>This API is defined but not implemented yet.<br>Note: It is supported since API version 6 and deprecated since API version 8. You are advised to use **AUDIO_AMR_NB** in [CodecMimeType](#codecmimetype8) instead.|
| AMR_WB  | 2    | Adaptive Multi Rate-Wide Band Speech Codec (AMR-WB).<br>This API is defined but not implemented yet.<br>Note: It is supported since API version 6 and deprecated since API version 8. You are advised to use **AUDIO_AMR_WB** in [CodecMimeType](#codecmimetype8) instead.|
| AAC_LC  | 3    | Advanced Audio Coding Low Complexity (AAC-LC).<br>Note: It is supported since API version 6 and deprecated since API version 8. You are advised to use **AUDIO_AAC** in [CodecMimeType](#codecmimetype8) instead.|
| HE_AAC  | 4    | High-Efficiency Advanced Audio Coding (HE_AAC).<br>This API is defined but not implemented yet.<br>Note: It is supported since API version 6 and deprecated since API version 8. You are advised to use **AUDIO_AAC** in [CodecMimeType](#codecmimetype8) instead.|

## AudioOutputFormat<sup>(deprecated)</sup>

> **NOTE**
> This API is supported since API version 6 and deprecated since API version 8. You are advised to use [ContainerFormatType](#containerformattype8) instead.

Enumerates the audio output formats.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

| Name    | Value  | Description                                                        |
| -------- | ---- | ------------------------------------------------------------ |
| DEFAULT  | 0    | Default output format.<br>This API is defined but not implemented yet.<br>Note: It is supported since API version 6 and deprecated since API version 8. You are advised to select one from [ContainerFormatType](#containerformattype8) as required.|
| MPEG_4   | 2    | MPEG-4.<br>Note: It is supported since API version 6 and deprecated since API version 8. You are advised to use **CFT_MPEG_4** in [ContainerFormatType](#containerformattype8) instead.|
| AMR_NB   | 3    | AMR_NB.<br>This API is defined but not implemented yet.<br>Note: It is supported since API version 6 and deprecated since API version 8. You are advised to use **CFT_AMR** in [ContainerFormatType](#containerformattype8) instead. For the encoding format, use **AUDIO_AMR_NB** in [CodecMimeType](#codecmimetype8).|
| AMR_WB   | 4    | AMR_WB.<br>This API is defined but not implemented yet.<br>Note: It is supported since API version 6 and deprecated since API version 8. You are advised to use **CFT_AMR** in [ContainerFormatType](#containerformattype8) instead. For the encoding format, use **AUDIO_AMR_WB** in [CodecMimeType](#codecmimetype8).|
| AAC_ADTS | 6    | Audio Data Transport Stream (ADTS), which is a transport stream format of AAC-based audio.<br>Note: It is supported since API version 6 and deprecated since API version 8. You are advised to use **CFT_AAC** in [ContainerFormatType](#containerformattype8) instead.|

## MediaErrorCode<sup>(deprecated)</sup>

Enumerates the media error codes.

> **NOTE**
> This API is supported since API version 8 and deprecated since API version 11. You are advised to use [AVErrorCode](#averrorcode9) instead.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name                      | Value  | Description                                  |
| -------------------------- | ---- | -------------------------------------- |
| MSERR_OK                   | 0    | The operation is successful.                        |
| MSERR_NO_MEMORY            | 1    | Failed to allocate memory. The system may have no available memory.|
| MSERR_OPERATION_NOT_PERMIT | 2    | No permission to perform the operation.                |
| MSERR_INVALID_VAL          | 3    | Invalid input parameter.                    |
| MSERR_IO                   | 4    | An I/O error occurs.                      |
| MSERR_TIMEOUT              | 5    | The operation times out.                        |
| MSERR_UNKNOWN              | 6    | An unknown error occurs.                        |
| MSERR_SERVICE_DIED         | 7    | Invalid server.                      |
| MSERR_INVALID_STATE        | 8    | The operation is not allowed in the current state.  |
| MSERR_UNSUPPORTED          | 9    | The operation is not supported in the current version.      |