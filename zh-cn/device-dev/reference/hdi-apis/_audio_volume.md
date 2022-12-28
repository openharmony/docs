# AudioVolume


## **概述**

AudioVolume音频音量接口。

提供音频播放（Render）或录音（Capture）需要的公共音量驱动能力，包括静音操作、设置音量、设置增益等。

**Since：**

1.0

**Version：**

1.0

**相关模块:**

[Audio](_audio.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| ([SetMute](#setmute))(AudioHandle&nbsp;handle,&nbsp;bool&nbsp;mute) | 设置音频的静音状态 | 
| ([GetMute](#getmute))(AudioHandle&nbsp;handle,&nbsp;bool&nbsp;\*mute) | 获取音频的静音状态 | 
| ([SetVolume](#setvolume))(AudioHandle&nbsp;handle,&nbsp;float&nbsp;volume) | 设置一个音频流的音量 | 
| ([GetVolume](#getvolume))(AudioHandle&nbsp;handle,&nbsp;float&nbsp;\*volume) | 获取一个音频流的音量 | 
| ([GetGainThreshold](#getgainthreshold))(AudioHandle&nbsp;handle,&nbsp;float&nbsp;\*min,&nbsp;float&nbsp;\*max) | 获取音频流增益的阈值 | 
| ([GetGain](#getgain))(AudioHandle&nbsp;handle,&nbsp;float&nbsp;\*gain) | 获取音频流的增益 | 
| ([SetGain](#setgain))(AudioHandle&nbsp;handle,&nbsp;float&nbsp;gain) | 设置音频流的增益 | 


## **类成员变量说明**


### GetGain

  
```
int32_t(* AudioVolume::GetGain) (AudioHandle handle, float *gain)
```

**描述：**

获取音频流的增益。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输入参数，待操作的音频句柄。 | 
| gain | 输出参数，保存当前获取到的增益到gain中。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[GetGainThreshold](#getgainthreshold)

[SetGain](#setgain)


### GetGainThreshold

  
```
int32_t(* AudioVolume::GetGainThreshold) (AudioHandle handle, float *min, float *max)
```

**描述：**

获取音频流增益的阈值。

在具体的功能实现中，可以根据芯片平台的实际情况来进行处理：

- 可以使用实际的增益值，例如增益的范围为-50db ~ 6db。

- 也可以将增益范围设定为0.0~1.0，如果增益的范围为-50db ~ 6db， 则增益的映射关系为0.0表示静音，1.0表示最大增益（6db）。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输入参数，待操作的音频句柄。 | 
| min | 输出参数，获取的音频增益的阈值下限保存到min中。 | 
| max | 输出参数，获取的音频增益的阈值上限保存到max中。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[GetGain](#getgain)

[SetGain](#setgain)


### GetMute

  
```
int32_t(* AudioVolume::GetMute) (AudioHandle handle, bool *mute)
```

**描述：**

获取音频的静音状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输入参数，待操作的音频句柄。 | 
| mute | 输出参数，获取的静音状态保存到mute中，true表示静音操作，false表示取消静音操作。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[SetMute](#setmute)


### GetVolume

  
```
int32_t(* AudioVolume::GetVolume) (AudioHandle handle, float *volume)
```

**描述：**

获取一个音频流的音量。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输入参数，待操作的音频句柄。 | 
| volume | 输出参数，获取的音量保存到volume中，范围0.0~1.0。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[SetVolume](#setvolume)


### SetGain

  
```
int32_t(* AudioVolume::SetGain) (AudioHandle handle, float gain)
```

**描述：**

设置音频流的增益。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输入参数，待操作的音频句柄。 | 
| gain | 输入参数，待设置的增益。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[GetGainThreshold](#getgainthreshold)

[GetGain](#getgain)


### SetMute

  
```
int32_t(* AudioVolume::SetMute) (AudioHandle handle, bool mute)
```

**描述：**

设置音频的静音状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输入参数，待操作的音频句柄。 | 
| mute | 输入参数，待设置的静音状态，true表示静音操作，false表示取消静音操作。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[GetMute](#getmute)


### SetVolume

  
```
int32_t(* AudioVolume::SetVolume) (AudioHandle handle, float volume)
```

**描述：**

设置一个音频流的音量。

音量的取值范围是0.0~1.0，如果音频服务中的音量等级为15级（0 ~ 15），则音量的映射关系为0.0表示静音，1.0表示最大音量等级（15）。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| handle | 输入参数，待操作的音频句柄。 | 
| volume | 输入参数，待设置的音量，范围0.0~1.0。 | 

**返回:**

成功返回值0，失败返回负值。
