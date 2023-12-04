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
| [native_avcodec_base.h](native__avcodec__base_8h.md) | 声明运行音视频编解码通用的结构体、字符常量、枚举。<br/>**引用文件**：<multimedia/player_framework/native_avcodec_base.h> <br>**库**：libnative_media_codecbase.so| 


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
| [OH_AVCodecBufferFlags](#oh_avcodecbufferflags) {<br/>&nbsp;&nbsp;&nbsp;&nbsp;**AVCODEC_BUFFER_FLAGS_NONE** = 0,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**AVCODEC_BUFFER_FLAGS_EOS** = 1 &lt;&lt; 0,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**AVCODEC_BUFFER_FLAGS_SYNC_FRAME** = 1 &lt;&lt; 1,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**AVCODEC_BUFFER_FLAGS_INCOMPLETE_FRAME** = 1 &lt;&lt; 2,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**AVCODEC_BUFFER_FLAGS_CODEC_DATA** = 1 &lt;&lt; 3<br/>} | 枚举OH_AVCodec缓冲区标记的类别。 | 
| [OH_AVOutputFormat](#oh_avoutputformat) {<br/>&nbsp;&nbsp;&nbsp;&nbsp;**AV_OUTPUT_FORMAT_DEFAULT** = 0,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**AV_OUTPUT_FORMAT_MPEG_4** = 2,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**AV_OUTPUT_FORMAT_M4A** = 6<br/>} | 枚举封装器的输出文件格式。 | 
| [OH_MediaType](#oh_mediatype) {<br/>&nbsp;&nbsp;&nbsp;&nbsp;**MEDIA_TYPE_AUD** = 0,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**MEDIA_TYPE_VID** = 1<br/>} | 媒体类型。 | 
| [OH_AVCProfile](#oh_avcprofile) {<br/>&nbsp;&nbsp;&nbsp;&nbsp;**AVC_PROFILE_BASELINE** = 0,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**AVC_PROFILE_HIGH** = 4,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**AVC_PROFILE_MAIN** = 8<br/>} | AVC Profile枚举。 | 
| [OH_HEVCProfile](#oh_hevcprofile) {<br/>&nbsp;&nbsp;&nbsp;&nbsp;**HEVC_PROFILE_MAIN** = 0,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**HEVC_PROFILE_MAIN_10** = 1,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**HEVC_PROFILE_MAIN_STILL** = 2,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**HEVC_PROFILE_MAIN_10_HDR10** = 3,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**HEVC_PROFILE_MAIN_10_HDR10_PLUS** = 4<br/>} | HEVC Profile枚举。 | 
| [OH_AACProfile](#oh_aacprofile) {<br/>&nbsp;&nbsp;&nbsp;&nbsp;**AAC_PROFILE_LC** = 0<br/>} | AAC Profile枚举。 | 
| [OH_AVSeekMode](#oh_avseekmode) {<br/>&nbsp;&nbsp;&nbsp;&nbsp;**SEEK_MODE_NEXT_SYNC** = 0,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**SEEK_MODE_PREVIOUS_SYNC**,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**SEEK_MODE_CLOSEST_SYNC**<br/>} | 跳转模式。 | 
| [OH_ColorPrimary](#oh_colorprimary) {<br/>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_BT709** = 1,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_UNSPECIFIED** = 2,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_BT470_M** = 4,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_BT601_625** = 5,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_BT601_525** = 6,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_SMPTE_ST240** = 7,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_GENERIC_FILM** = 8,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_BT2020** = 9,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_SMPTE_ST428** = 10,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_P3DCI** = 11,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_P3D65** = 12<br/>} | 原色。 | 
| [OH_TransferCharacteristic](#oh_transfercharacteristic) {<br/>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_BT709** = 1,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_UNSPECIFIED** = 2,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_GAMMA_2_2** = 4,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_GAMMA_2_8** = 5,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_BT601** = 6,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_SMPTE_ST240** = 7,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_LINEAR** = 8,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_LOG** = 9,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_LOG_SQRT** = 10,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_IEC_61966_2_4** = 11,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_BT1361** = 12,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_IEC_61966_2_1** = 13,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_BT2020_10BIT** = 14,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_BT2020_12BIT** = 15,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_PQ** = 16,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_SMPTE_ST428** = 17,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_HLG** = 18<br/>} | 转移特性。 | 
| [OH_MatrixCoefficient](#oh_matrixcoefficient) {<br/>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_IDENTITY** = 0,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_BT709** = 1,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_UNSPECIFIED** = 2,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_FCC** = 4,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_BT601_625** = 5,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_BT601_525** = 6,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_SMPTE_ST240** = 7,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_YCGCO** = 8,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_BT2020_NCL** = 9,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_BT2020_CL** = 10,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_SMPTE_ST2085** = 11,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_CHROMATICITY_NCL** = 12,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_CHROMATICITY_CL** = 13,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_ICTCP** = 14<br/>} | 矩阵系数。 | 
| [OH_BitsPerSample](#oh_bitspersample) {<br/>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_U8** = 0,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_S16LE** = 1,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_S24LE** = 2,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_S32LE** = 3,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_F32LE** = 4,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_U8P** = 5,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_S16P** = 6,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_S24P** = 7,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_S32P** = 8,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_F32P** = 9,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**INVALID_WIDTH** = -1<br/>} | 枚举每个编码样本的音频位数。 | 


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
| \*[OH_AVCODEC_MIMETYPE_AUDIO_AAC](#oh_avcodec_mimetype_audio_aac) | AAC音频编解码器的MIME类型。 | 
| \*[OH_AVCODEC_MIMETYPE_VIDEO_MPEG4](#oh_avcodec_mimetype_video_mpeg4) | MPEG4视频编解码器的MIME类型。 | 
| \*[OH_AVCODEC_MIMETYPE_VIDEO_HEVC](#oh_avcodec_mimetype_video_hevc) | HEVC视频编解码器的MIME类型。 | 
| \*[OH_AVCODEC_MIMETYPE_AUDIO_MPEG](#oh_avcodec_mimetype_audio_mpeg) | MPEG音频编解码器的MIME类型。 | 
| \*[OH_AVCODEC_MIMETYPE_IMAGE_JPG](#oh_avcodec_mimetype_image_jpg) | JPG图片编解码器的MIME类型。 | 
| \*[OH_AVCODEC_MIMETYPE_IMAGE_PNG](#oh_avcodec_mimetype_image_png) | PNG图片编解码器的MIME类型。 | 
| \*[OH_AVCODEC_MIMETYPE_IMAGE_BMP](#oh_avcodec_mimetype_image_bmp) | BMP图片编解码器的MIME类型。 | 
| \*[OH_AVCODEC_MIMETYPE_AUDIO_FLAC](#oh_avcodec_mimetype_audio_flac) | FLAC音频编解码器的MIME类型。 | 
| \*[OH_AVCODEC_MIMETYPE_AUDIO_VORBIS](#oh_avcodec_mimetype_audio_vorbis) | VORBIS音频编解码器的MIME类型。 | 
| \*[OH_ED_KEY_TIME_STAMP](#oh_ed_key_time_stamp) | 表面的额外数据中时间戳的键，值类型为int64 | 
| \*[OH_ED_KEY_EOS](#oh_ed_key_eos) | 表面的额外数据中流结束符的键，值类型为bool | 
| \*[OH_MD_KEY_TRACK_TYPE](#oh_md_key_track_type) | 提供统一容器，用于存储媒体描述。 | 
| \*[OH_MD_KEY_CODEC_MIME](#oh_md_key_codec_mime) | 编解码器mime类型的键，值类型为字符串。 | 
| \*[OH_MD_KEY_DURATION](#oh_md_key_duration) | 持续时间键，值类型为int64_t。 | 
| \*[OH_MD_KEY_BITRATE](#oh_md_key_bitrate) | 比特率的键，值类型为uint32_t。视频编码需要额外设置 [OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE](#oh_md_key_video_encode_bitrate_mode) 以完成比特率设置。 | 
| \*[OH_MD_KEY_MAX_INPUT_SIZE](#oh_md_key_max_input_size) | 最大输入大小的键，值类型为uint32_t | 
| \*[OH_MD_KEY_WIDTH](#oh_md_key_width) | 视频宽度的键，值类型为uint32_t | 
| \*[OH_MD_KEY_HEIGHT](#oh_md_key_height) | 视频高度键，值类型为uint32_t | 
| \*[OH_MD_KEY_PIXEL_FORMAT](#oh_md_key_pixel_format) | 视频像素格式的键，值类型为int32_t，具体见[OH_AVPixelFormat](_core.md#oh_avpixelformat) | 
| \*[OH_MD_KEY_RANGE_FLAG](#oh_md_key_range_flag) | 视频YUV取值范围标志的键，值类型为bool | 
| \*[OH_MD_KEY_COLOR_PRIMARIES](#oh_md_key_color_primaries) | 视频颜色原色键, 值类型为int32_t | 
| \*[OH_MD_KEY_TRANSFER_CHARACTERISTICS](#oh_md_key_transfer_characteristics) | 视频转移特性的键，值类型为int32_t | 
| \*[OH_MD_KEY_MATRIX_COEFFICIENTS](#oh_md_key_matrix_coefficients) | 视频矩阵系数的键，值类型为int32_t | 
| \*[OH_MD_KEY_AUDIO_SAMPLE_FORMAT](#oh_md_key_audio_sample_format) | 音频原始格式的键，值类型为uint32_t | 
| \*[OH_MD_KEY_FRAME_RATE](#oh_md_key_frame_rate) | 视频帧率的键，值类型为双精度浮点。 | 
| \*[OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE](#oh_md_key_video_encode_bitrate_mode) | 视频编码码率模式，值类型为int32_t，具体见[OH_VideoEncodeBitrateMode](_video_encoder.md#oh_videoencodebitratemode) | 
| \*[OH_MD_KEY_PROFILE](#oh_md_key_profile) | 编码模板，值类型为数字，具体见[OH_AVCProfile](#oh_avcprofile)，[OH_AACProfile](#oh_aacprofile)或[OH_HEVCProfile](#oh_hevcprofile) | 
| \*[OH_MD_KEY_AUD_CHANNEL_COUNT](#oh_md_key_aud_channel_count) | 音频通道计数键，值类型为uint32_t | 
| \*[OH_MD_KEY_AUD_SAMPLE_RATE](#oh_md_key_aud_sample_rate) | 音频采样率键，值类型为uint32_t | 
| \*[OH_MD_KEY_I_FRAME_INTERVAL](#oh_md_key_i_frame_interval) | 关键帧间隔的键，值类型为int32_t，单位为毫秒。 | 
| \*[OH_MD_KEY_ROTATION](#oh_md_key_rotation) | 表面旋转角度的键。值类型为int32_t：应为{0, 90, 180, 270}，默认值为0。 | 
| \*[OH_MD_KEY_CODEC_CONFIG](#oh_md_key_codec_config) | 编解码器特定数据的键，值类型为uint8_t\*。 | 
| \*[OH_MD_KEY_REQUEST_I_FRAME](#oh_md_key_request_i_frame) | 请求立即编码I帧的键。值类型为布尔值 | 
| \*[OH_MD_KEY_QUALITY](#oh_md_key_quality) | 所需编码质量的键。值类型为uint32_t，此键仅适用于配置在恒定质量模式下的编码器 | 
| \*[OH_MD_KEY_CHANNEL_LAYOUT](#oh_md_key_channel_layout) | 所需编码通道布局的键。值类型为int64_t，此键仅适用于编码器。 | 
| \*[OH_MD_KEY_BITS_PER_CODED_SAMPLE](#oh_md_key_bits_per_coded_sample) | 每个编码样本位数的键，值类型为uint32_t，支持flac编码器，请参见 [OH_BitsPerSample](#oh_bitspersample)。 | 
| \*[OH_MD_KEY_AAC_IS_ADTS](#oh_md_key_aac_is_adts) | aac格式的键，值类型为uint32_t,aac解码器支持。 | 
| \*[OH_MD_KEY_SBR](#oh_md_key_sbr) | aac sbr模式的键，值类型为uint32_t,aac编码器支持。 | 
| \*[OH_MD_KEY_COMPLIANCE_LEVEL](#oh_md_key_compliance_level) | flac合规性级别的键，值类型为int32_t。 | 
| \*[OH_MD_KEY_IDENTIFICATION_HEADER](#oh_md_key_identification_header) | vorbis标识头的键，值类型为uint8_t\*，仅vorbis解码器支持。 | 
| \*[OH_MD_KEY_SETUP_HEADER](#oh_md_key_setup_header) | vorbis设置头的键，值类型为uint8_t\*，仅vorbis解码器支持。 | 
| \*[OH_MD_KEY_TITLE](#oh_md_key_title) | 源格式标题的键，值类型为字符串 | 
| \*[OH_MD_KEY_ARTIST](#oh_md_key_artist) | 艺术家的源格式Key，值类型为字符串 | 
| \*[OH_MD_KEY_ALBUM](#oh_md_key_album) | 相册的源格式键，值类型为字符串 | 
| \*[OH_MD_KEY_ALBUM_ARTIST](#oh_md_key_album_artist) | 源格式专辑_artist的键，值类型为字符串 | 
| \*[OH_MD_KEY_DATE](#oh_md_key_date) | 源格式日期的键，值类型为字符串 | 
| \*[OH_MD_KEY_COMMENT](#oh_md_key_comment) | 源格式注释的键，值类型为字符串 | 
| \*[OH_MD_KEY_GENRE](#oh_md_key_genre) | 源格式类型的键，值类型为字符串 | 
| \*[OH_MD_KEY_COPYRIGHT](#oh_md_key_copyright) | 源格式版权的键，值类型为字符串 | 
| \*[OH_MD_KEY_LANGUAGE](#oh_md_key_language) | 源格式语言的键，值类型为字符串 | 
| \*[OH_MD_KEY_DESCRIPTION](#oh_md_key_description) | 源格式描述的键，值类型为字符串 | 
| \*[OH_MD_KEY_LYRICS](#oh_md_key_lyrics) | 源格式歌词的键，值类型为字符串 | 
| \*[OH_MD_KEY_TRACK_COUNT](#oh_md_key_track_count) | 源格式轨道计数的键，值类型为uint32_t | 
| \*[OH_MD_MAX_INPUT_BUFFER_COUNT](#oh_md_max_input_buffer_count) | 输入buffer的最大个数，值类型为int32_t | 
| \*[OH_MD_MAX_OUTPUT_BUFFER_COUNT](#oh_md_max_output_buffer_count) | 输出buffer的最大个数，值类型为int32_t | 


## 类型定义说明


### OH_AACProfile

  
```
typedef enum OH_AACProfile OH_AACProfile
```

**描述：**

AAC Profile枚举。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCodecAsyncCallback

  
```
typedef struct OH_AVCodecAsyncCallback OH_AVCodecAsyncCallback
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
typedef struct OH_AVCodecBufferAttr OH_AVCodecBufferAttr
```

**描述：**

定义OH_AVCodec的缓冲区描述信息。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCodecBufferFlags

  
```
typedef enum OH_AVCodecBufferFlags OH_AVCodecBufferFlags
```

**描述：**

枚举OH_AVCodec缓冲区标记的类别。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCodecOnError

  
```
typedef void (*OH_AVCodecOnError) (OH_AVCodec *codec, int32_t errorCode, void *userData)
```

**描述：**

当OH_AVCodec实例运行出错时，会调用来上报具体的错误信息的函数指针。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | OH_AVCodec实例 | 
| errorCode | 特定错误代码 | 
| userData | 用户特定数据 | 


### OH_AVCodecOnNeedInputData

  
```
typedef void (*OH_AVCodecOnNeedInputData) (OH_AVCodec *codec, uint32_t index, OH_AVMemory *data, void *userData)
```

**描述：**

当OH_AVCodec在运行过程中需要新的输入数据时，将调用此函数指针，并携带可用的缓冲区来填充新的输入数据。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | OH_AVCodec实例 | 
| index | 与新可用的输入缓冲区相对应的索引 | 
| data | 新的可用输入缓冲区 | 
| userData | 用户特定数据 | 


### OH_AVCodecOnNewOutputData

  
```
typedef void (*OH_AVCodecOnNewOutputData) (OH_AVCodec *codec, uint32_t index, OH_AVMemory *data, OH_AVCodecBufferAttr *attr, void *userData)
```

**描述：**

当OH_AVCodec运行过程中生成新的输出数据时，将调用此函数指针，并携带包含新输出数据的缓冲区。 需要注意的是，OH_AVCodecBufferAttr指针的生命周期仅在调用函数指针时有效，这将禁止调用结束后继续访问。

\@syscap SystemCapability.Multimedia.Media.CodecBase

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
typedef void (*OH_AVCodecOnStreamChanged) (OH_AVCodec *codec, OH_AVFormat *format, void *userData)
```

**描述：**

当输出流发生变化时，将调用此函数指针报告新的流描述信息。需要注意的是， OH_AVFormat指针的生命周期只有在函数指针被调用时才有效，调用结束后禁止继续访问。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | OH_AVCodec实例 | 
| format | 新输出流描述信息 | 
| userData | 用户特定数据 | 

**format 携载字段：**
| Key                    | 描述             |
| ---------------------- | ---------------  |
| OH_MD_KEY_WIDTH        | 视频输出宽度     |
| OH_MD_KEY_HEIGHT       | 视频输出高度     |
| OH_MD_KEY_PIXEL_FORMAT | 视频输出像素格式 |

### OH_AVCProfile

  
```
typedef enum OH_AVCProfile OH_AVCProfile
```

**描述：**

AVC Profile枚举。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVOutputFormat

  
```
typedef enum OH_AVOutputFormat OH_AVOutputFormat
```

**描述：**

枚举封装器的输出文件格式。


### OH_AVSeekMode

  
```
typedef enum OH_AVSeekMode OH_AVSeekMode
```

**描述：**

跳转模式。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_BitsPerSample

  
```
typedef enum OH_BitsPerSample OH_BitsPerSample
```

**描述：**

枚举每个编码样本的音频位数。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_ColorPrimary

  
```
typedef enum OH_ColorPrimary OH_ColorPrimary
```

**描述：**

原色。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_HEVCProfile

  
```
typedef enum OH_HEVCProfile OH_HEVCProfile
```

**描述：**

HEVC Profile枚举。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MatrixCoefficient

  
```
typedef enum OH_MatrixCoefficient OH_MatrixCoefficient
```

**描述：**

矩阵系数。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MediaType

  
```
typedef enum OH_MediaType OH_MediaType
```

**描述：**

媒体类型。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_TransferCharacteristic

  
```
typedef enum OH_TransferCharacteristic OH_TransferCharacteristic
```

**描述：**

转移特性。

\@syscap SystemCapability.Multimedia.Media.CodecBase


## 枚举类型说明


### OH_AACProfile

  
```
enum OH_AACProfile
```

**描述：**

AAC Profile枚举。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCodecBufferFlags

  
```
enum OH_AVCodecBufferFlags
```

**描述：**

枚举OH_AVCodec缓冲区标记的类别。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCProfile

  
```
enum OH_AVCProfile
```

**描述：**

AVC Profile枚举。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVOutputFormat

  
```
enum OH_AVOutputFormat
```

**描述：**

枚举封装器的输出文件格式。


### OH_AVSeekMode

  
```
enum OH_AVSeekMode
```

**描述：**

跳转模式。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_BitsPerSample

  
```
enum OH_BitsPerSample
```

**描述：**

枚举每个编码样本的音频位数。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_ColorPrimary

  
```
enum OH_ColorPrimary
```

**描述：**

原色。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_HEVCProfile

  
```
enum OH_HEVCProfile
```

**描述：**

HEVC Profile枚举。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MatrixCoefficient

  
```
enum OH_MatrixCoefficient
```

**描述：**

矩阵系数。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MediaType

  
```
enum OH_MediaType
```

**描述：**

媒体类型。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_TransferCharacteristic

  
```
enum OH_TransferCharacteristic
```

**描述：**

转移特性。

\@syscap SystemCapability.Multimedia.Media.CodecBase


## 变量说明


### OH_AVCODEC_MIMETYPE_AUDIO_AAC

  
```
const char* OH_AVCODEC_MIMETYPE_AUDIO_AAC
```

**描述：**

AAC音频编解码器的MIME类型。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCODEC_MIMETYPE_AUDIO_FLAC

  
```
const char* OH_AVCODEC_MIMETYPE_AUDIO_FLAC
```

**描述：**

FLAC音频编解码器的MIME类型。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCODEC_MIMETYPE_AUDIO_MPEG

  
```
const char* OH_AVCODEC_MIMETYPE_AUDIO_MPEG
```

**描述：**

MPEG音频编解码器的MIME类型。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCODEC_MIMETYPE_AUDIO_VORBIS

  
```
const char* OH_AVCODEC_MIMETYPE_AUDIO_VORBIS
```

**描述：**

VORBIS音频编解码器的MIME类型。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCODEC_MIMETYPE_IMAGE_BMP

  
```
const char* OH_AVCODEC_MIMETYPE_IMAGE_BMP
```

**描述：**

BMP图片编解码器的MIME类型。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCODEC_MIMETYPE_IMAGE_JPG

  
```
const char* OH_AVCODEC_MIMETYPE_IMAGE_JPG
```

**描述：**

JPG图片编解码器的MIME类型。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCODEC_MIMETYPE_IMAGE_PNG

  
```
const char* OH_AVCODEC_MIMETYPE_IMAGE_PNG
```

**描述：**

PNG图片编解码器的MIME类型。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCODEC_MIMETYPE_VIDEO_AVC

  
```
const char* OH_AVCODEC_MIMETYPE_VIDEO_AVC
```

**描述：**

AVC视频编解码器的MIME类型。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCODEC_MIMETYPE_VIDEO_HEVC

  
```
const char* OH_AVCODEC_MIMETYPE_VIDEO_HEVC
```

**描述：**

HEVC视频编解码器的MIME类型。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCODEC_MIMETYPE_VIDEO_MPEG4

  
```
const char* OH_AVCODEC_MIMETYPE_VIDEO_MPEG4
```

**描述：**

MPEG4视频编解码器的MIME类型。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_ED_KEY_EOS

  
```
const char* OH_ED_KEY_EOS
```

**描述：**

表面的额外数据中流结束符的键，值类型为bool

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_ED_KEY_TIME_STAMP

  
```
const char* OH_ED_KEY_TIME_STAMP
```

**描述：**

表面的额外数据中时间戳的键，值类型为int64

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MD_KEY_AAC_IS_ADTS

  
```
const char* OH_MD_KEY_AAC_IS_ADTS
```

**描述：**

aac格式的键，值类型为uint32_t,aac解码器支持。


### OH_MD_KEY_ALBUM

  
```
const char* OH_MD_KEY_ALBUM
```

**描述：**

相册的源格式键，值类型为字符串


### OH_MD_KEY_ALBUM_ARTIST

  
```
const char* OH_MD_KEY_ALBUM_ARTIST
```

**描述：**

源格式专辑_artist的键，值类型为字符串


### OH_MD_KEY_ARTIST

  
```
const char* OH_MD_KEY_ARTIST
```

**描述：**

艺术家的源格式Key，值类型为字符串


### OH_MD_KEY_AUD_CHANNEL_COUNT

  
```
const char* OH_MD_KEY_AUD_CHANNEL_COUNT
```

**描述：**

音频通道计数键，值类型为uint32_t


### OH_MD_KEY_AUD_SAMPLE_RATE

  
```
const char* OH_MD_KEY_AUD_SAMPLE_RATE
```

**描述：**

音频采样率键，值类型为uint32_t


### OH_MD_KEY_AUDIO_SAMPLE_FORMAT

  
```
const char* OH_MD_KEY_AUDIO_SAMPLE_FORMAT
```

**描述：**

音频原始格式的键，值类型为uint32_t


### OH_MD_KEY_BITRATE

  
```
const char* OH_MD_KEY_BITRATE
```

**描述：**

比特率的键，值类型为uint32_t。视频编码需要额外设置 [OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE](#oh_md_key_video_encode_bitrate_mode) 以完成比特率设置。


### OH_MD_KEY_BITS_PER_CODED_SAMPLE

  
```
const char* OH_MD_KEY_BITS_PER_CODED_SAMPLE
```

**描述：**

每个编码样本位数的键，值类型为uint32_t，支持flac编码器。


### OH_MD_KEY_CHANNEL_LAYOUT

  
```
const char* OH_MD_KEY_CHANNEL_LAYOUT
```

**描述：**

所需编码通道布局的键。值类型为int64_t，此键仅适用于编码器。


### OH_MD_KEY_CODEC_CONFIG

  
```
const char* OH_MD_KEY_CODEC_CONFIG
```

**描述：**

编解码器特定数据的键，值类型为uint8_t\*。


### OH_MD_KEY_CODEC_MIME

  
```
const char* OH_MD_KEY_CODEC_MIME
```

**描述：**

编解码器mime类型的键，值类型为字符串。


### OH_MD_KEY_COLOR_PRIMARIES

  
```
const char* OH_MD_KEY_COLOR_PRIMARIES
```

**描述：**

视频颜色原色键, 值类型为int32_t


### OH_MD_KEY_COMMENT

  
```
const char* OH_MD_KEY_COMMENT
```

**描述：**

源格式注释的键，值类型为字符串


### OH_MD_KEY_COMPLIANCE_LEVEL

  
```
const char* OH_MD_KEY_COMPLIANCE_LEVEL
```

**描述：**

flac合规性级别的键，值类型为int32_t。


### OH_MD_KEY_COPYRIGHT

  
```
const char* OH_MD_KEY_COPYRIGHT
```

**描述：**

源格式版权的键，值类型为字符串


### OH_MD_KEY_DATE

  
```
const char* OH_MD_KEY_DATE
```

**描述：**

源格式日期的键，值类型为字符串


### OH_MD_KEY_DESCRIPTION

  
```
const char* OH_MD_KEY_DESCRIPTION
```

**描述：**

源格式描述的键，值类型为字符串


### OH_MD_KEY_DURATION

  
```
const char* OH_MD_KEY_DURATION
```

**描述：**

持续时间键，值类型为int64_t。


### OH_MD_KEY_FRAME_RATE

  
```
const char* OH_MD_KEY_FRAME_RATE
```

**描述：**

视频帧率的键，值类型为双精度浮点。


### OH_MD_KEY_GENRE

  
```
const char* OH_MD_KEY_GENRE
```

**描述：**

源格式类型的键，值类型为字符串


### OH_MD_KEY_HEIGHT

  
```
const char* OH_MD_KEY_HEIGHT
```

**描述：**

视频高度键，值类型为uint32_t


### OH_MD_KEY_I_FRAME_INTERVAL

  
```
const char* OH_MD_KEY_I_FRAME_INTERVAL
```

**描述：**

关键帧间隔的键，值类型为int32_t，单位为毫秒。


### OH_MD_KEY_IDENTIFICATION_HEADER

  
```
const char* OH_MD_KEY_IDENTIFICATION_HEADER
```

**描述：**

vorbis标识头的键，值类型为uint8_t\*，仅vorbis解码器支持。


### OH_MD_KEY_LANGUAGE

  
```
const char* OH_MD_KEY_LANGUAGE
```

**描述：**

源格式语言的键，值类型为字符串


### OH_MD_KEY_LYRICS

  
```
const char* OH_MD_KEY_LYRICS
```

**描述：**

源格式歌词的键，值类型为字符串


### OH_MD_KEY_MATRIX_COEFFICIENTS

  
```
const char* OH_MD_KEY_MATRIX_COEFFICIENTS
```

**描述：**

视频矩阵系数的键，值类型为int32_t


### OH_MD_KEY_MAX_INPUT_SIZE

  
```
const char* OH_MD_KEY_MAX_INPUT_SIZE
```

**描述：**

最大输入大小的键，值类型为uint32_t


### OH_MD_KEY_PIXEL_FORMAT

  
```
const char* OH_MD_KEY_PIXEL_FORMAT
```

**描述：**

视频像素格式的键，值类型为int32_t，具体见[OH_AVPixelFormat](_core.md#oh_avpixelformat)


### OH_MD_KEY_PROFILE

  
```
const char* OH_MD_KEY_PROFILE
```

**描述：**

编码模板，值类型为数字，具体见[OH_AVCProfile](#oh_avcprofile)，[OH_AACProfile](#oh_aacprofile)或[OH_HEVCProfile](#oh_hevcprofile)。


### OH_MD_KEY_QUALITY

  
```
const char* OH_MD_KEY_QUALITY
```

**描述：**

所需编码质量的键。值类型为uint32_t，此键仅适用于配置在恒定质量模式下的编码器


### OH_MD_KEY_RANGE_FLAG

  
```
const char* OH_MD_KEY_RANGE_FLAG
```

**描述：**

视频YUV取值范围标志的键，值类型为bool


### OH_MD_KEY_REQUEST_I_FRAME

  
```
const char* OH_MD_KEY_REQUEST_I_FRAME
```

**描述：**

请求立即编码I帧的键。值类型为布尔值


### OH_MD_KEY_ROTATION

  
```
const char* OH_MD_KEY_ROTATION
```

**描述：**

表面旋转角度的键。值类型为int32_t：应为{0, 90, 180, 270}，默认值为0。


### OH_MD_KEY_SBR

  
```
const char* OH_MD_KEY_SBR
```

**描述：**

aac sbr模式的键，值类型为uint32_t,aac编码器支持。


### OH_MD_KEY_SETUP_HEADER

  
```
const char* OH_MD_KEY_SETUP_HEADER
```

**描述：**

vorbis设置头的键，值类型为uint8_t\*，仅vorbis解码器支持。


### OH_MD_KEY_TITLE

  
```
const char* OH_MD_KEY_TITLE
```

**描述：**

源格式标题的键，值类型为字符串


### OH_MD_KEY_TRACK_COUNT

  
```
const char* OH_MD_KEY_TRACK_COUNT
```

**描述：**

源格式轨道计数的键，值类型为uint32_t


### OH_MD_KEY_TRACK_TYPE

  
```
const char* OH_MD_KEY_TRACK_TYPE
```

**描述：**

提供统一容器，用于存储媒体描述。

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MD_KEY_TRANSFER_CHARACTERISTICS

  
```
const char* OH_MD_KEY_TRANSFER_CHARACTERISTICS
```

**描述：**

视频转移特性的键，值类型为int32_t


### OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE

  
```
const char* OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE
```

**描述：**

视频编码码率模式，值类型为int32_t，具体见[OH_VideoEncodeBitrateMode](_video_encoder.md#oh_videoencodebitratemode)


### OH_MD_KEY_WIDTH

  
```
const char* OH_MD_KEY_WIDTH
```

**描述：**

视频宽度的键，值类型为uint32_t


### OH_MD_MAX_INPUT_BUFFER_COUNT

  
```
const char* OH_MD_MAX_INPUT_BUFFER_COUNT
```

**描述：**

输入buffer的最大个数，值类型为int32_t


### OH_MD_MAX_OUTPUT_BUFFER_COUNT

  
```
const char* OH_MD_MAX_OUTPUT_BUFFER_COUNT
```

**描述：**

输出buffer的最大个数，值类型为int32_t