# Spatial Audio Management (for System Applications Only)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

Spatial audio management includes querying, setting, and listening for spatial audio status and capabilities.

Spatial audio management is available only for system applications. It enables a system application to obtain, set, and listen for spatial audio status (enabled/disabled status of spatial audio rendering and head tracking), obtain spatial audio capabilities (support for spatial audio rendering and head tracking), update the state information of spatial devices, and obtain and set the spatial audio rendering scene type.

A system application that plays audio can query whether the system or a device supports spatial audio rendering or head tracking, whether spatial audio rendering or head tracking is enabled, and the spatial audio rendering scene type in use.

A system application with spatial audio setting capabilities (for example, a setting screen where users can change the spatial audio status) can enable or disable spatial audio rendering or head tracking, set the spatial audio rendering scene type, and update the state information of a spatial device, in addition to the query operation.
To use this feature, the application must request the ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS permission. For details, see [Requesting Permissions for system_basic Applications](../../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).

## Obtaining an AudioSpatializationManager Instance

Before using AudioSpatializationManager APIs, you must use **getSpatializationManager()** to obtain an AudioSpatializationManager instance.

  ```ts
  import { audio } from '@kit.AudioKit';

  let audioManager = audio.getAudioManager();
  let audioSpatializationManager = audioManager.getSpatializationManager();
  ```

## Checking Whether the System Supports Spatial Audio Rendering

Call [isSpatializationSupported](../../reference/apis-audio-kit/js-apis-audio-sys.md#isspatializationsupported11) to check whether the system supports spatial audio rendering.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let isSpatializationSupported: boolean = audioSpatializationManager.isSpatializationSupported();
    console.info(`AudioSpatializationManager isSpatializationSupported: ${isSpatializationSupported}`);
  } catch (err) {
    let error = err as BusinessError;
    console.error(`ERROR: ${error}`);
  }
  ```

## Checking Whether a Device Supports Spatial Audio Rendering

Call [isSpatializationSupportedForDevice](../../reference/apis-audio-kit/js-apis-audio-sys.md#isspatializationsupportedfordevice11) to check whether a device (specified by **AudioDeviceDescriptor**) supports spatial audio rendering. You are advised to use other audio APIs to obtain **AudioDeviceDescriptor** of a connected device or the current audio device. For details, see [AudioDeviceDescriptor](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiodevicedescriptor).

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let deviceDescriptor: audio.AudioDeviceDescriptor = {
    deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
    deviceType : audio.DeviceType.BLUETOOTH_A2DP,
    id : 1,
    name : "",
    address : "123",
    sampleRates : [44100],
    channelCounts : [2],
    channelMasks : [0],
    networkId : audio.LOCAL_NETWORK_ID,
    interruptGroupId : 1,
    volumeGroupId : 1,
    displayName : ""
  };
  try {
    let isSpatializationSupportedForDevice: boolean = audioSpatializationManager.isSpatializationSupportedForDevice(deviceDescriptor);
    console.info(`AudioSpatializationManager isSpatializationSupportedForDevice: ${isSpatializationSupportedForDevice}`);
  } catch (err) {
    let error = err as BusinessError;
    console.error(`ERROR: ${error}`);
  }
  ```

## Checking Whether the System Supports Head Tracking

Call [isHeadTrackingSupported](../../reference/apis-audio-kit/js-apis-audio-sys.md#isheadtrackingsupported11) to check whether the system supports head tracking.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let isHeadTrackingSupported: boolean = audioSpatializationManager.isHeadTrackingSupported();
    console.info(`AudioSpatializationManager isHeadTrackingSupported: ${isHeadTrackingSupported}`);
  } catch (err) {
    let error = err as BusinessError;
    console.error(`ERROR: ${error}`);
  }
  ```

## Checking Whether a Device Supports Head Tracking

Call [isHeadTrackingSupportedForDevice](../../reference/apis-audio-kit/js-apis-audio-sys.md#isheadtrackingsupportedfordevice11) to check whether a device (specified by **AudioDeviceDescriptor**) supports head tracking. You are advised to use other audio APIs to obtain **AudioDeviceDescriptor** of a connected device or the current audio device. For details, see [AudioDeviceDescriptor](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiodevicedescriptor).

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let deviceDescriptor: audio.AudioDeviceDescriptor = {
    deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
    deviceType : audio.DeviceType.BLUETOOTH_A2DP,
    id : 1,
    name : "",
    address : "123",
    sampleRates : [44100],
    channelCounts : [2],
    channelMasks : [0],
    networkId : audio.LOCAL_NETWORK_ID,
    interruptGroupId : 1,
    volumeGroupId : 1,
    displayName : ""
  };

  try {
    let isHeadTrackingSupportedForDevice: boolean = audioSpatializationManager.isHeadTrackingSupportedForDevice(deviceDescriptor);
    console.info(`AudioSpatializationManager isHeadTrackingSupportedForDevice: ${isHeadTrackingSupportedForDevice}`);
  } catch (err) {
    let error = err as BusinessError;
    console.error(`ERROR: ${error}`);
  }
  ```

