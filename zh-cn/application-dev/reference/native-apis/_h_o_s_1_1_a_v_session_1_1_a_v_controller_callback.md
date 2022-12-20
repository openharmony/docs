# OHOS::AVSession::AVControllerCallback


## 概述

定义控制器相关回调操作的类的实现。

**Since:**
9
**Version:**
1.0

## 汇总


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [OnSessionDestroy](#onsessiondestroy)&nbsp;()=0 | AVSession会话销毁的抽象的回调方法。&nbsp; | 
| [OnPlaybackStateChange](#onplaybackstatechange)&nbsp;(const&nbsp;[AVPlaybackState](_o_h_o_s_1_1_a_v_session_1_1_a_v_playback_state.md)&nbsp;&amp;state)=0 | 音视频的播放状态发生改变的抽象的回调方法。&nbsp; | 
| [OnMetaDataChange](#onmetadatachange)&nbsp;(const&nbsp;[AVMetaData](_o_h_o_s_1_1_a_v_session_1_1_a_v_meta_data.md)&nbsp;&amp;data)=0 | 会话元数据内容发生变化的抽象的回调方法。&nbsp; | 
| [OnActiveStateChange](#onactivestatechange)&nbsp;(bool&nbsp;isActive)=0 | 当前会话激活状态发生改变的抽象的回调方法。&nbsp; | 
| [OnValidCommandChange](#onvalidcommandchange)&nbsp;(const&nbsp;std::vector&lt;&nbsp;int32_t&nbsp;&gt;&nbsp;&amp;cmds)=0 | 控制命令的有效性发生变化的抽象的回调方法。&nbsp; | 
| [OnOutputDeviceChange](#onoutputdevicechange)&nbsp;(const&nbsp;[OutputDeviceInfo](_o_h_o_s_1_1_a_v_session_1_1_output_device_info.md)&nbsp;&amp;outputDeviceInfo)=0 | 注册会话输出设备更改。&nbsp; | 
| [~AVControllerCallback](#avcontrollercallback)&nbsp;()=default | AVControllerCallback的默认的析构函数。&nbsp; | 


## 构造及析构函数说明


### ~AVControllerCallback()

  
```
virtual OHOS::AVSession::AVControllerCallback::~AVControllerCallback ()
```
**描述:**
AVControllerCallback的默认的析构函数。


## 成员函数说明


### OnActiveStateChange()

  
```
virtual void OHOS::AVSession::AVControllerCallback::OnActiveStateChange (bool isActive)
```
**描述:**
当前会话激活状态发生改变的抽象的回调方法。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| isActive | 表示是否激活。&nbsp; | 


### OnMetaDataChange()

  
```
virtual void OHOS::AVSession::AVControllerCallback::OnMetaDataChange (const AVMetaData & data)
```
**描述:**
会话元数据内容发生变化的抽象的回调方法。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| data | 会话元数据内容，类型为[AVMetaData](_o_h_o_s_1_1_a_v_session_1_1_a_v_meta_data.md)。&nbsp; | 

**参见:**

[AVMetaData](_o_h_o_s_1_1_a_v_session_1_1_a_v_meta_data.md)


### OnOutputDeviceChange()

  
```
virtual void OHOS::AVSession::AVControllerCallback::OnOutputDeviceChange (const OutputDeviceInfo & outputDeviceInfo)
```
**描述:**
注册会话输出设备更改。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| outputDeviceInfo | 输出设备信息&nbsp;[OutputDeviceInfo](_o_h_o_s_1_1_a_v_session_1_1_output_device_info.md)。&nbsp; | 


### OnPlaybackStateChange()

  
```
virtual void OHOS::AVSession::AVControllerCallback::OnPlaybackStateChange (const AVPlaybackState & state)
```
**描述:**
音视频的播放状态发生改变的抽象的回调方法。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| state | 音视频的播放状态的枚举值，类型为[AVPlaybackState](_o_h_o_s_1_1_a_v_session_1_1_a_v_playback_state.md)。&nbsp; | 


### OnSessionDestroy()

  
```
virtual void OHOS::AVSession::AVControllerCallback::OnSessionDestroy ()
```
**描述:**
AVSession会话销毁的抽象的回调方法。


### OnValidCommandChange()

  
```
virtual void OHOS::AVSession::AVControllerCallback::OnValidCommandChange (const std::vector< int32_t > & cmds)
```
**描述:**
控制命令的有效性发生变化的抽象的回调方法。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| cmds，媒体有效的指令列表，范围为{ |  | 
