# audio_types.h


## **概述**

Audio模块接口定义中使用的自定义数据类型，包括音频端口、适配器描述符、设备描述符、场景描述符、采样属性、时间戳等。

**Since:**

1.0

**Version:**

1.0

**相关模块:**

[Audio](_audio.md)


## **汇总**


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [AudioPort](_audio_port.md) | 音频端口 | 
| [AudioAdapterDescriptor](_audio_adapter_descriptor.md) | 音频适配器描述符 | 
| [AudioDeviceDescriptor](_audio_device_descriptor.md) | 音频设备描述符 | 
| [AudioSceneDescriptor](_audio_scene_descriptor.md) | 音频场景描述符 | 
| [AudioSceneDescriptor::SceneDesc](union_audio_scene_descriptor_1_1_scene_desc.md) | 音频场景描述 | 
| [AudioSampleAttributes](_audio_sample_attributes.md) | 音频采样属性 | 
| [AudioTimeStamp](_audio_time_stamp.md) | 音频时间戳 | 
| [AudioSubPortCapability](_audio_sub_port_capability.md) | 音频子端口的支持能力 | 
| [AudioPortCapability](_audio_port_capability.md) | 音频端口的支持能力 | 
| [AudioMmapBufferDescriptor](_audio_mmap_buffer_descriptor.md) | mmap缓冲区描述符 | 
| [AudioDevExtInfo](_audio_dev_ext_info.md) | 音频设备拓展信息. | 
| [AudioMixExtInfo](_audio_mix_ext_info.md) | 音轨拓展信息 | 
| [AudioSessionExtInfo](_audio_session_ext_info.md) | 会话拓展信息 | 
| [AudioRouteNode](_audio_route_node.md) | 音频路由节点. | 
| [AudioRoute](_audio_route.md) | 音频路由信息. | 


### 类型定义

  | 名称 | 描述 | 
