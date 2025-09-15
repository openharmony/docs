# Global Audio Input Device Management
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

You can use APIs to manage audio input devices, including querying audio input device information and listening for device connection status changes. For details about the APIs, see [AudioRoutingManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioRoutingManager.md).

## Creating an AudioRoutingManager Instance

Before using AudioRoutingManager to manage audio devices, import the audio module and create an AudioManager instance.

```ts
import { audio } from '@kit.AudioKit';  // Import the audio module.

let audioManager = audio.getAudioManager();  // Create an AudioManager instance.
let audioRoutingManager = audioManager.getRoutingManager();  // Call an API of AudioManager to create an AudioRoutingManager instance.
```

## Supported Audio Input Device Types

The table below lists the supported audio input devices.

| Name| Value| Description| 
| -------- | -------- | -------- |
| WIRED_HEADSET | 3 | Wired headset with a microphone.| 
| BLUETOOTH_SCO | 7 | Bluetooth device using Synchronous Connection Oriented (SCO) links.| 
| MIC | 15 | Microphone.| 
| USB_HEADSET | 22 | USB Type-C headset.| 

## Obtaining Input Device Information

Use **getDevices()** to obtain information about all the input devices.

```ts
import { audio } from '@kit.AudioKit';

audioRoutingManager.getDevices(audio.DeviceFlag.INPUT_DEVICES_FLAG).then((data: audio.AudioDeviceDescriptors) => {
  console.info('Promise returned to indicate that the device list is obtained.');
});
```

## Listening for Device Connection State Changes

Set a listener to listen for changes of the device connection state. When a device is connected or disconnected, a callback is triggered.

```ts
import { audio } from '@kit.AudioKit';

// Listen for connection state changes of audio devices.
audioRoutingManager.on('deviceChange', audio.DeviceFlag.INPUT_DEVICES_FLAG, (deviceChanged: audio.DeviceChangeAction) => {
  console.info('device change type: ' + deviceChanged.type);  // Device connection state change. The value 0 means that the device is connected and 1 means that the device is disconnected.
  console.info('device descriptor size : ' + deviceChanged.deviceDescriptors.length);
  console.info('device change descriptor: ' + deviceChanged.deviceDescriptors[0].deviceRole);  // Device role.
  console.info('device change descriptor: ' + deviceChanged.deviceDescriptors[0].deviceType);  // Device type.
});

// Cancel the listener for the connection state changes of audio devices.
audioRoutingManager.off('deviceChange', (deviceChanged: audio.DeviceChangeAction) => {
  console.info('Should be no callback.');
});
```
<!--Del-->
## Selecting an Audio Input Device (for System Applications only)

Currently, only one input device can be selected, and the device ID is used as the unique identifier. For details about audio device descriptors, see [AudioDeviceDescriptors](../../reference/apis-audio-kit/arkts-apis-audio-t.md#audiodevicedescriptors).

> **NOTE**
> 
> The user can connect to a group of audio devices (for example, a pair of Bluetooth headsets), but the system treats them as one device (a group of devices that share the same device ID).

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let inputAudioDeviceDescriptor: audio.AudioDeviceDescriptors = [{
    deviceRole : audio.DeviceRole.INPUT_DEVICE,
    deviceType : audio.DeviceType.EARPIECE,
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

async function getRoutingManager() {
    audioRoutingManager.selectInputDevice(inputAudioDeviceDescriptor).then(() => {
      console.info('Invoke selectInputDevice succeeded.');
    }).catch((err: BusinessError) => {
      console.error(`Invoke selectInputDevice failed, code is ${err.code}, message is ${err.message}`);
    });
}

```
<!--DelEnd-->
