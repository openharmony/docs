# Volume Management

You can use different APIs to manage the system volume and audio stream volume. The system volume and audio stream volume refer to the volume of a OpenHarmony device and the volume of a specified audio stream, respectively. The audio stream volume is restricted by the system volume.

## System Volume

The API for managing the system volume is **AudioVolumeManager**. Before using this API, you must call **getVolumeManager()** to obtain an **AudioVolumeManager** instance. Currently, this API can be used to obtain volume information and listen for volume changes. It cannot be used to adjust the system volume.

```ts
import audio from '@ohos.multimedia.audio';
let audioManager = audio.getAudioManager();
let audioVolumeManager = audioManager.getVolumeManager();
```

### Listening for System Volume Changes

You can set an event to listen for system volume changes.

```ts
audioVolumeManager.on('volumeChange', (volumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
});
```

### Adjusting the System Volume (for System Applications Only)

Currently, the system volume is mainly adjusted by using system APIs, which serve the physical volume button and the Settings application. When the user presses the volume button, a system API is called to adjust the system volume, including the volume for media, ringtone, or notification.

## Audio Stream Volume

The API for managing the audio stream volume is **setVolume()** in the **AVPlayer** or **AudioRenderer** class. The code snippet below is used for setting the audio stream volume by using the **AVPlayer** class:

```ts
let volume = 1.0 // Specified volume. The value range is [0.00-1.00]. The value 1 indicates the maximum volume.
avPlayer.setVolume(volume)
```

The code snippet below is used for setting the audio stream volume by using the **AudioRenderer** class:

```ts
audioRenderer.setVolume(0.5).then(data=>{ // The volume range is [0.0-1.0].
  console.info('Invoke setVolume succeeded.');
}).catch((err) => {  
  console.error(`Invoke setVolume failed, code is ${err.code}, message is ${err.message}`);
});
```
