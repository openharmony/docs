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

**表3** 表示音频设备的interface **AudioDeviceDescriptor**

| 属性 | 描述 | 
| -------- | -------- |
| deviceRole:&nbsp;DeviceRole | 设备角色。 | 
| deviceType:&nbsp;DeviceType | 设备类型。 | 

**表4** 表示音频流类型的枚举**AudioVolumeType**

| 枚举值 | 描述 | 
| -------- | -------- |
| MEDIA&nbsp;=&nbsp;1 | 媒体声音。 | 
| RINGTONE&nbsp;=&nbsp;2 | 铃声。 | 

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
| SPEAKER&nbsp;=&nbsp;1 | 扬声器。 | 
| WIRED_HEADSET&nbsp;=&nbsp;2 | 有线耳机。 | 
| BLUETOOTH_SCO&nbsp;=&nbsp;3 | 蓝牙设备。 | 
| BLUETOOTH_A2DP&nbsp;=&nbsp;4 | 支持A2DP的蓝牙设备。 | 
| MIC&nbsp;=&nbsp;5 | 麦克风。 | 


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
