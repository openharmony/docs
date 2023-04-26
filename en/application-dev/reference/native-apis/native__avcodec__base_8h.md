# native_avcodec_base.h


## Overview

Declares the common structs, character constants, and enums for running **OH_AVCodec** instances.

**Since:**
9

**Related Modules:**

[CodecBase](_codec_base.md)


## Summary


### Structs

| Name | Description | 
| -------- | -------- |
| [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) | Defines the buffer attributes of an **OH_AVCodec** instance.  | 
| [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) | Defines a collection of asynchronous callback functions for an **OH_AVCodec** instance. You must register this struct instance for an **OH_AVCodec** instance and process the information reported through these callbacks to ensure the normal running of the instance.  | 


### Types

| Name | Description | 
| -------- | -------- |
| [OH_AVCodecBufferFlags](_codec_base.md#oh_avcodecbufferflags) | Enumerates the buffer flags of an **OH_AVCodec** instance.  | 
| [OH_AVCodecBufferAttr](_codec_base.md#oh_avcodecbufferattr) | Defines the buffer attributes of an **OH_AVCodec** instance.  | 
| [OH_AVCodecOnError](_codec_base.md#oh_avcodeconerror)) (OH_AVCodec \*codec, int32_t errorCode, void \*userData) | Defines the function pointer that is called to report error information when an error occurs during the running of an **OH_AVCodec** instance.  | 
| [OH_AVCodecOnStreamChanged](_codec_base.md#oh_avcodeconstreamchanged)) (OH_AVCodec \*codec, OH_AVFormat \*format, void \*userData) | Defines the function pointer that is called to report the attributes of the new stream when the output stream changes. Note that the lifecycle of the pointer to the **OH_AVFormat** instance is valid only when the function pointer is being called. Do not access the pointer to the instance after the function pointer is called.  | 
| [OH_AVCodecOnNeedInputData](_codec_base.md#oh_avcodeconneedinputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, void \*userData) | Defines the function pointer that is called, with a new buffer to fill in new input data, when new input data is required during the running of an **OH_AVCodec** instance.  | 
| [OH_AVCodecOnNewOutputData](_codec_base.md#oh_avcodeconnewoutputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr, void \*userData) | Defines the function pointer that is called, with a buffer containing new output data, when the new output data is generated during the running of an **OH_AVCodec** instance. Note that the lifecycle of the pointer to the **[OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md)** instance is valid only when the function pointer is being called. Do not access the pointer to the instance after the function pointer is called.  | 
| [OH_AVCodecAsyncCallback](_codec_base.md#oh_avcodecasynccallback) | Defines a collection of asynchronous callback functions for an **OH_AVCodec** instance. You must register this struct instance for an **OH_AVCodec** instance and process the information reported through these callbacks to ensure the normal running of the instance.  | 
| [OH_MediaType](_codec_base.md#oh_mediatype) | Enumerates the media types.  | 
| [OH_AVCProfile](_codec_base.md#oh_avcprofile) | Enumerates the AVC profiles.  | 
| [OH_AACProfile](_codec_base.md#oh_aacprofile) | Enumerates the AAC profiles.  | 


### Enums

| Name | Description | 
| -------- | -------- |
| [OH_AVCodecBufferFlags](_codec_base.md#oh_avcodecbufferflags) {<br/>AVCODEC_BUFFER_FLAGS_NONE = 0, AVCODEC_BUFFER_FLAGS_EOS = 1 &lt;&lt; 0, AVCODEC_BUFFER_FLAGS_SYNC_FRAME = 1 &lt;&lt; 1, AVCODEC_BUFFER_FLAGS_INCOMPLETE_FRAME = 1 &lt;&lt; 2,<br/>AVCODEC_BUFFER_FLAGS_CODEC_DATA = 1 &lt;&lt; 3<br/>} | Enumerates the buffer flags of an **OH_AVCodec** instance.  | 
| [OH_MediaType](_codec_base.md#oh_mediatype) { MEDIA_TYPE_AUD = 0, MEDIA_TYPE_VID = 1 } | Enumerates the media types.  | 
| [OH_AVCProfile](_codec_base.md#oh_avcprofile) { AVC_PROFILE_BASELINE = 0, AVC_PROFILE_HIGH = 4, AVC_PROFILE_MAIN = 8 } | Enumerates the AVC profiles.  | 
| [OH_AACProfile](_codec_base.md#oh_aacprofile) { AAC_PROFILE_LC = 0 } | Enumerates the AAC profiles.  | 


### Variables

| Name | Description | 
| -------- | -------- |
| [OH_AVCODEC_MIMETYPE_VIDEO_AVC](_codec_base.md#oh_avcodec_mimetype_video_avc) |  Defines the Multipurpose Internet Mail Extension (MIME) type for Advanced Video Coding (AVC).  | 
| [OH_AVCODEC_MIMETYPE_AUDIO_AAC](_codec_base.md#oh_avcodec_mimetype_audio_aac) |  Defines the MIME type for Advanced Audio Coding (AAC).  | 
| [OH_ED_KEY_TIME_STAMP](_codec_base.md#oh_ed_key_time_stamp) |  Provides unified character descriptors for the auxiliary data of the surface buffer.  | 
| [OH_ED_KEY_EOS](_codec_base.md#oh_ed_key_eos) |  Character descriptor of the end-of-stream in the surface auxiliary data. The value type is bool.|
| [OH_MD_KEY_TRACK_TYPE](_codec_base.md#oh_md_key_track_type) |  Provides unified character descriptors for the media playback framework.  | 
| [OH_MD_KEY_CODEC_MIME](_codec_base.md#oh_md_key_codec_mime) | Character descriptor of the MIME type. The value type is string.|
| [OH_MD_KEY_DURATION](_codec_base.md#oh_md_key_duration) | Character descriptor of duration. The value type is int64_t.|
| [OH_MD_KEY_BITRATE](_codec_base.md#oh_md_key_bitrate) | Character descriptor of the bit rate. The value type is uint32_t. |
| [OH_MD_KEY_MAX_INPUT_SIZE](_codec_base.md#oh_md_key_max_input_size) | Character descriptor of the maximum input size. The value type is uint32_t. |
| [OH_MD_KEY_WIDTH](_codec_base.md#oh_md_key_width) | Character descriptor of the video width. The value type is uint32_t. |
| [OH_MD_KEY_HEIGHT](_codec_base.md#oh_md_key_height) | Character descriptor of the video height. The value type is uint32_t. |
| [OH_MD_KEY_PIXEL_FORMAT](_codec_base.md#oh_md_key_pixel_format) | Character descriptor of the video pixel format. The value type is int32_t.  |
| [OH_MD_KEY_AUDIO_SAMPLE_FORMAT](_codec_base.md#oh_md_key_audio_sample_format) | Character descriptor of the audio sample format. The value type is uint32_t. |
| [OH_MD_KEY_FRAME_RATE](_codec_base.md#oh_md_key_frame_rate) | Character descriptor of the video frame rate. The value type is double. |
| [OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE](_codec_base.md#oh_md_key_video_encode_bitrate_mode) | Character descriptor of the video encoding bit rate mode. The value type is int32_t. |
| [OH_MD_KEY_PROFILE](_codec_base.md#oh_md_key_profile) | Character descriptor of the audio/video encoding capability. The value type is int32_t. |
| [OH_MD_KEY_AUD_CHANNEL_COUNT](_codec_base.md#oh_md_key_aud_channel_count) | Character descriptor of the number of audio channels. The value type is uint32_t. |
| [OH_MD_KEY_AUD_SAMPLE_RATE](_codec_base.md#oh_md_key_aud_sample_rate) | Character descriptor of the audio sampling rate. The value type is uint32_t. |
| [OH_MD_KEY_I_FRAME_INTERVAL](_codec_base.md#oh_md_key_i_frame_interval) | Character descriptor of the I-frame interval. The value type is int32_t, and the unit is ms. |
| [OH_MD_KEY_ROTATION](_codec_base.md#oh_md_key_rotation) | Character descriptor of the surface rotation angle. The value type is int32_t. The value range is {0, 90, 180, 270}. The default value is 0. |
