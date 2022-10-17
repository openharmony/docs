# Codec


## **概述**

Codec模块接口定义。

Codec模块涉及自定义类型、音视频编解码组件初始化、参数设置、数据的轮转和控制等。

**Since**:

3.1

**Version**:

2.0


## **汇总**


### 文件

  | 名称 | 描述 | 
| -------- | -------- |
| [codec_callback_if.h](codec_callback_if_h.md) | 主要包括回调函数接口定义。 | 
| [codec_common_type.h](codec_common_type_h.md) | Codec模块接口定义中使用的自定义数据类型。 | 
| [codec_component_if.h](codec_component_if_h.md) | 主要包括Codec组件接口定义。 | 
| [codec_component_manager.h](codec__component__manager_h.md) | 主要包括Codec组件管理类接口。 | 
| [codec_component_type.h](codec__component__type_h.md) | Codec模块接口定义中使用的自定义数据类型。 | 


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [CodecCallbackType](_codec_callback_type.md) | Codec回调接口定义。 | 
| [Alignment](_alignment.md) | 对齐结构定义，包含宽高的对齐值。 | 
| [Rect](_rect.md) | 矩形的定义。 | 
| [RangeValue](_range_value.md) | 取值范围的定义。 | 
| [CodecComponentType](_codec_component_type.md) | Codec组件接口定义。 | 
| [CodecComponentManager](_codec_component_manager.md) | Codec组件管理类接口定义。 | 
| [VideoPortCap](_video_port_cap.md) | 定义视频编解码能力。 | 
| [AudioPortCap](audio_portcap.md) | 定义音频编解码能力。 | 
| [PortCap](union_port_cap.md) | 定义音视频编解码能力。 | 
| [CodecCompCapability](_codec_comp_capability.md) | 定义Codec编解码能力。 | 
| [OmxCodecBuffer](_omx_codec_buffer.md) | Codec&nbsp;buffer信息的定义。 | 
| [CompVerInfo](_comp_ver_info.md) | 定义组件版本信息。 | 
| [EventInfo](_event_info.md) | 定义事件上报信息。 | 
| [SupportBufferType](_support_buffer_type.md) | SupportBuffer类型定义。 | 
| [UseBufferType](_use_buffer_type.md) | UseBuffer类型定义。 | 
| [GetBufferHandleUsageParams](_get_buffer_handle_usage_params.md) | BufferHandleUsage类型定义。 | 


### 宏定义

  | 名称 | 描述 | 
