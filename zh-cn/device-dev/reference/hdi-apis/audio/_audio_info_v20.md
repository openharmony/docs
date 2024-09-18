# AudioInfo


## 概述

音频端口特定信息。

**起始版本：** 4.1

**相关模块：**[HdiAudio](_hdi_audio_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| struct [AudioDevExtInfo](_audio_dev_ext_info_v20.md)[device](#device) | 设备特定信息，详情参考[AudioDevExtInfo](_audio_dev_ext_info_v20.md)。  | 
| struct [AudioMixExtInfo](_audio_mix_ext_info_v20.md)[mix](#mix) | 音轨特定信息，详情参考[AudioMixExtInfo](_audio_mix_ext_info_v20.md)。  | 
| struct [AudioSessionExtInfo](_audio_session_ext_info_v20.md)[session](#session) | 会话特定信息，详情参考[AudioSessionExtInfo](_audio_session_ext_info_v20.md)。  | 


## 类成员变量说明


### device

```
struct AudioDevExtInfo AudioInfo::device
```
**描述**

设备特定信息，详情参考[AudioDevExtInfo](_audio_dev_ext_info_v20.md)。


### mix

```
struct AudioMixExtInfo AudioInfo::mix
```
**描述**

音轨特定信息，详情参考[AudioMixExtInfo](_audio_mix_ext_info_v20.md)。


### session

```
struct AudioSessionExtInfo AudioInfo::session
```
**描述**

会话特定信息，详情参考[AudioSessionExtInfo](_audio_session_ext_info_v20.md)。
