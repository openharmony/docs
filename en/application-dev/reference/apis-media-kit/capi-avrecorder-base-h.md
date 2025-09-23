# avrecorder_base.h
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @shiwei75-->
<!--Designer: @HmQQQ-->
<!--Tester: @xdlinc-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the struct and enums used by the AVRecorder.

**File to include**: <multimedia/player_framework/avrecorder_base.h>

**Library**: libavrecorder.so

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Related module**: [AVRecorder](capi-avrecorder.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AVRecorder_Profile](capi-avrecorder-oh-avrecorder-profile.md) | OH_AVRecorder_Profile | Describes the parameters used for audio and video recording.|
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) | OH_AVRecorder | Describes an initialized AVRecorder.|
| [OH_AVRecorder_Location](capi-avrecorder-oh-avrecorder-location.md) | OH_AVRecorder_Location | Describes the geographical location information about a media asset.|
| [OH_AVRecorder_MetadataTemplate](capi-avrecorder-oh-avrecorder-metadatatemplate.md) | OH_AVRecorder_MetadataTemplate | Describes the basic template of metadata.|
| [OH_AVRecorder_Metadata](capi-avrecorder-oh-avrecorder-metadata.md) | OH_AVRecorder_Metadata | Describes the metadata.|
| [OH_AVRecorder_Config](capi-avrecorder-oh-avrecorder-config.md) | OH_AVRecorder_Config | Describes the AVRecorder configuration.|
| [OH_AVRecorder_Range](capi-avrecorder-oh-avrecorder-range.md) | OH_AVRecorder_Range | Describes the range.|
| [OH_AVRecorder_EncoderInfo](capi-avrecorder-oh-avrecorder-encoderinfo.md) | OH_AVRecorder_EncoderInfo | Describes the encoder information.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AVRecorder_AudioSourceType](#oh_avrecorder_audiosourcetype) | OH_AVRecorder_AudioSourceType | Enumerates the audio source types of the AVRecorder.|
| [OH_AVRecorder_VideoSourceType](#oh_avrecorder_videosourcetype) | OH_AVRecorder_VideoSourceType | Enumerates the video source types of the AVRecorder.|
| [OH_AVRecorder_CodecMimeType](#oh_avrecorder_codecmimetype) | OH_AVRecorder_CodecMimeType | Enumerates the MIME types of the encoder.|
| [OH_AVRecorder_ContainerFormatType](#oh_avrecorder_containerformattype) | OH_AVRecorder_ContainerFormatType | Enumerates the Container Format Types (CFTs).|
| [OH_AVRecorder_State](#oh_avrecorder_state) | OH_AVRecorder_State | Enumerates the AVRecorder states.|
| [OH_AVRecorder_StateChangeReason](#oh_avrecorder_statechangereason) | OH_AVRecorder_StateChangeReason | Enumerates the reasons for AVRecorder state changes.|
| [OH_AVRecorder_FileGenerationMode](#oh_avrecorder_filegenerationmode) | OH_AVRecorder_FileGenerationMode | Enumerates the modes available for creating a recording file.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_AVRecorder_OnStateChange)(OH_AVRecorder *recorder, OH_AVRecorder_State state, OH_AVRecorder_StateChangeReason reason, void *userData)](#oh_avrecorder_onstatechange) | OH_AVRecorder_OnStateChange | Called when the AVRecorder state changes.|
| [typedef void (\*OH_AVRecorder_OnError)(OH_AVRecorder *recorder, int32_t errorCode, const char *errorMsg, void *userData)](#oh_avrecorder_onerror) | OH_AVRecorder_OnError | Called when an error occurs during recording.|
| [typedef void (\*OH_AVRecorder_OnUri)(OH_AVRecorder *recorder, OH_MediaAsset *asset, void *userData)](#oh_avrecorder_onuri) | OH_AVRecorder_OnUri | Called when the recording is in [OH_AVRecorder_FileGenerationMode](#oh_avrecorder_filegenerationmode).AVRECORDER_AUTO_CREATE_CAMERA_SCENE mode.|

## Enum Description

### OH_AVRecorder_AudioSourceType

```
enum OH_AVRecorder_AudioSourceType
```

**Description**

Enumerates the audio source types of the AVRecorder.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

| Enum Item| Description|
| -- | -- |
| AVRECORDER_DEFAULT = 0 | Default audio source.|
| AVRECORDER_MIC = 1 | Microphone audio source.|
| AVRECORDER_VOICE_RECOGNITION = 2 | Audio source in speech recognition scenarios.|
| AVRECORDER_VOICE_COMMUNICATION = 7 | Voice communication source.|
| AVRECORDER_VOICE_MESSAGE = 10 | Voice message source.|
| AVRECORDER_CAMCORDER = 13 | Audio source in camera recording scenarios.|

### OH_AVRecorder_VideoSourceType

```
enum OH_AVRecorder_VideoSourceType
```

**Description**

Enumerates the video source types of the AVRecorder.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

| Enum Item| Description|
| -- | -- |
| AVRECORDER_SURFACE_YUV = 0 | Raw data surface.|
| AVRECORDER_SURFACE_ES = 1 | ES data surface.|

### OH_AVRecorder_CodecMimeType

```
enum OH_AVRecorder_CodecMimeType
```

**Description**

Enumerates the MIME types of the encoder.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

| Enum Item| Description|
| -- | -- |
| AVRECORDER_VIDEO_AVC = 2 | MIME type of the H.264 encoder.|
| AVRECORDER_AUDIO_AAC = 3 | MIME type of the AAC encoder.|
| AVRECORDER_AUDIO_MP3 = 4 | MIME type of the MP3 encoder.|
| AVRECORDER_AUDIO_G711MU = 5 | MIME type of the G711-mulaw encoder.|
| AVRECORDER_VIDEO_MPEG4 = 6 | MIME type of the MPEG4 encoder.|
| AVRECORDER_VIDEO_HEVC = 8 | MIME type of the H.265 encoder.|
| AVRECORDER_AUDIO_AMR_NB = 9 | MIME type of the AMR-NB codec.|
| AVRECORDER_AUDIO_AMR_WB = 10 | MIME type of the AMR-WB codec.|

### OH_AVRecorder_ContainerFormatType

```
enum OH_AVRecorder_ContainerFormatType
```

**Description**

Enumerates the Container Format Types (CFTs).

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

| Enum Item| Description|
| -- | -- |
| AVRECORDER_CFT_MPEG_4 = 2 | Video container format mp4.|
| AVRECORDER_CFT_MPEG_4A = 6 | Audio container format m4a.|
| AVRECORDER_CFT_AMR = 8 | Audio container format amr.|
| AVRECORDER_CFT_MP3 = 9 | Audio container format mp3.|
| AVRECORDER_CFT_WAV = 10 | Audio container format wav.|
| AVRECORDER_CFT_AAC = 11 | Audio container format aac (with ADTS header).<br>**Since**: 20|

### OH_AVRecorder_State

```
enum OH_AVRecorder_State
```

**Description**

Enumerates the AVRecorder states.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

| Enum Item| Description|
| -- | -- |
| AVRECORDER_IDLE = 0 | Idle. In this state, you can call [OH_AVRecorder_Prepare](capi-avrecorder-h.md#oh_avrecorder_prepare) to set recording parameters, and the AVRecorder transitions to the AVRECORDER_PREPARED state.|
| AVRECORDER_PREPARED = 1 | Prepared. After the parameters are set, you can call [OH_AVRecorder_Start](capi-avrecorder-h.md#oh_avrecorder_start) to start recording, and the AVRecorder transitions to the AVRECORDER_STARTED state.|
| AVRECORDER_STARTED = 2 | Started. Recording is in progress. In this case, you can call [OH_AVRecorder_Pause](capi-avrecorder-h.md#oh_avrecorder_pause) to pause recording, and the AVRecorder transitions to the AVRECORDER_PAUSED state.<br>You can also call [OH_AVRecorder_Stop](capi-avrecorder-h.md#oh_avrecorder_stop) to stop recording, and the AVRecorder transitions to the AVRECORDER_STOPPED state.|
| AVRECORDER_PAUSED = 3 | Paused. In this state, you can call [OH_AVRecorder_Resume](capi-avrecorder-h.md#oh_avrecorder_resume) to resume recording, and the AVRecorder transitions to the AVRECORDER_STARTED state.<br>You can also call [OH_AVRecorder_Stop](capi-avrecorder-h.md#oh_avrecorder_stop) to stop recording, and the AVRecorder transitions to the AVRECORDER_STOPPED state.|
| AVRECORDER_STOPPED = 4 | Stopped. In this state, you can call [OH_AVRecorder_Prepare](capi-avrecorder-h.md#oh_avrecorder_prepare) to set recording parameters, and the AVRecorder transitions to the AVRECORDER_PREPARED state again.|
| AVRECORDER_RELEASED = 5 | Released. The recording resources are released. No operation can be performed at this time. In any other state, you can call [OH_AVRecorder_Release](capi-avrecorder-h.md#oh_avrecorder_release) to transition to the AVRECORDER_RELEASED state.|
| AVRECORDER_ERROR = 6 | Error state. The AVRecorder transitions to this state when an irreversible error occurs in the instance.<br>In this state, the [OH_AVRecorder_OnError](#oh_avrecorder_onerror) event is reported, with the detailed error cause.<br>You should call [OH_AVRecorder_Reset](capi-avrecorder-h.md#oh_avrecorder_reset) to reset the AVRecorder instance or call [OH_AVRecorder_Release](capi-avrecorder-h.md#oh_avrecorder_release) to release resources.|

### OH_AVRecorder_StateChangeReason

```
enum OH_AVRecorder_StateChangeReason
```

**Description**

Enumerates the reasons for AVRecorder state changes.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

| Enum Item| Description|
| -- | -- |
| AVRECORDER_USER = 0 | The state change is caused by user operations.|
| AVRECORDER_BACKGROUND = 1 | The state change is caused by background operations.|

### OH_AVRecorder_FileGenerationMode

```
enum OH_AVRecorder_FileGenerationMode
```

**Description**

Enumerates the modes available for creating a recording file.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

| Enum Item| Description|
| -- | -- |
| AVRECORDER_APP_CREATE = 0 | The application creates a media file in the sandbox.|
| AVRECORDER_AUTO_CREATE_CAMERA_SCENE = 1 | The system creates a media file. This value is valid only in camera recording scenarios.|


## Function Description

### OH_AVRecorder_OnStateChange()

```
typedef void (*OH_AVRecorder_OnStateChange)(OH_AVRecorder *recorder,OH_AVRecorder_State state, OH_AVRecorder_StateChangeReason reason, void *userData)
```

**Description**

Called when the AVRecorder state changes.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | Pointer to the OH_AVRecorder instance.|
| [OH_AVRecorder_State](#oh_avrecorder_state) state | AVRecorder state.|
| [OH_AVRecorder_StateChangeReason](#oh_avrecorder_statechangereason) reason | Reason for the AVRecorder state change.|
|  void *userData | Pointer to user-defined data.|

### OH_AVRecorder_OnError()

```
typedef void (*OH_AVRecorder_OnError)(OH_AVRecorder *recorder, int32_t errorCode, const char *errorMsg,void *userData)
```

**Description**

Called when an error occurs during recording.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | Pointer to the OH_AVRecorder instance.|
|  int32_t errorCode | Error code. For details, see [AVErrorCode](../apis-avcodec-kit/_core.md#oh_averrcode-1).|
|  const char *errorMsg | Pointer to the error message.|
| void *userData | Pointer to user-defined data.|

### OH_AVRecorder_OnUri()

```
typedef void (*OH_AVRecorder_OnUri)(OH_AVRecorder *recorder, OH_MediaAsset *asset, void *userData)
```

**Description**

Called when the recording is in [OH_AVRecorder_FileGenerationMode](#oh_avrecorder_filegenerationmode).AVRECORDER_AUTO_CREATE_CAMERA_SCENE mode.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | Pointer to the OH_AVRecorder instance.|
| [OH_MediaAsset](../apis-media-library-kit/capi-mediaassetmanager-oh-mediaasset.md) *asset | Pointer to the OH_MediaAsset instance.|
|  void *userData | Pointer to user-defined data.|
