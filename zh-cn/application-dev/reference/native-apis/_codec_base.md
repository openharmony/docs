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
| [native_avcodec_base.h](native__avcodec__base_8h.md) | 声明运行音视频编解码通用的结构体、字符常量、枚举。&nbsp; | 


### 结构体

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) | struct<br/>定义OH_AVCodec的Buffer描述信息。&nbsp; | 
| [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) | struct<br/>AVCodec所有的异步回调函数指针集合。注册一个该结构体实例给OH_AVCodec实例，并处理通过该回调报告&nbsp;的信息，以确保AVCodec正常运转。&nbsp; | 


### 类型定义

  | 名称 | 描述 | 
| -------- | -------- |
| **OHNativeWindow** | typedef&nbsp;struct&nbsp;NativeWindow | 
| **OH_AVCodec** | typedef&nbsp;struct&nbsp;OH_AVCodec | 
| [OH_AVCodecBufferFlags](#ohavcodecbufferflags) | typedef&nbsp;enum&nbsp;[OH_AVCodecBufferFlags](#ohavcodecbufferflags)<br/>枚举OH_AVCodec的Buffer标记的类别。&nbsp; | 
| [OH_AVCodecBufferAttr](#ohavcodecbufferattr) | typedef&nbsp;struct&nbsp;[OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md)<br/>定义OH_AVCodec的Buffer描述信息。&nbsp; | 
| [OH_AVCodecOnError](#ohavcodeconerror))&nbsp;(OH_AVCodec&nbsp;\*codec,&nbsp;int32_t&nbsp;errorCode,&nbsp;void&nbsp;\*userData) | typedef&nbsp;void(\*<br/>当OH_AVCodec实例运行发生错误时，该函数指针会被调用以报告具体错误信息。&nbsp; | 
| [OH_AVCodecOnStreamChanged](#ohavcodeconstreamchanged))&nbsp;(OH_AVCodec&nbsp;\*codec,&nbsp;OH_AVFormat&nbsp;\*format,&nbsp;void&nbsp;\*userData) | typedef&nbsp;void(\*<br/>当输出流发生变化时，该函数指针会被调用以报告新的流描述信息。&nbsp;需要注意的时，OH_AVFormat指针的生命周期仅维持在该函数指针被调用时上有效，禁止在调用结束后继续访问。&nbsp; | 
| [OH_AVCodecOnNeedInputData](#ohavcodeconneedinputdata))&nbsp;(OH_AVCodec&nbsp;\*codec,&nbsp;uint32_t&nbsp;index,&nbsp;OH_AVMemory&nbsp;\*data,&nbsp;void&nbsp;\*userData) | typedef&nbsp;void(\*<br/>当AVCodec运行过程中需要新的输入数据时，该函数指针会被调用，并携带一块可用的Buffer以供填入新的输入数据。&nbsp; | 
| [OH_AVCodecOnNewOutputData](#ohavcodeconnewoutputdata))&nbsp;(OH_AVCodec&nbsp;\*codec,&nbsp;uint32_t&nbsp;index,&nbsp;OH_AVMemory&nbsp;\*data,&nbsp;[OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md)&nbsp;\*attr,&nbsp;void&nbsp;\*userData) | typedef&nbsp;void(\*<br/>当AVCodec运行过程中产生了新的输出数据时，该函数指针会被调用，并携带一块包含新输出数据的Buffer，&nbsp;需要注意的是，OH_AVCodecBufferAttr指针的生命周期仅维持在该函数指针被调用时有效，禁止调用结束后继续访问。&nbsp; | 
| [OH_AVCodecAsyncCallback](#ohavcodecasynccallback) | typedef&nbsp;struct&nbsp;[OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md)<br/>AVCodec所有的异步回调函数指针集合。注册一个该结构体实例给OH_AVCodec实例，并处理通过该回调报告&nbsp;的信息，以确保AVCodec正常运转。&nbsp; | 
| [OH_MediaType](#ohmediatype) | typedef&nbsp;enum&nbsp;[OH_MediaType](#ohmediatype)<br/>媒体类型。&nbsp; | 
| [OH_AVCProfile](#ohavcprofile) | typedef&nbsp;enum&nbsp;[OH_AVCProfile](#ohavcprofile)<br/>AVC&nbsp;Profile枚举。&nbsp; | 
| [OH_AACProfile](#ohaacprofile) | typedef&nbsp;enum&nbsp;[OH_AACProfile](#ohaacprofile)<br/>AAC&nbsp;Profile枚举。&nbsp; | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_AVCodecBufferFlags](#ohavcodecbufferflags)&nbsp;{<br/>**AVCODEC_BUFFER_FLAGS_NONE**&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001473612293.xml#xref1210167552182348,link:zh-cn_topic_0000001473612293.xml#gga9222f5c24f4bcbfb91a5d552dd777439a7946993493046fb2076a9e4addce0b98](#gga9222f5c24f4bcbfb91a5d552dd777439a7946993493046fb2076a9e4addce0b98)&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001473612293.xml#xref147761475182348,link:zh-cn_topic_0000001473612293.xml#gga9222f5c24f4bcbfb91a5d552dd777439a4d85a25f4a9557f23e1144f9a137ddea](#gga9222f5c24f4bcbfb91a5d552dd777439a4d85a25f4a9557f23e1144f9a137ddea)&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001473612293.xml#xref89189050182348,link:zh-cn_topic_0000001473612293.xml#gga9222f5c24f4bcbfb91a5d552dd777439ac4c8a639feb36efde0d799d43fcfb59b](#gga9222f5c24f4bcbfb91a5d552dd777439ac4c8a639feb36efde0d799d43fcfb59b)&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;2,<br/>[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001473612293.xml#xref1599285555182348,link:zh-cn_topic_0000001473612293.xml#gga9222f5c24f4bcbfb91a5d552dd777439aba644475534bc79bfd3d43e1d28ab2f5](#gga9222f5c24f4bcbfb91a5d552dd777439aba644475534bc79bfd3d43e1d28ab2f5)&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;3<br/>} | 枚举OH_AVCodec的Buffer标记的类别。&nbsp; | 
| [OH_MediaType](#ohmediatype)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001473612293.xml#xref493726308182348,link:zh-cn_topic_0000001473612293.xml#gga28eb13d2f8f932345eeb3417d6e69e19ac0b3147adc27646ac965569adc38692e](#gga28eb13d2f8f932345eeb3417d6e69e19ac0b3147adc27646ac965569adc38692e)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001473612293.xml#xref25548070182348,link:zh-cn_topic_0000001473612293.xml#gga28eb13d2f8f932345eeb3417d6e69e19a0cbb91e5931fb03294c2d3bdbbc62dbd](#gga28eb13d2f8f932345eeb3417d6e69e19a0cbb91e5931fb03294c2d3bdbbc62dbd)&nbsp;=&nbsp;1&nbsp;} | 媒体类型。&nbsp; | 
| [OH_AVCProfile](#ohavcprofile)&nbsp;{&nbsp;**AVC_PROFILE_BASELINE**&nbsp;=&nbsp;0,&nbsp;**AVC_PROFILE_HIGH**&nbsp;=&nbsp;4,&nbsp;**AVC_PROFILE_MAIN**&nbsp;=&nbsp;8&nbsp;} | AVC&nbsp;Profile枚举。&nbsp; | 
| [OH_AACProfile](#ohaacprofile)&nbsp;{&nbsp;**AAC_PROFILE_LC**&nbsp;=&nbsp;0&nbsp;} | AAC&nbsp;Profile枚举。&nbsp; | 


### 变量

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_AVCodecBufferAttr::pts](#pts) | int64_t<br/>以微秒为单位表示的该Buffer的Presentation时间戳&nbsp; | 
| [OH_AVCodecBufferAttr::size](#size) | int32_t<br/>以字节为单位表示的该Buffer内所包含数据的大小&nbsp; | 
| [OH_AVCodecBufferAttr::offset](#offset) | int32_t<br/>有效数据在该Buffer内的起始偏移量&nbsp; | 
| [OH_AVCodecBufferAttr::flags](#flags) | uint32_t<br/>该Buffer具有的标记，也是多个[OH_AVCodecBufferFlags](#ohavcodecbufferflags)的组合&nbsp; | 
| **OH_AVCodecAsyncCallback::onError** | [OH_AVCodecOnError](#ohavcodeconerror) | 
| **OH_AVCodecAsyncCallback::onStreamChanged** | [OH_AVCodecOnStreamChanged](#ohavcodeconstreamchanged) | 
| **OH_AVCodecAsyncCallback::onNeedInputData** | [OH_AVCodecOnNeedInputData](#ohavcodeconneedinputdata) | 
| **OH_AVCodecAsyncCallback::onNeedOutputData** | [OH_AVCodecOnNewOutputData](#ohavcodeconnewoutputdata) | 
| [OH_AVCODEC_MIMETYPE_VIDEO_AVC](#ohavcodecmimetypevideoavc) | const&nbsp;char&nbsp;\*<br/>AVC视频编解码器的MIME类型。&nbsp; | 
| [OH_AVCODEC_MIMETYPE_AUDIO_AAC](#ohavcodecmimetypeaudioaac) | const&nbsp;char&nbsp;\*<br/>AAC音频编解码器的MIME类型。&nbsp; | 
| [OH_ED_KEY_TIME_STAMP](#ohedkeytimestamp) | const&nbsp;char&nbsp;\*<br/>提供统一的surface&nbsp;Buffer附属数据的字符描述符。&nbsp; | 
| [OH_ED_KEY_EOS](#ohedkeyeos) | const&nbsp;char&nbsp;\*<br/>surface附属数据中结束流的字符描述符，值类型为bool&nbsp; | 
| [OH_MD_KEY_TRACK_TYPE](#ohmdkeytracktype) | const&nbsp;char&nbsp;\*<br/>为媒体播放框架提供统一的字符描述符。&nbsp; | 
| [OH_MD_KEY_CODEC_MIME](#ohmdkeycodecmime) | const&nbsp;char&nbsp;\*<br/>mime类型的字符描述符，值类型为string&nbsp; | 
| [OH_MD_KEY_DURATION](#ohmdkeyduration) | const&nbsp;char&nbsp;\*<br/>duration的字符描述符，值类型为int64_t&nbsp; | 
| [OH_MD_KEY_BITRATE](#ohmdkeybitrate) | const&nbsp;char&nbsp;\*<br/>比特率的字符描述符，值类型为uint32_t&nbsp; | 
| [OH_MD_KEY_MAX_INPUT_SIZE](#ohmdkeymaxinputsize) | const&nbsp;char&nbsp;\*<br/>最大输入尺寸的字符描述符，值类型为uint32_t&nbsp; | 
| [OH_MD_KEY_WIDTH](#ohmdkeywidth) | const&nbsp;char&nbsp;\*<br/>视频宽度的字符描述符，值类型为uint32_t&nbsp; | 
| [OH_MD_KEY_HEIGHT](#ohmdkeyheight) | const&nbsp;char&nbsp;\*<br/>视频高度的字符描述符，值类型为uint32_t&nbsp; | 
| [OH_MD_KEY_PIXEL_FORMAT](#ohmdkeypixelformat) | const&nbsp;char&nbsp;\*<br/>视频像素格式的字符描述符，值类型为int32_t，具体见[OH_AVPixelFormat](_core.md#ohavpixelformat) | 
| [OH_MD_KEY_AUDIO_SAMPLE_FORMAT](#ohmdkeyaudiosampleformat) | const&nbsp;char&nbsp;\*<br/>音频采样格式的字符描述符，值类型为uint32_t&nbsp; | 
| [OH_MD_KEY_FRAME_RATE](#ohmdkeyframerate) | const&nbsp;char&nbsp;\*<br/>视频帧率的字符描述符，值类型为double&nbsp; | 
| [OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE](#ohmdkeyvideoencodebitratemode) | const&nbsp;char&nbsp;\*<br/>视频编码比特率模式的字符描述符，值类型为int32_t，具体见[OH_VideoEncodeBitrateMode](_video_encoder.md#ohvideoencodebitratemode) | 
| [OH_MD_KEY_PROFILE](#ohmdkeyprofile) | const&nbsp;char&nbsp;\*<br/>音视频编码能力的字符描述符，值类型为int32_t，具体见[OH_AVCProfile](#ohavcprofile)或[OH_AACProfile](#ohaacprofile) | 
| [OH_MD_KEY_AUD_CHANNEL_COUNT](#ohmdkeyaudchannelcount) | const&nbsp;char&nbsp;\*<br/>音频声道数的字符描述符，值类型为uint32_t&nbsp; | 
| [OH_MD_KEY_AUD_SAMPLE_RATE](#ohmdkeyaudsamplerate) | const&nbsp;char&nbsp;\*<br/>音频采样率的字符描述符，值类型为uint32_t&nbsp; | 
| [OH_MD_KEY_I_FRAME_INTERVAL](#ohmdkeyiframeinterval) | const&nbsp;char&nbsp;\*<br/>I帧间隔时长的字符描述符，值类型为int32_t，单位是毫秒&nbsp; | 
| [OH_MD_KEY_ROTATION](#ohmdkeyrotation) | const&nbsp;char&nbsp;\*<br/>surface旋转角度的字符描述符，值类型为int32_t，限于{0,&nbsp;90,&nbsp;180,&nbsp;270}，默认值为0&nbsp; | 


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
| codec | OH_AVCodec实例&nbsp; | 
| errorCode | 具体错误码&nbsp; | 
| userData | 用户特定数据&nbsp; | 


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
| codec | OH_AVCodec实例&nbsp; | 
| index | 新的可用的输入Buffer对应的索引&nbsp; | 
| data | 新的可用的输入Buffer&nbsp; | 
| userData | 用户特定数据&nbsp; | 


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
| codec | OH_AVCodec实例&nbsp; | 
| index | 新的输出Buffer对应的索引&nbsp; | 
| data | 包含新的输出数据的Buffer&nbsp; | 
| attr | 新的输出Buffer的描述信息，具体参考[OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) | 
| userData | specified&nbsp;data&nbsp; | 


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
| codec | OH_AVCodec实例&nbsp; | 
| format | 新的输出流描述信息&nbsp; | 
| userData | 用户特定数据&nbsp; | 


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
| AVCODEC_BUFFER_FLAGS_EOS&nbsp; | 表明该Buffer是End-of-Stream帧 | 
| AVCODEC_BUFFER_FLAGS_SYNC_FRAME&nbsp; | 表明该Buffer内包含关键帧 | 
| AVCODEC_BUFFER_FLAGS_INCOMPLETE_FRAME&nbsp; | 表明该Buffer内包含的数据仅仅为一帧的一部分 | 
| AVCODEC_BUFFER_FLAGS_CODEC_DATA&nbsp; | 表明该Buffer包含Codec-Specific-Data | 


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
| MEDIA_TYPE_AUD&nbsp; | 音频轨道 | 
| MEDIA_TYPE_VID&nbsp; | 视频轨道 | 


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
