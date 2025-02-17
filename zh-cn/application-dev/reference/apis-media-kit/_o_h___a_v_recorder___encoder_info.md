# OH_AVRecorder_EncoderInfo


## 概述

提供编码器信息。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 16

**相关模块：**[AVRecorder](_a_v_recorder.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVRecorder_CodecMimeType](_a_v_recorder.md#oh_avrecorder_codecmimetype) [mimeType](#mimetype) | 编码器MIME类型名称。 | 
| char \*[type](#type) | 编码器类型，audio表示音频编码器，video表示视频编码器。 | 
| [OH_AVRecorder_Range](_o_h___a_v_recorder___range.md) [bitRate](#bitrate) | 比特率，包含该编码器的最大和最小值。 | 
| [OH_AVRecorder_Range](_o_h___a_v_recorder___range.md) [frameRate](#framerate) | 视频帧率，包含帧率的最大和最小值，仅视频编码器拥有。 | 
| [OH_AVRecorder_Range](_o_h___a_v_recorder___range.md) [width](#width) | 视频帧的宽度，包含宽度的最大和最小值，仅视频编码器拥有。 | 
| [OH_AVRecorder_Range](_o_h___a_v_recorder___range.md) [height](#height) | 视频帧的高度，包含高度的最大和最小值，仅视频编码器拥有。 | 
| [OH_AVRecorder_Range](_o_h___a_v_recorder___range.md) [channels](#channels) | 音频采集声道数，包含声道数的最大和最小值，仅音频编码器拥有。 | 
| int32_t \*[sampleRate](#samplerate) | 音频采样率列表，包含所有可以使用的音频采样率值，仅音频编码器拥有。 | 
| int32_t [sampleRateLen](#sampleratelen) | 音频采样率列表长度。 | 


## 成员变量说明


### mimeType

```
OH_AVRecorder_CodecMimeType mimeType
```

**描述**

编码器MIME类型名称。


### type

```
char *type
```

**描述**

编码器类型，audio表示音频编码器，video表示视频编码器。


### bitRate

```
OH_AVRecorder_Range bitRate
```

**描述**

比特率，包含该编码器的最大和最小值。


### frameRate

```
OH_AVRecorder_Range frameRate
```

**描述**

视频帧率，包含帧率的最大和最小值，仅视频编码器拥有。


### width

```
OH_AVRecorder_Range width
```

**描述**

视频帧的宽度，包含宽度的最大和最小值，仅视频编码器拥有。


### height

```
OH_AVRecorder_Range height
```

**描述**

视频帧的高度，包含高度的最大和最小值，仅视频编码器拥有。


### channels

```
OH_AVRecorder_Range channels
```

**描述**

音频采集声道数，包含声道数的最大和最小值，仅音频编码器拥有。


### sampleRate

```
int32_t *sampleRate
```

**描述**

音频采样率列表，包含所有可以使用的音频采样率值，仅音频编码器拥有。


### sampleRateLen

```
int32_t sampleRateLen
```

**描述**

音频采样率列表长度。
