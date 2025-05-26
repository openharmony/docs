# OH_AudioBuffer

## 概述

定义了音频数据的大小、类型、时间戳等配置信息。

**起始版本：** 10

**相关模块：** [AVScreenCapture](capi-avscreencapture.md)

**所在头文件：** [native_avscreen_capture_base.h](capi-native-avscreen-capture-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint8_t* buf | 音频buffer块 |
| int32_t size | 音频buffer块大小 |
| int64_t timestamp | 时间戳 |
| OH_AudioCaptureSourceType type | 音频录制类型 |


