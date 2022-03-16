# 音频管理开发指导

## 场景介绍

音频管理的主要工作是音量调节与音量查询，以及输入/输出设备查询。


## 接口说明

**表1** audio的相关接口

| 接口名 | 描述 |
| -------- | -------- |
| getAudioManager():&nbsp;AudioManager | 获得音频管理器。 |
| AudioManager | 音频管理器。具体参考表&nbsp;音频管理相关的interface&nbsp;AudioManager。 |
| AudioDeviceDescriptor | 描述音频设备。 |
| AudioVolumeType | 表示音频流类型的枚举。 |
| DeviceFlag | 表示可获取的设备种类的枚举。 |
| DeviceRole | 表示设备角色的枚举。 |
| DeviceType | 表示设备类型的枚举。 |
| AudioScene | 表示音频场景的枚举。 |

**表2** 音频管理相关的interface  **AudioManager**

| 接口名 | 描述 |
| -------- | -------- |
| setVolume(audioType:&nbsp;AudioVolumeType,volume:&nbsp;number,callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | 改变某个流的音量。 |
| setVolume(audioType:&nbsp;AudioVolumeType,volume:&nbsp;number):&nbsp;Promise&lt;void&gt; | 改变某个流的音量。 |
| getVolume(audioType:&nbsp;AudioVolumeType,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void | 获得某个流的音量。 |
| getVolume(audioType:&nbsp;AudioVolumeType):&nbsp;Promise&lt;number&gt; | 获得某个流的音量。 |
| getMinVolume(audioType:&nbsp;AudioVolumeType,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void | 获得某个流的最小音量。 |
| getMinVolume(audioType:&nbsp;AudioVolumeType):&nbsp;Promise&lt;number&gt; | 获得某个流的最小音量。 |
| getMaxVolume(audioType:&nbsp;AudioVolumeType,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void | 获得某个流的最大音量。 |
| getMaxVolume(audioType:&nbsp;AudioVolumeType):&nbsp;Promise&lt;number&gt; | 获得某个流的最大音量。 |
| getDevices(deviceFlag:&nbsp;DeviceFlag,&nbsp;callback:&nbsp;AsyncCallback&lt;AudioDeviceDescriptors&gt;):&nbsp;void | 获得设备列表。 |
| getDevices(deviceFlag:&nbsp;DeviceFlag):&nbsp;Promise&lt;AudioDeviceDescriptors&gt; | 获得设备列表。 |
| setDeviceActive(deviceType: ActiveDeviceType, active: boolean, callback: AsyncCallback<void>): void | 激活设备，使用callback返回异步结果 |
| setDeviceActive(deviceType: ActiveDeviceType, active: boolean): Promise<void> | 激活设备，使用Promise返回异步结果。 |
| isDeviceActive(deviceType: ActiveDeviceType, callback: AsyncCallback<boolean>): void | 检查设备是否激活，使用callback返回异步结果。 |
| isDeviceActive(deviceType: ActiveDeviceType): Promise<boolean> | 检查设备是否激活，使用Promise返回异步结果。 |
| on(type: 'deviceChange', callback: AsyncCallback<DeviceChangeAction>): void | 订阅设备更改事件。 当设备连接或断开时，注册的客户端将收到回调。 |
| setAudioScene(scene: AudioScene, callback: AsyncCallback<void>): void | 设置音频场景模式，使用callback返回异步结果。 |
| setAudioScene(scene: AudioScene): Promise<void> | 设置音频场景模式，使用Promise返回异步结果。 |
| getAudioScene(callback: AsyncCallback<AudioScene>): void | 获取音频场景模式，使用callback返回异步结果。 |
| getAudioScene(): Promise<AudioScene> | 获取音频场景模式，使用Promise返回异步结果。 |

**表3** 表示音频设备的interface **AudioDeviceDescriptor**

| 属性 | 描述 |
| -------- | -------- |
| deviceRole:&nbsp;DeviceRole | 设备角色。 |
| deviceType:&nbsp;DeviceType | 设备类型。 |

**表4** 表示音频流类型的枚举**AudioVolumeType**

| 枚举值 | 描述 |
| -------- | -------- |
| VOICE_CALL = 0 | 语音通话。 |
| MEDIA&nbsp;=&nbsp;1 | 媒体声音。 |
| RINGTONE&nbsp;=&nbsp;2 | 铃声。 |
| VOICE_ASSISTANT = 9 | 语音助手。 |

**表5** 表示可获取的设备种类的枚举**DeviceFlag**

| 枚举值 | 描述 |
| -------- | -------- |
| OUTPUT_DEVICES_FLAG&nbsp;=&nbsp;1 | 输出设备。 |
| INPUT_DEVICES_FLAG&nbsp;=&nbsp;2 | 输入设备。 |
| ALL_DEVICES_FLAG&nbsp;=&nbsp;3 | 所有设备。 |

**表6** 表示设备角色的枚举**DeviceRole**

| 枚举值 | 描述 |
| -------- | -------- |
| INPUT_DEVICE&nbsp;=&nbsp;1 | 输入设备。 |
| OUTPUT_DEVICE&nbsp;=&nbsp;2 | 输出设备。 |

**表7** 表示设备类型的枚举**DeviceType**

| 枚举值 | 描述 |
| -------- | -------- |
| INVALID&nbsp;=&nbsp;0 | 无效。 |
| SPEAKER&nbsp;=&nbsp;2 | 扬声器。 |
| WIRED_HEADSET&nbsp;=&nbsp;3 | 有线耳机。 |
| BLUETOOTH_SCO&nbsp;=&nbsp;7 | 蓝牙设备。 |
| BLUETOOTH_A2DP&nbsp;=&nbsp;8 | 支持A2DP的蓝牙设备。 |
| MIC&nbsp;=&nbsp;15 | 麦克风。 |

**表8** 表示音频模式的枚举** **AudioScene **

| Name                       | Description              |
| :------------------------- | :----------------------- |
| AUDIO_SCENE_DEFAULT = 0    | 默认的音频。 <br/>       |
| AUDIO_SCENE_RINGING = 1    | 响铃音频场景。 <br/>     |
| AUDIO_SCENE_PHONE_CALL = 2 | 电话音频场景。 <br/>     |
| AUDIO_SCENE_VOICE_CHAT = 3 | 语音聊天音频场景。 <br/> |

## 开发步骤

1. 获取音频控制器。
   ```
   const audioManager = audio.getAudioManager();
   ```

2. 改变媒体流的声音。
   ```
   audioManager.getVolume(audio.AudioVolumeType.MEDIA, (err, value) => {
      if (err) {
   	   console.error(`failed to get volume ${err.message}`);
   	   return;
      }
      console.log(`Media getVolume  ${value}`);
   });
   ```

## 使用方法

**setAudioScene**

**示例**

1. 获取音频管理器。

   ```
   const audioManager = audio.getAudioManager();
   ```

2. 获取当前的音频场景。

   ```
   audioManager.getAudioScene((err, value) => {
       if (err) {
           console.error('Failed to obtain the audio scene mode.​ ${err.message}');
           return;
       }
       console.log('Audio scene mode  ${value)');
    })
   ```