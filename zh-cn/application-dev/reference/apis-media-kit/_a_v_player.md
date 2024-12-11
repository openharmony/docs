# AVPlayer


## 概述

为媒体源提供播放能力的API。

开发者可根据实际的开发需求，参考对应的开发指南及样例：

- [使用AVPlayer播放音频](../../media/media/using-ndk-avplayer-for-playback.md)
- [使用AVPlayer播放视频](../../media/media/using-ndk-avplayer-for-video-playback.md)

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [avplayer.h](avplayer_8h.md) | 定义avplayer接口。使用AVPlayer提供的Native API播放媒体源。  | 
| [avplayer_base.h](avplayer__base_8h.md) | 定义AVPlayer的结构体和枚举。  | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [AVPlayerCallback](_a_v_player_callback.md) | （已废弃）包含了OH_AVPlayerOnInfo和OH_AVPlayerOnInfo回调函数指针的集合。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [MediaKeySession](#mediakeysession) [MediaKeySession](#mediakeysession) | MediaKeySession类型。  | 
| typedef struct [DRM_MediaKeySystemInfo](#drm_mediakeysysteminfo) [DRM_MediaKeySystemInfo](#drm_mediakeysysteminfo) | DRM_MediaKeySystemInfo类型。  | 
| typedef void(\* [Player_MediaKeySystemInfoCallback](#player_mediakeysysteminfocallback)) (OH_AVPlayer \*player, [DRM_MediaKeySystemInfo](#drm_mediakeysysteminfo) \*mediaKeySystemInfo) | 播放器DRM信息更新时被调用。  | 
| typedef enum [AVPlayerState](#avplayerstate-1) [AVPlayerState](#avplayerstate) | 播放状态。  | 
| typedef enum [AVPlayerSeekMode](#avplayerseekmode-1) [AVPlayerSeekMode](#avplayerseekmode) | 跳转模式。  | 
| typedef enum [AVPlaybackSpeed](#avplaybackspeed-1) [AVPlaybackSpeed](#avplaybackspeed) | 播放速度。  | 
| typedef enum [AVPlayerOnInfoType](#avplayeroninfotype-1) [AVPlayerOnInfoType](#avplayeroninfotype) | OnInfo类型。  | 
| typedef enum [AVPlayerBufferingType](#avplayerbufferingtype-1) [AVPlayerBufferingType](#avplayerbufferingtype) | 播放缓冲消息类型定义。  | 
| typedef void(\*[OH_AVPlayerOnInfo](#oh_avplayeroninfo)) (OH_AVPlayer \*player, [AVPlayerOnInfoType](#avplayeroninfotype) type, int32_t extra) | （已废弃）收到播放器消息时调用。  | 
| typedef void(\*[OH_AVPlayerOnInfoCallback](#oh_avplayeroninfocallback)) (OH_AVPlayer \*player, [AVPlayerOnInfoType](#avplayeroninfotype) type, OH_AVFormat \*infoBody, void \*userData) | 收到播放器消息时被调用。如果应用成功设置该回调，则不会回调OH_AVPlayerOnInfo函数。  | 
| typedef void(\* [OH_AVPlayerOnError](#oh_avplayeronerror)) (OH_AVPlayer \*player, int32_t errorCode, const char \*errorMsg) | （已废弃）在API 9以上的版本发生错误时调用。  | 
| typedef void(\* [OH_AVPlayerOnErrorCallback](#oh_avplayeronerrorcallback)) (OH_AVPlayer \*player, int32_t errorCode, const char \*errorMsg, void \*userData) | 发生错误时被调用。如果应用成功设置该回调，则不会回调OH_AVPlayerOnError函数。  | 
| typedef struct [AVPlayerCallback](_a_v_player_callback.md) [AVPlayerCallback](#avplayercallback) | （已废弃）包含了OH_AVPlayerOnInfo和OH_AVPlayerOnInfo回调函数指针的集合。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [AVPlayerState](#avplayerstate-1) {<br/>AV_IDLE = 0, <br/>AV_INITIALIZED = 1, <br/>AV_PREPARED = 2, <br/>AV_PLAYING = 3,<br/>AV_PAUSED = 4, <br/>AV_STOPPED = 5, <br/>AV_COMPLETED = 6, <br/>AV_RELEASED = 7,<br/>AV_ERROR = 8<br/>} | 播放状态。 | 
| [AVPlayerSeekMode](#avplayerseekmode) { <br/>AV_SEEK_NEXT_SYNC = 0, <br/>AV_SEEK_PREVIOUS_SYNC, <br/>AV_SEEK_CLOSEST = 2<br/>} | 跳转模式。 | 
| [AVPlaybackSpeed](#avplaybackspeed-1) {<br/>AV_SPEED_FORWARD_0_75_X, <br/>AV_SPEED_FORWARD_1_00_X, <br/>AV_SPEED_FORWARD_1_25_X, <br/> AV_SPEED_FORWARD_1_75_X,<br/>AV_SPEED_FORWARD_2_00_X, <br/>AV_SPEED_FORWARD_0_50_X, <br/>AV_SPEED_FORWARD_1_50_X<br/>, <br/>AV_SPEED_FORWARD_3_00_X, <br/>AV_SPEED_FORWARD_0_25_X, <br/>AV_SPEED_FORWARD_0_125_X} | 播放速度。  | 
| [AVPlayerOnInfoType](#avplayeroninfotype-1) {<br/>AV_INFO_TYPE_SEEKDONE = 0, <br/>AV_INFO_TYPE_SPEEDDONE = 1, <br/>AV_INFO_TYPE_BITRATEDONE = 2, <br/>AV_INFO_TYPE_EOS = 3,<br/>AV_INFO_TYPE_STATE_CHANGE = 4, <br/>AV_INFO_TYPE_POSITION_UPDATE = 5, <br/>AV_INFO_TYPE_MESSAGE = 6, <br/>AV_INFO_TYPE_VOLUME_CHANGE = 7,<br/>AV_INFO_TYPE_RESOLUTION_CHANGE = 8, <br/>AV_INFO_TYPE_BUFFERING_UPDATE = 9, <br/>AV_INFO_TYPE_BITRATE_COLLECT = 10, <br/>AV_INFO_TYPE_INTERRUPT_EVENT = 11,<br/>AV_INFO_TYPE_DURATION_UPDATE = 12, <br/>AV_INFO_TYPE_IS_LIVE_STREAM = 13, <br/>AV_INFO_TYPE_TRACKCHANGE = 14, <br/>AV_INFO_TYPE_TRACK_INFO_UPDATE = 15,<br/>AV_INFO_TYPE_SUBTITLE_UPDATE = 16, AV_INFO_TYPE_AUDIO_OUTPUT_DEVICE_CHANGE = 17<br/>} | OnInfo类型。 | 
| [AVPlayerBufferingType](#avplayerbufferingtype-1) { <br/>AVPLAYER_BUFFERING_START = 1, <br/>AVPLAYER_BUFFERING_END, <br/>AVPLAYER_BUFFERING_PERCENT, <br/>AVPLAYER_BUFFERING_CACHED_DURATION <br/>} | 播放缓冲消息类型定义。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| OH_AVPlayer \*[OH_AVPlayer_Create](#oh_avplayer_create) (void) | 创建播放器。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode)  [OH_AVPlayer_SetURLSource](#oh_avplayer_seturlsource) (OH_AVPlayer \*player, const char \*url) | 设置播放器的播放源。对应的源可以是http url。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode)  [OH_AVPlayer_SetFDSource](#oh_avplayer_setfdsource) (OH_AVPlayer \*player, int32_t fd, int64_t offset, int64_t size) | 设置播放器的播放媒体文件描述符来源。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode)  [OH_AVPlayer_Prepare](#oh_avplayer_prepare) (OH_AVPlayer \*player) | 准备播放环境，异步缓存媒体数据。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode)  [OH_AVPlayer_Play](#oh_avplayer_play) (OH_AVPlayer \*player) | 开始播放。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_Pause](#oh_avplayer_pause) (OH_AVPlayer \*player) | 暂停播放。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_Stop](#oh_avplayer_stop) (OH_AVPlayer \*player) | 停止播放。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_Reset](#oh_avplayer_reset) (OH_AVPlayer \*player) | 将播放器恢复到初始状态。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_Release](#oh_avplayer_release) (OH_AVPlayer \*player) | 异步释放播放器资源。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_ReleaseSync](#oh_avplayer_releasesync) (OH_AVPlayer \*player) | 同步释放播放器资源。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetVolume](#oh_avplayer_setvolume) (OH_AVPlayer \*player, float leftVolume, float rightVolume) | 设置播放器的音量。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_Seek](#oh_avplayer_seek) (OH_AVPlayer \*player, int32_t mSeconds, [AVPlayerSeekMode](#avplayerseekmode) mode) | 改变播放位置。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetCurrentTime](#oh_avplayer_getcurrenttime) (OH_AVPlayer \*player, int32_t \*currentTime) | 获取播放位置，精确到毫秒。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetVideoWidth](#oh_avplayer_getvideowidth) (OH_AVPlayer \*player, int32_t \*videoWidth) | 获取视频宽度。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetVideoHeight](#oh_avplayer_getvideoheight) (OH_AVPlayer \*player, int32_t \*videoHeight) | 获取视频高度。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetPlaybackSpeed](#oh_avplayer_setplaybackspeed) (OH_AVPlayer \*player, [AVPlaybackSpeed](#avplaybackspeed) speed) | 设置播放器播放速率。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetPlaybackSpeed](#oh_avplayer_getplaybackspeed) (OH_AVPlayer \*player, [AVPlaybackSpeed](#avplaybackspeed) \*speed) | 获取当前播放器播放速率。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetAudioRendererInfo](#oh_avplayer_setaudiorendererinfo) (OH_AVPlayer \*player, OH_AudioStream_Usage streamUsage) | 设置player音频流类型。  | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetAudioInterruptMode](#oh_avplayer_setaudiointerruptmode) (OH_AVPlayer \*player, OH_AudioInterrupt_Mode interruptMode) | 设置player音频流的打断模式。  | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetAudioEffectMode](#oh_avplayer_setaudioeffectmode) (OH_AVPlayer \*player, OH_AudioStream_AudioEffectMode effectMode) | 设置player音频流的音效模式。  | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SelectBitRate](#oh_avplayer_selectbitrate) (OH_AVPlayer \*player, uint32_t bitRate) | 设置hls播放器使用的码率。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetVideoSurface](#oh_avplayer_setvideosurface) (OH_AVPlayer \*player, OHNativeWindow \*window) | 设置播放画面窗口。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetDuration](#oh_avplayer_getduration) (OH_AVPlayer \*player, int32_t \*duration) | 获取媒体文件的总时长，精确到毫秒。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetState](#oh_avplayer_getstate) (OH_AVPlayer \*player, [AVPlayerState](#avplayerstate) \*state) | 获取当前播放状态。 | 
| bool [OH_AVPlayer_IsPlaying](#oh_avplayer_isplaying) (OH_AVPlayer \*player) | 判断播放器是否在播放。 | 
| bool [OH_AVPlayer_IsLooping](#oh_avplayer_islooping) (OH_AVPlayer \*player) | 判断是用循环播放。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetLooping](#oh_avplayer_setlooping) (OH_AVPlayer \*player, bool loop) | 设置循环播放。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetPlayerCallback](#oh_avplayer_setplayercallback) (OH_AVPlayer \*player, [AVPlayerCallback](_a_v_player_callback.md) callback) | 设置播放器回调方法。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SelectTrack](#oh_avplayer_selecttrack) (OH_AVPlayer \*player, int32_t index) | 选择音频轨道。该接口在当前版本暂不支持，将在后续版本开放能力。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_DeselectTrack](#oh_avplayer_deselecttrack) (OH_AVPlayer \*player, int32_t index) | 取消选择当前音频轨道。该接口在当前版本暂不支持，将在后续版本开放能力。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetCurrentTrack](#oh_avplayer_getcurrenttrack) (OH_AVPlayer \*player, int32_t trackType, int32_t \*index) | 获取当前有效的轨道索引。该接口在当前版本暂不支持，将在后续版本开放能力。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetMediaKeySystemInfoCallback](#oh_avplayer_setmediakeysysteminfocallback) (OH_AVPlayer \*player, Player_MediaKeySystemInfoCallback callback) | 设置播放器媒体密钥系统信息回调的方法。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetMediaKeySystemInfo](#oh_avplayer_getmediakeysysteminfo) (OH_AVPlayer \*player, [DRM_MediaKeySystemInfo](../apis-drm-kit/_d_r_m___media_key_system_info.md) \*mediaKeySystemInfo) | 获取媒体密钥系统信息以创建媒体密钥会话。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetDecryptionConfig](#oh_avplayer_setdecryptionconfig) (OH_AVPlayer \*player, [MediaKeySession](../apis-drm-kit/_drm.md#mediakeysession) \*mediaKeySession, bool secureVideoPath) | 设置解密信息。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetOnInfoCallback](#oh_avplayer_setoninfocallback) (OH_AVPlayer \*player, [OH_AVPlayerOnInfoCallback](#oh_avplayeroninfocallback) callback, void \*userData) | 设置播放器消息回调监听函数。  | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetOnErrorCallback](#oh_avplayer_setonerrorcallback) (OH_AVPlayer \*player, [OH_AVPlayerOnErrorCallback](#oh_avplayeronerrorcallback) callback, void \*userData) | 设置播放器错误回调监听函数。  | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| const char \* [OH_PLAYER_STATE](#oh_player_state) | 获取播放状态的关键字, 对应值类型是int32_t。  | 
| const char \* [OH_PLAYER_STATE_CHANGE_REASON](#oh_player_state_change_reason) | 获取播放状态变更原因的关键字, 对应值类型是int32_t。  | 
| const char \* [OH_PLAYER_VOLUME](#oh_player_volume) | 获取音量的关键字, 对应值类型是float。  | 
| const char \* [OH_PLAYER_BITRATE_ARRAY](#oh_player_bitrate_array) | 获取比特率列表的关键字, 对应值类型是uint8_t字节数组[AV_INFO_TYPE_BITRATE_COLLECT](#avplayeroninfotype-1)。  | 
| const char \* [OH_PLAYER_AUDIO_INTERRUPT_TYPE](#oh_player_audio_interrupt_type) | 获取音频打断类型的关键字, 对应值类型是int32_t。  | 
| const char \* [OH_PLAYER_AUDIO_INTERRUPT_FORCE](#oh_player_audio_interrupt_force) | 获取音频打断FORCE类型的关键字, 对应值类型是int32_t。  | 
| const char \* [OH_PLAYER_AUDIO_INTERRUPT_HINT](#oh_player_audio_interrupt_hint) | 获取音频打断HINT类型的关键字, 对应值类型是int32_t。  | 
| const char \* [OH_PLAYER_AUDIO_DEVICE_CHANGE_REASON](#oh_player_audio_device_change_reason) | 获取音频音频设备变更原因的关键字, 对应值类型是int32_t。  | 
| const char \* [OH_PLAYER_BUFFERING_TYPE](#oh_player_buffering_type) | 获取缓冲更新消息类型的关键字, 对应值类型是[AVPlayerBufferingType](#avplayerbufferingtype-1)。  | 
| const char \* [OH_PLAYER_BUFFERING_VALUE](#oh_player_buffering_value) | 获取缓冲更新消息具体数值的关键字, 对应值类型是int32_t。  | 
| const char \* [OH_PLAYER_SEEK_POSITION](#oh_player_seek_position) | 获取Seek后播放进度信息的关键字, 对应值类型是int32_t。  | 
| const char \* [OH_PLAYER_PLAYBACK_SPEED](#oh_player_playback_speed) | 获取播放倍速信息的关键字, 对应值类型是[AVPlaybackSpeed](#avplaybackspeed-1)。  | 
| const char \* [OH_PLAYER_BITRATE](#oh_player_bitrate) | 获取比特率信息的关键字, 对应值类型是int32_t。  | 
| const char \* [OH_PLAYER_CURRENT_POSITION](#oh_player_current_position) | 获取播放进度信息的关键字, 对应值类型是int32_t。  | 
| const char \* [OH_PLAYER_DURATION](#oh_player_duration) | 获取媒体资源时长信息的关键字, 对应值类型是int64_t。  | 
| const char \* [OH_PLAYER_VIDEO_WIDTH](#oh_player_video_width) | 获取视频宽度信息的关键字, 对应值类型int32_t。  | 
| const char \* [OH_PLAYER_VIDEO_HEIGHT](#oh_player_video_height) | 获取视频高度信息的关键字, 对应值类型int32_t。  | 
| const char \* [OH_PLAYER_MESSAGE_TYPE](#oh_player_message_type) | 获取播放器消息信息的关键字, 对应值类型int32_t。  | 
| const char \* [OH_PLAYER_IS_LIVE_STREAM](#oh_player_is_live_stream) | 获取媒体资源是否为直播类型信息的关键字, 对应值类型int32_t。  | 


## 类型定义说明


### AVPlaybackSpeed

```
typedef enum AVPlaybackSpeed AVPlaybackSpeed
```
**描述**
播放速度

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


### AVPlayerBufferingType

```
typedef enum AVPlayerBufferingType AVPlayerBufferingType
```
**描述**
播放缓冲消息类型定义。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


### AVPlayerCallback

```
typedef struct AVPlayerCallback AVPlayerCallback
```
**描述**
包含了OH_AVPlayerOnInfo和OH_AVPlayerOnInfo回调函数指针的集合。应用需注册此实例结构体到OH_AVPlayer实例中，并对回调上报的信息进行处理，保证AVPlayer的正常运行。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**废弃版本：** 12

**替代接口：**[OH_AVPlayerOnInfoCallback](#oh_avplayeroninfocallback) [OH_AVPlayerOnErrorCallback](#oh_avplayeronerrorcallback)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| onInfo | 监控AVPlayer过程信息，参考[OH_AVPlayerOnInfo](#oh_avplayeroninfo) | 
| onError | 监控AVPlayer操作错误，参考[OH_AVPlayerOnError](#oh_avplayeronerror) | 


### AVPlayerOnInfoType

```
typedef enum AVPlayerOnInfoType AVPlayerOnInfoType
```
**描述**
OnInfo类型。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


### AVPlayerSeekMode

```
typedef enum AVPlayerSeekMode AVPlayerSeekMode
```
**描述**
跳转模式

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


### AVPlayerState

```
typedef enum AVPlayerState AVPlayerState
```
**描述**
播放状态

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


### DRM_MediaKeySystemInfo

```
typedef struct DRM_MediaKeySystemInfo DRM_MediaKeySystemInfo
```
**描述**
DRM_MediaKeySystemInfo类型。

**起始版本：** 12


### MediaKeySession

```
typedef struct MediaKeySession MediaKeySession
```
**描述**
MediaKeySession类型。

**起始版本：** 12


### OH_AVPlayerOnError

```
typedef void(* OH_AVPlayerOnError) (OH_AVPlayer *player, int32_t errorCode, const char *errorMsg)
```
**描述**
在API9以上的版本发生错误时调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**废弃版本：** 12

**替代接口：**[OH_AVPlayerOnErrorCallback](#oh_avplayeronerrorcallback)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| 指向OH_AVPlayer实例的指针 |  | 
| errorCode | 错误码。<br> AV_ERR_NO_MEMORY：无内存，取值为1<br>AV_ERR_OPERATE_NOT_PERMIT：操作不允许，取值为2<br>AV_ERR_INVALID_VAL：无效值，取值为3<br>AV_ERR_IO：IO错误，取值为4<br>AV_ERR_TIMEOUT：超时错误，取值为5<br>AV_ERR_UNKNOWN：未知错误，取值为6<br>AV_ERR_SERVICE_DIED：服务死亡，取值为7<br>AV_ERR_INVALID_STATE：当前状态不支持此操作，取值为8<br>AV_ERR_UNSUPPORT：未支持的接口，取值为9<br>AV_ERR_EXTEND_START：扩展错误码初始值，取值为100 | 
| errorMsg | 错误消息  | 


### OH_AVPlayerOnErrorCallback

```
typedef void(* OH_AVPlayerOnErrorCallback) (OH_AVPlayer *player, int32_t errorCode, const char *errorMsg, void *userData)
```
**描述**
发生错误时被调用。如果应用成功设置该回调，则不会回调OH_AVPlayerOnError函数。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针。  | 
| errorCode | 错误码。<br> AV_ERR_NO_MEMORY：无内存，取值为1<br>AV_ERR_OPERATE_NOT_PERMIT：操作不允许，取值为2<br>AV_ERR_INVALID_VAL：无效值，取值为3<br>AV_ERR_IO：IO错误，取值为4<br>AV_ERR_TIMEOUT：超时错误，取值为5<br>AV_ERR_UNKNOWN：未知错误，取值为6<br>AV_ERR_SERVICE_DIED：服务死亡，取值为7<br>AV_ERR_INVALID_STATE：当前状态不支持此操作，取值为8<br>AV_ERR_UNSUPPORT：未支持的接口，取值为9<br>AV_ERR_EXTEND_START：扩展错误码初始值，取值为100 | 
| errorMsg | 错误消息。  | 
| userData | 原样返回用户设置回调时传入的userData数据。  | 


### OH_AVPlayerOnInfo

```
typedef void(* OH_AVPlayerOnInfo) (OH_AVPlayer *player, AVPlayerOnInfoType type, int32_t extra)
```
**描述**
收到播放器消息时调用。

信息类型（type）和信息（extra）的对应关系如表所示。

| 信息类型（type） | 对应的extra描述 | 
| -------- | -------- |
| AV_INFO_TYPE_SEEKDONE | 跳转到对应播放位置时返回消息，extra表示seek到的位置。 |
| AV_INFO_TYPE_SPEEDDONE | 播放倍速设置完成时返回消息，extra表示播放倍速信息，具体请参考[AVPlaybackSpeed](#avplaybackspeed-1)。 |
| AV_INFO_TYPE_BITRATEDONE | 比特率设置完成时返回消息，extra表示比特率信息。 |
| AV_INFO_TYPE_EOS | 播放完成时返回消息。|
| AV_INFO_TYPE_STATE_CHANGE | 状态改变时返回消息，extra表示当前播放状态，具体请参见[AVPlayerState](#avplayerstate-1)。 |
| AV_INFO_TYPE_POSITION_UPDATE | 返回当前播放位置，extra表示当前位置。 |
| AV_INFO_TYPE_MESSAGE | 视频开始渲染时返回消息，extra表示视频首帧渲染。 |
| AV_INFO_TYPE_VOLUME_CHANGE | 音量改变时返回消息，此场景extra未定义。 |
| AV_INFO_TYPE_RESOLUTION_CHANGE | 首次获取视频大小或视频大小更新时返回消息，此场景extra未定义。 |
| AV_INFO_TYPE_BUFFERING_UPDATE | 返回多队列缓冲时间，extra表示视频时长。 |
| AV_INFO_TYPE_BITRATE_COLLECT  | 上报HLS视频比特率列表消息。上报时每个比特率已经被转为uint8_t字节数组，使用者需要将uint8_t字节数组强制转换为uint32_t整型数组。   | 
| AV_INFO_TYPE_INTERRUPT_EVENT | 音频焦点改变时返回消息，extra表示音频打断提示，具体请参见[OH_AudioInterrupt_Hint](../apis-audio-kit/_o_h_audio.md#oh_audiointerrupt_hint)，应用可决定是否根据打断提示作进一步处理。 |
| AV_INFO_TYPE_DURATION_UPDATE | 返回播放时长，extra表示视频时长。 |
| AV_INFO_TYPE_IS_LIVE_STREAM | 播放为直播流时返回消息，extra表示是否为直播流，0表示非直播流，1表示直播流。 |
| AV_INFO_TYPE_TRACKCHANGE | 轨道改变时返回消息，此场景extra未定义。 |
| AV_INFO_TYPE_TRACK_INFO_UPDATE |轨道更新时返回消息，此场景extra未定义。 |
| AV_INFO_TYPE_SUBTITLE_UPDATE | 字幕信息更新时返回消息，此场景extra未定义。 |
| AV_INFO_TYPE_AUDIO_OUTPUT_DEVICE_CHANGE | 音频输出设备改变时返回消息，extra表示设备改变原因，具体请参见[OH_AudioStream_DeviceChangeReason](../apis-audio-kit/_o_h_audio.md#oh_audiostream_devicechangereason)。 |

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**废弃版本：** 12

**替代接口：**[OH_AVPlayerOnInfoCallback](#oh_avplayeroninfocallback)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针。  | 
| type | 信息类型。类型为[AVPlayerOnInfoType](#avplayeroninfotype-1)，与extra的对应关系可见方法描述。 | 
| extra | 其他信息，如播放文件的开始时间位置。  | 


### OH_AVPlayerOnInfoCallback

```
typedef void(* OH_AVPlayerOnInfoCallback) (OH_AVPlayer *player, AVPlayerOnInfoType type, OH_AVFormat *infoBody, void *userData)
```
**描述**
收到播放器消息时被调用。如果应用成功设置该回调，则不会回调OH_AVPlayerOnInfo函数。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针。  | 
| type | 信息类型。具体请参见[AVPlayerOnInfoType](#avplayeroninfotype-1)。  | 
| infoBody | 指向携带具体消息的指针，仅在该回调方法内有效。  | 
| userData | 原样返回用户设置回调时传入的userData数据。  | 


### Player_MediaKeySystemInfoCallback

```
typedef void(* Player_MediaKeySystemInfoCallback) (OH_AVPlayer *player, DRM_MediaKeySystemInfo *mediaKeySystemInfo)
```
**描述**
播放器DRM信息更新时被调用。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针。  | 
| mediaKeySystemInfo | DRM信息。  | 

**返回：**

void


## 枚举类型说明


### AVPlaybackSpeed

```
enum AVPlaybackSpeed
```
**描述**
播放速度

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| AV_SPEED_FORWARD_0_75_X | 0.75倍速播放 | 
| AV_SPEED_FORWARD_1_00_X | 正常播放 | 
| AV_SPEED_FORWARD_1_25_X | 1.25倍速播放 | 
| AV_SPEED_FORWARD_1_75_X | 1.75倍速播放 | 
| AV_SPEED_FORWARD_2_00_X | 2.0倍速播放 | 
| AV_SPEED_FORWARD_0_50_X | 0.5倍速播放<br>**起始版本：** 12 | 
| AV_SPEED_FORWARD_1_50_X | 1.5倍速播放<br>**起始版本：** 12 | 
| AV_SPEED_FORWARD_3_00_X | 3.0倍速播放<br>**起始版本：** 13 |
| AV_SPEED_FORWARD_0_25_X | 0.25倍速播放<br>**起始版本：** 13 |
| AV_SPEED_FORWARD_0_125_X | 0.125倍速播放<br>**起始版本：** 13 |


### AVPlayerBufferingType

```
enum AVPlayerBufferingType
```
**描述**
播放缓冲消息类型定义。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| AVPLAYER_BUFFERING_START  | 缓冲开始消息。   | 
| AVPLAYER_BUFFERING_END  | 缓冲结束消息。   | 
| AVPLAYER_BUFFERING_PERCENT  | 缓冲执行进度百分比，取值范围：整数，[0, 100]。   | 
| AVPLAYER_BUFFERING_CACHED_DURATION  | 缓冲数据可播放时长，单位：毫秒。   | 


### AVPlayerOnInfoType

```
enum AVPlayerOnInfoType
```
**描述**
OnInfo类型。

可用于[OH_AVPlayerOnInfoCallback](#oh_avplayeroninfocallback)和[OH_AVPlayerOnInfo(已废弃)](#oh_avplayeroninfo)，用于表示收到的播放器信息类型。

- 从API 12开始，推荐用户使用[OH_AVPlayerOnInfoCallback](#oh_avplayeroninfocallback)。不同的OnInfo类型，可获取到不同信息（infoBody），infoBody中包含key-value关系表，详见下述枚举值表。

- 使用API 11版本的开发者，需要使用旧接口。针对已废弃接口OH_AVPlayerOnInfo中使用的对应关系，可直接参考[OH_AVPlayerOnInfo的API说明](#oh_avplayeroninfo)。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| AV_INFO_TYPE_SEEKDONE | 跳转到对应播放位置时返回消息。<br>key为OH_PLAYER_SEEK_POSITION：取值类型int32_t。系统通过int32_t传递value，应用需通过int32_t获取。|
| AV_INFO_TYPE_SPEEDDONE | 播放倍速设置完成时返回消息。<br>key为OH_PLAYER_PLAYBACK_SPEED：取值类型[AVPlaybackSpeed](#avplaybackspeed-1)。系统通过int32_t传递value，应用需先通过int32_t获取，再强制转为[AVPlaybackSpeed](#avplaybackspeed-1)。 |
| AV_INFO_TYPE_BITRATEDONE | 比特率设置完成时返回消息。<br>key为OH_PLAYER_BITRATE：取值类型uint32_t。系统通过int32_t传递value，应用需先通过int32_t获取，再强制为uint32_t。 |
| AV_INFO_TYPE_EOS | 播放完成时返回消息。|
| AV_INFO_TYPE_STATE_CHANGE | 状态改变时返回消息。<br>- key为OH_PLAYER_STATE：取值类型int32_t。系统通过int32_t传递value，应用需先通过int32_t获取，再强制转为[AVPlayerState](#avplayerstate-1)。<br>- key为OH_PLAYER_STATE_CHANGE_REASON：取值类型int32_t。系统通过int32_t传递value，应用需通过int32_t获取。1：用户操作触发；2：系统变更触发。 |
| AV_INFO_TYPE_POSITION_UPDATE | 返回当前播放位置。<br>key为OH_PLAYER_CURRENT_POSITION：取值类型int32_t。系统通过int32_t传递value，应用需通过int32_t获取。 |
| AV_INFO_TYPE_MESSAGE | 视频开始渲染时返回消息。<br>key为OH_PLAYER_MESSAGE_TYPE：取值类型int32_t。系统通过int32_t传递value，应用需通过int32_t获取。1表示视频开始渲染。 |
| AV_INFO_TYPE_VOLUME_CHANGE | 音量改变时返回消息。<br>key为OH_PLAYER_VOLUME：取值类型float。系统通过float传递value，应用需通过float获取。取值范围[0.0, 1.0]。 |
| AV_INFO_TYPE_RESOLUTION_CHANGE | 首次获取视频大小或视频大小更新时返回消息。<br>key为OH_PLAYER_VIDEO_WIDTH 或 OH_PLAYER_VIDEO_HEIGHT：取值类型int32_t。系统通过int32_t传递value，应用需通过int32_t获取。 |
| AV_INFO_TYPE_BUFFERING_UPDATE | 返回多队列缓冲时间。<br>- key为OH_PLAYER_BUFFERING_TYPE：取值类型[AVPlayerBufferingType](#avplayerbufferingtype-1)。系统通过int32_t传递value，应用需先通过int32_t获取，再强制转为[AVPlayerBufferingType](#avplayerbufferingtype-1)。<br>- key为OH_PLAYER_BUFFERING_VALUE：取值类型int32_t。系统通过int32_t传递value，应用需通过int32_t获取。当缓冲更新消息类型是AVPLAYER_BUFFERING_PERCENT、AVPLAYER_BUFFERING_CACHED_DURATION时有效，分别表示缓冲进度完成百分比、缓冲数据可播放时长。 |
| AV_INFO_TYPE_BITRATE_COLLECT  | 上报HLS视频比特率列表消息。<br>key为OH_PLAYER_BITRATE_ARRAY：取值类型uint8_t字节数组。应用需要先使用uint8_t类型指针变量保存比特率列表，使用size_t类型变量保存字节数组长度。然后分配若干个uint32_t类型的存储空间，接收将uint8_t字节数组转换为uint32_t类型比特率整数值。   | 
| AV_INFO_TYPE_INTERRUPT_EVENT | 音频焦点改变时返回消息。<br>取值类型int32_t。系统通过int32_t传递value，应用需通过int32_t获取。<br>key为：<br>- OH_PLAYER_AUDIO_INTERRUPT_TYPE：取值1表示中断事件开始；2表示结束。<br>- OH_PLAYER_AUDIO_INTERRUPT_FORCE：取值0表示强制打断，系统改变音频播放状态；1表示共享打断，应用改变音频播放状态。<br>- OH_PLAYER_AUDIO_INTERRUPT_HINT：取值0表示NONE，无提示；1表示RESUME，提示音频恢复；2表示PAUSE，提示音频暂停暂时失去焦点；3表示STOP，提示音频停止；4表示DUCK，音频降低音量；5表示UNDUCK，音频恢复音量。 |
| AV_INFO_TYPE_DURATION_UPDATE | 返回播放时长。<br>key为OH_PLAYER_DURATION：取值类型int64_t。系统通过int64_t传递value，应用需通过int64_t获取。 |
| AV_INFO_TYPE_IS_LIVE_STREAM | 播放为直播流时返回消息。<br>key为OH_PLAYER_IS_LIVE_STREAM：取值类型int32_t。系统通过int32_t传递value，应用需通过int32_t获取。0表示非直播流，1表示直播流。 |
| AV_INFO_TYPE_TRACKCHANGE | 轨道改变时返回消息，此场景暂未定义。 |
| AV_INFO_TYPE_TRACK_INFO_UPDATE |轨道更新时返回消息，此场景暂未定义。 |
| AV_INFO_TYPE_SUBTITLE_UPDATE | 字幕信息更新时返回消息，此场景暂未定义。 |
| AV_INFO_TYPE_AUDIO_OUTPUT_DEVICE_CHANGE | 音频输出设备改变时返回消息。<br>key为OH_PLAYER_AUDIO_DEVICE_CHANGE_REASON：取值类型int32_t。系统通过int32_t传递value，应用需通过int32_t获取。 |


### AVPlayerSeekMode

```
enum AVPlayerSeekMode
```
**描述**
跳转模式

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| AV_SEEK_NEXT_SYNC | 同步到时间点之后的关键帧。 | 
| AV_SEEK_PREVIOUS_SYNC | 同步到时间点之前的关键帧。 | 
| AV_SEEK_CLOSEST | 同步到距离指定时间点最近的帧。<br/>**起始版本：** 12 | 


### AVPlayerState

```
enum AVPlayerState
```
**描述**
播放状态

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| AV_IDLE | 空闲 | 
| AV_INITIALIZED | 初始化 | 
| AV_PREPARED | 准备 | 
| AV_PLAYING | 播放 | 
| AV_PAUSED | 暂停 | 
| AV_STOPPED | 停止 | 
| AV_COMPLETED | 结束 | 
| AV_RELEASED | 释放 | 
| AV_ERROR | 错误 | 


## 函数说明


### OH_AVPlayer_Create()

```
OH_AVPlayer* OH_AVPlayer_Create (void)
```
**描述**
创建播放器。

> **说明：**
>
> - 推荐单个应用创建的音视频播放器实例（即音频、视频、音视频三类相加）不超过16个。<!--Del-->
> - 可创建的音视频播放器实例数量依赖于设备芯片的支持情况，如芯片支持创建的数量少于上述情况，请以芯片规格为准。如RK3568推荐单个应用创建6个以内的音视频播放器实例。<!--DelEnd-->

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**返回：**

如果创建成功返回指向OH_AVPlayer实例的指针，否则返回空指针。

可能的失败原因：

1. PlayerFactory::CreatePlayer执行失败；
2. new PlayerObject执行失败。


### OH_AVPlayer_DeselectTrack()

```
OH_AVErrCode OH_AVPlayer_DeselectTrack (OH_AVPlayer *player, int32_t index)
```
**描述**
取消选择当前音频轨道。该接口在当前版本暂不支持，将在后续版本开放能力。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 
| index | 索引  | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：成功取消。

AV_ERR_INVALID_VAL：输入player为空指针、player DeselectTrack执行失败。


### OH_AVPlayer_GetCurrentTime()

```
OH_AVErrCode OH_AVPlayer_GetCurrentTime (OH_AVPlayer *player, int32_t *currentTime)
```
**描述**
获取播放位置，精确到毫秒。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 
| currentTime | 播放位置 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：获取当前位置。

AV_ERR_INVALID_VAL：输入player为空指针、player GetCurrentTime执行失败。


### OH_AVPlayer_GetCurrentTrack()

```
OH_AVErrCode OH_AVPlayer_GetCurrentTrack (OH_AVPlayer *player, int32_t trackType, int32_t *index)
```
**描述**
获取当前有效的轨道索引。该接口在当前版本暂不支持，将在后续版本开放能力。

请将其设置为准备/正在播放/暂停/完成状态。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 
| trackType | 媒体类型。0：音频，1：视频 | 
| index | 索引 |  

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：成功获取。

AV_ERR_INVALID_VAL：输入player为空指针、player GetCurrentTrack执行失败。


### OH_AVPlayer_GetDuration()

```
OH_AVErrCode OH_AVPlayer_GetDuration (OH_AVPlayer *player, int32_t *duration)
```
**描述**
获取媒体文件的总时长，精确到毫秒。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 
| duration | 媒体文件的总时长 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：获取当前时长。

AV_ERR_INVALID_VAL：输入player为空指针、player GetDuration执行失败。


### OH_AVPlayer_GetMediaKeySystemInfo()

```
OH_AVErrCode OH_AVPlayer_GetMediaKeySystemInfo (OH_AVPlayer *player, DRM_MediaKeySystemInfo *mediaKeySystemInfo)
```
**描述**
获取媒体密钥系统信息以创建媒体密钥会话。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 |
| mediaKeySystemInfo | 媒体密钥系统信息 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：成功设置。

AV_ERR_INVALID_VAL：输入player为空指针、内存不足。

### OH_AVPlayer_GetPlaybackSpeed()

```
OH_AVErrCode OH_AVPlayer_GetPlaybackSpeed (OH_AVPlayer *player, AVPlaybackSpeed *speed)
```
**描述**
获取当前播放器播放速率。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 
| speed | 可以获取的速率模式[AVPlaybackSpeed](#avplaybackspeed) | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：成功获取播放速率。

AV_ERR_INVALID_VAL：输入player为空指针、player GetPlaybackSpeed执行失败。


### OH_AVPlayer_GetState()

```
OH_AVErrCode OH_AVPlayer_GetState (OH_AVPlayer *player, AVPlayerState *state)
```
**描述**
获取当前播放状态。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 
| state | 当前播放状态 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：获取当前播放状态。

AV_ERR_INVALID_VAL：输入player为空指针、player GetState执行失败。


### OH_AVPlayer_GetVideoHeight()

```
OH_AVErrCode OH_AVPlayer_GetVideoHeight (OH_AVPlayer *player, int32_t *videoHeight)
```
**描述**
获取视频高度。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 
| videoHeights | 视频高度 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：成功获取视频高度。

AV_ERR_INVALID_VAL：输入player为空指针。


### OH_AVPlayer_GetVideoWidth()

```
OH_AVErrCode OH_AVPlayer_GetVideoWidth (OH_AVPlayer *player, int32_t *videoWidth)
```
**描述**
获取视频宽度。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 
| videoWidth | 视频宽度 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：成功获取视频宽度。

AV_ERR_INVALID_VAL：输入player为空指针。


### OH_AVPlayer_IsLooping()

```
bool OH_AVPlayer_IsLooping (OH_AVPlayer *player)
```
**描述**
判断是否循环播放。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 

**返回：**

如果循环播放，则返回true；如果不是循环播放或者输入player为空指针则返回false。


### OH_AVPlayer_IsPlaying()

```
bool OH_AVPlayer_IsPlaying (OH_AVPlayer *player)
```
**描述**
判断播放器是否在播放。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 

**返回：**

如果正在播放，则返回true；如果不在播放或者输入player为空指针则返回false。


### OH_AVPlayer_Pause()

```
OH_AVErrCode OH_AVPlayer_Pause (OH_AVPlayer *player)
```
**描述**
暂停播放。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：成功将**Pause**添加到任务队列中。

AV_ERR_INVALID_VAL：输入player为空指针、player Pause执行失败。


### OH_AVPlayer_Play()

```
OH_AVErrCode OH_AVPlayer_Play (OH_AVPlayer *player)
```
**描述**
开始播放。

此函数必须在**Prepare**之后调用。如果播放器状态为&lt;Prepared&gt;。调用此函数开始播放。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：开始播放。

AV_ERR_INVALID_VAL：输入player为空指针、player Play执行失败。


### OH_AVPlayer_Prepare()

```
OH_AVErrCode OH_AVPlayer_Prepare (OH_AVPlayer *player)
```
**描述**
准备播放环境，异步缓存媒体数据。

此函数必须在**SetSource**之后调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：成功将**Prepare**添加到任务队列中。

AV_ERR_INVALID_VAL：输入player为空指针、player Prepare执行失败。


### OH_AVPlayer_Release()

```
OH_AVErrCode OH_AVPlayer_Release (OH_AVPlayer *player)
```
**描述**
异步释放播放器资源。

异步释放保证性能，但无法保证是否释放了播放画面的surfacebuffer。调用者需要保证播放画面窗口的生命周期安全。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：成功将**Release**添加到任务队列中。

AV_ERR_INVALID_VAL：输入player为空指针、player Release执行失败。


### OH_AVPlayer_ReleaseSync()

```
OH_AVErrCode OH_AVPlayer_ReleaseSync (OH_AVPlayer *player)
```
**描述**
同步释放播放器资源。

同步过程保证了播放画面的显示缓存释放，但这个过程花费时间较长，要求调用者自己设计异步机制。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：播放被释放。

AV_ERR_INVALID_VAL：输入player为空指针、player ReleaseSync执行失败。

### OH_AVPlayer_Reset()

```
OH_AVErrCode OH_AVPlayer_Reset (OH_AVPlayer *player)
```
**描述**
将播放器恢复到初始状态。

函数调用完成后，调用**SetSource**添加播放源。调用**Prepare**后，调用**Play**重新开始播放。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：成功将**reset**添加到任务队列。

AV_ERR_INVALID_VAL：输入player为空指针、player Reset执行失败。


### OH_AVPlayer_Seek()

```
OH_AVErrCode OH_AVPlayer_Seek (OH_AVPlayer *player, int32_t mSeconds, AVPlayerSeekMode mode)
```
**描述**
改变播放位置。

此函数可以在播放或暂停时使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针。 | 
| mSeconds | 播放目标位置，精确到毫秒。 | 
| mode | 播放器的跳转模式。具体请参考[AVPlayerSeekMode](#avplayerseekmode)。 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：完成跳转。

AV_ERR_INVALID_VAL：输入player为空指针、player Seek执行失败。


### OH_AVPlayer_SelectBitRate()

```
OH_AVErrCode OH_AVPlayer_SelectBitRate (OH_AVPlayer *player, uint32_t bitRate)
```
**描述**
设置hls播放器使用的码率。

播放比特率，以比特/秒为单位，以比特/秒为单位。 仅对HLS协议网络流有效。默认情况下， 播放器会根据网络连接情况选择合适的码率和速度。 通过INFO_TYPE_BITRATE_COLLECT上报有效码率链表 设置并选择指定的码率，选择小于和最接近的码率 到指定的码率播放。准备好后，读取它以查询当前选择的比特率。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 
| bitRate | 码率，单位为bps | 

**返回：**

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：设置码率成功。

AV_ERR_INVALID_VAL：输入player为空指针、player SelectBitRate执行失败。


### OH_AVPlayer_SelectTrack()

```
OH_AVErrCode OH_AVPlayer_SelectTrack (OH_AVPlayer *player, int32_t index)
```
**描述**
选择音频轨道。该接口在当前版本暂不支持，将在后续版本开放能力。

默认播放第一个带数据的音频流。设置生效后，原曲目将失效。将音轨设置为准备状态。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 
| index | 索引 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：成功选择。

AV_ERR_INVALID_VAL：输入player为空指针、player SelectTrack执行失败。


### OH_AVPlayer_SetAudioEffectMode()

```
OH_AVErrCode OH_AVPlayer_SetAudioEffectMode (OH_AVPlayer *player, OH_AudioStream_AudioEffectMode effectMode)
```
**描述**
设置player音频流的音效模式。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针。  | 
| interruptMode | player音频流使用的音效模式[OH_AudioStream_AudioEffectMode](../apis-audio-kit/_o_h_audio.md#oh_audiostream_audioeffectmode)。  | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：成功设置。

AV_ERR_INVALID_VAL：输入player为空指针或者effectMode值无效。


### OH_AVPlayer_SetAudioInterruptMode()

```
OH_AVErrCode OH_AVPlayer_SetAudioInterruptMode (OH_AVPlayer *player, OH_AudioInterrupt_Mode interruptMode)
```
**描述**
设置player音频流的打断模式。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针。  | 
| interruptMode | player音频流使用的打断模式[OH_AudioInterrupt_Mode](../apis-audio-kit/_o_h_audio.md#oh_audiointerrupt_mode)。  | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：成功设置。

AV_ERR_INVALID_VAL：输入player为空指针或者interruptMode值无效。


### OH_AVPlayer_SetAudioRendererInfo()

```
OH_AVErrCode OH_AVPlayer_SetAudioRendererInfo (OH_AVPlayer *player, OH_AudioStream_Usage streamUsage)
```
**描述**
设置player音频流类型。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针。  | 
| streamUsage | player音频流设置的类型[OH_AudioStream_Usage](../apis-audio-kit/_o_h_audio.md#oh_audiostream_usage)。  | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：成功设置。

AV_ERR_INVALID_VAL：输入player为空指针或者streamUsage值无效。


### OH_AVPlayer_SetDecryptionConfig()

```
OH_AVErrCode OH_AVPlayer_SetDecryptionConfig (OH_AVPlayer *player, MediaKeySession *mediaKeySession, bool secureVideoPath)
```
**描述**
设置解密信息。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针。 | 
| mediaKeySession | 具有解密功能的媒体密钥会话实例。 | 
| secureVideoPath | 是否需要安全解码器。 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：成功设置。

AV_ERR_INVALID_VAL：输入player为空指针、player SetDecryptionConfig执行失败。


### OH_AVPlayer_SetFDSource()

```
OH_AVErrCode OH_AVPlayer_SetFDSource (OH_AVPlayer *player, int32_t fd, int64_t offset, int64_t size)
```
**描述**
设置播放器的播放媒体文件描述符来源。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 
| fd | 媒体源的文件描述符 | 
| offset | 媒体源在文件描述符中的偏移量 | 
| size | 表示媒体源的大小 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：fd设置成功。

AV_ERR_INVALID_VAL：输入player为空指针、player SetFdSource执行失败。


### OH_AVPlayer_SetLooping()

```
OH_AVErrCode OH_AVPlayer_SetLooping (OH_AVPlayer *player, bool loop)
```
**描述**
设置循环播放。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 
| loop | 循环播放开关 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：循环播放设置成功。

AV_ERR_INVALID_VAL：输入player为空指针、player SetLooping执行失败。


### OH_AVPlayer_SetMediaKeySystemInfoCallback()

```
OH_AVErrCode OH_AVPlayer_SetMediaKeySystemInfoCallback (OH_AVPlayer *player, Player_MediaKeySystemInfoCallback callback)
```
**描述**
设置播放器媒体密钥系统信息回调的方法。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针。 | 
| callback | 对象指针。 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：设置成功。

AV_ERR_INVALID_VAL：输入player为空、callback为空、player SetDrmSystemInfoCallback执行失败。


### OH_AVPlayer_SetOnErrorCallback()

```
OH_AVErrCode OH_AVPlayer_SetOnErrorCallback (OH_AVPlayer * player, OH_AVPlayerOnErrorCallback callback, void * userData )
```
**描述**
设置播放器错误回调监听函数。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针。  | 
| callback | 执行回调监听函数的指针, 空指针表示取消设置播放器错误回调监听。  | 
| userData | 指向应用调用者设置的实例的指针。  | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：成功。 

AV_ERR_NO_MEMORY：输入分配内存失败。

AV_ERR_INVALID_VAL：输入player为空指针或者函数执行失败。


### OH_AVPlayer_SetOnInfoCallback()

```
OH_AVErrCode OH_AVPlayer_SetOnInfoCallback (OH_AVPlayer * player, OH_AVPlayerOnInfoCallback callback, void * userData )
```
**描述**
设置播放器消息回调监听函数。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针。  | 
| callback | 执行回调监听函数的指针, 空指针表示取消设置播放器消息回调监听。  | 
| userData | 指向应用调用者设置的实例的指针。  | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：成功。 

AV_ERR_NO_MEMORY：输入分配内存失败。

AV_ERR_INVALID_VAL：输入player为空指针或者函数执行失败。


### OH_AVPlayer_SetPlaybackSpeed()

```
OH_AVErrCode OH_AVPlayer_SetPlaybackSpeed (OH_AVPlayer *player, AVPlaybackSpeed speed)
```
**描述**
设置播放器播放速率。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 
| speed | 可以设置速率模式[AVPlaybackSpeed](#avplaybackspeed) | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：成功设置播放速率。

AV_ERR_INVALID_VAL：输入player为空指针。


### OH_AVPlayer_SetPlayerCallback()

```
OH_AVErrCode OH_AVPlayer_SetPlayerCallback (OH_AVPlayer *player, AVPlayerCallback callback)
```
**描述**
设置播放器回调函数。由于通过此方法设置的信息监听回调函数[OH_AVPlayerOnInfo](#oh_avplayeroninfo)和错误监听回调函数[OH_AVPlayerOnError](#oh_avplayeronerror)可以传递信息有限，也不便于应用区分多个播放器实例。从 API 12 开始，应使用[OH_AVPlayer_SetOnInfoCallback()](#oh_avplayer_setoninfocallback)、[OH_AVPlayer_SetOnErrorCallback()](#oh_avplayer_setonerrorcallback)接口分别设置信息监听回调函数[OH_AVPlayerOnInfoCallback](../../reference/apis-media-kit/_a_v_player.md#oh_avplayeroninfocallback)和错误监听回调函数[OH_AVPlayerOnErrorCallback](../../reference/apis-media-kit/_a_v_player.md#oh_avplayeronerrorcallback)。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 
| callback | 回调对象指针 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：成功设置播放器回调。

AV_ERR_INVALID_VAL：输入player为空指针、callback.onInfo或onError为空、player SetPlayerCallback执行失败。


### OH_AVPlayer_SetURLSource()

```
OH_AVErrCode OH_AVPlayer_SetURLSource (OH_AVPlayer *player, const char *url)
```
**描述**
设置播放器的播放源。对应的源可以是http url。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 
| url | 播放源 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：设置成功。

AV_ERR_INVALID_VAL：输入player为空指针、url为空、player SetUrlSource执行失败。


### OH_AVPlayer_SetVideoSurface()

```
OH_AVErrCode OH_AVPlayer_SetVideoSurface (OH_AVPlayer *player, OHNativeWindow *window)
```
**描述**
设置播放画面窗口。
此函数必须在**SetSource**之后，**Prepare**之前调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 
| window | 指向OHNativeWindow实例的指针 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：设置播放画面窗口成功。

AV_ERR_INVALID_VAL：输入player为空指针、输入window为空指针、player SetVideoSurface执行失败。


### OH_AVPlayer_SetVolume()

```
OH_AVErrCode OH_AVPlayer_SetVolume (OH_AVPlayer *player, float leftVolume, float rightVolume)
```
**描述**
设置播放器的音量。

可以在播放或暂停的过程中使用。&lt;0&gt;表示无声音，&lt;1&gt;为原始值。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 
| leftVolume | 要设置的左声道目标音量 | 
| rightVolume | 要设置的右声道目标音量 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：设置音量成功。

AV_ERR_INVALID_VAL：输入player为空指针、player SetVolume执行失败。


### OH_AVPlayer_Stop()

```
OH_AVErrCode OH_AVPlayer_Stop (OH_AVPlayer *player)
```
**描述**
停止播放。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| player | 指向OH_AVPlayer实例的指针 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：成功将**stop**添加到任务队列。

AV_ERR_INVALID_VAL：输入player为空指针、player Stop执行失败。


## 变量说明


### OH_PLAYER_AUDIO_DEVICE_CHANGE_REASON

```
const char* OH_PLAYER_AUDIO_DEVICE_CHANGE_REASON
```
**描述**
获取音频音频设备变更原因的关键字, 对应值类型是int32_t。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


### OH_PLAYER_AUDIO_INTERRUPT_FORCE

```
const char* OH_PLAYER_AUDIO_INTERRUPT_FORCE
```
**描述**
获取音频打断FORCE类型的关键字, 对应值类型是int32_t。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


### OH_PLAYER_AUDIO_INTERRUPT_HINT

```
const char* OH_PLAYER_AUDIO_INTERRUPT_HINT
```
**描述**
获取音频打断HINT类型的关键字, 对应值类型是int32_t。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


### OH_PLAYER_AUDIO_INTERRUPT_TYPE

```
const char* OH_PLAYER_AUDIO_INTERRUPT_TYPE
```
**描述**
获取音频打断类型的关键字, 对应值类型是int32_t。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


### OH_PLAYER_BITRATE

```
const char* OH_PLAYER_BITRATE
```
**描述**
获取比特率信息的关键字, 对应值类型是int32_t。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


### OH_PLAYER_BITRATE_ARRAY

```
const char* OH_PLAYER_BITRATE_ARRAY
```
**描述**
获取比特率列表的关键字, 对应值类型是uint8_t字节数组。通过该关键字获取信息时：
- 需要先使用 uint8_t 类型指针变量保存比特率列表，使用 size_t 类型变量保存字节数组长度。
- 然后分配若干个 uint32_t 类型的存储空间，接收将 uint8_t 字节数组转换为 uint32_t 类型比特率整数值。可以参考[完整实例](../../media/media/using-ndk-avplayer-for-playback.md#完整示例)中**OHAVPlayerOnInfoCallback**函数。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


### OH_PLAYER_BUFFERING_TYPE

```
const char* OH_PLAYER_BUFFERING_TYPE
```
**描述**
获取缓冲更新消息类型的关键字, 对应值类型是[AVPlayerBufferingType](#avplayerbufferingtype-1)。通过该关键字获取信息时，需要先使用 int32_t 类型变量保存结果，再转换为类型[AVPlayerBufferingType](#avplayerbufferingtype-1)。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


### OH_PLAYER_BUFFERING_VALUE

```
const char* OH_PLAYER_BUFFERING_VALUE
```
**描述**
获取缓冲更新消息具体数值的关键字, 对应值类型是int32_t。参见[AVPlayerBufferingType](#avplayerbufferingtype-1)，当缓冲更新消息类型是AVPLAYER_BUFFERING_PERCENT、AVPLAYER_BUFFERING_CACHED_DURATION时有效。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


### OH_PLAYER_CURRENT_POSITION

```
const char* OH_PLAYER_CURRENT_POSITION
```
**描述**
获取播放进度信息的关键字, 对应值类型是int32_t。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


### OH_PLAYER_DURATION

```
const char* OH_PLAYER_DURATION
```
**描述**
获取媒体资源时长信息的关键字, 对应值类型是int64_t。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


### OH_PLAYER_IS_LIVE_STREAM

```
const char* OH_PLAYER_IS_LIVE_STREAM
```
**描述**
获取媒体资源是否为直播类型信息的关键字, 对应值类型int32_t。

1：直播。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


### OH_PLAYER_MESSAGE_TYPE

```
const char* OH_PLAYER_MESSAGE_TYPE
```
**描述**
获取播放器消息信息的关键字, 对应值类型int32_t。

1：视频帧开始渲染。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


### OH_PLAYER_PLAYBACK_SPEED

```
const char* OH_PLAYER_PLAYBACK_SPEED
```
**描述**
获取播放倍速信息的关键字, 对应值类型是[AVPlaybackSpeed](#avplaybackspeed-1)。通过该关键字获取信息时，需要先使用 int32_t 类型变量保存结果，再转换为类型[AVPlaybackSpeed](#avplaybackspeed-1)。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


### OH_PLAYER_SEEK_POSITION

```
const char* OH_PLAYER_SEEK_POSITION
```
**描述**
获取Seek后播放进度信息的关键字, 对应值类型是int32_t。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


### OH_PLAYER_STATE

```
const char* OH_PLAYER_STATE
```
**描述**
获取播放状态的关键字, 对应值类型是int32_t。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


### OH_PLAYER_STATE_CHANGE_REASON

```
const char* OH_PLAYER_STATE_CHANGE_REASON
```
**描述**
获取播放状态变更原因的关键字, 对应值类型是int32_t。

1：用户操作触发；2：系统变更触发。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


### OH_PLAYER_VIDEO_HEIGHT

```
const char* OH_PLAYER_VIDEO_HEIGHT
```
**描述**
获取视频高度信息的关键字, 对应值类型int32_t。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


### OH_PLAYER_VIDEO_WIDTH

```
const char* OH_PLAYER_VIDEO_WIDTH
```
**描述**
获取视频宽度信息的关键字, 对应值类型int32_t。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


### OH_PLAYER_VOLUME

```
const char* OH_PLAYER_VOLUME
```
**描述**
获取音量的关键字, 对应值类型是float。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12
