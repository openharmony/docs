# Enums
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## ProtocolType<sup>11+</sup>

Enumerates the protocol types supported by the remote device.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

| Name                       | Value  | Description        |
| --------------------------- | ---- | ----------- |
| TYPE_LOCAL<sup>11+</sup>      | 0    | Local device, which can be the built-in speaker or audio jack of the device, or an A2DP device.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| TYPE_CAST_PLUS_STREAM<sup>11+</sup>      | 2    | Cast+ stream mode, indicating that the media asset is being displayed on another device.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| TYPE_DLNA<sup>12+</sup>      | 4    | DLNA protocol, indicating that the media asset is being displayed on another device.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| TYPE_CAST_PLUS_AUDIO<sup>20+</sup>      | 8    | PCM mode, indicating that the media asset is being displayed on another device.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|

## CastDisplayState<sup>12+</sup>

Enumerates the states of the cast display.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.ExtendedDisplayCast

| Name                       | Value  | Description        |
| --------------------------- | ---- | ----------- |
| STATE_OFF      | 1    | The device is disconnected, and the extended screen does not display any content.   |
| STATE_ON      | 2    | The device is connected, and the extended screen is available.|

## ConnectionState<sup>10+</sup>

Enumerates the connection states.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name                       | Value  | Description        |
| --------------------------- | ---- | ----------- |
| STATE_CONNECTING      | 0    | The device is connecting.   |
| STATE_CONNECTED      | 1    | The device is connected.|
| STATE_DISCONNECTED      | 6    | The device is disconnected.|

## CallState<sup>11+</sup>

Enumerates the call states.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name                       | Value  | Description     |
| --------------------------  | ---- | -------- |
| CALL_STATE_IDLE             | 0    | The phone is idle.  |
| CALL_STATE_INCOMING         | 1    | The phone is ringing.    |
| CALL_STATE_ACTIVE           | 2    | The call is connected.    |
| CALL_STATE_DIALING          | 3    | The caller is dialing.    |
| CALL_STATE_WAITING          | 4    | The call is waiting for connection. |
| CALL_STATE_HOLDING          | 5    | The call is placed on hold.    |
| CALL_STATE_DISCONNECTING    | 6    | The call is disconnecting.    |

## DisplayTag<sup>11+</sup>

Enumerates the display tags of the media asset. The display tag is a special type identifier of the media audio source.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name                       | Value  | Description          |
| --------------------------  | ---- | ------------ |
| TAG_AUDIO_VIVID             | 1    | AUDIO VIVID  |

## DecoderType<sup>19+</sup>

Enumerates the decoding formats supported by the device.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

| Name                       | Value  | Description          |
| --------------------------  | ---- | ------------ |
| OH_AVCODEC_MIMETYPE_VIDEO_AVC      | "video/avc"  | VIDEO AVC. |
| OH_AVCODEC_MIMETYPE_VIDEO_HEVC     | "video/hevc" | VIDEO HEVC. |
| OH_AVCODEC_MIMETYPE_AUDIO_VIVID    | "audio/av3a" | AUDIO AV3A. |

## ResolutionLevel<sup>19+</sup>

Enumerates the resolution levels supported by the device.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

| Name                       | Value  | Description          |
| --------------------------  | ---- | ------------ |
| RESOLUTION_480P             | 0    | 480p (640 x 480 dpi).    |
| RESOLUTION_720P             | 1    | 720p (1280 x 720 dpi).   |
| RESOLUTION_1080P            | 2    | 1080p (1920 x 1080 dpi).  |
| RESOLUTION_2K               | 3    | 2K (2560 x 1440 dpi).  |
| RESOLUTION_4K               | 4    | 4K (4096 x 3840 dpi).  |

## AVCastCategory<sup>10+</sup>

Enumerates the cast categories.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

| Name                       | Value  | Description        |
| --------------------------- | ---- | ----------- |
| CATEGORY_LOCAL      | 0    | Local playback. The sound is played from the local device or a connected Bluetooth headset by default.    |
| CATEGORY_REMOTE      | 1    | Remote playback. The sound or images are played from a remote device. |

## DeviceType<sup>10+</sup>

Enumerates the output device types.

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name                       | Value  | Description        |
| --------------------------- | ---- | ----------- |
| DEVICE_TYPE_LOCAL      | 0    | Local device.<br> **System capability**: SystemCapability.Multimedia.AVSession.Core|
| DEVICE_TYPE_BLUETOOTH      | 10   | Bluetooth device.<br> **System capability**: SystemCapability.Multimedia.AVSession.Core|
| DEVICE_TYPE_TV      | 2    | TV.<br> **System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| DEVICE_TYPE_SMART_SPEAKER      | 3   | Speaker.<br> **System capability**: SystemCapability.Multimedia.AVSession.AVCast|

## LoopMode<sup>10+</sup>

