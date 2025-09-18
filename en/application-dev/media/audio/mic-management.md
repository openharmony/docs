# Microphone Management
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

The microphone is used to record audio data. To deliver an optimal recording effect, you are advised to query the microphone state before starting recording and listen for state changes during recording.

If the user mutes the microphone during audio recording, the recording process is normal, the size of the recorded file increases with the recording duration, but the data volume written into the file is 0.

## How to Develop

The **AudioVolumeGroupManager** class provides APIs for managing the microphone state. For details, see [API Reference](../../reference/apis-audio-kit/arkts-apis-audio-AudioVolumeGroupManager.md).

1. Create an audioVolumeGroupManager object.
     
   ```ts
   import { audio } from '@kit.AudioKit';

   let audioVolumeGroupManager: audio.AudioVolumeGroupManager;

   // Create an audioVolumeGroupManager object.
   async function loadVolumeGroupManager() {
     const groupid = audio.DEFAULT_VOLUME_GROUP_ID;
     audioVolumeGroupManager = await audio.getAudioManager().getVolumeManager().getVolumeGroupManager(groupid);
     console.info('audioVolumeGroupManager create success.');
   }
   ```
<!--Del-->
2. **(Optional; for system applications only)** Call **on('micStateChange')** to listen for microphone state changes. When the microphone state changes, the application will be notified of the change.
   
   Currently, when multiple AudioManager instances are used in a single process, only the subscription of the last instance takes effect, and the subscription of other instances is overwritten (even if the last instance does not initiate a subscription). Therefore, you are advised to use a single AudioManager instance.

   ```ts
   // Listen for microphone state changes.
   async function on() {
     audioVolumeGroupManager.on('micStateChange', (micStateChange: audio.MicStateChangeEvent) => {
       console.info(`Current microphone status is: ${micStateChange.mute} `);
     });
   }
   ```
<!--DelEnd-->

3. Call **isMicrophoneMute** to check whether the microphone is muted. If the return value is **true**, the microphone is muted; otherwise, the microphone is not muted.
     
   ```ts
   // Check whether the microphone is muted.
   async function isMicrophoneMute() {
     await audioVolumeGroupManager.isMicrophoneMute().then((value: boolean) => {
       console.info(`isMicrophoneMute is: ${value}.`);
     });
   }
   ```
<!--Del-->
4. **(Optional; for system applications only)** Call **setMicrophoneMute** to mute or unmute the microphone. To mute the microphone, pass in **true**. To unmute the microphone, pass in **false**.
     
   ```ts
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

```ts
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
