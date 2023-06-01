# AudioTypes.idl


## 概述

Audio模块接口定义中使用的数据类型，包括音频端口、适配器描述符、设备描述符、场景描述符、采样属性、时间戳等。

**Since:**

3.2

**Version:**

1.0

**相关模块:**

[Audio](_audio.md)


## 汇总


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


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [AudioPortDirection](_audio.md#audioportdirection)&nbsp;{&nbsp;PORT_OUT&nbsp;=&nbsp;1&nbsp;,&nbsp;PORT_IN&nbsp;=&nbsp;2&nbsp;,&nbsp;PORT_OUT_IN&nbsp;=&nbsp;3&nbsp;} | 音频端口的类型。 | 
| [AudioPortPin](_audio.md#audioportpin)&nbsp;{<br/>PIN_NONE&nbsp;=&nbsp;0&nbsp;,&nbsp;PIN_OUT_SPEAKER&nbsp;=&nbsp;1&nbsp;,&nbsp;PIN_OUT_HEADSET&nbsp;=&nbsp;2&nbsp;,&nbsp;PIN_OUT_LINEOUT&nbsp;=&nbsp;4&nbsp;,<br/>PIN_OUT_HDMI&nbsp;=&nbsp;8&nbsp;,&nbsp;PIN_IN_MIC&nbsp;=&nbsp;134217729&nbsp;,&nbsp;PIN_IN_HS_MIC&nbsp;=&nbsp;134217730&nbsp;,&nbsp;PIN_IN_LINEIN&nbsp;=&nbsp;134217732&nbsp;,<br/>PIN_IN_USB_EXT&nbsp;=&nbsp;134217736<br/>} | 音频端口上的Pin脚。 | 
| [AudioCategory](_audio.md#audiocategory)&nbsp;{&nbsp;AUDIO_IN_MEDIA&nbsp;=&nbsp;0&nbsp;,&nbsp;AUDIO_IN_COMMUNICATION&nbsp;=&nbsp;1&nbsp;,&nbsp;AUDIO_IN_RINGTONE&nbsp;=&nbsp;2&nbsp;,&nbsp;AUDIO_IN_CALL&nbsp;=&nbsp;3&nbsp;} | 音频类型（场景）。 | 
| [AudioFormat](_audio.md#audioformat)&nbsp;{<br/>AUDIO_FORMAT_PCM_8_BIT&nbsp;=&nbsp;1&nbsp;,&nbsp;AUDIO_FORMAT_PCM_16_BIT&nbsp;=&nbsp;2&nbsp;,&nbsp;AUDIO_FORMAT_PCM_24_BIT&nbsp;=&nbsp;3&nbsp;,&nbsp;AUDIO_FORMAT_PCM_32_BIT&nbsp;=&nbsp;4&nbsp;,<br/>AUDIO_FORMAT_AAC_MAIN&nbsp;=&nbsp;16777217&nbsp;,&nbsp;AUDIO_FORMAT_AAC_LC&nbsp;=&nbsp;16777218&nbsp;,&nbsp;AUDIO_FORMAT_AAC_LD&nbsp;=&nbsp;16777219&nbsp;,&nbsp;AUDIO_FORMAT_AAC_ELD&nbsp;=&nbsp;16777220&nbsp;,<br/>AUDIO_FORMAT_AAC_HE_V1&nbsp;=&nbsp;16777221&nbsp;,&nbsp;AUDIO_FORMAT_AAC_HE_V2&nbsp;=&nbsp;16777222&nbsp;,&nbsp;AUDIO_FORMAT_G711A&nbsp;=&nbsp;33554433&nbsp;,&nbsp;AUDIO_FORMAT_G711U&nbsp;=&nbsp;33554434&nbsp;,<br/>AUDIO_FORMAT_G726&nbsp;=&nbsp;33554435<br/>} | 音频格式。 | 
| [AudioChannelMask](_audio.md#audiochannelmask)&nbsp;{&nbsp;AUDIO_CHANNEL_FRONT_LEFT&nbsp;=&nbsp;1&nbsp;,&nbsp;AUDIO_CHANNEL_FRONT_RIGHT&nbsp;=&nbsp;2&nbsp;,&nbsp;AUDIO_CHANNEL_MONO&nbsp;=&nbsp;1&nbsp;,&nbsp;AUDIO_CHANNEL_STEREO&nbsp;=&nbsp;3&nbsp;} | 音频通道掩码。 | 
| [AudioSampleRatesMask](_audio.md#audiosampleratesmask)&nbsp;{<br/>AUDIO_SAMPLE_RATE_MASK_8000&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;0&nbsp;,&nbsp;AUDIO_SAMPLE_RATE_MASK_12000&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;1&nbsp;,&nbsp;AUDIO_SAMPLE_RATE_MASK_11025&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;2&nbsp;,&nbsp;AUDIO_SAMPLE_RATE_MASK_16000&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;3&nbsp;,<br/>AUDIO_SAMPLE_RATE_MASK_22050&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;4&nbsp;,&nbsp;AUDIO_SAMPLE_RATE_MASK_24000&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;5&nbsp;,&nbsp;AUDIO_SAMPLE_RATE_MASK_32000&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;6&nbsp;,&nbsp;AUDIO_SAMPLE_RATE_MASK_44100&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;7&nbsp;,<br/>AUDIO_SAMPLE_RATE_MASK_48000&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;8&nbsp;,&nbsp;AUDIO_SAMPLE_RATE_MASK_64000&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;9&nbsp;,&nbsp;AUDIO_SAMPLE_RATE_MASK_96000&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;10&nbsp;,&nbsp;AUDIO_SAMPLE_RATE_MASK_INVALID&nbsp;=&nbsp;4294967295<br/>} | 音频采样频率掩码。 | 
| [AudioPortPassthroughMode](_audio.md#audioportpassthroughmode)&nbsp;{&nbsp;PORT_PASSTHROUGH_LPCM&nbsp;=&nbsp;1&nbsp;,&nbsp;PORT_PASSTHROUGH_RAW&nbsp;=&nbsp;2&nbsp;,&nbsp;PORT_PASSTHROUGH_HBR2LBR&nbsp;=&nbsp;4&nbsp;,&nbsp;PORT_PASSTHROUGH_AUTO&nbsp;=&nbsp;8&nbsp;} | 音频端口的数据透传模式。 | 
| [AudioDeviceType](_audio.md#audiodevicetype)&nbsp;{<br/>AUDIO_LINEOUT&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;0&nbsp;,&nbsp;AUDIO_HEADPHONE&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;1&nbsp;,&nbsp;AUDIO_HEADSET&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;2&nbsp;,&nbsp;AUDIO_USB_HEADSET&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;3&nbsp;,<br/>AUDIO_USB_HEADPHONE&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;4&nbsp;,&nbsp;AUDIO_USBA_HEADSET&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;5&nbsp;,&nbsp;AUDIO_USBA_HEADPHONE&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;6&nbsp;,&nbsp;AUDIO_PRIMARY_DEVICE&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;7&nbsp;,<br/>AUDIO_USB_DEVICE&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;8&nbsp;,&nbsp;AUDIO_A2DP_DEVICE&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;9&nbsp;,&nbsp;AUDIO_DEVICE_UNKOWN<br/>} | 音频设备类型。 | 
| [AudioEventType](_audio.md#audioeventtype)&nbsp;{<br/>AUDIO_DEVICE_ADD&nbsp;=&nbsp;1&nbsp;,&nbsp;AUDIO_DEVICE_REMOVE&nbsp;=&nbsp;2&nbsp;,&nbsp;AUDIO_LOAD_SUCCESS&nbsp;=&nbsp;3&nbsp;,&nbsp;AUDIO_LOAD_FAILURE&nbsp;=&nbsp;4&nbsp;,<br/>AUDIO_UNLOAD&nbsp;=&nbsp;5&nbsp;,&nbsp;AUDIO_SERVICE_VALID&nbsp;=&nbsp;7&nbsp;,&nbsp;AUDIO_SERVICE_INVALID&nbsp;=&nbsp;8&nbsp;,&nbsp;AUDIO_CAPTURE_THRESHOLD&nbsp;=&nbsp;9&nbsp;,<br/>AUDIO_EVENT_UNKOWN&nbsp;=&nbsp;10<br/>} | 音频事件类型。 | 
| [AudioExtParamKey](_audio.md#audioextparamkey)&nbsp;{<br/>AUDIO_EXT_PARAM_KEY_NONE&nbsp;=&nbsp;0&nbsp;,&nbsp;AUDIO_EXT_PARAM_KEY_VOLUME&nbsp;=&nbsp;1&nbsp;,&nbsp;AUDIO_EXT_PARAM_KEY_FOCUS&nbsp;=&nbsp;2&nbsp;,&nbsp;AUDIO_EXT_PARAM_KEY_BUTTON&nbsp;=&nbsp;3&nbsp;,<br/>AUDIO_EXT_PARAM_KEY_EFFECT&nbsp;=&nbsp;4&nbsp;,&nbsp;AUDIO_EXT_PARAM_KEY_STATUS&nbsp;=&nbsp;5&nbsp;,&nbsp;AUDIO_EXT_PARAM_KEY_LOWPOWER&nbsp;=&nbsp;1000<br/>} | 音频扩展参数键类型。 | 
| [AudioSampleFormat](_audio.md#audiosampleformat)&nbsp;{<br/>AUDIO_SAMPLE_FORMAT_S8&nbsp;=&nbsp;0&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_S8P&nbsp;=&nbsp;1&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_U8&nbsp;=&nbsp;2&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_U8P&nbsp;=&nbsp;3&nbsp;,<br/>AUDIO_SAMPLE_FORMAT_S16&nbsp;=&nbsp;4&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_S16P&nbsp;=&nbsp;5&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_U16&nbsp;=&nbsp;6&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_U16P&nbsp;=&nbsp;7&nbsp;,<br/>AUDIO_SAMPLE_FORMAT_S24&nbsp;=&nbsp;8&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_S24P&nbsp;=&nbsp;9&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_U24&nbsp;=&nbsp;10&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_U24P&nbsp;=&nbsp;11&nbsp;,<br/>AUDIO_SAMPLE_FORMAT_S32&nbsp;=&nbsp;12&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_S32P&nbsp;=&nbsp;13&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_U32&nbsp;=&nbsp;14&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_U32P&nbsp;=&nbsp;15&nbsp;,<br/>AUDIO_SAMPLE_FORMAT_S64&nbsp;=&nbsp;16&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_S64P&nbsp;=&nbsp;17&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_U64&nbsp;=&nbsp;18&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_U64P&nbsp;=&nbsp;19&nbsp;,<br/>AUDIO_SAMPLE_FORMAT_F32&nbsp;=&nbsp;20&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_F32P&nbsp;=&nbsp;21&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_F64&nbsp;=&nbsp;22&nbsp;,&nbsp;AUDIO_SAMPLE_FORMAT_F64P&nbsp;=&nbsp;23<br/>} | 原始音频样本格式。 | 
| [AudioChannelMode](_audio.md#audiochannelmode)&nbsp;{<br/>AUDIO_CHANNEL_NORMAL&nbsp;=&nbsp;0&nbsp;,&nbsp;AUDIO_CHANNEL_BOTH_LEFT&nbsp;,&nbsp;AUDIO_CHANNEL_BOTH_RIGHT&nbsp;,&nbsp;AUDIO_CHANNEL_EXCHANGE&nbsp;,<br/>AUDIO_CHANNEL_MIX&nbsp;,&nbsp;AUDIO_CHANNEL_LEFT_MUTE&nbsp;,&nbsp;AUDIO_CHANNEL_RIGHT_MUTE&nbsp;,&nbsp;AUDIO_CHANNEL_BOTH_MUTE<br/>} | 音频播放的通道模式。 | 
| [AudioDrainNotifyType](_audio.md#audiodrainnotifytype)&nbsp;{&nbsp;AUDIO_DRAIN_NORMAL_MODE&nbsp;,&nbsp;AUDIO_DRAIN_EARLY_MODE&nbsp;} | 音频数据结束类型。 | 
| [AudioCallbackType](_audio.md#audiocallbacktype)&nbsp;{<br/>AUDIO_NONBLOCK_WRITE_COMPELETED&nbsp;,&nbsp;AUDIO_DRAIN_COMPELETED&nbsp;,&nbsp;AUDIO_FLUSH_COMPLETED&nbsp;,&nbsp;AUDIO_RENDER_FULL&nbsp;,<br/>AUDIO_ERROR_OCCUR<br/>} | 回调函数通知事件类型。 | 
| [AudioPortRole](_audio.md#audioportrole)&nbsp;{&nbsp;AUDIO_PORT_UNASSIGNED_ROLE&nbsp;=&nbsp;0&nbsp;,&nbsp;AUDIO_PORT_SOURCE_ROLE&nbsp;=&nbsp;1&nbsp;,&nbsp;AUDIO_PORT_SINK_ROLE&nbsp;=&nbsp;2&nbsp;} | 音频端口角色。 | 
| [AudioPortType](_audio.md#audioporttype)&nbsp;{&nbsp;AUDIO_PORT_UNASSIGNED_TYPE&nbsp;=&nbsp;0&nbsp;,&nbsp;AUDIO_PORT_DEVICE_TYPE&nbsp;=&nbsp;1&nbsp;,&nbsp;AUDIO_PORT_MIX_TYPE&nbsp;=&nbsp;2&nbsp;,&nbsp;AUDIO_PORT_SESSION_TYPE&nbsp;=&nbsp;3&nbsp;} | 音频端口类型。 | 
| [AudioSessionType](_audio.md#audiosessiontype)&nbsp;{&nbsp;AUDIO_OUTPUT_STAGE_SESSION&nbsp;=&nbsp;0&nbsp;,&nbsp;AUDIO_OUTPUT_MIX_SESSION&nbsp;,&nbsp;AUDIO_ALLOCATE_SESSION&nbsp;,&nbsp;AUDIO_INVALID_SESSION&nbsp;} | 端口会话类型。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.audio.v1_0 | 音频接口的包路径。 | 
