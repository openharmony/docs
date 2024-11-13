# IAudioAdapter


## 概述

AudioAdapter音频适配器接口。

提供音频适配器（声卡）对外支持的驱动能力，包括初始化端口、创建放音、创建录音、获取端口能力集等。

参见

[IAudioRender](interface_i_audio_render_v10.md)

[IAudioCapture](interface_i_audio_capture_v10.md)

**起始版本：** 4.0

**相关模块：**[HdiAudio](_hdi_audio_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [InitAllPorts](#initallports) () | 初始化一个音频适配器所有的端口驱动。 | 
| [CreateRender](#createrender) ([in] struct [AudioDeviceDescriptor](_audio_device_descriptor_v10.md) desc, [in] struct [AudioSampleAttributes](_audio_sample_attributes_v10.md) attrs, [out] [IAudioRender](interface_i_audio_render_v10.md) render, [out] unsigned int renderId) | 创建一个音频播放接口的对象。 | 
| [DestroyRender](#destroyrender) ([in] unsigned int renderId) | 销毁一个音频播放接口的对象。 | 
| [CreateCapture](#createcapture) ([in] struct [AudioDeviceDescriptor](_audio_device_descriptor_v10.md) desc, [in] struct [AudioSampleAttributes](_audio_sample_attributes_v10.md) attrs, [out] [IAudioCapture](interface_i_audio_capture_v10.md) capture, [out] unsigned int captureId) | 创建一个音频录音接口的对象。 | 
| [DestroyCapture](#destroycapture) ([in] unsigned int captureId) | 销毁一个音频录音接口的对象。 | 
| [GetPortCapability](#getportcapability) ([in] struct [AudioPort](_audio_port_v10.md) port, [out] struct [AudioPortCapability](_audio_port_capability_v10.md) capability) | 获取一个音频适配器的端口驱动的能力集。 | 
| [SetPassthroughMode](#setpassthroughmode) ([in] struct [AudioPort](_audio_port_v10.md) port, [in] enum [AudioPortPassthroughMode](_hdi_audio_v11.md#audioportpassthroughmode) mode) | 设置音频端口驱动的数据透传模式。 | 
| [GetPassthroughMode](#getpassthroughmode) ([in] struct [AudioPort](_audio_port_v10.md) port, [out] enum [AudioPortPassthroughMode](_hdi_audio_v11.md#audioportpassthroughmode) mode) | 获取音频端口驱动的数据透传模式。 | 
| [GetDeviceStatus](#getdevicestatus) ([out] struct [AudioDeviceStatus](_audio_device_status_v10.md) status) | 获取一个音频适配器的设备状态。 | 
| [UpdateAudioRoute](#updateaudioroute) ([in] struct [AudioRoute](_audio_route_v10.md) route, [out] int routeHandle) | 更新音频路由。 | 
| [ReleaseAudioRoute](#releaseaudioroute) ([in] int routeHandle) | 释放音频路由。 | 
| [SetMicMute](#setmicmute) ([in] boolean mute) | 设置音频静音。 | 
| [GetMicMute](#getmicmute) ([out] boolean mute) | 获取音频静音状态。 | 
| [SetVoiceVolume](#setvoicevolume) ([in] float volume) | 设置语音呼叫的音量。 | 
| [SetExtraParams](#setextraparams) ([in] enum [AudioExtParamKey](_hdi_audio_v11.md#audioextparamkey) key, [in] String condition, [in] String value) | 根据指定的条件设置音频拓展参数。 | 
| [GetExtraParams](#getextraparams) ([in] enum [AudioExtParamKey](_hdi_audio_v11.md#audioextparamkey) key, [in] String condition, [out] String value) | 根据指定条件获取音频扩展参数的取值。 | 
| [RegExtraParamObserver](#regextraparamobserver) ([in] [IAudioCallback](interface_i_audio_callback_v10.md) audioCallback, [in] byte cookie) | 注册扩展参数回调函数。 | 


## 成员函数说明


### CreateCapture()

```
IAudioAdapter::CreateCapture ([in] struct AudioDeviceDescriptor desc, [in] struct AudioSampleAttributes attrs, [out] IAudioCapture capture, [out] unsigned int captureId )
```

**描述**

创建一个音频录音接口的对象。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adapter | 调用当前函数的AudioAdapter指针对象，该参数在编译为C接口后产生。 | 
| desc | 待打开的音频设备描述符，详请参考[AudioDeviceDescriptor](_audio_device_descriptor_v10.md)。 | 
| attrs | 待打开的音频采样属性，详请参考[AudioSampleAttributes](_audio_sample_attributes_v10.md)。 | 
| capture | 获取的音频录音接口的对象实例保存到capture中，详请参考[IAudioCapture](interface_i_audio_capture_v10.md)。 | 
| captureId | 获取的音频录音接口的序号 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[GetPortCapability](#getportcapability)

[DestroyCapture](#destroycapture)


### CreateRender()

```
IAudioAdapter::CreateRender ([in] struct AudioDeviceDescriptor desc, [in] struct AudioSampleAttributes attrs, [out] IAudioRender render, [out] unsigned int renderId )
```

**描述**

创建一个音频播放接口的对象。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adapter | 调用当前函数的AudioAdapter指针对象，该参数在编译为C接口后产生。 | 
| desc | 待打开的音频设备描述符，详请参考[AudioDeviceDescriptor](_audio_device_descriptor_v10.md)。 | 
| attrs | 待打开的音频采样属性，详请参考[AudioSampleAttributes](_audio_sample_attributes_v10.md)。 | 
| render | 获取的音频播放接口的对象实例保存到render中，详请参考[IAudioRender](interface_i_audio_render_v10.md)。 | 
| renderId | 获取的音频播放接口序号。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[GetPortCapability](#getportcapability)

[DestroyRender](#destroyrender)


### DestroyCapture()

```
IAudioAdapter::DestroyCapture ([in] unsigned int captureId)
```

**描述**

销毁一个音频录音接口的对象。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adapter | 调用当前函数的AudioAdapter指针对象，该参数在编译为C接口后产生。 | 
| captureId | 待销毁的音频录音接口的序号 | 

**注意：**

在音频录音过程中，不能销毁该接口对象。

**返回：**

成功返回值0，失败返回负值。

**参见：**

[CreateCapture](#createcapture)


### DestroyRender()

```
IAudioAdapter::DestroyRender ([in] unsigned int renderId)
```

**描述**

销毁一个音频播放接口的对象。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adapter | 调用当前函数的AudioAdapter指针对象，该参数在编译为C接口后产生。 | 
| renderId | 待销毁的音频播放接口的序号 | 

**注意：**

在音频播放过程中，不能销毁该接口对象。

**返回：**

成功返回值0，失败返回负值。

**参见：**

[CreateRender](#createrender)


### GetDeviceStatus()

```
IAudioAdapter::GetDeviceStatus ([out] struct AudioDeviceStatus status)
```

**描述**

获取一个音频适配器的设备状态。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adapter | 调用当前函数的AudioAdapter指针对象，该参数在编译为C接口后产生。 | 
| status | 获取的设备状态保存到status中，详请参考[AudioDeviceStatus](_audio_device_status_v10.md)。 | 

**返回：**

成功返回值0，失败返回负值。


### GetExtraParams()

```
IAudioAdapter::GetExtraParams ([in] enum AudioExtParamKey key, [in] String condition, [out] String value )
```

**描述**

根据指定条件获取音频扩展参数的取值。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adapter | 调用当前函数的AudioAdapter指针对象，该参数在编译为C接口后产生。 | 
| key | 指定的扩展参数键类型，详请参考[AudioExtParamKey](_hdi_audio_v11.md#audioextparamkey)。 | 
| condition | 指定的扩展参数查询条件。<br/>condition为多个键值对组成的字符串，多个键值对之间通过分号分割，键值对的格式为"keytype=keyvalue"。 当输入的key值为AudioExtParamKey::AUDIO_EXT_PARAM_KEY_VOLUME时，condition的格式必须为： "EVENT_TYPE=xxx;VOLUME_GROUP_ID=xxx;AUDIO_VOLUME_TYPE=xxx;"<br/>- EVENT_TYPE 表示音量事件类型：其中1表示设置音量，4表示设置静音。<br/>- VOLUME_GROUP_ID 表示待查询的音频扩展参数相关的音量组。<br/>- AUDIO_VOLUME_TYPE 表示待查询的音频扩展参数相关的音量类型。 | 
| value | 待返回的指定扩展参数条件的当前值。 | 
| lenth | value的长度，该参数在编译为C接口后产生。 | 

**返回：**

成功返回值0，失败返回负值。


### GetMicMute()

```
IAudioAdapter::GetMicMute ([out] boolean mute)
```

**描述**

获取音频静音状态。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adapter | 调用当前函数的AudioAdapter指针对象，该参数在编译为C接口后产生。 | 
| mute | 获取的静音状态保存到mute中，true表示静音，false表示非静音。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[GetMicMute](#getmicmute)


### GetPassthroughMode()

```
IAudioAdapter::GetPassthroughMode ([in] struct AudioPort port, [out] enum AudioPortPassthroughMode mode )
```

**描述**

获取音频端口驱动的数据透传模式。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adapter | 调用当前函数的AudioAdapter指针对象，该参数在编译为C接口后产生。 | 
| port | 待获取的端口，详请参考[AudioPort](_audio_port_v10.md)。 | 
| mode | 获取的传输模式保存到mode中，详请参考[AudioPortPassthroughMode](_hdi_audio_v11.md#audioportpassthroughmode)。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[SetPassthroughMode](#setpassthroughmode)


### GetPortCapability()

```
IAudioAdapter::GetPortCapability ([in] struct AudioPort port, [out] struct AudioPortCapability capability )
```

**描述**

获取一个音频适配器的端口驱动的能力集。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adapter | 调用当前函数的AudioAdapter指针对象，该参数在编译为C接口后产生。 | 
| port | 待获取的端口，详请参考[AudioPort](_audio_port_v10.md)。 | 
| capability | 获取的端口能力保存到capability中，详请参考[AudioPortCapability](_audio_port_capability_v10.md)。 | 

**返回：**

成功返回值0，失败返回负值。


### InitAllPorts()

```
IAudioAdapter::InitAllPorts ()
```

**描述**

初始化一个音频适配器所有的端口驱动。

在音频服务中，调用其他驱动接口前需要先调用该接口检查端口是否已经初始化完成，如果端口没有初始化完成， 则需要等待一段时间（例如100ms）后重新进行检查，直到端口初始化完成后再继续操作。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adapter | 调用当前函数的AudioAdapter指针对象，该参数在编译为C接口后产生。 | 

**返回：**

初始化完成返回值0，初始化失败返回负值。


### RegExtraParamObserver()

```
IAudioAdapter::RegExtraParamObserver ([in] IAudioCallback audioCallback, [in] byte cookie )
```

**描述**

注册扩展参数回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adapter | 调用当前函数的AudioAdapter指针对象，该参数在编译为C接口后产生。 | 
| callback | 待注册的回调函数，详请参考[IAudioCallback](interface_i_audio_callback_v10.md)。 | 
| cookie | 用于传递数据。 | 

**返回：**

成功返回值0，失败返回负值。


### ReleaseAudioRoute()

```
IAudioAdapter::ReleaseAudioRoute ([in] int routeHandle)
```

**描述**

释放音频路由。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adapter | 调用当前函数的AudioAdapter指针对象，该参数在编译为C接口后产生。 | 
| routeHandle | 待释放的音频路由句柄。 | 

**返回：**

成功返回值0，失败返回负值。


### SetExtraParams()

```
IAudioAdapter::SetExtraParams ([in] enum AudioExtParamKey key, [in] String condition, [in] String value )
```

**描述**

根据指定的条件设置音频拓展参数。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adapter | 调用当前函数的AudioAdapter指针对象，该参数在编译为C接口后产生。 | 
| key | 指定的扩展参数键类型，详请参考[AudioExtParamKey](_hdi_audio_v11.md#audioextparamkey)。 | 
| condition | 指定的扩展参数查询条件。<br/>condition为多个键值对组成的字符串，多个键值对之间通过分号分割，键值对的格式为"keytype=keyvalue"。 当输入的key值为AudioExtParamKey::AUDIO_EXT_PARAM_KEY_VOLUME时，condition的格式必须为： "EVENT_TYPE=xxx;VOLUME_GROUP_ID=xxx;AUDIO_VOLUME_TYPE=xxx;"<br/>- EVENT_TYPE 表示音量事件类型：其中1表示设置音量，4表示设置静音。<br/>- VOLUME_GROUP_ID 表示待设置的音频扩展参数相关的音量组。<br/>- AUDIO_VOLUME_TYPE 表示待设置的音频扩展参数相关的音量类型。 | 
| value | 指定的扩展参数条件值。 | 

**返回：**

成功返回值0，失败返回负值。


### SetMicMute()

```
IAudioAdapter::SetMicMute ([in] boolean mute)
```

**描述**

设置音频静音。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adapter | 调用当前函数的AudioAdapter指针对象，该参数在编译为C接口后产生。 | 
| mute | 表示是否将音频静音，true表示静音，false表示非静音。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[SetMicMute](#setmicmute)


### SetPassthroughMode()

```
IAudioAdapter::SetPassthroughMode ([in] struct AudioPort port, [in] enum AudioPortPassthroughMode mode )
```

**描述**

设置音频端口驱动的数据透传模式。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adapter | 调用当前函数的AudioAdapter指针对象，该参数在编译为C接口后产生。 | 
| port | 待设置的端口，详请参考[AudioPort](_audio_port_v10.md)。 | 
| mode | 待设置的传输模式，详请参考[AudioPortPassthroughMode](_hdi_audio_v11.md#audioportpassthroughmode)。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[GetPassthroughMode](#getpassthroughmode)


### SetVoiceVolume()

```
IAudioAdapter::SetVoiceVolume ([in] float volume)
```

**描述**

设置语音呼叫的音量。

音量范围从0.0到1.0。如果音频服务中的音量水平在0到15的范围内， 0.0表示音频静音，1.0指示最大音量级别（15）。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adapter | 调用当前函数的AudioAdapter指针对象，该参数在编译为C接口后产生。 | 
| volume | 待设置的音量值，范围为（0.0-1.0），0.0表示最小音量值，1.0表示最大音量值。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

GetVolume


### UpdateAudioRoute()

```
IAudioAdapter::UpdateAudioRoute ([in] struct AudioRoute route, [out] int routeHandle )
```

**描述**

更新音频路由。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| adapter | 调用当前函数的AudioAdapter指针对象，该参数在编译为C接口后产生。 | 
| route | 待更新的路由，详请参考[AudioRoute](_audio_route_v10.md)。 | 
| routeHandle | 更新后的音频路由句柄保存到routeHandle中。 | 

**返回：**

成功返回值0，失败返回负值。
