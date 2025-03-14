# native_audiostream_base.h


## 概述

声明OHAudio基础的数据结构。

**起始版本：** 10

**相关模块：** OHAudio


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp; OH_AudioRenderer_Callbacks_Struct| 声明输出音频流的回调函数指针。  | 
| struct&nbsp;&nbsp;OH_AudioCapturer_Callbacks_Struct | 声明输入音频流的回调函数指针。  | 


### 类型定义

| 名称                                                                                                                                                                       | 描述 | 
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------| -------- |
| typedef struct OH_AudioStreamBuilderStruct  OH_AudioStreamBuilder| 声明音频流的构造器。  | 
| typedef struct OH_AudioRendererStruct OH_AudioRenderer  | 声明输出音频流。  | 
| typedef struct OH_AudioCapturerStruct OH_AudioCapturer | 声明输入音频流。  | 
| typedef struct OH_AudioRenderer_Callbacks_Struct OH_AudioRenderer_Callbacks| 声明输出音频流的回调函数指针。  | 
| typedef struct OH_AudioCapturer_Callbacks_Struct OH_AudioCapturer_Callbacks | 声明输入音频流的回调函数指针。  | 
| typedef void \* OH_AudioRenderer_OutputDeviceChangeCallback (OH_AudioRenderer \*renderer, void \*userData, OH_AudioStream_DeviceChangeReason reason) | 输出音频流设备变更的回调函数。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| OH_AudioStream_Result {<br/>AUDIOSTREAM_SUCCESS = 0,<br/>AUDIOSTREAM_ERROR_INVALID_PARAM = 1,<br/>AUDIOSTREAM_ERROR_ILLEGAL_STATE = 2,<br/>AUDIOSTREAM_ERROR_SYSTEM = 3<br/>} | 音频错误码。 | 
| OH_AudioStream_Type {<br/>AUDIOSTREAM_TYPE_RERNDERER = 1,<br/>AUDIOSTREAM_TYPE_CAPTURER = 2<br/>} | 音频流类型。 | 
| OH_AudioStream_SampleFormat {<br/>AUDIOSTREAM_SAMPLE_U8 = 0,<br/>AUDIOSTREAM_SAMPLE_S16LE = 1,<br/>AUDIOSTREAM_SAMPLE_S24LE = 2,<br/>AUDIOSTREAM_SAMPLE_S32LE = 3<br/>} | 定义音频流采样格式。 | 
| OH_AudioStream_EncodingType {<br/>AUDIOSTREAM_ENCODING_TYPE_RAW = 0<br/>} | 定义音频流编码类型。 | 
| OH_AudioStream_Usage {<br/>AUDIOSTREAM_USAGE_UNKNOWN = 0,<br/>AUDIOSTREAM_USAGE_MUSIC = 1,<br/>AUDIOSTREAM_USAGE_COMMUNICATION = 2,<br/>AUDIOSTREAM_USAGE_VOICE_ASSISTANT = 3,<br/>AUDIOSTREAM_USAGE_ALARM = 4,<br/>AUDIOSTREAM_USAGE_VOICE_MESSAGE = 5,<br/>AUDIOSTREAM_USAGE_RINGTONE = 6,<br/>AUDIOSTREAM_USAGE_NOTIFICATION = 7,<br/>AUDIOSTREAM_USAGE_ACCESSIBILITY = 8,<br/>AUDIOSTREAM_USAGE_MOVIE = 10,<br/>AUDIOSTREAM_USAGE_GAME = 11,<br/>AUDIOSTREAM_USAGE_AUDIOBOOK = 12,<br/>AUDIOSTREAM_USAGE_NAVIGATION = 13<br/>} | 定义音频流使用场景。 | 
| OH_AudioStream_LatencyMode {<br/>AUDIOSTREAM_LATENCY_MODE_NORMAL = 0,<br/>AUDIOSTREAM_LATENCY_MODE_FAST = 1<br/>} | 定义音频时延模式。 | 
| OH_AudioStream_State {<br/>AUDIOSTREAM_STATE_INVALID = -1,<br/>AUDIOSTREAM_STATE_NEW = 0,<br/>AUDIOSTREAM_STATE_PREPARED = 1,<br/>AUDIOSTREAM_STATE_RUNNING = 2,<br/>AUDIOSTREAM_STATE_STOPPED = 3,<br/>AUDIOSTREAM_STATE_RELEASED = 4,<br/>AUDIOSTREAM_STATE_PAUSED = 5<br/>} | 定义音频流的状态。 | 
| OH_AudioStream_SourceType {<br/>AUDIOSTREAM_SOURCE_TYPE_INVALID = -1,<br/>AUDIOSTREAM_SOURCE_TYPE_MIC = 0,<br/>AUDIOSTREAM_SOURCE_TYPE_VOICE_RECOGNITION = 1,<br/>AUDIOSTREAM_SOURCE_TYPE_PLAYBACK_CAPTURE = 2,<br/>AUDIOSTREAM_SOURCE_TYPE_VOICE_COMMUNICATION = 7<br/>} | 定义音频流使用场景。 | 
| OH_AudioStream_Event {<br/>AUDIOSTREAM_EVENT_ROUTING_CHANGED = 0<br/>} | 定义音频事件。 | 
| OH_AudioInterrupt_ForceType {<br/>AUDIOSTREAM_INTERRUPT_FORCE = 0,<br/>AUDIOSTREAM_INTERRUPT_SHARE = 1<br/>} | 定义音频中断类型。 | 
| OH_AudioInterrupt_Hint {<br/>AUDIOSTREAM_INTERRUPT_HINT_NONE = 0,<br/>AUDIOSTREAM_INTERRUPT_HINT_RESUME = 1,<br/>AUDIOSTREAM_INTERRUPT_HINT_PAUSE = 2,<br/>AUDIOSTREAM_INTERRUPT_HINT_STOP = 3,<br/>AUDIOSTREAM_INTERRUPT_HINT_DUCK = 4,<br/>AUDIOSTREAM_INTERRUPT_HINT_UNDUCK = 5<br/>} | 定义音频中断类型。 | 
| OH_AudioStream_DeviceChangeReason {<br/>REASON_UNKNOWN = 0,<br/>REASON_NEW_DEVICE_AVAILABLE = 1,<br/>REASON_OLD_DEVICE_UNAVAILABLE = 2,<br/>REASON_OVERRODE = 3<br/>} | 流设备变更原因。 | 
