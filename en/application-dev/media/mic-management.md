# Microphone Management

The microphone is used to record audio data. To deliver an optimal recording effect, you are advised to query the microphone state before starting recording and listen for state changes during recording.

If the user mutes the microphone during audio recording, the recording process is normal, the size of the recorded file increases with the recording duration, but the data volume written into the file is 0.

## How to Develop

The **AudioVolumeGroupManager** class provides APIs for managing the microphone state. For details, see [API Reference](../reference/apis/js-apis-audio.md#audiovolumegroupmanager9).

1. Create an **audioVolumeGroupManager** object.
   
   ```ts
   import audio from '@ohos.multimedia.audio';
   
   let audioVolumeGroupManager;
   async function loadVolumeGroupManager() { // Create an audioVolumeGroupManager object.
     const groupid = audio.DEFAULT_VOLUME_GROUP_ID;
     audioVolumeGroupManager = await audio.getAudioManager().getVolumeManager().getVolumeGroupManager(groupid);
     console.info('audioVolumeGroupManager create success.');
   }
   ```

2. Call **on('micStateChange')** to listen for microphone state changes. When the microphone state changes, the application will be notified of the change.
   
   Currently, when multiple **AudioManager** instances are used in a single process, only the subscription of the last instance takes effect, and the subscription of other instances is overwritten (even if the last instance does not initiate a subscription). Therefore, you are advised to use a single **AudioManager** instance.

   
   ```ts
   async function on() {   // Subscribe to microphone state changes.
     audioVolumeGroupManager.on('micStateChange', (micStateChange) => {
       console.info(`Current microphone status is: ${micStateChange.mute} `);
     });
   }
   ```

3. Call **isMicrophoneMute** to check whether the microphone is muted. If the returned value is **true**, the microphone is muted; otherwise, the microphone is not muted.
   
   ```ts
   async function isMicrophoneMute() { // Check whether the microphone is muted.
     await audioVolumeGroupManager.isMicrophoneMute().then((value) => {
       console.info(`isMicrophoneMute is: ${value}.`);
     });
   }
   ```

4. Call **setMicrophoneMute** to mute or unmute the microphone. To mute the microphone, pass in **true**. To unmute the microphone, pass in **false**.
   
   ```ts
   async function setMicrophoneMuteTrue() { // Pass in true to mute the microphone.
     await audioVolumeGroupManager.setMicrophoneMute(true).then(() => {
       console.info('setMicrophoneMute to mute.');
     });
   }
   async function setMicrophoneMuteFalse() { // Pass in false to unmute the microphone.
     await audioVolumeGroupManager.setMicrophoneMute(false).then(() => {
       console.info('setMicrophoneMute to not mute.');
     });
   }
   ```

## Sample Code

Refer to the sample code below to complete the process of muting and unmuting the microphone.

```ts
import audio from '@ohos.multimedia.audio';

@Entry
@Component
struct AudioVolumeGroup {
 private audioVolumeGroupManager: audio.AudioVolumeGroupManager;

  async loadVolumeGroupManager() {
    const groupid = audio.DEFAULT_VOLUME_GROUP_ID;
    this.audioVolumeGroupManager = await audio.getAudioManager().getVolumeManager().getVolumeGroupManager(groupid);
    console.info('audioVolumeGroupManager------create-------success.');
  }

  async on() {   // Subscribe to microphone state changes.
    await this.loadVolumeGroupManager();
    this.audioVolumeGroupManager.on('micStateChange', (micStateChange) => {
      console.info(`Current microphone status is: ${micStateChange.mute} `);
    });
  }
  async isMicrophoneMute() { // Check whether the microphone is muted.
    await this.audioVolumeGroupManager.isMicrophoneMute().then((value) => {
      console.info(`isMicrophoneMute is: ${value}.`);
    });
  }
  async setMicrophoneMuteTrue() { // Mute the microphone.
    await this.loadVolumeGroupManager();
    await this.audioVolumeGroupManager.setMicrophoneMute(true).then(() => {
      console.info('setMicrophoneMute to mute.');
    });
  }
  async setMicrophoneMuteFalse() { // Unmute the microphone.
    await this.loadVolumeGroupManager();
    await this.audioVolumeGroupManager.setMicrophoneMute(false).then(() => {
      console.info('setMicrophoneMute to not mute.');
    });
  }
  async test(){
    await this.on();
    await this.isMicrophoneMute();
    await this.setMicrophoneMuteTrue();
    await this.isMicrophoneMute();
    await this.setMicrophoneMuteFalse();
    await this.isMicrophoneMute();
    await this.setMicrophoneMuteTrue();
    await this.isMicrophoneMute();
  }
}
```
