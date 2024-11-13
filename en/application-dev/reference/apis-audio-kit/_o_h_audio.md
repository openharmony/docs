# OHAudio


## Overview

The **OHAudio** module provides C APIs of the audio module.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [native_audio_common.h](native__audio__common_8h.md) | Declares the common basic audio data structs. |
| [native_audio_device_base.h](native__audio__device__base_8h.md) | Declares the types of audio device parameters and the functions for obtaining these parameters. |
| [native_audio_manager.h](native__audio__manager_8h.md) | Declares the functions related to an audio manager. |
| [native_audio_routing_manager.h](native__audio__routing__manager_8h.md) | Declares the functions related to an audio routing manager. |
| [native_audio_session_manager.h](native__audio__session__manager_8h.md) | Declares the functions related to an audio session manager. |
| [native_audiocapturer.h](native__audiocapturer_8h.md) | Declares the functions related to an audio capturer. |
| [native_audiorenderer.h](native__audiorenderer_8h.md) | Declares the functions related to an audio renderer. |
| [native_audiostream_base.h](native__audiostream__base_8h.md) | Declares the basic data structure of **OHAudio**. |
| [native_audiostreambuilder.h](native__audiostreambuilder_8h.md) | Declares the functions related to an audio stream builder. |


### Structs

| Name| Description|
| -------- | -------- |
| struct  [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) | Describes an array of audio device descriptors. |
| struct  [OH_AudioSession_Strategy](_o_h___audio_session___strategy.md) | Describes the audio session strategy. |
| struct  [OH_AudioSession_DeactivatedEvent](_o_h___audio_session___deactivated_event.md) | Describes the event indicating that an audio session is deactivated. |
| struct  [OH_AudioRenderer_Callbacks_Struct](_o_h___audio_renderer___callbacks___struct.md) | Describes a pointer to the callback functions related to an audio renderer. |
| struct  [OH_AudioCapturer_Callbacks_Struct](_o_h___audio_capturer___callbacks___struct.md) | Describes a pointer to the callback functions related to an audio capturer. |


### Types

