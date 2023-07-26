# AVScreenCaptureBase


## 概述

AVScreenCaptureBase模块提供运行录屏通用的结构体、字符常量、枚举。该模块部分参数暂时不支持，在以下说明中会详细解答。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioCaptureInfo](#oh_audiocaptureinfo) | 定义音频录制audiocapture实例的描述信息。 |
| [OH_AudioEncInfo](#oh_audioencinfo) | 定义音频的编码数据的描述信息。 |
| [OH_AudioInfo](#oh_audioinfo) | 定义屏幕录制时音频的描述信息。 |
| [OH_VideoCaptureInfo](#oh_videocaptureinfo) | 定义屏幕录制中视频录制采集的描述信息。 |
| [OH_VideoEncInfo](#oh_videoencinfo) | 定义屏幕录制中视频的编码数据描述信息。 |
| [OH_VideoInfo](#oh_videoinfo) | 定义屏幕录制时视频的描述信息。 |
| [OH_AVScreenCaptureConfig](#oh_avscreencaptureconfig) | 定义整体avscreencapture的配置信息。 |
| [OH_AVScreenCaptureCallback](_a_v_screen_capture_callback.md) | 定义avscreencapture的回调信息，包含不同的回调函数类型。 |
| [OH_Rect](#oh_rect) | 定义录屏的宽高以及画面信息。 |
| [OH_AudioBuffer](#oh_audiobuffer) | 定义了音频数据的大小，类型，时间戳等配置信息。 |

### 类型定义
| 名称 | 描述 | 
| -------- | -------- |
| (\*[OH_AVScreenCaptureOnError](#oh_avscreencaptureonerror)) (OH_AVScreenCapture \*capture, int32_t errorCode)| 当screencapture在运行过程中执行某一流程出现错误，则调用该函数指针并上报错误码。 |
| (\*[OH_AVScreenCaptureOnAudioBufferAvailable](#oh_avscreencaptureonaudiobufferavailable)) (OH_AVScreenCapture \*capture, bool isReady， OH_AudioCaptureSourceType type)| 当screencapture在运行，音频缓冲可用时，调用该函数指针并更新状态信息。 |
| (\*[OH_AVScreenCaptureOnVideoBufferAvailable](#oh_avscreencaptureonvideobufferavailable)) (OH_AVScreenCapture \*capture, bool isReady)| 当screencapture在运行，视频缓冲可用时，调用该函数指针并更新状态信息。 |

### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_CaptureMode](#oh_capturemode) {<br/>**OH_CAPTURE_HOME_SCREEN** = 0，**OH_CAPTURE_SPECIFIED_SCREEN** = 1, **OH_CAPTURE_SPECIFIED_WINDOW** = 2, **OH_CAPTURE_INVAILD** = -1<br/>} | 屏幕录制的不同模式。 |
| [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) {<br/>**OH_SOURCE_INVALID** = -1, **OH_SOURCE_DEFAULT** = 0, **OH_MIC** = 1, **OH_ALL_PLAYBACK** = 2, **OH_APP_PLAYBACK** = 3<br/>} | 屏幕录制音频的不同source类型。 |
| [OH_AudioCodecFormat](#oh_audiocodecformat) {<br/>**OH_AUDIO_DEFAULT** = 0, **OH_AAC_LC** = 3, **OH_AUDIO_CODEC_FORMAT_BUTT**,<br/>} | 屏幕录制音频的不同的编码格式。 |
| [OH_VideoCodecFormat](#oh_videocodecformat) {<br/>**OH_VIDEO_DEFAULT** = 0, **OH_H264** = 2, **OH_H265** = 4, **OH_MPEG4** = 6, **OH_VP8** = 8, **OH_VP9** = 10, **OH_VIDEO_CODEC_FORMAT_BUTT**<br/>} | 屏幕录制视频的不同编码格式。 |
| [OH_DataType](#oh_datatype) {<br/>**OH_ORIGINAL_STREAM** = 0, **OH_ENCODED_STREAM** = 1, **OH_CAPTURE_FILE** = 2, **OH_INVAILD** = -1<br/>} | 屏幕录制流的数据格式，编码格式，以及保存文件格式等参数。 |
| [OH_VideoSourceType](#oh_videosourcetype) {<br/>**OH_VIDEO_SOURCE_SURFACE_YUV** = 0, **OH_VIDEO_SOURCE_SURFACE_ES**, **OH_VIDEO_SOURCE_SURFACE_RGBA**, **OH_VIDEO_SOURCE_BUTT**<br/>} | 屏幕录制视频的不同source类型。 |
| [OH_ContainerFormatType](#oh_containerformattype) {<br/>**CFT_MPEG_4A** = 0, **CFT_MPEG_4** = 1<br/>} | 屏幕录制生成物的不同音视频格式类型。 |

### 变量

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioCaptureInfo::audioSampleRate](#audiosamplerate) | 录屏音频采样率， 支持列表见[OH_AudioCapturer_GetSamplingRate](#_o_h_audio.md#oh_audiocapturer_getsamplingrate)。 | 
| [OH_AudioCaptureInfo::audioChannels](#audiochannels) | 录屏音频声道数。 | 
| [OH_AudioCaptureInfo::audioSource](#audiosource) | 录屏音频的source源，如麦克风或者内录。 |
| [OH_AudioEncInfo::audioBitrate](#audiobitrate) | 录制音频的比特率，用于编码相关参数的设置。 |
| [OH_AudioEncInfo::audioCodecformat](#audiocodecformat) | 录制音频的编码格式。 |
| [OH_AudioInfo::micCapInfo](#miccapinfo) | 录制的mic的音频参数设置，设置类型为OH_AudioCaptureInfo。 |
| [OH_AudioInfo::innerCapInfo](#innercapinfo) | 录制的内录的音频参数设置，设置类型为OH_AudioCaptureInfo。 |
| [OH_AudioInfo::audioEncInfo](#audioencinfo) | 录制音频编码的相关参数，设置类型为OH_AudioEncInfo。 |
| [OH_VideoCaptureInfo::displayId](#displayid) | 录制物理屏id，使用该参数需要在capturemode为CAPTURE_SPECIFIED_SCREEN模式下使用。 |
| [OH_VideoCaptureInfo::missionIDs](#missionids) | 指定窗口id列表，使用该参数需要在capturemode为CAPTURE_SPECIFIED_WINDOW模式下使用。 |
| [OH_VideoCaptureInfo::missionIDsLen](#missionidslen) | 指定窗口的，使用该参数需要在capturemode为CAPTURE_SPECIFIED_WINDOW模式下使用。 |
| [OH_VideoCaptureInfo::videoFrameWidth](#videoframewidth) | 采集视频的宽度设置。 |
| [OH_VideoCaptureInfo::videoFrameHeight](#videoframeheight) | 采集视频的高度设置。 |
| [OH_VideoCaptureInfo::videoSource](#videosource) | 视频采集格式设置，目前仅支持RGBA格式。 |
| [OH_VideoEncInfo::videoCodec](#videocodec) | 视频采集编码格式，类型为OH_VideoCodecFormat。 |
| [OH_VideoEncInfo::videoBitrate](#videobitrate) | 视频采集比特率。 |
| [OH_VideoEncInfo::videoFrameRate](#videoframerate) | 视频采集帧率。 |
| [OH_VideoInfo::videoCapInfo](#videocapinfo) | 视频采集信息的设置，设置类型为OH_VideoCaptureInfo。 |
| [OH_VideoInfo::videoEncInfo](#videoencinfo) | 视频编码参数的设置，设置类型为OH_VideoEncInfo。 |
| [OH_AVScreenCaptureConfig::captureMode](#capturemode) | 屏幕录制方式，如全屏录制，指定物理屏录制或者指定窗口录制。 |
| [OH_AVScreenCaptureConfig::dataType](#datatype) | 屏幕录制的形式，比如录制原始码流，编码后码流还是文件。 |
| [OH_AVScreenCaptureConfig::audioInfo](#audioinfo) | 录制音频相关参数设置，类型为OH_AudioInfo。 |
| [OH_AVScreenCaptureConfig::videoInfo](#videoinfo) | 录制视频相关参数设置，类型为OH_VideoInfo。 |
| [OH_AVScreenCaptureCallback::onError](_a_v_screen_capture_callback.md#onerror) | 录屏过程中错误事件的监听函数。 |
| [OH_AVScreenCaptureCallback::onAudioBufferAvailable](_a_v_screen_capture_callback.md#onaudiobufferavailable) | 录屏过程中音频流产生的监听。 |
| [OH_AVScreenCaptureCallback::onVideoBufferAvailable](_a_v_screen_capture_callback.md#onvideobufferavailable) | 录屏过程中视频流产生的监听。 |
| [OH_Rect::x](#x) | 视频数据的x坐标。 |
| [OH_Rect::y](#y) | 视频数据的y坐标。 |
| [OH_Rect::width](#width) | 视频宽度。 |
| [OH_Rect::height](#height) | 视频高度。 |
| [OH_AudioBuffer::buf](#buf) | 存放音频数据。 |
| [OH_AudioBuffer::size](#size) | 存放音频每一帧数据的长度。 |
| [OH_AudioBuffer::timestamp](#timestamp) | 音频的时间戳。 |
| [OH_AudioBuffer::type](#type) | 音频数据源类型，比如内录源还是mic。 |


## 类型定义说明

# OH_AudioCaptureInfo

```
typedef struct OH_AudioCaptureInfo OH_AudioCaptureInfo
```

## 概述

定义音频录制audiocapture实例的描述信息。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

### 成员变量

|                 名称                 |                描述                 |
| ----------------------------------- | ----------------------------------- |
| [audioSampleRate](#audiosamplerate) | 录屏音频采样率。                      |
| [audioChannels](#audiochannels)     | 录制音频的声道数。                    |
| [audioSource](#audiosource)         | 录屏音频的source源，如麦克风或者内录。 |

## 结构体成员变量说明


### audiosamplerate


```
int32_t audioSampleRate
```

**描述：**

音频采样率，支持列表见[OH_AudioCapturer_GetSamplingRate](#_o_h_audio.md#oh_audiocapturer_getsamplingrate)。

**起始版本：**

10


### audioChannels

  
```
int32_t audioChannels
```

**描述：**

采样声道数。

**起始版本：**

10


### audioSource


```
OH_AudioCaptureSourceType audioSource;
```

**描述：**

录屏音频的source源，如麦克风或者内录。

**起始版本：**

10

# OH_AudioEncInfo

```
typedef struct OH_AudioCaptureInfo OH_AudioCaptureInfo
```

## 概述

定义音频的编码数据的描述信息。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [audioBitrate](#audiobitrate) | 录屏音频比特率。 |
| [audioCodecformat](#audiocodecformat) | 录屏音频编码格式。 |

## 结构体成员变量说明


### audioBitrate


```
int32_t audioBitrate
```

**描述：**

录屏音频比特率。

**起始版本：**

10

### audioCodecformat


```
OH_AudioCodecFormat audioCodecformat
```

**描述：**

录屏音频编码格式。

**起始版本：**

10

# OH_AudioInfo

```
typedef struct OH_AudioInfo
```

## 概述

定义屏幕录制音频的描述信息。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [micCapInfo](#miccapinfo) | 麦克风录制信息。 |
| [innerCapInfo](#innercapinfo) | 内录录制信息。 |
| [audioEncInfo](#audioencinfo) | 音频编码信息。 |

## 结构体成员变量说明


### micCapInfo


```
OH_AudioCaptureInfo micCapInfo
```

**描述：**
麦克风录制信息。

**起始版本：**

10

### innerCapInfo


```
OH_AudioCaptureInfo innerCapInfo
```

**描述：**
声音内录录制信息。

**起始版本：**

10

### audioEncInfo


```
OH_AudioCaptureInfo audioEncInfo
```

**描述：**
音频编码信息。

**起始版本：**

10

# OH_VideoCaptureInfo

```
typedef struct OH_VideoCaptureInfo OH_VideoCaptureInfo 
```

## 概述

定义屏幕录制中视频录制的描述信息。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [displayId](#displayid) | 录屏显示id。 |
| [missionIDs](#missionids) | 录屏任务id。 |
| [missionIDsLen](#missionidslen) | 录屏任务id长度。 |
| [videoFrameWidth](#videoframewidth) | 录屏视频帧宽。 |
| [videoFrameHeight](#videoframeheight) | 录屏视频帧高。 |
| [videoSource](#videosource) | 录屏视频数据源。 |

## 结构体成员变量说明


### displayId


```
uint64_t displayId
```

**描述：**
录屏的显示id，用于选择绑定指定屏幕录屏。

**起始版本：**

10

### missionIDs


```
int32_t *missionIDs
```

**描述：**
指定特定屏幕录屏时，对应的录屏任务id信息。

**起始版本：**

10

### missionIDsLen


```
int32_t missionIDsLen
```

**描述：**
指定特定屏幕录屏时，录屏任务id信息长度。

**起始版本：**

10

### videoFrameWidth


```
int32_t videoFrameWidth
```

**描述：**
视频分辨率中的帧宽参数。

**起始版本：**

10

### videoFrameHeight


```
int32_t videoFrameHeight
```

**描述：**
视频分辨率中的帧高参数。

**起始版本：**

10

### videoSource


```
OH_VideoSourceType videoSource
```

**描述：**
录屏视频源类型参数。

**起始版本：**

10

# OH_VideoEncInfo

```
typedef struct OH_VideoEncInfo OH_VideoEncInfo 
```

## 概述

定义屏幕录制中视频数据的编码信息。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [videoCodec](#videocodec) | 视频数据编码信息。 |
| [videoBitrate](#videobitrate) | 视频数据比特率信息。 |
| [videoFrameRate](#videoframerate) | 视频数据帧率参数。 |

## 结构体成员变量说明


### videoCodec


```
OH_VideoCodecFormat videoCodec
```

**描述：**
录屏视频数据的编码信息。

**起始版本：**

10

### videoBitrate


```
int32_t videoBitrate
```

**描述：**
录屏视频数据的比特率信息。

**起始版本：**

10

### videoFrameRate


```
int32_t videoFrameRate
```

**描述：**
录屏视频数据的帧率信息。

**起始版本：**

10


# OH_VideoInfo

```
typedef struct OH_VideoInfo OH_VideoInfo 
```

## 概述

定义屏幕录制时视频的描述信息。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [videoCapInfo](#videocapinfo) | 视频数据编码信息。 |
| [videoEncInfo](#videoencinfo) | 视频数据比特率信息。 |

## 结构体成员变量说明


### videoCapInfo


```
OH_VideoCaptureInfo videoCapInfo
```

**描述：**
视频采集信息的设置，设置类型为OH_VideoCaptureInfo。

**起始版本：**

10

### videoEncInfo


```
OH_VideoEncInfo videoEncInfo
```

**描述：**
视频编码参数的设置，设置类型为OH_VideoEncInfo。

**起始版本：**

10

# OH_AVScreenCaptureConfig

```
typedef struct OH_AVScreenCaptureConfig OH_AVScreenCaptureConfig 
```

## 概述

定义整体avscreencapture的配置信息。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [captureMode](#capturemode) | 屏幕录制方式，如全屏录制，指定物理屏录制或者指定窗口录制。 |
| [dataType](#datatype) | 屏幕录制的形式，比如录制原始码流，编码后码流还是文件。 |
| [audioInfo](#audioinfo) | 录制音频相关参数设置，类型为OH_AudioInfo。 |
| [videoInfo](#videoinfo) | 录制视频相关参数设置，类型为OH_VideoInfo。 |


## 结构体成员变量说明


### captureMode


```
OH_CaptureMode captureMode
```

**描述：**
屏幕录制方式，如全屏录制，指定物理屏录制或者指定窗口录制。

**起始版本：**

10

### dataType


```
OH_DataType dataType
```

**描述：**
屏幕录制的形式，比如录制原始码流，编码后码流还是文件。

**起始版本：**

10

### audioInfo


```
OH_AudioInfo audioInfo
```

**描述：**
录制音频相关参数设置，类型为OH_AudioInfo。

**起始版本：**

10

### videoInfo


```
OH_VideoInfo videoInfo
```

**描述：**
录制视频相关参数设置，类型为OH_VideoInfo。

**起始版本：**

10

# OH_AVScreenCaptureCallback

```
typedef struct OH_AVScreenCaptureCallback OH_AVScreenCaptureCallback 
```

## 概述

定义avscreencapture的回调信息，包含不同的回调函数类型。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [onError](#onerror) | 录屏过程中错误事件的监听函数。 |
| [onAudioBufferAvailable](#onaudiobufferavailable) | 录屏过程中音频流产生的监听。 |
| [onVideoBufferAvailable](#onvideobufferavailable) | 录屏过程中视频流产生的监听。 |

## 结构体成员变量说明


### onError


```
OH_AVScreenCaptureOnError onError
```

**描述：**
录屏过程中错误事件的监听函数，具体错误码可参照[错误码说明文档](native__avscreen_capture_errors_8h.md#oh_avscreen_capture_errcode)。

**起始版本：**

10

### onAudioBufferAvailable


```
OH_AVScreenCaptureOnAudioBufferAvailable onAudioBufferAvailable
```

**描述：**
录屏过程中音频流产生的监听。

**起始版本：**

10

### onVideoBufferAvailable


```
OH_AVScreenCaptureOnVideoBufferAvailable onVideoBufferAvailable
```

**描述：**
录屏过程中视频流产生的监听。

**起始版本：**

10

# OH_Rect

```
typedef struct OH_Rect OH_Rect 
```

## 概述

定义录屏的宽高以及画面信息。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [x](#x) | 视频数据的x坐标。 |
| [y](#y) | 视频数据的y坐标。 |
| [width](#width) | 视频宽度。 |
| [height](#height) | 视频高度。 |

## 结构体成员变量说明


### x


```
int32_t x
```

**描述：**
视频数据的x坐标。

**起始版本：**

10

### y


```
int32_t y
```

**描述：**
视频数据的y坐标。

**起始版本：**

10

### width


```
int32_t width
```

**描述：**
视频宽度。

**起始版本：**

10

### height


```
int32_t height
```

**描述：**
视频高度。

**起始版本：**

10

# OH_AudioBuffer

```
typedef struct OH_AudioBuffer OH_AudioBuffer 
```

## 概述

定义了音频数据的大小，类型，时间戳等配置信息。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [buf](#buf) | 存放音频数据。 |
| [size](#size) | 存放音频每一帧数据的长度。 |
| [timestamp](#timestamp) | 音频的时间戳。 |
| [type](#type) | 音频数据源类型，比如内录源还是mic。 |

## 结构体成员变量说明


### buf


```
uint8_t *buf
```

**描述：**
存放音频数据。

**起始版本：**

10

### size


```
int32_t size
```

**描述：**
存放音频每一帧数据的长度。

**起始版本：**

10

### timestamp


```
int64_t timestamp
```

**描述：**
音频的时间戳。

**起始版本：**

10

### type


```
OH_AudioCaptureSourceType type
```

**描述：**
音频数据源类型，比如内录源还是mic。

**起始版本：**

10

### OH_AVScreenCaptureOnError

  
```
typedef void (*OH_AVScreenCaptureOnError)(OH_AVScreenCapture *capture, int32_t errorCode)
```

**描述：**

当实例AVScreenCapture运行出错时，会调用来上报具体的错误信息的函数指针。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | OH_AVScreenCapture实例 | 
| errorCode | 特定错误码 |

### OH_AVScreenCaptureOnAudioBufferAvailable

  
```
typedef void (*OH_AVScreenCaptureOnAudioBufferAvailable)(OH_AVScreenCapture *capture, bool isReady, OH_AudioCaptureSourceType type)
```

**描述：**

当实例AVScreenCapture申请到音频数据可用时，回调来产生音频流监听。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | OH_AVScreenCapture实例 | 
| isReady | 状态参数 |
| type | 音频数据源类型，比如内录源还是mic |

### OH_AVScreenCaptureOnVideoBufferAvailable

  
```
typedef void (*OH_AVScreenCaptureOnVideoBufferAvailable)(OH_AVScreenCapture *capture, bool isReady)
```

**描述：**

当实例AVScreenCapture申请到视频数据可用时，回调来产生视频流监听。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | OH_AVScreenCapture实例 | 
| isReady | 状态参数 |


### OH_CaptureMode
  
```
typedef enum OH_CaptureMode OH_CaptureMode
```

**描述：**

屏幕录制模式。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

### OH_AudioCaptureSourceType
  
```
typedef enum OH_AudioCaptureSourceType OH_AudioCaptureSourceType
```

**描述：**

屏幕录制音频数据源类型，如内录或mic。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

### OH_AudioCodecFormat
  
```
typedef enum OH_AudioCodecFormat OH_AudioCodecFormat
```

**描述：**

屏幕录制音频数据编码格式。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

### OH_VideoCodecFormat
  
```
typedef enum OH_VideoCodecFormat OH_VideoCodecFormat
```

**描述：**

屏幕录制视频数据编码格式。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

### OH_DataType
  
```
typedef enum OH_DataType OH_DataType
```

**描述：**
屏幕录制的形式，比如录制原始码流，编码后码流还是文件。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

### OH_VideoSourceType
  
```
typedef enum OH_VideoSourceType OH_VideoSourceType
```

**描述：**
屏幕录制视频数据源类型，如手动设置或直接从显示中获取。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

### OH_ContainerFormatType
  
```
typedef enum OH_ContainerFormatType OH_ContainerFormatType
```

**描述：**
屏幕录制数据容器类型。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

## 枚举类型说明


### OH_CaptureMode

```
enum OH_CaptureMode
```

**描述：**

屏幕录制模式。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

| 枚举值 | 描述 |
| -------- | -------- |
| OH_CAPTURE_HOME_SCREEN | 录制主屏幕模式。 | 
| OH_CAPTURE_SPECIFIED_SCREEN | 录制指定屏幕模式。 |
| OH_CAPTURE_SPECIFIED_WINDOW | 录制指定窗口模式。 |
| OH_CAPTURE_INVAILD | 录制错误模式。 |

### OH_AudioCaptureSourceType

```
enum OH_AudioCaptureSourceType
```

**描述：**

音频录制数据源类型。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

| 枚举值 | 描述 |
| -------- | -------- |
| OH_SOURCE_INVALID | 错误类型。 | 
| OH_SOURCE_DEFAULT | 默认类型。 |
| OH_MIC | 麦克风类型。 |
| OH_ALL_PLAYBACK | 内录类型。 |
| OH_APP_PLAYBACK | 指定app内录类型。 |

### OH_AudioCodecFormat 

```
enum OH_AudioCodecFormat 
```

**描述：**

音频录制数据编码类型。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

| 枚举值 | 描述 |
| -------- | -------- |
| OH_AUDIO_DEFAULT | 默认格式类型。 | 
| OH_AAC_LC  | aac_lc格式类型。 |
| OH_AUDIO_CODEC_FORMAT_BUTT | 错误格式类型。 |

### OH_VideoCodecFormat 

```
enum OH_VideoCodecFormat 
```

**描述：**

视频录制数据编码类型。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

| 枚举值 | 描述 |
| -------- | -------- |
| OH_VIDEO_DEFAULT | 默认格式类型。 | 
| OH_H264 | h264格式类型。 |
| OH_H265 | h265格式类型。 |
| OH_MPEG4 | mp4格式类型。 |
| OH_VP8 | vp8格式类型。 |
| OH_VP9 | vp9格式类型。 |
| OH_VIDEO_CODEC_FORMAT_BUTT | 错误格式类型。|

### OH_DataType 

```
enum OH_DataType 
```

**描述：**

录屏生成数据形式，码流或指定格式文件。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

| 枚举值 | 描述 |
| -------- | -------- |
| OH_VIDEO_SOURCE_SURFACE_YUV | yuv格式类型。 | 
| OH_VIDEO_SOURCE_SURFACE_ES | es格式类型。 |
| OH_VIDEO_SOURCE_SURFACE_RGBA | rgba格式类型。 |
| OH_VIDEO_SOURCE_BUTT | 错误格式类型。 |

### OH_ContainerFormatType  

```
enum OH_ContainerFormatType  
```

**描述：**

录制生成数据容器格式类型。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

| 枚举值 | 描述 |
| -------- | -------- |
| CFT_MPEG_4A | 音频格式m4a格式。 | 
| CFT_MPEG_4 | 视频格式mp4格式。 |

### OH_ContainerFormatType  

```
enum OH_ContainerFormatType  
```

**描述：**

录制生成数据容器格式类型。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

| 枚举值 | 描述 |
| -------- | -------- |
| CFT_MPEG_4A | 音频格式m4a格式。 | 
| CFT_MPEG_4 | 视频格式mp4格式。 |
