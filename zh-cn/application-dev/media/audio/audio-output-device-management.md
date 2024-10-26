# 管理全局音频输出设备

有时设备同时连接多个音频输出设备，需要指定音频输出设备进行音频播放，此时需要使用AudioRoutingManager接口进行输出设备的管理，API说明可以参考[AudioRoutingManager API文档](../../reference/apis-audio-kit/js-apis-audio.md#audioroutingmanager9)。

## 创建AudioRoutingManager实例

在使用AudioRoutingManager管理音频设备前，需要先导入模块并创建实例。

```ts
import { audio } from '@kit.AudioKit';  // 导入audio模块

let audioManager = audio.getAudioManager();  // 需要先创建AudioManager实例

let audioRoutingManager = audioManager.getRoutingManager();  // 再调用AudioManager的方法创建AudioRoutingManager实例
```

## 支持的音频输出设备类型

目前支持的音频输出设备见下表：

| 名称 | 值 | 说明 | 
| -------- | -------- | -------- |
| EARPIECE | 1 | 听筒。 | 
| SPEAKER | 2 | 扬声器。 | 
| WIRED_HEADSET | 3 | 有线耳机，带麦克风。 | 
| WIRED_HEADPHONES | 4 | 有线耳机，无麦克风。 | 
| BLUETOOTH_SCO | 7 | 蓝牙设备SCO（Synchronous&nbsp;Connection&nbsp;Oriented）连接。 | 
| BLUETOOTH_A2DP | 8 | 蓝牙设备A2DP（Advanced&nbsp;Audio&nbsp;Distribution&nbsp;Profile）连接。 | 
| USB_HEADSET | 22 | USB耳机，带麦克风。 | 

## 获取输出设备信息

使用getDevices()方法可以获取当前所有输出设备的信息。

```ts
import { audio } from '@kit.AudioKit';

audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data: audio.AudioDeviceDescriptors) => {
  console.info('Promise returned to indicate that the device list is obtained.');
});
```

## 监听设备连接状态变化

可以设置监听事件来监听设备连接状态的变化，当有设备连接或断开时触发回调：

```ts
import { audio } from '@kit.AudioKit';

// 监听音频设备状态变化
audioRoutingManager.on('deviceChange', audio.DeviceFlag.OUTPUT_DEVICES_FLAG, (deviceChanged: audio.DeviceChangeAction) => {
  console.info(`device change type : ${deviceChanged.type}`);  // 设备连接状态变化，0为连接，1为断开连接
  console.info(`device descriptor size : ${deviceChanged.deviceDescriptors.length}`);
  console.info(`device change descriptor : ${deviceChanged.deviceDescriptors[0].deviceRole}`);  // 设备角色
  console.info(`device change descriptor : ${deviceChanged.deviceDescriptors[0].deviceType}`);  // 设备类型
});

// 取消监听音频设备状态变化
audioRoutingManager.off('deviceChange');
```

<!--Del-->
## 选择音频输出设备（仅对系统应用开放）

选择音频输出设备，当前只能选择一个输出设备，以设备ID作为唯一标识。AudioDeviceDescriptors的具体信息可以参考[AudioDeviceDescriptors](../../reference/apis-audio-kit/js-apis-audio.md#audiodevicedescriptors)。

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

## 获取最高优先级输出设备信息

使用getPreferOutputDeviceForRendererInfo()方法, 可以获取当前最高优先级的输出设备。

> **说明：**
>
> 最高优先级输出设备表示声音将在此设备输出的设备。

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rendererInfo: audio.AudioRendererInfo = {
    usage : audio.StreamUsage.STREAM_USAGE_MUSIC,
    rendererFlags : 0
};

async function getPreferOutputDeviceForRendererInfo() {
  audioRoutingManager.getPreferOutputDeviceForRendererInfo(rendererInfo).then((desc: audio.AudioDeviceDescriptors) => {
    console.info(`device descriptor: ${desc}`);
  }).catch((err: BusinessError) => {
    console.error(`Result ERROR: ${err}`);
  })
}
```

## 监听最高优先级输出设备变化

```ts
import { audio } from '@kit.AudioKit';

let rendererInfo: audio.AudioRendererInfo = {
    usage : audio.StreamUsage.STREAM_USAGE_MUSIC,
    rendererFlags : 0
};

// 监听最高优先级输出设备变化
audioRoutingManager.on('preferOutputDeviceChangeForRendererInfo', rendererInfo, (desc: audio.AudioDeviceDescriptors) => {
    console.info(`device change descriptor : ${desc[0].deviceRole}`);  // 设备角色
    console.info(`device change descriptor : ${desc[0].deviceType}`);  // 设备类型
});

// 取消监听最高优先级输出设备变化
audioRoutingManager.off('preferOutputDeviceChangeForRendererInfo');
```
