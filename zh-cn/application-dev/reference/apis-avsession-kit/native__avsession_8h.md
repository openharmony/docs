# native_avsession.h


## 概述

媒体会话定义，可用于设置元数据、播放状态信息等操作。

**库：** libohavsession.so

**引用文件：** &lt;multimedia/av_session/native_avsession.h&gt;

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**起始版本：** 13

**相关模块：**[OHAVSession](_o_h_a_v_session.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [AVSession_PlaybackPosition](_a_v_session___playback_position.md) | 媒体播放位置的相关属性。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [AVSession_PlaybackPosition](_a_v_session___playback_position.md) [AVSession_PlaybackPosition](_o_h_a_v_session.md#avsession_playbackposition) | 媒体播放位置的相关属性。 | 
| typedef enum [AVSession_ControlCommand](_o_h_a_v_session.md#avsession_controlcommand) [AVSession_ControlCommand](_o_h_a_v_session.md#avsession_controlcommand) | 播控命令。 | 
| typedef [AVSessionCallback_Result](_o_h_a_v_session.md#avsessioncallback_result)(\* [OH_AVSessionCallback_OnCommand](_o_h_a_v_session.md#oh_avsessioncallback_oncommand)) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*session, [AVSession_ControlCommand](_o_h_a_v_session.md#avsession_controlcommand) command, void \*userData) | 通用的执行播控命令的回调。 | 
| typedef [AVSessionCallback_Result](_o_h_a_v_session.md#avsessioncallback_result)(\* [OH_AVSessionCallback_OnFastForward](_o_h_a_v_session.md#oh_avsessioncallback_onfastforward)) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*session, uint32_t seekTime, void \*userData) | 快进的回调。 | 
| typedef [AVSessionCallback_Result](_o_h_a_v_session.md#avsessioncallback_result)(\* [OH_AVSessionCallback_OnRewind](_o_h_a_v_session.md#oh_avsessioncallback_onrewind)) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*session, uint32_t seekTime, void \*userData) | 快退的回调。 | 
| typedef [AVSessionCallback_Result](_o_h_a_v_session.md#avsessioncallback_result)(\* [OH_AVSessionCallback_OnSeek](_o_h_a_v_session.md#oh_avsessioncallback_onseek)) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*session, uint64_t seekTime, void \*userData) | 进度调节的回调。 | 
| typedef [AVSessionCallback_Result](_o_h_a_v_session.md#avsessioncallback_result)(\* [OH_AVSessionCallback_OnSetLoopMode](_o_h_a_v_session.md#oh_avsessioncallback_onsetloopmode)) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*session, [AVSession_LoopMode](_o_h_a_v_session.md#avsession_loopmode) curLoopMode, void \*userData) | 设置循环模式的回调。 | 
| typedef [AVSessionCallback_Result](_o_h_a_v_session.md#avsessioncallback_result)(\* [OH_AVSessionCallback_OnToggleFavorite](_o_h_a_v_session.md#oh_avsessioncallback_ontogglefavorite)) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*session, const char \*assetId, void \*userData) | 收藏的回调。 | 
| typedef struct [OH_AVSession](_o_h_a_v_session.md#oh_avsession) [OH_AVSession](_o_h_a_v_session.md#oh_avsession) | 播控会话对象定义。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [AVSession_Type](_o_h_a_v_session.md#avsession_type) {<br/>SESSION_TYPE_AUDIO = 0,<br/>SESSION_TYPE_VIDEO = 1,<br/>SESSION_TYPE_VOICE_CALL = 2,<br/>SESSION_TYPE_VIDEO_CALL = 3 } | 会话类型。 | 
| [AVSession_PlaybackState](_o_h_a_v_session.md#avsession_playbackstate) {<br/>PLAYBACK_STATE_INITIAL = 0,<br/>PLAYBACK_STATE_PREPARING = 1,<br/>PLAYBACK_STATE_PLAYING = 2,<br/>PLAYBACK_STATE_PAUSED = 3,<br/>PLAYBACK_STATE_FAST_FORWARDING = 4,<br/>PLAYBACK_STATE_REWINDED = 5,<br/>PLAYBACK_STATE_STOPPED = 6,<br/>PLAYBACK_STATE_COMPLETED = 7,<br/>PLAYBACK_STATE_RELEASED = 8,<br/>PLAYBACK_STATE_ERROR = 9,<br/>PLAYBACK_STATE_IDLE = 10,<br/>PLAYBACK_STATE_BUFFERING = 11,<br/>PLAYBACK_STATE_MAX = 12<br/>} | 媒体播放状态的相关属性。 | 
| [AVSession_LoopMode](_o_h_a_v_session.md#avsession_loopmode) {<br/>LOOP_MODE_SEQUENCE = 0,<br/>LOOP_MODE_SINGLE = 1,<br/>LOOP_MODE_LIST = 2,<br/>LOOP_MODE_SHUFFLE = 3,<br/>LOOP_MODE_CUSTOM = 4<br/>} | 媒体播放循环模式。 | 
| [AVSession_ControlCommand](_o_h_a_v_session.md#avsession_controlcommand) {<br/>CONTROL_CMD_INVALID = -1,<br/>CONTROL_CMD_PLAY = 0,<br/>CONTROL_CMD_PAUSE = 1,<br/>CONTROL_CMD_STOP = 2,<br/>CONTROL_CMD_PLAY_NEXT = 3,<br/>CONTROL_CMD_PLAY_PREVIOUS = 4<br/>} | 播控命令。 | 
| [AVSessionCallback_Result](_o_h_a_v_session.md#avsessioncallback_result) {<br/>AVSESSION_CALLBACK_RESULT_SUCCESS = 0,<br/>AVSESSION_CALLBACK_RESULT_FAILURE = -1 } | 回调执行的结果。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_Create](_o_h_a_v_session.md#oh_avsession_create) ([AVSession_Type](_o_h_a_v_session.md#avsession_type) sessionType, const char \*sessionTag, const char \*bundleName, const char \*abilityName, [OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*\*avsession) | 创建会话对象。 | 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_Destroy](_o_h_a_v_session.md#oh_avsession_destroy) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession) | 销毁会话对象。 | 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_Activate](_o_h_a_v_session.md#oh_avsession_activate) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession) | 激活会话。 | 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_Deactivate](_o_h_a_v_session.md#oh_avsession_deactivate) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession) | 取消激活媒体会话。 | 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_GetSessionType](_o_h_a_v_session.md#oh_avsession_getsessiontype) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [AVSession_Type](_o_h_a_v_session.md#avsession_type) \*sessionType) | 获取会话类型。 | 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_GetSessionId](_o_h_a_v_session.md#oh_avsession_getsessionid) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, const char \*\*sessionId) | 获取会话id。 | 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_SetAVMetadata](_o_h_a_v_session.md#oh_avsession_setavmetadata) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [OH_AVMetadata](_o_h_a_v_session.md#oh_avmetadata) \*avmetadata) | 设置媒体元数据。 | 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_SetPlaybackState](_o_h_a_v_session.md#oh_avsession_setplaybackstate) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [AVSession_PlaybackState](_o_h_a_v_session.md#avsession_playbackstate) playbackState) | 设置播放状态。 | 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_SetPlaybackPosition](_o_h_a_v_session.md#oh_avsession_setplaybackposition) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [AVSession_PlaybackPosition](_a_v_session___playback_position.md) \*playbackPosition) | 设置播放位置。 | 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_SetFavorite](_o_h_a_v_session.md#oh_avsession_setfavorite) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, bool favorite) | 设置收藏状态。 | 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_SetLoopMode](_o_h_a_v_session.md#oh_avsession_setloopmode) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [AVSession_LoopMode](_o_h_a_v_session.md#avsession_loopmode) loopMode) | 设置循环模式。 | 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_RegisterCommandCallback](_o_h_a_v_session.md#oh_avsession_registercommandcallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [AVSession_ControlCommand](_o_h_a_v_session.md#avsession_controlcommand) command, [OH_AVSessionCallback_OnCommand](_o_h_a_v_session.md#oh_avsessioncallback_oncommand) callback, void \*userData) | 注册通用播控的回调。 | 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_UnregisterCommandCallback](_o_h_a_v_session.md#oh_avsession_unregistercommandcallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [AVSession_ControlCommand](_o_h_a_v_session.md#avsession_controlcommand) command, [OH_AVSessionCallback_OnCommand](_o_h_a_v_session.md#oh_avsessioncallback_oncommand) callback) | 取消注册通用播控的回调。 | 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_RegisterForwardCallback](_o_h_a_v_session.md#oh_avsession_registerforwardcallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [OH_AVSessionCallback_OnFastForward](_o_h_a_v_session.md#oh_avsessioncallback_onfastforward) callback, void \*userData) | 注册快进的回调。 | 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_UnregisterForwardCallback](_o_h_a_v_session.md#oh_avsession_unregisterforwardcallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [OH_AVSessionCallback_OnFastForward](_o_h_a_v_session.md#oh_avsessioncallback_onfastforward) callback) | 取消注册快进的回调。 | 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_RegisterRewindCallback](_o_h_a_v_session.md#oh_avsession_registerrewindcallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [OH_AVSessionCallback_OnRewind](_o_h_a_v_session.md#oh_avsessioncallback_onrewind) callback, void \*userData) | 注册快退的回调。 | 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_UnregisterRewindCallback](_o_h_a_v_session.md#oh_avsession_unregisterrewindcallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [OH_AVSessionCallback_OnRewind](_o_h_a_v_session.md#oh_avsessioncallback_onrewind) callback) | 取消注册快退的回调。 | 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_RegisterSeekCallback](_o_h_a_v_session.md#oh_avsession_registerseekcallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [OH_AVSessionCallback_OnSeek](_o_h_a_v_session.md#oh_avsessioncallback_onseek) callback, void \*userData) | 注册跳转的回调。 | 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_UnregisterSeekCallback](_o_h_a_v_session.md#oh_avsession_unregisterseekcallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [OH_AVSessionCallback_OnSeek](_o_h_a_v_session.md#oh_avsessioncallback_onseek) callback) | 取消注册跳转的回调。 | 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_RegisterSetLoopModeCallback](_o_h_a_v_session.md#oh_avsession_registersetloopmodecallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [OH_AVSessionCallback_OnSetLoopMode](_o_h_a_v_session.md#oh_avsessioncallback_onsetloopmode) callback, void \*userData) | 注册设置循环模式的回调。 | 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_UnregisterSetLoopModeCallback](_o_h_a_v_session.md#oh_avsession_unregistersetloopmodecallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [OH_AVSessionCallback_OnSetLoopMode](_o_h_a_v_session.md#oh_avsessioncallback_onsetloopmode) callback) | 取消注册设置循环模式的回调。 | 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_RegisterToggleFavoriteCallback](_o_h_a_v_session.md#oh_avsession_registertogglefavoritecallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [OH_AVSessionCallback_OnToggleFavorite](_o_h_a_v_session.md#oh_avsessioncallback_ontogglefavorite) callback, void \*userData) | 设置收藏的回调。 | 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_UnregisterToggleFavoriteCallback](_o_h_a_v_session.md#oh_avsession_unregistertogglefavoritecallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [OH_AVSessionCallback_OnToggleFavorite](_o_h_a_v_session.md#oh_avsessioncallback_ontogglefavorite) callback) | 取消设置收藏的回调。 | 
