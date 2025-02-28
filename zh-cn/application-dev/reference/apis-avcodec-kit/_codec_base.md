# CodecBase


## 概述

CodecBase模块提供用于音视频封装、解封装、编解码基础功能的变量、属性以及函数。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9

### 媒体编解码格式

用于描述媒体编解码格式的名字如下表。类型是常量字符串。

| 名称                                                         | 描述                                                   |
| ------------------------------------------------------------ | ------------------------------------------------------ |
| [OH_AVCODEC_MIMETYPE_AUDIO_AAC](#oh_avcodec_mimetype_audio_aac) | AAC音频编解码器的MIME类型。                            |
| [OH_AVCODEC_MIMETYPE_AUDIO_FLAC](#oh_avcodec_mimetype_audio_flac) | FLAC音频编解码器的MIME类型。                           |
| [OH_AVCODEC_MIMETYPE_AUDIO_OPUS](#oh_avcodec_mimetype_audio_opus) | OPUS音频编解码器的MIME类型。<!--Del-->（此规格暂未开放）<!--DelEnd-->        |
| [OH_AVCODEC_MIMETYPE_AUDIO_G711MU](#oh_avcodec_mimetype_audio_g711mu) | G711MU音频编解码器的MIME类型。                         |
| [OH_AVCODEC_MIMETYPE_AUDIO_RAW](#oh_avcodec_mimetype_audio_raw) | RAW音频码流的MIME类型。                         |
| [OH_AVCODEC_MIMETYPE_AUDIO_VORBIS](#oh_avcodec_mimetype_audio_vorbis) | VORBIS音频解码器的MIME类型。                           |
| [OH_AVCODEC_MIMETYPE_AUDIO_MPEG](#oh_avcodec_mimetype_audio_mpeg) | MP3音频解码器的MIME类型。                              |
| [OH_AVCODEC_MIMETYPE_AUDIO_VIVID](#oh_avcodec_mimetype_audio_vivid) | Audio Vivid音频解码器的MIME类型。<!--Del-->（此规格暂未开放）<!--DelEnd-->     |
| [OH_AVCODEC_MIMETYPE_AUDIO_AMR_NB](#oh_avcodec_mimetype_audio_amr_nb) | AMR_NB音频解码器的MIME类型。                           |
| [OH_AVCODEC_MIMETYPE_AUDIO_AMR_WB](#oh_avcodec_mimetype_audio_amr_wb) | AMR_WB音频解码器的MIME类型。                           |
| [OH_AVCODEC_MIMETYPE_AUDIO_APE](#oh_avcodec_mimetype_audio_ape) |APE音频解码器的MIME类型。                         |
| [OH_AVCODEC_MIMETYPE_VIDEO_VVC](#oh_avcodec_mimetype_video_vvc) | VVC(H.266)视频编解码器的MIME类型。                    |
| [OH_AVCODEC_MIMETYPE_VIDEO_HEVC](#oh_avcodec_mimetype_video_hevc) | HEVC(H.265)视频编解码器的MIME类型。                    |
| [OH_AVCODEC_MIMETYPE_VIDEO_AVC](#oh_avcodec_mimetype_video_avc) | AVC(H.264)视频编解码器的MIME类型。                     |
| [OH_AVCODEC_MIMETYPE_VIDEO_MPEG4](#oh_avcodec_mimetype_video_mpeg4) | MPEG4视频编码的MIME类型，仅用于封装MPEG4视频码流使用。（API11废弃） |
| [OH_AVCODEC_MIMETYPE_IMAGE_JPG](#oh_avcodec_mimetype_image_jpg) | JPG图片编码的MIME类型，仅用于封装JPG封面时使用。       |
| [OH_AVCODEC_MIMETYPE_IMAGE_PNG](#oh_avcodec_mimetype_image_png) | PNG图片编码的MIME类型，仅用于封装PNG封面时使用。       |
| [OH_AVCODEC_MIMETYPE_IMAGE_BMP](#oh_avcodec_mimetype_image_bmp) | BMP图片编码的MIME类型，仅用于封装BMP封面时使用。       |
| [OH_AVCODEC_MIMETYPE_SUBTITLE_WEBVTT](#oh_avcodec_mimetype_subtitle_webvtt) |WEBVTT字幕解封装器的MIME类型。                         |
| [OH_AVCODEC_MIMETYPE_SUBTITLE_SRT](#oh_avcodec_mimetype_subtitle_srt) |SRT字幕解封装器的MIME类型。                         |


### 媒体数据键值对

用于描述媒体数据的键值对查找表如下。键的类型是常量字符串，值的类型可以是int32_t/int64_t/float/double/char */uint8_t *。

使用以下key的主要接口是[OH_AVFormat](_core.md#函数)，通过以下key可以进行参数配置或查询。

能力查询专有的键值对：

| 名称                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_FEATURE_PROPERTY_KEY_VIDEO_ENCODER_MAX_LTR_FRAME_COUNT](#oh_feature_property_key_video_encoder_max_ltr_frame_count)     | 在视频编码中获取长期参考帧的最大个数的键，值类型为int32_t。 |

音视频公共的键值对：

| 名称                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_MD_KEY_CODEC_CONFIG](#oh_md_key_codec_config)            | 编解码器特定数据的键，视频中表示传递SPS/PPS，音频中表示传递extraData，值类型为uint8_t\*。该键是可选的。 <!--Del-->（视频编解码此功能暂未支持）<!--DelEnd--> |
| [OH_MD_MAX_INPUT_BUFFER_COUNT](#oh_md_max_input_buffer_count) | 最大输入缓冲区个数的键，值类型为int32_t。该键是可选的。      |
| [OH_MD_MAX_OUTPUT_BUFFER_COUNT](#oh_md_max_output_buffer_count) | 最大输出缓冲区个数的键，值类型int32_t。该键是可选的。        |
| [OH_MD_KEY_BITRATE](#oh_md_key_bitrate)                      | 比特率的键，值类型为int64_t。该键用于音视频编码场景。在视频编码场景下该键是可选的。 |
| [OH_MD_KEY_PROFILE](#oh_md_key_profile)                      | 编码档次，值类型为int32_t，请参见[OH_AVCProfile](#oh_avcprofile)，[OH_HEVCProfile](#oh_hevcprofile)，[OH_AACProfile](#oh_aacprofile)。该键是可选的。 |
| [OH_MD_KEY_MAX_INPUT_SIZE](#oh_md_key_max_input_size)        | 设置解码输入码流大小最大值的键，值类型为int32_t。该键是可选的。           |


视频专有的键值对：

| 名称                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_ED_KEY_TIME_STAMP](#oh_ed_key_time_stamp)                | 表示surfacebuffer时间戳的键，值类型为int64_t。该键是可选的。（API14废弃） |
| [OH_ED_KEY_EOS](#oh_ed_key_eos)                              | 表示surfacebuffer流结束符的键，值类型为int32_t。该键是可选的。（API14废弃）|
| [OH_MD_KEY_WIDTH](#oh_md_key_width)                          | 视频宽度的键，值类型为int32_t。                             |
| [OH_MD_KEY_HEIGHT](#oh_md_key_height)                        | 视频高度键，值类型为int32_t。                               |
| [OH_MD_KEY_PIXEL_FORMAT](#oh_md_key_pixel_format)            | 视频像素格式的键，值类型为int32_t，请参见[OH_AVPixelFormat](_core.md#oh_avpixelformat)。 |
| [OH_MD_KEY_FRAME_RATE](#oh_md_key_frame_rate)                | 视频帧率的键，值类型为double。该键是可选的。                 |
| [OH_MD_KEY_RANGE_FLAG](#oh_md_key_range_flag)                | 视频YUV值域标志的键，值类型为int32_t，1表示full range，0表示limited range。该键是可选的。 |
| [OH_MD_KEY_COLOR_PRIMARIES](#oh_md_key_color_primaries)      | 视频色域的键，值类型为int32_t，请参见[OH_ColorPrimary](#oh_colorprimary)，遵循H.273标准Table2。该键是可选的。 |
| [OH_MD_KEY_TRANSFER_CHARACTERISTICS](#oh_md_key_transfer_characteristics) | 视频传递函数的键，值类型为int32_t，请参见[OH_TransferCharacteristic](#oh_transfercharacteristic)，遵循H.273标准Table3。该键是可选的。 |
| [OH_MD_KEY_MATRIX_COEFFICIENTS](#oh_md_key_matrix_coefficients) | 视频矩阵系数的键，值类型为int32_t，请参见[OH_MatrixCoefficient](#oh_matrixcoefficient)，遵循H.273标准Table4。该键是可选的。 |
| [OH_MD_KEY_VIDEO_STRIDE](#oh_md_key_video_stride)       | 描述视频帧宽跨距的键，值类型为int32_t。该键是可选的。        |
| [OH_MD_KEY_VIDEO_SLICE_HEIGHT](#oh_md_key_video_slice_height)    | 描述视频帧高跨距的键，值类型为int32_t。该键是可选的。        |
| [OH_MD_KEY_VIDEO_PIC_WIDTH](#oh_md_key_video_pic_width)       | 描述视频帧真实宽度的键，值类型为int32_t。该键是可选的。        |
| [OH_MD_KEY_VIDEO_PIC_HEIGHT](#oh_md_key_video_pic_height)    | 描述视频帧真实高度的键，值类型为int32_t。该键是可选的。        |
| [OH_MD_KEY_VIDEO_ENABLE_LOW_LATENCY](#oh_md_key_video_enable_low_latency)   | 使能低时延视频编解码的键，值类型为int32_t，1表示使能，0表示其它情况。该键是可选，在Configure阶段使用。 |
| [OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE](#oh_md_key_video_encode_bitrate_mode) | 视频编码码率模式，值类型为int32_t，请参见[OH_BitrateMode](#oh_bitratemode-1)。该键是可选的。 |
| [OH_MD_KEY_QUALITY](#oh_md_key_quality)                      | 所需编码质量的键。值类型为int32_t，此键仅适用于配置在恒定质量模式下的编码器。该键是可选的。 |
| [OH_MD_KEY_REQUEST_I_FRAME](#oh_md_key_request_i_frame)      | 请求立即编码I帧的键。值类型为int32_t。该键是可选的。            |
| [OH_MD_KEY_I_FRAME_INTERVAL](#oh_md_key_i_frame_interval)    | 关键帧间隔的键，值类型为int32_t，单位为毫秒。该键是可选的且只用于视频编码。 |
| [OH_MD_KEY_VIDEO_ENCODER_ENABLE_TEMPORAL_SCALABILITY](#oh_md_key_video_encoder_enable_temporal_scalability)          | 使能分层编码的键，值类型为int32_t，1表示使能，0表示其它情况。该键是可选的且只用于视频编码，在Configure阶段使用。 |
| [OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_SIZE](#oh_md_key_video_encoder_temporal_gop_size)       | 描述图片组基本层图片的间隔大小的键，值类型为int32_t，只在使能分层编码时生效。该键是可选的且只用于视频编码，在Configure阶段使用。 |
| [OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_REFERENCE_MODE](#oh_md_key_video_encoder_temporal_gop_reference_mode)         | 描述图片组内参考模式的键，值类型为int32_t，请参见[OH_TemporalGopReferenceMode](#oh_temporalgopreferencemode-1)，只在使能分层编码时生效。该键是可选的且只用于视频编码，在Configure阶段使用。 |
| [OH_MD_KEY_VIDEO_ENCODER_LTR_FRAME_COUNT](#oh_md_key_video_encoder_ltr_frame_count)        | 描述长期参考帧个数的键，值类型为int32_t，必须在支持的值范围内使用。该键是可选的且只用于视频编码。|
| [OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_MARK_LTR](#oh_md_key_video_encoder_per_frame_mark_ltr)  | 标记当前帧为长期参考帧的键，值类型为int32_t，1表示被标记，0表示其它情况。该键是可选的且只用于视频编码。 |
| [OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_USE_LTR](#oh_md_key_video_encoder_per_frame_use_ltr)    | 	描述当前帧参考的长期参考帧帧的POC号的键，值类型为int32_t。该键是可选的且只用于视频编码。 |
| [OH_MD_KEY_VIDEO_PER_FRAME_IS_LTR](#oh_md_key_video_per_frame_is_ltr)      | 当前[OH_AVBuffer](_core.md#oh_avbuffer)中输出的码流对应的帧是否为长期参考帧的键，值类型为int32_t，1表示是LTR，0表示其它情况。该键是可选的且只用于视频编码。 |
| [OH_MD_KEY_VIDEO_PER_FRAME_POC](#oh_md_key_video_per_frame_poc)            | 描述帧的POC号的键，值类型为int32_t。该键是可选的且只用于视频编码。 |
| [OH_MD_KEY_VIDEO_ENCODER_QP_MAX](#oh_md_key_video_encoder_qp_max)       | 描述视频编码器允许的最大量化参数的键，值类型为int32_t。该键是可选的且只用于视频编码。 |
| [OH_MD_KEY_VIDEO_ENCODER_QP_MIN](#oh_md_key_video_encoder_qp_min)      | 描述视频编码器允许的最小量化参数的键，值类型为int32_t。该键是可选的且只用于视频编码。 |
| [OH_MD_KEY_VIDEO_ENCODER_QP_AVERAGE](#oh_md_key_video_encoder_qp_average)     |描述视频帧平均量化参数的键，值类型为int32_t。该键是可选的且只用于视频编码。  |
| [OH_MD_KEY_VIDEO_ENCODER_MSE](#oh_md_key_video_encoder_mse)     |描述视频帧平方误差的键，值类型为double。该键是可选的且只用于视频编码。  |
| [OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER](#oh_md_key_video_encoder_repeat_previous_frame_after)         | 如果在上一帧提交给编码器之后没有新的帧可用，则会以毫秒为单位重复提交最后一帧，值类型为int32_t。该键只用于视频编码Surface模式，在Configure阶段使用。 |
| [OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_MAX_COUNT](#oh_md_key_video_encoder_repeat_previous_max_count)         | 描述编码器在没有新的帧可用的情况下，可以对之前的帧进行重复编码的最大次数，值类型为int32_t。该键仅在OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER可用时生效，在Configure阶段使用。|
| [OH_MD_KEY_VIDEO_DECODER_OUTPUT_COLOR_SPACE](#oh_md_key_video_decoder_output_color_space)    | 设置视频解码器输出色彩空间的键，值类型为int32_t。 支持的值为OH_COLORSPACE_BT709_LIMIT。|
| [OH_MD_KEY_ROTATION](#oh_md_key_rotation)                    | surface旋转角度的键。值类型为int32_t：应为{0, 90, 180, 270}，默认值为0。该键只在视频解码Surface模式下使用。该键是可选的。 |
| [OH_MD_KEY_SCALING_MODE](#oh_md_key_scaling_mode)            | 视频缩放模式，值类型为int32_t，请参见[OH_ScalingMode](#oh_scalingmode)。该键是可选的且只用于视频解码Surface模式。建议直接调用[OH_NativeWindow_NativeWindowSetScalingModeV2](../apis-arkgraphics2d/_native_window.md#oh_nativewindow_nativewindowsetscalingmodev2)接口进行设置。（API14废弃）|
| [OH_MD_KEY_VIDEO_CROP_TOP](#oh_md_key_video_crop_top)       | 描述裁剪矩形顶部坐标(y)值的键，值类型为int32_t。该键是可选的且只用于视频解码。 |
| [OH_MD_KEY_VIDEO_CROP_BOTTOM](#oh_md_key_video_crop_bottom)        | 描述裁剪矩形底部坐标(y)值的键，值类型为int32_t。该键是可选的且只用于视频解码。 |
| [OH_MD_KEY_VIDEO_CROP_LEFT](#oh_md_key_video_crop_left)     | 描述裁剪矩形左坐标(x)值的键，值类型为int32_t。该键是可选的且只用于视频解码。 |
| [OH_MD_KEY_VIDEO_CROP_RIGHT](#oh_md_key_video_crop_right)     | 描述裁剪矩形右坐标(x)值的键，值类型为int32_t。该键是可选的且只用于视频解码。 |
| [OH_MD_KEY_VIDEO_DECODER_OUTPUT_ENABLE_VRR](#oh_md_key_video_decoder_output_enable_vrr)     | 解码器是否打开视频可变帧率功能的键，值类型为int32_t。该键是可选的且只用于视频解码。 |

音频专有的键值对：

| 名称                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_MD_KEY_AUDIO_SAMPLE_FORMAT](#oh_md_key_audio_sample_format) | 音频原始格式的键，值类型为int32_t。请参见[OH_BitsPerSample](#oh_bitspersample-1)。|
| [OH_MD_KEY_AUD_CHANNEL_COUNT](#oh_md_key_aud_channel_count)  | 音频通道计数键，值类型为int32_t。                           |
| [OH_MD_KEY_AUD_SAMPLE_RATE](#oh_md_key_aud_sample_rate)      | 音频采样率键，值类型为int32_t。                             |
| [OH_MD_KEY_AUDIO_COMPRESSION_LEVEL](#oh_md_key_audio_compression_level) | 音频编解码压缩水平的键，只在音频编码使用，值类型为int32_t。该键是可选的。     |
| [OH_MD_KEY_CHANNEL_LAYOUT](#oh_md_key_channel_layout)        | 所需编码通道布局的键。值类型为int64_t，此键仅适用于编码器。请参见[OH_AudioChannelLayout](_core.md#oh_audiochannellayout-1)。  |
| [OH_MD_KEY_BITS_PER_CODED_SAMPLE](#oh_md_key_bits_per_coded_sample) | 每个编码样本位数的键，值类型为int32_t，支持flac编码器，请参见[OH_BitsPerSample](#oh_bitspersample-1)。该键是可选的。 |
| [OH_MD_KEY_SBR](#oh_md_key_sbr)                              | aac sbr模式的键，值类型为int32_t，aac编码器支持。该键是可选的。 |
| [OH_MD_KEY_COMPLIANCE_LEVEL](#oh_md_key_compliance_level)    | flac兼容性等级的键，值类型为int32_t，仅在音频编码使用。该键是可选的。          |
| [OH_MD_KEY_AAC_IS_ADTS](#oh_md_key_aac_is_adts)              | aac格式的键，aac格式分为ADTS格式和LATM格式。值类型为int32_t，aac解码器支持。该键是可选的。  |
| [OH_MD_KEY_IDENTIFICATION_HEADER](#oh_md_key_identification_header) | vorbis标识头的键，值类型为uint8_t\*，仅vorbis解码器支持。该键是可选的。 |
| [OH_MD_KEY_SETUP_HEADER](#oh_md_key_setup_header)            | vorbis设置头的键，值类型为uint8_t\*，仅vorbis解码器支持。该键是可选的。 |
| [OH_MD_KEY_AUDIO_OBJECT_NUMBER](#oh_md_key_audio_object_number) | 音频对象数目的键，值类型为int32_t，只有Audio Vivid解码使用。该键是可选的。            |
| [OH_MD_KEY_AUDIO_VIVID_METADATA](#oh_md_key_audio_vivid_metadata) | Audio Vivid元数据的键，值类型为uint8_t\*，只有Audio Vivid解码使用。该键是可选的。     |

封装/解封装专有的键值对：

| 名称                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_MD_KEY_VIDEO_IS_HDR_VIVID](#oh_md_key_video_is_hdr_vivid) | 媒体文件中的视频轨是否为HDR Vivid的键，支持封装和解封装，值类型为int32_t。该键是可选的。  |
| [OH_MD_KEY_START_TIME](#oh_md_key_start_time) | 媒体文件中第一帧起始位置开始时间的键，以微秒为单位，值类型为int64_t。该键是可选的。            |
| [OH_MD_KEY_TRACK_START_TIME](#oh_md_key_track_start_time) | 轨道开始时间的键，以微秒为单位，值类型为int64_t。该键是可选的。            |
| [OH_MD_KEY_TRACK_TYPE](#oh_md_key_track_type)                | 轨道媒体类型的键，值类型为int32_t，请参见[OH_MediaType](#oh_mediatype-1)。该键是可选的。 |
| [OH_MD_KEY_DURATION](#oh_md_key_duration)                    | 媒体文件持续时间的键，值类型为int64_t。该键是可选的。                  |
| [OH_MD_KEY_TITLE](#oh_md_key_title)                          | 媒体文件标题的键，值类型为string。该键是可选的。               |
| [OH_MD_KEY_ARTIST](#oh_md_key_artist)                        | 艺术家的键，值类型为string。该键是可选的。             |
| [OH_MD_KEY_ALBUM](#oh_md_key_album)                          | 专辑的媒体文件的键，值类型为string。该键是可选的。               |
| [OH_MD_KEY_ALBUM_ARTIST](#oh_md_key_album_artist)            | 专辑艺术家的键，值类型为string。该键是可选的。               |
| [OH_MD_KEY_DATE](#oh_md_key_date)                            | 媒体文件日期的键，值类型为string，例如2024年。该键是可选的。    |
| [OH_MD_KEY_COMMENT](#oh_md_key_comment)                      | 媒体文件注释的键，值类型为string。该键是可选的。               |
| [OH_MD_KEY_GENRE](#oh_md_key_genre)                          | 媒体文件流派的键，值类型为string。该键是可选的。               |
| [OH_MD_KEY_COPYRIGHT](#oh_md_key_copyright)                  | 媒体文件版权的键，值类型为string。该键是可选的。               |
| [OH_MD_KEY_LANGUAGE](#oh_md_key_language)                    | 媒体文件语言的键，值类型为string。该键是可选的。               |
| [OH_MD_KEY_DESCRIPTION](#oh_md_key_description)              | 媒体文件描述的键，值类型为string。该键是可选的。               |
| [OH_MD_KEY_LYRICS](#oh_md_key_lyrics)                        | 媒体文件歌词的键，值类型为string。该键是可选的。               |
| [OH_MD_KEY_TRACK_COUNT](#oh_md_key_track_count)              | 媒体文件轨道数量的键，值类型为int32_t。该键是可选的。         |
| [OH_MD_KEY_BUFFER_DURATION](#oh_md_key_buffer_duration) | AVBuffer中携带的音视频或字幕的sample对应的持续时间的键，以微秒为单位，值类型为int64_t。该键是可选的。            |
| [OH_MD_KEY_DECODING_TIMESTAMP](#oh_md_key_decoding_timestamp) | AVBuffer中携带的音视频或字幕的sample对应的解码时间戳的键，以微秒为单位，值类型为int64_t。该键是可选的。            |
| [OH_MD_KEY_CODEC_MIME](#oh_md_key_codec_mime)                | 编解码器[MIME](#媒体编解码格式)类型的键，值类型为string。该键是可选的。         |
| [OH_MD_KEY_VIDEO_SAR](#oh_md_key_video_sar)                  | 样本长宽比的键，值类型为double。 |
| [OH_MD_KEY_CREATION_TIME](#oh_md_key_creation_time)          | 媒体文件创建时间的元数据，值类型为string。 |


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [avcodec_audio_channel_layout.h](avcodec__audio__channel__layout_8h.md) | 音频编解码枚举的声明。 | 
| [native_avcodec_base.h](native__avcodec__base_8h.md) | 音视频封装、解封装、编解码基础功能Native API的声明。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) | OH_AVCodec中所有异步回调函数指针的集合。（API11废弃）| 
| struct  [OH_AVCodecCallback](_o_h___a_v_codec_callback.md) | OH_AVCodec中所有异步回调函数指针的集合。 | 
| struct  [OH_AVDataSource](_o_h___a_v_data_source.md) | 用户自定义数据源。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct NativeWindow [OHNativeWindow](#ohnativewindow) | 为图形接口定义native层对象。  | 
| typedef struct [OH_AVCodec](#oh_avcodec) [OH_AVCodec](#oh_avcodec) | 为音视频编解码接口定义native层对象。  | 
| typedef void(\* [OH_AVCodecOnError](#oh_avcodeconerror)) ([OH_AVCodec](#oh_avcodec) \*codec, int32_t errorCode, void \*userData) | 当OH_AVCodec实例运行出错时，会调用来上报具体的错误信息的函数指针。 | 
| typedef void(\* [OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged)) ([OH_AVCodec](#oh_avcodec) \*codec, [OH_AVFormat](_core.md#oh_avformat) \*format, void \*userData) | 当视频解码输入码流分辨率或者视频编码输出码流的分辨率发生变化时，将调用此函数指针报告新的流描述信息。<br>从API 15开始，支持音频解码时，码流采样率、声道数或者音频采样格式发生变化时，将调用此函数指针报告新的流描述信息，支持检测此变化的解码格式有：<!--RP3--><!--RP3End-->AAC，FLAC，MP3，VORBIS。| 
| typedef void(\* [OH_AVCodecOnNeedInputData](#oh_avcodeconneedinputdata)) ([OH_AVCodec](#oh_avcodec) \*codec, uint32_t index, [OH_AVMemory](_core.md#oh_avmemory) \*data, void \*userData) | 当OH_AVCodec在运行过程中需要新的输入数据时，将调用此函数指针，并携带可用的缓冲区来填充新的输入数据。（API11废弃）| 
| typedef void(\* [OH_AVCodecOnNewOutputData](#oh_avcodeconnewoutputdata)) ([OH_AVCodec](#oh_avcodec) \*codec, uint32_t index, [OH_AVMemory](_core.md#oh_avmemory) \*data, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr, void \*userData) | 当OH_AVCodec运行过程中生成新的输出数据时，将调用此函数指针，并携带包含新输出数据的缓冲区。（API11废弃）| 
| typedef void(\* [OH_AVCodecOnNeedInputBuffer](#oh_avcodeconneedinputbuffer)) ([OH_AVCodec](#oh_avcodec) \*codec, uint32_t index, [OH_AVBuffer](_core.md#oh_avbuffer) \*buffer, void \*userData) | 当OH_AVCodec在运行过程中需要新的输入数据时，将调用此函数指针，并携带可用的缓冲区来填充新的输入数据。 | 
| typedef void(\* [OH_AVCodecOnNewOutputBuffer](#oh_avcodeconnewoutputbuffer)) ([OH_AVCodec](#oh_avcodec) \*codec, uint32_t index, [OH_AVBuffer](_core.md#oh_avbuffer) \*buffer, void \*userData) | 当OH_AVCodec运行过程中生成新的输出数据时，将调用此函数指针，并携带包含新输出数据的缓冲区。 | 
| typedef struct [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) [OH_AVCodecAsyncCallback](#oh_avcodecasynccallback) | OH_AVCodec中所有异步回调函数指针的集合。（API11废弃）| 
| typedef struct [OH_AVCodecCallback](_o_h___a_v_codec_callback.md) [OH_AVCodecCallback](#oh_avcodeccallback) | OH_AVCodec中所有异步回调函数指针的集合。 | 
| typedef int32_t(\* [OH_AVDataSourceReadAt](#oh_avdatasourcereadat)) (OH_AVBuffer \*data, int32_t length, int64_t pos) | 函数指针定义，用于提供获取用户自定义媒体数据的能力。  | 
| typedef struct [OH_AVDataSource](_o_h___a_v_data_source.md) [OH_AVDataSource](#oh_avdatasource) | 用户自定义数据源。  | 
| typedef enum [OH_MediaType](#oh_mediatype-1) [OH_MediaType](#oh_mediatype) | 媒体类型。 | 
| typedef enum [OH_AACProfile](#oh_aacprofile-1) [OH_AACProfile](#oh_aacprofile) | AAC档次。 | 
| typedef enum [OH_AVCProfile](#oh_avcprofile-1) [OH_AVCProfile](#oh_avcprofile) | AVC档次。 | 
| typedef enum [OH_HEVCProfile](#oh_hevcprofile-1) [OH_HEVCProfile](#oh_hevcprofile) | HEVC档次。 | 
| typedef enum [OH_VVCProfile](#oh_vvcprofile-1) [OH_VVCProfile](#oh_vvcprofile) | VVC档次。 | 
| typedef enum [OH_AVOutputFormat](#oh_avoutputformat-1) [OH_AVOutputFormat](#oh_avoutputformat) | 封装器支持的输出文件格式。 | 
| typedef enum [OH_AVSeekMode](#oh_avseekmode-1) [OH_AVSeekMode](#oh_avseekmode) | 跳转模式。 | 
| typedef enum [OH_ScalingMode](#oh_scalingmode-1) [OH_ScalingMode](#oh_scalingmode) | 缩放模式，只在Surface模式下使用。（API14废弃） | 
| typedef enum [OH_BitsPerSample](#oh_bitspersample-1) [OH_BitsPerSample](#oh_bitspersample) | 每个编码样本的音频位数。 | 
| typedef enum [OH_ColorPrimary](#oh_colorprimary-1) [OH_ColorPrimary](#oh_colorprimary) | 色域。 | 
| typedef enum [OH_TransferCharacteristic](#oh_transfercharacteristic-1) [OH_TransferCharacteristic](#oh_transfercharacteristic) | 转移特性。 | 
| typedef enum [OH_MatrixCoefficient](#oh_matrixcoefficient-1) [OH_MatrixCoefficient](#oh_matrixcoefficient) | 矩阵系数。 | 
| typedef enum [OH_AVCLevel](#oh_avclevel-1) [OH_AVCLevel](#oh_avclevel) | AVC级别。  | 
| typedef enum [OH_HEVCLevel](#oh_hevclevel-1) [OH_HEVCLevel](#oh_hevclevel) | HEVC级别。  | 
| typedef enum [OH_VVCLevel](#oh_vvclevel-1) [OH_VVCLevel](#oh_vvclevel) | VVC级别。  | 
| typedef enum [OH_TemporalGopReferenceMode](#oh_temporalgopreferencemode-1) [OH_TemporalGopReferenceMode](#oh_temporalgopreferencemode) | 时域图片组参考模式。  |
| typedef enum [OH_BitrateMode](#oh_bitratemode-1) [OH_BitrateMode](#oh_bitratemode) | 编码器的比特率模式。  |


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [AudioChannelSet](#audiochannelset) : uint64_t {<br/>FRONT_LEFT = 1ULL &lt;&lt; 0U,<br/>FRONT_RIGHT = 1ULL &lt;&lt; 1U,<br/>FRONT_CENTER = 1ULL &lt;&lt; 2U,<br/>LOW_FREQUENCY = 1ULL &lt;&lt; 3U,<br/>BACK_LEFT = 1ULL &lt;&lt; 4U,<br/>BACK_RIGHT = 1ULL &lt;&lt; 5U,<br/>FRONT_LEFT_OF_CENTER = 1ULL &lt;&lt; 6U,<br/>FRONT_RIGHT_OF_CENTER = 1ULL &lt;&lt; 7U,<br/>BACK_CENTER = 1ULL &lt;&lt; 8U,<br/>SIDE_LEFT = 1ULL &lt;&lt; 9U,<br/>SIDE_RIGHT = 1ULL &lt;&lt; 10U,<br/>TOP_CENTER = 1ULL &lt;&lt; 11U,<br/>TOP_FRONT_LEFT = 1ULL &lt;&lt; 12U,<br/>TOP_FRONT_CENTER = 1ULL &lt;&lt; 13U,<br/>TOP_FRONT_RIGHT = 1ULL &lt;&lt; 14U,<br/>TOP_BACK_LEFT = 1ULL &lt;&lt; 15U,<br/>TOP_BACK_CENTER = 1ULL &lt;&lt; 16U,<br/>TOP_BACK_RIGHT = 1ULL &lt;&lt; 17U,<br/>STEREO_LEFT = 1ULL &lt;&lt; 29U,<br/>STEREO_RIGHT = 1ULL &lt;&lt; 30U,<br/>WIDE_LEFT = 1ULL &lt;&lt; 31U,<br/>WIDE_RIGHT = 1ULL &lt;&lt; 32U,<br/>SURROUND_DIRECT_LEFT = 1ULL &lt;&lt; 33U,<br/>SURROUND_DIRECT_RIGHT = 1ULL &lt;&lt; 34U,<br/>LOW_FREQUENCY_2 = 1ULL &lt;&lt; 35U,<br/>TOP_SIDE_LEFT = 1ULL &lt;&lt; 36U,<br/>TOP_SIDE_RIGHT = 1ULL &lt;&lt; 37U,<br/>BOTTOM_FRONT_CENTER = 1ULL &lt;&lt; 38U,<br/>BOTTOM_FRONT_LEFT = 1ULL &lt;&lt; 39U,<br/>BOTTOM_FRONT_RIGHT = 1ULL &lt;&lt; 40U,<br/>AMBISONICS_ACN0 = 1ULL &lt;&lt; 41U,<br/>AMBISONICS_ACN1 = 1ULL &lt;&lt; 42U,<br/>AMBISONICS_ACN2 = 1ULL &lt;&lt; 43U,<br/>AMBISONICS_ACN3 = 1ULL &lt;&lt; 44U,<br/>AMBISONICS_W = AMBISONICS_ACN0,<br/>AMBISONICS_Y = AMBISONICS_ACN1,<br/>AMBISONICS_Z = AMBISONICS_ACN2,<br/>AMBISONICS_X = AMBISONICS_ACN3,<br/>AMBISONICS_ACN4 = 1ULL &lt;&lt; 45U,<br/>AMBISONICS_ACN5 = 1ULL &lt;&lt; 46U,<br/>AMBISONICS_ACN6 = 1ULL &lt;&lt; 47U,<br/>AMBISONICS_ACN7 = 1ULL &lt;&lt; 48U,<br/>AMBISONICS_ACN8 = 1ULL &lt;&lt; 49U,<br/>AMBISONICS_ACN9 = 1ULL &lt;&lt; 50U,<br/>AMBISONICS_ACN10 = 1ULL &lt;&lt; 51U,<br/>AMBISONICS_ACN11 = 1ULL &lt;&lt; 52U,<br/>AMBISONICS_ACN12 = 1ULL &lt;&lt; 53U,<br/>AMBISONICS_ACN13 = 1ULL &lt;&lt; 54U,<br/>AMBISONICS_ACN14 = 1ULL &lt;&lt; 55U,<br/>AMBISONICS_ACN15 = 1ULL &lt;&lt; 56U<br/>} | 音频声道数集合， 将每一个声道数映射为int64_t的变量。（API11废弃）| 
| [AudioChannelLayout](#audiochannellayout) : uint64_t {<br/>UNKNOWN_CHANNEL_LAYOUT = 0,<br/>MONO = (AudioChannelSet::FRONT_CENTER),<br/>STEREO = (AudioChannelSet::FRONT_LEFT \| AudioChannelSet::FRONT_RIGHT),<br/>CH_2POINT1 = (STEREO \| AudioChannelSet::LOW_FREQUENCY),<br/>CH_2_1 = (STEREO \| AudioChannelSet::BACK_CENTER),<br/>SURROUND = (STEREO \| AudioChannelSet::FRONT_CENTER),<br/>CH_3POINT1 = (SURROUND \| AudioChannelSet::LOW_FREQUENCY),<br/>CH_4POINT0 = (SURROUND \| AudioChannelSet::BACK_CENTER),<br/>CH_4POINT1 = (CH_4POINT0 \| AudioChannelSet::LOW_FREQUENCY),<br/>CH_2_2 = (STEREO \| AudioChannelSet::SIDE_LEFT \| AudioChannelSet::SIDE_RIGHT),<br/>QUAD = (STEREO \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT),<br/>CH_5POINT0 = (SURROUND \| AudioChannelSet::SIDE_LEFT \| AudioChannelSet::SIDE_RIGHT),<br/>CH_5POINT1 = (CH_5POINT0 \| AudioChannelSet::LOW_FREQUENCY),<br/>CH_5POINT0_BACK = (SURROUND \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT),<br/>CH_5POINT1_BACK = (CH_5POINT0_BACK \| AudioChannelSet::LOW_FREQUENCY),<br/>CH_6POINT0 = (CH_5POINT0 \| AudioChannelSet::BACK_CENTER),<br/>CH_6POINT0_FRONT = (CH_2_2 \| AudioChannelSet::FRONT_LEFT_OF_CENTER \| AudioChannelSet::FRONT_RIGHT_OF_CENTER),<br/>HEXAGONAL = (CH_5POINT0_BACK \| AudioChannelSet::BACK_CENTER),<br/>CH_6POINT1 = (CH_5POINT1 \| AudioChannelSet::BACK_CENTER),<br/>CH_6POINT1_BACK = (CH_5POINT1_BACK \| AudioChannelSet::BACK_CENTER),<br/>CH_6POINT1_FRONT = (CH_6POINT0_FRONT \| AudioChannelSet::LOW_FREQUENCY),<br/>CH_7POINT0 = (CH_5POINT0 \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT),<br/>CH_7POINT0_FRONT = (CH_5POINT0 \| AudioChannelSet::FRONT_LEFT_OF_CENTER \| AudioChannelSet::FRONT_RIGHT_OF_CENTER),<br/>CH_7POINT1 = (CH_5POINT1 \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT),<br/>CH_7POINT1_WIDE = (CH_5POINT1 \| AudioChannelSet::FRONT_LEFT_OF_CENTER \| AudioChannelSet::FRONT_RIGHT_OF_CENTER),<br/>CH_7POINT1_WIDE_BACK, CH_3POINT1POINT2 = (CH_3POINT1 \| AudioChannelSet::TOP_FRONT_LEFT \| AudioChannelSet::TOP_FRONT_RIGHT),<br/>CH_5POINT1POINT2 = (CH_5POINT1 \| AudioChannelSet::TOP_SIDE_LEFT \| AudioChannelSet::TOP_SIDE_RIGHT),<br/>CH_5POINT1POINT4, CH_7POINT1POINT2 = (CH_7POINT1 \| AudioChannelSet::TOP_SIDE_LEFT \| AudioChannelSet::TOP_SIDE_RIGHT),<br/>CH_7POINT1POINT4, CH_9POINT1POINT4 = (CH_7POINT1POINT4 \| AudioChannelSet::WIDE_LEFT \| AudioChannelSet::WIDE_RIGHT),<br/>CH_9POINT1POINT6 = (CH_9POINT1POINT4 \| AudioChannelSet::TOP_SIDE_LEFT \| AudioChannelSet::TOP_SIDE_RIGHT),<br/>CH_10POINT2, CH_22POINT2, OCTAGONAL = (CH_5POINT0 \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_CENTER \| AudioChannelSet::BACK_RIGHT),<br/>HEXADECAGONAL, STEREO_DOWNMIX = (AudioChannelSet::STEREO_LEFT \| AudioChannelSet::STEREO_RIGHT),<br/>HOA_FIRST,<br/>HOA_SECOND,<br/>HOA_THIRD<br/>} | 音频声道数类型，将用户申请的解码器输出格式表示为编解码器的声道类型。（API11废弃） | 
| [OH_MediaType](#oh_mediatype-1) {<br/>MEDIA_TYPE_AUD = 0,<br/>MEDIA_TYPE_VID = 1，<br/>MEDIA_TYPE_SUBTITILE = 2<br/>} | 媒体类型。 |
| [OH_AACProfile](#oh_aacprofile-1) {<br/>AAC_PROFILE_LC = 0,<br/>AAC_PROFILE_HE = 3,<br/>AAC_PROFILE_HE_V2 = 4<br/>} | AAC档次。<!--Del--><br/>（AAC_PROFILE_HE, AAC_PROFILE_HE_V2暂未开放）<!--DelEnd--> | 
| [OH_AVCProfile](#oh_avcprofile-1) {<br/>AVC_PROFILE_BASELINE = 0,<br/>AVC_PROFILE_HIGH = 4,<br/>AVC_PROFILE_MAIN = 8<br/>} | AVC档次。 | 
| [OH_HEVCProfile](#oh_hevcprofile-1) {<br/>HEVC_PROFILE_MAIN = 0,<br/>HEVC_PROFILE_MAIN_10 = 1,<br/>HEVC_PROFILE_MAIN_STILL = 2,<br/>HEVC_PROFILE_MAIN_10_HDR10 = 3,<br/>HEVC_PROFILE_MAIN_10_HDR10_PLUS = 4<br/>} | HEVC档次。<br>HEVC_PROFILE_MAIN_10_HDR10、HEVC_PROFILE_MAIN_10_HDR10_PLUS在API 14废弃。| 
| [OH_VVCProfile](#oh_vvcprofile-1) {<br/>VVC_PROFILE_MAIN_10 = 1, <br/>VVC_PROFILE_MAIN_12 = 2, <br/>VVC_PROFILE_MAIN_12_INTRA = 10, <br/>VVC_PROFILE_MULTI_MAIN_10 = 17, <br/>VVC_PROFILE_MAIN_10_444 = 33, <br/>VVC_PROFILE_MAIN_12_444 = 34, <br/>VVC_PROFILE_MAIN_16_444 = 36, <br/>VVC_PROFILE_MAIN_12_444_INTRA = 42, <br/>VVC_PROFILE_MAIN_16_444_INTRA = 44, <br/>VVC_PROFILE_MULTI_MAIN_10_444 = 49, <br/>VVC_PROFILE_MAIN_10_STILL = 65, <br/>VVC_PROFILE_MAIN_12_STILL = 66, <br/>VVC_PROFILE_MAIN_10_444_STILL = 97, <br/>VVC_PROFILE_MAIN_12_444_STILL = 98, <br/>VVC_PROFILE_MAIN_16_444_STILL = 100 <br/>} | VVC档次。 | 
| [OH_AVOutputFormat](#oh_avoutputformat-1) {<br/>AV_OUTPUT_FORMAT_DEFAULT = 0,<br/>AV_OUTPUT_FORMAT_MPEG_4 = 2,<br/>AV_OUTPUT_FORMAT_M4A = 6,<br/>AV_OUTPUT_FORMAT_AMR = 8,<br/>AV_OUTPUT_FORMAT_MP3 = 9,<br/>AV_OUTPUT_FORMAT_WAV = 10<br/>} | 封装器支持的输出文件格式。 |
| [OH_AVSeekMode](#oh_avseekmode-1) {<br/>SEEK_MODE_NEXT_SYNC = 0,<br/>SEEK_MODE_PREVIOUS_SYNC,<br/>SEEK_MODE_CLOSEST_SYNC<br/>} | 跳转模式。 | 
| [OH_ScalingMode](#oh_scalingmode-1) {<br/>SCALING_MODE_SCALE_TO_WINDOW = 1,<br/>SCALING_MODE_SCALE_CROP = 2<br/>} | 缩放模式。（API14废弃） | 
| [OH_BitsPerSample](#oh_bitspersample-1) {<br/>SAMPLE_U8 = 0, SAMPLE_S16LE = 1,<br/>SAMPLE_S24LE = 2, SAMPLE_S32LE = 3,<br/>SAMPLE_F32LE = 4, SAMPLE_U8P = 5,<br/>SAMPLE_S16P = 6, SAMPLE_S24P = 7,<br/>SAMPLE_S32P = 8, SAMPLE_F32P = 9,<br/>INVALID_WIDTH = -1<br/>} | 每个编码样本的音频位数。 | 
| [OH_ColorPrimary](#oh_colorprimary-1) {<br/>COLOR_PRIMARY_BT709 = 1,<br/>COLOR_PRIMARY_UNSPECIFIED = 2,<br/>COLOR_PRIMARY_BT470_M = 4,<br/>COLOR_PRIMARY_BT601_625 = 5,<br/>COLOR_PRIMARY_BT601_525 = 6,<br/>COLOR_PRIMARY_SMPTE_ST240 = 7,<br/>COLOR_PRIMARY_GENERIC_FILM = 8,<br/>COLOR_PRIMARY_BT2020 = 9,<br/>COLOR_PRIMARY_SMPTE_ST428 = 10,<br/>COLOR_PRIMARY_P3DCI = 11,<br/>COLOR_PRIMARY_P3D65 = 12<br/>} | 色域。 | 
| [OH_TransferCharacteristic](#oh_transfercharacteristic-1) {<br/>TRANSFER_CHARACTERISTIC_BT709 = 1,<br/>TRANSFER_CHARACTERISTIC_UNSPECIFIED = 2,<br/>TRANSFER_CHARACTERISTIC_GAMMA_2_2 = 4,<br/>TRANSFER_CHARACTERISTIC_GAMMA_2_8 = 5,<br/>TRANSFER_CHARACTERISTIC_BT601 = 6,<br/>TRANSFER_CHARACTERISTIC_SMPTE_ST240 = 7,<br/>TRANSFER_CHARACTERISTIC_LINEAR = 8,<br/>TRANSFER_CHARACTERISTIC_LOG = 9,<br/>TRANSFER_CHARACTERISTIC_LOG_SQRT = 10,<br/>TRANSFER_CHARACTERISTIC_IEC_61966_2_4 = 11,<br/>TRANSFER_CHARACTERISTIC_BT1361 = 12,<br/>TRANSFER_CHARACTERISTIC_IEC_61966_2_1 = 13,<br/>TRANSFER_CHARACTERISTIC_BT2020_10BIT = 14,<br/>TRANSFER_CHARACTERISTIC_BT2020_12BIT = 15,<br/>TRANSFER_CHARACTERISTIC_PQ = 16,<br/>TRANSFER_CHARACTERISTIC_SMPTE_ST428 = 17,<br/>TRANSFER_CHARACTERISTIC_HLG = 18<br/>} | 转移特性。 | 
| [OH_MatrixCoefficient](#oh_matrixcoefficient-1) {<br/>MATRIX_COEFFICIENT_IDENTITY = 0,<br/>MATRIX_COEFFICIENT_BT709 = 1,<br/>MATRIX_COEFFICIENT_UNSPECIFIED = 2,<br/>MATRIX_COEFFICIENT_FCC = 4,<br/>MATRIX_COEFFICIENT_BT601_625 = 5,<br/>MATRIX_COEFFICIENT_BT601_525 = 6, MATRIX_COEFFICIENT_SMPTE_ST240 = 7,<br/>MATRIX_COEFFICIENT_YCGCO = 8,<br/>MATRIX_COEFFICIENT_BT2020_NCL = 9,<br/>MATRIX_COEFFICIENT_BT2020_CL = 10,<br/>MATRIX_COEFFICIENT_SMPTE_ST2085 = 11,<br/>MATRIX_COEFFICIENT_CHROMATICITY_NCL = 12,<br/>MATRIX_COEFFICIENT_CHROMATICITY_CL = 13,<br/>MATRIX_COEFFICIENT_ICTCP = 14<br/>} | 矩阵系数。 | 
| [OH_AVCLevel](#oh_avclevel-1) {<br/>AVC_LEVEL_1 = 0, <br/>AVC_LEVEL_1b = 1, <br/>AVC_LEVEL_11 = 2, <br/>AVC_LEVEL_12 = 3,<br/>AVC_LEVEL_13 = 4, <br/>AVC_LEVEL_2 = 5, <br/>AVC_LEVEL_21 = 6, <br/>AVC_LEVEL_22 = 7,<br/>AVC_LEVEL_3 = 8, <br/>AVC_LEVEL_31 = 9, <br/>AVC_LEVEL_32 = 10, <br/>AVC_LEVEL_4 = 11,<br/>AVC_LEVEL_41 = 12, <br/>AVC_LEVEL_42 = 13, <br/>AVC_LEVEL_5 = 14, <br/>AVC_LEVEL_51 = 15, <br/>AVC_LEVEL_52 = 16, <br/>AVC_LEVEL_6 = 17, <br/>AVC_LEVEL_61 = 18, <br/>AVC_LEVEL_62 = 19<br/>} | AVC级别。  | 
| [OH_HEVCLevel](#oh_hevclevel-1) {<br/>HEVC_LEVEL_1 = 0, <br/>HEVC_LEVEL_2 = 1, <br/>HEVC_LEVEL_21 = 2, <br/>HEVC_LEVEL_3 = 3,<br/>HEVC_LEVEL_31 = 4, <br/>HEVC_LEVEL_4 = 5, <br/>HEVC_LEVEL_41 = 6, <br/>HEVC_LEVEL_5 = 7,<br/>HEVC_LEVEL_51 = 8, <br/>HEVC_LEVEL_52 = 9, <br/>HEVC_LEVEL_6 = 10, <br/>HEVC_LEVEL_61 = 11,<br/>HEVC_LEVEL_62 = 12<br/>} | HEVC级别。  | 
| [OH_VVCLevel](#oh_vvclevel-1) {<br/>VVC_LEVEL_1 = 16, <br/>VVC_LEVEL_2 = 32, <br/>VVC_LEVEL_21 = 35, <br/>VVC_LEVEL_3 = 48, <br/>VVC_LEVEL_31 = 51, <br/>VVC_LEVEL_4 = 64, <br/>VVC_LEVEL_41 = 67, <br/>VVC_LEVEL_5 = 80, <br/>VVC_LEVEL_51 = 83, <br/>VVC_LEVEL_52 = 86, <br/>VVC_LEVEL_6 = 96, <br/>VVC_LEVEL_61 = 99, <br/>VVC_LEVEL_62 = 102, <br/>VVC_LEVEL_63 = 105, <br/>VVC_LEVEL_155 = 255<br/>} | VVC级别。  | 
| [OH_TemporalGopReferenceMode](#oh_temporalgopreferencemode-1) { <br/>ADJACENT_REFERENCE = 0, <br/>JUMP_REFERENCE = 1, <br/>UNIFORMLY_SCALED_REFERENCE = 2 <br/>} | 时域图片组参考模式。  | 
| [OH_BitrateMode](#oh_bitratemode-1) { <br/>BITRATE_MODE_CBR = 0, <br/>BITRATE_MODE_VBR = 1, <br/>BITRATE_MODE_CQ = 2 } | 编码器的比特率模式。  |

### 变量

| 名称 | 描述 | 
| -------- | -------- |
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_AAC](#oh_avcodec_mimetype_audio_aac) | AAC音频编解码器的MIME类型。 |
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_FLAC](#oh_avcodec_mimetype_audio_flac) | FLAC音频编解码器的MIME类型。 |
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_OPUS](#oh_avcodec_mimetype_audio_opus) | OPUS音频编解码器的MIME类型。<!--Del-->（此规格暂未开放）<!--DelEnd-->  |
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_G711MU](#oh_avcodec_mimetype_audio_g711mu) | G711MU音频编解码器的MIME类型。 |
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_VORBIS](#oh_avcodec_mimetype_audio_vorbis) | VORBIS音频解码器的MIME类型。 |
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_MPEG](#oh_avcodec_mimetype_audio_mpeg) | MP3音频解码器的MIME类型。 |
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_VIVID](#oh_avcodec_mimetype_audio_vivid) | Audio Vivid音频解码器的MIME类型。<!--Del-->（此规格暂未开放）<!--DelEnd-->  |
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_AMR_NB](#oh_avcodec_mimetype_audio_amr_nb) | AMR_NB音频解码器的MIME类型。 |
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_AMR_WB](#oh_avcodec_mimetype_audio_amr_wb) | AMR_WB音频解码器的MIME类型。 |
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_APE](#oh_avcodec_mimetype_audio_ape) |APE音频解码器的MIME类型。                         |
| const char \* [OH_AVCODEC_MIMETYPE_VIDEO_VVC](#oh_avcodec_mimetype_video_vvc) | VVC(H.266)视频编解码器的MIME类型。 |
| const char \* [OH_AVCODEC_MIMETYPE_VIDEO_HEVC](#oh_avcodec_mimetype_video_hevc) | HEVC(H.265)视频编解码器的MIME类型。 |
| const char \* [OH_AVCODEC_MIMETYPE_VIDEO_AVC](#oh_avcodec_mimetype_video_avc) | AVC(H.264)视频编解码器的MIME类型。 |
| const char \* [OH_AVCODEC_MIMETYPE_VIDEO_MPEG4](#oh_avcodec_mimetype_video_mpeg4) | MPEG4视频编码的MIME类型，仅用于封装MPEG4视频码流使用。（API11废弃） |
| const char \* [OH_AVCODEC_MIMETYPE_IMAGE_JPG](#oh_avcodec_mimetype_image_jpg) | JPG图片编码的MIME类型，仅用于封装JPG封面时使用。 |
| const char \* [OH_AVCODEC_MIMETYPE_IMAGE_PNG](#oh_avcodec_mimetype_image_png) | PNG图片编码的MIME类型，仅用于封装PNG封面时使用。 |
| const char \* [OH_AVCODEC_MIMETYPE_IMAGE_BMP](#oh_avcodec_mimetype_image_bmp) | BMP图片编码的MIME类型，仅用于封装BMP封面时使用。 |
| const char \* [OH_AVCODEC_MIMETYPE_SUBTITLE_WEBVTT](#oh_avcodec_mimetype_subtitle_webvtt) |WEBVTT字幕解封装器的MIME类型。                 |
| const char \* [OH_AVCODEC_MIMETYPE_SUBTITLE_SRT](#oh_avcodec_mimetype_subtitle_srt) |SRT字幕解封装器的MIME类型。                         |
| const char \* [OH_FEATURE_PROPERTY_KEY_VIDEO_ENCODER_MAX_LTR_FRAME_COUNT](#oh_feature_property_key_video_encoder_max_ltr_frame_count) | 在视频编码中获取长期参考帧的最大个数的键，值类型为int32_t。  |
| const char \* [OH_MD_KEY_CODEC_CONFIG](#oh_md_key_codec_config) | 编解码器特定数据的键，视频中表示传递SPS/PPS，音频中表示传递extraData，值类型为uint8_t\*。 <!--Del-->（视频编解码此功能暂未支持）<!--DelEnd--> |
| const char \* [OH_MD_MAX_INPUT_BUFFER_COUNT](#oh_md_max_input_buffer_count) | 最大输入缓冲区个数的键，值类型为int32_t。 |
| const char \* [OH_MD_MAX_OUTPUT_BUFFER_COUNT](#oh_md_max_output_buffer_count) | 最大输出缓冲区个数的键，值类型int32_t。 |
| const char \* [OH_MD_KEY_BITRATE](#oh_md_key_bitrate) | 比特率的键，值类型为int64_t。 |
| const char \* [OH_MD_KEY_PROFILE](#oh_md_key_profile) | 编码档次，值类型为int32_t，请参见[OH_AVCProfile](#oh_avcprofile)，[OH_HEVCProfile](#oh_hevcprofile)，[OH_AACProfile](#oh_aacprofile)。 |
| const char \* [OH_MD_KEY_MAX_INPUT_SIZE](#oh_md_key_max_input_size) | 设置解码输入码流大小最大值的键，值类型为int32_t。 |
| const char \* [OH_ED_KEY_TIME_STAMP](#oh_ed_key_time_stamp) | 表示surfacebuffer时间戳的键，值类型为int64_t。（API14废弃）|
| const char \* [OH_ED_KEY_EOS](#oh_ed_key_eos) | 表示surfacebuffer流结束符的键，值类型为int32_t。（API14废弃）|
| const char \* [OH_MD_KEY_WIDTH](#oh_md_key_width) | 视频宽度的键，值类型为int32_t。 |
| const char \* [OH_MD_KEY_HEIGHT](#oh_md_key_height) | 视频高度键，值类型为int32_t。 |
| const char \* [OH_MD_KEY_PIXEL_FORMAT](#oh_md_key_pixel_format) | 视频像素格式的键，值类型为int32_t，请参见[OH_AVPixelFormat](_core.md#oh_avpixelformat)。 |
| const char \* [OH_MD_KEY_FRAME_RATE](#oh_md_key_frame_rate) | 视频帧率的键，值类型为double。 |
| const char \* [OH_MD_KEY_ROTATION](#oh_md_key_rotation) | surface旋转角度的键。值类型为int32_t：应为{0, 90, 180, 270}，默认值为0。该键只在视频解码Surface模式下使用。 |
| const char \* [OH_MD_KEY_RANGE_FLAG](#oh_md_key_range_flag) | 视频YUV值域标志的键，值类型为int32_t，1表示full range，0表示limited range。 |
| const char \* [OH_MD_KEY_COLOR_PRIMARIES](#oh_md_key_color_primaries) | 视频色域的键，值类型为int32_t，请参见[OH_ColorPrimary](#oh_colorprimary)，遵循H.273标准Table2。 |
| const char \* [OH_MD_KEY_TRANSFER_CHARACTERISTICS](#oh_md_key_transfer_characteristics) | 视频传递函数的键，值类型为int32_t，请参见[OH_TransferCharacteristic](#oh_transfercharacteristic)，遵循H.273标准Table3。 |
| const char \* [OH_MD_KEY_MATRIX_COEFFICIENTS](#oh_md_key_matrix_coefficients) | 视频矩阵系数的键，值类型为int32_t，请参见[OH_MatrixCoefficient](#oh_matrixcoefficient)，遵循H.273标准Table4。 |
| const char \* [OH_MD_KEY_SCALING_MODE](#oh_md_key_scaling_mode) | 视频缩放模式，值类型为int32_t，请参见[OH_ScalingMode](#oh_scalingmode)。该键是可选的且只用于视频解码Surface模式。建议直接调用[OH_NativeWindow_NativeWindowSetScalingModeV2](../apis-arkgraphics2d/_native_window.md#oh_nativewindow_nativewindowsetscalingmodev2)接口进行设置。（API14废弃）|
| const char \* [OH_MD_KEY_VIDEO_CROP_TOP](#oh_md_key_video_crop_top) | 描述裁剪矩形顶部坐标(y)值的键，值类型为int32_t。  | 
| const char \* [OH_MD_KEY_VIDEO_CROP_BOTTOM](#oh_md_key_video_crop_bottom) | 描述裁剪矩形底部坐标(y)值的键，值类型为int32_t。  | 
| const char \* [OH_MD_KEY_VIDEO_CROP_LEFT](#oh_md_key_video_crop_left) | 描述裁剪矩形左坐标(x)值的键，值类型为int32_t。  | 
| const char \* [OH_MD_KEY_VIDEO_CROP_RIGHT](#oh_md_key_video_crop_right) | 描述裁剪矩形右坐标(x)值的键，值类型为int32_t。 | 
| const char \* [OH_MD_KEY_VIDEO_DECODER_OUTPUT_ENABLE_VRR](#oh_md_key_video_decoder_output_enable_vrr) | 解码器是否打开视频可变帧率功能的键，值类型为int32_t。 |
| const char \* [OH_MD_KEY_VIDEO_STRIDE](#oh_md_key_video_stride) | 描述视频帧宽跨距的键，值类型为int32_t。本。  | 
| const char \* [OH_MD_KEY_VIDEO_SLICE_HEIGHT](#oh_md_key_video_slice_height) | 描述视频帧高跨距的键，值类型为int32_t。  | 
| const char \* [OH_MD_KEY_VIDEO_PIC_WIDTH](#oh_md_key_video_pic_width) | 描述视频帧真实宽度的键，值类型为int32_t。  | 
| const char \* [OH_MD_KEY_VIDEO_PIC_HEIGHT](#oh_md_key_video_pic_height) | 描述视频帧真实高度的键，值类型为int32_t。  | 
| const char \* [OH_MD_KEY_VIDEO_ENABLE_LOW_LATENCY](#oh_md_key_video_enable_low_latency) | 使能低时延视频编解码的键，值类型为int32_t，1表示使能，0表示其它情况。如果使能，则视频编码器或视频解码器持有的输入和输出数据不会超过编解码器标准所要求的数量。   | 
| const char \* [OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE](#oh_md_key_video_encode_bitrate_mode) | 视频编码码率模式，值类型为int32_t，请参见[OH_BitrateMode](#oh_bitratemode-1)。 |
| const char \* [OH_MD_KEY_QUALITY](#oh_md_key_quality) | 所需编码质量的键。值类型为int32_t，此键仅适用于配置在恒定质量模式下的编码器。 |
| const char \* [OH_MD_KEY_REQUEST_I_FRAME](#oh_md_key_request_i_frame) | 请求立即编码I帧的键。值类型为int32_t。 |
| const char \* [OH_MD_KEY_I_FRAME_INTERVAL](#oh_md_key_i_frame_interval) | 关键帧间隔的键，值类型为int32_t，单位为毫秒。该键是可选的且只用于视频编码。 |
| const char \* [OH_MD_KEY_VIDEO_ENCODER_ENABLE_TEMPORAL_SCALABILITY](#oh_md_key_video_encoder_enable_temporal_scalability) | 使能分层编码的键，值类型为int32_t，1表示使能，0表示其它情况。  | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_SIZE](#oh_md_key_video_encoder_temporal_gop_size) | 描述图片组基本层图片的间隔大小的键，值类型为int32_t，只在使能分层编码时生效。  |
| const char \* [OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_REFERENCE_MODE](#oh_md_key_video_encoder_temporal_gop_reference_mode) | 描述图片组内参考模式的键，值类型为int32_t，请参见[OH_TemporalGopReferenceMode](#oh_temporalgopreferencemode)，只在使能分层编码时生效。  | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_LTR_FRAME_COUNT](#oh_md_key_video_encoder_ltr_frame_count) | 描述长期参考帧个数的键，值类型为int32_t，必须在支持的值范围内使用。该键是可选的且只用于视频编码。  | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_MARK_LTR](#oh_md_key_video_encoder_per_frame_mark_ltr) | 标记当前帧为长期参考帧的键，值类型为int32_t，1表示被标记，0表示其它情况。该键是可选的且只用于视频编码。  | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_USE_LTR](#oh_md_key_video_encoder_per_frame_use_ltr) | 描述当前帧参考的长期参考帧帧的POC号的键，值类型为int32_t。该键是可选的且只用于视频编码。  |
| const char \* [OH_MD_KEY_VIDEO_PER_FRAME_IS_LTR](#oh_md_key_video_per_frame_is_ltr) | 当前OH_AVBuffer中输出的码流对应的帧是否为长期参考帧的键，值类型为int32_t，1表示是LTR，0表示其它情况。该键是可选的且只用于视频编码。  | 
| const char \* [OH_MD_KEY_VIDEO_PER_FRAME_POC](#oh_md_key_video_per_frame_poc) | 描述帧的POC号的键，值类型为int32_t。该键是可选的且只用于视频编码。  | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_QP_MAX](#oh_md_key_video_encoder_qp_max) | 描述视频编码器允许的最大量化参数的键，值类型为int32_t。  | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_QP_MIN](#oh_md_key_video_encoder_qp_min) | 描述视频编码器允许的最小量化参数的键，值类型为int32_t。  | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_QP_AVERAGE](#oh_md_key_video_encoder_qp_average) | 描述视频帧平均量化参数的键，值类型为int32_t。 |
| const char \* [OH_MD_KEY_VIDEO_ENCODER_MSE](#oh_md_key_video_encoder_mse)     |描述视频帧平方误差的键，值类型为double。  |
| const char \* [OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER](#oh_md_key_video_encoder_repeat_previous_frame_after)    | 如果在上一帧提交给编码器之后没有新的帧可用，则会以毫秒为单位重复提交最后一帧，值类型为int32_t。 |
| const char \* [OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_MAX_COUNT](#oh_md_key_video_encoder_repeat_previous_max_count)    | 描述编码器在没有新的帧可用的情况下，可以对之前的帧进行重复编码的最大次数，值类型为int32_t。|
| const char \* [OH_MD_KEY_VIDEO_DECODER_OUTPUT_COLOR_SPACE](#oh_md_key_video_decoder_output_color_space)   | 设置视频解码器输出色彩空间的键，值类型为int32_t。 支持的值为OH_COLORSPACE_BT709_LIMIT。|
| const char \* [OH_MD_KEY_AUDIO_SAMPLE_FORMAT](#oh_md_key_audio_sample_format) | 音频原始格式的键，值类型为int32_t。请参见[OH_BitsPerSample](#oh_bitspersample-1)。 |
| const char \* [OH_MD_KEY_AUD_CHANNEL_COUNT](#oh_md_key_aud_channel_count) | 音频通道计数键，值类型为int32_t。 |
| const char \* [OH_MD_KEY_AUD_SAMPLE_RATE](#oh_md_key_aud_sample_rate) | 音频采样率键，值类型为int32_t。 |
| const char \* [OH_MD_KEY_AUDIO_COMPRESSION_LEVEL](#oh_md_key_audio_compression_level) | 音频编解码压缩水平的键，只在音频编码使用，值类型为int32_t。 |
| const char \* [OH_MD_KEY_CHANNEL_LAYOUT](#oh_md_key_channel_layout) | 所需编码通道布局的键。值类型为int64_t，此键仅适用于编码器。 |
| const char \* [OH_MD_KEY_BITS_PER_CODED_SAMPLE](#oh_md_key_bits_per_coded_sample) | 每个编码样本位数的键，值类型为int32_t，支持flac编码器，请参见[OH_BitsPerSample](#oh_bitspersample-1)。 |
| const char \* [OH_MD_KEY_SBR](#oh_md_key_sbr) | aac sbr模式的键，值类型为int32_t，aac编码器支持。 |
| const char \* [OH_MD_KEY_COMPLIANCE_LEVEL](#oh_md_key_compliance_level) | flac兼容性等级的键，值类型为int32_t，仅在音频编码使用。 |
| const char \* [OH_MD_KEY_AAC_IS_ADTS](#oh_md_key_aac_is_adts) | aac格式的键，aac格式分为ADTS格式和LATM格式。值类型为int32_t，aac解码器支持。 |
| const char \* [OH_MD_KEY_IDENTIFICATION_HEADER](#oh_md_key_identification_header) | vorbis标识头的键，值类型为uint8_t\*，仅vorbis解码器支持。 |
| const char \* [OH_MD_KEY_SETUP_HEADER](#oh_md_key_setup_header) | vorbis设置头的键，值类型为uint8_t\*，仅vorbis解码器支持。 |
| const char \* [OH_MD_KEY_AUDIO_OBJECT_NUMBER](#oh_md_key_audio_object_number) | 音频对象数目的键，值类型为int32_t，只有Audio Vivid解码使用。 |
| const char \* [OH_MD_KEY_AUDIO_VIVID_METADATA](#oh_md_key_audio_vivid_metadata) | Audio Vivid元数据的键，值类型为uint8_t\*，只有Audio Vivid解码使用。 |
| const char \* [OH_MD_KEY_VIDEO_IS_HDR_VIVID](#oh_md_key_video_is_hdr_vivid) | 媒体文件中的视频轨是否为HDR Vivid的键，支持封装和解封装，值类型为int32_t。 |
| const char \* [OH_MD_KEY_START_TIME](#oh_md_key_start_time) | 媒体文件中第一帧起始位置开始时间的键，以微秒为单位，值类型为int64_t。     |
| const char \* [OH_MD_KEY_TRACK_START_TIME](#oh_md_key_track_start_time) | 轨道开始时间的键，以微秒为单位，值类型为int64_t。     |
| const char \* [OH_MD_KEY_TRACK_TYPE](#oh_md_key_track_type) | 轨道媒体类型的键，值类型为int32_t，请参见[OH_MediaType](#oh_mediatype-1)。 |
| const char \* [OH_MD_KEY_DURATION](#oh_md_key_duration) | 媒体文件持续时间的键，值类型为int64_t。 |
| const char \* [OH_MD_KEY_TITLE](#oh_md_key_title) | 媒体文件标题的键，值类型为string。 |
| const char \* [OH_MD_KEY_ARTIST](#oh_md_key_artist) | 媒体文件艺术家的键，值类型为string。 |
| const char \* [OH_MD_KEY_ALBUM](#oh_md_key_album) | 专辑的媒体文件的键，值类型为string。 |
| const char \* [OH_MD_KEY_ALBUM_ARTIST](#oh_md_key_album_artist) | 专辑艺术家的键，值类型为string。 |
| const char \* [OH_MD_KEY_DATE](#oh_md_key_date) | 媒体文件日期的键，值类型为string，例如2024年。 |
| const char \* [OH_MD_KEY_COMMENT](#oh_md_key_comment) | 媒体文件注释的键，值类型为string。 |
| const char \* [OH_MD_KEY_GENRE](#oh_md_key_genre) | 媒体文件流派的键，值类型为string。 |
| const char \* [OH_MD_KEY_COPYRIGHT](#oh_md_key_copyright) | 媒体文件版权的键，值类型为string。 |
| const char \* [OH_MD_KEY_LANGUAGE](#oh_md_key_language) | 媒体文件语言的键，值类型为string。 |
| const char \* [OH_MD_KEY_DESCRIPTION](#oh_md_key_description) | 媒体文件描述的键，值类型为string。 |
| const char \* [OH_MD_KEY_LYRICS](#oh_md_key_lyrics) | 媒体文件歌词的键，值类型为string。 |
| const char \* [OH_MD_KEY_TRACK_COUNT](#oh_md_key_track_count) | 媒体文件轨道数量的键，值类型为int32_t。 |
| const char \* [OH_MD_KEY_BUFFER_DURATION](#oh_md_key_buffer_duration) | AVBuffer中携带的音视频或字幕的sample对应的持续时间的键，以微秒为单位，值类型为int64_t。       |
| const char \* [OH_MD_KEY_DECODING_TIMESTAMP](#oh_md_key_decoding_timestamp) | AVBuffer中携带的音视频或字幕的sample对应的解码时间戳的键，以微秒为单位，值类型为int64_t。  |
| const char \* [OH_MD_KEY_CODEC_MIME](#oh_md_key_codec_mime) | 编解码器[MIME](#媒体编解码格式)类型的键，值类型为string。 |
| const char \* [OH_MD_KEY_VIDEO_SAR](#oh_md_key_video_sar) | 样本长宽比的键，值类型为double。 |
| const char \* [OH_MD_KEY_CREATION_TIME](#oh_md_key_creation_time) | 媒体文件创建时间的元数据，值类型为string。 |


## 类型定义说明


### OH_AACProfile

```
typedef enum OH_AACProfile OH_AACProfile
```
**描述**
AAC档次。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9


### OH_AVCLevel

```
typedef enum OH_AVCLevel OH_AVCLevel
```
**描述**
AVC级别。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_AVCodec

```
typedef struct OH_AVCodec OH_AVCodec
```
**描述**
为音视频编解码接口定义native层对象。

**起始版本：** 9


### OH_AVCodecAsyncCallback

```
typedef struct OH_AVCodecAsyncCallback OH_AVCodecAsyncCallback
```
**描述**
OH_AVCodec中所有异步回调函数指针的集合。将该结构体的实例注册到OH_AVCodec实例中， 并处理回调上报的信息，以保证OH_AVCodec的正常运行。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9

**废弃版本：** 11

**替代接口：**[OH_AVCodecCallback](#oh_avcodeccallback)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| onError | 监控编解码器操作错误，请参见[OH_AVCodecOnError](#oh_avcodeconerror)。 | 
| onStreamChanged | 监控编解码器流变化，请参见[OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged)。 | 
| onNeedInputData | 监控编解码器需要输入数据，请参见[OH_AVCodecOnNeedInputData](#oh_avcodeconneedinputdata)。 | 
| onNeedOutputData | 监控编解码器已生成输出数据，请参见[OH_AVCodecOnNewOutputData](#oh_avcodeconnewoutputdata)。 | 


### OH_AVCodecCallback

```
typedef struct OH_AVCodecCallback OH_AVCodecCallback
```
**描述**
OH_AVCodec中所有异步回调函数指针的集合。将该结构体的实例注册到OH_AVCodec实例中， 并处理回调上报的信息，以保证OH_AVCodec的正常运行。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| onError | 监控编解码器操作错误，请参见[OH_AVCodecOnError](#oh_avcodeconerror)。 | 
| onStreamChanged | 监控编解码器流变化，请参见[OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged)。 | 
| onNeedInputBuffer | 监控编解码器需要输入数据，请参见[OH_AVCodecOnNeedInputBuffer](#oh_avcodeconneedinputbuffer)。 | 
| onNewOutputBuffer | 监控编解码器已生成输出数据，请参见[OH_AVCodecOnNewOutputBuffer](#oh_avcodeconnewoutputbuffer)。 | 


### OH_AVCodecOnError

```
typedef void(* OH_AVCodecOnError) (OH_AVCodec *codec, int32_t errorCode, void *userData)
```
**描述**
当OH_AVCodec实例运行出错时，回调将上报具体的错误信息的函数指针。

| 使用场景| 错误码 |
| -------- | -------- |
| 音频编解码 | AV_ERR_DRM_DECRYPT_FAILED：DRM解密失败。  |
| 视频编解码 | AV_ERROR_NO_MEMORY：系统资源不足。<br>AV_ERROR_UNKNOWN：未知错误，请通过具体日志分析。<br>AV_ERR_SERVICE_DIED：服务状态已消亡。  |
| 视频解码 | AV_ERR_VIDEO_UNSUPPORTED_COLOR_SPACE_CONVERSION：当前输入不支持色彩空间转换功能。  |
<!--RP1--><!--RP1End-->

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| codec | OH_AVCodec实例。  | 
| errorCode | 特定错误代码。在不同场景下返回的错误码不同，详情可见上述描述中的表格。  | 
| userData | 用户执行回调所依赖的数据。  |


### OH_AVCodecOnNeedInputBuffer

```
typedef void(* OH_AVCodecOnNeedInputBuffer) (OH_AVCodec *codec, uint32_t index, OH_AVBuffer *buffer, void *userData)
```
**描述**
当OH_AVCodec在运行过程中需要新的输入数据时，将调用此函数指针，并携带可用的缓冲区来填充新的输入数据。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| codec | OH_AVCodec实例。  | 
| index | 与新可用的输入缓冲区相对应的索引。  | 
| buffer | 新的可用输入缓冲区。  | 
| userData | 用户执行回调所依赖的数据。  | 


### OH_AVCodecOnNeedInputData

```
typedef void(* OH_AVCodecOnNeedInputData) (OH_AVCodec *codec, uint32_t index, OH_AVMemory *data, void *userData)
```
**描述**
当OH_AVCodec在运行过程中需要新的输入数据时，将调用此函数指针，并携带可用的缓冲区来填充新的输入数据。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9

**废弃版本：** 11

**替代接口：**[OH_AVCodecOnNeedInputBuffer](#oh_avcodeconneedinputbuffer)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| codec | OH_AVCodec实例。  | 
| index | 与新可用的输入缓冲区相对应的索引。  | 
| data | 新的可用输入缓冲区。  | 
| userData | 用户执行回调所依赖的数据。  | 


### OH_AVCodecOnNewOutputBuffer

```
typedef void(* OH_AVCodecOnNewOutputBuffer) (OH_AVCodec *codec, uint32_t index, OH_AVBuffer *buffer, void *userData)
```
**描述**
当OH_AVCodec运行过程中生成新的输出数据时，将调用此函数指针，并携带包含新输出数据的缓冲区。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| codec | OH_AVCodec实例。  | 
| index | 与新输出缓冲区对应的索引。  | 
| buffer | 包含新输出数据的缓冲区。  | 
| userData | 用户执行回调所依赖的数据。  | 


### OH_AVCodecOnNewOutputData

```
typedef void(* OH_AVCodecOnNewOutputData) (OH_AVCodec *codec, uint32_t index, OH_AVMemory *data, OH_AVCodecBufferAttr *attr, void *userData)
```
**描述**
当OH_AVCodec运行过程中生成新的输出数据时，将调用此函数指针，并携带包含新输出数据的缓冲区。 需要注意的是，OH_AVCodecBufferAttr指针的生命周期仅在调用函数指针时有效，这将禁止调用结束后继续访问。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9

**废弃版本：** 11

**替代接口：**[OH_AVCodecOnNewOutputBuffer](#oh_avcodeconnewoutputbuffer)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| codec | OH_AVCodec实例。  | 
| index | 与新输出缓冲区对应的索引。  | 
| data | 包含新输出数据的缓冲区。  | 
| attr | 新输出缓冲区的说明，请参见[OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md)。  | 
| userData | 用户执行回调所依赖的数据。  | 


### OH_AVCodecOnStreamChanged

```
typedef void(* OH_AVCodecOnStreamChanged) (OH_AVCodec *codec, OH_AVFormat *format, void *userData)
```
**描述**
当视频解码输入码流分辨率或者视频编码输出码流的分辨率发生变化时，调用此函数指针报告新的流描述信息。<br>从API 15开始，支持音频解码时，码流采样率、声道数或者音频采样格式发生变化时，将调用此函数指针报告新的流描述信息，支持检测此变化的解码格式有：<!--RP3--><!--RP3End-->AAC，FLAC，MP3，VORBIS。<br>需要注意的是，OH_AVFormat指针的生命周期只有在函数指针被调用时才有效，调用结束后禁止继续访问。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| codec | OH_AVCodec实例。  |
| format | 新输出流描述信息。  |
| userData | 用户执行回调所依赖的数据。  |


### OH_AVCProfile

```
typedef enum OH_AVCProfile OH_AVCProfile
```
**描述**
AVC档次。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9


### OH_AVDataSource

```
typedef struct OH_AVDataSource OH_AVDataSource
```
**描述**
用户自定义数据源。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_AVDataSourceReadAt

```
typedef int32_t(* OH_AVDataSourceReadAt) (OH_AVBuffer *data, int32_t length, int64_t pos)
```
**描述**
函数指针定义，用于提供获取用户自定义媒体数据的能力。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| data | 要填充的缓冲区。  | 
| length | 要读取的数据长度。  | 
| pos | 从偏移量位置读取。  | 

**返回：**

读取到缓冲区的数据的实际长度。


### OH_AVOutputFormat

```
typedef enum OH_AVOutputFormat OH_AVOutputFormat
```
**描述**
封装器支持的输出文件格式。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_AVSeekMode

```
typedef enum OH_AVSeekMode OH_AVSeekMode
```
**描述**
跳转模式。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_BitsPerSample

```
typedef enum OH_BitsPerSample OH_BitsPerSample
```
**描述**
每个编码样本的音频位数。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_ColorPrimary

```
typedef enum OH_ColorPrimary OH_ColorPrimary
```
**描述**
色域。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_HEVCLevel

```
typedef enum OH_HEVCLevel OH_HEVCLevel
```
**描述**
HEVC级别。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_HEVCProfile

```
typedef enum OH_HEVCProfile OH_HEVCProfile
```
**描述**
HEVC档次。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MatrixCoefficient

```
typedef enum OH_MatrixCoefficient OH_MatrixCoefficient
```
**描述**
矩阵系数。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MediaType

```
typedef enum OH_MediaType OH_MediaType
```
**描述**
媒体类型。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9


### OH_ScalingMode

```
typedef enum OH_ScalingMode OH_ScalingMode
```
**描述**
缩放模式，只在Surface模式下使用。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**废弃版本：** 14 

**替代接口：**[OHScalingModeV2](../apis-arkgraphics2d/_native_window.md#ohscalingmodev2-1)


### OH_TemporalGopReferenceMode

```
typedef enum OH_TemporalGopReferenceMode OH_TemporalGopReferenceMode
```
**描述**
时域图片组参考模式。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12

### OH_VVCLevel

```
typedef enum OH_VVCLevel OH_VVCLevel
```
**描述**
VVC级别。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 14


### OH_VVCProfile

```
typedef enum OH_VVCProfile OH_VVCProfile
```
**描述**
VVC档次。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 14


### OH_TransferCharacteristic

```
typedef enum OH_TransferCharacteristic OH_TransferCharacteristic
```
**描述**
转移特性。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_BitrateMode

```
typedef enum OH_BitrateMode OH_BitrateMode
```
**描述**
编码器的比特率模式。从API14开始改变key的位置。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OHNativeWindow

```
typedef struct NativeWindow OHNativeWindow
```
**描述**
为图形接口定义native层对象。

**起始版本：** 9


## 枚举类型说明


### AudioChannelLayout

```
enum AudioChannelLayout : uint64_t
```

**描述**
音频声道数类型，将用户申请的解码器输出格式表示为编解码器的声道类型。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**废弃版本：** 11

**替代接口：**[OH_AudioChannelLayout](_core.md#oh_audiochannellayout)

| 枚举值 | 描述 | 
| -------- | -------- |
| UNKNOWN_CHANNEL_LAYOUT | 未知通道布局 | 
| MONO | 单通道布局 | 
| STEREO | 立体声布局 | 
| CH_2POINT1 | 2.1布局 | 
| CH_2_1 | 2_1布局 | 
| SURROUND | 环绕布局 | 
| CH_3POINT1 | 3.1布局 | 
| CH_4POINT0 | 4.0布局 | 
| CH_4POINT1 | 4.1布局 | 
| CH_2_2 | 2_2布局 | 
| QUAD | 四角形布局 | 
| CH_5POINT0 | 5.0布局 | 
| CH_5POINT1 | 5.1布局 | 
| CH_5POINT0_BACK | 5.0后置布局 | 
| CH_5POINT1_BACK | 5.1后置布局 | 
| CH_6POINT0 | 6.0布局 | 
| CH_6POINT0_FRONT | 6.0前置布局 | 
| HEXAGONAL | 六角形布局 | 
| CH_6POINT1 | 6.1布局 | 
| CH_6POINT1_BACK | 6.1后置布局 | 
| CH_6POINT1_FRONT | 6.1前置布局 | 
| CH_7POINT0 | 7.0布局 | 
| CH_7POINT0_FRONT | 7.0前置布局 | 
| CH_7POINT1 | 7.1布局 | 
| CH_7POINT1_WIDE | 7.1宽布局 | 
| CH_7POINT1_WIDE_BACK | 7.1后置宽布局 | 
| CH_3POINT1POINT2 | 3.1.2布局 | 
| CH_5POINT1POINT2 | 5.1.2布局 | 
| CH_5POINT1POINT4 | 5.1.4布局 | 
| CH_7POINT1POINT2 | 7.1.2布局 | 
| CH_7POINT1POINT4 | 7.1.4布局 | 
| CH_9POINT1POINT4 | 9.1.4布局 | 
| CH_9POINT1POINT6 | 9.1.6布局 | 
| CH_10POINT2 | 10.2布局 | 
| CH_22POINT2 | 22.2布局 | 
| OCTAGONAL | 八边形布局 | 
| HEXADECAGONAL | 十六边形布局 | 
| STEREO_DOWNMIX | 立体声下混布局 | 
| HOA_FIRST | 高阶立体声一阶布局 | 
| HOA_SECOND | 高阶立体声二阶布局 | 
| HOA_THIRD | 高阶立体声三阶布局 | 


### AudioChannelSet

```
enum AudioChannelSet : uint64_t
```

**描述**
音频声道数集合， 将每一个声道数映射为int64_t的变量。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**废弃版本：** 11

**替代接口：**[OH_AudioChannelSet](_core.md#oh_audiochannelset)

| 枚举值 | 描述 | 
| -------- | -------- |
| FRONT_LEFT | 左前声道 | 
| FRONT_RIGHT | 右前声道 | 
| FRONT_CENTER | 中前声道 | 
| LOW_FREQUENCY | 低频声道 | 
| BACK_LEFT | 左后声道 | 
| BACK_RIGHT | 右后声道 | 
| FRONT_LEFT_OF_CENTER | 左前中置声道 | 
| FRONT_RIGHT_OF_CENTER | 右前中置声道 | 
| BACK_CENTER | 后方中置声道 | 
| SIDE_LEFT | 左侧声道 | 
| SIDE_RIGHT | 右侧声道 | 
| TOP_CENTER | 上方中置声道 | 
| TOP_FRONT_LEFT | 上方左前声道 | 
| TOP_FRONT_CENTER | 上方中前声道 | 
| TOP_FRONT_RIGHT | 上方右前声道 | 
| TOP_BACK_LEFT | 上方左后声道 | 
| TOP_BACK_CENTER | 上方中后声道 | 
| TOP_BACK_RIGHT | 上方右后声道 | 
| STEREO_LEFT | 立体声左声道 | 
| STEREO_RIGHT | 立体声右声道 | 
| WIDE_LEFT | 宽左声道 | 
| WIDE_RIGHT | 宽右声道 | 
| SURROUND_DIRECT_LEFT | 左环绕声道 | 
| SURROUND_DIRECT_RIGHT | 右环绕声道 | 
| LOW_FREQUENCY_2 | 低频声道2 | 
| TOP_SIDE_LEFT | 上方左侧声道 | 
| TOP_SIDE_RIGHT | 上方右侧声道 | 
| BOTTOM_FRONT_CENTER | 下方中前声道 | 
| BOTTOM_FRONT_LEFT | 下方左前声道 | 
| BOTTOM_FRONT_RIGHT | 下方右前声道 | 
| AMBISONICS_ACN0 | 零阶立体声声道数 0 | 
| AMBISONICS_ACN1 | 一阶立体声声道数 1 | 
| AMBISONICS_ACN2 | 一阶立体声声道数 2 | 
| AMBISONICS_ACN3 | 一阶立体声声道数 3 | 
| AMBISONICS_W | 同于零阶立体声声道数 0 | 
| AMBISONICS_Y | 同于一阶立体声声道数 1 | 
| AMBISONICS_Z | 同于一阶立体声声道数 2 | 
| AMBISONICS_X | 同于一阶立体声声道数 3 | 
| AMBISONICS_ACN4 | 二阶立体声声道数 4 | 
| AMBISONICS_ACN5 | 二阶立体声声道数 5 | 
| AMBISONICS_ACN6 | 二阶立体声声道数 6 | 
| AMBISONICS_ACN7 | 二阶立体声声道数 7 | 
| AMBISONICS_ACN8 | 二阶立体声声道数 8 | 
| AMBISONICS_ACN9 | 三阶立体声声道数 9 | 
| AMBISONICS_ACN10 | 三阶立体声声道数 10 | 
| AMBISONICS_ACN11 | 三阶立体声声道数 11 | 
| AMBISONICS_ACN12 | 三阶立体声声道数 12 | 
| AMBISONICS_ACN13 | 三阶立体声声道数 13 | 
| AMBISONICS_ACN14 | 三阶立体声声道数 14 | 
| AMBISONICS_ACN15 | 三阶立体声声道数 15 | 


### OH_AACProfile

```
enum OH_AACProfile
```
**描述**
AAC档次。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9

| 枚举值 | 描述 | 
| -------- | -------- |
| AAC_PROFILE_LC  | AAC编码档次为Low Complexity级别。   | 
| AAC_PROFILE_HE  | AAC编码档次为High Efficiency级别。<!--Del-->（此规格暂未开放）<!--DelEnd--> <br>**起始版本：** 14 | 
| AAC_PROFILE_HE_V2 | AAC编码档次为High Efficiency v2级别。<!--Del-->（此规格暂未开放）<!--DelEnd--> <br>**起始版本：** 14 | 


### OH_AVCLevel

```
enum OH_AVCLevel
```
**描述**
AVC级别。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| AVC_LEVEL_1  | 级别1   | 
| AVC_LEVEL_1b  | 级别1b   | 
| AVC_LEVEL_11  | 级别1.1   | 
| AVC_LEVEL_12  | 级别1.2   | 
| AVC_LEVEL_13  | 级别1.3   | 
| AVC_LEVEL_2  | 级别2   | 
| AVC_LEVEL_21  | 级别2.1   | 
| AVC_LEVEL_22  | 级别2.2   | 
| AVC_LEVEL_3  | 级别3   | 
| AVC_LEVEL_31  | 级别3.1   | 
| AVC_LEVEL_32  | 级别3.2   | 
| AVC_LEVEL_4  | 级别4   | 
| AVC_LEVEL_41  | 级别4.1   | 
| AVC_LEVEL_42  | 级别4.2   | 
| AVC_LEVEL_5  | 级别5   | 
| AVC_LEVEL_51  | 级别5.1   | 
| AVC_LEVEL_52  | 级别5.2   | 
| AVC_LEVEL_6  | 级别6   | 
| AVC_LEVEL_61  | 级别6.1   | 
| AVC_LEVEL_62  | 级别6.2   | 


### OH_AVCProfile

```
enum OH_AVCProfile
```
**描述**
AVC档次。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9

| 枚举值 | 描述 | 
| -------- | -------- |
| AVC_PROFILE_BASELINE  | AVC编码档次为基本档次。   |
| AVC_PROFILE_HIGH  | AVC编码档次为高档次。   |
| AVC_PROFILE_MAIN  | AVC编码档次为主档次。   |


### OH_AVOutputFormat

```
enum OH_AVOutputFormat
```
**描述**
封装器支持的输出文件格式。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| AV_OUTPUT_FORMAT_DEFAULT  | 输出文件格式默认值，默认为MP4格式。   | 
| AV_OUTPUT_FORMAT_MPEG_4  | 输出文件格式为MP4格式。   | 
| AV_OUTPUT_FORMAT_M4A  | 输出文件格式为M4A格式。   | 
| AV_OUTPUT_FORMAT_AMR  | 输出文件格式为AMR格式。<br>**起始版本：** 12    | 
| AV_OUTPUT_FORMAT_MP3  | 输出文件格式为MP3格式。<br>**起始版本：** 12   | 
| AV_OUTPUT_FORMAT_WAV  | 输出文件格式为WAV格式。<br>**起始版本：** 12   | 

### OH_AVSeekMode

```
enum OH_AVSeekMode
```
**描述**
跳转模式。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| SEEK_MODE_NEXT_SYNC  | 指定时间位置的下一I帧。若时间点后没有I帧，该模式可能跳转失败。   |
| SEEK_MODE_PREVIOUS_SYNC  | 指定时间位置的上一I帧。   | 
| SEEK_MODE_CLOSEST_SYNC  | 指定时间位置的最近I帧。   | 


### OH_BitsPerSample

```
enum OH_BitsPerSample
```
**描述**
每个编码样本的音频位数。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| SAMPLE_U8  | 8位无符号整数采样。   | 
| SAMPLE_S16LE  | 16位有符号整数采样。   | 
| SAMPLE_S24LE  | 24位有符号整数采样。   | 
| SAMPLE_S32LE  | 32位有符号整数采样。   | 
| SAMPLE_F32LE  | 32位浮点采样。   | 
| SAMPLE_U8P  | 8位无符号整数平面采样。   | 
| SAMPLE_S16P  | 16位有符号整数平面采样。   | 
| SAMPLE_S24P  | 24位有符号整数平面采样。   | 
| SAMPLE_S32P  | 32位有符号整数平面采样。   | 
| SAMPLE_F32P  | 32位浮点平面采样。   | 
| INVALID_WIDTH  | 无效采样格式。   | 


### OH_ColorPrimary

```
enum OH_ColorPrimary
```
**描述**
色域。编解码都支持。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| COLOR_PRIMARY_BT709  | BT709色域。   | 
| COLOR_PRIMARY_UNSPECIFIED  | 未指定色域。   | 
| COLOR_PRIMARY_BT470_M  | BT470_M色域。   | 
| COLOR_PRIMARY_BT601_625  | BT601_625色域。   | 
| COLOR_PRIMARY_BT601_525  | BT601_525色域。   | 
| COLOR_PRIMARY_SMPTE_ST240  | SMPTE_ST240色域。   | 
| COLOR_PRIMARY_GENERIC_FILM  | GENERIC_FILM色域。   | 
| COLOR_PRIMARY_BT2020  | BT2020色域。   | 
| COLOR_PRIMARY_SMPTE_ST428  | SMPTE_ST428色域。   | 
| COLOR_PRIMARY_P3DCI  | P3DCI色域。   | 
| COLOR_PRIMARY_P3D65  | P3D65色域。   | 


### OH_HEVCLevel

```
enum OH_HEVCLevel
```
**描述**
HEVC级别。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| HEVC_LEVEL_1  | 级别1   | 
| HEVC_LEVEL_2  | 级别2   | 
| HEVC_LEVEL_21  | 级别2.1   | 
| HEVC_LEVEL_3  | 级别3   | 
| HEVC_LEVEL_31  | 级别3.1   | 
| HEVC_LEVEL_4  | 级别4   | 
| HEVC_LEVEL_41  | 级别4.1   | 
| HEVC_LEVEL_5  | 级别5   | 
| HEVC_LEVEL_51  | 级别5.1   | 
| HEVC_LEVEL_52  | 级别5.2   | 
| HEVC_LEVEL_6  | 级别6   | 
| HEVC_LEVEL_61  | 级别6.1   | 
| HEVC_LEVEL_62  | 级别6.2   | 


### OH_HEVCProfile

```
enum OH_HEVCProfile
```
**描述**
HEVC档次。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| HEVC_PROFILE_MAIN  | HEVC编码档次为主档次。   | 
| HEVC_PROFILE_MAIN_10  | HEVC编码档次为10bit主档次。   | 
| HEVC_PROFILE_MAIN_STILL  | HEVC编码档次为静止图像主档次。   | 
| HEVC_PROFILE_MAIN_10_HDR10  | HEVC编码档次为HDR10主档次。（API14废弃）   | 
| HEVC_PROFILE_MAIN_10_HDR10_PLUS  | HEVC编码档次为HDR10+主档次。（API14废弃）   | 


### OH_MatrixCoefficient

```
enum OH_MatrixCoefficient
```
**描述**
矩阵系数。编解码都支持。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| MATRIX_COEFFICIENT_IDENTITY  | 单位矩阵。   | 
| MATRIX_COEFFICIENT_BT709  | BT709转换矩阵。   | 
| MATRIX_COEFFICIENT_UNSPECIFIED  | 未指定转换矩阵。   | 
| MATRIX_COEFFICIENT_FCC  | FCC转换矩阵。   | 
| MATRIX_COEFFICIENT_BT601_625  | BT601_625转换矩阵。   | 
| MATRIX_COEFFICIENT_BT601_525  | BT601_525转换矩阵。   | 
| MATRIX_COEFFICIENT_SMPTE_ST240  | SMPTE_ST240转换矩阵。   | 
| MATRIX_COEFFICIENT_YCGCO  | YCGCO转换矩阵。   | 
| MATRIX_COEFFICIENT_BT2020_NCL  | BT2020_NCL转换矩阵。   | 
| MATRIX_COEFFICIENT_BT2020_CL  | BT2020_CL转换矩阵。   | 
| MATRIX_COEFFICIENT_SMPTE_ST2085  | SMPTE_ST2085转换矩阵。   | 
| MATRIX_COEFFICIENT_CHROMATICITY_NCL  | CHROMATICITY_NCL转换矩阵。   | 
| MATRIX_COEFFICIENT_CHROMATICITY_CL  | CHROMATICITY_CL转换矩阵。   | 
| MATRIX_COEFFICIENT_ICTCP  | ICTCP转换矩阵。   | 


### OH_MediaType

```
enum OH_MediaType
```
**描述**
媒体类型。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9

| 枚举值 | 描述 | 
| -------- | -------- |
| MEDIA_TYPE_AUD  | 音频轨。   | 
| MEDIA_TYPE_VID  | 视频轨。   | 
| MEDIA_TYPE_SUBTITILE  | 字幕轨。 <br>**起始版本：** 12   |

### OH_ScalingMode

```
enum OH_ScalingMode
```
**描述**
缩放模式，只在Surface模式下使用。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**废弃版本：** 14 

**替代接口：** [OHScalingModeV2](../apis-arkgraphics2d/_native_window.md#ohscalingmodev2-1).OH_SCALING_MODE_SCALE_TO_WINDOW_V2、
[OHScalingModeV2](../apis-arkgraphics2d/_native_window.md#ohscalingmodev2-1).OH_SCALING_MODE_SCALE_CROP_V2

| 枚举值 | 描述 | 
| -------- | -------- |
| SCALING_MODE_SCALE_TO_WINDOW  | 根据窗口尺寸自适应调整图像大小。 | 
| SCALING_MODE_SCALE_CROP  | 根据窗口尺寸裁剪图像大小。 | 



### OH_TemporalGopReferenceMode

```
enum OH_TemporalGopReferenceMode
```
**描述**
时域图片组参考模式。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ADJACENT_REFERENCE  | 参考最近的短期参考帧。   | 
| JUMP_REFERENCE  | 参考最近的长期参考帧。   | 
| UNIFORMLY_SCALED_REFERENCE  | 均匀分层参考结构，在丢弃最高层级视频帧后，视频帧均匀分布。其中时域图片组个数必须为2的幂。   | 


### OH_VVCLevel

```
enum OH_VVCLevel
```
**描述**
VVC级别。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 14

| 枚举值 | 描述 | 
| -------- | -------- |
| VVC_LEVEL_1  | 级别1.0  | 
| VVC_LEVEL_2  | 级别2.0  | 
| VVC_LEVEL_21  | 级别2.1  | 
| VVC_LEVEL_3  | 级别3.0  |
| VVC_LEVEL_31  | 级别3.1  |
| VVC_LEVEL_4  | 级别4.0  |
| VVC_LEVEL_41  | 级别4.1  |
| VVC_LEVEL_5  | 级别5.0   |
| VVC_LEVEL_51  | 级别5.1  |
| VVC_LEVEL_52  | 级别5.2  |
| VVC_LEVEL_6  | 级别6.0  |
| VVC_LEVEL_61  | 级别6.1  |
| VVC_LEVEL_62  | 级别6.2  |
| VVC_LEVEL_63  | 级别6.3  |
| VVC_LEVEL_155  | 级别15.5  |


### OH_VVCProfile

```
enum OH_VVCProfile
```
**描述**
VVC档次。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 14

| 枚举值 | 描述 | 
| -------- | -------- |
| VVC_PROFILE_MAIN_10 | VVC编码档次为10bit主档次。  |
| VVC_PROFILE_MAIN_12 VVC | 编码档次为12bit主档次。  |
| VVC_PROFILE_MAIN_12_INTRA | VVC编码档次为12bit帧内主档次。  |
| VVC_PROFILE_MULTI_MAIN_10 | VVC编码档次为多层编码10bit主档次。  |
| VVC_PROFILE_MAIN_10_444 | VVC编码档次为10bit全采样主档次。  |
| VVC_PROFILE_MAIN_12_444 | VVC编码档次为12bit全采样主档次。  |
| VVC_PROFILE_MAIN_16_444 | VVC编码档次为16bit全采样主档次。  |
| VVC_PROFILE_MAIN_12_444_INTRA | VVC编码档次为12bit全采样帧内主档次。  |
| VVC_PROFILE_MAIN_16_444_INTRA | VVC编码档次为16bit全采样帧内主档次。  |
| VVC_PROFILE_MULTI_MAIN_10_444 | VVC编码档次为多层编码10bit全采样主档次。  |
| VVC_PROFILE_MAIN_10_STILL | VVC编码档次为10bit静止图像主档次。  |
| VVC_PROFILE_MAIN_12_STILL | VVC编码档次为12bit静止图像主档次。  |
| VVC_PROFILE_MAIN_10_444_STILL | VVC编码档次为10bit全采样静止图像主档次。  |
| VVC_PROFILE_MAIN_12_444_STILL | VVC编码档次为12bit全采样静止图像主档次。  |
| VVC_PROFILE_MAIN_16_444_STILL | VVC编码档次为16bit全采样静止图像主档次。  |


### OH_TransferCharacteristic

```
enum OH_TransferCharacteristic
```
**描述**
转移特性。编解码都支持。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| TRANSFER_CHARACTERISTIC_BT709  | BT709传递函数。   | 
| TRANSFER_CHARACTERISTIC_UNSPECIFIED  | 未指定传递函数。   | 
| TRANSFER_CHARACTERISTIC_GAMMA_2_2  | GAMMA_2_2传递函数。   | 
| TRANSFER_CHARACTERISTIC_GAMMA_2_8  | GAMMA_2_8传递函数。   | 
| TRANSFER_CHARACTERISTIC_BT601  | BT601传递函数。   | 
| TRANSFER_CHARACTERISTIC_SMPTE_ST240  | SMPTE_ST240传递函数。   | 
| TRANSFER_CHARACTERISTIC_LINEAR  | LINEAR传递函数。   | 
| TRANSFER_CHARACTERISTIC_LOG  | LOG传递函数。   | 
| TRANSFER_CHARACTERISTIC_LOG_SQRT  | LOG_SQRT传递函数。   | 
| TRANSFER_CHARACTERISTIC_IEC_61966_2_4  | IEC_61966_2_4传递函数。   | 
| TRANSFER_CHARACTERISTIC_BT1361  | BT1361传递函数。   | 
| TRANSFER_CHARACTERISTIC_IEC_61966_2_1  | IEC_61966_2_1传递函数。   | 
| TRANSFER_CHARACTERISTIC_BT2020_10BIT  | BT2020_10BIT传递函数。   | 
| TRANSFER_CHARACTERISTIC_BT2020_12BIT  | BT2020_12BIT传递函数。   | 
| TRANSFER_CHARACTERISTIC_PQ  | PQ传递函数。   | 
| TRANSFER_CHARACTERISTIC_SMPTE_ST428  | SMPTE_ST428传递函数。   | 
| TRANSFER_CHARACTERISTIC_HLG  | HLG传递函数。   | 


### OH_BitrateMode

```
enum OH_BitrateMode
```
**描述**
编码器的比特率模式。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| BITRATE_MODE_CBR  | 恒定比特率模式。   | 
| BITRATE_MODE_VBR  | 可变比特率模式，码率仅作参考。   | 
| BITRATE_MODE_CQ  | 恒定质量模式。   | 

## 变量说明


### OH_AVCODEC_MIMETYPE_SUBTITLE_SRT

```
const char* OH_AVCODEC_MIMETYPE_SUBTITLE_SRT
```
**描述**
SRT字幕解封装器的MIME类型。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_AVCODEC_MIMETYPE_SUBTITLE_WEBVTT

```
const char* OH_AVCODEC_MIMETYPE_SUBTITLE_WEBVTT
```
**描述**
WEBVTT字幕解封装器的MIME类型。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_AVCODEC_MIMETYPE_AUDIO_APE

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_APE
```
**描述**
APE音频解码器的MIME类型。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_AVCODEC_MIMETYPE_AUDIO_AAC

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_AAC
```
**描述**
AAC音频编解码器的MIME类型。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9


### OH_AVCODEC_MIMETYPE_AUDIO_AMR_NB

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_AMR_NB
```
**描述**
AMR_NB音频解码器的MIME类型。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 11


### OH_AVCODEC_MIMETYPE_AUDIO_AMR_WB

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_AMR_WB
```
**描述**
AMR_WB音频解码器的MIME类型。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 11


### OH_AVCODEC_MIMETYPE_AUDIO_FLAC

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_FLAC
```
**描述**
FLAC音频编解码器的MIME类型。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_AVCODEC_MIMETYPE_AUDIO_G711MU

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_G711MU
```
**描述**
G711MU音频编解码器的MIME类型。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 11


### OH_AVCODEC_MIMETYPE_AUDIO_RAW

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_RAW
```
**描述**
RAW音频码流的MIME类型。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 16


### OH_AVCODEC_MIMETYPE_AUDIO_MPEG

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_MPEG
```
**描述**
MP3音频解码器的MIME类型。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_AVCODEC_MIMETYPE_AUDIO_OPUS

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_OPUS
```
**描述**
OPUS音频编解码器的MIME类型。<!--Del-->（此规格暂未开放）<!--DelEnd--> 

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 11


### OH_AVCODEC_MIMETYPE_AUDIO_VIVID

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_VIVID
```
**描述**
Audio Vivid音频解码器的MIME类型。<!--Del-->（目前本规格未开放）<!--DelEnd-->

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 11


### OH_AVCODEC_MIMETYPE_AUDIO_VORBIS

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_VORBIS
```
**描述**
VORBIS音频解码器的MIME类型。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_AVCODEC_MIMETYPE_IMAGE_BMP

```
const char* OH_AVCODEC_MIMETYPE_IMAGE_BMP
```
**描述**
BMP图片编码的MIME类型，仅用于封装BMP封面时使用。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_AVCODEC_MIMETYPE_IMAGE_JPG

```
const char* OH_AVCODEC_MIMETYPE_IMAGE_JPG
```
**描述**
JPG图片编码的MIME类型，仅用于封装JPG封面时使用。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_AVCODEC_MIMETYPE_IMAGE_PNG

```
const char* OH_AVCODEC_MIMETYPE_IMAGE_PNG
```
**描述**
PNG图片编码的MIME类型，仅用于封装PNG封面时使用。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_AVCODEC_MIMETYPE_VIDEO_AVC

```
const char* OH_AVCODEC_MIMETYPE_VIDEO_AVC
```
**描述**
AVC(H.264)视频编解码器的MIME类型。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9


### OH_AVCODEC_MIMETYPE_VIDEO_HEVC

```
const char* OH_AVCODEC_MIMETYPE_VIDEO_HEVC
```
**描述**
HEVC(H.265)视频编解码器的MIME类型。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_AVCODEC_MIMETYPE_VIDEO_VVC

```
const char* OH_AVCODEC_MIMETYPE_VIDEO_VVC
```
**描述**
VVC(H.266)视频编解码器的MIME类型。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_AVCODEC_MIMETYPE_VIDEO_MPEG4

```
const char* OH_AVCODEC_MIMETYPE_VIDEO_MPEG4
```
**描述**
MPEG4视频编码的MIME类型，仅用于封装MPEG4视频码流使用。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**废弃版本：** 11


### OH_ED_KEY_EOS

```
const char* OH_ED_KEY_EOS
```
**描述**
表示surfacebuffer流结束符的键，值类型为int32_t。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9

**废弃版本：** 14 


### OH_ED_KEY_TIME_STAMP

```
const char* OH_ED_KEY_TIME_STAMP
```
**描述**
表示surfacebuffer时间戳的键，值类型为int64_t。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9

**废弃版本：** 14 


### OH_FEATURE_PROPERTY_KEY_VIDEO_ENCODER_MAX_LTR_FRAME_COUNT

```
const char* OH_FEATURE_PROPERTY_KEY_VIDEO_ENCODER_MAX_LTR_FRAME_COUNT
```
**描述**
在视频编码中获取长期参考帧的最大个数的键，值类型为int32_t。 

可以通过[OH_AVCapability_GetFeatureProperties](_a_v_capability.md#oh_avcapability_getfeatureproperties)接口和枚举值[VIDEO_ENCODER_LONG_TERM_REFERENCE](_a_v_capability.md#oh_avcapabilityfeature-1)来查询这个最大值。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_AAC_IS_ADTS

```
const char* OH_MD_KEY_AAC_IS_ADTS
```
**描述**
aac格式的键，aac格式分为ADTS格式和LATM格式。值类型为int32_t，0表示LATM格式，1表示ADTS格式。aac解码器支持。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_ALBUM

```
const char* OH_MD_KEY_ALBUM
```
**描述**
专辑的媒体文件的键，值类型为string。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_ALBUM_ARTIST

```
const char* OH_MD_KEY_ALBUM_ARTIST
```
**描述**
专辑艺术家的键，值类型为string。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_ARTIST

```
const char* OH_MD_KEY_ARTIST
```
**描述**
媒体文件艺术家的键，值类型为string。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_AUD_CHANNEL_COUNT

```
const char* OH_MD_KEY_AUD_CHANNEL_COUNT
```
**描述**
音频通道计数键，值类型为int32_t。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9


### OH_MD_KEY_AUD_SAMPLE_RATE

```
const char* OH_MD_KEY_AUD_SAMPLE_RATE
```
**描述**
音频采样率键，值类型为int32_t。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9


### OH_MD_KEY_AUDIO_COMPRESSION_LEVEL

```
const char* OH_MD_KEY_AUDIO_COMPRESSION_LEVEL
```
**描述**
音频编解码压缩水平的键，只在音频编码使用，值类型为int32_t。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 11


### OH_MD_KEY_AUDIO_OBJECT_NUMBER

```
const char* OH_MD_KEY_AUDIO_OBJECT_NUMBER
```
**描述**
音频对象数目的键，值类型为int32_t，只有Audio Vivid解码使用。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 11


### OH_MD_KEY_AUDIO_SAMPLE_FORMAT

```
const char* OH_MD_KEY_AUDIO_SAMPLE_FORMAT
```
**描述**
音频原始格式的键，值类型为int32_t。请参见[OH_BitsPerSample](#oh_bitspersample-1)。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9


### OH_MD_KEY_AUDIO_VIVID_METADATA

```
const char* OH_MD_KEY_AUDIO_VIVID_METADATA
```
**描述**
Audio Vivid元数据的键，值类型为uint8_t\*，只有Audio Vivid解码使用。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 11


### OH_MD_KEY_BITRATE

```
const char* OH_MD_KEY_BITRATE
```
**描述**
比特率的键，值类型为int64_t。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9


### OH_MD_KEY_BITS_PER_CODED_SAMPLE

```
const char* OH_MD_KEY_BITS_PER_CODED_SAMPLE
```
**描述**
每个编码样本位数的键，值类型为int32_t，支持flac编码器，请参见[OH_BitsPerSample](#oh_bitspersample-1)。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_CHANNEL_LAYOUT

```
const char* OH_MD_KEY_CHANNEL_LAYOUT
```
**描述**
所需编码通道布局的键。值类型为int64_t，此键仅适用于编码器。
请参见[OH_AudioChannelLayout](_core.md#oh_audiochannellayout-1)。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_CODEC_CONFIG

```
const char* OH_MD_KEY_CODEC_CONFIG
```
**描述**

编解码器特定数据的键，视频中表示传递SPS/PPS，音频中表示传递extraData，值类型为uint8_t\*。 <!--Del-->（视频编解码此功能暂未支持）<!--DelEnd-->

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_CODEC_MIME

```
const char* OH_MD_KEY_CODEC_MIME
```
**描述**
编解码器[MIME](#媒体编解码格式)类型的键，值类型为string。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9


### OH_MD_KEY_COLOR_PRIMARIES

```
const char* OH_MD_KEY_COLOR_PRIMARIES
```
**描述**
视频色域的键，值类型为int32_t，请参见[OH_ColorPrimary](#oh_colorprimary)，遵循H.273标准Table2。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_COMMENT

```
const char* OH_MD_KEY_COMMENT
```
**描述**
媒体文件注释的键，值类型为string。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_COMPLIANCE_LEVEL

```
const char* OH_MD_KEY_COMPLIANCE_LEVEL
```
**描述**
flac兼容性等级的键，值类型为int32_t，仅在音频编码使用。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_COPYRIGHT

```
const char* OH_MD_KEY_COPYRIGHT
```
**描述**
媒体文件版权的键，值类型为string。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_DATE

```
const char* OH_MD_KEY_DATE
```
**描述**
媒体文件日期的键，值类型为string，例如2024年。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_DESCRIPTION

```
const char* OH_MD_KEY_DESCRIPTION
```
**描述**
媒体文件描述的键，值类型为string。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_DURATION

```
const char* OH_MD_KEY_DURATION
```
**描述**
媒体文件持续时间的键，单位为微秒，值类型为int64_t。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9


### OH_MD_KEY_FRAME_RATE

```
const char* OH_MD_KEY_FRAME_RATE
```
**描述**
视频帧率的键，值类型为double。该值必须大于 0。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9


### OH_MD_KEY_GENRE

```
const char* OH_MD_KEY_GENRE
```
**描述**
媒体文件流派的键，值类型为string。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_HEIGHT

```
const char* OH_MD_KEY_HEIGHT
```
**描述**
视频高度键，值类型为int32_t。

使用指导请参见：[视频编码](../../media/avcodec/video-encoding.md)中的“Surface模式的步骤-5或Buffer模式步骤-4”。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9


### OH_MD_KEY_I_FRAME_INTERVAL

```
const char* OH_MD_KEY_I_FRAME_INTERVAL
```

**描述**
关键帧间隔的键，值类型为int32_t，单位为毫秒。该键是可选的且只用于视频编码。

负值表示只有第一帧是关键帧，零表示所有帧都是关键帧。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9


### OH_MD_KEY_IDENTIFICATION_HEADER

```
const char* OH_MD_KEY_IDENTIFICATION_HEADER
```
**描述**
vorbis标识头的键，值类型为uint8_t\*，仅vorbis解码器支持。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_LANGUAGE

```
const char* OH_MD_KEY_LANGUAGE
```
**描述**
媒体文件语言的键，值类型为string。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_LYRICS

```
const char* OH_MD_KEY_LYRICS
```
**描述**
媒体文件歌词的键，值类型为string。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_MATRIX_COEFFICIENTS

```
const char* OH_MD_KEY_MATRIX_COEFFICIENTS
```
**描述**
视频矩阵系数的键，值类型为int32_t，请参见[OH_MatrixCoefficient](#oh_matrixcoefficient)，遵循H.273标准Table4。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_MAX_INPUT_SIZE

```
const char* OH_MD_KEY_MAX_INPUT_SIZE
```
**描述**
设置解码输入码流大小最大值的键，值类型为int32_t。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9


### OH_MD_KEY_PIXEL_FORMAT

```
const char* OH_MD_KEY_PIXEL_FORMAT
```
**描述**
视频像素格式的键，值类型为int32_t，请参见[OH_AVPixelFormat](_core.md#oh_avpixelformat)。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9


### OH_MD_KEY_PROFILE

```
const char* OH_MD_KEY_PROFILE
```
**描述**
编码档次，值类型为int32_t，请参见[OH_AVCProfile](#oh_avcprofile)，[OH_HEVCProfile](#oh_hevcprofile)，[OH_AACProfile](#oh_aacprofile)。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9


### OH_MD_KEY_QUALITY

```
const char* OH_MD_KEY_QUALITY
```
**描述**
所需编码质量的键。值类型为int32_t，在H.264、H.265编码场景值范围可以根据能力查询接口OH_AVCapability_GetEncoderQualityRange()获取，此键仅适用于配置在恒定质量模式下的编码器。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_RANGE_FLAG

```
const char* OH_MD_KEY_RANGE_FLAG
```
**描述**
视频YUV值域标志的键，值类型为int32_t，1表示full range，0表示limited range。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_REQUEST_I_FRAME

```
const char* OH_MD_KEY_REQUEST_I_FRAME
```
**描述**
请求立即编码I帧的键。值类型为int32_t。在调用OH_VideoEncoder_SetParameter()阶段使用，或随帧立即生效。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_ROTATION

```
const char* OH_MD_KEY_ROTATION
```
**描述**
surface旋转角度的键。值类型为int32_t：应为{0, 90, 180, 270}，默认值为0。该键只在视频解码Surface模式下使用。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9


### OH_MD_KEY_SBR

```
const char* OH_MD_KEY_SBR
```
**描述**
aac sbr模式的键，值类型为int32_t，aac编码器支持。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_SCALING_MODE

```
const char* OH_MD_KEY_SCALING_MODE
```
**描述**
视频缩放模式，值类型为int32_t，请参见[OH_ScalingMode](#oh_scalingmode)。建议直接调用[OH_NativeWindow_NativeWindowSetScalingModeV2](../apis-arkgraphics2d/_native_window.md#oh_nativewindow_nativewindowsetscalingmodev2)接口进行设置。该键是可选的且只用于视频解码Surface模式。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**废弃版本：** 14 

**替代接口：**[OH_NativeWindow_NativeWindowSetScalingModeV2](../apis-arkgraphics2d/_native_window.md#oh_nativewindow_nativewindowsetscalingmodev2)


### OH_MD_KEY_SETUP_HEADER

```
const char* OH_MD_KEY_SETUP_HEADER
```
**描述**
vorbis设置头的键，值类型为uint8_t\*，仅vorbis解码器支持。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_TITLE

```
const char* OH_MD_KEY_TITLE
```
**描述**
媒体文件标题的键，值类型为string。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_TRACK_COUNT

```
const char* OH_MD_KEY_TRACK_COUNT
```
**描述**
媒体文件轨道数量的键，值类型为int32_t。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_TRACK_TYPE

```
const char* OH_MD_KEY_TRACK_TYPE
```
**描述**

轨道媒体类型的键，值类型为int32_t，请参见[OH_MediaType](#oh_mediatype-1)。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9


### OH_MD_KEY_TRANSFER_CHARACTERISTICS

```
const char* OH_MD_KEY_TRANSFER_CHARACTERISTICS
```
**描述**
视频传递函数的键，值类型为int32_t，请参见[OH_TransferCharacteristic](#oh_transfercharacteristic)，遵循H.273标准Table3。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

### OH_MD_KEY_VIDEO_CROP_BOTTOM

```
const char* OH_MD_KEY_VIDEO_CROP_BOTTOM
```
**描述**
描述裁剪矩形底部坐标(y)值的键，值类型为int32_t。 包含裁剪框底部的行，行索引从0开始。该键只用于视频解码。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_VIDEO_CROP_LEFT

```
const char* OH_MD_KEY_VIDEO_CROP_LEFT
```
**描述**
描述裁剪矩形左坐标(x)值的键，值类型为int32_t。包含裁剪框最左边的列，列索引从0开始。该键只用于视频解码。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_VIDEO_CROP_RIGHT

```
const char* OH_MD_KEY_VIDEO_CROP_RIGHT
```
**描述**
描述裁剪矩形右坐标(x)值的键，值类型为int32_t。包含裁剪框最右边的列，列索引从0开始。该键只用于视频解码。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_VIDEO_CROP_TOP

```
const char* OH_MD_KEY_VIDEO_CROP_TOP
```
**描述**
描述裁剪矩形顶部坐标(y)值的键，值类型为int32_t。 包含裁剪框顶部的行，行索引从0开始。该键只用于视频解码。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_VIDEO_ENABLE_LOW_LATENCY

```
const char* OH_MD_KEY_VIDEO_ENABLE_LOW_LATENCY
```
**描述**
使能低时延视频编解码的键，值类型为int32_t，1表示使能，0表示其它情况。

如果使能，则视频编码器或视频解码器持有的输入和输出数据不会超过编解码器标准所要求的数量。 

该键是可选的，在Configure阶段使用。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE

```
const char* OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE
```
**描述**
视频编码码率模式，值类型为int32_t，请参见[OH_BitrateMode](#oh_bitratemode-1)。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9

### OH_MD_KEY_VIDEO_ENCODER_ENABLE_TEMPORAL_SCALABILITY

```
const char* OH_MD_KEY_VIDEO_ENCODER_ENABLE_TEMPORAL_SCALABILITY
```
**描述**
使能分层编码的键，值类型为int32_t，1表示使能，0表示其它情况。

使用前可以通过[OH_AVCapability_IsFeatureSupported](_a_v_capability.md#oh_avcapability_isfeaturesupported)接口和枚举值
[VIDEO_ENCODER_TEMPORAL_SCALABILITY](_a_v_capability.md#oh_avcapabilityfeature-1)来查询当前视频编码器是否支持分层编码。
详情请参见：[时域可分层视频编码](../../media/avcodec/video-encoding-temporal-scalability.md#接口介绍)。

该键是可选的且只用于视频编码，在Configure阶段使用。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_VIDEO_ENCODER_LTR_FRAME_COUNT

```
const char* OH_MD_KEY_VIDEO_ENCODER_LTR_FRAME_COUNT
```
**描述**
描述长期参考帧个数的键，值类型为int32_t，必须在支持的值范围内使用。 

使用前可以通过[OH_AVCapability_GetFeatureProperties](_a_v_capability.md#oh_avcapability_getfeatureproperties)接口和枚举值[VIDEO_ENCODER_LONG_TERM_REFERENCE](_a_v_capability.md#oh_avcapabilityfeature-1)来查询支持的LTR数目。 

该键是可选的且只用于视频编码，在Configure阶段使用。

详情请参见：[时域可分层视频编码](../../media/avcodec/video-encoding-temporal-scalability.md#接口介绍-1)。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_MARK_LTR

```
const char* OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_MARK_LTR
```
**描述**
标记当前帧为长期参考帧的键，值类型为int32_t，1表示被标记，0表示其它情况。 

只在长期参考帧个数被配置后生效。 

该键是可选的且只用于视频编码输入轮转中，配置后立即生效。

详情请参见：[时域可分层视频编码](../../media/avcodec/video-encoding-temporal-scalability.md#接口介绍-1)。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_USE_LTR

```
const char* OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_USE_LTR
```
**描述**
描述当前帧参考的长期参考帧帧的POC号的键，值类型为int32_t。

该键是可选的且只用于视频编码输入轮转中，配置后立即生效。

详情请参见：[时域可分层视频编码](../../media/avcodec/video-encoding-temporal-scalability.md#接口介绍-1)。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_VIDEO_ENCODER_QP_MAX

```
const char* OH_MD_KEY_VIDEO_ENCODER_QP_MAX
```
**描述**
描述视频编码器允许的最大量化参数的键，值类型为int32_t。 

在Configure/setparameter阶段使用，或随帧立即生效。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_VIDEO_ENCODER_QP_MIN

```
const char* OH_MD_KEY_VIDEO_ENCODER_QP_MIN
```
**描述**
描述视频编码器允许的最小量化参数的键，值类型为int32_t。 

在Configure/setparameter阶段使用，或随帧立即生效。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_VIDEO_ENCODER_QP_AVERAGE

```
const char* OH_MD_KEY_VIDEO_ENCODER_QP_AVERAGE
```
**描述**
描述视频帧平均量化参数的键，值类型为int32_t。

表示当前帧编码块的平均qp值，随[OH_AVBuffer](_core.md#oh_avbuffer)输出。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_VIDEO_ENCODER_MSE

```
const char* OH_MD_KEY_VIDEO_ENCODER_MSE
```
**描述**
描述视频帧平方误差的键，值类型为double。

表示当前帧编码块的MSE统计值，随[OH_AVBuffer](_core.md#oh_avbuffer)输出。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_REFERENCE_MODE

```
const char* OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_REFERENCE_MODE
```
**描述**
描述图片组内参考模式的键，值类型为int32_t，请参见[OH_TemporalGopReferenceMode](#oh_temporalgopreferencemode)，只在使能分层编码时生效。 

该键是可选的且只用于视频编码，在Configure阶段使用。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_SIZE

```
const char* OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_SIZE
```
**描述**
描述图片组基本层图片的间隔大小的键，值类型为int32_t，只在使能分层编码时生效。

该键是可选的且只用于视频编码，在Configure阶段使用。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_VIDEO_IS_HDR_VIVID

```
const char* OH_MD_KEY_VIDEO_IS_HDR_VIVID
```
**描述**
媒体文件中的视频轨是否为HDR Vivid的键，支持封装和解封装，值类型为int32_t。

1代表是HDR Vivid视频轨，0表示其他情况。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 11


### OH_MD_KEY_DECODING_TIMESTAMP

```
const char* OH_MD_KEY_DECODING_TIMESTAMP
```
**描述**
AVBuffer中携带的音视频或字幕的sample对应的解码时间戳的键，以微秒为单位，值类型为int64_t。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_BUFFER_DURATION

```
const char* OH_MD_KEY_BUFFER_DURATION
```
**描述**
AVBuffer中携带的音视频或字幕的sample对应的持续时间的键，以微秒为单位，值类型为int64_t。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_START_TIME

```
const char* OH_MD_KEY_START_TIME
```
**描述**
媒体文件中第一帧起始位置开始时间的键，以微秒为单位，值类型为int64_t。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12

### OH_MD_KEY_TRACK_START_TIME

```
const char* OH_MD_KEY_TRACK_START_TIME
```
**描述**
轨道开始时间的键，以微秒为单位，值类型为int64_t。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_VIDEO_DECODER_OUTPUT_COLOR_SPACE

```
const char* OH_MD_KEY_VIDEO_DECODER_OUTPUT_COLOR_SPACE
```
**描述**
设置视频解码器输出色彩空间的键，值类型为int32_t。

支持的值为OH_COLORSPACE_BT709_LIMIT，请参见[OH_NativeBuffer_ColorSpace](../../reference/apis-arkgraphics2d/_o_h___native_buffer.md#oh_nativebuffer_colorspace-1)。

在视频解码调用[OH_VideoDecoder_Configure](_video_decoder.md#oh_videodecoder_configure)接口时使用。

如果支持色彩空间转换功能并配置了此键，则视频解码器会自动将HDR Vivid视频转码为色彩空间BT709的SDR视频。

如果不支持色彩空间转换功能，则接口[OH_VideoDecoder_Configure](_video_decoder.md#oh_videodecoder_configure)返回错误码[AV_ERR_VIDEO_UNSUPPORTED_COLOR_SPACE_CONVERSION](_core.md#oh_averrcode-1)。

如果输入视频不是HDR Vivid视频，则会通过回调函数[OH_AVCodecOnError](#oh_avcodeconerror)报告错误码[AV_ERR_VIDEO_UNSUPPORTED_COLOR_SPACE_CONVERSION](_core.md#oh_averrcode-1)。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_VIDEO_PER_FRAME_IS_LTR

```
const char* OH_MD_KEY_VIDEO_PER_FRAME_IS_LTR
```
**描述**
当前OH_AVBuffer中输出的码流对应的帧是否为长期参考帧的键，值类型为int32_t，1表示是LTR，0表示其它情况。 

该键是可选的且只用于视频编码输出轮转中。

表示帧的属性。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_VIDEO_PER_FRAME_POC

```
const char* OH_MD_KEY_VIDEO_PER_FRAME_POC
```
**描述**
描述帧的POC号的键，值类型为int32_t。 

该键是可选的且只用于视频编码输出轮转中。 

表示帧的属性。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_VIDEO_PIC_HEIGHT

```
const char* OH_MD_KEY_VIDEO_PIC_HEIGHT
```
**描述**
描述视频帧真实高度的键，值类型为int32_t。

视频解码时调用[OH_VideoDecoder_GetOutputDescription](_video_decoder.md#oh_videodecoder_getoutputdescription)接口，可以从其返回的OH_AVFormat中解析出高度值。

当解码输出码流<!--RP2--><!--RP2End-->变化时，也可从[OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged)返回的OH_AVForamt实例中解析出高度值。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_VIDEO_PIC_WIDTH

```
const char* OH_MD_KEY_VIDEO_PIC_WIDTH
```
**描述**
描述视频帧真实宽度的键，值类型为int32_t。

视频解码时调用[OH_VideoDecoder_GetOutputDescription](_video_decoder.md#oh_videodecoder_getoutputdescription)接口，可以从其返回的OH_AVFormat中解析出宽度值。

当解码输出码流<!--RP2--><!--RP2End-->变化时，也可从[OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged)返回的OH_AVForamt实例中解析出宽度值。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_VIDEO_SLICE_HEIGHT

```
const char* OH_MD_KEY_VIDEO_SLICE_HEIGHT
```
**描述**
描述视频帧高跨距的键，值类型为int32_t。

高跨距是指从Y平面顶部到U平面顶部必须偏移的行数。本质上，U平面的偏移量是sliceHeight \* stride。 

U/V平面的高度可以根据颜色格式计算，尽管它通常是未定义的，并且取决于设备和版本。

使用指导请参见：[视频编码](../../media/avcodec/video-encoding.md#)中的“Buffer模式步骤-3”。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_VIDEO_STRIDE

```
const char* OH_MD_KEY_VIDEO_STRIDE
```
**描述**
描述视频帧宽跨距的键，值类型为int32_t。

宽跨距是像素的索引与正下方像素的索引之间的差。 

对于YUV420格式，宽跨距对应于Y平面，U和V平面的跨距可以根据颜色格式计算，但通常未定义，并且取决于设备和版本。

使用指导请参见：[视频编码](../../media/avcodec/video-encoding.md#)中的“Buffer模式步骤-3”。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_WIDTH

```
const char* OH_MD_KEY_WIDTH
```
**描述**
视频宽度的键，值类型为int32_t。

使用指导请参见：[视频编码](../../media/avcodec/video-encoding.md)中的“Surface模式的步骤-5或Buffer模式步骤-4”。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 9


### OH_MD_MAX_INPUT_BUFFER_COUNT

```
const char* OH_MD_MAX_INPUT_BUFFER_COUNT
```
**描述**
最大输入缓冲区个数的键，值类型为int32_t。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_MAX_OUTPUT_BUFFER_COUNT

```
const char* OH_MD_MAX_OUTPUT_BUFFER_COUNT
```
**描述**
最大输出缓冲区个数的键，值类型int32_t。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_MD_KEY_VIDEO_SAR

```
const char* OH_MD_KEY_VIDEO_SAR
```
**描述**
样本长宽比的键，值类型为double。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_MD_KEY_CREATION_TIME

```
const char* OH_MD_KEY_CREATION_TIME
```
**描述**
媒体文件创建时间的元数据，值类型为string。使用ISO 8601标准的时间格式且为UTC时间，时间格式参考："2024-12-28T00:00:00:000000Z"。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 14

### OH_MD_KEY_VIDEO_DECODER_OUTPUT_ENABLE_VRR

```
const char* OH_MD_KEY_VIDEO_DECODER_OUTPUT_ENABLE_VRR
```
**描述**
解码器是否打开视频可变帧率功能的键，值类型为int32_t。1代表使能视频可变帧率功能，0代表不使能。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 15

### OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER

```
const char* OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER
```
**描述**
如果在上一帧提交给编码器之后没有新的帧可用，则会以毫秒为单位重复提交最后一帧，值类型为int32_t。

该键只用于视频编码Surface模式，在Configure阶段使用。

| 配置的值 | 描述 | 
| -------- | -------- |
| 小于等于0 | Configure阶段会被拦截，返回ERROR AV_ERR_INVALID_VAL。  |
| 大于0|  如果在上一帧提交给编码器之后没有新的帧可用，则会以毫秒为单位重复提交最后一帧。 |

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 16


### OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_MAX_COUNT

```
const char* OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_MAX_COUNT
```
**描述**
描述编码器在没有新的帧可用的情况下，可以对之前的帧进行重复编码的最大次数，值类型为int32_t。

该键仅在[OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER](#oh_md_key_video_encoder_repeat_previous_frame_after)可用时生效，在Configure阶段使用。

| 配置的值 | 描述 | 
| -------- | -------- |
| 0  | Configure阶段会被拦截，返回ERROR AV_ERR_INVALID_VAL。  |
| 小于0 | 在没有新的帧提交给编码器的这段时间内，编码器会一直重复编上一帧，直到达到系统上限。  | 
| 大于0|  在没有新的帧提交给编码器的这段时间内，最多可以重复编码的帧数。 |

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 16