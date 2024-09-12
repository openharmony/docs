# CodecTypes.idl


## 概述

Codec模块接口定义中使用的自定义数据类型。

Codec模块接口定义中使用的自定义数据类型，包括编解码类型、音视频参数、buffer定义等。

模块包路径：ohos.hdi.codec.v2_0

**起始版本：** 4.1

**相关模块：**[Codec](_codec_v20.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[Alignment](_alignment_v20.md) | 对齐结构定义。 | 
| struct&nbsp;&nbsp;[Rect](_rect_v20.md) | 矩形的定义。 | 
| struct&nbsp;&nbsp;[RangeValue](_range_value_v20.md) | 取值范围的定义。 | 
| struct&nbsp;&nbsp;[CodecVideoPortCap](_codec_video_port_cap_v20.md) | 定义视频编解码能力。 | 
| struct&nbsp;&nbsp;[CodecAudioPortCap](_codec_audio_port_cap_v20.md) | 定义音频编解码能力。 | 
| struct&nbsp;&nbsp;[PortCap](_port_cap_v20.md) | 定义音视频编解码能力。 | 
| struct&nbsp;&nbsp;[OmxVerType](_omx_ver_type_v20.md) | 定义组件的版本信息。 | 
| union&nbsp;&nbsp;[OMX_VERSIONTYPE](union_o_m_x___v_e_r_s_i_o_n_t_y_p_e_v20.md) | 定义组件的版本信息。 | 
| struct&nbsp;&nbsp;[CodecCompCapability](_codec_comp_capability_v20.md) | 定义Codec编解码能力。 | 
| struct&nbsp;&nbsp;[OmxCodecBuffer](_omx_codec_buffer_v20.md) | Codec buffer信息的定义。 | 
| struct&nbsp;&nbsp;[OMX_TUNNELSETUPTYPE](_o_m_x___t_u_n_n_e_l_s_e_t_u_p_t_y_p_e_v20.md) | 用于将数据从输出端口传递到输入端口。 | 
| struct&nbsp;&nbsp;[CompVerInfo](_comp_ver_info_v20.md) | 定义了组件信息，包含组件名，UUID， 组件版本以及spec版本。 | 
| struct&nbsp;&nbsp;[EventInfo](_event_info_v20.md) | 定义事件上报信息。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [CodecType](_codec_v20.md#codectype) {<br/>VIDEO_DECODER , VIDEO_ENCODER , AUDIO_DECODER , AUDIO_ENCODER , INVALID_TYPE<br/>} | 枚举编解码的类型。 | 
| [AvCodecRole](_codec_v20.md#avcodecrole) {<br/>MEDIA_ROLETYPE_IMAGE_JPEG = 0, MEDIA_ROLETYPE_VIDEO_AVC, MEDIA_ROLETYPE_VIDEO_HEVC, MEDIA_ROLETYPE_AUDIO_FIRST = 0x10000,&nbsp;&nbsp;&nbsp;MEDIA_ROLETYPE_AUDIO_AAC = 0x10000, MEDIA_ROLETYPE_AUDIO_G711A, MEDIA_ROLETYPE_AUDIO_G711U, MEDIA_ROLETYPE_AUDIO_G726,&nbsp;&nbsp;&nbsp;MEDIA_ROLETYPE_AUDIO_PCM, MEDIA_ROLETYPE_AUDIO_MP3, MEDIA_ROLETYPE_INVALID<br/>} | 枚举音视频编解码组件类型。 | 
| [Profile](_codec_v20.md#profile) {<br/>INVALID_PROFILE = 0, AAC_LC_PROFILE = 0x1000, AAC_MAIN_PROFILE, AAC_HE_V1_PROFILE,&nbsp;&nbsp;&nbsp;AAC_HE_V2_PROFILE, AAC_LD_PROFILE, AAC_ELD_PROFILE, AVC_BASELINE_PROFILE = 0x2000,&nbsp;&nbsp;&nbsp;AVC_MAIN_PROFILE, AVC_HIGH_PROFILE, HEVC_MAIN_PROFILE = 0x3000, HEVC_MAIN_10_PROFILE<br/>} | 枚举Codec规格。 | 
| [CodecCapsMask](_codec_v20.md#codeccapsmask) {<br/>CODEC_CAP_ADAPTIVE_PLAYBACK = 0x1, CODEC_CAP_SECURE_PLAYBACK = 0x2, CODEC_CAP_TUNNEL_PLAYBACK = 0x4, CODEC_CAP_MULTI_PLANE = 0x10000<br/>} | 枚举播放能力。 | 
| [AudioSampleRate](_codec_v20.md#audiosamplerate) {<br/>AUD_SAMPLE_RATE_8000 = 8000, AUD_SAMPLE_RATE_12000 = 12000, AUD_SAMPLE_RATE_11025 = 11025, AUD_SAMPLE_RATE_16000 = 16000,&nbsp;&nbsp;&nbsp;AUD_SAMPLE_RATE_22050 = 22050, AUD_SAMPLE_RATE_24000 = 24000, AUD_SAMPLE_RATE_32000 = 32000, AUD_SAMPLE_RATE_44100 = 44100,&nbsp;&nbsp;&nbsp;AUD_SAMPLE_RATE_48000 = 48000, AUD_SAMPLE_RATE_64000 = 64000, AUD_SAMPLE_RATE_96000 = 96000, AUD_SAMPLE_RATE_INVALID<br/>} | 枚举音频采样率。 | 
| [AudioSampleFormat](_codec_v20.md#audiosampleformat) {<br/>AUDIO_SAMPLE_FMT_U8&nbsp;&nbsp;= 0 , AUDIO_SAMPLE_FMT_S16 , AUDIO_SAMPLE_FMT_S32 , AUDIO_SAMPLE_FMT_FLOAT , AUDIO_SAMPLE_FMT_DOUBLE , AUDIO_SAMPLE_FMT_U8P , AUDIO_SAMPLE_FMT_S16P , AUDIO_SAMPLE_FMT_S32P , AUDIO_SAMPLE_FMT_FLOATP , AUDIO_SAMPLE_FMT_DOUBLEP , AUDIO_SAMPLE_FMT_INVALID<br/>} | 枚举音频采样格式。 | 
| [CodecProcessMode](_codec_v20.md#codecprocessmode) {<br/>PROCESS_BLOCKING_INPUT_BUFFER = 0X1, PROCESS_BLOCKING_OUTPUT_BUFFER = 0X2, PROCESS_BLOCKING_CONTROL_FLOW = 0X4, PROCESS_NONBLOCKING_INPUT_BUFFER = 0X100,&nbsp;&nbsp;&nbsp;PROCESS_NONBLOCKING_OUTPUT_BUFFER = 0X200, PROCESS_NONBLOCKING_CONTROL_FLOW = 0X400<br/>} | 枚举编解码处理模式。 | 
| [ShareMemTypes](_codec_v20.md#sharememtypes) { READ_WRITE_TYPE = 0x1 , READ_ONLY_TYPE = 0x2 } | 枚举共享内存类型。 | 
| [BitRateMode](_codec_v20.md#bitratemode) {<br/>BIT_RATE_MODE_INVALID , BIT_RATE_MODE_VBR , BIT_RATE_MODE_CBR , BIT_RATE_MODE_CQ , BIT_RATE_MODE_VCBR , BIT_RATE_MODE_ABR<br/>} | 枚举比特率类型。 | 
| [CodecEventType](_codec_v20.md#codeceventtype) {<br/>CODEC_EVENT_CMD_COMPLETE , CODEC_EVENT_ERROR , CODEC_EVENT_MARK , CODEC_EVENT_PORT_SETTINGS_CHANGED , CODEC_EVENT_BUFFER_FLAG , CODEC_EVENT_RESOURCES_ACQUIRED , CODEC_EVENT_COMPONENT_RESUMED , CODEC_EVENT_DYNAMIC_RESOURCES_AVAILABLE , CODEC_EVENT_PORT_FORMAT_DETECTED , CODEC_EVENT_KHRONOS_EXTENSIONS = 0x6F000000 , CODEC_EVENT_VENDOR_START_UNUSED = 0x7F000000 , CODEC_EVENT_MAX = 0x7FFFFFFF<br/>} | 枚举组件状态。 | 
| [CodecCommandType](_codec_v20.md#codeccommandtype) {<br/>CODEC_COMMAND_STATE_SET , CODEC_COMMAND_FLUSH , CODEC_COMMAND_PORT_DISABLE , CODEC_COMMAND_PORT_ENABLE ,<br/>CODEC_COMMAND_MARK_BUFFER , CODEC_COMMAND_KHRONOS_EXTENSIONS = 0x6F000000 , CODEC_COMMAND_VENDOR_START_UNUSED = 0x7F000000 , CODEC_COMMAND_MAX = 0x7FFFFFFF<br/>} | 枚举ICodecComponent中SendCommand接口的cmd参数。 | 
| [CodecStateType](_codec_v20.md#codecstatetype) {<br/>CODEC_STATE_INVALID , CODEC_STATE_LOADED , CODEC_STATE_IDLE , CODEC_STATE_EXECUTING , CODEC_STATE_PAUSE , CODEC_STATE_WAIT_FOR_RESOURCES , CODEC_STATE_KHRONOS_EXTENSIONS = 0x6F000000 , CODEC_STATE_VENDOR_START_UNUSED = 0x7F000000 , CODEC_STATE_MAX = 0x7FFFFFFF<br/>} | 更改组件状态。 | 
| [CodecBufferSupplierType](_codec_v20.md#codecbuffersuppliertype) {<br/>CODEC_BUFFER_SUPPLY_UNSPECIFIED = 0 , CODEC_BUFFER_SUPPLY_INPUT , CODEC_BUFFER_SUPPLY_OUTPUT , CODEC_BUFFER_SUPPLY_KHRONOS_EXTENSIONS = 0x6F000000 , CODEC_BUFFER_SUPPLY_VENDOR_START_UNUSED = 0x7F000000 , CODEC_BUFFER_SUPPLY_MAX = 0x7FFFFFFF<br/>} | 表示端口供应商在两个端口之间建立隧道时的首选项。 | 
