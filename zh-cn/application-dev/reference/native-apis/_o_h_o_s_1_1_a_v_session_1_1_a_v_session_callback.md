# OHOS::AVSession::AVSessionCallback


## 概述

定义AVSession回调类的实现

**Since:**
9
**Version:**
1.0

## 汇总


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [OnPlay](#onplay)&nbsp;()=0 | AVSession多媒体播放的抽象的回调方法。&nbsp; | 
| [OnPause](#onpause)&nbsp;()=0 | AVSession多媒体播放暂停的抽象的回调方法。&nbsp; | 
| [OnStop](#onstop)&nbsp;()=0 | AVSession多媒体播放停止的抽象的回调方法。&nbsp; | 
| [OnPlayNext](#onplaynext)&nbsp;()=0 | AVSession播放下一首多媒体的抽象的回调方法。&nbsp; | 
| [OnPlayPrevious](#onplayprevious)&nbsp;()=0 | AVSession播放上一首多媒体的抽象的回调方法。&nbsp; | 
| [OnFastForward](#onfastforward)&nbsp;()=0 | AVSession快进播放多媒体的抽象的回调方法。&nbsp; | 
| [OnRewind](#onrewind)&nbsp;()=0 | AVSession多媒体快退的抽象的回调方法。&nbsp; | 
| [OnSeek](#onseek)&nbsp;(int64_t&nbsp;time)=0 | AVSession多媒体跳播操作的抽象的回调方法。&nbsp; | 
| [OnSetSpeed](#onsetspeed)&nbsp;(double&nbsp;speed)=0 | AVSession设置多媒体倍速播放操作的抽象的回调方法。&nbsp; | 
| [OnSetLoopMode](#onsetloopmode)&nbsp;(int32_t&nbsp;loopMode)=0 | AVSession设置多媒体循环播放模式的抽象的回调方法。&nbsp; | 
| [OnToggleFavorite](#ontogglefavorite)&nbsp;(const&nbsp;std::string&nbsp;&amp;mediald)=0 | AVSession设置多媒体切换收藏操作的抽象的回调方法。&nbsp; | 
| [OnMediaKeyEvent](#onmediakeyevent)&nbsp;(const&nbsp;MMI::KeyEvent&nbsp;&amp;keyEvent)=0 | AVSession多媒体按键事件处理的抽象的回调方法。&nbsp; | 
| [OnOutputDeviceChange](#onoutputdevicechange)&nbsp;(const&nbsp;[OutputDeviceInfo](_o_h_o_s_1_1_a_v_session_1_1_output_device_info.md)&nbsp;&amp;outputDeviceInfo)=0 | 注册会话输出设备变更监听。&nbsp; | 
| [~AVSessionCallback](#avsessioncallback)&nbsp;()=default | AVSessionCallback的默认的析构函数。&nbsp; | 


## 构造及析构函数说明


### ~AVSessionCallback()

  
```
virtual OHOS::AVSession::AVSessionCallback::~AVSessionCallback ()
```
**描述:**
AVSessionCallback的默认的析构函数。


## 成员函数说明


### OnFastForward()

  
```
virtual void OHOS::AVSession::AVSessionCallback::OnFastForward ()
```
**描述:**
AVSession快进播放多媒体的抽象的回调方法。


### OnMediaKeyEvent()

  
```
virtual void OHOS::AVSession::AVSessionCallback::OnMediaKeyEvent (const MMI::KeyEvent & keyEvent)
```
**描述:**
AVSession多媒体按键事件处理的抽象的回调方法。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| keyEvent | 按键事件码，类型为**MMI::KeyEvent**。&nbsp; | 


### OnOutputDeviceChange()

  
```
virtual void OHOS::AVSession::AVSessionCallback::OnOutputDeviceChange (const OutputDeviceInfo & outputDeviceInfo)
```
**描述:**
注册会话输出设备变更监听。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| outputDeviceInfo | 输出设备信息&nbsp;[OutputDeviceInfo](_o_h_o_s_1_1_a_v_session_1_1_output_device_info.md)。&nbsp; | 


### OnPause()

  
```
virtual void OHOS::AVSession::AVSessionCallback::OnPause ()
```
**描述:**
AVSession多媒体播放暂停的抽象的回调方法。


### OnPlay()

  
```
virtual void OHOS::AVSession::AVSessionCallback::OnPlay ()
```
**描述:**
AVSession多媒体播放的抽象的回调方法。


### OnPlayNext()

  
```
virtual void OHOS::AVSession::AVSessionCallback::OnPlayNext ()
```
**描述:**
AVSession播放下一首多媒体的抽象的回调方法。


### OnPlayPrevious()

  
```
virtual void OHOS::AVSession::AVSessionCallback::OnPlayPrevious ()
```
**描述:**
AVSession播放上一首多媒体的抽象的回调方法。


### OnRewind()

  
```
virtual void OHOS::AVSession::AVSessionCallback::OnRewind ()
```
**描述:**
AVSession多媒体快退的抽象的回调方法。


### OnSeek()

  
```
virtual void OHOS::AVSession::AVSessionCallback::OnSeek (int64_t time)
```
**描述:**
AVSession多媒体跳播操作的抽象的回调方法。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| time | 媒体资源的位置，从媒体资源开头开始计算，单位为ms。取值需大于等于0。&nbsp; | 


### OnSetLoopMode()

  
```
virtual void OHOS::AVSession::AVSessionCallback::OnSetLoopMode (int32_t loopMode)
```
**描述:**
AVSession设置多媒体循环播放模式的抽象的回调方法。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| loopMode | 多媒体循环播放模式，&nbsp;范围在&nbsp;[AVPlaybackState#LOOP_MODE_SEQUENCE](_o_h_o_s_1_1_a_v_session_1_1_a_v_playback_state.md#a12c2de6b9e2d86a6d2fe5bec88f90abfa85feb6afb637e762bc97d938f74c5f08)到[AVPlaybackState#LOOP_MODE_SHUFFLE](_o_h_o_s_1_1_a_v_session_1_1_a_v_playback_state.md#a12c2de6b9e2d86a6d2fe5bec88f90abfaeaa9c517ca402e56c594c6b17d566203)之间。&nbsp; | 


### OnSetSpeed()

  
```
virtual void OHOS::AVSession::AVSessionCallback::OnSetSpeed (double speed)
```
**描述:**
AVSession设置多媒体倍速播放操作的抽象的回调方法。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| speed | 多媒体播放的倍速值。&nbsp; | 


### OnStop()

  
```
virtual void OHOS::AVSession::AVSessionCallback::OnStop ()
```
**描述:**
AVSession多媒体播放停止的抽象的回调方法。


### OnToggleFavorite()

  
```
virtual void OHOS::AVSession::AVSessionCallback::OnToggleFavorite (const std::string & mediald)
```
**描述:**
AVSession设置多媒体切换收藏操作的抽象的回调方法。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| mediald | 多媒体ID号标识。&nbsp; | 
