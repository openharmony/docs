# codec_component_type.h


## **概述**

**所属模块:**

[Codec](_codec.md)


## **汇总**


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [VideoPortCap](_video_port_cap.md) | 定义视频编解码能力&nbsp;[更多...](_video_port_cap.md) | 
| [AudioPortCap](_audio_port_cap.md) | 定义音频编解码能力&nbsp;[更多...](_audio_port_cap.md) | 
| [PortCap](union_port_cap.md) | 定义音视频编解码能力&nbsp;[更多...](union_port_cap.md) | 
| [CodecCompCapability](_codec_comp_capability.md) | 定义Codec编解码能力&nbsp;[更多...](_codec_comp_capability.md) | 
| [OmxCodecBuffer](_omx_codec_buffer.md) | Codec&nbsp;buffer信息的定义&nbsp;[更多...](_omx_codec_buffer.md) | 
| [CompVerInfo](_comp_ver_info.md) | 定义组件版本信息&nbsp;[更多...](_comp_ver_info.md) | 
| [EventInfo](_event_info.md) | 定义事件上报信息&nbsp;[更多...](_event_info.md) | 
| [SupportBufferType](_support_buffer_type.md) | SupportBuffer类型定义.&nbsp;[更多...](_support_buffer_type.md) | 
| [UseBufferType](_use_buffer_type.md) | UseBuffer类型定义&nbsp;[更多...](_use_buffer_type.md) | 
| [GetBufferHandleUsageParams](_get_buffer_handle_usage_params.md) | BufferHandleUsage类型定义&nbsp;[更多...](_get_buffer_handle_usage_params.md) | 


### 宏定义

  | 宏定义 | 描述 | 
