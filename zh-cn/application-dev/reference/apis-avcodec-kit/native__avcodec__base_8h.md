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
| struct  [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) | OH_AVCodec中所有异步回调函数指针的集合。（API11废弃）  | 
| struct  [OH_AVCodecCallback](_o_h___a_v_codec_callback.md) | OH_AVCodec中所有异步回调函数指针的集合。  | 
| struct  [OH_AVDataSource](_o_h___a_v_data_source.md) | 用户自定义数据源。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef void(\* [OH_AVCodecOnError](_codec_base.md#oh_avcodeconerror)) (OH_AVCodec \*codec, int32_t errorCode, void \*userData) | 当OH_AVCodec实例运行出错时，会调用来上报具体的错误信息的函数指针。 | 
| typedef void(\* [OH_AVCodecOnStreamChanged](_codec_base.md#oh_avcodeconstreamchanged)) (OH_AVCodec \*codec, OH_AVFormat \*format, void \*userData) | 当解码输入码流分辨率或者编码输出码流的分辨率发生变化时，调用此函数指针报告新的流描述信息。 | 
| typedef void(\* [OH_AVCodecOnNeedInputData](_codec_base.md#oh_avcodeconneedinputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, void \*userData) | 当OH_AVCodec在运行过程中需要新的输入数据时，将调用此函数指针，并携带可用的缓冲区来填充新的输入数据。（API11废弃） | 
| typedef void(\* [OH_AVCodecOnNewOutputData](_codec_base.md#oh_avcodeconnewoutputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr, void \*userData) | 当OH_AVCodec运行过程中生成新的输出数据时，将调用此函数指针，并携带包含新输出数据的缓冲区。（API11废弃） | 
| typedef void(\* [OH_AVCodecOnNeedInputBuffer](_codec_base.md#oh_avcodeconneedinputbuffer)) (OH_AVCodec \*codec, uint32_t index, OH_AVBuffer \*buffer, void \*userData) | 当OH_AVCodec在运行过程中需要新的输入数据时，将调用此函数指针，并携带可用的缓冲区来填充新的输入数据。 | 
| typedef void(\* [OH_AVCodecOnNewOutputBuffer](_codec_base.md#oh_avcodeconnewoutputbuffer)) (OH_AVCodec \*codec, uint32_t index, OH_AVBuffer \*buffer, void \*userData) | 当OH_AVCodec运行过程中生成新的输出数据时，将调用此函数指针，并携带包含新输出数据的缓冲区。 | 
| typedef struct [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) [OH_AVCodecAsyncCallback](_codec_base.md#oh_avcodecasynccallback) | OH_AVCodec中所有异步回调函数指针的集合。（API11废弃） | 
| typedef struct [OH_AVCodecCallback](_o_h___a_v_codec_callback.md) [OH_AVCodecCallback](_codec_base.md#oh_avcodeccallback) | OH_AVCodec中所有异步回调函数指针的集合。 | 
| typedef int32_t(\* [OH_AVDataSourceReadAt](_codec_base.md#oh_avdatasourcereadat)) (OH_AVBuffer \*data, int32_t length, int64_t offset) | 函数指针定义，用于提供获取用户自定义媒体数据的能力。  | 
| typedef struct [OH_AVDataSource](_o_h___a_v_data_source.md) [OH_AVDataSource](_codec_base.md#oh_avdatasource) | 用户自定义数据源。  | 
| typedef enum [OH_MediaType](_codec_base.md#oh_mediatype-1) [OH_MediaType](_codec_base.md#oh_mediatype) | 媒体类型。 | 
| typedef enum [OH_AACProfile](_codec_base.md#oh_aacprofile-1) [OH_AACProfile](_codec_base.md#oh_aacprofile) | AAC档次。 | 
| typedef enum [OH_AVCProfile](_codec_base.md#oh_avcprofile-1) [OH_AVCProfile](_codec_base.md#oh_avcprofile) | AVC档次。 | 
| typedef enum [OH_HEVCProfile](_codec_base.md#oh_hevcprofile-1) [OH_HEVCProfile](_codec_base.md#oh_hevcprofile) | HEVC档次。 | 
| typedef enum [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat-1) [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat) | 封装器支持的输出文件格式。 | 
| typedef enum [OH_AVSeekMode](_codec_base.md#oh_avseekmode-1) [OH_AVSeekMode](_codec_base.md#oh_avseekmode) | 跳转模式。 | 
| typedef enum [OH_ScalingMode](_codec_base.md#oh_scalingmode-1) [OH_ScalingMode](_codec_base.md#oh_scalingmode) | 缩放模式，只在surface模式下使用。 | 
| typedef enum [OH_BitsPerSample](_codec_base.md#oh_bitspersample-1) [OH_BitsPerSample](_codec_base.md#oh_bitspersample) | 每个编码样本的音频位数。 | 
| typedef enum [OH_ColorPrimary](_codec_base.md#oh_colorprimary-1) [OH_ColorPrimary](_codec_base.md#oh_colorprimary) | 色域。 | 
| typedef enum [OH_TransferCharacteristic](_codec_base.md#oh_transfercharacteristic-1) [OH_TransferCharacteristic](_codec_base.md#oh_transfercharacteristic) | 转移特性。 | 
| typedef enum [OH_MatrixCoefficient](_codec_base.md#oh_matrixcoefficient-1) [OH_MatrixCoefficient](_codec_base.md#oh_matrixcoefficient) | 矩阵系数。 | 
| typedef enum [OH_AVCLevel](_codec_base.md#oh_avclevel-1) [OH_AVCLevel](_codec_base.md#oh_avclevel) | AVC级别。  | 
| typedef enum [OH_HEVCLevel](_codec_base.md#oh_hevclevel-1) [OH_HEVCLevel](_codec_base.md#oh_hevclevel) | HEVC级别。  | 
| typedef enum [OH_TemporalGopReferenceMode](_codec_base.md#oh_temporalgopreferencemode-1) [OH_TemporalGopReferenceMode](_codec_base.md#oh_temporalgopreferencemode) | 时域图片组参考模式。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_MediaType](_codec_base.md#oh_mediatype-1) {<br/>MEDIA_TYPE_AUD = 0,<br/>MEDIA_TYPE_VID = 1，<br/>MEDIA_TYPE_SUBTITILE = 2<br/>} | 媒体类型。 |
| [OH_AACProfile](_codec_base.md#oh_aacprofile-1) { AAC_PROFILE_LC = 0 } | AAC档次。 | 
| [OH_AVCProfile](_codec_base.md#oh_avcprofile-1) {<br/>AVC_PROFILE_BASELINE = 0,<br/>AVC_PROFILE_HIGH = 4,<br/>AVC_PROFILE_MAIN = 8<br/>} | AVC档次。 | 
| [OH_HEVCProfile](_codec_base.md#oh_hevcprofile-1) {<br/>HEVC_PROFILE_MAIN = 0,<br/>HEVC_PROFILE_MAIN_10 = 1,<br/>HEVC_PROFILE_MAIN_STILL = 2,<br/>HEVC_PROFILE_MAIN_10_HDR10 = 3,<br/>HEVC_PROFILE_MAIN_10_HDR10_PLUS = 4<br/>} | HEVC档次。 | 
| [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat-1) {<br/>AV_OUTPUT_FORMAT_DEFAULT = 0,<br/>AV_OUTPUT_FORMAT_MPEG_4 = 2,<br/>AV_OUTPUT_FORMAT_M4A = 6,<br/>AV_OUTPUT_FORMAT_AMR = 8,<br/>AV_OUTPUT_FORMAT_MP3 = 9,<br/>AV_OUTPUT_FORMAT_WAV = 10<br/>} | 封装器支持的输出文件格式。 | 
| [OH_AVSeekMode](_codec_base.md#oh_avseekmode-1) {<br/>SEEK_MODE_NEXT_SYNC = 0,<br/>SEEK_MODE_PREVIOUS_SYNC,<br/>SEEK_MODE_CLOSEST_SYNC<br/>} | 跳转模式。 | 
| [OH_ScalingMode](_codec_base.md#oh_scalingmode-1) {<br/>SCALING_MODE_SCALE_TO_WINDOW = 1,<br/>SCALING_MODE_SCALE_CROP = 2<br/>} | 缩放模式。 | 
| [OH_BitsPerSample](_codec_base.md#oh_bitspersample-1) {<br/>SAMPLE_U8 = 0, SAMPLE_S16LE = 1,<br/>SAMPLE_S24LE = 2, SAMPLE_S32LE = 3,<br/>SAMPLE_F32LE = 4, SAMPLE_U8P = 5,<br/>SAMPLE_S16P = 6, SAMPLE_S24P = 7,<br/>SAMPLE_S32P = 8, SAMPLE_F32P = 9,<br/>INVALID_WIDTH = -1<br/>} | 每个编码样本的音频位数。 | 
| [OH_ColorPrimary](_codec_base.md#oh_colorprimary-1) {<br/>COLOR_PRIMARY_BT709 = 1,<br/>COLOR_PRIMARY_UNSPECIFIED = 2,<br/>COLOR_PRIMARY_BT470_M = 4,<br/>COLOR_PRIMARY_BT601_625 = 5,<br/>COLOR_PRIMARY_BT601_525 = 6,<br/>COLOR_PRIMARY_SMPTE_ST240 = 7,<br/>COLOR_PRIMARY_GENERIC_FILM = 8,<br/>COLOR_PRIMARY_BT2020 = 9,<br/>COLOR_PRIMARY_SMPTE_ST428 = 10,<br/>COLOR_PRIMARY_P3DCI = 11,<br/>COLOR_PRIMARY_P3D65 = 12<br/>} | 色域。 | 
| [OH_TransferCharacteristic](_codec_base.md#oh_transfercharacteristic-1) {<br/>TRANSFER_CHARACTERISTIC_BT709 = 1,<br/>TRANSFER_CHARACTERISTIC_UNSPECIFIED = 2,<br/>TRANSFER_CHARACTERISTIC_GAMMA_2_2 = 4,<br/>TRANSFER_CHARACTERISTIC_GAMMA_2_8 = 5,<br/>TRANSFER_CHARACTERISTIC_BT601 = 6,<br/>TRANSFER_CHARACTERISTIC_SMPTE_ST240 = 7,<br/>TRANSFER_CHARACTERISTIC_LINEAR = 8,<br/>TRANSFER_CHARACTERISTIC_LOG = 9,<br/>TRANSFER_CHARACTERISTIC_LOG_SQRT = 10,<br/>TRANSFER_CHARACTERISTIC_IEC_61966_2_4 = 11,<br/>TRANSFER_CHARACTERISTIC_BT1361 = 12,<br/>TRANSFER_CHARACTERISTIC_IEC_61966_2_1 = 13,<br/>TRANSFER_CHARACTERISTIC_BT2020_10BIT = 14,<br/>TRANSFER_CHARACTERISTIC_BT2020_12BIT = 15,<br/>TRANSFER_CHARACTERISTIC_PQ = 16,<br/>TRANSFER_CHARACTERISTIC_SMPTE_ST428 = 17,<br/>TRANSFER_CHARACTERISTIC_HLG = 18<br/>} | 转移特性。 | 
| [OH_MatrixCoefficient](_codec_base.md#oh_matrixcoefficient-1) {<br/>MATRIX_COEFFICIENT_IDENTITY = 0,<br/>MATRIX_COEFFICIENT_BT709 = 1,<br/>MATRIX_COEFFICIENT_UNSPECIFIED = 2,<br/>MATRIX_COEFFICIENT_FCC = 4,<br/>MATRIX_COEFFICIENT_BT601_625 = 5,<br/>MATRIX_COEFFICIENT_BT601_525 = 6, MATRIX_COEFFICIENT_SMPTE_ST240 = 7,<br/>MATRIX_COEFFICIENT_YCGCO = 8,<br/>MATRIX_COEFFICIENT_BT2020_NCL = 9,<br/>MATRIX_COEFFICIENT_BT2020_CL = 10,<br/>MATRIX_COEFFICIENT_SMPTE_ST2085 = 11,<br/>MATRIX_COEFFICIENT_CHROMATICITY_NCL = 12,<br/>MATRIX_COEFFICIENT_CHROMATICITY_CL = 13,<br/>MATRIX_COEFFICIENT_ICTCP = 14<br/>} | 矩阵系数。 | 
| [OH_AVCLevel](_codec_base.md#oh_avclevel-1) {<br/>AVC_LEVEL_1 = 0, <br/>AVC_LEVEL_1b = 1, <br/>AVC_LEVEL_11 = 2, <br/>AVC_LEVEL_12 = 3,<br/>AVC_LEVEL_13 = 4, <br/>AVC_LEVEL_2 = 5, <br/>AVC_LEVEL_21 = 6, <br/>AVC_LEVEL_22 = 7,<br/>AVC_LEVEL_3 = 8, <br/>AVC_LEVEL_31 = 9, <br/>AVC_LEVEL_32 = 10, <br/>AVC_LEVEL_4 = 11,<br/>AVC_LEVEL_41 = 12, <br/>AVC_LEVEL_42 = 13, <br/>AVC_LEVEL_5 = 14, <br/>AVC_LEVEL_51 = 15, <br/>AVC_LEVEL_52 = 16, <br/>AVC_LEVEL_6 = 17, <br/>AVC_LEVEL_61 = 18, <br/>AVC_LEVEL_62 = 19<br/>} | AVC级别。  | 
| [OH_HEVCLevel](_codec_base.md#oh_hevclevel-1) {<br/>HEVC_LEVEL_1 = 0, <br/>HEVC_LEVEL_2 = 1, <br/>HEVC_LEVEL_21 = 2, <br/>HEVC_LEVEL_3 = 3,<br/>HEVC_LEVEL_31 = 4, <br/>HEVC_LEVEL_4 = 5, <br/>HEVC_LEVEL_41 = 6, <br/>HEVC_LEVEL_5 = 7,<br/>HEVC_LEVEL_51 = 8, <br/>HEVC_LEVEL_52 = 9, <br/>HEVC_LEVEL_6 = 10, <br/>HEVC_LEVEL_61 = 11,<br/>HEVC_LEVEL_62 = 12<br/>} | HEVC级别。  | 
| [OH_TemporalGopReferenceMode](_codec_base.md#oh_temporalgopreferencemode-1) { <br/>ADJACENT_REFERENCE = 0, <br/>JUMP_REFERENCE = 1, <br/>UNIFORMLY_SCALED_REFERENCE = 2 <br/>} | 时域图片组参考模式。  | 


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
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_VIVID](_codec_base.md#oh_avcodec_mimetype_audio_vivid) | Audio Vivid音频解码器的MIME类型。<!--Del-->（此规格暂未开放）<!--DelEnd-->  | 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_AMR_NB](_codec_base.md#oh_avcodec_mimetype_audio_amr_nb) | AMR_NB音频解码器的MIME类型。 | 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_AMR_WB](_codec_base.md#oh_avcodec_mimetype_audio_amr_wb) | AMR_WB音频解码器的MIME类型。 | 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_OPUS](_codec_base.md#oh_avcodec_mimetype_audio_opus) | OPUS音频编解码器的MIME类型。<!--Del-->（此规格暂未开放）<!--DelEnd-->  | 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_G711MU](_codec_base.md#oh_avcodec_mimetype_audio_g711mu) | G711MU音频编解码器的MIME类型。 | 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_APE](_codec_base.md#oh_avcodec_mimetype_audio_ape) |APE音频解码器的MIME类型。                         |
| const char \* [OH_AVCODEC_MIMETYPE_SUBTITLE_SRT](_codec_base.md#oh_avcodec_mimetype_subtitle_srt) |SRT字幕解封装器的MIME类型。                         |
| const char \* [OH_AVCODEC_MIMETYPE_SUBTITLE_WEBVTT](_codec_base.md#oh_avcodec_mimetype_subtitle_webvtt) |WEBVTT字幕解封装器的MIME类型。                         |
| const char \* [OH_ED_KEY_TIME_STAMP](_codec_base.md#oh_ed_key_time_stamp) | 表示surfacebuffer中时间戳的键，值类型为int64_t。<!--Del-->（此功能暂未支持）<!--DelEnd--> |
| const char \* [OH_ED_KEY_EOS](_codec_base.md#oh_ed_key_eos) | 表示surfacebuffer中流结束符的键，值类型为int32_t。 <!--Del-->（此功能暂未支持）<!--DelEnd-->|
| const char \* [OH_MD_KEY_TRACK_TYPE](_codec_base.md#oh_md_key_track_type) | 轨道媒体类型的键，值类型为int32_t，请参见[OH_MediaType](_codec_base.md#oh_mediatype-1)。 | 
| const char \* [OH_MD_KEY_CODEC_MIME](_codec_base.md#oh_md_key_codec_mime) | 编解码器MIME类型的键，值类型为string。 |
| const char \* [OH_MD_KEY_DURATION](_codec_base.md#oh_md_key_duration) | 媒体文件持续时间的键，值类型为int64_t。 | 
| const char \* [OH_MD_KEY_BITRATE](_codec_base.md#oh_md_key_bitrate) | 比特率的键，值类型为int64_t。 | 
| const char \* [OH_MD_KEY_MAX_INPUT_SIZE](_codec_base.md#oh_md_key_max_input_size) | 设置解码输入码流大小最大值的键，值类型为int32_t。 |
| const char \* [OH_MD_KEY_WIDTH](_codec_base.md#oh_md_key_width) | 视频宽度的键，值类型为int32_t。 | 
| const char \* [OH_MD_KEY_HEIGHT](_codec_base.md#oh_md_key_height) | 视频高度键，值类型为int32_t。 | 
| const char \* [OH_MD_KEY_PIXEL_FORMAT](_codec_base.md#oh_md_key_pixel_format) | 视频像素格式的键，值类型为int32_t，请参见[OH_AVPixelFormat](_core.md#oh_avpixelformat)。 | 
| const char \* [OH_MD_KEY_AUDIO_SAMPLE_FORMAT](_codec_base.md#oh_md_key_audio_sample_format) | 音频原始格式的键，值类型为int32_t，请参见[OH_BitsPerSample](_codec_base.md#oh_bitspersample)。 | 
| const char \* [OH_MD_KEY_FRAME_RATE](_codec_base.md#oh_md_key_frame_rate) | 视频帧率的键，值类型为double。 | 
| const char \* [OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE](_codec_base.md#oh_md_key_video_encode_bitrate_mode) | 视频编码码率模式，值类型为int32_t，请参见[OH_VideoEncodeBitrateMode](_video_encoder.md#oh_videoencodebitratemode)。 | 
| const char \* [OH_MD_KEY_PROFILE](_codec_base.md#oh_md_key_profile) | 编码档次，值类型为int32_t，请参见[OH_AVCProfile](_codec_base.md#oh_avcprofile),[OH_HEVCProfile](_codec_base.md#oh_hevcprofile), [OH_AACProfile](_codec_base.md#oh_aacprofile)。 |
| const char \* [OH_MD_KEY_AUD_CHANNEL_COUNT](_codec_base.md#oh_md_key_aud_channel_count) | 音频通道计数键，值类型为int32_t。 | 
| const char \* [OH_MD_KEY_AUD_SAMPLE_RATE](_codec_base.md#oh_md_key_aud_sample_rate) | 音频采样率键，值类型为int32_t。 | 
| const char \* [OH_MD_KEY_I_FRAME_INTERVAL](_codec_base.md#oh_md_key_i_frame_interval) | 关键帧间隔的键，值类型为int32_t，单位为毫秒。 | 
| const char \* [OH_MD_KEY_ROTATION](_codec_base.md#oh_md_key_rotation) | surface旋转角度的键。值类型为int32_t：应为{0, 90, 180, 270}，默认值为0。该键只在视频解码surface模式下使用。 |
| const char \* [OH_MD_KEY_RANGE_FLAG](_codec_base.md#oh_md_key_range_flag) | 视频YUV值域标志的键，值类型为int32_t，1表示full range，0表示limited range。 |
| const char \* [OH_MD_KEY_COLOR_PRIMARIES](_codec_base.md#oh_md_key_color_primaries) | 视频色域的键，值类型为int32_t，请参见[OH_ColorPrimary](_codec_base.md#oh_colorprimary)，遵循H.273标准Table2。 | 
| const char \* [OH_MD_KEY_TRANSFER_CHARACTERISTICS](_codec_base.md#oh_md_key_transfer_characteristics) | 视频传递函数的键，值类型为int32_t，请参见[OH_TransferCharacteristic](_codec_base.md#oh_transfercharacteristic)，遵循H.273标准Table3。 | 
| const char \* [OH_MD_KEY_MATRIX_COEFFICIENTS](_codec_base.md#oh_md_key_matrix_coefficients) | 视频矩阵系数的键，值类型为int32_t，请参见[OH_MatrixCoefficient](_codec_base.md#oh_matrixcoefficient)，遵循H.273标准Table4。 | 
| const char \* [OH_MD_KEY_REQUEST_I_FRAME](_codec_base.md#oh_md_key_request_i_frame) | 请求立即编码I帧的键。值类型为int32_t。 |
| const char \* [OH_MD_KEY_QUALITY](_codec_base.md#oh_md_key_quality) | 所需编码质量的键。值类型为int32_t，此键仅适用于配置在恒定质量模式下的编码器。 | 
| const char \* [OH_MD_KEY_CODEC_CONFIG](_codec_base.md#oh_md_key_codec_config) | 编解码器特定数据的键，值类型为uint8_t\*。 <!--Del-->（视频编解码此功能暂未支持）<!--DelEnd--> |
| const char \* [OH_MD_KEY_TRACK_START_TIME](_codec_base.md#oh_md_key_track_start_time) | 轨道开始时间的键，值类型为int64_t。     |
| const char \* [OH_MD_KEY_TITLE](_codec_base.md#oh_md_key_title) | 媒体文件的标题的键，值类型为string。 | 
| const char \* [OH_MD_KEY_ARTIST](_codec_base.md#oh_md_key_artist) | 媒体文件艺术家的键，值类型为string。 | 
| const char \* [OH_MD_KEY_ALBUM](_codec_base.md#oh_md_key_album) | 专辑的媒体文件的键，值类型为string。 | 
| const char \* [OH_MD_KEY_ALBUM_ARTIST](_codec_base.md#oh_md_key_album_artist) | 专辑艺术家的键，值类型为string。 | 
| const char \* [OH_MD_KEY_DATE](_codec_base.md#oh_md_key_date) | 媒体文件日期的键，值类型为string，例如2024年。 | 
| const char \* [OH_MD_KEY_COMMENT](_codec_base.md#oh_md_key_comment) | 媒体文件注释的键，值类型为string。 | 
| const char \* [OH_MD_KEY_GENRE](_codec_base.md#oh_md_key_genre) | 媒体文件流派的键，值类型为string。 | 
| const char \* [OH_MD_KEY_COPYRIGHT](_codec_base.md#oh_md_key_copyright) | 媒体文件版权的键，值类型为string。 | 
| const char \* [OH_MD_KEY_LANGUAGE](_codec_base.md#oh_md_key_language) | 媒体文件语言的键，值类型为string。 | 
| const char \* [OH_MD_KEY_DESCRIPTION](_codec_base.md#oh_md_key_description) | 媒体文件描述的键，值类型为string。 | 
| const char \* [OH_MD_KEY_LYRICS](_codec_base.md#oh_md_key_lyrics) | 媒体文件歌词的键，值类型为string。 | 
| const char \* [OH_MD_KEY_TRACK_COUNT](_codec_base.md#oh_md_key_track_count) | 媒体文件轨道数量的键，值类型为int32_t。 | 
| const char \* [OH_MD_KEY_CHANNEL_LAYOUT](_codec_base.md#oh_md_key_channel_layout) | 所需编码通道布局的键。值类型为int64_t，此键仅适用于编码器。 | 
| const char \* [OH_MD_KEY_BITS_PER_CODED_SAMPLE](_codec_base.md#oh_md_key_bits_per_coded_sample) | 每个编码样本位数的键，值类型为int32_t，支持flac编码器，请参见[OH_BitsPerSample](_codec_base.md#oh_bitspersample)。 | 
| const char \* [OH_MD_KEY_AAC_IS_ADTS](_codec_base.md#oh_md_key_aac_is_adts) | aac格式的键，aac格式分为ADTS格式和LATM格式。值类型为int32_t，aac解码器支持。 |
| const char \* [OH_MD_KEY_SBR](_codec_base.md#oh_md_key_sbr) | aac sbr模式的键，值类型为int32_t，aac编码器支持。 | 
| const char \* [OH_MD_KEY_COMPLIANCE_LEVEL](_codec_base.md#oh_md_key_compliance_level) | flac兼容性等级的键，值类型为int32_t，仅在音频编码使用。 | 
| const char \* [OH_MD_KEY_IDENTIFICATION_HEADER](_codec_base.md#oh_md_key_identification_header) | vorbis标识头的键，值类型为uint8_t\*，仅vorbis解码器支持。 | 
| const char \* [OH_MD_KEY_SETUP_HEADER](_codec_base.md#oh_md_key_setup_header) | vorbis设置头的键，值类型为uint8_t\*，仅vorbis解码器支持。 | 
| const char \* [OH_MD_KEY_SCALING_MODE](_codec_base.md#oh_md_key_scaling_mode) | 视频缩放模式，值类型为int32_t，请参见[OH_ScalingMode](_codec_base.md#oh_scalingmode)。 该键只在视频解码surface模式下使用。建议直接调用[OH_NativeWindow_NativeWindowSetScalingModeV2](../apis-arkgraphics2d/_native_window.md)接口进行设置 |
| const char \* [OH_MD_MAX_INPUT_BUFFER_COUNT](_codec_base.md#oh_md_max_input_buffer_count) | 最大输入缓冲区个数的键，值类型为int32_t。 | 
| const char \* [OH_MD_MAX_OUTPUT_BUFFER_COUNT](_codec_base.md#oh_md_max_output_buffer_count) | 最大输出缓冲区个数的键，值类型int32_t。 | 
| const char \* [OH_MD_KEY_AUDIO_COMPRESSION_LEVEL](_codec_base.md#oh_md_key_audio_compression_level) | 音频编解码压缩水平的键，只在音频编码使用，值类型为int32_t。 | 
| const char \* [OH_MD_KEY_VIDEO_IS_HDR_VIVID](_codec_base.md#oh_md_key_video_is_hdr_vivid) | 媒体文件中的视频轨是否为HDR Vivid的键，支持封装和解封装，值类型为int32_t。 |
| const char \* [OH_MD_KEY_AUDIO_OBJECT_NUMBER](_codec_base.md#oh_md_key_audio_object_number) | 音频对象数目的键，值类型为int32_t，只有Audio Vivid解码使用。 | 
| const char \* [OH_MD_KEY_AUDIO_VIVID_METADATA](_codec_base.md#oh_md_key_audio_vivid_metadata) | Audio Vivid元数据的键，值类型为uint8_t\*，只有Audio Vivid解码使用。 | 
| const char \* [OH_FEATURE_PROPERTY_KEY_VIDEO_ENCODER_MAX_LTR_FRAME_COUNT](_codec_base.md#oh_feature_property_key_video_encoder_max_ltr_frame_count) | 在视频编码中获取长期参考帧的最大个数的键，值类型为int32_t。  | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_ENABLE_TEMPORAL_SCALABILITY](_codec_base.md#oh_md_key_video_encoder_enable_temporal_scalability) | 使能分层编码的键，值类型为int32_t，1表示使能，0表示其它情况。 | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_SIZE](_codec_base.md#oh_md_key_video_encoder_temporal_gop_size) | 描述图片组基本层图片的间隔大小的键，值类型为int32_t，只在使能分层编码时生效。  |
| const char \* [OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_REFERENCE_MODE](_codec_base.md#oh_md_key_video_encoder_temporal_gop_reference_mode) | 描述图片组内参考模式的键，值类型为int32_t，请参见[OH_TemporalGopReferenceMode](_codec_base.md#oh_temporalgopreferencemode)，只在使能分层编码时生效。 | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_LTR_FRAME_COUNT](_codec_base.md#oh_md_key_video_encoder_ltr_frame_count) | 描述长期参考帧个数的键，值类型为int32_t，必须在支持的值范围内使用。该键是可选的且只用于视频编码。  | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_MARK_LTR](_codec_base.md#oh_md_key_video_encoder_per_frame_mark_ltr) | 标记当前帧为长期参考帧的键，值类型为int32_t，1表示被标记，0表示其它情况。该键是可选的且只用于视频编码。  | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_USE_LTR](_codec_base.md#oh_md_key_video_encoder_per_frame_use_ltr) | 描述当前帧参考的长期参考帧帧号的键，值类型为int32_t。该键是可选的且只用于视频编码。  | 
| const char \* [OH_MD_KEY_VIDEO_PER_FRAME_IS_LTR](_codec_base.md#oh_md_key_video_per_frame_is_ltr) | 当前OH_AVBuffer中输出的码流对应的帧是否为长期参考帧的键，值类型为int32_t，1表示是LTR，0表示其它情况。该键是可选的且只用于视频编码。 | 
| const char \* [OH_MD_KEY_VIDEO_PER_FRAME_POC](_codec_base.md#oh_md_key_video_per_frame_poc) | 描述帧的POC的键，值类型为int32_t。该键是可选的且只用于视频编码。  | 
| const char \* [OH_MD_KEY_VIDEO_CROP_TOP](_codec_base.md#oh_md_key_video_crop_top) | 描述裁剪矩形顶部坐标(y)值的键，值类型为int32_t。 该键只用于视频解码。| 
| const char \* [OH_MD_KEY_VIDEO_CROP_BOTTOM](_codec_base.md#oh_md_key_video_crop_bottom) | 描述裁剪矩形底部坐标(y)值的键，值类型为int32_t。该键只用于视频解码。   | 
| const char \* [OH_MD_KEY_VIDEO_CROP_LEFT](_codec_base.md#oh_md_key_video_crop_left) | 描述裁剪矩形左坐标(x)值的键，值类型为int32_t。该键只用于视频解码。  | 
| const char \* [OH_MD_KEY_VIDEO_CROP_RIGHT](_codec_base.md#oh_md_key_video_crop_right) | 描述裁剪矩形右坐标(x)值的键，值类型为int32_t。该键只用于视频解码。  | 
| const char \* [OH_MD_KEY_VIDEO_STRIDE](_codec_base.md#oh_md_key_video_stride) | 描述视频帧宽跨距的键，值类型为int32_t。  | 
| const char \* [OH_MD_KEY_VIDEO_SLICE_HEIGHT](_codec_base.md#oh_md_key_video_slice_height) | 描述视频帧高跨距的键，值类型为int32_t。  | 
| const char \* [OH_MD_KEY_VIDEO_PIC_WIDTH](_codec_base.md#oh_md_key_video_pic_width) | 描述视频帧真实宽度的键，值类型为int32_t。  | 
| const char \* [OH_MD_KEY_VIDEO_PIC_HEIGHT](_codec_base.md#oh_md_key_video_pic_height) | 描述视频帧真实高度的键，值类型为int32_t。  | 
| const char \* [OH_MD_KEY_VIDEO_ENABLE_LOW_LATENCY](_codec_base.md#oh_md_key_video_enable_low_latency) | 使能低时延视频编解码的键，值类型为int32_t，1表示使能，0表示其它情况。  | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_QP_MAX](_codec_base.md#oh_md_key_video_encoder_qp_max) | 描述视频编码器允许的最大量化参数的键，值类型为int32_t。  | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_QP_MIN](_codec_base.md#oh_md_key_video_encoder_qp_min) | 描述视频编码器允许的最小量化参数的键，值类型为int32_t。  | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_QP_AVERAGE](_codec_base.md#oh_md_key_video_encoder_qp_average) | 描述视频帧平均量化参数的键，值类型为int32_t。 |
| const char \* [OH_MD_KEY_VIDEO_ENCODER_MSE](_codec_base.md#oh_md_key_video_encoder_mse)     |描述视频帧平方误差的键，值类型为double。  |
| const char \* [OH_MD_KEY_DECODING_TIMESTAMP](_codec_base.md#oh_md_key_decoding_timestamp) | AVBuffer中携带的音视频或字幕的sample对应的解码时间戳的键，以微秒为单位，值类型为int64_t。  |
| const char \* [OH_MD_KEY_BUFFER_DURATION](_codec_base.md#oh_md_key_buffer_duration) | AVBuffer中携带的音视频或字幕的sample对应的持续时间的键，以微秒为单位，值类型为int64_t。       |
| const char \* [OH_MD_KEY_START_TIME](_codec_base.md#oh_md_key_start_time) | 媒体文件中第一帧起始位置的开始时间的键，值类型为int64_t。     |
| const char \* [OH_MD_KEY_VIDEO_DECODER_OUTPUT_COLOR_SPACE](_codec_base.md#oh_md_key_video_decoder_output_color_space)   | 设置视频解码器输出色彩空间的键，值类型为int32_t。 支持的值为OH_COLORSPACE_BT709_LIMIT。|
| const char \* [OH_MD_KEY_TRACK_START_TIME](_codec_base.md#oh_md_key_track_start_time) | 轨道开始时间的键，值类型为int64_t。     |
| const char \* [OH_MD_KEY_VIDEO_SAR](_codec_base.md#oh_md_key_video_sar)            | 样本长宽比的键，值类型为double。 |