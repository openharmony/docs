# native_audio_session_manager.h


## Overview

The **native_audio_session_manager.h** file declares the functions related to an audio session manager.

You can call the functions to create an audio session manager, activates or deactivates an audio session, checks whether an audio session is activated, and listens for audio session deactivation events.

**Library**: libohaudio.so

**File to include**: &lt;ohaudio/native_audio_session_manager.h&gt;

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

**Related module**: [OHAudio](_o_h_audio.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [OH_AudioSession_Strategy](_o_h___audio_session___strategy.md) | Describes the audio session strategy. | 
| struct  [OH_AudioSession_DeactivatedEvent](_o_h___audio_session___deactivated_event.md) | Describes the event indicating that an audio session is deactivated. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_AudioSessionManager](_o_h_audio.md#oh_audiosessionmanager) [OH_AudioSessionManager](_o_h_audio.md#oh_audiosessionmanager) | Defines a struct for the audio session manager. | 
| typedef struct [OH_AudioSession_Strategy](_o_h___audio_session___strategy.md) [OH_AudioSession_Strategy](_o_h_audio.md#oh_audiosession_strategy) | Defines a struct for the audio session strategy. | 
| typedef struct [OH_AudioSession_DeactivatedEvent](_o_h___audio_session___deactivated_event.md) [OH_AudioSession_DeactivatedEvent](_o_h_audio.md#oh_audiosession_deactivatedevent) | Defines a struct for the event indicating that an audio session is deactivated. | 
| typedef int32_t (\*[OH_AudioSession_DeactivatedCallback](_o_h_audio.md#oh_audiosession_deactivatedcallback))([OH_AudioSession_DeactivatedEvent](_o_h___audio_session___deactivated_event.md) event) | Defines a function pointer to the callback function used to listen for audio session deactivation events. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_AudioSession_ConcurrencyMode](_o_h_audio.md#oh_audiosession_concurrencymode) { <br>CONCURRENCY_DEFAULT = 0, <br>CONCURRENCY_MIX_WITH_OTHERS = 1, <br>CONCURRENCY_DUCK_OTHERS = 2, <br>CONCURRENCY_PAUSE_OTHERS = 3 <br>} | Enumerates the audio concurrency modes. | 
| [OH_AudioSession_DeactivatedReason](_o_h_audio.md#oh_audiosession_deactivatedreason) { <br>DEACTIVATED_LOWER_PRIORITY = 0, <br>DEACTIVATED_TIMEOUT = 1 <br>} | Enumerates the reasons for deactivating an audio session. | 

### Functions

| Name| Description| 
| -------- | -------- |
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioManager_GetAudioSessionManager](_o_h_audio.md#oh_audiomanager_getaudiosessionmanager)([OH_AudioSessionManager](_o_h_audio.md#oh_audiosessionmanager) \*\*audioSessionManager) | Obtains an **OH_AudioSessionManager** instance. | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioSessionManager_ActivateAudioSession](_o_h_audio.md#oh_audiosessionmanager_activateaudiosession)([OH_AudioSessionManager](_o_h_audio.md#oh_audiosessionmanager) \*audioSessionManager, const [OH_AudioSession_Strategy](_o_h___audio_session___strategy.md) \*strategy) | Activates an audio session. | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioSessionManager_DeactivateAudioSession](_o_h_audio.md#oh_audiosessionmanager_deactivateaudiosession)([OH_AudioSessionManager](_o_h_audio.md#oh_audiosessionmanager) \*audioSessionManager) | Deactivates an audio session. | 
| bool [OH_AudioSessionManager_IsAudioSessionActivated](_o_h_audio.md#oh_audiosessionmanager_isaudiosessionactivated)([OH_AudioSessionManager](_o_h_audio.md#oh_audiosessionmanager) \*audioSessionManager) | Checks whether an audio session is activated. | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioSessionManager_RegisterSessionDeactivatedCallback](_o_h_audio.md#oh_audiosessionmanager_registersessiondeactivatedcallback)([OH_AudioSessionManager](_o_h_audio.md#oh_audiosessionmanager) \*audioSessionManager, [OH_AudioSession_DeactivatedCallback](_o_h_audio.md#oh_audiosession_deactivatedcallback) callback) | Registers a callback to listen for audio session deactivation events. | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioSessionManager_UnregisterSessionDeactivatedCallback](_o_h_audio.md#oh_audiosessionmanager_unregistersessiondeactivatedcallback)([OH_AudioSessionManager](_o_h_audio.md#oh_audiosessionmanager) \*audioSessionManager, [OH_AudioSession_DeactivatedCallback](_o_h_audio.md#oh_audiosession_deactivatedcallback) callback) | Unregisters the callback used to listen for audio session deactivation events. | 
