# IAudioAdapter


## 概述

AudioAdapter音频适配器接口。

提供音频适配器（声卡）对外支持的驱动能力，包括初始化端口、创建放音、创建录音、获取端口能力集等。

3.2

**Version:**

1.0

**相关模块:**

[Audio](_audio.md)


## 汇总


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [InitAllPorts](#initallports)&nbsp;() | 初始化一个音频适配器所有的端口驱动。 | 
| [CreateRender](#createrender)&nbsp;([in]&nbsp;struct&nbsp;[AudioDeviceDescriptor](_audio_device_descriptor.md)&nbsp;desc,&nbsp;[in]&nbsp;struct&nbsp;[AudioSampleAttributes](_audio_sample_attributes.md)&nbsp;attrs,&nbsp;[out]&nbsp;[IAudioRender](interface_i_audio_render.md)&nbsp;render) | 创建一个音频播放接口的对象。 | 
| [DestroyRender](#destroyrender)&nbsp;() | 销毁一个音频播放接口的对象。 | 
| [CreateCapture](#createcapture)&nbsp;([in]&nbsp;struct&nbsp;[AudioDeviceDescriptor](_audio_device_descriptor.md)&nbsp;desc,&nbsp;[in]&nbsp;struct&nbsp;[AudioSampleAttributes](_audio_sample_attributes.md)&nbsp;attrs,&nbsp;[out]&nbsp;[IAudioCapture](interface_i_audio_capture.md)&nbsp;capture) | 创建一个音频录音接口的对象。 | 
| [DestroyCapture](#destroycapture)&nbsp;() | 销毁一个音频录音接口的对象。 | 
| [GetPortCapability](#getportcapability)&nbsp;([in]&nbsp;struct&nbsp;[AudioPort](_audio_port.md)&nbsp;port,&nbsp;[out]&nbsp;struct&nbsp;[AudioPortCapability](_audio_port_capability.md)&nbsp;capability) | 获取一个音频适配器的端口驱动的能力集。 | 
| [SetPassthroughMode](#setpassthroughmode)&nbsp;([in]&nbsp;struct&nbsp;[AudioPort](_audio_port.md)&nbsp;port,&nbsp;[in]&nbsp;enum&nbsp;[AudioPortPassthroughMode](_audio.md#audioportpassthroughmode)&nbsp;mode) | 设置音频端口驱动的数据透传模式。 | 
| [GetPassthroughMode](#getpassthroughmode)&nbsp;([in]&nbsp;struct&nbsp;[AudioPort](_audio_port.md)&nbsp;port,&nbsp;[out]&nbsp;enum&nbsp;[AudioPortPassthroughMode](_audio.md#audioportpassthroughmode)&nbsp;mode) | 获取音频端口驱动的数据透传模式。 | 
| [GetDeviceStatus](#getdevicestatus)&nbsp;([out]&nbsp;struct&nbsp;[AudioDeviceStatus](_audio_device_status.md)&nbsp;status) | 获取一个音频适配器的设备状态。 | 
| [UpdateAudioRoute](#updateaudioroute)&nbsp;([in]&nbsp;struct&nbsp;[AudioRoute](_audio_route.md)&nbsp;route,&nbsp;[out]&nbsp;int&nbsp;routeHandle) | 更新音频路由。 | 
| [ReleaseAudioRoute](#releaseaudioroute)&nbsp;([in]&nbsp;int&nbsp;routeHandle) | 释放音频路由。 | 
| [SetMicMute](#setmicmute)&nbsp;([in]&nbsp;boolean&nbsp;mute) | 设置音频静音。 | 
| [GetMicMute](#getmicmute)&nbsp;([out]&nbsp;boolean&nbsp;mute) | 获取音频静音状态。 | 
| [SetVoiceVolume](#setvoicevolume)&nbsp;([in]&nbsp;float&nbsp;volume) | 设置语音呼叫的音量。 | 
| [SetExtraParams](#setextraparams)&nbsp;([in]&nbsp;enum&nbsp;[AudioExtParamKey](_audio.md#audioextparamkey)&nbsp;key,&nbsp;[in]&nbsp;String&nbsp;condition,&nbsp;[in]&nbsp;String&nbsp;value) | 根据指定的条件设置音频拓展参数。 | 
| [GetExtraParams](#getextraparams)&nbsp;([in]&nbsp;enum&nbsp;[AudioExtParamKey](_audio.md#audioextparamkey)&nbsp;key,&nbsp;[in]&nbsp;String&nbsp;condition,&nbsp;[out]&nbsp;String&nbsp;value) | 根据指定条件获取音频扩展参数的取值。 | 
| [RegExtraParamObserver](#regextraparamobserver)&nbsp;([in]&nbsp;AudioCallback&nbsp;audioCallback,&nbsp;[in]&nbsp;byte&nbsp;cookie) | 注册扩展参数回调函数。 | 


## 成员函数说明


### CreateCapture()

  
```
IAudioAdapter::CreateCapture ([in] struct AudioDeviceDescriptor desc, [in] struct AudioSampleAttributes attrs, [out] IAudioCapture capture )
```

**描述:**

创建一个音频录音接口的对象。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| desc | 待打开的音频设备描述符，详请参考[AudioDeviceDescriptor](_audio_device_descriptor.md)。 | 
| attrs | 待打开的音频采样属性，详请参考[AudioSampleAttributes](_audio_sample_attributes.md)。 | 
| capture | 获取的音频录音接口的对象实例保存到capture中，详请参考[IAudioCapture](interface_i_audio_capture.md)。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[CreateCapture](#createcapture)


### CreateRender()

  
```
IAudioAdapter::CreateRender ([in] struct AudioDeviceDescriptor desc, [in] struct AudioSampleAttributes attrs, [out] IAudioRender render )
```

**描述:**

创建一个音频播放接口的对象。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| desc | 待打开的音频设备描述符，详请参考[AudioDeviceDescriptor](_audio_device_descriptor.md)。 | 
| attrs | 待打开的音频采样属性，详请参考[AudioSampleAttributes](_audio_sample_attributes.md)。 | 
| render | 获取的音频播放接口的对象实例保存到render中，详请参考[IAudioRender](interface_i_audio_render.md)。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[GetPortCapability](#getportcapability)

[DestroyRender](#destroyrender)


### DestroyCapture()

  
```
IAudioAdapter::DestroyCapture ()
```

**描述:**

销毁一个音频录音接口的对象。

**注意:**

在音频录音过程中，不能销毁该接口对象。

**返回:**

成功返回值0，失败返回负值。

**参见:**

[CreateCapture](#createcapture)


### DestroyRender()

  
```
IAudioAdapter::DestroyRender ()
```

**描述:**

销毁一个音频播放接口的对象。

**注意:**

在音频播放过程中，不能销毁该接口对象。

**返回:**

成功返回值0，失败返回负值。

**参见:**

[CreateRender](#createrender)


### GetDeviceStatus()

  
```
IAudioAdapter::GetDeviceStatus ([out] struct AudioDeviceStatus status)
```

**描述:**

获取一个音频适配器的设备状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| status | 获取的设备状态保存到status中，详请参考[AudioDeviceStatus](_audio_device_status.md)。 | 

**返回:**

成功返回值0，失败返回负值。


### GetExtraParams()

  
```
IAudioAdapter::GetExtraParams ([in] enum AudioExtParamKey key, [in] String condition, [out] String value )
```

**描述:**

根据指定条件获取音频扩展参数的取值。

- condition为多个键值对组成的字符串，多个键值对之间通过分号分割，键值对的格式为"keytype=keyvalue"。

- 当输入的key值为AudioExtParamKey::AUDIO_EXT_PARAM_KEY_VOLUME时，condition的格式必须为：
    EVENT_TYPE=xxx;VOLUME_GROUP_ID=xxx;AUDIO_VOLUME_TYPE=xxx;
  - EVENT_TYPE 表示音量事件类型: 其中1表示设置音量, 4表示设置静音。
  
  - VOLUME_GROUP_ID 表示待查询的音频扩展参数相关的音量组。
  
  - AUDIO_VOLUME_TYPE 表示待查询的音频扩展参数相关的音量类型。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| key | 指定的扩展参数键类型，详请参考[AudioExtParamKey](_audio.md#audioextparamkey)。 | 
| condition | 指定的扩展参数查询条件。 | 
| value | 待返回的指定扩展参数条件的当前值。 | 

**返回:**

成功返回值0，失败返回负值。


### GetMicMute()

  
```
IAudioAdapter::GetMicMute ([out] boolean mute)
```

**描述:**

获取音频静音状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| mute | 获取的静音状态保存到mute中，true表示静音，false表示非静音。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[GetMicMute](#getmicmute)


### GetPassthroughMode()

  
```
IAudioAdapter::GetPassthroughMode ([in] struct AudioPort port, [out] enum AudioPortPassthroughMode mode )
```

**描述:**

获取音频端口驱动的数据透传模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| port | 待获取的端口，详请参考[AudioPort](_audio_port.md)。 | 
| mode | 获取的传输模式保存到mode中，详请参考[AudioPortPassthroughMode](_audio.md#audioportpassthroughmode)。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[SetPassthroughMode](#setpassthroughmode)


### GetPortCapability()

  
```
IAudioAdapter::GetPortCapability ([in] struct AudioPort port, [out] struct AudioPortCapability capability )
```

**描述:**

获取一个音频适配器的端口驱动的能力集。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| port | 待获取的端口，详请参考[AudioPort](_audio_port.md)。 | 
| capability | 获取的端口能力保存到capability中，详请参考[AudioPortCapability](_audio_port_capability.md)。 | 

**返回:**

成功返回值0，失败返回负值。


### InitAllPorts()

  
```
IAudioAdapter::InitAllPorts ()
```

**描述:**

初始化一个音频适配器所有的端口驱动。

在音频服务中，调用其他驱动接口前需要先调用该接口检查端口是否已经初始化完成，如果端口没有初始化完成， 则需要等待一段时间（例如100ms）后重新进行检查，直到端口初始化完成后再继续操作。

**返回:**

初始化完成返回值0，初始化失败返回负值。


### RegExtraParamObserver()

  
```
IAudioAdapter::RegExtraParamObserver ([in] AudioCallback audioCallback, [in] byte cookie )
```

**描述:**

注册扩展参数回调函数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| audioCallback | 待注册的回调函数，详请参考[IAudioCallback](interface_i_audio_callback.md)。 | 
| cookie | 用于传递数据。 | 

**返回:**

成功返回值0，失败返回负值。


### ReleaseAudioRoute()

  
```
IAudioAdapter::ReleaseAudioRoute ([in] int routeHandle)
```

**描述:**

释放音频路由。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| routeHandle | 待释放的音频路由句柄。 | 

**返回:**

成功返回值0，失败返回负值。


### SetExtraParams()

  
```
IAudioAdapter::SetExtraParams ([in] enum AudioExtParamKey key, [in] String condition, [in] String value )
```

**描述:**

根据指定的条件设置音频拓展参数。

- condition为多个键值对组成的字符串，多个键值对之间通过分号分割，键值对的格式为"keytype=keyvalue"。

- 当输入的key值为AudioExtParamKey::AUDIO_EXT_PARAM_KEY_VOLUME时，condition的格式必须为：
    EVENT_TYPE=xxx;VOLUME_GROUP_ID=xxx;AUDIO_VOLUME_TYPE=xxx;
  - EVENT_TYPE 表示音量事件类型: 其中1表示设置音量, 4表示设置静音。
  
  - VOLUME_GROUP_ID 表示待设置的音频扩展参数相关的音量组。
  
  - AUDIO_VOLUME_TYPE 表示待设置的音频扩展参数相关的音量类型。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| key | 指定的扩展参数键类型，详请参考[AudioDrainNotifyType](_audio.md#audiodrainnotifytype)。 | 
| condition | 指定的扩展参数查询条件。 | 
| value | 指定的扩展参数条件值。 | 

**返回:**

成功返回值0，失败返回负值。


### SetMicMute()

  
```
IAudioAdapter::SetMicMute ([in] boolean mute)
```

**描述:**

设置音频静音。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| mute | 表示是否将音频静音，true表示静音，false表示非静音。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[SetMicMute](#setmicmute)


### SetPassthroughMode()

  
```
IAudioAdapter::SetPassthroughMode ([in] struct AudioPort port, [in] enum AudioPortPassthroughMode mode )
```

**描述:**

设置音频端口驱动的数据透传模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| port | 待设置的端口，详请参考[AudioPort](_audio_port.md)。 | 
| mode | 待设置的传输模式，详请参考[AudioDrainNotifyType](_audio.md#audiodrainnotifytype)。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[GetPassthroughMode](#getpassthroughmode)


### SetVoiceVolume()

  
```
IAudioAdapter::SetVoiceVolume ([in] float volume)
```

**描述:**

设置语音呼叫的音量。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| volume | 待设置的音量值，范围为（0.0-1.0），0.0表示最小音量值，1.0表示最大音量值。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[SetVoiceVolume](#setvoicevolume)


### UpdateAudioRoute()

  
```
IAudioAdapter::UpdateAudioRoute ([in] struct AudioRoute route, [out] int routeHandle )
```

**描述:**

更新音频路由。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| route | 待更新的路由，详请参考[AudioRoute](_audio_route.md)。 | 
| routeHandle | 更新后的音频路由句柄保存到routeHandle中。 | 

**返回:**

成功返回值0，失败返回负值。
