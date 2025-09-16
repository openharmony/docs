# Using AudioSession to Manage Audio Focus (ArkTS)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

In the scenario where multiple audio streams are concurrently playing, the system has preset a [default audio focus strategy](audio-playback-concurrency.md#audio-focus-strategy) for unified audio focus management of all streams (including playback and recording).

An application can use an audio session provided by the audio session manager to actively manage the audio focus. Specifically, it can customize an audio focus strategy and determine the timing for releasing the audio focus, thereby meeting its specific service needs.

This topic describes the usage and precautions of the ArkTS APIs related to the audio session. For more information about the audio focus and audio session, see [Introduction to Audio Focus and Audio Session](audio-playback-concurrency.md).

## Obtaining an Audio Session Manager

Create an AudioSessionManager instance. Before using any APIs of AudioSessionManager, you must call [getSessionManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioManager.md#getsessionmanager12) to obtain an AudioSessionManager instance.

  ```ts
  import { audio } from '@kit.AudioKit';

  let audioManager = audio.getAudioManager();
  let audioSessionManager: audio.AudioSessionManager = audioManager.getSessionManager();
  ```

## Activating an Audio Session

Call [AudioSessionManager.activateAudioSession](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#activateaudiosession12) to activate an audio session.

During the activation, specify an [audio session strategy](audio-playback-concurrency.md#audio-session-strategy). The strategy contains the **concurrencyMode** parameter, which is of the [AudioConcurrencyMode](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audioconcurrencymode12) type and is used to declare the audio concurrency strategy.

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  let strategy: audio.AudioSessionStrategy = {
    concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_MIX_WITH_OTHERS
  };
  
  audioSessionManager.activateAudioSession(strategy).then(() => {
    console.info('Succeeded in doing activateAudioSession.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to activateAudioSession. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## Checking Whether an Audio Session Is Activated

Call [isAudioSessionActivated](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#isaudiosessionactivated12) to check whether an audio session is activated.

  ```ts
  let isActivated = audioSessionManager.isAudioSessionActivated();
  ```

## Deactivating an Audio Session

Call [deactivateAudioSession](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#deactivateaudiosession12) to deactivate an audio session.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  
  audioSessionManager.deactivateAudioSession().then(() => {
    console.info('Succeeded in doing deactivateAudioSession.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to deactivateAudioSession. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## Listening for Audio Session Deactivation Events

Call [on('audioSessionDeactivated')](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#onaudiosessiondeactivated12) to listen for the [AudioSessionDeactivatedEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiosessiondeactivatedevent12) event.

When an audio session is deactivated (not proactively), the application receives [AudioSessionDeactivatedEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiosessiondeactivatedevent12), which contains [AudioSessionDeactivatedReason](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audiosessiondeactivatedreason12).

Upon this event, the application can perform operations based on service requirements, for example, releasing resources or reactivating the audio session.

  ```ts
  import { audio } from '@kit.AudioKit';

  audioSessionManager.on('audioSessionDeactivated', (audioSessionDeactivatedEvent: audio.AudioSessionDeactivatedEvent) => {
    console.info(`reason of audioSessionDeactivated: ${audioSessionDeactivatedEvent.reason} `);
  });
  ```

## Canceling Listening for Audio Session Deactivation Events

Call [off('audioSessionDeactivated')](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#offaudiosessiondeactivated12) to cancel listening for **AudioSessionDeactivatedEvent**.

  ```ts
  audioSessionManager.off('audioSessionDeactivated');
  ```


**Below is a comprehensive example of creating, activating, and listening for an audio session:**

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let audioManager = audio.getAudioManager();
  // Create an AudioSessionManager instance.
  let audioSessionManager: audio.AudioSessionManager = audioManager.getSessionManager();
  // Set the audio concurrency mode.
  let strategy: audio.AudioSessionStrategy = {
    concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_MIX_WITH_OTHERS
  };

  // Activate an audio session.
  audioSessionManager.activateAudioSession(strategy).then(() => {
    console.info('Succeeded in doing activateAudioSession.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to activateAudioSession. Code: ${err.code}, message: ${err.message}`);
  });

  // Check whether the audio session is activated.
  let isActivated = audioSessionManager.isAudioSessionActivated();

  // Listen for audio session deactivation events.
  audioSessionManager.on('audioSessionDeactivated', (audioSessionDeactivatedEvent: audio.AudioSessionDeactivatedEvent) => {
    console.info(`reason of audioSessionDeactivated: ${audioSessionDeactivatedEvent.reason} `);
  });

  // After the audio session is activated, the application can perform operations such as playing, pausing, stopping, and releasing audio streams.

  // Deactivate the audio session.
  audioSessionManager.deactivateAudioSession().then(() => {
    console.info('Succeeded in doing deactivateAudioSession.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to deactivateAudioSession. Code: ${err.code}, message: ${err.message}`);
  });

  // Cancel listening for audio session deactivation events.
  audioSessionManager.off('audioSessionDeactivated');
  ```

## Requesting Focus by Setting Audio Session Scene Parameters
The application requests focus using an audio session. Call [setAudioSessionScene](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setaudiosessionscene20) to set the scene parameters, and then call [activateAudioSession](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#activateaudiosession12) to activate the audio session.
  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  audioSessionManager.setAudioSessionScene(audio.AudioSessionScene.AUDIO_SESSION_SCENE_MEDIA);

  let strategy: audio.AudioSessionStrategy = {
    concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_MIX_WITH_OTHERS
  };

  audioSessionManager.activateAudioSession(strategy).then(() => {
    console.info('activateAudioSession SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`ERROR: ${err}`);
  });
  ```

## Listening for Audio Session Focus State Change events
Listen for audio session focus state changes through [AudioSessionStateChangedEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiosessionstatechangedevent20).

**Below is a comprehensive example of requesting focus for an audio session and listening for focus change events:**

```ts
import { audio } from '@kit.AudioKit';  // Import the audio module.
import { BusinessError } from '@kit.BasicServicesKit'; // Import BusinessError.

let audioSessionStateChangedCallback = (audioSessionStateChangedEvent: audio.AudioSessionStateChangedEvent) => {
  console.info(`hint of audioSessionStateChanged: ${audioSessionStateChangedEvent.stateChangeHint} `);

  switch (audioSessionStateChangedEvent.stateChangeHint) {
  case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_PAUSE:
    // The system has paused the audio stream. The application should switch to the audio paused state.
    // Temporarily losing focus: When other audio streams release focus, the application will receive a resume event and can resume playback.
    break;
  case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_RESUME:
    // The system has resumed the audio session.
    break;
  case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_STOP:
    // The system has stopped the audio stream (focus is permanently lost). To ensure state consistency, the application should switch to the audio paused state.
    // Permanently losing focus: No audio focus event will be received. The user must manually trigger the operation to resume playback.
    break;
  case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_TIME_OUT_STOP:
    // The system has stopped the audio session (permanently losing focus) due to inactivity. The application should switch to the audio paused state.
    // Permanently losing focus: No audio focus event will be received. The user must manually trigger the operation to resume playback.
    break;
  case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_DUCK:
    // The system has ducked the volume down (to 20% of the normal volume by default).
    break;
  case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_UNDUCK:
    // The system has restored the audio volume to normal.
    break;
  default:
    break;
  }
};

let audioManager = audio.getAudioManager();
let audioSessionManager = audioManager.getSessionManager();

audioSessionManager.on('audioSessionStateChanged', audioSessionStateChangedCallback);

// In this example, AUDIO_SESSION_SCENE_MEDIA is selected. You can change the session scene as needed.
audioSessionManager.setAudioSessionScene(audio.AudioSessionScene.AUDIO_SESSION_SCENE_MEDIA);

// In this example, CONCURRENCY_MIX_WITH_OTHERS is selected. You can change the strategy as needed.
let strategy: audio.AudioSessionStrategy = {
  concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_MIX_WITH_OTHERS
};

// Activate the audio session to gain focus.
audioSessionManager.activateAudioSession(strategy).then(() => {
  console.info('activateAudioSession SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});

// Start multiple audio renderers or other audio playback as needed.

// Deactivate the audio session to release focus.
audioSessionManager.deactivateAudioSession().then(() => {
  console.info('deactivateAudioSession SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});

audioSessionManager.off('audioSessionStateChanged', audioSessionStateChangedCallback);

```
