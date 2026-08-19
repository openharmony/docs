# Switching Audio Output Devices

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @zhanganxiang1-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=6a4a729ec6a0e268d35d21b1aad24f8f25982c16 translatedAt=2026-08-18T11:03:42.555Z pushedAt=2026-08-18T11:47:10.379Z -->

When an app outputs audio, the system automatically matches the corresponding output device based on the audio stream type. If the system output device does not meet the app's requirements, the app can implement audio output device routing switch through `AVCastPicker` or `setDefaultOutputDevice`. When an external audio device (such as a Bluetooth headset or a wired headset) is connected, the app can also force media output to switch to the speaker through `setMediaOutputDevice`.

## When to Use

1. If an app needs to provide a visual and interactive entry for switching audio output devices, you can use the `AVCastPicker` component. Simply place this component in the layout, and the system automatically detects the list of currently available audio output devices. The user can then tap to complete the routing switch.

2. Apps have different requirements for the default output device in different scenarios. For example, voice message streams are typically played through the speaker by default so that users can listen directly. However, in certain private scenarios, an app may want to set voice messages to play through the earpiece by default to protect user privacy. In such cases, you can use the `setDefaultOutputDevice` API to flexibly change the default output device for voice messages to meet specific business requirements.

3. When an external device such as a Bluetooth headset or a wired headset is connected, the system plays audio from the external device by priority. However, in some scenarios, the app expects to force media audio to switch to the speaker even when an external device is connected (for example, playing real-time translation to the other party). Starting from API version 26.0.0, you can call the `setMediaOutputDevice` API to force the media output device to switch to the speaker by setting the parameter to `audio.DeviceType.SPEAKER` when an external device is connected. To restore the system default routing, call the `setMediaOutputDevice` API again and set the parameter to `audio.DeviceType.DEFAULT`.

## Switching Output Device Routing for Media Streams

