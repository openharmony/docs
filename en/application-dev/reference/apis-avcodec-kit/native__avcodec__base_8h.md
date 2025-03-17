# native_avcodec_base.h


## Overview

The **native_avcodec_base.h** file declares the native APIs used for basic audio and video muxing, demuxing, encoding, and decoding.

**Library**: libnative_media_codecbase.so

**Since**: 9

**Related module**: [CodecBase](_codec_base.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) | Describes all the asynchronous callback function pointers of an **OH_AVCodec** instance. (This struct is deprecated from API version 11.) | 
| struct  [OH_AVCodecCallback](_o_h___a_v_codec_callback.md) | Describes all the callback function pointers of an **OH_AVCodec** instance. | 
| struct  [OH_AVDataSource](_o_h___a_v_data_source.md) | Describes a user-defined data source. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef void(\* [OH_AVCodecOnError](_codec_base.md#oh_avcodeconerror)) (OH_AVCodec \*codec, int32_t errorCode, void \*userData) | Defines the pointer to the function that is called to report error information when an error occurs during the running of an **OH_AVCodec** instance.| 
| typedef void(\* [OH_AVCodecOnStreamChanged](_codec_base.md#oh_avcodeconstreamchanged)) (OH_AVCodec \*codec, OH_AVFormat \*format, void \*userData) | Defines the pointer to the function that is called to report the new stream description when the resolution of the input video stream being decoded or the output video stream that has been encoded changes.<br>From API version 15, this function pointer is called to report the new stream description when the stream sampling rate, number of audio channels, or audio sampling format changes during audio decoding. The decoding formats that can detect these changes include <!--RP1--><!--RP1End-->AAC, FLAC, MP3, and VORBIS.| 
| typedef void(\* [OH_AVCodecOnNeedInputData](_codec_base.md#oh_avcodeconneedinputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, void \*userData) | Defines the pointer to the function that is called when new input data is required during the running of an **OH_AVCodec** instance. The function carries a buffer to fill in new input data. (This type is deprecated from API version 11.)| 
| typedef void(\* [OH_AVCodecOnNewOutputData](_codec_base.md#oh_avcodeconnewoutputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr, void \*userData) | Defines the pointer to the function that is called when new output data is generated during the running of an **OH_AVCodec** instance. The function carries a buffer filled with new output data. (This type is deprecated from API version 11.)| 
| typedef void(\* [OH_AVCodecOnNeedInputBuffer](_codec_base.md#oh_avcodeconneedinputbuffer)) (OH_AVCodec \*codec, uint32_t index, OH_AVBuffer \*buffer, void \*userData) | Defines the pointer to the function that is called when new input data is required during the running of an **OH_AVCodec** instance. The function carries a buffer to fill in new input data.| 
| typedef void(\* [OH_AVCodecOnNewOutputBuffer](_codec_base.md#oh_avcodeconnewoutputbuffer)) (OH_AVCodec \*codec, uint32_t index, OH_AVBuffer \*buffer, void \*userData) | Defines the pointer to the function that is called when new output data is generated during the running of an **OH_AVCodec** instance. The function carries a buffer filled with new output data.| 
| typedef struct [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) [OH_AVCodecAsyncCallback](_codec_base.md#oh_avcodecasynccallback) | Defines a struct for all the asynchronous callback function pointers of an **OH_AVCodec** instance. (This type is deprecated from API version 11.)| 
| typedef struct [OH_AVCodecCallback](_o_h___a_v_codec_callback.md) [OH_AVCodecCallback](_codec_base.md#oh_avcodeccallback) | Defines a struct for all the callback function pointers of an **OH_AVCodec** instance.| 
| typedef int32_t(\* [OH_AVDataSourceReadAt](_codec_base.md#oh_avdatasourcereadat)) (OH_AVBuffer \*data, int32_t length, int64_t offset) | Defines a function pointer used to provide the capability of obtaining user-defined media data. | 
| typedef struct [OH_AVDataSource](_o_h___a_v_data_source.md) [OH_AVDataSource](_codec_base.md#oh_avdatasource) | Defines a struct for the user-defined data source. | 
| typedef enum [OH_MediaType](_codec_base.md#oh_mediatype-1) [OH_MediaType](_codec_base.md#oh_mediatype) | Defines an enum for media types.| 
| typedef enum [OH_AACProfile](_codec_base.md#oh_aacprofile-1) [OH_AACProfile](_codec_base.md#oh_aacprofile) | Defines an enum for Advanced Audio Coding (AAC) profiles.| 
| typedef enum [OH_AVCProfile](_codec_base.md#oh_avcprofile-1) [OH_AVCProfile](_codec_base.md#oh_avcprofile) | Defines an enum for Advanced Video Coding (AVC) profiles.| 
| typedef enum [OH_HEVCProfile](_codec_base.md#oh_hevcprofile-1) [OH_HEVCProfile](_codec_base.md#oh_hevcprofile) | Defines an enum for High Efficiency Video Coding (HEVC) profiles.| 
| typedef enum [OH_VVCProfile](_codec_base.md#oh_vvcprofile-1) [OH_VVCProfile](_codec_base.md#oh_vvcprofile) | Defines an enum for Versatile Video Coding (VVC) profiles.| 
| typedef enum [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat-1) [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat) | Defines an enum for the output file formats supported by a muxer.| 
| typedef enum [OH_AVSeekMode](_codec_base.md#oh_avseekmode-1) [OH_AVSeekMode](_codec_base.md#oh_avseekmode) | Defines an enum for seek modes.| 
| typedef enum [OH_ScalingMode](_codec_base.md#oh_scalingmode-1) [OH_ScalingMode](_codec_base.md#oh_scalingmode) | Defines an enum for the scaling modes. This enum is used only in surface mode. (This type is deprecated from API version 14.)| 
| typedef enum [OH_BitsPerSample](_codec_base.md#oh_bitspersample-1) [OH_BitsPerSample](_codec_base.md#oh_bitspersample) | Defines an enum for the number of audio bits for each coded sample.| 
| typedef enum [OH_ColorPrimary](_codec_base.md#oh_colorprimary-1) [OH_ColorPrimary](_codec_base.md#oh_colorprimary) | Defines an enum for primary colors.| 
| typedef enum [OH_TransferCharacteristic](_codec_base.md#oh_transfercharacteristic-1) [OH_TransferCharacteristic](_codec_base.md#oh_transfercharacteristic) | Defines an enum for transfer characteristics.| 
| typedef enum [OH_MatrixCoefficient](_codec_base.md#oh_matrixcoefficient-1) [OH_MatrixCoefficient](_codec_base.md#oh_matrixcoefficient) | Defines an enum for matrix coefficients.| 
| typedef enum [OH_AVCLevel](_codec_base.md#oh_avclevel-1) [OH_AVCLevel](_codec_base.md#oh_avclevel) | Defines an enum for AVC levels. | 
| typedef enum [OH_HEVCLevel](_codec_base.md#oh_hevclevel-1) [OH_HEVCLevel](_codec_base.md#oh_hevclevel) | Defines an enum for HEVC levels. | 
| typedef enum [OH_VVCLevel](_codec_base.md#oh_vvclevel-1) [OH_VVCLevel](_codec_base.md#oh_vvclevel) | Defines an enum for VVC levels. | 
| typedef enum [OH_TemporalGopReferenceMode](_codec_base.md#oh_temporalgopreferencemode-1) [OH_TemporalGopReferenceMode](_codec_base.md#oh_temporalgopreferencemode) | Defines an enum for reference modes of temporal image groups. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_MediaType](_codec_base.md#oh_mediatype-1) {<br>MEDIA_TYPE_AUD = 0,<br>MEDIA_TYPE_VID = 1,<br>MEDIA_TYPE_SUBTITILE = 2<br>} | Enumerates the media types.|
| [OH_AACProfile](_codec_base.md#oh_aacprofile-1) {<br>AAC_PROFILE_LC = 0,<br>AAC_PROFILE_HE = 3,<br>AAC_PROFILE_HE_V2 = 4<br>} | Enumerates the AAC profiles.<!--Del--><br>(**AAC_PROFILE_HE** and **AAC_PROFILE_HE_V2** are not available yet.)<!--DelEnd--> | 
| [OH_AVCProfile](_codec_base.md#oh_avcprofile-1) {<br>AVC_PROFILE_BASELINE = 0,<br>AVC_PROFILE_HIGH = 4,<br>AVC_PROFILE_MAIN = 8<br>} | Enumerates the AVC profiles.| 
| [OH_HEVCProfile](_codec_base.md#oh_hevcprofile-1) {<br>HEVC_PROFILE_MAIN = 0,<br>HEVC_PROFILE_MAIN_10 = 1,<br>HEVC_PROFILE_MAIN_STILL = 2,<br>HEVC_PROFILE_MAIN_10_HDR10 = 3,<br>HEVC_PROFILE_MAIN_10_HDR10_PLUS = 4<br>} | Enumerates the HEVC profiles.<br>**HEVC_PROFILE_MAIN_10_HDR10** and **HEVC_PROFILE_MAIN_10_HDR10_PLUS** are deprecated since API version 14.| 
| [OH_VVCProfile](_codec_base.md#oh_vvcprofile-1) {<br>VVC_PROFILE_MAIN_10 = 1, <br>VVC_PROFILE_MAIN_12 = 2, <br>VVC_PROFILE_MAIN_12_INTRA = 10, <br>VVC_PROFILE_MULTI_MAIN_10 = 17, <br>VVC_PROFILE_MAIN_10_444 = 33, <br>VVC_PROFILE_MAIN_12_444 = 34, <br>VVC_PROFILE_MAIN_16_444 = 36, <br>VVC_PROFILE_MAIN_12_444_INTRA = 42, <br>VVC_PROFILE_MAIN_16_444_INTRA = 44, <br>VVC_PROFILE_MULTI_MAIN_10_444 = 49, <br>VVC_PROFILE_MAIN_10_STILL = 65, <br>VVC_PROFILE_MAIN_12_STILL = 66, <br>VVC_PROFILE_MAIN_10_444_STILL = 97, <br>VVC_PROFILE_MAIN_12_444_STILL = 98, <br>VVC_PROFILE_MAIN_16_444_STILL = 100 <br>} | Enumerates the VVC profiles.| 
| [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat-1) {<br>AV_OUTPUT_FORMAT_DEFAULT = 0,<br>AV_OUTPUT_FORMAT_MPEG_4 = 2,<br>AV_OUTPUT_FORMAT_M4A = 6,<br>AV_OUTPUT_FORMAT_AMR = 8,<br>AV_OUTPUT_FORMAT_MP3 = 9,<br>AV_OUTPUT_FORMAT_WAV = 10<br>} | Enumerates the output file formats supported by a muxer.| 
| [OH_AVSeekMode](_codec_base.md#oh_avseekmode-1) {<br>SEEK_MODE_NEXT_SYNC = 0,<br>SEEK_MODE_PREVIOUS_SYNC,<br>SEEK_MODE_CLOSEST_SYNC<br>} | Enumerates the seek modes.| 
| [OH_ScalingMode](_codec_base.md#oh_scalingmode-1) {<br>SCALING_MODE_SCALE_TO_WINDOW = 1,<br>SCALING_MODE_SCALE_CROP = 2<br>} | Enumerates the scaling modes. (This enum is deprecated from API version 14.)| 
| [OH_BitsPerSample](_codec_base.md#oh_bitspersample-1) {<br>SAMPLE_U8 = 0, SAMPLE_S16LE = 1,<br>SAMPLE_S24LE = 2, SAMPLE_S32LE = 3,<br>SAMPLE_F32LE = 4, SAMPLE_U8P = 5,<br>SAMPLE_S16P = 6, SAMPLE_S24P = 7,<br>SAMPLE_S32P = 8, SAMPLE_F32P = 9,<br>INVALID_WIDTH = -1<br>} | Enumerates the number of audio bits for each coded sample.| 
| [OH_ColorPrimary](_codec_base.md#oh_colorprimary-1) {<br>COLOR_PRIMARY_BT709 = 1,<br>COLOR_PRIMARY_UNSPECIFIED = 2,<br>COLOR_PRIMARY_BT470_M = 4,<br>COLOR_PRIMARY_BT601_625 = 5,<br>COLOR_PRIMARY_BT601_525 = 6,<br>COLOR_PRIMARY_SMPTE_ST240 = 7,<br>COLOR_PRIMARY_GENERIC_FILM = 8,<br>COLOR_PRIMARY_BT2020 = 9,<br>COLOR_PRIMARY_SMPTE_ST428 = 10,<br>COLOR_PRIMARY_P3DCI = 11,<br>COLOR_PRIMARY_P3D65 = 12<br>} | Enumerates the primary colors.| 
| [OH_TransferCharacteristic](_codec_base.md#oh_transfercharacteristic-1) {<br>TRANSFER_CHARACTERISTIC_BT709 = 1,<br>TRANSFER_CHARACTERISTIC_UNSPECIFIED = 2,<br>TRANSFER_CHARACTERISTIC_GAMMA_2_2 = 4,<br>TRANSFER_CHARACTERISTIC_GAMMA_2_8 = 5,<br>TRANSFER_CHARACTERISTIC_BT601 = 6,<br>TRANSFER_CHARACTERISTIC_SMPTE_ST240 = 7,<br>TRANSFER_CHARACTERISTIC_LINEAR = 8,<br>TRANSFER_CHARACTERISTIC_LOG = 9,<br>TRANSFER_CHARACTERISTIC_LOG_SQRT = 10,<br>TRANSFER_CHARACTERISTIC_IEC_61966_2_4 = 11,<br>TRANSFER_CHARACTERISTIC_BT1361 = 12,<br>TRANSFER_CHARACTERISTIC_IEC_61966_2_1 = 13,<br>TRANSFER_CHARACTERISTIC_BT2020_10BIT = 14,<br>TRANSFER_CHARACTERISTIC_BT2020_12BIT = 15,<br>TRANSFER_CHARACTERISTIC_PQ = 16,<br>TRANSFER_CHARACTERISTIC_SMPTE_ST428 = 17,<br>TRANSFER_CHARACTERISTIC_HLG = 18<br>} | Enumerates the transfer characteristics.| 
| [OH_MatrixCoefficient](_codec_base.md#oh_matrixcoefficient-1) {<br>MATRIX_COEFFICIENT_IDENTITY = 0,<br>MATRIX_COEFFICIENT_BT709 = 1,<br>MATRIX_COEFFICIENT_UNSPECIFIED = 2,<br>MATRIX_COEFFICIENT_FCC = 4,<br>MATRIX_COEFFICIENT_BT601_625 = 5,<br>MATRIX_COEFFICIENT_BT601_525 = 6, MATRIX_COEFFICIENT_SMPTE_ST240 = 7,<br>MATRIX_COEFFICIENT_YCGCO = 8,<br>MATRIX_COEFFICIENT_BT2020_NCL = 9,<br>MATRIX_COEFFICIENT_BT2020_CL = 10,<br>MATRIX_COEFFICIENT_SMPTE_ST2085 = 11,<br>MATRIX_COEFFICIENT_CHROMATICITY_NCL = 12,<br>MATRIX_COEFFICIENT_CHROMATICITY_CL = 13,<br>MATRIX_COEFFICIENT_ICTCP = 14<br>} | Enumerates the matrix coefficients.| 
| [OH_AVCLevel](_codec_base.md#oh_avclevel-1) {<br>AVC_LEVEL_1 = 0, <br>AVC_LEVEL_1b = 1, <br>AVC_LEVEL_11 = 2, <br>AVC_LEVEL_12 = 3,<br>AVC_LEVEL_13 = 4, <br>AVC_LEVEL_2 = 5, <br>AVC_LEVEL_21 = 6, <br>AVC_LEVEL_22 = 7,<br>AVC_LEVEL_3 = 8, <br>AVC_LEVEL_31 = 9, <br>AVC_LEVEL_32 = 10, <br>AVC_LEVEL_4 = 11,<br>AVC_LEVEL_41 = 12, <br>AVC_LEVEL_42 = 13, <br>AVC_LEVEL_5 = 14, <br>AVC_LEVEL_51 = 15, <br>AVC_LEVEL_52 = 16, <br>AVC_LEVEL_6 = 17, <br>AVC_LEVEL_61 = 18, <br>AVC_LEVEL_62 = 19<br>} | Enumerates the AVC levels. | 
| [OH_HEVCLevel](_codec_base.md#oh_hevclevel-1) {<br>HEVC_LEVEL_1 = 0, <br>HEVC_LEVEL_2 = 1, <br>HEVC_LEVEL_21 = 2, <br>HEVC_LEVEL_3 = 3,<br>HEVC_LEVEL_31 = 4, <br>HEVC_LEVEL_4 = 5, <br>HEVC_LEVEL_41 = 6, <br>HEVC_LEVEL_5 = 7,<br>HEVC_LEVEL_51 = 8, <br>HEVC_LEVEL_52 = 9, <br>HEVC_LEVEL_6 = 10, <br>HEVC_LEVEL_61 = 11,<br>HEVC_LEVEL_62 = 12<br>} | Enumerates the HEVC levels. | 
| [OH_VVCLevel](_codec_base.md#oh_vvclevel-1) {<br>VVC_LEVEL_1 = 16, <br>VVC_LEVEL_2 = 32, <br>VVC_LEVEL_21 = 35, <br>VVC_LEVEL_3 = 48, <br>VVC_LEVEL_31 = 51, <br>VVC_LEVEL_4 = 64, <br>VVC_LEVEL_41 = 67, <br>VVC_LEVEL_5 = 80, <br>VVC_LEVEL_51 = 83, <br>VVC_LEVEL_52 = 86, <br>VVC_LEVEL_6 = 96, <br>VVC_LEVEL_61 = 99, <br>VVC_LEVEL_62 = 102, <br>VVC_LEVEL_63 = 105, <br>VVC_LEVEL_155 = 255<br>} | Enumerates the VVC levels. | 
| [OH_TemporalGopReferenceMode](_codec_base.md#oh_temporalgopreferencemode-1) { <br>ADJACENT_REFERENCE = 0, <br>JUMP_REFERENCE = 1, <br>UNIFORMLY_SCALED_REFERENCE = 2 <br>} | Enumerates the reference modes of temporal image groups. | 


### Variables

| Name| Description| 
| -------- | -------- |
| const char \* [OH_AVCODEC_MIMETYPE_VIDEO_AVC](_codec_base.md#oh_avcodec_mimetype_video_avc) | Pointer to the key that describes the Multipurpose Internet Mail Extension (MIME) type of AVC (H.264) video codec.| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_AAC](_codec_base.md#oh_avcodec_mimetype_audio_aac) | Pointer to the key that describes the MIME type of AAC audio codec.| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_FLAC](_codec_base.md#oh_avcodec_mimetype_audio_flac) | Pointer to the key that describes the MIME type of FLAC audio codec.| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_VORBIS](_codec_base.md#oh_avcodec_mimetype_audio_vorbis) | Pointer to the key that describes the MIME type of the Vorbis audio decoder.| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_MPEG](_codec_base.md#oh_avcodec_mimetype_audio_mpeg) | Pointer to the key that describes the MIME type of the MP3 audio decoder.| 
| const char \* [OH_AVCODEC_MIMETYPE_VIDEO_HEVC](_codec_base.md#oh_avcodec_mimetype_video_hevc) | Pointer to the key that describes the MIME type of HEVC (H.265) video codec.| 
| const char \* [OH_AVCODEC_MIMETYPE_VIDEO_MPEG4](_codec_base.md#oh_avcodec_mimetype_video_mpeg4) | Pointer to the key that describes the MIME type of the MPEG4 video encoder, which is used only for muxing MPEG4 video streams.| 
| const char \* [OH_AVCODEC_MIMETYPE_IMAGE_JPG](_codec_base.md#oh_avcodec_mimetype_image_jpg) | Pointer to the key that describes the MIME type of the JPG image encoder, which is used only for muxing JPG covers.| 
| const char \* [OH_AVCODEC_MIMETYPE_IMAGE_PNG](_codec_base.md#oh_avcodec_mimetype_image_png) | Pointer to the key that describes the MIME type of the PNG image encoder, which is used only for muxing PNG covers.| 
| const char \* [OH_AVCODEC_MIMETYPE_IMAGE_BMP](_codec_base.md#oh_avcodec_mimetype_image_bmp) | Pointer to the key that describes the MIME type of the BMP image encoder, which is used only for muxing BMP covers.| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_VIVID](_codec_base.md#oh_avcodec_mimetype_audio_vivid) | Pointer to the key that describes the MIME type of the Audio Vivid audio decoder. <!--Del-->(This specification is not available yet.)<!--DelEnd-->  | 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_AMR_NB](_codec_base.md#oh_avcodec_mimetype_audio_amr_nb) | Pointer to the key that describes the MIME type of the AMR-NB audio decoder.| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_AMR_WB](_codec_base.md#oh_avcodec_mimetype_audio_amr_wb) | Pointer to the key that describes the MIME type of the AMR-WB audio decoder.| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_OPUS](_codec_base.md#oh_avcodec_mimetype_audio_opus) | Pointer to the key that describes the MIME type of Opus audio codec. <!--Del-->(This specification is not available yet.)<!--DelEnd-->  | 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_G711MU](_codec_base.md#oh_avcodec_mimetype_audio_g711mu) | Pointer to the key that describes the MIME type of G.711 mu-law audio codec.| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_RAW](_codec_base.md#oh_avcodec_mimetype_audio_raw) | Pointer to the key that describes the MIME type of raw audio streams.|
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_APE](_codec_base.md#oh_avcodec_mimetype_audio_ape) |Pointer to the key that describes the MIME type of the APE audio decoder.                        |
| const char \* [OH_AVCODEC_MIMETYPE_VIDEO_VVC](_codec_base.md#oh_avcodec_mimetype_video_vvc) | Pointer to the key that describes the MIME type of the VVC (H.266) video codec.| 
| const char \* [OH_AVCODEC_MIMETYPE_SUBTITLE_SRT](_codec_base.md#oh_avcodec_mimetype_subtitle_srt) |Pointer to the key that describes the MIME type of the SRT subtitle demuxer.                        |
| const char \* [OH_AVCODEC_MIMETYPE_SUBTITLE_WEBVTT](_codec_base.md#oh_avcodec_mimetype_subtitle_webvtt) |Pointer to the key that describes the MIME type of the WEBVTT subtitle demuxer.                        |
| const char \* [OH_ED_KEY_TIME_STAMP](_codec_base.md#oh_ed_key_time_stamp) | Pointer to the key that describes the surface buffer timestamp. The value is of the int64_t type. (This variable is deprecated from API version 14.)|
| const char \* [OH_ED_KEY_EOS](_codec_base.md#oh_ed_key_eos) | Pointer to the key that describes the end of stream for the surface buffer. The value type is int32_t. (This variable is deprecated from API version 14.)|
| const char \* [OH_MD_KEY_TRACK_TYPE](_codec_base.md#oh_md_key_track_type) | Pointer to the key that describes the track in a media type. The value type is int32_t. For details, see [OH_MediaType](_codec_base.md#oh_mediatype-1).| 
| const char \* [OH_MD_KEY_CODEC_MIME](_codec_base.md#oh_md_key_codec_mime) | Pointer to the key that describes the MIME type of the codec. The value type is string.|
| const char \* [OH_MD_KEY_DURATION](_codec_base.md#oh_md_key_duration) | Pointer to the key that describes the duration of a media file. The value type is int64_t.| 
| const char \* [OH_MD_KEY_BITRATE](_codec_base.md#oh_md_key_bitrate) | Pointer to the key that describes the bit rate. The value type is int64_t.| 
| const char \* [OH_MD_KEY_MAX_INPUT_SIZE](_codec_base.md#oh_md_key_max_input_size) | Pointer to the key that describes the maximum size of an input stream to decode. The value type is int32_t.|
| const char \* [OH_MD_KEY_WIDTH](_codec_base.md#oh_md_key_width) | Pointer to the key that describes the video width. The value type is int32_t.| 
| const char \* [OH_MD_KEY_HEIGHT](_codec_base.md#oh_md_key_height) | Pointer to the key that describes the video height. The value type is int32_t.| 
| const char \* [OH_MD_KEY_PIXEL_FORMAT](_codec_base.md#oh_md_key_pixel_format) | Pointer to the key that describes the video pixel format. The value type is int32_t. For details, see [OH_AVPixelFormat](_core.md#oh_avpixelformat).| 
| const char \* [OH_MD_KEY_AUDIO_SAMPLE_FORMAT](_codec_base.md#oh_md_key_audio_sample_format) | Pointer to the key that describes the original audio format. The value type is int32_t. For details, see [OH_BitsPerSample](_codec_base.md#oh_bitspersample).| 
| const char \* [OH_MD_KEY_FRAME_RATE](_codec_base.md#oh_md_key_frame_rate) | Pointer to the key that describes the video frame rate. The value type is double.| 
| const char \* [OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE](_codec_base.md#oh_md_key_video_encode_bitrate_mode) | Pointer to the key that describes the video encoding bit rate mode. The value type is int32_t. For details, see [OH_BitrateMode](_codec_base.md#oh_bitratemode-1).| 
| const char \* [OH_MD_KEY_PROFILE](_codec_base.md#oh_md_key_profile) | Pointer to the key that describes the encoding grading. The value type is int32_t. For details, see [OH_AVCProfile](_codec_base.md#oh_avcprofile), [OH_HEVCProfile](_codec_base.md#oh_hevcprofile), and [OH_AACProfile](_codec_base.md#oh_aacprofile).|
| const char \* [OH_MD_KEY_AUD_CHANNEL_COUNT](_codec_base.md#oh_md_key_aud_channel_count) | Pointer to the key that describes the number of audio channels. The value type is int32_t.| 
| const char \* [OH_MD_KEY_AUD_SAMPLE_RATE](_codec_base.md#oh_md_key_aud_sample_rate) | Pointer to the key that describes the audio sampling rate. The value type is int32_t.| 
| const char \* [OH_MD_KEY_I_FRAME_INTERVAL](_codec_base.md#oh_md_key_i_frame_interval) | Pointer to the key that describes the key frame interval, in milliseconds. The value type is int32_t.| 
| const char \* [OH_MD_KEY_ROTATION](_codec_base.md#oh_md_key_rotation) | Pointer to the key that describes the rotation angle of the surface. The value type is int32_t, and the value range is {0, 90, 180, 270}. The default value is 0. This key is used only for video decoding in surface mode.|
| const char \* [OH_MD_KEY_RANGE_FLAG](_codec_base.md#oh_md_key_range_flag) | Pointer to the key that describes the video YUV value range flag. The value type is int32_t. The value **1** means a full range, and **0** means a limited range.|
| const char \* [OH_MD_KEY_COLOR_PRIMARIES](_codec_base.md#oh_md_key_color_primaries) | Pointer to the key that describes the video primary color. The value type is int32_t. For details, see [OH_ColorPrimary](_codec_base.md#oh_colorprimary). The video primary color complies with Table 2 in the H.273 standard.| 
| const char \* [OH_MD_KEY_TRANSFER_CHARACTERISTICS](_codec_base.md#oh_md_key_transfer_characteristics) | Pointer to the key that describes the video transfer characteristics. The value type is int32_t. For details, see [OH_TransferCharacteristic](_codec_base.md#oh_transfercharacteristic). The video transfer characteristics comply with Table 3 in the H.273 standard.| 
| const char \* [OH_MD_KEY_MATRIX_COEFFICIENTS](_codec_base.md#oh_md_key_matrix_coefficients) | Pointer to the key that describes the video matrix coefficient. The value type is int32_t. For details, see [OH_MatrixCoefficient](_codec_base.md#oh_matrixcoefficient). The video matrix coefficient complies with Table 4 in the H.273 standard.| 
| const char \* [OH_MD_KEY_REQUEST_I_FRAME](_codec_base.md#oh_md_key_request_i_frame) | Pointer to the key that describes the request for immediate encoding of I-frames. The value type is int32_t.|
| const char \* [OH_MD_KEY_QUALITY](_codec_base.md#oh_md_key_quality) | Pointer to the key that describes the required encoding quality. The value type is int32_t. This key applies only to encoders configured in constant quality mode.| 
| const char \* [OH_MD_KEY_CODEC_CONFIG](_codec_base.md#oh_md_key_codec_config) | Pointer to the key that describes the codec-specific data. The value type is uint8_t\*. <!--Del-->(This key is not supported yet for the video codec.)<!--DelEnd--> |
| const char \* [OH_MD_KEY_TRACK_START_TIME](_codec_base.md#oh_md_key_track_start_time) | Pointer to the key that describes the start time of the track, measured in microseconds. The value type is int64_t.    |
| const char \* [OH_MD_KEY_TITLE](_codec_base.md#oh_md_key_title) | Pointer to the key that describes the title of a media file. The value is of the string type.| 
| const char \* [OH_MD_KEY_ARTIST](_codec_base.md#oh_md_key_artist) | Pointer to the key that describes the lyrics of a media file. The value type is string.| 
| const char \* [OH_MD_KEY_ALBUM](_codec_base.md#oh_md_key_album) | Pointer to the key that describes the album of a media file. The value type is string.| 
| const char \* [OH_MD_KEY_ALBUM_ARTIST](_codec_base.md#oh_md_key_album_artist) | Pointer to the key that describes the album artist of the input media. The value type is string.| 
| const char \* [OH_MD_KEY_DATE](_codec_base.md#oh_md_key_date) | Pointer to the key that describes the date of a media file, for example, 2024. The value type is string.| 
| const char \* [OH_MD_KEY_COMMENT](_codec_base.md#oh_md_key_comment) | Pointer to the key that describes the comment of a media file. The value is of the string type.| 
| const char \* [OH_MD_KEY_GENRE](_codec_base.md#oh_md_key_genre) | Pointer to the key that describes the genre of a media file. The value type is string.| 
| const char \* [OH_MD_KEY_COPYRIGHT](_codec_base.md#oh_md_key_copyright) | Pointer to the key that describes the copyright of a media file. The value type is string.| 
| const char \* [OH_MD_KEY_LANGUAGE](_codec_base.md#oh_md_key_language) | Pointer to the key that describes the language of a media file. The value type is string.| 
| const char \* [OH_MD_KEY_DESCRIPTION](_codec_base.md#oh_md_key_description) | Pointer to the key that describes the description of a media file. The value type is string.| 
| const char \* [OH_MD_KEY_LYRICS](_codec_base.md#oh_md_key_lyrics) | Pointer to the key that describes the lyrics of a media file. The value type is string.| 
| const char \* [OH_MD_KEY_TRACK_COUNT](_codec_base.md#oh_md_key_track_count) | Pointer to the key that describes the number of tracks of a media file. The value type is int32_t.| 
| const char \* [OH_MD_KEY_CHANNEL_LAYOUT](_codec_base.md#oh_md_key_channel_layout) | Pointer to the key that describes the required encoding channel layout. The value type is int64_t. This key applies only to encoders.| 
| const char \* [OH_MD_KEY_BITS_PER_CODED_SAMPLE](_codec_base.md#oh_md_key_bits_per_coded_sample) | Pointer to the key that describes the number of bits for each coded sample. The value type is int32_t. This key applies to FLAC encoders. For details, see [OH_BitsPerSample](_codec_base.md#oh_bitspersample).| 
| const char \* [OH_MD_KEY_AAC_IS_ADTS](_codec_base.md#oh_md_key_aac_is_adts) | Pointer to the key that describes the AAC format, which can be ADTS or LATM. The value type is int32_t. This key is supported only by the AAC decoder.|
| const char \* [OH_MD_KEY_SBR](_codec_base.md#oh_md_key_sbr) | Pointer to the key that describes the AAC SBR format. The value type is int32_t. This key applies to AAC encoders.| 
| const char \* [OH_MD_KEY_COMPLIANCE_LEVEL](_codec_base.md#oh_md_key_compliance_level) | Pointer to the key that describes the FLAC compliance level. The value type is int32_t. This key is used only for audio encoding.| 
| const char \* [OH_MD_KEY_IDENTIFICATION_HEADER](_codec_base.md#oh_md_key_identification_header) | Pointer to the key that describes the VORBIS identification header. The value type is uint8_t\*. This key applies only to VORBIS decoders.| 
| const char \* [OH_MD_KEY_SETUP_HEADER](_codec_base.md#oh_md_key_setup_header) | Pointer to the key that describes the VORBIS setup header. The value type is uint8_t\*. This key applies only to VORBIS decoders.| 
| const char \* [OH_MD_KEY_SCALING_MODE](_codec_base.md#oh_md_key_scaling_mode) | Pointer to the key that describes the video scaling mode. The value type is int32_t. For details, see [OH_ScalingMode](_codec_base.md#oh_scalingmode). This key is used only in video decoding surface mode. You are advised to set the scaling mode by calling [OH_NativeWindow_NativeWindowSetScalingModeV2](../apis-arkgraphics2d/_native_window.md). (This variable is deprecated from API version 14.)|
| const char \* [OH_MD_MAX_INPUT_BUFFER_COUNT](_codec_base.md#oh_md_max_input_buffer_count) | Pointer to the key that describes the maximum number of input buffers. The value type is int32_t.| 
| const char \* [OH_MD_MAX_OUTPUT_BUFFER_COUNT](_codec_base.md#oh_md_max_output_buffer_count) | Pointer to the key that describes the maximum number of output buffers. The value type is int32_t.| 
| const char \* [OH_MD_KEY_AUDIO_COMPRESSION_LEVEL](_codec_base.md#oh_md_key_audio_compression_level) | Pointer to the key that describes the compression level for audio encoding and decoding. The value type is int32_t type. This key is used only for audio encoding.| 
| const char \* [OH_MD_KEY_VIDEO_IS_HDR_VIVID](_codec_base.md#oh_md_key_video_is_hdr_vivid) | Pointer to the key that describes whether the video track in a media file is HDR Vivid. The value type is int32_t. This key is used for both muxing and demuxing.|
| const char \* [OH_MD_KEY_AUDIO_OBJECT_NUMBER](_codec_base.md#oh_md_key_audio_object_number) | Pointer to the key that describes the number of audio objects. The value type is int32_t. This key is used only for Audio Vivid decoding.| 
| const char \* [OH_MD_KEY_AUDIO_VIVID_METADATA](_codec_base.md#oh_md_key_audio_vivid_metadata) | Pointer to the key that describes the Audio Vivid metadata. The value type is uint8_t\*. This key is used only for Audio Vivid decoding.| 
| const char \* [OH_FEATURE_PROPERTY_KEY_VIDEO_ENCODER_MAX_LTR_FRAME_COUNT](_codec_base.md#oh_feature_property_key_video_encoder_max_ltr_frame_count) | Pointer to the key that describes the maximum number of long-term reference frames obtained during video encoding. The value type is int32_t. | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_ENABLE_TEMPORAL_SCALABILITY](_codec_base.md#oh_md_key_video_encoder_enable_temporal_scalability) | Pointer to the key that describes the enabled status of temporal scalability. The value type is int32_t. The value **1** means temporal scalability is enabled, and **0** means the opposite.| 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_SIZE](_codec_base.md#oh_md_key_video_encoder_temporal_gop_size) | Pointer to the key that describes the size of a temporal image group. The value type is int32_t. This key is valid only when temporal scalability is enabled. |
| const char \* [OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_REFERENCE_MODE](_codec_base.md#oh_md_key_video_encoder_temporal_gop_reference_mode) | Pointer to the key that describes the reference mode in a temporal image group. The value type is int32_t. For details, see [OH_TemporalGopReferenceMode](_codec_base.md#oh_temporalgopreferencemode). This key is valid only when temporal scalability is enabled.| 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_LTR_FRAME_COUNT](_codec_base.md#oh_md_key_video_encoder_ltr_frame_count) | Pointer to the key that describes the number of long-term reference frames. The value type is int32_t. The value must be within the supported value range. This key is optional and is used only for video encoding. | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_MARK_LTR](_codec_base.md#oh_md_key_video_encoder_per_frame_mark_ltr) | Pointer to the key that describes the key that marks the current frame as a long-term reference frame. The value type is int32_t. The value **1** means that the frame is marked as a long-term reference frame, and **0** means the opposite. This key is optional and is used only for video encoding. | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_USE_LTR](_codec_base.md#oh_md_key_video_encoder_per_frame_use_ltr) | Pointer to the key that describes the POC number of the LTR frame referenced by the current frame. The value type is int32_t. This key is optional and is used only for video encoding. | 
| const char \* [OH_MD_KEY_VIDEO_PER_FRAME_IS_LTR](_codec_base.md#oh_md_key_video_per_frame_is_ltr) | Pointer to the key that describes whether the frame corresponding to the stream output from the current OH_AVBuffer is the long-term reference frame. The value type is int32_t. The value **1** means LTR, and **0** means non-LTR. This key is optional and is used only for video encoding.| 
| const char \* [OH_MD_KEY_VIDEO_PER_FRAME_POC](_codec_base.md#oh_md_key_video_per_frame_poc) | Pointer to the key that describes the POC number of the frame. The value type is int32_t. This key is optional and is used only for video encoding. | 
| const char \* [OH_MD_KEY_VIDEO_CROP_TOP](_codec_base.md#oh_md_key_video_crop_top) | Pointer to the key that describes the top coordinate (y) of the cropped rectangle. The value type is int32_t. This key is used only for video decoding.| 
| const char \* [OH_MD_KEY_VIDEO_CROP_BOTTOM](_codec_base.md#oh_md_key_video_crop_bottom) | Pointer to the key that describes the bottom coordinate (y) of the cropped rectangle. The value type is int32_t. This key is used only for video decoding.  | 
| const char \* [OH_MD_KEY_VIDEO_CROP_LEFT](_codec_base.md#oh_md_key_video_crop_left) | Pointer to the key that describes the left coordinate (x) of the cropped rectangle. The value type is int32_t. This key is used only for video decoding. | 
| const char \* [OH_MD_KEY_VIDEO_CROP_RIGHT](_codec_base.md#oh_md_key_video_crop_right) | Pointer to the key that describes the right coordinate (x) of the cropped rectangle. The value type is int32_t. This key is used only for video decoding. | 
| const char \* [OH_MD_KEY_VIDEO_STRIDE](_codec_base.md#oh_md_key_video_stride) | Pointer to the key that describes the stride of a video frame. The value type is int32_t. | 
| const char \* [OH_MD_KEY_VIDEO_SLICE_HEIGHT](_codec_base.md#oh_md_key_video_slice_height) | Pointer to the key that describes the height of a video frame. The value type is int32_t. | 
| const char \* [OH_MD_KEY_VIDEO_PIC_WIDTH](_codec_base.md#oh_md_key_video_pic_width) | Pointer to the key that describes the width of the video frame. The value type is int32_t. | 
| const char \* [OH_MD_KEY_VIDEO_PIC_HEIGHT](_codec_base.md#oh_md_key_video_pic_height) | Pointer to the key that describes the height of the video frame. The value type is int32_t. | 
| const char \* [OH_MD_KEY_VIDEO_ENABLE_LOW_LATENCY](_codec_base.md#oh_md_key_video_enable_low_latency) | Pointer to the key that describes the enabled status of low-latency video codec. The value type is int32_t. The value **1** means that low-latency video codec is enabled, and **0** means the opposite. | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_QP_MAX](_codec_base.md#oh_md_key_video_encoder_qp_max) | Pointer to the key that describes the maximum Quantization Parameter (QP) allowed by the video encoder. The value type is int32_t. | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_QP_MIN](_codec_base.md#oh_md_key_video_encoder_qp_min) | Pointer to the key that describes the minimum QP allowed by the video encoder. The value type is int32_t. | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_QP_AVERAGE](_codec_base.md#oh_md_key_video_encoder_qp_average) | Pointer to the key that describes the average QP of video frames. The value type is int32_t.|
| const char \* [OH_MD_KEY_VIDEO_ENCODER_MSE](_codec_base.md#oh_md_key_video_encoder_mse)     |Pointer to the key that describes the MSE of video frames. The value type is double. |
| const char \* [OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER](_codec_base.md#oh_md_key_video_encoder_repeat_previous_frame_after)    | Pointer to the key that indicates the duration (in milliseconds) for which the last frame will be resubmitted repeatedly, if no new frame is available after the previous frame is submitted to the encoder. The value type is int32_t.|
| const char \* [OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_MAX_COUNT](_codec_base.md#oh_md_key_video_encoder_repeat_previous_max_count)    | Pointer to the key that describes the maximum number of times the encoder can repeat encoding the previous frame when no new frame is available. The value type is int32_t.|
| const char \* [OH_MD_KEY_DECODING_TIMESTAMP](_codec_base.md#oh_md_key_decoding_timestamp) | Pointer to the key that describes the decoding timestamp corresponding to the audio, video, or subtitle sample carried in AVBuffer, in microseconds. The value type is int64_t. |
| const char \* [OH_MD_KEY_BUFFER_DURATION](_codec_base.md#oh_md_key_buffer_duration) | Pointer to the key that describes the duration corresponding to the audio, video, or subtitle sample carried in AVBuffer, in microseconds. The value type is int64_t.      |
| const char \* [OH_MD_KEY_START_TIME](_codec_base.md#oh_md_key_start_time) | Pointer to the key that describes the start time of the first frame in a media file, measured in microseconds. The value type is int64_t.    |
| const char \* [OH_MD_KEY_VIDEO_DECODER_OUTPUT_COLOR_SPACE](_codec_base.md#oh_md_key_video_decoder_output_color_space)   | Pointer to the key that describes the output color space of the video decoder. The value type is int32_t. The supported value is **OH_COLORSPACE_BT709_LIMIT**.|
| const char \* [OH_MD_KEY_VIDEO_SAR](_codec_base.md#oh_md_key_video_sar)            | Pointer to the key that describes the aspect ratio of the sample. The value type is double.|
| const char \* [OH_MD_KEY_CREATION_TIME](_codec_base.md#oh_md_key_creation_time) | Pointer to the key that describes the media file creation time. The value type is string.|
| const char \* [OH_MD_KEY_VIDEO_DECODER_OUTPUT_ENABLE_VRR](_codec_base.md#oh_md_key_video_decoder_output_enable_vrr) | Pointer to the key that specifies whether the decoder enables the video variable frame rate feature. The value type is int32_t.|
