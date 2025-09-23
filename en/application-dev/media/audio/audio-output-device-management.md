# Global Audio Output Device Management
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->
Applications can manage global audio output devices in either of the following ways:
- Typically, applications can [manage global audio output devices using AudioRoutingManager](#managing-global-audio-output-devices-with-audioroutingmanager).
- Starting from API version 20, AudioSessionManager offers certain APIs for managing output devices. Applications can now [manage global audio output devices using AudioSession](#managing-global-audio-output-devices-with-audiosession). This is useful for simultaneously managing audio focus and output.
## Managing Global Audio Output Devices with AudioRoutingManager

You can use APIs to manage audio output devices, including querying audio device information and listening for connection status changes. For details about the APIs, see [AudioRoutingManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioRoutingManager.md).

### Creating an AudioRoutingManager Instance

Before using AudioRoutingManager to manage audio devices, import the audio module and create an AudioManager instance.

```ts
import { audio } from '@kit.AudioKit';  // Import the audio module.

let audioManager = audio.getAudioManager();  // Create an AudioManager instance.

let audioRoutingManager = audioManager.getRoutingManager();  // Call an API of AudioManager to create an AudioRoutingManager instance.
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
| USB_HEADSET | 22 | USB Type-C headset.|

### Obtaining Output Device Information

Use **getDevices()** to obtain information about all the output devices.

```ts
import { audio } from '@kit.AudioKit';

audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data: audio.AudioDeviceDescriptors) => {
  console.info('Promise returned to indicate that the device list is obtained.');
});
```

### Listening for Device Connection State Changes

Set a listener to listen for changes of the device connection state. When a device is connected or disconnected, a callback is triggered.

> **NOTE**
>
> The listener captures all changes in device connections. It is not recommended that the changes be used as a basis for handling automatic pausing in applications. If an application needs to manage services related to automatic pause, it should consider the [reasons behind changes in the audio stream output device](audio-output-device-change.md).

```ts
import { audio } from '@kit.AudioKit';

// Listen for connection state changes of audio devices.
audioRoutingManager.on('deviceChange', audio.DeviceFlag.OUTPUT_DEVICES_FLAG, (deviceChanged: audio.DeviceChangeAction) => {
  console.info(`device change type : ${deviceChanged.type}`);  // Device connection state change. The value 0 means that the device is connected and 1 means that the device is disconnected.
  console.info(`device descriptor size : ${deviceChanged.deviceDescriptors.length}`);
  console.info(`device change descriptor : ${deviceChanged.deviceDescriptors[0].deviceRole}`);  // Device role.
  console.info(`device change descriptor : ${deviceChanged.deviceDescriptors[0].deviceType}`);  // Device type.
});

// Cancel the listener for the connection state changes of audio devices.
audioRoutingManager.off('deviceChange');
```

<!--Del-->
### Selecting an Audio Output Device (for System Applications only)

Currently, only one output device can be selected, and the device ID is used as the unique identifier. For details about audio device descriptors, see [AudioDeviceDescriptors](../../reference/apis-audio-kit/arkts-apis-audio-t.md#audiodevicedescriptors).

> **NOTE**
>
> The user can connect to a group of audio devices (for example, a pair of Bluetooth headsets), but the system treats them as one device (a group of devices that share the same device ID).

```ts
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

Call **getPreferOutputDeviceForRendererInfo()** to obtain the output device with the highest priority.

> **NOTE**
>
> The output device with the highest priority is the device that will output audio.

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rendererInfo: audio.AudioRendererInfo = {
    usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // Audio stream usage type: music. Set this parameter based on the service scenario.
    rendererFlags: 0 // AudioRenderer flag.
};

async function getPreferOutputDeviceForRendererInfo() {
  audioRoutingManager.getPreferOutputDeviceForRendererInfo(rendererInfo).then((desc: audio.AudioDeviceDescriptors) => {
    console.info(`device descriptor: ${desc}`);
  }).catch((err: BusinessError) => {
    console.error(`Result ERROR: ${err}`);
  })
}
```

### Listening for Changes of the Output Device with the Highest Priority

```ts
import { audio } from '@kit.AudioKit';

let rendererInfo: audio.AudioRendererInfo = {
    usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // Audio stream usage type: music. Set this parameter based on the service scenario.
    rendererFlags: 0 // AudioRenderer flag.
};

// Listen for changes of the output device with the highest priority.
audioRoutingManager.on('preferOutputDeviceChangeForRendererInfo', rendererInfo, (desc: audio.AudioDeviceDescriptors) => {
    console.info(`device change descriptor : ${desc[0].deviceRole}`);  // Device role.
    console.info(`device change descriptor : ${desc[0].deviceType}`);  // Device type.
});