Enumerates the loop modes of media playback.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name              | Value  | Description    |
| ------------------ | ---- | -------- |
| LOOP_MODE_SEQUENCE | 0    | Sequential playback.|
| LOOP_MODE_SINGLE   | 1    | Single loop.|
| LOOP_MODE_LIST     | 2    | Playlist loop.|
| LOOP_MODE_SHUFFLE  | 3    | Shuffle.|
| LOOP_MODE_CUSTOM<sup>11+</sup>   | 4    | Custom playback. |

## PlaybackState<sup>10+</sup>

Enumerates the media playback states.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name                       | Value  | Description        |
| --------------------------- | ---- | ----------- |
| PLAYBACK_STATE_INITIAL      | 0    | Initial.    |
| PLAYBACK_STATE_PREPARE      | 1    | Preparing. |
| PLAYBACK_STATE_PLAY         | 2    | Playing.    |
| PLAYBACK_STATE_PAUSE        | 3    | Paused.        |
| PLAYBACK_STATE_FAST_FORWARD | 4    | Fast-forwarding.        |
| PLAYBACK_STATE_REWIND       | 5    | Rewinding.        |
| PLAYBACK_STATE_STOP         | 6    | Stopped.        |
| PLAYBACK_STATE_COMPLETED    | 7    | Playback complete.    |
| PLAYBACK_STATE_RELEASED     | 8    | Released.        |
| PLAYBACK_STATE_ERROR        | 9    | Error.        |
| PLAYBACK_STATE_IDLE<sup>11+</sup>        | 10    | Idle.    |
| PLAYBACK_STATE_BUFFERING<sup>11+</sup>         | 11    | Buffering.  |

## AVSessionErrorCode<sup>10+</sup>

Enumerates the error codes used in the media session.

