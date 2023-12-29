# OHAudio


## 概述

提供音频模块C接口定义。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_audiocapturer.h](native__audiocapturer_8h.md) | 声明输入类型的音频流相关接口。<br/>**引用文件**：&lt;ohaudio/native_audiocapturer.h&gt;<br/>**库**：libohaudio.so | 
| [native_audiorenderer.h](native__audiorenderer_8h.md) | 声明输出类型的音频流相关接口。<br/>**引用文件**：&lt;ohaudio/native_audiorenderer.h&gt;<br/>**库**：libohaudio.so | 
| [native_audiostream_base.h](native__audiostream__base_8h.md) | 声明OHAudio基础的数据结构。<br/>**引用文件**：&lt;ohaudio/native_audiostream_base.h&gt;<br/>**库**：libohaudio.so | 
| [native_audiostreambuilder.h](native__audiostreambuilder_8h.md) | 声明音频流构造器相关接口。<br/>**引用文件**：&lt;ohaudio/native_audiostreambuilder.h&gt;<br/>**库**：libohaudio.so | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioRenderer_Callbacks_Struct](_o_h___audio_renderer___callbacks___struct.md) | 声明输出音频流的回调函数指针。 | 
| [OH_AudioCapturer_Callbacks_Struct](_o_h___audio_capturer___callbacks___struct.md) | 声明输入音频流的回调函数指针。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioStreamBuilder](#oh_audiostreambuilder) | 声明音频流的构造器。 | 
| [OH_AudioRenderer](#oh_audiorenderer) | 声明输出音频流。 | 
| [OH_AudioCapturer](#oh_audiocapturer) | 声明输入音频流。 | 
| [OH_AudioRenderer_Callbacks](#oh_audiorenderer_callbacks) | 声明输出音频流的回调函数指针。 | 
| [OH_AudioCapturer_Callbacks](#oh_audiocapturer_callbacks) | 声明输入音频流的回调函数指针。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioStream_Result](#oh_audiostream_result) { AUDIOSTREAM_SUCCESS, AUDIOSTREAM_ERROR_INVALID_PARAM, AUDIOSTREAM_ERROR_ILLEGAL_STATE, AUDIOSTREAM_ERROR_SYSTEM } | 音频错误码。 | 
| [OH_AudioStream_Type](#oh_audiostream_type) { AUDIOSTREAM_TYPE_RERNDERER = 1, AUDIOSTREAM_TYPE_CAPTURER = 2 } | 音频流类型。 | 
| [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) { AUDIOSTREAM_SAMPLE_U8 = 0, AUDIOSTREAM_SAMPLE_S16LE = 1, AUDIOSTREAM_SAMPLE_S24LE = 2, AUDIOSTREAM_SAMPLE_S32LE = 3 } | 定义音频流采样格式。 | 
| [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) { AUDIOSTREAM_ENCODING_TYPE_RAW = 0 } | 定义音频流编码类型。 | 
| [OH_AudioStream_Usage](#oh_audiostream_usage) { AUDIOSTREAM_USAGE_UNKNOWN = 0, AUDIOSTREAM_USAGE_MUSIC = 1, AUDIOSTREAM_USAGE_COMMUNICATION = 2, AUDIOSTREAM_USAGE_GAME = 11 } | 定义音频流使用场景。 | 
| [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) { AUDIOSTREAM_LATENCY_MODE_NORMAL } | 定义音频时延模式。 | 
| [OH_AudioStream_State](#oh_audiostream_state) {<br/>AUDIOSTREAM_STATE_INVALID = -1, AUDIOSTREAM_STATE_PREPARED = 1, AUDIOSTREAM_STATE_RUNNING = 2, AUDIOSTREAM_STATE_STOPPED = 3,<br/>AUDIOSTREAM_STATE_RELEASED = 4, AUDIOSTREAM_STATE_PAUSED = 5<br/>} | 定义音频流的状态。 | 
| [OH_AudioStream_SourceType](#oh_audiostream_sourcetype) { AUDIOSTREAM_SOURCE_TYPE_INVALID = -1, AUDIOSTREAM_SOURCE_TYPE_MIC, AUDIOSTREAM_SOURCE_TYPE_VOICE_RECOGNITION = 1, AUDIOSTREAM_SOURCE_TYPE_VOICE_COMMUNICATION = 7 } | 定义音频流使用场景。 | 
| [OH_AudioStream_Event](#oh_audiostream_event) { AUDIOSTREAM_EVENT_ROUTING_CHANGED } | 定义音频事件。 | 
| [OH_AudioInterrupt_ForceType](#oh_audiointerrupt_forcetype) { AUDIOSTREAM_INTERRUPT_FORCE, AUDIOSTREAM_INTERRUPT_SHAR } | 定义音频中断类型。 | 
| [OH_AudioInterrupt_Hint](#oh_audiointerrupt_hint) {<br/>AUDIOSTREAM_INTERRUPT_HINT_NONE, AUDIOSTREAM_INTERRUPT_HINT_RESUME, AUDIOSTREAM_INTERRUPT_HINT_PAUSE, AUDIOSTREAM_INTERRUPT_HINT_STOP,<br/>AUDIOSTREAM_INTERRUPT_HINT_DUCK, AUDIOSTREAM_INTERRUPT_HINT_UNDUCK<br/>} | 定义音频中断类型。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioCapturer_Release](#oh_audiocapturer_release) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer) | 释放输入音频流。 | 
| [OH_AudioCapturer_Start](#oh_audiocapturer_start) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer) | 开始获取音频数据。 | 
| [OH_AudioCapturer_Pause](#oh_audiocapturer_pause) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer) | 暂停输入音频流。 | 
| [OH_AudioCapturer_Stop](#oh_audiocapturer_stop) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer) | 停止输入音频流 | 
| [OH_AudioCapturer_Flush](#oh_audiocapturer_flush) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer) | 丢弃获取的音频数据。 | 
| [OH_AudioCapturer_GetCurrentState](#oh_audiocapturer_getcurrentstate) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_State](#oh_audiostream_state) \*state) | 查询当前输入音频流状态。 | 
| [OH_AudioCapturer_GetLatencyMode](#oh_audiocapturer_getlatencymode) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) \*latencyMode) | 查询当前输入音频流时延模式。 | 
| [OH_AudioCapturer_GetStreamId](#oh_audiocapturer_getstreamid) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer, uint32_t \*streamId) | 查询当前输入音频流ID。 | 
| [OH_AudioCapturer_GetSamplingRate](#oh_audiocapturer_getsamplingrate) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer, int32_t \*rate) | 查询当前输入音频流采样率。 | 
| [OH_AudioCapturer_GetChannelCount](#oh_audiocapturer_getchannelcount) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer, int32_t \*channelCount) | 查询当前输入音频流通道数。 | 
| [OH_AudioCapturer_GetSampleFormat](#oh_audiocapturer_getsampleformat) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) \*sampleFormat) | 查询当前输入音频流采样格式。 | 
| [OH_AudioCapturer_GetEncodingType](#oh_audiocapturer_getencodingtype) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) \*encodingType) | 查询当前输入音频流编码类型。 | 
| [OH_AudioCapturer_GetCapturerInfo](#oh_audiocapturer_getcapturerinfo) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_SourceType](#oh_audiostream_sourcetype) \*sourceType) | 查询当前输入音频流工作场景类型。 | 
| [OH_AudioCapturer_GetFrameSizeInCallback](#oh_audiocapturer_getframesizeincallback) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer, int32_t \*frameSize) | 在回调中查询帧大小，它是每次回调返回的缓冲区的固定长度。 | 
| [OH_AudioCapturer_GetTimestamp](#oh_audiocapturer_gettimestamp) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer, clockid_t clockId, int64_t \*framePosition, int64_t \*timestamp) | 获取输入音频流时间戳和位置信息。 | 
| [OH_AudioCapturer_GetFramesRead](#oh_audiocapturer_getframesread) ([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, int64_t *frame) | 查询自创建流以来已读取的帧数。 |
| [OH_AudioRenderer_Release](#oh_audiorenderer_release) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | 释放输出音频流。 | 
| [OH_AudioRenderer_Start](#oh_audiorenderer_start) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | 开始输出音频数据。 | 
| [OH_AudioRenderer_Pause](#oh_audiorenderer_pause) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | 暂停输出音频流。 | 
| [OH_AudioRenderer_Stop](#oh_audiorenderer_stop) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | 停止输出音频流。 | 
| [OH_AudioRenderer_Flush](#oh_audiorenderer_flush) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | 丢弃已经写入的音频数据。 | 
| [OH_AudioRenderer_GetCurrentState](#oh_audiorenderer_getcurrentstate) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_State](#oh_audiostream_state) \*state) | 查询当前输出音频流状态。 | 
| [OH_AudioRenderer_GetSamplingRate](#oh_audiorenderer_getsamplingrate) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, int32_t \*rate) | 查询当前输出音频流采样率。 | 
| [OH_AudioRenderer_GetStreamId](#oh_audiorenderer_getstreamid) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, uint32_t \*streamId) | 查询当前输出音频流ID。 | 
| [OH_AudioRenderer_GetChannelCount](#oh_audiorenderer_getchannelcount) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, int32_t \*channelCount) | 查询当前输出音频流通道数。 | 
| [OH_AudioRenderer_GetSampleFormat](#oh_audiorenderer_getsampleformat) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) \*sampleFormat) | 查询当前输出音频流采样格式。 | 
| [OH_AudioRenderer_GetLatencyMode](#oh_audiorenderer_getlatencymode) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) \*latencyMode) | 查询当前输出音频流时延模式。 | 
| [OH_AudioRenderer_GetRendererInfo](#oh_audiorenderer_getrendererinfo) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_Usage](#oh_audiostream_usage) \*usage) | 查询当前输出音频流工作场景类型。 | 
| [OH_AudioRenderer_GetEncodingType](#oh_audiorenderer_getencodingtype) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) \*encodingType) | 查询当前输出音频流编码类型。 | 
| [OH_AudioRenderer_GetFramesWritten](#oh_audiorenderer_getframeswritten) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, int64_t \*frames) | 查询自创建流以来已写入的帧数。 | 
| [OH_AudioRenderer_GetTimestamp](#oh_audiorenderer_gettimestamp) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, clockid_t clockId, int64_t \*framePosition, int64_t \*timestamp) | 获取输出音频流时间戳和位置信息。 | 
| [OH_AudioRenderer_GetFrameSizeInCallback](#oh_audiorenderer_getframesizeincallback) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, int32_t \*frameSize) | 在回调中查询帧大小。 | 
| [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*\*builder, [OH_AudioStream_Type](#oh_audiostream_type) type) | 创建一个输入或者输出类型的音频流构造器。 | 
| [OH_AudioStreamBuilder_Destroy](#oh_audiostreambuilder_destroy) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder) | 销毁一个音频流构造器。 | 
| [OH_AudioStreamBuilder_SetSamplingRate](#oh_audiostreambuilder_setsamplingrate) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, int32_t rate) | 设置音频流的采样率属性。 | 
| [OH_AudioStreamBuilder_SetChannelCount](#oh_audiostreambuilder_setchannelcount) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, int32_t channelCount) | 设置音频流的通道数属性。 | 
| [OH_AudioStreamBuilder_SetSampleFormat](#oh_audiostreambuilder_setsampleformat) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) format) | 设置音频流的采样格式属性。 | 
| [OH_AudioStreamBuilder_SetEncodingType](#oh_audiostreambuilder_setencodingtype) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) encodingType) | 设置音频流的编码类型属性。 | 
| [OH_AudioStreamBuilder_SetLatencyMode](#oh_audiostreambuilder_setlatencymode) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) latencyMode) | 设置音频流的时延模式。 | 
| [OH_AudioStreamBuilder_SetRendererInfo](#oh_audiostreambuilder_setrendererinfo) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_Usage](#oh_audiostream_usage) usage) | 设置输出音频流的工作场景。 | 
| [OH_AudioStreamBuilder_SetCapturerInfo](#oh_audiostreambuilder_setcapturerinfo) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_SourceType](#oh_audiostream_sourcetype) sourceType) | 设置输入音频流的工作场景。 | 
| [OH_AudioStreamBuilder_SetRendererCallback](#oh_audiostreambuilder_setrenderercallback) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioRenderer_Callbacks](#oh_audiorenderer_callbacks) callbacks, void \*userData) | 设置输出音频流的回调。 | 
| [OH_AudioStreamBuilder_SetCapturerCallback](#oh_audiostreambuilder_setcapturercallback) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioCapturer_Callbacks](#oh_audiocapturer_callbacks) callbacks, void \*userData) | 设置输入音频流的回调。 | 
| [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioRenderer](#oh_audiorenderer) \*\*audioRenderer) | 创建输出音频流实例。 | 
| [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioCapturer](#oh_audiocapturer) \*\*audioCapturer) | 创建输入音频流实例。 | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| (\*[OH_AudioRenderer_Callbacks_Struct::OH_AudioRenderer_OnWriteData](#oh_audiorenderer_onwritedata) )([OH_AudioRenderer](#oh_audiorenderer) \*renderer, void \*userData, void \*buffer, int32_t lenth) | 该函数指针将指向用于写入音频数据的回调函数。 | 
| (\*[OH_AudioCapturer_Callbacks_Struct::OH_AudioCapturer_OnReadData](#oh_audiocapturer_onreaddata) )([OH_AudioCapturer](#oh_audiocapturer) \*capturer, void \*userData, void \*buffer, int32_t lenth) | 该函数指针将指向用于读取音频数据的回调函数。 | 


## 类型定义说明


### OH_AudioCapturer

```
typedef struct OH_AudioCapturerStruct OH_AudioCapturer
```

**描述**

声明输入音频流。

输入音频流的实例被用来获取音频数据。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10


### OH_AudioCapturer_Callbacks

```
typedef struct OH_AudioCapturer_Callbacks_Struct OH_AudioCapturer_Callbacks
```

**描述**

声明输入音频流的回调函数指针。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10


### OH_AudioRenderer

```
typedef struct OH_AudioRendererStruct OH_AudioRenderer
```

**描述**

声明输出音频流。

输出音频流的实例被用来播放音频数据。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10


### OH_AudioRenderer_Callbacks

```
typedef struct OH_AudioRenderer_Callbacks_Struct OH_AudioRenderer_Callbacks
```

**描述**

声明输出音频流的回调函数指针。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10


### OH_AudioStreamBuilder

```
typedef struct OH_AudioStreamBuilderStruct OH_AudioStreamBuilder
```

**描述**

声明音频流的构造器。

构造器实例通常被用来设置音频流属性和创建音频流。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10


## 枚举类型说明


### OH_AudioInterrupt_ForceType

```
enum OH_AudioInterrupt_ForceType
```

**描述**

定义音频中断类型。

通常用来描述音频中断事件。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIOSTREAM_INTERRUPT_FORCE | 强制类型，系统更改音频状态。 | 
| AUDIOSTREAM_INTERRUPT_SHAR | 共享类型，应用程序更改音频状态。 | 


### OH_AudioInterrupt_Hint

```
enum OH_AudioInterrupt_Hint
```

**描述**

定义音频中断类型。

通常用来描述音频中断事件。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIOSTREAM_INTERRUPT_HINT_NONE | 不提示。 | 
| AUDIOSTREAM_INTERRUPT_HINT_RESUME | 恢复流提示。 | 
| AUDIOSTREAM_INTERRUPT_HINT_PAUSE | 暂停流提示。 | 
| AUDIOSTREAM_INTERRUPT_HINT_STOP | 停止流提示。 | 
| AUDIOSTREAM_INTERRUPT_HINT_DUCK | 短暂降低音量。 | 
| AUDIOSTREAM_INTERRUPT_HINT_UNDUCK | 恢复音量。 | 


### OH_AudioStream_EncodingType

```
enum OH_AudioStream_EncodingType
```

**描述**

定义音频流编码类型。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIOSTREAM_ENCODING_TYPE_RAW | PCM编码。 | 


### OH_AudioStream_Event

```
enum OH_AudioStream_Event
```

**描述**

定义音频事件。

通常用来描述音频事件。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIOSTREAM_EVENT_ROUTING_CHANGED | 音频的路由已更改。 | 


### OH_AudioStream_LatencyMode

```
enum OH_AudioStream_LatencyMode
```

**描述**

定义音频时延模式。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIOSTREAM_LATENCY_MODE_NORMAL | 该模式代表一个普通时延的音频流。 | 


### OH_AudioStream_Result

```
enum OH_AudioStream_Result
```

**描述**

音频错误码。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIOSTREAM_SUCCESS | 操作成功。 | 
| AUDIOSTREAM_ERROR_INVALID_PARAM | 入参错误。 | 
| AUDIOSTREAM_ERROR_ILLEGAL_STATE | 非法状态。 | 
| AUDIOSTREAM_ERROR_SYSTEM | 系统通用错误。 | 


### OH_AudioStream_SampleFormat

```
enum OH_AudioStream_SampleFormat
```

**描述**

定义音频流采样格式。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIOSTREAM_SAMPLE_U8 | Unsigned 8位。 | 
| AUDIOSTREAM_SAMPLE_S16LE | Short 16位小端。 | 
| AUDIOSTREAM_SAMPLE_S24LE | Short 24位小端。 | 
| AUDIOSTREAM_SAMPLE_S32LE | Short 32位小端。 | 


### OH_AudioStream_SourceType

```
enum OH_AudioStream_SourceType
```

**描述**

定义音频流使用场景。

通常用来描述音频输入流的使用场景。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIOSTREAM_SOURCE_TYPE_INVALID | 不合法状态。 | 
| AUDIOSTREAM_SOURCE_TYPE_MIC | 录音。 | 
| AUDIOSTREAM_SOURCE_TYPE_VOICE_RECOGNITION | 语音识别。 | 
| AUDIOSTREAM_SOURCE_TYPE_VOICE_COMMUNICATION | 通话。 | 


### OH_AudioStream_State

```
enum OH_AudioStream_State
```

**描述**

定义音频流的状态。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIOSTREAM_STATE_INVALID | 不合法的状态。 | 
| AUDIOSTREAM_STATE_PREPARED | 准备状态。 | 
| AUDIOSTREAM_STATE_RUNNING | 工作状态。 | 
| AUDIOSTREAM_STATE_STOPPED | 停止状态。 | 
| AUDIOSTREAM_STATE_RELEASED | 释放状态。 | 
| AUDIOSTREAM_STATE_PAUSED | 暂停状态。 | 


### OH_AudioStream_Type

```
enum OH_AudioStream_Type
```

**描述**

音频流类型。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIOSTREAM_TYPE_RENDERER | 该类型代表音频流是输出流。 | 
| AUDIOSTREAM_TYPE_CAPTURER | 该类型代表音频流是输入流。 | 


### OH_AudioStream_Usage

```
enum OH_AudioStream_Usage
```

**描述**

定义音频流使用场景。

通常用来描述音频输出流的使用场景。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIOSTREAM_USAGE_UNKNOWN | 未定义。 | 
| AUDIOSTREAM_USAGE_MUSIC | 音乐。 | 
| AUDIOSTREAM_USAGE_COMMUNICATION | 通话。 | 
| AUDIOSTREAM_USAGE_GAME | 游戏。 | 


## 函数说明


### OH_AudioCapturer_Flush()

```
OH_AudioStream_Result OH_AudioCapturer_Flush (OH_AudioCapturer * capturer)
```

**描述**

丢弃获取的音频数据。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioCapturer_GetCapturerInfo()

```
OH_AudioStream_Result OH_AudioCapturer_GetCapturerInfo (OH_AudioCapturer * capturer, OH_AudioStream_SourceType * sourceType )
```

**描述**

查询当前音频流工作场景类型。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 | 
| sourceType | 指向一个用来接收输入类型音频流的工作场景的变量。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioCapturer_GetChannelCount()

```
OH_AudioStream_Result OH_AudioCapturer_GetChannelCount (OH_AudioCapturer * capturer, int32_t * channelCount )
```

**描述**

查询当前音频流通道数。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 | 
| channelCount | 指向一个用来接收音频流通道数的变量。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioCapturer_GetCurrentState()

```
OH_AudioStream_Result OH_AudioCapturer_GetCurrentState (OH_AudioCapturer * capturer, OH_AudioStream_State * state )
```

**描述**

查询当前音频流状态。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 | 
| state | 指向一个用来接收音频流状态的变量。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioCapturer_GetEncodingType()

```
OH_AudioStream_Result OH_AudioCapturer_GetEncodingType (OH_AudioCapturer * capturer, OH_AudioStream_EncodingType * encodingType )
```

**描述**

查询当前音频流编码类型。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 | 
| encodingType | 指向一个用来接收音频流编码类型的变量。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。

### OH_AudioCapturer_GetFramesRead()

```
OH_AudioStream_Result OH_AudioCapturer_GetFramesRead (OH_AudioCapturer * capturer, int64_t * frames )
```

**描述**

查询自创建流以来已读取的帧数。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 | 
| frames | 指向将为帧计数设置的变量的指针（作为返回值使用）。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。

### OH_AudioCapturer_GetFrameSizeInCallback()

```
OH_AudioStream_Result OH_AudioCapturer_GetFrameSizeInCallback (OH_AudioCapturer * capturer, int32_t * frameSize )
```

**描述**

在回调中查询帧大小，它是每次回调返回的缓冲区的固定长度。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 | 
| frameSize | 指向将为帧大小设置的变量的指针。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioCapturer_GetLatencyMode()

```
OH_AudioStream_Result OH_AudioCapturer_GetLatencyMode (OH_AudioCapturer * capturer, OH_AudioStream_LatencyMode * latencyMode )
```

**描述**

查询当前音频流时延模式。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 | 
| latencyMode | 指向一个用来接收音频流时延模式的变量。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioCapturer_GetSampleFormat()

```
OH_AudioStream_Result OH_AudioCapturer_GetSampleFormat (OH_AudioCapturer * capturer, OH_AudioStream_SampleFormat * sampleFormat )
```

**描述**

查询当前输入音频流采样格式。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 | 
| sampleFormat | 指向一个用来接收音频流采样格式的变量。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioCapturer_GetSamplingRate()

```
OH_AudioStream_Result OH_AudioCapturer_GetSamplingRate (OH_AudioCapturer * capturer, int32_t * rate )
```

**描述**

查询当前输入音频流采样率。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 | 
| rate | 指向一个用来接收音频流采样率的变量。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioCapturer_GetStreamId()

```
OH_AudioStream_Result OH_AudioCapturer_GetStreamId (OH_AudioCapturer * capturer, uint32_t * streamId )
```

**描述**

查询当前输入音频流ID。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 | 
| streamId | 指向一个用来接收音频流ID的变量。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioCapturer_GetTimestamp()

```
OH_AudioStream_Result OH_AudioCapturer_GetTimestamp (OH_AudioCapturer * capturer, clockid_t clockId, int64_t * framePosition, int64_t * timestamp )
```

**描述**

获取输入音频流时间戳和位置信息。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 | 
| clockId | CLOCK_MONOTONIC。 | 
| framePosition | 指向要接收位置的变量的指针。 | 
| timestamp | 指向接收时间戳的变量的指针。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioCapturer_Pause()

```
OH_AudioStream_Result OH_AudioCapturer_Pause (OH_AudioCapturer * capturer)
```

**描述**

暂停输入音频流。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 | 

**需要权限：**

ohos.permission.MICROPHONE

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioCapturer_Release()

```
OH_AudioStream_Result OH_AudioCapturer_Release (OH_AudioCapturer * capturer)
```

**描述**

释放输入音频流。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 | 

**需要权限：**

ohos.permission.MICROPHONE

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioCapturer_Start()

```
OH_AudioStream_Result OH_AudioCapturer_Start (OH_AudioCapturer * capturer)
```

**描述**

开始获取音频数据。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 | 

**需要权限：**

ohos.permission.MICROPHONE

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioCapturer_Stop()

```
OH_AudioStream_Result OH_AudioCapturer_Stop (OH_AudioCapturer * capturer)
```

**描述**

停止输入音频流

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 | 

**需要权限：**

ohos.permission.MICROPHONE

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioRenderer_Flush()

```
OH_AudioStream_Result OH_AudioRenderer_Flush (OH_AudioRenderer * renderer)
```

**描述**

丢弃已经写入的音频数据。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioRenderer_GetChannelCount()

```
OH_AudioStream_Result OH_AudioRenderer_GetChannelCount (OH_AudioRenderer * renderer, int32_t * channelCount )
```

**描述**

查询当前输出音频流通道数。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 | 
| channelCount | 指向一个用来接收音频流通道数的变量。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioRenderer_GetCurrentState()

```
OH_AudioStream_Result OH_AudioRenderer_GetCurrentState (OH_AudioRenderer * renderer, OH_AudioStream_State * state )
```

**描述**

查询当前输出音频流状态。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 | 
| state | 指向一个用来接收音频流状态的变量。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioRenderer_GetEncodingType()

```
OH_AudioStream_Result OH_AudioRenderer_GetEncodingType (OH_AudioRenderer * renderer, OH_AudioStream_EncodingType * encodingType )
```

**描述**

查询当前输出音频流编码类型。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 | 
| encodingType | 指向一个用来接收音频流编码类型的变量。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioRenderer_GetFrameSizeInCallback()

```
OH_AudioStream_Result OH_AudioRenderer_GetFrameSizeInCallback (OH_AudioRenderer * renderer, int32_t * frameSize )
```

**描述**

在回调中查询帧大小，它是一个固定的长度，每次回调都要填充流。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 | 
| frameSize | 指向将为帧大小设置的变量的指针。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioRenderer_GetFramesWritten()

```
OH_AudioStream_Result OH_AudioRenderer_GetFramesWritten (OH_AudioRenderer * renderer, int64_t * frames )
```

**描述**

查询自创建流以来已写入的帧数。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 | 
| frames | 指向将为帧计数设置的变量的指针。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioRenderer_GetLatencyMode()

```
OH_AudioStream_Result OH_AudioRenderer_GetLatencyMode (OH_AudioRenderer * renderer, OH_AudioStream_LatencyMode * latencyMode )
```

**描述**

查询当前输出音频流时延模式。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 | 
| latencyMode | 指向一个用来接收音频流时延模式的变量。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioRenderer_GetRendererInfo()

```
OH_AudioStream_Result OH_AudioRenderer_GetRendererInfo (OH_AudioRenderer * renderer, OH_AudioStream_Usage * usage )
```

**描述**

查询当前输出音频流工作场景类型。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 | 
| usage | 指向一个用来接收输出类型音频流的工作场景的变量。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioRenderer_GetSampleFormat()

```
OH_AudioStream_Result OH_AudioRenderer_GetSampleFormat (OH_AudioRenderer * renderer, OH_AudioStream_SampleFormat * sampleFormat )
```

**描述**

查询当前输出音频流采样格式。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 | 
| sampleFormat | 指向一个用来接收音频流采样格式的变量。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioRenderer_GetSamplingRate()

```
OH_AudioStream_Result OH_AudioRenderer_GetSamplingRate (OH_AudioRenderer * renderer, int32_t * rate )
```

**描述**

查询当前输出音频流采样率。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 | 
| rate | 指向一个用来接收音频流采样率的变量。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioRenderer_GetStreamId()

```
OH_AudioStream_Result OH_AudioRenderer_GetStreamId (OH_AudioRenderer * renderer, uint32_t * streamId )
```

**描述**

查询当前输出音频流ID。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 | 
| streamId | 指向一个用来接收音频流ID的变量。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioRenderer_GetTimestamp()

```
OH_AudioStream_Result OH_AudioRenderer_GetTimestamp (OH_AudioRenderer * renderer, clockid_t clockId, int64_t * framePosition, int64_t * timestamp )
```

**描述**

获取输出音频流时间戳和位置信息。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 | 
| clockId | CLOCK_MONOTONIC | 
| framePosition | 指向要接收位置的变量的指针。 | 
| timestamp | 指向接收时间戳的变量的指针。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioRenderer_Pause()

```
OH_AudioStream_Result OH_AudioRenderer_Pause (OH_AudioRenderer * renderer)
```

**描述**

暂停输出音频流。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioRenderer_Release()

```
OH_AudioStream_Result OH_AudioRenderer_Release (OH_AudioRenderer * renderer)
```

**描述**

释放输出音频流。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioRenderer_Start()

```
OH_AudioStream_Result OH_AudioRenderer_Start (OH_AudioRenderer * renderer)
```

**描述**

开始输出音频数据。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioRenderer_Stop()

```
OH_AudioStream_Result OH_AudioRenderer_Stop (OH_AudioRenderer * renderer)
```

**描述**

停止输出音频流。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioStreamBuilder_Create()

```
OH_AudioStream_Result OH_AudioStreamBuilder_Create (OH_AudioStreamBuilder ** builder, OH_AudioStream_Type type )
```

**描述**

创建一个输入或者输出类型的音频流构造器。

当构造器不再使用时，需要调用OH_AudioStreamBuilder_Destroy()销毁它。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 该引用指向创建的构造器的结果。 | 
| type | 构造器的流类型。AUDIOSTREAM_TYPE_RERNDERER or AUDIOSTREAM_TYPE_CAPTURER | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioStreamBuilder_Destroy()

```
OH_AudioStream_Result OH_AudioStreamBuilder_Destroy (OH_AudioStreamBuilder * builder)
```

**描述**

销毁一个音频流构造器。

当构造器不再使用时，需要调用该函数销毁它。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioStreamBuilder_GenerateCapturer()

```
OH_AudioStream_Result OH_AudioStreamBuilder_GenerateCapturer (OH_AudioStreamBuilder * builder, OH_AudioCapturer ** audioCapturer )
```

**描述**

创建输入音频流实例。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。 | 
| audioCapturer | 指向输入音频流实例的指针，将被用来接收函数创建的结果。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioStreamBuilder_GenerateRenderer()

```
OH_AudioStream_Result OH_AudioStreamBuilder_GenerateRenderer (OH_AudioStreamBuilder * builder, OH_AudioRenderer ** audioRenderer )
```

**描述**

创建输出音频流实例。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。 | 
| audioRenderer | 指向输出音频流实例的指针，将被用来接收函数创建的结果。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioStreamBuilder_SetCapturerCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerCallback (OH_AudioStreamBuilder * builder, OH_AudioCapturer_Callbacks callbacks, void * userData )
```

**描述**

设置输入音频流的回调。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。 | 
| callbacks | 将被用来处理输入音频流相关事件的回调函数。 | 
| userData | 指向通过回调函数传递的应用数据指针。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioStreamBuilder_SetCapturerInfo()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerInfo (OH_AudioStreamBuilder * builder, OH_AudioStream_SourceType sourceType )
```

**描述**

设置输入音频流的工作场景。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。 | 
| sourceType | 输入音频流属性，使用的工作场景。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioStreamBuilder_SetChannelCount()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetChannelCount (OH_AudioStreamBuilder * builder, int32_t channelCount )
```

**描述**

设置音频流的通道数属性。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。 | 
| channelCount | 音频流通道数。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioStreamBuilder_SetEncodingType()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetEncodingType (OH_AudioStreamBuilder * builder, OH_AudioStream_EncodingType encodingType )
```

**描述**

设置音频流的编码类型属性。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。 | 
| encodingType | 音频流编码类型, **AUDIOSTREAM_ENCODING_PCM** | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioStreamBuilder_SetLatencyMode()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetLatencyMode (OH_AudioStreamBuilder * builder, OH_AudioStream_LatencyMode latencyMode )
```

**描述**

设置音频流的时延模式。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。 | 
| latencyMode | 音频流时延模式。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioStreamBuilder_SetRendererCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererCallback (OH_AudioStreamBuilder * builder, OH_AudioRenderer_Callbacks callbacks, void * userData )
```

**描述**

设置输出音频流的回调。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。 | 
| callbacks | 将被用来处理输出音频流相关事件的回调函数。 | 
| userData | 指向通过回调函数传递的应用数据指针。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioStreamBuilder_SetRendererInfo()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInfo (OH_AudioStreamBuilder * builder, OH_AudioStream_Usage usage )
```

**描述**

设置输出音频流的工作场景。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。 | 
| usage | 输出音频流属性，使用的工作场景。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioStreamBuilder_SetSampleFormat()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetSampleFormat (OH_AudioStreamBuilder * builder, OH_AudioStream_SampleFormat format )
```

**描述**

设置音频流的采样格式属性。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。 | 
| format | 音频流采样格式。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


### OH_AudioStreamBuilder_SetSamplingRate()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetSamplingRate (OH_AudioStreamBuilder * builder, int32_t rate )
```

**描述**

设置音频流的采样率属性。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。 | 
| channelCount | 音频流采样率。 | 

**返回：**

AUDIOSTREAM_SUCCESS 或者一个预期之外的错误。


## 变量说明


### OH_AudioCapturer_OnReadData

```
int32_t(* OH_AudioCapturer_Callbacks_Struct::OH_AudioCapturer_OnReadData) (OH_AudioCapturer *capturer, void *userData, void *buffer, int32_t lenth)
```

**描述**

该函数指针将指向用于读取音频数据的回调函数。

**起始版本：** 10


### OH_AudioRenderer_OnWriteData

```
int32_t(* OH_AudioRenderer_Callbacks_Struct::OH_AudioRenderer_OnWriteData) (OH_AudioRenderer *renderer, void *userData, void *buffer, int32_t lenth)
```

**描述**

该函数指针将指向用于写入音频数据的回调函数。

**起始版本：** 10
