# Using AudioHaptic for Audio-Haptic Playback

AudioHaptic<sup>11+</sup> provides APIs for audio-haptic playback and management. It applies to scenarios where haptic feedback needs to be initiated synchronously during audio playback, for example, when there are incoming calls or messages or users are typing.

## Development Guidelines

The entire process of audio-haptic development involves management of audio and haptic sources, configuration of an audio latency mode and audio stream usage, and creation and management of an audio-haptic player. This topic uses the process of one-time audio-haptic playback as an example to describe how to use **AudioHaptic**. Before the development, read [AudioHaptic](../../reference/apis-audio-kit/js-apis-audioHaptic.md#audiohapticmanager) for better understanding.

### Requesting Permissions

If the audio-haptic player needs to trigger vibration, check whether the application has the permission **ohos.permission.VIBRATE**.

1. [Declare the permission](../../security/AccessToken/declare-permissions.md).
2. [Request user authorization](../../security/AccessToken/request-user-authorization.md).

### How to Develop

1. Obtain an **AudioHapticManager** instance, and register the audio and haptic sources. For details about the sources supported, see [AudioHapticManager](../../reference/apis-audio-kit/js-apis-audioHaptic.md#audiohapticmanager).

   ```ts
   import { audio, audioHaptic } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   let audioHapticManagerInstance: audioHaptic.AudioHapticManager = audioHaptic.getAudioHapticManager();

   let audioUri = 'data/audioTest.wav'; // Change it to the URI of the target audio source.
   let hapticUri = 'data/hapticTest.json'; // Change it to the URI of the target haptic source.
   let id = 0;

   audioHapticManagerInstance.registerSource(audioUri, hapticUri).then((value: number) => {
     console.info(`Promise returned to indicate that the source id of the registered source ${value}.`);
     id = value;
   }).catch ((err: BusinessError) => {
     console.error(`Failed to register source ${err}`);
   });
   ```

2. Set the parameters of an audio-haptic player. For details, see [AudioHapticManager](../../reference/apis-audio-kit/js-apis-audioHaptic.md#audiohapticmanager).

   ```ts
   let latencyMode: audioHaptic.AudioLatencyMode = audioHaptic.AudioLatencyMode.AUDIO_LATENCY_MODE_FAST;
   audioHapticManagerInstance.setAudioLatencyMode(id, latencyMode);

   let usage: audio.StreamUsage = audio.StreamUsage.STREAM_USAGE_NOTIFICATION;
   audioHapticManagerInstance.setStreamUsage(id, usage);
   ```

3. Create an **AudioHapticPlayer** instance.

   ```ts
   let options: audioHaptic.AudioHapticPlayerOptions = {muteAudio: false, muteHaptics: false};
   let audioHapticPlayer: audioHaptic.AudioHapticPlayer | undefined = undefined;

   audioHapticManagerInstance.createPlayer(id, options).then((value: audioHaptic.AudioHapticPlayer) => {
     console.info(`Promise returned to indicate that the audio haptic player instance.`);
     audioHapticPlayer = value;
   }).catch ((err: BusinessError) => {
     console.error(`Failed to create player ${err}`);
   });
   console.info(`Create the audio haptic player successfully.`);
   ```

4. Call **start()** to start the audio-haptic player.

   ```ts
   audioHapticPlayer.start().then(() => {
     console.info(`Promise returned to indicate that start playing successfully.`);
   }).catch ((err: BusinessError) => {
     console.error(`Failed to start playing. ${err}`);
   });
   ```

5. Call **stop()** to stop the audio-haptic player.

   ```ts
   audioHapticPlayer.stop().then(() => {
     console.info(`Promise returned to indicate that stop playing successfully.`);
   }).catch ((err: BusinessError) => {
     console.error(`Failed to stop playing. ${err}`);
   });
   ```

6. Release the **AudioHapticPlayer** instance.

   ```ts
   audioHapticPlayer.release().then(() => {
     console.info(`Promise returned to indicate that release the audio haptic player successfully.`);
   }).catch ((err: BusinessError) => {
     console.error(`Failed to release the audio haptic player. ${err}`);
   });
   ```

7. Unregister the audio and haptic sources.

   ```ts
   audioHapticManagerInstance.unregisterSource(id).then(() => {
     console.info(`Promise returned to indicate that unregister source successfully`);
   }).catch ((err: BusinessError) => {
     console.error(`Failed to unregister source ${err}`);
   });
   ```
