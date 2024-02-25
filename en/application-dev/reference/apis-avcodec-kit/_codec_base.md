# CodecBase


## Overview

The **CodecBase** module provides the variables, attributes, and functions for basic audio and video muxing, demuxing, encoding, and decoding.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [avcodec_audio_channel_layout.h](avcodec__audio__channel__layout_8h.md) | Declares the enums used for audio codec.| 
| [native_avcodec_base.h](native__avcodec__base_8h.md) | Declare the native APIs used for basic audio and video muxing, demuxing, encoding, and decoding.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) | Defines all the asynchronous callback function pointers of an **OH_AVCodec** instance.| 
| struct&nbsp;&nbsp;[OH_AVCodecCallback](_o_h___a_v_codec_callback.md) | Defines all the asynchronous callback function pointers of an **OH_AVCodec** instance.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef void(\* [OH_AVCodecOnError](#oh_avcodeconerror)) (OH_AVCodec \*codec, int32_t errorCode, void \*userData) | Defines the pointer to the function that is called to report error information when an error occurs during the running of an **OH_AVCodec** instance.| 
| typedef void(\* [OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged)) (OH_AVCodec \*codec, OH_AVFormat \*format, void \*userData) | Defines the pointer to the function that is called to report the new stream description when the output stream changes.| 
| typedef void(\* [OH_AVCodecOnNeedInputData](#oh_avcodeconneedinputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, void \*userData) | Defines the pointer to the function that is called when new input data is required during the running of an **OH_AVCodec** instance. The function carries a buffer to fill in new input data.| 
| typedef void(\* [OH_AVCodecOnNewOutputData](#oh_avcodeconnewoutputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr, void \*userData) | Defines the pointer to the function that is called when new output data is generated during the running of an **OH_AVCodec** instance. The function carries a buffer filled with new output data.| 
| typedef void(\* [OH_AVCodecOnNeedInputBuffer](#oh_avcodeconneedinputbuffer)) (OH_AVCodec \*codec, uint32_t index, OH_AVBuffer \*buffer, void \*userData) | Defines the pointer to the function that is called when new input data is required during the running of an **OH_AVCodec** instance. The function carries a buffer to fill in new input data.| 
| typedef void(\* [OH_AVCodecOnNewOutputBuffer](#oh_avcodeconnewoutputbuffer)) (OH_AVCodec \*codec, uint32_t index, OH_AVBuffer \*buffer, void \*userData) | Defines the pointer to the function that is called when new output data is generated during the running of an **OH_AVCodec** instance. The function carries a buffer filled with new output data.| 
| typedef struct [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md)[OH_AVCodecAsyncCallback](#oh_avcodecasynccallback) | Defines all the asynchronous callback function pointers of an **OH_AVCodec** instance.| 
| typedef struct [OH_AVCodecCallback](_o_h___a_v_codec_callback.md)[OH_AVCodecCallback](#oh_avcodeccallback) | Defines all the asynchronous callback function pointers of an **OH_AVCodec** instance.| 
| typedef enum [OH_MediaType](#oh_mediatype)[OH_MediaType](#oh_mediatype) | Defines an enum that enumerates the media types.| 
| typedef enum [OH_AACProfile](#oh_aacprofile)[OH_AACProfile](#oh_aacprofile) | Defines an enum that enumerates the Advanced Audio Coding (AAC) profiles.| 
| typedef enum [OH_AVCProfile](#oh_avcprofile)[OH_AVCProfile](#oh_avcprofile) | Defines an enum that enumerates the Advanced Video Coding (AVC) profiles.| 
| typedef enum [OH_HEVCProfile](#oh_hevcprofile)[OH_HEVCProfile](#oh_hevcprofile) | Defines an enum that enumerates the High Efficiency Video Coding (HEVC) profiles.| 
| typedef enum [OH_AVOutputFormat](#oh_avoutputformat)[OH_AVOutputFormat](#oh_avoutputformat) | Defines an enum that enumerates the output file formats of a muxer.| 
| typedef enum [OH_AVSeekMode](#oh_avseekmode)[OH_AVSeekMode](#oh_avseekmode) | Defines an enum that enumerates the seek modes.| 
| typedef enum [OH_ScalingMode](#oh_scalingmode)[OH_ScalingMode](#oh_scalingmode) | Defines an enum that enumerates the scaling modes.| 
| typedef enum [OH_BitsPerSample](#oh_bitspersample)[OH_BitsPerSample](#oh_bitspersample) | Defines an enum that enumerates the number of audio bits for each coded sample.| 
| typedef enum [OH_ColorPrimary](#oh_colorprimary)[OH_ColorPrimary](#oh_colorprimary) | Defines an enum that enumerates the primary colors.| 
| typedef enum [OH_TransferCharacteristic](#oh_transfercharacteristic)[OH_TransferCharacteristic](#oh_transfercharacteristic) | Defines an enum that enumerates the transfer characteristics.| 
| typedef enum [OH_MatrixCoefficient](#oh_matrixcoefficient)[OH_MatrixCoefficient](#oh_matrixcoefficient) | Defines an enum that enumerates the matrix coefficients.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [AudioChannelSet](#audiochannelset) : uint64_t {<br>FRONT_LEFT = 1ULL &lt;&lt; 0U,<br>FRONT_RIGHT = 1ULL &lt;&lt; 1U,<br>FRONT_CENTER = 1ULL &lt;&lt; 2U,<br>LOW_FREQUENCY = 1ULL &lt;&lt; 3U,<br>BACK_LEFT = 1ULL &lt;&lt; 4U,<br>BACK_RIGHT = 1ULL &lt;&lt; 5U,<br>FRONT_LEFT_OF_CENTER = 1ULL &lt;&lt; 6U,<br>FRONT_RIGHT_OF_CENTER = 1ULL &lt;&lt; 7U,<br>BACK_CENTER = 1ULL &lt;&lt; 8U,<br>SIDE_LEFT = 1ULL &lt;&lt; 9U,<br>SIDE_RIGHT = 1ULL &lt;&lt; 10U,<br>TOP_CENTER = 1ULL &lt;&lt; 11U,<br>TOP_FRONT_LEFT = 1ULL &lt;&lt; 12U,<br>TOP_FRONT_CENTER = 1ULL &lt;&lt; 13U,<br>TOP_FRONT_RIGHT = 1ULL &lt;&lt; 14U,<br>TOP_BACK_LEFT = 1ULL &lt;&lt; 15U,<br>TOP_BACK_CENTER = 1ULL &lt;&lt; 16U,<br>TOP_BACK_RIGHT = 1ULL &lt;&lt; 17U,<br>STEREO_LEFT = 1ULL &lt;&lt; 29U,<br>STEREO_RIGHT = 1ULL &lt;&lt; 30U,<br>WIDE_LEFT = 1ULL &lt;&lt; 31U,<br>WIDE_RIGHT = 1ULL &lt;&lt; 32U,<br>SURROUND_DIRECT_LEFT = 1ULL &lt;&lt; 33U,<br>SURROUND_DIRECT_RIGHT = 1ULL &lt;&lt; 34U,<br>LOW_FREQUENCY_2 = 1ULL &lt;&lt; 35U,<br>TOP_SIDE_LEFT = 1ULL &lt;&lt; 36U,<br>TOP_SIDE_RIGHT = 1ULL &lt;&lt; 37U,<br>BOTTOM_FRONT_CENTER = 1ULL &lt;&lt; 38U,<br>BOTTOM_FRONT_LEFT = 1ULL &lt;&lt; 39U,<br>BOTTOM_FRONT_RIGHT = 1ULL &lt;&lt; 40U,<br>AMBISONICS_ACN0 = 1ULL &lt;&lt; 41U,<br>AMBISONICS_ACN1 = 1ULL &lt;&lt; 42U,<br>AMBISONICS_ACN2 = 1ULL &lt;&lt; 43U,<br>AMBISONICS_ACN3 = 1ULL &lt;&lt; 44U,<br>AMBISONICS_W = AMBISONICS_ACN0,<br>AMBISONICS_Y = AMBISONICS_ACN1,<br>AMBISONICS_Z = AMBISONICS_ACN2,<br>AMBISONICS_X = AMBISONICS_ACN3,<br>AMBISONICS_ACN4 = 1ULL &lt;&lt; 45U,<br>AMBISONICS_ACN5 = 1ULL &lt;&lt; 46U,<br>AMBISONICS_ACN6 = 1ULL &lt;&lt; 47U,<br>AMBISONICS_ACN7 = 1ULL &lt;&lt; 48U,<br>AMBISONICS_ACN8 = 1ULL &lt;&lt; 49U,<br>AMBISONICS_ACN9 = 1ULL &lt;&lt; 50U,<br>AMBISONICS_ACN10 = 1ULL &lt;&lt; 51U,<br>AMBISONICS_ACN11 = 1ULL &lt;&lt; 52U,<br>AMBISONICS_ACN12 = 1ULL &lt;&lt; 53U,<br>AMBISONICS_ACN13 = 1ULL &lt;&lt; 54U,<br>AMBISONICS_ACN14 = 1ULL &lt;&lt; 55U,<br>AMBISONICS_ACN15 = 1ULL &lt;&lt; 56U<br>} | Enumerates the audio channel sets. Each channel number is mapped to a variable of int64.| 
| [AudioChannelLayout](#audiochannellayout) : uint64_t {<br>UNKNOWN_CHANNEL_LAYOUT = 0,<br>MONO = (AudioChannelSet::FRONT_CENTER),<br>STEREO = (AudioChannelSet::FRONT_LEFT \| AudioChannelSet::FRONT_RIGHT),<br>CH_2POINT1 = (STEREO \| AudioChannelSet::LOW_FREQUENCY),<br>CH_2_1 = (STEREO \| AudioChannelSet::BACK_CENTER),<br>SURROUND = (STEREO \| AudioChannelSet::FRONT_CENTER),<br>CH_3POINT1 = (SURROUND \| AudioChannelSet::LOW_FREQUENCY),<br>CH_4POINT0 = (SURROUND \| AudioChannelSet::BACK_CENTER),<br>CH_4POINT1 = (CH_4POINT0 \| AudioChannelSet::LOW_FREQUENCY),<br>CH_2_2 = (STEREO \| AudioChannelSet::SIDE_LEFT \| AudioChannelSet::SIDE_RIGHT),<br>QUAD = (STEREO \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT),<br>CH_5POINT0 = (SURROUND \| AudioChannelSet::SIDE_LEFT \| AudioChannelSet::SIDE_RIGHT),<br>CH_5POINT1 = (CH_5POINT0 \| AudioChannelSet::LOW_FREQUENCY),<br>CH_5POINT0_BACK = (SURROUND \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT),<br>CH_5POINT1_BACK = (CH_5POINT0_BACK \| AudioChannelSet::LOW_FREQUENCY),<br>CH_6POINT0 = (CH_5POINT0 \| AudioChannelSet::BACK_CENTER),<br>CH_6POINT0_FRONT = (CH_2_2 \| AudioChannelSet::FRONT_LEFT_OF_CENTER \| AudioChannelSet::FRONT_RIGHT_OF_CENTER),<br>HEXAGONAL = (CH_5POINT0_BACK \| AudioChannelSet::BACK_CENTER),<br>CH_6POINT1 = (CH_5POINT1 \| AudioChannelSet::BACK_CENTER),<br>CH_6POINT1_BACK = (CH_5POINT1_BACK \| AudioChannelSet::BACK_CENTER),<br>CH_6POINT1_FRONT = (CH_6POINT0_FRONT \| AudioChannelSet::LOW_FREQUENCY),<br>CH_7POINT0 = (CH_5POINT0 \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT),<br>CH_7POINT0_FRONT = (CH_5POINT0 \| AudioChannelSet::FRONT_LEFT_OF_CENTER \| AudioChannelSet::FRONT_RIGHT_OF_CENTER),<br>CH_7POINT1 = (CH_5POINT1 \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT),<br>CH_7POINT1_WIDE = (CH_5POINT1 \| AudioChannelSet::FRONT_LEFT_OF_CENTER \| AudioChannelSet::FRONT_RIGHT_OF_CENTER),<br>CH_7POINT1_WIDE_BACK, CH_3POINT1POINT2 = (CH_3POINT1 \| AudioChannelSet::TOP_FRONT_LEFT \| AudioChannelSet::TOP_FRONT_RIGHT),<br>CH_5POINT1POINT2 = (CH_5POINT1 \| AudioChannelSet::TOP_SIDE_LEFT \| AudioChannelSet::TOP_SIDE_RIGHT),<br>CH_5POINT1POINT4, CH_7POINT1POINT2 = (CH_7POINT1 \| AudioChannelSet::TOP_SIDE_LEFT \| AudioChannelSet::TOP_SIDE_RIGHT),<br>CH_7POINT1POINT4, CH_9POINT1POINT4 = (CH_7POINT1POINT4 \| AudioChannelSet::WIDE_LEFT \| AudioChannelSet::WIDE_RIGHT),<br>CH_9POINT1POINT6 = (CH_9POINT1POINT4 \| AudioChannelSet::TOP_SIDE_LEFT \| AudioChannelSet::TOP_SIDE_RIGHT),<br>CH_10POINT2, CH_22POINT2, OCTAGONAL = (CH_5POINT0 \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_CENTER \| AudioChannelSet::BACK_RIGHT),<br>HEXADECAGONAL, STEREO_DOWNMIX = (AudioChannelSet::STEREO_LEFT \| AudioChannelSet::STEREO_RIGHT),<br>HOA_FIRST,<br>HOA_SECOND,<br>HOA_THIRD<br>} | Enumerates the types of the audio channel sets. The output format of the decoder is represented as the channel type of the codec.| 
| [OH_MediaType](#oh_mediatype) {<br>MEDIA_TYPE_AUD = 0,<br>MEDIA_TYPE_VID = 1<br>} | Enumerates the media types.| 
| [OH_AACProfile](#oh_aacprofile) { AAC_PROFILE_LC = 0 } | Enumerates the AAC profiles.| 
| [OH_AVCProfile](#oh_avcprofile) {<br>AVC_PROFILE_BASELINE = 0,<br>AVC_PROFILE_HIGH = 4,<br>AVC_PROFILE_MAIN = 8<br>} | Enumerates the AVC profiles.| 
| [OH_HEVCProfile](#oh_hevcprofile) {<br>HEVC_PROFILE_MAIN = 0,<br>HEVC_PROFILE_MAIN_10 = 1,<br>HEVC_PROFILE_MAIN_STILL = 2,<br>HEVC_PROFILE_MAIN_10_HDR10 = 3,<br>HEVC_PROFILE_MAIN_10_HDR10_PLUS = 4<br>} | Enumerates the HEVC profiles.| 
| [OH_AVOutputFormat](#oh_avoutputformat) {<br>AV_OUTPUT_FORMAT_DEFAULT = 0,<br>AV_OUTPUT_FORMAT_MPEG_4 = 2,<br>AV_OUTPUT_FORMAT_M4A = 6<br>} | Enumerates the output file formats of a muxer.| 
| [OH_AVSeekMode](#oh_avseekmode) {<br>SEEK_MODE_NEXT_SYNC = 0,<br>SEEK_MODE_PREVIOUS_SYNC,<br>SEEK_MODE_CLOSEST_SYNC<br>} | Enumerates the seek modes.| 
| [OH_ScalingMode](#oh_scalingmode) {<br>SCALING_MODE_SCALE_TO_WINDOW = 1,<br>SCALING_MODE_SCALE_CROP = 2<br>} | Enumerates the scaling modes.| 
| [OH_BitsPerSample](#oh_bitspersample) {<br>SAMPLE_U8 = 0, SAMPLE_S16LE = 1,<br>SAMPLE_S24LE = 2, SAMPLE_S32LE = 3,<br>SAMPLE_F32LE = 4, SAMPLE_U8P = 5,<br>SAMPLE_S16P = 6, SAMPLE_S24P = 7,<br>SAMPLE_S32P = 8, SAMPLE_F32P = 9,<br>INVALID_WIDTH = -1<br>} | Enumerates the number of audio bits for each coded sample.| 
| [OH_ColorPrimary](#oh_colorprimary) {<br>COLOR_PRIMARY_BT709 = 1,<br>COLOR_PRIMARY_UNSPECIFIED = 2,<br>COLOR_PRIMARY_BT470_M = 4,<br>COLOR_PRIMARY_BT601_625 = 5,<br>COLOR_PRIMARY_BT601_525 = 6,<br>COLOR_PRIMARY_SMPTE_ST240 = 7,<br>COLOR_PRIMARY_GENERIC_FILM = 8,<br>COLOR_PRIMARY_BT2020 = 9,<br>COLOR_PRIMARY_SMPTE_ST428 = 10,<br>COLOR_PRIMARY_P3DCI = 11,<br>COLOR_PRIMARY_P3D65 = 12<br>} | Enumerates the primary colors.| 
| [OH_TransferCharacteristic](#oh_transfercharacteristic) {<br>TRANSFER_CHARACTERISTIC_BT709 = 1,<br>TRANSFER_CHARACTERISTIC_UNSPECIFIED = 2,<br>TRANSFER_CHARACTERISTIC_GAMMA_2_2 = 4,<br>TRANSFER_CHARACTERISTIC_GAMMA_2_8 = 5,<br>TRANSFER_CHARACTERISTIC_BT601 = 6,<br>TRANSFER_CHARACTERISTIC_SMPTE_ST240 = 7,<br>TRANSFER_CHARACTERISTIC_LINEAR = 8,<br>TRANSFER_CHARACTERISTIC_LOG = 9,<br>TRANSFER_CHARACTERISTIC_LOG_SQRT = 10,<br>TRANSFER_CHARACTERISTIC_IEC_61966_2_4 = 11,<br>TRANSFER_CHARACTERISTIC_BT1361 = 12,<br>TRANSFER_CHARACTERISTIC_IEC_61966_2_1 = 13,<br>TRANSFER_CHARACTERISTIC_BT2020_10BIT = 14,<br>TRANSFER_CHARACTERISTIC_BT2020_12BIT = 15,<br>TRANSFER_CHARACTERISTIC_PQ = 16,<br>TRANSFER_CHARACTERISTIC_SMPTE_ST428 = 17,<br>TRANSFER_CHARACTERISTIC_HLG = 18<br>} | Enumerates the transfer characteristics.| 
| [OH_MatrixCoefficient](#oh_matrixcoefficient) {<br>MATRIX_COEFFICIENT_IDENTITY = 0,<br>MATRIX_COEFFICIENT_BT709 = 1,<br>MATRIX_COEFFICIENT_UNSPECIFIED = 2,<br>MATRIX_COEFFICIENT_FCC = 4,<br>MATRIX_COEFFICIENT_BT601_625 = 5,<br>MATRIX_COEFFICIENT_BT601_525 = 6, MATRIX_COEFFICIENT_SMPTE_ST240 = 7,<br>MATRIX_COEFFICIENT_YCGCO = 8,<br>MATRIX_COEFFICIENT_BT2020_NCL = 9,<br>MATRIX_COEFFICIENT_BT2020_CL = 10,<br>MATRIX_COEFFICIENT_SMPTE_ST2085 = 11,<br>MATRIX_COEFFICIENT_CHROMATICITY_NCL = 12,<br>MATRIX_COEFFICIENT_CHROMATICITY_CL = 13,<br>MATRIX_COEFFICIENT_ICTCP = 14<br>} | Enumerates the matrix coefficients.| 


### Variables

| Name| Description| 
| -------- | -------- |
| const char \* [OH_AVCODEC_MIMETYPE_VIDEO_AVC](#oh_avcodec_mimetype_video_avc) | Defines the pointer to the Multipurpose Internet Mail Extension (MIME) type of AVC (H.264) video codec.| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_AAC](#oh_avcodec_mimetype_audio_aac) | Defines the pointer to the MIME type of AAC audio codec.| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_FLAC](#oh_avcodec_mimetype_audio_flac) | Defines the pointer to the MIME type of Free Lossless Audio Codec (FLAC) audio codec.| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_VORBIS](#oh_avcodec_mimetype_audio_vorbis) | Defines the pointer to the MIME type of Vorbis audio decoder.| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_MPEG](#oh_avcodec_mimetype_audio_mpeg) | Defines the pointer to the MIME type of MP3 audio decoder.| 
| const char \* [OH_AVCODEC_MIMETYPE_VIDEO_HEVC](#oh_avcodec_mimetype_video_hevc) | Defines the pointer to the MIME type of HEVC (H.265) video codec.| 
| const char \* [OH_AVCODEC_MIMETYPE_VIDEO_MPEG4](#oh_avcodec_mimetype_video_mpeg4) | Defines the pointer to the MIME type of MPEG4 video encoder, which is used only for muxing MPEG4 video streams.| 
| const char \* [OH_AVCODEC_MIMETYPE_IMAGE_JPG](#oh_avcodec_mimetype_image_jpg) | Defines the pointer to the MIME type of JPG image encoder, which is used only for muxing JPG covers.| 
| const char \* [OH_AVCODEC_MIMETYPE_IMAGE_PNG](#oh_avcodec_mimetype_image_png) | Defines the pointer to the MIME type of PNG image encoder, which is used only for muxing PNG covers.| 
| const char \* [OH_AVCODEC_MIMETYPE_IMAGE_BMP](#oh_avcodec_mimetype_image_bmp) | Defines the pointer to the MIME type of BMP image encoder, which is used only for muxing BMP covers.| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_VIVID](#oh_avcodec_mimetype_audio_vivid) | Defines the pointer to the MIME type of Audio Vivid audio decoder. (This specification is not available yet.)| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_AMR_NB](#oh_avcodec_mimetype_audio_amr_nb) | Defines the pointer to the MIME type of AMR-NB audio decoder.| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_AMR_WB](#oh_avcodec_mimetype_audio_amr_wb) | Defines the pointer to the MIME type of AMR-WB audio decoder.| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_OPUS](#oh_avcodec_mimetype_audio_opus) | Defines the pointer to the MIME type of Opus audio codec. (This specification is not available yet.)| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_G711MU](#oh_avcodec_mimetype_audio_g711mu) | Defines the pointer to the MIME type of G.711 mu-law audio codec.| 
| const char \* [OH_ED_KEY_TIME_STAMP](#oh_ed_key_time_stamp) | Defines the pointer to the timestamp in the extra data of the surface. The value type is int64.| 
| const char \* [OH_ED_KEY_EOS](#oh_ed_key_eos) | Defines the pointer to the end of stream (EOS) in the extra data of the surface. The value type is Boolean.| 
| const char \* [OH_MD_KEY_TRACK_TYPE](#oh_md_key_track_type) | Defines the pointer to the track type. The value type is uint8_t. For details, see [OH_MediaType](#oh_mediatype).| 
| const char \* [OH_MD_KEY_CODEC_MIME](#oh_md_key_codec_mime) | Define the pointer to the MIME type of codec. The value type is string.| 
| const char \* [OH_MD_KEY_DURATION](#oh_md_key_duration) | Defines the pointer to the duration. The value type is int64_t.| 
| const char \* [OH_MD_KEY_BITRATE](#oh_md_key_bitrate) | Defines the pointer to the bit rate. The value type is int64_t.| 
| const char \* [OH_MD_KEY_MAX_INPUT_SIZE](#oh_md_key_max_input_size) | Defines the pointer to the maximum input size. The value type is uint32_t.| 
| const char \* [OH_MD_KEY_WIDTH](#oh_md_key_width) | Defines the pointer to the video width. The value type is uint32_t.| 
| const char \* [OH_MD_KEY_HEIGHT](#oh_md_key_height) | Defines the pointer to the video height. The value type is uint32_t.| 
| const char \* [OH_MD_KEY_PIXEL_FORMAT](#oh_md_key_pixel_format) | Defines the pointer to the video pixel format. The value type is int32_t. For details, see [OH_AVPixelFormat](_core.md#oh_avpixelformat).| 
| const char \* [OH_MD_KEY_AUDIO_SAMPLE_FORMAT](#oh_md_key_audio_sample_format) | Defines the pointer to the original audio format. The value type is uint32_t.| 
| const char \* [OH_MD_KEY_FRAME_RATE](#oh_md_key_frame_rate) | Defines the pointer to the video frame rate. The value type is double.| 
| const char \* [OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE](#oh_md_key_video_encode_bitrate_mode) | Defines the pointer to the video encoding bit rate mode. The value type is int32_t. For details, see [OH_VideoEncodeBitrateMode](_video_encoder.md#oh_videoencodebitratemode).| 
| const char \* [OH_MD_KEY_PROFILE](#oh_md_key_profile) | Defines the pointer to the encoding template. The value type is number. For details, see [OH_HEVCProfile](#oh_hevcprofile) and [OH_AACProfile](#oh_aacprofile).| 
| const char \* [OH_MD_KEY_AUD_CHANNEL_COUNT](#oh_md_key_aud_channel_count) | Defines the pointer to the number of audio channels. The value type is uint32_t.| 
| const char \* [OH_MD_KEY_AUD_SAMPLE_RATE](#oh_md_key_aud_sample_rate) | Defines the pointer to the audio sampling rate. The value type is uint32_t.| 
| const char \* [OH_MD_KEY_I_FRAME_INTERVAL](#oh_md_key_i_frame_interval) | Defines the pointer to the key frame interval, in milliseconds. The value type is int32_t.| 
| const char \* [OH_MD_KEY_ROTATION](#oh_md_key_rotation) | Defines the pointer to the rotation angle of the surface. The value type is int32_t, and the value range is {0, 90, 180, 270}. The default value is 0.| 
| const char \* [OH_MD_KEY_RANGE_FLAG](#oh_md_key_range_flag) | Defines the pointer to the video YUV value range flag. The value type is Boolean.| 
| const char \* [OH_MD_KEY_COLOR_PRIMARIES](#oh_md_key_color_primaries) | Defines the pointer to the video primary color. The value type is int32_t. For details, see [OH_ColorPrimary](#oh_colorprimary).| 
| const char \* [OH_MD_KEY_TRANSFER_CHARACTERISTICS](#oh_md_key_transfer_characteristics) | Defines the pointer to the video transfer characteristics. The value type is int32_t. For details, see [OH_TransferCharacteristic](#oh_transfercharacteristic).| 
| const char \* [OH_MD_KEY_MATRIX_COEFFICIENTS](#oh_md_key_matrix_coefficients) | Defines the pointer to the video matrix coefficient. The value type is int32_t. For details, see [OH_MatrixCoefficient](#oh_matrixcoefficient).| 
| const char \* [OH_MD_KEY_REQUEST_I_FRAME](#oh_md_key_request_i_frame) | Defines the pointer to the request for immediate encoding of I-frames. The value type is Boolean.| 
| const char \* [OH_MD_KEY_QUALITY](#oh_md_key_quality) | Defines the pointer to the required encoding quality. The value type is uint32_t. This key applies only to encoders configured in constant quality mode.| 
| const char \* [OH_MD_KEY_CODEC_CONFIG](#oh_md_key_codec_config) | Defines the pointer to the codec-specific data. The value type is uint8_t.| 
| const char \* [OH_MD_KEY_TITLE](#oh_md_key_title) | Defines the pointer to the title of the input media. The value type is string.| 
| const char \* [OH_MD_KEY_ARTIST](#oh_md_key_artist) | Defines the pointer to the artist of the input media. The value type is string.| 
| const char \* [OH_MD_KEY_ALBUM](#oh_md_key_album) | Defines the pointer to the album of the input media. The value type is string.| 
| const char \* [OH_MD_KEY_ALBUM_ARTIST](#oh_md_key_album_artist) | Defines the pointer to the album artist of the input media. The value type is string.| 
| const char \* [OH_MD_KEY_DATE](#oh_md_key_date) | Defines the pointer to the date of the input media. The value type is string.| 
| const char \* [OH_MD_KEY_COMMENT](#oh_md_key_comment) | Defines the pointer to the comment of the input media. The value type is string.| 
| const char \* [OH_MD_KEY_GENRE](#oh_md_key_genre) | Defines the pointer to the genre of the input media. The value type is string.| 
| const char \* [OH_MD_KEY_COPYRIGHT](#oh_md_key_copyright) | Defines the pointer to the copyright of the input media. The value type is string.| 
| const char \* [OH_MD_KEY_LANGUAGE](#oh_md_key_language) | Defines the pointer to the language of the input media. The value type is string.| 
| const char \* [OH_MD_KEY_DESCRIPTION](#oh_md_key_description) | Defines the pointer to the description of the input media. The value type is string.| 
| const char \* [OH_MD_KEY_LYRICS](#oh_md_key_lyrics) | Defines the pointer to the lyrics of the input media. The value type is string.| 
| const char \* [OH_MD_KEY_TRACK_COUNT](#oh_md_key_track_count) | Defines the pointer to the track count of the input media. The value type is uint32_t.| 
| const char \* [OH_MD_KEY_CHANNEL_LAYOUT](#oh_md_key_channel_layout) | Defines the pointer to the required encoding channel layout. The value type is int64_t. This key applies only to encoders.| 
| const char \* [OH_MD_KEY_BITS_PER_CODED_SAMPLE](#oh_md_key_bits_per_coded_sample) | Defines the pointer to the number of bits for each coded sample. The value type is uint32_t. This key applies to FLAC encoders. For details, see [OH_BitsPerSample](#oh_bitspersample).| 
| const char \* [OH_MD_KEY_AAC_IS_ADTS](#oh_md_key_aac_is_adts) | Defines the pointer to the AAC format. The value type is uint32_t. This key applies to AAC decoders.| 
| const char \* [OH_MD_KEY_SBR](#oh_md_key_sbr) | Defines the pointer to the AAC SBR format. The value type is uint32_t. This key applies to AAC encoders.| 
| const char \* [OH_MD_KEY_COMPLIANCE_LEVEL](#oh_md_key_compliance_level) | Defines the pointer to the FLAC compliance level. The value type is int32_t.| 
| const char \* [OH_MD_KEY_IDENTIFICATION_HEADER](#oh_md_key_identification_header) | Defines the pointer to the Vorbis identification header. The value type is uint8_t. This key applies only to Vorbis decoders.| 
| const char \* [OH_MD_KEY_SETUP_HEADER](#oh_md_key_setup_header) | Defines the pointer to the Vorbis setup header. The value type is uint8_t. This key applies only to Vorbis decoders.| 
| const char \* [OH_MD_KEY_SCALING_MODE](#oh_md_key_scaling_mode) | Defines the pointer to the video surface scale mode. The value type is int32_t. For details, see [OH_ScalingMode](#oh_scalingmode).| 
| const char \* [OH_MD_MAX_INPUT_BUFFER_COUNT](#oh_md_max_input_buffer_count) | Defines the pointer to the maximum number of input buffers. The value type is int32_t.| 
| const char \* [OH_MD_MAX_OUTPUT_BUFFER_COUNT](#oh_md_max_output_buffer_count) | Defines the pointer to the maximum number of output buffers. The value type is int32_t.| 
| const char \* [OH_MD_KEY_AUDIO_COMPRESSION_LEVEL](#oh_md_key_audio_compression_level) | Defines the pointer to the audio codec compression level. The value type is uint32_t.| 
| const char \* [OH_MD_KEY_VIDEO_IS_HDR_VIVID](#oh_md_key_video_is_hdr_vivid) | Defines the pointer to indicate whether it is HDR Vivid. The value type is Boolean.| 
| const char \* [OH_MD_KEY_AUDIO_OBJECT_NUMBER](#oh_md_key_audio_object_number) | Defines the pointer to the number of audio objects. The value type is int32_t.| 
| const char \* [OH_MD_KEY_AUDIO_VIVID_METADATA](#oh_md_key_audio_vivid_metadata) | Defines the pointer to the Audio Vivid metadata. The value type is uint8_t.| 


## Type Description


### OH_AACProfile

```
typedef enum OH_AACProfileOH_AACProfile
```

**Description**

Defines an enum that enumerates the AAC profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_AVCodecAsyncCallback

```
typedef struct OH_AVCodecAsyncCallbackOH_AVCodecAsyncCallback
```

**Description**

Defines a struct for all the asynchronous callback function pointers of an **OH_AVCodec** instance. To ensure the normal running of **OH_AVCodec**, you must register the instance of this struct with the **OH_AVCodec** instance and process the information reported by the callback function.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

**Deprecated from**: 11

**Substitute**: [OH_AVCodecCallback](#oh_avcodeccallback)

**Parameters**

| Name| Description| 
| -------- | -------- |
| onError | Callback used to report a codec operation error. For details, see [OH_AVCodecOnError](#oh_avcodeconerror).| 
| onStreamChanged | Callback used to report a codec stream change. For details, see [OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged).| 
| onNeedInputData | Callback used to report input data required. For details, see [OH_AVCodecOnNeedInputData](#oh_avcodeconneedinputdata).| 
| onNeedOutputData | Callback used to report output data generated. For details, see [OH_AVCodecOnNewOutputData](#oh_avcodeconnewoutputdata).| 


### OH_AVCodecCallback

```
typedef struct OH_AVCodecCallbackOH_AVCodecCallback
```

**Description**

Defines a struct for all the asynchronous callback function pointers of an **OH_AVCodec** instance. To ensure the normal running of **OH_AVCodec**, you must register the instance of this struct with the **OH_AVCodec** instance and process the information reported by the callback function.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| onError | Callback used to report a codec operation error. For details, see [OH_AVCodecOnError](#oh_avcodeconerror).| 
| onStreamChanged | Callback used to report a codec stream change. For details, see [OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged).| 
| onNeedInputBuffer | Callback used to report input data required. For details, see [OH_AVCodecOnNeedInputBuffer](#oh_avcodeconneedinputbuffer).| 
| onNewOutputBuffer | Callback used to report output data generated. For details, see [OH_AVCodecOnNewOutputBuffer](#oh_avcodeconnewoutputbuffer).| 


### OH_AVCodecOnError

```
typedef void(* OH_AVCodecOnError) (OH_AVCodec *codec, int32_t errorCode, void *userData)
```

**Description**

Defines the pointer to the function that is called to report error information when an error occurs during the running of an **OH_AVCodec** instance.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| codec | Pointer to an **OH_AVCodec** instance.| 
| errorCode | Error code.| 
| userData | Pointer to user-specific data.| 


### OH_AVCodecOnNeedInputBuffer

```
typedef void(* OH_AVCodecOnNeedInputBuffer) (OH_AVCodec *codec, uint32_t index, OH_AVBuffer *buffer, void *userData)
```

**Description**

Defines the pointer to the function that is called when new input data is required during the running of an **OH_AVCodec** instance. The function carries a buffer to fill in new input data.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| codec | Pointer to an **OH_AVCodec** instance.| 
| index | Index of the new input buffer.| 
| buffer | Pointer to the data to fill in the new input buffer.| 
| userData | Pointer to user-specific data.| 


### OH_AVCodecOnNeedInputData

```
typedef void(* OH_AVCodecOnNeedInputData) (OH_AVCodec *codec, uint32_t index, OH_AVMemory *data, void *userData)
```

**Description**

Defines the pointer to the function that is called when new input data is required during the running of an **OH_AVCodec** instance. The function carries a buffer to fill in new input data.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

**Deprecated version**: 11

**Substitute**: [OH_AVCodecOnNeedInputBuffer](#oh_avcodeconneedinputbuffer)

**Parameters**

| Name| Description| 
| -------- | -------- |
| codec | Pointer to an **OH_AVCodec** instance.| 
| index | Index of the new input buffer.| 
| data | Pointer to the data to fill in the new input buffer.| 
| userData | Pointer to user-specific data.| 


### OH_AVCodecOnNewOutputBuffer

```
typedef void(* OH_AVCodecOnNewOutputBuffer) (OH_AVCodec *codec, uint32_t index, OH_AVBuffer *buffer, void *userData)
```

**Description**

Defines the pointer to the function that is called when new output data is generated during the running of an **OH_AVCodec** instance. The function carries a buffer filled with new output data.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| codec | Pointer to an **OH_AVCodec** instance.| 
| index | Index of the new output buffer.| 
| buffer | Pointer to the data filled in the new output buffer.| 
| userData | Pointer to user-specific data.| 


### OH_AVCodecOnNewOutputData

```
typedef void(* OH_AVCodecOnNewOutputData) (OH_AVCodec *codec, uint32_t index, OH_AVMemory *data, OH_AVCodecBufferAttr *attr, void *userData)
```

**Description**

Defines the pointer to the function that is called when new output data is generated during the running of an **OH_AVCodec** instance. The function carries a buffer filled with new output data. Note that the lifecycle of the pointer to the **OH_AVCodecBufferAttr** instance is valid only when the function pointer is being called. Do not access the pointer to the instance after the function pointer is called.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

**Deprecated from**: 11

**Substitute**: [OH_AVCodecOnNewOutputBuffer](#oh_avcodeconnewoutputbuffer)

**Parameters**

| Name| Description| 
| -------- | -------- |
| codec | Pointer to an **OH_AVCodec** instance.| 
| index | Index of the new output buffer.| 
| data | Pointer to the data filled in the new output buffer.| 
| attr | Pointer to the description information about the new output buffer. For details, see [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md).| 
| userData | Pointer to user-specific data.| 


### OH_AVCodecOnStreamChanged

```
typedef void(* OH_AVCodecOnStreamChanged) (OH_AVCodec *codec, OH_AVFormat *format, void *userData)
```

**Description**

Defines the pointer to the function that is called to report the new stream description when the output stream changes. Note that the lifecycle of the pointer to the **OH_AVFormat** instance is valid only when the function pointer is being called. Do not access the pointer to the instance after the function pointer is called.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| codec | Pointer to an **OH_AVCodec** instance.| 
| format | Pointer to the description information about the new output stream.| 
| userData | Pointer to user-specific data.| 


### OH_AVCProfile

```
typedef enum OH_AVCProfileOH_AVCProfile
```

**Description**

Defines an enum that enumerates the AVC profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_AVOutputFormat

```
typedef enum OH_AVOutputFormatOH_AVOutputFormat
```

**Description**

Defines an enum that enumerates the output file formats of a muxer.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_AVSeekMode

```
typedef enum OH_AVSeekModeOH_AVSeekMode
```

**Description**

Defines an enum that enumerates the seek modes.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_BitsPerSample

```
typedef enum OH_BitsPerSampleOH_BitsPerSample
```

**Description**

Defines an enum that enumerates the number of audio bits for each coded sample.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_ColorPrimary

```
typedef enum OH_ColorPrimaryOH_ColorPrimary
```

**Description**

Defines an enum that enumerates the primary colors.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_HEVCProfile

```
typedef enum OH_HEVCProfileOH_HEVCProfile
```

**Description**

Defines an enum that enumerates the HEVC profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MatrixCoefficient

```
typedef enum OH_MatrixCoefficientOH_MatrixCoefficient
```

**Description**

Defines an enum that enumerates the matrix coefficients.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MediaType

```
typedef enum OH_MediaTypeOH_MediaType
```

**Description**

Defines an enum that enumerates the media types.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_ScalingMode

```
typedef enum OH_ScalingModeOH_ScalingMode
```

**Description**

Defines an enum that enumerates the scaling modes.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_TransferCharacteristic

```
typedef enum OH_TransferCharacteristicOH_TransferCharacteristic
```

**Description**

Defines an enum that enumerates the transfer characteristics.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


## Enum Description


### AudioChannelLayout

```
enum AudioChannelLayout : uint64_t
```

**Description**

Enumerates the types of the audio channel sets. The output format of the decoder is represented as the channel type of the codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Deprecated from**: 11

**Substitute**: [OH_AudioChannelLayout](_core.md#oh_audiochannellayout)

| Value| Description| 
| -------- | -------- |
| UNKNOWN_CHANNEL_LAYOUT | Unknown.| 
| MONO | Mono layout.| 
| STEREO | Stereo layout| 
| CH_2POINT1 | 2.1 layout.| 
| CH_2_1 | 2_1 layout.| 
| SURROUND | Surround layout.| 
| CH_3POINT1 | 3.1 layout.| 
| CH_4POINT0 | 4.0 layout.| 
| CH_4POINT1 | 4.1 layout.| 
| CH_2_2 | 2_2 layout.| 
| QUAD | Quad layout.| 
| CH_5POINT0 | 5.0 layout.| 
| CH_5POINT1 | 5.1 layout.| 
| CH_5POINT0_BACK | 5.0 rear layout.| 
| CH_5POINT1_BACK | 5.1 rear layout.| 
| CH_6POINT0 | 6.0 layout.| 
| CH_6POINT0_FRONT | 6.0 front layout.| 
| HEXAGONAL | Hexagonal layout.| 
| CH_6POINT1 | 6.1 layout.| 
| CH_6POINT1_BACK | 6.1 rear layout.| 
| CH_6POINT1_FRONT | 6.1 front layout.| 
| CH_7POINT0 | 7.0 layout.| 
| CH_7POINT0_FRONT | 7.0 front layout.| 
| CH_7POINT1 | 7.1 layout.| 
| CH_7POINT1_WIDE | 7.1 wide layout.| 
| CH_7POINT1_WIDE_BACK | 7.1 rear wide layout.| 
| CH_3POINT1POINT2 | 3.1.2 layout.| 
| CH_5POINT1POINT2 | 5.1.2 layout.| 
| CH_5POINT1POINT4 | 5.1.4 layout.| 
| CH_7POINT1POINT2 | 7.1.2 layout.| 
| CH_7POINT1POINT4 | 7.1.4 layout.| 
| CH_9POINT1POINT4 | 9.1.4 layout.| 
| CH_9POINT1POINT6 | 9.1.6 layout.| 
| CH_10POINT2 | 10.2 layout.| 
| CH_22POINT2 | 22.2 layout.| 
| OCTAGONAL | Octagonal layout.| 
| HEXADECAGONAL | Hexadecagonal layout.| 
| STEREO_DOWNMIX | Stereo downmix layout.| 
| HOA_FIRST | High-Order Ambisonics (HOA) first-order layout.| 
| HOA_SECOND | HOA second-order layout.| 
| HOA_THIRD | HOA third-order layout.| 


### AudioChannelSet

```
enum AudioChannelSet : uint64_t
```

**Description**

Enumerates the audio channel sets. Each channel number is mapped to a variable of int64.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Deprecated from**: 11. Use [OH_AudioChannelSet](_core.md#oh_audiochannelset) instead.

| Value| Description| 
| -------- | -------- |
| FRONT_LEFT | Front left channel.| 
| FRONT_RIGHT | Front right channel| 
| FRONT_CENTER | Front center channel.| 
| LOW_FREQUENCY | Low-frequency channel.| 
| BACK_LEFT | Rear left channel.| 
| BACK_RIGHT | Rear right channel| 
| FRONT_LEFT_OF_CENTER | Front left center channel.| 
| FRONT_RIGHT_OF_CENTER | Front right center channel.| 
| BACK_CENTER | Rear center channel.| 
| SIDE_LEFT | Left channel.| 
| SIDE_RIGHT | Right channel.| 
| TOP_CENTER | Top center channel.| 
| TOP_FRONT_LEFT | Top left front channel.| 
| TOP_FRONT_CENTER | Top center front channel.| 
| TOP_FRONT_RIGHT | Top right front channel.| 
| TOP_BACK_LEFT | Top left rear channel.| 
| TOP_BACK_CENTER | Top center rear channel.| 
| TOP_BACK_RIGHT | Top right rear channel.| 
| STEREO_LEFT | Stereo left channel.| 
| STEREO_RIGHT | Stereo right channel.| 
| WIDE_LEFT | Wide left channel.| 
| WIDE_RIGHT | Wide right channel.| 
| SURROUND_DIRECT_LEFT | Left surround channel.| 
| SURROUND_DIRECT_RIGHT | Right surround channel.| 
| LOW_FREQUENCY_2 | Low-frequency channel 2.| 
| TOP_SIDE_LEFT | Top left channel.| 
| TOP_SIDE_RIGHT | Top right channel.| 
| BOTTOM_FRONT_CENTER | Bottom center front channel.| 
| BOTTOM_FRONT_LEFT | Bottom left front channel.| 
| BOTTOM_FRONT_RIGHT | Bottom right front channel.| 
| AMBISONICS_ACN0 | Channel 0 for the zero-order stereo.| 
| AMBISONICS_ACN1 | Channel 1 for the first-order stereo.| 
| AMBISONICS_ACN2 | Channel 2 for the first-order stereo.| 
| AMBISONICS_ACN3 | Channel 3 for the first-order stereo.| 
| AMBISONICS_W | Equivalent to channel 0 for the zero-order stereo.| 
| AMBISONICS_Y | Equivalent to channel 1 for the first-order stereo.| 
| AMBISONICS_Z | Equivalent to channel 2 for the first-order stereo.| 
| AMBISONICS_X | Equivalent to channel 3 for the first-order stereo.| 
| AMBISONICS_ACN4 | Channel 4 for the second-order stereo.| 
| AMBISONICS_ACN5 | Channel 5 for the second-order stereo.| 
| AMBISONICS_ACN6 | Channel 6 for the second-order stereo.| 
| AMBISONICS_ACN7 | Channel 7 for the second-order stereo.| 
| AMBISONICS_ACN8 | Channel 8 for the second-order stereo.| 
| AMBISONICS_ACN9 | Channel 9 for the third-order stereo.| 
| AMBISONICS_ACN10 | Channel 10 for the third-order stereo.| 
| AMBISONICS_ACN11 | Channel 11 for the third-order stereo.| 
| AMBISONICS_ACN12 | Channel 12 for the third-order stereo.| 
| AMBISONICS_ACN13 | Channel 13 for the third-order stereo.| 
| AMBISONICS_ACN14 | Channel 14 for the third-order stereo.| 
| AMBISONICS_ACN15 | Channel 15 for the third-order stereo.| 


### OH_AACProfile

```
enum OH_AACProfile
```

**Description**

Enumerates the AAC profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

| Value| Description| 
| -------- | -------- |
| AAC_PROFILE_LC | Low complexity level.| 


### OH_AVCProfile

```
enum OH_AVCProfile
```

**Description**

Enumerates the AVC profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

| Value| Description| 
| -------- | -------- |
| AVC_PROFILE_BASELINE | Baseline.| 
| AVC_PROFILE_HIGH | High.| 
| AVC_PROFILE_MAIN | Main.| 


### OH_AVOutputFormat

```
enum OH_AVOutputFormat
```

**Description**

Enumerates the output file formats of a muxer.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description| 
| -------- | -------- |
| AV_OUTPUT_FORMAT_DEFAULT | Default format, which is MP4.| 
| AV_OUTPUT_FORMAT_MPEG_4 | MP4.| 
| AV_OUTPUT_FORMAT_M4A | M4A.| 


### OH_AVSeekMode

```
enum OH_AVSeekMode
```

**Description**

Enumerates the seek modes.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description| 
| -------- | -------- |
| SEEK_MODE_NEXT_SYNC | Seeks to the next key frame at the specified position.| 
| SEEK_MODE_PREVIOUS_SYNC | Seeks to the previous key frame at the specified position.| 
| SEEK_MODE_CLOSEST_SYNC | Seeks to the latest key frame at the specified position.| 


### OH_BitsPerSample

```
enum OH_BitsPerSample
```

**Description**

Enumerates the number of audio bits for each coded sample.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description| 
| -------- | -------- |
| SAMPLE_U8 | 8-bit unsigned integer sampling.| 
| SAMPLE_S16LE | 16-bit signed integer sampling.| 
| SAMPLE_S24LE | 24-bit signed integer sampling.| 
| SAMPLE_S32LE | 32-bit signed integer sampling.| 
| SAMPLE_F32LE | 32-bit floating-point sampling.| 
| SAMPLE_U8P | 8-bit unsigned integer plane sampling.| 
| SAMPLE_S16P | 16-bit signed integer plane sampling.| 
| SAMPLE_S24P | 24-bit signed integer plane sampling.| 
| SAMPLE_S32P | 32-bit signed integer plane sampling.| 
| SAMPLE_F32P | 32-bit floating-point plane sampling.| 
| INVALID_WIDTH | Invalid sampling format.| 


### OH_ColorPrimary

```
enum OH_ColorPrimary
```

**Description**

Enumerates the primary colors.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description| 
| -------- | -------- |
| COLOR_PRIMARY_BT709 | BT.709 color gamut.| 
| COLOR_PRIMARY_UNSPECIFIED | Unspecified color gamut.| 
| COLOR_PRIMARY_BT470_M | BT.470 System M color gamut.| 
| COLOR_PRIMARY_BT601_625 | BT.601 625 color gamut.| 
| COLOR_PRIMARY_BT601_525 | BT.601 525 color gamut.| 
| COLOR_PRIMARY_SMPTE_ST240 | SMPTE ST 240 color gamut.| 
| COLOR_PRIMARY_GENERIC_FILM | Generic film color gamut.| 
| COLOR_PRIMARY_BT2020 | BT.2020 color gamut.| 
| COLOR_PRIMARY_SMPTE_ST428 | SMPTE ST 428 color gamut.| 
| COLOR_PRIMARY_P3DCI | DCI-P3 color gamut.| 
| COLOR_PRIMARY_P3D65 | P3-D65 color gamut.| 


### OH_HEVCProfile

```
enum OH_HEVCProfile
```

**Description**

Enumerates the HEVC profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description| 
| -------- | -------- |
| HEVC_PROFILE_MAIN | Main.| 
| HEVC_PROFILE_MAIN_10 | Main 10.| 
| HEVC_PROFILE_MAIN_STILL | Main Still Picture.| 
| HEVC_PROFILE_MAIN_10_HDR10 | Main 10 HDR10.| 
| HEVC_PROFILE_MAIN_10_HDR10_PLUS | Main 10 HDR10+.| 


### OH_MatrixCoefficient

```
enum OH_MatrixCoefficient
```

**Description**

Enumerates the matrix coefficients.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description| 
| -------- | -------- |
| MATRIX_COEFFICIENT_IDENTITY | Identity matrix.| 
| MATRIX_COEFFICIENT_BT709 | BT.709 conversion matrix.| 
| MATRIX_COEFFICIENT_UNSPECIFIED | Unspecified conversion matrix.| 
| MATRIX_COEFFICIENT_FCC | FCC conversion matrix.| 
| MATRIX_COEFFICIENT_BT601_625 | BT.601 625 conversion matrix.| 
| MATRIX_COEFFICIENT_BT601_525 | BT.601 525 conversion matrix.| 
| MATRIX_COEFFICIENT_SMPTE_ST240 | SMPTE ST 240 conversion matrix.| 
| MATRIX_COEFFICIENT_YCGCO | YCgCo conversion matrix.| 
| MATRIX_COEFFICIENT_BT2020_NCL | BT.2020 NCL conversion matrix.| 
| MATRIX_COEFFICIENT_BT2020_CL | BT.2020 CL conversion matrix.| 
| MATRIX_COEFFICIENT_SMPTE_ST2085 | SMPTE ST 2085 conversion matrix.| 
| MATRIX_COEFFICIENT_CHROMATICITY_NCL | Chromaticity NCL conversion matrix.| 
| MATRIX_COEFFICIENT_CHROMATICITY_CL | Chromaticity CL conversion matrix.| 
| MATRIX_COEFFICIENT_ICTCP | ICTCP conversion matrix.| 


### OH_MediaType

```
enum OH_MediaType
```

**Description**

Enumerates the media types.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

| Value| Description| 
| -------- | -------- |
| MEDIA_TYPE_AUD | Audio track.| 
| MEDIA_TYPE_VID | Video track.| 


### OH_ScalingMode

```
enum OH_ScalingMode
```

**Description**

Enumerates the scaling modes.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description| 
| -------- | -------- |
| SCALING_MODE_SCALE_TO_WINDOW | Scales the image based on the window size.| 
| SCALING_MODE_SCALE_CROP | Crops the image based on the window size.| 


### OH_TransferCharacteristic

```
enum OH_TransferCharacteristic
```

**Description**

Enumerates the transfer characteristics.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description| 
| -------- | -------- |
| TRANSFER_CHARACTERISTIC_BT709 | BT.709 transfer function.| 
| TRANSFER_CHARACTERISTIC_UNSPECIFIED | Unspecified transfer function.| 
| TRANSFER_CHARACTERISTIC_GAMMA_2_2 | Gamma 2-2 transfer function.| 
| TRANSFER_CHARACTERISTIC_GAMMA_2_8 | Gamma 2-8 transfer function.| 
| TRANSFER_CHARACTERISTIC_BT601 | BT.601 transfer function.| 
| TRANSFER_CHARACTERISTIC_SMPTE_ST240 | SMPTE ST 240 transfer function.| 
| TRANSFER_CHARACTERISTIC_LINEAR | Linear transfer function.| 
| TRANSFER_CHARACTERISTIC_LOG | Log transfer function.| 
| TRANSFER_CHARACTERISTIC_LOG_SQRT | Log SQRT transfer function.| 
| TRANSFER_CHARACTERISTIC_IEC_61966_2_4 | IEC61966-2.4 transfer function.| 
| TRANSFER_CHARACTERISTIC_BT1361 | BT.1361 transfer function.| 
| TRANSFER_CHARACTERISTIC_IEC_61966_2_1 | IEC61966 2.1 transfer function.| 
| TRANSFER_CHARACTERISTIC_BT2020_10BIT | BT.2020 10-bit transfer function.| 
| TRANSFER_CHARACTERISTIC_BT2020_12BIT | BT.2020 12-bit transfer function.| 
| TRANSFER_CHARACTERISTIC_PQ | PQ transfer function.| 
| TRANSFER_CHARACTERISTIC_SMPTE_ST428 | SMPTE ST.428 transfer function.| 
| TRANSFER_CHARACTERISTIC_HLG | HLG transfer function.| 


## Variable Description


### OH_AVCODEC_MIMETYPE_AUDIO_AAC

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_AAC
```

**Description**

Defines the pointer to the MIME type of AAC audio codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_AVCODEC_MIMETYPE_AUDIO_AMR_NB

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_AMR_NB
```

**Description**

Defines the pointer to the MIME type of AMR-NB audio decoder.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 11


### OH_AVCODEC_MIMETYPE_AUDIO_AMR_WB

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_AMR_WB
```

**Description**

Defines the pointer to the MIME type of AMR-WB audio decoder.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 11


### OH_AVCODEC_MIMETYPE_AUDIO_FLAC

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_FLAC
```

**Description**

Defines the pointer to the MIME type of FLAC audio codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_AVCODEC_MIMETYPE_AUDIO_G711MU

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_G711MU
```

**Description**

Defines the pointer to the MIME type of G.711 mu-law audio codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 11


### OH_AVCODEC_MIMETYPE_AUDIO_MPEG

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_MPEG
```

**Description**

Defines the pointer to the MIME type of MP3 audio decoder.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_AVCODEC_MIMETYPE_AUDIO_OPUS

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_OPUS
```

**Description**

Defines the pointer to the MIME type of Opus audio codec. (This specification is not available yet.)

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 11


### OH_AVCODEC_MIMETYPE_AUDIO_VIVID

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_VIVID
```

**Description**

Defines the pointer to the MIME type of Audio Vivid audio decoder. (This specification is not available yet.)

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 11


### OH_AVCODEC_MIMETYPE_AUDIO_VORBIS

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_VORBIS
```

**Description**

Defines the pointer to the MIME type of Vorbis audio decoder.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_AVCODEC_MIMETYPE_IMAGE_BMP

```
const char* OH_AVCODEC_MIMETYPE_IMAGE_BMP
```

**Description**

Defines the pointer to the MIME type of BMP image encoder, which is used only for muxing BMP covers.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_AVCODEC_MIMETYPE_IMAGE_JPG

```
const char* OH_AVCODEC_MIMETYPE_IMAGE_JPG
```

**Description**

Defines the pointer to the MIME type of JPG image encoder, which is used only for muxing JPG covers.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_AVCODEC_MIMETYPE_IMAGE_PNG

```
const char* OH_AVCODEC_MIMETYPE_IMAGE_PNG
```

**Description**

Defines the pointer to the MIME type of PNG image encoder, which is used only for muxing PNG covers.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_AVCODEC_MIMETYPE_VIDEO_AVC

```
const char* OH_AVCODEC_MIMETYPE_VIDEO_AVC
```

**Description**

Defines the pointer to the MIME type of AVC (H.264) video codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_AVCODEC_MIMETYPE_VIDEO_HEVC

```
const char* OH_AVCODEC_MIMETYPE_VIDEO_HEVC
```

**Description**

Defines the pointer to the MIME type of HEVC (H.265) video codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_AVCODEC_MIMETYPE_VIDEO_MPEG4

```
const char* OH_AVCODEC_MIMETYPE_VIDEO_MPEG4
```

**Description**

Defines the pointer to the MIME type of MPEG4 video encoder, which is used only for muxing MPEG4 video streams.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Deprecated from**: 11


### OH_ED_KEY_EOS

```
const char* OH_ED_KEY_EOS
```

**Description**

Defines the pointer to the EOS in the extra data of the surface. The value type is Boolean.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_ED_KEY_TIME_STAMP

```
const char* OH_ED_KEY_TIME_STAMP
```

**Description**

Defines the pointer to the timestamp in the extra data of the surface. The value type is int64.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_AAC_IS_ADTS

```
const char* OH_MD_KEY_AAC_IS_ADTS
```

**Description**

Defines the pointer to the AAC format. The value type is uint32_t. This key applies to AAC decoders.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_ALBUM

```
const char* OH_MD_KEY_ALBUM
```

**Description**

Defines the pointer to the album of the input media. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_ALBUM_ARTIST

```
const char* OH_MD_KEY_ALBUM_ARTIST
```

**Description**

Defines the pointer to the album artist of the input media. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_ARTIST

```
const char* OH_MD_KEY_ARTIST
```

**Description**

Defines the pointer to the artist of the input media. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_AUD_CHANNEL_COUNT

```
const char* OH_MD_KEY_AUD_CHANNEL_COUNT
```

**Description**

Defines the pointer to the number of audio channels. The value type is uint32_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_AUD_SAMPLE_RATE

```
const char* OH_MD_KEY_AUD_SAMPLE_RATE
```

**Description**

Defines the pointer to the audio sampling rate. The value type is uint32_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_AUDIO_COMPRESSION_LEVEL

```
const char* OH_MD_KEY_AUDIO_COMPRESSION_LEVEL
```

**Description**

Defines the pointer to the audio codec compression level. The value type is uint32_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 11


### OH_MD_KEY_AUDIO_OBJECT_NUMBER

```
const char* OH_MD_KEY_AUDIO_OBJECT_NUMBER
```

**Description**

Defines the pointer to the number of audio objects. The value type is int32_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 11


### OH_MD_KEY_AUDIO_SAMPLE_FORMAT

```
const char* OH_MD_KEY_AUDIO_SAMPLE_FORMAT
```

**Description**

Defines the pointer to the original audio format. The value type is uint32_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_AUDIO_VIVID_METADATA

```
const char* OH_MD_KEY_AUDIO_VIVID_METADATA
```

**Description**

Defines the pointer to the Audio Vivid metadata. The value type is uint8_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 11


### OH_MD_KEY_BITRATE

```
const char* OH_MD_KEY_BITRATE
```

**Description**

Defines the pointer to the bit rate. The value type is int64_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_BITS_PER_CODED_SAMPLE

```
const char* OH_MD_KEY_BITS_PER_CODED_SAMPLE
```

**Description**

Defines the pointer to the number of bits for each coded sample. The value type is uint32_t. This key applies to FLAC encoders. For details, see [OH_BitsPerSample](#oh_bitspersample).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_CHANNEL_LAYOUT

```
const char* OH_MD_KEY_CHANNEL_LAYOUT
```

**Description**

Defines the pointer to the required encoding channel layout. The value type is int64_t. This key applies only to encoders.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_CODEC_CONFIG

```
const char* OH_MD_KEY_CODEC_CONFIG
```

**Description**

Defines the pointer to the codec-specific data. The value type is uint8_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_CODEC_MIME

```
const char* OH_MD_KEY_CODEC_MIME
```

**Description**

Define the pointer to the MIME type of codec. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_COLOR_PRIMARIES

```
const char* OH_MD_KEY_COLOR_PRIMARIES
```

**Description**

Defines the pointer to the video primary color. The value type is int32_t. For details, see [OH_ColorPrimary](#oh_colorprimary).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_COMMENT

```
const char* OH_MD_KEY_COMMENT
```

**Description**

Defines the pointer to the comment of the input media. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_COMPLIANCE_LEVEL

```
const char* OH_MD_KEY_COMPLIANCE_LEVEL
```

**Description**

Defines the pointer to the FLAC compliance level. The value type is int32_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_COPYRIGHT

```
const char* OH_MD_KEY_COPYRIGHT
```

**Description**

Defines the pointer to the copyright of the input media. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_DATE

```
const char* OH_MD_KEY_DATE
```

**Description**

Defines the pointer to the date of the input media. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_DESCRIPTION

```
const char* OH_MD_KEY_DESCRIPTION
```

**Description**

Defines the pointer to the description of the input media. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_DURATION

```
const char* OH_MD_KEY_DURATION
```

**Description**

Defines the pointer to the duration. The value type is int64_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_FRAME_RATE

```
const char* OH_MD_KEY_FRAME_RATE
```

**Description**

Defines the pointer to the video frame rate. The value type is double.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_GENRE

```
const char* OH_MD_KEY_GENRE
```

**Description**

Defines the pointer to the genre of the input media. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_HEIGHT

```
const char* OH_MD_KEY_HEIGHT
```

**Description**

Defines the pointer to the video height. The value type is uint32_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_I_FRAME_INTERVAL

```
const char* OH_MD_KEY_I_FRAME_INTERVAL
```

**Description**

Defines the pointer to the key frame interval, in milliseconds. The value type is int32_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_IDENTIFICATION_HEADER

```
const char* OH_MD_KEY_IDENTIFICATION_HEADER
```

**Description**

Defines the pointer to the Vorbis identification header. The value type is uint8_t. This key applies only to Vorbis decoders.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_LANGUAGE

```
const char* OH_MD_KEY_LANGUAGE
```

**Description**

Defines the pointer to the language of the input media. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_LYRICS

```
const char* OH_MD_KEY_LYRICS
```

**Description**

Defines the pointer to the lyrics of the input media. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_MATRIX_COEFFICIENTS

```
const char* OH_MD_KEY_MATRIX_COEFFICIENTS
```

**Description**

Defines the pointer to the video matrix coefficient. The value type is int32_t. For details, see [OH_MatrixCoefficient](#oh_matrixcoefficient).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_MAX_INPUT_SIZE

```
const char* OH_MD_KEY_MAX_INPUT_SIZE
```

**Description**

Defines the pointer to the maximum input size. The value type is uint32_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_PIXEL_FORMAT

```
const char* OH_MD_KEY_PIXEL_FORMAT
```

**Description**

Defines the pointer to the video pixel format. The value type is int32_t. For details, see [OH_AVPixelFormat](_core.md#oh_avpixelformat).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_PROFILE

```
const char* OH_MD_KEY_PROFILE
```

**Description**

Defines the pointer to the encoding template. The value type is number. For details, see [OH_HEVCProfile](#oh_hevcprofile) and [OH_AACProfile](#oh_aacprofile).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_QUALITY

```
const char* OH_MD_KEY_QUALITY
```

**Description**

Defines the pointer to the required encoding quality. The value type is uint32_t. This key applies only to encoders configured in constant quality mode.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_RANGE_FLAG

```
const char* OH_MD_KEY_RANGE_FLAG
```

**Description**

Defines the pointer to the video YUV value range flag. The value type is Boolean.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_REQUEST_I_FRAME

```
const char* OH_MD_KEY_REQUEST_I_FRAME
```

**Description**

Defines the pointer to the request for immediate encoding of I-frames. The value type is Boolean.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_ROTATION

```
const char* OH_MD_KEY_ROTATION
```

**Description**

Defines the pointer to the rotation angle of the surface. The value type is int32_t, and the value range is {0, 90, 180, 270}. The default value is 0.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_SBR

```
const char* OH_MD_KEY_SBR
```

**Description**

Defines the pointer to the AAC SBR format. The value type is uint32_t. This key applies to AAC encoders.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_SCALING_MODE

```
const char* OH_MD_KEY_SCALING_MODE
```

**Description**

Defines the pointer to the video surface scale mode. The value type is int32_t. For details, see [OH_ScalingMode](#oh_scalingmode).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_SETUP_HEADER

```
const char* OH_MD_KEY_SETUP_HEADER
```

**Description**

Defines the pointer to the Vorbis setup header. The value type is uint8_t. This key applies only to Vorbis decoders.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_TITLE

```
const char* OH_MD_KEY_TITLE
```

**Description**

Defines the pointer to the title of the input media. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_TRACK_COUNT

```
const char* OH_MD_KEY_TRACK_COUNT
```

**Description**

Defines the pointer to the track count of the input media. The value type is uint32_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_TRACK_TYPE

```
const char* OH_MD_KEY_TRACK_TYPE
```

**Description**

Defines the pointer to the track type. The value type is uint8_t. For details, see [OH_MediaType](#oh_mediatype).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_TRANSFER_CHARACTERISTICS

```
const char* OH_MD_KEY_TRANSFER_CHARACTERISTICS
```

**Description**

Defines the pointer to the video transfer characteristics. The value type is int32_t. For details, see [OH_TransferCharacteristic](#oh_transfercharacteristic).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE

```
const char* OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE
```

**Description**

Defines the pointer to the video encoding bit rate mode. The value type is int32_t. For details, see [OH_VideoEncodeBitrateMode](_video_encoder.md#oh_videoencodebitratemode).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_VIDEO_IS_HDR_VIVID

```
const char* OH_MD_KEY_VIDEO_IS_HDR_VIVID
```

**Description**

Defines the pointer to indicate whether it is HDR Vivid. The value type is Boolean.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 11


### OH_MD_KEY_WIDTH

```
const char* OH_MD_KEY_WIDTH
```

**Description**

Defines the pointer to the video width. The value type is uint32_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_MAX_INPUT_BUFFER_COUNT

```
const char* OH_MD_MAX_INPUT_BUFFER_COUNT
```

**Description**

Defines the pointer to the maximum number of input buffers. The value type is int32_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_MAX_OUTPUT_BUFFER_COUNT

```
const char* OH_MD_MAX_OUTPUT_BUFFER_COUNT
```

**Description**

Defines the pointer to the maximum number of output buffers. The value type is int32_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10
