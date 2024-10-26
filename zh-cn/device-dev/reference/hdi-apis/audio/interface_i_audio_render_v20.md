# IAudioRender


## 概述

AudioRender音频播放接口。

提供音频播放支持的驱动能力，包括音频控制、音频属性、音频场景、音频音量、获取硬件延迟时间、播放音频帧数据等。

**起始版本：** 4.1

**相关模块：**[HdiAudio](_hdi_audio_v20.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetLatency](#getlatency) ([out] unsigned int ms) | 获取音频硬件驱动的延迟时间。 | 
| [RenderFrame](#renderframe) ([in] byte[] frame, [out] unsigned long replyBytes) | 向音频驱动中播放一帧输出数据（放音，音频下行数据）。 | 
| [GetRenderPosition](#getrenderposition) ([out] unsigned long frames, [out] struct [AudioTimeStamp](_audio_time_stamp_v20.md) time) | 获取音频已输出的帧数。 | 
| [SetRenderSpeed](#setrenderspeed) ([in] float speed) | 设置一个音频的播放速度。 | 
| [GetRenderSpeed](#getrenderspeed) ([out] float speed) | 获取一个音频当前的播放速度。 | 
| [SetChannelMode](#setchannelmode) ([in] enum [AudioChannelMode](_hdi_audio_v20.md#audiochannelmode) mode) | 设置音频播放的通道模式。 | 
| [GetChannelMode](#getchannelmode) ([out] enum [AudioChannelMode](_hdi_audio_v20.md#audiochannelmode) mode) | 获取音频播放当前的通道模式。 | 
| [RegCallback](#regcallback) ([in] [IAudioCallback](interface_i_audio_callback_v20.md) audioCallback, [in] byte cookie) | 注册音频回调函数，用于放音过程中缓冲区数据写、DrainBuffer完成通知。 | 
| [DrainBuffer](#drainbuffer) ([out] enum [AudioDrainNotifyType](_hdi_audio_v20.md#audiodrainnotifytype) type) | 排空缓冲区中的数据。 | 
| [IsSupportsDrain](#issupportsdrain) ([out] boolean support) | 判断是否支持清空缓冲区数据的功能。 | 
| [CheckSceneCapability](#checkscenecapability) ([in] struct [AudioSceneDescriptor](_audio_scene_descriptor_v20.md) scene, [out] boolean supported) | 是否支持某个音频场景的配置。 | 
| [SelectScene](#selectscene) ([in] struct [AudioSceneDescriptor](_audio_scene_descriptor_v20.md) scene) | 选择音频场景。 | 
| [SetMute](#setmute) ([in] boolean mute) | 设置音频的静音状态。 | 
| [GetMute](#getmute) ([out] boolean mute) | 获取音频的静音状态。 | 
| [SetVolume](#setvolume) ([in] float volume) | 设置一个音频流的音量。 | 
| [GetVolume](#getvolume) ([out] float volume) | 获取一个音频流的音量。 | 
| [GetGainThreshold](#getgainthreshold) ([out] float min, [out] float max) | 获取音频流增益的阈值。 | 
| [GetGain](#getgain) ([out] float gain) | 获取音频流的增益。 | 
| [SetGain](#setgain) ([in] float gain) | 设置音频流的增益。 | 
| [GetFrameSize](#getframesize) ([out] unsigned long size) | 获取音频帧的大小。 | 
| [GetFrameCount](#getframecount) ([out] unsigned long count) | 获取音频buffer中的音频帧数。 | 
| [SetSampleAttributes](#setsampleattributes) ([in] struct [AudioSampleAttributes](_audio_sample_attributes_v20.md) attrs) | 设置音频采样的属性参数。 | 
| [GetSampleAttributes](#getsampleattributes) ([out] struct [AudioSampleAttributes](_audio_sample_attributes_v20.md) attrs) | 获取音频采样的属性参数。 | 
| [GetCurrentChannelId](#getcurrentchannelid) ([out] unsigned int channelId) | 获取音频的数据通道ID。 | 
| [SetExtraParams](#setextraparams) ([in] String keyValueList) | 设置音频拓展参数。 | 
| [GetExtraParams](#getextraparams) ([out] String keyValueList) | 获取音频拓展参数。 | 
| [ReqMmapBuffer](#reqmmapbuffer) ([in] int reqSize, [in] struct AudioMmapBufferDescriptor desc) | 请求mmap缓冲区。 | 
| [GetMmapPosition](#getmmapposition) ([out] unsigned long frames, [out] struct [AudioTimeStamp](_audio_time_stamp_v20.md) time) | 获取当前mmap的读/写位置。 | 
| [AddAudioEffect](#addaudioeffect) ([in] unsigned long effectid) | 添加音频效果。 | 
| [RemoveAudioEffect](#removeaudioeffect) ([in] unsigned long effectid) | 移除音频效果。 | 
| [GetFrameBufferSize](#getframebuffersize) ([out] unsigned long bufferSize) | 获取缓冲区大小。 | 
| [Start](#start) () | 启动一个音频播放或录音处理。 | 
| [Stop](#stop) () | 停止一个音频播放或录音处理。 | 
| [Pause](#pause) () | 暂停一个音频播放或录音处理。 | 
| [Resume](#resume) () | 恢复一个音频播放或录音处理。 | 
| [Flush](#flush) () | 刷新音频缓冲区buffer中的数据。 | 
| [TurnStandbyMode](#turnstandbymode) () | 设置或去设置设备的待机模式。 | 
| [AudioDevDump](#audiodevdump) ([in] int range, [in] int fd) | Dump音频设备信息。 | 
| [IsSupportsPauseAndResume](#issupportspauseandresume) ([out] boolean supportPause, [out] boolean supportResume) | 判断声卡是否支持音频播放的暂停和恢复功能 | 
| [SetBufferSize](#setbuffersize) ([in] unsigned int size) | 设置低功耗模式缓存长度。 | 


## 成员函数说明


### AddAudioEffect()

```
IAudioRender::AddAudioEffect ([in] unsigned long effectid)
```

**描述**

添加音频效果。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| effectid | 添加的音频效果实例标识符。 | 

**返回：**

成功返回值0，失败返回负值。


### AudioDevDump()

```
IAudioRender::AudioDevDump ([in] int range, [in] int fd )
```

**描述**

Dump音频设备信息。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| range | Dump信息范围，分为简要信息、全量信息。 | 
| fd | 指定Dump目标文件。 | 

**返回：**

成功返回值0，失败返回负值。


### CheckSceneCapability()

```
IAudioRender::CheckSceneCapability ([in] struct AudioSceneDescriptor scene, [out] boolean supported )
```

**描述**

是否支持某个音频场景的配置。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| scene | 待判断的音频场景描述符，详请参考[AudioSceneDescriptor](_audio_scene_descriptor_v20.md)。 | 
| supported | 是否支持的状态保存到supported中，true表示支持，false表示不支持。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[SelectScene](#selectscene)


### DrainBuffer()

```
IAudioRender::DrainBuffer ([out] enum AudioDrainNotifyType type)
```

**描述**

排空缓冲区中的数据。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| type | 播放结束的类型，详请参考[AudioDrainNotifyType](_hdi_audio_v20.md#audiodrainnotifytype)。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[RegCallback](#regcallback)


### Flush()

```
IAudioRender::Flush ()
```

**描述**

刷新音频缓冲区buffer中的数据。

**起始版本：** 4.1

**返回：**

成功返回值0，失败返回负值。


### GetChannelMode()

```
IAudioRender::GetChannelMode ([out] enum AudioChannelMode mode)
```

**描述**

获取音频播放当前的通道模式。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mode | 获取的通道模式保存到mode中，详请参考[AudioChannelMode](_hdi_audio_v20.md#audiochannelmode)。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[SetChannelMode](#setchannelmode)


### GetCurrentChannelId()

```
IAudioRender::GetCurrentChannelId ([out] unsigned int channelId)
```

**描述**

获取音频的数据通道ID。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| channelId | 获取的通道ID保存到channelId中。 | 

**返回：**

成功返回值0，失败返回负值。


### GetExtraParams()

```
IAudioRender::GetExtraParams ([out] String keyValueList)
```

**描述**

获取音频拓展参数。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyValueList | 拓展参数键值对字符串列表，格式为key=value，多个键值对通过分号分割。 | 

**返回：**

成功返回值0，失败返回负值。


### GetFrameBufferSize()

```
IAudioRender::GetFrameBufferSize ([out] unsigned long bufferSize)
```

**描述**

获取缓冲区大小。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| bufferSize | 获取的缓冲区大小保存在bufferSize中，单位为字节。 | 

**返回：**

成功返回值0，失败返回负值。


### GetFrameCount()

```
IAudioRender::GetFrameCount ([out] unsigned long count)
```

**描述**

获取音频buffer中的音频帧数。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| count | 一个音频buffer中包含的音频帧数，获取后保存到count中。 | 

**返回：**

成功返回值0，失败返回负值。


### GetFrameSize()

```
IAudioRender::GetFrameSize ([out] unsigned long size)
```

**描述**

获取音频帧的大小。

获取一帧音频数据的长度（字节数）。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| size | 获取的音频帧大小（字节数）保存到size中。 | 

**返回：**

成功返回值0，失败返回负值。


### GetGain()

```
IAudioRender::GetGain ([out] float gain)
```

**描述**

获取音频流的增益。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| gain | 保存当前获取到的增益到gain中。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[GetGainThreshold](#getgainthreshold)

[SetGain](#setgain)


### GetGainThreshold()

```
IAudioRender::GetGainThreshold ([out] float min, [out] float max )
```

**描述**

获取音频流增益的阈值。

在具体的功能实现中，可以根据芯片平台的实际情况来进行处理：

- 可以使用实际的增益值，例如增益的范围为-50db ~ 6db。

- 也可以将增益范围设定为0.0~1.0，如果增益的范围为-50db ~ 6db， 则增益的映射关系为0.0表示静音，1.0表示最大增益（6db）。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| min | 获取的音频增益的阈值下限保存到min中。 | 
| max | 获取的音频增益的阈值上限保存到max中。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[GetGain](#getgain)

[SetGain](#setgain)


### GetLatency()

```
IAudioRender::GetLatency ([out] unsigned int ms)
```

**描述**

获取音频硬件驱动的延迟时间。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ms | 获取的延迟时间（单位：毫秒）保存到ms中。 | 

**返回：**

成功返回值0，失败返回负值。


### GetMmapPosition()

```
IAudioRender::GetMmapPosition ([out] unsigned long frames, [out] struct AudioTimeStamp time )
```

**描述**

获取当前mmap的读/写位置。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| frames | 获取的音频帧计数保存到frames中。 | 
| time | 获取的关联时间戳保存到time中，详请参考[AudioTimeStamp](_audio_time_stamp_v20.md)。 | 

**返回：**

成功返回值0，失败返回负值。


### GetMute()

```
IAudioRender::GetMute ([out] boolean mute)
```

**描述**

获取音频的静音状态。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mute | 获取的静音状态保存到mute中，true表示静音操作、false表示取消静音操作。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[SetMute](#setmute)


### GetRenderPosition()

```
IAudioRender::GetRenderPosition ([out] unsigned long frames, [out] struct AudioTimeStamp time )
```

**描述**

获取音频已输出的帧数。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| frames | 获取的音频帧数保存到frames中，详请参考[AudioTimeStamp](_audio_time_stamp_v20.md)。 | 
| time | 获取的关联时间戳保存到time中。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[RenderFrame](#renderframe)


### GetRenderSpeed()

```
IAudioRender::GetRenderSpeed ([out] float speed)
```

**描述**

获取一个音频当前的播放速度。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| speed | 获取的播放速度保存到speed中。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[SetRenderSpeed](#setrenderspeed)


### GetSampleAttributes()

```
IAudioRender::GetSampleAttributes ([out] struct AudioSampleAttributes attrs)
```

**描述**

获取音频采样的属性参数。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| attrs | 获取的音频采样属性（例如采样频率、采样精度、通道） 保存到attrs中，详请参考[AudioSampleAttributes](_audio_sample_attributes_v20.md)。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[SetSampleAttributes](#setsampleattributes)


### GetVolume()

```
IAudioRender::GetVolume ([out] float volume)
```

**描述**

获取一个音频流的音量。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| volume | 获取的音量保存到volume中，范围0.0~1.0。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[SetVolume](#setvolume)


### IsSupportsDrain()

```
IAudioRender::IsSupportsDrain ([out] boolean support)
```

**描述**

判断是否支持清空缓冲区数据的功能。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| support | 是否支持的状态保存到support中，true表示支持，false表示不支持。 | 

**返回：**

成功返回值0，失败返回负值。


### IsSupportsPauseAndResume()

```
IAudioRender::IsSupportsPauseAndResume ([out] boolean supportPause, [out] boolean supportResume )
```

**描述**

判断声卡是否支持音频播放的暂停和恢复功能

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| supportPause | 是否支持暂停功能的状态保存到supportPause中，true表示支持，false表示不支持。 | 
| supportResume | 是否支持恢复功能的状态保存到supportResume中，true表示支持，false表示不支持。 | 

**返回：**

成功返回值0，失败返回负值。


### Pause()

```
IAudioRender::Pause ()
```

**描述**

暂停一个音频播放或录音处理。

**起始版本：** 4.1

**返回：**

成功返回值0，失败返回负值。

**参见：**

[Resume](#resume)


### RegCallback()

```
IAudioRender::RegCallback ([in] IAudioCallback audioCallback, [in] byte cookie )
```

**描述**

注册音频回调函数，用于放音过程中缓冲区数据写、DrainBuffer完成通知。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioCallback | 注册的回调函数，详请参考[IAudioCallback](interface_i_audio_callback_v20.md)。 | 
| cookie | 回调函数的入参。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[RegCallback](#regcallback)


### RemoveAudioEffect()

```
IAudioRender::RemoveAudioEffect ([in] unsigned long effectid)
```

**描述**

移除音频效果。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| effectid | 移除的音频效果实例标识符。 | 

**返回：**

成功返回值0，失败返回负值。


### RenderFrame()

```
IAudioRender::RenderFrame ([in] byte[] frame, [out] unsigned long replyBytes )
```

**描述**

向音频驱动中播放一帧输出数据（放音，音频下行数据）。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| frame | 待写入的输出数据的音频frame。 | 
| replyBytes | 实际写入的音频数据长度（字节数），获取后保存到replyBytes中。 | 

**返回：**

成功返回值0，失败返回负值。


### ReqMmapBuffer()

```
IAudioRender::ReqMmapBuffer ([in] int reqSize, [in] struct AudioMmapBufferDescriptor desc )
```

**描述**

请求mmap缓冲区。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| reqSize | 请求缓冲区的大小。 | 
| desc | 缓冲区描述符，详请参考**AudioMmapBufferDescriptor**。 | 

**返回：**

成功返回值0，失败返回负值。


### Resume()

```
IAudioRender::Resume ()
```

**描述**

恢复一个音频播放或录音处理。

**起始版本：** 4.1

**返回：**

成功返回值0，失败返回负值。

**参见：**

[Pause](#pause)


### SelectScene()

```
IAudioRender::SelectScene ([in] struct AudioSceneDescriptor scene)
```

**描述**

选择音频场景。

- 1. 选择一个非常具体的音频场景（应用场景和输出设备的组合），例如同样是使用手机中的喇叭作为输出设备。
  - 在媒体播放场景scene为media_speaker。
  - 在语音通话免提场景scene为voice_speaker。

- 2. 只是选择一个音频场景，例如使用场景为媒体播放（media）、电影播放（movie）、游戏播放（game）。

- 3. 只是选择一个音频输出设备，例如输出设备为听筒（receiver）、喇叭（speaker）、有线耳机（headset）。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| scene | 待设置的音频场景描述符，详请参考[AudioSceneDescriptor](_audio_scene_descriptor_v20.md)。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[CheckSceneCapability](#checkscenecapability)


### SetBufferSize()

```
IAudioRender::SetBufferSize ([in] unsigned int size)
```

**描述**

设置低功耗模式缓存长度。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| size | 包含音频数据的缓存长度。 | 

**返回：**

成功返回值0，失败返回负值。


### SetChannelMode()

```
IAudioRender::SetChannelMode ([in] enum AudioChannelMode mode)
```

**描述**

设置音频播放的通道模式。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mode | 待设置的通道模式，详请参考[AudioChannelMode](_hdi_audio_v20.md#audiochannelmode)。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[GetChannelMode](#getchannelmode)


### SetExtraParams()

```
IAudioRender::SetExtraParams ([in] String keyValueList)
```

**描述**

设置音频拓展参数。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyValueList | 拓展参数键值对字符串列表，格式为key=value，多个键值对通过分号分割。 | 

**返回：**

成功返回值0，失败返回负值。


### SetGain()

```
IAudioRender::SetGain ([in] float gain)
```

**描述**

设置音频流的增益。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| gain | 待设置的增益，最小为0.0，最大为1.0。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[GetGainThreshold](#getgainthreshold)

[GetGain](#getgain)


### SetMute()

```
IAudioRender::SetMute ([in] boolean mute)
```

**描述**

设置音频的静音状态。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mute | 待设置的静音状态，true表示静音操作、false表示取消静音操作。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[GetMute](#getmute)


### SetRenderSpeed()

```
IAudioRender::SetRenderSpeed ([in] float speed)
```

**描述**

设置一个音频的播放速度。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| speed | 待设置的播放速度（倍速），例0.5、0.75、1.0、1.25、1.5、2.0。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[GetRenderSpeed](#getrenderspeed)


### SetSampleAttributes()

```
IAudioRender::SetSampleAttributes ([in] struct AudioSampleAttributes attrs)
```

**描述**

设置音频采样的属性参数。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| attrs | 待设置的音频采样属性，例如采样频率、采样精度、通道，详请参考[AudioSampleAttributes](_audio_sample_attributes_v20.md)。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[GetSampleAttributes](#getsampleattributes)


### SetVolume()

```
IAudioRender::SetVolume ([in] float volume)
```

**描述**

设置一个音频流的音量。

音量的取值范围是0.0~1.0，如果音频服务中的音量等级为15级（0 ~ 15）， 则音量的映射关系为0.0表示静音，1.0表示最大音量等级（15）。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| volume | 待设置的音量，范围0.0~1.0。 | 

**返回：**

成功返回值0，失败返回负值。


### Start()

```
IAudioRender::Start ()
```

**描述**

启动一个音频播放或录音处理。

**起始版本：** 4.1

**返回：**

成功返回值0，失败返回负值。

**参见：**

[Stop](#stop)


### Stop()

```
IAudioRender::Stop ()
```

**描述**

停止一个音频播放或录音处理。

**起始版本：** 4.1

**返回：**

成功返回值0，失败返回负值。

**参见：**

[Start](#start)


### TurnStandbyMode()

```
IAudioRender::TurnStandbyMode ()
```

**描述**

设置或去设置设备的待机模式。

**起始版本：** 4.1

**返回：**

设置设备待机模式成功返回值0，失败返回负值；设置取消设备待机模式成功返回正值，失败返回负值。
