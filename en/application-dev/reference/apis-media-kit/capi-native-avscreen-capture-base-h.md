# native_avscreen_capture_base.h

## Overview

The **native_avscreen_capture_base.h** file declares the common structs, character constants, and enums used for running screen capture.

**Library**: libnative_avscreen_capture.so

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Related module**: [AVScreenCapture](capi-avscreencapture.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioCaptureInfo](capi-oh-audiocaptureinfo.md) | OH_AudioCaptureInfo | Describes the audio capture information.<br>When both **audioSampleRate** and **audioChannels** are **0**, the audio-related parameters are ignored and the audio data is not recorded.|
| [OH_NativeBuffer](capi-oh-nativebuffer.md) | OH_NativeBuffer | Describes the native video stream class for screen capture.|
| [OH_AVScreenCapture](capi-oh-avscreencapture.md) | OH_AVScreenCapture | Describes a screen capture instance used to obtain original video and audio streams.|
| [OH_AVScreenCapture_ContentFilter](capi-oh-avscreencapture-contentfilter.md) | OH_AVScreenCapture_ContentFilter | Describes the filter used to filter audio and video content.|
| [OH_AVScreenCapture_CaptureStrategy](capi-oh-avscreencapture-capturestrategy.md) | OH_AVScreenCapture_CaptureStrategy | Describes the screen capture strategy configured by using OH_AVScreenCapture_CaptureStrategy.|
| [OH_AudioEncInfo](capi-oh-audioencinfo.md) | OH_AudioEncInfo | Describes the audio encoding information.|
| [OH_AudioInfo](capi-oh-audioinfo.md) | OH_AudioInfo | Describes the audio information.<br>To perform both external capture (using microphones) and internal capture, **audioSampleRate** and **audioChannels** must be the same for both audio channels.|
| [OH_VideoCaptureInfo](capi-oh-videocaptureinfo.md) | OH_VideoCaptureInfo | Describes the video capture information. When **videoFrameWidth** and **videoFrameHeight** are both **0**, video-related parameters are ignored and screen data is not recorded.|
| [OH_VideoEncInfo](capi-oh-videoencinfo.md) | OH_VideoEncInfo | Describes the video encoding information.|
| [OH_VideoInfo](capi-oh-videoinfo.md) | OH_VideoInfo | Describes the video information.|
| [OH_RecorderInfo](capi-oh-recorderinfo.md) | OH_RecorderInfo | Describes the recording file information.|
| [OH_AVScreenCaptureConfig](capi-oh-avscreencaptureconfig.md) | OH_AVScreenCaptureConfig | Describes the screen capture configuration.|
| [OH_AVScreenCaptureCallback](capi-oh-avscreencapturecallback.md) | OH_AVScreenCaptureCallback | Defines all the asynchronous callback function pointers of an **OH_AVScreenCapture** instance. To ensure the normal running of **OH_AVScreenCapture**, you must register the instance of this struct with the **OH_AVScreenCapture** instance and process the information reported by the callback functions.<br>From API version 12, you are advised to use [OH_AVScreenCapture_OnError](#oh_avscreencapture_onerror) and [OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable) instead.|
| [OH_Rect](capi-oh-rect.md) | OH_Rect | Describes the width, height, and image information of the rectangle used for screen capture.|
| [OH_AudioBuffer](capi-oh-audiobuffer.md) | OH_AudioBuffer | Describes the configuration such as the size, type, and timestamp of audio data.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_CaptureMode](#oh_capturemode) | OH_CaptureMode | Enumerates the screen capture modes.|
| [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) | OH_AudioCaptureSourceType | Enumerates the audio source types during screen capture.|
| [OH_AudioCodecFormat](#oh_audiocodecformat) | OH_AudioCodecFormat | Enumerates the audio encoding formats.|
| [OH_VideoCodecFormat](#oh_videocodecformat) | OH_VideoCodecFormat | Enumerates the video encoding formats.|
| [OH_DataType](#oh_datatype) | OH_DataType | Enumerates the data types of screen capture streams.|
| [OH_VideoSourceType](#oh_videosourcetype) | OH_VideoSourceType | Enumerates the video source formats.|
| [OH_ContainerFormatType](#oh_containerformattype) | OH_ContainerFormatType | Enumerates the types of files generated during screen capture.|
| [OH_AVScreenCaptureStateCode](#oh_avscreencapturestatecode) | OH_AVScreenCaptureStateCode | Enumerates the screen capture states.|
| [OH_AVScreenCaptureBufferType](#oh_avscreencapturebuffertype) | OH_AVScreenCaptureBufferType | Enumerates the buffer types.|
| [OH_AVScreenCaptureFilterableAudioContent](#oh_avscreencapturefilterableaudiocontent) | OH_AVScreenCaptureFilterableAudioContent | Enumerates the types of audio that can be added to a content filter.|
| [OH_AVScreenCaptureContentChangedEvent](#oh_avscreencapturecontentchangedevent) | OH_AVScreenCaptureContentChangedEvent | Enumerates the screen capture content change events.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_AVScreenCaptureOnError)(OH_AVScreenCapture *capture, int32_t errorCode)](#oh_avscreencaptureonerror) | OH_AVScreenCaptureOnError | Called when an error occurs during the running of an **OH_AVScreenCapture** instance.|
| [typedef void (\*OH_AVScreenCaptureOnAudioBufferAvailable)(OH_AVScreenCapture *capture, bool isReady,OH_AudioCaptureSourceType type)](#oh_avscreencaptureonaudiobufferavailable) | OH_AVScreenCaptureOnAudioBufferAvailable | Called when an audio buffer is available during the running of an **OH_AVScreenCapture** instance.|
| [typedef void (\*OH_AVScreenCaptureOnVideoBufferAvailable)(OH_AVScreenCapture *capture, bool isReady)](#oh_avscreencaptureonvideobufferavailable) | OH_AVScreenCaptureOnVideoBufferAvailable | Called when a video buffer is available during the running of an **OH_AVScreenCapture** instance.|
| [typedef void (\*OH_AVScreenCapture_OnStateChange)(struct OH_AVScreenCapture *capture,OH_AVScreenCaptureStateCode stateCode, void *userData)](#oh_avscreencapture_onstatechange) | OH_AVScreenCapture_OnStateChange | Called when the state changes during the running of an **OH_AVScreenCapture** instance.|
| [typedef void (\*OH_AVScreenCapture_OnError)(OH_AVScreenCapture *capture, int32_t errorCode, void *userData)](#oh_avscreencapture_onerror) | OH_AVScreenCapture_OnError | Called when an error occurs during the running of an **OH_AVScreenCapture** instance.|
| [typedef void (\*OH_AVScreenCapture_OnBufferAvailable)(OH_AVScreenCapture *capture, OH_AVBuffer *buffer,OH_AVScreenCaptureBufferType bufferType, int64_t timestamp, void *userData)](#oh_avscreencapture_onbufferavailable) | OH_AVScreenCapture_OnBufferAvailable | Called when an audio buffer or a video buffer is available during the running of an **OH_AVScreenCapture** instance.|
| [typedef void (\*OH_AVScreenCapture_OnDisplaySelected)(OH_AVScreenCapture *capture, uint64_t displayId, void *userData)](#oh_avscreencapture_ondisplayselected) | OH_AVScreenCapture_OnDisplaySelected | Called when screen capture starts.|
| [typedef void (\*OH_AVScreenCapture_OnCaptureContentChanged)(OH_AVScreenCapture* capture,OH_AVScreenCaptureContentChangedEvent event, OH_Rect* area, void *userData)](#oh_avscreencapture_oncapturecontentchanged) | OH_AVScreenCapture_OnCaptureContentChanged | Called when the screen capture content changes.|

## Enum Description

### OH_CaptureMode

```
enum OH_CaptureMode
```

**Description**

Enumerates the screen capture modes.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

| Enum Item| Description|
| -- | -- |
| OH_CAPTURE_HOME_SCREEN = 0 | Captures the home screen.|
| OH_CAPTURE_SPECIFIED_SCREEN = 1 | Captures a specified screen.|
| OH_CAPTURE_SPECIFIED_WINDOW = 2 | Captures a specified window.|
| OH_CAPTURE_INVAILD = -1 | Invalid mode.|

### OH_AudioCaptureSourceType

```
enum OH_AudioCaptureSourceType
```

**Description**

Enumerates the audio source types during screen capture.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

| Enum Item| Description|
| -- | -- |
| OH_SOURCE_INVALID = -1 | Invalid audio source.|
| OH_SOURCE_DEFAULT = 0 | Default audio source. The default value is **OH_MIC**.|
| OH_MIC = 1 | External audio streams recorded by the microphone.|
| OH_ALL_PLAYBACK = 2 | All internal audio streams played by the system.|
| OH_APP_PLAYBACK = 3 | Internal audio streams played by a specified application.|

### OH_AudioCodecFormat

```
enum OH_AudioCodecFormat
```

**Description**

Enumerates the audio encoding formats.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

| Enum Item| Description|
| -- | -- |
| OH_AUDIO_DEFAULT = 0 | Default audio encoding format. The default value is **AAC_LC**.|
| OH_AAC_LC = 3 | AAC_LC audio encoding.|
| OH_AUDIO_CODEC_FORMAT_BUTT | Invalid format.|

### OH_VideoCodecFormat

```
enum OH_VideoCodecFormat
```

**Description**

Enumerates the video encoding formats.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

| Enum Item| Description|
| -- | -- |
| OH_VIDEO_DEFAULT = 0 | Default video encoding format. The default value is **H.264**.|
| OH_H264 = 2 | H.264.|
| OH_H265 = 4 | H.265/HEVC.|
| OH_MPEG4 = 6 | MPEG4.|
| OH_VP8 = 8 | VP8.|
| OH_VP9 = 10 | VP9.|
| OH_VIDEO_CODEC_FORMAT_BUTT | Invalid format.|

### OH_DataType

```
enum OH_DataType
```

**Description**

Enumerates the data types of screen capture streams.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

| Enum Item| Description|
| -- | -- |
| OH_ORIGINAL_STREAM = 0 | Original stream format, such as YUV, RGBA, and PCM.|
| OH_ENCODED_STREAM = 1 | Encoded stream format, such as H.264 and AAC. This value is not supported yet.|
| OH_CAPTURE_FILE = 2 | Format of the recording file. The value can be **mp4**.|
| OH_INVAILD = -1 | Invalid format.|

### OH_VideoSourceType

```
enum OH_VideoSourceType
```

**Description**

Enumerates the video source formats. Currently, only the RGBA format is supported.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

| Enum Item| Description|
| -- | -- |
| OH_VIDEO_SOURCE_SURFACE_YUV = 0 | YUV format. This value is not supported yet.|
| OH_VIDEO_SOURCE_SURFACE_ES | Raw format. This value is not supported yet.|
| OH_VIDEO_SOURCE_SURFACE_RGBA | RGBA format.|
| OH_VIDEO_SOURCE_BUTT | Invalid format.|

### OH_ContainerFormatType

```
enum OH_ContainerFormatType
```

**Description**

Enumerates the types of files generated during screen capture.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

| Enum Item| Description|
| -- | -- |
| CFT_MPEG_4A = 0 | Audio format M4A.|
| CFT_MPEG_4 = 1 | Video format MP4.|

### OH_AVScreenCaptureStateCode

```
enum OH_AVScreenCaptureStateCode
```

**Description**

Enumerates the screen capture states.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12

| Enum Item| Description|
| -- | -- |
| OH_SCREEN_CAPTURE_STATE_STARTED = 0 | Screen capture is started.|
| OH_SCREEN_CAPTURE_STATE_CANCELED = 1 | Screen capture is canceled.|
| OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER = 2 | Screen capture is stopped.|
| OH_SCREEN_CAPTURE_STATE_INTERRUPTED_BY_OTHER = 3 | Screen capture is interrupted by another screen capture.|
| OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL = 4 | Screen capture is interrupted by a call.|
| OH_SCREEN_CAPTURE_STATE_MIC_UNAVAILABLE = 5 | The microphone is unavailable.|
| OH_SCREEN_CAPTURE_STATE_MIC_MUTED_BY_USER = 6 | The microphone is muted.|
| OH_SCREEN_CAPTURE_STATE_MIC_UNMUTED_BY_USER = 7 | The microphone is unmuted.|
| OH_SCREEN_CAPTURE_STATE_ENTER_PRIVATE_SCENE = 8 | The system enters a privacy screen.|
| OH_SCREEN_CAPTURE_STATE_EXIT_PRIVATE_SCENE = 9 | The system exits a privacy screen.|
| OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER_SWITCHES = 10 | Screen capture is interrupted by system user switching.|

### OH_AVScreenCaptureBufferType

```
enum OH_AVScreenCaptureBufferType
```

**Description**

Enumerates the buffer types.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12

| Enum Item| Description|
| -- | -- |
| OH_SCREEN_CAPTURE_BUFFERTYPE_VIDEO = 0 | Video data.|
| OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_INNER = 1 | Internal audio capture data.|
| OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_MIC = 2 | Microphone audio data.|

### OH_AVScreenCaptureFilterableAudioContent

```
enum OH_AVScreenCaptureFilterableAudioContent
```

**Description**

Enumerates the types of audio that can be added to a content filter.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12

| Enum Item| Description|
| -- | -- |
| OH_SCREEN_CAPTURE_NOTIFICATION_AUDIO = 0 | Notification tone.|
| OH_SCREEN_CAPTURE_CURRENT_APP_AUDIO = 1 | Sound of the application itself.|

### OH_AVScreenCaptureContentChangedEvent

```
enum OH_AVScreenCaptureContentChangedEvent
```

**Description**

Enumerates the screen capture content change events.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 20

| Enum Item| Description|
| -- | -- |
| OH_SCREEN_CAPTURE_CONTENT_HIDE = 0 | The screen capture content is hidden.|
| OH_SCREEN_CAPTURE_CONTENT_VISIBLE = 1 | The screen capture content is visible.|
| OH_SCREEN_CAPTURE_CONTENT_UNAVAILABLE = 2 | The screen capture content becomes unavailable. For example, the screen capture window is closed.|


## Function Description

### OH_AVScreenCaptureOnError()

```
typedef void (*OH_AVScreenCaptureOnError)(OH_AVScreenCapture *capture, int32_t errorCode)
```

**Description**

Called when an error occurs during the running of an **OH_AVScreenCapture** instance.

From API version 12, you are advised to use [OH_AVScreenCapture_OnError](#oh_avscreencapture_onerror) instead.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture | Pointer to the **OH_AVScreenCapture** instance.|
|  int32_t errorCode | Error code.|

### OH_AVScreenCaptureOnAudioBufferAvailable()

```
typedef void (*OH_AVScreenCaptureOnAudioBufferAvailable)(OH_AVScreenCapture *capture, bool isReady,OH_AudioCaptureSourceType type)
```

**Description**

Called when an audio buffer is available during the running of an **OH_AVScreenCapture** instance.

From API version 12, you are advised to use [OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable) instead.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture | Pointer to the **OH_AVScreenCapture** instance.|
|  bool isReady | Whether the audio buffer is available.|
| [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) type | Audio source type.|

### OH_AVScreenCaptureOnVideoBufferAvailable()

```
typedef void (*OH_AVScreenCaptureOnVideoBufferAvailable)(OH_AVScreenCapture *capture, bool isReady)
```

**Description**

Called when a video buffer is available during the running of an **OH_AVScreenCapture** instance.

From API version 12, you are advised to use [OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable) instead.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture | Pointer to the **OH_AVScreenCapture** instance.|
|  bool isReady | Whether the video buffer is available.|

### OH_AVScreenCapture_OnStateChange()

```
typedef void (*OH_AVScreenCapture_OnStateChange)(struct OH_AVScreenCapture *capture,OH_AVScreenCaptureStateCode stateCode, void *userData)
```

**Description**

Called when the state changes during the running of an **OH_AVScreenCapture** instance.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture | Pointer to the **OH_AVScreenCapture** instance.|
| [OH_AVScreenCaptureStateCode](#oh_avscreencapturestatecode) stateCode | Status code.|
|  void *userData | Pointer to the user-defined data carried in the function.|

### OH_AVScreenCapture_OnError()

```
typedef void (*OH_AVScreenCapture_OnError)(OH_AVScreenCapture *capture, int32_t errorCode, void *userData)
```

**Description**

Called when an error occurs during the running of an **OH_AVScreenCapture** instance.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture | Pointer to the **OH_AVScreenCapture** instance.|
|  int32_t errorCode | Error code.|
|  void *userData | Pointer to the user-defined data carried in the function.|

### OH_AVScreenCapture_OnBufferAvailable()

```
typedef void (*OH_AVScreenCapture_OnBufferAvailable)(OH_AVScreenCapture *capture, OH_AVBuffer *buffer,OH_AVScreenCaptureBufferType bufferType, int64_t timestamp, void *userData)
```

**Description**

Called when an audio buffer or a video buffer is available during the running of an **OH_AVScreenCapture** instance.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture | Pointer to the **OH_AVScreenCapture** instance.|
|  [OH_AVBuffer](../apis-avcodec-kit/_core.md#oh_avbuffer) *buffer | Pointer to the **OH_AVBuffer** instance. After the callback is triggered, the buffer is no longer valid.|
| [OH_AVScreenCaptureBufferType](#oh_avscreencapturebuffertype) bufferType | Type of the buffer.|
|  int64_t timestamp | Timestamp, in nanoseconds.|
|  void *userData | Pointer to the user-defined data carried in the function.|

### OH_AVScreenCapture_OnDisplaySelected()

```
typedef void (*OH_AVScreenCapture_OnDisplaySelected)(OH_AVScreenCapture *capture, uint64_t displayId, void *userData)
```

**Description**

Called when screen capture starts.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture | Pointer to the **OH_AVScreenCapture** instance.|
|  uint64_t displayId | ID of the screen to capture.|
|  void *userData | Pointer to the user-defined data carried in the function.|

### OH_AVScreenCapture_OnCaptureContentChanged()

```
typedef void (*OH_AVScreenCapture_OnCaptureContentChanged)(OH_AVScreenCapture* capture,OH_AVScreenCaptureContentChangedEvent event, OH_Rect* area, void *userData)
```

**Description**

Called when the screen capture content changes during the running of an **OH_AVScreenCapture** instance.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVScreenCapture](capi-oh-avscreencapture.md)* capture | Pointer to the **OH_AVScreenCapture** instance.|
| [OH_AVScreenCaptureContentChangedEvent](#oh_avscreencapturecontentchangedevent) event | Screen capture content change event.|
|  [OH_Rect](capi-oh-rect.md)* area | Pointer to the area information when the screen capture content is visible.|
|  void *userData | Pointer to the user-defined data carried in the function.|
