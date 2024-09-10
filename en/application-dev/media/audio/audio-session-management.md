# Extended Audio Concurrency Strategy (ArkTS)

The audio system offers a [default concurrency strategy](audio-playback-concurrency.md) based on the audio stream type. If the default concurrency strategy cannot meet your service requirements, you can use an audio session to customize a strategy. The audio session is an extension of the default audio concurrency strategy. Example scenarios are as follows:

- When an application that continuously plays a short sound does not want to be paused when running in the background, it can obtain an audio session to ensure a seamless integration of the entire playback process.

- If the default concurrency strategy does not meet service requirements, an application can request an audio session and specify a strategy.

The following figure shows the audio session process.

![AudioSession status change](figures/audiosession-status-change.png)

## Audio Session Strategy

In scenarios where multiple audio streams are active, an application can proactively establish an audio session strategy to manage how other applications handle audio streams once it has acquired audio focus.

### Audio Concurrency Mode

When the default concurrency strategy cannot meet service requirements, you can configure the audio concurrency mode.

Four audio concurrency modes are provided. 

- **CONCURRENCY_DEFAULT**: default concurrency strategy, which is used no audio session is used. For details, see [Processing Audio Interruption Events](audio-playback-concurrency.md)

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

Two audio session deactivation reasons ([AudioSessionDeactivatedReason](../../reference/apis-audio-kit/js-apis-audio.md#audiosessiondeactivatedreason12)) are preset:

- **DEACTIVATED_LOWER_PRIORITY**: The focus of the application that is playing audio streams is forcibly cleared.

- **DEACTIVATED_TIME_OUT**: The default duration is reached after the application creates an audio session or stops audio playback. In this case, the volume of the application that was lowered in volume by this session will be restored to its original level, and the application that was paused by this session will receive a stop playback focus event.

## Obtaining an Audio Session Manager

Create an **AudioSessionManager** instance. Before using any APIs of **AudioSessionManager**, you must call [getSessionManager](../../reference/apis-audio-kit/js-apis-audio.md#getsessionmanager12) to obtain an **AudioSessionManager** instance.

  ```ts
  import { audio } from '@kit.AudioKit';

  let audioSessionManager: audio.AudioSessionManager = audioManager.getSessionManager();
  ```

## Activating an Audio Session

Call [activateAudioSession](../../reference/apis-audio-kit/js-apis-audio.md#activateaudiosession12) to activate an audio session.

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  let strategy: audio.AudioSessionStrategy = {
    concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_MIX_WITH_OTHERS
  }
  
  audioSessionManager.activateAudioSession(strategy).then(() => {
    console.info('activateAudioSession SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`ERROR: ${err}`);
  });
  ```

## Deactivating an Audio Session

Call [deactivateAudioSession](../../reference/apis-audio-kit/js-apis-audio.md#deactivateaudiosession12) to deactivate an audio session when it is no longer needed.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  
  audioSessionManager.deactivateAudioSession().then(() => {
    console.info('deactivateAudioSession SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`ERROR: ${err}`);
  });
  ```

## Checking Whether an Audio Session Is Activated

Call [isAudioSessionActivated](../../reference/apis-audio-kit/js-apis-audio.md#isaudiosessionactivated12) to check whether an audio session is activated.

  ```ts
  let isActivated = audioSessionManager.isAudioSessionActivated();
  ```

## Listening for Audio Session Deactivation Events

Call [on('audioSessionDeactivated')](../../reference/apis-audio-kit/js-apis-audio.md#onaudiosessiondeactivated12) to listen for audio session deactivation events and obtain the reason for the deactivation.

  ```ts
  import { audio } from '@kit.AudioKit';

  audioSessionManager.on('audioSessionDeactivated', (audioSessionDeactivatedEvent: audio.AudioSessionDeactivatedEvent) => {
    console.info(`VolumeType of stream: ${audioSessionDeactivatedEvent.reason} `);
  });
  ```

## Canceling Listening for Audio Session Deactivation Events

Call [off('audioSessionDeactivated')](../../reference/apis-audio-kit/js-apis-audio.md#offaudiosessiondeactivated12) to cancel listening for audio session deactivation events.

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
  }

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
    console.info(`VolumeType of stream: ${audioSessionDeactivatedEvent.reason} `);
  });

  // After the audio session is activated, the application can perform operations such as playing, pausing, stopping, and releasing audio streams.

  // Cancel listening for audio session deactivation events.
  audioSessionManager.off('audioSessionDeactivated');

  // Deactivate the audio session.
  audioSessionManager.deactivateAudioSession().then(() => {
    console.info('deactivateAudioSession SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`ERROR: ${err}`);
  });
  ```
