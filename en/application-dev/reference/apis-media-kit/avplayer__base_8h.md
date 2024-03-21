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
| [AVPlayerState](_a_v_player.md#avplayerstate) | Defines an enum that enumerates the AVPlayer states.| 
| [AVPlayerSeekMode](_a_v_player.md#avplayerseekmode) | Defines an enum that enumerates the seek modes of the AVPlayer.| 
| [AVPlaybackSpeed](_a_v_player.md#avplaybackspeed) | Defines an enum that enumerates the playback speeds of the AVPlayer.| 
| [AVPlayerOnInfoType](_a_v_player.md#avplayeroninfotype) | Defines an enum that enumerates the types of messages received by the AVPlayer.| 
| (\*[OH_AVPlayerOnInfo](_a_v_player.md#oh_avplayeroninfo)) (OH_AVPlayer \*player, [AVPlayerOnInfoType](_a_v_player.md#avplayeroninfotype) type, int32_t extra) | Defines the callback when the AVPlayer receives a message.| 
| (\*[OH_AVPlayerOnError](_a_v_player.md#oh_avplayeronerror)) (OH_AVPlayer \*player, int32_t errorCode, const char \*errorMsg) | Defines the callback when an error occurs in the AVPlayer. This type is available in API version 9 or later.| 
| [AVPlayerCallback](_a_v_player.md#avplayercallback) | Defines all the callback function pointers of an **OH_AVPlayer** instance.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [AVPlayerState](_a_v_player.md#avplayerstate) {<br>AV_IDLE = 0, AV_INITIALIZED = 1, AV_PREPARED = 2, AV_PLAYING = 3,<br>AV_PAUSED = 4, AV_STOPPED = 5, AV_COMPLETED = 6, AV_RELEASED = 7,<br>AV_ERROR = 8<br>} | Enumerates the AVPlayer states.| 
| [AVPlayerSeekMode](_a_v_player.md#avplayerseekmode) { AV_SEEK_NEXT_SYNC = 0, AV_SEEK_PREVIOUS_SYNC } | Enumerates the seek modes of the AVPlayer.| 
| [AVPlaybackSpeed](_a_v_player.md#avplaybackspeed) {<br>AV_SPEED_FORWARD_0_75_X, AV_SPEED_FORWARD_1_00_X, AV_SPEED_FORWARD_1_25_X, AV_SPEED_FORWARD_1_75_X,<br>AV_SPEED_FORWARD_2_00_X<br>} | Enumerates the playback speeds of the AVPlayer.| 
| [AVPlayerOnInfoType](_a_v_player.md#avplayeroninfotype) {<br>AV_INFO_TYPE_SEEKDONE = 0, AV_INFO_TYPE_SPEEDDONE = 1, AV_INFO_TYPE_BITRATEDONE = 2, AV_INFO_TYPE_EOS = 3,<br>AV_INFO_TYPE_STATE_CHANGE = 4, AV_INFO_TYPE_POSITION_UPDATE = 5, AV_INFO_TYPE_MESSAGE = 6, AV_INFO_TYPE_VOLUME_CHANGE = 7,<br>AV_INFO_TYPE_RESOLUTION_CHANGE = 8, AV_INFO_TYPE_BUFFERING_UPDATE = 9, AV_INFO_TYPE_BITRATE_COLLECT = 10, AV_INFO_TYPE_INTERRUPT_EVENT = 11,<br>AV_INFO_TYPE_DURATION_UPDATE = 12, AV_INFO_TYPE_IS_LIVE_STREAM = 13, AV_INFO_TYPE_TRACKCHANGE = 14, AV_INFO_TYPE_TRACK_INFO_UPDATE = 15,<br>AV_INFO_TYPE_SUBTITLE_UPDATE = 16, AV_INFO_TYPE_AUDIO_OUTPUT_DEVICE_CHANGE = 17<br>} | Enumerates the types of messages received by the AVPlayer.| 
