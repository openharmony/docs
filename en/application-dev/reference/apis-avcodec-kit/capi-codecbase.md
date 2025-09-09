# CodecBase

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @mr-chencxy-->
<!--Designer: @dpy2650--->
<!--Tester: @baotianhao-->
<!--Adviser: @zengyawen-->

## Overview

The CodecBase module provides the variables, attributes, and functions for basic audio and video multiplexing, demultiplexing, encoding, and decoding.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

## Files

| Name| Description|
| -- | -- |
| [avcodec_audio_channel_layout.h](capi-avcodec-audio-channel-layout-h.md) | Declares the enums used for audio encoding and decoding.|
| [native_avcodec_base.h](capi-native-avcodec-base-h.md) | Declares the native APIs used for basic audio and video multiplexing, demultiplexing, encoding, and decoding.|

## Media Codec Formats

The table below lists the media codec formats. The type is a constant string.

| Name                                                        | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------ |
| OH_AVCODEC_MIMETYPE_AUDIO_AAC | MIME type of the AAC audio codec.                           |
| OH_AVCODEC_MIMETYPE_AUDIO_FLAC | MIME type of the FLAC audio codec.                          |
| OH_AVCODEC_MIMETYPE_AUDIO_OPUS | MIME type of the Opus audio codec. <!--Del-->(This specification is not available yet.)<!--DelEnd-->        |
| OH_AVCODEC_MIMETYPE_AUDIO_G711MU | MIME type of the G.711 mu-law audio codec.                        |
| OH_AVCODEC_MIMETYPE_AUDIO_G711A | MIME type of the G.711 a-law audio decoder.                        |
| OH_AVCODEC_MIMETYPE_AUDIO_RAW | MIME type of raw audio streams.                        |
| OH_AVCODEC_MIMETYPE_AUDIO_VORBIS | MIME type of the Vorbis audio decoder.                          |
| OH_AVCODEC_MIMETYPE_AUDIO_MPEG | MIME type of the MP3 audio codec.                             |
| OH_AVCODEC_MIMETYPE_AUDIO_VIVID | MIME type of the Audio Vivid audio decoder. <!--Del-->(This specification is not available yet.)<!--DelEnd-->     |
| OH_AVCODEC_MIMETYPE_AUDIO_AMR_NB | MIME type of the AMR-NB audio decoder.                          |
| OH_AVCODEC_MIMETYPE_AUDIO_AMR_WB | MIME type of the AMR-WB audio decoder.                          |
| OH_AVCODEC_MIMETYPE_AUDIO_APE |MIME type of the APE audio decoder.                        |
| OH_AVCODEC_MIMETYPE_VIDEO_VVC | MIME type of the VVC (H.266) video codec.                   |
| OH_AVCODEC_MIMETYPE_VIDEO_HEVC | MIME type of the HEVC (H.265) video codec.                   |
| OH_AVCODEC_MIMETYPE_VIDEO_AVC | MIME type of the AVC (H.264) video codec.                    |
| OH_AVCODEC_MIMETYPE_VIDEO_H263 | MIME type of the H.263 video codec.                    |
| OH_AVCODEC_MIMETYPE_VIDEO_MPEG4 | MIME type of the MPEG4 video encoder, which is used only for multiplexing MPEG4 video streams. (It is deprecated from API version 11.)|
| OH_AVCODEC_MIMETYPE_VIDEO_MPEG4_PART2 | MIME type of the MPEG4 Part 2 video codec.|
| OH_AVCODEC_MIMETYPE_VIDEO_MPEG2 | MIME type of the MPEG2 video codec.|
| OH_AVCODEC_MIMETYPE_IMAGE_JPG | MIME type of the JPG image encoder, which is used only for multiplexing JPG covers.      |
| OH_AVCODEC_MIMETYPE_IMAGE_PNG | MIME type of the PNG image encoder, which is used only for multiplexing PNG covers.      |
| OH_AVCODEC_MIMETYPE_IMAGE_BMP | MIME type of the BMP image encoder, which is used only for multiplexing BMP covers.      |
| OH_AVCODEC_MIMETYPE_SUBTITLE_WEBVTT |MIME type of the WEBVTT subtitle demuxer.                        |
| OH_AVCODEC_MIMETYPE_SUBTITLE_SRT |MIME type of the SRT subtitle demuxer.                        |

## Media Data Key-Value Pairs

