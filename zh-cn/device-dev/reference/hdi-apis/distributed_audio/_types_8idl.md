# Types.idl


## 概述

Audio模块接口定义中使用的数据类型。

Audio模块接口定义中使用的数据类型，包括音频播放模式、采样属性、事件类型、数据类型、时间戳等。

模块包路径：ohos.hdi.distributed_audio.audioext.v1_0

**起始版本：** 4.1

**相关模块：**[Audio](_distributed.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[AudioParameter](_audio_parameter.md) | 音频采样属性。 | 
| struct&nbsp;&nbsp;[AudioData](_audio_data.md) | 音频数据类型。 | 
| struct&nbsp;&nbsp;[DAudioEvent](_d_audio_event.md) | 音频事件类型。 | 
| struct&nbsp;&nbsp;[CurrentTime](_current_time.md) | 音频时间戳。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [PortOperationMode](_distributed.md#portoperationmode) { NORMAL_MODE = 0 , MMAP_MODE = 1 } | 音频端口播放模式。 | 
