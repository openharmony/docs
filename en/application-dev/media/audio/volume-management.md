# Volume Management

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @hao-liangfei-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=b065b5b02aeefe715acab92287399dde4481a96c translatedAt=2026-08-06T01:57:29.467Z pushedAt=2026-08-06T10:33:26.467Z -->

This module provides capabilities for managing playback volume, covering system volume, application volume, and audio stream volume.

The system volume is managed globally by OpenHarmony and applies to all applications and devices. OpenHarmony categorizes audio into various stream types, each with its own independent system volume control.

> **NOTE**
>
> The system volume can be adjusted using physical volume buttons or through the system settings screen. On the system settings screen, users can individually adjust the volume levels for each type of system volume.

The following lists the common stream types and their corresponding system volumes.

- Media volume: used for media playback such as music, videos, and games.

- Call volume: used for voice calls.

- Ringtone volume: used for incoming call ringtones.

- Alarm volume: used for alarm notifications.

The application volume is a type of volume control provided by OpenHarmony for third-party applications to manage the volume of all audio streams within that application. Once set, all audio streams initiated by the application will use this volume level by default. In addition, applications with the system application permission can adjust the volume of specific applications by using their UIDs.

The audio stream volume is a volume setting controlled independently by an application and affects only the output volume of the specified audio stream within that application. For example, a media player can control its playback volume independently without affecting the system volume or other types of stream volumes within the application.

The following describes the relationship between the system volume, application volume, and audio stream volume.

- Hierarchy: The system volume is global, whereas the application volume and audio stream volume are local.

  The adjustment range for the app volume and audio stream volume is limited by the system volume. For example, if the system media volume is set to 50% and the app volume is set to 100%, the final output volume of the application can only reach 50% (50% * 100%).<br>
  The audio stream volume provides finer-grained control over the app volume. Third-party applications that have set the app volume can further use the audio stream volume to exercise more precise control over specific audio streams.

- Synergy: The final output volume of an application is determined collectively by the system volume, app volume, and audio stream volume. For example, if the system media volume is set to 50%, the app volume is set to 50%, and the audio stream volume for a media audio stream in the application is set to 100%, the final output volume of that audio stream is 25% (50% * 50% * 100%).

OpenHarmony achieves precise volume control for applications through the coordinated use of the system volume, app volume, and audio stream volume.

The following examples are code snippets. You can get the [complete sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample) via the link at the bottom right of the sample code.

## System Volume

