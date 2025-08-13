# 空间音频管理
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--SE: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--TSE: @Filger-->

空间音频是一种能够将传统的立体声体验扩展到三维空间的音频技术，在单声道、立体声、环绕声基础上，增加高度感知，营造全方位的听音体验的音频技术。空间音频为用户提供沉浸的、有互动的、有空间感的“声”临其境的音频体验。

Audio Vivid是基于AI技术的音频编解码标准，由世界超高清视频产业联盟（UWA）与数字音视频编解码技术标准工作组（AVS）联合制定，共同发布。包含音频PCM数据以及元数据的音频格式，相比传统立体声音源，Audio Vivid包含音频内容源的元数据信息，能够还原物理和感知世界中的真实听感，打造极致的沉浸式听觉体验。

空间音频支持播放多声道、立体声、Audio Vivid等格式音源，并在耳机实现双耳空间音频渲染重放。搭配Audio Vivid格式音源的空间音频渲染，能够将音乐中的人声和各种乐器作为独立的声音对象，重新定义各种声音对象的位置、移动轨迹和声音大小、远近等要素，实现声音在听众四周及上方全面萦绕，实现更佳的空间音频沉浸式体验，获得影院、音乐厅等的临场感与艺术体验。当设备支持空间音频且空间音频开关被打开时，下发Audio Vivid格式音源可以得到更加沉浸的音频体验。关于如何播放Audio Vivid音源，可参考[播放Audio Vivid音源](using-ohaudio-for-playback.md#播放audio-vivid格式音源)。

## 使用说明

对于播放音频类的应用，开发者可以查询到设备是否有支持空间音频的能力，以及当前设备空间音频的开关状态。

### 创建空间音频示例

应用开发者在使用AudioSpatializationManager的API前，需要先用[getSpatializationManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioManager.md#getspatializationmanager18)创建一个AudioSpatializationManager实例。

  ```ts
  import { audio } from '@kit.AudioKit';

  let audioManager = audio.getAudioManager();
  let audioSpatializationManager = audioManager.getSpatializationManager();
  ```

### 查询设备是否支持空间音频渲染能力

应用开发者可以使用[AudioDeviceDescriptor](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiodevicedescriptor)的spatializationSupported属性获取指定设备是否具有空间音频渲染的能力，需要通过音频框架中其他接口来获取当前已连接设备或当前发声设备的AudioDeviceDescriptor。

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

### 查询当前发声设备的空间音频渲染效果开关状态

应用开发者可以通过[isSpatializationEnabledForCurrentDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioSpatializationManager.md#isspatializationenabledforcurrentdevice18)接口查询当前设备的空间音频渲染效果开关状态。

- 该接口返回true表示当前设备空间音频渲染开启，返回false表示当前设备空间音频渲染关闭。
- 该状态仅为开关状态，实际是否生效还需依赖当前设备是否支持空间音频渲染。

  ```ts
  import { audio } from '@kit.AudioKit';

  let isSpatializationEnabledForCurrentDevice: boolean = audioSpatializationManager.isSpatializationEnabledForCurrentDevice();
  console.info(`AudioSpatializationManager isSpatializationEnabledForCurrentDevice: ${isSpatializationEnabledForCurrentDevice}`);
  ```

**订阅当前发声设备空间音频渲染效果的开关状态变化事件**

应用开发者可以通过[on('spatializationEnabledChangeForCurrentDevice')](../../reference/apis-audio-kit/arkts-apis-audio-AudioSpatializationManager.md#onspatializationenabledchangeforcurrentdevice18)接口订阅当前空间音频渲染效果的开关状态变化事件。

该接口返回true表示空间音频渲染被开启，返回false表示空间音频渲染被关闭。

  ```ts
  import { audio } from '@kit.AudioKit';

  audioSpatializationManager.on('spatializationEnabledChangeForCurrentDevice', (isSpatializationEnabledForCurrentDevice: boolean) => {
    console.info(`isSpatializationEnabledForCurrentDevice: ${isSpatializationEnabledForCurrentDevice}`);
  });
  ```

**取消订阅当前发声设备空间音频渲染效果的开关状态变化事件**

应用开发者可以通过[off('spatializationEnabledChangeForCurrentDevice')](../../reference/apis-audio-kit/arkts-apis-audio-AudioSpatializationManager.md#offspatializationenabledchangeforcurrentdevice18)接口取消订阅空间音频渲染效果的开关状态变化事件。

  ```ts
  import { audio } from '@kit.AudioKit';
  audioSpatializationManager.off('spatializationEnabledChangeForCurrentDevice');
  ```