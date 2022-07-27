# audio_types.h


## **概述**

**所属模块:**

[Audio](_audio.md)


## **汇总**


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [AudioPort](_audio_port.md) | 音频端口&nbsp;[更多...](_audio_port.md) | 
| [AudioAdapterDescriptor](_audio_adapter_descriptor.md) | 音频适配器描述符&nbsp;[更多...](_audio_adapter_descriptor.md) | 
| [AudioDeviceDescriptor](_audio_device_descriptor.md) | 音频设备描述符&nbsp;[更多...](_audio_device_descriptor.md) | 
| [AudioSceneDescriptor](_audio_scene_descriptor.md) | 音频场景描述符&nbsp;[更多...](_audio_scene_descriptor.md) | 
| [AudioSceneDescriptor::SceneDesc](union_audio_scene_descriptor_1_1_scene_desc.md) | 音频场景描述&nbsp;[更多...](union_audio_scene_descriptor_1_1_scene_desc.md) | 
| [AudioSampleAttributes](_audio_sample_attributes.md) | 音频采样属性&nbsp;[更多...](_audio_sample_attributes.md) | 
| [AudioTimeStamp](_audio_time_stamp.md) | 音频时间戳&nbsp;[更多...](_audio_time_stamp.md) | 
| [AudioSubPortCapability](_audio_sub_port_capability.md) | 音频子端口的支持能力&nbsp;[更多...](_audio_sub_port_capability.md) | 
| [AudioPortCapability](_audio_port_capability.md) | 音频端口的支持能力&nbsp;[更多...](_audio_port_capability.md) | 
| [AudioMmapBufferDescripter](_audio_mmap_buffer_descripter.md) | mmap缓冲区描述符&nbsp;[更多...](_audio_mmap_buffer_descripter.md) | 
| [AudioDevExtInfo](_audio_dev_ext_info.md) | 音频设备拓展信息&nbsp;[更多...](_audio_dev_ext_info.md) | 
| [AudioMixExtInfo](_audio_mix_ext_info.md) | 音轨拓展信息&nbsp;[更多...](_audio_mix_ext_info.md) | 
| [AudioSessionExtInfo](_audio_session_ext_info.md) | 会话拓展信息&nbsp;[更多...](_audio_session_ext_info.md) | 
| [AudioRouteNode](_audio_route_node.md) | 音频路由节点&nbsp;[更多...](_audio_route_node.md) | 
| [AudioRoute](_audio_route.md) | 音频路由信息&nbsp;[更多...](_audio_route.md) | 


### 类型定义

  | 类型定义 | 描述 | 
