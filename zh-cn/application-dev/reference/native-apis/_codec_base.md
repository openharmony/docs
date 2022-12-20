# CodecBase


## 概述

CodecBase模块提供运行音视频编解码通用的结构体、字符常量、枚举。

@syscap SystemCapability.Multimedia.Media.CodecBase

**Since:**
9
**Version:**
1.0

## 汇总


### 文件

  | 名称 | 描述 | 
| -------- | -------- |
| [native_avcodec_base.h](native__avcodec__base_8h.md) | 声明运行音视频编解码通用的结构体、字符常量、枚举。  | 


### 结构体

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) | struct<br/>定义OH_AVCodec的Buffer描述信息。  | 
| [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) | struct<br/>AVCodec所有的异步回调函数指针集合。注册一个该结构体实例给OH_AVCodec实例，并处理通过该回调报告 的信息，以确保AVCodec正常运转。  | 


### 类型定义

  | 名称 | 描述 | 
| -------- | -------- |
| **OHNativeWindow** | typedef struct NativeWindow | 
| **OH_AVCodec** | typedef struct OH_AVCodec | 
| [OH_AVCodecBufferFlags](#ohavcodecbufferflags) | typedef enum [OH_AVCodecBufferFlags](#ohavcodecbufferflags)<br/>枚举OH_AVCodec的Buffer标记的类别。  | 
| [OH_AVCodecBufferAttr](#ohavcodecbufferattr) | typedef struct [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md)<br/>定义OH_AVCodec的Buffer描述信息。  | 
| [OH_AVCodecOnError](#ohavcodeconerror)) (OH_AVCodec \*codec, int32_t errorCode, void \*userData) | typedef void(\*<br/>当OH_AVCodec实例运行发生错误时，该函数指针会被调用以报告具体错误信息。  | 
| [OH_AVCodecOnStreamChanged](#ohavcodeconstreamchanged)) (OH_AVCodec \*codec, OH_AVFormat \*format, void \*userData) | typedef void(\*<br/>当输出流发生变化时，该函数指针会被调用以报告新的流描述信息。 需要注意的时，OH_AVFormat指针的生命周期仅维持在该函数指针被调用时上有效，禁止在调用结束后继续访问。  | 
| [OH_AVCodecOnNeedInputData](#ohavcodeconneedinputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, void \*userData) | typedef void(\*<br/>当AVCodec运行过程中需要新的输入数据时，该函数指针会被调用，并携带一块可用的Buffer以供填入新的输入数据。  | 
| [OH_AVCodecOnNewOutputData](#ohavcodeconnewoutputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr, void \*userData) | typedef void(\*<br/>当AVCodec运行过程中产生了新的输出数据时，该函数指针会被调用，并携带一块包含新输出数据的Buffer， 需要注意的是，OH_AVCodecBufferAttr指针的生命周期仅维持在该函数指针被调用时有效，禁止调用结束后继续访问。  | 
| [OH_AVCodecAsyncCallback](#ohavcodecasynccallback) | typedef struct [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md)<br/>AVCodec所有的异步回调函数指针集合。注册一个该结构体实例给OH_AVCodec实例，并处理通过该回调报告 的信息，以确保AVCodec正常运转。  | 
| [OH_MediaType](#ohmediatype) | typedef enum [OH_MediaType](#ohmediatype)<br/>媒体类型。  | 
| [OH_AVCProfile](#ohavcprofile) | typedef enum [OH_AVCProfile](#ohavcprofile)<br/>AVC Profile枚举。  | 
| [OH_AACProfile](#ohaacprofile) | typedef enum [OH_AACProfile](#ohaacprofile)<br/>AAC Profile枚举。  | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_AVCodecBufferFlags](#ohavcodecbufferflags) {<br/>**AVCODEC_BUFFER_FLAGS_NONE** = 0, **AVCODEC_BUFFER_FLAGS_EOS** = 1 &lt;&lt; 0, **AVCODEC_BUFFER_FLAGS_SYNC_FRAME** = 1 &lt;&lt; 1, **AVCODEC_BUFFER_FLAGS_INCOMPLETE_FRAME** = 1 &lt;&lt; 2, **AVCODEC_BUFFER_FLAGS_CODEC_DATA**= 1 &lt;&lt; 3<br/>} | 枚举OH_AVCodec的Buffer标记的类别。  |
| [OH_MediaType](#ohmediatype) { **MEDIA_TYPE_AUD** = 0, **MEDIA_TYPE_VID** = 1 } | 媒体类型。  |
| [OH_AVCProfile](#ohavcprofile) { **AVC_PROFILE_BASELINE** = 0, **AVC_PROFILE_HIGH** = 4, **AVC_PROFILE_MAIN** = 8 } | AVC Profile枚举。  | 
| [OH_AACProfile](#ohaacprofile) { **AAC_PROFILE_LC** = 0 } | AAC Profile枚举。  | 


### 变量

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_AVCodecBufferAttr::pts](#pts) | int64_t<br/>以微秒为单位表示的该Buffer的Presentation时间戳  | 
| [OH_AVCodecBufferAttr::size](#size) | int32_t<br/>以字节为单位表示的该Buffer内所包含数据的大小  | 
| [OH_AVCodecBufferAttr::offset](#offset) | int32_t<br/>有效数据在该Buffer内的起始偏移量  | 
| [OH_AVCodecBufferAttr::flags](#flags) | uint32_t<br/>该Buffer具有的标记，也是多个[OH_AVCodecBufferFlags](#ohavcodecbufferflags)的组合  | 
| **OH_AVCodecAsyncCallback::onError** | [OH_AVCodecOnError](#ohavcodeconerror) | 
| **OH_AVCodecAsyncCallback::onStreamChanged** | [OH_AVCodecOnStreamChanged](#ohavcodeconstreamchanged) | 
| **OH_AVCodecAsyncCallback::onNeedInputData** | [OH_AVCodecOnNeedInputData](#ohavcodeconneedinputdata) | 
| **OH_AVCodecAsyncCallback::onNeedOutputData** | [OH_AVCodecOnNewOutputData](#ohavcodeconnewoutputdata) | 
| [OH_AVCODEC_MIMETYPE_VIDEO_AVC](#ohavcodecmimetypevideoavc) | const char \*<br/>AVC视频编解码器的MIME类型。  | 
| [OH_AVCODEC_MIMETYPE_AUDIO_AAC](#ohavcodecmimetypeaudioaac) | const char \*<br/>AAC音频编解码器的MIME类型。  | 
| [OH_ED_KEY_TIME_STAMP](#ohedkeytimestamp) | const char \*<br/>提供统一的surface Buffer附属数据的字符描述符。  | 
| [OH_ED_KEY_EOS](#ohedkeyeos) | const char \*<br/>surface附属数据中结束流的字符描述符，值类型为bool  | 
| [OH_MD_KEY_TRACK_TYPE](#ohmdkeytracktype) | const char \*<br/>为媒体播放框架提供统一的字符描述符。  | 
| [OH_MD_KEY_CODEC_MIME](#ohmdkeycodecmime) | const char \*<br/>mime类型的字符描述符，值类型为string  | 
| [OH_MD_KEY_DURATION](#ohmdkeyduration) | const char \*<br/>duration的字符描述符，值类型为int64_t  | 
| [OH_MD_KEY_BITRATE](#ohmdkeybitrate) | const char \*<br/>比特率的字符描述符，值类型为uint32_t  | 
| [OH_MD_KEY_MAX_INPUT_SIZE](#ohmdkeymaxinputsize) | const char \*<br/>最大输入尺寸的字符描述符，值类型为uint32_t  | 
| [OH_MD_KEY_WIDTH](#ohmdkeywidth) | const char \*<br/>视频宽度的字符描述符，值类型为uint32_t  | 
| [OH_MD_KEY_HEIGHT](#ohmdkeyheight) | const char \*<br/>视频高度的字符描述符，值类型为uint32_t  | 
| [OH_MD_KEY_PIXEL_FORMAT](#ohmdkeypixelformat) | const char \*<br/>视频像素格式的字符描述符，值类型为int32_t，具体见[OH_AVPixelFormat](_core.md#ohavpixelformat) | 
| [OH_MD_KEY_AUDIO_SAMPLE_FORMAT](#ohmdkeyaudiosampleformat) | const char \*<br/>音频采样格式的字符描述符，值类型为uint32_t  | 
| [OH_MD_KEY_FRAME_RATE](#ohmdkeyframerate) | const char \*<br/>视频帧率的字符描述符，值类型为double  | 
| [OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE](#ohmdkeyvideoencodebitratemode) | const char \*<br/>视频编码比特率模式的字符描述符，值类型为int32_t，具体见[OH_VideoEncodeBitrateMode](_video_encoder.md#ohvideoencodebitratemode) | 
| [OH_MD_KEY_PROFILE](#ohmdkeyprofile) | const char \*<br/>音视频编码能力的字符描述符，值类型为int32_t，具体见[OH_AVCProfile](#ohavcprofile)或[OH_AACProfile](#ohaacprofile) | 
| [OH_MD_KEY_AUD_CHANNEL_COUNT](#ohmdkeyaudchannelcount) | const char \*<br/>音频声道数的字符描述符，值类型为uint32_t  | 
| [OH_MD_KEY_AUD_SAMPLE_RATE](#ohmdkeyaudsamplerate) | const char \*<br/>音频采样率的字符描述符，值类型为uint32_t  | 
| [OH_MD_KEY_I_FRAME_INTERVAL](#ohmdkeyiframeinterval) | const char \*<br/>I帧间隔时长的字符描述符，值类型为int32_t，单位是毫秒  | 
| [OH_MD_KEY_ROTATION](#ohmdkeyrotation) | const char \*<br/>surface旋转角度的字符描述符，值类型为int32_t，限于{0, 90, 180, 270}，默认值为0  | 


## 类型定义说明


### OH_AACProfile

  
```
typedef enum OH_AACProfileOH_AACProfile
```
**描述:**
AAC Profile枚举。

@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCodecAsyncCallback

  
```
typedef struct OH_AVCodecAsyncCallbackOH_AVCodecAsyncCallback
```
**描述:**
AVCodec所有的异步回调函数指针集合。注册一个该结构体实例给OH_AVCodec实例，并处理通过该回调报告 的信息，以确保AVCodec正常运转。

@syscap SystemCapability.Multimedia.Media.CodecBase

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| onError | 监听AVCodec运行错误，参考[OH_AVCodecOnError](#ohavcodeconerror) | 
| onStreamChanged | 监听编解码流信息，参考[OH_AVCodecOnStreamChanged](#ohavcodeconstreamchanged) | 
| onNeedInputData | 监听编解码需要输入数据，参考[OH_AVCodecOnNeedInputData](#ohavcodeconneedinputdata) | 
| onNeedInputData | 监听编解码产生输出数据，参考[OH_AVCodecOnNewOutputData](#ohavcodeconnewoutputdata) | 


### OH_AVCodecBufferAttr

  
```
typedef struct OH_AVCodecBufferAttrOH_AVCodecBufferAttr
```
**描述:**
定义OH_AVCodec的Buffer描述信息。

@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCodecBufferFlags

  
```
typedef enum OH_AVCodecBufferFlagsOH_AVCodecBufferFlags
```
**描述:**
枚举OH_AVCodec的Buffer标记的类别。

@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCodecOnError

  
```
typedef void(* OH_AVCodecOnError) (OH_AVCodec *codec, int32_t errorCode, void *userData)
```
**描述:**
当OH_AVCodec实例运行发生错误时，该函数指针会被调用以报告具体错误信息。

@syscap SystemCapability.Multimedia.Media.CodecBase

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | OH_AVCodec实例  | 
| errorCode | 具体错误码  | 
| userData | 用户特定数据  | 


### OH_AVCodecOnNeedInputData

  
```
typedef void(* OH_AVCodecOnNeedInputData) (OH_AVCodec *codec, uint32_t index, OH_AVMemory *data, void *userData)
```
**描述:**
当AVCodec运行过程中需要新的输入数据时，该函数指针会被调用，并携带一块可用的Buffer以供填入新的输入数据。

@syscap SystemCapability.Multimedia.Media.CodecBase

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | OH_AVCodec实例  | 
| index | 新的可用的输入Buffer对应的索引  | 
| data | 新的可用的输入Buffer  | 
| userData | 用户特定数据  | 


### OH_AVCodecOnNewOutputData

  
```
typedef void(* OH_AVCodecOnNewOutputData) (OH_AVCodec *codec, uint32_t index, OH_AVMemory *data, OH_AVCodecBufferAttr *attr, void *userData)
```
**描述:**
当AVCodec运行过程中产生了新的输出数据时，该函数指针会被调用，并携带一块包含新输出数据的Buffer， 需要注意的是，OH_AVCodecBufferAttr指针的生命周期仅维持在该函数指针被调用时有效，禁止调用结束后继续访问。

@syscap SystemCapability.Multimedia.Media.CodecBase

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | OH_AVCodec实例  | 
| index | 新的输出Buffer对应的索引  | 
| data | 包含新的输出数据的Buffer  | 
| attr | 新的输出Buffer的描述信息，具体参考[OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) | 
| userData | specified data  | 


### OH_AVCodecOnStreamChanged

  
```
typedef void(* OH_AVCodecOnStreamChanged) (OH_AVCodec *codec, OH_AVFormat *format, void *userData)
```
**描述:**
当输出流发生变化时，该函数指针会被调用以报告新的流描述信息。 需要注意的时，OH_AVFormat指针的生命周期仅维持在该函数指针被调用时上有效，禁止在调用结束后继续访问。

@syscap SystemCapability.Multimedia.Media.CodecBase

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | OH_AVCodec实例  | 
| format | 新的输出流描述信息  | 
| userData | 用户特定数据  | 


### OH_AVCProfile

  
```
typedef enum OH_AVCProfileOH_AVCProfile
```
**描述:**
AVC Profile枚举。

@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MediaType

  
```
typedef enum OH_MediaTypeOH_MediaType
```
**描述:**
媒体类型。

@syscap SystemCapability.Multimedia.Media.CodecBase


## 枚举类型说明


### OH_AACProfile

  
```
enum OH_AACProfile
```
**描述:**
AAC Profile枚举。

@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCodecBufferFlags

  
```
enum OH_AVCodecBufferFlags
```
**描述:**
枚举OH_AVCodec的Buffer标记的类别。

@syscap SystemCapability.Multimedia.Media.CodecBase

  | 枚举值 | 描述 | 
| -------- | -------- |
| AVCODEC_BUFFER_FLAGS_EOS  | 表明该Buffer是End-of-Stream帧 | 
| AVCODEC_BUFFER_FLAGS_SYNC_FRAME  | 表明该Buffer内包含关键帧 | 
| AVCODEC_BUFFER_FLAGS_INCOMPLETE_FRAME  | 表明该Buffer内包含的数据仅仅为一帧的一部分 | 
| AVCODEC_BUFFER_FLAGS_CODEC_DATA  | 表明该Buffer包含Codec-Specific-Data | 


### OH_AVCProfile

  
```
enum OH_AVCProfile
```
**描述:**
AVC Profile枚举。

@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MediaType

  
```
enum OH_MediaType
```
**描述:**
媒体类型。

@syscap SystemCapability.Multimedia.Media.CodecBase

  | 枚举值 | 描述 | 
| -------- | -------- |
| MEDIA_TYPE_AUD  | 音频轨道 | 
| MEDIA_TYPE_VID  | 视频轨道 | 


## 变量说明


### flags

  
```
uint32_t OH_AVCodecBufferAttr::flags
```
**描述:**
该Buffer具有的标记，也是多个[OH_AVCodecBufferFlags](#ohavcodecbufferflags)的组合


### offset

  
```
int32_t OH_AVCodecBufferAttr::offset
```
**描述:**
有效数据在该Buffer内的起始偏移量


### OH_AVCODEC_MIMETYPE_AUDIO_AAC

  
```
const char* OH_AVCODEC_MIMETYPE_AUDIO_AAC
```
**描述:**
AAC音频编解码器的MIME类型。

@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCODEC_MIMETYPE_VIDEO_AVC

  
```
const char* OH_AVCODEC_MIMETYPE_VIDEO_AVC
```
**描述:**
AVC视频编解码器的MIME类型。

@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_ED_KEY_EOS

  
```
const char* OH_ED_KEY_EOS
```
**描述:**
surface附属数据中结束流的字符描述符，值类型为bool


### OH_ED_KEY_TIME_STAMP

  
```
const char* OH_ED_KEY_TIME_STAMP
```
**描述:**
提供统一的surface Buffer附属数据的字符描述符。

@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MD_KEY_AUD_CHANNEL_COUNT

  
```
const char* OH_MD_KEY_AUD_CHANNEL_COUNT
```
**描述:**
音频声道数的字符描述符，值类型为uint32_t


### OH_MD_KEY_AUD_SAMPLE_RATE

  
```
const char* OH_MD_KEY_AUD_SAMPLE_RATE
```
**描述:**
音频采样率的字符描述符，值类型为uint32_t


### OH_MD_KEY_AUDIO_SAMPLE_FORMAT

  
```
const char* OH_MD_KEY_AUDIO_SAMPLE_FORMAT
```
**描述:**
音频采样格式的字符描述符，值类型为uint32_t


### OH_MD_KEY_BITRATE

  
```
const char* OH_MD_KEY_BITRATE
```
**描述:**
比特率的字符描述符，值类型为uint32_t


### OH_MD_KEY_CODEC_MIME

  
```
const char* OH_MD_KEY_CODEC_MIME
```
**描述:**
mime类型的字符描述符，值类型为string


### OH_MD_KEY_DURATION

  
```
const char* OH_MD_KEY_DURATION
```
**描述:**
duration的字符描述符，值类型为int64_t


### OH_MD_KEY_FRAME_RATE

  
```
const char* OH_MD_KEY_FRAME_RATE
```
**描述:**
视频帧率的字符描述符，值类型为double


### OH_MD_KEY_HEIGHT

  
```
const char* OH_MD_KEY_HEIGHT
```
**描述:**
视频高度的字符描述符，值类型为uint32_t


### OH_MD_KEY_I_FRAME_INTERVAL

  
```
const char* OH_MD_KEY_I_FRAME_INTERVAL
```
**描述:**
I帧间隔时长的字符描述符，值类型为int32_t，单位是毫秒


### OH_MD_KEY_MAX_INPUT_SIZE

  
```
const char* OH_MD_KEY_MAX_INPUT_SIZE
```
**描述:**
最大输入尺寸的字符描述符，值类型为uint32_t


### OH_MD_KEY_PIXEL_FORMAT

  
```
const char* OH_MD_KEY_PIXEL_FORMAT
```
**描述:**
视频像素格式的字符描述符，值类型为int32_t，具体见[OH_AVPixelFormat](_core.md#ohavpixelformat)


### OH_MD_KEY_PROFILE

  
```
const char* OH_MD_KEY_PROFILE
```
**描述:**
音视频编码能力的字符描述符，值类型为int32_t，具体见[OH_AVCProfile](#ohavcprofile)或[OH_AACProfile](#ohaacprofile)


### OH_MD_KEY_ROTATION

  
```
const char* OH_MD_KEY_ROTATION
```
**描述:**
surface旋转角度的字符描述符，值类型为int32_t，限于{0, 90, 180, 270}，默认值为0


### OH_MD_KEY_TRACK_TYPE

  
```
const char* OH_MD_KEY_TRACK_TYPE
```
**描述:**
为媒体播放框架提供统一的字符描述符。

@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE

  
```
const char* OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE
```
**描述:**
视频编码比特率模式的字符描述符，值类型为int32_t，具体见[OH_VideoEncodeBitrateMode](_video_encoder.md#ohvideoencodebitratemode)


### OH_MD_KEY_WIDTH

  
```
const char* OH_MD_KEY_WIDTH
```
**描述:**
视频宽度的字符描述符，值类型为uint32_t


### pts

  
```
int64_t OH_AVCodecBufferAttr::pts
```
**描述:**
以微秒为单位表示的该Buffer的Presentation时间戳


### size

  
```
int32_t OH_AVCodecBufferAttr::size
```
**描述:**
以字节为单位表示的该Buffer内所包含数据的大小