| Name                                  | Value     | Description                            |
| -------------------------------------- | ------- | ------------------------------- |
| ERR_CODE_SERVICE_EXCEPTION             | 6600101 | The session server is abnormal.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core|
| ERR_CODE_SESSION_NOT_EXIST             | 6600102 | The session does not exist.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core|
| ERR_CODE_CONTROLLER_NOT_EXIST          | 6600103 | The session controller does not exist.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core|
| ERR_CODE_REMOTE_CONNECTION_ERR         | 6600104 | Connection to the remote session fails.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core|
| ERR_CODE_COMMAND_INVALID               | 6600105 | The session command is invalid.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core|
| ERR_CODE_SESSION_INACTIVE              | 6600106 | The session is not activated.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core|
| ERR_CODE_MESSAGE_OVERLOAD              | 6600107 | Too many commands or messages.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core|
| ERR_CODE_DEVICE_CONNECTION_FAILED      | 6600108 | Connection to the device fails.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core|
| ERR_CODE_REMOTE_CONNECTION_NOT_EXIST   | 6600109 | The remote session does not exist.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.Multimedia.AVSession.Core|
| ERR_CODE_CAST_CONTROL_UNSPECIFIED<sup>13+</sup>    | 6611000 | An undefined error occurs during cast control.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_REMOTE_ERROR<sup>13+</sup>    | 6611001 | An unknown error occurs in the remote player.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_BEHIND_LIVE_WINDOW<sup>13+</sup>     | 6611002 | The playback is delayed.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_TIMEOUT<sup>13+</sup>     | 6611003 | The cast control process times out.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_RUNTIME_CHECK_FAILED<sup>13+</sup>      | 6611004 | The runtime check fails.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PLAYER_NOT_WORKING<sup>13+</sup>      | 6611100 | Cross-device data transfer is locked.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_SEEK_MODE_UNSUPPORTED<sup>13+</sup>      | 6611101 | The specified seek mode is not supported.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_ILLEGAL_SEEK_TARGET<sup>13+</sup>      | 6611102 | The seek position is out of the media range, or the current seek mode is not supported.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PLAY_MODE_UNSUPPORTED<sup>13+</sup>      | 6611103 |  The specified playback mode is not supported.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PLAY_SPEED_UNSUPPORTED<sup>13+</sup>      | 6611104 | The specified playback speed is not supported.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DEVICE_MISSING<sup>13+</sup>      | 6611105 | Operation failed because the media source device or media receiver device has been destroyed.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_INVALID_PARAM<sup>13+</sup>       | 6611106 | The parameter is invalid.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_NO_MEMORY<sup>13+</sup>       | 6611107 | Failed to allocate memory.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_OPERATION_NOT_ALLOWED<sup>13+</sup>       | 6611108 | The operation is not allowed.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_UNSPECIFIED<sup>13+</sup>       | 6612000 | An unspecified input/output error occurs.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_NETWORK_CONNECTION_FAILED<sup>13+</sup>       | 6612001 | Network connection fails.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_NETWORK_CONNECTION_TIMEOUT<sup>13+</sup>       | 6612002 | Network connection times out.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_INVALID_HTTP_CONTENT_TYPE <sup>13+</sup>      | 6612003 | The value of **Content-Type** is invalid.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_BAD_HTTP_STATUS<sup>13+</sup>        | 6612004 | The HTTP server returns an unexpected HTTP response status code.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_FILE_NOT_FOUND<sup>13+</sup>   | 6612005 | The file does not exist.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_NO_PERMISSION<sup>13+</sup>    | 6612006 | The input/output operation is not allowed.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_CLEARTEXT_NOT_PERMITTED<sup>13+</sup>    | 6612007 | The network security configuration of the application does not allow access to plaintext HTTP traffic.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_READ_POSITION_OUT_OF_RANGE<sup>13+</sup>        | 6612008 | Data is read from data binding.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_NO_CONTENTS<sup>13+</sup>     | 6612100 | No content can be played in the media.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_READ_ERROR<sup>13+</sup>        | 6612101 | The media cannot be read.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_CONTENT_BUSY<sup>13+</sup>         | 6612102 | The resource is in use.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_CONTENT_EXPIRED<sup>13+</sup>    | 6612103 | The input/output request content has expired.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_USE_FORBIDDEN<sup>13+</sup>    | 6612104 | The requested content cannot be played.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_NOT_VERIFIED<sup>13+</sup>     | 6612105 | The allowed content cannot be verified.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_EXHAUSTED_ALLOWED_USES<sup>13+</sup>     | 6612106 | The number of times that the content can be used has reached the maximum.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_NETWORK_PACKET_SENDING_FAILED<sup>13+</sup>   | 6612107 | An error occurs when the source device sends data packets to the destination device.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PARSING_UNSPECIFIED<sup>13+</sup>    | 6613000 | An unspecified content parsing error occurs.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PARSING_CONTAINER_MALFORMED<sup>13+</sup>    | 6613001 | The format of the media container bit stream is incorrectly parsed.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PARSING_MANIFEST_MALFORMED<sup>13+</sup>     | 6613002 | An error occurred when parsing the media list.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PARSING_CONTAINER_UNSUPPORTED<sup>13+</sup>   | 6613003 | The media container format or feature of the file is not supported.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PARSING_MANIFEST_UNSUPPORTED<sup>13+</sup>      | 6613004 | The feature is not supported in the media list.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DECODING_UNSPECIFIED<sup>13+</sup>     | 6614000 | An unspecified decoding error occurs.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DECODING_INIT_FAILED<sup>13+</sup>   | 6614001 | Initializing the decoder fails.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DECODING_QUERY_FAILED<sup>13+</sup>     | 6614002 | Querying the decoder fails.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DECODING_FAILED<sup>13+</sup>     | 6614003 | Decoding the media sample fails.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DECODING_FORMAT_EXCEEDS_CAPABILITIES<sup>13+</sup>    | 6614004 | The device cannot decode the current format.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DECODING_FORMAT_UNSUPPORTED<sup>13+</sup>    | 6614005 | The decoding format is not supported.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_AUDIO_RENDERER_UNSPECIFIED<sup>13+</sup>       | 6615000 | An unspecified audio renderer error occurs.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_AUDIO_RENDERER_INIT_FAILED <sup>13+</sup>     | 6615001 | Initializing the audio renderer fails.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_AUDIO_RENDERER_WRITE_FAILED<sup>13+</sup>    | 6615002 | Writing data to the audio renderer fails.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_UNSPECIFIED<sup>13+</sup>      | 6616000 | An unspecified DRM-related error occurs.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_SCHEME_UNSUPPORTED<sup>13+</sup>  | 6616001 | The device does not support the selected DRM scheme.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_PROVISIONING_FAILED<sup>13+</sup>   | 6616002 | Device configurations fail.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_CONTENT_ERROR<sup>13+</sup>  | 6616003 | The DRM-protected content cannot be played.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_LICENSE_ACQUISITION_FAILED<sup>13+</sup>    | 6616004 | Obtaining a license fails.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_DISALLOWED_OPERATION<sup>13+</sup>     | 6616005 | The license policy does not allow this operation.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_SYSTEM_ERROR<sup>13+</sup>     | 6616006 | An error occurs in the DRM system.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_DEVICE_REVOKED<sup>13+</sup>     | 6616007 | The DRM permission has been revoked from the device.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_LICENSE_EXPIRED<sup>13+</sup>   | 6616008 | The DRM license that is being loaded has expired.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_PROVIDE_KEY_RESPONSE_ERROR<sup>13+</sup>    | 6616100 | An error occurs when the DRM processes the key response.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**System capability**: SystemCapability.Multimedia.AVSession.AVCast|

## SkipIntervals<sup>11+</sup>

Enumerates the fast-forward or rewind intervals supported by the media session.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name                  | Value| Description                    |
| ---------------------- | -- | ----------------------- |
| SECONDS_10             | 10 | The time is 10 seconds.            |
| SECONDS_15             | 15 | The time is 15 seconds.            |
| SECONDS_30             | 30 | The time is 30 seconds.            |
