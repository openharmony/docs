# Using OHAudio for Audio Session (C/C++)

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @funny_sunix-->
<!--Designer: @hao-liangfei-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=3a7084fa36f3aa40ad1ae670f066e28c8494300a translatedAt=2026-08-06T01:54:21.431Z pushedAt=2026-08-06T09:59:06.286Z -->

In the scenario where multiple audio streams are concurrently playing, the system has preset a [default audio focus strategy](audio-playback-concurrency.md#audio-focus-strategy) for unified audio focus management of all streams (including playback and recording).

An application can use an audio session provided by the audio session manager to actively manage the audio focus. Specifically, it can customize an audio focus strategy and determine the timing for releasing the audio focus, thereby meeting its specific service needs.

This section mainly introduces the usage and precautions of the AudioSession-related C APIs. For more information about audio focus and audio sessions, see [Introduction to Audio Focus](audio-playback-concurrency.md) and [Audio Session Management](audio-session-management.md).

## Prerequisites

To use the audio session manager provided by OHAudio, add the corresponding header file.

The following examples are code snippets. You can access the [complete sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioSessionSampleC) via the link at the bottom-right corner of each code snippet.

### Linking the Dynamic Library in the CMake Script

``` cmake
target_link_libraries(sample PUBLIC libohaudio.so)
```

### Adding a Header File

Include the [native_audio_session_manager.h](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md) header file so that the application can use the functions related to audio playback.

<!-- @[cimport_h](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleC/entry/src/main/cpp/audiosession.cpp) -->

``` C++
#include "ohaudio/native_audio_session_manager.h"
```

## Obtaining an Audio Session Manager

Create an [OH_AudioSessionManager](../../reference/apis-audio-kit/capi-ohaudio-oh-audiosessionmanager.md) instance. Before using any APIs of OH_AudioSessionManager, you must use [OH_AudioManager_GetAudioSessionManager](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager) to obtain an OH_AudioSessionManager instance.

<!-- @[cget_sessionmanager](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleC/entry/src/main/cpp/audiosession.cpp) -->  

``` C++
OH_AudioSessionManager *audioSessionManager;
// ...
    OH_AudioCommon_Result resultManager = OH_AudioManager_GetAudioSessionManager(&audioSessionManager);
    if (resultManager == 0) {
        OH_LOG_Print(LOG_APP, LOG_INFO, g_audioSessionVariable->globalResmgr, SESSION_TAG,
                     " OH_AudioManager_GetAudioSessionManager success! ");
    }
    OH_AudioCommon_Result result = OH_AudioSessionManager_RegisterStateChangeCallback(audioSessionManager,
                                                                                      AudioSessionStateChangedCallback);    
```

## Activating an Audio Session

Call [OH_AudioSessionManager_ActivateAudioSession](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_activateaudiosession) to activate an audio session.

During the activation, specify an [audio session strategy](../../reference/apis-audio-kit/capi-ohaudio-oh-audiosession-strategy.md). The strategy contains the [OH_AudioSession_ConcurrencyMode](../../reference/apis-audio-kit/capi-native-audio-session-base-h.md#oh_audiosession_concurrencymode) parameter, which is used to declare the audio concurrency strategy.

<!-- @[cactive_sessionmanager](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleC/entry/src/main/cpp/audiosession.cpp) -->

``` C++
// In this example, CONCURRENCY_MIX_WITH_OTHERS is selected. You can change the strategy as needed.
OH_AudioSession_Strategy strategy = {CONCURRENCY_MIX_WITH_OTHERS};
    
// Set an audio concurrency mode and activate an audio session.
OH_AudioSessionManager_ActivateAudioSession(audioSessionManager, &strategy);
```

## Checking Whether an Audio Session Is Activated

Call [OH_AudioSessionManager_IsAudioSessionActivated](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_isaudiosessionactivated) to check whether an audio session is activated.

<!-- @[ccheck_isactivated](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleC/entry/src/main/cpp/audiosession.cpp) -->

``` C++
bool isActivated = OH_AudioSessionManager_IsAudioSessionActivated(audioSessionManager);
```

## Setting Session-Level Recording Stream Mute Hint

Starting from API version 24, when an app has muted the recording streams within the current audio session on the service side, it can call [OH_AudioSessionManager_SetCaptureMuteHint](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_setcapturemutehint) to report this state to the system audio module. The system audio module then adjusts its strategy based on the reported state to reduce power consumption. This feature currently takes effect only on certain PC and 2-in-1 devices. This API does not actually trigger muting, nor does it perform mute processing on recording data. It merely informs the system audio module that the app has muted the recording streams within the current audio session. The app must still handle recording data on its own, for example, by not sending captured data or by sending silent data.

This API can only be called when there is an active recording stream in the current audio session; otherwise, it returns `AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE`. If a recording stream has both the stream-level mute hint API [OH_AudioCapturer_SetMuteHint](../../reference/apis-audio-kit/capi-native-audiocapturer-h.md#oh_audiocapturer_setmutehint) and the session-level mute hint API called on it, the stream-level setting takes precedence. Therefore, when multiple recording streams in an app share the same mute state, you can use the session-level API for unified reporting. When different recording streams have different mute states, use the stream-level API for each specific recording stream. If you create a recording stream with a mic audio source solely to call the session-level API, you must request the microphone permission `ohos.permission.MICROPHONE`.

<!-- @[cset_capturer_mute_hint](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleC/entry/src/main/cpp/audiosession.cpp) --> 

``` C++
bool mute = true;
OH_AudioCommon_Result setResult = OH_AudioSessionManager_SetCaptureMuteHint(audioSessionManager, mute);
if (setResult != AUDIOCOMMON_RESULT_SUCCESS) {
    // Handle exceptions based on the return value, such as AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE.
}

mute = false;
OH_AudioCommon_Result unsetResult = OH_AudioSessionManager_SetCaptureMuteHint(audioSessionManager, mute);
```

## Deactivating an Audio Session

Call [OH_AudioSessionManager_DeactivateAudioSession](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_deactivateaudiosession) to deactivate an audio session.

<!-- @[cdeactive_audiosession](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleC/entry/src/main/cpp/audiosession.cpp) -->

``` C++
OH_AudioCommon_Result result;
// ...
result = OH_AudioSessionManager_DeactivateAudioSession(audioSessionManager);
```

## Listening for Audio Session Deactivation Events

When using the audio session, you are advised to listen for the [OH_AudioSession_DeactivatedEvent](../../reference/apis-audio-kit/capi-ohaudio-oh-audiosession-deactivatedevent.md) event.

When an audio session is deactivated (not proactively), the application receives [OH_AudioSession_DeactivatedEvent](../../reference/apis-audio-kit/capi-ohaudio-oh-audiosession-deactivatedevent.md), which contains [OH_AudioSession_DeactivatedReason](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosession_deactivatedreason).

Upon this event, the application can perform operations based on service requirements, for example, releasing resources or reactivating the audio session.

### Defining a Callback

<!-- @[cint_deacticatedcallback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleC/entry/src/main/cpp/audiosession.cpp) -->

``` C++
int32_t MyAudioSessionDeactivatedCallback(OH_AudioSession_DeactivatedEvent event)
{
    switch (event.reason) {
        case DEACTIVATED_LOWER_PRIORITY:
          // The application focus is preempted.
            return 0;
        case DEACTIVATED_TIMEOUT:
          // A timeout error occurs.
            return 0;
    }
}

OH_AudioSessionManager *audioSessionManager;
```

### Registering a Callback to Listen for Audio Session Deactivation Events

Call [OH_AudioSessionManager_RegisterSessionDeactivatedCallback](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_registersessiondeactivatedcallback) to register a callback to listen for audio session deactivation events.

<!-- @[cregist_deacticatedcallback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleC/entry/src/main/cpp/audiosession.cpp) -->

``` C++
OH_AudioCommon_Result resultRegister = OH_AudioSessionManager_RegisterSessionDeactivatedCallback(
    audioSessionManager, MyAudioSessionDeactivatedCallback);
```

### Unregistering the Callback Used to Listen for Audio Session Deactivation Events

Call [OH_AudioSessionManager_UnregisterSessionDeactivatedCallback](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_unregistersessiondeactivatedcallback) to cancel listening for audio session deactivation events.

<!-- @[cunregist_deacticatedcallback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleC/entry/src/main/cpp/audiosession.cpp) -->

``` C++
OH_AudioCommon_Result resultUnregister = OH_AudioSessionManager_UnregisterSessionDeactivatedCallback(
    audioSessionManager, MyAudioSessionDeactivatedCallback);
```

**Below is a comprehensive example of creating, activating, and listening for an audio session:**

Refer to the sample code below to complete the process of creating, activating, and listening of an audio session.

<!-- @[csessionactive_process](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleC/entry/src/main/cpp/audiosession.cpp) -->

``` C++
#include <cstdint>
#include "ohaudio/native_audio_session_manager.h"
// ...
int32_t MyAudioSessionDeactivatedCallback(OH_AudioSession_DeactivatedEvent event)
{
    switch (event.reason) {
        case DEACTIVATED_LOWER_PRIORITY:
          // The application focus is preempted.
            return 0;
        case DEACTIVATED_TIMEOUT:
          // A timeout error occurs.
            return 0;
    }
}

OH_AudioSessionManager *audioSessionManager;
// ...
    OH_AudioCommon_Result resultManager = OH_AudioManager_GetAudioSessionManager(&audioSessionManager);
    // ...
    OH_AudioSession_Strategy strategy = {CONCURRENCY_MIX_WITH_OTHERS};
    
    // Set an audio concurrency mode and activate an audio session.
    OH_AudioSessionManager_ActivateAudioSession(audioSessionManager, &strategy);
    // Check whether the audio session is activated.
    bool isActivated = OH_AudioSessionManager_IsAudioSessionActivated(audioSessionManager);
    if (isActivated) {
        OH_LOG_Print(LOG_APP, LOG_INFO, g_audioSessionVariable->globalResmgr, SESSION_TAG,
                     " AudioSessionManager is activated! ");
    }
    // Listen for audio session deactivation events.
    OH_AudioCommon_Result resultRegister = OH_AudioSessionManager_RegisterSessionDeactivatedCallback(
        audioSessionManager, MyAudioSessionDeactivatedCallback);
    // ...
    // Cancel listening for audio session deactivation events.
    result = OH_AudioSessionManager_UnregisterStateChangeCallback(audioSessionManager,
                                                                  AudioSessionStateChangedCallback);
    // ...
    // Deactivate the audio session.
    result = OH_AudioSessionManager_DeactivateAudioSession(audioSessionManager);
```

## Requesting Focus by Setting Audio Session Scene Parameters

The application requests focus using an audio session. Call [OH_AudioSessionManager_SetScene](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_setscene) to set the scene parameters, and then call [OH_AudioSessionManager_ActivateAudioSession](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_activateaudiosession) to activate the audio session.

<!-- @[cset_audioscene](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleC/entry/src/main/cpp/audiosession.cpp) -->

``` C++
// In this example, AUDIO_SESSION_SCENE_MEDIA is selected. You can change the session scene as needed.
OH_AudioSessionManager_SetScene(audioSessionManager, AUDIO_SESSION_SCENE_MEDIA);
// ...
// In this example, CONCURRENCY_MIX_WITH_OTHERS is selected. You can change the strategy as needed.
OH_AudioSession_Strategy strategy = {CONCURRENCY_MIX_WITH_OTHERS};
    
// Set an audio concurrency mode and activate an audio session.
OH_AudioSessionManager_ActivateAudioSession(audioSessionManager, &strategy);
```

## Enabling Mute Suggestion Notifications for Mixed Playback

Starting from API version 23, when the current application plays audio in the **CONCURRENCY_MIX_WITH_OTHERS** concurrency mode, if audio from other applications is playing simultaneously, the audio from both will be mixed. In certain scenarios (such as games or broadcasts), applications can enable mute suggestion notifications to enhance user experience.

After enabling mute suggestion notifications, if other applications play audio that cannot be played concurrently with the current application while the current application is playing audio, the current application will receive a mute suggestion notification. The current application can either choose to take no action (allowing concurrent playback with other applications) or mute itself to let other applications play audio alone.

To enable the mute suggestion notification when mixing with others, you must first call [OH_AudioSessionManager_SetScene](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_setscene) to set scene parameters, call [OH_AudioSessionManager_EnableMuteSuggestionWhenMixWithOthers](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_enablemutesuggestionwhenmixwithothers) to enable the feature, subscribe to the audio session state change event [OH_AudioSession_StateChangeHint](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosession_statechangehint), and finally call [OH_AudioSessionManager_ActivateAudioSession](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_activateaudiosession) to activate the AudioSession. A prerequisite for enabling the mute suggestion notification is that the [OH_AudioSession_ConcurrencyMode](../../reference/apis-audio-kit/capi-native-audio-session-base-h.md#oh_audiosession_concurrencymode) must be set to CONCURRENCY_MIX_WITH_OTHERS.

<!-- @[cenable_muteSuggestion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleC/entry/src/main/cpp/audiosession.cpp) -->

``` C++
// In this example, AUDIO_SESSION_SCENE_MEDIA is selected. You can change the session scene as needed.
OH_AudioSessionManager_SetScene(audioSessionManager, AUDIO_SESSION_SCENE_MEDIA);
// Enable mute suggestions for mixed playback.
OH_AudioSessionManager_EnableMuteSuggestionWhenMixWithOthers(audioSessionManager, true);
// ...
OH_AudioSession_Strategy strategy = {CONCURRENCY_MIX_WITH_OTHERS};
    
// Set an audio concurrency mode and activate an audio session.
OH_AudioSessionManager_ActivateAudioSession(audioSessionManager, &strategy);
```

## Listening for Audio Session Focus State Change events

Listen for audio session focus state changes through [OH_AudioSession_StateChangedEvent](../../reference/apis-audio-kit/capi-ohaudio-oh-audiosession-statechangedevent.md).

**Below is a comprehensive example of requesting focus for an audio session and listening for focus change events:**

<!-- @[clistencallback_process](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleC/entry/src/main/cpp/audiosession.cpp) --> 

``` C++
OH_AudioSessionManager *audioSessionManager;

void AudioSessionStateChangedCallback(OH_AudioSession_StateChangedEvent event)
{
    switch (event.stateChangeHint) {
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
          // This branch indicates that the system has stopped the AudioSession (permanently losing focus) due to no audio stream playback for an extended period.
          // This prevents long-term invalid occupation of system resources. To maintain state consistency, the application needs to switch to the audio pause state.
          // Permanently losing focus: No audio focus event will be received. The user must manually trigger the operation to resume playback.
            break;
        case AUDIO_SESSION_STATE_CHANGE_HINT_DUCK:
          // The system has ducked the volume down (to 20% of the normal volume by default).
            break;
        case AUDIO_SESSION_STATE_CHANGE_HINT_UNDUCK:
          // The system has restored the audio volume to normal.
            break;
        case AUDIO_SESSION_STATE_CHANGE_HINT_MUTE_SUGGESTION:
          // This branch indicates that another application has started playing non-mixed audio, and the system may decide whether to mute the current application.
            break;
        case AUDIO_SESSION_STATE_CHANGE_HINT_UNMUTE_SUGGESTION:
          // This branch indicates that another application has finished playing non-mixed audio, and the system may decide whether to unmute the current application.
            break;
        case AUDIO_SESSION_STATE_CHANGE_HINT_MUTE:
          // This branch indicates that the system has muted the audio.
            break;
        case AUDIO_SESSION_STATE_CHANGE_HINT_UNMUTE:
          // This branch indicates that the system has unmuted the audio.
            break;
        default:
            break;
    }
}
// ...
    OH_AudioCommon_Result result = OH_AudioSessionManager_RegisterStateChangeCallback(audioSessionManager,
                                                                                      AudioSessionStateChangedCallback);
    // ...
    // In this example, AUDIO_SESSION_SCENE_MEDIA is selected. You can change the session scene as needed.
    OH_AudioSessionManager_SetScene(audioSessionManager, AUDIO_SESSION_SCENE_MEDIA);
    // Enable mute suggestions for mixed playback.
    OH_AudioSessionManager_EnableMuteSuggestionWhenMixWithOthers(audioSessionManager, true);
    // In this example, CONCURRENCY_MIX_WITH_OTHERS is selected. You can change the strategy as needed.
    OH_AudioSession_Strategy strategy = {CONCURRENCY_MIX_WITH_OTHERS};
    
    // Set an audio concurrency mode and activate an audio session.
    OH_AudioSessionManager_ActivateAudioSession(audioSessionManager, &strategy);
    // ...
    result = OH_AudioSessionManager_DeactivateAudioSession(audioSessionManager);
    // ...
    OH_AudioCommon_Result resultUnregister = OH_AudioSessionManager_UnregisterSessionDeactivatedCallback(
        audioSessionManager, MyAudioSessionDeactivatedCallback);
```

## Setting Audio Session Behavior

Starting from API version 24, you can set audio session behavior parameters through [OH_AudioSessionManager_SetBehavior](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_setbehavior) to achieve a better audio focus experience in specific scenarios.

In a live streaming scenario, when another app starts an audio stream (for example, using a keyboard for speech-to-text) that interrupts the live stream, the audio and video of the live stream are paused, degrading the viewing experience. A live streaming app can set the [OH_AudioSession_BehaviorFlags](../../reference/apis-audio-kit/capi-native-audio-session-base-h.md#oh_audiosession_behaviorflags).MUTE_WHEN_INTERRUPTED session behavior so that the live stream remains in muted playback instead of pausing when interrupted, thereby avoiding video interruption.

If your app does not use audio session management, you can also set independent audio session behavior for individual audio streams. For playback streams, see [OH_AudioRenderer_SetIndependentAudioSessionStrategy](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md#oh_audiorenderer_setindependentaudiosessionstrategy). For recording streams, see [OH_AudioCapturer_SetIndependentAudioSessionStrategy](../../reference/apis-audio-kit/capi-native-audiocapturer-h.md#oh_audiocapturer_setindependentaudiosessionstrategy).

<!-- @[cset_session_behavior](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleC/entry/src/main/cpp/audiosession.cpp) -->

``` C++
// AUDIO_SESSION_SCENE_MEDIA is only an example. Modify it based on the actual situation.
OH_AudioSessionManager_SetScene(audioSessionManager, AUDIO_SESSION_SCENE_MEDIA);
    
// Call this API before activating the audio session.
// If this API is called while the audio session is in the activated state, you must re-activate the audio session for the changes to take effect.
uint32_t behavior = OH_AudioSession_BehaviorFlags::MUTE_WHEN_INTERRUPTED;
OH_AudioSessionManager_SetBehavior(audioSessionManager, behavior);
    
OH_AudioSession_Strategy strategy = {CONCURRENCY_PAUSE_OTHERS};
    
// Set the audio concurrency mode and activate the audio session.
OH_AudioSessionManager_ActivateAudioSession(audioSessionManager, &strategy);
```

<!--no_check-->
