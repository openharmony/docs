# 使用分布式媒体会话(仅对系统应用开放)

## 基本概念

- 远端媒体会话：可信组网内的设备创建本地媒体会话后，媒体会话服务会将本地会话自动同步到远端，生成远端媒体会话。本地媒体会话与远端媒体会话时刻保持同步。

- 远端媒体会话控制器：远端投播后，远端设备上的媒体会话控制器。

## 接口说明

使用分布式媒体会话进行远端投播时使用的关键接口如下表所示。接口返回值有两种返回形式：callback和promise，下表中为callback形式接口，promise和callback只是返回值方式不一样，功能相同。

更多API说明请参见[API文档](../../reference/apis-avsession-kit/js-apis-avsession.md)。

| 接口名 | 说明 | 
| -------- | -------- |
| castAudio(session: SessionToken \| 'all', audioDevices: Array&lt;audio.AudioDeviceDescriptor&gt;, callback: AsyncCallback&lt;void&gt;): void | 投播会话到指定设备列表。 | 

## 开发步骤

系统应用作为媒体会话控制方接入媒体会话时，根据需要使用分布式媒体会话进行投播的步骤如下所示：

1. 导入模块接口。由于在进行投播之前，需要从audio模块获取音频设备描述符AudioDeviceDescriptor，所以除了导入AVSessionManager模块外，还需要导入audio模块。
     
```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { audio } from '@kit.AudioKit';
```

2. 通过AVSessionManager的castAudio接口将当前设备所有会话投播到其他设备。
     
```ts
import { avSession as AVSessionManager } from '@kit.AVSessionKit';
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function castAudio() {
  // 投播到其他设备
  let audioManager = audio.getAudioManager();
  let audioRoutingManager = audioManager.getRoutingManager();
  let audioDevices: audio.AudioDeviceDescriptors | undefined = undefined;
  audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
    audioDevices = data;
    console.info(`Promise returned to indicate that the device list is obtained.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get devices. Code: ${err.code}, message: ${err.message}`);
  });
  if (audioDevices !== undefined) {
    AVSessionManager.castAudio('all', audioDevices as audio.AudioDeviceDescriptors).then(() => {
      console.info(`createController : SUCCESS`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to cast audio. Code: ${err.code}, message: ${err.message}`);
    });
  }
}

```

   系统应用在投播主控端发起投播后，媒体会话框架会通知远端设备的AVSession服务创建远端媒体会话。投播主控端的媒体会话变化时（例如媒体信息变化、播放状态变化等），媒体会话框架会自动同步变化到远端设备。

   远端设备上的媒体会话处理机制，与本地设备上的机制保持一致，即远端设备上的媒体会话控制方，例如播控中心，会监听媒体会话创建事件，并创建相应的远端媒体会话控制器对远端媒体会话进行管理，而管理过程中的控制命令会由媒体会话框架自动同步到投播主控端设备。

   本地投播主控端中的媒体会话提供方，例如各音视频应用，会监听各类播控命令事件，从而可以及时响应来自远端设备的各类播控命令。
