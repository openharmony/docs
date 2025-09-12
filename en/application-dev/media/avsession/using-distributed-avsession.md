# Using Distributed AVSession (for System Applications Only)
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--SE: @ccfriend-->
<!--TSE: @chenmingxi1_huawei-->

## Basic Concepts

- Remote AVSession: an AVSession automatically created on the remote device by the AVSession service for synchronization with an AVSession on the local device.

- Remote AVSessionController: AVSessionController automatically created on the remote device after projection.

## Available APIs

The table below describes the key APIs used for remote projection with the distributed AVSession. The APIs use either a callback or promise to return the result. The APIs listed below use a callback. They provide the same functions as their counterparts that use a promise.

For details, see [AVSession Management](../../reference/apis-avsession-kit/arkts-apis-avsession.md).

| API| Description|
| -------- | -------- |
| castAudio(session: SessionToken \| 'all', audioDevices: Array&lt;audio.AudioDeviceDescriptor&gt;, callback: AsyncCallback&lt;void&gt;): void | Casts a session to a list of devices.|

## How to Develop

To enable a system application that accesses the AVSession service as the controller to use the distributed AVSession for projection, proceed as follows:

1. Import the modules. Before projection, you must obtain the AudioDeviceDescriptor from the audio module. Therefore, import the audio module and AVSessionManager module.
   
   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   import { audio } from '@kit.AudioKit';
   ```
   
2. Use **castAudio** in the **AVSessionManager** class to project all sessions of the local device to another device.

   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   import { audio } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   async function castAudio() {
     // Cast the sessions to another device.
     let audioManager = audio.getAudioManager();
     let audioRoutingManager = audioManager.getRoutingManager();
     let audioDevices: audio.AudioDeviceDescriptors | undefined = undefined;
     audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
       audioDevices = data;
       console.info(`Promise returned to indicate that the device list is obtained.`);
     }).catch((err: BusinessError) => {
       console.error(`Failed to get devices. Code: ${err.code}, message: ${err.message}`);
     });
     if (audioDevices !== undefined) {
       AVSessionManager.castAudio('all', audioDevices as audio.AudioDeviceDescriptors).then(() => {
         console.info(`createController : SUCCESS`);
       }).catch((err: BusinessError) => {
         console.error(`Failed to cast audio. Code: ${err.code}, message: ${err.message}`);
       });
     }
   }
   
   ```

After the system application on the local service initiates projection to a remote device, the AVSession framework instructs the AVSession service of the remote device to create a remote AVSession. When the AVSession on the local device changes (for example, the media information or playback state changes), the AVSession framework automatically synchronizes the change to the remote device.

The AVSession processing mechanism on the remote device is consistent with that on the local device. That is, the controller (for example, the Media Controller) on the remote device listens for the AVSession creation event, and creates a remote AVSessionController object to manage the remote AVSession. In addition, the control commands are automatically synchronized by the AVSession framework to the local device.

The provider (for example, an audio and video application) on the local device listens for control command events, so as to respond to the commands from the remote device in time.
