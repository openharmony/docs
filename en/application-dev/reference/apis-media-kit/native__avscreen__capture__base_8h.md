# native_avscreen_capture_base.h


## Overview

The **native_avscreen_capture_base.h** file declares the common structs, character constants, and enums used for running screen capture.

**Library**: libnative_avscreen_capture.so

**File to include**: <multimedia/player_framework/native_avscreen_capture_base.h>

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Related module**: [AVScreenCapture](_a_v_screen_capture.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [OH_AudioCaptureInfo](_o_h___audio_capture_info.md) | Describes the audio capture information.| 
| struct  [OH_AudioEncInfo](_o_h___audio_enc_info.md) | Describes the audio encoding information.| 
| struct  [OH_AudioInfo](_o_h___audio_info.md) | Describes the audio information.| 
| struct  [OH_VideoCaptureInfo](_o_h___video_capture_info.md) | Describes the video capture information.| 
| struct  [OH_VideoEncInfo](_o_h___video_enc_info.md) | Describes the video encoding information.| 
| struct  [OH_VideoInfo](_o_h___video_info.md) | Describes the video information.| 
| struct  [OH_RecorderInfo](_o_h___recorder_info.md) | Describes the recording file information.| 
| struct  [OH_AVScreenCaptureConfig](_o_h___a_v_screen_capture_config.md) | Describes the screen capture configuration.| 
| struct  [OH_AVScreenCaptureCallback](_o_h___a_v_screen_capture_callback.md) | Describes all the asynchronous callback function pointers of an **OH_AVScreenCapture** instance.| 
| struct  [OH_Rect](_o_h___rect.md) | Describes the width, height, and image information of the rectangle used for screen capture.| 
| struct  [OH_AudioBuffer](_o_h___audio_buffer.md) | Describes the configuration such as the size, type, and timestamp of audio data.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_NativeBuffer](_a_v_screen_capture.md#oh_nativebuffer) [OH_NativeBuffer](_a_v_screen_capture.md#oh_nativebuffer) | Defines the native video stream class for screen capture.| 
| typedef struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) | Defines a screen capture instance used to obtain original video and audio streams.| 
| typedef struct [OH_AVScreenCapture_ContentFilter](_a_v_screen_capture.md#oh_avscreencapture_contentfilter) [OH_AVScreenCapture_ContentFilter](_a_v_screen_capture.md#oh_avscreencapture_contentfilter) | Defines a struct that describes the filter used to filter audio and video content.| 
| typedef enum [OH_CaptureMode](_a_v_screen_capture.md#oh_capturemode-1) [OH_CaptureMode](_a_v_screen_capture.md#oh_capturemode) | Defines an enum for the screen capture modes.| 
| typedef enum [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype-1) [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype) | Defines an enum for the audio source types during screen capture.| 
| typedef enum [OH_AudioCodecFormat](_a_v_screen_capture.md#oh_audiocodecformat-1) [OH_AudioCodecFormat](_a_v_screen_capture.md#oh_audiocodecformat) | Defines an enum for the audio encoding formats.| 
| typedef enum [OH_VideoCodecFormat](_a_v_screen_capture.md#oh_videocodecformat-1) [OH_VideoCodecFormat](_a_v_screen_capture.md#oh_videocodecformat) | Defines an enum for the video encoding formats.| 
| typedef enum [OH_DataType](_a_v_screen_capture.md#oh_datatype-1) [OH_DataType](_a_v_screen_capture.md#oh_datatype) | Defines an enum for the data types of screen capture streams.| 
| typedef enum [OH_VideoSourceType](_a_v_screen_capture.md#oh_videosourcetype-1) [OH_VideoSourceType](_a_v_screen_capture.md#oh_videosourcetype) | Defines an enum for the video source formats. Currently, only the RGBA format is supported.| 
| typedef enum [OH_ContainerFormatType](_a_v_screen_capture.md#oh_containerformattype-1) [OH_ContainerFormatType](_a_v_screen_capture.md#oh_containerformattype) | Defines an enum for the types of files generated during screen capture.| 
| typedef struct [OH_AudioCaptureInfo](_o_h___audio_capture_info.md) [OH_AudioCaptureInfo](_a_v_screen_capture.md#oh_audiocaptureinfo) | Defines a struct that describes the audio capture information.| 
| typedef struct [OH_AudioEncInfo](_o_h___audio_enc_info.md) [OH_AudioEncInfo](_a_v_screen_capture.md#oh_audioencinfo) | Defines a struct that describes the audio encoding information.| 
| typedef struct [OH_AudioInfo](_o_h___audio_info.md) [OH_AudioInfo](_a_v_screen_capture.md#oh_audioinfo) | Defines a struct that describes the audio information.| 
| typedef struct [OH_VideoCaptureInfo](_o_h___video_capture_info.md) [OH_VideoCaptureInfo](_a_v_screen_capture.md#oh_videocaptureinfo) | Defines a struct that describes the video capture information.| 
| typedef struct [OH_VideoEncInfo](_o_h___video_enc_info.md) [OH_VideoEncInfo](_a_v_screen_capture.md#oh_videoencinfo) | Defines a struct that describes the video encoding information.| 
| typedef struct [OH_VideoInfo](_o_h___video_info.md) [OH_VideoInfo](_a_v_screen_capture.md#oh_videoinfo) | Defines a struct that describes the video information.| 
| typedef struct [OH_RecorderInfo](_o_h___recorder_info.md) [OH_RecorderInfo](_a_v_screen_capture.md#oh_recorderinfo) | Defines a struct that describes the recording file information.| 
| typedef struct [OH_AVScreenCaptureConfig](_o_h___a_v_screen_capture_config.md) [OH_AVScreenCaptureConfig](_a_v_screen_capture.md#oh_avscreencaptureconfig) | Defines a struct that describes the screen capture configuration.| 
| typedef void(\* [OH_AVScreenCaptureOnError](_a_v_screen_capture.md#oh_avscreencaptureonerror)) ([OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, int32_t errorCode) | Defines a pointer to a callback function that is called when an error occurs during the running of an **OH_AVScreenCapture** instance.| 
| typedef void(\* [OH_AVScreenCaptureOnAudioBufferAvailable](_a_v_screen_capture.md#oh_avscreencaptureonaudiobufferavailable)) ([OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, bool isReady, [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype) type) | Defines a pointer to a callback function that is called when an audio buffer is available during the running of an **OH_AVScreenCapture** instance.| 
| typedef void(\* [OH_AVScreenCaptureOnVideoBufferAvailable](_a_v_screen_capture.md#oh_avscreencaptureonvideobufferavailable)) ([OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, bool isReady) | Defines a pointer to a callback function that is called when a video buffer is available during the running of an **OH_AVScreenCapture** instance.| 
| typedef struct [OH_AVScreenCaptureCallback](_o_h___a_v_screen_capture_callback.md) [OH_AVScreenCaptureCallback](_a_v_screen_capture.md#oh_avscreencapturecallback) | Defines a struct that describes all the asynchronous callback function pointers of an **OH_AVScreenCapture** instance.| 
| typedef struct [OH_Rect](_o_h___rect.md) [OH_Rect](_a_v_screen_capture.md#oh_rect) | Defines a struct that describes the width, height, and image information of the rectangle used for screen capture.| 
| typedef struct [OH_AudioBuffer](_o_h___audio_buffer.md) [OH_AudioBuffer](_a_v_screen_capture.md#oh_audiobuffer) | Defines a struct that describes the configuration such as the size, type, and timestamp of audio data.| 
| typedef enum [OH_AVScreenCaptureStateCode](_a_v_screen_capture.md#oh_avscreencapturestatecode-1) [OH_AVScreenCaptureStateCode](_a_v_screen_capture.md#oh_avscreencapturestatecode) | Defines an enum for the screen capture states.| 
| typedef enum [OH_AVScreenCaptureBufferType](_a_v_screen_capture.md#oh_avscreencapturebuffertype-1) [OH_AVScreenCaptureBufferType](_a_v_screen_capture.md#oh_avscreencapturebuffertype) | Defines an enum for the buffer types.| 
| typedef enum [OH_AVScreenCaptureFilterableAudioContent](_a_v_screen_capture.md#oh_avscreencapturefilterableaudiocontent-1) [OH_AVScreenCaptureFilterableAudioContent](_a_v_screen_capture.md#oh_avscreencapturefilterableaudiocontent) | Defines an enum for the types of audio that can be added to a content filter.| 
| typedef void(\* [OH_AVScreenCapture_OnStateChange](_a_v_screen_capture.md#oh_avscreencapture_onstatechange)) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, [OH_AVScreenCaptureStateCode](_a_v_screen_capture.md#oh_avscreencapturestatecode) stateCode, void \*userData) | Defines a pointer to a callback function that is called when the state changes during the running of an **OH_AVScreenCapture** instance.| 
| typedef void(\* [OH_AVScreenCapture_OnError](_a_v_screen_capture.md#oh_avscreencapture_onerror)) ([OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, int32_t errorCode, void \*userData) | Defines a pointer to a callback function that is called when an error occurs during the running of an **OH_AVScreenCapture** instance.| 
| typedef void(\* [OH_AVScreenCapture_OnBufferAvailable](_a_v_screen_capture.md#oh_avscreencapture_onbufferavailable)) ([OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, [OH_AVBuffer](../apis-avcodec-kit/_core.md#oh_avbuffer) \*buffer, [OH_AVScreenCaptureBufferType](_a_v_screen_capture.md#oh_avscreencapturebuffertype) bufferType, int64_t timestamp, void \*userData) | Defines a pointer to a callback function that is called when an audio or a video buffer is available during the running of an **OH_AVScreenCapture** instance.| 
| typedef void(\* [OH_AVScreenCapture_OnDisplaySelected](_a_v_screen_capture.md#oh_avscreencapture_ondisplayselected)) ([OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, uint64_t displayId, void \*userData) | Defines a pointer to a callback function that is called when screen capture starts.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_CaptureMode](_a_v_screen_capture.md#oh_capturemode-1) {<br>OH_CAPTURE_HOME_SCREEN = 0,<br>OH_CAPTURE_SPECIFIED_SCREEN = 1,<br>OH_CAPTURE_SPECIFIED_WINDOW = 2,<br>OH_CAPTURE_INVAILD = -1<br>} | Enumerates the screen capture modes.| 
| [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype-1) {<br>OH_SOURCE_INVALID = -1,<br>OH_SOURCE_DEFAULT = 0,<br>OH_MIC = 1,<br>OH_ALL_PLAYBACK = 2,<br>OH_APP_PLAYBACK = 3<br>} | Enumerates the audio source types during screen capture.| 
| [OH_AudioCodecFormat](_a_v_screen_capture.md#oh_audiocodecformat-1) {<br>OH_AUDIO_DEFAULT = 0,<br>OH_AAC_LC = 3,<br>OH_AUDIO_CODEC_FORMAT_BUTT<br>} | Enumerates the audio encoding formats.| 
| [OH_VideoCodecFormat](_a_v_screen_capture.md#oh_videocodecformat-1) {<br>OH_VIDEO_DEFAULT = 0,<br>OH_H264 = 2,<br>OH_H265 = 4,<br>OH_MPEG4 = 6,<br>OH_VP8 = 8,<br>OH_VP9 = 10,<br>OH_VIDEO_CODEC_FORMAT_BUTT<br>} | Enumerates the video encoding formats.| 
| [OH_DataType](_a_v_screen_capture.md#oh_datatype-1) {<br>OH_ORIGINAL_STREAM = 0,<br>OH_ENCODED_STREAM = 1,<br>OH_CAPTURE_FILE = 2,<br>OH_INVAILD = -1<br>} | Enumerates the data types of screen capture streams.| 
| [OH_VideoSourceType](_a_v_screen_capture.md#oh_videosourcetype-1) {<br>OH_VIDEO_SOURCE_SURFACE_YUV = 0,<br>OH_VIDEO_SOURCE_SURFACE_ES,<br>OH_VIDEO_SOURCE_SURFACE_RGBA,<br>OH_VIDEO_SOURCE_BUTT<br>} | Enumerates the video source formats. Currently, only the RGBA format is supported.| 
| [OH_ContainerFormatType](_a_v_screen_capture.md#oh_containerformattype-1) {<br>CFT_MPEG_4A = 0,<br>CFT_MPEG_4 = 1<br>} | Enumerates the types of files generated during screen capture.| 
| [OH_AVScreenCaptureStateCode](_a_v_screen_capture.md#oh_avscreencapturestatecode-1) {<br>OH_SCREEN_CAPTURE_STATE_STARTED = 0,<br>OH_SCREEN_CAPTURE_STATE_CANCELED = 1,<br>OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER = 2,<br>OH_SCREEN_CAPTURE_STATE_INTERRUPTED_BY_OTHER = 3,<br>OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL = 4,<br>OH_SCREEN_CAPTURE_STATE_MIC_UNAVAILABLE = 5,<br>OH_SCREEN_CAPTURE_STATE_MIC_MUTED_BY_USER = 6,<br>OH_SCREEN_CAPTURE_STATE_MIC_UNMUTED_BY_USER = 7,<br>OH_SCREEN_CAPTURE_STATE_ENTER_PRIVATE_SCENE = 8,<br>OH_SCREEN_CAPTURE_STATE_EXIT_PRIVATE_SCENE = 9,<br>OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER_SWITCHES = 10<br>} | Enumerates the screen capture states.| 
| [OH_AVScreenCaptureBufferType](_a_v_screen_capture.md#oh_avscreencapturebuffertype-1) {<br>OH_SCREEN_CAPTURE_BUFFERTYPE_VIDEO = 0,<br>OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_INNER = 1,<br>OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_MIC = 2<br>} | Enumerates the buffer types.| 
| [OH_AVScreenCaptureFilterableAudioContent](_a_v_screen_capture.md#oh_avscreencapturefilterableaudiocontent-1) {<br>OH_SCREEN_CAPTURE_NOTIFICATION_AUDIO = 0, <br>OH_SCREEN_CAPTURE_CURRENT_APP_AUDIO = 1 <br>} | Enumerates the types of audio that can be added to a content filter. | 
