# Responding to Audio Output Device Changes

To ensure a seamless user experience when there are changes in the audio output device, it is crucial to listen for such changes and adapt accordingly.

You can use [outputDeviceChangeWithInfo](../../reference/apis-audio-kit/js-apis-audio.md#onoutputdevicechangewithinfo11) of the AudioRenderer to listen for audio output device changes and obtain the change reason. When the audio output device is changed due to the online/offline status change, forcible user selection, device preemption, or device selection policy change, the system uses this API to notify the application of the change, including the audio output device information and change reason.

## Audio Output Device Information

[outputDeviceChangeWithInfo](../../reference/apis-audio-kit/js-apis-audio.md#onoutputdevicechangewithinfo11) contains the information about the new audio output device, in the form of an array. Generally, the array contains information about only one device. For details, see [AudioDeviceDescriptors](../../reference/apis-audio-kit/js-apis-audio.md#audiodevicedescriptors).

## Device Change Reason

The system sends [AudioStreamDeviceChangeReason](../../reference/apis-audio-kit/js-apis-audio.md#audiostreamdevicechangereason11) to the application in any of the following cases:

- **REASON_NEW_DEVICE_AVAILABLE**: A new device is available.

  **Trigger conditions**:

  Typical Bluetooth devices (such as headsets, smart glasses, speakers, and telematics devices) are connected; Bluetooth devices that support wear detection (such as headsets and smart glasses) are put on; wired devices (such as 3.5mm headsets, Type-C headsets, USB headsets, and USB speakers) are plugged in; distributed devices are brought online.

- **REASON_OLD_DEVICE_UNAVAILABLE**: The old device is unavailable.

  When this reason is reported, the application should consider pausing audio playback.

  **Trigger conditions**:

  Typical Bluetooth devices (such as headsets, smart glasses, speakers, and telematics devices) are disconnected; Bluetooth devices that support wear detection (such as headsets and smart glasses) are taken off; wired devices (such as 3.5mm headsets, Type-C headsets, USB headsets, and speakers) are unplugged; distributed devices are brought offline.

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

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  let audioRenderer: audio.AudioRenderer | undefined = undefined;
  let audioStreamInfo: audio.AudioStreamInfo = {
    samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // Sampling rate.
    channels: audio.AudioChannel.CHANNEL_2, // Channel.
    sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // Sampling format.
    encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // Encoding format.
  };
  let audioRendererInfo: audio.AudioRendererInfo = {
    usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // Audio stream usage type: music. Set this parameter based on the service scenario.
    rendererFlags: 0 // AudioRenderer flag.
  };
  let audioRendererOptions: audio.AudioRendererOptions = {
    streamInfo: audioStreamInfo,
    rendererInfo: audioRendererInfo
  };
  
  // Create an AudioRenderer instance.
  audio.createAudioRenderer(audioRendererOptions).then((data) => {
    audioRenderer = data;
    console.info('AudioFrameworkRenderLog: AudioRenderer Created : Success : Stream Type: SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`AudioFrameworkRenderLog: AudioRenderer Created : ERROR : ${err}`);
  });
  
  if (audioRenderer) {
    // Subscribe to audio output device changes, carrying the change reason.
    (audioRenderer as audio.AudioRenderer).on('outputDeviceChangeWithInfo', async (deviceChangeInfo: audio.AudioStreamDeviceChangeInfo) => {
      switch (deviceChangeInfo.changeReason) {
        case audio.AudioStreamDeviceChangeReason.REASON_OLD_DEVICE_UNAVAILABLE:
          // Respond to the device unavailability event. If the application is playing content, pause the playback and update the UX.
          // await audioRenderer.pause();
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
  }
  ```
