# native_avscreen_capture_base.h


## Overview

The **native_avscreen_capture_base.h** file declares the common structs, character constants, and enums used for running screen capture.

**Since**

10

**Related Modules**

[AVScreenCapture](_a_v_screen_capture.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| [OH_AudioCaptureInfo](_o_h___audio_capture_info.md) | Defines audio capturing information.| 
| [OH_AudioEncInfo](_o_h___audio_enc_info.md) | Defines audio encoding information.<br>**NOTE**: This struct is reserved and will be provided in later versions.| 
| [OH_AudioInfo](_o_h___audio_info.md) | Defines audio capturing parameters.| 
| [OH_VideoCaptureInfo](_o_h___video_capture_info.md) | Defines video capturing information.| 
| [OH_VideoEncInfo](_o_h___video_enc_info.md) | Defines video encoding information.<br>**NOTE**: This struct is reserved and will be provided in later versions.| 
| [OH_VideoInfo](_o_h___video_info.md) | Defines video capturing parameters.| 
| [OH_RecorderInfo](_o_h___recorder_info.md) | Defines recording file information.| 
| [OH_AVScreenCaptureConfig](_o_h___a_v_screen_capture_config.md) | Defines the screen capture configuration.| 
| [OH_AVScreenCaptureCallback](_o_h___a_v_screen_capture_callback.md) | Defines all the asynchronous callback function pointers of an **OH_AVScreenCapture** instance.| 
| [OH_Rect](_o_h___rect.md) | Defines the width, height, and image information of the rectangle used for screen capture.| 
| [OH_AudioBuffer](_o_h___audio_buffer.md) | Defines the configuration such as the size, type, and timestamp of audio data.| 


### Types

| Name| Description| 
| -------- | -------- |
| [OH_NativeBuffer](_a_v_screen_capture.md#oh_nativebuffer) | Defines the native video stream class for screen capture.| 
| [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) | Defines a screen capture instance used to obtain original video and audio streams.| 
| [OH_CaptureMode](_a_v_screen_capture.md#oh_capturemode) | Defines an enum that enumerates the screen capture modes.| 
| [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype) | Defines an enum that enumerates the audio source types during screen capture.| 
| [OH_AudioCodecFormat](_a_v_screen_capture.md#oh_audiocodecformat) | Defines an enum that enumerates the audio encoding formats.| 
| [OH_VideoCodecFormat](_a_v_screen_capture.md#oh_videocodecformat) | Defines an enum that enumerates the video encoding formats.| 
| [OH_DataType](_a_v_screen_capture.md#oh_datatype) | Defines an enum that enumerates the data types of screen capture streams.| 
| [OH_VideoSourceType](_a_v_screen_capture.md#oh_videosourcetype) | Defines an enum that enumerates the video source formats.| 
| [OH_ContainerFormatType](_a_v_screen_capture.md#oh_containerformattype) | Defines an enum that enumerates the types of files generated during screen capture.<br>**NOTE**: This type is reserved and will be provided in later versions.| 
| [OH_AudioCaptureInfo](_a_v_screen_capture.md#oh_audiocaptureinfo) | Defines audio capturing information.| 
| [OH_AudioEncInfo](_a_v_screen_capture.md#oh_audioencinfo) | Defines audio encoding information.<br>**NOTE**: This type is reserved and will be provided in later versions.| 
| [OH_AudioInfo](_a_v_screen_capture.md#oh_audioinfo) | Defines audio capturing parameters.| 
| [OH_VideoCaptureInfo](_a_v_screen_capture.md#oh_videocaptureinfo) | Defines video capturing information.| 
| [OH_VideoEncInfo](_a_v_screen_capture.md#oh_videoencinfo) | Defines video encoding information.<br>**NOTE**: This type is reserved and will be provided in later versions.| 
| [OH_VideoInfo](_a_v_screen_capture.md#oh_videoinfo) | Defines video capturing parameters.| 
| [OH_RecorderInfo](_a_v_screen_capture.md#oh_recorderinfo) | Defines recording file information.| 
| [OH_AVScreenCaptureConfig](_a_v_screen_capture.md#oh_avscreencaptureconfig) | Defines the screen recording configuration.| 
| (\*[OH_AVScreenCaptureOnError](_a_v_screen_capture.md#oh_avscreencaptureonerror)) ([OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, int32_t errorCode) | Defines a pointer to a callback function that is called when an error occurs during the running of an **OH_AVScreenCapture** instance.| 
| (\*[OH_AVScreenCaptureOnAudioBufferAvailable](_a_v_screen_capture.md#oh_avscreencaptureonaudiobufferavailable)) ([OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, bool isReady, [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype) type) | Defines a pointer to a callback function that is called when an audio buffer is available during the running of an **OH_AVScreenCapture** instance.| 
| (\*[OH_AVScreenCaptureOnVideoBufferAvailable](_a_v_screen_capture.md#oh_avscreencaptureonvideobufferavailable)) ([OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, bool isReady) | Defines a pointer to a callback function that is called when a video buffer is available during the running of an **OH_AVScreenCapture** instance.| 
| [OH_AVScreenCaptureCallback](_a_v_screen_capture.md#oh_avscreencapturecallback) | Defines all the asynchronous callback function pointers of an **OH_AVScreenCapture** instance.| 
| [OH_Rect](_a_v_screen_capture.md#oh_rect) | Defines the width, height, and image information of the rectangle used for screen capture.| 
| [OH_AudioBuffer](_a_v_screen_capture.md#oh_audiobuffer) | Defines the configuration such as the size, type, and timestamp of audio data.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_CaptureMode](_a_v_screen_capture.md#oh_capturemode) { [OH_CAPTURE_HOME_SCREEN](_a_v_screen_capture.md) = 0, [OH_CAPTURE_SPECIFIED_SCREEN](_a_v_screen_capture.md) = 1, [OH_CAPTURE_SPECIFIED_WINDOW](_a_v_screen_capture.md) = 2, [OH_CAPTURE_INVAILD](_a_v_screen_capture.md) = -1 } | Enumerates the screen capture modes.| 
| [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype) {<br>[OH_SOURCE_INVALID](_a_v_screen_capture.md) = -1, [OH_SOURCE_DEFAULT](_a_v_screen_capture.md) = 0, [OH_MIC](_a_v_screen_capture.md) = 1, [OH_ALL_PLAYBACK](_a_v_screen_capture.md) = 2,<br>[OH_APP_PLAYBACK](_a_v_screen_capture.md) = 3<br>} | Enumerates the audio source types during screen capture.| 
| [OH_AudioCodecFormat](_a_v_screen_capture.md#oh_audiocodecformat) { [OH_AUDIO_DEFAULT](_a_v_screen_capture.md) = 0, [OH_AAC_LC](_a_v_screen_capture.md) = 3, [OH_AUDIO_CODEC_FORMAT_BUTT](_a_v_screen_capture.md) } | Enumerates the audio encoding formats.| 
| [OH_VideoCodecFormat](_a_v_screen_capture.md#oh_videocodecformat) {<br>[OH_VIDEO_DEFAULT](_a_v_screen_capture.md) = 0, [OH_H264](_a_v_screen_capture.md) = 2, [OH_H265](_a_v_screen_capture.md) = 4, [OH_MPEG4](_a_v_screen_capture.md) = 6,<br>[OH_VP8](_a_v_screen_capture.md) = 8, [OH_VP9](_a_v_screen_capture.md) = 10, [OH_VIDEO_CODEC_FORMAT_BUTT](_a_v_screen_capture.md)<br>} | Enumerates the video encoding formats.| 
| [OH_DataType](_a_v_screen_capture.md#oh_datatype) { [OH_ORIGINAL_STREAM](_a_v_screen_capture.md) = 0, [OH_ENCODED_STREAM](_a_v_screen_capture.md) = 1, [OH_CAPTURE_FILE](_a_v_screen_capture.md) = 2, OH_INVAILD = -1 } | Enumerates the data sources of screen capture streams.| 
| [OH_VideoSourceType](_a_v_screen_capture.md#oh_videosourcetype) { [OH_VIDEO_SOURCE_SURFACE_YUV](_a_v_screen_capture.md) = 0, [OH_VIDEO_SOURCE_SURFACE_ES](_a_v_screen_capture.md), [OH_VIDEO_SOURCE_SURFACE_RGBA](_a_v_screen_capture.md), [OH_VIDEO_SOURCE_BUTT](_a_v_screen_capture.md) } | Enumerates the video source formats.| 
| [OH_ContainerFormatType](_a_v_screen_capture.md#oh_containerformattype) { [CFT_MPEG_4A](_a_v_screen_capture.md) = 0, [CFT_MPEG_4](_a_v_screen_capture.md) = 1 } | Enumerates the types of files generated during screen capture.<br>**NOTE**: This enum is reserved and will be provided in later versions.| 
