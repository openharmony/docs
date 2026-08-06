# Spatial Audio Management (for System Applications Only)

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @tom_guo-->
<!--Designer: @trytocalm-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=bf5d49a4393b61c9a2c280c54a54215020618b5d translatedAt=2026-08-06T01:48:13.095Z pushedAt=2026-08-06T08:15:17.849Z -->

Spatial audio management includes querying, setting, and listening for spatial audio status and capabilities.

Spatial audio management is available only for system apps. It mainly includes querying, setting, and listening for spatial audio-related status (enabling/disabling of spatial audio rendering, adaptive spatial audio rendering, and head tracking), querying spatial audio-related capabilities (spatial audio rendering capability and head tracking capability), updating spatial device states, and querying and setting the spatial audio rendering scene type.

Adaptive spatial audio rendering is a capability where the system automatically determines whether to perform spatial audio rendering based on the audio content. When enabled, spatial audio rendering takes effect only for multi-channel content, and does not take effect for mono or dual-channel (stereo) content. When disabled, it does not affect spatial audio rendering.

A system application that plays audio can query whether the system or a device supports spatial audio rendering or head tracking, whether spatial audio rendering or head tracking is enabled, and the spatial audio rendering scene type in use.

For system apps with spatial audio control capabilities (such as spatial audio UX), in addition to querying the above status and capabilities, you can also set the spatial audio rendering switch, adaptive spatial audio rendering switch, head tracking switch, and spatial audio rendering scene type, as well as update the spatial device state to indicate whether a specific spatial device supports spatial audio rendering and head tracking.

Before using this feature, the app must request the `ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS` permission. For details, see [Requesting Permissions for system_basic Applications](../../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).

## Obtaining an AudioSpatializationManager Instance

