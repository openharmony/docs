# native_audio_session_manager.h

## Overview

The file declares the functions related to an audio session manager.

You can call the functions to create an audio session manager, activate or deactivate an audio session, check whether an audio session is activated, and listen for audio session deactivation events.

**Library**: libohaudio.so

**File to include**: <ohaudio/native_audio_session_manager.h>

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

**Related module**: [OHAudio](capi-ohaudio.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioSession_Strategy](capi-ohaudio-oh-audiosession-strategy.md) | OH_AudioSession_Strategy | Describes the audio session strategy.|
| [OH_AudioSession_DeactivatedEvent](capi-ohaudio-oh-audiosession-deactivatedevent.md) | OH_AudioSession_DeactivatedEvent | Describes the event indicating that an audio session is deactivated.|
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) | OH_AudioSessionManager | Describes an audio session manager, which is used to manage audio sessions. |

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioSession_ConcurrencyMode](#oh_audiosession_concurrencymode) | OH_AudioSession_ConcurrencyMode | Enumerates the audio concurrency modes.|
| [OH_AudioSession_DeactivatedReason](#oh_audiosession_deactivatedreason) | OH_AudioSession_DeactivatedReason | Enumerates the reasons for deactivating an audio session.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef int32_t (\*OH_AudioSession_DeactivatedCallback)(OH_AudioSession_DeactivatedEvent event)](#oh_audiosession_deactivatedcallback) | OH_AudioSession_DeactivatedCallback | Defines a function pointer to the callback used to listen for audio session deactivation events.|
| [OH_AudioCommon_Result OH_AudioManager_GetAudioSessionManager(OH_AudioSessionManager **audioSessionManager)](#oh_audiomanager_getaudiosessionmanager) | - | Obtains an OH_AudioSessionManager instance. Before using the features related to the audio session manager, you must obtain an OH_AudioSessionManager instance.|
| [OH_AudioCommon_Result OH_AudioSessionManager_ActivateAudioSession(OH_AudioSessionManager *audioSessionManager, const OH_AudioSession_Strategy *strategy)](#oh_audiosessionmanager_activateaudiosession) | - | Activates an audio session.|
| [OH_AudioCommon_Result OH_AudioSessionManager_DeactivateAudioSession(OH_AudioSessionManager *audioSessionManager)](#oh_audiosessionmanager_deactivateaudiosession) | - | Deactivates an audio session.|
| [bool OH_AudioSessionManager_IsAudioSessionActivated(OH_AudioSessionManager *audioSessionManager)](#oh_audiosessionmanager_isaudiosessionactivated) | - | Checks whether an audio session is activated.|
| [OH_AudioCommon_Result OH_AudioSessionManager_RegisterSessionDeactivatedCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_DeactivatedCallback callback)](#oh_audiosessionmanager_registersessiondeactivatedcallback) | - | Registers a callback to listen for audio session deactivation events.|
| [OH_AudioCommon_Result OH_AudioSessionManager_UnregisterSessionDeactivatedCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_DeactivatedCallback callback)](#oh_audiosessionmanager_unregistersessiondeactivatedcallback) | - | Unregisters the callback used to listen for audio session deactivation events.|

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
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_SYSTEM**: System error. |

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
| const [OH_AudioSession_Strategy](capi-ohaudio-oh-audiosession-strategy.md) *strategy | Pointer to an audio session strategy, which is an [OH_AudioSession_Strategy](capi-ohaudio-oh-audiosession-strategy.md) struct.                                                                                                                          |

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>1. The **audioSessionManager** parameter is nullptr.<br>2. The **strategy** parameter is invalid.<br>**AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE**: Invalid state. |

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
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **audioSessionManager** parameter is nullptr.<br>**AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE**: Invalid state. |

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
| bool | Check result. The value **true** is returned if the audio session is activated, and **false** is returned otherwise.|

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
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>1. The **audioSessionManager** parameter is nullptr.<br>2. The **callback** parameter is nullptr. |

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
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>1. The **audioSessionManager** parameter is nullptr.<br>2. The **callback** parameter is nullptr. |