| -------- | -------- |
| [AudioHandle](_audio.md#ga18675ddb073465fdeac33a897f675d79) | 音频句柄 | 
| ([RenderCallback](_audio.md#rendercallback))&nbsp;(enum&nbsp;[AudioCallbackType](_audio.md#audiocallbacktype),&nbsp;void&nbsp;\*reserved,&nbsp;void&nbsp;\*cookie) | 回调函数指针&nbsp;[更多...](_audio.md#rendercallback) | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [AudioPortDirection](_audio.md#audioportdirection)&nbsp;{&nbsp;PORT_OUT&nbsp;=&nbsp;0x1u,&nbsp;PORT_IN&nbsp;=&nbsp;0x2u,&nbsp;PORT_OUT_IN&nbsp;=&nbsp;0x3u&nbsp;} | 音频端口的类型&nbsp;[更多...](_audio.md#audioportdirection) | 
| [AudioPortPin](_audio.md#audioportpin)&nbsp;{&nbsp;&nbsp;&nbsp;PIN_NONE&nbsp;=&nbsp;0x0u,&nbsp;PIN_OUT_SPEAKER&nbsp;=&nbsp;0x1u,&nbsp;PIN_OUT_HEADSET&nbsp;=&nbsp;0x2u,&nbsp;PIN_OUT_LINEOUT&nbsp;=&nbsp;0x4u,&nbsp;&nbsp;&nbsp;PIN_OUT_HDMI&nbsp;=&nbsp;0x8u,&nbsp;PIN_OUT_USB&nbsp;=&nbsp;0x10u,&nbsp;PIN_OUT_USB_EXT&nbsp;=&nbsp;0x20u,&nbsp;PIN_IN_MIC&nbsp;=&nbsp;0x8000001u,&nbsp;&nbsp;&nbsp;PIN_IN_HS_MIC&nbsp;=&nbsp;0x8000002u,&nbsp;PIN_IN_LINEIN&nbsp;=&nbsp;0x8000004u,&nbsp;PIN_IN_USB_EXT&nbsp;=&nbsp;0x8000008u&nbsp;} | 音频适配器端口的PIN脚&nbsp;[更多...](_audio.md#audioportpin) | 
| [AudioCategory](_audio.md#audiocategory)&nbsp;{&nbsp;AUDIO_IN_MEDIA&nbsp;=&nbsp;0,&nbsp;AUDIO_IN_COMMUNICATION,&nbsp;AUDIO_IN_RINGTONE,&nbsp;AUDIO_IN_CALL&nbsp;} | 音频类型（category）&nbsp;[更多...](_audio.md#audiocategory) | 
| [AudioFormat](_audio.md#audioformat)&nbsp;{&nbsp;&nbsp;&nbsp;AUDIO_FORMAT_PCM_8_BIT&nbsp;=&nbsp;0x1u,&nbsp;AUDIO_FORMAT_PCM_16_BIT&nbsp;=&nbsp;0x2u,&nbsp;AUDIO_FORMAT_PCM_24_BIT&nbsp;=&nbsp;0x3u,&nbsp;AUDIO_FORMAT_PCM_32_BIT&nbsp;=&nbsp;0x4u,&nbsp;&nbsp;&nbsp;AUDIO_FORMAT_AAC_MAIN&nbsp;=&nbsp;0x1000001u,&nbsp;AUDIO_FORMAT_AAC_LC&nbsp;=&nbsp;0x1000002u,&nbsp;AUDIO_FORMAT_AAC_LD&nbsp;=&nbsp;0x1000003u,&nbsp;AUDIO_FORMAT_AAC_ELD&nbsp;=&nbsp;0x1000004u,&nbsp;&nbsp;&nbsp;AUDIO_FORMAT_AAC_HE_V1&nbsp;=&nbsp;0x1000005u,&nbsp;AUDIO_FORMAT_AAC_HE_V2&nbsp;=&nbsp;0x1000006u,&nbsp;AUDIO_FORMAT_G711A&nbsp;=&nbsp;0x2000001u,&nbsp;AUDIO_FORMAT_G711U&nbsp;=&nbsp;0x2000002u,&nbsp;&nbsp;&nbsp;AUDIO_FORMAT_G726&nbsp;=&nbsp;0x2000003u&nbsp;} | 音频格式&nbsp;[更多...](_audio.md#audioformat) | 
| [AudioChannelMask](_audio.md#audiochannelmask)&nbsp;{&nbsp;AUDIO_CHANNEL_FRONT_LEFT&nbsp;=&nbsp;0x1,&nbsp;AUDIO_CHANNEL_FRONT_RIGHT&nbsp;=&nbsp;0x2,&nbsp;AUDIO_CHANNEL_MONO&nbsp;=&nbsp;0x1u,&nbsp;AUDIO_CHANNEL_STEREO&nbsp;=&nbsp;0x3u&nbsp;} | 音频通道掩码（mask）&nbsp;[更多...](_audio.md#audiochannelmask) | 
| [AudioSampleRatesMask](_audio.md#audiosampleratesmask)&nbsp;{&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_RATE_MASK_8000&nbsp;=&nbsp;0x1u,&nbsp;AUDIO_SAMPLE_RATE_MASK_12000&nbsp;=&nbsp;0x2u,&nbsp;AUDIO_SAMPLE_RATE_MASK_11025&nbsp;=&nbsp;0x4u,&nbsp;AUDIO_SAMPLE_RATE_MASK_16000&nbsp;=&nbsp;0x8u,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_RATE_MASK_22050&nbsp;=&nbsp;0x10u,&nbsp;AUDIO_SAMPLE_RATE_MASK_24000&nbsp;=&nbsp;0x20u,&nbsp;AUDIO_SAMPLE_RATE_MASK_32000&nbsp;=&nbsp;0x40u,&nbsp;AUDIO_SAMPLE_RATE_MASK_44100&nbsp;=&nbsp;0x80u,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_RATE_MASK_48000&nbsp;=&nbsp;0x100u,&nbsp;AUDIO_SAMPLE_RATE_MASK_64000&nbsp;=&nbsp;0x200u,&nbsp;AUDIO_SAMPLE_RATE_MASK_96000&nbsp;=&nbsp;0x400u,&nbsp;AUDIO_SAMPLE_RATE_MASK_INVALID&nbsp;=&nbsp;0xFFFFFFFFu&nbsp;} | 音频采样频率MASK&nbsp;[更多...](_audio.md#audiosampleratesmask) | 
| [AudioPortPassthroughMode](_audio.md#audioportpassthroughmode)&nbsp;{&nbsp;PORT_PASSTHROUGH_LPCM&nbsp;=&nbsp;0x1,&nbsp;PORT_PASSTHROUGH_RAW&nbsp;=&nbsp;0x2,&nbsp;PORT_PASSTHROUGH_HBR2LBR&nbsp;=&nbsp;0x4,&nbsp;PORT_PASSTHROUGH_AUTO&nbsp;=&nbsp;0x8&nbsp;} | 音频端口的数据透传模式&nbsp;[更多...](_audio.md#audioportpassthroughmode) | 
| [AudioSampleFormat](_audio.md#audiosampleformat)&nbsp;{&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_S8,&nbsp;AUDIO_SAMPLE_FORMAT_S8P,&nbsp;AUDIO_SAMPLE_FORMAT_U8,&nbsp;AUDIO_SAMPLE_FORMAT_U8P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_S16,&nbsp;AUDIO_SAMPLE_FORMAT_S16P,&nbsp;AUDIO_SAMPLE_FORMAT_U16,&nbsp;AUDIO_SAMPLE_FORMAT_U16P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_S24,&nbsp;AUDIO_SAMPLE_FORMAT_S24P,&nbsp;AUDIO_SAMPLE_FORMAT_U24,&nbsp;AUDIO_SAMPLE_FORMAT_U24P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_S32,&nbsp;AUDIO_SAMPLE_FORMAT_S32P,&nbsp;AUDIO_SAMPLE_FORMAT_U32,&nbsp;AUDIO_SAMPLE_FORMAT_U32P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_S64,&nbsp;AUDIO_SAMPLE_FORMAT_S64P,&nbsp;AUDIO_SAMPLE_FORMAT_U64,&nbsp;AUDIO_SAMPLE_FORMAT_U64P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_F32,&nbsp;AUDIO_SAMPLE_FORMAT_F32P,&nbsp;AUDIO_SAMPLE_FORMAT_F64,&nbsp;AUDIO_SAMPLE_FORMAT_F64P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FMT_U8,&nbsp;AUDIO_SAMPLE_FMT_S16,&nbsp;AUDIO_SAMPLE_FMT_S32,&nbsp;AUDIO_SAMPLE_FMT_FLOAT,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FMT_DOUBLE,&nbsp;AUDIO_SAMPLE_FMT_U8P,&nbsp;AUDIO_SAMPLE_FMT_S16P,&nbsp;AUDIO_SAMPLE_FMT_S32P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FMT_FLOATP,&nbsp;AUDIO_SAMPLE_FMT_DOUBLEP,&nbsp;AUDIO_SAMPLE_FMT_INVALID&nbsp;} | 原始音频样本格式&nbsp;[更多...](_audio.md#audiosampleformat) | 
| [AudioChannelMode](_audio.md#audiochannelmode)&nbsp;{&nbsp;&nbsp;&nbsp;AUDIO_CHANNEL_NORMAL&nbsp;=&nbsp;0,&nbsp;AUDIO_CHANNEL_BOTH_LEFT,&nbsp;AUDIO_CHANNEL_BOTH_RIGHT,&nbsp;AUDIO_CHANNEL_EXCHANGE,&nbsp;&nbsp;&nbsp;AUDIO_CHANNEL_MIX,&nbsp;AUDIO_CHANNEL_LEFT_MUTE,&nbsp;AUDIO_CHANNEL_RIGHT_MUTE,&nbsp;AUDIO_CHANNEL_BOTH_MUTE&nbsp;} | 音频播放的通道模式&nbsp;[更多...](_audio.md#audiochannelmode) | 
| [AudioDrainNotifyType](_audio.md#audiodrainnotifytype)&nbsp;{&nbsp;AUDIO_DRAIN_NORMAL_MODE,&nbsp;AUDIO_DRAIN_EARLY_MODE&nbsp;} | DrainBuffer函数结束类型&nbsp;[更多...](_audio.md#audiodrainnotifytype) | 
| [AudioCallbackType](_audio.md#audiocallbacktype)&nbsp;{&nbsp;&nbsp;&nbsp;AUDIO_NONBLOCK_WRITE_COMPELETED,&nbsp;AUDIO_DRAIN_COMPELETED,&nbsp;AUDIO_FLUSH_COMPLETED,&nbsp;AUDIO_RENDER_FULL,&nbsp;&nbsp;&nbsp;AUDIO_ERROR_OCCUR&nbsp;} | 回调函数通知事件类型&nbsp;[更多...](_audio.md#audiocallbacktype) | 
| [AudioPortRole](_audio.md#audioportrole)&nbsp;{&nbsp;AUDIO_PORT_UNASSIGNED_ROLE&nbsp;=&nbsp;0,&nbsp;AUDIO_PORT_SOURCE_ROLE&nbsp;=&nbsp;1,&nbsp;AUDIO_PORT_SINK_ROLE&nbsp;=&nbsp;2&nbsp;} | 音频端口角色&nbsp;[更多...](_audio.md#audioportrole) | 
| [AudioPortType](_audio.md#audioporttype)&nbsp;{&nbsp;AUDIO_PORT_UNASSIGNED_TYPE&nbsp;=&nbsp;0,&nbsp;AUDIO_PORT_DEVICE_TYPE&nbsp;=&nbsp;1,&nbsp;AUDIO_PORT_MIX_TYPE&nbsp;=&nbsp;2,&nbsp;AUDIO_PORT_SESSION_TYPE&nbsp;=&nbsp;3&nbsp;} | 音频端口类型.&nbsp;[更多...](_audio.md#audioporttype) | 
| [AudioSessionType](_audio.md#audiosessiontype)&nbsp;{&nbsp;AUDIO_OUTPUT_STAGE_SESSION&nbsp;=&nbsp;0,&nbsp;AUDIO_OUTPUT_MIX_SESSION,&nbsp;AUDIO_ALLOCATE_SESSION,&nbsp;AUDIO_INVALID_SESSION&nbsp;} | 端口会话类型&nbsp;[更多...](_audio.md#audiosessiontype) | 


## **详细描述**

Audio模块接口定义中使用的自定义数据类型

Audio模块接口定义中使用的自定义数据类型，包括音频端口、适配器描述符、设备描述符、场景描述符、采样属性、时间戳等。

**Since：**

1.0

**Version：**

1.0
