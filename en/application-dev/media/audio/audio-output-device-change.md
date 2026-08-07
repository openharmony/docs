# Handling Output Device Changes Gracefully

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @zhanganxiang1-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=b065b5b02aeefe715acab92287399dde4481a96c translatedAt=2026-08-06T01:43:39.322Z pushedAt=2026-08-06T03:52:19.047Z -->

You can listen for audio output device changes and implement appropriate responses. For example, if the output device disconnects during music playback, the application should pause playback immediately to avoid disrupting the user.

You can use [on('outputDeviceChangeWithInfo')](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#onoutputdevicechangewithinfo11) of **AudioRenderer** or [on('currentOutputDeviceChanged')](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#oncurrentoutputdevicechanged20) of **AudioSessionManager** to listen for changes in the audio output device and the associated reason. When the audio output device is changed due to the online/offline status change, forcible user selection, device preemption, or device selection strategy change, the system uses this API to notify the application of the change, including the audio output device information and change reason.

## Audio Output Device Information

The audio device change information returned by [on('outputDeviceChangeWithInfo')](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#onoutputdevicechangewithinfo11) of **AudioRenderer** or [on('currentOutputDeviceChanged')](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#oncurrentoutputdevicechanged20) of **AudioSessionManager** contains the audio output device information, delivered as an array. Typically, this array contains information about only one device. For details, please refer to [AudioDeviceDescriptors](../../reference/apis-audio-kit/arkts-apis-audio-t.md#audiodevicedescriptors) (device information list).

## Device Change Reason

> **NOTE**
> 
> The system sends [AudioStreamDeviceChangeReason](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audiostreamdevicechangereason11) to the application in any of the following cases.

- **REASON_NEW_DEVICE_AVAILABLE**: A new device is available.

  **Trigger conditions**:

  Typical Bluetooth devices (such as headsets, smart glasses, speakers, and telematics devices) are connected; Bluetooth devices that support wear detection (such as headsets and smart glasses) are put on; wired devices (such as 3.5mm headsets, Type-C headsets, USB headsets, and USB speakers) are plugged in; distributed devices are brought online.

- **REASON_OLD_DEVICE_UNAVAILABLE**: The old device is unavailable.

  When this reason is reported, the application should consider pausing audio playback.

  **Trigger conditions**:

  Typical Bluetooth devices (such as headsets, smart glasses, speakers, and telematics devices) are disconnected; Bluetooth devices that support wear detection (such as headsets and smart glasses) are taken off; wired devices (such as 3.5mm headsets, Type-C headsets, USB headsets, and USB speakers) are unplugged; distributed devices are brought offline.

  The handling suggestions for typical service scenarios are as follows:

  - Gaming scenario: Do not pause audio playback.

  - Audiobook scenario: Pause audio playback.

  - Music scenario: Pause audio playback.

  - Video scenario: Pause audio playback.

- **REASON_OVERRODE**: The user forcibly selects a device.

  **Trigger conditions**:

  The user selects another audio output device from the UI, and selects to answer a cellular or VoIP call from the peripheral.

- **REASON_UNKNOWN**: Unknown reason.

## Example

The following examples are code snippets. For the [complete sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample), click the link at the bottom right of each example.

### AudioRenderer Sample

  <!-- @[onOutputDeviceChangeWithInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/AudioOutputDeviceChange.ets) --> 

  ``` TypeScript	
  import { audio } from '@kit.AudioKit';	
  import { BusinessError } from '@kit.BasicServicesKit';	
  // ...
  
  let audioRenderer: audio.AudioRenderer | undefined = undefined;	
  let audioStreamInfo: audio.AudioStreamInfo = {	
    samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // Sampling rate.
    channels: audio.AudioChannel.CHANNEL_2, // Channel.
    sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // Sampling format.
    encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // Encoding format.
  };	
  let audioRendererInfo: audio.AudioRendererInfo = {	
    usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION, // Audio stream usage type: voice communication. Configure based on the service scenario. See StreamUsage.
    rendererFlags: 0 // AudioRenderer flag.
  };	
  let audioRendererOptions: audio.AudioRendererOptions = {	
    streamInfo: audioStreamInfo,	
    rendererInfo: audioRendererInfo	
  };
  // ...

    // Create an AudioRenderer instance.
    audio.createAudioRenderer(audioRendererOptions, (err, renderer) => {
      if (!err) {
        console.info('Succeeded in creating audio renderer.');
        // ...
        audioRenderer = renderer;
        // ...
      } else {
        console.info(`Failed to create audio renderer. Code: ${err.code}, message: ${err.message}`);
        // ...
      }
    });
    // ...
  
    try {
      audioRenderer?.on('outputDeviceChangeWithInfo', (deviceChangeInfo: audio.AudioStreamDeviceChangeInfo) => {
        console.info(`Succeeded in using on function. AudioStreamDeviceChangeInfo: ${JSON.stringify(deviceChangeInfo)}`);
        // ...
        switch (deviceChangeInfo.changeReason) {	
          case audio.AudioStreamDeviceChangeReason.REASON_OLD_DEVICE_UNAVAILABLE:	
            // Respond to the device unavailable event. If the app is in the playback state, pause playback and update the UX.
            audioRenderer?.pause();
            break;	
          case audio.AudioStreamDeviceChangeReason.REASON_NEW_DEVICE_AVAILABLE:	
            // The application responds to the device availability event based on the service status.
            break;	
          case audio.AudioStreamDeviceChangeReason.REASON_OVERRODE:	
            // The application responds to the forcible device selection event based on the service status.
            break;	
          case audio.AudioStreamDeviceChangeReason.REASON_UNKNOWN:	
            // The application responds to the unknown reason event based on the service status.
            break;	
        }
      });
    } catch (err) {
      let error = err as BusinessError;
      console.error(`Failed to use on function. Code: ${error.code}, message: ${error.message}`);
      // ...
    }	
  ```

### AudioSessionManager Sample

  <!-- @[onCurrentOutputDeviceChanged](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/AudioOutputDeviceChange.ets) --> 

  ``` TypeScript
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  // ...
  
  let audioRenderer: audio.AudioRenderer | undefined = undefined;
  let audioStreamInfo: audio.AudioStreamInfo = {
    samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // Sampling rate.
    channels: audio.AudioChannel.CHANNEL_2, // Channel.
    sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // Sampling format.
    encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // Encoding format.
  };
  let audioRendererInfo: audio.AudioRendererInfo = {
    usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION, // Audio stream usage type: voice communication. Configure based on the service scenario. For details, see StreamUsage.
    rendererFlags: 0 // AudioRenderer flag.
  };
  let audioRendererOptions: audio.AudioRendererOptions = {
    streamInfo: audioStreamInfo,
    rendererInfo: audioRendererInfo
  };
  
  let audioSessionManager = audio.getAudioManager().getSessionManager();
  // ...
  
    // Create an AudioRenderer instance.
    audio.createAudioRenderer(audioRendererOptions, (err, renderer) => {
      if (!err) {
        console.info('Succeeded in creating audio renderer.');
        // ...
        audioRenderer = renderer;
        // ...
      } else {
        console.info(`Failed to create audio renderer. Code: ${err.code}, message: ${err.message}`);
        // ...
      }
    });
    // ...
  
    // Set the audio session policy.
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
  
    try {
      // Subscribe to audio output device changes, carrying the change reason.
      audioSessionManager.on('currentOutputDeviceChanged', async (deviceChangeInfo: audio.CurrentOutputDeviceChangedEvent) => {
        console.info(`Succeeded in using on function. AudioStreamDeviceChangeInfo: ${JSON.stringify(deviceChangeInfo)}`);
        // ...
        switch (deviceChangeInfo.changeReason) {
          case audio.AudioStreamDeviceChangeReason.REASON_OLD_DEVICE_UNAVAILABLE:
            // Respond to the device unavailability event. If the application is playing content, pause the playback and update the UX.
            audioRenderer?.pause();
            console.info('REASON_OLD_DEVICE_UNAVAILABLE, pause audio is recommended');
            break;
          case audio.AudioStreamDeviceChangeReason.REASON_NEW_DEVICE_AVAILABLE:
            // The application responds to the device availability event based on the service status.
            break;
          case audio.AudioStreamDeviceChangeReason.REASON_OVERRODE:
            // The application responds to the forcible device selection event based on the service status.
            break;
          case audio.AudioStreamDeviceChangeReason.REASON_UNKNOWN:
            // The application responds to the unknown reason event based on the service status.
            break;
        }
      });
    } catch (err) {
      let error = err as BusinessError;
      console.error(`Failed to use on function. Code: ${error.code}, message: ${error.message}`);
      // ...
    }
  ```