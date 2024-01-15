# native_avcodec_base.h


## 概述

声明用于音视频封装、解封装、编解码基础功能的Native API。

**库：** libnative_media_codecbase.so

**起始版本：** 9

**相关模块：**[CodecBase](_codec_base.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) | OH_AVCodec中所有异步回调函数指针的集合。 | 
| struct&nbsp;&nbsp;[OH_AVCodecCallback](_o_h___a_v_codec_callback.md) | OH_AVCodec中所有异步回调函数指针的集合。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef void(\* [OH_AVCodecOnError](_codec_base.md#oh_avcodeconerror)) (OH_AVCodec \*codec, int32_t errorCode, void \*userData) | 当OH_AVCodec实例运行出错时，会调用来上报具体的错误信息的函数指针。 | 
| typedef void(\* [OH_AVCodecOnStreamChanged](_codec_base.md#oh_avcodeconstreamchanged)) (OH_AVCodec \*codec, OH_AVFormat \*format, void \*userData) | 当输出码流发生变化时，将调用此函数指针报告新的流描述信息。 | 
| typedef void(\* [OH_AVCodecOnNeedInputData](_codec_base.md#oh_avcodeconneedinputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, void \*userData) | 当OH_AVCodec在运行过程中需要新的输入数据时，将调用此函数指针，并携带可用的缓冲区来填充新的输入数据。 | 
| typedef void(\* [OH_AVCodecOnNewOutputData](_codec_base.md#oh_avcodeconnewoutputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr, void \*userData) | 当OH_AVCodec运行过程中生成新的输出数据时，将调用此函数指针，并携带包含新输出数据的缓冲区。 | 
| typedef void(\* [OH_AVCodecOnNeedInputBuffer](_codec_base.md#oh_avcodeconneedinputbuffer)) (OH_AVCodec \*codec, uint32_t index, OH_AVBuffer \*buffer, void \*userData) | 当OH_AVCodec在运行过程中需要新的输入数据时，将调用此函数指针，并携带可用的缓冲区来填充新的输入数据。 | 
| typedef void(\* [OH_AVCodecOnNewOutputBuffer](_codec_base.md#oh_avcodeconnewoutputbuffer)) (OH_AVCodec \*codec, uint32_t index, OH_AVBuffer \*buffer, void \*userData) | 当OH_AVCodec运行过程中生成新的输出数据时，将调用此函数指针，并携带包含新输出数据的缓冲区。 | 
| typedef struct [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md)[OH_AVCodecAsyncCallback](_codec_base.md#oh_avcodecasynccallback) | OH_AVCodec中所有异步回调函数指针的集合。 | 
| typedef struct [OH_AVCodecCallback](_o_h___a_v_codec_callback.md)[OH_AVCodecCallback](_codec_base.md#oh_avcodeccallback) | OH_AVCodec中所有异步回调函数指针的集合。 | 
| typedef enum [OH_MediaType](_codec_base.md#oh_mediatype)[OH_MediaType](_codec_base.md#oh_mediatype) | 媒体类型。 | 
| typedef enum [OH_AACProfile](_codec_base.md#oh_aacprofile)[OH_AACProfile](_codec_base.md#oh_aacprofile) | AAC配置。 | 
| typedef enum [OH_AVCProfile](_codec_base.md#oh_avcprofile)[OH_AVCProfile](_codec_base.md#oh_avcprofile) | AVC配置。 | 
| typedef enum [OH_HEVCProfile](_codec_base.md#oh_hevcprofile)[OH_HEVCProfile](_codec_base.md#oh_hevcprofile) | HEVC配置。 | 
| typedef enum [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat)[OH_AVOutputFormat](_codec_base.md#oh_avoutputformat) | 枚举封装器的输出文件格式。 | 
| typedef enum [OH_AVSeekMode](_codec_base.md#oh_avseekmode)[OH_AVSeekMode](_codec_base.md#oh_avseekmode) | 跳转模式。 | 
| typedef enum [OH_ScalingMode](_codec_base.md#oh_scalingmode)[OH_ScalingMode](_codec_base.md#oh_scalingmode) | 缩放模式。 | 
| typedef enum [OH_BitsPerSample](_codec_base.md#oh_bitspersample)[OH_BitsPerSample](_codec_base.md#oh_bitspersample) | 枚举每个编码样本的音频位数。 | 
| typedef enum [OH_ColorPrimary](_codec_base.md#oh_colorprimary)[OH_ColorPrimary](_codec_base.md#oh_colorprimary) | 色域。 | 
| typedef enum [OH_TransferCharacteristic](_codec_base.md#oh_transfercharacteristic)[OH_TransferCharacteristic](_codec_base.md#oh_transfercharacteristic) | 转移特性。 | 
| typedef enum [OH_MatrixCoefficient](_codec_base.md#oh_matrixcoefficient)[OH_MatrixCoefficient](_codec_base.md#oh_matrixcoefficient) | 矩阵系数。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_MediaType](_codec_base.md#oh_mediatype) {<br/>MEDIA_TYPE_AUD = 0,<br/>MEDIA_TYPE_VID = 1<br/>} | 媒体类型。 | 
| [OH_AACProfile](_codec_base.md#oh_aacprofile) { AAC_PROFILE_LC = 0 } | AAC配置。 | 
| [OH_AVCProfile](_codec_base.md#oh_avcprofile) {<br/>AVC_PROFILE_BASELINE = 0,<br/>AVC_PROFILE_HIGH = 4,<br/>AVC_PROFILE_MAIN = 8<br/>} | AVC配置。 | 
| [OH_HEVCProfile](_codec_base.md#oh_hevcprofile) {<br/>HEVC_PROFILE_MAIN = 0,<br/>HEVC_PROFILE_MAIN_10 = 1,<br/>HEVC_PROFILE_MAIN_STILL = 2,<br/>HEVC_PROFILE_MAIN_10_HDR10 = 3,<br/>HEVC_PROFILE_MAIN_10_HDR10_PLUS = 4<br/>} | HEVC配置。 | 
| [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat) {<br/>AV_OUTPUT_FORMAT_DEFAULT = 0,<br/>AV_OUTPUT_FORMAT_MPEG_4 = 2,<br/>AV_OUTPUT_FORMAT_M4A = 6<br/>} | 枚举封装器的输出文件格式。 | 
| [OH_AVSeekMode](_codec_base.md#oh_avseekmode) {<br/>SEEK_MODE_NEXT_SYNC = 0,<br/>SEEK_MODE_PREVIOUS_SYNC,<br/>SEEK_MODE_CLOSEST_SYNC<br/>} | 跳转模式。 | 
| [OH_ScalingMode](_codec_base.md#oh_scalingmode) {<br/>SCALING_MODE_SCALE_TO_WINDOW = 1,<br/>SCALING_MODE_SCALE_CROP = 2<br/>} | 缩放模式。 | 
| [OH_BitsPerSample](_codec_base.md#oh_bitspersample) {<br/>SAMPLE_U8 = 0, SAMPLE_S16LE = 1,<br/>SAMPLE_S24LE = 2, SAMPLE_S32LE = 3,<br/>SAMPLE_F32LE = 4, SAMPLE_U8P = 5,<br/>SAMPLE_S16P = 6, SAMPLE_S24P = 7,<br/>SAMPLE_S32P = 8, SAMPLE_F32P = 9,<br/>INVALID_WIDTH = -1<br/>} | 枚举每个编码样本的音频位数。 | 
| [OH_ColorPrimary](_codec_base.md#oh_colorprimary) {<br/>COLOR_PRIMARY_BT709 = 1,<br/>COLOR_PRIMARY_UNSPECIFIED = 2,<br/>COLOR_PRIMARY_BT470_M = 4,<br/>COLOR_PRIMARY_BT601_625 = 5,<br/>COLOR_PRIMARY_BT601_525 = 6,<br/>COLOR_PRIMARY_SMPTE_ST240 = 7,<br/>COLOR_PRIMARY_GENERIC_FILM = 8,<br/>COLOR_PRIMARY_BT2020 = 9,<br/>COLOR_PRIMARY_SMPTE_ST428 = 10,<br/>COLOR_PRIMARY_P3DCI = 11,<br/>COLOR_PRIMARY_P3D65 = 12<br/>} | 色域。 | 
| [OH_TransferCharacteristic](_codec_base.md#oh_transfercharacteristic) {<br/>TRANSFER_CHARACTERISTIC_BT709 = 1,<br/>TRANSFER_CHARACTERISTIC_UNSPECIFIED = 2,<br/>TRANSFER_CHARACTERISTIC_GAMMA_2_2 = 4,<br/>TRANSFER_CHARACTERISTIC_GAMMA_2_8 = 5,<br/>TRANSFER_CHARACTERISTIC_BT601 = 6,<br/>TRANSFER_CHARACTERISTIC_SMPTE_ST240 = 7,<br/>TRANSFER_CHARACTERISTIC_LINEAR = 8,<br/>TRANSFER_CHARACTERISTIC_LOG = 9,<br/>TRANSFER_CHARACTERISTIC_LOG_SQRT = 10,<br/>TRANSFER_CHARACTERISTIC_IEC_61966_2_4 = 11,<br/>TRANSFER_CHARACTERISTIC_BT1361 = 12,<br/>TRANSFER_CHARACTERISTIC_IEC_61966_2_1 = 13,<br/>TRANSFER_CHARACTERISTIC_BT2020_10BIT = 14,<br/>TRANSFER_CHARACTERISTIC_BT2020_12BIT = 15,<br/>TRANSFER_CHARACTERISTIC_PQ = 16,<br/>TRANSFER_CHARACTERISTIC_SMPTE_ST428 = 17,<br/>TRANSFER_CHARACTERISTIC_HLG = 18<br/>} | 转移特性。 | 
| [OH_MatrixCoefficient](_codec_base.md#oh_matrixcoefficient) {<br/>MATRIX_COEFFICIENT_IDENTITY = 0,<br/>MATRIX_COEFFICIENT_BT709 = 1,<br/>MATRIX_COEFFICIENT_UNSPECIFIED = 2,<br/>MATRIX_COEFFICIENT_FCC = 4,<br/>MATRIX_COEFFICIENT_BT601_625 = 5,<br/>MATRIX_COEFFICIENT_BT601_525 = 6, MATRIX_COEFFICIENT_SMPTE_ST240 = 7,<br/>MATRIX_COEFFICIENT_YCGCO = 8,<br/>MATRIX_COEFFICIENT_BT2020_NCL = 9,<br/>MATRIX_COEFFICIENT_BT2020_CL = 10,<br/>MATRIX_COEFFICIENT_SMPTE_ST2085 = 11,<br/>MATRIX_COEFFICIENT_CHROMATICITY_NCL = 12,<br/>MATRIX_COEFFICIENT_CHROMATICITY_CL = 13,<br/>MATRIX_COEFFICIENT_ICTCP = 14<br/>} | 矩阵系数。 | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| const char \* [OH_AVCODEC_MIMETYPE_VIDEO_AVC](_codec_base.md#oh_avcodec_mimetype_video_avc) | AVC(H.264)视频编解码器的MIME类型。 | 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_AAC](_codec_base.md#oh_avcodec_mimetype_audio_aac) | AAC音频编解码器的MIME类型。 | 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_FLAC](_codec_base.md#oh_avcodec_mimetype_audio_flac) | FLAC音频编解码器的MIME类型。 | 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_VORBIS](_codec_base.md#oh_avcodec_mimetype_audio_vorbis) | VORBIS音频解码器的MIME类型。 | 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_MPEG](_codec_base.md#oh_avcodec_mimetype_audio_mpeg) | MP3音频解码器的MIME类型。 | 
| const char \* [OH_AVCODEC_MIMETYPE_VIDEO_HEVC](_codec_base.md#oh_avcodec_mimetype_video_hevc) | HEVC(H.265)视频编解码器的MIME类型。 | 
| const char \* [OH_AVCODEC_MIMETYPE_VIDEO_MPEG4](_codec_base.md#oh_avcodec_mimetype_video_mpeg4) | MPEG4视频编码的MIME类型，仅用于封装MPEG4视频码流使用。 | 
| const char \* [OH_AVCODEC_MIMETYPE_IMAGE_JPG](_codec_base.md#oh_avcodec_mimetype_image_jpg) | JPG图片编码的MIME类型，仅用于封装JPG封面时使用。 | 
| const char \* [OH_AVCODEC_MIMETYPE_IMAGE_PNG](_codec_base.md#oh_avcodec_mimetype_image_png) | PNG图片编码的MIME类型，仅用于封装PNG封面时使用。 | 
| const char \* [OH_AVCODEC_MIMETYPE_IMAGE_BMP](_codec_base.md#oh_avcodec_mimetype_image_bmp) | BMP图片编码的MIME类型，仅用于封装BMP封面时使用。 | 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_VIVID](_codec_base.md#oh_avcodec_mimetype_audio_vivid) | AudioVivid音频解码器的MIME类型。（此规格暂未开放） | 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_AMR_NB](_codec_base.md#oh_avcodec_mimetype_audio_amr_nb) | AMR_NB音频解码器的MIME类型。 | 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_AMR_WB](_codec_base.md#oh_avcodec_mimetype_audio_amr_wb) | AMR_WB音频解码器的MIME类型。 | 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_OPUS](_codec_base.md#oh_avcodec_mimetype_audio_opus) | OPUS音频编解码器的MIME类型。（此规格暂未开放） | 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_G711MU](_codec_base.md#oh_avcodec_mimetype_audio_g711mu) | G711MU音频编解码器的MIME类型。 | 
| const char \* [OH_ED_KEY_TIME_STAMP](_codec_base.md#oh_ed_key_time_stamp) | 表面的额外数据中时间戳的键，值类型为int64。 | 
| const char \* [OH_ED_KEY_EOS](_codec_base.md#oh_ed_key_eos) | 表面的额外数据中流结束符的键，值类型为bool。 | 
| const char \* [OH_MD_KEY_TRACK_TYPE](_codec_base.md#oh_md_key_track_type) | 曲目类型的键，值类型为uint8_t，请参见[OH_MediaType](_codec_base.md#oh_mediatype)。 | 
| const char \* [OH_MD_KEY_CODEC_MIME](_codec_base.md#oh_md_key_codec_mime) | 编解码器mime类型的键，值类型为string。 | 
| const char \* [OH_MD_KEY_DURATION](_codec_base.md#oh_md_key_duration) | 持续时间键，值类型为int64_t。 | 
| const char \* [OH_MD_KEY_BITRATE](_codec_base.md#oh_md_key_bitrate) | 比特率的键，值类型为int64_t。 | 
| const char \* [OH_MD_KEY_MAX_INPUT_SIZE](_codec_base.md#oh_md_key_max_input_size) | 最大输入大小的键，值类型为uint32_t。 | 
| const char \* [OH_MD_KEY_WIDTH](_codec_base.md#oh_md_key_width) | 视频宽度的键，值类型为uint32_t。 | 
| const char \* [OH_MD_KEY_HEIGHT](_codec_base.md#oh_md_key_height) | 视频高度键，值类型为uint32_t。 | 
| const char \* [OH_MD_KEY_PIXEL_FORMAT](_codec_base.md#oh_md_key_pixel_format) | 视频像素格式的键，值类型为int32_t，请参见[OH_AVPixelFormat](_core.md#oh_avpixelformat)。 | 
| const char \* [OH_MD_KEY_AUDIO_SAMPLE_FORMAT](_codec_base.md#oh_md_key_audio_sample_format) | 音频原始格式的键，值类型为uint32_t，请参见AudioSampleFormat。 | 
| const char \* [OH_MD_KEY_FRAME_RATE](_codec_base.md#oh_md_key_frame_rate) | 视频帧率的键，值类型为double。 | 
| const char \* [OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE](_codec_base.md#oh_md_key_video_encode_bitrate_mode) | 视频编码码率模式，值类型为int32_t，请参见[OH_VideoEncodeBitrateMode](_video_encoder.md#oh_videoencodebitratemode)。 | 
| const char \* [OH_MD_KEY_PROFILE](_codec_base.md#oh_md_key_profile) | 编码模板，值类型为数字，请参见[OH_HEVCProfile](_codec_base.md#oh_hevcprofile), [OH_AACProfile](_codec_base.md#oh_aacprofile)。 | 
| const char \* [OH_MD_KEY_AUD_CHANNEL_COUNT](_codec_base.md#oh_md_key_aud_channel_count) | 音频通道计数键，值类型为uint32_t。 | 
| const char \* [OH_MD_KEY_AUD_SAMPLE_RATE](_codec_base.md#oh_md_key_aud_sample_rate) | 音频采样率键，值类型为uint32_t。 | 
| const char \* [OH_MD_KEY_I_FRAME_INTERVAL](_codec_base.md#oh_md_key_i_frame_interval) | 关键帧间隔的键，值类型为int32_t，单位为毫秒。 | 
| const char \* [OH_MD_KEY_ROTATION](_codec_base.md#oh_md_key_rotation) | 表面旋转角度的键。值类型为int32_t：应为{0, 90, 180, 270}，默认值为0。 | 
| const char \* [OH_MD_KEY_RANGE_FLAG](_codec_base.md#oh_md_key_range_flag) | 视频YUV取值范围标志的键，值类型为bool。 | 
| const char \* [OH_MD_KEY_COLOR_PRIMARIES](_codec_base.md#oh_md_key_color_primaries) | 视频色域的键, 值类型为int32_t, 请参见[OH_ColorPrimary](_codec_base.md#oh_colorprimary)。 | 
| const char \* [OH_MD_KEY_TRANSFER_CHARACTERISTICS](_codec_base.md#oh_md_key_transfer_characteristics) | 视频转移特性的键，值类型为int32_t,请参见[OH_TransferCharacteristic](_codec_base.md#oh_transfercharacteristic)。 | 
| const char \* [OH_MD_KEY_MATRIX_COEFFICIENTS](_codec_base.md#oh_md_key_matrix_coefficients) | 视频矩阵系数的键，值类型为int32_t,请参见[OH_MatrixCoefficient](_codec_base.md#oh_matrixcoefficient)。 | 
| const char \* [OH_MD_KEY_REQUEST_I_FRAME](_codec_base.md#oh_md_key_request_i_frame) | 请求立即编码I帧的键。值类型为bool。 | 
| const char \* [OH_MD_KEY_QUALITY](_codec_base.md#oh_md_key_quality) | 所需编码质量的键。值类型为uint32_t，此键仅适用于配置在恒定质量模式下的编码器。 | 
| const char \* [OH_MD_KEY_CODEC_CONFIG](_codec_base.md#oh_md_key_codec_config) | 编解码器特定数据的键，值类型为uint8_t\*。 | 
| const char \* [OH_MD_KEY_TITLE](_codec_base.md#oh_md_key_title) | 源格式标题的键，值类型为string。 | 
| const char \* [OH_MD_KEY_ARTIST](_codec_base.md#oh_md_key_artist) | 艺术家的源格式键，值类型为string。 | 
| const char \* [OH_MD_KEY_ALBUM](_codec_base.md#oh_md_key_album) | 相册的源格式键，值类型为string。 | 
| const char \* [OH_MD_KEY_ALBUM_ARTIST](_codec_base.md#oh_md_key_album_artist) | 相册艺术家的键，值类型为string。 | 
| const char \* [OH_MD_KEY_DATE](_codec_base.md#oh_md_key_date) | 源格式日期的键，值类型为string。 | 
| const char \* [OH_MD_KEY_COMMENT](_codec_base.md#oh_md_key_comment) | 源格式注释的键，值类型为string。 | 
| const char \* [OH_MD_KEY_GENRE](_codec_base.md#oh_md_key_genre) | 源格式类型的键，值类型为string。 | 
| const char \* [OH_MD_KEY_COPYRIGHT](_codec_base.md#oh_md_key_copyright) | 源格式版权的键，值类型为string。 | 
| const char \* [OH_MD_KEY_LANGUAGE](_codec_base.md#oh_md_key_language) | 源格式语言的键，值类型为string。 | 
| const char \* [OH_MD_KEY_DESCRIPTION](_codec_base.md#oh_md_key_description) | 源格式描述的键，值类型为string。 | 
| const char \* [OH_MD_KEY_LYRICS](_codec_base.md#oh_md_key_lyrics) | 源格式歌词的键，值类型为string。 | 
| const char \* [OH_MD_KEY_TRACK_COUNT](_codec_base.md#oh_md_key_track_count) | 源格式轨道数量的键，值类型为uint32_t。 | 
| const char \* [OH_MD_KEY_CHANNEL_LAYOUT](_codec_base.md#oh_md_key_channel_layout) | 所需编码通道布局的键。值类型为int64_t，此键仅适用于编码器。 | 
| const char \* [OH_MD_KEY_BITS_PER_CODED_SAMPLE](_codec_base.md#oh_md_key_bits_per_coded_sample) | 每个编码样本位数的键，值类型为uint32_t，支持flac编码器，请参见[OH_BitsPerSample](_codec_base.md#oh_bitspersample)。 | 
| const char \* [OH_MD_KEY_AAC_IS_ADTS](_codec_base.md#oh_md_key_aac_is_adts) | aac格式的键，值类型为uint32_t,aac解码器支持。 | 
| const char \* [OH_MD_KEY_SBR](_codec_base.md#oh_md_key_sbr) | aac sbr模式的键，值类型为uint32_t,aac编码器支持。 | 
| const char \* [OH_MD_KEY_COMPLIANCE_LEVEL](_codec_base.md#oh_md_key_compliance_level) | flac合规性级别的键，值类型为int32_t。 | 
| const char \* [OH_MD_KEY_IDENTIFICATION_HEADER](_codec_base.md#oh_md_key_identification_header) | vorbis标识头的键，值类型为uint8_t\*，仅vorbis解码器支持。 | 
| const char \* [OH_MD_KEY_SETUP_HEADER](_codec_base.md#oh_md_key_setup_header) | vorbis设置头的键，值类型为uint8_t\*，仅vorbis解码器支持。 | 
| const char \* [OH_MD_KEY_SCALING_MODE](_codec_base.md#oh_md_key_scaling_mode) | 视频表面尺度类型, 值类型为int32_t, 请参见[OH_ScalingMode](_codec_base.md#oh_scalingmode)。 | 
| const char \* [OH_MD_MAX_INPUT_BUFFER_COUNT](_codec_base.md#oh_md_max_input_buffer_count) | 最大输入缓冲区个数的键, 值类型为int32_t。 | 
| const char \* [OH_MD_MAX_OUTPUT_BUFFER_COUNT](_codec_base.md#oh_md_max_output_buffer_count) | 最大输出缓冲区个数的键, 值类型int32_t。 | 
| const char \* [OH_MD_KEY_AUDIO_COMPRESSION_LEVEL](_codec_base.md#oh_md_key_audio_compression_level) | 音频编解码压缩水平的键，值类型为uint32_t。 | 
| const char \* [OH_MD_KEY_VIDEO_IS_HDR_VIVID](_codec_base.md#oh_md_key_video_is_hdr_vivid) | 查询是否是hdr vivid的键，值类型为bool。 | 
| const char \* [OH_MD_KEY_AUDIO_OBJECT_NUMBER](_codec_base.md#oh_md_key_audio_object_number) | 音频对象数目的键. 值类型为int32_t。 | 
| const char \* [OH_MD_KEY_AUDIO_VIVID_METADATA](_codec_base.md#oh_md_key_audio_vivid_metadata) | audio vivid元数据的键，值类型为uint8_t\*。 | 
