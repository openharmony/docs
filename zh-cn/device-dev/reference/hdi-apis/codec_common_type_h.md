# codec_common_type.h


## **概述**

Codec模块接口定义中使用的自定义数据类型，包括编解码类型、音视频参数、buffer定义等。

**Since**:

3.1

**Version**:

2.0

**相关模块:**

[Codec](codec.md)


## **汇总**


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [Alignment](_alignment.md) | 对齐结构定义，包含宽高的对齐值。 | 
| [Rect](_rect.md) | 矩形的定义。 | 
| [RangeValue](_range_value.md) | 取值范围的定义。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [CodecType](codec.md#codectype)&nbsp;{&nbsp;VIDEO_DECODER,&nbsp;VIDEO_ENCODER,&nbsp;AUDIO_DECODER,&nbsp;AUDIO_ENCODER,&nbsp;&nbsp;&nbsp;INVALID_TYPE&nbsp;&nbsp;} | 枚举编解码的类型。 | 
| [Profile](codec.md#profile)&nbsp;{&nbsp;INVALID_PROFILE&nbsp;=&nbsp;0,&nbsp;AAC_LC_PROFILE&nbsp;=&nbsp;0x1000,&nbsp;AAC_MAIN_PROFILE,&nbsp;AAC_HE_V1_PROFILE,&nbsp;&nbsp;&nbsp;AAC_HE_V2_PROFILE,&nbsp;AAC_LD_PROFILE,&nbsp;AAC_ELD_PROFILE,&nbsp;AVC_BASELINE_PROFILE&nbsp;=&nbsp;0x2000,&nbsp;&nbsp;&nbsp;AVC_MAIN_PROFILE,&nbsp;AVC_HIGH_PROFILE,&nbsp;HEVC_MAIN_PROFILE&nbsp;=&nbsp;0x3000,&nbsp;HEVC_MAIN_10_PROFILE&nbsp;} | 枚举Codec规格。 | 
| [AudioSampleRate](codec.md#audiosamplerate)&nbsp;{&nbsp;AUD_SAMPLE_RATE_8000&nbsp;=&nbsp;8000,&nbsp;AUD_SAMPLE_RATE_12000&nbsp;=&nbsp;12000,&nbsp;AUD_SAMPLE_RATE_11025&nbsp;=&nbsp;11025,&nbsp;AUD_SAMPLE_RATE_16000&nbsp;=&nbsp;16000,&nbsp;&nbsp;&nbsp;AUD_SAMPLE_RATE_22050&nbsp;=&nbsp;22050,&nbsp;AUD_SAMPLE_RATE_24000&nbsp;=&nbsp;24000,&nbsp;AUD_SAMPLE_RATE_32000&nbsp;=&nbsp;32000,&nbsp;AUD_SAMPLE_RATE_44100&nbsp;=&nbsp;44100,&nbsp;&nbsp;&nbsp;AUD_SAMPLE_RATE_48000&nbsp;=&nbsp;48000,&nbsp;AUD_SAMPLE_RATE_64000&nbsp;=&nbsp;64000,&nbsp;AUD_SAMPLE_RATE_96000&nbsp;=&nbsp;96000,&nbsp;AUD_SAMPLE_RATE_INVALID&nbsp;} | 枚举音频采样率。 | 
| [CodecCapsMask](codec.md#codeccapsmask)&nbsp;{&nbsp;CODEC_CAP_ADAPTIVE_PLAYBACK&nbsp;=&nbsp;0x1,&nbsp;CODEC_CAP_SECURE_PLAYBACK&nbsp;=&nbsp;0x2,&nbsp;CODEC_CAP_TUNNEL_PLAYBACK&nbsp;=&nbsp;0x4,&nbsp;CODEC_CAP_MULTI_PLANE&nbsp;=&nbsp;0x10000&nbsp;} | 枚举播放能力。 | 
| [CodecProcessMode](codec.md#codecprocessmode)&nbsp;{&nbsp;PROCESS_BLOCKING_INPUT_BUFFER&nbsp;=&nbsp;0X1,&nbsp;PROCESS_BLOCKING_OUTPUT_BUFFER&nbsp;=&nbsp;0X2,&nbsp;PROCESS_BLOCKING_CONTROL_FLOW&nbsp;=&nbsp;0X4,&nbsp;PROCESS_NONBLOCKING_INPUT_BUFFER&nbsp;=&nbsp;0X100,&nbsp;&nbsp;&nbsp;PROCESS_NONBLOCKING_OUTPUT_BUFFER&nbsp;=&nbsp;0X200,&nbsp;PROCESS_NONBLOCKING_CONTROL_FLOW&nbsp;=&nbsp;0X400&nbsp;} | 枚举编解码处理模式。 | 