## Enabling or Disabling Spatial Audio Rendering for a Device

Call [setSpatializationEnabled](../../reference/apis-audio-kit/js-apis-audio-sys.md#setspatializationenabled12) to enable or disable spatial audio rendering for a device. This API contains two parameters:

- **AudioDeviceDescriptor**: specifies an audio device. You are advised to use other audio APIs to obtain **AudioDeviceDescriptor** of a connected device or the current audio device. For details, see [AudioDeviceDescriptor](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiodevicedescriptor).
- **enabled**: specifies the status of spatial audio rendering of the specified device. The value **true** means to enable spatial audio rendering, and **false** means to disable it.

To use this feature, the application must request the ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS permission. For details, see [Requesting Permissions for system_basic Applications](../../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).

Before enabling spatial audio rendering, ensure that both the system and the specified device support spatial audio rendering.

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let deviceDescriptor: audio.AudioDeviceDescriptor = {
    deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
    deviceType : audio.DeviceType.BLUETOOTH_A2DP,
    id : 1,
    name : "",
    address : "123",
    sampleRates : [44100],
    channelCounts : [2],
    channelMasks : [0],
    networkId : audio.LOCAL_NETWORK_ID,
    interruptGroupId : 1,
    volumeGroupId : 1,
    displayName : ""
  };
  let enabled: boolean = true;

  audioSpatializationManager.setSpatializationEnabled(deviceDescriptor, enabled).then(() => {
    console.info(`setSpatializationEnabled success`);
  }).catch((err: BusinessError) => {
    console.error(`Result ERROR: ${err}`);
  });
  ```

## Checking the Status of Spatial Audio Rendering of a Device

Call [isSpatializationEnabled](../../reference/apis-audio-kit/js-apis-audio-sys.md#isspatializationenabled12) to check whether spatial audio rendering is enabled for a device (specified by **AudioDeviceDescriptor**). You are advised to use other audio APIs to obtain **AudioDeviceDescriptor** of a connected device or the current audio device. For details, see [AudioDeviceDescriptor](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiodevicedescriptor). If **true** is returned, spatial audio rendering is enabled. If **false** is returned, it is disabled. This API returns the value passed in **setSpatializationEnabled**. The default value is **false**. Note that spatial audio rendering takes effect only when the system and the specified device support spatial audio rendering.

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let deviceDescriptor: audio.AudioDeviceDescriptor = {
    deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
    deviceType : audio.DeviceType.BLUETOOTH_A2DP,
    id : 1,
    name : "",
    address : "123",
    sampleRates : [44100],
    channelCounts : [2],
    channelMasks : [0],
    networkId : audio.LOCAL_NETWORK_ID,
    interruptGroupId : 1,
    volumeGroupId : 1,
    displayName : ""
  }

  try {
    let isSpatializationEnabled: boolean = audioSpatializationManager.isSpatializationEnabled(deviceDescriptor);
    console.info(`AudioSpatializationManager isSpatializationEnabled: ${isSpatializationEnabled}`);
  } catch (err) {
    let error = err as BusinessError;
    console.error(`ERROR: ${error}`);
  }
  ```

## Subscribing to Spatial Audio Rendering Status Changes

Call [on('spatializationEnabledChangeForAnyDevice')](../../reference/apis-audio-kit/js-apis-audio-sys.md#onspatializationenabledchangeforanydevice12) to subscribe to spatial audio rendering status changes. In the callback, the **AudioSpatialEnabledStateForDevice** parameter contains **deviceDescriptor** and **enabled**. **deviceDescriptor** specifies the device descriptor, and **enabled** specifies the enabled status, where **true** means that spatial audio rendering is enabled and **false** means the opposite. For details, see [AudioSpatialEnabledStateForDevice](../../reference/apis-audio-kit/js-apis-audio-sys.md#audiospatialenabledstatefordevice12). The callback is triggered when spatial audio rendering is enabled or disabled for any device through **setSpatializationEnabled**.

  ```ts
  import { audio } from '@kit.AudioKit';

  audioSpatializationManager.on('spatializationEnabledChangeForAnyDevice', (audioSpatialEnabledStateForDevice: audio.AudioSpatialEnabledStateForDevice) => {
    console.info(`deviceDescriptor: ${audioSpatialEnabledStateForDevice.deviceDescriptor}`);
    console.info(`isSpatializationEnabled: ${audioSpatialEnabledStateForDevice.enabled}`);
  });
  ```

## Unsubscribing from Spatial Audio Rendering Status Changes

Call [off('spatializationEnabledChangeForAnyDevice')](../../reference/apis-audio-kit/js-apis-audio-sys.md#offspatializationenabledchangeforanydevice12) to unsubscribe from spatial audio rendering status changes.

  ```ts
  import { audio } from '@kit.AudioKit';
  audioSpatializationManager.off('spatializationEnabledChangeForAnyDevice');
  ```

## Enabling or Disabling Head Tracking for a Device

Call [setHeadTrackingEnabled](../../reference/apis-audio-kit/js-apis-audio-sys.md#setheadtrackingenabled12) to enable or disable head tracking for a device. This API contains two parameters:

- **AudioDeviceDescriptor**: specifies an audio device. You are advised to use other audio APIs to obtain **AudioDeviceDescriptor** of a connected device or the current audio device. For details, see [AudioDeviceDescriptor](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiodevicedescriptor).
- **enabled**: specifies the status of head tracking of the specified device. The value **true** means to enable head tracking, and **false** means to disable it.

To use this feature, the application must request the ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS permission. For details, see [Requesting Permissions for system_basic Applications](../../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).

Before enabling head tracking, ensure that both the system and the specified device support head tracking and when spatial audio rendering is enabled.

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let deviceDescriptor: audio.AudioDeviceDescriptor = {
    deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
    deviceType : audio.DeviceType.BLUETOOTH_A2DP,
    id : 1,
    name : "",
    address : "123",
    sampleRates : [44100],
    channelCounts : [2],
    channelMasks : [0],
    networkId : audio.LOCAL_NETWORK_ID,
    interruptGroupId : 1,
    volumeGroupId : 1,
    displayName : ""
  };
  let enable: boolean = true;

  audioSpatializationManager.setHeadTrackingEnabled(deviceDescriptor, enable).then(() => {
    console.info(`setHeadTrackingEnabled success`);
  }).catch((err: BusinessError) => {
    console.error(`Result ERROR: ${err}`);
  });
  ```

## Checking the Status of Head Tracking of a Device

Call [isHeadTrackingEnabled](../../reference/apis-audio-kit/js-apis-audio-sys.md#isheadtrackingenabled12) to check whether head tracking is enabled for a device (specified by **AudioDeviceDescriptor**). You are advised to use other audio APIs to obtain **AudioDeviceDescriptor** of a connected device or the current audio device. For details, see [AudioDeviceDescriptor](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiodevicedescriptor). If **true** is returned, head tracking is enabled. If **false** is returned, it is disabled. This API returns the value passed in **setHeadTrackingEnabled**. The default value is **false**. Note that head tracking takes effect only when the system and the specified device support head tracking and spatial audio rendering is enabled.

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let deviceDescriptor: audio.AudioDeviceDescriptor = {
    deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
    deviceType : audio.DeviceType.BLUETOOTH_A2DP,
    id : 1,
    name : "",
    address : "123",
    sampleRates : [44100],
    channelCounts : [2],
    channelMasks : [0],
    networkId : audio.LOCAL_NETWORK_ID,
    interruptGroupId : 1,
    volumeGroupId : 1,
    displayName : ""
  };

  try {
    let isHeadTrackingEnabled: boolean = audioSpatializationManager.isHeadTrackingEnabled(deviceDescriptor);
    console.info(`AudioSpatializationManager isHeadTrackingEnabled: ${isHeadTrackingEnabled}`);
  } catch (err) {
    let error = err as BusinessError;
    console.error(`ERROR: ${error}`);
  }
  ```

## Subscribing to Head Tracking Status Changes

Call [on('headTrackingEnabledChangeForAnyDevice')](../../reference/apis-audio-kit/js-apis-audio-sys.md#onheadtrackingenabledchangeforanydevice12) to subscribe to head tracking status changes. In the callback, the **AudioSpatialEnabledStateForDevice** parameter contains **deviceDescriptor** and **enabled**. **deviceDescriptor** specifies the device descriptor, and **enabled** specifies the enabled status, where **true** means that head tracking is enabled and **false** means the opposite. For details, see [AudioSpatialEnabledStateForDevice](../../reference/apis-audio-kit/js-apis-audio-sys.md#audiospatialenabledstatefordevice12). The callback is triggered when head tracking is enabled or disabled for any device through **setHeadTrackingEnabled**.

  ```ts
  import { audio } from '@kit.AudioKit';

  audioSpatializationManager.on('headTrackingEnabledChangeForAnyDevice', (audioSpatialEnabledStateForDevice: audio.AudioSpatialEnabledStateForDevice) => {
    console.info(`deviceDescriptor: ${audioSpatialEnabledStateForDevice.deviceDescriptor}`);
    console.info(`isSpatializationEnabled: ${audioSpatialEnabledStateForDevice.enabled}`);
  });
  ```

## Unsubscribing from Head Tracking Status Changes

Call [off('headTrackingEnabledChangeForAnyDevice')](../../reference/apis-audio-kit/js-apis-audio-sys.md#offheadtrackingenabledchangeforanydevice12) to unsubscribe from head tracking status changes.

  ```ts
  import { audio } from '@kit.AudioKit';
  audioSpatializationManager.off('headTrackingEnabledChangeForAnyDevice');
  ```

## Updating the State Information of a Spatial Device

Call [updateSpatialDeviceState](../../reference/apis-audio-kit/js-apis-audio-sys.md#updatespatialdevicestate11) to update the state information of a spatial device. The state information includes the device address, support for spatial audio rendering and head tracking, and device form.

To use this feature, the application must request the ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS permission. For details, see [Requesting Permissions for system_basic Applications](../../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).

For details about the state information, see [AudioSpatialDeviceState](../../reference/apis-audio-kit/js-apis-audio-sys.md#audiospatialdevicestate11).

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let spatialDeviceState: audio.AudioSpatialDeviceState = {
    address: "123",
    isSpatializationSupported: true,
    isHeadTrackingSupported: true,
    spatialDeviceType: audio.AudioSpatialDeviceType.SPATIAL_DEVICE_TYPE_IN_EAR_HEADPHONE
  };

  try {
    audioSpatializationManager.updateSpatialDeviceState(spatialDeviceState);
    console.info(`AudioSpatializationManager updateSpatialDeviceState success`);
  } catch (err) {
    let error = err as BusinessError;
    console.error(`ERROR: ${error}`);
  }
  ```

## Setting the Spatial Audio Rendering Scene Type

Call [setSpatializationSceneType](../../reference/apis-audio-kit/js-apis-audio-sys.md#setspatializationscenetype12) to set the spatial audio rendering scene type, which can be **DEFAULT** (default value), **MUSIC**, **MOVIE**, or **AUDIOBOOK**. The spatial audio rendering scene type takes effect only when spatial audio rendering is enabled.

To use this feature, the application must request the ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS permission. For details, see [Requesting Permissions for system_basic Applications](../../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).

For details about the spatial audio rendering scene type, see [AudioSpatializationSceneType](../../reference/apis-audio-kit/js-apis-audio-sys.md#audiospatializationscenetype12).

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    audioSpatializationManager.setSpatializationSceneType(audio.AudioSpatializationSceneType.DEFAULT);
    console.info(`AudioSpatializationManager setSpatializationSceneType success`);
  } catch (err) {
    let error = err as BusinessError;
    console.error(`ERROR: ${error}`);
  }
  ```

## Querying the Spatial Audio Rendering Scene Type

Call [getSpatializationSceneType](../../reference/apis-audio-kit/js-apis-audio-sys.md#getspatializationscenetype12) to obtain the spatial audio rendering scene type in use. This API returns the value passed in **setSpatializationSceneType()**. The default value is **DEFAULT**.

For details about the spatial audio rendering scene type, see [AudioSpatializationSceneType](../../reference/apis-audio-kit/js-apis-audio-sys.md#audiospatializationscenetype12).

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let spatializationSceneType: audio.AudioSpatializationSceneType = audioSpatializationManager.getSpatializationSceneType();
    console.info(`AudioSpatializationManager spatializationSceneType: ${spatializationSceneType}`);
  } catch (err) {
    let error = err as BusinessError;
    console.error(`ERROR: ${error}`);
  }
  ```
