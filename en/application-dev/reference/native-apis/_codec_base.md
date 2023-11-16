# CodecBase


## Overview

The **CodecBase** module provides the common structs, character constants, and enums for running **OH_AVCodec** instances. This module may not be supported on some devices. You can call [CanIUse](../syscap.md) to check whether your device supports this module.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Since**

9


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [native_avcodec_base.h](native__avcodec__base_8h.md) | Declares the common structs, character constants, and enums for running **OH_AVCodec** instances.<br>**File to include**: <multimedia/player_framework/native_avcodec_base.h><br>**Library**: libnative_media_codecbase.so| 


### Structs

| Name| Description| 
| -------- | -------- |
| [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) | Defines the description information about the buffer of an **OH_AVCodec** instance.| 
| [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) | Defines all the asynchronous callback function pointers of an **OH_AVCodec** instance.| 


### Types

| Name| Description| 
| -------- | -------- |
| [OH_AVCodecBufferFlags](#oh_avcodecbufferflags) | Defines an enum that enumerates the flags for the buffer of an **OH_AVCodec** instance.| 
| [OH_AVOutputFormat](#oh_avoutputformat) | Defines an enum that enumerates the output file formats of a muxer.| 
| [OH_AVCodecBufferAttr](#oh_avcodecbufferattr) | Defines a struct for the description information about the buffer of an **OH_AVCodec** instance.| 
| (\*[OH_AVCodecOnError](#oh_avcodeconerror)) (OH_AVCodec \*codec, int32_t errorCode, void \*userData) | Defines the pointer to the function that is called to report error information when an error occurs during the running of an **OH_AVCodec** instance.| 
| (\*[OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged)) (OH_AVCodec \*codec, OH_AVFormat \*format, void \*userData) | Defines the pointer to the function that is called to report the new stream description when the output stream changes.| 
| (\*[OH_AVCodecOnNeedInputData](#oh_avcodeconneedinputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, void \*userData) | Defines the pointer to the function that is called when new input data is required during the running of an **OH_AVCodec** instance. The function carries a buffer to fill in new input data.| 
| (\*[OH_AVCodecOnNewOutputData](#oh_avcodeconnewoutputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr, void \*userData) | Defines the pointer to the function that is called when new output data is generated during the running of an **OH_AVCodec** instance. The function carries a buffer filled with new output data.| 
| [OH_AVCodecAsyncCallback](#oh_avcodecasynccallback) | Defines a struct for all the asynchronous callback function pointers of an **OH_AVCodec** instance.| 
| [OH_MediaType](#oh_mediatype) | Defines an enum that enumerates the media types.| 
| [OH_AVCProfile](#oh_avcprofile) | Defines an enum that enumerates the Advanced Video Coding (AVC) profiles.| 
| [OH_HEVCProfile](#oh_hevcprofile) | Defines an enum that enumerates the High Efficiency Video Coding (HEVC) profiles.| 
| [OH_AACProfile](#oh_aacprofile) | Defines an enum that enumerates the Advanced Audio Coding (AAC) profiles.| 
| [OH_AVSeekMode](#oh_avseekmode) | Defines an enum that enumerates the seek modes.| 
| [OH_ColorPrimary](#oh_colorprimary) | Defines an enum that enumerates the primary colors.| 
| [OH_TransferCharacteristic](#oh_transfercharacteristic) | Defines an enum that enumerates the transfer characteristics.| 
| [OH_MatrixCoefficient](#oh_matrixcoefficient) | Defines an enum that enumerates the matrix coefficients.| 
| [OH_BitsPerSample](#oh_bitspersample) | Defines an enum that enumerates the number of audio bits for each coded sample.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_AVCodecBufferFlags](#oh_avcodecbufferflags) {<br>&nbsp;&nbsp;&nbsp;&nbsp;**AVCODEC_BUFFER_FLAGS_NONE** = 0,<br>&nbsp;&nbsp;&nbsp;&nbsp;**AVCODEC_BUFFER_FLAGS_EOS** = 1 &lt;&lt; 0,<br>&nbsp;&nbsp;&nbsp;&nbsp;**AVCODEC_BUFFER_FLAGS_SYNC_FRAME** = 1 &lt;&lt; 1,<br>&nbsp;&nbsp;&nbsp;&nbsp;**AVCODEC_BUFFER_FLAGS_INCOMPLETE_FRAME** = 1 &lt;&lt; 2,<br>&nbsp;&nbsp;&nbsp;&nbsp;**AVCODEC_BUFFER_FLAGS_CODEC_DATA** = 1 &lt;&lt; 3<br>} | Enumerates the flags for the buffer of an **OH_AVCodec** instance.| 
| [OH_AVOutputFormat](#oh_avoutputformat) {<br>&nbsp;&nbsp;&nbsp;&nbsp;**AV_OUTPUT_FORMAT_DEFAULT** = 0,<br>&nbsp;&nbsp;&nbsp;&nbsp;**AV_OUTPUT_FORMAT_MPEG_4** = 2,<br>&nbsp;&nbsp;&nbsp;&nbsp;**AV_OUTPUT_FORMAT_M4A** = 6<br>} | Enumerates the output file formats of a muxer.| 
| [OH_MediaType](#oh_mediatype) {<br>&nbsp;&nbsp;&nbsp;&nbsp;**MEDIA_TYPE_AUD** = 0,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MEDIA_TYPE_VID** = 1<br>} | Enumerates the media types.| 
| [OH_AVCProfile](#oh_avcprofile) {<br>&nbsp;&nbsp;&nbsp;&nbsp;**AVC_PROFILE_BASELINE** = 0,<br>&nbsp;&nbsp;&nbsp;&nbsp;**AVC_PROFILE_HIGH** = 4,<br>&nbsp;&nbsp;&nbsp;&nbsp;**AVC_PROFILE_MAIN** = 8<br>} | Enumerates the AVC profiles.| 
| [OH_HEVCProfile](#oh_hevcprofile) {<br>&nbsp;&nbsp;&nbsp;&nbsp;**HEVC_PROFILE_MAIN** = 0,<br>&nbsp;&nbsp;&nbsp;&nbsp;**HEVC_PROFILE_MAIN_10** = 1,<br>&nbsp;&nbsp;&nbsp;&nbsp;**HEVC_PROFILE_MAIN_STILL** = 2,<br>&nbsp;&nbsp;&nbsp;&nbsp;**HEVC_PROFILE_MAIN_10_HDR10** = 3,<br>&nbsp;&nbsp;&nbsp;&nbsp;**HEVC_PROFILE_MAIN_10_HDR10_PLUS** = 4<br>} | Enumerates the HEVC profiles.| 
| [OH_AACProfile](#oh_aacprofile) {<br>&nbsp;&nbsp;&nbsp;&nbsp;**AAC_PROFILE_LC** = 0<br>} | Enumerates the AAC profiles.| 
| [OH_AVSeekMode](#oh_avseekmode) {<br>&nbsp;&nbsp;&nbsp;&nbsp;**SEEK_MODE_NEXT_SYNC** = 0,<br>&nbsp;&nbsp;&nbsp;&nbsp;**SEEK_MODE_PREVIOUS_SYNC**,<br>&nbsp;&nbsp;&nbsp;&nbsp;**SEEK_MODE_CLOSEST_SYNC**<br>} | Enumerates the seek modes.| 
| [OH_ColorPrimary](#oh_colorprimary) {<br>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_BT709** = 1,<br>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_UNSPECIFIED** = 2,<br>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_BT470_M** = 4,<br>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_BT601_625** = 5,<br>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_BT601_525** = 6,<br>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_SMPTE_ST240** = 7,<br>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_GENERIC_FILM** = 8,<br>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_BT2020** = 9,<br>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_SMPTE_ST428** = 10,<br>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_P3DCI** = 11,<br>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_P3D65** = 12<br>} | Enumerates the primary colors.| 
| [OH_TransferCharacteristic](#oh_transfercharacteristic) {<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_BT709** = 1,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_UNSPECIFIED** = 2,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_GAMMA_2_2** = 4,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_GAMMA_2_8** = 5,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_BT601** = 6,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_SMPTE_ST240** = 7,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_LINEAR** = 8,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_LOG** = 9,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_LOG_SQRT** = 10,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_IEC_61966_2_4** = 11,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_BT1361** = 12,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_IEC_61966_2_1** = 13,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_BT2020_10BIT** = 14,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_BT2020_12BIT** = 15,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_PQ** = 16,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_SMPTE_ST428** = 17,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_HLG** = 18<br>} | Enumerates the transfer characteristics.| 
| [OH_MatrixCoefficient](#oh_matrixcoefficient) {<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_IDENTITY** = 0,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_BT709** = 1,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_UNSPECIFIED** = 2,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_FCC** = 4,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_BT601_625** = 5,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_BT601_525** = 6,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_SMPTE_ST240** = 7,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_YCGCO** = 8,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_BT2020_NCL** = 9,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_BT2020_CL** = 10,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_SMPTE_ST2085** = 11,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_CHROMATICITY_NCL** = 12,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_CHROMATICITY_CL** = 13,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_ICTCP** = 14<br>} | Enumerates the matrix coefficients.| 
| [OH_BitsPerSample](#oh_bitspersample) {<br>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_U8** = 0,<br>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_S16LE** = 1,<br>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_S24LE** = 2,<br>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_S32LE** = 3,<br>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_F32LE** = 4,<br>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_U8P** = 5,<br>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_S16P** = 6,<br>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_S24P** = 7,<br>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_S32P** = 8,<br>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_F32P** = 9,<br>&nbsp;&nbsp;&nbsp;&nbsp;**INVALID_WIDTH** = -1<br>} | Enumerates the number of audio bits for each coded sample.| 


### Variables

| Name| Description| 
| -------- | -------- |
| [OH_AVCodecBufferAttr::pts](_o_h___a_v_codec_buffer_attr.md#pts) | Defines the display timestamp of the buffer, in microseconds.| 
| [OH_AVCodecBufferAttr::size](_o_h___a_v_codec_buffer_attr.md#size) | Defines the size of data contained in the buffer, in bytes.| 
| [OH_AVCodecBufferAttr::offset](_o_h___a_v_codec_buffer_attr.md#offset) | Defines the offset of valid data in the buffer.| 
| [OH_AVCodecBufferAttr::flags](_o_h___a_v_codec_buffer_attr.md#flags) | Defines the flags of the buffer. It is a combination of multiple [OH_AVCodecBufferFlags](#oh_avcodecbufferflags).| 
| [OH_AVCodecAsyncCallback::onError](_o_h___a_v_codec_async_callback.md#onerror) | Defines the callback used to report a codec operation error. For details, see [OH_AVCodecOnError](#oh_avcodeconerror).| 
| [OH_AVCodecAsyncCallback::onStreamChanged](_o_h___a_v_codec_async_callback.md#onstreamchanged) | Defines the callback used to report a codec stream change. For details, see [OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged).| 
| [OH_AVCodecAsyncCallback::onNeedInputData](_o_h___a_v_codec_async_callback.md#onneedinputdata) | Defines the callback used to report input data required. For details, see [OH_AVCodecOnNeedInputData](#oh_avcodeconneedinputdata).| 
| [OH_AVCodecAsyncCallback::onNeedOutputData](_o_h___a_v_codec_async_callback.md#onneedinputdata) | Defines the callback used to report output data generated. For details, see [OH_AVCodecOnNewOutputData](#oh_avcodeconnewoutputdata).| 
| \*[OH_AVCODEC_MIMETYPE_VIDEO_AVC](#oh_avcodec_mimetype_video_avc) | Defines the pointer to the Multipurpose Internet Mail Extension (MIME) type for AVC video codec.| 
| \*[OH_AVCODEC_MIMETYPE_AUDIO_AAC](#oh_avcodec_mimetype_audio_aac) | Defines the pointer to the MIME type for AAC audio codec.| 
| \*[OH_AVCODEC_MIMETYPE_VIDEO_MPEG4](#oh_avcodec_mimetype_video_mpeg4) | Defines the pointer to the MIME type for MPEG4 video codec.| 
| \*[OH_AVCODEC_MIMETYPE_VIDEO_HEVC](#oh_avcodec_mimetype_video_hevc) | Defines the pointer to the MIME type for HEVC video codec.| 
| \*[OH_AVCODEC_MIMETYPE_AUDIO_MPEG](#oh_avcodec_mimetype_audio_mpeg) | Defines the pointer to the MIME type for MPEG audio codec.| 
| \*[OH_AVCODEC_MIMETYPE_IMAGE_JPG](#oh_avcodec_mimetype_image_jpg) | Defines the pointer to the MIME type for JPG image codec.| 
| \*[OH_AVCODEC_MIMETYPE_IMAGE_PNG](#oh_avcodec_mimetype_image_png) | Defines the pointer to the MIME type for PNG image codec.| 
| \*[OH_AVCODEC_MIMETYPE_IMAGE_BMP](#oh_avcodec_mimetype_image_bmp) | Defines the pointer to the MIME type for BMP image codec.| 
| \*[OH_AVCODEC_MIMETYPE_AUDIO_FLAC](#oh_avcodec_mimetype_audio_flac) | Defines the pointer to the MIME type for FLAC audio codec.| 
| \*[OH_AVCODEC_MIMETYPE_AUDIO_VORBIS](#oh_avcodec_mimetype_audio_vorbis) | Defines the pointer to the MIME type for VORBIS audio codec.| 
| \*[OH_ED_KEY_TIME_STAMP](#oh_ed_key_time_stamp) | Defines the pointer to the timestamp in the extra data of the surface. The value type is int64.| 
| \*[OH_ED_KEY_EOS](#oh_ed_key_eos) | Defines the pointer to the end of stream (EOS) in the extra data of the surface. The value type is Boolean.| 
| \*[OH_MD_KEY_TRACK_TYPE](#oh_md_key_track_type) | Defines the pointer to a container for storing media descriptions.| 
| \*[OH_MD_KEY_CODEC_MIME](#oh_md_key_codec_mime) | Define the pointer to the MIME type of codec. The value is a string.| 
| \*[OH_MD_KEY_DURATION](#oh_md_key_duration) | Defines the pointer to the duration. The value type is int64_t.| 
| \*[OH_MD_KEY_BITRATE](#oh_md_key_bitrate) | Defines the pointer to the bit rate. The value type is uint32_t. In the case of video encoding, you must set [OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE](#oh_md_key_video_encode_bitrate_mode), which specifies the bit rate.| 
| \*[OH_MD_KEY_MAX_INPUT_SIZE](#oh_md_key_max_input_size) | Defines the pointer to the maximum input size. The value type is uint32_t.| 
| \*[OH_MD_KEY_WIDTH](#oh_md_key_width) | Defines the pointer to the video width. The value type is uint32_t.| 
| \*[OH_MD_KEY_HEIGHT](#oh_md_key_height) | Defines the pointer to the video height. The value type is uint32_t.| 
| \*[OH_MD_KEY_PIXEL_FORMAT](#oh_md_key_pixel_format) | Defines the pointer to the video pixel format. The value type is int32_t. For details, see [OH_AVPixelFormat](_core.md#oh_avpixelformat).| 
| \*[OH_MD_KEY_RANGE_FLAG](#oh_md_key_range_flag) | Defines the pointer to the video YUV value range flag. The value type is Boolean.| 
| \*[OH_MD_KEY_COLOR_PRIMARIES](#oh_md_key_color_primaries) | Defines the pointer to the primary color of the video. The value type is int32_t.| 
| \*[OH_MD_KEY_TRANSFER_CHARACTERISTICS](#oh_md_key_transfer_characteristics) | Defines the pointer to the video transfer characteristics. The value type is int32_t.| 
| \*[OH_MD_KEY_MATRIX_COEFFICIENTS](#oh_md_key_matrix_coefficients) | Defines the pointer to the video matrix coefficient. The value type is int32_t.| 
| \*[OH_MD_KEY_AUDIO_SAMPLE_FORMAT](#oh_md_key_audio_sample_format) | Defines the pointer to the original audio format. The value type is uint32_t.| 
| \*[OH_MD_KEY_FRAME_RATE](#oh_md_key_frame_rate) | Defines the pointer to the video frame rate. The value is a double-precision floating point number.| 
| \*[OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE](#oh_md_key_video_encode_bitrate_mode) | Defines the pointer to the video encoding bit rate mode. The value type is int32_t. For details, see [OH_VideoEncodeBitrateMode](_video_encoder.md#oh_videoencodebitratemode).| 
| \*[OH_MD_KEY_PROFILE](#oh_md_key_profile) | Defines the pointer to the encoding template. The value is a number. For details, see [OH_AVCProfile](#oh_avcprofile), [OH_AACProfile](#oh_aacprofile), or [OH_HEVCProfile](#oh_hevcprofile).| 
| \*[OH_MD_KEY_AUD_CHANNEL_COUNT](#oh_md_key_aud_channel_count) | Defines the pointer to the number of audio channels. The value type is uint32_t.| 
| \*[OH_MD_KEY_AUD_SAMPLE_RATE](#oh_md_key_aud_sample_rate) | Defines the pointer to the audio sampling rate. The value type is uint32_t.| 
| \*[OH_MD_KEY_I_FRAME_INTERVAL](#oh_md_key_i_frame_interval) | Defines the pointer to the key frame interval, in milliseconds. The value type is int32_t.| 
| \*[OH_MD_KEY_ROTATION](#oh_md_key_rotation) | Defines the pointer to the rotation angle of the surface. The value type is int32_t, and the value range is {0, 90, 180, 270}. The default value is 0.| 
| \*[OH_MD_KEY_CODEC_CONFIG](#oh_md_key_codec_config) | Defines the pointer to the codec-specific data. The value type is uint8_t\*.| 
| \*[OH_MD_KEY_REQUEST_I_FRAME](#oh_md_key_request_i_frame) | Defines the pointer to the request for immediate encoding of I-frames. The value type is Boolean.| 
| \*[OH_MD_KEY_QUALITY](#oh_md_key_quality) | Defines the pointer to the required encoding quality. The value type is uint32_t. This key applies only to encoders configured in constant quality mode.| 
| \*[OH_MD_KEY_CHANNEL_LAYOUT](#oh_md_key_channel_layout) | Defines the pointer to the required encoding channel layout. The value type is int64_t. This key applies only to encoders.| 
| \*[OH_MD_KEY_BITS_PER_CODED_SAMPLE](#oh_md_key_bits_per_coded_sample) | Defines the pointer to the number of bits for each coded sample. The value type is uint32_t. This key applies to FLAC encoders. For details, see [OH_BitsPerSample](#oh_bitspersample).| 
| \*[OH_MD_KEY_AAC_IS_ADTS](#oh_md_key_aac_is_adts) | Defines the pointer to the AAC format. The value type is uint32_t. This key applies to AAC decoders.| 
| \*[OH_MD_KEY_SBR](#oh_md_key_sbr) | Defines the pointer to the AAC SBR format. The value type is uint32_t. This key applies to AAC encoders.| 
| \*[OH_MD_KEY_COMPLIANCE_LEVEL](#oh_md_key_compliance_level) | Defines the pointer to the FLAC compliance level. The value type is int32_t.| 
| \*[OH_MD_KEY_IDENTIFICATION_HEADER](#oh_md_key_identification_header) | Defines the pointer to the VORBIS identification header. The value type is uint8_t\*. This key applies only to VORBIS decoders.| 
| \*[OH_MD_KEY_SETUP_HEADER](#oh_md_key_setup_header) | Defines the pointer to the VORBIS setup header. The value type is uint8_t\*. This key applies only to VORBIS decoders.| 
| \*[OH_MD_KEY_TITLE](#oh_md_key_title) | Defines the pointer to the title of the input media. The value is a string.| 
| \*[OH_MD_KEY_ARTIST](#oh_md_key_artist) | Defines the pointer to the artist of the input media. The value is a string.| 
| \*[OH_MD_KEY_ALBUM](#oh_md_key_album) | Defines the pointer to the album of the input media. The value is a string.| 
| \*[OH_MD_KEY_ALBUM_ARTIST](#oh_md_key_album_artist) | Defines the pointer to the album_artist of the input media. The value is a string.| 
| \*[OH_MD_KEY_DATE](#oh_md_key_date) | Defines the pointer to the date of the input media. The value is a string.| 
| \*[OH_MD_KEY_COMMENT](#oh_md_key_comment) | Defines the pointer to the comment of the input media. The value is a string.| 
| \*[OH_MD_KEY_GENRE](#oh_md_key_genre) | Defines the pointer to the genre of the input media. The value is a string.| 
| \*[OH_MD_KEY_COPYRIGHT](#oh_md_key_copyright) | Defines the pointer to the copyright of the input media. The value is a string.| 
| \*[OH_MD_KEY_LANGUAGE](#oh_md_key_language) | Defines the pointer to the language of the input media. The value is a string.| 
| \*[OH_MD_KEY_DESCRIPTION](#oh_md_key_description) | Defines the pointer to the description of the input media. The value is a string.| 
| \*[OH_MD_KEY_LYRICS](#oh_md_key_lyrics) | Defines the pointer to the lyrics of the input media. The value is a string.| 
| \*[OH_MD_KEY_TRACK_COUNT](#oh_md_key_track_count) | Defines the pointer to the track count of the input media. The value type is uint32_t.| 


## Type Description


### OH_AACProfile

  
```
typedef enum OH_AACProfile OH_AACProfile
```

**Description**

Defines an enum that enumerates the AAC profiles.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCodecAsyncCallback

  
```
typedef struct OH_AVCodecAsyncCallback OH_AVCodecAsyncCallback
```

**Description**

Defines a struct for all the asynchronous callback function pointers of an **OH_AVCodec** instance. To ensure the normal running of **OH_AVCodec**, you must register the instance of this struct with the **OH_AVCodec** instance and process the information reported by the callback function.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| [onError](_o_h___a_v_codec_async_callback.md#onerror) | Callback used to report a codec operation error. For details, see [OH_AVCodecOnError](#oh_avcodeconerror).| 
| [onStreamChanged](_o_h___a_v_codec_async_callback.md#onstreamchanged) | Callback used to report a codec stream change. For details, see [OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged).| 
| [onNeedInputData](_o_h___a_v_codec_async_callback.md#onneedinputdata) | Callback used to report input data required. For details, see [OH_AVCodecOnNeedInputData](#oh_avcodeconneedinputdata).| 
| [onNeedOutputData](_o_h___a_v_codec_async_callback.md#onneedoutputdata) | Callback used to report output data generated. For details, see [OH_AVCodecOnNewOutputData](#oh_avcodeconnewoutputdata).| 


### OH_AVCodecBufferAttr

  
```
typedef struct OH_AVCodecBufferAttr OH_AVCodecBufferAttr
```

**Description**

Defines a struct for the description information about the buffer of an **OH_AVCodec** instance.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCodecBufferFlags

  
```
typedef enum OH_AVCodecBufferFlags OH_AVCodecBufferFlags
```

**Description**

Defines an enum that enumerates the flags for the buffer of an **OH_AVCodec** instance.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCodecOnError

  
```
typedef void (*OH_AVCodecOnError) (OH_AVCodec *codec, int32_t errorCode, void *userData)
```

**Description**

Defines the pointer to the function that is called to report error information when an error occurs during the running of an **OH_AVCodec** instance.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| codec | Pointer to an **OH_AVCodec** instance.| 
| errorCode | Error code.| 
| userData | Pointer to user-specific data.| 


### OH_AVCodecOnNeedInputData

  
```
typedef void (*OH_AVCodecOnNeedInputData) (OH_AVCodec *codec, uint32_t index, OH_AVMemory *data, void *userData)
```

**Description**

Defines the pointer to the function that is called when new input data is required during the running of an **OH_AVCodec** instance. The function carries a buffer to fill in new input data.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| codec | Pointer to an **OH_AVCodec** instance.| 
| index | Index of the new input buffer.| 
| data | Pointer to the data to fill in the new input buffer.| 
| userData | Pointer to user-specific data.| 


### OH_AVCodecOnNewOutputData

  
```
typedef void (*OH_AVCodecOnNewOutputData) (OH_AVCodec *codec, uint32_t index, OH_AVMemory *data, OH_AVCodecBufferAttr *attr, void *userData)
```

**Description**

Defines the pointer to the function that is called when new output data is generated during the running of an **OH_AVCodec** instance. The function carries a buffer filled with new output data. Note that the lifecycle of the pointer to the **OH_AVCodecBufferAttr** instance is valid only when the function pointer is being called. Do not access the pointer to the instance after the function pointer is called.

\@syscap SystemCapability.Multimedia.Media.CodecBase

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
typedef void (*OH_AVCodecOnStreamChanged) (OH_AVCodec *codec, OH_AVFormat *format, void *userData)
```

**Description**

Defines the pointer to the function that is called to report the new stream description when the output stream changes. Note that the lifecycle of the pointer to the **OH_AVFormat** instance is valid only when the function pointer is being called. Do not access the pointer to the instance after the function pointer is called.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

| Name| Description| 
| -------- | -------- |
| codec | Pointer to an **OH_AVCodec** instance.| 
| format | Pointer to the description information about the new output stream.| 
| userData | Pointer to user-specific data.| 

**format** carries the following fields:
| Key                    | Description            |
| ---------------------- | ---------------  |
| OH_MD_KEY_WIDTH        | Video output width.    |
| OH_MD_KEY_HEIGHT       | Video output height.    |
| OH_MD_KEY_PIXEL_FORMAT | Video output pixel format.|

### OH_AVCProfile

  
```
typedef enum OH_AVCProfile OH_AVCProfile
```

**Description**

Defines an enum that enumerates the AVC profiles.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVOutputFormat

  
```
typedef enum OH_AVOutputFormat OH_AVOutputFormat
```

**Description**

Defines an enum that enumerates the output file formats of a muxer.


### OH_AVSeekMode

  
```
typedef enum OH_AVSeekMode OH_AVSeekMode
```

**Description**

Defines an enum that enumerates the seek modes.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_BitsPerSample

  
```
typedef enum OH_BitsPerSample OH_BitsPerSample
```

**Description**

Defines an enum that enumerates the number of audio bits for each coded sample.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_ColorPrimary

  
```
typedef enum OH_ColorPrimary OH_ColorPrimary
```

**Description**

Defines an enum that enumerates the primary colors.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_HEVCProfile

  
```
typedef enum OH_HEVCProfile OH_HEVCProfile
```

**Description**

Defines an enum that enumerates the HEVC profiles.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MatrixCoefficient

  
```
typedef enum OH_MatrixCoefficient OH_MatrixCoefficient
```

**Description**

Defines an enum that enumerates the matrix coefficients.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MediaType

  
```
typedef enum OH_MediaType OH_MediaType
```

**Description**

Defines an enum that enumerates the media types.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_TransferCharacteristic

  
```
typedef enum OH_TransferCharacteristic OH_TransferCharacteristic
```

**Description**

Defines an enum that enumerates the transfer characteristics.

\@syscap SystemCapability.Multimedia.Media.CodecBase


## Enum Description


### OH_AACProfile

  
```
enum OH_AACProfile
```

**Description**

Enumerates the AAC profiles.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCodecBufferFlags

  
```
enum OH_AVCodecBufferFlags
```

**Description**

Enumerates the flags for the buffer of an **OH_AVCodec** instance.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCProfile

  
```
enum OH_AVCProfile
```

**Description**

Enumerates the AVC profiles.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVOutputFormat

  
```
enum OH_AVOutputFormat
```

**Description**

Enumerates the output file formats of a muxer.


### OH_AVSeekMode

  
```
enum OH_AVSeekMode
```

**Description**

Enumerates the seek modes.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_BitsPerSample

  
```
enum OH_BitsPerSample
```

**Description**

Enumerates the number of audio bits for each coded sample.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_ColorPrimary

  
```
enum OH_ColorPrimary
```

**Description**

Enumerates the primary colors.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_HEVCProfile

  
```
enum OH_HEVCProfile
```

**Description**

Enumerates the HEVC profiles.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MatrixCoefficient

  
```
enum OH_MatrixCoefficient
```

**Description**

Enumerates the matrix coefficients.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MediaType

  
```
enum OH_MediaType
```

**Description**

Enumerates the media types.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_TransferCharacteristic

  
```
enum OH_TransferCharacteristic
```

**Description**

Enumerates the transfer characteristics.

\@syscap SystemCapability.Multimedia.Media.CodecBase


## Variable Description


### OH_AVCODEC_MIMETYPE_AUDIO_AAC

  
```
const char* OH_AVCODEC_MIMETYPE_AUDIO_AAC
```

**Description**

Defines the pointer to the MIME type for AAC audio codec.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCODEC_MIMETYPE_AUDIO_FLAC

  
```
const char* OH_AVCODEC_MIMETYPE_AUDIO_FLAC
```

**Description**

Defines the pointer to the MIME type for FLAC audio codec.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCODEC_MIMETYPE_AUDIO_MPEG

  
```
const char* OH_AVCODEC_MIMETYPE_AUDIO_MPEG
```

**Description**

Defines the pointer to the MIME type for MPEG audio codec.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCODEC_MIMETYPE_AUDIO_VORBIS

  
```
const char* OH_AVCODEC_MIMETYPE_AUDIO_VORBIS
```

**Description**

Defines the pointer to the MIME type for VORBIS audio codec.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCODEC_MIMETYPE_IMAGE_BMP

  
```
const char* OH_AVCODEC_MIMETYPE_IMAGE_BMP
```

**Description**

Defines the pointer to the MIME type for BMP image codec.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCODEC_MIMETYPE_IMAGE_JPG

  
```
const char* OH_AVCODEC_MIMETYPE_IMAGE_JPG
```

**Description**

Defines the pointer to the MIME type for JPG image codec.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCODEC_MIMETYPE_IMAGE_PNG

  
```
const char* OH_AVCODEC_MIMETYPE_IMAGE_PNG
```

**Description**

Defines the pointer to the MIME type for PNG image codec.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCODEC_MIMETYPE_VIDEO_AVC

  
```
const char* OH_AVCODEC_MIMETYPE_VIDEO_AVC
```

**Description**

Defines the pointer to the MIME type for AVC video codec.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCODEC_MIMETYPE_VIDEO_HEVC

  
```
const char* OH_AVCODEC_MIMETYPE_VIDEO_HEVC
```

**Description**

Defines the pointer to the MIME type for HEVC video codec.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCODEC_MIMETYPE_VIDEO_MPEG4

  
```
const char* OH_AVCODEC_MIMETYPE_VIDEO_MPEG4
```

**Description**

Defines the pointer to the MIME type for MPEG4 video codec.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_ED_KEY_EOS

  
```
const char* OH_ED_KEY_EOS
```

**Description**

Defines the pointer to the EOS in the extra data of the surface. The value type is Boolean.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_ED_KEY_TIME_STAMP

  
```
const char* OH_ED_KEY_TIME_STAMP
```

**Description**

Defines the pointer to the timestamp in the extra data of the surface. The value type is int64.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MD_KEY_AAC_IS_ADTS

  
```
const char* OH_MD_KEY_AAC_IS_ADTS
```

**Description**

Defines the pointer to the AAC format. The value type is uint32_t. This key applies to AAC decoders.


### OH_MD_KEY_ALBUM

  
```
const char* OH_MD_KEY_ALBUM
```

**Description**

Defines the pointer to the album of the input media. The value is a string.


### OH_MD_KEY_ALBUM_ARTIST

  
```
const char* OH_MD_KEY_ALBUM_ARTIST
```

**Description**

Defines the pointer to the album_artist of the input media. The value is a string.


### OH_MD_KEY_ARTIST

  
```
const char* OH_MD_KEY_ARTIST
```

**Description**

Defines the pointer to the artist of the input media. The value is a string.


### OH_MD_KEY_AUD_CHANNEL_COUNT

  
```
const char* OH_MD_KEY_AUD_CHANNEL_COUNT
```

**Description**

Defines the pointer to the number of audio channels. The value type is uint32_t.


### OH_MD_KEY_AUD_SAMPLE_RATE

  
```
const char* OH_MD_KEY_AUD_SAMPLE_RATE
```

**Description**

Defines the pointer to the audio sampling rate. The value type is uint32_t.


### OH_MD_KEY_AUDIO_SAMPLE_FORMAT

  
```
const char* OH_MD_KEY_AUDIO_SAMPLE_FORMAT
```

**Description**

Defines the pointer to the original audio format. The value type is uint32_t.


### OH_MD_KEY_BITRATE

  
```
const char* OH_MD_KEY_BITRATE
```

**Description**

Defines the pointer to the bit rate. The value type is uint32_t. In the case of video encoding, you must set [OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE](#oh_md_key_video_encode_bitrate_mode), which specifies the bit rate.


### OH_MD_KEY_BITS_PER_CODED_SAMPLE

  
```
const char* OH_MD_KEY_BITS_PER_CODED_SAMPLE
```

**Description**

Defines the pointer to the number of bits for each coded sample. The value type is uint32_t. This key applies to FLAC encoders.


### OH_MD_KEY_CHANNEL_LAYOUT

  
```
const char* OH_MD_KEY_CHANNEL_LAYOUT
```

**Description**

Defines the pointer to the required encoding channel layout. The value type is int64_t. This key applies only to encoders.


### OH_MD_KEY_CODEC_CONFIG

  
```
const char* OH_MD_KEY_CODEC_CONFIG
```

**Description**

Defines the pointer to the codec-specific data. The value type is uint8_t\*.


### OH_MD_KEY_CODEC_MIME

  
```
const char* OH_MD_KEY_CODEC_MIME
```

**Description**

Define the pointer to the MIME type of codec. The value is a string.


### OH_MD_KEY_COLOR_PRIMARIES

  
```
const char* OH_MD_KEY_COLOR_PRIMARIES
```

**Description**

Defines the pointer to the primary color of the video. The value type is int32_t.


### OH_MD_KEY_COMMENT

  
```
const char* OH_MD_KEY_COMMENT
```

**Description**

Defines the pointer to the comment of the input media. The value is a string.


### OH_MD_KEY_COMPLIANCE_LEVEL

  
```
const char* OH_MD_KEY_COMPLIANCE_LEVEL
```

**Description**

Defines the pointer to the FLAC compliance level. The value type is int32_t.


### OH_MD_KEY_COPYRIGHT

  
```
const char* OH_MD_KEY_COPYRIGHT
```

**Description**

Defines the pointer to the copyright of the input media. The value is a string.


### OH_MD_KEY_DATE

  
```
const char* OH_MD_KEY_DATE
```

**Description**

Defines the pointer to the date of the input media. The value is a string.


### OH_MD_KEY_DESCRIPTION

  
```
const char* OH_MD_KEY_DESCRIPTION
```

**Description**

Defines the pointer to the description of the input media. The value is a string.


### OH_MD_KEY_DURATION

  
```
const char* OH_MD_KEY_DURATION
```

**Description**

Defines the pointer to the duration. The value type is int64_t.


### OH_MD_KEY_FRAME_RATE

  
```
const char* OH_MD_KEY_FRAME_RATE
```

**Description**

Defines the pointer to the video frame rate. The value is a double-precision floating point number.


### OH_MD_KEY_GENRE

  
```
const char* OH_MD_KEY_GENRE
```

**Description**

Defines the pointer to the genre of the input media. The value is a string.


### OH_MD_KEY_HEIGHT

  
```
const char* OH_MD_KEY_HEIGHT
```

**Description**

Defines the pointer to the video height. The value type is uint32_t.


### OH_MD_KEY_I_FRAME_INTERVAL

  
```
const char* OH_MD_KEY_I_FRAME_INTERVAL
```

**Description**

Defines the pointer to the key frame interval, in milliseconds. The value type is int32_t.


### OH_MD_KEY_IDENTIFICATION_HEADER

  
```
const char* OH_MD_KEY_IDENTIFICATION_HEADER
```

**Description**

Defines the pointer to the VORBIS identification header. The value type is uint8_t\*. This key applies only to VORBIS decoders.


### OH_MD_KEY_LANGUAGE

  
```
const char* OH_MD_KEY_LANGUAGE
```

**Description**

Defines the pointer to the language of the input media. The value is a string.


### OH_MD_KEY_LYRICS

  
```
const char* OH_MD_KEY_LYRICS
```

**Description**

Defines the pointer to the lyrics of the input media. The value is a string.


### OH_MD_KEY_MATRIX_COEFFICIENTS

  
```
const char* OH_MD_KEY_MATRIX_COEFFICIENTS
```

**Description**

Defines the pointer to the video matrix coefficient. The value type is int32_t.


### OH_MD_KEY_MAX_INPUT_SIZE

  
```
const char* OH_MD_KEY_MAX_INPUT_SIZE
```

**Description**

Defines the pointer to the maximum input size. The value type is uint32_t.


### OH_MD_KEY_PIXEL_FORMAT

  
```
const char* OH_MD_KEY_PIXEL_FORMAT
```

**Description**

Defines the pointer to the video pixel format. The value type is int32_t. For details, see [OH_AVPixelFormat](_core.md#oh_avpixelformat).


### OH_MD_KEY_PROFILE

  
```
const char* OH_MD_KEY_PROFILE
```

**Description**

Defines the pointer to the encoding template. The value is a number. For details, see [OH_AVCProfile](#oh_avcprofile), [OH_AACProfile](#oh_aacprofile), or [OH_HEVCProfile](#oh_hevcprofile).


### OH_MD_KEY_QUALITY

  
```
const char* OH_MD_KEY_QUALITY
```

**Description**

Defines the pointer to the required encoding quality. The value type is uint32_t. This key applies only to encoders configured in constant quality mode.


### OH_MD_KEY_RANGE_FLAG

  
```
const char* OH_MD_KEY_RANGE_FLAG
```

**Description**

Defines the pointer to the video YUV value range flag. The value type is Boolean.


### OH_MD_KEY_REQUEST_I_FRAME

  
```
const char* OH_MD_KEY_REQUEST_I_FRAME
```

**Description**

Defines the pointer to the request for immediate encoding of I-frames. The value type is Boolean.


### OH_MD_KEY_ROTATION

  
```
const char* OH_MD_KEY_ROTATION
```

**Description**

Defines the pointer to the rotation angle of the surface. The value type is int32_t, and the value range is {0, 90, 180, 270}. The default value is 0.


### OH_MD_KEY_SBR

  
```
const char* OH_MD_KEY_SBR
```

**Description**

Defines the pointer to the AAC SBR format. The value type is uint32_t. This key applies to AAC encoders.


### OH_MD_KEY_SETUP_HEADER

  
```
const char* OH_MD_KEY_SETUP_HEADER
```

**Description**

Defines the pointer to the VORBIS setup header. The value type is uint8_t\*. This key applies only to VORBIS decoders.


### OH_MD_KEY_TITLE

  
```
const char* OH_MD_KEY_TITLE
```

**Description**

Defines the pointer to the title of the input media. The value is a string.


### OH_MD_KEY_TRACK_COUNT

  
```
const char* OH_MD_KEY_TRACK_COUNT
```

**Description**

Defines the pointer to the track count of the input media. The value type is uint32_t.


### OH_MD_KEY_TRACK_TYPE

  
```
const char* OH_MD_KEY_TRACK_TYPE
```

**Description**

Defines the pointer to a container for storing media descriptions.

\@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MD_KEY_TRANSFER_CHARACTERISTICS

  
```
const char* OH_MD_KEY_TRANSFER_CHARACTERISTICS
```

**Description**

Defines the pointer to the video transfer characteristics. The value type is int32_t.


### OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE

  
```
const char* OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE
```

**Description**

Defines the pointer to the video encoding bit rate mode. The value type is int32_t. For details, see [OH_VideoEncodeBitrateMode](_video_encoder.md#oh_videoencodebitratemode).


### OH_MD_KEY_WIDTH

  
```
const char* OH_MD_KEY_WIDTH
```

**Description**

Defines the pointer to the video width. The value type is uint32_t.
