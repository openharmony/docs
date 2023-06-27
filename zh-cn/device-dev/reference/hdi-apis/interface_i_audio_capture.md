# IAudioCapture


## 概述

AudioCapture音频录音接口。

提供音频录音支持的驱动能力，包括音频控制、音频属性、音频场景、音频音量、录制音频帧数据等。

**Since:**

3.2

**Version:**

1.0

**相关模块:**

[Audio](_audio.md)


## 汇总


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [CaptureFrame](#captureframe)&nbsp;([out]&nbsp;byte[]&nbsp;frame,&nbsp;[in]&nbsp;unsigned&nbsp;long&nbsp;requestBytes) | 从音频驱动中录制一帧输入数据（录音，音频上行数据）。 | 
| [GetCapturePosition](#getcaptureposition)&nbsp;([out]&nbsp;unsigned&nbsp;long&nbsp;frames,&nbsp;[out]&nbsp;struct&nbsp;[AudioTimeStamp](_audio_time_stamp.md)&nbsp;time) | 获取音频已输入的帧数。 | 
| [CheckSceneCapability](#checkscenecapability)&nbsp;([in]&nbsp;struct&nbsp;[AudioSceneDescriptor](_audio_scene_descriptor.md)&nbsp;scene,&nbsp;[out]&nbsp;boolean&nbsp;supported) | 判断某个音频场景能力是否支持。 | 
| [SelectScene](#selectscene)&nbsp;([in]&nbsp;struct&nbsp;[AudioSceneDescriptor](_audio_scene_descriptor.md)&nbsp;scene) | 选择音频场景。 | 
| [SetMute](#setmute)&nbsp;([in]&nbsp;boolean&nbsp;mute) | 设置音频的静音状态。 | 
| [GetMute](#getmute)&nbsp;([out]&nbsp;boolean&nbsp;mute) | 获取音频的静音状态。 | 
| [SetVolume](#setvolume)&nbsp;([in]&nbsp;float&nbsp;volume) | 设置一个音频流的音量。 | 
| [GetVolume](#getvolume)&nbsp;([out]&nbsp;float&nbsp;volume) | 获取一个音频流的音量。 | 
| [GetGainThreshold](#getgainthreshold)&nbsp;([out]&nbsp;float&nbsp;min,&nbsp;[out]&nbsp;float&nbsp;max) | 获取音频流增益的阈值。 | 
| [GetGain](#getgain)&nbsp;([out]&nbsp;float&nbsp;gain) | 获取音频流的增益。 | 
| [SetGain](#setgain)&nbsp;([in]&nbsp;float&nbsp;gain) | 设置音频流的增益。 | 
| [GetFrameSize](#getframesize)&nbsp;([out]&nbsp;unsigned&nbsp;long&nbsp;size) | 获取一帧音频数据的长度（字节数）大小。 | 
| [GetFrameCount](#getframecount)&nbsp;([out]&nbsp;unsigned&nbsp;long&nbsp;count) | 获取音频buffer中的音频帧数。 | 
| [SetSampleAttributes](#setsampleattributes)&nbsp;([in]&nbsp;struct&nbsp;[AudioSampleAttributes](_audio_sample_attributes.md)&nbsp;attrs) | 设置音频采样的属性参数。 | 
| [GetSampleAttributes](#getsampleattributes)&nbsp;([out]&nbsp;struct&nbsp;[AudioSampleAttributes](_audio_sample_attributes.md)&nbsp;attrs) | 获取音频采样的属性参数。 | 
| [GetCurrentChannelId](#getcurrentchannelid)&nbsp;([out]&nbsp;unsigned&nbsp;int&nbsp;channelId) | 获取音频的数据通道ID。 | 
| [SetExtraParams](#setextraparams)&nbsp;([in]&nbsp;String&nbsp;keyValueList) | 设置音频拓展参数。 | 
| [GetExtraParams](#getextraparams)&nbsp;([out]&nbsp;String&nbsp;keyValueList) | 获取音频拓展参数。 | 
| [ReqMmapBuffer](#reqmmapbuffer)&nbsp;([in]&nbsp;int&nbsp;reqSize,&nbsp;[in]&nbsp;struct&nbsp;[AudioMmapBufferDescripter](_audio_mmap_buffer_descripter.md)&nbsp;desc) | 请求mmap缓冲区。 | 
| [GetMmapPosition](#getmmapposition)&nbsp;([out]&nbsp;unsigned&nbsp;long&nbsp;frames,&nbsp;[out]&nbsp;struct&nbsp;[AudioTimeStamp](_audio_time_stamp.md)&nbsp;time) | 获取当前mmap的读/写位置。 | 
| [AddAudioEffect](#addaudioeffect)&nbsp;([in]&nbsp;unsigned&nbsp;long&nbsp;effectid) | 添加音频效果。 | 
| [RemoveAudioEffect](#removeaudioeffect)&nbsp;([in]&nbsp;unsigned&nbsp;long&nbsp;effectid) | 移除音频效果。 | 
| [GetFrameBufferSize](#getframebuffersize)&nbsp;([out]&nbsp;unsigned&nbsp;long&nbsp;bufferSize) | 获取缓冲区大小。 | 
| [Start](#start)&nbsp;() | 启动一个音频播放或录音处理。 | 
| [Stop](#stop)&nbsp;() | 停止一个音频播放或录音处理。 | 
| [Pause](#pause)&nbsp;() | 暂停一个音频播放或录音处理。 | 
| [Resume](#resume)&nbsp;() | 恢复一个音频播放或录音处理。 | 
| [Flush](#flush)&nbsp;() | 刷新音频缓冲区buffer中的数据。 | 
| [TurnStandbyMode](#turnstandbymode)&nbsp;() | 设置或去设置设备的待机模式。 | 
| [AudioDevDump](#audiodevdump)&nbsp;([in]&nbsp;int&nbsp;range,&nbsp;[in]&nbsp;int&nbsp;fd) | 保存音频设备信息。 | 
| [IsSupportsPauseAndResume](#issupportspauseandresume)&nbsp;([out]&nbsp;boolean&nbsp;supportPause,&nbsp;[out]&nbsp;boolean&nbsp;supportResume) | 判断声卡是否支持音频录制的暂停和恢复功能。 | 


## 成员函数说明


### AddAudioEffect()

  
```
IAudioCapture::AddAudioEffect ([in] unsigned long effectid)
```

**描述:**

添加音频效果。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| effectid | 添加的音频效果实例标识符。 | 

**返回:**

成功返回值0，失败返回负值。


### AudioDevDump()

  
```
IAudioCapture::AudioDevDump ([in] int range, [in] int fd )
```

**描述:**

保存音频设备信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| range | 需要保存的信息范围（3&nbsp;~&nbsp;5），分为简要信息（3）、一般信息（4）、全量信息（5）。 | 
| fd | 保存到指定的目标文件。 | 

**返回:**

成功返回值0，失败返回负值。


### CaptureFrame()

  
```
IAudioCapture::CaptureFrame ([out] byte[] frame, [in] unsigned long requestBytes )
```

**描述:**

从音频驱动中录制一帧输入数据（录音，音频上行数据）。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| frame | 待存放输入数据的音频frame。 | 
| requestBytes | 待存放输入数据的音频frame大小（字节数）。 | 

**返回:**

成功返回值0，失败返回负值。


### CheckSceneCapability()

  
```
IAudioCapture::CheckSceneCapability ([in] struct AudioSceneDescriptor scene, [out] boolean supported )
```

**描述:**

判断某个音频场景能力是否支持。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| scene | 待判断的音频场景描述符，详请参考[AudioSceneDescriptor](_audio_scene_descriptor.md)。 | 
| supported | 是否支持的状态保存到supported中，true表示支持，false表示不支持。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[SelectScene](#selectscene)


### Flush()

  
```
IAudioCapture::Flush ()
```

**描述:**

刷新音频缓冲区buffer中的数据。

**返回:**

成功返回值0，失败返回负值。


### GetCapturePosition()

  
```
IAudioCapture::GetCapturePosition ([out] unsigned long frames, [out] struct AudioTimeStamp time )
```

**描述:**

获取音频已输入的帧数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| frames | 获取的音频帧数保存到frames中。 | 
| time | 获取的关联时间戳保存到time中，详请参考[AudioTimeStamp](_audio_time_stamp.md)。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[CaptureFrame](#captureframe)


### GetCurrentChannelId()

  
```
IAudioCapture::GetCurrentChannelId ([out] unsigned int channelId)
```

**描述:**

获取音频的数据通道ID。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| channelId | 获取的通道ID保存到channelId中。 | 

**返回:**

成功返回值0，失败返回负值。


### GetExtraParams()

  
```
IAudioCapture::GetExtraParams ([out] String keyValueList)
```

**描述:**

获取音频拓展参数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| keyValueList | 拓展参数键值对字符串列表，格式为key=value，多个键值对通过分号分割。 | 

**返回:**

成功返回值0，失败返回负值。


### GetFrameBufferSize()

  
```
IAudioCapture::GetFrameBufferSize ([out] unsigned long bufferSize)
```

**描述:**

获取缓冲区大小。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| bufferSize | 获取的缓冲区大小保存在bufferSize中，单位为字节。 | 

**返回:**

成功返回值0，失败返回负值。


### GetFrameCount()

  
```
IAudioCapture::GetFrameCount ([out] unsigned long count)
```

**描述:**

获取音频buffer中的音频帧数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| count | 一个音频buffer中包含的音频帧数，获取后保存到count中。 | 

**返回:**

成功返回值0，失败返回负值。


### GetFrameSize()

  
```
IAudioCapture::GetFrameSize ([out] unsigned long size)
```

**描述:**

获取一帧音频数据的长度（字节数）大小。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| size | 获取的音频帧大小（字节数）保存到size中。 | 

**返回:**

成功返回值0，失败返回负值。


### GetGain()

  
```
IAudioCapture::GetGain ([out] float gain)
```

**描述:**

获取音频流的增益。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| gain | 保存当前获取到的增益到gain中。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[GetGainThreshold](#getgainthreshold)

[SetGain](#setgain)


### GetGainThreshold()

  
```
IAudioCapture::GetGainThreshold ([out] float min, [out] float max )
```

**描述:**

获取音频流增益的阈值。

在具体的功能实现中，可以根据芯片平台的实际情况来进行处理：

- 可以使用实际的增益值，例如增益的范围为-50db ~ 6db。

- 也可以将增益范围设定为0.0~1.0，如果增益的范围为-50db ~ 6db， 则增益的映射关系为0.0表示静音（-50db），1.0表示最大增益（6db）。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| min | 获取的音频增益的阈值下限保存到min中。 | 
| max | 获取的音频增益的阈值上限保存到max中。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[GetGain](#getgain)

[SetGain](#setgain)


### GetMmapPosition()

  
```
IAudioCapture::GetMmapPosition ([out] unsigned long frames, [out] struct AudioTimeStamp time )
```

**描述:**

获取当前mmap的读/写位置。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| frames | 获取的音频帧计数保存到frames中。 | 
| time | 获取的关联时间戳保存到time中，详请参考[AudioTimeStamp](_audio_time_stamp.md)。 | 

**返回:**

成功返回值0，失败返回负值。


### GetMute()

  
```
IAudioCapture::GetMute ([out] boolean mute)
```

**描述:**

获取音频的静音状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| mute | 获取的静音状态保存到mute中，true表示静音操作、false表示取消静音操作。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[SetMute](#setmute)


### GetSampleAttributes()

  
```
IAudioCapture::GetSampleAttributes ([out] struct AudioSampleAttributes attrs)
```

**描述:**

获取音频采样的属性参数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| attrs | 获取的音频采样属性（例如采样频率、采样精度、通道）保存到attrs中，详请参考[AudioSampleAttributes](_audio_sample_attributes.md)。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[SetSampleAttributes](#setsampleattributes)


### GetVolume()

  
```
IAudioCapture::GetVolume ([out] float volume)
```

**描述:**

获取一个音频流的音量。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| volume | 获取的音量保存到volume中，范围0.0~1.0。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[SetVolume](#setvolume)


### IsSupportsPauseAndResume()

  
```
IAudioCapture::IsSupportsPauseAndResume ([out] boolean supportPause, [out] boolean supportResume )
```

**描述:**

判断声卡是否支持音频录制的暂停和恢复功能。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| supportPause | 是否支持暂停功能的状态保存到supportPause中，true表示支持，false表示不支持。 | 
| supportResume | 是否支持恢复功能的状态保存到supportResume中，true表示支持，false表示不支持。 | 

**返回:**

成功返回值0，失败返回负值。


### Pause()

  
```
IAudioCapture::Pause ()
```

**描述:**

暂停一个音频播放或录音处理。

**返回:**

成功返回值0，失败返回负值。

**参见:**

[Resume](#resume)


### RemoveAudioEffect()

  
```
IAudioCapture::RemoveAudioEffect ([in] unsigned long effectid)
```

**描述:**

移除音频效果。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| effectid | 移除的音频效果实例标识符。 | 

**返回:**

成功返回值0，失败返回负值。


### ReqMmapBuffer()

  
```
IAudioCapture::ReqMmapBuffer ([in] int reqSize, [in] struct AudioMmapBufferDescripter desc )
```

**描述:**

请求mmap缓冲区。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| reqSize | 请求缓冲区的大小，单位：字节。 | 
| desc | 缓冲区描述符，详请参考[AudioMmapBufferDescripter](_audio_mmap_buffer_descripter.md)。 | 

**返回:**

成功返回值0，失败返回负值。


### Resume()

  
```
IAudioCapture::Resume ()
```

**描述:**

恢复一个音频播放或录音处理。

**返回:**

成功返回值0，失败返回负值。

**参见:**

[Pause](#pause)


### SelectScene()

  
```
IAudioCapture::SelectScene ([in] struct AudioSceneDescriptor scene)
```

**描述:**

选择音频场景。

- 选择一个非常具体的音频场景（应用场景和输出设备的组合），例如同样是使用手机中的喇叭作为输出设备。
  - 在媒体播放场景中，scene为media_speaker。
  - 在语音通话免提场景中，scene为voice_speaker。

- 只是选择一个音频场景，例如使用场景为媒体播放（media）、电影播放（movie）、游戏播放（game）。

- 只是选择一个音频输出设备，例如输出设备为听筒（receiver）、喇叭（speaker）、有线耳机（headset）。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| scene | 待设置的音频场景描述符，详请参考[AudioSceneDescriptor](_audio_scene_descriptor.md)。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[CheckSceneCapability](#checkscenecapability)


### SetExtraParams()

  
```
IAudioCapture::SetExtraParams ([in] String keyValueList)
```

**描述:**

设置音频拓展参数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| keyValueList | 拓展参数键值对字符串列表，格式为key=value，多个键值对通过分号分割。 | 

**返回:**

成功返回值0，失败返回负值。


### SetGain()

  
```
IAudioCapture::SetGain ([in] float gain)
```

**描述:**

设置音频流的增益。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| gain | 待设置的增益，最小为0.0，最大为1.0。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[GetGainThreshold](#getgainthreshold)

[GetGain](#getgain)


### SetMute()

  
```
IAudioCapture::SetMute ([in] boolean mute)
```

**描述:**

设置音频的静音状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| mute | 待设置的静音状态，true表示静音操作、false表示取消静音操作。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[GetMute](#getmute)


### SetSampleAttributes()

  
```
IAudioCapture::SetSampleAttributes ([in] struct AudioSampleAttributes attrs)
```

**描述:**

设置音频采样的属性参数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| attrs | 待设置的音频采样属性，例如采样频率、采样精度、通道，详请参考[AudioSampleAttributes](_audio_sample_attributes.md)。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[GetSampleAttributes](#getsampleattributes)


### SetVolume()

  
```
IAudioCapture::SetVolume ([in] float volume)
```

**描述:**

设置一个音频流的音量。

音量的取值范围是0.0~1.0，如果音频服务中的音量等级范围是0 ~ 15， 则音量的映射关系为0.0（或0）表示静音，1.0（或15）表示最大音量等级。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| volume | 待设置的音量，范围0.0~1.0。 | 

**返回:**

成功返回值0，失败返回负值。


### Start()

  
```
IAudioCapture::Start ()
```

**描述:**

启动一个音频播放或录音处理。

**返回:**

成功返回值0，失败返回负值。

**参见:**

[Stop](#stop)


### Stop()

  
```
IAudioCapture::Stop ()
```

**描述:**

停止一个音频播放或录音处理。

**返回:**

成功返回值0，失败返回负值。

**参见:**

[Start](#start)


### TurnStandbyMode()

  
```
IAudioCapture::TurnStandbyMode ()
```

**描述:**

设置或去设置设备的待机模式。

**返回:**

设置设备待机模式成功返回值0，再次执行后去设置待机模式成功返回正值，失败返回负值。
