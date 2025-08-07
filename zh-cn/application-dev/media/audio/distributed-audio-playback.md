# 分布式音频播放(仅对系统应用开放)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--SE: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--TSE: @Filger-->

通过分布式音频播放的能力，用户可以将音频投播远端设备播放，实现音频在组网中不同设备之间流转。

开发者可以通过分布式音频播放，将当前设备播放的所有音频投放到指定的远端设备播放，或将设备播放的某个音频流投放到指定的远端设备播放。

## 开发步骤及示例

在将音频投播到组网内其他设备前，需要先获取组网内的设备列表，并监听设备连接状态的变化，具体开发步骤请参考[音频输出设备管理](audio-output-device-management.md)。

在获取组网内的设备列表时，可以通过指定DeviceFlag，筛选出需要的设备。

| 名称 | 说明 | 
| -------- | -------- |
| NONE_DEVICES_FLAG<sup>9+</sup> | 无设备。此接口为系统接口。 | 
| OUTPUT_DEVICES_FLAG | 本地输出设备。 | 
| INPUT_DEVICES_FLAG | 本地输入设备。 | 
| ALL_DEVICES_FLAG | 本地输入输出设备。 | 
| DISTRIBUTED_OUTPUT_DEVICES_FLAG<sup>9+</sup> | 分布式输出设备。&nbsp;此接口为系统接口。 | 
| DISTRIBUTED_INPUT_DEVICES_FLAG<sup>9+</sup> | 分布式输入设备。&nbsp;此接口为系统接口。 | 
| ALL_DISTRIBUTED_DEVICES_FLAG<sup>9+</sup> | 分布式输入输出设备。&nbsp;此接口为系统接口。 | 

具体接口说明请参考[AudioRoutingManager API文档](../../reference/apis-audio-kit/arkts-apis-audio-AudioRoutingManager.md)。

### 投播所有音频

1. [获取输出设备信息](audio-output-device-management.md#获取输出设备信息)。

2. 创建AudioDeviceDescriptor对象，用于指定音频输出设备。

3. 调用selectOutputDevice，将当前设备播放的所有音频投放到指定的远端设备播放。

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioManager = audio.getAudioManager();
let audioRoutingManager = audioManager.getRoutingManager();
let outputAudioDeviceDescriptor: audio.AudioDeviceDescriptors = [{
  deviceRole: audio.DeviceRole.OUTPUT_DEVICE,
  deviceType: audio.DeviceType.SPEAKER,
  id: 1,
  name: "",
  address: "",
  sampleRates: [44100],
  channelCounts: [2],
  channelMasks: [0],
  networkId: audio.LOCAL_NETWORK_ID,
  interruptGroupId: 1,
  volumeGroupId: 1,
  displayName: ""
}];

async function selectOutputDevice(): Promise<void> {
  audioRoutingManager.selectOutputDevice(outputAudioDeviceDescriptor, (err: BusinessError) => {
    if (err) {
      console.error(`Invoke selectOutputDevice failed, code is ${err.code}, message is ${err.message}`);
    } else {
      console.info('Invoke selectOutputDevice succeeded.');
    }
  });
}
```

### 投播指定音频流

1. [获取输出设备信息](audio-output-device-management.md#获取输出设备信息)。

2. 创建AudioRendererFilter对象，通过uid指定应用，通过rendererId指定音频流。

3. 创建AudioDeviceDescriptor对象，用于指定音频输出设备。

4. 调用selectOutputDeviceByFilter，将当前设备播放的指定音频流投放到指定的远端设备播放。
 
```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioManager = audio.getAudioManager();
let audioRoutingManager = audioManager.getRoutingManager();
let outputAudioRendererFilter: audio.AudioRendererFilter  = {
  uid: 20010041,
  rendererInfo: {
    usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // 音频流使用类型：音乐。根据业务场景配置，参考StreamUsage。
    rendererFlags: 0 // 音频渲染器标志。
  } as audio.AudioRendererInfo,
  rendererId: 0
};

let outputAudioDeviceDescriptor: audio.AudioDeviceDescriptors = [{
  deviceRole: audio.DeviceRole.OUTPUT_DEVICE,
  deviceType: audio.DeviceType.SPEAKER,
  id: 1,
  name: "",
  address: "",
  sampleRates: [44100],
  channelCounts: [2],
  channelMasks: [0],
  networkId: audio.LOCAL_NETWORK_ID,
  interruptGroupId: 1,
  volumeGroupId: 1,
  displayName: ""
}];

async function selectOutputDeviceByFilter(): Promise<void> {
  audioRoutingManager.selectOutputDeviceByFilter(outputAudioRendererFilter, outputAudioDeviceDescriptor, (err: BusinessError) => {
    if (err) {
      console.error(`Invoke selectOutputDeviceByFilter failed, code is ${err.code}, message is ${err.message}`);
    } else {
      console.info('Invoke selectOutputDeviceByFilter succeeded.');
    }
  });
}
```
