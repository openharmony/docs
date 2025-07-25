# Using AudioSession to Manage Audio Focus (ArkTS)

In the scenario where multiple audio streams are concurrently playing, the system has preset a [default audio focus strategy](audio-playback-concurrency.md#audio-focus-strategy) for unified audio focus management of all streams (including playback and recording).

An application can use an audio session provided by the audio session manager to actively manage the audio focus. Specifically, it can customize an audio focus strategy and determine the timing for releasing the audio focus, thereby meeting its specific service needs.

This topic describes the usage and precautions of the ArkTS APIs related to the audio session. For more information about the audio focus and audio session, see [Introduction to Audio Focus and Audio Session](audio-playback-concurrency.md).

## Obtaining an Audio Session Manager

Create an AudioSessionManager instance. Before using any APIs of AudioSessionManager, you must call [getSessionManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioManager.md#getsessionmanager12) to obtain an AudioSessionManager instance.

  ```ts
  import { audio } from '@kit.AudioKit';

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
    console.info('activateAudioSession SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`ERROR: ${err}`);
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
    console.info('deactivateAudioSession SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`ERROR: ${err}`);
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

## Sample Code

Refer to the sample code below to complete the process of creating, activating, and listening of an audio session.

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
    console.info('activateAudioSession SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`ERROR: ${err}`);
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
    console.info('deactivateAudioSession SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`ERROR: ${err}`);
  });

  // Cancel listening for audio session deactivation events.
  audioSessionManager.off('audioSessionDeactivated');
  ```
