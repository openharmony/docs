# codec_component_type.h


## 概述

Codec模块接口定义中使用的自定义数据类型。

Codec模块接口定义中使用的自定义数据类型，包括编解码类型、音视频参数、buffer定义等。

**Since:**

3.1

**Version:**

2.0

**相关模块:**

[Codec](_codec.md)


## 汇总


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [VideoPortCap](_video_port_cap.md) | struct<br/>定义视频编解码能力。 | 
| [AudioPortCap](_audio_port_cap.md) | struct<br/>定义音频编解码能力。 | 
| [PortCap](union_port_cap.md) | union<br/>定义音视频编解码能力。 | 
| [CodecCompCapability](_codec_comp_capability.md) | struct<br/>定义Codec编解码能力。 | 
| [OmxCodecBuffer](_omx_codec_buffer.md) | struct<br/>Codec&nbsp;buffer信息的定义。 | 
| [CompVerInfo](_comp_ver_info.md) | struct<br/>定义组件版本信息。 | 
| [EventInfo](_event_info.md) | struct<br/>定义事件上报信息。 | 
| [SupportBufferType](_support_buffer_type.md) | struct<br/>SupportBuffer类型定义。 | 
| [UseBufferType](_use_buffer_type.md) | struct<br/>UseBuffer类型定义。 | 
| [GetBufferHandleUsageParams](_get_buffer_handle_usage_params.md) | struct<br/>BufferHandleUsage类型定义。 | 


### 宏定义

  | 名称 | 描述 | 
| -------- | -------- |
| [SAMPLE_FMT_NUM](_codec.md#sample_fmt_num)&nbsp;&nbsp;&nbsp;32 | 采样格式最大值。 | 
| [UUID_LENGTH](_codec.md#uuid_length)&nbsp;&nbsp;&nbsp;128 | 定义UUID长度。 | 
| [PIX_FORMAT_NUM](_codec.md#pix_format_num)&nbsp;&nbsp;&nbsp;16 | 支持的像素格式数组大小。 | 
| [SAMPLE_FORMAT_NUM](_codec.md#sample_format_num)&nbsp;&nbsp;&nbsp;12 | 支持的音频采样格式数组大小。 | 
| [SAMPLE_RATE_NUM](_codec.md#sample_rate_num)&nbsp;&nbsp;&nbsp;16 | 支持的音频采样率数组大小。 | 
| [CHANNEL_NUM](_codec.md#channel_num)&nbsp;&nbsp;&nbsp;16 | 支持的音频通道数组大小。 | 
| [NAME_LENGTH](_codec.md#name_length)&nbsp;&nbsp;&nbsp;32 | 组件名称大小。 | 
| [PROFILE_NUM](_codec.md#profile_num)&nbsp;&nbsp;&nbsp;256 | 支持的profile数组大小。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [AvCodecRole](_codec.md#avcodecrole)&nbsp;{&nbsp;MEDIA_ROLETYPE_IMAGE_JPEG&nbsp;=&nbsp;0,&nbsp;MEDIA_ROLETYPE_VIDEO_AVC,&nbsp;MEDIA_ROLETYPE_VIDEO_HEVC,&nbsp;MEDIA_ROLETYPE_AUDIO_FIRST&nbsp;=&nbsp;0x10000,&nbsp;&nbsp;&nbsp;MEDIA_ROLETYPE_AUDIO_AAC&nbsp;=&nbsp;0x10000,&nbsp;MEDIA_ROLETYPE_AUDIO_G711A,&nbsp;MEDIA_ROLETYPE_AUDIO_G711U,&nbsp;MEDIA_ROLETYPE_AUDIO_G726,&nbsp;&nbsp;&nbsp;MEDIA_ROLETYPE_AUDIO_PCM,&nbsp;MEDIA_ROLETYPE_AUDIO_MP3,&nbsp;MEDIA_ROLETYPE_INVALID&nbsp;} | 枚举音视频编解码组件类型。 | 
| [AudioSampleFormat](_codec.md#audiosampleformat)&nbsp;{<br/>AUDIO_SAMPLE_FMT_U8&nbsp;,&nbsp;AUDIO_SAMPLE_FMT_S16&nbsp;,&nbsp;AUDIO_SAMPLE_FMT_S32&nbsp;,&nbsp;AUDIO_SAMPLE_FMT_FLOAT&nbsp;,<br/>AUDIO_SAMPLE_FMT_DOUBLE&nbsp;,&nbsp;AUDIO_SAMPLE_FMT_U8P&nbsp;,&nbsp;AUDIO_SAMPLE_FMT_S16P&nbsp;,&nbsp;AUDIO_SAMPLE_FMT_S32P&nbsp;,<br/>AUDIO_SAMPLE_FMT_FLOATP&nbsp;,&nbsp;AUDIO_SAMPLE_FMT_DOUBLEP&nbsp;,&nbsp;AUDIO_SAMPLE_FMT_INVALID<br/>} | 枚举音频采样格式。 | 
| [CodecBufferType](_codec.md#codecbuffertype)&nbsp;{&nbsp;CODEC_BUFFER_TYPE_INVALID&nbsp;=&nbsp;0,&nbsp;CODEC_BUFFER_TYPE_VIRTUAL_ADDR&nbsp;=&nbsp;0x1,&nbsp;CODEC_BUFFER_TYPE_AVSHARE_MEM_FD&nbsp;=&nbsp;0x2,&nbsp;CODEC_BUFFER_TYPE_HANDLE&nbsp;=&nbsp;0x4,&nbsp;&nbsp;&nbsp;CODEC_BUFFER_TYPE_DYNAMIC_HANDLE&nbsp;=&nbsp;0x8&nbsp;} | 定义buffer类型。 | 
| [ShareMemTypes](_codec.md#sharememtypes)&nbsp;{&nbsp;READ_WRITE_TYPE&nbsp;=&nbsp;0x1,&nbsp;READ_ONLY_TYPE&nbsp;=&nbsp;0x2&nbsp;} | 枚举共享内存类型。 | 
| [OmxIndexCodecExType](_codec.md#omxindexcodecextype)&nbsp;{&nbsp;OMX_IndexExtBufferTypeStartUnused&nbsp;=&nbsp;OMX_IndexKhronosExtensions&nbsp;+&nbsp;0x00a00000,&nbsp;OMX_IndexParamSupportBufferType,&nbsp;OMX_IndexParamUseBufferType,&nbsp;OMX_IndexParamGetBufferHandleUsage&nbsp;} | 枚举Codec扩展index。 | 
| [OmxVideoExType](_codec.md#omxvideoextype)&nbsp;{&nbsp;OMX_VIDEO_CodingHEVC&nbsp;=&nbsp;11&nbsp;} | 枚举Codec扩展编码类型。 | 
