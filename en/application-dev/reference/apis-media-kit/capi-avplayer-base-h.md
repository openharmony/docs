# avplayer_base.h

## Overview

The **avplayer_base.h** file declares the structs and enums of the AVPlayer.

**File to include**: <multimedia/player_framework/avplayer_base.h>

**Library**: libavplayer.so

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Related module**: [AVPlayer](capi-avplayer.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [AVPlayerCallback](capi-avplayercallback.md) | AVPlayerCallback | Contains the set of the **OH_AVPlayerOnInfo** and **OH_AVPlayerOnInfo** callback function pointers. To ensure the normal running of **OH_AVPlayer**, you must register the instance of this struct with the **OH_AVPlayer** instance and process the information reported by the callback functions.|
| [OH_AVPlayer](capi-oh-avplayer.md) | OH_AVPlayer | Describes an initialized AVPlayer.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [AVPlayerState](#avplayerstate) | AVPlayerState | Enumerates the AVPlayer states.|
| [AVPlayerSeekMode](#avplayerseekmode) | AVPlayerSeekMode | Enumerates the seek modes.|
| [AVPlaybackSpeed](#avplaybackspeed) | AVPlaybackSpeed | Enumerates the playback speeds of the AVPlayer.|
| [AVPlayerOnInfoType](#avplayeroninfotype) | AVPlayerOnInfoType | Enumerates the types of messages received by the AVPlayer.<br>The enum can be used in **OH_AVPlayerOnInfoCallback** and **OH_AVPlayerOnInfo** (deprecated) to indicate the type of information received by the AVPlayer.|
| [AVPlayerBufferingType](#avplayerbufferingtype) | AVPlayerBufferingType | Enumerates the types of buffer messages of the AVPlayer.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_AVPlayerOnInfo)(OH_AVPlayer *player, AVPlayerOnInfoType type, int32_t extra)](#oh_avplayeroninfo) | OH_AVPlayerOnInfo | Called when the AVPlayer receives a message.|
| [typedef void (\*OH_AVPlayerOnInfoCallback)(OH_AVPlayer \*player, AVPlayerOnInfoType type, OH_AVFormat* infoBody,void *userData)](#oh_avplayeroninfocallback) | OH_AVPlayerOnInfoCallback | Called when the AVPlayer receives a message. If this callback is successfully set, the **OH_AVPlayerOnInfo** function will not be invoked.|
| [typedef void (\*OH_AVPlayerOnError)(OH_AVPlayer *player, int32_t errorCode, const char *errorMsg)](#oh_avplayeronerror) | OH_AVPlayerOnError | Called when an error occurs in the AVPlayer. This type is available in API version 9 or later.|
| [typedef void (\*OH_AVPlayerOnErrorCallback)(OH_AVPlayer *player, int32_t errorCode, const char *errorMsg,void *userData)](#oh_avplayeronerrorcallback) | OH_AVPlayerOnErrorCallback | Called when an error occurs in the AVPlayer. If this callback is successfully set, the **OH_AVPlayerOnError** function will not be invoked.|

### Variables

| Name| Description|
| -- | -- |
| const char * OH_PLAYER_STATE | Pointer to the key for obtaining the AVPlayer state. The value is of the int32_t type.<br>**Since**: 12|
| const char * OH_PLAYER_STATE_CHANGE_REASON | Pointer to the key for obtaining the AVPlayer state change reason. The value is of the int32_t type.<br>The value **1** means that the change is triggered by user operations, and **2** means that the change is triggered by the system.<br>**Since**: 12|
| const char * OH_PLAYER_VOLUME | Pointer to the key for obtaining the volume. The value type is float.<br>**Since**: 12|
| const char * OH_PLAYER_BITRATE_ARRAY | Pointer to the key for obtaining the bit rate array. The value is of the uint8_t byte array type. When this key is used to obtain information, you need to:<br>Use a pointer variable of the uint8_t type to store the bit rate list and use a variable of the size_t type to store the byte array length.<br>Then it allocates several storage spaces of the uint32_t type to receive the bit rate integer of the uint32_t type, which is converted from the uint8_t byte array.<br>For details, see the **OHAVPlayerOnInfoCallback** function in [Sample Code](../../media/media/using-ndk-avplayer-for-playback.md#development-example).<br>**Since**: 12 |
| const char * OH_PLAYER_AUDIO_INTERRUPT_TYPE | Pointer to the key for obtaining the audio interruption type. The value is of the int32_t type.<br>**Since**: 12|
| const char * OH_PLAYER_AUDIO_INTERRUPT_FORCE | Pointer to the key for obtaining the FORCE type of audio interruption. The value is of the int32_t type.<br>**Since**: 12|
| const char * OH_PLAYER_AUDIO_INTERRUPT_HINT | Pointer to the key for obtaining the HINT type of audio interruption. The value is of the int32_t type.<br>**Since**: 12|
| const char * OH_PLAYER_AUDIO_DEVICE_CHANGE_REASON | Pointer to the key for obtaining the audio device change reason. The value is of the int32_t type.<br>**Since**: 12|
| const char * OH_PLAYER_BUFFERING_TYPE | Pointer to the key for obtaining the type of the buffer update message. The value type is [AVPlayerBufferingType](capi-avplayer-base-h.md#avplayerbufferingtype).<br>When this key is used to obtain information, you must use a variable of the int32_t type to save the result and then convert the result to a value of **AVPlayerBufferingType**.<br>**Since**: 12|
| const char * OH_PLAYER_BUFFERING_VALUE | Pointer to the key for obtaining the value of the buffer update message. The value is of the int32_t type. For details, see [AVPlayerBufferingType](capi-avplayer-base-h.md#avplayerbufferingtype).<br>This parameter is valid only when the buffer update message type is **AVPLAYER_BUFFERING_PERCENT** or **AVPLAYER_BUFFERING_CACHED_DURATION**.<br>**Since**: 12|
| const char * OH_PLAYER_SEEK_POSITION | Pointer to the key for obtaining the playback progress after the seek operation. The value is of the int32_t type.<br>**Since**: 12|
| const char * OH_PLAYER_PLAYBACK_SPEED | Pointer to the key for obtaining the playback speed. The value type is [AVPlaybackSpeed](capi-avplayer-base-h.md#avplaybackspeed).<br>When this key is used to obtain information, you must use a variable of the int32_t type to save the result and then convert the result to a value of **AVPlaybackSpeed**.<br>**Since**: 12|
| const char * OH_PLAYER_PLAYBACK_RATE | Pointer to the key for obtaining the playback rate. The value is a floating point number.<br>**Since**: 20|
| const char * OH_PLAYER_BITRATE | Pointer to the key for obtaining the bit rate. The value is of the uint32_t type.<br>**Since**: 12|
| const char * OH_PLAYER_CURRENT_POSITION | Pointer to the key for obtaining the playback progress information. The value is of the int32_t type.<br>**Since**: 12|
| const char * OH_PLAYER_DURATION | Pointer to the key for obtaining the media asset duration. The value type is int64_t.<br>**Since**: 12|
| const char * OH_PLAYER_VIDEO_WIDTH | Pointer to the key for obtaining the video width. The value is of the int32_t type.<br>**Since**: 12|
| const char * OH_PLAYER_VIDEO_HEIGHT | Pointer to the key for obtaining the video height. The value is of the int32_t type.<br>**Since**: 12|
| const char * OH_PLAYER_MESSAGE_TYPE | Pointer to the key for obtaining the type of message received by the AVPlayer. The value is of the int32_t type.<br>The value **1** means that the video frame starts to be rendered.<br>**Since**: 12|
| const char * OH_PLAYER_IS_LIVE_STREAM | Pointer to the key for checking whether a media asset is live streaming. The value is of the int32_t type.<br>The value **1** means live streaming.<br>**Since**: 12|

## Enum Description

### AVPlayerState

```
enum AVPlayerState
```

**Description**

Enumerates the AVPlayer states.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

| Enum Item| Description|
| -- | -- |
| AV_IDLE = 0 | Idle.|
| AV_INITIALIZED = 1 | Initialized.|
| AV_PREPARED = 2 | Ready.|
| AV_PLAYING = 3 | Playing.|
| AV_PAUSED = 4 | Paused.|
| AV_STOPPED = 5 | Stopped.|
| AV_COMPLETED = 6 | Completed.|
| AV_RELEASED = 7 | Released.|
| AV_ERROR = 8 | Error.|

### AVPlayerSeekMode

```
enum AVPlayerSeekMode
```

**Description**

Enumerates the seek modes.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

| Enum Item| Description|
| -- | -- |
| AV_SEEK_NEXT_SYNC = 0 | Seeks to the next key frame at the specified position.|
| AV_SEEK_PREVIOUS_SYNC | Seeks to the previous key frame at the specified position.|
| AV_SEEK_CLOSEST = 2 | Seeks to the frame closest to the specified position.<br>**Since**: 12|

### AVPlaybackSpeed

```
enum AVPlaybackSpeed
```

**Description**

Enumerates the playback speeds of the AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

| Enum Item| Description|
| -- | -- |
| AV_SPEED_FORWARD_0_75_X | Plays the video at 0.75 times the normal speed.|
| AV_SPEED_FORWARD_1_00_X | Plays the video at the normal speed.|
| AV_SPEED_FORWARD_1_25_X | Plays the video at 1.25 times the normal speed.|
| AV_SPEED_FORWARD_1_75_X | Plays the video at 1.75 times the normal speed.|
| AV_SPEED_FORWARD_2_00_X | Plays the video at 2.0 times the normal speed.|
| AV_SPEED_FORWARD_0_50_X | Plays the video at 0.5 times the normal speed.<br>**Since**: 12|
| AV_SPEED_FORWARD_1_50_X | Plays the video at 1.5 times the normal speed.<br>**Since**: 12|
| AV_SPEED_FORWARD_3_00_X | Plays the video at 3.0 times the normal speed.<br>**Since**: 13|
| AV_SPEED_FORWARD_0_25_X | Plays the video at 0.25 times the normal speed.<br>**Since**: 13|
| AV_SPEED_FORWARD_0_125_X | Plays the video at 0.125 times the normal speed.<br>**Since**: 13|

### AVPlayerOnInfoType

```
enum AVPlayerOnInfoType
```

**Description**

Enumerates the types of messages received by the AVPlayer.<br>The enum can be used in **OH_AVPlayerOnInfoCallback** and **OH_AVPlayerOnInfo** (deprecated) to indicate the type of information received by the AVPlayer.<br>Since API version 12, you are advised to use [OH_AVPlayerOnInfoCallback](capi-avplayer-base-h.md#oh_avplayeroninfocallback) instead. Different information (**infoBody**) can be obtained for different **OnInfo** types. **infoBody** contains the key-value pairs. For details, see the following enumerated value table.<br>If you are using API version 11 for development, use **OH_AVPlayerOnInfo (deprecated)**. For details about the mappings used in this deprecated API, see [OH_AVPlayerOnInfo](capi-avplayer-base-h.md#oh_avplayeroninfo).

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

| Enum Item| Description|
| -- | -- |
| AV_INFO_TYPE_SEEKDONE = 0 | Message returned when seeking to a playback position is complete.<br>If **key** is set to **OH_PLAYER_SEEK_POSITION**, the value type is int32_t. The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value.|
| AV_INFO_TYPE_SPEEDDONE = 1 | Message returned when the playback speed setting is complete.<br>If **key** is set to **OH_PLAYER_PLAYBACK_SPEED**, the value is an enumerated value of [AVPlaybackSpeed](capi-avplayer-base-h.md#avplaybackspeed). The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value and forcibly converts the value to an enumerated value of [AVPlaybackSpeed](capi-avplayer-base-h.md#avplaybackspeed).|
| AV_INFO_TYPE_BITRATEDONE = 2 | Message returned when the bit rate setting is complete.<br>If **key** is set to **OH_PLAYER_BITRATE**, the value type is uint32_t. The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value and forcibly converts the value to the uint32_t type.|
| AV_INFO_TYPE_EOS = 3 | Message returned when the playback is complete.|
| AV_INFO_TYPE_STATE_CHANGE = 4 | Message returned when the AVPlayer state changes.<br>If **key** is set to **OH_PLAYER_STATE**, the value type is int32_t. The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value and forcibly converts the value to an enumerated value of [AVPlayerState](capi-avplayer-base-h.md#avplayerstate).<br>If **key** is set to **OH_PLAYER_STATE_CHANGE_REASON**, the value type is int32_t. The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value. The value **1** means that the change is triggered by user operations, and **2** means that the change is triggered by the system.|
| AV_INFO_TYPE_POSITION_UPDATE = 5 | Message returned when the playback position changes.<br>If **key** is set to **OH_PLAYER_CURRENT_POSITION**, the value type is int32_t. The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value.|
| AV_INFO_TYPE_MESSAGE = 6 | Message returned when video rendering starts.<br>If **key** is set to **OH_PLAYER_MESSAGE_TYPE**, the value type is int32_t. The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value. The value **1** means that video rendering starts.|
| AV_INFO_TYPE_VOLUME_CHANGE = 7 | Message returned when the playback volume changes.<br>If **key** is set to **OH_PLAYER_VOLUME**, the value type is float. The system uses float to transfer the value, and the application uses float to obtain the value. The value range is [0.0, 1.0].|
| AV_INFO_TYPE_RESOLUTION_CHANGE = 8 | Message returned when the video size is obtained for the first time or the video size is updated.<br>If **key** is set to **OH_PLAYER_VIDEO_WIDTH** or **OH_PLAYER_VIDEO_HEIGHT**, the value type is int32_t. The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value.|
| AV_INFO_TYPE_BUFFERING_UPDATE = 9 | Message returned when multi-queue buffering changes.<br>If **key** is set to **OH_PLAYER_BUFFERING_TYPE**, the value is an enumerated value of [AVPlayerBufferingType](capi-avplayer-base-h.md#avplayerbufferingtype). The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value and forcibly converts the value to an enumerated value of [AVPlayerBufferingType](capi-avplayer-base-h.md#avplayerbufferingtype).<br>If **key** is set to **OH_PLAYER_BUFFERING_VALUE**, the value type is int32_t. The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value.<br>This value is valid when the buffer update message type is **AVPLAYER_BUFFERING_PERCENT** or **AVPLAYER_BUFFERING_CACHED_DURATION**, which indicate the percentage of the buffer progress and the duration that the cached data can play, respectively.|
| AV_INFO_TYPE_BITRATE_COLLECT = 10 | Message returned to report the HLS video bit rates.<br>If **key** is set to **OH_PLAYER_BITRATE_ARRAY**, the value type is uint8_t. The application uses a pointer variable of the uint8_t type to store the bit rate list and uses a variable of the size_t type to store the byte array length. Then it allocates several storage spaces of the uint32_t type to receive the bit rate integer of the uint32_t type, which is converted from the uint8_t byte array.|
| AV_INFO_TYPE_INTERRUPT_EVENT = 11 | Message returned when the audio focus changes.<br>The value type is int32_t. The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value.<br>**key** can be set to any of the following values:<br>**OH_PLAYER_AUDIO_INTERRUPT_TYPE**: The value **1** means that the audio interruption event starts, and **2** means that the event ends.<br>**OH_PLAYER_AUDIO_INTERRUPT_FORCE**: The value **0** means forcible interruption (the system changes the audio playback status), and **1** means sharing interruption (the application changes the audio playback status).<br>**OH_PLAYER_AUDIO_INTERRUPT_HINT**: The value **0** (NONE) means no hint; **1** (RESUME) means that the audio playback is resumed; **2** (PAUSE) means that the audio playback is paused and loses focus; **3** (STOP) means that the audio playback is stopped; **4** (DUCK) means that the audio volume is reduced; **5** (UNDUCK) means that the audio volume is restored.|
| AV_INFO_TYPE_DURATION_UPDATE = 12 | Message returned when the playback duration changes.<br>If **key** is set to **OH_PLAYER_DURATION**, the value type is int64_t. The system uses int64_t to transfer the value, and the application uses int64_t to obtain the value.|
| AV_INFO_TYPE_IS_LIVE_STREAM = 13 | Message returned when live streams are played. If **key** is set to **OH_PLAYER_IS_LIVE_STREAM**, the value type is int32_t. The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value. The value **0** means a non-live stream, and **1** means a live stream.|
| AV_INFO_TYPE_TRACKCHANGE = 14 | Message returned when the track changes. **extra** is not defined in this scenario.|
| AV_INFO_TYPE_TRACK_INFO_UPDATE = 15 | Message returned when the track information updates. **extra** is not defined in this scenario.|
| AV_INFO_TYPE_SUBTITLE_UPDATE = 16 | Message returned when the subtitle information changes. **extra** is not defined in this scenario.|
| AV_INFO_TYPE_AUDIO_OUTPUT_DEVICE_CHANGE = 17 | Message returned when the audio output device changes.<br>If **key** is set to **OH_PLAYER_AUDIO_DEVICE_CHANGE_REASON**, the value type is int32_t. The system uses int32_t to transfer the value, and the application uses int32_t to obtain the value.|
| AV_INFO_TYPE_PLAYBACK_RATE_DONE = 18 | Message returned when the playback rate is applied.<br>If **key** is set to **OH_PLAYER_PLAYBACK_RATE**, the value type is float. The system uses float to transfer the value, and the application uses float to obtain the value.<br>**Since**: 20|

### AVPlayerBufferingType

```
enum AVPlayerBufferingType
```

**Description**

Enumerates the types of buffer messages of the AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12

| Enum Item| Description|
| -- | -- |
| AVPLAYER_BUFFERING_START = 1 | Buffering start message.|
| AVPLAYER_BUFFERING_END | Buffering end message.|
| AVPLAYER_BUFFERING_PERCENT | Buffer execution progress, in percentage. The value is an integer in the range [0, 100].|
| AVPLAYER_BUFFERING_CACHED_DURATION | Duration that cached data can be played, in milliseconds.|


## Function Description

### OH_AVPlayerOnInfo()

```
typedef void (*OH_AVPlayerOnInfo)(OH_AVPlayer *player, AVPlayerOnInfoType type, int32_t extra)
```

**Description**

Called when the AVPlayer receives a message.

The following table lists the mappings between **type** and **extra** values.

| Value of type| Value of extra|
| -------- | -------- |
| AV_INFO_TYPE_SEEKDONE | Message returned when seeking to a playback position is complete. **extra** indicates the position after the seek operation.|
| AV_INFO_TYPE_SPEEDDONE | Message returned when the playback speed setting is complete. **extra** indicates the playback speed. For details about the available options, see [AVPlaybackSpeed](#avplaybackspeed).|
| AV_INFO_TYPE_BITRATEDONE | Message returned when the bit rate setting is complete. **extra** indicates the bit rate.|
| AV_INFO_TYPE_EOS | Message returned when the playback is complete.|
| AV_INFO_TYPE_STATE_CHANGE | Message returned when the AVPlayer state changes. **extra** indicates the new state. For details about the available options, see [AVPlayerState](#avplayerstate).|
| AV_INFO_TYPE_POSITION_UPDATE | Message returned when the playback position changes. **extra** indicates the current position.|
| AV_INFO_TYPE_MESSAGE | Message returned when video rendering starts. **extra** indicates the first video frame rendered.|
| AV_INFO_TYPE_VOLUME_CHANGE | Message returned when the playback volume changes. **extra** is not defined in this scenario.|
| AV_INFO_TYPE_RESOLUTION_CHANGE | Message returned when the video size is obtained for the first time or the video size is updated. **extra** is not defined in this scenario.|
| AV_INFO_TYPE_BUFFERING_UPDATE | Message returned when multi-queue buffering changes. **extra** indicates the video duration.|
| AV_INFO_TYPE_BITRATE_COLLECT  | Message returned to report the HLS video bit rates. Each bit rate has been converted into a uint8_t byte array during the reporting. You need to forcibly convert the uint8_t byte array into a uint32_t integer array.  |
| AV_INFO_TYPE_INTERRUPT_EVENT | Message returned when the audio focus changes. **extra** indicates the hints provided along with audio interruption. For details about the available options, see [OH_AudioInterrupt_Hint](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiointerrupt_hint). The application can determine whether to perform further processing based on the hint.|
| AV_INFO_TYPE_DURATION_UPDATE | Message returned when the playback duration changes. **extra** indicates the video duration.|
| AV_INFO_TYPE_IS_LIVE_STREAM | Message returned when live streams are played. **extra** indicates whether the stream is a live stream. The value **0** means a non-live stream, and **1** means a live stream.|
| AV_INFO_TYPE_TRACKCHANGE | Message returned when the track changes. **extra** is not defined in this scenario.|
| AV_INFO_TYPE_TRACK_INFO_UPDATE |Message returned when the track information updates. **extra** is not defined in this scenario.|
| AV_INFO_TYPE_SUBTITLE_UPDATE | Message returned when the subtitle information changes. **extra** is not defined in this scenario.|
| AV_INFO_TYPE_AUDIO_OUTPUT_DEVICE_CHANGE | Message returned when the audio output device changes. **extra** indicates the device change reason. For details about the available options, see [OH_AudioStream_DeviceChangeReason](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_devicechangereason).|

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Deprecated from**: 12

**Substitute**: [OH_AVPlayerOnInfoCallback](capi-avplayer-base-h.md#oh_avplayeroninfocallback)


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | Pointer to an **OH_AVPlayer** instance.|
| [AVPlayerOnInfoType](capi-avplayer-base-h.md#avplayeroninfotype) type | Message type. For details about the available options, see [AVPlayerOnInfoType](capi-avplayer-base-h.md#avplayeroninfotype). For details about the mappings between **type** and **extra** values, see the function description.|
|  int32_t extra | Other information, such as the start time and position of the media file to play.|

### OH_AVPlayerOnInfoCallback()

```
typedef void (*OH_AVPlayerOnInfoCallback)(OH_AVPlayer *player, AVPlayerOnInfoType type, OH_AVFormat* infoBody,void *userData)
```

**Description**

Called when the AVPlayer receives a message. If this callback is successfully set, the **OH_AVPlayerOnInfo** function will not be invoked.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | Pointer to an **OH_AVPlayer** instance.|
| [AVPlayerOnInfoType](capi-avplayer-base-h.md#avplayeroninfotype) type | Message type. For details about the available options, see [AVPlayerOnInfoType](capi-avplayer-base-h.md#avplayeroninfotype).|
| [OH_AVFormat](../apis-avcodec-kit/_core.md#oh_avformat)* infoBody | Pointer to the message. The pointer is valid only in this callback.|
| void *userData | Pointer to the instance provided by the caller when setting the callback function.|

### OH_AVPlayerOnError()

```
typedef void (*OH_AVPlayerOnError)(OH_AVPlayer *player, int32_t errorCode, const char *errorMsg)
```

**Description**

Defines the callback when an error occurs in the AVPlayer. This type is available in API version 9 or later.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Deprecated from**: 12

**Substitute**: [OH_AVPlayerOnInfoCallback](capi-avplayer-base-h.md#oh_avplayeroninfocallback) and [OH_AVPlayerOnError](capi-avplayer-base-h.md#oh_avplayeronerror)


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | Pointer to an **OH_AVPlayer** instance.|
|  int32_t errorCode | Error code.<br>**AV_ERR_NO_MEMORY**: No memory. The value is **1**.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The value is **2**.<br>**AV_ERR_INVALID_VAL**: Invalid value. The value is **3**.<br>**AV_ERR_IO**: I/O error. The value is **4**.<br>**AV_ERR_TIMEOUT**: Timeout. The value is **5**.<br>**AV_ERR_UNKNOWN**: Unknown error. The value is **6**.<br>**AV_ERR_SERVICE_DIED**: The service is dead. The value is **7**.<br>**AV_ERR_INVALID_STATE**: The operation is not supported in the current state. The value is **8**.<br>**AV_ERR_UNSUPPORT**: The function is not supported. The value is **9**.<br>**AV_ERR_EXTEND_START**: Initial value for extended error codes. The value is **100**.|
|  const char *errorMsg | Pointer to the error message.|

### OH_AVPlayerOnErrorCallback()

```
typedef void (*OH_AVPlayerOnErrorCallback)(OH_AVPlayer *player, int32_t errorCode, const char *errorMsg,void *userData)
```

**Description**

Called when an error occurs in the AVPlayer. If this callback is successfully set, the **OH_AVPlayerOnError** function will not be invoked.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | Pointer to an **OH_AVPlayer** instance.|
|  int32_t errorCode | Error code.<br>**AV_ERR_NO_MEMORY**: No memory. The value is **1**.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The value is **2**.<br>**AV_ERR_INVALID_VAL**: Invalid value. The value is **3**.<br>**AV_ERR_IO**: I/O error. The value is **4**.<br>**AV_ERR_TIMEOUT**: Timeout. The value is **5**.<br>**AV_ERR_UNKNOWN**: Unknown error. The value is **6**.<br>**AV_ERR_SERVICE_DIED**: The service is dead. The value is **7**.<br>**AV_ERR_INVALID_STATE**: The operation is not supported in the current state. The value is **8**.<br>**AV_ERR_UNSUPPORT**: The function is not supported. The value is **9**.<br>**AV_ERR_EXTEND_START**: Initial value for extended error codes. The value is **100**.|
|  const char *errorMsg | Pointer to the error message.|
| void *userData | Pointer to the user data passed in. The same data is returned.|

 <!--no_check--> 