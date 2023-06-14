# CodecBase


## 概述

CodecBase模块提供运行音视频编解码通用的结构体、字符常量、枚举。该模块在部分设备上可能不支持，可以通过[CanIUse](../syscap.md)接口确认。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**起始版本：**

9


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_avcodec_base.h](native__avcodec__base_8h.md) | 声明运行音视频编解码通用的结构体、字符常量、枚举。<br>引用文件：<multimedia/player_framework/native_avcodec_base.h>  |


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) | 定义OH_AVCodec的缓冲区描述信息。 | 
| [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) | OH_AVCodec中所有异步回调函数指针的集合。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVCodecBufferFlags](#oh_avcodecbufferflags) | 枚举OH_AVCodec缓冲区标记的类别。 | 
| [OH_AVOutputFormat](#oh_avoutputformat) | 枚举封装器的输出文件格式。 | 
| [OH_AVCodecBufferAttr](#oh_avcodecbufferattr) | 定义OH_AVCodec的缓冲区描述信息。 | 
| (\*[OH_AVCodecOnError](#oh_avcodeconerror)) (OH_AVCodec \*codec, int32_t errorCode, void \*userData) | 当OH_AVCodec实例运行出错时，会调用来上报具体的错误信息的函数指针。 | 
| (\*[OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged)) (OH_AVCodec \*codec, OH_AVFormat \*format, void \*userData) | 当输出流发生变化时，将调用此函数指针报告新的流描述信息。 | 
| (\*[OH_AVCodecOnNeedInputData](#oh_avcodeconneedinputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, void \*userData) | 当OH_AVCodec在运行过程中需要新的输入数据时，将调用此函数指针，并携带可用的缓冲区来填充新的输入数据。 | 
| (\*[OH_AVCodecOnNewOutputData](#oh_avcodeconnewoutputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr, void \*userData) | 当OH_AVCodec运行过程中生成新的输出数据时，将调用此函数指针，并携带包含新输出数据的缓冲区。 | 
| [OH_AVCodecAsyncCallback](#oh_avcodecasynccallback) | OH_AVCodec中所有异步回调函数指针的集合。 | 
| [OH_MediaType](#oh_mediatype) | 媒体类型。 | 
| [OH_AVCProfile](#oh_avcprofile) | AVC Profile枚举。 | 
| [OH_HEVCProfile](#oh_hevcprofile) | HEVC Profile枚举。 | 
| [OH_AACProfile](#oh_aacprofile) | AAC Profile枚举。 | 
| [OH_AVSeekMode](#oh_avseekmode) | 跳转模式。 | 
| [OH_ColorPrimary](#oh_colorprimary) | 原色。 | 
| [OH_TransferCharacteristic](#oh_transfercharacteristic) | 转移特性。 | 
| [OH_MatrixCoefficient](#oh_matrixcoefficient) | 矩阵系数。 | 
| [OH_BitsPerSample](#oh_bitspersample) | 枚举每个编码样本的音频位数。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVCodecBufferFlags](#oh_avcodecbufferflags) {<br/>**AVCODEC_BUFFER_FLAGS_NONE** = 0, **AVCODEC_BUFFER_FLAGS_EOS** = 1 &lt;&lt; 0, **AVCODEC_BUFFER_FLAGS_SYNC_FRAME** = 1 &lt;&lt; 1, **AVCODEC_BUFFER_FLAGS_INCOMPLETE_FRAME** = 1 &lt;&lt; 2,<br/>**AVCODEC_BUFFER_FLAGS_CODEC_DATA** = 1 &lt;&lt; 3<br/>} | 枚举OH_AVCodec缓冲区标记的类别。 | 
| [OH_AVOutputFormat](#oh_avoutputformat) { **AV_OUTPUT_FORMAT_DEFAULT** = 0, **AV_OUTPUT_FORMAT_MPEG_4** = 2, **AV_OUTPUT_FORMAT_M4A** = 6 } | 枚举封装器的输出文件格式。 | 
| [OH_MediaType](#oh_mediatype) { **MEDIA_TYPE_AUD** = 0, **MEDIA_TYPE_VID** = 1 } | 媒体类型。 | 
| [OH_AVCProfile](#oh_avcprofile) { **AVC_PROFILE_BASELINE** = 0, **AVC_PROFILE_HIGH** = 4, **AVC_PROFILE_MAIN** = 8 } | AVC Profile枚举。 | 
| [OH_HEVCProfile](#oh_hevcprofile) {<br/>**HEVC_PROFILE_MAIN** = 0, **HEVC_PROFILE_MAIN_10** = 1, **HEVC_PROFILE_MAIN_STILL** = 2, **HEVC_PROFILE_MAIN_10_HDR10** = 3,<br/>**HEVC_PROFILE_MAIN_10_HDR10_PLUS** = 4<br/>} | HEVC Profile枚举。 | 
| [OH_AACProfile](#oh_aacprofile) { **AAC_PROFILE_LC** = 0 } | AAC Profile枚举。 | 
| [OH_AVSeekMode](#oh_avseekmode) { **SEEK_MODE_NEXT_SYNC** = 0, **SEEK_MODE_PREVIOUS_SYNC**, **SEEK_MODE_CLOSEST_SYNC** } | 跳转模式。 | 
| [OH_ColorPrimary](#oh_colorprimary) {<br/>**COLOR_PRIMARY_BT709** = 1, **COLOR_PRIMARY_UNSPECIFIED** = 2, **COLOR_PRIMARY_BT470_M** = 4, **COLOR_PRIMARY_BT601_625** = 5,<br/>**COLOR_PRIMARY_BT601_525** = 6, **COLOR_PRIMARY_SMPTE_ST240** = 7, **COLOR_PRIMARY_GENERIC_FILM** = 8, **COLOR_PRIMARY_BT2020** = 9,<br/>**COLOR_PRIMARY_SMPTE_ST428** = 10, **COLOR_PRIMARY_P3DCI** = 11, **COLOR_PRIMARY_P3D65** = 12<br/>} | 原色。 | 
| [OH_TransferCharacteristic](#oh_transfercharacteristic) {<br/>**TRANSFER_CHARACTERISTIC_BT709** = 1, **TRANSFER_CHARACTERISTIC_UNSPECIFIED** = 2, **TRANSFER_CHARACTERISTIC_GAMMA_2_2** = 4, **TRANSFER_CHARACTERISTIC_GAMMA_2_8** = 5,<br/>**TRANSFER_CHARACTERISTIC_BT601** = 6, **TRANSFER_CHARACTERISTIC_SMPTE_ST240** = 7, **TRANSFER_CHARACTERISTIC_LINEAR** = 8, **TRANSFER_CHARACTERISTIC_LOG** = 9,<br/>**TRANSFER_CHARACTERISTIC_LOG_SQRT** = 10, **TRANSFER_CHARACTERISTIC_IEC_61966_2_4** = 11, **TRANSFER_CHARACTERISTIC_BT1361** = 12, **TRANSFER_CHARACTERISTIC_IEC_61966_2_1** = 13,<br/>**TRANSFER_CHARACTERISTIC_BT2020_10BIT** = 14, **TRANSFER_CHARACTERISTIC_BT2020_12BIT** = 15, **TRANSFER_CHARACTERISTIC_PQ** = 16, **TRANSFER_CHARACTERISTIC_SMPTE_ST428** = 17,<br/>**TRANSFER_CHARACTERISTIC_HLG** = 18<br/>} | 转移特性。 | 
| [OH_MatrixCoefficient](#oh_matrixcoefficient) {<br/>**MATRIX_COEFFICIENT_IDENTITY** = 0, **MATRIX_COEFFICIENT_BT709** = 1, **MATRIX_COEFFICIENT_UNSPECIFIED** = 2, **MATRIX_COEFFICIENT_FCC** = 4,<br/>**MATRIX_COEFFICIENT_BT601_625** = 5, **MATRIX_COEFFICIENT_BT601_525** = 6, **MATRIX_COEFFICIENT_SMPTE_ST240** = 7, **MATRIX_COEFFICIENT_YCGCO** = 8,<br/>**MATRIX_COEFFICIENT_BT2020_NCL** = 9, **MATRIX_COEFFICIENT_BT2020_CL** = 10, **MATRIX_COEFFICIENT_SMPTE_ST2085** = 11, **MATRIX_COEFFICIENT_CHROMATICITY_NCL** = 12,<br/>**MATRIX_COEFFICIENT_CHROMATICITY_CL** = 13, **MATRIX_COEFFICIENT_ICTCP** = 14<br/>} | 矩阵系数。 | 
| [OH_BitsPerSample](#oh_bitspersample) {<br/>**SAMPLE_U8** = 0, **SAMPLE_S16LE** = 1, **SAMPLE_S24LE** = 2, **SAMPLE_S32LE** = 3,<br/>**SAMPLE_F32LE** = 4, **SAMPLE_U8P** = 5, **SAMPLE_S16P** = 6, **SAMPLE_S24P** = 7,<br/>**SAMPLE_S32P** = 8, **SAMPLE_F32P** = 9, **INVALID_WIDTH** = -1<br/>} | 枚举每个编码样本的音频位数。 | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVCodecBufferAttr::pts](_o_h___a_v_codec_buffer_attr.md#pts) | 此缓冲区的显示时间戳（以微秒为单位） | 
| [OH_AVCodecBufferAttr::size](_o_h___a_v_codec_buffer_attr.md#size) | 缓冲区中包含的数据的大小（以字节为单位） | 
| [OH_AVCodecBufferAttr::offset](_o_h___a_v_codec_buffer_attr.md#offset) | 此缓冲区中有效数据的起始偏移量 | 
| [OH_AVCodecBufferAttr::flags](_o_h___a_v_codec_buffer_attr.md#flags) | 此缓冲区具有的标志，也是多个[OH_AVCodecBufferFlags](#oh_avcodecbufferflags)的组合。 | 
| [OH_AVCodecAsyncCallback::onError](_o_h___a_v_codec_async_callback.md#onerror) | 监控编解码器操作错误，请参见[OH_AVCodecOnError](#oh_avcodeconerror) | 
| [OH_AVCodecAsyncCallback::onStreamChanged](_o_h___a_v_codec_async_callback.md#onstreamchanged) | 监控编解码器流变化，请参见[OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged) | 
| [OH_AVCodecAsyncCallback::onNeedInputData](_o_h___a_v_codec_async_callback.md#onneedinputdata) | 监控编解码器需要输入数据，请参见[OH_AVCodecOnNeedInputData](#oh_avcodeconneedinputdata) | 
| [OH_AVCodecAsyncCallback::onNeedOutputData](_o_h___a_v_codec_async_callback.md#onneedinputdata) | 监控编解码器已生成输出数据，请参见[OH_AVCodecOnNewOutputData](#oh_avcodeconnewoutputdata) | 
| \*[OH_AVCODEC_MIMETYPE_VIDEO_AVC](#oh_avcodec_mimetype_video_avc) | AVC视频编解码器的MIME类型。 | 
| \*[OH_AVCODEC_MIMETYPE_AUDIO_AAC](#oh_avcodec_mimetype_audio_avc) | AAC音频编解码器的MIME类型。 | 
| \*[OH_AVCODEC_MIMETYPE_VIDEO_MPEG4](#oh_avcodec_mimetype_video_mpeg4) | MPEG4视频编解码器的MIME类型。 | 
| \*OH_AVCODEC_MIMETYPE_VIDEO_HEVC | HEVC视频编解码器的MIME类型。 | 
| \*OH_AVCODEC_MIMETYPE_AUDIO_MPEG | MPEG音频编解码器的MIME类型。 | 
| \*OH_AVCODEC_MIMETYPE_IMAGE_JPG | JPG图片编解码器的MIME类型。 | 
| \*OH_AVCODEC_MIMETYPE_IMAGE_PNG | PNG图片编解码器的MIME类型。 | 
| \*OH_AVCODEC_MIMETYPE_IMAGE_BMP | BMP图片编解码器的MIME类型。 | 
| \*OH_AVCODEC_MIMETYPE_AUDIO_FLAC | FLAC音频编解码器的MIME类型。 | 
| \*OH_AVCODEC_MIMETYPE_AUDIO_VORBIS | VORBIS音频编解码器的MIME类型。 | 
| \*[OH_ED_KEY_TIME_STAMP](#oh_ed_key_time_stamp) | 提供统一的surface Buffer附属数据的字符描述符。 | 
| \*OH_ED_KEY_EOS | surface附属数据中结束流的字符描述符，值类型为bool | 
| \*[OH_MD_KEY_TRACK_TYPE](#oh_md_key_track_type) | 为媒体播放框架提供统一的字符描述符。 | 
| \*OH_MD_KEY_CODEC_MIME | mime类型的字符描述符，值类型为string | 
| \*OH_MD_KEY_DURATION | duration的字符描述符，值类型为int64_t | 
| \*OH_MD_KEY_BITRATE | 比特率的字符描述符，值类型为uint32_t | 
| \*OH_MD_KEY_MAX_INPUT_SIZE | 最大输入尺寸的字符描述符，值类型为uint32_t | 
| \*OH_MD_KEY_WIDTH | 视频宽度的字符描述符，值类型为uint32_t | 
| \*OH_MD_KEY_HEIGHT | 视频高度的字符描述符，值类型为uint32_t | 
| \*OH_MD_KEY_PIXEL_FORMAT | 视频像素格式的字符描述符，值类型为int32_t，具体见[OH_AVPixelFormat](_core.md#oh_avpixelformat) | 
| \*OH_MD_KEY_RANGE_FLAG |  | 
| \*OH_MD_KEY_COLOR_PRIMARIES |  | 
| \*OH_MD_KEY_TRANSFER_CHARACTERISTICS |  | 
| \*OH_MD_KEY_MATRIX_COEFFICIENTS |  | 
| \*OH_MD_KEY_AUDIO_SAMPLE_FORMAT | 音频采样格式的字符描述符，值类型为uint32_t | 
| \*OH_MD_KEY_FRAME_RATE | 视频帧率的字符描述符，值类型为double | 
| \*OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE | 视频编码比特率模式的字符描述符，值类型为int32_t，具体见[OH_VideoEncodeBitrateMode](_video_encoder.md#oh_videoencodebitratemode) | 
| \*OH_MD_KEY_PROFILE | 音视频编码能力的字符描述符，值类型为int32_t，具体见[OH_AVCProfile](#oh_avcprofile)或[OH_AACProfile](#oh_aacprofile) | 
| \*OH_MD_KEY_AUD_CHANNEL_COUNT | 音频声道数的字符描述符，值类型为uint32_t | 
| \*OH_MD_KEY_AUD_SAMPLE_RATE | 音频采样率的字符描述符，值类型为uint32_t | 
| \*OH_MD_KEY_I_FRAME_INTERVAL | I帧间隔时长的字符描述符，值类型为int32_t，单位是毫秒 | 
| \*OH_MD_KEY_ROTATION | surface旋转角度的字符描述符，值类型为int32_t，限于{0, 90, 180, 270}，默认值为0 | 
| \*OH_MD_KEY_CODEC_CONFIG |  | 
| \*OH_MD_KEY_REQUEST_I_FRAME |  | 
| \*OH_MD_KEY_QUALITY |  | 
| \*OH_MD_KEY_CHANNEL_LAYOUT |  | 
| \*OH_MD_KEY_BITS_PER_CODED_SAMPLE |  | 
| \*OH_MD_KEY_AAC_IS_ADTS |  | 
| \*OH_MD_KEY_SBR |  | 
| \*OH_MD_KEY_COMPLIANCE_LEVEL |  | 
| \*OH_MD_KEY_IDENTIFICATION_HEADER |  | 
| \*OH_MD_KEY_SETUP_HEADER |  | 
| \*OH_MD_KEY_TITLE |  | 
| \*OH_MD_KEY_ARTIST |  | 
| \*OH_MD_KEY_ALBUM |  | 
| \*OH_MD_KEY_ALBUM_ARTIST |  | 
| \*OH_MD_KEY_DATE |  | 
| \*OH_MD_KEY_COMMENT |  | 
| \*OH_MD_KEY_GENRE |  | 
| \*OH_MD_KEY_COPYRIGHT |  | 
| \*OH_MD_KEY_LANGUAGE |  | 
| \*OH_MD_KEY_DESCRIPTION |  | 
| \*OH_MD_KEY_LYRICS |  | 
| \*OH_MD_KEY_TRACK_COUNT |  | 


## 类型定义说明


### OH_AACProfile

  
```
typedef enum OH_AACProfileOH_AACProfile
```

**描述：**

AAC Profile枚举。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCodecAsyncCallback

  
```
typedef struct OH_AVCodecAsyncCallbackOH_AVCodecAsyncCallback
```

**描述：**

OH_AVCodec中所有异步回调函数指针的集合。将该结构体的实例注册到OH_AVCodec实例中， 并处理回调上报的信息，以保证OH_AVCodec的正常运行。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| [onError](_o_h___a_v_codec_async_callback.md#onerror) | 监控编解码器操作错误，请参见[OH_AVCodecOnError](#oh_avcodeconerror) | 
| [onStreamChanged](_o_h___a_v_codec_async_callback.md#onstreamchanged) | 监控编解码器流变化，请参见[OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged) | 
| [onNeedInputData](_o_h___a_v_codec_async_callback.md#onneedinputdata) | 监控编解码器需要输入数据，请参见[OH_AVCodecOnNeedInputData](#oh_avcodeconneedinputdata) | 
| [onNeedOutputData](_o_h___a_v_codec_async_callback.md#onneedoutputdata) | 监控编解码器已生成输出数据，请参见[OH_AVCodecOnNewOutputData](#oh_avcodeconnewoutputdata) | 


### OH_AVCodecBufferAttr

  
```
typedef struct OH_AVCodecBufferAttrOH_AVCodecBufferAttr
```

**描述：**

定义OH_AVCodec的缓冲区描述信息。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCodecBufferFlags

  
```
typedef enum OH_AVCodecBufferFlagsOH_AVCodecBufferFlags
```

**描述：**

枚举OH_AVCodec缓冲区标记的类别 \@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCodecOnError

  
```
typedef void(* OH_AVCodecOnError) (OH_AVCodec *codec, int32_t errorCode, void *userData)
```

**描述：**

当OH_AVCodec实例运行出错时，会调用来上报具体的错误信息的函数指针。 \@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | OH_AVCodec实例 | 
| errorCode | 特定错误代码 | 
| userData | 用户特定数据 | 


### OH_AVCodecOnNeedInputData

  
```
typedef void(* OH_AVCodecOnNeedInputData) (OH_AVCodec *codec, uint32_t index, OH_AVMemory *data, void *userData)
```

**描述：**

当OH_AVCodec在运行过程中需要新的输入数据时，将调用此函数指针，并携带可用的缓冲区来填充新的输入数据。 \@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | OH_AVCodec实例 | 
| index | 与新可用的输入缓冲区相对应的索引 | 
| data | 新的可用输入缓冲区 | 
| userData | 用户特定数据 | 


### OH_AVCodecOnNewOutputData

  
```
typedef void(* OH_AVCodecOnNewOutputData) (OH_AVCodec *codec, uint32_t index, OH_AVMemory *data, OH_AVCodecBufferAttr *attr, void *userData)
```

**描述：**

当OH_AVCodec运行过程中生成新的输出数据时，将调用此函数指针，并携带包含新输出数据的缓冲区。 需要注意的是，OH_AVCodecBufferAttr指针的生命周期仅在调用函数指针时有效，这将禁止调用结束后继续访问。 \@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | OH_AVCodec实例 | 
| index | 与新输出缓冲区对应的索引 | 
| data | 包含新输出数据的缓冲区 | 
| attr | 新输出缓冲区的说明，请参见[OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) | 
| userData | 用户特定数据 | 


### OH_AVCodecOnStreamChanged

  
```
typedef void(* OH_AVCodecOnStreamChanged) (OH_AVCodec *codec, OH_AVFormat *format, void *userData)
```

**描述：**

当输出流发生变化时，将调用此函数指针报告新的流描述信息。需要注意的是， OH_AVFormat指针的生命周期只有在函数指针被调用时才有效，调用结束后禁止继续访问。 \@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | OH_AVCodec实例 | 
| format | 新输出流描述信息 | 
| userData | 用户特定数据 | 


### OH_AVCProfile

  
```
typedef enum OH_AVCProfileOH_AVCProfile
```

**描述：**

AVC模板 \@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVOutputFormat

  
```
typedef enum OH_AVOutputFormatOH_AVOutputFormat
```

**描述：**

枚举封装器的输出文件格式

**起始版本：**

10


### OH_AVSeekMode

  
```
typedef enum OH_AVSeekModeOH_AVSeekMode
```

**描述：**

寻找模式 \@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_BitsPerSample

  
```
typedef enum OH_BitsPerSampleOH_BitsPerSample
```

**描述：**

枚举每个编码样本的音频位数 \@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_ColorPrimary

  
```
typedef enum OH_ColorPrimaryOH_ColorPrimary
```

**描述：**

原色 \@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_HEVCProfile

  
```
typedef enum OH_HEVCProfileOH_HEVCProfile
```

**描述：**

HEVC模板 \@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MatrixCoefficient

  
```
typedef enum OH_MatrixCoefficientOH_MatrixCoefficient
```

**描述：**

矩阵系数 \@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MediaType

  
```
typedef enum OH_MediaTypeOH_MediaType
```

**描述：**

媒体类型。 \@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_TransferCharacteristic

  
```
typedef enum OH_TransferCharacteristicOH_TransferCharacteristic
```

**描述：**

转移特性 \@syscap SystemCapability.Multimedia.Media.CodecBase


## 枚举类型说明


### OH_AACProfile

  
```
enum OH_AACProfile
```

**描述：**

AAC模板 \@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCodecBufferFlags

  
```
enum OH_AVCodecBufferFlags
```

**描述：**

枚举OH_AVCodec缓冲区标记的类别 \@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCProfile

  
```
enum OH_AVCProfile
```

**描述：**

AVC模板 \@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVOutputFormat

  
```
enum OH_AVOutputFormat
```

**描述：**

枚举封装器的输出文件格式


### OH_AVSeekMode

  
```
enum OH_AVSeekMode
```

**描述：**

寻找模式 \@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_BitsPerSample

  
```
enum OH_BitsPerSample
```

**描述：**

枚举每个编码样本的音频位数 \@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_ColorPrimary

  
```
enum OH_ColorPrimary
```

**描述：**

原色 \@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_HEVCProfile

  
```
enum OH_HEVCProfile
```

**描述：**

HEVC模板 \@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MatrixCoefficient

  
```
enum OH_MatrixCoefficient
```

**描述：**

矩阵系数 \@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MediaType

  
```
enum OH_MediaType
```

**描述：**

媒体类型。 \@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_TransferCharacteristic

  
```
enum OH_TransferCharacteristic
```

**描述：**

转移特性 \@syscap SystemCapability.Multimedia.Media.CodecBase


## 变量说明


### OH_AVCODEC_MIMETYPE_VIDEO_AVC

  
```
const char* OH_AVCODEC_MIMETYPE_VIDEO_AVC
```

**描述：**

AVC视频编解码器的MIME类型。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**起始版本：**

9


### OH_AVCODEC_MIMETYPE_AUDIO_AVC

  
```
const char* OH_AVCODEC_MIMETYPE_AUDIO_AVC
```

**描述：**

AAC音频编解码器的MIME类型。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**起始版本：**

9


### OH_AVCODEC_MIMETYPE_VIDEO_MPEG4

  
```
const char* OH_AVCODEC_MIMETYPE_VIDEO_MPEG4
```

**描述：**

MPEG4视频编解码器的MIME类型。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**起始版本：**

10


### OH_ED_KEY_TIME_STAMP

  
```
const char* OH_ED_KEY_TIME_STAMP
```

**描述：**

表面缓冲区的额外数据的键 \@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MD_KEY_TRACK_TYPE

  
```
const char* OH_MD_KEY_TRACK_TYPE
```

**描述：**

提供统一容器，用于存储媒体描述。 \@syscap SystemCapability.Multimedia.Media.CodecBase
