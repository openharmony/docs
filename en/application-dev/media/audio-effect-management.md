# Audio Effect Management (ArkTS)

You can manage the audio effect of a specific playback instance, for example, obtaining or setting the audio effect mode of the current audio playback stream. You can obtain the global audio effect, that is, the audio effect mode corresponding to a specific audio content type (specified by **ContentType**) and audio stream usage (specified by **StreamUsage**). You can also obtain, set, and listen for spatial audio status and capabilities.

## Managing the Audio Effect of a Playback Instance

You can obtain and set the audio effect mode, which can be disabled (**EFFECT_NONE**) or default (**EFFECT_DEFAULT**), of the current audio playback stream. In default audio effect mode, the audio effect of the corresponding scenario is automatically loaded based on **ContentType** and **StreamUsage** of the audio stream.

### Creating a Playback Instance

Before obtaining or setting the audio effect mode, you must call **createAudioRenderer(options: AudioRendererOptions)** to create an **AudioRenderer** instance.

1. Import the audio module.

    ```ts
    import audio from '@ohos.multimedia.audio';
    ```

2. Configure audio rendering parameters and create an **AudioRenderer** instance. For details about the audio rendering parameters, see [AudioRendererOptions](../reference/apis/js-apis-audio.md#audiorendereroptions8). For the **AudioRenderer** instance, the audio effect mode **EFFECT_DEFAULT** is used by default.

    ```ts
    import { BusinessError } from '@ohos.base';

    let audioStreamInfo: audio.AudioStreamInfo = {
      samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
      channels: audio.AudioChannel.CHANNEL_1,
      sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
      encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
    };

    let audioRendererInfo: audio.AudioRendererInfo = {
      usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION,
      rendererFlags: 0
    };

    let audioRendererOptions: audio.AudioRendererOptions = {
      streamInfo: audioStreamInfo,
      rendererInfo: audioRendererInfo
    };

    audio.createAudioRenderer(audioRendererOptions, (err: BusinessError, data: audio.AudioRenderer) => {
      if (err) {
        console.error(`Invoke createAudioRenderer failed, code is ${err.code}, message is ${err.message}`);
        return;
      } else {
        console.info('Invoke createAudioRenderer succeeded.');
        let audioRenderer: audio.AudioRenderer = data;
      }
    });
    ```

### Obtaining the Audio Effect Mode of the Playback Instance

  ```ts
  import audio from '@ohos.multimedia.audio';
  import { BusinessError } from '@ohos.base';

  audioRenderer.getAudioEffectMode((err: BusinessError, effectMode: audio.AudioEffectMode) => {
    if (err) {
      console.error(`Failed to get params, code is ${err.code}, message is ${err.message}`);
      return;    
    } else {
      console.info(`getAudioEffectMode: ${effectMode}`);
    }
  });
  ```

### Setting an Audio Effect Mode for the Playback Instance

Disable the system audio effect.

  ```ts
  import audio from '@ohos.multimedia.audio';
  import { BusinessError } from '@ohos.base';

  audioRenderer.setAudioEffectMode(audio.AudioEffectMode.EFFECT_NONE, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to set params, code is ${err.code}, message is ${err.message}`);
      return;
    } else {
      console.info('Callback invoked to indicate a successful audio effect mode setting.');
    }
  });
  ```

Enable the default system audio effect.

  ```ts
  import audio from '@ohos.multimedia.audio';
  import { BusinessError } from '@ohos.base';

  audioRenderer.setAudioEffectMode(audio.AudioEffectMode.EFFECT_DEFAULT, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to set params, code is ${err.code}, message is ${err.message}`);
      return;
    } else {
      console.info('Callback invoked to indicate a successful audio effect mode setting.');
    }
  });
  ```

## Obtaining the Global Audio Effect Mode

You can obtain the global audio effect mode corresponding to a specific audio stream usage (specified by **StreamUsage**).

For an audio playback application, pay attention to the audio effect mode used by the audio stream of the application and perform corresponding operations. For example, for a music application, select the audio effect mode for the music scenario. Before obtaining the global audio effect mode, call **getStreamManager()** to create an **AudioStreamManager** instance.

### Creating an AudioStreamManager Instance

Before using **AudioStreamManager** APIs, you must use **getStreamManager()** to create an **AudioStreamManager** instance.

   ```ts
   import audio from '@ohos.multimedia.audio';

   let audioManager = audio.getAudioManager();
   let audioStreamManager = audioManager.getStreamManager();
   ```

### Querying the Audio Effect Mode of the Corresponding Scenario

  ```ts
  import audio from '@ohos.multimedia.audio';
  import { BusinessError } from '@ohos.base';

  audioStreamManager.getAudioEffectInfoArray(audio.StreamUsage.STREAM_USAGE_MEDIA, async (err: BusinessError, audioEffectInfoArray: audio.AudioEffectInfoArray) => {
    if (err) {
      console.error('Failed to get effect info array');
      return;    
    } else {
      console.info(`getAudioEffectInfoArray: ${audioEffectInfoArray}`);
    }
  });
  ```

## Spatial Audio Management (for System Applications Only)

Spatial audio management is available only for system applications. It enables a system application to obtain, set, and listen for spatial audio status (enabled/disabled status of spatial audio rendering or head tracking), obtain spatial audio capabilities (support for spatial audio rendering and head tracking), and update the state information of spatial devices.

A system application that plays audio can check whether the system or a device supports spatial audio rendering or head tracking and whether spatial audio rendering or head tracking is enabled.

A system application with spatial audio setting capabilities (for example, a setting screen where users can change the spatial audio status) can enable or disable spatial audio rendering or head tracking, and update the state information of a spatial device, in addition to the query operation.

### Obtaining an AudioSpatializationManager Instance

Before using **AudioSpatializationManager** APIs, you must use **getSpatializationManager()** to obtain an **AudioSpatializationManager** instance.

  ```ts
  import audio from '@ohos.multimedia.audio';

  let audioManager = audio.getAudioManager();
  let audioSpatializationManager = audioManager.getSpatializationManager();
  ```

### Checking Whether the System Supports Spatial Audio Rendering

Call [isSpatializationSupported](../reference/apis/js-apis-audio.md#isspatializationsupported11) to check whether the system supports spatial audio rendering.

  ```ts
  import { BusinessError } from '@ohos.base';
  
  try {
    let isSpatializationSupported: boolean = audioSpatializationManager.isSpatializationSupported();
    console.info(`AudioSpatializationManager isSpatializationSupported: ${isSpatializationSupported}`);
  } catch (err) {
    let error = err as BusinessError;
    console.error(`ERROR: ${error}`);
  }
  ```

### Checking Whether a Device Supports Spatial Audio Rendering

Call [isSpatializationSupportedForDevice](../reference/apis/js-apis-audio.md#isspatializationsupportedfordevice11) to check whether a device (specified by **AudioDeviceDescriptor**) supports spatial audio rendering. You are advised to use other audio APIs to obtain **AudioDeviceDescriptor** of a connected device or the current audio device. For details, see [AudioDeviceDescriptor](../reference/apis/js-apis-audio.md#audiodevicedescriptor).

  ```ts
  import audio from '@ohos.multimedia.audio';
  import { BusinessError } from '@ohos.base';
  
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
    let isSpatializationSupportedForDevice: boolean = audioSpatializationManager.isSpatializationSupportedForDevice(deviceDescriptor);
    console.info(`AudioSpatializationManager isSpatializationSupportedForDevice: ${isSpatializationSupportedForDevice}`);
  } catch (err) {
    let error = err as BusinessError;
    console.error(`ERROR: ${error}`);
  }
  ```

### Checking Whether the System Supports Head Tracking

Call [isHeadTrackingSupported](../reference/apis/js-apis-audio.md#isheadtrackingsupported11) to check whether the system supports head tracking.

  ```ts
  import { BusinessError } from '@ohos.base';
  
  try {
    let isHeadTrackingSupported: boolean = audioSpatializationManager.isHeadTrackingSupported();
    console.info(`AudioSpatializationManager isHeadTrackingSupported: ${isHeadTrackingSupported}`);
  } catch (err) {
    let error = err as BusinessError;
    console.error(`ERROR: ${error}`);
  }
  ```

### Checking Whether a Device Supports Head Tracking

Call [isHeadTrackingSupportedForDevice](../reference/apis/js-apis-audio.md#isheadtrackingsupportedfordevice11) to check whether a device (specified by **AudioDeviceDescriptor**) supports head tracking. You are advised to use other audio APIs to obtain **AudioDeviceDescriptor** of a connected device or the current audio device. For details, see [AudioDeviceDescriptor](../reference/apis/js-apis-audio.md#audiodevicedescriptor).

  ```ts
  import audio from '@ohos.multimedia.audio';
  import { BusinessError } from '@ohos.base';
  
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
    let isHeadTrackingSupportedForDevice: boolean = audioSpatializationManager.isHeadTrackingSupportedForDevice(deviceDescriptor);
    console.info(`AudioSpatializationManager isHeadTrackingSupportedForDevice: ${isHeadTrackingSupportedForDevice}`);
  } catch (err) {
    let error = err as BusinessError;
    console.error(`ERROR: ${error}`);
  }
  ```

### Enabling or Disabling Spatial Audio Rendering

Call [setSpatializationEnabled](../reference/apis/js-apis-audio.md#setspatializationenabled11) to enable or disable spatial audio rendering. Pass in **true** to enable spatial audio rendering, and pass in **false** to disable it. This API can be called only by system applications with spatial audio setting capabilities (for example, a setting screen where users can change the spatial audio status). Before enabling spatial audio rendering, ensure that both the system and the current audio device support spatial audio rendering. In addition, if **AudioEffectMode** of the audio stream is set to **EFFECT_NONE**, spatial audio rendering does not take effect regardless of whether it is enabled.

  ```ts
  import { BusinessError } from '@ohos.base';
  
  let enable: boolean = true
  audioSpatializationManager.setSpatializationEnabled(enable, (err: BusinessError) => {
    if (err) {
      console.error(`Result ERROR: ${err}`);
    } else {
      console.info(`setSpatializationEnabled success`);
    }
  });
  ```

### Checking the Status of Spatial Audio Rendering

Call [isSpatializationEnabled](../reference/apis/js-apis-audio.md#isspatializationenabled11) to check whether spatial audio rendering is enabled. If **true** is returned, spatial audio rendering is enabled. If **false** is returned, it is disabled. This API returns the value passed in **setSpatializationEnabled()**. The default value is **true**. Note that spatial audio rendering takes effect only when the system and the current audio device support spatial audio rendering and **AudioEffectMode** of the audio stream is not set to **EFFECT_NONE**.

  ```ts
  import { BusinessError } from '@ohos.base';
  
  try {
    let isSpatializationEnabled: boolean = audioSpatializationManager.isSpatializationEnabled();
    console.info(`AudioSpatializationManager isSpatializationEnabled: ${isSpatializationEnabled}`);
  } catch (err) {
    let error = err as BusinessError;
    console.error(`ERROR: ${error}`);
  }
  ```

### Subscribing to Spatial Audio Rendering Status Changes

Call [on('spatializationEnabledChange')](../reference/apis/js-apis-audio.md#onspatializationenabledchange11) to subscribe to spatial audio rendering status changes. In the callback, the value **true** means that spatial audio rendering is enabled, and **false** means the opposite. The callback is triggered when spatial audio rendering is enabled or disabled through **setSpatializationEnabled()**.

  ```ts
  import { BusinessError } from '@ohos.base';
  
  audioSpatializationManager.on('spatializationEnabledChange', (isSpatializationEnabled: boolean) => {
    console.info(`isSpatializationEnabled: ${isSpatializationEnabled}`);
  });
  ```

### Unsubscribing from Spatial Audio Rendering Status Changes

Call [off('spatializationEnabledChange')](../reference/apis/js-apis-audio.md#offspatializationenabledchange11) to unsubscribe from spatial audio rendering status changes.

  ```ts
  import { BusinessError } from '@ohos.base';
  
  audioSpatializationManager.off('spatializationEnabledChange');
  ```

### Enabling or Disabling Head Tracking

Call [setHeadTrackingEnabled](../reference/apis/js-apis-audio.md#setheadtrackingenabled11) to enable or disable head tracking. Pass in **true** to enable head tracking, and pass in **false** to disable it. This API can be called only by system applications with spatial audio setting capabilities (for example, a setting screen where users can change the spatial audio status). Before enabling head tracking, ensure that both the system and the current audio device support head tracking. In addition, if **AudioEffectMode** of the audio stream is set to **EFFECT_NONE**, head tracking does not take effect regardless of whether it is enabled.

  ```ts
  import { BusinessError } from '@ohos.base';
  
  let enable: boolean = true;
  audioSpatializationManager.setHeadTrackingEnabled(enable, (err: BusinessError) => {
    if (err) {
      console.error(`Result ERROR: ${err}`);
    } else {
      console.info(`setHeadTrackingEnabled success`);
    }
  });
  ```

### Checking the Status of Head tracking

Call [isHeadTrackingEnabled](../reference/apis/js-apis-audio.md#isheadtrackingenabled11) to check whether head tracking is enabled. If **true** is returned, head tracking is enabled. If **false** is returned, it is disabled. This API returns the value passed in **setHeadTrackingEnabled()**. The default value is **false**. Note that head tracking takes effect only when the system and the current audio device support head tracking and **AudioEffectMode** of the audio stream is not set to **EFFECT_NONE**.

  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    let isHeadTrackingEnabled: boolean = audioSpatializationManager.isHeadTrackingEnabled();
    console.info(`AudioSpatializationManager isHeadTrackingEnabled: ${isHeadTrackingEnabled}`);
  } catch (err) {
    let error = err as BusinessError;
    console.error(`ERROR: ${error}`);
  }
  ```

### Subscribing to Head Tracking Status Changes

Call [on('headTrackingEnabledChange')](../reference/apis/js-apis-audio.md#onheadtrackingenabledchange11) to subscribe to head tracking status changes. In the callback, the value **true** means that head tracking is enabled, and **false** means the opposite. The callback is triggered when head tracking is enabled or disabled through **setHeadTrackingEnabled()**.

  ```ts
  import { BusinessError } from '@ohos.base';

  audioSpatializationManager.on('headTrackingEnabledChange', (isHeadTrackingEnabled: boolean) => {
    console.info(`isHeadTrackingEnabled: ${isHeadTrackingEnabled}`);
  });
  ```

### Unsubscribing from Head Tracking Status Changes

Call [off('headTrackingEnabledChange')](../reference/apis/js-apis-audio.md#offheadtrackingenabledchange11) to unsubscribe from head tracking status changes.

  ```ts
  audioSpatializationManager.off('headTrackingEnabledChange');
  ```

### Updating the State Information of a Spatial Device

Call [updateSpatialDeviceState](../reference/apis/js-apis-audio.md#updatespatialdevicestate11) to update the state information of a spatial device. The state information includes the device address, support for spatial audio rendering and head tracking, and device form. This API can be called only by system applications with spatial audio setting capabilities (for example, a setting screen where users can change the spatial audio status). For details about the state information, see [AudioSpatialDeviceState](../reference/apis/js-apis-audio.md#audiospatialdevicestate).

  ```ts
  import audio from '@ohos.multimedia.audio';
  import { BusinessError } from '@ohos.base';

  let spatialDeviceState: audio.AudioSpatialDeviceState = {
    address: "123",
    isSpatializationSupported: true,
    isHeadTrackingSupported: true,
    spatialDeviceType: audio.AudioSpatialDeviceType.SPATIAL_DEVICE_TYPE_IN_EAR_HEADPHONE
  }
  try {
    audioSpatializationManager.updateSpatialDeviceState(spatialDeviceState);
    console.info(`AudioSpatializationManager updateSpatialDeviceState success`);
  } catch (err) {
    let error = err as BusinessError;
    console.error(`ERROR: ${error}`);
  }
  ```