| -------- | -------- |
| SAMPLE_FMT_NUM&nbsp;&nbsp;&nbsp;&nbsp;32 | 采样格式最大值。 | 
| UUID_LENGTH&nbsp;&nbsp;&nbsp;&nbsp;128 | 定义UUID长度。 | 
| PIX_FORMAT_NUM&nbsp;&nbsp;&nbsp;&nbsp;16 | 支持的像素格式数组大小。 | 
| SAMPLE_FORMAT_NUM&nbsp;&nbsp;&nbsp;&nbsp;12 | 支持的音频采样格式数组大小。 | 
| SAMPLE_RATE_NUM&nbsp;&nbsp;&nbsp;&nbsp;16 | 支持的音频采样率数组大小。 | 
| CHANNEL_NUM&nbsp;&nbsp;&nbsp;&nbsp;16 | 支持的音频通道数组大小。 | 
| NAME_LENGTH&nbsp;&nbsp;&nbsp;&nbsp;32 | 组件名称大小。 | 
| PROFILE_NUM&nbsp;&nbsp;&nbsp;&nbsp;256 | 支持的profile数组大小。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [CodecType](#codectype)&nbsp;{&nbsp;VIDEO_DECODER,&nbsp;VIDEO_ENCODER,&nbsp;AUDIO_DECODER,&nbsp;AUDIO_ENCODER,&nbsp;&nbsp;&nbsp;INVALID_TYPE&nbsp;} | 枚举编解码的类型。 | 
| [Profile](#profile)&nbsp;{&nbsp;INVALID_PROFILE&nbsp;=&nbsp;0,&nbsp;AAC_LC_PROFILE&nbsp;=&nbsp;0x1000,&nbsp;AAC_MAIN_PROFILE,&nbsp;AAC_HE_V1_PROFILE,&nbsp;&nbsp;&nbsp;AAC_HE_V2_PROFILE,&nbsp;AAC_LD_PROFILE,&nbsp;AAC_ELD_PROFILE,&nbsp;AVC_BASELINE_PROFILE&nbsp;=&nbsp;0x2000,&nbsp;&nbsp;&nbsp;AVC_MAIN_PROFILE,&nbsp;AVC_HIGH_PROFILE,&nbsp;HEVC_MAIN_PROFILE&nbsp;=&nbsp;0x3000,&nbsp;HEVC_MAIN_10_PROFILE&nbsp;} | 枚举Codec规格。 | 
| [AudioSampleRate](#audiosamplerate)&nbsp;{&nbsp;AUD_SAMPLE_RATE_8000&nbsp;=&nbsp;8000,&nbsp;AUD_SAMPLE_RATE_12000&nbsp;=&nbsp;12000,&nbsp;AUD_SAMPLE_RATE_11025&nbsp;=&nbsp;11025,&nbsp;AUD_SAMPLE_RATE_16000&nbsp;=&nbsp;16000,&nbsp;&nbsp;&nbsp;AUD_SAMPLE_RATE_22050&nbsp;=&nbsp;22050,&nbsp;AUD_SAMPLE_RATE_24000&nbsp;=&nbsp;24000,&nbsp;AUD_SAMPLE_RATE_32000&nbsp;=&nbsp;32000,&nbsp;AUD_SAMPLE_RATE_44100&nbsp;=&nbsp;44100,&nbsp;&nbsp;&nbsp;AUD_SAMPLE_RATE_48000&nbsp;=&nbsp;48000,&nbsp;AUD_SAMPLE_RATE_64000&nbsp;=&nbsp;64000,&nbsp;AUD_SAMPLE_RATE_96000&nbsp;=&nbsp;96000,&nbsp;AUD_SAMPLE_RATE_INVALID&nbsp;} | 枚举音频采样率。 | 
| [CodecCapsMask](#codeccapsmask)&nbsp;{&nbsp;CODEC_CAP_ADAPTIVE_PLAYBACK&nbsp;=&nbsp;0x1,&nbsp;CODEC_CAP_SECURE_PLAYBACK&nbsp;=&nbsp;0x2,&nbsp;CODEC_CAP_TUNNEL_PLAYBACK&nbsp;=&nbsp;0x4,&nbsp;CODEC_CAP_MULTI_PLANE&nbsp;=&nbsp;0x10000&nbsp;} | 枚举播放能力。 | 
| [CodecProcessMode](#codecprocessmode)&nbsp;{&nbsp;PROCESS_BLOCKING_INPUT_BUFFER&nbsp;=&nbsp;0X1,&nbsp;PROCESS_BLOCKING_OUTPUT_BUFFER&nbsp;=&nbsp;0X2,&nbsp;PROCESS_BLOCKING_CONTROL_FLOW&nbsp;=&nbsp;0X4,&nbsp;PROCESS_NONBLOCKING_INPUT_BUFFER&nbsp;=&nbsp;0X100,&nbsp;&nbsp;&nbsp;PROCESS_NONBLOCKING_OUTPUT_BUFFER&nbsp;=&nbsp;0X200,&nbsp;PROCESS_NONBLOCKING_CONTROL_FLOW&nbsp;=&nbsp;0X400&nbsp;} | 枚举编解码处理模式。 | 
| [AvCodecRole](#avcodecrole)&nbsp;{&nbsp;&nbsp;&nbsp;MEDIA_ROLETYPE_IMAGE_JPEG&nbsp;=&nbsp;0,&nbsp;MEDIA_ROLETYPE_VIDEO_AVC,&nbsp;MEDIA_ROLETYPE_VIDEO_HEVC,&nbsp;MEDIA_ROLETYPE_AUDIO_FIRST&nbsp;=&nbsp;0x10000,&nbsp;&nbsp;&nbsp;MEDIA_ROLETYPE_AUDIO_AAC&nbsp;=&nbsp;0x10000,&nbsp;MEDIA_ROLETYPE_AUDIO_G711A,&nbsp;MEDIA_ROLETYPE_AUDIO_G711U,&nbsp;MEDIA_ROLETYPE_AUDIO_G726,&nbsp;&nbsp;&nbsp;MEDIA_ROLETYPE_AUDIO_PCM,&nbsp;MEDIA_ROLETYPE_AUDIO_MP3,&nbsp;MEDIA_ROLETYPE_INVALID&nbsp;} | 枚举音视频编解码组件类型。 | 
| [AudioSampleFormat](#audiosampleformat)&nbsp;{&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_S8&nbsp;=&nbsp;0,&nbsp;AUDIO_SAMPLE_FORMAT_S8P&nbsp;=&nbsp;1,&nbsp;AUDIO_SAMPLE_FORMAT_U8&nbsp;=&nbsp;2,&nbsp;AUDIO_SAMPLE_FORMAT_U8P&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_S16&nbsp;=&nbsp;4,&nbsp;AUDIO_SAMPLE_FORMAT_S16P&nbsp;=&nbsp;5,&nbsp;AUDIO_SAMPLE_FORMAT_U16&nbsp;=&nbsp;6,&nbsp;AUDIO_SAMPLE_FORMAT_U16P&nbsp;=&nbsp;7,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_S24&nbsp;=&nbsp;8,&nbsp;AUDIO_SAMPLE_FORMAT_S24P&nbsp;=&nbsp;9,&nbsp;AUDIO_SAMPLE_FORMAT_U24&nbsp;=&nbsp;10,&nbsp;AUDIO_SAMPLE_FORMAT_U24P&nbsp;=&nbsp;11,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_S32&nbsp;=&nbsp;12,&nbsp;AUDIO_SAMPLE_FORMAT_S32P&nbsp;=&nbsp;13,&nbsp;AUDIO_SAMPLE_FORMAT_U32&nbsp;=&nbsp;14,&nbsp;AUDIO_SAMPLE_FORMAT_U32P&nbsp;=&nbsp;15,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_S64&nbsp;=&nbsp;16,&nbsp;AUDIO_SAMPLE_FORMAT_S64P&nbsp;=&nbsp;17,&nbsp;AUDIO_SAMPLE_FORMAT_U64&nbsp;=&nbsp;18,&nbsp;AUDIO_SAMPLE_FORMAT_U64P&nbsp;=&nbsp;19,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_F32&nbsp;=&nbsp;20,&nbsp;AUDIO_SAMPLE_FORMAT_F32P&nbsp;=&nbsp;21,&nbsp;AUDIO_SAMPLE_FORMAT_F64&nbsp;=&nbsp;22,&nbsp;AUDIO_SAMPLE_FORMAT_F64P&nbsp;=&nbsp;23,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FMT_U8,&nbsp;AUDIO_SAMPLE_FMT_S16,&nbsp;AUDIO_SAMPLE_FMT_S32,&nbsp;AUDIO_SAMPLE_FMT_FLOAT,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FMT_DOUBLE,&nbsp;AUDIO_SAMPLE_FMT_U8P,&nbsp;AUDIO_SAMPLE_FMT_S16P,&nbsp;AUDIO_SAMPLE_FMT_S32P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FMT_FLOATP,&nbsp;AUDIO_SAMPLE_FMT_DOUBLEP,&nbsp;AUDIO_SAMPLE_FMT_INVALID&nbsp;} | 枚举音频采样格式。 | 
| [CodecBufferType](#codecbuffertype)&nbsp;{&nbsp;&nbsp;&nbsp;CODEC_BUFFER_TYPE_INVALID&nbsp;=&nbsp;0,&nbsp;CODEC_BUFFER_TYPE_VIRTUAL_ADDR&nbsp;=&nbsp;0x1,&nbsp;CODEC_BUFFER_TYPE_AVSHARE_MEM_FD&nbsp;=&nbsp;0x2,&nbsp;CODEC_BUFFER_TYPE_HANDLE&nbsp;=&nbsp;0x4,&nbsp;&nbsp;&nbsp;CODEC_BUFFER_TYPE_DYNAMIC_HANDLE&nbsp;=&nbsp;0x8&nbsp;} | 定义buffer类型。 | 
| [ShareMemTypes](#sharememtypes)&nbsp;{&nbsp;READ_WRITE_TYPE&nbsp;=&nbsp;0x1,&nbsp;READ_ONLY_TYPE&nbsp;=&nbsp;0x2&nbsp;} | 枚举共享内存类型。 | 
| [OmxIndexCodecExType](#omxindexcodecextype)&nbsp;{&nbsp;OMX_IndexExtBufferTypeStartUnused&nbsp;=&nbsp;OMX_IndexKhronosExtensions&nbsp;+&nbsp;0x00a00000,&nbsp;OMX_IndexParamSupportBufferType,&nbsp;OMX_IndexParamUseBufferType,&nbsp;OMX_IndexParamGetBufferHandleUsage&nbsp;} | 枚举Codec扩展index。 | 
| [OmxVideoExType](#omxvideoextype)&nbsp;{&nbsp;OMX_VIDEO_CodingHEVC&nbsp;=&nbsp;11&nbsp;} | 枚举Codec扩展编码类型。 | 


### 函数

  | 名称 | 描述 | 
| -------- | -------- |
| [CodecCallbackTypeGet](#codeccallbacktypeget)&nbsp;(struct&nbsp;HdfRemoteService&nbsp;\*remote) | 实例化CodecCallbackType对象。 | 
| [CodecCallbackTypeRelease](#codeccallbacktyperelease)&nbsp;(struct&nbsp;[CodecCallbackType](_codec_callback_type.md)&nbsp;\*instance) | 释放CodecCallbackType对象。 | 
| [CodecComponentTypeGet](#codeccomponenttypeget)&nbsp;(struct&nbsp;HdfRemoteService&nbsp;\*remote) | 实例化CodecComponentType对象。 | 
| [CodecComponentTypeRelease](#codeccomponenttyperelease)&nbsp;(struct&nbsp;[CodecComponentType](_codec_component_type.md)&nbsp;\*instance) | 释放CodecComponentType对象。 | 
| [GetCodecComponentManager](#getcodeccomponentmanager)&nbsp;(void) | 实例化CodecComponentManager对象。 | 
| [CodecComponentManagerRelease](#codeccomponentmanagerrelease)&nbsp;(void) | 释放CodecComponentManager对象。 | 


## **枚举类型说明**


### AudioSampleFormat

  
```
enum AudioSampleFormat
```

**描述：**

枚举音频采样格式。

对于planar的采样格式，每个声道的数据是独立存储在data中；对于packed的采样格式，只使用第一个data，每个声道的数据是交错存储的。

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
| AUDIO_SAMPLE_FMT_U8 | 无符号8位整型，打包格式。 | 
| AUDIO_SAMPLE_FMT_S16 | 带符号16位整型，打包格式。 | 
| AUDIO_SAMPLE_FMT_S32 | 带符号32位整型，打包格式。 | 
| AUDIO_SAMPLE_FMT_FLOAT | 浮点型，打包格式。 | 
| AUDIO_SAMPLE_FMT_DOUBLE | 双精度浮点型，打包格式。 | 
| AUDIO_SAMPLE_FMT_U8P | 无符号8位整型，平面格式。 | 
| AUDIO_SAMPLE_FMT_S16P | 带符号16位整型，平面格式。 | 
| AUDIO_SAMPLE_FMT_S32P | 带符号32位整型，平面格式。 | 
| AUDIO_SAMPLE_FMT_FLOATP | 浮点型，平面格式。 | 
| AUDIO_SAMPLE_FMT_DOUBLEP | 双精度浮点型，平面格式。 | 
| AUDIO_SAMPLE_FMT_INVALID | 无效采样格式。 | 


### AudioSampleRate

  
```
enum AudioSampleRate
```

**描述：**

枚举音频采样率。

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

**描述：**

枚举音视频编解码组件类型。

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


### CodecBufferType

  
```
enum CodecBufferType
```

**描述：**

定义buffer类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| CODEC_BUFFER_TYPE_INVALID | 无效buffer类型。 | 
| CODEC_BUFFER_TYPE_VIRTUAL_ADDR | 虚拟地址类型。 | 
| CODEC_BUFFER_TYPE_AVSHARE_MEM_FD | 共享内存类型。 | 
| CODEC_BUFFER_TYPE_HANDLE | handle类型。 | 
| CODEC_BUFFER_TYPE_DYNAMIC_HANDLE | 动态handle类型。 | 


### CodecCapsMask

  
```
enum CodecCapsMask
```

**描述：**

枚举播放能力。

  | 枚举值 | 描述 | 
| -------- | -------- |
| CODEC_CAP_ADAPTIVE_PLAYBACK | 自适应播放能力。 | 
| CODEC_CAP_SECURE_PLAYBACK | 安全播放能力。 | 
| CODEC_CAP_TUNNEL_PLAYBACK | 通道播放能力。 | 
| CODEC_CAP_MULTI_PLANE | 视频图像平面/音频通道平面能力。 | 


### CodecProcessMode

  
```
enum CodecProcessMode
```

**描述：**

枚举编解码处理模式。

  | 枚举值 | 描述 | 
| -------- | -------- |
| PROCESS_BLOCKING_INPUT_BUFFER | 同步模式输入buffer。 | 
| PROCESS_BLOCKING_OUTPUT_BUFFER | 同步模式输出buffer。 | 
| PROCESS_BLOCKING_CONTROL_FLOW | 同步模式控制流。 | 
| PROCESS_NONBLOCKING_INPUT_BUFFER | 异步模式输入buffer。 | 
| PROCESS_NONBLOCKING_OUTPUT_BUFFER | 异步模式输出buffer。 | 
| PROCESS_NONBLOCKING_CONTROL_FLOW | 异步模式控制流。 | 


### CodecType

  
```
enum CodecType
```

**描述：**

枚举编解码的类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| VIDEO_DECODER | 视频解码类型。 | 
| VIDEO_ENCODER | 视频编码类型。 | 
| AUDIO_DECODER | 音频解码类型。 | 
| AUDIO_ENCODER | 音频编码类型。 | 
| INVALID_TYPE | 无效类型。 | 


### OmxIndexCodecExType

  
```
enum OmxIndexCodecExType
```

**描述：**

枚举Codec扩展index。

  | 枚举值 | 描述 | 
| -------- | -------- |
| OMX_IndexExtBufferTypeStartUnused | BufferType&nbsp;扩展index。 | 
| OMX_IndexParamSupportBufferType | SupportBuffer类型。 | 
| OMX_IndexParamUseBufferType | UseBuffer类型。 | 
| OMX_IndexParamGetBufferHandleUsage | GetBufferHandleUsage类型。 | 


### OmxVideoExType

  
```
enum OmxVideoExType
```

**描述：**

枚举Codec扩展编码类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| OMX_VIDEO_CodingHEVC | HEVC编码类型。 | 


### Profile

  
```
enum Profile
```

**描述：**

枚举Codec规格。

  | 枚举值 | 描述 | 
| -------- | -------- |
| INVALID_PROFILE | 无效的规格。 | 
| AAC_LC_PROFILE | AAC低复杂度规格。 | 
| AAC_MAIN_PROFILE | AAC主规格。 | 
| AAC_HE_V1_PROFILE | AAC高效率和频带重现规格，又称为HEAAC，AAC+，或者AACPlusV1。 | 
| AAC_HE_V2_PROFILE | AAC高效率和频带重现以及变量立体声规格，又称为AAC++或者AACPlusV2。 | 
| AAC_LD_PROFILE | AAC低延迟规格。 | 
| AAC_ELD_PROFILE | AAC增强型低延迟规格。 | 
| AVC_BASELINE_PROFILE | H.264低规格。 | 
| AVC_MAIN_PROFILE | H.264主规格。 | 
| AVC_HIGH_PROFILE | H.264高规格。 | 
| HEVC_MAIN_PROFILE | H.265主规格。 | 
| HEVC_MAIN_10_PROFILE | H.265&nbsp;10比特主规格。 | 


### ShareMemTypes

  
```
enum ShareMemTypes
```

**描述：**

枚举共享内存类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| READ_WRITE_TYPE | 可读可写的共享内存类型。 | 
| READ_ONLY_TYPE | 可读的共享内存类型。 | 


## **函数说明**


### CodecCallbackTypeGet()

  
```
struct CodecCallbackType* CodecCallbackTypeGet (struct HdfRemoteService * remote)
```

**描述：**

实例化CodecCallbackType对象。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| remote | 输入参数，指向HdfRemoteService的指针。 | 

**返回:**

实例化CodecCallbackType对象。


### CodecCallbackTypeRelease()

  
```
void CodecCallbackTypeRelease (struct CodecCallbackType * instance)
```

**描述：**

释放CodecCallbackType对象。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| instance | 输入参数，指向CodecCallbackType实例的指针。 | 


### CodecComponentManagerRelease()

  
```
void CodecComponentManagerRelease (void )
```

**描述：**

释放CodecComponentManager对象。


### CodecComponentTypeGet()

  
```
struct CodecComponentType* CodecComponentTypeGet (struct HdfRemoteService * remote)
```

**描述：**

实例化CodecComponentType对象。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| remote | 输入参数，指向RemoteService的指针。 | 

**返回:**

实例化的CodecComponentType对象。


### CodecComponentTypeRelease()

  
```
void CodecComponentTypeRelease (struct CodecComponentType * instance)
```

**描述：**

释放CodecComponentType对象。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| instance | 输入参数，指向CodecComponentType实例的指针。 | 


### GetCodecComponentManager()

  
```
struct CodecComponentManager* GetCodecComponentManager (void )
```

**描述：**

实例化CodecComponentManager对象。

**返回:**

实例化的CodecComponentManager对象。
