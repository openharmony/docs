# AVRecorder


## 概述

提供请求录制能力的 API。

开发者可根据实际的开发需求，参考对应的开发指南及样例：

- [使用AVRecorder录制音频(C/C++)](../../media/media/using-ndk-avrecorder-for-audio-recording.md)
- [使用AVRecorder录制视频(C/C++)](../../media/media/using-ndk-avrecorder-for-video-recording.md)

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [avrecorder.h](avrecorder_8h.md) | 定义AVRecorder接口。应用可使用Media AVRecorder提供的接口录制媒体数据。 | 
| [avrecorder_base.h](avrecorder__base_8h.md) | 定义了媒体 AVRecorder 的结构体和枚举。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OH_AVRecorder_Profile](_o_h___a_v_recorder___profile.md) | 定义音视频录制的详细参数。<br/>可以通过参数设置选择只录制音频或只录制视频：当 audioBitrate 或 audioChannels 为 0 时，不录制音频；当 videoFrameWidth 或 videoFrameHeight 为 0 时，不录制视频。 | 
| struct  [OH_AVRecorder_Location](_o_h___a_v_recorder___location.md) | 提供媒体资源的地理位置信息。 | 
| struct  [OH_AVRecorder_MetadataTemplate](_o_h___a_v_recorder___metadata_template.md) | 定义元数据的基本模板。 | 
| struct  [OH_AVRecorder_Metadata](_o_h___a_v_recorder___metadata.md) | 设置元数据信息。 | 
| struct  [OH_AVRecorder_Config](_o_h___a_v_recorder___config.md) | 提供媒体AVRecorder的配置定义。 | 
| struct  [OH_AVRecorder_Range](_o_h___a_v_recorder___range.md) | 表示一个类型的范围。 | 
| struct  [OH_AVRecorder_EncoderInfo](_o_h___a_v_recorder___encoder_info.md) | 提供编码器信息。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_AVRecorder](#oh_avrecorder) [OH_AVRecorder](#oh_avrecorder) | 初始化AVRecorder。 | 
| typedef enum [OH_AVRecorder_AudioSourceType](#oh_avrecorder_audiosourcetype-1) [OH_AVRecorder_AudioSourceType](#oh_avrecorder_audiosourcetype) | AVRecorder的音频源类型。 | 
| typedef enum [OH_AVRecorder_VideoSourceType](#oh_avrecorder_videosourcetype-1) [OH_AVRecorder_VideoSourceType](#oh_avrecorder_videosourcetype) | AVRecorder的视频源类型。 | 
| typedef enum [OH_AVRecorder_CodecMimeType](#oh_avrecorder_codecmimetype-1) [OH_AVRecorder_CodecMimeType](#oh_avrecorder_codecmimetype) | 枚举编码器 MIME 类型。 | 
| typedef enum [OH_AVRecorder_ContainerFormatType](#oh_avrecorder_containerformattype-1) [OH_AVRecorder_ContainerFormatType](#oh_avrecorder_containerformattype) | 枚举容器格式类型（容器格式类型的缩写是 CFT）。 | 
| typedef enum [OH_AVRecorder_State](#oh_avrecorder_state-1) [OH_AVRecorder_State](#oh_avrecorder_state) | AVRecorder状态。 | 
| typedef enum [OH_AVRecorder_StateChangeReason](#oh_avrecorder_statechangereason-1) [OH_AVRecorder_StateChangeReason](#oh_avrecorder_statechangereason) | AVRecorder状态变化的原因。 | 
| typedef enum [OH_AVRecorder_FileGenerationMode](#oh_avrecorder_filegenerationmode-1) [OH_AVRecorder_FileGenerationMode](#oh_avrecorder_filegenerationmode) | 创建录制文件的模式。 | 
| typedef struct [OH_AVRecorder_Profile](_o_h___a_v_recorder___profile.md) [OH_AVRecorder_Profile](#oh_avrecorder_profile) | 定义音视频录制的详细参数。<br/>可以通过参数设置选择只录制音频或只录制视频：当 audioBitrate 或 audioChannels 为 0 时，不录制音频；当 videoFrameWidth 或 videoFrameHeight 为 0 时，不录制视频。 | 
| typedef struct [OH_AVRecorder_Location](_o_h___a_v_recorder___location.md) [OH_AVRecorder_Location](#oh_avrecorder_location) | 提供媒体资源的地理位置信息。 | 
| typedef struct [OH_AVRecorder_MetadataTemplate](_o_h___a_v_recorder___metadata_template.md) [OH_AVRecorder_MetadataTemplate](#oh_avrecorder_metadatatemplate) | 定义元数据的基本模板。 | 
| typedef struct [OH_AVRecorder_Metadata](_o_h___a_v_recorder___metadata.md) [OH_AVRecorder_Metadata](#oh_avrecorder_metadata) | 设置元数据信息。 | 
| typedef struct [OH_AVRecorder_Config](_o_h___a_v_recorder___config.md) [OH_AVRecorder_Config](#oh_avrecorder_config) | 提供媒体AVRecorder的配置定义。 | 
| typedef struct [OH_AVRecorder_Range](_o_h___a_v_recorder___range.md) [OH_AVRecorder_Range](#oh_avrecorder_range) | 表示一个类型的范围。 | 
| typedef struct [OH_AVRecorder_EncoderInfo](_o_h___a_v_recorder___encoder_info.md) [OH_AVRecorder_EncoderInfo](#oh_avrecorder_encoderinfo) | 提供编码器信息。 | 
| typedef void(\* [OH_AVRecorder_OnStateChange](#oh_avrecorder_onstatechange)) ([OH_AVRecorder](#oh_avrecorder) \*recorder, [OH_AVRecorder_State](#oh_avrecorder_state) state, [OH_AVRecorder_StateChangeReason](#oh_avrecorder_statechangereason) reason, void \*userData) | 当录制状态发生变化时调用。 | 
| typedef void(\* [OH_AVRecorder_OnError](#oh_avrecorder_onerror)) ([OH_AVRecorder](#oh_avrecorder) \*recorder, int32_t errorCode, const char \*errorMsg, void \*userData) | 当录制过程中发生错误时调用。 | 
| typedef void(\* [OH_AVRecorder_OnUri](#oh_avrecorder_onuri)) ([OH_AVRecorder](#oh_avrecorder) \*recorder, OH_MediaAsset \*asset, void \*userData) | 当录制在 OH_AVRecorder_FileGenerationMode.AVRECORDER_AUTO_CREATE_CAMERA_SCENE模式下时调用。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVRecorder_AudioSourceType](#oh_avrecorder_audiosourcetype-1) {<br/>AVRECORDER_DEFAULT = 0,<br/>AVRECORDER_MIC = 1,<br/>AVRECORDER_VOICE_RECOGNITION = 2,<br/>AVRECORDER_VOICE_COMMUNICATION = 7,<br/>AVRECORDER_VOICE_MESSAGE = 10,<br/>AVRECORDER_CAMCORDER = 13<br/>} | AVRecorder的音频源类型。 | 
| [OH_AVRecorder_VideoSourceType](#oh_avrecorder_videosourcetype-1) {<br/>AVRECORDER_SURFACE_YUV = 0,<br/>AVRECORDER_SURFACE_ES = 1 } | AVRecorder的视频源类型。 | 
| [OH_AVRecorder_CodecMimeType](#oh_avrecorder_codecmimetype-1) {<br/>AVRECORDER_VIDEO_AVC = 2,<br/>AVRECORDER_AUDIO_AAC = 3,<br/>AVRECORDER_AUDIO_MP3 = 4,<br/>AVRECORDER_AUDIO_G711MU = 5,<br/>AVRECORDER_VIDEO_MPEG4 = 6,<br/>AVRECORDER_VIDEO_HEVC = 8,<br/>AVRECORDER_AUDIO_AMR_NB = 9,<br/>AVRECORDER_AUDIO_AMR_WB = 10<br/>} | 枚举编码器 MIME 类型。 | 
| [OH_AVRecorder_ContainerFormatType](#oh_avrecorder_containerformattype-1) {<br/>AVRECORDER_CFT_MPEG_4 = 2,<br/>AVRECORDER_CFT_MPEG_4A = 6,<br/>AVRECORDER_CFT_AMR = 8,<br/>AVRECORDER_CFT_MP3 = 9,<br/>AVRECORDER_CFT_WAV = 10<br/>} | 枚举容器格式类型（容器格式类型的缩写是 CFT）。 | 
| [OH_AVRecorder_State](#oh_avrecorder_state-1) {<br/>AVRECORDER_IDLE = 0,<br/>AVRECORDER_PREPARED = 1,<br/>AVRECORDER_STARTED = 2,<br/>AVRECORDER_PAUSED = 3,<br/>AVRECORDER_STOPPED = 4,<br/>AVRECORDER_RELEASED = 5, AVRECORDER_ERROR = 6<br/>} | AVRecorder状态。 | 
| [OH_AVRecorder_StateChangeReason](#oh_avrecorder_statechangereason-1) {<br/>AVRECORDER_USER = 0,<br/>AVRECORDER_BACKGROUND = 1<br/>} | AVRecorder状态变化的原因。 | 
| [OH_AVRecorder_FileGenerationMode](#oh_avrecorder_filegenerationmode-1) {<br/>AVRECORDER_APP_CREATE = 0, AVRECORDER_AUTO_CREATE_CAMERA_SCENE = 1<br/>} | 创建录制文件的模式。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVRecorder](#oh_avrecorder) \* [OH_AVRecorder_Create](#oh_avrecorder_create) (void) | 创建AVRecorder实例。调用成功之后进入AVRECORDER_IDLE状态。 | 
| OH_AVErrCode [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) ([OH_AVRecorder](#oh_avrecorder) \*recorder, [OH_AVRecorder_Config](_o_h___a_v_recorder___config.md) \*config) | 配置AVRecorder参数，准备录制。必须在[OH_AVRecorder_Start](#oh_avrecorder_start)成功触发之后调用，调用成功之后进入AVRECORDER_PREPARED状态。 | 
| OH_AVErrCode [OH_AVRecorder_GetAVRecorderConfig](#oh_avrecorder_getavrecorderconfig) ([OH_AVRecorder](#oh_avrecorder) \*recorder, [OH_AVRecorder_Config](_o_h___a_v_recorder___config.md) \*\*config) | 获取当前的录制参数。此接口必须在录制准备完成后调用。传入的 \*config 必须为 nullptr，由框架层统一分配和释放内存，以避免内存管理混乱，防止内存泄漏或重复释放等问题。 | 
| OH_AVErrCode [OH_AVRecorder_GetInputSurface](#oh_avrecorder_getinputsurface) ([OH_AVRecorder](#oh_avrecorder) \*recorder, OHNativeWindow \*\*window) | 获取输入Surface。必须在[OH_AVRecorder_Prepare](#oh_avrecorder_prepare)成功触发之后，[OH_AVRecorder_Start](#oh_avrecorder_start)之前调用。 | 
| OH_AVErrCode [OH_AVRecorder_UpdateRotation](#oh_avrecorder_updaterotation) ([OH_AVRecorder](#oh_avrecorder) \*recorder, int32_t rotation) | 更新视频旋转角度。必须在[OH_AVRecorder_Prepare](#oh_avrecorder_prepare)成功触发之后，[OH_AVRecorder_Start](#oh_avrecorder_start)之前调用。 | 
| OH_AVErrCode [OH_AVRecorder_Start](#oh_avrecorder_start) ([OH_AVRecorder](#oh_avrecorder) \*recorder) | 开始录制。必须在[OH_AVRecorder_Prepare](#oh_avrecorder_prepare)成功触发之后调用，调用成功之后进入AVRECORDER_STARTED状态。 | 
| OH_AVErrCode [OH_AVRecorder_Pause](#oh_avrecorder_pause) ([OH_AVRecorder](#oh_avrecorder) \*recorder) | 暂停录制。必须在[OH_AVRecorder_Start](#oh_avrecorder_start)成功触发之后，处于AVRECORDER_STARTED状态时调用，调用成功之后进入AVRECORDER_PAUSED状态。 | 
| OH_AVErrCode [OH_AVRecorder_Resume](#oh_avrecorder_resume) ([OH_AVRecorder](#oh_avrecorder) \*recorder) | 恢复录制。必须在[OH_AVRecorder_Pause](#oh_avrecorder_pause)成功触发之后，处于PAUSED状态时调用，调用成功之后重新进入AVRECORDER_STARTED状态。 | 
| OH_AVErrCode [OH_AVRecorder_Stop](#oh_avrecorder_stop) ([OH_AVRecorder](#oh_avrecorder) \*recorder) | 停止录制。必须在[OH_AVRecorder_Start](#oh_avrecorder_start)成功触发之后调用，调用成功之后进入AVRECORDER_STOPPED状态。 | 
| OH_AVErrCode [OH_AVRecorder_Reset](#oh_avrecorder_reset) ([OH_AVRecorder](#oh_avrecorder) \*recorder) | 重置录制状态。必须在非AVRECORDER_RELEASED状态下调用，调用成功之后进入AVRECORDER_IDLE状态。 | 
| OH_AVErrCode [OH_AVRecorder_Release](#oh_avrecorder_release) ([OH_AVRecorder](#oh_avrecorder) \*recorder) | 释放录制资源。调用成功之后进入AVRECORDER_RELEASED状态。调用此接口释放录制资源后，recorder 内存将释放，应用层需要显式地将 recorder 指针置空，避免访问野指针。 | 
| OH_AVErrCode [OH_AVRecorder_GetAvailableEncoder](#oh_avrecorder_getavailableencoder) ([OH_AVRecorder](#oh_avrecorder) \*recorder, [OH_AVRecorder_EncoderInfo](_o_h___a_v_recorder___encoder_info.md) \*\*info, int32_t \*length) | 获取 AVRecorder 可用的编码器和编码器信息。参数 \*info 必须为 nullptr，由框架层统一分配和释放内存，以避免内存管理混乱，防止内存泄漏或重复释放等问题。 | 
| OH_AVErrCode [OH_AVRecorder_SetStateCallback](#oh_avrecorder_setstatecallback) ([OH_AVRecorder](#oh_avrecorder) \*recorder, [OH_AVRecorder_OnStateChange](#oh_avrecorder_onstatechange) callback, void \*userData) | 设置状态回调函数，以便应用能够响应AVRecorder生成的状态变化事件。此接口必须在[OH_AVRecorder_Start](#oh_avrecorder_start)调用之前调用。 | 
| OH_AVErrCode [OH_AVRecorder_SetErrorCallback](#oh_avrecorder_seterrorcallback) ([OH_AVRecorder](#oh_avrecorder) \*recorder, [OH_AVRecorder_OnError](#oh_avrecorder_onerror) callback, void \*userData) | 设置错误回调函数，以便应用能够响应AVRecorder生成的错误事件。此接口必须在[OH_AVRecorder_Start](#oh_avrecorder_start)调用之前调用。 | 
| OH_AVErrCode [OH_AVRecorder_SetUriCallback](#oh_avrecorder_seturicallback) ([OH_AVRecorder](#oh_avrecorder) \*recorder, [OH_AVRecorder_OnUri](#oh_avrecorder_onuri) callback, void \*userData) | 设置 URI 回调函数，以便应用能够响应AVRecorder生成的 URI 事件。此接口必须在 [OH_AVRecorder_Start](#oh_avrecorder_start) 调用之前调用。 | 


## 类型定义说明


### OH_AVRecorder

```
typedef struct OH_AVRecorder OH_AVRecorder
```

**描述**

初始化AVRecorder。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


### OH_AVRecorder_AudioSourceType

```
typedef enum OH_AVRecorder_AudioSourceType OH_AVRecorder_AudioSourceType
```

**描述**

AVRecorder的音频源类型。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


### OH_AVRecorder_CodecMimeType

```
typedef enum OH_AVRecorder_CodecMimeType OH_AVRecorder_CodecMimeType
```

**描述**

枚举编码器 MIME 类型。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


### OH_AVRecorder_Config

```
typedef struct OH_AVRecorder_Config OH_AVRecorder_Config
```

**描述**

提供媒体AVRecorder的配置定义。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


### OH_AVRecorder_ContainerFormatType

```
typedef enum OH_AVRecorder_ContainerFormatType OH_AVRecorder_ContainerFormatType
```

**描述**

枚举容器格式类型（容器格式类型的缩写是 CFT）。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


### OH_AVRecorder_EncoderInfo

```
typedef struct OH_AVRecorder_EncoderInfo OH_AVRecorder_EncoderInfo
```

**描述**

提供编码器信息。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


### OH_AVRecorder_FileGenerationMode

```
typedef enum OH_AVRecorder_FileGenerationMode OH_AVRecorder_FileGenerationMode
```

**描述**

创建录制文件的模式。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


### OH_AVRecorder_Location

```
typedef struct OH_AVRecorder_Location OH_AVRecorder_Location
```

**描述**

提供媒体资源的地理位置信息。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


### OH_AVRecorder_Metadata

```
typedef struct OH_AVRecorder_Metadata OH_AVRecorder_Metadata
```

**描述**

设置元数据信息。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


### OH_AVRecorder_MetadataTemplate

```
typedef struct OH_AVRecorder_MetadataTemplate OH_AVRecorder_MetadataTemplate
```

**描述**

定义元数据的基本模板。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


### OH_AVRecorder_OnError

```
typedef void (*OH_AVRecorder_OnError)(OH_AVRecorder *recorder, int32_t errorCode, const char *errorMsg, void *userData)
```

**描述**

当录制过程中发生错误时调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recorder | OH_AVRecorder 实例的指针。 | 
| errorCode | 错误码。 | 
| errorMsg | 错误信息。 | 
| userData | 用户特定数据的指针。 | 


### OH_AVRecorder_OnStateChange

```
typedef void (*OH_AVRecorder_OnStateChange)(OH_AVRecorder *recorder, OH_AVRecorder_State state, OH_AVRecorder_StateChangeReason reason, void *userData)
```

**描述**

当录制状态发生变化时调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recorder | OH_AVRecorder 实例的指针。 | 
| state | 表示录制器状态。详情请参见 [OH_AVRecorder_State](#oh_avrecorder_state)。 | 
| reason | 录制器状态变化的原因。详情请参见 [OH_AVRecorder_StateChangeReason](#oh_avrecorder_statechangereason)。 | 
| userData | 用户特定数据的指针。 | 


### OH_AVRecorder_OnUri

```
typedef void (*OH_AVRecorder_OnUri)(OH_AVRecorder *recorder, OH_MediaAsset *asset, void *userData)
```

**描述**

当录制在 OH_AVRecorder_FileGenerationMode.AVRECORDER_AUTO_CREATE_CAMERA_SCENE 模式下时调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recorder | OH_AVRecorder 实例的指针。 | 
| asset | OH_MediaAsset 实例的指针。 | 
| userData | 用户特定数据的指针。 | 


### OH_AVRecorder_Profile

```
typedef struct OH_AVRecorder_Profile OH_AVRecorder_Profile
```

**描述**

定义音视频录制的详细参数。

可以通过参数设置选择只录制音频或只录制视频：当 audioBitrate 或 audioChannels 为 0 时，不录制音频；当 videoFrameWidth 或 videoFrameHeight 为 0 时，不录制视频。

各参数的范围请参见[AVRecorderProfile](js-apis-media.md#avrecorderprofile9)。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


### OH_AVRecorder_Range

```
typedef struct OH_AVRecorder_Range OH_AVRecorder_Range
```

**描述**

表示一个类型的范围。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


### OH_AVRecorder_State

```
typedef enum OH_AVRecorder_State OH_AVRecorder_State
```

**描述**

AVRecorder状态。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


### OH_AVRecorder_StateChangeReason

```
typedef enum OH_AVRecorder_StateChangeReason OH_AVRecorder_StateChangeReason
```

**描述**

AVRecorder状态变化的原因。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


### OH_AVRecorder_VideoSourceType

```
typedef enum OH_AVRecorder_VideoSourceType OH_AVRecorder_VideoSourceType
```

**描述**

AVRecorder的视频源类型。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


## 枚举类型说明


### OH_AVRecorder_AudioSourceType

```
enum OH_AVRecorder_AudioSourceType
```

**描述**

AVRecorder的音频源类型。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

| 枚举值 | 描述 | 
| -------- | -------- |
| AVRECORDER_DEFAULT | 默认音频源类型。 | 
| AVRECORDER_MIC | 麦克风音频源类型。 | 
| AVRECORDER_VOICE_RECOGNITION | 表示语音识别场景的音频源。 | 
| AVRECORDER_VOICE_COMMUNICATION | 表示语音通话场景的音频源。 | 
| AVRECORDER_VOICE_MESSAGE | 表示短语音消息的音频源。 | 
| AVRECORDER_CAMCORDER | 表示相机录像的音频源。 | 


### OH_AVRecorder_CodecMimeType

```
enum OH_AVRecorder_CodecMimeType
```

**描述**

枚举编码器 MIME 类型。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

| 枚举值 | 描述 | 
| -------- | -------- |
| AVRECORDER_VIDEO_AVC | H.264 编码器 MIME 类型。 | 
| AVRECORDER_AUDIO_AAC | AAC 编码器 MIME 类型。 | 
| AVRECORDER_AUDIO_MP3 | mp3 编码器 MIME 类型。 | 
| AVRECORDER_AUDIO_G711MU | G711-mulaw 编码器 MIME 类型。 | 
| AVRECORDER_VIDEO_MPEG4 | MPEG4 编码器 MIME 类型。 | 
| AVRECORDER_VIDEO_HEVC | H.265 编码器 MIME 类型。 | 
| AVRECORDER_AUDIO_AMR_NB | AMR_NB 编解码器 MIME 类型。 | 
| AVRECORDER_AUDIO_AMR_WB | AMR_WB 编解码器 MIME 类型。 | 


### OH_AVRecorder_ContainerFormatType

```
enum OH_AVRecorder_ContainerFormatType
```

**描述**

枚举容器格式类型（容器格式类型的缩写是 CFT）。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

| 枚举值 | 描述 | 
| -------- | -------- |
| AVRECORDER_CFT_MPEG_4 | 视频容器格式类型 mp4。 | 
| AVRECORDER_CFT_MPEG_4A | 音频容器格式类型 m4a。 | 
| AVRECORDER_CFT_AMR | 音频容器格式类型 amr。 | 
| AVRECORDER_CFT_MP3 | 音频容器格式类型 mp3。 | 
| AVRECORDER_CFT_WAV | 音频容器格式类型 wav。 | 


### OH_AVRecorder_FileGenerationMode

```
enum OH_AVRecorder_FileGenerationMode
```

**描述**

创建录制文件的模式。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

| 枚举值 | 描述 | 
| -------- | -------- |
| AVRECORDER_APP_CREATE | 由应用自行在沙箱创建媒体文件。 | 
| AVRECORDER_AUTO_CREATE_CAMERA_SCENE | 由系统创建媒体文件，当前仅在相机录制场景下生效，会忽略应用设置的url。 | 


### OH_AVRecorder_State

```
enum OH_AVRecorder_State
```

**描述**

AVRecorder状态。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

| 枚举值 | 描述 | 
| -------- | -------- |
| AVRECORDER_IDLE | 空闲状态。此时可以调用OH_AVRecorder_Prepare()方法设置录制参数，进入AVRECORDER_PREPARED状态。 | 
| AVRECORDER_PREPARED | 准备状态。参数设置完成，此时可以调用OH_AVRecorder_Start()方法开始录制，进入AVRECORDER_STARTED状态。 | 
| AVRECORDER_STARTED | 启动状态。正在录制，此时可以调用OH_AVRecorder_Pause()方法暂停录制，进入AVRECORDER_PAUSED状态。也可以调用OH_AVRecorder_Stop()方法结束录制，进入AVRECORDER_STOPPED状态。 | 
| AVRECORDER_PAUSED | 暂停状态。此时可以调用OH_AVRecorder_Resume()方法继续录制，进入AVRECORDER_STARTED状态。也可以调用OH_AVRecorder_Stop()方法结束录制，进入AVRECORDER_STOPPED状态。 | 
| AVRECORDER_STOPPED | 停止状态。此时可以调用OH_AVRecorder_Prepare()方法设置录制参数，重新进入AVRECORDER_PREPARED状态。 | 
| AVRECORDER_RELEASED | 释放状态。录制资源释放，此时不能再进行任何操作。在任何其他状态下，均可以通过调用OH_AVRecorder_Release()方法进入AVRECORDER_RELEASED状态。 | 
| AVRECORDER_ERROR | 错误状态。当AVRecorder实例发生不可逆错误，会转换至当前状态。切换至AVRECORDER_ERROR状态时会伴随OH_AVRecorder_OnError事件，该事件会上报详细错误原因。在AVRECORDER_ERROR状态时，用户需要调用OH_AVRecorder_Reset()方法重置AVRecorder实例，或者调用OH_AVRecorder_Release()方法释放资源。 | 


### OH_AVRecorder_StateChangeReason

```
enum OH_AVRecorder_StateChangeReason
```

**描述**

AVRecorder状态变化的原因。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

| 枚举值 | 描述 | 
| -------- | -------- |
| AVRECORDER_USER | 用户操作导致的状态变化。 | 
| AVRECORDER_BACKGROUND | 后台操作导致的状态变化。 | 


### OH_AVRecorder_VideoSourceType

```
enum OH_AVRecorder_VideoSourceType
```

**描述**

AVRecorder的视频源类型。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

| 枚举值 | 描述 | 
| -------- | -------- |
| AVRECORDER_SURFACE_YUV | 原始数据Surface。 | 
| AVRECORDER_SURFACE_ES | ES数据Surface。 | 


## 函数说明


### OH_AVRecorder_Create()

```
OH_AVRecorder *OH_AVRecorder_Create(void)
```

**描述**

创建AVRecorder实例。调用成功之后进入AVRECORDER_IDLE状态。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**返回：**

成功时返回指向 OH_AVRecorder 实例的指针，失败时返回 nullptr。


### OH_AVRecorder_GetAvailableEncoder()

```
OH_AVErrCode OH_AVRecorder_GetAvailableEncoder(OH_AVRecorder *recorder, OH_AVRecorder_EncoderInfo **info, int32_t *length)
```

**描述**

获取 AVRecorder 可用的编码器和编码器信息。参数 \*info 必须为 nullptr，由框架层统一分配和释放内存，以避免内存管理混乱，防止内存泄漏或重复释放等问题。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recorder | 指向 OH_AVRecorder 实例的指针。 | 
| info | 指向 [OH_AVRecorder_EncoderInfo](_o_h___a_v_recorder___encoder_info.md) 实例的指针，见 [OH_AVRecorder_EncoderInfo](_o_h___a_v_recorder___encoder_info.md)。 | 
| length | 可用编码器的长度。 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：执行成功。

AV_ERR_INVALID_VAL：输入的 recorder 为 nullptr。

AV_ERR_NO_MEMORY：内存不足，\*info 内存分配失败。


### OH_AVRecorder_GetAVRecorderConfig()

```
OH_AVErrCode OH_AVRecorder_GetAVRecorderConfig(OH_AVRecorder *recorder, OH_AVRecorder_Config **config)
```

**描述**

获取当前的录制参数。此接口必须在录制准备完成后调用。传入的 \*config 必须为 nullptr，由框架层统一分配和释放内存，以避免内存管理混乱，防止内存泄漏或重复释放等问题。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recorder | 指向 OH_AVRecorder 实例的指针。 | 
| config | 指向 [OH_AVRecorder_Config](_o_h___a_v_recorder___config.md) 实例的指针，见 [OH_AVRecorder_Config](_o_h___a_v_recorder___config.md)。 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)： AV_ERR_OK：执行成功。

AV_ERR_INVALID_VAL** 如果输入的 recorder 为 nullptr 或 \*config 不为 nullptr；

AV_ERR_NO_MEMORY** 如果内存不足，\*config 内存分配失败。


### OH_AVRecorder_GetInputSurface()

```
OH_AVErrCode OH_AVRecorder_GetInputSurface(OH_AVRecorder *recorder, OHNativeWindow **window)
```

**描述**

获取输入Surface。必须在[OH_AVRecorder_Prepare](#oh_avrecorder_prepare)成功触发之后，[OH_AVRecorder_Start](#oh_avrecorder_start)之前调用。

此Surface提供给调用者，调用者从此Surface中获取Surface Buffer，填入相应的视频数据。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recorder | 指向 OH_AVRecorder 实例的指针。 | 
| window | 指向 OHNativeWindow 实例的指针，见 **OHNativeWindow**。 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)： AV_ERR_OK：执行成功。

AV_ERR_INVALID_VAL** 如果输入的 recorder 为 nullptr。


### OH_AVRecorder_Pause()

```
OH_AVErrCode OH_AVRecorder_Pause(OH_AVRecorder *recorder)
```

**描述**

暂停录制。必须在[OH_AVRecorder_Start](#oh_avrecorder_start)成功触发之后，处于AVRECORDER_STARTED状态时调用，调用成功之后进入AVRECORDER_PAUSED状态。

之后可以通过调用[OH_AVRecorder_Resume](#oh_avrecorder_resume)恢复录制，重新进入AVRECORDER_STARTED状态。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recorder | 指向 OH_AVRecorder 实例的指针。 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)： AV_ERR_OK：执行成功。

AV_ERR_INVALID_VAL** 如果输入的 recorder 为 nullptr 或暂停失败。


### OH_AVRecorder_Prepare()

```
OH_AVErrCode OH_AVRecorder_Prepare(OH_AVRecorder *recorder, OH_AVRecorder_Config *config)
```

**描述**

配置AVRecorder参数，准备录制。必须在[OH_AVRecorder_Start](#oh_avrecorder_start)成功触发之后调用，调用成功之后进入AVRECORDER_PREPARED状态。

若只录制音频，则无需配置视频相关参数；同理，若只录制视频，则无需配置音频相关参数。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recorder | 指向 OH_AVRecorder 实例的指针。 | 
| config | 指向 [OH_AVRecorder_Config](_o_h___a_v_recorder___config.md) 实例的指针，见 [OH_AVRecorder_Config](_o_h___a_v_recorder___config.md)。 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)： AV_ERR_OK：执行成功。

AV_ERR_INVALID_VAL** 如果输入的 recorder 为 nullptr 或者准备失败。


### OH_AVRecorder_Release()

```
OH_AVErrCode OH_AVRecorder_Release(OH_AVRecorder *recorder)
```

**描述**

释放录制资源。调用成功之后进入AVRECORDER_RELEASED状态。调用此接口释放录制资源后，recorder 内存将释放，应用层需要显式地将 recorder 指针置空，避免访问野指针。

调用此接口释放录制资源后，recorder 内存将释放，应用层需要显式地将 recorder 指针置空，避免访问野指针。 释放音视频录制资源之后，该 OH_AVRecorder 实例不能再进行任何操作。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recorder | 指向 OH_AVRecorder 实例的指针。 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)： AV_ERR_OK：执行成功。

AV_ERR_INVALID_VAL** 如果输入的 recorder 为 nullptr 或释放失败。


### OH_AVRecorder_Reset()

```
OH_AVErrCode OH_AVRecorder_Reset(OH_AVRecorder *recorder)
```

**描述**

重置录制状态。必须在非AVRECORDER_RELEASED状态下调用，调用成功之后进入AVRECORDER_IDLE状态。

纯音频录制时，需要重新调用[OH_AVRecorder_Prepare](#oh_avrecorder_prepare)接口才能重新录制。纯视频录制、音视频录制时，需要重新调用[OH_AVRecorder_Prepare](#oh_avrecorder_prepare)和[OH_AVRecorder_GetInputSurface](#oh_avrecorder_getinputsurface)接口才能重新录制。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recorder | 指向 OH_AVRecorder 实例的指针。 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)： AV_ERR_OK：执行成功。

AV_ERR_INVALID_VAL** 如果输入的 recorder 为 nullptr 或重置失败。


### OH_AVRecorder_Resume()

```
OH_AVErrCode OH_AVRecorder_Resume(OH_AVRecorder *recorder)
```

**描述**

恢复录制。必须在[OH_AVRecorder_Pause](#oh_avrecorder_pause)成功触发之后，处于PAUSED状态时调用，调用成功之后重新进入AVRECORDER_STARTED状态。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recorder | 指向 OH_AVRecorder 实例的指针。 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)： AV_ERR_OK：执行成功。

AV_ERR_INVALID_VAL** 如果输入的 recorder 为 nullptr 或恢复失败。


### OH_AVRecorder_SetErrorCallback()

```
OH_AVErrCode OH_AVRecorder_SetErrorCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnError callback, void *userData)
```

**描述**

设置错误回调函数，以便应用能够响应AVRecorder生成的错误事件。此接口必须在[OH_AVRecorder_Start](#oh_avrecorder_start)调用之前调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recorder | 指向 OH_AVRecorder 实例的指针。 | 
| callback | 错误回调函数，见 [OH_AVRecorder_OnError](#oh_avrecorder_onerror)。 | 
| userData | 指向用户特定数据的指针。 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)： AV_ERR_OK：执行成功。

AV_ERR_INVALID_VAL** 如果输入的 recorder 为 nullptr 或回调函数为 nullptr。


### OH_AVRecorder_SetStateCallback()

```
OH_AVErrCode OH_AVRecorder_SetStateCallback( OH_AVRecorder *recorder, OH_AVRecorder_OnStateChange callback, void *userData)
```

**描述**

设置状态回调函数，以便应用能够响应AVRecorder生成的状态变化事件。此接口必须在[OH_AVRecorder_Start](#oh_avrecorder_start)调用之前调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recorder | 指向 OH_AVRecorder 实例的指针。 | 
| callback | 状态回调函数，见 [OH_AVRecorder_OnStateChange](#oh_avrecorder_onstatechange)。 | 
| userData | 指向用户特定数据的指针。 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)： AV_ERR_OK：执行成功。

AV_ERR_INVALID_VAL** 如果输入的 recorder 为 nullptr 或回调函数为 nullptr。


### OH_AVRecorder_SetUriCallback()

```
OH_AVErrCode OH_AVRecorder_SetUriCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnUri callback, void *userData)
```

**描述**

设置 URI 回调函数，以便应用能够响应AVRecorder生成的 URI 事件。此接口必须在 [OH_AVRecorder_Start](#oh_avrecorder_start) 调用之前调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recorder | 指向 OH_AVRecorder 实例的指针。 | 
| callback | URI 回调函数，见 [OH_AVRecorder_OnUri](#oh_avrecorder_onuri)。 | 
| userData | 指向用户特定数据的指针。 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)： AV_ERR_OK：执行成功。

AV_ERR_INVALID_VAL** 如果输入的 recorder 为 nullptr 或回调函数为 nullptr。


### OH_AVRecorder_Start()

```
OH_AVErrCode OH_AVRecorder_Start(OH_AVRecorder *recorder)
```

**描述**

开始录制。必须在[OH_AVRecorder_Prepare](#oh_avrecorder_prepare)成功触发之后调用，调用成功之后进入AVRECORDER_STARTED状态。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recorder | 指向 OH_AVRecorder 实例的指针。 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)： AV_ERR_OK：执行成功。

AV_ERR_INVALID_VAL** 如果输入的 recorder 为 nullptr 或启动失败。


### OH_AVRecorder_Stop()

```
OH_AVErrCode OH_AVRecorder_Stop(OH_AVRecorder *recorder)
```

**描述**

停止录制。必须在[OH_AVRecorder_Start](#oh_avrecorder_start)成功触发之后调用，调用成功之后进入AVRECORDER_STOPPED状态。

纯音频录制时，需要重新调用[OH_AVRecorder_Prepare](#oh_avrecorder_prepare)接口才能重新录制。纯视频录制、音视频录制时，需要重新调用[OH_AVRecorder_Prepare](#oh_avrecorder_prepare)和[OH_AVRecorder_GetInputSurface](#oh_avrecorder_getinputsurface)接口才能重新录制。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recorder | 指向 OH_AVRecorder 实例的指针。 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)： AV_ERR_OK：执行成功。

AV_ERR_INVALID_VAL** 如果输入的 recorder 为 nullptr 或停止失败。


### OH_AVRecorder_UpdateRotation()

```
OH_AVErrCode OH_AVRecorder_UpdateRotation(OH_AVRecorder *recorder, int32_t rotation)
```

**描述**

更新视频旋转角度。必须在[OH_AVRecorder_Prepare](#oh_avrecorder_prepare)成功触发之后，[OH_AVRecorder_Start](#oh_avrecorder_start)之前调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recorder | 指向 OH_AVRecorder 实例的指针。 | 
| rotation | 视频旋转角度，必须是整数 [0, 90, 180, 270] 中的一个。 | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)： AV_ERR_OK：执行成功。

AV_ERR_INVALID_VAL** 如果输入的 recorder 为 nullptr 或输入的 rotation 不符合要求或更新方向失败。
