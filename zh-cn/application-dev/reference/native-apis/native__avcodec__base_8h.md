# native_avcodec_base.h


## 概述

声明运行音视频编解码通用的结构体、字符常量、枚举。

**起始版本：**

9

**相关模块：**

[CodecBase](_codec_base.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) | struct<br/>定义OH_AVCodec的缓冲区描述信息 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) | struct<br/>OH_AVCodec中所有异步回调函数指针的集合。将该结构体的实例注册到OH_AVCodec实例中， 并处理回调上报的信息，以保证OH_AVCodec的正常运行。 \@syscap SystemCapability.Multimedia.Media.CodecBase | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| **OHNativeWindow** | typedef struct NativeWindow | 
| **OH_AVCodec** | typedef struct OH_AVCodec | 
| [OH_AVCodecBufferFlags](_codec_base.md#oh_avcodecbufferflags) | typedef enum [OH_AVCodecBufferFlags](_codec_base.md#oh_avcodecbufferflags)<br/>枚举OH_AVCodec缓冲区标记的类别 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat) | typedef enum [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat)<br/>枚举封装器的输出文件格式 | 
| [OH_AVCodecBufferAttr](_codec_base.md#oh_avcodecbufferattr) | typedef struct [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md)<br/>定义OH_AVCodec的缓冲区描述信息 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_AVCodecOnError](_codec_base.md#oh_avcodeconerror)) (OH_AVCodec \*codec, int32_t errorCode, void \*userData) | typedef void(\*<br/>当OH_AVCodec实例运行出错时，会调用来上报具体的错误信息的函数指针。 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_AVCodecOnStreamChanged](_codec_base.md#oh_avcodeconstreamchanged)) (OH_AVCodec \*codec, OH_AVFormat \*format, void \*userData) | typedef void(\*<br/>当输出流发生变化时，将调用此函数指针报告新的流描述信息。需要注意的是， OH_AVFormat指针的生命周期只有在函数指针被调用时才有效，调用结束后禁止继续访问。 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_AVCodecOnNeedInputData](_codec_base.md#oh_avcodeconneedinputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, void \*userData) | typedef void(\*<br/>当OH_AVCodec在运行过程中需要新的输入数据时，将调用此函数指针，并携带可用的缓冲区来填充新的输入数据。 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_AVCodecOnNewOutputData](_codec_base.md#oh_avcodeconnewoutputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr, void \*userData) | typedef void(\*<br/>当OH_AVCodec运行过程中生成新的输出数据时，将调用此函数指针，并携带包含新输出数据的缓冲区。 需要注意的是，OH_AVCodecBufferAttr指针的生命周期仅在调用函数指针时有效，这将禁止调用结束后继续访问。 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_AVCodecAsyncCallback](_codec_base.md#oh_avcodecasynccallback) | typedef struct [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md)<br/>OH_AVCodec中所有异步回调函数指针的集合。将该结构体的实例注册到OH_AVCodec实例中， 并处理回调上报的信息，以保证OH_AVCodec的正常运行。 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_MediaType](_codec_base.md#oh_mediatype) | typedef enum [OH_MediaType](_codec_base.md#oh_mediatype)<br/>媒体类型。 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_AVCProfile](_codec_base.md#oh_avcprofile) | typedef enum [OH_AVCProfile](_codec_base.md#oh_avcprofile)<br/>AVC模板 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_HEVCProfile](_codec_base.md#oh_hevcprofile) | typedef enum [OH_HEVCProfile](_codec_base.md#oh_hevcprofile)<br/>HEVC模板 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_AACProfile](_codec_base.md#oh_aacprofile) | typedef enum [OH_AACProfile](_codec_base.md#oh_aacprofile)<br/>AAC模板 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_AVSeekMode](_codec_base.md#oh_avseekmode) | typedef enum [OH_AVSeekMode](_codec_base.md#oh_avseekmode)<br/>寻找模式 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_ColorPrimary](_codec_base.md#oh_colorprimary) | typedef enum [OH_ColorPrimary](_codec_base.md#oh_colorprimary)<br/>原色 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_TransferCharacteristic](_codec_base.md#oh_transfercharacteristic) | typedef enum [OH_TransferCharacteristic](_codec_base.md#oh_transfercharacteristic)<br/>转移特性 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_MatrixCoefficient](_codec_base.md#oh_matrixcoefficient) | typedef enum [OH_MatrixCoefficient](_codec_base.md#oh_matrixcoefficient)<br/>矩阵系数 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_BitsPerSample](_codec_base.md#oh_bitspersample) | typedef enum [OH_BitsPerSample](_codec_base.md#oh_bitspersample)<br/>枚举每个编码样本的音频位数 \@syscap SystemCapability.Multimedia.Media.CodecBase | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVCodecBufferFlags](_codec_base.md#oh_avcodecbufferflags) {<br/>**AVCODEC_BUFFER_FLAGS_NONE** = 0, **AVCODEC_BUFFER_FLAGS_EOS** = 1 &lt;&lt; 0, **AVCODEC_BUFFER_FLAGS_SYNC_FRAME** = 1 &lt;&lt; 1, **AVCODEC_BUFFER_FLAGS_INCOMPLETE_FRAME** = 1 &lt;&lt; 2,<br/>**AVCODEC_BUFFER_FLAGS_CODEC_DATA** = 1 &lt;&lt; 3<br/>} | 枚举OH_AVCodec缓冲区标记的类别 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat) { **AV_OUTPUT_FORMAT_DEFAULT** = 0, **AV_OUTPUT_FORMAT_MPEG_4** = 2, **AV_OUTPUT_FORMAT_M4A** = 6 } | 枚举封装器的输出文件格式 | 
| [OH_MediaType](_codec_base.md#oh_mediatype) { **MEDIA_TYPE_AUD** = 0, **MEDIA_TYPE_VID** = 1 } | 媒体类型。 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_AVCProfile](_codec_base.md#oh_avcprofile) { **AVC_PROFILE_BASELINE** = 0, **AVC_PROFILE_HIGH** = 4, **AVC_PROFILE_MAIN** = 8 } | AVC模板 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_HEVCProfile](_codec_base.md#oh_hevcprofile) {<br/>**HEVC_PROFILE_MAIN** = 0, **HEVC_PROFILE_MAIN_10** = 1, **HEVC_PROFILE_MAIN_STILL** = 2, **HEVC_PROFILE_MAIN_10_HDR10** = 3,<br/>**HEVC_PROFILE_MAIN_10_HDR10_PLUS** = 4<br/>} | HEVC模板 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_AACProfile](_codec_base.md#oh_aacprofile) { **AAC_PROFILE_LC** = 0 } | AAC模板 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_AVSeekMode](_codec_base.md#oh_avseekmode) { **SEEK_MODE_NEXT_SYNC** = 0, **SEEK_MODE_PREVIOUS_SYNC**, **SEEK_MODE_CLOSEST_SYNC** } | 寻找模式 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_ColorPrimary](_codec_base.md#oh_colorprimary) {<br/>**COLOR_PRIMARY_BT709** = 1, **COLOR_PRIMARY_UNSPECIFIED** = 2, **COLOR_PRIMARY_BT470_M** = 4, **COLOR_PRIMARY_BT601_625** = 5,<br/>**COLOR_PRIMARY_BT601_525** = 6, **COLOR_PRIMARY_SMPTE_ST240** = 7, **COLOR_PRIMARY_GENERIC_FILM** = 8, **COLOR_PRIMARY_BT2020** = 9,<br/>**COLOR_PRIMARY_SMPTE_ST428** = 10, **COLOR_PRIMARY_P3DCI** = 11, **COLOR_PRIMARY_P3D65** = 12<br/>} | 原色 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_TransferCharacteristic](_codec_base.md#oh_transfercharacteristic) {<br/>**TRANSFER_CHARACTERISTIC_BT709** = 1, **TRANSFER_CHARACTERISTIC_UNSPECIFIED** = 2, **TRANSFER_CHARACTERISTIC_GAMMA_2_2** = 4, **TRANSFER_CHARACTERISTIC_GAMMA_2_8** = 5,<br/>**TRANSFER_CHARACTERISTIC_BT601** = 6, **TRANSFER_CHARACTERISTIC_SMPTE_ST240** = 7, **TRANSFER_CHARACTERISTIC_LINEAR** = 8, **TRANSFER_CHARACTERISTIC_LOG** = 9,<br/>**TRANSFER_CHARACTERISTIC_LOG_SQRT** = 10, **TRANSFER_CHARACTERISTIC_IEC_61966_2_4** = 11, **TRANSFER_CHARACTERISTIC_BT1361** = 12, **TRANSFER_CHARACTERISTIC_IEC_61966_2_1** = 13,<br/>**TRANSFER_CHARACTERISTIC_BT2020_10BIT** = 14, **TRANSFER_CHARACTERISTIC_BT2020_12BIT** = 15, **TRANSFER_CHARACTERISTIC_PQ** = 16, **TRANSFER_CHARACTERISTIC_SMPTE_ST428** = 17,<br/>**TRANSFER_CHARACTERISTIC_HLG** = 18<br/>} | 转移特性 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_MatrixCoefficient](_codec_base.md#oh_matrixcoefficient) {<br/>**MATRIX_COEFFICIENT_IDENTITY** = 0, **MATRIX_COEFFICIENT_BT709** = 1, **MATRIX_COEFFICIENT_UNSPECIFIED** = 2, **MATRIX_COEFFICIENT_FCC** = 4,<br/>**MATRIX_COEFFICIENT_BT601_625** = 5, **MATRIX_COEFFICIENT_BT601_525** = 6, **MATRIX_COEFFICIENT_SMPTE_ST240** = 7, **MATRIX_COEFFICIENT_YCGCO** = 8,<br/>**MATRIX_COEFFICIENT_BT2020_NCL** = 9, **MATRIX_COEFFICIENT_BT2020_CL** = 10, **MATRIX_COEFFICIENT_SMPTE_ST2085** = 11, **MATRIX_COEFFICIENT_CHROMATICITY_NCL** = 12,<br/>**MATRIX_COEFFICIENT_CHROMATICITY_CL** = 13, **MATRIX_COEFFICIENT_ICTCP** = 14<br/>} | 矩阵系数 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| [OH_BitsPerSample](_codec_base.md#oh_bitspersample) {<br/>**SAMPLE_U8** = 0, **SAMPLE_S16LE** = 1, **SAMPLE_S24LE** = 2, **SAMPLE_S32LE** = 3,<br/>**SAMPLE_F32LE** = 4, **SAMPLE_U8P** = 5, **SAMPLE_S16P** = 6, **SAMPLE_S24P** = 7,<br/>**SAMPLE_S32P** = 8, **SAMPLE_F32P** = 9, **INVALID_WIDTH** = -1<br/>} | 枚举每个编码样本的音频位数 \@syscap SystemCapability.Multimedia.Media.CodecBase | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVCODEC_MIMETYPE_VIDEO_AVC](_codec_base.md#oh_avcodec_mimetype_video_avc) | const char \*<br/>枚举音频和视频编解码器的MIME类型 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| **OH_AVCODEC_MIMETYPE_AUDIO_AAC** | const char \* | 
| [OH_AVCODEC_MIMETYPE_VIDEO_MPEG4](_codec_base.md#oh_avcodec_mimetype_video_mpeg4) | const char \*<br/>枚举音频和视频编解码器的MIME类型 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| **OH_AVCODEC_MIMETYPE_VIDEO_HEVC** | const char \* | 
| **OH_AVCODEC_MIMETYPE_AUDIO_MPEG** | const char \* | 
| **OH_AVCODEC_MIMETYPE_IMAGE_JPG** | const char \* | 
| **OH_AVCODEC_MIMETYPE_IMAGE_PNG** | const char \* | 
| **OH_AVCODEC_MIMETYPE_IMAGE_BMP** | const char \* | 
| **OH_AVCODEC_MIMETYPE_AUDIO_FLAC** | const char \* | 
| **OH_AVCODEC_MIMETYPE_AUDIO_VORBIS** | const char \* | 
| [OH_ED_KEY_TIME_STAMP](_codec_base.md#oh_ed_key_time_stamp) | const char \*<br/>表面缓冲区的额外数据的键 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| **OH_ED_KEY_EOS** | const char \* | 
| [OH_MD_KEY_TRACK_TYPE](_codec_base.md#oh_md_key_track_type) | const char \*<br/>提供统一容器，用于存储媒体描述。 \@syscap SystemCapability.Multimedia.Media.CodecBase | 
| **OH_MD_KEY_CODEC_MIME** | const char \* | 
| **OH_MD_KEY_DURATION** | const char \* | 
| **OH_MD_KEY_BITRATE** | const char \* | 
| **OH_MD_KEY_MAX_INPUT_SIZE** | const char \* | 
| **OH_MD_KEY_WIDTH** | const char \* | 
| **OH_MD_KEY_HEIGHT** | const char \* | 
| **OH_MD_KEY_PIXEL_FORMAT** | const char \* | 
| **OH_MD_KEY_RANGE_FLAG** | const char \* | 
| **OH_MD_KEY_COLOR_PRIMARIES** | const char \* | 
| **OH_MD_KEY_TRANSFER_CHARACTERISTICS** | const char \* | 
| **OH_MD_KEY_MATRIX_COEFFICIENTS** | const char \* | 
| **OH_MD_KEY_AUDIO_SAMPLE_FORMAT** | const char \* | 
| **OH_MD_KEY_FRAME_RATE** | const char \* | 
| **OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE** | const char \* | 
| **OH_MD_KEY_PROFILE** | const char \* | 
| **OH_MD_KEY_AUD_CHANNEL_COUNT** | const char \* | 
| **OH_MD_KEY_AUD_SAMPLE_RATE** | const char \* | 
| **OH_MD_KEY_I_FRAME_INTERVAL** | const char \* | 
| **OH_MD_KEY_ROTATION** | const char \* | 
| **OH_MD_KEY_CODEC_CONFIG** | const char \* | 
| **OH_MD_KEY_REQUEST_I_FRAME** | const char \* | 
| **OH_MD_KEY_QUALITY** | const char \* | 
| **OH_MD_KEY_CHANNEL_LAYOUT** | const char \* | 
| **OH_MD_KEY_BITS_PER_CODED_SAMPLE** | const char \* | 
| **OH_MD_KEY_AAC_IS_ADTS** | const char \* | 
| **OH_MD_KEY_SBR** | const char \* | 
| **OH_MD_KEY_COMPLIANCE_LEVEL** | const char \* | 
| **OH_MD_KEY_IDENTIFICATION_HEADER** | const char \* | 
| **OH_MD_KEY_SETUP_HEADER** | const char \* | 
| **OH_MD_KEY_TITLE** | const char \* | 
| **OH_MD_KEY_ARTIST** | const char \* | 
| **OH_MD_KEY_ALBUM** | const char \* | 
| **OH_MD_KEY_ALBUM_ARTIST** | const char \* | 
| **OH_MD_KEY_DATE** | const char \* | 
| **OH_MD_KEY_COMMENT** | const char \* | 
| **OH_MD_KEY_GENRE** | const char \* | 
| **OH_MD_KEY_COPYRIGHT** | const char \* | 
| **OH_MD_KEY_LANGUAGE** | const char \* | 
| **OH_MD_KEY_DESCRIPTION** | const char \* | 
| **OH_MD_KEY_LYRICS** | const char \* | 
| **OH_MD_KEY_TRACK_COUNT** | const char \* | 
