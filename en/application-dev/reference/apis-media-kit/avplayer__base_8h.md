# avplayer_base.h


## Overview

The **avplayer_base.h** file declares the structs and enums of the AVPlayer.

**Library**: libavplayer.so

**File to include**: <multimedia/player_framework/avplayer_base.h>

**Since**: 11

**Related module**: [AVPlayer](_a_v_player.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [AVPlayerCallback](_a_v_player_callback.md) | (Deprecated) Contains the set of the **OH_AVPlayerOnInfo** and **OH_AVPlayerOnInfo** callback function pointers. To ensure the normal running of **OH_AVPlayer**, you must register the instance of this struct with the **OH_AVPlayer** instance and process the information reported by the callback functions. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [AVPlayerState](_a_v_player.md#avplayerstate-1) [AVPlayerState](_a_v_player.md#avplayerstate) | Defines an enum for the AVPlayer states. | 
| typedef enum [AVPlayerSeekMode](_a_v_player.md#avplayerseekmode-1) [AVPlayerSeekMode](_a_v_player.md#avplayerseekmode) | Defines an enum for the seek modes of the AVPlayer. | 
| typedef enum [AVPlaybackSpeed](_a_v_player.md#avplaybackspeed-1) [AVPlaybackSpeed](_a_v_player.md#avplaybackspeed) | Defines an enum for the playback speeds of the AVPlayer. | 
| typedef enum [AVPlayerOnInfoType](_a_v_player.md#avplayeroninfotype-1) [AVPlayerOnInfoType](_a_v_player.md#avplayeroninfotype) | Defines an enum for the types of messages received by the AVPlayer. | 
| typedef enum [AVPlayerBufferingType](_a_v_player.md#avplayerbufferingtype-1) [AVPlayerBufferingType](_a_v_player.md#avplayerbufferingtype) | Defines the types of buffer messages of the AVPlayer. | 
| typedef void(\* [OH_AVPlayerOnInfo](_a_v_player.md#oh_avplayeroninfo)) (OH_AVPlayer \*player, [AVPlayerOnInfoType](_a_v_player.md#avplayeroninfotype) type, int32_t extra) | (Deprecated) Defines the callback invoked when the AVPlayer receives a message. | 
| typedef void(\* [OH_AVPlayerOnInfoCallback](_a_v_player.md#oh_avplayeroninfocallback)) (OH_AVPlayer \*player, [AVPlayerOnInfoType](_a_v_player.md#avplayeroninfotype) type, OH_AVFormat \*infoBody, void \*userData) | Defines the callback invoked when the AVPlayer receives a message. If this callback is successfully set, the **OH_AVPlayerOnInfo** function will not be invoked. | 
| typedef void(\* [OH_AVPlayerOnError](_a_v_player.md#oh_avplayeronerror)) (OH_AVPlayer \*player, int32_t errorCode, const char \*errorMsg) | (Deprecated) Defines the callback invoked when an error occurs in the AVPlayer. This type is available in API version 9 or later. | 
| typedef void(\* [OH_AVPlayerOnErrorCallback](_a_v_player.md#oh_avplayeronerrorcallback)) (OH_AVPlayer \*player, int32_t errorCode, const char \*errorMsg, void \*userData) | Defines the callback invoked when an error occurs in the AVPlayer. If this callback is successfully set, the **OH_AVPlayerOnError** function will not be invoked. | 
| typedef struct [AVPlayerCallback](_a_v_player_callback.md) [AVPlayerCallback](_a_v_player.md#avplayercallback) | Defines all the callback function pointers of an **OH_AVPlayer** instance. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [AVPlayerState](_a_v_player.md#avplayerstate-1) {<br>AV_IDLE = 0, <br>AV_INITIALIZED = 1, <br>AV_PREPARED = 2, <br>AV_PLAYING = 3,<br>AV_PAUSED = 4, <br>AV_STOPPED = 5, <br>AV_COMPLETED = 6, <br>AV_RELEASED = 7,<br>AV_ERROR = 8<br>} | Enumerates the AVPlayer states.| 
| [AVPlayerSeekMode](_a_v_player.md#avplayerseekmode) { <br>AV_SEEK_NEXT_SYNC = 0, <br>AV_SEEK_PREVIOUS_SYNC, <br>AV_SEEK_CLOSEST = 2<br>} | Enumerates the seek modes of the AVPlayer.| 
| [AVPlaybackSpeed](_a_v_player.md#avplaybackspeed-1) {<br>AV_SPEED_FORWARD_0_75_X, <br>AV_SPEED_FORWARD_1_00_X, <br>AV_SPEED_FORWARD_1_25_X, <br> AV_SPEED_FORWARD_1_75_X,<br>AV_SPEED_FORWARD_2_00_X, <br>AV_SPEED_FORWARD_0_50_X, <br>AV_SPEED_FORWARD_1_50_X<br>} | Enumerates the playback speeds of the AVPlayer. | 
| [AVPlayerOnInfoType](_a_v_player.md#avplayeroninfotype-1) {<br>AV_INFO_TYPE_SEEKDONE = 0, <br>AV_INFO_TYPE_SPEEDDONE = 1, <br>AV_INFO_TYPE_BITRATEDONE = 2, <br>AV_INFO_TYPE_EOS = 3,<br>AV_INFO_TYPE_STATE_CHANGE = 4, <br>AV_INFO_TYPE_POSITION_UPDATE = 5, <br>AV_INFO_TYPE_MESSAGE = 6, <br>AV_INFO_TYPE_VOLUME_CHANGE = 7,<br>AV_INFO_TYPE_RESOLUTION_CHANGE = 8, <br>AV_INFO_TYPE_BUFFERING_UPDATE = 9, <br>AV_INFO_TYPE_BITRATE_COLLECT = 10, <br>AV_INFO_TYPE_INTERRUPT_EVENT = 11,<br>AV_INFO_TYPE_DURATION_UPDATE = 12, <br>AV_INFO_TYPE_IS_LIVE_STREAM = 13, <br>AV_INFO_TYPE_TRACKCHANGE = 14, <br>AV_INFO_TYPE_TRACK_INFO_UPDATE = 15,<br>AV_INFO_TYPE_SUBTITLE_UPDATE = 16, AV_INFO_TYPE_AUDIO_OUTPUT_DEVICE_CHANGE = 17<br>} | Enumerates the types of messages received by the AVPlayer.| 
| [AVPlayerBufferingType](_a_v_player.md#avplayerbufferingtype-1) { <br>AVPLAYER_BUFFERING_START = 1, <br>AVPLAYER_BUFFERING_END, <br>AVPLAYER_BUFFERING_PERCENT, <br>AVPLAYER_BUFFERING_CACHED_DURATION <br>} | Enumerates the types of buffer messages of the AVPlayer. | 


### Variables

| Name| Description| 
| -------- | -------- |
| const char \* [OH_PLAYER_STATE](_a_v_player.md#oh_player_state) | Pointer to the key for obtaining the AVPlayer state. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_STATE_CHANGE_REASON](_a_v_player.md#oh_player_state_change_reason) | Pointer to the key for obtaining the AVPlayer state change reason. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_VOLUME](_a_v_player.md#oh_player_volume) | Pointer to the key for obtaining the volume. The value type is float. | 
| const char \* [OH_PLAYER_BITRATE_ARRAY](_a_v_player.md#oh_player_bitrate_array) | Pointer to the key for obtaining the bit rate array. The value is of the uint8_t byte array type, which is expressed by [AV_INFO_TYPE_BITRATE_COLLECT](_a_v_player.md#avplayeroninfotype-1). | 
| const char \* [OH_PLAYER_AUDIO_INTERRUPT_TYPE](_a_v_player.md#oh_player_audio_interrupt_type) | Pointer to the key for obtaining the audio interruption type. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_AUDIO_INTERRUPT_FORCE](_a_v_player.md#oh_player_audio_interrupt_force) | Pointer to the key for obtaining the FORCE type of audio interruption. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_AUDIO_INTERRUPT_HINT](_a_v_player.md#oh_player_audio_interrupt_hint) | Pointer to the key for obtaining the HINT type of audio interruption. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_AUDIO_DEVICE_CHANGE_REASON](_a_v_player.md#oh_player_audio_device_change_reason) | Pointer to the key for obtaining the audio device change reason. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_BUFFERING_TYPE](_a_v_player.md#oh_player_buffering_type) | Pointer to the key for obtaining the type of the buffer update message. The value type is **AVPlayerBufferingType**. | 
| const char \* [OH_PLAYER_BUFFERING_VALUE](_a_v_player.md#oh_player_buffering_value) | Pointer to the key for obtaining the value of the buffer update message. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_SEEK_POSITION](_a_v_player.md#oh_player_seek_position) | Pointer to the key for obtaining the playback progress after the seek operation. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_PLAYBACK_SPEED](_a_v_player.md#oh_player_playback_speed) | Pointer to the key for obtaining the playback speed. The value type is **AVPlaybackSpeed**. | 
| const char \* [OH_PLAYER_BITRATE](_a_v_player.md#oh_player_bitrate) | Pointer to the key for obtaining the bit rate. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_CURRENT_POSITION](_a_v_player.md#oh_player_current_position) | Pointer to the key for obtaining the playback progress information. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_DURATION](_a_v_player.md#oh_player_duration) | Pointer to the key for obtaining the media asset duration. The value type is int64_t. | 
| const char \* [OH_PLAYER_VIDEO_WIDTH](_a_v_player.md#oh_player_video_width) | Pointer to the key for obtaining the video width. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_VIDEO_HEIGHT](_a_v_player.md#oh_player_video_height) | Pointer to the key for obtaining the video height. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_MESSAGE_TYPE](_a_v_player.md#oh_player_message_type) | Pointer to the key for obtaining the type of message received by the AVPlayer. The value is of the int32_t type. | 
| const char \* [OH_PLAYER_IS_LIVE_STREAM](_a_v_player.md#oh_player_is_live_stream) | Pointer to the key for checking whether a media asset is live TV. The value is of the int32_t type. | 
