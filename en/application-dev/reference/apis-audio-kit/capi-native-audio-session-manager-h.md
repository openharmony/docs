# native_audio_session_manager.h
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the functions related to an audio session manager.

You can call the functions to create an audio session manager, activate or deactivate an audio session, check whether an audio session is activated, and listen for audio session deactivation events.

**File to include**: <ohaudio/native_audio_session_manager.h>

**Library**: libohaudio.so

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

**Related module**: [OHAudio](capi-ohaudio.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioSession_Strategy](capi-ohaudio-oh-audiosession-strategy.md) | OH_AudioSession_Strategy | Describes the audio session strategy.|
| [OH_AudioSession_DeactivatedEvent](capi-ohaudio-oh-audiosession-deactivatedevent.md) | OH_AudioSession_DeactivatedEvent | Describes the event indicating that an audio session is deactivated.|
| [OH_AudioSession_StateChangedEvent](capi-ohaudio-oh-audiosession-statechangedevent.md) | OH_AudioSession_StateChangedEvent | Describes the event indicating that the audio session state changes.|
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) | OH_AudioSessionManager | Describes an audio session manager, which is used to manage audio sessions.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioSession_ConcurrencyMode](#oh_audiosession_concurrencymode) | OH_AudioSession_ConcurrencyMode | Enumerates the audio concurrency modes.|
| [OH_AudioSession_Scene](#oh_audiosession_scene) | OH_AudioSession_Scene | Enumerates the audio session scenes.|
| [OH_AudioSession_StateChangeHint](#oh_audiosession_statechangehint) | OH_AudioSession_StateChangeHint | Enumerates the hints for audio session state changes.|
| [OH_AudioSession_OutputDeviceChangeRecommendedAction](#oh_audiosession_outputdevicechangerecommendedaction) | OH_AudioSession_OutputDeviceChangeRecommendedAction | Enumerates the recommended actions to take after an output device changes.|
| [OH_AudioSession_DeactivatedReason](#oh_audiosession_deactivatedreason) | OH_AudioSession_DeactivatedReason | Enumerates the reasons for deactivating an audio session.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_AudioSession_StateChangedCallback)(OH_AudioSession_StateChangedEvent event)](#oh_audiosession_statechangedcallback) | OH_AudioSession_StateChangedCallback | Defines a function pointer to the callback used to listen for audio session state change events.|
| [typedef void (\*OH_AudioSession_CurrentOutputDeviceChangedCallback)(OH_AudioDeviceDescriptorArray *devices, OH_AudioStream_DeviceChangeReason changeReason, OH_AudioSession_OutputDeviceChangeRecommendedAction recommendedAction)](#oh_audiosession_currentoutputdevicechangedcallback) | OH_AudioSession_CurrentOutputDeviceChangedCallback | Defines a function pointer to the callback used to listen for the current output device change events.|
| [typedef int32_t (\*OH_AudioSession_DeactivatedCallback)(OH_AudioSession_DeactivatedEvent event)](#oh_audiosession_deactivatedcallback) | OH_AudioSession_DeactivatedCallback | Defines a function pointer to the callback used to listen for audio session deactivation events.|
| [OH_AudioCommon_Result OH_AudioManager_GetAudioSessionManager(OH_AudioSessionManager **audioSessionManager)](#oh_audiomanager_getaudiosessionmanager) | - | Obtains an OH_AudioSessionManager instance. Before using the features related to the audio session manager, you must obtain an OH_AudioSessionManager instance.|
| [OH_AudioCommon_Result OH_AudioSessionManager_ActivateAudioSession(OH_AudioSessionManager *audioSessionManager, const OH_AudioSession_Strategy *strategy)](#oh_audiosessionmanager_activateaudiosession) | - | Activates an audio session.|
| [OH_AudioCommon_Result OH_AudioSessionManager_DeactivateAudioSession(OH_AudioSessionManager *audioSessionManager)](#oh_audiosessionmanager_deactivateaudiosession) | - | Deactivates an audio session.|
| [bool OH_AudioSessionManager_IsAudioSessionActivated(OH_AudioSessionManager *audioSessionManager)](#oh_audiosessionmanager_isaudiosessionactivated) | - | Checks whether an audio session is activated.|
| [OH_AudioCommon_Result OH_AudioSessionManager_RegisterSessionDeactivatedCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_DeactivatedCallback callback)](#oh_audiosessionmanager_registersessiondeactivatedcallback) | - | Registers a callback to listen for audio session deactivation events.|
| [OH_AudioCommon_Result OH_AudioSessionManager_UnregisterSessionDeactivatedCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_DeactivatedCallback callback)](#oh_audiosessionmanager_unregistersessiondeactivatedcallback) | - | Unregisters the callback used to listen for audio session deactivation events.|
| [OH_AudioCommon_Result OH_AudioSessionManager_SetScene(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_Scene scene)](#oh_audiosessionmanager_setscene) | - | Sets an audio session scene.|
| [OH_AudioCommon_Result OH_AudioSessionManager_RegisterStateChangeCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_StateChangedCallback callback)](#oh_audiosessionmanager_registerstatechangecallback) | - | Registers a callback to listen for audio session state change events.|
| [OH_AudioCommon_Result OH_AudioSessionManager_UnregisterStateChangeCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_StateChangedCallback callback)](#oh_audiosessionmanager_unregisterstatechangecallback) | - | Unregisters the callback used to listen for audio session state change events.|
| [OH_AudioCommon_Result OH_AudioSessionManager_SetDefaultOutputDevice(OH_AudioSessionManager *audioSessionManager, OH_AudioDevice_Type deviceType)](#oh_audiosessionmanager_setdefaultoutputdevice) | - | Sets the default audio output device.|
| [OH_AudioCommon_Result OH_AudioSessionManager_GetDefaultOutputDevice(OH_AudioSessionManager *audioSessionManager, OH_AudioDevice_Type *deviceType)](#oh_audiosessionmanager_getdefaultoutputdevice) | - | Obtains the default audio output device set by [OH_AudioSessionManager_SetDefaultOutputDevice](#oh_audiosessionmanager_setdefaultoutputdevice).|
| [OH_AudioCommon_Result OH_AudioSessionManager_ReleaseDevices(OH_AudioSessionManager *audioSessionManager, OH_AudioDeviceDescriptorArray *audioDeviceDescriptorArray)](#oh_audiosessionmanager_releasedevices) | - | Releases audio devices available for an audio routing manager.|
| [OH_AudioCommon_Result OH_AudioSessionManager_RegisterCurrentOutputDeviceChangeCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_CurrentOutputDeviceChangedCallback callback)](#oh_audiosessionmanager_registercurrentoutputdevicechangecallback) | - | Registers a callback to listen for the current output device change events.|
| [OH_AudioCommon_Result OH_AudioSessionManager_UnregisterCurrentOutputDeviceChangeCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_CurrentOutputDeviceChangedCallback callback)](#oh_audiosessionmanager_unregistercurrentoutputdevicechangecallback) | - | Unregisters the callback used to listen for the current output device change events.|

## Enum Description

### OH_AudioSession_ConcurrencyMode

```
enum OH_AudioSession_ConcurrencyMode
```

**Description**

Enumerates the audio concurrency modes.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| CONCURRENCY_DEFAULT = 0 | Uses the system strategy by default.|
| CONCURRENCY_MIX_WITH_OTHERS = 1 | Mixes audio with other applications that are playing audio.|
| CONCURRENCY_DUCK_OTHERS = 2 | Lowers the volume of the application that is currently playing the audio.|
| CONCURRENCY_PAUSE_OTHERS = 3 | Pauses the application that is currently playing the audio.|

### OH_AudioSession_Scene

```
enum OH_AudioSession_Scene
```

**Description**

Enumerates the audio session scenes.

**Since**: 20

| Enum Item| Description|
| -- | -- |
| AUDIO_SESSION_SCENE_MEDIA = 0 | Media audio session.|
| AUDIO_SESSION_SCENE_GAME = 1 | Game audio session.|
| AUDIO_SESSION_SCENE_VOICE_COMMUNICATION = 2 | VoIP voice call audio session.|

### OH_AudioSession_StateChangeHint

```
enum OH_AudioSession_StateChangeHint
```

**Description**

Enumerates the hints for audio session state changes.

**Since**: 20

| Enum Item| Description|
| -- | -- |
| AUDIO_SESSION_STATE_CHANGE_HINT_RESUME = 0 | A hint is displayed, indicating that the audio session is resuming. The application can proactively trigger operations such as rendering.|
| AUDIO_SESSION_STATE_CHANGE_HINT_PAUSE = 1 | A hint is displayed, indicating that the audio session is paused and the audio focus is lost temporarily. When focus is regained, the AUDIO_SESSION_STATE_CHANGE_HINT_RESUME event is received.|
| AUDIO_SESSION_STATE_CHANGE_HINT_STOP = 2 | A hint is displayed, indicating that the audio session is stopped and the audio focus is lost permanently.|
| AUDIO_SESSION_STATE_CHANGE_HINT_TIME_OUT_STOP = 3 | A hint is displayed, indicating that the audio session is stopped by the system due to no activity, and the audio focus is lost.|
| AUDIO_SESSION_STATE_CHANGE_HINT_DUCK = 4 | A hint is displayed, indicating that audio ducking starts and the audio is played at a lower volume.|
| AUDIO_SESSION_STATE_CHANGE_HINT_UNDUCK = 5 | A hint is displayed, indicating that audio ducking ends and the audio is played at the normal volume.|

### OH_AudioSession_OutputDeviceChangeRecommendedAction

```
enum OH_AudioSession_OutputDeviceChangeRecommendedAction
```

**Description**

Enumerates the recommended actions to take after an output device changes.

**Since**: 20

| Enum Item| Description|
| -- | -- |
| DEVICE_CHANGE_RECOMMEND_TO_CONTINUE = 0 | Suggests continuing playback.|
| DEVICE_CHANGE_RECOMMEND_TO_STOP = 1 | Suggests stopping playback.|

### OH_AudioSession_DeactivatedReason

```
enum OH_AudioSession_DeactivatedReason
```

**Description**

Enumerates the reasons for deactivating an audio session.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| DEACTIVATED_LOWER_PRIORITY = 0 | The application focus is preempted.|
| DEACTIVATED_TIMEOUT = 1 | The application times out after the stream is stopped.|


## Function Description

### OH_AudioSession_StateChangedCallback()

```
typedef void (*OH_AudioSession_StateChangedCallback)(OH_AudioSession_StateChangedEvent event)
```

**Description**

Defines a function pointer to the callback used to listen for audio session state change events.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSession_StateChangedEvent](capi-ohaudio-oh-audiosession-statechangedevent.md) event | Pointer to the [OH_AudioSession_StateChangedEvent](capi-ohaudio-oh-audiosession-statechangedevent.md) event.|

### OH_AudioSession_CurrentOutputDeviceChangedCallback()

```
typedef void (*OH_AudioSession_CurrentOutputDeviceChangedCallback)(OH_AudioDeviceDescriptorArray *devices, OH_AudioStream_DeviceChangeReason changeReason, OH_AudioSession_OutputDeviceChangeRecommendedAction recommendedAction)
```

**Description**

Defines a function pointer to the callback used to listen for the current output device change events.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioDeviceDescriptorArray](capi-ohaudio-oh-audiodevicedescriptorarray.md) *devices | Pointer to the audio device descriptors in the array. For details, see [OH_AudioDeviceDescriptorArray](capi-ohaudio-oh-audiodevicedescriptorarray.md). Do not release the pointer to the audioDeviceDescriptorArray struct separately. Instead, call [OH_AudioSessionManager_ReleaseDevices](#oh_audiosessionmanager_releasedevices) to release the DeviceDescriptor array.|
| [OH_AudioStream_DeviceChangeReason](capi-native-audiostream-base-h.md#oh_audiostream_devicechangereason) changeReason | Pointer to [OH_AudioStream_DeviceChangeReason](capi-native-audiostream-base-h.md#oh_audiostream_devicechangereason), which is used to receive the device change reason.|
| [OH_AudioSession_OutputDeviceChangeRecommendedAction](#oh_audiosession_outputdevicechangerecommendedaction) recommendedAction | Pointer to [OH_AudioSession_OutputDeviceChangeRecommendedAction](#oh_audiosession_outputdevicechangerecommendedaction), which is used to receive the recommended action to take after the device change.|

### OH_AudioSession_DeactivatedCallback()

```
typedef int32_t (*OH_AudioSession_DeactivatedCallback)(OH_AudioSession_DeactivatedEvent event)
```

**Description**

Defines a function pointer to the callback used to listen for audio session deactivation events.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSession_DeactivatedEvent](capi-ohaudio-oh-audiosession-deactivatedevent.md) event | Pointer to OH_AudioSession_Deactivated_Event, which indicates that an audio session is deactivated.|

### OH_AudioManager_GetAudioSessionManager()

```
OH_AudioCommon_Result OH_AudioManager_GetAudioSessionManager(OH_AudioSessionManager **audioSessionManager)
```

**Description**

Obtains an OH_AudioSessionManager instance.

Before using the features related to the audio session manager, you must obtain an OH_AudioSessionManager instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) **audioSessionManager | Double pointer to the OH_AudioSessionManager instance obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: System error.|

### OH_AudioSessionManager_ActivateAudioSession()

```
OH_AudioCommon_Result OH_AudioSessionManager_ActivateAudioSession(OH_AudioSessionManager *audioSessionManager, const OH_AudioSession_Strategy *strategy)
```

**Description**

Activates an audio session.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to an audio session manager instance, which is created by calling [OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager).|
| const [OH_AudioSession_Strategy](capi-ohaudio-oh-audiosession-strategy.md) *strategy | Pointer to an audio session strategy, which is an [OH_AudioSession_Strategy](capi-ohaudio-oh-audiosession-strategy.md) struct.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) |         **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **strategy** parameter is invalid.<br>         **AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE**: Invalid state.|

### OH_AudioSessionManager_DeactivateAudioSession()

```
OH_AudioCommon_Result OH_AudioSessionManager_DeactivateAudioSession(OH_AudioSessionManager *audioSessionManager)
```

**Description**

Deactivates an audio session.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to an audio session manager instance, which is created by calling [OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **audioSessionManager** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE**: Invalid state.|

### OH_AudioSessionManager_IsAudioSessionActivated()

```
bool OH_AudioSessionManager_IsAudioSessionActivated(OH_AudioSessionManager *audioSessionManager)
```

**Description**

Checks whether an audio session is activated.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to an audio session manager instance, which is created by calling [OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager).|

**Returns**

| Type| Description|
| -- | -- |
| bool | Check result for whether the audio session is activated. **true** if activated, **false** otherwise.|

### OH_AudioSessionManager_RegisterSessionDeactivatedCallback()

```
OH_AudioCommon_Result OH_AudioSessionManager_RegisterSessionDeactivatedCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_DeactivatedCallback callback)
```

**Description**

Registers a callback to listen for audio session deactivation events.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to an audio session manager instance, which is created by calling [OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioSession_DeactivatedCallback](#oh_audiosession_deactivatedcallback) callback | OH_AudioSessionDeactivatedCallback, a callback used to receive the audio session deactivation event.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **callback** parameter is nullptr.|

### OH_AudioSessionManager_UnregisterSessionDeactivatedCallback()

```
OH_AudioCommon_Result OH_AudioSessionManager_UnregisterSessionDeactivatedCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_DeactivatedCallback callback)
```

**Description**

Unregisters the callback used to listen for audio session deactivation events.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to an audio session manager instance, which is created by calling [OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioSession_DeactivatedCallback](#oh_audiosession_deactivatedcallback) callback | OH_AudioSessionDeactivatedCallback, a callback used to receive the audio session deactivation event.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **callback** parameter is nullptr.|

### OH_AudioSessionManager_SetScene()

```
OH_AudioCommon_Result OH_AudioSessionManager_SetScene(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_Scene scene)
```

**Description**

Sets an audio session scene.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to an audio session manager instance, which is created by calling [OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioSession_Scene](#oh_audiosession_scene) scene | Audio session scene.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **scene** parameter is set to a value outside the valid enumeration range.<br>         **AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE**: The setting is not allowed in the current system state, for example, when the audio session is not ready.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system error occurs, such as an abnormal exit of a system service.|

### OH_AudioSessionManager_RegisterStateChangeCallback()

```
OH_AudioCommon_Result OH_AudioSessionManager_RegisterStateChangeCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_StateChangedCallback callback)
```

**Description**

Registers a callback to listen for audio session state change events.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to an audio session manager instance, which is created by calling [OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioSession_StateChangedCallback](#oh_audiosession_statechangedcallback) callback | Pointer to OH_AudioSession_StateChangedCallback, which is used to receive the audio session state change event.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **callback** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_NO_MEMORY**: Memory allocation fails.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system error occurs, such as an abnormal exit of a system service.|

### OH_AudioSessionManager_UnregisterStateChangeCallback()

```
OH_AudioCommon_Result OH_AudioSessionManager_UnregisterStateChangeCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_StateChangedCallback callback)
```

**Description**

Unregisters the callback used to listen for audio session state change events.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to an audio session manager instance, which is created by calling [OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioSession_StateChangedCallback](#oh_audiosession_statechangedcallback) callback | Pointer to OH_AudioSession_StateChangedCallback, which is used to receive the audio session state change event.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **callback** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system error occurs, such as an abnormal exit of a system service.|

### OH_AudioSessionManager_SetDefaultOutputDevice()

```
OH_AudioCommon_Result OH_AudioSessionManager_SetDefaultOutputDevice(OH_AudioSessionManager *audioSessionManager, OH_AudioDevice_Type deviceType)
```

**Description**

Sets the default audio output device.
> This function applies to the following scenarios:
>
> - When [OH_AudioSession_Scene](#oh_audiosession_scene) is set to **VoIP**, the setting takes effect immediately after the AudioSession is activated. For non-VoIP scenarios, the setting does not take effect upon AudioSession activation. Instead, the setting applies when [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage) for playback is voice message, VoIP voice call, or VoIP video call. Supported devices include the earpiece, speaker, and system default device.
> - This function can be called at any time after an [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) instance is created. The system records the device set by the application. However, the setting takes effect only after the AudioSession is activated. When the application is started, if an external device such as a Bluetooth or wired headset is connected, the system preferentially uses the external device to play sound. Otherwise, the system uses this default device to play sound.
> - This function has a lower priority than [AVCastPicker](../apis-avsession-kit/ohos-multimedia-avcastpicker.md#avcastpicker). If you have already switched the audio device using AVCastPicker, using this function to switch devices again does not take effect.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to an audio session manager instance, which is created by calling [OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioDevice_Type](capi-native-audio-device-base-h.md#oh_audiodevice_type) deviceType | Device type. For details about the available options, see [OH_AudioDevice_Type](capi-native-audio-device-base-h.md#oh_audiodevice_type). The device types that can be set are as follows:<br>                                          **AUDIO_DEVICE_TYPE_EARPIECE**: earpiece.<br>                                          **AUDIO_DEVICE_TYPE_SPEAKER**: speaker.<br>                                          **AUDIO_DEVICE_TYPE_DEFAULT**: system default device.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The deviceType parameter is out of the OH_AudioDevice_Type range.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system error occurs, such as an abnormal exit of a system service.|

### OH_AudioSessionManager_GetDefaultOutputDevice()

```
OH_AudioCommon_Result OH_AudioSessionManager_GetDefaultOutputDevice(OH_AudioSessionManager *audioSessionManager, OH_AudioDevice_Type *deviceType)
```

**Description**

Obtains the default audio output device set by [OH_AudioSessionManager_SetDefaultOutputDevice](#oh_audiosessionmanager_setdefaultoutputdevice).

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to an audio session manager instance, which is created by calling [OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioDevice_Type](capi-native-audio-device-base-h.md#oh_audiodevice_type) *deviceType | Pointer to the device type. For details about the available options, see [OH_AudioDevice_Type](capi-native-audio-device-base-h.md#oh_audiodevice_type). The returned device types are as follows:<br>                                          **AUDIO_DEVICE_TYPE_EARPIECE**: earpiece.<br>                                          **AUDIO_DEVICE_TYPE_SPEAKER**: speaker.<br>                                          **AUDIO_DEVICE_TYPE_DEFAULT**: system default device.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **deviceType** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE**: The default device type cannot be obtained in the current system state, for example, when the audio session is not ready.|

### OH_AudioSessionManager_ReleaseDevices()

```
OH_AudioCommon_Result OH_AudioSessionManager_ReleaseDevices(OH_AudioSessionManager *audioSessionManager, OH_AudioDeviceDescriptorArray *audioDeviceDescriptorArray)
```

**Description**

Releases audio devices available for an audio routing manager.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to an audio session manager instance, which is created by calling [OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioDeviceDescriptorArray](capi-ohaudio-oh-audiodevicedescriptorarray.md) *audioDeviceDescriptorArray |  Pointer to the audio device descriptors in the array to be released.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **audioDeviceDescriptorArray** parameter is nullptr.|

### OH_AudioSessionManager_RegisterCurrentOutputDeviceChangeCallback()

```
OH_AudioCommon_Result OH_AudioSessionManager_RegisterCurrentOutputDeviceChangeCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_CurrentOutputDeviceChangedCallback callback)
```

**Description**

Registers a callback to listen for the current output device change events.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to an audio session manager instance, which is created by calling [OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioSession_CurrentOutputDeviceChangedCallback](#oh_audiosession_currentoutputdevicechangedcallback) callback | Pointer to OH_AudioSession_CurrentOutputDeviceChangedCallback, which is used to return the audio device change information.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **callback** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_NO_MEMORY**: Memory allocation fails.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system error occurs, such as an abnormal exit of a system service.|

### OH_AudioSessionManager_UnregisterCurrentOutputDeviceChangeCallback()

```
OH_AudioCommon_Result OH_AudioSessionManager_UnregisterCurrentOutputDeviceChangeCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_CurrentOutputDeviceChangedCallback callback)
```

**Description**

Unregisters the callback used to listen for the current output device change events.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to an audio session manager instance, which is created by calling [OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioSession_CurrentOutputDeviceChangedCallback](#oh_audiosession_currentoutputdevicechangedcallback) callback | Pointer to OH_AudioSession_CurrentOutputDeviceChangedCallback, which is used to return the audio device change information.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **callback** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system error occurs, such as an abnormal exit of a system service.|
