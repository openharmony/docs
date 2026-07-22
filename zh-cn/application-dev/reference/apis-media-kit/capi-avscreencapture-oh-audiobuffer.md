# OH_AudioBuffer
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @yxc2-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_AudioBuffer {...} OH_AudioBuffer
```

## 概述

定义了音频缓冲区数据及其大小、类型、时间戳等属性信息。

在屏幕录制过程中，该结构体由系统通过音频数据回调填充，开发者可从中读取录制的音频帧数据及其时间戳，用于后续音频处理或编码。适用于需要获取屏幕录制音频帧数据的场景。

**起始版本：** 10

**相关模块：** [AVScreenCapture](capi-avscreencapture.md)

**所在头文件：** [native_avscreen_capture_base.h](capi-native-avscreen-capture-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint8_t* buf | 指向音频缓冲区内存的指针。由系统分配和释放，开发者无需手动管理。音频缓冲区用于存储录制的音频采样数据，数据格式为PCM原始字节流，需配合size字段确定数据长度。 |
| int32_t size | 音频缓冲区内存大小，单位为字节（Byte），表示buf指针所指音频数据的字节长度。取值范围大于等于0，传入负数时行为未定义。 |
| int64_t timestamp | 音频缓冲区时间戳。单位为纳秒（ns）。 |
| [OH_AudioCaptureSourceType](capi-native-avscreen-capture-base-h.md#oh_audiocapturesourcetype) type | 音频录制源类型。其值由OH_AudioCaptureInfo中配置的[OH_AudioCaptureSourceType](capi-native-avscreen-capture-base-h.md#oh_audiocapturesourcetype)决定。 |