The tables below list the key-value pairs used to describe media data. The key type is a constant string, and the value type can be int32_t, int64_t, float, double, char *, or uint8_t *.

The [OH_AVFormat](_core.md#functions) API is used to configure or query parameters.

### Key-Value Pairs Dedicated for Capability Query

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_FEATURE_PROPERTY_KEY_VIDEO_ENCODER_MAX_LTR_FRAME_COUNT     | Maximum number of long-term reference (LTR) frames obtained during video encoding. The value type is int32_t.|

### Common Key-value Pairs of Audio and Video

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_MD_KEY_CODEC_CONFIG           | Codec-specific data. In the case of video, data carried in **SPS/PPS** is transferred. In the case of audio, data carried in **extraData** is transferred. The value type is uint8_t\*. This key is optional. <!--Del-->(This key is not supported yet for the video codec.)<!--DelEnd--> |
| OH_MD_MAX_INPUT_BUFFER_COUNT | Maximum number of input buffers. The value type is int32_t. This key is optional.     |
| OH_MD_MAX_OUTPUT_BUFFER_COUNT | Maximum number of output buffers. The value type is int32_t. This key is optional.       |
| OH_MD_KEY_BITRATE                      | Bit rate. The value type is int64_t. This key is used in audio and video encoding scenarios. It is optional in video encoding scenarios.|
| OH_MD_KEY_PROFILE                     | Encoding grading. The value type is int32_t. For details, see [OH_AVCProfile](capi-native-avcodec-base-h.md#oh_avcprofile), [OH_HEVCProfile](capi-native-avcodec-base-h.md#oh_hevcprofile), and [OH_AACProfile](capi-native-avcodec-base-h.md#oh_aacprofile). This key is optional.|
| OH_MD_KEY_MAX_INPUT_SIZE        | Maximum size of an input stream to decode. The value type is int32_t. This key is optional.          |

### Key-Value Pairs Dedicated for Video

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_ED_KEY_TIME_STAMP               | Surface buffer timestamp. The value is of the int64_t type. This key is optional. (It is deprecated from API version 14.)|
| OH_ED_KEY_EOS                         | End of stream for the surface buffer. The value type is int32_t. This key is optional. (It is deprecated from API version 14.)|
| OH_MD_KEY_WIDTH                          | Video width. The value type is int32_t.                            |
| OH_MD_KEY_HEIGHT                        | Video height. The value type is int32_t.                              |
| OH_MD_KEY_PIXEL_FORMAT            | Video pixel format. The value type is int32_t. For details, see [OH_AVPixelFormat](_core.md#oh_avpixelformat).|
| OH_MD_KEY_FRAME_RATE                | Video frame rate. The value type is double. This key is optional.                |
| OH_MD_KEY_RANGE_FLAG           | Video YUV value range flag. The value type is int32_t. The value **1** means a full range, and **0** means a limited range. This key is optional.|
| OH_MD_KEY_COLOR_PRIMARIES      | Video primary colors. The value type is int32_t. For details, see [OH_ColorPrimary](capi-native-avcodec-base-h.md#oh_colorprimary). The value complies with Table 2 in H.273. This key is optional.|
| OH_MD_KEY_TRANSFER_CHARACTERISTICS | Video transfer characteristics. The value type is int32_t. For details, see [OH_TransferCharacteristic](capi-native-avcodec-base-h.md#oh_transfercharacteristic). The value complies with Table 3 in H.273. This key is optional.|
| OH_MD_KEY_MATRIX_COEFFICIENTS | Video matrix coefficients. The value type is int32_t. For details, see [OH_MatrixCoefficient](capi-native-avcodec-base-h.md#oh_matrixcoefficient). The value complies with Table 4 in H.273. This key is optional.|
| OH_MD_KEY_VIDEO_STRIDE       | Stride of the video frame. The value type is int32_t. This key is optional.       |
| OH_MD_KEY_VIDEO_SLICE_HEIGHT    | Height of the video frame. The value type is int32_t. This key is optional.       |
| OH_MD_KEY_VIDEO_PIC_WIDTH       | Width of the video frame. The value type is int32_t. This key is optional.       |
| OH_MD_KEY_VIDEO_PIC_HEIGHT    | Height of the video frame. The value type is int32_t. This key is optional.       |
| OH_MD_KEY_VIDEO_ENABLE_LOW_LATENCY  | Enabled status of low-latency video codec. The value type is int32_t. **1** if enabled, **0** otherwise. This key is optional and used only in the configuration phase.|
| OH_MD_KEY_ENABLE_SYNC_MODE   | Enabled status of video codec synchronization. The value type is int32_t. **1** if enabled, **0** otherwise. This key is optional and used only in the configuration phase.|
| OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE | Video encoding bit rate mode. The value type is int32_t. For details, see [OH_BitrateMode](capi-native-avcodec-base-h.md#oh_bitratemode). This key is optional.|
| OH_MD_KEY_QUALITY                      | Required encoding quality. The value type is int32_t. This key applies only to encoders configured in constant quality mode. This key is optional.|
| OH_MD_KEY_REQUEST_I_FRAME      | Request for immediate encoding of I-frames. The value type is int32_t. This key is optional.           |
| OH_MD_KEY_I_FRAME_INTERVAL   | Key frame interval, in milliseconds. The value type is int32_t. This key is optional and is used only for video encoding.|
| OH_MD_KEY_VIDEO_ENCODER_ENABLE_TEMPORAL_SCALABILITY         | Enabled status of temporal scalability. The value type is int32_t. **1** if enabled, **0** otherwise. This key is optional and used only in the configuration phase of video encoding.|
| OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_SIZE       | Size of a temporal image group. The value type is int32_t. This key is valid only when temporal scalability is enabled. This key is optional and used only in the configuration phase of video encoding.|
| OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_REFERENCE_MODE         | Reference mode in a temporal image group. The value type is int32_t. For details, see [OH_TemporalGopReferenceMode](capi-native-avcodec-base-h.md#oh_temporalgopreferencemode). This key is valid only when temporal scalability is enabled. This key is optional and used only in the configuration phase of video encoding.|
| OH_MD_KEY_VIDEO_ENCODER_LTR_FRAME_COUNT        | Number of LTR frames. The value type is int32_t. The value must be within the supported value range. This key is optional and is used only for video encoding.|
| OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_MARK_LTR  | Whether the current frame is marked as an LTR frame. The value type is int32_t. **1** if marked, **0** otherwise. This key is optional and is used only for video encoding.|
| OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_USE_LTR    | 	POC number of the LTR frame referenced by the current frame. The value type is int32_t. This key is optional and is used only for video encoding.|
| OH_MD_KEY_VIDEO_PER_FRAME_IS_LTR      | Whether the frame corresponding to the stream output from the current [OH_AVBuffer](_core.md#oh_avbuffer) is marked as an LTR frame. The value type is int32_t. **1** if marked, **0** otherwise. This key is optional and is used only for video encoding.|
| OH_MD_KEY_VIDEO_PER_FRAME_POC            | POC number of the frame. The value type is int32_t. This key is optional and is used only for video encoding.|
| OH_MD_KEY_VIDEO_ENCODER_QP_MAX       | Maximum Quantization Parameter (QP) allowed by the video encoder. The value type is int32_t. This key is optional and is used only for video encoding.|
| OH_MD_KEY_VIDEO_ENCODER_QP_MIN      | Minimum QP allowed by the video encoder. The value type is int32_t. This key is optional and is used only for video encoding.|
| OH_MD_KEY_VIDEO_ENCODER_QP_AVERAGE     |Average QP of video frames. The value type is int32_t. This key is optional and is used only for video encoding. |
| OH_MD_KEY_VIDEO_ENCODER_MSE     |Mean Squared Error (MSE) of video frames. The value type is double. This key is optional and is used only for video encoding. |
| OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER         | Duration (in milliseconds) for which the last frame will be resubmitted repeatedly, if no new frame is available after the previous frame is submitted to the encoder. The value type is int32_t. This key is used only in the configuration phase of video encoding in surface mode.|
| OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_MAX_COUNT         | Maximum number of times the encoder can repeat encoding the previous frame when no new frame is available. The value type is int32_t. This key takes effect only when **OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER** is available and is used only in the configuration phase.|
| OH_MD_KEY_VIDEO_DECODER_OUTPUT_COLOR_SPACE   | Output color space of the video decoder. The value type is int32_t. The supported value is **OH_COLORSPACE_BT709_LIMIT**.|
| OH_MD_KEY_ROTATION                    | Rotation angle of the surface. The value type is int32_t, and the value range is {0, 90, 180, 270}. The default value is 0. This key is optional and is used only for video decoding in surface mode This key is optional.|
| OH_MD_KEY_SCALING_MODE            | Video scaling mode. The value type is int32_t. For details, see [OH_ScalingMode](capi-native-avcodec-base-h.md#oh_scalingmode). This key is optional and is used only for video decoding in surface mode. You are advised to set the scaling mode by calling [OH_NativeWindow_NativeWindowSetScalingModeV2](../apis-arkgraphics2d/capi-external-window-h.md#oh_nativewindow_nativewindowsetscalingmodev2). (It is deprecated from API version 14.)|
| OH_MD_KEY_VIDEO_CROP_TOP       | Top coordinate (y) of the cropped rectangle. The value type is int32_t. This key is optional and is used only for video decoding.|
| OH_MD_KEY_VIDEO_CROP_BOTTOM        | Bottom coordinate (y) of the cropped rectangle. The value type is int32_t. This key is optional and is used only for video decoding.|
| OH_MD_KEY_VIDEO_CROP_LEFT     | Left coordinate (x) of the cropped rectangle. The value type is int32_t. This key is optional and is used only for video decoding.|
| OH_MD_KEY_VIDEO_CROP_RIGHT     | Right coordinate (x) of the cropped rectangle. The value type is int32_t. This key is optional and is used only for video decoding.|
| OH_MD_KEY_VIDEO_DECODER_OUTPUT_ENABLE_VRR     | Whether the decoder enables the video variable frame rate feature. The value type is int32_t. This key is optional and is used only for video decoding.|
| OH_MD_KEY_SQR_FACTOR     | Quality parameter in SQR mode. The value range is [0, 51] (same as the QP value in encoding). A smaller value indicates a higher output bit rate and better quality. The value type is int32_t. This key is optional and is used only for video encoding.|
| OH_MD_KEY_MAX_BITRATE    | Maximum bit rate in SQR mode. The value range can be obtained by calling [OH_AVCapability_GetEncoderBitrateRange](capi-native-avcapability-h.md#oh_avcapability_getencoderbitraterange) and is the same as that of **OH_MD_KEY_BITRATE**. The unit is bit/s. The value type is int64_t. This key is optional and is used only for video encoding.|
| OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS    | ROI encoding parameters, including the ROI area and deltaQp. The value type is string. This key is optional and is used only for video encoding.|
| OH_MD_KEY_VIDEO_ENCODER_ENABLE_PTS_BASED_RATECONTROL    | Enabled status of the PTS-based bit rate control mode. The value type is int32_t. **1** if enabled, **0** otherwise. This key is optional and used only for video encoding. The default value is **0**. If this feature is enabled, each video frame must contain PTS information and be sent to the encoder. It is used in the configuration phase.|

### Key-Value Pairs Dedicated for Audio

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_MD_KEY_AUDIO_SAMPLE_FORMAT | Original audio format. The value type is int32_t. For details, see [OH_BitsPerSample](capi-native-avcodec-base-h.md#oh_bitspersample).|
| OH_MD_KEY_AUD_CHANNEL_COUNT  | Number of audio channels. The value type is int32_t.                          |
| OH_MD_KEY_AUD_SAMPLE_RATE      | Audio sampling rate. The value type is int32_t.                            |
| OH_MD_KEY_AUDIO_COMPRESSION_LEVEL | Audio codec compression level. The value type is int32_t type. This key is used only for audio encoding. This key is optional.    |
| OH_MD_KEY_CHANNEL_LAYOUT        | Required encoding channel layout. The value type is int64_t. This key applies only to encoders. For details, see [OH_AudioChannelLayout](_core.md#oh_audiochannellayout-1). |
| OH_MD_KEY_BITS_PER_CODED_SAMPLE | Number of bits per sample. The value type is int32_t. This key is optional.<br>In versions earlier than API version 20, this parameter must be set to **1** for FLAC encoding. Otherwise, **OH_AudioCodec_Configure** returns the error code **AV_ERR_INVALID_VAL**. However, this parameter has no actual effect and does not affect the encoding result. Starting from API version 20, you do not need to set it anymore.|
| OH_MD_KEY_SBR                              | AAC SBR format. The value type is int32_t. This key applies to AAC encoders. This key is optional.|
| OH_MD_KEY_COMPLIANCE_LEVEL    | FLAC compliance level. The value type is int32_t. This key is used only for audio encoding. This key is optional.         |
| OH_MD_KEY_AAC_IS_ADTS              | AAC format, which can be ADTS or LATM. The value type is int32_t. This key applies to AAC decoders. This key is optional. |
| OH_MD_KEY_IDENTIFICATION_HEADER | Vorbis identification header. The value type is uint8_t\*. This key applies only to Vorbis decoders. This key is optional.|
| OH_MD_KEY_SETUP_HEADER            | Vorbis setup header. The value type is uint8_t\*. This key applies only to Vorbis decoders. This key is optional.|
| OH_MD_KEY_AUDIO_OBJECT_NUMBER | Number of audio objects. The value type is int32_t. This key is used only for Audio Vivid decoding. This key is optional.           |
| OH_MD_KEY_AUDIO_VIVID_METADATA | Audio Vivid metadata. The value type is uint8_t\*. This key is used only for Audio Vivid decoding. This key is optional.    |

### Key-Value Pairs Dedicated for Multiplexing and Demultiplexing

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_MD_KEY_VIDEO_IS_HDR_VIVID | Whether the video track in a media file is HDR Vivid. The value type is int32_t. This key is used for both multiplexing and demultiplexing. This key is optional. |
| OH_MD_KEY_START_TIME | Start time of the first frame in a media file, measured in microseconds. The value type is int64_t. This key is optional.           |
| OH_MD_KEY_TRACK_START_TIME | Start time of the track, measured in microseconds. The value type is int64_t. This key is optional.           |
| OH_MD_KEY_TRACK_TYPE                | Track type in a media file. The value type is int32_t. For details, see [OH_MediaType](capi-native-avcodec-base-h.md#oh_mediatype). This key is optional.|
| OH_MD_KEY_DURATION                    | Duration in a media file. The value type is int64_t. This key is optional.                 |
| OH_MD_KEY_TITLE                          | Title in a media file. The value type is string. This key is optional.              |
| OH_MD_KEY_ARTIST                        | Artist in a media file. The value type is string. This key is optional.            |
| OH_MD_KEY_ALBUM                          | Album in a media file. The value type is string. This key is optional.              |
| OH_MD_KEY_ALBUM_ARTIST            | Album artist of the input media. The value type is string. This key is optional.              |
| OH_MD_KEY_DATE                            | Date in a media file, for example, 2024. The value type is string. This key is optional.   |
| OH_MD_KEY_COMMENT                      | Comment in a media file. The value type is string. This key is optional.              |
| OH_MD_KEY_GENRE                          | Genre in a media file. The value type is string. This key is optional.              |
| OH_MD_KEY_COPYRIGHT                  | Copyright in a media file. The value type is string. This key is optional.              |
| OH_MD_KEY_LANGUAGE                    | Language in a media file. The value type is string. This key is optional.              |
| OH_MD_KEY_DESCRIPTION              | Description in a media file. The value type is string. This key is optional.              |
| OH_MD_KEY_LYRICS                        | Lyrics in a media file. The value type is string. This key is optional.              |
| OH_MD_KEY_TRACK_COUNT              | Number of tracks in a media file. The value type is int32_t. This key is optional.        |
| OH_MD_KEY_BUFFER_DURATION | Duration corresponding to the audio, video, or subtitle sample carried in AVBuffer, in microseconds. The value type is int64_t. This key is optional.           |
| OH_MD_KEY_DECODING_TIMESTAMP | Decoding timestamp corresponding to the audio, video, or subtitle sample carried in AVBuffer, in microseconds. The value type is int64_t. This key is optional.           |
| OH_MD_KEY_CODEC_MIME                | [MIME](#media-codec-formats) type of the codec. The value type is string. This key is optional.        |
| OH_MD_KEY_VIDEO_SAR                  | Aspect ratio of the sample. The value type is double.|
| OH_MD_KEY_CREATION_TIME          | Media file creation time. The value type is string.|
| OH_MD_KEY_REFERENCE_TRACK_IDS          | Reference relationship between media file tracks. The value type is int32_t\*.|
| OH_MD_KEY_TRACK_REFERENCE_TYPE         | Auxiliary track type of a media file. The value type is string.|
| OH_MD_KEY_TRACK_DESCRIPTION         | Auxiliary track description of a media file. The value type is string.|
<!--no_check-->