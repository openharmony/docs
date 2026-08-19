# OH_AudioAccessoryCapabilities
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_AudioAccessoryCapabilities {...} OH_AudioAccessoryCapabilities
```

## 概述

定义音频配件的能力。

调用方需将structSize设置为sizeof(OH_AudioAccessoryCapabilities)。

**起始版本：** 26.0.0

**相关模块：** [OHAudio](capi-ohaudio.md)

**所在头文件：** [native_audio_accessory_common.h](capi-native-audio-accessory-common-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t structSize | 结构体大小，单位为字节（Byte）。<br>调用方需初始化此字段。 |
| const [OH_AudioStreamInfo](capi-ohaudio-oh-audiostreaminfo.md) *streamProperties | 支持的音频流配置数组。<br>每个条目表示采样率、采样格式和声道数的有效组合。<br>系统会对此数组进行深拷贝。 |
| uint32_t streamPropertyCount | 支持的音频流配置数量。 |