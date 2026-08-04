# CodecBase

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @mr-chencxy-->
<!--Designer: @dpy2650--->
<!--Tester: @baotianhao-->
<!--Adviser: @w_Machine_cc-->

## Overview

The CodecBase module provides variables, attributes, and functions for basic audio and video muxing, demuxing, and codec functionalities, including codec base structures, asynchronous callback mechanisms, MIME type definitions, media description keys, user-defined data sources, and video-specific configurations. This module serves as the foundation of the AVCodec Kit, providing common type definitions and attribute keys for modules such as video encoders, video decoders, audio encoders, audio decoders, muxers, and demuxers.

The main capabilities provided by this module include:

- **Codec base structures**: Define the `OH_AVCodec` codec instance and the `OHNativeWindow` graphics API, which serve as the core objects for audio and video encoding and decoding operations.
- **Asynchronous callback mechanism**: Provides function pointer types for error callbacks, stream change callbacks, input buffer callbacks, output buffer callbacks, and the callback collection structure `OH_AVCodecCallback`, used to handle asynchronous events during the encoding and decoding process.
- **User-defined data source**: Supports custom media data reading through the `OH_AVDataSourceReadAt` callback and the `OH_AVDataSource` structure.
- **MIME type definitions**: Defines MIME type constants for video codecs (H.264, H.265, and more), audio codecs (MP3, FLAC, OGG, WAV, and more), subtitles (SRT, WEBVTT), and more.
- **Media description keys**: Provides unified key name constants (`OH_MD_KEY_*`) for configuring and querying media parameters, covering the video resolution, frame rate, bitrate, profile, pixel format, color space, audio sample rate, channel count, channel layout, codec features (layered coding, long-term reference frames, B-frames, low latency); and media metadata (title, artist, album, and more).
- **Video ROI configuration**: Supports ROI encoding configuration, including ROI region coordinates, quantization parameter offset, semantic labels, and provides ROI string parsing and formatting functions.
- **Audio channel layout**: Defines audio channel sets and channel layout enumerations.

Applicable scenarios include audio and video encoding and decoding, media encapsulation and decapsulation, and media data processing, and other scenarios where basic types and attribute keys of common codecs are required.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

## Files

| Name| Description|
| -- | -- |
| [avcodec_audio_channel_layout.h](capi-avcodec-audio-channel-layout-h.md) | Declares the enums used for audio codec channel layouts.|
| [native_avcodec_base.h](capi-native-avcodec-base-h.md) | Declares the native APIs used for basic audio and video multiplexing, demultiplexing, encoding, and decoding.|

## Media Codec Formats

The table below lists the media codec formats. The type is a constant string.

