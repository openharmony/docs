# Using AudioSession to Manage Audio Focus (C/C++)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

In the scenario where multiple audio streams are concurrently playing, the system has preset a [default audio focus strategy](audio-playback-concurrency.md#audio-focus-strategy) for unified audio focus management of all streams (including playback and recording).

An application can use an audio session provided by the audio session manager to actively manage the audio focus. Specifically, it can customize an audio focus strategy and determine the timing for releasing the audio focus, thereby meeting its specific service needs.

This topic describes the usage and precautions of the C APIs related to the audio session. For more information about the audio focus and audio session, see [Introduction to Audio Focus and Audio Session](audio-playback-concurrency.md).

## Prerequisites

To use the audio session manager provided by OHAudio, add the corresponding header file.

### Linking the Dynamic Library in the CMake Script

``` cmake
target_link_libraries(sample PUBLIC libohaudio.so)
```

### Adding a Header File

Include the [native_audio_session_manager.h](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md) header file so that the application can use the functions related to audio playback.

```cpp
#include <ohaudio/native_audio_session_manager.h>
```

## Obtaining an Audio Session Manager

Create an [OH_AudioSessionManager](../../reference/apis-audio-kit/capi-ohaudio-oh-audiosessionmanager.md) instance. Before using any APIs of OH_AudioSessionManager, you must use [OH_AudioManager_GetAudioSessionManager](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager) to obtain an OH_AudioSessionManager instance.

  ```cpp
  OH_AudioSessionManager *audioSessionManager;
  OH_AudioManager_GetAudioSessionManager(&audioSessionManager);
  ```

## Activating an Audio Session

Call [OH_AudioSessionManager_ActivateAudioSession](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_activateaudiosession) to activate an audio session.

During the activation, specify an [audio session strategy](../../reference/apis-audio-kit/capi-ohaudio-oh-audiosession-strategy.md). The strategy contains the [OH_AudioSession_ConcurrencyMode](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosession_concurrencymode) parameter, which is used to declare the audio concurrency strategy.

  ```cpp
  OH_AudioSession_Strategy strategy = {CONCURRENCY_MIX_WITH_OTHERS};
  
  OH_AudioSessionManager_ActivateAudioSession(audioSessionManager, &strategy);
  ```

## Checking Whether an Audio Session Is Activated

Call [OH_AudioSessionManager_IsAudioSessionActivated](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_isaudiosessionactivated) to check whether an audio session is activated.

  ```cpp
  bool isActivated = OH_AudioSessionManager_IsAudioSessionActivated(audioSessionManager);
  ```

## Deactivating an Audio Session

Call [OH_AudioSessionManager_DeactivateAudioSession](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_deactivateaudiosession) to deactivate an audio session.

  ```cpp
  OH_AudioSessionManager_DeactivateAudioSession(audioSessionManager);
  ```

## Listening for Audio Session Deactivation Events

When using the audio session, you are advised to listen for the [OH_AudioSession_DeactivatedEvent](../../reference/apis-audio-kit/capi-ohaudio-oh-audiosession-deactivatedevent.md) event.

When an audio session is deactivated (not proactively), the application receives [OH_AudioSession_DeactivatedEvent](../../reference/apis-audio-kit/capi-ohaudio-oh-audiosession-deactivatedevent.md), which contains [OH_AudioSession_DeactivatedReason](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosession_deactivatedreason).

Upon this event, the application can perform operations based on service requirements, for example, releasing resources or reactivating the audio session.

### Defining a Callback

  ```cpp
  int32_t MyAudioSessionDeactivatedCallback(OH_AudioSession_DeactivatedEvent event)
  {
    switch(event.reason) {
      case DEACTIVATED_LOWER_PRIORITY:
        // The application focus is preempted.
        return 0;
      case DEACTIVATED_TIMEOUT:
        // A timeout error occurs.
        return 0;
    }
  }
  ```

### Registering a Callback to Listen for Audio Session Deactivation Events

Call [OH_AudioSessionManager_RegisterSessionDeactivatedCallback](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_registersessiondeactivatedcallback) to register a callback to listen for audio session deactivation events.

```cpp
OH_AudioSessionManager_RegisterSessionDeactivatedCallback(audioSessionManager, MyAudioSessionDeactivatedCallback);
```

### Unregistering the Callback Used to Listen for Audio Session Deactivation Events

Call [OH_AudioSessionManager_UnregisterSessionDeactivatedCallback](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_unregistersessiondeactivatedcallback) to cancel listening for audio session deactivation events.

```cpp
OH_AudioSessionManager_UnregisterSessionDeactivatedCallback(audioSessionManager, MyAudioSessionDeactivatedCallback);
```

**Below is a comprehensive example of creating, activating, and listening for an audio session:**

Refer to the sample code below to complete the process of creating, activating, and listening of an audio session.

  ```cpp
  #include <cstdint>
  #include "ohaudio/native_audio_session_manager.h"
  
  int32_t MyAudioSessionDeactivatedCallback(OH_AudioSession_DeactivatedEvent event)
  {
    switch(event.reason) {
      case DEACTIVATED_LOWER_PRIORITY:
        // The application focus is preempted.
        return 0;
      case DEACTIVATED_TIMEOUT:
        // A timeout error occurs.
        return 0;
    }
  }
  
  OH_AudioSessionManager *audioSessionManager;

  // Create an OH_AudioSessionManager instance.
  OH_AudioCommon_Result resultManager = OH_AudioManager_GetAudioSessionManager(&audioSessionManager);
  
  OH_AudioSession_Strategy strategy = {CONCURRENCY_MIX_WITH_OTHERS};

  // Set an audio concurrency mode and activate an audio session.
  OH_AudioCommon_Result resultActivate = OH_AudioSessionManager_ActivateAudioSession(audioSessionManager, &strategy);
  
  // Check whether the audio session is activated.
  bool isActivated = OH_AudioSessionManager_IsAudioSessionActivated(audioSessionManager);
  
  // Listen for audio session deactivation events.
  OH_AudioCommon_Result resultRegister = OH_AudioSessionManager_RegisterSessionDeactivatedCallback(audioSessionManager, MyAudioSessionDeactivatedCallback);

  // After the audio session is activated, the application can perform operations such as playing, pausing, stopping, and releasing audio streams.
  
  // Cancel listening for audio session deactivation events.
  OH_AudioCommon_Result resultUnregister = OH_AudioSessionManager_UnregisterSessionDeactivatedCallback(audioSessionManager, MyAudioSessionDeactivatedCallback);
  
  // Deactivate the audio session.
  OH_AudioCommon_Result resultDeactivate = OH_AudioSessionManager_DeactivateAudioSession(audioSessionManager);
  ```
## Requesting Focus by Setting Audio Session Scene Parameters
The application requests focus using an audio session. Call [OH_AudioSessionManager_SetScene](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_setscene) to set the scene parameters, and then call [OH_AudioSessionManager_ActivateAudioSession](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_activateaudiosession) to activate the audio session.

  ```cpp

  OH_AudioSessionManager_SetScene(audioSessionManager, AUDIO_SESSION_SCENE_MEDIA);

  OH_AudioSession_Strategy strategy = {CONCURRENCY_MIX_WITH_OTHERS};

  OH_AudioSessionManager_ActivateAudioSession(audioSessionManager, &strategy);
  ```

## Listening for Audio Session Focus State Change events
Listen for audio session focus state changes through [OH_AudioSession_StateChangedEvent](../../reference/apis-audio-kit/capi-ohaudio-oh-audiosession-statechangedevent.md).

**Below is a comprehensive example of requesting focus for an audio session and listening for focus change events:**

  ```cpp

OH_AudioSessionManager *audioSessionManager;

// Create an OH_AudioSessionManager instance.
OH_AudioCommon_Result resultManager = OH_AudioManager_GetAudioSessionManager(&audioSessionManager);

void AudioSessionStateChangedCallback(OH_AudioSession_StateChangedEvent event)
  {
    switch(event.stateChangeHint) {
      case AUDIO_SESSION_STATE_CHANGE_HINT_PAUSE:
        // The system has paused the audio stream (focus is temporarily lost). To ensure state consistency, the application needs to switch to the audio paused state.
        // Temporarily losing focus: When other audio streams release focus, the application will receive a resume event and can resume playback.
        break;
      case AUDIO_SESSION_STATE_CHANGE_HINT_RESUME:
        // The system has resumed the audio session.
        break;
      case AUDIO_SESSION_STATE_CHANGE_HINT_STOP:
        // The system has stopped the audio stream (focus is permanently lost). To ensure state consistency, the application should switch to the audio paused state.
        // Permanently losing focus: No audio focus event will be received. The user must manually trigger the operation to resume playback.
        break;
      case AUDIO_SESSION_STATE_CHANGE_HINT_TIME_OUT_STOP:
        // The system has stopped the audio session (permanently losing focus) due to inactivity. The application should switch to the audio paused state.
        // Permanently losing focus: No audio focus event will be received. The user must manually trigger the operation to resume playback.
        break;
      case AUDIO_SESSION_STATE_CHANGE_HINT_DUCK:
        // The system has ducked the volume down (to 20% of the normal volume by default).
        break;
      case AUDIO_SESSION_STATE_CHANGE_HINT_UNDUCK:
        // The system has restored the audio volume to normal.
        break;
      default:
        break;
      }
  }

  OH_AudioCommon_Result result = OH_AudioSessionManager_RegisterStateChangeCallback(audioSessionManager, AudioSessionStateChangedCallback);

  // In this example, AUDIO_SESSION_SCENE_MEDIA is selected. You can change the session scene as needed.
  OH_AudioSessionManager_SetScene(audioSessionManager, AUDIO_SESSION_SCENE_MEDIA);

  // In this example, CONCURRENCY_MIX_WITH_OTHERS is selected. You can change the strategy as needed.
  OH_AudioSession_Strategy strategy = {CONCURRENCY_MIX_WITH_OTHERS};

  result = OH_AudioSessionManager_ActivateAudioSession(audioSessionManager, &strategy);

  // Start multiple audio renderers or other audio playback as needed.

  result = OH_AudioSessionManager_DeactivateAudioSession(audioSessionManager);

  result = OH_AudioSessionManager_UnregisterStateChangeCallback(audioSessionManager, AudioSessionStateChangedCallback);

  ```
