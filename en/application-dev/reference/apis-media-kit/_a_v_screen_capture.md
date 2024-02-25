# AVScreenCapture


## Overview

The **AVScreenCapture** module provides APIs for screen capture.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**

10


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [native_avscreen_capture.h](native__avscreen__capture_8h.md) | Declares the native APIs used to create an **OH_AVScreenCapture** instance.<br>**File to include**: <multimedia/player_framework/native_avscreen_capture.h> <br>**Library**: libnative_avscreen_capture.so| 
| [native_avscreen_capture_base.h](native__avscreen__capture__base_8h.md) | Declares the common structs, character constants, and enums used for running screen capture.<br>**File to include**: <multimedia/player_framework/native_avscreen_capture_base.h><br>**Library**: libnative_avscreen_capture.so| 
| [native_avscreen_capture_errors.h](native__avscreen__capture__errors_8h.md) | Declares the error codes generated during screen capture.<br>**File to include**: <multimedia/player_framework/native_avscreen_capture_errors.h><br>**Library**: libnative_avscreen_capture.so| 


### Structs

| Name| Description| 
| -------- | -------- |
| [OH_AudioCaptureInfo](_o_h___audio_capture_info.md) | Defines audio capture information.| 
| [OH_AudioEncInfo](_o_h___audio_enc_info.md) | Defines audio encoding information.<br>**NOTE**: This struct is reserved and will be provided in later versions.| 
| [OH_AudioInfo](_o_h___audio_info.md) | Defines audio capture parameters.| 
| [OH_VideoCaptureInfo](_o_h___video_capture_info.md) | Defines video capture information.| 
| [OH_VideoEncInfo](_o_h___video_enc_info.md) | Defines video encoding information.<br>**NOTE**: This struct is reserved and will be provided in later versions.| 
| [OH_VideoInfo](_o_h___video_info.md) | Defines video capture parameters.| 
| [OH_RecorderInfo](_o_h___recorder_info.md) | Defines recording file information.<br>**NOTE**: This struct is reserved and will be provided in later versions.| 
| [OH_AVScreenCaptureConfig](_o_h___a_v_screen_capture_config.md) | Defines the screen capture configuration.| 
| [OH_AVScreenCaptureCallback](_o_h___a_v_screen_capture_callback.md) | Defines all the asynchronous callback function pointers of an **OH_AVScreenCapture** instance.| 
| [OH_Rect](_o_h___rect.md) | Defines the width, height, and image information of the rectangle used for screen capture.| 
| [OH_AudioBuffer](_o_h___audio_buffer.md) | Defines the configuration such as the size, type, and timestamp of audio data.| 


### Types