| Name                                                        | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------ |
| OH_AVCODEC_MIMETYPE_AUDIO_AAC | MIME type of the AAC audio codec.                           |
| OH_AVCODEC_MIMETYPE_AUDIO_FLAC | MIME type of the FLAC audio codec.                          |
| OH_AVCODEC_MIMETYPE_AUDIO_OPUS | MIME type of the Opus audio codec.                           |
| OH_AVCODEC_MIMETYPE_AUDIO_G711MU | MIME type of the G.711 mu-law audio codec.                        |
| OH_AVCODEC_MIMETYPE_AUDIO_G711A | MIME type of the G.711 a-law audio decoder.<br>This specification is supported since API version 20.                        |
| OH_AVCODEC_MIMETYPE_AUDIO_RAW | MIME type of raw audio streams.                        |
| OH_AVCODEC_MIMETYPE_AUDIO_VORBIS | MIME type of the Vorbis audio decoder.                          |
| OH_AVCODEC_MIMETYPE_AUDIO_MPEG | MIME type of the MP3 audio codec.                             |
| OH_AVCODEC_MIMETYPE_AUDIO_VIVID | MIME type of the Audio Vivid audio decoder.                      |
| OH_AVCODEC_MIMETYPE_AUDIO_AMR_NB | MIME type of the AMR-NB audio decoder.                          |
| OH_AVCODEC_MIMETYPE_AUDIO_AMR_WB | MIME type of the AMR-WB audio decoder.                          |
| OH_AVCODEC_MIMETYPE_AUDIO_APE | MIME type of the APE audio decoder.                        |
| OH_AVCODEC_MIMETYPE_AUDIO_ALAC | MIME type of the Apple Lossless Audio Codec (ALAC) audio decoder.<br>This specification is supported since API version 22.|
| OH_AVCODEC_MIMETYPE_AUDIO_AC3 | MIME type of the Dolby Audio Coding 3 (AC 3) audio decoder.<br>This specification is supported since API version 22.|
| OH_AVCODEC_MIMETYPE_AUDIO_EAC3 | MIME type of the Enhanced AC-3 (EAC3) audio decoder.<br>This specification is supported since API version 22.|
| OH_AVCODEC_MIMETYPE_AUDIO_WMAV1 | MIME type of the Windows Media Audio (WMA) V1 audio decoder.<br>This specification is supported since API version 22.|
| OH_AVCODEC_MIMETYPE_AUDIO_WMAV2 | MIME type of the WMA V2 audio decoder.<br>This specification is supported since API version 22.|
| OH_AVCODEC_MIMETYPE_AUDIO_WMAPRO | MIME type of the WMA Pro audio decoder.<br>This specification is supported since API version 22.|
| OH_AVCODEC_MIMETYPE_AUDIO_GSM | MIME type of the Global System for Mobile Communications (GSM) audio decoder.<br>This specification is supported since API version 22.|
| OH_AVCODEC_MIMETYPE_AUDIO_GSM_MS | MIME type of the GSM Microsoft variant (MS) audio decoder.<br>This specification is supported since API version 22.|
| OH_AVCODEC_MIMETYPE_AUDIO_TWINVQ | MIME type of the Transform-domain Weighted Interleave Vector Quantization (TWINVQ) audio decoder.<br>This specification is supported since API version 23.|
| OH_AVCODEC_MIMETYPE_AUDIO_ILBC | MIME type of the Internet Low Bitrate Codec (iLBC) audio decoder.<br>This specification is supported since API version 23.|
| OH_AVCODEC_MIMETYPE_AUDIO_TRUEHD | MIME type of the True High Definition (TRUEHD) audio decoder.<br>This specification is supported since API version 23.|
| OH_AVCODEC_MIMETYPE_AUDIO_DVAUDIO | MIME type of the DVAUDIO (Digital Video Audio) audio decoder.<br>This specification is supported since API version 23.|
| OH_AVCODEC_MIMETYPE_AUDIO_DTS | MIME type of the DTS (Digital Theater Systems) audio decoder.<br>This specification is supported since API version 23.|
| OH_AVCODEC_MIMETYPE_AUDIO_COOK | MIME type of the Cook (RealAudio Cook) audio decoder.<br>This specification is supported since API version 23.|
| OH_AVCODEC_MIMETYPE_VIDEO_VVC | MIME type of the VVC (H.266) video codec.                   |
| OH_AVCODEC_MIMETYPE_VIDEO_HEVC | MIME type of the HEVC (H.265) video codec.                   |
| OH_AVCODEC_MIMETYPE_VIDEO_AVC | MIME type of the AVC (H.264) video codec.                    |
| OH_AVCODEC_MIMETYPE_VIDEO_H263 | MIME type of the H.263 video codec.                    |
| OH_AVCODEC_MIMETYPE_VIDEO_VC1 | MIME type of the VC-1 video codec.<br>This specification is supported since API version 22.|
| OH_AVCODEC_MIMETYPE_VIDEO_MSVIDEO1 | MIME type of the Microsoft Video 1 (MSVIDEO1) video codec.<br>This specification is supported since API version 22.|
| OH_AVCODEC_MIMETYPE_VIDEO_WMV3 | MIME type of the WMV3 video codec.<br>This specification is supported since API version 22.|
| OH_AVCODEC_MIMETYPE_VIDEO_MJPEG | MIME type of the Motion JPEG (MJPEG) video codec.<br>This specification is supported since API version 22.|
| OH_AVCODEC_MIMETYPE_VIDEO_MPEG4 | MIME type of the MPEG4 video encoder, which is used only for multiplexing MPEG4 video streams. (It is deprecated from API version 11.)|
| OH_AVCODEC_MIMETYPE_VIDEO_MPEG4_PART2 | MIME type of the MPEG4 Part 2 video codec.|
| OH_AVCODEC_MIMETYPE_VIDEO_MPEG2 | MIME type of the MPEG2 video codec.|
| OH_AVCODEC_MIMETYPE_VIDEO_AV1 | MIME type of the AV1 video codec.<br>This specification is supported since API version 23.|
| OH_AVCODEC_MIMETYPE_VIDEO_VP9 | MIME type of the VP9 video codec.<br>This specification is supported since API version 23.|
| OH_AVCODEC_MIMETYPE_VIDEO_VP8 | MIME type of the VP8 video codec.<br>This specification is supported since API version 23.|
| OH_AVCODEC_MIMETYPE_VIDEO_RV30 | MIME type of the RV30 video codec.<br>This specification is supported since API version 23.|
| OH_AVCODEC_MIMETYPE_VIDEO_RV40 | MIME type of the RV40 video codec.<br>This specification is supported since API version 23.|
| OH_AVCODEC_MIMETYPE_VIDEO_WVC1 | MIME type of the WVC1 video codec.<br>This specification is supported since API version 23.|
| OH_AVCODEC_MIMETYPE_VIDEO_DVVIDEO | MIME type of the DVVIDEO (Digital Video) video codec. Supports DV NTSC, DV PAL, and DVCPRO HD.<br>This specification is supported since API version 23.|
| OH_AVCODEC_MIMETYPE_VIDEO_RAWVIDEO | MIME type of the RAWVIDEO video codec.<br>This specification is supported since API version 23.|
| OH_AVCODEC_MIMETYPE_VIDEO_MPEG1 | MIME type of the MPEG1 video codec.<br>This specification is supported since API version 23.|
| OH_AVCODEC_MIMETYPE_VIDEO_CINEPAK | MIME type of the Cinepak video codec.<br>This key is supported since API version 24.|
| OH_AVCODEC_MIMETYPE_IMAGE_JPG | MIME type of the JPG image encoder, which is used only for multiplexing JPG covers.      |
| OH_AVCODEC_MIMETYPE_IMAGE_PNG | MIME type of the PNG image encoder, which is used only for multiplexing PNG covers.      |
| OH_AVCODEC_MIMETYPE_IMAGE_BMP | MIME type of the BMP image encoder, which is used only for multiplexing BMP covers.      |
| OH_AVCODEC_MIMETYPE_SUBTITLE_WEBVTT |MIME type of the WEBVTT subtitle demuxer.                        |
| OH_AVCODEC_MIMETYPE_SUBTITLE_SRT |MIME type of the SRT subtitle demuxer.                        |

## Media Data Key-Value Pairs

The tables below list the key-value pairs used to describe media data. The key type is a constant string, and the value type can be int32_t, int64_t, float, double, char *, or uint8_t *.

The [OH_AVFormat](capi-core-oh-avformat.md) API is used to configure or query parameters.

### Key-Value Pairs Dedicated for Capability Query

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_FEATURE_PROPERTY_KEY_VIDEO_ENCODER_MAX_LTR_FRAME_COUNT     | Maximum number of long-term reference (LTR) frames obtained during video encoding. The value type is int32_t.|

