# avrecorder_base.h


## Overview

The **avrecorder_base.h** file declares the struct and enums used by the AVRecorder.

**Library**: libavrecorder.so

**File to include**: &lt;multimedia/player_framework/avrecorder_base.h&gt;

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Related module**: [AVRecorder](_a_v_recorder.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[OH_AVRecorder_Profile](_o_h___a_v_recorder___profile.md) | Describes the parameters used for audio and video recording.<br>You can choose to record only audio or only video by setting the parameters. When **audioBitrate** or **audioChannels** is set to 0, audio recording is disabled. When **videoFrameWidth** or **videoFrameHeight** is set to 0, video recording is disabled.| 
| struct&nbsp;&nbsp;[OH_AVRecorder_Location](_o_h___a_v_recorder___location.md) | Describes the geographical location information about a media asset.| 
| struct&nbsp;&nbsp;[OH_AVRecorder_MetadataTemplate](_o_h___a_v_recorder___metadata_template.md) | Describes the basic template of metadata.| 
| struct&nbsp;&nbsp;[OH_AVRecorder_Metadata](_o_h___a_v_recorder___metadata.md) | Describes the metadata.| 
| struct&nbsp;&nbsp;[OH_AVRecorder_Config](_o_h___a_v_recorder___config.md) | Describes the AVRecorder configuration.| 
| struct&nbsp;&nbsp;[OH_AVRecorder_Range](_o_h___a_v_recorder___range.md) | Describes the range.| 
| struct&nbsp;&nbsp;[OH_AVRecorder_EncoderInfo](_o_h___a_v_recorder___encoder_info.md) | Describes the encoder information.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) [OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) | Defines a struct for the AVRecorder.| 
| typedef enum [OH_AVRecorder_AudioSourceType](_a_v_recorder.md#oh_avrecorder_audiosourcetype-1) [OH_AVRecorder_AudioSourceType](_a_v_recorder.md#oh_avrecorder_audiosourcetype) | Defines an enum for the audio source types of the AVRecorder.| 
| typedef enum [OH_AVRecorder_VideoSourceType](_a_v_recorder.md#oh_avrecorder_videosourcetype-1) [OH_AVRecorder_VideoSourceType](_a_v_recorder.md#oh_avrecorder_videosourcetype) | Defines an enum for the video source types of the AVRecorder.| 
| typedef enum [OH_AVRecorder_CodecMimeType](_a_v_recorder.md#oh_avrecorder_codecmimetype-1) [OH_AVRecorder_CodecMimeType](_a_v_recorder.md#oh_avrecorder_codecmimetype) | Defines an enum for the MIME types of the encoder.| 
| typedef enum [OH_AVRecorder_ContainerFormatType](_a_v_recorder.md#oh_avrecorder_containerformattype-1) [OH_AVRecorder_ContainerFormatType](_a_v_recorder.md#oh_avrecorder_containerformattype) | Defines an enum for the Container Format Types (CFTs).| 
| typedef enum [OH_AVRecorder_State](_a_v_recorder.md#oh_avrecorder_state-1) [OH_AVRecorder_State](_a_v_recorder.md#oh_avrecorder_state) | Defines an enum for the AVRecorder states.| 
| typedef enum [OH_AVRecorder_StateChangeReason](_a_v_recorder.md#oh_avrecorder_statechangereason-1) [OH_AVRecorder_StateChangeReason](_a_v_recorder.md#oh_avrecorder_statechangereason) | Defines an enum for the reasons for AVRecorder state changes.| 
| typedef enum [OH_AVRecorder_FileGenerationMode](_a_v_recorder.md#oh_avrecorder_filegenerationmode-1) [OH_AVRecorder_FileGenerationMode](_a_v_recorder.md#oh_avrecorder_filegenerationmode) | Defines an enum for the modes available for creating a recording file.| 
| typedef struct [OH_AVRecorder_Profile](_o_h___a_v_recorder___profile.md) [OH_AVRecorder_Profile](_a_v_recorder.md#oh_avrecorder_profile) | Defines a struct for the parameters used for audio and video recording.<br>You can choose to record only audio or only video by setting the parameters. When **audioBitrate** or **audioChannels** is set to 0, audio recording is disabled. When **videoFrameWidth** or **videoFrameHeight** is set to 0, video recording is disabled.| 
| typedef struct [OH_AVRecorder_Location](_o_h___a_v_recorder___location.md) [OH_AVRecorder_Location](_a_v_recorder.md#oh_avrecorder_location) | Defines a struct for the geographical location information about a media asset.| 
| typedef struct [OH_AVRecorder_MetadataTemplate](_o_h___a_v_recorder___metadata_template.md) [OH_AVRecorder_MetadataTemplate](_a_v_recorder.md#oh_avrecorder_metadatatemplate) | Defines a struct for the basic template of metadata.| 
| typedef struct [OH_AVRecorder_Metadata](_o_h___a_v_recorder___metadata.md) [OH_AVRecorder_Metadata](_a_v_recorder.md#oh_avrecorder_metadata) | Defines a struct for the metadata.| 
| typedef struct [OH_AVRecorder_Config](_o_h___a_v_recorder___config.md) [OH_AVRecorder_Config](_a_v_recorder.md#oh_avrecorder_config) | Defines a struct for the AVRecorder configuration.| 
| typedef struct [OH_AVRecorder_Range](_o_h___a_v_recorder___range.md) [OH_AVRecorder_Range](_a_v_recorder.md#oh_avrecorder_range) | Defines a struct for the range.| 
| typedef struct [OH_AVRecorder_EncoderInfo](_o_h___a_v_recorder___encoder_info.md) [OH_AVRecorder_EncoderInfo](_a_v_recorder.md#oh_avrecorder_encoderinfo) | Defines a struct for the encoder information.| 
| typedef void(\* [OH_AVRecorder_OnStateChange](_a_v_recorder.md#oh_avrecorder_onstatechange)) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder, [OH_AVRecorder_State](_a_v_recorder.md#oh_avrecorder_state) state, [OH_AVRecorder_StateChangeReason](_a_v_recorder.md#oh_avrecorder_statechangereason) reason, void \*userData) | Defines a callback invoked when the AVRecorder state changes.| 
| typedef void(\* [OH_AVRecorder_OnError](_a_v_recorder.md#oh_avrecorder_onerror)) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder, int32_t errorCode, const char \*errorMsg, void \*userData) | Defines a callback invoked when an error occurs during recording.| 
| typedef void(\* [OH_AVRecorder_OnUri](_a_v_recorder.md#oh_avrecorder_onuri)) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder, OH_MediaAsset \*asset, void \*userData) | Defines a callback invoked when the recording is in OH_AVRecorder_FileGenerationMode.AVRECORDER_AUTO_CREATE_CAMERA_SCENE mode.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_AVRecorder_AudioSourceType](_a_v_recorder.md#oh_avrecorder_audiosourcetype-1) {<br>AVRECORDER_DEFAULT = 0,<br>AVRECORDER_MIC = 1,<br>AVRECORDER_VOICE_RECOGNITION = 2,<br>AVRECORDER_VOICE_COMMUNICATION = 7,<br>AVRECORDER_VOICE_MESSAGE = 10,<br>AVRECORDER_CAMCORDER = 13<br>} | Enumerates the audio source types of the AVRecorder.| 
| [OH_AVRecorder_VideoSourceType](_a_v_recorder.md#oh_avrecorder_videosourcetype-1) {<br>AVRECORDER_SURFACE_YUV = 0,<br>AVRECORDER_SURFACE_ES = 1<br>} | Enumerates the video source types of the AVRecorder.| 
| [OH_AVRecorder_CodecMimeType](_a_v_recorder.md#oh_avrecorder_codecmimetype-1) {<br>AVRECORDER_VIDEO_AVC = 2,<br>AVRECORDER_AUDIO_AAC = 3,<br>AVRECORDER_AUDIO_MP3 = 4,<br>AVRECORDER_AUDIO_G711MU = 5,<br>AVRECORDER_VIDEO_MPEG4 = 6,<br>AVRECORDER_VIDEO_HEVC = 8,<br>AVRECORDER_AUDIO_AMR_NB = 9,<br>AVRECORDER_AUDIO_AMR_WB = 10<br>} | Enumerates the MIME types of the encoder.| 
| [OH_AVRecorder_ContainerFormatType](_a_v_recorder.md#oh_avrecorder_containerformattype-1) {<br>AVRECORDER_CFT_MPEG_4 = 2,<br>AVRECORDER_CFT_MPEG_4A = 6,<br>AVRECORDER_CFT_AMR = 8,<br>AVRECORDER_CFT_MP3 = 9,<br>AVRECORDER_CFT_WAV = 10<br>} | Enumerates the CFTs.| 
| [OH_AVRecorder_State](_a_v_recorder.md#oh_avrecorder_state-1) {<br>AVRECORDER_IDLE = 0,<br>AVRECORDER_PREPARED = 1,<br>AVRECORDER_STARTED = 2,<br>AVRECORDER_PAUSED = 3,<br>AVRECORDER_STOPPED = 4,<br>AVRECORDER_RELEASED = 5,<br>AVRECORDER_ERROR = 6<br>} | Enumerates the AVRecorder states.| 
| [OH_AVRecorder_StateChangeReason](_a_v_recorder.md#oh_avrecorder_statechangereason-1) {<br>AVRECORDER_USER = 0,<br>AVRECORDER_BACKGROUND = 1<br>} | Enumerates the reasons for AVRecorder state changes.| 
| [OH_AVRecorder_FileGenerationMode](_a_v_recorder.md#oh_avrecorder_filegenerationmode-1) {<br>AVRECORDER_APP_CREATE = 0,<br>AVRECORDER_AUTO_CREATE_CAMERA_SCENE = 1<br>} | Enumerates the modes available for creating a recording file.| 
