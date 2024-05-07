# avplayer_base.h


## Overview

The **avplayer_base.h** file declares the structs and enums of the AVPlayer.

**Library**: libavplayer.so

**Since**: 11

**Related module**: [AVPlayer](_a_v_player.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| [AVPlayerCallback](_a_v_player_callback.md) | Defines all the callback function pointers of an **OH_AVPlayer** instance.| 


### Types

| Name| Description| 
| -------- | -------- |
| [AVPlayerState](_a_v_player.md#avplayerstate) | Defines an enum for AVPlayer states.| 
| [AVPlayerSeekMode](_a_v_player.md#avplayerseekmode) | Defines an enum for seek modes of the AVPlayer.| 
| [AVPlaybackSpeed](_a_v_player.md#avplaybackspeed) | Defines an enum for playback speeds of the AVPlayer.| 
| [AVPlayerOnInfoType](_a_v_player.md#avplayeroninfotype) | Defines an enum for types of messages received by the AVPlayer.| 
| (\*[OH_AVPlayerOnInfo](_a_v_player.md#oh_avplayeroninfo)) (OH_AVPlayer \*player, [AVPlayerOnInfoType](_a_v_player.md#avplayeroninfotype) type, int32_t extra) | Defines the callback when the AVPlayer receives a message.| 
| (\*[OH_AVPlayerOnError](_a_v_player.md#oh_avplayeronerror)) (OH_AVPlayer \*player, int32_t errorCode, const char \*errorMsg) | Defines the callback when an error occurs in the AVPlayer. This type is available in API version 9 or later.| 
| [AVPlayerCallback](_a_v_player.md#avplayercallback) | Defines all the callback function pointers of an **OH_AVPlayer** instance.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [AVPlayerState](_a_v_player.md#avplayerstate) {<br>AV_IDLE = 0, <br>AV_INITIALIZED = 1, <br>AV_PREPARED = 2, <br>AV_PLAYING = 3,<br>AV_PAUSED = 4, <br>AV_STOPPED = 5, <br>AV_COMPLETED = 6, <br>AV_RELEASED = 7,<br>AV_ERROR = 8<br>} | Enumerates the AVPlayer states.| 
| [AVPlayerSeekMode](_a_v_player.md#avplayerseekmode) { <br>AV_SEEK_NEXT_SYNC = 0, <br>AV_SEEK_PREVIOUS_SYNC, <br>AV_SEEK_CLOSEST = 2<br>} | Enumerates the seek modes of the AVPlayer.| 
| [AVPlaybackSpeed](_a_v_player.md#avplaybackspeed) {<br>AV_SPEED_FORWARD_0_75_X, <br>AV_SPEED_FORWARD_1_00_X, <br>AV_SPEED_FORWARD_1_25_X, <br>AV_SPEED_FORWARD_1_75_X,<br>AV_SPEED_FORWARD_2_00_X<br>} | Enumerates the playback speeds of the AVPlayer.| 
| [AVPlayerOnInfoType](_a_v_player.md#avplayeroninfotype) {<br>AV_INFO_TYPE_SEEKDONE = 0, <br>AV_INFO_TYPE_SPEEDDONE = 1, <br>AV_INFO_TYPE_BITRATEDONE = 2, <br>AV_INFO_TYPE_EOS = 3,<br>AV_INFO_TYPE_STATE_CHANGE = 4, <br>AV_INFO_TYPE_POSITION_UPDATE = 5, <br>AV_INFO_TYPE_MESSAGE = 6, <br>AV_INFO_TYPE_VOLUME_CHANGE = 7,<br>AV_INFO_TYPE_RESOLUTION_CHANGE = 8, <br>AV_INFO_TYPE_BUFFERING_UPDATE = 9, <br>AV_INFO_TYPE_BITRATE_COLLECT = 10, <br>AV_INFO_TYPE_INTERRUPT_EVENT = 11,<br>AV_INFO_TYPE_DURATION_UPDATE = 12, <br>AV_INFO_TYPE_IS_LIVE_STREAM = 13, <br>AV_INFO_TYPE_TRACKCHANGE = 14, <br>AV_INFO_TYPE_TRACK_INFO_UPDATE = 15,<br>AV_INFO_TYPE_SUBTITLE_UPDATE = 16, AV_INFO_TYPE_AUDIO_OUTPUT_DEVICE_CHANGE = 17<br>} | Enumerates the types of messages received by the AVPlayer.| 
