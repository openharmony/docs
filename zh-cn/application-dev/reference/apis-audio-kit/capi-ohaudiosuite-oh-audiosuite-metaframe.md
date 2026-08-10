# OH_AudioSuite_MetaFrame
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xxngwang-->
<!--Designer: @jay-liusong-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_AudioSuite_MetaFrame {...} OH_AudioSuite_MetaFrame
```

## 概述

定义包含音频数据和元数据的帧结构。

**起始版本：** 26.0.0

**相关模块：** [OHAudioSuite](capi-ohaudiosuite.md)

**所在头文件：** [native_audio_suite_base.h](capi-native-audio-suite-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| void* audioData | 音频数据指针。 |
| int32_t audioDataSize | 音频数据大小。 |
| void* metaData | 元数据指针。 |
| int32_t metaDataSize | 元数据大小。 |


