# Using Distributed AVSession

## Basic Concepts

- Remote AVSession: an AVSession automatically created on the remote device by the AVSession service for synchronization with an AVSession on the local device.

- Remote AVSessionController: AVSessionController automatically created on the remote device after projection.

## Available APIs

The table below describes the key APIs used for remote projection with the distributed AVSession. The APIs use either a callback or promise to return the result. The APIs listed below use a callback. They provide the same functions as their counterparts that use a promise.

For details, see [AVSession Management](../reference/apis/js-apis-avsession.md).

| API| Description| 
| -------- | -------- |
| castAudio(session: SessionToken \| 'all', audioDevices: Array&lt;audio.AudioDeviceDescriptor&gt;, callback: AsyncCallback&lt;void&gt;): void | Casts a session to a list of devices.| 

## How to Develop

To enable a system application that accesses the AVSession service as the controller to use the distributed AVSession for projection, proceed as follows:

1. Import the modules. Before projection, you must obtain the AudioDeviceDescriptor from the audio module. Therefore, import the audio module and AVSessionManager module.
     
   ```ts
   import AVSessionManager from '@ohos.multimedia.avsession';
   import audio from '@ohos.multimedia.audio';
   ```

2. Use **castAudio** in the **AVSessionManager** class to project all sessions of the local device to another device.
     
   ```ts
   // Cast the sessions to another device.
   let audioManager = audio.getAudioManager();
   let audioRoutingManager = audioManager.getRoutingManager();
   let audioDevices;
   await audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
      audioDevices = data;
      console.info('Promise returned to indicate that the device list is obtained.');
   }).catch((err) => {
      console.info(`getDevices : ERROR : ${err.message}`);
   });
   
   AVSessionManager.castAudio('all', audioDevices).then(() => {
      console.info('createController : SUCCESS');
   }).catch((err) => {
      console.info(`createController : ERROR : ${err.message}`);
   });
   ```

   After the system application on the local service initiates projection to a remote device, the AVSession framework instructs the AVSession service of the remote device to create a remote AVSession. When the AVSession on the local device changes (for example, the media information or playback state changes), the AVSession framework automatically synchronizes the change to the remote device.

   The AVSession processing mechanism on the remote device is consistent with that on the local device. That is, the controller (for example, the Media Controller) on the remote device listens for the AVSession creation event, and creates a remote **AVSessionController** object to manage the remote AVSession. In addition, the control commands are automatically synchronized by the AVSession framework to the local device.

   The provider (for example, an audio and video application) on the local device listens for control command events, so as to respond to the commands from the remote device in time.
