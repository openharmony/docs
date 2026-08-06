# Distributed Audio Playback (for System Applications Only)

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @zhanganxiang1-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=425e79ed59a841b19860caacc0b050f68405d43e translatedAt=2026-08-06T01:50:24.447Z pushedAt=2026-08-06T08:40:06.288Z -->

With distributed audio playback, users can cast audio to a remote device, enabling audio to flow between different devices in the network.

With distributed audio playback, you can cast all audio streams currently playing on this device to a specified remote device, or cast a specific audio stream to a specified remote device.

## How to Develop

Before continuing audio playback on another device in the same network, you must obtain the device list on the network and listen for device connection state changes. For details, see [Querying and Listening for Audio Output Devices](audio-output-device-management.md).

When obtaining the device list on the network, you can specify **DeviceFlag** to filter out the required devices.

| Name| Description| 
| -------- | -------- |
| NONE_DEVICES_FLAG<sup>9+</sup> | No device is available. This is a system API.| 
| OUTPUT_DEVICES_FLAG | Local output device.| 
| INPUT_DEVICES_FLAG | Local input device.| 
| ALL_DEVICES_FLAG | Local input and output device.| 
| DISTRIBUTED_OUTPUT_DEVICES_FLAG<sup>9+</sup> | Remote output device. This is a system API.| 
| DISTRIBUTED_INPUT_DEVICES_FLAG<sup>9+</sup> | Remote input device. This is a system API.| 
| ALL_DISTRIBUTED_DEVICES_FLAG<sup>9+</sup> | Remote input and output device. This is a system API.| 

For details about the APIs, see [AudioRoutingManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioRoutingManager.md).

### Continuing the Playing of All Audio Streams

1. [Obtain the output device information](audio-output-device-management.md#obtaining-output-device-information).

2. Create an AudioDeviceDescriptor instance to describe an audio output device.

3. Call **selectOutputDevice** to cast all audio streams currently playing on this device to the specified remote device.

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioManager = audio.getAudioManager();
let audioRoutingManager = audioManager.getRoutingManager();
let outputAudioDeviceDescriptor: audio.AudioDeviceDescriptors = [{
  deviceRole: audio.DeviceRole.OUTPUT_DEVICE,
  deviceType: audio.DeviceType.SPEAKER,
  id: 1,
  name: "",
  address: "",
  sampleRates: [44100],
  channelCounts: [2],
  channelMasks: [0],
  networkId: "",  // Enter the networkId of the remote device here.
  interruptGroupId: 1,
  volumeGroupId: 1,
  displayName: ""
}];

async function exampleSelectOutputDevice(): Promise<void> {
  audioRoutingManager.selectOutputDevice(outputAudioDeviceDescriptor, (err: BusinessError) => {
    if (err) {
      console.error(`Invoke selectOutputDevice failed, code is ${err.code}, message is ${err.message}`);
    } else {
      console.info('Invoke selectOutputDevice succeeded.');
    }
  });
}
```

### Continuing the Playing of the Specified Audio Stream

1. [Obtain the output device information](audio-output-device-management.md#obtaining-output-device-information).

2. Create an AudioRendererFilter instance, with **uid** to specify an application and **rendererId** to specify an audio stream.

3. Create an AudioDeviceDescriptor instance to describe an audio output device.

4. Call **selectOutputDeviceByFilter** to cast the specified audio stream currently playing on this device to the specified remote device.

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioManager = audio.getAudioManager();
let audioRoutingManager = audioManager.getRoutingManager();
let outputAudioRendererFilter: audio.AudioRendererFilter  = {
  uid: 20010041,
  rendererInfo: {
    usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // Audio stream usage type: music. Set this parameter based on the service scenario.
    rendererFlags: 0 // AudioRenderer flag.
  } as audio.AudioRendererInfo,
  rendererId: 0 // This value is an example. Replace it with the actual ID value.
};

let outputAudioDeviceDescriptor: audio.AudioDeviceDescriptors = [{
  deviceRole: audio.DeviceRole.OUTPUT_DEVICE,
  deviceType: audio.DeviceType.SPEAKER,
  id: 1,
  name: "",
  address: "",
  sampleRates: [44100],
  channelCounts: [2],
  channelMasks: [0],
  networkId: "",  // Enter the networkId of the remote device here.
  interruptGroupId: 1,
  volumeGroupId: 1,
  displayName: ""
}];

async function exampleSelectOutputDeviceByFilter(): Promise<void> {
  audioRoutingManager.selectOutputDeviceByFilter(outputAudioRendererFilter, outputAudioDeviceDescriptor, (err: BusinessError) => {
    if (err) {
      console.error(`Invoke selectOutputDeviceByFilter failed, code is ${err.code}, message is ${err.message}`);
    } else {
      console.info('Invoke selectOutputDeviceByFilter succeeded.');
    }
  });
}
```