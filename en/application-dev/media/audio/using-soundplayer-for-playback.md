# Using SoundPlayer for System Sound Effect Playback

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwall-->
<!--Designer: @huyue57-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=cfecea1c41187dad0c66b395f9088cd7a30d17e5 translatedAt=2026-08-06T01:56:02.310Z pushedAt=2026-08-06T10:29:06.609Z -->

Starting from API version 23, system sound effect playback is supported.

**SoundPlayer** provides system sound effect playback functionality, which is suitable for camera prompt sounds, such as playing prompt sounds when starting to take a photo, starting to record a video, or ending a video recording.

## Supported Sound Effect Types

The following table describes the supported [sound effect types](../../reference/apis-audio-kit/js-apis-systemSoundManager.md#systemsoundtype). Specific types like **systemSoundManager.SystemSoundType.PHOTO_SHUTTER** can be used as input parameters for the [load](../../reference/apis-audio-kit/js-apis-inner-multimedia-systemSoundPlayer.md#load), [play](../../reference/apis-audio-kit/js-apis-inner-multimedia-systemSoundPlayer.md#play), or [unload](../../reference/apis-audio-kit/js-apis-inner-multimedia-systemSoundPlayer.md#unload) methods.

| Sound Effect Type| Value| Description| 
| -------- | -------- | -------- |
| PHOTO_SHUTTER | 0 | Camera shutter sound.| 
| VIDEO_RECORDING_BEGIN | 1 | Video recording start sound.| 
| VIDEO_RECORDING_END | 2 | Video recording end sound.|

## How to Develop

The examples in the following steps are code snippets. You can click the link at the bottom right of each to get the [complete sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/SystemSoundPlayer).

1. Before calling any of the **SystemSoundPlayer** APIs, you need to create an instance through [createSystemSoundPlayer](../../reference/apis-audio-kit/js-apis-systemSoundManager.md#systemsoundmanagercreatesystemsoundplayer).

   <!-- @[sound_player_create](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/SystemSoundPlayer/entry/src/main/ets/pages/SoundPlayer.ets) -->

   ``` TypeScript
   import { systemSoundManager } from '@kit.AudioKit';
   // ...
   
   // SystemSoundPlayer object
   let systemSoundPlayer: systemSoundManager.SystemSoundPlayer | null = null;
   
   // ...
     systemSoundManager.createSystemSoundPlayer().then((systemSoundPlayerInstance) => {
       console.info('Succeeded in creating the system sound player.');
       systemSoundPlayer = systemSoundPlayerInstance;
     }).catch((err: BusinessError) => {
       console.error(`Failed to create the system sound player. Code: ${err.code}, message: ${err.message}`);
     });
   ```

2. Call the [load](../../reference/apis-audio-kit/js-apis-inner-multimedia-systemSoundPlayer.md#load) API to load the sound effect resource of a specified type.

   <!-- @[sound_player_load](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/SystemSoundPlayer/entry/src/main/ets/pages/SoundPlayer.ets) -->

   ``` TypeScript
   import { systemSoundManager } from '@kit.AudioKit';
   // ...
   
   // Sound effect type
   let systemSoundType: systemSoundManager.SystemSoundType = systemSoundManager.SystemSoundType.PHOTO_SHUTTER;
   
   // ...
     systemSoundPlayer?.load(systemSoundType).then(() => {
       console.info('Succeeded in calling the load method.');
     }).catch((err: BusinessError) => {
       console.error(`Failed to call the load method. Code: ${err.code}, message: ${err.message}`);
     });
   ```

3. Call the [play](../../reference/apis-audio-kit/js-apis-inner-multimedia-systemSoundPlayer.md#play) API to play the loaded sound effect resource.

   <!-- @[sound_player_play](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/SystemSoundPlayer/entry/src/main/ets/pages/SoundPlayer.ets) -->

   ``` TypeScript
   import { systemSoundManager } from '@kit.AudioKit';
   // ...
   
   // Sound effect type
   let systemSoundType: systemSoundManager.SystemSoundType = systemSoundManager.SystemSoundType.PHOTO_SHUTTER;
   
   // ...
     systemSoundPlayer?.play(systemSoundType).then(() => {
       console.info('Succeeded in calling the play method.');
     }).catch((err: BusinessError) => {
       console.error(`Failed to call the play method. Code: ${err.code}, message: ${err.message}`);
     });
   ```

4. Call the [unload](../../reference/apis-audio-kit/js-apis-inner-multimedia-systemSoundPlayer.md#unload) API to unload the sound effect resource.

   <!-- @[sound_player_unload](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/SystemSoundPlayer/entry/src/main/ets/pages/SoundPlayer.ets) -->

   ``` TypeScript
   import { systemSoundManager } from '@kit.AudioKit';
   // ...
   
   // Sound effect type
   let systemSoundType: systemSoundManager.SystemSoundType = systemSoundManager.SystemSoundType.PHOTO_SHUTTER;
   
   // ...
     systemSoundPlayer?.unload(systemSoundType).then(() => {
       console.info('Succeeded in calling the unload method.');
     }).catch((err: BusinessError) => {
       console.error(`Failed to call the unload method. Code: ${err.code}, message: ${err.message}`);
     });
   ```

5. Call the [release](../../reference/apis-audio-kit/js-apis-inner-multimedia-systemSoundPlayer.md#release) API to release the system sound effect player.

   <!-- @[sound_player_release](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/SystemSoundPlayer/entry/src/main/ets/pages/SoundPlayer.ets) -->

   ``` TypeScript
   systemSoundPlayer?.release().then(() => {
     console.info('Succeeded in calling the release method.');
   }).catch((err: BusinessError) => {
     console.error(`Failed to call the release method. Code: ${err.code}, message: ${err.message}`);
   });
   ```