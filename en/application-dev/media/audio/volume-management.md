# Volume Management

You can use different APIs to manage the system volume and audio stream volume. The system volume and audio stream volume refer to the volume of a OpenHarmony device and the volume of a specified audio stream, respectively. The audio stream volume is restricted by the system volume.

## System Volume

**AudioVolumeManager** is provided for system volume management. Before using this API, you must call [getVolumeManager()](../../reference/apis-audio-kit/js-apis-audio.md#getvolumemanager9) to obtain an **AudioVolumeManager** instance.

Currently, **AudioVolumeManager** can be used to obtain volume information and listen for volume changes. It cannot be used to adjust the system volume. If you want to adjust the system volume, follow the instructions provided in [Adjusting the System Volume Using the Volume Panel](#adjusting-the-system-volume-using-the-volume-panel).

```ts
import { audio } from '@kit.AudioKit';

let audioManager = audio.getAudioManager();
let audioVolumeManager = audioManager.getVolumeManager();
```

### Listening for System Volume Changes

You can set an event to listen for system volume changes.

```ts
import { audio } from '@kit.AudioKit';

audioVolumeManager.on('volumeChange', (volumeEvent: audio.VolumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
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

**AudioVolumeManager** is provided for application volume management. Before using this API, you must call [getVolumeManager()](../../reference/apis-audio-kit/js-apis-audio.md#getvolumemanager9) to obtain an **AudioVolumeManager** instance.

When [volume mode](../../reference/apis-audio-kit/js-apis-audio.md#audiovolumemode18) is set to **APP_INDIVIDUAL**, you can set and query the application volume by calling the APIs in the following sample.

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
audioVolumeManager.setAppVolumePercentageForUid(uid, true).then((value: boolean) => {
  console.info(`app muted state is ${value}.`);
});

// Set the application mute state.
audioVolumeManager.setAppVolumePercentageForUid(uid, true).then(() => {
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

The **setVolume()** API in both the **AVPlayer** and **AudioRenderer** classes can be used to set the audio stream volume. The code snippet below uses the API in the [AVPlayer](../../reference/apis-media-kit/js-apis-media.md#mediacreateavplayer9) class:

```ts
let volume = 1.0;  // Specified volume. The value range is [0.00-1.00]. The value 1 indicates the maximum volume.
avPlayer.setVolume(volume);
```

The code snippet below uses the API in the [AudioRenderer](../../reference/apis-audio-kit/js-apis-audio.md#audiocreateaudiorenderer8) class:

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.setVolume(0.5).then(() => {  // The volume range is [0.0-1.0].
  console.info('Invoke setVolume succeeded.');
}).catch((err: BusinessError) => {  
  console.error(`Invoke setVolume failed, code is ${err.code}, message is ${err.message}`);
});
```
