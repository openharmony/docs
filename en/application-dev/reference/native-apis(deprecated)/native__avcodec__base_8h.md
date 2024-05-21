# native_avcodec_base.h


## Overview

The **native_avcodec_base.h** file declares the common structs, character constants, and enums for running **OH_AVCodec** instances.

**Since**

9

**Related Modules**

[CodecBase](_codec_base.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) | Defines the description information about the buffer of an **OH_AVCodec** instance.| 
| [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) | Defines all the asynchronous callback function pointers of an **OH_AVCodec** instance.| 


### Types

| Name| Description| 
| -------- | -------- |
| [OH_AVCodecBufferFlags](_codec_base.md#oh_avcodecbufferflags) | Defines an enum that enumerates the flags for the buffer of an **OH_AVCodec** instance.| 
| [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat) | Defines an enum that enumerates the output file formats of a muxer.| 
| [OH_AVCodecBufferAttr](_codec_base.md#oh_avcodecbufferattr) | Defines a struct for the description information about the buffer of an **OH_AVCodec** instance.| 
| (\*[OH_AVCodecOnError](_codec_base.md#oh_avcodeconerror)) (OH_AVCodec \*codec, int32_t errorCode, void \*userData) | Defines the pointer to the function that is called to report error information when an error occurs during the running of an **OH_AVCodec** instance.| 
| (\*[OH_AVCodecOnStreamChanged](_codec_base.md#oh_avcodeconstreamchanged)) (OH_AVCodec \*codec, OH_AVFormat \*format, void \*userData) | Defines the pointer to the function that is called to report the new stream description when the output stream changes.| 
| (\*[OH_AVCodecOnNeedInputData](_codec_base.md#oh_avcodeconneedinputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, void \*userData) | Defines the pointer to the function that is called when new input data is required during the running of an **OH_AVCodec** instance. The function carries a buffer to fill in new input data.| 
| (\*[OH_AVCodecOnNewOutputData](_codec_base.md#oh_avcodeconnewoutputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr, void \*userData) | Defines the pointer to the function that is called when new output data is generated during the running of an **OH_AVCodec** instance. The function carries a buffer filled with new output data.| 
| [OH_AVCodecAsyncCallback](_codec_base.md#oh_avcodecasynccallback) | Defines a struct for all the asynchronous callback function pointers of an **OH_AVCodec** instance.| 
| [OH_MediaType](_codec_base.md#oh_mediatype) | Defines an enum that enumerates the media types.| 
| [OH_AVCProfile](_codec_base.md#oh_avcprofile) | Defines an enum that enumerates the Advanced Video Coding (AVC) profiles.| 
| [OH_HEVCProfile](_codec_base.md#oh_hevcprofile) | Defines an enum that enumerates the High Efficiency Video Coding (HEVC) profiles.| 
| [OH_AACProfile](_codec_base.md#oh_aacprofile) | Defines an enum that enumerates the Advanced Audio Coding (AAC) profiles.| 
| [OH_AVSeekMode](_codec_base.md#oh_avseekmode) | Defines an enum that enumerates the seek modes.| 
| [OH_ColorPrimary](_codec_base.md#oh_colorprimary) | Defines an enum that enumerates the primary colors.| 
| [OH_TransferCharacteristic](_codec_base.md#oh_transfercharacteristic) | Defines an enum that enumerates the transfer characteristics.| 
| [OH_MatrixCoefficient](_codec_base.md#oh_matrixcoefficient) | Defines an enum that enumerates the matrix coefficients.| 
| [OH_BitsPerSample](_codec_base.md#oh_bitspersample) | Defines an enum that enumerates the number of audio bits for each coded sample.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_AVCodecBufferFlags](_codec_base.md#oh_avcodecbufferflags) {<br>&nbsp;&nbsp;&nbsp;&nbsp;**AVCODEC_BUFFER_FLAGS_NONE** = 0,<br>&nbsp;&nbsp;&nbsp;&nbsp;**AVCODEC_BUFFER_FLAGS_EOS** = 1 &lt;&lt; 0,<br>&nbsp;&nbsp;&nbsp;&nbsp;**AVCODEC_BUFFER_FLAGS_SYNC_FRAME** = 1 &lt;&lt; 1,<br>&nbsp;&nbsp;&nbsp;&nbsp;**AVCODEC_BUFFER_FLAGS_INCOMPLETE_FRAME** = 1 &lt;&lt; 2,<br>&nbsp;&nbsp;&nbsp;&nbsp;**AVCODEC_BUFFER_FLAGS_CODEC_DATA** = 1 &lt;&lt; 3<br>} | Enumerates the flags for the buffer of an **OH_AVCodec** instance.| 
| [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat) {<br>&nbsp;&nbsp;&nbsp;&nbsp;**AV_OUTPUT_FORMAT_DEFAULT** = 0,<br>&nbsp;&nbsp;&nbsp;&nbsp;**AV_OUTPUT_FORMAT_MPEG_4** = 2,<br>&nbsp;&nbsp;&nbsp;&nbsp;**AV_OUTPUT_FORMAT_M4A** = 6<br>} | Enumerates the output file formats of a muxer.| 
| [OH_MediaType](_codec_base.md#oh_mediatype) {<br>&nbsp;&nbsp;&nbsp;&nbsp;**MEDIA_TYPE_AUD** = 0,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MEDIA_TYPE_VID** = 1<br>} | Enumerates the media types.| 
| [OH_AVCProfile](_codec_base.md#oh_avcprofile) {<br>&nbsp;&nbsp;&nbsp;&nbsp;**AVC_PROFILE_BASELINE** = 0,<br>&nbsp;&nbsp;&nbsp;&nbsp;**AVC_PROFILE_HIGH** = 4,<br>&nbsp;&nbsp;&nbsp;&nbsp;**AVC_PROFILE_MAIN** = 8<br>} | Enumerates the AVC profiles.| 
| [OH_HEVCProfile](_codec_base.md#oh_hevcprofile) {<br>&nbsp;&nbsp;&nbsp;&nbsp;**HEVC_PROFILE_MAIN** = 0,<br>&nbsp;&nbsp;&nbsp;&nbsp;**HEVC_PROFILE_MAIN_10** = 1,<br>&nbsp;&nbsp;&nbsp;&nbsp;**HEVC_PROFILE_MAIN_STILL** = 2,<br>&nbsp;&nbsp;&nbsp;&nbsp;**HEVC_PROFILE_MAIN_10_HDR10** = 3,<br>&nbsp;&nbsp;&nbsp;&nbsp;**HEVC_PROFILE_MAIN_10_HDR10_PLUS** = 4<br>} | Enumerates the HEVC profiles.| 
| [OH_AACProfile](_codec_base.md#oh_aacprofile) {<br>&nbsp;&nbsp;&nbsp;&nbsp;**AAC_PROFILE_LC** = 0<br>} | Enumerates the AAC profiles.| 
| [OH_AVSeekMode](_codec_base.md#oh_avseekmode) {<br>&nbsp;&nbsp;&nbsp;&nbsp;**SEEK_MODE_NEXT_SYNC** = 0,<br>&nbsp;&nbsp;&nbsp;&nbsp;**SEEK_MODE_PREVIOUS_SYNC**,<br>&nbsp;&nbsp;&nbsp;&nbsp;**SEEK_MODE_CLOSEST_SYNC**<br>} | Enumerates the seek modes.| 
| [OH_ColorPrimary](_codec_base.md#oh_colorprimary) {<br>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_BT709** = 1,<br>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_UNSPECIFIED** = 2,<br>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_BT470_M** = 4,<br>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_BT601_625** = 5,<br>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_BT601_525** = 6,<br>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_SMPTE_ST240** = 7,<br>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_GENERIC_FILM** = 8,<br>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_BT2020** = 9,<br>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_SMPTE_ST428** = 10,<br>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_P3DCI** = 11,<br>&nbsp;&nbsp;&nbsp;&nbsp;**COLOR_PRIMARY_P3D65** = 12<br>} | Enumerates the primary colors.| 
| [OH_TransferCharacteristic](_codec_base.md#oh_transfercharacteristic) {<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_BT709** = 1,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_UNSPECIFIED** = 2,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_GAMMA_2_2** = 4,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_GAMMA_2_8** = 5,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_BT601** = 6,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_SMPTE_ST240** = 7,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_LINEAR** = 8,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_LOG** = 9,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_LOG_SQRT** = 10,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_IEC_61966_2_4** = 11,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_BT1361** = 12,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_IEC_61966_2_1** = 13,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_BT2020_10BIT** = 14,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_BT2020_12BIT** = 15,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_PQ** = 16,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_SMPTE_ST428** = 17,<br>&nbsp;&nbsp;&nbsp;&nbsp;**TRANSFER_CHARACTERISTIC_HLG** = 18<br>} | Enumerates the transfer characteristics.| 
| [OH_MatrixCoefficient](_codec_base.md#oh_matrixcoefficient) {<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_IDENTITY** = 0,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_BT709** = 1,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_UNSPECIFIED** = 2,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_FCC** = 4,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_BT601_625** = 5,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_BT601_525** = 6,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_SMPTE_ST240** = 7,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_YCGCO** = 8,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_BT2020_NCL** = 9,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_BT2020_CL** = 10,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_SMPTE_ST2085** = 11,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_CHROMATICITY_NCL** = 12,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_CHROMATICITY_CL** = 13,<br>&nbsp;&nbsp;&nbsp;&nbsp;**MATRIX_COEFFICIENT_ICTCP** = 14<br>} | Enumerates the matrix coefficients.| 
| [OH_BitsPerSample](_codec_base.md#oh_bitspersample) {<br>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_U8** = 0,<br>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_S16LE** = 1,<br>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_S24LE** = 2,<br>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_S32LE** = 3,<br>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_F32LE** = 4,i<br>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_U8P** = 5,<br>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_S16P** = 6,<br>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_S24P** = 7,<br>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_S32P** = 8,<br>&nbsp;&nbsp;&nbsp;&nbsp;**SAMPLE_F32P** = 9,<br>&nbsp;&nbsp;&nbsp;&nbsp;**INVALID_WIDTH** = -1<br>} | Enumerates the number of audio bits for each coded sample.| 


### Variables

| Name| Description| 
| -------- | -------- |
| [OH_AVCodecBufferAttr::pts](_o_h___a_v_codec_buffer_attr.md#pts) | Defines the display timestamp of the buffer, in microseconds.| 
| [OH_AVCodecBufferAttr::size](_o_h___a_v_codec_buffer_attr.md#size) | Defines the size of data contained in the buffer, in bytes.| 
| [OH_AVCodecBufferAttr::offset](_o_h___a_v_codec_buffer_attr.md#offset) | Defines the offset of valid data in the buffer.| 
| [OH_AVCodecBufferAttr::flags](_o_h___a_v_codec_buffer_attr.md#flags) | Defines the flags of the buffer. It is a combination of multiple [OH_AVCodecBufferFlags](_codec_base.md#oh_avcodecbufferflags).| 
| [OH_AVCodecAsyncCallback::onError](_o_h___a_v_codec_async_callback.md#onerror) | Defines the callback used to report a codec operation error. For details, see [OH_AVCodecOnError](_codec_base.md#oh_avcodeconerror).| 
| [OH_AVCodecAsyncCallback::onStreamChanged](_o_h___a_v_codec_async_callback.md#onstreamchanged) | Defines the callback used to report a codec stream change. For details, see [OH_AVCodecOnStreamChanged](_codec_base.md#oh_avcodeconstreamchanged).| 
| [OH_AVCodecAsyncCallback::onNeedInputData](_o_h___a_v_codec_async_callback.md#onneedinputdata) | Defines the callback used to report input data required. For details, see [OH_AVCodecOnNeedInputData](_codec_base.md#oh_avcodeconneedinputdata).| 
| [OH_AVCodecAsyncCallback::onNeedOutputData](_o_h___a_v_codec_async_callback.md#onneedinputdata) | Defines the callback used to report output data generated. For details, see [OH_AVCodecOnNewOutputData](_codec_base.md#oh_avcodeconnewoutputdata).| 
| \*[OH_AVCODEC_MIMETYPE_VIDEO_AVC](_codec_base.md#oh_avcodec_mimetype_video_avc) | Defines the pointer to the Multipurpose Internet Mail Extension (MIME) type for AVC video codec.| 
| \*[OH_AVCODEC_MIMETYPE_AUDIO_AAC](_codec_base.md#oh_avcodec_mimetype_audio_aac) | Defines the pointer to the MIME type for AAC audio codec.| 
| \*[OH_AVCODEC_MIMETYPE_VIDEO_MPEG4](_codec_base.md#oh_avcodec_mimetype_video_mpeg4) | Defines the pointer to the MIME type for MPEG4 video codec.| 
| \*[OH_AVCODEC_MIMETYPE_VIDEO_HEVC](_codec_base.md#oh_avcodec_mimetype_video_hevc) | Defines the pointer to the MIME type for HEVC video codec.| 
| \*[OH_AVCODEC_MIMETYPE_AUDIO_MPEG](_codec_base.md#oh_avcodec_mimetype_audio_mpeg) | Defines the pointer to the MIME type for MPEG audio codec.| 
| \*[OH_AVCODEC_MIMETYPE_IMAGE_JPG](_codec_base.md#oh_avcodec_mimetype_image_jpg) | Defines the pointer to the MIME type for JPG image codec.| 
| \*[OH_AVCODEC_MIMETYPE_IMAGE_PNG](_codec_base.md#oh_avcodec_mimetype_image_png) | Defines the pointer to the MIME type for PNG image codec.| 
| \*[OH_AVCODEC_MIMETYPE_IMAGE_BMP](_codec_base.md#oh_avcodec_mimetype_image_bmp) | Defines the pointer to the MIME type for BMP image codec.| 
| \*[OH_AVCODEC_MIMETYPE_AUDIO_FLAC](_codec_base.md#oh_avcodec_mimetype_audio_flac) | Defines the pointer to the MIME type for FLAC audio codec.| 
| \*[OH_AVCODEC_MIMETYPE_AUDIO_VORBIS](_codec_base.md#oh_avcodec_mimetype_audio_vorbis) | Defines the pointer to the MIME type for VORBIS audio codec.| 
| \*[OH_ED_KEY_TIME_STAMP](_codec_base.md#oh_ed_key_time_stamp) | Defines the pointer to the timestamp in the extra data of the surface. The value type is int64.| 
| \*[OH_ED_KEY_EOS](_codec_base.md#oh_ed_key_eos) | Defines the pointer to the end of stream (EOS) in the extra data of the surface. The value type is Boolean.| 
| \*[OH_MD_KEY_TRACK_TYPE](_codec_base.md#oh_md_key_track_type) | Defines the pointer to a container for storing media descriptions.| 
| \*[OH_MD_KEY_CODEC_MIME](_codec_base.md#oh_md_key_codec_mime) | Define the pointer to the MIME type of codec. The value is a string.| 
| \*[OH_MD_KEY_DURATION](_codec_base.md#oh_md_key_duration) | Defines the pointer to the duration. The value type is int64_t.| 
| \*[OH_MD_KEY_BITRATE](_codec_base.md#oh_md_key_bitrate) | Defines the pointer to the bit rate. The value type is uint32_t.| 
| \*[OH_MD_KEY_MAX_INPUT_SIZE](_codec_base.md#oh_md_key_max_input_size) | Defines the pointer to the maximum input size. The value type is uint32_t.| 
| \*[OH_MD_KEY_WIDTH](_codec_base.md#oh_md_key_width) | Defines the pointer to the video width. The value type is uint32_t.| 
| \*[OH_MD_KEY_HEIGHT](_codec_base.md#oh_md_key_height) | Defines the pointer to the video height. The value type is uint32_t.| 
| \*[OH_MD_KEY_PIXEL_FORMAT](_codec_base.md#oh_md_key_pixel_format) | Defines the pointer to the video pixel format. The value type is int32_t. For details, see [OH_AVPixelFormat](_core.md#oh_avpixelformat).| 
| \*[OH_MD_KEY_RANGE_FLAG](_codec_base.md#oh_md_key_range_flag) | Defines the pointer to the video YUV value range flag. The value type is Boolean.| 
| \*[OH_MD_KEY_COLOR_PRIMARIES](_codec_base.md#oh_md_key_color_primaries) | Defines the pointer to the primary color of the video. The value type is int32_t.| 
| \*[OH_MD_KEY_TRANSFER_CHARACTERISTICS](_codec_base.md#oh_md_key_transfer_characteristics) | Defines the pointer to the video transfer characteristics. The value type is int32_t.| 
| \*[OH_MD_KEY_MATRIX_COEFFICIENTS](_codec_base.md#oh_md_key_matrix_coefficients) | Defines the pointer to the video matrix coefficient. The value type is int32_t.| 
| \*[OH_MD_KEY_AUDIO_SAMPLE_FORMAT](_codec_base.md#oh_md_key_audio_sample_format) | Defines the pointer to the original audio format. The value type is uint32_t.| 
| \*[OH_MD_KEY_FRAME_RATE](_codec_base.md#oh_md_key_frame_rate) | Defines the pointer to the video frame rate. The value is a double-precision floating point number.| 
| \*[OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE](_codec_base.md#oh_md_key_video_encode_bitrate_mode) | Defines the pointer to the video encoding bit rate mode. The value type is int32_t. For details, see [OH_VideoEncodeBitrateMode](_video_encoder.md#oh_videoencodebitratemode).| 
| \*[OH_MD_KEY_PROFILE](_codec_base.md#oh_md_key_profile) | Defines the pointer to the encoding template. The value is a number. For details, see [OH_AVCProfile](_codec_base.md#oh_avcprofile), [OH_AACProfile](_codec_base.md#oh_aacprofile), or [CodecBase](_codec_base.md#oh_hevcprofile).| 
| \*[OH_MD_KEY_AUD_CHANNEL_COUNT](_codec_base.md#oh_md_key_aud_channel_count) | Defines the pointer to the number of audio channels. The value type is uint32_t.| 
| \*[OH_MD_KEY_AUD_SAMPLE_RATE](_codec_base.md#oh_md_key_aud_sample_rate) | Defines the pointer to the audio sampling rate. The value type is uint32_t.| 
| \*[OH_MD_KEY_I_FRAME_INTERVAL](_codec_base.md#oh_md_key_i_frame_interval) | Defines the pointer to the key frame interval, in milliseconds. The value type is int32_t.| 
| \*[OH_MD_KEY_ROTATION](_codec_base.md#oh_md_key_rotation) | Defines the pointer to the rotation angle of the surface. The value type is int32_t, and the value range is {0, 90, 180, 270}. The default value is 0.| 
| \*[OH_MD_KEY_CODEC_CONFIG](_codec_base.md#oh_md_key_codec_config) | Defines the pointer to the codec-specific data. The value type is uint8_t\*.| 
| \*[OH_MD_KEY_REQUEST_I_FRAME](_codec_base.md#oh_md_key_request_i_frame) | Defines the pointer to the request for immediate encoding of I-frames. The value type is Boolean.| 
| \*[OH_MD_KEY_QUALITY](_codec_base.md#oh_md_key_quality) | Defines the pointer to the required encoding quality. The value type is uint32_t. This key applies only to encoders configured in constant quality mode.| 
| \*[OH_MD_KEY_CHANNEL_LAYOUT](_codec_base.md#oh_md_key_channel_layout) | Defines the pointer to the required encoding channel layout. The value type is int64_t. This key applies only to encoders.| 
| \*[OH_MD_KEY_BITS_PER_CODED_SAMPLE](_codec_base.md#oh_md_key_bits_per_coded_sample) | Defines the pointer to the number of bits for each coded sample. The value type is uint32_t. This key applies to FLAC encoders.| 
| \*[OH_MD_KEY_AAC_IS_ADTS](_codec_base.md#oh_md_key_aac_is_adts) | Defines the pointer to the AAC format. The value type is uint32_t. This key applies to AAC decoders.| 
| \*[OH_MD_KEY_SBR](_codec_base.md#oh_md_key_sbr) | Defines the pointer to the AAC SBR format. The value type is uint32_t. This key applies to AAC encoders.| 
| \*[OH_MD_KEY_COMPLIANCE_LEVEL](_codec_base.md#oh_md_key_compliance_level) | Defines the pointer to the FLAC compliance level. The value type is int32_t.| 
| \*[OH_MD_KEY_IDENTIFICATION_HEADER](_codec_base.md#oh_md_key_identification_header) | Defines the pointer to the VORBIS identification header. The value type is uint8_t\*. This key applies only to VORBIS decoders.| 
| \*[OH_MD_KEY_SETUP_HEADER](_codec_base.md#oh_md_key_setup_header) | Defines the pointer to the VORBIS setup header. The value type is uint8_t\*. This key applies only to VORBIS decoders.| 
| \*[OH_MD_KEY_TITLE](_codec_base.md#oh_md_key_title) | Defines the pointer to the title of the input media. The value is a string.| 
| \*[OH_MD_KEY_ARTIST](_codec_base.md#oh_md_key_artist) | Defines the pointer to the artist of the input media. The value is a string.| 
| \*[OH_MD_KEY_ALBUM](_codec_base.md#oh_md_key_album) | Defines the pointer to the album of the input media. The value is a string.| 
| \*[OH_MD_KEY_ALBUM_ARTIST](_codec_base.md#oh_md_key_album_artist) | Defines the pointer to the album_artist of the input media. The value is a string.| 
| \*[OH_MD_KEY_DATE](_codec_base.md#oh_md_key_date) | Defines the pointer to the date of the input media. The value is a string.| 
| \*[OH_MD_KEY_COMMENT](_codec_base.md#oh_md_key_comment) | Defines the pointer to the comment of the input media. The value is a string.| 
| \*[OH_MD_KEY_GENRE](_codec_base.md#oh_md_key_genre) | Defines the pointer to the genre of the input media. The value is a string.| 
| \*[OH_MD_KEY_COPYRIGHT](_codec_base.md#oh_md_key_copyright) | Defines the pointer to the copyright of the input media. The value is a string.| 
| \*[OH_MD_KEY_LANGUAGE](_codec_base.md#oh_md_key_language) | Defines the pointer to the language of the input media. The value is a string.| 
| \*[OH_MD_KEY_DESCRIPTION](_codec_base.md#oh_md_key_description) | Defines the pointer to the description of the input media. The value is a string.| 
| \*[OH_MD_KEY_LYRICS](_codec_base.md#oh_md_key_lyrics) | Defines the pointer to the lyrics of the input media. The value is a string.| 
| \*[OH_MD_KEY_TRACK_COUNT](_codec_base.md#oh_md_key_track_count) | Defines the pointer to the track count of the input media. The value type is uint32_t.| 
| \*[OH_MD_MAX_INPUT_BUFFER_COUNT](_codec_base.md#oh_md_max_input_buffer_count) | Defines the pointer to the maximum number of input buffers. The value type is int32_t.| 
| \*[OH_MD_MAX_OUTPUT_BUFFER_COUNT](_codec_base.md#oh_md_max_output_buffer_count) | Defines the pointer to the maximum number of output buffers. The value type is int32_t.| 
