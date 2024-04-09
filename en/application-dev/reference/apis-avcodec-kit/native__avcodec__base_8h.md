# native_avcodec_base.h


## Overview

The **native_avcodec_base.h** file declare the native APIs used for basic audio and video muxing, demuxing, encoding, and decoding.

**Library**: libnative_media_codecbase.so

**Since**: 9

**Related module**: [CodecBase](_codec_base.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) | Defines all the asynchronous callback function pointers of an **OH_AVCodec** instance.| 
| struct&nbsp;&nbsp;[OH_AVCodecCallback](_o_h___a_v_codec_callback.md) | Defines all the asynchronous callback function pointers of an **OH_AVCodec** instance.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef void(\* [OH_AVCodecOnError](_codec_base.md#oh_avcodeconerror)) (OH_AVCodec \*codec, int32_t errorCode, void \*userData) | Defines the pointer to the function that is called to report error information when an error occurs during the running of an **OH_AVCodec** instance.| 
| typedef void(\* [OH_AVCodecOnStreamChanged](_codec_base.md#oh_avcodeconstreamchanged)) (OH_AVCodec \*codec, OH_AVFormat \*format, void \*userData) | Defines the pointer to the function that is called to report the new stream description when the output stream changes.| 
| typedef void(\* [OH_AVCodecOnNeedInputData](_codec_base.md#oh_avcodeconneedinputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, void \*userData) | Defines the pointer to the function that is called when new input data is required during the running of an **OH_AVCodec** instance. The function carries a buffer to fill in new input data.| 
| typedef void(\* [OH_AVCodecOnNewOutputData](_codec_base.md#oh_avcodeconnewoutputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr, void \*userData) | Defines the pointer to the function that is called when new output data is generated during the running of an **OH_AVCodec** instance. The function carries a buffer filled with new output data.| 
| typedef void(\* [OH_AVCodecOnNeedInputBuffer](_codec_base.md#oh_avcodeconneedinputbuffer)) (OH_AVCodec \*codec, uint32_t index, OH_AVBuffer \*buffer, void \*userData) | Defines the pointer to the function that is called when new input data is required during the running of an **OH_AVCodec** instance. The function carries a buffer to fill in new input data.| 
| typedef void(\* [OH_AVCodecOnNewOutputBuffer](_codec_base.md#oh_avcodeconnewoutputbuffer)) (OH_AVCodec \*codec, uint32_t index, OH_AVBuffer \*buffer, void \*userData) | Defines the pointer to the function that is called when new output data is generated during the running of an **OH_AVCodec** instance. The function carries a buffer filled with new output data.| 
| typedef struct [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) [OH_AVCodecAsyncCallback](_codec_base.md#oh_avcodecasynccallback) | Defines all the asynchronous callback function pointers of an **OH_AVCodec** instance.| 
| typedef struct [OH_AVCodecCallback](_o_h___a_v_codec_callback.md) [OH_AVCodecCallback](_codec_base.md#oh_avcodeccallback) | Defines all the asynchronous callback function pointers of an **OH_AVCodec** instance.| 
| typedef enum [OH_MediaType](_codec_base.md#oh_mediatype-1) [OH_MediaType](_codec_base.md#oh_mediatype) | Defines an enum that enumerates the media types.| 
| typedef enum [OH_AACProfile](_codec_base.md#oh_aacprofile-1) [OH_AACProfile](_codec_base.md#oh_aacprofile) | Defines an enum that enumerates the AAC profiles.| 
| typedef enum [OH_AVCProfile](_codec_base.md#oh_avcprofile-1) [OH_AVCProfile](_codec_base.md#oh_avcprofile) | Defines an enum that enumerates the AVC profiles.| 
| typedef enum [OH_HEVCProfile](_codec_base.md#oh_hevcprofile-1) [OH_HEVCProfile](_codec_base.md#oh_hevcprofile) | Defines an enum that enumerates the HEVC profiles.| 
| typedef enum [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat-1) [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat) | Defines an enum that enumerates the output file formats of a muxer.| 
| typedef enum [OH_AVSeekMode](_codec_base.md#oh_avseekmode-1) [OH_AVSeekMode](_codec_base.md#oh_avseekmode) | Defines an enum that enumerates the seek modes.| 
| typedef enum [OH_ScalingMode](_codec_base.md#oh_scalingmode-1) [OH_ScalingMode](_codec_base.md#oh_scalingmode) | Defines an enum that enumerates the scaling modes.| 
| typedef enum [OH_BitsPerSample](_codec_base.md#oh_bitspersample-1) [OH_BitsPerSample](_codec_base.md#oh_bitspersample) | Defines an enum that enumerates the number of audio bits for each coded sample.| 
| typedef enum [OH_ColorPrimary](_codec_base.md#oh_colorprimary-1) [OH_ColorPrimary](_codec_base.md#oh_colorprimary) | Defines an enum that enumerates the primary colors.| 
| typedef enum [OH_TransferCharacteristic](_codec_base.md#oh_transfercharacteristic-1) [OH_TransferCharacteristic](_codec_base.md#oh_transfercharacteristic) | Defines an enum that enumerates the transfer characteristics.| 
| typedef enum [OH_MatrixCoefficient](_codec_base.md#oh_matrixcoefficient-1) [OH_MatrixCoefficient](_codec_base.md#oh_matrixcoefficient) | Defines an enum that enumerates the matrix coefficients.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_MediaType](_codec_base.md#oh_mediatype-1) {<br>MEDIA_TYPE_AUD = 0,<br>MEDIA_TYPE_VID = 1<br>} | Enumerates the media types.| 
| [OH_AACProfile](_codec_base.md#oh_aacprofile-1) { AAC_PROFILE_LC = 0 } | Enumerates the AAC profiles.| 
| [OH_AVCProfile](_codec_base.md#oh_avcprofile-1) {<br>AVC_PROFILE_BASELINE = 0,<br>AVC_PROFILE_HIGH = 4,<br>AVC_PROFILE_MAIN = 8<br>} | Enumerates the AVC profiles.| 
| [OH_HEVCProfile](_codec_base.md#oh_hevcprofile-1) {<br>HEVC_PROFILE_MAIN = 0,<br>HEVC_PROFILE_MAIN_10 = 1,<br>HEVC_PROFILE_MAIN_STILL = 2,<br>HEVC_PROFILE_MAIN_10_HDR10 = 3,<br>HEVC_PROFILE_MAIN_10_HDR10_PLUS = 4<br>} | Enumerates the HEVC profiles.| 
| [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat-1) {<br>AV_OUTPUT_FORMAT_DEFAULT = 0,<br>AV_OUTPUT_FORMAT_MPEG_4 = 2,<br>AV_OUTPUT_FORMAT_M4A = 6<br>} | Enumerates the output file formats of a muxer.| 
| [OH_AVSeekMode](_codec_base.md#oh_avseekmode-1) {<br>SEEK_MODE_NEXT_SYNC = 0,<br>SEEK_MODE_PREVIOUS_SYNC,<br>SEEK_MODE_CLOSEST_SYNC<br>} | Enumerates the seek modes.| 
| [OH_ScalingMode](_codec_base.md#oh_scalingmode-1) {<br>SCALING_MODE_SCALE_TO_WINDOW = 1,<br>SCALING_MODE_SCALE_CROP = 2<br>} | Enumerates the scaling modes.| 
| [OH_BitsPerSample](_codec_base.md#oh_bitspersample-1) {<br>SAMPLE_U8 = 0, SAMPLE_S16LE = 1,<br>SAMPLE_S24LE = 2, SAMPLE_S32LE = 3,<br>SAMPLE_F32LE = 4, SAMPLE_U8P = 5,<br>SAMPLE_S16P = 6, SAMPLE_S24P = 7,<br>SAMPLE_S32P = 8, SAMPLE_F32P = 9,<br>INVALID_WIDTH = -1<br>} | Enumerates the number of audio bits for each coded sample.| 
| [OH_ColorPrimary](_codec_base.md#oh_colorprimary-1) {<br>COLOR_PRIMARY_BT709 = 1,<br>COLOR_PRIMARY_UNSPECIFIED = 2,<br>COLOR_PRIMARY_BT470_M = 4,<br>COLOR_PRIMARY_BT601_625 = 5,<br>COLOR_PRIMARY_BT601_525 = 6,<br>COLOR_PRIMARY_SMPTE_ST240 = 7,<br>COLOR_PRIMARY_GENERIC_FILM = 8,<br>COLOR_PRIMARY_BT2020 = 9,<br>COLOR_PRIMARY_SMPTE_ST428 = 10,<br>COLOR_PRIMARY_P3DCI = 11,<br>COLOR_PRIMARY_P3D65 = 12<br>} | Enumerates the primary colors.| 
| [OH_TransferCharacteristic](_codec_base.md#oh_transfercharacteristic-1) {<br>TRANSFER_CHARACTERISTIC_BT709 = 1,<br>TRANSFER_CHARACTERISTIC_UNSPECIFIED = 2,<br>TRANSFER_CHARACTERISTIC_GAMMA_2_2 = 4,<br>TRANSFER_CHARACTERISTIC_GAMMA_2_8 = 5,<br>TRANSFER_CHARACTERISTIC_BT601 = 6,<br>TRANSFER_CHARACTERISTIC_SMPTE_ST240 = 7,<br>TRANSFER_CHARACTERISTIC_LINEAR = 8,<br>TRANSFER_CHARACTERISTIC_LOG = 9,<br>TRANSFER_CHARACTERISTIC_LOG_SQRT = 10,<br>TRANSFER_CHARACTERISTIC_IEC_61966_2_4 = 11,<br>TRANSFER_CHARACTERISTIC_BT1361 = 12,<br>TRANSFER_CHARACTERISTIC_IEC_61966_2_1 = 13,<br>TRANSFER_CHARACTERISTIC_BT2020_10BIT = 14,<br>TRANSFER_CHARACTERISTIC_BT2020_12BIT = 15,<br>TRANSFER_CHARACTERISTIC_PQ = 16,<br>TRANSFER_CHARACTERISTIC_SMPTE_ST428 = 17,<br>TRANSFER_CHARACTERISTIC_HLG = 18<br>} | Enumerates the transfer characteristics.| 
| [OH_MatrixCoefficient](_codec_base.md#oh_matrixcoefficient-1) {<br>MATRIX_COEFFICIENT_IDENTITY = 0,<br>MATRIX_COEFFICIENT_BT709 = 1,<br>MATRIX_COEFFICIENT_UNSPECIFIED = 2,<br>MATRIX_COEFFICIENT_FCC = 4,<br>MATRIX_COEFFICIENT_BT601_625 = 5,<br>MATRIX_COEFFICIENT_BT601_525 = 6, MATRIX_COEFFICIENT_SMPTE_ST240 = 7,<br>MATRIX_COEFFICIENT_YCGCO = 8,<br>MATRIX_COEFFICIENT_BT2020_NCL = 9,<br>MATRIX_COEFFICIENT_BT2020_CL = 10,<br>MATRIX_COEFFICIENT_SMPTE_ST2085 = 11,<br>MATRIX_COEFFICIENT_CHROMATICITY_NCL = 12,<br>MATRIX_COEFFICIENT_CHROMATICITY_CL = 13,<br>MATRIX_COEFFICIENT_ICTCP = 14<br>} | Enumerates the matrix coefficients.| 


### Variables

| Name| Description| 
| -------- | -------- |
| const char \* [OH_AVCODEC_MIMETYPE_VIDEO_AVC](_codec_base.md#oh_avcodec_mimetype_video_avc) | Defines the pointer to the Multipurpose Internet Mail Extension (MIME) type of AVC (H.264) video codec.| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_AAC](_codec_base.md#oh_avcodec_mimetype_audio_aac) | Defines the pointer to the MIME type for AAC audio codec.| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_FLAC](_codec_base.md#oh_avcodec_mimetype_audio_flac) | Defines the pointer to the MIME type for FLAC audio codec.| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_VORBIS](_codec_base.md#oh_avcodec_mimetype_audio_vorbis) | Defines the pointer to the MIME type of Vorbis audio decoder.| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_MPEG](_codec_base.md#oh_avcodec_mimetype_audio_mpeg) | Defines the pointer to the MIME type of MP3 audio decoder.| 
| const char \* [OH_AVCODEC_MIMETYPE_VIDEO_HEVC](_codec_base.md#oh_avcodec_mimetype_video_hevc) | Defines the pointer to the MIME type of HEVC (H.265) video codec.| 
| const char \* [OH_AVCODEC_MIMETYPE_VIDEO_MPEG4](_codec_base.md#oh_avcodec_mimetype_video_mpeg4) | Defines the pointer to the MIME type of MPEG4 video encoder, which is used only for muxing MPEG4 video streams.| 
| const char \* [OH_AVCODEC_MIMETYPE_IMAGE_JPG](_codec_base.md#oh_avcodec_mimetype_image_jpg) | Defines the pointer to the MIME type of JPG image encoder, which is used only for muxing JPG covers.| 
| const char \* [OH_AVCODEC_MIMETYPE_IMAGE_PNG](_codec_base.md#oh_avcodec_mimetype_image_png) | Defines the pointer to the MIME type of PNG image encoder, which is used only for muxing PNG covers.| 
| const char \* [OH_AVCODEC_MIMETYPE_IMAGE_BMP](_codec_base.md#oh_avcodec_mimetype_image_bmp) | Defines the pointer to the MIME type of BMP image encoder, which is used only for muxing BMP covers.| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_VIVID](_codec_base.md#oh_avcodec_mimetype_audio_vivid) | Defines the pointer to the MIME type of Audio Vivid audio decoder. (This specification is not available yet.)| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_AMR_NB](_codec_base.md#oh_avcodec_mimetype_audio_amr_nb) | Defines the pointer to the MIME type of AMR-NB audio decoder.| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_AMR_WB](_codec_base.md#oh_avcodec_mimetype_audio_amr_wb) | Defines the pointer to the MIME type of AMR-WB audio decoder.| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_OPUS](_codec_base.md#oh_avcodec_mimetype_audio_opus) | Defines the pointer to the MIME type of Opus audio codec. (This specification is not available yet.)| 
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_G711MU](_codec_base.md#oh_avcodec_mimetype_audio_g711mu) | Defines the pointer to the MIME type of G.711 mu-law audio codec.| 
| const char \* [OH_ED_KEY_TIME_STAMP](_codec_base.md#oh_ed_key_time_stamp) | Defines the pointer to the timestamp in the extra data of the surface. The value type is int64.| 
| const char \* [OH_ED_KEY_EOS](_codec_base.md#oh_ed_key_eos) | Defines the pointer to the end of stream (EOS) in the extra data of the surface. The value type is Boolean.| 
| const char \* [OH_MD_KEY_TRACK_TYPE](_codec_base.md#oh_md_key_track_type) | Defines the pointer to the track type. The value type is uint8_t. For details, see [OH_MediaType](_codec_base.md#oh_mediatype).| 
| const char \* [OH_MD_KEY_CODEC_MIME](_codec_base.md#oh_md_key_codec_mime) | Define the pointer to the MIME type of codec. The value type is string.| 
| const char \* [OH_MD_KEY_DURATION](_codec_base.md#oh_md_key_duration) | Defines the pointer to the duration. The value type is int64_t.| 
| const char \* [OH_MD_KEY_BITRATE](_codec_base.md#oh_md_key_bitrate) | Defines the pointer to the bit rate. The value type is int64_t.| 
| const char \* [OH_MD_KEY_MAX_INPUT_SIZE](_codec_base.md#oh_md_key_max_input_size) | Defines the pointer to the maximum input size. The value type is uint32_t.| 
| const char \* [OH_MD_KEY_WIDTH](_codec_base.md#oh_md_key_width) | Defines the pointer to the video width. The value type is uint32_t.| 
| const char \* [OH_MD_KEY_HEIGHT](_codec_base.md#oh_md_key_height) | Defines the pointer to the video height. The value type is uint32_t.| 
| const char \* [OH_MD_KEY_PIXEL_FORMAT](_codec_base.md#oh_md_key_pixel_format) | Defines the pointer to the video pixel format. The value type is int32_t. For details, see [OH_AVPixelFormat](_core.md#oh_avpixelformat).| 
| const char \* [OH_MD_KEY_AUDIO_SAMPLE_FORMAT](_codec_base.md#oh_md_key_audio_sample_format) | Defines the pointer to the original audio format. The value type is uint32_t. For details, see **AudioSampleFormat**.| 
| const char \* [OH_MD_KEY_FRAME_RATE](_codec_base.md#oh_md_key_frame_rate) | Defines the pointer to the video frame rate. The value type is double.| 
| const char \* [OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE](_codec_base.md#oh_md_key_video_encode_bitrate_mode) | Defines the pointer to the video encoding bit rate mode. The value type is int32_t. For details, see [OH_VideoEncodeBitrateMode](_video_encoder.md#oh_videoencodebitratemode).| 
| const char \* [OH_MD_KEY_PROFILE](_codec_base.md#oh_md_key_profile) | Defines the pointer to the encoding grading. The value type is int32_t. For details, see [OH_HEVCProfile](_codec_base.md#oh_hevcprofile) and [OH_AACProfile](_codec_base.md#oh_aacprofile).| 
| const char \* [OH_MD_KEY_AUD_CHANNEL_COUNT](_codec_base.md#oh_md_key_aud_channel_count) | Defines the pointer to the number of audio channels. The value type is uint32_t.| 
| const char \* [OH_MD_KEY_AUD_SAMPLE_RATE](_codec_base.md#oh_md_key_aud_sample_rate) | Defines the pointer to the audio sampling rate. The value type is uint32_t.| 
| const char \* [OH_MD_KEY_I_FRAME_INTERVAL](_codec_base.md#oh_md_key_i_frame_interval) | Defines the pointer to the key frame interval, in milliseconds. The value type is int32_t.| 
| const char \* [OH_MD_KEY_ROTATION](_codec_base.md#oh_md_key_rotation) | Defines the pointer to the rotation angle of the surface. The value type is int32_t, and the value range is {0, 90, 180, 270}. The default value is 0.| 
| const char \* [OH_MD_KEY_RANGE_FLAG](_codec_base.md#oh_md_key_range_flag) | Defines the pointer to the video YUV value range flag. The value type is Boolean. The value **true** means a full range, and **false** means a limited range.| 
| const char \* [OH_MD_KEY_COLOR_PRIMARIES](_codec_base.md#oh_md_key_color_primaries) | Defines the pointer to the video primary color. The value type is int32_t. For details, see [OH_ColorPrimary](_codec_base.md#oh_colorprimary). The video primary color complies with Table 2 in the H.273 standard.| 
| const char \* [OH_MD_KEY_TRANSFER_CHARACTERISTICS](_codec_base.md#oh_md_key_transfer_characteristics) | Defines the pointer to the video transfer characteristics. The value type is int32_t. For details, see [OH_TransferCharacteristic](_codec_base.md#oh_transfercharacteristic). The video transfer characteristics comply with Table 3 in the H.273 standard.| 
| const char \* [OH_MD_KEY_MATRIX_COEFFICIENTS](_codec_base.md#oh_md_key_matrix_coefficients) | Defines the pointer to the video matrix coefficient. The value type is int32_t. For details, see [OH_MatrixCoefficient](_codec_base.md#oh_matrixcoefficient). The video matrix coefficient complies with Table 4 in the H.273 standard.| 
| const char \* [OH_MD_KEY_REQUEST_I_FRAME](_codec_base.md#oh_md_key_request_i_frame) | Defines the pointer to the request for immediate encoding of I-frames. The value type is Boolean.| 
| const char \* [OH_MD_KEY_QUALITY](_codec_base.md#oh_md_key_quality) | Defines the pointer to the required encoding quality. The value type is uint32_t. This key applies only to encoders configured in constant quality mode.| 
| const char \* [OH_MD_KEY_CODEC_CONFIG](_codec_base.md#oh_md_key_codec_config) | Defines the pointer to the codec-specific data. The value type is uint8_t\*.| 
| const char \* [OH_MD_KEY_TITLE](_codec_base.md#oh_md_key_title) | Defines the pointer to the title of the input media. The value type is string.| 
| const char \* [OH_MD_KEY_ARTIST](_codec_base.md#oh_md_key_artist) | Defines the pointer to the artist of the input media. The value type is string.| 
| const char \* [OH_MD_KEY_ALBUM](_codec_base.md#oh_md_key_album) | Defines the pointer to the album of the input media. The value type is string.| 
| const char \* [OH_MD_KEY_ALBUM_ARTIST](_codec_base.md#oh_md_key_album_artist) | Defines the pointer to the album artist of the input media. The value type is string.| 
| const char \* [OH_MD_KEY_DATE](_codec_base.md#oh_md_key_date) | Defines the pointer to the date of the input media. The value type is string.| 
| const char \* [OH_MD_KEY_COMMENT](_codec_base.md#oh_md_key_comment) | Defines the pointer to the comment of the input media. The value type is string.| 
| const char \* [OH_MD_KEY_GENRE](_codec_base.md#oh_md_key_genre) | Defines the pointer to the genre of the input media. The value type is string.| 
| const char \* [OH_MD_KEY_COPYRIGHT](_codec_base.md#oh_md_key_copyright) | Defines the pointer to the copyright of the input media. The value type is string.| 
| const char \* [OH_MD_KEY_LANGUAGE](_codec_base.md#oh_md_key_language) | Defines the pointer to the language of the input media. The value type is string.| 
| const char \* [OH_MD_KEY_DESCRIPTION](_codec_base.md#oh_md_key_description) | Defines the pointer to the description of the input media. The value type is string.| 
| const char \* [OH_MD_KEY_LYRICS](_codec_base.md#oh_md_key_lyrics) | Defines the pointer to the lyrics of the input media. The value type is string.| 
| const char \* [OH_MD_KEY_TRACK_COUNT](_codec_base.md#oh_md_key_track_count) | Defines the pointer to the track count of the input media. The value type is uint32_t.| 
| const char \* [OH_MD_KEY_CHANNEL_LAYOUT](_codec_base.md#oh_md_key_channel_layout) | Defines the pointer to the required encoding channel layout. The value type is int64_t. This key applies only to encoders.| 
| const char \* [OH_MD_KEY_BITS_PER_CODED_SAMPLE](_codec_base.md#oh_md_key_bits_per_coded_sample) | Defines the pointer to the number of bits for each coded sample. The value type is uint32_t. This key applies to FLAC encoders. For details, see [OH_BitsPerSample](_codec_base.md#oh_bitspersample).| 
| const char \* [OH_MD_KEY_AAC_IS_ADTS](_codec_base.md#oh_md_key_aac_is_adts) | Defines the pointer to the AAC format. The value type is uint32_t. This key applies to AAC decoders.| 
| const char \* [OH_MD_KEY_SBR](_codec_base.md#oh_md_key_sbr) | Defines the pointer to the AAC SBR format. The value type is uint32_t. This key applies to AAC encoders.| 
| const char \* [OH_MD_KEY_COMPLIANCE_LEVEL](_codec_base.md#oh_md_key_compliance_level) | Defines the pointer to the FLAC compliance level. The value type is int32_t.| 
| const char \* [OH_MD_KEY_IDENTIFICATION_HEADER](_codec_base.md#oh_md_key_identification_header) | Defines the pointer to the VORBIS identification header. The value type is uint8_t\*. This key applies only to VORBIS decoders.| 
| const char \* [OH_MD_KEY_SETUP_HEADER](_codec_base.md#oh_md_key_setup_header) | Defines the pointer to the VORBIS setup header. The value type is uint8_t\*. This key applies only to VORBIS decoders.| 
| const char \* [OH_MD_KEY_SCALING_MODE](_codec_base.md#oh_md_key_scaling_mode) | Defines the pointer to the video surface scale mode. The value type is int32_t. For details, see [OH_ScalingMode](_codec_base.md#oh_scalingmode).| 
| const char \* [OH_MD_MAX_INPUT_BUFFER_COUNT](_codec_base.md#oh_md_max_input_buffer_count) | Defines the pointer to the maximum number of input buffers. The value type is int32_t.| 
| const char \* [OH_MD_MAX_OUTPUT_BUFFER_COUNT](_codec_base.md#oh_md_max_output_buffer_count) | Defines the pointer to the maximum number of output buffers. The value type is int32_t.| 
| const char \* [OH_MD_KEY_AUDIO_COMPRESSION_LEVEL](_codec_base.md#oh_md_key_audio_compression_level) | Defines the pointer to the audio codec compression level. The value type is uint32_t.| 
| const char \* [OH_MD_KEY_VIDEO_IS_HDR_VIVID](_codec_base.md#oh_md_key_video_is_hdr_vivid) | Defines the pointer to indicate whether it is HDR Vivid. The value type is Boolean.| 
| const char \* [OH_MD_KEY_AUDIO_OBJECT_NUMBER](_codec_base.md#oh_md_key_audio_object_number) | Defines the pointer to the number of audio objects. The value type is int32_t.| 
| const char \* [OH_MD_KEY_AUDIO_VIVID_METADATA](_codec_base.md#oh_md_key_audio_vivid_metadata) | Defines the pointer to the Audio Vivid metadata. The value type is uint8_t.| 
