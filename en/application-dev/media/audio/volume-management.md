# Volume Management

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

  The adjustment range for the application volume and audio stream volume is limited by the system volume. For example, if the system media volume is set to 50% and the application volume is set to 100%, the final output volume of the application can only reach 50%.

  The audio stream volume provides more precise control over the application volume. Third-party applications that have set an application volume can further fine-tune the volume of specific audio streams using the audio stream volume.
- Synergy: The final output volume of an application is determined collectively by the system volume, application volume, and audio stream volume. For example, if the system media volume is set to 50%, the application volume is set to 50%, and the application sets the audio stream volume for media audio to 100%, the final output volume of that audio stream will be 25%.

OpenHarmony achieves precise volume control for applications through the coordinated use of the system volume, app volume, and audio stream volume.

## System Volume

The API for managing system volume is provided by AudioVolumeManager. Before using this API, you must call [getVolumeManager()](../../reference/apis-audio-kit/arkts-apis-audio-AudioManager.md#getvolumemanager9) to obtain an AudioVolumeManager instance.

Currently, AudioVolumeManager can be used to obtain volume information and listen for volume changes. It cannot be used to adjust the system volume. If you want to adjust the system volume, follow the instructions provided in [Adjusting the System Volume Using the Volume Panel](#adjusting-the-system-volume-using-the-volume-panel).

```ts
import { audio } from '@kit.AudioKit';

let audioManager = audio.getAudioManager();
let audioVolumeManager = audioManager.getVolumeManager();
```

### Obtaining Volume Information

The API for managing system volume is provided by AudioVolumeManager. Before using this API, you must call [getVolumeManager()](../../reference/apis-audio-kit/arkts-apis-audio-AudioManager.md#getvolumemanager9) to obtain an AudioVolumeManager instance.

```ts
import { audio } from '@kit.AudioKit';

let audioManager = audio.getAudioManager();
let audioVolumeManager = audioManager.getVolumeManager();
```

Call [AudioVolumeManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioVolumeManager.md) to obtain the volume of a specified audio stream.

The example code is as follows:

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the volume of a stream.
audioVolumeManager.getVolumeByStream(audio.StreamUsage.STREA_USAGE_MUSIC);

// Obtain the minimum volume of a stream.
audioVolumeManager.getMinVolumeByStream(audio.StreamUsage.STREA_USAGE_MUSIC);

// Obtain the maximum volume of a stream.
audioVolumeManager.getMaxVolumeByStream(audio.StreamUsage.STREA_USAGE_MUSIC);
```

### Listening for System Volume Changes

You can set an event to listen for system volume changes.

```ts
import { audio } from '@kit.AudioKit';

audioVolumeManager.on('streamVolumeChange', audio.StreamUsage.STREAM_USAGE_MUSIC, (streamVolumeEvent: audio.StreamVolumeEvent) => {
  console.info(`StreamUsagem: ${streamVolumeEvent.streamUsage} `);
  console.info(`Volume level: ${streamVolumeEvent.volume} `);
  console.info(`Whether to updateUI: ${streamVolumeEvent.updateUi} `);
});
```

<!--Del-->
### Adjusting the System Volume (for System Applications Only)

Currently, adjusting the system volume is mainly conducted by using system APIs, which are available for the physical volume button and the Settings application. When the user presses the volume button, a system API is called to adjust the system volume, including the volume for media, ringtone, or notification.
<!--DelEnd-->

### Adjusting the System Volume Using the Volume Panel

An application cannot directly adjust the system volume. However, it can invoke the system volume panel for users to adjust the volume. When the user adjusts the volume, a volume prompt UI is displayed to explicitly notify the user that the system volume changes.

To achieve this, you can use the ArkTS component **AVVolumePanel** in your application. For details, see the [AVVolumePanel Reference](../../reference/apis-audio-kit/ohos-multimedia-avvolumepanel.md).

## Application Volume

The API for managing application volume is provided by AudioVolumeManager. Before using this API, you must call [getVolumeManager()](../../reference/apis-audio-kit/arkts-apis-audio-AudioManager.md#getvolumemanager9) to obtain an AudioVolumeManager instance.

When [volume mode](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audiovolumemode19) is set to **APP_INDIVIDUAL**, you can set and query the application volume by calling the APIs in the following sample.

### Adjusting the Application Volume

```ts
import { audio } from '@kit.AudioKit';

let audioManager = audio.getAudioManager();
let audioVolumeManager = audioManager.getVolumeManager();

// Set the volume (ranging from 0 to 100) for the application.
audioVolumeManager.setAppVolumePercentage(20).then(() => {
  console.info(`set app volume success.`);
});

// Query the application volume.
audioVolumeManager.getAppVolumePercentage().then((value: number) => {
  console.info(`app volume is ${value}.`);
});

// Subscribe to the application volume change event. For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let appVolumeChangeCallback = (volumeEvent: audio.VolumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
};
audioVolumeManager.on('appVolumeChange', appVolumeChangeCallback);
audioVolumeManager.off('appVolumeChange', appVolumeChangeCallback);

// Cancel all subscriptions to the event.
audioVolumeManager.off('appVolumeChange');
```

<!--Del-->
### Adjusting the Application Volume Based on the UID (for System Applications Only)

```ts
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

// Cancel all subscriptions to the event.
audioVolumeManager.off('appVolumeChangeForUid');
```
<!--DelEnd-->

## Audio Stream Volume

The **setVolume()** API in both the **AVPlayer** and **AudioRenderer** classes can be used to set the audio stream volume. The code snippet below uses the API in the [AVPlayer](../../reference/apis-media-kit/arkts-apis-media-f.md#mediacreateavplayer9) class:

```ts
let volume = 1.0;  // Specified volume. The value range is [0.00-1.00]. The value 1 indicates the maximum volume.
avPlayer.setVolume(volume);
```

Call [setVolume](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#setvolume9) and [getVolume](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#getvolume12) of [AudioRenderer](../../reference/apis-audio-kit/arkts-apis-audio-f.md#audiocreateaudiorenderer8) to set and obtain the volume of the audio stream, respectively.

The example code is as follows:

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Set the volume for the audio stream.
audioRenderer.setVolume(0.5).then(() => {  // The volume range is [0.0-1.0].
  console.info('Invoke setVolume succeeded.');
}).catch((err: BusinessError) => {
  console.error(`Invoke setVolume failed, code is ${err.code}, message is ${err.message}`);
});

// Obtain the volume of the audio stream.
try {
  let value: number = audioRenderer.getVolume();
  console.info(`Indicate that the volume is obtained ${value}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the volume, error ${error}.`);
}
```

### Listening for Active Stream Changes

You can set an event to listen for active stream changes.

```ts
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

<!--no_check-->