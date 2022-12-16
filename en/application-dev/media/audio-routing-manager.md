# Audio Routing and Device Management Development

## Overview

The **AudioRoutingManager** module provides APIs for audio routing and device management. You can use the APIs to obtain the current input and output audio devices, listen for connection status changes of audio devices, and activate communication devices.

## Working Principles

The figure below shows the common APIs provided by the **AudioRoutingManager** module.

**Figure 1** Common APIs of AudioRoutingManager

![en-us_image_audio_routing_manager](figures/en-us_image_audio_routing_manager.png)

You can use these APIs to obtain the device list, subscribe to or unsubscribe from device connection status changes, activate communication devices, and obtain their activation status. For details, see [Audio Management](../reference/apis/js-apis-audio.md).


## How to Develop

For details about the APIs, see [AudioRoutingManager in Audio Management](../reference/apis/js-apis-audio.md#audioroutingmanager9).

1. Obtain an **AudioRoutingManager** instance.

   Before using an API in **AudioRoutingManager**, you must use **getRoutingManager()** to obtain an **AudioRoutingManager** instance.

   ```js
   import audio from '@ohos.multimedia.audio';
   async loadAudioRoutingManager() {
     var audioRoutingManager = await audio.getAudioManager().getRoutingManager();
     console.info('audioRoutingManager------create-------success.');
   }

   ```

2. (Optional) Obtain the device list and subscribe to device connection status changes.
   
   To obtain the device list (such as input, output, distributed input, and distributed output devices) or listen for connection status changes of audio devices, refer to the following code:

   ```js
   import audio from '@ohos.multimedia.audio';
   // Obtain an AudioRoutingManager instance.
   async loadAudioRoutingManager() {
     var audioRoutingManager = await audio.getAudioManager().getRoutingManager();
     console.info('audioRoutingManager------create-------success.');
   }
   // Obtain information about all audio devices. (You can set DeviceFlag as required.)
   async getDevices() {
     await loadAudioRoutingManager();
     await audioRoutingManager.getDevices(audio.DeviceFlag.ALL_DEVICES_FLAG).then((data) => {
       console.info(`getDevices success and data is: ${JSON.stringify(data)}.`);
     });
    }
   // Subscribe to connection status changes of audio devices.
   async onDeviceChange() {  
     await loadAudioRoutingManager();
     await audioRoutingManager.on('deviceChange', audio.DeviceFlag.ALL_DEVICES_FLAG, (deviceChanged) => {
       console.info('on device change type : ' + deviceChanged.type);
       console.info('on device descriptor size : ' + deviceChanged.deviceDescriptors.length);
       console.info('on device change descriptor : ' + deviceChanged.deviceDescriptors[0].deviceRole);
       console.info('on device change descriptor : ' + deviceChanged.deviceDescriptors[0].deviceType);
     });
   }
   // Unsubscribe from the connection status changes of audio devices.
   async offDeviceChange() {  
     await loadAudioRoutingManager();
     await audioRoutingManager.off('deviceChange', (deviceChanged) => {
       console.info('off device change type : ' + deviceChanged.type);
       console.info('off device descriptor size : ' + deviceChanged.deviceDescriptors.length);
       console.info('off device change descriptor : ' + deviceChanged.deviceDescriptors[0].deviceRole);
       console.info('off device change descriptor : ' + deviceChanged.deviceDescriptors[0].deviceType);
     });
   }
   // Complete process: Call APIs to obtain all devices and subscribe to device changes, then manually change the connection status of a device (for example, wired headset), and finally call APIs to obtain all devices and unsubscribe from the device changes.
   async test(){  
     await getDevices();
     await onDeviceChange()();
     // Manually disconnect or connect devices.
     await getDevices();
     await offDeviceChange();
   }
   ```

3. (Optional) Activate a communication device and obtain its activation status.

   ```js
   import audio from '@ohos.multimedia.audio';
   // Obtain an AudioRoutingManager instance.
   async loadAudioRoutingManager() {
     var audioRoutingManager = await audio.getAudioManager().getRoutingManager();
     console.info('audioRoutingManager------create-------success.');
   }
   // Activate a communication device.
   async setCommunicationDevice() {  
     await loadAudioRoutingManager();
     await audioRoutingManager.setCommunicationDevice(audio.CommunicationDeviceType.SPEAKER, true).then(() => {
       console.info('setCommunicationDevice true is success.');
     });
   }
   // Obtain the activation status of the communication device.
   async isCommunicationDeviceActive() {   
     await loadAudioRoutingManager();
     await audioRoutingManager.isCommunicationDeviceActive(audio.CommunicationDeviceType.SPEAKER).then((value) => {
       console.info(`CommunicationDevice state is: ${value}.`);
     });
   }
   // Complete process: Activate a device and obtain the activation status.
   async test(){  
     await setCommunicationDevice();
     await isCommunicationDeviceActive();
   }
   ```   
