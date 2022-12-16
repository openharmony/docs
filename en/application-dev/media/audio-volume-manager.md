# Volume Management Development

## Overview

The **AudioVolumeManager** module provides APIs for volume management. You can use the APIs to obtain the volume of a stream, listen for ringer mode changes, and mute a microphone.

## Working Principles

The figure below shows the common APIs provided by the **AudioVolumeManager** module.

**Figure 1** Common APIs of AudioVolumeManager

![en-us_image_audio_volume_manager](figures/en-us_image_audio_volume_manager.png)

**AudioVolumeManager** provides the APIs for subscribing to system volume changes and obtaining the audio volume group manager (an **AudioVolumeGroupManager** instance). Before calling any API in **AudioVolumeGroupManager**, you must call **getVolumeGroupManager** to obtain an **AudioVolumeGroupManager** instance. You can use the APIs provided by **AudioVolumeGroupManager** to obtain the volume of a stream, mute a microphone, and listen for microphone state changes. For details, see [Audio Management](../reference/apis/js-apis-audio.md).

## Constraints

Before developing a microphone management application, configure the permission **ohos.permission.MICROPHONE** for the application. To set the microphone state, configure the permission **ohos.permission.MANAGE_AUDIO_CONFIG** (a system permission). For details about the permission configuration, see [Permission Application Guide](../security/accesstoken-guidelines.md).

## How to Develop

For details about the APIs, see [AudioVolumeManager in Audio Management](../reference/apis/js-apis-audio.md#audiovolumemanager9)

1. Obtain an **AudioVolumeGroupManager** instance.

   Before using an API in **AudioVolumeGroupManager**, you must use **getVolumeGroupManager()** to obtain an **AudioStreamManager** instance.

   ```js
   import audio from '@ohos.multimedia.audio';
   async loadVolumeGroupManager() {
     const groupid = audio.DEFAULT_VOLUME_GROUP_ID;
     var audioVolumeGroupManager = await audio.getAudioManager().getVolumeManager().getVolumeGroupManager(groupid);
     console.error('audioVolumeGroupManager create success.');
   }

   ```

2. (Optional) Obtain the volume information and ringer mode.
   
   To obtain the volume information (such as the ringtone, voice call, media, and voice assistant) of an audio stream or obtain the ringer mode (silent, vibration, or normal) of the current device, refer to the code below. For more details, see [Audio Management](../reference/apis/js-apis-audio.md).

   ```js
   import audio from '@ohos.multimedia.audio';
   async loadVolumeGroupManager() {
     const groupid = audio.DEFAULT_VOLUME_GROUP_ID;
     var audioVolumeGroupManager = await audio.getAudioManager().getVolumeManager().getVolumeGroupManager(groupid);
     console.info('audioVolumeGroupManager create success.');
   }
   
   // Obtain the volume of a stream. The value ranges from 0 to 15.
   async getVolume() {
    await loadVolumeGroupManager();
    await audioVolumeGroupManager.getVolume(audio.AudioVolumeType.MEDIA).then((value) => {
      console.info(`getVolume success and volume is: ${value}.`);
    });
   }
   // Obtain the minimum volume of a stream.
   async getMinVolume() {
     await loadVolumeGroupManager();
     await audioVolumeGroupManager.getMinVolume(audio.AudioVolumeType.MEDIA).then((value) => {
       console.info(`getMinVolume success and volume is: ${value}.`);
     });
   }
   // Obtain the maximum volume of a stream.
   async getMaxVolume() {
     await loadVolumeGroupManager();
     await audioVolumeGroupManager.getMaxVolume(audio.AudioVolumeType.MEDIA).then((value) => {
       console.info(`getMaxVolume success and volume is: ${value}.`);
     });
   }
   // Obtain the ringer mode in use: silent (0) | vibrate (1) | normal (2).
   async getRingerMode() {
     await loadVolumeGroupManager();
     await audioVolumeGroupManager.getRingerMode().then((value) => {
       console.info(`getRingerMode success and RingerMode is: ${value}.`);
     });
   }
   ```

3. (Optional) Obtain and set the microphone state, and subscribe to microphone state changes.

   To obtain and set the microphone state or subscribe to microphone state changes, refer to the following code:

   ```js
   import audio from '@ohos.multimedia.audio';
   async loadVolumeGroupManager() {
     const groupid = audio.DEFAULT_VOLUME_GROUP_ID;
     var audioVolumeGroupManager = await audio.getAudioManager().getVolumeManager().getVolumeGroupManager(groupid);
     console.info('audioVolumeGroupManager create success.');
   }

   async on() {   // Subscribe to microphone state changes.
     await loadVolumeGroupManager();
     await audioVolumeGroupManager.audioVolumeGroupManager.on('micStateChange', (micStateChange) => {
       console.info(`Current microphone status is: ${micStateChange.mute} `);
     });
   }

   async isMicrophoneMute() { // Check whether the microphone is muted.
     await audioVolumeGroupManager.audioVolumeGroupManager.isMicrophoneMute().then((value) => {
       console.info(`isMicrophoneMute is: ${value}.`);
     });
   }
 
   async setMicrophoneMuteTrue() { // Mute the microphone.
     await loadVolumeGroupManager();
     await audioVolumeGroupManager.audioVolumeGroupManager.setMicrophoneMute(true).then(() => {
       console.info('setMicrophoneMute to mute.');
     });
   }
 
   async setMicrophoneMuteFalse() { // Unmute the microphone.
     await loadVolumeGroupManager();
     await audioVolumeGroupManager.audioVolumeGroupManager.setMicrophoneMute(false).then(() => {
       console.info('setMicrophoneMute to not mute.');
     });
   }
   async test(){  // Complete process: Subscribe to microphone state changes, obtain the microphone state, mute the microphone, obtain the microphone state, and unmute the microphone.
     await on();
     await isMicrophoneMute();
     await setMicrophoneMuteTrue();
     await isMicrophoneMute();
     await setMicrophoneMuteFalse();
   }
   ```
