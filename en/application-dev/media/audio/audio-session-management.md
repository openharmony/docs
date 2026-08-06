# Audio Session Management (ArkTS)

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @funny_sunix-->
<!--Designer: @hao-liangfei-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9f16298947fff422a95582209d672f68fd597026 translatedAt=2026-08-06T01:49:31.539Z pushedAt=2026-08-06T08:09:10.700Z -->

In the scenario where multiple audio streams are concurrently playing, the system has preset a default [audio focus strategy](audio-playback-concurrency.md#audio-focus-strategy) for unified audio focus management across all audio streams (including playback and recording).

When the default focus strategy provided by the system cannot meet app requirements, you can use the APIs provided by audio session management to manage the focus of audio streams within the app, customize the focus strategy for audio streams, and adjust the timing for releasing audio focus to meet specific needs. The sample code in this document is all ArkTS. If you need to use OHAudio for development, see [Using OHAudio for Audio Session (C/C++)](using-ohaudio-for-session.md).

The audio session APIs can be used to implement the following features:

- When the system default focus strategy cannot meet the current app requirements, you can [use an audio session to modify the focus strategy](#using-an-audio-session-to-modify-the-focus-strategy) to adapt a focus strategy that suits your needs.

  Typical scenario: When an app plays a short video, it interrupts background music. The app expects the background music to automatically resume after its own audio stream stops. (This scenario requires the app to activate the audio session before starting the audio stream and deactivate the audio session after the audio stream stops.)

- When an app needs to start multiple audio streams in a business process and must ensure the integrity of the entire process, you can [use an audio session to request a focus strategy](#using-an-audio-session-to-request-a-focus-strategy) to adapt a focus strategy that suits your business scenario.

  Typical scenario: When an app plays multiple audio clips consecutively, during the gaps between clips, the app does not want other affected background audio to automatically resume. Instead, it wants to maintain audio focus continuity throughout the entire playback process. (This scenario requires the app to activate the audio session before the entire playback process starts and deactivate the audio session after the entire playback process ends.)

> **NOTE**
>
> - The audio concurrency strategy priority is: STOP > PAUSE > DUCK > PLAYBOTH. When the specified audio session strategy has a higher priority than the default concurrency strategy, the specified audio session strategy will not take effect.
> - Before starting audio playback or recording, ensure that the audio session is already activated. Otherwise, the custom focus strategy of the audio session will not take effect. If the app uses asynchronous APIs, pay extra attention to the timing of asynchronous operations.

## Obtaining an Audio Session Manager

Before using any APIs of AudioSessionManager, you must call [getSessionManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioManager.md#getsessionmanager12) to obtain a singleton AudioSessionManager instance.

For OHAudio development, see [Obtaining an Audio Session Manager](using-ohaudio-for-session.md#obtaining-an-audio-session-manager).

<!-- @[get_session_manager](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
import { audio } from '@kit.AudioKit';
// ...

let audioManager = audio.getAudioManager();
// Create an audio session manager.
let audioSessionManager: audio.AudioSessionManager = audioManager.getSessionManager();
```

## Setting a Session-Level Recording Stream Mute Prompt

Starting from API version 24, when an app has muted the recording stream in the current audio session on the service side, you can call [setCapturerMuteHint](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setcapturermutehint24) to report this state to the system audio module. The system audio module adjusts its strategy based on the reported state to reduce power consumption. Note that this feature currently takes effect only on certain PC/2-in-1 devices. This API does not actually trigger muting or perform mute processing on recording data. It only notifies the system audio module that the app has muted the recording stream in the current audio session. You still need to handle the recording data yourself, for example, by not sending captured data or by sending mute data.

This API can only be called when there is a running recording stream in the current audio session. Otherwise, error code `6800103` is returned. If a recording stream has both the stream-level mute prompt API [AudioCapturer.setMuteHint](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#setmutehint24) and the session-level mute prompt API called, the stream-level setting takes precedence. Therefore, when the mute states of multiple recording streams in the app are consistent, you can use the session-level API for unified reporting. When the mute states of different recording streams are inconsistent, use the stream-level API for specific recording streams. If you create a Mic audio source recording stream to call the session-level API, you need to request the microphone permission `ohos.permission.MICROPHONE`. No system query API is currently provided. If you need to display the mute prompt state on the UI, you must maintain the most recently set state yourself. In the following example, `muteHint` set to `true` indicates reporting a mute prompt, and `false` indicates canceling the mute prompt.

<!-- @[set_capturer_mute_hint](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
try {
  await audioSessionManager.setCapturerMuteHint(muteHint);
  console.info(`setCapturerMuteHint ${muteHint} success.`);
  // ...
} catch (err) {
  let error = err as BusinessError;
  console.error(`setCapturerMuteHint ${muteHint} failed. Code: ${error.code}, message: ${error.message}`);
  // ...
}
```

## Audio Session Strategy

When activating an AudioSession, you must first specify an audio session strategy ([AudioSessionStrategy](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiosessionstrategy12)). You can specify different audio session strategies by setting the audio concurrency mode ([AudioConcurrencyMode](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audioconcurrencymode12)).

For OHAudio development, see Audio Session Strategy ([OH_AudioSession_Strategy](../../reference/apis-audio-kit/capi-ohaudio-oh-audiosession-strategy.md)).

The system preset audio concurrency modes are as follows:

- Default mode (CONCURRENCY_DEFAULT): The system default [audio focus strategy](audio-playback-concurrency.md#audio-focus-strategy).

- Concurrency mode (CONCURRENCY_MIX_WITH_OTHERS): Plays concurrently with other audio streams.

  **Typical scenarios:**

  - When an app plays music, it may be interrupted by subsequent music or video. The app expects its own audio stream to play concurrently with the subsequent music or video. (This scenario requires the app to activate the AudioSession before starting the audio stream.)

  - When an app records audio, it interrupts background music or video that is playing. The app expects its own audio stream to play concurrently with the background music or video. (This scenario requires the app to activate the AudioSession before starting the audio stream.)

- Duck mode (CONCURRENCY_DUCK_OTHERS): Plays concurrently with other audio streams and reduces the volume of other audio streams.

  **Typical scenario:** When an app plays game sound effects, it plays concurrently with background music. The app expects to lower the volume of the background music while playing concurrently with it. (This scenario requires the app to activate the AudioSession before starting the audio stream.)

- Pause mode (CONCURRENCY_PAUSE_OTHERS): Pauses other audio streams and notifies them to resume after the focus is released.

  **Typical scenario:** When an app plays a short video, it interrupts background music that is playing. The app expects the background music to automatically resume after its own audio stream stops. (This scenario requires the app to activate the AudioSession before starting the audio stream and deactivate the AudioSession after the audio stream stops.)

> **NOTE**
>
> - When an app uses the above modes through AudioSession, the system will try its best to satisfy the focus policy, but it may not be fully guaranteed in all scenarios.
> - The concurrency mode (CONCURRENCY_MIX_WITH_OTHERS) takes effect both when the current app requests focus and when other apps subsequently request focus. The duck mode (CONCURRENCY_DUCK_OTHERS) and pause mode (CONCURRENCY_PAUSE_OTHERS) take effect only when the current app requests focus. When other apps subsequently request focus, their concurrency modes take precedence.

## Using an Audio Session to Modify the Focus Strategy

When the system default focus strategy cannot meet the current app requirements, you can modify the focus strategy by specifying an [audio session strategy](#audio-session-strategy) and then activating the AudioSession.

After the AudioSession is successfully activated, new audio streams started by the app will follow the modified focus strategy.

When using AudioSession to modify the focus strategy, the AudioSession does not hold the focus. The focus is still held by individual audio streams.

For OHAudio development, see [Using OHAudio for Audio Session (C/C++)](using-ohaudio-for-session.md).

> **NOTE**
> 
> When the AudioSession is deactivated due to timeout, the audio streams that were ducked by it will trigger an unduck operation, and the audio streams that were paused by it will trigger a stop operation.

### AudioSession Deactivation Event

When using AudioSession, you are recommended to listen for the audio session deactivation event (AudioSessionDeactivatedEvent). When the AudioSession is deactivated (not proactively), the app receives this event notification. You can perform corresponding operations based on your service requirements, for example, releasing resources or reactivating the AudioSession.

The audio session deactivation event (AudioSessionDeactivatedEvent) contains the `AudioSessionDeactivatedReason` parameter, which identifies the specific reason for session deactivation (such as focus preemption or timeout).

1. App focus preempted (DEACTIVATED_LOWER_PRIORITY): When all audio streams of the app have their focus preempted by other apps, the AudioSession is deactivated at the same time.

2. Timeout (DEACTIVATED_TIMEOUT): If the AudioSession is in the activated state but the app has no audio stream running, the AudioSession will be deactivated after a specified period due to timeout.

### How to Develop

1. Specify an audio session strategy (AudioSessionStrategy) and activate the audio session.

   You can call [activateAudioSession](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#activateaudiosession12) to activate the audio session of the current app.

   When activating the AudioSession, you must specify an [audio session strategy](#audio-session-strategy). The strategy contains the **concurrencyMode** parameter, which is of the [AudioConcurrencyMode](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audioconcurrencymode12) type and is used to declare the audio concurrency strategy.

   <!-- @[activate_audio_session_v1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   import { audio } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   // ...
   
     // Set the audio concurrency mode.
     let strategy: audio.AudioSessionStrategy = {
       concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_MIX_WITH_OTHERS
     };
   
     // Activate the audio session.
     audioSessionManager.activateAudioSession(strategy).then(() => {
       console.info('Succeeded in activating audio session.');
       // ...
     }).catch((err: BusinessError) => {
       console.error(`Failed to activate audio session. Code: ${err.code}, message: ${err.message}`);
       // ...
     });
   ```

2. Check whether the audio session is activated (optional).

   You can call [isAudioSessionActivated](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#isaudiosessionactivated12) to check whether the audio session of the current app is activated.

   <!-- @[is_audio_session_activated](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // Check whether the audio session is activated.
   let isActivated = audioSessionManager.isAudioSessionActivated();
   ```

3. Listen for audio session deactivation events (optional).

   You can call [on('audioSessionDeactivated')](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#onaudiosessiondeactivated12) to listen for audio session deactivation events ([AudioSessionDeactivatedEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiosessiondeactivatedevent12)).

   When the AudioSession is deactivated (not proactively), the app receives an audio session deactivation event ([AudioSessionDeactivatedEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiosessiondeactivatedevent12)), which contains the audio session deactivation reason ([AudioSessionDeactivatedReason](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audiosessiondeactivatedreason12)).

   Upon receiving AudioSessionDeactivatedEvent, you can perform corresponding operations based on your service requirements, for example, releasing resources or reactivating the AudioSession.

   You can call [off('audioSessionDeactivated')](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#offaudiosessiondeactivated12) to cancel listening for audio session deactivation events.

   <!-- @[on_audio_session_deactivated](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   import { audio } from '@kit.AudioKit';
   // ...
   
     // Listen for audio session deactivation events.
     audioSessionManager.on('audioSessionDeactivated', (audioSessionDeactivatedEvent: audio.AudioSessionDeactivatedEvent) => {
       // ...
       console.info(`Succeeded in using on function. AudioSessionDeactivatedEvent: ${JSON.stringify(audioSessionDeactivatedEvent)}`);
     });
   ```

4. Deactivate the audio session.

   You can call [deactivateAudioSession](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#deactivateaudiosession12) to deactivate the audio session of the current app.

   > **NOTE**
   >
   > After the AudioSession is deactivated, new audio streams started by the app will follow the default focus strategy.

   <!-- @[deactivate_audio_session_v1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   import { BusinessError } from '@kit.BasicServicesKit';
   // ...
   
     // Deactivate the audio session.
     // ...
     audioSessionManager.deactivateAudioSession().then(() => {
       console.info('Succeeded in deactivating audio session.');
       // ...
     }).catch((err: BusinessError) => {
       console.error(`Failed to deactivate audio session. Code: ${err.code}, message: ${err.message}`);
       // ...
     });
   ```

### Sample

The following shows the sample code for modifying the focus strategy using AudioSession.

<!-- @[audio_session_v1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

let audioManager = audio.getAudioManager();
// Create an audio session manager.
let audioSessionManager: audio.AudioSessionManager = audioManager.getSessionManager();
// ...
  // Set the audio concurrency mode.
  let strategy: audio.AudioSessionStrategy = {
    concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_MIX_WITH_OTHERS
  };

  // Activate the audio session.
  audioSessionManager.activateAudioSession(strategy).then(() => {
    console.info('Succeeded in activating audio session.');
    // ...
  }).catch((err: BusinessError) => {
    console.error(`Failed to activate audio session. Code: ${err.code}, message: ${err.message}`);
    // ...
  });

  // Check whether the audio session is activated.
  let isActivated = audioSessionManager.isAudioSessionActivated();

  // Listen for audio session deactivation events.
  audioSessionManager.on('audioSessionDeactivated', (audioSessionDeactivatedEvent: audio.AudioSessionDeactivatedEvent) => {
    // ...
    console.info(`Succeeded in using on function. AudioSessionDeactivatedEvent: ${JSON.stringify(audioSessionDeactivatedEvent)}`);
  });

  if (isActivated) {
    // After the audio session is activated, the app can perform audio playback, pause, stop, release, and other operations here.
  }
  // ...

  // Stop listening for audio session deactivation events.
  audioSessionManager.off('audioSessionDeactivated');

  // ...
  // Deactivate the audio session.
  // ...
  audioSessionManager.deactivateAudioSession().then(() => {
    console.info('Succeeded in deactivating audio session.');
    // ...
  }).catch((err: BusinessError) => {
    console.error(`Failed to deactivate audio session. Code: ${err.code}, message: ${err.message}`);
    // ...
  });
```

## Using an Audio Session to Request a Focus Strategy

When an app needs to start multiple audio streams and ensure process continuity, you can request focus through AudioSession to ensure the continuity of multi-audio-stream playback.

When activating the AudioSession, the system requests the corresponding audio focus based on the [audio session scene](#audio-session-scene) selected by the app, and the AudioSession holds the focus. Subsequent playback streams started by the app through AudioRenderer will no longer request audio focus.

For OHAudio development, see [Using OHAudio for Audio Session (C/C++)](using-ohaudio-for-session.md).

Typical usage scenarios are as follows:

- When swiping through multiple short videos, frequent focus requests and releases by multiple audio streams may cause audio leakage. Using AudioSession to request focus once can avoid frequent focus requests and releases during the playback of multiple audio streams, thereby preventing audio leakage.

- In a VoIP call scenario, you may need to start a ringtone stream, a recording stream, and a playback stream. These audio streams have different focus priorities, and some may be interrupted by audio streams from other apps. To maintain the continuity of the service experience, you can use AudioSession to request focus and prevent audio streams from being interrupted.

- An app uses a player SDK to play audio streams, does not hold an AudioRenderer object, but wants to listen for focus changes.

> **NOTE**
>
> - The focus requested by AudioSession is at the app level. If the app contains different modules, coordination between modules is required to prevent a situation where one module requests focus through AudioSession while another module's audio streams are affected by the AudioSession focus management, producing unexpected results.
> - Requesting focus through AudioSession is effective only for playback streams. It is not effective for recording streams and certain playback audio streams (such as STREAM_USAGE_ALARM, STREAM_USAGE_NOTIFICATION, STREAM_USAGE_ACCESSIBILITY, etc.).
> - During the AudioSession activation process, if you dynamically modify AudioSessionScene, you need to call activateAudioSession again for the change to take effect.
> - After requesting focus through AudioSession, the focus is held by the AudioSession. After the current playback scenario ends, you must proactively deactivate the AudioSession to release the focus. This prevents abnormal focus holding caused by unreleased focus after the playback stream stops.

### Audio Session Scene

When using AudioSession to request a focus strategy, the system provides three audio session scenes. Before activating the AudioSession, you must call [setAudioSessionScene](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setaudiosessionscene20) to set the corresponding audio session scene. When the AudioSession is activated, the system requests the corresponding audio focus based on the audio session scene selected by the app.

| Name                   | Value | Description      |
| :--------------------- |:--|:--------|
| AUDIO_SESSION_SCENE_MEDIA | 0 | Media audio session scene.     |
| AUDIO_SESSION_SCENE_GAME | 1 | Game audio session scene.     |
| AUDIO_SESSION_SCENE_VOICE_COMMUNICATION  | 2 | VoIP voice call audio session scene. |

### Listening for AudioSession Focus and State Change Events

The focus requested by AudioSession and the focus requested by AudioRenderer have equal status.

You can call [on('audioSessionStateChanged')](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#onaudiosessionstatechanged20) to listen for AudioSession focus and state changes. To maintain state consistency between the app and the system and ensure a good user experience, you should listen for AudioSession focus state events and respond accordingly when the focus changes.

[on('audioSessionStateChanged')](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#onaudiosessionstatechanged20) includes the information of [AudioSession deactivation events](#audiosession-deactivation-event). When [using an audio session to request a focus strategy](#using-an-audio-session-to-request-a-focus-strategy), you do not need to additionally listen for audio session deactivation events (AudioSessionDeactivatedEvent).

> **NOTE**
>
> If the app also registers focus event listening for AudioRenderer, note the following two points:
> - The app receives both AudioSession focus state change callbacks and AudioRenderer focus change callbacks ([InterruptEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#interruptevent9)). Handle these callbacks as needed.
> - When the AudioSession focus changes from paused to resumed, the system sends a focus resume event only to the AudioSession, not to the AudioRenderer. To resume playback in this case, you must perform the following operations in order:
>    1. Call [setAudioSessionScene](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setaudiosessionscene20) to set the corresponding audio session scene.
>    2. Call [activateAudioSession](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#activateaudiosession12) to activate the AudioSession.
>    3. Call [start](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#start8) to resume playback.

### How to Develop

1. Specify an audio session scene (AudioSessionScene) and strategy (AudioSessionStrategy) and activate the audio session.

   The app requests focus through AudioSession. First, call [setAudioSessionScene](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setaudiosessionscene20) to set the scene parameters, and then call [activateAudioSession](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#activateaudiosession12) to activate the AudioSession. When the AudioSession is activated, the system requests the corresponding audio focus based on the audio session scene selected by the app.

   > **NOTE**
   >
   > - When the AudioSession is activated, the system requests the corresponding audio focus based on the audio session scene selected by the app. Subsequent playback streams started by the app through AudioRenderer will no longer request audio focus.
   > - If the app already has a running audio playback stream when activating the AudioSession, the system releases the focus held by that playback stream and the AudioSession manages it uniformly.

   <!-- @[activate_audio_session_v2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   import { audio } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   // ...
   
     // The app sets an appropriate audio session scenario based on its business scenario. When AudioSession is activated, the system requests the corresponding audio focus based on the audio session scenario selected by the app.
     audioSessionManager.setAudioSessionScene(audio.AudioSessionScene.AUDIO_SESSION_SCENE_MEDIA);
     // ...
   
     // Set the audio session strategy.
     let strategy: audio.AudioSessionStrategy = {
       concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_MIX_WITH_OTHERS
     };
   
     // Activate AudioSession.
     audioSessionManager.activateAudioSession(strategy).then(() => {
       console.info('Succeeded in activating audio session.');
       // ...
     }).catch((err: BusinessError) => {
       console.error(`Failed to activate audio session. Code: ${err.code}, message: ${err.message}`);
       // ...
     });
   ```

2. Check whether the audio session is activated (optional).

   You can call [isAudioSessionActivated](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#isaudiosessionactivated12) to check whether the audio session of the current app is activated.

   <!-- @[is_audio_session_activated](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // Query whether the audio session is activated.
   let isActivated = audioSessionManager.isAudioSessionActivated();
   ```

3. Listen for AudioSession focus state change events.

   You can call [on('audioSessionStateChanged')](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#onaudiosessionstatechanged20) to listen for AudioSession focus and state changes.

   <!-- @[on_audio_session_state_changed](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->  

   ``` TypeScript
   import { audio } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   // ...
   
     // Listen for AudioSession focus and state change events.
     let audioSessionStateChangedCallback = (audioSessionStateChangedEvent: audio.AudioSessionStateChangedEvent) => {
       // ...
       console.info(`hint of audioSessionStateChanged: ${audioSessionStateChangedEvent.stateChangeHint} `);
   
       switch (audioSessionStateChangedEvent.stateChangeHint) {
         case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_PAUSE:
           // This branch indicates that the system has paused the audio stream. The app must switch to the audio paused state.
           // Temporary focus loss: AudioSession is deactivated and releases focus, and all audio streams of the app are stopped. Therefore, after the app receives the Resume callback, it needs to reactivate AudioSession and resume the audio streams that need to continue playing.
           break;
         case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_RESUME:
           // This branch indicates that the system has lifted the pause on AudioSession focus.
           break;
         case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_STOP:
           // This branch indicates that the system has stopped the audio stream (permanent focus loss). To maintain state consistency, the app must switch to the audio paused state.
           // Permanent focus loss: AudioSession is deactivated and releases focus, and all audio streams of the app are stopped. No further audio focus events will be received, and resuming playback requires user initiation.
           break;
         case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_TIME_OUT_STOP:
           // This branch indicates that the system has stopped AudioSession (permanent focus loss) due to prolonged inactivity of audio streams. The app must switch to the audio stopped state.
           // Permanent focus loss: No further audio focus events will be received, and resuming playback requires user initiation.
           break;
         case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_DUCK:
           // This branch indicates that the system has reduced the volume of all playback audio streams of the app (to 20% of normal volume by default).
           break;
         case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_UNDUCK:
           // This branch indicates that the system has restored the volume of all playback audio streams of the app to normal.
         case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_MUTE_SUGGESTION:
           // This branch indicates that another app has started playing non-mixable audio. The system may decide whether to mute.
           break;
         case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_UNMUTE_SUGGESTION:
           // This branch indicates that the non-mixable audio playback of another app has ended. The system may decide whether to unmute.
           break;
         case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_MUTE:
           // This branch indicates that the system has muted all playback audio streams of the app.
           break;
         case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_UNMUTE:
           // This branch indicates that the system has unmuted all playback audio streams of the app.
           break;           
         default:
           break;
       }
     };

     audioSessionManager.on('audioSessionStateChanged', audioSessionStateChangedCallback);
   ```

4. Deactivate the audio session.

   You can call [deactivateAudioSession](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#deactivateaudiosession12) to deactivate the audio session of the current app.

   > **NOTE**
   >
   > When the AudioSession is deactivated, the system releases the focus requested by the AudioSession and stops all audio streams being played by the app.

   <!-- @[deactivate_audio_session_v2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->  

   ``` TypeScript
   import { BusinessError } from '@kit.BasicServicesKit';
   // ...
   
     // Deactivate AudioSession, that is, release the focus and deactivate all audio streams being played by the app.
     audioSessionManager.deactivateAudioSession().then(() => {
       console.info('Succeeded in deactivating audio session.');
       // ...
     }).catch((err: BusinessError) => {
       console.error(`Failed to deactivate audio session. Code: ${err.code}, message: ${err.message}`);
       // ...
     });
   ```

### Sample

The following shows the sample code for requesting a focus strategy using AudioSession.

<!-- @[audio_session_v2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

  // The app sets an audio session scenario suitable for its business needs. When AudioSession is activated, the system requests the corresponding audio focus based on the audio session scenario selected by the app.
  audioSessionManager.setAudioSessionScene(audio.AudioSessionScene.AUDIO_SESSION_SCENE_MEDIA);
  // ...

  // Set the audio session policy.
  let strategy: audio.AudioSessionStrategy = {
    concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_MIX_WITH_OTHERS
  };

  // Activate AudioSession.
  audioSessionManager.activateAudioSession(strategy).then(() => {
    console.info('Succeeded in activating audio session.');
    // ...
  }).catch((err: BusinessError) => {
    console.error(`Failed to activate audio session. Code: ${err.code}, message: ${err.message}`);
    // ...
  });

  // Listen for AudioSession focus and state change events.
  let audioSessionStateChangedCallback = (audioSessionStateChangedEvent: audio.AudioSessionStateChangedEvent) => {
    // ...
    console.info(`hint of audioSessionStateChanged: ${audioSessionStateChangedEvent.stateChangeHint} `);

    switch (audioSessionStateChangedEvent.stateChangeHint) {
      case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_PAUSE:
        // This branch indicates that the system has paused the audio stream. The app must switch to the audio paused state.
        // Temporary focus loss: AudioSession is deactivated and releases focus, and all audio streams of the app are stopped. Therefore, after the app receives the Resume callback, it needs to reactivate AudioSession and resume the audio streams that need to continue playing.
        break;
      case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_RESUME:
        // This branch indicates that the system has lifted the pause on AudioSession focus.
        break;
      case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_STOP:
        // This branch indicates that the system has stopped the audio stream (permanent focus loss). To maintain state consistency, the app must switch to the audio paused state.
        // Permanent focus loss: AudioSession is deactivated and releases focus, and all audio streams of the app are stopped. No further audio focus events will be received, and playback can only be resumed when triggered by the user.
        break;
      case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_TIME_OUT_STOP:
        // This branch indicates that the system has stopped AudioSession (permanent focus loss) due to prolonged inactivity of audio stream playback. The app must switch to the audio stopped state.
        // Permanent focus loss: No further audio focus events will be received, and playback can only be resumed when triggered by the user.
        break;
      case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_DUCK:
        // This branch indicates that the system has reduced the volume of all playback audio streams of the app (to 20% of the normal volume by default).
        break;
      case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_UNDUCK:
        // This branch indicates that the system has restored the volume of all playback audio streams of the app to normal.
      case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_MUTE_SUGGESTION:
        // This branch indicates that another app has started playing non-mixable audio. The system may decide whether to mute at its own discretion.
        break;
      case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_UNMUTE_SUGGESTION:
        // This branch indicates that the non-mixable audio playback of another app has ended. The system may decide whether to unmute at its own discretion.
        break;
      case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_MUTE:
        // This branch indicates that the system has muted all playback audio streams of the app.
        break;
      case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_UNMUTE:
        // This branch indicates that the system has unmuted all playback audio streams of the app.
        break;        
      default:
        break;
    }
  };

  audioSessionManager.on('audioSessionStateChanged', audioSessionStateChangedCallback);

  // Query whether the audio session is activated.
  let isActivated = audioSessionManager.isAudioSessionActivated();

  if (isActivated) {
    // After the audio session is activated, the app can perform normal audio operations such as play, pause, stop, and release here.
    // Based on actual business needs, the app can start multiple AudioRenderer audio playback streams. The audio playback streams started here no longer hold focus individually; they are managed by AudioSession.
    // If multiple audio streams are playing simultaneously, pay special attention to the timing of AudioSession deactivation (deactivating AudioSession also releases all audio playback streams of the app).
  }
  // ...

  // When the service ends, stop listening for AudioSession focus and state change events.
  audioSessionManager.off('audioSessionStateChanged');
  // ...

  // Deactivate AudioSession, which releases focus and stops all audio streams currently being played by the app.
  audioSessionManager.deactivateAudioSession().then(() => {
    console.info('Succeeded in deactivating audio session.');
    // ...
  }).catch((err: BusinessError) => {
    console.error(`Failed to deactivate audio session. Code: ${err.code}, message: ${err.message}`);
    // ...
  });
```

## Enabling Mute Suggestion Notifications for Mixed Playback

Starting from API version 23, when the current application plays audio in the **CONCURRENCY_MIX_WITH_OTHERS** concurrency mode, if audio from other applications is playing simultaneously, the audio from both will be mixed. In certain scenarios (such as games or broadcasts), applications can enable mute suggestion notifications to enhance user experience.

After enabling mute suggestion notifications, if other applications play audio that cannot be played concurrently with the current application while the current application is playing audio, the current application will receive a mute suggestion notification. The current application can either choose to take no action (allowing concurrent playback with other applications) or mute itself to let other applications play audio alone.

To enable mute suggestion notifications for mixed playback, you need to first call [setAudioSessionScene](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setaudiosessionscene20) to set the scene parameters, call [enableMuteSuggestionWhenMixWithOthers](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#enablemutesuggestionwhenmixwithothers23) to enable the feature, subscribe to audio session state change events [AudioSessionStateChangedEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiosessionstatechangedevent20), and finally call [activateAudioSession](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#activateaudiosession12) to activate the AudioSession. The prerequisite for enabling mute suggestion notifications is that the [AudioConcurrencyMode](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audioconcurrencymode12) mode must be CONCURRENCY_MIX_WITH_OTHERS.

<!-- @[enable_mute_suggestion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

  // The app sets an appropriate audio session scenario based on the service scenario. When AudioSession is activated, the system requests the corresponding audio focus based on the audio session scenario selected by the app.
  audioSessionManager.setAudioSessionScene(audio.AudioSessionScene.AUDIO_SESSION_SCENE_MEDIA);

  // This API takes effect only when called before the audio session is activated.
  audioSessionManager.enableMuteSuggestionWhenMixWithOthers(true);

  // Set the audio session policy.
  let strategy: audio.AudioSessionStrategy = {
    concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_MIX_WITH_OTHERS
  };

  // Activate AudioSession.
  audioSessionManager.activateAudioSession(strategy).then(() => {
    console.info('Succeeded in activating audio session.');
    // ...
  }).catch((err: BusinessError) => {
    console.error(`Failed to activate audio session. Code: ${err.code}, message: ${err.message}`);
    // ...
  });
```

## Setting Audio Session Behavior

Starting from API version 24, you can call [setAudioSessionBehavior](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setaudiosessionbehavior24) to set audio session behavior parameters for a better audio focus experience in specific scenarios.

In a live streaming scenario, when another app starts an audio stream (such as using a keyboard for speech-to-text) that interrupts the live stream, the live stream's audio and video are paused, affecting the viewing experience. A live streaming app can set the [AudioSessionBehaviorFlags](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audiosessionbehaviorflags24).MUTE_WHEN_INTERRUPTED session behavior to keep the live stream playing in mute mode instead of pausing when interrupted, thereby avoiding video interruption.

If your app does not use audio session management, you can also set independent audio session behavior for a single audio stream. For playback streams, see [setIndependentAudioSessionStrategy](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#setindependentaudiosessionstrategy24). For recording streams, see [setIndependentAudioSessionStrategy](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#setindependentaudiosessionstrategy24).

<!-- @[set_session_behavior](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

  // The app sets an appropriate audio session scenario based on its service requirements. When AudioSession is activated, the system requests the corresponding audio focus based on the audio session scenario selected by the app.
  audioSessionManager.setAudioSessionScene(audio.AudioSessionScene.AUDIO_SESSION_SCENE_MEDIA);

  // Call this API before activating the audio session.
  // If this API is called while the audio session is active, you must reactivate the audio session for the changes to take effect.
  let behavior = audio.AudioSessionBehaviorFlags.MUTE_WHEN_INTERRUPTED;
  audioSessionManager.setAudioSessionBehavior(behavior);

  // Set the audio session policy.
  let strategy: audio.AudioSessionStrategy = {
    concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_PAUSE_OTHERS
  };

  // Activate the AudioSession.
  audioSessionManager.activateAudioSession(strategy).then(() => {
    console.info('Succeeded in activating audio session.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to activate audio session. Code: ${err.code}, message: ${err.message}`);
  });
```