| -------- | -------- |
| AudioHandle | 音频句柄 | 
| ([RenderCallback](_audio.md#rendercallback))&nbsp;(enum&nbsp;AudioCallbackType,&nbsp;void&nbsp;\*reserved,&nbsp;void&nbsp;\*cookie) | 回调函数指针 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [AudioPortDirection](_audio.md#audioportdirection)&nbsp;{&nbsp;PORT_OUT&nbsp;=&nbsp;0x1u,&nbsp;PORT_IN&nbsp;=&nbsp;0x2u,&nbsp;PORT_OUT_IN&nbsp;=&nbsp;0x3u&nbsp;} | 音频端口的类型 | 
| [AudioPortPin](_audio.md#audioportpin)&nbsp;{&nbsp;PIN_NONE&nbsp;=&nbsp;0x0u,&nbsp;PIN_OUT_SPEAKER&nbsp;=&nbsp;0x1u,&nbsp;PIN_OUT_HEADSET&nbsp;=&nbsp;0x2u,&nbsp;PIN_OUT_LINEOUT&nbsp;=&nbsp;0x4u,&nbsp;&nbsp;&nbsp;PIN_OUT_HDMI&nbsp;=&nbsp;0x8u,&nbsp;PIN_OUT_USB&nbsp;=&nbsp;0x10u,&nbsp;PIN_OUT_USB_EXT&nbsp;=&nbsp;0x20u,&nbsp;PIN_IN_MIC&nbsp;=&nbsp;0x8000001u,&nbsp;&nbsp;&nbsp;PIN_IN_HS_MIC&nbsp;=&nbsp;0x8000002u,&nbsp;PIN_IN_LINEIN&nbsp;=&nbsp;0x8000004u,&nbsp;PIN_IN_USB_EXT&nbsp;=&nbsp;0x8000008u&nbsp;} | 音频适配器端口的PIN脚 | 
| [AudioCategory](_audio.md#audiocategory)&nbsp;{&nbsp;AUDIO_IN_MEDIA&nbsp;=&nbsp;0,&nbsp;AUDIO_IN_COMMUNICATION,&nbsp;AUDIO_IN_RINGTONE,&nbsp;AUDIO_IN_CALL&nbsp;} | 音频类型（category） | 
| [AudioFormat](_audio.md#audioformat){&nbsp;AUDIO_FORMAT_PCM_8_BIT&nbsp;=&nbsp;0x1u,&nbsp;AUDIO_FORMAT_PCM_16_BIT&nbsp;=&nbsp;0x2u,&nbsp;AUDIO_FORMAT_PCM_24_BIT&nbsp;=&nbsp;0x3u,&nbsp;AUDIO_FORMAT_PCM_32_BIT&nbsp;=&nbsp;0x4u,&nbsp;&nbsp;&nbsp;AUDIO_FORMAT_AAC_MAIN&nbsp;=&nbsp;0x1000001u,&nbsp;AUDIO_FORMAT_AAC_LC&nbsp;=&nbsp;0x1000002u,&nbsp;AUDIO_FORMAT_AAC_LD&nbsp;=&nbsp;0x1000003u,&nbsp;AUDIO_FORMAT_AAC_ELD&nbsp;=&nbsp;0x1000004u,&nbsp;&nbsp;&nbsp;AUDIO_FORMAT_AAC_HE_V1&nbsp;=&nbsp;0x1000005u,&nbsp;AUDIO_FORMAT_AAC_HE_V2&nbsp;=&nbsp;0x1000006u,&nbsp;AUDIO_FORMAT_G711A&nbsp;=&nbsp;0x2000001u,&nbsp;AUDIO_FORMAT_G711U&nbsp;=&nbsp;0x2000002u,&nbsp;&nbsp;&nbsp;AUDIO_FORMAT_G726&nbsp;=&nbsp;0x2000003u&nbsp;} | 音频格式 | 
| [AudioChannelMask](_audio.md#audiochannelmask){&nbsp;AUDIO_CHANNEL_FRONT_LEFT&nbsp;=&nbsp;0x1,&nbsp;AUDIO_CHANNEL_FRONT_RIGHT&nbsp;=&nbsp;0x2,&nbsp;AUDIO_CHANNEL_MONO&nbsp;=&nbsp;0x1u,&nbsp;AUDIO_CHANNEL_STEREO&nbsp;=&nbsp;0x3u&nbsp;} | 音频通道掩码（mask） | 
| [AudioSampleRatesMask](_audio.md#audiosampleratesmask){&nbsp;AUDIO_SAMPLE_RATE_MASK_8000&nbsp;=&nbsp;0x1u,&nbsp;AUDIO_SAMPLE_RATE_MASK_12000&nbsp;=&nbsp;0x2u,&nbsp;AUDIO_SAMPLE_RATE_MASK_11025&nbsp;=&nbsp;0x4u,&nbsp;AUDIO_SAMPLE_RATE_MASK_16000&nbsp;=&nbsp;0x8u,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_RATE_MASK_22050&nbsp;=&nbsp;0x10u,&nbsp;AUDIO_SAMPLE_RATE_MASK_24000&nbsp;=&nbsp;0x20u,&nbsp;AUDIO_SAMPLE_RATE_MASK_32000&nbsp;=&nbsp;0x40u,&nbsp;AUDIO_SAMPLE_RATE_MASK_44100&nbsp;=&nbsp;0x80u,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_RATE_MASK_48000&nbsp;=&nbsp;0x100u,&nbsp;AUDIO_SAMPLE_RATE_MASK_64000&nbsp;=&nbsp;0x200u,&nbsp;AUDIO_SAMPLE_RATE_MASK_96000&nbsp;=&nbsp;0x400u,&nbsp;AUDIO_SAMPLE_RATE_MASK_INVALID&nbsp;=&nbsp;0xFFFFFFFFu&nbsp;} | 音频采样频率MASK | 
| [AudioPortPassthroughMode](_audio.md#audioportpassthroughmode){&nbsp;PORT_PASSTHROUGH_LPCM&nbsp;=&nbsp;0x1,&nbsp;PORT_PASSTHROUGH_RAW&nbsp;=&nbsp;0x2,&nbsp;PORT_PASSTHROUGH_HBR2LBR&nbsp;=&nbsp;0x4,&nbsp;PORT_PASSTHROUGH_AUTO&nbsp;=&nbsp;0x8&nbsp;} | 音频端口的数据透传模式 | 
| [AudioSampleFormat](_audio.md#audiosampleformat){&nbsp;AUDIO_SAMPLE_FORMAT_S8,&nbsp;AUDIO_SAMPLE_FORMAT_S8P,&nbsp;AUDIO_SAMPLE_FORMAT_U8,&nbsp;AUDIO_SAMPLE_FORMAT_U8P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_S16,&nbsp;AUDIO_SAMPLE_FORMAT_S16P,&nbsp;AUDIO_SAMPLE_FORMAT_U16,&nbsp;AUDIO_SAMPLE_FORMAT_U16P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_S24,&nbsp;AUDIO_SAMPLE_FORMAT_S24P,&nbsp;AUDIO_SAMPLE_FORMAT_U24,&nbsp;AUDIO_SAMPLE_FORMAT_U24P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_S32,&nbsp;AUDIO_SAMPLE_FORMAT_S32P,&nbsp;AUDIO_SAMPLE_FORMAT_U32,&nbsp;AUDIO_SAMPLE_FORMAT_U32P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_S64,&nbsp;AUDIO_SAMPLE_FORMAT_S64P,&nbsp;AUDIO_SAMPLE_FORMAT_U64,&nbsp;AUDIO_SAMPLE_FORMAT_U64P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_F32,&nbsp;AUDIO_SAMPLE_FORMAT_F32P,&nbsp;AUDIO_SAMPLE_FORMAT_F64,&nbsp;AUDIO_SAMPLE_FORMAT_F64P&nbsp;} | 原始音频样本格式 | 
| [AudioChannelMode](_audio.md#audiochannelmode){&nbsp;&nbsp;AUDIO_CHANNEL_NORMAL&nbsp;=&nbsp;0,&nbsp;AUDIO_CHANNEL_BOTH_LEFT,&nbsp;AUDIO_CHANNEL_BOTH_RIGHT,&nbsp;AUDIO_CHANNEL_EXCHANGE,&nbsp;&nbsp;&nbsp;AUDIO_CHANNEL_MIX,&nbsp;AUDIO_CHANNEL_LEFT_MUTE,&nbsp;AUDIO_CHANNEL_RIGHT_MUTE,&nbsp;AUDIO_CHANNEL_BOTH_MUTE&nbsp;} | 音频播放的通道模式 | 
| [AudioDrainNotifyType](_audio.md#audiodrainnotifytype){&nbsp;AUDIO_DRAIN_NORMAL_MODE,&nbsp;AUDIO_DRAIN_EARLY_MODE&nbsp;} | DrainBuffer函数结束类型 | 
| [AudioCallbackType](_audio.md#audiocallbacktype){&nbsp;AUDIO_NONBLOCK_WRITE_COMPLETED,&nbsp;AUDIO_DRAIN_COMPLETED,&nbsp;AUDIO_FLUSH_COMPLETED,&nbsp;AUDIO_RENDER_FULL,&nbsp;&nbsp;&nbsp;AUDIO_ERROR_OCCUR&nbsp;} | 回调函数通知事件类型 | 
| [AudioPortRole](_audio.md#audioportrole){&nbsp;AUDIO_PORT_UNASSIGNED_ROLE&nbsp;=&nbsp;0,&nbsp;AUDIO_PORT_SOURCE_ROLE&nbsp;=&nbsp;1,&nbsp;AUDIO_PORT_SINK_ROLE&nbsp;=&nbsp;2&nbsp;} | 音频端口角色 | 
| [AudioPortType](_audio.md#audioporttype){&nbsp;AUDIO_PORT_UNASSIGNED_TYPE&nbsp;=&nbsp;0,&nbsp;AUDIO_PORT_DEVICE_TYPE&nbsp;=&nbsp;1,&nbsp;AUDIO_PORT_MIX_TYPE&nbsp;=&nbsp;2,&nbsp;AUDIO_PORT_SESSION_TYPE&nbsp;=&nbsp;3&nbsp;} | 音频端口类型. | 
| [AudioSessionType](_audio.md#audiosessiontype){&nbsp;AUDIO_OUTPUT_STAGE_SESSION&nbsp;=&nbsp;0,&nbsp;AUDIO_OUTPUT_MIX_SESSION,&nbsp;AUDIO_ALLOCATE_SESSION,&nbsp;AUDIO_INVALID_SESSION&nbsp;} | 端口会话类型 | 
