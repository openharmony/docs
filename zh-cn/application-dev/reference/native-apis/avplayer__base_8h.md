# avplayer_base.h


## 概述

定义AVPlayer的结构体和枚举。

**库：** libavplayer.so

**起始版本：** 11

**相关模块：**[AVPlayer](_a_v_player.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [AVPlayerCallback](_a_v_player_callback.md) | OH_AVPlayer中所有回调函数指针的集合。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [AVPlayerState](_a_v_player.md#avplayerstate) | 播放状态 | 
| [AVPlayerSeekMode](_a_v_player.md#avplayerseekmode) | 跳转模式 | 
| [AVPlaybackSpeed](_a_v_player.md#avplaybackspeed) | 播放速度 | 
| [AVPlayerOnInfoType](_a_v_player.md#avplayeroninfotype) | OnInfo类型 | 
| (\*[OH_AVPlayerOnInfo](_a_v_player.md#oh_avplayeroninfo)) (OH_AVPlayer \*player, [AVPlayerOnInfoType](_a_v_player.md#avplayeroninfotype) type, int32_t extra) | 收到播放器消息时调用。 | 
| (\*[OH_AVPlayerOnError](_a_v_player.md#oh_avplayeronerror)) (OH_AVPlayer \*player, int32_t errorCode, const char \*errorMsg) | 在API 9以上的版本发生错误时调用 | 
| [AVPlayerCallback](_a_v_player.md#avplayercallback) | OH_AVPlayer中所有回调函数指针的集合。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [AVPlayerState](_a_v_player.md#avplayerstate) {<br/>[AV_IDLE](_a_v_player.md) = 0, [AV_INITIALIZED](_a_v_player.md) = 1, [AV_PREPARED](_a_v_player.md) = 2, [AV_PLAYING](_a_v_player.md) = 3,<br/>[AV_PAUSED](_a_v_player.md) = 4, [AV_STOPPED](_a_v_player.md) = 5, [AV_COMPLETED](_a_v_player.md) = 6, [AV_RELEASED](_a_v_player.md) = 7,<br/>[AV_ERROR](_a_v_player.md) = 8<br/>} | 播放状态 | 
| [AVPlayerSeekMode](_a_v_player.md#avplayerseekmode) { [AV_SEEK_NEXT_SYNC](_a_v_player.md) = 0, [AV_SEEK_PREVIOUS_SYNC](_a_v_player.md) } | 跳转模式 | 
| [AVPlaybackSpeed](_a_v_player.md#avplaybackspeed) {<br/>[AV_SPEED_FORWARD_0_75_X](_a_v_player.md), [AV_SPEED_FORWARD_1_00_X](_a_v_player.md), [AV_SPEED_FORWARD_1_25_X](_a_v_player.md), [AV_SPEED_FORWARD_1_75_X](_a_v_player.md),<br/>[AV_SPEED_FORWARD_2_00_X](_a_v_player.md)<br/>} | 播放速度 | 
| [AVPlayerOnInfoType](_a_v_player.md#avplayeroninfotype) {<br/>[AV_INFO_TYPE_SEEKDONE](_a_v_player.md) = 0, [AV_INFO_TYPE_SPEEDDONE](_a_v_player.md) = 1, [AV_INFO_TYPE_BITRATEDONE](_a_v_player.md) = 2, [AV_INFO_TYPE_EOS](_a_v_player.md) = 3,<br/>[AV_INFO_TYPE_STATE_CHANGE](_a_v_player.md) = 4, [AV_INFO_TYPE_POSITION_UPDATE](_a_v_player.md) = 5, [AV_INFO_TYPE_MESSAGE](_a_v_player.md) = 6, [AV_INFO_TYPE_VOLUME_CHANGE](_a_v_player.md) = 7,<br/>[AV_INFO_TYPE_RESOLUTION_CHANGE](_a_v_player.md) = 8, [AV_INFO_TYPE_BUFFERING_UPDATE](_a_v_player.md) = 9, [AV_INFO_TYPE_BITRATE_COLLECT](_a_v_player.md) = 10, [AV_INFO_TYPE_INTERRUPT_EVENT](_a_v_player.md) = 11,<br/>[AV_INFO_TYPE_DURATION_UPDATE](_a_v_player.md) = 12, [AV_INFO_TYPE_IS_LIVE_STREAM](_a_v_player.md) = 13, [AV_INFO_TYPE_TRACKCHANGE](_a_v_player.md) = 14, [AV_INFO_TYPE_TRACK_INFO_UPDATE](_a_v_player.md) = 15,<br/>[AV_INFO_TYPE_SUBTITLE_UPDATE](_a_v_player.md) = 16<br/>} | OnInfo类型 | 
