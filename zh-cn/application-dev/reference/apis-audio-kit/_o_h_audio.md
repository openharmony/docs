# OHAudio


## 概述

提供音频模块C接口定义。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_audio_common.h](native__audio__common_8h.md) | 声明音频公共基础数据结构。<br/>**引用文件**：&lt;ohaudio/native_audio_common.h&gt;<br/>**库**：libohaudio.so | 
| [native_audio_device_base.h](native__audio__device__base_8h.md) | 定义音频设备参数的类型以及获取每个设备参数的接口。<br/>**引用文件**：&lt;ohaudio/native_audio_device_base.h&gt;<br/>**库**：libohaudio.so | 
| [native_audio_routing_manager.h](native__audio__routing__manager_8h.md) | 声明与音频路由管理器相关的接口。<br/>**引用文件**：&lt;ohaudio/native_audio_routing_manager.h&gt;<br/>**库**：libohaudio.so | 
| [native_audiocapturer.h](native__audiocapturer_8h.md) | 声明输入类型的音频流相关接口。<br/>**引用文件**：&lt;ohaudio/native_audiocapturer.h&gt;<br/>**库**：libohaudio.so | 
| [native_audiorenderer.h](native__audiorenderer_8h.md) | 声明输出类型的音频流相关接口。<br/>**引用文件**：&lt;ohaudio/native_audiorenderer.h&gt;<br/>**库**：libohaudio.so | 
| [native_audiostream_base.h](native__audiostream__base_8h.md) | 声明OHAudio基础的数据结构。<br/>**引用文件**：&lt;ohaudio/native_audiostream_base.h&gt;<br/>**库**：libohaudio.so | 
| [native_audiostreambuilder.h](native__audiostreambuilder_8h.md) | 声明音频流构造器相关接口。<br/>**引用文件**：&lt;ohaudio/native_audiostreambuilder.h&gt;<br/>**库**：libohaudio.so | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) | 声明音频设备描述符数组。 | 
| struct  [OH_AudioRenderer_Callbacks_Struct](_o_h___audio_renderer___callbacks___struct.md) | 声明输出音频流的回调函数指针。 | 
| struct  [OH_AudioCapturer_Callbacks_Struct](_o_h___audio_capturer___callbacks___struct.md) | 声明输入音频流的回调函数指针。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) [OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) | 声明音频设备描述符。 该实例用于获取更多音频设备详细信息属性。 | 
| typedef struct [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) [OH_AudioDeviceDescriptorArray](#oh_audiodevicedescriptorarray) | 声明音频设备描述符数组。 | 
| typedef struct [OH_AudioRoutingManager](#oh_audioroutingmanager) [OH_AudioRoutingManager](#oh_audioroutingmanager) | 声明音频路由管理器，用于路由和设备相关功能的音频路由管理器的句柄。 | 
| typedef int32_t(\* [OH_AudioRoutingManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback)) ([OH_AudioDevice_ChangeType](#oh_audiodevice_changetype) type, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*audioDeviceDescriptorArray) | 此函数指针将指向用于返回更改的音频设备描述符的回调函数，可能返回多个音频设备描述符。 | 
| typedef struct OH_AudioStreamBuilderStruct [OH_AudioStreamBuilder](#oh_audiostreambuilder)                                                                  | 声明音频流的构造器。 | 
| typedef struct OH_AudioRendererStruct [OH_AudioRenderer](#oh_audiorenderer)                                                                                 | 声明输出音频流。 | 
| typedef struct OH_AudioCapturerStruct [OH_AudioCapturer](#oh_audiocapturer)                                                                                 | 声明输入音频流。 | 
| typedef struct [OH_AudioRenderer_Callbacks_Struct](_o_h___audio_renderer___callbacks___struct.md) [OH_AudioRenderer_Callbacks](#oh_audiorenderer_callbacks) | 声明输出音频流的回调函数指针。 | 
| typedef struct [OH_AudioCapturer_Callbacks_Struct](_o_h___audio_capturer___callbacks___struct.md) [OH_AudioCapturer_Callbacks](#oh_audiocapturer_callbacks) | 声明输入音频流的回调函数指针。 | 
| typedef void(\* [OH_AudioRenderer_OutputDeviceChangeCallback](#oh_audiorenderer_outputdevicechangecallback)) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, void \*userData, [OH_AudioStream_DeviceChangeReason](#oh_audiostream_devicechangereason) reason) | 输出音频流设备变更的回调函数。 | 
| typedef void(\* [OH_AudioRenderer_OnMarkReachedCallback](#oh_audiorenderer_onmarkreachedcallback)) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, uint32_t samplePos, void \*userData) | 到达标记位置时回调。  | 
| typedef int32_t(\* [OH_AudioRenderer_WriteDataWithMetadataCallback](#oh_audiorenderer_writedatawithmetadatacallback)) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, void \*userData, void \*audioData, int32_t audioDataSize, void \*metadata, int32_t metadataSize) | 该函数指针将指向用于同时写入音频数据和元数据的回调函数。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioCommon_Result](#oh_audiocommon_result) {<br/>AUDIOCOMMON_RESULT_SUCCESS = 0,<br/>AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM = 6800101,<br/>AUDIOCOMMON_RESULT_ERROR_NO_MEMORY = 6800102,<br/>AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE = 6800103,<br/>AUDIOCOMMON_RESULT_ERROR_UNSUPPORTED = 6800104,<br/>AUDIOCOMMON_RESULT_ERROR_TIMEOUT = 6800105,<br/>AUDIOCOMMON_RESULT_ERROR_STREAM_LIMIT = 6800201,<br/>AUDIOCOMMON_RESULT_ERROR_SYSTEM = 6800301<br/>} | 音频错误码。 | 
| [OH_AudioDevice_ChangeType](#oh_audiodevice_changetype) {<br/>AUDIO_DEVICE_CHANGE_TYPE_CONNECT = 0,<br/>AUDIO_DEVICE_CHANGE_TYPE_DISCONNECT = 1<br/>} | 定义音频设备更改类型。 | 
| [OH_AudioDevice_Role](#oh_audiodevice_role) {<br/>AUDIO_DEVICE_ROLE_INPUT = 1,<br/>AUDIO_DEVICE_ROLE_OUTPUT = 2<br/>} | 定义音频设备设备角色。 | 
| [OH_AudioDevice_Type](#oh_audiodevice_type) {<br/>AUDIO_DEVICE_TYPE_INVALID = 0,<br/>AUDIO_DEVICE_TYPE_EARPIECE = 1,<br/>AUDIO_DEVICE_TYPE_SPEAKER = 2,<br/>AUDIO_DEVICE_TYPE_WIRED_HEADSET = 3,<br/>AUDIO_DEVICE_TYPE_WIRED_HEADPHONES = 4,<br/>AUDIO_DEVICE_TYPE_BLUETOOTH_SCO = 7,<br/>AUDIO_DEVICE_TYPE_BLUETOOTH_A2DP = 8,<br/>AUDIO_DEVICE_TYPE_MIC = 15,<br/>AUDIO_DEVICE_TYPE_USB_HEADSET = 22,<br/>AUDIO_DEVICE_TYPE_DISPLAY_PORT = 23,<br/>AUDIO_DEVICE_TYPE_DEFAULT = 1000<br/>} | 定义音频设备设备类型。 | 
| [OH_AudioDevice_Flag](#oh_audiodevice_flag) {<br/>AUDIO_DEVICE_FLAG_NONE = 0,<br/>AUDIO_DEVICE_FLAG_OUTPUT = 1,<br/>AUDIO_DEVICE_FLAG_INPUT = 2,<br/>AUDIO_DEVICE_FLAG_ALL = 3<br/>} | 定义音频设备标志。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) {<br/>AUDIOSTREAM_SUCCESS = 0,<br/>AUDIOSTREAM_ERROR_INVALID_PARAM = 1,<br/>AUDIOSTREAM_ERROR_ILLEGAL_STATE = 2,<br/>AUDIOSTREAM_ERROR_SYSTEM = 3<br/>} | 音频错误码。 | 
| [OH_AudioStream_Type](#oh_audiostream_type) {<br/>AUDIOSTREAM_TYPE_RERNDERER = 1,<br/>AUDIOSTREAM_TYPE_CAPTURER = 2<br/>} | 音频流类型。 | 
| [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) {<br/>AUDIOSTREAM_SAMPLE_U8 = 0,<br/>AUDIOSTREAM_SAMPLE_S16LE = 1,<br/>AUDIOSTREAM_SAMPLE_S24LE = 2,<br/>AUDIOSTREAM_SAMPLE_S32LE = 3<br/>} | 定义音频流采样格式。 | 
| [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) { <br/>AUDIOSTREAM_ENCODING_TYPE_RAW = 0, <br/>AUDIOSTREAM_ENCODING_TYPE_AUDIOVIVID = 1 <br/>} | 定义音频流编码类型。  | 
| [OH_AudioStream_Usage](#oh_audiostream_usage) {<br/>AUDIOSTREAM_USAGE_UNKNOWN = 0,<br/>AUDIOSTREAM_USAGE_MUSIC = 1,<br/>AUDIOSTREAM_USAGE_COMMUNICATION = 2,<br/>AUDIOSTREAM_USAGE_VOICE_ASSISTANT = 3,<br/>AUDIOSTREAM_USAGE_ALARM = 4,<br/>AUDIOSTREAM_USAGE_VOICE_MESSAGE = 5,<br/>AUDIOSTREAM_USAGE_RINGTONE = 6,<br/>AUDIOSTREAM_USAGE_NOTIFICATION = 7,<br/>AUDIOSTREAM_USAGE_ACCESSIBILITY = 8,<br/>AUDIOSTREAM_USAGE_MOVIE = 10,<br/>AUDIOSTREAM_USAGE_GAME = 11,<br/>AUDIOSTREAM_USAGE_AUDIOBOOK = 12,<br/>AUDIOSTREAM_USAGE_NAVIGATION = 13<br/>} | 定义音频流使用场景。 | 
| [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) {<br/>AUDIOSTREAM_LATENCY_MODE_NORMAL = 0,<br/>AUDIOSTREAM_LATENCY_MODE_FAST = 1<br/>} | 定义音频时延模式。 | 
| [OH_AudioStream_State](#oh_audiostream_state) {<br/>AUDIOSTREAM_STATE_INVALID = -1,<br/>AUDIOSTREAM_STATE_NEW = 0,<br/>AUDIOSTREAM_STATE_PREPARED = 1,<br/>AUDIOSTREAM_STATE_RUNNING = 2,<br/>AUDIOSTREAM_STATE_STOPPED = 3,<br/>AUDIOSTREAM_STATE_RELEASED = 4,<br/>AUDIOSTREAM_STATE_PAUSED = 5<br/>} | 定义音频流的状态。 | 
| [OH_AudioStream_SourceType](#oh_audiostream_sourcetype) {<br/>AUDIOSTREAM_SOURCE_TYPE_INVALID = -1,<br/>AUDIOSTREAM_SOURCE_TYPE_MIC = 0,<br/>AUDIOSTREAM_SOURCE_TYPE_VOICE_RECOGNITION = 1,<br/>AUDIOSTREAM_SOURCE_TYPE_PLAYBACK_CAPTURE = 2,<br/>AUDIOSTREAM_SOURCE_TYPE_VOICE_COMMUNICATION = 7<br/>} | 定义音频流使用场景。 | 
| [OH_AudioStream_Event](#oh_audiostream_event) {<br/>AUDIOSTREAM_EVENT_ROUTING_CHANGED = 0<br/>} | 定义音频事件。 | 
| [OH_AudioInterrupt_ForceType](#oh_audiointerrupt_forcetype) {<br/>AUDIOSTREAM_INTERRUPT_FORCE = 0,<br/>AUDIOSTREAM_INTERRUPT_SHARE = 1<br/>} | 定义音频中断类型。 | 
| [OH_AudioInterrupt_Hint](#oh_audiointerrupt_hint) {<br/>AUDIOSTREAM_INTERRUPT_HINT_NONE = 0,<br/>AUDIOSTREAM_INTERRUPT_HINT_RESUME = 1,<br/>AUDIOSTREAM_INTERRUPT_HINT_PAUSE = 2,<br/>AUDIOSTREAM_INTERRUPT_HINT_STOP = 3,<br/>AUDIOSTREAM_INTERRUPT_HINT_DUCK = 4,<br/>AUDIOSTREAM_INTERRUPT_HINT_UNDUCK = 5<br/>} | 定义音频中断类型。 | 
| [OH_AudioInterrupt_Mode](#oh_audiointerrupt_mode) {<br/> AUDIOSTREAM_INTERRUPT_MODE_SHARE = 0, <br/>AUDIOSTREAM_INTERRUPT_MODE_INDEPENDENT = 1 <br/>} | 定义音频中断模式。  | 
| [OH_AudioStream_AudioEffectMode](#oh_audiostream_audioeffectmode) { <br/>EFFECT_NONE = 0, <br/>EFFECT_DEFAULT = 1 <br/>} | 定义音效模式。  | 
| [OH_AudioStream_DeviceChangeReason](#oh_audiostream_devicechangereason) {<br/>REASON_UNKNOWN = 0,<br/>REASON_NEW_DEVICE_AVAILABLE = 1,<br/>REASON_OLD_DEVICE_UNAVAILABLE = 2,<br/>REASON_OVERRODE = 3<br/>} | 流设备变更原因。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceRole](#oh_audiodevicedescriptor_getdevicerole) ([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, [OH_AudioDevice_Role](#oh_audiodevice_role) \*deviceRole) | 查询目标音频设备描述符的设备角色。 | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceType](#oh_audiodevicedescriptor_getdevicetype) ([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, [OH_AudioDevice_Type](#oh_audiodevice_type) \*deviceType) | 查询目标音频设备描述符的设备类型。 | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceId](#oh_audiodevicedescriptor_getdeviceid) ([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, uint32_t \*id) | 查询目标音频设备描述符的设备id。 | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceName](#oh_audiodevicedescriptor_getdevicename) ([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, char \*\*name) | 查询目标音频设备描述符的设备名称。 | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceAddress](#oh_audiodevicedescriptor_getdeviceaddress) ([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, char \*\*address) | 查询目标音频设备描述符的设备地址。 | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceSampleRates](#oh_audiodevicedescriptor_getdevicesamplerates) ([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, uint32_t \*\*sampleRates, uint32_t \*size) | 查询目标音频设备描述符的采样率数组。 | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceChannelCounts](#oh_audiodevicedescriptor_getdevicechannelcounts) ([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, uint32_t \*\*channelCounts, uint32_t \*size) | 查询目标音频设备描述符的设备通道计数数组。 | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceDisplayName](#oh_audiodevicedescriptor_getdevicedisplayname) ([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, char \*\*displayName) | 查询目标音频设备描述符的显示名称。 | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceEncodingTypes](#oh_audiodevicedescriptor_getdeviceencodingtypes) ([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) \*\*encodingTypes, uint32_t \*size) | 查询目标音频设备描述符的编码类型数组。 | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager) ([OH_AudioRoutingManager](#oh_audioroutingmanager) \*\*audioRoutingManager) | 查询音频路由管理器句柄，该句柄应设置为路由相关函数中的第一个参数。 | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices) ([OH_AudioRoutingManager](#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioDevice_Flag](#oh_audiodevice_flag) deviceFlag, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*\*audioDeviceDescriptorArray) | 根据输入的deviceFlag查询可用的设备。 | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioRoutingManager_RegisterDeviceChangeCallback](#oh_audioroutingmanager_registerdevicechangecallback) ([OH_AudioRoutingManager](#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioDevice_Flag](#oh_audiodevice_flag) deviceFlag, [OH_AudioRoutingManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback) callback) | 注册音频路由管理器的设备更改回调。 | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioRoutingManager_UnregisterDeviceChangeCallback](#oh_audioroutingmanager_unregisterdevicechangecallback) ([OH_AudioRoutingManager](#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioRoutingManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback) callback) | 取消注册音频路由管理器的设备更改回调。 | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices) ([OH_AudioRoutingManager](#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*audioDeviceDescriptorArray) | 释放音频设备描述符数组对象。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_Release](#oh_audiocapturer_release)([OH_AudioCapturer](#oh_audiocapturer) \*capturer)                                                                                           | 释放输入音频流。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_Start](#oh_audiocapturer_start)([OH_AudioCapturer](#oh_audiocapturer) \*capturer)                                                                                               | 开始获取音频数据。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_Pause](#oh_audiocapturer_pause)([OH_AudioCapturer](#oh_audiocapturer) \*capturer)                                                                                               | 暂停输入音频流。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_Stop](#oh_audiocapturer_stop)([OH_AudioCapturer](#oh_audiocapturer) \*capturer)                                                                                                 | 停止输入音频流 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_Flush](#oh_audiocapturer_flush)([OH_AudioCapturer](#oh_audiocapturer) \*capturer)                                                                                               | 丢弃获取的音频数据。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetCurrentState](#oh_audiocapturer_getcurrentstate)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_State](#oh_audiostream_state) \*state)                    | 查询当前输入音频流状态。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetLatencyMode](#oh_audiocapturer_getlatencymode)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) \*latencyMode)    | 查询当前输入音频流时延模式。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetStreamId](#oh_audiocapturer_getstreamid)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, uint32_t \*streamId)                                                              | 查询当前输入音频流ID。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetSamplingRate](#oh_audiocapturer_getsamplingrate)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, int32_t \*rate)                                                           | 查询当前输入音频流采样率。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetChannelCount](#oh_audiocapturer_getchannelcount)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, int32_t \*channelCount)                                                   | 查询当前输入音频流通道数。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetSampleFormat](#oh_audiocapturer_getsampleformat)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) \*sampleFormat) | 查询当前输入音频流采样格式。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetEncodingType](#oh_audiocapturer_getencodingtype)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) \*encodingType) | 查询当前输入音频流编码类型。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetCapturerInfo](#oh_audiocapturer_getcapturerinfo)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_SourceType](#oh_audiostream_sourcetype) \*sourceType)     | 查询当前输入音频流工作场景类型。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetFrameSizeInCallback](#oh_audiocapturer_getframesizeincallback)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, int32_t \*frameSize)                                        | 在回调中查询帧大小，它是每次回调返回的缓冲区的固定长度。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetTimestamp](#oh_audiocapturer_gettimestamp)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, clockid_t clockId, int64_t \*framePosition, int64_t \*timestamp)                | 获取输入音频流时间戳和位置信息。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetFramesRead](#oh_audiocapturer_getframesread)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, int64_t \*frames)                                                             | 查询自创建流以来已读取的帧数。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetOverflowCount](#oh_audiocapturer_getoverflowcount) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer, uint32_t \*count) | 查询当前录制音频流过载数。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_Release](#oh_audiorenderer_release)([OH_AudioRenderer](#oh_audiorenderer) \*renderer)                                                                                           | 释放输出音频流。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_Start](#oh_audiorenderer_start)([OH_AudioRenderer](#oh_audiorenderer) \*renderer)                                                                                               | 开始输出音频数据。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_Pause](#oh_audiorenderer_pause)([OH_AudioRenderer](#oh_audiorenderer) \*renderer)                                                                                               | 暂停输出音频流。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_Stop](#oh_audiorenderer_stop)([OH_AudioRenderer](#oh_audiorenderer) \*renderer)                                                                                                 | 停止输出音频流。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_Flush](#oh_audiorenderer_flush)([OH_AudioRenderer](#oh_audiorenderer) \*renderer)                                                                                               | 丢弃已经写入的音频数据。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetCurrentState](#oh_audiorenderer_getcurrentstate)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_State](#oh_audiostream_state) \*state)                    | 查询当前输出音频流状态。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetSamplingRate](#oh_audiorenderer_getsamplingrate)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, int32_t \*rate)                                                           | 查询当前输出音频流采样率。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetStreamId](#oh_audiorenderer_getstreamid)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, uint32_t \*streamId)                                                              | 查询当前输出音频流ID。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetChannelCount](#oh_audiorenderer_getchannelcount)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, int32_t \*channelCount)                                                   | 查询当前输出音频流通道数。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetSampleFormat](#oh_audiorenderer_getsampleformat)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) \*sampleFormat) | 查询当前输出音频流采样格式。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetLatencyMode](#oh_audiorenderer_getlatencymode)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) \*latencyMode)    | 查询当前输出音频流时延模式。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetRendererInfo](#oh_audiorenderer_getrendererinfo)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_Usage](#oh_audiostream_usage) \*usage)                    | 查询当前输出音频流工作场景类型。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetEncodingType](#oh_audiorenderer_getencodingtype)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) \*encodingType) | 查询当前输出音频流编码类型。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetFramesWritten](#oh_audiorenderer_getframeswritten)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, int64_t \*frames)                                                       | 查询自创建流以来已写入的帧数。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetTimestamp](#oh_audiorenderer_gettimestamp)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, clockid_t clockId, int64_t \*framePosition, int64_t \*timestamp)                | 获取输出音频流时间戳和位置信息。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetFrameSizeInCallback](#oh_audiorenderer_getframesizeincallback)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, int32_t \*frameSize)                                        | 在回调中查询帧大小。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetSpeed](#oh_audiorenderer_getspeed) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, float \*speed) | 获取音频渲染速率。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetSpeed](#oh_audiorenderer_setspeed) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, float speed) | 设置音频渲染速率。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetMarkPosition](#oh_audiorenderer_setmarkposition) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, uint32_t samplePos, [OH_AudioRenderer_OnMarkReachedCallback](#oh_audiorenderer_onmarkreachedcallback) callback, void \*userData) | 在当前渲染器上设置标记位置。调用此函数将覆盖已设置的标记位置。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_CancelMark](#oh_audiorenderer_cancelmark) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | 取消由[OH_AudioRenderer_SetMarkPosition](#oh_audiorenderer_setmarkposition)设置的标记。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetVolume](#oh_audiorenderer_setvolume) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, float volume) | 设置当前音频流音量值。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetVolumeWithRamp](#oh_audiorenderer_setvolumewithramp) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, float volume, int32_t durationMs) | 在指定时间范围内使用渐变更改音量。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetVolume](#oh_audiorenderer_getvolume) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, float \*volume) | 获取当前音频流音量值。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetUnderflowCount](#oh_audiorenderer_getunderflowcount) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, uint32_t \*count) | 查询当前播放音频流欠载数。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetChannelLayout](#oh_audiorenderer_getchannellayout) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioChannelLayout](../apis-avcodec-kit/_core.md#oh_audiochannellayout-1) \*channelLayout) | 查询当前音频流声道布局。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetEffectMode](#oh_audiorenderer_geteffectmode) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_AudioEffectMode](#oh_audiostream_audioeffectmode) \*effectMode) | 查询当前音频流音效模式。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetEffectMode](#oh_audiorenderer_seteffectmode) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_AudioEffectMode](#oh_audiostream_audioeffectmode) effectMode) | 设置当前音频流音效模式。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*\*builder, [OH_AudioStream_Type](#oh_audiostream_type) type)                        | 创建一个输入或者输出类型的音频流构造器。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_Destroy](#oh_audiostreambuilder_destroy)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder)                                                                        | 销毁一个音频流构造器。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetSamplingRate](#oh_audiostreambuilder_setsamplingrate)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, int32_t rate)                                          | 设置音频流的采样率属性。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetChannelCount](#oh_audiostreambuilder_setchannelcount)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, int32_t channelCount)                                  | 设置音频流的通道数属性。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetSampleFormat](#oh_audiostreambuilder_setsampleformat)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) format) | 设置音频流的采样格式属性。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetEncodingType](#oh_audiostreambuilder_setencodingtype)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) encodingType) | 设置音频流的编码类型属性。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetLatencyMode](#oh_audiostreambuilder_setlatencymode)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) latencyMode) | 设置音频流的时延模式。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetChannelLayout](#oh_audiostreambuilder_setchannellayout) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioChannelLayout](../apis-avcodec-kit/_core.md#oh_audiochannellayout-1) channelLayout) | 设置音频流的声道布局。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetRendererInfo](#oh_audiostreambuilder_setrendererinfo)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_Usage](#oh_audiostream_usage) usage)   | 设置输出音频流的工作场景。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetCapturerInfo](#oh_audiostreambuilder_setcapturerinfo)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_SourceType](#oh_audiostream_sourcetype) sourceType) | 设置输入音频流的工作场景。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetRendererCallback](#oh_audiostreambuilder_setrenderercallback)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioRenderer_Callbacks](#oh_audiorenderer_callbacks) callbacks, void \*userData) | 设置输出音频流的回调。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetRendererOutputDeviceChangeCallback](#oh_audiostreambuilder_setrendereroutputdevicechangecallback) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioRenderer_OutputDeviceChangeCallback](#oh_audiorenderer_outputdevicechangecallback) callback, void \*userData) | 设置输出音频流设备变更的回调。 |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetCapturerCallback](#oh_audiostreambuilder_setcapturercallback)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioCapturer_Callbacks](#oh_audiocapturer_callbacks) callbacks, void \*userData) | 设置输入音频流的回调。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetWriteDataWithMetadataCallback](#oh_audiostreambuilder_setwritedatawithmetadatacallback) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioRenderer_WriteDataWithMetadataCallback](#oh_audiorenderer_writedatawithmetadatacallback) callback, void \*userData) | 设置同时写入音频数据和元数据的回调。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioRenderer](#oh_audiorenderer) \*\*audioRenderer) | 创建输出音频流实例。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioCapturer](#oh_audiocapturer) \*\*audioCapturer) | 创建输入音频流实例。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetFrameSizeInCallback](#oh_audiostreambuilder_setframesizeincallback)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, int32_t frameSize) | 用于播放时设置每次回调的帧长，帧长至少为音频硬件一次处理的数据大小，并且小于内部缓冲容量的一半。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetRendererInterruptMode](#oh_audiostreambuilder_setrendererinterruptmode) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioInterrupt_Mode](#oh_audiointerrupt_mode) mode) | 设置流客户端的中断模式。  | 


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


### OH_AudioDeviceDescriptor

```
typedef struct OH_AudioDeviceDescriptor OH_AudioDeviceDescriptor
```

**描述**

声明音频设备描述符。 

该实例用于获取更多音频设备详细信息属性。

**起始版本：** 12


### OH_AudioDeviceDescriptorArray

```
typedef struct OH_AudioDeviceDescriptorArray OH_AudioDeviceDescriptorArray
```

**描述**

声明音频设备描述符数组。

**起始版本：** 12


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


### OH_AudioRenderer_OnMarkReachedCallback

```
typedef void(* OH_AudioRenderer_OnMarkReachedCallback) (OH_AudioRenderer *renderer, uint32_t samplePos, void *userData)
```

**描述**

到达标记位置时回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| samplePos | 设置目标标记位置。  | 
| userData | 指向通过回调函数传递的应用数据指针。  | 


### OH_AudioRenderer_OutputDeviceChangeCallback

```
typedef void(* OH_AudioRenderer_OutputDeviceChangeCallback) (OH_AudioRenderer *renderer, void *userData, OH_AudioStream_DeviceChangeReason reason)
```

**描述**

输出音频流设备变更的回调函数。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 | 
| userData | 指向通过回调函数传递的应用数据指针。 | 
| reason | 流设备变更原因。 | 


### OH_AudioRenderer_WriteDataWithMetadataCallback

```
typedef int32_t(* OH_AudioRenderer_WriteDataWithMetadataCallback) (OH_AudioRenderer *renderer, void *userData, void *audioData, int32_t audioDataSize, void *metadata, int32_t metadataSize)
```

**描述**

该函数指针将指向用于同时写入音频数据和元数据的回调函数。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 | 
| userData | 指向通过回调函数传递的应用数据指针。 | 
| audioData | 指向用户写入的音频数据的指针。 | 
| audioDataSize | 用户写入的音频数据的数据长度，以字节为单位。 | 
| metadata | 指向用户写入的元数据的指针。 | 
| metadataSize | 用户写入的元数据的数据长度，以字节为单位。 | 

**返回：**

用户返回的回调函数的错误码。


### OH_AudioRoutingManager

```
typedef struct OH_AudioRoutingManager OH_AudioRoutingManager
```

**描述**

声明音频路由管理器，用于路由和设备相关功能的音频路由管理器的句柄。

**起始版本：** 12


### OH_AudioRoutingManager_OnDeviceChangedCallback

```
typedef int32_t(* OH_AudioRoutingManager_OnDeviceChangedCallback) (OH_AudioDevice_ChangeType type, OH_AudioDeviceDescriptorArray *audioDeviceDescriptorArray)
```

**描述**

此函数指针将指向用于返回更改的音频设备描述符的回调函数，可能返回多个音频设备描述符。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| type | 设备连接状态类型。 [OH_AudioDevice_ChangeType](#oh_audiodevice_changetype) 已连接或断开。 | 
| audioDeviceDescriptorArray | 音频设备描述符数组[OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md)。设置音频设备描述符值的指针变量，不要单独释放audioDeviceDescriptorArray指针， 而是调用[OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices)来释放DeviceDescriptor数组。 | 


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


### OH_AudioCommon_Result

```
enum OH_AudioCommon_Result
```

**描述**

音频错误码。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIOCOMMON_RESULT_SUCCESS | 操作成功。 | 
| AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM | 入参错误。 | 
| AUDIOCOMMON_RESULT_ERROR_NO_MEMORY | 无内存。 | 
| AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE | 非法状态。 | 
| AUDIOCOMMON_RESULT_ERROR_UNSUPPORTED | 操作不支持。 | 
| AUDIOCOMMON_RESULT_ERROR_TIMEOUT | 操作超时。 | 
| AUDIOCOMMON_RESULT_ERROR_STREAM_LIMIT | 达到系统可支持的最大数量。 | 
| AUDIOCOMMON_RESULT_ERROR_SYSTEM | 系统通用错误。 | 


### OH_AudioDevice_ChangeType

```
enum OH_AudioDevice_ChangeType
```

**描述**

定义音频设备更改类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_DEVICE_CHANGE_TYPE_CONNECT | 设备连接。 | 
| AUDIO_DEVICE_CHANGE_TYPE_DISCONNECT | 设备断开。 | 


### OH_AudioDevice_Flag

```
enum OH_AudioDevice_Flag
```

**描述**

定义音频设备标志。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_DEVICE_FLAG_NONE | 无设备。 | 
| AUDIO_DEVICE_FLAG_OUTPUT | 输出设备。 | 
| AUDIO_DEVICE_FLAG_INPUT | 输入设备。 | 
| AUDIO_DEVICE_FLAG_ALL | 所有设备。 | 


### OH_AudioDevice_Role

```
enum OH_AudioDevice_Role
```

**描述**

定义音频设备设备角色。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_DEVICE_ROLE_INPUT | 输入设备。 | 
| AUDIO_DEVICE_ROLE_OUTPUT | 输出设备。 | 


### OH_AudioDevice_Type

```
enum OH_AudioDevice_Type
```

**描述**

定义音频设备类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_DEVICE_TYPE_INVALID | 无效设备。 | 
| AUDIO_DEVICE_TYPE_EARPIECE | 内置听筒。 | 
| AUDIO_DEVICE_TYPE_SPEAKER | 内置扬声器。 | 
| AUDIO_DEVICE_TYPE_WIRED_HEADSET | 带话筒的耳机。 | 
| AUDIO_DEVICE_TYPE_WIRED_HEADPHONES | 无话筒的耳机。 | 
| AUDIO_DEVICE_TYPE_BLUETOOTH_SCO | 使用面向同步连接链路（SCO）的蓝牙设备。 | 
| AUDIO_DEVICE_TYPE_BLUETOOTH_A2DP | 使用高级音频分布模式（A2DP）的蓝牙设备。 | 
| AUDIO_DEVICE_TYPE_MIC | 内置麦克风。 | 
| AUDIO_DEVICE_TYPE_USB_HEADSET | USB音频耳机。 | 
| AUDIO_DEVICE_TYPE_DISPLAY_PORT | 显示端口（DisplayPort）设备。 | 
| AUDIO_DEVICE_TYPE_DEFAULT | 默认设备类型。 | 


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
| AUDIOSTREAM_INTERRUPT_SHARE | 共享类型，应用程序更改音频状态。 | 


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


### OH_AudioInterrupt_Mode

```
enum OH_AudioInterrupt_Mode
```

**描述**

定义音频中断模式。

通常用来设置音频中断模式。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIOSTREAM_INTERRUPT_MODE_SHARE  | 共享模式。 | 
| AUDIOSTREAM_INTERRUPT_MODE_INDEPENDENT  | 独立模式。| 


### OH_AudioStream_AudioEffectMode

```
enum OH_AudioStream_AudioEffectMode
```

**描述**

定义音效模式。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| EFFECT_NONE | 无音效模式。 | 
| EFFECT_DEFAULT | 默认音效模式。 | 


### OH_AudioStream_DeviceChangeReason

```
enum OH_AudioStream_DeviceChangeReason
```

**描述**

流设备变更原因。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| REASON_UNKNOWN | 未知原因。 | 
| REASON_NEW_DEVICE_AVAILABLE | 新设备可用。 | 
| REASON_OLD_DEVICE_UNAVAILABLE | 旧设备不可用。当报告此原因时，应用程序应考虑暂停音频播放。 | 
| REASON_OVERRODE | 用户或系统强制选择切换。 | 


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
| AUDIOSTREAM_ENCODING_TYPE_AUDIOVIVID  | AudioVivid编码。<br/>**起始版本：** 12 | 


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
| AUDIOSTREAM_LATENCY_MODE_FAST | 该模式代表一个低时延的音频流。 | 


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
| AUDIOSTREAM_SUCCESS | 操作成功 | 
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
| AUDIOSTREAM_SOURCE_TYPE_PLAYBACK_CAPTURE | 播放录音。 | 
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
| AUDIOSTREAM_STATE_NEW | 新创建时的状态。 | 
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
| AUDIOSTREAM_TYPE_RERNDERER | 该类型代表音频流是输出流。 | 
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
| AUDIOSTREAM_USAGE_VOICE_ASSISTANT | 语音助手。 | 
| AUDIOSTREAM_USAGE_ALARM | 闹钟。 | 
| AUDIOSTREAM_USAGE_VOICE_MESSAGE | 语音消息。 | 
| AUDIOSTREAM_USAGE_RINGTONE | 铃声。 | 
| AUDIOSTREAM_USAGE_NOTIFICATION | 通知。 | 
| AUDIOSTREAM_USAGE_ACCESSIBILITY | 无障碍。 | 
| AUDIOSTREAM_USAGE_MOVIE | 视频。 | 
| AUDIOSTREAM_USAGE_GAME | 游戏。 | 
| AUDIOSTREAM_USAGE_AUDIOBOOK | 有声读物。 | 
| AUDIOSTREAM_USAGE_NAVIGATION | 导航。 | 


## 函数说明


### OH_AudioCapturer_Flush()

```
OH_AudioStream_Result OH_AudioCapturer_Flush(OH_AudioCapturer *capturer)
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
OH_AudioStream_Result OH_AudioCapturer_GetCapturerInfo(OH_AudioCapturer *capturer, OH_AudioStream_SourceType *sourceType)
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


