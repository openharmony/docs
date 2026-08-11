# Using AudioHaptic for Audio-Haptic Playback (ArkTS)

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwall-->
<!--Designer: @huyue57-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=cfecea1c41187dad0c66b395f9088cd7a30d17e5 translatedAt=2026-08-06T01:53:07.986Z pushedAt=2026-08-06T09:05:39.359Z -->

Audio-haptic coordinated playback is supported from API version 11.

**AudioHaptic** provides APIs for audio-haptic playback and management. It applies to scenarios where haptic feedback needs to be initiated synchronously during audio playback, for example, when there are incoming calls or messages or users are typing.

## Development Guidelines

Developing audio-haptic coordinated playback with AudioHaptic involves management of audio and haptic sources, configuration of an audio latency mode and audio stream usage, and creation and management of an audio-haptic player. This document walks through the process of audio-haptic coordinated playback to demonstrate how to develop this feature with AudioHaptic. It is recommended to read this document together with the [audioHaptic](../../reference/apis-audio-kit/js-apis-audioHaptic.md) API reference.

### Requesting Permissions

If the audio-haptic player needs to trigger vibration, check whether the application has the permission **ohos.permission.VIBRATE**.

1. Declare the vibration permission by following the instructions in [Declaring Permissions](../../security/AccessToken/declare-permissions.md).

2. Since this permission is a user-granted permission, a user authorization dialog must pop up for the user to grant the permission during use; otherwise, the permission cannot be obtained. For code development, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

### How to Develop