Before using any APIs of AudioSpatializationManager, you must call [getSpatializationManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioManager.md#getspatializationmanager18) to obtain an AudioSpatializationManager instance.

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

Call [isSpatializationSupportedForDevice](../../reference/apis-audio-kit/js-apis-audio-sys.md#isspatializationsupportedfordevice11) to check whether a device (specified by [AudioDeviceDescriptor](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiodevicedescriptor)) supports spatial audio rendering. You are advised to use other audio APIs to obtain **AudioDeviceDescriptor **of a connected device or the current audio device.

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let deviceDescriptor: audio.AudioDeviceDescriptor = {
    deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
    deviceType : audio.DeviceType.BLUETOOTH_A2DP,
    id : 1,
    name : "",
    address : "00:11:22:33:FF:EE",
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

Call [isHeadTrackingSupportedForDevice](../../reference/apis-audio-kit/js-apis-audio-sys.md#isheadtrackingsupportedfordevice11) to check whether a device (specified by **AudioDeviceDescriptor**) supports head tracking. You are advised to use other audio APIs to obtain [AudioDeviceDescriptor](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiodevicedescriptor) of a connected device or the current audio device.

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let deviceDescriptor: audio.AudioDeviceDescriptor = {
    deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
    deviceType : audio.DeviceType.BLUETOOTH_A2DP,
    id : 1,
    name : "",
    address : "00:11:22:33:FF:EE",
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

**AudioDeviceDescriptor**: specifies an audio device. You are advised to use other audio APIs to obtain [AudioDeviceDescriptor](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiodevicedescriptor) of a connected device or the current audio device.

**enabled**: specifies the status of spatial audio rendering of the specified device. The value **true** means to enable spatial audio rendering, and **false** means to disable it.

Before using this feature, the app must request the `ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS` permission. For details, see [Requesting Permissions for system_basic Applications](../../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).

Before enabling spatial audio rendering, ensure that both the system and the specified device support spatial audio rendering.

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let deviceDescriptor: audio.AudioDeviceDescriptor = {
    deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
    deviceType : audio.DeviceType.BLUETOOTH_A2DP,
    id : 1,
    name : "",
    address : "00:11:22:33:FF:EE",
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
    console.info('Succeeded in setting spatialization enabled');
  }).catch((err: BusinessError) => {
    console.error(`Result ERROR: ${err}`);
  });
  ```

## Checking the Status of Spatial Audio Rendering of a Device

You can call [isSpatializationEnabled](../../reference/apis-audio-kit/js-apis-audio-sys.md#isspatializationenabled12) to query the spatial audio rendering effect switch status of a specified device. This API uses **AudioDeviceDescriptor** as an input parameter to specify the device. It is recommended to obtain the [AudioDeviceDescriptor](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiodevicedescriptor) of the current connected device or audio output device through other APIs in the audio framework. The API returns **true** if spatial audio rendering is enabled, and **false** if it is disabled. The return value reflects the spatial audio rendering switch status of the specified device that was successfully set through the [setSpatializationEnabled](../../reference/apis-audio-kit/js-apis-audio-sys.md#setspatializationenabled12) API, and defaults to disabled. This status only indicates the switch state; whether it actually takes effect depends on whether the system and the specified device support spatial audio rendering.

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let deviceDescriptor: audio.AudioDeviceDescriptor = {
    deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
    deviceType : audio.DeviceType.BLUETOOTH_A2DP,
    id : 1,
    name : "",
    address : "00:11:22:33:FF:EE",
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

Call [on('spatializationEnabledChangeForAnyDevice')](../../reference/apis-audio-kit/js-apis-audio-sys.md#onspatializationenabledchangeforanydevice12) to subscribe to spatial audio rendering status changes. In the callback, the [AudioSpatialEnabledStateForDevice](../../reference/apis-audio-kit/js-apis-audio-sys.md#audiospatialenabledstatefordevice12) parameter contains **deviceDescriptor** and **enabled**. **deviceDescriptor** specifies the device descriptor, and **enabled** specifies the enabled status, where **true** means that spatial audio rendering is enabled and **false** means the opposite. The callback is triggered when spatial audio rendering is enabled or disabled for any device through [setSpatializationEnabled](../../reference/apis-audio-kit/js-apis-audio-sys.md#setspatializationenabled12).

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

You can call [setHeadTrackingEnabled](../../reference/apis-audio-kit/js-apis-audio-sys.md#setheadtrackingenabled12) to enable or disable head tracking for a specified device. This API requires two parameters: **AudioDeviceDescriptor** and **enabled**.

**AudioDeviceDescriptor**: specifies an audio device. You are advised to use other audio APIs to obtain [AudioDeviceDescriptor](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiodevicedescriptor) of a connected device or the current audio device.

**enabled**: specifies the status of head tracking of the specified device. The value **true** means to enable head tracking, and **false** means to disable it.

Before using this feature, the app must request the `ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS` permission. For details, see [Requesting Permissions for system_basic Apps](../../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-apps).

Before enabling head tracking, ensure that both the system and the specified device support head tracking and spatial audio rendering is enabled.

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let deviceDescriptor: audio.AudioDeviceDescriptor = {
    deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
    deviceType : audio.DeviceType.BLUETOOTH_A2DP,
    id : 1,
    name : "",
    address : "00:11:22:33:FF:EE",
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
    console.info('Succeeded in setting head tracking enabled');
  }).catch((err: BusinessError) => {
    console.error(`Result ERROR: ${err}`);
  });
  ```

## Checking the Status of Head Tracking of a Device

You can call [isHeadTrackingEnabled](../../reference/apis-audio-kit/js-apis-audio-sys.md#isheadtrackingenabled12) to query the head tracking effect switch status of a specified device. This API uses **AudioDeviceDescriptor** as an input parameter to specify the device. It is recommended to obtain the [AudioDeviceDescriptor](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiodevicedescriptor) of the current connected device or audio output device through other APIs in the audio framework. The API returns **true** if head tracking is enabled, and **false** if it is disabled. The return value reflects the head tracking switch status of the specified device that was successfully set through the [setHeadTrackingEnabled](../../reference/apis-audio-kit/js-apis-audio-sys.md#setheadtrackingenabled12) API, and defaults to disabled. This status only indicates the switch state; whether it actually takes effect depends on whether the system and the specified device support head tracking, and whether the spatial audio rendering switch of the specified device is turned on.

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let deviceDescriptor: audio.AudioDeviceDescriptor = {
    deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
    deviceType : audio.DeviceType.BLUETOOTH_A2DP,
    id : 1,
    name : "",
    address : "00:11:22:33:FF:EE",
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

Call [on('headTrackingEnabledChangeForAnyDevice')](../../reference/apis-audio-kit/js-apis-audio-sys.md#onheadtrackingenabledchangeforanydevice12) to subscribe to head tracking status changes. In the callback, the [AudioSpatialEnabledStateForDevice](../../reference/apis-audio-kit/js-apis-audio-sys.md#audiospatialenabledstatefordevice12) parameter contains **deviceDescriptor** and **enabled**. **deviceDescriptor** specifies the device descriptor, and **enabled** specifies the enabled status, where **true** means that head tracking is enabled and **false** means the opposite. The callback is triggered when head tracking is enabled or disabled for any device through [setHeadTrackingEnabled](../../reference/apis-audio-kit/js-apis-audio-sys.md#setheadtrackingenabled12).

  ```ts
  import { audio } from '@kit.AudioKit';

  audioSpatializationManager.on('headTrackingEnabledChangeForAnyDevice', (audioSpatialEnabledStateForDevice: audio.AudioSpatialEnabledStateForDevice) => {
    console.info(`deviceDescriptor: ${audioSpatialEnabledStateForDevice.deviceDescriptor}`);
    console.info(`isHeadTrackingEnabled: ${audioSpatialEnabledStateForDevice.enabled}`);
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

Before using this feature, the app must request the `ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS` permission. For details, see [Requesting Permissions for system_basic Applications](../../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).

For details about the spatial device state, see [AudioSpatialDeviceState](../../reference/apis-audio-kit/js-apis-audio-sys.md#audiospatialdevicestate11).

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let spatialDeviceState: audio.AudioSpatialDeviceState = {
    address: "00:11:22:33:FF:EE",
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

Before using this feature, the app must request the `ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS` permission. For details, see [Requesting Permissions for system_basic Applications](../../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).

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

## Querying the Adaptive Spatial Audio Rendering Effect Switch Status of a Specified Device

Starting from API version 24, you can call [isAdaptiveSpatialRenderingEnabled](../../reference/apis-audio-kit/js-apis-audio-sys.md#isadaptivespatialrenderingenabled24) to query the adaptive spatial audio rendering effect switch status of a specified device.

The input parameter uses **AudioDeviceDescriptor** to specify the device. It is recommended to obtain the [AudioDeviceDescriptor](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiodevicedescriptor) of the current audio output device through the [getActiveOutputDeviceDescriptors](../../reference/apis-audio-kit/js-apis-audio-sys.md#getactiveoutputdevicedescriptors) API of the audio framework.

The return value indicates the adaptive spatial audio rendering switch status of the specified device: **true** means adaptive spatial audio rendering is enabled, and **false** means it is disabled (defaults to disabled). This status can be set through the [setAdaptiveSpatialRenderingEnabled](../../reference/apis-audio-kit/js-apis-audio-sys.md#setadaptivespatialrenderingenabled24) API.

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  // Device descriptor used to specify the device to query. In actual use, obtain real device information through audio framework APIs, and use real values for fields such as address.
  let deviceDescriptor: audio.AudioDeviceDescriptor = {
    deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
    deviceType : audio.DeviceType.BLUETOOTH_A2DP,
    id : 1,
    name : "",
    address : "00:11:22:33:FF:EE",
    sampleRates : [44100],
    channelCounts : [2],
    channelMasks : [0],
    networkId : audio.LOCAL_NETWORK_ID,
    interruptGroupId : 1,
    volumeGroupId : 1,
    displayName : ""
  };

  try {
    // Query the switch state of the adaptive spatial audio rendering effect for the specified device.
    let isAdaptiveSpatialRenderingEnabled: boolean = audioSpatializationManager.isAdaptiveSpatialRenderingEnabled(deviceDescriptor);
    console.info(`AudioSpatializationManager isAdaptiveSpatialRenderingEnabled: ${isAdaptiveSpatialRenderingEnabled}`);
  } catch (err) {
    let error = err as BusinessError;
    console.error(`ERROR: ${error}`);
  }
  ```

## Enabling or Disabling the Adaptive Spatial Audio Rendering Effect for a Specified Device

Starting from API version 24, you can call [setAdaptiveSpatialRenderingEnabled](../../reference/apis-audio-kit/js-apis-audio-sys.md#setadaptivespatialrenderingenabled24) to enable or disable the adaptive spatial audio rendering effect for a specified device.

Before using this feature, the app must request the `ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS` permission. For details, see [Requesting Permissions for system_basic Applications](../../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).

Before enabling adaptive spatial audio rendering, ensure that both the system and the specified device have the spatial audio rendering capability.

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  // Device descriptor used to specify the device to set.
  let deviceDescriptor: audio.AudioDeviceDescriptor = {
    deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
    deviceType : audio.DeviceType.BLUETOOTH_A2DP,
    id : 1,
    name : "",
    address : "00:11:22:33:FF:EE",
    sampleRates : [44100],
    channelCounts : [2],
    channelMasks : [0],
    networkId : audio.LOCAL_NETWORK_ID,
    interruptGroupId : 1,
    volumeGroupId : 1,
    displayName : ""
  };
  // Adaptive spatial audio rendering switch state. The value **true** indicates enabled, and **false** indicates disabled.
  let enabled: boolean = true;

  // Enable the adaptive spatial audio rendering effect for the specified device.
  audioSpatializationManager.setAdaptiveSpatialRenderingEnabled(deviceDescriptor, enabled).then(() => {
    console.info('Succeeded in setting adaptive spatial rendering enabled');
  }).catch((err: BusinessError) => {
    console.error(`Result ERROR: ${err}`);
  });
  ```

## Subscribing to Adaptive Spatial Audio Rendering Effect Switch Status Change Events

Starting from API version 24, you can call [onAdaptiveSpatialRenderingEnabledChangeForAnyDevice](../../reference/apis-audio-kit/js-apis-audio-sys.md#onadaptivespatialrenderingenabledchangeforanydevice24) to subscribe to adaptive spatial audio rendering effect switch status change events.

The callback includes the [AudioSpatialEnabledStateForDevice](../../reference/apis-audio-kit/js-apis-audio-sys.md#audiospatialenabledstatefordevice12) parameter, where **deviceDescriptor** is the description of the changed device, and **enabled** being **true** means adaptive spatial audio rendering is enabled, while **false** means it is disabled.

The callback is triggered when the adaptive spatial audio rendering switch status of any device is successfully changed through the [setAdaptiveSpatialRenderingEnabled](../../reference/apis-audio-kit/js-apis-audio-sys.md#setadaptivespatialrenderingenabled24) API.

  ```ts
  import { audio } from '@kit.AudioKit';

  // Subscribe to the switch state change event of the adaptive spatial audio rendering effect.
  audioSpatializationManager.onAdaptiveSpatialRenderingEnabledChangeForAnyDevice((audioSpatialEnabledStateForDevice: audio.AudioSpatialEnabledStateForDevice) => {
    console.info(`deviceDescriptor: ${audioSpatialEnabledStateForDevice.deviceDescriptor}`);
    console.info(`isAdaptiveSpatialRenderingEnabled: ${audioSpatialEnabledStateForDevice.enabled}`);
  });
  ```

## Unsubscribing from Adaptive Spatial Audio Rendering Effect Switch Status Change Events

Starting from API version 24, you can call [offAdaptiveSpatialRenderingEnabledChangeForAnyDevice](../../reference/apis-audio-kit/js-apis-audio-sys.md#offadaptivespatialrenderingenabledchangeforanydevice24) to unsubscribe from adaptive spatial audio rendering effect switch status change events.

  ```ts
  import { audio } from '@kit.AudioKit';
  // Unsubscribe from the switch state change event of the adaptive spatial audio rendering effect.
  audioSpatializationManager.offAdaptiveSpatialRenderingEnabledChangeForAnyDevice();
  ```

## Obtaining the Current Spatial Audio Source Type

Starting from API version 24, you can call [getCurrentSpatialAudioSourceType](../../reference/apis-audio-kit/js-apis-audio-sys.md#getcurrentspatialaudiosourcetype24) to obtain the current spatial audio source type. This API returns the type of the currently playing audio stream, including stereo, Audio Vivid, or multi-channel.

For details about the spatial audio source type, see [SpatialAudioSourceType](../../reference/apis-audio-kit/js-apis-audio-sys.md#spatialaudiosourcetype24).

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // Obtain the current spatial audio source type. Returns the type of the currently playing audio stream.
    let spatialAudioSourceType: audio.SpatialAudioSourceType = audioSpatializationManager.getCurrentSpatialAudioSourceType();
    console.info(`AudioSpatializationManager spatialAudioSourceType: ${spatialAudioSourceType}`);
  } catch (err) {
    let error = err as BusinessError;
    console.error(`ERROR: ${error}`);
  }
  ```

## Subscribing to Spatial Audio Source Type Change Events

Starting from API version 24, you can call [onSpatialAudioSourceTypeChange](../../reference/apis-audio-kit/js-apis-audio-sys.md#onspatialaudiosourcetypechange24) to subscribe to spatial audio source type change events. The callback includes the **SpatialAudioSourceType** parameter, which indicates the changed spatial audio source type. When a different type of audio stream starts playing, the spatial audio source type is automatically updated and the callback is triggered.

  ```ts
  import { audio } from '@kit.AudioKit';

  // Subscribe to the spatial audio source type change event.
  audioSpatializationManager.onSpatialAudioSourceTypeChange((spatialAudioSourceType: audio.SpatialAudioSourceType) => {
    console.info(`spatialAudioSourceType: ${spatialAudioSourceType}`);
  });
  ```

## Unsubscribing from Spatial Audio Source Type Change Events

Starting from API version 24, you can call [offSpatialAudioSourceTypeChange](../../reference/apis-audio-kit/js-apis-audio-sys.md#offspatialaudiosourcetypechange24) to unsubscribe from spatial audio source type change events.

  ```ts
  import { audio } from '@kit.AudioKit';

  // Unsubscribe from the spatial audio source type change event.
  audioSpatializationManager.offSpatialAudioSourceTypeChange();
  ```