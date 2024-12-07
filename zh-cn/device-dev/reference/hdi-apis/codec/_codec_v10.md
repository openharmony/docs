# Codec（V1_0）


## 概述

Codec模块接口定义。

Codec模块涉及自定义类型、音视频编解码组件初始化、参数设置、数据的轮转和控制等。

**起始版本：** 3.2


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [CodecImageType.idl](_codec_image_type_8idl_v10.md) | 定义图像编解码器模块API中使用的自定义数据类型，包括编解码器图像参数、类型和缓冲区。 | 
| [CodecTypes.idl](_codec_types_8idl_v10.md) | Codec模块接口定义中使用的自定义数据类型。 | 
| [ICodecCallback.idl](_i_codec_callback_8idl_v10.md) | 主要包括回调函数接口定义。 | 
| [ICodecComponent.idl](_i_codec_component_8idl_v10.md) | 主要包括Codec组件接口定义。 | 
| [ICodecComponentManager.idl](_i_codec_component_manager_8idl_v10.md) | 主要包括Codec组件管理类接口。 | 
| [ICodecImage.idl](_i_codec_image_8idl_v10.md) | 定义图像编解码器的API。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[CodecImageRegion](_codec_image_region_v10.md) | 定义图像区域信息。 | 
| struct&nbsp;&nbsp;[CodecImageBuffer](_codec_image_buffer_v10.md) | 定义编解码图像缓冲区信息。 | 
| struct&nbsp;&nbsp;[CodecImageCapability](_codec_image_capability_v10.md) | 定义图像编解码器功能。 | 
| struct&nbsp;&nbsp;[CodecJpegQuantTable](_codec_jpeg_quant_table_v10.md) | 定义jpeg图像量化表信息。 | 
| struct&nbsp;&nbsp;[CodecJpegHuffTable](_codec_jpeg_huff_table_v10.md) | 定义jpeg图像Huffman表信息。 | 
| struct&nbsp;&nbsp;[CodecJpegCompInfo](_codec_jpeg_comp_info_v10.md) | 定义jpeg图像的颜色分量信息。 | 
| struct&nbsp;&nbsp;[CodecJpegDecInfo](_codec_jpeg_dec_info_v10.md) | 定义jpeg图像解码信息。 | 
| struct&nbsp;&nbsp;[Alignment](_alignment_v10.md) | 对齐结构定义。 | 
| struct&nbsp;&nbsp;[Rect](_rect_v10.md) | 矩形的定义。 | 
| struct&nbsp;&nbsp;[RangeValue](_range_value_v10.md) | 取值范围的定义。 | 
| struct&nbsp;&nbsp;[CodecVideoPortCap](_codec_video_port_cap_v10.md) | 定义视频编解码能力。 | 
| struct&nbsp;&nbsp;[CodecAudioPortCap](_codec_audio_port_cap_v10.md) | 定义音频编解码能力。 | 
| struct&nbsp;&nbsp;[PortCap](_port_cap_v10.md) | 定义音视频编解码能力。 | 
| struct&nbsp;&nbsp;[OmxVerType](_omx_ver_type_v10.md) | 定义组件的版本信息。 | 
| union&nbsp;&nbsp;[OMX_VERSIONTYPE](union_o_m_x___v_e_r_s_i_o_n_t_y_p_e_v10.md) | 定义组件的版本信息。 | 
| struct&nbsp;&nbsp;[CodecCompCapability](_codec_comp_capability_v10.md) | 定义Codec编解码能力。 | 
| struct&nbsp;&nbsp;[OmxCodecBuffer](_omx_codec_buffer_v10.md) | Codec buffer信息的定义。 | 
| struct&nbsp;&nbsp;[OMX_TUNNELSETUPTYPE](_o_m_x___t_u_n_n_e_l_s_e_t_u_p_t_y_p_e_v10.md) | 用于将数据从输出端口传递到输入端口。 | 
| struct&nbsp;&nbsp;[CompVerInfo](_comp_ver_info_v10.md) | 定义了组件信息，包含组件名，UUID， 组件版本以及spec版本。 | 
| struct&nbsp;&nbsp;[EventInfo](_event_info_v10.md) | 定义事件上报信息。 | 
| interface&nbsp;&nbsp;[ICodecCallback](interface_i_codec_callback_v10.md) | Codec回调接口定义。 | 
| interface&nbsp;&nbsp;[ICodecComponent](interface_i_codec_component_v10.md) | Codec组件接口定义。 | 
| interface&nbsp;&nbsp;[ICodecComponentManager](interface_i_codec_component_manager_v10.md) | Codec组件管理类接口定义。 | 
| interface&nbsp;&nbsp;[ICodecImage](interface_i_codec_image_v10.md) | 图像编解码器模块接口。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [CodecImageRole](#codecimagerole) { CODEC_IMAGE_JPEG = 0 , CODEC_IMAGE_HEIF , CODEC_IMAGE_INVALID } | 编解码的图像格式枚举。 | 
| [CodecImageType](#codecimagetype) { CODEC_IMAGE_TYPE_DECODER = 0 , CODEC_IMAGE_TYPE_ENCODER , CODEC_IMAGE_TYPE_INVALID } | 定义图像编解码器类型。 | 
| [CodecType](#codectype) {<br/>VIDEO_DECODER, VIDEO_ENCODER, AUDIO_DECODER, AUDIO_ENCODER,&nbsp;&nbsp;&nbsp;INVALID_TYPE<br/>} | 枚举编解码的类型。 | 
| [AvCodecRole](#avcodecrole) {<br/>MEDIA_ROLETYPE_IMAGE_JPEG = 0, MEDIA_ROLETYPE_VIDEO_AVC, MEDIA_ROLETYPE_VIDEO_HEVC, MEDIA_ROLETYPE_AUDIO_FIRST = 0x10000,&nbsp;&nbsp;&nbsp;MEDIA_ROLETYPE_AUDIO_AAC = 0x10000, MEDIA_ROLETYPE_AUDIO_G711A, MEDIA_ROLETYPE_AUDIO_G711U, MEDIA_ROLETYPE_AUDIO_G726,&nbsp;&nbsp;&nbsp;MEDIA_ROLETYPE_AUDIO_PCM, MEDIA_ROLETYPE_AUDIO_MP3, MEDIA_ROLETYPE_INVALID<br/>} | 枚举音视频编解码组件类型。 | 
| [Profile](#profile) {<br/>INVALID_PROFILE = 0, AAC_LC_PROFILE = 0x1000, AAC_MAIN_PROFILE, AAC_HE_V1_PROFILE,&nbsp;&nbsp;&nbsp;AAC_HE_V2_PROFILE, AAC_LD_PROFILE, AAC_ELD_PROFILE, AVC_BASELINE_PROFILE = 0x2000,&nbsp;&nbsp;&nbsp;AVC_MAIN_PROFILE, AVC_HIGH_PROFILE, HEVC_MAIN_PROFILE = 0x3000, HEVC_MAIN_10_PROFILE<br/>} | 枚举Codec规格。 | 
| [CodecCapsMask](#codeccapsmask) { CODEC_CAP_ADAPTIVE_PLAYBACK = 0x1, CODEC_CAP_SECURE_PLAYBACK = 0x2, CODEC_CAP_TUNNEL_PLAYBACK = 0x4, CODEC_CAP_MULTI_PLANE = 0x10000 } | 枚举播放能力。 | 
| [AudioSampleRate](#audiosamplerate) {<br/>AUD_SAMPLE_RATE_8000 = 8000, AUD_SAMPLE_RATE_12000 = 12000, AUD_SAMPLE_RATE_11025 = 11025, AUD_SAMPLE_RATE_16000 = 16000,&nbsp;&nbsp;&nbsp;AUD_SAMPLE_RATE_22050 = 22050, AUD_SAMPLE_RATE_24000 = 24000, AUD_SAMPLE_RATE_32000 = 32000, AUD_SAMPLE_RATE_44100 = 44100,&nbsp;&nbsp;&nbsp;AUD_SAMPLE_RATE_48000 = 48000, AUD_SAMPLE_RATE_64000 = 64000, AUD_SAMPLE_RATE_96000 = 96000, AUD_SAMPLE_RATE_INVALID<br/>} | 枚举音频采样率。 | 
| [AudioSampleFormat](#audiosampleformat) {<br/>AUDIO_SAMPLE_FMT_U8 , AUDIO_SAMPLE_FMT_S16 , AUDIO_SAMPLE_FMT_S32 , AUDIO_SAMPLE_FMT_FLOAT , AUDIO_SAMPLE_FMT_DOUBLE , AUDIO_SAMPLE_FMT_U8P , AUDIO_SAMPLE_FMT_S16P , AUDIO_SAMPLE_FMT_S32P , AUDIO_SAMPLE_FMT_FLOATP , AUDIO_SAMPLE_FMT_DOUBLEP , AUDIO_SAMPLE_FMT_INVALID<br/>} | 枚举音频采样格式。 | 
| [CodecProcessMode](#codecprocessmode) {<br/>PROCESS_BLOCKING_INPUT_BUFFER = 0X1, PROCESS_BLOCKING_OUTPUT_BUFFER = 0X2, PROCESS_BLOCKING_CONTROL_FLOW = 0X4, PROCESS_NONBLOCKING_INPUT_BUFFER = 0X100,&nbsp;&nbsp;&nbsp;PROCESS_NONBLOCKING_OUTPUT_BUFFER = 0X200, PROCESS_NONBLOCKING_CONTROL_FLOW = 0X400<br/>} | 枚举编解码处理模式。 | 
| [ShareMemTypes](#sharememtypes) { READ_WRITE_TYPE = 0x1, READ_ONLY_TYPE = 0x2 } | 枚举共享内存类型。 | 
| [BitRateMode](#bitratemode) {<br/>BIT_RATE_MODE_INVALID , BIT_RATE_MODE_VBR , BIT_RATE_MODE_CBR , BIT_RATE_MODE_CQ , BIT_RATE_MODE_VCBR , BIT_RATE_MODE_ABR<br/>} | 枚举比特率类型。 | 
| [CodecEventType](#codeceventtype) {<br/>OMX_EventCmdComplete , OMX_EventError , OMX_EventMark , OMX_EventPortSettingsChanged ,<br/>OMX_EventBufferFlag , OMX_EventResourcesAcquired , OMX_EventComponentResumed , OMX_EventDynamicResourcesAvailable ,<br/>OMX_EventPortFormatDetected , OMX_EventKhronosExtensions = 0x6F000000 , OMX_EventVendorStartUnused = 0x7F000000 , OMX_EventMax = 0x7FFFFFFF<br/>} | 枚举组件状态 | 
| [CodecCommandType](#codeccommandtype) {<br/>OMX_CommandStateSet , OMX_CommandFlush , OMX_CommandPortDisable , OMX_CommandPortEnable , OMX_CommandMarkBuffer , OMX_CommandKhronosExtensions = 0x6F000000 , OMX_CommandVendorStartUnused = 0x7F000000 , OMX_CommandMax = 0x7FFFFFFF<br/>} | 枚举ICodecComponent中SendCommand接口的cmd参数 | 
| [CodecStateType](#codecstatetype) {<br/>OMX_StateInvalid , OMX_StateLoaded , OMX_StateIdle , OMX_StateExecuting , OMX_StatePause , OMX_StateWaitForResources , OMX_StateKhronosExtensions = 0x6F000000 , OMX_StateVendorStartUnused = 0x7F000000 , OMX_StateMax = 0x7FFFFFFF<br/>} | 更改组件状态 | 
| [CodecBufferSupplierType](#codecbuffersuppliertype) {<br/>OMX_BufferSupplyUnspecified = 0 , OMX_BufferSupplyInput , OMX_BufferSupplyOutput , OMX_BufferSupplyKhronosExtensions = 0x6F000000 , OMX_BufferSupplyVendorStartUnused = 0x7F000000 , OMX_BufferSupplyMax = 0x7FFFFFFF<br/>} | 表示端口供应商在两个端口之间建立隧道时的首选项 | 


## 枚举类型说明


### AudioSampleFormat

```
enum AudioSampleFormat
```

**描述**


枚举音频采样格式。

对于平面格式的采样格式，每个声道的数据是独立存储在data中; 对于打包格式的采样格式，只使用第一个data，每个声道的数据是交错存储的。

**起始版本：** 3.2

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

**起始版本：** 3.2

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

**起始版本：** 3.2

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

**起始版本：** 3.2

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


表示端口供应商在两个端口之间建立隧道时的首选项

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| CODEC_BUFFER_SUPPLY_UNSPECIFIED | 提供缓冲区的端口未指定，或不指定 | 
| CODEC_BUFFER_SUPPLY_INPUT | 为输入端口提供缓冲区 | 
| CODEC_BUFFER_SUPPLY_OUTPUT | 为输出端口提供缓冲区 | 
| CODEC_BUFFER_SUPPLY_KHRONOS_EXTENSIONS | 用于引入Khronos标准扩展的保留区域 | 
| CODEC_BUFFER_SUPPLY_VENDOR_START_UNUSED | 用于引入供应商扩展的预留区域 | 
| CODEC_BUFFER_SUPPLY_MAX | 枚举的最大值 | 


### CodecCapsMask

```
enum CodecCapsMask
```

**描述**


枚举播放能力。

**起始版本：** 3.2

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


枚举ICodecComponent中SendCommand接口的cmd参数

**起始版本：** 3.2

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


枚举组件状态

**起始版本：** 3.2

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


### CodecProcessMode

```
enum CodecProcessMode
```

**描述**


枚举编解码处理模式。

**起始版本：** 3.2

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


更改组件状态

**起始版本：** 3.2

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

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| VIDEO_DECODER | 视频解码类型。 | 
| VIDEO_ENCODER | 视频编码类型。 | 
| AUDIO_DECODER | 音频解码类型。 | 
| AUDIO_ENCODER | 音频编码类型。 | 
| INVALID_TYPE | 无效类型。 | 


### Profile

```
enum Profile
```

**描述**


枚举Codec规格。

**起始版本：** 3.2

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


### ShareMemTypes

```
enum ShareMemTypes
```

**描述**


枚举共享内存类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| READ_WRITE_TYPE | 可读可写的共享内存类型。 | 
| READ_ONLY_TYPE | 只读的共享内存类型。 | 
