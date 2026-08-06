# Querying and Listening for Audio Input Devices

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @zhanganxiang1-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=b065b5b02aeefe715acab92287399dde4481a96c translatedAt=2026-08-06T01:42:32.933Z pushedAt=2026-08-06T06:24:30.073Z -->

You can use APIs to manage audio input devices, including querying audio input device information and listening for device connection status changes. For details about the APIs, see [AudioRoutingManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioRoutingManager.md).

The following examples are code snippets. For the [complete sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample), click the link at the lower right of each code snippet.

## Creating an AudioRoutingManager Instance

Before using AudioRoutingManager to manage audio devices, import the audio module and create an instance.

<!-- @[getRoutingManager](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/AudioInputDeviceManagement.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
// ...

let audioManager = audio.getAudioManager();
let audioRoutingManager = audioManager.getRoutingManager();
```

## Supported Audio Input Device Types

The table below lists the supported audio input devices.

| Name| Value| Description|
| -------- | -------- | -------- |
| WIRED_HEADSET | 3 | Wired headset with a microphone.|
| BLUETOOTH_SCO | 7 | Bluetooth device using Synchronous Connection Oriented (SCO) links.|
| MIC | 15 | Microphone.|
| USB_HEADSET | 22 | USB headset with a microphone. |
| NEARLINK | 31 | NearLink device. |

## Obtaining Input Device Information

Use the [getDevices](../../reference/apis-audio-kit/arkts-apis-audio-AudioRoutingManager.md#getdevices9) method to obtain information about all current input devices.

<!-- @[getDevices](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/AudioInputDeviceManagement.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

  audioRoutingManager.getDevices(audio.DeviceFlag.INPUT_DEVICES_FLAG).then((audioDeviceDescriptors: audio.
    AudioDeviceDescriptors) => {
    console.info(`Succeeded in getting devices. AudioDeviceDescriptors: ${JSON.stringify(audioDeviceDescriptors)}`);
    // ...
  }).catch((err: BusinessError) => {
    console.error(`Failed to get devices. Code: ${err.code}, message: ${err.message}`);
    // ...
  });
```

## Listening for Device Connection State Changes

Set a listener to listen for changes of the device connection state. When a device is connected or disconnected, a callback is triggered.

<!-- @[onDeviceChange](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/AudioInputDeviceManagement.ets) -->  

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

let deviceChangeCallback = (deviceChanged: audio.DeviceChangeAction) => {
  console.info(`Succeeded in using on function. DeviceChangeAction: ${JSON.stringify(deviceChanged)}`);
  // ...
}
// ...

  try {
    // Listen for audio device state changes.
    audioRoutingManager.on('deviceChange', audio.DeviceFlag.INPUT_DEVICES_FLAG, deviceChangeCallback);
  } catch (err) {
    let error = err as BusinessError;
    console.error(`Failed to use on function. Code: ${error.code}, message: ${error.message}`);
    // ...
  }
```

<!--Del-->

## Selecting an Audio Input Device (for System Applications only)

Currently, only one input device can be selected, and the device ID is used as the unique identifier. For details about audio device descriptors, see [AudioDeviceDescriptors](../../reference/apis-audio-kit/arkts-apis-audio-t.md#audiodevicedescriptors).

> **NOTE**
> 
> The user can connect to a group of audio devices (for example, a pair of Bluetooth headsets), but the system treats them as one device (a group of devices that share the same device ID).

``` TypeScript
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