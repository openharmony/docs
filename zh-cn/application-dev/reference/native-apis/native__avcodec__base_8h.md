# native_avcodec_base.h


## 概述

声明运行音视频编解码通用的结构体、字符常量、枚举。

**Since:**
9
**Version:**
1.0
**相关模块:**

[CodecBase](_codec_base.md)


## 汇总


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
| [OH_AVCodecBufferFlags](_codec_base.md#ohavcodecbufferflags) | typedef enum [OH_AVCodecBufferFlags](_codec_base.md#ohavcodecbufferflags)<br/>枚举OH_AVCodec的Buffer标记的类别。  | 
| [OH_AVCodecBufferAttr](_codec_base.md#ohavcodecbufferattr) | typedef struct [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md)<br/>定义OH_AVCodec的Buffer描述信息。  | 
| [OH_AVCodecOnError](_codec_base.md#ohavcodeconerror)) (OH_AVCodec \*codec, int32_t errorCode, void \*userData) | typedef void(\*<br/>当OH_AVCodec实例运行发生错误时，该函数指针会被调用以报告具体错误信息。  | 
| [OH_AVCodecOnStreamChanged](_codec_base.md#ohavcodeconstreamchanged)) (OH_AVCodec \*codec, OH_AVFormat \*format, void \*userData) | typedef void(\*<br/>当输出流发生变化时，该函数指针会被调用以报告新的流描述信息。 需要注意的时，OH_AVFormat指针的生命周期仅维持在该函数指针被调用时上有效，禁止在调用结束后继续访问。  | 
| [OH_AVCodecOnNeedInputData](_codec_base.md#ohavcodeconneedinputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, void \*userData) | typedef void(\*<br/>当AVCodec运行过程中需要新的输入数据时，该函数指针会被调用，并携带一块可用的Buffer以供填入新的输入数据。  | 
| [OH_AVCodecOnNewOutputData](_codec_base.md#ohavcodeconnewoutputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr, void \*userData) | typedef void(\*<br/>当AVCodec运行过程中产生了新的输出数据时，该函数指针会被调用，并携带一块包含新输出数据的Buffer， 需要注意的是，OH_AVCodecBufferAttr指针的生命周期仅维持在该函数指针被调用时有效，禁止调用结束后继续访问。  | 
| [OH_AVCodecAsyncCallback](_codec_base.md#ohavcodecasynccallback) | typedef struct [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md)<br/>AVCodec所有的异步回调函数指针集合。注册一个该结构体实例给OH_AVCodec实例，并处理通过该回调报告 的信息，以确保AVCodec正常运转。  | 
| [OH_MediaType](_codec_base.md#ohmediatype) | typedef enum [OH_MediaType](_codec_base.md#ohmediatype)<br/>媒体类型。  | 
| [OH_AVCProfile](_codec_base.md#ohavcprofile) | typedef enum [OH_AVCProfile](_codec_base.md#ohavcprofile)<br/>AVC Profile枚举。  | 
| [OH_AACProfile](_codec_base.md#ohaacprofile) | typedef enum [OH_AACProfile](_codec_base.md#ohaacprofile)<br/>AAC Profile枚举。  | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_AVCodecBufferFlags](_codec_base.md#ohavcodecbufferflags) {<br/>**AVCODEC_BUFFER_FLAGS_NONE** = 0, [AVCODEC_BUFFER_FLAGS_EOS](_codec_base.md#gga9222f5c24f4bcbfb91a5d552dd777439a7946993493046fb2076a9e4addce0b98) = 1 &lt;&lt; 0, [AVCODEC_BUFFER_FLAGS_SYNC_FRAME](_codec_base.md#gga9222f5c24f4bcbfb91a5d552dd777439a4d85a25f4a9557f23e1144f9a137ddea) = 1 &lt;&lt; 1, [AVCODEC_BUFFER_FLAGS_INCOMPLETE_FRAME](_codec_base.md#gga9222f5c24f4bcbfb91a5d552dd777439ac4c8a639feb36efde0d799d43fcfb59b) = 1 &lt;&lt; 2,<br/>[AVCODEC_BUFFER_FLAGS_CODEC_DATA](_codec_base.md#gga9222f5c24f4bcbfb91a5d552dd777439aba644475534bc79bfd3d43e1d28ab2f5) = 1 &lt;&lt; 3<br/>} | 枚举OH_AVCodec的Buffer标记的类别。  | 
| [OH_MediaType](_codec_base.md#ohmediatype) { [MEDIA_TYPE_AUD](_codec_base.md#gga28eb13d2f8f932345eeb3417d6e69e19ac0b3147adc27646ac965569adc38692e) = 0, [MEDIA_TYPE_VID](_codec_base.md#gga28eb13d2f8f932345eeb3417d6e69e19a0cbb91e5931fb03294c2d3bdbbc62dbd) = 1 } | 媒体类型。  | 
| [OH_AVCProfile](_codec_base.md#ohavcprofile) { **AVC_PROFILE_BASELINE** = 0, **AVC_PROFILE_HIGH** = 4, **AVC_PROFILE_MAIN** = 8 } | AVC Profile枚举。  | 
| [OH_AACProfile](_codec_base.md#ohaacprofile) { **AAC_PROFILE_LC** = 0 } | AAC Profile枚举。  | 


### 变量

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_AVCODEC_MIMETYPE_VIDEO_AVC](_codec_base.md#ohavcodecmimetypevideoavc) | const char \*<br/>AVC视频编解码器的MIME类型。  | 
| [OH_AVCODEC_MIMETYPE_AUDIO_AAC](_codec_base.md#ohavcodecmimetypeaudioaac) | const char \*<br/>AAC音频编解码器的MIME类型。  | 
| [OH_ED_KEY_TIME_STAMP](_codec_base.md#ohedkeytimestamp) | const char \*<br/>提供统一的surface Buffer附属数据的字符描述符。  | 
| [OH_ED_KEY_EOS](_codec_base.md#ohedkeyeos) | const char \* | 
| [OH_MD_KEY_TRACK_TYPE](_codec_base.md#ohmdkeytracktype) | const char \*<br/>为媒体播放框架提供统一的字符描述符。  | 
| [OH_MD_KEY_CODEC_MIME](_codec_base.md#ohmdkeycodecmime) | const char \* | 
| [OH_MD_KEY_DURATION](_codec_base.md#ohmdkeyduration) | const char \* | 
| [OH_MD_KEY_BITRATE](_codec_base.md#ohmdkeybitrate) | const char \* | 
| [OH_MD_KEY_MAX_INPUT_SIZE](_codec_base.md#ohmdkeymaxinputsize) | const char \* | 
| [OH_MD_KEY_WIDTH](_codec_base.md#ohmdkeywidth) | const char \* | 
| [OH_MD_KEY_HEIGHT](_codec_base.md#ohmdkeyheight) | const char \* | 
| [OH_MD_KEY_PIXEL_FORMAT](_codec_base.md#ohmdkeypixelformat) | const char \* | 
| [OH_MD_KEY_AUDIO_SAMPLE_FORMAT](_codec_base.md#ohmdkeyaudiosampleformat) | const char \* | 
| [OH_MD_KEY_FRAME_RATE](_codec_base.md#ohmdkeyframerate) | const char \* | 
| [OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE](_codec_base.md#ohmdkeyvideoencodebitratemode) | const char \* | 
| [OH_MD_KEY_PROFILE](_codec_base.md#ohmdkeyprofile) | const char \* | 
| [OH_MD_KEY_AUD_CHANNEL_COUNT](_codec_base.md#ohmdkeyaudchannelcount) | const char \* | 
| [OH_MD_KEY_AUD_SAMPLE_RATE](_codec_base.md#ohmdkeyaudsamplerate) | const char \* | 
| [OH_MD_KEY_I_FRAME_INTERVAL](_codec_base.md#ohmdkeyiframeinterval) | const char \* | 
| [OH_MD_KEY_ROTATION](_codec_base.md#ohmdkeyrotation) | const char \* | 
