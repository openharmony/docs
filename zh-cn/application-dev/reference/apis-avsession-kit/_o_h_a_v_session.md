# OHAVSession


## 概述

提供播控模块C接口定义。

开发者可使用OHAVSession，作为媒体会话提供方接入AVSession服务，对应的开发指南及样例可参考[媒体会话提供方](../../media/avsession/using-ohavsession-developer.md)。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**起始版本：** 13


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_avmetadata.h](native__avmetadata_8h.md) | 提供播控元数据的定义。 | 
| [native_avsession.h](native__avsession_8h.md) | 媒体会话定义，可用于设置元数据、播放状态信息等操作。 | 
| [native_avsession_errors.h](native__avsession__errors_8h.md) | 提供播控错误码的定义。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [AVSession_PlaybackPosition](_a_v_session___playback_position.md) | 媒体播放位置的相关属性。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct OH_AVMetadataBuilderStruct [OH_AVMetadataBuilder](#oh_avmetadatabuilder) | 会话元数据构造器。 构造器用于构造会话元数据。 | 
| typedef struct OH_AVMetadataStruct [OH_AVMetadata](#oh_avmetadata) | 会话元数据。 资源设置的avmetadata的实例。 | 
| typedef struct [AVSession_PlaybackPosition](_a_v_session___playback_position.md) [AVSession_PlaybackPosition](#avsession_playbackposition) | 媒体播放位置的相关属性。 | 
| typedef enum [AVSession_ControlCommand](#avsession_controlcommand) [AVSession_ControlCommand](#avsession_controlcommand) | 播控命令。 | 
| typedef [AVSessionCallback_Result](#avsessioncallback_result)(\* [OH_AVSessionCallback_OnCommand](#oh_avsessioncallback_oncommand)) ([OH_AVSession](#oh_avsession) \*session, [AVSession_ControlCommand](#avsession_controlcommand) command, void \*userData) | 通用的执行播控命令的回调。 | 
| typedef [AVSessionCallback_Result](#avsessioncallback_result)(\* [OH_AVSessionCallback_OnFastForward](#oh_avsessioncallback_onfastforward)) ([OH_AVSession](#oh_avsession) \*session, uint32_t seekTime, void \*userData) | 快进的回调。 | 
| typedef [AVSessionCallback_Result](#avsessioncallback_result)(\* [OH_AVSessionCallback_OnRewind](#oh_avsessioncallback_onrewind)) ([OH_AVSession](#oh_avsession) \*session, uint32_t seekTime, void \*userData) | 快退的回调。 | 
| typedef [AVSessionCallback_Result](#avsessioncallback_result)(\* [OH_AVSessionCallback_OnSeek](#oh_avsessioncallback_onseek)) ([OH_AVSession](#oh_avsession) \*session, uint64_t seekTime, void \*userData) | 进度调节的回调。 | 
| typedef [AVSessionCallback_Result](#avsessioncallback_result)(\* [OH_AVSessionCallback_OnSetLoopMode](#oh_avsessioncallback_onsetloopmode)) ([OH_AVSession](#oh_avsession) \*session, [AVSession_LoopMode](#avsession_loopmode) curLoopMode, void \*userData) | 设置循环模式的回调。 | 
| typedef [AVSessionCallback_Result](#avsessioncallback_result)(\* [OH_AVSessionCallback_OnToggleFavorite](#oh_avsessioncallback_ontogglefavorite)) ([OH_AVSession](#oh_avsession) \*session, const char \*assetId, void \*userData) | 收藏的回调。 | 
| typedef struct [OH_AVSession](#oh_avsession) [OH_AVSession](#oh_avsession) | 播控会话对象定义。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [AVMetadata_Result](#avmetadata_result) {<br/>AVMETADATA_SUCCESS = 0,<br/>AVMETADATA_ERROR_INVALID_PARAM = 1,<br/>AVMETADATA_ERROR_NO_MEMORY = 2 } | 元数据操作的错误码。 | 
| [AVMetadata_SkipIntervals](#avmetadata_skipintervals) {<br/>SECONDS_10 = 10,<br/>SECONDS_15 = 15,<br/>SECONDS_30 = 30 } | 表示session支持的快进快退时间间隔。 | 
| [AVMetadata_DisplayTag](#avmetadata_displaytag) { AVSESSION_DISPLAYTAG_AUDIO_VIVID = 1 } | 应用媒体音源的特殊类型标识。 | 
| [AVSession_Type](#avsession_type) {<br/>SESSION_TYPE_AUDIO = 0,<br/>SESSION_TYPE_VIDEO = 1,<br/>SESSION_TYPE_VOICE_CALL = 2,<br/>SESSION_TYPE_VIDEO_CALL = 3 } | 会话类型。 | 
| [AVSession_PlaybackState](#avsession_playbackstate) {<br/>PLAYBACK_STATE_INITIAL = 0,<br/>PLAYBACK_STATE_PREPARING = 1,<br/>PLAYBACK_STATE_PLAYING = 2,<br/>PLAYBACK_STATE_PAUSED = 3,<br/>PLAYBACK_STATE_FAST_FORWARDING = 4,<br/>PLAYBACK_STATE_REWINDED = 5,<br/>PLAYBACK_STATE_STOPPED = 6,<br/>PLAYBACK_STATE_COMPLETED = 7,<br/>PLAYBACK_STATE_RELEASED = 8,<br/>PLAYBACK_STATE_ERROR = 9,<br/>PLAYBACK_STATE_IDLE = 10,<br/>PLAYBACK_STATE_BUFFERING = 11,<br/>PLAYBACK_STATE_MAX = 12<br/>} | 媒体播放状态的相关属性。 | 
| [AVSession_LoopMode](#avsession_loopmode) {<br/>LOOP_MODE_SEQUENCE = 0,<br/>LOOP_MODE_SINGLE = 1,<br/>LOOP_MODE_LIST = 2,<br/>LOOP_MODE_SHUFFLE = 3,<br/>LOOP_MODE_CUSTOM = 4<br/>} | 媒体播放循环模式。 | 
| [AVSession_ControlCommand](#avsession_controlcommand) {<br/>CONTROL_CMD_INVALID = -1,<br/>CONTROL_CMD_PLAY = 0,<br/>CONTROL_CMD_PAUSE = 1,<br/>CONTROL_CMD_STOP = 2,<br/>CONTROL_CMD_PLAY_NEXT = 3,<br/>CONTROL_CMD_PLAY_PREVIOUS = 4<br/>} | 播控命令。 | 
| [AVSessionCallback_Result](#avsessioncallback_result) {<br/>AVSESSION_CALLBACK_RESULT_SUCCESS = 0,<br/>AVSESSION_CALLBACK_RESULT_FAILURE = -1 } | 回调执行的结果。 | 
| [AVSession_ErrCode](#avsession_errcode) {<br/>AV_SESSION_ERR_SUCCESS = 0,<br/>AV_SESSION_ERR_INVALID_PARAMETER = 401,<br/>AV_SESSION_ERR_SERVICE_EXCEPTION = 6600101,<br/>AV_SESSION_ERR_CODE_SESSION_NOT_EXIST = 6600102,<br/>AV_SESSION_ERR_CODE_COMMAND_INVALID = 6600105,<br/>AV_SESSION_ERR_CODE_SESSION_INACTIVE = 6600106,<br/>AV_SESSION_ERR_CODE_MESSAGE_OVERLOAD = 6600107<br/>} | 播控错误码。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_Create](#oh_avmetadatabuilder_create) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*\*builder) | 创建一个元数据构造器。 | 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_Destroy](#oh_avmetadatabuilder_destroy) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder) | 销毁元数据构造器。 | 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetAssetId](#oh_avmetadatabuilder_setassetid) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, const char \*assetId) | 设置当前媒体资源id。 | 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetTitle](#oh_avmetadatabuilder_settitle) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, const char \*title) | 设置资源标题。 | 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetArtist](#oh_avmetadatabuilder_setartist) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, const char \*artist) | 设置资源所属的艺术家。 | 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetAuthor](#oh_avmetadatabuilder_setauthor) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, const char \*author) | 设置资源的作者。 | 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetAlbum](#oh_avmetadatabuilder_setalbum) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, const char \*album) | 设置资源专辑名称。 | 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetWriter](#oh_avmetadatabuilder_setwriter) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, const char \*writer) | 设置资源词作者。 | 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetComposer](#oh_avmetadatabuilder_setcomposer) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, const char \*composer) | 设置资源作曲者。 | 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetDuration](#oh_avmetadatabuilder_setduration) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, int64_t duration) | 设置资源播放时长。 | 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetMediaImageUri](#oh_avmetadatabuilder_setmediaimageuri) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, const char \*mediaImageUri) | 设置媒体图片数据。 | 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetSubtitle](#oh_avmetadatabuilder_setsubtitle) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, const char \*subtitle) | 设置副标题。 | 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetDescription](#oh_avmetadatabuilder_setdescription) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, const char \*description) | 设置媒体描述信息。 | 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetLyric](#oh_avmetadatabuilder_setlyric) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, const char \*lyric) | 设置歌词。 | 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetSkipIntervals](#oh_avmetadatabuilder_setskipintervals) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, [AVMetadata_SkipIntervals](#avmetadata_skipintervals) intervals) | 设置资源的跳转的间隔时间。 | 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetDisplayTags](#oh_avmetadatabuilder_setdisplaytags) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, int32_t tags) | 设置媒体资源的金标类型。 | 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_GenerateAVMetadata](#oh_avmetadatabuilder_generateavmetadata) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, [OH_AVMetadata](#oh_avmetadata) \*\*avMetadata) | 生成媒体元数据对象。 | 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadata_Destroy](#oh_avmetadata_destroy) ([OH_AVMetadata](#oh_avmetadata) \*avMetadata) | 释放媒体元数据对象。 | 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_Create](#oh_avsession_create) ([AVSession_Type](#avsession_type) sessionType, const char \*sessionTag, const char \*bundleName, const char \*abilityName, [OH_AVSession](#oh_avsession) \*\*avsession) | 创建会话对象。 | 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_Destroy](#oh_avsession_destroy) ([OH_AVSession](#oh_avsession) \*avsession) | 销毁会话对象。 | 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_Activate](#oh_avsession_activate) ([OH_AVSession](#oh_avsession) \*avsession) | 激活会话。 | 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_Deactivate](#oh_avsession_deactivate) ([OH_AVSession](#oh_avsession) \*avsession) | 取消激活媒体会话。 | 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_GetSessionType](#oh_avsession_getsessiontype) ([OH_AVSession](#oh_avsession) \*avsession, [AVSession_Type](#avsession_type) \*sessionType) | 获取会话类型。 | 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_GetSessionId](#oh_avsession_getsessionid) ([OH_AVSession](#oh_avsession) \*avsession, const char \*\*sessionId) | 获取会话id。 | 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_SetAVMetadata](#oh_avsession_setavmetadata) ([OH_AVSession](#oh_avsession) \*avsession, [OH_AVMetadata](#oh_avmetadata) \*avmetadata) | 设置媒体元数据。 | 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_SetPlaybackState](#oh_avsession_setplaybackstate) ([OH_AVSession](#oh_avsession) \*avsession, [AVSession_PlaybackState](#avsession_playbackstate) playbackState) | 设置播放状态。 | 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_SetPlaybackPosition](#oh_avsession_setplaybackposition) ([OH_AVSession](#oh_avsession) \*avsession, [AVSession_PlaybackPosition](_a_v_session___playback_position.md) \*playbackPosition) | 设置播放位置。 | 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_SetFavorite](#oh_avsession_setfavorite) ([OH_AVSession](#oh_avsession) \*avsession, bool favorite) | 设置收藏状态。 | 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_SetLoopMode](#oh_avsession_setloopmode) ([OH_AVSession](#oh_avsession) \*avsession, [AVSession_LoopMode](#avsession_loopmode) loopMode) | 设置循环模式。 | 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_RegisterCommandCallback](#oh_avsession_registercommandcallback) ([OH_AVSession](#oh_avsession) \*avsession, [AVSession_ControlCommand](#avsession_controlcommand) command, [OH_AVSessionCallback_OnCommand](#oh_avsessioncallback_oncommand) callback, void \*userData) | 注册通用播控的回调。 | 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_UnregisterCommandCallback](#oh_avsession_unregistercommandcallback) ([OH_AVSession](#oh_avsession) \*avsession, [AVSession_ControlCommand](#avsession_controlcommand) command, [OH_AVSessionCallback_OnCommand](#oh_avsessioncallback_oncommand) callback) | 取消注册通用播控的回调。 | 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_RegisterForwardCallback](#oh_avsession_registerforwardcallback) ([OH_AVSession](#oh_avsession) \*avsession, [OH_AVSessionCallback_OnFastForward](#oh_avsessioncallback_onfastforward) callback, void \*userData) | 注册快进的回调。 | 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_UnregisterForwardCallback](#oh_avsession_unregisterforwardcallback) ([OH_AVSession](#oh_avsession) \*avsession, [OH_AVSessionCallback_OnFastForward](#oh_avsessioncallback_onfastforward) callback) | 取消注册快进的回调。 | 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_RegisterRewindCallback](#oh_avsession_registerrewindcallback) ([OH_AVSession](#oh_avsession) \*avsession, [OH_AVSessionCallback_OnRewind](#oh_avsessioncallback_onrewind) callback, void \*userData) | 注册快退的回调。 | 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_UnregisterRewindCallback](#oh_avsession_unregisterrewindcallback) ([OH_AVSession](#oh_avsession) \*avsession, [OH_AVSessionCallback_OnRewind](#oh_avsessioncallback_onrewind) callback) | 取消注册快退的回调。 | 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_RegisterSeekCallback](#oh_avsession_registerseekcallback) ([OH_AVSession](#oh_avsession) \*avsession, [OH_AVSessionCallback_OnSeek](#oh_avsessioncallback_onseek) callback, void \*userData) | 注册跳转的回调。 | 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_UnregisterSeekCallback](#oh_avsession_unregisterseekcallback) ([OH_AVSession](#oh_avsession) \*avsession, [OH_AVSessionCallback_OnSeek](#oh_avsessioncallback_onseek) callback) | 取消注册跳转的回调。 | 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_RegisterSetLoopModeCallback](#oh_avsession_registersetloopmodecallback) ([OH_AVSession](#oh_avsession) \*avsession, [OH_AVSessionCallback_OnSetLoopMode](#oh_avsessioncallback_onsetloopmode) callback, void \*userData) | 注册设置循环模式的回调。 | 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_UnregisterSetLoopModeCallback](#oh_avsession_unregistersetloopmodecallback) ([OH_AVSession](#oh_avsession) \*avsession, [OH_AVSessionCallback_OnSetLoopMode](#oh_avsessioncallback_onsetloopmode) callback) | 取消注册设置循环模式的回调。 | 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_RegisterToggleFavoriteCallback](#oh_avsession_registertogglefavoritecallback) ([OH_AVSession](#oh_avsession) \*avsession, [OH_AVSessionCallback_OnToggleFavorite](#oh_avsessioncallback_ontogglefavorite) callback, void \*userData) | 设置收藏的回调。 | 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_UnregisterToggleFavoriteCallback](#oh_avsession_unregistertogglefavoritecallback) ([OH_AVSession](#oh_avsession) \*avsession, [OH_AVSessionCallback_OnToggleFavorite](#oh_avsessioncallback_ontogglefavorite) callback) | 取消设置收藏的回调。 | 


## 类型定义说明


### AVSession_ControlCommand

```
typedef enum AVSession_ControlCommand AVSession_ControlCommand
```

**描述**

播控命令。

**起始版本：** 13


### AVSession_PlaybackPosition

```
typedef struct AVSession_PlaybackPosition AVSession_PlaybackPosition
```

**描述**

媒体播放位置的相关属性。

**起始版本：** 13


### OH_AVMetadata

```
typedef struct OH_AVMetadataStruct OH_AVMetadata
```

**描述**

会话元数据。 资源设置的avmetadata的实例。

**起始版本：** 13


### OH_AVMetadataBuilder

```
typedef struct OH_AVMetadataBuilderStruct OH_AVMetadataBuilder
```

**描述**

会话元数据构造器。 构造器用于构造会话元数据。

**起始版本：** 13


### OH_AVSession

```
typedef struct OH_AVSession OH_AVSession
```

**描述**

播控会话对象定义。

可以用OH_AVSession_Create创建一个会话对象。

**起始版本：** 13


### OH_AVSessionCallback_OnCommand

```
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnCommand)(OH_AVSession* session, AVSession_ControlCommand command, void* userData)
```

**描述**

通用的执行播控命令的回调。

**起始版本：** 13


### OH_AVSessionCallback_OnFastForward

```
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnFastForward)(OH_AVSession* session, uint32_t seekTime, void* userData)
```

**描述**

快进的回调。

**起始版本：** 13


### OH_AVSessionCallback_OnRewind

```
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnRewind)(OH_AVSession* session, uint32_t seekTime, void* userData)
```

**描述**

快退的回调。

**起始版本：** 13


### OH_AVSessionCallback_OnSeek

```
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnSeek)(OH_AVSession* session, uint64_t seekTime, void* userData)
```

**描述**

进度调节的回调。

**起始版本：** 13


### OH_AVSessionCallback_OnSetLoopMode

```
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnSetLoopMode)(OH_AVSession* session, AVSession_LoopMode curLoopMode, void* userData)
```

**描述**

设置循环模式的回调。

**起始版本：** 13


### OH_AVSessionCallback_OnToggleFavorite

```
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnToggleFavorite)(OH_AVSession* session, const char* assetId, void* userData)
```

**描述**

收藏的回调。

**起始版本：** 13


## 枚举类型说明


### AVMetadata_DisplayTag

```
enum AVMetadata_DisplayTag
```

**描述**

应用媒体音源的特殊类型标识。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| AVSESSION_DISPLAYTAG_AUDIO_VIVID | AUDIO VIVID标识。 | 


### AVMetadata_Result

```
enum AVMetadata_Result
```

**描述**

元数据操作的错误码。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| AVMETADATA_SUCCESS | 执行成功。 | 
| AVMETADATA_ERROR_INVALID_PARAM | 入参错误。 | 
| AVMETADATA_ERROR_NO_MEMORY | 内存不足。 | 


### AVMetadata_SkipIntervals

```
enum AVMetadata_SkipIntervals
```

**描述**

表示session支持的快进快退时间间隔。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| SECONDS_10 | 时间为10秒。 | 
| SECONDS_15 | 时间为15秒。 | 
| SECONDS_30 | 时间为30秒。 | 


### AVSession_ControlCommand

```
enum AVSession_ControlCommand
```

**描述**

播控命令。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| CONTROL_CMD_INVALID | 无效控制命令。 | 
| CONTROL_CMD_PLAY | 播放命令。 | 
| CONTROL_CMD_PAUSE | 暂停命令。 | 
| CONTROL_CMD_STOP | 停止命令。 | 
| CONTROL_CMD_PLAY_NEXT | 播放下一首命令。 | 
| CONTROL_CMD_PLAY_PREVIOUS | 播放上一首命令。 | 


### AVSession_ErrCode

```
enum AVSession_ErrCode
```

**描述**

播控错误码。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| AV_SESSION_ERR_SUCCESS | 操作成功。 | 
| AV_SESSION_ERR_INVALID_PARAMETER | 参数检查失败。 | 
| AV_SESSION_ERR_SERVICE_EXCEPTION | 会话服务端异常。 | 
| AV_SESSION_ERR_CODE_SESSION_NOT_EXIST | 会话不存在。 | 
| AV_SESSION_ERR_CODE_COMMAND_INVALID | 无效会话命令。 | 
| AV_SESSION_ERR_CODE_SESSION_INACTIVE | 会话未激活。 | 
| AV_SESSION_ERR_CODE_MESSAGE_OVERLOAD | 命令&amp;消息过载。 | 


### AVSession_LoopMode

```
enum AVSession_LoopMode
```

**描述**

媒体播放循环模式。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| LOOP_MODE_SEQUENCE | 顺序播放。 | 
| LOOP_MODE_SINGLE | 单曲循环。 | 
| LOOP_MODE_LIST | 表单循环。 | 
| LOOP_MODE_SHUFFLE | 随机播放。 | 
| LOOP_MODE_CUSTOM | 自定义播放。 | 


### AVSession_PlaybackState

```
enum AVSession_PlaybackState
```

**描述**

媒体播放状态的相关属性。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| PLAYBACK_STATE_INITIAL | 初始状态。 | 
| PLAYBACK_STATE_PREPARING | 准备状态。 | 
| PLAYBACK_STATE_PLAYING | 正在播放。 | 
| PLAYBACK_STATE_PAUSED | 暂停。 | 
| PLAYBACK_STATE_FAST_FORWARDING | 快进。 | 
| PLAYBACK_STATE_REWINDED | 快退。 | 
| PLAYBACK_STATE_STOPPED | 停止。 | 
| PLAYBACK_STATE_COMPLETED | 播放完成。 | 
| PLAYBACK_STATE_RELEASED | 释放。 | 
| PLAYBACK_STATE_ERROR | 错误。 | 
| PLAYBACK_STATE_IDLE | 空闲。 | 
| PLAYBACK_STATE_BUFFERING | 缓冲。 | 
| PLAYBACK_STATE_MAX | 最大状态。（当state为12时，返回错误码401） | 


### AVSession_Type

```
enum AVSession_Type
```

**描述**

会话类型。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| SESSION_TYPE_AUDIO | 音频。 | 
| SESSION_TYPE_VIDEO | 视频。 | 
| SESSION_TYPE_VOICE_CALL | 音频通话。 | 
| SESSION_TYPE_VIDEO_CALL | 视频通话。 | 


### AVSessionCallback_Result

```
enum AVSessionCallback_Result
```

**描述**

回调执行的结果。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| AVSESSION_CALLBACK_RESULT_SUCCESS | 执行成功。 | 
| AVSESSION_CALLBACK_RESULT_FAILURE | 执行失败。 | 


## 函数说明


### OH_AVMetadata_Destroy()

```
AVMetadata_Result OH_AVMetadata_Destroy(OH_AVMetadata* avMetadata)
```

**描述**

释放媒体元数据对象。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| avMetadata | 指向元数据的指针对象。 | 

**返回：**

函数返回值[AVMetadata_Result](#avmetadata_result)：

AVMETADATA_SUCCESS：函数执行成功。

AVMETADATA_ERROR_INVALID_PARAM：参数avMetadata为nullptr。


### OH_AVMetadataBuilder_Create()

```
AVMetadata_Result OH_AVMetadataBuilder_Create(OH_AVMetadataBuilder** builder)
```

**描述**

创建一个元数据构造器。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 该引用指向创建的构造器的结果。 | 

**返回：**

函数返回值[AVMetadata_Result](#avmetadata_result)：

AVMETADATA_SUCCESS：函数执行成功。

AVMETADATA_ERROR_INVALID_PARAM：参数builder为nullptr。

AVMETADATA_ERROR_NO_MEMORY：没有内存来分配新实例。


### OH_AVMetadataBuilder_Destroy()

```
AVMetadata_Result OH_AVMetadataBuilder_Destroy(OH_AVMetadataBuilder* builder)
```

**描述**

销毁元数据构造器。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向元数据构造器的实例。 | 

**返回：**

函数返回值[AVMetadata_Result](#avmetadata_result)：

AVMETADATA_SUCCESS：函数执行成功。

AVMETADATA_ERROR_INVALID_PARAM：参数builder为nullptr。


### OH_AVMetadataBuilder_GenerateAVMetadata()

```
AVMetadata_Result OH_AVMetadataBuilder_GenerateAVMetadata(OH_AVMetadataBuilder* builder, OH_AVMetadata** avMetadata)
```

**描述**

生成媒体元数据对象。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向元数据构造器的实例。 | 
| avMetadata | 指向元数据的指针对象。 | 

**返回：**

函数返回值[AVMetadata_Result](#avmetadata_result)：

AVMETADATA_SUCCESS：函数执行成功。

AVMETADATA_ERROR_NO_MEMORY：内存不足。

AVMETADATA_ERROR_INVALID_PARAM：

1. 参数builder为nullptr。

2. 参数avMetadata为nullptr。


### OH_AVMetadataBuilder_SetAlbum()

```
AVMetadata_Result OH_AVMetadataBuilder_SetAlbum(OH_AVMetadataBuilder* builder, const char* album)
```

**描述**

设置资源专辑名称。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向元数据构造器的实例。 | 
| album | 专辑名。 | 

**返回：**

函数返回值[AVMetadata_Result](#avmetadata_result)：

AVMETADATA_SUCCESS：函数执行成功。

AVMETADATA_ERROR_INVALID_PARAM：
1. 参数builder为nullptr。

2. 参数album为nullptr。


### OH_AVMetadataBuilder_SetArtist()

```
AVMetadata_Result OH_AVMetadataBuilder_SetArtist(OH_AVMetadataBuilder* builder, const char* artist)
```

**描述**

设置资源所属的艺术家。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向元数据构造器的实例。 | 
| artist | 艺术家。 | 

**返回：**

函数返回值[AVMetadata_Result](#avmetadata_result)：

AVMETADATA_SUCCESS：函数执行成功。

AVMETADATA_ERROR_INVALID_PARAM：
1. 参数builder为nullptr。

2. 参数artist为nullptr。


### OH_AVMetadataBuilder_SetAssetId()

```
AVMetadata_Result OH_AVMetadataBuilder_SetAssetId(OH_AVMetadataBuilder* builder, const char* assetId)
```

**描述**

设置当前媒体资源id。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向元数据构造器的实例。 | 
| assetId | 资源id。 | 

**返回：**

函数返回值[AVMetadata_Result](#avmetadata_result)：

AVMETADATA_SUCCESS：函数执行成功。

AVMETADATA_ERROR_INVALID_PARAM：

1. 参数builder为nullptr。

2. 参数assetId为nullptr。


### OH_AVMetadataBuilder_SetAuthor()

```
AVMetadata_Result OH_AVMetadataBuilder_SetAuthor(OH_AVMetadataBuilder* builder, const char* author)
```

**描述**

设置资源的作者。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向元数据构造器的实例。 | 
| author | 作者。 | 

**返回：**

函数返回值[AVMetadata_Result](#avmetadata_result)：

AVMETADATA_SUCCESS：函数执行成功。

AVMETADATA_ERROR_INVALID_PARAM：

1. 参数builder为nullptr。

2. 参数author为nullptr。


### OH_AVMetadataBuilder_SetComposer()

```
AVMetadata_Result OH_AVMetadataBuilder_SetComposer(OH_AVMetadataBuilder* builder, const char* composer)
```

**描述**

设置资源作曲者。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向元数据构造器的实例。 | 
| composer | 作曲者。 | 

**返回：**

函数返回值[AVMetadata_Result](#avmetadata_result)：

AVMETADATA_SUCCESS：函数执行成功。

AVMETADATA_ERROR_INVALID_PARAM：
1. 参数builder为nullptr。

2. 参数composer为nullptr。


### OH_AVMetadataBuilder_SetDescription()

```
AVMetadata_Result OH_AVMetadataBuilder_SetDescription(OH_AVMetadataBuilder* builder, const char* description)
```

**描述**

设置媒体描述信息。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向元数据构造器的实例。 | 
| description | 媒体描述信息。 | 

**返回：**

函数返回值[AVMetadata_Result](#avmetadata_result)：

AVMETADATA_SUCCESS：函数执行成功。

AVMETADATA_ERROR_INVALID_PARAM：

1. 参数builder为nullptr。

2. 参数description为nullptr。


### OH_AVMetadataBuilder_SetDisplayTags()

```
AVMetadata_Result OH_AVMetadataBuilder_SetDisplayTags(OH_AVMetadataBuilder* builder, int32_t tags)
```

**描述**

设置媒体资源的金标类型。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向元数据构造器的实例。 | 
| tags | 用于显示在播控的媒体资源的金标类型。 | 

**返回：**

函数返回值[AVMetadata_Result](#avmetadata_result)：

AVMETADATA_SUCCESS：函数执行成功。

AVMETADATA_ERROR_INVALID_PARAM：参数builder为nullptr。


### OH_AVMetadataBuilder_SetDuration()

```
AVMetadata_Result OH_AVMetadataBuilder_SetDuration(OH_AVMetadataBuilder* builder, int64_t duration)
```

**描述**

设置资源播放时长。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向元数据构造器的实例。 | 
| duration | 资源播放时长，以ms为单位。 | 

**返回：**

函数返回值[AVMetadata_Result](#avmetadata_result)：

AVMETADATA_SUCCESS：函数执行成功。

AVMETADATA_ERROR_INVALID_PARAM：参数builder为nullptr。


### OH_AVMetadataBuilder_SetLyric()

```
AVMetadata_Result OH_AVMetadataBuilder_SetLyric(OH_AVMetadataBuilder* builder, const char* lyric)
```

**描述**

设置歌词。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向元数据构造器的实例。 | 
| lyric | lrc格式的歌词内容。 | 

**返回：**

函数返回值[AVMetadata_Result](#avmetadata_result)：

AVMETADATA_SUCCESS：函数执行成功。

AVMETADATA_ERROR_INVALID_PARAM：

1. 参数builder为nullptr。

2. 参数lyric为nullptr。


### OH_AVMetadataBuilder_SetMediaImageUri()

```
AVMetadata_Result OH_AVMetadataBuilder_SetMediaImageUri(OH_AVMetadataBuilder* builder, const char* mediaImageUri)
```

**描述**

设置媒体图片数据。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向元数据构造器的实例。 | 
| mediaImageUri | 网络资源图片数据地址。 | 

**返回：**

函数返回值[AVMetadata_Result](#avmetadata_result)：

AVMETADATA_SUCCESS：函数执行成功。

AVMETADATA_ERROR_INVALID_PARAM：

1. 参数builder为nullptr。

2. 参数mediaImageUri为nullptr。


### OH_AVMetadataBuilder_SetSkipIntervals()

```
AVMetadata_Result OH_AVMetadataBuilder_SetSkipIntervals(OH_AVMetadataBuilder* builder, AVMetadata_SkipIntervals intervals)
```

**描述**

设置资源的跳转的间隔时间。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向元数据构造器的实例。 | 
| intervals | 跳转的时间间隔。 | 

**返回：**

函数返回值[AVMetadata_Result](#avmetadata_result)：

AVMETADATA_SUCCESS：函数执行成功。

AVMETADATA_ERROR_INVALID_PARAM：

1. 参数builder为nullptr。

2. 参数intervals为无效。


### OH_AVMetadataBuilder_SetSubtitle()

```
AVMetadata_Result OH_AVMetadataBuilder_SetSubtitle(OH_AVMetadataBuilder* builder, const char* subtitle)
```

**描述**

设置副标题。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向元数据构造器的实例。 | 
| subtitle | The subtitle of resource. | 

**返回：**

函数返回值[AVMetadata_Result](#avmetadata_result)：

AVMETADATA_SUCCESS：函数执行成功。

AVMETADATA_ERROR_INVALID_PARAM：

1. 参数builder为nullptr。

2. 参数subtitle为nullptr。


### OH_AVMetadataBuilder_SetTitle()

```
AVMetadata_Result OH_AVMetadataBuilder_SetTitle(OH_AVMetadataBuilder* builder, const char* title)
```

**描述**

设置资源标题。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向元数据构造器的实例。 | 
| title | 标题。 | 

**返回：**

函数返回值[AVMetadata_Result](#avmetadata_result)：

AVMETADATA_SUCCESS：函数执行成功。

AVMETADATA_ERROR_INVALID_PARAM：
1. 参数builder为nullptr。

2. 参数title为nullptr。


### OH_AVMetadataBuilder_SetWriter()

```
AVMetadata_Result OH_AVMetadataBuilder_SetWriter(OH_AVMetadataBuilder* builder, const char* writer)
```

**描述**

设置资源词作者。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向元数据构造器的实例。 | 
| writer | 词作者。 | 

**返回：**

函数返回值[AVMetadata_Result](#avmetadata_result)：

AVMETADATA_SUCCESS：函数执行成功。

AVMETADATA_ERROR_INVALID_PARAM：
1. 参数builder为nullptr。

2. 参数writer为nullptr。


### OH_AVSession_Activate()

```
AVSession_ErrCode OH_AVSession_Activate(OH_AVSession* avsession)
```

**描述**

激活会话。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| avsession | 媒体会话对象。 | 

**返回：**

函数返回值[AVSession_ErrCode](#avsession_errcode)：

AV_SESSION_ERR_SUCCESS：函数执行成功。

AV_SESSION_ERR_INVALID_PARAMETER：参数avsession为nullptr。

AV_SESSION_ERR_SERVICE_EXCEPTION：会话服务异常。


### OH_AVSession_Create()

```
AVSession_ErrCode OH_AVSession_Create(AVSession_Type sessionType, const char* sessionTag, const char* bundleName, const char* abilityName, OH_AVSession** avsession)
```

**描述**

创建会话对象。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| sessionType | 会话类型[AVSession_Type](#avsession_type)。 | 
| sessionTag | 会话标签。 | 
| bundleName | 创建会话的包名。 | 
| abilityName | 创建会话的ability名。 | 
| avsession | 返回的媒体会话对象。 | 

**返回：**

函数返回值[AVSession_ErrCode](#avsession_errcode)：

AV_SESSION_ERR_SUCCESS：函数执行成功。

AV_SESSION_ERR_SERVICE_EXCEPTION：会话服务异常或session重复创建。

AV_SESSION_ERR_INVALID_PARAMETER：

1. 参数sessionType无效。

2. 参数sessionTag为nullptr。

3. 参数bundleName为nullptr。

4. 参数abilityName为nullptr。

5. 参数avsession为nullptr。


### OH_AVSession_Deactivate()

```
AVSession_ErrCode OH_AVSession_Deactivate(OH_AVSession* avsession)
```

**描述**

取消激活媒体会话。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| avsession | 媒体会话对象。 | 

**返回：**

函数返回值[AVSession_ErrCode](#avsession_errcode)：

AV_SESSION_ERR_SUCCESS：函数执行成功。

AV_SESSION_ERR_INVALID_PARAMETER：参数avsession为nullptr。

AV_SESSION_ERR_SERVICE_EXCEPTION：会话服务异常。


### OH_AVSession_Destroy()

```
AVSession_ErrCode OH_AVSession_Destroy(OH_AVSession* avsession)
```

**描述**

销毁会话对象。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| avsession | 媒体会话对象。 | 

**返回：**

函数返回值[AVSession_ErrCode](#avsession_errcode)：

AV_SESSION_ERR_SUCCESS：函数执行成功。

AV_SESSION_ERR_INVALID_PARAMETER：参数avsession为nullptr。


### OH_AVSession_GetSessionId()

```
AVSession_ErrCode OH_AVSession_GetSessionId(OH_AVSession* avsession, const char** sessionId)
```

**描述**

获取会话id。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| avsession | 媒体会话对象。 | 
| sessionId | 返回的会话类型id。 | 

**返回：**

函数返回值[AVSession_ErrCode](#avsession_errcode)：

AV_SESSION_ERR_SUCCESS：函数执行成功。

AV_SESSION_ERR_SERVICE_EXCEPTION：会话服务异常，获取session Id错误。

AV_SESSION_ERR_INVALID_PARAMETER：

1. 参数avsession为nullptr。

2. 参数sessionId为nullptr。


### OH_AVSession_GetSessionType()

```
AVSession_ErrCode OH_AVSession_GetSessionType(OH_AVSession* avsession, AVSession_Type* sessionType)
```

**描述**

获取会话类型。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| avsession | 媒体会话对象。 | 
| sessionType | 返回的会话类型。 | 

**返回：**

函数返回值[AVSession_ErrCode](#avsession_errcode)：

AV_SESSION_ERR_SUCCESS：函数执行成功。

AV_SESSION_ERR_SERVICE_EXCEPTION：会话服务异常，获取session type错误。

AV_SESSION_ERR_INVALID_PARAMETER：

1. 参数avsession为nullptr。

2. 参数sessionType为nullptr。


### OH_AVSession_RegisterCommandCallback()

```
AVSession_ErrCode OH_AVSession_RegisterCommandCallback(OH_AVSession* avsession, AVSession_ControlCommand command, OH_AVSessionCallback_OnCommand callback, void* userData)
```

**描述**

注册通用播控的回调。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| avsession | 媒体会话对象。 | 
| command | 播控的控制命令。 | 
| callback | 控制命令的回调[OH_AVSessionCallback_OnCommand](#oh_avsessioncallback_oncommand)。 | 
| userData | 指向通过回调函数传递的应用数据指针。 | 

**返回：**

函数返回值[AVSession_ErrCode](#avsession_errcode)：

AV_SESSION_ERR_SUCCESS：函数执行成功。

AV_SESSION_ERR_CODE_COMMAND_INVALID：控制命令无效。

AV_SESSION_ERR_SERVICE_EXCEPTION：会话服务异常。

AV_SESSION_ERR_INVALID_PARAMETER：

1. 参数avsession为nullptr。

2. 参数callback为nullptr。


### OH_AVSession_RegisterForwardCallback()

```
AVSession_ErrCode OH_AVSession_RegisterForwardCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnFastForward callback, void* userData)
```

**描述**

注册快进的回调。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| avsession | 媒体会话对象。 | 
| callback | 快进命令的回调[OH_AVSessionCallback_OnFastForward](#oh_avsessioncallback_onfastforward)。 | 
| userData | 指向通过回调函数传递的应用数据指针。 | 

**返回：**

函数返回值[AVSession_ErrCode](#avsession_errcode)：

AV_SESSION_ERR_SUCCESS：函数执行成功。

AV_SESSION_ERR_SERVICE_EXCEPTION：会话服务异常。

AV_SESSION_ERR_INVALID_PARAMETER：

1. 参数avsession为nullptr。

2. 参数callback为nullptr。


### OH_AVSession_RegisterRewindCallback()

```
AVSession_ErrCode OH_AVSession_RegisterRewindCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnRewind callback, void* userData)
```

**描述**

注册快退的回调。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| avsession | 媒体会话对象。 | 
| callback | 快退命令的回调[OH_AVSessionCallback_OnRewind](#oh_avsessioncallback_onrewind)。 | 
| userData | 指向通过回调函数传递的应用数据指针。 | 

**返回：**

函数返回值[AVSession_ErrCode](#avsession_errcode)：

AV_SESSION_ERR_SUCCESS：函数执行成功。

AV_SESSION_ERR_SERVICE_EXCEPTION：会话服务异常。

AV_SESSION_ERR_INVALID_PARAMETER：

1. 参数avsession为nullptr。

2. 参数callback为nullptr。


### OH_AVSession_RegisterSeekCallback()

```
AVSession_ErrCode OH_AVSession_RegisterSeekCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnSeek callback, void* userData)
```

**描述**

注册跳转的回调。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| avsession | 媒体会话对象。 | 
| callback | 跳转命令的回调[OH_AVSessionCallback_OnSeek](#oh_avsessioncallback_onseek)。 | 
| userData | 指向通过回调函数传递的应用数据指针。 | 

**返回：**

函数返回值[AVSession_ErrCode](#avsession_errcode)：

AV_SESSION_ERR_SUCCESS：函数执行成功。

AV_SESSION_ERR_SERVICE_EXCEPTION：会话服务异常。

AV_SESSION_ERR_INVALID_PARAMETER：

1. 参数avsession为nullptr。

2. 参数callback为nullptr。


### OH_AVSession_RegisterSetLoopModeCallback()

```
AVSession_ErrCode OH_AVSession_RegisterSetLoopModeCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnSetLoopMode callback, void* userData)
```

**描述**

注册设置循环模式的回调。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| avsession | 媒体会话对象。 | 
| callback | 设置循环模式命令的回调[OH_AVSessionCallback_OnSetLoopMode](#oh_avsessioncallback_onsetloopmode)。 | 
| userData | 指向通过回调函数传递的应用数据指针。 | 

**返回：**

函数返回值[AVSession_ErrCode](#avsession_errcode)：

AV_SESSION_ERR_SUCCESS：函数执行成功。

AV_SESSION_ERR_SERVICE_EXCEPTION：会话服务异常。

AV_SESSION_ERR_INVALID_PARAMETER：

1. 参数avsession为nullptr。

2. 参数callback为nullptr。


### OH_AVSession_RegisterToggleFavoriteCallback()

```
AVSession_ErrCode OH_AVSession_RegisterToggleFavoriteCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnToggleFavorite callback, void* userData)
```

**描述**

设置收藏的回调。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| avsession | 媒体会话对象。 | 
| callback | 设置收藏命令的回调[OH_AVSessionCallback_OnToggleFavorite](#oh_avsessioncallback_ontogglefavorite)。 | 
| userData | 指向通过回调函数传递的应用数据指针。 | 

**返回：**

函数返回值[AVSession_ErrCode](#avsession_errcode)：

AV_SESSION_ERR_SUCCESS：函数执行成功。

AV_SESSION_ERR_SERVICE_EXCEPTION：会话服务异常。

AV_SESSION_ERR_INVALID_PARAMETER：

1. 参数avsession为nullptr。

2. 参数callback为nullptr。


### OH_AVSession_SetAVMetadata()

```
AVSession_ErrCode OH_AVSession_SetAVMetadata(OH_AVSession* avsession, OH_AVMetadata* avmetadata)
```

**描述**

设置媒体元数据。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| avsession | 媒体会话对象。 | 
| avmetadata | 设置媒体元数据信息。 | 

**返回：**

函数返回值[AVSession_ErrCode](#avsession_errcode)：

AV_SESSION_ERR_SUCCESS：函数执行成功。

AV_SESSION_ERR_SERVICE_EXCEPTION：会话服务异常。

AV_SESSION_ERR_INVALID_PARAMETER：

1. 参数avsession为nullptr。

2. 参数avmetadata为nullptr。


### OH_AVSession_SetFavorite()

```
AVSession_ErrCode OH_AVSession_SetFavorite(OH_AVSession* avsession, bool favorite)
```

**描述**

设置收藏状态。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| avsession | 媒体会话对象。 | 
| favorite | 收藏状态，true表示收藏，false表示取消收藏。 | 

**返回：**

函数返回值[AVSession_ErrCode](#avsession_errcode)：

AV_SESSION_ERR_SUCCESS：函数执行成功。

AV_SESSION_ERR_SERVICE_EXCEPTION：会话服务异常。

AV_SESSION_ERR_INVALID_PARAMETER：参数avsession为nullptr。


### OH_AVSession_SetLoopMode()

```
AVSession_ErrCode OH_AVSession_SetLoopMode(OH_AVSession* avsession, AVSession_LoopMode loopMode)
```

**描述**

设置循环模式。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| avsession | 媒体会话对象。 | 
| loopMode | 循环模式。 | 

**返回：**

函数返回值[AVSession_ErrCode](#avsession_errcode)：

AV_SESSION_ERR_SUCCESS：函数执行成功。

AV_SESSION_ERR_SERVICE_EXCEPTION：会话服务异常。

AV_SESSION_ERR_INVALID_PARAMETER：

1. 参数avsession为nullptr。

2. 参数loopMode无效。


### OH_AVSession_SetPlaybackPosition()

```
AVSession_ErrCode OH_AVSession_SetPlaybackPosition(OH_AVSession* avsession, AVSession_PlaybackPosition* playbackPosition)
```

**描述**

设置播放位置。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| avsession | 媒体会话对象。 | 
| playbackPosition | 播放位置对象。 | 

**返回：**

函数返回值[AVSession_ErrCode](#avsession_errcode)：

AV_SESSION_ERR_SUCCESS：函数执行成功。

AV_SESSION_ERR_SERVICE_EXCEPTION：会话服务异常。

AV_SESSION_ERR_INVALID_PARAMETER：

1. 参数avsession为nullptr。

2. 参数playbackPosition为nullptr。


### OH_AVSession_SetPlaybackState()

```
AVSession_ErrCode OH_AVSession_SetPlaybackState(OH_AVSession* avsession, AVSession_PlaybackState playbackState)
```

**描述**

设置播放状态。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| avsession | 媒体会话对象。 | 
| playbackState | 播放状态。 | 

**返回：**

函数返回值[AVSession_ErrCode](#avsession_errcode)：

AV_SESSION_ERR_SUCCESS：函数执行成功。

AV_SESSION_ERR_SERVICE_EXCEPTION：会话服务异常。

AV_SESSION_ERR_INVALID_PARAMETER：

1. 参数avsession为nullptr。

2. 参数playbackState无效。


### OH_AVSession_UnregisterCommandCallback()

```
AVSession_ErrCode OH_AVSession_UnregisterCommandCallback(OH_AVSession* avsession, AVSession_ControlCommand command, OH_AVSessionCallback_OnCommand callback)
```

**描述**

取消注册通用播控的回调。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| avsession | 媒体会话对象。 | 
| command | 播控的控制命令。 | 
| callback | 控制命令的回调[OH_AVSessionCallback_OnCommand](#oh_avsessioncallback_oncommand)。 | 

**返回：**

函数返回值[AVSession_ErrCode](#avsession_errcode)：

AV_SESSION_ERR_SUCCESS：函数执行成功。

AV_SESSION_ERR_CODE_COMMAND_INVALID：控制命令无效。

AV_SESSION_ERR_SERVICE_EXCEPTION：会话服务异常。

AV_SESSION_ERR_INVALID_PARAMETER：

1. 参数avsession为nullptr。

2. 参数callback为nullptr。


### OH_AVSession_UnregisterForwardCallback()

```
AVSession_ErrCode OH_AVSession_UnregisterForwardCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnFastForward callback)
```

**描述**

取消注册快进的回调。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| avsession | 媒体会话对象。 | 
| callback | 快进命令的回调[OH_AVSessionCallback_OnFastForward](#oh_avsessioncallback_onfastforward)。 | 

**返回：**

函数返回值[AVSession_ErrCode](#avsession_errcode)：

AV_SESSION_ERR_SUCCESS：函数执行成功。

AV_SESSION_ERR_SERVICE_EXCEPTION：会话服务异常。

AV_SESSION_ERR_INVALID_PARAMETER：

1. 参数avsession为nullptr。

2. 参数callback为nullptr。


### OH_AVSession_UnregisterRewindCallback()

```
AVSession_ErrCode OH_AVSession_UnregisterRewindCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnRewind callback)
```

**描述**

取消注册快退的回调。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| avsession | 媒体会话对象。 | 
| callback | 快退命令的回调[OH_AVSessionCallback_OnRewind](#oh_avsessioncallback_onrewind)。 | 

**返回：**

函数返回值[AVSession_ErrCode](#avsession_errcode)：

AV_SESSION_ERR_SUCCESS：函数执行成功。

AV_SESSION_ERR_SERVICE_EXCEPTION：会话服务异常。

AV_SESSION_ERR_INVALID_PARAMETER：

1. 参数avsession为nullptr。

2. 参数callback为nullptr。


### OH_AVSession_UnregisterSeekCallback()

```
AVSession_ErrCode OH_AVSession_UnregisterSeekCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnSeek callback)
```

**描述**

取消注册跳转的回调。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| avsession | 媒体会话对象。 | 
| callback | 跳转命令的回调[OH_AVSessionCallback_OnSeek](#oh_avsessioncallback_onseek)。 | 

**返回：**

函数返回值[AVSession_ErrCode](#avsession_errcode)：

AV_SESSION_ERR_SUCCESS：函数执行成功。

AV_SESSION_ERR_SERVICE_EXCEPTION：会话服务异常。

AV_SESSION_ERR_INVALID_PARAMETER：

1. 参数avsession为nullptr。

2. 参数callback为nullptr。


### OH_AVSession_UnregisterSetLoopModeCallback()

```
AVSession_ErrCode OH_AVSession_UnregisterSetLoopModeCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnSetLoopMode callback)
```

**描述**

取消注册设置循环模式的回调。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| avsession | 媒体会话对象。 | 
| callback | 设置循环模式命令的回调[OH_AVSessionCallback_OnSetLoopMode](#oh_avsessioncallback_onsetloopmode)。 | 

**返回：**

函数返回值[AVSession_ErrCode](#avsession_errcode)：

AV_SESSION_ERR_SUCCESS：函数执行成功。

AV_SESSION_ERR_SERVICE_EXCEPTION：会话服务异常。

AV_SESSION_ERR_INVALID_PARAMETER：

1. 参数avsession为nullptr。

2. 参数callback为nullptr。


### OH_AVSession_UnregisterToggleFavoriteCallback()

```
AVSession_ErrCode OH_AVSession_UnregisterToggleFavoriteCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnToggleFavorite callback)
```

**描述**

取消设置收藏的回调。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| avsession | 媒体会话对象。 | 
| callback | 设置收藏命令的回调[OH_AVSessionCallback_OnToggleFavorite](#oh_avsessioncallback_ontogglefavorite)。 | 

**返回：**

函数返回值[AVSession_ErrCode](#avsession_errcode)：

AV_SESSION_ERR_SUCCESS：函数执行成功。

AV_SESSION_ERR_SERVICE_EXCEPTION：会话服务异常。

AV_SESSION_ERR_INVALID_PARAMETER：

1. 参数avsession为nullptr。

2. 参数callback为nullptr。
