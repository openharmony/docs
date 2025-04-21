# AVRecorder


## Overview

The AVRecorder module provides the APIs for requesting the recording capability.

You can refer to the corresponding development guide and samples based on your development requirements.

- [Using AVRecorder to Record Audio (C/C++)](../../media/media/using-ndk-avrecorder-for-audio-recording.md)
- [Using AVRecorder to Record Videos (C/C++)](../../media/media/using-ndk-avrecorder-for-video-recording.md)

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [avrecorder.h](avrecorder_8h.md) | Declares the AVRecorder APIs. Applications can use the APIs to record media data.|
| [avrecorder_base.h](avrecorder__base_8h.md) | Declares the struct and enums used by the AVRecorder.|


### Structs

| Name| Description|
| -------- | -------- |
| struct  [OH_AVRecorder_Profile](_o_h___a_v_recorder___profile.md) | Describes the parameters used for audio and video recording.<br>You can choose to record only audio or only video by setting the parameters. When **audioBitrate** or **audioChannels** is set to **0**, audio recording is disabled. When **videoFrameWidth** or **videoFrameHeight** is set to **0**, video recording is disabled.|
| struct  [OH_AVRecorder_Location](_o_h___a_v_recorder___location.md) | Describes the geographical location information about a media asset.|
| struct  [OH_AVRecorder_MetadataTemplate](_o_h___a_v_recorder___metadata_template.md) | Describes the basic template of metadata.|
| struct  [OH_AVRecorder_Metadata](_o_h___a_v_recorder___metadata.md) | Describes the metadata.|
| struct  [OH_AVRecorder_Config](_o_h___a_v_recorder___config.md) | Describes the AVRecorder configuration.|
| struct  [OH_AVRecorder_Range](_o_h___a_v_recorder___range.md) | Describes the range.|
| struct  [OH_AVRecorder_EncoderInfo](_o_h___a_v_recorder___encoder_info.md) | Describes the encoder information.|


### Types

