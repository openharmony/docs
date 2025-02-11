# @ohos.multimedia.audio (音频管理)(系统接口)

音频管理提供管理音频的一些基础能力，包括对音频音量、音频设备的管理，以及对音频数据的采集和渲染等。

该模块提供以下音频相关的常用功能：

- [AudioManager](#audiomanager)：音频管理。
- [TonePlayer](#toneplayer9)：用于管理和播放DTMF（Dual Tone Multi Frequency，双音多频）音调，如拨号音、通话回铃音等。

> **说明：**
>
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.multimedia.audio (音频管理)](js-apis-audio.md)。

## 导入模块

```ts
import audio from '@ohos.multimedia.audio';
```

## 常量

| 名称                                    | 类型      | 可读  | 可写 | 说明               |
| --------------------------------------- | ----------| ---- | ---- | ------------------ |
| LOCAL_NETWORK_ID<sup>9+</sup>           | string    | 是   | 否   | 本地设备网络id。<br/>此接口为系统接口。<br> **系统能力：** SystemCapability.Multimedia.Audio.Device  |

## audio.createTonePlayer<sup>9+</sup>

createTonePlayer(options: AudioRendererInfo, callback: AsyncCallback&lt;TonePlayer&gt;): void

创建DTMF播放器。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**系统接口：** 该接口为系统接口

**参数：**

| 参数名   | 类型                                             | 必填 | 说明            |
| -------- | ----------------------------------------------- | ---- | -------------- |
| options  | [AudioRendererInfo](js-apis-audio.md#audiorendererinfo8)        | 是   | 配置音频渲染器信息。|
| callback | AsyncCallback<[TonePlayer](#toneplayer9)>       | 是   | 回调函数。当获取DTMF播放器成功，err为undefined，data为获取到的DTMF播放器对象；否则为错误对象。|

**示例：**

```ts
import audio from '@ohos.multimedia.audio';

let audioRendererInfo: audio.AudioRendererInfo = {
  usage : audio.StreamUsage.STREAM_USAGE_DTMF,
  rendererFlags : 0
}
let tonePlayer: audio.TonePlayer;

audio.createTonePlayer(audioRendererInfo, (err, data) => {
  console.info(`callback call createTonePlayer: audioRendererInfo: ${audioRendererInfo}`);
  if (err) {
    console.error(`callback call createTonePlayer return error: ${err.message}`);
  } else {
    console.info(`callback call createTonePlayer return data: ${data}`);
    tonePlayer = data;
  }
});
```

## audio.createTonePlayer<sup>9+</sup>

createTonePlayer(options: AudioRendererInfo): Promise&lt;TonePlayer&gt;

创建DTMF播放器。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**系统接口：** 该接口为系统接口

**参数：**

| 参数名  | 类型                                           | 必填 | 说明         |
| :------ | :---------------------------------------------| :--- | :----------- |
| options | [AudioRendererInfo](js-apis-audio.md#audiorendererinfo8)      | 是   | 配置音频渲染器信息。 |

**返回值：**

| 类型                                      | 说明                             |
| ----------------------------------------- | -------------------------------- |
| Promise<[TonePlayer](#toneplayer9)>       | Promise对象，返回DTMF播放器对象。 |

**示例：**

```ts
import audio from '@ohos.multimedia.audio';

let tonePlayer: audio.TonePlayer;
async function createTonePlayerBefore(){
  let audioRendererInfo: audio.AudioRendererInfo = {
    usage : audio.StreamUsage.STREAM_USAGE_DTMF,
    rendererFlags : 0
  }
  tonePlayer = await audio.createTonePlayer(audioRendererInfo);
}
```

## AudioVolumeType

枚举，音频流类型。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

| 名称                         | 值      | 说明       |
| ---------------------------- | ------ | ---------- |
| ULTRASONIC<sup>10+</sup>     | 10     | 超声波。<br/>此接口为系统接口。|
| ALL<sup>9+</sup>             | 100    | 所有公共音频流。<br/>此接口为系统接口。|

## InterruptRequestResultType<sup>9+</sup>

枚举，音频中断请求结果类型。

**系统能力：** SystemCapability.Multimedia.Audio.Interrupt

**系统接口：** 该接口为系统接口

| 名称                         | 值      | 说明       |
| ---------------------------- | ------ | ---------- |
| INTERRUPT_REQUEST_GRANT      | 0      | 请求音频中断成功。 |
| INTERRUPT_REQUEST_REJECT     | 1      | 请求音频中断失败，可能具有较高优先级类型。 |

## DeviceFlag

枚举，可获取的设备种类。

**系统能力：** SystemCapability.Multimedia.Audio.Device

| 名称                            |  值     | 说明                        |
| ------------------------------- | ------ |---------------------------|
| NONE_DEVICES_FLAG<sup>9+</sup>  | 0      | 无设备。 <br/>此接口为系统接口。        |
| DISTRIBUTED_OUTPUT_DEVICES_FLAG<sup>9+</sup> | 4   | 分布式输出设备。<br/>此接口为系统接口。    |
| DISTRIBUTED_INPUT_DEVICES_FLAG<sup>9+</sup>  | 8   | 分布式输入设备。<br/>此接口为系统接口。    |
| ALL_DISTRIBUTED_DEVICES_FLAG<sup>9+</sup>    | 12  | 分布式输入和输出设备。<br/>此接口为系统接口。 |

## DeviceUsage<sup>11+</sup>

枚举，可获取的设备种类。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**系统接口：** 该接口为系统接口

| 名称                            |  值     | 说明                        |
| ------------------------------- | ------ |---------------------------|
| MEDIA_OUTPUT_DEVICES<sup>11+</sup> | 1      | 媒体输出设备。|
| MEDIA_INPUT_DEVICES<sup>11+</sup>  | 2      | 媒体输入设备。|
| ALL_MEDIA_DEVICES<sup>11+</sup>    | 3      | 所有媒体设备。|
| CALL_OUTPUT_DEVICES<sup>11+</sup>  | 4      | 通话输出设备。|
| CALL_INPUT_DEVICES<sup>11+</sup>   | 8      | 通话输入设备。|
| ALL_CALL_DEVICES<sup>11+</sup>     | 12     | 所有通话设备。|

## StreamUsage

枚举，音频流使用类型。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称                                      |  值    | 说明                                                                                                                                          |
| ------------------------------------------| ------ |---------------------------------------------------------------------------------------------------------------------------------------------|
| STREAM_USAGE_SYSTEM<sup>10+</sup>         | 9      | 系统音(如屏幕锁定或按键音)。<br/>此接口为系统接口。  |
| STREAM_USAGE_DTMF<sup>10+</sup>           | 14     | 拨号音。<br/>此接口为系统接口。    |
| STREAM_USAGE_ENFORCED_TONE<sup>10+</sup>  | 15     | 强制音(如相机快门音)。<br/>此接口为系统接口。   |
| STREAM_USAGE_ULTRASONIC<sup>10+</sup>     | 16     | 超声波（目前仅提供给MSDP使用）。<br/>此接口为系统接口。 |

## InterruptRequestType<sup>9+</sup>

枚举，音频中断请求类型。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Interrupt

| 名称                               |  值     | 说明                       |
| ---------------------------------- | ------ | ------------------------- |
| INTERRUPT_REQUEST_TYPE_DEFAULT     | 0      |  默认类型，可中断音频请求。  |

## InterruptResult<sup>9+</sup>

音频中断结果。

**系统能力：** SystemCapability.Multimedia.Audio.Interrupt

**系统接口：** 该接口为系统接口

| 名称          | 类型                                                            | 必填 | 说明             |
| --------------| -------------------------------------------------------------- | ---- | ---------------- |
| requestResult | [InterruptRequestResultType](#interruptrequestresulttype9)     | 是   | 表示音频请求中断类型。 |
| interruptNode | number                                                         | 是   | 音频请求中断的节点。 |

## VolumeEvent<sup>9+</sup>

音量改变时，应用接收的事件。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

| 名称       | 类型                                | 必填   | 说明                                        |
| ---------- | ----------------------------------- | ---- |-------------------------------------------|
| volumeGroupId | number                           | 是   | 音量组id，可用于getGroupManager入参。<br/>此接口为系统接口。 |
| networkId  | string                              | 是   | 网络id。<br/>此接口为系统接口。    |

## ConnectType<sup>9+</sup>

枚举，设备连接类型。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

| 名称                            |  值     | 说明                   |
| :------------------------------ | :----- | :--------------------- |
| CONNECT_TYPE_LOCAL              | 1      | 本地设备。         |
| CONNECT_TYPE_DISTRIBUTED        | 2      | 分布式设备。            |

## VolumeGroupInfos<sup>9+</sup>

音量组信息，数组类型，为[VolumeGroupInfo](#volumegroupinfo9)的数组，只读。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

## VolumeGroupInfo<sup>9+</sup>

音量组信息。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

| 名称                        | 类型                       | 可读 | 可写 | 说明       |
| -------------------------- | -------------------------- | ---- | ---- | ---------- |
| networkId<sup>9+</sup>     | string                     | 是   | 否   | 组网络id。  |
| groupId<sup>9+</sup>       | number                     | 是   | 否   | 组设备组id。 |
| mappingId<sup>9+</sup>     | number                     | 是   | 否   | 组映射id。 |
| groupName<sup>9+</sup>     | string                     | 是   | 否   | 组名。 |
| type<sup>9+</sup>          | [ConnectType](#connecttype9)| 是   | 否   | 连接设备类型。 |

## SourceType<sup>8+</sup>

枚举，音源类型。

| 名称                                         |  值     | 说明                   |
| :------------------------------------------- | :----- | :--------------------- |
| SOURCE_TYPE_WAKEUP <sup>10+</sup>            | 3 | 语音唤醒音频流录制音频源。<br/>**系统能力：** SystemCapability.Multimedia.Audio.Core <br/>**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE <br/> 此接口为系统接口|
| SOURCE_TYPE_VOICE_CALL<sup>11+</sup>            | 4 | 通话录音的音频源。<br/>**系统能力：** SystemCapability.Multimedia.Audio.Core<br/>**需要权限：** ohos.permission.RECORD_VOICE_CALL <br/> 此接口为系统接口|

## AudioScene<sup>8+</sup>

枚举，音频场景。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

| 名称                   |  值     | 说明                                          |
| :--------------------- | :----- | :-------------------------------------------- |
| AUDIO_SCENE_RINGING    | 1      | 响铃模式。<br/>此接口为系统接口。 |
| AUDIO_SCENE_PHONE_CALL | 2      | 电话模式。<br/>此接口为系统接口。 |

## VolumeAdjustType<sup>10+</sup>

枚举，音量调节类型。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

| 名称                   |  值     | 说明                                          |
| :--------------------- | :----- | :-------------------------------------------- |
| VOLUME_UP              | 0      | 向上调节音量。<br/>此接口为系统接口。   |
| VOLUME_DOWN            | 1      | 向下调节音量。<br/>此接口为系统接口。   |

## AudioManager

管理音频音量和音频设备。在调用AudioManager的接口前，需要先通过[getAudioManager](js-apis-audio.md#audiogetaudiomanager)创建实例。

### setExtraParameters<sup>11+</sup>

setExtraParameters(mainKey: string, kvpairs: Record<string, string\>): Promise&lt;void&gt;

音频扩展参数设置，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.MODIFY_AUDIO_SETTINGS

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| mainKey | string | 是   | 被设置的音频参数的主键。 |
| kvpairs | Record<string, string\> | 是   | 被设置的音频参数的子键值对。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------|
| 6800101 | Invalid parameter error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let kvpairs = {} as Record<string, string>;
kvpairs = {
  'key_example': 'value_example'
}
audioManager.setExtraParameters('key_example', kvpairs).then(() => {
  console.info('Promise returned to indicate a successful setting of the extra parameters.');
}).catch ((err: BusinessError) => {
    console.error(`Failed to set the audio extra parameters ${err}`);
});
```

### getExtraParameters<sup>11+</sup>

getExtraParameters(mainKey: string, subKeys?: Array\<string>): Promise\<Record\<string, string>>

获取指定音频参数值，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ |--| ---------------------- |
| mainKey | string | 是 | 待获取的音频参数的主键。 |
| subKeys | Array\<string> | 否 | 待获取的音频参数的子键。 |

**返回值：**

| 类型                  | 说明                                |
| --------------------- | ----------------------------------- |
| Promise\<Record\<string, string>> | Promise对象，返回获取的音频参数的值。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------|
| 6800101 | Invalid parameter error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let subKeys: Array<String> = ['key_example'];
audioManager.getExtraParameters('key_example', subKeys).then((value: Record<string, string>) => {
  console.info(`Promise returned to indicate that the value of the audio extra parameters is obtained ${value}.`);
}).catch ((err: BusinessError) => {
    console.error(`Failed to get the audio extra parameters ${err}`);
});
```

### setAudioScene<sup>8+</sup>

setAudioScene\(scene: AudioScene, callback: AsyncCallback<void\>\): void

设置音频场景模式，使用callback方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                 |
| :------- | :----------------------------------- | :--- | :------------------- |
| scene    | [AudioScene](#audioscene8) | 是   | 音频场景模式。       |
| callback | AsyncCallback<void\>                 | 是   | 回调函数。当设置音频场景模式成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

audioManager.setAudioScene(audio.AudioScene.AUDIO_SCENE_PHONE_CALL, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to set the audio scene mode. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate a successful setting of the audio scene mode.');
});
```

### setAudioScene<sup>8+</sup>

setAudioScene\(scene: AudioScene\): Promise<void\>

设置音频场景模式，使用Promise方式返回异步结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名 | 类型                                 | 必填 | 说明           |
| :----- | :----------------------------------- | :--- | :------------- |
| scene  | [AudioScene](#audioscene8) | 是   | 音频场景模式。 |

**返回值：**

| 类型           | 说明                 |
| :------------- | :------------------- |
| Promise<void\> | Promise对象，无返回结果。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

audioManager.setAudioScene(audio.AudioScene.AUDIO_SCENE_PHONE_CALL).then(() => {
  console.info('Promise returned to indicate a successful setting of the audio scene mode.');
}).catch ((err: BusinessError) => {
  console.error(`Failed to set the audio scene mode ${err}`);
});
```

### getSpatializationManager<sup>11+</sup>

getSpatializationManager(): AudioSpatializationManager

获取空间音频管理器。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**返回值：**

| 类型                                       | 说明                          |
|------------------------------------------| ----------------------------- |
| [AudioSpatializationManager](#audiospatializationmanager11) | AudioSpatializationManager实例 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |

**示例：**

```ts
import audio from '@ohos.multimedia.audio';
let audioSpatializationManager: audio.AudioSpatializationManager = audioManager.getSpatializationManager();
```

### on('volumeChange')<sup>(deprecated)</sup>

on(type: 'volumeChange', callback: Callback\<VolumeEvent>): void

> **说明：**
> 从 API version 8 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeManager中的[on('volumeChange')](js-apis-audio.md#onvolumechange9)替代。

监听系统音量变化事件，使用callback方式返回结果。

**系统接口：** 该接口为系统接口

目前此订阅接口在单进程多AudioManager实例的使用场景下，仅最后一个实例的订阅生效，其他实例的订阅会被覆盖（即使最后一个实例没有进行订阅），因此推荐使用单一AudioManager实例进行开发。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | 是   | 事件回调类型，支持的事件为：'volumeChange'（系统音量变化事件，检测到系统音量改变时，触发该事件）。 |
| callback | Callback<[VolumeEvent](#volumeevent9)> | 是   | 回调函数，返回变化后的音量信息。 |

**示例：**

```ts
audioManager.on('volumeChange', (volumeEvent: audio.VolumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
});
```

### on('ringerModeChange')<sup>(deprecated)</sup>

on(type: 'ringerModeChange', callback: Callback\<AudioRingMode>): void

监听铃声模式变化事件，使用callback方式返回结果。

> **说明：**
> 从 API version 8 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeGroupManager中的[on('ringerModeChange')](js-apis-audio.md#onringermodechange9)替代。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                                                         |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                    | 是   | 事件回调类型，支持的事件为：'ringerModeChange'（铃声模式变化事件，检测到铃声模式改变时，触发该事件）。 |
| callback | Callback<[AudioRingMode](js-apis-audio.md#audioringmode)> | 是   | 回调函数，返回变化后的铃音模式。                                                   |

**示例：**

```ts
audioManager.on('ringerModeChange', (ringerMode: audio.AudioRingMode) => {
  console.info(`Updated ringermode: ${ringerMode}`);
});
```

## AudioVolumeManager<sup>9+</sup>

音量管理。在使用AudioVolumeManager的接口前，需要使用[getVolumeManager](js-apis-audio.md#getvolumemanager9)获取AudioVolumeManager实例。

### getVolumeGroupInfos<sup>9+</sup>

getVolumeGroupInfos(networkId: string, callback: AsyncCallback<VolumeGroupInfos\>\): void

获取音量组信息列表，使用callback方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                 |
| ---------- | ------------------------------------------------------------ | ---- | -------------------- |
| networkId | string                                    | 是   | 设备的网络id。本地设备audio.LOCAL_NETWORK_ID。    |
| callback  | AsyncCallback&lt;[VolumeGroupInfos](#volumegroupinfos9)&gt; | 是   | 回调函数。当获取音量组信息列表成功，err为undefined，data为获取到的音量组信息列表；否则为错误对象。 |

**示例：**
```ts
import { BusinessError } from '@ohos.base';

audioVolumeManager.getVolumeGroupInfos(audio.LOCAL_NETWORK_ID, (err: BusinessError, value: audio.VolumeGroupInfos) => {
  if (err) {
    console.error(`Failed to obtain the volume group infos list. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the volume group infos list is obtained.');
});
```

### getVolumeGroupInfos<sup>9+</sup>

getVolumeGroupInfos(networkId: string\): Promise<VolumeGroupInfos\>

获取音量组信息列表，使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型               | 必填 | 说明                 |
| ---------- | ------------------| ---- | -------------------- |
| networkId | string             | 是   | 设备的网络id。本地设备audio.LOCAL_NETWORK_ID。   |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;[VolumeGroupInfos](#volumegroupinfos9)&gt; | Promise对象，返回音量组信息列表。 |

**示例：**

```ts
async function getVolumeGroupInfos(){
  let volumegroupinfos: audio.VolumeGroupInfos = await audio.getAudioManager().getVolumeManager().getVolumeGroupInfos(audio.LOCAL_NETWORK_ID);
  console.info('Promise returned to indicate that the volumeGroup list is obtained.'+JSON.stringify(volumegroupinfos))
}
```

### getVolumeGroupInfosSync<sup>10+</sup>

getVolumeGroupInfosSync(networkId: string\): VolumeGroupInfos

获取音量组信息列表，同步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型               | 必填 | 说明                 |
| ---------- | ------------------| ---- | -------------------- |
| networkId | string             | 是   | 设备的网络id。本地设备audio.LOCAL_NETWORK_ID。   |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| [VolumeGroupInfos](#volumegroupinfos9) | 音量组信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | invalid parameter error              |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

try {
  let volumegroupinfos: audio.VolumeGroupInfos = audioVolumeManager.getVolumeGroupInfosSync(audio.LOCAL_NETWORK_ID);
  console.info(`Indicate that the volumeGroup list is obtained. ${JSON.stringify(volumegroupinfos)}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the volumeGroup list ${error}`);
}
```

## AudioVolumeGroupManager<sup>9+</sup>

管理音频组音量。在调用AudioVolumeGroupManager的接口前，需要先通过 [getVolumeGroupManager](js-apis-audio.md#getvolumegroupmanager9) 创建实例。

### setVolume<sup>9+</sup>

setVolume(volumeType: AudioVolumeType, volume: number, callback: AsyncCallback&lt;void&gt;): void

设置指定流的音量，使用callback方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅设置铃声（即volumeType为AudioVolumeType.RINGTONE）在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。                                             |
| volume     | number                              | 是   | 音量等级，可设置范围通过getMinVolume和getMaxVolume获取。 |
| callback   | AsyncCallback&lt;void&gt;           | 是   | 回调函数。当设置指定流的音量成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

audioVolumeGroupManager.setVolume(audio.AudioVolumeType.MEDIA, 10, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to set the volume. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate a successful volume setting.');
});
```

### setVolume<sup>9+</sup>

setVolume(volumeType: AudioVolumeType, volume: number): Promise&lt;void&gt;

设置指定流的音量，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅设置铃声（即volumeType为AudioVolumeType.RINGTONE）在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。                                             |
| volume     | number                              | 是   | 音量等级，可设置范围通过getMinVolume和getMaxVolume获取。 |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**示例：**

```ts
audioVolumeGroupManager.setVolume(audio.AudioVolumeType.MEDIA, 10).then(() => {
  console.info('Promise returned to indicate a successful volume setting.');
});
```

### mute<sup>9+</sup>

mute(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback&lt;void&gt;): void

设置指定音量流静音，使用callback方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅设置铃声（即volumeType为AudioVolumeType.RINGTONE）在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                  |
| ---------- | ----------------------------------- | ---- | ------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。                          |
| mute       | boolean                             | 是   | 静音状态，true为静音，false为非静音。 |
| callback   | AsyncCallback&lt;void&gt;           | 是   | 回调函数。当设置指定音量流静音成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

audioVolumeGroupManager.mute(audio.AudioVolumeType.MEDIA, true, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to mute the stream. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the stream is muted.');
});
```

### mute<sup>9+</sup>

mute(volumeType: AudioVolumeType, mute: boolean): Promise&lt;void&gt;

设置指定音量流静音，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅设置铃声（即volumeType为AudioVolumeType.RINGTONE）在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                  |
| ---------- | ----------------------------------- | ---- | ------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。                          |
| mute       | boolean                             | 是   | 静音状态，true为静音，false为非静音。 |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**示例：**

```ts
audioVolumeGroupManager.mute(audio.AudioVolumeType.MEDIA, true).then(() => {
  console.info('Promise returned to indicate that the stream is muted.');
});
```

### setRingerMode<sup>9+</sup>

setRingerMode(mode: AudioRingMode, callback: AsyncCallback&lt;void&gt;): void

设置铃声模式，使用callback方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                            | 必填 | 说明                     |
| -------- | ------------------------------- | ---- | ------------------------ |
| mode     | [AudioRingMode](js-apis-audio.md#audioringmode) | 是   | 音频铃声模式。           |
| callback | AsyncCallback&lt;void&gt;       | 是   | 回调函数。当设置铃声模式成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

audioVolumeGroupManager.setRingerMode(audio.AudioRingMode.RINGER_MODE_NORMAL, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to set the ringer mode. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate a successful setting of the ringer mode.');
});
```

### setRingerMode<sup>9+</sup>

setRingerMode(mode: AudioRingMode): Promise&lt;void&gt;

设置铃声模式，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名 | 类型                            | 必填 | 说明           |
| ------ | ------------------------------- | ---- | -------------- |
| mode   | [AudioRingMode](js-apis-audio.md#audioringmode) | 是   | 音频铃声模式。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**示例：**

```ts
audioVolumeGroupManager.setRingerMode(audio.AudioRingMode.RINGER_MODE_NORMAL).then(() => {
  console.info('Promise returned to indicate a successful setting of the ringer mode.');
});
```

### setMicMute<sup>11+</sup>

setMicMute(mute: boolean): Promise&lt;void&gt;

设置麦克风静音状态，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.MANAGE_AUDIO_CONFIG

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名 | 类型    | 必填 | 说明                                          |
| ------ | ------- | ---- | --------------------------------------------- |
| mute   | boolean | 是   | 待设置的静音状态，true为静音，false为非静音。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied.                          |
| 202     | Not system App.                             |
| 401     | Input parameter type or number mismatch.    |
| 6800101 | Input parameter value error.                |

**示例：**

```ts
audioVolumeGroupManager.setMicMute(true).then(() => {
  console.info('Promise returned to indicate that the mic is muted.');
});
```

### adjustVolumeByStep<sup>10+</sup>

adjustVolumeByStep(adjustType: VolumeAdjustType, callback: AsyncCallback&lt;void&gt;): void

调节当前最高优先级的流的音量，使音量值按步长加或减，使用callback方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅设置铃声（即volumeType为AudioVolumeType.RINGTONE）在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| adjustType | [VolumeAdjustType](#volumeadjusttype10) | 是   | 音量调节方向。                                             |
| callback   | AsyncCallback&lt;void&gt;           | 是   | 回调函数。当调节当前最高优先级的流的音量成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Invalid parameter error. Return by callback.                     |
| 6800301 | System error. Return by callback.                                |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

audioVolumeGroupManager.adjustVolumeByStep(audio.VolumeAdjustType.VOLUME_UP, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to adjust the volume by step. ${err}`);
    return;
  } else {
    console.info('Success to adjust the volume by step.');
  }
});
```
### adjustVolumeByStep<sup>10+</sup>

adjustVolumeByStep(adjustType: VolumeAdjustType): Promise&lt;void&gt;

单步设置当前最高优先级的流的音量，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅设置铃声（即volumeType为AudioVolumeType.RINGTONE）在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| adjustType | [VolumeAdjustType](#volumeadjusttype10) | 是   | 音量调节方向。                                             |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Invalid parameter error. Return by promise.                     |
| 6800301 | System error. Return by promise.                                |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

audioVolumeGroupManager.adjustVolumeByStep(audio.VolumeAdjustType.VOLUME_UP).then(() => {
  console.info('Success to adjust the volume by step.');
}).catch((error: BusinessError) => {
  console.error('Fail to adjust the volume by step.');
});
```

### adjustSystemVolumeByStep<sup>10+</sup>

adjustSystemVolumeByStep(volumeType: AudioVolumeType, adjustType: VolumeAdjustType, callback: AsyncCallback&lt;void&gt;): void

单步设置指定流的音量，使用callback方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅设置铃声（即volumeType为AudioVolumeType.RINGTONE）在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。                                             |
| adjustType | [VolumeAdjustType](#volumeadjusttype10) | 是   | 音量调节方向。                                       |
| callback   | AsyncCallback&lt;void&gt;           | 是   | 回调函数。当单步设置指定流的音量成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Invalid parameter error. Return by callback.                     |
| 6800301 | System error. Return by callback.                                |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

audioVolumeGroupManager.adjustSystemVolumeByStep(audio.AudioVolumeType.MEDIA, audio.VolumeAdjustType.VOLUME_UP, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to adjust the system volume by step ${err}`);
  } else {
    console.info('Success to adjust the system volume by step.');
  }
});
```
### adjustSystemVolumeByStep<sup>10+</sup>

adjustSystemVolumeByStep(volumeType: AudioVolumeType, adjustType: VolumeAdjustType): Promise&lt;void&gt;

单步设置指定流的音量，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅设置铃声（即volumeType为AudioVolumeType.RINGTONE）在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。                                             |
| adjustType | [VolumeAdjustType](#volumeadjusttype10) | 是   | 音量调节方向。                                             |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Invalid parameter error. Return by promise.                     |
| 6800301 | System error. Return by promise.                                |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

audioVolumeGroupManager.adjustSystemVolumeByStep(audio.AudioVolumeType.MEDIA, audio.VolumeAdjustType.VOLUME_UP).then(() => {
  console.info('Success to adjust the system volume by step.');
}).catch((error: BusinessError) => {
  console.error('Fail to adjust the system volume by step.');
});
```

## AudioRoutingManager<sup>9+</sup>

音频路由管理。在使用AudioRoutingManager的接口前，需要使用[getRoutingManager](js-apis-audio.md#getroutingmanager9)获取AudioRoutingManager实例。

### getAvailableDevices<sup>11+</sup>

getAvailableDevices(deviceUsage: DeviceUsage): AudioDeviceDescriptors

获取音频可选设备列表，同步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**系统接口：** 该接口为系统接口

**参数：**

| 参数名     | 类型                      | 必填 | 说明             |
| ---------- | ------------------------- | ---- | ---------------- |
| deviceUsage| [DeviceUsage](#deviceusage11) | 是   | 设备的usage。 |

**返回值：**

| 类型                                                         | 说明                      |
| ------------------------------------------------------------ | ------------------------- |
| [AudioDeviceDescriptors](js-apis-audio.md#audiodevicedescriptors) | 返回设备列表。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | invalid parameter error              |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

try {
  let data: audio.AudioDeviceDescriptors = audioRoutingManager.getAvailableDevices(audio.DeviceUsage.MEDIA_OUTPUT_DEVICES);
  console.info(`Indicate that the device list is obtained ${data}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the device list. ${error}`);
}
```

### on('availableDeviceChange')<sup>11+</sup>

on(type: 'availableDeviceChange', deviceUsage: DeviceUsage, callback: Callback<DeviceChangeAction\>): void

订阅音频可选设备连接变化事件，使用callback方式返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**系统接口：** 该接口为系统接口

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                       |
| :------- | :--------------------------------------------------- | :--- | :----------------------------------------- |
| type     | string                                               | 是   | 订阅的事件的类型。支持事件：'availableDeviceChange' |
| deviceUsage | [DeviceUsage](#deviceusage11)                       | 是   | 设备的usage。     |
| callback | Callback<[DeviceChangeAction](js-apis-audio.md#devicechangeaction)\> | 是   | 回调函数，返回设备更新详情。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Invalid parameter error. |

**示例：**

```ts
audioRoutingManager.on('availableDeviceChange', audio.DeviceUsage.MEDIA_OUTPUT_DEVICES, (deviceChanged: audio.DeviceChangeAction) => {
  console.info('device change type : ' + deviceChanged.type);
  console.info('device descriptor size : ' + deviceChanged.deviceDescriptors.length);
  console.info('device change descriptor : ' + deviceChanged.deviceDescriptors[0].deviceRole);
  console.info('device change descriptor : ' + deviceChanged.deviceDescriptors[0].deviceType);
});
```

### off('availableDeviceChange')<sup>11+</sup>

off(type: 'availableDeviceChange', callback?: Callback<DeviceChangeAction\>): void

取消订阅音频可选设备连接变化事件，使用callback方式返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**系统接口：** 该接口为系统接口

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| type     | string                                              | 是   | 订阅的事件的类型。支持事件：'availableDeviceChange' |
| callback | Callback<[DeviceChangeAction](js-apis-audio.md#devicechangeaction)> | 否   | 回调函数，返回可选设备更新详情。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Invalid parameter error. |

**示例：**

```ts
audioRoutingManager.off('availableDeviceChange');
```

### selectInputDevice<sup>9+</sup>

selectInputDevice(inputAudioDevices: AudioDeviceDescriptors, callback: AsyncCallback&lt;void&gt;): void

选择音频输入设备，当前只能选择一个输入设备，使用callback方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| inputAudioDevices           | [AudioDeviceDescriptors](js-apis-audio.md#audiodevicedescriptors)            | 是   | 输入设备类。               |
| callback                    | AsyncCallback&lt;void&gt;                                    | 是   | 回调函数。当选择音频输入设备成功，err为undefined，否则为错误对象。 |

**示例：**
```ts
import audio from '@ohos.multimedia.audio';
import { BusinessError } from '@ohos.base';

let inputAudioDeviceDescriptor: audio.AudioDeviceDescriptors = [{
  deviceRole : audio.DeviceRole.INPUT_DEVICE,
  deviceType : audio.DeviceType.MIC,
  id : 1,
  name : "",
  address : "",
  sampleRates : [44100],
  channelCounts : [2],
  channelMasks : [0],
  networkId : audio.LOCAL_NETWORK_ID,
  interruptGroupId : 1,
  volumeGroupId : 1,
  displayName : "",
}];

async function selectInputDevice(){
  audioRoutingManager.selectInputDevice(inputAudioDeviceDescriptor, (err: BusinessError) => {
    if (err) {
      console.error(`Result ERROR: ${err}`);
    } else {
      console.info('Select input devices result callback: SUCCESS');
    }
  });
}
```

### selectInputDevice<sup>9+</sup>

selectInputDevice(inputAudioDevices: AudioDeviceDescriptors): Promise&lt;void&gt;

**系统接口：** 该接口为系统接口

选择音频输入设备，当前只能选择一个输入设备，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| inputAudioDevices           | [AudioDeviceDescriptors](js-apis-audio.md#audiodevicedescriptors)            | 是   | 输入设备类。               |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise对象，无返回结果。 |

**示例：**

```ts
import audio from '@ohos.multimedia.audio';
import { BusinessError } from '@ohos.base';

let inputAudioDeviceDescriptor: audio.AudioDeviceDescriptors = [{
  deviceRole : audio.DeviceRole.INPUT_DEVICE,
  deviceType : audio.DeviceType.MIC,
  id : 1,
  name : "",
  address : "",
  sampleRates : [44100],
  channelCounts : [2],
  channelMasks : [0],
  networkId : audio.LOCAL_NETWORK_ID,
  interruptGroupId : 1,
  volumeGroupId : 1,
  displayName : "",
}];

async function getRoutingManager(){
  audioRoutingManager.selectInputDevice(inputAudioDeviceDescriptor).then(() => {
    console.info('Select input devices result promise: SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`Result ERROR: ${err}`);
  });
}
```

### selectOutputDevice<sup>9+</sup>

selectOutputDevice(outputAudioDevices: AudioDeviceDescriptors, callback: AsyncCallback&lt;void&gt;): void

选择音频输出设备，当前只能选择一个输出设备，使用callback方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| outputAudioDevices          | [AudioDeviceDescriptors](js-apis-audio.md#audiodevicedescriptors)            | 是   | 输出设备类。               |
| callback                    | AsyncCallback&lt;void&gt;                                    | 是   | 回调函数。当选择音频输出设备成功，err为undefined，否则为错误对象。 |

**示例：**
```ts
import audio from '@ohos.multimedia.audio';
import { BusinessError } from '@ohos.base';

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
  displayName : "",
}];

async function selectOutputDevice(){
  audioRoutingManager.selectOutputDevice(outputAudioDeviceDescriptor, (err: BusinessError) => {
    if (err) {
      console.error(`Result ERROR: ${err}`);
    } else {
      console.info('Select output devices result callback: SUCCESS'); }
  });
}
```

### selectOutputDevice<sup>9+</sup>

selectOutputDevice(outputAudioDevices: AudioDeviceDescriptors): Promise&lt;void&gt;

**系统接口：** 该接口为系统接口

选择音频输出设备，当前只能选择一个输出设备，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| outputAudioDevices          | [AudioDeviceDescriptors](js-apis-audio.md#audiodevicedescriptors)            | 是   | 输出设备类。               |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise对象，无返回结果。 |

**示例：**

```ts
import audio from '@ohos.multimedia.audio';
import { BusinessError } from '@ohos.base';

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
  displayName : "",
}];

async function selectOutputDevice(){
  audioRoutingManager.selectOutputDevice(outputAudioDeviceDescriptor).then(() => {
    console.info('Select output devices result promise: SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`Result ERROR: ${err}`);
  });
}
```

### selectOutputDeviceByFilter<sup>9+</sup>

selectOutputDeviceByFilter(filter: AudioRendererFilter, outputAudioDevices: AudioDeviceDescriptors, callback: AsyncCallback&lt;void&gt;): void

**系统接口：** 该接口为系统接口

根据过滤条件，选择音频输出设备，当前只能选择一个输出设备，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| filter                      | [AudioRendererFilter](#audiorendererfilter9)                 | 是   | 过滤条件类。               |
| outputAudioDevices          | [AudioDeviceDescriptors](js-apis-audio.md#audiodevicedescriptors)            | 是   | 输出设备类。               |
| callback                    | AsyncCallback&lt;void&gt;                                    | 是   | 回调函数。当选择音频输出设备成功，err为undefined，否则为错误对象。 |

**示例：**
```ts
import audio from '@ohos.multimedia.audio';
import { BusinessError } from '@ohos.base';

let outputAudioRendererFilter: audio.AudioRendererFilter = {
  uid : 20010041,
  rendererInfo : {
    usage : audio.StreamUsage.STREAM_USAGE_MUSIC,
    rendererFlags : 0
  },
  rendererId : 0
};

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
  displayName : "",
}];

async function selectOutputDeviceByFilter(){
  audioRoutingManager.selectOutputDeviceByFilter(outputAudioRendererFilter, outputAudioDeviceDescriptor, (err: BusinessError) => {
    if (err) {
      console.error(`Result ERROR: ${err}`);
    } else {
      console.info('Select output devices by filter result callback: SUCCESS'); }
  });
}
```

### selectOutputDeviceByFilter<sup>9+</sup>

selectOutputDeviceByFilter(filter: AudioRendererFilter, outputAudioDevices: AudioDeviceDescriptors): Promise&lt;void&gt;

**系统接口：** 该接口为系统接口

根据过滤条件，选择音频输出设备，当前只能选择一个输出设备，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                 | 类型                                                         | 必填 | 说明                      |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| filter                | [AudioRendererFilter](#audiorendererfilter9)                 | 是   | 过滤条件类。               |
| outputAudioDevices    | [AudioDeviceDescriptors](js-apis-audio.md#audiodevicedescriptors)            | 是   | 输出设备类。               |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise对象，无返回结果。 |

**示例：**

```ts
import audio from '@ohos.multimedia.audio';
import { BusinessError } from '@ohos.base';

let outputAudioRendererFilter: audio.AudioRendererFilter = {
  uid : 20010041,
  rendererInfo : {
    usage : audio.StreamUsage.STREAM_USAGE_MUSIC,
    rendererFlags : 0
  },
  rendererId : 0
};

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
  displayName : "",
}];

async function selectOutputDeviceByFilter(){
  audioRoutingManager.selectOutputDeviceByFilter(outputAudioRendererFilter, outputAudioDeviceDescriptor).then(() => {
    console.info('Select output devices by filter result promise: SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`Result ERROR: ${err}`);
  })
}
```

## AudioRendererChangeInfo<sup>9+</sup>

描述音频渲染器更改信息。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

| 名称               | 类型                                       | 可读 | 可写 | 说明                          |
| -------------------| ----------------------------------------- | ---- | ---- | ---------------------------- |
| clientUid          | number                                    | 是   | 否   | 音频渲染器客户端应用程序的Uid。<br/>此接口为系统接口。 |
| rendererState      | [AudioState](js-apis-audio.md#audiostate8)                 | 是   | 否   | 音频状态。<br/>此接口为系统接口。|

## AudioCapturerChangeInfo<sup>9+</sup>

描述音频采集器更改信息。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

| 名称               | 类型                                       | 可读 | 可写 | 说明                          |
| -------------------| ----------------------------------------- | ---- | ---- | ---------------------------- |
| clientUid          | number                                    | 是   | 否   | 音频采集器客户端应用程序的Uid。<br/>此接口为系统接口。 |
| capturerState      | [AudioState](js-apis-audio.md#audiostate8)                 | 是   | 否   | 音频状态。<br/>此接口为系统接口。|

## AudioDeviceDescriptor

描述音频设备。

| 名称                          | 类型                       | 可读 | 可写 | 说明       |
| ----------------------------- | -------------------------- | ---- | ---- | ---------- |
| networkId<sup>9+</sup>        | string                     | 是   | 否   | 设备组网的ID。<br/>此接口为系统接口。 <br> **系统能力：** SystemCapability.Multimedia.Audio.Device|
| interruptGroupId<sup>9+</sup> | number                     | 是   | 否   | 设备所处的焦点组ID。<br/>此接口为系统接口。 <br> **系统能力：** SystemCapability.Multimedia.Audio.Device|
| volumeGroupId<sup>9+</sup>    | number                     | 是   | 否   | 设备所处的音量组ID。<br/>此接口为系统接口。 <br> **系统能力：** SystemCapability.Multimedia.Audio.Device|

## AudioRendererFilter<sup>9+</sup>

过滤条件类。在调用selectOutputDeviceByFilter接口前，需要先创建AudioRendererFilter实例。

**系统接口：** 该接口为系统接口

| 名称          | 类型                                     | 必填 | 说明          |
| -------------| ---------------------------------------- | ---- | -------------- |
| uid          | number                                   |  否  | 表示应用ID。<br> **系统能力：** SystemCapability.Multimedia.Audio.Core|
| rendererInfo | [AudioRendererInfo](js-apis-audio.md#audiorendererinfo8) |  否  | 表示渲染器信息。<br> **系统能力：** SystemCapability.Multimedia.Audio.Renderer|
| rendererId   | number                                   |  否  | 音频流唯一id。<br> **系统能力：** SystemCapability.Multimedia.Audio.Renderer|

**示例：**

```ts
import audio from '@ohos.multimedia.audio';

let outputAudioRendererFilter: audio.AudioRendererFilter = {
  uid : 20010041,
  rendererInfo : {
    usage : audio.StreamUsage.STREAM_USAGE_MUSIC,
    rendererFlags : 0
  },
  rendererId : 0
};
```

## AudioSpatializationManager<sup>11+</sup>

空间音频管理。在使用AudioSpatializationManager的接口前，需要使用[getSpatializationManager](#getspatializationmanager11)获取AudioSpatializationManager实例。

### isSpatializationSupported<sup>11+</sup>

isSpatializationSupported(): boolean

获取系统是否支持空间音频，同步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| boolean | 返回系统是否支持空间音频，true为支持，false为不支持。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |

**示例：**

```ts
import audio from '@ohos.multimedia.audio';
import { BusinessError } from '@ohos.base';
try {
  let isSpatializationSupported: boolean = audioSpatializationManager.isSpatializationSupported();
  console.info(`AudioSpatializationManager isSpatializationSupported: ${isSpatializationSupported}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

### isSpatializationSupportedForDevice<sup>11+</sup>

isSpatializationSupportedForDevice(deviceDescriptor: AudioDeviceDescriptor): boolean

获取指定设备是否支持空间音频，同步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                 |
| ---------- | ------------------------------------------------------------ | ---- | -------------------- |
| deviceDescriptor | [AudioDeviceDescriptor](#audiodevicedescriptor)         | 是   | 指定设备的描述。     |

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| boolean | 返回指定设备是否支持空间音频，true为支持，false为不支持。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Input parameter type or number mismatch.    |
| 6800101 | Invalid parameter error.                    |

**示例：**

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

### isHeadTrackingSupported<sup>11+</sup>

isHeadTrackingSupported(): boolean

获取系统是否支持头动跟踪，同步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| boolean | 返回系统是否支持头动跟踪，true为支持，false为不支持。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |

**示例：**

```ts
import audio from '@ohos.multimedia.audio';
import { BusinessError } from '@ohos.base';
try {
  let isHeadTrackingSupported: boolean = audioSpatializationManager.isHeadTrackingSupported();
  console.info(`AudioSpatializationManager isHeadTrackingSupported: ${isHeadTrackingSupported}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

### isHeadTrackingSupportedForDevice<sup>11+</sup>

isHeadTrackingSupportedForDevice(deviceDescriptor: AudioDeviceDescriptor): boolean

获取指定设备是否支持头动跟踪，同步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                 |
| ---------- | ------------------------------------------------------------ | ---- | -------------------- |
| deviceDescriptor | [AudioDeviceDescriptor](#audiodevicedescriptor)         | 是   | 指定设备的描述。     |

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| boolean | 返回指定设备是否支持头动跟踪，true为支持，false为不支持。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Input parameter type or number mismatch.    |
| 6800101 | Invalid parameter error.                    |

**示例：**

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

### setSpatializationEnabled<sup>11+</sup>

setSpatializationEnabled(enable: boolean, callback: AsyncCallback&lt;void&gt;): void

根据输入指令，开启/关闭空间音频渲染效果，使用callback方式异步返回结果。

**需要权限：** ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| enable                      | boolean                                                      | 是   | 表示开启/关闭空间音频渲染。true为开启，false为关闭。  |
| callback                    | AsyncCallback&lt;void&gt;                                    | 是   | AsyncCallback对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied. Return by callback.      |
| 202     | Not system App.                             |
| 401     | Input parameter type or number mismatch.    |
| 6800101 | Invalid parameter error.                    |

**示例：**
```ts
import audio from '@ohos.multimedia.audio';
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

### setSpatializationEnabled<sup>11+</sup>

setSpatializationEnabled(enable: boolean): Promise&lt;void&gt;

根据输入指令，开启/关闭空间音频渲染效果，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名                 | 类型                                                         | 必填 | 说明                      |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| enable                | boolean                                                      | 是   | 表示开启/关闭空间音频渲染。true为开启，false为关闭。  |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied. Return by promise.       |
| 202     | Not system App.                             |
| 401     | Input parameter type or number mismatch.    |

**示例：**

```ts
import audio from '@ohos.multimedia.audio';
import { BusinessError } from '@ohos.base';

let enable: boolean = true
audioSpatializationManager.setSpatializationEnabled(enable).then(() => {
  console.info(`setSpatializationEnabled success`);
}).catch((err: BusinessError) => {
  console.error(`Result ERROR: ${err}`);
});
```

### isSpatializationEnabled<sup>11+</sup>

isSpatializationEnabled(): boolean

获取空间音频渲染是否开启，同步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| boolean | 返回空间音频渲染是否开启，true为开启，false为未开启。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |

**示例：**

```ts
import audio from '@ohos.multimedia.audio';
import { BusinessError } from '@ohos.base';
try {
  let isSpatializationEnabled: boolean = audioSpatializationManager.isSpatializationEnabled();
  console.info(`AudioSpatializationManager isSpatializationEnabled: ${isSpatializationEnabled}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

### on('spatializationEnabledChange')<sup>11+</sup>

on(type: 'spatializationEnabledChange', callback: Callback<boolean\>): void

订阅空间音频渲染开关状态变化事件。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                           |
| :------- | :--------------------------------------------------- | :--- |:---------------------------------------------|
| type     | string                                               | 是   | 订阅的事件的类型。支持事件：'spatializationEnabledChange'。 |
| callback | Callback<boolean\> | 是   | Callback对象，返回空间音频渲染开关状态，true为打开，false为关闭。    |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Input parameter type or number mismatch.    |
| 6800101 | Invalid parameter error.                    |

**示例：**

```ts
import audio from '@ohos.multimedia.audio';

audioSpatializationManager.on('spatializationEnabledChange', (isSpatializationEnabled: boolean) => {
  console.info(`isSpatializationEnabled: ${isSpatializationEnabled}`);
});
```

### off('spatializationEnabledChange')<sup>11+</sup>

off(type: 'spatializationEnabledChange', callback?: Callback<boolean\>): void

取消订阅空间音频渲染开关状态变化事件。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| type     | string                                              | 是   | 订阅的事件的类型。支持事件：'spatializationEnabledChange'。 |
| callback | Callback<boolean\> | 否   | Callback对象，返回空间音频渲染开关状态，true为打开，false为关闭。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Input parameter type or number mismatch.    |
| 6800101 | Invalid parameter error.                    |

**示例：**

```ts
import audio from '@ohos.multimedia.audio';
audioSpatializationManager.off('spatializationEnabledChange');
```


### setHeadTrackingEnabled<sup>11+</sup>

setHeadTrackingEnabled(enable: boolean, callback: AsyncCallback&lt;void&gt;): void

根据输入指令，开启/关闭头动跟踪效果，使用callback方式异步返回结果。

**需要权限：** ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| enable                      | boolean                                                      | 是   | 表示开启/关闭头动跟踪。true为开启，false为关闭。  |
| callback                    | AsyncCallback&lt;void&gt;                                    | 是   | AsyncCallback对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied. Return by callback.      |
| 202     | Not system App.                             |
| 401     | Input parameter type or number mismatch.    |
| 6800101 | Invalid parameter error.                    |

**示例：**
```ts
import audio from '@ohos.multimedia.audio';
import { BusinessError } from '@ohos.base';

let enable: boolean = true
audioSpatializationManager.setHeadTrackingEnabled(enable, (err: BusinessError) => {
  if (err) {
    console.error(`Result ERROR: ${err}`);
  } else {
    console.info(`setHeadTrackingEnabled success`);
  }
});
```

### setHeadTrackingEnabled<sup>11+</sup>

setHeadTrackingEnabled(enable: boolean): Promise&lt;void&gt;

根据输入指令，开启/关闭头动跟踪效果，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名                 | 类型                                                         | 必填 | 说明                      |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| enable                | boolean                                                      | 是   | 表示开启/关闭头动跟踪。true为开启，false为关闭。  |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied. Return by promise.       |
| 202     | Not system App.                             |
| 401     | Input parameter type or number mismatch.    |

**示例：**

```ts
import audio from '@ohos.multimedia.audio';
import { BusinessError } from '@ohos.base';

let enable: boolean = true
audioSpatializationManager.setHeadTrackingEnabled(enable).then(() => {
  console.info(`setHeadTrackingEnabled success`);
}).catch((err: BusinessError) => {
  console.error(`Result ERROR: ${err}`);
});
```

### isHeadTrackingEnabled<sup>11+</sup>

isHeadTrackingEnabled(): boolean

获取头动跟踪是否开启，同步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| boolean | 返回头动跟踪是否开启，true为开启，false为未开启。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |

**示例：**

```ts
import audio from '@ohos.multimedia.audio';
import { BusinessError } from '@ohos.base';
try {
  let isHeadTrackingEnabled: boolean = audioSpatializationManager.isHeadTrackingEnabled();
  console.info(`AudioSpatializationManager isHeadTrackingEnabled: ${isHeadTrackingEnabled}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

### on('headTrackingEnabledChange')<sup>11+</sup>

on(type: 'headTrackingEnabledChange', callback: Callback<boolean\>): void

订阅头动跟踪开关状态变化事件。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                       |
| :------- | :--------------------------------------------------- | :--- | :----------------------------------------- |
| type     | string                                               | 是   | 订阅的事件的类型。支持事件：'headTrackingEnabledChange'。 |
| callback | Callback<boolean\> | 是   | Callback对象，返回头动跟踪开关状态，true为打开，false为关闭。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Input parameter type or number mismatch.    |
| 6800101 | Invalid parameter error.                    |

**示例：**

```ts
import audio from '@ohos.multimedia.audio';

audioSpatializationManager.on('headTrackingEnabledChange', (isHeadTrackingEnabled: boolean) => {
  console.info(`isHeadTrackingEnabled: ${isHeadTrackingEnabled}`);
});
```

### off('headTrackingEnabledChange')<sup>11+</sup>

off(type: 'headTrackingEnabledChange', callback?: Callback<boolean\>): void

取消订阅头动跟踪开关状态变化事件。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| type     | string                                              | 是   | 订阅的事件的类型。支持事件：'headTrackingEnabledChange'。 |
| callback | Callback<boolean\> | 否   | Callback对象，返回头动跟踪开关状态，true为打开，false为关闭。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Input parameter type or number mismatch.    |
| 6800101 | Invalid parameter error.                    |

**示例：**

```ts
import audio from '@ohos.multimedia.audio';
audioSpatializationManager.off('headTrackingEnabledChange');
```

### updateSpatialDeviceState<sup>11+</sup>

updateSpatialDeviceState(spatialDeviceState: AudioSpatialDeviceState): void

更新空间化设备状态，同步返回结果。

**需要权限：** ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| spatialDeviceState     | [AudioSpatialDeviceState](#audiospatialdevicestate11)     | 是   | 需要更新的空间化设备状态。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied.                          |
| 202     | Not system App.                             |
| 401     | Input parameter type or number mismatch.    |
| 6800101 | Invalid parameter error.                    |

**示例：**

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

## AudioSpatialDeviceState<sup>11+</sup>

空间化设备状态。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

| 名称                          | 类型                       | 可读 | 可写 | 说明       |
| ----------------------------- | -------------------------- | ---- | ---- | ---------- |
| address<sup>11+</sup>                    | string         | 是   | 是   | 空间化设备地址。|
| isSpatializationSupported<sup>11+</sup>  | boolean        | 是   | 是   | 空间化设备是否支持空间音频渲染。|
| isHeadTrackingSupported<sup>11+</sup>    | boolean        | 是   | 是   | 空间化设备是否支持头动跟踪。|
| spatialDeviceType<sup>11+</sup>          | [AudioSpatialDeviceType](#audiospatialdevicetype11)   | 是   | 是   | 空间化设备类型。|

**示例：**

```ts
import audio from '@ohos.multimedia.audio';

let spatialDeviceState: audio.AudioSpatialDeviceState = {
  address: "123",
  isSpatializationSupported: true,
  isHeadTrackingSupported: true,
  spatialDeviceType: audio.AudioSpatialDeviceType.SPATIAL_DEVICE_TYPE_IN_EAR_HEADPHONE
}
```

## AudioSpatialDeviceType<sup>11+</sup>

枚举，空间化设备类型。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

| 名称                               |  值     | 说明                       |
| ---------------------------------- | ------ | ------------------------- |
| SPATIAL_DEVICE_TYPE_NONE                   | 0      |  无空间化设备类型。  |
| SPATIAL_DEVICE_TYPE_IN_EAR_HEADPHONE       | 1      |  入耳式耳机。       |
| SPATIAL_DEVICE_TYPE_HALF_IN_EAR_HEADPHONE  | 2      |  半入耳式耳机。     |
| SPATIAL_DEVICE_TYPE_OVER_EAR_HEADPHONE     | 3      |  头戴式耳机。       |
| SPATIAL_DEVICE_TYPE_GLASSES                | 4      |  眼镜式耳机。       |
| SPATIAL_DEVICE_TYPE_OTHERS                 | 5      |  其他空间化设备类型。|

## ToneType<sup>9+</sup>

枚举，播放器的音调类型。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Tone

| 名称                                              |  值    | 说明                          |
| :------------------------------------------------ | :----- | :----------------------------|
| TONE_TYPE_DIAL_0                                  | 0      | 键0的DTMF音。                 |
| TONE_TYPE_DIAL_1                                  | 1      | 键1的DTMF音。                 |
| TONE_TYPE_DIAL_2                                  | 2      | 键2的DTMF音。                 |
| TONE_TYPE_DIAL_3                                  | 3      | 键3的DTMF音。                 |
| TONE_TYPE_DIAL_4                                  | 4      | 键4的DTMF音。                 |
| TONE_TYPE_DIAL_5                                  | 5      | 键5的DTMF音。                 |
| TONE_TYPE_DIAL_6                                  | 6      | 键6的DTMF音。                 |
| TONE_TYPE_DIAL_7                                  | 7      | 键7的DTMF音。                 |
| TONE_TYPE_DIAL_8                                  | 8      | 键8的DTMF音。                 |
| TONE_TYPE_DIAL_9                                  | 9      | 键9的DTMF音。                 |
| TONE_TYPE_DIAL_S                                  | 10     | 键*的DTMF音。                 |
| TONE_TYPE_DIAL_P                                  | 11     | 键#的DTMF音。                 |
| TONE_TYPE_DIAL_A                                  | 12     | 键A的DTMF音。                 |
| TONE_TYPE_DIAL_B                                  | 13     | 键B的DTMF音。                 |
| TONE_TYPE_DIAL_C                                  | 14     | 键C的DTMF音。                 |
| TONE_TYPE_DIAL_D                                  | 15     | 键D的DTMF音。                 |
| TONE_TYPE_COMMON_SUPERVISORY_DIAL                 | 100    | 呼叫监管音调，拨号音。          |
| TONE_TYPE_COMMON_SUPERVISORY_BUSY                 | 101    | 呼叫监管音调，忙。              |
| TONE_TYPE_COMMON_SUPERVISORY_CONGESTION           | 102    | 呼叫监管音调，拥塞。            |
| TONE_TYPE_COMMON_SUPERVISORY_RADIO_ACK            | 103    | 呼叫监管音调，无线电 ACK。      |
| TONE_TYPE_COMMON_SUPERVISORY_RADIO_NOT_AVAILABLE  | 104    | 呼叫监管音调，无线电不可用。     |
| TONE_TYPE_COMMON_SUPERVISORY_CALL_WAITING         | 106    | 呼叫监管音调，呼叫等待。        |
| TONE_TYPE_COMMON_SUPERVISORY_RINGTONE             | 107    | 呼叫监管音调，铃声。            |
| TONE_TYPE_COMMON_PROPRIETARY_BEEP                 | 200    | 专有声调，一般蜂鸣声。          |
| TONE_TYPE_COMMON_PROPRIETARY_ACK                  | 201    | 专有声调，ACK。                |
| TONE_TYPE_COMMON_PROPRIETARY_PROMPT               | 203    | 专有声调，PROMPT。             |
| TONE_TYPE_COMMON_PROPRIETARY_DOUBLE_BEEP          | 204    | 专有声调，双重蜂鸣声。          |

## TonePlayer<sup>9+</sup>

提供播放和管理DTMF（Dual Tone Multi Frequency，双音多频）音调的方法，包括各种系统监听音调、专有音调，如拨号音、通话回铃音等。
在调用TonePlayer的接口前，需要先通过[createTonePlayer](#audiocreatetoneplayer9)创建实例。

**系统接口：** 该接口为系统接口

### load<sup>9+</sup>

load(type: ToneType, callback: AsyncCallback&lt;void&gt;): void

加载DTMF音调配置。使用callback方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**参数：**

| 参数名          | 类型                        | 必填  | 说明                            |
| :--------------| :-------------------------- | :-----| :------------------------------ |
| type           | [ToneType](#tonetype9)       | 是    | 配置的音调类型。                 |
| callback       | AsyncCallback<void\>        | 是    | 回调函数。当加载DTMF音调配置成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

tonePlayer.load(audio.ToneType.TONE_TYPE_DIAL_5, (err: BusinessError) => {
  if (err) {
    console.error(`callback call load failed error: ${err.message}`);
    return;
  } else {
    console.info('callback call load success');
  }
});
```

### load<sup>9+</sup>

load(type: ToneType): Promise&lt;void&gt;

加载DTMF音调配置。使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**参数：**

| 参数名         | 类型                    | 必填  |  说明             |
| :------------- | :--------------------- | :---  | ---------------- |
| type           | [ToneType](#tonetype9)   | 是    | 配置的音调类型。  |

**返回值：**

| 类型            | 说明                        |
| :--------------| :-------------------------- |
| Promise<void\> | Promise对象，无返回结果。 |

**示例：**

```ts
tonePlayer.load(audio.ToneType.TONE_TYPE_DIAL_1).then(() => {
  console.info('promise call load ');
}).catch(() => {
  console.error('promise call load fail');
});
```

### start<sup>9+</sup>

start(callback: AsyncCallback&lt;void&gt;): void

启动DTMF音调播放。使用callback方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| :------- | :------------------- | :--- | :----------------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数。当启动DTMF音调播放成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

tonePlayer.start((err: BusinessError) => {
  if (err) {
    console.error(`callback call start failed error: ${err.message}`);
    return;
  } else {
    console.info('callback call start success');
  }
});
```

### start<sup>9+</sup>

start(): Promise&lt;void&gt;

启动DTMF音调播放。使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**返回值：**

| 类型           | 说明                          |
| :------------- | :---------------------------- |
| Promise<void\> | Promise对象，无返回结果。 |

**示例：**

```ts
tonePlayer.start().then(() => {
  console.info('promise call start');
}).catch(() => {
  console.error('promise call start fail');
});
```

### stop<sup>9+</sup>

stop(callback: AsyncCallback&lt;void&gt;): void

停止当前正在播放的音调。使用callback方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| :------- | :------------------- | :--- | :----------------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数。当停止当前正在播放的音调成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

tonePlayer.stop((err: BusinessError) => {
  if (err) {
    console.error(`callback call stop error: ${err.message}`);
    return;
  } else {
    console.error('callback call stop success ');
  }
});
```

### stop<sup>9+</sup>

stop(): Promise&lt;void&gt;

停止当前正在播放的音调。使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**返回值：**

| 类型           | 说明                          |
| :------------- | :---------------------------- |
| Promise<void\> | Promise对象，无返回结果。 |

**示例：**

```ts
tonePlayer.stop().then(() => {
  console.info('promise call stop finish');
}).catch(() => {
  console.error('promise call stop fail');
});
```

### release<sup>9+</sup>

release(callback: AsyncCallback&lt;void&gt;): void

释放与此TonePlayer对象关联的资源。使用callback方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**参数：**

| 参数名   | 类型                 | 必填 | 说明                            |
| :------- | :------------------- | :--- | :---------------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数。当释放与此TonePlayer对象关联的资源成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

tonePlayer.release((err: BusinessError) => {
  if (err) {
    console.error(`callback call release failed error: ${err.message}`);
    return;
  } else {
    console.info('callback call release success ');
  }
});
```

### release<sup>9+</sup>

release(): Promise&lt;void&gt;

释放与此TonePlayer对象关联的资源。使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**返回值：**

| 类型           | 说明                          |
| :------------- | :---------------------------- |
| Promise<void\> | Promise对象，无返回结果。 |

**示例：**

```ts
tonePlayer.release().then(() => {
  console.info('promise call release');
}).catch(() => {
  console.error('promise call release fail');
});
```