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
| [OnPlay](#onplay) ()=0 | AVSession多媒体播放的抽象的回调方法。  | 
| [OnPause](#onpause) ()=0 | AVSession多媒体播放暂停的抽象的回调方法。  | 
| [OnStop](#onstop) ()=0 | AVSession多媒体播放停止的抽象的回调方法。  | 
| [OnPlayNext](#onplaynext) ()=0 | AVSession播放下一首多媒体的抽象的回调方法。  | 
| [OnPlayPrevious](#onplayprevious) ()=0 | AVSession播放上一首多媒体的抽象的回调方法。  | 
| [OnFastForward](#onfastforward) ()=0 | AVSession快进播放多媒体的抽象的回调方法。  | 
| [OnRewind](#onrewind) ()=0 | AVSession多媒体快退的抽象的回调方法。  | 
| [OnSeek](#onseek) (int64_t time)=0 | AVSession多媒体跳播操作的抽象的回调方法。  | 
| [OnSetSpeed](#onsetspeed) (double speed)=0 | AVSession设置多媒体倍速播放操作的抽象的回调方法。  | 
| [OnSetLoopMode](#onsetloopmode) (int32_t loopMode)=0 | AVSession设置多媒体循环播放模式的抽象的回调方法。  | 
| [OnToggleFavorite](#ontogglefavorite) (const std::string &amp;mediald)=0 | AVSession设置多媒体切换收藏操作的抽象的回调方法。  | 
| [OnMediaKeyEvent](#onmediakeyevent) (const MMI::KeyEvent &amp;keyEvent)=0 | AVSession多媒体按键事件处理的抽象的回调方法。  | 
| [OnOutputDeviceChange](#onoutputdevicechange) (const [OutputDeviceInfo](_o_h_o_s_1_1_a_v_session_1_1_output_device_info.md) &amp;outputDeviceInfo)=0 | 注册会话输出设备变更监听。  | 
| [~AVSessionCallback](#avsessioncallback) ()=default | AVSessionCallback的默认的析构函数。  | 


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
| keyEvent | 按键事件码，类型为**MMI::KeyEvent**。  | 


### OnOutputDeviceChange()

  
```
virtual void OHOS::AVSession::AVSessionCallback::OnOutputDeviceChange (const OutputDeviceInfo & outputDeviceInfo)
```
**描述:**
注册会话输出设备变更监听。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| outputDeviceInfo | 输出设备信息 [OutputDeviceInfo](_o_h_o_s_1_1_a_v_session_1_1_output_device_info.md)。  | 


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
| time | 媒体资源的位置，从媒体资源开头开始计算，单位为ms。取值需大于等于0。  | 


### OnSetLoopMode()

  
```
virtual void OHOS::AVSession::AVSessionCallback::OnSetLoopMode (int32_t loopMode)
```
**描述:**
AVSession设置多媒体循环播放模式的抽象的回调方法。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| loopMode | 多媒体循环播放模式， 范围在[AVPlaybackState](_o_h_o_s_1_1_a_v_session_1_1_a_v_playback_state.md)的**LOOP_MODE_SEQUENCE**到**LOOP_MODE_SHUFFLE**之间。  |


### OnSetSpeed()

  
```
virtual void OHOS::AVSession::AVSessionCallback::OnSetSpeed (double speed)
```
**描述:**
AVSession设置多媒体倍速播放操作的抽象的回调方法。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| speed | 多媒体播放的倍速值。  | 


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
| mediald | 多媒体ID号标识。  | 
