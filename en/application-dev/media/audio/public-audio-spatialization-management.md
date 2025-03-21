# Spatial Audio Management

Spatial audio management primarily involves querying the support for spatial audio rendering, querying its enabled or disabled status, and listening for its status changes.

## How to Use

Before using any APIs of **AudioSpatializationManager**, you must call [getSpatializationManager](../../reference/apis-audio-kit/js-apis-audio.md#getspatializationmanager18) to obtain an **AudioSpatializationManager** instance.

  ```ts
  import { audio } from '@kit.AudioKit';

  let audioManager = audio.getAudioManager();
  let audioSpatializationManager = audioManager.getSpatializationManager();
  ```

## Checking Whether a Device Supports Spatial Audio Rendering

Use the **spatializationSupported** property in [AudioDeviceDescriptor](../../reference/apis-audio-kit/js-apis-audio.md#audiodevicedescriptor) to check whether a specified device supports spatial audio rendering. You need to use other audio APIs to obtain **AudioDeviceDescriptor** of a connected device or the current audio device.

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  const deviceDescriptors: audio.AudioDeviceDescriptors = audioRoutingManager.getDevicesSync(audio.DeviceFlag.OUTPUT_DEVICES_FLAG);
  for (let i = 0; i < deviceDescriptors.length; i++) {
    console.info('deviceDescriptor deviceRole: ${deviceDescriptors[i].deviceRole}');
    console.info('deviceDescriptor deviceType: ${deviceDescriptors[i].deviceType}');
    console.info('deviceDescriptor name: ${deviceDescriptors[i].name}');
    console.info('deviceDescriptor spatializationSupported: ${deviceDescriptors[i].spatializationSupported}');
  }
  ```

## Checking the Status of Spatial Audio Rendering of the Current Device

Call [isSpatializationEnabledForCurrentDevice](../../reference/apis-audio-kit/js-apis-audio.md#isspatializationenabledforcurrentdevice18) to check whether spatial audio rendering is enabled for the current device.
- If **true** is returned, spatial audio rendering is enabled for the current device. If **false** is returned, it is disabled.
- Spatial audio rendering takes effect only when the current device support spatial audio rendering.

  ```ts
  import { audio } from '@kit.AudioKit';

  let isSpatializationEnabledForCurrentDevice: boolean = audioSpatializationManager.isSpatializationEnabledForCurrentDevice();
  console.info(`AudioSpatializationManager isSpatializationEnabledForCurrentDevice: ${isSpatializationEnabledForCurrentDevice}`);
  ```

**Listening for Spatial Audio Rendering Status Changes of the Current Device**

Call [on('spatializationEnabledChangeForCurrentDevice')](../../reference/apis-audio-kit/js-apis-audio.md#onspatializationenabledchangeforcurrentdevice18) to subscribe to the spatial audio rendering status change event of the current device.

If **true** is returned, spatial audio rendering is enabled. If **false** is returned, it is disabled.

```ts
import { audio } from '@kit.AudioKit';

audioSpatializationManager.on('spatializationEnabledChangeForCurrentDevice', (isSpatializationEnabledForCurrentDevice: boolean) => {
  console.info(`isSpatializationEnabledForCurrentDevice: ${isSpatializationEnabledForCurrentDevice}`);
});
```

**Canceling Listening for Spatial Audio Rendering Status Changes of the Current Device**

Call [off('spatializationEnabledChangeForCurrentDevice')](../../reference/apis-audio-kit/js-apis-audio.md#offspatializationenabledchangeforcurrentdevice18) to unsubscribe from the spatial audio rendering status change event of the current device.

  ```ts
  import { audio } from '@kit.AudioKit';
  audioSpatializationManager.off('spatializationEnabledChangeForCurrentDevice');
  ```
