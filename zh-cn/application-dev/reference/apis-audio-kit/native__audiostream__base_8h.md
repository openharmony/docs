# native_audiostream_base.h


## 概述

声明OHAudio基础的数据结构。

**库**：libohaudio.so

**引用文件**：&lt;ohaudio/native_audiostream_base.h&gt;

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

**相关模块：**[OHAudio](_o_h_audio.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[OH_AudioRenderer_Callbacks_Struct](_o_h___audio_renderer___callbacks___struct.md) | 声明输出音频流的回调函数指针。  | 
| struct&nbsp;&nbsp;[OH_AudioCapturer_Callbacks_Struct](_o_h___audio_capturer___callbacks___struct.md) | 声明输入音频流的回调函数指针。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct OH_AudioStreamBuilderStruct [OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) | 声明音频流的构造器。  | 
| typedef struct OH_AudioRendererStruct [OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) | 声明输出音频流。  | 
| typedef struct OH_AudioCapturerStruct [OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) | 声明输入音频流。  | 
| typedef struct [OH_AudioRenderer_Callbacks_Struct](_o_h___audio_renderer___callbacks___struct.md) [OH_AudioRenderer_Callbacks](_o_h_audio.md#oh_audiorenderer_callbacks) | 声明输出音频流的回调函数指针。  | 
| typedef struct [OH_AudioCapturer_Callbacks_Struct](_o_h___audio_capturer___callbacks___struct.md) [OH_AudioCapturer_Callbacks](_o_h_audio.md#oh_audiocapturer_callbacks) | 声明输入音频流的回调函数指针。  | 
| typedef void(\* [OH_AudioRenderer_OutputDeviceChangeCallback](_o_h_audio.md#oh_audiorenderer_outputdevicechangecallback))([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, void \*userData, [OH_AudioStream_DeviceChangeReason](_o_h_audio.md#oh_audiostream_devicechangereason) reason) | 输出音频流设备变更的回调函数。  | 
| typedef void(\* [OH_AudioRenderer_OnMarkReachedCallback](_o_h_audio.md#oh_audiorenderer_onmarkreachedcallback))([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, uint32_t samplePos, void \*userData) | 到达标记位置时回调。  | 
| typedef int32_t(\* [OH_AudioRenderer_WriteDataWithMetadataCallback](_o_h_audio.md#oh_audiorenderer_writedatawithmetadatacallback))([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, void \*userData, void \*audioData, int32_t audioDataSize, void \*metadata, int32_t metadataSize) | 该函数指针将指向用于同时写入音频数据和元数据的回调函数。  | 
| typedef [OH_AudioData_Callback_Result](_o_h_audio.md#oh_audiodata_callback_result)(\* [OH_AudioRenderer_OnWriteDataCallback](_o_h_audio.md#oh_audiorenderer_onwritedatacallback))([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, void \*userData, void \*audioData, int32_t audioDataSize) | 该函数指针将指向用于写入音频数据的回调函数。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) {<br/>AUDIOSTREAM_SUCCESS = 0,<br/>AUDIOSTREAM_ERROR_INVALID_PARAM = 1,<br/>AUDIOSTREAM_ERROR_ILLEGAL_STATE = 2,<br/>AUDIOSTREAM_ERROR_SYSTEM = 3<br/>} | 音频错误码。 | 
| [OH_AudioStream_Type](_o_h_audio.md#oh_audiostream_type) {<br/>AUDIOSTREAM_TYPE_RENDERER = 1,<br/>AUDIOSTREAM_TYPE_CAPTURER = 2<br/>} | 音频流类型。 | 
| [OH_AudioStream_SampleFormat](_o_h_audio.md#oh_audiostream_sampleformat) {<br/>AUDIOSTREAM_SAMPLE_U8 = 0,<br/>AUDIOSTREAM_SAMPLE_S16LE = 1,<br/>AUDIOSTREAM_SAMPLE_S24LE = 2,<br/>AUDIOSTREAM_SAMPLE_S32LE = 3<br/>} | 定义音频流采样格式。 | 
| [OH_AudioStream_EncodingType](_o_h_audio.md#oh_audiostream_encodingtype) { <br/>AUDIOSTREAM_ENCODING_TYPE_RAW = 0, <br/>AUDIOSTREAM_ENCODING_TYPE_AUDIOVIVID = 1<br/>} | 定义音频流编码类型。  | 
| [OH_AudioStream_Usage](_o_h_audio.md#oh_audiostream_usage) {<br/>AUDIOSTREAM_USAGE_UNKNOWN = 0,<br/>AUDIOSTREAM_USAGE_MUSIC = 1,<br/>AUDIOSTREAM_USAGE_VOICE_COMMUNICATION = 2,<br/>AUDIOSTREAM_USAGE_VOICE_ASSISTANT = 3,<br/>AUDIOSTREAM_USAGE_ALARM = 4,<br/>AUDIOSTREAM_USAGE_VOICE_MESSAGE = 5,<br/>AUDIOSTREAM_USAGE_RINGTONE = 6,<br/>AUDIOSTREAM_USAGE_NOTIFICATION = 7,<br/>AUDIOSTREAM_USAGE_ACCESSIBILITY = 8,<br/>AUDIOSTREAM_USAGE_MOVIE = 10,<br/>AUDIOSTREAM_USAGE_GAME = 11,<br/>AUDIOSTREAM_USAGE_AUDIOBOOK = 12,<br/>AUDIOSTREAM_USAGE_NAVIGATION = 13,<br/>AUDIOSTREAM_USAGE_VIDEO_COMMUNICATION = 17<br/>} | 定义音频流使用场景。 | 
| [OH_AudioStream_LatencyMode](_o_h_audio.md#oh_audiostream_latencymode) {<br/>AUDIOSTREAM_LATENCY_MODE_NORMAL = 0,<br/>AUDIOSTREAM_LATENCY_MODE_FAST = 1<br/>} | 定义音频时延模式。 | 
| [OH_AudioStream_State](_o_h_audio.md#oh_audiostream_state) {<br/>AUDIOSTREAM_STATE_INVALID = -1,<br/>AUDIOSTREAM_STATE_NEW = 0,<br/>AUDIOSTREAM_STATE_PREPARED = 1,<br/>AUDIOSTREAM_STATE_RUNNING = 2,<br/>AUDIOSTREAM_STATE_STOPPED = 3,<br/>AUDIOSTREAM_STATE_RELEASED = 4,<br/>AUDIOSTREAM_STATE_PAUSED = 5<br/>} | 定义音频流的状态。 | 
| [OH_AudioStream_SourceType](_o_h_audio.md#oh_audiostream_sourcetype) {<br/>AUDIOSTREAM_SOURCE_TYPE_INVALID = -1,<br/>AUDIOSTREAM_SOURCE_TYPE_MIC = 0,<br/>AUDIOSTREAM_SOURCE_TYPE_VOICE_RECOGNITION = 1,<br/>AUDIOSTREAM_SOURCE_TYPE_PLAYBACK_CAPTURE = 2,<br/>AUDIOSTREAM_SOURCE_TYPE_VOICE_COMMUNICATION = 7<br/>} | 定义音频流使用场景。 | 
| [OH_AudioStream_Event](_o_h_audio.md#oh_audiostream_event) {<br/>AUDIOSTREAM_EVENT_ROUTING_CHANGED = 0<br/>} | 定义音频事件。 | 
| [OH_AudioInterrupt_ForceType](_o_h_audio.md#oh_audiointerrupt_forcetype) {<br/>AUDIOSTREAM_INTERRUPT_FORCE = 0,<br/>AUDIOSTREAM_INTERRUPT_SHARE = 1<br/>} | 定义音频中断类型。 | 
| [OH_AudioInterrupt_Hint](_o_h_audio.md#oh_audiointerrupt_hint) {<br/>AUDIOSTREAM_INTERRUPT_HINT_NONE = 0,<br/>AUDIOSTREAM_INTERRUPT_HINT_RESUME = 1,<br/>AUDIOSTREAM_INTERRUPT_HINT_PAUSE = 2,<br/>AUDIOSTREAM_INTERRUPT_HINT_STOP = 3,<br/>AUDIOSTREAM_INTERRUPT_HINT_DUCK = 4,<br/>AUDIOSTREAM_INTERRUPT_HINT_UNDUCK = 5<br/>} | 定义音频中断提示类型。 | 
| [OH_AudioInterrupt_Mode](_o_h_audio.md#oh_audiointerrupt_mode) {<br/> AUDIOSTREAM_INTERRUPT_MODE_SHARE = 0, <br/> AUDIOSTREAM_INTERRUPT_MODE_INDEPENDENT = 1 <br/>} | 定义音频中断模式。  | 
| [OH_AudioStream_AudioEffectMode](_o_h_audio.md#oh_audiostream_audioeffectmode) {<br/>  EFFECT_NONE = 0, <br/> EFFECT_DEFAULT = 1 <br/> } | 定义音效模式。  | 
| [OH_AudioStream_DeviceChangeReason](_o_h_audio.md#oh_audiostream_devicechangereason) {<br/>REASON_UNKNOWN = 0,<br/>REASON_NEW_DEVICE_AVAILABLE = 1,<br/>REASON_OLD_DEVICE_UNAVAILABLE = 2,<br/>REASON_OVERRODE = 3<br/>} | 流设备变更原因。 | 
| [OH_AudioStream_PrivacyType](_o_h_audio.md#oh_audiostream_privacytype) { <br/>AUDIO_STREAM_PRIVACY_TYPE_PUBLIC = 0, <br/>AUDIO_STREAM_PRIVACY_TYPE_PRIVATE = 1 <br/>} | 用于标识对应播放音频流是否支持被其他应用录制。  | 
| [OH_AudioData_Callback_Result](_o_h_audio.md#oh_audiodata_callback_result) { <br/>AUDIO_DATA_CALLBACK_RESULT_INVALID = -1, <br/>AUDIO_DATA_CALLBACK_RESULT_VALID = 0 <br/>} | 定义音频数据回调结果。  | 
