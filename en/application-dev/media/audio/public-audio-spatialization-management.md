# Spatial Audio Capability Query and Status Subscription

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @tom_guo-->
<!--Designer: @trytocalm-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=233316920aae5dc32b6b09f705ac05617f921672 translatedAt=2026-08-06T01:53:02.139Z pushedAt=2026-08-06T08:55:21.299Z -->

Starting from API version 18, you can query the spatial audio capabilities and subscribe to their status changes.

Spatial audio is an advanced audio technology that transforms traditional stereo sound into a three-dimensional experience. It enhances monaural, stereo, and surround sound by adding a sense of height, delivering an all-encompassing audio experience. Spatial audio immerses users in an interactive, spatially aware soundscape, making them feel as though they are truly present in the audio environment.

Audio Vivid is an AI-driven audio codec standard. It is jointly formulated and released by the UHD World Association (UWA) and the Audio and Video Coding Standard Working Group (AVS). This audio format contains audio Pulse-Code Modulation (PCM) data and metadata, offering a more immersive listening experience over traditional stereo sources. Audio Vivid contains metadata information of audio content sources, which can reproduce the true auditory sensations of the physical and perceptual world.

Spatial audio supports playback of multi-channel, stereo, and Audio Vivid formats, and can render binaural spatial audio through headphones. When paired with Audio Vivid format sources, spatial audio rendering can treat vocals and various instruments in music as independent sound objects. It redefines the position, movement trajectory, and volume of these sound objects, creating a fully immersive experience where sound surrounds and envelops the listener from all directions, including above. This provides a more immersive spatial audio experience, akin to being in a cinema or concert hall. When a device supports spatial audio and the spatial audio feature is enabled, playing Audio Vivid format sources can enhance the audio experience. For details about how to play Audio Vivid sources, see [Playing Audio Files in Audio Vivid Format](using-ohaudio-for-playback.md#playing-audio-files-in-audio-vivid-format).

The following examples are code snippets. For the [complete sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioRendererSampleJS), click the link at the bottom right of the example.

## How to Use

For audio playback apps, you can check whether the device supports spatial audio and the current spatial audio toggle state of the device.

### Obtaining a Spatial Audio Example

Before using any APIs of AudioSpatializationManager, you must call [getSpatializationManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioManager.md#getspatializationmanager18) to obtain an AudioSpatializationManager instance.

<!-- @[get_spacesound](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleJS/entry/src/main/ets/pages/renderer.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
// ...
let audioManager = audio.getAudioManager();
// ...
let audioSpatializationManager = audioManager.getSpatializationManager();
```

### Checking Whether a Device Supports Spatial Audio Rendering

Use the **spatializationSupported** property in [AudioDeviceDescriptor](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiodevicedescriptor) to check whether a specified device supports spatial audio rendering. You need to use other audio APIs to obtain AudioDeviceDescriptor of a connected device or the current audio device. For example, you can use [getDevicesSync](../../reference/apis-audio-kit/arkts-apis-audio-AudioRoutingManager.md#getdevicessync10) of the AudioRoutingManager instance created by [getRoutingManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioManager.md#getroutingmanager9) to obtain AudioDeviceDescriptor.

<!-- @[check_spacesound](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleJS/entry/src/main/ets/pages/renderer.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
// ...
let audioRoutingManager = audioManager.getRoutingManager();
// ...
  let deviceDescriptors = audioRoutingManager.getDevicesSync(audio.DeviceFlag.OUTPUT_DEVICES_FLAG);
  console.info(`Succeeded in getting devices, AudioDeviceDescriptors: ${JSON.stringify(deviceDescriptors)}.`);
```

### Checking the Status of Spatial Audio Rendering of the Current Device

Call [isSpatializationEnabledForCurrentDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioSpatializationManager.md#isspatializationenabledforcurrentdevice18) to check whether spatial audio rendering is enabled for the current device.

- If **true** is returned, spatial audio rendering is enabled for the current device. If **false** is returned, it is disabled.

- Spatial audio rendering takes effect only when the current device supports spatial audio rendering.

<!-- @[check_isspacesoundon](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleJS/entry/src/main/ets/pages/renderer.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
// ...
  let isSpatializationEnabledForCurrentDevice = audioSpatializationManager.isSpatializationEnabledForCurrentDevice();
  console.info(`Succeeded in checking spatialization enabled for current device is: ${isSpatializationEnabledForCurrentDevice}.`);
```

### Subscribing to Status Change Events of Spatial Audio Rendering for the Current Device

Call [on('spatializationEnabledChangeForCurrentDevice')](../../reference/apis-audio-kit/arkts-apis-audio-AudioSpatializationManager.md#onspatializationenabledchangeforcurrentdevice18) to subscribe to the spatial audio rendering status change event of the current device.

If **true** is returned, spatial audio rendering is enabled. If **false** is returned, it is disabled.

<!-- @[regist_spacesoundcallback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleJS/entry/src/main/ets/pages/renderer.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
// ...
  audioSpatializationManager.on('spatializationEnabledChangeForCurrentDevice',
    (isSpatializationEnabledForCurrentDevice: boolean) => {
    console.info(`Succeeded in using isSpatializationEnabledForCurrentDevice: ${isSpatializationEnabledForCurrentDevice}.`);
    // ...
  });
```

### Unsubscribing from Status Change Events of Spatial Audio Rendering for the Current Device

Call [off('spatializationEnabledChangeForCurrentDevice')](../../reference/apis-audio-kit/arkts-apis-audio-AudioSpatializationManager.md#offspatializationenabledchangeforcurrentdevice18) to unsubscribe from the spatial audio rendering status change event of the current device.

<!-- @[unregist_spacesoundcallback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleJS/entry/src/main/ets/pages/renderer.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
// ...
  audioSpatializationManager.off('spatializationEnabledChangeForCurrentDevice');
```