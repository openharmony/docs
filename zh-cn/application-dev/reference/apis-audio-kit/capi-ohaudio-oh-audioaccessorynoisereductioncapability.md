# OH_AudioAccessoryNoiseReductionCapability
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_AudioAccessoryNoiseReductionCapability {...} OH_AudioAccessoryNoiseReductionCapability
```

## 概述

定义音频配件的降噪能力。

**起始版本：** 26.0.0

**相关模块：** [OHAudio](capi-ohaudio.md)

**所在头文件：** [native_audio_accessory_common.h](capi-native-audio-accessory-common-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t structSize | 结构体大小，单位为字节（Byte）。<br>调用方需初始化此字段。<br>系统通过此字段校验结构体大小。 |
| const [OH_AudioNoiseReductionMode](capi-native-audio-common-h.md#oh_audionoisereductionmode) *supportedModes | 支持的降噪模式数组。 |
| uint32_t supportedModeCount | 支持的降噪模式数量。 |
| [OH_AudioNoiseReductionMode](capi-native-audio-common-h.md#oh_audionoisereductionmode) currentMode | 设备当前降噪模式。<br>表示注册能力时的初始状态。 |
