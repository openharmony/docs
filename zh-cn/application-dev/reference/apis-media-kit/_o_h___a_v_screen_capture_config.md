# OH_AVScreenCaptureConfig


## 概述

屏幕录制配置参数。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**相关模块：**[AVScreenCapture](_a_v_screen_capture.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [OH_CaptureMode](_a_v_screen_capture.md#oh_capturemode) [captureMode](#capturemode) | 屏幕录制的模式。 | 
| [OH_DataType](_a_v_screen_capture.md#oh_datatype) [dataType](#datatype) | 屏幕录制流的数据格式。 | 
| [OH_AudioInfo](_o_h___audio_info.md) [audioInfo](#audioinfo) | 音频录制参数。 | 
| [OH_VideoInfo](_o_h___video_info.md) [videoInfo](#videoinfo) | 视频录制参数。 | 
| [OH_RecorderInfo](_o_h___recorder_info.md) [recorderInfo](#recorderinfo) | 录制文件参数，当数据格式为OH_CAPTURE_FILE时，必须设置。 | 


## 结构体成员变量说明


### audioInfo

```
OH_AudioInfo OH_AVScreenCaptureConfig::audioInfo
```

**描述**

音频录制参数。


### captureMode

```
OH_CaptureMode OH_AVScreenCaptureConfig::captureMode
```

**描述**

屏幕录制的模式。


### dataType

```
OH_DataType OH_AVScreenCaptureConfig::dataType
```

**描述**

屏幕录制流的数据格式。


### recorderInfo

```
OH_RecorderInfo OH_AVScreenCaptureConfig::recorderInfo
```

**描述**

录制文件参数，当数据格式为OH_CAPTURE_FILE时，必须设置。


### videoInfo

```
OH_VideoInfo OH_AVScreenCaptureConfig::videoInfo
```

**描述**

视频录制参数。
