# OH_AVRecorder_Profile


## 概述

定义音视频录制的详细参数。

可以通过参数设置选择只录制音频或只录制视频：当 audioBitrate 或 audioChannels 为 0 时，不录制音频；当 videoFrameWidth 或 videoFrameHeight 为 0 时，不录制视频。

各参数的范围请参见[AVRecorderProfile](js-apis-media.md#avrecorderprofile9)。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 16

**相关模块：**[AVRecorder](_a_v_recorder.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [audioBitrate](#audiobitrate) | 音频比特率。 | 
| int32_t [audioChannels](#audiochannels) | 音频通道数。 | 
| [OH_AVRecorder_CodecMimeType](_a_v_recorder.md#oh_avrecorder_codecmimetype) [audioCodec](#audiocodec) | 音频编码格式。 | 
| int32_t [audioSampleRate](#audiosamplerate) | 音频采样率。 | 
| [OH_AVRecorder_ContainerFormatType](_a_v_recorder.md#oh_avrecorder_containerformattype) [fileFormat](#fileformat) | 输出文件格式。 | 
| int32_t [videoBitrate](#videobitrate) | 视频比特率。 | 
| [OH_AVRecorder_CodecMimeType](_a_v_recorder.md#oh_avrecorder_codecmimetype) [videoCodec](#videocodec) | 视频编码格式。 | 
| int32_t [videoFrameWidth](#videoframewidth) | 视频宽度。 | 
| int32_t [videoFrameHeight](#videoframeheight) | 视频高度。 | 
| int32_t [videoFrameRate](#videoframerate) | 视频帧率。 | 
| bool [isHdr](#ishdr) | 是否录制 HDR 视频。 | 
| bool [enableTemporalScale](#enabletemporalscale) | 是否启用时间缩放编码模式。 | 


## 成员变量说明


### audioBitrate

```
int32_t audioBitrate
```

**描述**

音频比特率。


### audioChannels

```
int32_t audioChannels
```

**描述**

音频通道数。


### audioCodec

```
OH_AVRecorder_CodecMimeType audioCodec
```

**描述**

音频编码格式。


### audioSampleRate

```
int32_t audioSampleRate
```

**描述**

音频采样率。


### fileFormat

```
OH_AVRecorder_ContainerFormatType fileFormat
```

**描述**

输出文件格式。


### videoBitrate

```
int32_t videoBitrate
```

**描述**

视频比特率。


### videoCodec

```
OH_AVRecorder_CodecMimeType videoCodec
```

**描述**

视频编码格式。


### videoFrameWidth

```
int32_t videoFrameWidth
```

**描述**

视频宽度。


### videoFrameHeight

```
int32_t videoFrameHeight
```

**描述**

视频高度。


### videoFrameRate

```
int32_t videoFrameRate
```

**描述**

视频帧率。


### isHdr

```
bool isHdr
```

**描述**

是否录制 HDR 视频。


### enableTemporalScale

```
bool enableTemporalScale
```

**描述**

是否启用时间缩放编码模式。
