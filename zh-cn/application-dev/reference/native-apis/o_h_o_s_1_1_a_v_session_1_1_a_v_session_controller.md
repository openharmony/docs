# OHOS::AVSession::AVSessionController


## 概述

控制器对象，可获取会话的播放状态和会话元数据，远程发送控制命令到会话端也可以通过订阅监听会话段的更新事件。


## 汇总


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [GetAVPlaybackState](#getavplaybackstate)&nbsp;([AVPlaybackState](_o_h_o_s_1_1_a_v_session_1_1_a_v_playback_state.md)&nbsp;&amp;state)=0 | 获取音视频的播放状态。&nbsp; | 
| [GetAVMetaData](#getavmetadata)&nbsp;([AVMetaData](_o_h_o_s_1_1_a_v_session_1_1_a_v_meta_data.md)&nbsp;&amp;data)=0 | 获取会话元数据。&nbsp; | 
| [SendAVKeyEvent](#sendavkeyevent)&nbsp;(const&nbsp;MMI::KeyEvent&nbsp;&amp;keyEvent)=0 | 发送系统按键事件。&nbsp; | 
| [GetLaunchAbility](#getlaunchability)&nbsp;(AbilityRuntime::WantAgent::WantAgent&nbsp;&amp;ability)=0 | 获取Ability。&nbsp; | 
| [GetValidCommands](#getvalidcommands)&nbsp;(std::vector&lt;&nbsp;int32_t&nbsp;&gt;&nbsp;&amp;cmds)=0 | 获取媒体有效的指令。&nbsp; | 
| [IsSessionActive](#issessionactive)&nbsp;(bool&nbsp;&amp;isActive)=0 | 获取session的激活状态。&nbsp; | 
| [SendControlCommand](#sendcontrolcommand)&nbsp;(const&nbsp;[AVControlCommand](_o_h_o_s_1_1_a_v_session_1_1_a_v_control_command.md)&nbsp;&amp;cmd)=0 | 发送媒体控制指令。&nbsp; | 
| [RegisterCallback](#registercallback)&nbsp;(const&nbsp;std::shared_ptr&lt;&nbsp;[AVControllerCallback](_h_o_s_1_1_a_v_session_1_1_a_v_controller_callback.md)&nbsp;&gt;&nbsp;&amp;callback)=0 | 注册回调。&nbsp; | 
| [SetMetaFilter](#setmetafilter)&nbsp;(const&nbsp;[AVMetaData::MetaMaskType](_o_h_o_s_1_1_a_v_session_1_1_a_v_meta_data.md#metamasktype)&nbsp;&amp;filter)=0 | 设置会话元数据过滤。&nbsp; | 
| [SetPlaybackFilter](#setplaybackfilter)&nbsp;(const&nbsp;AVPlaybackState::PlaybackStateMaskType&nbsp;&amp;filter)=0 | 设置音视频的播放状态回调过滤。&nbsp; | 
| [Destroy](#destroy)&nbsp;()=0 | 释放控制器。&nbsp; | 
| [GetSessionId](#getsessionid)&nbsp;()=0 | 获取sessionId。&nbsp; | 
| [GetRealPlaybackPosition](#getrealplaybackposition)&nbsp;()=0 | 获取播放的实时位置，第&nbsp;x&nbsp;ms。&nbsp; | 
| [IsDestroy](#isdestroy)&nbsp;()=0 | 是否释放控制器。&nbsp; | 


## 成员函数说明


### Destroy()

  
```
virtual int32_t OHOS::AVSession::AVSessionController::Destroy ()
```
**描述:**
释放控制器。

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。


### GetAVMetaData()

  
```
virtual int32_t OHOS::AVSession::AVSessionController::GetAVMetaData (AVMetaData & data)
```
**描述:**
获取会话元数据。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| data | 会话元数据[AVMetaData](_o_h_o_s_1_1_a_v_session_1_1_a_v_meta_data.md)。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。

**参见:**

[AVSession::SetAVMetaData](_o_h_o_s_1_1_a_v_session_1_1_a_v_session.md#setavmetadata)

[AVSession::GetAVMetaData](_o_h_o_s_1_1_a_v_session_1_1_a_v_session.md#getavmetadata)


### GetAVPlaybackState()

  
```
virtual int32_t OHOS::AVSession::AVSessionController::GetAVPlaybackState (AVPlaybackState & state)
```
**描述:**
获取音视频的播放状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| state | 音视频的播放状态[AVPlaybackState](_o_h_o_s_1_1_a_v_session_1_1_a_v_playback_state.md)。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。

**参见:**

[AVSession::SetAVPlaybackState](_o_h_o_s_1_1_a_v_session_1_1_a_v_session.md#setavplaybackstate)

[AVSession::GetAVPlaybackState](_o_h_o_s_1_1_a_v_session_1_1_a_v_session.md#getavplaybackstate)


### GetLaunchAbility()

  
```
virtual int32_t OHOS::AVSession::AVSessionController::GetLaunchAbility (AbilityRuntime::WantAgent::WantAgent & ability)
```
**描述:**
获取Ability。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| ability | 类型为**AbilityRuntime::WantAgent::WantAgent**。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。

**参见:**

[AVSession::SetLaunchAbility](_o_h_o_s_1_1_a_v_session_1_1_a_v_session.md#setlaunchability)


### GetRealPlaybackPosition()

  
```
virtual int64_t OHOS::AVSession::AVSessionController::GetRealPlaybackPosition ()
```
**描述:**
获取播放的实时位置，第 x ms。

**返回:**

返回播放的实时位置，第x ms，经过校正过的时间，单位为ms。


### GetSessionId()

  
```
virtual std::string OHOS::AVSession::AVSessionController::GetSessionId ()
```
**描述:**
获取sessionId。

**返回:**

返回sessionId。


### GetValidCommands()

  
```
virtual int32_t OHOS::AVSession::AVSessionController::GetValidCommands (std::vector< int32_t > & cmds)
```
**描述:**
获取媒体有效的指令。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| cmds | 媒体有效的指令列表，范围为**SESSION_CMD_INVALID**到**SESSION_CMD_MAX**。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。

**参见:**

[SendControlCommand](#sendcontrolcommand)

[AVSession::AddSupportCommand](_o_h_o_s_1_1_a_v_session_1_1_a_v_session.md#addsupportcommand)

[AVSession::DeleteSupportCommand](_o_h_o_s_1_1_a_v_session_1_1_a_v_session.md#deletesupportcommand)


### IsDestroy()

  
```
virtual bool OHOS::AVSession::AVSessionController::IsDestroy ()
```
**描述:**
是否释放控制器。

**返回:**

true：释放；false：不释放。


### IsSessionActive()

  
```
virtual int32_t OHOS::AVSession::AVSessionController::IsSessionActive (bool & isActive)
```
**描述:**
获取session的激活状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| isActive | session是否激活。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。

**参见:**

[AVSession::Activate](_o_h_o_s_1_1_a_v_session_1_1_a_v_session.md#activate)

[AVSession::Deactivate](_o_h_o_s_1_1_a_v_session_1_1_a_v_session.md#deactivate)

[AVSession::IsActive](_o_h_o_s_1_1_a_v_session_1_1_a_v_session.md#isactive)


### RegisterCallback()

  
```
virtual int32_t OHOS::AVSession::AVSessionController::RegisterCallback (const std::shared_ptr< AVControllerCallback > & callback)
```
**描述:**
注册回调。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| callback | 需要注册的回调，类型为[AVControllerCallback](_h_o_s_1_1_a_v_session_1_1_a_v_controller_callback.md)。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。


### SendAVKeyEvent()

  
```
virtual int32_t OHOS::AVSession::AVSessionController::SendAVKeyEvent (const MMI::KeyEvent & keyEvent)
```
**描述:**
发送系统按键事件。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| keyEvent | 按键事件码，类型为**MMI::KeyEvent**。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。

**参见:**

[AVSessionManager::SendSystemAVKeyEvent](_o_h_o_s_1_1_a_v_session_1_1_a_v_session_manager.md#sendsystemavkeyevent)


### SendControlCommand()

  
```
virtual int32_t OHOS::AVSession::AVSessionController::SendControlCommand (const AVControlCommand & cmd)
```
**描述:**
发送媒体控制指令。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| cmd | 媒体控制指令，类型为[AVControlCommand](_o_h_o_s_1_1_a_v_session_1_1_a_v_control_command.md)。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。

**参见:**

[GetValidCommands](#getvalidcommands)


### SetMetaFilter()

  
```
virtual int32_t OHOS::AVSession::AVSessionController::SetMetaFilter (const AVMetaData::MetaMaskType & filter)
```
**描述:**
设置会话元数据过滤。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| filter | 会话元数据过滤，类型为[AVMetaData#MetaMaskType](_o_h_o_s_1_1_a_v_session_1_1_a_v_meta_data.md#metamasktype)。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。


### SetPlaybackFilter()

  
```
virtual int32_t OHOS::AVSession::AVSessionController::SetPlaybackFilter (const AVPlaybackState::PlaybackStateMaskType & filter)
```
**描述:**
设置音视频的播放状态回调过滤。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| filter | 音视频播放状态回调过滤，类型为**AVPlaybackState\#PlaybackStateMaskType**。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。
