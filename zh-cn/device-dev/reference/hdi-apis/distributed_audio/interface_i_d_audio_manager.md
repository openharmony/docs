# IDAudioManager


## 概述

定义Distributed Audio设备基本的操作。

注册与去注册分布式音频设备、提供分布式音频SA向HDF层的事件通知机制。

**起始版本：** 4.1

**相关模块：**[Audio](_distributed.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [RegisterAudioDevice](#registeraudiodevice) ([in] String adpName, [in] int devId, [in] String capability, [in] [IDAudioCallback](interface_i_d_audio_callback.md) callbackObj) | 注册分布音频设备驱动。  | 
| [UnRegisterAudioDevice](#unregisteraudiodevice) ([in] String adpName, [in] int devId) | 去注册分布音频设备驱动。  | 
| [NotifyEvent](#notifyevent) ([in] String adpName, [in] int devId, [in] struct [DAudioEvent](_d_audio_event.md) event) | 分布音频设备SA通知事件。  | 


## 成员函数说明


### NotifyEvent()

```
IDAudioManager::NotifyEvent ([in] String adpName, [in] int devId, [in] struct DAudioEvent event )
```
**描述**

分布音频设备SA通知事件。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adpName | 分布式音频设备NetworkID。  | 
| devId | 分布式音频设备的端口ID。  | 
| event | 通知事件类型(如焦点事件，音量事件)。 | 

**返回：**

成功返回值0，失败返回负值。


### RegisterAudioDevice()

```
IDAudioManager::RegisterAudioDevice ([in] String adpName, [in] int devId, [in] String capability, [in] IDAudioCallback callbackObj )
```
**描述**

注册分布音频设备驱动。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adpName | 分布式音频设备NetworkID。  | 
| devId | 分布式音频设备的端口ID。  | 
| capability | 分布式音频设备能力集(包括采样率、通道数等)。  | 
| callbackObj | 分布式音频SA回调。 | 

**返回：**

成功返回值0，失败返回负值。


### UnRegisterAudioDevice()

```
IDAudioManager::UnRegisterAudioDevice ([in] String adpName, [in] int devId )
```
**描述**

去注册分布音频设备驱动。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adpName | 分布式音频设备NetworkID。  | 
| devId | 分布式音频设备的端口ID。 | 

**返回：**

成功返回值0，失败返回负值。
