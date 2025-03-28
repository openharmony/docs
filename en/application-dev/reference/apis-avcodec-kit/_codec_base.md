# CodecBase


## Overview

The CodecBase module provides the variables, attributes, and functions for basic audio and video muxing, demuxing, encoding, and decoding.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

### Media Codec Formats

The table below lists the media codec formats. The type is a constant string.

| Name                                                        | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------ |
| [OH_AVCODEC_MIMETYPE_AUDIO_AAC](#oh_avcodec_mimetype_audio_aac) | MIME type of the AAC audio codec.                           |
| [OH_AVCODEC_MIMETYPE_AUDIO_FLAC](#oh_avcodec_mimetype_audio_flac) | MIME type of the Free Lossless Audio Codec (FLAC) audio codec.                          |
| [OH_AVCODEC_MIMETYPE_AUDIO_OPUS](#oh_avcodec_mimetype_audio_opus) | MIME type of the Opus audio codec. <!--Del-->(This specification is not available yet.)<!--DelEnd-->        |
| [OH_AVCODEC_MIMETYPE_AUDIO_G711MU](#oh_avcodec_mimetype_audio_g711mu) | MIME type of the G.711 mu-law audio codec.                        |
| [OH_AVCODEC_MIMETYPE_AUDIO_RAW](#oh_avcodec_mimetype_audio_raw) | MIME type of raw audio streams.                        |
| [OH_AVCODEC_MIMETYPE_AUDIO_VORBIS](#oh_avcodec_mimetype_audio_vorbis) | MIME type of the Vorbis audio decoder.                          |
| [OH_AVCODEC_MIMETYPE_AUDIO_MPEG](#oh_avcodec_mimetype_audio_mpeg) | MIME type of the MP3 audio decoder.                             |
| [OH_AVCODEC_MIMETYPE_AUDIO_VIVID](#oh_avcodec_mimetype_audio_vivid) | MIME type of the Audio Vivid audio decoder. <!--Del-->(This specification is not available yet.)<!--DelEnd-->     |
| [OH_AVCODEC_MIMETYPE_AUDIO_AMR_NB](#oh_avcodec_mimetype_audio_amr_nb) | MIME type of the AMR-NB audio decoder.                          |
| [OH_AVCODEC_MIMETYPE_AUDIO_AMR_WB](#oh_avcodec_mimetype_audio_amr_wb) | MIME type of the AMR-WB audio decoder.                          |
| [OH_AVCODEC_MIMETYPE_AUDIO_APE](#oh_avcodec_mimetype_audio_ape) |MIME type of the APE audio decoder.                        |
| [OH_AVCODEC_MIMETYPE_VIDEO_VVC](#oh_avcodec_mimetype_video_vvc) | MIME type of the VVC (H.266) video codec.                   |
| [OH_AVCODEC_MIMETYPE_VIDEO_HEVC](#oh_avcodec_mimetype_video_hevc) | MIME type of the HEVC (H.265) video codec.                   |
| [OH_AVCODEC_MIMETYPE_VIDEO_AVC](#oh_avcodec_mimetype_video_avc) | Multipurpose Internet Mail Extension (MIME) type of AVC (H.264) video codec.                    |
| [OH_AVCODEC_MIMETYPE_VIDEO_MPEG4](#oh_avcodec_mimetype_video_mpeg4) | MIME type of the MPEG4 video encoder, which is used only for muxing MPEG4 video streams. (This function is deprecated in API version 11.)|
| [OH_AVCODEC_MIMETYPE_VIDEO_MPEG4_PART2](#oh_avcodec_mimetype_video_mpeg4_part2) | MIME type of MPEG4 Part 2 video codec.|
| [OH_AVCODEC_MIMETYPE_VIDEO_MPEG2](#oh_avcodec_mimetype_video_mpeg2) | MIME type of MPEG2 video codec.|
| [OH_AVCODEC_MIMETYPE_IMAGE_JPG](#oh_avcodec_mimetype_image_jpg) | MIME type of the JPG image encoder, which is used only for muxing JPG covers.      |
| [OH_AVCODEC_MIMETYPE_IMAGE_PNG](#oh_avcodec_mimetype_image_png) | MIME type of the PNG image encoder, which is used only for muxing PNG covers.      |
| [OH_AVCODEC_MIMETYPE_IMAGE_BMP](#oh_avcodec_mimetype_image_bmp) | MIME type of the BMP image encoder, which is used only for muxing BMP covers.      |
| [OH_AVCODEC_MIMETYPE_SUBTITLE_WEBVTT](#oh_avcodec_mimetype_subtitle_webvtt) |MIME type of the WEBVTT subtitle demuxer.                        |
| [OH_AVCODEC_MIMETYPE_SUBTITLE_SRT](#oh_avcodec_mimetype_subtitle_srt) |MIME type of the SRT subtitle demuxer.                        |


### Media Data Key-Value Pairs

The table below lists the key-value pairs used to describe media data. The key type is a constant string, and the value type can be int32_t, int64_t, float, double, char *, or uint8_t *.

The [OH_AVFormat](_core.md#functions) API is used to configure or query parameters.

Key-value pairs dedicated for capability query:

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_FEATURE_PROPERTY_KEY_VIDEO_ENCODER_MAX_LTR_FRAME_COUNT](#oh_feature_property_key_video_encoder_max_ltr_frame_count)     | Maximum number of long-term reference (LTR) frames obtained during video encoding. The value type is int32_t.|

Common key-value pairs of audio and video:

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_MD_KEY_CODEC_CONFIG](#oh_md_key_codec_config)            | Codec-specific data. In the case of video, data carried in **SPS/PPS** is transferred. In the case of audio, data carried in **extraData** is transferred. The value type is uint8_t\*. This key is optional. <!--Del-->(This key is not supported yet for the video codec.)<!--DelEnd--> |
| [OH_MD_MAX_INPUT_BUFFER_COUNT](#oh_md_max_input_buffer_count) | Maximum number of input buffers. The value type is int32_t. This key is optional.     |
| [OH_MD_MAX_OUTPUT_BUFFER_COUNT](#oh_md_max_output_buffer_count) | Maximum number of output buffers. The value type is int32_t. This key is optional.       |
| [OH_MD_KEY_BITRATE](#oh_md_key_bitrate)                      | Bit rate. The value type is int64_t. This key is used in audio and video encoding scenarios. It is optional in video encoding scenarios.|
| [OH_MD_KEY_PROFILE](#oh_md_key_profile)                      | Encoding grading. The value type is int32_t. For details, see [OH_AVCProfile](#oh_avcprofile), [OH_HEVCProfile](#oh_hevcprofile), and [OH_AACProfile](#oh_aacprofile). This key is optional.|
| [OH_MD_KEY_MAX_INPUT_SIZE](#oh_md_key_max_input_size)        | Maximum size of an input stream to decode. The value type is int32_t. This key is optional.          |


The table below lists the video-dedicated key-value pairs.

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_ED_KEY_TIME_STAMP](#oh_ed_key_time_stamp)                | Surface buffer timestamp. The value is of the int64_t type. This key is optional. (This key is deprecated from API version 14.)|
| [OH_ED_KEY_EOS](#oh_ed_key_eos)                              | End of stream for the surface buffer. The value type is int32_t. This key is optional. (This key is deprecated from API version 14.)|
| [OH_MD_KEY_WIDTH](#oh_md_key_width)                          | Video width. The value type is int32_t.                            |
| [OH_MD_KEY_HEIGHT](#oh_md_key_height)                        | Video height. The value type is int32_t.                              |
| [OH_MD_KEY_PIXEL_FORMAT](#oh_md_key_pixel_format)            | Video pixel format. The value type is int32_t. For details, see [OH_AVPixelFormat](_core.md#oh_avpixelformat).|
| [OH_MD_KEY_FRAME_RATE](#oh_md_key_frame_rate)                | Video frame rate. The value type is double. This key is optional.                |
| [OH_MD_KEY_RANGE_FLAG](#oh_md_key_range_flag)                | Video YUV value range flag. The value type is int32_t. The value **1** means a full range, and **0** means a limited range. This key is optional.|
| [OH_MD_KEY_COLOR_PRIMARIES](#oh_md_key_color_primaries)      | Video primary color. The value type is int32_t. For details, see [OH_ColorPrimary](#oh_colorprimary). The video primary color complies with Table 2 in the H.273 standard. This key is optional.|
| [OH_MD_KEY_TRANSFER_CHARACTERISTICS](#oh_md_key_transfer_characteristics) | Video transfer characteristics. The value type is int32_t. For details, see [OH_TransferCharacteristic](#oh_transfercharacteristic). The video transfer characteristics comply with Table 3 in the H.273 standard. This key is optional.|
| [OH_MD_KEY_MATRIX_COEFFICIENTS](#oh_md_key_matrix_coefficients) | Video matrix coefficient. The value type is int32_t. For details, see [OH_MatrixCoefficient](#oh_matrixcoefficient). The video matrix coefficient complies with Table 4 in the H.273 standard. This key is optional.|
| [OH_MD_KEY_VIDEO_STRIDE](#oh_md_key_video_stride)       | Stride of the video frame. The value type is int32_t. This key is optional.       |
| [OH_MD_KEY_VIDEO_SLICE_HEIGHT](#oh_md_key_video_slice_height)    | Height of the video frame. The value type is int32_t. This key is optional.       |
| [OH_MD_KEY_VIDEO_PIC_WIDTH](#oh_md_key_video_pic_width)       | Width of the video frame. The value type is int32_t. This key is optional.       |
| [OH_MD_KEY_VIDEO_PIC_HEIGHT](#oh_md_key_video_pic_height)    | Height of the video frame. The value type is int32_t. This key is optional.       |
| [OH_MD_KEY_VIDEO_ENABLE_LOW_LATENCY](#oh_md_key_video_enable_low_latency)   | Enabled status of low-latency video codec. The value type is int32_t. The value **1** means that low-latency video codec is enabled, and **0** means the opposite. This key is optional and used only in the configuration phase.|
| [OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE](#oh_md_key_video_encode_bitrate_mode) | Video encoding bit rate mode. The value type is int32_t. For details, see [OH_BitrateMode](#oh_bitratemode-1). This key is optional.|
| [OH_MD_KEY_QUALITY](#oh_md_key_quality)                      | Required encoding quality. The value type is int32_t. This key applies only to encoders configured in constant quality mode. This key is optional.|
| [OH_MD_KEY_REQUEST_I_FRAME](#oh_md_key_request_i_frame)      | Request for immediate encoding of I-frames. The value type is int32_t. This key is optional.           |
| [OH_MD_KEY_I_FRAME_INTERVAL](#oh_md_key_i_frame_interval)    | Key frame interval, in milliseconds. The value type is int32_t. This key is optional and is used only for video encoding.|
| [OH_MD_KEY_VIDEO_ENCODER_ENABLE_TEMPORAL_SCALABILITY](#oh_md_key_video_encoder_enable_temporal_scalability)          | Enabled status of temporal scalability. The value type is int32_t. The value **1** means temporal scalability is enabled, and **0** means the opposite. This key is optional and used only in the configuration phase of video encoding.|
| [OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_SIZE](#oh_md_key_video_encoder_temporal_gop_size)       | Size of a temporal image group. The value type is int32_t. This key is valid only when temporal scalability is enabled. This key is optional and used only in the configuration phase of video encoding.|
| [OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_REFERENCE_MODE](#oh_md_key_video_encoder_temporal_gop_reference_mode)         | Reference mode in a temporal image group. The value type is int32_t. For details, see [OH_TemporalGopReferenceMode](#oh_temporalgopreferencemode-1). This key is valid only when temporal scalability is enabled. This key is optional and used only in the configuration phase of video encoding.|
| [OH_MD_KEY_VIDEO_ENCODER_LTR_FRAME_COUNT](#oh_md_key_video_encoder_ltr_frame_count)        | Number of LTR frames. The value type is int32_t. The value must be within the supported value range. This key is optional and is used only for video encoding.|
| [OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_MARK_LTR](#oh_md_key_video_encoder_per_frame_mark_ltr)  | Whether the current frame is marked as an LTR frame. The value type is int32_t. The value **1** means that the frame is marked as an LTR frame, and **0** means the opposite. This key is optional and is used only for video encoding.|
| [OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_USE_LTR](#oh_md_key_video_encoder_per_frame_use_ltr)    | 	POC number of the LTR frame referenced by the current frame. The value type is int32_t. This key is optional and is used only for video encoding.|
| [OH_MD_KEY_VIDEO_PER_FRAME_IS_LTR](#oh_md_key_video_per_frame_is_ltr)      | Whether the frame corresponding to the stream output from the current [OH_AVBuffer](_core.md#oh_avbuffer) is marked as an LTR frame. The value type is int32_t. The value **1** means that the frame is an LTR frame, and **0** means the opposite. This key is optional and is used only for video encoding.|
| [OH_MD_KEY_VIDEO_PER_FRAME_POC](#oh_md_key_video_per_frame_poc)            | POC number of the frame. The value type is int32_t. This key is optional and is used only for video encoding.|
| [OH_MD_KEY_VIDEO_ENCODER_QP_MAX](#oh_md_key_video_encoder_qp_max)       | Maximum Quantization Parameter (QP) allowed by the video encoder. The value type is int32_t. This key is optional and is used only for video encoding.|
| [OH_MD_KEY_VIDEO_ENCODER_QP_MIN](#oh_md_key_video_encoder_qp_min)      | Minimum QP allowed by the video encoder. The value type is int32_t. This key is optional and is used only for video encoding.|
| [OH_MD_KEY_VIDEO_ENCODER_QP_AVERAGE](#oh_md_key_video_encoder_qp_average)     |Average QP of video frames. The value type is int32_t. This key is optional and is used only for video encoding. |
| [OH_MD_KEY_VIDEO_ENCODER_MSE](#oh_md_key_video_encoder_mse)     |Mean Squared Error (MSE) of video frames. The value type is double. This key is optional and is used only for video encoding. |
| [OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER](#oh_md_key_video_encoder_repeat_previous_frame_after)         | Duration (in milliseconds) for which the last frame will be resubmitted repeatedly, if no new frame is available after the previous frame is submitted to the encoder. The value type is int32_t. This key is used only in the configuration phase of video encoding in surface mode.|
| [OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_MAX_COUNT](#oh_md_key_video_encoder_repeat_previous_max_count)         | Maximum number of times the encoder can repeat encoding the previous frame when no new frame is available. The value type is int32_t. This key takes effect only when **OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER** is available and is used only in the configuration phase.|
| [OH_MD_KEY_VIDEO_DECODER_OUTPUT_COLOR_SPACE](#oh_md_key_video_decoder_output_color_space)    | Output color space of the video decoder. The value type is int32_t. The supported value is **OH_COLORSPACE_BT709_LIMIT**.|
| [OH_MD_KEY_ROTATION](#oh_md_key_rotation)                    | Rotation angle of the surface. The value type is int32_t, and the value range is {0, 90, 180, 270}. The default value is 0. This key is optional and is used only for video decoding in surface mode  |
| [OH_MD_KEY_SCALING_MODE](#oh_md_key_scaling_mode)            | Video scaling mode. The value type is int32_t. For details, see [OH_ScalingMode](#oh_scalingmode). This key is optional and is used only for video decoding in surface mode. You are advised to set the scaling mode by calling [OH_NativeWindow_NativeWindowSetScalingModeV2](../apis-arkgraphics2d/_native_window.md#oh_nativewindow_nativewindowsetscalingmodev2). (This key is deprecated from API version 14.)|
| [OH_MD_KEY_VIDEO_CROP_TOP](#oh_md_key_video_crop_top)       | Top coordinate (y) of the cropped rectangle. The value type is int32_t. This key is optional and is used only for video decoding.|
| [OH_MD_KEY_VIDEO_CROP_BOTTOM](#oh_md_key_video_crop_bottom)        | Bottom coordinate (y) of the cropped rectangle. The value type is int32_t. This key is optional and is used only for video decoding.|
| [OH_MD_KEY_VIDEO_CROP_LEFT](#oh_md_key_video_crop_left)     | Left coordinate (x) of the cropped rectangle. The value type is int32_t. This key is optional and is used only for video decoding.|
| [OH_MD_KEY_VIDEO_CROP_RIGHT](#oh_md_key_video_crop_right)     | Right coordinate (x) of the cropped rectangle. The value type is int32_t. This key is optional and is used only for video decoding.|
| [OH_MD_KEY_VIDEO_DECODER_OUTPUT_ENABLE_VRR](#oh_md_key_video_decoder_output_enable_vrr)     | Whether the decoder enables the video variable frame rate feature. The value type is int32_t. This key is optional and is used only for video decoding.|

The table below lists the audio-dedicated key-value pairs.

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_MD_KEY_AUDIO_SAMPLE_FORMAT](#oh_md_key_audio_sample_format) | Original audio format. The value type is int32_t. For details, see [OH_BitsPerSample](#oh_bitspersample-1).|
| [OH_MD_KEY_AUD_CHANNEL_COUNT](#oh_md_key_aud_channel_count)  | Number of audio channels. The value type is int32_t.                          |
| [OH_MD_KEY_AUD_SAMPLE_RATE](#oh_md_key_aud_sample_rate)      | Audio sampling rate. The value type is int32_t.                            |
| [OH_MD_KEY_AUDIO_COMPRESSION_LEVEL](#oh_md_key_audio_compression_level) | Audio codec compression level. The value type is int32_t type. This key is used only for audio encoding. This key is optional.    |
| [OH_MD_KEY_CHANNEL_LAYOUT](#oh_md_key_channel_layout)        | Required encoding channel layout. The value type is int64_t. This key applies only to encoders. For details, see [OH_AudioChannelLayout](_core.md#oh_audiochannellayout-1). |
| [OH_MD_KEY_BITS_PER_CODED_SAMPLE](#oh_md_key_bits_per_coded_sample) | Number of bits for each coded sample. The value type is int32_t. This key applies to FLAC encoders. For details, see [OH_BitsPerSample](#oh_bitspersample-1). This key is optional.|
| [OH_MD_KEY_SBR](#oh_md_key_sbr)                              | AAC SBR format. The value type is int32_t. This key applies to AAC encoders. This key is optional.|
| [OH_MD_KEY_COMPLIANCE_LEVEL](#oh_md_key_compliance_level)    | FLAC compliance level. The value type is int32_t. This key is used only for audio encoding. This key is optional.         |
| [OH_MD_KEY_AAC_IS_ADTS](#oh_md_key_aac_is_adts)              | AAC format, which can be ADTS or LATM. The value type is int32_t. This key applies to AAC decoders. This key is optional. |
| [OH_MD_KEY_IDENTIFICATION_HEADER](#oh_md_key_identification_header) | Vorbis identification header. The value type is uint8_t\*. This key applies only to Vorbis decoders. This key is optional.|
| [OH_MD_KEY_SETUP_HEADER](#oh_md_key_setup_header)            | Vorbis setup header. The value type is uint8_t\*. This key applies only to Vorbis decoders. This key is optional.|
| [OH_MD_KEY_AUDIO_OBJECT_NUMBER](#oh_md_key_audio_object_number) | Number of audio objects. The value type is int32_t. This key is used only for Audio Vivid decoding. This key is optional.           |
| [OH_MD_KEY_AUDIO_VIVID_METADATA](#oh_md_key_audio_vivid_metadata) | Audio Vivid metadata. The value type is uint8_t\*. This key is used only for Audio Vivid decoding. This key is optional.    |

The table below lists the key-value pairs dedicated for muxing and demuxing.

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_MD_KEY_VIDEO_IS_HDR_VIVID](#oh_md_key_video_is_hdr_vivid) | Whether the video track in a media file is HDR Vivid. The value type is int32_t. This key is used for both muxing and demuxing. This key is optional. |
| [OH_MD_KEY_START_TIME](#oh_md_key_start_time) | Start time of the first frame in a media file, measured in microseconds. The value type is int64_t. This key is optional.           |
| [OH_MD_KEY_TRACK_START_TIME](#oh_md_key_track_start_time) | Start time of the track, measured in microseconds. The value type is int64_t. This key is optional.           |
| [OH_MD_KEY_TRACK_TYPE](#oh_md_key_track_type)                | Track type in a media file. The value type is int32_t. For details, see [OH_MediaType](#oh_mediatype-1). This key is optional.|
| [OH_MD_KEY_DURATION](#oh_md_key_duration)                    | Duration in a media file. The value type is int64_t. This key is optional.                 |
| [OH_MD_KEY_TITLE](#oh_md_key_title)                          | Title in a media file. The value type is string. This key is optional.              |
| [OH_MD_KEY_ARTIST](#oh_md_key_artist)                        | Artist in a media file. The value type is string. This key is optional.            |
| [OH_MD_KEY_ALBUM](#oh_md_key_album)                          | Album in a media file. The value type is string. This key is optional.              |
| [OH_MD_KEY_ALBUM_ARTIST](#oh_md_key_album_artist)            | Album artist of the input media. The value type is string. This key is optional.              |
| [OH_MD_KEY_DATE](#oh_md_key_date)                            | Date in a media file, for example, 2024. The value type is string. This key is optional.   |
| [OH_MD_KEY_COMMENT](#oh_md_key_comment)                      | Comment in a media file. The value type is string. This key is optional.              |
| [OH_MD_KEY_GENRE](#oh_md_key_genre)                          | Genre in a media file. The value type is string. This key is optional.              |
| [OH_MD_KEY_COPYRIGHT](#oh_md_key_copyright)                  | Copyright in a media file. The value type is string. This key is optional.              |
| [OH_MD_KEY_LANGUAGE](#oh_md_key_language)                    | Language in a media file. The value type is string. This key is optional.              |
| [OH_MD_KEY_DESCRIPTION](#oh_md_key_description)              | Description in a media file. The value type is string. This key is optional.              |
| [OH_MD_KEY_LYRICS](#oh_md_key_lyrics)                        | Lyrics in a media file. The value type is string. This key is optional.              |
| [OH_MD_KEY_TRACK_COUNT](#oh_md_key_track_count)              | Number of tracks in a media file. The value type is int32_t. This key is optional.        |
| [OH_MD_KEY_BUFFER_DURATION](#oh_md_key_buffer_duration) | Duration corresponding to the audio, video, or subtitle sample carried in AVBuffer, in microseconds. The value type is int64_t. This key is optional.           |
| [OH_MD_KEY_DECODING_TIMESTAMP](#oh_md_key_decoding_timestamp) | Decoding timestamp corresponding to the audio, video, or subtitle sample carried in AVBuffer, in microseconds. The value type is int64_t. This key is optional.           |
| [OH_MD_KEY_CODEC_MIME](#oh_md_key_codec_mime)                | [MIME](#media-codec-formats) type of the codec. The value type is string. This key is optional.        |
| [OH_MD_KEY_VIDEO_SAR](#oh_md_key_video_sar)                  | Aspect ratio of the sample. The value type is double.|
| [OH_MD_KEY_CREATION_TIME](#oh_md_key_creation_time)          | Media file creation time. The value type is string.|


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [avcodec_audio_channel_layout.h](avcodec__audio__channel__layout_8h.md) | Declares the enums used for audio encoding and decoding.| 
| [native_avcodec_base.h](native__avcodec__base_8h.md) | Declares the native APIs used for basic audio and video muxing, demuxing, encoding, and decoding.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) | Describes all the asynchronous callback function pointers of an **OH_AVCodec** instance. (This function is deprecated in API version 11.)| 
| struct  [OH_AVCodecCallback](_o_h___a_v_codec_callback.md) | Describes all the asynchronous callback function pointers of an **OH_AVCodec** instance.| 
| struct  [OH_AVDataSource](_o_h___a_v_data_source.md) | Describes a user-defined data source. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct NativeWindow [OHNativeWindow](#ohnativewindow) | Defines a struct for a native object for the graphics interface. | 
| typedef struct [OH_AVCodec](#oh_avcodec) [OH_AVCodec](#oh_avcodec) | Defines a struct for a native object for the audio and video codec interface. | 
| typedef void(\* [OH_AVCodecOnError](#oh_avcodeconerror)) ([OH_AVCodec](#oh_avcodec) \*codec, int32_t errorCode, void \*userData) | Defines the pointer to the function that is called to report error information when an error occurs during the running of an **OH_AVCodec** instance.| 
| typedef void(\* [OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged)) ([OH_AVCodec](#oh_avcodec) \*codec, [OH_AVFormat](_core.md#oh_avformat) \*format, void \*userData) | Defines the pointer to the function that is called to report the new stream description when the resolution of the input video stream being decoded or the output video stream that has been encoded changes.<br>From API version 15, this function pointer is called to report the new stream description when the stream sampling rate, number of audio channels, or audio sampling format changes during audio decoding. The decoding formats that can detect these changes include <!--RP3--><!--RP3End-->AAC, FLAC, MP3, and VORBIS.| 
| typedef void(\* [OH_AVCodecOnNeedInputData](#oh_avcodeconneedinputdata)) ([OH_AVCodec](#oh_avcodec) \*codec, uint32_t index, [OH_AVMemory](_core.md#oh_avmemory) \*data, void \*userData) | Defines the pointer to the function that is called when new input data is required during the running of an **OH_AVCodec** instance. The function carries a buffer to fill in new input data. (This function is deprecated in API version 11.)| 
| typedef void(\* [OH_AVCodecOnNewOutputData](#oh_avcodeconnewoutputdata)) ([OH_AVCodec](#oh_avcodec) \*codec, uint32_t index, [OH_AVMemory](_core.md#oh_avmemory) \*data, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr, void \*userData) | Defines the pointer to the function that is called when new output data is generated during the running of an **OH_AVCodec** instance. The function carries a buffer filled with new output data. (This function is deprecated in API version 11.)| 
| typedef void(\* [OH_AVCodecOnNeedInputBuffer](#oh_avcodeconneedinputbuffer)) ([OH_AVCodec](#oh_avcodec) \*codec, uint32_t index, [OH_AVBuffer](_core.md#oh_avbuffer) \*buffer, void \*userData) | Defines the pointer to the function that is called when new input data is required during the running of an **OH_AVCodec** instance. The function carries a buffer to fill in new input data.| 
| typedef void(\* [OH_AVCodecOnNewOutputBuffer](#oh_avcodeconnewoutputbuffer)) ([OH_AVCodec](#oh_avcodec) \*codec, uint32_t index, [OH_AVBuffer](_core.md#oh_avbuffer) \*buffer, void \*userData) | Defines the pointer to the function that is called when new output data is generated during the running of an **OH_AVCodec** instance. The function carries a buffer filled with new output data.| 
| typedef struct [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) [OH_AVCodecAsyncCallback](#oh_avcodecasynccallback) | Defines all the asynchronous callback function pointers of an **OH_AVCodec** instance. (This function is deprecated in API version 11.)| 
| typedef struct [OH_AVCodecCallback](_o_h___a_v_codec_callback.md) [OH_AVCodecCallback](#oh_avcodeccallback) | Defines all the asynchronous callback function pointers of an **OH_AVCodec** instance.| 
| typedef int32_t(\* [OH_AVDataSourceReadAt](#oh_avdatasourcereadat)) (OH_AVBuffer \*data, int32_t length, int64_t pos) | Defines a function pointer used to provide the capability of obtaining user-defined media data. | 
| typedef struct [OH_AVDataSource](_o_h___a_v_data_source.md) [OH_AVDataSource](#oh_avdatasource) | Defines a struct for a user-defined data source. | 
| typedef enum [OH_MediaType](#oh_mediatype-1) [OH_MediaType](#oh_mediatype) | Defines an enum for the media types.| 
| typedef enum [OH_AACProfile](#oh_aacprofile-1) [OH_AACProfile](#oh_aacprofile) | Defines an enum for the Advanced Audio Coding (AAC) profiles.| 
| typedef enum [OH_AVCProfile](#oh_avcprofile-1) [OH_AVCProfile](#oh_avcprofile) | Defines an enum for the Advanced Video Coding (AVC) profiles.| 
| typedef enum [OH_HEVCProfile](#oh_hevcprofile-1) [OH_HEVCProfile](#oh_hevcprofile) | Defines an enum for the High Efficiency Video Coding (HEVC) profiles.| 
| typedef enum [OH_VVCProfile](#oh_vvcprofile-1) [OH_VVCProfile](#oh_vvcprofile) | Defines an enum for the VVC profiles.| 
| typedef enum [OH_MPEG2Profile](#oh_mpeg2profile-1) [OH_MPEG2Profile](#oh_mpeg2profile) | Defines an enum for the MPEG2 profiles.| 
| typedef enum [OH_MPEG4Profile](#oh_mpeg4profile-1) [OH_MPEG4Profile](#oh_mpeg4profile) | Defines an enum for the MPEG4 profiles.| 
| typedef enum [OH_AVOutputFormat](#oh_avoutputformat-1) [OH_AVOutputFormat](#oh_avoutputformat) | Defines an enum for the output file formats supported by a muxer.| 
| typedef enum [OH_AVSeekMode](#oh_avseekmode-1) [OH_AVSeekMode](#oh_avseekmode) | Defines an enum for the seek modes.| 
| typedef enum [OH_ScalingMode](#oh_scalingmode-1) [OH_ScalingMode](#oh_scalingmode) | Defines an enum for the scaling modes. This enum is used only in surface mode. (This type is deprecated from API version 14.)| 
| typedef enum [OH_BitsPerSample](#oh_bitspersample-1) [OH_BitsPerSample](#oh_bitspersample) | Defines an enum for the number of audio bits for each coded sample.| 
| typedef enum [OH_ColorPrimary](#oh_colorprimary-1) [OH_ColorPrimary](#oh_colorprimary) | Defines an enum for the primary colors.| 
| typedef enum [OH_TransferCharacteristic](#oh_transfercharacteristic-1) [OH_TransferCharacteristic](#oh_transfercharacteristic) | Defines an enum for the transfer characteristics.| 
| typedef enum [OH_MatrixCoefficient](#oh_matrixcoefficient-1) [OH_MatrixCoefficient](#oh_matrixcoefficient) | Defines an enum for the matrix coefficients.| 
| typedef enum [OH_AVCLevel](#oh_avclevel-1) [OH_AVCLevel](#oh_avclevel) | Defines an enum for the AVC levels. | 
| typedef enum [OH_HEVCLevel](#oh_hevclevel-1) [OH_HEVCLevel](#oh_hevclevel) | Defines an enum for the HEVC levels. | 
| typedef enum [OH_VVCLevel](#oh_vvclevel-1) [OH_VVCLevel](#oh_vvclevel) | Defines an enum for the VVC levels. | 
| typedef enum [OH_MPEG2Level](#oh_mpeg2level-1) [OH_MPEG2Level](#oh_mpeg2level) | Defines an enum for the MPEG2 levels.| 
| typedef enum [OH_MPEG4Level](#oh_mpeg4level-1) [OH_MPEG4Level](#oh_mpeg4level) | Defines an enum for the MPEG4 levels.| 
| typedef enum [OH_TemporalGopReferenceMode](#oh_temporalgopreferencemode-1) [OH_TemporalGopReferenceMode](#oh_temporalgopreferencemode) | Defines an enum for the reference modes of temporal image groups. |
| typedef enum [OH_BitrateMode](#oh_bitratemode-1) [OH_BitrateMode](#oh_bitratemode) | Defines an enum for the bit rate modes of an encoder. |


### Enums

| Name| Description| 
| -------- | -------- |
| [AudioChannelSet](#audiochannelset) : uint64_t {<br>FRONT_LEFT = 1ULL &lt;&lt; 0U,<br>FRONT_RIGHT = 1ULL &lt;&lt; 1U,<br>FRONT_CENTER = 1ULL &lt;&lt; 2U,<br>LOW_FREQUENCY = 1ULL &lt;&lt; 3U,<br>BACK_LEFT = 1ULL &lt;&lt; 4U,<br>BACK_RIGHT = 1ULL &lt;&lt; 5U,<br>FRONT_LEFT_OF_CENTER = 1ULL &lt;&lt; 6U,<br>FRONT_RIGHT_OF_CENTER = 1ULL &lt;&lt; 7U,<br>BACK_CENTER = 1ULL &lt;&lt; 8U,<br>SIDE_LEFT = 1ULL &lt;&lt; 9U,<br>SIDE_RIGHT = 1ULL &lt;&lt; 10U,<br>TOP_CENTER = 1ULL &lt;&lt; 11U,<br>TOP_FRONT_LEFT = 1ULL &lt;&lt; 12U,<br>TOP_FRONT_CENTER = 1ULL &lt;&lt; 13U,<br>TOP_FRONT_RIGHT = 1ULL &lt;&lt; 14U,<br>TOP_BACK_LEFT = 1ULL &lt;&lt; 15U,<br>TOP_BACK_CENTER = 1ULL &lt;&lt; 16U,<br>TOP_BACK_RIGHT = 1ULL &lt;&lt; 17U,<br>STEREO_LEFT = 1ULL &lt;&lt; 29U,<br>STEREO_RIGHT = 1ULL &lt;&lt; 30U,<br>WIDE_LEFT = 1ULL &lt;&lt; 31U,<br>WIDE_RIGHT = 1ULL &lt;&lt; 32U,<br>SURROUND_DIRECT_LEFT = 1ULL &lt;&lt; 33U,<br>SURROUND_DIRECT_RIGHT = 1ULL &lt;&lt; 34U,<br>LOW_FREQUENCY_2 = 1ULL &lt;&lt; 35U,<br>TOP_SIDE_LEFT = 1ULL &lt;&lt; 36U,<br>TOP_SIDE_RIGHT = 1ULL &lt;&lt; 37U,<br>BOTTOM_FRONT_CENTER = 1ULL &lt;&lt; 38U,<br>BOTTOM_FRONT_LEFT = 1ULL &lt;&lt; 39U,<br>BOTTOM_FRONT_RIGHT = 1ULL &lt;&lt; 40U,<br>AMBISONICS_ACN0 = 1ULL &lt;&lt; 41U,<br>AMBISONICS_ACN1 = 1ULL &lt;&lt; 42U,<br>AMBISONICS_ACN2 = 1ULL &lt;&lt; 43U,<br>AMBISONICS_ACN3 = 1ULL &lt;&lt; 44U,<br>AMBISONICS_W = AMBISONICS_ACN0,<br>AMBISONICS_Y = AMBISONICS_ACN1,<br>AMBISONICS_Z = AMBISONICS_ACN2,<br>AMBISONICS_X = AMBISONICS_ACN3,<br>AMBISONICS_ACN4 = 1ULL &lt;&lt; 45U,<br>AMBISONICS_ACN5 = 1ULL &lt;&lt; 46U,<br>AMBISONICS_ACN6 = 1ULL &lt;&lt; 47U,<br>AMBISONICS_ACN7 = 1ULL &lt;&lt; 48U,<br>AMBISONICS_ACN8 = 1ULL &lt;&lt; 49U,<br>AMBISONICS_ACN9 = 1ULL &lt;&lt; 50U,<br>AMBISONICS_ACN10 = 1ULL &lt;&lt; 51U,<br>AMBISONICS_ACN11 = 1ULL &lt;&lt; 52U,<br>AMBISONICS_ACN12 = 1ULL &lt;&lt; 53U,<br>AMBISONICS_ACN13 = 1ULL &lt;&lt; 54U,<br>AMBISONICS_ACN14 = 1ULL &lt;&lt; 55U,<br>AMBISONICS_ACN15 = 1ULL &lt;&lt; 56U<br>} | Enumerates the audio channel sets. Each channel number is mapped to a variable of int64_t. (This function is deprecated in API version 11.)| 
| [AudioChannelLayout](#audiochannellayout) : uint64_t {<br>UNKNOWN_CHANNEL_LAYOUT = 0,<br>MONO = (AudioChannelSet::FRONT_CENTER),<br>STEREO = (AudioChannelSet::FRONT_LEFT \| AudioChannelSet::FRONT_RIGHT),<br>CH_2POINT1 = (STEREO \| AudioChannelSet::LOW_FREQUENCY),<br>CH_2_1 = (STEREO \| AudioChannelSet::BACK_CENTER),<br>SURROUND = (STEREO \| AudioChannelSet::FRONT_CENTER),<br>CH_3POINT1 = (SURROUND \| AudioChannelSet::LOW_FREQUENCY),<br>CH_4POINT0 = (SURROUND \| AudioChannelSet::BACK_CENTER),<br>CH_4POINT1 = (CH_4POINT0 \| AudioChannelSet::LOW_FREQUENCY),<br>CH_2_2 = (STEREO \| AudioChannelSet::SIDE_LEFT \| AudioChannelSet::SIDE_RIGHT),<br>QUAD = (STEREO \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT),<br>CH_5POINT0 = (SURROUND \| AudioChannelSet::SIDE_LEFT \| AudioChannelSet::SIDE_RIGHT),<br>CH_5POINT1 = (CH_5POINT0 \| AudioChannelSet::LOW_FREQUENCY),<br>CH_5POINT0_BACK = (SURROUND \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT),<br>CH_5POINT1_BACK = (CH_5POINT0_BACK \| AudioChannelSet::LOW_FREQUENCY),<br>CH_6POINT0 = (CH_5POINT0 \| AudioChannelSet::BACK_CENTER),<br>CH_6POINT0_FRONT = (CH_2_2 \| AudioChannelSet::FRONT_LEFT_OF_CENTER \| AudioChannelSet::FRONT_RIGHT_OF_CENTER),<br>HEXAGONAL = (CH_5POINT0_BACK \| AudioChannelSet::BACK_CENTER),<br>CH_6POINT1 = (CH_5POINT1 \| AudioChannelSet::BACK_CENTER),<br>CH_6POINT1_BACK = (CH_5POINT1_BACK \| AudioChannelSet::BACK_CENTER),<br>CH_6POINT1_FRONT = (CH_6POINT0_FRONT \| AudioChannelSet::LOW_FREQUENCY),<br>CH_7POINT0 = (CH_5POINT0 \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT),<br>CH_7POINT0_FRONT = (CH_5POINT0 \| AudioChannelSet::FRONT_LEFT_OF_CENTER \| AudioChannelSet::FRONT_RIGHT_OF_CENTER),<br>CH_7POINT1 = (CH_5POINT1 \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT),<br>CH_7POINT1_WIDE = (CH_5POINT1 \| AudioChannelSet::FRONT_LEFT_OF_CENTER \| AudioChannelSet::FRONT_RIGHT_OF_CENTER),<br>CH_7POINT1_WIDE_BACK, CH_3POINT1POINT2 = (CH_3POINT1 \| AudioChannelSet::TOP_FRONT_LEFT \| AudioChannelSet::TOP_FRONT_RIGHT),<br>CH_5POINT1POINT2 = (CH_5POINT1 \| AudioChannelSet::TOP_SIDE_LEFT \| AudioChannelSet::TOP_SIDE_RIGHT),<br>CH_5POINT1POINT4, CH_7POINT1POINT2 = (CH_7POINT1 \| AudioChannelSet::TOP_SIDE_LEFT \| AudioChannelSet::TOP_SIDE_RIGHT),<br>CH_7POINT1POINT4, CH_9POINT1POINT4 = (CH_7POINT1POINT4 \| AudioChannelSet::WIDE_LEFT \| AudioChannelSet::WIDE_RIGHT),<br>CH_9POINT1POINT6 = (CH_9POINT1POINT4 \| AudioChannelSet::TOP_SIDE_LEFT \| AudioChannelSet::TOP_SIDE_RIGHT),<br>CH_10POINT2, CH_22POINT2, OCTAGONAL = (CH_5POINT0 \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_CENTER \| AudioChannelSet::BACK_RIGHT),<br>HEXADECAGONAL, STEREO_DOWNMIX = (AudioChannelSet::STEREO_LEFT \| AudioChannelSet::STEREO_RIGHT),<br>HOA_FIRST,<br>HOA_SECOND,<br>HOA_THIRD<br>} | Enumerates the types of the audio channel sets. The output format of the decoder is represented as the channel type of the codec. (This function is deprecated in API version 11.)| 
| [OH_MediaType](#oh_mediatype-1) {<br>MEDIA_TYPE_AUD = 0,<br>MEDIA_TYPE_VID = 1,<br>MEDIA_TYPE_SUBTITILE = 2<br>} | Enumerates the media types.|
| [OH_AACProfile](#oh_aacprofile-1) {<br>AAC_PROFILE_LC = 0,<br>AAC_PROFILE_HE = 3,<br>AAC_PROFILE_HE_V2 = 4<br>} | Enumerates the AAC profiles.<!--Del--><br>(**AAC_PROFILE_HE** and **AAC_PROFILE_HE_V2** are not available yet.)<!--DelEnd--> | 
| [OH_AVCProfile](#oh_avcprofile-1) {<br>AVC_PROFILE_BASELINE = 0,<br>AVC_PROFILE_HIGH = 4,<br>AVC_PROFILE_MAIN = 8<br>} | Enumerates the AVC profiles.| 
| [OH_HEVCProfile](#oh_hevcprofile-1) {<br>HEVC_PROFILE_MAIN = 0,<br>HEVC_PROFILE_MAIN_10 = 1,<br>HEVC_PROFILE_MAIN_STILL = 2,<br>HEVC_PROFILE_MAIN_10_HDR10 = 3,<br>HEVC_PROFILE_MAIN_10_HDR10_PLUS = 4<br>} | Enumerates the HEVC profiles.<br>(**HEVC_PROFILE_MAIN_10_HDR10** and **HEVC_PROFILE_MAIN_10_HDR10_PLUS** are deprecated since API version 14.)| 
| [OH_VVCProfile](#oh_vvcprofile-1) {<br>VVC_PROFILE_MAIN_10 = 1, <br>VVC_PROFILE_MAIN_12 = 2, <br>VVC_PROFILE_MAIN_12_INTRA = 10, <br>VVC_PROFILE_MULTI_MAIN_10 = 17, <br>VVC_PROFILE_MAIN_10_444 = 33, <br>VVC_PROFILE_MAIN_12_444 = 34, <br>VVC_PROFILE_MAIN_16_444 = 36, <br>VVC_PROFILE_MAIN_12_444_INTRA = 42, <br>VVC_PROFILE_MAIN_16_444_INTRA = 44, <br>VVC_PROFILE_MULTI_MAIN_10_444 = 49, <br>VVC_PROFILE_MAIN_10_STILL = 65, <br>VVC_PROFILE_MAIN_12_STILL = 66, <br>VVC_PROFILE_MAIN_10_444_STILL = 97, <br>VVC_PROFILE_MAIN_12_444_STILL = 98, <br>VVC_PROFILE_MAIN_16_444_STILL = 100 <br>} | Enumerates the VVC profiles.| 
| [OH_MPEG2Profile](#oh_mpeg2profile-1) {<br>MPEG2_PROFILE_SIMPLE = 0,<br>MPEG2_PROFILE_MAIN = 1,<br>MPEG2_PROFILE_SNR = 2,<br>MPEG2_PROFILE_SPATIAL = 3,<br>MPEG2_PROFILE_HIGH = 4,<br>MPEG2_PROFILE_422 = 5} | Enumerates the MPEG2 profiles.| 
| [OH_MPEG4Profile](#oh_mpeg4profile-1) {<br>MPEG4_PROFILE_SIMPLE = 0,<br>MPEG4_PROFILE_SIMPLE_SCALABLE = 1,<br>MPEG4_PROFILE_CORE = 2,<br>MPEG4_PROFILE_MAIN = 3,<br>MPEG4_PROFILE_NBIT = 4,<br>MPEG4_PROFILE_HYBRID = 5,<br>MPEG4_PROFILE_BASIC_ANIMATED_TEXTURE = 6,<br>MPEG4_PROFILE_SCALABLE_TEXTURE = 7,<br>MPEG4_PROFILE_SIMPLE_FA = 8,<br>MPEG4_PROFILE_ADVANCED_REAL_TIME_SIMPLE = 9,<br>MPEG4_PROFILE_CORE_SCALABLE = 10,<br>MPEG4_PROFILE_ADVANCED_CODING_EFFICIENCY = 11,<br>MPEG4_PROFILE_ADVANCED_CORE = 12,<br>MPEG4_PROFILE_ADVANCED_SCALABLE_TEXTURE = 13,<br>MPEG4_PROFILE_ADVANCED_SIMPLE = 17} | Enumerates the MPEG4 profiles.| 
| [OH_AVOutputFormat](#oh_avoutputformat-1) {<br>AV_OUTPUT_FORMAT_DEFAULT = 0,<br>AV_OUTPUT_FORMAT_MPEG_4 = 2,<br>AV_OUTPUT_FORMAT_M4A = 6,<br>AV_OUTPUT_FORMAT_AMR = 8,<br>AV_OUTPUT_FORMAT_MP3 = 9,<br>AV_OUTPUT_FORMAT_WAV = 10, <br>AV_OUTPUT_FORMAT_AAC = 11<br>} | Enumerates the output file formats supported by a muxer.|
| [OH_AVSeekMode](#oh_avseekmode-1) {<br>SEEK_MODE_NEXT_SYNC = 0,<br>SEEK_MODE_PREVIOUS_SYNC,<br>SEEK_MODE_CLOSEST_SYNC<br>} | Enumerates the seek modes.| 
| [OH_ScalingMode](#oh_scalingmode-1) {<br>SCALING_MODE_SCALE_TO_WINDOW = 1,<br>SCALING_MODE_SCALE_CROP = 2<br>} | Enumerates the scaling modes. (This enum is deprecated from API version 14.)| 
| [OH_BitsPerSample](#oh_bitspersample-1) {<br>SAMPLE_U8 = 0, SAMPLE_S16LE = 1,<br>SAMPLE_S24LE = 2, SAMPLE_S32LE = 3,<br>SAMPLE_F32LE = 4, SAMPLE_U8P = 5,<br>SAMPLE_S16P = 6, SAMPLE_S24P = 7,<br>SAMPLE_S32P = 8, SAMPLE_F32P = 9,<br>INVALID_WIDTH = -1<br>} | Enumerates the number of audio bits for each coded sample.| 
| [OH_ColorPrimary](#oh_colorprimary-1) {<br>COLOR_PRIMARY_BT709 = 1,<br>COLOR_PRIMARY_UNSPECIFIED = 2,<br>COLOR_PRIMARY_BT470_M = 4,<br>COLOR_PRIMARY_BT601_625 = 5,<br>COLOR_PRIMARY_BT601_525 = 6,<br>COLOR_PRIMARY_SMPTE_ST240 = 7,<br>COLOR_PRIMARY_GENERIC_FILM = 8,<br>COLOR_PRIMARY_BT2020 = 9,<br>COLOR_PRIMARY_SMPTE_ST428 = 10,<br>COLOR_PRIMARY_P3DCI = 11,<br>COLOR_PRIMARY_P3D65 = 12<br>} | Enumerates the primary colors.| 
| [OH_TransferCharacteristic](#oh_transfercharacteristic-1) {<br>TRANSFER_CHARACTERISTIC_BT709 = 1,<br>TRANSFER_CHARACTERISTIC_UNSPECIFIED = 2,<br>TRANSFER_CHARACTERISTIC_GAMMA_2_2 = 4,<br>TRANSFER_CHARACTERISTIC_GAMMA_2_8 = 5,<br>TRANSFER_CHARACTERISTIC_BT601 = 6,<br>TRANSFER_CHARACTERISTIC_SMPTE_ST240 = 7,<br>TRANSFER_CHARACTERISTIC_LINEAR = 8,<br>TRANSFER_CHARACTERISTIC_LOG = 9,<br>TRANSFER_CHARACTERISTIC_LOG_SQRT = 10,<br>TRANSFER_CHARACTERISTIC_IEC_61966_2_4 = 11,<br>TRANSFER_CHARACTERISTIC_BT1361 = 12,<br>TRANSFER_CHARACTERISTIC_IEC_61966_2_1 = 13,<br>TRANSFER_CHARACTERISTIC_BT2020_10BIT = 14,<br>TRANSFER_CHARACTERISTIC_BT2020_12BIT = 15,<br>TRANSFER_CHARACTERISTIC_PQ = 16,<br>TRANSFER_CHARACTERISTIC_SMPTE_ST428 = 17,<br>TRANSFER_CHARACTERISTIC_HLG = 18<br>} | Enumerates the transfer characteristics.| 
| [OH_MatrixCoefficient](#oh_matrixcoefficient-1) {<br>MATRIX_COEFFICIENT_IDENTITY = 0,<br>MATRIX_COEFFICIENT_BT709 = 1,<br>MATRIX_COEFFICIENT_UNSPECIFIED = 2,<br>MATRIX_COEFFICIENT_FCC = 4,<br>MATRIX_COEFFICIENT_BT601_625 = 5,<br>MATRIX_COEFFICIENT_BT601_525 = 6, MATRIX_COEFFICIENT_SMPTE_ST240 = 7,<br>MATRIX_COEFFICIENT_YCGCO = 8,<br>MATRIX_COEFFICIENT_BT2020_NCL = 9,<br>MATRIX_COEFFICIENT_BT2020_CL = 10,<br>MATRIX_COEFFICIENT_SMPTE_ST2085 = 11,<br>MATRIX_COEFFICIENT_CHROMATICITY_NCL = 12,<br>MATRIX_COEFFICIENT_CHROMATICITY_CL = 13,<br>MATRIX_COEFFICIENT_ICTCP = 14<br>} | Enumerates the matrix coefficients.| 
| [OH_AVCLevel](#oh_avclevel-1) {<br>AVC_LEVEL_1 = 0, <br>AVC_LEVEL_1b = 1, <br>AVC_LEVEL_11 = 2, <br>AVC_LEVEL_12 = 3,<br>AVC_LEVEL_13 = 4, <br>AVC_LEVEL_2 = 5, <br>AVC_LEVEL_21 = 6, <br>AVC_LEVEL_22 = 7,<br>AVC_LEVEL_3 = 8, <br>AVC_LEVEL_31 = 9, <br>AVC_LEVEL_32 = 10, <br>AVC_LEVEL_4 = 11,<br>AVC_LEVEL_41 = 12, <br>AVC_LEVEL_42 = 13, <br>AVC_LEVEL_5 = 14, <br>AVC_LEVEL_51 = 15, <br>AVC_LEVEL_52 = 16, <br>AVC_LEVEL_6 = 17, <br>AVC_LEVEL_61 = 18, <br>AVC_LEVEL_62 = 19<br>} | Enumerates the AVC levels. | 
| [OH_HEVCLevel](#oh_hevclevel-1) {<br>HEVC_LEVEL_1 = 0, <br>HEVC_LEVEL_2 = 1, <br>HEVC_LEVEL_21 = 2, <br>HEVC_LEVEL_3 = 3,<br>HEVC_LEVEL_31 = 4, <br>HEVC_LEVEL_4 = 5, <br>HEVC_LEVEL_41 = 6, <br>HEVC_LEVEL_5 = 7,<br>HEVC_LEVEL_51 = 8, <br>HEVC_LEVEL_52 = 9, <br>HEVC_LEVEL_6 = 10, <br>HEVC_LEVEL_61 = 11,<br>HEVC_LEVEL_62 = 12<br>} | Enumerates the HEVC levels. | 
| [OH_VVCLevel](#oh_vvclevel-1) {<br>VVC_LEVEL_1 = 16, <br>VVC_LEVEL_2 = 32, <br>VVC_LEVEL_21 = 35, <br>VVC_LEVEL_3 = 48, <br>VVC_LEVEL_31 = 51, <br>VVC_LEVEL_4 = 64, <br>VVC_LEVEL_41 = 67, <br>VVC_LEVEL_5 = 80, <br>VVC_LEVEL_51 = 83, <br>VVC_LEVEL_52 = 86, <br>VVC_LEVEL_6 = 96, <br>VVC_LEVEL_61 = 99, <br>VVC_LEVEL_62 = 102, <br>VVC_LEVEL_63 = 105, <br>VVC_LEVEL_155 = 255<br>} | Enumerates the VVC levels. | 
| [OH_MPEG2Level](#oh_mpeg2level-1) {<br>MPEG2_LEVEL_LL = 0,<br>MPEG2_LEVEL_ML = 1,<br>MPEG2_LEVEL_H14 = 2,<br>MPEG2_LEVEL_HL = 3 } | Enumerates the MPEG2 levels.| 
| [OH_MPEG4Level](#oh_mpeg4level-1) {<br>MPEG4_LEVEL_0 = 0,<br>MPEG4_LEVEL_0B = 1,<br>MPEG4_LEVEL_1 = 2,<br>MPEG4_LEVEL_2 = 3,<br>MPEG4_LEVEL_3 = 4,<br>MPEG4_LEVEL_3B = 5,<br>MPEG4_LEVEL_4 = 6,<br>MPEG4_LEVEL_4A = 7,<br>MPEG4_LEVEL_5 = 8,<br>MPEG4_LEVEL_6 = 9} | Enumerates the MPEG4 levels.| 
| [OH_TemporalGopReferenceMode](#oh_temporalgopreferencemode-1) { <br>ADJACENT_REFERENCE = 0, <br>JUMP_REFERENCE = 1, <br>UNIFORMLY_SCALED_REFERENCE = 2 <br>} | Enumerates the reference modes of temporal image groups. | 
| [OH_BitrateMode](#oh_bitratemode-1) { <br>BITRATE_MODE_CBR = 0, <br>BITRATE_MODE_VBR = 1, <br>BITRATE_MODE_CQ = 2 } | Enumerates the bit rate modes of an encoder. |

### Variables

| Name| Description| 
| -------- | -------- |
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_AAC](#oh_avcodec_mimetype_audio_aac) | Pointer to the key that describes the MIME type of the AAC audio codec.|
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_FLAC](#oh_avcodec_mimetype_audio_flac) | Pointer to the key that describes the MIME type of the Free Lossless Audio Codec (FLAC) audio codec.|
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_OPUS](#oh_avcodec_mimetype_audio_opus) | Pointer to the key that describes the MIME type of the Opus audio codec. <!--Del-->(This specification is not available yet.)<!--DelEnd-->  |
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_G711MU](#oh_avcodec_mimetype_audio_g711mu) | Pointer to the key that describes the MIME type of the G.711 mu-law audio codec.|
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_VORBIS](#oh_avcodec_mimetype_audio_vorbis) | Pointer to the key that describes the MIME type of the Vorbis audio decoder.|
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_MPEG](#oh_avcodec_mimetype_audio_mpeg) | Pointer to the key that describes the MIME type of the MP3 audio decoder.|
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_VIVID](#oh_avcodec_mimetype_audio_vivid) | Pointer to the key that describes the MIME type of the Audio Vivid audio decoder. <!--Del-->(This specification is not available yet.)<!--DelEnd-->  |
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_AMR_NB](#oh_avcodec_mimetype_audio_amr_nb) | Pointer to the key that describes the MIME type of the AMR-NB audio decoder.|
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_AMR_WB](#oh_avcodec_mimetype_audio_amr_wb) | Pointer to the key that describes the MIME type of the AMR-WB audio decoder.|
| const char \* [OH_AVCODEC_MIMETYPE_AUDIO_APE](#oh_avcodec_mimetype_audio_ape) |Pointer to the key that describes the MIME type of the APE audio decoder.                        |
| const char \* [OH_AVCODEC_MIMETYPE_VIDEO_VVC](#oh_avcodec_mimetype_video_vvc) | Pointer to the key that describes the MIME type of the VVC (H.266) video codec.|
| const char \* [OH_AVCODEC_MIMETYPE_VIDEO_HEVC](#oh_avcodec_mimetype_video_hevc) | Pointer to the key that describes the MIME type of the HEVC (H.265) video codec.|
| const char \* [OH_AVCODEC_MIMETYPE_VIDEO_AVC](#oh_avcodec_mimetype_video_avc) | Pointer to the key that describes the MIME type of the AVC (H.264) video codec.|
| const char \* [OH_AVCODEC_MIMETYPE_VIDEO_MPEG4](#oh_avcodec_mimetype_video_mpeg4) | Pointer to the key that describes the MIME type of the MPEG4 video encoder, which is used only for muxing MPEG4 video streams. (This function is deprecated in API version 11.)|
| const char \* [OH_AVCODEC_MIMETYPE_VIDEO_MPEG2](#oh_avcodec_mimetype_video_mpeg2) | Pointer to the key that describes the MIME type of MPEG2 video codec.                       |
| const char \* [OH_AVCODEC_MIMETYPE_VIDEO_MPEG4_PART2](#oh_avcodec_mimetype_video_mpeg4_part2) | Pointer to the key that describes the MIME type of MPEG4 Part 2 video codec.        |
| const char \* [OH_AVCODEC_MIMETYPE_IMAGE_JPG](#oh_avcodec_mimetype_image_jpg) | Pointer to the key that describes the MIME type of the JPG image encoder, which is used only for muxing JPG covers.|
| const char \* [OH_AVCODEC_MIMETYPE_IMAGE_PNG](#oh_avcodec_mimetype_image_png) | Pointer to the key that describes the MIME type of the PNG image encoder, which is used only for muxing PNG covers.|
| const char \* [OH_AVCODEC_MIMETYPE_IMAGE_BMP](#oh_avcodec_mimetype_image_bmp) | Pointer to the key that describes the MIME type of the BMP image encoder, which is used only for muxing BMP covers.|
| const char \* [OH_AVCODEC_MIMETYPE_SUBTITLE_WEBVTT](#oh_avcodec_mimetype_subtitle_webvtt) |Pointer to the key that describes the MIME type of the WEBVTT subtitle demuxer.                |
| const char \* [OH_AVCODEC_MIMETYPE_SUBTITLE_SRT](#oh_avcodec_mimetype_subtitle_srt) |Pointer to the key that describes the MIME type of the SRT subtitle demuxer.                        |
| const char \* [OH_FEATURE_PROPERTY_KEY_VIDEO_ENCODER_MAX_LTR_FRAME_COUNT](#oh_feature_property_key_video_encoder_max_ltr_frame_count) | Pointer to the key that describes the maximum number of LTR frames obtained during video encoding. The value type is int32_t. |
| const char \* [OH_MD_KEY_CODEC_CONFIG](#oh_md_key_codec_config) | Pointer to the key that describes codec-specific data. In the case of video, data carried in **SPS/PPS** is transferred. In the case of audio, data carried in **extraData** is transferred. The value type is uint8_t\*. <!--Del-->(This key is not supported yet for the video codec.)<!--DelEnd--> |
| const char \* [OH_MD_MAX_INPUT_BUFFER_COUNT](#oh_md_max_input_buffer_count) | Pointer to the key that describes the maximum number of input buffers. The value type is int32_t.|
| const char \* [OH_MD_MAX_OUTPUT_BUFFER_COUNT](#oh_md_max_output_buffer_count) | Pointer to the key that describes the maximum number of output buffers. The value type is int32_t.|
| const char \* [OH_MD_KEY_BITRATE](#oh_md_key_bitrate) | Pointer to the key that describes the bit rate. The value type is int64_t.|
| const char \* [OH_MD_KEY_PROFILE](#oh_md_key_profile) | Pointer to the key that describes the encoding grading. The value type is int32_t. For details, see [OH_AVCProfile](#oh_avcprofile), [OH_HEVCProfile](#oh_hevcprofile), and [OH_AACProfile](#oh_aacprofile).|
| const char \* [OH_MD_KEY_MAX_INPUT_SIZE](#oh_md_key_max_input_size) | Pointer to the key that describes the maximum size of an input stream to decode. The value type is int32_t.|
| const char \* [OH_ED_KEY_TIME_STAMP](#oh_ed_key_time_stamp) | Pointer to the key that describes the surface buffer timestamp. The value is of the int64_t type. (This variable is deprecated from API version 14.)|
| const char \* [OH_ED_KEY_EOS](#oh_ed_key_eos) | Pointer to the key that describes the end of stream for the surface buffer. The value type is int32_t. (This variable is deprecated from API version 14.)|
| const char \* [OH_MD_KEY_WIDTH](#oh_md_key_width) | Pointer to the key that describes the video width. The value type is int32_t.|
| const char \* [OH_MD_KEY_HEIGHT](#oh_md_key_height) | Pointer to the key that describes the video height. The value type is int32_t.|
| const char \* [OH_MD_KEY_PIXEL_FORMAT](#oh_md_key_pixel_format) | Pointer to the key that describes the video pixel format. The value type is int32_t. For details, see [OH_AVPixelFormat](_core.md#oh_avpixelformat).|
| const char \* [OH_MD_KEY_FRAME_RATE](#oh_md_key_frame_rate) | Pointer to the key that describes the video frame rate. The value type is double.|
| const char \* [OH_MD_KEY_ROTATION](#oh_md_key_rotation) | Pointer to the key that describes the rotation angle of the surface. The value type is int32_t, and the value range is {0, 90, 180, 270}. The default value is 0. This key is used only for video decoding in surface mode.|
| const char \* [OH_MD_KEY_RANGE_FLAG](#oh_md_key_range_flag) | Pointer to the key that describes the video YUV value range flag. The value type is int32_t. The value **1** means a full range, and **0** means a limited range.|
| const char \* [OH_MD_KEY_COLOR_PRIMARIES](#oh_md_key_color_primaries) | Pointer to the key that describes the video primary color. The value type is int32_t. For details, see [OH_ColorPrimary](#oh_colorprimary). The video primary color complies with Table 2 in the H.273 standard.|
| const char \* [OH_MD_KEY_TRANSFER_CHARACTERISTICS](#oh_md_key_transfer_characteristics) | Pointer to the key that describes the video transfer characteristics. The value type is int32_t. For details, see [OH_TransferCharacteristic](#oh_transfercharacteristic). The video transfer characteristics comply with Table 3 in the H.273 standard.|
| const char \* [OH_MD_KEY_MATRIX_COEFFICIENTS](#oh_md_key_matrix_coefficients) | Pointer to the key that describes the video matrix coefficient. The value type is int32_t. For details, see [OH_MatrixCoefficient](#oh_matrixcoefficient). The video matrix coefficient complies with Table 4 in the H.273 standard.|
| const char \* [OH_MD_KEY_SCALING_MODE](#oh_md_key_scaling_mode) | Pointer to the key that describes the video scaling mode. The value type is int32_t. For details, see [OH_ScalingMode](#oh_scalingmode). This key is optional and is used only for video decoding in surface mode. You are advised to set the scaling mode by calling [OH_NativeWindow_NativeWindowSetScalingModeV2](../apis-arkgraphics2d/_native_window.md#oh_nativewindow_nativewindowsetscalingmodev2). (This variable is deprecated from API version 14.)|
| const char \* [OH_MD_KEY_VIDEO_CROP_TOP](#oh_md_key_video_crop_top) | Pointer to the key that describes the top coordinate (y) of the cropped rectangle. The value type is int32_t. | 
| const char \* [OH_MD_KEY_VIDEO_CROP_BOTTOM](#oh_md_key_video_crop_bottom) | Pointer to the key that describes the bottom coordinate (y) of the cropped rectangle. The value type is int32_t. | 
| const char \* [OH_MD_KEY_VIDEO_CROP_LEFT](#oh_md_key_video_crop_left) | Pointer to the key that describes the left coordinate (x) of the cropped rectangle. The value type is int32_t. | 
| const char \* [OH_MD_KEY_VIDEO_CROP_RIGHT](#oh_md_key_video_crop_right) | Pointer to the key that describes the right coordinate (x) of the cropped rectangle. The value type is int32_t.| 
| const char \* [OH_MD_KEY_VIDEO_DECODER_OUTPUT_ENABLE_VRR](#oh_md_key_video_decoder_output_enable_vrr) | Pointer to the key that specifies whether the decoder enables the video variable frame rate feature. The value type is int32_t.|
| const char \* [OH_MD_KEY_VIDEO_STRIDE](#oh_md_key_video_stride) | Pointer to the key that describes the stride of the video frame. The value type is int32_t. | 
| const char \* [OH_MD_KEY_VIDEO_SLICE_HEIGHT](#oh_md_key_video_slice_height) | Pointer to the key that describes the height of the video frame. The value type is int32_t. | 
| const char \* [OH_MD_KEY_VIDEO_PIC_WIDTH](#oh_md_key_video_pic_width) | Pointer to the key that describes the width of the video frame. The value type is int32_t. | 
| const char \* [OH_MD_KEY_VIDEO_PIC_HEIGHT](#oh_md_key_video_pic_height) | Pointer to the key that describes the height of the video frame. The value type is int32_t. | 
| const char \* [OH_MD_KEY_VIDEO_ENABLE_LOW_LATENCY](#oh_md_key_video_enable_low_latency) | Pointer to the key that describes the enabled status of low-latency video codec. The value type is int32_t. The value **1** means that low-latency video codec is enabled, and **0** means the opposite. If enabled, the input and output data held by the video encoder or decoder does not exceed the amount required by the codec standard.  | 
| const char \* [OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE](#oh_md_key_video_encode_bitrate_mode) | Pointer to the key that describes the video encoding bit rate mode. The value type is int32_t. For details, see [OH_BitrateMode](#oh_bitratemode-1).|
| const char \* [OH_MD_KEY_QUALITY](#oh_md_key_quality) | Pointer to the key that describes the required encoding quality. The value type is int32_t. This key applies only to encoders configured in constant quality mode.|
| const char \* [OH_MD_KEY_REQUEST_I_FRAME](#oh_md_key_request_i_frame) | Pointer to the key that describes the request for immediate encoding of I-frames. The value type is int32_t.|
| const char \* [OH_MD_KEY_I_FRAME_INTERVAL](#oh_md_key_i_frame_interval) | Pointer to the key that describes the key frame interval, in milliseconds. The value type is int32_t. This key is optional and is used only for video encoding.|
| const char \* [OH_MD_KEY_VIDEO_ENCODER_ENABLE_TEMPORAL_SCALABILITY](#oh_md_key_video_encoder_enable_temporal_scalability) | Pointer to the key that describes the enabled status of temporal scalability. The value type is int32_t. The value **1** means temporal scalability is enabled, and **0** means the opposite. | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_SIZE](#oh_md_key_video_encoder_temporal_gop_size) | Pointer to the key that describes the size of a temporal image group. The value type is int32_t. This key is valid only when temporal scalability is enabled. |
| const char \* [OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_REFERENCE_MODE](#oh_md_key_video_encoder_temporal_gop_reference_mode) | Pointer to the key that describes the reference mode in a temporal image group. The value type is int32_t. For details, see [OH_TemporalGopReferenceMode](#oh_temporalgopreferencemode). This key is valid only when temporal scalability is enabled. | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_LTR_FRAME_COUNT](#oh_md_key_video_encoder_ltr_frame_count) | Pointer to the key that describes the number of LTR frames. The value type is int32_t. The value must be within the supported value range. This key is optional and is used only for video encoding. | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_MARK_LTR](#oh_md_key_video_encoder_per_frame_mark_ltr) | Pointer to the key that describes the key that marks the current frame as an LTR frame. The value type is int32_t. The value **1** means that the frame is marked as an LTR frame, and **0** means the opposite. This key is optional and is used only for video encoding. | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_USE_LTR](#oh_md_key_video_encoder_per_frame_use_ltr) | Pointer to the key that describes the POC number of the LTR frame referenced by the current frame. The value type is int32_t. This key is optional and is used only for video encoding. |
| const char \* [OH_MD_KEY_VIDEO_PER_FRAME_IS_LTR](#oh_md_key_video_per_frame_is_ltr) | Pointer to the key that specifies whether the frame corresponding to the stream output from the current OH_AVBuffer is marked as an LTR frame. The value type is int32_t. The value **1** means that the frame is an LTR frame, and **0** means the opposite. This key is optional and is used only for video encoding. | 
| const char \* [OH_MD_KEY_VIDEO_PER_FRAME_POC](#oh_md_key_video_per_frame_poc) | Pointer to the key that describes the POC number of the frame. The value type is int32_t. This key is optional and is used only for video encoding. | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_QP_MAX](#oh_md_key_video_encoder_qp_max) | Pointer to the key that describes the maximum QP allowed by the video encoder. The value type is int32_t. | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_QP_MIN](#oh_md_key_video_encoder_qp_min) | Pointer to the key that describes the minimum QP allowed by the video encoder. The value type is int32_t. | 
| const char \* [OH_MD_KEY_VIDEO_ENCODER_QP_AVERAGE](#oh_md_key_video_encoder_qp_average) | Pointer to the key that describes the average QP of video frames. The value type is int32_t.|
| const char \* [OH_MD_KEY_VIDEO_ENCODER_MSE](#oh_md_key_video_encoder_mse)     |Pointer to the key that describes the MSE of video frames. The value type is double. |
| const char \* [OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER](#oh_md_key_video_encoder_repeat_previous_frame_after)    | Pointer to the key that specifies the duration (in milliseconds) for which the last frame will be resubmitted repeatedly, if no new frame is available after the previous frame is submitted to the encoder. The value type is int32_t.|
| const char \* [OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_MAX_COUNT](#oh_md_key_video_encoder_repeat_previous_max_count)    | Pointer to the key that describes the maximum number of times the encoder can repeat encoding the previous frame when no new frame is available. The value type is int32_t.|
| const char \* [OH_MD_KEY_VIDEO_DECODER_OUTPUT_COLOR_SPACE](#oh_md_key_video_decoder_output_color_space)   | Pointer to the key that describes the output color space of the video decoder. The value type is int32_t. The supported value is **OH_COLORSPACE_BT709_LIMIT**.|
| const char \* [OH_MD_KEY_AUDIO_SAMPLE_FORMAT](#oh_md_key_audio_sample_format) | Pointer to the key that describes the original audio format. The value type is int32_t. For details, see [OH_BitsPerSample](#oh_bitspersample-1).|
| const char \* [OH_MD_KEY_AUD_CHANNEL_COUNT](#oh_md_key_aud_channel_count) | Pointer to the key that describes the number of audio channels. The value type is int32_t.|
| const char \* [OH_MD_KEY_AUD_SAMPLE_RATE](#oh_md_key_aud_sample_rate) | Pointer to the key that describes the audio sampling rate. The value type is int32_t.|
| const char \* [OH_MD_KEY_AUDIO_COMPRESSION_LEVEL](#oh_md_key_audio_compression_level) | Pointer to the key that describes the audio codec compression level. The value type is int32_t type. This key is used only for audio encoding.|
| const char \* [OH_MD_KEY_CHANNEL_LAYOUT](#oh_md_key_channel_layout) | Pointer to the key that describes the required encoding channel layout. The value type is int64_t. This key applies only to encoders.|
| const char \* [OH_MD_KEY_BITS_PER_CODED_SAMPLE](#oh_md_key_bits_per_coded_sample) | Pointer to the key that describes the number of bits for each coded sample. The value type is int32_t. This key applies to FLAC encoders. For details, see [OH_BitsPerSample](#oh_bitspersample-1).|
| const char \* [OH_MD_KEY_SBR](#oh_md_key_sbr) | Pointer to the key that describes the AAC SBR format. The value type is int32_t. This key applies to AAC encoders.|
| const char \* [OH_MD_KEY_COMPLIANCE_LEVEL](#oh_md_key_compliance_level) | Pointer to the key that describes the FLAC compliance level. The value type is int32_t. This key is used only for audio encoding.|
| const char \* [OH_MD_KEY_AAC_IS_ADTS](#oh_md_key_aac_is_adts) | Pointer to the key that describes the AAC format, which can be ADTS or LATM. The value type is int32_t. This key applies to AAC decoders.|
| const char \* [OH_MD_KEY_IDENTIFICATION_HEADER](#oh_md_key_identification_header) | Pointer to the key that describes the Vorbis identification header. The value type is uint8_t. This key applies only to Vorbis decoders.|
| const char \* [OH_MD_KEY_SETUP_HEADER](#oh_md_key_setup_header) | Pointer to the key that describes the Vorbis setup header. The value type is uint8_t. This key applies only to Vorbis decoders.|
| const char \* [OH_MD_KEY_AUDIO_OBJECT_NUMBER](#oh_md_key_audio_object_number) | Pointer to the key that describes the number of audio objects. The value type is int32_t. This key is used only for Audio Vivid decoding.|
| const char \* [OH_MD_KEY_AUDIO_VIVID_METADATA](#oh_md_key_audio_vivid_metadata) | Pointer to the key that describes the Audio Vivid metadata. The value type is uint8_t\*. This key is used only for Audio Vivid decoding.|
| const char \* [OH_MD_KEY_VIDEO_IS_HDR_VIVID](#oh_md_key_video_is_hdr_vivid) | Pointer to the key that describes whether the video track in a media file is HDR Vivid. The value type is int32_t. This key is used for both muxing and demuxing.|
| const char \* [OH_MD_KEY_START_TIME](#oh_md_key_start_time) | Pointer to the key that describes the start time of the first frame in a media file, measured in microseconds. The value type is int64_t.    |
| const char \* [OH_MD_KEY_TRACK_START_TIME](#oh_md_key_track_start_time) | Pointer to the key that describes the start time of the track, measured in microseconds. The value type is int64_t.    |
| const char \* [OH_MD_KEY_TRACK_TYPE](#oh_md_key_track_type) | Pointer to the key that describes the track type in a media file. The value type is int32_t. For details, see [OH_MediaType](#oh_mediatype-1).|
| const char \* [OH_MD_KEY_DURATION](#oh_md_key_duration) | Pointer to the key that describes the duration in a media file. The value type is int64_t.|
| const char \* [OH_MD_KEY_TITLE](#oh_md_key_title) | Pointer to the key that describes the title in a media file. The value type is string.|
| const char \* [OH_MD_KEY_ARTIST](#oh_md_key_artist) | Pointer to the key that describes the lyrics in a media file. The value type is string.|
| const char \* [OH_MD_KEY_ALBUM](#oh_md_key_album) | Pointer to the key that describes the album in a media file. The value type is string.|
| const char \* [OH_MD_KEY_ALBUM_ARTIST](#oh_md_key_album_artist) | Pointer to the key that describes the album artist of the input media. The value type is string.|
| const char \* [OH_MD_KEY_DATE](#oh_md_key_date) | Pointer to the key that describes the date in a media file, for example, 2024. The value type is string.|
| const char \* [OH_MD_KEY_COMMENT](#oh_md_key_comment) | Pointer to the key that describes the comment in a media file. The value type is string.|
| const char \* [OH_MD_KEY_GENRE](#oh_md_key_genre) | Pointer to the key that describes the genre in a media file. The value type is string.|
| const char \* [OH_MD_KEY_COPYRIGHT](#oh_md_key_copyright) | Pointer to the key that describes the copyright in a media file. The value type is string.|
| const char \* [OH_MD_KEY_LANGUAGE](#oh_md_key_language) | Pointer to the key that describes the language in a media file. The value type is string.|
| const char \* [OH_MD_KEY_DESCRIPTION](#oh_md_key_description) | Pointer to the key that describes the description in a media file. The value type is string.|
| const char \* [OH_MD_KEY_LYRICS](#oh_md_key_lyrics) | Pointer to the key that describes the lyrics in a media file. The value type is string.|
| const char \* [OH_MD_KEY_TRACK_COUNT](#oh_md_key_track_count) | Pointer to the key that describes the number of tracks in a media file. The value type is int32_t.|
| const char \* [OH_MD_KEY_BUFFER_DURATION](#oh_md_key_buffer_duration) | Pointer to the key that describes the duration corresponding to the audio, video, or subtitle sample carried in AVBuffer, in microseconds. The value type is int64_t.      |
| const char \* [OH_MD_KEY_DECODING_TIMESTAMP](#oh_md_key_decoding_timestamp) | Pointer to the key that describes the decoding timestamp corresponding to the audio, video, or subtitle sample carried in AVBuffer, in microseconds. The value type is int64_t. |
| const char \* [OH_MD_KEY_CODEC_MIME](#oh_md_key_codec_mime) | Pointer to the key that describes the [MIME](#media-codec-formats) type of the codec. The value type is string.|
| const char \* [OH_MD_KEY_VIDEO_SAR](#oh_md_key_video_sar) | Pointer to the key that describes the aspect ratio of the sample. The value type is double.|
| const char \* [OH_MD_KEY_CREATION_TIME](#oh_md_key_creation_time) | Pointer to the key that describes the media file creation time. The value type is string.|


## Type Description


### OH_AACProfile

```
typedef enum OH_AACProfile OH_AACProfile
```

**Description**

Defines an enum for the AAC profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_AVCLevel

```
typedef enum OH_AVCLevel OH_AVCLevel
```
**Description**

Defines an enum for the AVC levels.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_AVCodec

```
typedef struct OH_AVCodec OH_AVCodec
```
**Description**

Defines a struct for a native object for the audio and video codec interface.

**Since**: 9


### OH_AVCodecAsyncCallback

```
typedef struct OH_AVCodecAsyncCallback OH_AVCodecAsyncCallback
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
typedef struct OH_AVCodecCallback OH_AVCodecCallback
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

| Use Case| Error Code|
| -------- | -------- |
| Audio encoding/decoding| **AV_ERR_DRM_DECRYPT_FAILED**: DRM decryption failed. |
| Video encoding and decoding| **AV_ERROR_NO_MEMORY**: System resources are insufficient.<br>**AV_ERROR_UNKNOWN**: An unknown error occurs. Analyze the error based on specific logs.<br>**AV_ERR_SERVICE_DIED**: The service is dead. |
| Video decoding| **AV_ERR_VIDEO_UNSUPPORTED_COLOR_SPACE_CONVERSION**: The current input does not support CSC. |
<!--RP1--><!--RP1End-->

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| codec | Pointer to an **OH_AVCodec** instance. | 
| errorCode | Error code. The returned error codes vary in scenarios. For details, see the table in the function description. | 
| userData | Pointer to the data on which the caller depends when executing the callback. |


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
| codec | Pointer to an **OH_AVCodec** instance. | 
| index | Index of the new input buffer. | 
| buffer | Pointer to the data to fill in the new input buffer. | 
| userData | Pointer to the data on which the caller depends when executing the callback. | 


### OH_AVCodecOnNeedInputData

```
typedef void(* OH_AVCodecOnNeedInputData) (OH_AVCodec *codec, uint32_t index, OH_AVMemory *data, void *userData)
```

**Description**

Defines the pointer to the function that is called when new input data is required during the running of an **OH_AVCodec** instance. The function carries a buffer to fill in new input data.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

**Deprecated from**: 11

**Substitute**: [OH_AVCodecOnNeedInputBuffer](#oh_avcodeconneedinputbuffer)

**Parameters**

| Name| Description| 
| -------- | -------- |
| codec | Pointer to an **OH_AVCodec** instance. | 
| index | Index of the new input buffer. | 
| data | Pointer to the data to fill in the new input buffer. | 
| userData | Pointer to the data on which the caller depends when executing the callback. | 


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
| codec | Pointer to an **OH_AVCodec** instance. | 
| index | Index of the new output buffer. | 
| buffer | Pointer to the data filled in the new output buffer. | 
| userData | Pointer to the data on which the caller depends when executing the callback. | 


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
| codec | Pointer to an **OH_AVCodec** instance. | 
| index | Index of the new output buffer. | 
| data | Pointer to the data filled in the new output buffer. | 
| attr | Pointer to the description information about the new output buffer. For details, see [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md). | 
| userData | Pointer to the data on which the caller depends when executing the callback. | 


### OH_AVCodecOnStreamChanged

```
typedef void(* OH_AVCodecOnStreamChanged) (OH_AVCodec *codec, OH_AVFormat *format, void *userData)
```

**Description**

Defines the pointer to the function that is called to report the new stream description when the resolution of the input video stream being decoded or the output video stream that has been encoded changes.<br>From API version 15, this function pointer is called to report the new stream description when the stream sampling rate, number of audio channels, or audio sampling format changes during audio decoding. The decoding formats that can detect these changes include <!--RP3--><!--RP3End-->AAC, FLAC, MP3, and VORBIS.<br>Note that the lifecycle of the pointer to the **OH_AVFormat** instance is valid only when the function pointer is being called. Do not access the pointer to the instance after the function pointer is called.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| codec | Pointer to an **OH_AVCodec** instance. |
| format | Pointer to the description information about the new output stream. |
| userData | Pointer to the data on which the caller depends when executing the callback. |


### OH_AVCProfile

```
typedef enum OH_AVCProfile OH_AVCProfile
```

**Description**

Defines an enum for the AVC profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_AVDataSource

```
typedef struct OH_AVDataSource OH_AVDataSource
```

**Description**

Defines a struct for a user-defined data source.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_AVDataSourceReadAt

```
typedef int32_t(* OH_AVDataSourceReadAt) (OH_AVBuffer *data, int32_t length, int64_t pos)
```

**Description**

Defines a function pointer used to provide the capability of obtaining user-defined media data.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| data | Buffer to be filled in. | 
| length | Length of the data to read. | 
| pos | Offset from which the data is read. | 

**Returns**

Actual length of the data read to the buffer.


### OH_AVOutputFormat

```
typedef enum OH_AVOutputFormat OH_AVOutputFormat
```

**Description**

Defines an enum for the output file formats supported by a muxer.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_AVSeekMode

```
typedef enum OH_AVSeekMode OH_AVSeekMode
```

**Description**

Defines an enum for the seek modes.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_BitsPerSample

```
typedef enum OH_BitsPerSample OH_BitsPerSample
```

**Description**

Defines an enum for the number of audio bits for each coded sample.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_ColorPrimary

```
typedef enum OH_ColorPrimary OH_ColorPrimary
```

**Description**

Defines an enum for the primary colors.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_HEVCLevel

```
typedef enum OH_HEVCLevel OH_HEVCLevel
```

**Description**

Defines an enum for the HEVC levels.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_HEVCProfile

```
typedef enum OH_HEVCProfile OH_HEVCProfile
```

**Description**

Defines an enum for the HEVC profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MatrixCoefficient

```
typedef enum OH_MatrixCoefficient OH_MatrixCoefficient
```

**Description**

Defines an enum for the matrix coefficients.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MediaType

```
typedef enum OH_MediaType OH_MediaType
```

**Description**

Defines an enum for the media types.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MPEG2Level

```
typedef enum OH_MPEG2Level OH_MPEG2Level
```

**Description**

Defines an enum for the MPEG2 levels.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 18


### OH_MPEG2Profile

```
typedef enum OH_MPEG2Profile OH_MPEG2Profile
```

**Description**

Defines an enum for the MPEG2 profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 18


### OH_MPEG4Level

```
typedef enum OH_MPEG4Level OH_MPEG4Level
```

**Description**

Defines an enum for the MPEG4 levels.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 18


### OH_MPEG4Profile

```
typedef enum OH_MPEG4Profile OH_MPEG4Profile
```

**Description**

Defines an enum for the MPEG4 profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 18


### OH_ScalingMode

```
typedef enum OH_ScalingMode OH_ScalingMode
```

**Description**

Defines an enum for the scaling modes. This enum is used only in surface mode.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Deprecated from**: 14

**Substitute**: [OHScalingModeV2](../apis-arkgraphics2d/_native_window.md#ohscalingmodev2-1)


### OH_TemporalGopReferenceMode

```
typedef enum OH_TemporalGopReferenceMode OH_TemporalGopReferenceMode
```

**Description**

Defines an enum for the reference modes of temporal image groups.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12

### OH_VVCLevel

```
typedef enum OH_VVCLevel OH_VVCLevel
```

**Description**

Defines an enum for the VVC levels.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 14


### OH_VVCProfile

```
typedef enum OH_VVCProfile OH_VVCProfile
```

**Description**

Defines an enum for the VVC profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 14


### OH_TransferCharacteristic

```
typedef enum OH_TransferCharacteristic OH_TransferCharacteristic
```

**Description**

Defines an enum for the transfer characteristics.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_BitrateMode

```
typedef enum OH_BitrateMode OH_BitrateMode
```

**Description**

Defines an enum for the bit rate modes of an encoder. The key position is changed from API version 14.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OHNativeWindow

```
typedef struct NativeWindow OHNativeWindow
```
**Description**

Defines a struct for a native object for the graphics interface.

**Since**: 9


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

Enumerates the audio channel sets. Each channel number is mapped to a variable of int64_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Deprecated from**: 11

**Substitute**: [OH_AudioChannelSet](_core.md#oh_audiochannelset)

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
| AAC_PROFILE_LC  | AAC profile of the low complexity level.  | 
| AAC_PROFILE_HE  | AAC profile of the high efficiency level. <!--Del-->(This specification is not available yet.)<!--DelEnd--><br>**Since**: 14| 
| AAC_PROFILE_HE_V2 | AAC profile of the high efficiency V2 level. <!--Del-->(This specification is not available yet.)<!--DelEnd--><br>**Since**: 14| 


### OH_AVCLevel

```
enum OH_AVCLevel
```

**Description**

Enumerates the AVC levels.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12

| Value| Description| 
| -------- | -------- |
| AVC_LEVEL_1  | Level 1.  | 
| AVC_LEVEL_1b  | Level 1b.  | 
| AVC_LEVEL_11  | Level 1.1.  | 
| AVC_LEVEL_12  | Level 1.2.  | 
| AVC_LEVEL_13  | Level 1.3.  | 
| AVC_LEVEL_2  | Level 2.  | 
| AVC_LEVEL_21  | Level 2.1.  | 
| AVC_LEVEL_22  | Level 2.2.  | 
| AVC_LEVEL_3  | Level 3.  | 
| AVC_LEVEL_31  | Level 3.1.  | 
| AVC_LEVEL_32  | Level 3.2.  | 
| AVC_LEVEL_4  | Level 4.  | 
| AVC_LEVEL_41  | Level 4.1.  | 
| AVC_LEVEL_42  | Level 4.2.  | 
| AVC_LEVEL_5  | Level 5.  | 
| AVC_LEVEL_51  | Level 5.1.  | 
| AVC_LEVEL_52  | Level 5.2.  | 
| AVC_LEVEL_6  | Level 6.  | 
| AVC_LEVEL_61  | Level 6.1.  | 
| AVC_LEVEL_62  | Level 6.2.  | 


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
| AVC_PROFILE_BASELINE  | AVC baseline profile.  |
| AVC_PROFILE_HIGH  | AVC high profile.  |
| AVC_PROFILE_MAIN  | AVC main profile.  |


### OH_AVOutputFormat

```
enum OH_AVOutputFormat
```

**Description**

Enumerates the output file formats supported by a muxer.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description| 
| -------- | -------- |
| AV_OUTPUT_FORMAT_DEFAULT  | Default format, which is MP4.  | 
| AV_OUTPUT_FORMAT_MPEG_4  | MP4.  | 
| AV_OUTPUT_FORMAT_M4A  | M4A.  | 
| AV_OUTPUT_FORMAT_AMR  | AMR.<br>**Since**: 12   | 
| AV_OUTPUT_FORMAT_MP3  | MP3.<br>**Since**: 12  | 
| AV_OUTPUT_FORMAT_WAV  | WAV.<br>**Since**: 12  | 
| AV_OUTPUT_FORMAT_AAC  | AAC.<br>**Since**: 18  | 

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
| SEEK_MODE_NEXT_SYNC  | Seeks to the next I-frame at the specified position. If there is no I-frame after the specified position, the seek operation may fail.  |
| SEEK_MODE_PREVIOUS_SYNC  | Seeks to the previous I-frame at the specified position.  | 
| SEEK_MODE_CLOSEST_SYNC  | Seeks to the latest I-frame at the specified position.  | 


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
| SAMPLE_U8  | 8-bit unsigned integer sampling.  | 
| SAMPLE_S16LE  | 16-bit signed integer sampling.  | 
| SAMPLE_S24LE  | 24-bit signed integer sampling.  | 
| SAMPLE_S32LE  | 32-bit signed integer sampling.  | 
| SAMPLE_F32LE  | 32-bit floating-point sampling.  | 
| SAMPLE_U8P  | 8-bit unsigned integer plane sampling.  | 
| SAMPLE_S16P  | 16-bit signed integer plane sampling.  | 
| SAMPLE_S24P  | 24-bit signed integer plane sampling.  | 
| SAMPLE_S32P  | 32-bit signed integer plane sampling.  | 
| SAMPLE_F32P  | 32-bit floating-point plane sampling.  | 
| INVALID_WIDTH  | Invalid sampling format.  | 


### OH_ColorPrimary

```
enum OH_ColorPrimary
```

**Description**

Enumerates the primary colors. This enum is used for both encoding and decoding.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description| 
| -------- | -------- |
| COLOR_PRIMARY_BT709  | BT.709 color gamut.  | 
| COLOR_PRIMARY_UNSPECIFIED  | Unspecified color gamut.  | 
| COLOR_PRIMARY_BT470_M  | BT.470 System M color gamut.  | 
| COLOR_PRIMARY_BT601_625  | BT.601 625 color gamut.  | 
| COLOR_PRIMARY_BT601_525  | BT.601 525 color gamut.  | 
| COLOR_PRIMARY_SMPTE_ST240  | SMPTE ST 240 color gamut.  | 
| COLOR_PRIMARY_GENERIC_FILM  | Generic film color gamut.  | 
| COLOR_PRIMARY_BT2020  | BT.2020 color gamut.  | 
| COLOR_PRIMARY_SMPTE_ST428  | SMPTE ST 428 color gamut.  | 
| COLOR_PRIMARY_P3DCI  | DCI-P3 color gamut.  | 
| COLOR_PRIMARY_P3D65  | P3-D65 color gamut.  | 


### OH_HEVCLevel

```
enum OH_HEVCLevel
```

**Description**

Enumerates the HEVC levels.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12

| Value| Description| 
| -------- | -------- |
| HEVC_LEVEL_1  | Level 1.  | 
| HEVC_LEVEL_2  | Level 2.  | 
| HEVC_LEVEL_21  | Level 2.1.  | 
| HEVC_LEVEL_3  | Level 3.  | 
| HEVC_LEVEL_31  | Level 3.1.  | 
| HEVC_LEVEL_4  | Level 4.  | 
| HEVC_LEVEL_41  | Level 4.1.  | 
| HEVC_LEVEL_5  | Level 5.  | 
| HEVC_LEVEL_51  | Level 5.1.  | 
| HEVC_LEVEL_52  | Level 5.2.  | 
| HEVC_LEVEL_6  | Level 6.  | 
| HEVC_LEVEL_61  | Level 6.1.  | 
| HEVC_LEVEL_62  | Level 6.2.  | 


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
| HEVC_PROFILE_MAIN  | HEVC profile of the main level.  | 
| HEVC_PROFILE_MAIN_10  | HEVC profile of the 10-bit main level.  | 
| HEVC_PROFILE_MAIN_STILL  | HEVC profile of the main still picture level.  | 
| HEVC_PROFILE_MAIN_10_HDR10  | HEVC profile of the main 10 HDR10 level. (This value is deprecated from API version 14.)  | 
| HEVC_PROFILE_MAIN_10_HDR10_PLUS  | HEVC profile of the main 10 HDR10+ level. (This value is deprecated from API version 14.)  | 


### OH_MatrixCoefficient

```
enum OH_MatrixCoefficient
```

**Description**

Enumerates the matrix coefficients. This enum is used for both encoding and decoding.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description| 
| -------- | -------- |
| MATRIX_COEFFICIENT_IDENTITY  | Identity matrix.  | 
| MATRIX_COEFFICIENT_BT709  | BT.709 conversion matrix.  | 
| MATRIX_COEFFICIENT_UNSPECIFIED  | Unspecified conversion matrix.  | 
| MATRIX_COEFFICIENT_FCC  | FCC conversion matrix.  | 
| MATRIX_COEFFICIENT_BT601_625  | BT.601 625 conversion matrix.  | 
| MATRIX_COEFFICIENT_BT601_525  | BT.601 525 conversion matrix.  | 
| MATRIX_COEFFICIENT_SMPTE_ST240  | SMPTE ST 240 conversion matrix.  | 
| MATRIX_COEFFICIENT_YCGCO  | YCgCo conversion matrix.  | 
| MATRIX_COEFFICIENT_BT2020_NCL  | BT.2020 NCL conversion matrix.  | 
| MATRIX_COEFFICIENT_BT2020_CL  | BT.2020 CL conversion matrix.  | 
| MATRIX_COEFFICIENT_SMPTE_ST2085  | SMPTE ST 2085 conversion matrix.  | 
| MATRIX_COEFFICIENT_CHROMATICITY_NCL  | Chromaticity NCL conversion matrix.  | 
| MATRIX_COEFFICIENT_CHROMATICITY_CL  | Chromaticity CL conversion matrix.  | 
| MATRIX_COEFFICIENT_ICTCP  | ICTCP conversion matrix.  | 


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
| MEDIA_TYPE_AUD  | Audio track.  | 
| MEDIA_TYPE_VID  | Video track.  | 
| MEDIA_TYPE_SUBTITILE  | Subtitle track.<br>**Since**: 12  |

### OH_MPEG2Level

```
enum OH_MPEG2Level
```

**Description**

Enumerates the MPEG2 levels.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 18

| Value| Description| 
| -------- | -------- |
| MPEG2_LEVEL_LL | Low level.| 
| MPEG2_LEVEL_ML | Main level.| 
| MPEG2_LEVEL_H14 | High 1440 level.| 
| MPEG2_LEVEL_HL | High level.| 


### OH_MPEG2Profile

```
enum OH_MPEG2Profile
```

**Description**

Enumerates the MPEG2 profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 18

| Value| Description| 
| -------- | -------- |
| MPEG2_PROFILE_SIMPLE | Simple profile.| 
| MPEG2_PROFILE_MAIN | Main profile.| 
| MPEG2_PROFILE_SNR | Signal-to-Noise Ratio (SNR) scalable profile.| 
| MPEG2_PROFILE_SPATIAL | Spatial scalable profile.| 
| MPEG2_PROFILE_HIGH | High profile.| 
| MPEG2_PROFILE_422 | 4:2:2 profile.| 


### OH_MPEG4Level

```
enum OH_MPEG4Level
```

**Description**

Enumerates the MPEG4 levels.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 18

| Value| Description| 
| -------- | -------- |
| MPEG4_LEVEL_0 | Level 0.| 
| MPEG4_LEVEL_0B | Level 0B.| 
| MPEG4_LEVEL_1 | Level 1.| 
| MPEG4_LEVEL_2 | Level 2.| 
| MPEG4_LEVEL_3 | Level 3.| 
| MPEG4_LEVEL_3B | Level 3B.| 
| MPEG4_LEVEL_4 | Level 4.| 
| MPEG4_LEVEL_4A | Level 4A.| 
| MPEG4_LEVEL_5 | Level 5.| 
| MPEG4_LEVEL_6 | Level 6.| 


### OH_MPEG4Profile

```
enum OH_MPEG4Profile
```

**Description**

Enumerates the MPEG4 profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 18

| Value| Description| 
| -------- | -------- |
| MPEG4_PROFILE_SIMPLE | Simple profile.| 
| MPEG4_PROFILE_SIMPLE_SCALABLE | Simple scalable profile.| 
| MPEG4_PROFILE_CORE | Core profile.| 
| MPEG4_PROFILE_MAIN | Main profile.| 
| MPEG4_PROFILE_NBIT | N-bit profile.| 
| MPEG4_PROFILE_HYBRID | Hybrid profile.| 
| MPEG4_PROFILE_BASIC_ANIMATED_TEXTURE | Basic animated texture profile.| 
| MPEG4_PROFILE_SCALABLE_TEXTURE | Scalable texture profile.| 
| MPEG4_PROFILE_SIMPLE_FA | Simple FA profile.| 
| MPEG4_PROFILE_ADVANCED_REAL_TIME_SIMPLE | Advanced real-time simple profile.| 
| MPEG4_PROFILE_CORE_SCALABLE | Core scalable profile.| 
| MPEG4_PROFILE_ADVANCED_CODING_EFFICIENCY | Advanced coding efficiency profile.| 
| MPEG4_PROFILE_ADVANCED_CORE | Advanced core profile.| 
| MPEG4_PROFILE_ADVANCED_SCALABLE_TEXTURE | Advanced scalable texture profile.| 
| MPEG4_PROFILE_ADVANCED_SIMPLE | Advanced simple profile.| 


### OH_ScalingMode

```
enum OH_ScalingMode
```

**Description**

Enumerates the scaling modes. This enum is used only in surface mode.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Deprecated from**: 14

**Substitute**: [OHScalingModeV2](../apis-arkgraphics2d/_native_window.md#ohscalingmodev2-1).OH_SCALING_MODE_SCALE_TO_WINDOW_V2
[OHScalingModeV2](../apis-arkgraphics2d/_native_window.md#ohscalingmodev2-1).OH_SCALING_MODE_SCALE_CROP_V2

| Value| Description| 
| -------- | -------- |
| SCALING_MODE_SCALE_TO_WINDOW  | Scales the image based on the window size.| 
| SCALING_MODE_SCALE_CROP  | Crops the image based on the window size.| 



### OH_TemporalGopReferenceMode

```
enum OH_TemporalGopReferenceMode
```

**Description**

Enumerates the reference modes of temporal image groups.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12

| Value| Description| 
| -------- | -------- |
| ADJACENT_REFERENCE  | Refers to the nearest short-term reference frame.  | 
| JUMP_REFERENCE  | Refers to the latest LTR frame.  | 
| UNIFORMLY_SCALED_REFERENCE  | Drops video frames at the highest level, and evenly distributes the remaining frames. The number of temporal image groups must be a power of 2.  | 


### OH_VVCLevel

```
enum OH_VVCLevel
```

**Description**

Enumerates the VVC levels.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 14

| Value| Description| 
| -------- | -------- |
| VVC_LEVEL_1  | Level 1.0. | 
| VVC_LEVEL_2  | Level 2.0. | 
| VVC_LEVEL_21  | Level 2.1. | 
| VVC_LEVEL_3  | Level 3.0. |
| VVC_LEVEL_31  | Level 3.1. |
| VVC_LEVEL_4  | Level 4.0. |
| VVC_LEVEL_41  | Level 4.1. |
| VVC_LEVEL_5  | Level 5.0.  |
| VVC_LEVEL_51  | Level 5.1. |
| VVC_LEVEL_52  | Level 5.2. |
| VVC_LEVEL_6  | Level 6.0. |
| VVC_LEVEL_61  | Level 6.1. |
| VVC_LEVEL_62  | Level 6.2. |
| VVC_LEVEL_63  | Level 6.3. |
| VVC_LEVEL_155  | Level 15.5. |


### OH_VVCProfile

```
enum OH_VVCProfile
```

**Description**

Enumerates the VVC profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 14

| Value| Description| 
| -------- | -------- |
| VVC_PROFILE_MAIN_10 | VVC profile of the 10-bit main level. |
| VVC_PROFILE_MAIN_12 VVC | VVC profile of the 12-bit main level. |
| VVC_PROFILE_MAIN_12_INTRA | VVC profile of the 12-bit intra main level. |
| VVC_PROFILE_MULTI_MAIN_10 | VVC profile of the 10-bit main level for multi-layer encoding. |
| VVC_PROFILE_MAIN_10_444 | VVC profile of the 10-bit full-sample main level. |
| VVC_PROFILE_MAIN_12_444 | VVC profile of the 12-bit full-sample main level. |
| VVC_PROFILE_MAIN_16_444 | VVC profile of the 16-bit full-sample main level. |
| VVC_PROFILE_MAIN_12_444_INTRA | VVC profile of the 12-bit full-sample intra main level. |
| VVC_PROFILE_MAIN_16_444_INTRA | VVC profile of the 16-bit full-sample intra main level. |
| VVC_PROFILE_MULTI_MAIN_10_444 | VVC profile of the 10-bit full-sample main level for multi-layer encoding. |
| VVC_PROFILE_MAIN_10_STILL | VVC profile of the 10-bit still picture main level. |
| VVC_PROFILE_MAIN_12_STILL | VVC profile of the 12-bit still picture main level. |
| VVC_PROFILE_MAIN_10_444_STILL | VVC profile of the 10-bit full-sample still picture main level. |
| VVC_PROFILE_MAIN_12_444_STILL | VVC profile of the 12-bit full-sample still picture main level. |
| VVC_PROFILE_MAIN_16_444_STILL | VVC profile of the 16-bit full-sample still picture main level. |


### OH_TransferCharacteristic

```
enum OH_TransferCharacteristic
```

**Description**

Enumerates the transfer characteristics. This enum can be used for both encoding and decoding.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description| 
| -------- | -------- |
| TRANSFER_CHARACTERISTIC_BT709  | BT.709 transfer function.  | 
| TRANSFER_CHARACTERISTIC_UNSPECIFIED  | Unspecified transfer function.  | 
| TRANSFER_CHARACTERISTIC_GAMMA_2_2  | Gamma 2-2 transfer function.  | 
| TRANSFER_CHARACTERISTIC_GAMMA_2_8  | Gamma 2-8 transfer function.  | 
| TRANSFER_CHARACTERISTIC_BT601  | BT.601 transfer function.  | 
| TRANSFER_CHARACTERISTIC_SMPTE_ST240  | SMPTE ST 240 transfer function.  | 
| TRANSFER_CHARACTERISTIC_LINEAR  | Linear transfer function.  | 
| TRANSFER_CHARACTERISTIC_LOG  | Log transfer function.  | 
| TRANSFER_CHARACTERISTIC_LOG_SQRT  | Log SQRT transfer function.  | 
| TRANSFER_CHARACTERISTIC_IEC_61966_2_4  | IEC61966-2.4 transfer function.  | 
| TRANSFER_CHARACTERISTIC_BT1361  | BT.1361 transfer function.  | 
| TRANSFER_CHARACTERISTIC_IEC_61966_2_1  | IEC61966 2.1 transfer function.  | 
| TRANSFER_CHARACTERISTIC_BT2020_10BIT  | BT.2020 10-bit transfer function.  | 
| TRANSFER_CHARACTERISTIC_BT2020_12BIT  | BT.2020 12-bit transfer function.  | 
| TRANSFER_CHARACTERISTIC_PQ  | PQ transfer function.  | 
| TRANSFER_CHARACTERISTIC_SMPTE_ST428  | SMPTE ST.428 transfer function.  | 
| TRANSFER_CHARACTERISTIC_HLG  | HLG transfer function.  | 


### OH_BitrateMode

```
enum OH_BitrateMode
```

**Description**

Enumerates the bit rate modes of an encoder.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description| 
| -------- | -------- |
| BITRATE_MODE_CBR  | Constant bit rate.  | 
| BITRATE_MODE_VBR  | Variable bit rate. The bit rate is for reference only.  | 
| BITRATE_MODE_CQ  | Constant quality.  | 

## Variable Description


### OH_AVCODEC_MIMETYPE_SUBTITLE_SRT

```
const char* OH_AVCODEC_MIMETYPE_SUBTITLE_SRT
```

**Description**

Pointer to the key that describes the MIME type of the SRT subtitle demuxer.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_AVCODEC_MIMETYPE_SUBTITLE_WEBVTT

```
const char* OH_AVCODEC_MIMETYPE_SUBTITLE_WEBVTT
```

**Description**

Pointer to the key that describes the MIME type of the WEBVTT subtitle demuxer.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_AVCODEC_MIMETYPE_AUDIO_APE

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_APE
```

**Description**

Pointer to the key that describes the MIME type of the APE audio decoder.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_AVCODEC_MIMETYPE_AUDIO_AAC

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_AAC
```

**Description**

Pointer to the key that describes the MIME type of the AAC audio codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_AVCODEC_MIMETYPE_AUDIO_AMR_NB

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_AMR_NB
```

**Description**

Pointer to the key that describes the MIME type of the AMR-NB audio decoder.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 11


### OH_AVCODEC_MIMETYPE_AUDIO_AMR_WB

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_AMR_WB
```

**Description**

Pointer to the key that describes the MIME type of the AMR-WB audio decoder.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 11


### OH_AVCODEC_MIMETYPE_AUDIO_FLAC

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_FLAC
```

**Description**

Pointer to the key that describes the MIME type for FLAC audio codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_AVCODEC_MIMETYPE_AUDIO_G711MU

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_G711MU
```

**Description**

Pointer to the key that describes the MIME type of the G.711 mu-law audio codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 11


### OH_AVCODEC_MIMETYPE_AUDIO_RAW

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_RAW
```

**Description**

Pointer to the key that describes the MIME type of raw audio streams.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 18


### OH_AVCODEC_MIMETYPE_AUDIO_MPEG

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_MPEG
```

**Description**

Pointer to the key that describes the MIME type of the MP3 audio decoder.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_AVCODEC_MIMETYPE_AUDIO_OPUS

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_OPUS
```

**Description**

Pointer to the key that describes the MIME type of the Opus audio codec. <!--Del-->(This specification is not available yet.)<!--DelEnd--> 

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 11


### OH_AVCODEC_MIMETYPE_AUDIO_VIVID

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_VIVID
```

**Description**

Pointer to the key that describes the MIME type of the Audio Vivid audio decoder. <!--Del-->(This specification is not available yet.)<!--DelEnd-->

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 11


### OH_AVCODEC_MIMETYPE_AUDIO_VORBIS

```
const char* OH_AVCODEC_MIMETYPE_AUDIO_VORBIS
```

**Description**

Pointer to the key that describes the MIME type of the Vorbis audio decoder.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_AVCODEC_MIMETYPE_IMAGE_BMP

```
const char* OH_AVCODEC_MIMETYPE_IMAGE_BMP
```

**Description**

Pointer to the key that describes the MIME type of the BMP image encoder, which is used only for muxing BMP covers.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_AVCODEC_MIMETYPE_IMAGE_JPG

```
const char* OH_AVCODEC_MIMETYPE_IMAGE_JPG
```

**Description**

Pointer to the key that describes the MIME type of the JPG image encoder, which is used only for muxing JPG covers.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_AVCODEC_MIMETYPE_IMAGE_PNG

```
const char* OH_AVCODEC_MIMETYPE_IMAGE_PNG
```

**Description**

Pointer to the key that describes the MIME type of the PNG image encoder, which is used only for muxing PNG covers.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_AVCODEC_MIMETYPE_VIDEO_AVC

```
const char* OH_AVCODEC_MIMETYPE_VIDEO_AVC
```

**Description**

Pointer to the key that describes the MIME type of the AVC (H.264) video codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_AVCODEC_MIMETYPE_VIDEO_HEVC

```
const char* OH_AVCODEC_MIMETYPE_VIDEO_HEVC
```

**Description**

Pointer to the key that describes the MIME type of the HEVC (H.265) video codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_AVCODEC_MIMETYPE_VIDEO_VVC

```
const char* OH_AVCODEC_MIMETYPE_VIDEO_VVC
```

**Description**

Pointer to the key that describes the MIME type of the VVC (H.266) video codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_AVCODEC_MIMETYPE_VIDEO_MPEG2

```
const char* OH_AVCODEC_MIMETYPE_VIDEO_MPEG2
```

**Description**

Pointer to the key that describes the MIME type of MPEG2 video codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 18


### OH_AVCODEC_MIMETYPE_VIDEO_MPEG4

```
const char* OH_AVCODEC_MIMETYPE_VIDEO_MPEG4
```

**Description**

Pointer to the key that describes the MIME type of the MPEG4 video encoder, which is used only for muxing MPEG4 video streams.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Deprecated from**: 11


### OH_AVCODEC_MIMETYPE_VIDEO_MPEG4_PART2

```
const char* OH_AVCODEC_MIMETYPE_VIDEO_MPEG4_PART2
```

**Description**

Pointer to the key that describes the MIME type of MPEG4 Part 2 video codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 18


### OH_ED_KEY_EOS

```
const char* OH_ED_KEY_EOS
```

**Description**

Pointer to the key that describes the end of stream for the surface buffer. The value type is int32_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

**Deprecated from**: 14


### OH_ED_KEY_TIME_STAMP

```
const char* OH_ED_KEY_TIME_STAMP
```

**Description**

Pointer to the key that describes the surface buffer timestamp. The value is of the int64_t type.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

**Deprecated from**: 14


### OH_FEATURE_PROPERTY_KEY_VIDEO_ENCODER_MAX_LTR_FRAME_COUNT

```
const char* OH_FEATURE_PROPERTY_KEY_VIDEO_ENCODER_MAX_LTR_FRAME_COUNT
```

**Description**

Pointer to the key that describes the maximum number of LTR frames obtained during video encoding. The value type is int32_t.

You can use the API [OH_AVCapability_GetFeatureProperties](_a_v_capability.md#oh_avcapability_getfeatureproperties) and the enum [VIDEO_ENCODER_LONG_TERM_REFERENCE](_a_v_capability.md#oh_avcapabilityfeature-1) to query the maximum number.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_AAC_IS_ADTS

```
const char* OH_MD_KEY_AAC_IS_ADTS
```

**Description**

Pointer to the key that describes the AAC format, which can be ADTS or LATM. The value type is int32_t. The value **0** means the LATM format, and **1** means the ADTS format. This key is supported by AAC decoders.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_ALBUM

```
const char* OH_MD_KEY_ALBUM
```

**Description**

Pointer to the key that describes the album in a media file. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_ALBUM_ARTIST

```
const char* OH_MD_KEY_ALBUM_ARTIST
```

**Description**

Pointer to the key that describes the album artist in a media file. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_ARTIST

```
const char* OH_MD_KEY_ARTIST
```

**Description**

Pointer to the key that describes lyrics in a media file. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_AUD_CHANNEL_COUNT

```
const char* OH_MD_KEY_AUD_CHANNEL_COUNT
```

**Description**

Pointer to the key that describes the number of audio channels. The value type is int32_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_AUD_SAMPLE_RATE

```
const char* OH_MD_KEY_AUD_SAMPLE_RATE
```

**Description**

Pointer to the key that describes the audio sampling rate. The value type is int32_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_AUDIO_COMPRESSION_LEVEL

```
const char* OH_MD_KEY_AUDIO_COMPRESSION_LEVEL
```

**Description**

Pointer to the key that describes the audio codec compression level. The value type is int32_t type. This key is used only for audio encoding.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 11


### OH_MD_KEY_AUDIO_OBJECT_NUMBER

```
const char* OH_MD_KEY_AUDIO_OBJECT_NUMBER
```

**Description**

Pointer to the key that describes the number of audio objects. The value type is int32_t. This key is used only for Audio Vivid decoding.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 11


### OH_MD_KEY_AUDIO_SAMPLE_FORMAT

```
const char* OH_MD_KEY_AUDIO_SAMPLE_FORMAT
```

**Description**

Pointer to the key that describes the original audio format. The value type is int32_t. For details, see [OH_BitsPerSample](#oh_bitspersample-1).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_AUDIO_VIVID_METADATA

```
const char* OH_MD_KEY_AUDIO_VIVID_METADATA
```

**Description**

Pointer to the key that describes the Audio Vivid metadata. The value type is uint8_t\*. This key is used only for Audio Vivid decoding.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 11


### OH_MD_KEY_BITRATE

```
const char* OH_MD_KEY_BITRATE
```

**Description**

Pointer to the key that describes the bit rate. The value type is int64_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_BITS_PER_CODED_SAMPLE

```
const char* OH_MD_KEY_BITS_PER_CODED_SAMPLE
```

**Description**

Pointer to the key that describes the number of bits for each coded sample. The value type is int32_t. This key applies to FLAC encoders. For details, see [OH_BitsPerSample](#oh_bitspersample-1).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_CHANNEL_LAYOUT

```
const char* OH_MD_KEY_CHANNEL_LAYOUT
```

**Description**

Pointer to the key that describes the required encoding channel layout. The value type is int64_t. This key applies only to encoders.
For details, see [OH_AudioChannelLayout](_core.md#oh_audiochannellayout-1).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_CODEC_CONFIG

```
const char* OH_MD_KEY_CODEC_CONFIG
```

**Description**

Pointer to the key that describes the codec-specific data. In the case of video, data carried in **SPS/PPS** is transferred. In the case of audio, data carried in **extraData** is transferred. The value type is uint8_t\*. <!--Del-->(This key is not supported yet for the video codec.)<!--DelEnd-->

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_CODEC_MIME

```
const char* OH_MD_KEY_CODEC_MIME
```

**Description**

Pointer to the key that describes the [MIME](#media-codec-formats) type of the codec. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_COLOR_PRIMARIES

```
const char* OH_MD_KEY_COLOR_PRIMARIES
```

**Description**

Pointer to the key that describes the video primary color. The value type is int32_t. For details, see [OH_ColorPrimary](#oh_colorprimary). The video primary color complies with Table 2 in the H.273 standard.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_COMMENT

```
const char* OH_MD_KEY_COMMENT
```

**Description**

Pointer to the key that describes the comment in a media file. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_COMPLIANCE_LEVEL

```
const char* OH_MD_KEY_COMPLIANCE_LEVEL
```

**Description**

Pointer to the key that describes the FLAC compliance level. The value type is int32_t. This key is used only for audio encoding.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_COPYRIGHT

```
const char* OH_MD_KEY_COPYRIGHT
```

**Description**

Pointer to the key that describes the copyright in a media file. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_DATE

```
const char* OH_MD_KEY_DATE
```

**Description**

Pointer to the key that describes the date in a media file, for example, 2024. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_DESCRIPTION

```
const char* OH_MD_KEY_DESCRIPTION
```

**Description**

Pointer to the key that describes the description in a media file. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_DURATION

```
const char* OH_MD_KEY_DURATION
```

**Description**

Pointer to the key that describes the duration in a media file, in microseconds. The value type is int64_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_FRAME_RATE

```
const char* OH_MD_KEY_FRAME_RATE
```

**Description**

Pointer to the key that describes the video frame rate. The value type is double. The value must be greater than **0**.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_GENRE

```
const char* OH_MD_KEY_GENRE
```

**Description**

Pointer to the key that describes the genre in a media file. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_HEIGHT

```
const char* OH_MD_KEY_HEIGHT
```

**Description**

Pointer to the key that describes the video height. The value type is int32_t.

For details about the development guide, see step 5 in surface mode or step 4 in buffer mode in [Video Encoding](../../media/avcodec/video-encoding.md).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_I_FRAME_INTERVAL

```
const char* OH_MD_KEY_I_FRAME_INTERVAL
```

**Description**

Pointer to the key that describes the key frame interval, in milliseconds. The value type is int32_t. This key is optional and is used only for video encoding.

A negative value indicates that only the first frame is a key frame, and a zero value indicates that all frames are key frames.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_IDENTIFICATION_HEADER

```
const char* OH_MD_KEY_IDENTIFICATION_HEADER
```

**Description**

Pointer to the key that describes the Vorbis identification header. The value type is uint8_t. This key applies only to Vorbis decoders.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_LANGUAGE

```
const char* OH_MD_KEY_LANGUAGE
```

**Description**

Pointer to the key that describes the language in a media file. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_LYRICS

```
const char* OH_MD_KEY_LYRICS
```

**Description**

Pointer to the key that describes the lyrics in a media file. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_MATRIX_COEFFICIENTS

```
const char* OH_MD_KEY_MATRIX_COEFFICIENTS
```

**Description**

Pointer to the key that describes the video matrix coefficient. The value type is int32_t. For details, see [OH_MatrixCoefficient](#oh_matrixcoefficient). The video matrix coefficient complies with Table 4 in the H.273 standard.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_MAX_INPUT_SIZE

```
const char* OH_MD_KEY_MAX_INPUT_SIZE
```

**Description**

Pointer to the key that describes the maximum size of an input stream to decode. The value type is int32_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_PIXEL_FORMAT

```
const char* OH_MD_KEY_PIXEL_FORMAT
```

**Description**

Pointer to the key that describes the video pixel format. The value type is int32_t. For details, see [OH_AVPixelFormat](_core.md#oh_avpixelformat).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_PROFILE

```
const char* OH_MD_KEY_PROFILE
```

**Description**

Pointer to the key that describes the encoding grading. The value type is int32_t. For details, see [OH_AVCProfile](#oh_avcprofile), [OH_HEVCProfile](#oh_hevcprofile), and [OH_AACProfile](#oh_aacprofile).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_QUALITY

```
const char* OH_MD_KEY_QUALITY
```

**Description**

Pointer to the key that describes the required encoding quality. The value type is int32_t. In H.264 and H.265 encoding scenarios, the value range can be obtained by calling **OH_AVCapability_GetEncoderQualityRange()**. This key applies only to the encoder in constant quality mode.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_RANGE_FLAG

```
const char* OH_MD_KEY_RANGE_FLAG
```

**Description**

Pointer to the key that describes the video YUV value range flag. The value type is int32_t. The value **1** means a full range, and **0** means a limited range.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_REQUEST_I_FRAME

```
const char* OH_MD_KEY_REQUEST_I_FRAME
```

**Description**

Pointer to the key that describes the request for immediate encoding of I-frames. The value type is int32_t. This key is used in **OH_VideoEncoder_SetParameter()** or takes effect immediately with the frame.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_ROTATION

```
const char* OH_MD_KEY_ROTATION
```

**Description**

Pointer to the key that describes the rotation angle of the surface. The value type is int32_t, and the value range is {0, 90, 180, 270}. The default value is 0. This key is used only in video decoding surface mode.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_SBR

```
const char* OH_MD_KEY_SBR
```

**Description**

Pointer to the key that describes the AAC SBR format. The value type is int32_t. This key applies to AAC encoders.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_SCALING_MODE

```
const char* OH_MD_KEY_SCALING_MODE
```

**Description**

Pointer to the key that describes the video scaling mode. The value type is int32_t. For details, see [OH_ScalingMode](#oh_scalingmode). You are advised to set the scaling mode by calling [OH_NativeWindow_NativeWindowSetScalingModeV2](../apis-arkgraphics2d/_native_window.md#oh_nativewindow_nativewindowsetscalingmodev2). This key is optional and is used only for video decoding in surface mode.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Deprecated from**: 14

**Substitute**: [OH_NativeWindow_NativeWindowSetScalingModeV2](../apis-arkgraphics2d/_native_window.md#oh_nativewindow_nativewindowsetscalingmodev2)


### OH_MD_KEY_SETUP_HEADER

```
const char* OH_MD_KEY_SETUP_HEADER
```

**Description**

Pointer to the key that describes the Vorbis setup header. The value type is uint8_t. This key applies only to Vorbis decoders.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_TITLE

```
const char* OH_MD_KEY_TITLE
```

**Description**

Pointer to the key that describes the title in a media file. The value type is string.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_TRACK_COUNT

```
const char* OH_MD_KEY_TRACK_COUNT
```

**Description**

Pointer to the key that describes the number of tracks in a media file. The value type is int32_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_TRACK_TYPE

```
const char* OH_MD_KEY_TRACK_TYPE
```

**Description**

Pointer to the key that describes the track type in a media file. The value type is int32_t. For details, see [OH_MediaType](#oh_mediatype-1).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_KEY_TRANSFER_CHARACTERISTICS

```
const char* OH_MD_KEY_TRANSFER_CHARACTERISTICS
```

**Description**

Pointer to the key that describes the video transfer characteristics. The value type is int32_t. For details, see [OH_TransferCharacteristic](#oh_transfercharacteristic). The video transfer characteristics comply with Table 3 in the H.273 standard.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

### OH_MD_KEY_VIDEO_CROP_BOTTOM

```
const char* OH_MD_KEY_VIDEO_CROP_BOTTOM
```

**Description**

Pointer to the key that describes the bottom coordinate (y) of the cropped rectangle. The value type is int32_t. The row at the bottom of the cropped rectangle is contained, and the row index starts from 0. This key is used only for video decoding.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_VIDEO_CROP_LEFT

```
const char* OH_MD_KEY_VIDEO_CROP_LEFT
```

**Description**

Pointer to the key that describes the left coordinate (x) of the cropped rectangle. The value type is int32_t. The leftmost column of the cropped rectangle is contained, and the column index starts from 0. This key is used only for video decoding.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_VIDEO_CROP_RIGHT

```
const char* OH_MD_KEY_VIDEO_CROP_RIGHT
```

**Description**

Pointer to the key that describes the right coordinate (x) of the cropped rectangle. The value type is int32_t. The rightmost column of the cropped rectangle is contained, and the column index starts from 0. This key is used only for video decoding.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_VIDEO_CROP_TOP

```
const char* OH_MD_KEY_VIDEO_CROP_TOP
```

**Description**

Pointer to the key that describes the top coordinate (y) of the cropped rectangle. The value type is int32_t. The row at the top of the cropped rectangle is contained, and the row index starts from 0. This key is used only for video decoding.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_VIDEO_ENABLE_LOW_LATENCY

```
const char* OH_MD_KEY_VIDEO_ENABLE_LOW_LATENCY
```

**Description**

Pointer to the key that describes the enabled status of low-latency video codec. The value type is int32_t. The value **1** means that low-latency video codec is enabled, and **0** means the opposite.

If enabled, the input and output data held by the video encoder or decoder does not exceed the amount required by the codec standard.

This key is optional and used only in the configuration phase.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE

```
const char* OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE
```

**Description**

Pointer to the key that describes the video encoding bit rate mode. The value type is int32_t. For details, see [OH_BitrateMode](#oh_bitratemode-1).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

### OH_MD_KEY_VIDEO_ENCODER_ENABLE_TEMPORAL_SCALABILITY

```
const char* OH_MD_KEY_VIDEO_ENCODER_ENABLE_TEMPORAL_SCALABILITY
```

**Description**

Pointer to the key that describes the enabled status of temporal scalability. The value type is int32_t. The value **1** means temporal scalability is enabled, and **0** means the opposite.

Before using this variable, you can call [OH_AVCapability_IsFeatureSupported](_a_v_capability.md#oh_avcapability_isfeaturesupported) and use [VIDEO_ENCODER_TEMPORAL_SCALABILITY](_a_v_capability.md#oh_avcapabilityfeature-1) to check whether the video encoder supports temporal scalability.

For details, see [Temporally Scalable Video Coding](../../media/avcodec/video-encoding-temporal-scalability.md#available-apis).

This key is optional and used only in the configuration phase of video encoding.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_VIDEO_ENCODER_LTR_FRAME_COUNT

```
const char* OH_MD_KEY_VIDEO_ENCODER_LTR_FRAME_COUNT
```
**Description**

Pointer to the key that describes the number of LTR frames. The value type is int32_t. The value must be within the supported value range.

Before using this key, you can use the API [OH_AVCapability_GetFeatureProperties](_a_v_capability.md#oh_avcapability_getfeatureproperties) and the enum [VIDEO_ENCODER_LONG_TERM_REFERENCE](_a_v_capability.md#oh_avcapabilityfeature-1) to query the number of supported LTR frames.

This key is optional and used only in the configuration phase of video encoding.

For details, see [Temporally Scalable Video Coding](../../media/avcodec/video-encoding-temporal-scalability.md#available-apis-1).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_MARK_LTR

```
const char* OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_MARK_LTR
```
**Description**

Pointer to the key that describes the key that marks the current frame as an LTR frame. The value type is int32_t. The value **1** means that the frame is marked as an LTR frame, and **0** means the opposite.

This key takes effect only after the number of LTR frames is configured.

This key is optional and is used only for video encoding input rotation. The configuration takes effect immediately.

For details, see [Temporally Scalable Video Coding](../../media/avcodec/video-encoding-temporal-scalability.md#available-apis-1).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_USE_LTR

```
const char* OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_USE_LTR
```
**Description**

Pointer to the key that describes the POC number of the LTR frame referenced by the current frame. The value type is int32_t.

This key is optional and is used only for video encoding input rotation. The configuration takes effect immediately.

For details, see [Temporally Scalable Video Coding](../../media/avcodec/video-encoding-temporal-scalability.md#available-apis-1).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_VIDEO_ENCODER_QP_MAX

```
const char* OH_MD_KEY_VIDEO_ENCODER_QP_MAX
```

**Description**

Pointer to the key that describes the maximum QP allowed by the video encoder. The value type is int32_t.

This key is used in the configuration or parameter setting phase or takes effect immediately with the frame.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_VIDEO_ENCODER_QP_MIN

```
const char* OH_MD_KEY_VIDEO_ENCODER_QP_MIN
```

**Description**

Pointer to the key that describes the minimum QP allowed by the video encoder. The value type is int32_t.

This key is used in the configuration or parameter setting phase or takes effect immediately with the frame.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_VIDEO_ENCODER_QP_AVERAGE

```
const char* OH_MD_KEY_VIDEO_ENCODER_QP_AVERAGE
```

**Description**

Pointer to the key that describes the average QP of video frames. The value type is int32_t.

Pointer to the key that describes the average QP value of the current frame encoding block. It is output with [OH_AVBuffer](_core.md#oh_avbuffer)

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_VIDEO_ENCODER_MSE

```
const char* OH_MD_KEY_VIDEO_ENCODER_MSE
```

**Description**

Pointer to the key that describes the MSE of video frames. The value type is double.

Pointer to the key that describes the average MSE value of the current frame encoding block. It is output with [OH_AVBuffer](_core.md#oh_avbuffer)

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_REFERENCE_MODE

```
const char* OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_REFERENCE_MODE
```

**Description**

Pointer to the key that describes the reference mode in a temporal image group. The value type is int32_t. For details, see [OH_TemporalGopReferenceMode](#oh_temporalgopreferencemode). This key is valid only when temporal scalability is enabled.

This key is optional and used only in the configuration phase of video encoding.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_SIZE

```
const char* OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_SIZE
```

**Description**

Pointer to the key that describes the size of a temporal image group. The value type is int32_t. This key is valid only when temporal scalability is enabled.

This key is optional and used only in the configuration phase of video encoding.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_VIDEO_IS_HDR_VIVID

```
const char* OH_MD_KEY_VIDEO_IS_HDR_VIVID
```

**Description**

Pointer to the key that describes whether the video track in a media file is HDR Vivid. The value type is int32_t. This key is used for both muxing and demuxing.

The value **1** means the HDR Vivid video track, and **0** means other cases.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 11


### OH_MD_KEY_DECODING_TIMESTAMP

```
const char* OH_MD_KEY_DECODING_TIMESTAMP
```

**Description**

Pointer to the key that describes the decoding timestamp corresponding to the audio, video, or subtitle sample carried in AVBuffer, in microseconds. The value type is int64_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_BUFFER_DURATION

```
const char* OH_MD_KEY_BUFFER_DURATION
```

**Description**

Pointer to the key that describes the duration corresponding to the audio, video, or subtitle sample carried in AVBuffer, in microseconds. The value type is int64_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_START_TIME

```
const char* OH_MD_KEY_START_TIME
```

**Description**

Pointer to the key that describes the start time of the first frame in a media file, measured in microseconds. The value type is int64_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12

### OH_MD_KEY_TRACK_START_TIME

```
const char* OH_MD_KEY_TRACK_START_TIME
```

**Description**

Pointer to the key that describes the start time of the track, measured in microseconds. The value type is int64_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_VIDEO_DECODER_OUTPUT_COLOR_SPACE

```
const char* OH_MD_KEY_VIDEO_DECODER_OUTPUT_COLOR_SPACE
```

**Description**

Pointer to the key that describes the output color space of the video decoder. The value type is int32_t.

The supported value is **OH_COLORSPACE_BT709_LIMIT**. For details, see [OH_NativeBuffer_ColorSpace](../../reference/apis-arkgraphics2d/_o_h___native_buffer.md#oh_nativebuffer_colorspace-1).

It is used when [OH_VideoDecoder_Configure](_video_decoder.md#oh_videodecoder_configure) is called.

If Color Space Conversion (CSC) is supported and this key is configured, the video decoder automatically transcodes the HDR Vivid video to the BT.709 SDR video.

If CSC function not supported, the error code [AV_ERR_VIDEO_UNSUPPORTED_COLOR_SPACE_CONVERSION](_core.md#oh_averrcode-1) is returned when [OH_VideoDecoder_Configure](_video_decoder.md#oh_videodecoder_configure) is called.

If the input video is not an HDR Vivid video, the callback function [OH_AVCodecOnError](#oh_avcodeconerror) is invoked to report the error code [AV_ERR_VIDEO_UNSUPPORTED_COLOR_SPACE_CONVERSION](_core.md#oh_averrcode-1).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_VIDEO_PER_FRAME_IS_LTR

```
const char* OH_MD_KEY_VIDEO_PER_FRAME_IS_LTR
```
**Description**

Pointer to the key that describes the key that specifies whether the frame corresponding to the stream output from the current OH_AVBuffer is marked as an LTR frame. The value type is int32_t. The value **1** means that the frame is an LTR frame, and **0** means the opposite.

This key is optional and is used only for video encoding output rotation.

It indicates the attribute of a frame.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_VIDEO_PER_FRAME_POC

```
const char* OH_MD_KEY_VIDEO_PER_FRAME_POC
```
**Description**

Pointer to the key that describes the POC number of the frame. The value type is int32_t.

This key is optional and is used only for video encoding output rotation.

It indicates the attribute of a frame.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_VIDEO_PIC_HEIGHT

```
const char* OH_MD_KEY_VIDEO_PIC_HEIGHT
```

**Description**

Pointer to the key that describes the height of the video frame. The value type is int32_t.

When [OH_VideoDecoder_GetOutputDescription](_video_decoder.md#oh_videodecoder_getoutputdescription) is called during video decoding, the height can be parsed from the returned **OH_AVFormat** instance.

When the decoded output stream<!--RP2--><!--RP2End--> changes, the height can be parsed from the **OH_AVForamt** instance returned by [OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_VIDEO_PIC_WIDTH

```
const char* OH_MD_KEY_VIDEO_PIC_WIDTH
```

**Description**

Pointer to the key that describes the width of the video frame. The value type is int32_t.

When [OH_VideoDecoder_GetOutputDescription](_video_decoder.md#oh_videodecoder_getoutputdescription) is called during video decoding, the width can be parsed from the returned **OH_AVFormat** instance.

When the decoded output stream<!--RP2--><!--RP2End--> changes, the width can be parsed from the **OH_AVForamt** instance returned by [OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_VIDEO_SLICE_HEIGHT

```
const char* OH_MD_KEY_VIDEO_SLICE_HEIGHT
```
**Description**

Pointer to the key that describes the height of the video frame. The value type is int32_t.

The height is the number of rows that must be offset from the top of the Y plane to the top of the U plane. Essentially, the offset of the U plane is sliceHeight \* stride.

The height of the U/V plane can be calculated based on the color format, but it is usually not defined and depends on the device and version.

For details, see step 3 in buffer mode in [Video Encoding](../../media/avcodec/video-encoding.md).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_VIDEO_STRIDE

```
const char* OH_MD_KEY_VIDEO_STRIDE
```
**Description**

Pointer to the key that describes the stride of the video frame. The value type is int32_t.

The stride is the difference between the index of the pixel and the index of the pixel right below.

For the YUV420 format, the stride corresponds to the Y plane. The stride of the U/V plane can be calculated based on the color format, but it is usually not defined and depends on the device and version.

For details, see step 3 in buffer mode in [Video Encoding](../../media/avcodec/video-encoding.md).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_WIDTH

```
const char* OH_MD_KEY_WIDTH
```

**Description**

Pointer to the key that describes the video width. The value type is int32_t.

For details about the development guide, see step 5 in surface mode or step 4 in buffer mode in [Video Encoding](../../media/avcodec/video-encoding.md).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


### OH_MD_MAX_INPUT_BUFFER_COUNT

```
const char* OH_MD_MAX_INPUT_BUFFER_COUNT
```

**Description**

Pointer to the key that describes the maximum number of input buffers. The value type is int32_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_MAX_OUTPUT_BUFFER_COUNT

```
const char* OH_MD_MAX_OUTPUT_BUFFER_COUNT
```

**Description**

Pointer to the key that describes the maximum number of output buffers. The value type is int32_t.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10


### OH_MD_KEY_VIDEO_SAR

```
const char* OH_MD_KEY_VIDEO_SAR
```

**Description**

Pointer to the key that describes the aspect ratio of the sample. The value type is double.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### OH_MD_KEY_CREATION_TIME

```
const char* OH_MD_KEY_CREATION_TIME
```

**Description**

Pointer to the key that describes the media file creation time. The value type is string. The value must be in the UTC time format complying with ISO 8601. An example time format is 2024-12-28T00:00:00:000000Z.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 14

### OH_MD_KEY_VIDEO_DECODER_OUTPUT_ENABLE_VRR

```
const char* OH_MD_KEY_VIDEO_DECODER_OUTPUT_ENABLE_VRR
```

**Description**

Pointer to the key that specifies whether the decoder enables the video variable frame rate feature. The value type is int32_t. The value **1** means that the video variable frame rate feature is enabled, and **0** means the opposite.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 15

### OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER

```
const char* OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER
```

**Description**

Pointer to the key that specifies the duration (in milliseconds) for which the last frame will be resubmitted repeatedly, if no new frame is available after the previous frame is submitted to the encoder. The value type is int32_t.

This key is used only in the configuration phase of video encoding in surface mode.

| Value| Description| 
| -------- | -------- |
| Less than or equal to 0| The request is intercepted in the configuration phase and **ERROR AV_ERR_INVALID_VAL** is returned. |
| Greater than 0|  The last frame will be resubmitted repeatedly in the specified duration, measured in milliseconds.|

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 18


### OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_MAX_COUNT

```
const char* OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_MAX_COUNT
```

**Description**

Pointer to the key that describes the maximum number of times the encoder can repeat encoding the previous frame when no new frame is available. The value type is int32_t.

This key takes effect only when [OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER](#oh_md_key_video_encoder_repeat_previous_frame_after) is available and is used only in the configuration phase.

| Value| Description| 
| -------- | -------- |
| 0  | The request is intercepted in the configuration phase and **ERROR AV_ERR_INVALID_VAL** is returned. |
| Less than 0| If no new frame is available, the encoder repeatedly encodes the previous frame until the upper limit of the system is reached. | 
| Greater than 0|  If no new frame is available, the encoder repeatedly encodes the previous frame until the maximum number specified is reached.|

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 18