1. Obtain an **AudioHapticManager** instance, and register the audio and haptic sources. A single app can register up to 128 sources at the same time. For details about the audio and haptic source formats supported by the player, see the [registerSource](../../reference/apis-audio-kit/js-apis-audioHaptic.md#registersource) documentation. You can register sources using the following two methods:

   - Method 1: Use the [registerSource](../../reference/apis-audio-kit/js-apis-audioHaptic.md#registersource) API to register sources by file URI.

   - Method 2 (recommended): Starting from API version 20, you can use the [registerSourceFromFd](../../reference/apis-audio-kit/js-apis-audioHaptic.md#registersourcefromfd20) API to register sources by file descriptor.

   <!-- @[get_haptic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleJS/entry/src/main/ets/pages/haptic.ets) -->

   ``` TypeScript
   import { audio, audioHaptic } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   
   let audioHapticManagerInstance: audioHaptic.AudioHapticManager = audioHaptic.getAudioHapticManager();

   // ...
     // Method 1: Use registerSource to register sources.
     let audioUri = 'data/audioTest.wav'; // This is only an example. In actual use, replace the file with the URI of the app's target audio resource.
     let hapticUri = 'data/hapticTest.json'; // This is only an example. In actual use, replace the file with the URI of the app's target haptic resource.
     let idForUri = 0;
   
     audioHapticManagerInstance.registerSource(audioUri, hapticUri).then((value: number) => {
       console.info(`Succeeded in registering source, sourceId is ${value}.`);
       idForUri = value;
       // ...
     }).catch((err: BusinessError) => {
       console.error(`Failed to register source. Code: ${err.code}, message: ${err.message}`);
       // ...
     });
     // ...
     // Method 2: Use the registerSourceFromFd API to register the source.
     // This is only an example. In actual use, replace the file with the corresponding file in the app's rawfile directory.
     let audioFile = context.resourceManager.getRawFdSync('audioTest.ogg');
     let audioFd: audioHaptic.AudioHapticFileDescriptor = {
       fd: audioFile.fd,
       offset: audioFile.offset,
       length: audioFile.length,
     };
     // This is only an example. In actual use, replace the file with the corresponding file in the app's rawfile directory.
     let hapticFile = context.resourceManager.getRawFdSync('hapticTest.json');
     let hapticFd: audioHaptic.AudioHapticFileDescriptor = {
       fd: hapticFile.fd,
       offset: hapticFile.offset,
       length: hapticFile.length,
     };
     audioHapticManagerInstance.registerSourceFromFd(audioFd, hapticFd).then((value: number) => {
       console.info(`Succeeded in registering source from fd, sourceId is ${value}.`);
       idForFd = value;
       // ...
     }).catch((err: BusinessError) => {
       console.error(`Failed to register source from fd. Code: ${err.code}, message: ${err.message}`);
       // ...
     });
   ```

2. Set the audio latency mode and audio stream usage for the audio-haptic player. For details about their purposes and types, see the [setAudioLatencyMode](../../reference/apis-audio-kit/js-apis-audioHaptic.md#setaudiolatencymode) and [setStreamUsage](../../reference/apis-audio-kit/js-apis-audioHaptic.md#setstreamusage) API documentation. It is recommended to use the FAST mode for short notification sounds such as SMS and notification tones, and the NORMAL mode for long ringtones such as incoming call ringtones.

   <!-- @[set_hapticparam](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleJS/entry/src/main/ets/pages/haptic.ets) -->

   ``` TypeScript
   let latencyMode: audioHaptic.AudioLatencyMode = audioHaptic.AudioLatencyMode.AUDIO_LATENCY_MODE_NORMAL;
   audioHapticManagerInstance.setAudioLatencyMode(idForFd, latencyMode);

   let usage: audio.StreamUsage = audio.StreamUsage.STREAM_USAGE_NOTIFICATION;
   audioHapticManagerInstance.setStreamUsage(idForFd, usage);
   ```

3. Call the [createPlayer](../../reference/apis-audio-kit/js-apis-audioHaptic.md#createplayer) method to create an **AudioHapticPlayer** instance. The **options** parameter controls whether to mute the audio and whether to disable vibration. When this parameter is empty, the player enables audio and allows vibration by default.

   <!-- @[create_haptic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleJS/entry/src/main/ets/pages/haptic.ets) -->

   ``` TypeScript
   let options: audioHaptic.AudioHapticPlayerOptions = {muteAudio: false, muteHaptics: false};
   let audioHapticPlayer: audioHaptic.AudioHapticPlayer | undefined = undefined;
   // ...
       audioHapticManagerInstance.createPlayer(idForFd, options).then((value: audioHaptic.AudioHapticPlayer) => {
         console.info('Succeeded in creating player.');
         audioHapticPlayer = value;
         // ...
       }).catch((err: BusinessError) => {
         console.error(`Failed to create player. Code: ${err.code}, message: ${err.message}`);
         // ...
       });
   ```

4. Call the [start](../../reference/apis-audio-kit/js-apis-audioHaptic.md#start) method to start audio playback and synchronously start vibration.

   <!-- @[haptic_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleJS/entry/src/main/ets/pages/haptic.ets) -->

   ``` TypeScript
   audioHapticPlayer.start().then(() => {
     console.info('Succeeded in starting audio haptic player.');
     // ...
   }).catch((err: BusinessError) => {
     console.error(`Failed to start audio haptic player. Code: ${err.code}, message: ${err.message}`);
     // ...
   });
   ```

5. Call the [stop](../../reference/apis-audio-kit/js-apis-audioHaptic.md#stop) method to stop audio playback and synchronously stop vibration.

   <!-- @[haptic_stop](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleJS/entry/src/main/ets/pages/haptic.ets) -->

   ``` TypeScript
   audioHapticPlayer.stop().then(() => {
     console.info('Succeeded in stopping audio haptic player.');
     // ...
   }).catch((err: BusinessError) => {
     console.error(`Failed to stop audio haptic player. Code: ${err.code}, message: ${err.message}`);
     // ...
   });
   ```

6. After using the audio-haptic player, the app must call the [release](../../reference/apis-audio-kit/js-apis-audioHaptic.md#release) method to release the **AudioHapticPlayer** instance. This prevents the player instance from occupying system audio-haptic resources for an extended period, which can cause severe memory and system resource leaks and subsequently prevent the app from creating new audio-haptic players.

   <!-- @[haptic_release](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleJS/entry/src/main/ets/pages/haptic.ets) -->

   ``` TypeScript
   audioHapticPlayer.release().then(() => {
     console.info('Succeeded in releasing audio haptic player.');
     // ...
   }).catch((err: BusinessError) => {
     console.error(`Failed to release audio haptic player. Code: ${err.code}, message: ${err.message}`);
     // ...
   });
   ```

7. When the sources are no longer in use, the app must call the [unregisterSource](../../reference/apis-audio-kit/js-apis-audioHaptic.md#unregistersource) method to unregister the registered audio and haptic sources. If invalid sources accumulate without being unregistered over a long period, the 128-source registration quota for the app will be quickly exhausted, directly causing all subsequent audio-haptic source registrations to fail, preventing player creation, and rendering the audio-haptic coordinated playback feature unavailable. This also leads to persistent resource leaks.

   <!-- @[haptic_unregist](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleJS/entry/src/main/ets/pages/haptic.ets) -->

   ``` TypeScript
   audioHapticManagerInstance.unregisterSource(idForFd).then(() => {
     console.info('Succeeded in unregistering source.');
     // ...
   }).catch((err: BusinessError) => {
     console.error(`Failed to unregister source. Code: ${err.code}, message: ${err.message}`);
     // ...
   });
   ```