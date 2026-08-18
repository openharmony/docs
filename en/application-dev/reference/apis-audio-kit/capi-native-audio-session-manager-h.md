# native_audio_session_manager.h

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @funny_sunix-->
<!--Designer: @hao-liangfei-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=29c534c06e8886c79e4893a68977c0d74e48120b translatedAt=2026-08-10T01:23:52.167Z pushedAt=2026-08-10T03:30:15.512Z -->

## Overview

The file declares the functions related to an audio session manager.<br> You can call the functions to create an audio session manager, activate or deactivate an audio session, check whether an audio session is activated, and listen for audio session deactivation events.

**File to include**: <ohaudio/native_audio_session_manager.h>

**Library**: libohaudio.so

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

**Related module**: [OHAudio](capi-ohaudio.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioSession_DeactivatedEvent](capi-ohaudio-oh-audiosession-deactivatedevent.md) | OH_AudioSession_DeactivatedEvent | Describes the event indicating that an audio session is deactivated.|
| [OH_AudioSession_StateChangedEvent](capi-ohaudio-oh-audiosession-statechangedevent.md) | OH_AudioSession_StateChangedEvent | Describes the event indicating that the audio session state changes.|
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) | OH_AudioSessionManager | Describes an audio session manager, which is used to manage audio sessions.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioSession_Scene](#oh_audiosession_scene) | OH_AudioSession_Scene | Enumerates the audio session scenes.|
| [OH_AudioSession_StateChangeHint](#oh_audiosession_statechangehint) | OH_AudioSession_StateChangeHint | Enumerates the hints for audio session state changes.|
| [OH_AudioSession_OutputDeviceChangeRecommendedAction](#oh_audiosession_outputdevicechangerecommendedaction) | OH_AudioSession_OutputDeviceChangeRecommendedAction | Enumerates the recommended actions to take after an output device changes.|
| [OH_AudioSession_DeactivatedReason](#oh_audiosession_deactivatedreason) | OH_AudioSession_DeactivatedReason | Enumerates the reasons for deactivating an audio session.|
| [OH_AudioSession_BluetoothAndNearlinkPreferredRecordCategory](#oh_audiosession_bluetoothandnearlinkpreferredrecordcategory) | OH_AudioSession_BluetoothAndNearlinkPreferredRecordCategory | Enumerates the preferred device categories available for recording with Bluetooth or NearLink.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_AudioSession_StateChangedCallback)(OH_AudioSession_StateChangedEvent event)](#oh_audiosession_statechangedcallback) | OH_AudioSession_StateChangedCallback | Defines a function pointer to the callback used to listen for audio session state change events.|
| [typedef void (\*OH_AudioSession_AvailableDeviceChangedCallback)(OH_AudioDevice_ChangeType type, OH_AudioDeviceDescriptorArray *audioDeviceDescriptorArray)](#oh_audiosession_availabledevicechangedcallback) | OH_AudioSession_AvailableDeviceChangedCallback | Defines a pointer to the callback that returns the changed audio device descriptor (possibly multiple descriptors).|
| [typedef void (\*OH_AudioSession_CurrentInputDeviceChangedCallback)(OH_AudioDeviceDescriptorArray *devices, OH_AudioStream_DeviceChangeReason changeReason)](#oh_audiosession_currentinputdevicechangedcallback) | OH_AudioSession_CurrentInputDeviceChangedCallback | Defines a function pointer to the callback used to listen for the current input device change events.|
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
| [OH_AudioCommon_Result OH_AudioSessionManager_GetDefaultOutputDevice(OH_AudioSessionManager *audioSessionManager, OH_AudioDevice_Type *deviceType)](#oh_audiosessionmanager_getdefaultoutputdevice) | - | Obtains the default audio output device set by [OH_AudioSessionManager_SetDefaultOutputDevice](capi-native-audio-session-manager-h.md#oh_audiosessionmanager_setdefaultoutputdevice).|
| [OH_AudioCommon_Result OH_AudioSessionManager_ReleaseDevices(OH_AudioSessionManager *audioSessionManager, OH_AudioDeviceDescriptorArray *audioDeviceDescriptorArray)](#oh_audiosessionmanager_releasedevices) | - | Releases audio devices available for an audio routing manager.|
| [OH_AudioCommon_Result OH_AudioSessionManager_RegisterCurrentOutputDeviceChangeCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_CurrentOutputDeviceChangedCallback callback)](#oh_audiosessionmanager_registercurrentoutputdevicechangecallback) | - | Registers a callback to listen for the current output device change events.|
| [OH_AudioCommon_Result OH_AudioSessionManager_UnregisterCurrentOutputDeviceChangeCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_CurrentOutputDeviceChangedCallback callback)](#oh_audiosessionmanager_unregistercurrentoutputdevicechangecallback) | - | Unregisters the callback used to listen for the current output device change events.|
| [OH_AudioCommon_Result OH_AudioSessionManager_GetAvailableDevices(OH_AudioSessionManager *audioSessionManager, OH_AudioDevice_Usage deviceUsage, OH_AudioDeviceDescriptorArray **audioDeviceDescriptorArray)](#oh_audiosessionmanager_getavailabledevices) | - | Obtains the available audio devices. |
| [OH_AudioCommon_Result OH_AudioSessionManager_RegisterAvailableDevicesChangeCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioDevice_Usage deviceUsage, OH_AudioSession_AvailableDeviceChangedCallback callback)](#oh_audiosessionmanager_registeravailabledeviceschangecallback) | - | Registers a callback to listen for available device change events.|
| [OH_AudioCommon_Result OH_AudioSessionManager_UnregisterAvailableDevicesChangeCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_AvailableDeviceChangedCallback callback)](#oh_audiosessionmanager_unregisteravailabledeviceschangecallback) | - | Unregisters the callback used to listen for available device change events.|
| [OH_AudioCommon_Result OH_AudioSessionManager_SelectMediaInputDevice(OH_AudioSessionManager *audioSessionManager, OH_AudioDeviceDescriptor *deviceDescriptor)](#oh_audiosessionmanager_selectmediainputdevice) | - | Selects a media input device. This function is not suitable for call recording, meaning it does not apply to situations where [SourceType](capi-native-audiostream-base-h.md#oh_audiostream_sourcetype) is **SOURCE_TYPE_VOICE_COMMUNICATION**.<br> When there is a concurrent recording stream with higher priority, the actual input device used by the application may differ from the one selected.<br> The application can use [OH_AudioSessionManager_RegisterCurrentInputDeviceChangeCallback](capi-native-audio-session-manager-h.md#oh_audiosessionmanager_registercurrentinputdevicechangecallback) to register a callback to listen for the actual input device.|
| [OH_AudioCommon_Result OH_AudioSessionManager_GetSelectedMediaInputDevice(OH_AudioSessionManager *audioSessionManager, OH_AudioDeviceDescriptor **audioDeviceDescriptor)](#oh_audiosessionmanager_getselectedmediainputdevice) | - | Obtains the media input device set by [OH_AudioSessionManager_SelectMediaInputDevice](capi-native-audio-session-manager-h.md#oh_audiosessionmanager_selectmediainputdevice).|
| [OH_AudioCommon_Result OH_AudioSessionManager_SetBluetoothAndNearlinkPreferredRecordCategory(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_BluetoothAndNearlinkPreferredRecordCategory category)](#oh_audiosessionmanager_setbluetoothandnearlinkpreferredrecordcategory) | - | Sets the preferred device category for recording with Bluetooth or NearLink. Applications can set this category before connecting to Bluetooth or NearLink devices, and the system prioritizes using the device for recording when the device is connected.<br> When there is a concurrent recording stream with higher priority, the actual input device used by the application may differ from the set preferred device.<br> The application can use [OH_AudioSessionManager_RegisterCurrentInputDeviceChangeCallback](capi-native-audio-session-manager-h.md#oh_audiosessionmanager_registercurrentinputdevicechangecallback) to register a callback to listen for the actual input device.|
| [OH_AudioCommon_Result OH_AudioSessionManager_GetBluetoothAndNearlinkPreferredRecordCategory(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_BluetoothAndNearlinkPreferredRecordCategory *category)](#oh_audiosessionmanager_getbluetoothandnearlinkpreferredrecordcategory) | - | Obtains the preferred device category for recording with Bluetooth or NearLink.|
| [OH_AudioCommon_Result OH_AudioSessionManager_RegisterCurrentInputDeviceChangeCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_CurrentInputDeviceChangedCallback callback)](#oh_audiosessionmanager_registercurrentinputdevicechangecallback) | - | Registers a callback to listen for input device changes of an audio session manager.|
| [OH_AudioCommon_Result OH_AudioSessionManager_UnregisterCurrentInputDeviceChangeCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_CurrentInputDeviceChangedCallback callback)](#oh_audiosessionmanager_unregistercurrentinputdevicechangecallback) | - | Unregisters the callback used to listen for input device changes of an audio session manager.|
| [OH_AudioCommon_Result OH_AudioSessionManager_ReleaseDevice(OH_AudioSessionManager *audioSessionManager, OH_AudioDeviceDescriptor *audioDeviceDescriptor)](#oh_audiosessionmanager_releasedevice) | - | Releases an audio device for an audio session manager.|
| [OH_AudioCommon_Result OH_AudioSessionManager_EnableMuteSuggestionWhenMixWithOthers(OH_AudioSessionManager *audioSessionManager, bool enable)](#oh_audiosessionmanager_enablemutesuggestionwhenmixwithothers) | - | Enables the function of receiving mute playback suggestion notifications during mixed playback.|
| [OH_AudioCommon_Result OH_AudioSessionManager_SetCaptureMuteHint(OH_AudioSessionManager *audioSessionManager, bool mute)](#oh_audiosessionmanager_setcapturemutehint) | - | Reports the mute state of recording streams in the current audio session to the system audio module. This API is used to report the mute state of recording streams in the current audio session to the system audio module, without changing the actual mute state of the recording streams. Currently, only on some PC/2-in-1 devices, the system audio module adjusts policies based on the set state to reduce power consumption. This API can only be called when there is an active recording stream in the current audio session; otherwise, it returns error code AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE. If a recording stream calls both the stream-level API and this API, the stream-level API setting takes higher priority, and the stream-level API setting value prevails. |
| [bool OH_AudioSessionManager_IsOtherMediaPlaying(OH_AudioSessionManager *audioSessionManager)](#oh_audiosessionmanager_isothermediaplaying) | - | Checks whether audio of the MUSIC, MOVIE, AUDIOBOOK, and GAME media types is being played by other applications. Activated audio sessions of the media types are also checked.|
| [OH_AudioCommon_Result OH_AudioSessionManager_SetBehavior(OH_AudioSessionManager *audioSessionManager, uint32_t behavior)](#oh_audiosessionmanager_setbehavior) | - | Sets audio session behavior parameters. (Multiple flags can be combined.) If this API is called while an audio session is active, you must call the [OH_AudioSessionManager_ActivateAudioSession](capi-native-audio-session-manager-h.md#oh_audiosessionmanager_activateaudiosession) API again for the settings to take effect.|

## Enum Description

### OH_AudioSession_Scene

```c
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

```c
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
| AUDIO_SESSION_STATE_CHANGE_HINT_DUCK = 4 | A hint is displayed, indicating that audio ducking starts and the audio is played at a lower volume. If [OH_AudioSessionManager_EnableMuteSuggestionWhenMixWithOthers](capi-native-audio-session-manager-h.md#oh_audiosessionmanager_enablemutesuggestionwhenmixwithothers) is enabled, you can choose to mute the audio.|
| AUDIO_SESSION_STATE_CHANGE_HINT_UNDUCK = 5 | A hint is displayed, indicating that audio ducking ends and the audio is played at the normal volume. If [OH_AudioSessionManager_EnableMuteSuggestionWhenMixWithOthers](capi-native-audio-session-manager-h.md#oh_audiosessionmanager_enablemutesuggestionwhenmixwithothers) is enabled, you can unmute the audio.|
| AUDIO_SESSION_STATE_CHANGE_HINT_MUTE_SUGGESTION = 6 | Mute suggestion. When another application starts playing non-mixable audio, the application can determine whether to mute the audio.<br>**Since**: 23|
| AUDIO_SESSION_STATE_CHANGE_HINT_UNMUTE_SUGGESTION = 7 | Unmute suggestion. When the non-mixable audio of another application has finished playing, the application can decide whether to unmute the audio.<br>**Since**: 23|
| AUDIO_SESSION_STATE_CHANGE_HINT_MUTE = 8 | A hint is displayed, indicating that the audio session is muted. This hint is received only when the following conditions are met: The [OH_AudioSessionManager_SetBehavior](capi-native-audio-session-manager-h.md#oh_audiosessionmanager_setbehavior) API is called to set [OH_AudioSession_BehaviorFlags](capi-native-audio-session-base-h.md#oh_audiosession_behaviorflags).MUTE_WHEN_INTERRUPTED, the [OH_AudioSessionManager_SetScene](capi-native-audio-session-manager-h.md#oh_audiosessionmanager_setscene) API is called, and the audio session is activated.<br>**Since**: 24|
| AUDIO_SESSION_STATE_CHANGE_HINT_UNMUTE = 9 | A hint is displayed, indicating that the audio session is unmuted. This hint is received only when the following conditions are met: The [OH_AudioSessionManager_SetBehavior](capi-native-audio-session-manager-h.md#oh_audiosessionmanager_setbehavior) API is called to set [OH_AudioSession_BehaviorFlags](capi-native-audio-session-base-h.md#oh_audiosession_behaviorflags).MUTE_WHEN_INTERRUPTED, the [OH_AudioSessionManager_SetScene](capi-native-audio-session-manager-h.md#oh_audiosessionmanager_setscene) API is called, and the audio session is activated.<br>**Since**: 24|

### OH_AudioSession_OutputDeviceChangeRecommendedAction

```c
enum OH_AudioSession_OutputDeviceChangeRecommendedAction
```

**Description**

Enumerates the recommended actions to take after an output device changes.

Common scenario example: switching between a headset and a loudspeaker device. Upon switching from the loudspeaker device to the headset upon wearing, the system suggests continuing playback and prompts that the application does not need to pause. Upon transitioning from the headset to the loudspeaker device upon removal, the system suggests suspending playback.

**Since**: 20

| Enum Item| Description|
| -- | -- |
| DEVICE_CHANGE_RECOMMEND_TO_CONTINUE = 0 | Suggests continuing playback. (This event serves as a playback maintenance indication, informing the app that audio playback does not need to stop during this device change. However, it must not be used as a criterion for triggering audio playback.) |
| DEVICE_CHANGE_RECOMMEND_TO_STOP = 1 | Suggests stopping playback.|

### OH_AudioSession_DeactivatedReason

```c
enum OH_AudioSession_DeactivatedReason
```

**Description**

Enumerates the reasons for deactivating an audio session.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| DEACTIVATED_LOWER_PRIORITY = 0 | The application focus is preempted.|
| DEACTIVATED_TIMEOUT = 1 | The application times out after the stream is stopped.|

### OH_AudioSession_BluetoothAndNearlinkPreferredRecordCategory

```c
enum OH_AudioSession_BluetoothAndNearlinkPreferredRecordCategory
```

**Description**

Enumerates the preferred device categories available for recording with Bluetooth or NearLink.

**Since**: 21

| Enum Item| Description|
| -- | -- |
| PREFERRED_NONE = 0 | No specific device preference.|
| PREFERRED_DEFAULT = 1 | Prefers using Bluetooth or Nearlink devices for recording; whether to use low-latency or high-quality recording depends on the system.|
| PREFERRED_LOW_LATENCY = 2 | Prefers using Bluetooth or NearLink devices in low-latency mode for recording.|
| PREFERRED_HIGH_QUALITY = 3 | Prefers using Bluetooth or NearLink devices in high-quality mode for recording.|

## Function Description

### OH_AudioSession_StateChangedCallback()

```c
typedef void (*OH_AudioSession_StateChangedCallback)(OH_AudioSession_StateChangedEvent event)
```

**Description**

Points to the callback function used to listen for audio session state change events.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSession_StateChangedEvent](capi-ohaudio-oh-audiosession-statechangedevent.md) event | Event indicating that the audio session state changes.|

### OH_AudioSession_AvailableDeviceChangedCallback()

```c
typedef void (*OH_AudioSession_AvailableDeviceChangedCallback)(OH_AudioDevice_ChangeType type, OH_AudioDeviceDescriptorArray *audioDeviceDescriptorArray)
```

**Description**

Defines a pointer to the callback that returns the changed audio device descriptor (possibly multiple descriptors).

**Since**: 21

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioDevice_ChangeType](capi-native-audio-device-base-h.md#oh_audiodevice_changetype) type | Device connection status, which can be connected or disconnected.|
| [OH_AudioDeviceDescriptorArray](capi-ohaudio-oh-audiodevicedescriptorarray.md) *audioDeviceDescriptorArray | Pointer to the audio device descriptors in the array.<br> If the pointer is no longer needed, use [OH_AudioSessionManager_ReleaseDevices](#oh_audiosessionmanager_releasedevices) to release it.|

### OH_AudioSession_CurrentInputDeviceChangedCallback()

```c
typedef void (*OH_AudioSession_CurrentInputDeviceChangedCallback)(OH_AudioDeviceDescriptorArray *devices, OH_AudioStream_DeviceChangeReason changeReason)
```

**Description**

Defines a function pointer to the callback used to listen for the current input device change events.

**Since**: 21

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioDeviceDescriptorArray](capi-ohaudio-oh-audiodevicedescriptorarray.md) *devices | Pointer to the audio device descriptors in the array.<br> Use [OH_AudioSessionManager_ReleaseDevices](capi-native-audio-session-manager-h.md#oh_audiosessionmanager_releasedevices) to release the devices pointer if it is no longer needed.|
| [OH_AudioStream_DeviceChangeReason](capi-native-audiostream-base-h.md#oh_audiostream_devicechangereason) changeReason | Reason for the device change.|

### OH_AudioSession_CurrentOutputDeviceChangedCallback()

```c
typedef void (*OH_AudioSession_CurrentOutputDeviceChangedCallback)(OH_AudioDeviceDescriptorArray *devices, OH_AudioStream_DeviceChangeReason changeReason, OH_AudioSession_OutputDeviceChangeRecommendedAction recommendedAction)
```

**Description**

Defines a function pointer to the callback used to listen for the current output device change events.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioDeviceDescriptorArray](capi-ohaudio-oh-audiodevicedescriptorarray.md) *devices | Audio device descriptor array, which points to **OH_AudioDeviceDescriptorArray** used to set the pointer variable of the audio device descriptor array. Do not release the **audioDeviceDescriptorArray** pointer separately. Instead, call [OH_AudioSessionManager_ReleaseDevices](capi-native-audio-session-manager-h.md#oh_audiosessionmanager_releasedevices) to release the DeviceDescriptor array.|
| [OH_AudioStream_DeviceChangeReason](capi-native-audiostream-base-h.md#oh_audiostream_devicechangereason) changeReason | Pointer to [OH_AudioStream_DeviceChangeReason](capi-native-audiostream-base-h.md#oh_audiostream_devicechangereason), which is used to receive the device change reason.|
| [OH_AudioSession_OutputDeviceChangeRecommendedAction](capi-native-audio-session-manager-h.md#oh_audiosession_outputdevicechangerecommendedaction) recommendedAction | Pointer to [OH_AudioSession_OutputDeviceChangeRecommendedAction](capi-native-audio-session-manager-h.md#oh_audiosession_outputdevicechangerecommendedaction), which is used to receive the recommended operation after the device change.|

### OH_AudioSession_DeactivatedCallback()

```c
typedef int32_t (*OH_AudioSession_DeactivatedCallback)(OH_AudioSession_DeactivatedEvent event)
```

**Description**

Defines a function pointer to the callback used to listen for audio session deactivation events.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSession_DeactivatedEvent](capi-ohaudio-oh-audiosession-deactivatedevent.md) event | Event indicating that an audio session is deactivated.|

### OH_AudioManager_GetAudioSessionManager()

```c
OH_AudioCommon_Result OH_AudioManager_GetAudioSessionManager(OH_AudioSessionManager **audioSessionManager)
```

**Description**

Obtains an OH_AudioSessionManager instance. Before using the features related to the audio session manager, you must obtain an OH_AudioSessionManager instance.

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

```c
OH_AudioCommon_Result OH_AudioSessionManager_ActivateAudioSession(OH_AudioSessionManager *audioSessionManager, const OH_AudioSession_Strategy *strategy)
```

**Description**

Activates an audio session.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|
| [const OH_AudioSession_Strategy](capi-ohaudio-oh-audiosession-strategy.md) *strategy | Pointer to an audio session strategy, which is an [OH_AudioSession_Strategy](capi-ohaudio-oh-audiosession-strategy.md) struct.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | One of the following return values:<br>         **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **strategy** parameter is invalid.<br>         **AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE**: Invalid state.|

### OH_AudioSessionManager_DeactivateAudioSession()

```c
OH_AudioCommon_Result OH_AudioSessionManager_DeactivateAudioSession(OH_AudioSessionManager *audioSessionManager)
```

**Description**

Deactivates an audio session.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **audioSessionManager** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE**: Invalid state.|

### OH_AudioSessionManager_IsAudioSessionActivated()

```c
bool OH_AudioSessionManager_IsAudioSessionActivated(OH_AudioSessionManager *audioSessionManager)
```

**Description**

Checks whether an audio session is activated.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|

**Returns**

| Type| Description|
| -- | -- |
| bool | Check result for whether the audio session is activated. **true** if activated, **false** otherwise.|

### OH_AudioSessionManager_RegisterSessionDeactivatedCallback()

```c
OH_AudioCommon_Result OH_AudioSessionManager_RegisterSessionDeactivatedCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_DeactivatedCallback callback)
```

**Description**

Registers a callback to listen for audio session deactivation events.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioSession_DeactivatedCallback](capi-native-audio-session-manager-h.md#oh_audiosession_deactivatedcallback) callback | Callback used to receive the audio session deactivation event.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **callback** parameter is nullptr.|

### OH_AudioSessionManager_UnregisterSessionDeactivatedCallback()

```c
OH_AudioCommon_Result OH_AudioSessionManager_UnregisterSessionDeactivatedCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_DeactivatedCallback callback)
```

**Description**

Unregisters the callback used to listen for audio session deactivation events.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioSession_DeactivatedCallback](capi-native-audio-session-manager-h.md#oh_audiosession_deactivatedcallback) callback | Callback used to receive the audio session deactivation event.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **callback** parameter is nullptr.|

### OH_AudioSessionManager_SetScene()

```c
OH_AudioCommon_Result OH_AudioSessionManager_SetScene(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_Scene scene)
```

**Description**

Sets an audio session scene.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioSession_Scene](capi-native-audio-session-manager-h.md#oh_audiosession_scene) scene | Pointer to the audio session scene to be set by [OH_AudioSession_Scene](capi-native-audio-session-manager-h.md#oh_audiosession_scene).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **scene** parameter is set to a value outside the valid enumeration range.<br>         **AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE**: The setting is not allowed in the current system state, for example, when the audio session is not ready.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system error occurs, such as an abnormal exit of a system service.|

### OH_AudioSessionManager_RegisterStateChangeCallback()

```c
OH_AudioCommon_Result OH_AudioSessionManager_RegisterStateChangeCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_StateChangedCallback callback)
```

**Description**

Registers a callback to listen for audio session state change events.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioSession_StateChangedCallback](capi-native-audio-session-manager-h.md#oh_audiosession_statechangedcallback) callback | Callback used to receive the audio session state change event.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **callback** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_NO_MEMORY**: Memory allocation fails.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system error occurs, such as an abnormal exit of a system service.|

### OH_AudioSessionManager_UnregisterStateChangeCallback()

```c
OH_AudioCommon_Result OH_AudioSessionManager_UnregisterStateChangeCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_StateChangedCallback callback)
```

**Description**

Unregisters the callback used to listen for audio session state change events.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioSession_StateChangedCallback](capi-native-audio-session-manager-h.md#oh_audiosession_statechangedcallback) callback | Callback used to receive the audio session state change event.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **callback** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system error occurs, such as an abnormal exit of a system service.|

### OH_AudioSessionManager_SetDefaultOutputDevice()

```c
OH_AudioCommon_Result OH_AudioSessionManager_SetDefaultOutputDevice(OH_AudioSessionManager *audioSessionManager, OH_AudioDevice_Type deviceType)
```

**Description**

Sets the default audio output device.

 >**NOTE** 
 > - This API is applicable to the following scenarios: If [OH_AudioSession_Scene](capi-native-audio-session-manager-h.md#oh_audiosession_scene) is set to VoIP, this API takes effect immediately after the audio session is activated. If [OH_AudioSession_Scene](capi-native-audio-session-manager-h.md#oh_audiosession_scene) is set to non-VoIP, this API does not take effect when the audio session is activated. It takes effect only when [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage) of the started playback is a voice message, VoIP voice call, or VoIP video call. Supported devices include the earpiece, speaker, and system default device.
 > - This API can be called at any time after an [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) instance is created. The system records the device set by the application. However, the setting takes effect only after the AudioSession is activated. When the application starts playback, if an external device such as a Bluetooth or wired headset is connected, the system preferentially uses the external device to play sound. Otherwise, the system uses this default device to play sound.

 **Device behavior difference**: If the default audio output device is set to earpiece on a device without an earpiece, the speaker will still be used for audio output.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioDevice_Type](capi-native-audio-device-base-h.md#oh_audiodevice_type) deviceType | Device type. For details about the available options, see [OH_AudioDevice_Type](capi-native-audio-device-base-h.md#oh_audiodevice_type). The device types that can be set are as follows:<br>                                          **AUDIO_DEVICE_TYPE_EARPIECE**: earpiece.<br>                                          **AUDIO_DEVICE_TYPE_SPEAKER**: speaker.<br>                                          **AUDIO_DEVICE_TYPE_DEFAULT**: system default device.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The deviceType parameter is out of the OH_AudioDevice_Type range.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system error occurs, such as an abnormal exit of a system service.|

### OH_AudioSessionManager_GetDefaultOutputDevice()

```c
OH_AudioCommon_Result OH_AudioSessionManager_GetDefaultOutputDevice(OH_AudioSessionManager *audioSessionManager, OH_AudioDevice_Type *deviceType)
```

**Description**

Obtains the default audio output device set by [OH_AudioSessionManager_SetDefaultOutputDevice](capi-native-audio-session-manager-h.md#oh_audiosessionmanager_setdefaultoutputdevice).

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioDevice_Type](capi-native-audio-device-base-h.md#oh_audiodevice_type) *deviceType | Pointer to the device type. For details about the available options, see [OH_AudioDevice_Type](capi-native-audio-device-base-h.md#oh_audiodevice_type). The returned device types are as follows:<br>                                          **AUDIO_DEVICE_TYPE_EARPIECE**: earpiece.<br>                                          **AUDIO_DEVICE_TYPE_SPEAKER**: speaker.<br>                                          **AUDIO_DEVICE_TYPE_DEFAULT**: system default device.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **deviceType** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE**: The default device type cannot be obtained in the current system state, for example, when the audio session is not ready.|

### OH_AudioSessionManager_ReleaseDevices()

```c
OH_AudioCommon_Result OH_AudioSessionManager_ReleaseDevices(OH_AudioSessionManager *audioSessionManager, OH_AudioDeviceDescriptorArray *audioDeviceDescriptorArray)
```

**Description**

Releases audio devices available for an audio routing manager.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioDeviceDescriptorArray](capi-ohaudio-oh-audiodevicedescriptorarray.md) *audioDeviceDescriptorArray |  Pointer to the audio device descriptors in the array to be released.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **audioDeviceDescriptorArray** parameter is nullptr.|

### OH_AudioSessionManager_RegisterCurrentOutputDeviceChangeCallback()

```c
OH_AudioCommon_Result OH_AudioSessionManager_RegisterCurrentOutputDeviceChangeCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_CurrentOutputDeviceChangedCallback callback)
```

**Description**

Registers a callback to listen for the current output device change events.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioSession_CurrentOutputDeviceChangedCallback](capi-native-audio-session-manager-h.md#oh_audiosession_currentoutputdevicechangedcallback) callback | Callback used to return the audio device change information.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **callback** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_NO_MEMORY**: Memory allocation fails.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system error occurs, such as an abnormal exit of a system service.|

### OH_AudioSessionManager_UnregisterCurrentOutputDeviceChangeCallback()

```c
OH_AudioCommon_Result OH_AudioSessionManager_UnregisterCurrentOutputDeviceChangeCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_CurrentOutputDeviceChangedCallback callback)
```

**Description**

Unregisters the callback used to listen for the current output device change events.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioSession_CurrentOutputDeviceChangedCallback](capi-native-audio-session-manager-h.md#oh_audiosession_currentoutputdevicechangedcallback) callback | Callback used to return the audio device change information.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **callback** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system error occurs, such as an abnormal exit of a system service.|

### OH_AudioSessionManager_GetAvailableDevices()

```c
OH_AudioCommon_Result OH_AudioSessionManager_GetAvailableDevices(OH_AudioSessionManager *audioSessionManager, OH_AudioDevice_Usage deviceUsage, OH_AudioDeviceDescriptorArray **audioDeviceDescriptorArray)
```

**Description**

Obtains the available audio devices.

**Since**: 21

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioDevice_Usage](capi-native-audio-device-base-h.md#oh_audiodevice_usage) deviceUsage | Type of audio device.|
| [OH_AudioDeviceDescriptorArray](capi-ohaudio-oh-audiodevicedescriptorarray.md) **audioDeviceDescriptorArray | Pointer to the audio device descriptors in the array.<br> Use [OH_AudioSessionManager_ReleaseDevices](capi-native-audio-session-manager-h.md#oh_audiosessionmanager_releasedevices) to release the audioDeviceDescriptorArray pointer if the pointer is no longer needed.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **deviceUsage** parameter is invalid.<br>                                                        3. The **audioDeviceDescriptorArray** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system error occurs, such as an abnormal exit of a system service.|

### OH_AudioSessionManager_RegisterAvailableDevicesChangeCallback()

```c
OH_AudioCommon_Result OH_AudioSessionManager_RegisterAvailableDevicesChangeCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioDevice_Usage deviceUsage, OH_AudioSession_AvailableDeviceChangedCallback callback)
```

**Description**

Registers a callback to listen for available device change events.

**Since**: 21

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioDevice_Usage](capi-native-audio-device-base-h.md#oh_audiodevice_usage) deviceUsage | Type of audio device.|
| [OH_AudioSession_AvailableDeviceChangedCallback](capi-native-audio-session-manager-h.md#oh_audiosession_availabledevicechangedcallback) callback | Callback used to return the available audio device change information.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **deviceUsage** parameter is set to an invalid value.<br>                                                        3. The **callback** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system error occurs, such as an abnormal exit of a system service.|

### OH_AudioSessionManager_UnregisterAvailableDevicesChangeCallback()

```c
OH_AudioCommon_Result OH_AudioSessionManager_UnregisterAvailableDevicesChangeCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_AvailableDeviceChangedCallback callback)
```

**Description**

Unregisters the callback used to listen for available device change events.

**Since**: 21

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioSession_AvailableDeviceChangedCallback](capi-native-audio-session-manager-h.md#oh_audiosession_availabledevicechangedcallback) callback | Callback used to return the available audio device change information.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **callback** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system error occurs, such as an abnormal exit of a system service.|

### OH_AudioSessionManager_SelectMediaInputDevice()

```c
OH_AudioCommon_Result OH_AudioSessionManager_SelectMediaInputDevice(OH_AudioSessionManager *audioSessionManager, OH_AudioDeviceDescriptor *deviceDescriptor)
```

**Description**

Selects a media input device. This function is not suitable for call recording, meaning it does not apply to situations where [SourceType](capi-native-audiostream-base-h.md#oh_audiostream_sourcetype) is **SOURCE_TYPE_VOICE_COMMUNICATION**.<br> When there is a concurrent recording stream with higher priority, the actual input device used by the application may differ from the one selected.<br> The application can use [OH_AudioSessionManager_RegisterCurrentInputDeviceChangeCallback](capi-native-audio-session-manager-h.md#oh_audiosessionmanager_registercurrentinputdevicechangecallback) to register a callback to listen for the actual input device.

**Since**: 21

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioDeviceDescriptor](capi-ohaudio-oh-audiodevicedescriptor.md) *deviceDescriptor | Pointer to the target device, The available device must be in the array returned by [OH_AudioSessionManager_GetAvailableDevices](capi-native-audio-session-manager-h.md#oh_audiosessionmanager_getavailabledevices).<br> If nullptr is passed, the system clears the previous setting.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **audioSessionManager** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system error occurs, such as an abnormal exit of a system service.|

### OH_AudioSessionManager_GetSelectedMediaInputDevice()

```c
OH_AudioCommon_Result OH_AudioSessionManager_GetSelectedMediaInputDevice(OH_AudioSessionManager *audioSessionManager, OH_AudioDeviceDescriptor **audioDeviceDescriptor)
```

**Description**

Obtains the media input device set by [OH_AudioSessionManager_SelectMediaInputDevice](capi-native-audio-session-manager-h.md#oh_audiosessionmanager_selectmediainputdevice).

**Since**: 21

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioDeviceDescriptor](capi-ohaudio-oh-audiodevicedescriptor.md) **audioDeviceDescriptor | Media device set by [OH_AudioSessionManager_SelectMediaInputDevice](capi-native-audio-session-manager-h.md#oh_audiosessionmanager_selectmediainputdevice). If no media device is set, a device of the AUDIO_DEVICE_TYPE_INVALID type is returned.<br> Use [OH_AudioSessionManager_ReleaseDevice](capi-native-audio-session-manager-h.md#oh_audiosessionmanager_releasedevice) to release the audioDeviceDescriptor pointer if the pointer is no longer needed.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **audioDeviceDescriptor** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system error occurs, such as an abnormal exit of a system service.|

### OH_AudioSessionManager_SetBluetoothAndNearlinkPreferredRecordCategory()

```c
OH_AudioCommon_Result OH_AudioSessionManager_SetBluetoothAndNearlinkPreferredRecordCategory(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_BluetoothAndNearlinkPreferredRecordCategory category)
```

**Description**

Sets the preferred device category for recording with Bluetooth or NearLink. Applications can set this category before connecting to Bluetooth or NearLink devices, and the system prioritizes using the device for recording when the device is connected.<br> When there is a concurrent recording stream with higher priority, the actual input device used by the application may differ from the set preferred device.<br> The application can use [OH_AudioSessionManager_RegisterCurrentInputDeviceChangeCallback](capi-native-audio-session-manager-h.md#oh_audiosessionmanager_registercurrentinputdevicechangecallback) to register a callback to listen for the actual input device.

**Since**: 21

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioSession_BluetoothAndNearlinkPreferredRecordCategory](capi-native-audio-session-manager-h.md#oh_audiosession_bluetoothandnearlinkpreferredrecordcategory) category | Preferred device category available for recording with Bluetooth or NearLink.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **category** parameter is incorrect.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system error occurs, such as an abnormal exit of a system service.|

### OH_AudioSessionManager_GetBluetoothAndNearlinkPreferredRecordCategory()

```c
OH_AudioCommon_Result OH_AudioSessionManager_GetBluetoothAndNearlinkPreferredRecordCategory(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_BluetoothAndNearlinkPreferredRecordCategory *category)
```

**Description**

Obtains the preferred device category for recording with Bluetooth or NearLink.

**Since**: 21

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioSession_BluetoothAndNearlinkPreferredRecordCategory](capi-native-audio-session-manager-h.md#oh_audiosession_bluetoothandnearlinkpreferredrecordcategory) *category | Preferred device category available for recording with Bluetooth or NearLink.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **category** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system error occurs, such as an abnormal exit of a system service.|

### OH_AudioSessionManager_RegisterCurrentInputDeviceChangeCallback()

```c
OH_AudioCommon_Result OH_AudioSessionManager_RegisterCurrentInputDeviceChangeCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_CurrentInputDeviceChangedCallback callback)
```

**Description**

Registers a callback to listen for input device changes of an audio session manager.

**Since**: 21

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioSession_CurrentInputDeviceChangedCallback](capi-native-audio-session-manager-h.md#oh_audiosession_currentinputdevicechangedcallback) callback | Callback used to return the input audio device change information.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **callback** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_NO_MEMORY**: The memory is insufficient.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system error occurs, such as an abnormal exit of a system service.|

### OH_AudioSessionManager_UnregisterCurrentInputDeviceChangeCallback()

```c
OH_AudioCommon_Result OH_AudioSessionManager_UnregisterCurrentInputDeviceChangeCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_CurrentInputDeviceChangedCallback callback)
```

**Description**

Unregisters the callback used to listen for input device changes of an audio session manager.

**Since**: 21

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioSession_CurrentInputDeviceChangedCallback](capi-native-audio-session-manager-h.md#oh_audiosession_currentinputdevicechangedcallback) callback | Callback used to return the input audio device change information.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **callback** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system error occurs, such as an abnormal exit of a system service.|

### OH_AudioSessionManager_ReleaseDevice()

```c
OH_AudioCommon_Result OH_AudioSessionManager_ReleaseDevice(OH_AudioSessionManager *audioSessionManager, OH_AudioDeviceDescriptor *audioDeviceDescriptor)
```

**Description**

Releases an audio device for an audio session manager.

**Since**: 21

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|
| [OH_AudioDeviceDescriptor](capi-ohaudio-oh-audiodevicedescriptor.md) *audioDeviceDescriptor | Pointer to the audio device descriptor to be released.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioSessionManager** parameter is nullptr.<br>                                                        2. The **audioDeviceDescriptor** parameter is nullptr.|

### OH_AudioSessionManager_EnableMuteSuggestionWhenMixWithOthers()

```c
OH_AudioCommon_Result OH_AudioSessionManager_EnableMuteSuggestionWhenMixWithOthers(OH_AudioSessionManager *audioSessionManager, bool enable)
```

**Description**

Enables the function of receiving mute playback suggestion notifications during mix playback. Generally, when the mixed mode is used, if audio from other apps plays simultaneously, the two will be mixed for playback. In certain scenarios (such as games or broadcasting), an app can provide a better user experience by enabling mute suggestion notifications. If this function is enabled, after subscribing to audio session state change events, mute suggestions and unmute suggestions will be sent through the [OH_AudioSession_StateChangedCallback](capi-native-audio-session-manager-h.md#oh_audiosession_statechangedcallback) callback, which is registered by [OH_AudioSessionManager_RegisterStateChangeCallback](capi-native-audio-session-manager-h.md#oh_audiosessionmanager_registerstatechangecallback).<br> Receiving a mute suggestion indicates that another app has started playing audio, and the audio being played cannot be mixed with the audio of this app. This function is only supported for audio sessions that have set [OH_AudioSession_Scene](capi-native-audio-session-manager-h.md#oh_audiosession_scene) and activated with the mode [OH_AudioSession_ConcurrencyMode](capi-native-audio-session-base-h.md#oh_audiosession_concurrencymode).CONCURRENCY_MIX_WITH_OTHERS.<br> This API takes effect only once during the activation of the audio session, and must be re-enabled before each activation of the audio session.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|
| bool enable | Whether to enable the mute suggestion callback function. **true** to enable, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **audioSessionManager** parameter is nullptr.<br>         AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE:<br>                                                 1. Audio session scene not set.<br>                                                 2. Call this function after the audio session is activated.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system error occurs, such as an abnormal exit of a system service.|

### OH_AudioSessionManager_SetCaptureMuteHint()

```c
OH_AudioCommon_Result OH_AudioSessionManager_SetCaptureMuteHint(OH_AudioSessionManager *audioSessionManager, bool mute)
```

**Description**

Passes the self-mute state of the recording streams within the current audio session from the app to the system audio module. This API is used to report the mute state of the recording streams within the current audio session to the system audio module, without changing the actual mute state of the recording streams. Currently, only on certain PC/2-in-1 devices, the system audio module adjusts policies based on the set state to reduce power consumption. This API can only be called when there is a running recording stream in the current audio session; otherwise, the error code AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE is returned. If a recording stream calls both the stream-level API and this API, the stream-level API setting takes higher priority, and the value set by the stream-level API prevails.

**Since**: 24

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance returned by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager). |
| bool mute | Whether the app has muted the recording stream. The value **true** indicates that the recording stream under the current app is marked as muted, and **false** indicates that it is unmuted. |

**Returns**

| Type | Description |
| -- | -- |
| OH_AudioCommon_Result | Result code.<br>         **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: **audioSessionManager** is **nullptr**.<br>         **AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE**: The operation status is abnormal. No running recording stream exists in the current process.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: System exception, such as unexpected exit of the system service. |

### OH_AudioSessionManager_IsOtherMediaPlaying()

```c
bool OH_AudioSessionManager_IsOtherMediaPlaying(OH_AudioSessionManager *audioSessionManager)
```

**Description**

Checks whether audio of the MUSIC, MOVIE, AUDIOBOOK, and GAME media types is being played by other applications. The activated audio sessions of the media types are also checked.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|

**Returns**

| Type| Description|
| -- | -- |
| bool | Whether another application is playing media audio. **true** means yes; **false** otherwise.|

### OH_AudioSessionManager_SetBehavior()

```c
OH_AudioCommon_Result OH_AudioSessionManager_SetBehavior(OH_AudioSessionManager *audioSessionManager, uint32_t behavior)
```

**Description**

Configures audio session behavior parameters. (Multiple flags can be combined.) If this API is called while an audio session is active, you must call the [OH_AudioSessionManager_ActivateAudioSession](capi-native-audio-session-manager-h.md#oh_audiosessionmanager_activateaudiosession) API again for the settings to take effect.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *audioSessionManager | Pointer to the audio session management instance created by [OH_AudioManager_GetAudioSessionManager](capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager).|
| uint32_t behavior | Audio session behavior flag. This can be a single flag or a bitwise OR combination of multiple flags. For details about the supported audio session behaviors, see [OH_AudioSession_BehaviorFlags](capi-native-audio-session-base-h.md#oh_audiosession_behaviorflags).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The parameter value is a null pointer or out of range.<br>         **AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE**: Invalid state.|