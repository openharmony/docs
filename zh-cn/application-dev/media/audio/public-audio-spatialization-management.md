# 空间音频管理

空间音频管理主要包含空间音频支持能力的查询和开关状态的查询与监听。

## 获取空间音频管理接口

创建AudioSpatializationManager实例。在使用AudioSpatializationManager的API前，需要使用getSpatializationManager()创建一个AudioSpatializationManager实例。

  ```ts
  import { audio } from '@kit.AudioKit';

  let audioManager = audio.getAudioManager();
  let audioSpatializationManager = audioManager.getSpatializationManager();
  ```

## 查询设备是否支持空间音频渲染能力

应用开发者可以使用AudioDeviceDescriptor的spatializationSupported属性获取指定设备是否具有空间音频渲染的能力，需要通过音频框架中其他接口来获取当前已连接设备或当前发声设备的AudioDeviceDescriptor。AudioDeviceDescriptor的具体信息可以参考[AudioDeviceDescriptor](../../reference/apis-audio-kit/js-apis-audio.md#audiodevicedescriptor)。

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

## 查询当前发声设备的空间音频渲染效果开关状态

应用开发者可以通过[isSpatializationEnabledForCurrentDevice](../../reference/apis-audio-kit/js-apis-audio.md#isSpatializationEnabledForCurrentDevice18)接口查询当前设备的空间音频渲染效果开关状态，该接口返回为true表示当前设备空间音频渲染开启，false表示当前设备空间音频渲染关闭。该状态仅为开关状态，实际是否生效还需依赖当前设备是否支持空间音频渲染。
[isAudioSessionActivated](../../reference/apis-audio-kit/js-apis-audio.md#isaudiosessionactivated12)
  ```ts
  import { audio } from '@kit.AudioKit';

  let isSpatializationEnabledForCurrentDevice: boolean = audioSpatializationManager.isSpatializationEnabledForCurrentDevice();
  console.info(`AudioSpatializationManager isSpatializationEnabledForCurrentDevice: ${isSpatializationEnabledForCurrentDevice}`);
  ```

## 订阅当前发声设备空间音频渲染效果的开关状态变化事件

应用开发者可以通过[on('spatializationEnabledChangeForCurrentDevice')](../../reference/apis-audio-kit/js-apis-audio.md#onspatializationEnabledChangeForCurrentDevice18)接口订阅当前空间音频渲染效果的开关状态变化事件，回调为true表示空间音频渲染被开启，false表示空间音频渲染被关闭。

  ```ts
  import { audio } from '@kit.AudioKit';

  audioSpatializationManager.on('spatializationEnabledChangeForCurrentDevice', (isSpatializationEnabledForCurrentDevice: boolean) => {
    console.info(`isSpatializationEnabledForCurrentDevice: ${isSpatializationEnabledForCurrentDevice}`);
  });
  ```

## 取消订阅当前发声设备空间音频渲染效果的开关状态变化事件

应用开发者可以通过[off('spatializationEnabledChangeForCurrentDevice')](../../reference/apis-audio-kit/js-apis-audio.md#offspatializationEnabledChangeForCurrentDevice18)接口取消订阅空间音频渲染效果的开关状态变化事件。

  ```ts
  import { audio } from '@kit.AudioKit';
  audioSpatializationManager.off('spatializationEnabledChangeForCurrentDevice');
  ```