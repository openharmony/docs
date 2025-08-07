# CodecBase

## 概述

CodecBase模块提供用于音视频封装、解封装、编解码基础功能的变量、属性以及函数。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9

## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [avcodec_audio_channel_layout.h](capi-avcodec-audio-channel-layout-h.md) | 音频编解码枚举的声明。 |
| [native_avcodec_base.h](capi-native-avcodec-base-h.md) | 声明用于音视频封装、解封装、编解码基础功能的Native API。 |

## 媒体编解码格式

用于描述媒体编解码格式的名字如下表。类型是常量字符串。

| 名称                                                         | 描述                                                   |
| ------------------------------------------------------------ | ------------------------------------------------------ |
| OH_AVCODEC_MIMETYPE_AUDIO_AAC | AAC音频编解码器的MIME类型。                            |
| OH_AVCODEC_MIMETYPE_AUDIO_FLAC | FLAC音频编解码器的MIME类型。                           |
| OH_AVCODEC_MIMETYPE_AUDIO_OPUS | OPUS音频编解码器的MIME类型。<!--Del-->（此规格暂未开放）<!--DelEnd-->        |
| OH_AVCODEC_MIMETYPE_AUDIO_G711MU | G711MU音频编解码器的MIME类型。                         |
| OH_AVCODEC_MIMETYPE_AUDIO_G711A | G711A音频解码器的MIME类型。                         |
| OH_AVCODEC_MIMETYPE_AUDIO_RAW | RAW音频码流的MIME类型。                         |
| OH_AVCODEC_MIMETYPE_AUDIO_VORBIS | VORBIS音频解码器的MIME类型。                           |
| OH_AVCODEC_MIMETYPE_AUDIO_MPEG | MP3音频编解码器的MIME类型。                              |
| OH_AVCODEC_MIMETYPE_AUDIO_VIVID | Audio Vivid音频解码器的MIME类型。<!--Del-->（此规格暂未开放）<!--DelEnd-->     |
| OH_AVCODEC_MIMETYPE_AUDIO_AMR_NB | AMR_NB音频解码器的MIME类型。                           |
| OH_AVCODEC_MIMETYPE_AUDIO_AMR_WB | AMR_WB音频解码器的MIME类型。                           |
| OH_AVCODEC_MIMETYPE_AUDIO_APE |APE音频解码器的MIME类型。                         |
| OH_AVCODEC_MIMETYPE_VIDEO_VVC | VVC(H.266)视频编解码器的MIME类型。                    |
| OH_AVCODEC_MIMETYPE_VIDEO_HEVC | HEVC(H.265)视频编解码器的MIME类型。                    |
| OH_AVCODEC_MIMETYPE_VIDEO_AVC | AVC(H.264)视频编解码器的MIME类型。                     |
| OH_AVCODEC_MIMETYPE_VIDEO_H263 | H.263视频编解码器的MIME类型。                     |
| OH_AVCODEC_MIMETYPE_VIDEO_MPEG4 | MPEG4视频编码的MIME类型，仅用于封装MPEG4视频码流使用。（API11废弃） |
| OH_AVCODEC_MIMETYPE_VIDEO_MPEG4_PART2 | 视频MPEG4 Part2编解码器的MIME类型。 |
| OH_AVCODEC_MIMETYPE_VIDEO_MPEG2 | 视频MPEG2编解码器的MIME类型。 |
| OH_AVCODEC_MIMETYPE_IMAGE_JPG | JPG图片编码的MIME类型，仅用于封装JPG封面时使用。       |
| OH_AVCODEC_MIMETYPE_IMAGE_PNG | PNG图片编码的MIME类型，仅用于封装PNG封面时使用。       |
| OH_AVCODEC_MIMETYPE_IMAGE_BMP | BMP图片编码的MIME类型，仅用于封装BMP封面时使用。       |
| OH_AVCODEC_MIMETYPE_SUBTITLE_WEBVTT |WEBVTT字幕解封装器的MIME类型。                         |
| OH_AVCODEC_MIMETYPE_SUBTITLE_SRT |SRT字幕解封装器的MIME类型。                         |

## 媒体数据键值对

用于描述媒体数据的键值对查找表如下。键的类型是常量字符串，值的类型可以是int32_t/int64_t/float/double/char */uint8_t *。

