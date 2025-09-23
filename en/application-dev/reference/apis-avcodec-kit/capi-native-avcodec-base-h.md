# native_avcodec_base.h

## Overview

The file declares the native APIs used for basic audio and video multiplexing, demultiplexing, encoding, and decoding.

**File to include**: <multimedia/player_framework/native_avcodec_base.h>

**Library**: libnative_media_codecbase.so

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

**Related module**: [CodecBase](capi-codecbase.md)

**Sample**: [AVCodec](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVCodec)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AVCodecAsyncCallback](capi-codecbase-oh-avcodecasynccallback.md) | OH_AVCodecAsyncCallback | Describes all the asynchronous callback function pointers of an OH_AVCodec instance. (It is deprecated from API version 11.) To ensure the normal running of OH_AVCodec, you must register the instance of this struct with the OH_AVCodec instance and process the information reported by the callback function.|
| [OH_AVCodecCallback](capi-codecbase-oh-avcodeccallback.md) | OH_AVCodecCallback | Describes all the asynchronous callback function pointers of an OH_AVCodec instance. To ensure the normal running of OH_AVCodec, you must register the instance of this struct with the OH_AVCodec instance and process the information reported by the callback function.|
| [OH_AVDataSource](capi-codecbase-oh-avdatasource.md) | OH_AVDataSource | Describes a user-defined data source.|
| [OH_AVDataSourceExt](capi-codecbase-oh-avdatasourceext.md) | OH_AVDataSourceExt | Describes a user-defined data source. User-defined data can be passed to its callback functions through the **userData** parameter.|
| [NativeWindow](../apis-arkgraphics2d/capi-nativewindow-nativewindow.md) | OHNativeWindow | Describes a native object for the graphics interface.|
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) | OH_AVCodec | Describes a native object for the audio and video codec interface.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_MediaType](#oh_mediatype) | OH_MediaType | Enumerates the media types.|
| [OH_AACProfile](#oh_aacprofile) | OH_AACProfile | Enumerates the Advanced Audio Coding (AAC) profiles.<!--Del--><br>(**AAC_PROFILE_HE** and **AAC_PROFILE_HE_V2** are not available yet.)<!--DelEnd--> |
| [OH_AVCProfile](#oh_avcprofile) | OH_AVCProfile | Enumerates the Advanced Video Coding (AVC) profiles.|
| [OH_HEVCProfile](#oh_hevcprofile) | OH_HEVCProfile | Enumerates the High Efficiency Video Coding (HEVC) profiles.|
| [OH_VVCProfile](#oh_vvcprofile) | OH_VVCProfile | Enumerates the VVC profiles.|
| [OH_MPEG2Profile](#oh_mpeg2profile) | OH_MPEG2Profile | Enumerates the MPEG2 profiles.|
| [OH_MPEG4Profile](#oh_mpeg4profile) | OH_MPEG4Profile | Enumerates the MPEG4 profiles.|
| [OH_H263Profile](#oh_h263profile) | OH_H263Profile | Enumerates the H.263 profiles.|
| [OH_AVOutputFormat](#oh_avoutputformat) | OH_AVOutputFormat | Enumerates the output file formats supported by a muxer.|
| [OH_AVSeekMode](#oh_avseekmode) | OH_AVSeekMode | Enumerates the seek modes.|
| [OH_ScalingMode](#oh_scalingmode) | OH_ScalingMode | Enumerates the scaling modes. This enum is used only in surface mode.|
| [OH_BitsPerSample](#oh_bitspersample) | OH_BitsPerSample | Enumerates the number of audio bits for each coded sample.|
| [OH_ColorPrimary](#oh_colorprimary) | OH_ColorPrimary | Enumerates the primary colors. This enum is used for both encoding and decoding.|
| [OH_TransferCharacteristic](#oh_transfercharacteristic) | OH_TransferCharacteristic | Enumerates the transfer characteristics. This enum is used for both encoding and decoding.|
| [OH_MatrixCoefficient](#oh_matrixcoefficient) | OH_MatrixCoefficient | Enumerates the matrix coefficients. This enum is used for both encoding and decoding.|
| [OH_AVCLevel](#oh_avclevel) | OH_AVCLevel | Enumerates the AVC levels.|
| [OH_HEVCLevel](#oh_hevclevel) | OH_HEVCLevel | Enumerates the HEVC levels.|
| [OH_VVCLevel](#oh_vvclevel) | OH_VVCLevel | Enumerates the VVC levels.|
| [OH_MPEG2Level](#oh_mpeg2level) | OH_MPEG2Level | Enumerates the MPEG2 levels.|
| [OH_MPEG4Level](#oh_mpeg4level) | OH_MPEG4Level | Enumerates the MPEG4 levels.|
| [OH_H263Level](#oh_h263level) | OH_H263Level | Enumerates the H.263 levels.|
| [OH_TemporalGopReferenceMode](#oh_temporalgopreferencemode) | OH_TemporalGopReferenceMode | Enumerates the reference modes of temporal image groups.|
| [OH_BitrateMode](#oh_bitratemode) | OH_BitrateMode | Enumerates the bit rate modes of an encoder.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_AVCodecOnError)(OH_AVCodec *codec, int32_t errorCode, void *userData)](#oh_avcodeconerror) | OH_AVCodecOnError | Defines the pointer to the function that is called to report error information when an error occurs during the running of an OH_AVCodec instance.|
| [typedef void (\*OH_AVCodecOnStreamChanged)(OH_AVCodec *codec, OH_AVFormat *format, void *userData)](#oh_avcodeconstreamchanged) | OH_AVCodecOnStreamChanged | Defines the pointer to the function that is called to report the new stream description when the resolution of the input stream being decoded or the output stream that has been encoded changes. Note that the lifecycle of the pointer to the OH_AVFormat instance is valid only when the function pointer is being called. Do not access the pointer to the instance after the function pointer is called.|
| [typedef void (\*OH_AVCodecOnNeedInputData)(OH_AVCodec *codec, uint32_t index, OH_AVMemory *data, void *userData)](#oh_avcodeconneedinputdata) | OH_AVCodecOnNeedInputData | Defines the pointer to the function that is called when new input data is required during the running of an OH_AVCodec instance. The function carries a buffer to fill in new input data.|
| [typedef void (\*OH_AVCodecOnNewOutputData)(OH_AVCodec *codec, uint32_t index, OH_AVMemory *data,OH_AVCodecBufferAttr *attr, void *userData)](#oh_avcodeconnewoutputdata) | OH_AVCodecOnNewOutputData | Defines the pointer to the function that is called when new output data is generated during the running of an OH_AVCodec instance. The function carries a buffer filled with new output data. Note that the lifecycle of the pointer to the OH_AVCodecBufferAttr instance is valid only when the function pointer is being called. Do not access the pointer to the instance after the function pointer is called.|
| [typedef void (\*OH_AVCodecOnNeedInputBuffer)(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *buffer, void *userData)](#oh_avcodeconneedinputbuffer) | OH_AVCodecOnNeedInputBuffer | Defines the pointer to the function that is called when new input data is required during the running of an OH_AVCodec instance. The function carries a buffer to fill in new input data.|
| [typedef void (\*OH_AVCodecOnNewOutputBuffer)(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *buffer, void *userData)](#oh_avcodeconnewoutputbuffer) | OH_AVCodecOnNewOutputBuffer | Defines the pointer to the function that is called when new output data is generated during the running of an OH_AVCodec instance. The function carries a buffer filled with new output data.|
| [typedef int32_t (\*OH_AVDataSourceReadAt)(OH_AVBuffer *data, int32_t length, int64_t pos)](#oh_avdatasourcereadat) | OH_AVDataSourceReadAt | Defines a function pointer used to provide the capability of obtaining user-defined media data.|
| [typedef int32_t (\*OH_AVDataSourceReadAtExt)(OH_AVBuffer *data, int32_t length, int64_t pos, void *userData)](#oh_avdatasourcereadatext) | OH_AVDataSourceReadAtExt | Defines a function pointer used to provide the capability of obtaining user-defined media data.|

### Variables

| Name| Description|
| -- | -- |
| const char * OH_AVCODEC_MIMETYPE_VIDEO_AVC | Pointer to the key that describes the MIME type of the AVC (H.264) video codec.<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_AAC | Pointer to the key that describes the MIME type of the AAC audio codec.<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_FLAC | Pointer to the key that describes the MIME type of the FLAC audio codec.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_VORBIS | Pointer to the key that describes the MIME type of the Vorbis audio decoder.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_MPEG | Pointer to the key that describes the MIME type of the MP3 audio codec.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_HEVC | Pointer to the key that describes the MIME type of the HEVC (H.265) video codec.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_MPEG4 | Pointer to the key that describes the MIME type of the MPEG4 video encoder, which is used only for multiplexing MPEG4 video streams.<br>**Since**: 10<br>**Deprecated from**: 11<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_MPEG4_PART2 | Pointer to the key that describes the MIME type of the MPEG4 Part 2 video codec.<br>**Since**: 17<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_MPEG2 | Pointer to the key that describes the MIME type of the MPEG2 video codec.<br>**Since**: 17<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_H263 | Pointer to the key that describes the MIME type of the H.263 video codec.<br>**Since**: 17<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_IMAGE_JPG | Pointer to the key that describes the MIME type of the JPG image encoder, which is used only for multiplexing JPG covers.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_IMAGE_PNG | Pointer to the key that describes the MIME type of the PNG image encoder, which is used only for multiplexing PNG covers.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_IMAGE_BMP | Pointer to the key that describes the MIME type of the BMP image encoder, which is used only for multiplexing BMP covers.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_VIVID | Pointer to the key that describes the MIME type of the Audio Vivid audio decoder. <!--Del-->(This specification is not available yet.)<!--DelEnd--><br>**Since**: 11<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_AMR_NB | Pointer to the key that describes the MIME type of the AMR-NB audio decoder.<br>**Since**: 11<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_AMR_WB | Pointer to the key that describes the MIME type of the AMR-WB audio decoder.<br>**Since**: 11<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_OPUS | Pointer to the key that describes the MIME type of the Opus audio codec. <!--Del-->(This specification is not available yet.)<!--DelEnd--><br>**Since**: 11<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_G711MU | Pointer to the key that describes the MIME type of the G.711 mu-law audio codec.<br>**Since**: 11<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_VVC | Pointer to the key that describes the MIME type of the VVC (H.266) video codec.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_APE | Pointer to the key that describes the MIME type of the APE audio decoder.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_SUBTITLE_SRT | Pointer to the key that describes the MIME type of the SRT subtitle demuxer.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_SUBTITLE_WEBVTT | Pointer to the key that describes the MIME type of the WEBVTT subtitle demuxer.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_RAW | Pointer to the key that describes the MIME type of raw audio streams.<br>**Since**: 18<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_G711A | Pointer to the key that describes the MIME type of the G.711 a-law audio decoder.<br>**Since**: 20<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_ED_KEY_TIME_STAMP | Pointer to the key that describes the surface buffer timestamp. The value is of the int64_t type.<br>**Since**: 9<br>**Deprecated from**: 14<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_ED_KEY_EOS | Pointer to the key that describes the end of stream for the surface buffer. The value type is int32_t.<br>**Since**: 9<br>**Deprecated from**: 14<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_TRACK_TYPE | Pointer to the key that describes the track type in a media file. The value type is int32_t. For details, see [OH_MediaType](#oh_mediatype).<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_CODEC_MIME | Pointer to the key that describes the MIME type of the codec. The value type is string.<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_DURATION | Pointer to the key that describes the duration in a media file, in microseconds. The value type is int64_t.<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_BITRATE | Pointer to the key that describes the bit rate. The value type is int64_t.<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_MAX_INPUT_SIZE | Pointer to the key that describes the maximum size of an input stream to decode. The value type is int32_t.<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_WIDTH | Pointer to the key that describes the video width. The value type is int32_t.<br>This key is used to set the display width of a video frame when **Configure** is called during video encoding and decoding.<br>For details about the development guide, see step 5 in surface mode or step 4 in buffer mode in [Video Encoding](../../media/avcodec/video-encoding.md).<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_HEIGHT | Pointer to the key that describes the video height. The value type is int32_t.<br>This key is used to set the display height of a video frame when **Configure** is called during video encoding and decoding.<br>For details about the development guide, see step 5 in surface mode or step 4 in buffer mode in [Video Encoding](../../media/avcodec/video-encoding.md).<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_PIXEL_FORMAT | Pointer to the key that describes the video pixel format. The value type is int32_t. For details, see [OH_AVPixelFormat](_core.md#oh_avpixelformat-1).<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_AUDIO_SAMPLE_FORMAT | Pointer to the key that describes the original audio format. The value type is int32_t. For details, see [OH_BitsPerSample](#oh_bitspersample).<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_FRAME_RATE | Pointer to the key that describes the video frame rate. The value type is double. The value must be greater than **0**.<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE | Pointer to the key that describes the video encoding bit rate mode. The value type is int32_t. For details, see [OH_BitrateMode](#oh_bitratemode).<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_PROFILE | Pointer to the key that describes the encoding grading. The value type is int32_t. For details, see [OH_AVCProfile](#oh_avcprofile), [OH_HEVCProfile](#oh_hevcprofile), and [OH_AACProfile](#oh_aacprofile).<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_AUD_CHANNEL_COUNT | Pointer to the key that describes the number of audio channels. The value type is int32_t.<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_AUD_SAMPLE_RATE | Pointer to the key that describes the audio sampling rate. The value type is int32_t.<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_I_FRAME_INTERVAL | Pointer to the key that describes the key frame interval, in milliseconds. The value type is int32_t. This key is optional and is used only for video encoding.<br>A negative value indicates that only the first frame is a key frame, and a zero value indicates that all frames are key frames.<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_ROTATION | Pointer to the key that describes the rotation angle of the surface. The value type is int32_t, and the value range is {0, 90, 180, 270}. The default value is 0.<br>This key is optional and is used only for video decoding in surface mode<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_RANGE_FLAG | Pointer to the key that describes the video YUV value range flag. The value type is int32_t. The value **1** means a full range, and **0** means a limited range.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_COLOR_PRIMARIES | Pointer to the key that describes the video primary colors. The value type is int32_t. For details, see [OH_ColorPrimary](#oh_colorprimary). The value complies with Table 2 in H.273.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_TRANSFER_CHARACTERISTICS | Pointer to the key that describes the video transfer characteristics. The value type is int32_t. For details, see [OH_TransferCharacteristic](#oh_transfercharacteristic). The value complies with Table 3 in H.273.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_MATRIX_COEFFICIENTS | Pointer to the key that describes the video matrix coefficients. The value type is int32_t. For details, see [OH_MatrixCoefficient](#oh_matrixcoefficient). The value complies with Table 4 in H.273.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_REQUEST_I_FRAME | Pointer to the key that describes the request for immediate encoding of I-frames. The value type is int32_t. This key is used in [OH_VideoEncoder_SetParameter](_video_encoder.md#oh_videoencoder_setparameter) or takes effect immediately with each frame.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_QUALITY | Pointer to the key that describes the required encoding quality. The value type is int32_t. In H.264 and H.265 encoding scenarios, the value range can be obtained by calling [OH_AVCapability_GetEncoderQualityRange](capi-native-avcapability-h.md#oh_avcapability_getencoderqualityrange). This key applies only to the encoder in constant quality mode.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_CODEC_CONFIG | Pointer to the key that describes the codec-specific data. In the case of video, data carried in **SPS/PPS** is transferred. In the case of audio, data carried in **extraData** is transferred. The value type is uint8_t*. <!--Del-->(This key is not supported yet for the video codec.)<!--DelEnd--><br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_TITLE | Pointer to the key that describes the title in a media file. The value type is string.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_ARTIST | Pointer to the key that describes the lyrics in a media file. The value type is string.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_ALBUM | Pointer to the key that describes the album in a media file. The value type is string.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_ALBUM_ARTIST | Pointer to the key that describes the album artist of the input media. The value type is string.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_DATE | Pointer to the key that describes the date in a media file, for example, 2024. The value type is string.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_COMMENT | Pointer to the key that describes the comment in a media file. The value type is string.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_GENRE | Pointer to the key that describes the genre in a media file. The value type is string.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_COPYRIGHT | Pointer to the key that describes the copyright in a media file. The value type is string.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_LANGUAGE | Pointer to the key that describes the language in a media file. The value type is string.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_DESCRIPTION | Pointer to the key that describes the description in a media file. The value type is string.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_LYRICS | Pointer to the key that describes the lyrics in a media file. The value type is string.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_TRACK_COUNT | Pointer to the key that describes the number of tracks in a media file. The value type is int32_t.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_CHANNEL_LAYOUT | Pointer to the key that describes the required encoding channel layout. The value type is int64_t. This key applies only to encoders. For details, see [OH_AudioChannelLayout](_core.md#oh_audiochannellayout-1).<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_BITS_PER_CODED_SAMPLE | Pointer to the key that describes the number of bits per sample. The value type is int32_t.<br>In versions earlier than API version 20, this parameter must be set to **1** for FLAC encoding. Otherwise, **OH_AudioCodec_Configure** returns the error code **AV_ERR_INVALID_VAL**. However, this parameter has no actual effect and does not affect the encoding result.<br>Starting from API version 20, you do not need to set it anymore.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_AAC_IS_ADTS | Pointer to the key that describes the AAC format, which can be ADTS or LATM. The value type is int32_t. The value **0** means the LATM format, and **1** means the ADTS format. This key is supported by AAC decoders.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_SBR | Pointer to the key that describes the AAC SBR format. The value type is int32_t. This key applies to AAC encoders.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_COMPLIANCE_LEVEL | Pointer to the key that describes the FLAC compliance level. The value type is int32_t. This key is used only for audio encoding.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_IDENTIFICATION_HEADER | Pointer to the key that describes the vorbis identification header. The value type is uint8_t*. This key applies only to Vorbis decoders.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_SETUP_HEADER | Pointer to the key that describes the vorbis setup header. The value type is uint8_t*. This key applies only to Vorbis decoders.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_SCALING_MODE | Pointer to the key that describes the video scaling mode. The value type is int32_t. For details, see [OH_ScalingMode](#oh_scalingmode).<br>You are advised to set the scaling mode by calling [OH_NativeWindow_NativeWindowSetScalingModeV2](../apis-arkgraphics2d/capi-external-window-h.md#oh_nativewindow_nativewindowsetscalingmodev2). This key is optional and is used only for video decoding in surface mode.<br>**Since**: 10<br>**Deprecated from**: 14<br>**Substitute**: [OH_NativeWindow_NativeWindowSetScalingModeV2](../apis-arkgraphics2d/capi-external-window-h.md#oh_nativewindow_nativewindowsetscalingmodev2)<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_MAX_INPUT_BUFFER_COUNT | Pointer to the key that describes the maximum number of input buffers. The value type is int32_t.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_MAX_OUTPUT_BUFFER_COUNT | Pointer to the key that describes the maximum number of output buffers. The value type is int32_t.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_AUDIO_COMPRESSION_LEVEL | Pointer to the key that describes the audio codec compression level. The value type is int32_t type. This key is used only for audio encoding.<br>**Since**: 11<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_IS_HDR_VIVID | Pointer to the key that specifies whether the video track in a media file is HDR Vivid. The value type is int32_t. This key is used for both multiplexing and demultiplexing.<br>The value **1** means the HDR Vivid video track, and **0** means other cases.<br>**Since**: 11<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_AUDIO_OBJECT_NUMBER | Pointer to the key that describes the number of audio objects. The value type is int32_t. This key is used only for Audio Vivid decoding.<br>**Since**: 11<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_AUDIO_VIVID_METADATA | Pointer to the key that describes the Audio Vivid metadata. The value type is uint8_t*. This key is used only for Audio Vivid decoding.<br>**Since**: 11<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_FEATURE_PROPERTY_KEY_VIDEO_ENCODER_MAX_LTR_FRAME_COUNT | Pointer to the key that describes the maximum number of long-term reference (LTR) frames obtained during video encoding. The value type is int32_t. You can use the API [OH_AVCapability_GetFeatureProperties](capi-native-avcapability-h.md#oh_avcapability_getfeatureproperties) and the enumerated value **VIDEO_ENCODER_LONG_TERM_REFERENCE** in [OH_AVCapabilityFeature](capi-native-avcapability-h.md#oh_avcapabilityfeature) to query the maximum number.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_ENABLE_TEMPORAL_SCALABILITY | Pointer to the key that describes the enabled status of temporal scalability. The value type is int32_t. The value **1** means temporal scalability is enabled, and **0** means the opposite.<br>You can use the API [OH_AVCapability_IsFeatureSupported](capi-native-avcapability-h.md#oh_avcapability_isfeaturesupported) and the enumerated value **VIDEO_ENCODER_TEMPORAL_SCALABILITY** in [OH_AVCapabilityFeature](capi-native-avcapability-h.md#oh_avcapabilityfeature) to check whether the current video encoder supports temporal scalability. For details, see [Temporally Scalable Video Coding](../../media/avcodec/video-encoding-temporal-scalability.md#available-apis).<br>This key is optional and used only in the configuration phase of video encoding.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_SIZE | Pointer to the key that describes the size of a temporal image group. The value type is int32_t. This key is valid only when temporal scalability is enabled.<br>This key is optional and used only in the configuration phase of video encoding.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_REFERENCE_MODE | Pointer to the key that describes the reference mode in a temporal image group. The value type is int32_t. For details, see [OH_TemporalGopReferenceMode](#oh_temporalgopreferencemode). This key is valid only when temporal scalability is enabled.<br>This key is optional and used only in the configuration phase of video encoding.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_LTR_FRAME_COUNT | Pointer to the key that describes the number of LTR frames. The value type is int32_t. The value must be within the supported value range.<br>Before using this key, you can use the API [OH_AVCapability_GetFeatureProperties](capi-native-avcapability-h.md#oh_avcapability_getfeatureproperties) and the enumerated value **VIDEO_ENCODER_LONG_TERM_REFERENCE** in [OH_AVCapabilityFeature](capi-native-avcapability-h.md#oh_avcapabilityfeature) to query the number of supported LTR frames.<br>This key is optional and used only in the configuration phase of video encoding.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_MARK_LTR | Pointer to the key that specifies whether the current frame is marked as an LTR frame. The value type is int32_t. The value **1** means that the frame is marked as an LTR frame, and **0** means the opposite.<br>This key takes effect only after the number of LTR frames is configured.<br>This key is optional and is used only for video encoding input rotation. The configuration takes effect immediately.<br>For details, see [Temporally Scalable Video Coding](../../media/avcodec/video-encoding-temporal-scalability.md#available-apis).<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_USE_LTR | Pointer to the key that describes the POC number of the LTR frame referenced by the current frame. The value type is int32_t.<br>This key is optional and is used only for video encoding input rotation. The configuration takes effect immediately.<br>For details, see [Temporally Scalable Video Coding](../../media/avcodec/video-encoding-temporal-scalability.md#available-apis).<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_PER_FRAME_IS_LTR | Pointer to the key that specifies whether the frame corresponding to the stream output from the current OH_AVBuffer is marked as an LTR frame. The value type is int32_t. The value **1** means that the frame is an LTR frame, and **0** means the opposite.<br>This key is optional and is used only for video encoding output rotation.<br>It indicates the attribute of a frame.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_PER_FRAME_POC | Pointer to the key that describes the POC of the frame. The value type is int32_t.<br>This key is optional and is used only for video encoding output rotation.<br>It indicates the attribute of a frame.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_CROP_TOP | Pointer to the key that describes the top coordinate (y) of the cropped rectangle. The value type is int32_t.<br>The row at the top of the cropped rectangle is contained, and the row index starts from 0.<br>This key is used only for video decoding.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_CROP_BOTTOM | Pointer to the key that describes the bottom coordinate (y) of the cropped rectangle. The value type is int32_t.<br>The row at the bottom of the cropped rectangle is contained, and the row index starts from 0.<br>This key is used only for video decoding.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_CROP_LEFT | Pointer to the key that describes the left coordinate (x) of the cropped rectangle. The value type is int32_t.<br>The leftmost column of the cropped rectangle is contained, and the column index starts from 0.<br>This key is used only for video decoding.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_CROP_RIGHT | Pointer to the key that describes the right coordinate (x) of the cropped rectangle. The value type is int32_t.<br>The rightmost column of the cropped rectangle is contained, and the column index starts from 0.<br>This key is used only for video decoding.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_STRIDE | Pointer to the key that describes the stride of the video frame. The value type is int32_t.<br>The stride is the difference between the index of the pixel and the index of the pixel right below.<br>For the YUV420 format, the stride corresponds to the Y plane. The stride of the U/V plane can be calculated based on the color format, but it is usually not defined and depends on the device and version.<br>For details, see step 3 in buffer mode in [Video Encoding](../../media/avcodec/video-encoding.md#buffer-mode).<br>For details about the image arrangement and usage examples of **width**, **height**, **wStride**, and **hStride**, see step 8 in buffer mode in [Video Encoding](../../media/avcodec/video-encoding.md#buffer-mode) or step 11 in buffer mode in [Video Decoding](../../media/avcodec/video-decoding.md#buffer-mode).<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_SLICE_HEIGHT | Pointer to the key that describes the height of the video frame. The value type is int32_t.<br>The height is the number of rows that must be offset from the top of the Y plane to the top of the U plane. Essentially, the offset of the U plane is sliceHeight \* stride.<br>The height of the U/V plane can be calculated based on the color format, but it is usually not defined and depends on the device and version.<br>For details, see step 3 in buffer mode in [Video Encoding](../../media/avcodec/video-encoding.md#buffer-mode).<br>For details about the image arrangement and usage examples of **width**, **height**, **wStride**, and **hStride**, see step 8 in buffer mode in [Video Encoding](../../media/avcodec/video-encoding.md#buffer-mode) or step 11 in buffer mode in [Video Decoding](../../media/avcodec/video-decoding.md#buffer-mode).<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_PIC_WIDTH | Pointer to the key that describes the width of the video frame. The value type is int32_t.<br>When [OH_VideoDecoder_GetOutputDescription](_video_decoder.md#oh_videodecoder_getoutputdescription) is called during video decoding, the width can be parsed from the returned OH_AVFormat instance.<br>When the decoded output stream<!--RP2--><!--RP2End--> changes, the width can be parsed from the OH_AVForamt instance returned by [OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged).<br>The width and height parsed from the OH_AVFormat instance are aligned, which are different from **OH_MD_KEY_WIDTH** and **OH_MD_KEY_HEIGHT** set by calling **Configure**.<br>For details about the image arrangement and usage examples of **width**, **height**, **wStride**, and **hStride**, see step 8 in buffer mode in [Video Encoding](../../media/avcodec/video-encoding.md#buffer-mode) or step 11 in buffer mode in [Video Decoding](../../media/avcodec/video-decoding.md#buffer-mode).<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_PIC_HEIGHT | Pointer to the key that describes the height of the video frame. The value type is int32_t.<br>When [OH_VideoDecoder_GetOutputDescription](_video_decoder.md#oh_videodecoder_getoutputdescription) is called during video decoding, the height can be parsed from the returned OH_AVFormat instance.<br>When the decoded output stream<!--RP2--><!--RP2End--> changes, the height can be parsed from the OH_AVForamt instance returned by [OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged).<br>The width and height parsed from the OH_AVFormat instance are aligned, which are different from **OH_MD_KEY_WIDTH** and **OH_MD_KEY_HEIGHT** set by calling **Configure**.<br>For details about the image arrangement and usage examples of **width**, **height**, **wStride**, and **hStride**, see step 8 in buffer mode in [Video Encoding](../../media/avcodec/video-encoding.md#buffer-mode) or step 11 in buffer mode in [Video Decoding](../../media/avcodec/video-decoding.md#buffer-mode).<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENABLE_LOW_LATENCY | Pointer to the key that describes the enabled status of low-latency video codec. The value type is int32_t. The value **1** means that low-latency video codec is enabled, and **0** means the opposite.<br>This key is optional and used only in the configuration phase.<br>If enabled, the input and output data held by the video encoder or decoder does not exceed the amount required by the codec standard.<br>If supported by the platform, the video decoder outputs frames in the decoding sequence when low-latency video codec is enabled.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_QP_MAX | Pointer to the key that describes the maximum Quantization Parameter (QP) allowed by the video encoder. The value type is int32_t.<br>This key is used in the configuration or parameter setting phase or takes effect immediately with each frame.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_QP_MIN | Pointer to the key that describes the minimum QP allowed by the video encoder. The value type is int32_t.<br>This key is used in the configuration or parameter setting phase or takes effect immediately with each frame.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_QP_AVERAGE | Pointer to the key that describes the average QP of video frames. The value type is int32_t.<br>Pointer to the key that describes the average QP value of the current frame encoding block. It is output with [OH_AVBuffer](_core.md#oh_avbuffer)<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_MSE | Pointer to the key that describes the Mean Squared Error (MSE) of video frames. The value type is double.<br>Pointer to the key that describes the average MSE value of the current frame encoding block. It is output with [OH_AVBuffer](_core.md#oh_avbuffer)<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_DECODING_TIMESTAMP | Pointer to the key that describes the decoding timestamp corresponding to the audio, video, or subtitle sample carried in AVBuffer, in microseconds. The value type is int64_t.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_BUFFER_DURATION | Pointer to the key that describes the duration corresponding to the audio, video, or subtitle sample carried in AVBuffer, in microseconds. The value type is int64_t.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_SAR | Pointer to the key that describes the aspect ratio of the sample. The value type is double.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_START_TIME | Pointer to the key that describes the start time of the first frame in a media file, measured in microseconds. The value type is int64_t.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_TRACK_START_TIME | Pointer to the key that describes the start time of the track, measured in microseconds. The value type is int64_t.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_DECODER_OUTPUT_COLOR_SPACE | Pointer to the key that describes the output color space of the video decoder. The value type is int32_t.<br>The supported value is **OH_COLORSPACE_BT709_LIMIT**. For details, see [OH_NativeBuffer_ColorSpace](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_colorspace).<br>It is used when [OH_VideoDecoder_Configure](_video_decoder.md#oh_videodecoder_configure) is called.<br>Before calling **OH_VideoDecoder_Start**, you must call **OH_VideoDecoder_Prepare**.<br>If Color Space Conversion (CSC) is supported and this key is configured, the video decoder automatically transcodes the HDR Vivid video to the specified color space.<br>If CSC function not supported, the error code **AV_ERR_VIDEO_UNSUPPORTED_COLOR_SPACE_CONVERSION** in [OH_AVErrCode](_core.md#oh_averrcode-1) is returned when [OH_VideoDecoder_Configure](_video_decoder.md#oh_videodecoder_configure) is called.<br>If the input video is not an HDR Vivid video, the callback function [OH_AVCodecOnError](#oh_avcodeconerror) is invoked to report the error code **AV_ERR_VIDEO_UNSUPPORTED_COLOR_SPACE_CONVERSION** in [OH_AVErrCode](_core.md#oh_averrcode-1).<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_DECODER_OUTPUT_ENABLE_VRR | Pointer to the key that specifies whether the decoder enables the video variable frame rate feature. The value type is int32_t.<br>**1** if enabled, **0** otherwise.<br>**Since**: 15<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_CREATION_TIME | Pointer to the key that describes the media file creation time. The value type is string. The value must be in the UTC time format complying with ISO 8601. An example time format is 2024-12-28T00:00:00:000000Z.<br>**Since**: 14<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER | Pointer to the key that describes the duration (in milliseconds) for which the last frame will be resubmitted repeatedly, if no new frame is available after the previous frame is submitted to the encoder. The value type is int32_t.<br>This key is used only in the configuration phase of video encoding in surface mode.<br>Configured value.<br>- If the value is less than or equal to 0, the request is intercepted in the configuration phase and **ERROR AV_ERR_INVALID_VAL** is returned.<br>- If the value is greater than 0, the last frame will be resubmitted repeatedly in the specified duration, measured in milliseconds.<br>**Since**: 18<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_MAX_COUNT | Pointer to the key that describes the maximum number of times the encoder can repeat encoding the previous frame when no new frame is available. The value type is int32_t.<br>This key takes effect only when **OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER** is available and is used only in the configuration phase.<br>Configured value.<br>- If the value is equal to 0, the request is intercepted in the configuration phase and **ERROR AV_ERR_INVALID_VAL** is returned.<br>- If the value is less than 0 and no new frame is available, the encoder repeatedly encodes the previous frame until the upper limit of the system is reached.<br>- If the value is greater than 0 and no new frame is available, the encoder repeatedly encodes the previous frame until the maximum number specified is reached.<br>**Since**: 18<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS | Pointer to the key that describes the enabled status of ROI encoding in video encoding, with ROI parameters delivered. The parameters take effect immediately with the frame.<br>The value must be in the format of "Top1,Left1-Bottom1,Right1=Offset1;Top2,Left2-Bottom2,Right2=Offset2;", where multiple ROI parameters are separated by semicolons (;).<br>**Top**, **Left**, **Bottom**, and **Right** specify the upper, left, bottom, and right boundaries of an ROI area, respectively. **Offset** specifies deltaQP. **(=Offset)** can be omitted. If it is omitted, the default value (**–3**) is used.<br>**Since**: 20<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_SQR_FACTOR | Pointer to the key that describes the quality parameter in SQR mode. The value range is [0, 51] (same as the QP value in encoding). A smaller value indicates a higher output bit rate and better quality.<br>It is used in the configuration or parameter setting phase.<br>**Since**: 20<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_MAX_BITRATE | Pointer to the key that describes the maximum bit rate in SQR mode. The value range can be obtained by calling [OH_AVCapability_GetEncoderBitrateRange](capi-native-avcapability-h.md#oh_avcapability_getencoderbitraterange) and is the same as that of **OH_MD_KEY_BITRATE**. The unit is bit/s.<br>It is used in the configuration or parameter setting phase.<br>**Since**: 20<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_ENABLE_PTS_BASED_RATECONTROL | Pointer to the key that describes the enabled status of the PTS-based bit rate control mode. The value type is int32_t. **1** if enabled, **0** otherwise.<br>This key is optional and used only for video encoding. The default value is **0**.<br>If this feature is enabled, each video frame must contain PTS information and be sent to the encoder. In surface mode, the PTS is set by calling [OH_NativeWindow_NativeWindowHandleOpt](../apis-arkgraphics2d/capi-external-window-h.md#oh_nativewindow_nativewindowhandleopt), in units of nanosecond (ns). In buffer mode, the PTS is set by calling [OH_AVBuffer_SetBufferAttr](_core.md#oh_avbuffer_setbufferattr), in units of microsecond (us).<br>It is used in the configuration phase.<br>**Since**: 20<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_REFERENCE_TRACK_IDS | Pointer to the key that describes the reference relationship between media file tracks. The value type is int32_t\*.<br>**Since**: 20<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_TRACK_REFERENCE_TYPE | Pointer to the key that describes the auxiliary track type of a media file. The value type is string.<br>**Since**: 20<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_TRACK_DESCRIPTION | Pointer to the key that describes the auxiliary track description of a media file. The value type is string.<br>**Since**: 20<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_ENABLE_SYNC_MODE | Pointer to the key that describes the enabled status of video codec synchronization. The value type is int32_t. The value **1** means that low-latency video codec is enabled, and **0** means the opposite. This key is optional. The default value is **0**.<br>If this feature is enabled, pay attention to the following:<br> 1. The codec cannot have a callback function.<br> 2. You must use the buffer query API instead of the callback function.<br> 3. The key can be used only in the configuration phase.<br>**Since**: 20<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|

## Enum Description

### OH_MediaType

```
enum OH_MediaType
```

**Description**

Enumerates the media types.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

| Value| Description|
| -- | -- |
| MEDIA_TYPE_AUD = 0 | Audio track.|
| MEDIA_TYPE_VID = 1 | Video track.|
| MEDIA_TYPE_SUBTITLE = 2 | Subtitle track.<br>**Since**: 12|
| MEDIA_TYPE_TIMED_METADATA = 5 | Timed metadata track.<br>**Since**: 20|
| MEDIA_TYPE_AUXILIARY = 6 | Auxiliary track.<br>**Since**: 20|

### OH_AACProfile

```
enum OH_AACProfile
```

**Description**

Enumerates the Advanced Audio Coding (AAC) profiles.<!--Del--><br>(**AAC_PROFILE_HE** and **AAC_PROFILE_HE_V2** are not available yet.)<!--DelEnd-->

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

| Value| Description|
| -- | -- |
| AAC_PROFILE_LC = 0 | AAC profile of the low complexity level.|
| AAC_PROFILE_HE  | AAC profile of the high efficiency level. <!--Del-->(This specification is not available yet.)<!--DelEnd--><br>**Since**: 14|
| AAC_PROFILE_HE_V2 | AAC profile of the high efficiency V2 level. <!--Del-->(This specification is not available yet.)<!--DelEnd--><br>**Since**: 14|

### OH_AVCProfile

```
enum OH_AVCProfile
```

**Description**

Enumerates the AVC profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

| Value| Description|
| -- | -- |
| AVC_PROFILE_BASELINE = 0 | AVC baseline profile.|
| AVC_PROFILE_HIGH = 4 | AVC high profile.|
| AVC_PROFILE_MAIN = 8 | AVC main profile.|

### OH_HEVCProfile

```
enum OH_HEVCProfile
```

**Description**

Enumerates the HEVC profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description|
| -- | -- |
| HEVC_PROFILE_MAIN = 0 | HEVC profile of the main level.|
| HEVC_PROFILE_MAIN_10 = 1 | HEVC profile of the 10-bit main level.|
| HEVC_PROFILE_MAIN_STILL = 2 | HEVC profile of the main still picture level.|
| HEVC_PROFILE_MAIN_10_HDR10 = 3 | HEVC profile of the main 10 HDR10 level.<br>**Deprecated from**: 14|
| HEVC_PROFILE_MAIN_10_HDR10_PLUS = 4 | HEVC profile of the main 10 HDR10+ level.<br>**Deprecated from**: 14|

### OH_VVCProfile

```
enum OH_VVCProfile
```

**Description**

Enumerates the VVC profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 15

| Value| Description|
| -- | -- |
| VVC_PROFILE_MAIN_10 = 1 | VVC profile of the 10-bit main level.|
| VVC_PROFILE_MAIN_12 = 2 | VVC profile of the 12-bit main level.|
| VVC_PROFILE_MAIN_12_INTRA = 10 | VVC profile of the 12-bit intra main level.|
| VVC_PROFILE_MULTI_MAIN_10 = 17 | VVC profile of the 10-bit main level for multi-layer encoding.|
| VVC_PROFILE_MAIN_10_444 = 33 | VVC profile of the 10-bit full-sample main level.|
| VVC_PROFILE_MAIN_12_444 = 34 | VVC profile of the 12-bit full-sample main level.|
| VVC_PROFILE_MAIN_16_444 = 36 | VVC profile of the 16-bit full-sample main level.|
| VVC_PROFILE_MAIN_12_444_INTRA = 42 | VVC profile of the 12-bit full-sample intra main level.|
| VVC_PROFILE_MAIN_16_444_INTRA = 44 | VVC profile of the 16-bit full-sample intra main level.|
| VVC_PROFILE_MULTI_MAIN_10_444 = 49 | VVC profile of the 10-bit full-sample main level for multi-layer encoding.|
| VVC_PROFILE_MAIN_10_STILL = 65 | VVC profile of the 10-bit still picture main level.|
| VVC_PROFILE_MAIN_12_STILL = 66 | VVC profile of the 12-bit still picture main level.|
| VVC_PROFILE_MAIN_10_444_STILL = 97 | VVC profile of the 10-bit full-sample still picture main level.|
| VVC_PROFILE_MAIN_12_444_STILL = 98 | VVC profile of the 12-bit full-sample still picture main level.|
| VVC_PROFILE_MAIN_16_444_STILL = 100 | VVC profile of the 16-bit full-sample still picture main level.|

### OH_MPEG2Profile

```
enum OH_MPEG2Profile
```

**Description**

Enumerates the MPEG2 profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 17

| Value| Description|
| -- | -- |
| MPEG2_PROFILE_SIMPLE = 0 | Simple profile.|
| MPEG2_PROFILE_MAIN  = 1 | Main profile.|
| MPEG2_PROFILE_SNR_SCALABLE  = 2 | Signal-to-Noise Ratio (SNR) scalable profile.|
| MPEG2_PROFILE_SPATIALLY_SCALABLE = 3 | Spatial scalable profile.|
| MPEG2_PROFILE_HIGH = 4 | High profile.|
| MPEG2_PROFILE_422 = 5 | 4:2:2 profile.|

### OH_MPEG4Profile

```
enum OH_MPEG4Profile
```

**Description**

Enumerates the MPEG4 profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 17

| Value| Description|
| -- | -- |
| MPEG4_PROFILE_SIMPLE = 0 | Simple profile.|
| MPEG4_PROFILE_SIMPLE_SCALABLE = 1 | Simple scalable profile.|
| MPEG4_PROFILE_CORE = 2 | Core profile.|
| MPEG4_PROFILE_MAIN = 3 | Main profile.|
| MPEG4_PROFILE_N_BIT  = 4 | N-bit profile.|
| MPEG4_PROFILE_HYBRID = 5 | Hybrid profile.|
| MPEG4_PROFILE_BASIC_ANIMATED_TEXTURE = 6 | Basic animated texture profile.|
| MPEG4_PROFILE_SCALABLE_TEXTURE = 7 | Scalable texture profile.|
| MPEG4_PROFILE_SIMPLE_FA = 8 | Simple FA profile.|
| MPEG4_PROFILE_ADVANCED_REAL_TIME_SIMPLE = 9 | Advanced real-time simple profile.|
| MPEG4_PROFILE_CORE_SCALABLE = 10 | Core scalable profile.|
| MPEG4_PROFILE_ADVANCED_CODING_EFFICIENCY = 11 | Advanced coding efficiency profile.|
| MPEG4_PROFILE_ADVANCED_CORE = 12 | Advanced core profile.|
| MPEG4_PROFILE_ADVANCED_SCALABLE_TEXTURE = 13 | Advanced scalable texture profile.|
| MPEG4_PROFILE_ADVANCED_SIMPLE = 17 | Advanced simple profile.|

### OH_H263Profile

```
enum OH_H263Profile
```

**Description**

Enumerates the H.263 profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 17

| Value| Description|
| -- | -- |
| H263_PROFILE_BASELINE = 0 | Baseline profile.|
| H263_PROFILE_VERSION_1_BACKWARD_COMPATIBILITY = 2 | Version 1 backward compatibility.|

### OH_AVOutputFormat

```
enum OH_AVOutputFormat
```

**Description**

Enumerates the output file formats supported by a muxer.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description|
| -- | -- |
| AV_OUTPUT_FORMAT_DEFAULT = 0 | Default format, which is MP4.|
| AV_OUTPUT_FORMAT_MPEG_4 = 2 | MP4.|
| AV_OUTPUT_FORMAT_M4A = 6 | M4A.|
| AV_OUTPUT_FORMAT_AMR = 8 | AMR.<br>**Since**: 12|
| AV_OUTPUT_FORMAT_MP3 = 9 | MP3.<br>**Since**: 12|
| AV_OUTPUT_FORMAT_WAV = 10 | WAV.<br>**Since**: 12|
| AV_OUTPUT_FORMAT_AAC = 11 | AAC.<br>**Since**: 18|
| AV_OUTPUT_FORMAT_FLAC = 12 | FLAC.<br>**Since**: 20|

### OH_AVSeekMode

```
enum OH_AVSeekMode
```

**Description**

Enumerates the seek modes.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description|
| -- | -- |
| SEEK_MODE_NEXT_SYNC = 0 | Seeks to the next I-frame at the specified position. If there is no I-frame after the specified position, the seek operation may fail.|
| SEEK_MODE_PREVIOUS_SYNC | Seeks to the previous I-frame at the specified position.|
| SEEK_MODE_CLOSEST_SYNC | Seeks to the latest I-frame at the specified position.|

### OH_ScalingMode

```
enum OH_ScalingMode
```

**Description**

Enumerates the scaling modes. This enum is used only in surface mode.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Deprecated from**: 14

**Substitute**: [OHScalingModeV2](../apis-arkgraphics2d/capi-external-window-h.md#ohscalingmodev2)

| Value| Description|
| -- | -- |
| SCALING_MODE_SCALE_TO_WINDOW = 1 | Scales the image based on the window size.<br>**Deprecated from**: 14<br>**Substitute**: [OHScalingModeV2](../apis-arkgraphics2d/capi-external-window-h.md#ohscalingmodev2).OH_SCALING_MODE_SCALE_TO_WINDOW_V2|
| SCALING_MODE_SCALE_CROP = 2 | Crops the image based on the window size.<br>**Deprecated from**: 14<br>**Substitute**: [OHScalingModeV2](../apis-arkgraphics2d/capi-external-window-h.md#ohscalingmodev2).OH_SCALING_MODE_SCALE_CROP_V2 |

### OH_BitsPerSample

```
enum OH_BitsPerSample
```

**Description**

Enumerates the number of audio bits for each coded sample.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description|
| -- | -- |
| SAMPLE_U8 = 0 | 8-bit unsigned integer sampling.|
| SAMPLE_S16LE = 1 | 16-bit signed integer sampling.|
| SAMPLE_S24LE = 2 | 24-bit signed integer sampling.|
| SAMPLE_S32LE = 3 | 32-bit signed integer sampling.|
| SAMPLE_F32LE = 4 | 32-bit floating-point sampling.|
| SAMPLE_U8P = 5 | 8-bit unsigned integer plane sampling.|
| SAMPLE_S16P = 6 | 16-bit signed integer plane sampling.|
| SAMPLE_S24P = 7 | 24-bit signed integer plane sampling.|
| SAMPLE_S32P = 8 | 32-bit signed integer plane sampling.|
| SAMPLE_F32P = 9 | 32-bit floating-point plane sampling.|
| INVALID_WIDTH = -1 | Invalid sampling format.|

### OH_ColorPrimary

```
enum OH_ColorPrimary
```

**Description**

Enumerates the primary colors. This enum is used for both encoding and decoding.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description|
| -- | -- |
| COLOR_PRIMARY_BT709 = 1 | BT.709 color gamut.|
| COLOR_PRIMARY_UNSPECIFIED = 2 | Unspecified color gamut.|
| COLOR_PRIMARY_BT470_M = 4 | BT.470 System M color gamut.|
| COLOR_PRIMARY_BT601_625 = 5 | BT.601 625 color gamut.|
| COLOR_PRIMARY_BT601_525 = 6 | BT.601 525 color gamut.|
| COLOR_PRIMARY_SMPTE_ST240 = 7 | SMPTE ST 240 color gamut.|
| COLOR_PRIMARY_GENERIC_FILM = 8 | Generic film color gamut.|
| COLOR_PRIMARY_BT2020 = 9 | BT.2020 color gamut.|
| COLOR_PRIMARY_SMPTE_ST428 = 10 | SMPTE ST 428 color gamut.|
| COLOR_PRIMARY_P3DCI = 11 | DCI-P3 color gamut.|
| COLOR_PRIMARY_P3D65 = 12 | P3-D65 color gamut.|

### OH_TransferCharacteristic

```
enum OH_TransferCharacteristic
```

**Description**

Enumerates the transfer characteristics. This enum is used for both encoding and decoding.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description|
| -- | -- |
| TRANSFER_CHARACTERISTIC_BT709 = 1 | BT.709 transfer function.|
| TRANSFER_CHARACTERISTIC_UNSPECIFIED = 2 | Unspecified transfer function.|
| TRANSFER_CHARACTERISTIC_GAMMA_2_2 = 4 | Gamma 2-2 transfer function.|
| TRANSFER_CHARACTERISTIC_GAMMA_2_8 = 5 | Gamma 2-8 transfer function.|
| TRANSFER_CHARACTERISTIC_BT601 = 6 | BT.601 transfer function.|
| TRANSFER_CHARACTERISTIC_SMPTE_ST240 = 7 | SMPTE ST 240 transfer function.|
| TRANSFER_CHARACTERISTIC_LINEAR = 8 | Linear transfer function.|
| TRANSFER_CHARACTERISTIC_LOG = 9 | Log transfer function.|
| TRANSFER_CHARACTERISTIC_LOG_SQRT = 10 | Log SQRT transfer function.|
| TRANSFER_CHARACTERISTIC_IEC_61966_2_4 = 11 | IEC61966-2.4 transfer function.|
| TRANSFER_CHARACTERISTIC_BT1361 = 12 | BT.1361 transfer function.|
| TRANSFER_CHARACTERISTIC_IEC_61966_2_1 = 13 | IEC61966 2.1 transfer function.|
| TRANSFER_CHARACTERISTIC_BT2020_10BIT = 14 | BT.2020 10-bit transfer function.|
| TRANSFER_CHARACTERISTIC_BT2020_12BIT = 15 | BT.2020 12-bit transfer function.|
| TRANSFER_CHARACTERISTIC_PQ = 16 | PQ transfer function.|
| TRANSFER_CHARACTERISTIC_SMPTE_ST428 = 17 | SMPTE ST.428 transfer function.|
| TRANSFER_CHARACTERISTIC_HLG = 18 | HLG transfer function.|

### OH_MatrixCoefficient

```
enum OH_MatrixCoefficient
```

**Description**

Enumerates the matrix coefficients. This enum is used for both encoding and decoding.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description|
| -- | -- |
| MATRIX_COEFFICIENT_IDENTITY = 0 | Identity matrix.|
| MATRIX_COEFFICIENT_BT709 = 1 | BT.709 conversion matrix.|
| MATRIX_COEFFICIENT_UNSPECIFIED = 2 | Unspecified conversion matrix.|
| MATRIX_COEFFICIENT_FCC = 4 | FCC conversion matrix.|
| MATRIX_COEFFICIENT_BT601_625 = 5 | BT.601 625 conversion matrix.|
| MATRIX_COEFFICIENT_BT601_525 = 6 | BT.601 525 conversion matrix.|
| MATRIX_COEFFICIENT_SMPTE_ST240 = 7 | SMPTE ST 240 conversion matrix.|
| MATRIX_COEFFICIENT_YCGCO = 8 | YCgCo conversion matrix.|
| MATRIX_COEFFICIENT_BT2020_NCL = 9 | BT.2020 NCL conversion matrix.|
| MATRIX_COEFFICIENT_BT2020_CL = 10 | BT.2020 CL conversion matrix.|
| MATRIX_COEFFICIENT_SMPTE_ST2085 = 11 | SMPTE ST 2085 conversion matrix.|
| MATRIX_COEFFICIENT_CHROMATICITY_NCL = 12 | Chromaticity NCL conversion matrix.|
| MATRIX_COEFFICIENT_CHROMATICITY_CL = 13 | Chromaticity CL conversion matrix.|
| MATRIX_COEFFICIENT_ICTCP = 14 | ICTCP conversion matrix.|

### OH_AVCLevel

```
enum OH_AVCLevel
```

**Description**

Enumerates the AVC levels.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12

| Value| Description|
| -- | -- |
| AVC_LEVEL_1 = 0 | Level 1.|
| AVC_LEVEL_1b = 1 | Level 1b.|
| AVC_LEVEL_11 = 2 | Level 1.1.|
| AVC_LEVEL_12 = 3 | Level 1.2.|
| AVC_LEVEL_13 = 4 | Level 1.3.|
| AVC_LEVEL_2 = 5 | Level 2.|
| AVC_LEVEL_21 = 6 | Level 2.1.|
| AVC_LEVEL_22 = 7 | Level 2.2.|
| AVC_LEVEL_3 = 8 | Level 3.|
| AVC_LEVEL_31 = 9 | Level 3.1.|
| AVC_LEVEL_32 = 10 | Level 3.2.|
| AVC_LEVEL_4 = 11 | Level 4.|
| AVC_LEVEL_41 = 12 | Level 4.1.|
| AVC_LEVEL_42 = 13 | Level 4.2.|
| AVC_LEVEL_5 = 14 | Level 5.|
| AVC_LEVEL_51 = 15 | Level 5.1.|
| AVC_LEVEL_52 = 16 | Level 5.2.|
| AVC_LEVEL_6 = 17 | Level 6.|
| AVC_LEVEL_61 = 18 | Level 6.1.|
| AVC_LEVEL_62 = 19 | Level 6.2.|

### OH_HEVCLevel

```
enum OH_HEVCLevel
```

**Description**

Enumerates the HEVC levels.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12

| Value| Description|
| -- | -- |
| HEVC_LEVEL_1 = 0 | Level 1.|
| HEVC_LEVEL_2 = 1 | Level 2.|
| HEVC_LEVEL_21 = 2 | Level 2.1.|
| HEVC_LEVEL_3 = 3 | Level 3.|
| HEVC_LEVEL_31 = 4 | Level 3.1.|
| HEVC_LEVEL_4 = 5 | Level 4.|
| HEVC_LEVEL_41 = 6 | Level 4.1.|
| HEVC_LEVEL_5 = 7 | Level 5.|
| HEVC_LEVEL_51 = 8 | Level 5.1.|
| HEVC_LEVEL_52 = 9 | Level 5.2.|
| HEVC_LEVEL_6 = 10 | Level 6.|
| HEVC_LEVEL_61 = 11 | Level 6.1.|
| HEVC_LEVEL_62 = 12 | Level 6.2.|

### OH_VVCLevel

```
enum OH_VVCLevel
```

**Description**

Enumerates the VVC levels.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 15

| Value| Description|
| -- | -- |
| VVC_LEVEL_1 = 16 | Level 1.0.|
| VVC_LEVEL_2 = 32 | Level 2.0.|
| VVC_LEVEL_21 = 35 | Level 2.1.|
| VVC_LEVEL_3 = 48 | Level 3.0.|
| VVC_LEVEL_31 = 51 | Level 3.1.|
| VVC_LEVEL_4 = 64 | Level 4.0.|
| VVC_LEVEL_41 = 67 | Level 4.1.|
| VVC_LEVEL_5 = 80 | Level 5.0.|
| VVC_LEVEL_51 = 83 | Level 5.1.|
| VVC_LEVEL_52 = 86 | Level 5.2.|
| VVC_LEVEL_6 = 96 | Level 6.0.|
| VVC_LEVEL_61 = 99 | Level 6.1.|
| VVC_LEVEL_62 = 102 | Level 6.2.|
| VVC_LEVEL_63 = 105 | Level 6.3.|
| VVC_LEVEL_155 = 255 | Level 15.5.|

### OH_MPEG2Level

```
enum OH_MPEG2Level
```

**Description**

Enumerates the MPEG2 levels.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 17

| Value| Description|
| -- | -- |
| MPEG2_LEVEL_LOW = 0 | Low level.|
| MPEG2_LEVEL_MAIN = 1 | Main level.|
| MPEG2_LEVEL_HIGH_1440 = 2 | High 1440 level.|
| MPEG2_LEVEL_HIGH = 3 | High level.|

### OH_MPEG4Level

```
enum OH_MPEG4Level
```

**Description**

Enumerates the MPEG4 levels.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 17

| Value| Description|
| -- | -- |
| MPEG4_LEVEL_0  = 0 | Level 0.|
| MPEG4_LEVEL_0B = 1 | Level 0B.|
| MPEG4_LEVEL_1  = 2 | Level 1.|
| MPEG4_LEVEL_2  = 3 | Level 2.|
| MPEG4_LEVEL_3  = 4 | Level 3.|
| MPEG4_LEVEL_3B = 5 | Level 3B.|
| MPEG4_LEVEL_4  = 6 | Level 4.|
| MPEG4_LEVEL_4A = 7 | Level 4A.|
| MPEG4_LEVEL_5  = 8 | Level 5.|
| MPEG4_LEVEL_6  = 9 | Level 6.|

### OH_H263Level

```
enum OH_H263Level
```

**Description**

Enumerates the H.263 levels.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 17

| Value| Description|
| -- | -- |
| H263_LEVEL_10 = 0 | Level 10.|
| H263_LEVEL_20 = 1 | Level 20.|
| H263_LEVEL_30 = 2 | Level 30.|
| H263_LEVEL_40 = 3 | Level 40.|
| H263_LEVEL_45 = 4 | Level 45.|
| H263_LEVEL_50 = 5 | Level 50.|
| H263_LEVEL_60 = 6 | Level 60.|
| H263_LEVEL_70 = 7 | Level 70.|

### OH_TemporalGopReferenceMode

```
enum OH_TemporalGopReferenceMode
```

**Description**

Enumerates the reference modes of temporal image groups.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12

| Value| Description|
| -- | -- |
| ADJACENT_REFERENCE = 0 | Refers to the nearest short-term reference frame.|
| JUMP_REFERENCE = 1 | Refers to the latest LTR frame.|
| UNIFORMLY_SCALED_REFERENCE = 2 | Drops video frames at the highest level, and evenly distributes the remaining frames. The number of temporal image groups must be a power of 2.|

### OH_BitrateMode

```
enum OH_BitrateMode
```

**Description**

Enumerates the bit rate modes of an encoder.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description|
| -- | -- |
| BITRATE_MODE_CBR = 0 | Constant bit rate.|
| BITRATE_MODE_VBR = 1 | Variable bit rate.|
| BITRATE_MODE_CQ = 2 | Constant quality.|
| BITRATE_MODE_SQR = 3 | Stable quality. It is supported only for H.265 (HEVC).<br>**Since**: 20|


## Function Description

### OH_AVCodecOnError()

```
typedef void (*OH_AVCodecOnError)(OH_AVCodec *codec, int32_t errorCode, void *userData)
```

**Description**

Defines the pointer to the function that is called to report error information when an error occurs during the running of an OH_AVCodec instance.

| Use Case| Error Code|
| -------- | -------- |
| Audio encoding/decoding| **AV_ERR_DRM_DECRYPT_FAILED**: DRM decryption failed. |
| Video encoding/decoding| **AV_ERROR_NO_MEMORY**: System resources are insufficient.<br>**AV_ERROR_UNKNOWN**: An unknown error occurs. Analyze the error based on specific logs.<br>**AV_ERR_SERVICE_DIED**: The service is dead. |
| Video decoding| **AV_ERR_VIDEO_UNSUPPORTED_COLOR_SPACE_CONVERSION**: The current input does not support CSC. |
<!--RP1--><!--RP1End-->

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to an OH_AVCodec instance.|
|  int32_t errorCode | Error code.|
|  void *userData | Pointer to the data on which the caller depends when executing the callback.|

### OH_AVCodecOnStreamChanged()

```
typedef void (*OH_AVCodecOnStreamChanged)(OH_AVCodec *codec, OH_AVFormat *format, void *userData)
```

**Description**

Defines the pointer to the function that is called to report the new stream description when the resolution of the input video stream being decoded or the output video stream that has been encoded changes.<br>From API version 15, this function pointer is called to report the new stream description when the stream sampling rate, number of audio channels, or audio sampling format changes during audio decoding. The decoding formats that can detect these changes include <!--RP3--><!--RP3End-->AAC, FLAC, MP3, and VORBIS.<br>Note that the lifecycle of the pointer to the OH_AVFormat instance is valid only when the function pointer is being called. Do not access the pointer to the instance after the function pointer is called.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to an OH_AVCodec instance.|
| [OH_AVFormat](_core.md#oh_avformat) *format | Pointer to the description information about the new output stream.|
|  void *userData | Pointer to the data on which the caller depends when executing the callback.|

### OH_AVCodecOnNeedInputData()

```
typedef void (*OH_AVCodecOnNeedInputData)(OH_AVCodec *codec, uint32_t index, OH_AVMemory *data, void *userData)
```

**Description**

Defines the pointer to the function that is called when new input data is required during the running of an OH_AVCodec instance. The function carries a buffer to fill in new input data.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

**Deprecated from**: 11

**Substitute**: [OH_AVCodecOnNeedInputBuffer](#oh_avcodeconneedinputbuffer)


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to an OH_AVCodec instance.|
|  uint32_t index | Index of the new input buffer.|
|  [OH_AVMemory](_core.md#oh_avmemory) *data | Pointer to the data to fill in the new input buffer.|
|  void *userData | Pointer to the data on which the caller depends when executing the callback.|

### OH_AVCodecOnNewOutputData()

```
typedef void (*OH_AVCodecOnNewOutputData)(OH_AVCodec *codec, uint32_t index, OH_AVMemory *data,OH_AVCodecBufferAttr *attr, void *userData)
```

**Description**

Defines the pointer to the function that is called when new output data is generated during the running of an OH_AVCodec instance. The function carries a buffer filled with new output data. Note that the lifecycle of the pointer to the OH_AVCodecBufferAttr instance is valid only when the function pointer is being called. Do not access the pointer to the instance after the function pointer is called.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

**Deprecated from**: 11

**Substitute**: [OH_AVCodecOnNewOutputBuffer](#oh_avcodeconnewoutputbuffer)


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to an OH_AVCodec instance.|
|  uint32_t index | Index of the new output buffer.|
|  [OH_AVMemory](_core.md#oh_avmemory) *data | Pointer to the data filled in the new output buffer.|
| [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) *attr | Description of the new output buffer.|
|  void *userData | Pointer to the data on which the caller depends when executing the callback.|

### OH_AVCodecOnNeedInputBuffer()

```
typedef void (*OH_AVCodecOnNeedInputBuffer)(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *buffer, void *userData)
```

**Description**

Defines the pointer to the function that is called when new input data is required during the running of an OH_AVCodec instance. The function carries a buffer to fill in new input data.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to an OH_AVCodec instance.|
|  uint32_t index | Index of the new input buffer.|
|  [OH_AVBuffer](_core.md#oh_avbuffer) *buffer | Pointer to the data to fill in the new input buffer.|
|  void *userData | Pointer to the data on which the caller depends when executing the callback.|

### OH_AVCodecOnNewOutputBuffer()

```
typedef void (*OH_AVCodecOnNewOutputBuffer)(OH_AVCodec *codec, uint32_t index, OH_AVBuffer *buffer, void *userData)
```

**Description**

Defines the pointer to the function that is called when new output data is generated during the running of an OH_AVCodec instance. The function carries a buffer filled with new output data.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to an OH_AVCodec instance.|
|  uint32_t index | Index of the new output buffer.|
|  [OH_AVBuffer](_core.md#oh_avbuffer) *buffer | Pointer to the data filled in the new output buffer.|
|  void *userData | Pointer to the data on which the caller depends when executing the callback.|

### OH_AVDataSourceReadAt()

```
typedef int32_t (*OH_AVDataSourceReadAt)(OH_AVBuffer *data, int32_t length, int64_t pos)
```

**Description**

Defines a function pointer used to provide the capability of obtaining user-defined media data.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVBuffer](_core.md#oh_avbuffer) *data | Pointer to the buffer to be filled in.|
|  int32_t length | Length of the data to read.|
|  int64_t pos | Offset from which the data is read.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Actual length of the data read to the buffer.|

### OH_AVDataSourceReadAtExt()

```
typedef int32_t (*OH_AVDataSourceReadAtExt)(OH_AVBuffer *data, int32_t length, int64_t pos, void *userData)
```

**Description**

Defines a function pointer used to provide the capability of obtaining user-defined media data.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVBuffer](_core.md#oh_avbuffer) *data | Pointer to the buffer to be filled in.|
|  int32_t length | Length of the data to read.|
|  int64_t pos | Offset from which the data is read.|
|  void *userData | Pointer to user-defined data.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Actual length of the data read to the buffer.|
<!--no_check-->