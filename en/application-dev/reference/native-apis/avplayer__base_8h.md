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
| [AVPlayerState](_a_v_player.md#avplayerstate) {<br>[AV_IDLE](_a_v_player.md) = 0, [AV_INITIALIZED](_a_v_player.md) = 1, [AV_PREPARED](_a_v_player.md) = 2, [AV_PLAYING](_a_v_player.md) = 3,<br>[AV_PAUSED](_a_v_player.md) = 4, [AV_STOPPED](_a_v_player.md) = 5, [AV_COMPLETED](_a_v_player.md) = 6, [AV_RELEASED](_a_v_player.md) = 7,<br>[AV_ERROR](_a_v_player.md) = 8<br>} | Enumerates the AVPlayer states.| 
| [AVPlayerSeekMode](_a_v_player.md#avplayerseekmode) { [AV_SEEK_NEXT_SYNC](_a_v_player.md) = 0, [AV_SEEK_PREVIOUS_SYNC](_a_v_player.md) } | Enumerates the seek modes of the AVPlayer.| 
| [AVPlaybackSpeed](_a_v_player.md#avplaybackspeed) {<br>[AV_SPEED_FORWARD_0_75_X](_a_v_player.md), [AV_SPEED_FORWARD_1_00_X](_a_v_player.md), [AV_SPEED_FORWARD_1_25_X](_a_v_player.md), [AV_SPEED_FORWARD_1_75_X](_a_v_player.md),<br>[AV_SPEED_FORWARD_2_00_X](_a_v_player.md)<br>} | Enumerates the playback speeds of the AVPlayer.| 
| [AVPlayerOnInfoType](_a_v_player.md#avplayeroninfotype) {<br>[AV_INFO_TYPE_SEEKDONE](_a_v_player.md) = 0, [AV_INFO_TYPE_SPEEDDONE](_a_v_player.md) = 1, [AV_INFO_TYPE_BITRATEDONE](_a_v_player.md) = 2, [AV_INFO_TYPE_EOS](_a_v_player.md) = 3,<br>[AV_INFO_TYPE_STATE_CHANGE](_a_v_player.md) = 4, [AV_INFO_TYPE_POSITION_UPDATE](_a_v_player.md) = 5, [AV_INFO_TYPE_MESSAGE](_a_v_player.md) = 6, [AV_INFO_TYPE_VOLUME_CHANGE](_a_v_player.md) = 7,<br>[AV_INFO_TYPE_RESOLUTION_CHANGE](_a_v_player.md) = 8, [AV_INFO_TYPE_BUFFERING_UPDATE](_a_v_player.md) = 9, [AV_INFO_TYPE_BITRATE_COLLECT](_a_v_player.md) = 10, [AV_INFO_TYPE_INTERRUPT_EVENT](_a_v_player.md) = 11,<br>[AV_INFO_TYPE_DURATION_UPDATE](_a_v_player.md) = 12, [AV_INFO_TYPE_IS_LIVE_STREAM](_a_v_player.md) = 13, [AV_INFO_TYPE_TRACKCHANGE](_a_v_player.md) = 14, [AV_INFO_TYPE_TRACK_INFO_UPDATE](_a_v_player.md) = 15,<br>[AV_INFO_TYPE_SUBTITLE_UPDATE](_a_v_player.md) = 16<br>} | Enumerates the types of messages received by the AVPlayer.| 
