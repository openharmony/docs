# OHAudio


## 概述

提供音频模块C接口定义。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_audio_common.h](native__audio__common_8h.md) | 声明音频公共基础数据结构。  | 
| [native_audio_device_base.h](native__audio__device__base_8h.md) | 定义音频设备参数的类型以及获取每个设备参数的接口。  | 
| [native_audio_manager.h](native__audio__manager_8h.md) | 声明音频管理相关的接口。  | 
| [native_audio_routing_manager.h](native__audio__routing__manager_8h.md) | 声明与音频路由管理器相关的接口。  | 
| [native_audio_session_manager.h](native__audio__session__manager_8h.md) | 声明音频会话管理相关的接口。  | 
| [native_audiocapturer.h](native__audiocapturer_8h.md) | 声明输入类型的音频流相关接口。  | 
| [native_audiorenderer.h](native__audiorenderer_8h.md) | 声明输出类型的音频流相关接口。  | 
| [native_audiostream_base.h](native__audiostream__base_8h.md) | 声明OHAudio基础的数据结构。  | 
| [native_audiostreambuilder.h](native__audiostreambuilder_8h.md) | 声明音频流构造器相关接口。  | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) | 声明音频设备描述符数组。  | 
| struct  [OH_AudioSession_Strategy](_o_h___audio_session___strategy.md) | 音频会话策略。  | 
| struct  [OH_AudioSession_DeactivatedEvent](_o_h___audio_session___deactivated_event.md) | 音频会话已停用事件。  | 
| struct  [OH_AudioRenderer_Callbacks_Struct](_o_h___audio_renderer___callbacks___struct.md) | 声明输出音频流的回调函数指针。  | 
| struct  [OH_AudioCapturer_Callbacks_Struct](_o_h___audio_capturer___callbacks___struct.md) | 声明输入音频流的回调函数指针。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) [OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) | 声明音频设备描述符。 该实例用于获取更多音频设备详细信息属性。  | 
| typedef struct [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) [OH_AudioDeviceDescriptorArray](#oh_audiodevicedescriptorarray) | 声明音频设备描述符数组。  | 
| typedef struct [OH_AudioManager](#oh_audiomanager) [OH_AudioManager](#oh_audiomanager) | 声明音频管理器。  | 
| typedef struct [OH_AudioRoutingManager](#oh_audioroutingmanager) [OH_AudioRoutingManager](#oh_audioroutingmanager) | 声明音频路由管理器，用于路由和设备相关功能的音频路由管理器的句柄。  | 
| typedef int32_t(\* [OH_AudioRoutingManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback))([OH_AudioDevice_ChangeType](#oh_audiodevice_changetype) type, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*audioDeviceDescriptorArray) | 此函数指针将指向用于返回更改的音频设备描述符的回调函数，可能返回多个音频设备描述符。  | 
| typedef void(\* [OH_AudioRoutingManager_OnDeviceBlockStatusCallback](#oh_audioroutingmanager_ondeviceblockstatuscallback)) ([OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*audioDeviceDescriptorArray, [OH_AudioDevice_BlockStatus](#oh_audiodevice_blockstatus) status, void \*userData) | 此函数指针将指向用于返回音频设备堵塞状态的回调函数，可能返回多个音频设备描述符。  | 
| typedef struct [OH_AudioSessionManager](#oh_audiosessionmanager) [OH_AudioSessionManager](#oh_audiosessionmanager) | 声明音频会话管理器。  | 
| typedef struct [OH_AudioSession_Strategy](_o_h___audio_session___strategy.md) [OH_AudioSession_Strategy](#oh_audiosession_strategy) | 音频会话策略。  | 
| typedef struct [OH_AudioSession_DeactivatedEvent](_o_h___audio_session___deactivated_event.md) [OH_AudioSession_DeactivatedEvent](#oh_audiosession_deactivatedevent) | 音频会话已停用事件。  | 
| typedef int32_t(\* [OH_AudioSession_DeactivatedCallback](#oh_audiosession_deactivatedcallback))([OH_AudioSession_DeactivatedEvent](_o_h___audio_session___deactivated_event.md) event) | 这个函数指针将指向用于监听音频会话停用事件的回调函数。  | 
| typedef struct OH_AudioStreamBuilderStruct [OH_AudioStreamBuilder](#oh_audiostreambuilder) | 声明音频流的构造器。  | 
| typedef struct OH_AudioRendererStruct [OH_AudioRenderer](#oh_audiorenderer) | 声明输出音频流。  | 
| typedef struct OH_AudioCapturerStruct [OH_AudioCapturer](#oh_audiocapturer) | 声明输入音频流。  | 
| typedef struct [OH_AudioRenderer_Callbacks_Struct](_o_h___audio_renderer___callbacks___struct.md) [OH_AudioRenderer_Callbacks](#oh_audiorenderer_callbacks) | 声明输出音频流的回调函数指针。  | 
| typedef struct [OH_AudioCapturer_Callbacks_Struct](_o_h___audio_capturer___callbacks___struct.md) [OH_AudioCapturer_Callbacks](#oh_audiocapturer_callbacks) | 声明输入音频流的回调函数指针。  | 
| typedef void(\* [OH_AudioRenderer_OutputDeviceChangeCallback](#oh_audiorenderer_outputdevicechangecallback))([OH_AudioRenderer](#oh_audiorenderer) \*renderer, void \*userData, [OH_AudioStream_DeviceChangeReason](#oh_audiostream_devicechangereason) reason) | 输出音频流设备变更的回调函数。  | 
| typedef void(\* [OH_AudioRenderer_OnMarkReachedCallback](#oh_audiorenderer_onmarkreachedcallback))([OH_AudioRenderer](#oh_audiorenderer) \*renderer, uint32_t samplePos, void \*userData) | 到达标记位置时回调。  | 
| typedef int32_t(\* [OH_AudioRenderer_WriteDataWithMetadataCallback](#oh_audiorenderer_writedatawithmetadatacallback))([OH_AudioRenderer](#oh_audiorenderer) \*renderer, void \*userData, void \*audioData, int32_t audioDataSize, void \*metadata, int32_t metadataSize) | 该函数指针将指向用于同时写入音频数据和元数据的回调函数。  | 
| typedef [OH_AudioData_Callback_Result](#oh_audiodata_callback_result)(\* [OH_AudioRenderer_OnWriteDataCallback](#oh_audiorenderer_onwritedatacallback))([OH_AudioRenderer](#oh_audiorenderer) \*renderer, void \*userData, void \*audioData, int32_t audioDataSize) | 该函数指针将指向用于写入音频数据的回调函数。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioCommon_Result](#oh_audiocommon_result) {<br/>AUDIOCOMMON_RESULT_SUCCESS = 0,<br/>AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM = 6800101,<br/>AUDIOCOMMON_RESULT_ERROR_NO_MEMORY = 6800102,<br/>AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE = 6800103,<br/>AUDIOCOMMON_RESULT_ERROR_UNSUPPORTED = 6800104,<br/>AUDIOCOMMON_RESULT_ERROR_TIMEOUT = 6800105,<br/>AUDIOCOMMON_RESULT_ERROR_STREAM_LIMIT = 6800201,<br/>AUDIOCOMMON_RESULT_ERROR_SYSTEM = 6800301<br/>} | 音频错误码。 | 
| [OH_AudioScene](#oh_audioscene) { <br/>AUDIO_SCENE_DEFAULT = 0, <br/>AUDIO_SCENE_RINGING = 1, <br/>AUDIO_SCENE_PHONE_CALL = 2, <br/>AUDIO_SCENE_VOICE_CHAT = 3 } | 定义音频场景。  | 
| [OH_AudioDevice_ChangeType](#oh_audiodevice_changetype) {<br/>AUDIO_DEVICE_CHANGE_TYPE_CONNECT = 0,<br/>AUDIO_DEVICE_CHANGE_TYPE_DISCONNECT = 1<br/>} | 定义音频设备更改类型。 | 
| [OH_AudioDevice_Role](#oh_audiodevice_role) {<br/>AUDIO_DEVICE_ROLE_INPUT = 1,<br/>AUDIO_DEVICE_ROLE_OUTPUT = 2<br/>} | 定义音频设备角色。 | 
| [OH_AudioDevice_Type](#oh_audiodevice_type) {<br/>AUDIO_DEVICE_TYPE_INVALID = 0,<br/>AUDIO_DEVICE_TYPE_EARPIECE = 1,<br/>AUDIO_DEVICE_TYPE_SPEAKER = 2,<br/>AUDIO_DEVICE_TYPE_WIRED_HEADSET = 3,<br/>AUDIO_DEVICE_TYPE_WIRED_HEADPHONES = 4,<br/>AUDIO_DEVICE_TYPE_BLUETOOTH_SCO = 7,<br/>AUDIO_DEVICE_TYPE_BLUETOOTH_A2DP = 8,<br/>AUDIO_DEVICE_TYPE_MIC = 15,<br/>AUDIO_DEVICE_TYPE_USB_HEADSET = 22,<br/>AUDIO_DEVICE_TYPE_DISPLAY_PORT = 23,<br/>AUDIO_DEVICE_TYPE_REMOTE_CAST = 24,<br/>AUDIO_DEVICE_TYPE_DEFAULT = 1000<br/>} | 定义音频设备类型。 | 
| [OH_AudioDevice_Flag](#oh_audiodevice_flag) {<br/>AUDIO_DEVICE_FLAG_NONE = 0,<br/>AUDIO_DEVICE_FLAG_OUTPUT = 1,<br/>AUDIO_DEVICE_FLAG_INPUT = 2,<br/>AUDIO_DEVICE_FLAG_ALL = 3<br/>} | 定义音频设备标志。 | 
| [OH_AudioDevice_Usage](#oh_audiodevice_usage) {<br/>AUDIO_DEVICE_USAGE_MEDIA_OUTPUT = 1, <br/>AUDIO_DEVICE_USAGE_MEDIA_INPUT = 2, <br/>AUDIO_DEVICE_USAGE_MEDIA_ALL = 3, <br/>AUDIO_DEVICE_USAGE_CALL_OUTPUT = 4,<br/>AUDIO_DEVICE_USAGE_CALL_INPUT = 8, <br/>AUDIO_DEVICE_USAGE_CALL_ALL = 12<br/>} | 定义可获取的设备种类。  | 
| [OH_AudioDevice_BlockStatus](#oh_audiodevice_blockstatus) { <br/>AUDIO_DEVICE_UNBLOCKED = 0, <br/>AUDIO_DEVICE_BLOCKED = 1 } | 声明音频设备的堵塞状态。默认情况下，音频设备被视为未堵塞。 | 
| [OH_AudioSession_ConcurrencyMode](#oh_audiosession_concurrencymode) { <br/>CONCURRENCY_DEFAULT = 0, <br/>CONCURRENCY_MIX_WITH_OTHERS = 1, <br/>CONCURRENCY_DUCK_OTHERS = 2, <br/>CONCURRENCY_PAUSE_OTHERS = 3 } | 音频并发模式。  | 
| [OH_AudioSession_DeactivatedReason](#oh_audiosession_deactivatedreason) { <br/>DEACTIVATED_LOWER_PRIORITY = 0, <br/>DEACTIVATED_TIMEOUT = 1 } | 音频会话停用原因。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) {<br/>AUDIOSTREAM_SUCCESS = 0,<br/>AUDIOSTREAM_ERROR_INVALID_PARAM = 1,<br/>AUDIOSTREAM_ERROR_ILLEGAL_STATE = 2,<br/>AUDIOSTREAM_ERROR_SYSTEM = 3<br/>} | 音频错误码。 | 
| [OH_AudioStream_Type](#oh_audiostream_type) {<br/>AUDIOSTREAM_TYPE_RENDERER = 1,<br/>AUDIOSTREAM_TYPE_CAPTURER = 2<br/>} | 音频流类型。 | 
| [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) {<br/>AUDIOSTREAM_SAMPLE_U8 = 0,<br/>AUDIOSTREAM_SAMPLE_S16LE = 1,<br/>AUDIOSTREAM_SAMPLE_S24LE = 2,<br/>AUDIOSTREAM_SAMPLE_S32LE = 3<br/>} | 定义音频流采样格式。 | 
| [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) { <br/>AUDIOSTREAM_ENCODING_TYPE_RAW = 0, <br/>AUDIOSTREAM_ENCODING_TYPE_AUDIOVIVID = 1 <br/>} | 定义音频流编码类型。  | 
| [OH_AudioStream_Usage](#oh_audiostream_usage) {<br/>AUDIOSTREAM_USAGE_UNKNOWN = 0,<br/>AUDIOSTREAM_USAGE_MUSIC = 1,<br/>AUDIOSTREAM_USAGE_VOICE_COMMUNICATION = 2,<br/>AUDIOSTREAM_USAGE_VOICE_ASSISTANT = 3,<br/>AUDIOSTREAM_USAGE_ALARM = 4,<br/>AUDIOSTREAM_USAGE_VOICE_MESSAGE = 5,<br/>AUDIOSTREAM_USAGE_RINGTONE = 6,<br/>AUDIOSTREAM_USAGE_NOTIFICATION = 7,<br/>AUDIOSTREAM_USAGE_ACCESSIBILITY = 8,<br/>AUDIOSTREAM_USAGE_MOVIE = 10,<br/>AUDIOSTREAM_USAGE_GAME = 11,<br/>AUDIOSTREAM_USAGE_AUDIOBOOK = 12,<br/>AUDIOSTREAM_USAGE_NAVIGATION = 13,<br/>AUDIOSTREAM_USAGE_VIDEO_COMMUNICATION = 17<br/>} | 定义音频流使用场景。 | 
| [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) {<br/>AUDIOSTREAM_LATENCY_MODE_NORMAL = 0,<br/>AUDIOSTREAM_LATENCY_MODE_FAST = 1<br/>} | 定义音频时延模式。 | 
| [OH_AudioStream_State](#oh_audiostream_state) {<br/>AUDIOSTREAM_STATE_INVALID = -1,<br/>AUDIOSTREAM_STATE_NEW = 0,<br/>AUDIOSTREAM_STATE_PREPARED = 1,<br/>AUDIOSTREAM_STATE_RUNNING = 2,<br/>AUDIOSTREAM_STATE_STOPPED = 3,<br/>AUDIOSTREAM_STATE_RELEASED = 4,<br/>AUDIOSTREAM_STATE_PAUSED = 5<br/>} | 定义音频流的状态。 | 
| [OH_AudioStream_SourceType](#oh_audiostream_sourcetype) {<br/>AUDIOSTREAM_SOURCE_TYPE_INVALID = -1,<br/>AUDIOSTREAM_SOURCE_TYPE_MIC = 0,<br/>AUDIOSTREAM_SOURCE_TYPE_VOICE_RECOGNITION = 1,<br/>AUDIOSTREAM_SOURCE_TYPE_PLAYBACK_CAPTURE = 2,<br/>AUDIOSTREAM_SOURCE_TYPE_VOICE_COMMUNICATION = 7,<br/>AUDIOSTREAM_SOURCE_TYPE_CAMCORDER = 13<br/>} | 定义音频流使用场景。 | 
| [OH_AudioStream_Event](#oh_audiostream_event) {<br/>AUDIOSTREAM_EVENT_ROUTING_CHANGED = 0<br/>} | 定义音频事件。 | 
| [OH_AudioInterrupt_ForceType](#oh_audiointerrupt_forcetype) {<br/>AUDIOSTREAM_INTERRUPT_FORCE = 0,<br/>AUDIOSTREAM_INTERRUPT_SHARE = 1<br/>} | 定义音频中断类型。 | 
| [OH_AudioInterrupt_Hint](#oh_audiointerrupt_hint) {<br/>AUDIOSTREAM_INTERRUPT_HINT_NONE = 0,<br/>AUDIOSTREAM_INTERRUPT_HINT_RESUME = 1,<br/>AUDIOSTREAM_INTERRUPT_HINT_PAUSE = 2,<br/>AUDIOSTREAM_INTERRUPT_HINT_STOP = 3,<br/>AUDIOSTREAM_INTERRUPT_HINT_DUCK = 4,<br/>AUDIOSTREAM_INTERRUPT_HINT_UNDUCK = 5<br/>} | 定义音频中断提示类型。 | 
| [OH_AudioInterrupt_Mode](#oh_audiointerrupt_mode) {<br/> AUDIOSTREAM_INTERRUPT_MODE_SHARE = 0, <br/>AUDIOSTREAM_INTERRUPT_MODE_INDEPENDENT = 1 <br/>} | 定义音频中断模式。  | 
| [OH_AudioStream_AudioEffectMode](#oh_audiostream_audioeffectmode) { <br/>EFFECT_NONE = 0, <br/>EFFECT_DEFAULT = 1 <br/>} | 定义音效模式。  | 
| [OH_AudioStream_DeviceChangeReason](#oh_audiostream_devicechangereason) {<br/>REASON_UNKNOWN = 0,<br/>REASON_NEW_DEVICE_AVAILABLE = 1,<br/>REASON_OLD_DEVICE_UNAVAILABLE = 2,<br/>REASON_OVERRODE = 3<br/>} | 流设备变更原因。 | 
| [OH_AudioStream_PrivacyType](#oh_audiostream_privacytype) { <br/>AUDIO_STREAM_PRIVACY_TYPE_PUBLIC = 0, <br/>AUDIO_STREAM_PRIVACY_TYPE_PRIVATE = 1 <br/>} | 用于标识对应播放音频流是否支持被其他应用录制。  | 
| [OH_AudioData_Callback_Result](#oh_audiodata_callback_result) { <br/>AUDIO_DATA_CALLBACK_RESULT_INVALID = -1, <br/>AUDIO_DATA_CALLBACK_RESULT_VALID = 0 <br/>} | 定义音频数据回调结果。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceRole](#oh_audiodevicedescriptor_getdevicerole)([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, [OH_AudioDevice_Role](#oh_audiodevice_role) \*deviceRole) | 查询目标音频设备描述符的设备角色。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceType](#oh_audiodevicedescriptor_getdevicetype)([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, [OH_AudioDevice_Type](#oh_audiodevice_type) \*deviceType) | 查询目标音频设备描述符的设备类型。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceId](#oh_audiodevicedescriptor_getdeviceid)([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, uint32_t \*id) | 查询目标音频设备描述符的设备id。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceName](#oh_audiodevicedescriptor_getdevicename)([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, char \*\*name) | 查询目标音频设备描述符的设备名称。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceAddress](#oh_audiodevicedescriptor_getdeviceaddress)([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, char \*\*address) | 查询目标音频设备描述符的设备地址。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceSampleRates](#oh_audiodevicedescriptor_getdevicesamplerates)([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, uint32_t \*\*sampleRates, uint32_t \*size) | 查询目标音频设备描述符的采样率数组。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceChannelCounts](#oh_audiodevicedescriptor_getdevicechannelcounts)([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, uint32_t \*\*channelCounts, uint32_t \*size) | 查询目标音频设备描述符的设备通道计数数组。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceDisplayName](#oh_audiodevicedescriptor_getdevicedisplayname)([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, char \*\*displayName) | 查询目标音频设备描述符的显示名称。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceEncodingTypes](#oh_audiodevicedescriptor_getdeviceencodingtypes)([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) \*\*encodingTypes, uint32_t \*size) | 查询目标音频设备描述符的编码类型数组。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_GetAudioManager](#oh_getaudiomanager)([OH_AudioManager](#oh_audiomanager) \*\*audioManager) | 获取音频管理器。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_GetAudioScene](#oh_getaudioscene)([OH_AudioManager](#oh_audiomanager) \*manager, [OH_AudioScene](#oh_audioscene) \*scene) | 获取音频场景模式。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager)([OH_AudioRoutingManager](#oh_audioroutingmanager) \*\*audioRoutingManager) | 查询音频路由管理器句柄，该句柄应设置为路由相关函数中的第一个参数。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices)([OH_AudioRoutingManager](#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioDevice_Flag](#oh_audiodevice_flag) deviceFlag, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*\*audioDeviceDescriptorArray) | 根据输入的deviceFlag查询可用的设备。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioRoutingManager_GetAvailableDevices](#oh_audioroutingmanager_getavailabledevices)([OH_AudioRoutingManager](#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioDevice_Usage](#oh_audiodevice_usage) deviceUsage, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*\*audioDeviceDescriptorArray) | 获取音频可选设备列表。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioRoutingManager_GetPreferredOutputDevice](#oh_audioroutingmanager_getpreferredoutputdevice)([OH_AudioRoutingManager](#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioStream_Usage](#oh_audiostream_usage) streamUsage, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*\*audioDeviceDescriptorArray) | 根据音频输出流的使用场景，获取优先级最高的输出设备。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioRoutingManager_GetPreferredInputDevice](#oh_audioroutingmanager_getpreferredinputdevice)([OH_AudioRoutingManager](#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioStream_SourceType](#oh_audiostream_sourcetype) sourceType, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*\*audioDeviceDescriptorArray) | 根据音频输入流的使用场景，获取优先级最高的输入设备。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioRoutingManager_RegisterDeviceChangeCallback](#oh_audioroutingmanager_registerdevicechangecallback)([OH_AudioRoutingManager](#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioDevice_Flag](#oh_audiodevice_flag) deviceFlag, [OH_AudioRoutingManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback) callback) | 注册音频路由管理器的设备更改回调。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioRoutingManager_UnregisterDeviceChangeCallback](#oh_audioroutingmanager_unregisterdevicechangecallback)([OH_AudioRoutingManager](#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioRoutingManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback) callback) | 取消注册音频路由管理器的设备更改回调。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices)([OH_AudioRoutingManager](#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*audioDeviceDescriptorArray) | 释放音频设备描述符数组对象。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioRoutingManager_IsMicBlockDetectionSupported](#oh_audioroutingmanager_ismicblockdetectionsupported) ([OH_AudioRoutingManager](#oh_audioroutingmanager) \*audioRoutingManager, bool \*supported) | 查询当前设备是否支持麦克风堵塞状态检测。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioRoutingManager_SetMicBlockStatusCallback](#oh_audioroutingmanager_setmicblockstatuscallback) ([OH_AudioRoutingManager](#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioRoutingManager_OnDeviceBlockStatusCallback](#oh_audioroutingmanager_ondeviceblockstatuscallback) callback, void \*userData) | 设置麦克风是否堵塞状态回调。在使用此功能之前，用户应查询当前设备是否支持检测，应用只有在使用麦克风录音时， 并且所使用的麦克风的堵塞状态发生改变，才会收到回调，目前此检测功能仅支持麦克风位于本地设备上。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager)([OH_AudioSessionManager](#oh_audiosessionmanager) \*\*audioSessionManager) | 获取音频会话管理器。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioSessionManager_ActivateAudioSession](#oh_audiosessionmanager_activateaudiosession)([OH_AudioSessionManager](#oh_audiosessionmanager) \*audioSessionManager, const [OH_AudioSession_Strategy](_o_h___audio_session___strategy.md) \*strategy) | 激活音频会话。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioSessionManager_DeactivateAudioSession](#oh_audiosessionmanager_deactivateaudiosession)([OH_AudioSessionManager](#oh_audiosessionmanager) \*audioSessionManager) | 停用音频会话。  | 
| bool [OH_AudioSessionManager_IsAudioSessionActivated](#oh_audiosessionmanager_isaudiosessionactivated)([OH_AudioSessionManager](#oh_audiosessionmanager) \*audioSessionManager) | 检查音频会话是否已激活。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioSessionManager_RegisterSessionDeactivatedCallback](#oh_audiosessionmanager_registersessiondeactivatedcallback)([OH_AudioSessionManager](#oh_audiosessionmanager) \*audioSessionManager, [OH_AudioSession_DeactivatedCallback](#oh_audiosession_deactivatedcallback) callback) | 注册音频会话停用事件回调。  | 
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioSessionManager_UnregisterSessionDeactivatedCallback](#oh_audiosessionmanager_unregistersessiondeactivatedcallback)([OH_AudioSessionManager](#oh_audiosessionmanager) \*audioSessionManager, [OH_AudioSession_DeactivatedCallback](#oh_audiosession_deactivatedcallback) callback) | 取消注册音频会话停用事件回调。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_Release](#oh_audiocapturer_release)([OH_AudioCapturer](#oh_audiocapturer) \*capturer) | 释放输入音频流。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_Start](#oh_audiocapturer_start)([OH_AudioCapturer](#oh_audiocapturer) \*capturer) | 开始获取音频数据。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_Pause](#oh_audiocapturer_pause)([OH_AudioCapturer](#oh_audiocapturer) \*capturer) | 暂停输入音频流。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_Stop](#oh_audiocapturer_stop)([OH_AudioCapturer](#oh_audiocapturer) \*capturer) | 停止输入音频流。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_Flush](#oh_audiocapturer_flush)([OH_AudioCapturer](#oh_audiocapturer) \*capturer) | 丢弃获取的音频数据。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetCurrentState](#oh_audiocapturer_getcurrentstate)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_State](#oh_audiostream_state) \*state) | 查询当前输入音频流状态。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetLatencyMode](#oh_audiocapturer_getlatencymode)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) \*latencyMode) | 查询当前输入音频流时延模式。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetStreamId](#oh_audiocapturer_getstreamid)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, uint32_t \*streamId) | 查询当前输入音频流ID。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetSamplingRate](#oh_audiocapturer_getsamplingrate)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, int32_t \*rate) | 查询当前输入音频流采样率。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetChannelCount](#oh_audiocapturer_getchannelcount)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, int32_t \*channelCount) | 查询当前输入音频流通道数。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetSampleFormat](#oh_audiocapturer_getsampleformat)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) \*sampleFormat) | 查询当前输入音频流采样格式。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetEncodingType](#oh_audiocapturer_getencodingtype)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) \*encodingType) | 查询当前输入音频流编码类型。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetCapturerInfo](#oh_audiocapturer_getcapturerinfo)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_SourceType](#oh_audiostream_sourcetype) \*sourceType) | 查询当前输入音频流工作场景类型。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetFrameSizeInCallback](#oh_audiocapturer_getframesizeincallback)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, int32_t \*frameSize) | 在回调中查询帧大小，它是每次回调返回的缓冲区的固定长度。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetTimestamp](#oh_audiocapturer_gettimestamp)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, clockid_t clockId, int64_t \*framePosition, int64_t \*timestamp) | 获取输入音频流时间戳和位置信息。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetFramesRead](#oh_audiocapturer_getframesread)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, int64_t \*frames) | 查询自创建流以来已读取的帧数。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetOverflowCount](#oh_audiocapturer_getoverflowcount)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, uint32_t \*count) | 查询当前录制音频流过载数。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_Release](#oh_audiorenderer_release)([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | 释放输出音频流。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_Start](#oh_audiorenderer_start)([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | 开始输出音频数据。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_Pause](#oh_audiorenderer_pause)([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | 暂停输出音频流。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_Stop](#oh_audiorenderer_stop)([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | 停止输出音频流。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_Flush](#oh_audiorenderer_flush)([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | 丢弃已经写入的音频数据。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetCurrentState](#oh_audiorenderer_getcurrentstate)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_State](#oh_audiostream_state) \*state) | 查询当前输出音频流状态。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetSamplingRate](#oh_audiorenderer_getsamplingrate)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, int32_t \*rate) | 查询当前输出音频流采样率。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetStreamId](#oh_audiorenderer_getstreamid)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, uint32_t \*streamId) | 查询当前输出音频流ID。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetChannelCount](#oh_audiorenderer_getchannelcount)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, int32_t \*channelCount) | 查询当前输出音频流通道数。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetSampleFormat](#oh_audiorenderer_getsampleformat)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) \*sampleFormat) | 查询当前输出音频流采样格式。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetLatencyMode](#oh_audiorenderer_getlatencymode)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) \*latencyMode) | 查询当前输出音频流时延模式。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetRendererInfo](#oh_audiorenderer_getrendererinfo)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_Usage](#oh_audiostream_usage) \*usage) | 查询当前输出音频流工作场景类型。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetEncodingType](#oh_audiorenderer_getencodingtype)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) \*encodingType) | 查询当前输出音频流编码类型。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetFramesWritten](#oh_audiorenderer_getframeswritten)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, int64_t \*frames) | 查询自创建流以来已写入的帧数。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetTimestamp](#oh_audiorenderer_gettimestamp)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, clockid_t clockId, int64_t \*framePosition, int64_t \*timestamp) | 获取输出音频流时间戳和位置信息。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetFrameSizeInCallback](#oh_audiorenderer_getframesizeincallback)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, int32_t \*frameSize) | 在回调中查询帧大小。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetSpeed](#oh_audiorenderer_getspeed)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, float \*speed) | 获取音频渲染速率。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetSpeed](#oh_audiorenderer_setspeed)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, float speed) | 设置音频渲染速率。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetMarkPosition](#oh_audiorenderer_setmarkposition)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, uint32_t samplePos, [OH_AudioRenderer_OnMarkReachedCallback](#oh_audiorenderer_onmarkreachedcallback) callback, void \*userData) | 在当前渲染器上设置标记位置。调用此函数将覆盖已设置的标记位置。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_CancelMark](#oh_audiorenderer_cancelmark)([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | 取消由[OH_AudioRenderer_SetMarkPosition](#oh_audiorenderer_setmarkposition)设置的标记。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetVolume](#oh_audiorenderer_setvolume)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, float volume) | 设置当前音频流音量值。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetVolumeWithRamp](#oh_audiorenderer_setvolumewithramp)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, float volume, int32_t durationMs) | 在指定时间范围内使用渐变更改音量。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetVolume](#oh_audiorenderer_getvolume)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, float \*volume) | 获取当前音频流音量值。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetUnderflowCount](#oh_audiorenderer_getunderflowcount)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, uint32_t \*count) | 查询当前播放音频流欠载数。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetChannelLayout](#oh_audiorenderer_getchannellayout)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioChannelLayout](../apis-avcodec-kit/_core.md#oh_audiochannellayout-1) \*channelLayout) | 查询当前音频流声道布局。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetEffectMode](#oh_audiorenderer_geteffectmode)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_AudioEffectMode](#oh_audiostream_audioeffectmode) \*effectMode) | 查询当前音频流音效模式。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetEffectMode](#oh_audiorenderer_seteffectmode)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_AudioEffectMode](#oh_audiostream_audioeffectmode) effectMode) | 设置当前音频流音效模式。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetRendererPrivacy](#oh_audiorenderer_getrendererprivacy)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_PrivacyType](#oh_audiostream_privacytype) \*privacy) | 查询当前播放音频流是否会被其它应用录制。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetSilentModeAndMixWithOthers](#oh_audiorenderer_setsilentmodeandmixwithothers)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, bool on) | 设置静音并发播放模式。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetSilentModeAndMixWithOthers](#oh_audiorenderer_getsilentmodeandmixwithothers)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, bool \*on) | 查询当前音频流是否开启静音并发播放。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetDefaultOutputDevice](#oh_audiorenderer_setdefaultoutputdevice)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioDevice_Type](#oh_audiodevice_type) deviceType) | 设置默认本机内置发声设备。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*\*builder, [OH_AudioStream_Type](#oh_audiostream_type) type) | 创建一个输入或者输出类型的音频流构造器。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_Destroy](#oh_audiostreambuilder_destroy)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder) | 销毁一个音频流构造器。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetSamplingRate](#oh_audiostreambuilder_setsamplingrate)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, int32_t rate) | 设置音频流的采样率属性。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetChannelCount](#oh_audiostreambuilder_setchannelcount)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, int32_t channelCount) | 设置音频流的通道数属性。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetSampleFormat](#oh_audiostreambuilder_setsampleformat)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) format) | 设置音频流的采样格式属性。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetEncodingType](#oh_audiostreambuilder_setencodingtype)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) encodingType) | 设置音频流的编码类型属性。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetLatencyMode](#oh_audiostreambuilder_setlatencymode)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) latencyMode) | 设置音频流的时延模式。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetChannelLayout](#oh_audiostreambuilder_setchannellayout)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioChannelLayout](../apis-avcodec-kit/_core.md#oh_audiochannellayout-1) channelLayout) | 设置音频流的声道布局。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetRendererInfo](#oh_audiostreambuilder_setrendererinfo)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_Usage](#oh_audiostream_usage) usage) | 设置输出音频流的工作场景。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetCapturerInfo](#oh_audiostreambuilder_setcapturerinfo)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_SourceType](#oh_audiostream_sourcetype) sourceType) | 设置输入音频流的工作场景。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetRendererCallback](#oh_audiostreambuilder_setrenderercallback)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioRenderer_Callbacks](#oh_audiorenderer_callbacks) callbacks, void \*userData) | 设置输出音频流的回调。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetRendererOutputDeviceChangeCallback](#oh_audiostreambuilder_setrendereroutputdevicechangecallback)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioRenderer_OutputDeviceChangeCallback](#oh_audiorenderer_outputdevicechangecallback) callback, void \*userData) | 设置输出音频流设备变更的回调。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetRendererPrivacy](#oh_audiostreambuilder_setrendererprivacy)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_PrivacyType](#oh_audiostream_privacytype) privacy) | 设置当前播放音频流是否会被其它应用录制。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetCapturerCallback](#oh_audiostreambuilder_setcapturercallback)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioCapturer_Callbacks](#oh_audiocapturer_callbacks) callbacks, void \*userData) | 设置输入音频流的回调。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetWriteDataWithMetadataCallback](#oh_audiostreambuilder_setwritedatawithmetadatacallback)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioRenderer_WriteDataWithMetadataCallback](#oh_audiorenderer_writedatawithmetadatacallback) callback, void \*userData) | 设置同时写入音频数据和元数据的回调。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioRenderer](#oh_audiorenderer) \*\*audioRenderer) | 创建输出音频流实例。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioCapturer](#oh_audiocapturer) \*\*audioCapturer) | 创建输入音频流实例。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetFrameSizeInCallback](#oh_audiostreambuilder_setframesizeincallback)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, int32_t frameSize) | 用于播放时设置每次回调的帧长，帧长至少为音频硬件一次处理的数据大小，并且小于内部缓冲容量的一半。  | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetRendererInterruptMode](#oh_audiostreambuilder_setrendererinterruptmode)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioInterrupt_Mode](#oh_audiointerrupt_mode) mode) | 设置流客户端的中断模式。 | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetRendererWriteDataCallback](#oh_audiostreambuilder_setrendererwritedatacallback)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioRenderer_OnWriteDataCallback](#oh_audiorenderer_onwritedatacallback) callback, void \*userData) | 设置写入音频数据的回调。  | 


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


### OH_AudioManager

```
typedef struct OH_AudioManager OH_AudioManager
```
**描述**
声明音频管理器。

用于管理音频管理相关功能。

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
typedef void(* OH_AudioRenderer_OnMarkReachedCallback)(OH_AudioRenderer *renderer, uint32_t samplePos, void *userData)
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


### OH_AudioRenderer_OnWriteDataCallback

```
typedef OH_AudioData_Callback_Result(* OH_AudioRenderer_OnWriteDataCallback)(OH_AudioRenderer *renderer, void *userData, void *audioData, int32_t audioDataSize)
```
**描述**
该函数指针将指向用于写入音频数据的回调函数。

该函数类似于 [OH_AudioRenderer_Callbacks_Struct.OH_AudioRenderer_OnWriteData](_o_h___audio_renderer___callbacks___struct.md#oh_audiorenderer_onwritedata) 函数指针。但具有返回值，用于标识音频数据回调结果。 该函数的返回结果表示填充到缓冲区的数据是否有效。如果结果无效，用户填写的数据将不被播放。回调函数结束后，音频服务会把audioData指针数据放入队列里等待播放，因此请勿在回调外再次更改audioData指向的数据, 且务必保证往audioData填满audioDataSize长度的待播放数据, 否则会导致音频服务播放杂音。参数audioDataSize可以通过[OH_AudioStreamBuilder_SetFrameSizeInCallBack()](#OH_AudioStreamBuilder_SetFrameSizeInCallback)设置。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| userData | 指向通过回调函数传递的应用数据指针。  | 
| audioData | 指向用户写入的音频数据的指针。  | 
| audioDataSize | 用户写入的音频数据的数据长度，以字节为单位。  | 

**返回：**

函数返回值[OH_AudioData_Callback_Result](#oh_audiodata_callback_result)：

AUDIO_DATA_CALLBACK_RESULT_INVALID：音频数据回调结果无效，且音频数据不播放。

AUDIO_DATA_CALLBACK_RESULT_VALID：音频数据回调结果有效，将播放音频数据。

**参见：**

[OH_AudioRenderer_Callbacks_Struct.OH_AudioRenderer_OnWriteData](_o_h___audio_renderer___callbacks___struct.md#oh_audiorenderer_onwritedata)


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
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| userData | 指向通过回调函数传递的应用数据指针。  | 
| reason | 流设备变更原因。  | 


### OH_AudioRenderer_WriteDataWithMetadataCallback

```
typedef int32_t(* OH_AudioRenderer_WriteDataWithMetadataCallback)(OH_AudioRenderer *renderer, void *userData, void *audioData, int32_t audioDataSize, void *metadata, int32_t metadataSize)
```
**描述**
该函数指针将指向用于同时写入音频数据和元数据的回调函数。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| userData | 指向通过回调函数传递的应用数据指针。  | 
| audioData | 指向用户写入的音频数据的指针。  | 
| audioDataSize | 用户写入的音频数据的数据长度，以字节为单位。  | 
| metadata | 指向用户写入的元数据的指针。  | 
| metadataSize | 用户写入的元数据的数据长度，以字节为单位。  | 

**返回：**

用户返回的回调函数的错误码。


### OH_AudioRoutingManager

```
typedef struct OH_AudioRoutingManager OH_AudioRoutingManager
```
**描述**
声明音频路由管理器，用于路由和设备相关功能的音频路由管理器的句柄。

**起始版本：** 12


### OH_AudioRoutingManager_OnDeviceBlockStatusCallback

```
typedef void (*OH_AudioRoutingManager_OnDeviceBlockStatusCallback)(OH_AudioDeviceDescriptorArray *audioDeviceDescriptorArray, OH_AudioDevice_BlockStatus status, void *userData);
```
**描述**
此函数指针将指向用于返回音频设备堵塞状态的回调函数，可能返回多个音频设备描述符。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioDeviceDescriptorArray | 音频设备描述符数组应当被释放，获取请调用[OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices)接口。设置音频设备描述符值的指针变量，不要单独释放audioDeviceDescriptorArray指针，而是调用[OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices)来释放DeviceDescriptor数组。 |
| status | 音频设备的堵塞状态[OH_AudioDevice_BlockStatus](#oh_audiodevice_blockstatus)。 |
| userData | 用户自定义数据指针。 | 


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


### OH_AudioSession_DeactivatedCallback

```
typedef int32_t(* OH_AudioSession_DeactivatedCallback)(OH_AudioSession_DeactivatedEvent event)
```
**描述**
这个函数指针将指向用于监听音频会话停用事件的回调函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 指向[OH_AudioSession_Deactivated_Event](#oh_audiosession_deactivatedevent)音频会话已停用事件。  | 


### OH_AudioSession_DeactivatedEvent

```
typedef struct OH_AudioSession_DeactivatedEventOH_AudioSession_DeactivatedEvent
```
**描述**
音频会话已停用事件。

**起始版本：** 12


### OH_AudioSession_Strategy

```
typedef struct OH_AudioSession_Strategy OH_AudioSession_Strategy
```
**描述**
音频会话策略。

**起始版本：** 12


### OH_AudioSessionManager

```
typedef struct OH_AudioSessionManager OH_AudioSessionManager
```
**描述**
声明音频会话管理器。

用于管理音频会话相关功能。

**起始版本：** 12


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
| AUDIOCOMMON_RESULT_SUCCESS  | 操作成功。   | 
| AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM  | 入参错误。   | 
| AUDIOCOMMON_RESULT_ERROR_NO_MEMORY  | 无内存。   | 
| AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE  | 非法状态。   | 
| AUDIOCOMMON_RESULT_ERROR_UNSUPPORTED  | 操作不支持。   | 
| AUDIOCOMMON_RESULT_ERROR_TIMEOUT  | 操作超时。   | 
| AUDIOCOMMON_RESULT_ERROR_STREAM_LIMIT  | 达到系统可支持的最大数量。   | 
| AUDIOCOMMON_RESULT_ERROR_SYSTEM  | 系统通用错误。   | 


### OH_AudioData_Callback_Result

```
enum OH_AudioData_Callback_Result
```
**描述**
定义音频数据回调结果。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_DATA_CALLBACK_RESULT_INVALID  | 表示音频数据回调结果无效，且音频数据不播放。   | 
| AUDIO_DATA_CALLBACK_RESULT_VALID  | 表示音频数据回调结果有效，将播放音频数据。   | 


### OH_AudioDevice_BlockStatus

```
enum OH_AudioDevice_BlockStatus
```
**描述**
声明音频设备的堵塞状态。默认情况下，音频设备被视为未堵塞。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_DEVICE_UNBLOCKED  | 音频设备未被堵塞。 | 
| AUDIO_DEVICE_BLOCKED | 音频设备被堵塞。 | 


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
定义音频设备角色。

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
| AUDIO_DEVICE_TYPE_REMOTE_CAST | 音频被系统应用投送到其他远程的设备。 | 
| AUDIO_DEVICE_TYPE_DEFAULT | 默认设备类型。 | 


### OH_AudioDevice_Usage

```
enum OH_AudioDevice_Usage
```
**描述**
定义可获取的设备种类。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_DEVICE_USAGE_MEDIA_OUTPUT  | 媒体输出设备。 | 
| AUDIO_DEVICE_USAGE_MEDIA_INPUT  | 媒体输入设备。 | 
| AUDIO_DEVICE_USAGE_MEDIA_ALL  | 所有媒体设备。 | 
| AUDIO_DEVICE_USAGE_CALL_OUTPUT  | 通话输出设备。 | 
| AUDIO_DEVICE_USAGE_CALL_INPUT  | 通话输入设备。 | 
| AUDIO_DEVICE_USAGE_CALL_ALL  | 所有通话设备。 | 


### OH_AudioInterrupt_ForceType

```
enum OH_AudioInterrupt_ForceType
```
**描述**
定义音频中断类型。

当用户监听到音频中断时，将获取此信息。

此类型表示本次音频打断的操作是否已由系统强制执行，具体操作信息（如音频暂停、停止等）可通过[OH_AudioInterrupt_Hint](#oh_audiointerrupt_hint)获取。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIOSTREAM_INTERRUPT_FORCE  | 强制打断类型，即具体操作已由系统强制执行。   | 
| AUDIOSTREAM_INTERRUPT_SHARE  | 共享打断类型，即系统不执行具体操作，通过[OH_AudioInterrupt_Hint](#oh_audiointerrupt_hint)提示并建议应用操作，应用可自行决策下一步处理方式。  | 


### OH_AudioInterrupt_Hint

```
enum OH_AudioInterrupt_Hint
```
**描述**
定义音频中断提示类型。

当用户监听到音频中断时，将获取此信息。

此类型表示根据焦点策略，当前需要对音频流的具体操作（如暂停、调整音量等）。可以结合[OH_AudioInterrupt_ForceType](#oh_audiointerrupt_forcetype)信息，判断该操作是否已由系统强制执行。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIOSTREAM_INTERRUPT_HINT_NONE  | 不提示。   | 
| AUDIOSTREAM_INTERRUPT_HINT_RESUME  | 提示音频恢复，应用可主动触发开始渲染或开始采集的相关操作。<br>此操作无法由系统强制执行，其对应的[OH_AudioInterrupt_ForceType](#oh_audiointerrupt_forcetype)一定为AUDIOSTREAM_INTERRUPT_SHARE类型。   | 
| AUDIOSTREAM_INTERRUPT_HINT_PAUSE  | 提示音频暂停，暂时失去音频焦点。<br>后续待焦点可用时，会出现AUDIOSTREAM_INTERRUPT_HINT_RESUME事件。   | 
| AUDIOSTREAM_INTERRUPT_HINT_STOP  | 提示音频停止，彻底失去音频焦点。   | 
| AUDIOSTREAM_INTERRUPT_HINT_DUCK  | 提示音频躲避开始，音频降低音量播放，而不会停止。   | 
| AUDIOSTREAM_INTERRUPT_HINT_UNDUCK  | 提示音量躲避结束，音频恢复正常音量。   | 


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
| AUDIOSTREAM_INTERRUPT_MODE_SHARE  | 共享模式。  | 
| AUDIOSTREAM_INTERRUPT_MODE_INDEPENDENT  | 独立模式。 | 


### OH_AudioScene

```
enum OH_AudioScene
```
**描述**
定义音频场景。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_SCENE_DEFAULT  | 默认音频场景。 | 
| AUDIO_SCENE_RINGING  | 响铃场景。 | 
| AUDIO_SCENE_PHONE_CALL  | 电话场景。 | 
| AUDIO_SCENE_VOICE_CHAT  | 语音聊天场景。 | 


### OH_AudioSession_ConcurrencyMode

```
enum OH_AudioSession_ConcurrencyMode
```
**描述**
音频并发模式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| CONCURRENCY_DEFAULT  | 默认使用系统策略。   | 
| CONCURRENCY_MIX_WITH_OTHERS  | 和其它正在播放应用进行混音。   | 
| CONCURRENCY_DUCK_OTHERS  | 后来播放应用压低正在播放应用的音量。   | 
| CONCURRENCY_PAUSE_OTHERS  | 后来播放应用暂停正在播放应用。   | 


### OH_AudioSession_DeactivatedReason

```
enum OH_AudioSession_DeactivatedReason
```
**描述**
音频会话停用原因。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| DEACTIVATED_LOWER_PRIORITY  | 应用焦点被抢占。   | 
| DEACTIVATED_TIMEOUT  | 应用停流后超时。   | 


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
| EFFECT_NONE  | 无音效模式。   | 
| EFFECT_DEFAULT  | 默认音效模式。   | 


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
| REASON_UNKNOWN  | 未知原因。   | 
| REASON_NEW_DEVICE_AVAILABLE  | 新设备可用。   | 
| REASON_OLD_DEVICE_UNAVAILABLE  | 旧设备不可用。当报告此原因时，应用程序应考虑暂停音频播放。   | 
| REASON_OVERRODE  | 用户或系统强制选择切换。   | 


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
| AUDIOSTREAM_ENCODING_TYPE_RAW  | PCM编码。   | 
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
| AUDIOSTREAM_EVENT_ROUTING_CHANGED  | 音频的路由已更改。   | 


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
| AUDIOSTREAM_LATENCY_MODE_NORMAL  | 该模式代表一个普通时延的音频流。   | 
| AUDIOSTREAM_LATENCY_MODE_FAST  | 该模式代表一个低时延的音频流。   | 


### OH_AudioStream_PrivacyType

```
enum OH_AudioStream_PrivacyType
```
**描述**
用于标识对应播放音频流是否支持被其他应用录制。

**系统能力：** SystemCapability.Multimedia.Audio.PlaybackCapture

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_STREAM_PRIVACY_TYPE_PUBLIC  | 表示音频流可以被其他应用录制。   | 
| AUDIO_STREAM_PRIVACY_TYPE_PRIVATE  | 表示音频流不可以被其他应用录制。   | 


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
| AUDIOSTREAM_SUCCESS  | 操作成功   | 
| AUDIOSTREAM_ERROR_INVALID_PARAM  | 入参错误。   | 
| AUDIOSTREAM_ERROR_ILLEGAL_STATE  | 非法状态。   | 
| AUDIOSTREAM_ERROR_SYSTEM  | 系统通用错误。   | 


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
| AUDIOSTREAM_SAMPLE_U8  | Unsigned 8位。   | 
| AUDIOSTREAM_SAMPLE_S16LE  | Short 16位小端。   | 
| AUDIOSTREAM_SAMPLE_S24LE  | Short 24位小端。   | 
| AUDIOSTREAM_SAMPLE_S32LE  | Short 32位小端。   | 


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
| AUDIOSTREAM_SOURCE_TYPE_INVALID  | 不合法状态。   | 
| AUDIOSTREAM_SOURCE_TYPE_MIC  | 录音。   | 
| AUDIOSTREAM_SOURCE_TYPE_VOICE_RECOGNITION  | 语音识别。   | 
| AUDIOSTREAM_SOURCE_TYPE_PLAYBACK_CAPTURE  | 播放录音。   | 
| AUDIOSTREAM_SOURCE_TYPE_VOICE_COMMUNICATION  | 通话。   | 
| AUDIOSTREAM_SOURCE_TYPE_CAMCORDER | 录像。<br>**起始版本：** 13 |


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
| AUDIOSTREAM_STATE_INVALID  | 不合法的状态。   | 
| AUDIOSTREAM_STATE_NEW  | 新创建时的状态。   | 
| AUDIOSTREAM_STATE_PREPARED  | 准备状态。   | 
| AUDIOSTREAM_STATE_RUNNING  | 工作状态。   | 
| AUDIOSTREAM_STATE_STOPPED  | 停止状态。   | 
| AUDIOSTREAM_STATE_RELEASED  | 释放状态。   | 
| AUDIOSTREAM_STATE_PAUSED  | 暂停状态。   | 


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
| AUDIOSTREAM_TYPE_RENDERER  | 该类型代表音频流是输出流。   | 
| AUDIOSTREAM_TYPE_CAPTURER  | 该类型代表音频流是输入流。   | 


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
| AUDIOSTREAM_USAGE_UNKNOWN  | 未知类型。   | 
| AUDIOSTREAM_USAGE_MUSIC  | 音乐。   | 
| AUDIOSTREAM_USAGE_VOICE_COMMUNICATION  | VoIP语音通话。   | 
| AUDIOSTREAM_USAGE_VOICE_ASSISTANT  | 语音播报。   | 
| AUDIOSTREAM_USAGE_ALARM  | 闹钟。   | 
| AUDIOSTREAM_USAGE_VOICE_MESSAGE  | 语音消息。   | 
| AUDIOSTREAM_USAGE_RINGTONE  | 铃声。   | 
| AUDIOSTREAM_USAGE_NOTIFICATION  | 通知。   | 
| AUDIOSTREAM_USAGE_ACCESSIBILITY  | 无障碍。   | 
| AUDIOSTREAM_USAGE_MOVIE  | 电影或视频。   | 
| AUDIOSTREAM_USAGE_GAME  | 游戏。   | 
| AUDIOSTREAM_USAGE_AUDIOBOOK  | 有声读物（包括听书、相声、评书）、听新闻、播客等。   | 
| AUDIOSTREAM_USAGE_NAVIGATION  | 导航。   | 
| AUDIOSTREAM_USAGE_VIDEO_COMMUNICATION | VoIP视频通话。<br>**起始版本：** 12 | 


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

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数capturer为nullptr。

AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。


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

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数capturer为nullptr。


### OH_AudioCapturer_GetChannelCount()

```
OH_AudioStream_Result OH_AudioCapturer_GetChannelCount(OH_AudioCapturer *capturer, int32_t *channelCount)
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

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数capturer为nullptr。


### OH_AudioCapturer_GetCurrentState()

```
OH_AudioStream_Result OH_AudioCapturer_GetCurrentState(OH_AudioCapturer *capturer, OH_AudioStream_State *state)
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

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数capturer为nullptr。


### OH_AudioCapturer_GetEncodingType()

```
OH_AudioStream_Result OH_AudioCapturer_GetEncodingType(OH_AudioCapturer *capturer, OH_AudioStream_EncodingType *encodingType)
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

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数capturer为nullptr。


### OH_AudioCapturer_GetFrameSizeInCallback()

```
OH_AudioStream_Result OH_AudioCapturer_GetFrameSizeInCallback(OH_AudioCapturer *capturer, int32_t *frameSize)
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

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数capturer为nullptr。

AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。


### OH_AudioCapturer_GetFramesRead()

```
OH_AudioStream_Result OH_AudioCapturer_GetFramesRead (OH_AudioCapturer *capturer, int64_t *frames)
```
**描述**
查询自创建流以来已读取的帧数。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 | 
| frames | 指向将为帧计数设置的变量的指针。 | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数capturer为nullptr。


### OH_AudioCapturer_GetLatencyMode()

```
OH_AudioStream_Result OH_AudioCapturer_GetLatencyMode(OH_AudioCapturer *capturer, OH_AudioStream_LatencyMode *latencyMode)
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

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数capturer为nullptr。


### OH_AudioCapturer_GetOverflowCount()

```
OH_AudioStream_Result OH_AudioCapturer_GetOverflowCount (OH_AudioCapturer *capturer, uint32_t *count)
```
**描述**
查询当前录制音频流过载数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)创建的音频流实例。  | 
| count | 指向一个用来接收音频流过载数的变量的指针。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数capturer为nullptr。


### OH_AudioCapturer_GetSampleFormat()

```
OH_AudioStream_Result OH_AudioCapturer_GetSampleFormat(OH_AudioCapturer *capturer, OH_AudioStream_SampleFormat *sampleFormat)
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

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数capturer为nullptr。


### OH_AudioCapturer_GetSamplingRate()

```
OH_AudioStream_Result OH_AudioCapturer_GetSamplingRate(OH_AudioCapturer *capturer, int32_t *rate)
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

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数capturer为nullptr。


### OH_AudioCapturer_GetStreamId()

```
OH_AudioStream_Result OH_AudioCapturer_GetStreamId(OH_AudioCapturer *capturer, uint32_t *streamId)
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

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数capturer为nullptr。


### OH_AudioCapturer_GetTimestamp()

```
OH_AudioStream_Result OH_AudioCapturer_GetTimestamp(OH_AudioCapturer *capturer, clockid_t clockId, int64_t *framePosition, int64_t *timestamp)
```
**描述**
获取输入音频流时间戳和位置信息。

该接口可以获取到音频通道实际录制位置（framePosition）以及录制到该位置时候的时间戳（timestamp），时间戳单位为纳秒。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 | 
| clockId | 时钟标识符，使用CLOCK_MONOTONIC。 | 
| framePosition | 指向要接收位置的变量的指针。 | 
| timestamp | 指向接收时间戳的变量的指针。 | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：

  1. 参数capturer为nullptr；
  2. 参数clockId无效。

AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。


### OH_AudioCapturer_Pause()

```
OH_AudioStream_Result OH_AudioCapturer_Pause(OH_AudioCapturer *capturer)
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

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数capturer为nullptr。

AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。


### OH_AudioCapturer_Release()

```
OH_AudioStream_Result OH_AudioCapturer_Release(OH_AudioCapturer *capturer)
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

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数capturer为nullptr。

AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。


### OH_AudioCapturer_Start()

```
OH_AudioStream_Result OH_AudioCapturer_Start(OH_AudioCapturer *capturer)
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

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数capturer为nullptr。

AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。


### OH_AudioCapturer_Stop()

```
OH_AudioStream_Result OH_AudioCapturer_Stop(OH_AudioCapturer *capturer)
```
**描述**
停止输入音频流。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 | 

**需要权限：**

ohos.permission.MICROPHONE

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数capturer为nullptr。

AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。


### OH_AudioDeviceDescriptor_GetDeviceAddress()

```
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceAddress (OH_AudioDeviceDescriptor *audioDeviceDescriptor, char **address)
```
**描述**
查询目标音频设备描述符的设备地址。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioDeviceDescriptor | 音频设备描述符。通过 [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices) 或者 [OH_AudioRouterManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback)获取。 | 
| address | 设备MAC地址指针，将设置设备MAC地址值的变量。 不要单独释放音频设备MAC地址指针，而是调用[OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices)，以便在不再使用时释放所有DeviceDescriptor数组。 | 

**返回：**

AUDIOCOMMON_RESULT_SUCCESS 或 AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM


### OH_AudioDeviceDescriptor_GetDeviceChannelCounts()

```
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceChannelCounts (OH_AudioDeviceDescriptor *audioDeviceDescriptor, uint32_t **channelCounts, uint32_t *size)
```
**描述**
查询目标音频设备描述符的设备通道计数数组。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioDeviceDescriptor | 音频设备描述符。通过 [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices) 或者 [OH_AudioRouterManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback)获取。 | 
| channelCounts | 数组指针变量，该变量将设置通道计数数组值。 不要单独释放音频设备通道数指针，而是调用[OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices)，以便在不再使用时释放所有DeviceDescriptor数组。 | 
| size | 设置通道计数大小值的指针变量。 | 

**返回：**

AUDIOCOMMON_RESULT_SUCCESS 或 AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM


### OH_AudioDeviceDescriptor_GetDeviceDisplayName()

```
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceDisplayName (OH_AudioDeviceDescriptor *audioDeviceDescriptor, char **displayName)
```
**描述**
查询目标音频设备描述符的显示名称。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioDeviceDescriptor | 音频设备描述符。通过 [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices) 或者 [OH_AudioRouterManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback)获取。 | 
| displayName | 设置显示名称值的指针变量。 不要单独释放音频设备显示名称指针，而是调用[OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices)，以便在不再使用时释放所有DeviceDescriptor数组。 | 

**返回：**

AUDIOCOMMON_RESULT_SUCCESS 或 AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM


### OH_AudioDeviceDescriptor_GetDeviceEncodingTypes()

```
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceEncodingTypes (OH_AudioDeviceDescriptor *audioDeviceDescriptor, OH_AudioStream_EncodingType **encodingTypes, uint32_t *size)
```
**描述**
查询目标音频设备描述符的编码类型数组。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioDeviceDescriptor | 音频设备描述符。通过 [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices) 或者 [OH_AudioRouterManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback)获取。 | 
| encodingTypes | 音频设备编码类型。 [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) 不要单独释放音频设备编码类型指针，而是调用[OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices)，以便在不再使用时释放所有DeviceDescriptor数组。 | 
| size | 设置编码类型大小值的指针变量。 | 

**返回：**

AUDIOCOMMON_RESULT_SUCCESS 或 AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM


### OH_AudioDeviceDescriptor_GetDeviceId()

```
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceId (OH_AudioDeviceDescriptor *audioDeviceDescriptor, uint32_t *id)
```
**描述**
查询目标音频设备描述符的设备id。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioDeviceDescriptor | 音频设备描述符。通过 [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices) 或者 [OH_AudioRouterManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback)获取。 | 
| id | 设备id指针，将设置设备角色值的变量。 | 

**返回：**

AUDIODEVICE_SUCCESS 或 AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM


### OH_AudioDeviceDescriptor_GetDeviceName()

```
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceName (OH_AudioDeviceDescriptor *audioDeviceDescriptor, char **name )
```
**描述**
查询目标音频设备描述符的设备名称。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioDeviceDescriptor | 音频设备描述符。通过 [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices) 或者 [OH_AudioRouterManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback)获取。 | 
| name | 设备名称指针，将设置设备名称值的变量。 不要单独释放音频设备名称指针，而是调用[OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices)，以便在不再使用时释放所有DeviceDescriptor数组。 | 

**返回：**

AUDIOCOMMON_RESULT_SUCCESS 或 AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM


### OH_AudioDeviceDescriptor_GetDeviceRole()

```
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceRole (OH_AudioDeviceDescriptor *audioDeviceDescriptor, OH_AudioDevice_Role *deviceRole)
```
**描述**
查询目标音频设备描述符的设备角色。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioDeviceDescriptor | 音频设备描述符。通过 [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices) 或者 [OH_AudioRouterManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback)获取。 | 
| deviceRole | 设备角色指针。 [OH_AudioDevice_Role](#oh_audiodevice_role) 将设置设备角色值的变量。 | 

**返回：**

AUDIOCOMMON_RESULT_SUCCESS 或 AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM


### OH_AudioDeviceDescriptor_GetDeviceSampleRates()

```
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceSampleRates (OH_AudioDeviceDescriptor *audioDeviceDescriptor, uint32_t **sampleRates, uint32_t *size)
```
**描述**
查询目标音频设备描述符的采样率数组。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioDeviceDescriptor | 音频设备描述符。通过 [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices) 或者 [OH_AudioRouterManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback)获取。 | 
| sampleRates | 设置采样率数组值的数组指针变量。 不要单独释放音频设备采样率指针，而是调用[OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices)，以便在不再使用时释放所有DeviceDescriptor数组。 | 
| size | 设置采样率大小值的指针变量。 | 

**返回：**

AUDIOCOMMON_RESULT_SUCCESS 或 AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM


### OH_AudioDeviceDescriptor_GetDeviceType()

```
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceType (OH_AudioDeviceDescriptor *audioDeviceDescriptor, OH_AudioDevice_Type *deviceType)
```
**描述**
查询目标音频设备描述符的设备类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioDeviceDescriptor | 音频设备描述符。通过 [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices) 或者 [OH_AudioRouterManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback)获取。 | 
| deviceType | 设备类型指针。 [OH_AudioDevice_Type](#oh_audiodevice_type) 将设置设备类型值的变量。  | 

**返回：**

AUDIOCOMMON_RESULT_SUCCESS 或 AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM


### OH_AudioManager_GetAudioRoutingManager()

```
OH_AudioCommon_Result OH_AudioManager_GetAudioRoutingManager (OH_AudioRoutingManager **audioRoutingManager)
```
**描述**
查询音频路由管理器句柄，该句柄应设置为路由相关函数中的第一个参数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioRoutingManager | 音频路由管理器句柄[OH_AudioRoutingManager](#oh_audioroutingmanager)。 通过[OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager)获取句柄。 | 

**返回：**

函数返回值[OH_AudioCommon_Result](#oh_audiocommon_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。


### OH_AudioManager_GetAudioSessionManager()

```
OH_AudioCommon_Result OH_AudioManager_GetAudioSessionManager (OH_AudioSessionManager **audioSessionManager)
```
**描述**
获取音频会话管理器。

使用音频会话管理器相关功能，首先需要获取音频会话管理器实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioSessionManager | 指向[OH_AudioSessionManager](#oh_audiosessionmanager)音频会话管理器实例。 | 

**返回：**

函数返回值[OH_AudioCommon_Result](#oh_audiocommon_result)：

AUDIOCOMMON_RESULT_SUCCESS 函数执行成功。


### OH_AudioRenderer_CancelMark()

```
OH_AudioStream_Result OH_AudioRenderer_CancelMark (OH_AudioRenderer *renderer)
```
**描述**
取消由[OH_AudioRenderer_SetMarkPosition](#oh_audiorenderer_setmarkposition)设置的标记。

**起始版本：** 12

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。


### OH_AudioRenderer_Flush()

```
OH_AudioStream_Result OH_AudioRenderer_Flush(OH_AudioRenderer *renderer)
```
**描述**
丢弃已经写入的音频数据。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数renderer为nullptr。

AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。


### OH_AudioRenderer_GetChannelCount()

```
OH_AudioStream_Result OH_AudioRenderer_GetChannelCount(OH_AudioRenderer *renderer, int32_t *channelCount)
```
**描述**
查询当前输出音频流通道数。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| channelCount | 指向一个用来接收音频流通道数的变量。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数renderer为nullptr。


### OH_AudioRenderer_GetChannelLayout()

```
OH_AudioStream_Result OH_AudioRenderer_GetChannelLayout (OH_AudioRenderer *renderer, OH_AudioChannelLayout *channelLayout)
```
**描述**
查询当前音频流声道布局。

**起始版本：** 12

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| channelLayout | 指向一个用来接收音频流声道布局的变量的指针，具体参考[OH_AudioChannelLayout](../apis-avcodec-kit/_core.md#oh_audiochannellayout-1)。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数renderer为nullptr。


### OH_AudioRenderer_GetCurrentState()

```
OH_AudioStream_Result OH_AudioRenderer_GetCurrentState(OH_AudioRenderer *renderer, OH_AudioStream_State *state)
```
**描述**
查询当前输出音频流状态。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| state | 指向一个用来接收音频流状态的变量。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数renderer为nullptr。


### OH_AudioRenderer_GetEffectMode()

```
OH_AudioStream_Result OH_AudioRenderer_GetEffectMode (OH_AudioRenderer *renderer, OH_AudioStream_AudioEffectMode *effectMode)
```
**描述**
查询当前音频流音效模式。

**起始版本：** 12

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| effectMode | 指向一个用来接收音频流音效模式的变量的指针。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数renderer为nullptr。


### OH_AudioRenderer_GetEncodingType()

```
OH_AudioStream_Result OH_AudioRenderer_GetEncodingType(OH_AudioRenderer *renderer, OH_AudioStream_EncodingType *encodingType)
```
**描述**
查询当前输出音频流编码类型。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| encodingType | 指向一个用来接收音频流编码类型的变量。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数renderer为nullptr。


### OH_AudioRenderer_GetFrameSizeInCallback()

```
OH_AudioStream_Result OH_AudioRenderer_GetFrameSizeInCallback(OH_AudioRenderer *renderer, int32_t *frameSize)
```
**描述**
在回调中查询帧大小，它是一个固定的长度，每次回调都要填充流。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| frameSize | 指向将为帧大小设置的变量的指针。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数renderer为nullptr。


### OH_AudioRenderer_GetFramesWritten()

```
OH_AudioStream_Result OH_AudioRenderer_GetFramesWritten(OH_AudioRenderer *renderer, int64_t *frames)
```
**描述**
查询自创建流以来已写入的帧数。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| frames | 指向将为帧计数设置的变量的指针。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数renderer为nullptr。


### OH_AudioRenderer_GetLatencyMode()

```
OH_AudioStream_Result OH_AudioRenderer_GetLatencyMode(OH_AudioRenderer *renderer, OH_AudioStream_LatencyMode *latencyMode)
```
**描述**
查询当前输出音频流时延模式。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| latencyMode | 指向一个用来接收音频流时延模式的变量。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数renderer为nullptr。


### OH_AudioRenderer_GetRendererInfo()

```
OH_AudioStream_Result OH_AudioRenderer_GetRendererInfo(OH_AudioRenderer *renderer, OH_AudioStream_Usage *usage)
```
**描述**
查询当前输出音频流工作场景类型。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| usage | 指向一个用来接收输出类型音频流的工作场景的变量。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数renderer为nullptr。


### OH_AudioRenderer_GetRendererPrivacy()

```
OH_AudioStream_Result OH_AudioRenderer_GetRendererPrivacy (OH_AudioRenderer *renderer, OH_AudioStream_PrivacyType *privacy)
```
**描述**
查询当前播放音频流是否会被其它应用录制。

**起始版本：** 12

**系统能力：** SystemCapability.Multimedia.Audio.PlaybackCapture

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| privacy | 用于返回当前流的内录策略。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数renderer为nullptr。


### OH_AudioRenderer_GetSampleFormat()

```
OH_AudioStream_Result OH_AudioRenderer_GetSampleFormat(OH_AudioRenderer *renderer, OH_AudioStream_SampleFormat *sampleFormat)
```
**描述**
查询当前输出音频流采样格式。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| sampleFormat | 指向一个用来接收音频流采样格式的变量。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数renderer为nullptr。


### OH_AudioRenderer_GetSamplingRate()

```
OH_AudioStream_Result OH_AudioRenderer_GetSamplingRate(OH_AudioRenderer *renderer, int32_t *rate)
```
**描述**
查询当前输出音频流采样率。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| rate | 指向一个用来接收音频流采样率的变量。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数renderer为nullptr。


### OH_AudioRenderer_GetSilentModeAndMixWithOthers()

```
OH_AudioStream_Result OH_AudioRenderer_GetSilentModeAndMixWithOthers(OH_AudioRenderer *renderer, bool *on)
```
**描述**
查询当前音频流是否开启静音并发播放。

**起始版本：** 12

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| on | 用于返回当前流的静音并发状态。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOSTREAM_SUCCESS 函数执行成功。 

AUDIOSTREAM_ERROR_INVALID_PARAM 参数renderer为nullptr。



### OH_AudioRenderer_GetSpeed()

```
OH_AudioStream_Result OH_AudioRenderer_GetSpeed (OH_AudioRenderer * renderer, float * speed )
```
**描述**
获取音频渲染速率。

**起始版本：** 11

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| speed | 指向接收播放倍速值的变量的指针。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数renderer为nullptr。


### OH_AudioRenderer_GetStreamId()

```
OH_AudioStream_Result OH_AudioRenderer_GetStreamId(OH_AudioRenderer *renderer, uint32_t *streamId)
```
**描述**
查询当前输出音频流ID。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| streamId | 指向一个用来接收音频流ID的变量。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数renderer为nullptr。


### OH_AudioRenderer_GetTimestamp()

```
OH_AudioStream_Result OH_AudioRenderer_GetTimestamp(OH_AudioRenderer *renderer, clockid_t clockId, int64_t *framePosition, int64_t *timestamp)
```
**描述**
获取输出音频流时间戳和位置信息。

该接口可以获取到音频通道实际播放位置（framePosition）以及播放到该位置时的时间戳（timestamp），时间戳单位为纳秒。

该接口一般用来实现音画同步，建议频率不要太频繁，可以每分钟一次，最好不要低200ms一次。频繁调用可能会带来功耗问题，因此在能保证音画同步效果的情况下，不需要频繁的查询时间戳。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| clockId | 时钟标识符，使用CLOCK_MONOTONIC。  | 
| framePosition | 指向要接收位置的变量的指针。  | 
| timestamp | 指向接收时间戳的变量的指针。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：

  1. 参数renderer为nullptr；
  2. 参数clockId无效。

AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。


### OH_AudioRenderer_GetUnderflowCount()

```
OH_AudioStream_Result OH_AudioRenderer_GetUnderflowCount (OH_AudioRenderer *renderer, uint32_t *count)
```
**描述**
查询当前播放音频流欠载数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| count | 指向一个用来接收音频流欠载数的变量的指针。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：

  1. 参数renderer为nullptr；
  2. 参数count为nullptr。


### OH_AudioRenderer_GetVolume()

```
OH_AudioStream_Result OH_AudioRenderer_GetVolume (OH_AudioRenderer *renderer, float *volume)
```
**描述**
获取当前音频流音量值。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| volume | 指向一个获取当前音频流音量值的指针。音量值的范围是[0.0, 1.0]。  |

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：
  
  1. 参数renderer为nullptr；
  2. 参数volume为nullptr。


### OH_AudioRenderer_Pause()

```
OH_AudioStream_Result OH_AudioRenderer_Pause(OH_AudioRenderer *renderer)
```
**描述**
暂停输出音频流。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数renderer为nullptr。

AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。


### OH_AudioRenderer_Release()

```
OH_AudioStream_Result OH_AudioRenderer_Release(OH_AudioRenderer *renderer)
```
**描述**
释放输出音频流。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数renderer为nullptr。

AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。


### OH_AudioRenderer_SetDefaultOutputDevice()

```
OH_AudioStream_Result OH_AudioRenderer_SetDefaultOutputDevice (OH_AudioRenderer* renderer, OH_AudioDevice_Type deviceType)
```
**描述**
设置默认本机内置发声设备。

本接口仅适用于音频流类型[OH_AudioStream_Usage](#oh_audiostream_usage)为语音消息、VoIP语音通话或者VoIP视频通话的场景使用，以及可选的设备类型为听筒、扬声器和系统默认设备。

本接口允许在AudioRenderer创建以后的任何时间被调用，系统会记录应用设置的默认本机内置发声设备。在应用启动播放时，若有外接设备如蓝牙耳机/有线耳机接入，系统优先从外接设备发声；否则系统遵循应用设置的默认本机内置发声设备发声。

**起始版本：** 12

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| deviceType | 指向[OH_AudioDevice_Type](#oh_audiodevice_type)用于设置发声设备类型。<br>可设置的设备类型包括: <br>AUDIO_DEVICE_TYPE_EARPIECE: 听筒 <br>AUDIO_DEVICE_TYPE_SPEAKER: 扬声器 <br>AUDIO_DEVICE_TYPE_DEFAULT: 系统默认设备  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOSTREAM_ERROR_INVALID_PARAM:

1. 参数renderer为nullptr;
2. 参数deviceType无效。 
 
AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。 

AUDIOSTREAM_ERROR_SYSTEM：出现系统错误。 


### OH_AudioRenderer_SetEffectMode()

```
OH_AudioStream_Result OH_AudioRenderer_SetEffectMode (OH_AudioRenderer *renderer, OH_AudioStream_AudioEffectMode effectMode)
```
**描述**
设置当前音频流音效模式。

**起始版本：** 12

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| effectMode | 设置当前音频流的目标音效模式。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数renderer为nullptr。


### OH_AudioRenderer_SetMarkPosition()

```
OH_AudioStream_Result OH_AudioRenderer_SetMarkPosition (OH_AudioRenderer *renderer, uint32_t samplePos, OH_AudioRenderer_OnMarkReachedCallback callback, void *userData)
```
**描述**
在当前渲染器上设置标记位置。调用此函数将覆盖已设置的标记位置。

**起始版本：** 12

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| samplePos | 设置目标标记位置。  | 
| callback | 当到达目标标记位置时回调[OH_AudioRenderer_OnMarkReachedCallback](#oh_audiorenderer_onmarkreachedcallback)。  | 
| userData | 指向通过回调函数传递的应用数据指针。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：

  1. 参数renderer为nullptr；
  2. 参数samplePos无效。

AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。

AUDIOSTREAM_ERROR_SYSTEM：出现系统错误。


### OH_AudioRenderer_SetSilentModeAndMixWithOthers()

```
OH_AudioStream_Result OH_AudioRenderer_SetSilentModeAndMixWithOthers (OH_AudioRenderer *renderer, bool on)
```
**描述**
设置静音并发播放模式。

**起始版本：** 12

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| on | 设置当前音频流的静音并发状态。 true: 设置当前播放的音频流静音播放，并且不会打断其它音频流播放。 false: 取消当前播放的音频流静音播放，音频流可根据系统焦点策略抢占焦点。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOSTREAM_SUCCESS：函数执行成功。 

AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。


### OH_AudioRenderer_SetSpeed()

```
OH_AudioStream_Result OH_AudioRenderer_SetSpeed (OH_AudioRenderer *renderer, float speed)
```
**描述**
设置音频渲染速率。

**起始版本：** 11

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| speed | 设置播放的倍速值（倍速范围：0.25-4.0）。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数renderer为nullptr。


### OH_AudioRenderer_SetVolume()

```
OH_AudioStream_Result OH_AudioRenderer_SetVolume (OH_AudioRenderer *renderer, float volume)
```
**描述**
设置当前音频流音量值。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| volume | 设置当前音频流音量，音量值的范围是[0.0, 1.0]。  |

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：
  
  1. 参数renderer为nullptr；
  2. 参数volume无效。

AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。

AUDIOSTREAM_ERROR_SYSTEM：出现系统错误。


### OH_AudioRenderer_SetVolumeWithRamp()

```
OH_AudioStream_Result OH_AudioRenderer_SetVolumeWithRamp (OH_AudioRenderer *renderer, float volume, int32_t durationMs)
```
**描述**
在指定时间范围内使用渐变更改音量。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 
| volume | 目标音量值，取值范围[0.0, 1.0]。  | 
| durationMs | 音量渐变的持续时间，以毫秒为单位。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：
  
  1. 参数renderer为nullptr；
  2. 参数volume无效。

AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。

AUDIOSTREAM_ERROR_SYSTEM：出现系统错误。


### OH_AudioRenderer_Start()

```
OH_AudioStream_Result OH_AudioRenderer_Start(OH_AudioRenderer *renderer)
```
**描述**
开始输出音频数据。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOSTREAM_SUCCESS：函数执行成功。 

AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。 

AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。


### OH_AudioRenderer_Stop()

```
OH_AudioStream_Result OH_AudioRenderer_Stop(OH_AudioRenderer *renderer)
```
**描述**
停止输出音频流。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)创建的音频流实例。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数renderer为nullptr。

AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。


### OH_AudioRoutingManager_GetAvailableDevices()

```
OH_AudioCommon_Result OH_AudioRoutingManager_GetAvailableDevices (OH_AudioRoutingManager *audioRoutingManager, OH_AudioDevice_Usage deviceUsage, OH_AudioDeviceDescriptorArray **audioDeviceDescriptorArray)
```
**描述**
获取音频可选设备列表。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioRoutingManager | 指向[OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager)创建的音频路由管理器实例： [OH_AudioRoutingManager](#oh_audioroutingmanager)。  | 
| deviceUsage | 指向[OH_AudioDevice_Usage](#oh_audiodevice_usage)用于设置要获取的设备种类。  | 
| audioDeviceDescriptorArray | 音频设备描述符数组。[OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) 设置音频设备描述符值的指针变量，不要单独释放audioDeviceDescriptorArray指针， 而是调用[OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices)来释放DeviceDescriptor数组。| 

**返回：**

函数返回值[OH_AudioCommon_Result](#oh_audiocommon_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：
1. 参数audioRoutingManager为nullptr；
2. 参数deviceUsage无效; 
3. 参数audioDeviceDescriptorArray为nullptr。
 
AUDIOCOMMON_RESULT_ERROR_NO_MEMORY：内存不足。


### OH_AudioRoutingManager_GetDevices()

```
OH_AudioCommon_Result OH_AudioRoutingManager_GetDevices (OH_AudioRoutingManager *audioRoutingManager, OH_AudioDevice_Flag deviceFlag, OH_AudioDeviceDescriptorArray **audioDeviceDescriptorArray)
```
**描述**
根据输入的deviceFlag查询可用的设备。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioRoutingManager | 音频路由管理器句柄[OH_AudioRoutingManager](#oh_audioroutingmanager)。通过[OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager)获取句柄。 | 
| deviceFlag | 音频设备标志[OH_AudioDevice_Flag](#oh_audiodevice_flag)，用于选择目标设备的滤波器参数。 | 
| audioDeviceDescriptorArray | 音频设备描述符数组[OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md)。 设置音频设备描述符值的指针变量，不要单独释放audioDeviceDescriptorArray指针， 而是调用[OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices)来释放DeviceDescriptor数组。|

**返回：**

函数返回值[OH_AudioCommon_Result](#oh_audiocommon_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：

  1. 参数audioRoutingManager为nullptr；
  2. 参数deviceFlag无效；
  3. 参数audioDeviceDescriptorArray为nullptr。

AUDIOCOMMON_RESULT_ERROR_NO_MEMORY：内存不足。

### OH_AudioRoutingManager_GetPreferredInputDevice()

```
OH_AudioCommon_Result OH_AudioRoutingManager_GetPreferredInputDevice (OH_AudioRoutingManager *audioRoutingManager, OH_AudioStream_SourceType sourceType, OH_AudioDeviceDescriptorArray **audioDeviceDescriptorArray )
```
**描述**
根据音频输入流的使用场景，获取优先级最高的输入设备。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioRoutingManager | 指向[OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager)创建的音频路由管理器实例： [OH_AudioRoutingManager](#oh_audioroutingmanager)。  | 
| sourceType | 指向[OH_AudioStream_SourceType](#oh_audiostream_sourcetype)用于设置音频输入流的使用场景。  | 
| audioDeviceDescriptorArray | 音频设备描述符数组。[OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) 设置音频设备描述符值的指针变量，不要单独释放audioDeviceDescriptorArray指针， 而是调用[OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices)来释放DeviceDescriptor数组。| 

**返回：**

函数返回值[OH_AudioCommon_Result](#oh_audiocommon_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：

1. 参数audioRoutingManager为nullptr; 
2. 参数sourceType无效; 
3. 参数audioDeviceDescriptorArray为nullptr。 

AUDIOCOMMON_RESULT_ERROR_NO_MEMORY：内存不足。


### OH_AudioRoutingManager_GetPreferredOutputDevice()

```
OH_AudioCommon_Result OH_AudioRoutingManager_GetPreferredOutputDevice (OH_AudioRoutingManager *audioRoutingManager, OH_AudioStream_Usage streamUsage, OH_AudioDeviceDescriptorArray **audioDeviceDescriptorArray )
```
**描述**
根据音频输出流的使用场景，获取优先级最高的输出设备。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioRoutingManager | 指向[OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager)创建的音频路由管理器实例： [OH_AudioRoutingManager](#oh_audioroutingmanager)。  | 
| streamUsage | 指向[OH_AudioStream_Usage](#oh_audiostream_usage)用于设置音频输出流的使用场景。  | 
| audioDeviceDescriptorArray | 音频设备描述符数组。[OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) 设置音频设备描述符值的指针变量，不要单独释放audioDeviceDescriptorArray指针， 而是调用[OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices)来释放DeviceDescriptor数组。| 

**返回：**

函数返回值[OH_AudioCommon_Result](#oh_audiocommon_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：

1. 参数audioRoutingManager为nullptr; 
2. 参数streamUsage无效; 
3. 参数audioDeviceDescriptorArray为nullptr。 

AUDIOCOMMON_RESULT_ERROR_NO_MEMORY：内存不足。


### OH_AudioRoutingManager_IsMicBlockDetectionSupported()

```
OH_AudioCommon_Result OH_AudioRoutingManager_IsMicBlockDetectionSupported(OH_AudioRoutingManager *audioRoutingManager, bool *supported)
```
**描述**
查询当前设备是否支持麦克风堵塞状态检测。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioRoutingManager | 音频路由管理器句柄[OH_AudioRoutingManager](#oh_audioroutingmanager)。获取句柄通过[OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager)。  | 
| supported | 查询结果。  | 

**返回：**

函数返回值[OH_AudioCommon_Result](#oh_audiocommon_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：

1. 参数audioRoutingManager为nullptr； 
2. 参数supported为nullptr。


### OH_AudioRoutingManager_RegisterDeviceChangeCallback()

```
OH_AudioCommon_Result OH_AudioRoutingManager_RegisterDeviceChangeCallback (OH_AudioRoutingManager *audioRoutingManager, OH_AudioDevice_Flag deviceFlag, OH_AudioRoutingManager_OnDeviceChangedCallback callback)
```

**描述**
注册音频路由管理器的设备更改回调。
**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioRoutingManager | 音频路由管理器句柄[OH_AudioRoutingManager](#oh_audioroutingmanager)。通过[OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager)获取句柄。 | 
| deviceFlag | 音频设备标志[OH_AudioDevice_Flag](#oh_audiodevice_flag)，用来注册回调。 | 
| callback | 函数指针将指向用于返回更改的音频设备描述符的回调函数[OH_AudioRoutingManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback)。 | 

**返回：**

函数返回值[OH_AudioCommon_Result](#oh_audiocommon_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：

  1. 参数audioRoutingManager为nullptr；
  2. 参数deviceFlag无效；
  3. 参数callback为nullptr。


### OH_AudioRoutingManager_ReleaseDevices()

```
OH_AudioCommon_Result OH_AudioRoutingManager_ReleaseDevices (OH_AudioRoutingManager *audioRoutingManager, OH_AudioDeviceDescriptorArray *audioDeviceDescriptorArray)
```
**描述**
释放音频设备描述符数组对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioRoutingManager | 音频路由管理器句柄[OH_AudioRoutingManager](#oh_audioroutingmanager)。通过[OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager)获取句柄。 | 
| audioDeviceDescriptorArray | 音频设备描述符数组应当被释放，调用[OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices)获取。 | 

**返回：**

函数返回值[OH_AudioCommon_Result](#oh_audiocommon_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：

  1. 参数audioRoutingManager为nullptr；
  2. 参数audioDeviceDescriptorArray为nullptr。


### OH_AudioRoutingManager_SetMicBlockStatusCallback()

```
OH_AudioCommon_Result OH_AudioRoutingManager_SetMicBlockStatusCallback(OH_AudioRoutingManager *audioRoutingManager OH_AudioRoutingManager_OnDeviceBlockStatusCallback callback, void *userData)
```
**描述**
设置麦克风是否堵塞状态回调。

在使用此功能之前，用户应查询当前设备是否支持检测，应用只有在使用麦克风录音时，并且所使用的麦克风的堵塞状态发生改变，才会收到回调，目前此检测功能仅支持麦克风位于本地设备上。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioRoutingManager | 音频路由管理器句柄[OH_AudioRoutingManager](#oh_audioroutingmanager)。获取句柄通过[OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager)。  | 
| callback | 函数指针将指向用于返回接受设备麦克风堵塞状态 [OH_AudioRoutingManager_OnDeviceBlockStatusCallback](#oh_audioroutingmanager_ondeviceblockstatuscallback) | 
| userData | 用户自定义数据指针。  | 

**返回：**

函数返回值[OH_AudioCommon_Result](#oh_audiocommon_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：

1. 参数audioRoutingManager为nullptr； 
2. 参数callback为nullptr。


### OH_AudioRoutingManager_UnregisterDeviceChangeCallback()

```
OH_AudioCommon_Result OH_AudioRoutingManager_UnregisterDeviceChangeCallback (OH_AudioRoutingManager *audioRoutingManager, OH_AudioRoutingManager_OnDeviceChangedCallback callback)
```
**描述**
取消注册音频路由管理器的设备更改回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioRoutingManager | 音频路由管理器句柄[OH_AudioRoutingManager](#oh_audioroutingmanager)。通过[OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager)获取句柄。 | 
| callback | 函数指针将指向用于返回更改的音频设备描述符的回调函数[OH_AudioRoutingManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback)。 | 

**返回：**

函数返回值[OH_AudioCommon_Result](#oh_audiocommon_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：

  1. 参数audioRoutingManager为nullptr；
  2. 参数callback为nullptr。


### OH_AudioSessionManager_ActivateAudioSession()

```
OH_AudioCommon_Result OH_AudioSessionManager_ActivateAudioSession (OH_AudioSessionManager *audioSessionManager, const OH_AudioSession_Strategy *strategy )
```
**描述**
激活音频会话。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioSessionManager | 指向[OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager)创建的音频会话管理实例：[OH_AudioSessionManager](#oh_audiosessionmanager)。  | 
| strategy | 指向[OH_AudioSession_Strategy](_o_h___audio_session___strategy.md)用于设置音频会话策略。  | 

**返回：**

函数返回值[OH_AudioCommon_Result](#oh_audiocommon_result)：

AUDIOCOMMON_RESULT_SUCCESS 函数执行成功。 

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：

1. 参数audioSessionManager为nullptr；
2. 参数strategy无效。 AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE 非法状态。 


### OH_AudioSessionManager_DeactivateAudioSession()

```
OH_AudioCommon_Result OH_AudioSessionManager_DeactivateAudioSession (OH_AudioSessionManager *audioSessionManager)
```
**描述**
停用音频会话。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioSessionManager | 指向[OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager)创建的音频会话管理实例：[OH_AudioSessionManager](#oh_audiosessionmanager)。  | 

**返回：**

函数返回值[OH_AudioCommon_Result](#oh_audiocommon_result)：

AUDIOCOMMON_RESULT_SUCCESS 函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数audioSessionManager为nullptr。 

AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE 非法状态。


### OH_AudioSessionManager_IsAudioSessionActivated()

```
bool OH_AudioSessionManager_IsAudioSessionActivated (OH_AudioSessionManager *audioSessionManager)
```
**描述**
检查音频会话是否已激活。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioSessionManager | 指向[OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager)创建的音频会话管理实例：[OH_AudioSessionManager](#oh_audiosessionmanager)。  | 

**返回：**

用于返回当前应用的音频会话是否已激活，true表示已激活，false表示已停用。


### OH_AudioSessionManager_RegisterSessionDeactivatedCallback()

```
OH_AudioCommon_Result OH_AudioSessionManager_RegisterSessionDeactivatedCallback (OH_AudioSessionManager *audioSessionManager, OH_AudioSession_DeactivatedCallback callback)
```
**描述**
注册音频会话停用事件回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioSessionManager | 指向[OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager)创建的音频会话管理实例 [OH_AudioSessionManager](#oh_audiosessionmanager)。  | 
| callback | 指向[OH_AudioSessionDeactivatedCallback](#oh_audiosession_deactivatedcallback)，用于接收音频会话已停用事件。  | 

**返回：**

函数返回值[OH_AudioCommon_Result](#oh_audiocommon_result)：

AUDIOCOMMON_RESULT_SUCCESS 函数执行成功。 

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：

1. 参数audioSessionManager为nullptr；
2. 参数callback为nullptr。 


### OH_AudioSessionManager_UnregisterSessionDeactivatedCallback()

```
OH_AudioCommon_Result OH_AudioSessionManager_UnregisterSessionDeactivatedCallback (OH_AudioSessionManager *audioSessionManager, OH_AudioSession_DeactivatedCallback callback)
```
**描述**
取消注册音频会话停用事件回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioSessionManager | 指向[OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager)创建的音频会话管理实例 [OH_AudioSessionManager](#oh_audiosessionmanager)。  | 
| callback | 指向[OH_AudioSessionDeactivatedCallback](#oh_audiosession_deactivatedcallback)，用于接收音频会话已停用事件。  | 

**返回：**

函数返回值[OH_AudioCommon_Result](#oh_audiocommon_result)：

AUDIOCOMMON_RESULT_SUCCESS 函数执行成功。 

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：

1. 参数audioSessionManager为nullptr；
2. 参数callback为nullptr。 


### OH_AudioStreamBuilder_Create()

```
OH_AudioStream_Result OH_AudioStreamBuilder_Create(OH_AudioStreamBuilder **builder, OH_AudioStream_Type type)
```
**描述**
创建一个输入或者输出类型的音频流构造器。

当构造器不再使用时，需要调用OH_AudioStreamBuilder_Destroy()销毁它。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 该引用指向创建的构造器的结果。  | 
| type | 构造器的流类型。AUDIOSTREAM_TYPE_RENDERER or AUDIOSTREAM_TYPE_CAPTURER | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。


### OH_AudioStreamBuilder_Destroy()

```
OH_AudioStream_Result OH_AudioStreamBuilder_Destroy(OH_AudioStreamBuilder *builder)
```
**描述**
销毁一个音频流构造器。

当构造器不再使用时，需要调用该函数销毁它。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOSTREAM_ERROR_INVALID_PARAM：参数builder为nullptr。

AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。


### OH_AudioStreamBuilder_GenerateCapturer()

```
OH_AudioStream_Result OH_AudioStreamBuilder_GenerateCapturer(OH_AudioStreamBuilder *builder, OH_AudioCapturer **audioCapturer)
```
**描述**
创建输入音频流实例。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。  | 
| audioCapturer | 指向输入音频流实例的指针，将被用来接收函数创建的结果。  | 

**需要权限：**

ohos.permission.MICROPHONE

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOSTREAM_ERROR_INVALID_PARAM：

  1. 参数builder为nullptr；
  2. StreamType无效；
  3. 创建OHAudioCapturer失败。


### OH_AudioStreamBuilder_GenerateRenderer()

```
OH_AudioStream_Result OH_AudioStreamBuilder_GenerateRenderer(OH_AudioStreamBuilder *builder, OH_AudioRenderer **audioRenderer)
```
**描述**
创建输出音频流实例。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。  | 
| audioRenderer | 指向输出音频流实例的指针，将被用来接收函数创建的结果。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOSTREAM_ERROR_INVALID_PARAM：

  1. 参数builder为nullptr；
  2. StreamType无效；
  3. 创建OHAudioRenderer失败。


### OH_AudioStreamBuilder_SetCapturerCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerCallback(OH_AudioStreamBuilder *builder, OH_AudioCapturer_Callbacks callbacks, void *userData)
```
**描述**
设置输入音频流的回调。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。  | 
| callbacks | 将被用来处理输入音频流相关事件的回调函数。  | 
| userData | 指向通过回调函数传递的应用数据指针。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOSTREAM_ERROR_INVALID_PARAM：

  1. 参数builder为nullptr；
  2. StreamType无效。


### OH_AudioStreamBuilder_SetCapturerInfo()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerInfo(OH_AudioStreamBuilder *builder, OH_AudioStream_SourceType sourceType)
```
**描述**
设置输入音频流的工作场景。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。  | 
| sourceType | 输入音频流属性，使用的工作场景。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOSTREAM_ERROR_INVALID_PARAM：

  1. 参数builder为nullptr；
  2. 参数sourceType无效。


### OH_AudioStreamBuilder_SetChannelCount()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetChannelCount(OH_AudioStreamBuilder *builder, int32_t channelCount)
```
**描述**
设置音频流的通道数属性。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。  | 
| channelCount | 音频流通道数。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOSTREAM_ERROR_INVALID_PARAM：

  1. 参数builder为nullptr；
  2. 参数channelCount无效。


### OH_AudioStreamBuilder_SetChannelLayout()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetChannelLayout (OH_AudioStreamBuilder *builder, OH_AudioChannelLayout channelLayout)
```
**描述**
设置音频流的声道布局。

**起始版本：** 12

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。  | 
| channelLayout | 音频流声道布局，具体参考[OH_AudioChannelLayout](../apis-avcodec-kit/_core.md#oh_audiochannellayout-1)。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOSTREAM_ERROR_INVALID_PARAM：参数builder为nullptr。


### OH_AudioStreamBuilder_SetEncodingType()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetEncodingType(OH_AudioStreamBuilder *builder, OH_AudioStream_EncodingType encodingType)
```
**描述**
设置音频流的编码类型属性。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。 | 
| encodingType | 音频流编码类型。 | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOSTREAM_ERROR_INVALID_PARAM：参数builder为nullptr。

### OH_AudioStreamBuilder_SetFrameSizeInCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetFrameSizeInCallback(OH_AudioStreamBuilder *builder, int32_t frameSize)
```
**描述**
用于播放时设置每次回调的帧长，帧长至少为音频硬件一次处理的数据大小，并且小于内部缓冲容量的一半。

- 低时延播放：frameSize可设置为5ms、10ms、15ms、20ms音频数据对应的帧长。
- 普通通路播放：frameSize可设置为20ms-100ms音频数据对应的帧长。

**起始版本：** 11

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。  | 
| frameSize | 要设置音频数据的帧长。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOSTREAM_ERROR_INVALID_PARAM：参数builder为nullptr。


### OH_AudioStreamBuilder_SetLatencyMode()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetLatencyMode(OH_AudioStreamBuilder *builder, OH_AudioStream_LatencyMode latencyMode)
```
**描述**
设置音频流的时延模式。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。  | 
| latencyMode | 音频流时延模式。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOSTREAM_ERROR_INVALID_PARAM：参数builder为nullptr。


### OH_AudioStreamBuilder_SetRendererCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererCallback(OH_AudioStreamBuilder *builder, OH_AudioRenderer_Callbacks callbacks, void *userData)
```
**描述**
设置输出音频流的回调。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。  | 
| callbacks | 将被用来处理输出音频流相关事件的回调函数。  | 
| userData | 指向通过回调函数传递的应用数据指针。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOSTREAM_ERROR_INVALID_PARAM：

  1. 参数builder为nullptr；
  2. StreamType无效。


### OH_AudioStreamBuilder_SetRendererInfo()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInfo(OH_AudioStreamBuilder *builder, OH_AudioStream_Usage usage)
```
**描述**
设置输出音频流的工作场景。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。  | 
| usage | 输出音频流属性，使用的工作场景。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOSTREAM_ERROR_INVALID_PARAM：

  1. 参数builder为nullptr；
  2. 参数usage无效。


### OH_AudioStreamBuilder_SetRendererInterruptMode()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInterruptMode (OH_AudioStreamBuilder *builder, OH_AudioInterrupt_Mode mode)
```
**描述**
设置流客户端的中断模式。

**起始版本：** 12

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。  | 
| mode | 音频中断模式[OH_AudioInterrupt_Mode](#oh_audiointerrupt_mode)。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOSTREAM_ERROR_INVALID_PARAM：

  1. 参数builder为nullptr；
  2. 参数mode无效；
  3. StreamType无效。


### OH_AudioStreamBuilder_SetRendererOutputDeviceChangeCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererOutputDeviceChangeCallback (OH_AudioStreamBuilder * builder, OH_AudioRenderer_OutputDeviceChangeCallback callback, void * userData )
```
**描述**
设置输出音频流设备变更的回调。

**起始版本：** 11

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。  | 
| callbacks | 将被用来处理输出流设备变更相关事件的回调函数。  | 
| userData | 指向通过回调函数传递的应用数据指针。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOSTREAM_ERROR_INVALID_PARAM：

  1. 参数builder为nullptr；
  2. StreamType无效。


### OH_AudioStreamBuilder_SetRendererPrivacy()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererPrivacy (OH_AudioStreamBuilder * builder, OH_AudioStream_PrivacyType privacy)
```
**描述**
设置当前播放音频流是否会被其它应用录制。

**起始版本：** 12

**系统能力：** SystemCapability.Multimedia.Audio.PlaybackCapture

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向[OH_AudioStreamBuilder_Create()](#oh_audiostreambuilder_create)创建的构造器实例。  | 
| privacy | 标识对应播放音频流是否会被其它应用录制。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOSTREAM_ERROR_INVALID_PARAM：

  1. 参数builder为nullptr；
  2. StreamType无效。


### OH_AudioStreamBuilder_SetRendererWriteDataCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererWriteDataCallback (OH_AudioStreamBuilder *builder, OH_AudioRenderer_OnWriteDataCallback callback, void *userData)
```
**描述**
设置写入音频数据的回调。

该函数类似于 [OH_AudioStreamBuilder_SetRendererCallback](#oh_audiostreambuilder_setrenderercallback)。只有通过 OH_AudioStreamBuilder_SetRendererCallback或者此函数设置的最后一个回调函数才会被调用。

**起始版本：** 12

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。  | 
| callback | 将被用来写入音频数据的回调函数。  | 
| userData | 指向通过回调函数传递的应用数据指针。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOSTREAM_SUCCESS：函数执行成功。 

AUDIOSTREAM_ERROR_INVALID_PARAM：

  1. 参数builder为nullptr；
  2. StreamType无效。 


### OH_AudioStreamBuilder_SetSampleFormat()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetSampleFormat(OH_AudioStreamBuilder *builder, OH_AudioStream_SampleFormat format)
```
**描述**
设置音频流的采样格式属性。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。  | 
| format | 音频流采样格式。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOSTREAM_ERROR_INVALID_PARAM：参数builder为nullptr。


### OH_AudioStreamBuilder_SetSamplingRate()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetSamplingRate(OH_AudioStreamBuilder *builder, int32_t rate)
```
**描述**
设置音频流的采样率属性。

**起始版本：** 10

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。  | 
| channelCount | 音频流采样率。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOSTREAM_ERROR_INVALID_PARAM：

  1. 参数builder为nullptr；
  2. 参数rate无效。


### OH_AudioStreamBuilder_SetWriteDataWithMetadataCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetWriteDataWithMetadataCallback (OH_AudioStreamBuilder *builder, OH_AudioRenderer_WriteDataWithMetadataCallback callback, void *userData)
```
**描述**
设置同时写入音频数据和元数据的回调。

**起始版本：** 12

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| builder | 指向OH_AudioStreamBuilder_Create()创建的构造器实例。  | 
| callback | 将被用来同时写入音频数据和元数据的回调函数。  | 
| userData | 指向通过回调函数传递的应用数据指针。  | 

**返回：**

函数返回值[OH_AudioStream_Result](#oh_audiostream_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOSTREAM_ERROR_INVALID_PARAM：

  1. 参数builder为nullptr；
  2. StreamType无效。


### OH_GetAudioManager()

```
OH_AudioCommon_Result OH_GetAudioManager (OH_AudioManager ** audioManager)
```
**描述**
获取音频管理器。

使用音频管理器相关功能，首先需要获取音频管理器实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioManager | 指向[OH_AudioManager](#oh_audiomanager)用于接收创建的音频管理器实例。  | 

**返回：**

函数返回值[OH_AudioCommon_Result](#oh_audiocommon_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数audioManager为nullptr。


### OH_GetAudioScene()

```
OH_AudioCommon_Result OH_GetAudioScene (OH_AudioManager * manager, OH_AudioScene * scene )
```
**描述**
获取音频场景模式。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| audioManager | 指向[OH_GetAudioManager](#oh_getaudiomanager)创建的音频管理器实例：[OH_AudioManager](#oh_audiomanager)。  | 
| scene | 指向[OH_AudioScene](#oh_audioscene)用于接收返回的音频场景模式。  | 

**返回：**

函数返回值[OH_AudioCommon_Result](#oh_audiocommon_result)：

AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。 

AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：

1. 参数audioManager为nullptr; 
2. 参数scene为nullptr。
