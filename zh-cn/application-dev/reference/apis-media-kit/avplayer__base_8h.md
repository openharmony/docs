# avplayer_base.h


## 概述

定义AVPlayer的结构体和枚举。

**库：** libavplayer.so

**引用文件：** <multimedia/player_framework/avplayer_base.h>

**起始版本：** 11

**相关模块：**[AVPlayer](_a_v_player.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [AVPlayerCallback](_a_v_player_callback.md) | （已废弃）包含了OH_AVPlayerOnInfo和OH_AVPlayerOnInfo回调函数指针的集合。注册此的实例结构体到OH_AVPlayer实例中，并对回调上报的信息进行处理，保证AVPlayer的正常运行。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [AVPlayerState](_a_v_player.md#avplayerstate-1) [AVPlayerState](_a_v_player.md#avplayerstate) | 播放状态。  | 
| typedef enum [AVPlayerSeekMode](_a_v_player.md#avplayerseekmode-1) [AVPlayerSeekMode](_a_v_player.md#avplayerseekmode) | 跳转模式。  | 
| typedef enum [AVPlaybackSpeed](_a_v_player.md#avplaybackspeed-1) [AVPlaybackSpeed](_a_v_player.md#avplaybackspeed) | 播放速度。  | 
| typedef enum [AVPlayerOnInfoType](_a_v_player.md#avplayeroninfotype-1) [AVPlayerOnInfoType](_a_v_player.md#avplayeroninfotype) | OnInfo类型。  | 
| typedef enum [AVPlayerBufferingType](_a_v_player.md#avplayerbufferingtype-1) [AVPlayerBufferingType](_a_v_player.md#avplayerbufferingtype) | 播放缓冲消息类型定义。  | 
| typedef void(\* [OH_AVPlayerOnInfo](_a_v_player.md#oh_avplayeroninfo)) (OH_AVPlayer \*player, [AVPlayerOnInfoType](_a_v_player.md#avplayeroninfotype) type, int32_t extra) | （已废弃）收到播放器消息时调用。  | 
| typedef void(\* [OH_AVPlayerOnInfoCallback](_a_v_player.md#oh_avplayeroninfocallback)) (OH_AVPlayer \*player, [AVPlayerOnInfoType](_a_v_player.md#avplayeroninfotype) type, OH_AVFormat \*infoBody, void \*userData) | 收到播放器消息时被调用。如果应用成功设置该回调，则不会回调OH_AVPlayerOnInfo函数。  | 
| typedef void(\* [OH_AVPlayerOnError](_a_v_player.md#oh_avplayeronerror)) (OH_AVPlayer \*player, int32_t errorCode, const char \*errorMsg) | （已废弃）在API 9以上的版本发生错误时调用  | 
| typedef void(\* [OH_AVPlayerOnErrorCallback](_a_v_player.md#oh_avplayeronerrorcallback)) (OH_AVPlayer \*player, int32_t errorCode, const char \*errorMsg, void \*userData) | 发生错误时被调用。如果应用成功设置该回调，则不会回调OH_AVPlayerOnError函数。  | 
| typedef struct [AVPlayerCallback](_a_v_player_callback.md) [AVPlayerCallback](_a_v_player.md#avplayercallback) | OH_AVPlayer中所有回调函数指针的集合。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [AVPlayerState](_a_v_player.md#avplayerstate-1) {<br/>AV_IDLE = 0, <br/>AV_INITIALIZED = 1, <br/>AV_PREPARED = 2, <br/>AV_PLAYING = 3,<br/>AV_PAUSED = 4, <br/>AV_STOPPED = 5, <br/>AV_COMPLETED = 6, <br/>AV_RELEASED = 7,<br/>AV_ERROR = 8<br/>} | 播放状态。 | 
| [AVPlayerSeekMode](_a_v_player.md#avplayerseekmode) { <br/>AV_SEEK_NEXT_SYNC = 0, <br/>AV_SEEK_PREVIOUS_SYNC, <br/>AV_SEEK_CLOSEST = 2<br/>} | 跳转模式。 | 
| [AVPlaybackSpeed](_a_v_player.md#avplaybackspeed-1) {<br/>AV_SPEED_FORWARD_0_75_X, <br/>AV_SPEED_FORWARD_1_00_X, <br/>AV_SPEED_FORWARD_1_25_X, <br/> AV_SPEED_FORWARD_1_75_X,<br/>AV_SPEED_FORWARD_2_00_X, <br/>AV_SPEED_FORWARD_0_50_X, <br/>AV_SPEED_FORWARD_1_50_X<br/>} | 播放速度。  | 
| [AVPlayerOnInfoType](_a_v_player.md#avplayeroninfotype-1) {<br/>AV_INFO_TYPE_SEEKDONE = 0, <br/>AV_INFO_TYPE_SPEEDDONE = 1, <br/>AV_INFO_TYPE_BITRATEDONE = 2, <br/>AV_INFO_TYPE_EOS = 3,<br/>AV_INFO_TYPE_STATE_CHANGE = 4, <br/>AV_INFO_TYPE_POSITION_UPDATE = 5, <br/>AV_INFO_TYPE_MESSAGE = 6, <br/>AV_INFO_TYPE_VOLUME_CHANGE = 7,<br/>AV_INFO_TYPE_RESOLUTION_CHANGE = 8, <br/>AV_INFO_TYPE_BUFFERING_UPDATE = 9, <br/>AV_INFO_TYPE_BITRATE_COLLECT = 10, <br/>AV_INFO_TYPE_INTERRUPT_EVENT = 11,<br/>AV_INFO_TYPE_DURATION_UPDATE = 12, <br/>AV_INFO_TYPE_IS_LIVE_STREAM = 13, <br/>AV_INFO_TYPE_TRACKCHANGE = 14, <br/>AV_INFO_TYPE_TRACK_INFO_UPDATE = 15,<br/>AV_INFO_TYPE_SUBTITLE_UPDATE = 16, AV_INFO_TYPE_AUDIO_OUTPUT_DEVICE_CHANGE = 17<br/>} | OnInfo类型。 | 
| [AVPlayerBufferingType](_a_v_player.md#avplayerbufferingtype-1) { <br/>AVPLAYER_BUFFERING_START = 1, <br/>AVPLAYER_BUFFERING_END, <br/>AVPLAYER_BUFFERING_PERCENT, <br/>AVPLAYER_BUFFERING_CACHED_DURATION <br/>} | 播放缓冲消息类型定义。  | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| const char \* [OH_PLAYER_STATE](_a_v_player.md#oh_player_state) | 获取播放状态的关键字, 对应值类型是int32_t。  | 
| const char \* [OH_PLAYER_STATE_CHANGE_REASON](_a_v_player.md#oh_player_state_change_reason) | 获取播放状态变更原因的关键字, 对应值类型是int32_t。  | 
| const char \* [OH_PLAYER_VOLUME](_a_v_player.md#oh_player_volume) | 获取音量的关键字, 对应值类型是float。  | 
| const char \* [OH_PLAYER_BITRATE_ARRAY](_a_v_player.md#oh_player_bitrate_array) | 获取比特率列表的关键字, 对应值类型是uint8_t字节数组 [AV_INFO_TYPE_BITRATE_COLLECT](_a_v_player.md#avplayeroninfotype-1)。  | 
| const char \* [OH_PLAYER_AUDIO_INTERRUPT_TYPE](_a_v_player.md#oh_player_audio_interrupt_type) | 获取音频打断类型的关键字, 对应值类型是int32_t。  | 
| const char \* [OH_PLAYER_AUDIO_INTERRUPT_FORCE](_a_v_player.md#oh_player_audio_interrupt_force) | 获取音频打断FORCE类型的关键字, 对应值类型是int32_t。  | 
| const char \* [OH_PLAYER_AUDIO_INTERRUPT_HINT](_a_v_player.md#oh_player_audio_interrupt_hint) | 获取音频打断HINT类型的关键字, 对应值类型是int32_t。  | 
| const char \* [OH_PLAYER_AUDIO_DEVICE_CHANGE_REASON](_a_v_player.md#oh_player_audio_device_change_reason) | 获取音频音频设备变更原因的关键字, 对应值类型是int32_t。  | 
| const char \* [OH_PLAYER_BUFFERING_TYPE](_a_v_player.md#oh_player_buffering_type) | 获取缓冲更新消息类型的关键字, 对应值类型是AVPlayerBufferingType。  | 
| const char \* [OH_PLAYER_BUFFERING_VALUE](_a_v_player.md#oh_player_buffering_value) | 获取缓冲更新消息具体数值的关键字, 对应值类型是int32_t。  | 
| const char \* [OH_PLAYER_SEEK_POSITION](_a_v_player.md#oh_player_seek_position) | 获取Seek后播放进度信息的关键字, 对应值类型是int32_t。  | 
| const char \* [OH_PLAYER_PLAYBACK_SPEED](_a_v_player.md#oh_player_playback_speed) | 获取播放倍速信息的关键字, 对应值类型是AVPlaybackSpeed。  | 
| const char \* [OH_PLAYER_BITRATE](_a_v_player.md#oh_player_bitrate) | 获取比特率信息的关键字, 对应值类型是int32_t。  | 
| const char \* [OH_PLAYER_CURRENT_POSITION](_a_v_player.md#oh_player_current_position) | 获取播放进度信息的关键字, 对应值类型是int32_t。  | 
| const char \* [OH_PLAYER_DURATION](_a_v_player.md#oh_player_duration) | 获取媒体资源时长信息的关键字, 对应值类型是int64_t。  | 
| const char \* [OH_PLAYER_VIDEO_WIDTH](_a_v_player.md#oh_player_video_width) | 获取视频宽度信息的关键字, 对应值类型int32_t。  | 
| const char \* [OH_PLAYER_VIDEO_HEIGHT](_a_v_player.md#oh_player_video_height) | 获取视频高度信息的关键字, 对应值类型int32_t。  | 
| const char \* [OH_PLAYER_MESSAGE_TYPE](_a_v_player.md#oh_player_message_type) | 获取播放器消息信息的关键字, 对应值类型int32_t。  | 
| const char \* [OH_PLAYER_IS_LIVE_STREAM](_a_v_player.md#oh_player_is_live_stream) | 获取媒体资源是否为直播类型信息的关键字, 对应值类型int32_t。  | 
