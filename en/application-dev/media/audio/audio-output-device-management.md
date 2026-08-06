# Querying and Listening for Audio Output Devices

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @zhanganxiang1-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=425e79ed59a841b19860caacc0b050f68405d43e translatedAt=2026-08-06T01:45:37.904Z pushedAt=2026-08-06T06:21:43.696Z -->

Applications can manage global audio output devices in either of the following ways:

- Generally, applications can [query and listen for audio output devices using AudioRoutingManager](#querying-and-listening-for-audio-output-devices-using-audioroutingmanager).

- Starting from API version 20, AudioSessionManager offers certain APIs for managing output devices. Applications can now [query and listen for audio output devices using AudioSession](#querying-and-listening-for-audio-output-devices-using-audiosession). This is useful for simultaneously managing audio focus and output.

The examples in the following steps are code snippets. You can obtain the [complete sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample) via the link at the bottom right of each code block.

## Querying and Listening for Audio Output Devices Using AudioRoutingManager

You can use APIs to manage audio output devices, including querying audio device information and listening for connection status changes. For details about the APIs, see [AudioRoutingManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioRoutingManager.md).

### Creating an AudioRoutingManager Instance

Before using AudioRoutingManager to manage audio devices, import the audio module and create an instance.

<!-- @[getRoutingManager](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/AudioOutputDeviceManagement.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
// ...

let audioManager = audio.getAudioManager();
let audioRoutingManager = audioManager.getRoutingManager();
```

### Supported Audio Output Device Types

The table below lists the supported output devices.

| Name| Value| Description|
| -------- | -------- | -------- |
| EARPIECE | 1 | Earpiece.|
| SPEAKER | 2 | Speaker.|
| WIRED_HEADSET | 3 | Wired headset with a microphone.|
| WIRED_HEADPHONES | 4 | Wired headset without microphone.|
| BLUETOOTH_SCO | 7 | Bluetooth device using Synchronous Connection Oriented (SCO) links.|
| BLUETOOTH_A2DP | 8 | Bluetooth device using Advanced Audio Distribution Profile (A2DP) links.|
| USB_HEADSET | 22 | USB headset with a microphone. |
| NEARLINK | 31 | NearLink device. |

### Obtaining Output Device Information

Use [getDevices](../../reference/apis-audio-kit/arkts-apis-audio-AudioRoutingManager.md#getdevices9) to obtain information about all current output devices.

<!-- @[getDevices](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/AudioOutputDeviceManagement.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

  audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((audioDeviceDescriptors: audio.
    AudioDeviceDescriptors) => {
    console.info(`Succeeded in getting devices. AudioDeviceDescriptors: ${JSON.stringify(audioDeviceDescriptors)}`);
    // ...
  }).catch((err: BusinessError) => {
    console.error(`Failed to get devices. Code: ${err.code}, message: ${err.message}`);
    // ...
  });
```

### Listening for Device Connection State Changes

Set a listener to listen for changes of the device connection state. When a device is connected or disconnected, a callback is triggered.

> **NOTE**
>
> The listener captures all changes in device connections. It is not recommended that the changes be used as a basis for handling automatic pausing in applications. If an application needs to manage services related to automatic pause, it should consider the [reasons behind changes in the audio stream output device](audio-output-device-change.md#device-change-reason).

<!-- @[onDeviceChange](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/AudioOutputDeviceManagement.ets) -->  

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

  try {
    // Listen for audio output device status changes.
    audioRoutingManager.on('deviceChange', audio.DeviceFlag.OUTPUT_DEVICES_FLAG, (deviceChanged: audio.DeviceChangeAction) => {
      console.info(`Succeeded in using on function. DeviceChangeAction: ${JSON.stringify(deviceChanged)}`);
      // ...
    });
  } catch (err) {
    let error = err as BusinessError;
    console.error(`Failed to use on function. Code: ${error.code}, message: ${error.message}`);
    // ...
  }
```

<!--Del-->

### Selecting an Audio Output Device (for System Applications only)

Currently, only one output device can be selected, and the device ID is used as the unique identifier. For details about audio device descriptors, see [AudioDeviceDescriptors](../../reference/apis-audio-kit/arkts-apis-audio-t.md#audiodevicedescriptors).

> **NOTE**
>
> The user can connect to a group of audio devices (for example, a pair of Bluetooth headsets), but the system treats them as one device (a group of devices that share the same device ID).

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let outputAudioDeviceDescriptor: audio.AudioDeviceDescriptors = [{
    deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
    deviceType : audio.DeviceType.SPEAKER,
    id : 1,
    name : "",
    address : "",
    sampleRates : [44100],
    channelCounts : [2],
    channelMasks : [0],
    networkId : audio.LOCAL_NETWORK_ID,
    interruptGroupId : 1,
    volumeGroupId : 1,
    displayName : ""
}];

async function selectOutputDevice() {
  audioRoutingManager.selectOutputDevice(outputAudioDeviceDescriptor).then(() => {
    console.info('Invoke selectOutputDevice succeeded.');
  }).catch((err: BusinessError) => {
    console.error(`Invoke selectOutputDevice failed, code is ${err.code}, message is ${err.message}`);
  });
}
```

<!--DelEnd-->

### Obtaining Information About the Output Device with the Highest Priority

Use [getPreferOutputDeviceForRendererInfo](../../reference/apis-audio-kit/arkts-apis-audio-AudioRoutingManager.md#getpreferoutputdeviceforrendererinfo10) to obtain the output device with the highest priority.

> **NOTE**
>
> The output device with the highest priority is the device that will output audio.

<!-- @[getPreferOutputDeviceForRendererInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/AudioOutputDeviceManagement.ets) -->  

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION, // Audio stream usage type: voice communication. Configure based on the service scenario. See StreamUsage.
  rendererFlags: 0 // AudioRenderer flag.
};
// ...

  audioRoutingManager.getPreferOutputDeviceForRendererInfo(audioRendererInfo).
    then((audioDeviceDescriptors: audio.AudioDeviceDescriptors) => {
    console.info(`Succeeded in getting prefer output device for renderer info. AudioDeviceDescriptors: ${JSON.stringify(audioDeviceDescriptors)}`);
    // ...
  }).catch((err: BusinessError) => {
    console.error(`Failed to get prefer output device for renderer info. Code: ${err.code}, message: ${err.message}`);
    // ...
  });
```

### Listening for Changes of the Output Device with the Highest Priority

<!-- @[onPreferOutputDeviceChangeForRendererInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/AudioOutputDeviceManagement.ets) -->  

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION, // Audio stream usage type: voice communication. Configure based on the service scenario. See StreamUsage.
  rendererFlags: 0 // AudioRenderer flag.
};
// ...

  try {
    audioRoutingManager.on('preferOutputDeviceChangeForRendererInfo', audioRendererInfo, (audioDeviceDescriptors: audio.AudioDeviceDescriptors) => {
      console.info(`Succeeded in using on function. DeviceChangeAction: ${JSON.stringify(audioDeviceDescriptors)}`);
      // ...
    });
  } catch (err) {
    let error = err as BusinessError;
    console.error(`Failed to use on function. Code: ${error.code}, message: ${error.message}`);
    // ...
  }
```

## Querying and Listening for Audio Output Devices Using AudioSession

When an app uses an SDK player to play audio streams without holding an [AudioRenderer](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md) object, it cannot flexibly control output device selection or status listening. Starting from API version 20, AudioSession not only adds focus management capabilities but also provides audio output device management features, including setting the default output device and listening for device changes. For more information, see the following documents:

- ArkTS APIs: [AudioSessionManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md)

- C APIs: [native_audio_session_manager.h](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md)

### Creating an AudioSession Instance

Before using AudioSessionManager to manage audio devices, import the module and create an AudioSessionManager instance.

<!-- @[getSessionManager](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/AudioOutputDeviceManagement.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
// ...

let audioManager = audio.getAudioManager();
// ...
let audioSessionManager = audioManager.getSessionManager();
```

### Setting the Default Audio Output Device

Call [setDefaultOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setdefaultoutputdevice20) to set the default output device.
> **NOTE**
> 
> - As AudioSession is an application-level setting, calling this API to set the default audio output device will override the audio output device information set by the **setDefaultOutputDevice** API of AudioRenderer.
> - To cancel the default output device set by calling **setDefaultOutputDevice**, you can set the parameter to **audio.DeviceType.DEFAULT**, which returns the device selection to the system. Otherwise, each time **activateAudioSession** is called, the default output device selected by the application takes effect.

<!-- @[setDefaultOutputDevice](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/AudioOutputDeviceManagement.ets) -->  

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

  // The app sets an audio session scenario suitable for its service scenario. When AudioSession is activated, the system requests the corresponding audio focus based on the audio session scenario selected by the app.
  audioSessionManager.setAudioSessionScene(audio.AudioSessionScene.AUDIO_SESSION_SCENE_VOICE_COMMUNICATION);

  // Set the audio session strategy.
  let strategy: audio.AudioSessionStrategy = {
    concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_MIX_WITH_OTHERS
  };

  // Activate the AudioSession.
  audioSessionManager.activateAudioSession(strategy).then(() => {
    console.info('Succeeded in activating audio session.');
    // ...
  }).catch((err: BusinessError) => {
    console.error(`Failed to activate audio session. Code: ${err.code}, message: ${err.message}`);
    // ...
  });
  // ...

  // Set the default output device to the speaker.
  audioSessionManager.setDefaultOutputDevice(audio.DeviceType.SPEAKER).then(() => {
    console.info('Succeeded in setting default output device.');
    // ...
  }).catch((err: BusinessError) => {
    console.error(`Failed to set default output device. Code: ${err.code}, message: ${err.message}`);
    // ...
  });
  // ...

  // Set the default output device to the earpiece.
  audioSessionManager.setDefaultOutputDevice(audio.DeviceType.EARPIECE).then(() => {
    console.info('Succeeded in setting default output device.');
    // ...
  }).catch((err: BusinessError) => {
    console.error(`Failed to set default output device. Code: ${err.code}, message: ${err.message}`);
    // ...
  });
```

### Obtaining the Default Audio Output Device

Call [getDefaultOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#getdefaultoutputdevice20) to obtain the default output device.
> **NOTE**
>
> This API is used to query the output device set via [setDefaultOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setdefaultoutputdevice20).

<!-- @[getDefaultOutputDevice](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/AudioOutputDeviceManagement.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

  try {
    let deviceType = audioSessionManager.getDefaultOutputDevice();
    console.info(`Succeeded in getting default output device. DeviceType: ${deviceType}`);
    // ...
  } catch (err) {
    let error = err as BusinessError;
    console.error(`Failed to get default output device. Code: ${error.code}, message: ${error.message}`);
    // ...
  }
```

### Listening for Output Device Changes

Subscribe to [CurrentOutputDeviceChangedEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#currentoutputdevicechangedevent20) to listen for changes in the connection status of output devices.

> **NOTE**
>
> `currentOutputDeviceChangedCallback` contains the reason for the device change and the recommended follow-up action. Your app should handle different change reasons accordingly and continue or stop the current playback based on the system's recommendation.

<!-- @[onCurrentOutputDeviceChanged](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/AudioOutputDeviceManagement.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

let currentOutputDeviceChangedCallback = (currentOutputDeviceChangedEvent: audio.CurrentOutputDeviceChangedEvent) => {
  console.info(`Succeeded in using on or off function. CurrentOutputDeviceChangedEvent: ${JSON.stringify(currentOutputDeviceChangedEvent)}`);
  // ...

  switch (currentOutputDeviceChangedEvent.changeReason) {
    case audio.AudioStreamDeviceChangeReason.REASON_OLD_DEVICE_UNAVAILABLE:
      // Respond to the device unavailable event. If the app is in the playback state, pause playback and update the UX.
      break;
    case audio.AudioStreamDeviceChangeReason.REASON_NEW_DEVICE_AVAILABLE:
      // Handle the event where a new device is available based on the application's service logic.
      break;
    case audio.AudioStreamDeviceChangeReason.REASON_OVERRODE:
      // Handle the event where the device is overridden based on the application's service logic.
      break;
    case audio.AudioStreamDeviceChangeReason.REASON_SESSION_ACTIVATED:
      // Respond to the output device information when the audio session is activated based on the service scenario.
      break;
    case audio.AudioStreamDeviceChangeReason.REASON_STREAM_PRIORITY_CHANGED:
      // Handle the event where a higher-priority audio stream triggers a device change based on the application's service logic.
      break;
    case audio.AudioStreamDeviceChangeReason.REASON_UNKNOWN:
      // Handle the event for unknown reasons based on the application's service logic.
      break;
  }
};
// ...

  try {
    audioSessionManager.on('currentOutputDeviceChanged', currentOutputDeviceChangedCallback);
  } catch (err) {
    let error = err as BusinessError;
    console.error(`Failed to use on function. Code: ${error.code}, message: ${error.message}`);
    // ...
  }
```

<!--Del-->

### Obtaining Active Output Device Information (Only Open to System Applications)

Starting from API version 26.0.0, use [getActiveOutputDeviceDescriptors](../../reference/apis-audio-kit/js-apis-audio-sys.md#getactiveoutputdevicedescriptors) to obtain the active output device descriptors in the current audio device scenario.

> **NOTE**
>
> The active devices returned by this API are related to the system's audio device selection policy [AudioStreamDeviceChangeReason](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audiostreamdevicechangereason11).

```typescript
import { audio } from '@kit.AudioKit';  // Import the audio module.
import { BusinessError } from '@kit.BasicServicesKit';

async function getActiveOutputDeviceDescriptors() {
  audioRoutingManager.getActiveOutputDeviceDescriptors().then((audioDeviceDescriptors: audio.AudioDeviceDescriptors) => {
    console.info(`Succeeded in getting active output device descriptors, AudioDeviceDescriptors: ${JSON.stringify(audioDeviceDescriptors)}.`);
    for (let i = 0; i < audioDeviceDescriptors.length; i++) {
      console.info(`Active Device ${i} - id: ${audioDeviceDescriptors[i].id}`);
      console.info(`Active Device ${i} - name: ${audioDeviceDescriptors[i].name}`);
      console.info(`Active Device ${i} - type: ${audioDeviceDescriptors[i].deviceType}`);
      console.info(`Active Device ${i} - role: ${audioDeviceDescriptors[i].deviceRole}`);
      console.info(`Active Device ${i} - address: ${audioDeviceDescriptors[i].address}`);
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get active output device descriptors. Code: ${err.code}, message: ${err.message}`);
  });
}
```

<!--DelEnd-->

<!--no_check-->