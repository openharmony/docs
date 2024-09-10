# Codec（V2_0）


## 概述

Codec模块接口定义。

Codec模块涉及自定义类型、音视频编解码组件初始化、参数设置、数据的轮转和控制等。

**起始版本：** 4.1


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [CodecExtTypes.idl](_codec_ext_types_8idl_v20.md) | Codec模块接口定义中使用的扩展数据类型。 | 
| [CodecImageType.idl](_codec_image_type_8idl_v20.md) | 定义图像编解码器模块API中使用的自定义数据类型，包括编解码器图像参数、类型和缓冲区。 | 
| [CodecTypes.idl](_codec_types_8idl_v20.md) | Codec模块接口定义中使用的自定义数据类型。 | 
| [ICodecCallback.idl](_i_codec_callback_8idl_v20.md) | 主要包括回调函数接口定义。 | 
| [ICodecComponent.idl](_i_codec_component_8idl_v20.md) | 主要包括Codec组件接口定义。 | 
| [ICodecComponentManager.idl](_i_codec_component_manager_8idl_v20.md) | 主要包括Codec组件管理类接口。 | 
| [ICodecImage.idl](_i_codec_image_8idl_v20.md) | 定义图像编解码器的API。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[SupportBufferType](_support_buffer_type_v20.md) | 查询vendor层支持buffer类型信息。 | 
| struct&nbsp;&nbsp;[UseBufferType](_use_buffer_type_v20.md) | 设置输入输出端口对应的buffer类型。 | 
| struct&nbsp;&nbsp;[GetBufferHandleUsageParams](_get_buffer_handle_usage_params_v20.md) | 查询vendor层BufferHandle的默认usage配置。 | 
| struct&nbsp;&nbsp;[CodecVideoPortFormatParam](_codec_video_port_format_param_v20.md) | 设置输入输出端口的编解码格式。 | 
| struct&nbsp;&nbsp;[ControlRateConstantQuality](_control_rate_constant_quality_v20.md) | 控制编码画面质量参数。 | 
| struct&nbsp;&nbsp;[WorkingFrequencyParam](_working_frequency_param_v20.md) | 查询/设置vendor层编解码器工作频率。 | 
| struct&nbsp;&nbsp;[ProcessNameParam](_process_name_param_v20.md) | 设置调用者进程名。 | 
| struct&nbsp;&nbsp;[CodecVideoParamHevc](_codec_video_param_hevc_v20.md) | 定义HEVC视频编码格式信息。 | 
| struct&nbsp;&nbsp;[ColorAspects](_color_aspects_v20.md) | 色彩空间相关枚举 | 
| struct&nbsp;&nbsp;[CodecVideoColorspace](_codec_video_colorspace_v20.md) | 定义色彩空间参数信息 | 
| struct&nbsp;&nbsp;[CodecImageRegion](_codec_image_region_v20.md) | 定义图像区域信息。 | 
| struct&nbsp;&nbsp;[CodecImageBuffer](_codec_image_buffer_v20.md) | 定义编解码图像缓冲区信息。 | 
| struct&nbsp;&nbsp;[CodecImageCapability](_codec_image_capability_v20.md) | 定义图像编解码器功能。 | 
| struct&nbsp;&nbsp;[CodecJpegQuantTable](_codec_jpeg_quant_table_v20.md) | 定义jpeg图像量化表信息。 | 
| struct&nbsp;&nbsp;[CodecJpegHuffTable](_codec_jpeg_huff_table_v20.md) | 定义jpeg图像Huffman表信息。 | 
| struct&nbsp;&nbsp;[CodecJpegCompInfo](_codec_jpeg_comp_info_v20.md) | 定义jpeg图像的颜色分量信息。 | 
| struct&nbsp;&nbsp;[CodecJpegDecInfo](_codec_jpeg_dec_info_v20.md) | 定义jpeg图像解码信息。 | 
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
| interface&nbsp;&nbsp;[ICodecCallback](interface_i_codec_callback_v20.md) | Codec回调接口定义。 | 
| interface&nbsp;&nbsp;[ICodecComponent](interface_i_codec_component_v20.md) | Codec组件接口定义。 | 
| interface&nbsp;&nbsp;[ICodecComponentManager](interface_i_codec_component_manager_v20.md) | Codec组件管理类接口定义。 | 
| interface&nbsp;&nbsp;[ICodecImage](interface_i_codec_image_v20.md) | 图像编解码器模块接口。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [CodecVideoExType](#codecvideoextype) { CODEC_VIDEO_CodingVP9 = 10 , CODEC_VIDEO_CodingHEVC = 11 } | 视频编码格式枚举，对OMX原生枚举OMX_VIDEO_CODINGTYPE的补充。 | 
| [CodecHevcProfile](#codechevcprofile) {<br/>CODEC_HEVC_PROFILE_INVALID = 0x0 , CODEC_HEVC_PROFILE_MAIN = 0x1 , CODEC_HEVC_PROFILE_MAIN10 = 0x2 , CODEC_HEVC_PROFILE_MAIN_STILL = 0x3 , CODEC_HEVC_PROFILE_MAIN10_HDR10 = 0x1000 , CODEC_HEVC_PROFILE_MAIN10_HDR10_PLUS = 0x2000 , CODEC_HEVC_PROFILE_MAX = 0x7FFFFFFF<br/>} | HEVC的profile枚举。 | 
| [CodecHevcLevel](#codechevclevel) {<br/>CODEC_HEVC_LEVEL_INVALID = 0x0 , CODEC_HEVC_MAIN_TIER_LEVEL1 = 0x1 , CODEC_HEVC_HIGH_TIER_LEVEL1 = 0x2 , CODEC_HEVC_MAIN_TIER_LEVEL2 = 0x4 , CODEC_HEVC_HIGH_TIER_LEVEL2 = 0x8 , CODEC_HEVC_MAIN_TIER_LEVEL21 = 0x10 , CODEC_HEVC_HIGH_TIER_LEVEL21 = 0x20 , CODEC_HEVC_MAIN_TIER_LEVEL3 = 0x40 , CODEC_HEVC_HIGH_TIER_LEVEL3 = 0x80 , CODEC_HEVC_MAIN_TIER_LEVEL31 = 0x100 , CODEC_HEVC_HIGH_TIER_LEVEL31 = 0x200 , CODEC_HEVC_MAIN_TIER_LEVEL4 = 0x400 , CODEC_HEVC_HIGH_TIER_LEVEL4 = 0x800 , CODEC_HEVC_MAIN_TIER_LEVEL41 = 0x1000 , CODEC_HEVC_HIGH_TIER_LEVEL41 = 0x2000 , CODEC_HEVC_MAIN_TIER_LEVEL5 = 0x4000 , CODEC_HEVC_HIGH_TIER_LEVEL5 = 0x8000 , CODEC_HEVC_MAIN_TIER_LEVEL51 = 0x10000 , CODEC_HEVC_HIGH_TIER_LEVEL51 = 0x20000 , CODEC_HEVC_MAIN_TIER_LEVEL52 = 0x40000 , CODEC_HEVC_HIGH_TIER_LEVEL52 = 0x80000 , CODEC_HEVC_MAIN_TIER_LEVEL6 = 0x100000 , CODEC_HEVC_HIGH_TIER_LEVEL6 = 0x200000 , CODEC_HEVC_MAIN_TIER_LEVEL61 = 0x400000 , CODEC_HEVC_HIGH_TIER_LEVEL61 = 0x800000 , CODEC_HEVC_MAIN_TIER_LEVEL62 = 0x1000000 , CODEC_HEVC_HIGH_TIER_LEVEL62 = 0x2000000 , CODEC_HEVC_HIGH_TIER_MAX = 0x7FFFFFFF<br/>} | HEVC的level枚举。 | 
| [CodecBufferType](#codecbuffertype) {<br/>CODEC_BUFFER_TYPE_INVALID = 0 , CODEC_BUFFER_TYPE_VIRTUAL_ADDR = 0x1 , CODEC_BUFFER_TYPE_AVSHARE_MEM_FD = 0x2 , CODEC_BUFFER_TYPE_HANDLE = 0x4 , CODEC_BUFFER_TYPE_DYNAMIC_HANDLE = 0x8 , CODEC_BUFFER_TYPE_DMA_MEM_FD = 0x10<br/>} | 用于存储编解码视频帧的buffer类型。 | 
| [CodecIndexExType](#codecindexextype) {<br/>Codec_IndexExtBufferTypeStartUnused = 0x6F000000 + 0x00a00000 , Codec_IndexParamSupportBufferType , Codec_IndexParamUseBufferType , Codec_IndexParamGetBufferHandleUsage ,<br/>Codec_IndexCodecVideoPortFormat , Codec_IndexParamControlRateConstantQuality , Codec_IndexParamVideoHevc = 0x6F000000 + 0x00a00007 , Codec_IndexColorAspects ,<br/>Codec_IndexParamWorkingFrequency , Codec_IndexParamProcessName<br/>} | 编解码器参数索引，对OMX原生枚举OMX_INDEXTYPE的扩展。 | 
| [RangeType](#rangetype) { RANGE_UNSPECIFIED , RANGE_FULL , RANGE_LIMITED , RANGE_MAX = 0xff } | 视频像素值范围。 | 
| [Primaries](#primaries) {<br/>PRIMARIES_UNSPECIFIED , PRIMARIES_BT709 , PRIMARIES_BT470_6M , PRIMARIES_BT601_625 , PRIMARIES_BT601_525 , PRIMARIES_GENERICFILM , PRIMARIES_BT2020 , PRIMARIES_MAX = 0xff<br/>} | 设置视频色域。 | 
| [Transfer](#transfer) {<br/>TRANSFER_UNSPECIFIED , TRANSFER_LINEAR , TRANSFER_SRGB , TRANSFER_SMPTE170 , TRANSFER_GAMMA22 , TRANSFER_GAMMA28 , TRANSFER_PQ , TRANSFER_HLG , TRANSFER_SMPTE240 = 0x40 , TRANSFER_XVYCC , TRANSFER_BT1361 , TRANSFER_ST428 , TRANSFER_MAX = 0xff<br/>} | 设置视频传递函数。 | 
| [MatrixCoeffs](#matrixcoeffs) {<br/>MATRIX_UNSPECIFED , MATRIX_BT709 , MATRIX_FCC , MATRIX_BT601 ,<br/>MATRIX_SMPTE240 , MATRIX_BT2020 , MATRIX_BT2020CONSTANT , MATRIX_MAX = 0xff<br/>} | 设置视频矩阵系数。 | 
| [CodecImageRole](#codecimagerole) { CODEC_IMAGE_JPEG = 0 , CODEC_IMAGE_HEIF , CODEC_IMAGE_INVALID } | 编解码的图像格式枚举。 | 
| [CodecImageType](#codecimagetype) { CODEC_IMAGE_TYPE_DECODER = 0 , CODEC_IMAGE_TYPE_ENCODER , CODEC_IMAGE_TYPE_INVALID } | 定义图像编解码器类型。 | 
| [CodecType](#codectype) {<br/>VIDEO_DECODER , VIDEO_ENCODER , AUDIO_DECODER , AUDIO_ENCODER , INVALID_TYPE<br/>} | 枚举编解码的类型。 | 
| [AvCodecRole](#avcodecrole) {<br/>MEDIA_ROLETYPE_IMAGE_JPEG = 0, MEDIA_ROLETYPE_VIDEO_AVC, MEDIA_ROLETYPE_VIDEO_HEVC, MEDIA_ROLETYPE_AUDIO_FIRST = 0x10000,&nbsp;&nbsp;&nbsp;MEDIA_ROLETYPE_AUDIO_AAC = 0x10000, MEDIA_ROLETYPE_AUDIO_G711A, MEDIA_ROLETYPE_AUDIO_G711U, MEDIA_ROLETYPE_AUDIO_G726,&nbsp;&nbsp;&nbsp;MEDIA_ROLETYPE_AUDIO_PCM, MEDIA_ROLETYPE_AUDIO_MP3, MEDIA_ROLETYPE_INVALID<br/>} | 枚举音视频编解码组件类型。 | 
| [Profile](#profile) {<br/>INVALID_PROFILE = 0, AAC_LC_PROFILE = 0x1000, AAC_MAIN_PROFILE, AAC_HE_V1_PROFILE,&nbsp;&nbsp;&nbsp;AAC_HE_V2_PROFILE, AAC_LD_PROFILE, AAC_ELD_PROFILE, AVC_BASELINE_PROFILE = 0x2000,&nbsp;&nbsp;&nbsp;AVC_MAIN_PROFILE, AVC_HIGH_PROFILE, HEVC_MAIN_PROFILE = 0x3000, HEVC_MAIN_10_PROFILE<br/>} | 枚举Codec规格。 | 
| [CodecCapsMask](#codeccapsmask) {<br/>CODEC_CAP_ADAPTIVE_PLAYBACK = 0x1, CODEC_CAP_SECURE_PLAYBACK = 0x2, CODEC_CAP_TUNNEL_PLAYBACK = 0x4, CODEC_CAP_MULTI_PLANE = 0x10000<br/>} | 枚举播放能力。 | 
| [AudioSampleRate](#audiosamplerate) {<br/>AUD_SAMPLE_RATE_8000 = 8000, AUD_SAMPLE_RATE_12000 = 12000, AUD_SAMPLE_RATE_11025 = 11025, AUD_SAMPLE_RATE_16000 = 16000,&nbsp;&nbsp;&nbsp;AUD_SAMPLE_RATE_22050 = 22050, AUD_SAMPLE_RATE_24000 = 24000, AUD_SAMPLE_RATE_32000 = 32000, AUD_SAMPLE_RATE_44100 = 44100,&nbsp;&nbsp;&nbsp;AUD_SAMPLE_RATE_48000 = 48000, AUD_SAMPLE_RATE_64000 = 64000, AUD_SAMPLE_RATE_96000 = 96000, AUD_SAMPLE_RATE_INVALID<br/>} | 枚举音频采样率。 | 
| [AudioSampleFormat](#audiosampleformat) {<br/>AUDIO_SAMPLE_FMT_U8&nbsp;&nbsp;= 0 , AUDIO_SAMPLE_FMT_S16 , AUDIO_SAMPLE_FMT_S32 , AUDIO_SAMPLE_FMT_FLOAT , AUDIO_SAMPLE_FMT_DOUBLE , AUDIO_SAMPLE_FMT_U8P , AUDIO_SAMPLE_FMT_S16P , AUDIO_SAMPLE_FMT_S32P , AUDIO_SAMPLE_FMT_FLOATP , AUDIO_SAMPLE_FMT_DOUBLEP , AUDIO_SAMPLE_FMT_INVALID<br/>} | 枚举音频采样格式。 | 
| [CodecProcessMode](#codecprocessmode) {<br/>PROCESS_BLOCKING_INPUT_BUFFER = 0X1, PROCESS_BLOCKING_OUTPUT_BUFFER = 0X2, PROCESS_BLOCKING_CONTROL_FLOW = 0X4, PROCESS_NONBLOCKING_INPUT_BUFFER = 0X100,&nbsp;&nbsp;&nbsp;PROCESS_NONBLOCKING_OUTPUT_BUFFER = 0X200, PROCESS_NONBLOCKING_CONTROL_FLOW = 0X400<br/>} | 枚举编解码处理模式。 | 
| [ShareMemTypes](#sharememtypes) { READ_WRITE_TYPE = 0x1 , READ_ONLY_TYPE = 0x2 } | 枚举共享内存类型。 | 
| [BitRateMode](#bitratemode) {<br/>BIT_RATE_MODE_INVALID , BIT_RATE_MODE_VBR , BIT_RATE_MODE_CBR , BIT_RATE_MODE_CQ , BIT_RATE_MODE_VCBR , BIT_RATE_MODE_ABR<br/>} | 枚举比特率类型。 | 
| [CodecEventType](#codeceventtype) {<br/>CODEC_EVENT_CMD_COMPLETE , CODEC_EVENT_ERROR , CODEC_EVENT_MARK , CODEC_EVENT_PORT_SETTINGS_CHANGED , CODEC_EVENT_BUFFER_FLAG , CODEC_EVENT_RESOURCES_ACQUIRED , CODEC_EVENT_COMPONENT_RESUMED , CODEC_EVENT_DYNAMIC_RESOURCES_AVAILABLE , CODEC_EVENT_PORT_FORMAT_DETECTED , CODEC_EVENT_KHRONOS_EXTENSIONS = 0x6F000000 , CODEC_EVENT_VENDOR_START_UNUSED = 0x7F000000 , CODEC_EVENT_MAX = 0x7FFFFFFF<br/>} | 枚举组件状态。 | 
| [CodecCommandType](#codeccommandtype) {<br/>CODEC_COMMAND_STATE_SET , CODEC_COMMAND_FLUSH , CODEC_COMMAND_PORT_DISABLE , CODEC_COMMAND_PORT_ENABLE ,<br/>CODEC_COMMAND_MARK_BUFFER , CODEC_COMMAND_KHRONOS_EXTENSIONS = 0x6F000000 , CODEC_COMMAND_VENDOR_START_UNUSED = 0x7F000000 , CODEC_COMMAND_MAX = 0x7FFFFFFF<br/>} | 枚举ICodecComponent中SendCommand接口的cmd参数。 | 
| [CodecStateType](#codecstatetype) {<br/>CODEC_STATE_INVALID , CODEC_STATE_LOADED , CODEC_STATE_IDLE , CODEC_STATE_EXECUTING , CODEC_STATE_PAUSE , CODEC_STATE_WAIT_FOR_RESOURCES , CODEC_STATE_KHRONOS_EXTENSIONS = 0x6F000000 , CODEC_STATE_VENDOR_START_UNUSED = 0x7F000000 , CODEC_STATE_MAX = 0x7FFFFFFF<br/>} | 更改组件状态。 | 
| [CodecBufferSupplierType](#codecbuffersuppliertype) {<br/>CODEC_BUFFER_SUPPLY_UNSPECIFIED = 0 , CODEC_BUFFER_SUPPLY_INPUT , CODEC_BUFFER_SUPPLY_OUTPUT , CODEC_BUFFER_SUPPLY_KHRONOS_EXTENSIONS = 0x6F000000 , CODEC_BUFFER_SUPPLY_VENDOR_START_UNUSED = 0x7F000000 , CODEC_BUFFER_SUPPLY_MAX = 0x7FFFFFFF<br/>} | 表示端口供应商在两个端口之间建立隧道时的首选项。 | 


## 枚举类型说明


### AudioSampleFormat

```
enum AudioSampleFormat
```

**描述**


枚举音频采样格式。

对于平面格式的采样格式，每个声道的数据是独立存储在data中; 对于打包格式的采样格式，只使用第一个data，每个声道的数据是交错存储的。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_SAMPLE_FMT_U8 | 无符号8位整型，打包格式。 | 
| AUDIO_SAMPLE_FMT_S16 | 带符号16位整型, 打包格式。 | 
| AUDIO_SAMPLE_FMT_S32 | 带符号32位整型, 打包格式。 | 
| AUDIO_SAMPLE_FMT_FLOAT | 浮点型, 打包格式。 | 
| AUDIO_SAMPLE_FMT_DOUBLE | 双精度浮点型, 打包格式。 | 
| AUDIO_SAMPLE_FMT_U8P | 无符号8位整型, 平面格式。 | 
| AUDIO_SAMPLE_FMT_S16P | 带符号16位整型, 平面格式。 | 
| AUDIO_SAMPLE_FMT_S32P | 带符号32位整型, 平面格式。 | 
| AUDIO_SAMPLE_FMT_FLOATP | 浮点型, 平面格式。 | 
| AUDIO_SAMPLE_FMT_DOUBLEP | 双精度浮点型, 平面格式。 | 
| AUDIO_SAMPLE_FMT_INVALID | 无效采样格式。 | 


### AudioSampleRate

```
enum AudioSampleRate
```

**描述**


枚举音频采样率。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| AUD_SAMPLE_RATE_8000 | 8K采样率。 | 
| AUD_SAMPLE_RATE_12000 | 12K采样率。 | 
| AUD_SAMPLE_RATE_11025 | 11.025K采样率。 | 
| AUD_SAMPLE_RATE_16000 | 16K采样率。 | 
| AUD_SAMPLE_RATE_22050 | 22.050K采样率。 | 
| AUD_SAMPLE_RATE_24000 | 24K采样率。 | 
| AUD_SAMPLE_RATE_32000 | 32K采样率。 | 
| AUD_SAMPLE_RATE_44100 | 44.1K采样率。 | 
| AUD_SAMPLE_RATE_48000 | 48K采样率。 | 
| AUD_SAMPLE_RATE_64000 | 64K采样率。 | 
| AUD_SAMPLE_RATE_96000 | 96K采样率。 | 
| AUD_SAMPLE_RATE_INVALID | 无效采样率。 | 


### AvCodecRole

```
enum AvCodecRole
```

**描述**


枚举音视频编解码组件类型。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| MEDIA_ROLETYPE_IMAGE_JPEG | 图像JPEG媒体类型。 | 
| MEDIA_ROLETYPE_VIDEO_AVC | 视频H.264媒体类型。 | 
| MEDIA_ROLETYPE_VIDEO_HEVC | 视频H.265媒体类型。 | 
| MEDIA_ROLETYPE_AUDIO_FIRST | 音频编解码器类型。 | 
| MEDIA_ROLETYPE_AUDIO_AAC | 音频AAC媒体类型。 | 
| MEDIA_ROLETYPE_AUDIO_G711A | 音频G711A媒体类型。 | 
| MEDIA_ROLETYPE_AUDIO_G711U | 音频G711U媒体类型。 | 
| MEDIA_ROLETYPE_AUDIO_G726 | 音频G726媒体类型。 | 
| MEDIA_ROLETYPE_AUDIO_PCM | 音频PCM媒体类型。 | 
| MEDIA_ROLETYPE_AUDIO_MP3 | 音频MP3媒体类型。 | 
| MEDIA_ROLETYPE_INVALID | 无效媒体类型。 | 


### BitRateMode

```
enum BitRateMode
```

**描述**


枚举比特率类型。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| BIT_RATE_MODE_INVALID | 定义的一个无效值。 | 
| BIT_RATE_MODE_VBR | 可变比特率。 | 
| BIT_RATE_MODE_CBR | 恒定比特率。 | 
| BIT_RATE_MODE_CQ | 恒定质量。 | 
| BIT_RATE_MODE_VCBR | 受约束的可变位速率。 | 
| BIT_RATE_MODE_ABR | 平均比特率。 | 


### CodecBufferSupplierType

```
enum CodecBufferSupplierType
```

**描述**


表示端口供应商在两个端口之间建立隧道时的首选项。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| CODEC_BUFFER_SUPPLY_UNSPECIFIED | 提供缓冲区的端口未指定，或不指定 | 
| CODEC_BUFFER_SUPPLY_INPUT | 为输入端口提供缓冲区 | 
| CODEC_BUFFER_SUPPLY_OUTPUT | 为输出端口提供缓冲区 | 
| CODEC_BUFFER_SUPPLY_KHRONOS_EXTENSIONS | 用于引入Khronos标准扩展的保留区域 | 
| CODEC_BUFFER_SUPPLY_VENDOR_START_UNUSED | 用于引入供应商扩展的预留区域 | 
| CODEC_BUFFER_SUPPLY_MAX | 枚举的最大值 | 


### CodecBufferType

```
enum CodecBufferType
```

**描述**


用于存储编解码视频帧的buffer类型。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| CODEC_BUFFER_TYPE_INVALID | 无效的buffer类型 | 
| CODEC_BUFFER_TYPE_VIRTUAL_ADDR | Virtual address type | 
| CODEC_BUFFER_TYPE_AVSHARE_MEM_FD | 共享内存 | 
| CODEC_BUFFER_TYPE_HANDLE | Handle. | 
| CODEC_BUFFER_TYPE_DYNAMIC_HANDLE | Dynamic handle. | 
| CODEC_BUFFER_TYPE_DMA_MEM_FD | DMA内存 | 


### CodecCapsMask

```
enum CodecCapsMask
```

**描述**


枚举播放能力。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| CODEC_CAP_ADAPTIVE_PLAYBACK | 自适应播放能力。 | 
| CODEC_CAP_SECURE_PLAYBACK | 安全播放能力。 | 
| CODEC_CAP_TUNNEL_PLAYBACK | 通道播放能力。 | 
| CODEC_CAP_MULTI_PLANE | 视频图像平面/音频通道平面能力。 | 


### CodecCommandType

```
enum CodecCommandType
```

**描述**


枚举ICodecComponent中SendCommand接口的cmd参数。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| CODEC_COMMAND_STATE_SET | 更改组件状态 | 
| CODEC_COMMAND_FLUSH | 刷新组件的数据队列 | 
| CODEC_COMMAND_PORT_DISABLE | 禁用组件上的端口 | 
| CODEC_COMMAND_PORT_ENABLE | 启用组件上的端口 | 
| CODEC_COMMAND_MARK_BUFFER | 标记组件/缓冲区以进行观察 | 
| CODEC_COMMAND_KHRONOS_EXTENSIONS | 用于引入Khronos标准扩展的保留区域 | 
| CODEC_COMMAND_VENDOR_START_UNUSED | 用于引入供应商扩展的预留区域 | 
| CODEC_COMMAND_MAX | 枚举的最大值 | 


### CodecEventType

```
enum CodecEventType
```

**描述**


枚举组件状态。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| CODEC_EVENT_CMD_COMPLETE | 组件已成功完成命令 | 
| CODEC_EVENT_ERROR | 组件已检测到错误情况 | 
| CODEC_EVENT_MARK | 组件已检测到缓冲区标记 | 
| CODEC_EVENT_PORT_SETTINGS_CHANGED | 组件报告端口设置更改 | 
| CODEC_EVENT_BUFFER_FLAG | 组件已检测到EOS | 
| CODEC_EVENT_RESOURCES_ACQUIRED | 组件已被授予资源，并正在自动启动从OMX_StateWaitForResources状态更改为OMX_StateIdle | 
| CODEC_EVENT_COMPONENT_RESUMED | 组件回收由于重新占用的资源 | 
| CODEC_EVENT_DYNAMIC_RESOURCES_AVAILABLE | 组件已获取此前不可用的动态资源 | 
| CODEC_EVENT_PORT_FORMAT_DETECTED | 组件已经检测出数据格式 | 
| CODEC_EVENT_KHRONOS_EXTENSIONS | 用于引入Khronos标准扩展的保留区域 | 
| CODEC_EVENT_VENDOR_START_UNUSED | 用于引入供应商扩展的预留区域 | 
| CODEC_EVENT_MAX | 枚举的最大值 | 


### CodecHevcLevel

```
enum CodecHevcLevel
```

**描述**


HEVC的level枚举。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| CODEC_HEVC_LEVEL_INVALID | 无效的level | 
| CODEC_HEVC_MAIN_TIER_LEVEL1 | main tier level1 | 
| CODEC_HEVC_HIGH_TIER_LEVEL1 | high tier level1 | 
| CODEC_HEVC_MAIN_TIER_LEVEL2 | main tier level2 | 
| CODEC_HEVC_HIGH_TIER_LEVEL2 | high tier level2 | 
| CODEC_HEVC_MAIN_TIER_LEVEL21 | main tier level2.1 | 
| CODEC_HEVC_HIGH_TIER_LEVEL21 | high tier level2.1 | 
| CODEC_HEVC_MAIN_TIER_LEVEL3 | main tier level3 | 
| CODEC_HEVC_HIGH_TIER_LEVEL3 | high tier level3 | 
| CODEC_HEVC_MAIN_TIER_LEVEL31 | main tier level3.1 | 
| CODEC_HEVC_HIGH_TIER_LEVEL31 | high tier level3.1 | 
| CODEC_HEVC_MAIN_TIER_LEVEL4 | main tier level4 | 
| CODEC_HEVC_HIGH_TIER_LEVEL4 | high tier level4 | 
| CODEC_HEVC_MAIN_TIER_LEVEL41 | main tier level4.1 | 
| CODEC_HEVC_HIGH_TIER_LEVEL41 | high tier level4.1 | 
| CODEC_HEVC_MAIN_TIER_LEVEL5 | main tier level5 | 
| CODEC_HEVC_HIGH_TIER_LEVEL5 | high tier level5 | 
| CODEC_HEVC_MAIN_TIER_LEVEL51 | main tier level5.1 | 
| CODEC_HEVC_HIGH_TIER_LEVEL51 | high tier level5.1 | 
| CODEC_HEVC_MAIN_TIER_LEVEL52 | main tier level5.2 | 
| CODEC_HEVC_HIGH_TIER_LEVEL52 | high tier level5.2 | 
| CODEC_HEVC_MAIN_TIER_LEVEL6 | main tier level6 | 
| CODEC_HEVC_HIGH_TIER_LEVEL6 | high tier level6 | 
| CODEC_HEVC_MAIN_TIER_LEVEL61 | main tier level6.1 | 
| CODEC_HEVC_HIGH_TIER_LEVEL61 | high tier level6.1 | 
| CODEC_HEVC_MAIN_TIER_LEVEL62 | main tier level6.2 | 
| CODEC_HEVC_HIGH_TIER_LEVEL62 | high tier level6.2 | 
| CODEC_HEVC_HIGH_TIER_MAX | 最大值 | 


### CodecHevcProfile

```
enum CodecHevcProfile
```

**描述**


HEVC的profile枚举。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| CODEC_HEVC_PROFILE_INVALID | 无效的profile | 
| CODEC_HEVC_PROFILE_MAIN | main profile | 
| CODEC_HEVC_PROFILE_MAIN10 | main10 profile | 
| CODEC_HEVC_PROFILE_MAIN_STILL | main still profile | 
| CODEC_HEVC_PROFILE_MAIN10_HDR10 | main10 hdr10 profile | 
| CODEC_HEVC_PROFILE_MAIN10_HDR10_PLUS | main10 hdr10 plus profile | 
| CODEC_HEVC_PROFILE_MAX | 最大值 | 


### CodecImageRole

```
enum CodecImageRole
```

**描述**


编解码的图像格式枚举。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| CODEC_IMAGE_JPEG | Jpeg格式. | 
| CODEC_IMAGE_HEIF | Heif格式. | 
| CODEC_IMAGE_INVALID | 无效的格式 | 


### CodecImageType

```
enum CodecImageType
```

**描述**


定义图像编解码器类型。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| CODEC_IMAGE_TYPE_DECODER | 图像解码器。 | 
| CODEC_IMAGE_TYPE_ENCODER | 图像编码器。 | 
| CODEC_IMAGE_TYPE_INVALID | 无效类型 | 


### CodecIndexExType

```
enum CodecIndexExType
```

**描述**


编解码器参数索引，对OMX原生枚举OMX_INDEXTYPE的扩展。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| Codec_IndexExtBufferTypeStartUnused | 扩展BufferType索引，value = Codec_IndexExtBufferTypeStartUnused + 0x00a00000 | 
| Codec_IndexParamSupportBufferType | 支持的Buffer类型 | 
| Codec_IndexParamUseBufferType | 可用的Buffer类型 | 
| Codec_IndexParamGetBufferHandleUsage | 获取Buffer使用率 | 
| Codec_IndexCodecVideoPortFormat | [CodecVideoPortFormatParam](_codec_video_port_format_param_v20.md) | 
| Codec_IndexParamControlRateConstantQuality | [ControlRateConstantQuality](_control_rate_constant_quality_v20.md) | 
| Codec_IndexParamVideoHevc | Codec_IndexParamVideoHevc | 
| Codec_IndexColorAspects | range/primary/transfer/matrix | 
| Codec_IndexParamWorkingFrequency | [WorkingFrequencyParam](_working_frequency_param_v20.md) | 
| Codec_IndexParamProcessName | [ProcessNameParam](_process_name_param_v20.md) | 


### CodecProcessMode

```
enum CodecProcessMode
```

**描述**


枚举编解码处理模式。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| PROCESS_BLOCKING_INPUT_BUFFER | 同步模式输入buffer。 | 
| PROCESS_BLOCKING_OUTPUT_BUFFER | 同步模式输出buffer。 | 
| PROCESS_BLOCKING_CONTROL_FLOW | 同步模式控制流。 | 
| PROCESS_NONBLOCKING_INPUT_BUFFER | 异步模式输入buffer。 | 
| PROCESS_NONBLOCKING_OUTPUT_BUFFER | 异步模式输出buffer。 | 
| PROCESS_NONBLOCKING_CONTROL_FLOW | 异步模式控制流。 | 


### CodecStateType

```
enum CodecStateType
```

**描述**


更改组件状态。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| CODEC_STATE_INVALID | 组件已检测到其内部数据结构已损坏，以至于无法正确确定其状态 | 
| CODEC_STATE_LOADED | 组件已加载，但尚未完成初始化。ICodecComponent.SetParameter 和ICodecComponent.GetParameter是允许发送到处于此状态的组件的唯一有效函数 | 
| CODEC_STATE_IDLE | 组件初始化已成功完成，组件已准备好启动 | 
| CODEC_STATE_EXECUTING | 组件已接受启动命令并正在处理数据（如果数据可用） | 
| CODEC_STATE_PAUSE | 组件已收到暂停命令 | 
| CODEC_STATE_WAIT_FOR_RESOURCES | 组件正在等待资源，无论是在抢占之后还是在获得请求的资源之前 | 
| CODEC_STATE_KHRONOS_EXTENSIONS | 用于引入Khronos标准扩展的保留区域 | 
| CODEC_STATE_VENDOR_START_UNUSED | 用于引入供应商扩展的预留区域 | 
| CODEC_STATE_MAX | 枚举最大值 | 


### CodecType

```
enum CodecType
```

**描述**


枚举编解码的类型。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| VIDEO_DECODER | 视频解码类型。 | 
| VIDEO_ENCODER | 视频编码类型。 | 
| AUDIO_DECODER | 音频解码类型。 | 
| AUDIO_ENCODER | 音频编码类型。 | 
| INVALID_TYPE | 无效类型。 | 


### CodecVideoExType

```
enum CodecVideoExType
```

**描述**


视频编码格式枚举，对OMX原生枚举OMX_VIDEO_CODINGTYPE的补充。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| CODEC_VIDEO_CodingVP9 | VP9格式 | 
| CODEC_VIDEO_CodingHEVC | HEVC格式 | 


### MatrixCoeffs

```
enum MatrixCoeffs
```

**描述**


设置视频矩阵系数。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| MATRIX_UNSPECIFED | 未指定的矩阵 | 
| MATRIX_BT709 | Rec. ITU-R BT.709-6 | 
| MATRIX_FCC | United States Federal Communications Commission | 
| MATRIX_BT601 | Rec. ITU-R BT.601-7 or Rec. ITU-R BT.470-6 System B,G | 
| MATRIX_SMPTE240 | SMPTE ST 240 | 
| MATRIX_BT2020 | Rec. ITU-R BT.2100-2 (非恒定亮度) | 
| MATRIX_BT2020CONSTANT | Rec. ITU-R BT.2100-2 (恒定亮度) | 
| MATRIX_MAX | 最大值 | 


### Primaries

```
enum Primaries
```

**描述**


设置视频色域。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| PRIMARIES_UNSPECIFIED | 未指定的色域 | 
| PRIMARIES_BT709 | Rec. ITU-R BT.709-6 | 
| PRIMARIES_BT470_6M | Rec. ITU-R BT.470-6 System M | 
| PRIMARIES_BT601_625 | Rec. ITU-R BT.601-7 625 or Rec. ITU-R BT.470-6 System B,G | 
| PRIMARIES_BT601_525 | Rec. ITU-R BT.601-7 525 or SMPTE ST 170 or SMPTE ST 240 | 
| PRIMARIES_GENERICFILM | Generic Film | 
| PRIMARIES_BT2020 | Rec. ITU-R BT.2020-2 or Rec. ITU-R BT.2100-2 | 
| PRIMARIES_MAX | 最大值 | 


### Profile

```
enum Profile
```

**描述**


枚举Codec规格。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| INVALID_PROFILE | 无效的规格。 | 
| AAC_LC_PROFILE | AAC低复杂度规格。 | 
| AAC_MAIN_PROFILE | AAC主规格。 | 
| AAC_HE_V1_PROFILE | AAC高效率和频带重现规格，又称为HEAAC、AAC+、或者AACPlusV1。 | 
| AAC_HE_V2_PROFILE | AAC高效率和频带重现以及变量立体声规格，又称为AAC++或者AACPlusV2。 | 
| AAC_LD_PROFILE | AAC低延迟规格。 | 
| AAC_ELD_PROFILE | AAC增强型低延迟规格。 | 
| AVC_BASELINE_PROFILE | H.264低规格。 | 
| AVC_MAIN_PROFILE | H.264主规格。 | 
| AVC_HIGH_PROFILE | H.264高规格。 | 
| HEVC_MAIN_PROFILE | H.265主规格。 | 
| HEVC_MAIN_10_PROFILE | H.265 10比特主规格。 | 


### RangeType

```
enum RangeType
```

**描述**


视频像素值范围。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| RANGE_UNSPECIFIED | 未指定的range类型 | 
| RANGE_FULL | full range | 
| RANGE_LIMITED | limited range | 
| RANGE_MAX | 最大值 | 


### ShareMemTypes

```
enum ShareMemTypes
```

**描述**


枚举共享内存类型。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| READ_WRITE_TYPE | 可读可写的共享内存类型。 | 
| READ_ONLY_TYPE | 只读的共享内存类型。 | 


### Transfer

```
enum Transfer
```

**描述**


设置视频传递函数。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| TRANSFER_UNSPECIFIED | 未指定的类型 | 
| TRANSFER_LINEAR | 线性传递特性 | 
| TRANSFER_SRGB | IEC 61966-2-1 sRGB | 
| TRANSFER_SMPTE170 | SMPTE ST 170 or Rec. ITU-R BT.709-6 or BT.601-7 or BT.2020-2 | 
| TRANSFER_GAMMA22 | Rec. ITU-R BT.470-6 System M | 
| TRANSFER_GAMMA28 | Rec. ITU-R BT.470-6 System B,G | 
| TRANSFER_PQ | Rec. ITU-R BT.2100-2 perceptual quantization (PQ) system | 
| TRANSFER_HLG | Rec. ITU-R BT.2100-2 hybrid log gamma (HLG) system | 
| TRANSFER_SMPTE240 | SMPTE ST 240 | 
| TRANSFER_XVYCC | IEC 61966-2-4 | 
| TRANSFER_BT1361 | Rec. ITU-R BT.1361-0 extended colour gamut system | 
| TRANSFER_ST428 | SMPTE ST 428-1 | 
| TRANSFER_MAX | 最大值 | 