Apps can use the [AVCastPicker](../../reference/apis-avsession-kit/ohos-multimedia-avcastpicker.md#avcastpicker) component to provide users with an entry for selecting a device.

This component integrates capabilities such as device discovery, connection, and authentication, and can be embedded into the app UI. When the user taps it, the system automatically identifies and displays the list of currently switchable devices, supporting seamless switching among output devices such as speakers, headphones, and smart speakers.

## Switching Output Device Routing for Call Streams

The `AVCastPicker` component is also applicable to call scenarios. Apps can [use the call device switching component](../avsession/using-switch-call-devices.md) to provide users with an entry for switching among call devices such as the earpiece, speaker, and headphones, allowing users to flexibly adjust the audio output device during a call.

## Setting the Default Output Device

If no external device (such as a Bluetooth headset) is connected, audio is played through the earpiece by default in voice call scenarios and through the speaker in other scenarios. After an external device is connected, the system prioritizes playback through the external device. Apps can change the default output device by calling `setDefaultOutputDevice`, but this takes effect only for the following three [StreamUsage](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage) types:

| Name | Value | Description |
| -------- | -------- | -------- |
| STREAM_USAGE_VOICE_MESSAGE | 5 | Voice message. |
| STREAM_USAGE_VOICE_COMMUNICATION | 2 | VoIP voice call. |
| STREAM_USAGE_VIDEO_COMMUNICATION | 17 | VoIP video call. |

Supported device types:

| Name | Value | Description |
| -------- | -------- | -------- |
| EARPIECE | 1 | Earpiece. |
| SPEAKER | 2 | Speaker. |
| DEFAULT | 1000 | Follow the system. |

After this API is called, the system records the specified default output device. When no external device is connected, the audio stream is routed to the specified default output device for playback. When an external device is connected, the system prioritizes playback through the external device, and automatically switches back to the configured default output device after the external device is disconnected.

### How to Develop

Both `AudioRenderer` and `AudioSessionManager` provide the `setDefaultOutputDevice` API for setting the default output device for calls or voice.

- Audio stream level: The `AudioRenderer` API takes effect at the individual stream level, affecting only the audio stream corresponding to the current `AudioRenderer` instance.

- App level: The `AudioSessionManager` API takes effect for all voice and call audio streams within the current app, not limited to a single `AudioRenderer` instance.

The app-level API has a higher priority than the audio stream-level API. If both APIs are called, the `AudioSessionManager` setting overrides the `AudioRenderer` setting, and the `AudioRenderer` setting no longer takes effect.

**Audio Stream-Level Setting API**

Starting from API version 12, apps can use the [setDefaultOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#setdefaultoutputdevice12) API of AudioRenderer to set the default device to the earpiece or speaker. Before calling this API, you need to obtain an [AudioRenderer](../../reference/apis-audio-kit/arkts-apis-audio-f.md#audiocreateaudiorenderer8) instance. The lifecycle of the default device setting follows the audio stream. To cancel the default output device set by calling `setDefaultOutputDevice`, you can set the parameter to `audio.DeviceType.DEFAULT`, which returns the audio output device selection to the system.

   > **NOTE**
   >
   > - AudioRenderer operates at the stream level. Therefore, the default audio output device set via this API takes effect only for the current stream.
   > - This API has a lower priority than [setDefaultOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setdefaultoutputdevice20) of AudioSessionManager. If [setDefaultOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setdefaultoutputdevice20) of AudioSessionManager has been used to set the default audio output device, the settings made via this API do not take effect.

   <!-- @[audioRenderer_setDefaultOutputDevice](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/AudioOutputDeviceSwitcher.ets) -->  

   ``` TypeScript
   import { audio } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   // ...
   
       // Set the default output device to the speaker.
       audioRenderer.setDefaultOutputDevice(audio.DeviceType.SPEAKER).then(() => {
         console.info('Succeeded in setting default output device.');
         // ...
       }).catch((err: BusinessError) => {
         console.error(`Failed to set default output device. Code: ${err.code}, message: ${err.message}`);
         // ...
       });
       // ...
   
       // Set the default output device to the earpiece.
       audioRenderer.setDefaultOutputDevice(audio.DeviceType.EARPIECE).then(() => {
         console.info('Succeeded in setting default output device.');
         // ...
       }).catch((err: BusinessError) => {
         console.error(`Failed to set default output device. Code: ${err.code}, message: ${err.message}`);
         // ...
       });
   ```

**App-Level Setting API**

Starting from API version 20, after activating an [AudioSession](../audio/audio-session-management.md), apps can use the [setDefaultOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setdefaultoutputdevice20) API of AudioSessionManager to set the default output device, and check whether the default device is set successfully through `AudioSessionManager.getDefaultOutputDevice`. The lifecycle of the default device setting follows the `AudioSession`. To cancel the default output device set by calling `setDefaultOutputDevice`, you can set the parameter to `audio.DeviceType.DEFAULT`, which returns the audio output device selection to the system.

   > **NOTE**
   >
   > AudioSessionManager operates at the application level. Therefore, calling this API to set the default audio output device takes effect for all applicable audio streams within the current application and overrides the default audio output device settings made via [setDefaultOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#setdefaultoutputdevice12) of AudioRenderer.

   <!-- @[audioSessionManager_setDefaultOutputDevice](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/AudioOutputDeviceSwitcher.ets) -->  

   ``` TypeScript
   import { audio } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   // ...
   
   let audioManager = audio.getAudioManager();
   let audioSessionManager = audioManager.getSessionManager();
   // ...
   
     // The app sets an audio session scene that suits its business scenario. When AudioSession is activated, the system requests the corresponding audio focus based on the audio session scene selected by the app.
     audioSessionManager.setAudioSessionScene(audio.AudioSessionScene.AUDIO_SESSION_SCENE_VOICE_COMMUNICATION);
   
     // Set the audio session strategy.
     let strategy: audio.AudioSessionStrategy = {
       concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_MIX_WITH_OTHERS
     };
   
     // Activate AudioSession.
     audioSessionManager.activateAudioSession(strategy).then(() => {
       console.info('Succeeded in activating audio session.');
       // ...
     }).catch((err: BusinessError) => {
       console.error(`Failed to activate audio session. Code: ${err.code}, message: ${err.message}`);
       // ...
     });
     // ...
   
     // Set the default output device to the speaker.
     audioSessionManager.setDefaultOutputDevice(audio.DeviceType.SPEAKER).then(() => {
       console.info('Succeeded in setting default output device.');
       // ...
     }).catch((err: BusinessError) => {
       console.error(`Failed to set default output device. Code: ${err.code}, message: ${err.message}`);
       // ...
     });
     // ...
   
     // Set the default output device to the earpiece.
     audioSessionManager.setDefaultOutputDevice(audio.DeviceType.EARPIECE).then(() => {
       console.info('Succeeded in setting default output device.');
       // ...
     }).catch((err: BusinessError) => {
       console.error(`Failed to set default output device. Code: ${err.code}, message: ${err.message}`);
       // ...
     });
   ```

## Forcing Media Output Device Switching When an External Device Is Connected

When the system is connected to an external device such as a Bluetooth headset or a wired headset, the system plays from the external device by priority. Starting from API version 26.0.0, an app can use [setMediaOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setmediaoutputdevice) of `AudioSessionManager` to force the media output device to switch to the speaker, so that audio is still played from the speaker even when an external device is connected.

   > **NOTE**
   >
   > - This API takes effect only on media streams and applies to all media streams in the app. Call streams are not affected. The app must be in the foreground and have a running media stream; otherwise, the setting does not take effect and is automatically cleared after the app exits.
   > - The output device set by this API and the output device set in [Switching Output Device Routing for Media Streams](#switching-output-device-routing-for-media-streams) overwrite each other (the one called later overwrites the output device set by the one called earlier).
   > - The output device set by this API does not overwrite the output device set in [Setting the Default Output Device](#setting-the-default-output-device).
   > - You can listen for the [CurrentOutputDeviceChangedEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#currentoutputdevicechangedevent20) event to obtain the current output device information and check whether the configured output device takes effect.
   > - On devices without a built-in speaker (such as a smart screen), calling this API to switch the output device to the speaker does not take effect, but the API call still returns success and does not throw an error or trigger an error callback.

### How to Develop

An app can use [setMediaOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setmediaoutputdevice) of `AudioSessionManager` to force the media output device to switch to the speaker. After calling `setMediaOutputDevice`, to cancel the forced switching and restore the system default routing rule, set the parameter to `audio.DeviceType.DEFAULT`.

Supported device types:

| Name | Value | Description |
| -------- | -------- | -------- |
| SPEAKER | 2 | Speaker. Forces media output to switch to the speaker. |
| DEFAULT | 1000 | System default device. Clears the forced switch and restores the system default routing policy. |

   <!-- @[audioSessionManager_setMediaOutputDevice](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/AudioOutputDeviceSwitcher.ets) -->

   ``` TypeScript
   import { audio } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   // ...
   
   let audioManager = audio.getAudioManager();
   let audioSessionManager = audioManager.getSessionManager();
   // ...
   
     // After a Bluetooth headset is connected, force the media output device to switch to the speaker.
     audioSessionManager.setMediaOutputDevice(audio.DeviceType.SPEAKER).then(() => {
       console.info('Succeeded in setting media output device to speaker.');
       // ...
     }).catch((err: BusinessError) => {
       console.error(`Failed to set media output device. Code: ${err.code}, message: ${err.message}`);
       // ...
     });
     // ...
   
     // Cancel the forced switch and return the media output device selection to the system default routing rules.
     audioSessionManager.setMediaOutputDevice(audio.DeviceType.DEFAULT).then(() => {
       console.info('Succeeded in setting media output device to default.');
       // ...
     }).catch((err: BusinessError) => {
       console.error(`Failed to set media output device. Code: ${err.code}, message: ${err.message}`);
       // ...
     });
   ```

The above are code snippets for each feature implementation. You can obtain the [complete sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample) through the link at the bottom right of the sample code.