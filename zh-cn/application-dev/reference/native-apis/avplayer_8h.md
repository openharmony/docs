# avplayer.h


## 概述

定义AVPlayer接口。使用AVPlayer提供的Native API播放媒体源。

**库：** libavplayer.so

**起始版本：** 11

**相关模块：**[AVPlayer](_a_v_player.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| \*[OH_AVPlayer_Create](_a_v_player.md#oh_avplayer_create) (void) | 创建播放器。 | 
| [OH_AVPlayer_SetURLSource](_a_v_player.md#oh_avplayer_seturlsource) (OH_AVPlayer \*player, const char \*url) | 设置播放器的播放源。对应的源可以是http url。 | 
| [OH_AVPlayer_SetFDSource](_a_v_player.md#oh_avplayer_setfdsource) (OH_AVPlayer \*player, int32_t fd, int64_t offset, int64_t size) | 设置播放器的播放媒体文件描述符来源。 | 
| [OH_AVPlayer_Prepare](_a_v_player.md#oh_avplayer_prepare) (OH_AVPlayer \*player) | 准备播放环境，异步缓存媒体数据。 | 
| [OH_AVPlayer_Play](_a_v_player.md#oh_avplayer_play) (OH_AVPlayer \*player) | 开始播放。 | 
| [OH_AVPlayer_Pause](_a_v_player.md#oh_avplayer_pause) (OH_AVPlayer \*player) | 暂停播放。 | 
| [OH_AVPlayer_Stop](_a_v_player.md#oh_avplayer_stop) (OH_AVPlayer \*player) | 停止播放。 | 
| [OH_AVPlayer_Reset](_a_v_player.md#oh_avplayer_reset) (OH_AVPlayer \*player) | 将播放器恢复到初始状态。 | 
| [OH_AVPlayer_Release](_a_v_player.md#oh_avplayer_release) (OH_AVPlayer \*player) | 异步释放播放器资源。 | 
| [OH_AVPlayer_ReleaseSync](_a_v_player.md#oh_avplayer_releasesync) (OH_AVPlayer \*player) | 同步释放播放器资源。 | 
| [OH_AVPlayer_SetVolume](_a_v_player.md#oh_avplayer_setvolume) (OH_AVPlayer \*player, float leftVolume, float rightVolume) | 设置播放器的音量。 | 
| [OH_AVPlayer_Seek](_a_v_player.md#oh_avplayer_seek) (OH_AVPlayer \*player, int32_t mSeconds, [AVPlayerSeekMode](_a_v_player.md#avplayerseekmode) mode) | 改变播放位置。 | 
| [OH_AVPlayer_GetCurrentTime](_a_v_player.md#oh_avplayer_getcurrenttime) (OH_AVPlayer \*player, int32_t \*currentTime) | 获取播放位置，精确到毫秒。 | 
| [OH_AVPlayer_GetVideoWidth](_a_v_player.md#oh_avplayer_getvideowidth) (OH_AVPlayer \*player, int32_t \*videoWidth) | 获取视频宽度。 | 
| [OH_AVPlayer_GetVideoHeight](_a_v_player.md#oh_avplayer_getvideoheight) (OH_AVPlayer \*player, int32_t \*videoHeight) | 获取视频高度。 | 
| [OH_AVPlayer_SetPlaybackSpeed](_a_v_player.md#oh_avplayer_setplaybackspeed) (OH_AVPlayer \*player, [AVPlaybackSpeed](_a_v_player.md#avplaybackspeed) speed) | 设置播放器播放速率。 | 
| [OH_AVPlayer_GetPlaybackSpeed](_a_v_player.md#oh_avplayer_getplaybackspeed) (OH_AVPlayer \*player, [AVPlaybackSpeed](_a_v_player.md#avplaybackspeed) \*speed) | 获取当前播放器播放速率。 | 
| [OH_AVPlayer_SelectBitRate](_a_v_player.md#oh_avplayer_selectbitrate) (OH_AVPlayer \*player, uint32_t bitRate) | 设置hls播放器使用的码率。 | 
| [OH_AVPlayer_SetVideoSurface](_a_v_player.md#oh_avplayer_setvideosurface) (OH_AVPlayer \*player, OHNativeWindow \*window) | 设置播放画面窗口。 | 
| [OH_AVPlayer_GetDuration](_a_v_player.md#oh_avplayer_getduration) (OH_AVPlayer \*player, int32_t \*duration) | 获取媒体文件的总时长，精确到毫秒。 | 
| [OH_AVPlayer_GetState](_a_v_player.md#oh_avplayer_getstate) (OH_AVPlayer \*player, [AVPlayerState](_a_v_player.md#avplayerstate) \*state) | 获取当前播放状态。 | 
| [OH_AVPlayer_IsPlaying](_a_v_player.md#oh_avplayer_isplaying) (OH_AVPlayer \*player) | 判断播放器是否在播放。 | 
| [OH_AVPlayer_IsLooping](_a_v_player.md#oh_avplayer_islooping) (OH_AVPlayer \*player) | 判断是用循环播放。 | 
| [OH_AVPlayer_SetLooping](_a_v_player.md#oh_avplayer_setlooping) (OH_AVPlayer \*player, bool loop) | 设置循环播放。 | 
| [OH_AVPlayer_SetPlayerCallback](_a_v_player.md#oh_avplayer_setplayercallback) (OH_AVPlayer \*player, [AVPlayerCallback](_a_v_player_callback.md) callback) | 设置播放器回调方法。 | 
| [OH_AVPlayer_SelectTrack](_a_v_player.md#oh_avplayer_selecttrack) (OH_AVPlayer \*player, int32_t index) | 选择音频或字幕轨道。 | 
| [OH_AVPlayer_DeselectTrack](_a_v_player.md#oh_avplayer_deselecttrack) (OH_AVPlayer \*player, int32_t index) | 取消选择当前音频或字幕轨道。 | 
| [OH_AVPlayer_GetCurrentTrack](_a_v_player.md#oh_avplayer_getcurrenttrack) (OH_AVPlayer \*player, int32_t trackType, int32_t \*index) | 获取当前有效的轨道索引。 | 
