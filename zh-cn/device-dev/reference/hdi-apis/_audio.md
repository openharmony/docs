# Audio


## 概述

Audio模块接口定义。

音频接口涉及数据类型、驱动加载接口、驱动适配器接口、音频播放接口、音频录音接口等。

**Since:**

3.2

**Version:**

1.0


## 汇总


### 文件

  | 名称 | 描述 | 
| -------- | -------- |
| [AudioTypes.idl](_audio_types_8idl.md) | Audio模块接口定义中使用的数据类型。 | 
| [IAudioAdapter.idl](_i_audio_adapter_8idl.md) | Audio适配器的接口定义文件。 | 
| [IAudioCallback.idl](_i_audio_callback_8idl.md) | Audio播放的回调函数定义文件。 | 
| [IAudioCapture.idl](_i_audio_capture_8idl.md) | Audio录音的接口定义文件。 | 
| [IAudioManager.idl](_i_audio_manager_8idl.md) | Audio适配器管理及加载的接口定义文件。 | 
| [IAudioRender.idl](_i_audio_render_8idl.md) | Audio播放的接口定义文件。 | 


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [AudioDeviceStatus](_audio_device_status.md) | struct<br/>音频设备状态。 | 
| [SceneDesc](union_scene_desc.md) | union<br/>音频场景描述。 | 
| [AudioPort](_audio_port.md) | struct<br/>音频端口。 | 
| [AudioAdapterDescriptor](_audio_adapter_descriptor.md) | struct<br/>音频适配器描述符。 | 
| [AudioDeviceDescriptor](_audio_device_descriptor.md) | struct<br/>音频设备描述符。 | 
| [AudioSceneDescriptor](_audio_scene_descriptor.md) | struct<br/>音频场景描述符。 | 
| [AudioSampleAttributes](_audio_sample_attributes.md) | struct<br/>音频采样属性。 | 
| [AudioTimeStamp](_audio_time_stamp.md) | struct<br/>音频时间戳。 | 
| [AudioSubPortCapability](_audio_sub_port_capability.md) | struct<br/>音频子端口的支持能力。 | 
| [AudioPortCapability](_audio_port_capability.md) | struct<br/>音频端口的支持能力。 | 
| [AudioMmapBufferDescripter](_audio_mmap_buffer_descripter.md) | struct<br/>mmap缓冲区描述符。 | 
| [AudioDevExtInfo](_audio_dev_ext_info.md) | struct<br/>音频设备拓展信息。 | 
| [AudioMixExtInfo](_audio_mix_ext_info.md) | struct<br/>音轨拓展信息。 | 
| [AudioSessionExtInfo](_audio_session_ext_info.md) | struct<br/>会话拓展信息。 | 
| [AudioInfo](_audio_info.md) | struct<br/>音频端口特定信息。 | 
| [AudioRouteNode](_audio_route_node.md) | struct<br/>音频路由节点。 | 
| [AudioRoute](_audio_route.md) | struct<br/>音频路由信息。 | 
| [AudioEvent](_audio_event.md) | struct<br/>音频事件。 | 
| [IAudioAdapter](interface_i_audio_adapter.md) | interface<br/>AudioAdapter音频适配器接口。 | 
| [IAudioCallback](interface_i_audio_callback.md) | interface<br/>Audio回调接口。 | 
| [IAudioCapture](interface_i_audio_capture.md) | interface<br/>AudioCapture音频录音接口。 | 
| [IAudioManager](interface_i_audio_manager.md) | interface<br/>AudioManager音频适配器管理接口。 | 
| [IAudioRender](interface_i_audio_render.md) | interface<br/>AudioRender音频播放接口。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [AudioPortDirection](#audioportdirection)&nbsp;{&nbsp;PORT_OUT&nbsp;=&nbsp;1&nbsp;,&nbsp;PORT_IN&nbsp;=&nbsp;2&nbsp;,&nbsp;PORT_OUT_IN&nbsp;=&nbsp;3&nbsp;} | 音频端口的类型。 | 
| [AudioPortPin](#audioportpin)&nbsp;{<br/>PIN_NONE&nbsp;=&nbsp;0&nbsp;,&nbsp;PIN_OUT_SPEAKER&nbsp;=&nbsp;1&nbsp;,&nbsp;PIN_OUT_HEADSET&nbsp;=&nbsp;2&nbsp;,&nbsp;PIN_OUT_LINEOUT&nbsp;=&nbsp;4&nbsp;,<br/>PIN_OUT_HDMI&nbsp;=&nbsp;8&nbsp;,&nbsp;PIN_IN_MIC&nbsp;=&nbsp;134217729&nbsp;,&nbsp;PIN_IN_HS_MIC&nbsp;=&nbsp;134217730&nbsp;,&nbsp;PIN_IN_LINEIN&nbsp;=&nbsp;134217732&nbsp;,<br/>PIN_IN_USB_EXT&nbsp;=&nbsp;134217736<br/>} | 音频端口上的Pin脚。 | 
| [AudioCategory](#audiocategory)&nbsp;{&nbsp;AUDIO_IN_MEDIA&nbsp;=&nbsp;0&nbsp;,&nbsp;AUDIO_IN_COMMUNICATION&nbsp;=&nbsp;1&nbsp;,&nbsp;AUDIO_IN_RINGTONE&nbsp;=&nbsp;2&nbsp;,&nbsp;AUDIO_IN_CALL&nbsp;=&nbsp;3&nbsp;} | 音频类型（场景）。 | 
| [AudioFormat](#audioformat)&nbsp;{<br/>AUDIO_FORMAT_PCM_8_BIT&nbsp;=&nbsp;1&nbsp;,&nbsp;AUDIO_FORMAT_PCM_16_BIT&nbsp;=&nbsp;2&nbsp;,&nbsp;AUDIO_FORMAT_PCM_24_BIT&nbsp;=&nbsp;3&nbsp;,&nbsp;AUDIO_FORMAT_PCM_32_BIT&nbsp;=&nbsp;4&nbsp;,<br/>AUDIO_FORMAT_AAC_MAIN&nbsp;=&nbsp;16777217&nbsp;,&nbsp;AUDIO_FORMAT_AAC_LC&nbsp;=&nbsp;16777218&nbsp;,&nbsp;AUDIO_FORMAT_AAC_LD&nbsp;=&nbsp;16777219&nbsp;,&nbsp;AUDIO_FORMAT_AAC_ELD&nbsp;=&nbsp;16777220&nbsp;,<br/>AUDIO_FORMAT_AAC_HE_V1&nbsp;=&nbsp;16777221&nbsp;,&nbsp;AUDIO_FORMAT_AAC_HE_V2&nbsp;=&nbsp;16777222&nbsp;,&nbsp;AUDIO_FORMAT_G711A&nbsp;=&nbsp;33554433&nbsp;,&nbsp;AUDIO_FORMAT_G711U&nbsp;=&nbsp;33554434&nbsp;,<br/>AUDIO_FORMAT_G726&nbsp;=&nbsp;33554435<br/>} | 音频格式。 | 
| [AudioChannelMask](#audiochannelmask)&nbsp;{&nbsp;AUDIO_CHANNEL_FRONT_LEFT&nbsp;=&nbsp;1&nbsp;,&nbsp;AUDIO_CHANNEL_FRONT_RIGHT&nbsp;=&nbsp;2&nbsp;,&nbsp;AUDIO_CHANNEL_MONO&nbsp;=&nbsp;1&nbsp;,&nbsp;AUDIO_CHANNEL_STEREO&nbsp;=&nbsp;3&nbsp;} | 音频通道掩码。 | 
| [AudioSampleRatesMask](#audiosampleratesmask)&nbsp;{<br/>AUDIO_SAMPLE_RATE_MASK_8000&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;0&nbsp;,&nbsp;AUDIO_SAMPLE_RATE_MASK_12000&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;1&nbsp;,&nbsp;AUDIO_SAMPLE_RATE_MASK_11025&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;2&nbsp;,&nbsp;AUDIO_SAMPLE_RATE_MASK_16000&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;3&nbsp;,<br/>AUDIO_SAMPLE_RATE_MASK_22050&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;4&nbsp;,&nbsp;AUDIO_SAMPLE_RATE_MASK_24000&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;5&nbsp;,&nbsp;AUDIO_SAMPLE_RATE_MASK_32000&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;6&nbsp;,&nbsp;AUDIO_SAMPLE_RATE_MASK_44100&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;7&nbsp;,<br/>AUDIO_SAMPLE_RATE_MASK_48000&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;8&nbsp;,&nbsp;AUDIO_SAMPLE_RATE_MASK_64000&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;9&nbsp;,&nbsp;AUDIO_SAMPLE_RATE_MASK_96000&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;10&nbsp;,&nbsp;AUDIO_SAMPLE_RATE_MASK_INVALID&nbsp;=&nbsp;4294967295<br/>} | 音频采样频率掩码。 | 
| [AudioPortPassthroughMode](#audioportpassthroughmode)&nbsp;{&nbsp;PORT_PASSTHROUGH_LPCM&nbsp;=&nbsp;1&nbsp;,&nbsp;PORT_PASSTHROUGH_RAW&nbsp;=&nbsp;2&nbsp;,&nbsp;PORT_PASSTHROUGH_HBR2LBR&nbsp;=&nbsp;4&nbsp;,&nbsp;PORT_PASSTHROUGH_AUTO&nbsp;=&nbsp;8&nbsp;} | 音频端口的数据透传模式。 | 
| [AudioDeviceType](#audiodevicetype)&nbsp;{<br/>AUDIO_LINEOUT&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;0&nbsp;,&nbsp;AUDIO_HEADPHONE&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;1&nbsp;,&nbsp;AUDIO_HEADSET&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;2&nbsp;,&nbsp;AUDIO_USB_HEADSET&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;3&nbsp;,<br/>AUDIO_USB_HEADPHONE&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;4&nbsp;,&nbsp;AUDIO_USBA_HEADSET&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;5&nbsp;,&nbsp;AUDIO_USBA_HEADPHONE&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;6&nbsp;,&nbsp;AUDIO_PRIMARY_DEVICE&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;7&nbsp;,<br/>AUDIO_USB_DEVICE&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;8&nbsp;,&nbsp;AUDIO_A2DP_DEVICE&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;9&nbsp;,&nbsp;AUDIO_DEVICE_UNKOWN<br/>} | 音频设备类型。 | 
| [AudioEventType](#audioeventtype)&nbsp;{<br/>AUDIO_DEVICE_ADD&nbsp;=&nbsp;1&nbsp;,&nbsp;AUDIO_DEVICE_REMOVE&nbsp;=&nbsp;2&nbsp;,&nbsp;AUDIO_LOAD_SUCCESS&nbsp;=&nbsp;3&nbsp;,&nbsp;AUDIO_LOAD_FAILURE&nbsp;=&nbsp;4&nbsp;,<br/>AUDIO_UNLOAD&nbsp;=&nbsp;5&nbsp;,&nbsp;AUDIO_SERVICE_VALID&nbsp;=&nbsp;7&nbsp;,&nbsp;AUDIO_SERVICE_INVALID&nbsp;=&nbsp;8&nbsp;,&nbsp;AUDIO_CAPTURE_THRESHOLD&nbsp;=&nbsp;9&nbsp;,<br/>AUDIO_EVENT_UNKOWN&nbsp;=&nbsp;10<br/>} | 音频事件类型。 | 
| [AudioExtParamKey](#audioextparamkey)&nbsp;{<br/>AUDIO_EXT_PARAM_KEY_NONE&nbsp;=&nbsp;0&nbsp;,&nbsp;AUDIO_EXT_PARAM_KEY_VOLUME&nbsp;=&nbsp;1&nbsp;,&nbsp;AUDIO_EXT_PARAM_KEY_FOCUS&nbsp;=&nbsp;2&nbsp;,&nbsp;AUDIO_EXT_PARAM_KEY_BUTTON&nbsp;=&nbsp;3&nbsp;,<br/>AUDIO_EXT_PARAM_KEY_EFFECT&nbsp;=&nbsp;4&nbsp;,&nbsp;AUDIO_EXT_PARAM_KEY_STATUS&nbsp;=&nbsp;5&nbsp;,&nbsp;AUDIO_EXT_PARAM_KEY_LOWPOWER&nbsp;=&nbsp;1000<br/>} | 音频扩展参数键类型。 | 
| [AudioSampleFormat](#audiosampleformat)&nbsp;{<br/>AUDIO_SAMPLE_FORMAT_S8&nbsp;=&nbsp;0&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_S8P&nbsp;=&nbsp;1&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_U8&nbsp;=&nbsp;2&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_U8P&nbsp;=&nbsp;3&nbsp;,<br/>AUDIO_SAMPLE_FORMAT_S16&nbsp;=&nbsp;4&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_S16P&nbsp;=&nbsp;5&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_U16&nbsp;=&nbsp;6&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_U16P&nbsp;=&nbsp;7&nbsp;,<br/>AUDIO_SAMPLE_FORMAT_S24&nbsp;=&nbsp;8&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_S24P&nbsp;=&nbsp;9&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_U24&nbsp;=&nbsp;10&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_U24P&nbsp;=&nbsp;11&nbsp;,<br/>AUDIO_SAMPLE_FORMAT_S32&nbsp;=&nbsp;12&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_S32P&nbsp;=&nbsp;13&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_U32&nbsp;=&nbsp;14&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_U32P&nbsp;=&nbsp;15&nbsp;,<br/>AUDIO_SAMPLE_FORMAT_S64&nbsp;=&nbsp;16&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_S64P&nbsp;=&nbsp;17&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_U64&nbsp;=&nbsp;18&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_U64P&nbsp;=&nbsp;19&nbsp;,<br/>AUDIO_SAMPLE_FORMAT_F32&nbsp;=&nbsp;20&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_F32P&nbsp;=&nbsp;21&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_F64&nbsp;=&nbsp;22&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_F64P&nbsp;=&nbsp;23<br/>} | 原始音频样本格式。 | 
| [AudioChannelMode](#audiochannelmode)&nbsp;{<br/>AUDIO_CHANNEL_NORMAL&nbsp;=&nbsp;0&nbsp;,&nbsp;AUDIO_CHANNEL_BOTH_LEFT&nbsp;,&nbsp;AUDIO_CHANNEL_BOTH_RIGHT&nbsp;,&nbsp;AUDIO_CHANNEL_EXCHANGE&nbsp;,<br/>AUDIO_CHANNEL_MIX&nbsp;,&nbsp;AUDIO_CHANNEL_LEFT_MUTE&nbsp;,&nbsp;AUDIO_CHANNEL_RIGHT_MUTE&nbsp;,&nbsp;AUDIO_CHANNEL_BOTH_MUTE<br/>} | 音频播放的通道模式。 | 
| [AudioDrainNotifyType](#audiodrainnotifytype)&nbsp;{&nbsp;AUDIO_DRAIN_NORMAL_MODE&nbsp;,&nbsp;AUDIO_DRAIN_EARLY_MODE&nbsp;} | 音频数据结束类型。 | 
| [AudioCallbackType](#audiocallbacktype)&nbsp;{<br/>AUDIO_NONBLOCK_WRITE_COMPELETED&nbsp;,&nbsp;AUDIO_DRAIN_COMPELETED&nbsp;,&nbsp;AUDIO_FLUSH_COMPLETED&nbsp;,&nbsp;AUDIO_RENDER_FULL&nbsp;,<br/>AUDIO_ERROR_OCCUR<br/>} | 回调函数通知事件类型。 | 
| [AudioPortRole](#audioportrole)&nbsp;{&nbsp;AUDIO_PORT_UNASSIGNED_ROLE&nbsp;=&nbsp;0&nbsp;,&nbsp;AUDIO_PORT_SOURCE_ROLE&nbsp;=&nbsp;1&nbsp;,&nbsp;AUDIO_PORT_SINK_ROLE&nbsp;=&nbsp;2&nbsp;} | 音频端口角色。 | 
| [AudioPortType](#audioporttype)&nbsp;{&nbsp;AUDIO_PORT_UNASSIGNED_TYPE&nbsp;=&nbsp;0&nbsp;,&nbsp;AUDIO_PORT_DEVICE_TYPE&nbsp;=&nbsp;1&nbsp;,&nbsp;AUDIO_PORT_MIX_TYPE&nbsp;=&nbsp;2&nbsp;,&nbsp;AUDIO_PORT_SESSION_TYPE&nbsp;=&nbsp;3&nbsp;} | 音频端口类型。 | 
| [AudioSessionType](#audiosessiontype)&nbsp;{&nbsp;AUDIO_OUTPUT_STAGE_SESSION&nbsp;=&nbsp;0&nbsp;,&nbsp;AUDIO_OUTPUT_MIX_SESSION&nbsp;,&nbsp;AUDIO_ALLOCATE_SESSION&nbsp;,&nbsp;AUDIO_INVALID_SESSION&nbsp;} | 端口会话类型。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.audio.v1_0 | 音频接口的包路径。 | 


## 枚举类型说明


### AudioCallbackType


```
enum AudioCallbackType
```

**描述:**

回调函数通知事件类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_NONBLOCK_WRITE_COMPELETED | 非阻塞式写完成。 | 
| AUDIO_DRAIN_COMPELETED | DrainBuffer完成，详情参考[DrainBuffer()](interface_i_audio_render.md#drainbuffer)。 | 
| AUDIO_FLUSH_COMPLETED | Flush完成，详情参考[Flush()](interface_i_audio_capture.md#flush)。 | 
| AUDIO_RENDER_FULL | 录音缓冲区已满。 | 
| AUDIO_ERROR_OCCUR | 发生了错误。 | 


### AudioCategory


```
enum AudioCategory
```

**描述:**

音频类型（场景）。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_IN_MEDIA | 媒体。 | 
| AUDIO_IN_COMMUNICATION | 通信。 | 
| AUDIO_IN_RINGTONE | 电话铃声。 | 
| AUDIO_IN_CALL | 呼叫。 | 


### AudioChannelMask


```
enum AudioChannelMask
```

**描述:**

音频通道掩码。

定义音频声道的位置掩码。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_CHANNEL_FRONT_LEFT | 声道布局前左。 | 
| AUDIO_CHANNEL_FRONT_RIGHT | 声道布局前右。 | 
| AUDIO_CHANNEL_MONO | 单声道。 | 
| AUDIO_CHANNEL_STEREO | 立体声，由左右声道组成。 | 


### AudioChannelMode


```
enum AudioChannelMode
```

**描述:**

音频播放的通道模式。

**注意:**

下面的模式是针对双通道立体声的音频播放而设置，其他不支持。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_CHANNEL_NORMAL | 正常模式，不做处理。 | 
| AUDIO_CHANNEL_BOTH_LEFT | 两个声道全部为左声道声音。 | 
| AUDIO_CHANNEL_BOTH_RIGHT | 两个声道全部为右声道声音。 | 
| AUDIO_CHANNEL_EXCHANGE | 左右声道数据互换，左声道为右声道声音，右声道为左声道声音。 | 
| AUDIO_CHANNEL_MIX | 左右两个声道输出为左右声道相加（混音）。 | 
| AUDIO_CHANNEL_LEFT_MUTE | 左声道静音，右声道播放原右声道声音。 | 
| AUDIO_CHANNEL_RIGHT_MUTE | 右声道静音，左声道播放原左声道声音。 | 
| AUDIO_CHANNEL_BOTH_MUTE | 左右声道均静音。 | 


### AudioDeviceType


```
enum AudioDeviceType
```

**描述:**

音频设备类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_LINEOUT | LINEOUT设备。 | 
| AUDIO_HEADPHONE | 耳机。 | 
| AUDIO_HEADSET | 头戴式耳机。 | 
| AUDIO_USB_HEADSET | USB头戴式耳机。 | 
| AUDIO_USB_HEADPHONE | USB耳机。 | 
| AUDIO_USBA_HEADSET | USB模拟头戴式耳机。 | 
| AUDIO_USBA_HEADPHONE | USB模拟耳机。 | 
| AUDIO_PRIMARY_DEVICE | 主音频设备。 | 
| AUDIO_USB_DEVICE | USB音频设备。 | 
| AUDIO_A2DP_DEVICE | 蓝牙音频设备。 | 
| AUDIO_DEVICE_UNKOWN | 未知设备。 | 


### AudioDrainNotifyType


```
enum AudioDrainNotifyType
```

**描述:**

音频数据结束类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_DRAIN_NORMAL_MODE | 曲目的所有数据播放完就结束。 | 
| AUDIO_DRAIN_EARLY_MODE | 曲目的所有数据未播放完就结束，以便给音频服务做连续性曲目切换留出时间。 | 


### AudioEventType


```
enum AudioEventType
```

**描述:**

音频事件类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_DEVICE_ADD | 音频设备添加。 | 
| AUDIO_DEVICE_REMOVE | 音频设备移除。 | 
| AUDIO_LOAD_SUCCESS | 声卡加载成功。 | 
| AUDIO_LOAD_FAILURE | 声卡加载失败。 | 
| AUDIO_UNLOAD | 声卡卸载。 | 
| AUDIO_SERVICE_VALID | 音频服务可用。 | 
| AUDIO_SERVICE_INVALID | 音频服务不可用。 | 
| AUDIO_CAPTURE_THRESHOLD | 录音阈值上报。 | 
| AUDIO_EVENT_UNKOWN | 未知事件。 | 


### AudioExtParamKey


```
enum AudioExtParamKey
```

**描述:**

音频扩展参数键类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_EXT_PARAM_KEY_NONE | 分布式音频-无效事件。 | 
| AUDIO_EXT_PARAM_KEY_VOLUME | 分布式音频-音量事件。 | 
| AUDIO_EXT_PARAM_KEY_FOCUS | 分布式音频-焦点事件。 | 
| AUDIO_EXT_PARAM_KEY_BUTTON | 分布式音频-媒体按钮事件。 | 
| AUDIO_EXT_PARAM_KEY_EFFECT | 分布式音频-音频效果事件。 | 
| AUDIO_EXT_PARAM_KEY_STATUS | 分布式音频-设备状态事件。 | 
| AUDIO_EXT_PARAM_KEY_LOWPOWER | 低电量事件。 | 


### AudioFormat


```
enum AudioFormat
```

**描述:**

音频格式。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_FORMAT_PCM_8_BIT | 8bit位宽PCM（Pulse&nbsp;Code&nbsp;Modulation）格式。 | 
| AUDIO_FORMAT_PCM_16_BIT | 16bit位宽PCM格式。 | 
| AUDIO_FORMAT_PCM_24_BIT | 24bit位宽PCM格式。 | 
| AUDIO_FORMAT_PCM_32_BIT | 32bit位宽PCM格式。 | 
| AUDIO_FORMAT_AAC_MAIN | AAC（Advanced&nbsp;Audio&nbsp;Coding）&nbsp;MAIN格式。 | 
| AUDIO_FORMAT_AAC_LC | AAC&nbsp;LC格式。 | 
| AUDIO_FORMAT_AAC_LD | AAC&nbsp;LD格式。 | 
| AUDIO_FORMAT_AAC_ELD | AAC&nbsp;ELD格式。 | 
| AUDIO_FORMAT_AAC_HE_V1 | AAC&nbsp;HE_V1格式。 | 
| AUDIO_FORMAT_AAC_HE_V2 | AAC&nbsp;HE_V2格式。 | 
| AUDIO_FORMAT_G711A | PCM&nbsp;G711A格式。 | 
| AUDIO_FORMAT_G711U | PCM&nbsp;G711u格式。 | 
| AUDIO_FORMAT_G726 | PCM&nbsp;G726格式。 | 


### AudioPortDirection


```
enum AudioPortDirection
```

**描述:**

音频端口的类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| PORT_OUT | 音频输出端口。 | 
| PORT_IN | 音频输入端口。 | 
| PORT_OUT_IN | 音频输出输入端口。 | 


### AudioPortPassthroughMode


```
enum AudioPortPassthroughMode
```

**描述:**

音频端口的数据透传模式。

  | 枚举值 | 描述 | 
| -------- | -------- |
| PORT_PASSTHROUGH_LPCM | 立体声PCM。 | 
| PORT_PASSTHROUGH_RAW | HDMI透传。 | 
| PORT_PASSTHROUGH_HBR2LBR | 蓝光次世代音频降规格输出。 | 
| PORT_PASSTHROUGH_AUTO | 根据HDMI&nbsp;EDID能力自动匹配。 | 


### AudioPortPin


```
enum AudioPortPin
```

**描述:**

音频端口上的Pin脚。

  | 枚举值 | 描述 | 
| -------- | -------- |
| PIN_NONE | 无效端口。 | 
| PIN_OUT_SPEAKER | 喇叭输出。 | 
| PIN_OUT_HEADSET | 有线耳机输出。 | 
| PIN_OUT_LINEOUT | Lineout输出。 | 
| PIN_OUT_HDMI | HDMI输出。 | 
| PIN_IN_MIC | 麦克风输入。 | 
| PIN_IN_HS_MIC | 有线耳机麦克风输入。 | 
| PIN_IN_LINEIN | Linein输入。 | 
| PIN_IN_USB_EXT | USB外部声卡输出。 | 


### AudioPortRole


```
enum AudioPortRole
```

**描述:**

音频端口角色。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_PORT_UNASSIGNED_ROLE | 未指定端口角色。 | 
| AUDIO_PORT_SOURCE_ROLE | 指定端口为发送端角色。 | 
| AUDIO_PORT_SINK_ROLE | 指定端口为接受端角色。 | 


### AudioPortType


```
enum AudioPortType
```

**描述:**

音频端口类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_PORT_UNASSIGNED_TYPE | 未指定端口类型。 | 
| AUDIO_PORT_DEVICE_TYPE | 指定端口为设备类型。 | 
| AUDIO_PORT_MIX_TYPE | 指定端口为复合类型。 | 
| AUDIO_PORT_SESSION_TYPE | 指定端口为会话类型。 | 


### AudioSampleFormat


```
enum AudioSampleFormat
```

**描述:**

原始音频样本格式。

| 枚举值 | 描述 |
| -------- | -------- |
| AUDIO_SAMPLE_FORMAT_S8 | 8bit位宽有符号交织样本。 |
| AUDIO_SAMPLE_FORMAT_S8P | 8bit位宽有符号非交织样本。 |
| AUDIO_SAMPLE_FORMAT_U8 | 8bit位宽无符号交织样本。 |
| AUDIO_SAMPLE_FORMAT_U8P | 8bit位宽无符号非交织样本。 |
| AUDIO_SAMPLE_FORMAT_S16 | 16bit位宽有符号交织样本。 |
| AUDIO_SAMPLE_FORMAT_S16P | 16bit位宽有符号非交织样本。 |
| AUDIO_SAMPLE_FORMAT_U16 | 16bit位宽无符号交织样本。 |
| AUDIO_SAMPLE_FORMAT_U16P | 16bit位宽无符号非交织样本。 |
| AUDIO_SAMPLE_FORMAT_S24 | 24bit位宽有符号交织样本。 |
| AUDIO_SAMPLE_FORMAT_S24P | 24bit位宽有符号非交织样本。 |
| AUDIO_SAMPLE_FORMAT_U24 | 24bit位宽无符号交织样本。 |
| AUDIO_SAMPLE_FORMAT_U24P | 24bit位宽无符号非交织样本。 |
| AUDIO_SAMPLE_FORMAT_S32 | 32bit位宽有符号交织样本。 |
| AUDIO_SAMPLE_FORMAT_S32P | 32bit位宽有符号非交织样本。 |
| AUDIO_SAMPLE_FORMAT_U32 | 32bit位宽无符号交织样本。 |
| AUDIO_SAMPLE_FORMAT_U32P | 32bit位宽无符号非交织样本。 |
| AUDIO_SAMPLE_FORMAT_S64 | 64bit位宽有符号交织样本。 |
| AUDIO_SAMPLE_FORMAT_S64P | 64bit位宽有符号非交织样本。 |
| AUDIO_SAMPLE_FORMAT_U64 | 64bit位宽无符号交织样本。 |
| AUDIO_SAMPLE_FORMAT_U64P | 64bit位宽无符号非交织样本。 |
| AUDIO_SAMPLE_FORMAT_F32 | 32bit位宽浮点型交织样本。 |
| AUDIO_SAMPLE_FORMAT_F32P | 64bit位宽浮点型非交织样本。 |
| AUDIO_SAMPLE_FORMAT_F64 | 64bit位宽双精度浮点型交织样本。 |
| AUDIO_SAMPLE_FORMAT_F64P | 64bit位宽双精度浮点型非交织样本。 |


### AudioSampleRatesMask


```
enum AudioSampleRatesMask
```

**描述:**

音频采样频率掩码。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_SAMPLE_RATE_MASK_8000 | 8K&nbsp;采样频率。 | 
| AUDIO_SAMPLE_RATE_MASK_12000 | 12K&nbsp;采样频率。 | 
| AUDIO_SAMPLE_RATE_MASK_11025 | 11.025K&nbsp;采样频率。 | 
| AUDIO_SAMPLE_RATE_MASK_16000 | 16K&nbsp;采样频率。 | 
| AUDIO_SAMPLE_RATE_MASK_22050 | 22.050K&nbsp;采样频率。 | 
| AUDIO_SAMPLE_RATE_MASK_24000 | 24K&nbsp;采样频率。 | 
| AUDIO_SAMPLE_RATE_MASK_32000 | 32K&nbsp;采样频率。 | 
| AUDIO_SAMPLE_RATE_MASK_44100 | 44.1K&nbsp;采样频率。 | 
| AUDIO_SAMPLE_RATE_MASK_48000 | 48K&nbsp;采样频率。 | 
| AUDIO_SAMPLE_RATE_MASK_64000 | 64K&nbsp;采样频率。 | 
| AUDIO_SAMPLE_RATE_MASK_96000 | 96K&nbsp;采样频率。 | 
| AUDIO_SAMPLE_RATE_MASK_INVALID | 无效的采样频率。 | 


### AudioSessionType


```
enum AudioSessionType
```

**描述:**

端口会话类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_OUTPUT_STAGE_SESSION | 会话绑定到指定输出流。 | 
| AUDIO_OUTPUT_MIX_SESSION | 会话绑定到特定音轨。 | 
| AUDIO_ALLOCATE_SESSION | 会话ID需重新申请。 | 
| AUDIO_INVALID_SESSION | 无效会话类型。 | 
