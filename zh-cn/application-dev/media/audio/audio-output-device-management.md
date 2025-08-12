# 管理全局音频输出设备
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--SE: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--TSE: @Filger-->
应用可通过以下两种方式管理全局音频输出设备：
- 通常情况下，可以通过[AudioRoutingManager管理全局音频输出设备](#通过audioroutingmanager管理全局音频输出设备)。
- 从API 20开始，AudioSessionManager提供了部分输出设备管理的接口，支持通过[AudioSession管理全局音频输出](#通过audiosession管理全局音频输出设备)，方便在使用AudioSession管理音频焦点的同时管理音频输出。
## 通过AudioRoutingManager管理全局音频输出设备

本模块提供音频输出设备管理能力，包括查询设备信息和监听连接状态变化。具体API说明请参考文档[AudioRoutingManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioRoutingManager.md)。

### 创建AudioRoutingManager实例

在使用AudioRoutingManager管理音频设备前，需要先导入模块并创建实例。

```ts
import { audio } from '@kit.AudioKit';  // 导入audio模块。

let audioManager = audio.getAudioManager();  // 需要先创建AudioManager实例。

let audioRoutingManager = audioManager.getRoutingManager();  // 再调用AudioManager的方法创建AudioRoutingManager实例。
```

### 支持的音频输出设备类型

目前支持的输出设备如下表所示：

| 名称 | 值 | 说明 | 
| -------- | -------- | -------- |
| EARPIECE | 1 | 听筒。 | 
| SPEAKER | 2 | 扬声器。 | 
| WIRED_HEADSET | 3 | 有线耳机，带麦克风。 | 
| WIRED_HEADPHONES | 4 | 有线耳机，无麦克风。 | 
| BLUETOOTH_SCO | 7 | 蓝牙设备SCO（Synchronous&nbsp;Connection&nbsp;Oriented）连接。 | 
| BLUETOOTH_A2DP | 8 | 蓝牙设备A2DP（Advanced&nbsp;Audio&nbsp;Distribution&nbsp;Profile）连接。 | 
| USB_HEADSET | 22 | USB耳机，带麦克风。 | 

### 获取输出设备信息

使用getDevices()方法可以获取当前所有输出设备的信息。

```ts
import { audio } from '@kit.AudioKit';

audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data: audio.AudioDeviceDescriptors) => {
  console.info('Promise returned to indicate that the device list is obtained.');
});
```

### 监听设备连接状态变化

设置监听事件以监控设备连接状态的变化，设备连接或断开时触发回调。

> **说明：**
>
> 监听设备连接状态变化可以监听到全部的设备连接状态变化，不建议作为应用处理自动暂停的依据。应用如需处理自动暂停相关业务，可参考[音频流输出设备变更原因](audio-output-device-change.md)。

```ts
import { audio } from '@kit.AudioKit';

// 监听音频设备状态变化。
audioRoutingManager.on('deviceChange', audio.DeviceFlag.OUTPUT_DEVICES_FLAG, (deviceChanged: audio.DeviceChangeAction) => {
  console.info(`device change type : ${deviceChanged.type}`);  // 设备连接状态变化，0为连接，1为断开连接。
  console.info(`device descriptor size : ${deviceChanged.deviceDescriptors.length}`);
  console.info(`device change descriptor : ${deviceChanged.deviceDescriptors[0].deviceRole}`);  // 设备角色。
  console.info(`device change descriptor : ${deviceChanged.deviceDescriptors[0].deviceType}`);  // 设备类型。
});

// 取消监听音频设备状态变化。
audioRoutingManager.off('deviceChange');
```

<!--Del-->
### 选择音频输出设备（仅对系统应用开放）

选择音频输出设备，当前只能选择一个输出设备，以设备ID作为唯一标识。AudioDeviceDescriptors的具体信息可以参考[AudioDeviceDescriptors](../../reference/apis-audio-kit/arkts-apis-audio-t.md#audiodevicedescriptors)。

> **说明：**
>
> 用户可以选择连接一组音频设备（如一对蓝牙耳机），但系统侧只感知为一个设备，该组设备共用一个设备ID。

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let outputAudioDeviceDescriptor: audio.AudioDeviceDescriptors = [{
    deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
    deviceType : audio.DeviceType.SPEAKER,
    id : 1,
    name : "",
    address : "",
    sampleRates : [44100],
    channelCounts : [2],
    channelMasks : [0],
    networkId : audio.LOCAL_NETWORK_ID,
    interruptGroupId : 1,
    volumeGroupId : 1,
    displayName : ""
}];

async function selectOutputDevice() {
  audioRoutingManager.selectOutputDevice(outputAudioDeviceDescriptor).then(() => {
    console.info('Invoke selectOutputDevice succeeded.');
  }).catch((err: BusinessError) => {
    console.error(`Invoke selectOutputDevice failed, code is ${err.code}, message is ${err.message}`);
  });
}
```
<!--DelEnd-->

### 获取最高优先级输出设备信息

使用getPreferOutputDeviceForRendererInfo()方法, 可以获取当前最高优先级的输出设备。

> **说明：**
>
> 最高优先级输出设备表示声音将在此设备输出的设备。

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rendererInfo: audio.AudioRendererInfo = {
    usage: audio.StreamUsage.STREAM_USAGE_MUSIC,// 音频流使用类型：音乐。根据业务场景配置，参考StreamUsage。
    rendererFlags: 0 // 音频渲染器标志。
};

async function getPreferOutputDeviceForRendererInfo() {
  audioRoutingManager.getPreferOutputDeviceForRendererInfo(rendererInfo).then((desc: audio.AudioDeviceDescriptors) => {
    console.info(`device descriptor: ${desc}`);
  }).catch((err: BusinessError) => {
    console.error(`Result ERROR: ${err}`);
  })
}
```

### 监听最高优先级输出设备变化

```ts
import { audio } from '@kit.AudioKit';

let rendererInfo: audio.AudioRendererInfo = {
    usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // 音频流使用类型：音乐。根据业务场景配置，参考StreamUsage。
    rendererFlags: 0 // 音频渲染器标志。
};

// 监听最高优先级输出设备变化。
audioRoutingManager.on('preferOutputDeviceChangeForRendererInfo', rendererInfo, (desc: audio.AudioDeviceDescriptors) => {
    console.info(`device change descriptor : ${desc[0].deviceRole}`);  // 设备角色。
    console.info(`device change descriptor : ${desc[0].deviceType}`);  // 设备类型。
});

// 取消监听最高优先级输出设备变化。
audioRoutingManager.off('preferOutputDeviceChangeForRendererInfo');
```

## 通过AudioSession管理全局音频输出设备
应用使用播放器的SDK播放音频流，不持有AudioRenderer对象，因此无法灵活控制播放设备的选择和状态监听。从API 20开始，AudioSession不仅增加了焦点管理功能，还提供了音频输出设备管理功能，包括设置默认输出设备和监听设备变化。请参考以下文档获取更多信息：
- ArkTS API：[AudiSessionManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md)
- C API：[OH_AudioSessionManager](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md)

### 创建AudioSession实例
在使用AudioSessionManager管理音频设备前，需要先导入模块并创建实例。
```ts
import { audio } from '@kit.AudioKit';  // 导入audio模块。

let audioManager = audio.getAudioManager();  // 需要先创建AudioManager实例。

let audioSessionManager = audioManager.getSessionManager();  // 再调用AudioManager的方法创建AudioSessionManager实例。
```

### 设置本机默认音频输出设备

[setDefaultOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setdefaultoutputdevice20)可以用于设置本机默认输出设备。
> **说明：**
>- 由于AudioSession是应用级设置，调用本接口设置默认音频输出设备会覆盖AudioRenderer的`setDefaultOutputDevice`接口设置的音频输出设备信息。
> - 调用`setDefaultOutputDevice`设置音频输出设备后，如需取消，可将参数设为`audio.DeviceType.DEFAULT`，将音频设备选择权交还给系统。否则，每次调用`activateAudioSession`时，应用选择的默认输出设备将生效。

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 设置默认输出设备为本机扬声器。
audioSessionManager.setDefaultOutputDevice(audio.DeviceType.SPEAKER).then(() => {
  console.info('setDefaultOutputDevice Success!');
}).catch((err: BusinessError) => {
  console.error(`setDefaultOutputDevice Fail: ${err}`);
});

// 设置默认输出设备为默认设备，即取消应用设置的默认设备，交由系统选择设备。
audioSessionManager.setDefaultOutputDevice(audio.DeviceType.DEFAULT).then(() => {
  console.info('setDefaultOutputDevice Success!');
}).catch((err: BusinessError) => {
  console.error(`setDefaultOutputDevice Fail: ${err}`);
});
```

### 查询本机默认音频输出设备

应用可以通过[getDefaultOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#getdefaultoutputdevice20)查询本机默认输出设备类型。
> **说明：**
>
> 本接口用于查询通过[setDefaultOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setdefaultoutputdevice20)接口设置的输出设备。

```ts
let deviceType = audioSessionManager.getDefaultOutputDevice();
console.info('getDefaultOutputDevice Success, deviceType: ${deviceType}');
```

### 监听输出设备变化

应用可以通过注册[CurrentOutputDeviceChangedEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#currentoutputdevicechangedevent20)监听输出设备的连接状态变化。

> **说明：**
>`currentOutputDeviceChangedCallback` 包含设备变更的原因及推荐的后续操作。应用应根据不同的变更原因进行处理，并按系统推荐的操作继续或停止当前播放。

```ts
import { audio } from '@kit.AudioKit';

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let currentOutputDeviceChangedCallback = (currentOutputDeviceChangedEvent: audio.CurrentOutputDeviceChangedEvent) => {
  console.info(`reason of audioSessionStateChanged: ${currentOutputDeviceChangedEvent.changeReason} `);

  switch (currentOutputDeviceChangedEvent.changeReason) {
    case audio.AudioStreamDeviceChangeReason.REASON_OLD_DEVICE_UNAVAILABLE:
      // 响应设备不可用事件，如果应用处于播放状态，应暂停播放，更新UX界面。
      break;
    case audio.AudioStreamDeviceChangeReason.REASON_NEW_DEVICE_AVAILABLE:
      // 应用根据业务情况响应设备可用事件。
      break;
    case audio.AudioStreamDeviceChangeReason.REASON_OVERRODE:
      // 应用根据业务情况响应设备强选事件。
      break;
    case audio.AudioStreamDeviceChangeReason.REASON_SESSION_ACTIVATED:
      // 应用根据业务情况响应audio session激活时的输出设备信息。
      break;
    case audio.AudioStreamDeviceChangeReason.REASON_STREAM_PRIORITY_CHANGED:
      // 应用根据业务情况响应其它更高优先级的音频流触发的设备变更事件。
      break;
    case audio.AudioStreamDeviceChangeReason.REASON_UNKNOWN:
      // 应用根据业务情况响应未知原因事件。
      break;
  }
};

audioSessionManager.on('currentOutputDeviceChanged', currentOutputDeviceChangedCallback);

audioSessionManager.off('currentOutputDeviceChanged', currentOutputDeviceChangedCallback);

// 取消该事件的所有监听。
audioSessionManager.off('currentOutputDeviceChanged');
```