| Name| Description|
| -------- | -------- |
| typedef struct [OH_AVRecorder](#oh_avrecorder) [OH_AVRecorder](#oh_avrecorder) | Defines a struct for the AVRecorder.|
| typedef enum [OH_AVRecorder_AudioSourceType](#oh_avrecorder_audiosourcetype-1) [OH_AVRecorder_AudioSourceType](#oh_avrecorder_audiosourcetype) | Defines an enum for the audio source types of the AVRecorder.|
| typedef enum [OH_AVRecorder_VideoSourceType](#oh_avrecorder_videosourcetype-1) [OH_AVRecorder_VideoSourceType](#oh_avrecorder_videosourcetype) | Defines an enum for the video source types of the AVRecorder.|
| typedef enum [OH_AVRecorder_CodecMimeType](#oh_avrecorder_codecmimetype-1) [OH_AVRecorder_CodecMimeType](#oh_avrecorder_codecmimetype) | Defines an enum for the MIME types of the encoder.|
| typedef enum [OH_AVRecorder_ContainerFormatType](#oh_avrecorder_containerformattype-1) [OH_AVRecorder_ContainerFormatType](#oh_avrecorder_containerformattype) | Defines an enum for the Container Format Types (CFTs).|
| typedef enum [OH_AVRecorder_State](#oh_avrecorder_state-1) [OH_AVRecorder_State](#oh_avrecorder_state) | Defines an enum for the AVRecorder states.|
| typedef enum [OH_AVRecorder_StateChangeReason](#oh_avrecorder_statechangereason-1) [OH_AVRecorder_StateChangeReason](#oh_avrecorder_statechangereason) | Defines an enum for the reasons for AVRecorder state changes.|
| typedef enum [OH_AVRecorder_FileGenerationMode](#oh_avrecorder_filegenerationmode-1) [OH_AVRecorder_FileGenerationMode](#oh_avrecorder_filegenerationmode) | Defines an enum for the modes available for creating a recording file.|
| typedef struct [OH_AVRecorder_Profile](_o_h___a_v_recorder___profile.md) [OH_AVRecorder_Profile](#oh_avrecorder_profile) | Defines a struct for the parameters used for audio and video recording.<br>You can choose to record only audio or only video by setting the parameters. When **audioBitrate** or **audioChannels** is set to **0**, audio recording is disabled. When **videoFrameWidth** or **videoFrameHeight** is set to **0**, video recording is disabled.|
| typedef struct [OH_AVRecorder_Location](_o_h___a_v_recorder___location.md) [OH_AVRecorder_Location](#oh_avrecorder_location) | Defines a struct for the geographical location information about a media asset.|
| typedef struct [OH_AVRecorder_MetadataTemplate](_o_h___a_v_recorder___metadata_template.md) [OH_AVRecorder_MetadataTemplate](#oh_avrecorder_metadatatemplate) | Defines a struct for the basic template of metadata.|
| typedef struct [OH_AVRecorder_Metadata](_o_h___a_v_recorder___metadata.md) [OH_AVRecorder_Metadata](#oh_avrecorder_metadata) | Defines a struct for the metadata.|
| typedef struct [OH_AVRecorder_Config](_o_h___a_v_recorder___config.md) [OH_AVRecorder_Config](#oh_avrecorder_config) | Defines a struct for the AVRecorder configuration.|
| typedef struct [OH_AVRecorder_Range](_o_h___a_v_recorder___range.md) [OH_AVRecorder_Range](#oh_avrecorder_range) | Defines a struct for the range.|
| typedef struct [OH_AVRecorder_EncoderInfo](_o_h___a_v_recorder___encoder_info.md) [OH_AVRecorder_EncoderInfo](#oh_avrecorder_encoderinfo) | Defines a struct for the encoder information.|
| typedef void(\* [OH_AVRecorder_OnStateChange](#oh_avrecorder_onstatechange)) ([OH_AVRecorder](#oh_avrecorder) \*recorder, [OH_AVRecorder_State](#oh_avrecorder_state) state, [OH_AVRecorder_StateChangeReason](#oh_avrecorder_statechangereason) reason, void \*userData) | Defines a callback invoked when the AVRecorder state changes.|
| typedef void(\* [OH_AVRecorder_OnError](#oh_avrecorder_onerror)) ([OH_AVRecorder](#oh_avrecorder) \*recorder, int32_t errorCode, const char \*errorMsg, void \*userData) | Defines a callback invoked when an error occurs during recording.|
| typedef void(\* [OH_AVRecorder_OnUri](#oh_avrecorder_onuri)) ([OH_AVRecorder](#oh_avrecorder) \*recorder, OH_MediaAsset \*asset, void \*userData) | Defines a callback invoked when the recording is in OH_AVRecorder_FileGenerationMode.AVRECORDER_AUTO_CREATE_CAMERA_SCENE mode.|


### Enums

| Name| Description|
| -------- | -------- |
| [OH_AVRecorder_AudioSourceType](#oh_avrecorder_audiosourcetype-1) {<br>AVRECORDER_DEFAULT = 0,<br>AVRECORDER_MIC = 1,<br>AVRECORDER_VOICE_RECOGNITION = 2,<br>AVRECORDER_VOICE_COMMUNICATION = 7,<br>AVRECORDER_VOICE_MESSAGE = 10,<br>AVRECORDER_CAMCORDER = 13<br>} | Enumerates the audio source types of the AVRecorder.|
| [OH_AVRecorder_VideoSourceType](#oh_avrecorder_videosourcetype-1) {<br>AVRECORDER_SURFACE_YUV = 0,<br>AVRECORDER_SURFACE_ES = 1 } | Enumerates the video source types of the AVRecorder.|
| [OH_AVRecorder_CodecMimeType](#oh_avrecorder_codecmimetype-1) {<br>AVRECORDER_VIDEO_AVC = 2,<br>AVRECORDER_AUDIO_AAC = 3,<br>AVRECORDER_AUDIO_MP3 = 4,<br>AVRECORDER_AUDIO_G711MU = 5,<br>AVRECORDER_VIDEO_MPEG4 = 6,<br>AVRECORDER_VIDEO_HEVC = 8,<br>AVRECORDER_AUDIO_AMR_NB = 9,<br>AVRECORDER_AUDIO_AMR_WB = 10<br>} | Enumerates the MIME types of the encoder.|
| [OH_AVRecorder_ContainerFormatType](#oh_avrecorder_containerformattype-1) {<br>AVRECORDER_CFT_MPEG_4 = 2,<br>AVRECORDER_CFT_MPEG_4A = 6,<br>AVRECORDER_CFT_AMR = 8,<br>AVRECORDER_CFT_MP3 = 9,<br>AVRECORDER_CFT_WAV = 10<br>} | Enumerates the CFTs.|
| [OH_AVRecorder_State](#oh_avrecorder_state-1) {<br>AVRECORDER_IDLE = 0,<br>AVRECORDER_PREPARED = 1,<br>AVRECORDER_STARTED = 2,<br>AVRECORDER_PAUSED = 3,<br>AVRECORDER_STOPPED = 4,<br>AVRECORDER_RELEASED = 5, AVRECORDER_ERROR = 6<br>} | Enumerates the AVRecorder states.|
| [OH_AVRecorder_StateChangeReason](#oh_avrecorder_statechangereason-1) {<br>AVRECORDER_USER = 0,<br>AVRECORDER_BACKGROUND = 1<br>} | Enumerates the reasons for AVRecorder state changes.|
| [OH_AVRecorder_FileGenerationMode](#oh_avrecorder_filegenerationmode-1) {<br>AVRECORDER_APP_CREATE = 0, AVRECORDER_AUTO_CREATE_CAMERA_SCENE = 1<br>} | Enumerates the modes available for creating a recording file.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_AVRecorder](#oh_avrecorder) \* [OH_AVRecorder_Create](#oh_avrecorder_create) (void) | Creates an AVRecorder instance. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_IDLE state.|
| OH_AVErrCode [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) ([OH_AVRecorder](#oh_avrecorder) \*recorder, [OH_AVRecorder_Config](_o_h___a_v_recorder___config.md) \*config) | Sets AVRecorder parameters to prepare for recording. This function must be called after [OH_AVRecorder_Start](#oh_avrecorder_start) is successfully triggered. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_PREPARED state.|
| OH_AVErrCode [OH_AVRecorder_GetAVRecorderConfig](#oh_avrecorder_getavrecorderconfig) ([OH_AVRecorder](#oh_avrecorder) \*recorder, [OH_AVRecorder_Config](_o_h___a_v_recorder___config.md) \*\*config) | Obtains the AVRecorder configuration. This function must be called after the recording preparation is complete. **config** must be set to a null pointer. The framework layer allocates and releases the memory in a unified manner to avoid issues with memory management, such as leaks or double freeing.|
| OH_AVErrCode [OH_AVRecorder_GetInputSurface](#oh_avrecorder_getinputsurface) ([OH_AVRecorder](#oh_avrecorder) \*recorder, OHNativeWindow \*\*window) | Obtains an input surface. This function must be called after [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) is successfully triggered and before [OH_AVRecorder_Start](#oh_avrecorder_start) is called.|
| OH_AVErrCode [OH_AVRecorder_UpdateRotation](#oh_avrecorder_updaterotation) ([OH_AVRecorder](#oh_avrecorder) \*recorder, int32_t rotation) | Updates the video rotation angle. This function must be called after [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) is successfully triggered and before [OH_AVRecorder_Start](#oh_avrecorder_start) is called.|
| OH_AVErrCode [OH_AVRecorder_Start](#oh_avrecorder_start) ([OH_AVRecorder](#oh_avrecorder) \*recorder) | Starts recording. This function must be called after [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) is successfully triggered. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_STARTED state.|
| OH_AVErrCode [OH_AVRecorder_Pause](#oh_avrecorder_pause) ([OH_AVRecorder](#oh_avrecorder) \*recorder) | Pauses recording. This function must be called after [OH_AVRecorder_Start](#oh_avrecorder_start) is successfully triggered and the AVRecorder is in the AVRECORDER_STARTED state. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_PAUSED state.|
| OH_AVErrCode [OH_AVRecorder_Resume](#oh_avrecorder_resume) ([OH_AVRecorder](#oh_avrecorder) \*recorder) | Resumes recording. This function must be called after [OH_AVRecorder_Pause](#oh_avrecorder_pause) is successfully triggered and the AVRecorder is in the AVRECORDER_PAUSED state. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_STARTED state.|
| OH_AVErrCode [OH_AVRecorder_Stop](#oh_avrecorder_stop) ([OH_AVRecorder](#oh_avrecorder) \*recorder) | Stops recording. This function must be called after [OH_AVRecorder_Start](#oh_avrecorder_start) is successfully triggered. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_STOPPED state.|
| OH_AVErrCode [OH_AVRecorder_Reset](#oh_avrecorder_reset) ([OH_AVRecorder](#oh_avrecorder) \*recorder) | Resets the recording state. This function must be called when the AVRecorder is not in the AVRECORDER_RELEASED state. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_IDLE state.|
| OH_AVErrCode [OH_AVRecorder_Release](#oh_avrecorder_release) ([OH_AVRecorder](#oh_avrecorder) \*recorder) | Releases recording resources. After this API is successfully called, the AVRecorder transitions to the AVRECORDER_RELEASED state. The recorder memory will be released. The application layer must explicitly set the recorder to a null pointer to avoid access to wild pointers.|
| OH_AVErrCode [OH_AVRecorder_GetAvailableEncoder](#oh_avrecorder_getavailableencoder) ([OH_AVRecorder](#oh_avrecorder) \*recorder, [OH_AVRecorder_EncoderInfo](_o_h___a_v_recorder___encoder_info.md) \*\*info, int32_t \*length) | Obtains the available encoders and encoder information of the AVRecorder. **info** must be set to a null pointer. The framework layer allocates and releases the memory in a unified manner to avoid issues with memory management, such as leaks or double freeing.|
| OH_AVErrCode [OH_AVRecorder_SetStateCallback](#oh_avrecorder_setstatecallback) ([OH_AVRecorder](#oh_avrecorder) \*recorder, [OH_AVRecorder_OnStateChange](#oh_avrecorder_onstatechange) callback, void \*userData) | Sets a state callback so that the application can respond to state change events generated by the AVRecorder. This function must be called before [OH_AVRecorder_Start](#oh_avrecorder_start) is called.|
| OH_AVErrCode [OH_AVRecorder_SetErrorCallback](#oh_avrecorder_seterrorcallback) ([OH_AVRecorder](#oh_avrecorder) \*recorder, [OH_AVRecorder_OnError](#oh_avrecorder_onerror) callback, void \*userData) | Sets an error callback so that the application can respond to error events generated by the AVRecorder. This function must be called before [OH_AVRecorder_Start](#oh_avrecorder_start) is called.|
| OH_AVErrCode [OH_AVRecorder_SetUriCallback](#oh_avrecorder_seturicallback) ([OH_AVRecorder](#oh_avrecorder) \*recorder, [OH_AVRecorder_OnUri](#oh_avrecorder_onuri) callback, void \*userData) | Sets a URI callback so that the application can respond to URI events generated by the AVRecorder. This function must be called before [OH_AVRecorder_Start](#oh_avrecorder_start) is called.|


## Type Description


### OH_AVRecorder

```
typedef struct OH_AVRecorder OH_AVRecorder
```

**Description**

Defines a struct for the AVRecorder.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


### OH_AVRecorder_AudioSourceType

```
typedef enum OH_AVRecorder_AudioSourceType OH_AVRecorder_AudioSourceType
```

**Description**

Defines an enum for the audio source types of the AVRecorder.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


### OH_AVRecorder_CodecMimeType

```
typedef enum OH_AVRecorder_CodecMimeType OH_AVRecorder_CodecMimeType
```

**Description**

Defines an enum for the MIME types of the encoder.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


### OH_AVRecorder_Config

```
typedef struct OH_AVRecorder_Config OH_AVRecorder_Config
```

**Description**

Defines a struct for the AVRecorder configuration.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


### OH_AVRecorder_ContainerFormatType

```
typedef enum OH_AVRecorder_ContainerFormatType OH_AVRecorder_ContainerFormatType
```

**Description**

Defines an enum for the CFTs.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


### OH_AVRecorder_EncoderInfo

```
typedef struct OH_AVRecorder_EncoderInfo OH_AVRecorder_EncoderInfo
```

**Description**

Defines a struct for the encoder information.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


### OH_AVRecorder_FileGenerationMode

```
typedef enum OH_AVRecorder_FileGenerationMode OH_AVRecorder_FileGenerationMode
```

**Description**

Defines an enum for the modes available for creating a recording file.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


### OH_AVRecorder_Location

```
typedef struct OH_AVRecorder_Location OH_AVRecorder_Location
```

**Description**

Defines a struct for the geographical location information about a media asset.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


### OH_AVRecorder_Metadata

```
typedef struct OH_AVRecorder_Metadata OH_AVRecorder_Metadata
```

**Description**

Defines a struct for the metadata.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


### OH_AVRecorder_MetadataTemplate

```
typedef struct OH_AVRecorder_MetadataTemplate OH_AVRecorder_MetadataTemplate
```

**Description**

Defines a struct for the basic template of metadata.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


### OH_AVRecorder_OnError

```
typedef void (*OH_AVRecorder_OnError)(OH_AVRecorder *recorder, int32_t errorCode, const char *errorMsg, void *userData)
```

**Description**

Defines a callback invoked when an error occurs during recording.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| recorder | Pointer to an **OH_AVRecorder** instance.|
| errorCode | Error code.|
| errorMsg | Pointer to the error message.|
| userData | Pointer to user-defined data.|


### OH_AVRecorder_OnStateChange

```
typedef void (*OH_AVRecorder_OnStateChange)(OH_AVRecorder *recorder, OH_AVRecorder_State state, OH_AVRecorder_StateChangeReason reason, void *userData)
```

**Description**

Defines a callback invoked when the AVRecorder state changes.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| recorder | Pointer to an **OH_AVRecorder** instance.|
| state | AVRecorder state. For details, see [OH_AVRecorder_State](#oh_avrecorder_state).|
| reason | Reason for the AVRecorder state change. For details, see [OH_AVRecorder_StateChangeReason](#oh_avrecorder_statechangereason).|
| userData | Pointer to user-defined data.|


### OH_AVRecorder_OnUri

```
typedef void (*OH_AVRecorder_OnUri)(OH_AVRecorder *recorder, OH_MediaAsset *asset, void *userData)
```

**Description**

Defines a callback invoked when the recording is in OH_AVRecorder_FileGenerationMode.AVRECORDER_AUTO_CREATE_CAMERA_SCENE mode.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| recorder | Pointer to an **OH_AVRecorder** instance.|
| asset | Pointer to an **OH_MediaAsset** instance.|
| userData | Pointer to user-defined data.|


### OH_AVRecorder_Profile

```
typedef struct OH_AVRecorder_Profile OH_AVRecorder_Profile
```

**Description**

Defines a struct for the parameters used for audio and video recording.

You can choose to record only audio or only video by setting the parameters. When **audioBitrate** or **audioChannels** is set to **0**, audio recording is disabled. When **videoFrameWidth** or **videoFrameHeight** is set to **0**, video recording is disabled.

For details about the value range of each parameter, see [AVRecorderProfile](js-apis-media.md#avrecorderprofile9).

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


### OH_AVRecorder_Range

```
typedef struct OH_AVRecorder_Range OH_AVRecorder_Range
```

**Description**

Defines a struct for the range.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


### OH_AVRecorder_State

```
typedef enum OH_AVRecorder_State OH_AVRecorder_State
```

**Description**

Defines an enum for the AVRecorder states.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


### OH_AVRecorder_StateChangeReason

```
typedef enum OH_AVRecorder_StateChangeReason OH_AVRecorder_StateChangeReason
```

**Description**

Defines an enum for the reasons for AVRecorder state changes.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


### OH_AVRecorder_VideoSourceType

```
typedef enum OH_AVRecorder_VideoSourceType OH_AVRecorder_VideoSourceType
```

**Description**

Defines an enum for the video source types of the AVRecorder.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


## Enum Description


### OH_AVRecorder_AudioSourceType

```
enum OH_AVRecorder_AudioSourceType
```

**Description**

Enumerates the audio source types of the AVRecorder.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

| Value| Description|
| -------- | -------- |
| AVRECORDER_DEFAULT | Default audio source.|
| AVRECORDER_MIC | Microphone audio source.|
| AVRECORDER_VOICE_RECOGNITION | Audio source in speech recognition scenarios.|
| AVRECORDER_VOICE_COMMUNICATION | Voice communication source.|
| AVRECORDER_VOICE_MESSAGE | Voice message source.|
| AVRECORDER_CAMCORDER | Audio source in camera recording scenarios.|


### OH_AVRecorder_CodecMimeType

```
enum OH_AVRecorder_CodecMimeType
```

**Description**

Enumerates the MIME types of the encoder.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

| Value| Description|
| -------- | -------- |
| AVRECORDER_VIDEO_AVC | MIME type of the H.264 encoder.|
| AVRECORDER_AUDIO_AAC | MIME type of the AAC encoder.|
| AVRECORDER_AUDIO_MP3 | MIME type of the MP3 encoder.|
| AVRECORDER_AUDIO_G711MU | MIME type of the G711-mulaw encoder.|
| AVRECORDER_VIDEO_MPEG4 | MIME type of the MPEG4 encoder.|
| AVRECORDER_VIDEO_HEVC | MIME type of the H.265 encoder.|
| AVRECORDER_AUDIO_AMR_NB | MIME type of the AMR-NB codec.|
| AVRECORDER_AUDIO_AMR_WB | MIME type of the AMR-WB codec.|


### OH_AVRecorder_ContainerFormatType

```
enum OH_AVRecorder_ContainerFormatType
```

**Description**

Enumerates the CFTs.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

| Value| Description|
| -------- | -------- |
| AVRECORDER_CFT_MPEG_4 | Video container format mp4.|
| AVRECORDER_CFT_MPEG_4A | Audio container format m4a.|
| AVRECORDER_CFT_AMR | Audio container format amr.|
| AVRECORDER_CFT_MP3 | Audio container format mp3.|
| AVRECORDER_CFT_WAV | Audio container format wav.|


### OH_AVRecorder_FileGenerationMode

```
enum OH_AVRecorder_FileGenerationMode
```

**Description**

Enumerates the modes available for creating a recording file.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

| Value| Description|
| -------- | -------- |
| AVRECORDER_APP_CREATE | The application creates a media file in the sandbox.|
| AVRECORDER_AUTO_CREATE_CAMERA_SCENE | The system creates a media file. Currently, this mode takes effect only in camera recording scenarios. The URL set by the application is ignored.|


### OH_AVRecorder_State

```
enum OH_AVRecorder_State
```

**Description**

Enumerates the AVRecorder states.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

| Value| Description|
| -------- | -------- |
| AVRECORDER_IDLE | Idle. In this state, you can call **OH_AVRecorder_Prepare()** to set recording parameters, and the AVRecorder transitions to the AVRECORDER_PREPARED state.|
| AVRECORDER_PREPARED | Prepared. After the parameters are set, you can call **OH_AVRecorder_Start()** to start recording, and the AVRecorder transitions to the AVRECORDER_STARTED state.|
| AVRECORDER_STARTED | Started. Recording is in progress. In this case, you can call **OH_AVRecorder_Pause()** to pause recording, and the AVRecorder transitions to the AVRECORDER_PAUSED state. You can also call **OH_AVRecorder_Stop()** to stop recording, and the AVRecorder transitions to the AVRECORDER_STOPPED state.|
| AVRECORDER_PAUSED | Paused. In this state, you can call **OH_AVRecorder_Resume()** to resume recording, and the AVRecorder transitions to the AVRECORDER_STARTED state. You can also call **OH_AVRecorder_Stop()** to stop recording, and the AVRecorder transitions to the AVRECORDER_STOPPED state.|
| AVRECORDER_STOPPED | Stopped. In this state, you can call **OH_AVRecorder_Prepare()** to set recording parameters, and the AVRecorder transitions to the AVRECORDER_PREPARED state again.|
| AVRECORDER_RELEASED | Released. The recording resources are released. No operation can be performed at this time. In any other state, you can call **OH_AVRecorder_Release()** to transition to the AVRECORDER_RELEASED state.|
| AVRECORDER_ERROR | Error state. The AVRecorder transitions to this state when an irreversible error occurs in the instance. In this state, the OH_AVRecorder_OnError event is reported, with the detailed error cause. You should call **OH_AVRecorder_Reset()** to reset the AVRecorder instance or call **OH_AVRecorder_Release()** to release resources.|


### OH_AVRecorder_StateChangeReason

```
enum OH_AVRecorder_StateChangeReason
```

**Description**

Enumerates the reasons for AVRecorder state changes.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

| Value| Description|
| -------- | -------- |
| AVRECORDER_USER | The state change is caused by user operations.|
| AVRECORDER_BACKGROUND | The state change is caused by background operations.|


### OH_AVRecorder_VideoSourceType

```
enum OH_AVRecorder_VideoSourceType
```

**Description**

Enumerates the video source types of the AVRecorder.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

| Value| Description|
| -------- | -------- |
| AVRECORDER_SURFACE_YUV | Raw data surface.|
| AVRECORDER_SURFACE_ES | ES data surface.|


## Function Description


### OH_AVRecorder_Create()

```
OH_AVRecorder *OH_AVRecorder_Create(void)
```

**Description**

Creates an AVRecorder instance. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_IDLE state.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Returns**

Returns the pointer to the **OH_AVRecorder** instance created if the operation is successful; returns a null pointer otherwise.


### OH_AVRecorder_GetAvailableEncoder()

```
OH_AVErrCode OH_AVRecorder_GetAvailableEncoder(OH_AVRecorder *recorder, OH_AVRecorder_EncoderInfo **info, int32_t *length)
```

**Description**

Obtains the available encoders and encoder information of the AVRecorder. **info** must be set to a null pointer. The framework layer allocates and releases the memory in a unified manner to avoid issues with memory management, such as leaks or double freeing.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| recorder | Pointer to an **OH_AVRecorder** instance.|
| info | Double pointer to an [OH_AVRecorder_EncoderInfo](_o_h___a_v_recorder___encoder_info.md) instance. For details, see [OH_AVRecorder_EncoderInfo](_o_h___a_v_recorder___encoder_info.md).|
| length | Pointer to the number of available encoders.|

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The input parameter **recorder** is a null pointer.

**AV_ERR_NO_MEMORY**: The memory fails to be allocated due to insufficient memory.


### OH_AVRecorder_GetAVRecorderConfig()

```
OH_AVErrCode OH_AVRecorder_GetAVRecorderConfig(OH_AVRecorder *recorder, OH_AVRecorder_Config **config)
```

**Description**

Obtains the AVRecorder configuration. This function must be called after the recording preparation is complete. **config** must be set to a null pointer. The framework layer allocates and releases the memory in a unified manner to avoid issues with memory management, such as leaks or double freeing.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| recorder | Pointer to an **OH_AVRecorder** instance.|
| config | Double pointer to the [OH_AVRecorder_Config](_o_h___a_v_recorder___config.md) instance. For details, see [OH_AVRecorder_Config](_o_h___a_v_recorder___config.md).|

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The input parameter **recorder** is a null pointer or **config** is not a null pointer.

**AV_ERR_NO_MEMORY**: The memory fails to be allocated due to insufficient memory.


### OH_AVRecorder_GetInputSurface()

```
OH_AVErrCode OH_AVRecorder_GetInputSurface(OH_AVRecorder *recorder, OHNativeWindow **window)
```

**Description**

Obtains an input surface. This function must be called after [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) is successfully triggered and before [OH_AVRecorder_Start](#oh_avrecorder_start) is called.

The caller obtains the **surfaceBuffer** from this surface and fills in the corresponding video data.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| recorder | Pointer to an **OH_AVRecorder** instance.|
| window | Double pointer to an **OHNativeWindow** instance. For details, see **OHNativeWindow**.|

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The input parameter **recorder** is a null pointer.


### OH_AVRecorder_Pause()

```
OH_AVErrCode OH_AVRecorder_Pause(OH_AVRecorder *recorder)
```

**Description**

Pauses recording. This function must be called after [OH_AVRecorder_Start](#oh_avrecorder_start) is successfully triggered and the AVRecorder is in the AVRECORDER_STARTED state. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_PAUSED state.

Then, you can call [OH_AVRecorder_Resume](#oh_avrecorder_resume) to resume recording, and the AVRecorder transitions the AVRECORDER_STARTED state again.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| recorder | Pointer to an **OH_AVRecorder** instance.|

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The input parameter **recorder** is a null pointer or the pause operation fails.


### OH_AVRecorder_Prepare()

```
OH_AVErrCode OH_AVRecorder_Prepare(OH_AVRecorder *recorder, OH_AVRecorder_Config *config)
```

**Description**

Sets AVRecorder parameters to prepare for recording. This function must be called after [OH_AVRecorder_Start](#oh_avrecorder_start) is successfully triggered. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_PREPARED state.

To record only audio, you do not need to set video parameters. Similarly, to record only video, you do not need to set audio parameters.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| recorder | Pointer to an **OH_AVRecorder** instance.|
| config | Pointer to an [OH_AVRecorder_Config](_o_h___a_v_recorder___config.md) instance. For details, see [OH_AVRecorder_Config](_o_h___a_v_recorder___config.md).|

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The input parameter **recorder** is a null pointer or the preparation fails.


### OH_AVRecorder_Release()

```
OH_AVErrCode OH_AVRecorder_Release(OH_AVRecorder *recorder)
```

**Description**

Releases recording resources. After this API is successfully called, the AVRecorder transitions to the AVRECORDER_RELEASED state. The recorder memory will be released. The application layer must explicitly set the recorder to a null pointer to avoid access to wild pointers.

After the resources are released, you can no longer perform any operation on the **OH_AVRecorder** instance.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| recorder | Pointer to an **OH_AVRecorder** instance.|

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The input parameter **recorder** is a null pointer or the release operation fails.


### OH_AVRecorder_Reset()

```
OH_AVErrCode OH_AVRecorder_Reset(OH_AVRecorder *recorder)
```

**Description**

Resets the recording state. This function must be called when the AVRecorder is not in the AVRECORDER_RELEASED state. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_IDLE state.

For audio-only recording, you can call [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) again for re-recording. For video-only recording or audio and video recording, you can call [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) and [OH_AVRecorder_GetInputSurface](#oh_avrecorder_getinputsurface) again for re-recording.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| recorder | Pointer to an **OH_AVRecorder** instance.|

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The input parameter **recorder** is a null pointer or the resetting operation fails.


### OH_AVRecorder_Resume()

```
OH_AVErrCode OH_AVRecorder_Resume(OH_AVRecorder *recorder)
```

**Description**

Resumes recording. This function must be called after [OH_AVRecorder_Pause](#oh_avrecorder_pause) is successfully triggered and the AVRecorder is in the AVRECORDER_PAUSED state. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_STARTED state.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| recorder | Pointer to an **OH_AVRecorder** instance.|

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The input parameter **recorder** is a null pointer or the resumption operation fails.


### OH_AVRecorder_SetErrorCallback()

```
OH_AVErrCode OH_AVRecorder_SetErrorCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnError callback, void *userData)
```

**Description**

Sets an error callback so that the application can respond to error events generated by the AVRecorder. This function must be called before [OH_AVRecorder_Start](#oh_avrecorder_start) is called.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| recorder | Pointer to an **OH_AVRecorder** instance.|
| callback | Error callback. For details, see [OH_AVRecorder_OnError](#oh_avrecorder_onerror).|
| userData | Pointer to user-defined data.|

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The input parameter **recorder** or **callback** is a null pointer.


### OH_AVRecorder_SetStateCallback()

```
OH_AVErrCode OH_AVRecorder_SetStateCallback( OH_AVRecorder *recorder, OH_AVRecorder_OnStateChange callback, void *userData)
```

**Description**

Sets a state callback so that the application can respond to state change events generated by the AVRecorder. This function must be called before [OH_AVRecorder_Start](#oh_avrecorder_start) is called.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| recorder | Pointer to an **OH_AVRecorder** instance.|
| callback | State callback. For details, see [OH_AVRecorder_OnStateChange](#oh_avrecorder_onstatechange).|
| userData | Pointer to user-defined data.|

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The input parameter **recorder** or **callback** is a null pointer.


### OH_AVRecorder_SetUriCallback()

```
OH_AVErrCode OH_AVRecorder_SetUriCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnUri callback, void *userData)
```

**Description**

Sets a URI callback so that the application can respond to URI events generated by the AVRecorder. This function must be called before [OH_AVRecorder_Start](#oh_avrecorder_start) is called.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| recorder | Pointer to an **OH_AVRecorder** instance.|
| callback | URI callback. For details, see [OH_AVRecorder_OnUri](#oh_avrecorder_onuri).|
| userData | Pointer to user-defined data.|

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The input parameter **recorder** or **callback** is a null pointer.


### OH_AVRecorder_Start()

```
OH_AVErrCode OH_AVRecorder_Start(OH_AVRecorder *recorder)
```

**Description**

Starts recording. This function must be called after [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) is successfully triggered. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_STARTED state.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| recorder | Pointer to an **OH_AVRecorder** instance.|

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The input parameter **recorder** is a null pointer or recording fails to start.


### OH_AVRecorder_Stop()

```
OH_AVErrCode OH_AVRecorder_Stop(OH_AVRecorder *recorder)
```

**Description**

Stops recording. This function must be called after [OH_AVRecorder_Start](#oh_avrecorder_start) is successfully triggered. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_STOPPED state.

For audio-only recording, you can call [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) again for re-recording. For video-only recording or audio and video recording, you can call [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) and [OH_AVRecorder_GetInputSurface](#oh_avrecorder_getinputsurface) again for re-recording.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| recorder | Pointer to an **OH_AVRecorder** instance.|

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The input parameter **recorder** is a null pointer or recording fails to stop.


### OH_AVRecorder_UpdateRotation()

```
OH_AVErrCode OH_AVRecorder_UpdateRotation(OH_AVRecorder *recorder, int32_t rotation)
```

**Description**

Updates the video rotation angle. This function must be called after [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) is successfully triggered and before [OH_AVRecorder_Start](#oh_avrecorder_start) is called.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| recorder | Pointer to an **OH_AVRecorder** instance.|
| rotation | Video rotation angle. The value must be an integer in the range [0, 90, 180, 270].|

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The input parameter **recorder** is a null pointer, **rotation** is invalid, or the update operation fails.
