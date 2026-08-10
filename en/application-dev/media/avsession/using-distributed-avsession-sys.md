# Using Distributed AVSession (for System Applications Only)

<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @devil_red-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=4575f288d13c429dbede3c0b33d0bfd71bcb7755 translatedAt=2026-08-10T03:47:44.115Z pushedAt=2026-08-10T08:38:26.914Z -->

## Basic Concepts

- Remote AVSession: an AVSession automatically created on the remote device by the AVSession service for synchronization with an AVSession on the local device.

- Remote AVSessionController: AVSessionController automatically created on the remote device after projection.

## Available APIs

The table below describes the key APIs used for remote projection with the distributed AVSession. The APIs use either a callback or promise to return the result. The APIs listed below use a callback. They provide the same functions as their counterparts that use a promise.

For more API details, see [Module Description](../../reference/apis-avsession-kit/arkts-apis-avsession.md).

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

2. Use **castAudio** in **AVSessionManager** to project all sessions of the local device to another device.

   ```ts
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   import { audio } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   async function castAudio() {
     let audioManager = audio.getAudioManager();
     let audioRoutingManager = audioManager.getRoutingManager();
     try {
       let audioDevices = await audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG);
       console.info(`Promise returned to indicate that the device list is obtained.`);
       if (audioDevices !== undefined) {
         await AVSessionManager.castAudio('all', audioDevices);
         console.info(`castAudio : SUCCESS`);
       }
     } catch (err) {
       let error = err as BusinessError;
       console.error(`Failed to get devices or cast audio. Code: ${error.code}, message: ${error.message}`);
     }
   }
   ```

After the system application on the local service initiates projection to a remote device, the AVSession framework instructs the AVSession service of the remote device to create a remote AVSession. When the AVSession on the local device changes (for example, the media information or playback state changes), the AVSession framework automatically synchronizes the change to the remote device.

The AVSession processing mechanism on the remote device is consistent with that on the local device. That is, the controller (for example, the Media Controller) on the remote device listens for the AVSession creation event, and creates a remote AVSessionController object to manage the remote AVSession. In addition, the control commands are automatically synchronized by the AVSession framework to the local device.

The provider (for example, an audio and video application) on the local device listens for control command events, so as to respond to the commands from the remote device in time.