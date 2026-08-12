# OH_AVRecorder_EncoderInfo
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @gcw_dyOv3Sds-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @zzs911-->

```c
typedef struct OH_AVRecorder_EncoderInfo {...} OH_AVRecorder_EncoderInfo;
```

## 概述

提供AVRecorder编码器能力信息，包括编码器的MIME类型、比特率范围、帧率范围等参数，适用于在录制前查询和选择合适的音频或视频编码器配置的场景，帮助开发者根据编码器能力参数选择最优编码配置。开发者可通过[OH_AVRecorder_GetAvailableEncoder](capi-avrecorder-h.md#oh_avrecorder_getavailableencoder)接口获取该结构体对象。

**起始版本：** 18

**相关模块：** [AVRecorder](capi-avrecorder.md)

**所在头文件：** [avrecorder_base.h](capi-avrecorder-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [OH_AVRecorder_CodecMimeType](capi-avrecorder-base-h.md#oh_avrecorder_codecmimetype) mimeType | 编码器MIME类型。值与type对应，type为audio时值为音频MIME类型，type为video时值为视频MIME类型。 |
| char* type | 编码器类型，audio表示音频编码器，video表示视频编码器。 |
| [OH_AVRecorder_Range](capi-avrecorder-oh-avrecorder-range.md) bitRate | 编码器支持的比特率范围，单位为比特每秒（bit/s）。音频和视频编码器均适用。 |
| [OH_AVRecorder_Range](capi-avrecorder-oh-avrecorder-range.md) frameRate | 编码器支持的视频帧率范围，单位为帧每秒（fps）。仅适用于视频编码器。 |
| [OH_AVRecorder_Range](capi-avrecorder-oh-avrecorder-range.md) width | 编码器支持的视频帧宽度范围，单位为像素（px）。仅适用于视频编码器。 |
| [OH_AVRecorder_Range](capi-avrecorder-oh-avrecorder-range.md) height | 编码器支持的视频帧高度范围，单位为像素（px）。仅适用于视频编码器。 |
| [OH_AVRecorder_Range](capi-avrecorder-oh-avrecorder-range.md) channels | 编码器支持的音频声道数的范围，取值由设备编码器能力决定，常见取值为1（单声道）或2（立体声）。仅适用于音频编码器。 |
| int32_t* sampleRate | 音频采样率列表，包含所有支持的音频采样率值，取值由设备编码器能力决定，常见取值如8000、16000、44100、48000等，单位为赫兹（Hz）。与sampleRateLen字段配合使用，sampleRateLen表示该列表的长度。仅适用于音频编码器。 |
| int32_t sampleRateLen | 音频采样率列表长度，取值为大于0的整数，与sampleRate字段配合使用，表示sampleRate数组中元素的个数。仅适用于音频编码器。 |