The API for managing the system volume is provided by **AudioVolumeManager**. Before using this API, you must call [getVolumeManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioManager.md#getvolumemanager9) to obtain an **AudioVolumeManager** instance.

Currently, AudioVolumeManager can be used to obtain volume information and listen for volume changes. It cannot be used to adjust the system volume. If you want to adjust the system volume, follow the instructions provided in [Adjusting the System Volume Using the Volume Panel](#adjusting-the-system-volume-using-the-volume-panel).

<!-- @[getVolumeManager](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/VolumeManagement.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
// ...

let audioManager = audio.getAudioManager();
let audioVolumeManager = audioManager.getVolumeManager();
```

### Obtaining Volume Information

Call [AudioVolumeManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioVolumeManager.md) to obtain the volume of a specified audio stream.

The example code is as follows:

<!-- @[getVolumeByStream](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/VolumeManagement.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

  try {
    // Obtain the volume of the specified audio stream.
    let volume = audioVolumeManager.getVolumeByStream(audio.StreamUsage.STREAM_USAGE_MUSIC);
    console.info(`Succeeded in getting volume by stream. Volume: ${volume}`);
    // ...
  } catch (err) {
    let error = err as BusinessError;
    console.error(`Failed to get volume by stream. Code: ${error.code}, message: ${error.message}`);
    // ...
  }
  // ...

  try {
    // Obtain the minimum volume of the specified audio stream.
    let volume = audioVolumeManager.getMinVolumeByStream(audio.StreamUsage.STREAM_USAGE_MUSIC);
    console.info(`Succeeded in getting min volume by stream. Volume: ${volume}`);
    // ...
  } catch (err) {
    let error = err as BusinessError;
    console.error(`Failed to get min volume by stream. Code: ${error.code}, message: ${error.message}`);
    // ...
  }
  // ...

  try {
    // Obtain the maximum volume of the specified audio stream.
    let volume = audioVolumeManager.getMaxVolumeByStream(audio.StreamUsage.STREAM_USAGE_MUSIC);
    console.info(`Succeeded in getting max volume by stream. Volume: ${volume}`);
    // ...
  } catch (err) {
    let error = err as BusinessError;
    console.error(`Failed to get max volume by stream. Code: ${error.code}, message: ${error.message}`);
    // ...
  }
```

### Listening for System Volume Changes

You can set an event to listen for system volume changes.

<!-- @[onStreamVolumeChange](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/VolumeManagement.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

  try {
    audioVolumeManager.on('streamVolumeChange', audio.StreamUsage.STREAM_USAGE_MUSIC, (streamVolumeEvent: audio.StreamVolumeEvent) => {
      console.info(`Succeeded in using on function. StreamVolumeEvent: ${JSON.stringify(streamVolumeEvent)}`);
      // ...
    });
  } catch (err) {
    let error = err as BusinessError;
    console.error(`Failed to use on function. Code: ${error.code}, message: ${error.message}`);
    // ...
  }
```

<!--Del-->

### Adjusting the System Volume (for System Applications Only)

Currently, adjusting the system volume is mainly conducted by using system APIs, which are available for the physical volume button and the Settings application. When the user presses the volume button, a system API is called to adjust the system volume, including the volume for media, ringtone, or notification.

<!--DelEnd-->

### Adjusting the System Volume Using the Volume Panel

An application cannot directly adjust the system volume. However, it can invoke the system volume panel for users to adjust the volume. When the user adjusts the volume, a volume prompt UI is displayed to explicitly notify the user that the system volume changes.

The system provides the ArkTS component AVVolumePanel (volume panel), which applications can create. For details and examples, see [avVolumePanel](../../reference/apis-audio-kit/ohos-multimedia-avvolumepanel.md).

## Application Volume

The API for managing the application volume is provided by **AudioVolumeManager**. Before using this API, you must call [getVolumeManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioManager.md#getvolumemanager9) to obtain an **AudioVolumeManager** instance.

When [volume mode](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audiovolumemode19) is set to **APP_INDIVIDUAL**, you can set and query the application volume by calling the APIs in the following sample.

### Adjusting the Application Volume

<!-- @[setAppVolumePercentage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/VolumeManagement.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

let audioManager = audio.getAudioManager();
let audioVolumeManager = audioManager.getVolumeManager();

let appVolumeChangeCallback = (volumeEvent: audio.VolumeEvent) => {
  console.info(`Succeeded in using on function. VolumeEvent: ${JSON.stringify(volumeEvent)}`);
  // ...
};
// ...

  try {
    // Listen for app volume changes.
    audioVolumeManager.on('appVolumeChange', appVolumeChangeCallback);
  } catch (err) {
    let error = err as BusinessError;
    console.error(`Failed to use on function. Code: ${error.code}, message: ${error.message}`);
    // ...
  }
  // ...

  // Set the volume (ranging from 0 to 100) for the application.
  audioVolumeManager.setAppVolumePercentage(20).then(() => {
    console.info('Succeeded in setting app volume percentage.');
    // ...
  }).catch((err: BusinessError) => {
    console.error(`Failed to set app volume percentage. Code: ${err.code}, message: ${err.message}`);
    // ...
  });
  // ...

  // Query the application volume.
  audioVolumeManager.getAppVolumePercentage().then((volume: number) => {
    console.info(`Succeeded in getting app volume percentage. Volume: ${volume}`);
    // ...
  }).catch((err: BusinessError) => {
    console.error(`Failed to get app volume percentage. Code: ${err.code}, message: ${err.message}`);
    // ...
  });
```

<!--Del-->

### Adjusting the Application Volume Based on the UID (for System Applications Only)

``` TypeScript
import { audio } from '@kit.AudioKit';

let uid: number = 20010041; // Application ID.
let audioManager = audio.getAudioManager();
let audioVolumeManager = audioManager.getVolumeManager();

// Set the volume (ranging from 0 to 100) for an application.
let volume: number = 20;    // Volume to set.
audioVolumeManager.setAppVolumePercentageForUid(uid, volume).then(() => {
  console.info(`set app volume success.`);
});

// Obtain the volume (ranging from 0 to 100) of an application.
audioVolumeManager.getAppVolumePercentageForUid(uid).then((value: number) => {
  console.info(`app volume is ${value}.`);
});

// Check whether the application volume is muted.
audioVolumeManager.isAppVolumeMutedForUid(uid, true).then((value: boolean) => {
  console.info(`app muted state is ${value}.`);
});

// Set the application mute state.
audioVolumeManager.setAppVolumeMutedForUid(uid, true).then(() => {
  console.info(`set app mute state success.`);
});

// Subscribe to the application volume change event. For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let appVolumeChangeForUidCallback = (volumeEvent: audio.VolumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
};
audioVolumeManager.on('appVolumeChangeForUid', uid, appVolumeChangeForUidCallback);
audioVolumeManager.off('appVolumeChangeForUid', appVolumeChangeForUidCallback);
```

<!--DelEnd-->

## Audio Stream Volume

You can use [setVolume](../../reference/apis-media-kit/arkts-apis-media-AVPlayer.md#setvolume9) of [AVPlayer](../../reference/apis-media-kit/arkts-apis-media-f.md#mediacreateavplayer9) or [setVolume](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#setvolume9) of [AudioRenderer](../../reference/apis-audio-kit/arkts-apis-audio-f.md#audiocreateaudiorenderer8) to set the audio stream volume.

Call [setVolume](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#setvolume9) and [getVolume](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#getvolume12) of [AudioRenderer](../../reference/apis-audio-kit/arkts-apis-audio-f.md#audiocreateaudiorenderer8) to set and obtain the volume of the audio stream, respectively.

The example code is as follows:

<!-- @[setVolume](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/VolumeManagement.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

    // Set the audio stream volume. The volume ranges from 0.0 to 1.0.
    audioRenderer.setVolume(0.1).then(() => {
      console.info('Succeeded in setting volume.');
      // ...
    }).catch((err: BusinessError) => {
      console.error(`Failed to set volume. Code: ${err.code}, message: ${err.message}`);
      // ...
    });
    // ...

    try {
      // Obtain the audio stream volume.
      let volume: number = audioRenderer.getVolume();
      console.info(`Succeeded in getting volume. Volume: ${volume}`);
      // ...
    } catch (err) {
      let error = err as BusinessError;
      console.error(`Failed to get volume. Code: ${error.code}, message: ${error.message}`);
      // ...
    }
```

<!--Del-->

### Listening for Active Stream Changes (for System Applications Only)

You can set an event to listen for active stream changes.

``` TypeScript
import { audio } from '@kit.AudioKit';

// Subscribe to the active stream change event. For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let activeVolumeTypeChangeCallback = (volumeType: audio.AudioVolumeType) => {
  console.info(`VolumeType of stream: ${volumeType} `);
};
audioVolumeManager.on('activeVolumeTypeChange', activeVolumeTypeChangeCallback);
audioVolumeManager.off('activeVolumeTypeChange', activeVolumeTypeChangeCallback);

// Cancel all subscriptions to the event.
audioVolumeManager.off('activeVolumeTypeChange');
```

<!--DelEnd-->