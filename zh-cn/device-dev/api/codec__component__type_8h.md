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
| [AvCodecRole](_codec.md#avcodecrole)&nbsp;{&nbsp;&nbsp;&nbsp;[MEDIA_ROLETYPE_IMAGE_JPEG](_codec.md#gga7c1ff03fc0cd5a8f738afae873b5d5d5ac261edd4c0d6eed15f6317024810dee2)&nbsp;=&nbsp;0,&nbsp;[MEDIA_ROLETYPE_VIDEO_AVC](_codec.md#gga7c1ff03fc0cd5a8f738afae873b5d5d5adebef2ce1107d74e5d4f91d3452c823d),&nbsp;[MEDIA_ROLETYPE_VIDEO_HEVC](_codec.md#gga7c1ff03fc0cd5a8f738afae873b5d5d5af84180255d50e9ae94cedfc35ad19056),&nbsp;[MEDIA_ROLETYPE_AUDIO_FIRST](_codec.md#gga7c1ff03fc0cd5a8f738afae873b5d5d5a9e653abe452b248670825bd468f59d20)&nbsp;=&nbsp;0x10000,&nbsp;&nbsp;&nbsp;[MEDIA_ROLETYPE_AUDIO_AAC](_codec.md#gga7c1ff03fc0cd5a8f738afae873b5d5d5ac9627d3deaca6bbf69f03c0dee1b6c05)&nbsp;=&nbsp;0x10000,&nbsp;[MEDIA_ROLETYPE_AUDIO_G711A](_codec.md#gga7c1ff03fc0cd5a8f738afae873b5d5d5a033c0faacbd270fa2c539686e6d60551),&nbsp;[MEDIA_ROLETYPE_AUDIO_G711U](_codec.md#gga7c1ff03fc0cd5a8f738afae873b5d5d5ae0170e900d835de44884f483b28b10f8),&nbsp;[MEDIA_ROLETYPE_AUDIO_G726](_codec.md#gga7c1ff03fc0cd5a8f738afae873b5d5d5a1bd136ced64ce1ab7b9e45fb0f5d75b6),&nbsp;&nbsp;&nbsp;[MEDIA_ROLETYPE_AUDIO_PCM](_codec.md#gga7c1ff03fc0cd5a8f738afae873b5d5d5a30e0f43909d411eb0f4c4fd8f9216dd8),&nbsp;[MEDIA_ROLETYPE_AUDIO_MP3](_codec.md#gga7c1ff03fc0cd5a8f738afae873b5d5d5aec847c178f28118703297fb600907338),&nbsp;[MEDIA_ROLETYPE_INVALID](_codec.md#gga7c1ff03fc0cd5a8f738afae873b5d5d5aee058a8e8a635efc2ed3328440a58e45)&nbsp;} | 枚举音视频编解码组件类型&nbsp;[更多...](_codec.md#avcodecrole) | 
| [AudioSampleFormat](_codec.md#audiosampleformat)&nbsp;{&nbsp;&nbsp;&nbsp;[AUDIO_SAMPLE_FORMAT_S8](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a2d8a330d2cb71268562e1c4da0c4eabc),&nbsp;[AUDIO_SAMPLE_FORMAT_S8P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a4eb79a5d6d99244902cfb5c65f225c80),&nbsp;[AUDIO_SAMPLE_FORMAT_U8](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757ab6d04d1d87a9a243b195ab6be183600e),&nbsp;[AUDIO_SAMPLE_FORMAT_U8P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757aeffb8620959b836e01622c7dc82ebc6d),&nbsp;&nbsp;&nbsp;[AUDIO_SAMPLE_FORMAT_S16](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a4422a2a04509e492ef823189d454d5a3),&nbsp;[AUDIO_SAMPLE_FORMAT_S16P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a11a1fb37c21f722383a37fc5e6075dfe),&nbsp;[AUDIO_SAMPLE_FORMAT_U16](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757af961944b4c8e77ee56defc30e6e61eb5),&nbsp;[AUDIO_SAMPLE_FORMAT_U16P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a08ba605e3e58479ebb7432ff5d6d0972),&nbsp;&nbsp;&nbsp;[AUDIO_SAMPLE_FORMAT_S24](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a102520af7c50d1ee4951e472f5f921e4),&nbsp;[AUDIO_SAMPLE_FORMAT_S24P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757ae245cf6bd637c1f1304b38746f8940d6),&nbsp;[AUDIO_SAMPLE_FORMAT_U24](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a0d5fc3d14030aad7bc17d894bf4fc5c9),&nbsp;[AUDIO_SAMPLE_FORMAT_U24P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a0e8b7681ec3461988cb7fdd0f3616b2e),&nbsp;&nbsp;&nbsp;[AUDIO_SAMPLE_FORMAT_S32](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a46819088770f843230d2b094fd8d14ba),&nbsp;[AUDIO_SAMPLE_FORMAT_S32P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a7883f8a4bede55eb4ffaf6ecb47f6841),&nbsp;[AUDIO_SAMPLE_FORMAT_U32](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757afae09ccb9fdae65e73e5584a4c3a6d16),&nbsp;[AUDIO_SAMPLE_FORMAT_U32P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a915025bfdcf9491a21b2d38dec7998cc),&nbsp;&nbsp;&nbsp;[AUDIO_SAMPLE_FORMAT_S64](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a2e5477f7cc05dcc271b50e570dfd0452),&nbsp;[AUDIO_SAMPLE_FORMAT_S64P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757ab07b4d40994980a8012a79dc4a69a794),&nbsp;[AUDIO_SAMPLE_FORMAT_U64](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a959950ea0f2b6c0e17d752640238c23b),&nbsp;[AUDIO_SAMPLE_FORMAT_U64P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757aad2c58522f7d16111756c1731bf52044),&nbsp;&nbsp;&nbsp;[AUDIO_SAMPLE_FORMAT_F32](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757ac3cb5729241a7f73210d97d4fe0002fe),&nbsp;[AUDIO_SAMPLE_FORMAT_F32P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a1121b8995d1083f61b2fa0afcc45143f),&nbsp;[AUDIO_SAMPLE_FORMAT_F64](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a72f064169d0282fa8a152aea546056c3),&nbsp;[AUDIO_SAMPLE_FORMAT_F64P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a1f0e407cd152b27f7b0ff761d26bb300),&nbsp;&nbsp;&nbsp;[AUDIO_SAMPLE_FMT_U8](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757aad65a5b895b3dba000167dbb6c19b9ab),&nbsp;[AUDIO_SAMPLE_FMT_S16](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a40335eaa7ca378540941909ed02b51a0),&nbsp;[AUDIO_SAMPLE_FMT_S32](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757ab98feafb8396c0190a4fb719a15ab7c5),&nbsp;[AUDIO_SAMPLE_FMT_FLOAT](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757ac2fb27a42b3f79e51dd71ce05b42f9db),&nbsp;&nbsp;&nbsp;[AUDIO_SAMPLE_FMT_DOUBLE](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757afb8b12c44b4799f59a533609b4c360b5),&nbsp;[AUDIO_SAMPLE_FMT_U8P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a8eb00238e7aa21d69f056d9292eb64d9),&nbsp;[AUDIO_SAMPLE_FMT_S16P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a93008db1a966fee4a91b515fedc78cec),&nbsp;[AUDIO_SAMPLE_FMT_S32P](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a6bb874f2726bb94d08914b366ae947d6),&nbsp;&nbsp;&nbsp;[AUDIO_SAMPLE_FMT_FLOATP](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a8a635bbd6c5df1a8a0fadb1d9602ea74),&nbsp;[AUDIO_SAMPLE_FMT_DOUBLEP](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a467bd88ce7f736a433425695ed0a0dbc),&nbsp;[AUDIO_SAMPLE_FMT_INVALID](_codec.md#gga97cfd5633b2133e7ebe42dbb9b03e757a5c8f7c2c0f84e70f609f8fd4ffd2c910)&nbsp;} | 枚举音频采样格式&nbsp;[更多...](_codec.md#audiosampleformat) | 
| [CodecBufferType](_codec.md#codecbuffertype)&nbsp;{&nbsp;&nbsp;&nbsp;[CODEC_BUFFER_TYPE_INVALID](_codec.md#ggaf63c168decbe7dc156ad3b4d575a0d46aba35b6e9b3ca08afcb012f723c07baee)&nbsp;=&nbsp;0,&nbsp;[CODEC_BUFFER_TYPE_VIRTUAL_ADDR](_codec.md#ggaf63c168decbe7dc156ad3b4d575a0d46a4df6de0078bcf908fdb12d0ec1486899)&nbsp;=&nbsp;0x1,&nbsp;[CODEC_BUFFER_TYPE_AVSHARE_MEM_FD](_codec.md#ggaf63c168decbe7dc156ad3b4d575a0d46aaba95e9bf8ffbd7fe7512bc842d70ca5)&nbsp;=&nbsp;0x2,&nbsp;[CODEC_BUFFER_TYPE_HANDLE](_codec.md#ggaf63c168decbe7dc156ad3b4d575a0d46a90db1a10a238c832937c7a0e02287a79)&nbsp;=&nbsp;0x4,&nbsp;&nbsp;&nbsp;[CODEC_BUFFER_TYPE_DYNAMIC_HANDLE](_codec.md#ggaf63c168decbe7dc156ad3b4d575a0d46a931ecc36727f5eb3baba00e0d2b8771e)&nbsp;=&nbsp;0x8&nbsp;} | 定义buffer类型&nbsp;[更多...](_codec.md#codecbuffertype) | 
| [ShareMemTypes](_codec.md#sharememtypes)&nbsp;{&nbsp;[READ_WRITE_TYPE](_codec.md#ggae84516e039a3963772dfeebd4937cb8daa268821c7f672c1b968aeed0ad745dd0)&nbsp;=&nbsp;0x1,&nbsp;[READ_ONLY_TYPE](_codec.md#ggae84516e039a3963772dfeebd4937cb8daa5af6f1eec0b9f19c72a1085cef7c0ff)&nbsp;=&nbsp;0x2&nbsp;} | 枚举共享内存类型&nbsp;[更多...](_codec.md#sharememtypes) | 
| [OmxIndexCodecExType](_codec.md#omxindexcodecextype)&nbsp;{&nbsp;[OMX_IndexExtBufferTypeStartUnused](_codec.md#gga0ab3a4efe29745d2b49944c4014e0c28a228f8b3c93f68da516a76db3f594625d)&nbsp;=&nbsp;OMX_IndexKhronosExtensions&nbsp;+&nbsp;0x00a00000,&nbsp;[OMX_IndexParamSupportBufferType](_codec.md#gga0ab3a4efe29745d2b49944c4014e0c28aaab75f888d711f3168327535312117fa),&nbsp;[OMX_IndexParamUseBufferType](_codec.md#gga0ab3a4efe29745d2b49944c4014e0c28a353c3ccfb9985619526c0c7a28c9cce8),&nbsp;[OMX_IndexParamGetBufferHandleUsage](_codec.md#gga0ab3a4efe29745d2b49944c4014e0c28a3dea5e61dc211290d54d79d35679199d)&nbsp;} | 枚举Codec扩展index&nbsp;[更多...](_codec.md#omxindexcodecextype) | 
| [OmxVideoExType](_codec.md#omxvideoextype)&nbsp;{&nbsp;[OMX_VIDEO_CodingHEVC](_codec.md#ggab1cbacdf16bc8912e69547b37022a9c1acf4ea0b624499e3a53c3b36f6217f6fe)&nbsp;=&nbsp;11&nbsp;} | 枚举Codec扩展编码类型&nbsp;[更多...](_codec.md#omxvideoextype) | 


## **详细描述**

Codec模块接口定义中使用的自定义数据类型。

Codec模块接口定义中使用的自定义数据类型，包括编解码类型、音视频参数、buffer定义等。

**Since：**

3.1

**Version：**

2.0
