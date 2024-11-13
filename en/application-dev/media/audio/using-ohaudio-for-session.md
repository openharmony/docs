# Extended Audio Concurrency Strategy (C/C++)

The audio system offers a default concurrency strategy based on the audio stream type. If the default concurrency strategy cannot meet your service requirements, you can use an audio session to customize a strategy. The audio session is an extension of the default audio concurrency strategy. Example scenarios are as follows:

- When an application that continuously plays a short sound does not want to be paused when running in the background, it can obtain an audio session to ensure a seamless integration of the entire playback process.

- If the default concurrency strategy does not meet service requirements, an application can request an audio session and specify a strategy.

The following figure shows the audio session process.

![AudioSession status change](figures/audiosession-status-change.png)

## Prerequisites

To use the audio session management capability provided by OHAudio, add the corresponding header file.

### Linking the Dynamic Link Library in the CMake Script

``` cmake
target_link_libraries(sample PUBLIC libohaudio.so)
```

### Adding Header Files

Include the **native_audio_session_manager.h** header file so that the application can use the functions related to audio playback.

```cpp
#include <ohaudio/native_audio_session_manager.h>
```

## Audio Session Strategy

In scenarios where multiple audio streams are active, an application can proactively establish an audio session strategy to manage how other applications handle audio streams once it has acquired audio focus.

### Audio Concurrency Mode

When the default concurrency strategy cannot meet service requirements, you can configure the audio concurrency mode.

Four audio concurrency modes are provided. 

- **CONCURRENCY_DEFAULT**: default concurrency strategy, which is used no audio session is used.

- **CONCURRENCY_MIX_WITH_OTHERS**: mixes audio streams with other applications that are concurrently playing audio.

  It is assumed that application A adopts **CONCURRENCY_MIX_WITH_OTHERS** and is playing audio streams, and application B applies to play audio streams at a later time. The relationship between applications A and B is described in the table below.

  | Application Behavior Before Mode Configuration| Application Behavior After Mode Configuration|
  | ------------ | ------------------ |
  | Application A rejects the playback request of application B.| Application A mixes its audio playback with that of application B.|
  | Application A pauses the playback of application B.| Application A mixes its audio playback with that of application B.|
  | Application A lowers the volume of application B.| Application A mixes its audio playback with that of application B.|
  | Application B lowers the volume of application A.| If applications and B have similar types, application A mixes its audio playback with that of application B.|
  | Application B pauses the playback of application A.| If applications and B have similar types, application A mixes its audio playback with that of application B.|
  | Application B stops the playback of application A.| If applications and B have similar types, application A mixes its audio playback with that of application B.|

  It is assumed that application A is playing audio streams, and application B adopts **CONCURRENCY_MIX_WITH_OTHERS** and applies to play audio streams at a later time. The relationship between applications A and B is described in the table below.

  | Application Behavior Before Mode Configuration| Application Behavior After Mode Configuration|
  | ------------ | ------------------ |
  | Application A rejects the playback request of application B.| If applications and B have similar types, application A mixes its audio playback with that of application B.|
  | Application A pauses the playback of application B.| If applications and B have similar types, application A mixes its audio playback with that of application B.|
  | Application A lowers the volume of application B.| If applications and B have similar types, application A mixes its audio playback with that of application B.|
  | Application B lowers the volume of application A.| Application A mixes its audio playback with that of application B.|
  | Application B pauses the playback of application A.| Application A mixes its audio playback with that of application B.|
  | Application B stops the playback of application A.| Application A mixes its audio playback with that of application B.|

- **CONCURRENCY_DUCK_OTHERS**: lowers the volume of the application that is currently playing the audio.

  It is assumed that application A is playing audio streams, and application B adopts **CONCURRENCY_DUCK_OTHERS** and applies to play audio streams at a later time. The relationship between applications A and B is described in the table below.

  | Application Behavior Before Mode Configuration| Application Behavior After Mode Configuration|
  | ------------ | ------------------ |
  | Application B pauses the playback of application A.| Application B lowers the volume of application A.|
  | Application B stops the playback of application A.| Application B lowers the volume of application A.|

- **CONCURRENCY_PAUSE_OTHERS**: pauses the application that is currently playing the audio.

  It is assumed that application A is playing audio streams, and application B that adopts **CONCURRENCY_PAUSE_OTHERS** applies to play audio streams at a later time. The relationship between applications A and B is described in the table below.

  | Application Behavior Before Mode Configuration| Application Behavior After Mode Configuration|
  | ------------ | ------------------ |
  | Application B stops the playback of application A.| Application B pauses the playback of application A.|

## Audio Session Deactivation Event

It is recommended that an application listen for audio session deactivation events. When such an event occurs, the system performs corresponding operations on the related audio stream based on the reason of the deactivation.

If the application wants to customize a concurrency strategy through the audio session again, it must activate the audio session first.

### Reasons for Audio Session Deactivation

Two audio session deactivation reasons are preset:

- **DEACTIVATED_LOWER_PRIORITY**: The focus of the application that is playing audio streams is forcibly cleared.

- **DEACTIVATED_TIME_OUT**: The default duration is reached after the application creates an audio session or stops audio playback. In this case, the volume of the application that was lowered in volume by this session will be restored to its original level, and the application that was paused by this session will receive a stop playback focus event.

## Obtaining an Audio Session Manager

Create an **OH_AudioSessionManager** instance. Before using audio session management, you must call **OH_AudioManager_GetAudioSessionManager** to create an **OH_AudioSessionManager** instance.

  ```cpp
  OH_AudioSessionManager *audioSessionManager;
  OH_AudioManager_GetAudioSessionManager(&audioSessionManager);
  ```

## Activating an Audio Session

Call **OH_AudioSessionManager_ActivateAudioSession** to activate an audio session.

  ```cpp
  OH_AudioSession_Strategy strategy = {CONCURRENCY_MIX_WITH_OTHERS};
  
  OH_AudioSessionManager_ActivateAudioSession(audioSessionManager, &strategy);
  ```

## Deactivating an Audio Session

Call **OH_AudioSessionManager_DeactivateAudioSession** to deactivate an audio session when it is no longer needed.

  ```cpp
  OH_AudioSessionManager_DeactivateAudioSession(audioSessionManager);
  ```

## Checking Whether an Audio Session Is Activated

Call **OH_AudioSessionManager_IsAudioSessionActivated** to check whether an audio session is activated.

  ```cpp
  bool isActivated = OH_AudioSessionManager_IsAudioSessionActivated(audioSessionManager);
  ```

## Registering and Unregistering the Audio Session Deactivation Event Callback

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
Call **OH_AudioSessionManager_RegisterSessionDeactivatedCallback** to register a callback to listen for audio session deactivation events.

  ```cpp
  OH_AudioSessionManager_RegisterSessionDeactivatedCallback(audioSessionManager, MyAudioSessionDeactivatedCallback);
  ```

### Unregistering the Callback Used to Listen for Audio Session Deactivation Events

Call **OH_AudioSessionManager_UnregisterSessionDeactivatedCallback** to unregister the callback used to listen for audio session deactivation events.

  ```cpp
  OH_AudioSessionManager_UnregisterSessionDeactivatedCallback(audioSessionManager, MyAudioSessionDeactivatedCallback);
  ```

## Sample Code

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