| -------- | -------- |
| [SAMPLE_FMT_NUM](_codec.md#ga9bda75c363e9bcff915cdd521dd7ba84)&nbsp;&nbsp;&nbsp;32 | 采样格式最大值 | 
| [UUID_LENGTH](_codec.md#ga9226162b034cc837cd977f0fcf611c2c)&nbsp;&nbsp;&nbsp;128 | 定义UUID长度 | 
| [PIX_FORMAT_NUM](_codec.md#gadb8c6478388b68c09835ebe093a8920a)&nbsp;&nbsp;&nbsp;16 | 支持的像素格式数组大小 | 
| [SAMPLE_FORMAT_NUM](_codec.md#gaf958b9cc535f6260e2e8b7ce42c89946)&nbsp;&nbsp;&nbsp;12 | 支持的音频采样格式数组大小 | 
| [SAMPLE_RATE_NUM](_codec.md#ga0d905eaa05b4b6fcec76924eb795d7fe)&nbsp;&nbsp;&nbsp;16 | 支持的音频采样率数组大小 | 
| [CHANNEL_NUM](_codec.md#ga6511732d5b29a6781cf38783157f21e1)&nbsp;&nbsp;&nbsp;16 | 支持的音频通道数组大小 | 
| [NAME_LENGTH](_codec.md#gaf71324c57f05ff9e24bd384925dd6b17)&nbsp;&nbsp;&nbsp;32 | 组件名称大小 | 
| [PROFILE_NUM](_codec.md#gaab6353cb3662bdc672ae8ab90df529ce)&nbsp;&nbsp;&nbsp;256 | 支持的profile数组大小 | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [AvCodecRole](_codec.md#avcodecrole)&nbsp;{&nbsp;MEDIA_ROLETYPE_IMAGE_JPEG&nbsp;=&nbsp;0,&nbsp;MEDIA_ROLETYPE_VIDEO_AVC,&nbsp;MEDIA_ROLETYPE_VIDEO_HEVC,&nbsp;MEDIA_ROLETYPE_AUDIO_FIRST&nbsp;=&nbsp;0x10000,&nbsp;&nbsp;&nbsp;MEDIA_ROLETYPE_AUDIO_AAC&nbsp;=&nbsp;0x10000,&nbsp;MEDIA_ROLETYPE_AUDIO_G711A,&nbsp;MEDIA_ROLETYPE_AUDIO_G711U,&nbsp;MEDIA_ROLETYPE_AUDIO_G726,&nbsp;&nbsp;&nbsp;MEDIA_ROLETYPE_AUDIO_PCM,&nbsp;MEDIA_ROLETYPE_AUDIO_MP3,&nbsp;MEDIA_ROLETYPE_INVALID&nbsp;} | 枚举音视频编解码组件类型&nbsp;[更多...](_codec.md#avcodecrole) | 
| [AudioSampleFormat](_codec.md#audiosampleformat)&nbsp;{&nbsp;AUDIO_SAMPLE_FORMAT_S8,&nbsp;AUDIO_SAMPLE_FORMAT_S8P,&nbsp;AUDIO_SAMPLE_FORMAT_U8,&nbsp;AUDIO_SAMPLE_FORMAT_U8P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_S16,&nbsp;AUDIO_SAMPLE_FORMAT_S16P,&nbsp;AUDIO_SAMPLE_FORMAT_U16,&nbsp;AUDIO_SAMPLE_FORMAT_U16P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_S24,&nbsp;AUDIO_SAMPLE_FORMAT_S24P,&nbsp;AUDIO_SAMPLE_FORMAT_U24,&nbsp;AUDIO_SAMPLE_FORMAT_U24P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_S32,&nbsp;AUDIO_SAMPLE_FORMAT_S32P,&nbsp;AUDIO_SAMPLE_FORMAT_U32,&nbsp;AUDIO_SAMPLE_FORMAT_U32P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_S64,&nbsp;AUDIO_SAMPLE_FORMAT_S64P,&nbsp;AUDIO_SAMPLE_FORMAT_U64,&nbsp;AUDIO_SAMPLE_FORMAT_U64P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_F32,&nbsp;AUDIO_SAMPLE_FORMAT_F32P,&nbsp;AUDIO_SAMPLE_FORMAT_F64,&nbsp;AUDIO_SAMPLE_FORMAT_F64P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FMT_U8,&nbsp;AUDIO_SAMPLE_FMT_S16,&nbsp;AUDIO_SAMPLE_FMT_S32,&nbsp;AUDIO_SAMPLE_FMT_FLOAT,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FMT_DOUBLE,&nbsp;AUDIO_SAMPLE_FMT_U8P,&nbsp;AUDIO_SAMPLE_FMT_S16P,&nbsp;AUDIO_SAMPLE_FMT_S32P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FMT_FLOATP,&nbsp;AUDIO_SAMPLE_FMT_DOUBLEP,&nbsp;AUDIO_SAMPLE_FMT_INVALID&nbsp;} | 枚举音频采样格式&nbsp;[更多...](_codec.md#audiosampleformat) | 
| [CodecBufferType](_codec.md#codecbuffertype)&nbsp;{&nbsp;CODEC_BUFFER_TYPE_INVALID&nbsp;=&nbsp;0,&nbsp;CODEC_BUFFER_TYPE_VIRTUAL_ADDR&nbsp;=&nbsp;0x1,&nbsp;CODEC_BUFFER_TYPE_AVSHARE_MEM_FD&nbsp;=&nbsp;0x2,&nbsp;CODEC_BUFFER_TYPE_HANDLE&nbsp;=&nbsp;0x4,&nbsp;&nbsp;&nbsp;CODEC_BUFFER_TYPE_DYNAMIC_HANDLE&nbsp;=&nbsp;0x8&nbsp;} | 定义buffer类型&nbsp;[更多...](_codec.md#codecbuffertype) | 
| [ShareMemTypes](_codec.md#sharememtypes)&nbsp;{&nbsp;READ_WRITE_TYPE&nbsp;=&nbsp;0x1,&nbsp;READ_ONLY_TYPE&nbsp;=&nbsp;0x2&nbsp;} | 枚举共享内存类型&nbsp;[更多...](_codec.md#sharememtypes) | 
| [OmxIndexCodecExType](_codec.md#omxindexcodecextype)&nbsp;{&nbsp;OMX_IndexExtBufferTypeStartUnused&nbsp;=&nbsp;OMX_IndexKhronosExtensions&nbsp;+&nbsp;0x00a00000,&nbsp;OMX_IndexParamSupportBufferType,&nbsp;OMX_IndexParamUseBufferType,&nbsp;OMX_IndexParamGetBufferHandleUsage&nbsp;} | 枚举Codec扩展index&nbsp;[更多...](_codec.md#omxindexcodecextype) | 
| [OmxVideoExType](_codec.md#omxvideoextype)&nbsp;{&nbsp;OMX_VIDEO_CodingHEVC&nbsp;=&nbsp;11&nbsp;} | 枚举Codec扩展编码类型&nbsp;[更多...](_codec.md#omxvideoextype) | 


## **详细描述**

Codec模块接口定义中使用的自定义数据类型。

Codec模块接口定义中使用的自定义数据类型，包括编解码类型、音视频参数、buffer定义等。

**Since：**

3.1

**Version：**

2.0
