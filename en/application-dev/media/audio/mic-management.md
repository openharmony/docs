# Managing Microphone Mute State

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zyy0412-->
<!--Designer: @weixin_41398971-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=3fe644941755c7ef785f22b59c73ecb8389cc6db translatedAt=2026-08-06T01:51:14.377Z pushedAt=2026-08-06T08:43:50.871Z -->

The microphone is used to record audio data. To deliver an optimal recording effect, you are advised to query the microphone state before starting recording and listen for state changes during recording.

If the user mutes the microphone during audio recording, the recording process is normal, the size of the recorded file increases with the recording duration, but the data volume written into the file is 0.

Volume adjustment is not supported during recording.

## How to Develop

The examples below are code snippets. You can obtain the [complete sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS) via the link at the bottom right of the sample code.

The **AudioVolumeGroupManager** class provides APIs for managing the microphone state. For details, see [AudioVolumeGroupManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioVolumeGroupManager.md).

1. Create an audioVolumeGroupManager object.

   <!-- @[create_AudioVolumeGroupManager](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/MacManager.ets) --> 

   ``` TypeScript
   import { audio } from '@kit.AudioKit';
   
   let audioVolumeGroupManager: audio.AudioVolumeGroupManager;
   // Create an audioVolumeGroupManager object.
   async function loadVolumeGroupManager(updateCallback?: (msg: string, isError: boolean) => void): Promise<void> {
     const groupid = audio.DEFAULT_VOLUME_GROUP_ID;
     audioVolumeGroupManager = await audio.getAudioManager().getVolumeManager().getVolumeGroupManager(groupid);
     console.info('audioVolumeGroupManager create success.');
     // ...
   }
   ```

2. Call [on('micStateChange')](../../reference/apis-audio-kit/arkts-apis-audio-AudioVolumeGroupManager.md#onmicstatechange9) to listen for microphone state changes. When the microphone mute state changes, the application will be notified of the change.

   Currently, when multiple [AudioManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioManager.md) instances are used in a single process, only the subscription of the last instance takes effect for this API, and subscriptions of other instances are overwritten (even if the last instance has no subscription). Therefore, you are advised to use a single AudioManager instance for development.

   <!-- @[mac_on](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/MacManager.ets) --> 

   ``` TypeScript
   // Listen for microphone state changes.
   async function on() {
     audioVolumeGroupManager.on('micStateChange', (micStateChange: audio.MicStateChangeEvent) => {
       console.info(`Current microphone status is: ${micStateChange.mute} `);
     });
   }
   ```

3. Call [isMicrophoneMute](../../reference/apis-audio-kit/arkts-apis-audio-AudioVolumeGroupManager.md#ismicrophonemute9) to check whether the microphone is muted. If the return value is **true**, the microphone is muted; otherwise, the microphone is not muted.

   <!-- @[is_MicrophoneMute](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/MacManager.ets) -->

   ``` TypeScript
   // Check whether the microphone is muted.
   async function isMicrophoneMute(updateCallback?: (msg: string, isError: boolean) => void): Promise<void> {
     await audioVolumeGroupManager.isMicrophoneMute().then((value: boolean) => {
       console.info(`isMicrophoneMute is: ${value}.`);
       // ...
     });
   }
   ```

   <!--Del-->

4. (For system applications only) Call [setMicMute](../../reference/apis-audio-kit/js-apis-audio-sys.md#setmicmute11) to mute or unmute the microphone. To mute the microphone, pass in **true**. To unmute the microphone, pass in **false**.

   ``` TypeScript
   // Mute the microphone, with true passed.
   async function setMicrophoneMuteTrue() {
     await audioVolumeGroupManager.setMicMute(true).then(() => {
       console.info('setMicrophoneMute to mute.');
     });
   }

   // Unmute the microphone, with false passed.
   async function setMicrophoneMuteFalse() {
     await audioVolumeGroupManager.setMicMute(false).then(() => {
       console.info('setMicrophoneMute to not mute.');
     });
   }
   ```

## Complete Sample Code

Refer to the sample code below to complete the process of muting and unmuting the microphone.

``` TypeScript
import { audio } from '@kit.AudioKit';

let audioVolumeGroupManager: audio.AudioVolumeGroupManager;

async function loadVolumeGroupManager() {
  const groupid = audio.DEFAULT_VOLUME_GROUP_ID;
  audioVolumeGroupManager = await audio.getAudioManager().getVolumeManager().getVolumeGroupManager(groupid);
  console.info('audioVolumeGroupManager------create-------success.');
}

// Listen for microphone state changes.
async function on() {
  await loadVolumeGroupManager();
  audioVolumeGroupManager.on('micStateChange', (micStateChange) => {
    console.info(`Current microphone status is: ${micStateChange.mute} `);
  });
}

// Check whether the microphone is muted.
async function isMicrophoneMute() {
  await audioVolumeGroupManager.isMicrophoneMute().then((value) => {
    console.info(`isMicrophoneMute is: ${value}.`);
  });
}

// Mute the microphone.
async function setMicrophoneMuteTrue() {
  await loadVolumeGroupManager();
  await audioVolumeGroupManager.setMicMute(true).then(() => {
    console.info('setMicrophoneMute to mute.');
  });
}

// Unmute the microphone.
async function setMicrophoneMuteFalse() {
  await loadVolumeGroupManager();
  await audioVolumeGroupManager.setMicMute(false).then(() => {
    console.info('setMicrophoneMute to not mute.');
  });
}

async function test(){
  await on();
  await isMicrophoneMute();
  await setMicrophoneMuteTrue();
  await isMicrophoneMute();
  await setMicrophoneMuteFalse();
  await isMicrophoneMute();
  await setMicrophoneMuteTrue();
  await isMicrophoneMute();
}
```

   <!--DelEnd--> 