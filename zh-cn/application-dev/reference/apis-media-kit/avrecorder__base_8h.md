# avrecorder_base.h


## 概述

定义了媒体 AVRecorder 的结构体和枚举。

**库：** libavrecorder.so

**引用文件：** &lt;multimedia/player_framework/avrecorder_base.h&gt;

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 16

**相关模块：**[AVRecorder](_a_v_recorder.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[OH_AVRecorder_Profile](_o_h___a_v_recorder___profile.md) | 定义音视频录制的详细参数。<br/>可以通过参数设置选择只录制音频或只录制视频：当 audioBitrate 或 audioChannels 为 0 时，不录制音频；当 videoFrameWidth 或 videoFrameHeight 为 0 时，不录制视频。 | 
| struct&nbsp;&nbsp;[OH_AVRecorder_Location](_o_h___a_v_recorder___location.md) | 提供媒体资源的地理位置信息。 | 
| struct&nbsp;&nbsp;[OH_AVRecorder_MetadataTemplate](_o_h___a_v_recorder___metadata_template.md) | 定义元数据的基本模板。 | 
| struct&nbsp;&nbsp;[OH_AVRecorder_Metadata](_o_h___a_v_recorder___metadata.md) | 设置元数据信息。 | 
| struct&nbsp;&nbsp;[OH_AVRecorder_Config](_o_h___a_v_recorder___config.md) | 提供媒体AVRecorder的配置定义。 | 
| struct&nbsp;&nbsp;[OH_AVRecorder_Range](_o_h___a_v_recorder___range.md) | 表示一个类型的范围。 | 
| struct&nbsp;&nbsp;[OH_AVRecorder_EncoderInfo](_o_h___a_v_recorder___encoder_info.md) | 提供编码器信息。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) [OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) | 初始化AVRecorder。 | 
| typedef enum [OH_AVRecorder_AudioSourceType](_a_v_recorder.md#oh_avrecorder_audiosourcetype-1) [OH_AVRecorder_AudioSourceType](_a_v_recorder.md#oh_avrecorder_audiosourcetype) | AVRecorder的音频源类型。 | 
| typedef enum [OH_AVRecorder_VideoSourceType](_a_v_recorder.md#oh_avrecorder_videosourcetype-1) [OH_AVRecorder_VideoSourceType](_a_v_recorder.md#oh_avrecorder_videosourcetype) | AVRecorder的视频源类型。 | 
| typedef enum [OH_AVRecorder_CodecMimeType](_a_v_recorder.md#oh_avrecorder_codecmimetype-1) [OH_AVRecorder_CodecMimeType](_a_v_recorder.md#oh_avrecorder_codecmimetype) | 枚举编码器 MIME 类型。 | 
| typedef enum [OH_AVRecorder_ContainerFormatType](_a_v_recorder.md#oh_avrecorder_containerformattype-1) [OH_AVRecorder_ContainerFormatType](_a_v_recorder.md#oh_avrecorder_containerformattype) | 枚举容器格式类型（容器格式类型的缩写是 CFT）。 | 
| typedef enum [OH_AVRecorder_State](_a_v_recorder.md#oh_avrecorder_state-1) [OH_AVRecorder_State](_a_v_recorder.md#oh_avrecorder_state) | AVRecorder状态。 | 
| typedef enum [OH_AVRecorder_StateChangeReason](_a_v_recorder.md#oh_avrecorder_statechangereason-1) [OH_AVRecorder_StateChangeReason](_a_v_recorder.md#oh_avrecorder_statechangereason) | AVRecorder状态变化的原因。 | 
| typedef enum [OH_AVRecorder_FileGenerationMode](_a_v_recorder.md#oh_avrecorder_filegenerationmode-1) [OH_AVRecorder_FileGenerationMode](_a_v_recorder.md#oh_avrecorder_filegenerationmode) | 创建录制文件的模式。 | 
| typedef struct [OH_AVRecorder_Profile](_o_h___a_v_recorder___profile.md) [OH_AVRecorder_Profile](_a_v_recorder.md#oh_avrecorder_profile) | 定义音视频录制的详细参数。<br/>可以通过参数设置选择只录制音频或只录制视频：当 audioBitrate 或 audioChannels 为 0 时，不录制音频；当 videoFrameWidth 或 videoFrameHeight 为 0 时，不录制视频。 | 
| typedef struct [OH_AVRecorder_Location](_o_h___a_v_recorder___location.md) [OH_AVRecorder_Location](_a_v_recorder.md#oh_avrecorder_location) | 提供媒体资源的地理位置信息。 | 
| typedef struct [OH_AVRecorder_MetadataTemplate](_o_h___a_v_recorder___metadata_template.md) [OH_AVRecorder_MetadataTemplate](_a_v_recorder.md#oh_avrecorder_metadatatemplate) | 定义元数据的基本模板。 | 
| typedef struct [OH_AVRecorder_Metadata](_o_h___a_v_recorder___metadata.md) [OH_AVRecorder_Metadata](_a_v_recorder.md#oh_avrecorder_metadata) | 设置元数据信息。 | 
| typedef struct [OH_AVRecorder_Config](_o_h___a_v_recorder___config.md) [OH_AVRecorder_Config](_a_v_recorder.md#oh_avrecorder_config) | 提供媒体AVRecorder的配置定义。 | 
| typedef struct [OH_AVRecorder_Range](_o_h___a_v_recorder___range.md) [OH_AVRecorder_Range](_a_v_recorder.md#oh_avrecorder_range) | 表示一个类型的范围。 | 
| typedef struct [OH_AVRecorder_EncoderInfo](_o_h___a_v_recorder___encoder_info.md) [OH_AVRecorder_EncoderInfo](_a_v_recorder.md#oh_avrecorder_encoderinfo) | 提供编码器信息。 | 
| typedef void(\* [OH_AVRecorder_OnStateChange](_a_v_recorder.md#oh_avrecorder_onstatechange)) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder, [OH_AVRecorder_State](_a_v_recorder.md#oh_avrecorder_state) state, [OH_AVRecorder_StateChangeReason](_a_v_recorder.md#oh_avrecorder_statechangereason) reason, void \*userData) | 当录制状态发生变化时调用。 | 
| typedef void(\* [OH_AVRecorder_OnError](_a_v_recorder.md#oh_avrecorder_onerror)) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder, int32_t errorCode, const char \*errorMsg, void \*userData) | 当录制过程中发生错误时调用。 | 
| typedef void(\* [OH_AVRecorder_OnUri](_a_v_recorder.md#oh_avrecorder_onuri)) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder, OH_MediaAsset \*asset, void \*userData) | 当录制在 OH_AVRecorder_FileGenerationMode.AVRECORDER_AUTO_CREATE_CAMERA_SCENE 模式下时调用。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVRecorder_AudioSourceType](_a_v_recorder.md#oh_avrecorder_audiosourcetype-1) {<br/>AVRECORDER_DEFAULT = 0,<br/>AVRECORDER_MIC = 1,<br/>AVRECORDER_VOICE_RECOGNITION = 2,<br/>AVRECORDER_VOICE_COMMUNICATION = 7,<br/>AVRECORDER_VOICE_MESSAGE = 10,<br/>AVRECORDER_CAMCORDER = 13<br/>} | AVRecorder的音频源类型。 | 
| [OH_AVRecorder_VideoSourceType](_a_v_recorder.md#oh_avrecorder_videosourcetype-1) {<br/>AVRECORDER_SURFACE_YUV = 0,<br/>AVRECORDER_SURFACE_ES = 1 } | AVRecorder的视频源类型。 | 
| [OH_AVRecorder_CodecMimeType](_a_v_recorder.md#oh_avrecorder_codecmimetype-1) {<br/>AVRECORDER_VIDEO_AVC = 2,<br/>AVRECORDER_AUDIO_AAC = 3,<br/>AVRECORDER_AUDIO_MP3 = 4,<br/>AVRECORDER_AUDIO_G711MU = 5,<br/>AVRECORDER_VIDEO_MPEG4 = 6,<br/>AVRECORDER_VIDEO_HEVC = 8,<br/>AVRECORDER_AUDIO_AMR_NB = 9,<br/>AVRECORDER_AUDIO_AMR_WB = 10<br/>} | 枚举编码器 MIME 类型。 | 
| [OH_AVRecorder_ContainerFormatType](_a_v_recorder.md#oh_avrecorder_containerformattype-1) {<br/>AVRECORDER_CFT_MPEG_4 = 2,<br/>AVRECORDER_CFT_MPEG_4A = 6,<br/>AVRECORDER_CFT_AMR = 8,<br/>AVRECORDER_CFT_MP3 = 9,<br/>AVRECORDER_CFT_WAV = 10<br/>} | 枚举容器格式类型（容器格式类型的缩写是 CFT）。 | 
| [OH_AVRecorder_State](_a_v_recorder.md#oh_avrecorder_state-1) {<br/>AVRECORDER_IDLE = 0,<br/>AVRECORDER_PREPARED = 1,<br/>AVRECORDER_STARTED = 2,<br/>AVRECORDER_PAUSED = 3,<br/>AVRECORDER_STOPPED = 4,<br/>AVRECORDER_RELEASED = 5, [AVRECORDER_ERROR = 6<br/>} | AVRecorder状态。 | 
| [OH_AVRecorder_StateChangeReason](_a_v_recorder.md#oh_avrecorder_statechangereason-1) {<br/>AVRECORDER_USER = 0,<br/>AVRECORDER_BACKGROUND = 1<br/>} | AVRecorder状态变化的原因。 | 
| [OH_AVRecorder_FileGenerationMode](_a_v_recorder.md#oh_avrecorder_filegenerationmode-1) {<br/>AVRECORDER_APP_CREATE = 0, [AVRECORDER_AUTO_CREATE_CAMERA_SCENE = 1<br/>} | 创建录制文件的模式。 | 