| Name| Description| 
| -------- | -------- |
| [OH_NativeBuffer](#oh_nativebuffer) | Defines the native video stream class for screen capture.| 
| [OH_AVScreenCapture](#oh_avscreencapture) | Defines a screen capture instance used to obtain original video and audio streams.| 
| [OH_CaptureMode](#oh_capturemode) | Defines an enum that enumerates the screen capture modes.| 
| [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) | Defines an enum that enumerates the audio source types during screen capture.| 
| [OH_AudioCodecFormat](#oh_audiocodecformat) | Defines an enum that enumerates the audio encoding formats.| 
| [OH_VideoCodecFormat](#oh_videocodecformat) | Defines an enum that enumerates the video encoding formats.| 
| [OH_DataType](#oh_datatype) | Defines an enum that enumerates the data types of screen capture streams.| 
| [OH_VideoSourceType](#oh_videosourcetype) | Defines an enum that enumerates the video source formats.| 
| [OH_ContainerFormatType](#oh_containerformattype) | Defines an enum that enumerates the types of files generated during screen capture.<br>**NOTE**: This type is reserved and will be provided in later versions.| 
| [OH_AudioCaptureInfo](#oh_audiocaptureinfo) | Defines audio capture information.| 
| [OH_AudioEncInfo](#oh_audioencinfo) | Defines audio encoding information.<br>**NOTE**: This type is reserved and will be provided in later versions.| 
| [OH_AudioInfo](#oh_audioinfo) | Defines audio capture parameters.| 
| [OH_VideoCaptureInfo](#oh_videocaptureinfo) | Defines video capture information.| 
| [OH_VideoEncInfo](#oh_videoencinfo) | Defines video encoding information.<br>**NOTE**: This type is reserved and will be provided in later versions.| 
| [OH_VideoInfo](#oh_videoinfo) | Defines video capture parameters.| 
| [OH_RecorderInfo](#oh_recorderinfo) | Defines recording file information.| 
| [OH_AVScreenCaptureConfig](#oh_avscreencaptureconfig) | Defines the screen capture configuration.| 
| (\*[OH_AVScreenCaptureOnError](#oh_avscreencaptureonerror)) ([OH_AVScreenCapture](#oh_avscreencapture) \*capture, int32_t errorCode) | Defines a pointer to a callback function that is called when an error occurs during the running of an **OH_AVScreenCapture** instance.| 
| (\*[OH_AVScreenCaptureOnAudioBufferAvailable](#oh_avscreencaptureonaudiobufferavailable)) ([OH_AVScreenCapture](#oh_avscreencapture) \*capture, bool isReady, [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) type) | Defines a pointer to a callback function that is called when an audio buffer is available during the running of an **OH_AVScreenCapture** instance.| 
| (\*[OH_AVScreenCaptureOnVideoBufferAvailable](#oh_avscreencaptureonvideobufferavailable)) ([OH_AVScreenCapture](#oh_avscreencapture) \*capture, bool isReady) | Defines a pointer to a callback function that is called when a video buffer is available during the running of an **OH_AVScreenCapture** instance.| 
| [OH_AVScreenCaptureCallback](#oh_avscreencapturecallback) | Defines all the asynchronous callback function pointers of an **OH_AVScreenCapture** instance.| 
| [OH_Rect](#oh_rect) | Defines the width, height, and image information of the rectangle used for screen capture.| 
| [OH_AudioBuffer](#oh_audiobuffer) | Defines the configuration such as the size, type, and timestamp of audio data.| 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) | Defines an enum that enumerates the error codes generated during screen recording.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_CaptureMode](#oh_capturemode) { OH_CAPTURE_HOME_SCREEN = 0, OH_CAPTURE_SPECIFIED_SCREEN = 1, OH_CAPTURE_SPECIFIED_WINDOW = 2, OH_CAPTURE_INVAILD = -1 } | Enumerates the screen capture modes.| 
| [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) {<br>OH_SOURCE_INVALID = -1, OH_SOURCE_DEFAULT = 0, OH_MIC = 1, OH_ALL_PLAYBACK = 2,<br>OH_APP_PLAYBACK = 3<br>} | Enumerates the audio source types during screen capture.| 
| [OH_AudioCodecFormat](#oh_audiocodecformat) { OH_AUDIO_DEFAULT = 0, OH_AAC_LC = 3, OH_AUDIO_CODEC_FORMAT_BUTT } | Enumerates the audio encoding formats.| 
| [OH_VideoCodecFormat](#oh_videocodecformat) {<br>OH_VIDEO_DEFAULT = 0, OH_H264 = 2, OH_H265 = 4, OH_MPEG4 = 6,<br>OH_VP8 = 8, OH_VP9 = 10, OH_VIDEO_CODEC_FORMAT_BUTT<br>} | Enumerates the video encoding formats.| 
| [OH_DataType](#oh_datatype) { OH_ORIGINAL_STREAM = 0, OH_ENCODED_STREAM = 1, OH_CAPTURE_FILE = 2, OH_INVAILD = -1 } | Enumerates the data types of screen capture streams.| 
| [OH_VideoSourceType](#oh_videosourcetype) { OH_VIDEO_SOURCE_SURFACE_YUV = 0, OH_VIDEO_SOURCE_SURFACE_ES, OH_VIDEO_SOURCE_SURFACE_RGBA, OH_VIDEO_SOURCE_BUTT } | Enumerates the video source formats.| 
| [OH_ContainerFormatType](#oh_containerformattype) { CFT_MPEG_4A = 0, CFT_MPEG_4 = 1 } | Enumerates the types of files generated during screen capture.<br>**NOTE**: This enum is reserved and will be provided in later versions.| 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) {<br>AV_SCREEN_CAPTURE_ERR_BASE = 0, AV_SCREEN_CAPTURE_ERR_OK = AV_SCREEN_CAPTURE_ERR_BASE, AV_SCREEN_CAPTURE_ERR_NO_MEMORY = AV_SCREEN_CAPTURE_ERR_BASE + 1, AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT = AV_SCREEN_CAPTURE_ERR_BASE + 2,<br>AV_SCREEN_CAPTURE_ERR_INVALID_VAL = AV_SCREEN_CAPTURE_ERR_BASE + 3, AV_SCREEN_CAPTURE_ERR_IO = AV_SCREEN_CAPTURE_ERR_BASE + 4, AV_SCREEN_CAPTURE_ERR_TIMEOUT = AV_SCREEN_CAPTURE_ERR_BASE + 5, AV_SCREEN_CAPTURE_ERR_UNKNOWN = AV_SCREEN_CAPTURE_ERR_BASE + 6,<br>AV_SCREEN_CAPTURE_ERR_SERVICE_DIED = AV_SCREEN_CAPTURE_ERR_BASE + 7, AV_SCREEN_CAPTURE_ERR_INVALID_STATE = AV_SCREEN_CAPTURE_ERR_BASE + 8, AV_SCREEN_CAPTURE_ERR_UNSUPPORT = AV_SCREEN_CAPTURE_ERR_BASE + 9, AV_SCREEN_CAPTURE_ERR_EXTEND_START = AV_SCREEN_CAPTURE_ERR_BASE + 100<br>} | Enumerates the error codes generated during screen recording.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_AVScreenCapture_Create](#oh_avscreencapture_create) (void) | Creates an **OH_AVScreenCapture** instance.| 
| [OH_AVScreenCapture_Init](#oh_avscreencapture_init) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, [OH_AVScreenCaptureConfig](_o_h___a_v_screen_capture_config.md) config) | Initializes parameters related to an **OH_AVScreenCapture** instance.| 
| [OH_AVScreenCapture_StartScreenCapture](#oh_avscreencapture_startscreencapture) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | Starts screen capture and collects original streams. After calling this function, the application can use the callback listeners **OH_AVScreenCaptureOnAudioBufferAvailable** and **OH_AVScreenCaptureOnVideoBufferAvailable** to check whether streams are generated.| 
| [OH_AVScreenCapture_StopScreenCapture](#oh_avscreencapture_stopscreencapture) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | Stops screen capture. This function is used in pair with **OH_AVScreenCapture_StartScreenCapture**. After calling this function, the application stops screen capture or screen share and releases the microphone.| 
| [OH_AVScreenCapture_StartScreenRecording](#oh_avscreencapture_startscreenrecording) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | Starts screen recording and collects encoded streams.<br>**NOTE**: This function is reserved and will be provided in later versions.| 
| [OH_AVScreenCapture_StopScreenRecording](#oh_avscreencapture_stopscreenrecording) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | Stops screen recording. This function is used in pair with **OH_AVScreenCapture_StartScreenRecording**.<br>**NOTE**: This function is reserved and will be provided in later versions.| 
| [OH_AVScreenCapture_AcquireAudioBuffer](#oh_avscreencapture_acquireaudiobuffer) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, [OH_AudioBuffer](_o_h___audio_buffer.md) \*\*audiobuffer, [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) type) | Obtains an audio buffer. When calling this function, the application must allocate the memory of the corresponding struct size to the audio buffer.| 
| [OH_AVScreenCapture_AcquireVideoBuffer](#oh_avscreencapture_acquirevideobuffer) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, int32_t \*fence, int64_t \*timestamp, struct [OH_Rect](_o_h___rect.md) \*region) | Obtains a video buffer. An application can call this function to obtain information such as the video buffer and timestamp.| 
| [OH_AVScreenCapture_ReleaseAudioBuffer](#oh_avscreencapture_releaseaudiobuffer) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) type) | Releases an audio buffer.| 
| [OH_AVScreenCapture_ReleaseVideoBuffer](#oh_avscreencapture_releasevideobuffer) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | Releases a video buffer.| 
| [OH_AVScreenCapture_SetCallback](#oh_avscreencapture_setcallback) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, struct [OH_AVScreenCaptureCallback](_o_h___a_v_screen_capture_callback.md) callback) | Sets a callback to listen for available video buffers and audio buffers and errors that occur during the function calling.| 
| [OH_AVScreenCapture_Release](#oh_avscreencapture_release) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | Releases an **OH_AVScreenCapture** instance. This function is used in pair with **OH_AVScreenCapture_Create**.| 
| [OH_AVScreenCapture_SetMicrophoneEnabled](#oh_avscreencapture_setmicrophoneenabled) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, bool isMicrophone) | Enables or disables the microphone.| 


## Type Description


### OH_AudioBuffer

```
typedef struct OH_AudioBuffer OH_AudioBuffer
```

**Description**

Defines the configuration such as the size, type, and timestamp of audio data.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AudioCaptureInfo

```
typedef struct OH_AudioCaptureInfo OH_AudioCaptureInfo
```

**Description**

Defines audio capture information.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AudioCaptureSourceType

```
typedef enum OH_AudioCaptureSourceType OH_AudioCaptureSourceType
```

**Description**

Defines an enum that enumerates the audio source types during screen capture.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AudioCodecFormat

```
typedef enum OH_AudioCodecFormat OH_AudioCodecFormat
```

**Description**

Defines an enum that enumerates the audio encoding formats.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AudioEncInfo

```
typedef struct OH_AudioEncInfo OH_AudioEncInfo
```

**Description**

Defines audio encoding information.

> **NOTE**
> 
> This type is reserved and will be provided in later versions.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AudioInfo

```
typedef struct OH_AudioInfo OH_AudioInfo
```

**Description**

Defines audio capture parameters.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AVSCREEN_CAPTURE_ErrCode

```
typedef enum OH_AVSCREEN_CAPTURE_ErrCode OH_AVSCREEN_CAPTURE_ErrCode
```

**Description**

Defines an enum that enumerates the error codes generated during screen recording.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AVScreenCapture

```
typedef struct OH_AVScreenCapture OH_AVScreenCapture
```

**Description**

Defines a screen capture instance used to obtain original video and audio streams.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AVScreenCaptureCallback

```
typedef struct OH_AVScreenCaptureCallback OH_AVScreenCaptureCallback
```

**Description**

Defines all the asynchronous callback function pointers of an **OH_AVScreenCapture** instance. To ensure the normal running of **OH_AVScreenCapture**, you must register the instance of this struct with the **OH_AVScreenCapture** instance and process the information reported by the callback functions.

**Parameters**

| Name| Description| 
| -------- | -------- |
| onError | Pointer to a callback function that is called when an error occurs during the running of an **OH_AVScreenCapture** instance. For details, see [OH_AVScreenCaptureOnError](#oh_avscreencaptureonerror).| 
| onAudioBufferAvailable | Pointer to a callback function that is called when an audio buffer is available during the running of an **OH_AVScreenCapture** instance. For details, see [OH_AVScreenCaptureOnAudioBufferAvailable](#oh_avscreencaptureonaudiobufferavailable).| 
| onVideoBufferAvailable | Pointer to a callback function that is called when a video buffer is available during the running of an **OH_AVScreenCapture** instance. For details, see [OH_AVScreenCaptureOnVideoBufferAvailable](#oh_avscreencaptureonvideobufferavailable).| 

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AVScreenCaptureConfig

```
typedef struct OH_AVScreenCaptureConfig OH_AVScreenCaptureConfig
```

**Description**

Defines the screen capture configuration.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AVScreenCaptureOnAudioBufferAvailable

```
typedef void(* OH_AVScreenCaptureOnAudioBufferAvailable) (OH_AVScreenCapture *capture, bool isReady, OH_AudioCaptureSourceType type)
```

**Description**

Defines a pointer to a callback function that is called when an audio buffer is available during the running of an **OH_AVScreenCapture** instance.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an **OH_AVScreenCapture** instance.| 
| isReady | Whether the audio buffer is available.| 
| type | Audio source type.| 

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AVScreenCaptureOnError

```
typedef void(* OH_AVScreenCaptureOnError) (OH_AVScreenCapture *capture, int32_t errorCode)
```

**Description**

Defines a pointer to a callback function that is called when an error occurs during the running of an **OH_AVScreenCapture** instance.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an **OH_AVScreenCapture** instance.| 
| errorCode | Error code.| 

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AVScreenCaptureOnVideoBufferAvailable

```
typedef void(* OH_AVScreenCaptureOnVideoBufferAvailable) (OH_AVScreenCapture *capture, bool isReady)
```

**Description**

Defines a pointer to a callback function that is called when a video buffer is available during the running of an **OH_AVScreenCapture** instance.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an **OH_AVScreenCapture** instance.| 
| isReady | Whether the video buffer is available.| 

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_CaptureMode

```
typedef enum OH_CaptureModeOH_CaptureMode
```

**Description**

Defines an enum that enumerates the screen capture modes.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_ContainerFormatType

```
typedef enum OH_ContainerFormatType OH_ContainerFormatType
```

**Description**

Defines an enum that enumerates the types of files generated during screen capture.

> **NOTE**
>
> This type is reserved and will be provided in later versions.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_DataType

```
typedef enum OH_DataType OH_DataType
```

**Description**

Defines an enum that enumerates the data types of screen capture streams.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_NativeBuffer

```
typedef struct OH_NativeBuffer OH_NativeBuffer
```

**Description**

Defines the native video stream class for screen capture.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_RecorderInfo

```
typedef struct OH_RecorderInfo OH_RecorderInfo
```

**Description**

Defines recording file information.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_Rect

```
typedef struct OH_Rect OH_Rect
```

**Description**

Defines the width, height, and image information of the rectangle used for screen capture.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_VideoCaptureInfo

```
typedef struct OH_VideoCaptureInfo OH_VideoCaptureInfo
```

**Description**

Defines video capture information.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_VideoCodecFormat

```
typedef enum OH_VideoCodecFormat OH_VideoCodecFormat
```

**Description**

Defines an enum that enumerates the video encoding formats.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_VideoEncInfo

```
typedef struct OH_VideoEncInfo OH_VideoEncInfo
```

**Description**

Defines video encoding parameters.

> **NOTE**
> 
> This type is reserved and will be provided in later versions.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_VideoInfo

```
typedef struct OH_VideoInfo OH_VideoInfo
```

**Description**

Defines video capture parameters.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_VideoSourceType

```
typedef enum OH_VideoSourceType OH_VideoSourceType
```

**Description**

Defines an enum that enumerates the video source formats.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture


## Enum Description


### OH_AudioCaptureSourceType

```
enum OH_AudioCaptureSourceType
```

**Description**

Enumerates the audio source types during screen capture.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture

| Value| Description| 
| -------- | -------- |
| OH_SOURCE_INVALID | Invalid audio source.| 
| OH_SOURCE_DEFAULT | Default audio source. The default value is **MIC**.| 
| OH_MIC | External audio streams recorded by the microphone.| 
| OH_ALL_PLAYBACK | All internal audio streams played by the system.| 
| OH_APP_PLAYBACK | Internal audio streams played by a specified application.| 


### OH_AudioCodecFormat

```
enum OH_AudioCodecFormat
```

**Description**

Enumerates the audio encoding formats.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture

| Value| Description| 
| -------- | -------- |
| OH_AUDIO_DEFAULT | Default audio encoding format. The default value is **AAC_LC**.| 
| OH_AAC_LC | AAC_LC audio encoding.| 
| OH_AUDIO_CODEC_FORMAT_BUTT | Invalid format.| 


### OH_AVSCREEN_CAPTURE_ErrCode

```
enum OH_AVSCREEN_CAPTURE_ErrCode
```

**Description**

Enumerates the error codes generated during screen recording.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture

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


### OH_CaptureMode

```
enum OH_CaptureMode
```

**Description**

Enumerates the screen capture modes.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture

| Value| Description| 
| -------- | -------- |
| OH_CAPTURE_HOME_SCREEN | To capture the home screen.| 
| OH_CAPTURE_SPECIFIED_SCREEN | To capture a specified screen.<br>**NOTE**: This value is reserved and will be provided in later versions.| 
| OH_CAPTURE_SPECIFIED_WINDOW | To capture a specified window.<br>**NOTE**: This value is reserved and will be provided in later versions.| 
| OH_CAPTURE_INVAILD | Invalid mode.| 


### OH_ContainerFormatType

```
enum OH_ContainerFormatType
```

**Description**

Enumerates the types of files generated during screen capture.

> **NOTE**
>
> This enum is reserved and will be provided in later versions.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture

| Value| Description| 
| -------- | -------- |
| CFT_MPEG_4A | Audio format M4A.| 
| CFT_MPEG_4 | Video format MP4.| 


### OH_DataType

```
enum OH_DataType
```

**Description**

Enumerates the data types of screen capture streams.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture

| Value| Description| 
| -------- | -------- |
| OH_ORIGINAL_STREAM | Original stream format, such as YUV, RGBA, and PCM.| 
| OH_ENCODED_STREAM | Encoded stream format, such as H.264 and AAC.<br>**NOTE**: This value is reserved and will be provided in later versions.| 
| OH_CAPTURE_FILE | Format of the recording file. The value can be **mp4**.<br>**NOTE**: This value is reserved and will be provided in later versions.| 
| OH_INVAILD | Invalid format.| 


### OH_VideoCodecFormat

```
enum OH_VideoCodecFormat
```

**Description**

Enumerates the video encoding formats.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture

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

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture

| Value| Description| 
| -------- | -------- |
| OH_VIDEO_SOURCE_SURFACE_YUV | YUV format.| 
| OH_VIDEO_SOURCE_SURFACE_ES | Raw format.| 
| OH_VIDEO_SOURCE_SURFACE_RGBA | RGBA format.| 
| OH_VIDEO_SOURCE_BUTT | Invalid format.| 


## Function Description


### OH_AVScreenCapture_AcquireAudioBuffer()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_AcquireAudioBuffer (struct OH_AVScreenCapture * capture, OH_AudioBuffer ** audiobuffer, OH_AudioCaptureSourceType type )
```

**Description**

Obtains an audio buffer. When calling this function, the application must allocate the memory of the corresponding struct size to the audio buffer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an **OH_AVScreenCapture** instance.| 
| audiobuffer | Pointer to the struct for storing the audio buffer. This struct is used to obtain the information about the audio buffer and the timestamp of the buffer.| 
| type | Type of the audio buffer, which is used to distinguish external streams recorded by the microphone from internal streams played by the system. For details, see [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype).| 

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture

**Returns**

Returns **AV_SCREEN_CAPTURE_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) otherwise.


### OH_AVScreenCapture_AcquireVideoBuffer()

```
OH_NativeBuffer* OH_AVScreenCapture_AcquireVideoBuffer (struct OH_AVScreenCapture * capture, int32_t * fence, int64_t * timestamp, struct OH_Rect * region )
```

**Description**

Obtains a video buffer. An application can call this function to obtain information such as the video buffer and timestamp. After the buffer is no longer needed, call **OH_AVScreenCapture_ReleaseVideoBuffer** to release it.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an **OH_AVScreenCapture** instance.| 
| fence | Pointer to parameters for synchronization display.| 
| timestamp | Pointer to the timestamp of the video frame.| 
| region | Pointer to the coordinates related to video display.| 

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture

**Returns**

Returns an **OH_NativeBuffer** object if the operation is successful. The application can call the APIs provided by the **OH_NativeBuffer** object to obtain information such as the video buffer and resolution.


### OH_AVScreenCapture_Create()

```
struct OH_AVScreenCapture* OH_AVScreenCapture_Create (void )
```

**Description**

Creates an **OH_AVScreenCapture** instance. You can release the instance by calling **OH_AVScreenCapture_Release**.

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture

**Returns**

Returns the pointer to an **OH_AVScreenCapture** instance.


### OH_AVScreenCapture_Init()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Init (struct OH_AVScreenCapture * capture, OH_AVScreenCaptureConfig config )
```

**Description**

Initializes **OH_AVScreenCapture** parameters, including audio microphone sampling parameters, audio capture parameters (optional), and video resolution parameters.

To call this function, you must configure the **ohos.permission.MICROPHONE** and **ohos.permission.CAPTURE_SCREEN** permissions. Otherwise, the initialization fails and screen capture cannot be performed properly.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an **OH_AVScreenCapture** instance.| 
| config | Parameters related to screen capture initialization.| 

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture

**Returns**

Returns **AV_SCREEN_CAPTURE_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) otherwise.


### OH_AVScreenCapture_Release()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Release (struct OH_AVScreenCapture * capture)
```

**Description**

Releases an **OH_AVScreenCapture** instance. This function is used in pair with **OH_AVScreenCapture_Create**.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an **OH_AVScreenCapture** instance.| 

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture

**Returns**

Returns **AV_SCREEN_CAPTURE_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) otherwise.


### OH_AVScreenCapture_ReleaseAudioBuffer()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseAudioBuffer (struct OH_AVScreenCapture * capture, OH_AudioCaptureSourceType type )
```

**Description**

Releases an audio buffer. After the audio buffer is no longer needed, call this function to release it.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an **OH_AVScreenCapture** instance.| 
| type | Type of the audio buffer, which is used to distinguish external streams recorded by the microphone from internal streams played by the system.| 

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture

**Returns**

Returns **AV_SCREEN_CAPTURE_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) otherwise.


### OH_AVScreenCapture_ReleaseVideoBuffer()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseVideoBuffer (struct OH_AVScreenCapture * capture)
```

**Description**

Releases a video buffer. After the video buffer is no longer needed, call this function to release it.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an **OH_AVScreenCapture** instance.| 

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture

**Returns**

Returns **AV_SCREEN_CAPTURE_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) otherwise.


### OH_AVScreenCapture_SetCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCallback (struct OH_AVScreenCapture * capture, struct OH_AVScreenCaptureCallback callback )
```

**Description**

Sets a callback to listen for available video buffers and audio buffers and errors that occur during the function calling.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an **OH_AVScreenCapture** instance.| 
| callback | [OH_AVScreenCaptureCallback](_o_h___a_v_screen_capture_callback.md) struct, which stores related callback function pointers.| 

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture

**Returns**

Returns **AV_SCREEN_CAPTURE_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) otherwise.


### OH_AVScreenCapture_SetMicrophoneEnabled()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetMicrophoneEnabled (struct OH_AVScreenCapture * capture, bool isMicrophone )
```

**Description**

Enables or disables the microphone. When **isMicrophone** is set to **true**, the microphone is enabled, and the original PCM data of the microphone can be obtained by calling **OH_AVScreenCapture_StartScreenRecording** and **OH_AVScreenCapture_AcquireAudioBuffer**. When **isMicrophone** is set to **false**, the obtained audio data is silent data.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an **OH_AVScreenCapture** instance.| 
| isMicrophone | Whether to enable the microphone.| 

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture

**Returns**

Returns **AV_SCREEN_CAPTURE_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) otherwise.


### OH_AVScreenCapture_StartScreenCapture()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenCapture (struct OH_AVScreenCapture * capture)
```

**Description**

Starts screen capture and collects original streams. After calling this function, the application can use the callback listeners **OH_AVScreenCaptureOnAudioBufferAvailable** and **OH_AVScreenCaptureOnVideoBufferAvailable** to check whether streams are generated.

The application can obtain the original streams of screen capture by calling **OH_AVScreenCapture_AcquireAudioBuffer** and **OH_AVScreenCapture_ReleaseVideoBuffer**.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an **OH_AVScreenCapture** instance.| 

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture

**Returns**

Returns **AV_SCREEN_CAPTURE_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) otherwise.


### OH_AVScreenCapture_StartScreenRecording()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenRecording (struct OH_AVScreenCapture * capture)
```

**Description**

Starts screen recording and collects encoded streams.

> **NOTE**
> 
> This function is reserved and will be provided in later versions.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an **OH_AVScreenCapture** instance.| 

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture

**Returns**

Returns **AV_SCREEN_CAPTURE_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) otherwise.


### OH_AVScreenCapture_StopScreenCapture()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StopScreenCapture (struct OH_AVScreenCapture * capture)
```

**Description**

Stops screen capture. This function is used in pair with **OH_AVScreenCapture_StartScreenCapture**. After calling this function, the application stops screen capture or screen share and releases the microphone.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an **OH_AVScreenCapture** instance.| 

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture

**Returns**

Returns **AV_SCREEN_CAPTURE_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) otherwise.


### OH_AVScreenCapture_StopScreenRecording()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StopScreenRecording (struct OH_AVScreenCapture * capture)
```

**Description**

Stops screen recording. This function is used in pair with **OH_AVScreenCapture_StartScreenRecording**.

> **NOTE**
> 
> This function is reserved and will be provided in later versions.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capture | Pointer to an **OH_AVScreenCapture** instance.| 

**System capability**

SystemCapability.Multimedia.Media.AVScreenCapture

**Returns**

Returns **AV_SCREEN_CAPTURE_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) otherwise.
