# codec_common_type.h


## **概述**

**所属模块:**

[Codec](_codec.md)


## **汇总**


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [Alignment](_alignment.md) | 对齐结构定义，包含宽高的对齐值&nbsp;[更多...](_alignment.md) | 
| [Rect](_rect.md) | 矩形的定义&nbsp;[更多...](_rect.md) | 
| [RangeValue](_range_value.md) | 取值范围的定义&nbsp;[更多...](_range_value.md) | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [CodecType](_codec.md#codectype)&nbsp;{&nbsp;&nbsp;&nbsp;[VIDEO_DECODER](_codec.md#gga03b4b6ae5fb82af68d46aaea3d3e4d79a19c3c7765c55583a64e21938e2439261),&nbsp;[VIDEO_ENCODER](_codec.md#gga03b4b6ae5fb82af68d46aaea3d3e4d79ad8044bc5b7d871723be90b5b6a094992),&nbsp;[AUDIO_DECODER](_codec.md#gga03b4b6ae5fb82af68d46aaea3d3e4d79ae4ade329585f6c202847138e3f9cd4a4),&nbsp;[AUDIO_ENCODER](_codec.md#gga03b4b6ae5fb82af68d46aaea3d3e4d79a7f7f3d3880168089c1de6d1ebc3dbb54),&nbsp;&nbsp;&nbsp;[INVALID_TYPE](_codec.md#gga03b4b6ae5fb82af68d46aaea3d3e4d79a7314b0d0e4638eaaeb8690b8555a6546)&nbsp;} | 枚举编解码的类型&nbsp;[更多...](_codec.md#codectype) | 
| [Profile](_codec.md#profile)&nbsp;{&nbsp;&nbsp;&nbsp;[INVALID_PROFILE](_codec.md#gga85b10143618f300ff4f5bc6d45c72c01a6d67944b4958ad33b0eeb851bbcd169f)&nbsp;=&nbsp;0,&nbsp;[AAC_LC_PROFILE](_codec.md#gga85b10143618f300ff4f5bc6d45c72c01ad91765d6dcad7253a924d3cb30501e44)&nbsp;=&nbsp;0x1000,&nbsp;[AAC_MAIN_PROFILE](_codec.md#gga85b10143618f300ff4f5bc6d45c72c01aada4d857818cd9aa1ad62cdf608dab6b),&nbsp;[AAC_HE_V1_PROFILE](_codec.md#gga85b10143618f300ff4f5bc6d45c72c01ab4255dc0e7450af4f526b85acbabfd3e),&nbsp;&nbsp;&nbsp;[AAC_HE_V2_PROFILE](_codec.md#gga85b10143618f300ff4f5bc6d45c72c01a9b54f7a8c45ea6d4804133d8de4b8dd8),&nbsp;[AAC_LD_PROFILE](_codec.md#gga85b10143618f300ff4f5bc6d45c72c01afaaacd4f6bdadac28b5cf49ae8f8470a),&nbsp;[AAC_ELD_PROFILE](_codec.md#gga85b10143618f300ff4f5bc6d45c72c01a7c8028283d1ff60e486b3305bf8c1adc),&nbsp;[AVC_BASELINE_PROFILE](_codec.md#gga85b10143618f300ff4f5bc6d45c72c01a5bab002f00d3d7281aedc4807123a47a)&nbsp;=&nbsp;0x2000,&nbsp;&nbsp;&nbsp;[AVC_MAIN_PROFILE](_codec.md#gga85b10143618f300ff4f5bc6d45c72c01a323c1d6e02363f1717f7e6b33fd9a646),&nbsp;[AVC_HIGH_PROFILE](_codec.md#gga85b10143618f300ff4f5bc6d45c72c01ab9406e6bf30a0c128c3639cce51fe246),&nbsp;[HEVC_MAIN_PROFILE](_codec.md#gga85b10143618f300ff4f5bc6d45c72c01ae0d37dc2c7d39753a80f6e0ba64e5e22)&nbsp;=&nbsp;0x3000,&nbsp;[HEVC_MAIN_10_PROFILE](_codec.md#gga85b10143618f300ff4f5bc6d45c72c01a811b9e02d8b0afa93e7ab8d2aa7e5de6)&nbsp;} | 枚举Codec规格&nbsp;[更多...](_codec.md#profile) | 
| [AudioSampleRate](_codec.md#audiosamplerate)&nbsp;{&nbsp;&nbsp;&nbsp;[AUD_SAMPLE_RATE_8000](_codec.md#ggaa0280074adafe6d2581d31f71512b842a65d5a1e4d1f048a33d29c9a3b6f540bd)&nbsp;=&nbsp;8000,&nbsp;[AUD_SAMPLE_RATE_12000](_codec.md#ggaa0280074adafe6d2581d31f71512b842ac8379e14b05cdac5edfcc931ac8b33a9)&nbsp;=&nbsp;12000,&nbsp;[AUD_SAMPLE_RATE_11025](_codec.md#ggaa0280074adafe6d2581d31f71512b842a57b1853b1e309bf1aa5b3a35b06b0f81)&nbsp;=&nbsp;11025,&nbsp;[AUD_SAMPLE_RATE_16000](_codec.md#ggaa0280074adafe6d2581d31f71512b842a43395f0fe94ae2949778468e4488c3ee)&nbsp;=&nbsp;16000,&nbsp;&nbsp;&nbsp;[AUD_SAMPLE_RATE_22050](_codec.md#ggaa0280074adafe6d2581d31f71512b842a5e8155ecfa865686a66e004e37ce1e54)&nbsp;=&nbsp;22050,&nbsp;[AUD_SAMPLE_RATE_24000](_codec.md#ggaa0280074adafe6d2581d31f71512b842abd4c09d52f3da25adb108e9aa503119d)&nbsp;=&nbsp;24000,&nbsp;[AUD_SAMPLE_RATE_32000](_codec.md#ggaa0280074adafe6d2581d31f71512b842a1f94827fe757ad2857d970638b6f8d66)&nbsp;=&nbsp;32000,&nbsp;[AUD_SAMPLE_RATE_44100](_codec.md#ggaa0280074adafe6d2581d31f71512b842ac880553f2ee154a240d9414598e006a2)&nbsp;=&nbsp;44100,&nbsp;&nbsp;&nbsp;[AUD_SAMPLE_RATE_48000](_codec.md#ggaa0280074adafe6d2581d31f71512b842ade6dd509c28b66127c42d2634866b89c)&nbsp;=&nbsp;48000,&nbsp;[AUD_SAMPLE_RATE_64000](_codec.md#ggaa0280074adafe6d2581d31f71512b842a925218c15bb8522796e623a09d99dbc3)&nbsp;=&nbsp;64000,&nbsp;[AUD_SAMPLE_RATE_96000](_codec.md#ggaa0280074adafe6d2581d31f71512b842a48336a808a2ebcf5956995140e2d73dd)&nbsp;=&nbsp;96000,&nbsp;[AUD_SAMPLE_RATE_INVALID](_codec.md#ggaa0280074adafe6d2581d31f71512b842a0cb82ce52fb70b359a0b2232f7f465a2)&nbsp;} | 枚举音频采样率&nbsp;[更多...](_codec.md#audiosamplerate) | 
| [CodecCapsMask](_codec.md#codeccapsmask)&nbsp;{&nbsp;[CODEC_CAP_ADAPTIVE_PLAYBACK](_codec.md#gga9e2fbfb8a5881de2f495933f90f23b3fa30c688a80d3e64a3f5c2a13da89eef3c)&nbsp;=&nbsp;0x1,&nbsp;[CODEC_CAP_SECURE_PLAYBACK](_codec.md#gga9e2fbfb8a5881de2f495933f90f23b3fa33911c21f51bcd1980645cac6d0729ca)&nbsp;=&nbsp;0x2,&nbsp;[CODEC_CAP_TUNNEL_PLAYBACK](_codec.md#gga9e2fbfb8a5881de2f495933f90f23b3fa423e1b0d0a7dc9e4abeeded920aafb5b)&nbsp;=&nbsp;0x4,&nbsp;[CODEC_CAP_MULTI_PLANE](_codec.md#gga9e2fbfb8a5881de2f495933f90f23b3fa0da8339e6a216573d7dc3b8d4380d96d)&nbsp;=&nbsp;0x10000&nbsp;} | 枚举播放能力&nbsp;[更多...](_codec.md#codeccapsmask) | 
| [CodecProcessMode](_codec.md#codecprocessmode)&nbsp;{&nbsp;&nbsp;&nbsp;[PROCESS_BLOCKING_INPUT_BUFFER](_codec.md#gga5bec468886b760c542669b1615613dc4a0324b4efc6d2095c788806bf387955fe)&nbsp;=&nbsp;0X1,&nbsp;[PROCESS_BLOCKING_OUTPUT_BUFFER](_codec.md#gga5bec468886b760c542669b1615613dc4acba39cb03563db7f38634009575fdc21)&nbsp;=&nbsp;0X2,&nbsp;[PROCESS_BLOCKING_CONTROL_FLOW](_codec.md#gga5bec468886b760c542669b1615613dc4a2ebd571bd15c86c289b04617e78584ec)&nbsp;=&nbsp;0X4,&nbsp;[PROCESS_NONBLOCKING_INPUT_BUFFER](_codec.md#gga5bec468886b760c542669b1615613dc4a73009c59abb2943e3363ad0aeefa81c1)&nbsp;=&nbsp;0X100,&nbsp;&nbsp;&nbsp;[PROCESS_NONBLOCKING_OUTPUT_BUFFER](_codec.md#gga5bec468886b760c542669b1615613dc4ab943f6f6a762a47e663b74f42941fe9e)&nbsp;=&nbsp;0X200,&nbsp;[PROCESS_NONBLOCKING_CONTROL_FLOW](_codec.md#gga5bec468886b760c542669b1615613dc4a5421710be01e8656530fb22f39e766ea)&nbsp;=&nbsp;0X400&nbsp;} | 枚举编解码处理模式&nbsp;[更多...](_codec.md#codecprocessmode) | 


## **详细描述**

Codec模块接口定义中使用的自定义数据类型。

Codec模块接口定义中使用的自定义数据类型，包括编解码类型、音视频参数、buffer定义等。

**Since：**

3.1

**Version：**

2.0