使用以下key的主要接口是[OH_AVFormat](_core.md#函数)，通过以下key可以进行参数配置或查询。

### 能力查询专有的键值对

| 名称                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_FEATURE_PROPERTY_KEY_VIDEO_ENCODER_MAX_LTR_FRAME_COUNT     | 在视频编码中获取长期参考帧的最大个数的键，值类型为int32_t。 |

### 音视频公共的键值对

| 名称                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_MD_KEY_CODEC_CONFIG           | 编解码器特定数据的键，视频中表示传递SPS/PPS，音频中表示传递extraData，值类型为uint8_t\*。该键是可选的。 <!--Del-->（视频编解码此功能暂未支持）<!--DelEnd--> |
| OH_MD_MAX_INPUT_BUFFER_COUNT | 最大输入缓冲区个数的键，值类型为int32_t。该键是可选的。      |
| OH_MD_MAX_OUTPUT_BUFFER_COUNT | 最大输出缓冲区个数的键，值类型int32_t。该键是可选的。        |
| OH_MD_KEY_BITRATE                      | 比特率的键，值类型为int64_t。该键用于音视频编码场景。在视频编码场景下该键是可选的。 |
| OH_MD_KEY_PROFILE                     | 编码档次，值类型为int32_t，请参见[OH_AVCProfile](capi-native-avcodec-base-h.md#oh_avcprofile)，[OH_HEVCProfile](capi-native-avcodec-base-h.md#oh_hevcprofile)，[OH_AACProfile](capi-native-avcodec-base-h.md#oh_aacprofile)。该键是可选的。 |
| OH_MD_KEY_MAX_INPUT_SIZE        | 设置解码输入码流大小最大值的键，值类型为int32_t。该键是可选的。           |

### 视频专有的键值对

| 名称                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_ED_KEY_TIME_STAMP               | 表示surfacebuffer时间戳的键，值类型为int64_t。该键是可选的。（API14废弃） |
| OH_ED_KEY_EOS                         | 表示surfacebuffer流结束符的键，值类型为int32_t。该键是可选的。（API14废弃）|
| OH_MD_KEY_WIDTH                          | 视频宽度的键，值类型为int32_t。                             |
| OH_MD_KEY_HEIGHT                        | 视频高度键，值类型为int32_t。                               |
| OH_MD_KEY_PIXEL_FORMAT            | 视频像素格式的键，值类型为int32_t，请参见[OH_AVPixelFormat](_core.md#oh_avpixelformat)。 |
| OH_MD_KEY_FRAME_RATE                | 视频帧率的键，值类型为double。该键是可选的。                 |
| OH_MD_KEY_RANGE_FLAG           | 视频YUV值域标志的键，值类型为int32_t，1表示full range，0表示limited range。该键是可选的。 |
| OH_MD_KEY_COLOR_PRIMARIES      | 视频色域的键，值类型为int32_t，请参见[OH_ColorPrimary](capi-native-avcodec-base-h.md#oh_colorprimary)，遵循H.273标准Table2。该键是可选的。 |
| OH_MD_KEY_TRANSFER_CHARACTERISTICS | 视频传递函数的键，值类型为int32_t，请参见[OH_TransferCharacteristic](capi-native-avcodec-base-h.md#oh_transfercharacteristic)，遵循H.273标准Table3。该键是可选的。 |
| OH_MD_KEY_MATRIX_COEFFICIENTS | 视频矩阵系数的键，值类型为int32_t，请参见[OH_MatrixCoefficient](capi-native-avcodec-base-h.md#oh_matrixcoefficient)，遵循H.273标准Table4。该键是可选的。 |
| OH_MD_KEY_VIDEO_STRIDE       | 描述视频帧宽跨距的键，值类型为int32_t。该键是可选的。        |
| OH_MD_KEY_VIDEO_SLICE_HEIGHT    | 描述视频帧高跨距的键，值类型为int32_t。该键是可选的。        |
| OH_MD_KEY_VIDEO_PIC_WIDTH       | 描述视频帧真实宽度的键，值类型为int32_t。该键是可选的。        |
| OH_MD_KEY_VIDEO_PIC_HEIGHT    | 描述视频帧真实高度的键，值类型为int32_t。该键是可选的。        |
| OH_MD_KEY_VIDEO_ENABLE_LOW_LATENCY  | 使能低时延视频编解码的键，值类型为int32_t，1表示使能，0表示其它情况。该键是可选，在Configure阶段使用。 |
| OH_MD_KEY_ENABLE_SYNC_MODE   | 使能视频编解码同步模式的键，值类型为int32_t，1表示使能，0表示其它情况。该键是可选，在Configure阶段使用。 |
| OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE | 视频编码码率模式，值类型为int32_t，请参见[OH_BitrateMode](capi-native-avcodec-base-h.md#oh_bitratemode)。该键是可选的。 |
| OH_MD_KEY_QUALITY                      | 所需编码质量的键。值类型为int32_t，此键仅适用于配置在恒定质量模式下的编码器。该键是可选的。 |
| OH_MD_KEY_REQUEST_I_FRAME      | 请求立即编码I帧的键。值类型为int32_t。该键是可选的。            |
| OH_MD_KEY_I_FRAME_INTERVAL   | 关键帧间隔的键，值类型为int32_t，单位为毫秒。该键是可选的且只用于视频编码。 |
| OH_MD_KEY_VIDEO_ENCODER_ENABLE_TEMPORAL_SCALABILITY         | 使能分层编码的键，值类型为int32_t，1表示使能，0表示其它情况。该键是可选的且只用于视频编码，在Configure阶段使用。 |
| OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_SIZE       | 描述图片组基本层图片的间隔大小的键，值类型为int32_t，只在使能分层编码时生效。该键是可选的且只用于视频编码，在Configure阶段使用。 |
| OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_REFERENCE_MODE         | 描述图片组内参考模式的键，值类型为int32_t，请参见[OH_TemporalGopReferenceMode](capi-native-avcodec-base-h.md#oh_temporalgopreferencemode)，只在使能分层编码时生效。该键是可选的且只用于视频编码，在Configure阶段使用。 |
| OH_MD_KEY_VIDEO_ENCODER_LTR_FRAME_COUNT        | 描述长期参考帧个数的键，值类型为int32_t，必须在支持的值范围内使用。该键是可选的且只用于视频编码。|
| OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_MARK_LTR  | 标记当前帧为长期参考帧的键，值类型为int32_t，1表示被标记，0表示其它情况。该键是可选的且只用于视频编码。 |
| OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_USE_LTR    | 	描述当前帧参考的长期参考帧帧的POC号的键，值类型为int32_t。该键是可选的且只用于视频编码。 |
| OH_MD_KEY_VIDEO_PER_FRAME_IS_LTR      | 当前[OH_AVBuffer](_core.md#oh_avbuffer)中输出的码流对应的帧是否为长期参考帧的键，值类型为int32_t，1表示是LTR，0表示其它情况。该键是可选的且只用于视频编码。 |
| OH_MD_KEY_VIDEO_PER_FRAME_POC            | 描述帧的POC号的键，值类型为int32_t。该键是可选的且只用于视频编码。 |
| OH_MD_KEY_VIDEO_ENCODER_QP_MAX       | 描述视频编码器允许的最大量化参数的键，值类型为int32_t。该键是可选的且只用于视频编码。 |
| OH_MD_KEY_VIDEO_ENCODER_QP_MIN      | 描述视频编码器允许的最小量化参数的键，值类型为int32_t。该键是可选的且只用于视频编码。 |
| OH_MD_KEY_VIDEO_ENCODER_QP_AVERAGE     |描述视频帧平均量化参数的键，值类型为int32_t。该键是可选的且只用于视频编码。  |
| OH_MD_KEY_VIDEO_ENCODER_MSE     |描述视频帧平方误差的键，值类型为double。该键是可选的且只用于视频编码。  |
| OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER         | 如果在上一帧提交给编码器之后没有新的帧可用，则会以毫秒为单位重复提交最后一帧，值类型为int32_t。该键只用于视频编码Surface模式，在Configure阶段使用。 |
| OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_MAX_COUNT         | 描述编码器在没有新的帧可用的情况下，可以对之前的帧进行重复编码的最大次数，值类型为int32_t。该键仅在OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER可用时生效，在Configure阶段使用。|
| OH_MD_KEY_VIDEO_DECODER_OUTPUT_COLOR_SPACE   | 设置视频解码器输出色彩空间的键，值类型为int32_t。 支持的值为OH_COLORSPACE_BT709_LIMIT。|
| OH_MD_KEY_ROTATION                    | surface旋转角度的键。值类型为int32_t：应为{0, 90, 180, 270}，默认值为0。该键只在视频解码Surface模式下使用。该键是可选的。 |
| OH_MD_KEY_SCALING_MODE            | 视频缩放模式，值类型为int32_t，请参见[OH_ScalingMode](capi-native-avcodec-base-h.md#oh_scalingmode)。该键是可选的且只用于视频解码Surface模式。建议直接调用[OH_NativeWindow_NativeWindowSetScalingModeV2](../apis-arkgraphics2d/capi-external-window-h.md#oh_nativewindow_nativewindowsetscalingmodev2)接口进行设置。（API14废弃）|
| OH_MD_KEY_VIDEO_CROP_TOP       | 描述裁剪矩形顶部坐标(y)值的键，值类型为int32_t。该键是可选的且只用于视频解码。 |
| OH_MD_KEY_VIDEO_CROP_BOTTOM        | 描述裁剪矩形底部坐标(y)值的键，值类型为int32_t。该键是可选的且只用于视频解码。 |
| OH_MD_KEY_VIDEO_CROP_LEFT     | 描述裁剪矩形左坐标(x)值的键，值类型为int32_t。该键是可选的且只用于视频解码。 |
| OH_MD_KEY_VIDEO_CROP_RIGHT     | 描述裁剪矩形右坐标(x)值的键，值类型为int32_t。该键是可选的且只用于视频解码。 |
| OH_MD_KEY_VIDEO_DECODER_OUTPUT_ENABLE_VRR     | 解码器是否打开视频可变帧率功能的键，值类型为int32_t。该键是可选的且只用于视频解码。 |
| OH_MD_KEY_SQR_FACTOR     | 描述SQR码控模式的质量参数，取值范围为[0, 51]（同编码量化参数QP），值越小，编码输出码率越大，质量越好，值类型为int32_t。该键值是可选的且只用于视频编码。 |
| OH_MD_KEY_MAX_BITRATE    | 描述SQR码控模式的最大码率，使用[OH_AVCapability_GetEncoderBitrateRange](_a_v_capability.md#oh_avcapability_getencoderbitraterange)方法获取取值范围（同OH_MD_KEY_BITRATE），单位bps，值类型为int64_t。该键值是可选的且只用于视频编码。 |
| OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS    | 描述ROI编码参数，包括ROI区域和deltaQp，值类型为string。该键值是可选的且只用于视频编码。 |
| OH_MD_KEY_VIDEO_ENCODER_ENABLE_PTS_BASED_RATECONTROL    | 使能基于显示时间戳(PTS)的码控模式的键，值类型为int32_t，1表示使能，0表示其它情况。该键值是可选的且只用于视频编码，默认值为0。如果使能，则必须在每个视频帧中携带PTS信息，并发送到编码器。在Configure阶段使用。 |

### 音频专有的键值对

| 名称                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_MD_KEY_AUDIO_SAMPLE_FORMAT | 音频原始格式的键，值类型为int32_t。请参见[OH_BitsPerSample](capi-native-avcodec-base-h.md#oh_bitspersample)。|
| OH_MD_KEY_AUD_CHANNEL_COUNT  | 音频通道计数键，值类型为int32_t。                           |
| OH_MD_KEY_AUD_SAMPLE_RATE      | 音频采样率键，值类型为int32_t。                             |
| OH_MD_KEY_AUDIO_COMPRESSION_LEVEL | 音频编解码压缩水平的键，只在音频编码使用，值类型为int32_t。该键是可选的。     |
| OH_MD_KEY_CHANNEL_LAYOUT        | 所需编码通道布局的键。值类型为int64_t，此键仅适用于编码器。请参见[OH_AudioChannelLayout](_core.md#oh_audiochannellayout-1)。  |
| OH_MD_KEY_BITS_PER_CODED_SAMPLE | 每个编码样本位数的键，值类型为int32_t。该键是可选的。<br>API 20前，FLAC编码必须设置此参数，设置为1即可；未设置此参数配置FLAC编码器时，调用OH_AudioCodec_Configure会返回错误码AV_ERR_INVALID_VAL。该值无实际作用，不会影响编码结果。从API 20开始，无需设置此参数。|
| OH_MD_KEY_SBR                              | aac sbr模式的键，值类型为int32_t，aac编码器支持。该键是可选的。 |
| OH_MD_KEY_COMPLIANCE_LEVEL    | flac兼容性等级的键，值类型为int32_t，仅在音频编码使用。该键是可选的。          |
| OH_MD_KEY_AAC_IS_ADTS              | aac格式的键，aac格式分为ADTS格式和LATM格式。值类型为int32_t，aac解码器支持。该键是可选的。  |
| OH_MD_KEY_IDENTIFICATION_HEADER | vorbis标识头的键，值类型为uint8_t\*，仅vorbis解码器支持。该键是可选的。 |
| OH_MD_KEY_SETUP_HEADER            | vorbis设置头的键，值类型为uint8_t\*，仅vorbis解码器支持。该键是可选的。 |
| OH_MD_KEY_AUDIO_OBJECT_NUMBER | 音频对象数目的键，值类型为int32_t，只有Audio Vivid解码使用。该键是可选的。            |
| OH_MD_KEY_AUDIO_VIVID_METADATA | Audio Vivid元数据的键，值类型为uint8_t\*，只有Audio Vivid解码使用。该键是可选的。     |

### 封装/解封装专有的键值对

| 名称                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_MD_KEY_VIDEO_IS_HDR_VIVID | 媒体文件中的视频轨是否为HDR Vivid的键，支持封装和解封装，值类型为int32_t。该键是可选的。  |
| OH_MD_KEY_START_TIME | 媒体文件中第一帧起始位置开始时间的键，以微秒为单位，值类型为int64_t。该键是可选的。            |
| OH_MD_KEY_TRACK_START_TIME | 轨道开始时间的键，以微秒为单位，值类型为int64_t。该键是可选的。            |
| OH_MD_KEY_TRACK_TYPE                | 轨道媒体类型的键，值类型为int32_t，请参见[OH_MediaType](capi-native-avcodec-base-h.md#oh_mediatype)。该键是可选的。 |
| OH_MD_KEY_DURATION                    | 媒体文件持续时间的键，值类型为int64_t。该键是可选的。                  |
| OH_MD_KEY_TITLE                          | 媒体文件标题的键，值类型为string。该键是可选的。               |
| OH_MD_KEY_ARTIST                        | 艺术家的键，值类型为string。该键是可选的。             |
| OH_MD_KEY_ALBUM                          | 专辑的媒体文件的键，值类型为string。该键是可选的。               |
| OH_MD_KEY_ALBUM_ARTIST            | 专辑艺术家的键，值类型为string。该键是可选的。               |
| OH_MD_KEY_DATE                            | 媒体文件日期的键，值类型为string，例如2024年。该键是可选的。    |
| OH_MD_KEY_COMMENT                      | 媒体文件注释的键，值类型为string。该键是可选的。               |
| OH_MD_KEY_GENRE                          | 媒体文件流派的键，值类型为string。该键是可选的。               |
| OH_MD_KEY_COPYRIGHT                  | 媒体文件版权的键，值类型为string。该键是可选的。               |
| OH_MD_KEY_LANGUAGE                    | 媒体文件语言的键，值类型为string。该键是可选的。               |
| OH_MD_KEY_DESCRIPTION              | 媒体文件描述的键，值类型为string。该键是可选的。               |
| OH_MD_KEY_LYRICS                        | 媒体文件歌词的键，值类型为string。该键是可选的。               |
| OH_MD_KEY_TRACK_COUNT              | 媒体文件轨道数量的键，值类型为int32_t。该键是可选的。         |
| OH_MD_KEY_BUFFER_DURATION | AVBuffer中携带的音视频或字幕的sample对应的持续时间的键，以微秒为单位，值类型为int64_t。该键是可选的。            |
| OH_MD_KEY_DECODING_TIMESTAMP | AVBuffer中携带的音视频或字幕的sample对应的解码时间戳的键，以微秒为单位，值类型为int64_t。该键是可选的。            |
| OH_MD_KEY_CODEC_MIME                | 编解码器[MIME](#媒体编解码格式)类型的键，值类型为string。该键是可选的。         |
| OH_MD_KEY_VIDEO_SAR                  | 样本长宽比的键，值类型为double。 |
| OH_MD_KEY_CREATION_TIME          | 媒体文件创建时间的元数据，值类型为string。 |
| OH_MD_KEY_REFERENCE_TRACK_IDS          | 媒体文件轨道间参考、被参考关系，值类型为int32_t\*。 |
| OH_MD_KEY_TRACK_REFERENCE_TYPE         | 媒体文件辅助轨类型，值类型为string。 |
| OH_MD_KEY_TRACK_DESCRIPTION         | 媒体文件辅助轨描述信息，值类型为string。 |