### Common Key-Value Pairs of Audio and Video

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_MD_KEY_CODEC_CONFIG           | Codec-specific data. In the case of video, data carried in **SPS/PPS** is transferred. In the case of audio, data carried in **extraData** is transferred. The value type is uint8_t\*. This key is optional. <!--Del-->(This key is not supported yet for the video codec.)<!--DelEnd--> |
| OH_MD_MAX_INPUT_BUFFER_COUNT | Maximum number of input buffers. The value type is int32_t. This key is optional.     |
| OH_MD_MAX_OUTPUT_BUFFER_COUNT | Maximum number of output buffers. The value type is int32_t. This key is optional.       |
| OH_MD_KEY_BITRATE                      | Bit rate. The value type is int64_t. This key is used in audio and video encoding scenarios. It is optional in video encoding scenarios.|
| OH_MD_KEY_PROFILE                     | Encoding grading. The value type is int32_t. For details, see [OH_AVCProfile](capi-native-avcodec-base-h.md#oh_avcprofile), [OH_HEVCProfile](capi-native-avcodec-base-h.md#oh_hevcprofile), and [OH_AACProfile](capi-native-avcodec-base-h.md#oh_aacprofile). This key is optional.|
| OH_MD_KEY_MAX_INPUT_SIZE        | Maximum size of an input stream to decode. The value type is int32_t. This key is optional.          |
| OH_MD_KEY_ENABLE_SYNC_MODE   | Enabled status of audio/video codec synchronization. The value type is int32_t. **1** if enabled, **0** otherwise. This key is optional. By default, the feature is disabled. The key is used in the configuration phase.|

### Key-Value Pairs Dedicated for Video

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_ED_KEY_TIME_STAMP               | Surface buffer timestamp. The value is of the int64_t type. This key is optional. (It is deprecated from API version 14.)|
| OH_ED_KEY_EOS                         | End of stream for the surface buffer. The value type is int32_t. This key is optional. (It is deprecated from API version 14.)|
| OH_MD_KEY_WIDTH                          | Video width. The value type is int32_t.                            |
| OH_MD_KEY_HEIGHT                        | Video height. The value type is int32_t.                              |
| OH_MD_KEY_PIXEL_FORMAT            | Video pixel format. The value type is int32_t. For details, see [OH_AVPixelFormat](capi-native-avformat-h.md#oh_avpixelformat).|
| OH_MD_KEY_FRAME_RATE                | Video frame rate. The value type is double. This key is optional.                |
| OH_MD_KEY_RANGE_FLAG           | Video YUV value range flag. The value type is int32_t. The value **1** means a full range, and **0** means a limited range. This key is optional.|
| OH_MD_KEY_COLOR_PRIMARIES      | Video primary colors. The value type is int32_t. For details, see [OH_ColorPrimary](capi-native-avcodec-base-h.md#oh_colorprimary). The value complies with Table 2 in H.273. This key is optional.|
| OH_MD_KEY_TRANSFER_CHARACTERISTICS | Video transfer characteristics. The value type is int32_t. For details, see [OH_TransferCharacteristic](capi-native-avcodec-base-h.md#oh_transfercharacteristic). The value complies with Table 3 in H.273. This key is optional.|
| OH_MD_KEY_MATRIX_COEFFICIENTS | Video matrix coefficients. The value type is int32_t. For details, see [OH_MatrixCoefficient](capi-native-avcodec-base-h.md#oh_matrixcoefficient). The value complies with Table 4 in H.273. This key is optional.|
| OH_MD_KEY_VIDEO_STRIDE       | Stride of the video frame. The value type is int32_t. This key is optional.       |
| OH_MD_KEY_VIDEO_SLICE_HEIGHT    | Height of the video frame. The value type is int32_t. This key is optional.       |
| OH_MD_KEY_VIDEO_PIC_WIDTH       | Actual active width of a decoded video frame. The value type is int32_t. This key is read-only and used only for video decoding. This key is optional.       |
| OH_MD_KEY_VIDEO_PIC_HEIGHT      | Actual active height of a decoded video frame. The value type is int32_t. This key is read-only and used only for video decoding. This key is optional.       |
| OH_MD_KEY_VIDEO_ENABLE_LOW_LATENCY  | Enabled status of low-latency video codec. The value type is int32_t. **1** if enabled, **0** otherwise. This key is optional. By default, the feature is disabled. The key is used in the configuration phase.|
| OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE | Video encoding bit rate mode. The value type is int32_t. For details, see [OH_BitrateMode](capi-native-avcodec-base-h.md#oh_bitratemode). This key is optional.|
| OH_MD_KEY_QUALITY                      | Required encoding quality. The value type is int32_t. This key applies only to encoders configured in constant quality mode. This key is optional.|
| OH_MD_KEY_REQUEST_I_FRAME      | Request for immediate encoding of I-frames. The value type is int32_t. This key is optional.           |
| OH_MD_KEY_I_FRAME_INTERVAL   | Key frame interval, in milliseconds. The value type is int32_t. This key is optional and is used only for video encoding.|
| OH_MD_KEY_VIDEO_ENCODER_ENABLE_TEMPORAL_SCALABILITY         | Enabled status of temporal scalability. The value type is int32_t. **1** if enabled, **0** otherwise. This key is optional and used only for video encoding. By default, this feature is disabled. The key is used in the configuration phase.|
| OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_SIZE       | Size of a temporal image group. The value type is int32_t. This key is valid only when temporal scalability is enabled. This key is optional and used only in the configuration phase of video encoding.|
| OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_REFERENCE_MODE         | Reference mode in a temporal image group. The value type is int32_t. For details, see [OH_TemporalGopReferenceMode](capi-native-avcodec-base-h.md#oh_temporalgopreferencemode). This key is valid only when temporal scalability is enabled. This key is optional and used only in the configuration phase of video encoding.|
| OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_LAYER_ID         | Temporal layer ID in a group of pictures (GOP). The value type is int32_t.<br> Temporal layer ID **0** indicates the base layer. Temporal layer IDs **1** and above indicate enhancement layers. The maximum temporal layer ID is determined by **OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_REFERENCE_MODE** and **OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_SIZE**.<br> Currently, this key is used only to query the temporal layer ID carried in **AVBuffer** output by the encoder.<br> The procedure is as follows:<br> 1. Use [OH_AVCodecOnNewOutputBuffer](capi-native-avcodec-base-h.md#oh_avcodeconnewoutputbuffer) or [OH_VideoEncoder_GetOutputBuffer](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_getoutputbuffer) to obtain the buffer instance (**AVBuffer**).<br> 2. Use [OH_AVBuffer_GetParameter](capi-native-avbuffer-h.md#oh_avbuffer_getparameter) to obtain the parameter instance (**OH_AVFormat**), which does not contain basic properties.<br> 3. Use [OH_AVFormat_GetIntValue](capi-native-avformat-h.md#oh_avformat_getintvalue) and this key to obtain the temporal layer ID of the corresponding frame.<br>**Since**: 26.0.0|
| OH_MD_KEY_VIDEO_ENCODER_LTR_FRAME_COUNT        | Number of LTR frames. The value type is int32_t. The value must be within the supported value range. This key is optional and is used only for video encoding.|
| OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_MARK_LTR  | Whether the current frame is marked as an LTR frame. The value type is int32_t. **1** if marked, **0** otherwise. This key is optional and is used only for video encoding.|
| OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_USE_LTR    | POC number of the LTR frame referenced by the current frame. The value type is int32_t. This key is optional and is used only for video encoding.|
| OH_MD_KEY_VIDEO_PER_FRAME_IS_LTR      | Whether the frame corresponding to the stream output from the current [OH_AVBuffer](capi-core-oh-avbuffer.md) is marked as an LTR frame. The value type is int32_t. **1** if marked, **0** otherwise. This key is optional and used only for video encoding. The default value is **0**.|
| OH_MD_KEY_VIDEO_PER_FRAME_POC            | POC number of the frame. The value type is int32_t. This key is optional and is used only for video encoding.|
| OH_MD_KEY_VIDEO_ENCODER_QP_MAX       | Maximum Quantization Parameter (QP) allowed by the video encoder. The value type is int32_t. This key is optional and is used only for video encoding.|
| OH_MD_KEY_VIDEO_ENCODER_QP_MIN      | Minimum QP allowed by the video encoder. The value type is int32_t. This key is optional and is used only for video encoding.|
| OH_MD_KEY_VIDEO_ENCODER_QP_AVERAGE     |Average QP of video frames. The value type is int32_t. This key is optional and is used only for video encoding. |
| OH_MD_KEY_VIDEO_ENCODER_MSE     |Mean Squared Error (MSE) of video frames. The value type is double. This key is optional and is used only for video encoding. |
| OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER         | Duration (in milliseconds) for which the last frame will be resubmitted repeatedly, if no new frame is available after the previous frame is submitted to the encoder. The value type is int32_t. This key is used only in the configuration phase of video encoding in surface mode.|
| OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_MAX_COUNT         | Maximum number of times the encoder can repeat encoding the previous frame when no new frame is available. The value type is int32_t. This key takes effect only when **OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER** is available and is used only in the configuration phase.|
| OH_MD_KEY_VIDEO_DECODER_OUTPUT_COLOR_SPACE   | Output color space of the video decoder. The value type is int32_t. The supported value is **OH_COLORSPACE_BT709_LIMIT**.|
| OH_MD_KEY_ROTATION                    | Rotation angle of the surface, with a clockwise direction. The value type is int32_t, and the value range is {0, 90, 180, 270}. The default value is 0. This key is optional and is used only for video decoding in surface mode This key is optional.|
| OH_MD_KEY_SCALING_MODE            | Video scaling mode. The value type is int32_t. For details, see [OH_ScalingMode](capi-native-avcodec-base-h.md#oh_scalingmode). This key is optional and is used only for video decoding in surface mode. You are advised to set the scaling mode by calling [OH_NativeWindow_NativeWindowSetScalingModeV2](../apis-arkgraphics2d/capi-external-window-h.md#oh_nativewindow_nativewindowsetscalingmodev2). (It is deprecated from API version 14.)|
| OH_MD_KEY_VIDEO_CROP_TOP       | Y-coordinate of the top edge of the crop rectangle. The value type is int32_t. This key is optional and is used only for video decoding.|
| OH_MD_KEY_VIDEO_CROP_BOTTOM        | Y-coordinate of the bottom edge of the crop rectangle. The value type is int32_t. This key is optional and is used only for video decoding.|
| OH_MD_KEY_VIDEO_CROP_LEFT     | X-coordinate of the left edge of the crop rectangle. The value type is int32_t. This key is optional and is used only for video decoding.|
| OH_MD_KEY_VIDEO_CROP_RIGHT     | X-coordinate of the right edge of the crop rectangle. The value type is int32_t. This key is optional and is used only for video decoding.|
| OH_MD_KEY_VIDEO_DECODER_OUTPUT_ENABLE_VRR     | Whether the decoder enables the video variable frame rate feature. The value type is int32_t. This key is optional and is used only for video decoding.|
| OH_MD_KEY_SQR_FACTOR     | Quality parameter in SQR mode. The value range is [0, 51] (same as the QP value in encoding). A smaller value indicates a higher output bit rate and better quality. The value type is int32_t. This key is optional and is used only for video encoding.|
| OH_MD_KEY_MAX_BITRATE    | Maximum bit rate in SQR mode. The value range can be obtained by calling [OH_AVCapability_GetEncoderBitrateRange](capi-native-avcapability-h.md#oh_avcapability_getencoderbitraterange) and is the same as that of **OH_MD_KEY_BITRATE**. The unit is bit/s. The value type is int64_t. This key is optional and is used only for video encoding.|
| OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS    | ROI encoding parameters, including the ROI area and deltaQp. The value type is char *. This key is optional and is used only for video encoding.|
| OH_MD_KEY_VIDEO_ENCODER_ENABLE_PTS_BASED_RATECONTROL    | Whether to enable the PTS-based bit rate control mode. The value type is int32_t. **1** to enable, **0** otherwise. This key is optional and used only for video encoding. The default value is **0**. If this feature is enabled, each video frame must contain PTS information and be sent to the encoder. It is used in the configuration phase.|
| OH_MD_KEY_VIDEO_ENCODER_ENABLE_B_FRAME | Whether to enable bidirectional predictive frame (B-frame) encoding. The value type is int32_t. **1** to enable, **0** otherwise. This key is optional and used only for video encoding. The default value is **0**.<br> If enabled, the video encoder uses B-frame encoding, resulting in a decoding sequence different from the display sequence.<br> For a device that does not support B-frame encoding, the configured key does not take effect.<br> To check the device capability, use the [OH_AVCapability_IsFeatureSupported](capi-native-avcapability-h.md#oh_avcapability_isfeaturesupported) API and the enumerated value [OH_AVCapabilityFeature](capi-native-avcapability-h.md#oh_avcapabilityfeature).VIDEO_ENCODER_B_FRAME.<br> This key is used only by calling [OH_VideoEncoder_Configure](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_configure).|
| OH_MD_KEY_VIDEO_ENCODER_MAX_B_FRAMES | Maximum number of consecutive B-frames supported by the video encoder. The value type is int32_t. Note: This key is used only to query the encoder capability.<br> The usage specifications are as follows:<br> 1. To check whether the feature is supported, use the [OH_AVCapability_IsFeatureSupported](capi-native-avcapability-h.md#oh_avcapability_isfeaturesupported) API and the enumerated value [OH_AVCapabilityFeature](capi-native-avcapability-h.md#oh_avcapabilityfeature).VIDEO_ENCODER_B_FRAME.<br> 2. Obtain the OH_AVFormat pointer through the [OH_AVCapability_GetFeatureProperties](capi-native-avcapability-h.md#oh_avcapability_getfeatureproperties) API and the enumerated value [OH_AVCapabilityFeature](capi-native-avcapability-h.md#oh_avcapabilityfeature).VIDEO_ENCODER_B_FRAME.<br> 3. Obtain the maximum number of B-frames through the [OH_AVFormat_GetIntValue](capi-native-avformat-h.md#oh_avformat_getintvalue) API and this key.|
| OH_MD_KEY_VIDEO_DECODER_BLANK_FRAME_ON_SHUTDOWN | Whether to output blank frames when the video decoder is disabled. The value type is int32_t. **1** to output, **0** otherwise. The default value is **0**. If this parameter is set to a non-zero value, the value **1** is used. This key is optional and is used only for video decoding in surface mode.<br> After this feature is enabled, the video decoder outputs blank frames (usually black) when the [OH_VideoDecoder_Stop](capi-native-avcodec-videodecoder-h.md#oh_videodecoder_stop) or [OH_VideoDecoder_Destroy](capi-native-avcodec-videodecoder-h.md#oh_videodecoder_destroy) API is called. This mechanism prevents frozen frames caused by sudden termination of the decoder.|
| OH_MD_KEY_VIDEO_NATIVE_BUFFER_FORMAT     | Key for querying the native buffer pixel format in video encoding and decoding. The value type is int32_t.<br> For details, see the pixel formats defined in [OH_NativeBuffer_Format](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_format). This key is used in the following scenarios:<br> 1. Video decoding: Call [OH_VideoDecoder_GetOutputDescription](capi-native-avcodec-videodecoder-h.md#oh_videodecoder_getoutputdescription) or [OH_AVCodecOnStreamChanged](capi-native-avcodec-base-h.md#oh_avcodeconstreamchanged) to obtain the current output format from the returned OH_AVFormat object.<br> 2. Video encoding: Call [OH_VideoEncoder_GetInputDescription](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_getinputdescription) to obtain the current input format from the returned OH_AVFormat object.|
| OH_MD_KEY_VIDEO_ENCODER_PREPROC_DOWNSAMPLING_WIDTH  | Target width for downsampling in video encoding pre-processing. The value type is int32_t. This key is optional, and the downsampling feature is disabled by default. This key must be used together with **OH_MD_KEY_VIDEO_ENCODER_PREPROC_DOWNSAMPLING_HEIGHT**. When both are set to **0**, the downsampling feature is disabled. You can use [OH_AVCapability_IsVideoSizeSupported](capi-native-avcapability-h.md#oh_avcapability_isvideosizesupported) to query the supported range of downsampling widths and heights. Downsampling parameters are mutually exclusive with cropping parameters. Downsampling and cropping cannot be enabled simultaneously. <br>This key is applicable only to video encoders that support pre-processing or to one-input-two-output encoding scenarios. It can be configured during the configuration phase or dynamically adjusted at runtime via **SetParameter**.<br>**Since**: 26.0.0|
| OH_MD_KEY_VIDEO_ENCODER_PREPROC_DOWNSAMPLING_HEIGHT | Target height for downsampling in video encoding pre-processing. The value type is int32_t. This key is optional, and the downsampling feature is disabled by default. This key must be used together with **OH_MD_KEY_VIDEO_ENCODER_PREPROC_DOWNSAMPLING_WIDTH**. When both are set to **0**, the downsampling feature is disabled. You can use [OH_AVCapability_IsVideoSizeSupported](capi-native-avcapability-h.md#oh_avcapability_isvideosizesupported) to query the supported range of downsampling widths and heights. Downsampling parameters are mutually exclusive with cropping parameters. Downsampling and cropping cannot be enabled simultaneously. <br>This key is applicable only to video encoders that support pre-processing or to one-input-two-output encoding scenarios. It can be configured during the configuration phase or dynamically adjusted at runtime via **SetParameter**.<br>**Since**: 26.0.0|
| OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_LEFT         | Left coordinate (x) of the cropping region in video encoding pre-processing. The value type is int32_t. This key is optional, and the cropping feature is disabled by default. The four parameters **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_LEFT**, **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_TOP**, **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_RIGHT**, and **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_BOTTOM** must be set together. When all are set to **0**, the cropping feature is disabled. The default coordinate origin is the upper-left corner of the input video frame (0, 0). The coordinate values must not exceed the width and height of the input video frame, and must satisfy **(0, 0) <= (LEFT, TOP) < (RIGHT, BOTTOM) < (input video frame width, input video frame height)**. Downsampling parameters are mutually exclusive with cropping parameters. Downsampling and cropping cannot be enabled simultaneously. <br>This key is applicable only to video encoders that support pre-processing or to one-input-two-output encoding scenarios. It can be configured during the configuration phase or dynamically adjusted at runtime via **SetParameter**.<br>**Since**: 26.0.0|
| OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_TOP          | Top coordinate (y) of the cropping region in video encoding pre-processing. The value type is int32_t. This key is optional, and the cropping feature is disabled by default. The four parameters **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_LEFT**, **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_TOP**, **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_RIGHT**, and **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_BOTTOM** must be set together. When all are set to **0**, the cropping feature is disabled. The default coordinate origin is the upper-left corner of the input video frame (0, 0). The coordinate values must not exceed the width and height of the input video frame, and must satisfy **(0, 0) <= (LEFT, TOP) < (RIGHT, BOTTOM) < (input video frame width, input video frame height)**. Downsampling parameters are mutually exclusive with cropping parameters. Downsampling and cropping cannot be enabled simultaneously. <br>This key is applicable only to video encoders that support pre-processing or to one-input-two-output encoding scenarios. It can be configured during the configuration phase or dynamically adjusted at runtime via **SetParameter**.<br>**Since**: 26.0.0|
| OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_RIGHT        | Right coordinate (x) of the cropping region in video encoding pre-processing. The value type is int32_t. This key is optional, and the cropping feature is disabled by default. The four parameters **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_LEFT**, **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_TOP**, **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_RIGHT**, and **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_BOTTOM** must be set together. When all are set to **0**, the cropping feature is disabled. The default coordinate origin is the upper-left corner of the input video frame (0, 0). The coordinate values must not exceed the width and height of the input video frame, and must satisfy **(0, 0) <= (LEFT, TOP) < (RIGHT, BOTTOM) < (input video frame width, input video frame height)**. Downsampling parameters are mutually exclusive with cropping parameters. Downsampling and cropping cannot be enabled simultaneously. <br>This key is applicable only to video encoders that support pre-processing or to one-input-two-output encoding scenarios. It can be configured during the configuration phase or dynamically adjusted at runtime via **SetParameter**.<br>**Since**: 26.0.0|
| OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_BOTTOM       | Bottom coordinate (y) of the cropping region in video encoding pre-processing. The value type is int32_t. This key is optional, and the cropping feature is disabled by default. The four parameters **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_LEFT**, **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_TOP**, **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_RIGHT**, and **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_BOTTOM** must be set together. When all are set to **0**, the cropping feature is disabled. The default coordinate origin is the upper-left corner of the input video frame (0, 0). The coordinate values must not exceed the width and height of the input video frame, and must satisfy **(0, 0) <= (LEFT, TOP) < (RIGHT, BOTTOM) < (input video frame width, input video frame height)**. Downsampling parameters are mutually exclusive with cropping parameters. Downsampling and cropping cannot be enabled simultaneously. <br>This key is applicable only to video encoders that support pre-processing or to one-input-two-output encoding scenarios. It can be configured during the configuration phase or dynamically adjusted at runtime via **SetParameter**.<br>**Since**: 26.0.0|
| OH_MD_KEY_VIDEO_ENCODER_PREPROC_DROP_TO_FRAME_RATE | Target frame rate for frame dropping in video encoding pre-processing, in fps. The value type is double, and the value is accurate to two decimal places. This key is optional, and the frame dropping feature is disabled by default. Setting it to **0.00** disables the feature. When a value is set, it is automatically rounded to two decimal places. This key can be used independently or in combination with downsampling or cropping.<br>This key is applicable only to video encoders that support pre-processing or to one-input-two-output encoding scenarios. It can be configured during the configuration phase or dynamically adjusted at runtime via **SetParameter**.<br>**Since**: 26.0.0|
| OH_MD_KEY_VIDEO_ENCODER_NUMBER_OF_PENDING_FRAMES | Number of frames to be processed by the video encoder. The value type is int32_t. This key is read-only and is used to query the number of frames currently waiting to be encoded. It can be obtained via the [OH_VideoEncoder_GetInputDescription](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_getinputdescription) API.<br>**Since**: 26.0.0|
| OH_MD_KEY_VIDEO_DECODER_OUTPUT_IN_DECODING_ORDER | Decoder output mode. The value type is int32_t. The value can be **0** or **1**. **1** indicates that the decoder outputs frames in decoding order, while **0** indicates that the decoder outputs frames in display order. The default value is **0**. This key is optional and applies only to video decoding. It can be configured only during the configuration phase. Before setting this key, you can use the [OH_AVCapability_IsFeatureSupported](capi-native-avcapability-h.md#oh_avcapability_isfeaturesupported) API with the enumeration value [OH_AVCapabilityFeature](capi-native-avcapability-h.md#oh_avcapabilityfeature).VIDEO_DECODER_OUTPUT_IN_DECODING_ORDER to query whether the feature is supported. If the video decoder does not support this feature, setting this key via the [OH_VideoDecoder_Configure](capi-native-avcodec-videodecoder-h.md#oh_videodecoder_configure) API will return **AV_ERR_INVALID_VAL**.<br>**Since**: 26.0.0|
| OH_MD_KEY_VIDEO_ENCODER_MAX_FRAME_DELAY_COUNT | Maximum number of frames that the video encoder is allowed to buffer before outputting compressed frames. The value type is int32_t, and the value range is [1, 5]. This key is optional and applies only to video encoding. It can be configured only during the configuration phase. If the value falls within the [1, 5] range, it takes effect normally. If the value is outside this range (less than 1 or greater than 5), calling the [OH_VideoEncoder_Configure](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_configure) API will return **AV_ERR_INVALID_VAL**.<br>**Since**: 26.0.0|
| OH_MD_KEY_VIDEO_ENCODER_REPEAT_HEADER_BEFORE_SYNC_FRAMES | Whether to enable parameter set before the sync frame in the bitstream. The value type is int32_t, with the value being either **0** or **1**. **1** means to enable, and **0** means to disable. The default value is **0**. This key is optional and applies only to video encoding. It can be configured only during the configuration phase. When enabled, the encoder inserts parameter set data (such as SPS and PPS for H.264/H.265 formats) before each sync frame.<br>**Since**: 26.0.0|

### Key-Value Pairs Dedicated for Audio

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_MD_KEY_AUDIO_SAMPLE_FORMAT | Original audio format. The value type is int32_t. For details, see [OH_BitsPerSample](capi-native-avcodec-base-h.md#oh_bitspersample).|
| OH_MD_KEY_AUD_CHANNEL_COUNT  | Number of audio channels. The value type is int32_t.                          |
| OH_MD_KEY_AUD_SAMPLE_RATE      | Audio sampling rate. The value type is int32_t.                            |
| OH_MD_KEY_AUDIO_COMPRESSION_LEVEL | Audio codec compression level. The value type is int32_t type. This key is used only for audio encoding. This key is optional.    |
| OH_MD_KEY_CHANNEL_LAYOUT        | Required encoding channel layout. The value type is int64_t. This key applies only to encoders. For details, see [OH_AudioChannelLayout](capi-native-audio-channel-layout-h.md#oh_audiochannellayout). |
| OH_MD_KEY_BITS_PER_CODED_SAMPLE | Number of bits per sample. The value type is int32_t. This key is optional.<br>In versions earlier than API version 20, this parameter must be set to **1** for FLAC encoding. Otherwise, **OH_AudioCodec_Configure** returns the error code **AV_ERR_INVALID_VAL**. However, this parameter has no actual effect and does not affect the encoding result. Starting from API version 20, you do not need to set it anymore.|
| OH_MD_KEY_SBR                              | AAC SBR format. The value type is int32_t. This key applies to AAC encoders. This key is optional.|
| OH_MD_KEY_COMPLIANCE_LEVEL    | FLAC compliance level. The value type is int32_t. This key is used only for audio encoding. This key is optional.         |
| OH_MD_KEY_AAC_IS_ADTS              | AAC format, which can be ADTS or LATM. The value type is int32_t. This key applies to AAC decoders. This key is optional. |
| OH_MD_KEY_IDENTIFICATION_HEADER | Vorbis identification header. The value type is uint8_t\*. This key applies only to Vorbis decoders. This key is optional.|
| OH_MD_KEY_SETUP_HEADER            | Vorbis setup header. The value type is uint8_t\*. This key applies only to Vorbis decoders. This key is optional.|
| OH_MD_KEY_AUDIO_OBJECT_NUMBER | Number of audio objects. The value type is int32_t. This key is optional and is used only for Audio Vivid codec.|
| OH_MD_KEY_AUDIO_OBJECT_BITRATE | Encoding bitrate of the audio object. The value type is int64_t. This key is optional and applies only to the Audio Vivid encoder.<br>The actual encoding bitrate may be adjusted based on the encoder's capability.<br>This key is supported since API version 26.0.0.|
| OH_MD_KEY_AUDIO_VIVID_METADATA | Audio Vivid metadata. The value type is uint8_t\*. This key is optional and is used only for Audio Vivid codec.    |
| OH_MD_KEY_BLOCK_ALIGN | Size of the audio data block, in bytes. The value type is int32_t. This key is supported since API version 22 and must be configured only for WMAV1, WMAV2, and WMA PRO decoding.|
| OH_MD_KEY_ENABLE_BUFFER_SKIP_SAMPLES | Whether to enable OH_MD_KEY_BUFFER_SKIP_SAMPLES_INFO in the audio decoder. The value type is int32_t. **1** to enable, **0** otherwise. The default value is **0**. If this parameter is set to a value other than **1**, the value **0** is used.<br>This key is optional. It is for the audio decoder only.<br>This key is supported since API version 24.|
| OH_MD_KEY_AUDIO_VIVID_SIGNAL_FORMAT | Audio Vivid input signal format. The value type is int32_t. This key is used for the Audio Vivid encoder.<br>For details, see [OH_AudioVividSignalFormat](capi-native-audio-vivid-h.md#oh_audiovividsignalformat).<br>This key is supported since API version 26.0.0.|
| OH_MD_KEY_AUDIO_SOUNDBED_LAYOUT | Channel layout of the audio bed. The value type is int64_t. This key is optional and is used only for the Audio Vivid encoder.<br>For details, see [OH_AudioChannelLayout](capi-native-audio-channel-layout-h.md#oh_audiochannellayout).<br>This key is supported since API version 26.0.0.|
| OH_MD_KEY_AUDIO_SOUNDBED_BITRATE | Encoding bitrate of the audio bed. The value type is int64_t. This key is optional and is used only for the Audio Vivid encoder.<br>The actual encoding bitrate may be adjusted based on the encoder's capability.<br>This key is supported since API version 26.0.0.|
| OH_MD_KEY_AUDIO_MAX_INPUT_BUFFER_SIZE | Key for setting or querying the maximum input buffer size of the audio codec. The value type is int32_t, and the unit is bytes. The actual buffer size is limited by the codec implementation. Values exceeding the upper limit will not take effect. This key is optional.|
| OH_MD_KEY_AUDIO_ENCODER_PTS_MODE | Output PTS mode of an audio encoder. The value type is int32_t. For details, see [OH_AudioEncoderPTSMode](capi-native-avcodec-base-h.md#oh_audioencoderptsmode) This key is optional. If it is not set, the default value **OH_AUDIO_ENCODER_PTS_MODE_DEFAULT** is used.|
| OH_MD_KEY_AUDIO_ENCODER_ENABLE_SAMPLE_FORMAT_CONVERT | Whether to enable sample format conversion of an audio encoder. The value type is int32_t. The value **1** enables the conversion, and the value **0** disables it. The default value is **0**. After enabling, the supported input sample formats are: SAMPLE_U8, SAMPLE_S16LE, SAMPLE_S24LE, SAMPLE_S32LE, and SAMPLE_F32LE. This key is optional.|

### Key-Value Pairs Dedicated for Multiplexing and Demultiplexing

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_MD_KEY_VIDEO_IS_HDR_VIVID | Whether the video track in a media file is HDR Vivid. The value type is int32_t. This key is used for both multiplexing and demultiplexing. This key is optional. |
| OH_MD_KEY_START_TIME | Start time of the first frame in a media file, measured in microseconds. The value type is int64_t. This key is optional.           |
| OH_MD_KEY_TRACK_START_TIME | Start time of the track, measured in microseconds. The value type is int64_t. This key is optional.           |
| OH_MD_KEY_TRACK_TYPE                | Track type in a media file. The value type is int32_t. For details, see [OH_MediaType](capi-native-avcodec-base-h.md#oh_mediatype). This key is optional.|
| OH_MD_KEY_DURATION                    | Duration in a media file. The value type is int64_t. This key is optional.                 |
| OH_MD_KEY_TITLE                          | Title of a media file . The value type is char *. This key is optional.              |
| OH_MD_KEY_ARTIST                        | Artist. The value type is char *. This key is optional.            |
| OH_MD_KEY_ALBUM                          | Album media file. The value type is char *. This key is optional.              |
| OH_MD_KEY_ALBUM_ARTIST            | Album artist. The value type is char *. This key is optional.              |
| OH_MD_KEY_DATE                            | Date of a media file, for example, 2024. The value type is char *. This key is optional.   |
| OH_MD_KEY_COMMENT                      | Comment of a media file. The value type is char *. This key is optional.              |
| OH_MD_KEY_GENRE                          | Genre in a media file. The value type is char *. This key is optional.              |
| OH_MD_KEY_COPYRIGHT                  | Copyright of a media file. The value type is char *. This key is optional.              |
| OH_MD_KEY_LANGUAGE                    | Language of a media file. The value type is char *. This key is optional.              |
| OH_MD_KEY_DESCRIPTION              | Description of a media file. The value type is char *. This key is optional.              |
| OH_MD_KEY_LYRICS                        | Lyrics in a media file. The value type is char *. This key is optional.              |
| OH_MD_KEY_TRACK_COUNT              | Number of tracks in a media file. The value type is int32_t. This key is optional.        |
| OH_MD_KEY_BUFFER_DURATION | Duration corresponding to the audio, video, or subtitle sample carried in AVBuffer, in microseconds. The value type is int64_t. This key is optional.           |
| OH_MD_KEY_DECODING_TIMESTAMP | Decoding timestamp corresponding to the audio, video, or subtitle sample carried in AVBuffer, in microseconds. The value type is int64_t. This key is optional.           |
| OH_MD_KEY_CODEC_MIME                | [MIME](#media-codec-formats) type of the codec. The value type is char *. This key is optional.        |
| OH_MD_KEY_VIDEO_SAR                  | Aspect ratio of the sample. The value type is double.|
| OH_MD_KEY_CREATION_TIME          | Media file creation time metadata. The value type is char *.|
| OH_MD_KEY_REFERENCE_TRACK_IDS          | Reference relationship between media file tracks. The value type is int32_t\*.|
| OH_MD_KEY_TRACK_REFERENCE_TYPE         | Auxiliary track type of a media file. The value type is char *.|
| OH_MD_KEY_TRACK_DESCRIPTION         | Auxiliary track description of a media file. The value type is char *.|
| OH_MD_KEY_BUFFER_SKIP_SAMPLES_INFO | Key carried in the OH_AVBuffer, which is supported only by demultiplexing. This key may be carried in the start and end frames of the audio output of demultiplexing.<br>This key corresponds to a 10-byte uint8_t[] array, which records the number of audio samples to skip after decoding in the audio file metadata.<br>The structure is as follows:<br>1. Bytes 0-3 (uint32_t, little-endian): number of samples to skip from the beginning of this frame.<br>2. Bytes 4-7 (uint32_t, little-endian): number of samples to skip from the end of this frame (must not exceed the frame's total sample count).<br>3. Bytes 8-9: reserved. The default output is 0.<br>This key is supported since API version 23.|
| OH_MD_KEY_LATITUDE | Latitude key. The value is of the float type, and the value range is [-90.0, 90.0]. It indicates the latitude in geographic location information.<br>This key is supported since API version 24.|
| OH_MD_KEY_LONGITUDE | Longitude key. The value is of the float type, and the value range is [-180.0, 180.0]. It indicates the longitude in geographic location information.<br>This key is supported since API version 24.|
| OH_MD_KEY_ALTITUDE | Altitude key. The value is of the float type. This key is optional. It indicates the altitude in geographic location information.<br>This key is supported since API version 24.|
