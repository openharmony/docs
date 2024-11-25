# 空间音频管理（仅对系统应用开放）

空间音频管理主要包含空间音频相关状态和能力的查询、设置与监听。

空间音频管理仅开放给系统级应用，主要包括空间音频相关状态（空间音频渲染的开启与关闭、头动跟踪的开启与关闭）的查询、设置与监听，空间音频相关能力（空间音频渲染能力、头动跟踪能力）的查询，空间化设备状态的更新，以及空间音频渲染场景类型的查询与设置。

对于播放音频类的系统级应用，开发者可以查询空间音频渲染与头动跟踪的开关状态，系统/指定设备是否支持空间音频渲染与头动跟踪能力，以及当前使用的空间音频渲染场景类型。

对于空间音频控制类的系统级应用（比如空间音频UX等），开发者在查询上述状态和能力之外，还可以对空间音频渲染开关、头动跟踪开关以及空间音频渲染场景类型进行设置，以及更新空间化设备的状态，指明特定空间化设备是否支持空间音频渲染和头动跟踪能力。
在使用此功能前，应用需要先申请权限`ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS`，申请方式请参考：[申请应用权限](../../security/AccessToken/determine-application-mode.md#system_basic等级应用申请权限的方式)。

## 获取空间音频管理接口

创建AudioSpatializationManager实例。在使用AudioSpatializationManager的API前，需要使用getSpatializationManager()创建一个AudioSpatializationManager实例。

  ```ts
  import { audio } from '@kit.AudioKit';

  let audioManager = audio.getAudioManager();
  let audioSpatializationManager = audioManager.getSpatializationManager();
  ```

## 查询系统是否支持空间音频渲染能力

系统应用开发者可以通过[isSpatializationSupported](../../reference/apis-audio-kit/js-apis-audio-sys.md#isspatializationsupported11)接口查询当前系统是否具有空间音频渲染的能力。

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

## 查询指定设备是否支持空间音频渲染能力

系统应用开发者可以通过[isSpatializationSupportedForDevice](../../reference/apis-audio-kit/js-apis-audio-sys.md#isspatializationsupportedfordevice11)接口查询指定设备是否具有空间音频渲染的能力，开发者需要使用AudioDeviceDescriptor作为入参来指定设备，建议通过音频框架中其他接口来获取当前已连接设备或当前发声设备的AudioDeviceDescriptor。AudioDeviceDescriptor的具体信息可以参考[AudioDeviceDescriptor](../../reference/apis-audio-kit/js-apis-audio.md#audiodevicedescriptor)。

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

## 查询系统是否支持头动跟踪能力

系统应用开发者可以通过[isHeadTrackingSupported](../../reference/apis-audio-kit/js-apis-audio-sys.md#isheadtrackingsupported11)接口查询当前系统是否具有头动跟踪的能力。

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

## 查询指定设备是否支持头动跟踪能力

系统应用开发者可以通过[isHeadTrackingSupportedForDevice](../../reference/apis-audio-kit/js-apis-audio-sys.md#isheadtrackingsupportedfordevice11)接口查询指定设备是否具有头动跟踪的能力，开发者需要使用AudioDeviceDescriptor作为入参来指定设备，建议通过音频框架中其他接口来获取当前已连接设备或当前发声设备的AudioDeviceDescriptor。AudioDeviceDescriptor的具体信息可以参考[AudioDeviceDescriptor](../../reference/apis-audio-kit/js-apis-audio.md#audiodevicedescriptor)。

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

## 开启/关闭指定设备的空间音频渲染效果

系统应用开发者可以通过[setSpatializationEnabled](../../reference/apis-audio-kit/js-apis-audio-sys.md#setspatializationenabled12)接口开启/关闭指定设备的空间音频渲染效果，该接口需要传递两个参数：AudioDeviceDescriptor和enabled。

AudioDeviceDescriptor：用于指定音频设备。建议通过音频框架中其他接口来获取当前已连接设备或当前发声设备的AudioDeviceDescriptor。AudioDeviceDescriptor的具体信息可以参考[AudioDeviceDescriptor](../../reference/apis-audio-kit/js-apis-audio.md#audiodevicedescriptor)。
enabled：布尔值类型，用于控制指定设备的空间音频渲染开关。入参为true时为开启空间音频渲染，入参为false时为关闭空间音频渲染。

在使用此功能前，应用需要先申请权限`ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS`，申请方式请参考：[申请应用权限](../../security/AccessToken/determine-application-mode.md#system_basic等级应用申请权限的方式)。

在开启空间音频渲染时，需要先确保系统和指定设备都具有空间音频渲染的能力。

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

## 查询指定设备的空间音频渲染效果开关状态

系统应用开发者可以通过[isSpatializationEnabled](../../reference/apis-audio-kit/js-apis-audio-sys.md#isspatializationenabled12)接口查询指定设备的空间音频渲染效果开关状态，开发者需要使用AudioDeviceDescriptor作为入参来指定设备，建议通过音频框架中其他接口来获取当前已连接设备或当前发声设备的AudioDeviceDescriptor。AudioDeviceDescriptor的具体信息可以参考[AudioDeviceDescriptor](../../reference/apis-audio-kit/js-apis-audio.md#audiodevicedescriptor)。该接口返回为true表示空间音频渲染开启，false表示空间音频渲染关闭。返回值为setSpatializationEnabled接口中成功设置的指定设备空间音频渲染开关状态，默认为关闭。该状态仅为开关状态，实际是否生效还需依赖系统和指定设备是否支持空间音频渲染。

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

## 订阅空间音频渲染效果的开关状态变化事件

系统应用开发者可以通过[on('spatializationEnabledChangeForAnyDevice')](../../reference/apis-audio-kit/js-apis-audio-sys.md#onspatializationenabledchangeforanydevice12)接口订阅空间音频渲染效果的开关状态变化事件，回调包含AudioSpatialEnabledStateForDevice参数，AudioSpatialEnabledStateForDevice包含deviceDescriptor和enabled属性，其中deviceDescriptor为被改变设备的描述信息，enabled为true表示空间音频渲染被开启，false表示空间音频渲染被关闭，具体信息可以参考[AudioSpatialEnabledStateForDevice](../../reference/apis-audio-kit/js-apis-audio-sys.md#audiospatialenabledstatefordevice12)。当开发者通过setSpatializationEnabled接口成功地改变了任一设备的空间音频渲染开关状态时，回调将被触发。

  ```ts
  import { audio } from '@kit.AudioKit';

  audioSpatializationManager.on('spatializationEnabledChangeForAnyDevice', (audioSpatialEnabledStateForDevice: audio.AudioSpatialEnabledStateForDevice) => {
    console.info(`deviceDescriptor: ${audioSpatialEnabledStateForDevice.deviceDescriptor}`);
    console.info(`isSpatializationEnabled: ${audioSpatialEnabledStateForDevice.enabled}`);
  });
  ```

## 取消订阅空间音频渲染效果的开关状态变化事件

系统应用开发者可以通过[off('spatializationEnabledChangeForAnyDevice')](../../reference/apis-audio-kit/js-apis-audio-sys.md#offspatializationenabledchangeforanydevice12)接口取消订阅空间音频渲染效果的开关状态变化事件。

  ```ts
  import { audio } from '@kit.AudioKit';
  audioSpatializationManager.off('spatializationEnabledChangeForAnyDevice');
  ```

## 开启/关闭指定设备的头动跟踪效果

系统应用开发者可以通过[setHeadTrackingEnabled](../../reference/apis-audio-kit/js-apis-audio-sys.md#setheadtrackingenabled12)接口开启/关闭指定设备的空间音频渲染效果，该接口需要传递两个参数：AudioDeviceDescriptor和enabled。

AudioDeviceDescriptor：用于指定音频设备。建议通过音频框架中其他接口来获取当前已连接设备或当前发声设备的AudioDeviceDescriptor。AudioDeviceDescriptor的具体信息可以参考[AudioDeviceDescriptor](../../reference/apis-audio-kit/js-apis-audio.md#audiodevicedescriptor)。
enabled：布尔值类型，用于控制指定设备的头动跟踪开关。入参为true时为开启头动跟踪，入参为false时为关闭头动跟踪。

在使用此功能前，应用需要先申请权限`ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS`，申请方式请参考：[申请应用权限](../../security/AccessToken/determine-application-mode.md#system_basic等级应用申请权限的方式)。

在开启头动跟踪时，需要先确保系统和指定设备都具有头动跟踪的能力，同时头动跟踪效果的生效依赖于空间音频渲染开关打开。

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

## 查询指定设备的头动跟踪效果开关状态

系统应用开发者可以通过[isHeadTrackingEnabled](../../reference/apis-audio-kit/js-apis-audio-sys.md#isheadtrackingenabled12)接口查询指定设备的头动跟踪效果开关状态，开发者需要使用AudioDeviceDescriptor作为入参来指定设备，建议通过音频框架中其他接口来获取当前已连接设备或当前发声设备的AudioDeviceDescriptor。AudioDeviceDescriptor的具体信息可以参考[AudioDeviceDescriptor](../../reference/apis-audio-kit/js-apis-audio.md#audiodevicedescriptor)。该接口返回为true表示头动跟踪开启，false表示头动跟踪关闭。返回值为setHeadTrackingEnabled接口中成功设置的指定设备头动跟踪开关状态，默认为关闭。该状态仅为开关状态，实际是否生效还需依赖系统和指定设备是否支持头动跟踪，以及指定设备空间音频渲染开关是否打开。

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

## 订阅头动跟踪效果的开关状态变化事件

系统应用开发者可以通过[on('headTrackingEnabledChangeForAnyDevice')](../../reference/apis-audio-kit/js-apis-audio-sys.md#onheadtrackingenabledchangeforanydevice12)接口订阅头动跟踪效果的开关状态变化事件，回调包含AudioSpatialEnabledStateForDevice参数，AudioSpatialEnabledStateForDevice包含deviceDescriptor和enabled属性，其中deviceDescriptor为被改变设备的描述信息，enabled为true表示头动跟踪被开启，false表示头动跟踪被关闭。具体信息可以参考[AudioSpatialEnabledStateForDevice](../../reference/apis-audio-kit/js-apis-audio-sys.md#audiospatialenabledstatefordevice12)。当开发者通过setHeadTrackingEnabled接口成功地改变了任一设备的头动跟踪开关状态时，回调将被触发。

  ```ts
  import { audio } from '@kit.AudioKit';

  audioSpatializationManager.on('headTrackingEnabledChangeForAnyDevice', (audioSpatialEnabledStateForDevice: audio.AudioSpatialEnabledStateForDevice) => {
    console.info(`deviceDescriptor: ${audioSpatialEnabledStateForDevice.deviceDescriptor}`);
    console.info(`isSpatializationEnabled: ${audioSpatialEnabledStateForDevice.enabled}`);
  });
  ```

## 取消订阅头动跟踪效果的开关状态变化事件

系统应用开发者可以通过[off('headTrackingEnabledChangeForAnyDevice')](../../reference/apis-audio-kit/js-apis-audio-sys.md#offheadtrackingenabledchangeforanydevice12)接口取消订阅头动跟踪效果的开关状态变化事件。

  ```ts
  import { audio } from '@kit.AudioKit';
  audioSpatializationManager.off('headTrackingEnabledChangeForAnyDevice');
  ```

## 更新空间化设备状态

系统应用开发者可以通过[updateSpatialDeviceState](../../reference/apis-audio-kit/js-apis-audio-sys.md#updatespatialdevicestate11)接口更新空间化设备状态，空间化设备状态包含设备的地址、是否具有空间音频渲染的能力、是否具有头动跟踪的能力和设备的形态类型。

在使用此功能前，应用需要先申请权限`ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS`，申请方式请参考：[申请应用权限](../../security/AccessToken/determine-application-mode.md#system_basic等级应用申请权限的方式)。

空间化设备状态AudioSpatialDeviceState的具体信息可以参考[AudioSpatialDeviceState](../../reference/apis-audio-kit/js-apis-audio-sys.md#audiospatialdevicestate11)。

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

## 设置空间音频渲染场景类型

系统应用开发者可以通过[setSpatializationSceneType](../../reference/apis-audio-kit/js-apis-audio-sys.md#setspatializationscenetype12)接口设置空间音频渲染场景类型，可以选择默认场景、音乐场景、电影场景或有声读物场景，默认为默认场景。空间音频渲染场景类型的生效依赖空间音频渲染开关的打开。

在使用此功能前，应用需要先申请权限`ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS`，申请方式请参考：[申请应用权限](../../security/AccessToken/determine-application-mode.md#system_basic等级应用申请权限的方式)。

空间音频渲染场景类型AudioSpatializationSceneType的具体信息可以参考[AudioSpatializationSceneType](../../reference/apis-audio-kit/js-apis-audio-sys.md#audiospatializationscenetype12)。

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

## 查询空间音频渲染场景类型

系统应用开发者可以通过[getSpatializationSceneType](../../reference/apis-audio-kit/js-apis-audio-sys.md#getspatializationscenetype12)接口查询当前空间音频渲染场景类型。该接口将返回setSpatializationSceneType()接口中成功设置的值，默认为默认场景。

空间音频渲染场景类型AudioSpatializationSceneType的具体信息可以参考[AudioSpatializationSceneType](../../reference/apis-audio-kit/js-apis-audio-sys.md#audiospatializationscenetype12)。

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