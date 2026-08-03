# native_avcodec_base.h
<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @mr-chencxy-->
<!--Designer: @dpy2650--->
<!--Tester: @baotianhao-->
<!--Adviser: @w_Machine_cc-->

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
| [OH_AVCodecAsyncCallback](capi-codecbase-oh-avcodecasynccallback.md) | OH_AVCodecAsyncCallback | Describes all the asynchronous callback function pointers of an OH_AVCodec instance. To ensure the normal running of OH_AVCodec, you must register the instance of this struct with the OH_AVCodec instance and process the information reported by the callback function. (It is deprecated from API version 11.)|
| [OH_AVCodecCallback](capi-codecbase-oh-avcodeccallback.md) | OH_AVCodecCallback | Describes all the asynchronous callback function pointers of an OH_AVCodec instance. To ensure the normal running of OH_AVCodec, you must register the instance of this struct with the OH_AVCodec instance and process the information reported by the callback function.|
| [OH_AVDataSource](capi-codecbase-oh-avdatasource.md) | OH_AVDataSource | Describes a user-defined data source.|
| [OH_AVDataSourceExt](capi-codecbase-oh-avdatasourceext.md) | OH_AVDataSourceExt | Describes a user-defined data source. User-defined data can be passed to its callback functions through the **userData** parameter.|
| [NativeWindow](capi-codecbase-nativewindow.md) | OHNativeWindow | Describes a native object for the graphics interface.|
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) | OH_AVCodec | Describes a native object for the audio and video codec interface.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_MediaType](#oh_mediatype) | OH_MediaType | Enumerates the media types.|
| [OH_AACProfile](#oh_aacprofile) | OH_AACProfile | Enumerates the Advanced Audio Coding (AAC) profiles.|
| [OH_AVCProfile](#oh_avcprofile) | OH_AVCProfile | Enumerates the Advanced Video Coding (AVC) profiles.|
| [OH_HEVCProfile](#oh_hevcprofile) | OH_HEVCProfile | Enumerates the High Efficiency Video Coding (HEVC) profiles.|
| [OH_VVCProfile](#oh_vvcprofile) | OH_VVCProfile | Enumerates the VVC profiles.|
| [OH_MPEG2Profile](#oh_mpeg2profile) | OH_MPEG2Profile | Enumerates the MPEG2 profiles.|
| [OH_MPEG4Profile](#oh_mpeg4profile) | OH_MPEG4Profile | Enumerates the MPEG4 profiles.|
| [OH_H263Profile](#oh_h263profile) | OH_H263Profile | Enumerates the H.263 profiles.|
| [OH_VC1Profile](#oh_vc1profile) | OH_VC1Profile | Enumerates the VC-1 profiles.|
| [OH_AV1Profile](#oh_av1profile) | OH_AV1Profile | AV1 profile.|
| [OH_VP9Profile](#oh_vp9profile) | OH_VP9Profile | VP9 profile.|
| [OH_WVC1Profile](#oh_wvc1profile) | OH_WVC1Profile | WVC1 profile.|
| [OH_WMV3Profile](#oh_wmv3profile) | OH_WMV3Profile | Enumerates the WMV3 profiles.|
| [OH_AVOutputFormat](#oh_avoutputformat) | OH_AVOutputFormat | Enumerates the output file formats supported by a muxer.|
| [OH_AVSeekMode](#oh_avseekmode) | OH_AVSeekMode | Enumerates the seek modes.|
| [OH_ScalingMode](#oh_scalingmode) | OH_ScalingMode | Enumerates the scaling modes. This enum is used only in surface mode. (It is deprecated from API version 14.)|
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
| [OH_VC1Level](#oh_vc1level) | OH_VC1Level | Enumerates the VC-1 levels.|
| [OH_AV1Level](#oh_av1level) | OH_AV1Level | AV1 level.|
| [OH_VP9Level](#oh_vp9level) | OH_VP9Level | VP9 level.|
| [OH_WVC1Level](#oh_wvc1level) | OH_WVC1Level | WVC1 level.|
| [OH_WMV3Level](#oh_wmv3level) | OH_WMV3Level | Enumerates the WMV3 levels.|
| [OH_TemporalGopReferenceMode](#oh_temporalgopreferencemode) | OH_TemporalGopReferenceMode | Enumerates the reference modes of temporal image groups.|
| [OH_BitrateMode](#oh_bitratemode) | OH_BitrateMode | Enumerates the bit rate modes of an encoder.|
| [OH_FrameRetentionMode](#oh_frameretentionmode) | OH_FrameRetentionMode | Enumerates the frame retention modes of video decoding.|
| [OH_AudioEncoderPTSMode](#oh_audioencoderptsmode) | OH_AudioEncoderPTSMode | Enumerates the PTS modes of an audio encoder.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_AVCodecOnError)(OH_AVCodec *codec, int32_t errorCode, void *userData)](#oh_avcodeconerror) | OH_AVCodecOnError | Defines the pointer to the function that is called to report error information when an error occurs during the running of an OH_AVCodec instance.|
| [typedef void (\*OH_AVCodecOnStreamChanged)(OH_AVCodec *codec, OH_AVFormat *format, void *userData)](#oh_avcodeconstreamchanged) | OH_AVCodecOnStreamChanged | Defines the pointer to the function that is called to report the new stream description when the resolution of the input video stream being decoded or the output video stream that has been encoded changes.<br> Starting from API version 15, this function pointer is called to report the new stream description when the stream sampling rate, number of audio channels, or audio sampling format changes during audio decoding. The decoding formats that can detect these changes include <!--RP3--><!--RP3End-->AAC, FLAC, MP3, and VORBIS.<br> Note that the lifecycle of the pointer to the OH_AVFormat instance is valid only when the function pointer is being called. Do not access the pointer to the instance after the function pointer is called.|
| [typedef void (\*OH_AVCodecOnNeedInputData)(OH_AVCodec *codec, uint32_t index, OH_AVMemory *data, void *userData)](#oh_avcodeconneedinputdata) | OH_AVCodecOnNeedInputData | Defines the pointer to the function that is called when new input data is required during the running of an OH_AVCodec instance. The function carries a buffer to fill in new input data. (It is deprecated from API version 11.)|
| [typedef void (\*OH_AVCodecOnNewOutputData)(OH_AVCodec *codec, uint32_t index, OH_AVMemory *data, OH_AVCodecBufferAttr *attr, void *userData)](#oh_avcodeconnewoutputdata) | OH_AVCodecOnNewOutputData | Defines the pointer to the function that is called when new output data is generated during the running of an OH_AVCodec instance. The function carries a buffer filled with new output data. Note that the lifecycle of the pointer to the OH_AVCodecBufferAttr instance is valid only when the function pointer is being called. Do not access the pointer to the instance after the function pointer is called. (It is deprecated from API version 11.)|
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
| const char * OH_AVCODEC_MIMETYPE_VIDEO_MPEG4 | Pointer to the key that describes the MIME type of the MPEG4 video encoder, which is used only for multiplexing MPEG4 video streams.<br>**Since**: 10<br>**Deprecated from**: 11<br>**Substitute**: OH_AVCODEC_MIMETYPE_VIDEO_MPEG4_PART2<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_MPEG4_PART2 | Pointer to the key that describes the MIME type of the MPEG4 Part 2 video codec.<br>**Since**: 17<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_MPEG2 | Pointer to the key that describes the MIME type of the MPEG2 video codec.<br>**Since**: 17<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_H263 | Pointer to the key that describes the MIME type of the H.263 video codec.<br>**Since**: 17<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_VC1 | Pointer to the key that describes the MIME type of the VC-1 video codec.<br>**Since**: 22<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_AV1 | Pointer to the key that describes the MIME type of the AV1 video codec.<br>**Since**: 23|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_VP9 | Pointer to the key that describes the MIME type of the VP9 video codec.<br>**Since**: 23|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_VP8 | Pointer to the key that describes the MIME type of the VP8 video codec.<br>**Since**: 23|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_RV30 | Pointer to the key that describes the MIME type of the RV30 video codec.<br>**Since**: 23|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_RV40 | Pointer to the key that describes the MIME type of the RV40 video codec.<br>**Since**: 23|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_WVC1 | Pointer to the key that describes the MIME type of the WVC1 video codec.<br>**Since**: 23|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_DVVIDEO | Pointer to the key that describes the MIME type of the DVVIDEO (Digital Video) video codec. DV NTSC, DV PAL, and DVCPRO HD are supported.<br>**Since**: 23|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_RAWVIDEO | Pointer to the key that describes the MIME type of the RAWVIDEO video codec.<br>**Since**: 23|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_MPEG1 | Pointer to the key that describes the MIME type of the MPEG1 video codec.<br>**Since**: 23|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_CINEPAK | Pointer to the key that describes the MIME type of the Cinepak video codec.<br>**Since**: 24|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_MSVIDEO1 | Pointer to the key that describes the MIME type of the Microsoft Video 1 (MSVIDEO1) video codec.<br>**Since**: 22<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_WMV3 | Pointer to the key that describes the MIME type of the WMV3 video codec.<br>**Since**: 22<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_MJPEG | Pointer to the key that describes the MIME type of the Motion JPEG (MJPEG) video codec.<br>**Since**: 22<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_IMAGE_JPG | Pointer to the key that describes the MIME type of the JPG image encoder, which is used only for multiplexing JPG covers.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_IMAGE_PNG | Pointer to the key that describes the MIME type of the PNG image encoder, which is used only for multiplexing PNG covers.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_IMAGE_BMP | Pointer to the key that describes the MIME type of the BMP image encoder, which is used only for multiplexing BMP covers.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_VIVID | Pointer to the key that describes the MIME type of the Audio Vivid audio decoder.<br>**Since**: 11<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_AMR_NB | Pointer to the key that describes the MIME type of the AMR-NB audio <!--RP4--><!--RP4End--> decoder.<br>**Since**: 11<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_AMR_WB | Pointer to the key that describes the MIME type of the AMR-WB audio <!--RP4--><!--RP4End--> decoder.<br>**Since**: 11<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_OPUS | Pointer to the key that describes the MIME type of the Opus audio codec.<br>**Since**: 11<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_G711MU | Pointer to the key that describes the MIME type of the G.711 mu-law audio codec.<br>**Since**: 11<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_ALAC | Pointer to the key that describes the MIME type of the Apple Lossless Audio Codec (ALAC) audio decoder.<br>**Since**: 22|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_AC3 | Pointer to the key that describes the MIME type of the Dolby Audio Coding 3 (AC 3) audio decoder.<br>**Since**: 22|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_EAC3 | Pointer to the key that describes the MIME type of the Enhanced AC-3 (EAC3) audio decoder.<br>**Since**: 22|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_WMAV1 | Pointer to the key that describes the MIME type of the Windows Media Audio (WMA) V1 audio decoder.<br>**Since**: 22|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_WMAV2 | Pointer to the key that describes the MIME type of the WMA V2 audio decoder.<br>**Since**: 22|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_WMAPRO | Pointer to the key that describes the MIME type of the WMA Pro audio decoder.<br>**Since**: 22|
| const char * OH_MD_KEY_BLOCK_ALIGN | Pointer to the key that describes the size of the audio data block, in bytes. The value type is int32_t. This key is used only for WMA (V1, V2, and PRO) decoders.<br> The allowed MIME types include **OH_AVCODEC_MIMETYPE_AUDIO_WMAV1**, **OH_AVCODEC_MIMETYPE_AUDIO_WMAV2**, and **OH_AVCODEC_MIMETYPE_AUDIO_WMAPRO**.<br>**Since**: 22|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_GSM | Pointer to the key that describes the MIME type of the Global System for Mobile Communications (GSM) audio decoder.<br>**Since**: 22|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_GSM_MS | Pointer to the key that describes the MIME type of the GSM Microsoft variant (MS) audio decoder.<br>**Since**: 22|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_TWINVQ | Pointer to the key that describes the MIME type of the Transform-domain Weighted Interleave Vector Quantization (TWINVQ) audio decoder.<br>**Since**: 23|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_ILBC | Pointer to the key that describes the MIME type of the Internet Low Bitrate Codec (iLBC) audio decoder.<br>**Since**: 23|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_TRUEHD | Pointer to the key that describes the MIME type of the True High Definition (TRUEHD) audio decoder.<br>**Since**: 23|
| const char * OH_AVCODEC_MIMETYPE_VIDEO_VVC | Pointer to the key that describes the MIME type of the VVC (H.266) video codec.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_APE | Pointer to the key that describes the MIME type of the APE audio decoder.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_SUBTITLE_SRT | Pointer to the key that describes the MIME type of the SRT subtitle demuxer.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_SUBTITLE_WEBVTT | Pointer to the key that describes the MIME type of the WEBVTT subtitle demuxer.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_RAW | Pointer to the key that describes the MIME type of raw audio streams.<br>**Since**: 18<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_G711A | Pointer to the key that describes the MIME type of the G.711 a-law audio decoder.<br>**Since**: 20<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_COOK | Pointer to the key that describes the MIME type of the Cook (RealAudio Cook) audio decoder.<br>**Since**: 23<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_DTS | Pointer to the key that describes the MIME type of the DTS (Digital Theater Systems) audio decoder.<br>**Since**: 23<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_AVCODEC_MIMETYPE_AUDIO_DVAUDIO | Pointer to the key that describes the MIME type of the DVAUDIO (Digital Video Audio) audio decoder.<br>**Since**: 23<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_ED_KEY_TIME_STAMP | Pointer to the key that describes the surface buffer timestamp. The value is of the int64_t type.<br>**Since**: 9<br>**Deprecated from**: 14<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_ED_KEY_EOS | Pointer to the key that describes the end of stream for the surface buffer. The value type is int32_t.<br>**Since**: 9<br>**Deprecated from**: 14<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_TRACK_TYPE | Pointer to the key that describes the track type in a media file. The value type is int32_t. For details, see [OH_MediaType](#oh_mediatype).<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_CODEC_MIME | Pointer to the key that describes the MIME type of the codec. The value type is char *.<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_DURATION | Pointer to the key that describes the duration in a media file, in microseconds. The value type is int64_t.<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_BITRATE | Pointer to the key that describes the bit rate, in bps. The value type is int64_t. You can call [OH_AVCapability_GetEncoderBitrateRange](capi-native-avcapability-h.md#oh_avcapability_getencoderbitraterange) to obtain the value range.<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_MAX_INPUT_SIZE | Pointer to the key that describes the maximum size of an input stream to decode. The value type is int32_t.<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_WIDTH | Pointer to the key that describes the video width. The value type is int32_t.<br>For video encoding, this key is used to set the target encoding resolution. For video decoding, this key serves as a resolution hint for the decoder to pre-allocate internal buffers. The actual decoded output dimensions are provided by **OH_MD_KEY_VIDEO_PIC_WIDTH**.<br>This key is mainly used to control memory allocation. You can call [OH_AVCapability_GetVideoWidthRange](capi-native-avcapability-h.md#oh_avcapability_getvideowidthrange) to obtain the recommended value range. This API defines the decoding width range supported by the codec.<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_HEIGHT | Pointer to the key that describes the video height. The value type is int32_t.<br>For video encoding, this key is used to set the target encoding resolution. For video decoding, this key serves as a resolution hint for the decoder to pre-allocate internal buffers. The actual decoded output dimensions are provided by **OH_MD_KEY_VIDEO_PIC_HEIGHT**.<br> This key is mainly used to control memory allocation. You can call [OH_AVCapability_GetVideoHeightRange](capi-native-avcapability-h.md#oh_avcapability_getvideoheightrange) to obtain the recommended value range. This API defines the decoding height range supported by the codec.<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_PIXEL_FORMAT | Pointer to the key that describes the video pixel format. The value type is int32_t. For details, see [OH_AVPixelFormat](capi-native-avformat-h.md#oh_avpixelformat).<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_AUDIO_SAMPLE_FORMAT | Pointer to the key that describes the original audio format. The value type is int32_t. For details, see [OH_BitsPerSample](#oh_bitspersample).<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_FRAME_RATE | Pointer to the key that describes the video frame rate. The value type is double. The value must be greater than **0**. You can call [OH_AVCapability_GetVideoFrameRateRange](capi-native-avcapability-h.md#oh_avcapability_getvideoframeraterange) to obtain the value range.<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE | Pointer to the key that describes the video encoding bit rate mode. The value type is int32_t. For details, see [OH_BitrateMode](#oh_bitratemode).<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_PROFILE | Pointer to the key that describes the encoding grading. The value type is int32_t. For details, see [OH_AVCProfile](#oh_avcprofile), [OH_HEVCProfile](#oh_hevcprofile), and [OH_AACProfile](#oh_aacprofile). You can call [OH_AVCapability_GetSupportedProfiles](capi-native-avcapability-h.md#oh_avcapability_getsupportedprofiles) to obtain the supported profiles.<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_AUD_CHANNEL_COUNT | Pointer to the key that describes the number of audio channels. The value type is int32_t.<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_AUD_SAMPLE_RATE | Pointer to the key that describes the audio sampling rate. The value type is int32_t.<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_I_FRAME_INTERVAL | Pointer to the key that describes the key frame interval, in milliseconds. The value type is int32_t. This key is optional and is used only for video encoding.<br> A negative value means that only the first frame is a keyframe. The value **0** means that all frames are keyframes. A positive value means one keyframe every (frameRate * value)/1000 frames. The default value is **1000**.<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_ROTATION | Pointer to the key that describes the rotation angle of the surface, with a clockwise direction. The value type is int32_t, and the value range is {0, 90, 180, 270}. The default value is 0.<br> This key is optional and is used only for video decoding in surface mode<br> You are advised to use the **OH_MD_KEY_VIDEO_TRANSFORM_TYPE** key to set the rotation angle of the surface for video decoding.<br>**Since**: 9<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_TRANSFORM_TYPE | Pointer to the key that describes the video rotation angle. The value type is int32_t. For details, see [OH_NativeBuffer_TransformType](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_transformtype).<br>This key is used to set the rotation angle of the surface for video decoding. The default value is **0** ([NATIVEBUFFER_ROTATE_NONE](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_transformtype)).<br> This key is mutually exclusive with **OH_MD_KEY_ROTATION**. If both of them are set, **OH_MD_KEY_VIDEO_TRANSFORM_TYPE** is used. **OH_MD_KEY_VIDEO_TRANSFORM_TYPE** is recommended.<br> Note: The angle specified in **OH_NativeBuffer_TransformType** indicates a counter-clockwise rotation, which is opposite to the rotation direction defined by **OH_MD_KEY_ROTATION**.<br> The mapping is as follows.<br> - [NATIVEBUFFER_ROTATE_NONE](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_transformtype) is equivalent to OH_MD_KEY_ROTATION = 0.<br> - [NATIVEBUFFER_ROTATE_90](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_transformtype) is equivalent to OH_MD_KEY_ROTATION = 270.<br> - [NATIVEBUFFER_ROTATE_180](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_transformtype) is equivalent to OH_MD_KEY_ROTATION = 180.<br> - [NATIVEBUFFER_ROTATE_270](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_transformtype) is equivalent to OH_MD_KEY_ROTATION = 90.<br><br>**Since**: 22|
| const char * OH_MD_KEY_RANGE_FLAG | Pointer to the key that describes the video YUV value range flag. The value type is int32_t. The value **1** means a full range, and **0** means a limited range. The default value is **0**. If this parameter is set to a non-zero value, the value **1** is used.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_COLOR_PRIMARIES | Pointer to the key that describes the video primary colors. The value type is int32_t. The default value is **COLOR_PRIMARY_UNSPECIFIED**. For details, see [OH_ColorPrimary](#oh_colorprimary). The value complies with Table 2 in H.273.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_TRANSFER_CHARACTERISTICS | Pointer to the key that describes the video transfer characteristics. The value type is int32_t. The default value is **TRANSFER_CHARACTERISTIC_UNSPECIFIED**. For details, see [OH_TransferCharacteristic](#oh_transfercharacteristic). The value complies with Table 3 in H.273.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_MATRIX_COEFFICIENTS | Pointer to the key that describes the video matrix coefficients. The value type is int32_t. The default value is **MATRIX_COEFFICIENT_UNSPECIFIED**. For details, see [OH_MatrixCoefficient](#oh_matrixcoefficient). The value must comply with Table 4 in H.273.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_REQUEST_I_FRAME | Pointer to the key that describes the request for immediate encoding of I-frames. The value type is int32_t. This key is used in [OH_VideoEncoder_SetParameter](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_setparameter) or takes effect immediately with each frame.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_QUALITY | Pointer to the key that describes the required encoding quality. The value type is int32_t. The default value is **50**. In H.264 and H.265 encoding scenarios, the value range can be obtained by calling [OH_AVCapability_GetEncoderQualityRange](capi-native-avcapability-h.md#oh_avcapability_getencoderqualityrange). This key applies only to the encoder in constant quality mode.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_CODEC_CONFIG | Pointer to the key that describes the codec-specific data. In the case of video, data carried in **SPS/PPS** is transferred. In the case of audio, data carried in **extraData** is transferred. The value type is uint8_t\*. <!--Del-->(This key is not supported yet for the video codec.)<!--DelEnd--><br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_TITLE | Pointer to the key that describes the title of a media file . The value type is char *.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_ARTIST | Pointer to the key that describes the artist in a media file. The value type is char *.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_ALBUM | Pointer to the key that describes the album media file. The value type is char *.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_ALBUM_ARTIST | Pointer to the key that describes the album artist. The value type is char *.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_DATE | Pointer to the key that describes the date of a media file, for example, 2024. The value type is char *.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_COMMENT | Pointer to the key that describes the comment of a media file. The value type is char *.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_ENABLE_MOOV_FRONT | Pointer to the key that specifies whether the moov metadata should be at the front of a media file. The value type is int32_t. The value **1** indicates that the moov metadata should be at the front of a media file, and **0** indicates that the moov metadata should not be at the front of a media file. The default value is **0**.<br>**Since**: 20<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_GENRE | Pointer to the key that describes the genre in a media file. The value type is char *.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_COPYRIGHT | Pointer to the key that describes the copyright of a media file. The value type is char *.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_LANGUAGE | Pointer to the key that describes language of a media file. The value type is char *.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_DESCRIPTION | Pointer to the key that describes the description of a media file. The value type is char *.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_LYRICS | Pointer to the key that describes the lyrics in a media file. The value type is char *.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_TRACK_COUNT | Pointer to the key that describes the number of tracks in a media file. The value type is int32_t.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_CHANNEL_LAYOUT | Pointer to the key that describes the required encoding channel layout. The value type is int64_t. This key applies only to encoders. For details, see [OH_AudioChannelLayout](capi-native-audio-channel-layout-h.md#oh_audiochannellayout).<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_BITS_PER_CODED_SAMPLE | Pointer to the key that describes the number of bits per sample. The value type is int32_t.<br> In versions earlier than API version 20, this parameter must be set to **1** for FLAC encoding. Otherwise, **OH_AudioCodec_Configure** returns the error code **AV_ERR_INVALID_VAL**. However, this parameter has no actual effect and does not affect the encoding result.<br> Starting from API version 20, you do not need to set it anymore.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_AAC_IS_ADTS | Pointer to the key that describes the AAC format, which can be ADTS or LATM. The value type is int32_t. The value **0** means the LATM format, and **1** means the ADTS format. This key is supported by AAC decoders.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_SBR | Pointer to the key that describes the AAC SBR format. The value type is int32_t. This key applies to AAC encoders.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_COMPLIANCE_LEVEL | Pointer to the key that describes the FLAC compliance level. The value type is int32_t. This key is used only for audio encoding.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_IDENTIFICATION_HEADER | Pointer to the key that describes the vorbis identification header. The value type is uint8_t*. This key applies only to Vorbis decoders.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_SETUP_HEADER | Pointer to the key that describes the vorbis setup header. The value type is uint8_t*. This key applies only to Vorbis decoders.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_SCALING_MODE | Pointer to the key that describes the video scaling mode. The value type is int32_t. For details, see [OH_ScalingMode](#oh_scalingmode).<br> You are advised to set the scaling mode by calling [OH_NativeWindow_NativeWindowSetScalingModeV2](../apis-arkgraphics2d/capi-external-window-h.md#oh_nativewindow_nativewindowsetscalingmodev2). This key is optional and is used only for video decoding in surface mode.<br>**Since**: 10<br>**Deprecated from**: 14<br>**Substitute**: [OH_NativeWindow_NativeWindowSetScalingModeV2](../apis-arkgraphics2d/capi-external-window-h.md#oh_nativewindow_nativewindowsetscalingmodev2)<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_MAX_INPUT_BUFFER_COUNT | Pointer to the key that describes the maximum number of input buffers. The value type is int32_t.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_MAX_OUTPUT_BUFFER_COUNT | Pointer to the key that describes the maximum number of output buffers. The value type is int32_t.<br>**Since**: 10<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_AUDIO_COMPRESSION_LEVEL | Pointer to the key that describes the audio codec compression level. The value type is int32_t type. This key is used only for audio encoding.<br>**Since**: 11<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_IS_HDR_VIVID | Pointer to the key that specifies whether the video track in a media file is HDR Vivid. The value type is int32_t. This key is used for both multiplexing and demultiplexing.<br> The value **1** means the HDR Vivid video track, and **0** means other cases.<br>**Since**: 11<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_AUDIO_OBJECT_NUMBER | Pointer to the key that describes the number of audio objects. The value type is int32_t. This key is optional and is used only for Audio Vivid codec.<br>**Since**: 11<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_AUDIO_VIVID_METADATA | Pointer to the key that describes the Audio Vivid metadata. The value type is uint8_t*. This key is optional and is used only for Audio Vivid codec.<br>**Since**: 11<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_FEATURE_PROPERTY_KEY_VIDEO_ENCODER_MAX_LTR_FRAME_COUNT | Pointer to the key that describes the maximum number of long-term reference (LTR) frames obtained during video encoding. The value type is int32_t.<br> You can use the API [OH_AVCapability_GetFeatureProperties](capi-native-avcapability-h.md#oh_avcapability_getfeatureproperties) and the enumerated value **VIDEO_ENCODER_LONG_TERM_REFERENCE** in [OH_AVCapabilityFeature](capi-native-avcapability-h.md#oh_avcapabilityfeature) to query the maximum number.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_ENABLE_TEMPORAL_SCALABILITY | Pointer to the key that describes the enabled status of temporal scalability. The value type is int32_t. **1** if enabled, **0** otherwise. The default value is **0**. If this parameter is set to a non-zero value, the value **1** is used.<br> You can use the API [OH_AVCapability_IsFeatureSupported](capi-native-avcapability-h.md#oh_avcapability_isfeaturesupported) and the enumerated value **VIDEO_ENCODER_TEMPORAL_SCALABILITY** in [OH_AVCapabilityFeature](capi-native-avcapability-h.md#oh_avcapabilityfeature) to check whether the current video encoder supports temporal scalability.<br>For details, see [Temporally Scalable Video Coding](../../media/avcodec/video-encoding-temporal-scalability.md#available-apis).<br> This key is optional and used only in the configuration phase of video encoding.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_SIZE | Pointer to the key that describes the size of a temporal image group. The value type is int32_t. This key is valid only when temporal scalability is enabled.<br> This key is optional and used only in the configuration phase of video encoding.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_REFERENCE_MODE | Pointer to the key that describes the reference mode in a temporal image group. The value type is int32_t. For details, see [OH_TemporalGopReferenceMode](#oh_temporalgopreferencemode). This key is valid only when temporal scalability is enabled.<br> This key is optional and used only in the configuration phase of video encoding.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_LAYER_ID | Pointer to the key that describes the temporal layer ID in a group of pictures (GOP). The value type is int32_t.<br> Temporal layer ID **0** indicates the base layer. Temporal layer IDs **1** and above indicate enhancement layers. The maximum temporal layer ID is determined by **OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_REFERENCE_MODE** and **OH_MD_KEY_VIDEO_ENCODER_TEMPORAL_GOP_SIZE**.<br> Currently, this key is used only to query the temporal layer ID carried in **AVBuffer** output by the encoder.<br> The process is as follows:<br> 1. Use [OH_AVCodecOnNewOutputBuffer](#oh_avcodeconnewoutputbuffer) or [OH_VideoEncoder_GetOutputBuffer](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_getoutputbuffer) to obtain the buffer instance (**AVBuffer**).<br> 2. Use [OH_AVBuffer_GetParameter](capi-native-avbuffer-h.md#oh_avbuffer_getparameter) to obtain the parameter instance (**OH_AVFormat**), which does not contain basic properties.<br> 3. Use [OH_AVFormat_GetIntValue](capi-native-avformat-h.md#oh_avformat_getintvalue) and this key to obtain the temporal layer ID of the corresponding frame.<br>**Since**: 26.0.0|
| const char * OH_MD_KEY_VIDEO_ENCODER_LTR_FRAME_COUNT | Pointer to the key that describes the number of LTR frames. The value type is int32_t. The value must be within the supported value range.<br> Before using this key, you can use the API [OH_AVCapability_GetFeatureProperties](capi-native-avcapability-h.md#oh_avcapability_getfeatureproperties) and the enumerated value **VIDEO_ENCODER_LONG_TERM_REFERENCE** in [OH_AVCapabilityFeature](capi-native-avcapability-h.md#oh_avcapabilityfeature) to query the number of supported LTR frames.<br> This key is optional and used only in the configuration phase of video encoding.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_MARK_LTR | Pointer to the key that specifies whether the current frame is marked as an LTR frame. The value type is int32_t. **1** if marked, **0** otherwise. The default value is **0**. If this parameter is set to a non-zero value, the value **1** is used.<br> This key takes effect only after the number of LTR frames is configured.<br> This key is optional and is used only for video encoding input rotation. The configuration takes effect immediately.<br>For details, see [Temporally Scalable Video Coding](../../media/avcodec/video-encoding-temporal-scalability.md#available-apis).<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_PER_FRAME_USE_LTR | Pointer to the key that describes the POC number of the LTR frame referenced by the current frame. The value type is int32_t.<br> This key is optional and is used only for video encoding input rotation. The configuration takes effect immediately.<br>For details, see [Temporally Scalable Video Coding](../../media/avcodec/video-encoding-temporal-scalability.md#available-apis).<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_PER_FRAME_IS_LTR | Pointer to the key that specifies whether the frame corresponding to the stream output from the current OH_AVBuffer is marked as an LTR frame. The value type is int32_t. **1** if marked, **0** otherwise. The default value is **0**. If this parameter is set to a non-zero value, the value **1** is used.<br> This key is optional and is used only for video encoding output rotation.<br> It indicates the attribute of a frame.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_PER_FRAME_POC | Pointer to the key that describes the POC of the frame. The value type is int32_t.<br> This key is optional and is used only for video encoding output rotation.<br> It indicates the attribute of a frame.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_CROP_TOP | Pointer to the key that describes the top coordinate (y) of the cropped rectangle. The value type is int32_t.<br> The row at the top of the cropped rectangle is contained, and the row index starts from 0.<br> This key is used only for video decoding.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_CROP_BOTTOM | Pointer to the key that describes the bottom coordinate (y) of the cropped rectangle. The value type is int32_t.<br> The row at the bottom of the cropped rectangle is contained, and the row index starts from 0.<br> This key is used only for video decoding.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_CROP_LEFT | Pointer to the key that describes the left coordinate (x) of the cropped rectangle. The value type is int32_t.<br> The leftmost column of the cropped rectangle is contained, and the column index starts from 0.<br> This key is used only for video decoding.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_CROP_RIGHT | Pointer to the key that describes the right coordinate (x) of the cropped rectangle. The value type is int32_t.<br> The rightmost column of the cropped rectangle is contained, and the column index starts from 0.<br> This key is used only for video decoding.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_STRIDE | Pointer to the key that describes the stride of the video frame. The value type is int32_t.<br> Stride indicates the byte distance between the start positions of two consecutive rows in memory. Due to hardware alignment requirements, the stride is typically greater than or equal to the image's active width. When the stride equals the width, there is no horizontal padding. You should always obtain the actual stride through **OH_VideoEncoder_GetInputDescription** (for encoding), **OH_VideoDecoder_GetOutputDescription** (for decoding), or **OH_AVFormat** in the **OH_AVCodecOnStreamChanged** callback, instead of assuming a fixed value.<br> For details about the example, see step 8 in [video encoding](../../media/avcodec/video-encoding.md#buffer-mode) in buffer mode or step 11 in [video decoding](../../media/avcodec/video-decoding.md#buffer-mode) in buffer mode.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_SLICE_HEIGHT | Pointer to the key that describes the height of the video frame. The value type is int32_t.<br>Height indicates the total number of rows allocated in the memory for a single plane. Due to hardware alignment requirements, **sliceHeight** is typically greater than or equal to the image's active height. The offset of the start address of the U plane relative to the origin of the Y plane is **sliceHeight** × **stride**. You should always obtain the actual height through **OH_VideoEncoder_GetInputDescription** (for encoding), **OH_VideoDecoder_GetOutputDescription** (for decoding), or **OH_AVFormat** in the **OH_AVCodecOnStreamChanged** callback, instead of assuming a fixed value.<br>For details about the example, see step 8 in [video encoding](../../media/avcodec/video-encoding.md#buffer-mode) in buffer mode or step 11 in [video decoding](../../media/avcodec/video-decoding.md#buffer-mode) in buffer mode.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_PIC_WIDTH | Pointer to the key that describes the actual active width of a decoded video frame. The value type is int32_t. This key is read-only and used only for video decoding.<br>You can obtain the width from the returned **OH_AVFormat** instance when [OH_VideoDecoder_GetOutputDescription](capi-native-avcodec-videodecoder-h.md#oh_videodecoder_getoutputdescription) is called or decoded output stream changes are detected through the [OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged) callback. This value indicates the effective image width, which is different from **OH_MD_KEY_WIDTH** set in the configuration phase. The latter is a configuration hint used for pre-allocating buffers. Read this value when you need the actual image width for display or saving.<br>For details about the image layout and usage example, see step 8 in [video encoding](../../media/avcodec/video-encoding.md#buffer-mode) in buffer mode or step 11 in [video decoding](../../media/avcodec/video-decoding.md#buffer-mode) in buffer mode.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_PIC_HEIGHT | Pointer to the key that describes the actual active height of a decoded video frame. The value type is int32_t. This key is read-only and used only for video decoding.<br>You can obtain the height from the returned **OH_AVFormat** instance when [OH_VideoDecoder_GetOutputDescription](capi-native-avcodec-videodecoder-h.md#oh_videodecoder_getoutputdescription) is called or decoded output bitstream changes are detected through the [OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged) callback. This value indicates the effective image height, which is different from **OH_MD_KEY_HEIGHT** set in the configuration phase. The latter is a configuration hint used for pre-allocating buffers. Read this value when you need the actual image height for display or saving.<br>For details about the image layout and usage example, see step 8 in [video encoding](../../media/avcodec/video-encoding.md#buffer-mode) in buffer mode or step 11 in [video decoding](../../media/avcodec/video-decoding.md#buffer-mode) in buffer mode.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENABLE_LOW_LATENCY | Pointer to the key that describes the enabled status of low-latency video decoding. The value type is int32_t. **1** if enabled, **0** otherwise. The default value is **0**. If this parameter is set to a non-zero value, the value **1** is used.<br> This key is optional and used only in the configuration phase.<br> If enabled, the input and output data held by the video decoder does not exceed the amount required by the decoder standard.<br> You can call [OH_AVCapability_IsFeatureSupported](capi-native-avcapability-h.md#oh_avcapability_isfeaturesupported) to check whether a specific decoder supports low-latency decoding. If supported, the video decoder outputs frames in the decoding sequence when low-latency video codec is enabled.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_QP_MAX | Pointer to the key that describes the maximum Quantization Parameter (QP) allowed by the video encoder. The value type is int32_t.<br> This key is used in the configuration or parameter setting phase or takes effect immediately with each frame.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_QP_MIN | Pointer to the key that describes the minimum QP allowed by the video encoder. The value type is int32_t.<br> This key is used in the configuration or parameter setting phase or takes effect immediately with each frame.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_QP_AVERAGE | Pointer to the key that describes the average QP of video frames. The value type is int32_t.<br> Pointer to the key that describes the average QP value of the current frame encoding block. It is output with [OH_AVBuffer](capi-core-oh-avbuffer.md).<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_MSE | Pointer to the key that describes the Mean Squared Error (MSE) of video frames. The value type is double.<br> Pointer to the key that describes the average MSE value of the current frame encoding block. It is output with [OH_AVBuffer](capi-core-oh-avbuffer.md).<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_DECODING_TIMESTAMP | Pointer to the key that describes the decoding timestamp corresponding to the audio, video, or subtitle sample carried in AVBuffer, in microseconds. The value type is int64_t.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_BUFFER_DURATION | Pointer to the key that describes the duration corresponding to the audio, video, or subtitle sample carried in AVBuffer, in microseconds. The value type is int64_t.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_SAR | Pointer to the key that describes the aspect ratio of the sample. The value type is double.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_START_TIME | Pointer to the key that describes the start time of the first frame in a media file, measured in microseconds. The value type is int64_t.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_TRACK_START_TIME | Pointer to the key that describes the start time of the track, measured in microseconds. The value type is int64_t.<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_DECODER_OUTPUT_COLOR_SPACE | Pointer to the key that describes the output color space of the video decoder. The value type is int32_t.<br> The supported value is **OH_COLORSPACE_BT709_LIMIT**. For details, see [OH_NativeBuffer_ColorSpace](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_colorspace).<br> It is used in [OH_VideoDecoder_Configure](capi-native-avcodec-videodecoder-h.md#oh_videodecoder_configure).<br> Before calling **OH_VideoDecoder_Start**, you must call **OH_VideoDecoder_Prepare**.<br> If Color Space Conversion (CSC) is supported and this key is configured, the video decoder automatically transcodes the HDR Vivid video to the specified color space.<br> If CSC is not supported, the error code **AV_ERR_VIDEO_UNSUPPORTED_COLOR_SPACE_CONVERSION** in [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) is returned when [OH_VideoDecoder_Configure](capi-native-avcodec-videodecoder-h.md#oh_videodecoder_configure) is called. If the input video is not an HDR Vivid video, the callback function [OH_AVCodecOnError](#oh_avcodeconerror) is invoked to report the error code **AV_ERR_VIDEO_UNSUPPORTED_COLOR_SPACE_CONVERSION** in [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode).<br>**Since**: 12<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_DECODER_OUTPUT_ENABLE_VRR | Pointer to the key that specifies whether the decoder enables the video variable frame rate feature. The value type is int32_t.<br> **1** if enabled, **0** otherwise.<br>**Since**: 15<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_CREATION_TIME | Pointer to the key that describes the media file creation time. The value type is char *. The value must be in the UTC time format complying with ISO 8601. Time format example: 2024-12-28T00:00:00.000000Z<br>**Since**: 14<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER | Pointer to the key that describes the duration (in milliseconds) for which the last frame will be resubmitted repeatedly, if no new frame is available after the previous frame is submitted to the encoder. The value type is int32_t.<br> This key is used only in the configuration phase of video encoding in surface mode.<br> Configured value.<br> - If the value is less than or equal to 0, the request is intercepted in the configuration phase and **ERROR AV_ERR_INVALID_VAL** is returned.<br> - If the value is greater than 0, the last frame will be resubmitted repeatedly in the specified duration, measured in milliseconds.<br>**Since**: 18<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_MAX_COUNT | Pointer to the key that describes the maximum number of times the encoder can repeat encoding the previous frame when no new frame is available. The value type is int32_t.<br> This key takes effect only when **OH_MD_KEY_VIDEO_ENCODER_REPEAT_PREVIOUS_FRAME_AFTER** is available and is used only in the configuration phase.<br> Configured value.<br> - If the value is equal to 0, the request is intercepted in the configuration phase and **ERROR AV_ERR_INVALID_VAL** is returned.<br> - If the value is less than 0 and no new frame is available, the encoder repeatedly encodes the previous frame until the upper limit of the system is reached.<br> - If the value is greater than 0 and no new frame is available, the encoder repeatedly encodes the previous frame until the maximum number specified is reached.<br>**Since**: 18<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_ENABLE_B_FRAME | Pointer to the key that describes the enabled status of B-frame encoding. The value type is int32_t (**0** or **1**). **1** if enabled, **0** otherwise. This key is optional and used only for video encoding. The default value is **0**.<br> If enabled, the video encoder uses B-frames, resulting in a different decoding order from the display order.<br> If the platform does not support this feature, the configuration of this key does not take effect.<br> To check whether the platform supports B-frame encoding, use the [OH_AVCapability_IsFeatureSupported](capi-native-avcapability-h.md#oh_avcapability_isfeaturesupported) API and the enumerated value [OH_AVCapabilityFeature](capi-native-avcapability-h.md#oh_avcapabilityfeature).VIDEO_ENCODER_B_FRAME.<br> This key is used only in the configuration phase.<br><br>**Since**: 20<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_MAX_B_FRAMES | Pointer to the key that describes the maximum number of consecutive B-frames supported by the video encoder. The value type is int32_t. Note: This key is used only to query the encoder capability.<br> The usage specifications are as follows:<br> 1. To check whether the platform supports B-frame encoding, use the [OH_AVCapability_IsFeatureSupported](capi-native-avcapability-h.md#oh_avcapability_isfeaturesupported) API and the enumerated value [OH_AVCapabilityFeature](capi-native-avcapability-h.md#oh_avcapabilityfeature).VIDEO_ENCODER_B_FRAME.<br> 2. Obtain the OH_AVFormat pointer through the [OH_AVCapability_GetFeatureProperties](capi-native-avcapability-h.md#oh_avcapability_getfeatureproperties) API and the enumerated value [OH_AVCapabilityFeature](capi-native-avcapability-h.md#oh_avcapabilityfeature).VIDEO_ENCODER_B_FRAME.<br> 3. Obtain the maximum number of B-frames through the [OH_AVFormat_GetIntValue](capi-native-avformat-h.md#oh_avformat_getintvalue) API and this key.<br><br>**Since**: 20<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_ROI_PARAMS | Pointer to the key that describes the region of interest (ROI). The value is a character string in the format of **Top1,Left1-Bottom1,Right1[=Params1];Top2,Left2-Bottom2,Right2[=Params2];**. Each **Top,Left-Bottom,Right** represents the coordinate information of an ROI. **[=Params]** is optional, and its format varies with the version.<br>- Before API version 26.0.0: Only a single int32_t value representing the quantization parameter offset was supported (for example, **=Offset**).<br>- Since API version 26.0.0: Key-value pair format is additionally supported and recommended. The parameter uses comma-separated key-value pairs (for example, **=dqp:-6,slb:1**).<br>Supported keys include: <br>- **dqp**: Quantization parameter offset.<br>- **slb**: Semantic label.<br>The value must correspond to [OH_VideoMetadataRoiSemanticLabel](./capi-native-avcodec-videobase-h.md#oh_videometadataroisemanticlabel). If **=Params** is omitted entirely (for example, **Top1,Left1-Bottom1,Right1;Top2,Left2-Bottom2,Right2=dqp:-6;**), the encoder will apply default parameters for ROI encoding on the first ROI and the specified parameters for the second ROI. Note that the number of ROIs that can be applied simultaneously must not exceed 6, and the total area must not exceed 1/5 of the image area. This is an optional key that applies only to video encoders. It takes effect on a frame basis during runtime. In Surface mode, it is used for [OH_VideoEncoder_OnNeedInputParameter](./capi-native-avcodec-videoencoder-h.md#oh_videoencoder_onneedinputparameter). In Buffer mode, it is configured via [OH_AVBuffer_SetParameter](./capi-native-avbuffer-h.md#oh_avbuffer_setparameter).<br>**Since**: 20<br> **Note**: Since API version 26.0.0, you are advised to use [OH_VideoMetadata_AppendRoiString](../apis-avcodec-kit/capi-native-avcodec-videobase-h.md#oh_videometadata_appendroistring) to safely convert and append ROI configurations, rather than manually concatenating strings.|
| const char * OH_MD_KEY_SQR_FACTOR | Pointer to the key that describes the quality parameter in SQR mode. Only H.265 (HEVC) is supported. The value range is [0, 51] (same as the QP value in encoding). A smaller value indicates a higher output bit rate and better quality.<br> It is used in the configuration or parameter setting phase.<br>**Since**: 20<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_MAX_BITRATE | Pointer to the key that describes the maximum bit rate in SQR mode. Only H.265 (HEVC) is supported. Use the [OH_AVCapability_GetEncoderBitrateRange](capi-native-avcapability-h.md#oh_avcapability_getencoderbitraterange) method to obtain the value range (same as **OH_MD_KEY_BITRATE**). The unit is bps and the value type is int64_t.<br> It is used in the configuration or parameter setting phase.<br>**Since**: 20<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_ENCODER_ENABLE_PTS_BASED_RATECONTROL | Pointer to the key that describes the enabled status of the PTS-based bit rate control mode. The value type is int32_t. **1** if enabled, **0** otherwise. The default value is **0**. If this parameter is set to a non-zero value, the value **1** is used.<br>This key is optional and is used only for video encoding.<br> If this feature is enabled, each video frame must contain PTS information and be sent to the encoder. In surface mode, the PTS is set by calling [OH_NativeWindow_NativeWindowHandleOpt](../apis-arkgraphics2d/capi-external-window-h.md#oh_nativewindow_nativewindowhandleopt), in units of nanosecond (ns). In buffer mode, the PTS is set by calling [OH_AVBuffer_SetBufferAttr](capi-native-avbuffer-h.md#oh_avbuffer_setbufferattr), in units of microsecond (us).<br> It is used in the configuration phase.<br>**Since**: 20<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_REFERENCE_TRACK_IDS | Pointer to the key that describes the reference relationship between media file tracks. The value type is int32_t*.<br>**Since**: 20<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_TRACK_REFERENCE_TYPE | Pointer to the key that describes the auxiliary track type of a media file. The value type is char *.<br>**Since**: 20<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_TRACK_DESCRIPTION | Pointer to the key that describes the auxiliary track description of a media file. The value type is char *.<br>**Since**: 20<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_ENABLE_SYNC_MODE | Pointer to the key that describes the enabled status of audio/video codec synchronization. The value type is int32_t. **1** if enabled, **0** otherwise. The default value is **0**. If this parameter is set to a non-zero value, the value **1** is used. This key is optional.<br>If this feature is enabled, pay attention to the following:<br> 1. The codec cannot have a callback function.<br> 2. You must use the buffer query API instead of the callback function.<br> 3. The key can be used only in the configuration phase.<br>**Since**: 20<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_DECODER_BLANK_FRAME_ON_SHUTDOWN | Pointer to the key that specifies whether to output blank frames when the video decoder is disabled. The value type is int32_t. **1** to output, **0** otherwise. The default value is **0**. If this parameter is set to a non-zero value, the value **1** is used. This key is optional and is used only for video decoding in surface mode.<br> After this function is enabled, the video decoder outputs a blank frame (usually black) when the [OH_VideoDecoder_Stop](capi-native-avcodec-videodecoder-h.md#oh_videodecoder_stop) or [OH_VideoDecoder_Destroy](capi-native-avcodec-videodecoder-h.md#oh_videodecoder_destroy) API is called. This mechanism prevents frozen frames caused by sudden termination of the decoder.<br>**Since**: 20<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_NATIVE_BUFFER_FORMAT | Pointer to the key that is used to query the native buffer pixel format in video encoding and decoding. The value type is int32_t.<br> For details, see the pixel formats defined in [OH_NativeBuffer_Format](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_format). This key is used in the following scenarios:<br> 1. Video decoding: Call [OH_VideoDecoder_GetOutputDescription](capi-native-avcodec-videodecoder-h.md#oh_videodecoder_getoutputdescription) or [OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged), and obtain the current output format from the returned OH_AVFormat object.<br> 2. Video encoding: Call [OH_VideoEncoder_GetInputDescription](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_getinputdescription) to obtain the current input format from the returned OH_AVFormat object.<br>**Since**: 22<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_BUFFER_SKIP_SAMPLES_INFO | Pointer to the key carried in the OH_AVBuffer used to skip part of the decoded audio data. It is measured in sample points, with a value type of uint8_t*. This key is supported when using MP3, Vorbis, or OPUS decoders.<br> It is carried only by the first and last frames of an audio stream and is optional. Method 1: Obtain the information during demultiplexing and set it to the input OH_AVBuffer used for decoding.<br> 1. Obtain the OH_AVBuffer used for decoding from the callback function [OH_AVCodecOnNeedInputBuffer](#oh_avcodeconneedinputbuffer) of [OH_AVCodecCallback](capi-codecbase-oh-avcodeccallback.md).<br> 2. Call [OH_AVDemuxer_ReadSampleBuffer](capi-native-avdemuxer-h.md#oh_avdemuxer_readsamplebuffer) to read audio data. This function automatically sets **OH_MD_KEY_BUFFER_SKIP_SAMPLES_INFO** when needed.<br> 3. Call [OH_AudioCodec_PushInputBuffer](capi-native-avcodec-audiocodec-h.md#oh_audiocodec_pushinputbuffer) to push the input OH_AVBuffer for decoding.<br> Method 2: Construct the data required by the key and set it to the input OH_AVBuffer used for decoding.<br> Create a 10-byte uint8_t[] array with the structure as follows:<br> 1. Bytes 0-3 (uint32_t, little-endian): number of samples to skip from the beginning of this frame.<br> 2. Bytes 4-7 (uint32_t, little-endian): number of samples to skip from the end of this frame (must not exceed the frame's total sample count).<br> 3. Bytes 8-9: reserved; set to **0**.<br><br>**Since**: 23<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_ENABLE_BUFFER_SKIP_SAMPLES | Pointer to the key for enabling OH_MD_KEY_BUFFER_SKIP_SAMPLES_INFO in the audio decoder. The value type is int32_t. **1** to enable, **0** otherwise. The default value is **0**. If this parameter is set to a value other than **1**, the value **0** is used.<br>This key is optional. It is for the audio decoder only.<br>**Since**: 24|
| const char * OH_MD_KEY_LATITUDE | Pointer to the key that describes the latitude. The value is of the float type, and the value range is [-90.0, 90.0]. It indicates the latitude in geographic location information.<br>**Since**: 24|
| const char * OH_MD_KEY_LONGITUDE | Pointer to the key that describes the longitude. The value is of the float type, and the value range is [-180.0, 180.0]. It indicates the longitude in geographic location information.<br>**Since**: 24|
| const char * OH_MD_KEY_ALTITUDE | Pointer to the key that describes the altitude. The value is of the float type. This key is optional. It indicates the altitude in geographic location information.<br>**Since**: 24|
| const char * OH_MD_KEY_VIDEO_ENCODER_NUMBER_OF_PENDING_FRAMES | Pointer to the key that describes the number of frames to be processed by the video encoder. The value type is int32_t. This key is read-only and is used to query the number of frames currently waiting to be encoded. It can be obtained via the [OH_VideoEncoder_GetInputDescription](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_getinputdescription) API.<br>**Since**: 26.0.0|
| const char * OH_MD_KEY_VIDEO_DECODER_OUTPUT_IN_DECODING_ORDER | Pointer to the key that describes the decoder output mode. The value type is int32_t. The value can be **0** or **1**. **1** indicates that the decoder outputs frames in decoding order, while **0** indicates that the decoder outputs frames in display order. The default value is **0**. This key is optional and applies only to video decoding. It can be configured only during the configuration phase. Before setting this key, you can use the [OH_AVCapability_IsFeatureSupported](capi-native-avcapability-h.md#oh_avcapability_isfeaturesupported) API with the enumeration value [OH_AVCapabilityFeature](capi-native-avcapability-h.md#oh_avcapabilityfeature).VIDEO_DECODER_OUTPUT_IN_DECODING_ORDER to query whether the feature is supported. If the video decoder does not support this feature, setting this key via the [OH_VideoDecoder_Configure](capi-native-avcodec-videodecoder-h.md#oh_videodecoder_configure) API will return **AV_ERR_INVALID_VAL**.<br>**Since**: 26.0.0|
| const char * OH_MD_KEY_VIDEO_ENCODER_MAX_FRAME_DELAY_COUNT | Pointer to the key that describes the maximum number of frames that the video encoder is allowed to buffer before outputting compressed frames. The value type is int32_t, and the value range is [1, 5]. This key is optional and applies only to video encoding. It can be configured only during the configuration phase. If the value falls within the [1, 5] range, it takes effect normally. If the value is outside this range (less than 1 or greater than 5), calling the [OH_VideoEncoder_Configure](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_configure) API will return **AV_ERR_INVALID_VAL**.<br>**Since**: 26.0.0|
| const char * OH_MD_KEY_VIDEO_ENCODER_REPEAT_HEADER_BEFORE_SYNC_FRAMES | Pointer to the key that describes whether to enable the parameter set before the sync frame in the bitstream. The value type is int32_t, with the value being either **0** or **1**. **1** means to enable, and **0** means to disable. The default value is **0**. This key is optional and applies only to video encoding. It can be configured only during the configuration phase. When enabled, the encoder inserts parameter set data (such as SPS and PPS for H.264/H.265 formats) before each sync frame.<br>**Since**: 26.0.0|
| const char * OH_MD_KEY_AUDIO_VIVID_SIGNAL_FORMAT | Pointer to the key that describes the Audio Vivid input signal format. The value type is int32_t. This key is used only for the Audio Vivid encoder.<br> For details, see [OH_AudioVividSignalFormat](capi-native-audio-vivid-h.md#oh_audiovividsignalformat).<br>**Since**: 26.0.0|
| const char * OH_MD_KEY_AUDIO_SOUNDBED_LAYOUT | Pointer to the key that describes the channel layout of the audio bed. The value type is int64_t. This key is optional and is used only for the Audio Vivid encoder.<br> For details, see [OH_AudioChannelLayout](capi-native-audio-channel-layout-h.md#oh_audiochannellayout).<br>**Since**: 26.0.0|
| const char * OH_MD_KEY_AUDIO_SOUNDBED_BITRATE | Pointer to the key that describes the encoding bitrate of the audio bed. The value type is int64_t. This key is optional and is used only for the Audio Vivid encoder.<br> The actual encoding bitrate may be adjusted based on the encoder's capability.<br>**Since**: 26.0.0|
| const char * OH_MD_KEY_AUDIO_OBJECT_BITRATE | Pointer to the key that describes the encoding bitrate of the audio object. The value type is int64_t. This key is optional and applies only to the Audio Vivid encoder.<br> The actual encoding bitrate may be adjusted based on the encoder's capability.<br>**Since**: 26.0.0|
| const char * OH_MD_KEY_AUDIO_MAX_INPUT_BUFFER_SIZE | Pointer to the key for setting or querying the maximum input buffer size of an audio encoder. The unit is bytes, and the value type is int32_t. This key is used to configure or retrieve the maximum input buffer size of the audio encoder. The actual buffer size is limited by the encoder implementation. If the value exceeds the maximum supported by the encoder, the setting will not take effect. This configuration is optional. If it is not set, the encoder will use the default buffer size.<br>**Since**: 26.0.0|
| const char * OH_MD_KEY_AUDIO_ENCODER_PTS_MODE | Pointer to the key for configuring the Presentation Time Stamp (PTS) output mode of an audio encoder. It sets the PTS output behavior. The value type is int32_t. For details, see [OH_AudioEncoderPTSMode](#oh_audioencoderptsmode). This key is optional. If it is not set, the default value [OH_AUDIO_ENCODER_PTS_MODE_DEFAULT](#oh_audioencoderptsmode) is used.<br>**Since**: 26.0.0|
| const char * OH_MD_KEY_AUDIO_ENCODER_ENABLE_SAMPLE_FORMAT_CONVERT | Pointer to the key for enabling sample format conversion of an audio encoder. The value type is int32_t, with the value being either **0** or **1**. **1** means to enable the conversion, and **0** means to disable the conversion. The default value is **0**. An audio encoder support only a limited set of sample formats. When this configuration is enabled, if an unsupported sample format is used, the audio encoder will convert it to a supported format before encoding. The following sampling formats are supported before conversion: [SAMPLE_U8](#oh_bitspersample), [SAMPLE_S16LE](#oh_bitspersample), [SAMPLE_S24LE](#oh_bitspersample), [SAMPLE_S32LE](#oh_bitspersample), and [SAMPLE_F32LE](#oh_bitspersample).<br>**Since**: 26.0.0|
| const char * OH_MD_KEY_VIDEO_ENCODER_PREPROC_DOWNSAMPLING_WIDTH  | Pointer to the key that describes the target width for downsampling in video encoding pre-processing. The value type is int32_t. This key is optional, and the downsampling feature is disabled by default. This key must be used together with **OH_MD_KEY_VIDEO_ENCODER_PREPROC_DOWNSAMPLING_HEIGHT**. When both are set to **0**, the downsampling feature is disabled. You can use [OH_AVCapability_IsVideoSizeSupported](capi-native-avcapability-h.md#oh_avcapability_isvideosizesupported) to query the supported range of downsampling widths and heights. Downsampling parameters are mutually exclusive with cropping parameters. Downsampling and cropping cannot be enabled simultaneously. <br>This key is applicable only to video encoders that support pre-processing or to one-input-two-output encoding scenarios. It can be configured during the configuration phase or dynamically adjusted at runtime via **SetParameter**.<br>**Since**: 26.0.0 |
| const char * OH_MD_KEY_VIDEO_ENCODER_PREPROC_DOWNSAMPLING_HEIGHT | Pointer to the key that describes the target height for downsampling in video encoding pre-processing. The value type is int32_t. This key is optional, and the downsampling feature is disabled by default. This key must be used together with **OH_MD_KEY_VIDEO_ENCODER_PREPROC_DOWNSAMPLING_WIDTH**. When both are set to **0**, the downsampling feature is disabled. You can use [OH_AVCapability_IsVideoSizeSupported](capi-native-avcapability-h.md#oh_avcapability_isvideosizesupported) to query the supported range of downsampling widths and heights. Downsampling parameters are mutually exclusive with cropping parameters. Downsampling and cropping cannot be enabled simultaneously. <br>This key is applicable only to video encoders that support pre-processing or to one-input-two-output encoding scenarios. It can be configured during the configuration phase or dynamically adjusted at runtime via **SetParameter**.<br>**Since**: 26.0.0|
| const char * OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_LEFT         | Pointer to the key that describes the left coordinate (x) of the cropping region in video encoding pre-processing. The value type is int32_t. This key is optional, and the cropping feature is disabled by default. The four parameters **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_LEFT**, **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_TOP**, **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_RIGHT**, and **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_BOTTOM** must be set together. When all are set to **0**, the cropping feature is disabled. The default coordinate origin is the upper-left corner of the input video frame (0, 0). The coordinate values must not exceed the width and height of the input video frame, and must satisfy **(0, 0) <= (LEFT, TOP) < (RIGHT, BOTTOM) < (input video frame width, input video frame height)**. Downsampling parameters are mutually exclusive with cropping parameters. Downsampling and cropping cannot be enabled simultaneously. <br>This key is applicable only to video encoders that support pre-processing or to one-input-two-output encoding scenarios. It can be configured during the configuration phase or dynamically adjusted at runtime via **SetParameter**.<br>**Since**: 26.0.0|
| const char * OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_TOP          | Pointer to the key that describes the top coordinate (y) of the cropping region in video encoding pre-processing. The value type is int32_t. This key is optional, and the cropping feature is disabled by default. The four parameters **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_LEFT**, **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_TOP**, **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_RIGHT**, and **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_BOTTOM** must be set together. When all are set to **0**, the cropping feature is disabled. The default coordinate origin is the upper-left corner of the input video frame (0, 0). The coordinate values must not exceed the width and height of the input video frame, and must satisfy **(0, 0) <= (LEFT, TOP) < (RIGHT, BOTTOM) < (input video frame width, input video frame height)**. Downsampling parameters are mutually exclusive with cropping parameters. Downsampling and cropping cannot be enabled simultaneously. <br>This key is applicable only to video encoders that support pre-processing or to one-input-two-output encoding scenarios. It can be configured during the configuration phase or dynamically adjusted at runtime via **SetParameter**.<br>**Since**: 26.0.0|
| const char * OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_RIGHT        | Pointer to the key that describes the right coordinate (x) of the cropping region in video encoding pre-processing. The value type is int32_t. This key is optional, and the cropping feature is disabled by default. The four parameters **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_LEFT**, **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_TOP**, **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_RIGHT**, and **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_BOTTOM** must be set together. When all are set to **0**, the cropping feature is disabled. The default coordinate origin is the upper-left corner of the input video frame (0, 0). The coordinate values must not exceed the width and height of the input video frame, and must satisfy **(0, 0) <= (LEFT, TOP) < (RIGHT, BOTTOM) < (input video frame width, input video frame height)**. Downsampling parameters are mutually exclusive with cropping parameters. Downsampling and cropping cannot be enabled simultaneously. <br>This key is applicable only to video encoders that support pre-processing or to one-input-two-output encoding scenarios. It can be configured during the configuration phase or dynamically adjusted at runtime via **SetParameter**.<br>**Since**: 26.0.0|
| const char * OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_BOTTOM       | Pointer to the key that describes the bottom coordinate (y) of the cropping region in video encoding pre-processing. The value type is int32_t. This key is optional, and the cropping feature is disabled by default. The four parameters **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_LEFT**, **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_TOP**, **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_RIGHT**, and **OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_BOTTOM** must be set together. When all are set to **0**, the cropping feature is disabled. The default coordinate origin is the upper-left corner of the input video frame (0, 0). The coordinate values must not exceed the width and height of the input video frame, and must satisfy **(0, 0) <= (LEFT, TOP) < (RIGHT, BOTTOM) < (input video frame width, input video frame height)**. Downsampling parameters are mutually exclusive with cropping parameters. Downsampling and cropping cannot be enabled simultaneously. <br>This key is applicable only to video encoders that support pre-processing or to one-input-two-output encoding scenarios. It can be configured during the configuration phase or dynamically adjusted at runtime via **SetParameter**.<br>**Since**: 26.0.0|
| const char * OH_MD_KEY_VIDEO_ENCODER_PREPROC_DROP_TO_FRAME_RATE | Pointer to the key that describes the target frame rate for frame dropping in video encoding pre-processing. The value type is double, and the value is accurate to two decimal places. This key is optional, and the frame dropping feature is disabled by default. Setting it to **0.00** disables the feature. When a value is set, it is automatically rounded to two decimal places. This key can be used independently or in combination with downsampling or cropping.<br>This key is applicable only to video encoders that support pre-processing or to one-input-two-output encoding scenarios. It can be configured during the configuration phase or dynamically adjusted at runtime via **SetParameter**.<br>**Since**: 26.0.0|
| const char * OH_MD_KEY_VIDEO_DECODER_FRAME_RETENTION_MODE | Pointer to the key that describes the frame retention mode of video decoding. The value type is int32_t. The value indicates the frame retention mode defined in [OH_FrameRetentionMode](#oh_frameretentionmode). For details about each mode and its behavior, see the enumeration definition of OH_FrameRetentionMode.<br> You can configure this key through [OH_VideoDecoder_Configure](capi-native-avcodec-videodecoder-h.md#oh_videodecoder_configure) and [OH_VideoDecoder_SetParameter](capi-native-avcodec-videodecoder-h.md#oh_videodecoder_setparameter).<br>**Since**: 26.0.0|
| const char * OH_MD_KEY_VIDEO_DECODER_FRAME_RETENTION_RATIO | Pointer to the key that describes the frame retention ratio of video decoding. The value type is double. This key takes effect if **OH_MD_KEY_VIDEO_DECODER_FRAME_RETENTION_MODE** is set to **OH_FRAME_RETENTION_MODE_UNIFORM** or the retention mode is not configured (even logic is implicitly used by default).<br> This key is ignored only when the retention mode is explicitly set to **OH_FRAME_RETENTION_MODE_ADAPTIVE** or **OH_FRAME_RETENTION_MODE_FULL**.<br> The valid range is [0.01, 1.0] (where **1.0** indicates that all frames are retained, and **0.01** is the minimum limit). Any value beyond this range is considered invalid and ignored.<br> You can configure this key through [OH_VideoDecoder_Configure](capi-native-avcodec-videodecoder-h.md#oh_videodecoder_configure) and [OH_VideoDecoder_SetParameter](capi-native-avcodec-videodecoder-h.md#oh_videodecoder_setparameter). For details about each mode and its behavior, see the enumeration definition of [OH_FrameRetentionMode](#oh_frameretentionmode).<br>**Since**: 26.0.0|
| const char * OH_MD_KEY_VIDEO_DECODER_SPEED | Pointer to the key that describes the playback speed of the video decoder. The value type is double. This key is used to specify the target playback speed of the video. It is recommended that this key be used together with the **OH_FRAME_RETENTION_MODE_ADAPTIVE** mode to assist the perceptual adaptive algorithm in accurately evaluating the impact of frame loss on visual perception.<br> The value must be strictly greater than 0.0. The recommended standard values include 0.5, 0.75, 1.0 (normal speed), 1.25, 1.5, 2.0, and 3.0. Any value less than or equal to 0.0 is considered invalid.<br> You can configure this key through [OH_VideoDecoder_Configure](capi-native-avcodec-videodecoder-h.md#oh_videodecoder_configure) and [OH_VideoDecoder_SetParameter](capi-native-avcodec-videodecoder-h.md#oh_videodecoder_setparameter). For details about each mode and its behavior, see the enumeration definition of [OH_FrameRetentionMode](#oh_frameretentionmode).<br>**Since**: 26.0.0|
| const char * OH_MD_KEY_AUDIO_MAX_INPUT_BUFFER_SIZE | Pointer to the key for setting or querying the maximum input buffer size of the audio codec. The value type is int32_t, and the unit is bytes.<br> This key is used to configure or retrieve the maximum input buffer size of the audio codec. The actual buffer size is limited by the codec implementation. Values exceeding the upper limit will not take effect.<br> This key is optional. If this key is not set, the codec uses the default buffer size.<br>**Since**: 26.0.0|
| const char * OH_MD_KEY_AUDIO_ENCODER_PTS_MODE | Pointer to the key for configuring the output PTS mode of an audio encoder. The value type is int32_t. For details, see [OH_AudioEncoderPTSMode](#oh_audioencoderptsmode).<br> This key is optional. If it is not set, the default value **OH_AUDIO_ENCODER_PTS_MODE_DEFAULT** is used.<br>**Since**: 26.0.0|
| const char * OH_MD_KEY_AUDIO_ENCODER_ENABLE_SAMPLE_FORMAT_CONVERT | Pointer to the key for enabling sample format conversion of an audio encoder. The value type is int32_t. The value **1** enables the conversion, and the value **0** disables it. The default value is **0**.<br> An audio encoders support only a limited set of sample formats. When this feature is enabled, if an unsupported sample format is used, the encoder will convert it to a supported format before encoding.<br> After enabling, the supported input sample formats are: SAMPLE_U8, SAMPLE_S16LE, SAMPLE_S24LE, SAMPLE_S32LE, and SAMPLE_F32LE. For details, see [OH_BitsPerSample](#oh_bitspersample).<br> This key is optional and used only during the audio encoding configuration phase.<br>**Since**: 26.0.0|

## Enum Description

### OH_MediaType

```c
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

```c
enum OH_AACProfile
```

**Description**

Enumerates the AAC profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

| Value| Description|
| -- | -- |
| AAC_PROFILE_LC = 0 | AAC profile of the low complexity level.|
| AAC_PROFILE_HE = 3 | AAC profile of the high efficiency level. Audio object types AAC LC and SBR are included.<br>**Since**: 14|
| AAC_PROFILE_HE_V2 = 4 | AAC profile of the high efficiency V2 level. Audio object types AAC LC, SBR, and PS are included.<br>**Since**: 14|

### OH_AVCProfile

```c
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

```c
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

```c
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

```c
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

```c
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

```c
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

### OH_VC1Profile

```c
enum OH_VC1Profile
```

**Description**

Enumerates the VC-1 profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 22

| Value| Description|
| -- | -- |
| VC1_PROFILE_SIMPLE = 0 | Simple profile.|
| VC1_PROFILE_MAIN = 1 | Main profile.|
| VC1_PROFILE_ADVANCED = 2 | High profile.|

### OH_AV1Profile

```c
enum OH_AV1Profile
```

**Description**

AV1 profile.

**Since**: 23

| Value| Description|
| -- | -- |
| AV1_PROFILE_MAIN = 0 | Main profile.|
| AV1_PROFILE_HIGH = 1 | High profile.|
| AV1_PROFILE_PROFESSIONAL = 2 | Professional profile.|

### OH_VP9Profile

```c
enum OH_VP9Profile
```

**Description**

VP9 profile.

**Since**: 23

| Value| Description|
| -- | -- |
| VP9_PROFILE_0 = 0 | Profile 0.|
| VP9_PROFILE_1 = 1 | Profile 1.|
| VP9_PROFILE_2 = 2 | Profile 2.|
| VP9_PROFILE_3 = 3 | Profile 3.|

### OH_WVC1Profile

```c
enum OH_WVC1Profile
```

**Description**

WVC1 profile.

**Since**: 23

| Value| Description|
| -- | -- |
| WVC1_PROFILE_ADVANCED = 0 | High profile.|

### OH_WMV3Profile

```c
enum OH_WMV3Profile
```

**Description**

Enumerates the WMV3 profiles.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 22

| Value| Description|
| -- | -- |
| WMV3_PROFILE_SIMPLE = 0 | Simple profile.|
| WMV3_PROFILE_MAIN = 1 | Main profile.|

### OH_AVOutputFormat

```c
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
| AV_OUTPUT_FORMAT_OGG = 13 | OGG.<br>**Since**: 23|
| AV_OUTPUT_FORMAT_FLV = 14 | The output file is in FLV format.<br>**Since**: 26.0.0|

### OH_AVSeekMode

```c
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

```c
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
| SCALING_MODE_SCALE_TO_WINDOW = 1 | Scales the image based on the window size.<br>**Substitute**: [OHScalingModeV2](../apis-arkgraphics2d/capi-external-window-h.md#ohscalingmodev2).OH_SCALING_MODE_SCALE_TO_WINDOW_V2|
| SCALING_MODE_SCALE_CROP = 2 | Crops the image based on the window size.<br>**Substitute**: [OHScalingModeV2](../apis-arkgraphics2d/capi-external-window-h.md#ohscalingmodev2).OH_SCALING_MODE_SCALE_CROP_V2 |

### OH_BitsPerSample

```c
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

```c
enum OH_ColorPrimary
```

**Description**

Enumerates the primary colors. This enum is used for both encoding and decoding.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description|
| -- | -- |
| COLOR_PRIMARY_BT709 = 1 | BT709 color gamut.|
| COLOR_PRIMARY_UNSPECIFIED = 2 | Unspecified color gamut.|
| COLOR_PRIMARY_BT470_M = 4 | BT470_M color gamut.|
| COLOR_PRIMARY_BT601_625 = 5 | BT601_625 color gamut.|
| COLOR_PRIMARY_BT601_525 = 6 | BT601_525 color gamut.|
| COLOR_PRIMARY_SMPTE_ST240 = 7 | SMPTE_ST240 color gamut.|
| COLOR_PRIMARY_GENERIC_FILM = 8 | GENERIC_FILM color gamut.|
| COLOR_PRIMARY_BT2020 = 9 | BT2020 color gamut.|
| COLOR_PRIMARY_SMPTE_ST428 = 10 | SMPTE_ST428 color gamut.|
| COLOR_PRIMARY_P3DCI = 11 | P3DCI color gamut.|
| COLOR_PRIMARY_P3D65 = 12 | P3D65 color gamut.|

### OH_TransferCharacteristic

```c
enum OH_TransferCharacteristic
```

**Description**

Enumerates the transfer characteristics. This enum is used for both encoding and decoding.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description|
| -- | -- |
| TRANSFER_CHARACTERISTIC_BT709 = 1 | BT709 transfer function.|
| TRANSFER_CHARACTERISTIC_UNSPECIFIED = 2 | Unspecified transfer function.|
| TRANSFER_CHARACTERISTIC_GAMMA_2_2 = 4 | GAMMA_2_2 transfer function.|
| TRANSFER_CHARACTERISTIC_GAMMA_2_8 = 5 | GAMMA_2_8 transfer function.|
| TRANSFER_CHARACTERISTIC_BT601 = 6 | BT601 transfer function.|
| TRANSFER_CHARACTERISTIC_SMPTE_ST240 = 7 | SMPTE_ST240 transfer function.|
| TRANSFER_CHARACTERISTIC_LINEAR = 8 | Linear transfer function.|
| TRANSFER_CHARACTERISTIC_LOG = 9 | Log transfer function.|
| TRANSFER_CHARACTERISTIC_LOG_SQRT = 10 | LOG_SQRT transfer function.|
| TRANSFER_CHARACTERISTIC_IEC_61966_2_4 = 11 | IEC_61966_2_4 transfer function.|
| TRANSFER_CHARACTERISTIC_BT1361 = 12 | BT1361 transfer function.|
| TRANSFER_CHARACTERISTIC_IEC_61966_2_1 = 13 | IEC_61966_2_1 transfer function.|
| TRANSFER_CHARACTERISTIC_BT2020_10BIT = 14 | BT2020_10BIT transfer function.|
| TRANSFER_CHARACTERISTIC_BT2020_12BIT = 15 | BT2020_12BIT transfer function.|
| TRANSFER_CHARACTERISTIC_PQ = 16 | PQ transfer function.|
| TRANSFER_CHARACTERISTIC_SMPTE_ST428 = 17 | SMPTE_ST428 transfer function.|
| TRANSFER_CHARACTERISTIC_HLG = 18 | HLG transfer function.|

### OH_MatrixCoefficient

```c
enum OH_MatrixCoefficient
```

**Description**

Enumerates the matrix coefficients. This enum is used for both encoding and decoding.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

| Value| Description|
| -- | -- |
| MATRIX_COEFFICIENT_IDENTITY = 0 | Identity matrix.|
| MATRIX_COEFFICIENT_BT709 = 1 | BT709 conversion matrix.|
| MATRIX_COEFFICIENT_UNSPECIFIED = 2 | Unspecified conversion matrix.|
| MATRIX_COEFFICIENT_FCC = 4 | FCC conversion matrix.|
| MATRIX_COEFFICIENT_BT601_625 = 5 | BT601_625 conversion matrix.|
| MATRIX_COEFFICIENT_BT601_525 = 6 | BT601_525 conversion matrix.|
| MATRIX_COEFFICIENT_SMPTE_ST240 = 7 | SMPTE_ST240 conversion matrix.|
| MATRIX_COEFFICIENT_YCGCO = 8 | YCGCO conversion matrix.|
| MATRIX_COEFFICIENT_BT2020_NCL = 9 | BT2020_NCL conversion matrix.|
| MATRIX_COEFFICIENT_BT2020_CL = 10 | BT2020_CL conversion matrix.|
| MATRIX_COEFFICIENT_SMPTE_ST2085 = 11 | SMPTE_ST2085 conversion matrix.|
| MATRIX_COEFFICIENT_CHROMATICITY_NCL = 12 | CHROMATICITY_NCL conversion matrix.|
| MATRIX_COEFFICIENT_CHROMATICITY_CL = 13 | CHROMATICITY_CL conversion matrix.|
| MATRIX_COEFFICIENT_ICTCP = 14 | ICTCP conversion matrix.|

### OH_AVCLevel

```c
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

```c
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

```c
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

```c
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

```c
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

```c
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

### OH_VC1Level

```c
enum OH_VC1Level
```

**Description**

Enumerates the VC-1 levels.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 22

| Value| Description|
| -- | -- |
| VC1_LEVEL_L0 = 0 | Level L0.|
| VC1_LEVEL_L1 = 1 | Level L1.|
| VC1_LEVEL_L2 = 2 | Level L2.|
| VC1_LEVEL_L3 = 3 | Level L3.|
| VC1_LEVEL_L4 = 4 | Level L4.|
| VC1_LEVEL_LOW = 5 | Low level.|
| VC1_LEVEL_MEDIUM = 6 | Medium level.|
| VC1_LEVEL_HIGH = 7 |  High level.|

### OH_AV1Level

```c
enum OH_AV1Level
```

**Description**

AV1 level.

**Since**: 23

| Value| Description|
| -- | -- |
| AV1_LEVEL_20 = 0 | Level 2.0.|
| AV1_LEVEL_21 = 1 | Level 2.1.|
| AV1_LEVEL_22 = 2 | Level 2.2.|
| AV1_LEVEL_23 = 3 | Level 2.3.|
| AV1_LEVEL_30 = 4 | Level 3.0.|
| AV1_LEVEL_31 = 5 | Level 3.1.|
| AV1_LEVEL_32 = 6 | Level 3.2.|
| AV1_LEVEL_33 = 7 | Level 3.3.|
| AV1_LEVEL_40 = 8 | Level 4.0.|
| AV1_LEVEL_41 = 9 | Level 4.1.|
| AV1_LEVEL_42 = 10 | Level 4.2.|
| AV1_LEVEL_43 = 11 | Level 4.3.|
| AV1_LEVEL_50 = 12 | Level 5.0.|
| AV1_LEVEL_51 = 13 | Level 5.1.|
| AV1_LEVEL_52 = 14 | Level 5.2.|
| AV1_LEVEL_53 = 15 | Level 5.3.|
| AV1_LEVEL_60 = 16 | Level 6.0.|
| AV1_LEVEL_61 = 17 | Level 6.1.|
| AV1_LEVEL_62 = 18 | Level 6.2.|
| AV1_LEVEL_63 = 19 | Level 6.3.|
| AV1_LEVEL_70 = 20 | Level 7.0.|
| AV1_LEVEL_71 = 21 | Level 7.1.|
| AV1_LEVEL_72 = 22 | Level 7.2.|
| AV1_LEVEL_73 = 23 | Level 7.3.|

### OH_VP9Level

```c
enum OH_VP9Level
```

**Description**

VP9 level.

**Since**: 23

| Value| Description|
| -- | -- |
| VP9_LEVEL_1 = 0 | Level 1.|
| VP9_LEVEL_11 = 1 | Level 1.1.|
| VP9_LEVEL_2 = 2 | Level 2.|
| VP9_LEVEL_21 = 3 | Level 2.1.|
| VP9_LEVEL_3 = 4 | Level 3.|
| VP9_LEVEL_31 = 5 | Level 3.1.|
| VP9_LEVEL_4 = 6 | Level 4.|
| VP9_LEVEL_41 = 7 | Level 4.1.|
| VP9_LEVEL_5 = 8 | Level 5.|
| VP9_LEVEL_51 = 9 | Level 5.1.|
| VP9_LEVEL_52 = 10 | Level 5.2.|
| VP9_LEVEL_6 = 11 | Level 6.|
| VP9_LEVEL_61 = 12 | Level 6.1.|
| VP9_LEVEL_62 = 13 | Level 6.2.|

### OH_WVC1Level

```c
enum OH_WVC1Level
```

**Description**

WVC1 level.

**Since**: 23

| Value| Description|
| -- | -- |
| WVC1_LEVEL_L0 = 0 | Level L0.|
| WVC1_LEVEL_L1 = 1 | Level L1.|
| WVC1_LEVEL_L2 = 2 | Level L2.|
| WVC1_LEVEL_L3 = 3 | Level L3.|
| WVC1_LEVEL_L4 = 4 | Level L4.|

### OH_WMV3Level

```c
enum OH_WMV3Level
```

**Description**

Enumerates the WMV3 levels.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 22

| Value| Description|
| -- | -- |
| WMV3_LEVEL_LOW = 0 | Low level.|
| WMV3_LEVEL_MEDIUM = 1 | Medium level.|
| WMV3_LEVEL_HIGH = 2 | High level.|

### OH_TemporalGopReferenceMode

```c
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

```c
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
| BITRATE_MODE_CBR_HIGH_QUALITY = 4 | High-quality constant bit rate. It is supported only for H.265 (HEVC).<br>**Since**: 26.0.0|

### OH_FrameRetentionMode

```c
enum OH_FrameRetentionMode
```

**Description**

Enumerates the frame retention modes of video decoding.

**Since**: 26.0.0

| Value| Description|
| -- | -- |
| OH_FRAME_RETENTION_MODE_FULL = 0 | Full retention mode.<br>The decoder operates in a transparent passthrough state, retaining 100% of all input frames. In this mode, the frame-skipping function is essentially disabled. All underlying visual perception algorithms are completely bypassed, achieving zero algorithm overhead.<br>**Since**: 26.0.0|
| OH_FRAME_RETENTION_MODE_ADAPTIVE = 1 | Perceptual adaptive retention mode.<br>The decoder dynamically analyzes video characteristics and preferentially drops frames that have the least impact on visual perception. This minimizes playback experience degradation while maintaining visual smoothness. For optimal algorithmic accuracy, it is highly recommended that you explicitly configure the current playback speed via the OH_MD_KEY_VIDEO_DECODER_SPEED [variable](#variables).<br>**Since**: 26.0.0|
| OH_FRAME_RETENTION_MODE_UNIFORM = 2 | Smooth fixed-ratio retention mode.<br>Video frames are evenly retained according to the user-configured retention ratio (set via the OH_MD_KEY_VIDEO_DECODER_FRAME_RETENTION_RATIO [variable](#variables)). If the retention ratio is not explicitly configured, the decoder defaults to limiting the output to a maximum of 30 fps.<br>**Since**: 26.0.0|

### OH_AudioEncoderPTSMode

```c
enum OH_AudioEncoderPTSMode
```

**Description**

Enumerates the PTS modes of an audio encoder.

**Since**: 26.0.0

| Value| Description|
| -- | -- |
| OH_AUDIO_ENCODER_PTS_MODE_DEFAULT = 0 | Default PTS mode of an audio encoder. Different encoders may have different behaviors.<br>**Since**: 26.0.0|
| OH_AUDIO_ENCODER_PTS_MODE_ZERO_START = 1 | PTS mode with **0** as the starting point.<br>**Since**: 26.0.0|
| OH_AUDIO_ENCODER_PTS_MODE_FIRST_INPUT_START = 2 | PTS mode with the PTS of the first input frame as the starting point.<br>**Since**: 26.0.0|


## Function Description

### OH_AVCodecOnError()

```c
typedef void (*OH_AVCodecOnError)(OH_AVCodec *codec, int32_t errorCode, void *userData)
```

**Description**

Defines the pointer to the function that is called to report error information when an error occurs during the running of an OH_AVCodec instance.

| Use Case| Error Code|
| -------- | -------- |
| Audio encoding/decoding| **AV_ERR_DRM_DECRYPT_FAILED**: DRM decryption failed. |
| Video encoding/decoding| **AV_ERR_NO_MEMORY**: System resources are insufficient.<br>**AV_ERR_UNKNOWN**: An unknown error occurs. Analyze the error based on specific logs.<br>**AV_ERR_SERVICE_DIED**: The service is dead. |
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

```c
typedef void (*OH_AVCodecOnStreamChanged)(OH_AVCodec *codec, OH_AVFormat *format, void *userData)
```

**Description**

Defines the pointer to the function that is called to report the new stream description when the resolution of the input video stream being decoded or the output video stream that has been encoded changes.<br> Starting from API version 15, this function pointer is called to report the new stream description when the stream sampling rate, number of audio channels, or audio sampling format changes during audio decoding. The decoding formats that can detect these changes include <!--RP3--><!--RP3End-->AAC, FLAC, MP3, and VORBIS.<br> Note that the lifecycle of the pointer to the OH_AVFormat instance is valid only when the function pointer is being called. Do not access the pointer to the instance after the function pointer is called.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to an OH_AVCodec instance.|
| [OH_AVFormat](capi-core-oh-avformat.md) *format | Pointer to the description information about the new output stream.|
|  void *userData | Pointer to the data on which the caller depends when executing the callback.|

### OH_AVCodecOnNeedInputData()

```c
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
|  [OH_AVMemory](capi-core-oh-avmemory.md) *data | Pointer to the data to fill in the new input buffer.|
|  void *userData | Pointer to the data on which the caller depends when executing the callback.|

### OH_AVCodecOnNewOutputData()

```c
typedef void (*OH_AVCodecOnNewOutputData)(OH_AVCodec *codec, uint32_t index, OH_AVMemory *data, OH_AVCodecBufferAttr *attr, void *userData)
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
|  [OH_AVMemory](capi-core-oh-avmemory.md) *data | Pointer to the data filled in the new output buffer.|
| [OH_AVCodecBufferAttr](capi-core-oh-avcodecbufferattr.md) *attr | Pointer to the description information about the new output buffer.|
|  void *userData | Pointer to the data on which the caller depends when executing the callback.|

### OH_AVCodecOnNeedInputBuffer()

```c
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
|  [OH_AVBuffer](capi-core-oh-avbuffer.md) *buffer | Pointer to the data to fill in the new input buffer.|
|  void *userData | Pointer to the data on which the caller depends when executing the callback.|

### OH_AVCodecOnNewOutputBuffer()

```c
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
|  [OH_AVBuffer](capi-core-oh-avbuffer.md) *buffer | Pointer to the data filled in the new output buffer.|
|  void *userData | Pointer to the data on which the caller depends when executing the callback.|

### OH_AVDataSourceReadAt()

```c
typedef int32_t (*OH_AVDataSourceReadAt)(OH_AVBuffer *data, int32_t length, int64_t pos)
```

**Description**

Defines a function pointer used to provide the capability of obtaining user-defined media data.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) *data | Pointer to the buffer to be filled in.|
|  int32_t length | Length of the data to read, in bytes.|
|  int64_t pos | Offset from which to read, in bytes.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Actual length of the data read to the buffer.|

### OH_AVDataSourceReadAtExt()

```c
typedef int32_t (*OH_AVDataSourceReadAtExt)(OH_AVBuffer *data, int32_t length, int64_t pos, void *userData)
```

**Description**

Defines a function pointer used to provide the capability of obtaining user-defined media data.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) *data | Pointer to the buffer to be filled in.|
|  int32_t length | Length of the data to read, in bytes.|
|  int64_t pos | Offset from which to read, in bytes.|
|  void *userData | Pointer to user-defined data.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Actual length of the data read to the buffer.|
