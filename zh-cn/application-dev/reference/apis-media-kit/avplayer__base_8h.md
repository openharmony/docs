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
| [AVPlayerState](_a_v_player.md#avplayerstate) {<br/>AV_IDLE = 0, AV_INITIALIZED = 1, AV_PREPARED = 2, AV_PLAYING = 3,<br/>AV_PAUSED = 4, AV_STOPPED = 5, AV_COMPLETED = 6, AV_RELEASED = 7,<br/>AV_ERROR = 8<br/>} | 播放状态 | 
| [AVPlayerSeekMode](_a_v_player.md#avplayerseekmode) { <br/>AV_SEEK_NEXT_SYNC = 0, <br/>AV_SEEK_PREVIOUS_SYNC, <br/>AV_SEEK_CLOSEST = 2<br/>} | 跳转模式 | 
| [AVPlaybackSpeed](_a_v_player.md#avplaybackspeed) {<br/>AV_SPEED_FORWARD_0_75_X, AV_SPEED_FORWARD_1_00_X, AV_SPEED_FORWARD_1_25_X, AV_SPEED_FORWARD_1_75_X,<br/>AV_SPEED_FORWARD_2_00_X<br/>} | 播放速度 | 
| [AVPlayerOnInfoType](_a_v_player.md#avplayeroninfotype) {<br/>AV_INFO_TYPE_SEEKDONE = 0, AV_INFO_TYPE_SPEEDDONE = 1, AV_INFO_TYPE_BITRATEDONE = 2, AV_INFO_TYPE_EOS = 3,<br/>AV_INFO_TYPE_STATE_CHANGE = 4, AV_INFO_TYPE_POSITION_UPDATE = 5, AV_INFO_TYPE_MESSAGE = 6, AV_INFO_TYPE_VOLUME_CHANGE = 7,<br/>AV_INFO_TYPE_RESOLUTION_CHANGE = 8, AV_INFO_TYPE_BUFFERING_UPDATE = 9, AV_INFO_TYPE_BITRATE_COLLECT = 10, AV_INFO_TYPE_INTERRUPT_EVENT = 11,<br/>AV_INFO_TYPE_DURATION_UPDATE = 12, AV_INFO_TYPE_IS_LIVE_STREAM = 13, AV_INFO_TYPE_TRACKCHANGE = 14, AV_INFO_TYPE_TRACK_INFO_UPDATE = 15,<br/>AV_INFO_TYPE_SUBTITLE_UPDATE = 16, AV_INFO_TYPE_AUDIO_OUTPUT_DEVICE_CHANGE = 17<br/>} | OnInfo类型 | 
