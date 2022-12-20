# OHOS::AVSession::AVSession


## 概述

会话对象，支持配置会话属性，并可主动更新播放状态和会话元数据。


## 汇总


### Public 类型

  | 名称 | 描述 | 
| -------- | -------- |
| { **SESSION_TYPE_INVALID** = -1, **SESSION_TYPE_AUDIO** = 0, **SESSION_TYPE_VIDEO** = 1 } | 会话类型的枚举。  | 


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [GetSessionId](#getsessionid) ()=0 | 获取会话的标识。  | 
| [GetAVMetaData](#getavmetadata) ([AVMetaData](_o_h_o_s_1_1_a_v_session_1_1_a_v_meta_data.md) &amp;meta)=0 | 获取会话元数据。  | 
| [SetAVMetaData](#setavmetadata) (const [AVMetaData](_o_h_o_s_1_1_a_v_session_1_1_a_v_meta_data.md) &amp;meta)=0 | 设置会话元数据。  | 
| [GetAVPlaybackState](#getavplaybackstate) ([AVPlaybackState](_o_h_o_s_1_1_a_v_session_1_1_a_v_playback_state.md) &amp;state)=0 | 获取音视频的播放状态。  | 
| [SetAVPlaybackState](#setavplaybackstate) (const [AVPlaybackState](_o_h_o_s_1_1_a_v_session_1_1_a_v_playback_state.md) &amp;state)=0 | 设置音视频的播放状态。  | 
| [SetLaunchAbility](#setlaunchability) (const AbilityRuntime::WantAgent::WantAgent &amp;ability)=0 | 设置一个WantAgent用于启动会话的Ability。  | 
| [GetController](#getcontroller) ()=0 | 获取会话控制器。  | 
| [RegisterCallback](#registercallback) (const std::shared_ptr&lt; [AVSessionCallback](_o_h_o_s_1_1_a_v_session_1_1_a_v_session_callback.md) &gt; &amp;callback)=0 | 注册会话回调。  | 
| [Activate](#activate) ()=0 | 激活会话。  | 
| [Deactivate](#deactivate) ()=0 | 去激活会话。  | 
| [IsActive](#isactive) ()=0 | 获取会话是否被激活。  | 
| [Destroy](#destroy) ()=0 | 销毁会话。  | 
| [AddSupportCommand](#addsupportcommand) (const int32_t cmd)=0 | 添加支持的控制命令。  | 
| [DeleteSupportCommand](#deletesupportcommand) (const int32_t cmd)=0 | 删除支持的控制命令。  | 


## 成员枚举类型说明


### anonymous enum

  
```
anonymous enum
```
**描述:**
会话类型的枚举。

  | 枚举值 | 描述 | 
| -------- | -------- |
| SESSION_TYPE_INVALID  | 无效会话 | 
| SESSION_TYPE_AUDIO  | 音频会话 | 
| SESSION_TYPE_VIDEO  | 视频会话 | 


## 成员函数说明


### Activate()

  
```
virtual int32_t OHOS::AVSession::AVSession::Activate ()
```
**描述:**
激活会话。

激活成功后，会话才可以接收控制指令。

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。

**参见:**

[Deactivate](#deactivate)

[IsActive](#isactive)


### AddSupportCommand()

  
```
virtual int32_t OHOS::AVSession::AVSession::AddSupportCommand (const int32_t cmd)
```
**描述:**
添加支持的控制命令。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| cmd | 待添加的控制命令，范围为**SESSION_CMD_INVALID**到**SESSION_CMD_MAX**。  | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。


### Deactivate()

  
```
virtual int32_t OHOS::AVSession::AVSession::Deactivate ()
```
**描述:**
去激活会话。

去激活成功后，表示会话还不能接收控制指令。

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。

**参见:**

[Activate](#activate)

[IsActive](#isactive)


### DeleteSupportCommand()

  
```
virtual int32_t OHOS::AVSession::AVSession::DeleteSupportCommand (const int32_t cmd)
```
**描述:**
删除支持的控制命令。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| cmd | 待删除的控制命令，范围为**SESSION_CMD_INVALID**到**SESSION_CMD_MAX**。  | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。


### Destroy()

  
```
virtual int32_t OHOS::AVSession::AVSession::Destroy ()
```
**描述:**
销毁会话。

如果应用要创建一个新会话，必须要销毁之前的会话，否则会创建失败。

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。


### GetAVMetaData()

  
```
virtual int32_t OHOS::AVSession::AVSession::GetAVMetaData (AVMetaData & meta)
```
**描述:**
获取会话元数据。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| meta | 用于保存会话的元数据[AVMetaData](_o_h_o_s_1_1_a_v_session_1_1_a_v_meta_data.md)对象。  | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。

**参见:**

[SetAVMetaData](#setavmetadata)


### GetAVPlaybackState()

  
```
virtual int32_t OHOS::AVSession::AVSession::GetAVPlaybackState (AVPlaybackState & state)
```
**描述:**
获取音视频的播放状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| state | 用于保存播放状态的[AVPlaybackState](_o_h_o_s_1_1_a_v_session_1_1_a_v_playback_state.md)对象。  | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。

**参见:**

[SetAVPlaybackState](#setavplaybackstate)


### GetController()

  
```
virtual std::shared_ptr<AVSessionController> OHOS::AVSession::AVSession::GetController ()
```
**描述:**
获取会话控制器。

**返回:**

返回会话控制器，[AVSessionController](o_h_o_s_1_1_a_v_session_1_1_a_v_session_controller.md)类型智能指针。


### GetSessionId()

  
```
virtual std::string OHOS::AVSession::AVSession::GetSessionId ()
```
**描述:**
获取会话的标识。

**返回:**

返回会话的标识。


### IsActive()

  
```
virtual bool OHOS::AVSession::AVSession::IsActive ()
```
**描述:**
获取会话是否被激活。

**返回:**

如果是激活状态，则返回true；否则返回false。

**参见:**

[Activate](#activate)

[Deactivate](#deactivate)


### RegisterCallback()

  
```
virtual int32_t OHOS::AVSession::AVSession::RegisterCallback (const std::shared_ptr< AVSessionCallback > & callback)
```
**描述:**
注册会话回调。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| callback | 用于注册会话回调的[AVSessionCallback](_o_h_o_s_1_1_a_v_session_1_1_a_v_session_callback.md)对象。  | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。


### SetAVMetaData()

  
```
virtual int32_t OHOS::AVSession::AVSession::SetAVMetaData (const AVMetaData & meta)
```
**描述:**
设置会话元数据。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| meta | 用于修改会话的元数据[AVMetaData](_o_h_o_s_1_1_a_v_session_1_1_a_v_meta_data.md)对象。  | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。

**参见:**

[GetAVMetaData](#getavmetadata)


### SetAVPlaybackState()

  
```
virtual int32_t OHOS::AVSession::AVSession::SetAVPlaybackState (const AVPlaybackState & state)
```
**描述:**
设置音视频的播放状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| state | 用于修改播放状态的[AVPlaybackState](_o_h_o_s_1_1_a_v_session_1_1_a_v_playback_state.md)对象。  | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。

**参见:**

[GetAVPlaybackState](#getavplaybackstate)


### SetLaunchAbility()

  
```
virtual int32_t OHOS::AVSession::AVSession::SetLaunchAbility (const AbilityRuntime::WantAgent::WantAgent & ability)
```
**描述:**
设置一个WantAgent用于启动会话的Ability。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| ability | 具体的应用对应的能力，类型为**AbilityRuntime::WantAgent::WantAgent**。  | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。

**参见:**

[AVSessionController::GetLaunchAbility](o_h_o_s_1_1_a_v_session_1_1_a_v_session_controller.md#getlaunchability)