| Name| Description|
| -------- | -------- |
| typedef struct [OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) [OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) | Defines a struct for an audio device descriptor. It provides detailed attributes of an audio device. |
| typedef struct [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) [OH_AudioDeviceDescriptorArray](#oh_audiodevicedescriptorarray) | Defines a struct for an array of audio device descriptors. |
| typedef struct [OH_AudioManager](#oh_audiomanager) [OH_AudioManager](#oh_audiomanager) | Defines a struct for an audio manager. |
| typedef struct [OH_AudioRoutingManager](#oh_audioroutingmanager) [OH_AudioRoutingManager](#oh_audioroutingmanager) | Defines a struct for an audio routing manager, which is used for routing and device-related functions. |
| typedef int32_t(\* [OH_AudioRoutingManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback))([OH_AudioDevice_ChangeType](#oh_audiodevice_changetype) type, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*audioDeviceDescriptorArray) | Defines a pointer to the callback function that returns the changed audio device descriptor (possibly multiple descriptors). |
| typedef struct [OH_AudioSessionManager](#oh_audiosessionmanager) [OH_AudioSessionManager](#oh_audiosessionmanager) | Defines a struct for an audio session manager. |
| typedef struct [OH_AudioSession_Strategy](_o_h___audio_session___strategy.md) [OH_AudioSession_Strategy](#oh_audiosession_strategy) | Defines a struct for an audio session strategy. |
| typedef struct [OH_AudioSession_DeactivatedEvent](_o_h___audio_session___deactivated_event.md) [OH_AudioSession_DeactivatedEvent](#oh_audiosession_deactivatedevent) | Defines a struct for the event indicating that an audio session is deactivated. |
| typedef int32_t(\* [OH_AudioSession_DeactivatedCallback](#oh_audiosession_deactivatedcallback))([OH_AudioSession_DeactivatedEvent](_o_h___audio_session___deactivated_event.md) event) | Defines a function pointer to the callback function used to listen for audio session deactivation events. |
| typedef struct OH_AudioStreamBuilderStruct [OH_AudioStreamBuilder](#oh_audiostreambuilder) | Defines a struct for an audio stream builder. |
| typedef struct OH_AudioRendererStruct [OH_AudioRenderer](#oh_audiorenderer) | Defines a struct for an audio renderer. |
| typedef struct OH_AudioCapturerStruct [OH_AudioCapturer](#oh_audiocapturer) | Defines a struct for an audio capturer. |
| typedef struct [OH_AudioRenderer_Callbacks_Struct](_o_h___audio_renderer___callbacks___struct.md) [OH_AudioRenderer_Callbacks](#oh_audiorenderer_callbacks) | Defines a pointer to the callback functions related to an audio renderer. |
| typedef struct [OH_AudioCapturer_Callbacks_Struct](_o_h___audio_capturer___callbacks___struct.md) [OH_AudioCapturer_Callbacks](#oh_audiocapturer_callbacks) | Defines a pointer to the callback functions related to an audio capturer. |
| typedef void(\* [OH_AudioRenderer_OutputDeviceChangeCallback](#oh_audiorenderer_outputdevicechangecallback))([OH_AudioRenderer](#oh_audiorenderer) \*renderer, void \*userData, [OH_AudioStream_DeviceChangeReason](#oh_audiostream_devicechangereason) reason) | Defines a pointer to the callback invoked when the audio stream device changes. |
| typedef void(\* [OH_AudioRenderer_OnMarkReachedCallback](#oh_audiorenderer_onmarkreachedcallback))([OH_AudioRenderer](#oh_audiorenderer) \*renderer, uint32_t samplePos, void \*userData) | Defines a pointer to the callback invoked when the mark position is reached. |
| typedef int32_t(\* [OH_AudioRenderer_WriteDataWithMetadataCallback](#oh_audiorenderer_writedatawithmetadatacallback))([OH_AudioRenderer](#oh_audiorenderer) \*renderer, void \*userData, void \*audioData, int32_t audioDataSize, void \*metadata, int32_t metadataSize) | Defines a function pointer to the callback function used to write audio data and metadata. |
| typedef [OH_AudioData_Callback_Result](#oh_audiodata_callback_result)(\* [OH_AudioRenderer_OnWriteDataCallback](#oh_audiorenderer_onwritedatacallback))([OH_AudioRenderer](#oh_audiorenderer) \*renderer, void \*userData, void \*audioData, int32_t audioDataSize) | Defines a function pointer to the callback function used to write audio data. |


### Enums

| Name| Description|
| -------- | -------- |
| [OH_AudioCommon_Result](#oh_audiocommon_result) {<br>AUDIOCOMMON_RESULT_SUCCESS = 0,<br>AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM = 6800101,<br>AUDIOCOMMON_RESULT_ERROR_NO_MEMORY = 6800102,<br>AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE = 6800103,<br>AUDIOCOMMON_RESULT_ERROR_UNSUPPORTED = 6800104,<br>AUDIOCOMMON_RESULT_ERROR_TIMEOUT = 6800105,<br>AUDIOCOMMON_RESULT_ERROR_STREAM_LIMIT = 6800201,<br>AUDIOCOMMON_RESULT_ERROR_SYSTEM = 6800301<br>} | Enumerates the audio operation results.|
| [OH_AudioScene](#oh_audioscene) { <br>AUDIO_SCENE_DEFAULT = 0, <br>AUDIO_SCENE_RINGING = 1, <br>AUDIO_SCENE_PHONE_CALL = 2, <br>AUDIO_SCENE_VOICE_CHAT = 3 } | Enumerates the audio scenes. |
| [OH_AudioDevice_ChangeType](#oh_audiodevice_changetype) {<br>AUDIO_DEVICE_CHANGE_TYPE_CONNECT = 0,<br>AUDIO_DEVICE_CHANGE_TYPE_DISCONNECT = 1<br>} | Enumerates the types of audio device changes.|
| [OH_AudioDevice_Role](#oh_audiodevice_role) {<br>AUDIO_DEVICE_ROLE_INPUT = 1,<br>AUDIO_DEVICE_ROLE_OUTPUT = 2<br>} | Enumerates the roles of audio devices.|
| [OH_AudioDevice_Type](#oh_audiodevice_type) {<br>AUDIO_DEVICE_TYPE_INVALID = 0,<br>AUDIO_DEVICE_TYPE_EARPIECE = 1,<br>AUDIO_DEVICE_TYPE_SPEAKER = 2,<br>AUDIO_DEVICE_TYPE_WIRED_HEADSET = 3,<br>AUDIO_DEVICE_TYPE_WIRED_HEADPHONES = 4,<br>AUDIO_DEVICE_TYPE_BLUETOOTH_SCO = 7,<br>AUDIO_DEVICE_TYPE_BLUETOOTH_A2DP = 8,<br>AUDIO_DEVICE_TYPE_MIC = 15,<br>AUDIO_DEVICE_TYPE_USB_HEADSET = 22,<br>AUDIO_DEVICE_TYPE_DISPLAY_PORT = 23,<br>AUDIO_DEVICE_TYPE_REMOTE_CAST = 24,<br>AUDIO_DEVICE_TYPE_DEFAULT = 1000<br>} | Enumerates the types of audio devices.|
| [OH_AudioDevice_Flag](#oh_audiodevice_flag) {<br>AUDIO_DEVICE_FLAG_NONE = 0,<br>AUDIO_DEVICE_FLAG_OUTPUT = 1,<br>AUDIO_DEVICE_FLAG_INPUT = 2,<br>AUDIO_DEVICE_FLAG_ALL = 3<br>} | Enumerates the flags of audio devices.|
| [OH_AudioDevice_Usage](#oh_audiodevice_usage) {<br>AUDIO_DEVICE_USAGE_MEDIA_OUTPUT = 1, <br>AUDIO_DEVICE_USAGE_MEDIA_INPUT = 2, <br>AUDIO_DEVICE_USAGE_MEDIA_ALL = 3, <br>AUDIO_DEVICE_USAGE_CALL_OUTPUT = 4,<br>AUDIO_DEVICE_USAGE_CALL_INPUT = 8, <br>AUDIO_DEVICE_USAGE_CALL_ALL = 12<br>} | Enumerates the usage scenarios of audio devices. |
| [OH_AudioSession_ConcurrencyMode](#oh_audiosession_concurrencymode) { <br>CONCURRENCY_DEFAULT = 0, <br>CONCURRENCY_MIX_WITH_OTHERS = 1, <br>CONCURRENCY_DUCK_OTHERS = 2, <br>CONCURRENCY_PAUSE_OTHERS = 3 } | Enumerates the audio concurrency modes. |
| [OH_AudioSession_DeactivatedReason](#oh_audiosession_deactivatedreason) { <br>DEACTIVATED_LOWER_PRIORITY = 0, <br>DEACTIVATED_TIMEOUT = 1 } | Enumerates the reasons for deactivating an audio session. |
| [OH_AudioStream_Result](#oh_audiostream_result) {<br>AUDIOSTREAM_SUCCESS = 0,<br>AUDIOSTREAM_ERROR_INVALID_PARAM = 1,<br>AUDIOSTREAM_ERROR_ILLEGAL_STATE = 2,<br>AUDIOSTREAM_ERROR_SYSTEM = 3<br>} | Enumerates the audio stream operation results.|
| [OH_AudioStream_Type](#oh_audiostream_type) {<br>AUDIOSTREAM_TYPE_RENDERER = 1,<br>AUDIOSTREAM_TYPE_CAPTURER = 2<br>} | Enumerates the audio stream types.|
| [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) {<br>AUDIOSTREAM_SAMPLE_U8 = 0,<br>AUDIOSTREAM_SAMPLE_S16LE = 1,<br>AUDIOSTREAM_SAMPLE_S24LE = 2,<br>AUDIOSTREAM_SAMPLE_S32LE = 3<br>} | Enumerates the sampling formats of audio streams.|
| [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) { <br>AUDIOSTREAM_ENCODING_TYPE_RAW = 0, <br>AUDIOSTREAM_ENCODING_TYPE_AUDIOVIVID = 1 <br>} | Enumerates the encoding types of audio streams. |
| [OH_AudioStream_Usage](#oh_audiostream_usage) {<br>AUDIOSTREAM_USAGE_UNKNOWN = 0,<br>AUDIOSTREAM_USAGE_MUSIC = 1,<br>AUDIOSTREAM_USAGE_VOICE_COMMUNICATION = 2,<br>AUDIOSTREAM_USAGE_VOICE_ASSISTANT = 3,<br>AUDIOSTREAM_USAGE_ALARM = 4,<br>AUDIOSTREAM_USAGE_VOICE_MESSAGE = 5,<br>AUDIOSTREAM_USAGE_RINGTONE = 6,<br>AUDIOSTREAM_USAGE_NOTIFICATION = 7,<br>AUDIOSTREAM_USAGE_ACCESSIBILITY = 8,<br>AUDIOSTREAM_USAGE_MOVIE = 10,<br>AUDIOSTREAM_USAGE_GAME = 11,<br>AUDIOSTREAM_USAGE_AUDIOBOOK = 12,<br>AUDIOSTREAM_USAGE_NAVIGATION = 13,<br>AUDIOSTREAM_USAGE_VIDEO_COMMUNICATION = 17<br>} | Enumerates the usage scenarios of audio streams.|
| [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) {<br>AUDIOSTREAM_LATENCY_MODE_NORMAL = 0,<br>AUDIOSTREAM_LATENCY_MODE_FAST = 1<br>} | Enumerates the latency modes of audio streams.|
| [OH_AudioStream_State](#oh_audiostream_state) {<br>AUDIOSTREAM_STATE_INVALID = -1,<br>AUDIOSTREAM_STATE_NEW = 0,<br>AUDIOSTREAM_STATE_PREPARED = 1,<br>AUDIOSTREAM_STATE_RUNNING = 2,<br>AUDIOSTREAM_STATE_STOPPED = 3,<br>AUDIOSTREAM_STATE_RELEASED = 4,<br>AUDIOSTREAM_STATE_PAUSED = 5<br>} | Enumerates the audio stream states.|
| [OH_AudioStream_SourceType](#oh_audiostream_sourcetype) {<br>AUDIOSTREAM_SOURCE_TYPE_INVALID = -1,<br>AUDIOSTREAM_SOURCE_TYPE_MIC = 0,<br>AUDIOSTREAM_SOURCE_TYPE_VOICE_RECOGNITION = 1,<br>AUDIOSTREAM_SOURCE_TYPE_PLAYBACK_CAPTURE = 2,<br>AUDIOSTREAM_SOURCE_TYPE_VOICE_COMMUNICATION = 7<br>} | Enumerates the usage scenarios of audio streams.|
| [OH_AudioStream_Event](#oh_audiostream_event) {<br>AUDIOSTREAM_EVENT_ROUTING_CHANGED = 0<br>} | Enumerates the audio stream events.|
| [OH_AudioInterrupt_ForceType](#oh_audiointerrupt_forcetype) {<br>AUDIOSTREAM_INTERRUPT_FORCE = 0,<br>AUDIOSTREAM_INTERRUPT_SHARE = 1<br>} | Enumerates the types of force that causes audio interruption.|
| [OH_AudioInterrupt_Hint](#oh_audiointerrupt_hint) {<br>AUDIOSTREAM_INTERRUPT_HINT_NONE = 0,<br>AUDIOSTREAM_INTERRUPT_HINT_RESUME = 1,<br>AUDIOSTREAM_INTERRUPT_HINT_PAUSE = 2,<br>AUDIOSTREAM_INTERRUPT_HINT_STOP = 3,<br>AUDIOSTREAM_INTERRUPT_HINT_DUCK = 4,<br>AUDIOSTREAM_INTERRUPT_HINT_UNDUCK = 5<br>} | Enumerates the hints provided along with audio interruption.|
| [OH_AudioInterrupt_Mode](#oh_audiointerrupt_mode) {<br> AUDIOSTREAM_INTERRUPT_MODE_SHARE = 0, <br>AUDIOSTREAM_INTERRUPT_MODE_INDEPENDENT = 1 <br>} | Enumerates the audio interruption modes. |
| [OH_AudioStream_AudioEffectMode](#oh_audiostream_audioeffectmode) { <br>EFFECT_NONE = 0, <br>EFFECT_DEFAULT = 1 <br>} | Enumerates the audio effect modes. |
| [OH_AudioStream_DeviceChangeReason](#oh_audiostream_devicechangereason) {<br>REASON_UNKNOWN = 0,<br>REASON_NEW_DEVICE_AVAILABLE = 1,<br>REASON_OLD_DEVICE_UNAVAILABLE = 2,<br>REASON_OVERRODE = 3<br>} | Enumerates the reasons for audio stream device changes.|
| [OH_AudioStream_PrivacyType](#oh_audiostream_privacytype) { <br>AUDIO_STREAM_PRIVACY_TYPE_PUBLIC = 0, <br>AUDIO_STREAM_PRIVACY_TYPE_PRIVATE = 1 <br>} | Enumerates the privacy types of an audio stream. The privacy type specifies whether the audio stream can be recorded by other applications. |
| [OH_AudioData_Callback_Result](#oh_audiodata_callback_result) { <br>AUDIO_DATA_CALLBACK_RESULT_INVALID = -1, <br>AUDIO_DATA_CALLBACK_RESULT_VALID = 0 <br>} | Enumerates the audio data callback results. |


### Functions

| Name| Description|
| -------- | -------- |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceRole](#oh_audiodevicedescriptor_getdevicerole)([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, [OH_AudioDevice_Role](#oh_audiodevice_role) \*deviceRole) | Obtains the device role based on an audio device descriptor. |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceType](#oh_audiodevicedescriptor_getdevicetype)([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, [OH_AudioDevice_Type](#oh_audiodevice_type) \*deviceType) | Obtains the device type based on an audio device descriptor. |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceId](#oh_audiodevicedescriptor_getdeviceid)([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, uint32_t \*id) | Obtains the device ID based on an audio device descriptor. |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceName](#oh_audiodevicedescriptor_getdevicename)([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, char \*\*name) | Obtains the device name based on an audio device descriptor. |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceAddress](#oh_audiodevicedescriptor_getdeviceaddress)([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, char \*\*address) | Obtains the device address based on an audio device descriptor. |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceSampleRates](#oh_audiodevicedescriptor_getdevicesamplerates)([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, uint32_t \*\*sampleRates, uint32_t \*size) | Obtains the sample rates based on an audio device descriptor. |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceChannelCounts](#oh_audiodevicedescriptor_getdevicechannelcounts)([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, uint32_t \*\*channelCounts, uint32_t \*size) | Obtains an array that holds the number of device channels based on an audio device descriptor. |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceDisplayName](#oh_audiodevicedescriptor_getdevicedisplayname)([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, char \*\*displayName) | Obtains the device display name based on an audio device descriptor. |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceEncodingTypes](#oh_audiodevicedescriptor_getdeviceencodingtypes)([OH_AudioDeviceDescriptor](#oh_audiodevicedescriptor) \*audioDeviceDescriptor, [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) \*\*encodingTypes, uint32_t \*size) | Obtains the device encoding types based on an audio device descriptor. |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_GetAudioManager](#oh_getaudiomanager)([OH_AudioManager](#oh_audiomanager) \*\*audioManager) | Obtains an **OH_AudioManager** instance. |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_GetAudioScene](#oh_getaudioscene)([OH_AudioManager](#oh_audiomanager) \*manager, [OH_AudioScene](#oh_audioscene) \*scene) | Obtains the audio scene. |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager)([OH_AudioRoutingManager](#oh_audioroutingmanager) \*\*audioRoutingManager) | Obtains the handle to an audio routing manager. The handle should be set as the first parameter in the routing-related functions. |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices)([OH_AudioRoutingManager](#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioDevice_Flag](#oh_audiodevice_flag) deviceFlag, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*\*audioDeviceDescriptorArray) | Obtains available devices based on the device flag. |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioRoutingManager_GetAvailableDevices](#oh_audioroutingmanager_getavailabledevices)([OH_AudioRoutingManager](#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioDevice_Usage](#oh_audiodevice_usage) deviceUsage, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*\*audioDeviceDescriptorArray) | Obtains the available audio devices.  |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioRoutingManager_GetPreferredOutputDevice](#oh_audioroutingmanager_getpreferredoutputdevice)([OH_AudioRoutingManager](#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioStream_Usage](#oh_audiostream_usage) streamUsage, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*\*audioDeviceDescriptorArray) | Obtains the output device with the highest priority based on the usage scenario of an audio output stream. |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioRoutingManager_GetPreferredInputDevice](#oh_audioroutingmanager_getpreferredinputdevice)([OH_AudioRoutingManager](#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioStream_SourceType](#oh_audiostream_sourcetype) sourceType, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*\*audioDeviceDescriptorArray) | Obtains the input device with the highest priority based on the usage scenario of an audio input stream. |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioRoutingManager_RegisterDeviceChangeCallback](#oh_audioroutingmanager_registerdevicechangecallback)([OH_AudioRoutingManager](#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioDevice_Flag](#oh_audiodevice_flag) deviceFlag, [OH_AudioRoutingManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback) callback) | Registers a callback to listen for device changes of an audio routing manager. |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioRoutingManager_UnregisterDeviceChangeCallback](#oh_audioroutingmanager_unregisterdevicechangecallback)([OH_AudioRoutingManager](#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioRoutingManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback) callback) | Unregisters the callback used to listen for device changes of an audio routing manager. |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices)([OH_AudioRoutingManager](#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*audioDeviceDescriptorArray) | Releases audio devices available for an audio routing manager. |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager)([OH_AudioSessionManager](#oh_audiosessionmanager) \*\*audioSessionManager) | Obtains an **OH_AudioSessionManager** instance. |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioSessionManager_ActivateAudioSession](#oh_audiosessionmanager_activateaudiosession)([OH_AudioSessionManager](#oh_audiosessionmanager) \*audioSessionManager, const [OH_AudioSession_Strategy](_o_h___audio_session___strategy.md) \*strategy) | Activates an audio session. |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioSessionManager_DeactivateAudioSession](#oh_audiosessionmanager_deactivateaudiosession)([OH_AudioSessionManager](#oh_audiosessionmanager) \*audioSessionManager) | Deactivates an audio session. |
| bool [OH_AudioSessionManager_IsAudioSessionActivated](#oh_audiosessionmanager_isaudiosessionactivated)([OH_AudioSessionManager](#oh_audiosessionmanager) \*audioSessionManager) | Checks whether an audio session is activated. |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioSessionManager_RegisterSessionDeactivatedCallback](#oh_audiosessionmanager_registersessiondeactivatedcallback)([OH_AudioSessionManager](#oh_audiosessionmanager) \*audioSessionManager, [OH_AudioSession_DeactivatedCallback](#oh_audiosession_deactivatedcallback) callback) | Registers a callback to listen for audio session deactivation events. |
| [OH_AudioCommon_Result](#oh_audiocommon_result) [OH_AudioSessionManager_UnregisterSessionDeactivatedCallback](#oh_audiosessionmanager_unregistersessiondeactivatedcallback)([OH_AudioSessionManager](#oh_audiosessionmanager) \*audioSessionManager, [OH_AudioSession_DeactivatedCallback](#oh_audiosession_deactivatedcallback) callback) | Unregisters the callback used to listen for audio session deactivation events. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_Release](#oh_audiocapturer_release)([OH_AudioCapturer](#oh_audiocapturer) \*capturer) | Releases an audio capturer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_Start](#oh_audiocapturer_start)([OH_AudioCapturer](#oh_audiocapturer) \*capturer) | Starts an audio capturer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_Pause](#oh_audiocapturer_pause)([OH_AudioCapturer](#oh_audiocapturer) \*capturer) | Pauses an audio capturer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_Stop](#oh_audiocapturer_stop)([OH_AudioCapturer](#oh_audiocapturer) \*capturer) | Stops an audio capturer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_Flush](#oh_audiocapturer_flush)([OH_AudioCapturer](#oh_audiocapturer) \*capturer) | Flushes obtained audio data. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetCurrentState](#oh_audiocapturer_getcurrentstate)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_State](#oh_audiostream_state) \*state) | Obtains the state of an audio capturer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetLatencyMode](#oh_audiocapturer_getlatencymode)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) \*latencyMode) | Obtains the latency mode of an audio capturer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetStreamId](#oh_audiocapturer_getstreamid)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, uint32_t \*streamId) | Obtains the stream ID of an audio capturer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetSamplingRate](#oh_audiocapturer_getsamplingrate)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, int32_t \*rate) | Obtains the sampling rate of an audio capturer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetChannelCount](#oh_audiocapturer_getchannelcount)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, int32_t \*channelCount) | Obtains the number of channels for an audio capturer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetSampleFormat](#oh_audiocapturer_getsampleformat)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) \*sampleFormat) | Obtains the sampling format of an audio capturer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetEncodingType](#oh_audiocapturer_getencodingtype)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) \*encodingType) | Obtains the encoding type of an audio capturer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetCapturerInfo](#oh_audiocapturer_getcapturerinfo)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_SourceType](#oh_audiostream_sourcetype) \*sourceType) | Obtains the usage scenario of an audio capturer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetFrameSizeInCallback](#oh_audiocapturer_getframesizeincallback)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, int32_t \*frameSize) | Obtains the frame size in the callback. The frame size is the fixed length of the buffer returned by each callback. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetTimestamp](#oh_audiocapturer_gettimestamp)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, clockid_t clockId, int64_t \*framePosition, int64_t \*timestamp) | Obtains the timestamp and position information of an audio input stream. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetFramesRead](#oh_audiocapturer_getframesread)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, int64_t \*frames) | Obtains the number of frames that have been read since the stream was created. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetOverflowCount](#oh_audiocapturer_getoverflowcount)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, uint32_t \*count) | Obtains the number of overloaded audio streams of an audio capturer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_Release](#oh_audiorenderer_release)([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | Releases an audio renderer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_Start](#oh_audiorenderer_start)([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | Starts an audio renderer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_Pause](#oh_audiorenderer_pause)([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | Pauses an audio renderer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_Stop](#oh_audiorenderer_stop)([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | Stops an audio renderer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_Flush](#oh_audiorenderer_flush)([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | Flushes written audio data. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetCurrentState](#oh_audiorenderer_getcurrentstate)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_State](#oh_audiostream_state) \*state) | Obtains the state of an audio renderer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetSamplingRate](#oh_audiorenderer_getsamplingrate)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, int32_t \*rate) | Obtains the sampling rate of an audio renderer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetStreamId](#oh_audiorenderer_getstreamid)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, uint32_t \*streamId) | Obtains the stream ID of an audio renderer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetChannelCount](#oh_audiorenderer_getchannelcount)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, int32_t \*channelCount) | Obtains the number of channels for an audio renderer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetSampleFormat](#oh_audiorenderer_getsampleformat)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) \*sampleFormat) | Obtains the sampling format of an audio renderer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetLatencyMode](#oh_audiorenderer_getlatencymode)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) \*latencyMode) | Obtains the latency mode of an audio renderer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetRendererInfo](#oh_audiorenderer_getrendererinfo)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_Usage](#oh_audiostream_usage) \*usage) | Obtains the usage scenario of an audio renderer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetEncodingType](#oh_audiorenderer_getencodingtype)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) \*encodingType) | Obtains the encoding type of an audio renderer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetFramesWritten](#oh_audiorenderer_getframeswritten)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, int64_t \*frames) | Obtains the number of frames that have been written since the stream was created. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetTimestamp](#oh_audiorenderer_gettimestamp)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, clockid_t clockId, int64_t \*framePosition, int64_t \*timestamp) | Obtains the timestamp and position information of an audio output stream. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetFrameSizeInCallback](#oh_audiorenderer_getframesizeincallback)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, int32_t \*frameSize) | Obtains the frame size in the callback. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetSpeed](#oh_audiorenderer_getspeed)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, float \*speed) | Obtains the audio renderer rate. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetSpeed](#oh_audiorenderer_setspeed)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, float speed) | Sets the audio renderer rate. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetMarkPosition](#oh_audiorenderer_setmarkposition)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, uint32_t samplePos, [OH_AudioRenderer_OnMarkReachedCallback](#oh_audiorenderer_onmarkreachedcallback) callback, void \*userData) | Sets the mark position for an audio renderer. When this function is called, the mark position that has been set will be overwritten. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_CancelMark](#oh_audiorenderer_cancelmark)([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | Cancels the mark set by [OH_AudioRenderer_SetMarkPosition](#oh_audiorenderer_setmarkposition). |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetVolume](#oh_audiorenderer_setvolume)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, float volume) | Sets the volume for an audio stream. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetVolumeWithRamp](#oh_audiorenderer_setvolumewithramp)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, float volume, int32_t durationMs) | Sets the volume with a ramp within the specified duration for an audio stream. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetVolume](#oh_audiorenderer_getvolume)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, float \*volume) | Obtains the volume of an audio stream. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetUnderflowCount](#oh_audiorenderer_getunderflowcount)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, uint32_t \*count) | Obtains the number of underloaded audio streams of an audio capturer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetChannelLayout](#oh_audiorenderer_getchannellayout)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioChannelLayout](../apis-avcodec-kit/_core.md#oh_audiochannellayout-1) \*channelLayout) | Obtains the channel layout of an audio stream. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetEffectMode](#oh_audiorenderer_geteffectmode)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_AudioEffectMode](#oh_audiostream_audioeffectmode) \*effectMode) | Obtains the effect mode of an audio stream. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetEffectMode](#oh_audiorenderer_seteffectmode)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_AudioEffectMode](#oh_audiostream_audioeffectmode) effectMode) | Sets the effect mode for an audio stream. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetRendererPrivacy](#oh_audiorenderer_getrendererprivacy)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_PrivacyType](#oh_audiostream_privacytype) \*privacy) | Checks whether the audio stream being played can be recorded by other applications. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetSilentModeAndMixWithOthers](#oh_audiorenderer_setsilentmodeandmixwithothers)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, bool on) | Sets the silent mode in concurrent playback for an audio stream. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetSilentModeAndMixWithOthers](#oh_audiorenderer_getsilentmodeandmixwithothers)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, bool \*on) | Checks whether the silent mode in concurrent playback is enabled for an audio stream. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetDefaultOutputDevice](#oh_audiorenderer_setdefaultoutputdevice)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioDevice_Type](#oh_audiodevice_type) deviceType) | Sets the default built-in audio output device. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*\*builder, [OH_AudioStream_Type](#oh_audiostream_type) type) | Creates an audio stream builder, which can be an audio renderer or capturer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_Destroy](#oh_audiostreambuilder_destroy)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder) | Destroys an audio stream builder. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetSamplingRate](#oh_audiostreambuilder_setsamplingrate)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, int32_t rate) | Sets the sampling rate of an audio stream. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetChannelCount](#oh_audiostreambuilder_setchannelcount)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, int32_t channelCount) | Sets the number of channels for an audio stream. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetSampleFormat](#oh_audiostreambuilder_setsampleformat)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) format) | Sets the sampling format of an audio stream. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetEncodingType](#oh_audiostreambuilder_setencodingtype)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) encodingType) | Sets the encoding type of an audio stream. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetLatencyMode](#oh_audiostreambuilder_setlatencymode)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) latencyMode) | Sets the latency mode of an audio stream. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetChannelLayout](#oh_audiostreambuilder_setchannellayout)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioChannelLayout](../apis-avcodec-kit/_core.md#oh_audiochannellayout-1) channelLayout) | Sets the channel layout for an audio stream. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetRendererInfo](#oh_audiostreambuilder_setrendererinfo)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_Usage](#oh_audiostream_usage) usage) | Sets the usage scenario of an audio renderer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetCapturerInfo](#oh_audiostreambuilder_setcapturerinfo)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_SourceType](#oh_audiostream_sourcetype) sourceType) | Sets the usage scenario of an audio capturer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetRendererCallback](#oh_audiostreambuilder_setrenderercallback)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioRenderer_Callbacks](#oh_audiorenderer_callbacks) callbacks, void \*userData) | Sets callbacks for an audio renderer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetRendererOutputDeviceChangeCallback](#oh_audiostreambuilder_setrendereroutputdevicechangecallback)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioRenderer_OutputDeviceChangeCallback](#oh_audiorenderer_outputdevicechangecallback) callback, void \*userData) | Sets the callback invoked when the audio stream device changes. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetRendererPrivacy](#oh_audiostreambuilder_setrendererprivacy)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_PrivacyType](#oh_audiostream_privacytype) privacy) | Sets the privacy type for the audio stream being played. The privacy type specifies whether the audio stream can be recorded by other applications. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetCapturerCallback](#oh_audiostreambuilder_setcapturercallback)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioCapturer_Callbacks](#oh_audiocapturer_callbacks) callbacks, void \*userData) | Sets callbacks for an audio capturer. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetWriteDataWithMetadataCallback](#oh_audiostreambuilder_setwritedatawithmetadatacallback)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioRenderer_WriteDataWithMetadataCallback](#oh_audiorenderer_writedatawithmetadatacallback) callback, void \*userData) | Sets the callback invoked to write both audio data and metadata. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioRenderer](#oh_audiorenderer) \*\*audioRenderer) | Creates an audio renderer instance. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioCapturer](#oh_audiocapturer) \*\*audioCapturer) | Creates an audio capturer instance. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetFrameSizeInCallback](#oh_audiostreambuilder_setframesizeincallback)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, int32_t frameSize) | Sets the frame size for each callback during playback. The frame size must be at least equal to the size of the data processed by the audio hardware at a time and less than half of the internal buffer capacity. |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetRendererInterruptMode](#oh_audiostreambuilder_setrendererinterruptmode)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioInterrupt_Mode](#oh_audiointerrupt_mode) mode) | Sets the interrupt mode of the stream client.|
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetRendererWriteDataCallback](#oh_audiostreambuilder_setrendererwritedatacallback)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioRenderer_OnWriteDataCallback](#oh_audiorenderer_onwritedatacallback) callback, void \*userData) | Sets the callback used to write audio data. |


## Type Description


### OH_AudioCapturer

```
typedef struct OH_AudioCapturerStruct OH_AudioCapturer
```

**Description**

Defines a struct for an audio capturer.

An audio capturer instance is used to capture audio data.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10


### OH_AudioCapturer_Callbacks

```
typedef struct OH_AudioCapturer_Callbacks_Struct OH_AudioCapturer_Callbacks
```

**Description**

Defines a pointer to the callback functions related to an audio capturer.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10


### OH_AudioDeviceDescriptor

```
typedef struct OH_AudioDeviceDescriptor OH_AudioDeviceDescriptor
```

**Description**

Defines a struct for an audio device descriptor.

It provides detailed attributes of an audio device.

**Since**: 12


### OH_AudioDeviceDescriptorArray

```
typedef struct OH_AudioDeviceDescriptorArray OH_AudioDeviceDescriptorArray
```

**Description**

Defines a struct for an array of audio device descriptors.

**Since**: 12


### OH_AudioManager

```
typedef struct OH_AudioManager OH_AudioManager
```

**Description**

Defines a struct for an audio manager.

An audio manager provides audio management.

**Since**: 12


### OH_AudioRenderer

```
typedef struct OH_AudioRendererStruct OH_AudioRenderer
```

**Description**

Defines a struct for an audio renderer.

An audio renderer instance is used to render audio data.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10


### OH_AudioRenderer_Callbacks

```
typedef struct OH_AudioRenderer_Callbacks_Struct OH_AudioRenderer_Callbacks
```

**Description**

Defines a pointer to the callback functions related to an audio renderer.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10


### OH_AudioRenderer_OnMarkReachedCallback

```
typedef void(* OH_AudioRenderer_OnMarkReachedCallback)(OH_AudioRenderer *renderer, uint32_t samplePos, void *userData)
```

**Description**

Defines a pointer to the callback invoked when the mark position is reached.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| samplePos | Mark position. |
| userData | Pointer to the application data passed through the callback functions. |


### OH_AudioRenderer_OnWriteDataCallback

```
typedef OH_AudioData_Callback_Result(* OH_AudioRenderer_OnWriteDataCallback)(OH_AudioRenderer *renderer, void *userData, void *audioData, int32_t audioDataSize)
```

**Description**

Defines a function pointer to the callback function used to write audio data.

This function is similar to the function pointer [OH_AudioRenderer_Callbacks_Struct.OH_AudioRenderer_OnWriteData](_o_h___audio_renderer___callbacks___struct.md#oh_audiorenderer_onwritedata). However, this function has a return value to identify the audio data callback result. The return result indicates whether the data filled in the buffer is valid. If the data is invalid, the data entered by the user will not be played.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| userData | Pointer to the application data passed through the callback functions. |
| audioData | Pointer to the audio data written by the user. |
| audioDataSize | Length of the audio data, in bytes. |

**Returns**

Audio data callback result.

**See**

[OH_AudioRenderer_Callbacks_Struct.OH_AudioRenderer_OnWriteData](_o_h___audio_renderer___callbacks___struct.md#oh_audiorenderer_onwritedata)


### OH_AudioRenderer_OutputDeviceChangeCallback

```
typedef void(* OH_AudioRenderer_OutputDeviceChangeCallback) (OH_AudioRenderer *renderer, void *userData, OH_AudioStream_DeviceChangeReason reason)
```

**Description**

Defines a pointer to the callback invoked when the audio stream device changes.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| userData | Pointer to the application data passed through the callback functions. |
| reason | Enumerates the reasons for audio stream device changes. |


### OH_AudioRenderer_WriteDataWithMetadataCallback

```
typedef int32_t(* OH_AudioRenderer_WriteDataWithMetadataCallback)(OH_AudioRenderer *renderer, void *userData, void *audioData, int32_t audioDataSize, void *metadata, int32_t metadataSize)
```

**Description**

Defines a function pointer to the callback function used to write audio data and metadata.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| userData | Pointer to the application data passed through the callback functions. |
| audioData | Pointer to the audio data written by the user. |
| audioDataSize | Length of the audio data, in bytes. |
| metadata | Pointer to the metadata written by the user. |
| metadataSize | Length of the metadata, in bytes. |

**Returns**

Error code of the callback function.


### OH_AudioRoutingManager

```
typedef struct OH_AudioRoutingManager OH_AudioRoutingManager
```

**Description**

Defines a struct for an audio routing manager, which is used for routing and device-related functions.

**Since**: 12


### OH_AudioRoutingManager_OnDeviceChangedCallback

```
typedef int32_t(* OH_AudioRoutingManager_OnDeviceChangedCallback) (OH_AudioDevice_ChangeType type, OH_AudioDeviceDescriptorArray *audioDeviceDescriptorArray)
```

**Description**

Defines a pointer to the callback function that returns the changed audio device descriptor (possibly multiple descriptors).

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| type | Device connection status, which is [OH_AudioDevice_ChangeType](#oh_audiodevice_changetype). The status can be either connected or disconnected.|
| audioDeviceDescriptorArray | Pointer to the audio device descriptor array, which is [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md). Do not release the pointer to the **audioDeviceDescriptorArray** struct separately. Instead, call [OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices) to release the **DeviceDescriptor** array.|


### OH_AudioSession_DeactivatedCallback

```
typedef int32_t(* OH_AudioSession_DeactivatedCallback)(OH_AudioSession_DeactivatedEvent event)
```

**Description**

Defines a function pointer to the callback function used to listen for audio session deactivation events.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to [OH_AudioSession_Deactivated_Event](#oh_audiosession_deactivatedevent), which indicates that an audio session is deactivated. |


### OH_AudioSession_DeactivatedEvent

```
typedef struct OH_AudioSession_DeactivatedEventOH_AudioSession_DeactivatedEvent
```

**Description**

Defines a struct for the event indicating that an audio session is deactivated.

**Since**: 12


### OH_AudioSession_Strategy

```
typedef struct OH_AudioSession_Strategy OH_AudioSession_Strategy
```

**Description**

Defines a struct for an audio session strategy.

**Since**: 12


### OH_AudioSessionManager

```
typedef struct OH_AudioSessionManager OH_AudioSessionManager
```

**Description**

Defines a struct for an audio session manager.

An audio session manager is used to manage audio sessions.

**Since**: 12


### OH_AudioStreamBuilder

```
typedef struct OH_AudioStreamBuilderStruct OH_AudioStreamBuilder
```

**Description**

Defines a struct for an audio stream builder.

An audio stream builder instance is often used to create an audio stream and set its attributes.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10


## Enum Description


### OH_AudioCommon_Result

```
enum OH_AudioCommon_Result
```

**Description**

Enumerates the audio operation results.

**Since**: 12

| Value| Description|
| -------- | -------- |
| AUDIOCOMMON_RESULT_SUCCESS  | Operation successful.  |
| AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM  | Invalid input parameter.  |
| AUDIOCOMMON_RESULT_ERROR_NO_MEMORY  | No memory.  |
| AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE  | Invalid state.  |
| AUDIOCOMMON_RESULT_ERROR_UNSUPPORTED  | Unsupported operation.  |
| AUDIOCOMMON_RESULT_ERROR_TIMEOUT  | Operation timed out.  |
| AUDIOCOMMON_RESULT_ERROR_STREAM_LIMIT  | Reached the maximum number of audio streams allowed.  |
| AUDIOCOMMON_RESULT_ERROR_SYSTEM  | System error.  |


### OH_AudioData_Callback_Result

```
enum OH_AudioData_Callback_Result
```

**Description**

Enumerates the audio data callback results.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

| Value| Description|
| -------- | -------- |
| AUDIO_DATA_CALLBACK_RESULT_INVALID  | The data is invalid.  |
| AUDIO_DATA_CALLBACK_RESULT_VALID  | The data is valid.  |


### OH_AudioDevice_ChangeType

```
enum OH_AudioDevice_ChangeType
```

**Description**

Enumerates the types of audio device changes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| AUDIO_DEVICE_CHANGE_TYPE_CONNECT | Device connected.|
| AUDIO_DEVICE_CHANGE_TYPE_DISCONNECT | Device disconnected.|


### OH_AudioDevice_Flag

```
enum OH_AudioDevice_Flag
```

**Description**

Enumerates the flags of audio devices.

**Since**: 12

| Value| Description|
| -------- | -------- |
| AUDIO_DEVICE_FLAG_NONE | No flag.|
| AUDIO_DEVICE_FLAG_OUTPUT | Output device.|
| AUDIO_DEVICE_FLAG_INPUT | Input device.|
| AUDIO_DEVICE_FLAG_ALL | All devices.|


### OH_AudioDevice_Role

```
enum OH_AudioDevice_Role
```

**Description**

Enumerates the roles of audio devices.

**Since**: 12

| Value| Description|
| -------- | -------- |
| AUDIO_DEVICE_ROLE_INPUT | Input device.|
| AUDIO_DEVICE_ROLE_OUTPUT | Output device.|


### OH_AudioDevice_Type

```
enum OH_AudioDevice_Type
```

**Description**

Enumerates the types of audio devices.

**Since**: 12

| Value| Description|
| -------- | -------- |
| AUDIO_DEVICE_TYPE_INVALID | Invalid device.|
| AUDIO_DEVICE_TYPE_EARPIECE | Earpiece.|
| AUDIO_DEVICE_TYPE_SPEAKER | Speaker.|
| AUDIO_DEVICE_TYPE_WIRED_HEADSET | Wired headset with a microphone.|
| AUDIO_DEVICE_TYPE_WIRED_HEADPHONES | Wired headset without microphone.|
| AUDIO_DEVICE_TYPE_BLUETOOTH_SCO | Bluetooth device using Synchronous Connection-oriented (SCO) links.|
| AUDIO_DEVICE_TYPE_BLUETOOTH_A2DP | Bluetooth device using Advanced Audio Distribution Profile (A2DP) links.|
| AUDIO_DEVICE_TYPE_MIC | Microphone.|
| AUDIO_DEVICE_TYPE_USB_HEADSET | USB headset.|
| AUDIO_DEVICE_TYPE_DISPLAY_PORT | Display port device.|
| AUDIO_DEVICE_TYPE_REMOTE_CAST | Remote cast device.|
| AUDIO_DEVICE_TYPE_DEFAULT | Default device type.|


### OH_AudioDevice_Usage

```
enum OH_AudioDevice_Usage
```

**Description**

Enumerates the usage scenarios of audio devices.

**Since**: 12

| Value| Description|
| -------- | -------- |
| AUDIO_DEVICE_USAGE_MEDIA_OUTPUT  | Media output device.|
| AUDIO_DEVICE_USAGE_MEDIA_INPUT  | Media input device.|
| AUDIO_DEVICE_USAGE_MEDIA_ALL  | All media devices.|
| AUDIO_DEVICE_USAGE_CALL_OUTPUT  | Call output device.|
| AUDIO_DEVICE_USAGE_CALL_INPUT  | Call input device.|
| AUDIO_DEVICE_USAGE_CALL_ALL  | All call devices.|


### OH_AudioInterrupt_ForceType

```
enum OH_AudioInterrupt_ForceType
```

**Description**

Enumerates the types of force that causes audio interruption.

The force type is obtained when an audio interruption event is received.

This type specifies whether the audio interruption operation is forcibly performed by the system. The operation information (such as audio pause or stop) can be obtained through [OH_AudioInterrupt_Hint](#oh_audiointerrupt_hint).

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

| Value| Description|
| -------- | -------- |
| AUDIOSTREAM_INTERRUPT_FORCE  | The operation is forcibly performed by the system.  |
| AUDIOSTREAM_INTERRUPT_SHARE  | The operation will not be performed by the system. [OH_AudioInterrupt_Hint](#oh_audiointerrupt_hint) is used to provide recommended operations for the application, and the application can determine the next processing mode. |


### OH_AudioInterrupt_Hint

```
enum OH_AudioInterrupt_Hint
```

**Description**

Enumerates the hints provided along with audio interruption.

The hint is obtained when an audio interruption event is received.

The hint specifies the operation (such as audio pause or volume adjustment) to be performed on audio streams based on the focus policy. You can determine whether the operation is forcibly performed by the system based on [OH_AudioInterrupt_ForceType](#oh_audiointerrupt_forcetype).

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

| Value| Description|
| -------- | -------- |
| AUDIOSTREAM_INTERRUPT_HINT_NONE  | None.  |
| AUDIOSTREAM_INTERRUPT_HINT_RESUME  | A hint is displayed, indicating that the audio stream is restored. The application can proactively trigger operations related to rendering or recording.<br>This operation cannot be forcibly performed by the system, and the corresponding [OH_AudioInterrupt_ForceType](#oh_audiointerrupt_forcetype) must be **AUDIOSTREAM_INTERRUPT_SHARE**.  |
| AUDIOSTREAM_INTERRUPT_HINT_PAUSE  | A hint is displayed, indicating that the audio stream is paused and the audio focus is lost temporarily.<br>The **AUDIOSTREAM_INTERRUPT_HINT_RESUME** event will be triggered when the focus is gained.  |
| AUDIOSTREAM_INTERRUPT_HINT_STOP  | A hint is displayed, indicating that the audio stream stops and the audio focus is lost.  |
| AUDIOSTREAM_INTERRUPT_HINT_DUCK  | A hint is displayed, indicating that audio ducking starts and the audio is played at a lower volume.  |
| AUDIOSTREAM_INTERRUPT_HINT_UNDUCK  | A hint is displayed, indicating that audio ducking ends and the audio is played at the normal volume.  |


### OH_AudioInterrupt_Mode

```
enum OH_AudioInterrupt_Mode
```

**Description**

Enumerates the audio interruption modes.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

| Value| Description|
| -------- | -------- |
| AUDIOSTREAM_INTERRUPT_MODE_SHARE  | Shared mode. |
| AUDIOSTREAM_INTERRUPT_MODE_INDEPENDENT  | Independent mode.|


### OH_AudioScene

```
enum OH_AudioScene
```

**Description**

Enumerates the audio scenes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| AUDIO_SCENE_DEFAULT  | Default audio scene.|
| AUDIO_SCENE_RINGING  | Ringing scene.|
| AUDIO_SCENE_PHONE_CALL  | Phone call scene.|
| AUDIO_SCENE_VOICE_CHAT  | Voice chat scene.|


### OH_AudioSession_ConcurrencyMode

```
enum OH_AudioSession_ConcurrencyMode
```

**Description**

Enumerates the audio concurrency modes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| CONCURRENCY_DEFAULT  | Uses the system strategy by default.  |
| CONCURRENCY_MIX_WITH_OTHERS  | Mixes audio with other applications that are playing audio.  |
| CONCURRENCY_DUCK_OTHERS  | Lowers the volume of the application that is currently playing the audio.  |
| CONCURRENCY_PAUSE_OTHERS  | Pauses the application that is currently playing the audio.  |


### OH_AudioSession_DeactivatedReason

```
enum OH_AudioSession_DeactivatedReason
```

**Description**

Enumerates the reasons for deactivating an audio session.

**Since**: 12

| Value| Description|
| -------- | -------- |
| DEACTIVATED_LOWER_PRIORITY  | The application focus is preempted.  |
| DEACTIVATED_TIMEOUT  | The application times out after the stream is stopped.  |


### OH_AudioStream_AudioEffectMode

```
enum OH_AudioStream_AudioEffectMode
```

**Description**

Enumerates the audio effect modes.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

| Value| Description|
| -------- | -------- |
| EFFECT_NONE  | No audio effect used.  |
| EFFECT_DEFAULT  | Default audio effect mode.  |


### OH_AudioStream_DeviceChangeReason

```
enum OH_AudioStream_DeviceChangeReason
```

**Description**

Enumerates the reasons for audio stream device changes.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 11

| Value| Description|
| -------- | -------- |
| REASON_UNKNOWN  | Unknown reason.  |
| REASON_NEW_DEVICE_AVAILABLE  | A new device is available.  |
| REASON_OLD_DEVICE_UNAVAILABLE  | The old device is unavailable. When this reason is reported, the application should consider pausing audio playback.  |
| REASON_OVERRODE  | The user or system forcibly changes the device.  |


### OH_AudioStream_EncodingType

```
enum OH_AudioStream_EncodingType
```

**Description**

Enumerates the encoding types of audio streams.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

| Value| Description|
| -------- | -------- |
| AUDIOSTREAM_ENCODING_TYPE_RAW  | PCM encoding.  |
| AUDIOSTREAM_ENCODING_TYPE_AUDIOVIVID  | AudioVivid encoding.<br>**Since**: 12|


### OH_AudioStream_Event

```
enum OH_AudioStream_Event
```

**Description**

Enumerates the audio stream events.

This enum is used to describe audio events.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

| Value| Description|
| -------- | -------- |
| AUDIOSTREAM_EVENT_ROUTING_CHANGED  | The audio route has been changed.  |


### OH_AudioStream_LatencyMode

```
enum OH_AudioStream_LatencyMode
```

**Description**

Enumerates the latency modes of audio streams.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

| Value| Description|
| -------- | -------- |
| AUDIOSTREAM_LATENCY_MODE_NORMAL  | Normal latency mode.  |
| AUDIOSTREAM_LATENCY_MODE_FAST  | Low latency mode.  |


### OH_AudioStream_PrivacyType

```
enum OH_AudioStream_PrivacyType
```

**Description**

Enumerates the privacy types of an audio stream. The privacy type specifies whether the audio stream can be recorded by other applications.

**System capability**: SystemCapability.Multimedia.Audio.PlaybackCapture

**Since**: 12

| Value| Description|
| -------- | -------- |
| AUDIO_STREAM_PRIVACY_TYPE_PUBLIC  | The audio stream can be recorded by other applications.  |
| AUDIO_STREAM_PRIVACY_TYPE_PRIVATE  | The audio stream cannot be recorded by other applications.  |


### OH_AudioStream_Result

```
enum OH_AudioStream_Result
```

**Description**

Enumerates the audio stream operation results.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

| Value| Description|
| -------- | -------- |
| AUDIOSTREAM_SUCCESS  | The operation is successful.  |
| AUDIOSTREAM_ERROR_INVALID_PARAM  | Invalid input parameter.  |
| AUDIOSTREAM_ERROR_ILLEGAL_STATE  | Invalid state.  |
| AUDIOSTREAM_ERROR_SYSTEM  | System error.  |


### OH_AudioStream_SampleFormat

```
enum OH_AudioStream_SampleFormat
```

**Description**

Enumerates the sampling formats of audio streams.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

| Value| Description|
| -------- | -------- |
| AUDIOSTREAM_SAMPLE_U8  | Unsigned 8-bit.  |
| AUDIOSTREAM_SAMPLE_S16LE  | Short 16-bit little-endian.  |
| AUDIOSTREAM_SAMPLE_S24LE  | Short 24-bit little-endian.  |
| AUDIOSTREAM_SAMPLE_S32LE  | Short 32-bit little-endian.  |


### OH_AudioStream_SourceType

```
enum OH_AudioStream_SourceType
```
**Description**

Enumerates the usage scenarios of an audio capturer, that is, the usage scenarios of audio input streams.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

| Value| Description|
| -------- | -------- |
| AUDIOSTREAM_SOURCE_TYPE_INVALID  | Invalid state.  |
| AUDIOSTREAM_SOURCE_TYPE_MIC  | Audio recording.  |
| AUDIOSTREAM_SOURCE_TYPE_VOICE_RECOGNITION  | Voice recognition.  |
| AUDIOSTREAM_SOURCE_TYPE_PLAYBACK_CAPTURE  | Audio playback.  |
| AUDIOSTREAM_SOURCE_TYPE_VOICE_COMMUNICATION  | Voice communication.  |


### OH_AudioStream_State

```
enum OH_AudioStream_State
```

**Description**

Enumerates the audio stream states.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

| Value| Description|
| -------- | -------- |
| AUDIOSTREAM_STATE_INVALID  | Invalid state.  |
| AUDIOSTREAM_STATE_NEW  | Newly created.  |
| AUDIOSTREAM_STATE_PREPARED  | Prepared.  |
| AUDIOSTREAM_STATE_RUNNING  | Running.  |
| AUDIOSTREAM_STATE_STOPPED  | Stopped.  |
| AUDIOSTREAM_STATE_RELEASED  | Released.  |
| AUDIOSTREAM_STATE_PAUSED  | Paused.  |


### OH_AudioStream_Type

```
enum OH_AudioStream_Type
```

**Description**

Enumerates the audio stream types.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

| Value| Description|
| -------- | -------- |
| AUDIOSTREAM_TYPE_RENDERER  | The audio stream is an output stream.  |
| AUDIOSTREAM_TYPE_CAPTURER  | The audio stream is an input stream.  |


### OH_AudioStream_Usage

```
enum OH_AudioStream_Usage
```

**Description**

Enumerates the usage scenarios of an audio renderer, that is, the usage scenarios of audio output streams.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

| Value| Description|
| -------- | -------- |
| AUDIOSTREAM_USAGE_UNKNOWN  | Unknown content.  |
| AUDIOSTREAM_USAGE_MUSIC  | Music.  |
| AUDIOSTREAM_USAGE_VOICE_COMMUNICATION  | VoIP voice call.  |
| AUDIOSTREAM_USAGE_VOICE_ASSISTANT  | Voice assistant.  |
| AUDIOSTREAM_USAGE_ALARM  | Alarming.  |
| AUDIOSTREAM_USAGE_VOICE_MESSAGE  | Voice message.  |
| AUDIOSTREAM_USAGE_RINGTONE  | Ringtone.  |
| AUDIOSTREAM_USAGE_NOTIFICATION  | Notification.  |
| AUDIOSTREAM_USAGE_ACCESSIBILITY  | Accessibility.  |
| AUDIOSTREAM_USAGE_MOVIE  | Movie or video.  |
| AUDIOSTREAM_USAGE_GAME  | Gaming.  |
| AUDIOSTREAM_USAGE_AUDIOBOOK  | Audiobooks (including crosstalks and storytelling), news radio, and podcasts.  |
| AUDIOSTREAM_USAGE_NAVIGATION  | Navigation.  |
| AUDIOSTREAM_USAGE_VIDEO_COMMUNICATION | VoIP video call.<br>**Since**: 12|


## Function Description


### OH_AudioCapturer_Flush()

```
OH_AudioStream_Result OH_AudioCapturer_Flush(OH_AudioCapturer *capturer)
```

**Description**

Flushes obtained audio data.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).|

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **capturer** parameter is set to a null pointer.

**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.


### OH_AudioCapturer_GetCapturerInfo()

```
OH_AudioStream_Result OH_AudioCapturer_GetCapturerInfo(OH_AudioCapturer *capturer, OH_AudioStream_SourceType *sourceType)
```

**Description**

Obtains the usage scenario of an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).|
| sourceType | Pointer to a variable used to receive the usage scenario.|

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **capturer** parameter is set to a null pointer.


### OH_AudioCapturer_GetChannelCount()

```
OH_AudioStream_Result OH_AudioCapturer_GetChannelCount(OH_AudioCapturer *capturer, int32_t *channelCount)
```

**Description**

Obtains the number of channels for an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).|
| channelCount | Pointer to a variable used to receive the number of channels.|

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **capturer** parameter is set to a null pointer.


### OH_AudioCapturer_GetCurrentState()

```
OH_AudioStream_Result OH_AudioCapturer_GetCurrentState(OH_AudioCapturer *capturer, OH_AudioStream_State *state)
```

**Description**

Obtains the state of an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).|
| state | Pointer to a variable used to receive the state.|

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **capturer** parameter is set to a null pointer.


### OH_AudioCapturer_GetEncodingType()

```
OH_AudioStream_Result OH_AudioCapturer_GetEncodingType(OH_AudioCapturer *capturer, OH_AudioStream_EncodingType *encodingType)
```

**Description**

Obtains the encoding type of an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).|
| encodingType | Pointer to a variable used to receive the encoding type.|

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **capturer** parameter is set to a null pointer.


### OH_AudioCapturer_GetFrameSizeInCallback()

```
OH_AudioStream_Result OH_AudioCapturer_GetFrameSizeInCallback(OH_AudioCapturer *capturer, int32_t *frameSize)
```

**Description**

Obtains the frame size in the callback. The frame size is the fixed length of the buffer returned by each callback.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).|
| frameSize | Pointer to the variable that holds the frame size.|

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **capturer** parameter is set to a null pointer.

**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.


### OH_AudioCapturer_GetFramesRead()

```
OH_AudioStream_Result OH_AudioCapturer_GetFramesRead (OH_AudioCapturer *capturer, int64_t *frames)
```

**Description**

Obtains the number of frames that have been read since the stream was created.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).|
| frames | Pointer to the variable that holds the frame count.|

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **capturer** parameter is set to a null pointer.


### OH_AudioCapturer_GetLatencyMode()

```
OH_AudioStream_Result OH_AudioCapturer_GetLatencyMode(OH_AudioCapturer *capturer, OH_AudioStream_LatencyMode *latencyMode)
```

**Description**

Obtains the latency mode of an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).|
| latencyMode | Pointer to a variable used to receive the latency mode.|

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **capturer** parameter is set to a null pointer.


### OH_AudioCapturer_GetOverflowCount()

```
OH_AudioStream_Result OH_AudioCapturer_GetOverflowCount (OH_AudioCapturer *capturer, uint32_t *count)
```

**Description**

Obtains the number of overloaded audio streams of an audio capturer.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer). |
| count | Pointer to a variable used to receive the number of overloaded audio streams. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **capturer** parameter is set to a null pointer.


### OH_AudioCapturer_GetSampleFormat()

```
OH_AudioStream_Result OH_AudioCapturer_GetSampleFormat(OH_AudioCapturer *capturer, OH_AudioStream_SampleFormat *sampleFormat)
```

**Description**

Obtains the sampling format of an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).|
| sampleFormat | Pointer to a variable used to receive the sampling format.|

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **capturer** parameter is set to a null pointer.


### OH_AudioCapturer_GetSamplingRate()

```
OH_AudioStream_Result OH_AudioCapturer_GetSamplingRate(OH_AudioCapturer *capturer, int32_t *rate)
```

**Description**

Obtains the sampling rate of an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).|
| rate | Pointer to a variable used to receive the sampling rate.|

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **capturer** parameter is set to a null pointer.


### OH_AudioCapturer_GetStreamId()

```
OH_AudioStream_Result OH_AudioCapturer_GetStreamId(OH_AudioCapturer *capturer, uint32_t *streamId)
```

**Description**

Obtains the stream ID of an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).|
| streamId | Pointer to a variable used to receive the stream ID.|

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **capturer** parameter is set to a null pointer.


### OH_AudioCapturer_GetTimestamp()

```
OH_AudioStream_Result OH_AudioCapturer_GetTimestamp(OH_AudioCapturer *capturer, clockid_t clockId, int64_t *framePosition, int64_t *timestamp)
```

**Description**

Obtains the timestamp and position information of an audio input stream.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).|
| clockId | Clock identifier. Use **CLOCK_MONOTONIC**.|
| framePosition | Pointer to the variable that holds the position information.|
| timestamp | Pointer to the variable that holds the timestamp.|

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:

  1. The **capturer** parameter is set to a null pointer.
  2. The **clockId** parameter is set to an invalid value.

**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.


### OH_AudioCapturer_Pause()

```
OH_AudioStream_Result OH_AudioCapturer_Pause(OH_AudioCapturer *capturer)
```

**Description**

Pauses an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).|

**Required permissions**

ohos.permission.MICROPHONE

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **capturer** parameter is set to a null pointer.

**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.


### OH_AudioCapturer_Release()

```
OH_AudioStream_Result OH_AudioCapturer_Release(OH_AudioCapturer *capturer)
```

**Description**

Releases an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).|

**Required permissions**

ohos.permission.MICROPHONE

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **capturer** parameter is set to a null pointer.

**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.


### OH_AudioCapturer_Start()

```
OH_AudioStream_Result OH_AudioCapturer_Start(OH_AudioCapturer *capturer)
```

**Description**

Starts an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).|

**Required permissions**

ohos.permission.MICROPHONE

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **capturer** parameter is set to a null pointer.

**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.


### OH_AudioCapturer_Stop()

```
OH_AudioStream_Result OH_AudioCapturer_Stop(OH_AudioCapturer *capturer)
```

**Description**

Stops an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).|

**Required permissions**

ohos.permission.MICROPHONE

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **capturer** parameter is set to a null pointer.

**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.


### OH_AudioDeviceDescriptor_GetDeviceAddress()

```
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceAddress (OH_AudioDeviceDescriptor *audioDeviceDescriptor, char **address)
```

**Description**

Obtains the device address based on an audio device descriptor.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioDeviceDescriptor | Pointer to an audio device descriptor, which is obtained by calling [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices) or [OH_AudioRouterManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback).|
| address | Double pointer to the MAC address of the device. Do not release the pointer to the MAC address separately. Instead, call [OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices) to release all the device descriptors when they are no longer needed.|

**Returns**

Returns **AUDIOCOMMON_RESULT_SUCCESS** if the operation is successful; returns **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM** otherwise.


### OH_AudioDeviceDescriptor_GetDeviceChannelCounts()

```
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceChannelCounts (OH_AudioDeviceDescriptor *audioDeviceDescriptor, uint32_t **channelCounts, uint32_t *size)
```

**Description**

Obtains an array that holds the number of device channels based on an audio device descriptor.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioDeviceDescriptor | Pointer to an audio device descriptor, which is obtained by calling [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices) or [OH_AudioRouterManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback).|
| channelCounts | Double pointer to the array that holds the channel counts. Do not release the pointer to the channel counts separately. Instead, call [OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices) to release all the device descriptors when they are no longer needed.|
| size | Pointer to the size of the array.|

**Returns**

Returns **AUDIOCOMMON_RESULT_SUCCESS** if the operation is successful; returns **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM** otherwise.


### OH_AudioDeviceDescriptor_GetDeviceDisplayName()

```
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceDisplayName (OH_AudioDeviceDescriptor *audioDeviceDescriptor, char **displayName)
```

**Description**

Obtains the device display name based on an audio device descriptor.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioDeviceDescriptor | Pointer to an audio device descriptor, which is obtained by calling [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices) or [OH_AudioRouterManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback).|
| displayName | Double pointer to the display name. Do not release the pointer to the display name separately. Instead, call [OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices) to release all the device descriptors when they are no longer needed.|

**Returns**

Returns **AUDIOCOMMON_RESULT_SUCCESS** if the operation is successful; returns **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM** otherwise.


### OH_AudioDeviceDescriptor_GetDeviceEncodingTypes()

```
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceEncodingTypes (OH_AudioDeviceDescriptor *audioDeviceDescriptor, OH_AudioStream_EncodingType **encodingTypes, uint32_t *size)
```

**Description**

Obtains the device encoding types based on an audio device descriptor.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioDeviceDescriptor | Pointer to an audio device descriptor, which is obtained by calling [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices) or [OH_AudioRouterManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback).|
| encodingTypes | Double pointer to the device encoding type. For details about the available options, see [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype). Do not release the pointer to the device encoding type separately. Instead, call [OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices) to release all the device descriptors when they are no longer needed.|
| size | Pointer to the size of the device encoding type.|

**Returns**

Returns **AUDIOCOMMON_RESULT_SUCCESS** if the operation is successful; returns **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM** otherwise.


### OH_AudioDeviceDescriptor_GetDeviceId()

```
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceId (OH_AudioDeviceDescriptor *audioDeviceDescriptor, uint32_t *id)
```

**Description**

Obtains the device ID based on an audio device descriptor.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioDeviceDescriptor | Pointer to an audio device descriptor, which is obtained by calling [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices) or [OH_AudioRouterManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback).|
| id | Pointer to the device ID, which is a variable for setting the device role.|

**Returns**

Returns **AUDIODEVICE_SUCCESS** if the operation is successful; returns **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM** otherwise.


### OH_AudioDeviceDescriptor_GetDeviceName()

```
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceName (OH_AudioDeviceDescriptor *audioDeviceDescriptor, char **name )
```

**Description**

Obtains the device name based on an audio device descriptor.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioDeviceDescriptor | Pointer to an audio device descriptor, which is obtained by calling [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices) or [OH_AudioRouterManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback).|
| name | Double pointer to the device name. Do not release the pointer to the device name separately. Instead, call [OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices) to release all the device descriptors when they are no longer needed.|

**Returns**

Returns **AUDIOCOMMON_RESULT_SUCCESS** if the operation is successful; returns **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM** otherwise.


### OH_AudioDeviceDescriptor_GetDeviceRole()

```
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceRole (OH_AudioDeviceDescriptor *audioDeviceDescriptor, OH_AudioDevice_Role *deviceRole)
```

**Description**

Obtains the device role based on an audio device descriptor.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioDeviceDescriptor | Pointer to an audio device descriptor, which is obtained by calling [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices) or [OH_AudioRouterManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback).|
| deviceRole | Pointer to the device role. For details about the available options, see [OH_AudioDevice_Role](#oh_audiodevice_role).|

**Returns**

Returns **AUDIOCOMMON_RESULT_SUCCESS** if the operation is successful; returns **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM** otherwise.


### OH_AudioDeviceDescriptor_GetDeviceSampleRates()

```
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceSampleRates (OH_AudioDeviceDescriptor *audioDeviceDescriptor, uint32_t **sampleRates, uint32_t *size)
```

**Description**

Obtains the sample rates based on an audio device descriptor.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioDeviceDescriptor | Pointer to an audio device descriptor, which is obtained by calling [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices) or [OH_AudioRouterManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback).|
| sampleRates | Double pointer to the array of sample rates. Do not release the pointer to the sample rates separately. Instead, call [OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices) to release all the device descriptors when they are no longer needed.|
| size | Pointer to the size of the array.|

**Returns**

Returns **AUDIOCOMMON_RESULT_SUCCESS** if the operation is successful; returns **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM** otherwise.


### OH_AudioDeviceDescriptor_GetDeviceType()

```
OH_AudioCommon_Result OH_AudioDeviceDescriptor_GetDeviceType (OH_AudioDeviceDescriptor *audioDeviceDescriptor, OH_AudioDevice_Type *deviceType)
```

**Description**

Obtains the device type based on an audio device descriptor.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioDeviceDescriptor | Pointer to an audio device descriptor, which is obtained by calling [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices) or [OH_AudioRouterManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback).|
| deviceType | Pointer to the device type. For details about the available options, see [OH_AudioDevice_Type](#oh_audiodevice_type). |

**Returns**

Returns **AUDIOCOMMON_RESULT_SUCCESS** if the operation is successful; returns **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM** otherwise.


### OH_AudioManager_GetAudioRoutingManager()

```
OH_AudioCommon_Result OH_AudioManager_GetAudioRoutingManager (OH_AudioRoutingManager **audioRoutingManager)
```

**Description**

Obtains the handle to an audio routing manager. The handle should be set as the first parameter in the routing-related functions.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioRoutingManager | Pointer to an [OH_AudioRoutingManager](#oh_audioroutingmanager) object.  |

**Returns**

Returns a result code defined in [OH_AudioCommon_Result](#oh_audiocommon_result). The following result codes are possible:

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.


### OH_AudioManager_GetAudioSessionManager()

```
OH_AudioCommon_Result OH_AudioManager_GetAudioSessionManager (OH_AudioSessionManager **audioSessionManager)
```

**Description**

Obtains an **OH_AudioSessionManager** instance.

Before using the features related to the audio session manager, you must obtain an **OH_AudioSessionManager** instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioSessionManager | Double pointer to the [OH_AudioSessionManager](#oh_audiosessionmanager) instance obtained.|

**Returns**

Returns a result code defined in [OH_AudioCommon_Result](#oh_audiocommon_result). The following result codes are possible:

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.


### OH_AudioRenderer_CancelMark()

```
OH_AudioStream_Result OH_AudioRenderer_CancelMark (OH_AudioRenderer *renderer)
```

**Description**

Cancels the mark set by [OH_AudioRenderer_SetMarkPosition](#oh_audiorenderer_setmarkposition).

**Since**: 12

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.


### OH_AudioRenderer_Flush()

```
OH_AudioStream_Result OH_AudioRenderer_Flush(OH_AudioRenderer *renderer)
```

**Description**

Flushes written audio data.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.

**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.


### OH_AudioRenderer_GetChannelCount()

```
OH_AudioStream_Result OH_AudioRenderer_GetChannelCount(OH_AudioRenderer *renderer, int32_t *channelCount)
```

**Description**

Obtains the number of channels for an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| channelCount | Pointer to a variable used to receive the number of channels. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.


### OH_AudioRenderer_GetChannelLayout()

```
OH_AudioStream_Result OH_AudioRenderer_GetChannelLayout (OH_AudioRenderer *renderer, OH_AudioChannelLayout *channelLayout)
```

**Description**

Obtains the channel layout of an audio stream.

**Since**: 12

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| channelLayout | Pointer to a variable used to receive the channel layout. For details about the available options, see [OH_AudioChannelLayout](../apis-avcodec-kit/_core.md#oh_audiochannellayout-1). |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.


### OH_AudioRenderer_GetCurrentState()

```
OH_AudioStream_Result OH_AudioRenderer_GetCurrentState(OH_AudioRenderer *renderer, OH_AudioStream_State *state)
```

**Description**

Obtains the state of an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| state | Pointer to a variable used to receive the state. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.


### OH_AudioRenderer_GetEffectMode()

```
OH_AudioStream_Result OH_AudioRenderer_GetEffectMode (OH_AudioRenderer *renderer, OH_AudioStream_AudioEffectMode *effectMode)
```

**Description**

Obtains the effect mode of an audio stream.

**Since**: 12

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| effectMode | Pointer to a variable used to receive the effect mode. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.


### OH_AudioRenderer_GetEncodingType()

```
OH_AudioStream_Result OH_AudioRenderer_GetEncodingType(OH_AudioRenderer *renderer, OH_AudioStream_EncodingType *encodingType)
```

**Description**

Obtains the encoding type of an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| encodingType | Pointer to a variable used to receive the encoding type. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.


### OH_AudioRenderer_GetFrameSizeInCallback()

```
OH_AudioStream_Result OH_AudioRenderer_GetFrameSizeInCallback(OH_AudioRenderer *renderer, int32_t *frameSize)
```

**Description**

Obtains the frame size in the callback. The frame size is the fixed length of the buffer returned by each callback.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| frameSize | Pointer to the variable that holds the frame size. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.


### OH_AudioRenderer_GetFramesWritten()

```
OH_AudioStream_Result OH_AudioRenderer_GetFramesWritten(OH_AudioRenderer *renderer, int64_t *frames)
```

**Description**

Obtains the number of frames that have been written since the stream was created.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| frames | Pointer to the variable that holds the frame count. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.


### OH_AudioRenderer_GetLatencyMode()

```
OH_AudioStream_Result OH_AudioRenderer_GetLatencyMode(OH_AudioRenderer *renderer, OH_AudioStream_LatencyMode *latencyMode)
```

**Description**

Obtains the latency mode of an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| latencyMode | Pointer to a variable used to receive the latency mode. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.


### OH_AudioRenderer_GetRendererInfo()

```
OH_AudioStream_Result OH_AudioRenderer_GetRendererInfo(OH_AudioRenderer *renderer, OH_AudioStream_Usage *usage)
```

**Description**

Obtains the usage scenario of an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| usage | Pointer to a variable used to receive the usage scenario. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.


### OH_AudioRenderer_GetRendererPrivacy()

```
OH_AudioStream_Result OH_AudioRenderer_GetRendererPrivacy (OH_AudioRenderer *renderer, OH_AudioStream_PrivacyType *privacy)
```

**Description**

Checks whether the audio stream being played can be recorded by other applications.

**Since**: 12

**System capability**: SystemCapability.Multimedia.Audio.PlaybackCapture

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| privacy | Pointer to the privacy type, which specifies whether the audio stream being played can be recorded by other applications. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.


### OH_AudioRenderer_GetSampleFormat()

```
OH_AudioStream_Result OH_AudioRenderer_GetSampleFormat(OH_AudioRenderer *renderer, OH_AudioStream_SampleFormat *sampleFormat)
```

**Description**

Obtains the sampling format of an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| sampleFormat | Pointer to a variable used to receive the sampling format. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.


### OH_AudioRenderer_GetSamplingRate()

```
OH_AudioStream_Result OH_AudioRenderer_GetSamplingRate(OH_AudioRenderer *renderer, int32_t *rate)
```

**Description**

Obtains the sampling rate of an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| rate | Pointer to a variable used to receive the sampling rate. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.


### OH_AudioRenderer_GetSilentModeAndMixWithOthers()

```
OH_AudioStream_Result OH_AudioRenderer_GetSilentModeAndMixWithOthers(OH_AudioRenderer *renderer, bool *on)
```

**Description**

Checks whether the silent mode in concurrent playback is enabled for an audio stream.

**Since**: 12

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| on | Whether the silent mode in concurrent playback is enabled. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOSTREAM_SUCCESS**: The function is executed successfully.

**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.



### OH_AudioRenderer_GetSpeed()

```
OH_AudioStream_Result OH_AudioRenderer_GetSpeed (OH_AudioRenderer * renderer, float * speed )
```

**Description**

Obtains the audio renderer rate.

**Since**: 11

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| speed | Pointer to the variable that receives the playback speed. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.


### OH_AudioRenderer_GetStreamId()

```
OH_AudioStream_Result OH_AudioRenderer_GetStreamId(OH_AudioRenderer *renderer, uint32_t *streamId)
```

**Description**

Obtains the stream ID of an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| streamId | Pointer to a variable used to receive the stream ID. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.


### OH_AudioRenderer_GetTimestamp()

```
OH_AudioStream_Result OH_AudioRenderer_GetTimestamp(OH_AudioRenderer *renderer, clockid_t clockId, int64_t *framePosition, int64_t *timestamp)
```

**Description**

Obtains the timestamp and position information of an audio output stream.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| clockId | Clock identifier. Use **CLOCK_MONOTONIC**. |
| framePosition | Pointer to the variable that holds the position information. |
| timestamp | Pointer to the variable that holds the timestamp. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:

  1. The **renderer** parameter is set to a null pointer.
  2. The **clockId** parameter is set to an invalid value.

**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.


### OH_AudioRenderer_GetUnderflowCount()

```
OH_AudioStream_Result OH_AudioRenderer_GetUnderflowCount (OH_AudioRenderer *renderer, uint32_t *count)
```

**Description**

Obtains the number of underloaded audio streams of an audio capturer.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| count | Pointer to a variable used to receive the number of underloaded audio streams. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:

  1. The **renderer** parameter is set to a null pointer.
  2. The **count** parameter is set to a null pointer.


### OH_AudioRenderer_GetVolume()

```
OH_AudioStream_Result OH_AudioRenderer_GetVolume (OH_AudioRenderer *renderer, float *volume)
```

**Description**

Obtains the volume of an audio stream.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| volume | Pointer to the audio volume, in the range of [0.0, 1.0]. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:

  1. The **renderer** parameter is set to a null pointer.
  2. The **volume** parameter is set to a null pointer.


### OH_AudioRenderer_Pause()

```
OH_AudioStream_Result OH_AudioRenderer_Pause(OH_AudioRenderer *renderer)
```

**Description**

Pauses an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.

**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.


### OH_AudioRenderer_Release()

```
OH_AudioStream_Result OH_AudioRenderer_Release(OH_AudioRenderer *renderer)
```

**Description**

Releases an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.

**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.


### OH_AudioRenderer_SetDefaultOutputDevice()

```
OH_AudioStream_Result OH_AudioRenderer_SetDefaultOutputDevice (OH_AudioRenderer* renderer, OH_AudioDevice_Type deviceType)
```

**Description**

Sets the default built-in audio output device.

This function applies only to the scenario where [OH_AudioStream_Usage](#oh_audiostream_usage) is set to voice messages, VoIP voice calls, and VoIP video calls and the available device types are the receiver, speaker, and system default device.

This function can be called at any time after an **AudioRenderer** instance is created. The system records the default built-in audio output device set by the application. When the application is started, if an external device such as a Bluetooth or wired headset is connected, the system preferentially uses the external device to play sound. Otherwise, the system uses this default device to play sound.

**Since**: 12

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| deviceType | Device type. For details about the available options, see [OH_AudioDevice_Type](#oh_audiodevice_type).<br>The device types that can be set are as follows:<br>**AUDIO_DEVICE_TYPE_EARPIECE**: receiver.<br>**AUDIO_DEVICE_TYPE_SPEAKER**: speaker.<br>**AUDIO_DEVICE_TYPE_DEFAULT**: system default device. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

AUDIOSTREAM_ERROR_INVALID_PARAM:

1. The **renderer** parameter is set to a null pointer.
2. The **deviceType** parameter is set to an invalid value.

**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.

**AUDIOSTREAM_ERROR_SYSTEM**: A system error occurs.


### OH_AudioRenderer_SetEffectMode()

```
OH_AudioStream_Result OH_AudioRenderer_SetEffectMode (OH_AudioRenderer *renderer, OH_AudioStream_AudioEffectMode effectMode)
```

**Description**

Sets the effect mode for an audio stream.

**Since**: 12

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| effectMode | Effect mode to set. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.


### OH_AudioRenderer_SetMarkPosition()

```
OH_AudioStream_Result OH_AudioRenderer_SetMarkPosition (OH_AudioRenderer *renderer, uint32_t samplePos, OH_AudioRenderer_OnMarkReachedCallback callback, void *userData)
```

**Description**

Sets the mark position for an audio renderer. When this function is called, the mark position that has been set will be overwritten.

**Since**: 12

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| samplePos | Mark position. |
| callback | When the target mark position is reached, [OH_AudioRenderer_OnMarkReachedCallback](#oh_audiorenderer_onmarkreachedcallback) is invoked. |
| userData | Pointer to the application data passed through the callback functions. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:

  1. The **renderer** parameter is set to a null pointer.
  2. The **samplePos** parameter is set to an invalid value.

**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.

**AUDIOSTREAM_ERROR_SYSTEM**: A system error occurs.


### OH_AudioRenderer_SetSilentModeAndMixWithOthers()

```
OH_AudioStream_Result OH_AudioRenderer_SetSilentModeAndMixWithOthers (OH_AudioRenderer *renderer, bool on)
```

**Description**

Sets the silent mode in concurrent playback for an audio stream.

**Since**: 12

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| on | Status of the silent mode in concurrent playback. **true**: The audio stream being played is muted and the playback of other audio streams is not interrupted. **false**: The audio stream being played is unmuted and can gain focus based on the system focus policy. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOSTREAM_SUCCESS**: The function is executed successfully.

**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.


### OH_AudioRenderer_SetSpeed()

```
OH_AudioStream_Result OH_AudioRenderer_SetSpeed (OH_AudioRenderer *renderer, float speed)
```

**Description**

Sets the audio renderer rate.

**Since**: 11

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| speed | Playback speed, which ranges from 0.25 to 4.0. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.


### OH_AudioRenderer_SetVolume()

```
OH_AudioStream_Result OH_AudioRenderer_SetVolume (OH_AudioRenderer *renderer, float volume)
```

**Description**

Sets the volume for an audio stream.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| volume | Target volume, in the range of [0.0, 1.0]. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:

  1. The **renderer** parameter is set to a null pointer.
  2. The **volume** parameter is set to an invalid value.

**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.

**AUDIOSTREAM_ERROR_SYSTEM**: A system error occurs.


### OH_AudioRenderer_SetVolumeWithRamp()

```
OH_AudioStream_Result OH_AudioRenderer_SetVolumeWithRamp (OH_AudioRenderer *renderer, float volume, int32_t durationMs)
```

**Description**

Sets the volume with a ramp within the specified duration for an audio stream.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |
| volume | Target volume, in the range of [0.0, 1.0]. |
| durationMs | Duration, in milliseconds. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:

  1. The **renderer** parameter is set to a null pointer.
  2. The **volume** parameter is set to an invalid value.

**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.

**AUDIOSTREAM_ERROR_SYSTEM**: A system error occurs.


### OH_AudioRenderer_Start()

```
OH_AudioStream_Result OH_AudioRenderer_Start(OH_AudioRenderer *renderer)
```

**Description**

Starts an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOSTREAM_SUCCESS**: The function is executed successfully.

**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.

**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.


### OH_AudioRenderer_Stop()

```
OH_AudioStream_Result OH_AudioRenderer_Stop(OH_AudioRenderer *renderer)
```

**Description**

Stops an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **renderer** parameter is set to a null pointer.

**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.


### OH_AudioRoutingManager_GetAvailableDevices()

```
OH_AudioCommon_Result OH_AudioRoutingManager_GetAvailableDevices (OH_AudioRoutingManager *audioRoutingManager, OH_AudioDevice_Usage deviceUsage, OH_AudioDeviceDescriptorArray **audioDeviceDescriptorArray)
```

**Description**

Obtains the available audio devices.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioRoutingManager | Pointer to an [OH_AudioRoutingManager](#oh_audioroutingmanager) instance, which is created by calling [OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager). |
| deviceUsage | Usage scenario of the audio devices. For details about the available options, see [OH_AudioDevice_Usage](#oh_audiodevice_usage). |
| audioDeviceDescriptorArray | Double pointer to the audio device descriptors in the array. For details, see [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md). Do not release the pointer to the **audioDeviceDescriptorArray** struct separately. Instead, call [OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices) to release the device descriptor array.|

**Returns**

Returns a result code defined in [OH_AudioCommon_Result](#oh_audiocommon_result). The following result codes are possible:

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:
1. The **audioRoutingManager** parameter is set to a null pointer.
2. The **deviceUsage** parameter is set to an invalid value.
3. The **audioDeviceDescriptorArray** parameter is set to a null pointer.

**AUDIOCOMMON_RESULT_ERROR_NO_MEMORY**: The memory is insufficient.


### OH_AudioRoutingManager_GetDevices()

```
OH_AudioCommon_Result OH_AudioRoutingManager_GetDevices (OH_AudioRoutingManager *audioRoutingManager, OH_AudioDevice_Flag deviceFlag, OH_AudioDeviceDescriptorArray **audioDeviceDescriptorArray)
```

**Description**

Obtains available devices based on the device flag.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioRoutingManager | Pointer to an [OH_AudioRoutingManager](#oh_audioroutingmanager) object. which is obtained by calling [OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager).|
| deviceFlag | Device flag, which is used to filter the target device. For details about the available options, see [OH_AudioDevice_Flag](#oh_audiodevice_flag).|
| audioDeviceDescriptorArray | Pointer to the audio device descriptor array, which is [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md). Do not release the pointer to the **audioDeviceDescriptorArray** struct separately. Instead, call [OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices) to release the **DeviceDescriptor** array.|

**Returns**

Returns a result code defined in [OH_AudioCommon_Result](#oh_audiocommon_result). The following result codes are possible:

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:

  1. The **audioRoutingManager** parameter is set to a null pointer.
  2. The **deviceFlag** parameter is set to an invalid value.
  3. The **audioDeviceDescriptorArray** parameter is set to a null pointer.

**AUDIOCOMMON_RESULT_ERROR_NO_MEMORY**: The memory is insufficient.

### OH_AudioRoutingManager_GetPreferredInputDevice()

```
OH_AudioCommon_Result OH_AudioRoutingManager_GetPreferredInputDevice (OH_AudioRoutingManager *audioRoutingManager, OH_AudioStream_SourceType sourceType, OH_AudioDeviceDescriptorArray **audioDeviceDescriptorArray )
```

**Description**

Obtains the input device with the highest priority based on the usage scenario of an audio input stream.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioRoutingManager | Pointer to an [OH_AudioRoutingManager](#oh_audioroutingmanager) instance, which is created by calling [OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager). |
| sourceType | Usage scenario of an audio input stream. For details about the available options, see [OH_AudioStream_SourceType](#oh_audiostream_sourcetype). |
| audioDeviceDescriptorArray | Double pointer to the audio device descriptors in the array. For details, see [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md). Do not release the pointer to the **audioDeviceDescriptorArray** struct separately. Instead, call [OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices) to release the device descriptor array.|

**Returns**

Returns a result code defined in [OH_AudioCommon_Result](#oh_audiocommon_result). The following result codes are possible:

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:

1. The **audioRoutingManager** parameter is set to a null pointer.
2. The **sourceType** parameter is set to an invalid value.
3. The **audioDeviceDescriptorArray** parameter is set to a null pointer.

**AUDIOCOMMON_RESULT_ERROR_NO_MEMORY**: The memory is insufficient.


### OH_AudioRoutingManager_GetPreferredOutputDevice()

```
OH_AudioCommon_Result OH_AudioRoutingManager_GetPreferredOutputDevice (OH_AudioRoutingManager *audioRoutingManager, OH_AudioStream_Usage streamUsage, OH_AudioDeviceDescriptorArray **audioDeviceDescriptorArray )
```

**Description**

Obtains the output device with the highest priority based on the usage scenario of an audio output stream.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioRoutingManager | Pointer to an [OH_AudioRoutingManager](#oh_audioroutingmanager) instance, which is created by calling [OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager). |
| streamUsage | Usage scenario of an audio output stream. For details about the available options, see [OH_AudioStream_Usage](#oh_audiostream_usage). |
| audioDeviceDescriptorArray | Double pointer to the audio device descriptors in the array. For details, see [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md). Do not release the pointer to the **audioDeviceDescriptorArray** struct separately. Instead, call [OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices) to release the device descriptor array.|

**Returns**

Returns a result code defined in [OH_AudioCommon_Result](#oh_audiocommon_result). The following result codes are possible:

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:

1. The **audioRoutingManager** parameter is set to a null pointer.
2. The **streamUsage** parameter is set to an invalid value.
3. The **audioDeviceDescriptorArray** parameter is set to a null pointer.

**AUDIOCOMMON_RESULT_ERROR_NO_MEMORY**: The memory is insufficient.


### OH_AudioRoutingManager_RegisterDeviceChangeCallback()

```
OH_AudioCommon_Result OH_AudioRoutingManager_RegisterDeviceChangeCallback (OH_AudioRoutingManager *audioRoutingManager, OH_AudioDevice_Flag deviceFlag, OH_AudioRoutingManager_OnDeviceChangedCallback callback)
```


**Description**

Registers a callback to listen for device changes of an audio routing manager.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioRoutingManager | Pointer to an [OH_AudioRoutingManager](#oh_audioroutingmanager) object. which is obtained by calling [OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager).|
| deviceFlag | Device flag. For details about the available options, see [OH_AudioDevice_Flag](#oh_audiodevice_flag).|
| callback | Callback function used to return the changed audio device descriptor. For details, see [OH_AudioRoutingManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback).|

**Returns**

Returns a result code defined in [OH_AudioCommon_Result](#oh_audiocommon_result). The following result codes are possible:

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:

  1. The **audioRoutingManager** parameter is set to a null pointer.
  2. The **deviceFlag** parameter is set to an invalid value.
  3. The **callback** parameter is set to a null pointer.


### OH_AudioRoutingManager_ReleaseDevices()

```
OH_AudioCommon_Result OH_AudioRoutingManager_ReleaseDevices (OH_AudioRoutingManager *audioRoutingManager, OH_AudioDeviceDescriptorArray *audioDeviceDescriptorArray)
```

**Description**

Releases audio devices available for an audio routing manager.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioRoutingManager | Pointer to an [OH_AudioRoutingManager](#oh_audioroutingmanager) object. which is obtained by calling [OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager).|
| audioDeviceDescriptorArray | Pointer to the array of audio devices, which are obtained by calling [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices).|

**Returns**

Returns a result code defined in [OH_AudioCommon_Result](#oh_audiocommon_result). The following result codes are possible:

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:

  1. The **audioRoutingManager** parameter is set to a null pointer.
  2. The **audioDeviceDescriptorArray** parameter is set to a null pointer.


### OH_AudioRoutingManager_UnregisterDeviceChangeCallback()

```
OH_AudioCommon_Result OH_AudioRoutingManager_UnregisterDeviceChangeCallback (OH_AudioRoutingManager *audioRoutingManager, OH_AudioRoutingManager_OnDeviceChangedCallback callback)
```

**Description**

Unregisters the callback used to listen for device changes of an audio routing manager.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioRoutingManager | Pointer to an [OH_AudioRoutingManager](#oh_audioroutingmanager) object. which is obtained by calling [OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager).|
| callback | Callback function used to return the changed audio device descriptor. For details, see [OH_AudioRoutingManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback).|

**Returns**

Returns a result code defined in [OH_AudioCommon_Result](#oh_audiocommon_result). The following result codes are possible:

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:

  1. The **audioRoutingManager** parameter is set to a null pointer.
  2. The **callback** parameter is set to a null pointer.


### OH_AudioSessionManager_ActivateAudioSession()

```
OH_AudioCommon_Result OH_AudioSessionManager_ActivateAudioSession (OH_AudioSessionManager *audioSessionManager, const OH_AudioSession_Strategy *strategy )
```

**Description**

Activates an audio session.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioSessionManager | Pointer to an [OH_AudioSessionManager](#oh_audiosessionmanager) instance, which is created by calling [OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager). |
| strategy | Pointer to a session strategy. For details about the available options, see [OH_AudioSession_Strategy](_o_h___audio_session___strategy.md). |

**Returns**

Returns a result code defined in [OH_AudioCommon_Result](#oh_audiocommon_result). The following result codes are possible:

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:

1. The **audioSessionManager** parameter is set to a null pointer.
2. The **strategy** parameter is set to an invalid value. **AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE**: Invalid state.


### OH_AudioSessionManager_DeactivateAudioSession()

```
OH_AudioCommon_Result OH_AudioSessionManager_DeactivateAudioSession (OH_AudioSessionManager *audioSessionManager)
```

**Description**

Deactivates an audio session.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioSessionManager | Pointer to an [OH_AudioSessionManager](#oh_audiosessionmanager) instance, which is created by calling [OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager). |

**Returns**

Returns a result code defined in [OH_AudioCommon_Result](#oh_audiocommon_result). The following result codes are possible:

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **audioSessionManager** parameter is set to a null pointer.

**AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE**: Invalid state.


### OH_AudioSessionManager_IsAudioSessionActivated()

```
bool OH_AudioSessionManager_IsAudioSessionActivated (OH_AudioSessionManager *audioSessionManager)
```

**Description**

Checks whether an audio session is activated.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioSessionManager | Pointer to an [OH_AudioSessionManager](#oh_audiosessionmanager) instance, which is created by calling [OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager). |

**Returns**

Returns **true** if the audio session is activated; returns **false** otherwise.


### OH_AudioSessionManager_RegisterSessionDeactivatedCallback()

```
OH_AudioCommon_Result OH_AudioSessionManager_RegisterSessionDeactivatedCallback (OH_AudioSessionManager *audioSessionManager, OH_AudioSession_DeactivatedCallback callback)
```

**Description**

Registers a callback to listen for audio session deactivation events.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioSessionManager | Pointer to an [OH_AudioSessionManager](#oh_audiosessionmanager) instance, which is created by calling [OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager). |
| callback | Callback used to receive the audio session deactivation event. For details, see [OH_AudioSessionDeactivatedCallback](#oh_audiosession_deactivatedcallback). |

**Returns**

Returns a result code defined in [OH_AudioCommon_Result](#oh_audiocommon_result). The following result codes are possible:

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:

1. The **audioSessionManager** parameter is set to a null pointer.
2. The **callback** parameter is set to a null pointer.


### OH_AudioSessionManager_UnregisterSessionDeactivatedCallback()

```
OH_AudioCommon_Result OH_AudioSessionManager_UnregisterSessionDeactivatedCallback (OH_AudioSessionManager *audioSessionManager, OH_AudioSession_DeactivatedCallback callback)
```

**Description**

Unregisters the callback used to listen for audio session deactivation events.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioSessionManager | Pointer to an [OH_AudioSessionManager](#oh_audiosessionmanager) instance, which is created by calling [OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager). |
| callback | Callback used to receive the audio session deactivation event. For details, see [OH_AudioSessionDeactivatedCallback](#oh_audiosession_deactivatedcallback). |

**Returns**

Returns a result code defined in [OH_AudioCommon_Result](#oh_audiocommon_result). The following result codes are possible:

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:

1. The **audioSessionManager** parameter is set to a null pointer.
2. The **callback** parameter is set to a null pointer.


### OH_AudioStreamBuilder_Create()

```
OH_AudioStream_Result OH_AudioStreamBuilder_Create(OH_AudioStreamBuilder **builder, OH_AudioStream_Type type)
```

**Description**

Creates an audio stream builder, which can be an audio renderer or capturer.

You need to call **OH_AudioStreamBuilder_Destroy()** to destroy the builder when it is no longer required.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| builder | Double pointer to the audio stream builder created. |
| type | Type of the audio stream builder,AUDIOSTREAM_TYPE_RENDERER or AUDIOSTREAM_TYPE_CAPTURER |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.


### OH_AudioStreamBuilder_Destroy()

```
OH_AudioStream_Result OH_AudioStreamBuilder_Destroy(OH_AudioStreamBuilder *builder)
```

**Description**

Destroys an audio stream builder when it is no longer required.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| builder | Pointer to an audio stream builder instance, which is created by calling **OH_AudioStreamBuilder_Create()**. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **builder** parameter is set to a null pointer.

**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.


### OH_AudioStreamBuilder_GenerateCapturer()

```
OH_AudioStream_Result OH_AudioStreamBuilder_GenerateCapturer(OH_AudioStreamBuilder *builder, OH_AudioCapturer **audioCapturer)
```

**Description**

Creates an audio capturer instance.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| builder | Pointer to an audio stream builder instance, which is created by calling **OH_AudioStreamBuilder_Create()**. |
| audioCapturer | Double pointer to the audio capturer instance created. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOSTREAM_ERROR_INVALID_PARAM**:

  1. The **builder** parameter is set to a null pointer.
  2. The **StreamType** parameter is set to an invalid value.
  3. The **OHAudioRenderer** instance fails to be created.


### OH_AudioStreamBuilder_GenerateRenderer()

```
OH_AudioStream_Result OH_AudioStreamBuilder_GenerateRenderer(OH_AudioStreamBuilder *builder, OH_AudioRenderer **audioRenderer)
```

**Description**

Creates an audio renderer instance.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| builder | Pointer to an audio stream builder instance, which is created by calling **OH_AudioStreamBuilder_Create()**. |
| audioRenderer | Double pointer to the audio renderer instance created. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOSTREAM_ERROR_INVALID_PARAM**:

  1. The **builder** parameter is set to a null pointer.
  2. The **StreamType** parameter is set to an invalid value.
  3. The **OHAudioRenderer** instance fails to be created.


### OH_AudioStreamBuilder_SetCapturerCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerCallback(OH_AudioStreamBuilder *builder, OH_AudioCapturer_Callbacks callbacks, void *userData)
```

**Description**

Sets callbacks for an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| builder | Pointer to an audio stream builder instance, which is created by calling **OH_AudioStreamBuilder_Create()**. |
| callbacks | Callback functions that will be used to process events related to audio input streams. |
| userData | Pointer to the application data passed through the callback functions. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOSTREAM_ERROR_INVALID_PARAM**:

  1. The **builder** parameter is set to a null pointer.
  2. The **StreamType** parameter is set to an invalid value.


### OH_AudioStreamBuilder_SetCapturerInfo()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerInfo(OH_AudioStreamBuilder *builder, OH_AudioStream_SourceType sourceType)
```

**Description**

Sets the usage scenario of an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| builder | Pointer to an audio stream builder instance, which is created by calling **OH_AudioStreamBuilder_Create()**. |
| sourceType | Usage scenario of the audio capturer. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOSTREAM_ERROR_INVALID_PARAM**:

  1. The **builder** parameter is set to a null pointer.
  2. The **sourceType** parameter is set to an invalid value.


### OH_AudioStreamBuilder_SetChannelCount()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetChannelCount(OH_AudioStreamBuilder *builder, int32_t channelCount)
```

**Description**

Sets the number of channels for an audio stream.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| builder | Pointer to an audio stream builder instance, which is created by calling **OH_AudioStreamBuilder_Create()**. |
| channelCount | Number of channels. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOSTREAM_ERROR_INVALID_PARAM**:

  1. The **builder** parameter is set to a null pointer.
  2. The **channelCount** parameter is set to an invalid value.


### OH_AudioStreamBuilder_SetChannelLayout()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetChannelLayout (OH_AudioStreamBuilder *builder, OH_AudioChannelLayout channelLayout)
```

**Description**

Sets the channel layout for an audio stream.

**Since**: 12

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| builder | Pointer to an audio stream builder instance, which is created by calling **OH_AudioStreamBuilder_Create()**. |
| channelLayout | Channel layout. For details about the available options, see [OH_AudioChannelLayout](../apis-avcodec-kit/_core.md#oh_audiochannellayout-1). |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **builder** parameter is set to a null pointer.


### OH_AudioStreamBuilder_SetEncodingType()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetEncodingType(OH_AudioStreamBuilder *builder, OH_AudioStream_EncodingType encodingType)
```

**Description**

Sets the encoding type of an audio stream.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| builder | Pointer to an audio stream builder instance, which is created by calling **OH_AudioStreamBuilder_Create()**.|
| encodingType | Encoding type.|

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **builder** parameter is set to a null pointer.

### OH_AudioStreamBuilder_SetFrameSizeInCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetFrameSizeInCallback(OH_AudioStreamBuilder *builder, int32_t frameSize)
```

**Description**

Sets the frame size for each callback during playback. The frame size must be at least equal to the size of the data processed by the audio hardware at a time and less than half of the internal buffer capacity.

- In the case of low-latency playback, **frameSize** can be set to the frame length corresponding to the audio that lasts for 5 ms, 10 ms, 15 ms, or 20 ms.
- In the case of common playback, **frameSize** can be set to the frame length corresponding to the audio that lasts for 20 ms to 100 ms.

**Since**: 11

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| builder | Pointer to an audio stream builder instance, which is created by calling **OH_AudioStreamBuilder_Create()**. |
| frameSize | Frame size. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **builder** parameter is set to a null pointer.


### OH_AudioStreamBuilder_SetLatencyMode()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetLatencyMode(OH_AudioStreamBuilder *builder, OH_AudioStream_LatencyMode latencyMode)
```

**Description**

Sets the latency mode of an audio stream.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| builder | Pointer to an audio stream builder instance, which is created by calling **OH_AudioStreamBuilder_Create()**. |
| latencyMode | Latency mode. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **builder** parameter is set to a null pointer.


### OH_AudioStreamBuilder_SetRendererCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererCallback(OH_AudioStreamBuilder *builder, OH_AudioRenderer_Callbacks callbacks, void *userData)
```

**Description**

Sets callbacks for an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| builder | Pointer to an audio stream builder instance, which is created by calling **OH_AudioStreamBuilder_Create()**. |
| callbacks | Callback functions that will be used to process events related to audio output streams. |
| userData | Pointer to the application data passed through the callback functions. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOSTREAM_ERROR_INVALID_PARAM**:

  1. The **builder** parameter is set to a null pointer.
  2. The **StreamType** parameter is set to an invalid value.


### OH_AudioStreamBuilder_SetRendererInfo()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInfo(OH_AudioStreamBuilder *builder, OH_AudioStream_Usage usage)
```

**Description**

Sets the usage scenario of an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| builder | Pointer to an audio stream builder instance, which is created by calling **OH_AudioStreamBuilder_Create()**. |
| usage | Usage scenario of the audio renderer. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOSTREAM_ERROR_INVALID_PARAM**:

  1. The **builder** parameter is set to a null pointer.
  2. The **usage** parameter is set to an invalid value.


### OH_AudioStreamBuilder_SetRendererInterruptMode()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInterruptMode (OH_AudioStreamBuilder *builder, OH_AudioInterrupt_Mode mode)
```

**Description**

Sets the interrupt mode of the stream client.

**Since**: 12

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| builder | Pointer to an audio stream builder instance, which is created by calling **OH_AudioStreamBuilder_Create()**. |
| mode | Audio interruption mode. For details about the available options, see [OH_AudioInterrupt_Mode](#oh_audiointerrupt_mode). |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOSTREAM_ERROR_INVALID_PARAM**:

  1. The **builder** parameter is set to a null pointer.
  2. The **mode** parameter is set to an invalid value.
  3. The **StreamType** parameter is set to an invalid value.


### OH_AudioStreamBuilder_SetRendererOutputDeviceChangeCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererOutputDeviceChangeCallback (OH_AudioStreamBuilder * builder, OH_AudioRenderer_OutputDeviceChangeCallback callback, void * userData )
```

**Description**

Sets the callback invoked when the audio stream device changes.

**Since**: 11

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| builder | Pointer to an audio stream builder instance, which is created by calling **OH_AudioStreamBuilder_Create()**. |
| callbacks | Callback that will be used to process events related to audio stream device changes. |
| userData | Pointer to the application data passed through the callback functions. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOSTREAM_ERROR_INVALID_PARAM**:

  1. The **builder** parameter is set to a null pointer.
  2. The **StreamType** parameter is set to an invalid value.


### OH_AudioStreamBuilder_SetRendererPrivacy()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererPrivacy (OH_AudioStreamBuilder * builder, OH_AudioStream_PrivacyType privacy)
```

**Description**

Sets the privacy type for the audio stream being played. The privacy type specifies whether the audio stream can be recorded by other applications.

**Since**: 12

**System capability**: SystemCapability.Multimedia.Audio.PlaybackCapture

**Parameters**

| Name| Description|
| -------- | -------- |
| builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create()](#oh_audiostreambuilder_create). |
| privacy | Privacy type, which specifies whether the audio stream can be recorded by other applications. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOSTREAM_ERROR_INVALID_PARAM**:

  1. The **builder** parameter is set to a null pointer.
  2. The **StreamType** parameter is set to an invalid value.


### OH_AudioStreamBuilder_SetRendererWriteDataCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererWriteDataCallback (OH_AudioStreamBuilder *builder, OH_AudioRenderer_OnWriteDataCallback callback, void *userData)
```

**Description**

Sets the callback used to write audio data.

This function is similar to [OH_AudioStreamBuilder_SetRendererCallback](#oh_audiostreambuilder_setrenderercallback). Only the last callback function set through **OH_AudioStreamBuilder_SetRendererCallback** or this function can be invoked.

**Since**: 12

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| builder | Pointer to an audio stream builder instance, which is created by calling **OH_AudioStreamBuilder_Create()**. |
| callback | Callback function to be used to write audio data. |
| userData | Pointer to the application data passed through the callback functions. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOSTREAM_SUCCESS**: The function is executed successfully.

**AUDIOSTREAM_ERROR_INVALID_PARAM**:

  1. The **builder** parameter is set to a null pointer.
  2. The **StreamType** parameter is set to an invalid value.


### OH_AudioStreamBuilder_SetSampleFormat()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetSampleFormat(OH_AudioStreamBuilder *builder, OH_AudioStream_SampleFormat format)
```

**Description**

Sets the sampling format of an audio stream.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| builder | Pointer to an audio stream builder instance, which is created by calling **OH_AudioStreamBuilder_Create()**. |
| format | Sampling format. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **builder** parameter is set to a null pointer.


### OH_AudioStreamBuilder_SetSamplingRate()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetSamplingRate(OH_AudioStreamBuilder *builder, int32_t rate)
```

**Description**

Sets the sampling rate of an audio stream.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| builder | Pointer to an audio stream builder instance, which is created by calling **OH_AudioStreamBuilder_Create()**. |
| channelCount | Sampling rate. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOSTREAM_ERROR_INVALID_PARAM**:

  1. The **builder** parameter is set to a null pointer.
  2. The **rate** parameter is set to an invalid value.


### OH_AudioStreamBuilder_SetWriteDataWithMetadataCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetWriteDataWithMetadataCallback (OH_AudioStreamBuilder *builder, OH_AudioRenderer_WriteDataWithMetadataCallback callback, void *userData)
```

**Description**

Sets the callback invoked to write both audio data and metadata.

**Since**: 12

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description|
| -------- | -------- |
| builder | Pointer to an audio stream builder instance, which is created by calling **OH_AudioStreamBuilder_Create()**. |
| callback | Callback used to write both audio data and metadata. |
| userData | Pointer to the application data passed through the callback functions. |

**Returns**

Returns a result code defined in [OH_AudioStream_Result](#oh_audiostream_result):

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOSTREAM_ERROR_INVALID_PARAM**:

  1. The **builder** parameter is set to a null pointer.
  2. The **StreamType** parameter is set to an invalid value.


### OH_GetAudioManager()

```
OH_AudioCommon_Result OH_GetAudioManager (OH_AudioManager ** audioManager)
```

**Description**

Obtains an **OH_AudioManager** instance.

Before using the features related to the audio manager, you must obtain an **OH_AudioManager** instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioManager | Double pointer to the [OH_AudioManager](#oh_audiomanager) instance created. |

**Returns**

Returns a result code defined in [OH_AudioCommon_Result](#oh_audiocommon_result). The following result codes are possible:

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **audioManager** parameter is set to a null pointer.


### OH_GetAudioScene()

```
OH_AudioCommon_Result OH_GetAudioScene (OH_AudioManager * manager, OH_AudioScene * scene )
```

**Description**

Obtains the audio scene.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| audioManager | Pointer to an [OH_AudioManager](#oh_audiomanager) instance, which is created by calling [OH_GetAudioManager](#oh_getaudiomanager). |
| scene | Pointer to an audio scene. For details about the available options, see [OH_AudioScene](#oh_audioscene). |

**Returns**

Returns a result code defined in [OH_AudioCommon_Result](#oh_audiocommon_result). The following result codes are possible:

**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.

**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:

1. The **audioManager** parameter is set to a null pointer.
2. The **scene** parameter is set to a null pointer.
