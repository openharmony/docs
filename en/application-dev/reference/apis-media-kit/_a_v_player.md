# AVPlayer


## Overview

The AVPlayer module provides APIs related to media playback.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [avplayer.h](avplayer_8h.md) | Declares the AVPlayer APIs. You can use the native AVPlayer APIs to play a media asset. | 
| [avplayer_base.h](avplayer__base_8h.md) | Declares the structs and enums of the AVPlayer. | 


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [AVPlayerCallback](_a_v_player_callback.md) | (Deprecated) Contains the set of the **OH_AVPlayerOnInfo** and **OH_AVPlayerOnInfo** callback function pointers. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [MediaKeySession](#mediakeysession) [MediaKeySession](#mediakeysession) | Defines a struct for the media key session. | 
| typedef struct [DRM_MediaKeySystemInfo](#drm_mediakeysysteminfo) [DRM_MediaKeySystemInfo](#drm_mediakeysysteminfo) | Defines a struct for the media key system information. | 
| typedef void(\* [Player_MediaKeySystemInfoCallback](#player_mediakeysysteminfocallback)) (OH_AVPlayer \*player, [DRM_MediaKeySystemInfo](#drm_mediakeysysteminfo) \*mediaKeySystemInfo) | Defines the callback invoked when media key system information of the AVPlayer is updated. | 
| typedef enum [AVPlayerState](#avplayerstate-1) [AVPlayerState](#avplayerstate) | Defines an enum for the AVPlayer states. | 
| typedef enum [AVPlayerSeekMode](#avplayerseekmode-1) [AVPlayerSeekMode](#avplayerseekmode) | Defines an enum for the seek modes of the AVPlayer. | 
| typedef enum [AVPlaybackSpeed](#avplaybackspeed-1) [AVPlaybackSpeed](#avplaybackspeed) | Defines an enum for the playback speeds of the AVPlayer. | 
| typedef enum [AVPlayerOnInfoType](#avplayeroninfotype-1) [AVPlayerOnInfoType](#avplayeroninfotype) | Defines an enum for the types of messages received by the AVPlayer. | 
| typedef enum [AVPlayerBufferingType](#avplayerbufferingtype-1) [AVPlayerBufferingType](#avplayerbufferingtype) | Defines an enum for the types of buffer messages of the AVPlayer. | 
| typedef void(\*[OH_AVPlayerOnInfo](#oh_avplayeroninfo)) (OH_AVPlayer \*player, [AVPlayerOnInfoType](#avplayeroninfotype) type, int32_t extra) | (Deprecated) Defines the callback invoked when the AVPlayer receives a message. | 
| typedef void(\*[OH_AVPlayerOnInfoCallback](#oh_avplayeroninfocallback)) (OH_AVPlayer \*player, [AVPlayerOnInfoType](#avplayeroninfotype) type, OH_AVFormat \*infoBody, void \*userData) | Defines the callback invoked when the AVPlayer receives a message. If this callback is successfully set, the **OH_AVPlayerOnInfo** function will not be invoked. | 
| typedef void(\* [OH_AVPlayerOnError](#oh_avplayeronerror)) (OH_AVPlayer \*player, int32_t errorCode, const char \*errorMsg) | (Deprecated) Defines the callback invoked when an error occurs in the AVPlayer. This type is available in API version 9 or later. | 
| typedef void(\* [OH_AVPlayerOnErrorCallback](#oh_avplayeronerrorcallback)) (OH_AVPlayer \*player, int32_t errorCode, const char \*errorMsg, void \*userData) | Defines the callback invoked when an error occurs in the AVPlayer. If this callback is successfully set, the **OH_AVPlayerOnError** function will not be invoked. | 
| typedef struct [AVPlayerCallback](_a_v_player_callback.md) [AVPlayerCallback](#avplayercallback) | (Deprecated) Contains the set of the **OH_AVPlayerOnInfo** and **OH_AVPlayerOnInfo** callback function pointers. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [AVPlayerState](#avplayerstate-1) {<br>AV_IDLE = 0, <br>AV_INITIALIZED = 1, <br>AV_PREPARED = 2, <br>AV_PLAYING = 3,<br>AV_PAUSED = 4, <br>AV_STOPPED = 5, <br>AV_COMPLETED = 6, <br>AV_RELEASED = 7,<br>AV_ERROR = 8<br>} | Enumerates the AVPlayer states.| 
| [AVPlayerSeekMode](#avplayerseekmode) { <br>AV_SEEK_NEXT_SYNC = 0, <br>AV_SEEK_PREVIOUS_SYNC, <br>AV_SEEK_CLOSEST = 2<br>} | Enumerates the seek modes of the AVPlayer.| 
| [AVPlaybackSpeed](#avplaybackspeed-1) {<br>AV_SPEED_FORWARD_0_75_X, <br>AV_SPEED_FORWARD_1_00_X, <br>AV_SPEED_FORWARD_1_25_X, <br> AV_SPEED_FORWARD_1_75_X,<br>AV_SPEED_FORWARD_2_00_X, <br>AV_SPEED_FORWARD_0_50_X, <br>AV_SPEED_FORWARD_1_50_X<br>} | Enumerates the playback speeds of the AVPlayer. | 
| [AVPlayerOnInfoType](#avplayeroninfotype-1) {<br>AV_INFO_TYPE_SEEKDONE = 0, <br>AV_INFO_TYPE_SPEEDDONE = 1, <br>AV_INFO_TYPE_BITRATEDONE = 2, <br>AV_INFO_TYPE_EOS = 3,<br>AV_INFO_TYPE_STATE_CHANGE = 4, <br>AV_INFO_TYPE_POSITION_UPDATE = 5, <br>AV_INFO_TYPE_MESSAGE = 6, <br>AV_INFO_TYPE_VOLUME_CHANGE = 7,<br>AV_INFO_TYPE_RESOLUTION_CHANGE = 8, <br>AV_INFO_TYPE_BUFFERING_UPDATE = 9, <br>AV_INFO_TYPE_BITRATE_COLLECT = 10, <br>AV_INFO_TYPE_INTERRUPT_EVENT = 11,<br>AV_INFO_TYPE_DURATION_UPDATE = 12, <br>AV_INFO_TYPE_IS_LIVE_STREAM = 13, <br>AV_INFO_TYPE_TRACKCHANGE = 14, <br>AV_INFO_TYPE_TRACK_INFO_UPDATE = 15,<br>AV_INFO_TYPE_SUBTITLE_UPDATE = 16, AV_INFO_TYPE_AUDIO_OUTPUT_DEVICE_CHANGE = 17<br>} | Enumerates the types of messages received by the AVPlayer.| 
| [AVPlayerBufferingType](#avplayerbufferingtype-1) { <br>AVPLAYER_BUFFERING_START = 1, <br>AVPLAYER_BUFFERING_END, <br>AVPLAYER_BUFFERING_PERCENT, <br>AVPLAYER_BUFFERING_CACHED_DURATION <br>} | Enumerates the types of buffer messages of the AVPlayer. | 


### Functions

| Name| Description| 
| -------- | -------- |
| OH_AVPlayer \*[OH_AVPlayer_Create](#oh_avplayer_create) (void) | Creates an **OH_AVPlayer** instance.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode)  [OH_AVPlayer_SetURLSource](#oh_avplayer_seturlsource) (OH_AVPlayer \*player, const char \*url) | Sets the HTTP URL of a media source to be played by an AVPlayer.  | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode)  [OH_AVPlayer_SetFDSource](#oh_avplayer_setfdsource) (OH_AVPlayer \*player, int32_t fd, int64_t offset, int64_t size) | Sets the file descriptor of a media source to be played by an AVPlayer.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode)  [OH_AVPlayer_Prepare](#oh_avplayer_prepare) (OH_AVPlayer \*player) | Prepares the playback environment and buffers media data.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode)  [OH_AVPlayer_Play](#oh_avplayer_play) (OH_AVPlayer \*player) | Starts playback.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_Pause](#oh_avplayer_pause) (OH_AVPlayer \*player) | Pauses playback.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_Stop](#oh_avplayer_stop) (OH_AVPlayer \*player) | Stops playback.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_Reset](#oh_avplayer_reset) (OH_AVPlayer \*player) | Restores the AVPlayer to the initial state.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_Release](#oh_avplayer_release) (OH_AVPlayer \*player) | Asynchronously releases an **OH_AVPlayer** instance.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_ReleaseSync](#oh_avplayer_releasesync) (OH_AVPlayer \*player) | Synchronously releases an **OH_AVPlayer** instance.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetVolume](#oh_avplayer_setvolume) (OH_AVPlayer \*player, float leftVolume, float rightVolume) | Sets the volume for an AVPlayer.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_Seek](#oh_avplayer_seek) (OH_AVPlayer \*player, int32_t mSeconds, [AVPlayerSeekMode](#avplayerseekmode) mode) | Seeks to a playback position.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetCurrentTime](#oh_avplayer_getcurrenttime) (OH_AVPlayer \*player, int32_t \*currentTime) | Obtains the playback position, in milliseconds.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetVideoWidth](#oh_avplayer_getvideowidth) (OH_AVPlayer \*player, int32_t \*videoWidth) | Obtains the video width.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetVideoHeight](#oh_avplayer_getvideoheight) (OH_AVPlayer \*player, int32_t \*videoHeight) | Obtains the video height.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetPlaybackSpeed](#oh_avplayer_setplaybackspeed) (OH_AVPlayer \*player, [AVPlaybackSpeed](#avplaybackspeed) speed) | Sets the playback speed for an AVPlayer.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetPlaybackSpeed](#oh_avplayer_getplaybackspeed) (OH_AVPlayer \*player, [AVPlaybackSpeed](#avplaybackspeed) \*speed) | Obtains the playback speed of an AVPlayer.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetAudioRendererInfo](#oh_avplayer_setaudiorendererinfo) (OH_AVPlayer \*player, OH_AudioStream_Usage streamUsage) | Sets the audio stream type for an AVPlayer. | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetAudioInterruptMode](#oh_avplayer_setaudiointerruptmode) (OH_AVPlayer \*player, OH_AudioInterrupt_Mode interruptMode) | Sets the audio interruption mode for an AVPlayer. | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetAudioEffectMode](#oh_avplayer_setaudioeffectmode) (OH_AVPlayer \*player, OH_AudioStream_AudioEffectMode effectMode) | Sets the audio effect mode for an AVPlayer. | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SelectBitRate](#oh_avplayer_selectbitrate) (OH_AVPlayer \*player, uint32_t bitRate) | Sets the bit rate used by an HLS player.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetVideoSurface](#oh_avplayer_setvideosurface) (OH_AVPlayer \*player, OHNativeWindow \*window) | Sets a playback window.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetDuration](#oh_avplayer_getduration) (OH_AVPlayer \*player, int32_t \*duration) | Obtains the total duration of a media file, in milliseconds.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetState](#oh_avplayer_getstate) (OH_AVPlayer \*player, [AVPlayerState](#avplayerstate) \*state) | Obtains the AVPlayer state.| 
| bool [OH_AVPlayer_IsPlaying](#oh_avplayer_isplaying) (OH_AVPlayer \*player) | Checks whether an AVPlayer is playing.| 
| bool [OH_AVPlayer_IsLooping](#oh_avplayer_islooping) (OH_AVPlayer \*player) | Checks whether an AVPlayer is looping.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetLooping](#oh_avplayer_setlooping) (OH_AVPlayer \*player, bool loop) | Enables loop playback.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetPlayerCallback](#oh_avplayer_setplayercallback) (OH_AVPlayer \*player, [AVPlayerCallback](_a_v_player_callback.md) callback) | Sets a callback for an AVPlayer.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SelectTrack](#oh_avplayer_selecttrack) (OH_AVPlayer \*player, int32_t index) | Selects an audio track. This function is not supported yet.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_DeselectTrack](#oh_avplayer_deselecttrack) (OH_AVPlayer \*player, int32_t index) | Deselects an audio track. This function is not supported yet.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetCurrentTrack](#oh_avplayer_getcurrenttrack) (OH_AVPlayer \*player, int32_t trackType, int32_t \*index) | Obtains the currently valid track. This function is not supported yet.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetMediaKeySystemInfoCallback](#oh_avplayer_setmediakeysysteminfocallback) (OH_AVPlayer \*player, Player_MediaKeySystemInfoCallback callback) | Sets a callback to return the media key system information for an AVPlayer.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetMediaKeySystemInfo](#oh_avplayer_getmediakeysysteminfo) (OH_AVPlayer \*player, [DRM_MediaKeySystemInfo](../apis-drm-kit/_d_r_m___media_key_system_info.md) \*mediaKeySystemInfo) | Obtains the media key system information to create a media key session.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetDecryptionConfig](#oh_avplayer_setdecryptionconfig) (OH_AVPlayer \*player, [MediaKeySession](../apis-drm-kit/_drm.md#mediakeysession) \*mediaKeySession, bool secureVideoPath) | Sets the decryption information.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetOnInfoCallback](#oh_avplayer_setoninfocallback) (OH_AVPlayer \*player, [OH_AVPlayerOnInfoCallback](#oh_avplayeroninfocallback) callback, void \*userData) | Sets a callback for the event indicating that the AVPlayer receives a message. | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetOnErrorCallback](#oh_avplayer_setonerrorcallback) (OH_AVPlayer \*player, [OH_AVPlayerOnErrorCallback](#oh_avplayeronerrorcallback) callback, void \*userData) | Sets a callback for the event indicating that an error occurs in the AVPlayer. | 


### Variables

| Name| Description| 
| -------- | -------- |
| const char \* [OH_PLAYER_STATE](#oh_player_state) | Pointer to the key for obtaining the AVPlayer state. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_STATE_CHANGE_REASON](#oh_player_state_change_reason) | Pointer to the key for obtaining the AVPlayer state change reason. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_VOLUME](#oh_player_volume) | Pointer to the key for obtaining the volume. The value type is float. | 
| const char \* [OH_PLAYER_BITRATE_ARRAY](#oh_player_bitrate_array) | Pointer to the key for obtaining the bit rate array. The value is of the uint8_t byte array type, which is expressed by [AV_INFO_TYPE_BITRATE_COLLECT](#avplayeroninfotype-1). | 
| const char \* [OH_PLAYER_AUDIO_INTERRUPT_TYPE](#oh_player_audio_interrupt_type) | Pointer to the key for obtaining the audio interruption type. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_AUDIO_INTERRUPT_FORCE](#oh_player_audio_interrupt_force) | Pointer to the key for obtaining the FORCE type of audio interruption. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_AUDIO_INTERRUPT_HINT](#oh_player_audio_interrupt_hint) | Pointer to the key for obtaining the HINT type of audio interruption. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_AUDIO_DEVICE_CHANGE_REASON](#oh_player_audio_device_change_reason) | Pointer to the key for obtaining the audio device change reason. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_BUFFERING_TYPE](#oh_player_buffering_type) | Pointer to the key for obtaining the type of the buffer update message. The value type is [AVPlayerBufferingType](#avplayerbufferingtype-1). | 
| const char \* [OH_PLAYER_BUFFERING_VALUE](#oh_player_buffering_value) | Pointer to the key for obtaining the value of the buffer update message. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_SEEK_POSITION](#oh_player_seek_position) | Pointer to the key for obtaining the playback progress after the seek operation. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_PLAYBACK_SPEED](#oh_player_playback_speed) | Pointer to the key for obtaining the playback speed. The value type is [AVPlaybackSpeed](#avplaybackspeed-1). | 
| const char \* [OH_PLAYER_BITRATE](#oh_player_bitrate) | Pointer to the key for obtaining the bit rate. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_CURRENT_POSITION](#oh_player_current_position) | Pointer to the key for obtaining the playback progress information. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_DURATION](#oh_player_duration) | Pointer to the key for obtaining the media asset duration. The value type is int64_t. | 
| const char \* [OH_PLAYER_VIDEO_WIDTH](#oh_player_video_width) | Pointer to the key for obtaining the video width. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_VIDEO_HEIGHT](#oh_player_video_height) | Pointer to the key for obtaining the video height. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_MESSAGE_TYPE](#oh_player_message_type) | Pointer to the key for obtaining the type of message received by the AVPlayer. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_IS_LIVE_STREAM](#oh_player_is_live_stream) | Pointer to the key for checking whether a media asset is live streaming. The value is of the int32_t type. | 


## Type Description


### AVPlaybackSpeed

```
typedef enum AVPlaybackSpeed AVPlaybackSpeed
```

**Description**

Defines an enum for the playback speeds of the AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11


### AVPlayerBufferingType

```
typedef enum AVPlayerBufferingType AVPlayerBufferingType
```

**Description**

Defines an enum for the types of buffer messages of the AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12


### AVPlayerCallback

```
typedef struct AVPlayerCallback AVPlayerCallback
```

**Description**

Contains the set of the **OH_AVPlayerOnInfo** and **OH_AVPlayerOnInfo** callback function pointers. To ensure the normal running of **OH_AVPlayer**, you must register the instance of this struct with the **OH_AVPlayer** instance and process the information reported by the callback functions.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Deprecated from**: 12

**Substitute**: [OH_AVPlayerOnInfoCallback](#oh_avplayeroninfocallback) and [OH_AVPlayerOnErrorCallback](#oh_avplayeronerrorcallback)

**Parameters**

| Name| Description| 
| -------- | -------- |
| onInfo | Callback for AVPlayer message information. For details about the available options, see [OH_AVPlayerOnInfo](#oh_avplayeroninfo).| 
| onError | Callback for AVPlayer error information. For details about the available options, see [OH_AVPlayerOnError](#oh_avplayeronerror).| 


### AVPlayerOnInfoType

```
typedef enum AVPlayerOnInfoType AVPlayerOnInfoType
```

**Description**

Defines an enum for the types of messages received by the AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11


### AVPlayerSeekMode

```
typedef enum AVPlayerSeekMode AVPlayerSeekMode
```

**Description**

Defines an enum for the seek modes of the AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11


### AVPlayerState

```
typedef enum AVPlayerState AVPlayerState
```

**Description**

Defines an enum for the AVPlayer states.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11


### DRM_MediaKeySystemInfo

```
typedef struct DRM_MediaKeySystemInfo DRM_MediaKeySystemInfo
```

**Description**

Defines a struct for the media key system information.

**Since**: 12


### MediaKeySession

```
typedef struct MediaKeySession MediaKeySession
```

**Description**

Defines a struct for the media key session.

**Since**: 12


### OH_AVPlayerOnError

```
typedef void(* OH_AVPlayerOnError) (OH_AVPlayer *player, int32_t errorCode, const char *errorMsg)
```

**Description**

Defines the callback when an error occurs in the AVPlayer. This type is available in API version 9 or later.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Deprecated from**: 12

**Substitute**: [OH_AVPlayerOnErrorCallback](#oh_avplayeronerrorcallback)

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance. | 
| errorCode | Error code.<br>**AV_ERR_NO_MEMORY**: No memory. The value is **1**.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The value is **2**.<br>**AV_ERR_INVALID_VAL**: Invalid value. The value is **3**.<br>**AV_ERR_IO**: I/O error. The value is **4**.<br>**AV_ERR_TIMEOUT**: Timeout. The value is **5**.<br>**AV_ERR_UNKNOWN**: Unknown error. The value is **6**.<br>**AV_ERR_SERVICE_DIED**: The service is dead. The value is **7**.<br>**AV_ERR_INVALID_STATE**: The operation is not supported in the current state. The value is **8**.<br>**AV_ERR_UNSUPPORT**: The function is not supported. The value is **9**.<br>**AV_ERR_EXTEND_START**: Initial value for extended error codes. The value is **100**.| 
| errorMsg | Pointer to an error message. | 


### OH_AVPlayerOnErrorCallback

```
typedef void(* OH_AVPlayerOnErrorCallback) (OH_AVPlayer *player, int32_t errorCode, const char *errorMsg, void *userData)
```

**Description**

Defines the callback invoked when an error occurs in the AVPlayer. If this callback is successfully set, the **OH_AVPlayerOnError** function will not be invoked.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance. | 
| errorCode | Error code.<br>**AV_ERR_NO_MEMORY**: No memory. The value is **1**.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The value is **2**.<br>**AV_ERR_INVALID_VAL**: Invalid value. The value is **3**.<br>**AV_ERR_IO**: I/O error. The value is **4**.<br>**AV_ERR_TIMEOUT**: Timeout. The value is **5**.<br>**AV_ERR_UNKNOWN**: Unknown error. The value is **6**.<br>**AV_ERR_SERVICE_DIED**: The service is dead. The value is **7**.<br>**AV_ERR_INVALID_STATE**: The operation is not supported in the current state. The value is **8**.<br>**AV_ERR_UNSUPPORT**: The function is not supported. The value is **9**.<br>**AV_ERR_EXTEND_START**: Initial value for extended error codes. The value is **100**.| 
| errorMsg | Pointer to the error message. | 
| userData | Pointer to the user data passed in. The same data is returned. | 


### OH_AVPlayerOnInfo

```
typedef void(* OH_AVPlayerOnInfo) (OH_AVPlayer *player, AVPlayerOnInfoType type, int32_t extra)
```

**Description**
Defines the callback invoked when the AVPlayer receives a message.

The following table lists the mappings between **type** and **extra** values.

| Value of type| Value of extra| 
| -------- | -------- |
| AV_INFO_TYPE_SEEKDONE | Message returned when seeking to a playback position is complete. **extra** indicates the position after the seek operation.|
| AV_INFO_TYPE_SPEEDDONE | Message returned when the playback speed setting is complete. **extra** indicates the playback speed. For details about the available options, see [AVPlaybackSpeed](#avplaybackspeed-1).|
| AV_INFO_TYPE_BITRATEDONE | Message returned when the bit rate setting is complete. **extra** indicates the bit rate.|
| AV_INFO_TYPE_EOS | Message returned when the playback is complete.|
| AV_INFO_TYPE_STATE_CHANGE | Message returned when the AVPlayer state changes. **extra** indicates the new state. For details about the available options, see [AVPlayerState](#avplayerstate-1).|
| AV_INFO_TYPE_POSITION_UPDATE | Message returned when the playback position changes. **extra** indicates the current position.|
| AV_INFO_TYPE_MESSAGE | Message returned when video rendering starts. **extra** indicates the first video frame rendered.|
| AV_INFO_TYPE_VOLUME_CHANGE | Message returned when the playback volume changes. **extra** is not defined in this scenario.|
| AV_INFO_TYPE_RESOLUTION_CHANGE | Message returned when the video size is obtained for the first time or the video size is updated. **extra** is not defined in this scenario.|
| AV_INFO_TYPE_BUFFERING_UPDATE | Message returned when multi-queue buffering changes. **extra** indicates the video duration.|
| AV_INFO_TYPE_BITRATE_COLLECT  | Message returned to report the HLS video bit rates. Each bit rate has been converted into a uint8_t byte array during the reporting. You need to forcibly convert the uint8_t byte array into a uint32_t integer array.  | 
| AV_INFO_TYPE_INTERRUPT_EVENT | Message returned when the audio focus changes. **extra** indicates the hints provided along with audio interruption. For details about the available options, see [OH_AudioInterrupt_Hint](../apis-audio-kit/_o_h_audio.md#oh_audiointerrupt_hint). The application can determine whether to perform further processing based on the hint.|
| AV_INFO_TYPE_DURATION_UPDATE | Message returned when the playback duration changes. **extra** indicates the video duration.|
| AV_INFO_TYPE_IS_LIVE_STREAM | Message returned when live streams are played. **extra** indicates whether the stream is a live stream. The value **0** means a non-live stream, and **1** means a live stream.|
| AV_INFO_TYPE_TRACKCHANGE | Message returned when the track changes. **extra** is not defined in this scenario.|
| AV_INFO_TYPE_TRACK_INFO_UPDATE |Message returned when the track information updates. **extra** is not defined in this scenario.|
| AV_INFO_TYPE_SUBTITLE_UPDATE | Message returned when the subtitle information changes. **extra** is not defined in this scenario.|
| AV_INFO_TYPE_AUDIO_OUTPUT_DEVICE_CHANGE | Message returned when the audio output device changes. **extra** indicates the device change reason. For details about the available options, see [OH_AudioStream_DeviceChangeReason](../apis-audio-kit/_o_h_audio.md#oh_audiostream_devicechangereason).|

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Deprecated from**: 12

**Substitute**: [OH_AVPlayerOnInfoCallback](#oh_avplayeroninfocallback)

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance. | 
| type | Message type. For details about the available options, see [AVPlayerOnInfoType](#avplayeroninfotype-1). For details about the mappings between **type** and **extra** values, see the function description.| 
| extra | Other information, such as the start time and position of the media file to play. | 


### OH_AVPlayerOnInfoCallback

```
typedef void(* OH_AVPlayerOnInfoCallback) (OH_AVPlayer *player, AVPlayerOnInfoType type, OH_AVFormat *infoBody, void *userData)
```

**Description**

Defines the callback invoked when the AVPlayer receives a message. If this callback is successfully set, the **OH_AVPlayerOnInfo** function will not be invoked.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance. | 
| type | Message type. For details about the available options, see [AVPlayerOnInfoType](#avplayeroninfotype-1). | 
| infoBody | Pointer to the message. The pointer is valid only in this callback. | 
| userData | Pointer to the user data passed in. The same data is returned. | 


### Player_MediaKeySystemInfoCallback

```
typedef void(* Player_MediaKeySystemInfoCallback) (OH_AVPlayer *player, DRM_MediaKeySystemInfo *mediaKeySystemInfo)
```

**Description**

Defines the callback invoked when media key system information of the AVPlayer is updated.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance. | 
| mediaKeySystemInfo | Pointer to the media key system information. | 

**Returns**

void


## Enum Description


### AVPlaybackSpeed

```
enum AVPlaybackSpeed
```

**Description**

Enumerates the playback speeds of the AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

| Value| Description| 
| -------- | -------- |
| AV_SPEED_FORWARD_0_75_X | Plays the video at 0.75 times the normal speed.| 
| AV_SPEED_FORWARD_1_00_X | Plays the video at the normal speed.| 
| AV_SPEED_FORWARD_1_25_X | Plays the video at 1.25 times the normal speed.| 
| AV_SPEED_FORWARD_1_75_X | Plays the video at 1.75 times the normal speed.| 
| AV_SPEED_FORWARD_2_00_X | Plays the video at 2.0 times the normal speed.| 
| AV_SPEED_FORWARD_0_50_X | Plays the video at 0.5 times the normal speed.<br>**Since**: 12| 
| AV_SPEED_FORWARD_1_50_X | Plays the video at 1.5 times the normal speed.<br>**Since**: 12| 


### AVPlayerBufferingType

```
enum AVPlayerBufferingType
```

**Description**

Enumerates the types of buffer messages of the AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12

| Value| Description| 
| -------- | -------- |
| AVPLAYER_BUFFERING_START  | Buffering start message.  | 
| AVPLAYER_BUFFERING_END  | Buffering end message.  | 
| AVPLAYER_BUFFERING_PERCENT  | Buffer execution progress, in percentage. The value is an integer in the range [0, 100].  | 
| AVPLAYER_BUFFERING_CACHED_DURATION  | Duration that cached data can be played, in milliseconds.  | 


### AVPlayerOnInfoType

```
enum AVPlayerOnInfoType
```

**Description**

Enumerates the types of messages received by the AVPlayer.

The enum can be used in [OH_AVPlayerOnInfoCallback](#oh_avplayeroninfocallback) and [OH_AVPlayerOnInfo (deprecated)](#oh_avplayeroninfo) to indicate the type of information received by the AVPlayer.

- Since API version 12, you are advised to use [OH_AVPlayerOnInfoCallback](#oh_avplayeroninfocallback) instead. Different information (**infoBody**) can be obtained for different **OnInfo** types. **infoBody** contains the key-value pairs. For details, see the following enumerated value table.

- If you are using API version 11 for development, use **OH_AVPlayerOnInfo (deprecated)**. For details about the mappings used in this deprecated API, see [OH_AVPlayerOnInfo API Description](#oh_avplayeroninfo).

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

| Value| Description| 
| -------- | -------- |
| AV_INFO_TYPE_SEEKDONE | Message returned when seeking to a playback position is complete.<br>If **key** is set to **OH_PLAYER_SEEK_POSITION**, the value type is int32_t. The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value.|
| AV_INFO_TYPE_SPEEDDONE | Message returned when the playback speed setting is complete.<br>If **key** is set to **OH_PLAYER_PLAYBACK_SPEED**, the value is an enumerated value of [AVPlaybackSpeed](#avplaybackspeed-1). The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value and forcibly converts the value to an enumerated value of [AVPlaybackSpeed](#avplaybackspeed-1).|
| AV_INFO_TYPE_BITRATEDONE | Message returned when the bit rate setting is complete.<br>If **key** is set to **OH_PLAYER_BITRATE**, the value type is uint32_t. The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value and forcibly converts the value to the uint32_t type.|
| AV_INFO_TYPE_EOS | Message returned when the playback is complete.|
| AV_INFO_TYPE_STATE_CHANGE | Message returned when the AVPlayer state changes.<br>- If **key** is set to **OH_PLAYER_STATE**, the value type is int32_t. The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value and forcibly converts the value to an enumerated value of [AVPlayerState](#avplayerstate-1).<br>- If **key** is set to **OH_PLAYER_STATE_CHANGE_REASON**, the value type is int32_t. The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value. The value **1** means that the change is triggered by user operations, and **2** means that the change is triggered by the system.|
| AV_INFO_TYPE_POSITION_UPDATE | Message returned when the playback position changes.<br>If **key** is set to **OH_PLAYER_CURRENT_POSITION**, the value type is int32_t. The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value.|
| AV_INFO_TYPE_MESSAGE | Message returned when video rendering starts.<br>If **key** is set to **OH_PLAYER_MESSAGE_TYPE**, the value type is int32_t. The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value. The value **1** means that video rendering starts.|
| AV_INFO_TYPE_VOLUME_CHANGE | Message returned when the playback volume changes.<br>If **key** is set to **OH_PLAYER_VOLUME**, the value type is float. The system uses float to transfer the value, and the application uses float to obtain the value. The value range is [0.0, 1.0].|
| AV_INFO_TYPE_RESOLUTION_CHANGE | Message returned when the video size is obtained for the first time or the video size is updated.<br>If **key** is set to **OH_PLAYER_VIDEO_WIDTH** or **OH_PLAYER_VIDEO_HEIGHT**, the value type is int32_t. The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value.|
| AV_INFO_TYPE_BUFFERING_UPDATE | Message returned when multi-queue buffering changes.<br>- If **key** is set to **OH_PLAYER_BUFFERING_TYPE**, the value type is [AVPlayerBufferingType](#avplayerbufferingtype-1). The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value and forcibly converts the value to an enumerated value of [AVPlayerBufferingType](#avplayerbufferingtype-1).<br>- If **key** is set to **OH_PLAYER_BUFFERING_VALUE**, the value type is int32_t. The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value. This value is valid when the buffer update message type is **AVPLAYER_BUFFERING_PERCENT** or **AVPLAYER_BUFFERING_CACHED_DURATION**, which indicate the percentage of the buffer progress and the duration that the cached data can play, respectively.|
| AV_INFO_TYPE_BITRATE_COLLECT  | Message returned to report the HLS video bit rates.<br>If **key** is set to **OH_PLAYER_BITRATE_ARRAY**, the value type is uint8_t. The application uses a pointer variable of the uint8_t type to store the bit rate list and uses a variable of the size_t type to store the byte array length. Then it allocates several storage spaces of the uint32_t type to receive the bit rate integer of the uint32_t type, which is converted from the uint8_t byte array.  | 
| AV_INFO_TYPE_INTERRUPT_EVENT | Message returned when the audio focus changes.<br>The value type is int32_t. The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value.<br>**key** can be set to any of the following values:<br>- **OH_PLAYER_AUDIO_INTERRUPT_TYPE**: The value **1** means that the audio interruption event starts, and **2** means that the event ends.<br>- **OH_PLAYER_AUDIO_INTERRUPT_FORCE**: The value **0** means forcible interruption (the system changes the audio playback status), and **1** means sharing interruption (the application changes the audio playback status).<br>- **OH_PLAYER_AUDIO_INTERRUPT_HINT**: The value **0** (NONE) means no hint; **1** (RESUME) means that the audio playback is resumed; **2** (PAUSE) means that the audio playback is paused and loses focus; **3** (STOP) means that the audio playback is stopped; **4** (DUCK) means that the audio volume is reduced; **5** (UNDUCK) means that the audio volume is restored.|
| AV_INFO_TYPE_DURATION_UPDATE | Message returned when the playback duration changes.<br>If **key** is set to **OH_PLAYER_DURATION**, the value type is int64_t. The system uses int64_t to transfer the value, and the application uses int64_t to obtain the value.|
| AV_INFO_TYPE_IS_LIVE_STREAM | Message returned when live streams are played.<br>If **key** is set to **OH_PLAYER_IS_LIVE_STREAM**, the value type is int32_t. The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value. The value **0** means a non-live stream, and **1** means a live stream.|
| AV_INFO_TYPE_TRACKCHANGE | Message returned when the track changes. **extra** is not defined in this scenario.|
| AV_INFO_TYPE_TRACK_INFO_UPDATE |Message returned when the track information updates. **extra** is not defined in this scenario.|
| AV_INFO_TYPE_SUBTITLE_UPDATE | Message returned when the subtitle information changes. **extra** is not defined in this scenario.|
| AV_INFO_TYPE_AUDIO_OUTPUT_DEVICE_CHANGE | Message returned when the audio output device changes.<br>If **key** is set to **OH_PLAYER_AUDIO_DEVICE_CHANGE_REASON**, the value type is int32_t. The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value.|


### AVPlayerSeekMode

```
enum AVPlayerSeekMode
```

**Description**

Enumerates the seek modes of the AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

| Value| Description| 
| -------- | -------- |
| AV_SEEK_NEXT_SYNC | Seeks to the next key frame at the specified position.| 
| AV_SEEK_PREVIOUS_SYNC | Seeks to the previous key frame at the specified position.| 
| AV_SEEK_CLOSEST | Seeks to the frame closest to the specified position.<br>**Since**: 12| 


### AVPlayerState

```
enum AVPlayerState
```

**Description**

Enumerates the AVPlayer states.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

| Value| Description| 
| -------- | -------- |
| AV_IDLE | The AVPlayer is idle.| 
| AV_INITIALIZED | The AVPlayer is initialized.| 
| AV_PREPARED | The AVPlayer is ready for playback.| 
| AV_PLAYING | The AVPlayer is playing.| 
| AV_PAUSED | The AVPlayer is paused.| 
| AV_STOPPED | The AVPlayer is stopped.| 
| AV_COMPLETED | The AVPlayer finishes playing.| 
| AV_RELEASED | The AVPlayer is released.| 
| AV_ERROR | An error occurs.| 


## Function Description


### OH_AVPlayer_Create()

```
OH_AVPlayer* OH_AVPlayer_Create (void)
```

**Description**

Creates an **OH_AVPlayer** instance.

> **NOTE**
>
> You are advised to create a maximum of 16 **AVPlayer** instances for an application in both audio and video playback scenarios.<!--Del-->
> The actual number of instances that can be created may be different. It depends on the specifications of the device chip in use. For example, in the case of RK3568, you are advised to create a maximum of 6 **AVPlayer** instances for an application in audio and video playback scenarios.<!--DelEnd-->

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Returns**

Returns the pointer to the **OH_AVPlayer** instance created if the operation is successful; returns a null pointer otherwise.

The possible causes of an operation failure are as follows:

1. The execution of **PlayerFactory::CreatePlayer** fails.
2. The execution of **new PlayerObject** fails.


### OH_AVPlayer_DeselectTrack()

```
OH_AVErrCode OH_AVPlayer_DeselectTrack (OH_AVPlayer *player, int32_t index)
```

**Description**

Deselects an audio track. This function is not supported yet.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| index | Index of the track. | 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The deselection is successful.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, or the execution of **player DeselectTrack** fails.


### OH_AVPlayer_GetCurrentTime()

```
OH_AVErrCode OH_AVPlayer_GetCurrentTime (OH_AVPlayer *player, int32_t *currentTime)
```

**Description**

Obtains the playback position, in milliseconds.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| currentTime | Pointer to the playback position.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The playback position is obtained.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, or the execution of **player GetCurrentTime** fails.


### OH_AVPlayer_GetCurrentTrack()

```
OH_AVErrCode OH_AVPlayer_GetCurrentTrack (OH_AVPlayer *player, int32_t trackType, int32_t *index)
```

**Description**

Obtains the currently valid track. This function is not supported yet.

You can set the track to the prepared, playing, paused, or completed state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| trackType | Media type. The value **0** means audio and **1** means video.| 
| index | Pointer to the index of the track.|  

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The track is obtained.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, or the execution of **player GetCurrentTrack** fails.


### OH_AVPlayer_GetDuration()

```
OH_AVErrCode OH_AVPlayer_GetDuration (OH_AVPlayer *player, int32_t *duration)
```

**Description**

Obtains the total duration of a media file, in milliseconds.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| duration | Pointer to the total duration.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The total duration is obtained.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, or the execution of **player GetDuration** fails.


### OH_AVPlayer_GetMediaKeySystemInfo()

```
OH_AVErrCode OH_AVPlayer_GetMediaKeySystemInfo (OH_AVPlayer *player, DRM_MediaKeySystemInfo *mediaKeySystemInfo)
```

**Description**

Obtains the media key system information to create a media key session.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.|
| mediaKeySystemInfo | Pointer to the media key system information.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The setting is successful.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, or the memory is insufficient.

### OH_AVPlayer_GetPlaybackSpeed()

```
OH_AVErrCode OH_AVPlayer_GetPlaybackSpeed (OH_AVPlayer *player, AVPlaybackSpeed *speed)
```

**Description**

Obtains the playback speed of an AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| speed | Pointer to the playback speed. For details about the available options, see [AVPlaybackSpeed](#avplaybackspeed).| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The playback rate is obtained.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, or the execution of **player GetPlaybackSpeed** fails.


### OH_AVPlayer_GetState()

```
OH_AVErrCode OH_AVPlayer_GetState (OH_AVPlayer *player, AVPlayerState *state)
```

**Description**

Obtains the AVPlayer state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| state | Pointer to the state.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The AVPlayer state is obtained.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, or the execution of **player GetState** fails.


### OH_AVPlayer_GetVideoHeight()

```
OH_AVErrCode OH_AVPlayer_GetVideoHeight (OH_AVPlayer *player, int32_t *videoHeight)
```

**Description**

Obtains the video height.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| videoHeights | Pointer to the video height.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The video height is obtained.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer.


### OH_AVPlayer_GetVideoWidth()

```
OH_AVErrCode OH_AVPlayer_GetVideoWidth (OH_AVPlayer *player, int32_t *videoWidth)
```

**Description**

Obtains the video width.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| videoWidth | Pointer to the video width.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The video width is obtained.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer.


### OH_AVPlayer_IsLooping()

```
bool OH_AVPlayer_IsLooping (OH_AVPlayer *player)
```

**Description**

Checks whether an AVPlayer is looping.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 

**Returns**

Returns **true** if the AVPlayer is looping; returns **false** if the AVPlayer is not looping or the input parameter **player** is a null pointer.


### OH_AVPlayer_IsPlaying()

```
bool OH_AVPlayer_IsPlaying (OH_AVPlayer *player)
```

**Description**

Checks whether an AVPlayer is playing.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 

**Returns**

Returns **true** if the AVPlayer is playing; returns **false** if the AVPlayer is not playing or the input parameter **player** is a null pointer.


### OH_AVPlayer_Pause()

```
OH_AVErrCode OH_AVPlayer_Pause (OH_AVPlayer *player)
```

**Description**

Pauses playback.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The **Pause** operation is added to the task queue.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, or the execution of **player Pause** fails.


### OH_AVPlayer_Play()

```
OH_AVErrCode OH_AVPlayer_Play (OH_AVPlayer *player)
```

**Description**

Starts playback.

This function must be called after **Prepare**. In other words, you can call this function when the AVPlayer is in the prepared state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The playback starts.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, or the execution of **player Play** fails.


### OH_AVPlayer_Prepare()

```
OH_AVErrCode OH_AVPlayer_Prepare (OH_AVPlayer *player)
```

**Description**

Prepares the playback environment and buffers media data.

This function must be called after **SetSource**.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The **Prepare** operation is added to the task queue.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, or the execution of **player Prepare** fails.


### OH_AVPlayer_Release()

```
OH_AVErrCode OH_AVPlayer_Release (OH_AVPlayer *player)
```

**Description**

Asynchronously releases an **OH_AVPlayer** instance.

The asynchronous function ensures the performance, but cannot ensure that the surface buffer of the playback window is released. You must ensure the lifecycle of the playback window.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The **Release** operation is added to the task queue.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, or the execution of **player Release** fails.


### OH_AVPlayer_ReleaseSync()

```
OH_AVErrCode OH_AVPlayer_ReleaseSync (OH_AVPlayer *player)
```

**Description**

Synchronously releases an **OH_AVPlayer** instance.

The synchronous function ensures that the display buffer of the playback window is released, with a long time. Therefore, you need to design an asynchronous mechanism.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The AVPlayer is released.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, or the execution of **player ReleaseSync** fails.

### OH_AVPlayer_Reset()

```
OH_AVErrCode OH_AVPlayer_Reset (OH_AVPlayer *player)
```

**Description**

Restores the AVPlayer to the initial state.

After the function is called, you can call **SetSource** to set the media source to play, and then call **Prepare** and **Play** in sequence.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The **reset** operation is added to the task queue.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, or the execution of **player Reset** fails.


### OH_AVPlayer_Seek()

```
OH_AVErrCode OH_AVPlayer_Seek (OH_AVPlayer *player, int32_t mSeconds, AVPlayerSeekMode mode)
```

**Description**

Seeks to a playback position.

This function can be used when the AVPlayer is in the playing or paused state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| mSeconds | Position to seek to, in ms.| 
| mode | Seek mode. For details about the available options, see [AVPlayerSeekMode](#avplayerseekmode).| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

AV_ERR_OK: The seek operation is complete.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, or the execution of **player Seek** fails.


### OH_AVPlayer_SelectBitRate()

```
OH_AVErrCode OH_AVPlayer_SelectBitRate (OH_AVPlayer *player, uint32_t bitRate)
```

**Description**

Sets the bit rate used by an HLS player,

in bit/s. This function is valid only for HLS network streams. By default, the player selects a proper bit rate and speed based on the network connection. You can set a bit rate available in the valid bit rates reported in **INFO_TYPE_BITRATE_COLLECT**. The player selects a bit rate that is lower than or closest to the specified bit rate for playback. When ready, you can query the selected bit rate.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| bitRate | Bit rate, in kbit/s.| 

**Returns**

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The bit rate is set.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, or the execution of **player SelectBitRate** fails.


### OH_AVPlayer_SelectTrack()

```
OH_AVErrCode OH_AVPlayer_SelectTrack (OH_AVPlayer *player, int32_t index)
```

**Description**

Selects an audio track. This function is not supported yet.

By default, the first audio stream with data is played. After the setting takes effect, the original track becomes invalid. This API sets the audio track to the ready state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| index | Index of the track.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: A track is selected.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, or the execution of **player SelectTrack** fails.


### OH_AVPlayer_SetAudioEffectMode()

```
OH_AVErrCode OH_AVPlayer_SetAudioEffectMode (OH_AVPlayer *player, OH_AudioStream_AudioEffectMode effectMode)
```

**Description**

Sets the audio effect mode for an AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance. | 
| interruptMode | Audio effect mode. For details about the available options, see [OH_AudioStream_AudioEffectMode](../apis-audio-kit/_o_h_audio.md#oh_audiostream_audioeffectmode). | 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The setting is successful.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer or **effectMode** is invalid.


### OH_AVPlayer_SetAudioInterruptMode()

```
OH_AVErrCode OH_AVPlayer_SetAudioInterruptMode (OH_AVPlayer *player, OH_AudioInterrupt_Mode interruptMode)
```

**Description**

Sets the audio interruption mode for an AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance. | 
| interruptMode | Audio interruption mode. For details about the available options, see [OH_AudioInterrupt_Mode](../apis-audio-kit/_o_h_audio.md#oh_audiointerrupt_mode). | 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The setting is successful.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer or **interruptMode** is invalid.


### OH_AVPlayer_SetAudioRendererInfo()

```
OH_AVErrCode OH_AVPlayer_SetAudioRendererInfo (OH_AVPlayer *player, OH_AudioStream_Usage streamUsage)
```

**Description**

Sets the audio stream type for an AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance. | 
| streamUsage | Audio stream type. For details about the available options, see [OH_AudioStream_Usage](../apis-audio-kit/_o_h_audio.md#oh_audiostream_usage). | 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The setting is successful.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer or **streamUsage** is invalid.


### OH_AVPlayer_SetDecryptionConfig()

```
OH_AVErrCode OH_AVPlayer_SetDecryptionConfig (OH_AVPlayer *player, MediaKeySession *mediaKeySession, bool secureVideoPath)
```

**Description**

Sets the decryption information.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| mediaKeySession | Pointer to the media key session with the decryption feature.| 
| secureVideoPath | Whether a secure decoder is required.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The setting is successful.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, or the execution of **player SetDecryptionConfig** fails.


### OH_AVPlayer_SetFDSource()

```
OH_AVErrCode OH_AVPlayer_SetFDSource (OH_AVPlayer *player, int32_t fd, int64_t offset, int64_t size)
```

**Description**

Sets the file descriptor of a media source to be played by an AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| fd | File descriptor of the media source.| 
| offset | Offset of the media source in the file descriptor.| 
| size | Size of the media source.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The file descriptor is set.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, or the execution of **player SetFdSource** fails.


### OH_AVPlayer_SetLooping()

```
OH_AVErrCode OH_AVPlayer_SetLooping (OH_AVPlayer *player, bool loop)
```

**Description**

Enables loop playback.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| loop | Whether to enable loop playback.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: Loop playback is enabled.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, or the execution of **player SetLooping** fails.


### OH_AVPlayer_SetMediaKeySystemInfoCallback()

```
OH_AVErrCode OH_AVPlayer_SetMediaKeySystemInfoCallback (OH_AVPlayer *player, Player_MediaKeySystemInfoCallback callback)
```

**Description**

Sets a callback to return the media key system information for an AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| callback | Callback.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The setting is successful.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, the input parameter **callback** is null, or the execution of **player SetDrmSystemInfoCallback** fails.


### OH_AVPlayer_SetOnErrorCallback()

```
OH_AVErrCode OH_AVPlayer_SetOnErrorCallback (OH_AVPlayer * player, OH_AVPlayerOnErrorCallback callback, void * userData )
```

**Description**

Sets a callback for the event indicating that an error occurs in the AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance. | 
| callback | Pointer to the callback. If a null pointer is passed in, the listening for AVPlayer errors is canceled. | 
| userData | Pointer to the instance set by the caller. | 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_NO_MEMORY**: An error occurs during memory allocation.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer or the function fails to be executed.


### OH_AVPlayer_SetOnInfoCallback()

```
OH_AVErrCode OH_AVPlayer_SetOnInfoCallback (OH_AVPlayer * player, OH_AVPlayerOnInfoCallback callback, void * userData )
```

**Description**

Sets a callback for the event indicating that the AVPlayer receives a message.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance. | 
| callback | Pointer to the callback. If a null pointer is passed in, the listening for AVPlayer messages is canceled. | 
| userData | Pointer to the instance set by the caller. | 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_NO_MEMORY**: An error occurs during memory allocation.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer or the function fails to be executed.


### OH_AVPlayer_SetPlaybackSpeed()

```
OH_AVErrCode OH_AVPlayer_SetPlaybackSpeed (OH_AVPlayer *player, AVPlaybackSpeed speed)
```

**Description**

Sets the playback speed for an AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| speed | Playback speed. For details about the available options, see [AVPlaybackSpeed](#avplaybackspeed).| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The playback speed is set.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer.


### OH_AVPlayer_SetPlayerCallback()

```
OH_AVErrCode OH_AVPlayer_SetPlayerCallback (OH_AVPlayer *player, AVPlayerCallback callback)
```

**Description**
Sets an AVPlayer callback.

The callbacks [OH_AVPlayerOnInfo](#oh_avplayeroninfo) and [OH_AVPlayerOnError](#oh_avplayeronerror) set by using this function can transfer limited information. In addition, it is inconvenient for the application to distinguish between multiple **AVPlayer** instances. Therefore, since API version 12, [OH_AVPlayer_SetOnInfoCallback()](#oh_avplayer_setoninfocallback) and [OH_AVPlayer_SetOnErrorCallback()](#oh_avplayer_setonerrorcallback) are provided to set the callbacks [OH_AVPlayerOnInfoCallback](../../reference/apis-media-kit/_a_v_player.md#oh_avplayeroninfocallback) and [OH_AVPlayerOnErrorCallback](../../reference/apis-media-kit/_a_v_player.md#oh_avplayeronerrorcallback), respectively.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| callback | Callback used to return the result.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The callback is set.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, the input parameter **callback.onInfo** or **onError** is null, or the execution of **player SetPlayerCallback** fails.


### OH_AVPlayer_SetURLSource()

```
OH_AVErrCode OH_AVPlayer_SetURLSource (OH_AVPlayer *player, const char *url)
```

**Description**

Sets the HTTP URL of a media source to be played by an AVPlayer.  

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| url | URL of the media source.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The setting is successful.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, the input parameter **url** is null, or the execution of **player SetUrlSource** fails.


### OH_AVPlayer_SetVideoSurface()

```
OH_AVErrCode OH_AVPlayer_SetVideoSurface (OH_AVPlayer *player, OHNativeWindow *window)
```

**Description**

Sets a playback window.
This function must be called after **SetSource** and before **Prepare**.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| window | Pointer to an **OHNativeWindow** instance.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

AV_ERR_OK: The playback window is set.

**AV_ERR_INVALID_VAL**: The input parameter **player** or **window** is a null pointer, or the execution of **player SetVideoSurface** fails.


### OH_AVPlayer_SetVolume()

```
OH_AVErrCode OH_AVPlayer_SetVolume (OH_AVPlayer *player, float leftVolume, float rightVolume)
```

**Description**

Sets the volume for an AVPlayer.

This function can be used when the AVPlayer is in the playing or paused state. The value **0** means that the AVPlayer is muted, and **1** means that the original volume is used.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| leftVolume | Target volume of the left channel.| 
| rightVolume | Target volume of the right channel.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

AV_ERR_OK: The volume is set.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, or the execution of **player SetVolume** fails.


### OH_AVPlayer_Stop()

```
OH_AVErrCode OH_AVPlayer_Stop (OH_AVPlayer *player)
```

**Description**

Stops playback.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The **stop** operation is added to the task queue.

**AV_ERR_INVALID_VAL**: The input parameter **player** is a null pointer, or the execution of **player Stop** fails.


## Variable Description


### OH_PLAYER_AUDIO_DEVICE_CHANGE_REASON

```
const char* OH_PLAYER_AUDIO_DEVICE_CHANGE_REASON
```
**Description**

Pointer to the key for obtaining the audio device change reason. The value is of the int32_t type.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12


### OH_PLAYER_AUDIO_INTERRUPT_FORCE

```
const char* OH_PLAYER_AUDIO_INTERRUPT_FORCE
```

**Description**

Pointer to the key for obtaining the FORCE type of audio interruption. The value is of the int32_t type.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12


### OH_PLAYER_AUDIO_INTERRUPT_HINT

```
const char* OH_PLAYER_AUDIO_INTERRUPT_HINT
```

**Description**

Pointer to the key for obtaining the HINT type of audio interruption. The value is of the int32_t type.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12


### OH_PLAYER_AUDIO_INTERRUPT_TYPE

```
const char* OH_PLAYER_AUDIO_INTERRUPT_TYPE
```

**Description**

Pointer to the key for obtaining the audio interruption type. The value is of the int32_t type.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12


### OH_PLAYER_BITRATE

```
const char* OH_PLAYER_BITRATE
```

**Description**

Pointer to the key for obtaining the bit rate. The value is of the int32_t type.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12


### OH_PLAYER_BITRATE_ARRAY

```
const char* OH_PLAYER_BITRATE_ARRAY
```

**Description**

Pointer to the key for obtaining the bit rate array. The value is of the uint8_t byte array type. When this key is used to obtain information, you need to:
- Use a pointer variable of the uint8_t type to store the bit rate list and use a variable of the size_t type to store the byte array length.
- Allocate several storage spaces of the uint32_t type to receive the bit rate integer of the uint32_t type, which is converted from the uint8_t byte array. For details, see the **OHAVPlayerOnInfoCallback** function in [Sample Code](../../media/media/using-ndk-avplayer-for-playerback.md#sample-code).

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12


### OH_PLAYER_BUFFERING_TYPE

```
const char* OH_PLAYER_BUFFERING_TYPE
```

**Description**

Pointer to the key for obtaining the type of the buffer update message. The value type is [AVPlayerBufferingType](#avplayerbufferingtype-1). When this key is used to obtain information, you must use a variable of the int32_t type to save the result and then convert the result to a value of [AVPlayerBufferingType](#avplayerbufferingtype-1).

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12


### OH_PLAYER_BUFFERING_VALUE

```
const char* OH_PLAYER_BUFFERING_VALUE
```

**Description**

Pointer to the key for obtaining the value of the buffer update message. The value is of the int32_t type. For details about the available options, see [AVPlayerBufferingType](#avplayerbufferingtype-1). This key is valid when the buffer update message type is **AVPLAYER_BUFFERING_PERCENT** or **AVPLAYER_BUFFERING_CACHED_DURATION**.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12


### OH_PLAYER_CURRENT_POSITION

```
const char* OH_PLAYER_CURRENT_POSITION
```

**Description**

Pointer to the key for obtaining the playback progress information. The value is of the int32_t type.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12


### OH_PLAYER_DURATION

```
const char* OH_PLAYER_DURATION
```

**Description**

Pointer to the key for obtaining the media asset duration. The value type is int64_t.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12


### OH_PLAYER_IS_LIVE_STREAM

```
const char* OH_PLAYER_IS_LIVE_STREAM
```

**Description**

Pointer to the key for checking whether a media asset is live streaming. The value is of the int32_t type.

The value **1** means live streaming.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12


### OH_PLAYER_MESSAGE_TYPE

```
const char* OH_PLAYER_MESSAGE_TYPE
```

**Description**

Pointer to the key for obtaining the type of message received by the AVPlayer. The value is of the int32_t type.

The value **1** means that the video frame starts to be rendered.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12


### OH_PLAYER_PLAYBACK_SPEED

```
const char* OH_PLAYER_PLAYBACK_SPEED
```

**Description**

Pointer to the key for obtaining the playback speed. The value type is [AVPlaybackSpeed](#avplaybackspeed-1). When this key is used to obtain information, you must use a variable of the int32_t type to save the result and then convert the result to a value of [AVPlaybackSpeed](#avplaybackspeed-1).

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12


### OH_PLAYER_SEEK_POSITION

```
const char* OH_PLAYER_SEEK_POSITION
```

**Description**

Pointer to the key for obtaining the playback progress after the seek operation. The value is of the int32_t type.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12


### OH_PLAYER_STATE

```
const char* OH_PLAYER_STATE
```

**Description**

Pointer to the key for obtaining the AVPlayer state. The value is of the int32_t type.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12


### OH_PLAYER_STATE_CHANGE_REASON

```
const char* OH_PLAYER_STATE_CHANGE_REASON
```

**Description**

Pointer to the key for obtaining the AVPlayer state change reason. The value is of the int32_t type.

The value **1** means that the change is triggered by user operations, and **2** means that the change is triggered by the system.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12


### OH_PLAYER_VIDEO_HEIGHT

```
const char* OH_PLAYER_VIDEO_HEIGHT
```

**Description**

Pointer to the key for obtaining the video height. The value is of the int32_t type.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12


### OH_PLAYER_VIDEO_WIDTH

```
const char* OH_PLAYER_VIDEO_WIDTH
```

**Description**

Pointer to the key for obtaining the video width. The value is of the int32_t type.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12


### OH_PLAYER_VOLUME

```
const char* OH_PLAYER_VOLUME
```

**Description**

Pointer to the key for obtaining the volume. The value type is float.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12
