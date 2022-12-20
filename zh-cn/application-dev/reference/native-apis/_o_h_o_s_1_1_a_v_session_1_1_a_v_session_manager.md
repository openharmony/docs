# OHOS::AVSession::AVSessionManager


## 概述

实现会话管理器对外接口功能的类的实现。

**Since:**
9
**Version:**
1.0

## 汇总


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [CreateSession](#createsession)&nbsp;(const&nbsp;std::string&nbsp;&amp;tag,&nbsp;int32_t&nbsp;type,&nbsp;const&nbsp;AppExecFwk::ElementName&nbsp;&amp;elementName)=0 | 创建AVSession会话的接口方法。&nbsp; | 
| [GetAllSessionDescriptors](#getallsessiondescriptors)&nbsp;(std::vector&lt;&nbsp;[AVSessionDescriptor](o_h_o_s_1_1_a_v_session_1_1_a_v_session_descriptor.md)&nbsp;&gt;&nbsp;&amp;descriptors)=0 | 获取AVSession全部的会话描述的接口方法。&nbsp; | 
| [GetActivatedSessionDescriptors](#getactivatedsessiondescriptors)&nbsp;(std::vector&lt;&nbsp;[AVSessionDescriptor](o_h_o_s_1_1_a_v_session_1_1_a_v_session_descriptor.md)&nbsp;&gt;&nbsp;&amp;activatedSessions)=0 | 获取AVSession全部处于活动状态的会话描述的接口方法。&nbsp; | 
| [GetSessionDescriptorsBySessionId](#getsessiondescriptorsbysessionid)&nbsp;(const&nbsp;std::string&nbsp;&amp;sessionId,&nbsp;[AVSessionDescriptor](o_h_o_s_1_1_a_v_session_1_1_a_v_session_descriptor.md)&nbsp;&amp;descriptor)=0 | 通过会话ID获得会话描述的方法。&nbsp; | 
| [CreateController](#createcontroller)&nbsp;(const&nbsp;std::string&nbsp;&amp;sessionId,&nbsp;std::shared_ptr&lt;&nbsp;[AVSessionController](o_h_o_s_1_1_a_v_session_1_1_a_v_session_controller.md)&nbsp;&gt;&nbsp;&amp;controller)=0 | 创建AVSession会话控制器的接口方法。&nbsp; | 
| [RegisterSessionListener](#registersessionlistener)&nbsp;(const&nbsp;std::shared_ptr&lt;&nbsp;[SessionListener](_o_h_o_s_1_1_a_v_session_1_1_session_listener.md)&nbsp;&gt;&nbsp;&amp;listener)=0 | 注册AVSession会话监听器的接口方法。&nbsp; | 
| [RegisterServiceDeathCallback](#registerservicedeathcallback)&nbsp;(const&nbsp;[DeathCallback](avsession__info_8h.md#deathcallback)&nbsp;&amp;callback)=0 | 注册AVSession服务器的死亡回调的接口方法。&nbsp; | 
| [UnregisterServiceDeathCallback](#unregisterservicedeathcallback)&nbsp;()=0 | 注销AVSession服务器的死亡回调的接口方法。&nbsp; | 
| [SendSystemAVKeyEvent](#sendsystemavkeyevent)&nbsp;(const&nbsp;MMI::KeyEvent&nbsp;&amp;keyEvent)=0 | 发送系统按键事件的接口方法。&nbsp; | 
| [SendSystemControlCommand](#sendsystemcontrolcommand)&nbsp;(const&nbsp;[AVControlCommand](_o_h_o_s_1_1_a_v_session_1_1_a_v_control_command.md)&nbsp;&amp;command)=0 | 发送系统控制命令的接口方法。&nbsp; | 
| [CastAudio](#castaudio)&nbsp;(const&nbsp;[SessionToken](_o_h_o_s_1_1_a_v_session_1_1_session_token.md)&nbsp;&amp;token,&nbsp;const&nbsp;std::vector&lt;&nbsp;AudioStandard::AudioDeviceDescriptor&nbsp;&gt;&nbsp;&amp;descriptors)=0 | 将媒体会话投射到远程设备或投射回本地设备。&nbsp; | 
| [CastAudioForAll](#castaudioforall)&nbsp;(const&nbsp;std::vector&lt;&nbsp;AudioStandard::AudioDeviceDescriptor&nbsp;&gt;&nbsp;&amp;descriptors)=0 | 将此设备的所有媒体会话投播到远程设备。&nbsp; | 


### 静态 Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [GetInstance](#getinstance)&nbsp;() | 获取会话管理器实例。&nbsp; | 


## 成员函数说明


### CastAudio()

  
```
virtual int32_t OHOS::AVSession::AVSessionManager::CastAudio (const SessionToken & token, const std::vector< AudioStandard::AudioDeviceDescriptor > & descriptors )
```
**描述:**
将媒体会话投射到远程设备或投射回本地设备。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| token | 需要投播的会话令牌。&nbsp; | 
| descriptors | 指定要转换的音频设备。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。


### CastAudioForAll()

  
```
virtual int32_t OHOS::AVSession::AVSessionManager::CastAudioForAll (const std::vector< AudioStandard::AudioDeviceDescriptor > & descriptors)
```
**描述:**
将此设备的所有媒体会话投播到远程设备。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| descriptors | 指定要转换的音频设备。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。


### CreateController()

  
```
virtual int32_t OHOS::AVSession::AVSessionManager::CreateController (const std::string & sessionId, std::shared_ptr< AVSessionController > & controller )
```
**描述:**
创建AVSession会话控制器的接口方法。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| sessionId | AVSession的会话ID。&nbsp; | 
| controller | 会话控制器实例，类型为[AVSessionController](o_h_o_s_1_1_a_v_session_1_1_a_v_session_controller.md)。&nbsp; | 

**返回:**

返回成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。


### CreateSession()

  
```
virtual std::shared_ptr<AVSession> OHOS::AVSession::AVSessionManager::CreateSession (const std::string & tag, int32_t type, const AppExecFwk::ElementName & elementName )
```
**描述:**
创建AVSession会话的接口方法。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| tag | AVSession的会话标签，不可为空。&nbsp; | 
| type | AVSession的会话类型,&nbsp;入参为[AVSession#SESSION_TYPE_AUDIO](_o_h_o_s_1_1_a_v_session_1_1_a_v_session.md#ac1c9f46a84c35e7cca9966a48d4cbd96a10f702f1a7483e621c98c7b8ff4108f6)，[AVSession#SESSION_TYPE_VIDEO](_o_h_o_s_1_1_a_v_session_1_1_a_v_session.md#ac1c9f46a84c35e7cca9966a48d4cbd96ab28acf8f76ffe654b5820e9db3f0e9bb)。&nbsp; | 
| elementName | AVSession的会话名称**AppExecFwk::ElementName**。&nbsp; | 

**返回:**

返回已创建的会话对象的智能指针。


### GetActivatedSessionDescriptors()

  
```
virtual int32_t OHOS::AVSession::AVSessionManager::GetActivatedSessionDescriptors (std::vector< AVSessionDescriptor > & activatedSessions)
```
**描述:**
获取AVSession全部处于活动状态的会话描述的接口方法。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| activatedSessions | 处于活动状态的会话描述，类型为[AVSessionDescriptor](o_h_o_s_1_1_a_v_session_1_1_a_v_session_descriptor.md)。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。


### GetAllSessionDescriptors()

  
```
virtual int32_t OHOS::AVSession::AVSessionManager::GetAllSessionDescriptors (std::vector< AVSessionDescriptor > & descriptors)
```
**描述:**
获取AVSession全部的会话描述的接口方法。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| descriptors | AVSession的会话描述，类型为[AVSessionDescriptor](o_h_o_s_1_1_a_v_session_1_1_a_v_session_descriptor.md)。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。


### GetInstance()

  
```
static AVSessionManager& OHOS::AVSession::AVSessionManager::GetInstance ()
```
**描述:**
获取会话管理器实例。

**返回:**

返回会话管理器实例。


### GetSessionDescriptorsBySessionId()

  
```
virtual int32_t OHOS::AVSession::AVSessionManager::GetSessionDescriptorsBySessionId (const std::string & sessionId, AVSessionDescriptor & descriptor )
```
**描述:**
通过会话ID获得会话描述的方法。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| sessionId | AVSession的会话标签。&nbsp; | 
| descriptor | AVSession的会话描述，类型为[AVSessionDescriptor](o_h_o_s_1_1_a_v_session_1_1_a_v_session_descriptor.md)。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。


### RegisterServiceDeathCallback()

  
```
virtual int32_t OHOS::AVSession::AVSessionManager::RegisterServiceDeathCallback (const DeathCallback & callback)
```
**描述:**
注册AVSession服务器的死亡回调的接口方法。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| callback | 死亡回调的方法，类型为**DeathCallback**。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。

**参见:**

[UnregisterServiceDeathCallback](#unregisterservicedeathcallback)


### RegisterSessionListener()

  
```
virtual int32_t OHOS::AVSession::AVSessionManager::RegisterSessionListener (const std::shared_ptr< SessionListener > & listener)
```
**描述:**
注册AVSession会话监听器的接口方法。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| listener | 会话监听器的智能指针，类型为[SessionListener](_o_h_o_s_1_1_a_v_session_1_1_session_listener.md)。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。


### SendSystemAVKeyEvent()

  
```
virtual int32_t OHOS::AVSession::AVSessionManager::SendSystemAVKeyEvent (const MMI::KeyEvent & keyEvent)
```
**描述:**
发送系统按键事件的接口方法。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| keyEvent | 按键事件码，类型为**MMI::KeyEvent**。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。


### SendSystemControlCommand()

  
```
virtual int32_t OHOS::AVSession::AVSessionManager::SendSystemControlCommand (const AVControlCommand & command)
```
**描述:**
发送系统控制命令的接口方法。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| command | 系统控制命令[AVControlCommand](_o_h_o_s_1_1_a_v_session_1_1_a_v_control_command.md)。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。


### UnregisterServiceDeathCallback()

  
```
virtual int32_t OHOS::AVSession::AVSessionManager::UnregisterServiceDeathCallback ()
```
**描述:**
注销AVSession服务器的死亡回调的接口方法。

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。

**参见:**

[RegisterServiceDeathCallback](#registerservicedeathcallback)
