# AVScreenCapture


## Overview

The AVScreenCapture module provides APIs for screen capture.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [native_avscreen_capture.h](native__avscreen__capture_8h.md) | Declares the APIs used to create an **OH_AVScreenCapture** instance.| 
| [native_avscreen_capture_base.h](native__avscreen__capture__base_8h.md) | Declares the common structs, character constants, and enums used for running screen capture.| 
| [native_avscreen_capture_errors.h](native__avscreen__capture__errors_8h.md) | Declares the error codes generated during screen capture.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [OH_AudioCaptureInfo](_o_h___audio_capture_info.md) | Describes the audio capture information.| 
| struct  [OH_AudioEncInfo](_o_h___audio_enc_info.md) | Describes the audio encoding information.| 
| struct  [OH_AudioInfo](_o_h___audio_info.md) | Describes the audio information.| 
| struct  [OH_VideoCaptureInfo](_o_h___video_capture_info.md) | Describes the video capture information.| 
| struct  [OH_VideoEncInfo](_o_h___video_enc_info.md) | Describes the video encoding information.| 
| struct  [OH_VideoInfo](_o_h___video_info.md) |Describes the video information.| 
| struct  [OH_RecorderInfo](_o_h___recorder_info.md) | Describes the recording file information.| 
| struct  [OH_AVScreenCaptureConfig](_o_h___a_v_screen_capture_config.md) | Describes the screen capture configuration.| 
| struct  [OH_AVScreenCaptureCallback](_o_h___a_v_screen_capture_callback.md) | Describes all the asynchronous callback function pointers of an **OH_AVScreenCapture** instance.| 
| struct  [OH_Rect](_o_h___rect.md) | Describes the width, height, and image information of the rectangle used for screen capture.| 
| struct  [OH_AudioBuffer](_o_h___audio_buffer.md) | Describes the configuration such as the size, type, and timestamp of audio data.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_NativeBuffer](#oh_nativebuffer) [OH_NativeBuffer](#oh_nativebuffer) | Defines the native video stream class for screen capture.| 
| typedef struct [OH_AVScreenCapture](#oh_avscreencapture) [OH_AVScreenCapture](#oh_avscreencapture) | Defines a screen capture instance used to obtain original video and audio streams.| 
| typedef struct [OH_AVScreenCapture_ContentFilter](#oh_avscreencapture_contentfilter) [OH_AVScreenCapture_ContentFilter](#oh_avscreencapture_contentfilter) | Defines a struct for the filter used to filter audio and video content.| 
| typedef enum [OH_CaptureMode](#oh_capturemode-1) [OH_CaptureMode](#oh_capturemode) | Defines an enum for the screen capture modes.| 
| typedef enum [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype-1) [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) | Defines an enum for the audio source types during screen capture.| 
| typedef enum [OH_AudioCodecFormat](#oh_audiocodecformat-1) [OH_AudioCodecFormat](#oh_audiocodecformat) | Defines an enum for the audio encoding formats.| 
| typedef enum [OH_VideoCodecFormat](#oh_videocodecformat-1) [OH_VideoCodecFormat](#oh_videocodecformat) | Defines an enum for the video encoding formats.| 
| typedef enum [OH_DataType](#oh_datatype-1) [OH_DataType](#oh_datatype) | Defines an enum for the data types of screen capture streams.| 
| typedef enum [OH_VideoSourceType](#oh_videosourcetype-1) [OH_VideoSourceType](#oh_videosourcetype) | Defines an enum for the video source formats.| 
| typedef enum [OH_ContainerFormatType](#oh_containerformattype-1) [OH_ContainerFormatType](#oh_containerformattype) | Defines an enum for the types of files generated during screen capture.| 
| typedef struct [OH_AudioCaptureInfo](_o_h___audio_capture_info.md) [OH_AudioCaptureInfo](#oh_audiocaptureinfo) | Defines a struct for the audio capture information.| 
| typedef struct [OH_AudioEncInfo](_o_h___audio_enc_info.md) [OH_AudioEncInfo](#oh_audioencinfo) | Defines a struct for the audio encoding information.| 
| typedef struct [OH_AudioInfo](_o_h___audio_info.md) [OH_AudioInfo](#oh_audioinfo) | Defines a struct for the audio information.| 
| typedef struct [OH_VideoCaptureInfo](_o_h___video_capture_info.md) [OH_VideoCaptureInfo](#oh_videocaptureinfo) | Defines a struct for the video capture information.| 
| typedef struct [OH_VideoEncInfo](_o_h___video_enc_info.md) [OH_VideoEncInfo](#oh_videoencinfo) | Defines a struct for the video encoding information.| 
| typedef struct [OH_VideoInfo](_o_h___video_info.md) [OH_VideoInfo](#oh_videoinfo) | Defines a struct for the video information.| 
| typedef struct [OH_RecorderInfo](_o_h___recorder_info.md) [OH_RecorderInfo](#oh_recorderinfo) | Defines a struct for the recording file information.| 
| typedef struct [OH_AVScreenCaptureConfig](_o_h___a_v_screen_capture_config.md) [OH_AVScreenCaptureConfig](#oh_avscreencaptureconfig) | Defines a struct for the screen capture configuration.| 
| typedef void(\* [OH_AVScreenCaptureOnError](#oh_avscreencaptureonerror)) ([OH_AVScreenCapture](#oh_avscreencapture) \*capture, int32_t errorCode) | Defines a pointer to a callback function that is called when an error occurs during the running of an **OH_AVScreenCapture** instance.| 
| typedef void(\* [OH_AVScreenCaptureOnAudioBufferAvailable](#oh_avscreencaptureonaudiobufferavailable)) ([OH_AVScreenCapture](#oh_avscreencapture) \*capture, bool isReady, [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) type) | Defines a pointer to a callback function that is called when an audio buffer is available during the running of an **OH_AVScreenCapture** instance.| 
| typedef void(\* [OH_AVScreenCaptureOnVideoBufferAvailable](#oh_avscreencaptureonvideobufferavailable)) ([OH_AVScreenCapture](#oh_avscreencapture) \*capture, bool isReady) | Defines a pointer to a callback function that is called when a video buffer is available during the running of an **OH_AVScreenCapture** instance.| 
| typedef struct [OH_AVScreenCaptureCallback](_o_h___a_v_screen_capture_callback.md) [OH_AVScreenCaptureCallback](#oh_avscreencapturecallback) | Defines a struct for all the asynchronous callback function pointers of an **OH_AVScreenCapture** instance.| 
| typedef struct [OH_Rect](_o_h___rect.md) [OH_Rect](#oh_rect) | Defines a struct for the width, height, and image information of the rectangle used for screen capture.| 
| typedef struct [OH_AudioBuffer](_o_h___audio_buffer.md) [OH_AudioBuffer](#oh_audiobuffer) | Defines a struct for the configuration such as the size, type, and timestamp of audio data.| 
| typedef enum [OH_AVScreenCaptureStateCode](#oh_avscreencapturestatecode-1) [OH_AVScreenCaptureStateCode](#oh_avscreencapturestatecode) | Defines an enum for the screen capture states.| 
| typedef enum [OH_AVScreenCaptureBufferType](#oh_avscreencapturebuffertype-1) [OH_AVScreenCaptureBufferType](#oh_avscreencapturebuffertype) | Defines an enum for the buffer types.| 
| typedef enum [OH_AVScreenCaptureFilterableAudioContent](#oh_avscreencapturefilterableaudiocontent-1) [OH_AVScreenCaptureFilterableAudioContent](#oh_avscreencapturefilterableaudiocontent) | Defines an enum for the types of audio that can be added to a content filter.| 
| typedef void(\* [OH_AVScreenCapture_OnStateChange](#oh_avscreencapture_onstatechange)) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, [OH_AVScreenCaptureStateCode](#oh_avscreencapturestatecode) stateCode, void \*userData) | Defines a pointer to a callback function that is called when the state changes during the running of an **OH_AVScreenCapture** instance.| 
| typedef void(\* [OH_AVScreenCapture_OnError](#oh_avscreencapture_onerror)) ([OH_AVScreenCapture](#oh_avscreencapture) \*capture, int32_t errorCode, void \*userData) | Defines a pointer to a callback function that is called when an error occurs during the running of an **OH_AVScreenCapture** instance.| 
| typedef void(\* [OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)) ([OH_AVScreenCapture](#oh_avscreencapture) \*capture, OH_AVBuffer \*buffer, [OH_AVScreenCaptureBufferType](#oh_avscreencapturebuffertype) bufferType, int64_t timestamp, void \*userData) | Defines a pointer to a callback function that is called when an audio or a video buffer is available during the running of an **OH_AVScreenCapture** instance.| 
| typedef enum [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1) [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) | Defines an enum for the error codes generated during screen recording.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_CaptureMode](#oh_capturemode-1) {<br>OH_CAPTURE_HOME_SCREEN = 0,<br>OH_CAPTURE_SPECIFIED_SCREEN = 1,<br>OH_CAPTURE_SPECIFIED_WINDOW = 2,<br>OH_CAPTURE_INVAILD = -1<br>} | Enumerates the screen capture modes.| 
| [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype-1) {<br>OH_SOURCE_INVALID = -1,<br>OH_SOURCE_DEFAULT = 0,<br>OH_MIC = 1,<br>OH_ALL_PLAYBACK = 2,<br>OH_APP_PLAYBACK = 3<br>} | Enumerates the audio source types during screen capture.| 
| [OH_AudioCodecFormat](#oh_audiocodecformat-1) {<br>OH_AUDIO_DEFAULT = 0,<br>OH_AAC_LC = 3,<br>OH_AUDIO_CODEC_FORMAT_BUTT<br>} | Enumerates the audio encoding formats.| 
| [OH_VideoCodecFormat](#oh_videocodecformat-1) {<br>OH_VIDEO_DEFAULT = 0,<br>OH_H264 = 2,<br>OH_H265 = 4,<br>OH_MPEG4 = 6,<br>OH_VP8 = 8,<br>OH_VP9 = 10,<br>OH_VIDEO_CODEC_FORMAT_BUTT<br>} | Enumerates the video encoding formats.| 
| [OH_DataType](#oh_datatype-1) {<br>OH_ORIGINAL_STREAM = 0,<br>OH_ENCODED_STREAM = 1,<br>OH_CAPTURE_FILE = 2,<br>OH_INVAILD = -1<br>} | Enumerates the data types of screen capture streams.| 
| [OH_VideoSourceType](#oh_videosourcetype-1) {<br>OH_VIDEO_SOURCE_SURFACE_YUV = 0,<br>OH_VIDEO_SOURCE_SURFACE_ES,<br>OH_VIDEO_SOURCE_SURFACE_RGBA,<br>OH_VIDEO_SOURCE_BUTT<br>} | Enumerates the video source formats.| 
| [OH_ContainerFormatType](#oh_containerformattype) {<br>CFT_MPEG_4A = 0,<br>CFT_MPEG_4 = 1<br>} | Enumerates the types of files generated during screen capture.| 
| [OH_AVScreenCaptureStateCode](#oh_avscreencapturestatecode-1) {<br>OH_SCREEN_CAPTURE_STATE_STARTED = 0,<br>OH_SCREEN_CAPTURE_STATE_CANCELED = 1,<br>OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER = 2,<br>OH_SCREEN_CAPTURE_STATE_INTERRUPTED_BY_OTHER = 3,<br>OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL = 4,<br>OH_SCREEN_CAPTURE_STATE_MIC_UNAVAILABLE = 5,<br>OH_SCREEN_CAPTURE_STATE_MIC_MUTED_BY_USER = 6,<br>OH_SCREEN_CAPTURE_STATE_MIC_UNMUTED_BY_USER = 7,<br>OH_SCREEN_CAPTURE_STATE_ENTER_PRIVATE_SCENE = 8,<br>OH_SCREEN_CAPTURE_STATE_EXIT_PRIVATE_SCENE = 9<br>OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER_SWITCHES = 10<br>} | Enumerates the screen capture states.| 
| [OH_AVScreenCaptureBufferType](#oh_avscreencapturebuffertype-1) {<br>OH_SCREEN_CAPTURE_BUFFERTYPE_VIDEO = 0,<br>OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_INNER = 1,<br>OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_MIC = 2<br>} | Enumerates the buffer types.| 
| [OH_AVScreenCaptureFilterableAudioContent](#oh_avscreencapturefilterableaudiocontent-1) {<br>OH_SCREEN_CAPTURE_NOTIFICATION_AUDIO = 0, <br>OH_SCREEN_CAPTURE_CURRENT_APP_AUDIO = 1 <br>} | Enumerates the types of audio that can be added to a content filter. | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1) {<br>AV_SCREEN_CAPTURE_ERR_BASE = 0,<br>AV_SCREEN_CAPTURE_ERR_OK = AV_SCREEN_CAPTURE_ERR_BASE,<br>AV_SCREEN_CAPTURE_ERR_NO_MEMORY = AV_SCREEN_CAPTURE_ERR_BASE + 1,<br>AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT = AV_SCREEN_CAPTURE_ERR_BASE + 2,<br>AV_SCREEN_CAPTURE_ERR_INVALID_VAL = AV_SCREEN_CAPTURE_ERR_BASE + 3,<br>AV_SCREEN_CAPTURE_ERR_IO = AV_SCREEN_CAPTURE_ERR_BASE + 4,<br>AV_SCREEN_CAPTURE_ERR_TIMEOUT = AV_SCREEN_CAPTURE_ERR_BASE + 5,<br>AV_SCREEN_CAPTURE_ERR_UNKNOWN = AV_SCREEN_CAPTURE_ERR_BASE + 6,<br>AV_SCREEN_CAPTURE_ERR_SERVICE_DIED = AV_SCREEN_CAPTURE_ERR_BASE + 7,<br>AV_SCREEN_CAPTURE_ERR_INVALID_STATE = AV_SCREEN_CAPTURE_ERR_BASE + 8,<br>AV_SCREEN_CAPTURE_ERR_UNSUPPORT = AV_SCREEN_CAPTURE_ERR_BASE + 9,<br>AV_SCREEN_CAPTURE_ERR_EXTEND_START = AV_SCREEN_CAPTURE_ERR_BASE + 100<br>} | Enumerates the error codes generated during screen recording.| 


### Functions

| Name| Description| 
| -------- | -------- |
| struct [OH_AVScreenCapture](#oh_avscreencapture) \* [OH_AVScreenCapture_Create](#oh_avscreencapture_create) (void) | Creates an **OH_AVScreenCapture** instance. | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_Init](#oh_avscreencapture_init) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, [OH_AVScreenCaptureConfig](_o_h___a_v_screen_capture_config.md) config) | Initializes parameters related to an **OH_AVScreenCapture** instance, including audio sampling parameters for external capture using microphones (optional), audio sampling parameters for internal capture, and video resolution parameters. | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_StartScreenCapture](#oh_avscreencapture_startscreencapture) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | Starts screen capture and collects original streams. | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_StartScreenCaptureWithSurface](#oh_avscreencapture_startscreencapturewithsurface) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, OHNativeWindow \*window) | Starts screen capture in surface mode. | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_StopScreenCapture](#oh_avscreencapture_stopscreencapture) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | Stops screen capture. This function is used in pair with **OH_AVScreenCapture_StartScreenCapture**. | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_StartScreenRecording](#oh_avscreencapture_startscreenrecording) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | Starts screen recording, with recordings saved in files. | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_StopScreenRecording](#oh_avscreencapture_stopscreenrecording) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | Stops screen recording. This function is used in pair with **OH_AVScreenCapture_StartScreenRecording**.| 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_AcquireAudioBuffer](#oh_avscreencapture_acquireaudiobuffer) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, [OH_AudioBuffer](_o_h___audio_buffer.md) \*\*audiobuffer, [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) type) | Obtains an audio buffer. When calling this function, the application must allocate the memory of the corresponding struct size to the audio buffer. | 
| [OH_NativeBuffer](#oh_nativebuffer) \* [OH_AVScreenCapture_AcquireVideoBuffer](#oh_avscreencapture_acquirevideobuffer) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, int32_t \*fence, int64_t \*timestamp, struct [OH_Rect](_o_h___rect.md) \*region) | Obtains a video buffer. An application can call this function to obtain information such as the video buffer and timestamp. | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_ReleaseAudioBuffer](#oh_avscreencapture_releaseaudiobuffer) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) type) | Releases an audio buffer. | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_ReleaseVideoBuffer](#oh_avscreencapture_releasevideobuffer) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | Releases a video buffer. After the video buffer is no longer needed, call this function to release it. | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SetCallback](#oh_avscreencapture_setcallback) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, struct [OH_AVScreenCaptureCallback](_o_h___a_v_screen_capture_callback.md) callback) | Sets a callback to listen for available video buffers and audio buffers and errors that occur during the function calling. | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_Release](#oh_avscreencapture_release) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | Releases an **OH_AVScreenCapture** instance. This function is used in pair with **OH_AVScreenCapture_Create**. | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SetMicrophoneEnabled](#oh_avscreencapture_setmicrophoneenabled) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, bool isMicrophone) | Enables or disables the microphone. | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SetStateCallback](#oh_avscreencapture_setstatecallback) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, [OH_AVScreenCapture_OnStateChange](#oh_avscreencapture_onstatechange) callback, void \*userData) | Sets a state change callback. This function must be called before screen capture starts. | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SetDataCallback](#oh_avscreencapture_setdatacallback) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, [OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable) callback, void \*userData) | Sets a data processing callback. This function must be called before screen capture starts. | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SetErrorCallback](#oh_avscreencapture_seterrorcallback) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, [OH_AVScreenCapture_OnError](#oh_avscreencapture_onerror) callback, void \*userData) | Sets an error processing callback. This function must be called before screen capture starts. | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SetCanvasRotation](#oh_avscreencapture_setcanvasrotation) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, bool canvasRotation) | Sets canvas rotation for screen capture. | 
| struct [OH_AVScreenCapture_ContentFilter](#oh_avscreencapture_contentfilter) \* [OH_AVScreenCapture_CreateContentFilter](#oh_avscreencapture_createcontentfilter) (void) | Creates a content filter. | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_ReleaseContentFilter](#oh_avscreencapture_releasecontentfilter) (struct [OH_AVScreenCapture_ContentFilter](#oh_avscreencapture_contentfilter) \*filter) | Releases a content filter. | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_ContentFilter_AddAudioContent](#oh_avscreencapture_contentfilter_addaudiocontent) (struct [OH_AVScreenCapture_ContentFilter](#oh_avscreencapture_contentfilter) \*filter, [OH_AVScreenCaptureFilterableAudioContent](#oh_avscreencapturefilterableaudiocontent) content) | Adds audio content to a content filter. | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_ExcludeContent](#oh_avscreencapture_excludecontent) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, struct [OH_AVScreenCapture_ContentFilter](#oh_avscreencapture_contentfilter) \*filter) | Sets a content filter for an **OH_AVScreenCapture** instance. | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_ContentFilter_AddWindowContent](#oh_avscreencapture_contentfilter_addwindowcontent) (struct [OH_AVScreenCapture_ContentFilter](#oh_avscreencapture_contentfilter) \*filter, int32_t \*windowIDs, int32_t windowCount) | Adds a list of window IDs to a **ContentFilter** instance. | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_ResizeCanvas](#oh_avscreencapture_resizecanvas) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, int32_t width, int32_t height) | Adjusts the screen resolution. | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SkipPrivacyMode](#oh_avscreencapture_skipprivacymode) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, int32_t \*windowIDs, int32_t windowCount) | Exempts privacy windows during screen capture. | 


## Type Description


### OH_AudioBuffer

```
typedef struct OH_AudioBuffer OH_AudioBuffer
```

**Description**

Defines a struct for the configuration such as the size, type, and timestamp of audio data.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


### OH_AudioCaptureInfo

```
typedef struct OH_AudioCaptureInfo OH_AudioCaptureInfo
```

**Description**

Defines a struct for the audio capture information.

When both **audioSampleRate** and **audioChannels** are **0**, the audio-related parameters are ignored and the audio data is not recorded.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


### OH_AudioCaptureSourceType

```
typedef enum OH_AudioCaptureSourceType OH_AudioCaptureSourceType
```

**Description**

Defines an enum for the audio source types during screen capture.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


### OH_AudioCodecFormat

```
typedef enum OH_AudioCodecFormat OH_AudioCodecFormat
```

**Description**

Defines an enum for the audio encoding formats.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


### OH_AudioEncInfo

```
typedef struct OH_AudioEncInfo OH_AudioEncInfo
```

**Description**

Defines a struct for the audio encoding information.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


### OH_AudioInfo

```
typedef struct OH_AudioInfo OH_AudioInfo
```

**Description**

Defines a struct for the audio information.

To perform both external capture (using microphones) and internal capture, **audioSampleRate** and **audioChannels** must be the same for both audio channels.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


### OH_AVSCREEN_CAPTURE_ErrCode

```
typedef enum OH_AVSCREEN_CAPTURE_ErrCode OH_AVSCREEN_CAPTURE_ErrCode
```

**Description**

Defines an enum for the error codes generated during screen recording.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


### OH_AVScreenCapture

```
typedef struct OH_AVScreenCaptureOH_AVScreenCapture
```

**Description**

Defines a screen capture instance used to obtain original video and audio streams.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


### OH_AVScreenCapture_ContentFilter

```
typedef struct OH_AVScreenCapture_ContentFilterOH_AVScreenCapture_ContentFilter
```

**Description**

Defines a struct for the filter used to filter audio and video content.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12


### OH_AVScreenCapture_OnBufferAvailable

```
typedef void(* OH_AVScreenCapture_OnBufferAvailable) (OH_AVScreenCapture *capture, OH_AVBuffer *buffer, OH_AVScreenCaptureBufferType bufferType, int64_t timestamp, void *userData)
```

**Description**

Defines a pointer to a callback function that is called when an audio or a video buffer is available during the running of an **OH_AVScreenCapture** instance.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an **OH_AVScreenCapture** instance. | 
| buffer | Pointer to the **OH_AVBuffer** instance. After the callback is triggered, the buffer is no longer valid. | 
| bufferType | Type of the buffer. | 
| timestamp | Timestamp, in nanoseconds. | 
| userData | Pointer to the user-defined data carried in the function.| 


### OH_AVScreenCapture_OnError

```
typedef void(* OH_AVScreenCapture_OnError) (OH_AVScreenCapture *capture, int32_t errorCode, void *userData)
```

**Description**

Defines a pointer to a callback function that is called when an error occurs during the running of an **OH_AVScreenCapture** instance.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an **OH_AVScreenCapture** instance. | 
| errorCode | Error code. | 
| userData | Pointer to the user-defined data carried in the function.| 


### OH_AVScreenCapture_OnStateChange

```
typedef void(* OH_AVScreenCapture_OnStateChange) (struct OH_AVScreenCapture *capture, OH_AVScreenCaptureStateCode stateCode, void *userData)
```

**Description**

Defines a pointer to a callback function that is called when the state changes during the running of an **OH_AVScreenCapture** instance.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an **OH_AVScreenCapture** instance. | 
| stateCode | Status code. | 
| userData | Pointer to the user-defined data carried in the function.| 


### OH_AVScreenCaptureBufferType

```
typedef enum OH_AVScreenCaptureBufferTypeOH_AVScreenCaptureBufferType
```

**Description**

Defines an enum for the buffer types.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12


### OH_AVScreenCaptureCallback

```
typedef struct OH_AVScreenCaptureCallback OH_AVScreenCaptureCallback
```

**Description**

Defines a struct for all the asynchronous callback function pointers of an **OH_AVScreenCapture** instance. To ensure the normal running of **OH_AVScreenCapture**, you must register the instance of this struct with the **OH_AVScreenCapture** instance and process the information reported by the callback functions.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Deprecated from**: 12

**Substitute APIs**

[OH_AVScreenCapture_OnError](#oh_avscreencapture_onerror) and [OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)

**Parameters**

| Name| Description| 
| -------- | -------- |
| onError | Pointer to a callback function that is called when an error occurs during the running of an **OH_AVScreenCapture** instance. For details, see [OH_AVScreenCaptureOnError](#oh_avscreencaptureonerror).| 
| onAudioBufferAvailable | Pointer to a callback function that is called when an audio buffer is available during the running of an **OH_AVScreenCapture** instance. For details, see [OH_AVScreenCaptureOnAudioBufferAvailable](#oh_avscreencaptureonaudiobufferavailable).| 
| onVideoBufferAvailable | Pointer to a callback function that is called when a video buffer is available during the running of an **OH_AVScreenCapture** instance. For details, see [OH_AVScreenCaptureOnVideoBufferAvailable](#oh_avscreencaptureonvideobufferavailable).| 


### OH_AVScreenCaptureConfig

```
typedef struct OH_AVScreenCaptureConfig OH_AVScreenCaptureConfig
```

**Description**

Defines a struct for the screen capture configuration.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


### OH_AVScreenCaptureFilterableAudioContent

```
typedef enum OH_AVScreenCaptureFilterableAudioContent OH_AVScreenCaptureFilterableAudioContent
```

**Description**

Defines an enum for the types of audio that can be added to a content filter.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12


### OH_AVScreenCaptureOnAudioBufferAvailable

```
typedef void(* OH_AVScreenCaptureOnAudioBufferAvailable) (OH_AVScreenCapture *capture, bool isReady, OH_AudioCaptureSourceType type)
```

**Description**

Defines a pointer to a callback function that is called when an audio buffer is available during the running of an **OH_AVScreenCapture** instance.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Deprecated from**: 12

**Substitute API**: [OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an **OH_AVScreenCapture** instance. | 
| isReady | Whether the audio buffer is available. | 
| type | Audio source type.| 


### OH_AVScreenCaptureOnError

```
typedef void(* OH_AVScreenCaptureOnError) (OH_AVScreenCapture *capture, int32_t errorCode)
```

**Description**

Defines a pointer to a callback function that is called when an error occurs during the running of an **OH_AVScreenCapture** instance.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Deprecated from**: 12

**Substitute API**: [OH_AVScreenCapture_OnError](#oh_avscreencapture_onerror)

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an **OH_AVScreenCapture** instance. | 
| errorCode | Error code.| 


### OH_AVScreenCaptureOnVideoBufferAvailable

```
typedef void(* OH_AVScreenCaptureOnVideoBufferAvailable) (OH_AVScreenCapture *capture, bool isReady)
```

**Description**

Defines a pointer to a callback function that is called when a video buffer is available during the running of an **OH_AVScreenCapture** instance.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Deprecated from**: 12

**Substitute API**: [OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an **OH_AVScreenCapture** instance. | 
| isReady | Whether the video buffer is available.| 


### OH_AVScreenCaptureStateCode

```
typedef enum OH_AVScreenCaptureStateCode OH_AVScreenCaptureStateCode
```

**Description**

Defines an enum for the screen capture states.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12


### OH_CaptureMode

```
typedef enum OH_CaptureMode OH_CaptureMode
```

**Description**

Defines an enum for the screen capture modes.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


### OH_ContainerFormatType

```
typedef enum OH_ContainerFormatType OH_ContainerFormatType
```

**Description**

Defines an enum for the types of files generated during screen capture.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


### OH_DataType

```
typedef enum OH_DataType OH_DataType
```

**Description**

Defines an enum for the data types of screen capture streams.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


### OH_NativeBuffer

```
typedef struct OH_NativeBuffer OH_NativeBuffer
```

**Description**

Defines the native video stream class for screen capture.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


### OH_RecorderInfo

```
typedef struct OH_RecorderInfo OH_RecorderInfo
```

**Description**

Defines a struct for the recording file information.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


### OH_Rect

```
typedef struct OH_Rect OH_Rect
```

**Description**

Defines a struct for the width, height, and image information of the rectangle used for screen capture.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


### OH_VideoCaptureInfo

```
typedef struct OH_VideoCaptureInfo OH_VideoCaptureInfo
```

**Description**

Defines a struct for the video capture information.

When **videoFrameWidth** and **videoFrameHeight** are both **0**, video-related parameters are ignored and screen data is not recorded.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


### OH_VideoCodecFormat

```
typedef enum OH_VideoCodecFormat OH_VideoCodecFormat
```

**Description**

Defines an enum for the video encoding formats.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


### OH_VideoEncInfo

```
typedef struct OH_VideoEncInfo OH_VideoEncInfo
```

**Description**

Defines a struct for the video encoding information.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


### OH_VideoInfo

```
typedef struct OH_VideoInfo OH_VideoInfo
```

**Description**

Defines a struct for the video information.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


### OH_VideoSourceType

```
typedef enum OH_VideoSourceType OH_VideoSourceType
```

**Description**

Defines an enum for the video source formats.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


## Enum Description


### OH_AudioCaptureSourceType

```
enum OH_AudioCaptureSourceType
```

**Description**

Enumerates the audio source types during screen capture.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

| Value| Description| 
| -------- | -------- |
| OH_SOURCE_INVALID  | Invalid audio source.  | 
| OH_SOURCE_DEFAULT  | Default audio source. The default value is **MIC**.  | 
| OH_MIC  | External audio streams recorded by the microphone.  | 
| OH_ALL_PLAYBACK  | All internal audio streams played by the system.  | 
| OH_APP_PLAYBACK  | Internal audio streams played by a specified application.  | 


### OH_AudioCodecFormat

```
enum OH_AudioCodecFormat
```

**Description**

Enumerates the audio encoding formats.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

| Value| Description| 
| -------- | -------- |
| OH_AUDIO_DEFAULT  | Default audio encoding format. The default value is **AAC_LC**.  | 
| OH_AAC_LC  | AAC_LC audio encoding.  | 
| OH_AUDIO_CODEC_FORMAT_BUTT  | Invalid format.  | 


### OH_AVSCREEN_CAPTURE_ErrCode

```
enum OH_AVSCREEN_CAPTURE_ErrCode
```

**Description**

Enumerates the error codes generated during screen recording.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

| Value| Description| 
| -------- | -------- |
| AV_SCREEN_CAPTURE_ERR_BASE | Basic value returned when an API call error occurs.| 
| AV_SCREEN_CAPTURE_ERR_OK | Operation successful.| 
| AV_SCREEN_CAPTURE_ERR_NO_MEMORY | Memory insufficient.| 
| AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT | Operation not allowed.| 
| AV_SCREEN_CAPTURE_ERR_INVALID_VAL | Invalid parameter.| 
| AV_SCREEN_CAPTURE_ERR_IO | Abnormal input and output streams.| 
| AV_SCREEN_CAPTURE_ERR_TIMEOUT | Network timeout.| 
| AV_SCREEN_CAPTURE_ERR_UNKNOWN | Unknown error.| 
| AV_SCREEN_CAPTURE_ERR_SERVICE_DIED | Media service terminated.| 
| AV_SCREEN_CAPTURE_ERR_INVALID_STATE | Unsupported operation in this state.| 
| AV_SCREEN_CAPTURE_ERR_UNSUPPORT | Unsupported interface.| 
| AV_SCREEN_CAPTURE_ERR_EXTEND_START | Unexpected error.| 


### OH_AVScreenCaptureBufferType

```
enum OH_AVScreenCaptureBufferType
```

**Description**

Enumerates the buffer types.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12

| Value| Description| 
| -------- | -------- |
| OH_SCREEN_CAPTURE_BUFFERTYPE_VIDEO  | Video data.  | 
| OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_INNER  | Internal audio capture data.  | 
| OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_MIC  | Microphone audio data.  | 


### OH_AVScreenCaptureFilterableAudioContent

```
enum OH_AVScreenCaptureFilterableAudioContent
```

**Description**

Enumerates the types of audio that can be added to a content filter.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12

| Value| Description| 
| -------- | -------- |
| OH_SCREEN_CAPTURE_NOTIFICATION_AUDIO  | Notification tone.  | 
| OH_SCREEN_CAPTURE_CURRENT_APP_AUDIO  | Sound of the application itself.  | 


### OH_AVScreenCaptureStateCode

```
enum OH_AVScreenCaptureStateCode
```

**Description**

Enumerates the screen capture states.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12

| Value| Description| 
| -------- | -------- |
| OH_SCREEN_CAPTURE_STATE_STARTED  | Screen capture is started.  | 
| OH_SCREEN_CAPTURE_STATE_CANCELED  | Screen capture is canceled.  | 
| OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER  | Screen capture is stopped.  | 
| OH_SCREEN_CAPTURE_STATE_INTERRUPTED_BY_OTHER  | Screen capture is interrupted by another screen capture.  | 
| OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL  | Screen capture is interrupted by a call.  | 
| OH_SCREEN_CAPTURE_STATE_MIC_UNAVAILABLE  | The microphone is unavailable.  | 
| OH_SCREEN_CAPTURE_STATE_MIC_MUTED_BY_USER  | The microphone is muted. This value is not supported yet.  | 
| OH_SCREEN_CAPTURE_STATE_MIC_UNMUTED_BY_USER  | The microphone is unmuted. This value is not supported yet.  | 
| OH_SCREEN_CAPTURE_STATE_ENTER_PRIVATE_SCENE  | The system enters a privacy dialog box. This value is not supported yet.  | 
| OH_SCREEN_CAPTURE_STATE_EXIT_PRIVATE_SCENE  | The system exits a privacy dialog box. This value is not supported yet.  | 
| OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER_SWITCHES   | Screen capture is interrupted by system user switching.| 


### OH_CaptureMode

```
enum OH_CaptureMode
```

**Description**

Enumerates the screen capture modes.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

| Value| Description| 
| -------- | -------- |
| OH_CAPTURE_HOME_SCREEN  | Captures the home screen.  | 
| OH_CAPTURE_SPECIFIED_SCREEN  | Captures a specified screen.  | 
| OH_CAPTURE_SPECIFIED_WINDOW  | Captures a specified window.  | 
| OH_CAPTURE_INVAILD  | Invalid mode.  | 


### OH_ContainerFormatType

```
enum OH_ContainerFormatType
```

**Description**

Enumerates the types of files generated during screen capture.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

| Value| Description| 
| -------- | -------- |
| CFT_MPEG_4A  | Audio format M4A.  | 
| CFT_MPEG_4  | Video format MP4.  | 


### OH_DataType

```
enum OH_DataType
```

**Description**

Enumerates the data types of screen capture streams.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

| Value| Description| 
| -------- | -------- |
| OH_ORIGINAL_STREAM  | Original stream format, such as YUV, RGBA, and PCM.  | 
| OH_ENCODED_STREAM  | Encoded stream format, such as H.264 and AAC. This value is not supported yet.  | 
| OH_CAPTURE_FILE  | Format of the recording file. The value can be **mp4**.  | 
| OH_INVAILD  | Invalid format.  | 


### OH_VideoCodecFormat

```
enum OH_VideoCodecFormat
```

**Description**

Enumerates the video encoding formats.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

| Value| Description| 
| -------- | -------- |
| OH_VIDEO_DEFAULT | Default video encoding format. The default value is **H.264**.| 
| OH_H264 | H.264.| 
| OH_H265 | H.265/HEVC.| 
| OH_MPEG4 | MPEG4.| 
| OH_VP8 | VP8.| 
| OH_VP9 | VP9.| 
| OH_VIDEO_CODEC_FORMAT_BUTT | Invalid format.| 


### OH_VideoSourceType

```
enum OH_VideoSourceType
```

**Description**

Enumerates the video source formats.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

| Value| Description| 
| -------- | -------- |
| OH_VIDEO_SOURCE_SURFACE_YUV  | YUV format.  | 
| OH_VIDEO_SOURCE_SURFACE_ES  | Raw format.  | 
| OH_VIDEO_SOURCE_SURFACE_RGBA  | RGBA format.  | 
| OH_VIDEO_SOURCE_BUTT  | Invalid format.  | 


## Function Description


### OH_AVScreenCapture_AcquireAudioBuffer()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_AcquireAudioBuffer (struct OH_AVScreenCapture * capture, OH_AudioBuffer ** audiobuffer, OH_AudioCaptureSourceType type )
```

**Description**

Obtains an audio buffer. When calling this function, the application must allocate the memory of the corresponding struct size to the audio buffer.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Deprecated from**: 12

**Substitute API**: [OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an [OH_AVScreenCapture](#oh_avscreencapture) instance.| 
| audiobuffer | Pointer to the struct for storing the audio buffer. This struct is used to obtain the information about the audio buffer and the timestamp of the buffer.| 
| type | Type of the audio buffer, which is used to distinguish external streams recorded by the microphone from internal streams played by the system. For details, see [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype).| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.

**AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** or **audiobuffer** is a null pointer.

**AV_SCREEN_CAPTURE_ERR_NO_MEMORY**: The audio buffer fails to be allocated due to insufficient memory.

**AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The privacy permission fails to be enabled or the audio buffer fails to be obtained.



### OH_AVScreenCapture_AcquireVideoBuffer()

```
OH_NativeBuffer* OH_AVScreenCapture_AcquireVideoBuffer (struct OH_AVScreenCapture * capture, int32_t * fence, int64_t * timestamp, struct OH_Rect * region )
```

**Description**

Obtains a video buffer. An application can call this function to obtain information such as the video buffer and timestamp. After the buffer is no longer needed, call [OH_AVScreenCapture_ReleaseVideoBuffer](#oh_avscreencapture_releasevideobuffer) to release it.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Deprecated from**: 12

**Substitute API**: [OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an [OH_AVScreenCapture](#oh_avscreencapture) instance. | 
| fence | Pointer to parameters for synchronization display. | 
| timestamp | Pointer to the timestamp of the video frame. | 
| region | Pointer to the coordinates related to video display. | 

**Returns**

Returns an **OH_NativeBuffer** object if the operation is successful. The application can call the APIs provided by the **OH_NativeBuffer** object to obtain information such as the video buffer and resolution.


### OH_AVScreenCapture_ContentFilter_AddAudioContent()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ContentFilter_AddAudioContent (struct OH_AVScreenCapture_ContentFilter * filter, OH_AVScreenCaptureFilterableAudioContent content )
```

**Description**

Adds audio content to a content filter.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| filter | Pointer to an [OH_AVScreenCapture_ContentFilter](#oh_avscreencapture_contentfilter) instance.| 
| content | [OH_AVScreenCaptureFilterableAudioContent](#oh_avscreencapturefilterableaudiocontent) instance.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.

**AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **filter** is a null pointer or the input parameter **content** is invalid.


### OH_AVScreenCapture_ContentFilter_AddWindowContent()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ContentFilter_AddWindowContent (struct OH_AVScreenCapture_ContentFilter *filter, int32_t *windowIDs, int32_t windowCount)
```

**Description**

Adds a list of window IDs to a **ContentFilter** instance.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| filter | Pointer to an **OH_AVScreenCapture_ContentFilter** instance. | 
| windowIDs | Pointer to the window IDs. | 
| windowCount | Length of the window ID list. | 

**Returns**

Returns **AV_SCREEN_CAPTURE_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1) otherwise.


### OH_AVScreenCapture_Create()

```
struct OH_AVScreenCapture* OH_AVScreenCapture_Create (void )
```

**Description**

Creates an **OH_AVScreenCapture** instance. You can release the instance by calling [OH_AVScreenCapture_Release](#oh_avscreencapture_release).

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Returns**

Returns the pointer to an [OH_AVScreenCapture](#oh_avscreencapture) instance.


### OH_AVScreenCapture_CreateContentFilter()

```
struct OH_AVScreenCapture_ContentFilter* OH_AVScreenCapture_CreateContentFilter (void )
```

**Description**

Creates a content filter.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12

**Returns**

Returns [OH_AVScreenCapture_ContentFilter](#oh_avscreencapture_contentfilter) if the operation is successful; returns a null pointer otherwise.


### OH_AVScreenCapture_ExcludeContent()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ExcludeContent (struct OH_AVScreenCapture * capture, struct OH_AVScreenCapture_ContentFilter * filter )
```

**Description**

Sets a content filter for an **OH_AVScreenCapture** instance.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an [OH_AVScreenCapture](#oh_avscreencapture) instance.| 
| filter | Pointer to an [OH_AVScreenCapture_ContentFilter](#oh_avscreencapture_contentfilter) instance.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.

**AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** or **filter** is a null pointer.

**AV_SCREEN_CAPTURE_ERR_UNSUPPORT**: The operation is not supported. For streams, the **AudioCapturer** API must be called for the operation to take effect during the start. For captured files, the **AudioRecorder** API must be called for the operation to take effect during the start.


### OH_AVScreenCapture_Init()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Init (struct OH_AVScreenCapture * capture, OH_AVScreenCaptureConfig config )
```

**Description**

Initializes parameters related to an [OH_AVScreenCapture](#oh_avscreencapture) instance, including audio sampling parameters for external capture using microphones (optional), audio sampling parameters for internal capture, and video resolution parameters.

In the scenario where screen recording files are stored, the application must ensure that the video encoding parameters, video sampling parameters, audio encoding parameters, audio sampling parameters for internal capture, and audio sampling parameters for external capture using microphones (optional) are valid.

In the scenario where screen capture streams are generated, the application must ensure that either audio sampling parameters for internal capture or video sampling parameters are valid, or both are valid, and audio sampling parameters for external capture using microphones are valid (optional).

The members of the struct variables are not initialized during initialization. Therefore, the application must correctly set the parameters based on the use scenario. You are advised to
set all memory bytes of the OH_AVScreenCaptureConfig struct variables to **0**, and then set valid parameters based on the screen capture scenario.

If both **audioSampleRate** and **audioChannels** in the [OH_AudioCaptureInfo](#oh_audiocaptureinfo) struct are **0**,
the **OH_AVScreenCapture** instance ignores the audio parameters of this type and does not collect the audio data of this type.

If both **videoFrameWidth** and **videoFrameHeight** in the [OH_AudioCaptureInfo](#oh_audiocaptureinfo) struct are **0**,
the **OH_AVScreenCapture** instance ignores the corresponding video parameters and does not collect screen data.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an [OH_AVScreenCapture](#oh_avscreencapture) instance.| 
| config | Parameters related to screen capture initialization.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.

**AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.

**AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The configuration fails to be initialized.


### OH_AVScreenCapture_Release()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Release (struct OH_AVScreenCapture * capture)
```

**Description**

Releases an **OH_AVScreenCapture** instance. This function is used in pair with [OH_AVScreenCapture_Create](#oh_avscreencapture_create).

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an [OH_AVScreenCapture](#oh_avscreencapture) instance.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.

**AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.

**AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The **OH_AVScreenCapture** instance fails to be released.

### OH_AVScreenCapture_ReleaseAudioBuffer()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseAudioBuffer (struct OH_AVScreenCapture * capture, OH_AudioCaptureSourceType type )
```

**Description**

Releases an audio buffer. After the audio buffer is no longer needed, call this function to release it.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Deprecated from**: 12

**Substitute API**: [OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an [OH_AVScreenCapture](#oh_avscreencapture) instance.| 
| type | Type of the audio buffer, which is used to distinguish external streams recorded by the microphone from internal streams played by the system.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.

**AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.

**AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The data callback has been set or the audio buffer fails to be released.


### OH_AVScreenCapture_ReleaseContentFilter()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseContentFilter (struct OH_AVScreenCapture_ContentFilter * filter)
```

**Description**

Releases a content filter.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| filter | Pointer to an [OH_AVScreenCapture_ContentFilter](#oh_avscreencapture_contentfilter) instance.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.

**AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **filter** is a null pointer.


### OH_AVScreenCapture_ReleaseVideoBuffer()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseVideoBuffer (struct OH_AVScreenCapture * capture)
```

**Description**

Releases a video buffer. After the video buffer is no longer needed, call this function to release it.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Deprecated from**: 12

**Substitute API**: [OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an [OH_AVScreenCapture](#oh_avscreencapture) instance.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.

**AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.

**AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The data callback has been set or the video buffer fails to be released.


### OH_AVScreenCapture_SetCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCallback (struct OH_AVScreenCapture * capture, struct OH_AVScreenCaptureCallback callback )
```

**Description**

Sets a callback to listen for available video buffers and audio buffers and errors that occur during the function calling.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Deprecated from**: 12

**Substitute API**: [OH_AVScreenCapture_SetErrorCallback](#oh_avscreencapture_seterrorcallback) and [OH_AVScreenCapture_SetDataCallback](#oh_avscreencapture_setdatacallback)

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an [OH_AVScreenCapture](#oh_avscreencapture) instance.| 
| callback | [OH_AVScreenCaptureCallback](_o_h___a_v_screen_capture_callback.md) struct, which stores related callback function pointers.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.

**AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** or **callback** is a null pointer.

**AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The callback fails to be set.


### OH_AVScreenCapture_SetCanvasRotation()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCanvasRotation (struct OH_AVScreenCapture * capture, bool canvasRotation )
```

**Description**

Sets canvas rotation for screen capture.

You can call this function to set whether to rotate the recorded screen data. When **canvasRotation** is set to **true**, screen capture rotation is enabled and the recorded screen data remains positive.

The default value is **false**.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an [OH_AVScreenCapture](#oh_avscreencapture) instance.| 
| canvasRotation | Whether to enable screen data rotation.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.

**AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.

**AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. Canvas rotation fails to be set for screen capture.


### OH_AVScreenCapture_SetDataCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetDataCallback (struct OH_AVScreenCapture * capture, OH_AVScreenCapture_OnBufferAvailable callback, void * userData )
```

**Description**

Sets a data processing callback. This function must be called before screen capture starts.

The callback is triggered when an audio buffer or a video buffer becomes available during the running of an **OH_AVScreenCapture** instance.

The application needs to process microphone audio, internal audio, and video data based on the data type in the callback. After the callback is triggered, the buffer is no longer valid.

A successful call to this function leads to the following scenarios:

- The callbacks [OH_AVScreenCaptureOnAudioBufferAvailable](#oh_avscreencaptureonaudiobufferavailable) and [OH_AVScreenCaptureOnVideoBufferAvailable](#oh_avscreencaptureonvideobufferavailable) set by calling [OH_AVScreenCapture_SetCallback](#oh_avscreencapture_setcallback) will no longer be triggered, even when an audio buffer or a video buffer becomes available.
- A failure message is returned for a call to any of the following functions: [OH_AVScreenCapture_AcquireAudioBuffer](#oh_avscreencapture_acquireaudiobuffer), [OH_AVScreenCapture_ReleaseAudioBuffer](#oh_avscreencapture_releaseaudiobuffer), [OH_AVScreenCapture_AcquireVideoBuffer](#oh_avscreencapture_acquirevideobuffer), and [OH_AVScreenCapture_ReleaseVideoBuffer](#oh_avscreencapture_releasevideobuffer).

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an [OH_AVScreenCapture](#oh_avscreencapture) instance.| 
| callback | Data processing callback, which is [OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable).| 
| userData | Pointer to the user-defined data. The data is returned as an input parameter when the data processing callback is triggered.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.

**AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** or **callback** is a null pointer.

**AV_SCREEN_CAPTURE_ERR_NO_MEMORY**: The memory fails to be allocated due to insufficient memory.

**AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The data callback fails to be set.


### OH_AVScreenCapture_SetErrorCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetErrorCallback (struct OH_AVScreenCapture * capture, OH_AVScreenCapture_OnError callback, void * userData )
```

**Description**

Sets an error processing callback. This function must be called before screen capture starts.

The callback is triggered when an error occurs during the running of an **OH_AVScreenCapture** instance.

After a successful call to this function, the callback [OH_AVScreenCaptureOnError](#oh_avscreencaptureonerror) set by calling [OH_AVScreenCapture_SetCallback](#oh_avscreencapture_setcallback) will no longer be triggered, even when an error occurs in the **OH_AVScreenCapture** instance.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an [OH_AVScreenCapture](#oh_avscreencapture) instance.| 
| callback | Error processing callback, which is [OH_AVScreenCapture_OnError](#oh_avscreencapture_onerror).| 
| userData | Pointer to the user-defined data. The data is returned as an input parameter when the error processing callback is triggered.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.

**AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** or **callback** is a null pointer.

**AV_SCREEN_CAPTURE_ERR_NO_MEMORY**: The memory fails to be allocated due to insufficient memory.

**AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The error callback fails to be set.


### OH_AVScreenCapture_SetMicrophoneEnabled()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetMicrophoneEnabled (struct OH_AVScreenCapture * capture, bool isMicrophone )
```

**Description**

Enables or disables the microphone. When **isMicrophone** is set to **true**, the microphone is enabled, and the original PCM data of the microphone can be obtained by calling [OH_AVScreenCapture_StartScreenCapture](#oh_avscreencapture_startscreencapture) and [OH_AVScreenCapture_AcquireAudioBuffer](#oh_avscreencapture_acquireaudiobuffer). When **isMicrophone** is set to **false**, the obtained audio data is silent data.

By default, the microphone is enabled.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an [OH_AVScreenCapture](#oh_avscreencapture) instance.| 
| isMicrophone | Whether to enable the microphone.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.

**AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.

**AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The microphone fails to be enabled or disabled.


### OH_AVScreenCapture_SetStateCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetStateCallback (struct OH_AVScreenCapture * capture, OH_AVScreenCapture_OnStateChange callback, void * userData )
```

**Description**

Sets a state change callback. This function must be called before screen capture starts.

The callback is triggered when the state changes during the running of an **OH_AVScreenCapture** instance.

A privacy dialog box is displayed to ask for user consent before screen capture starts. After a successful call to this function, the following scenarios are possible:

- If the user agrees, the screen capture startup process starts. 

  - If screen capture starts successfully, the state change callback is triggered to report the [OH_SCREEN_CAPTURE_STATE_STARTED](#oh_avscreencapturestatecode-1) status to notify the application of the startup success, with a screen capture notification displayed.

  - If screen capture fails to start, the state change callback is triggered to report the failure information (for example, [OH_SCREEN_CAPTURE_STATE_MIC_UNAVAILABLE](#oh_avscreencapturestatecode-1) if the microphone is unavailable), or the error processing callback [OH_AVScreenCapture_OnError](#oh_avscreencapture_onerror) is triggered to report the error information.

- If the user disagrees, the screen capture startup process stops. The state change callback is triggered to report the [OH_SCREEN_CAPTURE_STATE_CANCELED](#oh_avscreencapturestatecode-1) status to notify the application of the startup failure due to user rejection.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an [OH_AVScreenCapture](#oh_avscreencapture) instance.| 
| callback | State change callback, which is [OH_AVScreenCapture_OnStateChange](#oh_avscreencapture_onstatechange).| 
| userData | Pointer to the user-defined data. The data is returned as an input parameter when the state change callback is triggered.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.

**AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** or **callback** is a null pointer.

**AV_SCREEN_CAPTURE_ERR_NO_MEMORY**: The memory fails to be allocated due to insufficient memory.

**AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The state callback fails to be set.


### OH_AVScreenCapture_StartScreenCapture()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenCapture (struct OH_AVScreenCapture * capture)
```

**Description**

Starts screen capture and collects original streams. After this function is called, the callback ([OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)) can be used to check whether streams are generated, and the callback ([OH_AVScreenCapture_OnStateChange](#oh_avscreencapture_onstatechange)) can be used to check the startup status.

The application can obtain the original streams of screen capture by calling [OH_AVScreenCapture_AcquireAudioBuffer](#oh_avscreencapture_acquireaudiobuffer) and [OH_AVScreenCapture_ReleaseVideoBuffer](#oh_avscreencapture_releasevideobuffer).

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an [OH_AVScreenCapture](#oh_avscreencapture) instance.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.

**AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.

**AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The privacy permission fails to be enabled or screen capture fails to start.


### OH_AVScreenCapture_StartScreenCaptureWithSurface()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenCaptureWithSurface (struct OH_AVScreenCapture * capture, OHNativeWindow * window )
```

**Description**

Starts screen capture in surface mode.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an [OH_AVScreenCapture](#oh_avscreencapture) instance.| 
| window | Pointer to an [OHNativeWindow](../apis-arkgraphics2d/_native_window.md#ohnativewindow) instance.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.

**AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture**, input parameter **window**, or **windowSurface** pointed to by **window** is a null pointer.

**AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The privacy permission fails to be enabled or screen capture with a surface fails to start.


### OH_AVScreenCapture_StartScreenRecording()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenRecording (struct OH_AVScreenCapture * capture)
```

**Description**

Starts screen recording, with recordings saved in files.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an [OH_AVScreenCapture](#oh_avscreencapture) instance.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.

**AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.

**AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The privacy permission fails to be enabled or screen recording fails to start.


### OH_AVScreenCapture_StopScreenCapture()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StopScreenCapture (struct OH_AVScreenCapture * capture)
```

**Description**

Stops screen capture. This function is used in pair with [OH_AVScreenCapture_StartScreenCapture](#oh_avscreencapture_startscreencapture). After calling this function, the application stops screen capture or screen share and releases the microphone.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an [OH_AVScreenCapture](#oh_avscreencapture) instance.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.

**AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.

**AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. Screen capture fails to stop.


### OH_AVScreenCapture_StopScreenRecording()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StopScreenRecording (struct OH_AVScreenCapture * capture)
```

**Description**

Stops screen recording. This function is used in pair with [OH_AVScreenCapture_StartScreenRecording](#oh_avscreencapture_startscreenrecording).

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an [OH_AVScreenCapture](#oh_avscreencapture) instance.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.

**AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.

**AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. Screen recording fails to stop.

### OH_AVScreenCapture_ResizeCanvas()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ResizeCanvas (struct OH_AVScreenCapture * capture, int32_t width, int32_t height)
```

**Description**

Adjusts the screen resolution.

This function is used to set the resolution of screen capture data. **width** indicates the screen width and **height** indicates the screen height.

Currently, this function supports only the scenario of capturing streams, but not the scenario of storing captured files. In addition, the caller of this function and the video data consumer must ensure that they support resolution changes of the received video data.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an [OH_AVScreenCapture](#oh_avscreencapture) instance.| 
| width | Width of the screen to capture.| 
| height | Height of the screen to capture.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.

**AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.

**AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.

### OH_AVScreenCapture_SkipPrivacyMode()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SkipPrivacyMode (struct OH_AVScreenCapture * capture, int32_t *windowIDs, int32_t windowCount)
```

**Description**

Exempts privacy windows during screen capture.

Currently, all the IDs of the subwindows and main windows to skip must be passed in.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an [OH_AVScreenCapture](#oh_avscreencapture) instance.| 
| windowIDs | Pointer to the IDs of the privacy windows to skip.| 
| windowCount | Length of the privacy window ID list.| 

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.

**AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.

**AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.
