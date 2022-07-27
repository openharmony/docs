# AudioVolume


## **概述**

**所属模块:**

[Audio](_audio.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| (&nbsp;[SetMute](#setmute)&nbsp;)([AudioHandle](_audio.md#ga18675ddb073465fdeac33a897f675d79)&nbsp;handle,&nbsp;bool&nbsp;mute) | 设置音频的静音状态&nbsp;[更多...](#setmute) | 
| (&nbsp;[GetMute](#getmute)&nbsp;)([AudioHandle](_audio.md#ga18675ddb073465fdeac33a897f675d79)&nbsp;handle,&nbsp;bool&nbsp;\*mute) | 获取音频的静音状态&nbsp;[更多...](#getmute) | 
| (&nbsp;[SetVolume](#setvolume)&nbsp;)([AudioHandle](_audio.md#ga18675ddb073465fdeac33a897f675d79)&nbsp;handle,&nbsp;float&nbsp;volume) | 设置一个音频流的音量&nbsp;[更多...](#setvolume) | 
| (&nbsp;[GetVolume](#getvolume)&nbsp;)([AudioHandle](_audio.md#ga18675ddb073465fdeac33a897f675d79)&nbsp;handle,&nbsp;float&nbsp;\*volume) | 获取一个音频流的音量&nbsp;[更多...](#getvolume) | 
| (&nbsp;[GetGainThreshold](#getgainthreshold)&nbsp;)([AudioHandle](_audio.md#ga18675ddb073465fdeac33a897f675d79)&nbsp;handle,&nbsp;float&nbsp;\*min,&nbsp;float&nbsp;\*max) | 获取音频流增益的阈值&nbsp;[更多...](#getgainthreshold) | 
| (&nbsp;[GetGain](#getgain)&nbsp;)([AudioHandle](_audio.md#ga18675ddb073465fdeac33a897f675d79)&nbsp;handle,&nbsp;float&nbsp;\*gain) | 获取音频流的增益&nbsp;[更多...](#getgain) | 
| (&nbsp;[SetGain](#setgain)&nbsp;)([AudioHandle](_audio.md#ga18675ddb073465fdeac33a897f675d79)&nbsp;handle,&nbsp;float&nbsp;gain) | 设置音频流的增益&nbsp;[更多...](#setgain) | 


## **详细描述**

AudioVolume音频音量接口。

提供音频播放（render）或录音（capture）需要的公共音量驱动能力，包括静音操作、设置音量、设置增益等。

**Since：**

1.0

**Version：**

1.0


## **类成员变量说明**


### GetGain

  
```
int32_t(* AudioVolume::GetGain) (AudioHandle handle, float *gain)
```

**描述：**

获取音频流的增益

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 待操作的音频句柄 | 
| gain | 保存当前获取到的增益到gain中 | 

**返回：**

成功返回值0，失败返回负值

**参见：**

[GetGainThreshold](#getgainthreshold)

[SetGain](#setgain)


### GetGainThreshold

  
```
int32_t(* AudioVolume::GetGainThreshold) (AudioHandle handle, float *min, float *max)
```

**描述：**

获取音频流增益的阈值

在具体的功能实现中，可以根据芯片平台的实际情况来进行处理：

- 1. 可以使用实际的增益值，例如增益的范围为-50db ~ 6db

- 2. 也可以将增益范围设定为0.0~1.0，如果增益的范围为-50db ~ 6db， 则增益的映射关系为0.0表示静音，1.0表示最大增益（6db）

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 待操作的音频句柄 | 
| min | 获取的音频增益的阈值下限保存到min中 | 
| max | 获取的音频增益的阈值上限保存到max中 | 

**返回：**

成功返回值0，失败返回负值

**参见：**

[GetGain](#getgain)

[SetGain](#setgain)


### GetMute

  
```
int32_t(* AudioVolume::GetMute) (AudioHandle handle, bool *mute)
```

**描述：**

获取音频的静音状态

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 待操作的音频句柄 | 
| mute | 获取的静音状态保存到mute中，true表示静音操作、false表示取消静音操作 | 

**返回：**

成功返回值0，失败返回负值

**参见：**

[SetMute](#setmute)


### GetVolume

  
```
int32_t(* AudioVolume::GetVolume) (AudioHandle handle, float *volume)
```

**描述：**

获取一个音频流的音量

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 待操作的音频句柄 | 
| volume | 获取的音量保存到volume中，范围0.0~1.0 | 

**返回：**

成功返回值0，失败返回负值

**参见：**

[SetVolume](#setvolume)


### SetGain

  
```
int32_t(* AudioVolume::SetGain) (AudioHandle handle, float gain)
```

**描述：**

设置音频流的增益

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 待操作的音频句柄 | 
| gain | gain&nbsp;待设置的增益 | 

**返回：**

成功返回值0，失败返回负值

**参见：**

[GetGainThreshold](#getgainthreshold)

[GetGain](#getgain)


### SetMute

  
```
int32_t(* AudioVolume::SetMute) (AudioHandle handle, bool mute)
```

**描述：**

设置音频的静音状态

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 待操作的音频句柄 | 
| mute | 待设置的静音状态，true表示静音操作、false表示取消静音操作 | 

**返回：**

成功返回值0，失败返回负值

**参见：**

[GetMute](#getmute)


### SetVolume

  
```
int32_t(* AudioVolume::SetVolume) (AudioHandle handle, float volume)
```

**描述：**

设置一个音频流的音量。

音量的取值范围是0.0~1.0，如果音频服务中的音量等级为15级（0 ~ 15）， 则音量的映射关系为0.0表示静音，1.0表示最大音量等级（15）

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 待操作的音频句柄 | 
| volume | 待设置的音量，范围0.0~1.0 | 

**返回：**

成功返回值0，失败返回负值