// Cancel the listening for changes of the output device with the highest priority.
audioRoutingManager.off('preferOutputDeviceChangeForRendererInfo');
```

## Managing Global Audio Output Devices with AudioSession
Applications using the player SDK to play audio streams do not hold an AudioRenderer object. As a result, they cannot flexibly control the selection of playback devices and listen for the device status. Starting from API version 20, AudioSession not only introduces focus management but also provides capabilities for managing audio output devices, including setting the default output device and listening for device changes. For more information, refer to the following documentation:
- ArkTS APIs: [AudiSessionManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md)
- C APIs: [OH_AudioSessionManager](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md)

### Creating an AudioSession Instance
Before using AudioSessionManager to manage audio devices, import the module and create an AudioSessionManager instance.
```ts
import { audio } from '@kit.AudioKit';  // Import the audio module.

let audioManager = audio.getAudioManager();  // Create an AudioManager instance.

let audioSessionManager = audioManager.getSessionManager();  // Call an API of AudioManager to create an AudioSessionManager instance.
```

### Setting the Default Audio Output Device

Call [setDefaultOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setdefaultoutputdevice20) to set the default output device.
> **NOTE**
>- As AudioSession is an application-level setting, calling this API to set the default audio output device will override the audio output device information set by the **setDefaultOutputDevice** API of AudioRenderer.
>- To cancel the default output device set by calling **setDefaultOutputDevice**, you can set the parameter to **audio.DeviceType.DEFAULT**, which returns the device selection to the system. Otherwise, each time **activateAudioSession** is called, the default output device selected by the application takes effect.

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Set the default output device to the device speaker.
audioSessionManager.setDefaultOutputDevice(audio.DeviceType.SPEAKER).then(() => {
  console.info('setDefaultOutputDevice Success!');
}).catch((err: BusinessError) => {
  console.error(`setDefaultOutputDevice Fail: ${err}`);
});

// Set the default output device to the default device, effectively canceling the application's default device setting.
audioSessionManager.setDefaultOutputDevice(audio.DeviceType.DEFAULT).then(() => {
  console.info('setDefaultOutputDevice Success!');
}).catch((err: BusinessError) => {
  console.error(`setDefaultOutputDevice Fail: ${err}`);
});
```

### Obtaining the Default Audio Output Device

Call [getDefaultOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#getdefaultoutputdevice20) to obtain the default output device.
> **NOTE**
>
> This API is used to query the output device set via [setDefaultOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setdefaultoutputdevice20).

```ts
let deviceType = audioSessionManager.getDefaultOutputDevice();
console.info('getDefaultOutputDevice Success, deviceType: ${deviceType}');
```

### Listening for Output Device Changes

Subscribe to [CurrentOutputDeviceChangedEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#currentoutputdevicechangedevent20) to listen for changes in the connection status of output devices.

> **NOTE**
>
> **currentOutputDeviceChangedCallback** includes the reason for the device change and the recommended subsequent actions. Applications should handle different change reasons accordingly and continue or stop playback as recommended by the system.

```ts
import { audio } from '@kit.AudioKit';

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let currentOutputDeviceChangedCallback = (currentOutputDeviceChangedEvent: audio.CurrentOutputDeviceChangedEvent) => {
  console.info(`reason of audioSessionStateChanged: ${currentOutputDeviceChangedEvent.changeReason} `);

  switch (currentOutputDeviceChangedEvent.changeReason) {
    case audio.AudioStreamDeviceChangeReason.REASON_OLD_DEVICE_UNAVAILABLE:
      // Handle the event where the old device is unavailable. If the application is playing, it should pause playback and update the UI.
      break;
    case audio.AudioStreamDeviceChangeReason.REASON_NEW_DEVICE_AVAILABLE:
      // Handle the event where a new device is available based on the application's service logic.
      break;
    case audio.AudioStreamDeviceChangeReason.REASON_OVERRODE:
      // Handle the event where the device is overridden based on the application's service logic.
      break;
    case audio.AudioStreamDeviceChangeReason.REASON_SESSION_ACTIVATED:
      // Handle the event where the audio session is activated based on the application's service logic.
      break;
    case audio.AudioStreamDeviceChangeReason.REASON_STREAM_PRIORITY_CHANGED:
      // Handle the event where a higher-priority audio stream triggers a device change based on the application's service logic.
      break;
    case audio.AudioStreamDeviceChangeReason.REASON_UNKNOWN:
      // Handle the event for unknown reasons based on the application's service logic.
      break;
  }
};

audioSessionManager.on('currentOutputDeviceChanged', currentOutputDeviceChangedCallback);

audioSessionManager.off('currentOutputDeviceChanged', currentOutputDeviceChangedCallback);

// Cancel all subscriptions to the event.
audioSessionManager.off('currentOutputDeviceChanged');
```
