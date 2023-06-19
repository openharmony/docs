# CodecBase


## Overview

Provides the common structs, character constants, and enums for running **OH_AVCodec** instances. This module may not be supported on some devices. You can call [CanIUse](../syscap.md) to check whether this module is supported on your device.

@syscap SystemCapability.Multimedia.Media.CodecBase

**Since**
9

## Summary


### Files

  | Name| Description| 
| -------- | -------- |
| [native_avcodec_base.h](native__avcodec__base_8h.md) | Declares the common structs, character constants, and enums for running <b>OH_AVCodec</b> instances.<br>File to include: <multimedia/player_framework/native_avcodec_base.h> |


### Structs

  | Name| Description| 
| -------- | -------- |
| [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) | Defines the buffer attributes of an **OH_AVCodec** instance. | 
| [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) | Defines a collection of asynchronous callback functions for an **OH_AVCodec** instance. You must register this struct instance for an **OH_AVCodec** instance and process the information reported through these callbacks to ensure the normal running of the instance. |


### Types

  | Name| Description| 
| -------- | -------- |
| [OH_AVCodecBufferFlags](#oh_avcodecbufferflags) | Enumerates the buffer flags of an **OH_AVCodec** instance. | 
| [OH_AVCodecBufferAttr](#oh_avcodecbufferattr) | Defines the buffer attributes of an **OH_AVCodec** instance. | 
| (\*[OH_AVCodecOnError](#oh_avcodeconerror)) (OH_AVCodec \*codec, int32_t errorCode, void \*userData) | Defines the function pointer that is called to report error information when an error occurs during the running of an **OH_AVCodec** instance. | 
| (\*[OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged)) (OH_AVCodec \*codec, OH_AVFormat \*format, void \*userData) | Defines the function pointer that is called to report the attributes of the new stream when the output stream changes. Note that the lifecycle of the pointer to the **OH_AVFormat** instance is valid only when the function pointer is being called. Do not access the pointer to the instance after the function pointer is called. | 
| (\*[OH_AVCodecOnNeedInputData](#oh_avcodeconneedinputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, void \*userData) | Defines the function pointer that is called, with a new buffer to fill in new input data, when new input data is required during the running of an **OH_AVCodec** instance. | 
| (\*[OH_AVCodecOnNewOutputData](#oh_avcodeconnewoutputdata)) (OH_AVCodec \*codec, uint32_t index, OH_AVMemory \*data, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr, void \*userData) | Defines the function pointer that is called, with a buffer containing new output data, when the new output data is generated during the running of an **OH_AVCodec** instance. Note that the lifecycle of the pointer to the **OH_AVCodecBufferAttr** instance is valid only when the function pointer is being called. Do not access the pointer to the instance after the function pointer is called. | 
| [OH_AVCodecAsyncCallback](#oh_avcodecasynccallback) | Defines a collection of asynchronous callback functions for an **OH_AVCodec** instance. You must register this struct instance for an **OH_AVCodec** instance and process the information reported through these callbacks to ensure the normal running of the instance. | 
| [OH_MediaType](#oh_mediatype) | Enumerates the media types. | 
| [OH_AVCProfile](#oh_avcprofile) | Enumerates the AVC profiles. | 
| [OH_AACProfile](#oh_aacprofile) | Enumerates the AAC profiles. | 


### Enums

  | Name| Description| 
| -------- | -------- |
| [OH_AVCodecBufferFlags](#oh_avcodecbufferflags) {<br>**AVCODEC_BUFFER_FLAGS_NONE** = 0, **AVCODEC_BUFFER_FLAGS_EOS** = 1 &lt;&lt; 0, **AVCODEC_BUFFER_FLAGS_SYNC_FRAME** = 1 &lt;&lt; 1, **AVCODEC_BUFFER_FLAGS_INCOMPLETE_FRAME** = 1 &lt;&lt; 2, **AVCODEC_BUFFER_FLAGS_CODEC_DATA**= 1 &lt;&lt; 3<br>} | Enumerates the buffer flags of an **OH_AVCodec** instance. |
| [OH_MediaType](#oh_mediatype) { **MEDIA_TYPE_AUD** = 0, **MEDIA_TYPE_VID** = 1 } | Enumerates the media types. |
| [OH_AVCProfile](#oh_avcprofile) { **AVC_PROFILE_BASELINE** = 0, **AVC_PROFILE_HIGH** = 4, **AVC_PROFILE_MAIN** = 8 } | Enumerates the Advanced Video Coding (AVC) profiles. | 
| [OH_AACProfile](#oh_aacprofile) { **AAC_PROFILE_LC** = 0 } | Enumerates the Advanced Audio Coding (AAC) profiles. | 


### Variables

  | Name| Description| 
| -------- | -------- |
| [OH_AVCodecBufferAttr::pts](#pts) | Defines the presentation timestamp of the buffer, in microseconds. | 
| [OH_AVCodecBufferAttr::size](#size) | Defines the size of the data contained in the buffer, in bytes. | 
| [OH_AVCodecBufferAttr::offset](#offset) | Defines the start offset of valid data in the buffer. | 
| [OH_AVCodecBufferAttr::flags](#flags) | Defines a buffer flag, which is a combination of multiple [OH_AVCodecBufferFlags](#oh_avcodecbufferflags). | 
| [OH_AVCODEC_MIMETYPE_VIDEO_AVC](#oh_avcodec_mimetype_video_avc) | Defines the Multipurpose Internet Mail Extension (MIME) type for AVC. | 
| [OH_AVCODEC_MIMETYPE_AUDIO_AAC](#oh_avcodec_mimetype_audio_aac) | Defines the MIME type for AAC. | 
| [OH_ED_KEY_TIME_STAMP](#oh_ed_key_time_stamp) | Defines the unified character descriptors for the auxiliary data of the surface buffer. | 
| [OH_ED_KEY_EOS](#oh_ed_key_eos) | Defines the character descriptor of the end-of-stream in the surface auxiliary data. The value type is bool. | 
| [OH_MD_KEY_TRACK_TYPE](#oh_md_key_track_type) | Defines the unified character descriptors for the media playback framework. | 
| [OH_MD_KEY_CODEC_MIME](#oh_md_key_codec_mime) | Defines the character descriptor of the MIME type. The value type is string. | 
| [OH_MD_KEY_DURATION](#oh_md_key_duration) | Defines the character descriptor of duration. The value type is int64_t. | 
| [OH_MD_KEY_BITRATE](#oh_md_key_bitrate) | Defines the character descriptor of the bit rate. The value type is uint32_t. | 
| [OH_MD_KEY_MAX_INPUT_SIZE](#oh_md_key_max_input_size) | Defines the character descriptor of the maximum input size. The value type is uint32_t. | 
| [OH_MD_KEY_WIDTH](#oh_md_key_width) | Defines the character descriptor of the video width. The value type is uint32_t. | 
| [OH_MD_KEY_HEIGHT](#oh_md_key_height) | Defines the character descriptor of the video height. The value type is uint32_t. | 
| [OH_MD_KEY_PIXEL_FORMAT](#oh_md_key_pixel_format) | Defines the character descriptor of the video pixel format. The value type is int32_t. For details, see [OH_AVPixelFormat](_core.md#oh_avpixelformat).| 
| [OH_MD_KEY_AUDIO_SAMPLE_FORMAT](#oh_md_key_audio_sample_format) | Defines the character descriptor of the audio sample format. The value type is uint32_t. | 
| [OH_MD_KEY_FRAME_RATE](#oh_md_key_frame_rate) | Defines the character descriptor of the video frame rate. The value type is double. | 
| [OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE](#oh_md_key_video_encode_bitrate_mode) | Defines the character descriptor of the video encoding bit rate mode. The value type is int32_t. For details, see [OH_VideoEncodeBitrateMode](_video_encoder.md#oh_videoencodebitratemode).| 
| [OH_MD_KEY_PROFILE](#oh_md_key_profile) | Defines the character descriptor of the audio/video encoding capability. The value type is int32_t. For details, see [OH_AVCProfile](#oh_avcprofile) or [OH_AACProfile](#oh_aacprofile).| 
| [OH_MD_KEY_AUD_CHANNEL_COUNT](#oh_md_key_aud_channel_count) | Defines the character descriptor of the number of audio channels. The value type is uint32_t. | 
| [OH_MD_KEY_AUD_SAMPLE_RATE](#oh_md_key_aud_sample_rate) | Defines the character descriptor of the audio sampling rate. The value type is uint32_t. | 
| [OH_MD_KEY_I_FRAME_INTERVAL](#oh_md_key_i_frame_interval) | Defines the character descriptor of the I-frame interval. The value type is int32_t, and the unit is ms. | 
| [OH_MD_KEY_ROTATION](#oh_md_key_rotation) | Defines the character descriptor of the surface rotation angle. The value type is int32_t. The value range is {0, 90, 180, 270}. The default value is 0. | 


## Type Description


### OH_AACProfile

  
```
typedef enum OH_AACProfileOH_AACProfile
```
**Description**<br>
Enumerates the AAC profiles.

@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCodecAsyncCallback

  
```
typedef struct OH_AVCodecAsyncCallbackOH_AVCodecAsyncCallback
```
**Description**<br>
Defines a collection of asynchronous callback functions for an **OH_AVCodec** instance. You must register this struct instance for an **OH_AVCodec** instance and process the information reported through these callbacks to ensure the normal running of the instance.

@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

  | Name| Description| 
| -------- | -------- |
| onError | Indicates the callback used to report errors occurred during the running of the instance. For details, see [OH_AVCodecOnError](#oh_avcodeconerror).| 
| onStreamChanged | Indicates the callback used to report stream information. For details, see [OH_AVCodecOnStreamChanged](#oh_avcodeconstreamchanged).| 
| onNeedInputData | Indicates the callback used to report input data needed. For details, see [OH_AVCodecOnNeedInputData](#oh_avcodeconneedinputdata).| 
| onNeedInputData | Indicates the callback used to report output data needed. For details, see [OH_AVCodecOnNewOutputData](#oh_avcodeconnewoutputdata).| 


### OH_AVCodecBufferAttr

  
```
typedef struct OH_AVCodecBufferAttrOH_AVCodecBufferAttr
```
**Description**<br>
Defines the buffer attributes of an **OH_AVCodec** instance.

@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCodecBufferFlags

  
```
typedef enum OH_AVCodecBufferFlagsOH_AVCodecBufferFlags
```
**Description**<br>
Enumerates the buffer flags of an **OH_AVCodec** instance.

@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCodecOnError

  
```
typedef void(* OH_AVCodecOnError) (OH_AVCodec *codec, int32_t errorCode, void *userData)
```
**Description**<br>
Defines the function pointer that is called to report error information when an error occurs during the running of an **OH_AVCodec** instance.

@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

  | Name| Description| 
| -------- | -------- |
| codec | Indicates the pointer to an **OH_AVCodec** instance. | 
| errorCode | Indicates an error code. | 
| userData | Indicates the pointer to user-specific data. | 


### OH_AVCodecOnNeedInputData

  
```
typedef void(* OH_AVCodecOnNeedInputData) (OH_AVCodec *codec, uint32_t index, OH_AVMemory *data, void *userData)
```
**Description**<br>
Defines the function pointer that is called, with a new buffer to fill in new input data, when new input data is required during the running of an **OH_AVCodec** instance.

@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

  | Name| Description| 
| -------- | -------- |
| codec | Indicates the pointer to an **OH_AVCodec** instance. | 
| index | Indicates the index of an input buffer. | 
| data | Indicates the pointer to the new input data. | 
| userData | Indicates the pointer to user-specific data. | 


### OH_AVCodecOnNewOutputData

  
```
typedef void(* OH_AVCodecOnNewOutputData) (OH_AVCodec *codec, uint32_t index, OH_AVMemory *data, OH_AVCodecBufferAttr *attr, void *userData)
```
**Description**<br>
Defines the function pointer that is called, with a buffer containing new output data, when the new output data is generated during the running of an **OH_AVCodec** instance. Note that the lifecycle of the pointer to the **OH_AVCodecBufferAttr** instance is valid only when the function pointer is being called. Do not access the pointer to the instance after the function pointer is called.

@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

  | Name| Description| 
| -------- | -------- |
| codec | Indicates the pointer to an **OH_AVCodec** instance. | 
| index | Indicates the index of a new output buffer. | 
| data | Indicates the pointer to the new output data. | 
| attr | Indicates the pointer to the attributes of the new output buffer. For details, see [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md).| 
| userData | Indicates the pointer to user-specific data.  | 


### OH_AVCodecOnStreamChanged

  
```
typedef void(* OH_AVCodecOnStreamChanged) (OH_AVCodec *codec, OH_AVFormat *format, void *userData)
```
**Description**<br>
Defines the function pointer that is called to report the attributes of the new stream when the output stream changes. Note that the lifecycle of the pointer to the **OH_AVFormat** instance is valid only when the function pointer is being called. Do not access the pointer to the instance after the function pointer is called.

@syscap SystemCapability.Multimedia.Media.CodecBase

**Parameters**

  | Name| Description| 
| -------- | -------- |
| codec | Indicates the pointer to an **OH_AVCodec** instance. | 
| format | Indicates the handle to the attributes of the new output stream. | 
| userData | Indicates the pointer to user-specific data. | 


### OH_AVCProfile

  
```
typedef enum OH_AVCProfileOH_AVCProfile
```
**Description**<br>
Enumerates the AVC profiles.

@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MediaType

  
```
typedef enum OH_MediaTypeOH_MediaType
```
**Description**<br>
Enumerates the media types.

@syscap SystemCapability.Multimedia.Media.CodecBase


## Enum Description


### OH_AACProfile

  
```
enum OH_AACProfile
```
**Description**<br>
Enumerates the AAC profiles.

@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCodecBufferFlags

  
```
enum OH_AVCodecBufferFlags
```
**Description**<br>
Enumerates the buffer flags of an **OH_AVCodec** instance.

@syscap SystemCapability.Multimedia.Media.CodecBase

  | Value| Description| 
| -------- | -------- |
| AVCODEC_BUFFER_FLAGS_EOS  | The buffer contains an end-of-stream frame.| 
| AVCODEC_BUFFER_FLAGS_SYNC_FRAME  | The buffer contains a sync frame.| 
| AVCODEC_BUFFER_FLAGS_INCOMPLETE_FRAME  | The buffer contains part of a frame.| 
| AVCODEC_BUFFER_FLAGS_CODEC_DATA  | The buffer contains codec-specific data.| 


### OH_AVCProfile

  
```
enum OH_AVCProfile
```
**Description**<br>
Enumerates the AVC profiles.

@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MediaType

  
```
enum OH_MediaType
```
**Description**<br>
Enumerates the media types.

@syscap SystemCapability.Multimedia.Media.CodecBase

  | Value| Description| 
| -------- | -------- |
| MEDIA_TYPE_AUD  | Audio track.| 
| MEDIA_TYPE_VID  | Video track.| 


## Variable Description


### flags

  
```
uint32_t OH_AVCodecBufferAttr::flags
```
**Description**<br>
Defines a buffer flag, which is a combination of multiple [OH_AVCodecBufferFlags](#oh_avcodecbufferflags).


### offset

  
```
int32_t OH_AVCodecBufferAttr::offset
```
**Description**<br>
Start offset of valid data in the buffer.


### OH_AVCODEC_MIMETYPE_AUDIO_AAC

  
```
const char* OH_AVCODEC_MIMETYPE_AUDIO_AAC
```
**Description**<br>
Defines the MIME type for AAC.

@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_AVCODEC_MIMETYPE_VIDEO_AVC

  
```
const char* OH_AVCODEC_MIMETYPE_VIDEO_AVC
```
**Description**<br>
Defines the MIME type for AVC.

@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_ED_KEY_EOS

  
```
const char* OH_ED_KEY_EOS
```
**Description**<br>
Defines the character descriptor of the end-of-stream in the surface auxiliary data. The value type is bool.


### OH_ED_KEY_TIME_STAMP

  
```
const char* OH_ED_KEY_TIME_STAMP
```
**Description**<br>
Defines the unified character descriptors for the auxiliary data of the surface buffer.

@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MD_KEY_AUD_CHANNEL_COUNT

  
```
const char* OH_MD_KEY_AUD_CHANNEL_COUNT
```
**Description**<br>
Defines the character descriptor of the number of audio channels. The value type is uint32_t.


### OH_MD_KEY_AUD_SAMPLE_RATE

  
```
const char* OH_MD_KEY_AUD_SAMPLE_RATE
```
**Description**<br>
Defines the character descriptor of the audio sampling rate. The value type is uint32_t.


### OH_MD_KEY_AUDIO_SAMPLE_FORMAT

  
```
const char* OH_MD_KEY_AUDIO_SAMPLE_FORMAT
```
**Description**<br>
Defines the character descriptor of the audio sample format. The value type is uint32_t.


### OH_MD_KEY_BITRATE

  
```
const char* OH_MD_KEY_BITRATE
```
**Description**<br>
Defines the character descriptor of the bit rate. The value type is uint32_t.


### OH_MD_KEY_CODEC_MIME

  
```
const char* OH_MD_KEY_CODEC_MIME
```
**Description**<br>
Defines the character descriptor of the MIME type. The value type is string.


### OH_MD_KEY_DURATION

  
```
const char* OH_MD_KEY_DURATION
```
**Description**<br>
Defines the character descriptor of duration. The value type is int64_t.


### OH_MD_KEY_FRAME_RATE

  
```
const char* OH_MD_KEY_FRAME_RATE
```
**Description**<br>
Defines the character descriptor of the video frame rate. The value type is double.


### OH_MD_KEY_HEIGHT

  
```
const char* OH_MD_KEY_HEIGHT
```
**Description**<br>
Defines the character descriptor of the video height. The value type is uint32_t.


### OH_MD_KEY_I_FRAME_INTERVAL

  
```
const char* OH_MD_KEY_I_FRAME_INTERVAL
```
**Description**<br>
Defines the character descriptor of the I-frame interval. The value type is int32_t, and the unit is ms.


### OH_MD_KEY_MAX_INPUT_SIZE

  
```
const char* OH_MD_KEY_MAX_INPUT_SIZE
```
**Description**<br>
Defines the character descriptor of the maximum input size. The value type is uint32_t.


### OH_MD_KEY_PIXEL_FORMAT

  
```
const char* OH_MD_KEY_PIXEL_FORMAT
```
**Description**<br>
Defines the character descriptor of the video pixel format. The value type is int32_t. For details, see [OH_AVPixelFormat](_core.md#oh_avpixelformat).


### OH_MD_KEY_PROFILE

  
```
const char* OH_MD_KEY_PROFILE
```
**Description**<br>
Defines the character descriptor of the audio/video encoding capability. The value type is int32_t. For details, see [OH_AVCProfile](#oh_avcprofile) or [OH_AACProfile](#oh_aacprofile).


### OH_MD_KEY_ROTATION

  
```
const char* OH_MD_KEY_ROTATION
```
**Description**<br>
Defines the character descriptor of the surface rotation angle. The value type is int32_t. The value range is {0, 90, 180, 270}. The default value is 0.


### OH_MD_KEY_TRACK_TYPE

  
```
const char* OH_MD_KEY_TRACK_TYPE
```
**Description**<br>
Defines the unified character descriptors for the media playback framework.

@syscap SystemCapability.Multimedia.Media.CodecBase


### OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE

  
```
const char* OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE
```
**Description**<br>
Defines the character descriptor of the video encoding bit rate mode. The value type is int32_t. For details, see [OH_VideoEncodeBitrateMode](_video_encoder.md#oh_videoencodebitratemode).


### OH_MD_KEY_WIDTH

  
```
const char* OH_MD_KEY_WIDTH
```
**Description**<br>
Defines the character descriptor of the video width. The value type is uint32_t.


### pts

  
```
int64_t OH_AVCodecBufferAttr::pts
```
**Description**<br>
Defines the presentation timestamp of the buffer, in microseconds.


### size

  
```
int32_t OH_AVCodecBufferAttr::size
```
**Description**<br>
Defines the size of the data contained in the buffer, in bytes.
