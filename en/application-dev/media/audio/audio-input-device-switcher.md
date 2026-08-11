# Switching Audio Input Devices

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @zhanganxiang1-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=b065b5b02aeefe715acab92287399dde4481a96c translatedAt=2026-08-06T01:42:36.832Z pushedAt=2026-08-06T03:46:35.330Z -->

Starting from API version 21, support for switching audio input device routes is available.

When an application performs audio input, the system selects the corresponding input device based on the audio stream type. (If the audio stream type is **SOURCE_TYPE_MIC**, the built-in microphone is used for recording. If the audio stream type is **SOURCE_TYPE_VOICE_COMMUNICATION**, the input device follows the current output device.) If the default input device does not meet the application requirements, the application can call [setBluetoothAndNearlinkPreferredRecordCategory](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setbluetoothandnearlinkpreferredrecordcategory21) or [selectMediaInputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#selectmediainputdevice21) to switch the audio input device.

The following examples are code snippets. You can obtain the [complete sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample) via the link at the bottom right of each snippet.

## Preferring Bluetooth or NearLink Devices for Recording

Applications can use [setBluetoothAndNearlinkPreferredRecordCategory](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setbluetoothandnearlinkpreferredrecordcategory21) of AudioSessionManager to express a preference for Bluetooth or NearLink devices when they become available.

> **NOTE**
>
> In call scenarios, if a Bluetooth or NearLink device is online, the system uses the Bluetooth or NearLink device as the input device by default.

<!-- @[setBluetoothAndNearlinkPreferredRecordCategory](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/AudioInputDeviceSwitcher.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

let audioManager = audio.getAudioManager();
let audioSessionManager = audioManager.getSessionManager();
// ...

  audioSessionManager.setBluetoothAndNearlinkPreferredRecordCategory(audio.BluetoothAndNearlinkPreferredRecordCategory.
    PREFERRED_DEFAULT).then(() => {
    console.info('Succeeded in setting bluetooth and nearlink preferred record category.');
    // ...
  }).catch((err: BusinessError) => {
    console.error(`Failed to set bluetooth and nearlink preferred record category. Code: ${err.code}, message: ${err.message}`);
    // ...
  });
```

## Manually Selecting Input Devices

Applications can use [selectMediaInputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#selectmediainputdevice21) of AudioSessionManager to select an input device.

> **NOTE**
>
> In call scenarios, the input device follows the current output device, and other concurrent recording streams also follow the call input device.

<!-- @[selectMediaInputDevice](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/AudioInputDeviceSwitcher.ets) -->  

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

let audioManager = audio.getAudioManager();
let audioSessionManager = audioManager.getSessionManager();
// ...

  try {
    // Listen for the current input device change event. This callback is triggered after an input device is successfully selected.
    audioSessionManager.on('currentInputDeviceChanged', (currentInputDeviceChangedEvent: audio.CurrentInputDeviceChangedEvent) => {
      console.info(`Succeeded in using on function. CurrentInputDeviceChangedEvent: ${JSON.stringify(currentInputDeviceChangedEvent)}`);
      // ...
    });
  } catch (err) {
    let error = err as BusinessError;
    console.error(`Failed to use on function. Code: ${error.code}, message: ${error.message}`);
    // ...
  }
  // ...

  try {
    // Listen for the connection status change event of available audio input devices. A callback notification is received when an input device goes online or offline.
    audioSessionManager.on('availableDeviceChange', audio.DeviceUsage.MEDIA_INPUT_DEVICES, (deviceChanged: audio.DeviceChangeAction) => {
      console.info(`Succeeded in using on function. DeviceChangeAction: ${JSON.stringify(deviceChanged)}`);
      // ...
    });
  } catch (err) {
    let error = err as BusinessError;
    console.error(`Failed to use on function. Code: ${error.code}, message: ${error.message}`);
    // ...
  }
  // ...

  try {
    // Obtain the list of currently available audio input devices.
    let data = audioSessionManager.getAvailableDevices(audio.DeviceUsage.MEDIA_INPUT_DEVICES);
    console.info(`Succeeded in getting available devices. AudioDeviceDescriptors: ${JSON.stringify(data)}`);
    // You can select a device when the list of available audio input devices is not empty.
    if (data[1] || data[0]) {
      // Select an input device.
      audioSessionManager.selectMediaInputDevice(data[1] ? data[1] : data[0]).then(() => {
        console.info('Succeeded in selecting media input device.');
        // ...
      }).catch((err: BusinessError) => {
        console.error(`Failed to select media input device. Code: ${err.code}, message: ${err.message}`);
        // ...
      });
    }
  } catch (err) {
    let error = err as BusinessError;
    console.error(`Failed to getAvailableDevices. Code: ${error.code}, message: ${error.message}`);
    // ...
  }
  // ...

  try {
    // You can query whether the input device selection is successful through this API.
    let device = audioSessionManager.getSelectedMediaInputDevice();
    console.info(`Succeeded in getting selected media input device. Device: ${JSON.stringify(device)}`);
    // ...
  } catch (err) {
    let error = err as BusinessError;
    console.error(`Failed to get selected media input device. Code: ${error.code}, message: ${error.message}`);
    // ...
  }
  // ...

  // Clear the input device selected via selectMediaInputDevice.
  audioSessionManager.clearSelectedMediaInputDevice().then(() => {
    console.info('Succeeded in clearing selected media input device.');
    // ...
  }).catch((err: BusinessError) => {
    console.error(`Failed to clear selected media input device. Code: ${err.code}, message: ${err.message}`);
    // ...
  });
```