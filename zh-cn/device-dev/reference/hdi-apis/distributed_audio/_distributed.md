# Distributed Audio


## 概述

Distributed Audio模块包括对分布式音频设备的操作、流的操作和各种回调等。 通过IDAudioCallback和IDAudioManager接口，与Source SA通信交互，实现分布式功能。

**起始版本：** 4.1


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IDAudioCallback.idl](_i_d_audio_callback_8idl.md) | 分布式音频HDF服务与分布式音频SA服务的传输接口调用，并为上层提供硬件驱动接口。 | 
| [IDAudioManager.idl](_i_d_audio_manager_8idl.md) | 分布式音频HDF层的调用接口，为分布式音频SA提供硬件驱动注册、去注册以及事件通知能力。 | 
| [Types.idl](_types_8idl.md) | Audio模块接口定义中使用的数据类型。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IDAudioCallback](interface_i_d_audio_callback.md) | 定义Distributed Audio设备基本的操作。 | 
| interface&nbsp;&nbsp;[IDAudioManager](interface_i_d_audio_manager.md) | 定义Distributed Audio设备基本的操作。 | 
| struct&nbsp;&nbsp;[AudioParameter](_audio_parameter.md) | 音频采样属性。 | 
| struct&nbsp;&nbsp;[AudioData](_audio_data.md) | 音频数据类型。 | 
| struct&nbsp;&nbsp;[DAudioEvent](_d_audio_event.md) | 音频事件类型。 | 
| struct&nbsp;&nbsp;[CurrentTime](_current_time.md) | 音频时间戳。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [PortOperationMode](#portoperationmode) { NORMAL_MODE = 0 , MMAP_MODE = 1 } | 音频端口播放模式。 | 


## 枚举类型说明


### PortOperationMode

```
enum PortOperationMode
```

**描述**


音频端口播放模式。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| NORMAL_MODE | 正常模式。 | 
| MMAP_MODE | 低时延模式。 | 
